/*
 * EX_Code.c
 *
 *  Created on: 2019年6月24日
 *      Author: helei
 */

#define __EX_CODE_GLOBALS__

#include "derivative.h"
#include "EX_Define.h"
#include "BASE_Global.h"
#include "Global.h"

//使用流程上锁，返回0则成功，否则失败
uint8_t Ex_Base_LockGate(uint8_t gate)
{
    uint8_t recode = _ERR_EX_GATE_;
    uint8_t ID;
    uint8_t status;
    ID = Get_Core_ID();

    if( _ERR_EX_GATE_ != ID ) //获取成功
    {
        status = Get_Gate_Status(gate);
        if( _ERR_EX_GATE_ != status ) //状态获取有效
        {
            if( (CoreNone == status) || (MyCore == status) ) //未上锁或者自己已经锁定
            {
                status = Lock_Gate(gate);	//上锁并返回锁状态
                if( ID == status )	//确认是被自己锁定
                {
                    recode = 0;	//返回值变为成功，即0
                }
            }
        }
    }
    return recode;
}
//按照流程解锁，返回0则解锁成功，否则失败
uint8_t Ex_Base_UnlockGate(uint8_t gate)
{
    uint8_t recode = _ERR_EX_GATE_;
    uint8_t status;

    status = Unlock_Gate(gate);
    if( CoreNone == status )	//解锁是否成功
    {
        recode = 0;
    }

    return recode;
}

//交换区任务初始化
void Ex_Init(void)
{
//无需要初始化的模块
}

/* 在线标定用于响应来自Core1的软件中断SI_0，中断处理函数；
 * 返回值：0代表处理完成，_ERR_EX_GATE_ 代表获取信号量状态有问题（可能需要强制重启）。
 *
 * */
uint8_t Ex_Cal_IntHandle(void)
{
    uint8_t errcode = _ERR_EX_GATE_;
    uint8_t recode = 0;

    errcode = Get_Gate_Status(Gate_Input);
    if( (errcode != _ERR_EX_GATE_) && (errcode != MyCore) )	//没有被自己锁上
    {
        errcode = Get_Gate_Status(Gate_Output);
        if( (errcode != _ERR_EX_GATE_) && (errcode != MyCore) )	//没有被自己锁上
        {
            //Ex_Base_UnlockGate(Gate_SPI);//解锁自身可能持有的其他信号量
            //SYS_ResetCore();
            RestartCore0 = 1;	//置位重启标志位. 均放置在循环中的安全位置重启。
        }
        else if( errcode == MyCore )	//被自身锁定
        {
            RestartCore0 = 1;	//置位重启标志位
        }
        else //获取失败
        {
            recode = _ERR_EX_GATE_;
        }
    }
    else if( errcode == MyCore ) //被自身锁定
    {
        RestartCore0 = 1; //置位重启标志位
    }
    else //获取失败
    {
        recode = _ERR_EX_GATE_;
    }

    return recode;
}

//检查是否需要重启
void Ex_Cal_Task(void)
{
    if( 1 == RestartCore0 )
    {
        SYS_ResetCore();
    }
}
//检查是否需要暂停
void Ex_Stop_Task(void)
{
    //当Core1通知需要暂停Core0时，则Core0停止在安全位置，等待Core1喂狗成功后继续执行。
    while(Core1ID == Get_Gate_Status(Gate_Core0Stop)) ;
}

//普通数据交换区任务，输入任务; 返回0则任务执行成功，否则根据错误码进行错误处理。
uint8_t Ex_Input_Task(void)
{
    uint8_t ErrTimes = 0;
    uint8_t errcode = 0;
    uint8_t recode = 0;

    while(ErrTimes < ERR_MAX_TIMES)
    {
        errcode = Ex_Base_LockGate(Gate_Input); //尝试上锁
        if( 0 == errcode )
            break;
//      if((ERR_MAX_TIMES-1) == ErrTimes)
//	recode = _ERR_EX_TASK_;
        ErrTimes++;
    }
    if( 0 == errcode )	//自身已锁定门
    {
        if( WriteComplete == Ex_Input->QAflag )	//写完成
        {
            Ex_Input_CopyValue();	//拷贝数据到本地变量
            Ex_Input->QAflag = ReadComplete;
        }
        else
        {
            recode += _ERR_EX_FLAG_;
        }

        errcode = Ex_Base_UnlockGate(Gate_Input);
        recode += errcode;
    }
    else
    {
        recode = _ERR_EX_TASK_;
    }
    return recode;
}

//普通数据交换区任务，输出任务; 返回0则任务执行成功，否则根据错误码进行错误处理。
uint8_t Ex_Output_Task(void)
{
    uint8_t ErrTimes = 0;
    uint8_t errcode = 0;
    uint8_t recode = 0;

    while(ErrTimes < ERR_MAX_TIMES)
    {
        errcode = Ex_Base_LockGate(Gate_Output);	//尝试上锁
        if( 0 == errcode )
            break;
//      if((ERR_MAX_TIMES-1) == ErrTimes)
//	recode = _ERR_EX_TASK_;
        ErrTimes++;
    }
    if( 0 == errcode )	//自身已锁定门
    {
        if( ReadComplete == Ex_Output->QAflag )	//读完成
        {
            Ex_Output_CopyValue();	//拷贝本地变量到交换区
            Ex_Output->QAflag = WriteComplete;
        }
        else
        {
            recode += _ERR_EX_FLAG_;
        }

        errcode = Ex_Base_UnlockGate(Gate_Output);
        recode += errcode;
    }
    else
    {
        recode = _ERR_EX_TASK_;
    }
    return recode;
}

//交换区总任务
void Ex_Task(void)
{
    static uint32_t errcodeTimes = 0;
    uint32_t errcode = 0;

    errcode += Ex_Output_Task();	//先发送后接收
    errcode = Ex_Input_Task();
    Ex_Cal_Task();	//判断是否满足重启
    Ex_Stop_Task();	//判断是否需要暂时停止
    if( errcode )
    {
        errcodeTimes++;	//累计错误次数，包括不能访问的次数
    }
}

/*
 * EX_Code.c
 *
 *  Created on: 2019年6月24日
 *      Author: helei
 */

#define __EX_CODE_GLOBALS__

#include "derivative.h"
#include "EX_Define.h"


//使用流程上锁，返回0则成功，否则失败
uint8_t Ex_Base_LockGate(uint8_t gate)
{
    uint8_t recode = _ERR_EX_GATE_;
    uint8_t ID = 0;
    uint8_t status = 0;
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
  uint8_t status = 0;

  status = Unlock_Gate (gate);
  if (CoreNone == status)	//解锁是否成功
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

/*在线标定时用于发送软件中断SI_0给Core0，使其在安全时重启
 *
 *
 * 注意：当前不对标定值做判断，只要在线标定就重启。后续可以添加范围判断。
 * */
void Ex_Cal_SendSignal2Core0(void)
{
  Set_SI0();//发送软件中断SI_0到Core0
}

//普通数据交换区任务，输入任务; 返回0则任务执行成功，否则根据错误码进行错误处理。
uint8_t Ex_Input_Task(void)
{
  uint8_t ErrTimes = 0;
  uint8_t errcode = 0;
  uint8_t recode = 0;

  while(ErrTimes < ERR_MAX_TIMES)
    {
      errcode = Ex_Base_LockGate(Gate_Input);//尝试上锁
      if(0 == errcode)
	break;
//      if((ERR_MAX_TIMES-1) == ErrTimes)
//	recode = _ERR_EX_TASK_;
      ErrTimes ++;
    }
  if(0 == errcode)	//自身已锁定门
    {
      if(WriteComplete == Ex_Input->QAflag)	//写完成
	{
//	  Ex_Input_CopyValue();	//拷贝数据到本地变量
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
      errcode = Ex_Base_LockGate(Gate_Output);//尝试上锁
      if(0 == errcode)
	break;
//      if((ERR_MAX_TIMES-1) == ErrTimes)
//	recode = _ERR_EX_TASK_;
      ErrTimes ++;
    }
  if(0 == errcode)	//自身已锁定门
    {
      if(ReadComplete == Ex_Output->QAflag)	//读完成
	{
//	  Ex_Output_CopyValue();	//拷贝本地变量到交换区
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
  Ex_Output_Task();
  Ex_Input_Task();
}

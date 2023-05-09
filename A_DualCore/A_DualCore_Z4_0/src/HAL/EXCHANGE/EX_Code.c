/*
 * EX_Code.c
 *
 *  Created on: 2019��6��24��
 *      Author: helei
 */

#define __EX_CODE_GLOBALS__

#include "derivative.h"
#include "EX_Define.h"
#include "BASE_Global.h"
#include "Global.h"

//ʹ����������������0��ɹ�������ʧ��
uint8_t Ex_Base_LockGate(uint8_t gate)
{
    uint8_t recode = _ERR_EX_GATE_;
    uint8_t ID;
    uint8_t status;
    ID = Get_Core_ID();

    if( _ERR_EX_GATE_ != ID ) //��ȡ�ɹ�
    {
        status = Get_Gate_Status(gate);
        if( _ERR_EX_GATE_ != status ) //״̬��ȡ��Ч
        {
            if( (CoreNone == status) || (MyCore == status) ) //δ���������Լ��Ѿ�����
            {
                status = Lock_Gate(gate);	//������������״̬
                if( ID == status )	//ȷ���Ǳ��Լ�����
                {
                    recode = 0;	//����ֵ��Ϊ�ɹ�����0
                }
            }
        }
    }
    return recode;
}
//�������̽���������0������ɹ�������ʧ��
uint8_t Ex_Base_UnlockGate(uint8_t gate)
{
    uint8_t recode = _ERR_EX_GATE_;
    uint8_t status;

    status = Unlock_Gate(gate);
    if( CoreNone == status )	//�����Ƿ�ɹ�
    {
        recode = 0;
    }

    return recode;
}

//�����������ʼ��
void Ex_Init(void)
{
//����Ҫ��ʼ����ģ��
}

/* ���߱궨������Ӧ����Core1������ж�SI_0���жϴ�������
 * ����ֵ��0��������ɣ�_ERR_EX_GATE_ �����ȡ�ź���״̬�����⣨������Ҫǿ����������
 *
 * */
uint8_t Ex_Cal_IntHandle(void)
{
    uint8_t errcode = _ERR_EX_GATE_;
    uint8_t recode = 0;

    errcode = Get_Gate_Status(Gate_Input);
    if( (errcode != _ERR_EX_GATE_) && (errcode != MyCore) )	//û�б��Լ�����
    {
        errcode = Get_Gate_Status(Gate_Output);
        if( (errcode != _ERR_EX_GATE_) && (errcode != MyCore) )	//û�б��Լ�����
        {
            //Ex_Base_UnlockGate(Gate_SPI);//����������ܳ��е������ź���
            //SYS_ResetCore();
            RestartCore0 = 1;	//��λ������־λ. ��������ѭ���еİ�ȫλ��������
        }
        else if( errcode == MyCore )	//����������
        {
            RestartCore0 = 1;	//��λ������־λ
        }
        else //��ȡʧ��
        {
            recode = _ERR_EX_GATE_;
        }
    }
    else if( errcode == MyCore ) //����������
    {
        RestartCore0 = 1; //��λ������־λ
    }
    else //��ȡʧ��
    {
        recode = _ERR_EX_GATE_;
    }

    return recode;
}

//����Ƿ���Ҫ����
void Ex_Cal_Task(void)
{
    if( 1 == RestartCore0 )
    {
        SYS_ResetCore();
    }
}
//����Ƿ���Ҫ��ͣ
void Ex_Stop_Task(void)
{
    //��Core1֪ͨ��Ҫ��ͣCore0ʱ����Core0ֹͣ�ڰ�ȫλ�ã��ȴ�Core1ι���ɹ������ִ�С�
    while(Core1ID == Get_Gate_Status(Gate_Core0Stop)) ;
}

//��ͨ���ݽ�����������������; ����0������ִ�гɹ���������ݴ�������д�����
uint8_t Ex_Input_Task(void)
{
    uint8_t ErrTimes = 0;
    uint8_t errcode = 0;
    uint8_t recode = 0;

    while(ErrTimes < ERR_MAX_TIMES)
    {
        errcode = Ex_Base_LockGate(Gate_Input); //��������
        if( 0 == errcode )
            break;
//      if((ERR_MAX_TIMES-1) == ErrTimes)
//	recode = _ERR_EX_TASK_;
        ErrTimes++;
    }
    if( 0 == errcode )	//������������
    {
        if( WriteComplete == Ex_Input->QAflag )	//д���
        {
            Ex_Input_CopyValue();	//�������ݵ����ر���
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

//��ͨ���ݽ����������������; ����0������ִ�гɹ���������ݴ�������д�����
uint8_t Ex_Output_Task(void)
{
    uint8_t ErrTimes = 0;
    uint8_t errcode = 0;
    uint8_t recode = 0;

    while(ErrTimes < ERR_MAX_TIMES)
    {
        errcode = Ex_Base_LockGate(Gate_Output);	//��������
        if( 0 == errcode )
            break;
//      if((ERR_MAX_TIMES-1) == ErrTimes)
//	recode = _ERR_EX_TASK_;
        ErrTimes++;
    }
    if( 0 == errcode )	//������������
    {
        if( ReadComplete == Ex_Output->QAflag )	//�����
        {
            Ex_Output_CopyValue();	//�������ر�����������
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

//������������
void Ex_Task(void)
{
    static uint32_t errcodeTimes = 0;
    uint32_t errcode = 0;

    errcode += Ex_Output_Task();	//�ȷ��ͺ����
    errcode = Ex_Input_Task();
    Ex_Cal_Task();	//�ж��Ƿ���������
    Ex_Stop_Task();	//�ж��Ƿ���Ҫ��ʱֹͣ
    if( errcode )
    {
        errcodeTimes++;	//�ۼƴ���������������ܷ��ʵĴ���
    }
}

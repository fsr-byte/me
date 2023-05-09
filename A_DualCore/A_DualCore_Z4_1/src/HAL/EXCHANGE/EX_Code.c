/*
 * EX_Code.c
 *
 *  Created on: 2019��6��24��
 *      Author: helei
 */

#define __EX_CODE_GLOBALS__

#include "derivative.h"
#include "EX_Define.h"


//ʹ����������������0��ɹ�������ʧ��
uint8_t Ex_Base_LockGate(uint8_t gate)
{
    uint8_t recode = _ERR_EX_GATE_;
    uint8_t ID = 0;
    uint8_t status = 0;
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
  uint8_t status = 0;

  status = Unlock_Gate (gate);
  if (CoreNone == status)	//�����Ƿ�ɹ�
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

/*���߱궨ʱ���ڷ�������ж�SI_0��Core0��ʹ���ڰ�ȫʱ����
 *
 *
 * ע�⣺��ǰ���Ա궨ֵ���жϣ�ֻҪ���߱궨������������������ӷ�Χ�жϡ�
 * */
void Ex_Cal_SendSignal2Core0(void)
{
  Set_SI0();//��������ж�SI_0��Core0
}

//��ͨ���ݽ�����������������; ����0������ִ�гɹ���������ݴ�������д�����
uint8_t Ex_Input_Task(void)
{
  uint8_t ErrTimes = 0;
  uint8_t errcode = 0;
  uint8_t recode = 0;

  while(ErrTimes < ERR_MAX_TIMES)
    {
      errcode = Ex_Base_LockGate(Gate_Input);//��������
      if(0 == errcode)
	break;
//      if((ERR_MAX_TIMES-1) == ErrTimes)
//	recode = _ERR_EX_TASK_;
      ErrTimes ++;
    }
  if(0 == errcode)	//������������
    {
      if(WriteComplete == Ex_Input->QAflag)	//д���
	{
//	  Ex_Input_CopyValue();	//�������ݵ����ر���
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
      errcode = Ex_Base_LockGate(Gate_Output);//��������
      if(0 == errcode)
	break;
//      if((ERR_MAX_TIMES-1) == ErrTimes)
//	recode = _ERR_EX_TASK_;
      ErrTimes ++;
    }
  if(0 == errcode)	//������������
    {
      if(ReadComplete == Ex_Output->QAflag)	//�����
	{
//	  Ex_Output_CopyValue();	//�������ر�����������
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
  Ex_Output_Task();
  Ex_Input_Task();
}

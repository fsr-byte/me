/*
 * EX_Lib.c
 *
 *  Created on: 2019��6��21��
 *      Author: helei
 */

#define __EX_DEFINE_GLOBALS__

#include "derivative.h"
#include "EX_Define.h"
#include "compiler_api.h"

/*-------------------------Semaphore---------------------------*/
#define GetCoreID() ((uint16_t) MFSPR(286))

/* ��ȡ���˵�ID */
uint8_t Get_Core_ID(void)
{
  uint16_t temp = 0;
  uint8_t recode = _ERR_EX_GATE_;

  temp = GetCoreID ();
  switch (temp)
    {
    case 0:
      recode = Core0ID;
      break;
    case 1:
      recode = Core1ID;
      break;
    default:
      break;
    }

  return recode;
}

/*  ��ȡ�ź���״̬     */
uint8_t Get_Gate_Status(uint8_t gate)
{
  uint8_t recode = _ERR_EX_GATE_;
  if (gate < 16)
    {
      recode = SEMA42.GATE[gate].R;
    }

  return recode;
}

//��ͼ���ţ�����������״̬
uint8_t Lock_Gate (uint8_t gate)
{
  uint8_t ID;
  uint8_t recode = _ERR_EX_GATE_;

  if (gate < 16)
    {
      ID = Get_Core_ID ();
      if (_ERR_EX_GATE_ != ID) //��ȡ�ɹ�
	{
	  SEMA42.GATE[gate].R = ID; //����
	  recode = Get_Gate_Status (gate);
	}
    }

  return recode;
}

//��ͼ�������������������״̬
uint8_t Unlock_Gate(uint8_t gate)
{
  uint8_t recode = _ERR_EX_GATE_;

  if(gate < 16)
    {
      SEMA42.GATE[gate].R = CoreNone;
      recode = Get_Gate_Status(gate);
    }

  return recode;
}

//ǿ�Ƹ�λGate��,����ֵΪ0ʱ�ɹ������ش����־ʱʧ�ܻ���ڴ���
uint8_t Reset_Gate(uint8_t gate)
{
  uint8_t cnt = 0;
  uint8_t recode = _ERR_EX_GATE_;

  if(gate < 16)
    {
      SEMA42.RSTGT.R.R = (0xE2 << 8);
      while(SEMA42.RSTGT.R.B.RSTGSM != 0x01)
	{
	  if(cnt++ > 10) return recode;
	}
      SEMA42.RSTGT.R.R = (0x1D << 8) | gate;
      recode = 0;
    }
  return recode;
}
//��λ����Gate��
void Rest_AllGate(void)
{
  uint8_t i = 0;
  for(i = 0; i< 16; i++)
    {
      Reset_Gate(i);
    }
  return;
}

/*-------------------------Software Interrupt---------------------------*/
void Set_SI0(void)	//�����ж�0�Ĵ���::���ڱ궨���ݵı궨��Core0�ڴ˲����µ�����
{
	INTC_0.SSCIR[0].B.SET = 1;
}




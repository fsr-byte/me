/*
 * EX_Lib.c
 *
 *  Created on: 2019年6月21日
 *      Author: helei
 */

#define __EX_DEFINE_GLOBALS__

#include "derivative.h"
#include "EX_Define.h"
#include "compiler_api.h"

/*-------------------------Semaphore---------------------------*/
#define GetCoreID() ((uint16_t) MFSPR(286))

/* 获取本核的ID */
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

/*  获取信号门状态     */
uint8_t Get_Gate_Status(uint8_t gate)
{
  uint8_t recode = _ERR_EX_GATE_;
  if (gate < 16)
    {
      recode = SEMA42.GATE[gate].R;
    }

  return recode;
}

//试图锁门，并反馈上锁状态
uint8_t Lock_Gate (uint8_t gate)
{
  uint8_t ID;
  uint8_t recode = _ERR_EX_GATE_;

  if (gate < 16)
    {
      ID = Get_Core_ID ();
      if (_ERR_EX_GATE_ != ID) //获取成功
	{
	  SEMA42.GATE[gate].R = ID; //上锁
	  recode = Get_Gate_Status (gate);
	}
    }

  return recode;
}

//试图解锁，并反馈解锁后的状态
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

//强制复位Gate门,返回值为0时成功，返回错误标志时失败或存在错误。
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
//复位所有Gate门
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
void Set_SI0(void)	//设置中断0的触发::用于标定数据的标定和Core0在此操作下的重启
{
	INTC_0.SSCIR[0].B.SET = 1;
}




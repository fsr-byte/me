/*
 * SYS.c
 *
 *  Created on: 2018年9月5日
 *      Author: helei
 */

#define __SYS_GLOBALS__

#include "derivative.h"
#include "SYS.h"
#include "Global.h"
#include "EX_Define.h"

static uint8_t	SYSCurExtIntStatus = 0;

void SYS_Timer_Init(void)
{
  INTC_0.PSR[228].R = INT_PIT02_CORE_PRIORITY;	//PIT0_2
  PIT_0.TIMER[2].LDVAL.R = 40000; //1ms周期，时钟源为PER_CLK
  PIT_0.TIMER[2].TCTRL.B.TIE = 1;
  PIT_0.TIMER[2].TCTRL.B.TEN = 1; //开始工作
}

void SYS_Timer_Stop(void)
{
  PIT_0.TIMER[2].TCTRL.B.TEN = 0; //停止工作
  PIT_0.TIMER[2].TCTRL.B.TIE = 0;
}

//软件中断初始化
void SYS_SI_Init(void)
{
  INTC_0.PSR[0].R = INT_SI0_CORE_PRIORITY;
}

void SYS_SI_Stop(void)
{
  INTC_0.PSR[0].R = 0;
}

void hwReset(void)//Core 0和Core1都重启
{
  Rest_AllGate();
  MC_ME.CADDR[0].B.RMC = 1;
  MC_ME.CADDR[1].B.RMC = 1;
  MC_ME.MCTL.R = 0xF0005AF0;              //DRUN Mode & Key
  MC_ME.MCTL.R = 0xF000A50F;              //DRUN Mode & Key
}

//仅重启Core0
void SYS_ResetCore(void)
{
  SYS_Timer_Stop();
  SYS_SI_Stop();
  InfoTimesRestart++;
  __asm__("e_lis %r12,0x011C");//0x11c0000; Core0 Start Address
  __asm__("e_or2i %r12,0x0000");
  //JUMP_ADDRESS
  __asm__("mtlr %r12");
  __asm__("se_blrl");
}

/* Enable external interrupts */
void SYS_Enable_EXTInterrupt(void)
{
	asm (" wrteei 1 ");
	SYSCurExtIntStatus = 1;
}

/* Disable external interrupts */
void SYS_Disable_EXTInterrupt(void)
{
	asm (" wrteei 0 ");
	SYSCurExtIntStatus = 0;
}

uint8_t SYS_GetCurIntStatus(void)
{
	return SYSCurExtIntStatus;
}

void SYS_SetCurIntStatus(uint8_t status)
{
	SYSCurExtIntStatus = (status>0)? 1:0;
}

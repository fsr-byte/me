/*
 * SYS.c
 *
 *  Created on: 2018年9月5日
 *      Author: helei
 */

#define __SYS_GLOBALS__

#include "derivative.h"
#include "SYS.h"
#include "EX_Define.h"

static uint8_t	SYSCurExtIntStatus = 0;

void SYS_CLOCK_Init(void)
{
	//MC_ME.RUN_PC[0].B.DRUN = 1;				//Enable DRUN mode for all peripherals using ME_RUN_PC[0]
	MC_ME.RUN_PC[0].R = 0xFE;
	//MC_ME.RUN_PC[0].R = 0x00000000;  /* gate off clock for all RUN modes */
	//MC_ME.RUN_PC[1].R = 0x000000FE;  /* config. peri clock for all RUN modes */
	MC_ME.PCTL[92].B.RUN_CFG = 0x0; //LINFlexD_0: Select run config 1
	MC_ME.PCTL[220].B.RUN_CFG = 0x0; //LINFlexD_1: Select peripheral config RUN_PC[0]. No LINFlex_D_2 on Panther

	// Set PLL1 as system clock  150M
    MC_ME.DRUN_MC.R = 0x000300F4;

    //configure SC
    MC_CGM.SC_DC[0].R = 0x80000000 | 0x0;		 	//Enable divider | divide by 1  ::150M
    MC_CGM.SC_DC[1].R = 0x80000000 | 0x10000;		//Enable divider | divide by 2  ::75M  ::LINCLK
    MC_CGM.SC_DC[2].R = 0x80000000 | 0x30000;		//Enable divider | divide by 4  ::37.5M   ::PBRIDGE_x_CLK
    //configure AC0
    MC_CGM.AC0_SC.B.SELCTL = 0x2;					//connect PLL0_PHI  to AXU_0	::200M
    MC_CGM.AC0_DC0.R = 0x80000000 | 0x40000;		//Enable divider | divide by 5  ::40M	::PER_CLK
//  MC_CGM.AC0_DC1.R = 0x80000000 | 0x70000;		//Enable divider | divide by 8  ::25M	::SD_CLK
    MC_CGM.AC0_DC2.R = 0x80000000 | 0x40000;		//Enable divider | divide by 5  ::40M	::SAR_CLK
    MC_CGM.AC0_DC3.R = 0x80000000 | 0x40000;		//Enable divider | divide by 5 	::40M	::DSPI_CLK0
    MC_CGM.AC0_DC4.R = 0x80000000 | 0x40000;		//Enable divider | divide by 5 	::40M	::DSPI_CLK1/LINCLK en
    //configure AC1
//    MC_CGM.AC1_SC.B.SELCTL = 0x1;					//connect XOSC to AUX_1	::40M
//    MC_CGM.AC1_DC0.R = 0x80000000 | 0x10000;		//Enable divider | divide by 2  ::20M	::PD_LFAST_PLL/BD_LFAST_PLL/SIPI_CLK_OUT
    //configure AC2
//    MC_CGM.AC2_SC.B.SELCTL = 0x2;					//connect PLL0_PHI  to AUX_2	::200M
//    MC_CGM.AC2_DC0.R = 0x80000000 | 0x70000;		//Enable divider | divide by 8  ::25M	::SENT_CLK
    //configure AC3
    MC_CGM.AC3_SC.B.SELCTL =1;						//connect XOSC to AUX_3	::40M	::for PLL0
    //configure AC4
    MC_CGM.AC4_SC.B.SELCTL =3;						//connect PLL0_PHI1 to AUX_4	::40M	::for PLL1
    //configure AC5
    MC_CGM.AC5_SC.B.SELCTL =2;						//connect PLL0_PHI  to AXU_5	::200M
    MC_CGM.AC5_DC0.R = 0x80000000 | 0x00000;		//Enable divider | divide by 1  ::200M	::eTPU_CLK
    MC_CGM.AC5_DC1.R = 0x80000000 | 0x10000;		//Enable divider | divide by 2  ::100M	::eMIOS_CLK
    //configure AC6
    MC_CGM.AC6_SC.B.SELCTL = 0x4;					//connect PLL1_PHI  to AXU_6	::200M
    MC_CGM.AC6_DC0.R = 0x80000000 | 0x130000;		//Enable divider | divide by 20 ::10M	::CLKOUT
    //configure AC8
    MC_CGM.AC8_SC.B.SELCTL =1;						//connect XOSC  to AXU_8	::40M
    MC_CGM.AC8_DC0.R = 0x80000000 | 0x40000;		//Enable divider | divide by 5  ::8M	::CAN_CLK
    //configure AC9
    MC_CGM.AC9_SC.B.SELCTL =1;						//connect XOSC	  to AXU_9		::20M	//XOSC connect ;should change
    MC_CGM.AC9_DC0.R = 0x80000000 | 0x270000;		//Enable divider | divide by 40 ::1M	::RTI_CLK ::MB is 13, A1 is 27
    //configure AC10
//    MC_CGM.AC10_SC.B.SELCTL =2;						//connect PLL0_PHI to AXU_10	::200M
//    MC_CGM.AC10_DC0.R = 0x80000000 | 0x30000;		//Enable divider | divide by 4  ::50M	::TXCLK_REF_CLK

    //开发板上的XOSC为20M，所以需要在分频时减少或者在倍频时增加,A0样为40M
    //configure PLL0
    PLLDIG.PLL0CR.B.CLKCFG = 0;						//PLL0 on
    				//RFDPHI1 = 10, RFDPHI = 3, PREDIV = 2, MFD = 20 (0x14)/* MB is 0x3C, A0 is 0x1E; just change this */
    PLLDIG.PLL0DV.R = 0x50000000 |0x00030000 |0x00002000 |0x001E; //PLL0_PHI = 200M;  PLL0 PHI1 = 60M
    //configure PLL1
    PLLDIG.PLL1CR.B.CLKCFG = 0;						//PLL1 on
    PLLDIG.PLL1DV.R = 0x00040000 |0x0014; 			//RFDPHI = 4, MFD = 20 (0x14h)	::PLL1_PHI = 150M

    //Mode transition to apply the PLL0 setup and set Normal mode with PLL running
    MC_ME.MCTL.R = 0x30005AF0;              //DRUN Mode & Key
    MC_ME.MCTL.R = 0x3000A50F;              //DRUN Mode & Key

    while(!MC_ME.GS.B.S_PLL0);              //ME_GS Wait for PLL stabilization.
    while(MC_ME.GS.B.S_MTRANS);             //Waiting for end of transaction
    while(MC_ME.GS.B.S_CURRENT_MODE != 3);  // ME_GS Check DRUN mode has successfully been entered
}

void hwReset(void)
{
  Rest_AllGate();
  MC_ME.CADDR[0].B.RMC = 1;
  MC_ME.CADDR[1].B.RMC = 1;
  MC_ME.MCTL.R = 0xF0005AF0;              //DRUN Mode & Key
  MC_ME.MCTL.R = 0xF000A50F;              //DRUN Mode & Key
}

/*
 * Name:		SYS_RT_Init
 * Function:	对Real Time Clock 进行初始化以及中断配置
 * Input:		null
 * Return:		null
 * Link:		SYS_CLK_Init();INT_RT_Isr();
 * Attention:	需要在SYS_CLK_Init()中配置好RT的时钟输入.效果是产生一个定时中断在INT_RT_Isr()中,且需要在中断里重置该定时数值
 * */
void SYS_RT_Init(void)
{
  INTC_0.PSR[239].R = INT_RT_CORE_PRIORITY;	//将中断送给core1 && 设置该中断优先级为30

  PIT_0.MCR.R = 0x00;			//使能PIT模块，FRZ=0(debug模式下timer仍然计时)
  PIT_0.RTI_LDVAL.R = 1000; //由时钟初始化为1M输入RTI，所以1000即是1ms，从该值自减到0后产生中断，并自动加载该值，时钟源为RTI_CLK
  PIT_0.RTI_TCTRL.B.TIE = 1;			//允许RTI产生溢出中断
  PIT_0.RTI_TCTRL.B.TEN = 1;			//RTI开始工作

  //INTC_0.PSR[226].R = INT_to_Core1 | 0x1E;	//用于延时使用,无中断
  PIT_0.TIMER[0].LDVAL.R = 4000;	//0.1ms周期，时钟源为PER_CLK
  PIT_0.TIMER[0].TCTRL.B.TIE = 0;
  PIT_0.TIMER[0].TCTRL.B.TEN = 0;		//开始工作

  INTC_0.PSR[227].R = INT_PIT01_CORE_PRIORITY;	//PIT0_1
  PIT_0.TIMER[1].LDVAL.R = 400000; //10ms周期，时钟源为PER_CLK
  PIT_0.TIMER[1].TCTRL.B.TIE = 1;
  PIT_0.TIMER[1].TCTRL.B.TEN = 0;	//暂时不开始工作

  //PIT0_2 为Core0使用于产生时间基准

  //PIT0_3-7 用于Core1的精准计时 1，不使用中断
        //enable stm clock and set div value to 150, to generate 0.25M clock
        STM_0.CR.R = 0x00009500;
        STM_0.CR.B.TEN = 1;
}


void SYS_Shut10msTimer(void)
{
  INTC_0.PSR[227].R = 0;	//PIT0_1
  PIT_0.TIMER[1].TCTRL.B.TIE = 0;
  PIT_0.TIMER[1].TCTRL.B.TEN = 0;
  PIT_0.TIMER[1].TFLG.B.TIF = 1;
}

void SYS_Reset10msTimer(void)
{
  PIT_0.TIMER[1].TCTRL.B.TIE = 0;
  PIT_0.TIMER[1].TCTRL.B.TEN = 0;

  PIT_0.TIMER[1].LDVAL.R = 400000; //10ms周期，时钟源为PER_CLK
  PIT_0.TIMER[1].TCTRL.B.TIE = 1;
  PIT_0.TIMER[1].TCTRL.B.TEN = 1;			//开始工作
  INTC_0.PSR[227].R = INT_PIT01_CORE_PRIORITY;	//PIT0_1
}

/*
 * 使用0.1ms为周期延时
 * */
void wait_micsec(uint32_t ms)
{
	PIT_0.TIMER[0].TCTRL.B.TEN	= 0;			//停止工作
	PIT_0.TIMER[0].LDVAL.R = 4000;
	PIT_0.TIMER[0].TCTRL.B.TEN	= 1;			//开始工作
	while(ms)
	{
		while(PIT_0.TIMER[0].TFLG.B.TIF == 0);
		PIT_0.TIMER[0].TFLG.B.TIF = 1;//clear INT flag
		ms --;
	}
	PIT_0.TIMER[0].TCTRL.B.TEN	= 0;			//停止工作
}

//开始计时，最长时间为10s， 单位为0.01ms
void StartTimer(uint8_t timer)
{
  if( (timer >= 3) && (timer <= 7) )//定时器分配判断
    {
      PIT_0.TIMER[timer].TCTRL.B.TEN = 0;			//开始初始化
      PIT_0.TIMER[timer].LDVAL.R = 400000000u;	//10s周期，时钟源为PER_CLK
      PIT_0.TIMER[timer].TCTRL.B.TIE = 0;
      PIT_0.TIMER[timer].TCTRL.B.TEN = 1;			//开始工作
    }
}

//获取当前耗时，并返回耗费时间；单位为0.01ms
uint32_t GetTimerAndShut(uint8_t timer)
{
  uint32_t currentTime = 0, recode = 0;
  if( (timer >= 3) && (timer <= 7) )//定时器分配判断
    {
      currentTime = PIT_0.TIMER[timer].CVAL.R;
      currentTime = 400000000u - currentTime;
      recode = currentTime / 400;			//单位为0.01ms
      PIT_0.TIMER[timer].TCTRL.B.TEN = 0;
    }
  return recode;
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



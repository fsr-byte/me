/*
 * SYS.c
 *
 *  Created on: 2018��9��5��
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

    //�������ϵ�XOSCΪ20M��������Ҫ�ڷ�Ƶʱ���ٻ����ڱ�Ƶʱ����,A0��Ϊ40M
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
 * Function:	��Real Time Clock ���г�ʼ���Լ��ж�����
 * Input:		null
 * Return:		null
 * Link:		SYS_CLK_Init();INT_RT_Isr();
 * Attention:	��Ҫ��SYS_CLK_Init()�����ú�RT��ʱ������.Ч���ǲ���һ����ʱ�ж���INT_RT_Isr()��,����Ҫ���ж������øö�ʱ��ֵ
 * */
void SYS_RT_Init(void)
{
  INTC_0.PSR[239].R = INT_RT_CORE_PRIORITY;	//���ж��͸�core1 && ���ø��ж����ȼ�Ϊ30

  PIT_0.MCR.R = 0x00;			//ʹ��PITģ�飬FRZ=0(debugģʽ��timer��Ȼ��ʱ)
  PIT_0.RTI_LDVAL.R = 1000; //��ʱ�ӳ�ʼ��Ϊ1M����RTI������1000����1ms���Ӹ�ֵ�Լ���0������жϣ����Զ����ظ�ֵ��ʱ��ԴΪRTI_CLK
  PIT_0.RTI_TCTRL.B.TIE = 1;			//����RTI��������ж�
  PIT_0.RTI_TCTRL.B.TEN = 1;			//RTI��ʼ����

  //INTC_0.PSR[226].R = INT_to_Core1 | 0x1E;	//������ʱʹ��,���ж�
  PIT_0.TIMER[0].LDVAL.R = 4000;	//0.1ms���ڣ�ʱ��ԴΪPER_CLK
  PIT_0.TIMER[0].TCTRL.B.TIE = 0;
  PIT_0.TIMER[0].TCTRL.B.TEN = 0;		//��ʼ����

  INTC_0.PSR[227].R = INT_PIT01_CORE_PRIORITY;	//PIT0_1
  PIT_0.TIMER[1].LDVAL.R = 400000; //10ms���ڣ�ʱ��ԴΪPER_CLK
  PIT_0.TIMER[1].TCTRL.B.TIE = 1;
  PIT_0.TIMER[1].TCTRL.B.TEN = 0;	//��ʱ����ʼ����

  //PIT0_2 ΪCore0ʹ���ڲ���ʱ���׼

  //PIT0_3-7 ����Core1�ľ�׼��ʱ 1����ʹ���ж�
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

  PIT_0.TIMER[1].LDVAL.R = 400000; //10ms���ڣ�ʱ��ԴΪPER_CLK
  PIT_0.TIMER[1].TCTRL.B.TIE = 1;
  PIT_0.TIMER[1].TCTRL.B.TEN = 1;			//��ʼ����
  INTC_0.PSR[227].R = INT_PIT01_CORE_PRIORITY;	//PIT0_1
}

/*
 * ʹ��0.1msΪ������ʱ
 * */
void wait_micsec(uint32_t ms)
{
	PIT_0.TIMER[0].TCTRL.B.TEN	= 0;			//ֹͣ����
	PIT_0.TIMER[0].LDVAL.R = 4000;
	PIT_0.TIMER[0].TCTRL.B.TEN	= 1;			//��ʼ����
	while(ms)
	{
		while(PIT_0.TIMER[0].TFLG.B.TIF == 0);
		PIT_0.TIMER[0].TFLG.B.TIF = 1;//clear INT flag
		ms --;
	}
	PIT_0.TIMER[0].TCTRL.B.TEN	= 0;			//ֹͣ����
}

//��ʼ��ʱ���ʱ��Ϊ10s�� ��λΪ0.01ms
void StartTimer(uint8_t timer)
{
  if( (timer >= 3) && (timer <= 7) )//��ʱ�������ж�
    {
      PIT_0.TIMER[timer].TCTRL.B.TEN = 0;			//��ʼ��ʼ��
      PIT_0.TIMER[timer].LDVAL.R = 400000000u;	//10s���ڣ�ʱ��ԴΪPER_CLK
      PIT_0.TIMER[timer].TCTRL.B.TIE = 0;
      PIT_0.TIMER[timer].TCTRL.B.TEN = 1;			//��ʼ����
    }
}

//��ȡ��ǰ��ʱ�������غķ�ʱ�䣻��λΪ0.01ms
uint32_t GetTimerAndShut(uint8_t timer)
{
  uint32_t currentTime = 0, recode = 0;
  if( (timer >= 3) && (timer <= 7) )//��ʱ�������ж�
    {
      currentTime = PIT_0.TIMER[timer].CVAL.R;
      currentTime = 400000000u - currentTime;
      recode = currentTime / 400;			//��λΪ0.01ms
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



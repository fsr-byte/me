/*
 * System.h
 *
 *  Created on: 2018Äê10ÔÂ9ÈÕ
 *      Author: helei
 */

#ifndef HAL_SYSTEM_H_
#define HAL_SYSTEM_H_

#include "typedefs.h"

#ifdef __SYSTEM_GLOBALS__
#define __SYSTEM_EXTERN__
#else
#define __SYSTEM_EXTERN__  extern
#endif

#define WAKEUPKL15		(INTstruct.IO_INPUT.B.IO_0)
#define WAKEUP1			(INTstruct.IO_INPUT.B.IO_4)
#define WAKEUP2			(INTstruct.IO_INPUT.B.IO_5)
#define WAKEUPCAN_LIN	INTstruct.WU_SOURCE.B.PHY_WU
#define WAKEUPLDT		INTstruct.WU_SOURCE.B.LDT_WU

#define D_IN1_PAD	GPIO_PORTH+11	//DIN_T1
#define D_IN2_PAD	GPIO_PORTH+12	//DIN_T2
#define D_IN3_PAD	GPIO_PORTH+14	//DIN_T3
#define D_IN4_PAD	GPIO_PORTH+15	//DIN_T4
#define D_IN5_PAD	GPIO_PORTY+10	//DIN_T5
#define D_IN6_PAD	GPIO_PORTY+9	//DIN_T6
#define D_IN7_PAD	GPIO_PORTY+7	//DIN_T7
#define D_IN8_PAD	GPIO_PORTX+7	//DIN_T8
#define D_IN9_PAD	GPIO_PORTW+1	//DIN_T9
#define D_IN10_PAD	GPIO_PORTK+11	//DIN_T10
#define D_IN11_PAD	GPIO_PORTJ+3	//DIN_T11
#define D_IN12_PAD	GPIO_PORTK+7	//DIN_T12
#define D_IN13_PAD	GPIO_PORTK+0	//DIN_T13
#define D_IN14_PAD	GPIO_PORTJ+15	//DIN_T14
#define D_IN15_PAD	GPIO_PORTJ+13	//DIN_T15
#define D_IN16_PAD	GPIO_PORTJ+12	//DIN_T16
#define D_IN17_PAD	GPIO_PORTJ+11	//DIN_T17
#define D_IN18_PAD	GPIO_PORTJ+5	//DIN_T18
#define D_IN19_PAD	GPIO_PORTW+3	//DIN_T19

#define D_IN20_PAD	GPIO_PORTK+13	//DIN_T20
#define D_IN21_PAD	GPIO_PORTJ+1	//DIN_T21
#define D_IN22_PAD	GPIO_PORTI+3	//DIN_T22
#define D_IN23_PAD	GPIO_PORTC+10	//DIN_T23  :: B0 is 10, A1 is 13; enet can't be use in A1 board
#define D_IN24_PAD	GPIO_PORTF+1	//DIN_T24
#define D_IN25_PAD	GPIO_PORTG+10	//DIN_T25
#define D_IN26_PAD	GPIO_PORTY+6	//DIN_T26
#define D_IN27_PAD	GPIO_PORTY+2	//DIN_T27
#define D_IN28_PAD	GPIO_PORTY+1	//DIN_T28
#define D_IN29_PAD	GPIO_PORTX+13	//DIN_T29
#define D_IN30_PAD	GPIO_PORTX+2	//DIN_T30
#define D_IN31_PAD	GPIO_PORTX+1	//DIN_T31

#define DIN_KL30a2_C	(GPIO_PORTK+10)	//Pull Up resistance for All DIN is pull up setting


//------------------ channel using --------------------
#define F_Collision_CHANNEL		       eMIOS_1_13
#define F_WaterPump_CHANNEL		eMIOS_0_18
#define F_HVInterlock_CHANNEL	       eMIOS_0_09
#define F_VacuumPump_CHANNEL	       eMIOS_0_12

#define AGINGTEST_F_IN_CHANNEL_0 eMIOS_1_16
#define AGINGTEST_F_IN_CHANNEL_1 eMIOS_1_20
#define AGINGTEST_F_IN_CHANNEL_2 eMIOS_1_17
#define AGINGTEST_F_IN_CHANNEL_3 eMIOS_0_12
#define AGINGTEST_F_IN_CHANNEL_4 eMIOS_0_09
#define AGINGTEST_F_IN_CHANNEL_5 eMIOS_0_18
#define AGINGTEST_F_IN_CHANNEL_6 eMIOS_1_13
#define AGINGTEST_F_IN_CHANNEL_7 eMIOS_0_10

#define AGINGTEST_F_OUT_CHANNEL_0 ETPU_ENGINE_A_CHANNEL(15)  //PWM_C5 
#define AGINGTEST_F_OUT_CHANNEL_1 ETPU_ENGINE_A_CHANNEL(16)  //PWM_C6
#define AGINGTEST_F_OUT_CHANNEL_2 ETPU_ENGINE_A_CHANNEL(14)  //PWM_C4
#define AGINGTEST_F_OUT_CHANNEL_3 ETPU_ENGINE_A_CHANNEL(11)  //PWM_C1
#define AGINGTEST_F_OUT_CHANNEL_4 ETPU_ENGINE_A_CHANNEL(18)  //PWM_C8 
#define AGINGTEST_F_OUT_CHANNEL_5 ETPU_ENGINE_A_CHANNEL(13)  //PWM_C3 
#define AGINGTEST_F_OUT_CHANNEL_6 ETPU_ENGINE_A_CHANNEL(17)  //PWM_C7
#define AGINGTEST_F_OUT_CHANNEL_7 ETPU_ENGINE_A_CHANNEL(12)  //PWM_C2 
//----ADC---- channel in ADC_Buff[] --------
#define ADC_AD_SEN1	(0)
#define ADC_AIN15	(1)
#define ADC_AIN14	(2)
#define ADC_AIN13	(3)
#define ADC_AIN12	(4)
#define ADC_AIN11	(5)
#define ADC_AIN10	(6)
#define ADC_AIN9	(7)
#define ADC_AIN8	(8)
#define ADC_AIN7	(9)
#define ADC_AIN6	(10)
#define ADC_AIN5	(11)
#define ADC_AIN4	(12)
#define ADC_AIN3	(13)
#define ADC_AIN2	(14)
#define ADC_AIN1	(15)
#define ADC_KL30_1	(16)
#define ADC_AIN19	(17)
#define ADC_AD_SEN2	(18)
#define ADC_AD_SEN3	(19)
#define ADC_BTS5180_IS	(20)
#define ADC_BTS5200_IS	(21)
#define ADC_AD_MUX_OUT	(22)
#define ADC_AIN16	(23)
#define ADC_AIN17	(24)
#define ADC_AIN18	(25)
#define ADC_KL30_2	(26)
#define ADC_AIN20	(27)

__SYSTEM_EXTERN__ void Init_System(void);

__SYSTEM_EXTERN__ void HAL_Set_HALVersion(float Value);
__SYSTEM_EXTERN__ void HAL_Get_SwitchKey_Test(void);
__SYSTEM_EXTERN__ void HAL_Get_SwitchKey_S11P01(void);
__SYSTEM_EXTERN__ void HAL_Get_SwitchKey_None(void);

__SYSTEM_EXTERN__ void Init_CanMessage(void);
__SYSTEM_EXTERN__ void NM_ShutAll_CANTxPeriodMessage(void);
__SYSTEM_EXTERN__ void NM_SetMessage(void);
__SYSTEM_EXTERN__ void System_CANBaseCycle(void);

__SYSTEM_EXTERN__ void Init_DIO(void);
__SYSTEM_EXTERN__ void HAL_Capture_Digital(void);
__SYSTEM_EXTERN__ uint8_t HAL_Get_Digital(uint8_t Channel);
__SYSTEM_EXTERN__ void HAL_Capture_ADC(void);
__SYSTEM_EXTERN__ float HAL_Get_ADC(unsigned char Channel);

__SYSTEM_EXTERN__ void HAL_Capture_Fin(void);
__SYSTEM_EXTERN__ float HAL_Get_Finf(uint8_t Channel);
__SYSTEM_EXTERN__ float HAL_Get_FinDuty(uint8_t Channel);

__SYSTEM_EXTERN__ void HAL_Drive_HLS(void);
__SYSTEM_EXTERN__ void HAL_Drive_LS(uint8_t Channel,uint8_t Value);
__SYSTEM_EXTERN__ void HAL_Drive_HS(uint8_t Channel,uint8_t Value);

__SYSTEM_EXTERN__ void HAL_Set_WaterPwm(uint32_t fre,uint16_t duty);
__SYSTEM_EXTERN__ void HAL_Set_LockPwm(uint32_t fre,uint16_t duty);


__SYSTEM_EXTERN__ void HAL_Drive_Sleep(uint8_t Value);
__SYSTEM_EXTERN__ void System_5ms(void);
__SYSTEM_EXTERN__ void System_MainCycle(void);


#endif /* HAL_SYSTEM_H_ */

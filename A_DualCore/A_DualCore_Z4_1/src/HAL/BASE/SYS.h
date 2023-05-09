/*
 * SYS.h
 *
 *  Created on: 2018年9月5日
 *      Author: helei
 */

#ifndef BASE_SYS_H_
#define BASE_SYS_H_

#include "typedefs.h"

#ifdef __SYS_GLOBALS__
#define __SYS_EXTERN__
#else
#define __SYS_EXTERN__  extern
#endif

#define PLL0_CLK	200000000
#define PLL1_CLK	150000000
#define MAIN_CLK	(PLL1_CLK/1)
#define DSPI_CLK	(PLL0_CLK/5)
#define FLEXCAN_CLK	(PLL0_CLK/5)
#define LINFLEX_CLK	(MAIN_CLK/2)

#define INT_to_Core1	(0x4000)
#define INT_to_Core0	(0x8000)
#define INT_to_DualCore	(0xC000)

//中断处理核及优先级 范围0-63 越大越高；该部分可以配置
#define INT_RT_CORE_PRIORITY			(INT_to_Core1 | 30)
#define INT_PIT01_CORE_PRIORITY			(INT_to_Core1 | 30)	//用于10ms定时器，在中断中发送CAN周期性报文
//#define INT_SI0_CORE_PRIORITY			(INT_to_Core0 | 30)	//Core1产生，Core0响应中断

#define	INT_CAN0RX_07_CORE_PRIORITY		(INT_to_Core1 | 30)
#define	INT_CAN0RX_815_CORE_PRIORITY		(INT_to_Core1 | 30)

#define	INT_CAN1RX_07_CORE_PRIORITY		(INT_to_Core1 | 40)

#define	INT_CAN2RX_07_CORE_PRIORITY		(INT_to_Core1 | 30)

#define	INT_CAN3RX_07_CORE_PRIORITY		(INT_to_DualCore | 30) //(INT_to_Core1 | 30)
#define	INT_CAN3RX_815_CORE_PRIORITY		(INT_to_Core1 | 30)
#define	INT_CAN3RX_1631_CORE_PRIORITY		(INT_to_Core1 | 30)
#define	INT_CAN3RX_3263_CORE_PRIORITY		(INT_to_Core1 | 30)

#define INT_ENETTX_CORE_PRIORITY		(INT_to_Core1 | 30)
#define INT_ENETRX_CORE_PRIORITY		(INT_to_Core1 | 30)
#define INT_LINTX_CORE_PRIORITY			(INT_to_Core1 | 30)
#define INT_LINRX_CORE_PRIORITY			(INT_to_Core1 | 30)
#define INT_EMIOSMCB_CORE_PRIORITY		(INT_to_Core1 | 30)	//为PWM输入提供基准计数
#define INT_EMIOSIPWM_CORE_PRIORITY		(INT_to_Core1 | 30) //PWM输入检测

//待使用
typedef struct SYS_HW_STATUS_struct_tag_{
	uint8_t curExtStatus;
}SYS_HW_STATUS_tag_;


__SYS_EXTERN__ void SYS_CLOCK_Init(void);

__SYS_EXTERN__ void hwReset(void);

__SYS_EXTERN__ void SYS_RT_Init(void);
__SYS_EXTERN__ void SYS_Shut10msTimer(void);
__SYS_EXTERN__ void SYS_Reset10msTimer(void);
__SYS_EXTERN__ void wait_micsec(uint32_t ms);

__SYS_EXTERN__ void StartTimer(uint8_t timer);
__SYS_EXTERN__ uint32_t GetTimerAndShut(uint8_t timer);

__SYS_EXTERN__ void SYS_Enable_EXTInterrupt(void);
__SYS_EXTERN__ void SYS_Disable_EXTInterrupt(void);
__SYS_EXTERN__ uint8_t SYS_GetCurIntStatus(void);
__SYS_EXTERN__ void SYS_SetCurIntStatus(uint8_t status);

#endif /* BASE_SYS_H_ */

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

#define INT_to_Core1	(0x4000)
#define INT_to_Core0	(0x8000)
#define INT_to_DualCore	(0xC000)

//中断处理核及优先级 范围0-63 越大越高；该部分可以配置
#define INT_PIT02_CORE_PRIORITY			(INT_to_Core0 | 30)	//用于1ms定时器，为Core0程序提供1ms计时SystemTickMs
#define INT_SI0_CORE_PRIORITY			(INT_to_Core0 | 30)	//Core1产生，Core0响应中断

__SYS_EXTERN__ void SYS_Timer_Init(void);
__SYS_EXTERN__ void SYS_SI_Init(void);
__SYS_EXTERN__ void hwReset(void);
__SYS_EXTERN__ void SYS_ResetCore(void);//重启Core0

__SYS_EXTERN__ void SYS_Enable_EXTInterrupt(void);
__SYS_EXTERN__ void SYS_Disable_EXTInterrupt(void);
__SYS_EXTERN__ uint8_t SYS_GetCurIntStatus(void);
__SYS_EXTERN__ void SYS_SetCurIntStatus(uint8_t status);

#endif /* BASE_SYS_H_ */

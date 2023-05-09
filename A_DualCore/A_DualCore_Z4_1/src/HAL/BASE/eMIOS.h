/*
 * eMIOS.h
 *
 *  Created on: 2018年9月10日
 *      Author: helei
 */

#ifndef HAL_BASE_EMIOS_H_
#define HAL_BASE_EMIOS_H_

#include "typedefs.h"

#ifdef __eMIOS_GLOBALS__
#define __eMIOS_EXTERN__
#else
#define __eMIOS_EXTERN__  extern
#endif

#define EMIOS0	0
#define EMIOS1	1

#define EMIOSNUM	29
#define EMIOS_OVERTIME	200
#define EMIOSCLK	5000000.0f
#define MCB_COUNT	0x00FFFFFFu

typedef enum {
	eMIOS_0_08 = 0,
	eMIOS_0_09,
	eMIOS_0_10,
	eMIOS_0_11,//3
	eMIOS_0_12,
	eMIOS_0_13,
	eMIOS_0_14,//6
	eMIOS_0_15,
	eMIOS_0_16,
	eMIOS_0_17,
	eMIOS_0_18,//10
	eMIOS_0_19,
	eMIOS_0_20,
	eMIOS_0_21,
	eMIOS_0_22,//14
	eMIOS_1_08,
	eMIOS_1_09,
	eMIOS_1_10,
	eMIOS_1_11,
	eMIOS_1_12,
	eMIOS_1_13,
	eMIOS_1_14,
	eMIOS_1_15,
	eMIOS_1_16,
	eMIOS_1_17,
//	eMIOS_1_18,
	eMIOS_1_19,
	eMIOS_1_20,
	eMIOS_1_21,
	eMIOS_1_22
} _eMIOS_channel_;

typedef enum {
	unlock = 0,
	lock = 1
} _eMIOS_flag_;

typedef struct _eMIOS_PWMIN_data_tag_ {
	uint32_t A_pre;
	uint32_t A;
	uint32_t B;
	_eMIOS_flag_ flag;
	uint32_t	stoptick;
	float freq;
	float duty;
       uint32_t  period;
       uint32_t  pulsewidth;
       uint8_t    InitCnt; /*切换模式后丢弃前几次采样*/
}_eMIOS_PWMIN_data_;

__eMIOS_EXTERN__ _eMIOS_PWMIN_data_ eMIOS_PWMin_data[EMIOSNUM];

__eMIOS_EXTERN__ void eMIOS_Init_All(void);

__eMIOS_EXTERN__  void eMIOS_IO_InitAll(void);
__eMIOS_EXTERN__  void AgingTest_eMIOS_IO_InitAll(void);
__eMIOS_EXTERN__ void eMIOS_INT_InitAll(void);
__eMIOS_EXTERN__ void eMIOS_Close(uint8_t x);
__eMIOS_EXTERN__ void eMIOS_Start(uint8_t x);
__eMIOS_EXTERN__ void eMIOS_Init(uint8_t x);

__eMIOS_EXTERN__ void eMIOS_CalculationAll(void);
__eMIOS_EXTERN__ void eMIOS_Calculation(_eMIOS_channel_ x);
__eMIOS_EXTERN__ void eMIOS_cycle(void);
__eMIOS_EXTERN__ void GetEMIOS0_9();
__eMIOS_EXTERN__ void GetEMIOS0_10();
__eMIOS_EXTERN__ void GetEMIOS0_12();
__eMIOS_EXTERN__ void GetEMIOS0_18();
__eMIOS_EXTERN__ void GetEMIOS1_13();
__eMIOS_EXTERN__ void GetEMIOS1_16();
__eMIOS_EXTERN__ void GetEMIOS1_17();
__eMIOS_EXTERN__ void GetEMIOS1_20();
#endif /* HAL_BASE_EMIOS_H_ */

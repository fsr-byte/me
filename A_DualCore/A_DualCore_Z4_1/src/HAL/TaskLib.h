/*
 * TaskLib.h
 *
 *  Created on: 2019Äê7ÔÂ11ÈÕ
 *      Author: helei
 */

#ifndef HAL_TASKLIB_H_
#define HAL_TASKLIB_H_

#include "typedefs.h"

#ifdef TASKLIB_GLOBALS
#define TASKLIB_EXTERN
#else
#define TASKLIB_EXTERN  extern
#endif

TASKLIB_EXTERN uint16_t LSChipStatus7240B;


TASKLIB_EXTERN void CheckHLSFaultsPOR (void);
TASKLIB_EXTERN void CheckLSFaults (void);
TASKLIB_EXTERN void CheckHSFaults (void);
TASKLIB_EXTERN void Task_NM (void);
TASKLIB_EXTERN void Task_GetSignal_Step1 (void);
TASKLIB_EXTERN void Task_GetSignal_Step2 (void);
TASKLIB_EXTERN void Task_OutputSignal (void);
TASKLIB_EXTERN void HwTest_OutputSignal (void);

TASKLIB_EXTERN void ChkBswWakeSrc(void);



#endif /* HAL_TASKLIB_H_ */

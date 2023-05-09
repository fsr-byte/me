/*
 * EX_Code.h
 *
 *  Created on: 2019Äê6ÔÂ24ÈÕ
 *      Author: helei
 */

#ifndef HAL_EXCHANGE_EX_CODE_H_
#define HAL_EXCHANGE_EX_CODE_H_

#include "typedefs.h"

#ifdef __EX_CODE_GLOBALS__
#define __EX_CODE_EXTERN__
#else
#define __EX_CODE_EXTERN__  extern
#endif


__EX_CODE_EXTERN__ void Ex_Init(void);

__EX_CODE_EXTERN__ uint8_t Ex_Base_LockGate(uint8_t gate);
__EX_CODE_EXTERN__ uint8_t Ex_Base_UnlockGate(uint8_t gate);

__EX_CODE_EXTERN__ uint8_t Ex_Cal_IntHandle(void);
__EX_CODE_EXTERN__ uint8_t Ex_Input_Task(void);
__EX_CODE_EXTERN__ uint8_t Ex_Output_Task(void);
__EX_CODE_EXTERN__ void Ex_Task(void);

#endif /* HAL_EXCHANGE_EX_CODE_H_ */

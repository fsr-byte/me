/*
 * Interrupt.h
 *
 *  Created on: 2018Äê9ÔÂ6ÈÕ
 *      Author: helei
 */

#ifndef HAL_INTERRUPT_H_
#define HAL_INTERRUPT_H_

#include "typedefs.h"

#ifdef __INTERRPUT_GLOBALS__
#define __INTERRPUT_EXTERN__
#else
#define __INTERRPUT_EXTERN__  extern
#endif

__INTERRPUT_EXTERN__ void INT_PIT0_1_ISR(void);
__INTERRPUT_EXTERN__ void INT_SI0_ISR(void);
__INTERRPUT_EXTERN__ void CAN3_RX_ISR(void);

#endif /* HAL_INTERRUPT_H_ */

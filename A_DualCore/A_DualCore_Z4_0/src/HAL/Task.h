/*
 * Task.h
 *
 *  Created on: 2019Äê7ÔÂ2ÈÕ
 *      Author: helei
 */

#ifndef HAL_TASK_H_
#define HAL_TASK_H_

#include "typedefs.h"

#ifdef __TASK_GLOBALS__
#define __TASK_EXTERN__
#else
#define __TASK_EXTERN__  extern
#endif

__TASK_EXTERN__ uint32_t tick_5ms, tick_10ms, tick_20ms, tick_50ms,
		tick_100ms, tick_500ms, tick_1000ms;
__TASK_EXTERN__ uint8_t tick_5ms_flag, tick_10ms_flag, tick_20ms_flag, tick_50ms_flag,
		tick_100ms_flag, tick_500ms_flag, tick_1000ms_flag;


__TASK_EXTERN__ void TASK_Schedule(void);



#endif /* HAL_TASK_H_ */

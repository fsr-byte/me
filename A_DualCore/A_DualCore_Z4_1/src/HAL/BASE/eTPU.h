/*
 * eTPU.h
 *
 *  Created on: 2018��9��11��
 *      Author: helei
 */

#ifndef HAL_BASE_ETPU_H_
#define HAL_BASE_ETPU_H_

#include "typedefs.h"
#include "untitled_etpu_gct.h"
#include "etpu_pwm.h" /* PWM */

#ifdef __eTPU_GLOBALS__
#define __eTPU_EXTERN__
#else
#define __eTPU_EXTERN__  extern
#endif



__eTPU_EXTERN__ void eTPU_Init(void);

__eTPU_EXTERN__ void eTPU_IO_Init(void);


#endif /* HAL_BASE_ETPU_H_ */

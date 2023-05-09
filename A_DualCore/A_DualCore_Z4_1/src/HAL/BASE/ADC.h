/*
 * ADC.h
 *
 *  Created on: 2018Äê9ÔÂ5ÈÕ
 *      Author: helei
 */

#ifndef BASE_ADC_H_
#define BASE_ADC_H_

#include "typedefs.h"

#ifdef __ADC_GLOBALS__
#define __ADC_EXTERN__
#else
#define __ADC_EXTERN__  extern
#endif

#define ADCNUM	28

__ADC_EXTERN__ uint16_t ADC_Buff[ADCNUM];

__ADC_EXTERN__ void SARADC_Init(void);
__ADC_EXTERN__ void SARADC_GetAll(void);
__ADC_EXTERN__ void SARADC_Get1(void);


#endif /* BASE_ADC_H_ */

/*
 * BTS.h
 *
 *  Created on: 2018年9月10日
 *      Author: helei
 */

#ifndef HAL_MODULES_BTS_H_
#define HAL_MODULES_BTS_H_

#include "typedefs.h"

#ifdef __BTS_GLOBALS__
#define __BTS_EXTERN__
#else
#define __BTS_EXTERN__  extern
#endif

#define BTS_GETADC()	SARADC_Get1()
#define BTS_KL30a1_C	(GPIO_PORTK+14)		//Pull Up resistance for diagnostic
#define KL30a1_C_Set()  		SIUL_SetPad(BTS_KL30a1_C)
#define KL30a1_C_Clear()  		SIUL_ClearPad(BTS_KL30a1_C)

/*Define for BTS5180*/
#define BTS5180_DEN  	(GPIO_PORTC+3)
#define BTS5180_DSEL	(GPIO_PORTC+4)
#define BTS5180_HS1		(GPIO_PORTA+4)
#define BTS5180_HS2		(GPIO_PORTA+5)
#define BTS5180_IS		ADC_Buff[20]
//置高
#define BTS5180_DEN_Set()  		SIUL_SetPad(BTS5180_DEN)
#define BTS5180_DSEL_Set()  	SIUL_SetPad(BTS5180_DSEL)
#define BTS5180_HS1_Set()  		SIUL_SetPad(BTS5180_HS1)
#define BTS5180_HS2_Set()  		SIUL_SetPad(BTS5180_HS2)

//置低
#define BTS5180_DEN_Clear()  	SIUL_ClearPad(BTS5180_DEN)
#define BTS5180_DSEL_Clear()  	SIUL_ClearPad(BTS5180_DSEL)
#define BTS5180_HS1_Clear()  	SIUL_ClearPad(BTS5180_HS1)
#define BTS5180_HS2_Clear()  	SIUL_ClearPad(BTS5180_HS2)


/*Define for BTS5200*/
#define BTS5200_DEN		(GPIO_PORTD+11)
#define BTS5200_DSEL0	(GPIO_PORTC+9)
#define BTS5200_DSEL1	(GPIO_PORTC+12)
#define BTS5200_HS11	(GPIO_PORTA+0)
#define BTS5200_HS12	(GPIO_PORTA+1)
#define BTS5200_HS13	(GPIO_PORTA+2)
#define BTS5200_HS14	(GPIO_PORTA+3)
#define BTS5200_IS		ADC_Buff[21]
//置高
#define BTS5200_DEN_Set()  		SIUL_SetPad(BTS5200_DEN)
#define BTS5200_DSEL0_Set()  	SIUL_SetPad(BTS5200_DSEL0)
#define BTS5200_DSEL1_Set()  	SIUL_SetPad(BTS5200_DSEL1)
#define BTS5200_HS11_Set()  	SIUL_SetPad(BTS5200_HS11)
#define BTS5200_HS12_Set()  	SIUL_SetPad(BTS5200_HS12)
#define BTS5200_HS13_Set()  	SIUL_SetPad(BTS5200_HS13)
#define BTS5200_HS14_Set()  	SIUL_SetPad(BTS5200_HS14)
//置低
#define BTS5200_DEN_Clear()  	SIUL_ClearPad(BTS5200_DEN)
#define BTS5200_DSEL0_Clear()  	SIUL_ClearPad(BTS5200_DSEL0)
#define BTS5200_DSEL1_Clear()  	SIUL_ClearPad(BTS5200_DSEL1)
#define BTS5200_HS11_Clear()  	SIUL_ClearPad(BTS5200_HS11)
#define BTS5200_HS12_Clear()  	SIUL_ClearPad(BTS5200_HS12)
#define BTS5200_HS13_Clear()  	SIUL_ClearPad(BTS5200_HS13)
#define BTS5200_HS14_Clear()  	SIUL_ClearPad(BTS5200_HS14)

typedef struct _BTS_data_tag_ {
	uint8_t status;
	uint32_t ADvalue;
	float	mA;
	uint8_t	openload;
	uint8_t shortload;
} _BTS_data_;

__BTS_EXTERN__ _BTS_data_ BTS5180_data[2];
__BTS_EXTERN__ _BTS_data_ BTS5200_data[4];

__BTS_EXTERN__ void BTS5180_Init(void);
__BTS_EXTERN__ void BTS5180_SetValue(uint8_t num, uint8_t value);
__BTS_EXTERN__ void BTS5180_Refresh(void);
__BTS_EXTERN__ void BTS5180_Diagnostic(void);

__BTS_EXTERN__ void BTS5200_Init(void);
__BTS_EXTERN__ void BTS5200_SetValue(uint8_t num, uint8_t value);
__BTS_EXTERN__ void BTS5200_Refresh(void);
__BTS_EXTERN__ void BTS5200_Diagnostic(void);


#endif /* HAL_MODULES_BTS_H_ */

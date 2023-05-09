/*
 * NCV7719.h
 *
 *  Created on: 2018年9月14日
 *      Author: helei
 */

#ifndef HAL_MODULES_NCV7719_H_
#define HAL_MODULES_NCV7719_H_

#include "typedefs.h"

#ifdef __NCV7719_GLOBALS__
#define __NCV7719_EXTERN__
#else
#define __NCV7719_EXTERN__  extern
#endif


#define NCV7719_CS	GPIO_PORTK+9
#define NCV7719_EN	GPIO_PORTK+8

#define NCV7719_CS_enable()		SIUL_ClearPad(NCV7719_CS)
#define NCV7719_CS_disable()	SIUL_SetPad(NCV7719_CS)

#define NCV7719_SPI		SELECT_DSPI1
#define NCV7719_CTAR	SELECT_CTAR0

#define NCV7719_Refresh_Times 	1

typedef union _NCV7719_INPUT1_6_tag_{
	uint16_t R;
	struct{
	uint16_t SRR:1;	// 1
	uint16_t HBSEL:1;//0
	uint16_t ULDSC:1;//0  Underload Shutdown should be set to 0, then LS can use; when set to 1, LS can't use.
	uint16_t HBEN6:1;//使能位1
	uint16_t HBEN5:1;
	uint16_t HBEN4:1;
	uint16_t HBEN3:1;
	uint16_t HBEN2:1;
	uint16_t HBEN1:1;
	uint16_t HBCNF6:1;//选择位HS(1)/LS(0)
	uint16_t HBCNF5:1;
	uint16_t HBCNF4:1;
	uint16_t HBCNF3:1;
	uint16_t HBCNF2:1;
	uint16_t HBCNF1:1;
	uint16_t OVLO:1;//1
	}B;
}_NCV7719_INPUT1_6_;

typedef union _NCV7719_INPUT7_8_tag_{
	uint16_t R;
	struct{
	uint16_t SRR:1;//1
	uint16_t HBSEL:1;//1
	uint16_t ULDSC:1;//0
	uint16_t 	:4;
	uint16_t HBEN8:1;//使能位1
	uint16_t HBEN7:1;
	uint16_t 	:4;
	uint16_t HBCNF8:1;//选择位HS(1)/LS(0)
	uint16_t HBCNF7:1;
	uint16_t OVLO:1;//1
	}B;
}_NCV7719_INPUT7_8_;

typedef struct _NCV7719_INOUTPUT_tag_{
	_NCV7719_INPUT1_6_ CH1_6;
	uint32_t CH1_6_recive;
	_NCV7719_INPUT7_8_ CH7_8;
	uint32_t CH7_8_recive;
}_NCV7719_INOUTPUT_;

__NCV7719_EXTERN__ _NCV7719_INOUTPUT_ NCV7719_data;

__NCV7719_EXTERN__ void NCV7719_Init(void);
__NCV7719_EXTERN__ uint32_t NCV7719_Refresh1_6(void);
__NCV7719_EXTERN__ uint32_t NCV7719_Refresh7_8(void);
__NCV7719_EXTERN__ void NCV7719_tx(uint16_t data);
__NCV7719_EXTERN__ uint32_t NCV7719_rx(void);




#endif /* HAL_MODULES_NCV7719_H_ */

/*
 * NCV7513B.h
 *
 *  Created on: 2018年9月5日
 *      Author: helei
 */

#ifndef MODULES_NCV7513B_H_
#define MODULES_NCV7513B_H_

#include "typedefs.h"

#ifdef __NCV7513B_GLOBALS__
#define __NCV7513B_EXTERN__
#else
#define __NCV7513B_EXTERN__  extern
#endif

#define NCV7513B_CS		GPIO_PORTF+11	//out
#define NCV7513B_EN2	GPIO_PORTH+7	//out
#define NCV7513B_FLTB	GPIO_PORTK+12	//in
#define NCV7513B_STAB	GPIO_PORTF+0	//in

#define NCV7513B_SPI	SELECT_DSPI1
#define NCV7513B_CTAR	SELECT_CTAR1

#define NCV7513B_RefreshTimes	1	//控制SPI传输次数，以保证数据的正确性

//ADDRESS
#define NCV7513B_GATE_SELECT		0
#define NCV7513B_DISABLE_MODE	1
#define NCV7513B_REFRESH			2
#define NCV7513B_FLAG_MASK		3
#define NCV7513B_NULL_USE		4

//DATA/CHANNEL Enable/Select
#define NCV7513B_D5	0x20
#define NCV7513B_D4	0x10
#define NCV7513B_D3	0x08
#define NCV7513B_D2	0x04
#define NCV7513B_D1	0x02
#define NCV7513B_D0	0x01
#define NCV7513B_DN	0x00	//不选择data位
#define NCV7513B_DA	0x3F	//选择所有data位

typedef union _NCV7513B_SI_data_tag_ {
	vuint16_t R;
	struct {
		vuint16_t :1;
		vuint16_t address:3;
		vuint16_t :6;
		vuint16_t data:6;
	} command;
} _NCV7513B_SI_data_;

typedef union _NCV7513B_SO_data_tag_ {
	vuint16_t R;
	struct {
		vuint16_t :4;
		vuint16_t CH5:2;
		vuint16_t CH4:2;
		vuint16_t CH3:2;
		vuint16_t CH2:2;
		vuint16_t CH1:2;
		vuint16_t CH0:2;
	} status;
} _NCV7513B_SO_data_;


__NCV7513B_EXTERN__ _NCV7513B_SO_data_ NCV7513B_SO_data;


__NCV7513B_EXTERN__ void NCV7513B_Init(void);
__NCV7513B_EXTERN__ void NCV7513B_Set_SI(uint8_t address, uint8_t data);
__NCV7513B_EXTERN__ void NCV7513B_Set_Data(uint8_t channel, uint8_t data);
__NCV7513B_EXTERN__ void NCV7513B_Set_Address(uint8_t address);
__NCV7513B_EXTERN__ void NCV7513B_Refresh(void);




#endif /* MODULES_NCV7513B_H_ */










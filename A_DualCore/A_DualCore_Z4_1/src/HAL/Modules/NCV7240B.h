/*
 * NCV7240B.h
 *
 *  Created on: 2018年9月5日
 *      Author: helei
 */

#ifndef MODULES_NCV7240B_H_
#define MODULES_NCV7240B_H_

#include "typedefs.h"

#ifdef __NCV7240B_GLOBALS__
#define __NCV7240B_EXTERN__
#else
#define __NCV7240B_EXTERN__  extern
#endif

#define NCV7240B_CS	GPIO_PORTH+8
#define NCV7240B_EN	GPIO_PORTG+9

#define NCV7240B_SPI	SELECT_DSPI1
#define NCV7240B_CTAR	SELECT_CTAR0

#define NCV7240B_RefreshTimes	4	//控制SPI传输次数，以保证数据的正确性

//CHANNEL MASK
#define NCV7240B_CHANNEL1_MASK	0b0000000000000011
#define NCV7240B_CHANNEL2_MASK	0b0000000000001100
#define NCV7240B_CHANNEL3_MASK	0b0000000000110000
#define NCV7240B_CHANNEL4_MASK	0b0000000011000000
#define NCV7240B_CHANNEL5_MASK	0b0000001100000000
#define NCV7240B_CHANNEL6_MASK	0b0000110000000000
#define NCV7240B_CHANNEL7_MASK	0b0011000000000000
#define NCV7240B_CHANNEL8_MASK	0b1100000000000000
//CHANNEL
#define NCV7240B_CHANNEL1	1
#define NCV7240B_CHANNEL2	2
#define NCV7240B_CHANNEL3	3
#define NCV7240B_CHANNEL4	4
#define NCV7240B_CHANNEL5	5
#define NCV7240B_CHANNEL6	6
#define NCV7240B_CHANNEL7	7
#define NCV7240B_CHANNEL8	8
#define NCV7240B_CHANNELALL	9
//MODE
#define NCV7240B_STANDBY		0b00
#define NCV7240B_INPUT			0b01
#define NCV7240B_ON				0b10
#define NCV7240B_OFF			0b11
//STATUS
#define NCV7240B_NORMAL			0b00
#define NCV7240B_OPENLOAD		0b10
#define NCV7240B_OVERLOAD		0b01

typedef union _NCV7240B_SI_data_tag_ {
	vuint16_t R;
	struct {
		vuint16_t channel8:2;
		vuint16_t channel7:2;
		vuint16_t channel6:2;
		vuint16_t channel5:2;
		vuint16_t channel4:2;
		vuint16_t channel3:2;
		vuint16_t channel2:2;
		vuint16_t channel1:2;
	} mode;
}_NCV7240B_SI_data_;

typedef union _NCV7240B_SO_data_tag_ {
	vuint16_t R;
	struct {
		vuint16_t channel8:2;
		vuint16_t channel7:2;
		vuint16_t channel6:2;
		vuint16_t channel5:2;
		vuint16_t channel4:2;
		vuint16_t channel3:2;
		vuint16_t channel2:2;
		vuint16_t channel1:2;
	} status;
} _NCV7240B_SO_data_;

__NCV7240B_EXTERN__ _NCV7240B_SO_data_ NCV7240B_SO_data;	//暂时对外部开放

__NCV7240B_EXTERN__ void NCV7240B_Init(void);
__NCV7240B_EXTERN__ void NCV7240B_Set_SI(uint8_t channel,uint8_t data);
__NCV7240B_EXTERN__ void NCV7240B_Refresh(void);

#endif /* MODULES_NCV7240B_H_ */

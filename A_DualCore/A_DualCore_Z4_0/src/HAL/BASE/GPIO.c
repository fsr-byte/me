/*
 * GPIO.c
 *
 *  Created on: 2018年9月5日
 *      Author: helei
 */

#define __GPIO_GLOBALS__

#include "derivative.h"
#include "GPIO.h"

/*****************INPUT Initial******************/
void SIUL_DigitalInput(uint8_t pad, uint16_t pad_in, uint32_t config, uint32_t config_in)
{
    SIUL2.MSCR0_255[pad].R = SIUL_INPUT | SIUL_PULL_DOWN | config;	//SIUL_PULL_UP//SIUL_PULL_DIS
    SIUL2.MSCR512_995[pad_in-512].R = config_in;
}

void SIUL_DigitalInputSimple(uint8_t pad, uint32_t config)
{
    SIUL2.MSCR0_255[pad].R = SIUL_INPUT | SIUL_PULL_DOWN | config;//helei:add "SIUL_PULL_DOWN"
}

void SIUL_AnalogInput(uint8_t pad, uint32_t config)
{
    SIUL2.MSCR0_255[pad].R = SIUL_ANALOG | config;
}

void SIUL_DigitalInput_LINRX(uint8_t pad, uint16_t pad_in, uint32_t config, uint32_t config_in)		//helei:SD 需要去除默认的上下拉，改为设置时使用
{
    SIUL2.MSCR0_255[pad].R = SIUL_INPUT | SIUL_PULL_UP | config;	//SIUL_PULL_UP//SIUL_PULL_DIS
    SIUL2.MSCR512_995[pad_in-512].R = config_in;
}

/*****************OUTPUT Initial******************/
void SIUL_DigitalOutput_LINTX(uint8_t pad, uint32_t config)
{
    SIUL2.MSCR0_255[pad].R = SIUL_OUTPUT | SIUL_PULL_UP | SIUL_SLEW_DIS | SIUL_DRIVE_FULL | config; //| SIUL_OPEND SIUL_PULL_UP
}

void SIUL_DigitalOutput(uint8_t pad, uint32_t config)
{
    SIUL2.MSCR0_255[pad].R = SIUL_OUTPUT | config;
}

void SIUL_DigitalIO(uint8_t pad, uint32_t config)
{
    SIUL2.MSCR0_255[pad].R = SIUL_BIDIR | config;
}

/*****************GPIO Operation******************/
void SIUL_ToggleIO(uint8_t pad)
{
    SIUL2.GPDO[pad].R = ~SIUL2.GPDI[pad].R;
}

void SIUL_SetPad(uint8_t pad)
{
	SIUL2.GPDO[pad].R = 1;
}

void SIUL_ClearPad(uint8_t pad)
{
	SIUL2.GPDO[pad].R = 0;
}

uint32_t SIUL_GetPadState(uint32_t pad)
{
	return SIUL2.GPDI[pad].R;
}
/***************** Interrupt ******************/
void SIUL_EnableExtInt(uint32_t maskEIRQ)
{
	SIUL2.DIRER0.R = SIUL2.DIRER0.R | maskEIRQ;				//ext INT enable
}

void SIUL_EnableExtIntRisingEdge(uint32_t maskEIRQ)
{
	SIUL2.IFER0.R = SIUL2.IFER0.R | maskEIRQ;				//filter enable
	SIUL2.IREER0.R = SIUL2.IREER0.R | maskEIRQ;			//rising edge INT enabled
}

void SIUL_EnableExtIntFallingEdge(uint32_t maskEIRQ)
{
	SIUL2.IFER0.R = SIUL2.IFER0.R | maskEIRQ;				//filter enable
	SIUL2.IFEER0.R = SIUL2.IFEER0.R | maskEIRQ;			//falling edge INT enabled
}

uint32_t SIUL_GetExtIntFlag(uint32_t maskEIRQ)
{
	if((SIUL2.DISR0.R & maskEIRQ) > 0){		//test EIF flag
		return 1;
	}
	else{
		return 0;
	}
}

void SIUL_ClearExtIntFlag(uint32_t maskEIRQ)
{
	SIUL2.DISR0.R = maskEIRQ;											//clear EIF flag
}




















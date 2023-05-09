/*
 * NCV7719.c
 *
 *  Created on: 2018年9月14日
 *      Author: helei
 */

#define __NCV7719_GLOBALS__

#include "derivative.h"
#include "BASE_Global.h"
#include "NCV7719.h"

_NCV7719_INOUTPUT_ NCV7719_data;

void NCV7719_Init(void)
{
    SIUL_DigitalOutput(NCV7719_CS, SIUL_GPIO);               // for NCV7719 select , cs
    SIUL_DigitalOutput(NCV7719_EN, SIUL_GPIO);               // for NCV7719 en , enable

    SIUL_SetPad(NCV7719_CS);	//CS 置高
    SIUL_SetPad(NCV7719_EN);	//默认使能芯片
}


uint32_t NCV7719_Refresh1_6(void)
{
	uint32_t i=0;
	for(i=0;i<NCV7719_Refresh_Times;i++)
	{
	NCV7719_CS_enable();
	NCV7719_tx(NCV7719_data.CH1_6.R);
	NCV7719_data.CH1_6_recive = NCV7719_rx();
//	NCV7719_tx(NCV7719_data.CH7_8.R);			//can not set with ch1-6,must be alone
//	NCV7719_data.CH7_8_recive = NCV7719_rx();
	NCV7719_CS_disable();
	}
	return 0;
}
uint32_t NCV7719_Refresh7_8(void)
{
	uint32_t i=0;
	for(i=0;i<NCV7719_Refresh_Times;i++)
	{
	NCV7719_CS_enable();
//	NCV7719_tx(NCV7719_data.CH1_6.R);
//	NCV7719_data.CH1_6_recive = NCV7719_rx();
	NCV7719_tx(NCV7719_data.CH7_8.R);			//can not set with ch1-6,must be alone
	NCV7719_data.CH7_8_recive = NCV7719_rx();
	NCV7719_CS_disable();
	}
	return 0;
}

void NCV7719_Set()
{

}

void NCV7719_tx(uint16_t data)
{
	uint32_t secure_counter;
	DSPI_1.PUSHR.PUSHR.R = 0x80040000 | data;
   	secure_counter = 0;
	while((DSPI_1.SR.B.TCF!=1) && (secure_counter < 50000)){
	secure_counter++;
	}; 			// Wait end of transfert if MASTER
	DSPI_1.SR.B.TCF=1;		// Clear Transfert Flag
}

uint32_t NCV7719_rx(void)
{
	uint32_t data2,secure_counter;
	secure_counter = 0;
	while((DSPI_1.SR.B.RFDF != 1) && (secure_counter < 50000)){
	    secure_counter++;
	};	//wait for RX data
	data2 = DSPI_1.POPR.R;					//get received data
	DSPI_1.SR.B.RFDF = 1;						//clear receive flag
	//DSPI_1.SR.B.TCF = 1;							//clear transfer complete flag
	return data2;
}




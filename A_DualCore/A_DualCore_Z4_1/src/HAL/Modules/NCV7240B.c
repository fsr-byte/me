/*
 * NCV7240B.c
 *
 *  Created on: 2018年9月5日
 *      Author: helei
 */

#define __NCV7240B_GLOBALS__

#include "derivative.h"
#include "BASE_Global.h"
#include "NCV7240B.h"

static _NCV7240B_SI_data_ NCV7240B_SI_data;
_NCV7240B_SO_data_ NCV7240B_SO_data;	//暂时对外部开放

void NCV7240B_tx(uint16_t data);
uint32_t NCV7240B_rx(void);

void NCV7240B_Init(void)
{
	//需要对应初始化DSPI_1 才能正常使用
    SIUL_DigitalOutput(NCV7240B_CS, SIUL_GPIO);               // for NCV7240B select , cs
    SIUL_DigitalOutput(NCV7240B_EN, SIUL_GPIO);               // for NCV7240B en , enable

    SIUL_SetPad(NCV7240B_CS);	//CS 置高
    SIUL_SetPad(NCV7240B_EN);	//默认进入Normal Mode

    //第一段诊断
//    NCV7240B_Set_SI(NCV7240B_CHANNELALL, NCV7240B_STANDBY);
//    NCV7240B_Refresh();
//    NCV7240B_Set_SI(NCV7240B_CHANNELALL, NCV7240B_OFF);	//获取OFF状态下的故障信息，检测开路相关
//    NCV7240B_Refresh();

}

void NCV7240B_Diagnosis(void)
{
	//处理相关故障信息
}

void NCV7240B_Set_SI(uint8_t channel,uint8_t data)
{
	switch(channel)
	{
	case NCV7240B_CHANNEL1:
		NCV7240B_SI_data.mode.channel1 = data;
		break;
	case NCV7240B_CHANNEL2:
		NCV7240B_SI_data.mode.channel2 = data;
		break;
	case NCV7240B_CHANNEL3:
		NCV7240B_SI_data.mode.channel3 = data;
		break;
	case NCV7240B_CHANNEL4:
		NCV7240B_SI_data.mode.channel4 = data;
		break;
	case NCV7240B_CHANNEL5:
		NCV7240B_SI_data.mode.channel5 = data;
		break;
	case NCV7240B_CHANNEL6:
		NCV7240B_SI_data.mode.channel6 = data;
		break;
	case NCV7240B_CHANNEL7:
		NCV7240B_SI_data.mode.channel7 = data;
		break;
	case NCV7240B_CHANNEL8:
		NCV7240B_SI_data.mode.channel8 = data;
		break;
	case NCV7240B_CHANNELALL:
		NCV7240B_SI_data.mode.channel1 = data;
		NCV7240B_SI_data.mode.channel2 = data;
		NCV7240B_SI_data.mode.channel3 = data;
		NCV7240B_SI_data.mode.channel4 = data;
		NCV7240B_SI_data.mode.channel5 = data;
		NCV7240B_SI_data.mode.channel6 = data;
		NCV7240B_SI_data.mode.channel7 = data;
		NCV7240B_SI_data.mode.channel8 = data;
		break;
	default:
		NCV7240B_SI_data.R = 0x0000;
		break;
	}
}

void NCV7240B_Refresh(void)
{
	uint16_t i = 0, temp = 0;
	for(i=0; i<NCV7240B_RefreshTimes; i++)			/*发送并读取数据多次*/
	{
		SIUL_ClearPad(NCV7240B_CS);	//CS select
//		DSPI_Send(NCV7240B_SPI, NCV7240B_CTAR, NCV7240B_SI_data.R);
//		temp = DSPI_Read(NCV7240B_SPI);
		NCV7240B_tx(NCV7240B_SI_data.R);
		temp = NCV7240B_rx();
		SIUL_SetPad(NCV7240B_CS);	//CS don't selected
	}
	NCV7240B_SO_data.R = temp;			/*刷新状态数据*/
}


void NCV7240B_tx(uint16_t data)
{
	uint32_t secure_counter;
	DSPI_1.PUSHR.PUSHR.R = 0x80040000 | data;
   	secure_counter = 0;
	while((DSPI_1.SR.B.TCF!=1) && (secure_counter < 50000)){
	secure_counter++;
	}; 			// Wait end of transfert if MASTER
	DSPI_1.SR.B.TCF=1;		// Clear Transfert Flag
}

uint32_t NCV7240B_rx(void)
{
	uint32_t data2,secure_counter;
	secure_counter = 0;
	while((DSPI_1.SR.B.RFDF != 1) && (secure_counter < 50000)){
	    secure_counter++;
	};	//wait for RX data
	data2 = DSPI_1.POPR.R;					//get received data
	DSPI_1.SR.B.RFDF = 1;						//clear receive flag
	DSPI_1.SR.B.TCF = 1;							//clear transfer complete flag
	return data2;
}






/*
 * NCV7513B.c
 *
 *  Created on: 2018年9月5日
 *      Author: helei
 */

#define __NCV7513B_GLOBALS__

#include "derivative.h"
#include "BASE_Global.h"
#include "NCV7513B.h"

_NCV7513B_SI_data_ NCV7513B_SI_data;
_NCV7513B_SO_data_ NCV7513B_SO_data;

void NCV7513B_Init(void)
{
	//需要对应初始化DSPI_1 才能正常使用
    SIUL_DigitalOutput(NCV7513B_CS, SIUL_GPIO);               // for NCV7513B select , cs
    SIUL_DigitalOutput(NCV7513B_EN2, SIUL_GPIO);              // for NCV7513B en2 , enable2
    SIUL_DigitalInputSimple(NCV7513B_FLTB,SIUL_GPIO);		  // for NCV7513B FLTB
    SIUL_DigitalInputSimple(NCV7513B_STAB,SIUL_GPIO);		  // for NCV7513B STAB

    SIUL_SetPad(NCV7513B_CS);	//默认CS 置高
    SIUL_SetPad(NCV7513B_EN2);	//默认开启诊断
    //允许FLTB通知错误状态,由MASK选定
    NCV7513B_Set_SI(NCV7513B_FLAG_MASK, NCV7513B_DA);			//mask 全为1， clear状态，允许FLTB通知错误状态
    NCV7513B_Refresh();											//获取0状态下的故障信息，检测开路及对地短路相关

    //第一段诊断
    NCV7513B_Set_SI(NCV7513B_GATE_SELECT, NCV7513B_DN);			//默认gate 选择为0
    NCV7513B_Refresh();											//获取0状态下的故障信息，检测开路及对地短路相关

}

void NCV7513B_Diagnosis(void)
{
	//处理相关故障信息

	if(SIUL_GetPadState(NCV7513B_FLTB) == 0)	//处于低电平时，有错误出现
	{
	    NCV7513B_Set_SI(NCV7513B_NULL_USE, NCV7513B_DN);			//读取故障代码
	    NCV7513B_Refresh();
	}//无错误时，不做操作


}

void NCV7513B_Set_SI(uint8_t address, uint8_t data)
{
	NCV7513B_SI_data.command.address = address;
	NCV7513B_SI_data.command.data = data;
}

void NCV7513B_Set_Data(uint8_t channel, uint8_t data)
{
	if(channel < 6)
	{
		switch(channel)
		{
		case 0 :
			if(data == 0)
				NCV7513B_SI_data.command.data &= (~0x01);
			else
				NCV7513B_SI_data.command.data |= 0x01;
			break;
		case 1 :
			if(data == 0)
				NCV7513B_SI_data.command.data &= (~0x02);
			else
				NCV7513B_SI_data.command.data |= 0x02;
			break;
		case 2 :
			if(data == 0)
				NCV7513B_SI_data.command.data &= (~0x04);
			else
				NCV7513B_SI_data.command.data |= 0x04;
			break;
		case 3 :
			if(data == 0)
				NCV7513B_SI_data.command.data &= (~0x08);
			else
				NCV7513B_SI_data.command.data |= 0x08;
			break;
		case 4 :
			if(data == 0)
				NCV7513B_SI_data.command.data &= (~0x10);
			else
				NCV7513B_SI_data.command.data |= 0x10;
			break;
		case 5 :
			if(data == 0)
				NCV7513B_SI_data.command.data &= (~0x20);
			else
				NCV7513B_SI_data.command.data |= 0x20;
			break;
		}
	}
}

void NCV7513B_Set_Address(uint8_t address)
{
	NCV7513B_SI_data.command.address = address;
}

void NCV7513B_Refresh(void)
{
	uint16_t i = 0, temp = 0;

	for(i=0; i<NCV7513B_RefreshTimes; i++)			/*发送并读取数据3次*/
	{
		SIUL_ClearPad(NCV7513B_CS);	//CS select
		DSPI_Send(NCV7513B_SPI, NCV7513B_CTAR, NCV7513B_SI_data.R);
		temp = DSPI_Read(NCV7513B_SPI);
		SIUL_SetPad(NCV7513B_CS);	//CS don't selected
	}

	NCV7513B_SO_data.R = temp;			/*刷新状态数据*/
}








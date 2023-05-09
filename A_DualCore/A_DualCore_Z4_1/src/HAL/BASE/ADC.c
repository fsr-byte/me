/*
 * ADC.c
 *
 *  Created on: 2018年9月5日
 *      Author: helei
 */

#define __ADC_GLOBALS__

#include "derivative.h"
#include "ADC.h"
#include "GPIO.h"

uint16_t ADC_Buff[ADCNUM] = {0};

void SARADC_Init(void)
{
	SIUL_AnalogInput(GPIO_PORTZ+15,0);//SAR0_15	--AIN1
	SIUL_AnalogInput(GPIO_PORTZ+14,0);//SAR0_14	--AIN2
	SIUL_AnalogInput(GPIO_PORTZ+13,0);//SAR0_13	--AIN3
	SIUL_AnalogInput(GPIO_PORTZ+12,0);//SAR0_12	--AIN4
	SIUL_AnalogInput(GPIO_PORTZ+11,0);//SAR0_11	--AIN5
	SIUL_AnalogInput(GPIO_PORTZ+10,0);//SAR0_10	--AIN6
	SIUL_AnalogInput(GPIO_PORTZ+9,0);//SAR0_9	--AIN7
	SIUL_AnalogInput(GPIO_PORTZ+8,0);//SAR0_8	--AIN8
	SIUL_AnalogInput(GPIO_PORTZ+7,0);//SAR0_7	--AIN9
	SIUL_AnalogInput(GPIO_PORTZ+6,0);//SAR0_6	--AIN10
	SIUL_AnalogInput(GPIO_PORTZ+5,0);//SAR0_5	--AIN11
	SIUL_AnalogInput(GPIO_PORTZ+4,0);//SAR0_4	--AIN12
	SIUL_AnalogInput(GPIO_PORTZ+3,0);//SAR0_3	--AIN13
	SIUL_AnalogInput(GPIO_PORTZ+2,0);//SAR0_2	--AIN14
	SIUL_AnalogInput(GPIO_PORTZ+1,0);//SAR0_1	--AIN15
	SIUL_AnalogInput(GPIO_PORTZ+0,0);//SAR0_0	--AD_SEN1

	SIUL_AnalogInput(GPIO_PORTY+15,0);//SAR0_31	--AD_SEN3
	SIUL_AnalogInput(GPIO_PORTY+13,0);//SAR0_29	--AD_SEN2
	SIUL_AnalogInput(GPIO_PORTY+4,0);//SAR0_20	--AIN_19
	SIUL_AnalogInput(GPIO_PORTY+0,0);//SAR0_16	--AD_KL30

	SIUL_AnalogInput(GPIO_PORTX+15,0);//SAR1_27	--AD_KL30 双通道共同检测
	SIUL_AnalogInput(GPIO_PORTX+14,0);//SAR1_26	--AIN_18
	SIUL_AnalogInput(GPIO_PORTX+12,0);//SAR1_24	--AIN_17
	SIUL_AnalogInput(GPIO_PORTX+10,0);//SAR1_22	--AIN_16
	SIUL_AnalogInput(GPIO_PORTX+9,0);//SAR1_21	--AD_MUX_OUT
	SIUL_AnalogInput(GPIO_PORTX+5,0);//SAR1_17	--BTS5200_IS
	SIUL_AnalogInput(GPIO_PORTX+3,0);//SAR1_15	--BTS5180_IS

	SIUL_AnalogInput(GPIO_PORTW+2,0);//SAR1_30	--AIN_20

	//精度12bits，参考电压5V
	ADC_0.MCR.B.PWDN = 1;     //close ADC_0 for configure
	ADC_0.MCR.B.OWREN = 1;	//0:不覆盖数据     1:覆盖数据
	ADC_0.MCR.B.MODE = 0;     //0:One_Shot 1:scan mode
	ADC_0.MCR.B.ADCLKSEL = 1; //0:half 1:all frequency is half of bus clock  when SAR ADC input CLK = 40M ,it's 20MHz
//	ADC_0.NCMR0.B.CH7 = 1;    //normal sampling for channel 7
	ADC_0.NCMR0.R	= 0xA011FFFF;  //set channel
	ADC_0.MCR.B.PWDN = 0;     //enable ADC_0
	ADC_0.MCR.B.NSTART = 1;   //start of normal conversion

	ADC_1.MCR.B.PWDN = 1;     //close ADC_1 for configure
	ADC_1.MCR.B.OWREN = 1;	//0:不覆盖数据     1:覆盖数据
	ADC_1.MCR.B.MODE = 0;     //0:One_Shot 1:scan mode
	ADC_1.MCR.B.ADCLKSEL = 1; //0:half 1:all frequency is half of bus clock  when SAR ADC input CLK = 40M ,it's 20MHz
//	ADC_1.NCMR0.B.CH7 = 1;    //normal sampling for channel 7
	ADC_1.NCMR0.R	= 0x4D628000;  //set channel
	ADC_1.MCR.B.PWDN = 0;     //enable ADC_1
	ADC_1.MCR.B.NSTART = 1;   //start of normal conversion
}

void SARADC_GetAll(void)
{
	ADC_0.ISR.R = 0xF;		//清除所有标志位
	ADC_0.MCR.B.NSTART = 1;   //start of normal conversion
	ADC_1.ISR.R = 0xF;		//清除所有标志位
	ADC_1.MCR.B.NSTART = 1;   //start of normal conversion

	while(ADC_0.ISR.B.ECH == 0);	//等待一个chain的转换完成

	ADC_Buff[0]	= (uint16_t) ADC_0.CDR[0].B.CDATA;//AD_SEN1
	ADC_Buff[1]	= (uint16_t) ADC_0.CDR[1].B.CDATA;//AIN15
	ADC_Buff[2]	= (uint16_t) ADC_0.CDR[2].B.CDATA;//AIN14
	ADC_Buff[3]	= (uint16_t) ADC_0.CDR[3].B.CDATA;//AIN13
	ADC_Buff[4]	= (uint16_t) ADC_0.CDR[4].B.CDATA;//AIN12
	ADC_Buff[5]	= (uint16_t) ADC_0.CDR[5].B.CDATA;//AIN11
	ADC_Buff[6]	= (uint16_t) ADC_0.CDR[6].B.CDATA;//AIN10
	ADC_Buff[7]	= (uint16_t) ADC_0.CDR[7].B.CDATA;//AIN9
	ADC_Buff[8]	= (uint16_t) ADC_0.CDR[8].B.CDATA;//AIN8
	ADC_Buff[9]	= (uint16_t) ADC_0.CDR[9].B.CDATA;//AIN7
	ADC_Buff[10]= (uint16_t) ADC_0.CDR[10].B.CDATA;//AIN6
	ADC_Buff[11]= (uint16_t) ADC_0.CDR[11].B.CDATA;//AIN5
	ADC_Buff[12]= (uint16_t) ADC_0.CDR[12].B.CDATA;//AIN4
	ADC_Buff[13]= (uint16_t) ADC_0.CDR[13].B.CDATA;//AIN3
	ADC_Buff[14]= (uint16_t) ADC_0.CDR[14].B.CDATA;//AIN2
	ADC_Buff[15]= (uint16_t) ADC_0.CDR[15].B.CDATA;//AIN1
	ADC_Buff[16]= (uint16_t) ADC_0.CDR[16].B.CDATA;//AD_KL30
	ADC_Buff[17]= (uint16_t) ADC_0.CDR[20].B.CDATA;//AIN_19
	ADC_Buff[18]= (uint16_t) ADC_0.CDR[29].B.CDATA;//AD_SEN2
	ADC_Buff[19]= (uint16_t) ADC_0.CDR[31].B.CDATA;//AD_SEN3

	while(ADC_1.ISR.B.ECH == 0);	//等待一个chain的转换完成

	ADC_Buff[20]	= (uint16_t) ADC_1.CDR[15].B.CDATA;//BTS5180_IS
	ADC_Buff[21]	= (uint16_t) ADC_1.CDR[17].B.CDATA;//BTS5200_IS
	ADC_Buff[22]	= (uint16_t) ADC_1.CDR[21].B.CDATA;//AD_MUX_OUT
	ADC_Buff[23]	= (uint16_t) ADC_1.CDR[22].B.CDATA;//AIN_16
	ADC_Buff[24]	= (uint16_t) ADC_1.CDR[24].B.CDATA;//AIN_17
	ADC_Buff[25]	= (uint16_t) ADC_1.CDR[26].B.CDATA;//AIN_18
	ADC_Buff[26]	= (uint16_t) ADC_1.CDR[27].B.CDATA;//AD_KL30
	ADC_Buff[27]	= (uint16_t) ADC_1.CDR[30].B.CDATA;//AIN20

	//(float)Voltage = 5000*ADC_Buff[i]/0xFFF;	//转换为真实电压值
}

void SARADC_Get1(void)
{
	ADC_1.ISR.R = 0xF;		//清除所有标志位
	ADC_1.MCR.B.NSTART = 1;   //start of normal conversion
	while(ADC_1.ISR.B.ECH == 0);	//等待一个chain的转换完成
	ADC_Buff[20]	= (uint16_t) ADC_1.CDR[15].B.CDATA;
	ADC_Buff[21]	= (uint16_t) ADC_1.CDR[17].B.CDATA;
	ADC_Buff[22]	= (uint16_t) ADC_1.CDR[21].B.CDATA;
	ADC_Buff[23]	= (uint16_t) ADC_1.CDR[22].B.CDATA;
	ADC_Buff[24]	= (uint16_t) ADC_1.CDR[24].B.CDATA;
	ADC_Buff[25]	= (uint16_t) ADC_1.CDR[26].B.CDATA;
	ADC_Buff[26]	= (uint16_t) ADC_1.CDR[27].B.CDATA;
	ADC_Buff[27]	= (uint16_t) ADC_1.CDR[30].B.CDATA;
}




/*
 * eMIOS.c
 *
 *  Created on: 2018年9月10日
 *      Author: helei
 */

#define __eMIOS_GLOBALS__

#include "derivative.h"
#include "eMIOS.h"
#include "GPIO.h"

_eMIOS_PWMIN_data_ eMIOS_PWMin_data[EMIOSNUM];

volatile struct eMIOS_tag * eMIOS[2] = {&eMIOS_0, &eMIOS_1};
volatile  uint32_t B_Reg_test=0;    
uint32_t gul_EMIOSMinCnt=50;  
uint32_t gul_EMIOS_InitCnt=3;  

void GetEMIOS1_13()
{
    uint32_t ulEMIOS_Channel_Num=eMIOS_1_13;
    uint32_t ultemp=0;
    volatile  uint32_t A_Reg=0;
    volatile  uint32_t B_Reg=0;
    static uint32_t A_Reg_Last = 0;
    
    A_Reg= eMIOS_1.A13.B.A; 
    B_Reg= eMIOS_1.B13.B.B;   
    ultemp=(A_Reg - B_Reg)&0xFFFFFF;    
    
    if(A_Reg !=A_Reg_Last) 
    {
        A_Reg_Last = A_Reg; 
        eMIOS_PWMin_data[ulEMIOS_Channel_Num].stoptick=0;
        if(eMIOS_PWMin_data[ulEMIOS_Channel_Num].InitCnt>0)
        {
            eMIOS_PWMin_data[ulEMIOS_Channel_Num].InitCnt=eMIOS_PWMin_data[ulEMIOS_Channel_Num].InitCnt-1; /*丢弃初始几次的取值*/
        }
        else
        {
            if(ultemp<gul_EMIOSMinCnt)
            {
                B_Reg_test = eMIOS_1.B13.B.B;
                return;
            } 
            else
            {
                eMIOS_PWMin_data[ulEMIOS_Channel_Num].InitCnt=gul_EMIOS_InitCnt;
                /*取周期或者占空比，并切换模式*/
                if(eMIOS_1.C13.B.MODE==4)
                {
                    eMIOS_PWMin_data[ulEMIOS_Channel_Num].pulsewidth = ultemp;
                    eMIOS_1.C13.B.MODE=5;
                }
                else
                {
                    eMIOS_PWMin_data[ulEMIOS_Channel_Num].period = ultemp;
                    eMIOS_1.C13.B.MODE=4;
                }
            }
        }
    }
    else
    {
        eMIOS_PWMin_data[ulEMIOS_Channel_Num].stoptick++;
        if(eMIOS_PWMin_data[ulEMIOS_Channel_Num].stoptick>10)
        { 
             eMIOS_1.S13.R= 0xFFFFFFFF;
        }
    }
}
void GetEMIOS1_16()
{
    uint32_t ulEMIOS_Channel_Num=eMIOS_1_16;
    uint32_t ultemp=0;
    volatile  uint32_t A_Reg=0;
    volatile  uint32_t B_Reg=0;
    static uint32_t A_Reg_Last = 0;
    
    A_Reg= eMIOS_1.A16.B.A; 
    B_Reg= eMIOS_1.B16.B.B;   
    ultemp=(A_Reg - B_Reg)&0xFFFFFF;    
    
    if(A_Reg !=A_Reg_Last) 
    {
        A_Reg_Last = A_Reg; 
        eMIOS_PWMin_data[ulEMIOS_Channel_Num].stoptick=0;
        if(eMIOS_PWMin_data[ulEMIOS_Channel_Num].InitCnt>0)
        {
            eMIOS_PWMin_data[ulEMIOS_Channel_Num].InitCnt=eMIOS_PWMin_data[ulEMIOS_Channel_Num].InitCnt-1; /*丢弃初始几次的取值*/
        }
        else
        {
            if(ultemp<gul_EMIOSMinCnt)
            {
                B_Reg_test = eMIOS_1.B16.B.B;
                return;
            } 
            else
            {
                eMIOS_PWMin_data[ulEMIOS_Channel_Num].InitCnt=gul_EMIOS_InitCnt;
                /*取周期或者占空比，并切换模式*/
                if(eMIOS_1.C16.B.MODE==4)
                {
                    eMIOS_PWMin_data[ulEMIOS_Channel_Num].pulsewidth = ultemp;
                    eMIOS_1.C16.B.MODE=5;
                }
                else
                {
                    eMIOS_PWMin_data[ulEMIOS_Channel_Num].period = ultemp;
                    eMIOS_1.C16.B.MODE=4;
                }
            }
        }
    }
    else
    {
        eMIOS_PWMin_data[ulEMIOS_Channel_Num].stoptick++;
        if(eMIOS_PWMin_data[ulEMIOS_Channel_Num].stoptick>10)
        { 
             eMIOS_1.S16.R= 0xFFFFFFFF;
        }
    }
}    

void GetEMIOS1_17()
{
    uint32_t ulEMIOS_Channel_Num=eMIOS_1_17;
    uint32_t ultemp=0;
    volatile  uint32_t A_Reg=0;
    volatile  uint32_t B_Reg=0;
    static uint32_t A_Reg_Last = 0;
    
    A_Reg= eMIOS_1.A17.B.A; 
    B_Reg= eMIOS_1.B17.B.B;   
    ultemp=(A_Reg - B_Reg)&0xFFFFFF;    
    
    if(A_Reg !=A_Reg_Last) 
    {
        A_Reg_Last = A_Reg; 
        eMIOS_PWMin_data[ulEMIOS_Channel_Num].stoptick=0;
        if(eMIOS_PWMin_data[ulEMIOS_Channel_Num].InitCnt>0)
        {
            eMIOS_PWMin_data[ulEMIOS_Channel_Num].InitCnt=eMIOS_PWMin_data[ulEMIOS_Channel_Num].InitCnt-1; /*丢弃初始几次的取值*/
        }
        else
        {
            if(ultemp<gul_EMIOSMinCnt)
            {
                B_Reg_test = eMIOS_1.B17.B.B;
                return;
            } 
            else
            {
                eMIOS_PWMin_data[ulEMIOS_Channel_Num].InitCnt=gul_EMIOS_InitCnt;
                /*取周期或者占空比，并切换模式*/
                if(eMIOS_1.C17.B.MODE==4)
                {
                    eMIOS_PWMin_data[ulEMIOS_Channel_Num].pulsewidth = ultemp;
                    eMIOS_1.C17.B.MODE=5;
                }
                else
                {
                    eMIOS_PWMin_data[ulEMIOS_Channel_Num].period = ultemp;
                    eMIOS_1.C17.B.MODE=4;
                }
            }
        }
    }
    else
    {
        eMIOS_PWMin_data[ulEMIOS_Channel_Num].stoptick++;
        if(eMIOS_PWMin_data[ulEMIOS_Channel_Num].stoptick>10)
        { 
             eMIOS_1.S17.R= 0xFFFFFFFF;
        }
    }
}
void GetEMIOS1_20()
{
    uint32_t ulEMIOS_Channel_Num=eMIOS_1_20;
    uint32_t ultemp=0;
    volatile  uint32_t A_Reg=0;
    volatile  uint32_t B_Reg=0;
    static uint32_t A_Reg_Last = 0;
    
    A_Reg= eMIOS_1.A20.B.A; 
    B_Reg= eMIOS_1.B20.B.B;   
    ultemp=(A_Reg - B_Reg)&0xFFFFFF;    
    
    if(A_Reg !=A_Reg_Last) 
    {
        A_Reg_Last = A_Reg; 
        eMIOS_PWMin_data[ulEMIOS_Channel_Num].stoptick=0;
        if(eMIOS_PWMin_data[ulEMIOS_Channel_Num].InitCnt>0)
        {
            eMIOS_PWMin_data[ulEMIOS_Channel_Num].InitCnt=eMIOS_PWMin_data[ulEMIOS_Channel_Num].InitCnt-1; /*丢弃初始几次的取值*/
        }
        else
        {
            if(ultemp<gul_EMIOSMinCnt)
            {
                B_Reg_test = eMIOS_1.B20.B.B;
                return;
            } 
            else
            {
                eMIOS_PWMin_data[ulEMIOS_Channel_Num].InitCnt=gul_EMIOS_InitCnt;
                /*取周期或者占空比，并切换模式*/
                if(eMIOS_1.C20.B.MODE==4)
                {
                    eMIOS_PWMin_data[ulEMIOS_Channel_Num].pulsewidth = ultemp;
                    eMIOS_1.C20.B.MODE=5;
                }
                else
                {
                    eMIOS_PWMin_data[ulEMIOS_Channel_Num].period = ultemp;
                    eMIOS_1.C20.B.MODE=4;
                }
            }
        }
    }
    else
    {
        eMIOS_PWMin_data[ulEMIOS_Channel_Num].stoptick++;
        if(eMIOS_PWMin_data[ulEMIOS_Channel_Num].stoptick>10)
        { 
             eMIOS_1.S20.R= 0xFFFFFFFF;
        }
    }
}
void GetEMIOS0_9()
{
    uint32_t ulEMIOS_Channel_Num=eMIOS_0_09;
    uint32_t ultemp=0;
    volatile  uint32_t A_Reg=0;
    volatile  uint32_t B_Reg=0;
    static uint32_t A_Reg_Last = 0;
    
    A_Reg= eMIOS_0.A9.B.A; 
    B_Reg= eMIOS_0.B9.B.B;   
    ultemp=(A_Reg - B_Reg)&0xFFFFFF;    
    
    if(A_Reg !=A_Reg_Last) 
    {
        A_Reg_Last = A_Reg; 
        eMIOS_PWMin_data[ulEMIOS_Channel_Num].stoptick=0;
        if(eMIOS_PWMin_data[ulEMIOS_Channel_Num].InitCnt>0)
        {
            eMIOS_PWMin_data[ulEMIOS_Channel_Num].InitCnt=eMIOS_PWMin_data[ulEMIOS_Channel_Num].InitCnt-1; /*丢弃初始几次的取值*/
        }
        else
        {
            if(ultemp<gul_EMIOSMinCnt)
            {
                B_Reg_test = eMIOS_0.B9.B.B;
                return;
            } 
            else
            {
                eMIOS_PWMin_data[ulEMIOS_Channel_Num].InitCnt=gul_EMIOS_InitCnt;
                /*取周期或者占空比，并切换模式*/
                if(eMIOS_0.C9.B.MODE==4)
                {
                    eMIOS_PWMin_data[ulEMIOS_Channel_Num].pulsewidth = ultemp;
                    eMIOS_0.C9.B.MODE=5;
                }
                else
                {
                    eMIOS_PWMin_data[ulEMIOS_Channel_Num].period = ultemp;
                    eMIOS_0.C9.B.MODE=4;
                }
            }
        }
    }
    else
    {
        eMIOS_PWMin_data[ulEMIOS_Channel_Num].stoptick++;
        if(eMIOS_PWMin_data[ulEMIOS_Channel_Num].stoptick>10)
        { 
             eMIOS_0.S9.R= 0xFFFFFFFF;
        }
    }
}
void GetEMIOS0_10()
{
    uint32_t ulEMIOS_Channel_Num=eMIOS_0_10;
    uint32_t ultemp=0;
    volatile  uint32_t A_Reg=0;
    volatile  uint32_t B_Reg=0;
    static uint32_t A_Reg_Last = 0;
    
    A_Reg= eMIOS_0.A10.B.A; 
    B_Reg= eMIOS_0.B10.B.B;   
    ultemp=(A_Reg - B_Reg)&0xFFFFFF;    
    
    if(A_Reg !=A_Reg_Last) 
    {
        A_Reg_Last = A_Reg; 
        eMIOS_PWMin_data[ulEMIOS_Channel_Num].stoptick=0;
        if(eMIOS_PWMin_data[ulEMIOS_Channel_Num].InitCnt>0)
        {
            eMIOS_PWMin_data[ulEMIOS_Channel_Num].InitCnt=eMIOS_PWMin_data[ulEMIOS_Channel_Num].InitCnt-1; /*丢弃初始几次的取值*/
        }
        else
        {
            if(ultemp<gul_EMIOSMinCnt)
            {
                B_Reg_test = eMIOS_0.B10.B.B;
                return;
            } 
            else
            {
                eMIOS_PWMin_data[ulEMIOS_Channel_Num].InitCnt=gul_EMIOS_InitCnt;
                /*取周期或者占空比，并切换模式*/
                if(eMIOS_0.C10.B.MODE==4)
                {
                    eMIOS_PWMin_data[ulEMIOS_Channel_Num].pulsewidth = ultemp;
                    eMIOS_0.C10.B.MODE=5;
                }
                else
                {
                    eMIOS_PWMin_data[ulEMIOS_Channel_Num].period = ultemp;
                    eMIOS_0.C10.B.MODE=4;
                }
            }
        }
    }
    else
    {
        eMIOS_PWMin_data[ulEMIOS_Channel_Num].stoptick++;
        if(eMIOS_PWMin_data[ulEMIOS_Channel_Num].stoptick>10)
        { 
             eMIOS_0.S10.R= 0xFFFFFFFF;
        }
    }
}
void GetEMIOS0_12()
{
    uint32_t ulEMIOS_Channel_Num=eMIOS_0_12;
    uint32_t ultemp=0;
    volatile  uint32_t A_Reg=0;
    volatile  uint32_t B_Reg=0;
    static uint32_t A_Reg_Last = 0;
    
    A_Reg= eMIOS_0.A12.B.A; 
    B_Reg= eMIOS_0.B12.B.B;   
    ultemp=(A_Reg - B_Reg)&0xFFFFFF;    
    
    if(A_Reg !=A_Reg_Last) 
    {
        A_Reg_Last = A_Reg; 
        eMIOS_PWMin_data[ulEMIOS_Channel_Num].stoptick=0;
        if(eMIOS_PWMin_data[ulEMIOS_Channel_Num].InitCnt>0)
        {
            eMIOS_PWMin_data[ulEMIOS_Channel_Num].InitCnt=eMIOS_PWMin_data[ulEMIOS_Channel_Num].InitCnt-1; /*丢弃初始几次的取值*/
        }
        else
        {
            if(ultemp<gul_EMIOSMinCnt)
            {
                B_Reg_test = eMIOS_0.B12.B.B;
                return;
            } 
            else
            {
                eMIOS_PWMin_data[ulEMIOS_Channel_Num].InitCnt=gul_EMIOS_InitCnt;
                /*取周期或者占空比，并切换模式*/
                if(eMIOS_0.C12.B.MODE==4)
                {
                    eMIOS_PWMin_data[ulEMIOS_Channel_Num].pulsewidth = ultemp;
                    eMIOS_0.C12.B.MODE=5;
                }
                else
                {
                    eMIOS_PWMin_data[ulEMIOS_Channel_Num].period = ultemp;
                    eMIOS_0.C12.B.MODE=4;
                }
            }
        }
    }
    else
    {
        eMIOS_PWMin_data[ulEMIOS_Channel_Num].stoptick++;
        if(eMIOS_PWMin_data[ulEMIOS_Channel_Num].stoptick>10)
        { 
             eMIOS_0.S12.R= 0xFFFFFFFF;
        }
    }
}
void GetEMIOS0_18()
{
    uint32_t ulEMIOS_Channel_Num=eMIOS_0_18;
    uint32_t ultemp=0;
    volatile  uint32_t A_Reg=0;
    volatile  uint32_t B_Reg=0;
    static uint32_t A_Reg_Last = 0;
    
    A_Reg= eMIOS_0.A18.B.A; 
    B_Reg= eMIOS_0.B18.B.B;   
    ultemp=(A_Reg - B_Reg)&0xFFFFFF;    
    
    if(A_Reg !=A_Reg_Last) 
    {
        A_Reg_Last = A_Reg; 
        eMIOS_PWMin_data[ulEMIOS_Channel_Num].stoptick=0;
        if(eMIOS_PWMin_data[ulEMIOS_Channel_Num].InitCnt>0)
        {
            eMIOS_PWMin_data[ulEMIOS_Channel_Num].InitCnt=eMIOS_PWMin_data[ulEMIOS_Channel_Num].InitCnt-1; /*丢弃初始几次的取值*/
        }
        else
        {
            if(ultemp<gul_EMIOSMinCnt)
            {
                B_Reg_test = eMIOS_0.B18.B.B;
                return;
            } 
            else
            {
                eMIOS_PWMin_data[ulEMIOS_Channel_Num].InitCnt=gul_EMIOS_InitCnt;
                /*取周期或者占空比，并切换模式*/
                if(eMIOS_0.C18.B.MODE==4)
                {
                    eMIOS_PWMin_data[ulEMIOS_Channel_Num].pulsewidth = ultemp;
                    eMIOS_0.C18.B.MODE=5;
                }
                else
                {
                    eMIOS_PWMin_data[ulEMIOS_Channel_Num].period = ultemp;
                    eMIOS_0.C18.B.MODE=4;
                }
            }
        }
    }
    else
    {
        eMIOS_PWMin_data[ulEMIOS_Channel_Num].stoptick++;
        if(eMIOS_PWMin_data[ulEMIOS_Channel_Num].stoptick>10)
        { 
             eMIOS_0.S18.R= 0xFFFFFFFF;
        }
    }
}
void eMIOS_Init_All(void)
{
	eMIOS_Close(EMIOS0);
	eMIOS_Close(EMIOS1);

	eMIOS_Init(EMIOS0);
	eMIOS_Init(EMIOS1);

	eMIOS_IO_InitAll();
	eMIOS_INT_InitAll();

	eMIOS_Start(EMIOS0);
	eMIOS_Start(EMIOS1);
}

void AgingTest_eMIOS_IO_InitAll(void)
{
	SIUL_DigitalInput(GPIO_PORTY+2,592,0,0x0B);	//1_EMIOS0-10  DIN_T27-- add for aging test

	SIUL_DigitalInput(GPIO_PORTF+1,625,0,0x09);	//1_EMIOS1-17  DIN_T24-- add for aging test

    	SIUL_DigitalInput(GPIO_PORTH+12,628,0,0x0A);	//1_EMIOS1-20  DIN_T2-- add for aging test
    	
	SIUL_DigitalInput(GPIO_PORTK+11,624,0,0x0B);	//1_EMIOS1-16    DIN10  -- add for aging test


    	SIUL_DigitalInput(GPIO_PORTK+0,621,0,0x0A);		//1_13 碰撞信号PWM检测 DINT13
	SIUL_DigitalInput(GPIO_PORTX+1,600,0,0x0A);	//0_18 水泵PWM检测DINT31
	SIUL_DigitalInput(GPIO_PORTY+6,594,0,0x0B);		//0_12 真空泵PWM检测 DINT26
	SIUL_DigitalInput(GPIO_PORTY+1,591,0,0x0B);		//0_9  高压互锁PWM检测DINT28

}

void AgingTest_eMIOS_Init_All()
{
	eMIOS_Close(EMIOS0);
	eMIOS_Close(EMIOS1);

	eMIOS_Init(EMIOS0);
	eMIOS_Init(EMIOS1);

	AgingTest_eMIOS_IO_InitAll();
	eMIOS_INT_InitAll();

	eMIOS_Start(EMIOS0);
	eMIOS_Start(EMIOS1);
}
void eMIOS_IO_InitAll(void)
{
	SIUL_DigitalInput(GPIO_PORTY+2,592,0,0);	//1_EMIOS0-10  DIN_T27-- clear aging test bit

	SIUL_DigitalInput(GPIO_PORTF+1,625,0,0);	//1_EMIOS1-17  DIN_T24--  clear aging test bit
//	SIUL_DigitalInput(GPIO_PORTH+11,627,0,0x0A);	//1_19
	SIUL_DigitalInput(GPIO_PORTH+12,628,0,0);	//1_EMIOS1-20  DIN_T2--  clear aging test bit
//	SIUL_DigitalInput(GPIO_PORTH+14,630,0,0x0A);	//1_22
//	SIUL_DigitalInput(GPIO_PORTI+3,593,0,0x0A);		//0_11
//	SIUL_DigitalInput(GPIO_PORTJ+11,616,0,0x0A);	//1_8
//	SIUL_DigitalInput(GPIO_PORTJ+12,617,0,0x0A);	//1_9
//	SIUL_DigitalInput(GPIO_PORTJ+13,618,0,0x0A);	//1_10
//	SIUL_DigitalInput(GPIO_PORTJ+15,620,0,0x0A);	//1_12
//	SIUL_DigitalInput(GPIO_PORTJ+3,596,0,0x0A);		//0_14
	SIUL_DigitalInput(GPIO_PORTK+0,621,0,0x0A);		//1_13 碰撞信号PWM检测 DINT13
	SIUL_DigitalInput(GPIO_PORTK+11,624,0,0);	//1  _EMIOS1-16    DIN10  --  clear aging test bit
//	SIUL_DigitalInput(GPIO_PORTK+7,602,0,0x0A);		//0_20
//	SIUL_DigitalInput(GPIO_PORTW+3,604,0,0x0A);		//0_22
	SIUL_DigitalInput(GPIO_PORTX+1,600,0,0x0A);	//0_18 水泵PWM检测DINT31
//	SIUL_DigitalInput(GPIO_PORTY+10,597,0,0x0B);	//0_15
//	SIUL_DigitalInput(GPIO_PORTY+7,595,0,0x0B);		//0_13
//	SIUL_DigitalInput(GPIO_PORTZ+0,598,0,0x0B);		//0_16
//	SIUL_DigitalInput(GPIO_PORTZ+1,599,0,0x0B);		//0_17
//	SIUL_DigitalInput(GPIO_PORTZ+11,619,0,0x0B);	//1_11
//	SIUL_DigitalInput(GPIO_PORTZ+14,622,0,0x0B);	//1_14
//	SIUL_DigitalInput(GPIO_PORTZ+15,623,0,0x0B);	//1_15
//	SIUL_DigitalInput(GPIO_PORTZ+3,601,0,0x0B);		//0_19
//	SIUL_DigitalInput(GPIO_PORTZ+5,603,0,0x0B);		//0_21
	SIUL_DigitalInput(GPIO_PORTY+6,594,0,0x0B);		//0_12 真空泵PWM检测 DINT26
	SIUL_DigitalInput(GPIO_PORTY+1,591,0,0x0B);		//0_9  高压互锁PWM检测DINT28
}

void eMIOS_INT_InitAll(void)
{
	//eMIOS  for PWM in
//	INTC_0.PSR[706].R = 0x4000 | 0x0A;	//将中断送给core1 && 设置该中断优先级为10
	INTC_0.PSR[707].R = 0x4000 | 0x0A;	//0_09
	INTC_0.PSR[708].R = 0x4000 | 0x0A;//0_10 EMIOS0-10  DIN_T27-- add for aging test
//	INTC_0.PSR[709].R = 0x4000 | 0x30;	//11
	INTC_0.PSR[710].R = 0x4000 | 0x0A;	//0_12
//	INTC_0.PSR[711].R = 0x4000 | 0x0A;
//	INTC_0.PSR[712].R = 0x4000 | 0x30;	//14
//	INTC_0.PSR[713].R = 0x4000 | 0x0A;
//	INTC_0.PSR[714].R = 0x4000 | 0x0A;
//	INTC_0.PSR[715].R = 0x4000 | 0x0A;
	INTC_0.PSR[716].R = 0x4000 | 0x30;	//18
//	INTC_0.PSR[717].R = 0x4000 | 0x0A;
//	INTC_0.PSR[718].R = 0x4000 | 0x0A;
//	INTC_0.PSR[719].R = 0x4000 | 0x0A;
//	INTC_0.PSR[720].R = 0x4000 | 0x30;	//0_22
	//INTC_0.PSR[721].R = 0x4000 | 0x14;	//将中断送给core1 && 设置该中断优先级为20 :: cycle count for PWM in  :: no pins

//	INTC_0.PSR[722].R = 0x4000 | 0x30;	//8
//	INTC_0.PSR[723].R = 0x4000 | 0x30;	//9
//	INTC_0.PSR[724].R = 0x4000 | 0x0A;	//1_10
//	INTC_0.PSR[725].R = 0x4000 | 0x0A;	//1_11
//	INTC_0.PSR[726].R = 0x4000 | 0x0A;	//1_12
	INTC_0.PSR[727].R = 0x4000 | 0x0A;	//1_13
//	INTC_0.PSR[728].R = 0x4000 | 0x0A;
//	INTC_0.PSR[729].R = 0x4000 | 0x0A;
	INTC_0.PSR[730].R = 0x4000 | 0x0A;  //EMIOS1-16
	INTC_0.PSR[731].R = 0x4000 | 0x0A;   //EMIOS1-17  DIN_T24-- add for aging test
	//INTC_0.PSR[732].R = 0x4000 | 0x0A;
//	INTC_0.PSR[733].R = 0x4000 | 0x0A;	//1_19
	INTC_0.PSR[734].R = 0x4000 | 0x0A;	//EMIOS1-20
//	INTC_0.PSR[735].R = 0x4000 | 0x0A;	//1_21
//	INTC_0.PSR[736].R = 0x4000 | 0x0A;	//1_22
	//INTC_0.PSR[737].R = 0x4000 | 0x14;	//将中断送给core1 && 设置该中断优先级为20 :: cycle count for PWM in  :: no pins

}

void eMIOS_Close(uint8_t x)
{
	volatile struct eMIOS_tag * p_eMIOS;
	if(x == EMIOS0)
		p_eMIOS = eMIOS[0];
	else
		p_eMIOS = eMIOS[1];

	p_eMIOS->MCR.B.GPREN = 0;  /* Disable global pre-scaler (reset default) */
	p_eMIOS->MCR.B.FRZ = 0;    /* No Freeze channel registers in debug mode if channel FREN=0 */
}

void eMIOS_Start(uint8_t x)
{
	volatile struct eMIOS_tag * p_eMIOS;
	if(x == EMIOS0)
		p_eMIOS = eMIOS[0];
	else
		p_eMIOS = eMIOS[1];
	p_eMIOS->MCR.B.GPRE = 19;  /* Divide 100 MHz clock to module by 20 ; 100M/20=5M*/
	p_eMIOS->MCR.B.GPREN = 1;    /* Enable global pre-scaled clocks*/
	p_eMIOS->MCR.B.GTBE = 1;     /* Enable global time base */
}

void eMIOS_Init(uint8_t x)
{
	volatile struct eMIOS_tag * p_eMIOS;
	if(x == EMIOS0)
		p_eMIOS = eMIOS[0];
	else
		p_eMIOS = eMIOS[1];

	//EMIOS_CH23_MCB	******   base cycle count for PWM_IN must Initial  ******
	p_eMIOS->C23.R = 0x0;  		/* Disable channel pre-scaler (reset default) */
	p_eMIOS->A23.R = MCB_COUNT; 		/* MCB mode: period will be 10M/100M clocks */
	p_eMIOS->C23.B.MODE = 0x50;	/* Modulus Counter Buffered (Up ctr) */
	p_eMIOS->C23.B.FEN	= 1;	//set interrupt
	p_eMIOS->C23.B.UCPRE = 0;  	/* Pre-scale channel clock by 0+1=1 */
	p_eMIOS->C23.B.UCPREN= 1;  	/* Enable pre-scaler */

	//EMIOS IPWM Mode
	p_eMIOS->C8.R	= 0x0;		/* Disable channel pre-scaler (reset default) */
	p_eMIOS->C8.R	= 0x00140004;	/* Using IPWM Mode */
	p_eMIOS->C9.R	= 0x0;		/* Disable channel pre-scaler (reset default) */
	p_eMIOS->C9.R	= 0x00140004;	/* Using IPWM Mode */
	p_eMIOS->C10.R	= 0x0;		/* Disable channel pre-scaler (reset default) */
	p_eMIOS->C10.R	= 0x00140004;	/* Using IPWM Mode */
	p_eMIOS->C11.R	= 0x0;		/* Disable channel pre-scaler (reset default) */
	p_eMIOS->C11.R	= 0x00140004;	/* Using IPWM Mode */
	p_eMIOS->C12.R	= 0x0;		/* Disable channel pre-scaler (reset default) */
	p_eMIOS->C12.R	= 0x00140004;	/* Using IPWM Mode */
	p_eMIOS->C13.R	= 0x0;		/* Disable channel pre-scaler (reset default) */
	p_eMIOS->C13.R	= 0x00140004;	/* Using IPWM Mode */
	p_eMIOS->C14.R	= 0x0;		/* Disable channel pre-scaler (reset default) */
	p_eMIOS->C14.R	= 0x00140004;	/* Using IPWM Mode */
	p_eMIOS->C15.R	= 0x0;		/* Disable channel pre-scaler (reset default) */
	p_eMIOS->C15.R	= 0x00140004;	/* Using IPWM Mode */
	p_eMIOS->C16.R	= 0x0;		/* Disable channel pre-scaler (reset default) */
	p_eMIOS->C16.R	= 0x00140004;	/* Using IPWM Mode */
	p_eMIOS->C17.R	= 0x0;		/* Disable channel pre-scaler (reset default) */
	p_eMIOS->C17.R	= 0x00140004;	/* Using IPWM Mode */
	if(x == EMIOS0)
	{
		p_eMIOS->C18.R	= 0x0;		/* Disable channel pre-scaler (reset default) */
		p_eMIOS->C18.R	= 0x00140004;	/* Using IPWM Mode */
	}
	p_eMIOS->C19.R	= 0x0;		/* Disable channel pre-scaler (reset default) */
	p_eMIOS->C19.R	= 0x00140004;	/* Using IPWM Mode */
	p_eMIOS->C20.R	= 0x0;		/* Disable channel pre-scaler (reset default) */
	p_eMIOS->C20.R	= 0x00140004;	/* Using IPWM Mode */
	p_eMIOS->C21.R	= 0x0;		/* Disable channel pre-scaler (reset default) */
	p_eMIOS->C21.R	= 0x00140004;	/* Using IPWM Mode */
	p_eMIOS->C22.R	= 0x0;		/* Disable channel pre-scaler (reset default) */
	p_eMIOS->C22.R	= 0x00140004;	/* Using IPWM Mode */
}

void eMIOS_CalculationAll(void)
{
//	uint32_t i;
//	for(i=0; i<EMIOSNUM; i++)
//		eMIOS_Calculation(i);
	eMIOS_Calculation(eMIOS_0_09);
	eMIOS_Calculation(eMIOS_0_12);
	eMIOS_Calculation(eMIOS_0_18);
	eMIOS_Calculation(eMIOS_1_13);
       /*add for aging test*/
	eMIOS_Calculation(eMIOS_0_10);
	eMIOS_Calculation(eMIOS_1_16);
	eMIOS_Calculation(eMIOS_1_17);
	eMIOS_Calculation(eMIOS_1_20);
    
}

void eMIOS_Calculation(_eMIOS_channel_ x)	//计算通道值
{
       #if 0
	float pH,pHL;
	eMIOS_PWMin_data[x].flag = lock;

	if(eMIOS_PWMin_data[x].A > eMIOS_PWMin_data[x].B)		//脉宽
		pH = eMIOS_PWMin_data[x].A - eMIOS_PWMin_data[x].B;
	else
		pH = MCB_COUNT + eMIOS_PWMin_data[x].A - eMIOS_PWMin_data[x].B;

	if(eMIOS_PWMin_data[x].A > eMIOS_PWMin_data[x].A_pre)	//周期
		pHL = eMIOS_PWMin_data[x].A - eMIOS_PWMin_data[x].A_pre;
	else
		pHL = MCB_COUNT + eMIOS_PWMin_data[x].A - eMIOS_PWMin_data[x].A_pre;

	eMIOS_PWMin_data[x].flag = unlock;

	eMIOS_PWMin_data[x].duty = 100.0f - (pH / pHL * 100.0f);
	eMIOS_PWMin_data[x].freq = EMIOSCLK / pHL;

#else
        if((eMIOS_PWMin_data[x].period!=0)&&(eMIOS_PWMin_data[x].pulsewidth!=0))
        {
            eMIOS_PWMin_data[x].duty = 100.0f - ((float)eMIOS_PWMin_data[x].pulsewidth / (float)eMIOS_PWMin_data[x].period * 100.0f);
            eMIOS_PWMin_data[x].freq = EMIOSCLK / (float)eMIOS_PWMin_data[x].period;
        }
        else
        {
            eMIOS_PWMin_data[x].freq=0;
            eMIOS_PWMin_data[x].duty=0;
        }
#endif
    
}

/******************************************** for interrupt ******/
void eMIOS_cycle(void)		//放置于5ms周期中
{
	uint32_t i;

	for(i=0; i<EMIOSNUM; i++)
	{
		eMIOS_PWMin_data[i].stoptick ++;
		if(eMIOS_PWMin_data[i].stoptick >EMIOS_OVERTIME)
		{
			eMIOS_PWMin_data[i].freq = 0.0;
			eMIOS_PWMin_data[i].duty = 0.0;
			eMIOS_PWMin_data[i].pulsewidth = 0.0;
			eMIOS_PWMin_data[i].period = 0.0;
		}
	}
}
















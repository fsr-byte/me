/*
 * SPI.c
 *
 *  Created on: 2018年9月5日
 *      Author: helei
 */

#define __SPI_GLOBALS__

#include "derivative.h"
#include "GPIO.h"
#include "SPI.h"
#include "math.h"


void DSPI_0_Master_Init(uint32_t sysClk, uint32_t baudRate)
{
	uint8_t bPBR,bBR;

    DSPI_0.MCR.B.HALT=1;
    DSPI_0.MCR.B.MSTR = 1;		// Set DSPIx in mode Slave-0 or Master-1
    DSPI_0.MCR.B.MDIS=0;    			// Enable clock
    DSPI_0.MCR.B.PCSIS=0x3F;		// CS0-5 active Low
    DSPI_0.MCR.B.CONT_SCKE = 0;
    //FIFOs
    DSPI_0.MCR.B.DIS_TXF=1;		//dis FIFOs
    DSPI_0.MCR.B.DIS_RXF=1;
   // DSPI_0.RSER.R = intMask;	//interrupt mask
    DSPI_0.MCR.B.FRZ = 0;

    //这里不对CS脚初始化，直接作为输出脚进行控制；为了使器件能有时间进行片选初始化
	SIUL_DigitalInputSimple(GPIO_PORTK+1,SIUL_SLEW_ENB);  // SIN_0 	->IN	//-SIUL_PULL_UP,SIUL_SLEW_ENB
    SIUL_DigitalOutput(GPIO_PORTK+2, 0x0D);                 // SOUT_0	->OUT
    SIUL_DigitalOutput(GPIO_PORTJ+14, 0x0E);                // SCK_0	->OUT

    DSPI_Clock(sysClk,baudRate,&bPBR,&bBR);

    //for SBC FS6500 B1 HW board
    DSPI_0.MODE.CTAR[0].B.DBR=0; 	// double baud rate
    DSPI_0.MODE.CTAR[0].B.FMSZ=15; 	// Frame size (value+1)
    DSPI_0.MODE.CTAR[0].B.CPOL=0; 	// Polarity CPOL=0=>sck is valid @1
    DSPI_0.MODE.CTAR[0].B.CPHA=1; 	// Phase CPHA=0=>data captured on leading edge
    DSPI_0.MODE.CTAR[0].B.LSBFE=0; 	// MSB first if 0
    DSPI_0.MODE.CTAR[0].B.PBR=bPBR;					//Baud rate
    DSPI_0.MODE.CTAR[0].B.BR=bBR;
    DSPI_0.MODE.CTAR[0].B.PCSSCK = PRESC_VAL1;		//tcsc
    DSPI_0.MODE.CTAR[0].B.CSSCK = SCALER3;//SCALER3
    DSPI_0.MODE.CTAR[0].B.PDT = PRESC_VAL3;//PRESC_VAL3			//tdt
    DSPI_0.MODE.CTAR[0].B.DT = SCALER4;//SCALER4
    DSPI_0.MODE.CTAR[0].B.PASC = PRESC_VAL1;			//tasc
    DSPI_0.MODE.CTAR[0].B.ASC = SCALER3;//SCALER3

    //for eeprom
    DSPI_0.MODE.CTAR[1].B.DBR=0; 	// double baud rate
    DSPI_0.MODE.CTAR[1].B.FMSZ=15; 	// Frame size (value+1)
    DSPI_0.MODE.CTAR[1].B.CPOL=0; 	// Polarity CPOL=0=>sck is valid @1
    DSPI_0.MODE.CTAR[1].B.CPHA=0; 	// Phase CPHA=0=>data captured on leading edge
    DSPI_0.MODE.CTAR[1].B.LSBFE=0; 	// MSB first if 0
    DSPI_0.MODE.CTAR[1].B.PBR=bPBR;					//Baud rate
    DSPI_0.MODE.CTAR[1].B.BR=bBR;
    DSPI_0.MODE.CTAR[1].B.PCSSCK = PRESC_VAL1;		//tcsc
    DSPI_0.MODE.CTAR[1].B.CSSCK = SCALER3;//SCALER3
    DSPI_0.MODE.CTAR[1].B.PDT = PRESC_VAL3;//PRESC_VAL3			//tdt
    DSPI_0.MODE.CTAR[1].B.DT = SCALER4;//SCALER4
    DSPI_0.MODE.CTAR[1].B.PASC = PRESC_VAL1;			//tasc
    DSPI_0.MODE.CTAR[1].B.ASC = SCALER3;//SCALER3

    DSPI_0.MCR.B.HALT=0;					// Allow transfer
}

void DSPI_1_Master_Init(uint32_t sysClk, uint32_t baudRate)
{
	uint8_t bPBR,bBR;

    DSPI_1.MCR.B.HALT=1;
    DSPI_1.MCR.B.MSTR = 1;		// Set DSPIx in mode Slave-0 or Master-1
    DSPI_1.MCR.B.MDIS=0;    			// Enable clock
    DSPI_1.MCR.B.PCSIS=0x3F;		// CS0-5 active Low
    //FIFOs
    DSPI_1.MCR.B.DIS_TXF=1;		//dis FIFOs
    DSPI_1.MCR.B.DIS_RXF=1;
   // DSPI_1.RSER.R = intMask;	//interrupt mask
    DSPI_1.MCR.B.FRZ = 0;

    //这里不对CS脚初始化，直接作为输出脚进行控制；为了使器件能有时间进行片选初始化
	SIUL_DigitalInputSimple(GPIO_PORTG+11,SIUL_PULL_UP | SIUL_SLEW_ENB);      // SIN_1 	->IN
    SIUL_DigitalOutput(GPIO_PORTG+12, 0x0D);                    // SOUT_1	->OUT
    SIUL_DigitalOutput(GPIO_PORTG+13, 0x0D);                    // SCK_1	->OUT

    DSPI_Clock(sysClk,baudRate,&bPBR,&bBR);

    //for NCV7240B | NCV7719
    DSPI_1.MODE.CTAR[0].B.DBR=0; 	// double baud rate
    DSPI_1.MODE.CTAR[0].B.FMSZ=15; 	// Frame size (value+1)
    DSPI_1.MODE.CTAR[0].B.CPOL=0; 	// Polarity CPOL=0=>sck is valid @1
    DSPI_1.MODE.CTAR[0].B.CPHA=1; 	// Phase CPHA=0=>data captured on leading edge
    DSPI_1.MODE.CTAR[0].B.LSBFE=0; 	// MSB first if 0
    DSPI_1.MODE.CTAR[0].B.PBR=bPBR;					//Baud rate
    DSPI_1.MODE.CTAR[0].B.BR=bBR;
    DSPI_1.MODE.CTAR[0].B.PCSSCK = PRESC_VAL1;		//tcsc
    DSPI_1.MODE.CTAR[0].B.CSSCK = SCALER3;//SCALER3
    DSPI_1.MODE.CTAR[0].B.PDT = PRESC_VAL3;//PRESC_VAL3			//tdt
    DSPI_1.MODE.CTAR[0].B.DT = SCALER4;//SCALER4
    DSPI_1.MODE.CTAR[0].B.PASC = PRESC_VAL1;			//tasc
    DSPI_1.MODE.CTAR[0].B.ASC = SCALER3;//SCALER3

    //for NCV7313B
    DSPI_1.MODE.CTAR[1].B.DBR=0; 	// double baud rate
    DSPI_1.MODE.CTAR[1].B.FMSZ=15; 	// Frame size (value+1)
    DSPI_1.MODE.CTAR[1].B.CPOL=0; 	// Polarity CPOL=0=>sck is valid @1
    DSPI_1.MODE.CTAR[1].B.CPHA=0; 	// Phase CPHA=0=>data captured on leading edge
    DSPI_1.MODE.CTAR[1].B.LSBFE=0; 	// MSB first if 0
    DSPI_1.MODE.CTAR[1].B.PBR=bPBR;					//Baud rate
    DSPI_1.MODE.CTAR[1].B.BR=bBR;
    DSPI_1.MODE.CTAR[1].B.PCSSCK = PRESC_VAL1;		//tcsc
    DSPI_1.MODE.CTAR[1].B.CSSCK = SCALER3;//SCALER3
    DSPI_1.MODE.CTAR[1].B.PDT = PRESC_VAL3;//PRESC_VAL3			//tdt
    DSPI_1.MODE.CTAR[1].B.DT = SCALER4;//SCALER4
    DSPI_1.MODE.CTAR[1].B.PASC = PRESC_VAL1;			//tasc
    DSPI_1.MODE.CTAR[1].B.ASC = SCALER3;//SCALER3

    //for SBC FS6500 B2 HW board
    DSPI_1.MODE.CTAR[2].B.DBR=0; 	// double baud rate
    DSPI_1.MODE.CTAR[2].B.FMSZ=15; 	// Frame size (value+1)
    DSPI_1.MODE.CTAR[2].B.CPOL=0; 	// Polarity CPOL=0=>sck is valid @1
    DSPI_1.MODE.CTAR[2].B.CPHA=1; 	// Phase CPHA=0=>data captured on leading edge
    DSPI_1.MODE.CTAR[2].B.LSBFE=0; 	// MSB first if 0
    DSPI_1.MODE.CTAR[2].B.PBR=bPBR;					//Baud rate
    DSPI_1.MODE.CTAR[2].B.BR=bBR;
    DSPI_1.MODE.CTAR[2].B.PCSSCK = PRESC_VAL1;		//tcsc
    DSPI_1.MODE.CTAR[2].B.CSSCK = SCALER3;//SCALER3
    DSPI_1.MODE.CTAR[2].B.PDT = PRESC_VAL3;//PRESC_VAL3			//tdt
    DSPI_1.MODE.CTAR[2].B.DT = SCALER4;//SCALER4
    DSPI_1.MODE.CTAR[2].B.PASC = PRESC_VAL1;			//tasc
    DSPI_1.MODE.CTAR[2].B.ASC = SCALER3;//SCALER3

    DSPI_1.MCR.B.HALT=0;					// Allow transfer
}

void DSPI_Send(uint8_t DspiNumber,uint8_t Ctar,uint16_t Word)
{
    uint32_t secure_counter = 0;

	//pointer setting
	volatile struct DSPI_tag *p_DSPI;				//base pointer
	switch(DspiNumber){								//choose base DSPI address
        case 0 : p_DSPI = &DSPI_0; break;
        case 1 : p_DSPI = &DSPI_1; break;
        case 2 : p_DSPI = &DSPI_2; break;
		case 3 : p_DSPI = &DSPI_3; break;
        default: p_DSPI = &DSPI_0; break;
    }

	if(Ctar == 0)
	{
	    p_DSPI->PUSHR.PUSHR.R = 0x80000000 | CTAR0 | PCS_default | Word;
	}
	else if (Ctar == 1)
	{
	    p_DSPI->PUSHR.PUSHR.R = 0x80000000 | CTAR1 | PCS_default | Word;
	}
	else
	{
	    p_DSPI->PUSHR.PUSHR.R = 0x80000000 | CTAR2 | PCS_default | Word;
	}

    if(p_DSPI->MCR.B.MSTR==MASTER){
	    	while((p_DSPI->SR.B.TCF!=1) && (secure_counter < DSPI_SECURE_COUNTER)){
			secure_counter++;
		}; 			// Wait end of transfert if MASTER
	    	p_DSPI->SR.B.TCF=1;									// Clear Transfert Flag
	    }
}

uint32_t DSPI_Read(uint8_t DspiNumber)
{
	volatile struct DSPI_tag *p_DSPI;				//base pointer
    uint32_t secure_counter = 0;
	uint32_t recData = 0;
	//pointer setting
	switch(DspiNumber)
	{											//choose base DSPI address
		case 0 : p_DSPI = &DSPI_0; break;
		case 1 : p_DSPI = &DSPI_1; break;
		case 2 : p_DSPI = &DSPI_2; break;
		case 3 : p_DSPI = &DSPI_3; break;
		default: p_DSPI = &DSPI_0; break;
	}
	while((p_DSPI->SR.B.RFDF != 1) && (secure_counter < DSPI_SECURE_COUNTER)){
		    secure_counter++;
		};	//wait for RX data
	recData = p_DSPI->POPR.R;					//get received data
	p_DSPI->SR.B.RFDF = 1;						//clear receive flag
	p_DSPI->SR.B.TCF = 1;							//clear transfer complete flag
	return recData;
}

void DSPI_Clock(uint32_t sysClk, uint32_t baudRate, uint8_t *binaryPBR, uint8_t *binaryBR)
{
    uint32_t p1 = sysClk/baudRate;				//basic parameter
    uint32_t realBR = 0;
    uint32_t realBR1 = 0;
    uint32_t realBR2 = 0;
    uint32_t realBR3 = 0;
    uint32_t realBR4 = 0;
    int16_t errorBR = 32767;							//undesirable value of error
    int16_t errorBR1 = 0;
    int16_t errorBR2 = 0;
    int16_t errorBR3 = 0;
    int16_t errorBR4 = 0;

    //prescaler PBR = 00
    if( (p1>=RATIO_MIN1) && (p1<=RATIO_MAX1) )
    {
         realBR1 = p1*(1/PBR_VALUE1);
         realBR1 = DSPI_RoundBaudRate(realBR1);
         errorBR1 = baudRate - (sysClk/(PBR_VALUE1*realBR1));
         errorBR1 = (int16_t)fabs(errorBR1);
         if(errorBR1<errorBR)
         {
             errorBR = errorBR1;
             realBR = realBR1;
             *binaryPBR = PBR1;
         }
    }
    //prescaler PBR = 01
    if( (p1>=RATIO_MIN2) && (p1<=RATIO_MAX2) )
    {
        realBR2 = p1*(1/PBR_VALUE2);
        realBR2 = DSPI_RoundBaudRate(realBR2);
        errorBR2 = baudRate - (sysClk/(PBR_VALUE2*realBR2));
        errorBR2 = (int16_t)fabs(errorBR2);
        if(errorBR2<errorBR)
        {
             errorBR = errorBR2;
             realBR = realBR2;
             *binaryPBR = PBR2;
        }
    }
    //prescaler PBR = 10
    if( (p1>=RATIO_MIN3) && (p1<=RATIO_MAX3) )
    {
        realBR3 = p1*(1/PBR_VALUE3);
        realBR3 = DSPI_RoundBaudRate(realBR3);
        errorBR3 = baudRate - (sysClk/(PBR_VALUE3*realBR3));
        errorBR3 = (int16_t)fabs(errorBR3);
        if(errorBR3<errorBR)
        {
           errorBR = errorBR3;
           realBR = realBR3;
           *binaryPBR = PBR3;
        }
    }
    //prescaler PBR = 11
    if( (p1>=RATIO_MIN4) && (p1<=RATIO_MAX4) )
    {
        realBR4 = p1*(1/PBR_VALUE4);
        realBR4 = DSPI_RoundBaudRate(realBR4);
        errorBR4 = baudRate - (sysClk/(PBR_VALUE4*realBR4));
        errorBR4 = (int16_t)fabs(errorBR4);
        if(errorBR4<errorBR)
        {
            errorBR = errorBR4;
            realBR = realBR4;
            *binaryPBR = PBR4;
        }
    }
    //choose the BR value
    if( (p1<RATIO_MIN1) || (p1>RATIO_MAX4) )
    {
        //out of bounds
        if(p1<RATIO_MIN1)
        {
             *binaryBR = BR1;										//lower than minimum
             *binaryPBR = PBR1;
        }
        else
        {
             *binaryBR = BR16;									//greater than maximum
             *binaryPBR = PBR4;
        }
    }
    else
    {																	//in the bounds
        switch(realBR)
        {
                case BR_VALUE1	: *binaryBR = BR1;	break;
                case BR_VALUE2  : *binaryBR = BR2;	break;
                case BR_VALUE3  : *binaryBR = BR3;	break;
                case BR_VALUE4  : *binaryBR = BR4;	break;
                case BR_VALUE5  : *binaryBR = BR5;	break;
                case BR_VALUE6  : *binaryBR = BR6;	break;
                case BR_VALUE7  : *binaryBR = BR7;	break;
                case BR_VALUE8  : *binaryBR = BR8;	break;
                case BR_VALUE9  : *binaryBR = BR9;	break;
                case BR_VALUE10	: *binaryBR = BR10;	break;
                case BR_VALUE11	: *binaryBR = BR11;	break;
                case BR_VALUE12	: *binaryBR = BR12;	break;
                case BR_VALUE13	: *binaryBR = BR13;	break;
                case BR_VALUE14	: *binaryBR = BR14;	break;
                case BR_VALUE15	: *binaryBR = BR15;	break;
                case BR_VALUE16	: *binaryBR = BR16;	break;
        }
    }
}

uint32_t DSPI_RoundBaudRate(uint32_t pureBR)
{					//IN - computed baud rate  OUT - baud rate from a list
    uint32_t BR = 0;
    if( (pureBR >= 2) && (pureBR < 3) )
    {
        BR = 2;
    }
    if( (pureBR >= 3) && (pureBR < 5) )
    {
        BR = 4;
    }
    if( (pureBR >= 5) && (pureBR < 7) )
    {
        BR = 6;
    }
    if( (pureBR >= 7) && (pureBR < 12) )
    {
        BR = 8;
    }
    if( (pureBR >= 12) && (pureBR < 24) )
    {
        BR = 16;
    }
    if( (pureBR >= 24) && (pureBR < 48) )
    {
        BR = 32;
    }
    if( (pureBR >= 48) && (pureBR < 96) )
    {
        BR = 64;
    }
    if( (pureBR >= 96) && (pureBR < 192) )
    {
        BR = 128;
    }
    if( (pureBR >= 192) && (pureBR < 384) )
    {
        BR = 256;
    }
    if( (pureBR >= 384) && (pureBR < 768) )
    {
        BR = 512;
    }
    if( (pureBR >= 768) && (pureBR < 1536) )
    {
        BR = 1024;
    }
    if( (pureBR >= 1536) && (pureBR < 3072) )
    {
        BR = 2048;
    }
    if( (pureBR >= 3072) && (pureBR < 6144) )
    {
        BR = 4096;
    }
    if( (pureBR >= 6144) && (pureBR < 12288) )
    {
        BR = 8192;
    }
    if( (pureBR >= 12288) && (pureBR < 24576) )
    {
        BR = 16384;
    }
    if( (pureBR >= 24576) && (pureBR < 32768) )
    {
        BR = 32768;
    }

    return BR;
}








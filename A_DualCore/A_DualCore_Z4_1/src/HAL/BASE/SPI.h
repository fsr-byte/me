/*
 * SPI.h
 *
 *  Created on: 2018Äê9ÔÂ5ÈÕ
 *      Author: helei
 */

#ifndef BASE_SPI_H_
#define BASE_SPI_H_

#include "typedefs.h"

#ifdef __SPI_GLOBALS__
#define __SPI_EXTERN__
#else
#define __SPI_EXTERN__  extern
#endif

#define MASTER 1
#define SLAVE  0

#define PBR_VALUE1	2.
#define PBR_VALUE2	3.
#define PBR_VALUE3	5.
#define PBR_VALUE4	7.

#define PBR1	0x0
#define PBR2	0x1
#define PBR3	0x2
#define PBR4	0x3

#define BR_VALUE1		2
#define BR_VALUE2		4
#define BR_VALUE3		6
#define BR_VALUE4		8
#define BR_VALUE5		16
#define BR_VALUE6		32
#define BR_VALUE7		64
#define BR_VALUE8		128
#define BR_VALUE9		256
#define BR_VALUE10      512
#define BR_VALUE11      1024
#define BR_VALUE12      2048
#define BR_VALUE13      4096
#define BR_VALUE14      8192
#define BR_VALUE15      16384
#define BR_VALUE16      32768

#define BR1             0x0
#define BR2             0x1
#define BR3             0x2
#define BR4             0x3
#define BR5             0x4
#define BR6             0x5
#define BR7             0x6
#define BR8             0x7
#define BR9             0x8
#define BR10            0x9
#define BR11            0xA
#define BR12            0xB
#define BR13            0xC
#define BR14            0xD
#define BR15            0xE
#define BR16            0xF

///Minimal values of the ratio (fsys/SCKbr) with different PBR setting
#define RATIO_MIN1	4
#define RATIO_MIN2	6
#define RATIO_MIN3	10
#define RATIO_MIN4	14
///Maximal values of the ratio (fsys/SCKbr) with different PBR setting
#define RATIO_MAX1	65536
#define RATIO_MAX2	98304
#define RATIO_MAX3	163840
#define RATIO_MAX4	229376

///CTAR defines
#define LOW_SCK				0	//CPOL
#define HIGH_SCK			1
#define CAPTURE_RISING		0	//CPHA
#define CAPTURE_FALLING     1
#define NORMAL_BR			0	//DBR
#define DOUBLED_BR			1
///CTAR Prescalers
#define PRESC_VAL1		0
#define PRESC_VAL3		1
#define PRESC_VAL5		2
#define PRESC_VAL7		3
///CTAR Scalers
#define SCALER1		    0x0
#define SCALER2		    0x1
#define SCALER3		    0x2
#define SCALER4		    0x3
#define SCALER5		    0x4
#define SCALER6		    0x5
#define SCALER7		    0x6
#define SCALER8		    0x7
#define SCALER9         0x8
#define SCALER10        0x9
#define SCALER11		0xA
#define SCALER12		0xB
#define SCALER13		0xC
#define SCALER14		0xD
#define SCALER15		0xE
#define SCALER16		0xF

///Interrupts
#define TCFRE	0x80000000
#define EOQFRE	0x10000000
#define TFUFRE	0x08000000
#define TFFFRE	0x02000000
#define RFOFRE	0x00080000
#define RFDFRE	0x00020000

///Offset definitions
#define CTAR0_OFF	0x000C	//till CTAR5 by 4 Bytes each
#define TXFR0_OFF	0x003C	//till TXFR3 by 4 Bytes each
#define RXFR0_OFF	0x007C	//till RXFR3 by 4 Bytes each

//DSPI  define
#define SELECT_DSPI0		0
#define SELECT_DSPI1		1

#define SELECT_CTAR0		0
#define SELECT_CTAR1		1
#define SELECT_CTAR2		2

#define CTAR0	0x00000000
#define CTAR1	0x10000000
#define CTAR2   0x20000000
//#define PCS_default	0x10000
#define SELECT_PCS0	0x010000
#define SELECT_PCS1	0x020000
#define SELECT_PCS2	0x040000
#define SELECT_PCS3	0x080000
#define SELECT_PCS4	0x100000
#define SELECT_PCS5	0x200000
#define PCS_default	SELECT_PCS0

#define DSPI_SECURE_COUNTER 50000


__SPI_EXTERN__ void DSPI_0_Master_Init(uint32_t sysClk, uint32_t baudRate);
__SPI_EXTERN__ void DSPI_1_Master_Init(uint32_t sysClk, uint32_t baudRate);
__SPI_EXTERN__ void DSPI_Send(uint8_t DspiNumber,uint8_t Ctar,uint16_t Word);
__SPI_EXTERN__ uint32_t DSPI_Read(uint8_t DspiNumber);

__SPI_EXTERN__ void DSPI_Clock(uint32_t sysClk, uint32_t baudRate, uint8_t *binaryPBR, uint8_t *binaryBR);
__SPI_EXTERN__ uint32_t DSPI_RoundBaudRate(uint32_t pureBR);




#endif /* BASE_SPI_H_ */

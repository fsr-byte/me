/*
 * M95128.h
 *
 *  Created on: 2018年10月16日
 *      Author: helei
 */

#ifndef HAL_MODULES_M95128_H_
#define HAL_MODULES_M95128_H_

#include "typedefs.h"

#ifdef __M95128_GLOBALS__
#define __M95128_EXTERN__
#else
#define __M95128_EXTERN__  extern
#endif


#define M95128_CS		GPIO_PORTK+4
#define M95128_CS_Enable()		SIUL_ClearPad(M95128_CS)
#define M95128_CS_Disable()		SIUL_SetPad(M95128_CS)

#define M95128_ReReadTimes		1	//控制SPI读取次数，以保证数据的正确性
#define M95128_ReWriteTimes		1	//控制SPI写入次数，以保证数据的正确性

// M95128 EEPROM Command definitions
#define M95128_READ   0x03u   // Read data from array beginning at address;
#define M95128_WRITE  0x02u   // Write data to array beginning at address (max 64 bytes);
#define M95128_WRDI   0x04u   // Disable write operation;
#define M95128_WREN   0x06u   // Enable write operation;
#define M95128_RDSR   0x05u   // Read status register;
#define M95128_WRSR   0x01u   // Write status register;
///#define M95128_WIP    0x01   // Write is in the progress

//just for M95128-D device not our device
#define M95128_RDID   0x83u   // Read Identification Page
#define M95128_WRID   0x82u   // Write Identification Page
#define M95128_RDLS   0x83u   // Reads the Identification Page lock status
#define M95128_LID    0x82u   // Locks the Identification page in read-only mode

#define M95128_PageSize		0x40	//即64bytes,表示页的大小
#define M95128_Capacity		0x4000	//16KBytes	最大容量
#define M95128_PageAmount	0x100	//页的数量


__M95128_EXTERN__ void M95128_Init(void);
__M95128_EXTERN__ void M95128_tx(uint16_t data);
__M95128_EXTERN__ uint16_t M95128_rx(void);
__M95128_EXTERN__ uint8_t M95128_ReadStatus(void)	;
__M95128_EXTERN__ void M95128_WriteStatus(uint8_t status);
__M95128_EXTERN__ void M95128_WriteEnable(void);
__M95128_EXTERN__ void M95128_WriteDisable(void);
__M95128_EXTERN__ uint8_t Read_byte_EE(uint16_t addr);
__M95128_EXTERN__ void Write_byte_EE(uint16_t addr, uint8_t data);

__M95128_EXTERN__ uint32_t ReadExtEE(uint16_t addr, uint16_t size, uint8_t * data);
__M95128_EXTERN__ uint32_t WriteExtEE(uint16_t addr, uint16_t size, uint8_t *data);

__M95128_EXTERN__ uint8_t M95128_OperationAlready(void);

#endif /* HAL_MODULES_M95128_H_ */

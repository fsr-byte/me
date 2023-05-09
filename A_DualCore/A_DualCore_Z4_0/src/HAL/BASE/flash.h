/*
 * flash.h
 *
 *  Created on: 2018年6月12日
 *      Author: helei
 */

#ifndef HAL_BASE_FLASH_H_
#define HAL_BASE_FLASH_H_

#include "typedefs.h"

#ifdef __FLASH_GLOBALS__
#define __FLASH_EXTERN__
#else
#define __FLASH_EXTERN__  extern
#endif

/*		宏定义函数，方便使用	*/
#define WRITE8(address, value)      (*(vuint8_t*)(address) = (value))
#define READ8(address)              ((uint8_t)(*(vuint8_t*)(address)))
#define SET8(address, value)        (*(vuint8_t*)(address) |= (value))
#define CLEAR8(address, value)      (*(vuint8_t*)(address) &= ~(value))

#define WRITE16(address, value)     (*(vuint16_t*)(address) = (value))
#define READ16(address)             ((uint16_t)(*(vuint16*)(address)))
#define SET16(address, value)       (*(vuint16_t*)(address) |= (value))
#define CLEAR16(address, value)     (*(vuint16_t*)(address) &= ~(value))

#define WRITE32(address, value)     (*(vuint32_t*)(address) = (value))
#define READ32(address)             ((uint32_t)(*(vuint32_t*)(address)))
#define SET32(address, value)       (*(vuint32_t*)(address) |= (value))
#define CLEAR32(address, value)     (*(vuint32_t*)(address) &= ~(value))

#define EE_LockBlock(MidId)			((C55FMC.LOCK0.B.MIDLOCK) |= (MidId))
#define EE_UnLockBlock(MidId)		((C55FMC.LOCK0.B.MIDLOCK) &= ~(MidId))

//对应MidId
#define MidId_get(x)		(~(0x0001 << x))
#define MidId_select(x)		(0x0001 << x)

//error
#define ERR_FLASH_EE_GetMidIdx	0xFF	//地址不在EE范围内

#define FLASH_EE_IDLE  1
#define FLASH_EE_BUSY 0

__FLASH_EXTERN__ const uint32_t EE_StartAddress[];

/*********************		function		*******************************/
__FLASH_EXTERN__ void FLASH_EE_UnLock(uint32_t address, uint32_t length);
__FLASH_EXTERN__ void FLASH_EE_EraseBlock(uint8_t MidIdx);
__FLASH_EXTERN__ void FLASH_EE_EraseAll(void);
__FLASH_EXTERN__ void FLASH_EE_Erase(uint32_t address, uint32_t length);
__FLASH_EXTERN__ void FLASH_EE_EraseStart(uint32_t address, uint32_t length);
__FLASH_EXTERN__ void FLASH_EE_EraseEnd(uint32_t address, uint32_t length);
__FLASH_EXTERN__ uint8_t FLASH_EE_Alone_Write32(uint32_t address, uint32_t value);
__FLASH_EXTERN__ uint32_t FLASH_EE_Write8(uint32_t address, uint32_t length, uint8_t *data);
__FLASH_EXTERN__ void FLASH_EE_Write32(uint32_t address, uint32_t length, uint32_t *data);
__FLASH_EXTERN__ uint32_t FLASH_EE_Read8(uint32_t address, uint32_t length, uint8_t * rbuff);
__FLASH_EXTERN__ uint8_t FLASH_EE_CheckBusy(void);

#endif /* HAL_BASE_FLASH_H_ */

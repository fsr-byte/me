/*
 * NVM.h
 *
 *
 *  Created on: 2018-10-11
 *      Author: ZhouYi
 */

#ifndef NVM_DTC_H_
#define NVM_DTC_H_

#include "typedefs.h"

#ifdef __NVM_GLOBALS__
#define __NVM_EXTERN__
#else
#define __NVM_EXTERN__  extern
#endif


/* -----------------------------------------------------------------------------
    Global Macro Definitions
------------------------------------------------------------------------------*/

#define FLAG_SIZE  8

#define DTC_CODE_SIZE      3
#define EXTEE_PAGE_SIZE         64
#define MIN_EXEEE_RW_SIZE    8

#define DTC_SNAP_LEN       61   /*DTC snapshot length: DTC index (RAM) or occurance (EEPROM) + freezeFrame(37+23) */
#define EXT_DTC_FLAG_ADDR      0x0
#define EXT_DTC_FLAG_SIZE        4
#define EXT_DTC_VALID_FLAG      0x20180911
#define EXT_DTC_START_ADDR    (EXT_DTC_FLAG_ADDR + EXTEE_PAGE_SIZE)
#define DTC_NUM_IN_RAM          40             /*CR 1414,1570: maximum 40 DTC records in RAM table (to save RAM)*/

#define EXTEE_OK	0
#define EXTEE_BUSY 	1
#define EXTEE_ERROR 2
#define EXTEE_OUTRANGE 3

#define EXTEE_MIN_WRTE_SIZE 8
#define EXTEE_MIN_READ_SIZE 8

#define SECA_FAILED_TIMER_PAGE 170


__NVM_EXTERN__ void NVM_DTC_Init(void);
__NVM_EXTERN__ void NVM_DTC_Task(void);
__NVM_EXTERN__ uint32_t NVM_ReadSecAFailedCounterAndTimer(uint8_t * pFailedCnt);
__NVM_EXTERN__ void NVM_SaveSecAFailedCounterAndTimer(void);
__NVM_EXTERN__ uint8_t  usReadDTCAgingCounter(uint8_t DTCIdx, uint8_t SnapRdId);

#endif /* NVM_DTC_H_ */

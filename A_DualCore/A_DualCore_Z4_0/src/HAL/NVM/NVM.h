/*
 * NVM.h
 *
 *
 *  Created on: 2018-10-11
 *      Author: ZhouYi
 */

#ifndef NVM_H_
#define NVM_H_

#include "typedefs.h"
#include "NVM_DidCal.h"
#include "NVM_DTC.h"
#include "NVM_AppData.h"

#ifdef __NVM_GLOBALS__
#define __NVM_EXTERN__
#else
#define __NVM_EXTERN__  extern
#endif
/* -----------------------------------------------------------------------------
    NVM module  type Definitions
------------------------------------------------------------------------------*/
/*EEPROM RW type bit mapping*/
#define EXTEE_IDLE          0   /* EEPROM idle*/
#define EXTEE_BACK_APP_HIST     1  /* history App Data area should be  written into EEPROM*/
#define EXTEE_BACK_APP_ENM     2  /* ENM App Data area  should be  written into EEPROM*/
#define EXTEE_WRITE_APP_HIST     4  /* history App Data area should be  written into EEPROM*/
#define EXTEE_WRITE_APP_ENM     8  /* ENM App Data area  should be  written into EEPROM*/

#define WRITE_EXT_RPOG_FINISHED  0
#define WRITE_EXT_PROG_ONGOING  1

/*DFLASH RW type bit mapping*/
#define DFLASH_IDLE  0          /* DFLASH idle*/
#define DFLASH_ERASING     1  /* DFLASH is being erased*/
#define DFLASH_WRITE_DTC     2  /* DTC snapshot  should be  written into DFLASH*/
#define DFLASH_WRITE_DID     4  /* DID data  should be  written into DFLASH*/
#define DFLASH_WRITE_APP_HIST     8  /* history App Data area should be  written into DFLASH*/
#define DFLASH_WRITE_APP_ENM     0x10  /* ENM App Data area  should be  written into DFLASH*/
#define DFLASH_WRITE_EXT_PROG      0x20  /*writing external program flag*/

__NVM_EXTERN__  uint8_t DFlashRWStatus;         /* DFLASH block read/write status*/

/* -----------------------------------------------------------------------------
      NVM module  Macro Definitions
------------------------------------------------------------------------------*/
__NVM_EXTERN__ void NvM_Init(void);
__NVM_EXTERN__ void NvM_Task(void);
__NVM_EXTERN__ void NvMDTC_SaveToDFlash(void);

__NVM_EXTERN__ void WriteCalDatalntoDFlash(void);
__NVM_EXTERN__ usResultType usClearRAMDTC(void);
__NVM_EXTERN__ void usClearDTCFinished(void);
__NVM_EXTERN__ usResultType usClearEEPROMDTC (uint32_t DTC, uint16_t DTCIdx, uint8_t status);
__NVM_EXTERN__ void NvM_StartWriteExtProgRequest(void);
__NVM_EXTERN__ uint8_t NvM_GetWriteExtProgRequestStatus(void);


__NVM_EXTERN__ uint8_t HistDataCheckFaliedFlag;    /*历史数据检查错误*/
__NVM_EXTERN__ uint8_t AppDataCheckFaliedFlag;     /*续航数据检查错误*/
__NVM_EXTERN__ boolean gbCalDataCorrect;  /*标定数据检查错误*/
__NVM_EXTERN__ uint8_t seriousHistFaultFlag ;  /*serious DTC fault, can not go to HV state*/
__NVM_EXTERN__ uint8_t IGBTFaultFromMCU;
#endif /* NVM_H_ */

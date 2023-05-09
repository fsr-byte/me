/*
 * NVM_Data.h
 *
 *
 *  Created on: 2019-3-27
 *      Author: ZhouYi
 */

#ifndef NVM_DATA_H_
#define NVM_DATA_H_

#include "typedefs.h"
#include "Global.h"
#ifdef __NVM_GLOBALS__
#define __NVM_EXTERN__
#else
#define __NVM_EXTERN__  extern
#endif
#define CRC_INIT_VAL    0xFFFFFFFF
#define APP_FLAG_SIZE 4
#define APP_CRC_SIZE 4

#define HIST_DATA_AREA_NUM 1
#define ENM_DATA_AREA_NUM 1


#define PMM_ACTIVE  1    /*match with PMM  active flag(VPMM_InternalSleepActive_flg)*/
#define PMM_INACTIVE 0
#define HIST_DATA_INDEX 0  /*history data index is 0 in following tables*/
#define ENM_DATA_INDEX 1   /*ENM data index is 1 in following tables*/

#define NvMLoadIdle        0       /*data was loaded from DFlash */
#define NvMDFlashLoaded   1       /*data was loaded from DFlash */
#define NvMLoadingEEPROM_HIST  2        /*loading EEPOM data for history data area */
#define NvMLoadingEEPROM_ENM  3        /*loading EEPOM data for ENM data area */
#define NvMBackUpDFlash_HIST  4      /*backup data to  DFlash for history data area*/
#define NvMBackUpDFlash_ENM  5      /*backup data to  DFlash for ENM data area  */
#define NvMBackUpEEPROM_HIST  6      /*backup data to  EEPROM forhistory data area */
#define NvMBackUpEEPROM_ENM  7      /*backup data to  EEPROM for ENM data area */

#define NvMSaveIdle  0    /*prepaing data to be saved*/
#define NvMSavePrepareData  1    /*prepaing data to be saved*/
#define NvMSaveDFlash_HIST  2      /*Save data to  DFlash for history data area*/
#define NvMSaveDFlash_ENM  3      /*Save data to  DFlash for ENM data area */
#define NvMSaveEEPROM_HIST  4      /*Save data to  EEPROM for history data area*/
#define NvMSaveEEPROM_ENM  5      /*Save data to  EEPROM for ENM data area */
#define NvMSaveDFLASH_TIMEOUT 6 
#define NvMSaveEEPROM_TIMEOUT 7


typedef struct NvMHandle
{
    uint8_t    errorState;
    uint8_t    currAppDataArea;
    
    boolean DFlashOK[HIST_DATA_AREA_NUM +ENM_DATA_AREA_NUM ];
    boolean EepromOK[HIST_DATA_AREA_NUM +ENM_DATA_AREA_NUM];

    boolean backToEepromFlag[HIST_DATA_AREA_NUM +ENM_DATA_AREA_NUM];

    uint16_t   currDataCursor;
    uint32_t   OperStartTime;   /*NVM erase/write operation start time*/

}NvMHandleType;


/* -----------------------------------------------------------------------------
    Global Macro Definitions
------------------------------------------------------------------------------*/
__NVM_EXTERN__ NvMLoadSaveType NvMAppDataSaveLoadFlag ;  

__NVM_EXTERN__ const uint32_t APP_DATA_DFLASH_ADDR_TBL[ HIST_DATA_AREA_NUM + ENM_DATA_AREA_NUM];

__NVM_EXTERN__  void NvMAppDataStartSave(void);
__NVM_EXTERN__  void NvMAppDataSaveToDFlash(uint8_t areaIndex);
__NVM_EXTERN__   boolean NvMAppData_NeedBackToEEPROM(void);

__NVM_EXTERN__ void NVM_AppData_Init(void);
__NVM_EXTERN__ boolean NvMAppData_LoadTask(void);
__NVM_EXTERN__ boolean NVM_AppData_SaveTask(void);
__NVM_EXTERN__ uint32_t CalcCrc32(uint8_t buf[], uint16_t len);



#endif /* NVM_DATA_H_ */

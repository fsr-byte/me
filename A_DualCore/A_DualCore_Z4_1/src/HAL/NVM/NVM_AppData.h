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


typedef enum EEPLoadSave
{
	EEPNoOperation = 0, 		/*data not loaded and not saved*/
	EEPDataLoaded = 1, 		/* all app data areas loaded from EEPROM*/
	EEPDataSaved = 2, 		/*all  app data areas saved to EEPROM*/
	EEPLoadingData = 3,       /*data is being loaded (internal DFlash + external EEPROM)*/
       EEPBackToDFlash  = 4,      /*back up data to DFLASH while loading loaded*/
	EEPBackToExtEE  = 5,      /*back up data to external EEPROM while loading loaded*/
	EEPSavingDFlash = 6,       /*saving data to DFlash is in progress*/
	EEPSavingExtEE= 7       /*saving data to external EEPROM is in progress*/
}EEPLoadSaveType;

//ÒÆ¶¯µ½Global.h
//typedef enum NvMLoadSave
//{
//	NvMDataLoading = 0,       /*data is being loaded from NVM*/
//	NvMDataLoaded  = 1, 		/* all app data areas loaded from NVM*/
//       NvMDataSaving  = 2,      /*data is being saved to NVM*/
//	NvMDataSaved   = 3, 		/*all  app data areas saved to NVM*/
//}NvMLoadSaveType;

typedef enum NvMLoad
{
    NvMLoadingDFlash  = 0,       /*data is being loaded from DFlash */
    NvMLoadingEEPROM = 1,
    NvMOneAreaLoaded = 2,
    NvMBackupEraseDFlash = 3,    /*eraseing VCU2.0 DFlash not for VCU1.0*/
    NvMBackupToDFlash = 4,    /*data is being saved while backup data to DFlash */
    NvMBackupToEEPROM = 5,       /*data is being saved while backup data to EEPROM */
}NvMLoadType;

typedef enum NvMSave
{
    NvMSavePrepareData = 0,    /*prepaing data to be saved*/
    NvMSaveEraseDFlash = 1,     /*eraseing VCU2.0 DFlash not for VCU1.0*/
    NvMSaveWriteDFlash = 2,    /*data is being saved to DFlash */
    NvMSaveWriteEEPROM = 3,       /*data is being saved to EEPROM */
}NvMSaveType;

typedef struct NvMHandle
{
    NvMLoadType   loadType;
    NvMSaveType   SaveType;
    uint8_t    prevPMMActiveFlag;
    uint8_t    currAppDataArea;
    uint8_t    NvMFailedCount;
    uint8_t    errorState;
    uint16_t   currDataCursor;
    uint32_t   OperStartTime;   /*NVM erase/write operation start time*/

    uint32_t  DFlashCrc;
    uint32_t  EEPROMCrc;       
}NvMHandleType;

/* -----------------------------------------------------------------------------
    Global Macro Definitions
------------------------------------------------------------------------------*/
    __NVM_EXTERN__ NvMLoadSaveType NvMAppDataSaveLoadFlag ;  

__NVM_EXTERN__ void usStartTestSaving(void);

__NVM_EXTERN__ void NVM_AppData_Init(void);
__NVM_EXTERN__ void NVM_AppData_Task(void);
__NVM_EXTERN__ uint32_t CalcCrc32(uint8_t buf[], uint16_t len);



#endif /* NVM_DATA_H_ */

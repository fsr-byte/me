/*
 * NVM.c
 *
 *  Created on: 2018-10-11
 *      Author: ZhouYi
 *  the Non-volatile Memory management (internal EEPROM) is implemented by this moudle
 */

#define __SYS_GLOBALS__

#include "derivative.h"
#include <cstring>
#include "NVM.h"
#include "NVM_DidCal.h"
#include "NVM_DTC.h"
#include "NVM_AppData.h"
#include "PMM_Model_types.h"
#include "M95128.h"
#include "UDS_service.h"


/* =================  Private type Declarations =========================*/

typedef struct NvMPwrStatus_
{
    uint8_t  currState;                             
    uint8_t  prevPMMActiveFlag;            /*record previous PMM active status*/
    uint16_t DFlashEraseTimeOut;         /**/
    uint32_t DFlashEraseStartTime;  
    uint8_t  prevBTKSleepFlag;            /*record previous BTK sleep allow*/
}NvMStatusType;

/* =================  Private macro Declarations =========================*/
#define NVM_INITING     0   /*NVM is in initializing phase*/
#define NVM_BACKUP    1   /*NVM is back-uping app data*/
#define NVM_RUNNING    2  /*NVM module running */
#define NVM_PRESLEEP   3 /*entered pre-sleep mode*/
//@@@@#define MAX_DFLASH_ERASE_TIME   400   /*it cost about 350ms to erase a DFLASH block, so set the timeout to 400ms*/

/* =================  Private Variable Declarations =========================*/
CORE0_INIT uint8_t DFlashRWStatus = 0;         /* DFLASH block read/write status*/
CORE0_INIT static NvMStatusType NvMStateMachine;
extern    uint8_t BootHeadTbl[BOOT_HEAD_LEN];
CORE0_INIT boolean NVM_WaitSave_flg = false;
/* =================  Private function Declarations =========================*/

/* =================  public funciton implementation =========================*/


/***************************************************************************************************************
 * Name:        NVM_Init
 * Function:    
 *              1. call the DID intialize function: load DID data from DFlash to RAM
 *              1. call the calibration  intialize function: load calibration data from DFlash to RAM 
 *              3. call the DTC loading function: read DTC initialized flag in EEPROM 
 *              4. call the application Data loading function: load history data and ENM data from DFLASH to RAM
 * Input:        null
 * Return:        null
 * Link:        
 * Attention:    
 ************************************************************************************************************* */
void NvM_Init(void)
{   
    DFlashRWStatus = DFLASH_IDLE;
    NvMStateMachine.currState = NVM_INITING;
    NvMStateMachine.prevPMMActiveFlag = PMM_INACTIVE;
    NvMStateMachine.prevBTKSleepFlag = 0;
    NVM_DID_Init();    
    NVM_Cal_Init();
    NVM_DTC_Init();
    NVM_AppData_Init();
}

/***************************************************************************************************************
 * Name:        CheckSleepFallingEdge
 * Function:    check the falling edge of PMM module active flag (VPMM_InternalSleepActive_flg), if detected, switch to Pre_sleep sate
 * Input:        null
 * Return:        null
 * Link:        
 * Attention:    
 ************************************************************************************************************* */
void CheckSleepFallingEdge(void)
{
    boolean IsUnactive = false;
    boolean IsActiveSave = false;
   /* wakeup source become invalid earlier than "PMM active flag become inactive" */
   if(WAKEUPSRC_INVALID == bswWakeSrc)
   {
       /*wakeup source is invalid , and PMM is inactive it means VCU is waked up by unexpcted PT CAN message, change NvMAppDataSaveLoadFlag to NvMDataSaved immediately*/
       if( PMM_INACTIVE == PMM_output.VPMM_InternalSleepActive_flg )
       {
           if( 2==Config_output.C_PMS_En )//BTK电源模式情况下
           {
               IsUnactive = ((PMM_INACTIVE == NvMStateMachine.prevPMMActiveFlag) && (!NVM_WaitSave_flg));
           }
           else
           {
               IsUnactive = (PMM_INACTIVE == NvMStateMachine.prevPMMActiveFlag) ;
           }
           if( IsUnactive )
           {
               NvMAppDataSaveLoadFlag = NvMDataSaved;
               NvMStateMachine.currState = NVM_PRESLEEP;
           }
           /*falling edge of  PMM  active flag(VPMM_InternalSleepActive_flg) detected, start the App data saving operation*/
           else if (PMM_ACTIVE == NvMStateMachine.prevPMMActiveFlag)
           {
               NVM_WaitSave_flg = true;
           }

           if( 2==Config_output.C_PMS_En )//BTK电源模式情况下,BTK允许sleep信号较PMM晚
           {
               IsActiveSave = NVM_WaitSave_flg && (VBTK_SleepAllw_flg&&(0==NvMStateMachine.prevBTKSleepFlag));
           }
           else
           {
               IsActiveSave = NVM_WaitSave_flg ;
           }
           if( IsActiveSave )
           {
               NVM_WaitSave_flg = false;
               NvMStateMachine.currState = NVM_PRESLEEP;
               NvMAppDataStartSave();
               /*save SecA failure record*/
               (void)NVM_SaveSecAFailedCounterAndTimer();
               /*reset DTC storage table */
               NvMReset_DTCStorage();
           }
           
       }
   }
}
/***************************************************************************************************************
 * Name:        CheckSleepRisingEdge
 * Function:    check the rising edge of PMM module active flag (VPMM_InternalSleepActive_flg), if detected, switch to Pre_sleep sate
 * Input:        null
 * Return:        null
 * Link:        
 * Attention:    
 ************************************************************************************************************* */
void CheckSleepRisingEdge(void)
{
    /*in pre-sleep state , app data saved, check for the rising edge of PMM active flag*/
    if(NvMDataSaved == NvMAppDataSaveLoadFlag)
    {
        /*rising edge of  PMM  active flag(VPMM_InternalSleepActive_flg) detected it means PMM was waked up again from 'pre-sleep ' state
        the application data won't change in pre-sleep phase because ENM is not called,  so change NvMAppDataSaveLoadFlag to NvMDataLoaded directly*/
        if((PMM_INACTIVE == NvMStateMachine.prevPMMActiveFlag) && ((PMM_ACTIVE == PMM_output.VPMM_InternalSleepActive_flg)/*&&(!NVM_BTKSleepAllow_flg)*/) )
        {
            NvMAppDataSaveLoadFlag = NvMDataLoaded;
            NvMStateMachine.currState = NVM_RUNNING;            
        }
    }
}
/***************************************************************************************************************
 * Name:        NvM_StartWriteExtProgRequest
 * Function:    set on the writing external program request to DFLASH flag
 * Input:        null
 * Return:        null
 * Link:        
 * Attention:    
 ************************************************************************************************************* */
 void NvM_StartWriteExtProgRequest(void)
 {
     DFlashRWStatus = DFlashRWStatus | DFLASH_WRITE_EXT_PROG;
 }
/***************************************************************************************************************
 * Name:        NvM_StartWriteExtProgRequest
 * Function:    set on the writing external program request to DFLASH flag
 * Input:        null
 * Return:        null
 * Link:        
 * Attention:    
 ************************************************************************************************************* */
uint8_t NvM_GetWriteExtProgRequestStatus(void)
{
    uint8_t rslt = WRITE_EXT_PROG_ONGOING;

    if(DFLASH_IDLE == (DFlashRWStatus & DFLASH_WRITE_EXT_PROG))
    {
        rslt = WRITE_EXT_RPOG_FINISHED;    
    }
    return rslt;
 }

/***************************************************************************************************************
 * Name:        NVM_DFlashWriteTask
 * Function:    
 * Input:        null
 * Return:        null
 * Link:        
 * Attention:    
 ************************************************************************************************************* */
 void NvM_DFlashWriteTask(void)
 {
     /* DFLASH block is NOT being erased, check if there is writing request*/
     if((DFlashRWStatus & DFLASH_ERASING) != DFLASH_ERASING)
     {
         NvMStateMachine.DFlashEraseTimeOut =  0;
         /*there is APP DFLASH writing request*/
         if((DFlashRWStatus & DFLASH_WRITE_APP_HIST) == DFLASH_WRITE_APP_HIST)
         {
             FLASH_EE_EraseStart(APP_DATA_DFLASH_ADDR_TBL[HIST_DATA_INDEX], 0x4000);
             DFlashRWStatus = DFlashRWStatus |DFLASH_ERASING;   /*set on the erasing request flag*/
             /*record erase start time, set the timeout threshold*/
             NvMStateMachine.DFlashEraseStartTime = SystemTickMs;
             NvMStateMachine.DFlashEraseTimeOut =  MAX_DFLASH_ERASE_TIME;
         }
         else if((DFlashRWStatus & DFLASH_WRITE_APP_ENM) == DFLASH_WRITE_APP_ENM)
         {
             FLASH_EE_EraseStart(APP_DATA_DFLASH_ADDR_TBL[ENM_DATA_INDEX], 0x4000);
             DFlashRWStatus = DFlashRWStatus |DFLASH_ERASING;   /*set on the erasing request flag*/
             /*record erase start time, set the timeout threshold*/
             NvMStateMachine.DFlashEraseStartTime = SystemTickMs;
             NvMStateMachine.DFlashEraseTimeOut =  MAX_DFLASH_ERASE_TIME;
         }
         /*there is DID DFLASH writing request*/
         /*if VCU is waked up by unexpected CAN message, core 1will powe off very soon. there could be an error: DFLASH DID info was erased, VCU power-off before new DTC info was written. DFLASH DID info was lost. 
          To prevent the situation: if PMM wakeup source is UNKNOWN, don't erase DID DFLASH , even  here is DID DFLASH writing request*/
         else if((DFlashRWStatus & DFLASH_WRITE_DID) == DFLASH_WRITE_DID)
         {
             if(WAKEUPSRC_UNKNOWN != bswWakeSrc)
             {
                 FLASH_EE_EraseStart(DID_DATA_START_ADDR, 0x4000);
                 DFlashRWStatus = DFlashRWStatus |DFLASH_ERASING;   /*set on the erasing request flag*/
                 /*record erase start time, set the timeout threshold*/
                 NvMStateMachine.DFlashEraseStartTime = SystemTickMs;
                 NvMStateMachine.DFlashEraseTimeOut =  MAX_DFLASH_ERASE_TIME;
             }
         }
         /*writing external program flag*/
         else if((DFlashRWStatus & DFLASH_WRITE_EXT_PROG) == DFLASH_WRITE_EXT_PROG)
         {
             FLASH_EE_EraseStart(BOOT_VERSION_ADDR, 0x4000);
             DFlashRWStatus = DFlashRWStatus |DFLASH_ERASING;   /*set on the erasing request flag*/
             /*record erase start time, set the timeout threshold*/
             NvMStateMachine.DFlashEraseStartTime = SystemTickMs;
             NvMStateMachine.DFlashEraseTimeOut =  MAX_DFLASH_ERASE_TIME;
         }

         /*there is DTC DFLASH writing request*/
         /*if VCU is waked up by unexpected CAN message, core 1 will powe off very soon. 
         There could be an error: DFLASH DTC info was erased, VCU power-off before new DTC info was written. DFLASH DTC info was lost. 
          To prevent the situation: if PMM wakeup source is UNKNOWN, don't erase DTC DFLASH , even  here is DTC DFLASH writing request*/
         else if((DFlashRWStatus & DFLASH_WRITE_DTC) == DFLASH_WRITE_DTC)
         {
             if(WAKEUPSRC_UNKNOWN != bswWakeSrc)
             {
                 FLASH_EE_EraseStart(DTCINFO_DFLASH_ADDR, 0x4000);
                 DFlashRWStatus = DFlashRWStatus |DFLASH_ERASING;   /*set on the erasing request flag*/
                 /*record erase start time, set the timeout threshold*/
                 NvMStateMachine.DFlashEraseStartTime = SystemTickMs;
                 NvMStateMachine.DFlashEraseTimeOut =  MAX_DFLASH_ERASE_TIME;
             }
         }

    }
    else
    {
        /*DFLASH being erased, wait DFLASH return to idle*/
        if (FLASH_EE_IDLE == FLASH_EE_CheckBusy())
        {
            DFlashRWStatus = DFlashRWStatus &(~DFLASH_ERASING);    /*clear the erasing flag*/
            /*there is APP DFLASH writing request*/
            if((DFlashRWStatus & DFLASH_WRITE_APP_HIST) == DFLASH_WRITE_APP_HIST)
            {
                FLASH_EE_EraseEnd(APP_DATA_DFLASH_ADDR_TBL[HIST_DATA_INDEX], 0x4000);
                NvMAppDataSaveToDFlash(HIST_DATA_INDEX);
            }
            /*there is APP DFLASH writing request*/
            else  if((DFlashRWStatus & DFLASH_WRITE_APP_ENM) == DFLASH_WRITE_APP_ENM)
            {
                FLASH_EE_EraseEnd(APP_DATA_DFLASH_ADDR_TBL[ENM_DATA_INDEX], 0x4000);
                NvMAppDataSaveToDFlash(ENM_DATA_INDEX);
            }
            /*there is DID DFLASH writing request, write DID data*/
            else if((DFlashRWStatus & DFLASH_WRITE_DID) == DFLASH_WRITE_DID)
            {
                FLASH_EE_EraseEnd(DID_DATA_START_ADDR, 0x4000);
                if(WAKEUPSRC_UNKNOWN != bswWakeSrc)
                {
                    Write_DIDFromRAM();
                }
            }
            /*there is writing external program  request flag*/
            else if((DFlashRWStatus & DFLASH_WRITE_EXT_PROG) == DFLASH_WRITE_EXT_PROG)
            {
                FLASH_EE_EraseEnd(BOOT_VERSION_ADDR, 0x4000);
                FLASH_EE_Write8(BOOT_VERSION_ADDR,  sizeof(BootHeadTbl),  BootHeadTbl);
                DFlashRWStatus = DFlashRWStatus & (~DFLASH_WRITE_EXT_PROG);  /*clear  external program flag writing request*/
            }
            /*there is DTC DFLASH writing request, write DTCInfoTbl*/
            else if((DFlashRWStatus & DFLASH_WRITE_DTC) == DFLASH_WRITE_DTC)
            {
                FLASH_EE_EraseEnd(DTCINFO_DFLASH_ADDR, 0x4000);
                if(WAKEUPSRC_UNKNOWN != bswWakeSrc)
                {
                    NvMDTC_SaveToDFlash();
                }
            }

        }
        else
        {
             /*time out , give up the DFLASH writing operation, force DFLASH exit from erasing state*/
             if((SystemTickMs > NvMStateMachine.DFlashEraseStartTime) && ((SystemTickMs -NvMStateMachine.DFlashEraseStartTime) > NvMStateMachine.DFlashEraseTimeOut))
             {
                 DFlashRWStatus = DFlashRWStatus &(~DFLASH_ERASING);    /*clear the erasing flag*/

                 /*there is APP DFLASH writing request stop erasing the block*/
                 if((DFlashRWStatus & DFLASH_WRITE_APP_HIST) == DFLASH_WRITE_APP_HIST)
                 {
                     FLASH_EE_EraseEnd(APP_DATA_DFLASH_ADDR_TBL[HIST_DATA_INDEX], 0x4000);
                 }
                 /*there is APP DFLASH writing request stop erasing the block*/
                 else if((DFlashRWStatus & DFLASH_WRITE_APP_ENM) == DFLASH_WRITE_APP_ENM)
                 {
                     FLASH_EE_EraseEnd(APP_DATA_DFLASH_ADDR_TBL[ENM_DATA_INDEX], 0x4000);
                 }
                 /*there is DTC DFLASH writing request, stop erasing the block*/
                 else if((DFlashRWStatus & DFLASH_WRITE_DTC) == DFLASH_WRITE_DTC)
                 {
                     FLASH_EE_EraseEnd(DTCINFO_DFLASH_ADDR, 0x4000);
                 }
                 /*there is writing external program flag request*/
                 else if((DFlashRWStatus & DFLASH_WRITE_EXT_PROG) == DFLASH_WRITE_EXT_PROG)
                 {
                     FLASH_EE_EraseEnd(BOOT_VERSION_ADDR, 0x4000);
                 }   

                 /*there is DID DFLASH writing request,stop erasing the block*/
                 else if((DFlashRWStatus & DFLASH_WRITE_DID) == DFLASH_WRITE_DID)
                 {
                     FLASH_EE_EraseEnd(DID_DATA_START_ADDR, 0x4000);
                 }    
 
                 
            }
          
        }
    }
}
 
/***************************************************************************************************************
 * Name:        NVM_Task
 * Function:    
 *              1. check the pre-sleep condition
 *              1. call the application cyclic task handler: load application data; save application data at correct time
 * Input:        null
 * Return:        null
 * Link:        
 * Attention:    
 ************************************************************************************************************* */
 void NvM_Task(void)
{
    uint32_t appEepromFinished;
    NVM_CheckCal();     /*in fact, this function is executed only once */
    /*in intializing phase, DTC */
    if(NVM_INITING == NvMStateMachine.currState)
    {
        NvM_DTC_LoadTask();             /*read DTC from EEPROM is synch operation*/
        appEepromFinished = NvMAppData_LoadTask();       /*load App data from EEPROM at initialzing phase*/
        /*all App data EEPROM loaded, */
        if(TRUE == appEepromFinished)
        {
           /*there is request to backup data from DFLASH to EEPROM, switch to backing*/
            if(TRUE == NvMAppData_NeedBackToEEPROM())
            {
                NvMStateMachine.currState = NVM_BACKUP;
            }
            else
            {
                NvMStateMachine.currState = NVM_RUNNING;
            }
        }
    }
    else if(NVM_BACKUP == NvMStateMachine.currState)
    {
        NvM_DTC_LoadTask();             /*read DTC from EEPROM is synch operation*/

        /*back up app data to EEPROM finished? switch to running state*/
        appEepromFinished = NVM_AppData_SaveTask();
        if(TRUE == appEepromFinished)
        {
           NvMStateMachine.currState = NVM_RUNNING;
        }
    }    
    else if(NVM_RUNNING == NvMStateMachine.currState)
    {
        NvM_DTC_LoadTask();             /*read DTC from EEPROM is synch operation*/
        NvMDTC_SaveTask();     /*EEPROM is exclusively used by DTC sub-module in running phase*/
        CheckSleepFallingEdge();         
        /*in Running phase,store PMM's active flag to NVM internally*/
      //@@@@  NvMStateMachine.prevPMMActiveFlag = PMM_output.VPMM_InternalSleepActive_flg;
    }
    else if (NVM_PRESLEEP == NvMStateMachine.currState)
    {
        if (NvMDataSaving == NvMAppDataSaveLoadFlag)
        {
            (void)NVM_AppData_SaveTask();  /*EEPROM is exclusively used by app data sub-module in pre-sleep phase*/
        }
        CheckSleepRisingEdge();
    }
    /*update the PMM active flag stored in NVM*/
    NvMStateMachine.prevPMMActiveFlag = PMM_output.VPMM_InternalSleepActive_flg;
    NvMStateMachine.prevBTKSleepFlag = VBTK_SleepAllw_flg;

    NvM_DFlashWriteTask();

    gblNVMStateMachineSts = NvMStateMachine.currState;
}



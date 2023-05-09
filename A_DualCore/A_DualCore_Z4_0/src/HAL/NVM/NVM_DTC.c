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
#include "flash.h"
#include "uds_service.h"
#include "Global.h"
#include "M95128.h"
#include "DHP_model.h"
#include "CAN_DBC_Lib.h"
#include "Ex_Data.h"
#include "HALI_Model.h"
#include "PEPS_Model.h"
/* =================  Private Constant Declarations =========================*/
#define MAX_DTC_NUM   250              /*maximum  250  DTC supported*/
#define SECA_FAILURE_RD_LEN  8   /*security Acess failure record len = 8  4 byte for timer,  1 byte for failure counter 3 byte reserved*/


#define AGING_COUNTER_POS    1   /*ageing counter is the No.1 byte in EEPROM page*/

#define COLLISION_DTC_INDEX  27
#define MAX_DTC_OCCURANCE 0xFF
#define MAX_DTC_AGINGCNT 0xFF
#define MAX_FAILED_DTC_SAVING  5
#define DTC_RAM_ADDR (uint32_t)(&Fault_storage_array[0])
#define DTC_RAM_TABLE Fault_storage_array

/*external DTC valid flag*/
const uint8_t EXT_DTC_VALID[FLAG_SIZE] = {0x20, 0x18, 0x10, 0x30, 0x14, 0x05, 0x20, 0x29};

#define IGBT_DTC_INDEX   56       /*IGBT historical fault */

/* =================  Private Variable Declarations =========================*/
//@@@@CORE0_INIT  boolean ExtDTCFlagValid;
/*DTC information table in RAM: last 64 bytes is the extended data for Auth failed DTC P10D996 (bug 1519)*/
#define DTCINFO_LEN  (MAX_DTC_NUM + MAX_DTC_NUM + SECA_FAILURE_RD_LEN + APP_CRC_SIZE)
CORE0_INIT uint8_t DTCInfoTbl[MAX_DTC_NUM + MAX_DTC_NUM + SECA_FAILURE_RD_LEN + APP_CRC_SIZE + AUTHFALIED_DATA_SIZE];

CORE0_INIT uint8_t MirrorDTCOccuranceTbl[UDS_SP_DTC_NUM] = {0};  /*DTC occurance table in RAM , read from EEPROM while start-up*/
CORE0_INIT uint16_t readDTCInfoNum = 0;   /*how many DTCs have been read out for the information*/
CORE0_INIT uint8_t DTCReadFailCnt = 0;
CORE0_INIT uint8_t DTCSaveFailCnt = 0;
CORE0_INIT uint8_t  bDTCToCanNum = 0;
CORE0_INIT uint16_t CheckedDTCRdInRAM = 0;
//@@@@CORE0_INIT uint8_t  DFlashRWStatus;     /*the DTC DFLASH block status */
/*reason to add confirmedDTCTbl: if confirmed DTC is more than DTC_NUM_IN_RAM, table Fault_storage_array and DTCStatusRAMTbl will be re-initialized*/
CORE0_INIT uint8_t   confirmedDTCTbl[UDS_SP_DTC_NUM] = {0};  /*1: 序号代表的DTC本上电周期确认过; 0 没有*/

CORE0_INIT uint8_t seriousHistFaultFlag = 0;  /*serious DTC fault, can not go to HV state*/
CORE0_INIT boolean secAFailedRecordsSaved = 0;   /*TRUE: the security Access records should be saved, FALSE: not saved.*/
CORE0_INIT uint8_t  IGBTFaultFromMCU = 0;      /*there is a IGBT fault reported by MCU. used by DHP to notify if MCU reported IGBT fault in current cycle*/
CORE0_INIT boolean ClearingDTCFromUDS = 0;
/* =================  Private function Declarations =========================*/
boolean CheckOneDTCRecordInRAM(void);
uint8_t SaveDTCToEEPROM(uint8_t DTCIdx, uint8_t RamRdIdx);
boolean ChkDid_VehState_IsValid(uint8_t  VehState);   /*check the DID 0A00 vehicle state is in valid range*/
/* =================  private funciton implementation =========================*/
/*---------------------------------------------------------------------------
description: this function check if there is serious history fault in EEPROM (only IGBT falut until 2019 04 08)
input param:         void
output param:    seriousHistFaultFlag
return:            void
---------------------------------------------------------------------------*/
#if 0 //bug 1508: delete the IGBT historical fault checking
void CheckSeriousHistoryFault (void)
{
    uint16_t  IgbtFltPos;
    seriousHistFaultFlag = 0;
    IgbtFltPos = IGBT_DTC_INDEX -1;/*IGBT faut index is 56 (counting from 1), so minus 1*/
    IgbtFltPos = IgbtFltPos << 1;  /*mutple with 2, is the occurance of IGBT fault*/
    if(DTCInfoTbl[IgbtFltPos] > 0)   
    {
        seriousHistFaultFlag = 1;
    }
}
#endif
/*---------------------------------------------------------------------------
description: this function update the aging counter in DTC info table based on occurance
input param:       DTCInfoTbl
output param:     DTCInfoTbl,currDFlashRWStatus
return:            void
---------------------------------------------------------------------------*/
void NvMUpdateAgingCounter(uint16_t DTCIdx)
{
    uint16_t rdIndex;
    rdIndex = DTCIdx << 1;
    MirrorDTCOccuranceTbl[DTCIdx] = DTCInfoTbl[rdIndex] ;
    if(DTCInfoTbl[rdIndex] > 0)
    {
        /*increase the aging counter*/
        if(DTCInfoTbl[rdIndex + 1] < MAX_DTC_AGINGCNT)
        {
            DTCInfoTbl[rdIndex + 1] ++;
            /*CR 1088: ageing counter > threshold , and not collision DTC, clear the DTC snapshot*/
            /*calibration KNVM_SelfClrCycle is 0, the self DTC clearing feature is disabled*/
            if((DTCInfoTbl[rdIndex + 1] > KNVM_SelfClrCycle) && (KNVM_SelfClrCycle > 0) && (DTCIdx != (COLLISION_DTC_INDEX -1)))
            {
                DTCInfoTbl[rdIndex] = 0;         /*clear DTC occurance to 0*/
                DTCInfoTbl[rdIndex + 1] = 0;  /*aging counter cleared to 0*/
                DFlashRWStatus = DFlashRWStatus | DFLASH_WRITE_DTC;   /*set on the DTC DFLASH writing request*/
            }
        }
    }

}


/*---------------------------------------------------------------------------
description: DTC snapshot record are stored in Fault_storage_array, there are 20 records, 
DHP module save confirmed DTC snapshot in accesending order into the array.
this function check the Fault_storage_array, if new confirmed DTC found, save into EEPROM
input param:        CheckedDTCRdInRAM -- how many DTC RAM record checked.
output param:     NONE
return:            FALSE: no new  DTC found,  TRUE-  new DTC found and saved
---------------------------------------------------------------------------*/
boolean CheckOneDTCRecordInRAM(void)
{
    int index;
    boolean bDTCFound;
    uint8_t progRslt;
    uint8_t DTCIdx;

    bDTCFound = FALSE;
    /*all DTC RAM records checked, don't check again*/
    if(CheckedDTCRdInRAM >= DTC_NUM_IN_RAM)
    {
        return bDTCFound;
    }

    index = (uint16_t)(CheckedDTCRdInRAM*DTC_SNAP_LEN);
    /*in DTC RAM table written by DHP module, DTC index start from 1*/
    /*DTC index is not 0, means there is a failed DTC*/
    if(Fault_storage_array[index] > 0)
    {
        bDTCFound  = TRUE;
        DTCIdx = Fault_storage_array[index];
        DtcToCAN[CheckedDTCRdInRAM] = Fault_storage_array[index];
        /*update the confirmed DTC table*/
        confirmedDTCTbl[DTCIdx -1] = 1; /*in fault_storage_array, DTC index start from 1, so minus 1*/

        progRslt = SaveDTCToEEPROM((DTCIdx -1), CheckedDTCRdInRAM);  /*VCU2.0 bug 1508*/

        /*only save operation succeed, move to next DTC RAM record. or try to save it next 50ms task*/
        if(EXTEE_OK == progRslt)
        {
            CheckedDTCRdInRAM++;
        }
        /*failed too much times, give up the operation*/
        else
        {
            DTCSaveFailCnt ++;
            if(DTCSaveFailCnt > MAX_FAILED_DTC_SAVING)
            {
                DTCSaveFailCnt = 0;
                CheckedDTCRdInRAM++;
            }
        }    
    }
    return bDTCFound;
}
/*---------------------------------------------------------------------------
description: copy input and output variables for PEPS module for auth failed DTC 
input param:         refer to the code
output param:     void
return:            void
---------------------------------------------------------------------------*/
void BackUpAuthFailedData(void)
{
   (void)memcpy(&DTCInfoTbl[DTCINFO_LEN], AuthFailedData, sizeof(AuthFailedData));
}
/*---------------------------------------------------------------------------
description: this function update DTC records(DTC occurance +aging counter +snapshot record) into EEPROM, 
the works are:
1)if there is latest DTC record for this DTC and the historical slot is empty, move lastest record to history record slot
2)replace latest DTC record slot with the record in RAM
input param:         DTCIdx -- DTC  index
input param:         RamRdIdx -- RAM record index
output param:     void
return:            result -- EEPROM operation result
---------------------------------------------------------------------------*/
uint8_t SaveDTCToEEPROM(uint8_t DTCIdx, uint8_t RamRdIdx)
{
    uint32_t ExtEEAddr;
     uint16_t index;

    uint8_t ExtEEDTCRd[EXTEE_PAGE_SIZE];
    uint8_t extEERslt;
    //uint32_t odometer;
    
    /*not found, return directly*/
    if( (DTCIdx >= UDS_SP_DTC_NUM) || (RamRdIdx >= DTC_NUM_IN_RAM) )
    {
        return EXTEE_OUTRANGE;
    }

    /*clear the whole buffer*/
    (void)memset(ExtEEDTCRd, 0, sizeof(ExtEEDTCRd));
    /*copy DTC information from RAM */
    index  = RamRdIdx * (DTC_SNAP_LEN); 
    memcpy(&ExtEEDTCRd[1], &DTC_RAM_TABLE[index], DTC_SNAP_LEN);

    /*clear the DTC aging counter in RAM table*/
    index = DTCIdx << 1;
    DTCInfoTbl[index + 1] = 0;
    /*increase the DTC occurance*/
    if(DTCInfoTbl[index] < MAX_DTC_OCCURANCE)
    { 
        DTCInfoTbl[index]++;
    }
    /*for bug 1519: copy extended data for  Auth failed DTC = P10D996*/
    if(AUTH_FAILED_DTC_INDEX == DTCIdx)
    {
        BackUpAuthFailedData();
        /*save Auth failed DTC extended data to EEPROM*/
    }
    DFlashRWStatus = DFlashRWStatus |DFLASH_WRITE_DTC;   /*set on the DTC DFLASH writing request*/

    /*prepare DTC extended data + snapshot to be written into EEPROM*/
    /* first byte is DTC occurance*/
    ExtEEDTCRd[0] = DTCInfoTbl[DTCIdx];      
    /* set  aging counter to 0*/
    ExtEEDTCRd[AGING_COUNTER_POS] = 0;      
    /*write into EEPROM*/
    ExtEEAddr = EXT_DTC_START_ADDR + DTCIdx * EXTEE_PAGE_SIZE * UDS_HISTO_SNAP_NUM;
    extEERslt = WriteExtEE(ExtEEAddr, EXTEE_PAGE_SIZE, ExtEEDTCRd);    

    return extEERslt;   
}

/* =============================  public funciton implementation ==================================*/

/***************************************************************************************************************
 description:  read DTC valid flag in external EEPROM
 input param:       
 output param:     ExtDTCFlagValid
 return:            none
 ************************************************************************************************************* */
 void NVM_DTC_Init(void)
 {
    int i;
    uint32_t storedCrc;   /*CRC stored in NVM*/
    uint32_t  calcedCrc;  /*CRC calculated based on data*/

    /*reset the global variables*/
    ClearingDTCFromUDS = FALSE;
    CheckedDTCRdInRAM = 0;
    (void)memset(DTCStatusRAMTbl, 0, sizeof(DTCStatusRAMTbl));
    (void)memset(confirmedDTCTbl, 0, sizeof(confirmedDTCTbl));
    (void)memset(MirrorDTCOccuranceTbl, 0, sizeof(MirrorDTCOccuranceTbl));
    
    /*read DTC information table from DFLASH*/
    (void)memset(DTCInfoTbl, 0, sizeof(DTCInfoTbl));
    (void)FLASH_EE_Read8(DTCINFO_DFLASH_ADDR, sizeof(DTCInfoTbl), DTCInfoTbl);
    /*check the CRC*/
    calcedCrc = CalcCrc32(DTCInfoTbl, (DTCINFO_LEN - APP_CRC_SIZE)); 
    /*parse out the stored CRC*/
    storedCrc = 0;
    for(i = 0; i < APP_CRC_SIZE; i++)
    {
        storedCrc = storedCrc << 8;
        storedCrc = storedCrc + (uint32_t)DTCInfoTbl[DTCINFO_LEN - APP_CRC_SIZE + i];
    }

    /*DTC information table readout */
    if(storedCrc == calcedCrc)
    {
        readDTCInfoNum = MAX_DTC_NUM;
        /*check the DTC occurance , update aging counter*/
        for(i = 0; i < UDS_SP_DTC_NUM; i++)
        {
            NvMUpdateAgingCounter(i);
        }
    }
    else
    { 
       /*CRC checking of DTC info in DFLASH failed, try to read DTC info from EEPROM*/
       (void)memset(DTCInfoTbl, 0, DTCINFO_LEN);
       readDTCInfoNum  = 0;   
    }

 }

/*---------------------------------------------------------------------------
description: this function read DTC occurance and ageing counter from EEPROM for one DTC
input param:       readDTCInfoNum
output param:     MirroredDTCOccuranceNum
return:            void
---------------------------------------------------------------------------*/
void NvM_DTC_LoadTask(void)
{
#define MAX_READ_DTC_FAILURE  5 
    uint32_t extEERslt = EXTEE_OK;
    uint16_t extEEAddr = 0;
    uint16_t dtcRdIndex;
    uint8_t extEEData[MIN_EXEEE_RW_SIZE];

    if(readDTCInfoNum >= UDS_SP_DTC_NUM)
    {
        return;
    }
    /*read DTC occurance  and aging counter*/
    extEEAddr = EXTEE_PAGE_SIZE *(readDTCInfoNum +1);
    extEERslt = ReadExtEE(extEEAddr, sizeof(extEEData), extEEData);
    /*update the corresponding byte in DTC info table*/
    if(EXTEE_OK == extEERslt)
    {
        /*byte #2 in EEPROM is vehicle state, only vehicle state is correct, can the snapshot be treated as valid snapshot*/
        if(TRUE == ChkDid_VehState_IsValid(extEEData[2]))
        {
            dtcRdIndex = readDTCInfoNum << 1;   /*2 bytes for each DTC records */
            DTCInfoTbl[dtcRdIndex] = extEEData[0];  /*DTC occurance*/
            DTCInfoTbl[dtcRdIndex + 1] =  extEEData[AGING_COUNTER_POS];  /*aging counter*/
            NvMUpdateAgingCounter(readDTCInfoNum);
            /**/
            readDTCInfoNum ++;
            DTCReadFailCnt = 0;
        }
    }
    else
    {
        DTCReadFailCnt++;
        if(DTCReadFailCnt > MAX_READ_DTC_FAILURE)
        {
            readDTCInfoNum ++;
        }        
    }

#undef  MAX_READ_DTC_FAILURE
}
/*---------------------------------------------------------------------------
description: this function check a RAM DTC , if found a new DTC record, save to EEPROM
input param:       
output param:     
return:            void
---------------------------------------------------------------------------*/
void NvMDTC_SaveTask(void)
{
    if(CheckedDTCRdInRAM < DTC_NUM_IN_RAM)
    {
        CheckOneDTCRecordInRAM();
    }
}
/*---------------------------------------------------------------------------
description: 1 change current DTC in confirmedDTCTbl to historical DTC (in MirrorDTCOccuranceTbl)
2 reset the DTC RAM tables : Fault_storage_array, DTCStatusRAMTbl, DtcToCAN and confirmedDTCTbl
input param:       
output param:     
return:            void
---------------------------------------------------------------------------*/
void NvMReset_DTCStorage(void)
{
   uint16_t i;

    /*change current DTC in confirmedDTCTbl to historical DTC (in MirrorDTCOccuranceTbl)*/
    for(i = 0; i < UDS_SP_DTC_NUM; i++)
    {
        if((confirmedDTCTbl[i] > 0) && (MirrorDTCOccuranceTbl[i] < MAX_DTC_OCCURANCE))
        {
            MirrorDTCOccuranceTbl[i] ++;
        }
    }

    /*clear the DTC RAM tables*/
    memset(Fault_storage_array, 0, sizeof(Fault_storage_array));
    (void)memset(DTCStatusRAMTbl, 0, sizeof(DTCStatusRAMTbl));    
    (void)memset(DtcToCAN, 0, sizeof(DtcToCAN));
    (void)memset(confirmedDTCTbl, 0, sizeof(confirmedDTCTbl));    
    CheckedDTCRdInRAM = 0;
}
/*---------------------------------------------------------------------------
description: this function create CRC for the DTCInfoTbl, save to DFlash
input param:       DTCInfoTbl
output param:     DFlashRWStatus
return:            void
---------------------------------------------------------------------------*/
void NvMDTC_SaveToDFlash(void)
{
    uint32_t crc;

    crc = CalcCrc32(DTCInfoTbl, (uint16_t)(DTCINFO_LEN- APP_CRC_SIZE));
    (void)memcpy(&DTCInfoTbl[(uint16_t)(DTCINFO_LEN - APP_CRC_SIZE)], (void*)&crc, sizeof(crc));
    FLASH_EE_Write8(DTCINFO_DFLASH_ADDR,  sizeof(DTCInfoTbl),  DTCInfoTbl);

    DFlashRWStatus = DFlashRWStatus & (~DFLASH_WRITE_DTC);  /*clear DTC DFLASH writing request*/
}
/***************************************************************************************************************
 description: read DTC status according to its DTC from RAM or EEPROM 
 input param:         index -- DTC record index
 output param:     statusTbl -- includeng current DTC status + occurance and 2 historical DTC status + occurance
 return:            result --  operation result
 ************************************************************************************************************* */
usResultType usReadDTCStaus(uint16_t DTCIdx, uint8_t  statusTbl[])
{
    usResultType result = US_OK;
    uint16_t i;
    uint8_t occurance = 0;
    uint8_t tempDTCIdx;
    uint16_t index;
    uint8_t * pDTCRAMAddr;

    
    /*search current falied DTC in fault_storage_array*/
    for(i = 0; i < DTC_NUM_IN_RAM; i++)
    {
        index = i * (DTC_SNAP_LEN);
        pDTCRAMAddr = (uint8_t*)((uint32_t)DTC_RAM_ADDR + index);
        tempDTCIdx = *pDTCRAMAddr;
        /*in DTC RAM table, DHP set the DTC index from 1*/
        if((DTCIdx+1) == (uint16_t)tempDTCIdx)
        {
            statusTbl[0] = 0x22;
        }
    }
    /*search the DTC in confirmed DTC table */
    if(confirmedDTCTbl[DTCIdx] >= 1)
    {
        statusTbl[0] = 0x22;
    }
    /*check the current DTC status table*/
    if(1 == DTCStatusRAMTbl[DTCIdx])
    {
        statusTbl[0] = 0x23; 
    }
    /*not found in DHP RAM table, search in EEP Mirror table*/
    /*calculate the position of specified DTC status byte*/
    /*latest snapshot occurance*/
    occurance = MirrorDTCOccuranceTbl[DTCIdx];
    if(occurance > 0)
    {
        statusTbl[1] = HIST_DTC_STATUS;              /*historically failed DTC*/
    }    
        
    return US_OK;

    return result;
}
/*---------------------------------------------------------------------------
description: read DTC snapshot record indentifier from RAM and EEPROM if its status > 0 
  (including bit 0 bit 3 or bit 5 is 1)
input param:    DTC -- DTC code
input param:    index -- index of the DTC
output param:  idTbl[] -- store the snapshot record indentifier
return:             snapshot record amount: 0 no confirmed  snapshot for this DTC
---------------------------------------------------------------------------*/
uint8_t  usReadFailedDTCSnapId(uint32_t DTC, uint16_t DTCIdx, uint8_t idTbl[])
{
    uint8_t amount = 0;
    uint8_t occurance;
    uint16_t i,  index;
    uint8_t tempDTCIdx;

    /*init status: there is no snapshot record for this  DTC in RAM and EEPROM*/
    amount = 0;
    /*step 1:  search confirmed DTC  in DHP DTC RAM table . it is a dynamic table, first byte is DTC index*/
    for(i = 0; i < DTC_NUM_IN_RAM; i ++)
    {
        index = i*(DTC_SNAP_LEN);
        tempDTCIdx = DTC_RAM_TABLE[index];
        /*in DTC RAM table, DHP set the DTC index from 1*/
        if((DTCIdx+1) == (uint16_t)tempDTCIdx)
        {
            idTbl[amount] = 0;
            amount ++;
            break;
        }
    }
    /*step2: check historical  occurance  in  Mirrored Status table */
    occurance = MirrorDTCOccuranceTbl[DTCIdx];
    if(occurance > 0)
    {
        idTbl[amount] = 1;
        amount ++;
    }
    return amount;
}

/*---------------------------------------------------------------------------
description: read  DTC snapshot record (freezeFrame)from RAM or  EEPROM, we believe the snapshot identifier is in valid range
input param:    DTC -- DTC code
input param:    SnapRdId -- snapshot identifier (according to ISO 14229 must start from 1)
output param:  freezeFrame[] -- store the snapshot record (freezeframe)
return:             US_FAILED not found; US_OK read out
---------------------------------------------------------------------------*/
usResultType  usReadSnapshotRecord(uint8_t DTCIdx, uint8_t SnapRdId, uint8_t freezeFrame[])
{
    usResultType result;
    uint32_t ExtEEAddr;
    uint32_t ramDTCAddr;
    uint16_t index, i;
    result = US_FAILED;
    
    /*check if the snapshot identifier is the current snapshot record, criteria: snapshot id is 0*/
    if(1 == SnapRdId)
    {
         for(i = 0; i < DTC_NUM_IN_RAM; i ++)
         {
             index = (uint16_t)(i*DTC_SNAP_LEN);
             /*in DTC RAM table, DHP set the DTC index from 1*/
             if((DTCIdx+1) == DTC_RAM_TABLE[index])
             {
                 ramDTCAddr = DTC_RAM_ADDR + index + 1;  /*IN RAM first byte is DTC index so, increase by 1*/
                 (void)memcpy(freezeFrame, (uint8_t*)ramDTCAddr, DTC_SNAP_LEN);
                 result = US_OK;
                 break;
             }
        }
        
    }   
    /* read the latest hisotorical snapshot record*/
    else if (UDS_SNAP_NUM_PER_DTC == SnapRdId)
    {
        /*latest historical snapshot*/
        ExtEEAddr = EXT_DTC_START_ADDR + (DTCIdx*EXTEE_PAGE_SIZE*UDS_HISTO_SNAP_NUM);
        /*in EEPROM byte 0 is occurance, byte 1 is aging counter, so in crease by 2*/
        ExtEEAddr = ExtEEAddr + 2;
        result = ReadExtEE(ExtEEAddr, DTC_SNAP_LEN, freezeFrame);
    }
    return result;
}
/*---------------------------------------------------------------------------
description: read  DTC occureance
input param:    DTC -- DTC code
input param:    extended record number -- according to ISO 14229 must start from 1
output param:  void
return:             DTC occurance (operation cycle)
---------------------------------------------------------------------------*/
uint8_t  usReadDTCOccurance(uint8_t DTCIdx, uint8_t SnapRdId)
{
    uint16_t index, i;
    uint8_t DTCOccurance = 0;
    
     for(i = 0; i < DTC_NUM_IN_RAM; i ++)
     {
         index = (uint16_t)(i*DTC_SNAP_LEN);
         /*in DTC RAM table, DHP set the DTC index from 1*/
         if((DTCIdx+1) == DTC_RAM_TABLE[index])
         {
             DTCOccurance = 1;
             break;
         }
    }    

    /*check the  occurance from MirrorTable*/
    if(MirrorDTCOccuranceTbl[DTCIdx] == MAX_DTC_OCCURANCE)
    {
       DTCOccurance = MAX_DTC_OCCURANCE;
    }
    if( (MirrorDTCOccuranceTbl[DTCIdx] >0) && (MirrorDTCOccuranceTbl[DTCIdx] < MAX_DTC_OCCURANCE) )
    {
       DTCOccurance = DTCOccurance + MirrorDTCOccuranceTbl[DTCIdx] ;
    }
    return DTCOccurance;
}
/*---------------------------------------------------------------------------
description: read  DTC aging counter
input param:    DTC -- DTC code
input param:    extended record number -- for aging counter , record id must be 2
output param:  void
return:             DTC occurance (operation cycle)
---------------------------------------------------------------------------*/
uint8_t  usReadDTCAgingCounter(uint8_t DTCIdx, uint8_t SnapRdId)
{
    uint8_t DTCAgeingCounter;
    uint16_t index;

    index = DTCIdx << 1;   /*calculate aging counter position*/
    DTCAgeingCounter= DTCInfoTbl[index +  1];
    
    return DTCAgeingCounter;
}

/*---------------------------------------------------------------------------
description: clear DTC records in RAM
input param:      void
output param:    void
return:            result --  operation result
---------------------------------------------------------------------------*/
usResultType usClearRAMDTC(void)
{
    usResultType result = US_OK;

    /*clear the relevant tables*/
    (void)memset(Fault_storage_array, 0, sizeof(Fault_storage_array));
    (void)memset(DTCStatusRAMTbl, 0, sizeof(DTCStatusRAMTbl));    
    (void)memset(confirmedDTCTbl, 0, sizeof(confirmedDTCTbl));    
    (void)memset(DtcToCAN, 0, sizeof(DtcToCAN));

    /*clear the DTC info table*/
    (void)memset(DTCInfoTbl, 0, DTCINFO_LEN);
    /*clear the DTC occurance table*/
    (void)memset(MirrorDTCOccuranceTbl, 0, sizeof(MirrorDTCOccuranceTbl));
    
    DFlashRWStatus = DFlashRWStatus | DFLASH_WRITE_DTC;   /*set on the DTC DFLASH writing request*/

    /*clear the serious historical fault flag and DTC checking counter*/
    CheckedDTCRdInRAM = 0;
    seriousHistFaultFlag = 0;

    /*temporary solution before DHP moved to Core 0, clear DTC information if $14 command received from Core 0*/
    currClrDTCCmdFromCore0 = 1; /*notify Core 1 to clear the DTC storage tables: Fault_storage_array and DTCStatusRAMTbl*/
    /*temporary solution before DHP moved to Core 0, clear DTC information if $14 command received from Core 0*/

    ClearingDTCFromUDS = TRUE;   /*DTC is being cleared by UDS command*/
    return result;
}
/*---------------------------------------------------------------------------
description: clear DTC by UDS command finished, reset flag ClearingDTCFromUDS
input param:      void
output param:    void
return:            result --  operation result
---------------------------------------------------------------------------*/
void usClearDTCFinished(void)
{
    ClearingDTCFromUDS = FALSE;   /*UDS command Clearing DTC finished, reset the flag*/
}

/*---------------------------------------------------------------------------
description: clear DTC records in RAM
input param:      void
output param:    void
return:            result --  operation result
---------------------------------------------------------------------------*/
usResultType usClearEEPROMDTC (uint32_t DTC, uint16_t DTCIdx, uint8_t status)
{
    usResultType result = US_OK;
    uint16_t ExtEEAddr;
    uint8_t ExtEEDTCRd[EXTEE_PAGE_SIZE];
    uint8_t extEERslt;

    /*update external EEPROM DTC records*/
    ExtEEAddr = EXT_DTC_START_ADDR + DTCIdx*EXTEE_PAGE_SIZE;
    /*read out current DTC snapshot , first byte is occurance*/
    extEERslt = ReadExtEE(ExtEEAddr, (uint16_t)sizeof(ExtEEDTCRd), ExtEEDTCRd);
    if(EXTEE_OK != extEERslt)
    {
       result = US_BUSY;
    }
    //the DTC page be cleared only when the occurange is not 0. 
    if((ExtEEDTCRd[0] > 0) && (EXTEE_OK == extEERslt))
    {           
            memset(ExtEEDTCRd, 0, sizeof(ExtEEDTCRd));
            extEERslt = WriteExtEE(ExtEEAddr,  (uint16_t)sizeof(ExtEEDTCRd), ExtEEDTCRd);
            if(EXTEE_BUSY == extEERslt)
            {
                result = US_BUSY;
            }
            if(EXTEE_OUTRANGE == extEERslt)
            {
                result = US_FAILED;
            }
            if(EXTEE_OK == extEERslt)
            {
                result = US_OK;
            }
    }
    return result;
}
/*---------------------------------------------------------------------------
description: this function clear the security access failure records in EEPROM page SECA_FAILED_TIMER_PAGE
only when the failed counter > 0 or the delay timer > 0, can we
input param:       none
output param:     none
return:        void
---------------------------------------------------------------------------*/
boolean ChkDid_VehState_IsValid(uint8_t  VehState)
{
#define MAX_VEHSTATE  7 /*according to DID list, max value of vehicle state is 7*/
    boolean isValid = TRUE; 
    if(VehState > MAX_VEHSTATE)
    {
        isValid = FALSE;
    }
    return isValid;
}
/*---------------------------------------------------------------------------
description: this function read the Security Access failed timer and failed counter stored in External EEPROM
The function reads the data stored in EEPROM page 170, first 4 bytes are delay timer, #4 byte is failed counter
if the data is all 0xFF, it means the VCU is first time power on, set the delay timer and failed counter to 0
input param:       none
output param:     pFailedCnt -- pointer of the failed counter
return:        void
---------------------------------------------------------------------------*/
uint32_t NVM_ReadSecAFailedCounterAndTimer(uint8_t * pFailedCnt)
{
    uint32_t SecAFailedTimer;
    int i;

    SecAFailedTimer = 0;

    for(i = 0; i < sizeof(SecAFailedTimer); i++)
    {
        SecAFailedTimer =  SecAFailedTimer << 8;
        SecAFailedTimer = SecAFailedTimer + DTCInfoTbl[2*MAX_DTC_NUM + i];
    }

    /*0xFF means the first time powe-on, delay timer should be set to 0*/
    if(0xFFFFFFFF == SecAFailedTimer)
    {
        SecAFailedTimer = 0;
    }
    
    *pFailedCnt = DTCInfoTbl[2*MAX_DTC_NUM + sizeof(SecAFailedTimer)];
    /*if the delay timer > 0 or failed counter > 0 (read from DFLASH), clear the record in DTCInfoTbl*/
    if( (SecAFailedTimer > 0) || (*pFailedCnt > 0) )
    {
        for(i = 0; i < 2*sizeof(SecAFailedTimer); i++)
        {
            DTCInfoTbl[2*MAX_DTC_NUM +i] = 0;
        }
        DFlashRWStatus = DFlashRWStatus |DFLASH_WRITE_DTC;   /*set on the DTC DFLASH writing request*/
    }
    
    return SecAFailedTimer;
}

/*---------------------------------------------------------------------------
description: this function save the Security Access failed delay timer and failed counter stored to External EEPROM
only when the failed counter > 0 or the delay timer > 0, can we
input param:       none
output param:     none
return:        void
---------------------------------------------------------------------------*/
void NVM_SaveSecAFailedCounterAndTimer(void)
{
    uint32_t remainDelayTimer;
    /*security Access failed timer (start tick) is NOT 0 or  failed counter is NOT 0, save to EEPROM , 
    or return directly , this solution can  save EEPROM lifecycle and power-off time*/
    if( (udsSecAFailedDelayTimer > 0) || (udsSecAFailedCount > 0) )
    {
        if(udsSecAFailedDelayTimer > 0)
        {
            /*calculate the remianing delay time*/
            remainDelayTimer = SystemTickMs - udsSecAFailedTick;
            remainDelayTimer = udsSecAFailedDelayTimer - remainDelayTimer;
            /*copy to save buffer*/
            memcpy(&DTCInfoTbl[2*MAX_DTC_NUM], &remainDelayTimer, sizeof(remainDelayTimer));
        }
        /*failed counter*/
        DTCInfoTbl[2*MAX_DTC_NUM + sizeof(udsSecAFailedDelayTimer)] = udsSecAFailedCount;
        DFlashRWStatus = DFlashRWStatus |DFLASH_WRITE_DTC;
    }
}


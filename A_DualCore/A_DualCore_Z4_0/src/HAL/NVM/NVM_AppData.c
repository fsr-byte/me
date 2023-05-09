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
#include "NVM_AppData.h"
#include "flash.h"
#include "History_Data.h"
#include "Global.h"
#include "CAN_DBC_Lib.h"
#include "CAN_Operation.h"
#include "PMM_Model_types.h"
#include "M95128.h"
#include "UDS_service.h"
/* =================  Private Constant Declarations =========================*/
/*following table will be removed after UDS module is integrated*/

#define MAX_APP_DATA_AREA_LEN 264   /*maximum length for a appliaton data area is 264  bytes*/
#define APP_DATA_DFLASH_BLOCK_SIZE  0x4000  /*size of dflash block is 16K*/
#define DFLASH_PAGE_SIZE  128


#define MAX_EXTEE_OPERATIONS_FOR_ENM_DATA  4          /*there are 4 external EEPROM operations for saving enm data area ( clear flag and CRC, + write 3 pages)*/
#define MAX_EEPROM_PAGES_FOR_ENM_DATA 3  /*there are 3 pages for enm data areas (2 page data + 1 page flag/CRC)*/

#define MaxEppSavingTry   4             /*at most try 20 times for saving a external EEPROM pages*/
#define MAX_EEPROM_READ_TIME  200    /*at most try 200ms to read data from EEPROM*/
#define MAX_EEPROM_WRITE_TIME  200    /*at most try 200ms to write data into EEPROM*/
//@@@#define MAX_DFLASH_ERASE_TIME   450   /*it cost about 350ms to erase a DFLASH block, so set the timeout to 450ms*/

#define NVM_NO_ERROR 0
#define NVM_DFLASH_ERROR 1
#define NVM_EEPROM_ERROR 2




/***********************************************************************
internal Data FLASH allocation table   refer to document 
http://svn-server01.zhijun.com:443/svn/VCU_Software/branches/BSW/VCU2.0�ĵ�/VCU2.0EEPROM����.xlsx


block 0: reserved for bootloader
block 1: used for DIDs

Data  area 1: relevent to  energy consumption
Data  area 2: relevent to displayed remaining range  and displayed SOC 
Data  area 3: relevant to creep gear position 
Data  area 4: reamaing range calculation in economic mode
Data  area 5: reamaing range calculation in sport mode

shorter and more important data area (1-3) are alocated at the begining , and be loaded/saved at the former loading/saving sequence 
reason: saving data to externl EEPROM costs much time, important data areas should loaded/saved with higher priority. 
In case of unexpected error, the strategy can ensure more consistency for important data 

block 2: for App data area 1 (history data  relevant): structure (20 byte data + 228 byte reserved + 4 bytes flag + 4 bytes CRC32)
block 3: for App data area 2 (history data  relevant): structure (32 byte data + 216 byte reserved + 4 bytes flag + 4 bytes CRC32)
block 4: for App data area 3 (history data  relevant): structure (9 byte data + 239 byte reserved + 4 bytes flag + 4 bytes CRC32)
block 5: for App data area 4 (remaing range relevant): structure (126 byte data + 122 byte reserved + 4 bytes flag + 4 bytes CRC32)
block 6: for App data area 5 (remaing range relevant): structure (126 byte data + 122 byte reserved + 4 bytes flag + 4 bytes CRC32)


block 8:  used to store calibration and its flag
************************************************************************/

/***********************************************************************
externl EEPROM allocation table    1 page size = 64 bytes
page 0: external EEPROM initialized (partioned) flag (8 bytes) and future possible flags
page 1- 230 reseved for DTC snapshot, one DTC occupies one page

page 231 -232: for App data area 1(history data  relevant): structure ( 61 bytes + 4 bytes flag + 4 bytes CRC32)
page 233 -234  reserved for app data area 1

page 235 -238: for App data area 2 (remaing range relevant): structure (252 byte data + 4 bytes flag + 4 bytes CRC32)

page 253:  store Security Access failed delay timer (4 bytes, all 0xFF means invalid data)
************************************************************************/

#define HIST_DATA_ACT_LEN 74   /*actual hisotrical data length.  (3 bytes after creepGearPositon will be reserved by compiler)*/
#define ENM_DATA_ACT_LEN  254  /*actual ENM data length, bug 1786*/
#define HIST_DATA_ALIGNED_LEN 88  /*aligned (to 8) hisotrical data length*/
#define ENM_DATA_ALIGNED_LEN 264   /*aligned (to 8) ENM data length*/


const uint32_t APP_DATA_RAM_ADDR_TBL[ HIST_DATA_AREA_NUM + ENM_DATA_AREA_NUM] = 
{
    0x40018000, 0x40018100, //0x40018200, 0x40018300, 0x40018400
};

const uint32_t APP_DATA_DFLASH_ADDR_TBL[ HIST_DATA_AREA_NUM + ENM_DATA_AREA_NUM] = 
{
    0x808000, 0x80C000, //0x810000, 0x814000, 0x818000
};

/*history data areas are alocated at the begining part*/
const uint16_t APP_DATA_EEPROM_ADDR_TBL[HIST_DATA_AREA_NUM + ENM_DATA_AREA_NUM] = 
{
    0x39C0, 0x3AC0, 
};

/*actual data length (except flag, CRC, reserved)*/
const uint16_t APP_DATA_ACTUAL_LEN[HIST_DATA_AREA_NUM + ENM_DATA_AREA_NUM] = 
{
    // 20/*area1 actual len = 20 */, 32/*area2 actual len = 32 + 4(BMSBattRatedPwrLast)*/, 9 /*area3 actual len = 1+8 +6 */, 126/*area4 actual len = 126 */, 126/*area5 actual len = 126 */
    HIST_DATA_ACT_LEN,  ENM_DATA_ACT_LEN  ,
};

/*totall data length aligned to 8 (including flag, CRC, reserved)*/
const uint16_t APP_DATA_ALIGNED_LEN[HIST_DATA_AREA_NUM + ENM_DATA_AREA_NUM] = 
{
    HIST_DATA_ALIGNED_LEN, ENM_DATA_ALIGNED_LEN
};

#define HIST_DATA_FLAG 0x00000498
#define ENM_DATA_FLAG 0x00000498

const uint32_t APP_DATA_FLAG_TBL[ENM_DATA_AREA_NUM + HIST_DATA_AREA_NUM] =
{
    HIST_DATA_FLAG,
    ENM_DATA_FLAG,
};
const uint32_t Crc32Table[256] =
{
    0x00000000, 0x77073096, 0xEE0E612C, 0x990951BA, 0x076DC419, 0x706AF48F, 0xE963A535, 0x9E6495A3, 0x0EDB8832, 0x79DCB8A4,
    0xE0D5E91E, 0x97D2D988, 0x09B64C2B, 0x7EB17CBD, 0xE7B82D07, 0x90BF1D91, 0x1DB71064, 0x6AB020F2, 0xF3B97148, 0x84BE41DE,
    0x1ADAD47D, 0x6DDDE4EB, 0xF4D4B551, 0x83D385C7, 0x136C9856, 0x646BA8C0, 0xFD62F97A, 0x8A65C9EC, 0x14015C4F, 0x63066CD9,
    0xFA0F3D63, 0x8D080DF5, 0x3B6E20C8, 0x4C69105E, 0xD56041E4, 0xA2677172, 0x3C03E4D1, 0x4B04D447, 0xD20D85FD, 0xA50AB56B,
    0x35B5A8FA, 0x42B2986C, 0xDBBBC9D6, 0xACBCF940, 0x32D86CE3, 0x45DF5C75, 0xDCD60DCF, 0xABD13D59, 0x26D930AC, 0x51DE003A,
    0xC8D75180, 0xBFD06116, 0x21B4F4B5, 0x56B3C423, 0xCFBA9599, 0xB8BDA50F, 0x2802B89E, 0x5F058808, 0xC60CD9B2, 0xB10BE924,
    0x2F6F7C87, 0x58684C11, 0xC1611DAB, 0xB6662D3D, 0x76DC4190, 0x01DB7106, 0x98D220BC, 0xEFD5102A, 0x71B18589, 0x06B6B51F,
    0x9FBFE4A5, 0xE8B8D433, 0x7807C9A2, 0x0F00F934, 0x9609A88E, 0xE10E9818, 0x7F6A0DBB, 0x086D3D2D, 0x91646C97, 0xE6635C01,
    0x6B6B51F4, 0x1C6C6162, 0x856530D8, 0xF262004E, 0x6C0695ED, 0x1B01A57B, 0x8208F4C1, 0xF50FC457, 0x65B0D9C6, 0x12B7E950,
    0x8BBEB8EA, 0xFCB9887C, 0x62DD1DDF, 0x15DA2D49, 0x8CD37CF3, 0xFBD44C65, 0x4DB26158, 0x3AB551CE, 0xA3BC0074, 0xD4BB30E2,
    0x4ADFA541, 0x3DD895D7, 0xA4D1C46D, 0xD3D6F4FB, 0x4369E96A, 0x346ED9FC, 0xAD678846, 0xDA60B8D0, 0x44042D73, 0x33031DE5,
    0xAA0A4C5F, 0xDD0D7CC9, 0x5005713C, 0x270241AA, 0xBE0B1010, 0xC90C2086, 0x5768B525, 0x206F85B3, 0xB966D409, 0xCE61E49F,
    0x5EDEF90E, 0x29D9C998, 0xB0D09822, 0xC7D7A8B4, 0x59B33D17, 0x2EB40D81, 0xB7BD5C3B, 0xC0BA6CAD, 0xEDB88320, 0x9ABFB3B6,
    0x03B6E20C, 0x74B1D29A, 0xEAD54739, 0x9DD277AF, 0x04DB2615, 0x73DC1683, 0xE3630B12, 0x94643B84, 0x0D6D6A3E, 0x7A6A5AA8,
    0xE40ECF0B, 0x9309FF9D, 0x0A00AE27, 0x7D079EB1, 0xF00F9344, 0x8708A3D2, 0x1E01F268, 0x6906C2FE, 0xF762575D, 0x806567CB,
    0x196C3671, 0x6E6B06E7, 0xFED41B76, 0x89D32BE0, 0x10DA7A5A, 0x67DD4ACC, 0xF9B9DF6F, 0x8EBEEFF9, 0x17B7BE43, 0x60B08ED5,
    0xD6D6A3E8, 0xA1D1937E, 0x38D8C2C4, 0x4FDFF252, 0xD1BB67F1, 0xA6BC5767, 0x3FB506DD, 0x48B2364B, 0xD80D2BDA, 0xAF0A1B4C,
    0x36034AF6, 0x41047A60, 0xDF60EFC3, 0xA867DF55, 0x316E8EEF, 0x4669BE79, 0xCB61B38C, 0xBC66831A, 0x256FD2A0, 0x5268E236,
    0xCC0C7795, 0xBB0B4703, 0x220216B9, 0x5505262F, 0xC5BA3BBE, 0xB2BD0B28, 0x2BB45A92, 0x5CB36A04, 0xC2D7FFA7, 0xB5D0CF31,
    0x2CD99E8B, 0x5BDEAE1D, 0x9B64C2B0, 0xEC63F226, 0x756AA39C, 0x026D930A, 0x9C0906A9, 0xEB0E363F, 0x72076785, 0x05005713,
    0x95BF4A82, 0xE2B87A14, 0x7BB12BAE, 0x0CB61B38, 0x92D28E9B, 0xE5D5BE0D, 0x7CDCEFB7, 0x0BDBDF21, 0x86D3D2D4, 0xF1D4E242,
    0x68DDB3F8, 0x1FDA836E, 0x81BE16CD, 0xF6B9265B, 0x6FB077E1, 0x18B74777, 0x88085AE6, 0xFF0F6A70, 0x66063BCA, 0x11010B5C,
    0x8F659EFF, 0xF862AE69, 0x616BFFD3, 0x166CCF45, 0xA00AE278, 0xD70DD2EE, 0x4E048354, 0x3903B3C2, 0xA7672661, 0xD06016F7,
    0x4969474D, 0x3E6E77DB, 0xAED16A4A, 0xD9D65ADC, 0x40DF0B66, 0x37D83BF0, 0xA9BCAE53, 0xDEBB9EC5, 0x47B2CF7F, 0x30B5FFE9,
    0xBDBDF21C, 0xCABAC28A, 0x53B39330, 0x24B4A3A6, 0xBAD03605, 0xCDD70693, 0x54DE5729, 0x23D967BF, 0xB3667A2E, 0xC4614AB8,
    0x5D681B02, 0x2A6F2B94, 0xB40BBE37, 0xC30C8EA1, 0x5A05DF1B, 0x2D02EF8D
};

/***************************above should be removed after App and UDS module integrated*****************************************************/


/* =================  Private Variable Declarations =========================*/

CORE0_INIT NvMLoadSaveType NvMAppDataSaveLoadFlag = 0 ;
CORE0_INIT NvMHandleType  NvMAppDataStatus;

CORE0_INIT uint8_t  HistDataDFlashBuf[HIST_DATA_ALIGNED_LEN];
CORE0_INIT uint8_t  HistDataEEPROMBuf[HIST_DATA_ALIGNED_LEN];

CORE0_INIT uint8_t  enmDataDFlashBuf[ENM_DATA_ALIGNED_LEN];
CORE0_INIT uint8_t  enmDataEEPROMBuf[ENM_DATA_ALIGNED_LEN];

CORE0_INIT uint8_t HistDataCheckFaliedFlag = 0;    /*��ʷ���ݼ�����*/
CORE0_INIT uint8_t AppDataCheckFaliedFlag = 0;     /*�������ݼ�����*/

#define DTC_RAM_ADDR (uint32_t)(&Fault_storage_array[0])
#define DTC_RAM_TABLE Fault_storage_array

const uint32_t APP_DATA_DFLASH_BUF_TBL[2] = {(uint32_t) HistDataDFlashBuf, (uint32_t) enmDataDFlashBuf};
const uint32_t APP_DATA_EEPROM_BUF_TBL[2] = {(uint32_t) HistDataEEPROMBuf, (uint32_t) enmDataEEPROMBuf};


/* =================  Private function Declarations =========================*/
void NvMAppDataSaveToDFlash(uint8_t areaIndex);
uint32_t NvMAppDataSaveToEEPROM(uint8_t areaIndex);
uint32_t CalcCrc32(uint8_t buf[], uint16_t len);
void SendNvMTestMsg(uint8_t saveType, uint8_t loadType, uint8_t areaIdx);


/*---------------------------------------------------------------------------
description:   this function Calculate the CRC checksum
input param: buf --  buffer to be calculated 
output param: udsCRC32 -- gblCrc
return value: calculated CRC32
---------------------------------------------------------------------------*/
uint32_t CalcCrc32(uint8_t buf[], uint16_t len)
{
    uint8_t  index;
    uint32_t newCrc;
    uint16_t i;
    
    newCrc = CRC_INIT_VAL;
    for(i = 0; i < len; i++)
    {
        index = (uint8_t)(buf[i] ^ newCrc);
        newCrc = (newCrc >> 8) ^ Crc32Table[index];
    }
    return newCrc;


}

/*---------------------------------------------------------------------------
description: this function check the data valid flag
input param:       areaIndex, data area index
input param:       buf, data buffer read out from DFLASH or EEPROM
output param:     void
return:            TRUE: valid flag is correct; false -incorrect
---------------------------------------------------------------------------*/
boolean NvMAppDataCheckValidFlag(uint8_t areaIndex, uint8_t  buf[])
{
    boolean  bFlagOK;
    uint8_t i;
    uint16_t  actLen;
    uint32_t  savedFlag;

    bFlagOK = TRUE;
    actLen = APP_DATA_ACTUAL_LEN[areaIndex];

    /*parse out the saved valid flag*/
    savedFlag = 0;
    for(i = 0; i < APP_FLAG_SIZE; i++)
    {
        savedFlag = savedFlag << 8;
        savedFlag = savedFlag + (uint32_t)buf[actLen + i];
    }
    /*compare saved flag with constant*/
    if(savedFlag != APP_DATA_FLAG_TBL[areaIndex])
    {
       bFlagOK = FALSE;
    }

    return bFlagOK;
}

/*---------------------------------------------------------------------------
description: this function check the CRC
input param:       areaIndex, data area index
input param:       buf, data buffer read out from DFLASH or EEPROM
output param:     void
return:            TRUE:  CRC  is correct; false -incorrect
---------------------------------------------------------------------------*/
boolean NvMAppDataCheckCrc(uint8_t areaIndex, uint8_t  buf[])
{
    boolean  bCrcOK;
    uint8_t i;
    uint16_t  actLen;
    uint32_t  savedCrc;    /*CRC saved in NVM*/
    uint32_t  calcedCrc;   /*CRC calculated based on data*/
    
    bCrcOK = TRUE;
    actLen = APP_DATA_ACTUAL_LEN[areaIndex];

    /*parse out the saved valid flag*/
    savedCrc = 0;
    for(i = 0; i < APP_CRC_SIZE; i++)
    {
        savedCrc = savedCrc << 8;
        savedCrc = savedCrc + (uint32_t)buf[actLen + APP_FLAG_SIZE + i];
    }

    calcedCrc = CRC_INIT_VAL;
    calcedCrc = CalcCrc32( buf , actLen);
    /*compare saved flag with constant*/
    if(savedCrc != calcedCrc)
    {
       bCrcOK = FALSE;
    }

    return bCrcOK;
}
/*---------------------------------------------------------------------------
description: generate PEPS challenge bytes for PMM module
input param:       void
output param:     void
return:           void
---------------------------------------------------------------------------*/
void GenPEPSChallengeBytes(void)
{
    uint32_t seed;
    uint8_t VIN[UDS_VIN_LEN];
    uint8_t index;
    
    seed = (uint32_t)((SystemTickMs>>16) + SystemTickMs);
    for(index = 0; index < UDS_SP_DID_NUM; index++)
    {
        if(UDS_VIN_DID == UdsSpDidTbl[index].DataId)
        {
            break;
        }
    }
    usReadDIDDatabyIndex(index, VIN);
    for(index = 0; index < sizeof(PEPS_ChallengeCodeHistory_Byte); index++)
    {
        PEPS_ChallengeCodeHistory_Byte[index] = (uint8_t)(seed) + (uint8_t)VIN[UDS_VIN_LEN-1 - index];
    }
}
/*---------------------------------------------------------------------------
description: this function initialize the applicaton data area
input param:       areaIndex which area to be initialized
input param:       Buf buffer to store the data + flag +crc loaded from EEPROM /DFlash
output param:     void
return:           void
---------------------------------------------------------------------------*/
void Init_AppData(uint8_t areaIndex)
{
    if(areaIndex == 0)
    {
        AppData_Init_1();
        AppData_Init_2();
        AppData_Init_3();
        GenPEPSChallengeBytes();
        SocResiMilgNvMCorrect = 0;
    }
    else
    {
        AppData_Init_4();
        AppData_Init_5();
    }
}
/*---------------------------------------------------------------------------
description: this function set the error state and NVM DTC flag
input param:       areaIndex which area to be initialized
input param:       bDFlashFlagValid etc (valid flag, CRC is correct or not)
output param:     void
return:           error sate bit map
---------------------------------------------------------------------------*/
uint16_t SetErrorStateAndDTCFlag(uint8_t areaIndex, boolean DFlashOK, boolean EEPROMOK)
{
    uint16_t errorState;

    errorState = 0;
    /*update the error state*/
    if(FALSE == DFlashOK )
    {
        errorState = errorState |NVM_DFLASH_ERROR;
    }
    if(FALSE == EEPROMOK )
    {
        errorState = errorState | NVM_EEPROM_ERROR;
    }
    /*shift left to correct position each area occupies 2 bits*/
    errorState = errorState << areaIndex;
    errorState = errorState << areaIndex;

    /*update the DTC flags, only valid flag correct but CRC wrong, set the DTC flag*/
    if((FALSE == DFlashOK) &&(FALSE == EEPROMOK))
    {
        if(areaIndex <=(HIST_DATA_AREA_NUM-1))
        {
            HistDataCheckFaliedFlag = TRUE;
        }
        else
        {
            AppDataCheckFaliedFlag = TRUE;
        }
    }

    return errorState;
}

/*---------------------------------------------------------------------------
description: this function load an area of  data from EEPROM, and check the valid flag, crc
input param:       NvMAppDataStatus, AppDataDFlashBuf
output param:     NvMAppDataStatus
return:            TRUE : both CRC and valid flag are correct
---------------------------------------------------------------------------*/
boolean  NvMAppDataLoadFromEEPROM(uint8_t areaIndex)
{
    boolean validFlag;
    boolean crcOK;
    uint32_t extEERslt;
    boolean extEERsltOK = FALSE;
       
    extEERslt =  ReadExtEE(APP_DATA_EEPROM_ADDR_TBL[areaIndex], APP_DATA_ALIGNED_LEN[areaIndex], (uint8_t*)APP_DATA_EEPROM_BUF_TBL[areaIndex] );
    if (EXTEE_OK == extEERslt)
    {
        validFlag = NvMAppDataCheckValidFlag(areaIndex, (uint8_t*)APP_DATA_EEPROM_BUF_TBL[areaIndex]);
        crcOK = NvMAppDataCheckCrc(areaIndex, (uint8_t*)APP_DATA_EEPROM_BUF_TBL[areaIndex]);
        /*valid correct, CRC correct, set the return value  to TRUE*/
        if((TRUE == validFlag) && (crcOK == TRUE))
        {
            extEERsltOK = TRUE;
        }
    }
    return extEERsltOK ;
}
/*---------------------------------------------------------------------------
description: this function is the post-handling after the EEPROM was loaded for an App data area
* 1: 
input param:       eepLoadOK : true EEPROM loaded successfully, FALSE: loading timeout
output param:     NvMAppDataStatus
return:            void
---------------------------------------------------------------------------*/
void NvMAppDataAnEEPROMAreaLoaded (boolean eepLoadOK)
{
    /*1: DFLASH wrong, EEPROM wrong re-intialize the data area*/
    if((FALSE == NvMAppDataStatus.DFlashOK[NvMAppDataStatus.currAppDataArea]) &&(FALSE == NvMAppDataStatus.EepromOK[NvMAppDataStatus.currAppDataArea] ))
    {
        Init_AppData( NvMAppDataStatus.currAppDataArea);
    }
    /*DFLASH correct, EEPROM wrong, back up DFLASH to EEPROM*/
    if((TRUE == NvMAppDataStatus.DFlashOK[NvMAppDataStatus.currAppDataArea]) &&(FALSE == NvMAppDataStatus.EepromOK[NvMAppDataStatus.currAppDataArea] ))
    {
       NvMAppDataStatus.backToEepromFlag[NvMAppDataStatus.currAppDataArea] = TRUE;
       (void)memcpy((uint8_t*)APP_DATA_EEPROM_BUF_TBL[NvMAppDataStatus.currAppDataArea], (uint8_t*)APP_DATA_DFLASH_BUF_TBL[NvMAppDataStatus.currAppDataArea], APP_DATA_ALIGNED_LEN[NvMAppDataStatus.currAppDataArea]);
    }
    /*DFLASH wrong, EEPROM correct, back up EEPROM to DFLASH*/
    if((FALSE == NvMAppDataStatus.DFlashOK[NvMAppDataStatus.currAppDataArea]) &&(TRUE == NvMAppDataStatus.EepromOK[NvMAppDataStatus.currAppDataArea] ))
    {
        /*!!!very important: copy correct data from EEPROM buffer into ENM RAM data area*/
        (void)memcpy((void*)APP_DATA_RAM_ADDR_TBL[NvMAppDataStatus.currAppDataArea],
                              (uint8_t*)APP_DATA_EEPROM_BUF_TBL[NvMAppDataStatus.currAppDataArea], APP_DATA_ACTUAL_LEN[NvMAppDataStatus.currAppDataArea]);   
        if(HIST_DATA_INDEX == NvMAppDataStatus.currAppDataArea)
        {
            (void)memcpy((uint8_t*)APP_DATA_DFLASH_BUF_TBL[HIST_DATA_INDEX], (uint8_t*)APP_DATA_EEPROM_BUF_TBL[HIST_DATA_INDEX], APP_DATA_ALIGNED_LEN[HIST_DATA_INDEX]);
            DFlashRWStatus = DFlashRWStatus |DFLASH_WRITE_APP_HIST;
        }
        else
        {
            (void)memcpy((uint8_t*)APP_DATA_DFLASH_BUF_TBL[ENM_DATA_INDEX], (uint8_t*)APP_DATA_EEPROM_BUF_TBL[ENM_DATA_INDEX], APP_DATA_ALIGNED_LEN[ENM_DATA_INDEX]);
            DFlashRWStatus = DFlashRWStatus |DFLASH_WRITE_APP_ENM;
        }
    }
    /*VCU bug 1451: Historay data in EEPROM is correct, set SocResiMilgNvMCorrect to 1*/
    if(TRUE ==  NvMAppDataStatus.EepromOK[HIST_DATA_INDEX])
    {
        SocResiMilgNvMCorrect = 1;
    }
    /*set the error state */
    NvMAppDataStatus.errorState |= SetErrorStateAndDTCFlag(NvMAppDataStatus.currAppDataArea, NvMAppDataStatus.DFlashOK[NvMAppDataStatus.currAppDataArea], NvMAppDataStatus.EepromOK[NvMAppDataStatus.currAppDataArea]);
}

/*---------------------------------------------------------------------------
description: this function write data into DFLASH
input param:       NvMAppDataStatus, AppDataDFlashBuf
output param:     NvMAppDataStatus
return:            void
---------------------------------------------------------------------------*/
void NvMAppDataSaveToDFlash(uint8_t areaIndex)
{
    uint32_t DFlashAddr;
    //uint16_t totalLen;

    DFlashAddr = APP_DATA_DFLASH_ADDR_TBL[areaIndex];
    //totalLen = APP_DATA_ALIGNED_LEN[areaIndex];

    if(HIST_DATA_INDEX == areaIndex)
    {
        FLASH_EE_Write8(DFlashAddr,  sizeof(HistDataDFlashBuf),  HistDataDFlashBuf);
        DFlashRWStatus = DFlashRWStatus & (~DFLASH_WRITE_APP_HIST);  /*clear App data DFLASH writing request*/        
        if(NvMDataSaving == NvMAppDataSaveLoadFlag)
        {
            SendNvMTestMsg(NvMSaveDFlash_HIST, NvMLoadIdle, HIST_DATA_INDEX);  /*save to DFlash for pre-sleep saviing*/
        }
        else
        {
            SendNvMTestMsg(NvMSaveDFlash_HIST, NvMBackUpDFlash_HIST, HIST_DATA_INDEX);   /*save to DFlash , reason : backing up because Dflash corrupted*/
        }
    }
    else
    {
        FLASH_EE_Write8(DFlashAddr,  sizeof(enmDataDFlashBuf),  enmDataDFlashBuf);
        DFlashRWStatus = DFlashRWStatus & (~DFLASH_WRITE_APP_ENM);  /*clear App data  DFLASH writing request*/        
        if(NvMDataSaving == NvMAppDataSaveLoadFlag)
        {
            SendNvMTestMsg(NvMSaveDFlash_ENM, NvMLoadIdle, ENM_DATA_INDEX); /*save to DFlash for pre-sleep saviing*/
        }
        else
        {
            SendNvMTestMsg(NvMSaveDFlash_ENM, NvMBackUpDFlash_ENM, ENM_DATA_INDEX);/*save to DFlash , reason : backing up because Dflash corrupted*/
        }
    }
}
/*---------------------------------------------------------------------------
description: this function write data into EEPROM
input param:       NvMAppDataStatus, AppDataEEPROMBuf
output param:     NvMAppDataStatus
return:            void
---------------------------------------------------------------------------*/
uint32_t NvMAppDataSaveToEEPROM(uint8_t areaIndex)
{
    uint32_t extEERslt;
    uint16_t EepromAddr;
  //@@@@  uint16_t totalLen;
    uint16_t writeLen;
    uint8_t extEEData[EXTEE_PAGE_SIZE];

    /*calculate length to be written*/
    writeLen = EXTEE_PAGE_SIZE;
    if(writeLen > (APP_DATA_ALIGNED_LEN[areaIndex] - NvMAppDataStatus.currDataCursor))
    {
        writeLen = APP_DATA_ALIGNED_LEN[areaIndex] - NvMAppDataStatus.currDataCursor;
    }

    /*calculate EEPROM address*/
    EepromAddr = APP_DATA_EEPROM_ADDR_TBL[areaIndex] + NvMAppDataStatus.currDataCursor;
    /*write into EEPROM*/
    (void)memcpy(extEEData, (uint8_t*)(APP_DATA_EEPROM_BUF_TBL[areaIndex] + NvMAppDataStatus.currDataCursor), writeLen);

    extEERslt = WriteExtEE(EepromAddr, writeLen, extEEData);
    if(EXTEE_OK == extEERslt)
    {
        NvMAppDataStatus.currDataCursor =  NvMAppDataStatus.currDataCursor + writeLen;
    }

    if((HIST_DATA_INDEX == NvMAppDataStatus.currAppDataArea))
    {
        if(NvMDataSaving == NvMAppDataSaveLoadFlag)
        {
            SendNvMTestMsg(NvMSaveEEPROM_HIST, NvMLoadIdle, HIST_DATA_INDEX);  /*save to EEPROM for pre-sleep saviing*/
        }
        else
        {
            SendNvMTestMsg(NvMSaveEEPROM_HIST, NvMBackUpEEPROM_HIST, HIST_DATA_INDEX);   /*save to EEPROM , reason : backing up because EEPROM corrupted*/
        }
    }
    else
    {
        if(NvMDataSaving == NvMAppDataSaveLoadFlag)
        {
            SendNvMTestMsg(NvMSaveEEPROM_ENM, NvMLoadIdle, ENM_DATA_INDEX);  /*save to EEPROM for pre-sleep saviing*/
        }
        else
        {
            SendNvMTestMsg(NvMSaveEEPROM_ENM, NvMBackUpEEPROM_ENM, ENM_DATA_INDEX);   /*save to EEPROM , reason : backing up because EEPROM corrupted*/
        }
    }    
    return extEERslt;
}
/*============================following functions are public interface functions =======================================*/
/*---------------------------------------------------------------------------
description:  check if Data should be backuped to EEPROM
input param:       NvMAppDataStatus, NvMAppDataSaveLoadFlag
output param:     NvMAppDataStatus
return:            void
---------------------------------------------------------------------------*/
boolean NvMAppData_NeedBackToEEPROM(void)
{
    boolean backToEeprom = FALSE;
    /*bacuse start from are 0 to saving EEPROM, so check backup request for area 1 as first step*/
    if(TRUE == NvMAppDataStatus.backToEepromFlag[ENM_DATA_INDEX])
    {
        backToEeprom = TRUE;
        NvMAppDataStatus.currAppDataArea = ENM_DATA_INDEX;
        NvMAppDataStatus.currDataCursor = 0;
    }

    if(TRUE == NvMAppDataStatus.backToEepromFlag[HIST_DATA_INDEX])
    {
        backToEeprom = TRUE;
        NvMAppDataStatus.currAppDataArea = HIST_DATA_INDEX;
        NvMAppDataStatus.currDataCursor = 0;
    }
    return backToEeprom;
}
/*---------------------------------------------------------------------------
description:  because DFlash data was loaded in initializing phase, this function only load data from EEPROM
input param:       NvMAppDataStatus, NvMAppDataSaveLoadFlag
output param:     NvMAppDataStatus
return:            void
---------------------------------------------------------------------------*/
boolean NvMAppData_LoadTask(void)
{  
    uint32_t timeOut;
    boolean allEepromLoaded = FALSE;
    
    NvMAppDataStatus.EepromOK[NvMAppDataStatus.currAppDataArea] = NvMAppDataLoadFromEEPROM(NvMAppDataStatus.currAppDataArea);
    if(TRUE == NvMAppDataStatus.EepromOK[NvMAppDataStatus.currAppDataArea])
    {
        NvMAppDataAnEEPROMAreaLoaded(TRUE);
        NvMAppDataStatus.currDataCursor = APP_DATA_ALIGNED_LEN[NvMAppDataStatus.currAppDataArea]; /*prepare to move to next area*/
    }
    else
    {
        /*calculate a suitable timeout threshold*/
        timeOut = MaxAppDataLoadTime;
        /*first area, give half timeout value*/
        if(HIST_DATA_INDEX == NvMAppDataStatus.currAppDataArea)
        {
            timeOut = MaxAppDataLoadTime >>1;
        }
        /*timeout , give up the area reading */
         if((SystemTickMs > NvMAppDataStatus.OperStartTime) && ((SystemTickMs -NvMAppDataStatus.OperStartTime) >( timeOut )))
         {
            NvMAppDataAnEEPROMAreaLoaded(FALSE);
            NvMAppDataStatus.currDataCursor = APP_DATA_ALIGNED_LEN[NvMAppDataStatus.currAppDataArea]; /*prepare to move to next area*/
         }
    }

    /*send the test message after the whole area loaded*/
    if( NvMAppDataStatus.currAppDataArea == HIST_DATA_INDEX)
    {
        SendNvMTestMsg(NvMSaveIdle, NvMLoadingEEPROM_HIST, HIST_DATA_INDEX);  /*data cursor is in History data range, */
    }
    else
    {
        SendNvMTestMsg(NvMSaveIdle, NvMLoadingEEPROM_ENM, ENM_DATA_INDEX);
    }

    if(NvMAppDataStatus.currDataCursor >= APP_DATA_ALIGNED_LEN[NvMAppDataStatus.currAppDataArea])
    {
        NvMAppDataStatus.currAppDataArea ++;
        /*reset data cursor to 0 for reading next data area*/
        NvMAppDataStatus.currDataCursor = 0;
    }
    
    if(NvMAppDataStatus.currAppDataArea >= (HIST_DATA_AREA_NUM + ENM_DATA_AREA_NUM))
    {
        allEepromLoaded = TRUE;
        NvMAppDataSaveLoadFlag = NvMDataLoaded;
    }
    return allEepromLoaded;
}
/*---------------------------------------------------------------------------
description: this function start to save the Application data
input param:       
output param:     void
return:            void
---------------------------------------------------------------------------*/
void NvMAppDataStartSave(void)
{
    uint32_t ramAddr;
    uint32_t calcedCrc;
    uint32_t validFlag;
    uint16_t  actLen;     /*actual len*/
    uint16_t  totalLen;   
    uint16_t i;
    for(i = 0; i < (HIST_DATA_AREA_NUM + ENM_DATA_AREA_NUM); i++)
    {   
        /*prepare data buffer for application */
        ramAddr = APP_DATA_RAM_ADDR_TBL[i];
        validFlag = APP_DATA_FLAG_TBL[i];
        actLen = APP_DATA_ACTUAL_LEN[i];
        totalLen = APP_DATA_ALIGNED_LEN[i];
    
        /*copy data from RAM to buffer*/
        (void)memcpy((uint8_t*)APP_DATA_DFLASH_BUF_TBL[i], (uint8_t*)ramAddr, actLen);
        
        /*copy valid flag*/
        (void)memcpy((uint8_t*)(APP_DATA_DFLASH_BUF_TBL[i]+actLen), &validFlag, sizeof(validFlag));
        /*calculate CRC and copy to buffer */
        calcedCrc = CalcCrc32((uint8_t*)APP_DATA_DFLASH_BUF_TBL[i], actLen);
        
        (void)memcpy((uint8_t*)(APP_DATA_DFLASH_BUF_TBL[i]+actLen + APP_FLAG_SIZE), &calcedCrc, sizeof(calcedCrc));
        /*copy DFlash bufer to EEPROM buffer*/
        (void)memcpy((uint8_t*)APP_DATA_EEPROM_BUF_TBL[i], (uint8_t*)APP_DATA_DFLASH_BUF_TBL[i], totalLen);   
    }

    NvMAppDataStatus.currAppDataArea = 0;
    NvMAppDataStatus.currDataCursor = 0;
    NvMAppDataStatus.OperStartTime = SystemTickMs;
    NvMAppDataSaveLoadFlag = NvMDataSaving;
    /*set on the application data EEPROM/ DFLASH write request*/
    DFlashRWStatus = DFlashRWStatus |DFLASH_WRITE_APP_HIST;
    DFlashRWStatus = DFlashRWStatus |DFLASH_WRITE_APP_ENM;
}

/*---------------------------------------------------------------------------
description: this function handes the app data EEPROM writing operation
input param:       NvMAppDataStatus, NvMAppDataSaveLoadFlag
output param:     NvMAppDataStatus
return:            void
---------------------------------------------------------------------------*/
boolean NVM_AppData_SaveTask(void)
{
    uint32_t extEERslt;
    uint32_t timeOutThreshold;
    boolean allEepromSaved;

    /*all EEPROM data saved, return directly*/
    if(NvMAppDataStatus.currAppDataArea >= (HIST_DATA_AREA_NUM + ENM_DATA_AREA_NUM))
    {
        /*all EEPROM saved, check the if the DFlash saved*/
        if(((DFlashRWStatus & DFLASH_WRITE_APP_HIST) != DFLASH_WRITE_APP_HIST) && ((DFlashRWStatus & DFLASH_WRITE_APP_ENM) != DFLASH_WRITE_APP_ENM))
        {
            /*pre-sleep saveing , change NvMAppDataSaveLoadFlag to NvMDataSaved*/
            if(NvMDataSaving == NvMAppDataSaveLoadFlag)
            {
                NvMAppDataSaveLoadFlag = NvMDataSaved;
                SendNvMTestMsg(NvMSaveIdle, NvMLoadIdle, ENM_DATA_INDEX);  /* DFLASH and EEPROM all saved, send the last message*/
            }
        }
        return TRUE;        
    }

    extEERslt = NvMAppDataSaveToEEPROM(NvMAppDataStatus.currAppDataArea);

    allEepromSaved = FALSE;
    if(EXTEE_OK != extEERslt)
    {
        /*timeout , give up the operation*/
        timeOutThreshold = MaxAppDataLoadTime;    /*maximum time for loading one area */
        if(NvMDataSaving == NvMAppDataSaveLoadFlag)
        {
            timeOutThreshold = MaxAppDataSaveTime; /*maximum time for saving one area */
        }
        if((SystemTickMs > NvMAppDataStatus.OperStartTime ) && ((SystemTickMs - NvMAppDataStatus.OperStartTime) > timeOutThreshold))
        {
            if(NvMDataSaving == NvMAppDataSaveLoadFlag)
            {
                SendNvMTestMsg(NvMSaveEEPROM_TIMEOUT, NvMLoadIdle, NvMAppDataStatus.currAppDataArea);  /*save to EEPROM for pre-sleep saviing*/
            }
            else
            {
                SendNvMTestMsg(NvMSaveEEPROM_TIMEOUT, NvMBackUpEEPROM_ENM,  NvMAppDataStatus.currAppDataArea);   /*save to EEPROM , reason : backing up because EEPROM corrupted*/
            }
            /*set current cursor to max, then move to next area*/
            NvMAppDataStatus.currDataCursor = APP_DATA_ALIGNED_LEN[NvMAppDataStatus.currAppDataArea];
        }
    }  
    /*data cursor was changed in NvMAppDataSaveToEEPROM(), check if it is reaches the max data area lenth, if Yes  move to next area*/
    if(NvMAppDataStatus.currDataCursor >= APP_DATA_ALIGNED_LEN[NvMAppDataStatus.currAppDataArea])
    {
         NvMAppDataStatus.currAppDataArea++; /*move to next area*/
         NvMAppDataStatus.currDataCursor = 0;
    }
    /*all area saved*/
    if(NvMAppDataStatus.currAppDataArea >= (HIST_DATA_AREA_NUM + ENM_DATA_AREA_NUM))
    {
        allEepromSaved = TRUE;
    }
    else
    {
        /*there is no EEPROM bakcup request for next area*/
        if((FALSE == NvMAppDataStatus.backToEepromFlag[NvMAppDataStatus.currAppDataArea]) && (NvMDataSaving != NvMAppDataSaveLoadFlag) )
        {
            NvMAppDataStatus.currAppDataArea = HIST_DATA_AREA_NUM + ENM_DATA_AREA_NUM;
            allEepromSaved = TRUE;
        }
    }
    return allEepromSaved;
}

/*---------------------------------------------------------------------------
  this function prepare the NVM moudle test message FA0666
send the ResiMilg and subtotal energy , load state, sleep/active flag etc
input param:       LoadType :0: power on load, 1: wake-up from pre-sleep load 
input param:       errorState; 
output param:     void
return:            void  
---------------------------------------------------------------------------*/
void PrepareNvMTestMsg666(uint8_t saveType, uint8_t loadType, uint8_t * buff)
{

   //@@@@ CAN_SetValue(buff, 0, 2, NvMAppDataStatus.SaveType); /*NVM save sub-state machine  */    
  //@@  CAN_SetValue(buff, 3, 3, NvMAppDataStatus.loadType); /*NVM load sub-state machine  */    

    CAN_SetValue(buff, 14, 4, saveType); /*NVM save sub-state machine  */    
    CAN_SetValue(buff, 2, 4, loadType); /*NVM load sub-state machine  */    

    CAN_SetValue(buff, 6, 2, NvMAppDataSaveLoadFlag); /* main save load state  */    
    CAN_SetValue(buff, 8, 4, NvMAppDataStatus.errorState); /* error state */    
    CAN_SetValue(buff, 12, 2, NvMAppDataStatus.currAppDataArea);
    CAN_SetValue(buff, 17, 1, PMM_output.VPMM_InternalSleepActive_flg);       
    CAN_SetValue(buff, 18, 2, creepGearPositon);       
    CAN_SetValue(buff, 20, 4, bswWakeSrc);       
    CAN_SetValue(buff, 24, 9, NvMAppDataStatus.currDataCursor);       
    CAN_SetValue(buff, 40, 7, (uint32_t)SOCDisp);       
    CAN_SetValue(buff, 47, 9, (uint32_t)ResiMilg);       
    CAN_SetValue(buff, 48, 7, (uint32_t)BMSSocLast);       
    CAN_SetValue(buff, 56, 7, (uint32_t)BMSSocMaxLast);       
    
    /*lock the channel */
}
/*---------------------------------------------------------------------------
  this function prepare the NVM moudle test message FA0777
output param:     void
return:            void  
---------------------------------------------------------------------------*/
void PrepareNvMTestMsg777(uint8_t * buff)
{
    
    CAN_SetValue(buff, 0, 8, (uint32_t)VCUVehEgyCnseDrv); 
    CAN_SetValue(buff, 24, 24, (uint32_t)VCUSubTotalEgyCnse_kwh); 

    CAN_SetValue(buff, 40, 16, (uint32_t)sport_egyCnse_1km[0]); 
    CAN_SetValue(buff, 56, 16, (uint32_t)eco_egyCnse_1km[0]); 

    /*lock the channel */
}
/*---------------------------------------------------------------------------
  this function prepare the two NVM moudle test messages and send them out
output param:     void
return:        void  
---------------------------------------------------------------------------*/
void SendNvMTestMsg(uint8_t saveType, uint8_t loadType, uint8_t areaIdx)
{
#define WAIT_A_MSG_SENT 1      /*delay 1ms to wait a message sent out*/
#define WAIT_DELAY_INIT  300   /*initalization phase, SystemTickMs is 0, so use conter++ to delay*/
#define MAX_SEND_RETRY_NUM 3

    _CAN_MESSAGE_  NvMTestMsg;
   uint32_t msgPDU;
   uint8_t msgSentRslt;
   uint8_t msgSendTry;
   uint32_t delayCnt;
   
    //@@@uint16_t delayCnt;
    if(1 == KUDS_TestFeature)
    {
        NvMTestMsg.control.dlc = 8;
        NvMTestMsg.control.id = 0x168A0999;
        NvMTestMsg.control.dlc = 8;
        NvMTestMsg.control.ide = 1;    /*extended rame*/
        NvMTestMsg.control.rtr = 0;    /*not remote frame*/

        PrepareNvMTestMsg666(saveType, loadType, &NvMTestMsg.data.R8[0]);

        NvMTestMsg.data.R32[0] = 0;
        msgPDU = NvMAppDataSaveLoadFlag&0x3;
        msgPDU = msgPDU << 30;
        NvMTestMsg.data.R32[0] += msgPDU;

        msgPDU = loadType &0xF;
        msgPDU = msgPDU << 26;
        NvMTestMsg.data.R32[0] += msgPDU;
        
        msgPDU = saveType &0xF;
        msgPDU = msgPDU << 22;
        NvMTestMsg.data.R32[0] += msgPDU;

       //@@@@ msgPDU = NvMAppDataStatus.currAppDataArea &0x3;
        msgPDU = areaIdx &0x3;
        msgPDU = msgPDU << 20;
        NvMTestMsg.data.R32[0] += msgPDU;

        msgPDU = NvMAppDataStatus.errorState &0xF;
        msgPDU = msgPDU << 16;
        NvMTestMsg.data.R32[0] += msgPDU;

        msgPDU = bswWakeSrc &0xF;
        msgPDU = msgPDU << 12;
        NvMTestMsg.data.R32[0] += msgPDU;

        msgPDU = creepGearPositon &0x3;
        msgPDU = msgPDU << 10;
        NvMTestMsg.data.R32[0] += msgPDU;
        
        msgPDU = PMM_output.VPMM_InternalSleepActive_flg &0x1;
        msgPDU = msgPDU << 9;
        NvMTestMsg.data.R32[0] += msgPDU;

        msgPDU =  NvMAppDataStatus.currDataCursor &0x1FF;
        NvMTestMsg.data.R32[0] += msgPDU;

        NvMTestMsg.data.R32[1] = 0;
        msgPDU = ResiMilg &0x1FF;
        msgPDU = msgPDU << 23;
        NvMTestMsg.data.R32[1] += msgPDU;

        msgPDU = (uint32_t)(SOCDisp);
        msgPDU = msgPDU &0x7F;
        msgPDU = msgPDU << 16;
        NvMTestMsg.data.R32[1] += msgPDU;

        msgPDU = (uint32_t)(BMSSocLast);
        msgPDU = msgPDU &0x7F;
        msgPDU = msgPDU << 8;
        NvMTestMsg.data.R32[1] += msgPDU;

        msgPDU = (uint32_t)(BMSSocMaxLast);
        msgPDU = msgPDU &0x7F;
        msgPDU = msgPDU << 0;
        NvMTestMsg.data.R32[1] += msgPDU;

        /*send test message to CAN 1*/
        /* //��CAN1��ʱ����S21��body CAN����(CR1931)���ʹر�CAN1�ϵ����౨��--2020.08.18
        msgSentRslt  = 1;
        msgSendTry = 0;
        while (msgSentRslt != 0)
        {
            msgSentRslt = CANTransimitRandomMessage(CAN1,&NvMTestMsg);
            //send failed, delay a while
            if( msgSentRslt != 0)
            {
               msgSendTry ++;
               if(msgSendTry >= MAX_SEND_RETRY_NUM)
               {
                    break;
               }
               else
               {
                    delayCnt =0;
                    while(delayCnt < WAIT_DELAY_INIT)
                    {
                        delayCnt ++;
                    }
                }
            }
        }
       */

        /*send test message to CAN 3*/
        msgSentRslt  = 1;
        msgSendTry = 0;
        while (msgSentRslt != 0)
        {
            msgSentRslt = CANTransimitRandomMessage(CAN3,&NvMTestMsg);
            /*send failed, delay a while*/
            if( msgSentRslt != 0)
            {
               msgSendTry ++;
               if(msgSendTry >= MAX_SEND_RETRY_NUM)
               {
                    break;
               }
               else
               {
                    delayCnt =0;
                    while(delayCnt < WAIT_DELAY_INIT)
                    {
                        delayCnt ++;
                    }
                }
            }
        }
#if 0        
        NvMTestMsg.control.id = 0xFA0777;
        PrepareNvMTestMsg777(&NvMTestMsg.data.R8[0]);
        /*delay 1 ms to send test message 0xFA0777*/
        currTime = SystemTickMs;
        delayCnt = 0;
        while (1)
        {
            delayCnt ++;
            if( delayCnt > WAIT_DELAY_INIT)
            {
                break;
            }
        }
        CANTransimitRandomMessage(CAN3, &NvMTestMsg);
#endif  
    }
#undef WAIT_A_MSG_SENT
#undef WAIT_DELAY_INIT
#undef MAX_SEND_RETRY_NUM
}

/* =================  public funciton implementation =========================*/
 /*---------------------------------------------------------------------------
 description:   this function intiliaze the application data load save feature 
 input param: void
 output param: NvMAppDataSaveLoadFlag, NvMAppDataStatus
 return value: void 
 ---------------------------------------------------------------------------*/
void usStartTestSaving (void)
{
    /*reset the global handler*/
    memset(&NvMAppDataStatus, 0, sizeof(NvMAppDataStatus));
    /*set current data area and data cursor to 0*/
    NvMAppDataStatus.currAppDataArea = 0;
    NvMAppDataStatus.currDataCursor   = 0;
    /*set the save type to preparing data*/
    /*change global state to saving*/
    NvMAppDataSaveLoadFlag = NvMDataSaving;    

}
 /*---------------------------------------------------------------------------
 description:   this function intiliaze the application data load save feature 
 input param: void
 output param: NvMAppDataSaveLoadFlag, NvMAppDataStatus
 return value: void 
 ---------------------------------------------------------------------------*/
void NVM_AppData_Init(void)
{
     uint32_t DFlashAddr;
     uint16_t readLen;
     boolean validFlag;
     boolean crcOK;
     uint8_t   i,j;
     uint8_t   maxloop=3; 

    NvMAppDataSaveLoadFlag = NvMDataLoading;
    memset(&NvMAppDataStatus, 0, sizeof(NvMAppDataStatus));
    /*read hsitory data form DFLASH in initialize phase*/
    for(i = 0; i < (HIST_DATA_AREA_NUM + ENM_DATA_AREA_NUM); i++)
    {
        DFlashAddr = APP_DATA_DFLASH_ADDR_TBL[i];
        readLen = APP_DATA_ALIGNED_LEN[i];
        for(j=0;j<maxloop;j++)
        {
                FLASH_EE_Read8(DFlashAddr, (uint32_t)readLen, (uint8_t*)APP_DATA_DFLASH_BUF_TBL[i]);  
            
                /*execute the validate check and CRC check for historical data */
                validFlag = NvMAppDataCheckValidFlag(i, (uint8_t*)APP_DATA_DFLASH_BUF_TBL[i]);
                crcOK = NvMAppDataCheckCrc(i, (uint8_t*)APP_DATA_DFLASH_BUF_TBL[i]);
                /*DFlash data checking pass, copy history data to RAM and send to Applayer for usage*/
                if((TRUE == validFlag) && (TRUE == crcOK))
                {
                    (void)memcpy((void*)APP_DATA_RAM_ADDR_TBL[i], (uint8_t*)APP_DATA_DFLASH_BUF_TBL[i], APP_DATA_ACTUAL_LEN[i]);   
                    NvMAppDataStatus.DFlashOK[i] = TRUE;
                    break; /* if success no need read again.*/
                }
                else
                {
                    continue;
                }
        
        }
        if(j>=maxloop)
        {
              /*set false flag after loop 3 times.*/
                NvMAppDataStatus.DFlashOK[i] = FALSE;
         }

    }

    NvMAppDataSaveLoadFlag = NvMDataLoading;
    /*set the error state, then send test message, EEPROM not loaded yet, assume the data is correct*/
    NvMAppDataStatus.errorState = NvMAppDataStatus.errorState |SetErrorStateAndDTCFlag(HIST_DATA_INDEX, NvMAppDataStatus.DFlashOK[HIST_DATA_INDEX], TRUE);
    NvMAppDataStatus.errorState = NvMAppDataStatus.errorState |SetErrorStateAndDTCFlag(ENM_DATA_INDEX, NvMAppDataStatus.DFlashOK[ENM_DATA_INDEX], TRUE);
    NvMAppDataStatus.currAppDataArea = ENM_DATA_INDEX;
    NvMAppDataStatus.currDataCursor = APP_DATA_ALIGNED_LEN[ENM_DATA_INDEX];
    /*both History data and ENM data verified OK, set NvMAppDataSaveLoadFlag to NvMDataLoaded*/
    if((TRUE== NvMAppDataStatus.DFlashOK[HIST_DATA_INDEX]) && (TRUE == NvMAppDataStatus.DFlashOK[ENM_DATA_INDEX]))
    {
        NvMAppDataSaveLoadFlag = NvMDataLoaded; 
    }
    /*VCU bug 1451: Historay data in DFLASH is correct, set SocResiMilgNvMCorrect to 1*/
    if(TRUE == NvMAppDataStatus.DFlashOK[HIST_DATA_INDEX])
    {
        SocResiMilgNvMCorrect = 1;
    }
    SendNvMTestMsg(NvMSaveIdle,  NvMDFlashLoaded, ENM_DATA_INDEX);
    /*start to load EEPROM data from Historical data area*/
    NvMAppDataStatus.currAppDataArea = HIST_DATA_INDEX;
    NvMAppDataStatus.currDataCursor = 0;
    NvMAppDataStatus.OperStartTime = SystemTickMs;  /*record the loading start time, it must be finished in expected time*/
}




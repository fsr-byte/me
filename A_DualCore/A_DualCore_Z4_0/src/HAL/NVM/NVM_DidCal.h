/*
 * NVM.h
 *
 *
 *  Created on: 2018-10-11
 *      Author: ZhouYi
 */

#ifndef NVM_DIDCAL_H_
#define NVM_DIDCAL_H_

#include "typedefs.h"
#include "NVM.h"

#ifdef __NVM_GLOBALS__
#define __NVM_EXTERN__
#else
#define __NVM_EXTERN__  extern
#endif
/* -----------------------------------------------------------------------------
    NVM module  type Definitions
------------------------------------------------------------------------------*/
typedef enum usResult
{
	US_OK = 0, 				/*eep opertion finished*/
	US_FAILED = 1, 			/*eep opertion failed*/
	US_BUSY = 2			/*eep opertion on-going (busy)*/
}usResultType;

#if 0
typedef enum NvMDidCalState
{
	NvMDidCal_None = 0,         /*no DFlash operation work pending for DID*/
	NvMDidCal_WritePending = 1, /*data pending to be written into DFLASH*/
	NvM_ErasingDid  = 2,       /* Erasing DFlash DID block  */
       NvM_ErasingCal  = 3,       /* Erasing DFlash Calibration block */
}NvMDidCalStateType;
#endif

/* -----------------------------------------------------------------------------
    Global Macro Definitions
------------------------------------------------------------------------------*/
#define FLAG_SIZE  8
#define CRC_LEN 4

/*must comply with the definition of bootloader project*/
/* bootloader head use EEPROM [0x00800000, 0x00803FFF] 
 1. BootLoader版本号 （8字节)2. 应用程序有效标志（8字节)3. 外部刷写标志（8字节)4. FingerPrint（8字节) */
 
#define BOOT_VERSION_ADDR     0x00800000           /*bootloader version*/
#define APP_VALID_FALG_ADDR    (BOOT_VERSION_ADDR +8) /*reserve 8 bytes for external programming flag*/ /*application valid flag*/
#define EXT_RPOG_FALG_ADDR       (APP_VALID_FALG_ADDR + 8) 
#define DID_FINGER_PRINT_ADDR  (EXT_RPOG_FALG_ADDR + 8) 

#define APP_VALID_START_OFFSET   8
#define EXT_PROG_START_OFFSET    16
#define DID_FINGER_START_OFFSET  24
#define BOOT_HEAD_LEN  32   /**/
/*must comply with the definition of bootloader project*/

#define DID_DATA_START_ADDR 0x804000
/*DID length: UDS_ECU_SN_LEN(13) + UDS_VIN_LEN(17) + UDS_MANU_DATE_LEN(4) + UDS_FUN_CFG_LEN(6) +UDS_VCU_CFG_LEN(8) +UDS_PEPS_VSK_LEN (16)+ UDS_PEPS_PIN_LEN (4)+ UDS_VCU_CCP_LEN (1)  = 69 */
/*reserve 3 bytes so DID total length = 72,  4 bytes for CRC32, + 4 reserve bytes , 76+4+4= 80  CRC position is 0x48  DID Flag start address is 0x804050*/
#define DID_TOTAL_LENGTH        0x48   /*total DID length 72 bytes (include 3 reserved bytes)*/
#define DID_CRC_ACT_LEN      4     /*DID CRC actual length 4 */
#define DID_CRC_RESERVED        4   /*DID CRC reserved length 4 */
#define DID_FLAG_START_ADDR 0x804050
/*DID length: UDS_ECU_SN_LEN(13) + UDS_VIN_LEN(17) + UDS_MANU_DATE_LEN(4) + UDS_FUN_CFG_LEN(6) +UDS_VCU_CFG_LEN(8) +UDS_PEPS_VSK_LEN (16)+ UDS_PEPS_PIN_LEN (4)+ UDS_VCU_CCP_LEN (1)  + ESCL key (4) = 73 */
/*CRC position index is 0x4C DID Flag start address is 0x804050*/
#define DID_TOTAL_LEN_BTK    0x4C
#define ESCL_FIX_CODE  0xCDF1704C

#define CAL_DATA_PFLASH_ADDR	      0x01000000      /*Calibration data start address in PFLASH*/
#define CAL_PFLASH_END_ADDR       0x0101F7FF
#define CAL_DATA_BLOCK_NUM         50
#define CAL_BLK_RECORD_LEN          12  /*calibration block record = start addr (4bytes) + length (4 bytes) + CRC (4 bytes) */
#define CAL_BLK_RECORD_ADDR       0x0101F800      /*Calibration data block start address/ length and CRC records are stored from here*/

#define CAL_DATA_RAM_ADDR              0x40018500
#define CAL_DATA_SIZE                    0xFB00		//64K-0x500

#define MAX_DFLASH_ERASE_TIME   400   /*it cost about 350ms to erase a DFLASH block, so set the timeout to 400ms*/

__NVM_EXTERN__ uint8_t     SocResiMilgNvMCorrect ;
__NVM_EXTERN__ const uint32_t ESCL_KEY_INIT ;

/*DID relevant interface*/
__NVM_EXTERN__ void NVM_DID_Init(void);
__NVM_EXTERN__ void NVM_CheckCal(void);
__NVM_EXTERN__ void NVM_EraseBlockSync(uint32_t address, uint32_t length);
__NVM_EXTERN__ boolean PepsPinIsInitValue(void);


__NVM_EXTERN__ usResultType usReadDIDDatabyIndex(uint8_t index, uint8_t  pDataRecord[]);
__NVM_EXTERN__ usResultType usWriteDID(uint16_t DID, uint8_t  DataRecord[]);
__NVM_EXTERN__ usResultType usReadPepsPinCode(uint8_t * pDataRecord);
__NVM_EXTERN__ void Write_DIDFromRAM(void);
__NVM_EXTERN__ void WriteEsclKey(uint32_t key);

/*calibration data relevant interface*/
__NVM_EXTERN__ void NVM_Cal_Init(void);
__NVM_EXTERN__ void NvMDTC_SaveTask(void);

#endif /* NVM_DIDCAL_H_ */

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
	US_OK = 0, 				//eep opertion finished
	US_FAILED = 1, 			//eep opertion failed
	US_BUSY = 2			//eep opertion on-going (busy)
}usResultType;

typedef enum NvMDidCalState
{
	NvMDidCal_None = 0,         //no DFlash operation work pending for DID
	NvMDidCal_WritePending = 1, //data pending to be written into DFLASH
	NvM_ErasingDid  = 2,       // Erasing DFlash DID block  
       NvM_ErasingCal  = 3,       // Erasing DFlash Calibration block 
}NvMDidCalStateType;


// -----------------------------------------------------------------------------
//    Global Macro Definitions
//------------------------------------------------------------------------------
#define FLAG_SIZE  8
#define CRC_LEN 4
//must comply with the definition of bootloader project
// bootloader head use EEPROM [0x00800000, 0x00803FFF]
// 1. BootLoader版本号 （8字节)2. 应用程序有效标志（8字节)3. 外部刷写标志（8字节)4. FingerPrint（8字节) 
 
#define BOOT_VERSION_ADDR     0x00800000           //bootloader version
#define APP_VALID_FALG_ADDR    (BOOT_VERSION_ADDR +8) // application valid flag
#define EXT_RPOG_FALG_ADDR       (APP_VALID_FALG_ADDR + 8) //reserve 8 bytes for external programming flag 
#define DID_FINGER_PRINT_ADDR  (EXT_RPOG_FALG_ADDR + 8) 

#define APP_VALID_START_OFFSET   8
#define EXT_PROG_START_OFFSET    16
#define DID_FINGER_START_OFFSET  24
#define BOOT_HEAD_LEN  32   /**/



#define DID_DATA_START_ADDR 0x804000
//DID length: UDS_ECU_SN_LEN(13) + UDS_VIN_LEN(17) + UDS_MANU_DATE_LEN(4) + UDS_FUN_CFG_LEN(6) +UDS_VCU_CFG_LEN(8) +UDS_PEPS_VSK_LEN (16)+ UDS_PEPS_PIN_LEN (4)+ UDS_VCU_CCP_LEN (1) = 69
//reserve 3 bytes so DID total length = 72,  4 bytes for CRC32, + 4 reserve bytes , 72+4+4= 80  so DID Flag start address is 0x804050
#define DID_TOTAL_LENGTH        0x48   //total DID length 72 bytes (include 3 reserved bytes)
#define DID_CRC_ACT_LEN      4     //DID CRC actual length 4 
#define DID_CRC_RESERVED        4   //DID CRC reserved length 4 
#define DID_FLAG_START_ADDR 0x804050




#define CAL_DATA_RAM_ADDR              0x40018500
#define CAL_DATA_SIZE                    0xFB00		//50K-0x500


__NVM_EXTERN__ uint8_t     SocResiMilgNvMCorrect ;

__NVM_EXTERN__ void NVM_DID_Init(void);
__NVM_EXTERN__ void NVM_DIDCal_Task(void);
__NVM_EXTERN__ void NVM_EraseBlockSync(uint32_t address, uint32_t length);
__NVM_EXTERN__ boolean PepsPinIsInitValue(void);


__NVM_EXTERN__ usResultType usReadDIDDatabyIndex(uint8_t index, uint8_t  pDataRecord[]);
__NVM_EXTERN__ usResultType usWriteDID(uint16_t DID, uint8_t  DataRecord[]);
__NVM_EXTERN__ usResultType usWritePepsPinCode(uint8_t DataRecord[]);
__NVM_EXTERN__ usResultType usReadPepsPinCode(uint8_t * pDataRecord);


__NVM_EXTERN__ void NVM_Cal_Init(void);
__NVM_EXTERN__ void ClearCalDataInDFlash(void);
__NVM_EXTERN__ void WriteCalDatalntoDFlash(void);

#endif /* NVM_DIDCAL_H_ */

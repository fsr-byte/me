/*
 *
 * Copyright (c) 2016 Zhou Yi  All Rights Reserved.
 *
 * Copying of this document or code and giving it to others and the
 * use or communication of the contents thereof, are forbidden without
 * expressed authority. Offenders are liable to the payment of damages.
 * All rights reserved in the event of the grant of a invention patent or the
 * registration of a utility model, design or code.
 *
 * Issued by Zhou Yi
 */

/*! @file uds_tp.c
 @brief  brief description on this source file, what is the function to be implemented
 @details details description on the function

  */


#define MASTER_UDS_SERVICE_




/* =====================Includes====================================*/
#include "derivative.h"      /* derivative-specific definitions */
#include "typedefs.h"
#include "CAN_Operation.h"
#include "UDS_Interface.h"
#include "uds_tp.h"
#include "uds_service.h"
#include "NVM.h"
#include <cstring>

#include "PMM_Model_types.h"
#include "Ex_Data.h"
#include "BASE_Global.h"
#include "Modules_Global.h"
#include "DIM_model.h"
#include "Global.h"
/* =====================Private Macro Definitions============================*/
#define UDS_MAX_SEED    10
#define COM_ENA_RXTX     0x0        /*service 28 subfunction enable Rx and Tx*/
#define COM_DIS_RXTX     0x3        /*service 28 subfunction disable Rx and Tx*/
#define COM_NOR_NM        0x3        /*service 28 communication type : normal communication and Network management*/

#define APP_DID_START_POS          21   /*in table UdsSpDidTbl, applicatoin relevant DID start from 21 (0 is first)*/
#define ALLOW_CLR_FAIL      20

#define ALLOW_SECA_FAIL   3

#define DFLASH_SECTOR_SIZE 256   /*only a logical sector size, not the physical feature of the internal DFLASH*/
#define RAM_EXT_PROG_ADDR 0x4003FFF0

#define ESTIMATED_MS_FROMWAKUP_TO_UDSINIT   1550 /*the estimated time (ms) from wakeup to UDS initialize is 1550ms (Twbs + initialize time) */

#define WAKEUP1			FS6500_IO_Input.B.IO_4
#define WAKEUP2			FS6500_IO_Input.B.IO_5

/* =================  Private Variable Declarations =========================*/
CORE0_INIT uint32_t    udsKey=0;                    /*the Key calcuated by UDS layer*/
CORE0_INIT udsSessionType udsCurSession=0;        /*current session*/
CORE0_INIT udsSecAStatusType  currSecAStatus=0;         /*security Access status*/
CORE0_INIT udsResetType     udsResetFlag=0;
CORE0_INIT int8_t    udsResetDelayTimer=0;
CORE0_INIT udsServiceType udsCurrService=0;
CORE0_INIT uint32_t  seedBase=0;                 /*used for srand()*/
CORE0_INIT uint32_t udsExtStartTick=0;            /*timer tick when the extended session is started*/
CORE0_INIT uint32_t  udsExtSessionTimeOut=0;            /*timeout value that keep UDS in extended session*/
CORE0_INIT uint16_t  udsClredDTCCnt=0;             /*clear DTC can't be finished in one task cycle, so we need a global counter*/  
CORE0_INIT uint16_t udsClrDTCFailCnt=0;
CORE0_INIT UDS_CtrlType AppComCtrlType = UDS_EnRx_EnTx;         /*App message control type (for 28 service)*/
CORE0_INIT UDS_CtrlType  NmComCtrlType = UDS_EnRx_EnTx;                    /*Network message control type (for 28 service)*/
CORE0_INIT boolean  udsBusyFlag=0;		    /*Service layer is busy or not*/
CORE0_INIT boolean DisRecordDTC=0;		/*the flag indicating if UDS service DTCControlling is called , used by FaultMatrix module*/
CORE0_INIT boolean pepsPINChecked=0;
CORE0_INIT uint32_t  udsSecAFailedTick=0;   /*when the security Access failed*/
CORE0_INIT uint32_t udsSecAFailedDelayTimer=0;
CORE0_INIT uint8_t  udsSecAFailedCount=0;
CORE0_INIT uint8_t statusTbl[UDS_SNAP_NUM_PER_DTC] = {0};
CORE0_INIT uint32_t servStartTime = 0;                              /*the start time of a service that costs several task cycles, 0x78 should be sent for such UDS service each 5000ms */
CORE0_INIT uint32_t bootResetStartTime=0;
CORE0_INIT uint8_t BootHeadTbl[BOOT_HEAD_LEN] = {0};

CORE0_INIT udsSecAStatusType  currSecAStatus_HWtest = 0;         /*security Access status for HW/aging test*/
CORE0_INIT uint32_t    udsKey_HWtest = 0;                    /*the Key calcuated by UDS layer*/



uint8_t dataBlkSN = 0;
uint32_t uploadAddr = 0;
uint32_t uploadLen = 0;
uint32_t uploadCnt = 0;

/* =================  Private Constant Declarations =========================*/
 /*supported DTC code table*/
 const uint32_t udsSpDTCTbl[UDS_SP_DTC_NUM] = /*ISO15031-6 Figure 8 page 17*/
 {
	/* From 2018.12.28 */
	0x105987, 0xD00587, 0xD00487, 0xD00387, 0xC13187, 0xC19887, 0xC10487, 0xD00287, 0xC14687, 0xC11187,
	0x100116, 0x100217, 0x100316, 0x100417, 0x100517, 0x10062F, 0x10292F, 0x100717, 0x100816, 0x10092F,
	0x101B17, 0x101C16, 0x101D17, 0x101E16, 0x101F2F, 0x102F4B, 0x10237F, 0x10214F, 0x10243F, 0x102531, 
	0x102631, 0x10282F, 0x10304B, 0x105096, 0x105196, 0x105296, 0x105417, 0x105519, 0x105619, 0x105729, 
	0x10584B, 0x106192, 0x106216, 0x106317, 0x106017, 0x106419, 0x106592, 0x106687, 0x106773, 0x106819, 
	0x10691C, 0x106AA5, 0x106B4B, 0x106C4B, 0x106E19, 0x106F29, 0x107029, 0x107329, 0x107829, 0x107929, 
	0x107A29, 0x107B29, 0x108329, 0x103196, 0x103296, 0x103331, 0x103596, 0x103696, 0x103431, 0x103787, 
	0x109196, 0x109296, 0x109396, 0x109496, 0x109596, 0x109696, 0x109796, 0x109896, 0x10A196, 0x10B196, 
	0x10B296,  0x10D096,0x10D396,  0x100A19, 0x100B19, 0x100C19, 0x100D19, 0x100E19, 0x100F19, 0x101019, 
	0x101119,  0x101A19, 0xD10017, 0xD10116, 0xC00188, 0x10D996, 0x102A87, 0xD00D87, 0x108496, 0x109996,
	0X10E84F, 0X10E94F, 0X10E04F, 0X10E14F, 0X10E24F, 0X10E34F, 0X10E44F, 0X10E54F, 0X10E64F, 0X10E74F, 
	0X10EA4F, 0x10C029, 0x10C196, 0x10C296, 0x10C34F, 0x10C44F, 0x10C529, 0x10C64F, 0x10C729, 0x10C896, 
	0x10C996, 0xC19687, 0xC10887, 0xD00687, 0xC16487, 0xD11087, 0x10D196, 0x10D296, 0x10D696, 0x10D796,
	0x10D896, 0X10EB4F, 0X10EC4F, 0X10ED4F, 0x102D46, 0x102E46, 0x10DA96, 0x108529, 0x10EE4F, 0x10EF4F,
	0x107D92, 0x109A92, 0x102746, 0x103846, 0x108629, 0x108729, 0x102B19, 0x102C19, 0x10DB96, 0xC11287,
	0x107492, 0x107516, 0x107692, 0x10774B, 0x107E4A, 0x107F88, 0x108017, 0x108109, 0x108209, 0x108892,
	0x108992, 0x102029, 0x101892, 0x103987, 0x103A87, 0x103B29,  0x101796, 0x101919, 0x10CA4F, 0x101219,
	0x101319, 0x101496, 0x101596, 0x10162F, 0x10FF19, 0x10F04F, 0x10F196, 0x10F229, 0x10F34A, 0x10F496,
	0x10F596, 0x10F699, 0x10F709, 0x10F846, 0x10F996, 0x10FA71, 0x10FB4F, 0x10FC4F, 0x10FD4F, 0x10FE56,
	0x109B16, 0x10CB29, 0x10A587, 0x10A487, 0x10A387, 0x10A687, 0x10A787, 0x10A887, 0x104992
};


/*supported Data Identifier and length*/
const udsDIDType UdsSpDidTbl[UDS_SP_DID_NUM + UDS_HW_TEST_DID_NUM] =
{
    {UDS_FINGER_DID, UDS_FINGER_LEN, FALSE},        /*Finger print can only be written in bootloader*/
    {UDS_SN_DID, UDS_ECU_SN_LEN, TRUE},     /*ECU SN version */
    {UDS_VIN_DID, UDS_VIN_LEN, TRUE},            /*VIN */
    {UDS_MANU_DATE_DID, UDS_MANU_DATE_LEN, TRUE},    /*Vehicle Manufacturing date information */
    {UDS_FUN_CFG_DID, UDS_FUN_CFG_LEN, TRUE},        /*system feature configuration */
    {UDS_VCU_CFG_DID, UDS_VCU_CFG_LEN, TRUE},              /*VCU feature configuration can be written*/
    {UDS_PEPS_VSK_DID, UDS_PEPS_VSK_LEN, TRUE},             /*PEPS VSK code  can be written*/
    {UDS_PEPS_PIN_DID, UDS_PEPS_PIN_LEN, TRUE},             /*PEPS VSK code  can be written*/

    {UDS_VCU_CCP_DID, UDS_VCU_CCP_LEN, TRUE},       /* CCP control*/
    
    {0xF089, UDS_HW_VER_LEN, FALSE},      /*HW version */
    {0xF120, UDS_NET_INFO_LEN, FALSE},        /*networkInformationDataIdentifier*/
    {0xF121, UDS_FUN_INFO_LEN, FALSE},        /*function InformationDataIdentifier*/
    {0xF122, UDS_DIAG_INFO_LEN, FALSE},            /*function InformationDataIdentifier*/
    {0xF083, UDS_APP_SW_VER_LEN, FALSE},         /*supplier defined appication SW version */
    {0xF084, UDS_BOOT_SW_VER_LEN, FALSE},         /*supplier defined bootloader SW version */
    {0xF085, UDS_CAL_SW_VER_LEN, FALSE},         /*supplier defined calibration SW version */
    {0xF193, UDS_ECU_HW_VER_LEN, FALSE},         /*supplier defined ECU HW version */
    {0xF195, UDS_ECU_SW_VER_LEN, FALSE},         /*supplier defined ECU SW version */
    {0xF189, UDS_SW_VER_LEN, FALSE},      /*SW version */
    {0xF187, UDS_PART_LEN, FALSE},          /*Part Number*/
    {0xF18A, UDS_SUPPLIER_LEN, FALSE},    /*supplier */
    /*following DIDs are VCU running data*/
    {0x0A00, UDS_VEH_STATE_LEN, FALSE},         /*Vehicle state  */
    {0x0A01, UDS_KEY_STATE_LEN, FALSE},         /*key state  */
    {0x0A02, UDS_GEAR_STATE_LEN, FALSE},         /*gear state  */
    {0x0A03, UDS_SPEED_PEDAL_LEN, FALSE},         /*speed pedal position x%  */
    {0x0A04, UDS_BRAKE_STATE_LEN, FALSE},         /*brake state  */
    {0x0A05, UDS_ODO_METER_LEN, FALSE},         /*odo meter  */
    {0x0A06, UDS_VEH_SPEED_LEN, FALSE},         /*vehicle speed  */
    {0x0A07, UDS_LOW_BATT_LEN, FALSE},         /*low battery voltage  */
    {0x0A08, UDS_CHG_STATE_LEN, FALSE},         /*charging state */
    {0x0A09, UDS_REQ_TQ_LEN, FALSE},           /*required Torque*/
    {0x0A0A, UDS_ACT_TQ_LEN, FALSE},           /*actual Torque*/
    {0x0A0B, UDS_MCU_TEMP_LEN, FALSE},          /*MCU inverter temperature*/
    {0x0A0C, UDS_MOT_TEMP_LEN, FALSE},          /*MCU motor temperature*/
    {0x0A0D, UDS_ACT_RPM_LEN, FALSE},          /*motor actual speed*/
    {0x0A0E, UDS_BATT_SOC_LEN, FALSE},          /*Battery SOC x%*/
    {0x0A0F, UDS_HV_VOLT_LEN, FALSE},          /*Battery HV voltage*/
    {0x0A10, UDS_HV_CURR_LEN, FALSE},          /*Battery HV current*/
    {0x0A11, UDS_HV_TEMP_LEN, FALSE},          /*Battery HV temperature*/
    {0x0A12, UDS_DCDC_TEMP_LEN, FALSE},        /*DCDC temperature*/
    {0x0A17, 1, FALSE},        /*TBOX -Year*/
    {0x0A18, 1, FALSE},        /*TBOX -Month*/
    {0x0A19, 1, FALSE},        /*TBOX -Day*/
    {0x0A1A, 1, FALSE},        /*TBOX -Hour*/
    {0x0A1B, 1, FALSE},        /*TBOX -Minute*/
    {0x0A1C, 1, FALSE},        /*TBOX -Second*/
    {0x0A1D, 2, FALSE},        /*BMS- ErrorNum*/
    {0x0A1E, 1, FALSE},        /*MCU- ErrorNum*/
	{0x0A20, 1, FALSE},		/*brklightSwitch signal 1,2 */
	{0x0A21, 1, FALSE},		/*Gear switch signal 1,2,3,4 */
	{0x0A22, 2, FALSE},		/*AccelPedal1 High Voltage */
	{0x0A23, 2, FALSE},		/*AccelPedal2 Low Voltage */
	{0x0A24, 2, FALSE},		/*waterpump PWM  duty */
	{0x0A25, 2, FALSE},		/*vacuumpump PWM  frequency */
	{0x0A26, 2, FALSE},		/*collision SRS  duty */
	{0x0A27, 2, FALSE},		/*collision SRS  frequency */
	{0x0A28, 2, FALSE},		/*HVinterlock frequency */
	{0x0A29, 1, FALSE},		/*LspdFan,HspdFan Relay */
	{0x0A2A, 1, FALSE},		/*waterpump Relay */
	{0x0A2B, 1, FALSE},		/*EPB status */
	{0x0A2C, 1, FALSE},		/*EPB request */
	{0x0A2D, 1, FALSE},		/*fast charge awake */
	{0x0A2E, 1, FALSE},		/*slow charge awake */
	{0x0A2F, 1, FALSE},		/*Main Relay */
	{0x0A30, 2, FALSE},			/*AccelPedal1 5v Voltage */
	{0x0A31, 2, FALSE},			/*AccelPedal2 5v Voltage */
	{0x0A32, 1, FALSE},			/*fast charge sensor1 Voltage */
	{0x0A33, 1, FALSE},			/*fast charge sensor2 Voltage */
	{0x0A34, 1, FALSE},			/*VCU-BMS operate mode request */
	{0x0A35, 1, FALSE},			/* BMS operate mode */
	{0x0A36, 2, FALSE},			/*BMS MAX discharge power */
	{0x0A37, 2, FALSE},			/*BMS MAX charge power */
	{0x0A38, 2, FALSE},			/*BMS MAX discharge current */
	{0x0A39, 2, FALSE},			/*BMS MAX charge current */
	{0x0A3A, 2, FALSE},			/*fast charge BMSCC2SngR */
	{0x0A3B, 2, FALSE},			/*slow charge BMSCCSngR */
	{0x0A3C, 1, FALSE},			/*VCU-DCDC status mode request */
	{0x0A3D, 1, FALSE},			/* DCDC operate mode */
	{0x0A3E, 2, FALSE},			/* DCDC output voltage -- LV */
	{0x0A3F, 2, FALSE},			/* DCDC output current -- LV */
	{0x0A40, 2, FALSE},			/* DCDC input voltage -- HV */
	{0x0A41, 1, FALSE},			/* DCDC input current -- HV */
	{0x0A42, 1, FALSE},			/*VCU-MCU operate mode request */
	{0x0A43, 1, FALSE},			/* MCU operate mode */
	{0x0A44, 1, FALSE},			/* MCU electric motor err */
    {0x0A45, 2, FALSE},          /*motor speed request*/
    {0x0A46, 2, FALSE},          /*motor max available torque*/
    {0x0A47, 2, FALSE},          /*motor min available torque*/
    {0x0A48, 2, FALSE},          /*BMS Isolation Resistance*/
	{0x0A49, 1, FALSE},		     /*MCU Relay */
	{0x0A4A, 1, FALSE},		     /*BrakeLight Relay */

    /*following DIDs are only used for production test, must not be stored in DTC snapshot*/
	{UDS_HWTEST_LSCTL_DID, UDS_HWTEST_LSCTL_LEN, TRUE},		/*LS_output*/
	{UDS_HWTEST_HSCTL_DID, UDS_HWTEST_HSCTL_LEN, TRUE},		/*HS_output*/
	{UDS_HWTEST_HBCTL_DID, UDS_HWTEST_HBCTL_LEN, TRUE},		/*HB_out*/
	{UDS_HWTEST_PWMCTL_DID, UDS_HWTEST_PWMCTL_LEN, TRUE},		/*PWMO 1~8*/
	{UDS_HWTEST_CANCTL_DID, UDS_HWTEST_CANCTL_LEN, TRUE},		/*testFrameCtrl: 0 not send; 1 send*/
	{UDS_HWTEST_DINSTS_DID, UDS_HWTEST_DINSTS_LEN, FALSE},	    /*DIN1~31, WakeUP1~2*/
	{UDS_HWTEST_ADCSTS_DID, UDS_HWTEST_ADCSTS_LEN, FALSE},	/*ADC_Out*/
	{UDS_HWTEST_PWMSTS_DID, UDS_HWTEST_PWMSTS_LEN, FALSE},		/*PWM status*/
	{UDS_HWTEST_FLTSTS_DID, UDS_HWTEST_FLTSTS_LEN, FALSE}		/*fault status*/
};

udsIOCTRLDIDType IOCtrlDidTbl[3] =
{
	{UDS_ACTDIAG_MAINRELAY_DID, UDS_ACTDIAG_MAINRELAY_LEN, 0, 0},  /*MainRelay control*/
	{UDS_ACTDIAG_MCURELAY_DID, UDS_ACTDIAG_MCURELAY_LEN, 0, 0},  /*MCURelay control*/
	{UDS_ACTDIAG_BRKLIGHT_DID, UDS_ACTDIAG_BRKLIGHT_LEN, 0, 0}  /*break light control*/
};

const uint8_t EXT_PROG_TBL[FLAG_SIZE] = {0x45, 0x58, 0x54, 0x20, 0x50, 0x52, 0x4F, 0x47};

/* =================  Private Function Declarations =========================*/

udsNRCType udsSessionCtrl(uint8_t newSession);
udsNRCType udsReset(void);
udsNRCType udsTesterPresent(uint8_t subFunction);

udsNRCType udsSeAGetSeed(void);
udsNRCType udsSeACompareKey(void);
void udsCalculateKey(uint32_t seed);
udsNRCType udsCommCtrl(uint8_t subFunction, uint8_t commType);
udsNRCType udsDTCSetting(uint8_t DTCType);
udsNRCType udsReadDID(void);
udsNRCType udsWriteDID(void);
udsNRCType udsClearDTC(void);
udsNRCType udsReadDTC(void);
udsNRCType udsReadDTCNumByMask(uint8_t mask);
udsNRCType udsReadDTCByMask(uint8_t mask);
udsNRCType udsReadDTCSnapId(void);
udsNRCType udsReadDTCSnapByDTCNumber(void);
udsNRCType udsReadDTCExtendedRecord(void);
udsNRCType udsReadSupportedDTC(void);
udsNRCType udsRoutineCtrl(void);
udsNRCType udsReqUpload(void);
udsNRCType udsTransferData(void);
udsNRCType udsTransferExit(void);
udsNRCType usReadCodeFlash(void);
udsNRCType usReadWriteDFlash(void);
udsNRCType usReadWriteExtEE(void);
udsNRCType usClrENMorHistData(void);
udsNRCType SecurityAccess(void);
boolean udsCheckCarAndMotorStopped(void);
udsNRCType udsIOCtrlById(void);
void udsChkWriteExtProgReq(void);
void udsPrepareExtProg(void);
float HAL_Get_ADC(unsigned char Channel) ;
udsNRCType udsSeAGetSeed_HWtest(void);
udsNRCType udsSeACompareKey_HWtest(void);
void udsCalculateKey_HWtest(uint32_t seed);

/* =================  Global Variable Declarations =========================*/
/*variables defined here can be used by other modules*/


/* =================  Global Constant Declarations =========================*/

/* =================  Global Function implementation =========================*/

/*---------------------------------------------------------------------------
description: init module variables 
---------------------------------------------------------------------------*/
void udsServiceInit(void)
{
    udsCurSession = UDS_SESSION_DEFAULT;
    udsResetFlag = UDS_NO_RESET;
    currSecAStatus = UDS_LOCKED_SECA;
    udsResetDelayTimer = -1;
    udsCurrService = UDS_NOP_SERVICE;
    seedBase = 0;
    udsClredDTCCnt = 0;
    DisRecordDTC = FALSE;
    gblUdsECUUpgrade = FALSE;
    gblUdsKeepPresent = FALSE;
    udsClrDTCFailCnt = 0;
    pepsPINChecked = FALSE;
    udsHWTestingModeStatus = 0;
    currSecAStatus_HWtest = UDS_LOCKED_SECA;

    /*read the security Access failed delay timer */
    udsSecAFailedDelayTimer = NVM_ReadSecAFailedCounterAndTimer(&udsSecAFailedCount);
    /*SecA failed delay timer is not 0, record current system timer */
    if(0 != udsSecAFailedDelayTimer)
    {
        /*delay timer must in reasonable range*/
        if(udsSecAFailedDelayTimer <= UDS_SECA_DELAYTIMER)
        {
            /*set faied tick to the estimated time from wakeup to here */
            udsSecAFailedTick = ESTIMATED_MS_FROMWAKUP_TO_UDSINIT;
        }
        /*delay timer not in reasonalbe range, set the failed counter and delay timer to 0*/
        else
        {
            udsSecAFailedCount = 0;
            udsSecAFailedDelayTimer = 0;
        }
    }
    
    udsExtSessionTimeOut = UDS_TEST_EXT_DELAY;

    uploadAddr = 0; 
    uploadLen = 0;
    uploadCnt = 0;
}
/*---------------------------------------------------------------------------
description: this function check if the writing operation of external program equest is finsihed or not
---------------------------------------------------------------------------*/
void udsChkWriteExtProgReq(void)
{
    if(WRITE_EXT_RPOG_FINISHED == NvM_GetWriteExtProgRequestStatus())
    {
        udsResetFlag = UDS_BOOT_RESET;
        udsResetDelayTimer = 2;
        /*prepare positive response and send*/
        tpRspBuf[0] = (uint8_t)UDS_SESSION_CTRL + 0x40;
        tpRspBuf[1] = (uint8_t)udsCurSession;
        /*P2Server and P2*server should be sent in Motorola endian (big endian)*/
        tpRspBuf[2] = (uint8_t)(P2_SERVER>>8);
        tpRspBuf[3] = (uint8_t)(P2_SERVER);
        tpRspBuf[4] = (uint8_t)(P2_STAR_SERVER>>8);
        tpRspBuf[5] = (uint8_t)(P2_STAR_SERVER);
        tpRspLen = 6;   
        udsTpSend(NRC_PR);
    }
    else
    {
        udsResetDelayTimer = UDS_BOOT_DELAY;
        /*send a 0x78*/
        if((SystemTickMs > bootResetStartTime) && ((SystemTickMs - bootResetStartTime) > UDS_0x78_INTERVAL))
        {
            /*continue next trial*/
            bootResetStartTime = SystemTickMs;
            udsTpSend(NRC_RCRRP);
        }
    }

}

/*---------------------------------------------------------------------------
description: this function dwrite external programming flag
1. disable all interrupts 2. write external programming flag; 3. use ASM code jump to bootloader
---------------------------------------------------------------------------*/
void udsPrepareExtProg(void)
{
    /*read boot head*/
    FLASH_EE_Read8(BOOT_VERSION_ADDR, BOOT_HEAD_LEN, BootHeadTbl);
    /*update the external flag */
    (void)memcpy(&BootHeadTbl[EXT_PROG_START_OFFSET], EXT_PROG_TBL, sizeof(EXT_PROG_TBL));

    /*erase the  DFLASH*/
//@@@@@    FLASH_EE_EraseStart(BOOT_VERSION_ADDR, 0x4000);
    NvM_StartWriteExtProgRequest();
    udsResetFlag = UDS_BOOT_PREPARE;
    udsResetDelayTimer = UDS_BOOT_DELAY;
    bootResetStartTime = SystemTickMs;                
}
/*---------------------------------------------------------------------------
description: reset to default diagnosis session:
1. VCU return to lock state
2. return to default session
3. reset DTC setting 
4. App and NM message - enable Tx enable Rx
---------------------------------------------------------------------------*/

void udsResetToDefaultSession(void)
{
    //reset back to default session
    udsCurSession = UDS_SESSION_DEFAULT;
    //reset security status            
    currSecAStatus = UDS_LOCKED_SECA;
    currSecAStatus_HWtest = UDS_LOCKED_SECA;
    /*clear PIN checked flag*/
    pepsPINChecked = FALSE;
    NmComCtrlType  = UDS_EnRx_EnTx;
    AppComCtrlType = UDS_EnRx_EnTx;
    DisRecordDTC = FALSE;
    gblUdsECUUpgrade = FALSE;
    gblUdsKeepPresent = FALSE;
}
/*---------------------------------------------------------------------------
description: cyclical function called by system schedular, this function check if extended session timer is not reset

---------------------------------------------------------------------------*/
void udsServiceTask(void)
{
    seedBase++;
    /*extended session timeout, reset to default state*/
    //if(UDS_SESSION_EXTENDED  == udsCurSession)
    if(UDS_SESSION_DEFAULT  != udsCurSession)	//stt
    {
        if((SystemTickMs -udsExtStartTick) >= udsExtSessionTimeOut)
        {
            udsResetToDefaultSession();
        }
    }
    /*bug 1567: Key off, reset UDs to default state*/
    /*bug 1856: UDS的会话模式不应该因整车电源档位切换而被改变*/
    ///if(0 == INP_output.Hardwire_signal.VINP_IgnitionOn_flg)
    ///{
    ///    udsResetToDefaultSession();
    ///}
    /*security access delay timer expired, clear the failed counter and delay timer to 0*/
    if((udsSecAFailedCount >= ALLOW_SECA_FAIL) && (SystemTickMs > udsSecAFailedTick))
    {
        if((SystemTickMs - udsSecAFailedTick) > udsSecAFailedDelayTimer)
        {
            udsSecAFailedCount = 0;
            udsSecAFailedDelayTimer = 0;
        }
    }
    
    if(udsResetDelayTimer > 0)
    {
        udsResetDelayTimer --;
        if(udsResetDelayTimer <= 0)
        {
            /*reset the system*/
            if(UDS_HARD_RESET == udsResetFlag)
            {
                hwReset();
            }    
            /*stop feed the dog*/
            if (UDS_SOFT_RESET == udsResetFlag )
            {
                hwReset();
            }
            else if( UDS_BOOT_PREPARE == udsResetFlag)
            {
               /*must write external programming request first, then jump to bootloader*/
                udsChkWriteExtProgReq();
            }
            else if( UDS_BOOT_RESET == udsResetFlag)
            {
               hwReset();
            }

        }
    }
    /*if there is pending service, handle it*/
    if((UDS_CLEAR_DTC == udsCurrService) || (UDS_ROUTINE_CTRL == udsCurrService))
    {
        //@@@@tpReqBuf[0] = (uint8_t)udsCurrService;
        //@@@@        tpReqBuf[1] = 0xFF;
        //@@@@        tpReqBuf[2] = 0xFF;
        //@@@@        tpReqBuf[3] = 0xFF;
        udsServiceMain();
    }
}
/*---------------------------------------------------------------------------
description: main function called by UDS TP layer when a vaild service are received completely
input param:         tpReqBuf -- UDS service request PDU 
input param:         tpReqLen -- UDS service request PDU length
---------------------------------------------------------------------------*/
void udsServiceMain(void)
{
    udsNRCType    result;

    /*any service requst will reset the timer*/
    if(UDS_SESSION_EXTENDED  == udsCurSession)
    {
        udsExtStartTick = SystemTickMs;
    } 

    udsCurrService = (udsServiceType)tpReqBuf[0];
   
    switch (udsCurrService)
    {
    case UDS_SESSION_CTRL:
        result = udsSessionCtrl(tpReqBuf[1]);
    break;
    
    case UDS_RESET:
        result = udsReset();
    break;

    case UDS_TESTER_PRESENT:
        result = udsTesterPresent(tpReqBuf[1]);
    break;

    case UDS_SEC_ACCESS:
        result = SecurityAccess();
    break;

    case UDS_COMM_CTRL:
        result = udsCommCtrl(tpReqBuf[1], tpReqBuf[2]);    
    break;

    case UDS_DTC_SET:
        result = udsDTCSetting(tpReqBuf[1]);
    break;

    case UDS_READ_DATA_DID:
        result = udsReadDID();        
    break;

    case UDS_WRITE_DATA_DID:
        result = udsWriteDID();        
    break;

    case UDS_CLEAR_DTC:
        result = udsClearDTC();        
    break;

    case UDS_READ_DTC:
        result = udsReadDTC();        
    break;

    case UDS_ROUTINE_CTRL:
        result = udsRoutineCtrl();
    break;

    case UDS_IO_CTRL:
       result = udsIOCtrlById();
    break;

    case UDS_REQ_UPLOAD:
       result = udsReqUpload();
       break;
       
    case UDS_TRANSFER_DATA:
       result = udsTransferData();  
       break;
       
    case UDS_TRANSFER_EXIT:
       result = udsTransferExit();  
       break;

       default:
        result = NRC_SNS;
    break;

    }

    /*if result is not positive frame, assembley negative response here*/
   // if (NRC_PR != result)
	if ((NRC_PR != result)&&(NRC_NRSP != result))//stt
	{
		tpRspBuf[0] = 0x7F;
		tpRspBuf[1]= (uint8_t)udsCurrService;
		tpRspBuf[2] = (uint8_t)result;
		tpRspLen = 3;   
	}
    /*the ClearDTC service is executed, reset current pending service*/
    /*current command is ClearDTC, we should wait until the EEPROM operation is finished*/
    if(UDS_CLEAR_DTC == udsCurrService)
    {
        /*all DTC cleared or failed to much times*/
        if( (udsClredDTCCnt >= UDS_SP_DTC_NUM) || (NRC_GPF == result) )
        {
            udsClredDTCCnt = 0;
            udsClrDTCFailCnt = 0;
            udsCurrService = UDS_NOP_SERVICE;
        }
    }
    else if(UDS_ROUTINE_CTRL == udsCurrService)
    {
        if((NRC_RCRRP != result) && (NRC_NRSP != result))
        {
            udsCurrService = UDS_NOP_SERVICE;
        }
    }
    else
    {
        udsCurrService = UDS_NOP_SERVICE;
    }
    /*service not supported or request outof range, but the addressing is functional address, don't send negative response*/
    if( (FALSE == phyReqFlag) && ((NRC_SNS == result) || (NRC_ROOR ==result)) )
    {
        result = NRC_NRSP;
    }   
    /*program session entered, no service supported now*/
    if( (UDS_SESSION_PROGRAM == udsCurSession) && (0 == KUDS_SupportOldBoot) && (result != NRC_NRSP) )
    {
        result = NRC_SNSIAS;
    } 
    
    /*send the response by calling TP layer*/
    udsTpSend(result);   
}


/* =================  Private Function implementation =========================*/
/*---------------------------------------------------------------------------
description: check if the  condtions are all true:  car stopped , motor stopped
input param:         VHALI_MCUElecMotSpd, VHALI_ABS_VehicleSpeed 
out param:         null
return value: TRUE--- this 2 conditions are all true; FALSE - one or more condtions are false
---------------------------------------------------------------------------*/
boolean udsCheckCarAndMotorStopped(void)
{
    uint16_t motorSpeed = 0;
    boolean result = TRUE;
    /*convert motor speed to absolute value*/

   // motorSpeed = abs(VINP_MCUElecMotSpd_rpm);
    if(VINP_MCUElecMotSpd_rpm>0)
      {
	motorSpeed = VINP_MCUElecMotSpd_rpm;
      }
    else
      {
	motorSpeed = -VINP_MCUElecMotSpd_rpm;

      }
    /*any of the 3 condition is true, set the return value to false: HV ON,  ABS speed > threshold, motor speed  > threshold*/
    if( (VHALI_ABS_VehicleSpeed > KUDS_ABSStopedSpeed) ||(motorSpeed > KUDS_MotorStopedSpeed) )
    {
       result = FALSE;                            
     }
     return result;
}

/*---------------------------------------------------------------------------
description: session switch: default <---> extended --> program
input param:         tpReqBuf -- UDS service request PDU 
input param:         tpReqLen -- UDS service request PDU length
output param:     tpRspBuf --  positive UDS service response PDU 
output param:     tpRspLen -- positive UDS service response PDU length
return value:         NRC  
---------------------------------------------------------------------------*/

udsNRCType udsSessionCtrl(uint8_t newSession)
{
    udsNRCType NRC = NRC_PR;    
    udsSessionType targetSession;

    targetSession = (udsSessionType)(newSession&0x7F);

	
    /*session control , request length must be 2*/
    if((tpReqLen != UDS_10_REQ_LEN) && (NRC == NRC_PR))
    {
        NRC = NRC_IMLOIF;
    }

    /*NRC check*/
    if( ((targetSession < UDS_SESSION_DEFAULT) || (targetSession > UDS_SESSION_EXTENDED)) && (NRC_PR == NRC) )
    {
        NRC = NRC_SFNS;
    }

    /* ABS speed or  motor speed indicate not stopped,  return 0x22*/    
     if( (FALSE == udsCheckCarAndMotorStopped())&& (NRC_PR == NRC) )
    {
        NRC = NRC_CNC;               
    }    
    if(NRC_PR == NRC)
    {
         /*remove the transistion condition for ALEV bootloader*/
         if(1 == KUDS_SupportOldBoot)
         {
            udsCurSession = targetSession;
            udsExtStartTick = SystemTickMs;
            udsExtSessionTimeOut = UDS_TEST_EXT_DELAY;
            currSecAStatus = UDS_LOCKED_SECA;         /*any session swith will change to Lock state*/
    		currSecAStatus_HWtest = UDS_LOCKED_SECA;
            
        }
        else
        {
            if((UDS_SESSION_PROGRAM == targetSession) && (UDS_SESSION_DEFAULT == udsCurSession))
            {
                  NRC = NRC_SFNS;
            }
            else 
            {
                if(udsCurSession == UDS_SESSION_PROGRAM)
                {
                    NRC = NRC_SNSIAS;
                }
                else
                {
                     if(UDS_SESSION_PROGRAM == targetSession)
                     {
                         /*HV on or car speed > threshold, or motor speed > threshold, return NRC = 0x22*/
                         if( ((FALSE == udsCheckCarAndMotorStopped())||(TRUE == PMM_output.VPMM_HVReady_flg)) && (NRC_PR == NRC) )
                         {
                            NRC = NRC_CNC;                            
                         }
                         else
                         {
                             udsCurSession = targetSession;
                             udsPrepareExtProg();
                             NRC = NRC_RCRRP;
                         }
                     }
                     else
                     {
                         udsCurSession = targetSession;
                         udsExtStartTick = SystemTickMs;
                         currSecAStatus = UDS_LOCKED_SECA;    /*any session swith will change to Lock state*/
    					 currSecAStatus_HWtest = UDS_LOCKED_SECA;
                         if(1 == KUDS_TestFeature)
                         {
                             udsExtSessionTimeOut = UDS_TEST_EXT_DELAY;
                         }
                         else
                         {
                             udsExtSessionTimeOut = UDS_EXTSESSION_TIME;     
                         }
                     }
                }
            }
        }
    }
    if(UDS_SESSION_DEFAULT == udsCurSession)
    {
         udsResetToDefaultSession();     /*bug 1567: return to default session, relevant state should be reseted*/
    }    
    //if(UDS_SESSION_EXTENDED == udsCurSession)
     if(UDS_SESSION_DEFAULT  != udsCurSession)	//stt
    {
        udsExtStartTick = SystemTickMs;
        
    }
    /*check the MSB of sub-function, MSB =1, don't send positive response*/
    if(((newSession &0x80)> 0) && (NRC == NRC_PR))
    {
        NRC = NRC_NRSP;
    }

    /*subfunction not supported or request outof range, or service not supported in the active session, but the addressing is functional address, don't send negative response*/
	//if((FALSE == phyReqFlag)  &&  ((NRC_SFNS == NRC) || (NRC_ROOR ==NRC) || (NRC_SNSIAS ==NRC)) )
	//{
	//	NRC = NRC_NRSP;
	//}


    /*prepare positive response , negative response is prepared in udsServiceMain() in unified pattern*/
    if(NRC_PR == NRC)
    {
        tpRspBuf[0] = (uint8_t)UDS_SESSION_CTRL + 0x40;
        tpRspBuf[1] = (uint8_t)udsCurSession;
        /*P2Server and P2*server should be sent in Motorola endian (big endian)*/
        tpRspBuf[2] = (uint8_t)(P2_SERVER>>8);
        tpRspBuf[3] = (uint8_t)(P2_SERVER);
        tpRspBuf[4] = (uint8_t)(P2_STAR_SERVER>>8);
        tpRspBuf[5] = (uint8_t)(P2_STAR_SERVER);
        tpRspLen = 6;    
    }
        
    return NRC;
}

/*---------------------------------------------------------------------------
description: session switch: only hard reset is supported only exteneded session can execute reset
input param:         tpReqBuf -- UDS service request PDU 
input param:         tpReqLen -- UDS service request PDU length
output param:     tpRspBuf --  positive UDS service response PDU 
output param:     tpRspLen -- positive UDS service response PDU length
return value:         NRC  
---------------------------------------------------------------------------*/
udsNRCType udsReset(void)
{
    uint8_t resetType;
    udsNRCType NRC = NRC_PR;
	
    /*mask out the supress response bit*/
    resetType = tpReqBuf[1]&0x7F;
    if( (UDS_HARD_RESET != resetType) && (UDS_SOFT_RESET != resetType) && (NRC_PR == NRC) && (tpReqLen >= 2) )
    {
        NRC = NRC_SFNS;    
    }
    /*Reset  requst length must be 2 */
    if( (tpReqLen != 2) && (NRC_PR == NRC) )
    {
        NRC  = NRC_IMLOIF;
    }

    /*HV on or car speed > threshold, or motor speed > threshold, return NRC = 0x22*/
    if( ((FALSE == udsCheckCarAndMotorStopped())||(TRUE == PMM_output.VPMM_HVReady_flg))&& (NRC_PR == NRC) )
    {
       NRC = NRC_CNC;                            
    }

    if( ((UDS_SESSION_PROGRAM == udsCurSession) && (0 == KUDS_SupportOldBoot)) && (NRC_PR == NRC) )
    {
        NRC = NRC_SNSIAS;
    }
    if(NRC == NRC_PR)
    {
        /*both hard reset and soft reset  is supported*/
        if( (UDS_HARD_RESET == resetType) || (UDS_SOFT_RESET == resetType) )
        {
        /*!!! perpare to perform reset, after response is sent out, execute reset*/
            udsResetFlag = (udsResetType)(resetType&0x7F);   /*remove the MSB*/
        }
    }

    /*check the MSB of sub-function, MSB =1, don't send positive response*/
    if( ((tpReqBuf[1] &0x80)> 0) && (NRC == NRC_PR) )
    {
        NRC = NRC_NRSP;
    }    
    /*subfunction not supported or request outof range, but the addressing is functional address, don't send negative response*/
    if( (FALSE == phyReqFlag) && ((NRC_SFNS == NRC) || (NRC_ROOR ==NRC) || (NRC_SNSIAS ==NRC)) )
    {
        NRC = NRC_NRSP;
    }      
    /*prepare positive response , negative response is prepared in udsServiceMain() in unified pattern*/
    if(NRC_PR == NRC)
    {
        tpRspBuf[0] = (uint8_t)UDS_RESET  + 0x40;
        tpRspBuf[1] = resetType;
        tpRspLen = 2;
        udsResetDelayTimer = UDS_RESET_DELAY;
    }
    return NRC;
}

/*---------------------------------------------------------------------------
description:  reset udsExtSessionTimer to keep UDS in extended session  if bit 7 of  subfunction is 1, no response should be sent. 
input param:         tpReqBuf -- UDS service request PDU 
input param:         tpReqLen -- UDS service request PDU length
output param:     tpRspBuf --  positive UDS service response PDU 
output param:     tpRspLen -- positive UDS service response PDU length
return value:         NRC  
---------------------------------------------------------------------------*/
udsNRCType udsTesterPresent(uint8_t subFunction)
{
    udsNRCType NRC = NRC_PR;

	/*any service requst will reset the timer*/
	//if(UDS_SESSION_EXTENDED  == udsCurSession)
	if(UDS_SESSION_DEFAULT  != udsCurSession)	//stt
	{
		udsExtStartTick = SystemTickMs;
		udsExtSessionTimeOut = UDS_EXTSESSION_TIME;            
		gblUdsKeepPresent = TRUE;
	} 

	/*test present requst length must be 2 */
	if(tpReqLen != 2)
	{
		NRC = NRC_IMLOIF;
	}
	/*subfunction code must be 0*/
	else if((subFunction&0x7F) != 0) 
	{
		NRC = NRC_SFNS;
	}
	
	/*subfunction not supported or request outof range, or service not supported in the active session, but the addressing is functional address, don't send negative response*/
	if((FALSE == phyReqFlag)  &&  (NRC_PR!=NRC))
	{
		NRC = NRC_NRSP;
		tpRspLen=0;
	}   
	
	if(NRC_PR == NRC)
	{
		if ((subFunction&0x80) == 0)
		{
			tpRspBuf[0] = (uint8_t)UDS_TESTER_PRESENT  + 0x40;
			tpRspBuf[1] = 0;
			tpRspLen = 2;
		}
		else /*check the MSB of sub-function, MSB =1, don't send positive response*/
		{
			tpRspLen = 0;
			NRC = NRC_NRSP;
		}
	}
    	return NRC;
}
/*---------------------------------------------------------------------------
description:   Get security Access Seed , not in security Access status, return seed
input param:         tpReqBuf -- UDS service request PDU 
input param:         tpReqLen -- UDS service request PDU length
output param:     tpRspBuf --  positive UDS service response PDU 
output param:     tpRspLen -- positive UDS service response PDU length
return value:         NRC  
---------------------------------------------------------------------------*/
udsNRCType SecurityAccess(void)
{  
    uint8_t subFun;
    udsNRCType NRC = NRC_PR;

    if(FALSE == phyReqFlag)
    {
       return NRC_NRSP;
    }
    if( (UDS_SESSION_DEFAULT == udsCurSession) && (NRC_PR == NRC) )
    {
        return NRC_SNSIAS;
    }    
    if( (tpReqLen < 2) && (NRC_PR == NRC) )
    {
       return NRC_IMLOIF;
    }
    if( (UDS_SESSION_DEFAULT == udsCurSession) && (NRC_PR == NRC) )
    {
        return NRC_SNSIAS;
    }
    subFun = (tpReqBuf[1]&0x7F);
	if( !HW_udsDiag_flag )
	{
		if(UDS_SECA_GETSEED == subFun)
		{
			NRC = udsSeAGetSeed();
		}
		else if (UDS_SECA_CHKKEY == subFun)
		{
		    NRC = udsSeACompareKey();
		}
		else
		{
			NRC = NRC_SFNS;
		}
	}
	else
	{
		if(UDS_SECA_GETSEED_HWTEST == subFun )
		{
			NRC = udsSeAGetSeed_HWtest();
		}
		else if (UDS_SECA_CHKKEY_HWTEST == subFun )
		{
			  NRC = udsSeACompareKey_HWtest();
		}
		else
		{
			NRC = NRC_SFNS;
		}
	}


    return NRC;
}
/*---------------------------------------------------------------------------
description:   Get security Access Seed , not in security Access status, return seed
input param:         tpReqBuf -- UDS service request PDU 
input param:         tpReqLen -- UDS service request PDU length
output param:     tpRspBuf --  positive UDS service response PDU 
output param:     tpRspLen -- positive UDS service response PDU length
return value:         NRC  
---------------------------------------------------------------------------*/
udsNRCType udsSeAGetSeed(void)
{
    udsNRCType NRC = NRC_PR;
    uint32_t seed = 0;

    /*get seed requst length must be 2 */
    if(tpReqLen != 2)
    {
        return NRC_IMLOIF;
    }
    /*check SecurityAccess delay timer*/
    if( (udsSecAFailedCount >= ALLOW_SECA_FAIL) && (NRC_PR == NRC) )
    {
        NRC = NRC_RTDNE;
    }    
    if(NRC_PR == NRC)
    {

      //  else
        {
            if(UDS_UNLOCK_SECA != currSecAStatus)
            {
                seed = (uint32_t)(SystemTickMs << 24) + (uint32_t)(SystemTickMs << 16) + (uint32_t)(seedBase <<9) + (uint32_t)(seedBase);
                tpRspBuf[0] = (uint8_t)UDS_SEC_ACCESS +0x40;
                tpRspBuf[1] = UDS_SECA_GETSEED;
                tpRspBuf[2] = (uint8_t)(((uint32_t)seed) >> 24);
                tpRspBuf[3] = (uint8_t)(((uint32_t)seed)>> 16);
                tpRspBuf[4] = (uint8_t)(((uint32_t)seed)>> 8);
                tpRspBuf[5] = (uint8_t)(((uint32_t)seed));
                tpRspLen = 6;
                currSecAStatus = UDS_SEED_SECA;
                /*call function to calculate Key*/
                udsCalculateKey((uint32_t)seed);

            }
            /*already in SecurityAccess status, return all zero seed (ISO14229 P52)*/
            else
            {
                tpRspBuf[0] = (uint8_t)UDS_SEC_ACCESS +0x40;
                tpRspBuf[1] = UDS_SECA_GETSEED;
                tpRspBuf[2] = 0;
                tpRspBuf[3] = 0;
                tpRspBuf[4] = 0;
                tpRspBuf[5] = 0;
                tpRspLen = 6;
            }        
        }
    }


    
    //only support in extended session
    if( (UDS_SESSION_EXTENDED != udsCurSession) && (NRC == NRC_PR) )
    {
        NRC = NRC_SNSIAS ;
    }
    return NRC;
}
/*---------------------------------------------------------------------------
description:   compare received key with calculated key in previous step
input param:         tpReqBuf -- UDS service request PDU 
input param:         tpReqLen -- UDS service request PDU length
output param:     tpRspBuf --  positive UDS service response PDU 
output param:     tpRspLen -- positive UDS service response PDU length
return value:         NRC  
---------------------------------------------------------------------------*/
udsNRCType udsSeACompareKey(void)
{
    udsNRCType NRC = NRC_PR;
    
    uint32_t recvKey = 0;            /*received key*/

    /*security Access only be supported in physical addressing*/
    if(FALSE == phyReqFlag)
    {
        return  NRC_NRSP;
    }    
    
    /*compare key requst length must be 6*/
    if( (tpReqLen != 6) && (NRC_PR == NRC) )
    {
        NRC = NRC_IMLOIF;
    }
    if( (UDS_SEED_SECA != currSecAStatus) && (NRC_PR == NRC) )
    {
        NRC = NRC_RSE;
    }
    if( (udsSecAFailedCount >= ALLOW_SECA_FAIL) && (NRC_PR == NRC) )
    {
        NRC = NRC_RTDNE;
    }
    if(NRC_PR == NRC)
    {
        /*get key*/
        recvKey = ((uint32_t)tpReqBuf[2] << 24) + ((uint32_t)tpReqBuf[3] << 16) + ((uint32_t)tpReqBuf[4] << 8) + ((uint32_t)tpReqBuf[5]);        
        /*compare key*/
        if(recvKey!= udsKey)
        {
            NRC = NRC_IK;
            udsSecAFailedCount ++;
            if(udsSecAFailedCount >= ALLOW_SECA_FAIL)
            {
                NRC = NRC_ENOA;
                udsSecAFailedTick = SystemTickMs;
                udsSecAFailedDelayTimer = UDS_SECA_DELAYTIMER;
            }
        }
        else
        {
            udsSecAFailedCount = 0;
            currSecAStatus = UDS_UNLOCK_SECA;
            /*prepare positive response*/
            tpRspBuf[0] = (uint8_t)UDS_SEC_ACCESS +0x40;
            tpRspBuf[1] = UDS_SECA_CHKKEY;
            tpRspLen = 2;
        }
    }
    return NRC;
}
/*---------------------------------------------------------------------------
description:   calculate key based on algorithm from customer, the key point is calculate 32 bits result on 16 bit MCU
input param:         seed
output param:     udsKey --  key calculated based on  customer algorithm
return value:         none  
---------------------------------------------------------------------------*/
void udsCalculateKey(uint32_t seed)
{
    uint32_t tmpseed = 0;
    uint32_t seed_2 = 0;
    uint32_t key_1 = 0;
    uint32_t key_2 = 0;

    tmpseed = seed;
    key_1 = tmpseed ^ UDS_ECU_MASK;

    seed_2 = tmpseed;
    seed_2 = (seed_2 ^ 0x55555555) << 1 ^ (seed_2 ^ 0xAAAAAAAA) >> 1;
    seed_2 = (seed_2 ^ 0x33333333) << 2 ^ (seed_2 ^ 0xCCCCCCCC) >> 2;
    seed_2 = (seed_2 ^ 0x0F0F0F0F) << 4 ^ (seed_2 ^ 0xF0F0F0F0) >> 4;
    seed_2 = (seed_2 ^ 0x00FF00FF) << 8 ^ (seed_2 ^ 0xFF00FF00) >> 8;
    seed_2 = (seed_2 ^ 0x0000FFFF) << 16 ^ (seed_2 ^ 0xFFFF0000) >> 16;

    key_2 = seed_2 & UDS_ECU_MASK;

    udsKey = key_1 + key_2;

}
/*---------------------------------------------------------------------------
description:   Get security Access Seed , not in security Access status, return seed
input param:         tpReqBuf -- UDS service request PDU 
input param:         tpReqLen -- UDS service request PDU length
output param:     tpRspBuf --  positive UDS service response PDU 
output param:     tpRspLen -- positive UDS service response PDU length
return value:         NRC  
---------------------------------------------------------------------------*/
udsNRCType udsSeAGetSeed_HWtest(void)
{
    udsNRCType NRC = NRC_PR;
    uint32_t seed = 0;

    /*get seed requst length must be 2 */
    if(tpReqLen != 2)
    {
        return NRC_IMLOIF;
    }
    /*check SecurityAccess delay timer*/
   /// if(udsSecAFailedCount >= ALLOW_SECA_FAIL && NRC_PR == NRC)
   /// {
   ///     NRC = NRC_RTDNE;
   /// }    
    if(NRC_PR == NRC)
    {

      //  else
        {
            if(UDS_UNLOCK_SECA != currSecAStatus_HWtest)
            {
                seed = (uint32_t)(SystemTickMs << 24) + (uint32_t)(SystemTickMs << 16) + (uint32_t)(seedBase <<9) + (uint32_t)(seedBase);
                tpRspBuf[0] = (uint8_t)UDS_SEC_ACCESS +0x40;
                tpRspBuf[1] = UDS_SECA_GETSEED_HWTEST;
                tpRspBuf[2] = (uint8_t)(((uint32_t)seed) >> 24);
                tpRspBuf[3] = (uint8_t)(((uint32_t)seed)>> 16);
                tpRspBuf[4] = (uint8_t)(((uint32_t)seed)>> 8);
                tpRspBuf[5] = (uint8_t)(((uint32_t)seed));
                tpRspLen = 6;
                currSecAStatus_HWtest = UDS_SEED_SECA;
                /*call function to calculate Key*/
                udsCalculateKey_HWtest((uint32_t)seed);

            }
            /*already in SecurityAccess status, return all zero seed (ISO14229 P52)*/
            else
            {
                tpRspBuf[0] = (uint8_t)UDS_SEC_ACCESS +0x40;
                tpRspBuf[1] = UDS_SECA_GETSEED_HWTEST;
                tpRspBuf[2] = 0;
                tpRspBuf[3] = 0;
                tpRspBuf[4] = 0;
                tpRspBuf[5] = 0;
                tpRspLen = 6;
            }        
        }
    }


    
    //only support in extended session
    if( (UDS_SESSION_EXTENDED !=  udsCurSession) && (NRC == NRC_PR) )
    {
        NRC = NRC_SNSIAS ;
    }
    return NRC;
}
/*---------------------------------------------------------------------------
description:   compare received key with calculated key in previous step
input param:         tpReqBuf -- UDS service request PDU 
input param:         tpReqLen -- UDS service request PDU length
output param:     tpRspBuf --  positive UDS service response PDU 
output param:     tpRspLen -- positive UDS service response PDU length
return value:         NRC  
---------------------------------------------------------------------------*/
udsNRCType udsSeACompareKey_HWtest(void)
{
    udsNRCType NRC = NRC_PR;
    
    uint32_t recvKey = 0;            /*received key*/

    /*security Access only be supported in physical addressing*/
    if(FALSE == phyReqFlag)
    {
        return  NRC_NRSP;
    }    
    
    /*compare key requst length must be 6*/
    if( (tpReqLen != 6) && (NRC_PR == NRC) )
    {
        NRC = NRC_IMLOIF;
    }
    if( (UDS_SEED_SECA != currSecAStatus_HWtest) && (NRC_PR == NRC) )
    {
        NRC = NRC_RSE;
    }
    ///if(udsSecAFailedCount >= ALLOW_SECA_FAIL &&  NRC_PR == NRC)
    ///{
    ///    NRC = NRC_RTDNE;
    ///}
    if(NRC_PR == NRC)
    {
        /*get key*/
        recvKey = ((uint32_t)tpReqBuf[2] << 24) + ((uint32_t)tpReqBuf[3] << 16) + ((uint32_t)tpReqBuf[4] << 8) + ((uint32_t)tpReqBuf[5]);        
        /*compare key*/
        if(recvKey!= udsKey_HWtest)
        {
            ///NRC = NRC_IK;
            ///udsSecAFailedCount ++;
            ///if(udsSecAFailedCount >= ALLOW_SECA_FAIL)
            ///{
            ///    NRC = NRC_ENOA;
            ///    udsSecAFailedTick = SystemTickMs;
            ///    udsSecAFailedDelayTimer = UDS_SECA_DELAYTIMER;
            ///}

            ///udsSecAFailedCount = 0;
                        currSecAStatus_HWtest = UDS_UNLOCK_SECA;
                        /*prepare positive response*/
                        tpRspBuf[0] = (uint8_t)UDS_SEC_ACCESS +0x40;
                        tpRspBuf[1] = UDS_SECA_CHKKEY_HWTEST;
                        tpRspLen = 2;
        }
        else
        {
            ///udsSecAFailedCount = 0;
            currSecAStatus_HWtest = UDS_UNLOCK_SECA;
            /*prepare positive response*/
            tpRspBuf[0] = (uint8_t)UDS_SEC_ACCESS +0x40;
            tpRspBuf[1] = UDS_SECA_CHKKEY_HWTEST;
            tpRspLen = 2;
        }
    }
    return NRC;
}
/*---------------------------------------------------------------------------
description:   calculate key based on algorithm from customer, the key point is calculate 32 bits result on 16 bit MCU
input param:         seed
output param:     udsKey --  key calculated based on  customer algorithm
return value:         none  
---------------------------------------------------------------------------*/
void udsCalculateKey_HWtest(uint32_t seed)
{
    uint32_t tmpseed = 0;
    uint32_t seed_2 = 0;
    uint32_t key_1 = 0;
    uint32_t key_2 = 0;

    tmpseed = seed;
    key_1 = tmpseed ^ UDS_HWTEST_MASK;

    seed_2 = tmpseed;
    seed_2 = (seed_2 ^ 0x55555555) << 1 ^ (seed_2 ^ 0xAAAAAAAA) >> 1;
    seed_2 = (seed_2 ^ 0x33333333) << 2 ^ (seed_2 ^ 0xCCCCCCCC) >> 2;
    seed_2 = (seed_2 ^ 0x0F0F0F0F) << 4 ^ (seed_2 ^ 0xF0F0F0F0) >> 4;
    seed_2 = (seed_2 ^ 0x00FF00FF) << 8 ^ (seed_2 ^ 0xFF00FF00) >> 8;
    seed_2 = (seed_2 ^ 0x0000FFFF) << 16 ^ (seed_2 ^ 0xFFFF0000) >> 16;

    key_2 = seed_2 & UDS_HWTEST_MASK;

    udsKey_HWtest = key_1 + key_2;

}
/*---------------------------------------------------------------------------
description:  set the global variable DisCanRxTxFlag only subfunction 0x00 and 0x03 is supported
            only CommunicationType = 0 is supported, this service only supported in extended session
input param:         tpReqBuf -- UDS service request PDU 
input param:         tpReqLen -- UDS service request PDU length
output param:     tpRspBuf --  positive UDS service response PDU 
output param:     tpRspLen -- positive UDS service response PDU length
output param:     DisCanRxTxFlag
return value:         NRC  
---------------------------------------------------------------------------*/
udsNRCType udsCommCtrl(uint8_t subFunction, uint8_t commType)
{
    uint8_t  tmpSrv28CtrlType = 0;
    uint8_t tmpSrv28ComType = 0;
    udsNRCType NRC = NRC_PR;

    /*check if UDS in extended session*/
    if( (UDS_SESSION_EXTENDED != udsCurSession) && (NRC == NRC_PR) )
    {
        NRC = NRC_SNSIAS ;
    }    
    

    tmpSrv28CtrlType = (uint8_t)(subFunction &0x7F);
    tmpSrv28ComType = (uint8_t)(commType &0x7F);
    /*check subfunciton */
    if( (tpReqLen < 3) && (NRC_PR == NRC) )
    {
        NRC =  NRC_IMLOIF;
    }
    if( (tmpSrv28CtrlType != (uint8_t)UDS_DisRx_DisTx) && (tmpSrv28CtrlType != (uint8_t)UDS_EnRx_EnTx) && (NRC_PR == NRC) )
    {
        NRC = NRC_SFNS;   
    }
    
    /*Communication Control Request length must be 3 */
    if( (tpReqLen > 3) && (NRC_PR == NRC) )
    {
        NRC =  NRC_IMLOIF;
    }
    /*HV on or car speed > threshold, or motor speed > threshold, return NRC = 0x22*/
    if( ((FALSE == udsCheckCarAndMotorStopped())||(TRUE == PMM_output.VPMM_HVReady_flg)) && (NRC_PR == NRC) )
    {
        NRC = NRC_CNC;
    }
    if( ((tmpSrv28ComType > (uint8_t)UDS_NorCom_NetMgr) || (tmpSrv28ComType < (uint8_t)UDS_NorCom)) && (NRC_PR == NRC) )
     {
         NRC = NRC_ROOR;
     }

     if(NRC_PR == NRC)
     {
         /*App communication is being changed  */
         if( 1 ==( tmpSrv28ComType&0x1))
         {
             AppComCtrlType = tmpSrv28CtrlType;
         }
         /*NM communication is being changed */
         if( 2 == ( tmpSrv28ComType&0x2))
         {
             NmComCtrlType = tmpSrv28CtrlType;
         }
     
     }
     /*check the MSB of sub-function, MSB =1, don't send positive response*/
    if( ((subFunction&0x80) >0) && (NRC == NRC_PR) )
    {
        NRC = NRC_NRSP;
    }
    
    /*subfunction not supported or request outof range, or service not supported in the active session, but the addressing is functional address, don't send negative response*/
    if( (FALSE == phyReqFlag) && ((NRC_SFNS == NRC) || (NRC_ROOR ==NRC) || (NRC_SNSIAS ==NRC)) )
    {
        NRC = NRC_NRSP;
    }   
    /*assembly positive response*/
    if(NRC_PR == NRC)
    {
        tpRspBuf[0] = (uint8_t)UDS_COMM_CTRL +0x40;
        tpRspBuf[1] = subFunction;
        tpRspLen = 2;
    }
    return NRC;
}

/*---------------------------------------------------------------------------
description:  set the global variable DisRecordDTC only subfunction 0x01 and 0x02 is supported
            this service only supported in extended session
input param:         tpReqBuf -- UDS service request PDU 
input param:         tpReqLen -- UDS service request PDU length
output param:     tpRspBuf --  positive UDS service response PDU 
output param:     tpRspLen -- positive UDS service response PDU length
output param:     DisCanRxTxFlag
return value:         NRC  
---------------------------------------------------------------------------*/
udsNRCType udsDTCSetting(uint8_t DTCType)
{
    udsNRCType NRC = NRC_PR;
    uint8_t DTCOnOff;
    DTCOnOff = (DTCType&0x7F);
    /*check if UDS in extended session*/
    if( (UDS_SESSION_EXTENDED != udsCurSession) && (NRC_PR == NRC) )
    {
        NRC = NRC_SNSIAS;
    }
    /*lenth < 2,  */
    if( (tpReqLen < 2) && (NRC_PR == NRC) )
    {
        NRC = NRC_IMLOIF;
    }
    if( (UDS_DTC_ON != DTCOnOff) && (UDS_DTC_OFF != DTCOnOff) && (NRC_PR == NRC) )
    {
         NRC = NRC_SFNS;
    }
    if( (tpReqLen > 2) && (NRC_PR == NRC) )
    {
        NRC = NRC_IMLOIF;
    }    
    /*HV on or car speed > threshold, or motor speed > threshold, return NRC = 0x22*/
    if( ((FALSE == udsCheckCarAndMotorStopped())||(TRUE == PMM_output.VPMM_HVReady_flg)) && (NRC_PR == NRC) )
    {
        NRC = NRC_CNC;               
    }
    if(NRC_PR == NRC)
    {
        if (UDS_DTC_ON == (DTCType&0x7F))
        {
            DisRecordDTC = FALSE;
	    gblUdsECUUpgrade = FALSE;
            /*temporary solution before DHP moved to Core 0, clear DTC information if $14 command received from Core 0*/
            currClrDTCCmdFromCore0 = 0;
            /*temporary solution before DHP moved to Core 0, clear DTC information if $14 command received from Core 0*/
        }
        else if (UDS_DTC_OFF == (DTCType&0x7F))
        {
            DisRecordDTC = TRUE;
	    gblUdsECUUpgrade = TRUE;
        }
    }
    /*check the MSB of sub-function, MSB =1, don't send positive response*/
    if( (0 < (DTCType&0x80)) && (NRC == NRC_PR) )
    {
        NRC = NRC_NRSP;
    }
    /*subfunction not supported or request outof range, or service not supported in the active session, but the addressing is functional address, don't send negative response*/
    if( (FALSE == phyReqFlag)  &&  ((NRC_SFNS == NRC) || (NRC_ROOR ==NRC) || (NRC_SNSIAS ==NRC)) )
    {
        NRC = NRC_NRSP;
    }   
    /*assembly positive response*/
    if(NRC_PR == NRC)
    {
        tpRspBuf[0] = (uint8_t)UDS_DTC_SET +0x40;
        tpRspBuf[1] = DTCType;
        tpRspLen = 2;
    }

    return NRC;
}
/*---------------------------------------------------------------------------
description:   read data by identifier. please pay attention to the max response length limit
input param:         tpReqBuf -- UDS service request PDU 
input param:         tpReqLen -- UDS service request PDU length
output param:     tpRspBuf --  positive UDS service response PDU 
output param:     tpRspLen -- positive UDS service response PDU length
output param:     DisCanRxTxFlag
return value:         NRC  
---------------------------------------------------------------------------*/
udsNRCType udsReadDID(void)
{
    uint16_t i = 0, reqLen = 0, remainLen = 0;
    uint16_t  dataId = 0;
    uint8_t dataRecord[UDS_MAX_DID_LEN]= {0};
    boolean bDidFound = 0;
    udsNRCType NRC = NRC_PR;
    usResultType usRslt;
    uint8_t j;
    uint8_t dataTempHWDIN[UDS_HWTEST_DINSTS_LEN] ={0};
    uint8_t dataTempHWADC[UDS_HWTEST_ADCSTS_LEN] ={0};
    uint8_t dataTempHWPWM[UDS_HWTEST_PWMSTS_LEN] ={0};
    uint8_t dataTempHWFLT[UDS_HWTEST_FLTSTS_LEN] ={0};
    uint16_t dataTemp = 0;

    uint8_t RspLen = 1;     /*first byte is 0x62*/

    /*request length check , except the $22, the remaining length should be mod by 2, because DID length is 2*/
    remainLen = tpReqLen -1 ;
    if(remainLen == 0)
    {
        return NRC_IMLOIF;
    }
    /*assume the response is positive, prepare the first bytes here*/
    tpRspBuf[0] = (uint8_t)UDS_READ_DATA_DID + 0x40;
    tpRspLen = 1;
    /*data id start from bye 1 in requst buffer*/
    for (reqLen = 1; reqLen < tpReqLen;)
    {
        dataId = (uint16_t)tpReqBuf[reqLen];
        dataId = dataId << 8;
        dataId += tpReqBuf[reqLen+1];
        bDidFound = FALSE;
        /*search if the data Id is supported id*/
        for (i = 0; i < (UDS_SP_DID_NUM + UDS_HW_TEST_DID_NUM); i++)
        {
            if( (dataId == UdsSpDidTbl[i].DataId) && (UDS_PEPS_PIN_DID != dataId) )
            {
                bDidFound = TRUE;
                /*matched DataID found, response length increased 2*/
                RspLen += sizeof(dataId);
                if( (RspLen + UdsSpDidTbl[i].DataLen)> MAX_UDS_RSP_LEN)
                {
                    NRC = NRC_RTL;
                    break;
                }                
                else 
                {
                    tpRspBuf[tpRspLen] = (uint8_t)(dataId >>8);
                    tpRspLen++;
                    tpRspBuf[tpRspLen] = (uint8_t)(dataId );
                    tpRspLen++;

                    	//for HW testing
                    if( (UDS_HWTEST_DINSTS_DID == dataId) || (UDS_HWTEST_ADCSTS_DID == dataId) || (UDS_HWTEST_PWMSTS_DID == dataId) || (UDS_HWTEST_FLTSTS_DID == dataId) )
                    {
                    	if(!HW_udsDiag_flag)
						{
                    		NRC = NRC_SNS;
                    	    break;
						}
                    	else if(UDS_START_HWTEST != udsHWTestingModeStatus)
                    	 {
                    		 NRC = NRC_GR;
                    		 break;
                    	 }
                    	 else
                    	 {
                    		 if(UDS_HWTEST_DINSTS_DID == dataId)
                    		 {
                    			 for(j=0; j<SW_NUM; j++) /*DIN1--DIN31*/
                    			 {
                    				 if(j%8==0)
                    				 {
                    					 dataTempHWDIN[j/8] = 0;
                    				 }
                    				 dataTempHWDIN[j/8] += (Bios_Sw_Input[j] & (0x1)) << j%8;
                    			 }
                    			 dataTempHWDIN[3] += (WAKEUP1 & 0x1) << 7 ;
                    			 dataTempHWDIN[4] =  WAKEUP2 & 0x1 ;
                    			 (void)memcpy(&tpRspBuf[tpRspLen], dataTempHWDIN, UDS_HWTEST_DINSTS_LEN);
                    			 tpRspLen += UDS_HWTEST_DINSTS_LEN;
                    			 RspLen = tpRspLen;
                    		 }
                    		 else if(UDS_HWTEST_ADCSTS_DID == dataId)
							 {//ADC_Buff

                    		     for(j=0; j<15;j++)
                    			 {
                    				 if(12==j)
                    				 {
                    					 dataTemp = (uint16_t)(HAL_Get_ADC(15-j)*122/22*1000); // for 12v
                    				 }
                    				 else
                    				 {
                    					 dataTemp = (uint16_t)(HAL_Get_ADC(15-j)*1000);
                    				 }
                    				 dataTempHWADC[2*j] = (dataTemp >> 8 ) & 0xFF;
                    				 dataTempHWADC[2*j+1] = dataTemp & 0xFF;
                    			 }
                    			 dataTemp = (uint16_t)(HAL_Get_ADC(23)*1000);
                    			 dataTempHWADC[30] = (dataTemp >> 8 ) & 0xFF;
                    			 dataTempHWADC[31] = dataTemp & 0xFF;
                    			 dataTemp = (uint16_t)(HAL_Get_ADC(24)*122/22*1000); // for 12v
                    			 dataTempHWADC[32] = (dataTemp >> 8 ) & 0xFF;
								 dataTempHWADC[33] = dataTemp & 0xFF;
                    			 dataTemp = (uint16_t)(HAL_Get_ADC(25)*1000);
                    			 dataTempHWADC[34] = (dataTemp >> 8 ) & 0xFF;
								 dataTempHWADC[35] = dataTemp & 0xFF;
                    			 dataTemp = (uint16_t)(HAL_Get_ADC(17)*1000);
                    			 dataTempHWADC[36] = (dataTemp >> 8 ) & 0xFF;
								 dataTempHWADC[37] = dataTemp & 0xFF;
                    			 dataTemp = (uint16_t)(HAL_Get_ADC(27)*1000);
                    			 dataTempHWADC[38] = (dataTemp >> 8 ) & 0xFF;
								 dataTempHWADC[39] = dataTemp & 0xFF;

                    			 /*sen1~3*/
                    			 dataTemp = (uint16_t)(HAL_Get_ADC(0)*1000*2);
								 dataTempHWADC[40] = (dataTemp >> 8 ) & 0xFF;
								 dataTempHWADC[41] = dataTemp & 0xFF;
                    			 dataTemp = (uint16_t)(HAL_Get_ADC(18)*1000*2);
								 dataTempHWADC[42] = (dataTemp >> 8 ) & 0xFF;
								 dataTempHWADC[43] = dataTemp & 0xFF;
                    			 dataTemp = (uint16_t)(HAL_Get_ADC(19)*1000*2);
								 dataTempHWADC[44] = (dataTemp >> 8 ) & 0xFF;
								 dataTempHWADC[45] = dataTemp & 0xFF;

                    			 *((uint16_t *)(&dataTempHWADC[46])) = (uint16_t)(HAL_Get_ADC(22)*2*1000);;//ADC_Buff[22];/*MAX_OUT  5V*/

                    			 /*KL30 A、B*/
                    			 dataTemp = (uint16_t)(HAL_Get_ADC(16)*11*1000);//*11 for 12v
								 dataTempHWADC[48] = (dataTemp >> 8 ) & 0xFF;
								 dataTempHWADC[49] = dataTemp & 0xFF;
                    			 dataTemp = (uint16_t)(HAL_Get_ADC(26)*11*1000);//*11 for 12v
								 dataTempHWADC[50] = (dataTemp >> 8 ) & 0xFF;
								 dataTempHWADC[51] = dataTemp & 0xFF;

								 /*VTS200,180*/
                    			 dataTemp = (uint16_t)(HAL_Get_ADC(21)*1000);
								 dataTempHWADC[52] = (dataTemp >> 8 ) & 0xFF;
								 dataTempHWADC[53] = dataTemp & 0xFF;
                    			 dataTemp = (uint16_t)(HAL_Get_ADC(20)*1000);
								 dataTempHWADC[54] = (dataTemp >> 8 ) & 0xFF;
								 dataTempHWADC[55] = dataTemp & 0xFF;

								 (void)memcpy(&tpRspBuf[tpRspLen], dataTempHWADC, UDS_HWTEST_ADCSTS_LEN);
								 tpRspLen += UDS_HWTEST_ADCSTS_LEN;
								 RspLen = tpRspLen;
							 }
                    		 else if(UDS_HWTEST_PWMSTS_DID == dataId)
							 {

                    			 	 	 //DIN10  no_used
                    			  dataTempHWPWM[3] = ((uint16_t)hIOP_CollisionSw_Hz >> 8) & 0xFF;	//:DIN13 碰撞信号
                    			  dataTempHWPWM[4] = (uint8_t)hIOP_CollisionSw_Hz;
                    			  dataTempHWPWM[5] = (uint8_t)hIOP_CollisionSw_Duty ;
                    			    	//DIN21  no_used
                    			  dataTempHWPWM[9] = ((uint16_t)hIOP_WaterPwm_Hz >> 8) & 0xFF;	//:DIN31 水泵PWM输入
                    			  dataTempHWPWM[10] = (uint8_t)hIOP_WaterPwm_Hz;
                    			  dataTempHWPWM[11] = (uint8_t)hIOP_WaterPwm_Duty ;

                    			  dataTempHWPWM[12] = ((uint16_t)hIOP_HVInterlock_Hz >> 8) & 0xFF;	//:DIN28 高压互锁
                    			  dataTempHWPWM[13] = (uint8_t)hIOP_HVInterlock_Hz;
                    			  dataTempHWPWM[14] = (uint8_t)hIOP_HVInterlock_Duty ;

                    			  dataTempHWPWM[15] = ((uint16_t)hIOP_Fin4_Hz >> 8) & 0xFF;	//:DIN26 真空泵报警信号
                    			  dataTempHWPWM[16] = (uint8_t)hIOP_Fin4_Hz;
                    			  dataTempHWPWM[17] = (uint8_t)hIOP_VacuumPumpIn_Duty ;

                    			 (void)memcpy(&tpRspBuf[tpRspLen], dataTempHWPWM, UDS_HWTEST_PWMSTS_LEN);
								 tpRspLen += UDS_HWTEST_PWMSTS_LEN;
								 RspLen = tpRspLen;
							 }
                    		 else if(UDS_HWTEST_FLTSTS_DID == dataId)
							 {

                    			 *((uint16_t*)(&dataTempHWFLT[0])) = NCV7513B_SO_data.R; //LS
                    			 *((uint16_t*)(&dataTempHWFLT[2])) = NCV7240B_SO_data.R;  //LS

                    			 //HS
                    			 dataTempHWFLT[4] = BTS5180_data[0].openload;
                    			 dataTempHWFLT[5] = BTS5180_data[0].shortload;
                    			 dataTempHWFLT[6] = BTS5180_data[1].openload;
                    			 dataTempHWFLT[7] = BTS5180_data[1].shortload;

                    			 //HS
								 dataTempHWFLT[8] = BTS5200_data[0].openload;
								 dataTempHWFLT[9] = BTS5200_data[0].shortload;
								 dataTempHWFLT[10] = BTS5200_data[1].openload;
								 dataTempHWFLT[11] = BTS5200_data[1].shortload;
								 dataTempHWFLT[12] = BTS5200_data[2].openload;
								 dataTempHWFLT[13] = BTS5200_data[2].shortload;
								 dataTempHWFLT[14] = BTS5200_data[3].openload;
								 dataTempHWFLT[15] = BTS5200_data[3].shortload;

								 //H桥
								 dataTempHWFLT[16] = ((uint16_t)NCV7719_data.CH1_6_recive >> 8) & 0xFF;
								 dataTempHWFLT[17] = (uint8_t)NCV7719_data.CH1_6_recive;
								 dataTempHWFLT[18] = ((uint16_t)NCV7719_data.CH7_8_recive >> 8) & 0xFF;
								 dataTempHWFLT[19] = (uint8_t)NCV7719_data.CH7_8_recive;

								 (void)memcpy(&tpRspBuf[tpRspLen], dataTempHWFLT, UDS_HWTEST_FLTSTS_LEN);
								 tpRspLen += UDS_HWTEST_FLTSTS_LEN;
								 RspLen = tpRspLen;
							 }
                    	 }
                    }
                    else /*call UDS storage module function to get dataRecord of DID*/
                    {
                    	usRslt = usReadDIDDatabyIndex(i, dataRecord);
                    	if(US_OK == usRslt)
                    	{
                    		(void)memcpy(&tpRspBuf[tpRspLen], dataRecord, UdsSpDidTbl[i].DataLen);
                    		tpRspLen += UdsSpDidTbl[i].DataLen;
                        RspLen = tpRspLen;
                    	}
                    	else
                    	{
                    		NRC = NRC_ROOR;
                    		break;
                    	}
                    }
                }
            }
        }
        if(FALSE == bDidFound)
        {
            NRC = NRC_ROOR;            
        }
        /*remaining length in request length must be mod of 2(DID length is 2), multiple DID can be read out in one request*/
        remainLen = tpReqLen -reqLen;
        if( ((0 != remainLen%2) && NRC_PR == NRC) )
        {
            NRC = NRC_IMLOIF;
        }
        
        if(NRC_PR != NRC)
        {
            break;
        }
        else
        {
            /*length of data id is 2 bytes*/
            reqLen += 2;
        }
    }    
    /*subfunction not supported or request outof range, but the addressing is functional address, don't send negative response*/
    if( (FALSE == phyReqFlag) && ((NRC_SFNS == NRC) || (NRC_ROOR ==NRC)) )
    {
        NRC = NRC_NRSP;
    }       
    return NRC;

}
/*---------------------------------------------------------------------------
description:   write data by identifier. must in Security Access state
input param:         tpReqBuf -- UDS service request PDU 
input param:         tpReqLen -- UDS service request PDU length
output param:     tpRspBuf --  positive UDS service response PDU 
output param:     tpRspLen -- positive UDS service response PDU length
output param:     DisCanRxTxFlag
return value:         NRC  
---------------------------------------------------------------------------*/
udsNRCType udsWriteDID(void)
{
    uint8_t i = 0;
    uint16_t  dataId = 0;
    usResultType usRslt = 0;
    boolean bPinIsInitValueFlag = 0;
    udsNRCType NRC = NRC_PR;
    /*ISO 14229-2013 page 164*/
    if(FALSE == phyReqFlag)
    {
       return NRC_SNS;
    }
    
    /*ISO14229-2013, page 173*/
    /*min.length = 4  (2E + DID (2 bytes) + DREC(at least one byte) )*/
    if( tpReqLen < 4)
    {
        NRC= NRC_IMLOIF;
    }
  
    if( (UDS_SESSION_DEFAULT == udsCurSession) && (NRC_PR == NRC) )
    {
        NRC = NRC_SNSIAS;
    }
    usRslt = US_OK;
    /*$2E only be supported if VCU id unlocked and not in default session*/
    if(NRC_PR == NRC)
    {
        /*check the data is supported or not*/
        dataId = (uint16_t)tpReqBuf[1];
        dataId = dataId << 8;
        dataId += tpReqBuf[2];
        for(i = 0; i < (UDS_SP_DID_NUM+UDS_HW_TEST_DID_NUM); i++)
        {
            if(dataId == UdsSpDidTbl[i].DataId)
            {
                break;    
            }
        }
        /*i < UDS_SP_DID_NUM+, it means the data ID is matched*/
        if(i < (UDS_SP_DID_NUM+UDS_HW_TEST_DID_NUM) )
        {
            /*check if the DID can be written*/
            if( (FALSE == UdsSpDidTbl[i].WriteFlag) && (NRC_PR == NRC) )
            {
               NRC = NRC_ROOR;
            }
            /*check the data record  length in request, $2E + DID length  = 3*/
            if( ((tpReqLen - 3) != UdsSpDidTbl[i].DataLen) && (NRC_PR == NRC) )
            {
                NRC = NRC_IMLOIF;
            }
            /*security Accessonly be supported when VCU is unlocked*/
            if( udsHWTestingModeStatus )
            {
                if( (UDS_UNLOCK_SECA != currSecAStatus_HWtest) && (NRC_PR == NRC) )
                {
                    NRC = NRC_SAD;
                }
            }
            else
            {
                if( (UDS_UNLOCK_SECA != currSecAStatus) && (NRC_PR == NRC) )
                {
                    NRC = NRC_SAD;
                }
            }

            /*check the SN data:Month and Date is in range: Month must in [1,12], day must in[1,31] */
            if((UDS_SN_DID == dataId)&& (NRC_PR == NRC) && ((tpReqBuf[14] < 1) || (tpReqBuf[14] >12) ||(tpReqBuf[15] < 1) ||(tpReqBuf[15] > 31)) )
            {
                NRC = NRC_ROOR;
            }
            /*check the Manufacture Date data:Year Month and Date is in range: Year_hight [0,99], Year_Low [0,99] Month must in [1,12], day must in[1,31] */
            if((UDS_MANU_DATE_DID == dataId)&& (NRC_PR == NRC) && ((tpReqBuf[3] > 0x99) || (tpReqBuf[4] >0x99) ||(tpReqBuf[5] < 1) || (tpReqBuf[5] >0x12) ||(tpReqBuf[6] < 1) ||(tpReqBuf[6] > 0x31)) )
            {
                NRC = NRC_ROOR;
            }
            /*car speed > threshold, or motor speed > threshold, return NRC = 0x22*/
            if( (FALSE == udsCheckCarAndMotorStopped()) && (NRC_PR == NRC) )
            {
                NRC = NRC_CNC;               
            }
            if(NRC_PR == NRC)
            {
                if(UDS_PEPS_VSK_DID == dataId)
                {
                    bPinIsInitValueFlag = PepsPinIsInitValue();
                    if( (TRUE == pepsPINChecked) && (FALSE == bPinIsInitValueFlag) )
                    {
                        /* call us storage function to write the data record*/
                        usRslt = usWriteDID(dataId, &tpReqBuf[3]);
                    }
                    else
                    {
                        NRC = NRC_CNC;
                    }
                }
                else if (UDS_PEPS_PIN_DID == dataId)
                {
                    if(pepsPINChecked == TRUE )
                    {
                        usRslt = usWriteDID(dataId, &tpReqBuf[3]);
                        if(US_OK != usRslt)
                        {
                            NRC = NRC_GPF;
                        }
                    }
                    else
                    {
                        NRC = NRC_CNC;
                    }                
                }
                else if( (UDS_HWTEST_LSCTL_DID == dataId) || (UDS_HWTEST_HSCTL_DID == dataId) || (UDS_HWTEST_HBCTL_DID == dataId) || (UDS_HWTEST_PWMCTL_DID == dataId) || (UDS_HWTEST_CANCTL_DID == dataId) )
				{
                	if(!HW_udsDiag_flag)
					{
						NRC = NRC_SNS;
					}
					else if(UDS_START_HWTEST != udsHWTestingModeStatus)
					{
						 NRC = NRC_GR;
					}
					else
					{
						/* call us storage function to write the data record*/
						usRslt = usWriteDID(dataId, &tpReqBuf[3]);
					}
				}
                else
                {
                    /* call us storage function to write the data record*/
                    usRslt = usWriteDID(dataId, &tpReqBuf[3]);
                }
                if(usRslt != US_OK)
                {
                   NRC = NRC_GPF;
                }
                 
            }
        }
        else
        {
            NRC = NRC_ROOR;
        }
    }
    /*assembly positive response*/
    if(NRC_PR == NRC)
    {
        tpRspBuf[0] = (uint8_t)UDS_WRITE_DATA_DID +0x40;
        tpRspBuf[1] = (uint8_t)(dataId >>8);
        tpRspBuf[2] = (uint8_t)(dataId );
        tpRspLen = 3;
    }
    return NRC;
}

/*---------------------------------------------------------------------------
description:   clear DTC , groupOFDTCs=0xFFFFFF
input param:         tpReqBuf -- UDS service request PDU 
input param:         tpReqLen -- UDS service request PDU length
output param:     tpRspBuf --  positive UDS service response PDU 
output param:     tpRspLen -- positive UDS service response PDU length
return value:         NRC  
---------------------------------------------------------------------------*/
udsNRCType udsClearDTC(void)
{
    udsNRCType NRC = NRC_PR;
    usResultType usRslt = 0;
    int i = 0;

    /*clear DTC requst length must be 4 (14 + Group Of DTC(3 bytes))  */
    if(tpReqLen < 4)
    {
        udsClredDTCCnt = UDS_SP_DTC_NUM;
        NRC = NRC_IMLOIF;
    }
    /*both ABS speed and motor speed indicate car is stopped, can enter to programming session*/
    if( (FALSE == udsCheckCarAndMotorStopped()) && (NRC_PR == NRC) )
    {
        udsClredDTCCnt = UDS_SP_DTC_NUM;
        NRC = NRC_CNC;                            
    }

    if( ((tpReqBuf[1] != 0xFF) ||(tpReqBuf[2] != 0xFF) ||(tpReqBuf[3] != 0xFF)) && (NRC_PR == NRC) )
    {
        udsClredDTCCnt = UDS_SP_DTC_NUM;
        NRC = NRC_ROOR;
    }
    if(tpReqLen > 4)
    {
        udsClredDTCCnt = UDS_SP_DTC_NUM;
        NRC = NRC_IMLOIF;
    }




    if(NRC_PR == NRC)
    {
        if(0 == udsClredDTCCnt)
        {
            NRC = NRC_RCRRP;
            (void)usClearRAMDTC();
            servStartTime = SystemTickMs;
        }
        else
        {
            NRC = NRC_NRSP;
        }
        /*call EEPROM layer function to clear DTC: write the Status masks of all DTCs to 0*/
        for(i = udsClredDTCCnt; i < UDS_SP_DTC_NUM ; i++)
        {
            usRslt = usClearEEPROMDTC(udsSpDTCTbl[udsClredDTCCnt], udsClredDTCCnt, 0);
            /*check ExtEEPROM operation result*/
            if(US_OK == usRslt)
            {
                udsClredDTCCnt++;
            }  
            /*EEPROM is busy, break the loop*/
            else if (US_BUSY == usRslt)
            {
                break;
            }
            else if(US_FAILED == usRslt)
            {
                udsClredDTCCnt  =  UDS_SP_DTC_NUM;
                NRC = NRC_GPF;
                break;
            }

            if(1 == udsClredDTCCnt) /*make sure that 0x78 can be sent within 100ms to meet the UDS requirement.*/
            {
                NRC = NRC_RCRRP;
                break;
            }
            /* 0x78 response should be sent in 5000ms. If function */
            if(((SystemTickMs - servStartTime) > UDS_0x78_INTERVAL) && (NRC_GPF != NRC))
            {
                servStartTime = SystemTickMs; //record the time that send 0x78
                NRC = NRC_RCRRP; 
                break;
            }
        }

    }

    if((udsClredDTCCnt >= UDS_SP_DTC_NUM) && (NRC_GPF != NRC)  && (NRC_ROOR != NRC)&& (NRC_IMLOIF != NRC) && (NRC_CNC != NRC))
    {
        NRC = NRC_PR;
    }
    /*subfunction not supported or request outof range, but the addressing is functional address, don't send negative response*/
    if( (FALSE == phyReqFlag) && ((NRC_SFNS == NRC) || (NRC_ROOR ==NRC)) )
    {
        NRC = NRC_NRSP;
    }   
    
    /*assembly positive response*/
    if(NRC_PR == NRC)
    {
        tpRspBuf[0] = (uint8_t)UDS_CLEAR_DTC +0x40;
        servStartTime = 0;
        tpRspLen = 1;      
    }
    /*notify NVM clear DTC operation finished*/
    if(udsClredDTCCnt >= UDS_SP_DTC_NUM)
    {
        usClearDTCFinished();
    }
    return NRC;
}
/*---------------------------------------------------------------------------
description:   read DTC, only subfunction 0x01 and 0x02 are supported
input param:         tpReqBuf -- UDS service request PDU 
input param:         tpReqLen -- UDS service request PDU length
output param:     tpRspBuf --  positive UDS service response PDU 
output param:     tpRspLen -- positive UDS service response PDU length
return value:         NRC  
---------------------------------------------------------------------------*/
udsNRCType udsReadDTC(void)
{
    udsNRCType NRC = NRC_PR;
    uint8_t subFunction = 0;

    subFunction = tpReqBuf[1]&0x7F;

    if(tpReqLen == 1)
    {
         return NRC_IMLOIF;
    }
    if(0x1 == subFunction)
    {
        NRC = udsReadDTCNumByMask(tpReqBuf[2]);
    }
    else if (0x2 == subFunction)
    {
        NRC = udsReadDTCByMask(tpReqBuf[2]);
    }
    else if (0x3 == subFunction)
    {
        NRC = udsReadDTCSnapId();
    }
    else if (0x4 == subFunction)
    {
        NRC = udsReadDTCSnapByDTCNumber();
    }
    else if (0x6 == subFunction)
    {
		NRC = udsReadDTCExtendedRecord();
    }
    else if (0xA == subFunction)
    {
        NRC = udsReadSupportedDTC(); 
    }

    else if (0xB == subFunction)
    {
        if(1 == KUDS_TestFeature)
        {   
             NRC = NRC_PR;
             tpRspBuf[0] = 0x59;
             tpRspBuf[1] = 0xB;
             tpRspLen  = 2;
             //@@@@@usStartTestSaving();
         }
         else
         {
            NRC = NRC_SFNS;
         }    
    }
    
    else if (0xC == subFunction)
    {
        if(1 == KUDS_TestFeature)
        {
            NRC = usReadWriteDFlash();
         }
         else
         {
            NRC = NRC_SFNS;
         }    
    }
    else if (0xD == subFunction)
    {
        if(1 == KUDS_TestFeature)
        {
            NRC = usReadWriteExtEE();
         }
         else
         {
            NRC = NRC_SFNS;
         }
    }    
    else if (0xF == subFunction)
    {
         NRC = usReadCodeFlash();
    }
    else
    {
        NRC = NRC_SFNS;
    }


    /*check Response length*/
    if(tpRspLen > MAX_UDS_RSP_LEN)
    {
        NRC = NRC_RTL;
    }
    /*subfunction not supported or request outof range, but the addressing is functional address, don't send negative response*/
    if( (FALSE == phyReqFlag) && ((NRC_SFNS == NRC) || (NRC_ROOR ==NRC)) )
    {
        NRC = NRC_NRSP;
    }       
    
    /*check the MSB of sub-function, MSB =1, don't send positive response*/
    if( ((tpReqBuf[1] &0x80)> 0) && (NRC == NRC_PR) )
    {
        NRC =  NRC_NRSP;
    }    
    return NRC;
}
/*---------------------------------------------------------------------------
description:   read DTC Numer by status mask
input param:         tpReqBuf -- UDS service request PDU 
input param:         tpReqLen -- UDS service request PDU length
output param:     tpRspBuf --  positive UDS service response PDU 
output param:     tpRspLen -- positive UDS service response PDU length
return value:         NRC  
---------------------------------------------------------------------------*/

udsNRCType udsReadDTCNumByMask(uint8_t mask)
{

    uint16_t i = 0;
    uint8_t reqMask = 0;        /*status mask in request*/
    uint16_t dtcNum = 0;        /*status mask matched DTC Num*/
    usResultType usRslt = 0;
    udsNRCType NRC = NRC_PR;

    /*ReadDTCNumByMask requst length must be 3 */
    if(tpReqLen != 3)
    {
        return NRC_IMLOIF;
    }
  
    dtcNum = 0;
    reqMask = mask;
    reqMask = mask & SP_DTC_STATUS;
    
    for( i = 0; i < UDS_SP_DTC_NUM; i++)
    {
      /*read status mask from UDS storage module*/
        /*reset status table*/
        (void)memset(statusTbl, 0, sizeof(statusTbl));
        usRslt = usReadDTCStaus( i,  statusTbl);
        if(US_OK != usRslt)
        {
            NRC = NRC_ROOR;
            break;
        }        
        /*execute AND operation, if no bit match, the result is 0*/
        if(((statusTbl[0] & reqMask) > 0) || ((statusTbl[1] & reqMask) > 0))
        {
            dtcNum ++;
        }
    }
    /*prepare positive response*/
    tpRspBuf[0] = (uint8_t)UDS_READ_DTC +0x40;
    tpRspBuf[1] = 0x1;    /*sub function = ReportNumberOfDTCByStatusMask*/
    tpRspBuf[2] = SP_DTC_STATUS;    /*Avaliability Mask*/
    tpRspBuf[3] = 0x0;    /*DTCFormatIdentifier  = ISO15031-6 value = 0x0*/
    tpRspBuf[4] = (uint8_t) (dtcNum >> 8);    /*high byte of DTC number */
    tpRspBuf[5] = (uint8_t)dtcNum;    /*DTC number lower byte*/
    tpRspLen = 6;


    return NRC;
}
/*---------------------------------------------------------------------------
description:   read DTC (the 3 bytes code) by status mask
input param:         tpReqBuf -- UDS service request PDU 
input param:         tpReqLen -- UDS service request PDU length
output param:     tpRspBuf --  positive UDS service response PDU 
output param:     tpRspLen -- positive UDS service response PDU length
return value:         NRC  
---------------------------------------------------------------------------*/
udsNRCType udsReadDTCByMask(uint8_t mask)
{
    uint16_t i = 0;
    uint32_t  DTC = 0;
    uint8_t reqMask = 0;        /*status mask in request*/
    usResultType usRslt = 0;

    udsNRCType NRC = NRC_PR;

    /*ReadDTCByMask( requst length must be 3 */
    if(tpReqLen != 3)
    {
        return NRC_IMLOIF;
    }
    reqMask = mask;
    reqMask = mask;
    reqMask = mask & SP_DTC_STATUS;


    tpRspBuf[0] = (uint8_t)UDS_READ_DTC +0x40;
    tpRspBuf[1] = 0x2;   /*sub function = ReportDTCByStatusMask*/
    tpRspBuf[2] = SP_DTC_STATUS;   /*Avaliability Mask: */
    tpRspLen = 3;

    for( i = 0; i < UDS_SP_DTC_NUM; i++)
    {
        /*read status mask from UDS storage module*/
        DTC = udsSpDTCTbl[i];
        /*reset status table*/
        (void)memset(statusTbl, 0, sizeof(statusTbl));
        usRslt = usReadDTCStaus(i,  statusTbl);
        if(US_OK != usRslt)
        {
            NRC = NRC_ROOR;
            break;
        }
                
        /*compare the DTC status with requested mask*/
        /*execute AND operation, if no bit match, the result is 0*/

        if(((statusTbl[0] & reqMask) > 0) || ((statusTbl[1] & reqMask) > 0) )
        {
            tpRspBuf[tpRspLen ]  =(uint8_t) (DTC >>16);
            tpRspBuf[tpRspLen+1]  =(uint8_t) (DTC >> 8);
            tpRspBuf[tpRspLen+2]  =(uint8_t) (DTC);
            tpRspBuf[tpRspLen+3]  =(uint8_t) (statusTbl[0] |statusTbl[1]);
            tpRspLen+= 4;      /*3 bytes DTC + 1 byte DTS status = 4 bytes*/
            if (tpRspLen >= MAX_UDS_RSP_LEN)
            {
                NRC = NRC_RTL;
                break;
            }
        }

    }

    return NRC;
}
/*---------------------------------------------------------------------------
description:   report DTC Snapshot Identification
input param:         tpReqBuf -- UDS service request PDU 
input param:         tpReqLen -- UDS service request PDU length
output param:     tpRspBuf --  positive UDS service response PDU 
output param:     tpRspLen -- positive UDS service response PDU length
return value:         NRC  
---------------------------------------------------------------------------*/

udsNRCType udsReadDTCSnapId(void)
{
    uint16_t i = 0;
    uint8_t u8SnapNum = 0;           /*the snapshot amount with fault information*/
    uint8_t j = 0;
    uint8_t  u8SnapIdTbl[UDS_SNAP_NUM_PER_DTC];
    uint32_t DTC = 0;
    udsNRCType NRC = NRC_PR;

    /*ReadDTCSnapId requst length must be 2 */
    if(tpReqLen != 2)
    {
        return NRC_IMLOIF;
    }    
    tpRspBuf[0] = (uint8_t)UDS_READ_DTC +0x40;
    tpRspBuf[1] = 0x3;        /*sub function = reportDTCSnapshotIdentification*/    
    tpRspLen = 2;
    for(i = 0; i < UDS_SP_DTC_NUM; i++)
    {
        //read the snapshot record id for DTC
        DTC = udsSpDTCTbl[i];
        u8SnapNum = usReadFailedDTCSnapId(DTC, i, u8SnapIdTbl);
        for(j = 0; j < u8SnapNum; j++)
        {
            tpRspBuf[tpRspLen ]  =(uint8_t) (DTC >>16);
            tpRspBuf[tpRspLen+1]  =(uint8_t) (DTC >> 8);
            tpRspBuf[tpRspLen+2]  =(uint8_t) (DTC);
            tpRspBuf[tpRspLen+3]  = (uint8_t)(u8SnapIdTbl[j]+1);
            /*3 bytes DTC + 1 byte DTC snapshot identifier = 4 bytes*/  
            tpRspLen+= 4;                      
        }           
    }
    return NRC;
}
/*---------------------------------------------------------------------------
description:    report DTC Snapshot Record By DTCNumber, send out the snapshot (freeze frame)
according to DTC number and snapshot number
input param:         tpReqBuf -- UDS service request PDU 
input param:         tpReqLen -- UDS service request PDU length
output param:     tpRspBuf --  positive UDS service response PDU 
output param:     tpRspLen -- positive UDS service response PDU length
return value:         NRC  
---------------------------------------------------------------------------*/
udsNRCType udsReadDTCSnapByDTCNumber(void)
{
#define DID_START_IN_SNAP  0
#define TOTAL_DIDS_IN_SNAP   43   /*totally 43 DIDs should be sent out in snapshot record, */
    uint32_t DTC = 0;             // 3 bytes DTC number 
    uint8_t currSnapId;
    uint8_t maxSnapId= 0;
    uint8_t DTCIdx = 0;
    uint8_t i = 0, j = 0;
    uint16_t did = 0;
    uint16_t frameCursor = 0;      //the cursor in frozen frame
    uint8_t freezeFrame[DTC_SNAP_LEN];
    usResultType usRslt = 0;
    udsNRCType NRC = NRC_ROOR;

    /*udsReadDTCSnapByDTCNumber requst length must be 6 (19 04) + DTC (3bytes)+ snapshotIDnumber(1 bytes) */
    if(tpReqLen != 6)
    {
        return NRC_IMLOIF;
    }    

    //get out DTC and snapshot record id
    DTC = 0;
    /*byte 2,3,4 in req is DTC*/
    for(i = 2; i < 5; i++)
    {
        DTC = DTC << 8;
        DTC = DTC + (uint32_t)tpReqBuf[i];
    }

    //check DTC range and snapshot id range, if out of range, return NRC = ROOR
    for(i = 0; i < UDS_SP_DTC_NUM; i++)
    {
        /*matched DTC found*/
        if(DTC == udsSpDTCTbl[i])
        {
            DTCIdx = i;
            NRC = NRC_PR;
            break;
        }
    }
    
    /* check if snapshot id is in the correct range according to ISO14229-2013, recordID start range is [1,FE] or use 0xFF to read all */    
    if( ((tpReqBuf[5] > UDS_SNAP_NUM_PER_DTC) && (tpReqBuf[5] != 0xFF)) || (0 == tpReqBuf[5]) )
    {
        NRC = NRC_ROOR;
    }

    if(NRC_PR != NRC)
    {
        return NRC;
    }
    /*FF read all snapshots for this DTC*/
    if(0xFF == tpReqBuf[5])
    {
       maxSnapId = UDS_SNAP_NUM_PER_DTC;
       currSnapId = 1;
    }
    else
    {
       maxSnapId = tpReqBuf[5] ;
       currSnapId = tpReqBuf[5];
    }
    /*copy DTC and Status first 3 bytes in Freeze frame is DTC, the 4th byte is status*/
    tpRspBuf[0] = (uint8_t)UDS_READ_DTC +0x40;
    tpRspBuf[1] = 0x4;        /*sub function = report DTC Snapshot Record By DTCNumber*/    
    
    tpRspLen = 2;

    /*read DTC status*/
    (void)memset(statusTbl, 0, sizeof(statusTbl));
    usReadDTCStaus( DTCIdx,  statusTbl);
    tpRspBuf[2] = tpReqBuf[2];
    tpRspBuf[3] = tpReqBuf[3];
    tpRspBuf[4] = tpReqBuf[4];
    tpRspBuf[5] =  statusTbl[0] |statusTbl[1];  /* current DTC status*/
    tpRspLen = 6;
    
    /*read snapshot record (freezeframe from UDS storage module)*/
    for(; currSnapId <= maxSnapId; currSnapId++)
    {    
        
        (void)memset(freezeFrame, 0, sizeof(freezeFrame));
        usRslt = usReadSnapshotRecord((uint8_t)i, currSnapId, freezeFrame);
        /*status for specified record is 0, dont' send the record number and DTCSnapshotRecordNumberOfIdentifiers combination*/
        /*ISO14229-2013: The DTCSnapshotRecordNumber and the first dataIdentifier/snapshotData combination in the DTCSnapshotRecord parameter is only present if at least one DTCSnapshot record is available to be reported*/
        if( (1 == currSnapId) && (0 == statusTbl[0]) )
        {
            continue;
        }
        if( (2 == currSnapId) && (0 == statusTbl[1]) )
        {
            continue;
        }
        
        tpRspBuf[tpRspLen] = currSnapId;
        tpRspBuf[tpRspLen+ 1] = TOTAL_DIDS_IN_SNAP;  /*43 DID*/
        tpRspLen = tpRspLen + 2;
        
        /* jump  over the process bytes  */
        frameCursor = DID_START_IN_SNAP;
        /*2 bytes DIDs and its frozen values*/
        for(i = APP_DID_START_POS; i < (UDS_SP_DID_NUM-UDS_NOTSNAPSHOT_DID_NUM); i++)
        {
            /*DID number*/
            did = UdsSpDidTbl[i].DataId;
            tpRspBuf[tpRspLen] = (uint8_t)(did >>8);
            tpRspLen++;
            tpRspBuf[tpRspLen] = (uint8_t)(did);
            tpRspLen++;

            /*DID value*/
            for(j =0; j < (uint16_t)UdsSpDidTbl[i].DataLen; j++)
            {
                tpRspBuf[tpRspLen + j] = freezeFrame[frameCursor+j];
            }
            tpRspLen = tpRspLen + UdsSpDidTbl[i].DataLen;
            frameCursor += j;
        }
    }
    usRslt = NRC;
    return usRslt;
}
/*---------------------------------------------------------------------------
description:    reportSupportedDTCs
according to DTC number and snapshot number
input param:         tpReqBuf -- UDS service request PDU 
input param:         tpReqLen -- UDS service request PDU length
output param:     tpRspBuf --  positive UDS service response PDU 
output param:     tpRspLen -- positive UDS service response PDU length
return value:         NRC  
---------------------------------------------------------------------------*/
udsNRCType udsReadSupportedDTC(void)
{
    udsNRCType NRC = NRC_PR;
    uint16_t i = 0;
    /*ReadDTCByMask( requst length must be 3 */
    if(tpReqLen != 2)
    {
        return NRC_IMLOIF;
    }
    if((tpReqBuf[1]&0x80) > 0)
    {
       return NRC_NRSP;
    }
    tpRspBuf[0] = (uint8_t)UDS_READ_DTC +0x40;
    tpRspBuf[1] = 0xA;    /*sub function = reportSupportedDTCs*/
    tpRspBuf[2] = SP_DTC_STATUS;    /*Avaliability Mask: only bit 0 and bit 3 are supported for staus mask*/
    tpRspLen = 3;
    
    for (i = 0; i < UDS_SP_DTC_NUM; i++)
    {
        //read DTC status byte from storage module one by one
        /*reset status table*/
        (void)memset(statusTbl, 0, sizeof(statusTbl));
        (void)usReadDTCStaus(i, statusTbl);
        tpRspBuf[tpRspLen ]  =(uint8_t) (udsSpDTCTbl[i] >>16);
        tpRspBuf[tpRspLen+1]  =(uint8_t) (udsSpDTCTbl[i] >> 8);
        tpRspBuf[tpRspLen+2]  =(uint8_t) (udsSpDTCTbl[i]);
        tpRspBuf[tpRspLen+3]  =(uint8_t) (statusTbl[0] |statusTbl[1]);
        tpRspLen+= 4;        /*3 bytes DTC + 1 byte DTS status = 4 bytes*/
        if(tpRspLen >= sizeof(tpRspBuf))
        {
            NRC = NRC_RTL;
            break;
        }
    }

    return NRC;
}
/*---------------------------------------------------------------------------
description:    read extended data of a DTC according to DTC number and snapshot number
input param:         tpReqBuf -- UDS service request PDU 
input param:         tpReqLen -- UDS service request PDU length
output param:     tpRspBuf --  positive UDS service response PDU 
output param:     tpRspLen -- positive UDS service response PDU length
return value:         NRC  
---------------------------------------------------------------------------*/
udsNRCType udsReadDTCExtendedRecord(void)
{
    uint32_t DTC = 0;             // 3 bytes DTC number 
    uint8_t i = 0;
    uint8_t DTCIdx = 0;
    uint8_t Occurance = 0;
    uint8_t u8AgingCount = 0;
    udsNRCType NRC = NRC_ROOR;

    /*reportDTCExtendedDataRecordByDTCNumber  requst length must be 6 =  (19 04) + DTC (3bytes)+ extended record(1 bytes) */
    if(tpReqLen != 6)
    {
        return NRC_IMLOIF;
    }    


    //get out DTC and snapshot record id
    DTC = 0;
    /*byte 2,3,4 in req is DTC*/
    for(i = 2; i < 5; i++)
    {
        DTC = DTC << 8;
        DTC = DTC + (uint32_t)tpReqBuf[i];
    }

    //check DTC range and snapshot id range, if out of range, return NRC = ROOR
    for(i = 0; i < UDS_SP_DTC_NUM; i++)
    {
        /*matched DTC found*/
        if(DTC == udsSpDTCTbl[i])
        {
            DTCIdx = i;
            NRC = NRC_PR;
            break;
        }
    }
    
    //only DTC range is corret, then we check if snapshot id is in the correct range
    if(NRC_PR != NRC)
    {
        return NRC;
    }
    /*extended record number is 1 (DTC occurance) or 2 (aging counter), or use 0xFF to read all extended records (in fact only 1)*/
    if((tpReqBuf[5] != 1) &&(tpReqBuf[5] !=2) && (tpReqBuf[5] != 0xFF))
    {
        NRC = NRC_ROOR;
    }

    if(NRC_PR != NRC)
    {
        return NRC;
    }
    /*read DTC status*/
    usReadDTCStaus(DTCIdx,  statusTbl);
    /*prepare the head part of response*/
    tpRspBuf[0] = (uint8_t)UDS_READ_DTC +0x40;
    tpRspBuf[1] = 0x6;        /*sub function = reportDTCExtendedDataRecord By DTCNumber*/    
    tpRspBuf[2] = tpReqBuf[2];
    tpRspBuf[3] = tpReqBuf[3];
    tpRspBuf[4] = tpReqBuf[4];    
    tpRspBuf[5] = statusTbl[0]|statusTbl[1];             

    /*read DTC occurance*/
    Occurance = usReadDTCOccurance(DTCIdx, 1);
    /*read aging counter*/
    u8AgingCount = usReadDTCAgingCounter(DTCIdx,  2);
    if(1 == tpReqBuf[5] )
    {
        tpRspBuf[6] = 1;       
        tpRspBuf[7] = Occurance;         
        tpRspLen = 8;
    }
    else if (2 == tpReqBuf[5])
    {
        tpRspBuf[6] = 1;       
        tpRspBuf[7] = u8AgingCount;         
        tpRspLen = 8;        
    }
    else if (0xFF == tpReqBuf[5])
    {
        tpRspBuf[6] = 1;       
        tpRspBuf[7] = Occurance;         
        tpRspBuf[8] = 2;       
        tpRspBuf[9] = u8AgingCount;         
        tpRspLen = 10;    
    }
    return NRC;
}
/*---------------------------------------------------------------------------
description:   this function handle the routine control service request
input param:         tpReqBuf -- UDS service request PDU 
input param:         tpReqLen -- UDS service request PDU length
output param:     tpRspBuf --  positive UDS service response PDU 
output param:     tpRspLen -- positive UDS service response PDU length
return value:         NRC  
---------------------------------------------------------------------------*/
udsNRCType udsRoutineCtrl(void)
{
    uint16_t routineID;
    uint8_t EEData[UDS_PEPS_PIN_LEN];
    int i;
    uint8_t result = 0;
    uint32_t addrRequest = 0;
    uint32_t addrTemp = 0;
    uint16_t LenRWRequest = 0;
    udsNRCType NRC = NRC_PR;
#define CHECK_PEPS_PIN_REQ_LEN 8  /*check length = $31 $01 + routineID(2 bytes) + PEPS PIN code (4 bytes) = 8 */
#define CHECK_HETEST_CTRL_REQ_LEN 5  /*check length = $31 $01 + routineID(2 bytes) + ctrl code (1 bytes) = 5 */
#define CHECK_HETEST_WRITE_REQ_LEN 18  /*check length = $31 $01 + routineID(2 bytes) + para (14 bytes) = 18 */
#define CHECK_HETEST_READ_REQ_LEN 10  /*check length = $31 $01 + routineID(2 bytes) + para (6 bytes) = 10 */
#define DFLASH_START_ADDRESS	0x00800000
#define DFLASH_END_ADDRESS	0x0083FFFF
#define CHECK_AGINGTEST_CTRL_REQ_LEN 5  /*check length = $31 $01 + routineID(2 bytes) + ctrl code (1 bytes) = 5 */
    uint8_t BuffData[CHECK_HETEST_WRITE_REQ_LEN] = {0};

    if( (FALSE == phyReqFlag) && (NRC_PR == NRC) )
    {
       NRC =  NRC_NRSP;
    }
    if( (UDS_SESSION_EXTENDED != udsCurSession) && (NRC_PR == NRC) )
    {
       NRC = NRC_SNSIAS;
    }
    /*check mininum length*/
    if( (tpReqLen < 4) && (NRC_PR == NRC) )
    {
        NRC = NRC_IMLOIF;
    }

    
    routineID = (uint16_t)tpReqBuf[2];
    routineID = routineID << 8;
    routineID += (uint16_t)tpReqBuf[3];

    /*routine ID check*/
    if(!HW_udsDiag_flag)
    {
        if( (UDS_ERASE_MEM != routineID) && (UDS_CHEK_PEPS_PIN != routineID) && (UDS_ERASE_ESCL != routineID) && (UDS_PROG_ESCL != routineID) && (NRC_PR == NRC) )
        {
            NRC = NRC_ROOR;
        }
    }
    else
    {
	if( (NRC_PR == NRC) && (UDS_HWTEST_CTL != routineID) && (UDS_HWTEST_WRITEDFLASH != routineID) && (UDS_HWTEST_WRITEEEPROM != routineID) && (UDS_HWTEST_READDFLASH != routineID) && (UDS_HWTEST_READEEPROM != routineID) \
		&& (UDS_AGINGTEST_CTL != routineID))
	{
	    NRC = NRC_ROOR;
	}
    }
    /*erase Memory only supported if supporting old bootloader*/
    if( (UDS_ERASE_MEM == routineID) && (1 != KUDS_SupportOldBoot) )
    {
        NRC = NRC_ROOR;
    }

    if(!HW_udsDiag_flag)
    {
        if( (UDS_UNLOCK_SECA != currSecAStatus) && (NRC_PR == NRC) )
        {
            NRC = NRC_SAD;
        }
    }
    else
    {
        if( (UDS_UNLOCK_SECA != currSecAStatus_HWtest) && (NRC_PR == NRC) )
        {
            NRC = NRC_SAD;
        }
    }
    /*check the subfunction it must be: 0x1 == start routine*/
    if( (UDS_START_ROUTINE != tpReqBuf[1]) && (NRC_PR == NRC) )
    {
        NRC = NRC_SFNS;
    }
    /*check the HW-testing subfunction it must be: 0x1 == start HW testing*/
    if( ( /*(UDS_HWTEST_CTL == routineID) ||*/ (UDS_HWTEST_WRITEDFLASH == routineID) || (UDS_HWTEST_WRITEEEPROM == routineID) || (UDS_HWTEST_READDFLASH == routineID) || (UDS_HWTEST_READEEPROM == routineID) ) \
		&& (NRC_PR == NRC) && (UDS_START_HWTEST != udsHWTestingModeStatus) )
    {
	NRC = NRC_GR;
    }

    if( (UDS_CHEK_PEPS_PIN == routineID) && (NRC_PR == NRC) )
    {
        /*check length = $31 $01 + routineID(2 bytes) + PEPS PIN code (4 bytes) = 8 */
        if(tpReqLen != CHECK_PEPS_PIN_REQ_LEN)
        {
            NRC = NRC_IMLOIF;
        }

        if( (FALSE == udsCheckCarAndMotorStopped()) && (NRC_PR == NRC) )
        {
            NRC = NRC_CNC;
        }
        else
        {
            usReadPepsPinCode(EEData);
            result = UDS_CHK_PIN_OK;
            pepsPINChecked = TRUE;
            for(i = 0; i < UDS_PEPS_PIN_LEN; i++)
            {
                if(EEData[i] != tpReqBuf[i+4])
                {
                    result = UDS_CHK_PIN_NOK;
                    pepsPINChecked = FALSE;
                    break;
                }
            }
        }
    }
	
    if( UDS_AGINGTEST_CTL == routineID ) //NRC_SNS not the HW aging test ID in extended frame
    {
        if(udsHWTestingModeStatus)//老化测试和硬件测试不可以共存，如果已经启动老化测试，不可以再次启动硬件测试，反之亦然。
        {
            NRC = NRC_RSE;
        }

        if( (NRC_PR == NRC) && (tpReqLen != CHECK_AGINGTEST_CTRL_REQ_LEN) ) /*check length = $31 $01 + routineID(2 bytes) + ctrl code (1 bytes) = 5 */
        {
            NRC = NRC_IMLOIF;
        }

        if(NRC_PR == NRC)
        {
            if(tpReqBuf[4] == 1)
            {
                bool_udsAgingTestStart_flag = 1;
                
            }
            else
            {
               bool_udsAgingTestStart_flag = 0;
            }
        }
    }

    if( (UDS_HWTEST_CTL == routineID) || (UDS_HWTEST_WRITEDFLASH == routineID) || (UDS_HWTEST_WRITEEEPROM == routineID) || (UDS_HWTEST_READDFLASH == routineID) || (UDS_HWTEST_READEEPROM == routineID) ) //not the HW test ID in extended frame
    {
        if(bool_udsAgingTestStart_flag)//老化测试和硬件测试不可以共存，如果已经启动老化测试，不可以再次启动硬件测试，反之亦然。
        {
            NRC = NRC_RSE;
        }
		
	if( (UDS_HWTEST_CTL == routineID) && (NRC_PR == NRC) )
	{
		/*check length = $31 $01 + routineID(2 bytes) + ctrl code (1 bytes) = 5 */
		if(tpReqLen != CHECK_HETEST_CTRL_REQ_LEN)
		{
			NRC = NRC_IMLOIF;
		}

		if(NRC_PR == NRC)
		{
		    if(tpReqBuf[4] == 1)
		    {
			udsHWTestingModeStatus = UDS_START_HWTEST;
			EnetTestMaster = 1;//开启以太网测试
		    }
		    else
		    {
			udsHWTestingModeStatus = 0;
			EnetTestMaster = 0;//关闭以太网测试
		    }
		}
	}
	if( (UDS_HWTEST_WRITEDFLASH == routineID) && (NRC_PR == NRC) )
	{
		if(tpReqLen != CHECK_HETEST_WRITE_REQ_LEN)
		{
			NRC = NRC_IMLOIF;
		}
		else
		{
			addrRequest = 0x0;
			addrTemp = 0x0;
			addrTemp = (uint32_t)tpReqBuf[4];
			addrRequest += addrTemp << 24;
			addrTemp = (uint32_t)tpReqBuf[5];
			addrRequest += addrTemp << 16;
			addrTemp = (uint32_t)tpReqBuf[6];
			addrRequest += addrTemp << 8;
			addrRequest += (uint32_t)tpReqBuf[7];

			LenRWRequest = (uint16_t)tpReqBuf[8];
			LenRWRequest = LenRWRequest << 8;
			LenRWRequest += (uint16_t)tpReqBuf[9];
			if(LenRWRequest > 8)
				LenRWRequest = 8;

			if( (addrRequest <= DFLASH_END_ADDRESS) && (addrRequest >= DFLASH_START_ADDRESS) && (addrRequest+LenRWRequest <= DFLASH_END_ADDRESS) )
			{
				FLASH_EE_Write8(addrRequest, LenRWRequest, &tpReqBuf[10]);
			}
			else
			{
				NRC = NRC_GPF;
			}
		}
	}
	if( (UDS_HWTEST_WRITEEEPROM == routineID) && (NRC_PR == NRC) )
	{
		if(tpReqLen != CHECK_HETEST_WRITE_REQ_LEN)
		{
			NRC = NRC_IMLOIF;
		}
		else
		{
			addrRequest = 0x0;
			addrTemp = 0x0;
			addrTemp = (uint32_t)tpReqBuf[4];
			addrRequest += addrTemp << 24;
			addrTemp = (uint32_t)tpReqBuf[5];
			addrRequest += addrTemp << 16;
			addrTemp = (uint32_t)tpReqBuf[6];
			addrRequest += addrTemp << 8;
			addrRequest += (uint32_t)tpReqBuf[7];

			LenRWRequest = (uint16_t)tpReqBuf[8];
			LenRWRequest = LenRWRequest << 8;
			LenRWRequest += (uint16_t)tpReqBuf[9];
			if(LenRWRequest > 8)
				LenRWRequest = 8;

			if( 0 != WriteExtEE(addrRequest, LenRWRequest, &tpReqBuf[10]) ) /*0x0000~~0x3FFF*/
			{
				NRC = NRC_GPF;
			}
		}
	}
	if( (UDS_HWTEST_READDFLASH == routineID) && (NRC_PR == NRC) )
	{
		if(tpReqLen != CHECK_HETEST_READ_REQ_LEN)
		{
			NRC = NRC_IMLOIF;
		}
		else
		{
			addrRequest = 0x0;
			addrTemp = 0x0;
			addrTemp = (uint32_t)tpReqBuf[4];
			addrRequest += addrTemp << 24;
			addrTemp = (uint32_t)tpReqBuf[5];
			addrRequest += addrTemp << 16;
			addrTemp = (uint32_t)tpReqBuf[6];
			addrRequest += addrTemp << 8;
			addrRequest += (uint32_t)tpReqBuf[7];

			LenRWRequest = (uint16_t)tpReqBuf[8];
			LenRWRequest = LenRWRequest << 8;
			LenRWRequest += (uint16_t)tpReqBuf[9];

			if( (addrRequest <= DFLASH_END_ADDRESS) && (addrRequest >= DFLASH_START_ADDRESS) && (addrRequest+LenRWRequest <= DFLASH_END_ADDRESS) )
			{
				FLASH_EE_Read8(addrRequest, LenRWRequest, &(BuffData[0]));
			}
			else
			{
				NRC = NRC_GPF;
			}
		}
	}
	if( (UDS_HWTEST_READEEPROM == routineID) && (NRC_PR == NRC) )
	{
		if(tpReqLen != CHECK_HETEST_READ_REQ_LEN)
		{
			NRC = NRC_IMLOIF;
		}
		else
		{
			addrRequest = 0x0;
			addrTemp = 0x0;
			addrTemp = (uint32_t)tpReqBuf[4];
			addrRequest += addrTemp << 24;
			addrTemp = (uint32_t)tpReqBuf[5];
			addrRequest += addrTemp << 16;
			addrTemp = (uint32_t)tpReqBuf[6];
			addrRequest += addrTemp << 8;
			addrRequest += (uint32_t)tpReqBuf[7];

			LenRWRequest = (uint16_t)tpReqBuf[8];
			LenRWRequest = LenRWRequest << 8;
			LenRWRequest += (uint16_t)tpReqBuf[9];

			if( 0 != ReadExtEE(addrRequest, LenRWRequest, &(BuffData[0])) )
			{
				NRC = NRC_GPF;
			}
		}
	}
    }

    /**************************BTK  and ESCL  ***************************************************/
    /*program ESCL key , erase ESCL key , violent erase ESCL key*/
    if((UDS_PROG_ESCL == routineID) || (UDS_ERASE_ESCL == routineID) || (UDS_FORCE_ERASE_ESCL == routineID))
    {
        if (0  == servStartTime)   /*the udsRoutineCtrl() is called for ESCL as the first time */
        {
            if(BTK_ESCL_BUSY != gblEsclRslt)
            {
                NRC = NRC_RCRRP;
                servStartTime = SystemTickMs;
                if(UDS_PROG_ESCL == routineID)
                {
                    gblEsclOperReq = BTK_ESCL_PROGKEY;
                    (void)memcpy(&newEsclKey, &tpReqBuf[4], sizeof(newEsclKey));  /*copy the new ESCL key*/
                }
                else if (UDS_ERASE_ESCL == routineID)
                {
                    gblEsclOperReq = BTK_ESCL_ERASEKEY;
                }
                else if (UDS_FORCE_ERASE_ESCL == routineID)
                {
                    gblEsclOperReq = BTK_ESCL_FORCEERASE;
                }
            }
            else
            {
                result = UDS_ESCL_BUSY;
                NRC = NRC_PR;
            }
        }
        else
        {
            if(BTK_ESCL_SUCCESS == gblEsclRslt)
            {
               if((SystemTickMs - servStartTime) > ESCL_MIN_OPER_TIME) /*wait for minimum ESCL operation time in case of  the core1 and core 0 are async*/
               {
                    result = UDS_ESCL_SUCCESS;
                    NRC = NRC_PR;
                    /*new key programmed, save to DFlash*/
                    if(BTK_ESCL_PROGKEY == gblEsclOperReq)
                    {
                        WriteEsclKey(newEsclKey);
                    }
                    else if ((BTK_ESCL_ERASEKEY == gblEsclOperReq) || (BTK_ESCL_FORCEERASE == gblEsclOperReq))
                    {
                        WriteEsclKey(ESCL_KEY_INIT);   /*reset the ESCL key to default value*/
                    }
                    servStartTime = 0;
                    gblEsclOperReq = BTK_ESCL_NOCMD;   /*clear the UDS ESCL request*/
                }
                else
                {
                    NRC = NRC_NRSP;
                }
            }
            else if (BTK_ESCL_BUSY == gblEsclRslt)
            {
                 /*send out another  0x78*/
                 if((SystemTickMs - servStartTime) > UDS_0x78_INTERVAL) 
                 {
                     NRC = NRC_RCRRP;
                     servStartTime = SystemTickMs;
                 }
                 else
                 {
                     NRC = NRC_NRSP;
                 }
            }
            else 
            {  
            if( (SystemTickMs -servStartTime) >50 )
            	{
                NRC = NRC_PR;
                result = UDS_ESCL_FAILED;
                servStartTime = 0;
                gblEsclOperReq = BTK_ESCL_NOCMD;   /*clear the UDS ESCL request*/
            	}
            }
          }
        if(NRC_PR == NRC)
        {
            tpRspBuf[0] = (uint8_t)UDS_ROUTINE_CTRL + 0x40;
            tpRspBuf[1] = tpReqBuf[1];
            /*routine ID*/
            tpRspBuf[2] = tpReqBuf[2];
            tpRspBuf[3] = tpReqBuf[3];
            tpRspBuf[4] = result;
            tpRspLen = 5; 
        }
    }
    /**************************BTK  and ESCL  ***************************************************/
    
    /*create positive response*/
    if (NRC_PR == NRC)
    {
        if(UDS_ERASE_MEM == routineID)
        {
            NRC = NRC_RCRRP;
        }
        else if (UDS_CHEK_PEPS_PIN == routineID)
        {
            tpRspBuf[0] = (uint8_t)UDS_ROUTINE_CTRL + 0x40;
            tpRspBuf[1] = tpReqBuf[1];
            /*routine ID*/
            tpRspBuf[2] = tpReqBuf[2];
            tpRspBuf[3] = tpReqBuf[3];
            tpRspBuf[4] = result;
            tpRspLen = 5;        
        }
        else if (UDS_HWTEST_CTL == routineID)
        {
        	tpRspBuf[0] = (uint8_t)UDS_ROUTINE_CTRL + 0x40;
			tpRspBuf[1] = tpReqBuf[1];
			/*routine ID*/
			tpRspBuf[2] = tpReqBuf[2];
			tpRspBuf[3] = tpReqBuf[3];
			tpRspBuf[4] = udsHWTestingModeStatus;
			tpRspLen = 5;
        }
        else if (UDS_HWTEST_WRITEDFLASH == routineID)
        {
        	tpRspBuf[0] = (uint8_t)UDS_ROUTINE_CTRL + 0x40;
			tpRspBuf[1] = tpReqBuf[1];

			(void)memcpy(&tpRspBuf[2], &tpReqBuf[2], 8); /*DID+addr+len*/
			(void)memcpy(&tpRspBuf[10], &tpReqBuf[10], LenRWRequest);
			tpRspLen = 10+LenRWRequest;
        }
        else if (UDS_HWTEST_WRITEEEPROM == routineID)
        {
        	tpRspBuf[0] = (uint8_t)UDS_ROUTINE_CTRL + 0x40;
			tpRspBuf[1] = tpReqBuf[1];

			(void)memcpy(&tpRspBuf[2], &tpReqBuf[2], 8); /*DID+addr+len*/
			(void)memcpy(&tpRspBuf[10], &tpReqBuf[10], LenRWRequest);
			tpRspLen = 10+LenRWRequest;
        }
        else if (UDS_HWTEST_READDFLASH == routineID)
        {
        	tpRspBuf[0] = (uint8_t)UDS_ROUTINE_CTRL + 0x40;
			tpRspBuf[1] = tpReqBuf[1];

			(void)memcpy(&tpRspBuf[2], &tpReqBuf[2], 8); /*DID+addr+len*/
			(void)memcpy(&tpRspBuf[10], &BuffData, LenRWRequest);
			tpRspLen = 10+LenRWRequest;
        }
        else if (UDS_HWTEST_READEEPROM == routineID)
        {
        	tpRspBuf[0] = (uint8_t)UDS_ROUTINE_CTRL + 0x40;
			tpRspBuf[1] = tpReqBuf[1];

			(void)memcpy(&tpRspBuf[2], &tpReqBuf[2], 8); /*DID+addr+len*/
			(void)memcpy(&tpRspBuf[10], &BuffData, LenRWRequest);
			tpRspLen = 10+LenRWRequest;
        }
        else if (UDS_AGINGTEST_CTL == routineID)
        {
        	tpRspBuf[0] = (uint8_t)UDS_ROUTINE_CTRL + 0x40;
			tpRspBuf[1] = tpReqBuf[1];
			/*routine ID*/
			tpRspBuf[2] = tpReqBuf[2];
			tpRspBuf[3] = tpReqBuf[3];
			tpRspBuf[4] = bool_udsAgingTestStart_flag;
			tpRspLen = 5;
        }
    
    }

    return NRC;
}

/*---------------------------------------------------------------------------
description:   this function handle the  InputOutputControlByIdentifier service request
input param:         tpReqBuf -- UDS service request PDU 
input param:         tpReqLen -- UDS service request PDU length
output param:     tpRspBuf --  positive UDS service response PDU 
output param:     tpRspLen -- positive UDS service response PDU length
return value:         NRC  
---------------------------------------------------------------------------*/
udsNRCType udsIOCtrlById(void)
{
    udsNRCType NRC = NRC_PR;
    uint16_t IOCtrlID = 0;
    uint8_t IOCtrlType = 0;
    uint8_t IOCtrlStatus = 0;

    if( (FALSE == phyReqFlag) && (NRC_PR == NRC) )
    {
       NRC =  NRC_NRSP;
    }
    if( (UDS_SESSION_DEFAULT == udsCurSession) && (NRC_PR == NRC) )
    {
       NRC = NRC_SNSIAS;
    }
    /*check mininum length*/
    if( (tpReqLen < 4) && (NRC_PR == NRC) )
    {
        NRC = NRC_IMLOIF;
    }

    if( (!KUDS_IOCtrlEnable) && (NRC_PR == NRC) )
    {
        NRC = NRC_SFNS;
    }

    if(NRC_PR == NRC)
    {

        IOCtrlID = (uint16_t)tpReqBuf[1];
        IOCtrlID = IOCtrlID << 8;
        IOCtrlID += (uint16_t)tpReqBuf[2];
        IOCtrlType = tpReqBuf[3];

        // add the actual IO control code here
        /*NRC=0x33 piority > NRC 0x31*/
        if( (UDS_UNLOCK_SECA != currSecAStatus) && (NRC_PR == NRC) )
        {
            NRC = NRC_SAD;
        }
        if( (IOCtrlID < UDS_ACTDIAG_MAINRELAY_DID) || (IOCtrlID > UDS_ACTDIAG_BRKLIGHT_DID) )
        {
            NRC = NRC_ROOR;
        }
        /* ABS speed or  motor speed indicate not stopped,  return 0x22*/    
        if( (FALSE == udsCheckCarAndMotorStopped()) && (NRC_PR == NRC) )
        {
            NRC = NRC_CNC;
        }


		 /*MainRelay control of ActionDiagnostic testing*/
		 if( (IOCtrlID == UDS_ACTDIAG_MAINRELAY_DID) && (NRC_PR == NRC) )
		 {
			  if(UDS_IOCTRL_TYPE_UDS == IOCtrlType)
			  {
				  if(tpReqLen != 5)
				  {
					  NRC = NRC_IMLOIF;
				  }
				  else
				  {
					  IOCtrlStatus = tpReqBuf[4];
					  if(1 == IOCtrlStatus)
					  {
						  IOCtrlDidTbl[0].Enable = 1;
						  IOCtrlDidTbl[0].Status = 1;
					  }
					  else if( 0 == IOCtrlStatus )
					  {
						  IOCtrlDidTbl[0].Enable = 1;
						  IOCtrlDidTbl[0].Status = 0;
					  }
					  else
					  {
						  NRC = NRC_IMLOIF;
					  }
				  }
			  }
			  else if( UDS_IOCTRL_TYPE_ECU == IOCtrlType )
			  {
			      if(tpReqLen != 4)
				  {
					  NRC = NRC_IMLOIF;
				  }
			      else
			      {
			    	  IOCtrlDidTbl[0].Enable = 0;
			      }
			  }
			  else
			  {
					NRC = NRC_IMLOIF;
			  }
		 }
		 /*MCURelay control of ActionDiagnostic testing*/
		 if( (IOCtrlID == UDS_ACTDIAG_MCURELAY_DID) && (NRC_PR == NRC) )
		 {
			  if(UDS_IOCTRL_TYPE_UDS == IOCtrlType)
			  {
				  if(tpReqLen != 5)
				  {
					  NRC = NRC_IMLOIF;
				  }
				  else
				  {
					  IOCtrlStatus = tpReqBuf[4];
					  if(1 == IOCtrlStatus)
					  {
						  IOCtrlDidTbl[1].Enable = 1;
						  IOCtrlDidTbl[1].Status = 1;
					  }
					  else if( 0 == IOCtrlStatus )
					  {
						  IOCtrlDidTbl[1].Enable = 1;
						  IOCtrlDidTbl[1].Status = 0;
					  }
					  else
					  {
						  NRC = NRC_IMLOIF;
					  }
				  }
			  }
			  else if( UDS_IOCTRL_TYPE_ECU == IOCtrlType )
			  {
			      if(tpReqLen != 4)
				  {
					  NRC = NRC_IMLOIF;
				  }
			      else
			      {
			    	  IOCtrlDidTbl[1].Enable = 0;
			      }
			  }
			  else
			  {
					NRC = NRC_IMLOIF;
			  }
		 }
		 /*brake light control of ActionDiagnostic testing*/
		 if( (IOCtrlID == UDS_ACTDIAG_BRKLIGHT_DID) && (NRC_PR == NRC) )
		 {
			  if(UDS_IOCTRL_TYPE_UDS == IOCtrlType)
			  {
				  if(tpReqLen != 5)
				  {
					  NRC = NRC_IMLOIF;
				  }
				  else
				  {
					  IOCtrlStatus = tpReqBuf[4];
					  if(1 == IOCtrlStatus)
					  {
						  IOCtrlDidTbl[2].Enable = 1;
						  IOCtrlDidTbl[2].Status = 1;
					  }
					  else if( 0 == IOCtrlStatus )
					  {
						  IOCtrlDidTbl[2].Enable = 1;
						  IOCtrlDidTbl[2].Status = 0;
					  }
					  else
					  {
						  NRC = NRC_IMLOIF;
					  }
				  }
			  }
			  else if( UDS_IOCTRL_TYPE_ECU == IOCtrlType )
			  {
			      if(tpReqLen != 4)
				  {
					  NRC = NRC_IMLOIF;
				  }
			      else
			      {
			    	  IOCtrlDidTbl[2].Enable = 0;
			      }
			  }
			  else
			  {
					NRC = NRC_IMLOIF;
			  }
		 }

    }
    /*assembly positive response*/
   if(NRC_PR == NRC)
   {
	   tpRspBuf[0] = (uint8_t)UDS_IO_CTRL +0x40;
	   tpRspBuf[1] = (uint8_t)(IOCtrlID >>8);
	   tpRspBuf[2] = (uint8_t)(IOCtrlID );
	   tpRspBuf[3] = IOCtrlType;
	   if(tpReqLen == 5 )
	   {
		   tpRspBuf[4] = IOCtrlStatus;
		   tpRspLen = 5;
	   }
	   else
	   {
		   tpRspLen = 4;
	   }
   }
    return NRC;
}

/*---------------------------------------------------------------------------
description:   this function is copied from Core1, read ADC result for HW test 
input param:         tADC_OutBuff-- ADC result from Core 1
input param:         Channel --ADC channel number
return value:         foat type  
---------------------------------------------------------------------------*/
float HAL_Get_ADC(unsigned char Channel) 

{
    float adc_data_temp = 0;
    if( Channel < ADC_NUM )
    {
        adc_data_temp = ADC_OutBuff[Channel];
        if( 0 == adc_data_temp )
        {
            adc_data_temp = 0;
        }
        else
        {
            adc_data_temp = (adc_data_temp + 1) * 5 / 4096;
        }
    }
    return adc_data_temp;
}

/*---------------------------------------------------------------------------
description:   this function handle the  request upload service request
input param:         tpReqBuf -- UDS service request PDU 
input param:         tpReqLen -- UDS service request PDU length
output param:     tpRspBuf --  positive UDS service response PDU 
output param:     tpRspLen -- positive UDS service response PDU length
return value:         NRC  
---------------------------------------------------------------------------*/
udsNRCType udsReqUpload(void)
{
    uint8_t paramLen = 0, i = 0, paramPos = 0;

    udsNRCType NRC = NRC_PR;

    if(1 == KUDS_TestFeature)
    {
        /*parse out the memory address*/
        paramLen = tpReqBuf[2]&0xF;
        uploadAddr = 0;
        paramPos = 3;
        for(i = 0; i < paramLen; i++)
        {
             uploadAddr =  uploadAddr << 8;
             uploadAddr += tpReqBuf[paramPos+i];
        }
        /*parse out the memory size*/
        uploadLen= 0;
        paramPos = paramPos + paramLen;
        paramLen = tpReqBuf[2] >> 4;
        paramLen = paramLen & 0xF;
        for(i = 0; i < paramLen; i++)
        {
             uploadLen =  uploadLen << 8;
             uploadLen += tpReqBuf[paramPos+i];
        }
        
    }
    else
    {
        NRC = NRC_SNS;
    }

    if(NRC_PR == NRC)
    {
         tpRspBuf[0] = (uint8_t)UDS_REQ_UPLOAD + 0x40;
         tpRspBuf[1] =  0x20;              /*maxNumberOfBlockLength parameter length is 2 bytes*/
         tpRspBuf[2] = (uint8_t)(MAX_BLOCK_LENGTH >> 8);
         tpRspBuf[3] = (uint8_t)(MAX_BLOCK_LENGTH);
         tpRspLen  = 4;
         dataBlkSN = 1;   /*block sequence number for $36 start from 1, reset to 1 in RequestUpload ($35)*/
         uploadCnt = 0;
        
    }
    
    return NRC;
}

/*---------------------------------------------------------------------------
description:   this function handle the  tansfer data service request
input param:         tpReqBuf -- UDS service request PDU 
input param:         tpReqLen -- UDS service request PDU length
output param:     tpRspBuf --  positive UDS service response PDU 
output param:     tpRspLen -- positive UDS service response PDU length
return value:         NRC  
---------------------------------------------------------------------------*/
udsNRCType udsTransferData(void)
{
    int len = 0;
    udsNRCType NRC = NRC_PR;

    if(1 != KUDS_TestFeature)
    {
        NRC = NRC_SNS;
    }

    if(NRC_PR == NRC)
    {
        len = uploadLen - uploadCnt;
        if(len > MAX_BLOCK_LENGTH)
        {
            len = MAX_BLOCK_LENGTH;
        }
    
        tpRspBuf[0] = (uint8_t)UDS_TRANSFER_DATA + 0x40;
        tpRspBuf[1] = dataBlkSN;
        (void)memcpy(&tpRspBuf[2], (uint8_t*)uploadAddr, len);
        /*total response lenth is  0x76 (positive response for service 0x36) + block SN + data length*/
        tpRspLen = 2 + len;
        dataBlkSN ++;
        uploadAddr = uploadAddr + len;
        uploadCnt = uploadCnt + len;
    }
    return NRC;
}

/*---------------------------------------------------------------------------
description:   this function handle the  tansfer exit service request
input param:         tpReqBuf -- UDS service request PDU 
input param:         tpReqLen -- UDS service request PDU length
output param:     tpRspBuf --  positive UDS service response PDU 
output param:     tpRspLen -- positive UDS service response PDU length
return value:         NRC  
---------------------------------------------------------------------------*/
udsNRCType udsTransferExit(void)
{
    udsNRCType NRC = NRC_PR;

    if(1 == KUDS_TestFeature)
    {
    }
    else
    {
        NRC = NRC_SNS;
    }

    if(NRC_PR == NRC)
    {
        tpRspBuf[0] = (uint8_t)UDS_TRANSFER_EXIT + 0x40;
        tpRspLen  = 1;    
    }
    return NRC;
}
/*---------------------------------------------------------------------------
description:   this function is used to test the External EEPROM read write
input param:         tpReqBuf[2] -- 0 read, 1 write
input param:         tpReqBuf[3-6] -- 32 bit address
input param:         tpReqBuf[7] -- size
output param:     tpRspBuf --  positive UDS service response PDU 
output param:     tpRspLen -- positive UDS service response PDU length
return value:         NRC  
---------------------------------------------------------------------------*/
udsNRCType usReadWriteDFlash(void)
{
    udsNRCType NRC = NRC_PR;
    uint32_t DFlashAddr = 0, alignedAddr = 0;
    uint32_t  size = 0, offset = 0;
    uint8_t i = 0;
    uint8_t tmpDFlashBuf[DFLASH_SECTOR_SIZE];

    /*calculate the DFlash Address*/
    DFlashAddr = 0;
    for(i = 0 ; i < 4; i++)
    {
         DFlashAddr = DFlashAddr << 8;
         DFlashAddr += (uint32_t)(tpReqBuf[3+i]);
    }

    size = (uint32_t)tpReqBuf[7];
    if(0 == tpReqBuf[2])
    {
        if(size<= DFLASH_SECTOR_SIZE)
        {
            tpRspBuf[0] = (uint8_t)UDS_READ_DTC + 0x40;
            tpRspBuf[1] = tpReqBuf[1];
            FLASH_EE_Read8(DFlashAddr, size, &tpRspBuf[2]);
            tpRspLen = 2 + (uint16_t)size;
        }
        else
        {
            NRC = NRC_ROOR;
        }
    }    
    else
    {

        if(0 == (DFlashAddr%DFLASH_SECTOR_SIZE))
        {
             offset = 0;
             alignedAddr = DFlashAddr;
        }
        else
        {
            offset = DFlashAddr%DFLASH_SECTOR_SIZE;
            alignedAddr = DFlashAddr - offset;
        }
        if((size + offset) <=DFLASH_SECTOR_SIZE)
        {
            if(FLASH_EE_IDLE == FLASH_EE_CheckBusy())
           {
                /*read the DFLASH back to internal bffer*/
                FLASH_EE_Read8(alignedAddr, DFLASH_SECTOR_SIZE, tmpDFlashBuf);
                for(i = 0; i < size; i++)
                {
                    tmpDFlashBuf[offset + i]= tpReqBuf[8+i] ;
                }     
                NVM_EraseBlockSync(alignedAddr, 0x1000);
                FLASH_EE_Write8(alignedAddr,  DFLASH_SECTOR_SIZE, tmpDFlashBuf);
                tpRspBuf[0] = (uint8_t)UDS_READ_DTC + 0x40;
                tpRspBuf[1] = tpReqBuf[1];
                tpRspBuf[2] = tpReqBuf[2];
                tpRspLen  = 3;
           }           
           else
           {
                NRC = NRC_GPF;
           }
        }
        else
        {
            NRC = NRC_ROOR;
        }
    }

    return NRC;

}

/*---------------------------------------------------------------------------
description:   this function is used to test the External EEPROM read write
input param:         tpReqBuf[2] -- 0 read, 1 write
input param:         tpReqBuf[3-4] -- 32 bit address
input param:         tpReqBuf[7] -- size
output param:     tpRspBuf --  positive UDS service response PDU 
output param:     tpRspLen -- positive UDS service response PDU length
return value:         NRC  
---------------------------------------------------------------------------*/
udsNRCType usReadWriteExtEE(void)
{
    udsNRCType NRC = NRC_PR;
    uint32_t ExtEEAddr = 0;
    uint32_t size = 0;
    uint8_t i = 0;
    uint8_t tmpExtEEBuf[EXTEE_PAGE_SIZE];
    uint8_t result = 0;
    /*calculate the DFlash Address*/
    ExtEEAddr = 0;
    for(i = 0 ; i < 2; i++)
    {
         ExtEEAddr = ExtEEAddr << 8;
         ExtEEAddr += (uint32_t)(tpReqBuf[3+i]);
    }

    size = (uint32_t)tpReqBuf[5];
    if(0 == tpReqBuf[2])
    {
        if(size<= EXTEE_PAGE_SIZE)
        {
            tpRspBuf[0] = (uint8_t)UDS_READ_DTC + 0x40;
            tpRspBuf[1] = tpReqBuf[1];
            result = ReadExtEE(ExtEEAddr, size, &tpRspBuf[2]);
            if(result != EXTEE_OK)
            {
                NRC = NRC_GR;
            }
            else
            {
                tpRspLen = 2 + (uint16_t)size;
            }
        }
        else
        {
            NRC = NRC_ROOR;
        }
    }    
    else
    {
        if(size <=EXTEE_PAGE_SIZE)
        {
            for(i = 0; i < size; i++)
            {
                tmpExtEEBuf[i]= tpReqBuf[6+i] ;
            }     
            result = WriteExtEE(ExtEEAddr, size, tmpExtEEBuf);
            if(EXTEE_OK == result)
            {
                tpRspBuf[0] = (uint8_t)UDS_READ_DTC + 0x40;
                tpRspBuf[1] = tpReqBuf[1];
                tpRspBuf[2] = tpReqBuf[2];
                tpRspLen  = 3;
            }
            else
            {
                NRC = NRC_GPF;
            }
        }
        else
        {
            NRC = NRC_ROOR;
        }
    }

    return NRC;

}

/*---------------------------------------------------------------------------
description:   this function is used to test the code FLASH reading 
input param:         tpReqBuf[2] -- 0 read, 1 write
input param:         tpReqBuf[3-6] -- 32 bit address
input param:         tpReqBuf[7] -- size
output param:     tpRspBuf --  positive UDS service response PDU 
output param:     tpRspLen -- positive UDS service response PDU length
return value:         NRC  
---------------------------------------------------------------------------*/
udsNRCType usReadCodeFlash(void)
{
    udsNRCType NRC = NRC_PR;
    uint32_t readAddr = 0;
    uint32_t  size = 0;
    uint8_t i = 0;
    /*calculate the DFlash Address*/
    readAddr = 0;
    for(i = 0 ; i < 4; i++)
    {
         readAddr = readAddr << 8;
         readAddr += (uint32_t)(tpReqBuf[3+i]);
    }

    size = (uint32_t)tpReqBuf[7];
    if(0 == tpReqBuf[2])
    {
        /*only code flash range and RAM can be read*/
        if(((readAddr >=0xF9C000) &&(readAddr <=0x133FFFF)) || ((readAddr >=0x40000000) &&(readAddr <=0x4003FFFF)))
        {
            tpRspBuf[0] = (uint8_t)UDS_READ_DTC + 0x40;
            tpRspBuf[1] = tpReqBuf[1];
            (void)memcpy((void*)&tpRspBuf[2], (void*)readAddr, size);
            tpRspLen = 2 + (uint16_t)size;
        }
        else
        {
            NRC = NRC_ROOR;
        }
    }    
    else
    {
        NRC = NRC_ROOR;
    }

    return NRC;

}


/* -----------------------------------------------------------------------------
 End of FILE uds_service.c
 ------------------------------------------------------------------------------*/


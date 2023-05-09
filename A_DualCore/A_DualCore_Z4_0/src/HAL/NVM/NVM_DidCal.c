/*
 * NVM_DidCal.c
 *
 *  Created on: 2019-3-27
 *      Author: ZhouYi
 *  the Non-volatile Memory management for DID and calibration data  is implemented by this moudle
 */

#define __SYS_GLOBALS__

#include "derivative.h"
#include <cstring>
#include "NVM.h"
#include "flash.h"
#include "uds_service.h"
#include "Global.h"
#include "CAN_DBC_Lib.h"
#include "CAN_Operation.h"
#include "M95128.h"
#include "DHP_model.h"
#include "EX_Data.h"
//@@@@@ #include "NCV7719.h"
#include "History_Data.h"
#include "untitled_etpu_gct.h"
/* =================  Private Constant Declarations =========================*/
/*following table will be removed after UDS module is integrated*/
#define UDS_FINGER_DID              0xF184
#define UDS_SN_DID                0xF18C
#define UDS_VIN_DID                0xF190
#define UDS_MANU_DATE_DID           0xF1A2
#define UDS_FUN_CFG_DID           0xF1FA
#define UDS_PEPS_VSK_DID     0x0A15
#define UDS_VCU_CFG_DID       0xF1FD
#define UDS_PEPS_PIN_DID         0x0A16

#define UDS_VEH_STATE_DID        0x0A00          /*vehicle state  */
#define UDS_KEY_STATE_DID        0x0A01          /*key state  */
#define UDS_GEAR_STATE_DID       0x0A02          /*gear state  */
#define UDS_SPEED_PEDAL_DID      0x0A03          /*speed pedal */
#define UDS_BRAKE_STATE_DID      0x0A04          /*brake state */
#define UDS_ODO_METER_DID        0x0A05          /*Odo meter */
#define UDS_VEH_SPEED_DID        0x0A06          /*vehicle speed */
#define UDS_LOW_BATT_DID         0x0A07         /*low battery voltage  */
#define UDS_CHG_STATE_DID        0x0A08          /*charging state*/
#define UDS_REQ_TQ_DID           0x0A09          /*required Torque*/
#define UDS_ACT_TQ_DID           0x0A0A          /*actual Torque*/
#define UDS_MCU_TEMP_DID         0x0A0B          /*MCU inverter temperature*/
#define UDS_MOT_TEMP_DID         0x0A0C          /*MCU motor temperature*/
#define UDS_ACT_RPM_DID          0x0A0D          /*motor actual speed*/
#define UDS_BATT_SOC_DID         0x0A0E          /*Battery SOC x%*/
#define UDS_HV_VOLT_DID          0x0A0F          /*Battery HV voltage*/
#define UDS_HV_CURR_DID          0x0A10          /*Battery HV current*/
#define UDS_HV_TEMP_DID          0x0A11          /*Battery HV temperature*/
#define UDS_DCDC_TEMP_DID        0x0A12          /*DCDC temperature*/

#define UDS_VEH_STATE_LEN 1                    /*vehicle state length= 1 */
#define UDS_KEY_STATE_LEN 1                    /*key state length= 1 */
#define UDS_GEAR_STATE_LEN 1                   /*gear state length= 1 */
#define UDS_SPEED_PEDAL_LEN 1                 /*speed pedal length= 1 */
#define UDS_BRAKE_STATE_LEN 1                   /*brake state length= 1 */
#define UDS_ODO_METER_LEN    3                 /*Odo meter length=4*/
#define UDS_VEH_SPEED_LEN    2                /*vehicle speed length=4*/
#define UDS_LOW_BATT_LEN   1         /*low battery voltage  */
#define UDS_CHG_STATE_LEN  1          /*charging state = 1*/
#define UDS_REQ_TQ_LEN        2          /*required Torque*/
#define UDS_ACT_TQ_LEN        2          /*actual Torque*/
#define UDS_MCU_TEMP_LEN        1          /*MCU inverter temperature*/
#define UDS_MOT_TEMP_LEN        1          /*MCU motor temperature*/
#define UDS_ACT_RPM_LEN        2          /*motor actual speed*/
#define UDS_BATT_SOC_LEN    2             /*Battery SOC x%*/
#define UDS_HV_VOLT_LEN    2             /*Battery HV voltage*/
#define UDS_HV_CURR_LEN    2             /*Battery HV current*/
#define UDS_HV_TEMP_LEN    1             /*Battery HV temperature*/
#define UDS_DCDC_TEMP_LEN    1             /*DCDC temperature*/


/***************************following should be removed after App and UDS module integrated*****************************************************/
extern uint8_t UdsAppSWVer[12];
extern uint8_t UdsCalSWVer[8];
extern uint8_t UdsHWVer[12];
extern uint8_t UdsPartNumber[21];

/***************************above should be removed after App and UDS module integrated*****************************************************/

/*HW version ASCII: 2108S1100101             \u0032\u0031\u0030\u0038\u0053\u0031\u0031\u0030\u0030\u0031\u0030\u0031*/
const uint8_t HW_VER_DID_INIT[UDS_HW_VER_LEN] = {0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30};/*{0x32, 0x31, 0x30, 0x38, 0x53, 0x31, 0x31, 0x30, 0x30, 0x31, 0x30, 0x31}*/

/*Finger print unsigned Year+MOnth+Day + 4 bytes ASCII NJDK*/
const uint8_t ECU_Finger_DID_INIT[UDS_FINGER_LEN] = {0x11,0x0A, 0x1F,0x4E,0x4A,0x44,0x4B};
/*SW version ASCII: SF0000000102             \u0053\u0046\u0030\u0030\u0030\u0030\u0030\u0030\u0030\u0031\u0030\u0032*/
const uint8_t SW_VER_DID_INIT[UDS_SW_VER_LEN] = {0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30};/*{0x53, 0x46, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x31, 0x30, 0x33}*/
/*part number :2108S11001A               \u0032\u0031\u0030\u0038\u0053\u0031\u0031\u0030\u0030\u0031\u0041*/
const uint8_t Part_DID_INIT[UDS_PART_LEN] = {0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x20,  0x20, 0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20};/*{0x32, 0x31, 0x30, 0x38, 0x53, 0x31, 0x31, 0x30, 0x30, 0x31, 0x41, 0x20,  0x20, 0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20}*/
/*supplier ASCII : PP025004                      \u0050\u0050\u0030\u0032\u0035\u0030\u0030\u0034*/
const uint8_t Supplier_DID_INIT[UDS_SUPPLIER_LEN] = {0x50, 0x50, 0x30, 0x32, 0x35, 0x30, 0x30, 0x34};
/*ECU SN: 4bytes unsigned + 6 bytes ASCII +unsigned Year+MOnth+Day*/
/*21010000080                                \u0032\u0031\u0030\u0031\u0030\u0030\u0030\u0030\u0030\u0038\u0030*/
const uint8_t ECU_SN_DID_INIT[UDS_ECU_SN_LEN] = {0x32, 0x31, 0x30, 0x31, 0x30, 0x30, 0x30, 0x30, 0x30, 0x38, 0xFF,0xFF,0xFF};
/*VIN length  ASCII: LJU70W1Z6FG061012*/
const uint8_t VIN_DID_INIT[UDS_VIN_LEN] = {0x4C,0x4A,0x55,0x37,0x30,0x57,0x31,0x5A,0x36,0x46,0x47,0x30,0x36,0x31,0x30,0x31,0x32};
/*manufaction date BCD code Year+MOnth+Day*/
const uint8_t MANU_DATE_DID_INIT[UDS_MANU_DATE_LEN] = {0x20, 0x19,0x10,0x29};
/*feature configuration*/
const uint8_t FUN_CFG_DID_INIT[UDS_FUN_CFG_LEN] = {0x12,0x34,0x56,0x78, 0x9A,0xCD};
/*network info, 3.40                               \u0033\u002e\u0034*/
const uint8_t NET_INFO_DID_INIT[UDS_NET_INFO_LEN] = {0x33,0x2e,0x34,0x30};
//const uint8_t NET_INFO_DID_INIT[UDS_NET_INFO_LEN] = {0x30,0x2E,0x31};
/*function info, feature spec version ASCII 03.0   \u0030\u0033\u002e\u0030*/
const uint8_t FUN_INFO_DID_INIT[UDS_FUN_INFO_LEN] = {0x30,0x33,0x2E,0x30};
/*diagnosis info, diagnosis spec version ASCII 00.1*/
const uint8_t DIAG_INFO_DID_INIT[UDS_DIAG_INFO_LEN] = {0x30,0x30,0x2E,0x31};
/*APP SW version: ASCII*/
const uint8_t APP_SW_DID_INIT[UDS_APP_SW_VER_LEN] = {0x04,0x98,0x32,0x44,0x07,0xE6,0x03,0x12};
/*bootloader SW version: ASCII*/
const uint8_t BOOT_SW_DID_INIT[UDS_BOOT_SW_VER_LEN] = {0x5A, 0x4A,0x32,0x2E,0x30,0x2E,0x30,0x30};  /*ASCII: ZJ2.0.00*/
/*calibration SW version: ASCII*/
const uint8_t CAL_SW_DID_INIT[UDS_CAL_SW_VER_LEN] = {0x30, 0x30,0x30,0x30,0x30,0x30,0x30,0x30};/*{0x31, 0x32,0x33,0x34,0x35,0x36,0x37,0x38}*/
/*ECU HW version: ASCII VCU201*/
const uint8_t ECU_HW_DID_INIT[UDS_ECU_HW_VER_LEN] = {0x56, 0x43, 0x55U, 0x32, 0x30, 0x31, 0x30, 0x31};
/*ECU SW version: ASCII*/
const uint8_t ECU_SW_DID_INIT[UDS_ECU_SW_VER_LEN] = {0x31, 0x32,0x33,0x34,0x35,0x36,0x37,0x38};
/*PEPS VSK code: default value 16 0xAA*/
const uint8_t PEPS_VSK_DID_INIT[UDS_PEPS_VSK_LEN] = {0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA};
/*VCU feature configuraton default vaue: vehicle_type = 1 (S11) --2019.07.02 VCU_CFG changed, not send vehicle_type any more*/
const uint8_t VCU_CFG_DID_INIT [UDS_VCU_CFG_LEN] = {0xF0, 0x10, 0x20, 0x30, 0x40, 0x50, 0x60, 0x70};

const uint8_t PES_PIN_DID_INIT[UDS_PEPS_PIN_LEN] = {0,0,0,0};

const uint8_t VCU_CCP_DID_INIT [UDS_VCU_CCP_LEN] = {1}; //Ĭ�Ͽ���CCP

const uint32_t UDS_EEPROM_DID_ADDR_TBL[UDS_EEPROM_DID_NUM] ={
   0, 
   UDS_FINGER_LEN,
   UDS_FINGER_LEN  + UDS_ECU_SN_LEN, 
   UDS_FINGER_LEN  + UDS_ECU_SN_LEN + UDS_VIN_LEN, 
   UDS_FINGER_LEN  + UDS_ECU_SN_LEN + UDS_VIN_LEN + UDS_MANU_DATE_LEN, 
   UDS_FINGER_LEN  + UDS_ECU_SN_LEN + UDS_VIN_LEN + UDS_MANU_DATE_LEN + UDS_FUN_CFG_LEN, 
   UDS_FINGER_LEN  + UDS_ECU_SN_LEN + UDS_VIN_LEN + UDS_MANU_DATE_LEN + UDS_FUN_CFG_LEN +UDS_VCU_CFG_LEN, 
   UDS_FINGER_LEN  + UDS_ECU_SN_LEN + UDS_VIN_LEN + UDS_MANU_DATE_LEN + UDS_FUN_CFG_LEN +UDS_VCU_CFG_LEN +UDS_PEPS_VSK_LEN,
   UDS_FINGER_LEN  + UDS_ECU_SN_LEN + UDS_VIN_LEN + UDS_MANU_DATE_LEN + UDS_FUN_CFG_LEN +UDS_VCU_CFG_LEN +UDS_PEPS_VSK_LEN + UDS_PEPS_PIN_LEN};

const uint8_t *  UDS_FLASH_DID_ADDR_TBL[UDS_FLASH_DID_NUM] = {

    UdsHWVer, NET_INFO_DID_INIT, FUN_INFO_DID_INIT, DIAG_INFO_DID_INIT, APP_SW_DID_INIT, BOOT_SW_DID_INIT,
    UdsCalSWVer, ECU_HW_DID_INIT, ECU_SW_DID_INIT, UdsAppSWVer, UdsPartNumber, Supplier_DID_INIT 
};


const uint8_t DID_VALID_FLAG[FLAG_SIZE] = {0x56, 0x41, 0x4C, 0x49, 0x44, 0x44, 0x49, 0x44};    /*ASCII: "VALIDDID" */
/*string "GOODDATA"*/
const uint8_t CAL_DATA_VALID[FLAG_SIZE] = {0x47, 0x4F, 0x4F, 0x44, 0x44, 0x41, 0x54, 0x41};

const uint32_t UDS_SW_DID_ADDR_TBL[UDS_SP_DID_NUM -UDS_VEHICLE_DID_NUM]= {
    (uint32_t)&DHP_model_B.BusCreator.VDHP_VehSts_enum, (uint32_t)&DHP_model_B.BusCreator.VDHP_PEPS_PDU_enum,  (uint32_t)&DHP_model_B.BusCreator.VDHP_GearOut_enum, 
    (uint32_t)&DHP_model_B.BusCreator.VDHP_AccelPedal_per,  (uint32_t)&DHP_model_B.BusCreator.VDHP_BrkLightSwitchActive_flg,  (uint32_t)&DHP_model_B.BusCreator.VDHP_TotalVehDistance_km,
    (uint32_t)&DHP_model_B.BusCreator.VDHP_ABS_VehicleSpeed,  (uint32_t)&DHP_model_B.BusCreator.VDHP_LVBattVoltage_V,  (uint32_t)&DHP_model_B.BusCreator.VDHP_BMSChrgSts_enum,
    (uint32_t)&VHALO_MotTqReq, (uint32_t)&DHP_model_B.BusCreator.VDHP_MotTqReal,   (uint32_t)&DHP_model_B.BusCreator.VDHP_MCUIGBTT,  (uint32_t)&DHP_model_B.BusCreator.VDHP_MCUElecMotT,  
    (uint32_t)&DHP_model_B.BusCreator.VDHP_MCUElecMotSpd,  (uint32_t)&DHP_model_B.BusCreator.VDHP_BMSSOC,   (uint32_t)&DHP_model_B.BusCreator.VDHP_BMSBattU, 
    (uint32_t)&DHP_model_B.BusCreator.VDHP_BMSBattI,  (uint32_t)&DHP_model_B.BusCreator.VDHP_BMSAvrgBattT ,  (uint32_t)&DHP_model_B.BusCreator.VDHP_DCDCT , 
    (uint32_t)&VHALI_TBOX_TimeYear, (uint32_t)&VHALI_TBOX_TimeMonth, (uint32_t)&VHALI_TBOX_TimeDate, (uint32_t)&VHALI_TBOX_TimeHour, (uint32_t)&VHALI_TBOX_TimeMinute,
    (uint32_t)&VHALI_TBOX_TimeSecond,  (uint32_t)&VHALI_BMSErrNum, (uint32_t)&VHALI_MCUErrNum,
	(uint32_t)&DHP_model_B.BusCreator.VDHP_BrkLightSwitch, (uint32_t)&DHP_model_B.BusCreator.VDHP_GearSwitch,
	(uint32_t)&DHP_model_B.BusCreator.VDHP_AccelPedalH_kv, (uint32_t)&DHP_model_B.BusCreator.VDHP_AccelPedalL_kv,
	(uint32_t)&DHP_model_B.BusCreator.VDHP_WaterPWM_Duty, (uint32_t)&DHP_model_B.BusCreator.VDHP_VacuumPump_HZ,
	(uint32_t)&DHP_model_B.BusCreator.VDHP_SRSPWM_Duty, (uint32_t)&DHP_model_B.BusCreator.VDHP_SRSPWM_HZ, (uint32_t)&DHP_model_B.BusCreator.VDHP_HVInterlock_HZ,
	(uint32_t)&DHP_model_B.BusCreator.VDHP_HLspdFan, (uint32_t)&DHP_model_B.BusCreator.VDHP_WaterPump_flg,
	(uint32_t)&DHP_model_B.BusCreator.VDHP_EPB_Status, (uint32_t)&DHP_model_B.BusCreator.VDHP_EPBAppliedReq,
	(uint32_t)&DHP_model_B.BusCreator.VDHP_FastChargeAwake_flg, (uint32_t)&DHP_model_B.BusCreator.VDHP_SlowChargeAwake_flg,
	/*(uint32_t)&DHP_model_B.BusCreator.VDHP_MainRelay_flg //IO control may change the relay status*/
	(uint32_t)&appDID_outSnapshot.MainRelay_flg,
	(uint32_t)&appDID_outSnapshot.AccPdlSensor5V1, (uint32_t)&appDID_outSnapshot.AccPdlSensor5V2,
	(uint32_t)&appDID_outSnapshot.fastChrgSensorTemp1, (uint32_t)&appDID_outSnapshot.fastChrgSensorTemp2,
	(uint32_t)&appDID_outSnapshot.VCUBMSOperModeReq, (uint32_t)&appDID_outSnapshot.BMSOperMode,
	(uint32_t)&appDID_outSnapshot.BMSMaxDischrgPwr, (uint32_t)&appDID_outSnapshot.BMSMaxChrgPwr,
	(uint32_t)&appDID_outSnapshot.BMSMaxDischrgI, (uint32_t)&appDID_outSnapshot.BMSMaxChrgI,
	(uint32_t)&appDID_outSnapshot.BMSCC2SngR, (uint32_t)&appDID_outSnapshot.BMSCCSngR,
	(uint32_t)&appDID_outSnapshot.VCUDCDCOperModeReq, (uint32_t)&appDID_outSnapshot.DCDCOperMode,
	(uint32_t)&appDID_outSnapshot.DCDCoutputU, (uint32_t)&appDID_outSnapshot.DCDCoutputI,
	(uint32_t)&appDID_outSnapshot.DCDCinputU, (uint32_t)&appDID_outSnapshot.DCDCinputI,
	(uint32_t)&appDID_outSnapshot.VCUMCUOperModeReq, (uint32_t)&appDID_outSnapshot.MCUOperMode,
	(uint32_t)&appDID_outSnapshot.VCUElecMotErr, (uint32_t)&appDID_outSnapshot.VCUMotspeedReq,
	(uint32_t)&appDID_outSnapshot.MCUMaxAvlTorque, (uint32_t)&appDID_outSnapshot.MCUMinAvlTorque,
	(uint32_t)&appDID_outSnapshot.BMSIsolationR, (uint32_t)&appDID_outSnapshot.MCURelay_flg, (uint32_t)&appDID_outSnapshot.BrklightRelay_flg
};

const uint32_t ESCL_KEY_INIT = 0x12345678;
/* =================  Private Variable Declarations =========================*/
CORE0_INIT uint8_t DIDRamTbl[UDS_FINGER_LEN + UDS_ECU_SN_LEN + UDS_VIN_LEN + UDS_MANU_DATE_LEN + UDS_FUN_CFG_LEN +UDS_VCU_CFG_LEN +UDS_PEPS_VSK_LEN + UDS_PEPS_PIN_LEN + UDS_VCU_CCP_LEN + UDS_ESCL_KEY_LEN];
CORE0_INIT boolean gbCalDataCorrect = TRUE;  /*TRUE: calibration data is correct; FALSE: calibration data is wrong (was corrupted)*/
CORE0_INIT boolean gbCalDataChecked = FALSE;
CORE0_INIT uint32_t  EraseStartTime = 0;
CORE0_INIT boolean gbDidDataCorrect = TRUE;   /*TRUE: DID data is correct; FALSE: DID data is wrong (was corrupted)*/

/* =================  Private function Declarations =========================*/
void NVM_DID_Init(void);
void Write_DIDFromRAM(void);
void NVM_DID_CheckCrc(void);

 void HWTest_etpu_pwm_update(uint8_t channel, uint32_t freq, uint16_t duty);

 /* ===================================  public funciton implementation ==============================*/

 /***************************************************************************************************************
  * Name:        Write_DIDFromRAM
  * Function:    1. call funtion to Erase Block assigned to DID, 
  *              2.  write DID RAM table into DFLASH, 
  *              3.  wrie DID valid flag
  * Input:       null
  * Return:      null
  * Link:        
  * Attention:   
  ************************************************************************************************************* */
void Write_DIDFromRAM(void)
{
    uint8_t  DFlashData[DID_TOTAL_LENGTH + DID_CRC_ACT_LEN + DID_CRC_RESERVED + FLAG_SIZE];  /*total DID+3 reserve + CRC + 4 reserve + valid flag  = 88*/
    uint32_t crc;

    /* write DID RAM table finger print should not be written */
    (void)memset(DFlashData, 0, sizeof(DFlashData));
    (void)memcpy(DFlashData, &DIDRamTbl[UDS_FINGER_LEN], (sizeof(DIDRamTbl) -UDS_FINGER_LEN));
    /*calculate the CRC and copy into buffer*/
    if(1 == Config_output.C_ESCL_En)
    {
        crc = CalcCrc32(DFlashData, (sizeof(DIDRamTbl) -UDS_FINGER_LEN));
        (void)memcpy(&DFlashData[DID_TOTAL_LEN_BTK], (uint8_t*)&crc, sizeof(crc));
    }
    else
    {
        crc = CalcCrc32(DFlashData, (sizeof(DIDRamTbl) -UDS_FINGER_LEN - UDS_ESCL_KEY_LEN));    
        (void)memcpy(&DFlashData[DID_TOTAL_LENGTH], (uint8_t*)&crc, sizeof(crc));
    }
    /*copy the vlaid flag*/
    (void)memcpy(&DFlashData[DID_TOTAL_LENGTH + DID_CRC_ACT_LEN + DID_CRC_RESERVED], DID_VALID_FLAG, sizeof(DID_VALID_FLAG));
    /*write into DFLASH*/
    FLASH_EE_Write8(DID_DATA_START_ADDR,  sizeof(DFlashData),  DFlashData);
    /*DID have been written , of course the data is correct now*/
    gbDidDataCorrect = TRUE;
    DFlashRWStatus = DFlashRWStatus & (~ DFLASH_WRITE_DID);   /*clear the DID DFLASH writing request*/
}

/* ===================================  public funciton implementation ==============================*/
/*============================= following is DID relevant functions=========================================*/


/***************************************************************************************************************
 * Name:        NVM_EraseBlockSync
 * Function:    this function do 3 works in one function, start the erase operation, wait until DFLASH return to idle; finish the erasing operation
 *                  
 * Input:        NvMDidCalStatus
 * Return:        null
 * Link:        
 * Attention:  it will stop the task schedule  
 ************************************************************************************************************* */
void NVM_EraseBlockSync(uint32_t address, uint32_t length)
{
    FLASH_EE_EraseStart(address, length);
    /*keep in while loop to wait the erasing finished max wait time MAX_DFLASH_ERASE_TIME*/
    EraseStartTime = SystemTickMs;
  
    while(FLASH_EE_IDLE != FLASH_EE_CheckBusy())
    {
         /*waited maximum time give up the operation*/
         if((SystemTickMs -EraseStartTime ) > MAX_DFLASH_ERASE_TIME)
         {
             break;
         }
    }
    /*finish the erase  operation*/
    FLASH_EE_EraseEnd(address, length);

}
/***************************************************************************************************************
 * Name:        PepsPinIsInitValue
 * Function:    this function check if the PEPS PIN is initial value
 *                  
 * Input:        NvMDidCalStatus
 * Return:     TURE -- PIN is initial value; FALSE -- not initial value
 * Link:        
 * Attention:  it will stop the task schedule  
 ************************************************************************************************************* */
boolean PepsPinIsInitValue(void)
{
    uint8_t i;
    uint8_t EEData[UDS_PEPS_PIN_LEN];
    
    boolean bIsInitValueFlag = TRUE;
    usReadPepsPinCode(EEData);
    for(i = 0; i < UDS_PEPS_PIN_LEN; i++)
    {
        if(EEData[i] != PES_PIN_DID_INIT[i])
        {
            bIsInitValueFlag = FALSE;
            break;
        }
    }    
    return bIsInitValueFlag;

}

/***************************************************************************************************************
 * Name:        NVM_DID_Init
 * Function:    1. check DID valid flag in DFLASH, if not vliad, write Default DID content from P-Flash to DFLASH
 *              2. if valid , copy DID from DFLASH to RAM
 * Input:        null
 * Return:        null
 * Link:        
 * Attention:    
 ************************************************************************************************************* */
 void NVM_DID_Init(void)
 {
    uint8_t i;
    uint8_t FlagValid=0;
    uint8_t DFlashFlag[FLAG_SIZE];
    uint8_t loop = 0;
    uint8_t maxloopcounter=3;
    gbDidDataCorrect = TRUE;
    
    ECU_FUN_CFG_Valid = 0;
    VCU_CCP_Valid = VCU_CCP_DID_INIT[0];

    FlagValid= 1; 
    for(loop=0;loop<maxloopcounter;loop++)
    {
        /*read DID vlaid flag*/
        FLASH_EE_Read8(DID_FLAG_START_ADDR, FLAG_SIZE, DFlashFlag);    
        for(i = 0 ; i < FLAG_SIZE; i++)
        {
            if(DID_VALID_FLAG[i] != DFlashFlag[i])
            {
                FlagValid = 0;
                break;
            }
        }
        /*if read success once, no need to read again. else continue next read. */
        if(1==FlagValid)
        {
            break;
        }
        
    }
    
    /*read fingerprint written by bootloader*/
    FLASH_EE_Read8(DID_FINGER_PRINT_ADDR, UDS_FINGER_LEN, DIDRamTbl);
    
    /*Flag is valid, copy from DFLASH to RAM mirror table*/
    if(1 == FlagValid)
    {
        FLASH_EE_Read8(DID_DATA_START_ADDR, (sizeof(DIDRamTbl) - UDS_FINGER_LEN), &DIDRamTbl[UDS_FINGER_LEN]);

        (void)memcpy( &PEPS_VSK_Byte, &DIDRamTbl[UDS_FINGER_LEN + UDS_ECU_SN_LEN + UDS_VIN_LEN + UDS_MANU_DATE_LEN + UDS_FUN_CFG_LEN + UDS_VCU_CFG_LEN], UDS_PEPS_VSK_LEN);

        (void)memcpy( &ECU_FUN_CFG_Byte, &DIDRamTbl[UDS_FINGER_LEN + UDS_ECU_SN_LEN + UDS_VIN_LEN + UDS_MANU_DATE_LEN],  UDS_FUN_CFG_LEN);
        if( (FUN_CFG_DID_INIT[0] != ECU_FUN_CFG_Byte[0]) && (FUN_CFG_DID_INIT[1] != ECU_FUN_CFG_Byte[1]) && (FUN_CFG_DID_INIT[2] != ECU_FUN_CFG_Byte[2]) \
                  && (FUN_CFG_DID_INIT[3] != ECU_FUN_CFG_Byte[3]) /*&& (FUN_CFG_DID_INIT[4] != ECU_FUN_CFG_Byte[4]) && (FUN_CFG_DID_INIT[5] != ECU_FUN_CFG_Byte[5])*/  )
        {
            ECU_FUN_CFG_Valid = 1;
        }
        (void)memcpy( &VCU_CFG_Byte, &DIDRamTbl[UDS_FINGER_LEN + UDS_ECU_SN_LEN + UDS_VIN_LEN + UDS_MANU_DATE_LEN + UDS_FUN_CFG_LEN],  UDS_VCU_CFG_LEN);
        if( (VCU_CFG_DID_INIT[0] != VCU_CFG_Byte[0]) )
        {
             VCU_CFG_Valid = 1;
        }

        (void)memcpy( &VCU_CCP_Byte, &DIDRamTbl[UDS_FINGER_LEN + UDS_ECU_SN_LEN + UDS_VIN_LEN + UDS_MANU_DATE_LEN + UDS_FUN_CFG_LEN +UDS_VCU_CFG_LEN +UDS_PEPS_VSK_LEN + UDS_PEPS_PIN_LEN], UDS_VCU_CCP_LEN);
        if(1==VCU_CCP_Byte[0])
        {
            VCU_CCP_Valid = 1;
        }
        else if(0xFF==VCU_CCP_Byte[0])
        {
            ///(void)memcpy(&DIDRamTbl[UDS_FINGER_LEN + UDS_ECU_SN_LEN + UDS_VIN_LEN + UDS_MANU_DATE_LEN + UDS_FUN_CFG_LEN +UDS_VCU_CFG_LEN +UDS_PEPS_VSK_LEN + UDS_PEPS_PIN_LEN], VCU_CCP_DID_INIT, UDS_VCU_CCP_LEN);
            ///VCU_CCP_Byte[0] = VCU_CCP_DID_INIT[0];
            VCU_CCP_Valid = 1;   //Ĭ�Ͽ���CCP
        }
        else
        {
            VCU_CCP_Valid = 0;
        }
        /*ESCL key */
        (void)memcpy((void*)&currEsclKey, &DIDRamTbl[UDS_FINGER_LEN + UDS_ECU_SN_LEN + UDS_VIN_LEN + UDS_MANU_DATE_LEN + UDS_FUN_CFG_LEN +UDS_VCU_CFG_LEN +UDS_PEPS_VSK_LEN + UDS_PEPS_PIN_LEN+UDS_VCU_CCP_LEN], UDS_ESCL_KEY_LEN);
        /*ESCL key is not initialized, set it to default value*/
        if((0xFFFFFFFF == currEsclKey) ||(0 == (currEsclKey & 0xFFFFFF00)))
        {
            currEsclKey = ESCL_KEY_INIT;
        }
        currEsclKey = currEsclKey ^ESCL_FIX_CODE;
        NVM_DID_CheckCrc();
    }
    /*copy from const table to RAM mirror table*/
    else
    {
        /*SN */
        for(i = 0; i < UDS_ECU_SN_LEN; i++)
        {
            DIDRamTbl[UDS_FINGER_LEN + i] = ECU_SN_DID_INIT[i];
        }
        
        /*VIN */
        for(i = 0; i < UDS_VIN_LEN; i++)
        {
            DIDRamTbl[UDS_FINGER_LEN + UDS_ECU_SN_LEN + i] = VIN_DID_INIT[i];
        }    
        /*Manufacture Date */
        for(i = 0; i < UDS_MANU_DATE_LEN; i++)
        {
            DIDRamTbl[UDS_FINGER_LEN + UDS_ECU_SN_LEN + UDS_VIN_LEN + i] = MANU_DATE_DID_INIT[i];
        }            
        
        /*function configuration */
        for(i = 0; i < UDS_FUN_CFG_LEN; i++)
        {
            DIDRamTbl[UDS_FINGER_LEN + UDS_ECU_SN_LEN + UDS_VIN_LEN + UDS_MANU_DATE_LEN + i] = FUN_CFG_DID_INIT[i];
        }                

        /*VCU feature configuration */
        for(i = 0; i < UDS_VCU_CFG_LEN; i++)
        {
            DIDRamTbl[UDS_FINGER_LEN + UDS_ECU_SN_LEN + UDS_VIN_LEN + UDS_MANU_DATE_LEN  + UDS_FUN_CFG_LEN + i] = VCU_CFG_DID_INIT[i];
        }    

        /*PEPS VSK code */
        for(i = 0; i < UDS_PEPS_VSK_LEN; i++)
        {
            DIDRamTbl[UDS_FINGER_LEN + UDS_ECU_SN_LEN + UDS_VIN_LEN + UDS_MANU_DATE_LEN  + UDS_FUN_CFG_LEN +UDS_VCU_CFG_LEN + i] = PEPS_VSK_DID_INIT[i];
        }        

        /*VCU PIN code */
        for(i = 0; i < UDS_PEPS_PIN_LEN; i++)
        {
            DIDRamTbl[UDS_FINGER_LEN + UDS_ECU_SN_LEN + UDS_VIN_LEN + UDS_MANU_DATE_LEN  + UDS_FUN_CFG_LEN +UDS_VCU_CFG_LEN + UDS_PEPS_VSK_LEN  + i] = PES_PIN_DID_INIT[i];
        }    

        /*VCU CCP config */
        for(i = 0; i < UDS_VCU_CCP_LEN; i++)
        {
            DIDRamTbl[UDS_FINGER_LEN + UDS_ECU_SN_LEN + UDS_VIN_LEN + UDS_MANU_DATE_LEN  + UDS_FUN_CFG_LEN +UDS_VCU_CFG_LEN + UDS_PEPS_VSK_LEN  + UDS_PEPS_PIN_LEN + i] = VCU_CCP_DID_INIT[i];
        }
        DFlashRWStatus   = DFlashRWStatus | DFLASH_WRITE_DID;    /*set on the Write DID to DFlash request*/
    }

    VHALO_VCUHwVer1 = ECU_HW_DID_INIT[3];
    VHALO_VCUHwVer2 = ECU_HW_DID_INIT[4];   
    VHALO_VCUSwVer1 = (uint16_t)(APP_SW_DID_INIT[0] <<8) + APP_SW_DID_INIT[1];
    VHALO_VCUSwVer2 = APP_SW_DID_INIT[2];
    VHALO_VCUSwVer3 = APP_SW_DID_INIT[3];
    
 }
   /***************************************************************************************************************
   * Name:        NVM_DID_CheckCrc
   * Function:    1. check if the Crc checksum of DID is correct or not
   * Input:       DIDRamTbl
   * output:      gbDidDataCorrect
   * Return:      null
   * Link:        
   * Attention:   
   ************************************************************************************************************* */
 void NVM_DID_CheckCrc(void)
 {
     uint8_t i;
     uint8_t DFlashData[DID_CRC_ACT_LEN];
     uint32_t u32StoredCrc, u32CalcedCrc;

     /*read the CRC stored in DFLASH CRC is stored different position for VCU with BTK or no BTK*/
    if(1 == Config_output.C_ESCL_En)
    {     
         FLASH_EE_Read8((DID_DATA_START_ADDR+ DID_TOTAL_LEN_BTK), DID_CRC_ACT_LEN, DFlashData);
    }
    else
    {
        FLASH_EE_Read8((DID_DATA_START_ADDR+ DID_TOTAL_LENGTH), DID_CRC_ACT_LEN, DFlashData);
    }
    u32StoredCrc = 0;
    for(i = 0; i < sizeof(uint32_t); i++)
    {
         u32StoredCrc = u32StoredCrc << 8;
         u32StoredCrc = u32StoredCrc + (uint32_t)DFlashData[ i];
    }
    /*calculate CRC based on readout DID data*/
    if(1 == Config_output.C_ESCL_En)
    {
        u32CalcedCrc = CalcCrc32(&DIDRamTbl[UDS_FINGER_LEN], (sizeof(DIDRamTbl) -UDS_FINGER_LEN));
    }
    else
    {
        u32CalcedCrc = CalcCrc32(&DIDRamTbl[UDS_FINGER_LEN], (sizeof(DIDRamTbl) -UDS_FINGER_LEN-UDS_ESCL_KEY_LEN));
    }
    if(u32CalcedCrc != u32StoredCrc)
    {
         gbDidDataCorrect  = FALSE;
    }
 }

 /***************************************************************************************************************
  * Name:        Write_DIDFromRAM
  * Function:    1. call funtion to Erase Block assigned to DID, 
  *              2.  write DID RAM table into DFLASH, 
  *              3.  wrie DID valid flag
  * Input:       index: DID index (close-coupled with uds_service module
  * Return:      null
  * Link:        
  * Attention:   
  ************************************************************************************************************* */
usResultType usReadDIDDatabyIndex(uint8_t index, uint8_t  pDataRecord[])
{
     uint32_t OdoMeter;
     uint8_t * pSrc;
    usResultType result = US_OK;

    /*check if pointer is NULL and index is in corret range*/
    if( (index >= UDS_SP_DID_NUM) || (NULL == pDataRecord) )
    {
        return US_FAILED;
    }

    /* finger print ,SN, VIN, manufacture date, function configuration VCU confuguration, PEPS (7) DID was copied from DFLASH to RAM already at initialization phase*/
    if(index < UDS_EEPROM_DID_NUM)
    {
        (void)memcpy((uint8_t*)pDataRecord, &DIDRamTbl[UDS_EEPROM_DID_ADDR_TBL[index]], UdsSpDidTbl[index].DataLen);
    }
    /*Some DIDs are constant in Flash */
    else if( (index >=UDS_EEPROM_DID_NUM) && (index < (UDS_EEPROM_DID_NUM + UDS_FLASH_DID_NUM)) )
    {
       (void)memcpy((uint8_t*)pDataRecord, (uint8_t*)UDS_FLASH_DID_ADDR_TBL[index - UDS_EEPROM_DID_NUM], UdsSpDidTbl[index].DataLen);

       /*if finger print loaded from DFLASH is not all 0xFF, use the content in DIDRamTbl to replace the default Flash FingerPrint value*/
       if(UDS_FINGER_DID == UdsSpDidTbl[index].DataId)
       {
           if( (0xFF != DIDRamTbl[0]) && (0xFF != DIDRamTbl[1]) )
           {
               (void)memcpy((uint8_t*)pDataRecord, DIDRamTbl, UdsSpDidTbl[index].DataLen);
           }
       }  
       /*bootloader version, read from EEPROM*/
       else if (0xF084 == UdsSpDidTbl[index].DataId)
       {
           (void)FLASH_EE_Read8(BOOT_VERSION_ADDR, UDS_BOOT_SW_VER_LEN, (uint8_t*)pDataRecord);
       }
    }
    else
    {
#if 1
        pSrc = (uint8_t*)UDS_SW_DID_ADDR_TBL[index - UDS_EEPROM_DID_NUM - UDS_FLASH_DID_NUM];
        if(UdsSpDidTbl[index].DataId == 0x0A05)
        {
            memcpy((uint8_t*)(&OdoMeter), pSrc, sizeof(OdoMeter));
            OdoMeter =  OdoMeter << 8;
            (void)memcpy((uint8_t*)pDataRecord, (uint8_t*)&OdoMeter , UdsSpDidTbl[index].DataLen);
        }
        else
        {
            (void)memcpy((uint8_t*)pDataRecord, pSrc ,UdsSpDidTbl[index].DataLen);
        }
#endif    
    }

    return result;
}
 /*---------------------------------------------------------------------------
 description: write DID record int EEPROM, size align with DFLASH_PAGE_SIZE (8)
 input param:         DID -- 
 input param:     pDataRecord -- buffer holding data record content
 return:            result -- EEPROM operation result
 ---------------------------------------------------------------------------*/
 usResultType usWriteDID(uint16_t DID, uint8_t  DataRecord[])
 {
    usResultType result = US_OK;
    uint16_t tempFreq = 0;
    uint8_t tempData = 0;
    uint8_t i = 0;
    uint8_t j = 0;
    boolean WriteToDFlash = FALSE;

    if(NULL == DataRecord)
    {
        return US_FAILED;
    }
     /*SN*/
     if(DID == UDS_SN_DID)
     {
         (void)memcpy(&DIDRamTbl[UDS_FINGER_LEN], DataRecord, UDS_ECU_SN_LEN);
         WriteToDFlash = TRUE;
     }

    /*VIN*/
    else if(DID == UDS_VIN_DID)
    {
        (void)memcpy(&DIDRamTbl[UDS_FINGER_LEN + UDS_ECU_SN_LEN], DataRecord, UDS_VIN_LEN);
        WriteToDFlash = TRUE;
    }
    /*Manufaction date*/
    else if(DID == UDS_MANU_DATE_DID)
    {
        (void)memcpy(&DIDRamTbl[UDS_FINGER_LEN + UDS_ECU_SN_LEN + UDS_VIN_LEN], DataRecord, UDS_MANU_DATE_LEN);
        WriteToDFlash = TRUE;
    }    

    /*vehicle function configuration*/
    else if(DID == UDS_FUN_CFG_DID)
    {
        (void)memcpy(&DIDRamTbl[UDS_FINGER_LEN + UDS_ECU_SN_LEN + UDS_VIN_LEN + UDS_MANU_DATE_LEN], DataRecord, UDS_FUN_CFG_LEN);
        /*read new ECU config to RAM immediately*/
        (void)memcpy( &ECU_FUN_CFG_Byte, &DIDRamTbl[UDS_FINGER_LEN + UDS_ECU_SN_LEN + UDS_VIN_LEN + UDS_MANU_DATE_LEN],  UDS_FUN_CFG_LEN);
        ECU_FUN_CFG_Valid = 1;
        WriteToDFlash = TRUE;
    }    

    /*VCU feature configuration*/
    else if(DID == UDS_VCU_CFG_DID)
    {
        (void)memcpy(&DIDRamTbl[UDS_FINGER_LEN + UDS_ECU_SN_LEN + UDS_VIN_LEN + UDS_MANU_DATE_LEN + UDS_FUN_CFG_LEN], DataRecord, UDS_VCU_CFG_LEN);
        /*read new VCU config to RAM immediately*/
        (void)memcpy( &VCU_CFG_Byte, &DIDRamTbl[UDS_FINGER_LEN + UDS_ECU_SN_LEN + UDS_VIN_LEN + UDS_MANU_DATE_LEN + UDS_FUN_CFG_LEN],  UDS_VCU_CFG_LEN);
        VCU_CFG_Valid = 1;
        WriteToDFlash = TRUE;
    }    

    /*PEPS VSK Code*/
    else  if(DID == UDS_PEPS_VSK_DID)
    {
        (void)memcpy(&DIDRamTbl[UDS_FINGER_LEN + UDS_ECU_SN_LEN + UDS_VIN_LEN + UDS_MANU_DATE_LEN + UDS_FUN_CFG_LEN + UDS_VCU_CFG_LEN], DataRecord, UDS_PEPS_VSK_LEN);
        /*bug: 739 read new VSK code to RAM immediately*/
        (void)memcpy( &PEPS_VSK_Byte, &DIDRamTbl[UDS_FINGER_LEN + UDS_ECU_SN_LEN + UDS_VIN_LEN + UDS_MANU_DATE_LEN + UDS_FUN_CFG_LEN + UDS_VCU_CFG_LEN], UDS_PEPS_VSK_LEN);
        WriteToDFlash = TRUE;
    }

     /*CCP config*/
    else  if(DID == UDS_VCU_CCP_DID)
    {
        (void)memcpy(&DIDRamTbl[UDS_FINGER_LEN + UDS_ECU_SN_LEN + UDS_VIN_LEN + UDS_MANU_DATE_LEN + UDS_FUN_CFG_LEN +UDS_VCU_CFG_LEN +UDS_PEPS_VSK_LEN + UDS_PEPS_PIN_LEN], DataRecord, UDS_VCU_CCP_LEN);
        /*read new config to RAM immediately*/
        (void)memcpy( &VCU_CCP_Byte, &DIDRamTbl[UDS_FINGER_LEN + UDS_ECU_SN_LEN + UDS_VIN_LEN + UDS_MANU_DATE_LEN + UDS_FUN_CFG_LEN +UDS_VCU_CFG_LEN +UDS_PEPS_VSK_LEN + UDS_PEPS_PIN_LEN], UDS_VCU_CCP_LEN);
        if( 1==VCU_CCP_Byte[0] )
        {
            VCU_CCP_Valid = 1;
        }
        else
        {
            VCU_CCP_Valid = 0;
        }
        WriteToDFlash = TRUE;
    }
    else if (DID == UDS_PEPS_PIN_DID)
    {
        (void)memcpy(&DIDRamTbl[UDS_FINGER_LEN + UDS_ECU_SN_LEN + UDS_VIN_LEN + UDS_MANU_DATE_LEN + UDS_FUN_CFG_LEN + UDS_VCU_CFG_LEN + UDS_PEPS_VSK_LEN], DataRecord, UDS_PEPS_PIN_LEN);
        WriteToDFlash = TRUE;
    }
     /*LS_OUT control of HW testing*/
     else if(DID == UDS_HWTEST_LSCTL_DID)
     {
         for( i=0; i<UDS_HWTEST_LSCTL_LEN; i++)
         {
             for( j=0; j<8; j++)
             {
                 if( (j+i*8) > LS_NUM)
                     break;

                  Bios_LS_Output[j+i*8] = ( DataRecord[i] & (0x1<<j) ) >> j;
             }

         }
     }
     /*HS_OUT control of HW testing*/
      else if(DID == UDS_HWTEST_HSCTL_DID)
      {
          Bios_HS_Output[2] = DataRecord[0] & 0x1 ; ////HS1_OUT1
          Bios_HS_Output[3] = ( DataRecord[0] & (0x1<<1) ) >> 1;
          Bios_HS_Output[4] = ( DataRecord[0] & (0x1<<2) ) >> 2;
          Bios_HS_Output[5] = ( DataRecord[0] & (0x1<<3) ) >> 3;////HS1_OUT4
          Bios_HS_Output[0] = ( DataRecord[0] & (0x1<<4) ) >> 4; //HS2_OUT1
          Bios_HS_Output[1] = ( DataRecord[0] & (0x1<<5) ) >> 5; //HS2_OUT2

      }
     /*HB_OUT control of HW testing*/
      else if(DID == UDS_HWTEST_HBCTL_DID)
      {
          NCV7719_data.CH1_6.B.SRR = 1;
          NCV7719_data.CH1_6.B.HBSEL = 0;
          NCV7719_data.CH1_6.B.ULDSC = 0;
          NCV7719_data.CH7_8.B.SRR = 0;
          NCV7719_data.CH7_8.B.HBSEL = 1;
          NCV7719_data.CH7_8.B.ULDSC = 0;

          NCV7719_data.CH1_6.B.OVLO = 1;
          NCV7719_data.CH1_6.B.HBEN1 = 1;
          NCV7719_data.CH1_6.B.HBEN2 = 1;
          NCV7719_data.CH1_6.B.HBEN3 = 1;
          NCV7719_data.CH1_6.B.HBEN4 = 1;
          NCV7719_data.CH1_6.B.HBEN5 = 1;
          NCV7719_data.CH1_6.B.HBEN6 = 1;
          NCV7719_data.CH7_8.B.OVLO = 1;
          NCV7719_data.CH7_8.B.HBEN7 = 1;
          NCV7719_data.CH7_8.B.HBEN8 = 1;
          NCV7719_data.CH1_6.B.HBCNF1 = DataRecord[0] & 0x1;
          NCV7719_data.CH1_6.B.HBCNF2 = ( DataRecord[0] & (0x1<<1) ) >> 1;
          NCV7719_data.CH1_6.B.HBCNF3 = ( DataRecord[0] & (0x1<<2) ) >> 2;
          NCV7719_data.CH1_6.B.HBCNF4 = ( DataRecord[0] & (0x1<<3) ) >> 3;
          NCV7719_data.CH1_6.B.HBCNF5 = ( DataRecord[0] & (0x1<<4) ) >> 4;
          NCV7719_data.CH1_6.B.HBCNF6 = ( DataRecord[0] & (0x1<<5) ) >> 5;
          NCV7719_data.CH7_8.B.HBCNF7 = ( DataRecord[0] & (0x1<<6) ) >> 6;
          NCV7719_data.CH7_8.B.HBCNF8 = ( DataRecord[0] & (0x1<<7) ) >> 7;
      }
     /*PWM_OUT control of HW testing*/
      else if(DID == UDS_HWTEST_PWMCTL_DID)
      {
          for(i=0; i<8; i++)
          {
              tempData = DataRecord[i*3];
              tempFreq = tempData;//DataRecord[i*3];
              tempFreq = tempFreq << 8;
              tempData = DataRecord[i*3+1];
              tempFreq += tempData;
              tempData = DataRecord[i*3+2];

              HWTest_etpu_pwm_update(i, tempFreq, tempData*100);
          }
      }
     /*CAN control of HW testing*/
     else if(DID == UDS_HWTEST_CANCTL_DID)
     {
          if(DataRecord[0] == 1)
          {
             LINFlexD_1.LINIER.B.DTIE = 0; /* Disable TX Interrupt */
             LINFlexD_1.LINIER.B.DRIE = 0; /*Disable RX Interrupt */
             CanComTest = ReadyToSend;
             lintest = 1;
	  }
          else if(2 == DataRecord[0])
            {
              CanComTest = ReadyToSend;
              LINFlexD_1.LINIER.B.DTIE = 0; /* Disable TX Interrupt */
              LINFlexD_1.LINIER.B.DRIE = 0; /*Disable RX Interrupt */
              lintest = 1;
            }
            else if(0 == DataRecord[0])
            {
               CanComTest = DontSending;
               LINFlexD_1.LINIER.B.DTIE = 1; /* Enable TX Interrupt */
               LINFlexD_1.LINIER.B.DRIE = 1; /* Enable RX Interrupt */
               lintest = 0;
            }
     }

    else
    {
        result = US_FAILED;
    }    
    if((US_OK == result) && (TRUE == WriteToDFlash))
    {
        DFlashRWStatus   = DFlashRWStatus | DFLASH_WRITE_DID;    /*set on the Write DID to DFlash request*/
    }
    
    return result;
 }

 /*---------------------------------------------------------------------------
description: read PEPS PIN code from EEPROM
input param:         DID -- 
input param:     pDataRecord -- buffer holding PIN
return:            result -- EEPROM operation result
---------------------------------------------------------------------------*/
usResultType usReadPepsPinCode(uint8_t * pDataRecord)
{
     if(NULL == pDataRecord)
     {
       return US_FAILED;
     }
     else
     {
         (void)memcpy(pDataRecord, &DIDRamTbl[UDS_FINGER_LEN + UDS_ECU_SN_LEN + UDS_VIN_LEN + UDS_MANU_DATE_LEN + UDS_FUN_CFG_LEN + UDS_VCU_CFG_LEN + UDS_PEPS_VSK_LEN], UDS_PEPS_PIN_LEN);
     }
    return US_OK;
}
 
 /*---------------------------------------------------------------------------
   description: this function is called for HW test, update the output from core 0 to core 1
   input param:       void
   output param:     HWTest_etpu_pwm_update
   return:            void
 ---------------------------------------------------------------------------*/
void HWTest_etpu_pwm_update(uint8_t channel, uint32_t freq, uint16_t duty)
{
    udsHWTestPwmCtrl[channel].freq = freq;
    udsHWTestPwmCtrl[channel].duty = duty;
}

/*---------------------------------------------------------------------------
  description: this function write the new ESCL key into DFLASH
  input param:       key -- new ESCL key
  output param:     void
  return:            void
---------------------------------------------------------------------------*/
void WriteEsclKey(uint32_t key)
{
    uint32_t newKey;

    newKey = key;
    (void)memcpy(&DIDRamTbl[UDS_FINGER_LEN + UDS_ECU_SN_LEN + UDS_VIN_LEN + UDS_MANU_DATE_LEN + UDS_FUN_CFG_LEN +UDS_VCU_CFG_LEN +UDS_PEPS_VSK_LEN + UDS_PEPS_PIN_LEN + UDS_VCU_CCP_LEN], \
            (void*)&newKey,  UDS_ESCL_KEY_LEN);

    DFlashRWStatus   = DFlashRWStatus | DFLASH_WRITE_DID;    /*set on the Write DID to DFlash request*/
    /*update the ESCL key transmitted to Core1*/
    currEsclKey = key ^ ESCL_FIX_CODE;
}
 /*============================= following is Calibration relevant functions=========================================*/
 void NVM_Cal_Init(void)
{
     gbCalDataChecked = FALSE;
     gbCalDataCorrect = TRUE;
}
 /*---------------------------------------------------------------------------
 description: this function check the calibration data CRC. calibration data size ix 0xFB00, checking the CRC cost much time, 
 so don't call this function at initialize phase, and the CRC checking should only be executed once.
 input param:       void
 output param:     void
 return:            void
 ---------------------------------------------------------------------------*/
void NVM_CheckCal(void)
{
     uint32_t CalDataAddr;
     uint32_t CalDataLen;
     uint32_t storedCrc;   /*CRC stored in PFLASH */
     uint32_t calcedCrc;   /*CRC calculated based on calibration data*/
     uint32_t offset;
     uint8_t i;

    if(TRUE == gbCalDataChecked)
    {
       return;
    }
    gbCalDataChecked = TRUE;
    for(i = 0; i < CAL_DATA_BLOCK_NUM; i++)
    {
              
        /*read out the start address  length and CRC in PFLASH */
        (void)memcpy((uint8_t*)&CalDataAddr, (uint8_t*)(CAL_BLK_RECORD_ADDR + i*CAL_BLK_RECORD_LEN), sizeof(CalDataAddr));
        (void)memcpy((uint8_t*)&CalDataLen, (uint8_t*)(CAL_BLK_RECORD_ADDR + sizeof(CalDataAddr) + i*CAL_BLK_RECORD_LEN), sizeof(CalDataLen));
        (void)memcpy((uint8_t*)&storedCrc, (uint8_t*)(CAL_BLK_RECORD_ADDR + sizeof(CalDataAddr) + sizeof(CalDataLen) + i*CAL_BLK_RECORD_LEN), sizeof(storedCrc));
        /*address  is in correct range, copy calibration data from PFLASH*/        
        if((CalDataAddr >=  CAL_DATA_PFLASH_ADDR) && (CalDataAddr <= CAL_PFLASH_END_ADDR))
        {
            offset = CalDataAddr - CAL_DATA_PFLASH_ADDR;
            /*limit calibration data length in correct range*/
            if(CalDataLen > (CAL_DATA_SIZE - offset))
            {
                CalDataLen = CAL_DATA_SIZE - offset;
            }
            /*make sure the whole calibration data block is in correct range*/
            if((CAL_DATA_RAM_ADDR + offset+CalDataLen) <= (CAL_DATA_RAM_ADDR + CAL_DATA_SIZE))
            {
                calcedCrc = CalcCrc32((uint8_t*)(CAL_DATA_RAM_ADDR + offset), (uint16_t) CalDataLen);
                if(calcedCrc != storedCrc)
                {
                    gbCalDataCorrect = FALSE;
                }                    
            }
        }
        else
        {
            break;
        }
    }
}



#ifndef UDS_SERVICE_H_
#define UDS_SERVICE_H_
/*
 *
 * Copyright (c) 2016 SIEMENS AG. All Rights Reserved.
 *
 */

/*! @file uds_service.h
    @details details description on this header file
	implement the UDS service features
*/

#include "Global.h"
#include "Ex_Data.h"
#ifdef MASTER_UDS_SERVICE_
	#define UDS_SER_EXTERNAL_
#else
	#define UDS_SER_EXTERNAL_  extern
#endif

/* -----------------------------------------------------------------------------
    Includes
------------------------------------------------------------------------------*/
/* -----------------------------------------------------------------------------
    Global Macro Definitions
------------------------------------------------------------------------------*/
#define SP_DTC_STATUS    0x2B            /*only bit 0, 1, 3 and 5 are supported*/
#define CURR_DTC_STATUS 0x23          /*current failed DTC, bit 0, bit 1 and bit 5 is 1*/
#define HIST_DTC_STATUS 0x28           /*hisitorical failed DTC ,  bit 3 and bit 5 is 1*/
//@@@@#define UDS_UNIT_TEST         

#define UDS_VIN_LEN 		17			/*VIN length is 17 bytes*/
#define UDS_PART_LEN 		21			/*part number length is 21 bytes*/
#define UDS_SUPPLIER_LEN 	8			/*supplier code length is 7 bytes*/
#define UDS_HW_VER_LEN 	12			/*HW version length is 12 bytes*/
#define UDS_SW_VER_LEN 	12			/*SW version length is 12 bytes*/
#define UDS_ECU_SN_LEN        13                  /*ECU Serial Number  length is 13 bytes*/
#define UDS_MANU_DATE_LEN 	4		/*vehicle Manufacturing Date bytes*/
#define UDS_FUN_CFG_LEN     6                    /*system feature configuration*/
#define UDS_NET_INFO_LEN    4                   /*network Information DataIdentifier length = 4*/
#define UDS_FUN_INFO_LEN    4                   /*function Information DataIdentifier length = 4*/
#define UDS_DIAG_INFO_LEN    4                   /*diagnosis Information DataIdentifier length = 4*/
#define UDS_APP_SW_VER_LEN 8                 /*supplier defined appication SW version  length = 8*/
#define UDS_BOOT_SW_VER_LEN 8               /*supplier defined bootloader SW version length =8 */
#define UDS_CAL_SW_VER_LEN 8                 /*supplier defined calibration SW version length =8 */
#define UDS_ECU_HW_VER_LEN 8                /*supplier defined ECU HW version length =8 */
#define UDS_ECU_SW_VER_LEN 8                /*supplier defined ECU SW version length =8 */
#define UDS_FINGER_LEN 		7			/*finger print length is 7 bytes*/
#define UDS_PEPS_VSK_LEN    16                /*PEPS VSK code length  = 17 bytes */
#define UDS_VCU_CFG_LEN     8                 /*VCU feature configuration length = 8 bytes*/
#define UDS_PEPS_PIN_LEN 4                      /*PEPS PIN size*/

#define UDS_VCU_CCP_LEN    1             /*CCP control*/
#define UDS_ESCL_KEY_LEN 4             /*ESCL key length*/

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


/* for Hardware testing */
#define UDS_HWTEST_LSCTL_LEN	2			/*LS_output*/
#define UDS_HWTEST_HSCTL_LEN	1			/*HS_output*/
#define UDS_HWTEST_HBCTL_LEN	1			/*HBridge Out*/
#define UDS_HWTEST_PWMCTL_LEN	24			/*PWMO 1~8*/
#define UDS_HWTEST_CANCTL_LEN	1			/*testFrameCtrl: 0 not send; 1 send*/
#define UDS_HWTEST_DINSTS_LEN	5			/*DIN1~31, WakeUP1~2*/
#define UDS_HWTEST_ADCSTS_LEN	56			/*ADC_Out*/
#define UDS_HWTEST_PWMSTS_LEN	18			/*PWM status*/
#define UDS_HWTEST_FLTSTS_LEN	20			/*fault status: LS+HS+Hbridge*/

#define UDS_HWTEST_LSCTL_DID	0x0C01			/*LS_output*/
#define UDS_HWTEST_HSCTL_DID	0x0C02			/*HS_output*/
#define UDS_HWTEST_HBCTL_DID	0x0C03			/*HBridge Out*/
#define UDS_HWTEST_PWMCTL_DID	0x0C04			/*PWMO 1~8*/
#define UDS_HWTEST_CANCTL_DID	0x0C05			/*testFrameCtrl: 0 not send; 1 send*/
#define UDS_HWTEST_DINSTS_DID	0x0B01			/*DIN1~31, WakeUP1~2*/
#define UDS_HWTEST_ADCSTS_DID	0x0B02			/*ADC_Out*/
#define UDS_HWTEST_PWMSTS_DID	0x0B03			/*PWM status*/
#define UDS_HWTEST_FLTSTS_DID	0x0B04			/*fault status*/
/* end for Hardware testing*/

	/* for Action test with diagnostic instrument*/
#define UDS_ACTDIAG_MAINRELAY_DID 	0xD100  /*MainRelay control*/
#define UDS_ACTDIAG_MCURELAY_DID 	0xD101  /*MCURelay control*/
#define UDS_ACTDIAG_BRKLIGHT_DID    0xD102 /*brake light control*/
#define UDS_ACTDIAG_MAINRELAY_LEN 	1  /*MainRelay control*/
#define UDS_ACTDIAG_MCURELAY_LEN 	1  /*MCURelay control*/
#define UDS_ACTDIAG_BRKLIGHT_LEN   1  /*brake light control*/
	/* end for Action test*/

/*DID number*/
#define UDS_FINGER_DID              0xF184
#define UDS_SN_DID                0xF18C
#define UDS_VIN_DID                0xF190
#define UDS_MANU_DATE_DID           0xF1A2
#define UDS_FUN_CFG_DID           0xF1FA
#define UDS_PEPS_VSK_DID     0x0A15
#define UDS_VCU_CFG_DID       0xF1FD
#define UDS_PEPS_PIN_DID         0x0A16

#define UDS_VCU_CCP_DID         0x0AFA			 /* to control CCP */

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

#define MAX_BLOCK_LENGTH  0x100 

/* -----------------------------------------------------------------------------
    Function-like Macro Definition
------------------------------------------------------------------------------*/

/* -----------------------------------------------------------------------------
    Global Type Definitions
------------------------------------------------------------------------------*/
    /* ===================== Private Type Definitions=========================*/
    typedef enum udsSecAStatus
    {
        UDS_LOCKED_SECA  = 0x0,         /*not in Security Access = locked*/
        UDS_SEED_SECA  = 0x1,         /*Get Seed already passed */
        UDS_UNLOCK_SECA  = 0x2     /*Cmpare key already passed, unlocked */
    }udsSecAStatusType;

/* -----------------------------------------------------------------------------
    Global Constant Declarations
------------------------------------------------------------------------------*/
#define UDS_SECA_DELAYTIMER    60000     /*power up, delay 1mins to execute 27 service*/
#define UDS_BOOT_DELAY              40       
#define UDS_RESET_DELAY             10
#define UDS_EXTSESSION_TIME	5000		/*extended session can be kept for 5000ms*/
#define UDS_0x78_INTERVAL        4000         /*take the task-scheduling time into account, the NRC 0x78 interval is 4500 ms */
#define UDS_TEST_EXT_DELAY       300000    /*test mode, delay in extended session for 5 minutes*/

#define VEHICLE_STOP_LIMIT   89           /*CAN signal ABS_VehicleSpeed factor is 0.0563, speed limit is 5km/h, so the value is 89*/
#define MOTOR_SPPED_OFFSET  12000 /*CAN signal MCUElecMotSpd  offset is 12000*/
#define MOTOR_STOP_LIMIT     100      /*CAN signal MCUElecMotSpd  offset is 12000, speed limit absolute value is 100 rpm*/

#define P2_SERVER				50  		/*P2Server value*/
#define P2_STAR_SERVER			5000	 /*P2*Server value*/
#define DELAY_BEFORE_RESET      50
#define UDS_SECA_GETSEED  		0x1		/*sub function of SecA -- GetSeed*/
#define UDS_SECA_CHKKEY  		0x2		/*sub function of SecA -- check key*/
#define UDS_10_REQ_LEN               2            /*service 0x10 length must be 2*/
#define UDS_DTC_ON				0x1
#define UDS_DTC_OFF			0x2
#define UDS_ERASE_MEM	              0xFF00	/*supported routine ID: Erase Memory (jump to bootloader directly)*/
#define UDS_CHEK_PEPS_PIN         0xFF02   /*check PEPS PIN code*/
#define UDS_START_ROUTINE		0x1
#define UDS_ERASE_OK	              0x1
#define UDS_ERASE_NOK	              0x0
#define UDS_CHK_PIN_OK               0x1
#define UDS_CHK_PIN_NOK             0x0

#define UDS_ERASE_ESCL              0xE220
#define UDS_GENKEY_ESCL             0xE221
#define UDS_PROG_ESCL               0xE222
#define UDS_FORCE_ERASE_ESCL  0xE224
#define UDS_ESCL_BUSY               0
#define UDS_ESCL_SUCCESS            1
#define UDS_ESCL_FAILED             2
#define ESCL_MIN_OPER_TIME         500              /*minimum ESCL operation time is 500ms*/

#define UDS_HWTEST_CTL		0xFF10	/*control VCU HW testing*/
#define UDS_START_HWTEST		0x1
#define UDS_HWTEST_WRITEDFLASH		0xFF21	/*write VCU DFLASH */
#define UDS_HWTEST_WRITEEEPROM		0xFF31	/*write VCU EEPROM */
#define UDS_HWTEST_READDFLASH		0xFF20	/*read VCU DFLASH */
#define UDS_HWTEST_READEEPROM		0xFF30	/*read VCU EEPROM */
#define UDS_AGINGTEST_CTL		0xFF11	/*control VCU HW aging test*/
#define UDS_SECA_GETSEED_HWTEST  		0x11		/*sub function of hw test SecA -- GetSeed*/
#define UDS_SECA_CHKKEY_HWTEST  		0x12		/*sub function of hw test SecA -- check key*/
#define UDS_HWTEST_MASK			0x03FF2020	/* ECU_MASK to calculate SecA key (defined by GuoJiZhiJun)*/

#define UDS_ECU_MASK			0x72F40507	/* ECU_MASK to calculate SecA key (defined by GuoJiZhiJun)*/

#define UDS_EEPROM_DID_NUM     9   /*7+1(CCPctrl) DID stored in EEPROM (inc FingerPrint, except PEPS_PIN code */
#define UDS_FLASH_DID_NUM      12   /*12 DID stored in FLASH , there are constant*/
#define UDS_VEHICLE_DID_NUM     21         /*vehicle level DID number is 21, other is SW running DID*/
#define UDS_SP_DID_NUM			91	/*supported Data Id num = VehicleDID(21) + SnapshotDTD(43) + AddDIDnotInSnapshot(27)*/
#define UDS_NOTSNAPSHOT_DID_NUM	27   /* the App DID not in snapshot 27  */
#define UDS_HW_TEST_DID_NUM   9

#define UDS_MAX_DID_LEN		120		/*Maximum data record length for Read/Write Data by ID*///helei:add for test .default 24

#define UDS_SNAP_NUM_PER_DTC   2          /*each DTC have 1 current snapshot +1 historical snapshots*/
#define UDS_HISTO_SNAP_NUM        1         /*1 historical snapshot*/
#define UDS_CLR_DTC_ONE_TIME    1        /*clear 1 DTCs one time*/
#define SN_DID_POS                      5          /*SN is the 5th in UdsSpDidTbl*/
#define VIN_DID_POS                     6          /*VIN is the 6th in UdsSpDidTbl*/
#define MANU_DATE_DID_POS       7          /*manufaction date is the 7th in UdsSpDidTbl*/
#define FUN_CFG_DID_POS       8          /*feature configuration is the 8th in UdsSpDidTbl*/
/* -----------------------------------------------------------------------------
    Global type Declarations
------------------------------------------------------------------------------*/
    typedef struct udsDID
    {
        uint16_t  DataId;                 /*2 bytes DID*/
        uint8_t    DataLen;              /*length*/
        boolean  WriteFlag;           /*can be written*/
    }udsDIDType;


typedef enum udsService
{
    UDS_NOP_SERVICE = 0x0,               /*NOP uds service*/
	UDS_SESSION_CTRL = 0x10, 		/*session control*/
	UDS_RESET = 0x11, 				/*reset*/
	UDS_CLEAR_DTC = 0x14, 			/*clear DTC*/
	UDS_READ_DTC = 0x19, 			/*Read DTC*/
	UDS_READ_DATA_DID = 0x22, 	/*Read Data by ID*/
	UDS_SEC_ACCESS = 0x27, 		/*security Access*/
	UDS_COMM_CTRL = 0x28, 			/*communication control*/
	UDS_WRITE_DATA_DID = 0x2E, 	/*write Data by ID*/
	UDS_IO_CTRL = 0x2F,               /*UDS IO control*/	
	UDS_ROUTINE_CTRL = 0x31, 		/*Routine Control*/
	UDS_REQ_UPLOAD = 0x35,
        UDS_TRANSFER_DATA = 0x36,      /*trasnfer data*/
        UDS_TRANSFER_EXIT = 0x37,      /*trasnfer exit*/
	UDS_TESTER_PRESENT = 0x3E, 	/*Tester present*/
	UDS_DTC_SET = 0x85 			/*DTC Setting*/
}udsServiceType;

typedef enum udsSession
{
	UDS_SESSION_DEFAULT = 0x1, 		/*default session*/
	UDS_SESSION_PROGRAM = 0x2, 		/*pogramming session*/
	UDS_SESSION_EXTENDED = 0x3 		/*extended session*/
}udsSessionType;


typedef enum udsReset
{
    UDS_NO_RESET = 0x0,                 /*No reset*/
    UDS_HARD_RESET = 0x1,                 /*hard reset*/
    UDS_SOFT_RESET = 0x3,                 /*soft reset*/
    UDS_BOOT_PREPARE = 0x4,               /*reset to bootloader*/
    UDS_BOOT_RESET = 0x5               /*reset to bootloader*/
}udsResetType;


extern udsIOCTRLDIDType IOCtrlDidTbl[3];
#define UDS_IOCTRL_TYPE_ECU    0x00        /*Return Control To ECU*/
#define UDS_IOCTRL_TYPE_UDS    0x03        /*Short Term Adjustment*/

/* -----------------------------------------------------------------------------
    Global Function Declarations
------------------------------------------------------------------------------*/
void udsServiceInit(void);
void udsServiceMain(void);
void udsServiceTask(void);
/* =================  Global Variable Declarations =========================*/
UDS_SER_EXTERNAL_  const udsDIDType UdsSpDidTbl[UDS_SP_DID_NUM + UDS_HW_TEST_DID_NUM ] ;
UDS_SER_EXTERNAL_  const uint32_t udsSpDTCTbl[UDS_SP_DTC_NUM]  ;

UDS_SER_EXTERNAL_ uint8_t udsSecAFailedCount;
UDS_SER_EXTERNAL_ uint32_t udsSecAFailedTick;
UDS_SER_EXTERNAL_ uint32_t udsSecAFailedDelayTimer;

/* -----------------------------------------------------------------------------
    Global Inline Function Definitions
------------------------------------------------------------------------------*/

#endif /* UDS_SERVICE_H_ */


/*
 * Global.h
 *
 *  Created on: 2018年10月8日
 *      Author: helei
 */

#ifndef HAL_GLOBAL_H_
#define HAL_GLOBAL_H_

#include "typedefs.h"
#include "derivative.h"
#include "BASE_Global.h"
#include "rtwtypes.h"
#include "FS65xx.h"
#include  "CAN.h"
#ifdef __GLOBAL_GLOBALS__
#define __GLOBALS_EXTERN__
#else
#define __GLOBALS_EXTERN__  extern
#endif

#define   SW_NUM 31
#define   ADC_NUM 28
#define   FRE_NUM 4
#define   LS_NUM 14
#define   HS_NUM 6
#define  PWM_NUM 8
#define WAKEUPSRC_UNKNOWN  0     /*wakeup source not checked out, unknown state*/
#define WAKEUPSRC_INVALID  1      /*all wakeup sources become invalid*/
#define WAKEUPSRC_HWWAKE  2
#define WAKEUPSRC_NETWORK 3

#define FLAGOFINITRAM_VALUE	(0x44u)

/*BSw calibration data  需要同Core1定义的顺序完全相同！！！*/
extern unsigned char Vehicle_Type;
extern unsigned char S11_Mark;
extern unsigned char K11_Mark;
extern unsigned char S11P01_Mark;
extern unsigned char A11_Mark;
extern unsigned char K11P01_Mark;
extern unsigned char S11P03_Mark;
extern unsigned char S21_Mark;
extern unsigned char K11E01R_Mark;
extern unsigned char S11P05_Mark;
extern unsigned char K11P06_Mark ;
extern unsigned char Authentication_flg;
extern unsigned char KACMiddleVoltage_flg;
extern uint8_t MaxDaqRetryTime ; /*after DAQ transmission tried for 2 ms, give up*/
extern unsigned char KHALI_DisRelayWhenCanOff;
extern unsigned char KUDS_TestFeature;
extern unsigned char KUDS_SupportOldBoot;
extern unsigned short KUDS_ABSStopedSpeed;
extern unsigned short KUDS_MotorStopedSpeed;
extern boolean KUDS_IOCtrlEnable; /*1: IO 控制功能打开*/
extern uint32_t PeriodSendInvalidMsg; /*CR 1082:  the initialize time is 100ms, the period that send invalid CAN message is 900, set the time to 850 */
extern unsigned char KNVM_SelfClrCycle; /*CR1088: DTC self clear operation cycle, 0: disable self clear feature*/
extern uint16_t MaxAppDataLoadTime; /*application data loading must be finished in 1800ms*/
extern uint16_t MaxAppDataSaveTime; /*application data saving must be finished in 2000ms (erase two DFLASH nees about 800ms , save 10 page EEPROM costs about 400ms )*/
extern uint16_t NEDC_Milg_kmU;
extern uint16_t Eco_egyCnse_1km_c;
extern uint8_t zone_km_c;
extern unsigned char KHALI_DisRelayWhenCanOff;
extern unsigned char KUDS_TestFeature;
extern unsigned char KUDS_SupportOldBoot;
extern unsigned short KUDS_ABSStopedSpeed;
extern unsigned short KUDS_MotorStopedSpeed;
extern boolean KUDS_IOCtrlEnable; /*1: IO 控制功能打开*/

/*blue tooth relevant calibration parameters*/
//extern unsigned char KHALI_VCUActAsPeps;    /*1: VCU acting as PEPS to sample SSB, control the IGN1/IGN2 relay*/
extern uint16_t KHALI_Escl_InitDelay;
extern uint16_t KHALI_Escl_TimeOut_1;
extern uint16_t KHALI_Escl_TimeOut_2;
extern uint16_t KHALI_Escl_TimeOut_31;
extern uint16_t KHALI_Escl_TimeOut_32;
extern uint16_t KHALI_Escl_TimeOut_33;
extern uint16_t KHALI_Escl_TimeOut_4;
extern uint16_t KHALI_Escl_TimeOut_5;
extern uint16_t KHALI_Escl_ProgKeyInterval;
extern uint32_t KHALI_Escl_ForceEraseDuration ;
extern unsigned char KHALI_Escl_TasckStep;
//extern unsigned char KHALI_Escl_Installed ;

extern boolean IGN1_FeedVoltCorrect;    /*IGN1 relay feedback voltage correct*/
extern boolean IGN2_FeedVoltCorrect;    /*IGN1 relay feedback voltage correct*/
extern boolean SSB_SyncCorrect;   /*FALSE: SSB two switches not synchronized; TRUE: two switches are synchronized*/
/*blue tooth relevant calibration parameters*/



extern CORE0_INIT uint8_t FlagOfInitRam;

extern uint8_t K11E01R_Mark;
/********************	模式 && 系统*******/
extern volatile uint32_t SystemTickMs;	//全局时钟，分辨率为1ms :: define in Task.c

extern uint8_t HW_udsDiag_flag;
extern uint8_t tpUdsCANRecv[8];
extern uint8_t UdsRecvChannel;
//DualCore Communication
extern uint8_t RestartCore0;
extern uint32_t ErrTimesInSI0;
extern uint32_t InfoTimesRestart;

extern unsigned char Bios_Sw_Input[SW_NUM];
extern unsigned int ADC_OutBuff[ADC_NUM];
extern unsigned char Bios_LS_Output[LS_NUM];
extern unsigned char Bios_HS_Output[HS_NUM];

extern uint8_t EnetTestMaster;
extern uint8_t bswWakeSrc;

/******************	UDS && CCP	*******/
typedef enum NvMLoadSave
{
	NvMDataLoading = 0, /*data is being loaded from NVM*/
	NvMDataLoaded = 1, /* all app data areas loaded from NVM*/
	NvMDataSaving = 2, /*data is being saved to NVM*/
	NvMDataSaved = 3, /*all  app data areas saved to NVM*/
} NvMLoadSaveType;

typedef struct udsIOCTRLDID
{
	uint16_t DataId; /*2 bytes DID*/
	uint8_t DataLen; /*length*/
	boolean Enable; /*Enabled or not  1: IO 控制功能打开，输出不受应用层影响*/
	uint8_t Status;
} udsIOCTRLDIDType;

#define UDS_SP_DTC_NUM			199	     /*supported DTC number:  188+2+1+1+6+1 2021-8-4 changed*/

typedef enum UDS_CtrlType
{
	UDS_EnRx_EnTx = 0x0,
	UDS_EnRx_DisTx = 0x1,
	UDS_DisRx_EnTx = 0x2,
	UDS_DisRx_DisTx = 0x3
} UDS_CtrlType;
typedef enum UDS_CommType
{
	UDS_NorCom = 0x1, /*Normal Communication Messages*/
	UDS_NetMgr = 0x2, /*Network Management  Messages*/
	UDS_NorCom_NetMgr = 0x3 /*Normal Communication and Network Management  Messages*/
} UDS_CommType;

typedef struct _BTS_data_tag_
{
	uint8_t status;
	uint32_t ADvalue;
	float mA;
	uint8_t openload;
	uint8_t shortload;
} _BTS_data_;

typedef union _NCV7513B_SI_data_tag_
{
	vuint16_t R;
	struct
	{
		vuint16_t :1;
		vuint16_t address :3;
		vuint16_t :6;
		vuint16_t data :6;
	} command;
} _NCV7513B_SI_data_;

typedef union _NCV7513B_SO_data_tag_
{
	vuint16_t R;
	struct
	{
		vuint16_t :4;
		vuint16_t CH5 :2;
		vuint16_t CH4 :2;
		vuint16_t CH3 :2;
		vuint16_t CH2 :2;
		vuint16_t CH1 :2;
		vuint16_t CH0 :2;
	} status;
} _NCV7513B_SO_data_;

typedef union _NCV7719_INPUT1_6_tag_
{
	uint16_t R;
	struct
	{
		uint16_t SRR :1;	// 1
		uint16_t HBSEL :1;	//0
		uint16_t ULDSC :1;//0  Underload Shutdown should be set to 0, then LS can use; when set to 1, LS can't use.
		uint16_t HBEN6 :1;	//使能位1
		uint16_t HBEN5 :1;
		uint16_t HBEN4 :1;
		uint16_t HBEN3 :1;
		uint16_t HBEN2 :1;
		uint16_t HBEN1 :1;
		uint16_t HBCNF6 :1;	//选择位HS(1)/LS(0)
		uint16_t HBCNF5 :1;
		uint16_t HBCNF4 :1;
		uint16_t HBCNF3 :1;
		uint16_t HBCNF2 :1;
		uint16_t HBCNF1 :1;
		uint16_t OVLO :1;	//1
	} B;
} _NCV7719_INPUT1_6_;

typedef union _NCV7719_INPUT7_8_tag_
{
	uint16_t R;
	struct
	{
		uint16_t SRR :1;	//1
		uint16_t HBSEL :1;	//1
		uint16_t ULDSC :1;	//0
		uint16_t :4;
		uint16_t HBEN8 :1;	//使能位1
		uint16_t HBEN7 :1;
		uint16_t :4;
		uint16_t HBCNF8 :1;	//选择位HS(1)/LS(0)
		uint16_t HBCNF7 :1;
		uint16_t OVLO :1;	//1
	} B;
} _NCV7719_INPUT7_8_;

typedef struct _NCV7719_INOUTPUT_tag_
{
	_NCV7719_INPUT1_6_ CH1_6;
	uint32_t CH1_6_recive;
	_NCV7719_INPUT7_8_ CH7_8;
	uint32_t CH7_8_recive;
} _NCV7719_INOUTPUT_;

typedef union _NCV7240B_SI_data_tag_
{
	vuint16_t R;
	struct
	{
		vuint16_t channel8 :2;
		vuint16_t channel7 :2;
		vuint16_t channel6 :2;
		vuint16_t channel5 :2;
		vuint16_t channel4 :2;
		vuint16_t channel3 :2;
		vuint16_t channel2 :2;
		vuint16_t channel1 :2;
	} mode;
} _NCV7240B_SI_data_;

typedef union _NCV7240B_SO_data_tag_
{
	vuint16_t R;
	struct
	{
		vuint16_t channel8 :2;
		vuint16_t channel7 :2;
		vuint16_t channel6 :2;
		vuint16_t channel5 :2;
		vuint16_t channel4 :2;
		vuint16_t channel3 :2;
		vuint16_t channel2 :2;
		vuint16_t channel1 :2;
	} status;
} _NCV7240B_SO_data_;

/*define the HW test: PWM control test parameters from Core 0 to core 1*/
typedef struct
{
	uint16_t duty;
	uint32_t freq;
} HWTest_PwmCtrlType;

extern UDS_CtrlType AppComCtrlType;
extern UDS_CtrlType NmComCtrlType;
extern uint8_t UdsRecvChannel; /*CCP command received from which channel*/
extern unsigned char tpUdsCANRecv[8];

extern uint8_t IOCtrlEnable; /*1: IO 控制功能打开，输出不受应用层影响*/

extern _BTS_data_ BTS5180_data[2];
extern _BTS_data_ BTS5200_data[4];
/* 以太网下线检测使用 */
extern uint8_t EnetTestMaster;

/*频率量采集变量*/
extern float hIOP_CollisionSw_Hz;
extern float hIOP_CollisionSw_Duty;
extern float hIOP_WaterPwm_Hz;
extern float hIOP_WaterPwm_Duty;
extern float hIOP_HVInterlock_Hz;
extern float hIOP_Fin4_Hz;
extern uint8_t hIOP_HVInterlock_Duty;
extern uint8_t hIOP_VacuumPumpIn_Duty;

extern _NCV7513B_SO_data_ NCV7513B_SO_data;
extern _NCV7719_INOUTPUT_ NCV7719_data;
extern _NCV7240B_SO_data_ NCV7240B_SO_data;

extern boolean udsHWTestingModeStatus;
extern boolean bool_udsAgingTestStart_flag;
extern boolean bool_udsAgingTestError_flag;
extern HWTest_PwmCtrlType udsHWTestPwmCtrl[PWM_NUM];

extern _CAN_flag_ CanComTest;
extern uint8_t lintest;

extern uint8_t X11_Mark;
/*******************else part*****************************/
typedef struct
{
	uint16_t AccPdlSensor5V1;
	uint16_t AccPdlSensor5V2;
	uint8_t fastChrgSensorTemp1;
	uint8_t fastChrgSensorTemp2;
	uint8_t VCUBMSOperModeReq;
	uint8_t BMSOperMode;
	uint16_t BMSMaxDischrgPwr;
	uint16_t BMSMaxChrgPwr;
	uint16_t BMSMaxDischrgI;
	uint16_t BMSMaxChrgI;
	uint16_t BMSCC2SngR;
	uint16_t BMSCCSngR;
	uint8_t VCUDCDCOperModeReq;
	uint8_t DCDCOperMode;
	uint16_t DCDCoutputU;
	uint16_t DCDCoutputI;
	uint16_t DCDCinputU;
	uint8_t DCDCinputI;
	uint8_t VCUMCUOperModeReq;
	uint8_t MCUOperMode;
	uint8_t VCUElecMotErr;
	uint16_t VCUMotspeedReq;
	uint16_t MCUMaxAvlTorque;
	uint16_t MCUMinAvlTorque;
	uint16_t BMSIsolationR;
	uint8_t MCURelay_flg;
	uint8_t BrklightRelay_flg;
	uint8_t MainRelay_flg;
} APPDID_outSnapshots;
extern uint8_t SocResiMilgNvMCorrect;
/*temporary solution before DHP moved to Core 0, clear DTC information if $14 command received from Core 0*/
extern uint8_t currClrDTCCmdFromCore0;
/*temporary solution before DHP moved to Core 0, clear DTC information if $14 command received from Core 0*/
#define AUTHFALIED_DATA_SIZE 72   /*auth failed data size is 72 bytes*/
extern uint8_t AuthFailedData[AUTHFALIED_DATA_SIZE];
/**************************BTK  and ESCL  ***************************************************/
typedef enum BTK_EsclReqType_
{
    BTK_ESCL_NOCMD = 0,
    BTK_ESCL_UNLOCK = 1,
    BTK_ESCL_LOCK = 2,
    BTK_ESCL_PROGKEY = 3,
    BTK_ESCL_ERASEKEY = 4,    
    BTK_ESCL_FORCEERASE = 5,
} BTK_EsclReqType;

/*ESCL result  enum*/
typedef enum BTK_EsclRsltType_
{
    BTK_ESCL_SUCCESS = 0,
    BTK_ESCL_BUSY = 1,
    BTK_ESCL_UNLOCK_FAILED = 2,
    BTK_ESCL_LOCK_FAILED = 3,
    BTL_ESCL_PROGKEY_FAILED = 5,
    BTK_ESCL_ERASEKEY_FAILED = 4,
} BTK_EsclRsltType;
extern BTK_EsclReqType gblEsclOperReq;
extern BTK_EsclRsltType gblEsclRslt;
extern uint32_t newEsclKey;
extern uint32_t currEsclKey;
extern uint8_t EsclLinCommFailed;
extern uint8_t EsclStatus;
extern uint8_t EsclErrorCode;

extern uint16_t LSChip7240BFaultStatus;
extern uint8_t HSChip5180BFaultStatus;

extern boolean gblUdsECUUpgrade;
extern boolean gblUdsKeepPresent;

extern uint8_t gblNVMStateMachineSts;

#endif /* HAL_GLOBAL_H_ */

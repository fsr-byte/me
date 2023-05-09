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
#include "NCV7719.h"

#ifdef __GLOBAL_GLOBALS__
#define __GLOBALS_EXTERN__
#else
#define __GLOBALS_EXTERN__  extern
#endif

#define _HW_A0_TABLE_      0		//1：代表驱动输出使用A1的设置； 0:代表驱动输出使用B0的设置
#define USINGBOOTLOADER    0		//1:代表使用BootLoader，将去掉SBC初始化; 0:代表单件调试，需要SBC初始化。

//标定量中 双核重合部分。
#define BSWCalRamAddrStart	(0x4001B800u)
#define BSWCalRamAddrSize	(0x600u)
#define DHPCalRamAddrStart	(0x40026500u)
#define DHPCalRamAddrSize	(0x80u)


#define   SW_NUM 31
#define   ADC_NUM 28
#define   FRE_NUM 4
#define   LS_NUM 14
#define   HS_NUM 6
#define  PWM_NUM 8

#define     AddOfCodeJumpFlag     0xC78000
#define     AddOfDCTProgram  	    0xC68000
#define     AddOfDataCalibrate  	0xC58000
#define     AddOfBootLoader     	0xC000

#define    	NO_MODE			      0
#define     MONITOR_MODE	    1			//监控模式宏定义
#define    	CALIBRATE_MODE	  2			//标定模式宏定义
#define    	DIAGNOSE_MODE	    3			//诊断模式宏定义
#define    	SELFTEST_MODE		  4			//自测试模式宏定义
#define    	BOOTLOAD_MODE	    5			//bootloader模式宏定义
#define     DEBUG_MODE		    6			//系统测试模式
#define     BootUpdate_Mode 	7    	//BOOTLOADE的代码更新模式宏定义
#define     MOTORTEST_MODE  	8    	//电机测试模式宏定义
#define     ICPTEST_MODE    	9
#define     DTCTEST_MODE    	10
#define 	  CALIBRATEFLASH	  11
#define	    BOOTPCAN_MODE	    12

#define	    CAN3_GOTOSLEEP_MODE    0
#define	    CAN3_NORMAL_MODE       1
#define	    CAN3_LISTENONLY_MODE   2
#define	    CAN3_STANDBY_MODE      3
#define	    CAN3_SLEEP_MODE        4

#define UDS_SP_DTC_NUM			199 	     /*supported DTC number:  188+2+1+1+6+1 2021-8-4 changed*/
#define RUN_UDS_NVM_ON_CORE1 0   /*0: UDS and NVM can run NOT on core 1; */

#define WAKEUPSRC_UNKNOWN  0     /*wakeup source not checked out, unknown state*/
#define WAKEUPSRC_INVALID  1      /*all wakeup sources become invalid*/
#define WAKEUPSRC_HWWAKE  2
#define WAKEUPSRC_NETWORK 3
#define WAKESRC_DAMP_FACTOR 5    /*wakeup source keeps valid or invalid for 5 task cycle, change the wake up source state*/
#define MAX_NMMSG_INTERVAL   300    /*at most 300ms, a NM message should be received from GW (if GW is online)*/
/**************************************************************************************		硬线信号		*******/
extern unsigned char Bios_Sw_Input[SW_NUM];
extern unsigned int ADC_OutBuff[ADC_NUM];
extern unsigned char Bios_LS_Output[LS_NUM];
extern unsigned char Bios_HS_Output[HS_NUM];

extern unsigned char Batt12_15Vol;
extern unsigned char Batt12_30Vol;

/*开关量采集变量*/
extern unsigned char HIOP_HandBrake_flg;
extern unsigned char KACMiddleVoltage_flg;
extern unsigned char hIOP_AirSwitch_flg;
extern unsigned char hIOP_BrkLightSwitch1_flg;
extern unsigned char hIOP_Crank_flg;
extern unsigned char hIOP_GearSwitch1_flg;
extern unsigned char hIOP_GearSwitch2_flg;
extern unsigned char hIOP_GearSwitch3_flg;
extern unsigned char hIOP_GearSwitch4_flg;
extern unsigned char hIOP_ACSwitch_flg;
extern unsigned char hIOP_BrkLightSwitch2_flg;
extern unsigned char hIOP_SlowChargeAwake_flg;
extern unsigned char hIOP_FastChargeAwake_flg;
extern unsigned char hIOP_ClutchSwitch1_flg;  //YK19 离合器信号1
extern unsigned char hIOP_ClutchSwitch2_flg;  //YK19 离合器信号2
/*外接模拟量采集变量*/
extern float hIOP_AccelPedalL_V;
extern float hIOP_AccelPedalH_V;
extern float hIOP_FastChargeTemp1_V;
extern float hIOP_FastChargeTemp2_V;
/*内部模拟量采集变量*/
extern float hIOP_K15_V;
extern float hIOP_K30_V;
extern float hIOP_Sen5V1_V;
extern float hIOP_Sen5V2_V;
extern float hIOP_PCBTemp_V;
/*频率量采集变量*/
extern float hIOP_CollisionSw_Hz;
extern float hIOP_CollisionSw_Duty;
extern float hIOP_WaterPwm_Hz;
extern float hIOP_WaterPwm_Duty;
extern float hIOP_HVInterlock_Hz;
extern uint32_t hIOP_HVInterlock_PulseTime_us;
extern uint32_t hIOP_HVInterlock_PeriodTime_us;
extern float hIOP_Fin4_Hz;
extern uint8_t hIOP_HVInterlock_Duty;
extern uint8_t hIOP_VacuumPumpIn_Duty;
/*芯片唤醒信号*/
extern unsigned char hIOP_1043WKUP_flg;
/*诊断错误码*/
extern unsigned int hIOP_LSFaultCode_enum;
extern unsigned char hIOP_HSFaultCode_enum;
extern unsigned int hIOP_LSFaultCode_enum_POR;
extern unsigned char hIOP_HSFaultCode_enum_POR;
/*CAN总线各通道的Tick*/
unsigned long hIOP_VCUCanTickCount;
unsigned int hIOP_McuImportentMsg_Ticks1;
unsigned int hIOP_McuImportentMsg_Ticks2;
unsigned int hIOP_BmsImportentMsg_Ticks1;
unsigned int hIOP_BmsImportentMsg_Ticks2;
unsigned int hIOP_BmsImportentMsg_Ticks3;
unsigned int hIOP_DCDCImportentMsg_Ticks1;
unsigned int hIOP_DCDCImportentMsg_Ticks2;
unsigned int hIOP_ICMImportentMsg_Ticks1;
/*低驱驱动信号*/
extern unsigned char hIOP_MCURelay_flg;
extern unsigned char hIOP_LSpdFan_flg;
extern unsigned char hIOP_HSpdFan_flg;
extern unsigned char hIOP_WaterPump_flg;
extern unsigned char hIOP_RLight_flg;
extern unsigned char hIOP_PTCRelay_flg;
extern unsigned char hIOP_MainRelay_flg;
extern unsigned char hIOP_LSRelay9_flg;
extern unsigned char hIOP_WPTCRelay_flg;
/*PWM驱动信号*/
extern unsigned char hIOP_WaterPumpPWMDuyt_pct;
extern unsigned int hIOP_WaterPumpPWM_Hz;
extern unsigned char hIOP_HVInterlock_flg;
extern unsigned int hIOP_HVInterlockEn_Hz;
/*高驱驱动信号*/
extern unsigned char hIOP_HSRelay1_flg;
/*生命信号*/
extern unsigned char hIOP_VCULife_enum;

/**************************************************************************************		模式 && 系统		*******/
extern uint8_t AppBeginRunning_flg; /*if applicaton begin run the loop */
extern volatile uint32_t SystemTickMs;	//全局时钟，分辨率为1ms :: define in Task.c
extern float HAL_Version;
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
extern unsigned char K11P06_Mark;
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
extern uint32_t PeriodSendInvalidMsg; /*the initialize time is 100ms, the period that send invalid CAN message is 900, set the time to 850 */
extern unsigned char KNVM_SelfClrCycle; /*DTC self clear operation cycle, 0: disable self clear feature*/
extern uint16_t MaxAppDataLoadTime; /*application data loading must be finished in 1800ms*/
extern uint16_t MaxAppDataSaveTime; /*application data saving must be finished in 2000ms (erase two DFLASH nees about 800ms , save 10 page EEPROM costs about 400ms )*/

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
extern uint8_t KHALI_Escl_TasckStep;
//extern uint8_t KHALI_Escl_Installed;
/*blue tooth relevant calibration parameters*/


extern unsigned char S11P04_Mark ;

#define EEP_NOT_SAVING 0                 /*0: 存储模块不在存储数据，1:正在存储数据*/
#define EEP_SAVE_ONGOING 1
extern unsigned char EEPSavingFlag;
extern uint8_t PTCAN_RxReal_Num;
extern uint8_t CSCAN_RxReal_Num;

extern uint8_t FLAG_GateSPI_ERROR;
extern uint8_t ShouldFeedDog;
extern uint8_t bswWakeSrc;
/*********************************************************************************		UDS && CCP		*******/
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
extern UDS_CtrlType AppComCtrlType;  /* controlling type for NM Message communication*/
extern UDS_CtrlType NmComCtrlType;   /* controlling type for App Message communication*/
extern _CAN_MESSAGE_ VCU_UDS_msg;
extern _CAN_MESSAGE_ VCU_CCP_msg;
extern _CAN_MESSAGE_ NVM_msg; //used to send NVM operation test frame for load/save operation

extern uint8_t CcpRecvChannel; /*CCP command received from which channel*/
extern uint8_t UdsRecvChannel; /*CCP command received from which channel*/
extern unsigned char tpUdsCANRecv[8];

/***********************************************************************************		时间	 && 应用层信号	*******/
extern unsigned char VHALO_HWSignal_Time;  //运行时间统计
extern unsigned char VHALO_CANRx_Time;
extern unsigned char VHALO_TQM_Time;
extern unsigned char VHALO_DHP_Time;
extern unsigned char VHALO_HALI_Time;
extern unsigned char VHALO_DIM_Time;
extern unsigned char VHALO_PMM_Time;
extern unsigned char VHALO_CHRG_Time;
extern unsigned char VHALO_ENM_Time;
extern unsigned char VHALO_TMM_Time;
extern unsigned char VHALO_DSI_Time;
extern unsigned char VHALO_PEPS_Time;
extern unsigned char VHALO_DOM_Time;
extern unsigned char VHALO_TotalLoopTime;
extern unsigned char VHALO_BTK_Time;

extern uint32_t TimeofAllTask;
extern uint32_t MaxTimeofAllTask;
extern uint32_t TimeofAllInt;
extern uint32_t TimeofWithoutInt;

extern uint32_t TimeofIntPIT_temp;
extern uint32_t TimeofIntPIT;
extern uint32_t TimeofIntRT_temp;
extern uint32_t TimeofIntRT;
extern uint32_t TimeofIntCANRX_temp;
extern uint32_t TimeofIntCANRX;

//---------------DBC-------------------------
//BMS213
extern uint8_t VHALI_BMSBattTherMagErr;
extern uint16_t VHALI_ChrgSysMaxPwrSup;
//BMS306
extern uint8_t VHALI_coch_stopmIt;
extern uint8_t VHALI_cohv_stopm;
extern uint8_t VHALI_hvcon_stopmIt;
extern uint16_t VHALI_HVPVoltage;
extern uint16_t VHALI_HVNVoltage;
//BMS603
extern uint8_t VHALI_BMSModTSnsrNumTot;
extern uint8_t VHALI_BMSBattNum1;
extern uint8_t VHALI_BMSBatt1CellNumTot;
extern uint8_t VHALI_BMSBatt1TSnsrNumTot;
//BMS613
extern uint8_t VHALI_BMSCellUUnder;
extern uint8_t VHALI_BMSCellUOver;
extern uint8_t VHALI_BMSDeltaUOver;
extern uint8_t VHALI_BMSBattUnder;
extern uint8_t VHALI_BMSBattUOver;
extern uint8_t VHALI_BMSCellTUnder;
extern uint8_t VHALI_BMSCellTOver;
extern uint8_t VHALI_BMSDeltaTOver;
extern uint8_t VHALI_BMSVehCANErr;
extern uint8_t VHALI_BMSBattSOCLo;
extern uint8_t VHALI_BMSBattSOCHi;
extern uint8_t VHALI_BMSBattSOCUnder;
extern uint8_t VHALI_BMSOverCrrtChrg;
extern uint8_t VHALI_BMSOverCrrtDischrg;
extern uint8_t VHALI_BMSBattMatchErr;
extern uint8_t VHALI_BMSBattconsistErr;
extern uint8_t VHALI_BMSBattUErr;
extern uint8_t VHALI_BMSBattPoleTOver;
extern uint8_t VHALI_BMSRESSErr;
extern uint8_t VHALI_BMSBattSOCJump;
extern uint16_t VHALI_BMSVehicleRunmode_SOH;
extern uint16_t VHALI_BMSSOHMaxCp;
extern uint16_t VHALI_BMSSOHMinCp;
extern uint8_t VHALI_SOH_MinCpNr_Disp;
extern uint8_t VHALI_SOH_MaxCpNr_Disp;
//MCU515
extern uint8_t VHALI_MCU515CheckSum;
extern uint8_t VHALI_MCUMotopenphaseErr;
extern uint8_t VHALI_MCUTarTorOverErr;
//PEPS282
extern uint8_t VHALI_PEPS_RkeCmd;
extern uint8_t VHALI_TBOX_ESCLLock_Req;
extern uint8_t VHALI_TBOX_ESCLLockGND_Sts;

//GW522
extern uint8_t VHALI_BCM_RearDefrosterstatus;
//ABS232
extern uint16_t VHALI_ESC_MotorTorq_Req;
extern uint8_t VHALI_ESC_MotorWork_Req;
//FCW281
extern uint8_t VHALI_LDW_Left_Detected;
extern uint8_t VHALI_LDW_Left_Departure;
extern uint8_t VHALI_LDW_Right_Detected;
extern uint8_t VHALI_LDW_Right_Departure;
extern uint8_t VHALI_LDW_Alarm_Off;
extern uint8_t VHALI_Ambient_Light;
extern uint8_t VHALI_Calibration_Board_Detected;
extern uint8_t VHALI_LWheelLaneDistance;
extern uint8_t VHALI_RWheelLaneDistance;
extern uint8_t VHALI_FCW_TTC;
extern uint8_t VHALI_FCW_TTC_Valid_Flag;
extern uint8_t VHALI_Forward_Vehicle_Detected;
extern uint8_t VHALI_Forward_Collision_Warning;
extern uint8_t VHALI_Forward_Vehicle_Distance;
extern uint8_t VHALI_Pre_Collision_Warning;
//FCW285
extern uint8_t  VHALI_System_Status;
extern uint8_t  VHALI_LDWS_Running_Status;
extern uint8_t  VHALI_FCWS_Running_Status;
extern uint8_t  VHALI_PCWS_Running_Status;
extern uint8_t  VHALI_CALIB_Running_Status;
extern uint8_t  VHALI_System_Boot_Failed;
extern uint8_t  VHALI_Camera_Error;
extern uint8_t  VHALI_System_Halted_Error;
extern uint8_t  VHALI_CAN_Receive_Error;
extern uint8_t  VHALI_Need_Calibrate_Error;
//EPS_180
extern uint8_t VHALI_SAS_SteeringAngleValid;
extern uint8_t VHALI_SAS_SASFailure;
extern uint8_t VHALI_SAS_Calibrated;

//VCU10A
extern uint8_t VHALO_CRUISECtrlSys;
extern uint8_t VHALO_CRUISECtrlErr;
extern uint16_t VHALO_CRUISESpeed;
extern uint8_t VHALO_CRUISEModStop;

//---------------for A11----------------------
extern uint16_t VHALO_BrkSysRegTorqLimit;
extern uint8_t VHALO_BrkSysRegTorqLimitValid;
extern uint16_t VHALO_CoastRegenTq_Expectation;

extern uint16_t VHALI_BrakeSysRegTrqTrgt;
extern uint8_t VHALI_BrakeSysRegTrqTrgtValid;
extern uint8_t VHALI_BrakePedalApplied;
extern uint8_t VHALI_BrakePedalAppliedValid;
extern uint8_t VHALI_BrakePedalPosition;
extern uint8_t VHALI_BrakePedalPositionValid;
extern uint8_t VHALI_XBS_BLReq;
extern uint8_t VHALI_C_boosterFaultStatus;

//--------------------------------------------

/*模型需要的硬件信号*/
extern uint8_t VHALI_ACSwitchActiveIn_flg;
extern float VHALI_AccelPedalHIn_V;
extern float VHALI_AccelPedalLIn_V;
extern float VHALI_Batt_InWater_T;
extern float VHALI_Batt_OutWater_T;

extern uint8_t VHALI_BrkLightSwitch1ActiveIn_flg;
extern uint8_t VHALI_BrkLightSwitch2ActiveIn_flg;
extern uint8_t VHALI_CollisionDutyIn_pct;
extern uint8_t VHALI_CollisionFreIn_Hz;
extern uint8_t VHALI_CrankActiveIn_flg;

extern uint8_t VHALI_FastChargeAwakeActiveIn_flg;
extern float VHALI_FastChargeTemp1In_V;
extern float VHALI_FastChargeTemp2In_V;
extern uint8_t VHALI_FastChrgCANAwakeActiveIn_flg;
extern uint8_t VHALI_GearSwitch1ActiveIn_flg;
extern uint8_t VHALI_GearSwitch2ActiveIn_flg;
extern uint8_t VHALI_GearSwitch3ActiveIn_flg;
extern uint8_t VHALI_GearSwitch4ActiveIn_flg;
extern uint8_t VHALI_HSFaultCodeIn_enum;
extern uint8_t VHALI_HVInterlockFreIn_Hz;
extern uint8_t VHALI_IgnitionOnIn_flg;
extern uint32_t VHALI_LSFaultCodeIn_enum;
extern float VHALI_LVBattVoltageIn_V;
extern float VHALI_LVK15VoltageIn_V;

extern float VHALI_PCBTempIn_V;
extern float VHALI_Sensor5V1In_V;
extern float VHALI_Sensor5V2In_V;
extern uint8_t VHALI_SlowChargeAwakeActiveIn_flg;
extern float VHALI_VacuumPumpIn_V;
extern uint16_t VHALI_VacuumPumpIn_Hz;
extern uint8_t VHALI_WaterPwmIn_Duty;
extern uint16_t VHALI_WaterPwmIn_Hz;
extern uint8_t VHALI_PTCSwitchActiveIn_flg;
extern uint8_t VHALI_HandBrake; /*K11 handle brake*/
extern uint8_t  VHALI_ClutchSwitch1_flg ;  //YK19 离合器信号1
extern uint8_t  VHALI_ClutchSwitch2_flg ;  //YK19 离合器信号2

//add for Task.c

//add end

extern uint8_t VHALO_HSpdFanActive_flg;
extern uint8_t VHALO_HVInterlockActive_flg;
extern uint8_t VHALO_InternalSleepActive_flg;
extern uint8_t VHALO_LSpdFanActive_flg;
extern uint8_t VHALO_MCURelayActive_flg;
extern uint8_t VHALO_MainRelayActive_flg;
extern uint8_t VHALO_PTCRelayActive_flg;
extern uint8_t VHALO_RLight_flg;
extern uint8_t VHALO_VacuumPumpActive_flg;
extern uint8_t VHALO_WaterPumpActive_flg;
extern uint8_t VHALO_WaterPumpPWMDuty_pct;
extern uint8_t VHALO_BMSAwake_flg;
extern uint8_t VHALO_BrakeLamp_flg; /*add by zhou Yi S11*/
extern uint8_t VHALO_ACEnReq_flg;
extern uint8_t VHALO_WPTCRelayActive_flg;

extern unsigned long prevGW522Tick;
extern unsigned char CanWakeUp_Flg;
extern unsigned char HwWakeup_Flg;
extern uint8_t Old_VPEPS_SendChallengeCodeType_enum;
extern uint8_t VPEPS_SendChallengeCodeType_enum;
extern uint8_t STMM_WPPWM_Duty_pct;
extern uint8_t STMM_HSCoolFanEnReq_flg;
extern uint8_t STMM_LSCoolFanEnReq_flg;
extern uint8_t STMM_WaterPumpEnReq_flg;
extern uint8_t STMM_MCUInWaterT_C;
extern uint8_t STMM_PDUInWaterT_C;
extern uint8_t STMM_MoterInWaterT_C;
extern uint16_t SENM_CoolingPower_KJ;
extern uint8_t hIOP_MCURelay_flg;
extern uint8_t hIOP_MainRelay_flg;
extern uint8_t VCHRG_ChrgStopAbnormal_flg;
extern uint8_t VCHRG_ChrgStopModeInvalid_flg;

//----------------------------------------------- LIN Signal ---------
/*		TMMEXV signal    */
extern uint16_t STMM_EXV1_PositionRequest;
extern boolean STMM_EXV1_EnableRequest;
extern boolean STMM_EXV1_initRequest;

//extern boolean STMM_EXV1_ResponseError;
//extern uint8_t STMM_EXV1_CurrentInitState;
//extern boolean STMM_EXV1_RunState;
//extern uint8_t STMM_EXV1_FaultState;
//extern uint8_t STMM_EXV1_VoltageState;
//extern boolean STMM_EXV1_TemperatureWarn;
//extern uint16_t STMM_EXV1_CurrentPosition;

extern uint16_t STMM_EXV2_PositionRequest;
extern boolean STMM_EXV2_EnableRequest;
extern boolean STMM_EXV2_initRequest;

//extern boolean STMM_EXV2_ResponseError;
//extern uint8_t STMM_EXV2_CurrentInitState;
//extern boolean STMM_EXV2_RunState;
//extern uint8_t STMM_EXV2_FaultState;
//extern uint8_t STMM_EXV2_VoltageState;
//extern boolean STMM_EXV2_TemperatureWarn;
//extern uint16_t STMM_EXV2_CurrentPosition;

extern uint16_t VHALI_EWP_ErrorCode;
extern uint16_t VHALI_EWP_CurrentSpeed;
extern uint16_t VHALI_EWP_Volatge;
extern uint8_t VHALI_EWP_Temperature;

extern uint8_t  VHALI_EXV_ErrorCheck;
extern uint8_t  VHALI_EXV_InitStatus;
extern uint8_t  VHALI_EXV_RunStatus;
extern uint8_t  VHALI_EXV_ErrorStatus;
extern uint8_t  VHALI_EXV_VolatgeErrorStatus;
extern uint8_t  VHALI_EXV_TemperatureErrorStatus;
extern uint16_t VHALI_EXV_Position;

extern int16_t	VHALI_BatInWaterT_deg;
extern int16_t VHALI_PTSensorT_deg;
extern uint16_t VHALI_PTSensorP_kPa;

/*		Test For Switch		*/
extern float hIOP_CruiseKey_V;
extern float CruiseKeyResistance;
extern uint8_t VINP_CruiseKeyOnOff_flg;
extern uint8_t VINP_CruiseKeyCancel_flg;
extern uint8_t VINP_CruiseKeySet_flg;
extern uint8_t VINP_CruiseKeyRes_flg;
extern uint8_t CruiseKeyFaultCode;//按键诊断

extern uint8_t hIOP_Elect2_flg;

//CAN period sending
extern uint32_t CAN_PeriodSendTime;

//NM 相关
extern uint8_t NM_First;
extern uint8_t NM_ShutPerSend;
extern uint8_t NM_ReACKandCanStop;
extern uint8_t NM_AppWaitValid;//app等待模式
//-----------------------
#define NM_Before_Tbws  0    /*VCU is not in NM Twbs period*/
#define NM_Begin_Twbs  1     /*VCU sent 14 or 32, or VCU received 32, Twbs period began*/
#define NM_Enter_Twbs    2   /*In Twbs period, wait the Twbs timer expired*/
#define NM_End_Twbs     4     /*Twbs timer expired, VCU can power off*/
extern uint8_t NM_Twbs;
extern uint8_t NM_quitTwbsFirstF;

//Ack
extern uint8_t Bus_Ack_Start;
extern uint8_t Bus_Ack_Statusf;
extern uint8_t CAN3_AckErrFlag;

extern uint16_t NEDC_Milg_km;
extern uint16_t Eco_egyCnse_1km_c;
extern uint8_t zone_km_c;

/***************************************************************************		else part		******************************/
extern unsigned char KHALI_DisRelayWhenCanOff;
extern unsigned char KUDS_TestFeature;
extern unsigned char KUDS_SupportOldBoot;
extern unsigned short KUDS_ABSStopedSpeed;
extern unsigned short KUDS_MotorStopedSpeed;
extern boolean KUDS_IOCtrlEnable; /*1: IO 控制功能打开*/
extern uint32_t PeriodSendInvalidMsg;
extern unsigned char KNVM_SelfClrCycle; /*CR 1088*/
extern uint8_t      MaxDaqRetryTime;   /*bug 1251*/
/*reserve 12 bytes for App SW version */
extern unsigned char UdsAppSWVer[12];
/*reserve 12 bytes for HW version */
extern unsigned char UdsHWVer[12];
/*reserve 12 bytes for HW version */
extern unsigned char UdsPartNumber[21];
/*reserve 8 bytes for calibraton version */
extern unsigned char UdsCalSWVer[8];

/**********		仅声明			**********/
extern unsigned long VHALI_NMTxSuceess_MsgTicks;  //define in DBC_Lib.c
extern unsigned char CAN_Send_Cmd;	//define in Task.c
extern unsigned char CAN_Send_Nm;	//define in Task.c

/*  useless in VCU2.0  */
extern uint8_t X11_Mark;

/*used for PT CAN bus-off recovery handler*/
/*
 0: All OK, no bus-off
 1: bus-off detected, CAN device re-initialized
 2:  waiting for fast recovey delay timeout, if timeout re-start ransmission
 3:  waiting for slow recovery delay timeout  if timeout re-start ransmission
 4: re-transmission started, checking if CAN bus is in error-active state
 5: entered error-active  state, delay to clear Bus-off Confirmed flag
 */
#define BUS_OFF_OK                0
#define BUS_OFF_DTECTED           1
#define BUS_OFF_FAST_RECOVERY_WAIT      2
#define BUS_OFF_SLOW_RECOVERY_WAIT      3
#define BUS_OFF_TX_RESTRATED            4
#define BUS_OFF_RE_TX_OK                5

extern uint8_t CAN3_BusOffState;
extern uint8_t CAN3_BusOffDelayTimeOut; /*1:PT CAN bus-off recovery delay timeout, can retry the transmission*/
extern uint16_t CAN3_BusOffFastRecoveryCnt; /*PT CAN bus-off fast recovery retry count*/
extern uint32_t CAN3_BusOffRecoveryStart; /*record when the bus-off recovery is started*/

extern boolean udsHWTestingModeStatus; /* 1: enter testing mode;  0: quit testing mode*/
extern uint8_t HW_udsDiag_flag;

extern boolean bool_udsAgingTestStart_flag;/* 1: enter testing mode;  0: quit testing mode*/
extern boolean bool_udsAgingTestError_flag;/* 1: enter error;  0: no error*/
//测试以太网使用，牵扯到下线检测
extern uint8_t EnetTestMaster;
extern uint8_t EnetRight;
extern uint32_t EnetTxTick;
extern uint32_t EnetRxTick;

//硬件测试添加
extern _CAN_flag_ CanComTest;
extern uint8_t lintest;

extern unsigned char Ex_Bios_LS_Output[LS_NUM];   /* 硬件测试，低驱输出 */
extern unsigned char Ex_Bios_HS_Output[HS_NUM];   /* 硬件测试，高驱输出 */
extern _NCV7719_INOUTPUT_ Ex_NCV7719_data;    /* HW test , H  bridge output */  


/*VCU HW platform version*/
#define HW_VCU10    0x10   /*VCU1.0 HW platform*/
#define HW_VCU20    0x20   /*VCU2.0  HW platform*/
extern unsigned char VHALI_HWVersion;

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
}APPDID_outSnapshots;
extern APPDID_outSnapshots appDID_outSnapshot;

typedef enum NvMLoadSave
{
	NvMDataLoading = 0,       /*data is being loaded from NVM*/
	NvMDataLoaded  = 1, 		/* all app data areas loaded from NVM*/
       NvMDataSaving  = 2,      /*data is being saved to NVM*/
	NvMDataSaved   = 3, 		/*all  app data areas saved to NVM*/
}NvMLoadSaveType;

typedef struct udsIOCTRLDID
{
   uint16_t  DataId;                 /*2 bytes DID*/
   uint8_t    DataLen;              /*length*/
   boolean  Enable;           /*Enabled or not  1: IO 控制功能打开，输出不受应用层影响*/
   uint8_t  Status;
}udsIOCTRLDIDType;

typedef struct 
{
    uint16_t duty;
    uint32_t freq;
}HWTest_PwmCtrlType;
extern HWTest_PwmCtrlType udsHWTestPwmCtrl[PWM_NUM];
extern uint8_t     SocResiMilgNvMCorrect;
#define AUTHFALIED_DATA_SIZE 72   /*auth failed data size is 72 bytes*/
extern uint8_t AuthFailData[AUTHFALIED_DATA_SIZE];   /*be used to store the auth failure internal data*/
extern uint32_t VHALO_VCU_105_Ticks;
extern uint8_t PTBusOffConfirmedFlag;
extern uint8_t VHALI_Local_Auth_Req;
extern uint8_t authFaileDataCopied;
#define HW_VCU20_B1   0xB1  
#define HW_VCU20_B2   0xB2
extern uint8_t VCU20DetailedHwVer;   /*VCU2.0 detailed HW version*/

/****************************************BTK relevant start ****************************************************/
extern uint8_t VHALI_Local_Auth_Req;
extern uint8_t EsclLinCommFailed;
extern uint8_t VHALO_EsclStatus;
extern uint8_t EsclErrorCode;

/*开关量采集变量*/
extern unsigned char hIOP_SSB_Switch1_flg; 
extern unsigned char hIOP_SSB_Switch2_flg; 
/*低驱驱动信号*/
extern unsigned char hIOP_IGN1_flg;
extern unsigned char hIOP_IGN2_flg;
/*内部模拟量采集变量*/
extern float hIOP_IGN1_FB_v;  
extern float hIOP_IGN2_FB_v;  

extern uint8_t VHALI_SSB_Switch_1;
extern uint8_t VHALI_SSB_Switch_2;
extern float VHALI_IGN1_Out_v;   
extern float VHALI_IGN2_Out_v;   

extern uint8_t VHALO_VCU_PDU;
extern uint8_t VHALO_IGN1_Flg;
extern uint8_t VHALO_IGN2_Flg;
extern uint8_t VHALO_SSB_GreenLed;
extern uint8_t VHALO_SSB_RedLed;
/**************************************BTK relevant end****************************************************/

 extern uint8_t VHALI_PTCLowReqIn_flg;  //  Z18: PTC低档请求信号
 extern uint8_t VHALI_PTCHighReqIn_flg; //  Z18: PTC高档请求信号
 extern uint8_t VHALI_DefrostActiveIn_flg;//Z18: 除霜开关输入（12V）
 extern uint8_t VHALI_EACReqIn_flg;    //Z18: 压缩机开启请求信号（+12V)
 extern unsigned char VHALI_EHU_VSPSwitchSet;/*低速行人提醒开关设置*/
 
extern boolean gblUdsECUUpgrade;
extern boolean gblUdsKeepPresent;
extern boolean gblUdsCommCtrl;

extern uint8_t gblNVMStateMachineSts;

/****************************************S21 seat motor relevant start ************************************************/

/*开关量采集变量*/
extern unsigned char hIOP_SeatHall_flg;
extern unsigned char hIOP_FrontSeatMotorSwitch_flg;
extern unsigned char hIOP_RearSeatMotorSwitch_flg;
/*低驱驱动信号*/
extern unsigned char hIOP_FrontSeatMotorRelay_flg;
extern unsigned char hIOP_RearSeatMotorRelay_flg;

extern uint8_t VHALI_SeatHallActiveIn_flg;
extern uint8_t VHALI_FrontSeatMotorSwitchActiveIn_flg;
extern uint8_t VHALI_RearSeatMotorSwitchActiveIn_flg;
extern uint8_t VHALO_FrontSeatMotorRelayActive_flg;
extern uint8_t VHALO_RearSeatMotorRelayActive_flg;

/****************************************S21 seat motor relevant end ************************************************/
#endif /* HAL_GLOBAL_H_ */

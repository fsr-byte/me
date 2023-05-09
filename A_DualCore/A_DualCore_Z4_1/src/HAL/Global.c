/*
 * Global.c
 *
 *  Created on: 2018年10月8日
 *      Author: helei
 */

#define __GLOBAL_GLOBALS__

#include "derivative.h"
#include "Global.h"
#include "BASE_Global.h"
#include "CAN_Operation.h"
#include "uds_service.h"

/**************************************************************************************		硬线信号		*******/
unsigned char Bios_Sw_Input[SW_NUM] = {0};	//数字量获取
unsigned int ADC_OutBuff[ADC_NUM] = {0};		//ADC获取
unsigned char Bios_LS_Output[LS_NUM] = {0};	//低驱输出
unsigned char Bios_HS_Output[HS_NUM] = {0};	//高驱输出

unsigned char Batt12_15Vol = 0;	//电压获取、HAL_Capture_ADC
unsigned char Batt12_30Vol = 0;	//电压获取、HAL_Capture_ADC

/*开关量采集变量*/
unsigned char hIOP_AirSwitch_flg = 0;
unsigned char hIOP_BrkLightSwitch1_flg = 0;
unsigned char hIOP_Crank_flg = 0;
unsigned char hIOP_GearSwitch1_flg = 0;
unsigned char hIOP_GearSwitch2_flg = 0;
unsigned char hIOP_GearSwitch3_flg = 0;
unsigned char hIOP_GearSwitch4_flg = 0;
unsigned char hIOP_ACSwitch_flg = 0;
unsigned char hIOP_BrkLightSwitch2_flg = 0;
unsigned char hIOP_SlowChargeAwake_flg = 0;
unsigned char hIOP_FastChargeAwake_flg = 0;
unsigned char HIOP_HandBrake_flg = 0;	//---++
unsigned char hIOP_ClutchSwitch1_flg = 0;  //YK19 离合器信号1
unsigned char hIOP_ClutchSwitch2_flg = 0;  //YK19 离合器信号2

/*外接模拟量采集变量*/
float hIOP_AccelPedalL_V = 0;
float hIOP_AccelPedalH_V = 0;
float hIOP_FastChargeTemp1_V = 0;
float hIOP_FastChargeTemp2_V = 0;
/*内部模拟量采集变量*/
float hIOP_K15_V = 0;
float hIOP_K30_V = 0;
float hIOP_Sen5V1_V = 0;
float hIOP_Sen5V2_V = 0;
float hIOP_PCBTemp_V = 0;
/*频率量采集变量*/
float hIOP_CollisionSw_Hz = 0;
float hIOP_CollisionSw_Duty = 0;
float hIOP_WaterPwm_Hz = 0;
float hIOP_WaterPwm_Duty = 0;
float hIOP_HVInterlock_Hz = 0;
uint32_t hIOP_HVInterlock_PulseTime_us= 0;
uint32_t hIOP_HVInterlock_PeriodTime_us = 0;

float hIOP_Fin4_Hz = 0;
uint8_t hIOP_HVInterlock_Duty = 0;
uint8_t hIOP_VacuumPumpIn_Duty = 0;
/*芯片唤醒信号*/
unsigned char hIOP_1043WKUP_flg = 0;	//同hIOP_FastChargeAwake_flg
/*诊断错误码*/
unsigned int hIOP_LSFaultCode_enum = 0;
unsigned char hIOP_HSFaultCode_enum = 0;
unsigned int hIOP_LSFaultCode_enum_POR = 0;
unsigned char hIOP_HSFaultCode_enum_POR = 0;
/*CAN总线各通道的Tick*/	//--?--
unsigned long hIOP_VCUCanTickCount = 0;
unsigned int hIOP_McuImportentMsg_Ticks1 = 0;
unsigned int hIOP_McuImportentMsg_Ticks2 = 0;
unsigned int hIOP_BmsImportentMsg_Ticks1 = 0;
unsigned int hIOP_BmsImportentMsg_Ticks2 = 0;
unsigned int hIOP_BmsImportentMsg_Ticks3 = 0;
unsigned int hIOP_DCDCImportentMsg_Ticks1 = 0;
unsigned int hIOP_DCDCImportentMsg_Ticks2 = 0;
unsigned int hIOP_ICMImportentMsg_Ticks1 = 0;
/*低驱驱动信号*/
unsigned char hIOP_MCURelay_flg = 0;
unsigned char hIOP_LSpdFan_flg = 0;
unsigned char hIOP_HSpdFan_flg = 0;
unsigned char hIOP_WaterPump_flg = 0;
unsigned char hIOP_RLight_flg = 0;
unsigned char hIOP_PTCRelay_flg = 0;
unsigned char hIOP_MainRelay_flg = 0;
unsigned char hIOP_LSRelay9_flg = 0;	//---?---
unsigned char hIOP_WPTCRelay_flg = 0;
/*PWM驱动信号*/
unsigned char hIOP_WaterPumpPWMDuyt_pct = 50;
unsigned int hIOP_WaterPumpPWM_Hz = 100;
unsigned char hIOP_HVInterlock_flg = 1;
unsigned int hIOP_HVInterlockEn_Hz = 20;
/*高驱驱动信号*/
unsigned char hIOP_HSRelay1_flg = 0;
/*生命信号*/
unsigned char hIOP_VCULife_enum = 0;	//---?---

/******************************		模式	 && 系统		*******/
float HAL_Version = 0; /*底层HAL库 软件版本*/
uint8_t AppBeginRunning_flg; /*if applicaton begin run the loop */

uint8_t PTCAN_RxReal_Num = 0;	//动力CAN上实际在Core1中接收的报文数目
uint8_t CSCAN_RxReal_Num = 0;	//底盘CAN上实际在Core1中接收的报文数目

uint8_t FLAG_GateSPI_ERROR = 0;	//1：存在抢占SPI总线失败的情况。
uint8_t ShouldFeedDog = 0;	//1：抢占总线失败时Core1缩短喂狗周期。
uint8_t bswWakeSrc = WAKEUPSRC_UNKNOWN;
/***************************		UDS && CCP		*******/
UDS_CtrlType AppComCtrlType = UDS_EnRx_EnTx;   /* App message control type (for 28 service)*/
UDS_CtrlType NmComCtrlType = UDS_EnRx_EnTx;    /* Network  message control type (for 28 service)*/
_CAN_MESSAGE_ VCU_UDS_msg;	//UDS&&CCP结构体
_CAN_MESSAGE_ VCU_CCP_msg;
_CAN_MESSAGE_ NVM_msg;           //used to send NVM operation test frame for load/save operation

uint8_t CcpRecvChannel; /*CCP command received from which channel*/
uint8_t UdsRecvChannel; /*CCP command received from which channel*/
unsigned char tpUdsCANRecv[8];
/**************************************************************************************		时间 && 应用层信号			*******/
unsigned char VHALO_HWSignal_Time = 0;	//运行时间统计
unsigned char VHALO_CANRx_Time = 0;
unsigned char VHALO_TQM_Time = 0;
unsigned char VHALO_DHP_Time = 0;
unsigned char VHALO_HALI_Time = 0;
unsigned char VHALO_DIM_Time = 0;
unsigned char VHALO_PMM_Time = 0;
unsigned char VHALO_CHRG_Time = 0;
unsigned char VHALO_ENM_Time = 0;
unsigned char VHALO_TMM_Time = 0;
unsigned char VHALO_DSI_Time = 0;
unsigned char VHALO_PEPS_Time = 0;
unsigned char VHALO_DOM_Time = 0;
unsigned char VHALO_TotalLoopTime = 0;
unsigned char VHALO_BTK_Time = 0;

//--add for collect timing infomation--
uint32_t TimeofAllTask = 0;
uint32_t MaxTimeofAllTask = 0;
uint32_t TimeofAllInt = 0;
uint32_t TimeofWithoutInt = 0;

uint32_t TimeofIntPIT_temp = 0;
uint32_t TimeofIntPIT = 0;
uint32_t TimeofIntRT_temp = 0;
uint32_t TimeofIntRT = 0;
uint32_t TimeofIntCANRX_temp = 0;
uint32_t TimeofIntCANRX = 0;

//---------------DBC-------------------------
//BMS213
uint8_t VHALI_BMSBattTherMagErr = 0;
uint16_t VHALI_ChrgSysMaxPwrSup = 0;
//BMS306
uint8_t VHALI_coch_stopmIt = 0;
uint8_t VHALI_cohv_stopm = 0;
uint8_t VHALI_hvcon_stopmIt = 0;
uint16_t VHALI_HVPVoltage = 0;
uint16_t VHALI_HVNVoltage = 0;
//BMS603
uint8_t VHALI_BMSModTSnsrNumTot = 0;
uint8_t VHALI_BMSBattNum1 = 0;
uint8_t VHALI_BMSBatt1CellNumTot = 0;
uint8_t VHALI_BMSBatt1TSnsrNumTot = 0;
//BMS613
uint8_t VHALI_BMSCellUUnder = 0;
uint8_t VHALI_BMSCellUOver = 0;
uint8_t VHALI_BMSDeltaUOver = 0;
uint8_t VHALI_BMSBattUnder = 0;
uint8_t VHALI_BMSBattUOver = 0;
uint8_t VHALI_BMSCellTUnder = 0;
uint8_t VHALI_BMSCellTOver = 0;
uint8_t VHALI_BMSDeltaTOver = 0;
uint8_t VHALI_BMSVehCANErr = 0;
uint8_t VHALI_BMSBattSOCLo = 0;
uint8_t VHALI_BMSBattSOCHi = 0;
uint8_t VHALI_BMSBattSOCUnder = 0;
uint8_t VHALI_BMSOverCrrtChrg = 0;
uint8_t VHALI_BMSOverCrrtDischrg = 0;
uint8_t VHALI_BMSBattMatchErr = 0;
uint8_t VHALI_BMSBattconsistErr = 0;
uint8_t VHALI_BMSBattUErr = 0;
uint8_t VHALI_BMSBattPoleTOver = 0;
uint8_t VHALI_BMSRESSErr = 0;
uint8_t VHALI_BMSBattSOCJump = 0;
uint16_t VHALI_BMSVehicleRunmode_SOH = 0;
uint16_t VHALI_BMSSOHMaxCp = 0;
uint16_t VHALI_BMSSOHMinCp = 0;
uint8_t VHALI_SOH_MinCpNr_Disp = 0;
uint8_t VHALI_SOH_MaxCpNr_Disp = 0;
//MCU515
uint8_t VHALI_MCU515CheckSum = 0;
uint8_t VHALI_MCUMotopenphaseErr = 0;
uint8_t VHALI_MCUTarTorOverErr = 0;
//PEPS282
uint8_t VHALI_PEPS_RkeCmd = 0;
uint8_t VHALI_TBOX_ESCLLock_Req = 0;
uint8_t VHALI_TBOX_ESCLLockGND_Sts = 0;
//GW522
uint8_t VHALI_BCM_RearDefrosterstatus = 0;
//ABS232
uint16_t VHALI_ESC_MotorTorq_Req = 0;
uint8_t VHALI_ESC_MotorWork_Req = 0;
//FCW281
uint8_t VHALI_LDW_Left_Detected = 0;
uint8_t VHALI_LDW_Left_Departure = 0;
uint8_t VHALI_LDW_Right_Detected = 0;
uint8_t VHALI_LDW_Right_Departure = 0;
uint8_t VHALI_LDW_Alarm_Off = 0;
uint8_t VHALI_Ambient_Light = 0;
uint8_t VHALI_Calibration_Board_Detected = 0;
uint8_t VHALI_LWheelLaneDistance = 0;
uint8_t VHALI_RWheelLaneDistance = 0;
uint8_t VHALI_FCW_TTC = 0;
uint8_t VHALI_FCW_TTC_Valid_Flag = 0;
uint8_t VHALI_Forward_Vehicle_Detected = 0;
uint8_t VHALI_Forward_Collision_Warning = 0;
uint8_t VHALI_Forward_Vehicle_Distance = 0;
uint8_t VHALI_Pre_Collision_Warning = 0;
//FCW285
uint8_t VHALI_System_Status = 0;
uint8_t VHALI_LDWS_Running_Status = 0;
uint8_t VHALI_FCWS_Running_Status = 0;
uint8_t VHALI_PCWS_Running_Status = 0;
uint8_t VHALI_CALIB_Running_Status = 0;
uint8_t VHALI_System_Boot_Failed = 0;
uint8_t VHALI_Camera_Error = 0;
uint8_t VHALI_System_Halted_Error = 0;
uint8_t VHALI_CAN_Receive_Error = 0;
uint8_t VHALI_Need_Calibrate_Error = 0;
//EPS_180
uint8_t VHALI_SAS_SteeringAngleValid = 0;
uint8_t VHALI_SAS_SASFailure = 0;
uint8_t VHALI_SAS_Calibrated = 0;

//VCU10A
uint8_t VHALO_CRUISECtrlSys = 0;
uint8_t VHALO_CRUISECtrlErr = 0;
uint16_t VHALO_CRUISESpeed = 0;
uint8_t VHALO_CRUISEModStop = 0;

//---------------for A11----------------------
uint16_t VHALO_BrkSysRegTorqLimit = 0;
uint8_t VHALO_BrkSysRegTorqLimitValid = 0;
uint16_t VHALO_CoastRegenTq_Expectation = 0;

uint16_t VHALI_BrakeSysRegTrqTrgt = 0;
uint8_t VHALI_BrakeSysRegTrqTrgtValid = 0;
uint8_t VHALI_BrakePedalApplied = 0;
uint8_t VHALI_BrakePedalAppliedValid = 0;
uint8_t VHALI_BrakePedalPosition = 0;
uint8_t VHALI_BrakePedalPositionValid = 0;
uint8_t VHALI_XBS_BLReq = 0;
uint8_t VHALI_C_boosterFaultStatus = 0;

//------------------------------------------
/*模型需要的硬件信号*/
uint8_t VHALI_ACSwitchActiveIn_flg;
float VHALI_AccelPedalHIn_V;
float VHALI_AccelPedalLIn_V;

float VHALI_Batt_InWater_T;
float VHALI_Batt_OutWater_T;

uint8_t VHALI_BrkLightSwitch1ActiveIn_flg;
uint8_t VHALI_BrkLightSwitch2ActiveIn_flg;
uint8_t VHALI_CollisionDutyIn_pct;
uint8_t VHALI_CollisionFreIn_Hz;
uint8_t VHALI_CrankActiveIn_flg;

uint8_t VHALI_FastChargeAwakeActiveIn_flg;
float VHALI_FastChargeTemp1In_V;
float VHALI_FastChargeTemp2In_V;
uint8_t VHALI_FastChrgCANAwakeActiveIn_flg;
uint8_t VHALI_GearSwitch1ActiveIn_flg;
uint8_t VHALI_GearSwitch2ActiveIn_flg;
uint8_t VHALI_GearSwitch3ActiveIn_flg;
uint8_t VHALI_GearSwitch4ActiveIn_flg;
uint8_t VHALI_HSFaultCodeIn_enum;
uint8_t VHALI_HVInterlockFreIn_Hz;

uint8_t VHALI_IgnitionOnIn_flg;
float VHALI_LVBattVoltageIn_V;
float VHALI_LVK15VoltageIn_V;

uint32_t VHALI_LSFaultCodeIn_enum;

float VHALI_PCBTempIn_V;
float VHALI_Sensor5V1In_V;
float VHALI_Sensor5V2In_V;
uint8_t VHALI_SlowChargeAwakeActiveIn_flg;
float VHALI_VacuumPumpIn_V;
uint16_t VHALI_VacuumPumpIn_Hz;
uint8_t VHALI_WaterPwmIn_Duty;
uint16_t VHALI_WaterPwmIn_Hz;
uint8_t VHALI_PTCSwitchActiveIn_flg;
uint8_t VHALI_HandBrake; /*K11 handle brake*/
uint8_t VHALI_ClutchSwitch1_flg ;  //YK19 离合器信号1
uint8_t VHALI_ClutchSwitch2_flg ;  //YK19 离合器信号2

/*模型控制硬件信号输出*/
uint8_t VHALO_HSpdFanActive_flg;
uint8_t VHALO_HVInterlockActive_flg;
uint8_t VHALO_InternalSleepActive_flg;
uint8_t VHALO_LSpdFanActive_flg;
uint8_t VHALO_MCURelayActive_flg;
uint8_t VHALO_MainRelayActive_flg;
uint8_t VHALO_PTCRelayActive_flg;
uint8_t VHALO_RLight_flg;
uint8_t VHALO_VacuumPumpActive_flg;
uint8_t VHALO_WaterPumpActive_flg;
uint8_t VHALO_WaterPumpPWMDuty_pct;
uint8_t VHALO_BMSAwake_flg;
uint8_t VHALO_BrakeLamp_flg; /*add by zhou Yi S11*/
uint8_t VHALO_ACEnReq_flg;
uint8_t VHALO_WPTCRelayActive_flg;

/*模型控制硬件信号输出*/
unsigned long prevGW522Tick;
unsigned char CanWakeUp_Flg;	//---?---
unsigned char HwWakeup_Flg;

uint8_t Old_VPEPS_SendChallengeCodeType_enum;
uint8_t VPEPS_SendChallengeCodeType_enum;
uint8_t STMM_WPPWM_Duty_pct;
uint8_t STMM_HSCoolFanEnReq_flg;
uint8_t STMM_LSCoolFanEnReq_flg;
uint8_t STMM_WaterPumpEnReq_flg;
uint8_t STMM_MCUInWaterT_C;
uint8_t STMM_PDUInWaterT_C;
uint8_t STMM_MoterInWaterT_C;

uint16_t SENM_CoolingPower_KJ;
uint8_t hIOP_MCURelay_flg;
uint8_t hIOP_MainRelay_flg;
uint8_t VCHRG_ChrgStopAbnormal_flg;
uint8_t VCHRG_ChrgStopModeInvalid_flg;

//----------------------------------------------- LIN Signal ---------
/*		TMMEXV signal    */
uint16_t STMM_EXV1_PositionRequest;
boolean STMM_EXV1_EnableRequest;
boolean STMM_EXV1_initRequest;

//   boolean STMM_EXV1_ResponseError;
//   uint8_t STMM_EXV1_CurrentInitState;
//   boolean STMM_EXV1_RunState;
//   uint8_t STMM_EXV1_FaultState;
//   uint8_t STMM_EXV1_VoltageState;
//   boolean STMM_EXV1_TemperatureWarn;
//   uint16_t STMM_EXV1_CurrentPosition;

uint16_t STMM_EXV2_PositionRequest;
boolean STMM_EXV2_EnableRequest;
boolean STMM_EXV2_initRequest;

//   boolean STMM_EXV2_ResponseError;
//   uint8_t STMM_EXV2_CurrentInitState;
//   boolean STMM_EXV2_RunState;
//   uint8_t STMM_EXV2_FaultState;
//   uint8_t STMM_EXV2_VoltageState;
//   boolean STMM_EXV2_TemperatureWarn;
//   uint16_t STMM_EXV2_CurrentPosition;

uint16_t VHALI_EWP_ErrorCode;
uint16_t VHALI_EWP_CurrentSpeed;	//range [0,4000]
uint16_t VHALI_EWP_Volatge;		//range [0,2550]
uint8_t VHALI_EWP_Temperature;	//offset -50; range [-50,160]

uint8_t VHALI_EXV_ErrorCheck;
uint8_t VHALI_EXV_InitStatus;
uint8_t VHALI_EXV_RunStatus;
uint8_t VHALI_EXV_ErrorStatus;
uint8_t VHALI_EXV_VolatgeErrorStatus;
uint8_t VHALI_EXV_TemperatureErrorStatus;
uint16_t VHALI_EXV_Position;

int16_t VHALI_BatInWaterT_deg;
int16_t VHALI_PTSensorT_deg;
uint16_t VHALI_PTSensorP_kPa;

//----------------------------------------------- Switch Signal ---------
/*		Test For Switch		*/
float hIOP_CruiseKey_V = 0.0f;
float CruiseKeyResistance = 0;
uint8_t VINP_CruiseKeyOnOff_flg = 0;
uint8_t VINP_CruiseKeyCancel_flg = 0;
uint8_t VINP_CruiseKeySet_flg = 0;
uint8_t VINP_CruiseKeyRes_flg = 0;
uint8_t CruiseKeyFaultCode = 0;	//按键诊断

uint8_t hIOP_Elect2_flg;

//CAN period sending
uint32_t CAN_PeriodSendTime = 0;	//记录CAN3的周期报文发送时间

//NM 相关
uint8_t NM_First = 0;
uint8_t NM_ShutPerSend = 0;
uint8_t NM_ReACKandCanStop = 0;
uint8_t NM_AppWaitValid = 0;	//app等待模式
//-----------------------
uint8_t NM_Twbs = NM_Before_Tbws;
uint8_t NM_quitTwbsFirstF = 0;

//Ack
uint8_t Bus_Ack_Start = 0;
uint8_t Bus_Ack_Statusf = 0;
uint8_t CAN3_AckErrFlag = 0;

/*********************************************************		BSW calibration variables ******************************/
CAL_BSW unsigned char Vehicle_Type = 1;
CAL_BSW unsigned char S11_Mark = 1;
CAL_BSW unsigned char K11_Mark = 2;
CAL_BSW unsigned char S11P01_Mark = 4;
CAL_BSW unsigned char A11_Mark = 5;
CAL_BSW unsigned char K11P01_Mark = 6;
CAL_BSW unsigned char S11P03_Mark = 7;
CAL_BSW unsigned char S21_Mark = 8;
CAL_BSW unsigned char K11E01R_Mark = 9;
CAL_BSW unsigned char S11P05_Mark = 12;
CAL_BSW unsigned char K11P06_Mark = 13;
CAL_BSW unsigned char Authentication_flg = 0;
CAL_BSW unsigned char KACMiddleVoltage_flg = 0;
CAL_BSW uint8_t MaxDaqRetryTime = 2; /*after DAQ transmission tried for 2 ms, give up*/
CAL_BSW unsigned char KHALI_DisRelayWhenCanOff = 1;
CAL_BSW unsigned char KUDS_TestFeature = 1;
CAL_BSW unsigned char KUDS_SupportOldBoot = 0;
CAL_BSW unsigned short KUDS_ABSStopedSpeed = VEHICLE_STOP_LIMIT;
CAL_BSW unsigned short KUDS_MotorStopedSpeed = MOTOR_STOP_LIMIT;
CAL_BSW boolean KUDS_IOCtrlEnable = 1; /*1: IO 控制功能打开*/
CAL_BSW uint32_t PeriodSendInvalidMsg = 850; /*CR 1082:  the initialize time is 100ms, the period that send invalid CAN message is 900, set the time to 850 */
CAL_BSW unsigned char KNVM_SelfClrCycle = 0; /*CR1088: DTC self clear operation cycle, 0: disable self clear feature*/
CAL_BSW uint16_t MaxAppDataLoadTime = 800; /*application data loading must be finished in 1800ms*/
CAL_BSW uint16_t MaxAppDataSaveTime = 2000; /*application data saving must be finished in 2000ms (erase two DFLASH nees about 800ms , save 10 page EEPROM costs about 400ms )*/
CAL_BSW uint16_t NEDC_Milg_km = 300U;
CAL_BSW uint16_t Eco_egyCnse_1km_c = 111U;
CAL_BSW uint8_t zone_km_c = 20U;

/*blue tooth relevant calibration parameters*/
//CAL_BSW unsigned char KHALI_VCUActAsPeps = 0;    /*1: VCU acting as PEPS to sample SSB, control the IGN1/IGN2 relay*/
/*timeout values based on ESCL spec*/
CAL_BSW uint16_t KHALI_Escl_InitDelay = 150;
CAL_BSW uint16_t KHALI_Escl_TimeOut_1 = 180;
CAL_BSW uint16_t KHALI_Escl_TimeOut_2 = 1600;
CAL_BSW uint16_t KHALI_Escl_TimeOut_31 = 1500;
CAL_BSW uint16_t KHALI_Escl_TimeOut_32 = 1500;
CAL_BSW uint16_t KHALI_Escl_TimeOut_33 = 1500;
CAL_BSW uint16_t KHALI_Escl_TimeOut_4 = 1200;
CAL_BSW uint16_t KHALI_Escl_TimeOut_5 = 1600;
CAL_BSW uint32_t KHALI_Escl_ForceEraseDuration = 700000;    /*force eracing ESCL, maximum 10 minutes*/
CAL_BSW uint16_t KHALI_Escl_ProgKeyInterval = 50;  /*the interval of the two program key commands*/
CAL_BSW uint8_t KHALI_Escl_TasckStep = 2;            /*how many task cyles should ESCl be called, each cycle is 10ms */
//CAL_BSW uint8_t KHALI_Escl_Installed = 0;          /*0: ESCL not installed, 1: ESCL installed*/

/*blue tooth relevant calibration parameters*/


unsigned char S11P04_Mark = 10;

/*  useless in VCU2.0  not use just define*/
uint32_t VHALI_GW_405_MsgTicks;
uint8_t X11_Mark = 3;

uint8_t KUDS_CheckCalData = 0;
uint8_t KUDS_CheckDidCrc = 0;

boolean udsHWTestingModeStatus = 0;
uint8_t HW_udsDiag_flag = 0;


boolean bool_udsAgingTestStart_flag=0;
boolean bool_udsAgingTestError_flag=0;

uint8_t CAN3_BusOffState;
uint8_t CAN3_BusOffDelayTimeOut = 1; /*1:PT CAN bus-off recovery delay timeout, can retry the transmission*/
uint16_t CAN3_BusOffFastRecoveryCnt; /*PT CAN bus-off fast recovery retry count*/
uint32_t CAN3_BusOffRecoveryStart; /*record when the bus-off recovery is started*/

//测试以太网使用，牵扯到下线检测
uint8_t EnetTestMaster = 0;
uint8_t EnetRight = 0;
uint32_t EnetTxTick = 0, EnetRxTick = 0;	//用于观测Enet发送与接收的情况

//硬件测试添加
_CAN_flag_ CanComTest = DontSending;
uint8_t lintest = 0;

/*VCU HW platform version*/
unsigned char VHALI_HWVersion;

APPDID_outSnapshots appDID_outSnapshot;

HWTest_PwmCtrlType udsHWTestPwmCtrl[PWM_NUM] = { {0}};

unsigned char Ex_Bios_LS_Output[LS_NUM]; /* 硬件测试，低驱输出 */
unsigned char Ex_Bios_HS_Output[HS_NUM]; /* 硬件测试，高驱输出 */
_NCV7719_INOUTPUT_ Ex_NCV7719_data; /* HW test , H  bridge output */
uint8_t SocResiMilgNvMCorrect = 0;
uint32_t VHALO_VCU_105_Ticks = 0;
uint8_t AuthFailData[AUTHFALIED_DATA_SIZE];   /*be used to store the auth failure internal data*/
uint8_t VCU20DetailedHwVer  = 0xB1;

boolean IsVINUseInitValue = 0;

/**************************************BTK relevant start****************************************************/
uint8_t VHALI_Local_Auth_Req = 0;
uint8_t EsclLinCommFailed = 0;
uint8_t VHALO_EsclStatus  = 0;
uint8_t EsclErrorCode  = 0;
uint8_t VHALO_VCU_PDU = 0;

/*开关量采集变量*/
unsigned char hIOP_SSB_Switch1_flg = 0; 
unsigned char hIOP_SSB_Switch2_flg = 0; 
/*内部模拟量采集变量*/
float hIOP_IGN1_FB_v = 0;  
float hIOP_IGN2_FB_v = 0;  
/*低驱驱动信号*/
unsigned char hIOP_IGN1_flg;
unsigned char hIOP_IGN2_flg;

uint8_t VHALI_SSB_Switch_1;
uint8_t VHALI_SSB_Switch_2;
float VHALI_IGN1_Out_v;   
float VHALI_IGN2_Out_v;   

uint8_t VHALO_IGN1_Flg;
uint8_t VHALO_IGN2_Flg;
uint8_t VHALO_SSB_GreenLed;
uint8_t VHALO_SSB_RedLed;
/**************************************BTK relevant end****************************************************/

 uint8_t VHALI_PTCLowReqIn_flg=0 ;  //  Z18: PTC低档请求信号
 uint8_t VHALI_PTCHighReqIn_flg=0 ; //  Z18: PTC高档请求信号
 uint8_t VHALI_DefrostActiveIn_flg=0 ;//Z18: 除霜开关输入（12V）
 uint8_t VHALI_EACReqIn_flg=0 ;    //Z18: 压缩机开启请求信号（+12V�
 unsigned char VHALI_EHU_VSPSwitchSet = 0;/*低速行人提醒开关设置*/
 
boolean gblUdsECUUpgrade=FALSE;
boolean gblUdsKeepPresent = FALSE; //UDS request ECU to keep present(3E)
boolean gblUdsCommCtrl = FALSE; //1:UDS禁止应用报文接收标志 ; 0:无UDS禁止，应用报文正常接收
uint8_t gblNVMStateMachineSts = 0;

/**************************************ENM config****************************************************/
/****************************************S21 seat motor relevant start ************************************************/

/*开关量采集变量*/
unsigned char hIOP_SeatHall_flg=0;
unsigned char hIOP_FrontSeatMotorSwitch_flg=0;
unsigned char hIOP_RearSeatMotorSwitch_flg=0;
/*低驱驱动信号*/
unsigned char hIOP_FrontSeatMotorRelay_flg;
unsigned char hIOP_RearSeatMotorRelay_flg;

uint8_t VHALI_SeatHallActiveIn_flg;
uint8_t VHALI_FrontSeatMotorSwitchActiveIn_flg;
uint8_t VHALI_RearSeatMotorSwitchActiveIn_flg;
uint32_t VHALI_SeatHallcnt=0;

uint8_t VHALO_FrontSeatMotorRelayActive_flg;
uint8_t VHALO_RearSeatMotorRelayActive_flg;

/****************************************S21 seat motor relevant end ************************************************/
uint32_t BMSBattRatedPwrNextTime = 0;


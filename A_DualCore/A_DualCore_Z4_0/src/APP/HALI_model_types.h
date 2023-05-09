/*
 * File: HALI_model_types.h
 *
 * Code generated for Simulink model 'HALI_model'.
 *
 * Model version                  : 1.816
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Fri Mar 18 15:39:52 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Freescale->32-bit PowerPC
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_HALI_model_types_h_
#define RTW_HEADER_HALI_model_types_h_
#include "rtwtypes.h"
#ifndef DEFINED_TYPEDEF_FOR_HALI_Hardwire_
#define DEFINED_TYPEDEF_FOR_HALI_Hardwire_

typedef struct {
  boolean_T VHALI_GearSwitch1Active_flg;
  boolean_T VHALI_GearSwitch2Active_flg;
  boolean_T VHALI_GearSwitch3Active_flg;
  boolean_T VHALI_GearSwitch4Active_flg;
  boolean_T VHALI_ACSwitchActive_flg;
  uint8_T VHALI_Collisionfre_Hz;
  uint8_T VHALI_CollisionDuty_pct;
  uint8_T VHALI_HVInterlockFreIn_Hz;
  boolean_T VHALI_SlowChargeAwakeActive_flg;
  boolean_T VHALI_FastChargeAwakeActive_flg;
  boolean_T VHALI_IgnitionOn_flg;
  boolean_T VHALI_CrankActive_flg;
  boolean_T VHALI_BrkLightSwitch1Active_flg;
  real32_T VHALI_AccelPedalL_V;
  real32_T VHALI_AccelPedalH_V;
  real32_T VHALI_FastChargeTemp1_C;
  real32_T VHALI_FastChargeTemp2_C;
  real32_T VHALI_Sensor5V1_V;
  real32_T VHALI_Sensor5V2_V;
  real32_T VHALI_LVBattVoltage_V;
  real32_T VHALI_LVK15Voltage_V;
  real32_T VHALI_PCBTemp_V;
  uint32_T VHALI_LSFaultCode_enum;
  uint8_T VHALI_HSFaultCode_enum;
  boolean_T VHALI_FastChrgCANAwakeActive_flg;
  uint8_T VHAL_BrkVacuum_kPa;
  boolean_T VHALI_BrkLightSwitch2Active_flg;
  uint32_T VHAL_VCUCanTickCount;
  uint32_T VHAL_VCUPTCanTickCount;
  uint32_T VHAL_VCUBodyCanTickCount;
  uint32_T VHALI_BMS_113_MsgTicks;
  uint32_T VHALI_BMS_213_MsgTicks;
  uint32_T VHALI_BMS_233_MsgTicks;
  uint32_T VHALI_BMS_303_MsgTicks;
  uint32_T VHALI_BMS_313_MsgTicks;
  uint32_T VHALI_BMS_323_MsgTicks;
  uint32_T VHALI_BMS_377_MsgTicks;
  uint32_T VHALI_BMS_513_MsgTicks;
  boolean_T VHALI_PTCSwitchActive_flg;
  uint16_T VHALI_VacuumPumpIn_Hz;
  boolean_T VHALI_HandBrake;
  uint32_T VHALI_BMS_633_MsgTicks;
  uint32_T VHALI_MCU_115_MsgTicks;
  uint32_T VHALI_MCU_125_MsgTicks;
  uint32_T VHALI_MCU_215_MsgTicks;
  uint32_T VHALI_MCU_515_MsgTicks;
  uint32_T VHALI_DCDC_231_MsgTicks;
  uint32_T VHALI_DCDC_251_MsgTicks;
  uint32_T VHALI_OBC_311_MsgTicks;
  uint32_T VHALI_OBC_321_MsgTicks;
  uint32_T VHALI_OBC_331_MsgTicks;
  uint32_T VHALI_PTC_5DA_MsgTicks;
  uint32_T VHALI_ECC_33C_MsgTicks;
  uint32_T VHALI_ECC_34C_MsgTicks;
  uint32_T VHALI_ECC_35C_MsgTicks;
  uint32_T VHALI_PEPS_108_MsgTicks;
  uint32_T VHALI_PEPS_103_MsgTicks;
  uint32_T VHALI_SRS_050_MsgTicks;
  uint32_T VHALI_ABS_232_MsgTicks;
  uint32_T VHALI_ABS_237_MsgTicks;
  uint32_T VHALI_GW_217_MsgTicks;
  uint32_T VHALI_GW_522_MsgTicks;
  uint32_T VHALI_TPMS_317_MsgTicks;
  uint32_T VHALI_TPMS_3A2_MsgTicks;
  uint32_T VHALI_EAC_349_MsgTicks;
  uint32_T VHALI_TBOX_298_MsgTicks;
  uint8_T VHALI_WaterPwmIn_Duty;
  uint16_T VHALI_WaterPwmIn_Hz;
  uint32_T VHALI_EPS_2A0_MsgTicks;
  uint32_T VHALI_EPS_180_MsgTicks;
  uint32_T VHALI_ECC_36C_MsgTicks;
  uint32_T VHALI_BMS_653_MsgTicks;
  uint32_T VHALI_PEPS_282_MsgTicks;
  uint32_T VHALI_BMS_603_MsgTicks;
  uint32_T VHALI_PTC_5DB_MsgTicks;
  uint32_T VHALI_TBOX_296_MsgTicks;
  uint32_T VHALI_GW_405_MsgTicks;
  uint32_T VHALI_TMS_2C0_MsgTicks;
  uint32_T VHALI_TMS_2C1_MsgTicks;
  uint32_T VHALI_TMS_2C2_MsgTicks;
  uint32_T VHALI_TMS_2C3_MsgTicks;
  uint32_T VHALI_WPTC_2F0_MsgTicks;
  uint32_T VHALI_EHU_345_MsgTicks;
  uint32_T VHALI_TMS_325_MsgTicks;
  uint32_T VHALI_WPTC_566_MsgTicks;
  real32_T VHALI_Batt_InWater_T;
  real32_T VHALI_Batt_OutWater_T;
  uint32_T VHALI_BMS_304_MsgTicks;
  uint32_T VHALI_BMS_613_MsgTicks;
  uint32_T VHALI_ABS_229_MsgTicks;
  uint32_T VHALI_BMS_623_MsgTicks;
  uint32_T VHALI_EAC_34A_MsgTicks;
  int16_T VHALI_BatInWaterT_deg;
  int16_T VHALI_PTSensorT_deg;
  uint16_T VHALI_PTSensorP_kPa;
  uint32_T VHALI_ICM_235_MsgTicks;
  boolean_T VHALI_ClutchSwitch1_flg;
  boolean_T VHALI_ClutchSwitch2_flg;
  boolean_T VHALI_SSB_Switch_1;
  boolean_T VHALI_SSB_Switch_2;
  boolean_T VHALI_PTCLowReqIn_flg;
  boolean_T VHALI_PTCHighReqIn_flg;
  boolean_T VHALI_DefrostActiveIn_flg;
  boolean_T VHALI_EACReqIn_flg;
  real32_T VHALI_IGN1_Out_v;
  real32_T VHALI_IGN2_Out_v;
} HALI_Hardwire;

#endif

#ifndef DEFINED_TYPEDEF_FOR_HALI_TMS_
#define DEFINED_TYPEDEF_FOR_HALI_TMS_

typedef struct {
  uint8_T VHALI_TMS_PoweDesired_WPTC;
  uint8_T VHALI_TMS_AC_SwtSts;
  boolean_T VHALI_TMS_AC_ReqValid;
  uint16_T VHALI_TMS_AC_TargetPower;
  boolean_T VHALI_TMS_PTCSwtSts;
  boolean_T VHALI_TMS_PTC_ReqValid;
  uint16_T VHALI_TMS_PTCTargetPwr;
  boolean_T VHALI_TMS_WPTC_Req;
  boolean_T VHALI_TMS_WPTC_ReqValid;
  uint16_T VHALI_TMS_WPTCTargetPwr;
  boolean_T VHALI_TMS_AC_Command;
  uint8_T VHALI_TMS_AC_SpeedSet;
  uint16_T VHALI_TMS_AC_Pow_limit;
  boolean_T VHALI_TMS_PTC_Command;
  uint8_T VHALI_TMS_PTC_Target_T;
  uint16_T VHALI_TMS_PTC_Pow_limit;
  uint16_T VHALI_PTC_MAXPower;
  uint16_T VHALI_AC_MAXPower;
  uint16_T VHALI_WPTC_MAXPower;
  boolean_T VHALI_TMS_Batt_GVSt;
  uint8_T VHALI_TMS_Batt_EXVSt;
  boolean_T VHALI_TMS_Cabin_GVSt;
  uint8_T VHALI_TMS_Cabin_EXVSt;
  uint8_T VHALI_TMS_Batt_WPFlow;
} HALI_TMS;

#endif

#ifndef DEFINED_TYPEDEF_FOR_HALI_WPTC_
#define DEFINED_TYPEDEF_FOR_HALI_WPTC_

typedef struct {
  uint8_T VHALI_WPTC_CurrentPower;
  uint8_T VHALI_WPTC_RunMode;
  boolean_T VHALI_WPTC_State;
  uint8_T VHALI_WPTC_WaterTemp;
  uint16_T VHALI_WPTC_Power;
  uint8_T VHALI_WPTC_InVoltage;
  uint8_T VHALI_WPTC_BusbarCurrent;
  uint8_T VHALI_WPTC_IGBTTemp;
  boolean_T VHALI_WPTC_OverHV;
  boolean_T VHALI_WPTC_UnderHV;
  boolean_T VHALI_WPTC_OverLV;
  boolean_T VHALI_WPTC_UnderLV;
  boolean_T VHALI_WPTC_OverCurrent;
  boolean_T VHALI_WPTC_WaterOverHeat;
  boolean_T VHALI_WPTC_IGBTOverHeat;
  boolean_T VHALI_WPTC_IGBTDriverFlt;
  boolean_T VHALI_WPTC_WaterTempSnsrFlt;
  boolean_T VHALI_WPTC_IGBTTempSnsrFlt;
  boolean_T VHALI_WPTC_HVCircCut;
  boolean_T VHALI_WPTC_HVCircShort;
} HALI_WPTC;

#endif

#ifndef DEFINED_TYPEDEF_FOR_HALI_PTC_
#define DEFINED_TYPEDEF_FOR_HALI_PTC_

typedef struct {
  uint8_T VHALI_PTC_State;
  uint8_T VHALI_PTC_Temperature;
  uint16_T VHALI_PTC_Power;
  uint16_T VHALI_PTC_InVoltage;
  uint8_T VHALI_PTC_HVUnderfault;
  uint8_T VHALI_PTC_HVOverfault;
  uint8_T VHALI_PTC_HVOFFfault;
  uint8_T VHALI_PTC_OverCurrfault;
  uint8_T VHALI_PTC_IGBTErr;
  uint8_T VHALI_PTC_IGBTTSnsrErr;
  uint8_T VHALI_PTC_IGBTOverTErr;
  uint8_T VHALI_PTC_TempSnsrErr;
  uint8_T VHALI_PTC_TempOverTErr;
  uint16_T VHALI_PTCIGBTT;
} HALI_PTC;

#endif

#ifndef DEFINED_TYPEDEF_FOR_HALI_EAC_
#define DEFINED_TYPEDEF_FOR_HALI_EAC_

typedef struct {
  uint16_T VHALI_AC_ActSpeed;
  uint8_T VHALI_AC_Command;
  uint8_T VHALI_ECC_A_C_Req;
  uint8_T VHALI_ECC_A_C_ReqValid;
  uint8_T VHALI_AC_SpeedSet;
  uint16_T VHALI_AC_AcceptPower;
  uint8_T VHALI_AC_Counter;
  uint8_T VHALI_AC_Checksum;
  uint8_T VHALI_Bus_cur_ERR;
  uint8_T VHALI_Bus_limit;
  uint8_T VHALI_CAN_ERR;
  uint8_T VHALI_COMPBaseState;
  uint8_T VHALI_COMPCurr;
  uint8_T VHALI_COMPMotor_Temp;
  uint8_T VHALI_COMPVold;
  uint8_T VHALI_HVolt_ERR;
  int16_T VHALI_COMPSpeed_now;
  uint8_T VHALI_LVolt_ERR;
  uint8_T VHALI_Pow_limit;
  uint8_T VHALI_Start_ERR;
  uint16_T VHALI_AC_TargetPower;
  uint16_T VHALI_EAC_RealSpeed;
  uint16_T VHALI_EAC_PowerConsumption;
  uint8_T VHALI_EAC_BusbarVoltage;
  uint8_T VHALI_EAC_BusbarCurrent;
  uint8_T VHALI_EAC_PeakPhaCurrent;
  uint8_T VHALI_EAC_IGBTTemp;
  uint8_T VHALI_EAC_CurrentState;
  boolean_T VHALI_EAC_SampleCircMalfct;
  boolean_T VHALI_EAC_LackPhase;
  boolean_T VHALI_EAC_IGBTMalfct;
  boolean_T VHALI_EAC_TempSensorFault;
  boolean_T VHALI_EAC_OverCurrent;
  boolean_T VHALI_EAC_StallFault;
  boolean_T VHALI_EAC_OverHeatFault;
  boolean_T VHALI_EAC_RotateSpdAnomaly;
  boolean_T VHALI_EAC_OverPhaVoltMalfct;
  boolean_T VHALI_EAC_Overload;
  boolean_T VHALI_EAC_OverHighVolt;
  boolean_T VHALI_EAC_UnderHighVolt;
  boolean_T VHALI_EAC_TTLfault;
} HALI_EAC;

#endif

#ifndef DEFINED_TYPEDEF_FOR_HALI_EPTC_
#define DEFINED_TYPEDEF_FOR_HALI_EPTC_

typedef struct {
  uint16_T VHALI_PTCActPower;
  uint8_T VHALI_PTCCommand;
  uint8_T VHALI_ECC_PTC_Req;
  uint8_T VHALI_ECC_PTC_ReqValid;
  uint16_T VHALI_PTCTargetPwr;
  uint8_T VHALI_PTCCounter;
  uint8_T VHALI_PTCChecksum;
  uint8_T VHALI_FrontDefrosterSwitch;
  uint8_T VHALI_RearDefrosterSwitch;
  uint16_T VHALI_PTC_MAXPower;
  uint16_T VHALI_AC_MAXPower;
} HALI_EPTC;

#endif

#ifndef DEFINED_TYPEDEF_FOR_HALI_PEPS_
#define DEFINED_TYPEDEF_FOR_HALI_PEPS_

typedef struct {
  uint8_T VHALI_PEPS_EncryptedRsvd;
  uint8_T VHALI_PEPS_EncryptedStatus;
  uint8_T VHALI_PEPS_EncryptedResponseByte5;
  uint8_T VHALI_PEPS_EncryptedResponseByte4;
  uint8_T VHALI_PEPS_EncryptedResponseByte3;
  uint8_T VHALI_PEPS_EncryptedResponseByte2;
  uint8_T VHALI_PEPS_EncryptedResponseByte1;
  uint8_T VHALI_PEPS_EncryptedResponseByte0;
  uint32_T VHALI_PEPS108Rcv;
  uint8_T VHALI_PEPS_ReAuth_Req;
  uint32_T VHALI_PEPS103Rcv;
  uint8_T VHALI_PEPS_PDU;
  uint8_T VHALI_PEPS_RkeCmd;
} HALI_PEPS;

#endif

#ifndef DEFINED_TYPEDEF_FOR_HALI_SRS_
#define DEFINED_TYPEDEF_FOR_HALI_SRS_

typedef struct {
  uint8_T VHALI_SRS_CrashOutputStatusCheckSum;
  uint8_T VHALI_SRS_CrashOutputStatus;
  uint8_T VHALI_SRS_WarningLampStatus;
  uint8_T VHALI_SRS_PassengerBuckleSwitchStatus;
  uint8_T VHALI_SRS_DriverBuckleSwitchStatus;
  uint8_T VHALI_SRS_FrontPsgOccupancy;
  uint8_T VHALI_SRS_RollingCounter;
} HALI_SRS;

#endif

#ifndef DEFINED_TYPEDEF_FOR_HALI_ABS_
#define DEFINED_TYPEDEF_FOR_HALI_ABS_

typedef struct {
  uint8_T VHALI_NO_Evflag;
  uint8_T VHALI_ABS_EbdFlgFlt;
  uint8_T VHALI_ABS_AbsFlgFlt;
  uint8_T VHALI_ABS_AbsCtrlActv;
  uint8_T VHALI_ABS_VehicleSpeedValid;
  uint16_T VHALI_ABS_VehicleSpeed;
  uint8_T VHALI_ABS_RollingCounter;
  uint8_T VHALI_ABS_Checksum;
  uint8_T VHALI_ABS_Checksum237;
  uint8_T VHALI_ABS_RollingCounter237;
  int16_T VHALI_WheelSpeedPlusCounter_FL;
  boolean_T VHALI_WheelSpeedPlusCounter_FL_Valid;
  int16_T VHALI_WheelSpeedPlusCounter_FR;
  boolean_T VHALI_WheelSpeedPlusCounter_FR_Valid;
  int16_T VHALI_WheelSpeedPlusCounter_RL;
  boolean_T VHALI_WheelSpeedPlusCounter_RL_Valid;
  int16_T VHALI_WheelSpeedPlusCounter_RR;
  boolean_T VHALI_WheelSpeedPlusCounter_RR_Valid;
  boolean_T VHALI_ESP_TCSActiveStatus;
  boolean_T VHALI_ESP_ESPSwitchStatus;
  boolean_T VHALI_ESP_ESPActiveStatus;
  boolean_T VHALI_ESP_ESPFailStatus;
  uint16_T VHALI_ESC_MotorTorq_Req;
  uint8_T VHALI_ESC_MotorWork_Req;
  boolean_T VHALI_ESP_HHCActiveStatus;
  boolean_T VHALI_ESP_EBDActiveStatus;
  boolean_T VHALI_ESP_HBAActiveStatus;
  uint8_T VHALI_ABS_FLWheelSpeedValid;
  uint16_T VHALI_ABS_FLWheelSpeed;
  uint8_T VHALI_ABS_FRWheelSpeedValid;
  uint16_T VHALI_ABS_FRWheelSpeed;
  uint8_T VHALI_ABS_RLWheelSpeedValid;
  uint16_T VHALI_ABS_RLWheelSpeed;
  uint8_T VHALI_ABS_RRWheelSpeedValid;
  uint16_T VHALI_ABS_RRWheelSpeed;
} HALI_ABS;

#endif

#ifndef DEFINED_TYPEDEF_FOR_HALI_EHU_
#define DEFINED_TYPEDEF_FOR_HALI_EHU_

typedef struct {
  uint32_T VHALI_ClstrOdo;
  uint8_T VHALI_EHU_EnergyRecovery;
  uint8_T VHALI_EHU_DriverModel;
  uint8_T VHALI_EHU_VoiceIdentify;
  uint8_T VHALI_SubtotalEgyCnseRet;
  boolean_T VHALI_EHUVehrpValid;
  uint8_T VHALI_BCM_RearDefrosterstatus;
  uint16_T VHALI_ICM_VehicleSpeedDisplay;
  uint8_T VHALI_EHU_VSPSwitchSet;
  uint8_T VHALI_DriveHeatAllow;
} HALI_EHU;

#endif

#ifndef DEFINED_TYPEDEF_FOR_HALI_EPB_
#define DEFINED_TYPEDEF_FOR_HALI_EPB_

typedef struct {
  uint8_T VHALI_EPB_Status;
  uint8_T VHALI_EPB_Brake_Lights_Requested;
  uint8_T VHALI_EPS_TorqSensorStatus;
  uint8_T VHALI_EPS_EpasFailed;
  uint8_T VHALI_EPB_Acceleration_X;
  uint16_T VHALI_SAS_SteeringAngle;
  uint8_T VHALI_SAS_SteeringAngleSpeed;
} HALI_EPB;

#endif

#ifndef DEFINED_TYPEDEF_FOR_HALI_BMS_
#define DEFINED_TYPEDEF_FOR_HALI_BMS_

typedef struct {
  uint16_T VHALI_BMSBattU;
  uint16_T VHALI_BMSBattI;
  uint16_T VHALI_BMSSOC;
  uint8_T VHALI_BMSFltRnk;
  uint8_T VHALI_BMSOperMod;
  uint8_T VHALI_BMSOBCOperModReq;
  uint8_T VHALI_BMSPwrUpAllw;
  uint8_T VHALI_BMSHVILSts;
  uint8_T VHALI_BMSCrashSts;
  uint8_T VHALI_BMSRlyWlddErr;
  uint8_T VHALI_BMSInsulationSts;
  uint8_T VHALI_BMSInsulationIntrErr;
  uint8_T VHALI_BMSInsulationHVLoadErr;
  uint8_T VHALI_BMS113CycCntr;
  uint8_T VHALI_BMSCRCChk113;
  uint16_T VHALI_BMSMaxChrgU;
  uint16_T VHALI_BMSMinDchaIU;
  uint16_T VHALI_BMSBattExU;
  uint8_T VHALI_BMS213CycCntr;
  uint8_T VHALI_BMSCRCChk213;
  uint16_T VHALI_BMSMaxDchaPwr;
  uint16_T VHALI_BMSMaxChrgPwr;
  uint16_T VHALI_BMSMaxDchaI;
  uint16_T VHALI_BMSMaxChrgI;
  uint8_T VHALI_BMS233CycCntr;
  uint8_T VHALI_BMSCRCChk233;
  uint16_T VHALI_BMSChrgUReq;
  uint16_T VHALI_BMSChrgIReq;
  uint16_T VHALI_BMSOBCMaxChrgPwrAvl;
  uint8_T VHALI_BMSOBCHeatModeCtrl;
  uint8_T VHALI_BMSChrgMod;
  uint8_T VHALI_BMSChrgErrInfo;
  uint8_T VHALI_BMSChrgSts;
  uint8_T VHALI_BMSDCChrgRlySts;
  uint8_T VHALI_BMS303CycCntr;
  uint8_T VHALI_BMSCRCChk303;
  uint8_T VHALI_BMSMaxBattT;
  uint8_T VHALI_BMSMinBattT;
  uint16_T VHALI_BMSPredChrgTi;
  uint8_T VHALI_BMSBattIntrHeatReq;
  uint8_T VHALI_BMSBattIntrHeatActv;
  uint16_T VHALI_BMSIsolationR;
  uint8_T VHALI_BMSAvrgBattT;
  uint8_T VHALI_BMSMILReq;
  uint8_T VHALI_BMS313CycCntr;
  uint8_T VHALI_BMSCRCChk313;
  uint8_T VHALI_BMSSOCMax;
  uint8_T VHALI_BMSSOCMin;
  uint16_T VHALI_BMSSOH;
  uint16_T VHALI_BMSRmaingCpby;
  uint8_T VHALI_BMSEquilnSts;
  uint16_T VHALI_BMSCC2SngR;
  uint8_T VHALI_BMSBattHeatI;
  uint8_T VHALI_BMSErrAmnt;
  uint16_T VHALI_BMSErrNum;
  uint16_T VHALI_BMSCCSngR;
  uint16_T VHALI_BMSCellUMin;
  uint8_T VHALI_BMSCellUMinCellNum;
  uint8_T VHALI_BMSCellUMinBattNum;
  uint16_T VHALI_BMSCellUMax;
  uint8_T VHALI_BMSCellUMaxCellNum;
  uint8_T VHALI_BMSCellUMaxBattNum;
  uint8_T VHALI_BMSBattNumTot;
  uint8_T VHALI_BMSCellNumTot;
  uint16_T VHALI_BMSBattResidPwr;
  boolean_T VHALI_BMSDateMonitoringReq;
  uint8_T VHALI_BMSDateMonitoringt;
  boolean_T VHALI_TMS_StateOverT;
  boolean_T VHALI_TMS_COOLErr;
  uint8_T VHALI_BMSBattTherMagReq;
  uint8_T VHALI_BMSBattTherTargetFlow;
  uint8_T VHALI_BMSBattTherTargetT;
  uint16_T VHALI_BMSBattRatedPwr;
  uint16_T VHALI_BMSCellUMinUnderU;
  uint16_T VHALI_BMSBattUOverU;
  uint16_T VHALI_BMSBattUUnderU;
  uint16_T VHALI_BMSCellUMaxOverU;
  uint8_T VHALI_BMSMaxBattTOverT;
  uint8_T VHALI_BMSBattTherMagErr;
  uint16_T VHALI_ChrgSysMaxPwrSup;
  uint8_T VHALI_BMSS2Stus;
  uint8_T VHALI_BMSPlugLockStatus;
  uint16_T VHALI_BMSPPSngR;
  uint8_T VHALI_BMSCPSts;
  uint8_T VHALI_BMSCPValue;
  boolean_T VHALI_BMSIChrgEna;
  uint16_T VHALI_ChrgPilePwrAvail;
} HALI_BMS;

#endif

#ifndef DEFINED_TYPEDEF_FOR_HALI_MCU_
#define DEFINED_TYPEDEF_FOR_HALI_MCU_

typedef struct {
  uint16_T VHALI_MCUElecMotSpd;
  uint16_T VHALI_MotTqReal;
  uint8_T VHALI_MCUOperMdl;
  uint16_T VHALI_MCUMaxAvlTq;
  uint8_T VHALI_Spdvalidflag;
  uint16_T VHALI_MCUMinAvlTq;
  uint8_T VHALI_Trqvalidflag;
  uint8_T VHALI_MCUID153CycCntr;
  uint16_T VHALI_MCUDcU;
  uint16_T VHALI_MCUDcCrrt;
  uint16_T VHALI_MCUPhaCrrt;
  uint8_T VHALI_MCUFltRnk;
  uint16_T VHALI_MCUElecMotT;
  uint8_T VHALI_MCUMotNumTot;
  uint8_T VHALI_MCUMotNum;
  uint16_T VHALI_MCUIGBTT;
  uint8_T VHALI_MCUT;
  uint8_T VHALI_MCUErrAmnt;
  uint8_T VHALI_MCUErrNum;
  uint8_T VHALI_MCUMotSts;
  uint8_T VHALI_Hardware_Ver;
  uint8_T VHALI_Motor_Ver;
  uint8_T VHALI_Software_Ver;
  uint8_T VHALI_MCUPwrModErr;
  uint8_T VHALI_MCUOverTErr;
  uint8_T VHALI_MCUDcUOverUErr;
  uint8_T VHALI_MCUDcUUnderUErr;
  uint8_T VHALI_MCULowBatUnderUErr;
  uint8_T VHALI_MCUElecMotOverCrrtErr;
  uint8_T VHALI_MCUDCUShoCirc;
  uint8_T VHALI_MCUIGBTOverTErr;
  uint8_T VHALI_MCUElecMotOverTErr;
  uint8_T VHALI_MCUElecMotUnderTErr;
  uint8_T VHALI_MCUCANComErr;
  uint8_T VHALI_MCUDischrgErr;
  uint8_T VHALI_MCUPrechrgErr;
  uint8_T VHALI_MCUElecMotReslvErr;
  uint8_T VHALI_MCUElecMotStopTurnErr;
  uint8_T VHALI_MCUElecMotTqErr;
  uint8_T VHALI_MCUSystemErr;
  uint8_T VHALI_MCUDcUSnsrRatiErr;
  uint8_T VHALI_MCUTSnsrRatiErr;
  uint8_T VHALI_MCUIGBTTSnsrRatiErr;
  uint8_T VHALI_MCUElecMotTSnsrRatiErr;
  uint8_T VHALI_MCUDcCrrtSnsrRatiErr;
  uint8_T VHALI_MCUPhaACrrtSnsrRatiErr;
  uint8_T VHALI_MCUPhaCCrrtSnsrRatiErr;
  uint8_T VHALI_VMS_EN_Err;
  uint8_T VHALI_MCUHVLockErr;
  uint8_T VHALI_MCUPwrModUnderUErr;
  uint8_T VHALI_MCU131CRCErr;
  uint8_T VHALI_MCUCRCElecMotSpdErr;
  uint8_T VHALI_MCUCRCRealTqErr;
  uint8_T VHALI_MCUPhaBCrrtSnsrRatiErr;
  uint8_T VHALI_MCUUndefineErr2;
  uint8_T VHALI_MCUUndefineErr3;
  uint8_T VHALI_MCUElecMotOverSpdErr;
  boolean_T VHALI_MCUHWCurrOverErr;
  uint8_T VHALI_MCUMotopenphaseErr;
  uint8_T VHALI_MCUTarTorOverErr;
} HALI_MCU;

#endif

#ifndef DEFINED_TYPEDEF_FOR_HALI_DCDC_
#define DEFINED_TYPEDEF_FOR_HALI_DCDC_

typedef struct {
  uint16_T VHALI_DCDCInpU;
  uint16_T VHALI_DCDCOutpU;
  uint16_T VHALI_DCDCOutpCrrt;
  uint16_T VHALI_DCDCAvlOutpPwr;
  uint8_T VHALI_DCDCHwFltFlg;
  uint8_T VHALI_DCDCErrCANCom;
  uint8_T VHALI_DCDCOverInpU;
  uint8_T VHALI_DCDCUnderInpU;
  uint8_T VHALI_DCDCOverOutpU;
  uint8_T VHALI_DCDCUnderOutpU;
  uint8_T VHALI_DCDCOverOutpCrrt;
  uint8_T VHALI_DCDCOverOutpPwr;
  uint8_T VHALI_DCDCOverT;
  uint8_T VHALI_DCDCShoCircOutp;
  uint8_T VHALI_DCDCOperMod;
  uint8_T VHALI_DCDCFltRnk;
  uint8_T VHALI_DCDCT;
  uint8_T VHALI_DCDCIInput;
  uint32_T VHALI_DCDCSwVers;
} HALI_DCDC;

#endif

#ifndef DEFINED_TYPEDEF_FOR_HALI_OBC_
#define DEFINED_TYPEDEF_FOR_HALI_OBC_

typedef struct {
  uint16_T VHALI_OBCMaxChrgOutpUAvl;
  uint16_T VHALI_OBCMaxChrgOutpIAvl;
  uint16_T VHALI_OBCMaxChrgOutpPwrAvl;
  uint8_T VHALI_OBCVehInletT;
  uint8_T VHALI_OBCChrgSts;
  uint8_T VHALI_PlugLockStatus;
  uint8_T VHALI_OBCS2Stus;
  uint8_T VHALI_OBC311CycCntr;
  uint8_T VHALI_OBCFltRnk;
  uint8_T VHALI_OBCCPValue;
  uint8_T VHALI_CPSts;
  uint8_T VHALI_OBC321CycCntr;
  uint16_T VHALI_OBCChrgInpAcU;
  uint16_T VHALI_OBCChrgInpAcI;
  uint16_T VHALI_OBCChrgDcU;
  uint16_T VHALI_OBCChrgDcI;
  uint8_T VHALI_OBCT;
  uint8_T VHALI_OBCCANErr;
  uint8_T VHALI_OBCHwErr;
  uint8_T VHALI_OBCInpUOver;
  uint8_T VHALI_OBCOutpUOver;
  uint8_T VHALI_OBCInpUUnder;
  uint8_T VHALI_OBCOutpUUnder;
  uint8_T VHALI_OBCInpIOver;
  uint8_T VHALI_OBCOutpIOver;
  uint8_T VHALI_OBCTOvrErr;
  uint8_T VHALI_OBC331CycCntr;
} HALI_OBC;

#endif

#ifndef DEFINED_TYPEDEF_FOR_HALI_ECC_
#define DEFINED_TYPEDEF_FOR_HALI_ECC_

typedef struct {
  uint8_T VHALI_ECC_AutoReq;
  uint8_T VHALI_ECC_Blowing;
  uint8_T VHALI_ECC_EnvironmentalTemp;
  uint8_T VHALI_ECC_EvaporatorTemp;
  uint8_T VHALI_ECC_InterCarTemp;
  uint8_T VHALI_ECC_Mode;
  uint8_T VHALI_ECC_PM2_5;
  uint8_T VHALI_ECC_Rec_FreSetState;
  uint8_T VHALI_ECC_Sunlight;
  uint8_T VHALI_ECC_TempSetReq;
  uint8_T VHALI_ECC_RemoteACStatus;
  uint8_T VHALI_PTCRecTemp;
  uint16_T VHALI_ECC_PTCTargetPwrReq;
  uint16_T VHALI_ECC_ACTargetPwrReq;
} HALI_ECC;

#endif

#ifndef DEFINED_TYPEDEF_FOR_HALI_TPMS_
#define DEFINED_TYPEDEF_FOR_HALI_TPMS_

typedef struct {
  uint8_T VHALI_FLPressureWarning;
  uint8_T VHALI_FLTempHigh;
  uint8_T VHALI_FLTirePres;
  uint8_T VHALI_FRPressureWarning;
  uint8_T VHALI_FRTempHigh;
  uint8_T VHALI_FRTirePres;
  uint8_T VHALI_RLPressureWarning;
  uint8_T VHALI_RLTempHigh;
  uint8_T VHALI_RLTirePres;
  uint8_T VHALI_RRPressureWarning;
  uint8_T VHALI_RRTempHigh;
  uint8_T VHALI_RRTirePres;
  uint8_T VHALI_StudyFailureWarning;
  uint8_T VHALI_StudyMode;
  uint8_T VHALI_SystemWarning;
  uint8_T VHALI_TPMSLearnIdStatus;
  uint8_T VHALI_FLTireTemp;
  uint8_T VHALI_FRTireTemp;
  uint8_T VHALI_RLTireTemp;
  uint8_T VHALI_RRTireTemp;
} HALI_TPMS;

#endif

#ifndef DEFINED_TYPEDEF_FOR_HALI_TBOX_
#define DEFINED_TYPEDEF_FOR_HALI_TBOX_

typedef struct {
  uint8_T VHALI_TBOX_TimeValid;
  uint8_T VHALI_TBOX_TimeYear;
  uint8_T VHALI_TBOX_TimeMonth;
  uint8_T VHALI_TBOX_TimeDate;
  uint8_T VHALI_TBOX_TimeHour;
  uint8_T VHALI_TBOX_TimeMinute;
  uint8_T VHALI_TBOX_TimeSecond;
  boolean_T VHALI_TBOX_RemoteHVACReq;
  boolean_T VHALI_TBOX_RemoteWorkReq;
  boolean_T VHALI_IChrgWakeUpReq;
  uint8_T VHALI_TBOX_LockCommand;
} HALI_TBOX;

#endif

#ifndef DEFINED_TYPEDEF_FOR_HALI_LIN_
#define DEFINED_TYPEDEF_FOR_HALI_LIN_

typedef struct {
  uint16_T VHALI_EWP_ErrorCode;
  uint16_T VHALI_EWP_CurrentSpeed;
  uint16_T VHALI_EWP_Volatge;
  uint8_T VHALI_EWP_Temperature;
  uint8_T VHALI_EXV_ErrorCheck;
  uint8_T VHALI_EXV_InitStatus;
  uint8_T VHALI_EXV_RunStatus;
  uint8_T VHALI_EXV_ErrorStatus;
  uint8_T VHALI_EXV_VolatgeErrorStatus;
  uint8_T VHALI_EXV_TemperatureErrorStatus;
  uint16_T VHALI_EXV_Position;
} HALI_LIN;

#endif

#ifndef DEFINED_TYPEDEF_FOR_HALI_FCW_
#define DEFINED_TYPEDEF_FOR_HALI_FCW_

typedef struct {
  uint8_T VHALI_LDW_Left_Detected;
  uint8_T VHALI_LDW_Left_Departure;
  uint8_T VHALI_LDW_Right_Detected;
  uint8_T VHALI_LDW_Right_Departure;
  uint8_T VHALI_LDW_Alarm_Off;
  uint8_T VHALI_Ambient_Light;
  uint8_T VHALI_Calibration_Board_Detected;
  uint8_T VHALI_LWheelLaneDistance;
  uint8_T VHALI_RWheelLaneDistance;
  uint8_T VHALI_FCW_TTC;
  uint8_T VHALI_FCW_TTC_Valid_Flag;
  uint8_T VHALI_Forward_Vehicle_Detected;
  uint8_T VHALI_Forward_Collision_Warning;
  uint8_T VHALI_Forward_Vehicle_Distance;
  uint8_T VHALI_Pre_Collision_Warning;
  uint8_T VHALI_System_Status;
  uint8_T VHALI_LDWS_Running_Status;
  uint8_T VHALI_FCWS_Running_Status;
  uint8_T VHALI_PCWS_Running_Status;
  uint8_T VHALI_CALIB_Running_Status;
  uint8_T VHALI_System_Boot_Failed;
  uint8_T VHALI_Camera_Error;
  uint8_T VHALI_System_Halted_Error;
  uint8_T VHALI_CAN_Receive_Error;
  uint8_T VHALI_Need_Calibrate_Error;
} HALI_FCW;

#endif

#ifndef DEFINED_TYPEDEF_FOR_HALI_EPS_
#define DEFINED_TYPEDEF_FOR_HALI_EPS_

typedef struct {
  uint8_T VHALI_SAS_SteeringAngleValid;
  uint8_T VHALI_SAS_SASFailure;
  uint8_T VHALI_SAS_Calibrated;
} HALI_EPS;

#endif

#ifndef DEFINED_TYPEDEF_FOR_HALI_XBS_
#define DEFINED_TYPEDEF_FOR_HALI_XBS_

typedef struct {
  uint16_T VHALI_BrakeSysRegTrqTrgt;
  uint8_T VHALI_BrakeSysRegTrqTrgtValid;
  uint8_T VHALI_BrakePedalApplied;
  uint8_T VHALI_BrakePedalAppliedValid;
  uint8_T VHALI_BrakePedalPosition;
  uint8_T VHALI_BrakePedalPositionValid;
  uint8_T VHALI_XBS_BLReq;
  uint8_T VHALI_C_boosterFaultStatus;
} HALI_XBS;

#endif

#ifndef DEFINED_TYPEDEF_FOR_HALI_BCM_
#define DEFINED_TYPEDEF_FOR_HALI_BCM_

typedef struct {
  uint8_T VHALI_DrvrDoorSts;
  uint8_T VHALI_FrtPsngDoorSts;
  uint8_T VHALI_RLDoorSts;
  uint8_T VHALI_RRDoorSts;
  uint8_T VHALI_TailgateSts;
  uint8_T VHALI_VehLckSts;
} HALI_BCM;

#endif

#ifndef DEFINED_TYPEDEF_FOR_HALI_CAN_
#define DEFINED_TYPEDEF_FOR_HALI_CAN_

typedef struct {
  HALI_TMS HALI_TMS;
  HALI_WPTC HALI_WPTC;
  HALI_PTC HALI_PTC;
  HALI_EAC HALI_EAC;
  HALI_EPTC HALI_EPTC;
  HALI_PEPS HALI_PEPS;
  HALI_SRS HALI_SRS;
  HALI_ABS HALI_ABS;
  HALI_EHU HALI_EHU;
  HALI_EPB HALI_EPB;
  HALI_BMS HALI_BMS;
  HALI_MCU HALI_MCU;
  HALI_DCDC HALI_DCDC;
  HALI_OBC HALI_OBC;
  HALI_ECC HALI_ECC;
  HALI_TPMS HALI_TPMS;
  HALI_TBOX HALI_TBOX;
  HALI_LIN HALI_LIN;
  HALI_FCW HALI_FCW;
  HALI_EPS HALI_EPS;
  HALI_XBS HALI_XBS;
  HALI_BCM HALI_BCM;
} HALI_CAN;

#endif

#ifndef DEFINED_TYPEDEF_FOR_HALI_
#define DEFINED_TYPEDEF_FOR_HALI_

typedef struct {
  HALI_Hardwire Hardwire_Inputs;
  HALI_CAN CAN_Inputs;
} HALI;

#endif
#endif                                 /* RTW_HEADER_HALI_model_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

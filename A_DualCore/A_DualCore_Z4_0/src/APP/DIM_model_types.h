/*
 * File: DIM_model_types.h
 *
 * Code generated for Simulink model 'DIM_model'.
 *
 * Model version                  : 1.2422
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Fri Mar 18 15:35:30 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Freescale->32-bit PowerPC
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_DIM_model_types_h_
#define RTW_HEADER_DIM_model_types_h_
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

#ifndef DEFINED_TYPEDEF_FOR_DHP_
#define DEFINED_TYPEDEF_FOR_DHP_

typedef struct {
  boolean_T VDHP_BrakeSysFault_Flg;
  boolean_T VDHP_AccPedalFault_Flg;
  boolean_T VDHP_GearSingleNotInAeraFlt_Flg;
  boolean_T DCDCFault_Flg;
  boolean_T OBCFault_Flg;
  boolean_T MCUFault_Flg;
  boolean_T BMSFault_Flg;
  uint8_T VDHP_MaxFaultLever;
  boolean_T VDHP_HVILErrFault_flg;
  uint8_T VDHP_BrkDSCheckFaultLevel_enum;
  boolean_T VDHP_VehCrashFault_flg;
  boolean_T VDHP_MCU_DisEnableFlg;
  boolean_T VDHP_AuxBattVoltHighInstFlt_flg;
  boolean_T VDHP_AuxBattVoltLowInstFlt_flg;
  boolean_T VDHP_Forbid_DCDCFlg;
  boolean_T VDHP_Forbid_ConditionFlg;
  boolean_T VDHP_Forbid_PTCFlg;
  uint8_T VDHP_Spd_Limit;
  uint8_T VDHP_Pwr_Limit_Pct;
  boolean_T VDHP_Forbid_ChargeFlg;
  boolean_T VDHP_Forbid_ActiveDischargeFlg;
  boolean_T VDHP_Forbid_PreChargeFlg;
  boolean_T VDHP_Off_DeviceRelayFlg;
  boolean_T VDHP_OFFMainRelayFlg;
  boolean_T VDHP_OFFAllHVRelayFlg;
  boolean_T VDHP_Normal_PowerDownFlg;
  boolean_T VDHP_AccPdlLVoltLowInstFlt_flg;
  boolean_T VDHP_AccPdlLVoltLowFault_flg;
  boolean_T VDHP_AccPdlLVoltHighInstFlt_flg;
  boolean_T VDHP_AccPdlLVoltHighFault_flg;
  boolean_T VDHP_AccPdlLHVoltDeathInstFlt_flg;
  boolean_T VDHP_AccPdlLHVoltDeathFault_flg;
  boolean_T VDHP_AccPdlHVoltLowInstFlt_flg;
  boolean_T VDHP_AccPdlHVoltLowFault_flg;
  boolean_T VDHP_AccPdlHVoltHighInstFlt_flg;
  boolean_T VDHP_AccPdlHVoltHighFault_flg;
  boolean_T VDHP_AccelPdlRatInstFlt_flg;
  boolean_T VDHP_AccelPdlRatFault_flg;
  boolean_T VDHP_AccPdlSenRefVoltHighInstFlt_flg;
  boolean_T VDHP_AccPdlSenRefVoltHighFault_flg;
  boolean_T VDHP_AccPdlSenRefVoltLowInstFlt_flg;
  boolean_T VDHP_AccPdlSenRefVoltLowFault_flg;
  boolean_T VDHP_AuxBattVoltHighInstWarm_flg;
  boolean_T VDHP_AuxBattVoltHighWarnFault_flg;
  boolean_T VDHP_AuxBattVoltLowInstWarm_flg;
  boolean_T VDHP_AuxBattVoltLowWarnFault_flg;
  boolean_T VDHP_AuxBattVoltHighFltFault_flg;
  boolean_T VDHP_AuxBattVoltLowFltFault_flg;
  boolean_T VDHP_VCUtoBMSLossCanNetFault_flg;
  boolean_T VDHP_VCUtoMCULossCanNetFault_flg;
  boolean_T VDHP_VCUtoDCDCLossCanNetFault_flg;
  boolean_T VDHP_WaterPumpFault_flg;
  boolean_T VDHP_SRSFault_flg;
  boolean_T VDHP_CoolingSysFault_Flg;
  boolean_T VDHP_MCUOverSpdFault_Flg;
  boolean_T VDHP_MCUSysOverTFault_Flg;
  boolean_T VDHP_MCUFltExitReady_Flg;
  boolean_T VDHP_Forbid_FeedbackFlg;
  boolean_T VDHP_Forbid_CreepFlg;
  boolean_T VDHP_Forbid_CruiseFlg;
  boolean_T VDHP_VCUtoABSLossCanNetFlt_flg;
  boolean_T VDHP_BrakeFault_Flg;
  boolean_T VDHP_VCUtoOBCLossCanNetFault_flg;
  boolean_T VDHP_AccelPdlRatDeathInstFlt_flg;
  boolean_T VDHP_AccelPdlRatDeathFault_flg;
  boolean_T VDHP_VCUBattChrgErr_Flg;
  boolean_T VDHP_MCUFaultSpeedBased_Flg;
  boolean_T VDHP_BMSFaultSpeedBased_Flg;
  boolean_T VDHP_BMSFaultTimeBased_Flg;
  boolean_T VDHP_CruiseHWFault_Flg;
  boolean_T VDHP_VCUtoABS232LossCanNetFault_flg;
  boolean_T VDHP_VCUtoICM235LossCanNetFault_flg;
  boolean_T VDHP_VehFaultLight_flg;
  boolean_T VDHP_CalDataCorrupted_flg;
  boolean_T VDHP_VCUFaultSpeedBased_Flg;
  boolean_T VDHP_PwrLimitLight_flg;
  boolean_T VDHP_PwrLimitbyBMS_flg;
} DHP;

#endif

#ifndef DEFINED_TYPEDEF_FOR_PMM_
#define DEFINED_TYPEDEF_FOR_PMM_

typedef struct {
  uint8_T VPMM_SystemState_enum;
  uint8_T VPMM_BMSOperModeReq_enum;
  uint8_T VPMM_MotStsModReq_enum;
  boolean_T VPMM_InternalSleepActive_flg;
  boolean_T VPMM_MCURelayActive_flg;
  boolean_T VPMM_PTReady_flg;
  boolean_T VPMM_HVReady_flg;
  boolean_T VPMM_HVPowerDownReq_flg;
  boolean_T VPMM_MainRelayActive_flg;
  uint8_T VPMM_VehSts_enum;
  boolean_T VPMM_LVUpBMSPwrUpAllwTimeout_flg;
  boolean_T VPMM_LVUpBMSTimeout_flg;
  boolean_T VPMM_LVUpDCDCTimeout_flg;
  boolean_T VPMM_LVUpMCUTimeout_flg;
  boolean_T VPMM_LVUpTimeout_flg;
  boolean_T VPMM_HVUpTimeout_flg;
  boolean_T VPMM_HVActiveTimeout_flg;
  boolean_T VPMM_HVStopWorkTimeout_flg;
  boolean_T VPMM_HVDownTimeout_flg;
  boolean_T VPMM_MCUDischargeTimeout_flg;
  boolean_T VPMM_HVDCDCActiveTimeout_flg;
  boolean_T VPMM_MCUHVActiveTimeout_flg;
  boolean_T VPMM_HVActiveChrgModeInvalid_flg;
  boolean_T VPMM_LVEna;
  boolean_T VPMM_LVComplete_flg;
  boolean_T VPMM_UpToHVMode_flg;
  boolean_T VPMM_RemoteHVACStop;
  uint8_T VPMM_IChrgSts;
  boolean_T VPMM_MCUModError;
  boolean_T VPMM_BMSModError;
  boolean_T VPMM_DCDCModError;
  uint8_T WakeSrcValid;
  boolean_T VPMM_MCUExitTqlTimeout_flg;
  boolean_T VPMM_DCDCStopworkTimeout_flg;
} PMM;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Config_
#define DEFINED_TYPEDEF_FOR_Config_

typedef struct {
  uint8_T C_ABS_ESP_En;
  uint8_T C_PB_En;
  uint8_T C_CS_En;
  uint8_T C_EPS_En;
  uint8_T C_AEB_En;
  uint8_T C_VSP_En;
  uint8_T C_ECC_En;
  uint8_T C_EHU_En;
  uint8_T C_ICM_En;
  uint8_T C_EAC_En;
  uint8_T C_PTC_En;
  uint8_T C_BCM_En;
  uint8_T C_SRS_En;
  uint8_T C_PEPS_En;
  uint8_T C_GW_En;
  boolean_T CS_OBCChrgLock;
  boolean_T C_TMS_En;
  boolean_T C_TMS_Internal;
  boolean_T C_WPTC_En;
  boolean_T C_MCURelayOff_En;
  uint8_T C_CC_En;
  uint8_T C_AS_En;
  uint8_T C_DVM_En;
  uint8_T C_Booster_En;
  uint8_T C_VacuumPump_En;
  uint8_T C_EVCCPlugLock_En;
  boolean_T C_YK19_En;
  boolean_T C_ECC_Internal;
  boolean_T C_HDC_En;
  uint8_T C_PMS_En;
  uint8_T C_ESCL_En;
  uint8_T C_PMSC_En;
  uint8_T C_CRG_En;
  uint8_T C_VSL_En;
} Config;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Hardwire_
#define DEFINED_TYPEDEF_FOR_Hardwire_

typedef struct {
  uint8_T VINP_GearOut_enum;
  boolean_T VINP_GearOutValid_flg;
  boolean_T VINP_ShiftPosnHold_flg;
  uint8_T VINP_DriveMode;
  real32_T VINP_AccelPedal_per;
  boolean_T VINP_AccelPedalValid_flg;
  boolean_T VINP_BrkLightSwitchActive_flg;
  boolean_T VINP_BrkPdlPosnValid_flg;
  boolean_T VINP_IgnitionOn_flg;
  boolean_T VINP_CrankActive_flg;
  boolean_T VINP_CollisionSwitchActive_flg;
  real32_T VINP_FastChargeTemp1_C;
  boolean_T VINP_FastChargeTemp1Valid_flg;
  real32_T VINP_FastChargeTemp2_C;
  boolean_T VINP_FastChargeTemp2Valid_flg;
  real32_T VINP_Sensor5V1_V;
  boolean_T VINP_Sensor5V1Valid_flg;
  real32_T VINP_Sensor5V2_V;
  boolean_T VINP_Sensor5V2Valid_flg;
  real32_T VINP_LVBattVoltage_V;
  boolean_T VINP_LVBattVoltageValid_flg;
  real32_T VINP_LVK15Voltage_V;
  boolean_T VINP_LVK15VoltageValid_flg;
  real32_T VINP_PCBTemp_C;
  boolean_T VINP_PCBTempValid_flg;
  boolean_T VINP_ACSwitchActive_flg;
  boolean_T VINP_SlowChargeAwakeActive_flg;
  boolean_T VINP_FastChargeAwakeActiveIn_flg;
  boolean_T VINP_FastChrgCANAwakeActiveIn_flg;
  boolean_T VINP_HVInterlockActiveIn_flg;
  boolean_T VINP_PTCSwitchActiveIn_flg;
  uint8_T VINP_WaterPwmIn_Duty;
  boolean_T VINP_WaterPwmIn_DutyValid_flg;
  uint16_T VINP_WaterPwmIn_Hz;
  boolean_T VINP_WaterPwmIn_HzValid_flg;
  real32_T VINP_Batt_InWater_T;
  real32_T VINP_Batt_OutWater_T;
  int16_T VINP_BatInWaterT_deg;
  int16_T VINP_PTSensorT_deg;
  uint16_T VINP_PTSensorP_kPa;
  boolean_T VINP_ClutchSwitchActive_flg;
  boolean_T VINP_SSB_Switch1;
  boolean_T VINP_SSB_Switch2;
  boolean_T VINP_PTCLowReqIn_flg;
  boolean_T VINP_PTCHighReqIn_flg;
  boolean_T VINP_DefrostActiveIn_flg;
  boolean_T VINP_EACReqIn_flg;
  real32_T VINP_IGN1_Out_v;
  real32_T VINP_IGN2_Out_v;
} Hardwire;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BMS_
#define DEFINED_TYPEDEF_FOR_BMS_

typedef struct {
  real32_T VINP_BMSBattU_V;
  real32_T VINP_BMSBattI_A;
  real32_T VINP_BMSSOC_per;
  uint8_T VINP_BMSFltRnk_enum;
  uint8_T VINP_BMSOperMod_enum;
  uint16_T VINP_BMSOBCOperModReq_enum;
  boolean_T VINP_BMSPwrUpAllw_flg;
  boolean_T VINP_BMSHVILSts_flg;
  boolean_T VINP_BMSCrashSts_flg;
  boolean_T VINP_BMSRlyWiddErr_flg;
  boolean_T VINP_BMSInsulationSts_flg;
  boolean_T VINP_BMSInsulationIntrErr_flg;
  boolean_T VINP_BMSInsulationHVLoadErr_flg;
  uint8_T VINP_BMS113CycCntr;
  uint8_T VINP_BMSCRCChk113;
  uint16_T VINP_BMSMaxChrgU;
  uint16_T VINP_BMSMinDchaIU;
  real32_T VINP_BMSBattExU;
  uint8_T VINP_BMS213CycCntr;
  uint8_T VINP_BMSCRCChk213;
  real32_T VINP_BMSMaxDchaPwr_kW;
  real32_T VINP_BMSMaxChrgPwr_kW;
  uint16_T VINP_BMSMaxDchaI;
  uint16_T VINP_BMSMaxChrgI;
  uint8_T VINP_BMS233CycCntr;
  uint8_T VINP_BMSCRCChk233;
  real32_T VINP_BMSChrgUReq;
  real32_T VINP_BMSChrgIReq;
  real32_T VINP_BMSOBCMaxChrgPwrAvl;
  boolean_T VINP_BMSOBCHeatModeCtrl_flg;
  uint8_T VINP_BMSChrgMod_enum;
  uint8_T VINP_BMSChrgErrInfo_enum;
  uint8_T VINP_BMSChrgSts_enum;
  boolean_T VINP_BMSDCChrgRlySts_flg;
  uint8_T VINP_BMS303CycCntr;
  uint8_T VINP_BMSCRCChk303;
  int16_T VINP_BMSMaxBattT;
  int16_T VINP_BMSMinBattT;
  int16_T VINP_BMSPredChrgTi;
  uint8_T VINP_BMSBattIntrHeatReq;
  uint8_T VINP_BMSBattIntrHeatActv;
  uint16_T VINP_BMSIsolationR_kR;
  real32_T VINP_BMSAvrgBattT_C;
  boolean_T VINP_BMSMILReq;
  uint8_T VINP_BMS313CycCntr;
  uint8_T VINP_BMSCRCChk313;
  uint8_T VINP_BMSSOCMax;
  uint8_T VINP_BMSSOCMin;
  real32_T VINP_BMSSOH_per;
  real32_T VINP_BMSRmaingCpby_kWh;
  boolean_T VINP_BMSEquilnSts;
  uint16_T VINP_BMSCC2SngR_R;
  real32_T VINP_BMSBattHeatI;
  uint8_T VINP_BMSErrAmnt;
  uint16_T VINP_BMSErrNum;
  uint16_T VINP_BMSCCSngR;
  real32_T VINP_BMSCellUMin;
  uint8_T VINP_BMSCellUMinCellNum;
  uint8_T VINP_BMSCellUMinBattNum;
  real32_T VINP_BMSCellUMax;
  uint8_T VINP_BMSCellUMaxCellNum;
  uint8_T VINP_BMSCellUMaxBattNum;
  uint8_T VINP_BMSBattNumTot;
  uint8_T VINP_BMSCellNumTot;
  real32_T VINP_BMSBattResidPwr;
  boolean_T VINP_BMSDateMonitoringReq;
  uint8_T VINP_BMSDateMonitoringt;
  boolean_T VINP_TMS_StateOverT;
  boolean_T VINP_TMS_COOLErr;
  uint8_T VINP_BMSBattTherMagReq;
  real32_T VINP_BMSBattTherTargetFlow;
  int8_T VINP_BMSBattTherTargetT;
  uint32_T VINP_BMSBattRatedPwr;
  real32_T VINP_BMSCellUMinUnderU;
  real32_T VINP_BMSBattUOverU;
  real32_T VINP_BMSBattUUnderU;
  real32_T VINP_BMSCellUMaxOverU;
  int16_T VINP_BMSMaxBattTOverT;
  boolean_T VINP_BMSBattTherMagErr;
  real32_T VINP_ChrgSysMaxPwrSup;
  uint8_T VVINP_BMSS2Stus;
  uint8_T VINP_BMSPlugLockStatus;
  uint16_T VINP_BMSPPSngR;
  uint8_T VINP_BMSCPSts;
  uint8_T VINP_BMSCPValue;
  boolean_T VINP_BMSIChrgEna;
  uint16_T VINP_ChrgPilePwrAvail;
} BMS;

#endif

#ifndef DEFINED_TYPEDEF_FOR_MCU_
#define DEFINED_TYPEDEF_FOR_MCU_

typedef struct {
  int16_T VINP_MCUElecMotSpd_rpm;
  boolean_T VINP_MCUElecMotSpdValid_flg;
  real32_T VINP_MotTqReal_Nm;
  boolean_T VINP_MotTqRealValid_flg;
  uint8_T VINP_MCUOperMdl_enum;
  real32_T VINP_MCUMaxAvlTq_Nm;
  real32_T VINP_MCUMinAvlTq_Nm;
  uint8_T VINP_MCUID153CycCntr;
  real32_T VINP_MCUDcU_V;
  real32_T VINP_MCUDcCrrt_A;
  int16_T VINP_MCUPhaCrrt_A;
  uint8_T VINP_MCUFltRnk_enum;
  real32_T VINP_MCUElecMotT_C;
  boolean_T VINP_MCUMotNumTot;
  boolean_T VINP_MCUMotNum;
  real32_T VINP_MCUIGBTT_C;
  real32_T VINP_MCUT_C;
  uint8_T VINP_MCUErrAmnt;
  uint8_T VINP_MCUErrNum;
  uint8_T VINP_MCUMotSts_enum;
  uint8_T VINP_Hardware_Ver;
  uint8_T VINP_Motor_Ver;
  uint8_T VINP_Software_Ver;
  boolean_T VINP_MCUPwrModErr_flg;
  boolean_T VINP_MCUOverTErr_flg;
  boolean_T VINP_MCUDcUOverUErr_flg;
  boolean_T VINP_MCUDcUUnderUErr_flg;
  boolean_T VINP_MCULowBatUnderUErr_flg;
  boolean_T VINP_MCUElecMotOverCrrtErr_flg;
  boolean_T VINP_MCUDCUShoCirc_flg;
  boolean_T VINP_MCUIGBTOverTErr_flg;
  boolean_T VINP_MCUElecMotOverTErr_flg;
  boolean_T VINP_MCUElecMotUnderTErr_flg;
  boolean_T VINP_MCUCANComErr_flg;
  boolean_T VINP_MCUDischrgErr_flg;
  boolean_T VINP_MCUPrechrgErr_flg;
  boolean_T VINP_MCUElecMotReslvErr_flg;
  boolean_T VINP_MCUElecMotStopTurnErr_flg;
  boolean_T VINP_MCUElecMotTqErr_flg;
  boolean_T VINP_MCUSystemErr_flg;
  boolean_T VINP_MCUDcUSnsrRatiErr_flg;
  boolean_T VINP_MCUTSnsrRatiErr_flg;
  boolean_T VINP_MCUIGBTTSnsrRatiErr_flg;
  boolean_T VINP_MCUElecMotTSnsrRatiErr_flg;
  boolean_T VINP_MCUDcCrrtSnsrRatiErr_flg;
  boolean_T VINP_MCUPhaACrrtSnsrRatiErr_flg;
  boolean_T VINP_MCUPhaCCrrtSnsrRatiErr_flg;
  boolean_T VINP_VMSENErr_flg;
  boolean_T VINP_MCUHVLockErr_flg;
  boolean_T VINP_MCUPwrModUnderUErr_flg;
  boolean_T VINP_MCU131CRCErr_flg;
  boolean_T VINP_MCUCRCElecMotSpdErr_flg;
  boolean_T VINP_MCUCRCRealTqErr_flg;
  boolean_T VINP_MCUPhaBCrrtSnsrRatiErr;
  boolean_T VINP_MCUUndefineErr2;
  boolean_T VINP_MCUUndefineErr3;
  uint8_T VINP_MCUElecMotOverSpdErr_flg;
  boolean_T MCUHWCurrOverErr;
  boolean_T VINP_MCUMotopenphaseErr;
  boolean_T VINP_BMSBattTherMagErr;
} MCU;

#endif

#ifndef DEFINED_TYPEDEF_FOR_OBC_
#define DEFINED_TYPEDEF_FOR_OBC_

typedef struct {
  real32_T VINP_OBCMaxChrgOutpUAvl;
  real32_T VINP_OBCMaxChrgOutpIAvl;
  uint16_T VINP_OBCMaxChrgOutpPwrAvl;
  int16_T VINP_OBCVehInletT_C;
  uint8_T VINP_OBCChrgSts;
  uint8_T VINP_PlugLockStatus_enum;
  uint8_T VINP_OBCS2Stus;
  uint8_T VINP_OBC311CycCntr;
  uint8_T VINP_OBCFltRnk_enum;
  uint8_T VINP_OBCCPValue;
  uint8_T VINP_CPSts;
  uint8_T VINP_OBC321CycCntr;
  uint16_T VINP_OBCChrgInpAcU;
  real32_T VINP_OBCChrgInpAcI;
  real32_T VINP_OBCChrgDcU_A;
  real32_T VINP_OBCChrgDcI_A;
  int16_T VINP_OBCT_C;
  boolean_T VINP_OBCCANErr;
  boolean_T VINP_OBCHwErr;
  boolean_T VINP_OBCInpUOver;
  boolean_T VINP_OBCOutpUOver;
  boolean_T VINP_OBCInpUUnder;
  boolean_T VINP_OBCOutpUUnder;
  boolean_T VINP_OBCInpIOver;
  boolean_T VINP_OBCOutpIOver;
  boolean_T VINP_OBCTOvrErr;
  uint8_T VINP_OBC331CycCntr;
  uint16_T VINP_OBCCCSngR;
} OBC;

#endif

#ifndef DEFINED_TYPEDEF_FOR_DCDC_
#define DEFINED_TYPEDEF_FOR_DCDC_

typedef struct {
  real32_T VINP_DCDCInpU_V;
  real32_T VINP_DCDCOutpU_V;
  real32_T VINP_DCDCOutpCrrt_A;
  int16_T VINP_DCDCAvlOutpPwr_W;
  boolean_T VINP_DCDCHwFltFlg_flg;
  boolean_T VINP_DCDCErrCANCom_flg;
  boolean_T VINP_DCDCOverInpU_flg;
  boolean_T VINP_DCDCUnderInpU_flg;
  boolean_T VINP_DCDCOverOutpU_flg;
  boolean_T VINP_DCDCUnderOutpU_flg;
  boolean_T VINP_DCDCOverOutpCrrt_flg;
  boolean_T VINP_DCDCOverOutpPwr_flg;
  boolean_T VINP_DCDCOverT_flg;
  boolean_T VINP_DCDCShoCircOutp_flg;
  uint8_T VINP_DCDCOperMod_enum;
  real32_T VINP_DCDCT_C;
  real32_T VINP_DCDCIInput_A;
  uint8_T VINP_DCDCFltRnk_enum;
} DCDC;

#endif

#ifndef DEFINED_TYPEDEF_FOR_CANOther_
#define DEFINED_TYPEDEF_FOR_CANOther_

typedef struct {
  boolean_T VINP_HandBrake_flg;
  real32_T VINP_VehicleSpeed_kmph;
} CANOther;

#endif

#ifndef DEFINED_TYPEDEF_FOR_PTC_
#define DEFINED_TYPEDEF_FOR_PTC_

typedef struct {
  boolean_T VINP_PTC_State;
  int16_T VINP_PTC_Temperature;
  uint16_T VINP_PTC_Power;
  uint16_T VINP_PTC_InVoltage;
  boolean_T VINP_PTC_HVUnderfault;
  boolean_T VINP_PTC_HVOverfault;
  boolean_T VINP_PTC_HVOFFfault;
  boolean_T VINP_PTC_OverCurrfault;
  boolean_T VINP_PTC_IGBTErr;
  boolean_T VINP_PTC_IGBTTSnsrErr;
  boolean_T VINP_PTC_IGBTOverTErr;
  boolean_T VINP_PTC_TempSnsrErr;
  boolean_T VINP_PTC_TempOverTErr;
  int16_T VINP_PTCIGBTT;
} PTC;

#endif

#ifndef DEFINED_TYPEDEF_FOR_ECC_
#define DEFINED_TYPEDEF_FOR_ECC_

typedef struct {
  uint16_T VINP_AC_ActSpeed;
  boolean_T VINP_AC_Command;
  boolean_T VINP_ECC_A_C_Req;
  boolean_T VINP_ECC_A_C_ReqValid_flg;
  uint16_T VINP_AC_SpeedSet;
  uint16_T VINP_AC_AcceptPower;
  uint8_T VINP_AC_Counter;
  uint8_T VINP_AC_Checksum;
  uint16_T VINP_PTCActPower;
  boolean_T VINP_PTCCommand;
  boolean_T VINP_ECC_PTC_Req;
  boolean_T VINP_ECC_PTC_ReqValid_flg;
  uint16_T VINP_PTCTargetPwr;
  uint8_T VINP_PTCCounter;
  uint8_T VINP_PTCChecksum;
  uint8_T VINP_ECC_AutoReq;
  uint8_T VINP_ECC_Blowing;
  real32_T VINP_ECC_EnvironmentalTemp;
  real32_T VINP_ECC_EvaporatorTemp;
  real32_T VINP_ECC_InterCarTemp;
  uint8_T VINP_ECC_Mode;
  uint8_T VINP_ECC_PM2_5;
  uint8_T VINP_ECC_Rec_FreSetState;
  real32_T VINP_ECC_Sunlight;
  real32_T VINP_ECC_TempSetReq;
  uint8_T VINP_FrontDefrosterSwitch;
  uint8_T VINP_RearDefrosterSwitch;
  uint16_T VINP_PTC_MAXPower;
  uint16_T VINP_AC_MAXPower;
  uint8_T VINP_ECC_RemoteACStatus;
  uint16_T VINP_AC_TargetPower;
  real32_T VINP_PTCRecTemp;
  uint16_T VINP_ECC_PTCTargetPwrReq;
  uint16_T VINP_ECC_ACTargetPwrReq;
} ECC;

#endif

#ifndef DEFINED_TYPEDEF_FOR_PEPS_
#define DEFINED_TYPEDEF_FOR_PEPS_

typedef struct {
  uint8_T VINP_PEPS_EncryptedStatus;
  uint8_T VINP_PEPS_EncryptedResponseByte5;
  uint8_T VINP_PEPS_EncryptedResponseByte4;
  uint8_T VINP_PEPS_EncryptedResponseByte3;
  uint8_T VINP_PEPS_EncryptedResponseByte2;
  uint8_T VINP_PEPS_EncryptedResponseByte1;
  uint8_T VINP_PEPS_EncryptedResponseByte0;
  uint32_T VINP_PEPS108Rcv_cnt;
  uint8_T VINP_PEPS_ReAuth_Req;
  uint32_T VINP_PEPS103Rcv_cnt;
  uint8_T VINP_PEPS_PDU;
  uint8_T VINP_PEPS_RkeCmd;
} PEPS;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SRS_
#define DEFINED_TYPEDEF_FOR_SRS_

typedef struct {
  uint8_T VINP_SRS_CrashOutputStatusCheckSum;
  uint8_T VINP_SRS_CrashOutputStatus;
  uint8_T VINP_SRS_WarningLampStatus;
  uint8_T VINP_SRS_PassengerBuckleSwitchStatus;
  uint8_T VINP_SRS_DriverBuckleSwitchStatus;
  boolean_T VINP_SRS_FrontPsgOccupancy;
  uint8_T VINP_SRS_RollingCounter;
} SRS;

#endif

#ifndef DEFINED_TYPEDEF_FOR_ABS_
#define DEFINED_TYPEDEF_FOR_ABS_

typedef struct {
  boolean_T VINP_NO_Evflag;
  boolean_T VINP_ABS_EbdFlgFlt;
  boolean_T VINP_ABS_AbsFlgFlt;
  boolean_T VINP_ABS_AbsCtrlActv;
  real32_T VINP_ABS_VehicleSpeed;
  boolean_T VINP_ABS_VehicleSpeedValid_flg;
  int16_T VINP_WheelSpeedPlusCounter_FL;
  boolean_T VINP_WheelSpeedPlusCounter_FLValid_flg;
  int16_T VINP_WheelSpeedPlusCounter_FR;
  boolean_T VINP_WheelSpeedPlusCounter_FRValid_flg;
  int16_T VINP_WheelSpeedPlusCounter_RL;
  boolean_T VINP_WheelSpeedPlusCounter_RLValid_flg;
  int16_T VINP_WheelSpeedPlusCounter_RR;
  boolean_T VINP_WheelSpeedPlusCounter_RRValid_flg;
  uint8_T VINP_ABS_Checksum;
  uint8_T VINP_ABS_RollingCounter;
  uint8_T VINP_ABS_Checksum237;
  uint8_T VINP_ABS_RollingCounter237;
  boolean_T VINP_ESP_TCSActiveStatus;
  boolean_T VINP_ESP_ESPSwitchStatus;
  boolean_T VINP_ESP_ESPActiveStatus;
  boolean_T VINP_ESP_ESPFailStatus;
  real32_T VINP_ESC_MotorTorq_Req;
  uint8_T VINP_ESC_MotorWork_Req;
  boolean_T VINP_ESP_HHCActiveStatus;
  boolean_T VINP_ESP_EBDActiveStatus;
  boolean_T VINP_ESP_HBAActiveStatus;
  boolean_T VINP_ABS_FLWheelSpeedValid;
  real32_T VINP_ABS_FLWheelSpeed;
  boolean_T VINP_ABS_FRWheelSpeedValid;
  real32_T VINP_ABS_FRWheelSpeed;
  boolean_T VINP_ABS_RLWheelSpeedValid;
  real32_T VINP_ABS_RLWheelSpeed;
  boolean_T VINP_ABS_RRWheelSpeedValid;
  real32_T VINP_ABS_RRWheelSpeed;
} ABS;

#endif

#ifndef DEFINED_TYPEDEF_FOR_EHU_
#define DEFINED_TYPEDEF_FOR_EHU_

typedef struct {
  uint32_T VINP_ClstrOdo;
  uint8_T VINP_EHU_EnergyRecovery;
  uint8_T VINP_EHU_DriverModel;
  uint8_T VINP_EHU_VoiceIdentify;
  uint8_T VINP_SubtotalEgyCnseRet;
  boolean_T VINP_EHUVehrpValid;
  uint8_T VINP_BCM_RearDefrosterstatus;
  uint8_T VINP_EHU_VSPSwitchSet;
  uint8_T VINP_EHU_DriveHeatAllow;
} EHU;

#endif

#ifndef DEFINED_TYPEDEF_FOR_EPB_
#define DEFINED_TYPEDEF_FOR_EPB_

typedef struct {
  uint8_T VINP_EPB_Status;
  boolean_T VINP_EPB_Brake_Lights_Requested;
  boolean_T VINP_EPS_TorqSensorStatus;
  boolean_T VINP_EPS_EpasFailed;
  real32_T VINP_EPB_Acceleration_X;
  real32_T VINP_SAS_SteeringAngle;
  real32_T VINP_SAS_SteeringAngleSpeed;
} EPB;

#endif

#ifndef DEFINED_TYPEDEF_FOR_TPMS_
#define DEFINED_TYPEDEF_FOR_TPMS_

typedef struct {
  uint8_T VINP_FLPressureWarning;
  uint8_T VINP_FLTempHigh;
  uint16_T VINP_FLTirePres;
  uint8_T VINP_FRPressureWarning;
  uint8_T VINP_FRTempHigh;
  uint16_T VINP_FRTirePres;
  uint8_T VINP_RLPressureWarning;
  uint8_T VINP_RLTempHigh;
  uint16_T VINP_RLTirePres;
  uint8_T VINP_RRPressureWarning;
  uint8_T VINP_RRTempHigh;
  uint16_T VINP_RRTirePres;
  uint8_T VINP_StudyFailureWarning;
  uint8_T VINP_StudyMode;
  uint8_T VINP_SystemWarning;
  uint8_T VINP_TPMSLearnIdStatus;
  int8_T VINP_FLTireTemp;
  int8_T VINP_FRTireTemp;
  int8_T VINP_RLTireTemp;
  int8_T VINP_RRTireTemp;
} TPMS;

#endif

#ifndef DEFINED_TYPEDEF_FOR_EAC_
#define DEFINED_TYPEDEF_FOR_EAC_

typedef struct {
  real32_T VINP_COMPCurr;
  uint16_T VINP_COMPVold;
  uint16_T VINP_COMPSpeed_now;
  int8_T VINP_COMPMotor_Temp;
  uint8_T VINP_Bus_cur_ERR;
  uint8_T VINP_Bus_limit;
  uint8_T VINP_CAN_ERR;
  uint8_T VINP_COMPBaseState;
  uint8_T VINP_HVolt_ERR;
  uint8_T VINP_LVolt_ERR;
  uint8_T VINP_Pow_limit;
  uint8_T VINP_Start_ERR;
  uint16_T VINP_EAC_RealSpeed;
  uint16_T VINP_EAC_PowerConsumption;
  uint16_T VINP_EAC_BusbarVoltage;
  real32_T VINP_EAC_BusbarCurrent;
  real32_T VINP_EAC_PeakPhaCurrent;
  int16_T VINP_EAC_IGBTTemp;
  uint8_T VINP_EAC_CurrentState;
  boolean_T VINP_EAC_SampleCircMalfct;
  boolean_T VINP_EAC_LackPhase;
  boolean_T VINP_EAC_IGBTMalfct;
  boolean_T VINP_EAC_TempSensorFault;
  boolean_T VINP_EAC_OverCurrent;
  boolean_T VINP_EAC_StallFault;
  boolean_T VINP_EAC_OverHeatFault;
  boolean_T VINP_EAC_RotateSpdAnomaly;
  boolean_T VINP_EAC_OverPhaVoltMalfct;
  boolean_T VINP_EAC_Overload;
  boolean_T VINP_EAC_OverHighVolt;
  boolean_T VINP_EAC_UnderHighVolt;
  boolean_T VINP_EAC_TTLfault;
} EAC;

#endif

#ifndef DEFINED_TYPEDEF_FOR_TBOX_
#define DEFINED_TYPEDEF_FOR_TBOX_

typedef struct {
  uint8_T VINP_TBOX_TimeValid;
  uint16_T VINP_TBOX_TimeYear;
  uint8_T VINP_TBOX_TimeMonth;
  uint8_T VINP_TBOX_TimeDate;
  uint8_T VINP_TBOX_TimeHour;
  uint8_T VINP_TBOX_TimeMinute;
  uint8_T VINP_TBOX_TimeSecond;
  boolean_T VINP_TBOX_RemoteHVACReq;
  boolean_T VINP_TBOX_RemoteWorkReq;
  boolean_T VINP_IChrgWakeUpReq;
  uint8_T VINP_TBOX_LockCommand;
} TBOX;

#endif

#ifndef DEFINED_TYPEDEF_FOR_TMS_
#define DEFINED_TYPEDEF_FOR_TMS_

typedef struct {
  uint16_T VINP_TMS_PoweDesired_WPTC;
  uint8_T VINP_TMS_AC_SwtSts;
  boolean_T VINP_TMS_AC_ReqValid;
  uint16_T VINP_TMS_AC_TargetPwr;
  boolean_T VINP_TMS_PTCSwtSts;
  boolean_T VINP_TMS_PTC_ReqValid;
  uint16_T VINP_TMS_PTCTargetPwr;
  boolean_T VINP_TMS_WPTC_Req;
  boolean_T VINP_TMS_WPTC_ReqValid;
  uint16_T VINP_TMS_WPTCTargetPwr;
  boolean_T VINP_TMS_AC_Command;
  uint16_T VINP_TMS_AC_SpeedSet;
  uint16_T VINP_TMS_AC_Pow_limit;
  boolean_T VINP_TMS_PTC_Command;
  int16_T VINP_TMS_PTC_Target_T;
  uint16_T VINP_TMS_PTC_Pow_limit;
  uint16_T VINP_PTC_MAXPower;
  uint16_T VINP_AC_MAXPower;
  uint16_T VINP_WPTC_MAXPower;
  boolean_T VINP_TMS_Batt_GVSt;
  uint8_T VINP_TMS_Batt_EXVSt;
  boolean_T VINP_TMS_Cabin_GVSt;
  uint8_T VINP_TMS_Cabin_EXVSt;
  uint8_T VINP_TMS_Batt_WPFlow;
} TMS;

#endif

#ifndef DEFINED_TYPEDEF_FOR_WPTC_
#define DEFINED_TYPEDEF_FOR_WPTC_

typedef struct {
  uint16_T VINP_WPTC_CurrentPower;
  uint8_T VINP_WPTC_RunMode;
  boolean_T VINP_WPTC_State;
  int16_T VINP_WPTC_WaterTemp;
  uint16_T VINP_WPTC_Power;
  uint16_T VINP_WPTC_InVoltage;
  real32_T VINP_WPTC_BusbarCurrent;
  int16_T VINP_WPTC_IGBTTemp;
  boolean_T VINP_WPTC_OverHV;
  boolean_T VINP_WPTC_UnderHV;
  boolean_T VINP_WPTC_OverLV;
  boolean_T VINP_WPTC_UnderLV;
  boolean_T VINP_WPTC_OverCurrent;
  boolean_T VINP_WPTC_WaterOverHeat;
  boolean_T VINP_WPTC_IGBTOverHeat;
  boolean_T VINP_WPTC_IGBTDriverFlt;
  boolean_T VINP_WPTC_WaterTempSnsrFlt;
  boolean_T VINP_WPTC_IGBTTempSnsrFlt;
  boolean_T VINP_WPTC_HVCircCut;
  boolean_T VINP_WPTC_HVCircShort;
} WPTC;

#endif

#ifndef DEFINED_TYPEDEF_FOR_LIN_
#define DEFINED_TYPEDEF_FOR_LIN_

typedef struct {
  uint16_T VINP_EWP_ErrorCode;
  uint16_T VINP_EWP_CurrentSpeed;
  real32_T VINP_EWP_Volatge;
  int16_T VINP_EWP_Temperature;
  uint8_T VINP_EXV_ErrorCheck;
  uint8_T VINP_EXV_InitStatus;
  uint8_T VINP_EXV_RunStatus;
  uint8_T VINP_EXV_ErrorStatus;
  uint8_T VINP_EXV_VolatgeErrorStatus;
  uint8_T VINP_EXV_TemperatureErrorStatus;
  uint16_T VINP_EXV_Position;
} LIN;

#endif

#ifndef DEFINED_TYPEDEF_FOR_FCW_
#define DEFINED_TYPEDEF_FOR_FCW_

typedef struct {
  boolean_T VINP_LDW_Left_Detected;
  boolean_T VINP_LDW_Left_Departure;
  boolean_T VINP_LDW_Right_Detected;
  boolean_T VINP_LDW_Right_Departure;
  boolean_T VINP_LDW_Alarm_Off;
  uint8_T VINP_Ambient_Light;
  boolean_T VINP_Calibration_Board_Detected;
  real32_T VINP_LWheelLaneDistance;
  real32_T VINP_RWheelLaneDistance;
  real32_T VINP_FCW_TTC;
  boolean_T VINP_FCW_TTC_Valid_Flag;
  boolean_T VINP_Forward_Vehicle_Detected;
  boolean_T VINP_Forward_Collision_Warning;
  uint8_T VINP_Forward_Vehicle_Distance;
  boolean_T VINP_Pre_Collision_Warning;
  uint8_T VINP_System_Status;
  boolean_T VINP_LDWS_Running_Status;
  boolean_T VINP_FCWS_Running_Status;
  boolean_T VINP_PCWS_Running_Status;
  boolean_T VINP_CALIB_Running_Status;
  boolean_T VINP_System_Boot_Failed;
  boolean_T VINP_Camera_Error;
  boolean_T VINP_System_Halted_Error;
  boolean_T VINP_CAN_Receive_Error;
  boolean_T VINP_Need_Calibrate_Error;
} FCW;

#endif

#ifndef DEFINED_TYPEDEF_FOR_EPS_
#define DEFINED_TYPEDEF_FOR_EPS_

typedef struct {
  boolean_T VINP_SAS_SteeringAngleValid;
  boolean_T VINP_SAS_SASFailure;
  boolean_T VINP_SAS_Calibrated;
} EPS;

#endif

#ifndef DEFINED_TYPEDEF_FOR_XBS_
#define DEFINED_TYPEDEF_FOR_XBS_

typedef struct {
  int16_T VINP_BrakeSysRegTrqTrgt;
  boolean_T VINP_BrakeSysRegTrqTrgtValid;
  boolean_T VINP_BrakePedalApplied;
  boolean_T VINP_BrakePedalAppliedValid;
  uint8_T VINP_BrakePedalPosition;
  boolean_T VINP_BrakePedalPositionValid;
  boolean_T VINP_XBS_BLReq;
  uint8_T VINP_C_boosterFaultStatus;
} XBS;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BCM_
#define DEFINED_TYPEDEF_FOR_BCM_

typedef struct {
  uint8_T VINP_DrvrDoorSts;
  uint8_T VINP_FrtPsngDoorSts;
  uint8_T VINP_RLDoorSts;
  uint8_T VINP_RRDoorSts;
  uint8_T VINP_TailgateSts;
  uint8_T VINP_VehLckSts;
} BCM;

#endif

#ifndef DEFINED_TYPEDEF_FOR_ICM_
#define DEFINED_TYPEDEF_FOR_ICM_

typedef struct {
  real32_T VINP_ICM_VehicleSpeedDisplay;
  boolean_T VINP_ICM_VehicleSpeedDisplayValid_flg;
  boolean_T VINP_ICM_VehSpdChkInvalidFlt_flg;
} ICM;

#endif

#ifndef DEFINED_TYPEDEF_FOR_INP_
#define DEFINED_TYPEDEF_FOR_INP_

typedef struct {
  Hardwire Hardwire_signal;
  BMS CANBMS_signal;
  MCU CANMCU_signal;
  OBC CANOBC_signal;
  DCDC CANDCDC_signal;
  CANOther CANOther_signal;
  PTC PTC;
  ECC ECC;
  PEPS PEPS;
  SRS SRS;
  ABS ABS;
  EHU EHU;
  EPB EPB;
  TPMS TPMS;
  EAC EAC;
  TBOX TBOX;
  TMS TMS;
  WPTC WPTC;
  LIN LIN;
  FCW FCW;
  EPS EPS;
  XBS XBS;
  BCM BCM;
  ICM ICM;
} INP;

#endif
#endif                                 /* RTW_HEADER_DIM_model_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

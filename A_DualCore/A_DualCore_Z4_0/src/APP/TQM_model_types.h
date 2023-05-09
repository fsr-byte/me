/*
 * File: TQM_model_types.h
 *
 * Code generated for Simulink model 'TQM_model'.
 *
 * Model version                  : 1.3587
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Fri Mar 18 15:45:56 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Freescale->32-bit PowerPC
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. MISRA C:2012 guidelines
 * Validation result: Not run
 */

#ifndef RTW_HEADER_TQM_model_types_h_
#define RTW_HEADER_TQM_model_types_h_
#include "rtwtypes.h"
#ifndef SS_INT64
#define SS_INT64                       88
#endif

#ifndef SS_UINT64
#define SS_UINT64                      89
#endif

#ifndef DEFINED_TYPEDEF_FOR_Hardwire_
#define DEFINED_TYPEDEF_FOR_Hardwire_

typedef struct
{
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
}
Hardwire;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BMS_
#define DEFINED_TYPEDEF_FOR_BMS_

typedef struct
{
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
}
BMS;

#endif

#ifndef DEFINED_TYPEDEF_FOR_MCU_
#define DEFINED_TYPEDEF_FOR_MCU_

typedef struct
{
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
}
MCU;

#endif

#ifndef DEFINED_TYPEDEF_FOR_OBC_
#define DEFINED_TYPEDEF_FOR_OBC_

typedef struct
{
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
}
OBC;

#endif

#ifndef DEFINED_TYPEDEF_FOR_DCDC_
#define DEFINED_TYPEDEF_FOR_DCDC_

typedef struct
{
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
}
DCDC;

#endif

#ifndef DEFINED_TYPEDEF_FOR_CANOther_
#define DEFINED_TYPEDEF_FOR_CANOther_

typedef struct
{
    boolean_T VINP_HandBrake_flg;
    real32_T VINP_VehicleSpeed_kmph;
}
CANOther;

#endif

#ifndef DEFINED_TYPEDEF_FOR_PTC_
#define DEFINED_TYPEDEF_FOR_PTC_

typedef struct
{
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
}
PTC;

#endif

#ifndef DEFINED_TYPEDEF_FOR_ECC_
#define DEFINED_TYPEDEF_FOR_ECC_

typedef struct
{
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
}
ECC;

#endif

#ifndef DEFINED_TYPEDEF_FOR_PEPS_
#define DEFINED_TYPEDEF_FOR_PEPS_

typedef struct
{
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
}
PEPS;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SRS_
#define DEFINED_TYPEDEF_FOR_SRS_

typedef struct
{
    uint8_T VINP_SRS_CrashOutputStatusCheckSum;
    uint8_T VINP_SRS_CrashOutputStatus;
    uint8_T VINP_SRS_WarningLampStatus;
    uint8_T VINP_SRS_PassengerBuckleSwitchStatus;
    uint8_T VINP_SRS_DriverBuckleSwitchStatus;
    boolean_T VINP_SRS_FrontPsgOccupancy;
    uint8_T VINP_SRS_RollingCounter;
}
SRS;

#endif

#ifndef DEFINED_TYPEDEF_FOR_ABS_
#define DEFINED_TYPEDEF_FOR_ABS_

typedef struct
{
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
}
ABS;

#endif

#ifndef DEFINED_TYPEDEF_FOR_EHU_
#define DEFINED_TYPEDEF_FOR_EHU_

typedef struct
{
    uint32_T VINP_ClstrOdo;
    uint8_T VINP_EHU_EnergyRecovery;
    uint8_T VINP_EHU_DriverModel;
    uint8_T VINP_EHU_VoiceIdentify;
    uint8_T VINP_SubtotalEgyCnseRet;
    boolean_T VINP_EHUVehrpValid;
    uint8_T VINP_BCM_RearDefrosterstatus;
    uint8_T VINP_EHU_VSPSwitchSet;
    uint8_T VINP_EHU_DriveHeatAllow;
}
EHU;

#endif

#ifndef DEFINED_TYPEDEF_FOR_EPB_
#define DEFINED_TYPEDEF_FOR_EPB_

typedef struct
{
    uint8_T VINP_EPB_Status;
    boolean_T VINP_EPB_Brake_Lights_Requested;
    boolean_T VINP_EPS_TorqSensorStatus;
    boolean_T VINP_EPS_EpasFailed;
    real32_T VINP_EPB_Acceleration_X;
    real32_T VINP_SAS_SteeringAngle;
    real32_T VINP_SAS_SteeringAngleSpeed;
}
EPB;

#endif

#ifndef DEFINED_TYPEDEF_FOR_TPMS_
#define DEFINED_TYPEDEF_FOR_TPMS_

typedef struct
{
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
}
TPMS;

#endif

#ifndef DEFINED_TYPEDEF_FOR_EAC_
#define DEFINED_TYPEDEF_FOR_EAC_

typedef struct
{
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
}
EAC;

#endif

#ifndef DEFINED_TYPEDEF_FOR_TBOX_
#define DEFINED_TYPEDEF_FOR_TBOX_

typedef struct
{
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
}
TBOX;

#endif

#ifndef DEFINED_TYPEDEF_FOR_TMS_
#define DEFINED_TYPEDEF_FOR_TMS_

typedef struct
{
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
}
TMS;

#endif

#ifndef DEFINED_TYPEDEF_FOR_WPTC_
#define DEFINED_TYPEDEF_FOR_WPTC_

typedef struct
{
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
}
WPTC;

#endif

#ifndef DEFINED_TYPEDEF_FOR_LIN_
#define DEFINED_TYPEDEF_FOR_LIN_

typedef struct
{
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
}
LIN;

#endif

#ifndef DEFINED_TYPEDEF_FOR_FCW_
#define DEFINED_TYPEDEF_FOR_FCW_

typedef struct
{
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
}
FCW;

#endif

#ifndef DEFINED_TYPEDEF_FOR_EPS_
#define DEFINED_TYPEDEF_FOR_EPS_

typedef struct
{
    boolean_T VINP_SAS_SteeringAngleValid;
    boolean_T VINP_SAS_SASFailure;
    boolean_T VINP_SAS_Calibrated;
}
EPS;

#endif

#ifndef DEFINED_TYPEDEF_FOR_XBS_
#define DEFINED_TYPEDEF_FOR_XBS_

typedef struct
{
    int16_T VINP_BrakeSysRegTrqTrgt;
    boolean_T VINP_BrakeSysRegTrqTrgtValid;
    boolean_T VINP_BrakePedalApplied;
    boolean_T VINP_BrakePedalAppliedValid;
    uint8_T VINP_BrakePedalPosition;
    boolean_T VINP_BrakePedalPositionValid;
    boolean_T VINP_XBS_BLReq;
    uint8_T VINP_C_boosterFaultStatus;
}
XBS;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BCM_
#define DEFINED_TYPEDEF_FOR_BCM_

typedef struct
{
    uint8_T VINP_DrvrDoorSts;
    uint8_T VINP_FrtPsngDoorSts;
    uint8_T VINP_RLDoorSts;
    uint8_T VINP_RRDoorSts;
    uint8_T VINP_TailgateSts;
    uint8_T VINP_VehLckSts;
}
BCM;

#endif

#ifndef DEFINED_TYPEDEF_FOR_ICM_
#define DEFINED_TYPEDEF_FOR_ICM_

typedef struct
{
    real32_T VINP_ICM_VehicleSpeedDisplay;
    boolean_T VINP_ICM_VehicleSpeedDisplayValid_flg;
    boolean_T VINP_ICM_VehSpdChkInvalidFlt_flg;
}
ICM;

#endif

#ifndef DEFINED_TYPEDEF_FOR_INP_
#define DEFINED_TYPEDEF_FOR_INP_

typedef struct
{
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
}
INP;

#endif

#ifndef DEFINED_TYPEDEF_FOR_DHP_
#define DEFINED_TYPEDEF_FOR_DHP_

typedef struct
{
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
}
DHP;

#endif

#ifndef DEFINED_TYPEDEF_FOR_PMM_
#define DEFINED_TYPEDEF_FOR_PMM_

typedef struct
{
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
}
PMM;

#endif

#ifndef DEFINED_TYPEDEF_FOR_TMM_
#define DEFINED_TYPEDEF_FOR_TMM_

typedef struct
{
    boolean_T TMM_AfterRunComplete_flg;
    boolean_T TMM_WaterPumpEnReq_flg;
    uint8_T TMM_WPPWM_Duty_pct;
    boolean_T TMM_HSCoolFanEnReq_flg;
    boolean_T TMM_LSCoolFanEnReq_flg;
    uint8_T TMM_Motor_DischargePowerLimit_Pct;
    uint8_T TMM_Motor_RegenPowerLimit_Pct;
    uint8_T TMM_BattIntrHeatAllwd_enum;
    uint8_T TMM_VCUChrgReqLimFac_enum;
    uint8_T TMM_MCUInWaterT_C;
    uint8_T TMM_PDUInWaterT_C;
    uint8_T TMM_MoterInWaterT_C;
    boolean_T TMM_PTCEn_flg;
    boolean_T TMM_ACEn_flg;
    boolean_T TMM_WPTCEn_flg;
    uint16_T TMM_MaxPermPTCPwr_W;
    uint16_T TMM_MaxPermHVACPwr_W;
    uint16_T TMM_MaxPermWPTCPwr_W;
    uint16_T TMM_ECCNeedPwr;
    boolean_T TMM_ECC_ShutoffMessage;
    boolean_T TMM_TMS_AC_Command;
    uint16_T TMM_TMS_AC_SpeedSet;
    uint16_T TMM_TMS_AC_Pow_Limit;
    boolean_T TMM_TMS_PTC_Command;
    uint8_T TMM_TMS_PTC_Target_T;
    uint16_T TMM_TMS_PTC_Pow_Limit;
    boolean_T TMM_TMS_WPTC_Command;
    uint8_T TMM_TMS_WPTC_Target_T;
    uint16_T TMM_TMS_WPTC_Pow_Limit;
    boolean_T TMM_TMS_Batt_GVSt;
    uint16_T TMM_TMS_Batt_EXVSt_Step;
    boolean_T TMM_TMS_Batt_EXVSt_Init;
    boolean_T TMM_TMS_Cabin_GVSt;
    uint16_T TMM_TMS_Cabin_EXVSt_Step;
    boolean_T TMM_TMS_Cabin_EXVSt_Init;
    uint8_T TMM_TMS_Batt_WPFlow;
    uint8_T TMM_TMS_Batt_InWT;
    uint8_T TMM_TMS_Batt_OutWT;
    uint8_T TMM_TMS_TMS_State;
    boolean_T TMM_Cabin_UserOp_Req;
    boolean_T TMM_InvalidBattReq;
}
TMM;

#endif

#ifndef DEFINED_TYPEDEF_FOR_ENM_
#define DEFINED_TYPEDEF_FOR_ENM_

typedef struct
{
    real32_T ENM_Motor_FeedbackPowerLimit_kW;
    real32_T ENM_Motor_OutputPowerLimit_kW;
    boolean_T ENM_DCDCEnReq_flg;
    uint16_T ENM_VCUMaxPermDCDCPwr_W;
    real32_T ENM_VCUReqDCDCU_V;
    uint8_T ENM_SysSOC;
    boolean_T ENM_ChargingRemind_flg;
    boolean_T ENM_ForbidPwrOutput_flg;
    uint16_T ENM_ECC_PermPwr_W;
    uint32_T ENM_HVLoadPwrLimit_W;
    int16_T ENM_DCDC_Temp;
    real32_T ENM_VCUActHVPwrCnsExt;
    real32_T ENM_InstantEgyCnse;
    real32_T ENM_SubtotalEgyCnse;
    real32_T ENM_TotalEgyCnse;
    real32_T ENM_VehEgyCnseDrv;
    uint16_T ENM_CoolingSysPwr_KJ;
    uint16_T ENM_ResiMilg_km;
    boolean_T ENM_BMSMaxDchaPwrFlt_flg;
    uint8_T ENM_VCUPwrAvail_KW;
    boolean_T ENM_Batt_EnergyToolow;
    uint8_T ENM_VCUDrvgEff;
    uint8_T ENM_BMSMaxDchaPer;
}
ENM;

#endif

#ifndef DEFINED_TYPEDEF_FOR_CHRG_
#define DEFINED_TYPEDEF_FOR_CHRG_

typedef struct
{
    boolean_T VCHRG_ChrgOperStartReq_flg;
    boolean_T VCHRG_VCUChrgAllwd_flg;
    boolean_T VCHRG_OBCSleepReq_flg;
    boolean_T VCHRG_OBCWakeUpReq_flg;
    boolean_T VCHRG_ShiftKnobRemindReq_flg;
    boolean_T VCHRG_ChrgStsLampReq_flg;
    boolean_T VCHRG_EPBWakeupReq_flg;
    uint8_T VCHRG_ChrgProcOptState_enum;
    boolean_T VCHRG_OBCUnlockRemind_flg;
    boolean_T VCHRG_CHMASignalStsReq_flg;
    boolean_T VCHRG_ChrgPlugConnectLampReq_flg;
    boolean_T VCHRG_OBCWakeupTimeout_flg;
    boolean_T VCHRG_ShiftKnobCheckTimeout_flg;
    boolean_T VCHRG_ChrgModeInvalid_flg;
    boolean_T VCHRG_ChrgLockCheckTimeou_flg;
    boolean_T VCHRG_ChrgOperationTimeout_flg;
    boolean_T VCHRG_ChargerLockRemind_flg;
    uint8_T VCHRG_VehChrgSts_enum;
    boolean_T VCHRG_ChrgEnableSleep_flg;
    boolean_T VCHRG_ChrgModeCheck_flg;
    boolean_T VCHRG_ChrgStopAbnormal_flg;
    boolean_T VCHRG_ChrgEnd_flg;
    boolean_T VCHRG_ChrgModeCheckReq_flg;
    boolean_T VCHRG_ChrgCheck_flg;
    boolean_T VCHRG_ChrgStartTimeout_flg;
    boolean_T VCHRG_CutOffMCURelay_flg;
    boolean_T VCHRG_ChrgSuspend_flg;
    boolean_T VCHRG_KeepLVReq_flg;
}
CHRG;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Config_
#define DEFINED_TYPEDEF_FOR_Config_

typedef struct
{
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
}
Config;

#endif

#ifndef DEFINED_TYPEDEF_FOR_TQFRate_
#define DEFINED_TYPEDEF_FOR_TQFRate_

typedef struct
{
    uint8_T u1_M_TQFRate_DriveTqIncRat_Nmps;
    uint8_T u1_M_TQFRate_DriveTqDecRat_Nmps;
    uint8_T u1_M_TQFRate_RegenTqIncRat_Nmps;
    uint8_T u1_M_TQFRate_RegenTqDecRat_Nmps;
}
TQFRate;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SPDCtl_
#define DEFINED_TYPEDEF_FOR_SPDCtl_

typedef struct
{
    uint8_T u1_M_SPDCtl_CRUISECtrlErr_enum;
    uint8_T u1_M_SPDCtl_CruiseIcmTargetSpd_kph;
    boolean_T u1_M_SPDCtl_CruiseRun_flg;
    int32_T s4_M_SPDCtl_CruiseTq_Nm;
    uint8_T u1_M_SPDCtl_CRUISECtrlSys_enum;
    uint8_T u1_M_SPDCtl_CRUISEDiagError_enum;
    boolean_T u1_M_SPDCtl_CRUISEModStop_flg;
    uint8_T u1_M_SPDCtl_CRUISECtrlSysGearMode_enum;
    boolean_T u1_M_SPDCtl_NedcEnable_flg;
    boolean_T u1_M_SPDCtl_NedcBrakeEnable_flg;
    uint8_T u1_M_SPDCtl_NedcBrakeTypeEnum;
    int32_T s4_M_SPDCtl_NedcBrakeTorque_Nm;
    int32_T s4_M_SPDCtl_HDCTq_Nm;
    boolean_T u1_M_SPDCtl_HDCRun_flg;
    uint8_T u1_M_SPDCtl_HDCCtrlSys_enum;
    real32_T s4_M_SPDCtl_HDCSpeed_kph;
    boolean_T u1_M_SPDCtl_CLTCCycle_flg;
    int16_T u1_M_SPDCtl_CLTCTargetMotSpd_rpm;
}
SPDCtl;

#endif

#ifndef DEFINED_TYPEDEF_FOR_ACR_
#define DEFINED_TYPEDEF_FOR_ACR_

typedef struct
{
    real32_T ACR_AclCtr_TargetTorque_Nm;
}
ACR;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BTK_
#define DEFINED_TYPEDEF_FOR_BTK_

typedef struct
{
    boolean_T BTK_SSB1Sts;
    boolean_T BTK_SSB2Sts;
    boolean_T BTK_SSBSts;
    boolean_T BTK_SSBRedLed;
    boolean_T BTK_SSBGreenLed;
    boolean_T BTK_IGNRelay1_flg;
    boolean_T BTK_IGNRelay2_flg;
    uint8_T BTK_FailedReason;
    uint8_T BTK_Remind;
    uint8_T BTK_PDU;
    boolean_T BTK_ACChrg_flg;
    boolean_T BTK_DCChrg_flg;
    boolean_T BTK_RemoteHVACReq;
    boolean_T BTK_IChrgReq;
}
BTK;

#endif

#ifndef DEFINED_TYPEDEF_FOR_ABS_TQ_
#define DEFINED_TYPEDEF_FOR_ABS_TQ_

typedef struct
{
    boolean_T No_Evflag;
    boolean_T ABS_VehSpdValid;
    boolean_T ABS_Active_flg;
    boolean_T ABSFlgFlt;
    boolean_T ABSEbdFlgFlt;
    boolean_T VSJ_ABS_Spd_Valid;
}
ABS_TQ;

#endif

#ifndef DEFINED_TYPEDEF_FOR_EPB_TQ_
#define DEFINED_TYPEDEF_FOR_EPB_TQ_

typedef struct
{
    uint8_T EPB_Status;
    boolean_T EPB_BrakeLights_Request;
    real32_T EPB_Acceleration_X;
    real32_T SAS_SteeringAngle;
    real32_T SAS_SteeringAngleSpeed;
    boolean_T HandBrake_flg;
    boolean_T SAS_Calibrated;
}
EPB_TQ;

#endif

#ifndef DEFINED_TYPEDEF_FOR_ACCELERATOR_PEDAL_TQ_
#define DEFINED_TYPEDEF_FOR_ACCELERATOR_PEDAL_TQ_

typedef struct
{
    uint16_T AccPct;
    boolean_T AccPress_flg;
    boolean_T AccPct_Valid;
    uint16_T RealAccPct;
}
ACCELERATOR_PEDAL_TQ;

#endif

#ifndef DEFINED_TYPEDEF_FOR_VEHICLE_GEAR_TQ_
#define DEFINED_TYPEDEF_FOR_VEHICLE_GEAR_TQ_

typedef struct
{
    uint8_T Gear_Act;
    boolean_T GearPos_Valid;
    uint8_T DriverRemind;
    boolean_T EPBAppliedReqValid;
    boolean_T EPBAppliedReq;
    uint8_T GearDisplay;
    uint8_T VGJ_GearAct_enum;
}
VEHICLE_GEAR_TQ;

#endif

#ifndef DEFINED_TYPEDEF_FOR_MCU_TQ_
#define DEFINED_TYPEDEF_FOR_MCU_TQ_

typedef struct
{
    int16_T MotTqReal_Nm;
    boolean_T MotTqReal_Valid;
    int16_T MotSpd_Rpm;
    boolean_T MotSpd_Valid;
    real32_T MCUMaxAvlTq_Nm;
    real32_T MCUMinAvlTq_Nm;
    uint8_T VehOri;
    uint8_T MCUFltRnk_Enum;
    boolean_T VSJ_MCU_Spd_Valid;
    uint16_T VSJ_MotSpd;
    uint16_T VSJ_ABS_MotSpd;
    int16_T ASM_MCUAntiSlide_MaxTq;
    int16_T ASM_MCUAntiSlide_MinTq;
}
MCU_TQ;

#endif

#ifndef DEFINED_TYPEDEF_FOR_VEHICLE_SPEED_TQ_
#define DEFINED_TYPEDEF_FOR_VEHICLE_SPEED_TQ_

typedef struct
{
    uint32_T VehSpd;
    boolean_T Vehspd_Valid;
}
VEHICLE_SPEED_TQ;

#endif

#ifndef DEFINED_TYPEDEF_FOR_ROAD_SLOPE_TQ_
#define DEFINED_TYPEDEF_FOR_ROAD_SLOPE_TQ_

typedef struct
{
    int32_T VehAcceleratedSpeed;
    int32_T RoadAngle;
}
ROAD_SLOPE_TQ;

#endif

#ifndef DEFINED_TYPEDEF_FOR_ESC_TQ_
#define DEFINED_TYPEDEF_FOR_ESC_TQ_

typedef struct
{
    boolean_T ESC_TqInc_flg;
    boolean_T ESC_TqDec_flg;
    int16_T ESC_MotorTq_Nm;
    boolean_T ESC_ForbidCreep_flg;
}
ESC_TQ;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BOOSTER_TQ_
#define DEFINED_TYPEDEF_FOR_BOOSTER_TQ_

typedef struct
{
    int16_T BrakeSysRegTqTarget;
    boolean_T BrakeSysRegTqTargetValid;
    uint8_T BoosterFaultStatus;
}
BOOSTER_TQ;

#endif

#ifndef DEFINED_TYPEDEF_FOR_INPUT_TQ_
#define DEFINED_TYPEDEF_FOR_INPUT_TQ_

typedef struct
{
    ABS_TQ ABS;
    EPB_TQ EPB;
    uint8_T DriveMode;
    uint8_T CoastRegenGrade;
    boolean_T BrakeSts;
    uint8_T BMSFltRnk;
    ACCELERATOR_PEDAL_TQ ACCELERATOR_PEDAL;
    VEHICLE_GEAR_TQ VEHICLE_GEAR;
    MCU_TQ MCU;
    boolean_T RegenerationEnable;
    boolean_T CREEP;
    boolean_T DriveSlipDetect_flg;
    VEHICLE_SPEED_TQ VEHICLE_SPEED;
    ROAD_SLOPE_TQ ROAD_SLOP;
    ESC_TQ ESC;
    BOOSTER_TQ BOOSTER;
    boolean_T ClutchEnable;
    real32_T AcceleratedSpeed;
}
INPUT_TQ;

#endif

#ifndef DEFINED_TYPEDEF_FOR_ConditionTq_flg_
#define DEFINED_TYPEDEF_FOR_ConditionTq_flg_

typedef struct
{
    boolean_T Accel_flg;
    boolean_T Creep_flg;
    boolean_T Coast_flg;
    boolean_T Brake_flg;
    boolean_T NEDC_flg;
    boolean_T RegenForbid_flg;
    boolean_T AntiSlide_flg;
    boolean_T CC_flg;
    boolean_T RunForbid_flg;
    boolean_T ESC_flg;
    boolean_T Booster_flg;
    boolean_T CLTC_flg;
    boolean_T HDC_flg;
    boolean_T ACC_flg;
    boolean_T APA_flg;
    boolean_T AEB_flg;
    boolean_T ASM_MotorSpdCtlReq_flg;
    boolean_T ASM_S11_EPBAppliedReq_flg;
    boolean_T ASM_S11_MotorSpdCtlReq_flg;
}
ConditionTq_flg;

#endif

#ifndef DEFINED_TYPEDEF_FOR_ConditionTq_Nm_
#define DEFINED_TYPEDEF_FOR_ConditionTq_Nm_

typedef struct
{
    int16_T CoastTq_Nm;
    int16_T BrakeTq_Nm;
    int16_T AccelTq_Nm;
    int16_T CreepTq_Nm;
    int16_T NEDCTq_Nm;
    int16_T CruiseTq_Nm;
    int16_T RegenForbidTq_Nm;
    int16_T RunForbidTq_Nm;
    int16_T ESCTq_Nm;
    int16_T BoosterTq_Nm;
    int16_T HDCTq_Nm;
    int16_T CLTC_Condition;
    int16_T ACCTq_Nm;
    int16_T AntiSlideTq_Nm;
    int16_T AEBTq_Nm;
    int16_T APATq_Nm;
}
ConditionTq_Nm;

#endif

#ifndef DEFINED_TYPEDEF_FOR_TQM_
#define DEFINED_TYPEDEF_FOR_TQM_

typedef struct
{
    boolean_T TQM_Reverse_Light_Sts;
    boolean_T TQM_Brake_LampSts;
    uint8_T TQM_MCU_ModeReq;
    int16_T TQM_MotSpdReq;
    real32_T TQM_VehTq;
    real32_T TQM_TSC_VehTq;
    boolean_T TQM_MCUAntishake;
    boolean_T b1_M_TQM_TqArbitration;
    boolean_T TQM_AntiSlipFunEn;
    uint8_T TQM_WorkMode;
    real32_T TQM_DriverDmdTq_Nm;
    real32_T TQM_CoastRegenTq_Nm;
    real32_T TQM_TQDDriverDmdTq_Nm;
    int16_T TQM_BrakeRegenTq_Ava;
    boolean_T TQM_BrakeRegenTq_Ava_Valid;
    uint8_T TQM_GearR_SpdLim_Low;
    uint8_T TQM_GearD_SpdLim_Low;
    int16_T TQM_ENM_TqDrive_Lim;
    int16_T TQM_AntiSlip_Tq_Lim;
    real32_T TQM_SpdLimTq_Nm;
    real32_T TQM_TQRVehTq_Nm;
    boolean_T TQM_VehSpd_Valid;
    real32_T TQM_AccePct;
    int16_T TQM_VCU_AvTq_Max;
    int16_T TQM_VCU_AvTq_Min;
    uint8_T TQM_Gear_Act;
    boolean_T TQM_GearPos_Valid;
    uint8_T TQM_GearDisp;
    boolean_T TQM_EPBAppliedReq;
    boolean_T TQM_EPBAppliedReqValid;
    uint8_T TQM_Driver_Remind;
    uint8_T TQM_CoastRegenGrade;
    boolean_T TQM_AccePct_Valid;
    real32_T TQM_Veh_Accel;
    real32_T TQM_Road_Angle;
    uint8_T TQM_VehOri;
    boolean_T TQM_AccePress_Flg;
    real32_T TQM_MotSpd;
    boolean_T TQM_MCU_Spd_Valid;
    boolean_T TQM_ABS_Spd_Valid;
    real32_T TQM_VehSpd;
    real32_T TQM_AcceleratedSpeed_mpss;
    boolean_T TQM_FrontSeatMotor_flg;
    boolean_T TQM_RearSeatMotor_flg;
}
TQM;

#endif
#endif                                 /* RTW_HEADER_TQM_model_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

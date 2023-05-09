/*
 * File: HALI_model_private.h
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

#ifndef RTW_HEADER_HALI_model_private_h_
#define RTW_HEADER_HALI_model_private_h_
#include "rtwtypes.h"

/* Imported (extern) states */
extern uint8_T VHALI_HWVersion;        /* '<S2>/Data Store Memory1' */

/* Imported (extern) block parameters */
extern uint32_T PeriodSendInvalidMsg;  /* Variable: PeriodSendInvalidMsg
                                        * Referenced by: '<Root>/Constant11'
                                        */
extern uint16_T KUDS_ABSStopedSpeed;   /* Variable: KUDS_ABSStopedSpeed
                                        * Referenced by: '<Root>/Constant7'
                                        */
extern uint16_T KUDS_MotorStopedSpeed; /* Variable: KUDS_MotorStopedSpeed
                                        * Referenced by: '<Root>/Constant8'
                                        */
extern uint8_T KACMiddleVoltage_flg;   /* Variable: KACMiddleVoltage_flg
                                        * Referenced by: '<Root>/Constant6'
                                        */
extern uint8_T KHALI_DisRelayWhenCanOff;/* Variable: KHALI_DisRelayWhenCanOff
                                         * Referenced by: '<Root>/Constant10'
                                         */
extern uint8_T KNVM_SelfClrCycle;      /* Variable: KNVM_SelfClrCycle
                                        * Referenced by: '<Root>/Constant12'
                                        */
extern uint8_T KUDS_CheckCalData;      /* Variable: KUDS_CheckCalData
                                        * Referenced by: '<Root>/Constant14'
                                        */
extern uint8_T KUDS_CheckDidCrc;       /* Variable: KUDS_CheckDidCrc
                                        * Referenced by: '<Root>/Constant13'
                                        */
extern uint8_T KUDS_IOCtrlEnable;      /* Variable: KUDS_IOCtrlEnable
                                        * Referenced by: '<Root>/Constant9'
                                        */
extern uint8_T KUDS_SupportOldBoot;    /* Variable: KUDS_SupportOldBoot
                                        * Referenced by: '<Root>/Constant5'
                                        */
extern uint8_T KUDS_TestFeature;       /* Variable: KUDS_TestFeature
                                        * Referenced by: '<Root>/Constant4'
                                        */
extern real32_T look1_iflf_binlx(real32_T u0, const real32_T bp0[], const
  real32_T table[], uint32_T maxIndex);

/* Exported data declaration */

/* Declaration for custom storage class: ImportFromFile */
extern uint8_T AppBeginRunning_flg;
extern boolean_T CAN3_BusOffDelayTimeOut;
extern uint8_T CAN_Send_Cmd;
extern uint8_T K11_Mark;
extern uint32_T KHALI_Escl_ForceEraseDuration;
extern uint16_T KHALI_Escl_InitDelay;
extern uint16_T KHALI_Escl_ProgKeyInterval;
extern uint8_T KHALI_Escl_TasckStep;
extern uint16_T KHALI_Escl_TimeOut_1;
extern uint16_T KHALI_Escl_TimeOut_2;
extern uint16_T KHALI_Escl_TimeOut_31;
extern uint16_T KHALI_Escl_TimeOut_32;
extern uint16_T KHALI_Escl_TimeOut_33;
extern uint16_T KHALI_Escl_TimeOut_4;
extern uint16_T KHALI_Escl_TimeOut_5;
extern boolean_T NmSentFlg;
extern uint8_T S11_Mark;
extern uint32_T VHALI_ABS_229_MsgTicks;
extern uint32_T VHALI_ABS_232_MsgTicks;
extern uint32_T VHALI_ABS_237_MsgTicks;
extern uint8_T VHALI_ABS_AbsCtrlActv;
extern uint8_T VHALI_ABS_AbsFlgFlt;
extern uint8_T VHALI_ABS_Checksum;
extern uint8_T VHALI_ABS_Checksum237;
extern uint8_T VHALI_ABS_EbdFlgFlt;
extern uint16_T VHALI_ABS_FLWheelSpeed;
extern uint8_T VHALI_ABS_FLWheelSpeedValid;
extern uint16_T VHALI_ABS_FRWheelSpeed;
extern uint8_T VHALI_ABS_FRWheelSpeedValid;
extern uint16_T VHALI_ABS_RLWheelSpeed;
extern uint8_T VHALI_ABS_RLWheelSpeedValid;
extern uint16_T VHALI_ABS_RRWheelSpeed;
extern uint8_T VHALI_ABS_RRWheelSpeedValid;
extern uint8_T VHALI_ABS_RollingCounter;
extern uint8_T VHALI_ABS_RollingCounter237;
extern uint16_T VHALI_ABS_VehicleSpeed;
extern uint8_T VHALI_ABS_VehicleSpeedValid;
extern boolean_T VHALI_ACSwitchActiveIn_flg;
extern uint16_T VHALI_AC_AcceptPower;
extern uint16_T VHALI_AC_ActSpeed;
extern uint8_T VHALI_AC_Checksum;
extern uint8_T VHALI_AC_Command;
extern uint8_T VHALI_AC_Counter;
extern uint16_T VHALI_AC_MAXPower;
extern uint8_T VHALI_AC_SpeedSet;
extern uint16_T VHALI_AC_TargetPower;
extern real32_T VHALI_AccelPedalHIn_V;
extern real32_T VHALI_AccelPedalLIn_V;
extern uint8_T VHALI_Ambient_Light;
extern uint32_T VHALI_BCM_410h_MsgTicks;
extern uint8_T VHALI_BCM_RearDefrosterstatus;
extern uint8_T VHALI_BMS113CycCntr;
extern uint8_T VHALI_BMS213CycCntr;
extern uint8_T VHALI_BMS233CycCntr;
extern uint8_T VHALI_BMS303CycCntr;
extern uint8_T VHALI_BMS313CycCntr;
extern uint8_T VHALI_BMSAvrgBattT;
extern uint16_T VHALI_BMSBattExU;
extern uint8_T VHALI_BMSBattHeatI;
extern uint16_T VHALI_BMSBattI;
extern uint8_T VHALI_BMSBattIntrHeatActv;
extern uint8_T VHALI_BMSBattIntrHeatReq;
extern uint8_T VHALI_BMSBattNumTot;
extern uint16_T VHALI_BMSBattRatedPwr;
extern uint16_T VHALI_BMSBattResidPwr;
extern uint8_T VHALI_BMSBattTherMagErr;
extern uint8_T VHALI_BMSBattTherMagReq;
extern uint8_T VHALI_BMSBattTherTargetFlow;
extern uint8_T VHALI_BMSBattTherTargetT;
extern uint16_T VHALI_BMSBattU;
extern uint16_T VHALI_BMSBattUOverU;
extern uint16_T VHALI_BMSBattUUnderU;
extern uint16_T VHALI_BMSCC2SngR;
extern uint16_T VHALI_BMSCCSngR;
extern uint8_T VHALI_BMSCPSts;
extern uint8_T VHALI_BMSCPValue;
extern uint8_T VHALI_BMSCRCChk113;
extern uint8_T VHALI_BMSCRCChk213;
extern uint8_T VHALI_BMSCRCChk233;
extern uint8_T VHALI_BMSCRCChk303;
extern uint8_T VHALI_BMSCRCChk313;
extern uint8_T VHALI_BMSCellNumTot;
extern uint16_T VHALI_BMSCellUMax;
extern uint8_T VHALI_BMSCellUMaxBattNum;
extern uint8_T VHALI_BMSCellUMaxCellNum;
extern uint16_T VHALI_BMSCellUMaxOverU;
extern uint16_T VHALI_BMSCellUMin;
extern uint8_T VHALI_BMSCellUMinBattNum;
extern uint8_T VHALI_BMSCellUMinCellNum;
extern uint16_T VHALI_BMSCellUMinUnderU;
extern uint8_T VHALI_BMSChrgErrInfo;
extern uint16_T VHALI_BMSChrgIReq;
extern uint8_T VHALI_BMSChrgMod;
extern uint8_T VHALI_BMSChrgSts;
extern uint16_T VHALI_BMSChrgUReq;
extern uint8_T VHALI_BMSCrashSts;
extern uint8_T VHALI_BMSDCChrgRlySts;
extern boolean_T VHALI_BMSDateMonitoringReq;
extern uint8_T VHALI_BMSDateMonitoringt;
extern uint8_T VHALI_BMSEquilnSts;
extern uint8_T VHALI_BMSErrAmnt;
extern uint16_T VHALI_BMSErrNum;
extern uint8_T VHALI_BMSFltRnk;
extern uint8_T VHALI_BMSHVILSts;
extern boolean_T VHALI_BMSIChrgEna;
extern uint8_T VHALI_BMSInsulationHVLoadErr;
extern uint8_T VHALI_BMSInsulationIntrErr;
extern uint8_T VHALI_BMSInsulationSts;
extern uint16_T VHALI_BMSIsolationR;
extern uint8_T VHALI_BMSMILReq;
extern uint8_T VHALI_BMSMaxBattT;
extern uint8_T VHALI_BMSMaxBattTOverT;
extern uint16_T VHALI_BMSMaxChrgI;
extern uint16_T VHALI_BMSMaxChrgPwr;
extern uint16_T VHALI_BMSMaxChrgU;
extern uint16_T VHALI_BMSMaxDchaI;
extern uint16_T VHALI_BMSMaxDchaPwr;
extern uint8_T VHALI_BMSMinBattT;
extern uint16_T VHALI_BMSMinDchaIU;
extern uint8_T VHALI_BMSOBCHeatModeCtrl;
extern uint16_T VHALI_BMSOBCMaxChrgPwrAvl;
extern uint8_T VHALI_BMSOBCOperModReq;
extern uint8_T VHALI_BMSOperMod;
extern uint16_T VHALI_BMSPPSngR;
extern uint8_T VHALI_BMSPlugLockStatus;
extern uint16_T VHALI_BMSPredChrgTi;
extern uint8_T VHALI_BMSPwrUpAllw;
extern uint8_T VHALI_BMSRlyWlddErr;
extern uint16_T VHALI_BMSRmaingCpby;
extern uint8_T VHALI_BMSS2Stus;
extern uint16_T VHALI_BMSSOC;
extern uint8_T VHALI_BMSSOCMax;
extern uint8_T VHALI_BMSSOCMin;
extern uint16_T VHALI_BMSSOH;
extern uint32_T VHALI_BMS_113_MsgTicks;
extern uint32_T VHALI_BMS_213_MsgTicks;
extern uint32_T VHALI_BMS_233_MsgTicks;
extern uint32_T VHALI_BMS_303_MsgTicks;
extern uint32_T VHALI_BMS_304_MsgTicks;
extern uint32_T VHALI_BMS_313_MsgTicks;
extern uint32_T VHALI_BMS_323_MsgTicks;
extern uint32_T VHALI_BMS_377_MsgTicks;
extern uint32_T VHALI_BMS_513_MsgTicks;
extern uint32_T VHALI_BMS_603_MsgTicks;
extern uint32_T VHALI_BMS_613_MsgTicks;
extern uint32_T VHALI_BMS_623_MsgTicks;
extern uint32_T VHALI_BMS_633_MsgTicks;
extern uint32_T VHALI_BMS_653_MsgTicks;
extern int16_T VHALI_BatInWaterT_deg;
extern real32_T VHALI_Batt_InWater_T;
extern real32_T VHALI_Batt_OutWater_T;
extern uint8_T VHALI_BrakePedalApplied;
extern uint8_T VHALI_BrakePedalAppliedValid;
extern uint8_T VHALI_BrakePedalPosition;
extern uint8_T VHALI_BrakePedalPositionValid;
extern uint16_T VHALI_BrakeSysRegTrqTrgt;
extern uint8_T VHALI_BrakeSysRegTrqTrgtValid;
extern boolean_T VHALI_BrkLightSwitch1ActiveIn_flg;
extern boolean_T VHALI_BrkLightSwitch2ActiveIn_flg;
extern uint8_T VHALI_Bus_cur_ERR;
extern uint8_T VHALI_Bus_limit;
extern uint8_T VHALI_CALIB_Running_Status;
extern uint8_T VHALI_CAN_ERR;
extern uint8_T VHALI_CAN_Receive_Error;
extern uint8_T VHALI_COMPBaseState;
extern uint8_T VHALI_COMPCurr;
extern uint8_T VHALI_COMPMotor_Temp;
extern int16_T VHALI_COMPSpeed_now;
extern uint8_T VHALI_COMPVold;
extern uint8_T VHALI_CPSts;
extern uint8_T VHALI_C_boosterFaultStatus;
extern uint8_T VHALI_Calibration_Board_Detected;
extern uint8_T VHALI_Camera_Error;
extern uint16_T VHALI_ChrgPilePwrAvail;
extern uint16_T VHALI_ChrgSysMaxPwrSup;
extern uint32_T VHALI_ClstrOdo;
extern boolean_T VHALI_ClutchSwitch1_flg;
extern boolean_T VHALI_ClutchSwitch2_flg;
extern uint8_T VHALI_CollisionDutyIn_pct;
extern uint8_T VHALI_CollisionFreIn_Hz;
extern boolean_T VHALI_CrankActiveIn_flg;
extern uint16_T VHALI_DCDCAvlOutpPwr;
extern uint8_T VHALI_DCDCErrCANCom;
extern uint8_T VHALI_DCDCFltRnk;
extern uint8_T VHALI_DCDCHwFltFlg;
extern uint8_T VHALI_DCDCIInput;
extern uint16_T VHALI_DCDCInpU;
extern uint8_T VHALI_DCDCOperMod;
extern uint16_T VHALI_DCDCOutpCrrt;
extern uint16_T VHALI_DCDCOutpU;
extern uint8_T VHALI_DCDCOverInpU;
extern uint8_T VHALI_DCDCOverOutpCrrt;
extern uint8_T VHALI_DCDCOverOutpPwr;
extern uint8_T VHALI_DCDCOverOutpU;
extern uint8_T VHALI_DCDCOverT;
extern uint8_T VHALI_DCDCShoCircOutp;
extern uint32_T VHALI_DCDCSwVers;
extern uint8_T VHALI_DCDCT;
extern uint8_T VHALI_DCDCUnderInpU;
extern uint8_T VHALI_DCDCUnderOutpU;
extern uint32_T VHALI_DCDC_231_MsgTicks;
extern uint32_T VHALI_DCDC_251_MsgTicks;
extern uint8_T VHALI_DefrostActiveIn_flg;
extern uint8_T VHALI_DriveHeatAllow;
extern uint8_T VHALI_DrvrDoorSts;
extern uint8_T VHALI_EACReqIn_flg;
extern uint32_T VHALI_EAC_349_MsgTicks;
extern uint32_T VHALI_EAC_34A_MsgTicks;
extern uint8_T VHALI_EAC_BusbarCurrent;
extern uint8_T VHALI_EAC_BusbarVoltage;
extern uint8_T VHALI_EAC_CurrentState;
extern boolean_T VHALI_EAC_IGBTMalfct;
extern uint8_T VHALI_EAC_IGBTTemp;
extern boolean_T VHALI_EAC_LackPhase;
extern boolean_T VHALI_EAC_OverCurrent;
extern boolean_T VHALI_EAC_OverHeatFault;
extern boolean_T VHALI_EAC_OverHighVolt;
extern boolean_T VHALI_EAC_OverPhaVoltMalfct;
extern boolean_T VHALI_EAC_Overload;
extern uint8_T VHALI_EAC_PeakPhaCurrent;
extern uint16_T VHALI_EAC_PowerConsumption;
extern uint16_T VHALI_EAC_RealSpeed;
extern boolean_T VHALI_EAC_RotateSpdAnomaly;
extern boolean_T VHALI_EAC_SampleCircMalfct;
extern boolean_T VHALI_EAC_StallFault;
extern boolean_T VHALI_EAC_TTLfault;
extern boolean_T VHALI_EAC_TempSensorFault;
extern boolean_T VHALI_EAC_UnderHighVolt;
extern uint32_T VHALI_ECC_33C_MsgTicks;
extern uint32_T VHALI_ECC_34C_MsgTicks;
extern uint32_T VHALI_ECC_35C_MsgTicks;
extern uint32_T VHALI_ECC_36C_MsgTicks;
extern uint16_T VHALI_ECC_ACTargetPwrReq;
extern uint8_T VHALI_ECC_A_C_Req;
extern uint8_T VHALI_ECC_A_C_ReqValid;
extern uint8_T VHALI_ECC_AutoReq;
extern uint8_T VHALI_ECC_Blowing;
extern uint8_T VHALI_ECC_EnvironmentalTemp;
extern uint8_T VHALI_ECC_EvaporatorTemp;
extern uint8_T VHALI_ECC_InterCarTemp;
extern uint8_T VHALI_ECC_Mode;
extern uint8_T VHALI_ECC_PM2_5;
extern uint16_T VHALI_ECC_PTCTargetPwrReq;
extern uint8_T VHALI_ECC_PTC_Req;
extern uint8_T VHALI_ECC_PTC_ReqValid;
extern uint8_T VHALI_ECC_Rec_FreSetState;
extern uint8_T VHALI_ECC_RemoteACStatus;
extern uint8_T VHALI_ECC_Sunlight;
extern uint8_T VHALI_ECC_TempSetReq;
extern uint32_T VHALI_EHU_345_MsgTicks;
extern uint32_T VHALI_EHU_412h_MsgTicks;
extern uint8_T VHALI_EHU_DriverModel;
extern uint8_T VHALI_EHU_EnergyRecovery;
extern uint8_T VHALI_EHU_VSPSwitchSet;
extern boolean_T VHALI_EHU_VehrpValid;
extern uint8_T VHALI_EHU_VoiceIdentify;
extern uint8_T VHALI_EPB_Acceleration_X;
extern uint8_T VHALI_EPB_Brake_Lights_Requested;
extern uint8_T VHALI_EPB_Status;
extern uint32_T VHALI_EPS_180_MsgTicks;
extern uint32_T VHALI_EPS_2A0_MsgTicks;
extern uint8_T VHALI_EPS_EpasFailed;
extern uint8_T VHALI_EPS_TorqSensorStatus;
extern uint16_T VHALI_ESC_MotorTorq_Req;
extern uint8_T VHALI_ESC_MotorWork_Req;
extern boolean_T VHALI_ESP_EBDActiveStatus;
extern boolean_T VHALI_ESP_ESPActiveStatus;
extern boolean_T VHALI_ESP_ESPFailStatus;
extern boolean_T VHALI_ESP_ESPSwitchStatus;
extern boolean_T VHALI_ESP_HBAActiveStatus;
extern boolean_T VHALI_ESP_HHCActiveStatus;
extern boolean_T VHALI_ESP_TCSActiveStatus;
extern uint16_T VHALI_EWP_CurrentSpeed;
extern uint16_T VHALI_EWP_ErrorCode;
extern uint8_T VHALI_EWP_Temperature;
extern uint16_T VHALI_EWP_Volatge;
extern uint8_T VHALI_EXV_ErrorCheck;
extern uint8_T VHALI_EXV_ErrorStatus;
extern uint8_T VHALI_EXV_InitStatus;
extern uint16_T VHALI_EXV_Position;
extern uint8_T VHALI_EXV_RunStatus;
extern uint8_T VHALI_EXV_TemperatureErrorStatus;
extern uint8_T VHALI_EXV_VolatgeErrorStatus;
extern uint8_T VHALI_FCWS_Running_Status;
extern uint8_T VHALI_FCW_TTC;
extern uint8_T VHALI_FCW_TTC_Valid_Flag;
extern uint8_T VHALI_FLPressureWarning;
extern uint8_T VHALI_FLTempHigh;
extern uint8_T VHALI_FLTirePres;
extern uint8_T VHALI_FLTireTemp;
extern uint8_T VHALI_FRPressureWarning;
extern uint8_T VHALI_FRTempHigh;
extern uint8_T VHALI_FRTirePres;
extern uint8_T VHALI_FRTireTemp;
extern boolean_T VHALI_FastChargeAwakeActiveIn_flg;
extern real32_T VHALI_FastChargeTemp1In_V;
extern real32_T VHALI_FastChargeTemp2In_V;
extern boolean_T VHALI_FastChrgCANAwakeActiveIn_flg;
extern uint8_T VHALI_Forward_Collision_Warning;
extern uint8_T VHALI_Forward_Vehicle_Detected;
extern uint8_T VHALI_Forward_Vehicle_Distance;
extern uint8_T VHALI_FrontDefrosterSwitch;
extern uint8_T VHALI_FrtPsngDoorSts;
extern uint32_T VHALI_GW_217_MsgTicks;
extern uint32_T VHALI_GW_405_MsgTicks;
extern uint32_T VHALI_GW_405h_MsgTicks;
extern uint32_T VHALI_GW_522_MsgTicks;
extern boolean_T VHALI_GearSwitch1ActiveIn_flg;
extern boolean_T VHALI_GearSwitch2ActiveIn_flg;
extern boolean_T VHALI_GearSwitch3ActiveIn_flg;
extern boolean_T VHALI_GearSwitch4ActiveIn_flg;
extern uint8_T VHALI_HSFaultCodeIn_enum;
extern uint8_T VHALI_HVInterlockFreIn_Hz;
extern uint8_T VHALI_HVolt_ERR;
extern boolean_T VHALI_HandBrake;
extern uint8_T VHALI_Hardware_Ver;
extern uint32_T VHALI_ICM_235_MsgTicks;
extern uint32_T VHALI_ICM_421h_MsgTicks;
extern uint16_T VHALI_ICM_VehicleSpeedDisplay;
extern boolean_T VHALI_IChrgWakeUpReq;
extern real32_T VHALI_IGN1_Out_v;
extern real32_T VHALI_IGN2_Out_v;
extern boolean_T VHALI_IgnitionOnIn_flg;
extern uint8_T VHALI_LDWS_Running_Status;
extern uint8_T VHALI_LDW_Alarm_Off;
extern uint8_T VHALI_LDW_Left_Departure;
extern uint8_T VHALI_LDW_Left_Detected;
extern uint8_T VHALI_LDW_Right_Departure;
extern uint8_T VHALI_LDW_Right_Detected;
extern uint32_T VHALI_LSFaultCodeIn_enum;
extern real32_T VHALI_LVBattVoltageIn_V;
extern real32_T VHALI_LVK15VoltageIn_V;
extern uint8_T VHALI_LVolt_ERR;
extern uint8_T VHALI_LWheelLaneDistance;
extern uint8_T VHALI_MCU131CRCErr;
extern uint8_T VHALI_MCUCANComErr;
extern uint8_T VHALI_MCUCRCElecMotSpdErr;
extern uint8_T VHALI_MCUCRCRealTqErr;
extern uint8_T VHALI_MCUDCUShoCirc;
extern uint16_T VHALI_MCUDcCrrt;
extern uint8_T VHALI_MCUDcCrrtSnsrRatiErr;
extern uint16_T VHALI_MCUDcU;
extern uint8_T VHALI_MCUDcUOverUErr;
extern uint8_T VHALI_MCUDcUSnsrRatiErr;
extern uint8_T VHALI_MCUDcUUnderUErr;
extern uint8_T VHALI_MCUDischrgErr;
extern uint8_T VHALI_MCUElecMotOverCrrtErr;
extern uint8_T VHALI_MCUElecMotOverSpdErr;
extern uint8_T VHALI_MCUElecMotOverTErr;
extern uint8_T VHALI_MCUElecMotReslvErr;
extern uint16_T VHALI_MCUElecMotSpd;
extern uint8_T VHALI_MCUElecMotStopTurnErr;
extern uint16_T VHALI_MCUElecMotT;
extern uint8_T VHALI_MCUElecMotTSnsrRatiErr;
extern uint8_T VHALI_MCUElecMotTqErr;
extern uint8_T VHALI_MCUElecMotUnderTErr;
extern uint8_T VHALI_MCUErrAmnt;
extern uint8_T VHALI_MCUErrNum;
extern uint8_T VHALI_MCUFltRnk;
extern uint8_T VHALI_MCUHVLockErr;
extern boolean_T VHALI_MCUHWCurrOverErr;
extern uint8_T VHALI_MCUID153CycCntr;
extern uint8_T VHALI_MCUIGBTOverTErr;
extern uint16_T VHALI_MCUIGBTT;
extern uint8_T VHALI_MCUIGBTTSnsrRatiErr;
extern uint8_T VHALI_MCULowBatUnderUErr;
extern uint16_T VHALI_MCUMaxAvlTq;
extern uint16_T VHALI_MCUMinAvlTq;
extern uint8_T VHALI_MCUMotNum;
extern uint8_T VHALI_MCUMotNumTot;
extern uint8_T VHALI_MCUMotSts;
extern uint8_T VHALI_MCUMotopenphaseErr;
extern uint8_T VHALI_MCUOperMdl;
extern uint8_T VHALI_MCUOverTErr;
extern uint8_T VHALI_MCUPhaACrrtSnsrRatiErr;
extern uint8_T VHALI_MCUPhaBCrrtSnsrRatiErr;
extern uint8_T VHALI_MCUPhaCCrrtSnsrRatiErr;
extern uint16_T VHALI_MCUPhaCrrt;
extern uint8_T VHALI_MCUPrechrgErr;
extern uint8_T VHALI_MCUPwrModErr;
extern uint8_T VHALI_MCUPwrModUnderUErr;
extern uint8_T VHALI_MCUSystemErr;
extern uint8_T VHALI_MCUT;
extern uint8_T VHALI_MCUTSnsrRatiErr;
extern uint8_T VHALI_MCUTarTorOverErr;
extern uint8_T VHALI_MCUUndefineErr2;
extern uint8_T VHALI_MCUUndefineErr3;
extern uint32_T VHALI_MCU_115_MsgTicks;
extern uint32_T VHALI_MCU_125_MsgTicks;
extern uint32_T VHALI_MCU_215_MsgTicks;
extern uint32_T VHALI_MCU_515_MsgTicks;
extern uint16_T VHALI_MotTqReal;
extern uint8_T VHALI_Motor_Ver;
extern uint8_T VHALI_NO_Evflag;
extern uint8_T VHALI_Need_Calibrate_Error;
extern uint8_T VHALI_OBC311CycCntr;
extern uint8_T VHALI_OBC321CycCntr;
extern uint8_T VHALI_OBC331CycCntr;
extern uint8_T VHALI_OBCCANErr;
extern uint8_T VHALI_OBCCPValue;
extern uint16_T VHALI_OBCChrgDcI;
extern uint16_T VHALI_OBCChrgDcU;
extern uint16_T VHALI_OBCChrgInpAcI;
extern uint16_T VHALI_OBCChrgInpAcU;
extern uint8_T VHALI_OBCChrgSts;
extern uint8_T VHALI_OBCFltRnk;
extern uint8_T VHALI_OBCHwErr;
extern uint8_T VHALI_OBCInpIOver;
extern uint8_T VHALI_OBCInpUOver;
extern uint8_T VHALI_OBCInpUUnder;
extern uint16_T VHALI_OBCMaxChrgOutpIAvl;
extern uint16_T VHALI_OBCMaxChrgOutpPwrAvl;
extern uint16_T VHALI_OBCMaxChrgOutpUAvl;
extern uint8_T VHALI_OBCOutpIOver;
extern uint8_T VHALI_OBCOutpUOver;
extern uint8_T VHALI_OBCOutpUUnder;
extern uint8_T VHALI_OBCS2Stus;
extern uint8_T VHALI_OBCT;
extern uint8_T VHALI_OBCTOvrErr;
extern uint8_T VHALI_OBCVehInletT;
extern uint32_T VHALI_OBC_311_MsgTicks;
extern uint32_T VHALI_OBC_321_MsgTicks;
extern uint32_T VHALI_OBC_331_MsgTicks;
extern real32_T VHALI_PCBTempIn_V;
extern uint8_T VHALI_PCWS_Running_Status;
extern uint32_T VHALI_PEPS_103_MsgTicks;
extern uint32_T VHALI_PEPS_108_MsgTicks;
extern uint32_T VHALI_PEPS_282_MsgTicks;
extern uint32_T VHALI_PEPS_411h_MsgTicks;
extern uint8_T VHALI_PEPS_EncryptedResponseByte0;
extern uint8_T VHALI_PEPS_EncryptedResponseByte1;
extern uint8_T VHALI_PEPS_EncryptedResponseByte2;
extern uint8_T VHALI_PEPS_EncryptedResponseByte3;
extern uint8_T VHALI_PEPS_EncryptedResponseByte4;
extern uint8_T VHALI_PEPS_EncryptedResponseByte5;
extern uint8_T VHALI_PEPS_EncryptedRsvd;
extern uint8_T VHALI_PEPS_EncryptedStatus;
extern uint8_T VHALI_PEPS_PDU;
extern uint8_T VHALI_PEPS_ReAuth_Req;
extern uint8_T VHALI_PEPS_RkeCmd;
extern uint16_T VHALI_PTCActPower;
extern uint8_T VHALI_PTCChecksum;
extern uint8_T VHALI_PTCCommand;
extern uint8_T VHALI_PTCCounter;
extern uint8_T VHALI_PTCHighReqIn_flg;
extern uint16_T VHALI_PTCIGBTT;
extern uint8_T VHALI_PTCLowReqIn_flg;
extern uint8_T VHALI_PTCRecTemp;
extern boolean_T VHALI_PTCSwitchActiveIn_flg;
extern uint16_T VHALI_PTCTargetPwr;
extern uint32_T VHALI_PTC_5DA_MsgTicks;
extern uint32_T VHALI_PTC_5DB_MsgTicks;
extern uint8_T VHALI_PTC_HVOFFfault;
extern uint8_T VHALI_PTC_HVOverfault;
extern uint8_T VHALI_PTC_HVUnderfault;
extern uint8_T VHALI_PTC_IGBTErr;
extern uint8_T VHALI_PTC_IGBTOverTErr;
extern uint8_T VHALI_PTC_IGBTTSnsrErr;
extern uint16_T VHALI_PTC_InVoltage;
extern uint16_T VHALI_PTC_MAXPower;
extern uint8_T VHALI_PTC_OverCurrfault;
extern uint16_T VHALI_PTC_Power;
extern uint8_T VHALI_PTC_State;
extern uint8_T VHALI_PTC_TempOverTErr;
extern uint8_T VHALI_PTC_TempSnsrErr;
extern uint8_T VHALI_PTC_Temperature;
extern uint16_T VHALI_PTSensorP_kPa;
extern int16_T VHALI_PTSensorT_deg;
extern uint8_T VHALI_PlugLockStatus;
extern uint8_T VHALI_Pow_limit;
extern uint8_T VHALI_Pre_Collision_Warning;
extern uint8_T VHALI_RLDoorSts;
extern uint8_T VHALI_RLPressureWarning;
extern uint8_T VHALI_RLTempHigh;
extern uint8_T VHALI_RLTirePres;
extern uint8_T VHALI_RLTireTemp;
extern uint8_T VHALI_RRDoorSts;
extern uint8_T VHALI_RRPressureWarning;
extern uint8_T VHALI_RRTempHigh;
extern uint8_T VHALI_RRTirePres;
extern uint8_T VHALI_RRTireTemp;
extern uint8_T VHALI_RWheelLaneDistance;
extern uint8_T VHALI_RearDefrosterSwitch;
extern uint8_T VHALI_SAS_Calibrated;
extern uint8_T VHALI_SAS_SASFailure;
extern uint16_T VHALI_SAS_SteeringAngle;
extern uint8_T VHALI_SAS_SteeringAngleSpeed;
extern uint8_T VHALI_SAS_SteeringAngleValid;
extern uint32_T VHALI_SRS_050_MsgTicks;
extern uint8_T VHALI_SRS_CrashOutputStatus;
extern uint8_T VHALI_SRS_CrashOutputStatusCheckSum;
extern uint8_T VHALI_SRS_DriverBuckleSwitchStatus;
extern uint8_T VHALI_SRS_FrontPsgOccupancy;
extern uint8_T VHALI_SRS_PassengerBuckleSwitchStatus;
extern uint8_T VHALI_SRS_RollingCounter;
extern uint8_T VHALI_SRS_WarningLampStatus;
extern uint8_T VHALI_SSB_Switch_1;
extern uint8_T VHALI_SSB_Switch_2;
extern real32_T VHALI_Sensor5V1In_V;
extern real32_T VHALI_Sensor5V2In_V;
extern boolean_T VHALI_SlowChargeAwakeActiveIn_flg;
extern uint8_T VHALI_Software_Ver;
extern uint8_T VHALI_Spdvalidflag;
extern uint8_T VHALI_Start_ERR;
extern uint8_T VHALI_StudyFailureWarning;
extern uint8_T VHALI_StudyMode;
extern uint8_T VHALI_SubtotalEgyCnseRet;
extern uint8_T VHALI_SystemWarning;
extern uint8_T VHALI_System_Boot_Failed;
extern uint8_T VHALI_System_Halted_Error;
extern uint8_T VHALI_System_Status;
extern uint32_T VHALI_TBOX_296_MsgTicks;
extern uint32_T VHALI_TBOX_298_MsgTicks;
extern uint32_T VHALI_TBOX_430h_MsgTicks;
extern uint8_T VHALI_TBOX_LockCommand;
extern boolean_T VHALI_TBOX_RemoteHVACReq;
extern boolean_T VHALI_TBOX_RemoteWorkReq;
extern uint8_T VHALI_TBOX_TimeDate;
extern uint8_T VHALI_TBOX_TimeHour;
extern uint8_T VHALI_TBOX_TimeMinute;
extern uint8_T VHALI_TBOX_TimeMonth;
extern uint8_T VHALI_TBOX_TimeSecond;
extern uint8_T VHALI_TBOX_TimeValid;
extern uint8_T VHALI_TBOX_TimeYear;
extern uint32_T VHALI_TMS_2C0_MsgTicks;
extern uint32_T VHALI_TMS_2C1_MsgTicks;
extern uint32_T VHALI_TMS_2C2_MsgTicks;
extern uint32_T VHALI_TMS_2C3_MsgTicks;
extern uint32_T VHALI_TMS_325_MsgTicks;
extern boolean_T VHALI_TMS_AC_Command;
extern uint16_T VHALI_TMS_AC_Pow_limit;
extern boolean_T VHALI_TMS_AC_ReqValid;
extern uint8_T VHALI_TMS_AC_SpeedSet;
extern uint8_T VHALI_TMS_AC_SwtSts;
extern uint16_T VHALI_TMS_AC_TargetPwr;
extern uint8_T VHALI_TMS_Batt_EXVSt;
extern boolean_T VHALI_TMS_Batt_GVSt;
extern uint8_T VHALI_TMS_Batt_WPFlow;
extern boolean_T VHALI_TMS_COOLErr;
extern uint8_T VHALI_TMS_Cabin_EXVSt;
extern boolean_T VHALI_TMS_Cabin_GVSt;
extern boolean_T VHALI_TMS_PTCSwtSts;
extern uint16_T VHALI_TMS_PTCTargetPwr;
extern boolean_T VHALI_TMS_PTC_Command;
extern uint16_T VHALI_TMS_PTC_Pow_limit;
extern boolean_T VHALI_TMS_PTC_ReqValid;
extern uint8_T VHALI_TMS_PTC_Target_T;
extern uint8_T VHALI_TMS_PoweDesired_WPTC;
extern boolean_T VHALI_TMS_StateOverT;
extern uint16_T VHALI_TMS_WPTCTargetPwr;
extern uint16_T VHALI_TMS_WPTC_Max_Power;
extern boolean_T VHALI_TMS_WPTC_Req;
extern boolean_T VHALI_TMS_WPTC_ReqValid;
extern uint8_T VHALI_TPMSLearnIdStatus;
extern uint32_T VHALI_TPMS_317_MsgTicks;
extern uint32_T VHALI_TPMS_3A2_MsgTicks;
extern uint8_T VHALI_TailgateSts;
extern uint8_T VHALI_Trqvalidflag;
extern uint8_T VHALI_VMS_EN_Err;
extern uint16_T VHALI_VacuumPumpIn_Hz;
extern real32_T VHALI_VacuumPumpIn_V;
extern uint8_T VHALI_VehLckSts;
extern uint32_T VHALI_WPTC_2F0_MsgTicks;
extern uint32_T VHALI_WPTC_566_MsgTicks;
extern uint8_T VHALI_WPTC_BusbarCurrent;
extern uint8_T VHALI_WPTC_CurrentPower;
extern boolean_T VHALI_WPTC_HVCircCut;
extern boolean_T VHALI_WPTC_HVCircShort;
extern boolean_T VHALI_WPTC_IGBTDriverFlt;
extern boolean_T VHALI_WPTC_IGBTOverHeat;
extern uint8_T VHALI_WPTC_IGBTTemp;
extern boolean_T VHALI_WPTC_IGBTTempSnsrFlt;
extern uint8_T VHALI_WPTC_InVoltage;
extern boolean_T VHALI_WPTC_OverCurrent;
extern boolean_T VHALI_WPTC_OverHV;
extern boolean_T VHALI_WPTC_OverLV;
extern uint16_T VHALI_WPTC_Power;
extern uint8_T VHALI_WPTC_RunMode;
extern boolean_T VHALI_WPTC_State;
extern boolean_T VHALI_WPTC_UnderHV;
extern boolean_T VHALI_WPTC_UnderLV;
extern boolean_T VHALI_WPTC_WaterOverHeat;
extern uint8_T VHALI_WPTC_WaterTemp;
extern boolean_T VHALI_WPTC_WaterTempSnsrFlt;
extern uint8_T VHALI_WaterPwmIn_Duty;
extern uint16_T VHALI_WaterPwmIn_Hz;
extern int16_T VHALI_WheelSpeedPlusCounter_FL;
extern uint8_T VHALI_WheelSpeedPlusCounter_FL_Valid;
extern int16_T VHALI_WheelSpeedPlusCounter_FR;
extern uint8_T VHALI_WheelSpeedPlusCounter_FR_Valid;
extern int16_T VHALI_WheelSpeedPlusCounter_RL;
extern uint8_T VHALI_WheelSpeedPlusCounter_RL_Valid;
extern int16_T VHALI_WheelSpeedPlusCounter_RR;
extern uint8_T VHALI_WheelSpeedPlusCounter_RR_Valid;
extern uint8_T VHALI_XBS_BLReq;
extern uint8_T VHALO_BTK_Time;
extern uint8_T VHALO_CANRx_Time;
extern uint8_T VHALO_CHRG_Time;
extern uint8_T VHALO_DHP_Time;
extern uint8_T VHALO_DIM_Time;
extern uint8_T VHALO_DOM_Time;
extern uint8_T VHALO_DSI_Time;
extern uint8_T VHALO_ENM_Time;
extern uint8_T VHALO_HALI_Time;
extern uint8_T VHALO_PEPS_Time;
extern uint8_T VHALO_PMM_Time;
extern uint8_T VHALO_TMM_Time;
extern uint8_T VHALO_TQM_Time;
extern uint8_T VHALO_TotalLoopTime;
extern uint32_T VHAL_VCUBodyCanTickCount;
extern uint32_T VHAL_VCUCanTickCount;
extern uint32_T VHAL_VCUPTCanTickCount;
extern uint8_T Vehicle_Type;
extern uint8_T gbCalDataCorrect;
extern uint8_T gbDidDataCorrect;
extern uint8_T hIOP_FastChargeAwake_flg;
extern real32_T hIOP_K15_V;
extern uint8_T hIOP_SlowChargeAwake_flg;

#endif                                 /* RTW_HEADER_HALI_model_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

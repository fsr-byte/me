/*
 * File: DHP_model.c
 *
 * Code generated for Simulink model 'DHP_model'.
 *
 * Model version                  : 1.5367
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Fri Mar 18 15:33:37 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Freescale->32-bit PowerPC
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. ROM efficiency
 *    3. RAM efficiency
 *    4. MISRA C:2012 guidelines
 * Validation result: Not run
 */

#include "DHP_model.h"
#include "DHP_model_private.h"

#pragma push
#pragma DATA_SEG __GPAGE_SEG GPAGED_RAM

const DHP DHP_model_rtZDHP = {
  false,                               /* VDHP_BrakeSysFault_Flg */
  false,                               /* VDHP_AccPedalFault_Flg */
  false,                               /* VDHP_GearSingleNotInAeraFlt_Flg */
  false,                               /* DCDCFault_Flg */
  false,                               /* OBCFault_Flg */
  false,                               /* MCUFault_Flg */
  false,                               /* BMSFault_Flg */
  0U,                                  /* VDHP_MaxFaultLever */
  false,                               /* VDHP_HVILErrFault_flg */
  0U,                                  /* VDHP_BrkDSCheckFaultLevel_enum */
  false,                               /* VDHP_VehCrashFault_flg */
  false,                               /* VDHP_MCU_DisEnableFlg */
  false,                               /* VDHP_AuxBattVoltHighInstFlt_flg */
  false,                               /* VDHP_AuxBattVoltLowInstFlt_flg */
  false,                               /* VDHP_Forbid_DCDCFlg */
  false,                               /* VDHP_Forbid_ConditionFlg */
  false,                               /* VDHP_Forbid_PTCFlg */
  0U,                                  /* VDHP_Spd_Limit */
  0U,                                  /* VDHP_Pwr_Limit_Pct */
  false,                               /* VDHP_Forbid_ChargeFlg */
  false,                               /* VDHP_Forbid_ActiveDischargeFlg */
  false,                               /* VDHP_Forbid_PreChargeFlg */
  false,                               /* VDHP_Off_DeviceRelayFlg */
  false,                               /* VDHP_OFFMainRelayFlg */
  false,                               /* VDHP_OFFAllHVRelayFlg */
  false,                               /* VDHP_Normal_PowerDownFlg */
  false,                               /* VDHP_AccPdlLVoltLowInstFlt_flg */
  false,                               /* VDHP_AccPdlLVoltLowFault_flg */
  false,                               /* VDHP_AccPdlLVoltHighInstFlt_flg */
  false,                               /* VDHP_AccPdlLVoltHighFault_flg */
  false,                               /* VDHP_AccPdlLHVoltDeathInstFlt_flg */
  false,                               /* VDHP_AccPdlLHVoltDeathFault_flg */
  false,                               /* VDHP_AccPdlHVoltLowInstFlt_flg */
  false,                               /* VDHP_AccPdlHVoltLowFault_flg */
  false,                               /* VDHP_AccPdlHVoltHighInstFlt_flg */
  false,                               /* VDHP_AccPdlHVoltHighFault_flg */
  false,                               /* VDHP_AccelPdlRatInstFlt_flg */
  false,                               /* VDHP_AccelPdlRatFault_flg */
  false,                               /* VDHP_AccPdlSenRefVoltHighInstFlt_flg */
  false,                               /* VDHP_AccPdlSenRefVoltHighFault_flg */
  false,                               /* VDHP_AccPdlSenRefVoltLowInstFlt_flg */
  false,                               /* VDHP_AccPdlSenRefVoltLowFault_flg */
  false,                               /* VDHP_AuxBattVoltHighInstWarm_flg */
  false,                               /* VDHP_AuxBattVoltHighWarnFault_flg */
  false,                               /* VDHP_AuxBattVoltLowInstWarm_flg */
  false,                               /* VDHP_AuxBattVoltLowWarnFault_flg */
  false,                               /* VDHP_AuxBattVoltHighFltFault_flg */
  false,                               /* VDHP_AuxBattVoltLowFltFault_flg */
  false,                               /* VDHP_VCUtoBMSLossCanNetFault_flg */
  false,                               /* VDHP_VCUtoMCULossCanNetFault_flg */
  false,                               /* VDHP_VCUtoDCDCLossCanNetFault_flg */
  false,                               /* VDHP_WaterPumpFault_flg */
  false,                               /* VDHP_SRSFault_flg */
  false,                               /* VDHP_CoolingSysFault_Flg */
  false,                               /* VDHP_MCUOverSpdFault_Flg */
  false,                               /* VDHP_MCUSysOverTFault_Flg */
  false,                               /* VDHP_MCUFltExitReady_Flg */
  false,                               /* VDHP_Forbid_FeedbackFlg */
  false,                               /* VDHP_Forbid_CreepFlg */
  false,                               /* VDHP_Forbid_CruiseFlg */
  false,                               /* VDHP_VCUtoABSLossCanNetFlt_flg */
  false,                               /* VDHP_BrakeFault_Flg */
  false,                               /* VDHP_VCUtoOBCLossCanNetFault_flg */
  false,                               /* VDHP_AccelPdlRatDeathInstFlt_flg */
  false,                               /* VDHP_AccelPdlRatDeathFault_flg */
  false,                               /* VDHP_VCUBattChrgErr_Flg */
  false,                               /* VDHP_MCUFaultSpeedBased_Flg */
  false,                               /* VDHP_BMSFaultSpeedBased_Flg */
  false,                               /* VDHP_BMSFaultTimeBased_Flg */
  false,                               /* VDHP_CruiseHWFault_Flg */
  false,                               /* VDHP_VCUtoABS232LossCanNetFault_flg */
  false,                               /* VDHP_VCUtoICM235LossCanNetFault_flg */
  false,                               /* VDHP_VehFaultLight_flg */
  false,                               /* VDHP_CalDataCorrupted_flg */
  false,                               /* VDHP_VCUFaultSpeedBased_Flg */
  false,                               /* VDHP_PwrLimitLight_flg */
  false                                /* VDHP_PwrLimitbyBMS_flg */
} ;                                    /* DHP ground */

#pragma pop

/* Exported block signals */
DHP DHP_output;                        /* '<S1>/Bus Creator' */
real32_T VDSF_AccelPedalL_V;           /* '<S2244>/Data Type Conversion7' */
real32_T VDSF_AccelPedalH_V;           /* '<S2244>/Data Type Conversion8' */
uint32_T VDHP_LS1to10FaultCode;        /* '<S4>/Delay1' */
uint32_T VDHP_HVIL_PulseTime_us;       /* '<S701>/Data Store Read2' */
uint32_T VDHP_LS1to10FaultCode_PwrOn;  /* '<S600>/Data Store Read' */
uint16_T VDSF_VacuumPumpIn_Hz;         /* '<S2249>/Data Type Conversion' */
uint16_T VDHP_AllResponseBits;         /* '<S26>/Switch' */
uint8_T VDSF_CollisionFreIn_Hz;        /* '<S2244>/Data Type Conversion' */
uint8_T VDSF_CollisionDutyIn_pct;      /* '<S2244>/Data Type Conversion1' */
uint8_T VDSF_HVInterlockFreIn_Hz;      /* '<S2244>/Data Type Conversion12' */
uint8_T VDSF_WaterPwmIn_Duty;          /* '<S2250>/Data Type Conversion' */
uint8_T VDSF_WaterPwmIn_Hz;            /* '<S2251>/Data Type Conversion' */
uint8_T VDHP_deltaSystemTick_ms;       /* '<S1>/Data Type Conversion' */
uint8_T VDHP_GearOut_enum;             /* '<S10>/Data Type Conversion' */
uint8_T VDHP_VPEPS_Result_enum;        /* '<S1055>/Data Type  Conversion' */
uint8_T VDHP_HSFaultCode_PwrOn;        /* '<S599>/Data Store Read' */
uint8_T VDHP_MaxFaultLever_Light;      /* '<S25>/Switch1' */
uint8_T VDHP_Spd_Limit;                /* '<S29>/Switch' */
uint8_T VDHP_Pwr_Limit_Pct;            /* '<S28>/Switch' */
uint8_T VDHP_MaxFaultLever;            /* '<S25>/Switch' */
boolean_T VDSF_BrkSwitch1;             /* '<S2244>/Data Type Conversion2' */
boolean_T VDSF_BrkSwitch2;             /* '<S2244>/Data Type Conversion3' */
boolean_T VDSF_GearSwitch1Active_flg;  /* '<S2245>/Data Type Conversion' */
boolean_T VDSF_GearSwitch2Active_flg;  /* '<S2246>/Data Type Conversion' */
boolean_T VDSF_GearSwitch3Active_flg;  /* '<S2247>/Data Type Conversion' */
boolean_T VDSF_GearSwitch4Active_flg;  /* '<S2248>/Data Type Conversion' */
boolean_T VDHP_DisRecordDTC;           /* '<S1>/Data Store Read' */
boolean_T VDHP_NMSleepInd_flg;         /* '<S4>/Data Type Conversion7' */
boolean_T VDHP_VCU_Up_flg;             /* '<S4>/Relational Operator' */
boolean_T VDHP_AccPedalFault_Flg;      /* '<S482>/Relational Operator' */
boolean_T VDHP_BMSFailTimeBased_Flg;   /* '<S483>/Logical Operator' */
boolean_T VDHP_BMSFault_Flg;           /* '<S483>/Relational Operator' */
boolean_T VDHP_BrakeSysFault_Flg;      /* '<S484>/Logical Operator' */
boolean_T VDHP_CoolingSysFault_Flg;    /* '<S495>/Relational Operator' */
boolean_T VDHP_CruiseHWFault_Flg;      /* '<S496>/Relational Operator' */
boolean_T VDHP_DCDCFault_Flg;          /* '<S497>/Relational Operator' */
boolean_T VDHP_VCUBattChrgErr_Flg;     /* '<S497>/Relational Operator1' */
boolean_T VDHP_GearSingleNotInAeraFlt_Flg;/* '<S498>/Relational Operator' */
boolean_T VDHP_MCUFltExitReady_Flg;    /* '<S505>/Compare' */
boolean_T VDHP_MCUFault_Flg;           /* '<S506>/Compare' */
boolean_T VDHP_MCUFaultSpeedBased_Flg; /* '<S499>/Logical Operator' */
boolean_T VDHP_MCUSysOverTFault_Flg;   /* '<S499>/Relational Operator' */
boolean_T VDHP_OBCFault_Flg;           /* '<S500>/Relational Operator' */
boolean_T VDHP_VCUFaultSpeedBased_Flg; /* '<S501>/Relational Operator' */
boolean_T VDHP_BMSInstFlt2_NoErrNum;   /* '<S1124>/Logical Operator31' */
boolean_T VDHP_BMSInstFlt3_RecoveryFlg;/* '<S1124>/Logical Operator32' */
boolean_T VDHP_BMSInstFlt2_RecoveryFlg;/* '<S1124>/Logical Operator34' */
boolean_T VDHP_BMSInstFlt4_flg;        /* '<S1124>/Logical Operator6' */
boolean_T VDHP_BMSInstFlt3_NoErrNum;   /* '<S1124>/Logical Operator8' */
boolean_T VDHP_BMSInstFlt4_NoErrNum;   /* '<S1124>/Logical Operator9' */
boolean_T VDHP_BMSInstFlt3_flg;        /* '<S1124>/Switch' */
boolean_T VDHP_BMSInstFlt2_flg;        /* '<S1124>/Switch1' */
boolean_T VDHP_BMSDischrgPwrAbnormalInstFlt_flg;/* '<S1123>/Logical Operator15' */
boolean_T VDHP_EPSWorkInstFlt_flg;     /* '<S1037>/Logical Operator1' */
boolean_T VDHP_MCUSpdInvalid_flg;      /* '<S1037>/Logical Operator10' */
boolean_T VDHP_ESPWorkErrInstFlt_flg;  /* '<S1037>/Logical Operator11' */
boolean_T VDHP_SpeedInvalidInstFlt_flg;/* '<S1037>/Logical Operator13' */
boolean_T VDHP_EBDWorkInstFlt_flg;     /* '<S1037>/Logical Operator2' */
boolean_T VDHP_EPBWorkInstFlt_flg;     /* '<S1037>/Logical Operator3' */
boolean_T VDHP_ABSWorkInstFlt_flg;     /* '<S1037>/Logical Operator4' */
boolean_T VDHP_ABSVehicleSpeedInvalid_flg;/* '<S1037>/Logical Operator8' */
boolean_T VDHP_MCUTrqInvalid_flg;      /* '<S1037>/Logical Operator9' */
boolean_T VDHP_DcdcFlt2_flg;           /* '<S1049>/Logical Operator4' */
boolean_T VDHP_MCUModErrInstFlt_flg;   /* '<S1053>/Logical Operator1' */
boolean_T VDHP_DCDCModErrInstFlt_flg;  /* '<S1053>/Logical Operator2' */
boolean_T VDHP_BMSModErrInstFlt_flg;   /* '<S1053>/Logical Operator4' */
boolean_T VDHP_ObcFlt2_flg;            /* '<S1054>/Logical Operator17' */
boolean_T VDHP_ObcFlt3_flg;            /* '<S1054>/Logical Operator19' */
boolean_T VDHP_VacPumpHardwireInstFlt_flg;/* '<S1056>/Switch' */
boolean_T VDHP_WaterPumpHardwireInstFlt_flg;/* '<S1056>/Switch1' */
boolean_T VDHP_Authentication_flg;     /* '<S1034>/Data Type Conversion' */
boolean_T VDHP_PEPSFailedInstFlt_flg;  /* '<S1055>/Logical Operator4' */
boolean_T VDHP_TMSReqInvalid_flg;      /* '<S1064>/Compare' */
boolean_T VDHP_WaterPump_InstFlt2_flg; /* '<S1086>/Logical Operator1' */
boolean_T VDHP_WaterPumpPWMInstFlt_flg;/* '<S1086>/Logical Operator2' */
boolean_T VDHP_WaterPump_InstFlt1_flg; /* '<S1086>/Logical Operator5' */
boolean_T VDHP_VacHzInstFlt2_flg;      /* '<S1085>/Logical Operator4' */
boolean_T VDHP_VacHzInstFlt1_flg;      /* '<S1085>/Logical Operator5' */
boolean_T VDHP_EsclLinCommFailed_flg;  /* '<S1065>/Compare' */
boolean_T VDHP_EsclChipHWFailed_flg;   /* '<S1066>/Compare' */
boolean_T VDHP_EsclMotorNoAct_flg;     /* '<S1067>/Compare' */
boolean_T VDHP_EsclMasterReqTimeout_flg;/* '<S1068>/Compare' */
boolean_T VDHP_EsclUnlockTimeout_flg;  /* '<S1069>/Compare' */
boolean_T VDHP_EsclLockTimeout_flg;    /* '<S1070>/Compare' */
boolean_T VDHP_EsclMasterIReqInvalid_flg;/* '<S1071>/Compare' */
boolean_T VDHP_EsclLockGndFailed_flg;  /* '<S1072>/Compare' */
boolean_T VDHP_EsclSensorStsFailed_flg;/* '<S1073>/Compare' */
boolean_T VDHP_EsclMotorDriverFailed_flg;/* '<S1074>/Compare' */
boolean_T VDHP_EsclSensorHWFailed_flg; /* '<S1075>/Compare' */
boolean_T VDHP_EsclMotorOverload_flg;  /* '<S1076>/Compare' */
boolean_T VDHP_EsclPwrSupplyFailed_flg;/* '<S1077>/Compare' */
boolean_T VDHP_EsclEEPROMFailed_flg;   /* '<S1078>/Compare' */
boolean_T VDHP_EsclAuthenticFailed_flg;/* '<S1079>/Compare' */
boolean_T VDHP_DCChrgPortOverT2InstFlt_flg;/* '<S1048>/Logical Operator1' */
boolean_T VDHP_DCChrgPortOverT1InstFlt_flg;/* '<S1048>/Logical Operator4' */
boolean_T VDHP_MCUCANComInstFlt_Flg;   /* '<S862>/Logical Operator3' */
boolean_T VDHP_MCUDcUOverUWarnInstFlt_Flg;/* '<S866>/Switch1' */
boolean_T VDHP_MCUDcUOverUFltInstFlt_Flg;/* '<S866>/Switch4' */
boolean_T VDHP_MCUDcUOverURedundInstFlt_flg;/* '<S867>/Logical Operator1' */
boolean_T VDHP_MCUDcUUnderUWarnInstFlt_Flg;/* '<S868>/Logical Operator3' */
boolean_T VDHP_MCUDischrgInstFlt_Flg;  /* '<S869>/Logical Operator3' */
boolean_T VDHP_MCUElecMotTSnsrRatiInstFlt_Flg;/* '<S872>/Logical Operator3' */
boolean_T VDHP_MCUElecMotOverCrrtInstFlt_Flg;/* '<S873>/Logical Operator3' */
boolean_T VDHP_MCUFltUnmatchInstFlt_Flg;/* '<S874>/Logical Operator12' */
boolean_T VDHP_MCUInstFlt1_flg;        /* '<S874>/Logical Operator2' */
boolean_T VDHP_MCUInstFlt2_flg;        /* '<S874>/Merge' */
boolean_T VDHP_MCUInstFlt3_flg;        /* '<S874>/Merge3' */
boolean_T VDHP_MCUHWCurrOverInstFlt_Flg;/* '<S875>/Logical Operator3' */
boolean_T VDHP_MCUIGBTHWInstFlt_Flg;   /* '<S877>/Logical Operator3' */
boolean_T VDHP_MCULowBattUnderUInstFlt_Flg;/* '<S880>/Logical Operator3' */
boolean_T VDHP_MCUPwrModRedundInstFlt_flg;/* '<S881>/Logical Operator3' */
boolean_T VDHP_MCUTUpRateInstFlt_flg;  /* '<S882>/Logical Operator1' */
boolean_T VDHP_MCUPhaACCrrtSnsrRatiInstFlt_Flg;/* '<S884>/Logical Operator3' */
boolean_T VDHP_MCUElecMotOverSpdWarnInstFlt_Flg;/* '<S890>/Logical Operator3' */
boolean_T VDHP_MCUElecMotOverTWarnInstFlt_Flg;/* '<S891>/Logical Operator3' */
boolean_T VDHP_MCUCoverWarnInstFlt_Flg;/* '<S889>/Logical Operator1' */
boolean_T VDHP_MCUCoverFltInstFlt_Flg; /* '<S889>/Logical Operator15' */
boolean_T VDHP_MCUTorqOuterRangeInstFlt_Flg;/* '<S888>/Logical Operator3' */
boolean_T VDHP_MCUTorqCheckInstFlt_Flg;/* '<S887>/Logical Operator3' */
boolean_T VDHP_MCUTSnsrRatiInstFlt_Flg;/* '<S886>/Logical Operator3' */
boolean_T VDHP_MCUPhaseLossInstFlt_Flg;/* '<S885>/Logical Operator3' */
boolean_T VDHP_MCUOverTInstFlt_Flg;    /* '<S883>/Logical Operator3' */
boolean_T VDHP_MCUIGBTphaseTCheckErrInstFlt_Flg;/* '<S879>/Logical Operator3' */
boolean_T VDHP_MCUIGBTOverTWarnInstFlt_Flg;/* '<S878>/Logical Operator3' */
boolean_T VDHP_MCUHwCurrOverRedundInstFlt_flg;/* '<S876>/Logical Operator3' */
boolean_T VDHP_MCUElecMotStopTurnInstFlt_Flg;/* '<S871>/Logical Operator3' */
boolean_T VDHP_MCUElecMotReslvInstFlt_Flg;/* '<S870>/Logical Operator3' */
boolean_T VDHP_MCUDcUSnsrRatiInstFlt_Flg;/* '<S865>/Logical Operator3' */
boolean_T VDHP_MCUDcCrrtOverURedundInstFlt_flg;/* '<S864>/Logical Operator3' */
boolean_T VDHP_MCUDcUShoCircInstFlt_Flg;/* '<S863>/Logical Operator3' */
boolean_T VDHP_MCUCANBusOffInstFlt_Flg;/* '<S861>/Logical Operator10' */
boolean_T VDHP_MCUDCUOverUHWInstFlt_Flg;/* '<S861>/Logical Operator11' */
boolean_T VDHP_MCUHWSamplingInstFlt_Flg;/* '<S861>/Logical Operator12' */
boolean_T VDHP_MCUChipPowerInstFlt_Flg;/* '<S861>/Logical Operator13' */
boolean_T VDHP_MCUElecMotUnderTInstFlt_Flg;/* '<S861>/Logical Operator3' */
boolean_T VDHP_MCUIGBTUnderTInstFlt_Flg;/* '<S861>/Logical Operator4' */
boolean_T VDHP_MCUElecMotOverSpdFltInstFlt_Flg;/* '<S861>/Logical Operator5' */
boolean_T VDHP_MCUDcUUnderUFltInstFlt_Flg;/* '<S861>/Logical Operator6' */
boolean_T VDHP_MCUElecMotOverTFltInstFlt_Flg;/* '<S861>/Logical Operator7' */
boolean_T VDHP_MCUIGBTOverTFltInstFlt_Flg;/* '<S861>/Logical Operator8' */
boolean_T VDHP_MCUVersionMismatchInstFlt_Flg;/* '<S861>/Logical Operator9' */
boolean_T VDHP_PTCanLossInstFlt_Flg;   /* '<S689>/Logical Operator5' */
boolean_T VDHP_OverDiagnVoltInstFlt_Flg;/* '<S691>/Logical Operator' */
boolean_T VDHP_UnderDiagnVoltInstFlt_Flg;/* '<S691>/Logical Operator1' */
boolean_T VDHP_VehCrashCanSignalInstFlt_flg;/* '<S700>/Logical Operator1' */
boolean_T VDHP_VehCrashHardwareSignalInstFlt_flg;/* '<S700>/Logical Operator13' */
boolean_T VDHP_VehCrashInstFlt_flg;    /* '<S700>/Logical Operator15' */
boolean_T VDHP_VehCrashHardwareCanSignalInstFlt_flg;/* '<S700>/Switch' */
boolean_T VDHP_HVILErrInstFlt_flg;     /* '<S701>/Switch' */
boolean_T HVIL_UpToHVMode_flg;         /* '<S701>/Switch1' */
boolean_T HVIL_VehicleSpeed;           /* '<S701>/Switch2' */
boolean_T VDHP_OBC_CANLoseAuxCondition;/* '<S694>/Logical Operator2' */
boolean_T VDHP_VCUHCanNetLineOffInstFlt_flg;/* '<S695>/Logical Operator1' */
boolean_T VDHP_PTBusOffInstFlt_Flg;    /* '<S698>/Compare' */
boolean_T VDHP_OBCMissingtInstFlt_flg; /* '<S758>/Logical Operator6' */
boolean_T VDHP_NMLiphomeInstFlt_flg;   /* '<S757>/Logical Operator5' */
boolean_T VDHP_ICMLossCanNetInstFlt_flg;/* '<S755>/Switch' */
boolean_T VDHP_GWLossCanNetInstFlt_flg;/* '<S754>/Switch' */
boolean_T VDHP_DCDCMissingInstFlt_flg; /* '<S749>/Logical Operator3' */
boolean_T BMS_304LossCanNetInstFlt_flg;/* '<S771>/DHP_systemtick_Timer' */
boolean_T BMS_513LossCanNetInstFlt_flg;/* '<S772>/DHP_systemtick_Timer' */
boolean_T BMS_603LossCanNetInstFlt_flg;/* '<S773>/DHP_systemtick_Timer' */
boolean_T BMS_613LossCanNetInstFlt_flg;/* '<S774>/DHP_systemtick_Timer' */
boolean_T BMS_623LossCanNetInstFlt_flg;/* '<S777>/DHP_systemtick_Timer' */
boolean_T BMS_213LossCanNetInstFlt_flg;/* '<S781>/DHP_systemtick_Timer' */
boolean_T BMS_377LossCanNetInstFlt_flg;/* '<S782>/DHP_systemtick_Timer' */
boolean_T BMS_233LossCanNetInstFlt_flg;/* '<S783>/DHP_systemtick_Timer' */
boolean_T BMS_303LossCanNetInstFlt_flg;/* '<S784>/DHP_systemtick_Timer' */
boolean_T BMS_653LossCanNetInstFlt_flg;/* '<S785>/DHP_systemtick_Timer' */
boolean_T BMS_323LossCanNetInstFlt_flg;/* '<S786>/DHP_systemtick_Timer' */
boolean_T VDHP_BMSMissingInstFlt_flg;  /* '<S727>/Logical Operator19' */
boolean_T VDHP_ABSLossCanNetInstFlt_flg;/* '<S726>/Switch' */
boolean_T VDHP_DCDCStopworkTOInstFlt_flg;/* '<S522>/VPMM_DCDCStopworkTimeout_flg' */
boolean_T VDHP_HVActiveTOInstFlt_flg;  /* '<S522>/VPMM_HVActiveTimeout_flg' */
boolean_T VDHP_HVDCDCActiveTOInstFlt_flg;/* '<S522>/VPMM_HVDCDCActiveTimeout_flg' */
boolean_T VDHP_HVDownTOInstFlt_flg;    /* '<S522>/VPMM_HVDownTimeout_flg' */
boolean_T VDHP_HVUpTOInstFlt_flg;      /* '<S522>/VPMM_HVUpTimeout_flg' */
boolean_T VDHP_LVUpBMSPwrUpAllwTOInstFlt_flg;/* '<S522>/VPMM_LVUpBMSPwrUpAllwTimeout_flg' */
boolean_T VDHP_LVUpBMSTOInstFlt_flg;   /* '<S522>/VPMM_LVUpBMSTimeout_flg' */
boolean_T VDHP_LVUpDCDCTOInstFlt_flg;  /* '<S522>/VPMM_LVUpDCDCTimeout_flg' */
boolean_T VDHP_LVUpMCUTOInstFlt_flg;   /* '<S522>/VPMM_LVUpMCUTimeout_flg' */
boolean_T VDHP_MCUDischargeTOInstFlt_flg;/* '<S522>/VPMM_MCUDischargeTimeout_flg' */
boolean_T VDHP_MCUExitTorqTOInstFlt_flg;/* '<S522>/VPMM_MCUExitTorqTimeout_flg' */
boolean_T VDHP_MCUHVActiveTOInstFlt_flg;/* '<S522>/VPMM_MCUHVActiveTimeout_flg' */
boolean_T VDHP_AuxBattVoltHighInstWarm_flg;/* '<S531>/Switch' */
boolean_T VDHP_AuxBattVoltLowInstWarm_flg;/* '<S531>/Switch1' */
boolean_T VDHP_AuxBattVoltHighInstFlt_flg;/* '<S555>/Logical Operator6' */
boolean_T VDHP_AuxBattVoltLowInstFlt_flg;/* '<S555>/Logical Operator8' */
boolean_T VDHP_AccPdl_Judgment_Condition;/* '<S528>/Logical Operator6' */
boolean_T VDHP_AccPdlSenRefVoltLowInstFlt_flg;/* '<S543>/Switch1' */
boolean_T VDHP_AccPdlSenRefVoltHighInstFlt_flg;/* '<S543>/Switch' */
boolean_T VDHP_AccPdlHLVoltPrecondition;/* '<S544>/Logical Operator1' */
boolean_T VDHP_AccPdlHVoltLowInstFlt_flg;/* '<S544>/Logical Operator2' */
boolean_T VDHP_AccPdlHVoltHighInstFlt_flg;/* '<S544>/Logical Operator3' */
boolean_T VDHP_AccPdlLVoltLowInstFlt_flg;/* '<S544>/Logical Operator4' */
boolean_T VDHP_AccPdlLVoltHighInstFlt_flg;/* '<S544>/Logical Operator5' */
boolean_T VDHP_AccelPdlRatPrecondition;/* '<S545>/Logical Operator1' */
boolean_T VDHP_AccelPdlRatInstFlt_flg; /* '<S545>/Logical Operator2' */
boolean_T VDHP_AccelPdlRatDeathInstFlt_flg;/* '<S546>/Logical Operator2' */
boolean_T VDHP_AccPdlLHVoltDeathInstFlt_flg;/* '<S544>/Logical Operator11' */
boolean_T VDHP_Basc_Auxiliary_Judgment_Condition;/* '<S528>/Logical Operator2' */
boolean_T VDHP_BrkDSCheck0InstFlt_flg; /* '<S560>/Logical Operator' */
boolean_T VDHP_BrkDSCheck1InstFlt_flg; /* '<S560>/Logical Operator1' */
boolean_T VDHP_CoolSysFlt_Auxiliary_Judgment_Condition;/* '<S535>/Logical Operator' */
boolean_T VDHP_CoolSysErrInstFlt_flg;  /* '<S565>/Logical Operator7' */
boolean_T VDHP_ChrgStopLockErrInstFlt_flg;/* '<S528>/Data Store Read10' */
boolean_T VDHP_OBCWakeupTOInstFlt_flg; /* '<S528>/Data Store Read11' */
boolean_T VDHP_AppDataCheckFaliedInstFlt_flg;/* '<S528>/Data Store Read13' */
boolean_T VDHP_HistDataCheckFaliedInstFlt_flg;/* '<S528>/Data Store Read14' */
boolean_T VDHP_ChrgFaultInstFlt_flg;   /* '<S528>/Data Store Read2' */
boolean_T VDHP_ChrgModeInvalidInstFlt_flg;/* '<S528>/Data Store Read3' */
boolean_T VDHP_ChrgModeAbnormalInstFlt_flg;/* '<S528>/Data Store Read4' */
boolean_T VDHP_ChrgLockCheckTOInstFlt_flg;/* '<S528>/Data Store Read5' */
boolean_T VDHP_ShiftKnobCheckTOInstFlt_flg;/* '<S528>/Data Store Read6' */
boolean_T VDHP_ChrgStopAbnormalInstFlt_flg;/* '<S528>/Data Store Read7' */
boolean_T VDHP_ChrgStopOperTOInstFlt_flg;/* '<S528>/Data Store Read8' */
boolean_T VDHP_ChrgStopModeInvalidInstFlt_flg;/* '<S528>/Data Store Read9' */
boolean_T VDHP_GearSingleNotInAeraInstFlt_flg;/* '<S536>/Switch' */
boolean_T VDHP_HVPwrUpTimeoutInstFlt_flg;/* '<S587>/Logical Operator1' */
boolean_T VDHP_ChrgReqLimFacInstFlt_flg;/* '<S590>/Compare' */
boolean_T VDHP_VCUHwLS1ErrInstFlt_flg; /* '<S591>/Switch' */
boolean_T VDHP_VCUHwLS2ErrInstFlt_flg; /* '<S591>/Switch1' */
boolean_T VDHP_VCUHwLS3ErrInstFlt_flg; /* '<S591>/Switch2' */
boolean_T VDHP_VCUHwLS4ErrInstFlt_flg; /* '<S591>/Switch3' */
boolean_T VDHP_VCUHwLS5ErrInstFlt_flg; /* '<S591>/Switch4' */
boolean_T VDHP_VCUHwLS6ErrInstFlt_flg; /* '<S591>/Switch5' */
boolean_T VDHP_VCUHwLS7ErrInstFlt_flg; /* '<S591>/Switch6' */
boolean_T VDHP_VCUHwLS8ErrInstFlt_flg; /* '<S591>/Switch7' */
boolean_T VDHP_VCUHwHS1ErrInstFlt_flg; /* '<S591>/Switch8' */
boolean_T VDHP_DidDataCheckFailedInstFlt_flg;/* '<S661>/Compare' */
boolean_T VDHP_CalDataCheckFailedInstFlt_flg;/* '<S662>/Compare' */
boolean_T VDHP_CruiseKeyOpenInstFlt_flg;/* '<S592>/Switch' */
boolean_T VDHP_gbInvalidWriteToCalAreaInstFlt_flg;/* '<S659>/Compare' */
boolean_T VDHP_IGN1FeedVErrInstFlt_flg;/* '<S557>/Compare' */
boolean_T VDHP_IGN2FeedVErrInstFlt_flg;/* '<S558>/Compare' */
boolean_T VDHP_SSBSyncErrInstFlt_flg;  /* '<S559>/Compare' */
boolean_T VDHP_VCURegenAbnormal_flg;   /* '<S670>/Switch1' */
boolean_T VDHP_CruiseKeyShortedInstFlt_flg;/* '<S665>/Compare' */
boolean_T VDHP_VCUHwLSIGN1InstFlt_flg; /* '<S628>/Logical Operator1' */
boolean_T VDHP_VCUHWLSEsclPwrInstFlt_flg;/* '<S628>/Logical Operator17' */
boolean_T VDHP_VCUHwLSIGN2InstFlt_flg; /* '<S628>/Logical Operator5' */
boolean_T VDHP_Forbid_PTCFlg;          /* '<S27>/Switch' */
boolean_T VDHP_OFFMainRelayFlg;        /* '<S27>/Switch1' */
boolean_T VDHP_Forbid_DCDCFlg;         /* '<S27>/Switch10' */
boolean_T VDHP_Forbid_ActiveDischargeFlg;/* '<S27>/Switch11' */
boolean_T VDHP_Forbid_PreChargeFlg;    /* '<S27>/Switch12' */
boolean_T VDHP_Forbid_CruiseFlg;       /* '<S27>/Switch13' */
boolean_T VDHP_OFFAllHVRelayFlg;       /* '<S27>/Switch2' */
boolean_T VDHP_MCU_DisEnableFlg;       /* '<S27>/Switch3' */
boolean_T VDHP_Forbid_ChargeFlg;       /* '<S27>/Switch4' */
boolean_T VDHP_Forbid_CreepFlg;        /* '<S27>/Switch5' */
boolean_T VDHP_Forbid_FeedbackFlg;     /* '<S27>/Switch6' */
boolean_T VDHP_Forbid_ConditionFlg;    /* '<S27>/Switch7' */
boolean_T VDHP_Normal_PowerDownFlg;    /* '<S27>/Switch8' */
boolean_T VDHP_Off_DeviceRelayFlg;     /* '<S27>/Switch9' */
boolean_T VDHP_BMSBatt_OverTFlt_flg;   /* '<S1142>/Relational Operator' */
boolean_T VDHP_BMSCell_UnderUFlt_flg;  /* '<S1141>/Relational Operator' */
boolean_T VDHP_BMSCell_OverUFlt_flg;   /* '<S1140>/Relational Operator' */
boolean_T VDHP_BMS_UnderUFlt_flg;      /* '<S1139>/Relational Operator' */
boolean_T VDHP_BMS_OverUFlt_flg;       /* '<S1138>/Relational Operator' */
boolean_T VDHP_TestWorkDelay4s_Flg;    /* '<S1122>/Relational Operator' */
boolean_T VDHP_MCUWakeupWork_Flg;      /* '<S1121>/Relational Operator' */
boolean_T VDHP_VCUPowerUpDelay2SWork_Flg;/* '<S1120>/Relational Operator' */
boolean_T VDHP_BMSWakeupWork_Flg;      /* '<S1115>/Relational Operator' */
boolean_T VDHP_HVPowerUpDelay2SWork_Flg;/* '<S1114>/Relational Operator' */
boolean_T VDHP_XBSLossCanNetInstFlt_flg;/* '<S846>/Relational Operator' */
boolean_T VDHP_TMSLossCanNetInstFlt_flg;/* '<S844>/Relational Operator' */
boolean_T VDHP_TBOXLossCanNetInstFlt_flg;/* '<S842>/Relational Operator' */
boolean_T VDHP_OBCLossCanNetInstFlt_flg;/* '<S840>/Relational Operator' */
boolean_T MCU215LossCanNetInstFlt_flg; /* '<S830>/Relational Operator' */
boolean_T MCU515LossCanNetInstFlt_flg; /* '<S829>/Relational Operator' */
boolean_T MCU115LossCanNetInstFlt_flg; /* '<S828>/Relational Operator' */
boolean_T MCU125LossCanNetInstFlt_flg; /* '<S827>/Relational Operator' */
boolean_T VDHP_ICM235MissingInstFlt_flg;/* '<S822>/Relational Operator' */
boolean_T VDHP_EPSLossCanNetInstFlt_flg;/* '<S816>/Relational Operator' */
boolean_T VDHP_EHULossCanNetInstFlt_flg;/* '<S814>/Relational Operator' */
boolean_T VDHP_ECCLossCanNetInstFlt_flg;/* '<S813>/Relational Operator' */
boolean_T VDHP_EACLossCanNetInstFlt_flg;/* '<S811>/Relational Operator' */
boolean_T VDHP_DCDCLossCanNetInstFlt_flg;/* '<S810>/Relational Operator' */
boolean_T BMS_633LossCanNetInstFlt_flg;/* '<S798>/Relational Operator' */
boolean_T BMS_113LossCanNetInstFlt_flg;/* '<S797>/Relational Operator' */
boolean_T VDHP_BMSLossCanNetInstFlt_flg;/* '<S796>/Relational Operator' */
boolean_T BMS_313LossCanNetInstFlt_flg;/* '<S788>/Relational Operator' */
boolean_T VDHP_ABS232MissingInstFlt_flg;/* '<S768>/Relational Operator' */
boolean_T VDHP_CruiseKeyResFlt_flg;    /* '<S669>/Relational Operator' */
boolean_T VDHP_CruiseKeySetFlt_flg;    /* '<S668>/Relational Operator' */
boolean_T VDHP_ACCHWSignalInstFlt_flg; /* '<S586>/Relational Operator' */

/* Block signals (auto storage) */
#pragma push
#pragma DATA_SEG __GPAGE_SEG GPAGED_RAM

B_DHP_model_T DHP_model_B;

#pragma pop

/* Block states (auto storage) */

#pragma push
#pragma DATA_SEG __GPAGE_SEG GPAGED_RAM

DW_DHP_model_T DHP_model_DW;

#pragma pop

/* Previous zero-crossings (trigger) states */

#pragma push
#pragma DATA_SEG __GPAGE_SEG GPAGED_RAM

PrevZCX_DHP_model_T DHP_model_PrevZCX;

#pragma pop

/* Model step function */
void DHP_model_step(void)
{
  /* Outputs for Atomic SubSystem: '<S2>/DHP_Sub_HardwireSignal_Filter' */
  DHP_model_DHP_Sub_HardwireSignal_Filter();

  /* End of Outputs for SubSystem: '<S2>/DHP_Sub_HardwireSignal_Filter' */

  /* Outputs for Atomic SubSystem: '<Root>/DHP' */
  DHP_model_DHP();

  /* End of Outputs for SubSystem: '<Root>/DHP' */
}

/* Model initialize function */
void DHP_model_initialize(void)
{
  /* Registration code */

  /* block I/O */
  (void) memset(((void *) &DHP_model_B), 0,
                sizeof(B_DHP_model_T));

  {
    DHP_model_B.VHALI_Sensor5V1_V = 0.0F;
    DHP_model_B.VHALI_LVBattVoltage_V = 0.0F;
    DHP_model_B.VHALI_Sensor5V2_V = 0.0F;
    DHP_model_B.VINP_BMSBattUOverU = 0.0F;
    DHP_model_B.VINP_BMSBattUUnderU = 0.0F;
    DHP_model_B.VINP_BMSCellUMaxOverU = 0.0F;
    DHP_model_B.VINP_BMSCellUMinUnderU = 0.0F;
    DHP_model_B.VINP_BMSMaxDchaPwr_kW = 0.0F;
  }

  /* exported global signals */
  DHP_output = DHP_model_rtZDHP;
  VDSF_AccelPedalL_V = 0.0F;
  VDSF_AccelPedalH_V = 0.0F;
  VDHP_LS1to10FaultCode = 0U;
  VDHP_HVIL_PulseTime_us = 0U;
  VDHP_LS1to10FaultCode_PwrOn = 0U;
  VDSF_VacuumPumpIn_Hz = 0U;
  VDHP_AllResponseBits = 0U;
  VDSF_CollisionFreIn_Hz = 0U;
  VDSF_CollisionDutyIn_pct = 0U;
  VDSF_HVInterlockFreIn_Hz = 0U;
  VDSF_WaterPwmIn_Duty = 0U;
  VDSF_WaterPwmIn_Hz = 0U;
  VDHP_deltaSystemTick_ms = 0U;
  VDHP_GearOut_enum = 0U;
  VDHP_VPEPS_Result_enum = 0U;
  VDHP_HSFaultCode_PwrOn = 0U;
  VDHP_MaxFaultLever_Light = 0U;
  VDHP_Spd_Limit = 0U;
  VDHP_Pwr_Limit_Pct = 0U;
  VDHP_MaxFaultLever = 0U;
  VDSF_BrkSwitch1 = false;
  VDSF_BrkSwitch2 = false;
  VDSF_GearSwitch1Active_flg = false;
  VDSF_GearSwitch2Active_flg = false;
  VDSF_GearSwitch3Active_flg = false;
  VDSF_GearSwitch4Active_flg = false;
  VDHP_DisRecordDTC = false;
  VDHP_NMSleepInd_flg = false;
  VDHP_VCU_Up_flg = false;
  VDHP_AccPedalFault_Flg = false;
  VDHP_BMSFailTimeBased_Flg = false;
  VDHP_BMSFault_Flg = false;
  VDHP_BrakeSysFault_Flg = false;
  VDHP_CoolingSysFault_Flg = false;
  VDHP_CruiseHWFault_Flg = false;
  VDHP_DCDCFault_Flg = false;
  VDHP_VCUBattChrgErr_Flg = false;
  VDHP_GearSingleNotInAeraFlt_Flg = false;
  VDHP_MCUFltExitReady_Flg = false;
  VDHP_MCUFault_Flg = false;
  VDHP_MCUFaultSpeedBased_Flg = false;
  VDHP_MCUSysOverTFault_Flg = false;
  VDHP_OBCFault_Flg = false;
  VDHP_VCUFaultSpeedBased_Flg = false;
  VDHP_BMSInstFlt2_NoErrNum = false;
  VDHP_BMSInstFlt3_RecoveryFlg = false;
  VDHP_BMSInstFlt2_RecoveryFlg = false;
  VDHP_BMSInstFlt4_flg = false;
  VDHP_BMSInstFlt3_NoErrNum = false;
  VDHP_BMSInstFlt4_NoErrNum = false;
  VDHP_BMSInstFlt3_flg = false;
  VDHP_BMSInstFlt2_flg = false;
  VDHP_BMSDischrgPwrAbnormalInstFlt_flg = false;
  VDHP_EPSWorkInstFlt_flg = false;
  VDHP_MCUSpdInvalid_flg = false;
  VDHP_ESPWorkErrInstFlt_flg = false;
  VDHP_SpeedInvalidInstFlt_flg = false;
  VDHP_EBDWorkInstFlt_flg = false;
  VDHP_EPBWorkInstFlt_flg = false;
  VDHP_ABSWorkInstFlt_flg = false;
  VDHP_ABSVehicleSpeedInvalid_flg = false;
  VDHP_MCUTrqInvalid_flg = false;
  VDHP_DcdcFlt2_flg = false;
  VDHP_MCUModErrInstFlt_flg = false;
  VDHP_DCDCModErrInstFlt_flg = false;
  VDHP_BMSModErrInstFlt_flg = false;
  VDHP_ObcFlt2_flg = false;
  VDHP_ObcFlt3_flg = false;
  VDHP_VacPumpHardwireInstFlt_flg = false;
  VDHP_WaterPumpHardwireInstFlt_flg = false;
  VDHP_Authentication_flg = false;
  VDHP_PEPSFailedInstFlt_flg = false;
  VDHP_TMSReqInvalid_flg = false;
  VDHP_WaterPump_InstFlt2_flg = false;
  VDHP_WaterPumpPWMInstFlt_flg = false;
  VDHP_WaterPump_InstFlt1_flg = false;
  VDHP_VacHzInstFlt2_flg = false;
  VDHP_VacHzInstFlt1_flg = false;
  VDHP_EsclLinCommFailed_flg = false;
  VDHP_EsclChipHWFailed_flg = false;
  VDHP_EsclMotorNoAct_flg = false;
  VDHP_EsclMasterReqTimeout_flg = false;
  VDHP_EsclUnlockTimeout_flg = false;
  VDHP_EsclLockTimeout_flg = false;
  VDHP_EsclMasterIReqInvalid_flg = false;
  VDHP_EsclLockGndFailed_flg = false;
  VDHP_EsclSensorStsFailed_flg = false;
  VDHP_EsclMotorDriverFailed_flg = false;
  VDHP_EsclSensorHWFailed_flg = false;
  VDHP_EsclMotorOverload_flg = false;
  VDHP_EsclPwrSupplyFailed_flg = false;
  VDHP_EsclEEPROMFailed_flg = false;
  VDHP_EsclAuthenticFailed_flg = false;
  VDHP_DCChrgPortOverT2InstFlt_flg = false;
  VDHP_DCChrgPortOverT1InstFlt_flg = false;
  VDHP_MCUCANComInstFlt_Flg = false;
  VDHP_MCUDcUOverUWarnInstFlt_Flg = false;
  VDHP_MCUDcUOverUFltInstFlt_Flg = false;
  VDHP_MCUDcUOverURedundInstFlt_flg = false;
  VDHP_MCUDcUUnderUWarnInstFlt_Flg = false;
  VDHP_MCUDischrgInstFlt_Flg = false;
  VDHP_MCUElecMotTSnsrRatiInstFlt_Flg = false;
  VDHP_MCUElecMotOverCrrtInstFlt_Flg = false;
  VDHP_MCUFltUnmatchInstFlt_Flg = false;
  VDHP_MCUInstFlt1_flg = false;
  VDHP_MCUInstFlt2_flg = false;
  VDHP_MCUInstFlt3_flg = false;
  VDHP_MCUHWCurrOverInstFlt_Flg = false;
  VDHP_MCUIGBTHWInstFlt_Flg = false;
  VDHP_MCULowBattUnderUInstFlt_Flg = false;
  VDHP_MCUPwrModRedundInstFlt_flg = false;
  VDHP_MCUTUpRateInstFlt_flg = false;
  VDHP_MCUPhaACCrrtSnsrRatiInstFlt_Flg = false;
  VDHP_MCUElecMotOverSpdWarnInstFlt_Flg = false;
  VDHP_MCUElecMotOverTWarnInstFlt_Flg = false;
  VDHP_MCUCoverWarnInstFlt_Flg = false;
  VDHP_MCUCoverFltInstFlt_Flg = false;
  VDHP_MCUTorqOuterRangeInstFlt_Flg = false;
  VDHP_MCUTorqCheckInstFlt_Flg = false;
  VDHP_MCUTSnsrRatiInstFlt_Flg = false;
  VDHP_MCUPhaseLossInstFlt_Flg = false;
  VDHP_MCUOverTInstFlt_Flg = false;
  VDHP_MCUIGBTphaseTCheckErrInstFlt_Flg = false;
  VDHP_MCUIGBTOverTWarnInstFlt_Flg = false;
  VDHP_MCUHwCurrOverRedundInstFlt_flg = false;
  VDHP_MCUElecMotStopTurnInstFlt_Flg = false;
  VDHP_MCUElecMotReslvInstFlt_Flg = false;
  VDHP_MCUDcUSnsrRatiInstFlt_Flg = false;
  VDHP_MCUDcCrrtOverURedundInstFlt_flg = false;
  VDHP_MCUDcUShoCircInstFlt_Flg = false;
  VDHP_MCUCANBusOffInstFlt_Flg = false;
  VDHP_MCUDCUOverUHWInstFlt_Flg = false;
  VDHP_MCUHWSamplingInstFlt_Flg = false;
  VDHP_MCUChipPowerInstFlt_Flg = false;
  VDHP_MCUElecMotUnderTInstFlt_Flg = false;
  VDHP_MCUIGBTUnderTInstFlt_Flg = false;
  VDHP_MCUElecMotOverSpdFltInstFlt_Flg = false;
  VDHP_MCUDcUUnderUFltInstFlt_Flg = false;
  VDHP_MCUElecMotOverTFltInstFlt_Flg = false;
  VDHP_MCUIGBTOverTFltInstFlt_Flg = false;
  VDHP_MCUVersionMismatchInstFlt_Flg = false;
  VDHP_PTCanLossInstFlt_Flg = false;
  VDHP_OverDiagnVoltInstFlt_Flg = false;
  VDHP_UnderDiagnVoltInstFlt_Flg = false;
  VDHP_VehCrashCanSignalInstFlt_flg = false;
  VDHP_VehCrashHardwareSignalInstFlt_flg = false;
  VDHP_VehCrashInstFlt_flg = false;
  VDHP_VehCrashHardwareCanSignalInstFlt_flg = false;
  VDHP_HVILErrInstFlt_flg = false;
  HVIL_UpToHVMode_flg = false;
  HVIL_VehicleSpeed = false;
  VDHP_OBC_CANLoseAuxCondition = false;
  VDHP_VCUHCanNetLineOffInstFlt_flg = false;
  VDHP_PTBusOffInstFlt_Flg = false;
  VDHP_OBCMissingtInstFlt_flg = false;
  VDHP_NMLiphomeInstFlt_flg = false;
  VDHP_ICMLossCanNetInstFlt_flg = false;
  VDHP_GWLossCanNetInstFlt_flg = false;
  VDHP_DCDCMissingInstFlt_flg = false;
  BMS_304LossCanNetInstFlt_flg = false;
  BMS_513LossCanNetInstFlt_flg = false;
  BMS_603LossCanNetInstFlt_flg = false;
  BMS_613LossCanNetInstFlt_flg = false;
  BMS_623LossCanNetInstFlt_flg = false;
  BMS_213LossCanNetInstFlt_flg = false;
  BMS_377LossCanNetInstFlt_flg = false;
  BMS_233LossCanNetInstFlt_flg = false;
  BMS_303LossCanNetInstFlt_flg = false;
  BMS_653LossCanNetInstFlt_flg = false;
  BMS_323LossCanNetInstFlt_flg = false;
  VDHP_BMSMissingInstFlt_flg = false;
  VDHP_ABSLossCanNetInstFlt_flg = false;
  VDHP_DCDCStopworkTOInstFlt_flg = false;
  VDHP_HVActiveTOInstFlt_flg = false;
  VDHP_HVDCDCActiveTOInstFlt_flg = false;
  VDHP_HVDownTOInstFlt_flg = false;
  VDHP_HVUpTOInstFlt_flg = false;
  VDHP_LVUpBMSPwrUpAllwTOInstFlt_flg = false;
  VDHP_LVUpBMSTOInstFlt_flg = false;
  VDHP_LVUpDCDCTOInstFlt_flg = false;
  VDHP_LVUpMCUTOInstFlt_flg = false;
  VDHP_MCUDischargeTOInstFlt_flg = false;
  VDHP_MCUExitTorqTOInstFlt_flg = false;
  VDHP_MCUHVActiveTOInstFlt_flg = false;
  VDHP_AuxBattVoltHighInstWarm_flg = false;
  VDHP_AuxBattVoltLowInstWarm_flg = false;
  VDHP_AuxBattVoltHighInstFlt_flg = false;
  VDHP_AuxBattVoltLowInstFlt_flg = false;
  VDHP_AccPdl_Judgment_Condition = false;
  VDHP_AccPdlSenRefVoltLowInstFlt_flg = false;
  VDHP_AccPdlSenRefVoltHighInstFlt_flg = false;
  VDHP_AccPdlHLVoltPrecondition = false;
  VDHP_AccPdlHVoltLowInstFlt_flg = false;
  VDHP_AccPdlHVoltHighInstFlt_flg = false;
  VDHP_AccPdlLVoltLowInstFlt_flg = false;
  VDHP_AccPdlLVoltHighInstFlt_flg = false;
  VDHP_AccelPdlRatPrecondition = false;
  VDHP_AccelPdlRatInstFlt_flg = false;
  VDHP_AccelPdlRatDeathInstFlt_flg = false;
  VDHP_AccPdlLHVoltDeathInstFlt_flg = false;
  VDHP_Basc_Auxiliary_Judgment_Condition = false;
  VDHP_BrkDSCheck0InstFlt_flg = false;
  VDHP_BrkDSCheck1InstFlt_flg = false;
  VDHP_CoolSysFlt_Auxiliary_Judgment_Condition = false;
  VDHP_CoolSysErrInstFlt_flg = false;
  VDHP_ChrgStopLockErrInstFlt_flg = false;
  VDHP_OBCWakeupTOInstFlt_flg = false;
  VDHP_AppDataCheckFaliedInstFlt_flg = false;
  VDHP_HistDataCheckFaliedInstFlt_flg = false;
  VDHP_ChrgFaultInstFlt_flg = false;
  VDHP_ChrgModeInvalidInstFlt_flg = false;
  VDHP_ChrgModeAbnormalInstFlt_flg = false;
  VDHP_ChrgLockCheckTOInstFlt_flg = false;
  VDHP_ShiftKnobCheckTOInstFlt_flg = false;
  VDHP_ChrgStopAbnormalInstFlt_flg = false;
  VDHP_ChrgStopOperTOInstFlt_flg = false;
  VDHP_ChrgStopModeInvalidInstFlt_flg = false;
  VDHP_GearSingleNotInAeraInstFlt_flg = false;
  VDHP_HVPwrUpTimeoutInstFlt_flg = false;
  VDHP_ChrgReqLimFacInstFlt_flg = false;
  VDHP_VCUHwLS1ErrInstFlt_flg = false;
  VDHP_VCUHwLS2ErrInstFlt_flg = false;
  VDHP_VCUHwLS3ErrInstFlt_flg = false;
  VDHP_VCUHwLS4ErrInstFlt_flg = false;
  VDHP_VCUHwLS5ErrInstFlt_flg = false;
  VDHP_VCUHwLS6ErrInstFlt_flg = false;
  VDHP_VCUHwLS7ErrInstFlt_flg = false;
  VDHP_VCUHwLS8ErrInstFlt_flg = false;
  VDHP_VCUHwHS1ErrInstFlt_flg = false;
  VDHP_DidDataCheckFailedInstFlt_flg = false;
  VDHP_CalDataCheckFailedInstFlt_flg = false;
  VDHP_CruiseKeyOpenInstFlt_flg = false;
  VDHP_gbInvalidWriteToCalAreaInstFlt_flg = false;
  VDHP_IGN1FeedVErrInstFlt_flg = false;
  VDHP_IGN2FeedVErrInstFlt_flg = false;
  VDHP_SSBSyncErrInstFlt_flg = false;
  VDHP_VCURegenAbnormal_flg = false;
  VDHP_CruiseKeyShortedInstFlt_flg = false;
  VDHP_VCUHwLSIGN1InstFlt_flg = false;
  VDHP_VCUHWLSEsclPwrInstFlt_flg = false;
  VDHP_VCUHwLSIGN2InstFlt_flg = false;
  VDHP_Forbid_PTCFlg = false;
  VDHP_OFFMainRelayFlg = false;
  VDHP_Forbid_DCDCFlg = false;
  VDHP_Forbid_ActiveDischargeFlg = false;
  VDHP_Forbid_PreChargeFlg = false;
  VDHP_Forbid_CruiseFlg = false;
  VDHP_OFFAllHVRelayFlg = false;
  VDHP_MCU_DisEnableFlg = false;
  VDHP_Forbid_ChargeFlg = false;
  VDHP_Forbid_CreepFlg = false;
  VDHP_Forbid_FeedbackFlg = false;
  VDHP_Forbid_ConditionFlg = false;
  VDHP_Normal_PowerDownFlg = false;
  VDHP_Off_DeviceRelayFlg = false;
  VDHP_BMSBatt_OverTFlt_flg = false;
  VDHP_BMSCell_UnderUFlt_flg = false;
  VDHP_BMSCell_OverUFlt_flg = false;
  VDHP_BMS_UnderUFlt_flg = false;
  VDHP_BMS_OverUFlt_flg = false;
  VDHP_TestWorkDelay4s_Flg = false;
  VDHP_MCUWakeupWork_Flg = false;
  VDHP_VCUPowerUpDelay2SWork_Flg = false;
  VDHP_BMSWakeupWork_Flg = false;
  VDHP_HVPowerUpDelay2SWork_Flg = false;
  VDHP_XBSLossCanNetInstFlt_flg = false;
  VDHP_TMSLossCanNetInstFlt_flg = false;
  VDHP_TBOXLossCanNetInstFlt_flg = false;
  VDHP_OBCLossCanNetInstFlt_flg = false;
  MCU215LossCanNetInstFlt_flg = false;
  MCU515LossCanNetInstFlt_flg = false;
  MCU115LossCanNetInstFlt_flg = false;
  MCU125LossCanNetInstFlt_flg = false;
  VDHP_ICM235MissingInstFlt_flg = false;
  VDHP_EPSLossCanNetInstFlt_flg = false;
  VDHP_EHULossCanNetInstFlt_flg = false;
  VDHP_ECCLossCanNetInstFlt_flg = false;
  VDHP_EACLossCanNetInstFlt_flg = false;
  VDHP_DCDCLossCanNetInstFlt_flg = false;
  BMS_633LossCanNetInstFlt_flg = false;
  BMS_113LossCanNetInstFlt_flg = false;
  VDHP_BMSLossCanNetInstFlt_flg = false;
  BMS_313LossCanNetInstFlt_flg = false;
  VDHP_ABS232MissingInstFlt_flg = false;
  VDHP_CruiseKeyResFlt_flg = false;
  VDHP_CruiseKeySetFlt_flg = false;
  VDHP_ACCHWSignalInstFlt_flg = false;

  /* states (dwork) */
  (void) memset((void *)&DHP_model_DW, 0,
                sizeof(DW_DHP_model_T));
  DHP_model_DW.Delay5_152_DSTATE = 0.0F;
  DHP_model_DW.Delay5_149_DSTATE = 0.0F;
  DHP_model_DW.Delay5_153_DSTATE = 0.0F;
  DHP_model_DW.Delay5_145_DSTATE = 0.0F;
  DHP_model_DW.Delay5_146_DSTATE = 0.0F;
  DHP_model_DW.Delay5_50_DSTATE = 0.0F;
  DHP_model_DW.Delay5_109_DSTATE = 0.0F;
  DHP_model_DW.Delay5_106_DSTATE = 0.0F;
  DHP_model_DW.Delay5_124_DSTATE = 0.0F;
  DHP_model_DW.Delay5_125_DSTATE = 0.0F;
  DHP_model_DW.Delay5_126_DSTATE = 0.0F;
  DHP_model_DW.Delay5_123_DSTATE = 0.0F;
  DHP_model_DW.Delay1_16_DSTATE = 0.0F;
  DHP_model_DW.Delay1_17_DSTATE = 0.0F;
  DHP_model_DW.Delay5_5_DSTATE = 0.0F;
  DHP_model_DW.Delay1_20_DSTATE = 0.0F;
  DHP_model_DW.Delay1_15_DSTATE = 0.0F;
  DHP_model_DW.Delay1_14_DSTATE = 0.0F;
  DHP_model_DW.Delay5_70_DSTATE = 0.0F;
  DHP_model_PrevZCX.CoolErrMotTempUpRate_Trig_ZCE = POS_ZCSIG;

  /* SystemInitialize for Atomic SubSystem: '<Root>/DHP' */
  DHP_model_DHP_Init();

  /* End of SystemInitialize for SubSystem: '<Root>/DHP' */
}

/* Model terminate function */
void DHP_model_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

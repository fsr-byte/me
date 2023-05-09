/*
 * File: DHP.h
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

#ifndef RTW_HEADER_DHP_h_
#define RTW_HEADER_DHP_h_
#include <math.h>
#ifndef DHP_model_COMMON_INCLUDES_
# define DHP_model_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#endif                                 /* DHP_model_COMMON_INCLUDES_ */

#include "DHP_model_types.h"

/* Child system includes */
#include "Funcs_DHP_lib.h"

/* Block signals for system '<S543>/AccPdlSenRefVoltInstFlt' */
typedef struct {
  boolean_T LogicalOperator4;          /* '<S551>/Logical Operator4' */
  boolean_T LogicalOperator5;          /* '<S551>/Logical Operator5' */
} B_AccPdlSenRefVoltInstFlt_DHP_model_T;

/* Block signals for system '<S543>/AccPdlSenRefVoltInstFlt_Test' */
typedef struct {
  boolean_T LogicalOperator4;          /* '<S552>/Logical Operator4' */
  boolean_T LogicalOperator5;          /* '<S552>/Logical Operator5' */
} B_AccPdlSenRefVoltInstFlt_Test_DHP_model_T;

/* Block signals for system '<S531>/LowVoltBatErrState_Test' */
typedef struct {
  boolean_T RelationalOperator;        /* '<S556>/Relational Operator' */
  boolean_T RelationalOperator1;       /* '<S556>/Relational Operator1' */
} B_LowVoltBatErrState_Test_DHP_model_T;

/* Block signals for system '<S12>/VehPowerOnDelayWorkFlagCollect' */
typedef struct {
  boolean_T VINP_15KeyOn_flg;          /* '<S526>/VINP_15KeyOn_flg' */
  B_DHP_systemtick_Timer_DHP_model_k_T DHP_systemtick_Timer_n5;/* '<S1110>/DHP_systemtick_Timer' */
  B_DHP_systemtick_Timer_DHP_model_k_T DHP_systemtick_Timer_g;/* '<S1109>/DHP_systemtick_Timer' */
  B_DHP_systemtick_Timer_DHP_model_k_T DHP_systemtick_Timer_nq;/* '<S1108>/DHP_systemtick_Timer' */
  B_DHP_systemtick_Timer_DHP_model_k_T DHP_systemtick_Timer_d;/* '<S1107>/DHP_systemtick_Timer' */
} B_VehPowerOnDelayWorkFlagCollect_DHP_model_T;

/* Block states (auto storage) for system '<S12>/VehPowerOnDelayWorkFlagCollect' */
typedef struct {
  DW_DHP_systemtick_Timer_DHP_model_b_T DHP_systemtick_Timer_p;/* '<S1113>/DHP_systemtick_Timer' */
  DW_DHP_systemtick_Timer_DHP_model_k_T DHP_systemtick_Timer_o;/* '<S1112>/DHP_systemtick_Timer' */
  DW_DHP_systemtick_Timer_DHP_model_ny_T DHP_systemtick_Timer_f;/* '<S1111>/DHP_systemtick_Timer' */
  DW_DHP_systemtick_Timer_DHP_model_m_T DHP_systemtick_Timer_n5;/* '<S1110>/DHP_systemtick_Timer' */
  DW_DHP_systemtick_Timer_DHP_model_m_T DHP_systemtick_Timer_g;/* '<S1109>/DHP_systemtick_Timer' */
  DW_DHP_systemtick_Timer_DHP_model_m_T DHP_systemtick_Timer_nq;/* '<S1108>/DHP_systemtick_Timer' */
  DW_DHP_systemtick_Timer_DHP_model_m_T DHP_systemtick_Timer_d;/* '<S1107>/DHP_systemtick_Timer' */
  DW_DHP_systemtick_Timer_DHP_model_l_T DHP_systemtick_Timer_n;/* '<S1106>/DHP_systemtick_Timer' */
  DW_DHP_systemtick_Timer_DHP_model_an_T DHP_systemtick_Timer;/* '<S1105>/DHP_systemtick_Timer' */
} DW_VehPowerOnDelayWorkFlagCollect_DHP_model_T;

extern void DHP_model_AccPdlSenRefVoltInstFlt(boolean_T rtu_Enable, uint16_T
  rtu_AccPdlSen1Volt_mv, uint16_T rtu_AccPdlSenVolt2_mv, uint16_T
  rtu_KDHP_AccPdlPowerVoltDownLimValue_mv, uint16_T
  rtu_KDHP_AccPdlPowerVoltUpLimValue_mv, boolean_T
  rtu_Auxiliary_Judgment_Condition, B_AccPdlSenRefVoltInstFlt_DHP_model_T
  *localB);
extern void DHP_model_AccPdlSenRefVoltInstFlt_Test(boolean_T rtu_Enable,
  uint16_T rtu_AccPdlSen1Volt_mv, uint16_T rtu_AccPdlSenVolt2_mv, uint16_T
  rtu_KDHP_AccPdlPowerVoltDownLimValue_mv, uint16_T
  rtu_KDHP_AccPdlPowerVoltUpLimValue_mv, boolean_T rtu_TestWorkDelay2s_flg,
  B_AccPdlSenRefVoltInstFlt_Test_DHP_model_T *localB);
extern void DHP_model_LowVoltBatErrState_Test(boolean_T rtu_Enable, uint16_T
  rtu_Vbatt12_volt_dV, B_LowVoltBatErrState_Test_DHP_model_T *localB);
extern void DHP_model_VehPowerOnDelayWorkFlagCollect(boolean_T
  rtu_VNM_SleepInd_flg, boolean_T rtu_VINP_15KeyOn_flg, boolean_T
  rtu_VHAL_VCUUp_flg, boolean_T rtu_VPMM_HVOn_flg, uint8_T
  rtu_VINP_MCUOperMdl_enum, boolean_T rtu_VPMM_LVEna, uint8_T
  rtu_deltaSystemTick_ms, uint8_T rtu_VINP_BMSOperMdl,
  B_VehPowerOnDelayWorkFlagCollect_DHP_model_T *localB,
  DW_VehPowerOnDelayWorkFlagCollect_DHP_model_T *localDW);
extern void DHP_model_AllFaultPriorityCollect(void);
extern void DHP_model_DHP_FaultStore_Interface(void);
extern void DHP_model_VcuControlDevice1InstErrGenerate_Disable(void);
extern void DHP_model_VcuControlDevice1InstErrGenerate(void);
extern void DHP_model_VcuControlDevice2InstErrGenerate(void);
extern void DHP_model_VehDriveSysInstErrGenerate_Init(void);
extern void DHP_model_VehDriveSysInstErrGenerate(void);
extern void DHP_model_VehOtherDeviceInstErrGenerate(void);
extern void DHP_model_VehPowerSysInstErrGenerate(void);
extern void DHP_model_SysErrProduct2_Init(void);
extern void DHP_model_SysErrProduct2_Disable(void);
extern void DHP_model_SysErrProduct2(void);
extern void DHP_model_AccPdlHVoltHigh(void);
extern void DHP_model_AccPdlHVoltLow(void);
extern void DHP_model_AccPdlLHVoltDeath(void);
extern void DHP_model_AccPdlLVoltHigh(void);
extern void DHP_model_AccPdlLVoltLow(void);
extern void DHP_model_AccPdlSenRefVoltHigh(void);
extern void DHP_model_AccPdlSenRefVoltLow(void);
extern void DHP_model_AccelPdlRat(void);
extern void DHP_model_AccelPdlRatDeath(void);
extern void DHP_model_ACC_Fault(void);
extern void DHP_model_OverDiagnVolt(void);
extern void DHP_model_PTBusOff(void);
extern void DHP_model_PTCanLoss(void);
extern void DHP_model_UnderDiagnVolt(void);
extern void DHP_model_BUSOFF_Fault(void);
extern void DHP_model_IGN1FeedVoltFlt(void);
extern void DHP_model_IGN2FeedVoltFlt(void);
extern void DHP_model_SSBSyncFlt(void);
extern void DHP_model_VCUHwLSEsclPwrFlt(void);
extern void DHP_model_VCUHwLSIGN1Flt(void);
extern void DHP_model_VCUHwLSIGN2Flt(void);
extern void DHP_model_BlueToothKey_Fault(void);
extern void DHP_model_BrkDSCheck0(void);
extern void DHP_model_BrkDSCheck1(void);
extern void DHP_model_Brk_Fault(void);
extern void DHP_model_ABS232Missing(void);
extern void DHP_model_ABSLossCanNet(void);
extern void DHP_model_BMS113Missing(void);
extern void DHP_model_BMS303Missing(void);
extern void DHP_model_BMSLossCanNet(void);
extern void DHP_model_BMSMissing(void);
extern void DHP_model_DCDCLossCanNet(void);
extern void DHP_model_DCDCMissing(void);
extern void DHP_model_EACLossCanNet(void);
extern void DHP_model_ECCLossCanNet(void);
extern void DHP_model_EHULossCanNet(void);
extern void DHP_model_EPSLossCanNet(void);
extern void DHP_model_GWLossCanNet(void);
extern void DHP_model_ICMLossCanNet(void);
extern void DHP_model_MCULossCanNet(void);
extern void DHP_model_MCUMissing(void);
extern void DHP_model_NMLipHome(void);
extern void DHP_model_OBCLossCanNet(void);
extern void DHP_model_OBCMissing(void);
extern void DHP_model_SRSLossCanNet(void);
extern void DHP_model_TBOXLossCanNet(void);
extern void DHP_model_TMSLossCanNet(void);
extern void DHP_model_XBSLossCanNet(void);
extern void DHP_model_CANComm_Fault(void);
extern void DHP_model_CoolSysErr(void);
extern void DHP_model_CoolSys_Fault(void);
extern void DHP_model_GearSingleNotInAera(void);
extern void DHP_model_Gear_Fault(void);
extern void DHP_model_AuxBattVoltHighFlt(void);
extern void DHP_model_AuxBattVoltHighWarn(void);
extern void DHP_model_AuxBattVoltLowFlt(void);
extern void DHP_model_AuxBattVoltLowWarn(void);
extern void DHP_model_LBattery_Fault(void);
extern void DHP_model_ACCHWSignalAbnormal(void);
extern void DHP_model_MechanicalKey_Fault(void);
extern void DHP_model_ChrgFault(void);
extern void DHP_model_ChrgLockCheckTimeout(void);
extern void DHP_model_ChrgModeAbnormal(void);
extern void DHP_model_ChrgModeInvalid(void);
extern void DHP_model_ChrgOBCSleepTimeout(void);
extern void DHP_model_ChrgStopAbnormal(void);
extern void DHP_model_ChrgStopLockErr(void);
extern void DHP_model_ChrgStopModeInvalid(void);
extern void DHP_model_ChrgStopOperTimeout(void);
extern void DHP_model_DCDCStopWorkTimeout(void);
extern void DHP_model_HVActiveTimeout(void);
extern void DHP_model_HVDCDCActiveTimeout(void);
extern void DHP_model_HVDownTimeout(void);
extern void DHP_model_HVILErr(void);
extern void DHP_model_HVPwrUpTimeout(void);
extern void DHP_model_HVUpTimeout(void);
extern void DHP_model_LVUpBMSPwrUpAllwTimeout(void);
extern void DHP_model_LVUpBMSTimeout(void);
extern void DHP_model_LVUpDCDCTimeout(void);
extern void DHP_model_LVUpMCUTimeout(void);
extern void DHP_model_MCUDischargeTimeout(void);
extern void DHP_model_MCUExitTorqTimeout(void);
extern void DHP_model_MCUHVActiveTimeout(void);
extern void DHP_model_OBCWakeupTimeout(void);
extern void DHP_model_SRSMissing(void);
extern void DHP_model_ShiftKnobCheckTimeout(void);
extern void DHP_model_VCUChrgReqLimFac(void);
extern void DHP_model_VehCrash(void);
extern void DHP_model_VehCrashHardwareCanSignal(void);
extern void DHP_model_VehCrashHardwareSignal(void);
extern void DHP_model_VCUApplySW_Fault(void);
extern void DHP_model_APPData12DFlashInvalid(void);
extern void DHP_model_APPData12EEPROMInvalid(void);
extern void DHP_model_APPData3DFlashInvalid(void);
extern void DHP_model_APPData3EEPROMInvalid(void);
extern void DHP_model_APPData4DFlashInvalid(void);
extern void DHP_model_APPData4EEPROMInvalid(void);
extern void DHP_model_AppDataCheckFailed(void);
extern void DHP_model_CalDataCheckFailed(void);
extern void DHP_model_CruiseKeyJamFlt(void);
extern void DHP_model_CruiseKeyOpenFlt(void);
extern void DHP_model_CruiseKeyShortedFlt(void);
extern void DHP_model_DIDDataDFlashInvalid(void);
extern void DHP_model_DIDDataEEPROMInvalid(void);
extern void DHP_model_DidDataCheckFailed(void);
extern void DHP_model_HistDataCheckFailed(void);
extern void DHP_model_VCUHwCanNetLineOff(void);
extern void DHP_model_VCUHwHS1Flt(void);
extern void DHP_model_VCUHwLS1Flt(void);
extern void DHP_model_VCUHwLS2Flt(void);
extern void DHP_model_VCUHwLS3Flt(void);
extern void DHP_model_VCUHwLS4Flt(void);
extern void DHP_model_VCUHwLS5Flt(void);
extern void DHP_model_VCUHwLS6Flt(void);
extern void DHP_model_VCUHwLS7Flt(void);
extern void DHP_model_VCUHwLS8Flt(void);
extern void DHP_model_WriteToCalAreaInvalid(void);
extern void DHP_model_VCUHW_Fault(void);
extern void DHP_model_RegenAbnormal(void);
extern void DHP_model_VCUTorqueAbnormal_Fault(void);
extern void DHP_model_VcuControlDeviceErrValid(void);
extern void DHP_model_ABSSpdInvalid(void);
extern void DHP_model_ABSWorkErr(void);
extern void DHP_model_EBDWorkErr(void);
extern void DHP_model_EPBWorkErr(void);
extern void DHP_model_ESPWorkErr(void);
extern void DHP_model_MCUSpdInvalid(void);
extern void DHP_model_MCUTrqInvalid(void);
extern void DHP_model_SpeedInvalid(void);
extern void DHP_model_ABS_TQMWork_Fault(void);
extern void DHP_model_BattEnergyTooLow(void);
extern void DHP_model_BattEnergyTooLow_j(void);
extern void DHP_model_DCChrgPortOverT(void);
extern void DHP_model_DCChrgPortOverT_Fault(void);
extern void DHP_model_DcdcFlt2(void);
extern void DHP_model_DCDC_Fault(void);
extern void DHP_model_EPSWorkErr(void);
extern void DHP_model_EPSWorkErr_Fault(void);
extern void DHP_model_EsclAuthenticFailed(void);
extern void DHP_model_EsclChipHWFailed(void);
extern void DHP_model_EsclEEPROMFailed(void);
extern void DHP_model_EsclLinCommFailed(void);
extern void DHP_model_EsclLockGndFailed(void);
extern void DHP_model_EsclLockTimeout(void);
extern void DHP_model_EsclMasterIReqInvalid(void);
extern void DHP_model_EsclMasterReqTimeout(void);
extern void DHP_model_EsclMotorDriverFailed(void);
extern void DHP_model_EsclMotorNoAct(void);
extern void DHP_model_EsclMotorOverload(void);
extern void DHP_model_EsclPwrSupplyFailed(void);
extern void DHP_model_EsclSensorHWFailed(void);
extern void DHP_model_EsclSensorStsFailed(void);
extern void DHP_model_EsclUnlockTimeout(void);
extern void DHP_model_ESCL_Fault(void);
extern void DHP_model_IChrgError(void);
extern void DHP_model_IChrgError_g(void);
extern void DHP_model_BMSModeErr(void);
extern void DHP_model_DCDCModeErr(void);
extern void DHP_model_MCUModeErr(void);
extern void DHP_model_ModeErr_Fault(void);
extern void DHP_model_ObcFlt2(void);
extern void DHP_model_ObcFlt3(void);
extern void DHP_model_OBC_Fault(void);
extern void DHP_model_PEPSFailed(void);
extern void DHP_model_PEPSFailed_Fault(void);
extern void DHP_model_ICMVehSpdChkInvalid(void);
extern void DHP_model_SCRActualSpeedLow(void);
extern void DHP_model_SCRTargetSpdUnfollowed(void);
extern void DHP_model_SCR_Fault(void);
extern void DHP_model_TMSReqInvalid(void);
extern void DHP_model_TMSReqInvalid_n(void);
extern void DHP_model_VACHzFlt1(void);
extern void DHP_model_VACHzFlt2(void);
extern void DHP_model_VacPumpHardwire(void);
extern void DHP_model_VAC_Fault(void);
extern void DHP_model_WaterPumpFlt1(void);
extern void DHP_model_WaterPumpFlt2(void);
extern void DHP_model_WaterPumpHardwire(void);
extern void DHP_model_WaterPumpPWM(void);
extern void DHP_model_WaterPump_Fault(void);
extern void DHP_model_VehOtherDeviceErrValid(void);
extern void DHP_model_MCUCANBusOff(void);
extern void DHP_model_MCUCANCom(void);
extern void DHP_model_MCUChipPowerFlt(void);
extern void DHP_model_MCUCoverFlt(void);
extern void DHP_model_MCUCoverWarn(void);
extern void DHP_model_MCUDCUOverUHWFlt(void);
extern void DHP_model_MCUDCUShoCirc(void);
extern void DHP_model_MCUDcCrrtOverRedund(void);
extern void DHP_model_MCUDcUOverUFlt(void);
extern void DHP_model_MCUDcUOverURedund(void);
extern void DHP_model_MCUDcUOverUWarn(void);
extern void DHP_model_MCUDcUSnsrRati(void);
extern void DHP_model_MCUDcUUnderUFlt(void);
extern void DHP_model_MCUDcUUnderUWarn(void);
extern void DHP_model_MCUDischrg(void);
extern void DHP_model_MCUElecMotOverCrrt(void);
extern void DHP_model_MCUElecMotOverSpdFlt(void);
extern void DHP_model_MCUElecMotOverSpdWarn(void);
extern void DHP_model_MCUElecMotOverTFlt(void);
extern void DHP_model_MCUElecMotOverTWarn(void);
extern void DHP_model_MCUElecMotReslv(void);
extern void DHP_model_MCUElecMotStopTurn(void);
extern void DHP_model_MCUElecMotTSnsrRati(void);
extern void DHP_model_MCUElecMotUnderT(void);
extern void DHP_model_MCUFlt1(void);
extern void DHP_model_MCUFlt2(void);
extern void DHP_model_MCUFlt3(void);
extern void DHP_model_MCUFltUnmatch(void);
extern void DHP_model_MCUHWSamplingFlt(void);
extern void DHP_model_MCUHwCurrOver(void);
extern void DHP_model_MCUHwCurrOverRedund(void);
extern void DHP_model_MCUIGBTHW(void);
extern void DHP_model_MCUIGBTOverTFlt(void);
extern void DHP_model_MCUIGBTOverTWarn(void);
extern void DHP_model_MCUIGBTUnderT(void);
extern void DHP_model_MCUIGBTphaseTCheckErr(void);
extern void DHP_model_MCULowBattUnderU(void);
extern void DHP_model_MCUMotTUpRate(void);
extern void DHP_model_MCUOverT(void);
extern void DHP_model_MCUPhaACCrrtSnsrRati(void);
extern void DHP_model_MCUPhaseLoss(void);
extern void DHP_model_MCUPwrModRedund(void);
extern void DHP_model_MCUTSnsrRati(void);
extern void DHP_model_MCUTorqCheckErr(void);
extern void DHP_model_MCUTorqOuterRange(void);
extern void DHP_model_MCUVersionMismatch(void);
extern void DHP_model_MCU_Fault(void);
extern void DHP_model_VehDriveSysErrValid(void);
extern void DHP_model_BMSBattOverT(void);
extern void DHP_model_BMSCellOverU(void);
extern void DHP_model_BMSCellUnderU(void);
extern void DHP_model_BMSDischrgPwrAbnormal(void);
extern void DHP_model_BMSFlt2(void);
extern void DHP_model_BMSFlt3(void);
extern void DHP_model_BMSFlt4(void);
extern void DHP_model_BMSFltUnmatch(void);
extern void DHP_model_BMSOverU(void);
extern void DHP_model_BMSUnderU(void);
extern void DHP_model_BMS_Fault(void);
extern void DHP_model_VehPowerSysErrValid(void);
extern void DHP_model_DHP_Init(void);
extern void DHP_model_DHP(void);

#endif                                 /* RTW_HEADER_DHP_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

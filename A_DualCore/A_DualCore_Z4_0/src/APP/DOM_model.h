/*
 * File: DOM_model.h
 *
 * Code generated for Simulink model 'DOM_model'.
 *
 * Model version                  : 1.961
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Fri Mar 18 15:38:19 2022
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

#ifndef RTW_HEADER_DOM_model_h_
#define RTW_HEADER_DOM_model_h_
#include <string.h>
#include <stddef.h>
#ifndef DOM_model_COMMON_INCLUDES_
# define DOM_model_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* DOM_model_COMMON_INCLUDES_ */

#include "DOM_model_types.h"

/* Child system includes */
#include "DOM_M.h"

/* Includes for objects with custom storage classes. */
#include "DOM_Cal_Data.h"

/* Macros for accessing real-time model data structure */

/* user code (top of header file) */
#include "derivative.h"

/* Block signals (auto storage) */
typedef struct {
  B_Digital_Output_DOM_model_T Digital_Output_fa;/* '<S35>/Digital_Output' */
  B_Digital_Output_DOM_model_j_T Digital_Output_p;/* '<S34>/Digital_Output' */
  B_Digital_Output_DOM_model_a_T Digital_Output_g;/* '<S33>/Digital_Output' */
  B_Digital_Output_DOM_model_a_T Digital_Output_oq;/* '<S32>/Digital_Output' */
  B_Digital_Output_DOM_model_a_T Digital_Output_d;/* '<S31>/Digital_Output' */
  B_Digital_Output_DOM_model_a_T Digital_Output_h;/* '<S30>/Digital_Output' */
  B_Digital_Output_DOM_model_T Digital_Output_i;/* '<S29>/Digital_Output' */
  B_Digital_Output_DOM_model_T Digital_Output_o;/* '<S28>/Digital_Output' */
  B_Digital_Output_DOM_model_T Digital_Output_f;/* '<S27>/Digital_Output' */
  B_Digital_Output_DOM_model_i_T Digital_Output_if;/* '<S26>/Digital_Output' */
  B_Digital_Output_DOM_model_T Digital_Output;/* '<S25>/Digital_Output' */
} B_DOM_model_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  boolean_T UnitDelay_DSTATE;          /* '<S13>/Unit Delay' */
} DW_DOM_model_T;

/* Invariant block signals (auto storage) */
typedef struct {
  const boolean_T KOUTP_DCACEn_invert; /* '<S34>/'KOUTP_DCACEn_invert'' */
  ConstB_Digital_Output_DOM_m_o_T Digital_Output_if;/* '<S26>/Digital_Output' */
} ConstB_DOM_model_T;

/* Block signals (auto storage) */
#pragma push
#pragma DATA_SEG __GPAGE_SEG GPAGED_RAM

extern B_DOM_model_T DOM_model_B;

#pragma pop

/* Block states (auto storage) */

#pragma push
#pragma DATA_SEG __GPAGE_SEG GPAGED_RAM

extern DW_DOM_model_T DOM_model_DW;

#pragma pop

/* External data declarations for dependent source files */
#pragma push
#pragma DATA_SEG __GPAGE_SEG GPAGED_RAM

extern const DIP DOM_model_rtZDIP;     /* DIP ground */

#pragma pop
#pragma push
#pragma DATA_SEG __GPAGE_SEG GPAGED_RAM

extern const ConstB_DOM_model_T DOM_model_ConstB;/* constant block i/o */

#pragma pop

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern DIP DIP_output;                 /* '<S2>/Bus Creator2' */

/* Model entry point functions */
extern void DOM_model_initialize(void);
extern void DOM_model_step(void);
extern void DOM_model_terminate(void);

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'DOM_model'
 * '<S1>'   : 'DOM_model/DOM_M'
 * '<S2>'   : 'DOM_model/DOM_M/DOM'
 * '<S3>'   : 'DOM_model/DOM_M/Hardwire1'
 * '<S4>'   : 'DOM_model/DOM_M/Subsystem'
 * '<S5>'   : 'DOM_model/DOM_M/DOM/Calc_BMSSOC_Ind'
 * '<S6>'   : 'DOM_model/DOM_M/DOM/Calc_HandBrkSig'
 * '<S7>'   : 'DOM_model/DOM_M/DOM/Calc_LVBattChrgFlt'
 * '<S8>'   : 'DOM_model/DOM_M/DOM/Calc_PTReady'
 * '<S9>'   : 'DOM_model/DOM_M/DOM/Calc_PwrBattCutOff_flg'
 * '<S10>'  : 'DOM_model/DOM_M/DOM/Calc_PwrLimit'
 * '<S11>'  : 'DOM_model/DOM_M/DOM/Calc_VCUPwrBattFlt_Ind'
 * '<S12>'  : 'DOM_model/DOM_M/DOM/Calc_VCUPwrCnse'
 * '<S13>'  : 'DOM_model/DOM_M/DOM/Calc_VCUPwrSysFlt_Ind'
 * '<S14>'  : 'DOM_model/DOM_M/DOM/RevLight'
 * '<S15>'  : 'DOM_model/DOM_M/DOM/VCUBattChrgErr '
 * '<S16>'  : 'DOM_model/DOM_M/DOM/VCUBattChrgStatus'
 * '<S17>'  : 'DOM_model/DOM_M/DOM/VCUChrgStsLamp'
 * '<S18>'  : 'DOM_model/DOM_M/DOM/VCUEnaTextDisplayer'
 * '<S19>'  : 'DOM_model/DOM_M/DOM/VCUSysFltRank'
 * '<S20>'  : 'DOM_model/DOM_M/DOM/VCUsysOverT'
 * '<S21>'  : 'DOM_model/DOM_M/DOM/VCUEnaTextDisplayer/VCUEnaTextDisplayer'
 * '<S22>'  : 'DOM_model/DOM_M/DOM/VCUEnaTextDisplayer/bool_GearChangeRemind'
 * '<S23>'  : 'DOM_model/DOM_M/Hardwire1/Subsystem'
 * '<S24>'  : 'DOM_model/DOM_M/Hardwire1/Subsystem/Subsys_BrakeLamp_Control'
 * '<S25>'  : 'DOM_model/DOM_M/Hardwire1/Subsystem/Subsys_HSpdFanEn_flg'
 * '<S26>'  : 'DOM_model/DOM_M/Hardwire1/Subsystem/Subsys_HVInterlockEn_flg'
 * '<S27>'  : 'DOM_model/DOM_M/Hardwire1/Subsystem/Subsys_LSpdFanEn_flg'
 * '<S28>'  : 'DOM_model/DOM_M/Hardwire1/Subsystem/Subsys_MCURelayEn_flg'
 * '<S29>'  : 'DOM_model/DOM_M/Hardwire1/Subsystem/Subsys_MainRelayEn_flg'
 * '<S30>'  : 'DOM_model/DOM_M/Hardwire1/Subsystem/Subsys_PTCRelayEn_flg'
 * '<S31>'  : 'DOM_model/DOM_M/Hardwire1/Subsystem/Subsys_RLightEn_flg'
 * '<S32>'  : 'DOM_model/DOM_M/Hardwire1/Subsystem/Subsys_VAPP_ACEnReq_flg'
 * '<S33>'  : 'DOM_model/DOM_M/Hardwire1/Subsystem/Subsys_WPTCRelayEn_flg'
 * '<S34>'  : 'DOM_model/DOM_M/Hardwire1/Subsystem/Subsys_WaterPumpPWMDuyt_pct'
 * '<S35>'  : 'DOM_model/DOM_M/Hardwire1/Subsystem/Subsys_WaterPump_flg'
 * '<S36>'  : 'DOM_model/DOM_M/Hardwire1/Subsystem/Subsys_HSpdFanEn_flg/Digital_Output'
 * '<S37>'  : 'DOM_model/DOM_M/Hardwire1/Subsystem/Subsys_HVInterlockEn_flg/Digital_Output'
 * '<S38>'  : 'DOM_model/DOM_M/Hardwire1/Subsystem/Subsys_LSpdFanEn_flg/Digital_Output'
 * '<S39>'  : 'DOM_model/DOM_M/Hardwire1/Subsystem/Subsys_MCURelayEn_flg/Digital_Output'
 * '<S40>'  : 'DOM_model/DOM_M/Hardwire1/Subsystem/Subsys_MainRelayEn_flg/Digital_Output'
 * '<S41>'  : 'DOM_model/DOM_M/Hardwire1/Subsystem/Subsys_PTCRelayEn_flg/Digital_Output'
 * '<S42>'  : 'DOM_model/DOM_M/Hardwire1/Subsystem/Subsys_RLightEn_flg/Digital_Output'
 * '<S43>'  : 'DOM_model/DOM_M/Hardwire1/Subsystem/Subsys_VAPP_ACEnReq_flg/Digital_Output'
 * '<S44>'  : 'DOM_model/DOM_M/Hardwire1/Subsystem/Subsys_WPTCRelayEn_flg/Digital_Output'
 * '<S45>'  : 'DOM_model/DOM_M/Hardwire1/Subsystem/Subsys_WaterPumpPWMDuyt_pct/Digital_Output'
 * '<S46>'  : 'DOM_model/DOM_M/Hardwire1/Subsystem/Subsys_WaterPump_flg/Digital_Output'
 * '<S47>'  : 'DOM_model/DOM_M/Subsystem/TMS_2C1'
 * '<S48>'  : 'DOM_model/DOM_M/Subsystem/TMS_2C2'
 * '<S49>'  : 'DOM_model/DOM_M/Subsystem/TMS_2C3'
 * '<S50>'  : 'DOM_model/DOM_M/Subsystem/VCU_105_PEPS'
 * '<S51>'  : 'DOM_model/DOM_M/Subsystem/VCU_106'
 * '<S52>'  : 'DOM_model/DOM_M/Subsystem/VCU_10A_PEPS'
 * '<S53>'  : 'DOM_model/DOM_M/Subsystem/VCU_110_BMS'
 * '<S54>'  : 'DOM_model/DOM_M/Subsystem/VCU_120_MCU'
 * '<S55>'  : 'DOM_model/DOM_M/Subsystem/VCU_210_OBC'
 * '<S56>'  : 'DOM_model/DOM_M/Subsystem/VCU_220_OBC'
 * '<S57>'  : 'DOM_model/DOM_M/Subsystem/VCU_230_DCDC'
 * '<S58>'  : 'DOM_model/DOM_M/Subsystem/VCU_232 for X11'
 * '<S59>'  : 'DOM_model/DOM_M/Subsystem/VCU_307_Cluster'
 * '<S60>'  : 'DOM_model/DOM_M/Subsystem/VCU_510'
 * '<S61>'  : 'DOM_model/DOM_M/Subsystem/VCU_511'
 * '<S62>'  : 'DOM_model/DOM_M/Subsystem/VCU_520'
 * '<S63>'  : 'DOM_model/DOM_M/Subsystem/VCU_525_ECC'
 * '<S64>'  : 'DOM_model/DOM_M/Subsystem/VCU_530'
 * '<S65>'  : 'DOM_model/DOM_M/Subsystem/VCU_540_CS'
 * '<S66>'  : 'DOM_model/DOM_M/Subsystem/VCU_TEST_444'
 * '<S67>'  : 'DOM_model/DOM_M/Subsystem/VCU_TEST_555'
 * '<S68>'  : 'DOM_model/DOM_M/Subsystem/TMS_2C1/TMS_AC_Command'
 * '<S69>'  : 'DOM_model/DOM_M/Subsystem/TMS_2C1/TMS_AC_Pow_limit'
 * '<S70>'  : 'DOM_model/DOM_M/Subsystem/TMS_2C1/TMS_AC_SpeedSet'
 * '<S71>'  : 'DOM_model/DOM_M/Subsystem/TMS_2C1/TMS_PTC_Command'
 * '<S72>'  : 'DOM_model/DOM_M/Subsystem/TMS_2C1/TMS_PTC_Pow_limit'
 * '<S73>'  : 'DOM_model/DOM_M/Subsystem/TMS_2C1/TMS_PTC_Target_T'
 * '<S74>'  : 'DOM_model/DOM_M/Subsystem/TMS_2C1/TMS_WPTC_Command'
 * '<S75>'  : 'DOM_model/DOM_M/Subsystem/TMS_2C1/TMS_WPTC_Target_T'
 * '<S76>'  : 'DOM_model/DOM_M/Subsystem/TMS_2C2/TMS_WPTC_Pow_limit'
 * '<S77>'  : 'DOM_model/DOM_M/Subsystem/TMS_2C3/TMS_Batt_EXVSt'
 * '<S78>'  : 'DOM_model/DOM_M/Subsystem/TMS_2C3/TMS_Batt_GVSt'
 * '<S79>'  : 'DOM_model/DOM_M/Subsystem/TMS_2C3/TMS_Batt_InWT'
 * '<S80>'  : 'DOM_model/DOM_M/Subsystem/TMS_2C3/TMS_Batt_OutWT'
 * '<S81>'  : 'DOM_model/DOM_M/Subsystem/TMS_2C3/TMS_Batt_WPFlow'
 * '<S82>'  : 'DOM_model/DOM_M/Subsystem/TMS_2C3/TMS_Cabin_EXVSt '
 * '<S83>'  : 'DOM_model/DOM_M/Subsystem/TMS_2C3/TMS_Cabin_GVSt'
 * '<S84>'  : 'DOM_model/DOM_M/Subsystem/TMS_2C3/TMS_State'
 * '<S85>'  : 'DOM_model/DOM_M/Subsystem/VCU_105_PEPS/ChallengeFrame_ECM0'
 * '<S86>'  : 'DOM_model/DOM_M/Subsystem/VCU_105_PEPS/ChallengeFrame_ECM1'
 * '<S87>'  : 'DOM_model/DOM_M/Subsystem/VCU_105_PEPS/ChallengeFrame_ECM2'
 * '<S88>'  : 'DOM_model/DOM_M/Subsystem/VCU_105_PEPS/ChallengeFrame_ECM3'
 * '<S89>'  : 'DOM_model/DOM_M/Subsystem/VCU_105_PEPS/ChallengeFrame_ECM4'
 * '<S90>'  : 'DOM_model/DOM_M/Subsystem/VCU_105_PEPS/ChallengeFrame_ECM5'
 * '<S91>'  : 'DOM_model/DOM_M/Subsystem/VCU_105_PEPS/ChallengeFrame_ECM6'
 * '<S92>'  : 'DOM_model/DOM_M/Subsystem/VCU_105_PEPS/ChallengeFrame_ECM7'
 * '<S93>'  : 'DOM_model/DOM_M/Subsystem/VCU_106/VCUBrakeLampStatus'
 * '<S94>'  : 'DOM_model/DOM_M/Subsystem/VCU_10A_PEPS/CRUISECtrlErr'
 * '<S95>'  : 'DOM_model/DOM_M/Subsystem/VCU_10A_PEPS/CRUISECtrlSys'
 * '<S96>'  : 'DOM_model/DOM_M/Subsystem/VCU_10A_PEPS/CRUISESpeed'
 * '<S97>'  : 'DOM_model/DOM_M/Subsystem/VCU_10A_PEPS/Subsystem'
 * '<S98>'  : 'DOM_model/DOM_M/Subsystem/VCU_10A_PEPS/VCU_ReleaseSig'
 * '<S99>'  : 'DOM_model/DOM_M/Subsystem/VCU_110_BMS/CHMAsignalSts'
 * '<S100>' : 'DOM_model/DOM_M/Subsystem/VCU_110_BMS/RemoteHVACStopCtrl'
 * '<S101>' : 'DOM_model/DOM_M/Subsystem/VCU_110_BMS/SRSCrashSts'
 * '<S102>' : 'DOM_model/DOM_M/Subsystem/VCU_110_BMS/VCUActHVPwrCnsExt'
 * '<S103>' : 'DOM_model/DOM_M/Subsystem/VCU_110_BMS/VCUBMSOperModReq'
 * '<S104>' : 'DOM_model/DOM_M/Subsystem/VCU_110_BMS/VCUBMSSOCEna'
 * '<S105>' : 'DOM_model/DOM_M/Subsystem/VCU_110_BMS/VCUBattIntrHeatAllwd'
 * '<S106>' : 'DOM_model/DOM_M/Subsystem/VCU_110_BMS/VCUCRCID110'
 * '<S107>' : 'DOM_model/DOM_M/Subsystem/VCU_110_BMS/VCUChrgAllwd'
 * '<S108>' : 'DOM_model/DOM_M/Subsystem/VCU_110_BMS/VCUChrgIReqLimFac'
 * '<S109>' : 'DOM_model/DOM_M/Subsystem/VCU_110_BMS/VCUChrgPauseReq'
 * '<S110>' : 'DOM_model/DOM_M/Subsystem/VCU_110_BMS/VCUHVILSts'
 * '<S111>' : 'DOM_model/DOM_M/Subsystem/VCU_110_BMS/VCUSOCDisp'
 * '<S112>' : 'DOM_model/DOM_M/Subsystem/VCU_110_BMS/VCUVehSts'
 * '<S113>' : 'DOM_model/DOM_M/Subsystem/VCU_110_BMS/VCU_AvTq_Max'
 * '<S114>' : 'DOM_model/DOM_M/Subsystem/VCU_110_BMS/VCU_AvTq_Min'
 * '<S115>' : 'DOM_model/DOM_M/Subsystem/VCU_120_MCU/AccPed'
 * '<S116>' : 'DOM_model/DOM_M/Subsystem/VCU_120_MCU/MCU131CRC'
 * '<S117>' : 'DOM_model/DOM_M/Subsystem/VCU_120_MCU/MCUAntishakeCom'
 * '<S118>' : 'DOM_model/DOM_M/Subsystem/VCU_120_MCU/MotSpdReq'
 * '<S119>' : 'DOM_model/DOM_M/Subsystem/VCU_120_MCU/MotStsModReq'
 * '<S120>' : 'DOM_model/DOM_M/Subsystem/VCU_120_MCU/MotTqReq'
 * '<S121>' : 'DOM_model/DOM_M/Subsystem/VCU_120_MCU/VCUGearPosn'
 * '<S122>' : 'DOM_model/DOM_M/Subsystem/VCU_120_MCU/VCUSysFltRank'
 * '<S123>' : 'DOM_model/DOM_M/Subsystem/VCU_120_MCU/VHALO_VCU_AntiSlipFunEn_flg'
 * '<S124>' : 'DOM_model/DOM_M/Subsystem/VCU_210_OBC/VCUChrgStsLamp'
 * '<S125>' : 'DOM_model/DOM_M/Subsystem/VCU_210_OBC/VCUOBCSleep'
 * '<S126>' : 'DOM_model/DOM_M/Subsystem/VCU_210_OBC/VCUPlugConnectLamp'
 * '<S127>' : 'DOM_model/DOM_M/Subsystem/VCU_220_OBC/VCUOBCWake'
 * '<S128>' : 'DOM_model/DOM_M/Subsystem/VCU_230_DCDC/VCUDCDCStsMod'
 * '<S129>' : 'DOM_model/DOM_M/Subsystem/VCU_230_DCDC/VCUMaxPermDCDCPwr'
 * '<S130>' : 'DOM_model/DOM_M/Subsystem/VCU_230_DCDC/VCUReqDCDCU'
 * '<S131>' : 'DOM_model/DOM_M/Subsystem/VCU_232 for X11/VehicleSpeed'
 * '<S132>' : 'DOM_model/DOM_M/Subsystem/VCU_232 for X11/VehicleSpeedValid'
 * '<S133>' : 'DOM_model/DOM_M/Subsystem/VCU_307_Cluster/SystemErr'
 * '<S134>' : 'DOM_model/DOM_M/Subsystem/VCU_307_Cluster/VCUBattChrgErr'
 * '<S135>' : 'DOM_model/DOM_M/Subsystem/VCU_307_Cluster/VCUBattChrgPwr'
 * '<S136>' : 'DOM_model/DOM_M/Subsystem/VCU_307_Cluster/VCUBattChrgStatus'
 * '<S137>' : 'DOM_model/DOM_M/Subsystem/VCU_307_Cluster/VCUBattDischrgPwr'
 * '<S138>' : 'DOM_model/DOM_M/Subsystem/VCU_307_Cluster/VCUBrkErr'
 * '<S139>' : 'DOM_model/DOM_M/Subsystem/VCU_307_Cluster/VCUDrvgEff'
 * '<S140>' : 'DOM_model/DOM_M/Subsystem/VCU_307_Cluster/VCUElecMotErr'
 * '<S141>' : 'DOM_model/DOM_M/Subsystem/VCU_307_Cluster/VCUEnaTextDisplayer'
 * '<S142>' : 'DOM_model/DOM_M/Subsystem/VCU_307_Cluster/VCUEnaWarnSound'
 * '<S143>' : 'DOM_model/DOM_M/Subsystem/VCU_307_Cluster/VCUPowerlimte'
 * '<S144>' : 'DOM_model/DOM_M/Subsystem/VCU_307_Cluster/VCUPwrBattCutOff'
 * '<S145>' : 'DOM_model/DOM_M/Subsystem/VCU_307_Cluster/VCUPwrBattFlt'
 * '<S146>' : 'DOM_model/DOM_M/Subsystem/VCU_307_Cluster/VCUPwrCnse'
 * '<S147>' : 'DOM_model/DOM_M/Subsystem/VCU_307_Cluster/VCUPwrSysFlt'
 * '<S148>' : 'DOM_model/DOM_M/Subsystem/VCU_307_Cluster/VCURdy'
 * '<S149>' : 'DOM_model/DOM_M/Subsystem/VCU_307_Cluster/VCUVehOverSpd'
 * '<S150>' : 'DOM_model/DOM_M/Subsystem/VCU_307_Cluster/VCUsysOverT'
 * '<S151>' : 'DOM_model/DOM_M/Subsystem/VCU_510/DriverDemandTqReq'
 * '<S152>' : 'DOM_model/DOM_M/Subsystem/VCU_510/Test12VChk'
 * '<S153>' : 'DOM_model/DOM_M/Subsystem/VCU_510/TestBrkPedPsd'
 * '<S154>' : 'DOM_model/DOM_M/Subsystem/VCU_510/TestBrkPedValid'
 * '<S155>' : 'DOM_model/DOM_M/Subsystem/VCU_510/TestVacBrkP'
 * '<S156>' : 'DOM_model/DOM_M/Subsystem/VCU_510/VCUResiMilg'
 * '<S157>' : 'DOM_model/DOM_M/Subsystem/VCU_510/VccPumpEna'
 * '<S158>' : 'DOM_model/DOM_M/Subsystem/VCU_511/ESKGearPosn'
 * '<S159>' : 'DOM_model/DOM_M/Subsystem/VCU_511/InstantEnergyConsump'
 * '<S160>' : 'DOM_model/DOM_M/Subsystem/VCU_511/VCUHisSubtotalEgyCnse'
 * '<S161>' : 'DOM_model/DOM_M/Subsystem/VCU_511/VCUVehEgyCnseDrv'
 * '<S162>' : 'DOM_model/DOM_M/Subsystem/VCU_511/VHALO_VCU_DriverModel'
 * '<S163>' : 'DOM_model/DOM_M/Subsystem/VCU_511/VHALO_VCU_EnergyRecovery'
 * '<S164>' : 'DOM_model/DOM_M/Subsystem/VCU_511/VHALO_VCU_VehrpValid'
 * '<S165>' : 'DOM_model/DOM_M/Subsystem/VCU_520/ACChrgrLockEna'
 * '<S166>' : 'DOM_model/DOM_M/Subsystem/VCU_520/ACChrgrLockFb'
 * '<S167>' : 'DOM_model/DOM_M/Subsystem/VCU_520/ACChrgrUnLockEna'
 * '<S168>' : 'DOM_model/DOM_M/Subsystem/VCU_520/EPBAppliedReqValid'
 * '<S169>' : 'DOM_model/DOM_M/Subsystem/VCU_520/EPBOperReq'
 * '<S170>' : 'DOM_model/DOM_M/Subsystem/VCU_520/IChrgSts'
 * '<S171>' : 'DOM_model/DOM_M/Subsystem/VCU_520/LowSpdWarnEna'
 * '<S172>' : 'DOM_model/DOM_M/Subsystem/VCU_520/TestAChrgWakeup'
 * '<S173>' : 'DOM_model/DOM_M/Subsystem/VCU_520/TestFlgKeyOn'
 * '<S174>' : 'DOM_model/DOM_M/Subsystem/VCU_520/TestHndbrkSig'
 * '<S175>' : 'DOM_model/DOM_M/Subsystem/VCU_520/TestRvsLampEna'
 * '<S176>' : 'DOM_model/DOM_M/Subsystem/VCU_520/TestVehDrvPerm'
 * '<S177>' : 'DOM_model/DOM_M/Subsystem/VCU_520/VehChrgSts'
 * '<S178>' : 'DOM_model/DOM_M/Subsystem/VCU_525_ECC/ElectronicFan_Sts'
 * '<S179>' : 'DOM_model/DOM_M/Subsystem/VCU_525_ECC/PressureSwitchSts '
 * '<S180>' : 'DOM_model/DOM_M/Subsystem/VCU_525_ECC/VCUEnaHVAC'
 * '<S181>' : 'DOM_model/DOM_M/Subsystem/VCU_525_ECC/VCUEnaPTC'
 * '<S182>' : 'DOM_model/DOM_M/Subsystem/VCU_525_ECC/VCUEnaWPTC'
 * '<S183>' : 'DOM_model/DOM_M/Subsystem/VCU_525_ECC/VCUMaxPermHVACPwr'
 * '<S184>' : 'DOM_model/DOM_M/Subsystem/VCU_525_ECC/VCUMaxPermPTCPwr'
 * '<S185>' : 'DOM_model/DOM_M/Subsystem/VCU_525_ECC/VCUMaxPermWPTCPwr'
 * '<S186>' : 'DOM_model/DOM_M/Subsystem/VCU_530/TestBookingChrgSwt'
 * '<S187>' : 'DOM_model/DOM_M/Subsystem/VCU_530/TestElecMotEff'
 * '<S188>' : 'DOM_model/DOM_M/Subsystem/VCU_530/VCUMotTqAvlMax'
 * '<S189>' : 'DOM_model/DOM_M/Subsystem/VCU_530/VCUMotTqAvlMin'
 * '<S190>' : 'DOM_model/DOM_M/Subsystem/VCU_530/VCUVehEgyCnseAscy'
 * '<S191>' : 'DOM_model/DOM_M/Subsystem/VCU_530/VehVSpdAvrgHistory'
 * '<S192>' : 'DOM_model/DOM_M/Subsystem/VCU_540_CS/BrkSysRegTorqLimit'
 * '<S193>' : 'DOM_model/DOM_M/Subsystem/VCU_540_CS/BrkSysRegTorqLimitValid'
 * '<S194>' : 'DOM_model/DOM_M/Subsystem/VCU_540_CS/VHALO_CoastRegenTq_Expectation'
 * '<S195>' : 'DOM_model/DOM_M/Subsystem/VCU_TEST_444/ ECC_PwrLmit'
 * '<S196>' : 'DOM_model/DOM_M/Subsystem/VCU_TEST_444/MOT_CharPwr'
 * '<S197>' : 'DOM_model/DOM_M/Subsystem/VCU_TEST_444/MOT_DCharPwr'
 * '<S198>' : 'DOM_model/DOM_M/Subsystem/VCU_TEST_444/RR_RemainRange_Chrg_km'
 * '<S199>' : 'DOM_model/DOM_M/Subsystem/VCU_TEST_555/RR_Ave_Fad_whpkm'
 * '<S200>' : 'DOM_model/DOM_M/Subsystem/VCU_TEST_555/RR_Ave_Filt_whpkm'
 * '<S201>' : 'DOM_model/DOM_M/Subsystem/VCU_TEST_555/RR_PTRemainEgy_Wh'
 * '<S202>' : 'DOM_model/DOM_M/Subsystem/VCU_TEST_555/RR_RemainRange_noChrg_km'
 */
#endif                                 /* RTW_HEADER_DOM_model_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

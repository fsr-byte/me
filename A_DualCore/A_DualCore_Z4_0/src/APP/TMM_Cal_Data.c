/*
 * File: TMM_Cal_Data.c
 *
 * Code generated for Simulink model 'TMM_model'.
 *
 * Model version                  : 1.2731
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Fri Mar 18 15:44:30 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Freescale->32-bit PowerPC
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 *    3. ROM efficiency
 *    4. MISRA C:2012 guidelines
 * Validation result: Not run
 */

#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "TMM_model_types.h"

/* Exported data definition */
#include "derivative.h"

/* Definition for custom storage class: CAL_8_TMM */
CAL_TMM uint8_T BMSSOC_WPTC_Enable = 20U;
CAL_TMM uint16_T DTMM_AC_MaxPower_W = 5000U;
CAL_TMM uint16_T DTMM_AC_Shutoff_Pwr = 450U;
CAL_TMM boolean_T DTMM_AfterRunComplete_flg_ovrdflg = 0;
CAL_TMM boolean_T DTMM_AfterRunComplete_flg_ovrdval = 1;
CAL_TMM uint8_T DTMM_BMSHEATCTRL_HEAT = 1U;
CAL_TMM uint8_T DTMM_CHRMODE_ABNORMAL = 3U;
CAL_TMM uint8_T DTMM_CHRMODE_AC = 1U;
CAL_TMM uint8_T DTMM_CHRMODE_DC = 2U;
CAL_TMM int16_T DTMM_ChargerSocketTemperatureDefault_degC = 30;
CAL_TMM int16_T DTMM_ChrgReqLimFacOneLower_degC = 70;
CAL_TMM int16_T DTMM_ChrgReqLimFacOneUpper_degC = 75;
CAL_TMM int16_T DTMM_ChrgReqLimFacThreeLower_degC = 90;
CAL_TMM int16_T DTMM_ChrgReqLimFacThreeupper_degC = 95;
CAL_TMM int16_T DTMM_ChrgReqLimFacTwoLower_degC = 80;
CAL_TMM int16_T DTMM_ChrgReqLimFacTwoupper_degC = 85;
CAL_TMM real32_T DTMM_CoolFanOff_DCDCT_C = 55.0F;
CAL_TMM real32_T DTMM_CoolFanOff_IGBTT_C = 60.0F;
CAL_TMM real32_T DTMM_CoolFanOff_MCUElecMotT_C = 70.0F;
CAL_TMM real32_T DTMM_CoolFanOff_MCUT_C = 55.0F;
CAL_TMM real32_T DTMM_CoolFanOff_OBCT_C = 60.0F;
CAL_TMM boolean_T DTMM_DriveHeatAllow = 1;
CAL_TMM uint16_T DTMM_EACHigh_MaxPower_W = 3000U;
CAL_TMM uint16_T DTMM_EACLow_MaxPower_W = 1000U;
CAL_TMM uint16_T DTMM_EACMid_MaxPower_W = 2000U;
CAL_TMM uint16_T DTMM_ECCAfterShutoffWaitTime_ms = 10000U;
CAL_TMM uint16_T DTMM_ECCForceShutoffMsgDispTime_ms = 8000U;
CAL_TMM uint16_T DTMM_ECCInitWaitTime_ms = 30000U;
CAL_TMM uint16_T DTMM_EXV_Max_step = 480U;
CAL_TMM uint16_T DTMM_EXV_Min_step = 0U;
CAL_TMM uint16_T DTMM_ForceShutdownTime_ms = 3000U;
CAL_TMM uint8_T DTMM_ForceShutoffECC_RRMiles = 30U;
CAL_TMM real32_T DTMM_HSCoolFanOn_DCDCT_C = 65.0F;
CAL_TMM real32_T DTMM_HSCoolFanOn_IGBTT_C = 70.0F;
CAL_TMM real32_T DTMM_HSCoolFanOn_MCUElecMotT_C = 115.0F;
CAL_TMM real32_T DTMM_HSCoolFanOn_MCUT_C = 65.0F;
CAL_TMM real32_T DTMM_HSCoolFanOn_OBCT_C = 70.0F;
CAL_TMM boolean_T DTMM_IncludeTMS = 0;
CAL_TMM boolean_T DTMM_Internal_AC_MaxPower_flg = 0;
CAL_TMM boolean_T DTMM_Internal_PTC_MaxPower_flg = 0;
CAL_TMM real32_T DTMM_LSCoolFanOn_DCDCT_C = 60.0F;
CAL_TMM real32_T DTMM_LSCoolFanOn_IGBTT_C = 65.0F;
CAL_TMM real32_T DTMM_LSCoolFanOn_MCUElecMotT_C = 90.0F;
CAL_TMM real32_T DTMM_LSCoolFanOn_MCUT_C = 60.0F;
CAL_TMM real32_T DTMM_LSCoolFanOn_OBCT_C = 65.0F;
CAL_TMM int16_T DTMM_MotOverTempConfirm_Cal = 115;
CAL_TMM int16_T DTMM_MotOverTempRecovery_Cal = 110;
CAL_TMM uint8_T DTMM_MotOverTemp_EnterSpd_Cal = 20U;
CAL_TMM uint8_T DTMM_MotOverTemp_LeftSpd_Cal = 15U;
CAL_TMM uint16_T DTMM_PTCHigh_MaxPower_W = 3000U;
CAL_TMM uint16_T DTMM_PTCLow_MaxPower_W = 1000U;
CAL_TMM uint16_T DTMM_PTCMid_MaxPower_W = 2000U;
CAL_TMM uint16_T DTMM_PTC_MaxPower_W = 5000U;
CAL_TMM uint16_T DTMM_PTC_Shutoff_Pwr = 500U;
CAL_TMM boolean_T DTMM_TMS_Active = 0;
CAL_TMM boolean_T DTMM_TMS_Batt_EXVSt_init_SetFlg = 0;
CAL_TMM boolean_T DTMM_TMS_Batt_EXVSt_init_SetVal = 0;
CAL_TMM boolean_T DTMM_TMS_Batt_EXVSt_step_SetFlg = 0;
CAL_TMM uint16_T DTMM_TMS_Batt_EXVSt_step_SetVal = 0U;
CAL_TMM boolean_T DTMM_TMS_Batt_GVSt_SetFlg = 0;
CAL_TMM boolean_T DTMM_TMS_Batt_GVSt_SetVal = 0;
CAL_TMM boolean_T DTMM_TMS_Cabin_EXVSt_init_SetFlg = 0;
CAL_TMM boolean_T DTMM_TMS_Cabin_EXVSt_init_SetVal = 0;
CAL_TMM boolean_T DTMM_TMS_Cabin_EXVSt_step_SetFlg = 0;
CAL_TMM uint16_T DTMM_TMS_Cabin_EXVSt_step_SetVal = 0U;
CAL_TMM boolean_T DTMM_TMS_Cabin_GVSt_SetFlg = 0;
CAL_TMM boolean_T DTMM_TMS_Cabin_GVSt_SetVal = 0;
CAL_TMM boolean_T DTMM_WPPWM_Duty_per_ovrdflg = 0;
CAL_TMM uint8_T DTMM_WPPWM_Duty_per_ovrdval = 50U;
CAL_TMM uint16_T DTMM_WPTC_MaxPower_W = 5000U;
CAL_TMM uint16_T DTMM_WPTC_Shutoff_Pwr = 500U;
CAL_TMM boolean_T DTMM_WaterPumpEnReq_flg_ovrdflg = 0;
CAL_TMM boolean_T DTMM_WaterPumpEnReq_flg_ovrdval = 1;
CAL_TMM int16_T DTMM_WaterPumpOff_DCDCT_C = 45;
CAL_TMM int16_T DTMM_WaterPumpOff_IGBTT_C = 50;
CAL_TMM int16_T DTMM_WaterPumpOff_MCUElecMotT_C = 55;
CAL_TMM int16_T DTMM_WaterPumpOff_MCUT_C = 50;
CAL_TMM int16_T DTMM_WaterPumpOff_OBCT_C = 45;
CAL_TMM int16_T DTMM_WaterPumpOn_DCDCT_C = 50;
CAL_TMM int16_T DTMM_WaterPumpOn_IGBTT_C = 55;
CAL_TMM int16_T DTMM_WaterPumpOn_MCUElecMotT_C = 60;
CAL_TMM int16_T DTMM_WaterPumpOn_MCUT_C = 55;
CAL_TMM int16_T DTMM_WaterPumpOn_OBCT_C = 50;
CAL_TMM uint8_T DTMM_WaterPumpPWM_DutyMax = 85U;
CAL_TMM boolean_T DTMM_WaterT_Enable_flg = 0;
CAL_TMM uint32_T MTMM_BATT_DisPwr_per[7] = { 0U, 500U, 1000U, 8000U, 12000U,
  15000U, 20000U } ;

CAL_TMM int16_T MTMM_BATT_InWaterT_Below_Deg[5] = { 3, 4, 5, 10, 20 } ;

CAL_TMM int16_T MTMM_BATT_InWaterT_Exceed_Deg[5] = { 3, 4, 5, 10, 20 } ;

CAL_TMM uint16_T MTMM_BattCool_AC_SpeedSet_Per[5] = { 0U, 5U, 20U, 40U, 100U } ;

CAL_TMM int16_T MTMM_BattEXVSt_PTSensorT_X[6] = { 3, 4, 5, 10, 20, 50 } ;

CAL_TMM uint8_T MTMM_BattEXVSt_per[6] = { 0U, 2U, 5U, 10U, 30U, 100U } ;

CAL_TMM uint8_T MTMM_BattPump_PWM_per[5] = { 20U, 30U, 20U, 30U, 80U } ;

CAL_TMM real32_T MTMM_DCDCT_WPPWM_Duty_per[5] = { 45.0F, 45.0F, 55.0F, 84.0F,
  84.0F } ;

CAL_TMM real32_T MTMM_DCDCT_X_C[5] = { -40.0F, 30.0F, 45.0F, 70.0F, 150.0F } ;

CAL_TMM uint16_T MTMM_ECC_PWR_LIMIT_per[14] = { 0U, 0U, 500U, 500U, 1000U, 1000U,
  2000U, 2000U, 3000U, 3000U, 10000U, 10000U, 15000U, 15000U } ;

CAL_TMM real32_T MTMM_IGBTT_WPPWM_Duty_per[5] = { 45.0F, 45.0F, 55.0F, 84.0F,
  84.0F } ;

CAL_TMM real32_T MTMM_IGBTT_X_C[5] = { -40.0F, 30.0F, 60.0F, 70.0F, 150.0F } ;

CAL_TMM real32_T MTMM_MotMCUElecMotT_TqLim_Pct[15] = { 100.0F, 99.0F, 98.0F,
  97.0F, 95.0F, 93.0F, 90.0F, 88.0F, 85.0F, 83.0F, 80.0F, 75.0F, 70.0F, 50.0F,
  0.0F } ;

CAL_TMM real32_T MTMM_MotMCUElecMotT_X_C[15] = { 110.0F, 112.0F, 115.0F, 117.0F,
  120.0F, 122.0F, 125.0F, 127.0F, 130.0F, 132.0F, 135.0F, 137.0F, 140.0F, 142.0F,
  145.0F } ;

CAL_TMM real32_T MTMM_OBCT_WPPWM_Duty_per[5] = { 45.0F, 45.0F, 65.0F, 84.0F,
  84.0F } ;

CAL_TMM real32_T MTMM_OBCT_X_C[5] = { -40.0F, 30.0F, 45.0F, 70.0F, 150.0F } ;

CAL_TMM uint8_T MTMM_PumpPWMDuty_per[6] = { 35U, 45U, 55U, 65U, 75U, 85U } ;

CAL_TMM uint32_T MTMM_VEH_SPD_per[2] = { 0U, 40U } ;

CAL_TMM real32_T MTMM_WaterChannelEnterT_X_C[5] = { -40.0F, 30.0F, 50.0F, 70.0F,
  150.0F } ;

CAL_TMM real32_T MTMM_WaterChannelEnter_WPPWM_Duty_per[5] = { 45.0F, 45.0F,
  55.0F, 84.0F, 84.0F } ;

CAL_TMM real32_T MTMM_WaterChannelExitT_X_C[5] = { -40.0F, 60.0F, 100.0F, 115.0F,
  150.0F } ;

CAL_TMM real32_T MTMM_WaterChannelExit_WPPWM_Duty_per[5] = { 45.0F, 45.0F, 55.0F,
  84.0F, 84.0F } ;

CAL_TMM uint8_T MTMM_WaterSpd_L[6] = { 4U, 6U, 8U, 11U, 12U, 13U } ;

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

/*
 * File: TMM_Cal_Data.h
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

#ifndef RTW_HEADER_TMM_Cal_Data_h_
#define RTW_HEADER_TMM_Cal_Data_h_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "TMM_model_types.h"

/* Exported data define */

/* Definition for custom storage class: Define */
#define TMM_AC_REQ_BATT                2U
#define TMM_AC_REQ_CABIN_BATT          3U
#define TMM_AC_REQ_NULL                0U
#define TMM_VEHICLETYPE_Z18            14U
#define TMM_Z18PWMOUT_DEFROSTON_ACK    90U
#define TMM_Z18PWMOUT_EACONHIGH_ACK    55U
#define TMM_Z18PWMOUT_EACONLOW_ACK     37U
#define TMM_Z18PWMOUT_EACONMID_ACK     46U
#define TMM_Z18PWMOUT_NONE             0U
#define TMM_Z18PWMOUT_OFF_ACK          10U
#define TMM_Z18PWMOUT_PTCONHIGH_ACK    82U
#define TMM_Z18PWMOUT_PTCONLOW_ACK     64U
#define TMM_Z18PWMOUT_PTCONMID_ACK     73U
#define TMM_Z18PWMOUT_RMTEAC_REQ       19U
#define TMM_Z18PWMOUT_RMTPTC_REQ       28U
#define TMM_Z18PWM_DEFROSTREQ_LOWER    88U
#define TMM_Z18PWM_DEFROSTREQ_UPPER    92U
#define TMM_Z18PWM_EACONHIGH_LOWER     53U
#define TMM_Z18PWM_EACONHIGH_UPPER     57U
#define TMM_Z18PWM_EACONLOW_LOWER      35U
#define TMM_Z18PWM_EACONLOW_UPPER      39U
#define TMM_Z18PWM_EACONMID_LOWER      44U
#define TMM_Z18PWM_EACONMID_UPPER      48U
#define TMM_Z18PWM_OFFREQ_LOWER        8U
#define TMM_Z18PWM_OFFREQ_UPPER        12U
#define TMM_Z18PWM_PTCONHIGH_LOWER     80U
#define TMM_Z18PWM_PTCONHIGH_UPPER     84U
#define TMM_Z18PWM_PTCONLOW_LOWER      62U
#define TMM_Z18PWM_PTCONLOW_UPPER      66U
#define TMM_Z18PWM_PTCONMID_LOWER      71U
#define TMM_Z18PWM_PTCONMID_UPPER      75U

/* Exported data declaration */
#include "derivative.h"

/* Declaration for custom storage class: CAL_8_TMM */
extern CAL_TMM uint8_T BMSSOC_WPTC_Enable;
extern CAL_TMM uint16_T DTMM_AC_MaxPower_W;
extern CAL_TMM uint16_T DTMM_AC_Shutoff_Pwr;
extern CAL_TMM boolean_T DTMM_AfterRunComplete_flg_ovrdflg;
extern CAL_TMM boolean_T DTMM_AfterRunComplete_flg_ovrdval;
extern CAL_TMM uint8_T DTMM_BMSHEATCTRL_HEAT;
extern CAL_TMM uint8_T DTMM_CHRMODE_ABNORMAL;
extern CAL_TMM uint8_T DTMM_CHRMODE_AC;
extern CAL_TMM uint8_T DTMM_CHRMODE_DC;
extern CAL_TMM int16_T DTMM_ChargerSocketTemperatureDefault_degC;
extern CAL_TMM int16_T DTMM_ChrgReqLimFacOneLower_degC;
extern CAL_TMM int16_T DTMM_ChrgReqLimFacOneUpper_degC;
extern CAL_TMM int16_T DTMM_ChrgReqLimFacThreeLower_degC;
extern CAL_TMM int16_T DTMM_ChrgReqLimFacThreeupper_degC;
extern CAL_TMM int16_T DTMM_ChrgReqLimFacTwoLower_degC;
extern CAL_TMM int16_T DTMM_ChrgReqLimFacTwoupper_degC;
extern CAL_TMM real32_T DTMM_CoolFanOff_DCDCT_C;
extern CAL_TMM real32_T DTMM_CoolFanOff_IGBTT_C;
extern CAL_TMM real32_T DTMM_CoolFanOff_MCUElecMotT_C;
extern CAL_TMM real32_T DTMM_CoolFanOff_MCUT_C;
extern CAL_TMM real32_T DTMM_CoolFanOff_OBCT_C;
extern CAL_TMM boolean_T DTMM_DriveHeatAllow;
extern CAL_TMM uint16_T DTMM_EACHigh_MaxPower_W;
extern CAL_TMM uint16_T DTMM_EACLow_MaxPower_W;
extern CAL_TMM uint16_T DTMM_EACMid_MaxPower_W;
extern CAL_TMM uint16_T DTMM_ECCAfterShutoffWaitTime_ms;
extern CAL_TMM uint16_T DTMM_ECCForceShutoffMsgDispTime_ms;
extern CAL_TMM uint16_T DTMM_ECCInitWaitTime_ms;
extern CAL_TMM uint16_T DTMM_EXV_Max_step;
extern CAL_TMM uint16_T DTMM_EXV_Min_step;
extern CAL_TMM uint16_T DTMM_ForceShutdownTime_ms;
extern CAL_TMM uint8_T DTMM_ForceShutoffECC_RRMiles;
extern CAL_TMM real32_T DTMM_HSCoolFanOn_DCDCT_C;
extern CAL_TMM real32_T DTMM_HSCoolFanOn_IGBTT_C;
extern CAL_TMM real32_T DTMM_HSCoolFanOn_MCUElecMotT_C;
extern CAL_TMM real32_T DTMM_HSCoolFanOn_MCUT_C;
extern CAL_TMM real32_T DTMM_HSCoolFanOn_OBCT_C;
extern CAL_TMM boolean_T DTMM_IncludeTMS;
extern CAL_TMM boolean_T DTMM_Internal_AC_MaxPower_flg;
extern CAL_TMM boolean_T DTMM_Internal_PTC_MaxPower_flg;
extern CAL_TMM real32_T DTMM_LSCoolFanOn_DCDCT_C;
extern CAL_TMM real32_T DTMM_LSCoolFanOn_IGBTT_C;
extern CAL_TMM real32_T DTMM_LSCoolFanOn_MCUElecMotT_C;
extern CAL_TMM real32_T DTMM_LSCoolFanOn_MCUT_C;
extern CAL_TMM real32_T DTMM_LSCoolFanOn_OBCT_C;
extern CAL_TMM int16_T DTMM_MotOverTempConfirm_Cal;
extern CAL_TMM int16_T DTMM_MotOverTempRecovery_Cal;
extern CAL_TMM uint8_T DTMM_MotOverTemp_EnterSpd_Cal;
extern CAL_TMM uint8_T DTMM_MotOverTemp_LeftSpd_Cal;
extern CAL_TMM uint16_T DTMM_PTCHigh_MaxPower_W;
extern CAL_TMM uint16_T DTMM_PTCLow_MaxPower_W;
extern CAL_TMM uint16_T DTMM_PTCMid_MaxPower_W;
extern CAL_TMM uint16_T DTMM_PTC_MaxPower_W;
extern CAL_TMM uint16_T DTMM_PTC_Shutoff_Pwr;
extern CAL_TMM boolean_T DTMM_TMS_Active;
extern CAL_TMM boolean_T DTMM_TMS_Batt_EXVSt_init_SetFlg;
extern CAL_TMM boolean_T DTMM_TMS_Batt_EXVSt_init_SetVal;
extern CAL_TMM boolean_T DTMM_TMS_Batt_EXVSt_step_SetFlg;
extern CAL_TMM uint16_T DTMM_TMS_Batt_EXVSt_step_SetVal;
extern CAL_TMM boolean_T DTMM_TMS_Batt_GVSt_SetFlg;
extern CAL_TMM boolean_T DTMM_TMS_Batt_GVSt_SetVal;
extern CAL_TMM boolean_T DTMM_TMS_Cabin_EXVSt_init_SetFlg;
extern CAL_TMM boolean_T DTMM_TMS_Cabin_EXVSt_init_SetVal;
extern CAL_TMM boolean_T DTMM_TMS_Cabin_EXVSt_step_SetFlg;
extern CAL_TMM uint16_T DTMM_TMS_Cabin_EXVSt_step_SetVal;
extern CAL_TMM boolean_T DTMM_TMS_Cabin_GVSt_SetFlg;
extern CAL_TMM boolean_T DTMM_TMS_Cabin_GVSt_SetVal;
extern CAL_TMM boolean_T DTMM_WPPWM_Duty_per_ovrdflg;
extern CAL_TMM uint8_T DTMM_WPPWM_Duty_per_ovrdval;
extern CAL_TMM uint16_T DTMM_WPTC_MaxPower_W;
extern CAL_TMM uint16_T DTMM_WPTC_Shutoff_Pwr;
extern CAL_TMM boolean_T DTMM_WaterPumpEnReq_flg_ovrdflg;
extern CAL_TMM boolean_T DTMM_WaterPumpEnReq_flg_ovrdval;
extern CAL_TMM int16_T DTMM_WaterPumpOff_DCDCT_C;
extern CAL_TMM int16_T DTMM_WaterPumpOff_IGBTT_C;
extern CAL_TMM int16_T DTMM_WaterPumpOff_MCUElecMotT_C;
extern CAL_TMM int16_T DTMM_WaterPumpOff_MCUT_C;
extern CAL_TMM int16_T DTMM_WaterPumpOff_OBCT_C;
extern CAL_TMM int16_T DTMM_WaterPumpOn_DCDCT_C;
extern CAL_TMM int16_T DTMM_WaterPumpOn_IGBTT_C;
extern CAL_TMM int16_T DTMM_WaterPumpOn_MCUElecMotT_C;
extern CAL_TMM int16_T DTMM_WaterPumpOn_MCUT_C;
extern CAL_TMM int16_T DTMM_WaterPumpOn_OBCT_C;
extern CAL_TMM uint8_T DTMM_WaterPumpPWM_DutyMax;
extern CAL_TMM boolean_T DTMM_WaterT_Enable_flg;
extern CAL_TMM uint32_T MTMM_BATT_DisPwr_per[7];
extern CAL_TMM int16_T MTMM_BATT_InWaterT_Below_Deg[5];
extern CAL_TMM int16_T MTMM_BATT_InWaterT_Exceed_Deg[5];
extern CAL_TMM uint16_T MTMM_BattCool_AC_SpeedSet_Per[5];
extern CAL_TMM int16_T MTMM_BattEXVSt_PTSensorT_X[6];
extern CAL_TMM uint8_T MTMM_BattEXVSt_per[6];
extern CAL_TMM uint8_T MTMM_BattPump_PWM_per[5];
extern CAL_TMM real32_T MTMM_DCDCT_WPPWM_Duty_per[5];
extern CAL_TMM real32_T MTMM_DCDCT_X_C[5];
extern CAL_TMM uint16_T MTMM_ECC_PWR_LIMIT_per[14];
extern CAL_TMM real32_T MTMM_IGBTT_WPPWM_Duty_per[5];
extern CAL_TMM real32_T MTMM_IGBTT_X_C[5];
extern CAL_TMM real32_T MTMM_MotMCUElecMotT_TqLim_Pct[15];
extern CAL_TMM real32_T MTMM_MotMCUElecMotT_X_C[15];
extern CAL_TMM real32_T MTMM_OBCT_WPPWM_Duty_per[5];
extern CAL_TMM real32_T MTMM_OBCT_X_C[5];
extern CAL_TMM uint8_T MTMM_PumpPWMDuty_per[6];
extern CAL_TMM uint32_T MTMM_VEH_SPD_per[2];
extern CAL_TMM real32_T MTMM_WaterChannelEnterT_X_C[5];
extern CAL_TMM real32_T MTMM_WaterChannelEnter_WPPWM_Duty_per[5];
extern CAL_TMM real32_T MTMM_WaterChannelExitT_X_C[5];
extern CAL_TMM real32_T MTMM_WaterChannelExit_WPPWM_Duty_per[5];
extern CAL_TMM uint8_T MTMM_WaterSpd_L[6];

#endif                                 /* RTW_HEADER_TMM_Cal_Data_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

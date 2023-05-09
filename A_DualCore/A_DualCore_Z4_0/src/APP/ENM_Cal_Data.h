/*
 * File: ENM_Cal_Data.h
 *
 * Code generated for Simulink model 'ENM_model'.
 *
 * Model version                  : 1.1958
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Fri Mar 18 15:39:06 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Freescale->32-bit PowerPC
 * Code generation objective: Execution efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_ENM_Cal_Data_h_
#define RTW_HEADER_ENM_Cal_Data_h_
#include "rtwtypes.h"
#include "ENM_model_types.h"

/* Exported data declaration */
#include "derivative.h"

/* Declaration for custom storage class: CAL_7_ENM */
extern CAL_ENM uint16_T AVE60km_Milg_km;
extern CAL_ENM uint16_T AVE60km_Milg_km_1;
extern CAL_ENM real32_T AirConPwr_Proportion;
extern CAL_ENM uint16_T BATTRESIPWR_INVALID;
extern CAL_ENM uint16_T BMSSOC_INVALID;
extern CAL_ENM uint32_T Batt_RatedPwr_wh;
extern CAL_ENM uint32_T Batt_RatedPwr_wh_1;
extern CAL_ENM uint8_T DCDCOperMod_Err;
extern CAL_ENM uint32_T DENM_BMSRatedDchaPwr_W;
extern CAL_ENM uint8_T DENM_BMSSOC_GAP;
extern CAL_ENM uint8_T DENM_Charging_remind_RRMiles;
extern CAL_ENM uint8_T DENM_Charging_remind_SysSOC;
extern CAL_ENM uint16_T DENM_HFanPower_W;
extern CAL_ENM uint16_T DENM_InsCnse_Invalid_Value;
extern CAL_ENM uint16_T DENM_LFanPower_W;
extern CAL_ENM real32_T DENM_PUMP_COE;
extern CAL_ENM uint16_T DENM_RR_Ave_FilTC_s_low;
extern CAL_ENM uint16_T DENM_RR_Ave_FilTC_s_up;
extern CAL_ENM real32_T DENM_RR_BattPwr_Hide_kwh;
extern CAL_ENM real32_T DENM_RR_Defaultg_coe;
extern CAL_ENM uint8_T DENM_RR_SOC_mid;
extern CAL_ENM real32_T DENM_RR_battPwrHid_map_soc;
extern CAL_ENM real32_T DENM_SOCMIN_AMENDMENT;
extern CAL_ENM real32_T DENM_SOC_HIDE;
extern CAL_ENM real32_T DENM_SYSSOC_RoundUp;
extern CAL_ENM real32_T DENM_SYSSOC_Up;
extern CAL_ENM real32_T DENM_SubTotalCnseFltDelayTime_s;
extern CAL_ENM real32_T DENM_VCUReqDCDCU;
extern CAL_ENM real32_T DENM_VehSpdZero_LowerLimit;
extern CAL_ENM real32_T DENM_VehSpdZero_UpperLimit;
extern CAL_ENM real32_T ENM_BMSDchaPwrCheck_100ms;
extern CAL_ENM real32_T ENM_BMSDchaPwrCheck_5000ms;
extern CAL_ENM uint8_T ENM_CheckChrgstats_chrging;
extern CAL_ENM boolean_T ENM_DispInvalidRR_Enable;
extern CAL_ENM uint8_T ENM_DispInvalidRR_Threshold;
extern CAL_ENM uint16_T ENM_DispInvalidRR_Value;
extern CAL_ENM uint16_T ENM_EnergyTooLow_HVDown_time_s;
extern CAL_ENM real32_T ENM_ForbidPwrOut_BMSOutPwr;
extern CAL_ENM uint8_T ENM_ForbidPwrOut_JudgeMode;
extern CAL_ENM uint16_T ENM_ForbidPwrOut_JudgeTime;
extern CAL_ENM real32_T ENM_ForcastOverNEDCMiles_Per;
extern CAL_ENM real32_T Fading_Proportion;
extern CAL_ENM real32_T Filting_Proportion;
extern CAL_ENM real32_T Instance_EgyCnsePwr_wh_low;
extern CAL_ENM real32_T Instance_EgyCnsePwr_wh_up;
extern CAL_ENM real32_T MENM_RR_FilTC_s[99];
extern CAL_ENM real32_T MENM_SOC_RR_Per[5];
extern CAL_ENM real32_T MENM_SOC_RR_X_Per[5];
extern CAL_ENM real32_T MENM_SOC_per[11];
extern CAL_ENM real32_T MENM_VehSpd_per[9];
extern CAL_ENM uint16_T NEDC_Milg_km_1;
extern CAL_ENM uint32_T Odo_InvalidValue;
extern CAL_ENM real32_T Proportion_zone0;
extern CAL_ENM real32_T Proportion_zone1;
extern CAL_ENM real32_T Proportion_zone10;
extern CAL_ENM real32_T Proportion_zone11;
extern CAL_ENM real32_T Proportion_zone12;
extern CAL_ENM real32_T Proportion_zone13;
extern CAL_ENM real32_T Proportion_zone14;
extern CAL_ENM real32_T Proportion_zone15;
extern CAL_ENM real32_T Proportion_zone16;
extern CAL_ENM real32_T Proportion_zone17;
extern CAL_ENM real32_T Proportion_zone18;
extern CAL_ENM real32_T Proportion_zone19;
extern CAL_ENM real32_T Proportion_zone2;
extern CAL_ENM real32_T Proportion_zone3;
extern CAL_ENM real32_T Proportion_zone4;
extern CAL_ENM real32_T Proportion_zone5;
extern CAL_ENM real32_T Proportion_zone6;
extern CAL_ENM real32_T Proportion_zone7;
extern CAL_ENM real32_T Proportion_zone8;
extern CAL_ENM real32_T Proportion_zone9;
extern CAL_ENM int16_T PwrLimit_Hide_W;
extern CAL_ENM int16_T RR_AveEgyCnseLowlimit;
extern CAL_ENM int16_T RR_AveEgyCnseUplimit;
extern CAL_ENM uint8_T RR_Flat_km;
extern CAL_ENM real32_T RR_full_keep_threshold;
extern CAL_ENM real32_T Recent_Proportion;
extern CAL_ENM real32_T SOCGAP;
extern CAL_ENM real32_T SOCJump_EffectPercent;
extern CAL_ENM uint8_T SOCMAX_INVALID;
extern CAL_ENM uint8_T SOCMAX_lowlimit;
extern CAL_ENM uint8_T SOCMIN_INVALID;
extern CAL_ENM uint8_T SOCMIN_uplimit;
extern CAL_ENM uint8_T SOC_HideRelease;
extern CAL_ENM uint8_T SOC_InflexionPoint;
extern CAL_ENM uint8_T SOC_SmoothHidePercent;
extern CAL_ENM uint16_T ZeroSpd_Affirm_s;

#endif                                 /* RTW_HEADER_ENM_Cal_Data_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

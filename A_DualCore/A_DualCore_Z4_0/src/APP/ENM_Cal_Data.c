/*
 * File: ENM_Cal_Data.c
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

#include "rtwtypes.h"
#include "ENM_model_types.h"

/* Exported data definition */
#include "derivative.h"

/* Definition for custom storage class: CAL_7_ENM */
CAL_ENM uint16_T AVE60km_Milg_km = 350U;
CAL_ENM uint16_T AVE60km_Milg_km_1 = 160U;
CAL_ENM real32_T AirConPwr_Proportion = 0.0F;
CAL_ENM uint16_T BATTRESIPWR_INVALID = 65535U;
CAL_ENM uint16_T BMSSOC_INVALID = 1023U;
CAL_ENM uint32_T Batt_RatedPwr_wh = 33300U;
CAL_ENM uint32_T Batt_RatedPwr_wh_1 = 9340U;
CAL_ENM uint8_T DCDCOperMod_Err = 2U;
CAL_ENM uint32_T DENM_BMSRatedDchaPwr_W = 84000U;
CAL_ENM uint8_T DENM_BMSSOC_GAP = 10U;
CAL_ENM uint8_T DENM_Charging_remind_RRMiles = 60U;
CAL_ENM uint8_T DENM_Charging_remind_SysSOC = 20U;
CAL_ENM uint16_T DENM_HFanPower_W = 173U;
CAL_ENM uint16_T DENM_InsCnse_Invalid_Value = 511U;
CAL_ENM uint16_T DENM_LFanPower_W = 151U;
CAL_ENM real32_T DENM_PUMP_COE = 0.7F;
CAL_ENM uint16_T DENM_RR_Ave_FilTC_s_low = 60U;
CAL_ENM uint16_T DENM_RR_Ave_FilTC_s_up = 120U;
CAL_ENM real32_T DENM_RR_BattPwr_Hide_kwh = 0.5F;
CAL_ENM real32_T DENM_RR_Defaultg_coe = 0.01F;
CAL_ENM uint8_T DENM_RR_SOC_mid = 50U;
CAL_ENM real32_T DENM_RR_battPwrHid_map_soc = 30.0F;
CAL_ENM real32_T DENM_SOCMIN_AMENDMENT = 0.0F;
CAL_ENM real32_T DENM_SOC_HIDE = 0.0F;
CAL_ENM real32_T DENM_SYSSOC_RoundUp = 0.9F;
CAL_ENM real32_T DENM_SYSSOC_Up = 100.9F;
CAL_ENM real32_T DENM_SubTotalCnseFltDelayTime_s = 0.1F;
CAL_ENM real32_T DENM_VCUReqDCDCU = 14.0F;
CAL_ENM real32_T DENM_VehSpdZero_LowerLimit = -2.0F;
CAL_ENM real32_T DENM_VehSpdZero_UpperLimit = 2.0F;
CAL_ENM real32_T ENM_BMSDchaPwrCheck_100ms = 1.0F;
CAL_ENM real32_T ENM_BMSDchaPwrCheck_5000ms = 8.0F;
CAL_ENM uint8_T ENM_CheckChrgstats_chrging = 1U;
CAL_ENM boolean_T ENM_DispInvalidRR_Enable = 0;
CAL_ENM uint8_T ENM_DispInvalidRR_Threshold = 1U;
CAL_ENM uint16_T ENM_DispInvalidRR_Value = 511U;
CAL_ENM uint16_T ENM_EnergyTooLow_HVDown_time_s = 300U;
CAL_ENM real32_T ENM_ForbidPwrOut_BMSOutPwr = 0.5F;
CAL_ENM uint8_T ENM_ForbidPwrOut_JudgeMode = 0U;
CAL_ENM uint16_T ENM_ForbidPwrOut_JudgeTime = 1000U;
CAL_ENM real32_T ENM_ForcastOverNEDCMiles_Per = 0.1F;
CAL_ENM real32_T Fading_Proportion = 1.0F;
CAL_ENM real32_T Filting_Proportion = 1.0F;
CAL_ENM real32_T Instance_EgyCnsePwr_wh_low = -5.0F;
CAL_ENM real32_T Instance_EgyCnsePwr_wh_up = 5.0F;
CAL_ENM real32_T MENM_RR_FilTC_s[99] =
{
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 400.0F, 300.0F, 200.0F,
    100.0F, 80.0F, 60.0F, 60.0F, 30.0F, 30.0F, 500.0F, 400.0F, 300.0F, 240.0F,
    210.0F, 180.0F, 150.0F, 120.0F, 90.0F, 600.0F, 500.0F, 400.0F, 320.0F,
    280.0F, 240.0F, 200.0F, 160.0F, 120.0F, 1000.0F, 800.0F, 600.0F, 400.0F,
    350.0F, 300.0F, 250.0F, 200.0F, 150.0F, 1200.0F, 1000.0F, 800.0F, 500.0F,
    450.0F, 400.0F, 350.0F, 300.0F, 250.0F, 1500.0F, 1100.0F, 900.0F, 660.0F,
    590.0F, 520.0F, 450.0F, 380.0F, 310.0F, 1500.0F, 1280.0F, 1150.0F, 1020.0F,
    890.0F, 760.0F, 630.0F, 500.0F, 370.0F, 1500.0F, 1280.0F, 1150.0F, 1020.0F,
    890.0F, 760.0F, 630.0F, 500.0F, 370.0F, 1510.0F, 1380.0F, 1250.0F, 1120.0F,
    990.0F, 860.0F, 730.0F, 600.0F, 470.0F, 1610.0F, 1480.0F, 1350.0F, 1220.0F,
    1090.0F, 960.0F, 830.0F, 700.0F, 570.0F
} ;

CAL_ENM real32_T MENM_SOC_RR_Per[5] =
{
    0.0F, 0.15F, 0.5F, 0.85F, 1.0F
} ;

CAL_ENM real32_T MENM_SOC_RR_X_Per[5] =
{
    0.0F, 20.0F, 50.0F, 80.0F, 100.0F
} ;

CAL_ENM real32_T MENM_SOC_per[11] =
{
    0.0F, 10.0F, 20.0F, 30.0F, 40.0F, 50.0F, 60.0F, 70.0F, 80.0F, 90.0F, 100.0F
} ;

CAL_ENM real32_T MENM_VehSpd_per[9] =
{
    0.0F, 20.0F, 40.0F, 60.0F, 80.0F, 100.0F, 120.0F, 140.0F, 160.0F
} ;

CAL_ENM uint16_T NEDC_Milg_km_1 = 120U;
CAL_ENM uint32_T Odo_InvalidValue = 1048575U;
CAL_ENM real32_T Proportion_zone0 = 0.07F;
CAL_ENM real32_T Proportion_zone1 = 0.07F;
CAL_ENM real32_T Proportion_zone10 = 0.05F;
CAL_ENM real32_T Proportion_zone11 = 0.04F;
CAL_ENM real32_T Proportion_zone12 = 0.04F;
CAL_ENM real32_T Proportion_zone13 = 0.04F;
CAL_ENM real32_T Proportion_zone14 = 0.04F;
CAL_ENM real32_T Proportion_zone15 = 0.04F;
CAL_ENM real32_T Proportion_zone16 = 0.04F;
CAL_ENM real32_T Proportion_zone17 = 0.04F;
CAL_ENM real32_T Proportion_zone18 = 0.03F;
CAL_ENM real32_T Proportion_zone19 = 0.03F;
CAL_ENM real32_T Proportion_zone2 = 0.07F;
CAL_ENM real32_T Proportion_zone3 = 0.07F;
CAL_ENM real32_T Proportion_zone4 = 0.07F;
CAL_ENM real32_T Proportion_zone5 = 0.05F;
CAL_ENM real32_T Proportion_zone6 = 0.05F;
CAL_ENM real32_T Proportion_zone7 = 0.05F;
CAL_ENM real32_T Proportion_zone8 = 0.05F;
CAL_ENM real32_T Proportion_zone9 = 0.05F;
CAL_ENM int16_T PwrLimit_Hide_W = 500;
CAL_ENM int16_T RR_AveEgyCnseLowlimit = -300;
CAL_ENM int16_T RR_AveEgyCnseUplimit = 1000;
CAL_ENM uint8_T RR_Flat_km = 2U;
CAL_ENM real32_T RR_full_keep_threshold = 100.0F;
CAL_ENM real32_T Recent_Proportion = 0.01F;
CAL_ENM real32_T SOCGAP = 11.0F;
CAL_ENM real32_T SOCJump_EffectPercent = 0.5F;
CAL_ENM uint8_T SOCMAX_INVALID = 255U;
CAL_ENM uint8_T SOCMAX_lowlimit = 90U;
CAL_ENM uint8_T SOCMIN_INVALID = 255U;
CAL_ENM uint8_T SOCMIN_uplimit = 15U;
CAL_ENM uint8_T SOC_HideRelease = 10U;
CAL_ENM uint8_T SOC_InflexionPoint = 30U;
CAL_ENM uint8_T SOC_SmoothHidePercent = 5U;
CAL_ENM uint16_T ZeroSpd_Affirm_s = 20U;

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

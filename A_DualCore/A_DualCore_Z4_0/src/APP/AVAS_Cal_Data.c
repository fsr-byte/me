/*
 * File: AVAS_Cal_Data.c
 *
 * Code generated for Simulink model 'AVAS_Model'.
 *
 * Model version                  : 1.506
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Fri Mar 18 15:40:41 2022
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
#include "AVAS_Model_types.h"

/* Exported data definition */
#include "derivative.h"

/* Definition for custom storage class: CAL_15_AVAS */
CAL_AVAS uint16_T DAVAS_Entry_Speed_High_kph = 20U;
CAL_AVAS uint16_T DAVAS_Entry_Speed_Low_kph = 0U;
CAL_AVAS uint16_T DAVAS_Exit_Speed_High_kph = 20U;
CAL_AVAS uint16_T DAVAS_Exit_Speed_Low_kph = 0U;
CAL_AVAS uint8_T DAVAS_GearD = 4U;
CAL_AVAS uint8_T DAVAS_GearR = 2U;
CAL_AVAS uint16_T DAVAS_WarnEnaTime_ms = 5000U;
CAL_AVAS uint16_T KDSM_BorderCheck_DelayTime = 1000U;
CAL_AVAS int16_T KDSM_ExSeatAxlePos_enum = 300;
CAL_AVAS int16_T KDSM_ImSeatAxlePos_enum = 700;
CAL_AVAS uint16_T KDSM_SeatKey_TrueDelay_ms = 100U;
CAL_AVAS uint16_T KDSM_SeatKey_ZeroDelay_ms = 100U;
CAL_AVAS boolean_T KDSM_SeatToEnd_flg = 0;
CAL_AVAS uint16_T KDSM_StandandMode_delaytime1_ms = 300U;
CAL_AVAS uint16_T KDSM_StandandMode_delaytime2_ms = 500U;
CAL_AVAS boolean_T KDSM_VCUSeatControl_Ena = 0;
CAL_AVAS uint16_T u2s_SeatHallCntChg_DelayTime1_ms = 500U;
CAL_AVAS uint16_T u2s_SeatHallCntChg_DelayTime2_ms = 500U;

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

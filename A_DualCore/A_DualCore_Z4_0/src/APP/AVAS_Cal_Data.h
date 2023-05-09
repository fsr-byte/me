/*
 * File: AVAS_Cal_Data.h
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

#ifndef RTW_HEADER_AVAS_Cal_Data_h_
#define RTW_HEADER_AVAS_Cal_Data_h_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "AVAS_Model_types.h"

/* Exported data define */

/* Definition for custom storage class: Define */
#define Z18_MARK                       14U

/* Exported data declaration */
#include "derivative.h"

/* Declaration for custom storage class: CAL_15_AVAS */
extern CAL_AVAS uint16_T DAVAS_Entry_Speed_High_kph;
extern CAL_AVAS uint16_T DAVAS_Entry_Speed_Low_kph;
extern CAL_AVAS uint16_T DAVAS_Exit_Speed_High_kph;
extern CAL_AVAS uint16_T DAVAS_Exit_Speed_Low_kph;
extern CAL_AVAS uint8_T DAVAS_GearD;
extern CAL_AVAS uint8_T DAVAS_GearR;
extern CAL_AVAS uint16_T DAVAS_WarnEnaTime_ms;
extern CAL_AVAS uint16_T KDSM_BorderCheck_DelayTime;
extern CAL_AVAS int16_T KDSM_ExSeatAxlePos_enum;
extern CAL_AVAS int16_T KDSM_ImSeatAxlePos_enum;
extern CAL_AVAS uint16_T KDSM_SeatKey_TrueDelay_ms;
extern CAL_AVAS uint16_T KDSM_SeatKey_ZeroDelay_ms;
extern CAL_AVAS boolean_T KDSM_SeatToEnd_flg;
extern CAL_AVAS uint16_T KDSM_StandandMode_delaytime1_ms;
extern CAL_AVAS uint16_T KDSM_StandandMode_delaytime2_ms;
extern CAL_AVAS boolean_T KDSM_VCUSeatControl_Ena;
extern CAL_AVAS uint16_T u2s_SeatHallCntChg_DelayTime1_ms;
extern CAL_AVAS uint16_T u2s_SeatHallCntChg_DelayTime2_ms;

#endif                                 /* RTW_HEADER_AVAS_Cal_Data_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

/*
 * File: HAL_Cal_Data.c
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

#include "rtwtypes.h"
#include "HALI_model_types.h"

/* Exported data definition */
#include "derivative.h"

/* Definition for custom storage class: CAL_1_HALI */
CAL_HALI boolean_T KHALI_ACSwitch_ovrdflg = 0;
CAL_HALI boolean_T KHALI_BrkLightSwitch1_ovrdflg = 0;
CAL_HALI boolean_T KHALI_BrkLightSwitch2_ovrdflg = 0;
CAL_HALI boolean_T KHALI_Crank_ovrdflg = 0;
CAL_HALI real32_T KHALI_FastChargeTemp1_Pull_up_R_VCU20 = 1.0F;
CAL_HALI boolean_T KHALI_FastCharge_ovrdflg = 0;
CAL_HALI boolean_T KHALI_FastChrgCANAwake_ovrdflg = 0;
CAL_HALI boolean_T KHALI_GearSwitch1_ovrdflg = 0;
CAL_HALI boolean_T KHALI_GearSwitch2_ovrdflg = 0;
CAL_HALI boolean_T KHALI_GearSwitch3_ovrdflg = 0;
CAL_HALI boolean_T KHALI_GearSwitch4_ovrdflg = 0;
CAL_HALI uint8_T KHALI_HW_VCU20 = 32U;
CAL_HALI boolean_T KHALI_IgnitionOn_ovrdflg = 0;
CAL_HALI boolean_T KHALI_PTCSwitch_ovrdflg = 0;
CAL_HALI boolean_T KHALI_SlowCharge_ovrdflg = 0;
CAL_HALI real32_T KHAL_FastChargeTemp1_Pull_up_R = 1.0F;
CAL_HALI real32_T KHAL_FastChargeTemp1_Pull_up_V = 5.0F;
CAL_HALI real32_T KHAL_FastChargeTemp1_default_R = 10.0F;
CAL_HALI real32_T MHAL_FastChargeTemp1_X_R[15] = { 0.063F, 0.179F, 0.2922F,
  0.5002F, 0.6676F, 0.7754F, 0.904F, 1.058F, 1.2431F, 1.4667F, 1.738F, 2.4734F,
  5.3146F, 32.7547F, 343.632599F } ;

CAL_HALI real32_T MHAL_FastChargeTemp1_X_R_S11P01[16] = { 0.0692F, 0.1844F,
  0.3899F, 0.5108F, 0.6799F, 0.79F, 0.9208F, 1.0766F, 1.263F, 1.4871F, 1.7577F,
  2.4872F, 5.2949F, 12.49F, 32.657F, 290.74F } ;

CAL_HALI real32_T MHAL_FastChargeTemp1_Y_degC[15] = { 200.0F, 150.0F, 130.0F,
  110.0F, 100.0F, 95.0F, 90.0F, 85.0F, 80.0F, 75.0F, 70.0F, 60.0F, 40.0F, 0.0F,
  -40.0F } ;

CAL_HALI real32_T MHAL_FastChargeTemp1_Y_degC_S11P01[16] = { 200.0F, 150.0F,
  120.0F, 110.0F, 100.0F, 95.0F, 90.0F, 85.0F, 80.0F, 75.0F, 70.0F, 60.0F, 40.0F,
  20.0F, 0.0F, -40.0F } ;

CAL_HALI uint8_T UdsAppSWVer[12] = { 48U, 48U, 48U, 48U, 48U, 48U, 48U, 48U, 48U,
  48U, 48U, 48U } ;

CAL_HALI uint8_T UdsCalSWVer[8] = { 48U, 48U, 48U, 48U, 48U, 48U, 48U, 48U } ;

CAL_HALI uint8_T UdsHWVer[12] = { 48U, 48U, 48U, 48U, 48U, 48U, 48U, 48U, 48U,
  48U, 48U, 48U } ;

CAL_HALI uint8_T UdsPartNumber[21] = { 48U, 48U, 48U, 48U, 48U, 48U, 48U, 48U,
  48U, 48U, 48U, 32U, 32U, 32U, 32U, 32U, 32U, 32U, 32U, 32U, 32U } ;

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

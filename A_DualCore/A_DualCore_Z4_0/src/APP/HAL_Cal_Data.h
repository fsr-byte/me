/*
 * File: HAL_Cal_Data.h
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

#ifndef RTW_HEADER_HAL_Cal_Data_h_
#define RTW_HEADER_HAL_Cal_Data_h_
#include "rtwtypes.h"
#include "HALI_model_types.h"

/* Exported data declaration */
#include "derivative.h"

/* Declaration for custom storage class: CAL_1_HALI */
extern CAL_HALI boolean_T KHALI_ACSwitch_ovrdflg;
extern CAL_HALI boolean_T KHALI_BrkLightSwitch1_ovrdflg;
extern CAL_HALI boolean_T KHALI_BrkLightSwitch2_ovrdflg;
extern CAL_HALI boolean_T KHALI_Crank_ovrdflg;
extern CAL_HALI real32_T KHALI_FastChargeTemp1_Pull_up_R_VCU20;
extern CAL_HALI boolean_T KHALI_FastCharge_ovrdflg;
extern CAL_HALI boolean_T KHALI_FastChrgCANAwake_ovrdflg;
extern CAL_HALI boolean_T KHALI_GearSwitch1_ovrdflg;
extern CAL_HALI boolean_T KHALI_GearSwitch2_ovrdflg;
extern CAL_HALI boolean_T KHALI_GearSwitch3_ovrdflg;
extern CAL_HALI boolean_T KHALI_GearSwitch4_ovrdflg;
extern CAL_HALI uint8_T KHALI_HW_VCU20;
extern CAL_HALI boolean_T KHALI_IgnitionOn_ovrdflg;
extern CAL_HALI boolean_T KHALI_PTCSwitch_ovrdflg;
extern CAL_HALI boolean_T KHALI_SlowCharge_ovrdflg;
extern CAL_HALI real32_T KHAL_FastChargeTemp1_Pull_up_R;
extern CAL_HALI real32_T KHAL_FastChargeTemp1_Pull_up_V;
extern CAL_HALI real32_T KHAL_FastChargeTemp1_default_R;
extern CAL_HALI real32_T MHAL_FastChargeTemp1_X_R[15];
extern CAL_HALI real32_T MHAL_FastChargeTemp1_X_R_S11P01[16];
extern CAL_HALI real32_T MHAL_FastChargeTemp1_Y_degC[15];
extern CAL_HALI real32_T MHAL_FastChargeTemp1_Y_degC_S11P01[16];
extern CAL_HALI uint8_T UdsAppSWVer[12];
extern CAL_HALI uint8_T UdsCalSWVer[8];
extern CAL_HALI uint8_T UdsHWVer[12];
extern CAL_HALI uint8_T UdsPartNumber[21];

#endif                                 /* RTW_HEADER_HAL_Cal_Data_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

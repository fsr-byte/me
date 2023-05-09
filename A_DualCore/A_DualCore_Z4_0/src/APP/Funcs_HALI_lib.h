/*
 * File: Funcs_HALI_lib.h
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

#ifndef RTW_HEADER_Funcs_HALI_lib_h_
#define RTW_HEADER_Funcs_HALI_lib_h_
#ifndef HALI_model_COMMON_INCLUDES_
# define HALI_model_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* HALI_model_COMMON_INCLUDES_ */

#include "HALI_model_types.h"

/* Block signals for system '<S2>/Signal_inverter' */
typedef struct {
  boolean_T Switch;                    /* '<S7>/Switch' */
} B_Signal_inverter_HALI_model_T;

extern void HALI_model_Signal_inverter(boolean_T rtu_Sig_In, boolean_T
  rtu_Sig_Invert, B_Signal_inverter_HALI_model_T *localB);

#endif                                 /* RTW_HEADER_Funcs_HALI_lib_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

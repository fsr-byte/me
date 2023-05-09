/*
 * File: DOM_lib.h
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

#ifndef RTW_HEADER_DOM_lib_h_
#define RTW_HEADER_DOM_lib_h_
#ifndef DOM_model_COMMON_INCLUDES_
# define DOM_model_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* DOM_model_COMMON_INCLUDES_ */

#include "DOM_model_types.h"

/* Block signals for system '<S25>/Digital_Output' */
typedef struct {
  boolean_T Switch1;                   /* '<S36>/Switch1' */
} B_Digital_Output_DOM_model_T;

/* Block signals for system '<S26>/Digital_Output' */
typedef struct {
  boolean_T Switch1;                   /* '<S37>/Switch1' */
} B_Digital_Output_DOM_model_i_T;

/* Block signals for system '<S30>/Digital_Output' */
typedef struct {
  boolean_T Switch1;                   /* '<S41>/Switch1' */
} B_Digital_Output_DOM_model_a_T;

/* Block signals for system '<S34>/Digital_Output' */
typedef struct {
  uint8_T Switch1;                     /* '<S45>/Switch1' */
} B_Digital_Output_DOM_model_j_T;

/* Invariant block signals for system '<S26>/Digital_Output' */
typedef struct {
  const boolean_T LogicalOperator;     /* '<S37>/Logical Operator' */
} ConstB_Digital_Output_DOM_m_o_T;

extern void DOM_model_Digital_Output(boolean_T rtu_signal_raw, boolean_T
  rtu_cal_ovrdflg, uint8_T rtu_cal_ovrdval, boolean_T rtu_cal_invert,
  B_Digital_Output_DOM_model_T *localB);
extern void DOM_model_Digital_Output_i(boolean_T rtu_signal_raw, boolean_T
  rtu_cal_ovrdflg, uint8_T rtu_cal_ovrdval, boolean_T rtu_cal_invert,
  B_Digital_Output_DOM_model_i_T *localB, const ConstB_Digital_Output_DOM_m_o_T *
  localC);
extern void DOM_model_Digital_Output_h(boolean_T rtu_signal_raw, boolean_T
  rtu_cal_ovrdflg, boolean_T rtu_cal_ovrdval, boolean_T rtu_cal_invert,
  B_Digital_Output_DOM_model_a_T *localB);
extern void DOM_model_Digital_Output_p(uint8_T rtu_signal_raw, boolean_T
  rtu_cal_ovrdflg, uint8_T rtu_cal_ovrdval, B_Digital_Output_DOM_model_j_T
  *localB);

#endif                                 /* RTW_HEADER_DOM_lib_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

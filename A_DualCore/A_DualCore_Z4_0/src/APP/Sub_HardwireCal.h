/*
 * File: Sub_HardwireCal.h
 *
 * Code generated for Simulink model 'DIM_model'.
 *
 * Model version                  : 1.2422
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Fri Mar 18 15:35:30 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Freescale->32-bit PowerPC
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Sub_HardwireCal_h_
#define RTW_HEADER_Sub_HardwireCal_h_
#ifndef DIM_model_COMMON_INCLUDES_
# define DIM_model_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* DIM_model_COMMON_INCLUDES_ */

#include "DIM_model_types.h"

/* Child system includes */
#include "Funcs_DIM_lib.h"
#include "rt_sys_DIM_model_32.h"
#include "rt_nonfinite.h"

/* Block signals for system '<S1259>/valid_signal_selection' */
typedef struct {
  uint8_T valid_signal;                /* '<S1259>/valid_signal_selection' */
} B_valid_signal_selection_DIM_model_T;

extern void DIM_model_valid_signal_selection_Init
  (B_valid_signal_selection_DIM_model_T *localB);
extern void DIM_model_valid_signal_selection(uint8_T rtu_def_value, uint8_T
  rtu_new_signal, boolean_T rtu_ifault_flg, boolean_T rtu_fault_flg, uint8_T
  rtu_old_signal, B_valid_signal_selection_DIM_model_T *localB);
extern void DIM_model_Sub_HardwireCal_Init(void);
extern void DIM_model_Sub_HardwireCal(void);

#endif                                 /* RTW_HEADER_Sub_HardwireCal_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

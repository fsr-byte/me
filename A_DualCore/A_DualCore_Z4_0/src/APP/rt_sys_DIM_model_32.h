/*
 * File: rt_sys_DIM_model_32.h
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

#ifndef RTW_HEADER_rt_sys_DIM_model_32_h_
#define RTW_HEADER_rt_sys_DIM_model_32_h_
#ifndef DIM_model_COMMON_INCLUDES_
# define DIM_model_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* DIM_model_COMMON_INCLUDES_ */

#include "DIM_model_types.h"

/* Block signals for system '<S173>/Chart' */
typedef struct {
  uint32_T TaskTick;                   /* '<S173>/Chart' */
} B_Chart_DIM_model_T;

/* Block states (auto storage) for system '<S173>/Chart' */
typedef struct {
  uint32_T StartTime;                  /* '<S173>/Chart' */
  uint8_T is_active_c8_DIM_model;      /* '<S173>/Chart' */
  uint8_T is_c8_DIM_model;             /* '<S173>/Chart' */
} DW_Chart_DIM_model_T;

extern void DIM_model_Chart_Init(DW_Chart_DIM_model_T *localDW);
extern void DIM_model_Chart(boolean_T rtu_bool_True, uint32_T rtu_SystemTick,
  B_Chart_DIM_model_T *localB, DW_Chart_DIM_model_T *localDW);

#endif                                 /* RTW_HEADER_rt_sys_DIM_model_32_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

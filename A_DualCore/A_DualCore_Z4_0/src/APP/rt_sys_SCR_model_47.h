/*
 * File: rt_sys_SCR_model_47.h
 *
 * Code generated for Simulink model 'SCR_model'.
 *
 * Model version                  : 1.2266
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Fri Mar 18 15:47:47 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Freescale->32-bit PowerPC
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. MISRA C:2012 guidelines
 * Validation result: Not run
 */

#ifndef RTW_HEADER_rt_sys_SCR_model_47_h_
#define RTW_HEADER_rt_sys_SCR_model_47_h_
#ifndef SCR_model_COMMON_INCLUDES_
# define SCR_model_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#endif                                 /* SCR_model_COMMON_INCLUDES_ */

#include "SCR_model_types.h"

/* Block signals and states (auto storage) for system '<S63>/SetReset' */
typedef struct
{
    uint8_T is_active_c4_SCR_model;    /* '<S63>/SetReset' */
    uint8_T is_c4_SCR_model;           /* '<S63>/SetReset' */
}
rtDW_SetReset_SCR_model_T;

extern void SCR_model_SetReset_Init(boolean_T *rty_output);
extern void SCR_model_SetReset(boolean_T rtu_set, boolean_T rtu_reset, boolean_T
    *rty_output, rtDW_SetReset_SCR_model_T *localDW);

#endif                                 /* RTW_HEADER_rt_sys_SCR_model_47_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

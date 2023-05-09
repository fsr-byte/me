/*
 * File: rt_sys_SCR_model_9.h
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

#ifndef RTW_HEADER_rt_sys_SCR_model_9_h_
#define RTW_HEADER_rt_sys_SCR_model_9_h_
#ifndef SCR_model_COMMON_INCLUDES_
# define SCR_model_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#endif                                 /* SCR_model_COMMON_INCLUDES_ */

#include "SCR_model_types.h"

/* Block signals and states (auto storage) for system '<S13>/dataLatch' */
typedef struct
{
    uint8_T is_active_c2_OverRide;     /* '<S20>/02 set and reset' */
    uint8_T is_c2_OverRide;            /* '<S20>/02 set and reset' */
}
rtDW_dataLatch_SCR_model_T;

extern void SCR_model_dataLatch_Init(boolean_T *rty_out);
extern void SCR_model_dataLatch(boolean_T rtu_S, boolean_T rtu_R, boolean_T
    *rty_out, rtDW_dataLatch_SCR_model_T *localDW, boolean_T rtp_ic);

#endif                                 /* RTW_HEADER_rt_sys_SCR_model_9_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

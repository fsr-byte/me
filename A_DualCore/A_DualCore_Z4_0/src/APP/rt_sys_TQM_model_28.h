/*
 * File: rt_sys_TQM_model_28.h
 *
 * Code generated for Simulink model 'TQM_model'.
 *
 * Model version                  : 1.3587
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Fri Mar 18 15:45:56 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Freescale->32-bit PowerPC
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. MISRA C:2012 guidelines
 * Validation result: Not run
 */

#ifndef RTW_HEADER_rt_sys_TQM_model_28_h_
#define RTW_HEADER_rt_sys_TQM_model_28_h_
#ifndef TQM_model_COMMON_INCLUDES_
# define TQM_model_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* TQM_model_COMMON_INCLUDES_ */

#include "TQM_model_types.h"

/* Block signals and states (auto storage) for system '<S53>/Bilateral_Delay' */
typedef struct
{
    uint16_T Delay_DSTATE;             /* '<S54>/Delay' */
    uint16_T Delay3_DSTATE;            /* '<S54>/Delay3' */
    boolean_T Delay1_DSTATE;           /* '<S54>/Delay1' */
    boolean_T Delay2_DSTATE;           /* '<S54>/Delay2' */
    boolean_T Delay4_DSTATE;           /* '<S54>/Delay4' */
}
rtDW_Bilateral_Delay_TQM_mode_T;

extern void TQM_model_Bilateral_Delay(boolean_T rtu_Input, uint32_T
    rtu_Step_Time, boolean_T *rty_Output, rtDW_Bilateral_Delay_TQM_mode_T
    *localDW, uint16_T rtp_TrueDelay_Time, uint16_T rtp_ZeroDelay_Time);

#endif                                 /* RTW_HEADER_rt_sys_TQM_model_28_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

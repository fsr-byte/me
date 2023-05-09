/*
 * File: rt_sys_SCR_model_46.h
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

#ifndef RTW_HEADER_rt_sys_SCR_model_46_h_
#define RTW_HEADER_rt_sys_SCR_model_46_h_
#ifndef SCR_model_COMMON_INCLUDES_
# define SCR_model_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#endif                                 /* SCR_model_COMMON_INCLUDES_ */

#include "SCR_model_types.h"

/* Block signals and states (auto storage) for system '<S63>/ON_DelayTime_Judge' */
typedef struct
{
    uint32_T Delay_DSTATE;             /* '<S67>/Delay' */
    boolean_T Delay1_DSTATE;           /* '<S67>/Delay1' */
}
rtDW_ON_DelayTime_Judge_SCR_m_T;

extern void SCR_model_ON_DelayTime_Judge(boolean_T rtu_Input, uint32_T
    rtu_Step_Time, uint16_T rtu_Delay_Time, boolean_T *rty_Output,
    rtDW_ON_DelayTime_Judge_SCR_m_T *localDW);

#endif                                 /* RTW_HEADER_rt_sys_SCR_model_46_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

/*
 * File: CLTC_Control.h
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

#ifndef RTW_HEADER_CLTC_Control_h_
#define RTW_HEADER_CLTC_Control_h_
#ifndef SCR_model_COMMON_INCLUDES_
# define SCR_model_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#endif                                 /* SCR_model_COMMON_INCLUDES_ */

#include "SCR_model_types.h"

/* Child system includes */
#include "rt_sys_SCR_model_11.h"
#include "rt_sys_SCR_model_7.h"
#include "rt_sys_SCR_model_9.h"

/* Block signals and states (auto storage) for system '<S15>/Bilateral_Delay' */
typedef struct
{
    uint16_T Delay_DSTATE;             /* '<S23>/Delay' */
    uint16_T Delay3_DSTATE;            /* '<S23>/Delay3' */
    boolean_T Delay1_DSTATE;           /* '<S23>/Delay1' */
    boolean_T Delay2_DSTATE;           /* '<S23>/Delay2' */
    boolean_T Delay4_DSTATE;           /* '<S23>/Delay4' */
}
rtDW_Bilateral_Delay_SCR_mode_T;

extern void SCR_model_Bilateral_Delay(boolean_T rtu_Input, uint32_T
    rtu_Step_Time, boolean_T *rty_Output, rtDW_Bilateral_Delay_SCR_mode_T
    *localDW, uint16_T rtp_TrueDelay_Time, uint16_T rtp_ZeroDelay_Time);
extern void SCR_model_TargetAccCal(void);
extern void SCR_model_CLTC_Control_Init(void);
extern void SCR_model_CLTC_Control(void);

#endif                                 /* RTW_HEADER_CLTC_Control_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

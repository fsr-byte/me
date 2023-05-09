/*
 * File: Brake_Lamp_Control.h
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

#ifndef RTW_HEADER_Brake_Lamp_Control_h_
#define RTW_HEADER_Brake_Lamp_Control_h_
#ifndef TQM_model_COMMON_INCLUDES_
# define TQM_model_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* TQM_model_COMMON_INCLUDES_ */

#include "TQM_model_types.h"

/* Child system includes */
#include "rt_sys_TQM_model_236.h"
#include "rt_sys_TQM_model_28.h"

/* Block signals and states (auto storage) for system '<S556>/Hysteresis_LeftTrue' */
typedef struct
{
    boolean_T Delay_DSTATE;            /* '<S568>/Delay' */
}
rtDW_Hysteresis_LeftTrue_TQ_g_T;

/* Block signals and states (auto storage) for system '<S556>/Hysteresis_RightTrue' */
typedef struct
{
    boolean_T Delay_DSTATE;            /* '<S569>/Delay' */
}
rtDW_Hysteresis_RightTrue_T_m_T;

extern void TQM_model_Hysteresis_LeftTrue_n(int16_T rtu_Input, boolean_T
    *rty_Output, rtDW_Hysteresis_LeftTrue_TQ_g_T *localDW, int16_T rtp_leftpoint,
    int16_T rtp_rightpoint);
extern void TQM_mode_Hysteresis_RightTrue_k(int16_T rtu_Input, boolean_T
    *rty_Output, rtDW_Hysteresis_RightTrue_T_m_T *localDW, int16_T rtp_leftpoint,
    int16_T rtp_rightpoint);
extern void TQM_model_Brake_Lamp_Control(void);

#endif                                 /* RTW_HEADER_Brake_Lamp_Control_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

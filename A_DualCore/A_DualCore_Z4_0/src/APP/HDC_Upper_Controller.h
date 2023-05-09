/*
 * File: HDC_Upper_Controller.h
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

#ifndef RTW_HEADER_HDC_Upper_Controller_h_
#define RTW_HEADER_HDC_Upper_Controller_h_
#include <math.h>
#ifndef SCR_model_COMMON_INCLUDES_
# define SCR_model_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#endif                                 /* SCR_model_COMMON_INCLUDES_ */

#include "SCR_model_types.h"

/* Child system includes */
#include "rt_sys_SCR_model_11.h"
#include "rt_sys_SCR_model_144.h"
#include "rt_sys_SCR_model_7.h"
#include "rt_sys_SCR_model_9.h"

/* Block signals and states (auto storage) for system '<S172>/Bilateral_Delay' */
typedef struct
{
    uint32_T Delay_DSTATE;             /* '<S205>/Delay' */
    uint32_T Delay3_DSTATE;            /* '<S205>/Delay3' */
    boolean_T Delay1_DSTATE;           /* '<S205>/Delay1' */
    boolean_T Delay2_DSTATE;           /* '<S205>/Delay2' */
    boolean_T Delay4_DSTATE;           /* '<S205>/Delay4' */
}
rtDW_Bilateral_Delay_SCR_mo_h_T;

/* Block signals and states (auto storage) for system '<S213>/Differential' */
typedef struct
{
    uint32_T Delay1_DSTATE[2];         /* '<S242>/Delay1' */
    uint32_T Delay2_DSTATE[3];         /* '<S242>/Delay2' */
    uint32_T Delay_DSTATE;             /* '<S242>/Delay' */
}
rtDW_Differential_SCR_model_T;

/* Block signals and states (auto storage) for system '<S213>/IA_Filter_module' */
typedef struct
{
    int32_T UnitDelay1_DSTATE;         /* '<S251>/Unit Delay1' */
    boolean_T UnitDelay_DSTATE;        /* '<S251>/Unit Delay' */
}
rtDW_IA_Filter_module_SCR_m_b_T;

/* Block signals and states (auto storage) for system '<S213>/Kalman_Filter' */
typedef struct
{
    real32_T Delay1_DSTATE;            /* '<S244>/Delay1' */
    real32_T Delay_DSTATE;             /* '<S244>/Delay' */
    uint8_T icLoad;                    /* '<S244>/Delay1' */
    uint8_T icLoad_d;                  /* '<S244>/Delay' */
}
rtDW_Kalman_Filter_SCR_model_T;

extern void SCR_model_Bilateral_Delay_c(boolean_T rtu_Input, uint32_T
    rtu_Step_Time, boolean_T *rty_Output, rtDW_Bilateral_Delay_SCR_mo_h_T
    *localDW, uint32_T rtp_TrueDelay_Time, uint32_T rtp_ZeroDelay_Time);
extern void SCR_model_Differential(uint32_T rtu_Input, uint32_T rtu_Sample_Time,
    int32_T *rty_Output, rtDW_Differential_SCR_model_T *localDW);
extern void SCR_model_IA_Filter_module_d(real32_T rtu_Signal_in, uint32_T
    rtu_Filter_dT, int32_T *rty_Signal_out, rtDW_IA_Filter_module_SCR_m_b_T
    *localDW, uint8_T rtp_Filter_T);
extern void SCR_model_Kalman_Filter_Init(rtDW_Kalman_Filter_SCR_model_T *localDW);
extern void SCR_model_Kalman_Filter(real32_T rtu_INP, real32_T *rty_OUT,
    rtDW_Kalman_Filter_SCR_model_T *localDW, real32_T rtp_Cal_Kalman_Q, real32_T
    rtp_Cal_Kalman_P, real32_T rtp_Cal_Kalman_R);
extern void SCR_m_HDC_Upper_Controller_Init(void);
extern void SCR_model_HDC_Upper_Controller(void);

#endif                                 /* RTW_HEADER_HDC_Upper_Controller_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

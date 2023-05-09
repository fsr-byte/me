/*
 * File: Input.h
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

#ifndef RTW_HEADER_Input_h_
#define RTW_HEADER_Input_h_
#include <math.h>
#ifndef TQM_model_COMMON_INCLUDES_
# define TQM_model_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* TQM_model_COMMON_INCLUDES_ */

#include "TQM_model_types.h"

/* Child system includes */
#include "ABS_Process.h"
#include "BMS_Process.h"
#include "BrakeSts_Process.h"
#include "Clutch_Process.h"
#include "CoastRegenGrade_Process.h"
#include "Creep_Process.h"
#include "DSI.h"
#include "EPB_Process.h"
#include "rt_sys_TQM_model_12.h"
#include "rt_sys_TQM_model_55.h"

/* Block signals and states (auto storage) for system '<S77>/Differential' */
typedef struct
{
    real32_T Delay1_DSTATE[2];         /* '<S79>/Delay1' */
    real32_T Delay2_DSTATE[3];         /* '<S79>/Delay2' */
    real32_T Delay_DSTATE;             /* '<S79>/Delay' */
}
rtDW_Differential_TQM_model_T;

/* Block signals and states (auto storage) for system '<S81>/IA_Filter_module' */
typedef struct
{
    int32_T UnitDelay_DSTATE;          /* '<S85>/Unit Delay' */
}
rtDW_IA_Filter_module_TQM_m_j_T;

/* Block signals and states (auto storage) for system '<S99>/Differential' */
typedef struct
{
    uint32_T Delay1_DSTATE[2];         /* '<S101>/Delay1' */
    uint32_T Delay2_DSTATE[3];         /* '<S101>/Delay2' */
    uint32_T Delay_DSTATE;             /* '<S101>/Delay' */
}
rtDW_Differential_TQM_model_o_T;

/* Block signals and states (auto storage) for system '<S102>/Hysteresis_RightTrue' */
typedef struct
{
    boolean_T Delay_DSTATE;            /* '<S104>/Delay' */
}
rtDW_Hysteresis_RightTrue_TQM_T;

extern void TQM_model_Differential(real32_T rtu_Input, uint32_T rtu_Sample_Time,
    int32_T *rty_Output, rtDW_Differential_TQM_model_T *localDW);
extern void TQM_model_IA_Filter_module_e(real32_T rtu_Signal_in, uint32_T
    rtu_Filter_dT, int32_T *rty_Signal_out, rtDW_IA_Filter_module_TQM_m_j_T
    *localDW, uint16_T rtp_Filter_T);
extern void TQM_model_Differential_p(uint32_T rtu_Input, uint32_T
    rtu_Sample_Time, int32_T *rty_Output, rtDW_Differential_TQM_model_o_T
    *localDW);
extern void TQM_model_Hysteresis_RightTrue(uint16_T rtu_Input, boolean_T
    *rty_Output, rtDW_Hysteresis_RightTrue_TQM_T *localDW, uint16_T
    rtp_leftpoint, uint16_T rtp_rightpoint);
extern void TQM_model_Get_TickDiff_ms_Init(void);
extern void TQM_model_Get_TickDiff_ms(void);
extern void TQM_model_ActAclCalculate_Init(void);
extern void TQM_model_ActAclCalculate(void);
extern void TQM_model_Input_Init(void);
extern void TQM_model_Input(void);

#endif                                 /* RTW_HEADER_Input_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

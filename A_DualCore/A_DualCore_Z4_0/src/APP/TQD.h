/*
 * File: TQD.h
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

#ifndef RTW_HEADER_TQD_h_
#define RTW_HEADER_TQD_h_
#include <math.h>
#ifndef TQM_model_COMMON_INCLUDES_
# define TQM_model_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* TQM_model_COMMON_INCLUDES_ */

#include "TQM_model_types.h"

/* Child system includes */
#include "NEDC.h"
#include "WorkingConditionArbitirator.h"
#include "rt_sys_TQM_model_12.h"
#include "rt_sys_TQM_model_236.h"
#include "rt_sys_TQM_model_28.h"
#include "rt_sys_TQM_model_55.h"

/* Block signals and states (auto storage) for system '<S250>/dataLatch1' */
typedef struct
{
    uint8_T is_active_c2_OverRide;     /* '<S270>/02 set and reset' */
    uint8_T is_c2_OverRide;            /* '<S270>/02 set and reset' */
}
rtDW_dataLatch_TQM_model_T;

/* Block signals and states (auto storage) for system '<S252>/Hysteresis_RightTrue' */
typedef struct
{
    boolean_T Delay_DSTATE;            /* '<S285>/Delay' */
}
rtDW_Hysteresis_RightTrue_T_g_T;

/* Block signals and states (auto storage) for system '<S256>/Hysteresis_LeftTrue' */
typedef struct
{
    boolean_T Delay_DSTATE;            /* '<S311>/Delay' */
}
rtDW_Hysteresis_LeftTrue_TQM__T;

/* Block signals and states (auto storage) for system '<S314>/Hysteresis_LeftTrue' */
typedef struct
{
    boolean_T Delay_DSTATE;            /* '<S317>/Delay' */
}
rtDW_Hysteresis_LeftTrue_TQ_o_T;

/* Block signals and states (auto storage) for system '<S314>/Hysteresis_RightTrue' */
typedef struct
{
    boolean_T Delay_DSTATE;            /* '<S318>/Delay' */
}
rtDW_Hysteresis_RightTrue_T_f_T;

/* Block signals and states (auto storage) for system '<S401>/Hysteresis_LeftTrue1' */
typedef struct
{
    boolean_T Delay_DSTATE;            /* '<S404>/Delay' */
}
rtDW_Hysteresis_LeftTrue_TQ_i_T;

extern void TQM_model_dataLatch_Init(boolean_T *rty_out);
extern void TQM_model_dataLatch(boolean_T rtu_S, boolean_T rtu_R, boolean_T
    *rty_out, rtDW_dataLatch_TQM_model_T *localDW, boolean_T rtp_ic);
extern void TQM_mode_Hysteresis_RightTrue_g(real32_T rtu_Input, boolean_T
    *rty_Output, rtDW_Hysteresis_RightTrue_T_g_T *localDW, uint16_T
    rtp_leftpoint, uint16_T rtp_rightpoint);
extern void TQM_model_Hysteresis_LeftTrue(int16_T rtu_Input, boolean_T
    *rty_Output, rtDW_Hysteresis_LeftTrue_TQM__T *localDW, int16_T rtp_leftpoint,
    int16_T rtp_rightpoint);
extern void TQM_model_Hysteresis_LeftTrue_k(int16_T rtu_Input, boolean_T
    *rty_Output, rtDW_Hysteresis_LeftTrue_TQ_o_T *localDW, int16_T rtp_leftpoint,
    int16_T rtp_rightpoint);
extern void TQM_mod_Hysteresis_RightTrue_gv(int16_T rtu_Input, boolean_T
    *rty_Output, rtDW_Hysteresis_RightTrue_T_f_T *localDW, int16_T rtp_leftpoint,
    int16_T rtp_rightpoint);
extern void TQM_model_OverRide_a(uint8_T rtu_input, uint8_T *rty_Output, uint8_T
    rtp_Value, boolean_T rtp_Enable);
extern void TQM_model_Hysteresis_LeftTrue1(int16_T rtu_Input, boolean_T
    *rty_Output, rtDW_Hysteresis_LeftTrue_TQ_i_T *localDW, uint16_T
    rtp_leftpoint, uint16_T rtp_rightpoint);
extern void TQM_mode_Get_TickDiff_ms_i_Init(void);
extern void TQM_model_Get_TickDiff_ms_m(void);
extern void TQM_model_Booster_Condition(void);
extern void TQM_model_ESC_Condition(void);
extern void TQM_model_Cruise_Condition(void);
extern void TQM_model_RegenForbid_Condition(void);
extern void TQM_mode_CoastDriving_Condition(void);
extern void TQM_mode_BrakeDriving_Condition(void);
extern void TQM_mod_AccPedalPress_Condition(void);
extern void TQM_mo_AntiSlide_Condition_Init(void);
extern void TQM_model_AntiSlide_Condition(void);
extern void TQM_model_Creep_Condition(void);
extern void TQM_model_NEDC_Condition_Init(void);
extern void TQM_model_NEDC_Condition(void);
extern void TQM__Vehicle_Drivable_Determine(void);
extern void T_WorkingConditionIdentify_Init(void);
extern void TQM_mo_WorkingConditionIdentify(void);
extern void TQM_model_ACC_Condition(void);
extern void TQM_model_AEB_Condition(void);
extern void TQM_model_APA_Condition(void);
extern void TQM_model_Default_TqDmd(void);
extern void AcceleratedSpdLoopCtrl_AccelTq_(void);
extern void TQM_model_GearD_AccelTq_Cal(void);
extern void TQ_TorqueCtrl_Forward_Driver_Tq(void);
extern void TQ_TorqueCtrl_Reverse_Driver_Tq(void);
extern void TQM_model_Default_Tq(void);
extern void TQM__TorqueCtrl_AccelTq_Process(void);
extern void Acceleration_Condition_Disable(void);
extern void TQM_mode_Acceleration_Condition(void);
extern void TQM_model_AnitSlide_S_Process(void);
extern void TQM_model_K11_MCUAntiSlide(void);
extern void TQM_AntiSlide_Condition_Disable(void);
extern void TQM_model_AntiSlide_Condition_h(void);
extern void TQM_mod_Booster_Condition_Reset(void);
extern void TQM_m_Booster_Condition_Disable(void);
extern void TQM_model_Booster_Condition_k(void);
extern void TQM_model_Brake_Condition_Reset(void);
extern void TQM_mod_Brake_Condition_Disable(void);
extern void TQM_model_Brake_Condition(void);
extern void TQM_model_CLTC_Condition(void);
extern void TQM_model_CloseToGear_Process(void);
extern void AcceleratedSpdLoopCtrl_CoastTq_(void);
extern void TQM__TorqueCtrl_CoastTq_Process(void);
extern void TQM_mod_Coast_Condition_Disable(void);
extern void TQM_model_Coast_Condition(void);
extern void TQM_mod_Creep_Condition_p_Reset(void);
extern void TQM_mod_Creep_Condition_Disable(void);
extern void TQM_model_Creep_Condition_m(void);
extern void TQM_model_CruiseCtrl_Condition(void);
extern void TQM_model_ESC_Condition_l(void);
extern void TQM_model_HDC_Condition(void);
extern void TQM_model_NEDC_Condition_g(void);
extern void TQM_mod_RegenForbid_Condition_j(void);
extern void TQM_model_RunForbid_Condition(void);
extern void WorkingConditionTorqueAnalysis(void);
extern void TQM_model_TQD_Init(void);
extern void TQM_model_TQD(void);

#endif                                 /* RTW_HEADER_TQD_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

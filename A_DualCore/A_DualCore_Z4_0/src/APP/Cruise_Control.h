/*
 * File: Cruise_Control.h
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

#ifndef RTW_HEADER_Cruise_Control_h_
#define RTW_HEADER_Cruise_Control_h_
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
#include "rt_sys_SCR_model_46.h"
#include "rt_sys_SCR_model_47.h"
#include "rt_sys_SCR_model_9.h"

/* Block signals and states (auto storage) for system '<S93>/IA_Filter_module' */
typedef struct
{
    int32_T UnitDelay1_DSTATE;         /* '<S120>/Unit Delay1' */
    boolean_T UnitDelay_DSTATE;        /* '<S120>/Unit Delay' */
}
rtDW_IA_Filter_module_SCR_mod_T;

/* Block signals and states (auto storage) for system '<S86>/ON_DelayTime_Judge3' */
typedef struct
{
    uint32_T Delay_DSTATE;             /* '<S103>/Delay' */
    boolean_T Delay1_DSTATE;           /* '<S103>/Delay1' */
}
rtDW_ON_DelayTime_Judge_SCR_o_T;

/* Block signals and states (auto storage) for system '<S86>/Zero_Delay' */
typedef struct
{
    uint32_T Delay_DSTATE;             /* '<S113>/Delay' */
    boolean_T Delay1_DSTATE;           /* '<S113>/Delay1' */
}
rtDW_Zero_Delay_SCR_model_T;

/* Block signals and states (auto storage) for system '<S131>/SetReset' */
typedef struct
{
    uint8_T is_active_c5_SpdCtl_lib;   /* '<S131>/SetReset' */
    uint8_T is_c5_SpdCtl_lib;          /* '<S131>/SetReset' */
}
rtDW_SetReset_SCR_model_k_T;

/* Block signals and states (auto storage) for system '<S124>/Key_ShortLongPress' */
typedef struct
{
    uint32_T temporalCounter_i1;       /* '<S124>/Key_ShortLongPress' */
    uint8_T is_active_c12_SpdCtl_lib;  /* '<S124>/Key_ShortLongPress' */
    uint8_T is_c12_SpdCtl_lib;         /* '<S124>/Key_ShortLongPress' */
    uint8_T is_On;                     /* '<S124>/Key_ShortLongPress' */
}
rtDW_Key_ShortLongPress_SCR_m_T;

/* Block signals and states (auto storage) for system '<S35>/True_Delay' */
typedef struct
{
    uint8_T Delay_DSTATE;              /* '<S83>/Delay' */
    boolean_T Delay1_DSTATE;           /* '<S83>/Delay1' */
}
rtDW_True_Delay_SCR_model_a_T;

extern void SCR_model_IA_Filter_module(real32_T rtu_Signal_in, uint32_T
    rtu_Filter_dT, int32_T *rty_Signal_out, rtDW_IA_Filter_module_SCR_mod_T
    *localDW, uint16_T rtp_Filter_T);
extern void SCR_model_ON_DelayTime_Judge3(boolean_T rtu_Input, uint32_T
    rtu_Step_Time, uint32_T rtu_Delay_Time, boolean_T *rty_Output,
    rtDW_ON_DelayTime_Judge_SCR_o_T *localDW);
extern void SCR_model_Zero_Delay(boolean_T rtu_Input, uint32_T rtu_Step_Time,
    boolean_T *rty_Output, rtDW_Zero_Delay_SCR_model_T *localDW, uint32_T
    rtp_Delay_Time);
extern void SCR_model_SetReset_l_Init(boolean_T *rty_output);
extern void SCR_model_SetReset_n(boolean_T rtu_set, boolean_T rtu_reset,
    boolean_T *rty_output, rtDW_SetReset_SCR_model_k_T *localDW);
extern void SCR_mod_Key_ShortLongPress_Init(uint8_T *rty_u1s_key_status,
    uint32_T *rty_u4s_keyPressCnt);
extern void SCR_model_Key_ShortLongPress(boolean_T rtu_key_press_flg, uint16_T
    rtu_KeyShortPress_MinTime, uint16_T rtu_KeyLongPress_MinTime, uint32_T
    rtu_ShortPress_HoldTime, uint32_T rtu_SampleTime, uint32_T
    rtu_KeyShortPress_MaxTime, boolean_T rtu_bis_WorkMode_flg, uint8_T
    *rty_u1s_key_status, uint32_T *rty_u4s_keyPressCnt,
    rtDW_Key_ShortLongPress_SCR_m_T *localDW);
extern void SCR_model_OverRide1(boolean_T rtu_input, boolean_T *rty_Output,
    uint8_T rtp_Value, boolean_T rtp_Enable);
extern void SCR_model_OverRide3(uint8_T rtu_input, uint8_T *rty_Output, uint8_T
    rtp_Value, boolean_T rtp_Enable);
extern void SCR_model_True_Delay_a(boolean_T rtu_Input, uint32_T rtu_Step_Time,
    boolean_T *rty_Output, rtDW_True_Delay_SCR_model_a_T *localDW, uint8_T
    rtp_Delay_Time);
extern void SCR_mod_CruiseDiagnostic_Update(void);
extern void SCR_model_CruiseDiagnostic(void);
extern void SCR_model_KeyJudge_Init(void);
extern void SCR_model_KeyJudge(void);
extern void SCR_model_KeyJudge1_Init(void);
extern void SCR_model_KeyJudge1(void);
extern void SCR_model_KeyPressJudge_Init(void);
extern void SCR_model_KeyPressJudge(void);
extern void SCR_model_KeyPressJudge1_Init(void);
extern void SCR_model_KeyPressJudge1(void);
extern void SCR_model_KeyPressJudge2_Init(void);
extern void SCR_model_KeyPressJudge2(void);
extern void SCR_model_Subsystem(void);
extern void SCR_CruiseKey_Recoginition_Init(void);
extern void SCR_mode_CruiseKey_Recoginition(void);
extern void SCR_mo_CruiseOverride_Judgement(void);
extern void SCR_model_GearD_Judgement(void);
extern void SCR_model_Cruise_Control_Init(void);
extern void SCR_model_Cruise_Control(void);

#endif                                 /* RTW_HEADER_Cruise_Control_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

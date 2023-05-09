/*
 * File: CHRG_lib.h
 *
 * Code generated for Simulink model 'CHRG_Model'.
 *
 * Model version                  : 1.1917
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Fri Mar 18 15:31:54 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Freescale->32-bit PowerPC
 * Code generation objectives:
 *    1. RAM efficiency
 *    2. ROM efficiency
 *    3. Execution efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_CHRG_lib_h_
#define RTW_HEADER_CHRG_lib_h_
#ifndef CHRG_Model_COMMON_INCLUDES_
# define CHRG_Model_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#endif                                 /* CHRG_Model_COMMON_INCLUDES_ */

#include "CHRG_Model_types.h"

/* Block signals for system '<S67>/PMMSignalConfirm' */
typedef struct
{
    boolean_T RelationalOperator3;     /* '<S71>/Relational Operator3' */
}
rtB_PMMSignalConfirm_CHRG_Mod_T;

/* Block states (auto storage) for system '<S67>/PMMSignalConfirm' */
typedef struct
{
    uint32_T UnitDelay_DSTATE;         /* '<S71>/Unit Delay' */
}
rtDW_PMMSignalConfirm_CHRG_Mo_T;

/* Block signals for system '<S12>/SignalConfirm1' */
typedef struct
{
    boolean_T RelationalOperator3;     /* '<S70>/Relational Operator3' */
}
rtB_PMMSignalConfirm_CHRG_M_o_T;

/* Block states (auto storage) for system '<S12>/SignalConfirm1' */
typedef struct
{
    uint32_T UnitDelay_DSTATE;         /* '<S70>/Unit Delay' */
}
rtDW_PMMSignalConfirm_CHRG__b_T;

/* Block signals for system '<S76>/PMMSignalConfirm' */
typedef struct
{
    uint32_T Add;                      /* '<S84>/Add' */
    boolean_T RelationalOperator3;     /* '<S84>/Relational Operator3' */
}
rtB_PMMSignalConfirm_CHRG_M_f_T;

/* Block states (auto storage) for system '<S76>/PMMSignalConfirm' */
typedef struct
{
    uint32_T UnitDelay_DSTATE;         /* '<S84>/Unit Delay' */
}
rtDW_PMMSignalConfirm_CHRG__c_T;

/* Block signals for system '<S6>/CMM_Delay_Conferm' */
typedef struct
{
    boolean_T debounce;                /* '<S37>/debounce' */
}
rtB_CMM_Delay_Conferm_CHRG_Mo_T;

/* Block states (auto storage) for system '<S6>/CMM_Delay_Conferm' */
typedef struct
{
    int32_T Delay2_DSTATE;             /* '<S38>/Delay2' */
    boolean_T Delay_DSTATE;            /* '<S37>/Delay' */
    boolean_T Delay1_DSTATE;           /* '<S37>/Delay1' */
}
rtDW_CMM_Delay_Conferm_CHRG_M_T;

extern void CHRG_Mode_PMMSignalConfirm_Init(rtDW_PMMSignalConfirm_CHRG_Mo_T
    *localDW);
extern void CHRG_Mod_PMMSignalConfirm_Reset(rtDW_PMMSignalConfirm_CHRG_Mo_T
    *localDW);
extern void CHRG_Model_PMMSignalConfirm(boolean_T rtu_True_Flag, uint16_T
    rtu_SingalConfirmTime, rtB_PMMSignalConfirm_CHRG_Mod_T *localB,
    rtDW_PMMSignalConfirm_CHRG_Mo_T *localDW, uint8_T rtp_SAMPLETIME);
extern void CHRG_Model_SignalConfirm1_Init(rtDW_PMMSignalConfirm_CHRG__b_T
    *localDW);
extern void CHRG_Model_SignalConfirm1_Reset(rtDW_PMMSignalConfirm_CHRG__b_T
    *localDW);
extern void CHRG_Model_SignalConfirm1(boolean_T rtu_True_Flag, uint32_T
    rtu_SingalConfirmTime, rtB_PMMSignalConfirm_CHRG_M_o_T *localB,
    rtDW_PMMSignalConfirm_CHRG__b_T *localDW, uint8_T rtp_SAMPLETIME);
extern void CHRG_Mo_PMMSignalConfirm_h_Init(rtDW_PMMSignalConfirm_CHRG__c_T
    *localDW);
extern void CHRG_M_PMMSignalConfirm_b_Reset(rtDW_PMMSignalConfirm_CHRG__c_T
    *localDW);
extern void CHRG__PMMSignalConfirm_m_Update(rtB_PMMSignalConfirm_CHRG_M_f_T
    *localB, rtDW_PMMSignalConfirm_CHRG__c_T *localDW);
extern void CHRG_Model_PMMSignalConfirm_h(const boolean_T *rtu_True_Flag,
    uint32_T rtu_SingalConfirmTime, rtB_PMMSignalConfirm_CHRG_M_f_T *localB,
    rtDW_PMMSignalConfirm_CHRG__c_T *localDW, uint8_T rtp_SAMPLETIME);
extern void CHRG_Mod_CMM_Delay_Conferm_Init(rtDW_CMM_Delay_Conferm_CHRG_M_T
    *localDW);
extern void CHRG_Mo_CMM_Delay_Conferm_Reset(rtDW_CMM_Delay_Conferm_CHRG_M_T
    *localDW);
extern void CHRG_Model_CMM_Delay_Conferm(boolean_T rtu_din, uint16_T rtu_t_dbnc,
    uint32_T rtu_ms_diff, rtB_CMM_Delay_Conferm_CHRG_Mo_T *localB,
    rtDW_CMM_Delay_Conferm_CHRG_M_T *localDW);

#endif                                 /* RTW_HEADER_CHRG_lib_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

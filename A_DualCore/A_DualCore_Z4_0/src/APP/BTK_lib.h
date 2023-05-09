/*
 * File: BTK_lib.h
 *
 * Code generated for Simulink model 'BTK_Model'.
 *
 * Model version                  : 1.4445
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Fri Mar 18 15:41:24 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Freescale->32-bit PowerPC
 * Code generation objectives:
 *    1. RAM efficiency
 *    2. ROM efficiency
 *    3. Execution efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_BTK_lib_h_
#define RTW_HEADER_BTK_lib_h_
#ifndef BTK_Model_COMMON_INCLUDES_
# define BTK_Model_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#endif                                 /* BTK_Model_COMMON_INCLUDES_ */

#include "BTK_Model_types.h"

/* Block signals for system '<S5>/BTKSignalConfirm' */
typedef struct
{
    boolean_T RelationalOperator3;     /* '<S22>/Relational Operator3' */
}
rtB_BTKSignalConfirm_BTK_Mode_T;

/* Block states (auto storage) for system '<S5>/BTKSignalConfirm' */
typedef struct
{
    uint32_T UnitDelay_DSTATE;         /* '<S22>/Unit Delay' */
}
rtDW_BTKSignalConfirm_BTK_Mod_T;

/* Block signals for system '<S27>/BTK_Delay_Confirm' */
typedef struct
{
    boolean_T debounce;                /* '<S28>/debounce' */
}
rtB_BTK_Delay_Confirm_BTK_Mod_T;

/* Block states (auto storage) for system '<S27>/BTK_Delay_Confirm' */
typedef struct
{
    int32_T Delay2_DSTATE;             /* '<S29>/Delay2' */
    boolean_T Delay_DSTATE;            /* '<S28>/Delay' */
}
rtDW_BTK_Delay_Confirm_BTK_Mo_T;

/* Block signals for system '<S10>/BTKTimeoutCustomTimer' */
typedef struct
{
    boolean_T RelationalOperator3;     /* '<S55>/Relational Operator3' */
}
rtB_BTKTimeoutCustomTimer_BTK_T;

/* Block states (auto storage) for system '<S10>/BTKTimeoutCustomTimer' */
typedef struct
{
    uint32_T UnitDelay_DSTATE;         /* '<S55>/Unit Delay' */
}
rtDW_BTKTimeoutCustomTimer_BT_T;

extern void BTK_Model_BTKSignalConfirm_Init(rtDW_BTKSignalConfirm_BTK_Mod_T
    *localDW);
extern void BTK_Mode_BTKSignalConfirm_Reset(rtDW_BTKSignalConfirm_BTK_Mod_T
    *localDW);
extern void BTK_Model_BTKSignalConfirm(boolean_T rtu_True_Flag, uint32_T
    rtu_SingalConfirmTime, uint32_T rtu_simple, rtB_BTKSignalConfirm_BTK_Mode_T *
    localB, rtDW_BTKSignalConfirm_BTK_Mod_T *localDW);
extern void BTK_Model_BTK_Delay_Confirm(boolean_T rtu_din, uint32_T rtu_t_dbnc,
    uint32_T rtu_simple, rtB_BTK_Delay_Confirm_BTK_Mod_T *localB,
    rtDW_BTK_Delay_Confirm_BTK_Mo_T *localDW);
extern void BTK__BTKTimeoutCustomTimer_Init(rtDW_BTKTimeoutCustomTimer_BT_T
    *localDW);
extern void BTK_BTKTimeoutCustomTimer_Reset(rtDW_BTKTimeoutCustomTimer_BT_T
    *localDW);
extern void BTK_Model_BTKTimeoutCustomTimer(boolean_T rtu_False_Flag, uint32_T
    rtu_Timeout_ms, uint32_T rtu_SimpleTime, rtB_BTKTimeoutCustomTimer_BTK_T
    *localB, rtDW_BTKTimeoutCustomTimer_BT_T *localDW);

#endif                                 /* RTW_HEADER_BTK_lib_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

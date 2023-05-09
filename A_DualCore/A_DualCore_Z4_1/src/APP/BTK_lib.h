/*
 * File: BTK_lib.h
 *
 * Code generated for Simulink model 'BTK_Model'.
 *
 * Model version                  : 1.4525
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Apr 12 11:25:45 2023
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

/* Block signals for system '<S3>/BTK_Delay_Confirm' */
typedef struct
{
    boolean_T debounce;                /* '<S7>/debounce' */
}
rtB_BTK_Delay_Confirm_BTK_Mod_T;

/* Block states (default storage) for system '<S3>/BTK_Delay_Confirm' */
typedef struct
{
    int32_T Delay2_DSTATE;             /* '<S11>/Delay2' */
    boolean_T Delay_DSTATE;            /* '<S7>/Delay' */
}
rtDW_BTK_Delay_Confirm_BTK_Mo_T;

/* Block signals for system '<S10>/BTKSignalConfirm1' */
typedef struct
{
    boolean_T RelationalOperator3;     /* '<S17>/Relational Operator3' */
}
rtB_BTKSignalConfirm_BTK_Mode_T;

/* Block states (default storage) for system '<S10>/BTKSignalConfirm1' */
typedef struct
{
    uint32_T UnitDelay_DSTATE;         /* '<S17>/Unit Delay' */
}
rtDW_BTKSignalConfirm_BTK_Mod_T;

extern void BTK_Model_BTK_Delay_Confirm(boolean_T rtu_din, uint32_T rtu_t_dbnc,
    uint32_T rtu_simple, rtB_BTK_Delay_Confirm_BTK_Mod_T *localB,
    rtDW_BTK_Delay_Confirm_BTK_Mo_T *localDW);
extern void BTK_Model_BTKSignalConfirm(boolean_T rtu_True_Flag, uint32_T
    rtu_SingalConfirmTime, uint32_T rtu_simple, rtB_BTKSignalConfirm_BTK_Mode_T *
    localB, rtDW_BTKSignalConfirm_BTK_Mod_T *localDW);

#endif                                 /* RTW_HEADER_BTK_lib_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

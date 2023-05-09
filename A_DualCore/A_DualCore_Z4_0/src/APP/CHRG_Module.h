/*
 * File: CHRG_Module.h
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

#ifndef RTW_HEADER_CHRG_Module_h_
#define RTW_HEADER_CHRG_Module_h_
#ifndef CHRG_Model_COMMON_INCLUDES_
# define CHRG_Model_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#endif                                 /* CHRG_Model_COMMON_INCLUDES_ */

#include "CHRG_Model_types.h"

/* Child system includes */
#include "CHRG_lib.h"

/* Block signals for system '<S16>/CMM_NormalStsTimer' */
typedef struct
{
    boolean_T RelationalOperator3;     /* '<S89>/Relational Operator3' */
}
rtB_CMM_NormalStsTimer_CHRG_M_T;

/* Block states (auto storage) for system '<S16>/CMM_NormalStsTimer' */
typedef struct
{
    uint32_T UnitDelay_DSTATE;         /* '<S89>/Unit Delay' */
}
rtDW_CMM_NormalStsTimer_CHRG__T;

/* Block signals for system '<S2>/CHRG_C_ChrgConnectCheck' */
typedef struct
{
    rtB_CMM_Delay_Conferm_CHRG_Mo_T CMM_Delay_Conferm;/* '<S6>/CMM_Delay_Conferm' */
}
rtB_CHRG_C_ChrgConnectCheck_C_T;

/* Block states (auto storage) for system '<S2>/CHRG_C_ChrgConnectCheck' */
typedef struct
{
    uint32_T Delay_DSTATE;             /* '<S6>/Delay' */
    uint8_T icLoad;                    /* '<S6>/Delay' */
    rtDW_CMM_Delay_Conferm_CHRG_M_T CMM_Delay_Conferm;/* '<S6>/CMM_Delay_Conferm' */
}
rtDW_CHRG_C_ChrgConnectCheck__T;

extern void CHRG_Mo_CMM_NormalStsTimer_Init(rtDW_CMM_NormalStsTimer_CHRG__T
    *localDW);
extern void CHRG_M_CMM_NormalStsTimer_Reset(rtDW_CMM_NormalStsTimer_CHRG__T
    *localDW);
extern void CHRG_Model_CMM_NormalStsTimer(boolean_T rtu_NormalFlag, uint32_T
    rtu_samplestep_ms, uint32_T rtu_Timeout_ms, rtB_CMM_NormalStsTimer_CHRG_M_T *
    localB, rtDW_CMM_NormalStsTimer_CHRG__T *localDW);
extern void CH_CHRG_C_ChrgConnectCheck_Init(rtDW_CHRG_C_ChrgConnectCheck__T
    *localDW);
extern void C_CHRG_C_ChrgConnectCheck_Reset(rtDW_CHRG_C_ChrgConnectCheck__T
    *localDW);
extern void CHRG_Mo_CHRG_C_ChrgConnectCheck(boolean_T rtu_ConnectSts, boolean_T *
    rty_bool_ChrgDisconnect, rtB_CHRG_C_ChrgConnectCheck_C_T *localB,
    rtDW_CHRG_C_ChrgConnectCheck__T *localDW);
extern void CHRG_Model_CHRG_C_ChrgOperation(void);
extern void CHRG_Mode_CHRG_C_ChrgStart_Init(void);
extern void CHRG_Mod_CHRG_C_ChrgStart_Reset(void);
extern void CHRG_Model_CHRG_C_ChrgStart(void);
extern void CHR_CHRG_C_ChrgStopConfirm_Init(void);
extern void CH_CHRG_C_ChrgStopConfirm_Reset(void);
extern void CHRG_Mod_CHRG_C_ChrgStopConfirm(void);
extern void CHRG_Model_CHRG_C_ChrgStop_Init(void);
extern void CHRG_Mode_CHRG_C_ChrgStop_Reset(void);
extern void CHRG_Model_CHRG_C_ChrgStop(void);
extern void CHRG_Mod_CHRG_C_ChrgEndOpt_Init(void);
extern void CHRG_Mo_CHRG_C_ChrgEndOpt_Reset(void);
extern void CHRG_Model_CHRG_C_ChrgEndOpt(void);
extern void CHRG__CHRG_C_ChrgModecheck_Init(void);
extern void CHRG_CHRG_C_ChrgModecheck_Reset(void);
extern void CHRG_Model_CHRG_C_ChrgModecheck(void);
extern void CHRG_Model_CHRG_C_ChrgWait_Init(void);
extern void CHRG_Mode_CHRG_C_ChrgWait_Reset(void);
extern void CHRG_Model_CHRG_C_ChrgWait(void);
extern void CHRG_Model_CHRG_C_OBCSleep_Init(void);
extern void CHRG_Mode_CHRG_C_OBCSleep_Reset(void);
extern void CHRG_Model_CHRG_C_OBCSleep(void);
extern void CHRG_Mode_CHRG_C_OBCWakeUp_Init(void);
extern void CHRG_Model_CHRG_C_OBCWakeUp(void);
extern void CHRG_CHRG_C_ShiftKnobCheck_Init(void);
extern void CHR_CHRG_C_ShiftKnobCheck_Reset(void);
extern void CHRG_Mode_CHRG_C_ShiftKnobCheck(void);
extern void CHRG_Model_CHRG_C_ChrgCheck(void);
extern void CHRG_Mode_CHRG_C_ResetChrgCheck(void);
extern void CHRG_Model_CHRG_C_ResetChrgFlag(void);
extern void CH_CHRG_C_ChrgStopAbnormal_Init(void);
extern void C_CHRG_C_ChrgStopAbnormal_Reset(void);
extern void CHRG_Mo_CHRG_C_ChrgStopAbnormal(void);
extern void CHRG_Model_CHRG_C_ChrgActive(void);
extern void CHRG_Mode_CHRG_C_ChrgFaultCheck(void);
extern void CHRG_Mode_CHRG_C_ResetChrgFault(void);
extern void CHRG_Mode_CHRG_C_ChrgAgain_Init(void);
extern void CHRG_Mod_CHRG_C_ChrgAgain_Reset(void);
extern void CHRG_Model_CHRG_C_ChrgAgain(void);
extern void CHRG_C_RecoverChrgStartTimeout(void);
extern void CHR_CHRG_C_ParkingStsCheck_Init(void);
extern void CH_CHRG_C_ParkingStsCheck_Reset(void);
extern void CHRG_Mod_CHRG_C_ParkingStsCheck(void);
extern void CHRG_Model_PMM_A_CHMASignalSts(void);
extern void CHRG_Model_CHRG_Module_Init(void);
extern void CHRG_Model_CHRG_Module_Enable(void);
extern void CHRG_Model_CHRG_Module_Const(void);
extern void CHRG_Model_CHRG_Module(void);

#endif                                 /* RTW_HEADER_CHRG_Module_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

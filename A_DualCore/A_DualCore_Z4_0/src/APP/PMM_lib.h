/*
 * File: PMM_lib.h
 *
 * Code generated for Simulink model 'PMM_model'.
 *
 * Model version                  : 1.3119
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Fri Mar 18 15:42:54 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Freescale->32-bit PowerPC
 * Code generation objectives:
 *    1. RAM efficiency
 *    2. ROM efficiency
 *    3. Execution efficiency
 *    4. MISRA C:2012 guidelines
 * Validation result: Not run
 */

#ifndef RTW_HEADER_PMM_lib_h_
#define RTW_HEADER_PMM_lib_h_
#ifndef PMM_model_COMMON_INCLUDES_
# define PMM_model_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* PMM_model_COMMON_INCLUDES_ */

#include "PMM_model_types.h"

/* Block signals for system '<S56>/PMMTimeout1' */
typedef struct {
  boolean_T RelationalOperator3;       /* '<S59>/Relational Operator3' */
} rtB_PMMTimeout_PMM_model_T;

/* Block states (auto storage) for system '<S56>/PMMTimeout1' */
typedef struct {
  uint32_T UnitDelay_DSTATE;           /* '<S59>/Unit Delay' */
} rtDW_PMMTimeout_PMM_model_T;

/* Block signals for system '<S55>/SignalConfirm1' */
typedef struct {
  boolean_T RelationalOperator3;       /* '<S58>/Relational Operator3' */
} rtB_PMMSignalConfirm_PMM_mode_T;

/* Block states (auto storage) for system '<S55>/SignalConfirm1' */
typedef struct {
  uint32_T UnitDelay_DSTATE;           /* '<S58>/Unit Delay' */
} rtDW_PMMSignalConfirm_PMM_mod_T;

extern void PMM_model_PMMTimeout_Init(rtDW_PMMTimeout_PMM_model_T *localDW);
extern void PMM_model_PMMTimeout_Reset(rtDW_PMMTimeout_PMM_model_T *localDW);
extern void PMM_model_PMMTimeout(boolean_T rtu_bool_Flag,
  rtB_PMMTimeout_PMM_model_T *localB, rtDW_PMMTimeout_PMM_model_T *localDW,
  uint8_T rtp_SAMPLETIME, uint32_T rtp_Timeout_ms);
extern void PMM_model_PMMSignalConfirm_Init(rtDW_PMMSignalConfirm_PMM_mod_T
  *localDW);
extern void PMM_mode_PMMSignalConfirm_Reset(rtDW_PMMSignalConfirm_PMM_mod_T
  *localDW);
extern void PMM_model_PMMSignalConfirm(boolean_T rtu_True_Flag, uint32_T
  rtu_SingalConfirmTime, rtB_PMMSignalConfirm_PMM_mode_T *localB,
  rtDW_PMMSignalConfirm_PMM_mod_T *localDW, uint8_T rtp_SAMPLETIME);

#endif                                 /* RTW_HEADER_PMM_lib_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

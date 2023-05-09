/*
 * File: TMM_lib.h
 *
 * Code generated for Simulink model 'TMM_model'.
 *
 * Model version                  : 1.2731
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Fri Mar 18 15:44:30 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Freescale->32-bit PowerPC
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 *    3. ROM efficiency
 *    4. MISRA C:2012 guidelines
 * Validation result: Not run
 */

#ifndef RTW_HEADER_TMM_lib_h_
#define RTW_HEADER_TMM_lib_h_
#ifndef TMM_model_COMMON_INCLUDES_
# define TMM_model_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#endif                                 /* TMM_model_COMMON_INCLUDES_ */

#include "TMM_model_types.h"

/* Block signals for system '<S22>/SignalConfirm1' */
typedef struct {
  boolean_T RelationalOperator3;       /* '<S24>/Relational Operator3' */
} B_SignalConfirm_T;

/* Block states (auto storage) for system '<S22>/SignalConfirm1' */
typedef struct {
  uint32_T UnitDelay_DSTATE;           /* '<S24>/Unit Delay' */
  uint32_T Delay1_DSTATE;              /* '<S24>/Delay1' */
  uint8_T icLoad;                      /* '<S24>/Delay1' */
} DW_SignalConfirm_T;

extern void SignalConfirm_Init(DW_SignalConfirm_T *localDW);
extern void SignalConfirm(boolean_T rtu_True_Flag, uint32_T
  rtu_SingalConfirmTime, B_SignalConfirm_T *localB, DW_SignalConfirm_T *localDW);

#endif                                 /* RTW_HEADER_TMM_lib_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

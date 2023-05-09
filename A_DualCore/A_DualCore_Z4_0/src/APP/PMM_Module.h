/*
 * File: PMM_Module.h
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

#ifndef RTW_HEADER_PMM_Module_h_
#define RTW_HEADER_PMM_Module_h_
#include <math.h>
#ifndef PMM_model_COMMON_INCLUDES_
# define PMM_model_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* PMM_model_COMMON_INCLUDES_ */

#include "PMM_model_types.h"

/* Child system includes */
#include "PMM_lib.h"

/* Block signals for system '<S2>/PMM_CheckMsgLost_BMS' */
typedef struct {
  boolean_T LogicalOperator2;          /* '<S97>/Logical Operator2' */
} rtB_PMM_CheckMsgLost_BMS_PMM__T;

/* Block states (auto storage) for system '<S2>/PMM_CheckMsgLost_BMS' */
typedef struct {
  uint32_T Delay2_DSTATE;              /* '<S98>/Delay2' */
  uint32_T Delay3_DSTATE;              /* '<S98>/Delay3' */
  uint32_T Delay_DSTATE;               /* '<S97>/Delay' */
  uint32_T Delay1_DSTATE;              /* '<S97>/Delay1' */
  uint8_T icLoad;                      /* '<S98>/Delay2' */
  uint8_T icLoad_a;                    /* '<S97>/Delay' */
  uint8_T icLoad_b;                    /* '<S97>/Delay1' */
} rtDW_PMM_CheckMsgLost_BMS_PMM_T;

/* Block signals for system '<S26>/ConfirmMCUInHVActiveMode' */
typedef struct {
  boolean_T LogicalOperator3;          /* '<S91>/Logical Operator3' */
} rtB_ConfirmMCUInHVActiveMode__T;

/* Block states (auto storage) for system '<S26>/ConfirmMCUInHVActiveMode' */
typedef struct {
  uint32_T Delay6_DSTATE;              /* '<S91>/Delay6' */
  boolean_T Delay1_DSTATE;             /* '<S91>/Delay1' */
  boolean_T Delay2_DSTATE;             /* '<S91>/Delay2' */
} rtDW_ConfirmMCUInHVActiveMode_T;

/* Block signals for system '<S57>/Chart' */
typedef struct {
  uint32_T TaskTick;                   /* '<S57>/Chart' */
} rtB_Chart_PMM_model_T;

/* Block states (auto storage) for system '<S57>/Chart' */
typedef struct {
  uint32_T StartTime;                  /* '<S57>/Chart' */
  uint8_T is_active_c8_PMM_model;      /* '<S57>/Chart' */
  uint8_T is_c8_PMM_model;             /* '<S57>/Chart' */
} rtDW_Chart_PMM_model_T;

/* Block signals for system '<S2>/BMSMonitor' */
typedef struct {
  boolean_T LogicalOperator17;         /* '<S3>/Logical Operator17' */
} rtB_BMSMonitor_PMM_model_T;

/* Block signals for system '<S106>/PMM_InternalWaitTimeout' */
typedef struct {
  boolean_T RelationalOperator3;       /* '<S113>/Relational Operator3' */
} rtB_PMM_InternalWaitTimeout_P_T;

/* Block states (auto storage) for system '<S106>/PMM_InternalWaitTimeout' */
typedef struct {
  uint32_T Delay1_DSTATE;              /* '<S113>/Delay1' */
  uint32_T Delay_DSTATE;               /* '<S113>/Delay' */
  uint8_T icLoad;                      /* '<S113>/Delay' */
} rtDW_PMM_InternalWaitTimeout__T;

extern void PMM_m_PMM_CheckMsgLost_BMS_Init(rtDW_PMM_CheckMsgLost_BMS_PMM_T
  *localDW);
extern void PMM_model_PMM_CheckMsgLost_BMS(uint32_T rtu_MsgCycTimeMs, uint32_T
  rtu_MsgTickForCheck, rtB_PMM_CheckMsgLost_BMS_PMM__T *localB,
  rtDW_PMM_CheckMsgLost_BMS_PMM_T *localDW);
extern void P_ConfirmMCUInHVActiveMode_Init(rtDW_ConfirmMCUInHVActiveMode_T
  *localDW);
extern void ConfirmMCUInHVActiveMode_Reset(rtDW_ConfirmMCUInHVActiveMode_T
  *localDW);
extern void PMM_mo_ConfirmMCUInHVActiveMode(boolean_T rtu_IsMCURelayActived,
  uint8_T rtu_MCUMode, uint32_T rtu_MCU115_10ms_MSGTick, boolean_T
  rtu_MCUHVActive_timeout, rtB_ConfirmMCUInHVActiveMode__T *localB,
  rtDW_ConfirmMCUInHVActiveMode_T *localDW);
extern void PMM_model_Chart_Init(rtDW_Chart_PMM_model_T *localDW);
extern void PMM_model_Chart_Reset(rtDW_Chart_PMM_model_T *localDW);
extern void PMM_model_Chart(boolean_T rtu_bool_True, uint32_T rtu_SystemTick,
  rtB_Chart_PMM_model_T *localB, rtDW_Chart_PMM_model_T *localDW);
extern void PMM_model_BMSMonitor(uint8_T rtu_BMSDateMonitoringt, boolean_T
  rtu_BMSMonitorReq, rtB_BMSMonitor_PMM_model_T *localB);
extern void PM_PMM_InternalWaitTimeout_Init(rtDW_PMM_InternalWaitTimeout__T
  *localDW);
extern void P_PMM_InternalWaitTimeout_Reset(rtDW_PMM_InternalWaitTimeout__T
  *localDW);
extern void PMM_mod_PMM_InternalWaitTimeout(uint32_T rtu_timeout_ms,
  rtB_PMM_InternalWaitTimeout_P_T *localB, rtDW_PMM_InternalWaitTimeout__T
  *localDW);
extern void PMM_model_PMM_C_NonToRun_Init(void);
extern void PMM_model_PMM_C_NonToRun(void);
extern void PMM_model_PMM_C_HVDnToUp(void);
extern void PMM_model_PMM_C_HVActive_Init(void);
extern void PMM_model_PMM_C_HVActive_Reset(void);
extern void PMM_model_PMM_C_HVActive(void);
extern void PMM_model_PMM_C_HVDown_Init(void);
extern void PMM_model_PMM_C_HVDown_Reset(void);
extern void PMM_model_PMM_C_HVDown(void);
extern void PMM_model_PMM_C_HVModeToDn_Init(void);
extern void PMM_mode_PMM_C_HVModeToDn_Reset(void);
extern void PMM_model_PMM_C_HVModeToDn(void);
extern void PMM_model_PMM_C_HVStopWork_Init(void);
extern void PMM_mode_PMM_C_HVStopWork_Reset(void);
extern void PMM_model_PMM_C_HVStopWork(void);
extern void PMM_model_PMM_C_HVUp_Init(void);
extern void PMM_model_PMM_C_HVUp_Reset(void);
extern void PMM_model_PMM_C_HVUp(void);
extern void PMM_mod_PMM_C_MCUDischarge_Init(void);
extern void PMM_mo_PMM_C_MCUDischarge_Reset(void);
extern void PMM_model_PMM_C_MCUDischarge(void);
extern void PMM_model_PMM_C_RunToNon(void);
extern void PMM_model_PMM_C_HVUpToDn(void);
extern void PMM_model_PMM_C_UpToHVMode(void);
extern void PMM_model_PMM_C_ResetHVActive(void);
extern void PMM_mode_PMM_C_LVReadyToDn_Init(void);
extern void PMM_mod_PMM_C_LVReadyToDn_Reset(void);
extern void PMM_model_PMM_C_LVReadyToDn(void);
extern void P_PMM_C_HVActiveChrgModeInvalid(void);
extern void PMM_model_PMM_Module_Init(void);
extern void PMM_model_PMM_Module_Enable(void);
extern void PMM_model_PMM_Module(void);

#endif                                 /* RTW_HEADER_PMM_Module_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

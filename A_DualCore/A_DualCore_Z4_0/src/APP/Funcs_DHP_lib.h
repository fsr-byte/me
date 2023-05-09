/*
 * File: Funcs_DHP_lib.h
 *
 * Code generated for Simulink model 'DHP_model'.
 *
 * Model version                  : 1.5367
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Fri Mar 18 15:33:37 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Freescale->32-bit PowerPC
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. ROM efficiency
 *    3. RAM efficiency
 *    4. MISRA C:2012 guidelines
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Funcs_DHP_lib_h_
#define RTW_HEADER_Funcs_DHP_lib_h_
#ifndef DHP_model_COMMON_INCLUDES_
# define DHP_model_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#endif                                 /* DHP_model_COMMON_INCLUDES_ */

#include "DHP_model_types.h"

/* Block states (auto storage) for system '<S537>/DHP_systemtick_Timer' */
typedef struct {
  uint32_T UnitDelay_DSTATE;           /* '<S586>/UnitDelay' */
  boolean_T Delay_DSTATE;              /* '<S586>/Delay' */
} DW_DHP_systemtick_Timer_DHP_model_T;

/* Block states (auto storage) for system '<S663>/DHP_systemtick_Timer' */
typedef struct {
  uint32_T UnitDelay_DSTATE;           /* '<S668>/UnitDelay' */
  boolean_T Delay_DSTATE;              /* '<S668>/Delay' */
} DW_DHP_systemtick_Timer_DHP_model_d_T;

/* Block states (auto storage) for system '<S663>/DHP_systemtick_Timer1' */
typedef struct {
  uint32_T UnitDelay_DSTATE;           /* '<S669>/UnitDelay' */
  boolean_T Delay_DSTATE;              /* '<S669>/Delay' */
} DW_DHP_systemtick_Timer_DHP_model_e_T;

/* Block signals for system '<S689>/DHP_systemtick_Timer' */
typedef struct {
  boolean_T RelationalOperator;        /* '<S699>/Relational Operator' */
} B_DHP_systemtick_Timer_DHP_model_k_T;

/* Block states (auto storage) for system '<S689>/DHP_systemtick_Timer' */
typedef struct {
  uint32_T UnitDelay_DSTATE;           /* '<S699>/UnitDelay' */
  boolean_T Delay_DSTATE;              /* '<S699>/Delay' */
} DW_DHP_systemtick_Timer_DHP_model_m_T;

/* Block states (auto storage) for system '<S766>/DHP_systemtick_Timer' */
typedef struct {
  uint32_T UnitDelay_DSTATE;           /* '<S768>/UnitDelay' */
  boolean_T Delay_DSTATE;              /* '<S768>/Delay' */
  boolean_T UnitDelay1_DSTATE;         /* '<S768>/UnitDelay1' */
} DW_DHP_systemtick_Timer_DHP_model_md_T;

/* Block states (auto storage) for system '<S770>/DHP_systemtick_Timer' */
typedef struct {
  uint32_T UnitDelay_DSTATE;           /* '<S788>/UnitDelay' */
  boolean_T Delay_DSTATE;              /* '<S788>/Delay' */
} DW_DHP_systemtick_Timer_DHP_model_i_T;

/* Block states (auto storage) for system '<S778>/DHP_systemtick_Timer' */
typedef struct {
  uint32_T UnitDelay_DSTATE;           /* '<S796>/UnitDelay' */
  boolean_T Delay_DSTATE;              /* '<S796>/Delay' */
} DW_DHP_systemtick_Timer_DHP_model_ii_T;

/* Block states (auto storage) for system '<S779>/DHP_systemtick_Timer' */
typedef struct {
  uint32_T UnitDelay_DSTATE;           /* '<S797>/UnitDelay' */
  boolean_T Delay_DSTATE;              /* '<S797>/Delay' */
} DW_DHP_systemtick_Timer_DHP_model_mg_T;

/* Block states (auto storage) for system '<S780>/DHP_systemtick_Timer' */
typedef struct {
  uint32_T UnitDelay_DSTATE;           /* '<S798>/UnitDelay' */
  boolean_T Delay_DSTATE;              /* '<S798>/Delay' */
} DW_DHP_systemtick_Timer_DHP_model_j_T;

/* Block states (auto storage) for system '<S807>/DHP_systemtick_Timer' */
typedef struct {
  uint32_T UnitDelay_DSTATE;           /* '<S810>/UnitDelay' */
  boolean_T Delay_DSTATE;              /* '<S810>/Delay' */
} DW_DHP_systemtick_Timer_DHP_model_n_T;

/* Block states (auto storage) for system '<S750>/DHP_systemtick_Timer' */
typedef struct {
  uint32_T UnitDelay_DSTATE;           /* '<S811>/UnitDelay' */
  boolean_T Delay_DSTATE;              /* '<S811>/Delay' */
  boolean_T UnitDelay1_DSTATE;         /* '<S811>/UnitDelay1' */
} DW_DHP_systemtick_Timer_DHP_model_np_T;

/* Block states (auto storage) for system '<S812>/DHP_systemtick_Timer' */
typedef struct {
  uint32_T UnitDelay_DSTATE;           /* '<S813>/UnitDelay' */
  boolean_T Delay_DSTATE;              /* '<S813>/Delay' */
  boolean_T UnitDelay1_DSTATE;         /* '<S813>/UnitDelay1' */
} DW_DHP_systemtick_Timer_DHP_model_g_T;

/* Block states (auto storage) for system '<S752>/DHP_systemtick_Timer' */
typedef struct {
  uint32_T UnitDelay_DSTATE;           /* '<S814>/UnitDelay' */
  boolean_T Delay_DSTATE;              /* '<S814>/Delay' */
  boolean_T UnitDelay1_DSTATE;         /* '<S814>/UnitDelay1' */
} DW_DHP_systemtick_Timer_DHP_model_mc_T;

/* Block states (auto storage) for system '<S815>/DHP_systemtick_Timer' */
typedef struct {
  uint32_T UnitDelay_DSTATE;           /* '<S816>/UnitDelay' */
  boolean_T Delay_DSTATE;              /* '<S816>/Delay' */
  boolean_T UnitDelay1_DSTATE;         /* '<S816>/UnitDelay1' */
} DW_DHP_systemtick_Timer_DHP_model_ge_T;

/* Block states (auto storage) for system '<S755>/DHP_systemtick_Timer1' */
typedef struct {
  uint32_T UnitDelay_DSTATE;           /* '<S822>/UnitDelay' */
  boolean_T Delay_DSTATE;              /* '<S822>/Delay' */
  boolean_T UnitDelay1_DSTATE;         /* '<S822>/UnitDelay1' */
} DW_DHP_systemtick_Timer_DHP_model_a_T;

/* Block states (auto storage) for system '<S823>/DHP_systemtick_Timer' */
typedef struct {
  uint32_T UnitDelay_DSTATE;           /* '<S827>/UnitDelay' */
  boolean_T Delay_DSTATE;              /* '<S827>/Delay' */
} DW_DHP_systemtick_Timer_DHP_model_f_T;

/* Block states (auto storage) for system '<S824>/DHP_systemtick_Timer' */
typedef struct {
  uint32_T UnitDelay_DSTATE;           /* '<S828>/UnitDelay' */
  boolean_T Delay_DSTATE;              /* '<S828>/Delay' */
} DW_DHP_systemtick_Timer_DHP_model_db_T;

/* Block states (auto storage) for system '<S825>/DHP_systemtick_Timer' */
typedef struct {
  uint32_T UnitDelay_DSTATE;           /* '<S829>/UnitDelay' */
  boolean_T Delay_DSTATE;              /* '<S829>/Delay' */
} DW_DHP_systemtick_Timer_DHP_model_a5_T;

/* Block states (auto storage) for system '<S826>/DHP_systemtick_Timer' */
typedef struct {
  uint32_T UnitDelay_DSTATE;           /* '<S830>/UnitDelay' */
  boolean_T Delay_DSTATE;              /* '<S830>/Delay' */
} DW_DHP_systemtick_Timer_DHP_model_o_T;

/* Block states (auto storage) for system '<S835>/DHP_systemtick_Timer' */
typedef struct {
  uint32_T UnitDelay_DSTATE;           /* '<S840>/UnitDelay' */
  boolean_T Delay_DSTATE;              /* '<S840>/Delay' */
} DW_DHP_systemtick_Timer_DHP_model_h_T;

/* Block states (auto storage) for system '<S760>/DHP_systemtick_Timer' */
typedef struct {
  uint32_T UnitDelay_DSTATE;           /* '<S842>/UnitDelay' */
  boolean_T Delay_DSTATE;              /* '<S842>/Delay' */
  boolean_T UnitDelay1_DSTATE;         /* '<S842>/UnitDelay1' */
} DW_DHP_systemtick_Timer_DHP_model_op_T;

/* Block states (auto storage) for system '<S843>/DHP_systemtick_Timer' */
typedef struct {
  uint32_T UnitDelay_DSTATE;           /* '<S844>/UnitDelay' */
  boolean_T Delay_DSTATE;              /* '<S844>/Delay' */
  boolean_T UnitDelay1_DSTATE;         /* '<S844>/UnitDelay1' */
} DW_DHP_systemtick_Timer_DHP_model_ga_T;

/* Block states (auto storage) for system '<S763>/DHP_systemtick_Timer' */
typedef struct {
  uint32_T UnitDelay_DSTATE;           /* '<S846>/UnitDelay' */
  boolean_T Delay_DSTATE;              /* '<S846>/Delay' */
  boolean_T UnitDelay1_DSTATE;         /* '<S846>/UnitDelay1' */
} DW_DHP_systemtick_Timer_DHP_model_c_T;

/* Block states (auto storage) for system '<S1105>/DHP_systemtick_Timer' */
typedef struct {
  uint32_T UnitDelay_DSTATE;           /* '<S1114>/UnitDelay' */
  boolean_T Delay_DSTATE;              /* '<S1114>/Delay' */
} DW_DHP_systemtick_Timer_DHP_model_an_T;

/* Block states (auto storage) for system '<S1106>/DHP_systemtick_Timer' */
typedef struct {
  uint32_T UnitDelay_DSTATE;           /* '<S1115>/UnitDelay' */
  boolean_T Delay_DSTATE;              /* '<S1115>/Delay' */
} DW_DHP_systemtick_Timer_DHP_model_l_T;

/* Block states (auto storage) for system '<S1111>/DHP_systemtick_Timer' */
typedef struct {
  uint32_T UnitDelay_DSTATE;           /* '<S1120>/UnitDelay' */
  boolean_T Delay_DSTATE;              /* '<S1120>/Delay' */
} DW_DHP_systemtick_Timer_DHP_model_ny_T;

/* Block states (auto storage) for system '<S1112>/DHP_systemtick_Timer' */
typedef struct {
  uint32_T UnitDelay_DSTATE;           /* '<S1121>/UnitDelay' */
  boolean_T Delay_DSTATE;              /* '<S1121>/Delay' */
} DW_DHP_systemtick_Timer_DHP_model_k_T;

/* Block states (auto storage) for system '<S1113>/DHP_systemtick_Timer' */
typedef struct {
  uint32_T UnitDelay_DSTATE;           /* '<S1122>/UnitDelay' */
  boolean_T Delay_DSTATE;              /* '<S1122>/Delay' */
} DW_DHP_systemtick_Timer_DHP_model_b_T;

/* Block states (auto storage) for system '<S1123>/DHP_systemtick_Timer' */
typedef struct {
  uint32_T UnitDelay_DSTATE;           /* '<S1138>/UnitDelay' */
  boolean_T Delay_DSTATE;              /* '<S1138>/Delay' */
} DW_DHP_systemtick_Timer_DHP_model_p_T;

/* Block states (auto storage) for system '<S1123>/DHP_systemtick_Timer1' */
typedef struct {
  uint32_T UnitDelay_DSTATE;           /* '<S1139>/UnitDelay' */
  boolean_T Delay_DSTATE;              /* '<S1139>/Delay' */
} DW_DHP_systemtick_Timer_DHP_model_h3_T;

/* Block states (auto storage) for system '<S1123>/DHP_systemtick_Timer2' */
typedef struct {
  uint32_T UnitDelay_DSTATE;           /* '<S1140>/UnitDelay' */
  boolean_T Delay_DSTATE;              /* '<S1140>/Delay' */
} DW_DHP_systemtick_Timer_DHP_model_mf_T;

/* Block states (auto storage) for system '<S1123>/DHP_systemtick_Timer3' */
typedef struct {
  uint32_T UnitDelay_DSTATE;           /* '<S1141>/UnitDelay' */
  boolean_T Delay_DSTATE;              /* '<S1141>/Delay' */
} DW_DHP_systemtick_Timer_DHP_model_ac_T;

/* Block states (auto storage) for system '<S1123>/DHP_systemtick_Timer4' */
typedef struct {
  uint32_T UnitDelay_DSTATE;           /* '<S1142>/UnitDelay' */
  boolean_T Delay_DSTATE;              /* '<S1142>/Delay' */
} DW_DHP_systemtick_Timer_DHP_model_gc_T;

/* Block signals for system '<S1243>/Fault_Affirm' */
typedef struct {
  boolean_T Switch2;                   /* '<S1245>/Switch2' */
} B_Fault_Affirm_DHP_model_T;

/* Block states (auto storage) for system '<S1243>/Fault_Affirm' */
typedef struct {
  uint32_T Delay1_DSTATE;              /* '<S1245>/Delay1' */
  uint32_T Delay7_DSTATE;              /* '<S1245>/Delay7' */
  uint32_T Delay2_DSTATE;              /* '<S1245>/Delay2' */
  boolean_T Delay3_DSTATE;             /* '<S1245>/Delay3' */
  boolean_T Delay_DSTATE;              /* '<S1245>/Delay' */
  boolean_T Delay4_DSTATE;             /* '<S1245>/Delay4' */
  boolean_T Delay6_DSTATE;             /* '<S1245>/Delay6' */
} DW_Fault_Affirm_DHP_model_T;

/* Block signals for system '<S1242>/Fault_Valid_Time' */
typedef struct {
  uint16_T Switch2;                    /* '<S1244>/Switch2' */
  uint8_T Switch3;                     /* '<S1244>/Switch3' */
  uint8_T Switch4;                     /* '<S1244>/Switch4' */
  uint8_T Switch2_i;                   /* '<S1243>/Switch2' */
  B_Fault_Affirm_DHP_model_T Fault_Affirm;/* '<S1243>/Fault_Affirm' */
} B_Fault_Valid_Time_DHP_model_T;

/* Block states (auto storage) for system '<S1242>/Fault_Valid_Time' */
typedef struct {
  DW_Fault_Affirm_DHP_model_T Fault_Affirm;/* '<S1243>/Fault_Affirm' */
} DW_Fault_Valid_Time_DHP_model_T;

/* Block signals for system '<S1297>/Fault_Valid_RT' */
typedef struct {
  uint16_T Switch2;                    /* '<S1299>/Switch2' */
  uint8_T Switch3;                     /* '<S1299>/Switch3' */
  uint8_T Switch4;                     /* '<S1299>/Switch4' */
  uint8_T Switch2_m;                   /* '<S1298>/Switch2' */
  boolean_T Switch9;                   /* '<S1298>/Switch9' */
} B_Fault_Valid_RT_DHP_model_T;

/* Block states (auto storage) for system '<S1297>/Fault_Valid_RT' */
typedef struct {
  boolean_T Delay6_DSTATE;             /* '<S1298>/Delay6' */
} DW_Fault_Valid_RT_DHP_model_T;

/* Block signals for system '<S1693>/Fault_Action' */
typedef struct {
  uint16_T Switch2;                    /* '<S1694>/Switch2' */
  uint8_T Switch3;                     /* '<S1694>/Switch3' */
  uint8_T Switch4;                     /* '<S1694>/Switch4' */
} B_Fault_Action_DHP_model_T;

extern void DHP_model_DHP_FaultStore_Chart(boolean_T rtu_Fault_flg, uint8_T
  rtu_Fault_level, uint8_T rtu_Fault_serial, const uint8_T rtu_SnapShots_Infos
  [61], boolean_T rtu_ssInfosUpdate_flg);
extern void DHP_model_DHP_systemtick_Timer(boolean_T rtu_Enable, uint8_T
  rtu_DeltaSystemTick_ms, uint16_T rtu_KeepTime_ms,
  DW_DHP_systemtick_Timer_DHP_model_T *localDW);
extern void DHP_model_DHP_systemtick_Timer_p(boolean_T rtu_Enable, uint8_T
  rtu_DeltaSystemTick_ms, uint32_T rtu_KeepTime_ms,
  DW_DHP_systemtick_Timer_DHP_model_d_T *localDW);
extern void DHP_model_DHP_systemtick_Timer1(boolean_T rtu_Enable, uint8_T
  rtu_DeltaSystemTick_ms, uint32_T rtu_KeepTime_ms,
  DW_DHP_systemtick_Timer_DHP_model_e_T *localDW);
extern void DHP_model_DHP_systemtick_Timer_c(boolean_T rtu_Enable, uint8_T
  rtu_DeltaSystemTick_ms, uint16_T rtu_KeepTime_ms,
  B_DHP_systemtick_Timer_DHP_model_k_T *localB,
  DW_DHP_systemtick_Timer_DHP_model_m_T *localDW);
extern void DHP_model_DHP_systemtick_Timer_n(boolean_T rtu_Enable, uint8_T
  rtu_DeltaSystemTick_ms, uint16_T rtu_KeepTime_ms,
  DW_DHP_systemtick_Timer_DHP_model_md_T *localDW);
extern void DHP_model_DHP_systemtick_Timer_e(boolean_T rtu_Enable, uint8_T
  rtu_DeltaSystemTick_ms, uint16_T rtu_KeepTime_ms,
  DW_DHP_systemtick_Timer_DHP_model_i_T *localDW);
extern void DHP_model_DHP_systemtick_Timer_k(boolean_T rtu_Enable, uint8_T
  rtu_DeltaSystemTick_ms, uint16_T rtu_KeepTime_ms,
  DW_DHP_systemtick_Timer_DHP_model_ii_T *localDW);
extern void DHP_model_DHP_systemtick_Timer_o(boolean_T rtu_Enable, uint8_T
  rtu_DeltaSystemTick_ms, uint16_T rtu_KeepTime_ms,
  DW_DHP_systemtick_Timer_DHP_model_mg_T *localDW);
extern void DHP_model_DHP_systemtick_Timer_g(boolean_T rtu_Enable, uint8_T
  rtu_DeltaSystemTick_ms, uint16_T rtu_KeepTime_ms,
  DW_DHP_systemtick_Timer_DHP_model_j_T *localDW);
extern void DHP_model_DHP_systemtick_Timer_k2(boolean_T rtu_Enable, uint8_T
  rtu_DeltaSystemTick_ms, uint16_T rtu_KeepTime_ms,
  DW_DHP_systemtick_Timer_DHP_model_n_T *localDW);
extern void DHP_model_DHP_systemtick_Timer_m(boolean_T rtu_Enable, uint8_T
  rtu_DeltaSystemTick_ms, uint16_T rtu_KeepTime_ms,
  DW_DHP_systemtick_Timer_DHP_model_np_T *localDW);
extern void DHP_model_DHP_systemtick_Timer_m3(boolean_T rtu_Enable, uint8_T
  rtu_DeltaSystemTick_ms, uint16_T rtu_KeepTime_ms,
  DW_DHP_systemtick_Timer_DHP_model_g_T *localDW);
extern void DHP_model_DHP_systemtick_Timer_l(boolean_T rtu_Enable, uint8_T
  rtu_DeltaSystemTick_ms, uint16_T rtu_KeepTime_ms,
  DW_DHP_systemtick_Timer_DHP_model_mc_T *localDW);
extern void DHP_model_DHP_systemtick_Timer_f(boolean_T rtu_Enable, uint8_T
  rtu_DeltaSystemTick_ms, uint16_T rtu_KeepTime_ms,
  DW_DHP_systemtick_Timer_DHP_model_ge_T *localDW);
extern void DHP_model_DHP_systemtick_Timer1_k(boolean_T rtu_Enable, uint8_T
  rtu_DeltaSystemTick_ms, uint16_T rtu_KeepTime_ms,
  DW_DHP_systemtick_Timer_DHP_model_a_T *localDW);
extern void DHP_model_DHP_systemtick_Timer_a(boolean_T rtu_Enable, uint8_T
  rtu_DeltaSystemTick_ms, uint16_T rtu_KeepTime_ms,
  DW_DHP_systemtick_Timer_DHP_model_f_T *localDW);
extern void DHP_model_DHP_systemtick_Timer_b(boolean_T rtu_Enable, uint8_T
  rtu_DeltaSystemTick_ms, uint16_T rtu_KeepTime_ms,
  DW_DHP_systemtick_Timer_DHP_model_db_T *localDW);
extern void DHP_model_DHP_systemtick_Timer_j(boolean_T rtu_Enable, uint8_T
  rtu_DeltaSystemTick_ms, uint16_T rtu_KeepTime_ms,
  DW_DHP_systemtick_Timer_DHP_model_a5_T *localDW);
extern void DHP_model_DHP_systemtick_Timer_h(boolean_T rtu_Enable, uint8_T
  rtu_DeltaSystemTick_ms, uint16_T rtu_KeepTime_ms,
  DW_DHP_systemtick_Timer_DHP_model_o_T *localDW);
extern void DHP_model_DHP_systemtick_Timer_p0(boolean_T rtu_Enable, uint8_T
  rtu_DeltaSystemTick_ms, uint16_T rtu_KeepTime_ms,
  DW_DHP_systemtick_Timer_DHP_model_h_T *localDW);
extern void DHP_model_DHP_systemtick_Timer_i(boolean_T rtu_Enable, uint8_T
  rtu_DeltaSystemTick_ms, uint16_T rtu_KeepTime_ms,
  DW_DHP_systemtick_Timer_DHP_model_op_T *localDW);
extern void DHP_model_DHP_systemtick_Timer_ph(boolean_T rtu_Enable, uint8_T
  rtu_DeltaSystemTick_ms, uint16_T rtu_KeepTime_ms,
  DW_DHP_systemtick_Timer_DHP_model_ga_T *localDW);
extern void DHP_model_DHP_systemtick_Timer_ho(boolean_T rtu_Enable, uint8_T
  rtu_DeltaSystemTick_ms, uint16_T rtu_KeepTime_ms,
  DW_DHP_systemtick_Timer_DHP_model_c_T *localDW);
extern void DHP_model_DHP_systemtick_Timer_gq(boolean_T rtu_Enable, uint8_T
  rtu_DeltaSystemTick_ms, uint16_T rtu_KeepTime_ms,
  DW_DHP_systemtick_Timer_DHP_model_an_T *localDW);
extern void DHP_model_DHP_systemtick_Timer_na(boolean_T rtu_Enable, uint8_T
  rtu_DeltaSystemTick_ms, uint16_T rtu_KeepTime_ms,
  DW_DHP_systemtick_Timer_DHP_model_l_T *localDW);
extern void DHP_model_DHP_systemtick_Timer_fy(boolean_T rtu_Enable, uint8_T
  rtu_DeltaSystemTick_ms, uint16_T rtu_KeepTime_ms,
  DW_DHP_systemtick_Timer_DHP_model_ny_T *localDW);
extern void DHP_model_DHP_systemtick_Timer_oz(boolean_T rtu_Enable, uint8_T
  rtu_DeltaSystemTick_ms, uint16_T rtu_KeepTime_ms,
  DW_DHP_systemtick_Timer_DHP_model_k_T *localDW);
extern void DHP_model_DHP_systemtick_Timer_p3(boolean_T rtu_Enable, uint8_T
  rtu_DeltaSystemTick_ms, uint16_T rtu_KeepTime_ms,
  DW_DHP_systemtick_Timer_DHP_model_b_T *localDW);
extern void DHP_model_DHP_systemtick_Timer_k0(boolean_T rtu_Enable, uint8_T
  rtu_DeltaSystemTick_ms, uint16_T rtu_KeepTime_ms,
  DW_DHP_systemtick_Timer_DHP_model_p_T *localDW);
extern void DHP_model_DHP_systemtick_Timer1_f(boolean_T rtu_Enable, uint8_T
  rtu_DeltaSystemTick_ms, uint16_T rtu_KeepTime_ms,
  DW_DHP_systemtick_Timer_DHP_model_h3_T *localDW);
extern void DHP_model_DHP_systemtick_Timer2(boolean_T rtu_Enable, uint8_T
  rtu_DeltaSystemTick_ms, uint16_T rtu_KeepTime_ms,
  DW_DHP_systemtick_Timer_DHP_model_mf_T *localDW);
extern void DHP_model_DHP_systemtick_Timer3(boolean_T rtu_Enable, uint8_T
  rtu_DeltaSystemTick_ms, uint16_T rtu_KeepTime_ms,
  DW_DHP_systemtick_Timer_DHP_model_ac_T *localDW);
extern void DHP_model_DHP_systemtick_Timer4(boolean_T rtu_Enable, uint8_T
  rtu_DeltaSystemTick_ms, uint16_T rtu_KeepTime_ms,
  DW_DHP_systemtick_Timer_DHP_model_gc_T *localDW);
extern void DHP_model_Fault_Affirm(boolean_T rtu_VNM_SleepInd_flg, uint8_T
  rtu_deltaSystemtick_ms, boolean_T rtu_Err_generate_Ins, uint16_T
  rtu_ConfirmTime_ms, uint16_T rtu_ClearTime_ms, boolean_T rtu_Allow_Recover,
  B_Fault_Affirm_DHP_model_T *localB, DW_Fault_Affirm_DHP_model_T *localDW);
extern void DHP_model_Fault_Valid_Time(boolean_T rtu_VNM_SleepInd_flg, uint8_T
  rtu_deltaSystemtick_ms, boolean_T rtu_Err_generate_Ins, uint16_T
  rtu_ConfirmTime_ms, uint16_T rtu_ClearTime_ms, boolean_T rtu_Allow_Recover,
  uint8_T rtu_Fault_Lever, uint8_T rtu_Spd_Limit, uint8_T rtu_Pwr_limit_Pct,
  uint16_T rtu_Handle_Response_Bits, boolean_T rtu_Action_Switch_Open,
  B_Fault_Valid_Time_DHP_model_T *localB, DW_Fault_Valid_Time_DHP_model_T
  *localDW);
extern void DHP_model_Fault_Valid_RT(boolean_T rtu_VNM_SleepInd_flg, boolean_T
  rtu_Err_generate_Ins, boolean_T rtu_Allow_Recover, uint8_T rtu_Fault_Lever,
  uint8_T rtu_Spd_Limit, uint8_T rtu_Pwr_limit_Pct, uint16_T
  rtu_Handle_Response_Bits, boolean_T rtu_Action_Switch_Open,
  B_Fault_Valid_RT_DHP_model_T *localB, DW_Fault_Valid_RT_DHP_model_T *localDW);
extern void DHP_model_Fault_Action(boolean_T rtu_Valid_Err_Generate, uint8_T
  rtu_Spd_Limit, uint8_T rtu_Pwr_limit_Pct, uint16_T rtu_Handle_Response_Bits,
  boolean_T rtu_Action_Switch_Open, B_Fault_Action_DHP_model_T *localB);

#endif                                 /* RTW_HEADER_Funcs_DHP_lib_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

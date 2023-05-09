/*
 * File: Funcs_DHP_lib.c
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

#include "Funcs_DHP_lib.h"

/* Include model header file for global data */
#include "DHP_model.h"
#include "DHP_model_private.h"

/*
 * Output and update for atomic system:
 *    '<S59>/DHP_FaultStore_Chart'
 *    '<S60>/DHP_FaultStore_Chart'
 *    '<S61>/DHP_FaultStore_Chart'
 *    '<S62>/DHP_FaultStore_Chart'
 *    '<S63>/DHP_FaultStore_Chart'
 *    '<S64>/DHP_FaultStore_Chart'
 *    '<S65>/DHP_FaultStore_Chart'
 *    '<S66>/DHP_FaultStore_Chart'
 *    '<S67>/DHP_FaultStore_Chart'
 *    '<S68>/DHP_FaultStore_Chart'
 *    ...
 */
void DHP_model_DHP_FaultStore_Chart(boolean_T rtu_Fault_flg, uint8_T
  rtu_Fault_level, uint8_T rtu_Fault_serial, const uint8_T rtu_SnapShots_Infos
  [61], boolean_T rtu_ssInfosUpdate_flg)
{
  /* Gateway: DHP_FaultStore_Chart */
  /* During: DHP_FaultStore_Chart */
  /* Entry Internal: DHP_FaultStore_Chart */
  /* Transition: '<S227>:7' */
  if (rtu_Fault_flg) {
    /* Transition: '<S227>:3' */
    FaultStore(true, rtu_Fault_level, rtu_Fault_serial, &rtu_SnapShots_Infos[0],
               rtu_ssInfosUpdate_flg);
  }
}

/* Output and update for atomic system: '<S537>/DHP_systemtick_Timer' */
void DHP_model_DHP_systemtick_Timer(boolean_T rtu_Enable, uint8_T
  rtu_DeltaSystemTick_ms, uint16_T rtu_KeepTime_ms,
  DW_DHP_systemtick_Timer_DHP_model_T *localDW)
{
  uint32_T qY;
  uint8_T rtu_Enable_0;

  /* Switch: '<S586>/Switch' incorporates:
   *  Constant: '<S586>/Constant'
   *  Logic: '<S586>/Logical Operator'
   *  Logic: '<S586>/Logical Operator1'
   *  UnitDelay: '<S586>/UnitDelay1'
   */
  if (rtu_Enable && (!VDHP_ACCHWSignalInstFlt_flg)) {
    /* Switch: '<S586>/Switch2' incorporates:
     *  Constant: '<S586>/Constant2'
     *  Delay: '<S586>/Delay'
     *  Logic: '<S586>/Logical Operator2'
     */
    if (!localDW->Delay_DSTATE) {
      rtu_Enable_0 = 0U;
    } else {
      rtu_Enable_0 = rtu_DeltaSystemTick_ms;
    }

    /* End of Switch: '<S586>/Switch2' */
  } else {
    rtu_Enable_0 = 0U;
  }

  /* End of Switch: '<S586>/Switch' */

  /* Sum: '<S586>/Add1' incorporates:
   *  UnitDelay: '<S586>/UnitDelay'
   */
  qY = localDW->UnitDelay_DSTATE + rtu_Enable_0;
  if (qY < localDW->UnitDelay_DSTATE) {
    qY = MAX_uint32_T;
  }

  /* RelationalOperator: '<S586>/Relational Operator' incorporates:
   *  Sum: '<S586>/Add1'
   */
  VDHP_ACCHWSignalInstFlt_flg = (qY >= rtu_KeepTime_ms);

  /* Switch: '<S586>/Switch1' */
  if (rtu_Enable) {
    /* Update for UnitDelay: '<S586>/UnitDelay' incorporates:
     *  Sum: '<S586>/Add1'
     */
    localDW->UnitDelay_DSTATE = qY;
  } else {
    /* Update for UnitDelay: '<S586>/UnitDelay' incorporates:
     *  Constant: '<S586>/Constant1'
     */
    localDW->UnitDelay_DSTATE = 0U;
  }

  /* End of Switch: '<S586>/Switch1' */

  /* Update for Delay: '<S586>/Delay' */
  localDW->Delay_DSTATE = rtu_Enable;
}

/* Output and update for atomic system: '<S663>/DHP_systemtick_Timer' */
void DHP_model_DHP_systemtick_Timer_p(boolean_T rtu_Enable, uint8_T
  rtu_DeltaSystemTick_ms, uint32_T rtu_KeepTime_ms,
  DW_DHP_systemtick_Timer_DHP_model_d_T *localDW)
{
  uint32_T qY;
  uint8_T rtu_Enable_0;

  /* Switch: '<S668>/Switch' incorporates:
   *  Constant: '<S668>/Constant'
   *  Logic: '<S668>/Logical Operator'
   *  Logic: '<S668>/Logical Operator1'
   *  UnitDelay: '<S668>/UnitDelay1'
   */
  if (rtu_Enable && (!VDHP_CruiseKeySetFlt_flg)) {
    /* Switch: '<S668>/Switch2' incorporates:
     *  Constant: '<S668>/Constant2'
     *  Delay: '<S668>/Delay'
     *  Logic: '<S668>/Logical Operator2'
     */
    if (!localDW->Delay_DSTATE) {
      rtu_Enable_0 = 0U;
    } else {
      rtu_Enable_0 = rtu_DeltaSystemTick_ms;
    }

    /* End of Switch: '<S668>/Switch2' */
  } else {
    rtu_Enable_0 = 0U;
  }

  /* End of Switch: '<S668>/Switch' */

  /* Sum: '<S668>/Add1' incorporates:
   *  UnitDelay: '<S668>/UnitDelay'
   */
  qY = localDW->UnitDelay_DSTATE + rtu_Enable_0;
  if (qY < localDW->UnitDelay_DSTATE) {
    qY = MAX_uint32_T;
  }

  /* RelationalOperator: '<S668>/Relational Operator' incorporates:
   *  Sum: '<S668>/Add1'
   */
  VDHP_CruiseKeySetFlt_flg = (qY >= rtu_KeepTime_ms);

  /* Switch: '<S668>/Switch1' */
  if (rtu_Enable) {
    /* Update for UnitDelay: '<S668>/UnitDelay' incorporates:
     *  Sum: '<S668>/Add1'
     */
    localDW->UnitDelay_DSTATE = qY;
  } else {
    /* Update for UnitDelay: '<S668>/UnitDelay' incorporates:
     *  Constant: '<S668>/Constant1'
     */
    localDW->UnitDelay_DSTATE = 0U;
  }

  /* End of Switch: '<S668>/Switch1' */

  /* Update for Delay: '<S668>/Delay' */
  localDW->Delay_DSTATE = rtu_Enable;
}

/* Output and update for atomic system: '<S663>/DHP_systemtick_Timer1' */
void DHP_model_DHP_systemtick_Timer1(boolean_T rtu_Enable, uint8_T
  rtu_DeltaSystemTick_ms, uint32_T rtu_KeepTime_ms,
  DW_DHP_systemtick_Timer_DHP_model_e_T *localDW)
{
  uint32_T qY;
  uint8_T rtu_Enable_0;

  /* Switch: '<S669>/Switch' incorporates:
   *  Constant: '<S669>/Constant'
   *  Logic: '<S669>/Logical Operator'
   *  Logic: '<S669>/Logical Operator1'
   *  UnitDelay: '<S669>/UnitDelay1'
   */
  if (rtu_Enable && (!VDHP_CruiseKeyResFlt_flg)) {
    /* Switch: '<S669>/Switch2' incorporates:
     *  Constant: '<S669>/Constant2'
     *  Delay: '<S669>/Delay'
     *  Logic: '<S669>/Logical Operator2'
     */
    if (!localDW->Delay_DSTATE) {
      rtu_Enable_0 = 0U;
    } else {
      rtu_Enable_0 = rtu_DeltaSystemTick_ms;
    }

    /* End of Switch: '<S669>/Switch2' */
  } else {
    rtu_Enable_0 = 0U;
  }

  /* End of Switch: '<S669>/Switch' */

  /* Sum: '<S669>/Add1' incorporates:
   *  UnitDelay: '<S669>/UnitDelay'
   */
  qY = localDW->UnitDelay_DSTATE + rtu_Enable_0;
  if (qY < localDW->UnitDelay_DSTATE) {
    qY = MAX_uint32_T;
  }

  /* RelationalOperator: '<S669>/Relational Operator' incorporates:
   *  Sum: '<S669>/Add1'
   */
  VDHP_CruiseKeyResFlt_flg = (qY >= rtu_KeepTime_ms);

  /* Switch: '<S669>/Switch1' */
  if (rtu_Enable) {
    /* Update for UnitDelay: '<S669>/UnitDelay' incorporates:
     *  Sum: '<S669>/Add1'
     */
    localDW->UnitDelay_DSTATE = qY;
  } else {
    /* Update for UnitDelay: '<S669>/UnitDelay' incorporates:
     *  Constant: '<S669>/Constant1'
     */
    localDW->UnitDelay_DSTATE = 0U;
  }

  /* End of Switch: '<S669>/Switch1' */

  /* Update for Delay: '<S669>/Delay' */
  localDW->Delay_DSTATE = rtu_Enable;
}

/*
 * Output and update for atomic system:
 *    '<S689>/DHP_systemtick_Timer'
 *    '<S705>/DHP_systemtick_Timer'
 *    '<S703>/DHP_systemtick_Timer'
 *    '<S703>/DHP_systemtick_Timer1'
 *    '<S704>/DHP_systemtick_Timer'
 *    '<S717>/DHP_systemtick_Timer'
 *    '<S718>/DHP_systemtick_Timer'
 *    '<S767>/DHP_systemtick_Timer'
 *    '<S771>/DHP_systemtick_Timer'
 *    '<S772>/DHP_systemtick_Timer'
 *    ...
 */
void DHP_model_DHP_systemtick_Timer_c(boolean_T rtu_Enable, uint8_T
  rtu_DeltaSystemTick_ms, uint16_T rtu_KeepTime_ms,
  B_DHP_systemtick_Timer_DHP_model_k_T *localB,
  DW_DHP_systemtick_Timer_DHP_model_m_T *localDW)
{
  uint32_T qY;
  uint8_T rtu_Enable_0;

  /* Switch: '<S699>/Switch' incorporates:
   *  Constant: '<S699>/Constant'
   *  Logic: '<S699>/Logical Operator'
   *  Logic: '<S699>/Logical Operator1'
   *  UnitDelay: '<S699>/UnitDelay1'
   */
  if (rtu_Enable && (!localB->RelationalOperator)) {
    /* Switch: '<S699>/Switch2' incorporates:
     *  Constant: '<S699>/Constant2'
     *  Delay: '<S699>/Delay'
     *  Logic: '<S699>/Logical Operator2'
     */
    if (!localDW->Delay_DSTATE) {
      rtu_Enable_0 = 0U;
    } else {
      rtu_Enable_0 = rtu_DeltaSystemTick_ms;
    }

    /* End of Switch: '<S699>/Switch2' */
  } else {
    rtu_Enable_0 = 0U;
  }

  /* End of Switch: '<S699>/Switch' */

  /* Sum: '<S699>/Add1' incorporates:
   *  UnitDelay: '<S699>/UnitDelay'
   */
  qY = localDW->UnitDelay_DSTATE + rtu_Enable_0;
  if (qY < localDW->UnitDelay_DSTATE) {
    qY = MAX_uint32_T;
  }

  /* RelationalOperator: '<S699>/Relational Operator' incorporates:
   *  Sum: '<S699>/Add1'
   */
  localB->RelationalOperator = (qY >= rtu_KeepTime_ms);

  /* Switch: '<S699>/Switch1' */
  if (rtu_Enable) {
    /* Update for UnitDelay: '<S699>/UnitDelay' incorporates:
     *  Sum: '<S699>/Add1'
     */
    localDW->UnitDelay_DSTATE = qY;
  } else {
    /* Update for UnitDelay: '<S699>/UnitDelay' incorporates:
     *  Constant: '<S699>/Constant1'
     */
    localDW->UnitDelay_DSTATE = 0U;
  }

  /* End of Switch: '<S699>/Switch1' */

  /* Update for Delay: '<S699>/Delay' */
  localDW->Delay_DSTATE = rtu_Enable;
}

/* Output and update for atomic system: '<S766>/DHP_systemtick_Timer' */
void DHP_model_DHP_systemtick_Timer_n(boolean_T rtu_Enable, uint8_T
  rtu_DeltaSystemTick_ms, uint16_T rtu_KeepTime_ms,
  DW_DHP_systemtick_Timer_DHP_model_md_T *localDW)
{
  uint32_T qY;
  uint8_T rtu_Enable_0;

  /* Switch: '<S768>/Switch' incorporates:
   *  Constant: '<S768>/Constant'
   *  Logic: '<S768>/Logical Operator'
   *  Logic: '<S768>/Logical Operator1'
   *  UnitDelay: '<S768>/UnitDelay1'
   */
  if (rtu_Enable && (!localDW->UnitDelay1_DSTATE)) {
    /* Switch: '<S768>/Switch2' incorporates:
     *  Constant: '<S768>/Constant2'
     *  Delay: '<S768>/Delay'
     *  Logic: '<S768>/Logical Operator2'
     */
    if (!localDW->Delay_DSTATE) {
      rtu_Enable_0 = 0U;
    } else {
      rtu_Enable_0 = rtu_DeltaSystemTick_ms;
    }

    /* End of Switch: '<S768>/Switch2' */
  } else {
    rtu_Enable_0 = 0U;
  }

  /* End of Switch: '<S768>/Switch' */

  /* Sum: '<S768>/Add1' incorporates:
   *  UnitDelay: '<S768>/UnitDelay'
   */
  qY = localDW->UnitDelay_DSTATE + rtu_Enable_0;
  if (qY < localDW->UnitDelay_DSTATE) {
    qY = MAX_uint32_T;
  }

  /* RelationalOperator: '<S768>/Relational Operator' incorporates:
   *  Sum: '<S768>/Add1'
   */
  VDHP_ABS232MissingInstFlt_flg = (qY >= rtu_KeepTime_ms);

  /* Switch: '<S768>/Switch1' */
  if (rtu_Enable) {
    /* Update for UnitDelay: '<S768>/UnitDelay' incorporates:
     *  Sum: '<S768>/Add1'
     */
    localDW->UnitDelay_DSTATE = qY;
  } else {
    /* Update for UnitDelay: '<S768>/UnitDelay' incorporates:
     *  Constant: '<S768>/Constant1'
     */
    localDW->UnitDelay_DSTATE = 0U;
  }

  /* End of Switch: '<S768>/Switch1' */

  /* Update for Delay: '<S768>/Delay' */
  localDW->Delay_DSTATE = rtu_Enable;

  /* Update for UnitDelay: '<S768>/UnitDelay1' */
  localDW->UnitDelay1_DSTATE = VDHP_ABS232MissingInstFlt_flg;
}

/* Output and update for atomic system: '<S770>/DHP_systemtick_Timer' */
void DHP_model_DHP_systemtick_Timer_e(boolean_T rtu_Enable, uint8_T
  rtu_DeltaSystemTick_ms, uint16_T rtu_KeepTime_ms,
  DW_DHP_systemtick_Timer_DHP_model_i_T *localDW)
{
  uint32_T qY;
  uint8_T rtu_Enable_0;

  /* Switch: '<S788>/Switch' incorporates:
   *  Constant: '<S788>/Constant'
   *  Logic: '<S788>/Logical Operator'
   *  Logic: '<S788>/Logical Operator1'
   *  UnitDelay: '<S788>/UnitDelay1'
   */
  if (rtu_Enable && (!BMS_313LossCanNetInstFlt_flg)) {
    /* Switch: '<S788>/Switch2' incorporates:
     *  Constant: '<S788>/Constant2'
     *  Delay: '<S788>/Delay'
     *  Logic: '<S788>/Logical Operator2'
     */
    if (!localDW->Delay_DSTATE) {
      rtu_Enable_0 = 0U;
    } else {
      rtu_Enable_0 = rtu_DeltaSystemTick_ms;
    }

    /* End of Switch: '<S788>/Switch2' */
  } else {
    rtu_Enable_0 = 0U;
  }

  /* End of Switch: '<S788>/Switch' */

  /* Sum: '<S788>/Add1' incorporates:
   *  UnitDelay: '<S788>/UnitDelay'
   */
  qY = localDW->UnitDelay_DSTATE + rtu_Enable_0;
  if (qY < localDW->UnitDelay_DSTATE) {
    qY = MAX_uint32_T;
  }

  /* RelationalOperator: '<S788>/Relational Operator' incorporates:
   *  Sum: '<S788>/Add1'
   */
  BMS_313LossCanNetInstFlt_flg = (qY >= rtu_KeepTime_ms);

  /* Switch: '<S788>/Switch1' */
  if (rtu_Enable) {
    /* Update for UnitDelay: '<S788>/UnitDelay' incorporates:
     *  Sum: '<S788>/Add1'
     */
    localDW->UnitDelay_DSTATE = qY;
  } else {
    /* Update for UnitDelay: '<S788>/UnitDelay' incorporates:
     *  Constant: '<S788>/Constant1'
     */
    localDW->UnitDelay_DSTATE = 0U;
  }

  /* End of Switch: '<S788>/Switch1' */

  /* Update for Delay: '<S788>/Delay' */
  localDW->Delay_DSTATE = rtu_Enable;
}

/* Output and update for atomic system: '<S778>/DHP_systemtick_Timer' */
void DHP_model_DHP_systemtick_Timer_k(boolean_T rtu_Enable, uint8_T
  rtu_DeltaSystemTick_ms, uint16_T rtu_KeepTime_ms,
  DW_DHP_systemtick_Timer_DHP_model_ii_T *localDW)
{
  uint32_T qY;
  uint8_T rtu_Enable_0;

  /* Switch: '<S796>/Switch' incorporates:
   *  Constant: '<S796>/Constant'
   *  Logic: '<S796>/Logical Operator'
   *  Logic: '<S796>/Logical Operator1'
   *  UnitDelay: '<S796>/UnitDelay1'
   */
  if (rtu_Enable && (!VDHP_BMSLossCanNetInstFlt_flg)) {
    /* Switch: '<S796>/Switch2' incorporates:
     *  Constant: '<S796>/Constant2'
     *  Delay: '<S796>/Delay'
     *  Logic: '<S796>/Logical Operator2'
     */
    if (!localDW->Delay_DSTATE) {
      rtu_Enable_0 = 0U;
    } else {
      rtu_Enable_0 = rtu_DeltaSystemTick_ms;
    }

    /* End of Switch: '<S796>/Switch2' */
  } else {
    rtu_Enable_0 = 0U;
  }

  /* End of Switch: '<S796>/Switch' */

  /* Sum: '<S796>/Add1' incorporates:
   *  UnitDelay: '<S796>/UnitDelay'
   */
  qY = localDW->UnitDelay_DSTATE + rtu_Enable_0;
  if (qY < localDW->UnitDelay_DSTATE) {
    qY = MAX_uint32_T;
  }

  /* RelationalOperator: '<S796>/Relational Operator' incorporates:
   *  Sum: '<S796>/Add1'
   */
  VDHP_BMSLossCanNetInstFlt_flg = (qY >= rtu_KeepTime_ms);

  /* Switch: '<S796>/Switch1' */
  if (rtu_Enable) {
    /* Update for UnitDelay: '<S796>/UnitDelay' incorporates:
     *  Sum: '<S796>/Add1'
     */
    localDW->UnitDelay_DSTATE = qY;
  } else {
    /* Update for UnitDelay: '<S796>/UnitDelay' incorporates:
     *  Constant: '<S796>/Constant1'
     */
    localDW->UnitDelay_DSTATE = 0U;
  }

  /* End of Switch: '<S796>/Switch1' */

  /* Update for Delay: '<S796>/Delay' */
  localDW->Delay_DSTATE = rtu_Enable;
}

/* Output and update for atomic system: '<S779>/DHP_systemtick_Timer' */
void DHP_model_DHP_systemtick_Timer_o(boolean_T rtu_Enable, uint8_T
  rtu_DeltaSystemTick_ms, uint16_T rtu_KeepTime_ms,
  DW_DHP_systemtick_Timer_DHP_model_mg_T *localDW)
{
  uint32_T qY;
  uint8_T rtu_Enable_0;

  /* Switch: '<S797>/Switch' incorporates:
   *  Constant: '<S797>/Constant'
   *  Logic: '<S797>/Logical Operator'
   *  Logic: '<S797>/Logical Operator1'
   *  UnitDelay: '<S797>/UnitDelay1'
   */
  if (rtu_Enable && (!BMS_113LossCanNetInstFlt_flg)) {
    /* Switch: '<S797>/Switch2' incorporates:
     *  Constant: '<S797>/Constant2'
     *  Delay: '<S797>/Delay'
     *  Logic: '<S797>/Logical Operator2'
     */
    if (!localDW->Delay_DSTATE) {
      rtu_Enable_0 = 0U;
    } else {
      rtu_Enable_0 = rtu_DeltaSystemTick_ms;
    }

    /* End of Switch: '<S797>/Switch2' */
  } else {
    rtu_Enable_0 = 0U;
  }

  /* End of Switch: '<S797>/Switch' */

  /* Sum: '<S797>/Add1' incorporates:
   *  UnitDelay: '<S797>/UnitDelay'
   */
  qY = localDW->UnitDelay_DSTATE + rtu_Enable_0;
  if (qY < localDW->UnitDelay_DSTATE) {
    qY = MAX_uint32_T;
  }

  /* RelationalOperator: '<S797>/Relational Operator' incorporates:
   *  Sum: '<S797>/Add1'
   */
  BMS_113LossCanNetInstFlt_flg = (qY >= rtu_KeepTime_ms);

  /* Switch: '<S797>/Switch1' */
  if (rtu_Enable) {
    /* Update for UnitDelay: '<S797>/UnitDelay' incorporates:
     *  Sum: '<S797>/Add1'
     */
    localDW->UnitDelay_DSTATE = qY;
  } else {
    /* Update for UnitDelay: '<S797>/UnitDelay' incorporates:
     *  Constant: '<S797>/Constant1'
     */
    localDW->UnitDelay_DSTATE = 0U;
  }

  /* End of Switch: '<S797>/Switch1' */

  /* Update for Delay: '<S797>/Delay' */
  localDW->Delay_DSTATE = rtu_Enable;
}

/* Output and update for atomic system: '<S780>/DHP_systemtick_Timer' */
void DHP_model_DHP_systemtick_Timer_g(boolean_T rtu_Enable, uint8_T
  rtu_DeltaSystemTick_ms, uint16_T rtu_KeepTime_ms,
  DW_DHP_systemtick_Timer_DHP_model_j_T *localDW)
{
  uint32_T qY;
  uint8_T rtu_Enable_0;

  /* Switch: '<S798>/Switch' incorporates:
   *  Constant: '<S798>/Constant'
   *  Logic: '<S798>/Logical Operator'
   *  Logic: '<S798>/Logical Operator1'
   *  UnitDelay: '<S798>/UnitDelay1'
   */
  if (rtu_Enable && (!BMS_633LossCanNetInstFlt_flg)) {
    /* Switch: '<S798>/Switch2' incorporates:
     *  Constant: '<S798>/Constant2'
     *  Delay: '<S798>/Delay'
     *  Logic: '<S798>/Logical Operator2'
     */
    if (!localDW->Delay_DSTATE) {
      rtu_Enable_0 = 0U;
    } else {
      rtu_Enable_0 = rtu_DeltaSystemTick_ms;
    }

    /* End of Switch: '<S798>/Switch2' */
  } else {
    rtu_Enable_0 = 0U;
  }

  /* End of Switch: '<S798>/Switch' */

  /* Sum: '<S798>/Add1' incorporates:
   *  UnitDelay: '<S798>/UnitDelay'
   */
  qY = localDW->UnitDelay_DSTATE + rtu_Enable_0;
  if (qY < localDW->UnitDelay_DSTATE) {
    qY = MAX_uint32_T;
  }

  /* RelationalOperator: '<S798>/Relational Operator' incorporates:
   *  Sum: '<S798>/Add1'
   */
  BMS_633LossCanNetInstFlt_flg = (qY >= rtu_KeepTime_ms);

  /* Switch: '<S798>/Switch1' */
  if (rtu_Enable) {
    /* Update for UnitDelay: '<S798>/UnitDelay' incorporates:
     *  Sum: '<S798>/Add1'
     */
    localDW->UnitDelay_DSTATE = qY;
  } else {
    /* Update for UnitDelay: '<S798>/UnitDelay' incorporates:
     *  Constant: '<S798>/Constant1'
     */
    localDW->UnitDelay_DSTATE = 0U;
  }

  /* End of Switch: '<S798>/Switch1' */

  /* Update for Delay: '<S798>/Delay' */
  localDW->Delay_DSTATE = rtu_Enable;
}

/* Output and update for atomic system: '<S807>/DHP_systemtick_Timer' */
void DHP_model_DHP_systemtick_Timer_k2(boolean_T rtu_Enable, uint8_T
  rtu_DeltaSystemTick_ms, uint16_T rtu_KeepTime_ms,
  DW_DHP_systemtick_Timer_DHP_model_n_T *localDW)
{
  uint32_T qY;
  uint8_T rtu_Enable_0;

  /* Switch: '<S810>/Switch' incorporates:
   *  Constant: '<S810>/Constant'
   *  Logic: '<S810>/Logical Operator'
   *  Logic: '<S810>/Logical Operator1'
   *  UnitDelay: '<S810>/UnitDelay1'
   */
  if (rtu_Enable && (!VDHP_DCDCLossCanNetInstFlt_flg)) {
    /* Switch: '<S810>/Switch2' incorporates:
     *  Constant: '<S810>/Constant2'
     *  Delay: '<S810>/Delay'
     *  Logic: '<S810>/Logical Operator2'
     */
    if (!localDW->Delay_DSTATE) {
      rtu_Enable_0 = 0U;
    } else {
      rtu_Enable_0 = rtu_DeltaSystemTick_ms;
    }

    /* End of Switch: '<S810>/Switch2' */
  } else {
    rtu_Enable_0 = 0U;
  }

  /* End of Switch: '<S810>/Switch' */

  /* Sum: '<S810>/Add1' incorporates:
   *  UnitDelay: '<S810>/UnitDelay'
   */
  qY = localDW->UnitDelay_DSTATE + rtu_Enable_0;
  if (qY < localDW->UnitDelay_DSTATE) {
    qY = MAX_uint32_T;
  }

  /* RelationalOperator: '<S810>/Relational Operator' incorporates:
   *  Sum: '<S810>/Add1'
   */
  VDHP_DCDCLossCanNetInstFlt_flg = (qY >= rtu_KeepTime_ms);

  /* Switch: '<S810>/Switch1' */
  if (rtu_Enable) {
    /* Update for UnitDelay: '<S810>/UnitDelay' incorporates:
     *  Sum: '<S810>/Add1'
     */
    localDW->UnitDelay_DSTATE = qY;
  } else {
    /* Update for UnitDelay: '<S810>/UnitDelay' incorporates:
     *  Constant: '<S810>/Constant1'
     */
    localDW->UnitDelay_DSTATE = 0U;
  }

  /* End of Switch: '<S810>/Switch1' */

  /* Update for Delay: '<S810>/Delay' */
  localDW->Delay_DSTATE = rtu_Enable;
}

/* Output and update for atomic system: '<S750>/DHP_systemtick_Timer' */
void DHP_model_DHP_systemtick_Timer_m(boolean_T rtu_Enable, uint8_T
  rtu_DeltaSystemTick_ms, uint16_T rtu_KeepTime_ms,
  DW_DHP_systemtick_Timer_DHP_model_np_T *localDW)
{
  uint32_T qY;
  uint8_T rtu_Enable_0;

  /* Switch: '<S811>/Switch' incorporates:
   *  Constant: '<S811>/Constant'
   *  Logic: '<S811>/Logical Operator'
   *  Logic: '<S811>/Logical Operator1'
   *  UnitDelay: '<S811>/UnitDelay1'
   */
  if (rtu_Enable && (!localDW->UnitDelay1_DSTATE)) {
    /* Switch: '<S811>/Switch2' incorporates:
     *  Constant: '<S811>/Constant2'
     *  Delay: '<S811>/Delay'
     *  Logic: '<S811>/Logical Operator2'
     */
    if (!localDW->Delay_DSTATE) {
      rtu_Enable_0 = 0U;
    } else {
      rtu_Enable_0 = rtu_DeltaSystemTick_ms;
    }

    /* End of Switch: '<S811>/Switch2' */
  } else {
    rtu_Enable_0 = 0U;
  }

  /* End of Switch: '<S811>/Switch' */

  /* Sum: '<S811>/Add1' incorporates:
   *  UnitDelay: '<S811>/UnitDelay'
   */
  qY = localDW->UnitDelay_DSTATE + rtu_Enable_0;
  if (qY < localDW->UnitDelay_DSTATE) {
    qY = MAX_uint32_T;
  }

  /* RelationalOperator: '<S811>/Relational Operator' incorporates:
   *  Sum: '<S811>/Add1'
   */
  VDHP_EACLossCanNetInstFlt_flg = (qY >= rtu_KeepTime_ms);

  /* Switch: '<S811>/Switch1' */
  if (rtu_Enable) {
    /* Update for UnitDelay: '<S811>/UnitDelay' incorporates:
     *  Sum: '<S811>/Add1'
     */
    localDW->UnitDelay_DSTATE = qY;
  } else {
    /* Update for UnitDelay: '<S811>/UnitDelay' incorporates:
     *  Constant: '<S811>/Constant1'
     */
    localDW->UnitDelay_DSTATE = 0U;
  }

  /* End of Switch: '<S811>/Switch1' */

  /* Update for Delay: '<S811>/Delay' */
  localDW->Delay_DSTATE = rtu_Enable;

  /* Update for UnitDelay: '<S811>/UnitDelay1' */
  localDW->UnitDelay1_DSTATE = VDHP_EACLossCanNetInstFlt_flg;
}

/* Output and update for atomic system: '<S812>/DHP_systemtick_Timer' */
void DHP_model_DHP_systemtick_Timer_m3(boolean_T rtu_Enable, uint8_T
  rtu_DeltaSystemTick_ms, uint16_T rtu_KeepTime_ms,
  DW_DHP_systemtick_Timer_DHP_model_g_T *localDW)
{
  uint32_T qY;
  uint8_T rtu_Enable_0;

  /* Switch: '<S813>/Switch' incorporates:
   *  Constant: '<S813>/Constant'
   *  Logic: '<S813>/Logical Operator'
   *  Logic: '<S813>/Logical Operator1'
   *  UnitDelay: '<S813>/UnitDelay1'
   */
  if (rtu_Enable && (!localDW->UnitDelay1_DSTATE)) {
    /* Switch: '<S813>/Switch2' incorporates:
     *  Constant: '<S813>/Constant2'
     *  Delay: '<S813>/Delay'
     *  Logic: '<S813>/Logical Operator2'
     */
    if (!localDW->Delay_DSTATE) {
      rtu_Enable_0 = 0U;
    } else {
      rtu_Enable_0 = rtu_DeltaSystemTick_ms;
    }

    /* End of Switch: '<S813>/Switch2' */
  } else {
    rtu_Enable_0 = 0U;
  }

  /* End of Switch: '<S813>/Switch' */

  /* Sum: '<S813>/Add1' incorporates:
   *  UnitDelay: '<S813>/UnitDelay'
   */
  qY = localDW->UnitDelay_DSTATE + rtu_Enable_0;
  if (qY < localDW->UnitDelay_DSTATE) {
    qY = MAX_uint32_T;
  }

  /* RelationalOperator: '<S813>/Relational Operator' incorporates:
   *  Sum: '<S813>/Add1'
   */
  VDHP_ECCLossCanNetInstFlt_flg = (qY >= rtu_KeepTime_ms);

  /* Switch: '<S813>/Switch1' */
  if (rtu_Enable) {
    /* Update for UnitDelay: '<S813>/UnitDelay' incorporates:
     *  Sum: '<S813>/Add1'
     */
    localDW->UnitDelay_DSTATE = qY;
  } else {
    /* Update for UnitDelay: '<S813>/UnitDelay' incorporates:
     *  Constant: '<S813>/Constant1'
     */
    localDW->UnitDelay_DSTATE = 0U;
  }

  /* End of Switch: '<S813>/Switch1' */

  /* Update for Delay: '<S813>/Delay' */
  localDW->Delay_DSTATE = rtu_Enable;

  /* Update for UnitDelay: '<S813>/UnitDelay1' */
  localDW->UnitDelay1_DSTATE = VDHP_ECCLossCanNetInstFlt_flg;
}

/* Output and update for atomic system: '<S752>/DHP_systemtick_Timer' */
void DHP_model_DHP_systemtick_Timer_l(boolean_T rtu_Enable, uint8_T
  rtu_DeltaSystemTick_ms, uint16_T rtu_KeepTime_ms,
  DW_DHP_systemtick_Timer_DHP_model_mc_T *localDW)
{
  uint32_T qY;
  uint8_T rtu_Enable_0;

  /* Switch: '<S814>/Switch' incorporates:
   *  Constant: '<S814>/Constant'
   *  Logic: '<S814>/Logical Operator'
   *  Logic: '<S814>/Logical Operator1'
   *  UnitDelay: '<S814>/UnitDelay1'
   */
  if (rtu_Enable && (!localDW->UnitDelay1_DSTATE)) {
    /* Switch: '<S814>/Switch2' incorporates:
     *  Constant: '<S814>/Constant2'
     *  Delay: '<S814>/Delay'
     *  Logic: '<S814>/Logical Operator2'
     */
    if (!localDW->Delay_DSTATE) {
      rtu_Enable_0 = 0U;
    } else {
      rtu_Enable_0 = rtu_DeltaSystemTick_ms;
    }

    /* End of Switch: '<S814>/Switch2' */
  } else {
    rtu_Enable_0 = 0U;
  }

  /* End of Switch: '<S814>/Switch' */

  /* Sum: '<S814>/Add1' incorporates:
   *  UnitDelay: '<S814>/UnitDelay'
   */
  qY = localDW->UnitDelay_DSTATE + rtu_Enable_0;
  if (qY < localDW->UnitDelay_DSTATE) {
    qY = MAX_uint32_T;
  }

  /* RelationalOperator: '<S814>/Relational Operator' incorporates:
   *  Sum: '<S814>/Add1'
   */
  VDHP_EHULossCanNetInstFlt_flg = (qY >= rtu_KeepTime_ms);

  /* Switch: '<S814>/Switch1' */
  if (rtu_Enable) {
    /* Update for UnitDelay: '<S814>/UnitDelay' incorporates:
     *  Sum: '<S814>/Add1'
     */
    localDW->UnitDelay_DSTATE = qY;
  } else {
    /* Update for UnitDelay: '<S814>/UnitDelay' incorporates:
     *  Constant: '<S814>/Constant1'
     */
    localDW->UnitDelay_DSTATE = 0U;
  }

  /* End of Switch: '<S814>/Switch1' */

  /* Update for Delay: '<S814>/Delay' */
  localDW->Delay_DSTATE = rtu_Enable;

  /* Update for UnitDelay: '<S814>/UnitDelay1' */
  localDW->UnitDelay1_DSTATE = VDHP_EHULossCanNetInstFlt_flg;
}

/* Output and update for atomic system: '<S815>/DHP_systemtick_Timer' */
void DHP_model_DHP_systemtick_Timer_f(boolean_T rtu_Enable, uint8_T
  rtu_DeltaSystemTick_ms, uint16_T rtu_KeepTime_ms,
  DW_DHP_systemtick_Timer_DHP_model_ge_T *localDW)
{
  uint32_T qY;
  uint8_T rtu_Enable_0;

  /* Switch: '<S816>/Switch' incorporates:
   *  Constant: '<S816>/Constant'
   *  Logic: '<S816>/Logical Operator'
   *  Logic: '<S816>/Logical Operator1'
   *  UnitDelay: '<S816>/UnitDelay1'
   */
  if (rtu_Enable && (!localDW->UnitDelay1_DSTATE)) {
    /* Switch: '<S816>/Switch2' incorporates:
     *  Constant: '<S816>/Constant2'
     *  Delay: '<S816>/Delay'
     *  Logic: '<S816>/Logical Operator2'
     */
    if (!localDW->Delay_DSTATE) {
      rtu_Enable_0 = 0U;
    } else {
      rtu_Enable_0 = rtu_DeltaSystemTick_ms;
    }

    /* End of Switch: '<S816>/Switch2' */
  } else {
    rtu_Enable_0 = 0U;
  }

  /* End of Switch: '<S816>/Switch' */

  /* Sum: '<S816>/Add1' incorporates:
   *  UnitDelay: '<S816>/UnitDelay'
   */
  qY = localDW->UnitDelay_DSTATE + rtu_Enable_0;
  if (qY < localDW->UnitDelay_DSTATE) {
    qY = MAX_uint32_T;
  }

  /* RelationalOperator: '<S816>/Relational Operator' incorporates:
   *  Sum: '<S816>/Add1'
   */
  VDHP_EPSLossCanNetInstFlt_flg = (qY >= rtu_KeepTime_ms);

  /* Switch: '<S816>/Switch1' */
  if (rtu_Enable) {
    /* Update for UnitDelay: '<S816>/UnitDelay' incorporates:
     *  Sum: '<S816>/Add1'
     */
    localDW->UnitDelay_DSTATE = qY;
  } else {
    /* Update for UnitDelay: '<S816>/UnitDelay' incorporates:
     *  Constant: '<S816>/Constant1'
     */
    localDW->UnitDelay_DSTATE = 0U;
  }

  /* End of Switch: '<S816>/Switch1' */

  /* Update for Delay: '<S816>/Delay' */
  localDW->Delay_DSTATE = rtu_Enable;

  /* Update for UnitDelay: '<S816>/UnitDelay1' */
  localDW->UnitDelay1_DSTATE = VDHP_EPSLossCanNetInstFlt_flg;
}

/* Output and update for atomic system: '<S755>/DHP_systemtick_Timer1' */
void DHP_model_DHP_systemtick_Timer1_k(boolean_T rtu_Enable, uint8_T
  rtu_DeltaSystemTick_ms, uint16_T rtu_KeepTime_ms,
  DW_DHP_systemtick_Timer_DHP_model_a_T *localDW)
{
  uint32_T qY;
  uint8_T rtu_Enable_0;

  /* Switch: '<S822>/Switch' incorporates:
   *  Constant: '<S822>/Constant'
   *  Logic: '<S822>/Logical Operator'
   *  Logic: '<S822>/Logical Operator1'
   *  UnitDelay: '<S822>/UnitDelay1'
   */
  if (rtu_Enable && (!localDW->UnitDelay1_DSTATE)) {
    /* Switch: '<S822>/Switch2' incorporates:
     *  Constant: '<S822>/Constant2'
     *  Delay: '<S822>/Delay'
     *  Logic: '<S822>/Logical Operator2'
     */
    if (!localDW->Delay_DSTATE) {
      rtu_Enable_0 = 0U;
    } else {
      rtu_Enable_0 = rtu_DeltaSystemTick_ms;
    }

    /* End of Switch: '<S822>/Switch2' */
  } else {
    rtu_Enable_0 = 0U;
  }

  /* End of Switch: '<S822>/Switch' */

  /* Sum: '<S822>/Add1' incorporates:
   *  UnitDelay: '<S822>/UnitDelay'
   */
  qY = localDW->UnitDelay_DSTATE + rtu_Enable_0;
  if (qY < localDW->UnitDelay_DSTATE) {
    qY = MAX_uint32_T;
  }

  /* RelationalOperator: '<S822>/Relational Operator' incorporates:
   *  Sum: '<S822>/Add1'
   */
  VDHP_ICM235MissingInstFlt_flg = (qY >= rtu_KeepTime_ms);

  /* Switch: '<S822>/Switch1' */
  if (rtu_Enable) {
    /* Update for UnitDelay: '<S822>/UnitDelay' incorporates:
     *  Sum: '<S822>/Add1'
     */
    localDW->UnitDelay_DSTATE = qY;
  } else {
    /* Update for UnitDelay: '<S822>/UnitDelay' incorporates:
     *  Constant: '<S822>/Constant1'
     */
    localDW->UnitDelay_DSTATE = 0U;
  }

  /* End of Switch: '<S822>/Switch1' */

  /* Update for Delay: '<S822>/Delay' */
  localDW->Delay_DSTATE = rtu_Enable;

  /* Update for UnitDelay: '<S822>/UnitDelay1' */
  localDW->UnitDelay1_DSTATE = VDHP_ICM235MissingInstFlt_flg;
}

/* Output and update for atomic system: '<S823>/DHP_systemtick_Timer' */
void DHP_model_DHP_systemtick_Timer_a(boolean_T rtu_Enable, uint8_T
  rtu_DeltaSystemTick_ms, uint16_T rtu_KeepTime_ms,
  DW_DHP_systemtick_Timer_DHP_model_f_T *localDW)
{
  uint32_T qY;
  uint8_T rtu_Enable_0;

  /* Switch: '<S827>/Switch' incorporates:
   *  Constant: '<S827>/Constant'
   *  Logic: '<S827>/Logical Operator'
   *  Logic: '<S827>/Logical Operator1'
   *  UnitDelay: '<S827>/UnitDelay1'
   */
  if (rtu_Enable && (!MCU125LossCanNetInstFlt_flg)) {
    /* Switch: '<S827>/Switch2' incorporates:
     *  Constant: '<S827>/Constant2'
     *  Delay: '<S827>/Delay'
     *  Logic: '<S827>/Logical Operator2'
     */
    if (!localDW->Delay_DSTATE) {
      rtu_Enable_0 = 0U;
    } else {
      rtu_Enable_0 = rtu_DeltaSystemTick_ms;
    }

    /* End of Switch: '<S827>/Switch2' */
  } else {
    rtu_Enable_0 = 0U;
  }

  /* End of Switch: '<S827>/Switch' */

  /* Sum: '<S827>/Add1' incorporates:
   *  UnitDelay: '<S827>/UnitDelay'
   */
  qY = localDW->UnitDelay_DSTATE + rtu_Enable_0;
  if (qY < localDW->UnitDelay_DSTATE) {
    qY = MAX_uint32_T;
  }

  /* RelationalOperator: '<S827>/Relational Operator' incorporates:
   *  Sum: '<S827>/Add1'
   */
  MCU125LossCanNetInstFlt_flg = (qY >= rtu_KeepTime_ms);

  /* Switch: '<S827>/Switch1' */
  if (rtu_Enable) {
    /* Update for UnitDelay: '<S827>/UnitDelay' incorporates:
     *  Sum: '<S827>/Add1'
     */
    localDW->UnitDelay_DSTATE = qY;
  } else {
    /* Update for UnitDelay: '<S827>/UnitDelay' incorporates:
     *  Constant: '<S827>/Constant1'
     */
    localDW->UnitDelay_DSTATE = 0U;
  }

  /* End of Switch: '<S827>/Switch1' */

  /* Update for Delay: '<S827>/Delay' */
  localDW->Delay_DSTATE = rtu_Enable;
}

/* Output and update for atomic system: '<S824>/DHP_systemtick_Timer' */
void DHP_model_DHP_systemtick_Timer_b(boolean_T rtu_Enable, uint8_T
  rtu_DeltaSystemTick_ms, uint16_T rtu_KeepTime_ms,
  DW_DHP_systemtick_Timer_DHP_model_db_T *localDW)
{
  uint32_T qY;
  uint8_T rtu_Enable_0;

  /* Switch: '<S828>/Switch' incorporates:
   *  Constant: '<S828>/Constant'
   *  Logic: '<S828>/Logical Operator'
   *  Logic: '<S828>/Logical Operator1'
   *  UnitDelay: '<S828>/UnitDelay1'
   */
  if (rtu_Enable && (!MCU115LossCanNetInstFlt_flg)) {
    /* Switch: '<S828>/Switch2' incorporates:
     *  Constant: '<S828>/Constant2'
     *  Delay: '<S828>/Delay'
     *  Logic: '<S828>/Logical Operator2'
     */
    if (!localDW->Delay_DSTATE) {
      rtu_Enable_0 = 0U;
    } else {
      rtu_Enable_0 = rtu_DeltaSystemTick_ms;
    }

    /* End of Switch: '<S828>/Switch2' */
  } else {
    rtu_Enable_0 = 0U;
  }

  /* End of Switch: '<S828>/Switch' */

  /* Sum: '<S828>/Add1' incorporates:
   *  UnitDelay: '<S828>/UnitDelay'
   */
  qY = localDW->UnitDelay_DSTATE + rtu_Enable_0;
  if (qY < localDW->UnitDelay_DSTATE) {
    qY = MAX_uint32_T;
  }

  /* RelationalOperator: '<S828>/Relational Operator' incorporates:
   *  Sum: '<S828>/Add1'
   */
  MCU115LossCanNetInstFlt_flg = (qY >= rtu_KeepTime_ms);

  /* Switch: '<S828>/Switch1' */
  if (rtu_Enable) {
    /* Update for UnitDelay: '<S828>/UnitDelay' incorporates:
     *  Sum: '<S828>/Add1'
     */
    localDW->UnitDelay_DSTATE = qY;
  } else {
    /* Update for UnitDelay: '<S828>/UnitDelay' incorporates:
     *  Constant: '<S828>/Constant1'
     */
    localDW->UnitDelay_DSTATE = 0U;
  }

  /* End of Switch: '<S828>/Switch1' */

  /* Update for Delay: '<S828>/Delay' */
  localDW->Delay_DSTATE = rtu_Enable;
}

/* Output and update for atomic system: '<S825>/DHP_systemtick_Timer' */
void DHP_model_DHP_systemtick_Timer_j(boolean_T rtu_Enable, uint8_T
  rtu_DeltaSystemTick_ms, uint16_T rtu_KeepTime_ms,
  DW_DHP_systemtick_Timer_DHP_model_a5_T *localDW)
{
  uint32_T qY;
  uint8_T rtu_Enable_0;

  /* Switch: '<S829>/Switch' incorporates:
   *  Constant: '<S829>/Constant'
   *  Logic: '<S829>/Logical Operator'
   *  Logic: '<S829>/Logical Operator1'
   *  UnitDelay: '<S829>/UnitDelay1'
   */
  if (rtu_Enable && (!MCU515LossCanNetInstFlt_flg)) {
    /* Switch: '<S829>/Switch2' incorporates:
     *  Constant: '<S829>/Constant2'
     *  Delay: '<S829>/Delay'
     *  Logic: '<S829>/Logical Operator2'
     */
    if (!localDW->Delay_DSTATE) {
      rtu_Enable_0 = 0U;
    } else {
      rtu_Enable_0 = rtu_DeltaSystemTick_ms;
    }

    /* End of Switch: '<S829>/Switch2' */
  } else {
    rtu_Enable_0 = 0U;
  }

  /* End of Switch: '<S829>/Switch' */

  /* Sum: '<S829>/Add1' incorporates:
   *  UnitDelay: '<S829>/UnitDelay'
   */
  qY = localDW->UnitDelay_DSTATE + rtu_Enable_0;
  if (qY < localDW->UnitDelay_DSTATE) {
    qY = MAX_uint32_T;
  }

  /* RelationalOperator: '<S829>/Relational Operator' incorporates:
   *  Sum: '<S829>/Add1'
   */
  MCU515LossCanNetInstFlt_flg = (qY >= rtu_KeepTime_ms);

  /* Switch: '<S829>/Switch1' */
  if (rtu_Enable) {
    /* Update for UnitDelay: '<S829>/UnitDelay' incorporates:
     *  Sum: '<S829>/Add1'
     */
    localDW->UnitDelay_DSTATE = qY;
  } else {
    /* Update for UnitDelay: '<S829>/UnitDelay' incorporates:
     *  Constant: '<S829>/Constant1'
     */
    localDW->UnitDelay_DSTATE = 0U;
  }

  /* End of Switch: '<S829>/Switch1' */

  /* Update for Delay: '<S829>/Delay' */
  localDW->Delay_DSTATE = rtu_Enable;
}

/* Output and update for atomic system: '<S826>/DHP_systemtick_Timer' */
void DHP_model_DHP_systemtick_Timer_h(boolean_T rtu_Enable, uint8_T
  rtu_DeltaSystemTick_ms, uint16_T rtu_KeepTime_ms,
  DW_DHP_systemtick_Timer_DHP_model_o_T *localDW)
{
  uint32_T qY;
  uint8_T rtu_Enable_0;

  /* Switch: '<S830>/Switch' incorporates:
   *  Constant: '<S830>/Constant'
   *  Logic: '<S830>/Logical Operator'
   *  Logic: '<S830>/Logical Operator1'
   *  UnitDelay: '<S830>/UnitDelay1'
   */
  if (rtu_Enable && (!MCU215LossCanNetInstFlt_flg)) {
    /* Switch: '<S830>/Switch2' incorporates:
     *  Constant: '<S830>/Constant2'
     *  Delay: '<S830>/Delay'
     *  Logic: '<S830>/Logical Operator2'
     */
    if (!localDW->Delay_DSTATE) {
      rtu_Enable_0 = 0U;
    } else {
      rtu_Enable_0 = rtu_DeltaSystemTick_ms;
    }

    /* End of Switch: '<S830>/Switch2' */
  } else {
    rtu_Enable_0 = 0U;
  }

  /* End of Switch: '<S830>/Switch' */

  /* Sum: '<S830>/Add1' incorporates:
   *  UnitDelay: '<S830>/UnitDelay'
   */
  qY = localDW->UnitDelay_DSTATE + rtu_Enable_0;
  if (qY < localDW->UnitDelay_DSTATE) {
    qY = MAX_uint32_T;
  }

  /* RelationalOperator: '<S830>/Relational Operator' incorporates:
   *  Sum: '<S830>/Add1'
   */
  MCU215LossCanNetInstFlt_flg = (qY >= rtu_KeepTime_ms);

  /* Switch: '<S830>/Switch1' */
  if (rtu_Enable) {
    /* Update for UnitDelay: '<S830>/UnitDelay' incorporates:
     *  Sum: '<S830>/Add1'
     */
    localDW->UnitDelay_DSTATE = qY;
  } else {
    /* Update for UnitDelay: '<S830>/UnitDelay' incorporates:
     *  Constant: '<S830>/Constant1'
     */
    localDW->UnitDelay_DSTATE = 0U;
  }

  /* End of Switch: '<S830>/Switch1' */

  /* Update for Delay: '<S830>/Delay' */
  localDW->Delay_DSTATE = rtu_Enable;
}

/* Output and update for atomic system: '<S835>/DHP_systemtick_Timer' */
void DHP_model_DHP_systemtick_Timer_p0(boolean_T rtu_Enable, uint8_T
  rtu_DeltaSystemTick_ms, uint16_T rtu_KeepTime_ms,
  DW_DHP_systemtick_Timer_DHP_model_h_T *localDW)
{
  uint32_T qY;
  uint8_T rtu_Enable_0;

  /* Switch: '<S840>/Switch' incorporates:
   *  Constant: '<S840>/Constant'
   *  Logic: '<S840>/Logical Operator'
   *  Logic: '<S840>/Logical Operator1'
   *  UnitDelay: '<S840>/UnitDelay1'
   */
  if (rtu_Enable && (!VDHP_OBCLossCanNetInstFlt_flg)) {
    /* Switch: '<S840>/Switch2' incorporates:
     *  Constant: '<S840>/Constant2'
     *  Delay: '<S840>/Delay'
     *  Logic: '<S840>/Logical Operator2'
     */
    if (!localDW->Delay_DSTATE) {
      rtu_Enable_0 = 0U;
    } else {
      rtu_Enable_0 = rtu_DeltaSystemTick_ms;
    }

    /* End of Switch: '<S840>/Switch2' */
  } else {
    rtu_Enable_0 = 0U;
  }

  /* End of Switch: '<S840>/Switch' */

  /* Sum: '<S840>/Add1' incorporates:
   *  UnitDelay: '<S840>/UnitDelay'
   */
  qY = localDW->UnitDelay_DSTATE + rtu_Enable_0;
  if (qY < localDW->UnitDelay_DSTATE) {
    qY = MAX_uint32_T;
  }

  /* RelationalOperator: '<S840>/Relational Operator' incorporates:
   *  Sum: '<S840>/Add1'
   */
  VDHP_OBCLossCanNetInstFlt_flg = (qY >= rtu_KeepTime_ms);

  /* Switch: '<S840>/Switch1' */
  if (rtu_Enable) {
    /* Update for UnitDelay: '<S840>/UnitDelay' incorporates:
     *  Sum: '<S840>/Add1'
     */
    localDW->UnitDelay_DSTATE = qY;
  } else {
    /* Update for UnitDelay: '<S840>/UnitDelay' incorporates:
     *  Constant: '<S840>/Constant1'
     */
    localDW->UnitDelay_DSTATE = 0U;
  }

  /* End of Switch: '<S840>/Switch1' */

  /* Update for Delay: '<S840>/Delay' */
  localDW->Delay_DSTATE = rtu_Enable;
}

/* Output and update for atomic system: '<S760>/DHP_systemtick_Timer' */
void DHP_model_DHP_systemtick_Timer_i(boolean_T rtu_Enable, uint8_T
  rtu_DeltaSystemTick_ms, uint16_T rtu_KeepTime_ms,
  DW_DHP_systemtick_Timer_DHP_model_op_T *localDW)
{
  uint32_T qY;
  uint8_T rtu_Enable_0;

  /* Switch: '<S842>/Switch' incorporates:
   *  Constant: '<S842>/Constant'
   *  Logic: '<S842>/Logical Operator'
   *  Logic: '<S842>/Logical Operator1'
   *  UnitDelay: '<S842>/UnitDelay1'
   */
  if (rtu_Enable && (!localDW->UnitDelay1_DSTATE)) {
    /* Switch: '<S842>/Switch2' incorporates:
     *  Constant: '<S842>/Constant2'
     *  Delay: '<S842>/Delay'
     *  Logic: '<S842>/Logical Operator2'
     */
    if (!localDW->Delay_DSTATE) {
      rtu_Enable_0 = 0U;
    } else {
      rtu_Enable_0 = rtu_DeltaSystemTick_ms;
    }

    /* End of Switch: '<S842>/Switch2' */
  } else {
    rtu_Enable_0 = 0U;
  }

  /* End of Switch: '<S842>/Switch' */

  /* Sum: '<S842>/Add1' incorporates:
   *  UnitDelay: '<S842>/UnitDelay'
   */
  qY = localDW->UnitDelay_DSTATE + rtu_Enable_0;
  if (qY < localDW->UnitDelay_DSTATE) {
    qY = MAX_uint32_T;
  }

  /* RelationalOperator: '<S842>/Relational Operator' incorporates:
   *  Sum: '<S842>/Add1'
   */
  VDHP_TBOXLossCanNetInstFlt_flg = (qY >= rtu_KeepTime_ms);

  /* Switch: '<S842>/Switch1' */
  if (rtu_Enable) {
    /* Update for UnitDelay: '<S842>/UnitDelay' incorporates:
     *  Sum: '<S842>/Add1'
     */
    localDW->UnitDelay_DSTATE = qY;
  } else {
    /* Update for UnitDelay: '<S842>/UnitDelay' incorporates:
     *  Constant: '<S842>/Constant1'
     */
    localDW->UnitDelay_DSTATE = 0U;
  }

  /* End of Switch: '<S842>/Switch1' */

  /* Update for Delay: '<S842>/Delay' */
  localDW->Delay_DSTATE = rtu_Enable;

  /* Update for UnitDelay: '<S842>/UnitDelay1' */
  localDW->UnitDelay1_DSTATE = VDHP_TBOXLossCanNetInstFlt_flg;
}

/* Output and update for atomic system: '<S843>/DHP_systemtick_Timer' */
void DHP_model_DHP_systemtick_Timer_ph(boolean_T rtu_Enable, uint8_T
  rtu_DeltaSystemTick_ms, uint16_T rtu_KeepTime_ms,
  DW_DHP_systemtick_Timer_DHP_model_ga_T *localDW)
{
  uint32_T qY;
  uint8_T rtu_Enable_0;

  /* Switch: '<S844>/Switch' incorporates:
   *  Constant: '<S844>/Constant'
   *  Logic: '<S844>/Logical Operator'
   *  Logic: '<S844>/Logical Operator1'
   *  UnitDelay: '<S844>/UnitDelay1'
   */
  if (rtu_Enable && (!localDW->UnitDelay1_DSTATE)) {
    /* Switch: '<S844>/Switch2' incorporates:
     *  Constant: '<S844>/Constant2'
     *  Delay: '<S844>/Delay'
     *  Logic: '<S844>/Logical Operator2'
     */
    if (!localDW->Delay_DSTATE) {
      rtu_Enable_0 = 0U;
    } else {
      rtu_Enable_0 = rtu_DeltaSystemTick_ms;
    }

    /* End of Switch: '<S844>/Switch2' */
  } else {
    rtu_Enable_0 = 0U;
  }

  /* End of Switch: '<S844>/Switch' */

  /* Sum: '<S844>/Add1' incorporates:
   *  UnitDelay: '<S844>/UnitDelay'
   */
  qY = localDW->UnitDelay_DSTATE + rtu_Enable_0;
  if (qY < localDW->UnitDelay_DSTATE) {
    qY = MAX_uint32_T;
  }

  /* RelationalOperator: '<S844>/Relational Operator' incorporates:
   *  Sum: '<S844>/Add1'
   */
  VDHP_TMSLossCanNetInstFlt_flg = (qY >= rtu_KeepTime_ms);

  /* Switch: '<S844>/Switch1' */
  if (rtu_Enable) {
    /* Update for UnitDelay: '<S844>/UnitDelay' incorporates:
     *  Sum: '<S844>/Add1'
     */
    localDW->UnitDelay_DSTATE = qY;
  } else {
    /* Update for UnitDelay: '<S844>/UnitDelay' incorporates:
     *  Constant: '<S844>/Constant1'
     */
    localDW->UnitDelay_DSTATE = 0U;
  }

  /* End of Switch: '<S844>/Switch1' */

  /* Update for Delay: '<S844>/Delay' */
  localDW->Delay_DSTATE = rtu_Enable;

  /* Update for UnitDelay: '<S844>/UnitDelay1' */
  localDW->UnitDelay1_DSTATE = VDHP_TMSLossCanNetInstFlt_flg;
}

/* Output and update for atomic system: '<S763>/DHP_systemtick_Timer' */
void DHP_model_DHP_systemtick_Timer_ho(boolean_T rtu_Enable, uint8_T
  rtu_DeltaSystemTick_ms, uint16_T rtu_KeepTime_ms,
  DW_DHP_systemtick_Timer_DHP_model_c_T *localDW)
{
  uint32_T qY;
  uint8_T rtu_Enable_0;

  /* Switch: '<S846>/Switch' incorporates:
   *  Constant: '<S846>/Constant'
   *  Logic: '<S846>/Logical Operator'
   *  Logic: '<S846>/Logical Operator1'
   *  UnitDelay: '<S846>/UnitDelay1'
   */
  if (rtu_Enable && (!localDW->UnitDelay1_DSTATE)) {
    /* Switch: '<S846>/Switch2' incorporates:
     *  Constant: '<S846>/Constant2'
     *  Delay: '<S846>/Delay'
     *  Logic: '<S846>/Logical Operator2'
     */
    if (!localDW->Delay_DSTATE) {
      rtu_Enable_0 = 0U;
    } else {
      rtu_Enable_0 = rtu_DeltaSystemTick_ms;
    }

    /* End of Switch: '<S846>/Switch2' */
  } else {
    rtu_Enable_0 = 0U;
  }

  /* End of Switch: '<S846>/Switch' */

  /* Sum: '<S846>/Add1' incorporates:
   *  UnitDelay: '<S846>/UnitDelay'
   */
  qY = localDW->UnitDelay_DSTATE + rtu_Enable_0;
  if (qY < localDW->UnitDelay_DSTATE) {
    qY = MAX_uint32_T;
  }

  /* RelationalOperator: '<S846>/Relational Operator' incorporates:
   *  Sum: '<S846>/Add1'
   */
  VDHP_XBSLossCanNetInstFlt_flg = (qY >= rtu_KeepTime_ms);

  /* Switch: '<S846>/Switch1' */
  if (rtu_Enable) {
    /* Update for UnitDelay: '<S846>/UnitDelay' incorporates:
     *  Sum: '<S846>/Add1'
     */
    localDW->UnitDelay_DSTATE = qY;
  } else {
    /* Update for UnitDelay: '<S846>/UnitDelay' incorporates:
     *  Constant: '<S846>/Constant1'
     */
    localDW->UnitDelay_DSTATE = 0U;
  }

  /* End of Switch: '<S846>/Switch1' */

  /* Update for Delay: '<S846>/Delay' */
  localDW->Delay_DSTATE = rtu_Enable;

  /* Update for UnitDelay: '<S846>/UnitDelay1' */
  localDW->UnitDelay1_DSTATE = VDHP_XBSLossCanNetInstFlt_flg;
}

/* Output and update for atomic system: '<S1105>/DHP_systemtick_Timer' */
void DHP_model_DHP_systemtick_Timer_gq(boolean_T rtu_Enable, uint8_T
  rtu_DeltaSystemTick_ms, uint16_T rtu_KeepTime_ms,
  DW_DHP_systemtick_Timer_DHP_model_an_T *localDW)
{
  uint32_T qY;
  uint8_T rtu_Enable_0;

  /* Switch: '<S1114>/Switch' incorporates:
   *  Constant: '<S1114>/Constant'
   *  Logic: '<S1114>/Logical Operator'
   *  Logic: '<S1114>/Logical Operator1'
   *  UnitDelay: '<S1114>/UnitDelay1'
   */
  if (rtu_Enable && (!VDHP_HVPowerUpDelay2SWork_Flg)) {
    /* Switch: '<S1114>/Switch2' incorporates:
     *  Constant: '<S1114>/Constant2'
     *  Delay: '<S1114>/Delay'
     *  Logic: '<S1114>/Logical Operator2'
     */
    if (!localDW->Delay_DSTATE) {
      rtu_Enable_0 = 0U;
    } else {
      rtu_Enable_0 = rtu_DeltaSystemTick_ms;
    }

    /* End of Switch: '<S1114>/Switch2' */
  } else {
    rtu_Enable_0 = 0U;
  }

  /* End of Switch: '<S1114>/Switch' */

  /* Sum: '<S1114>/Add1' incorporates:
   *  UnitDelay: '<S1114>/UnitDelay'
   */
  qY = localDW->UnitDelay_DSTATE + rtu_Enable_0;
  if (qY < localDW->UnitDelay_DSTATE) {
    qY = MAX_uint32_T;
  }

  /* RelationalOperator: '<S1114>/Relational Operator' incorporates:
   *  Sum: '<S1114>/Add1'
   */
  VDHP_HVPowerUpDelay2SWork_Flg = (qY >= rtu_KeepTime_ms);

  /* Switch: '<S1114>/Switch1' */
  if (rtu_Enable) {
    /* Update for UnitDelay: '<S1114>/UnitDelay' incorporates:
     *  Sum: '<S1114>/Add1'
     */
    localDW->UnitDelay_DSTATE = qY;
  } else {
    /* Update for UnitDelay: '<S1114>/UnitDelay' incorporates:
     *  Constant: '<S1114>/Constant1'
     */
    localDW->UnitDelay_DSTATE = 0U;
  }

  /* End of Switch: '<S1114>/Switch1' */

  /* Update for Delay: '<S1114>/Delay' */
  localDW->Delay_DSTATE = rtu_Enable;
}

/* Output and update for atomic system: '<S1106>/DHP_systemtick_Timer' */
void DHP_model_DHP_systemtick_Timer_na(boolean_T rtu_Enable, uint8_T
  rtu_DeltaSystemTick_ms, uint16_T rtu_KeepTime_ms,
  DW_DHP_systemtick_Timer_DHP_model_l_T *localDW)
{
  uint32_T qY;
  uint8_T rtu_Enable_0;

  /* Switch: '<S1115>/Switch' incorporates:
   *  Constant: '<S1115>/Constant'
   *  Logic: '<S1115>/Logical Operator'
   *  Logic: '<S1115>/Logical Operator1'
   *  UnitDelay: '<S1115>/UnitDelay1'
   */
  if (rtu_Enable && (!VDHP_BMSWakeupWork_Flg)) {
    /* Switch: '<S1115>/Switch2' incorporates:
     *  Constant: '<S1115>/Constant2'
     *  Delay: '<S1115>/Delay'
     *  Logic: '<S1115>/Logical Operator2'
     */
    if (!localDW->Delay_DSTATE) {
      rtu_Enable_0 = 0U;
    } else {
      rtu_Enable_0 = rtu_DeltaSystemTick_ms;
    }

    /* End of Switch: '<S1115>/Switch2' */
  } else {
    rtu_Enable_0 = 0U;
  }

  /* End of Switch: '<S1115>/Switch' */

  /* Sum: '<S1115>/Add1' incorporates:
   *  UnitDelay: '<S1115>/UnitDelay'
   */
  qY = localDW->UnitDelay_DSTATE + rtu_Enable_0;
  if (qY < localDW->UnitDelay_DSTATE) {
    qY = MAX_uint32_T;
  }

  /* RelationalOperator: '<S1115>/Relational Operator' incorporates:
   *  Sum: '<S1115>/Add1'
   */
  VDHP_BMSWakeupWork_Flg = (qY >= rtu_KeepTime_ms);

  /* Switch: '<S1115>/Switch1' */
  if (rtu_Enable) {
    /* Update for UnitDelay: '<S1115>/UnitDelay' incorporates:
     *  Sum: '<S1115>/Add1'
     */
    localDW->UnitDelay_DSTATE = qY;
  } else {
    /* Update for UnitDelay: '<S1115>/UnitDelay' incorporates:
     *  Constant: '<S1115>/Constant1'
     */
    localDW->UnitDelay_DSTATE = 0U;
  }

  /* End of Switch: '<S1115>/Switch1' */

  /* Update for Delay: '<S1115>/Delay' */
  localDW->Delay_DSTATE = rtu_Enable;
}

/* Output and update for atomic system: '<S1111>/DHP_systemtick_Timer' */
void DHP_model_DHP_systemtick_Timer_fy(boolean_T rtu_Enable, uint8_T
  rtu_DeltaSystemTick_ms, uint16_T rtu_KeepTime_ms,
  DW_DHP_systemtick_Timer_DHP_model_ny_T *localDW)
{
  uint32_T qY;
  uint8_T rtu_Enable_0;

  /* Switch: '<S1120>/Switch' incorporates:
   *  Constant: '<S1120>/Constant'
   *  Logic: '<S1120>/Logical Operator'
   *  Logic: '<S1120>/Logical Operator1'
   *  UnitDelay: '<S1120>/UnitDelay1'
   */
  if (rtu_Enable && (!VDHP_VCUPowerUpDelay2SWork_Flg)) {
    /* Switch: '<S1120>/Switch2' incorporates:
     *  Constant: '<S1120>/Constant2'
     *  Delay: '<S1120>/Delay'
     *  Logic: '<S1120>/Logical Operator2'
     */
    if (!localDW->Delay_DSTATE) {
      rtu_Enable_0 = 0U;
    } else {
      rtu_Enable_0 = rtu_DeltaSystemTick_ms;
    }

    /* End of Switch: '<S1120>/Switch2' */
  } else {
    rtu_Enable_0 = 0U;
  }

  /* End of Switch: '<S1120>/Switch' */

  /* Sum: '<S1120>/Add1' incorporates:
   *  UnitDelay: '<S1120>/UnitDelay'
   */
  qY = localDW->UnitDelay_DSTATE + rtu_Enable_0;
  if (qY < localDW->UnitDelay_DSTATE) {
    qY = MAX_uint32_T;
  }

  /* RelationalOperator: '<S1120>/Relational Operator' incorporates:
   *  Sum: '<S1120>/Add1'
   */
  VDHP_VCUPowerUpDelay2SWork_Flg = (qY >= rtu_KeepTime_ms);

  /* Switch: '<S1120>/Switch1' */
  if (rtu_Enable) {
    /* Update for UnitDelay: '<S1120>/UnitDelay' incorporates:
     *  Sum: '<S1120>/Add1'
     */
    localDW->UnitDelay_DSTATE = qY;
  } else {
    /* Update for UnitDelay: '<S1120>/UnitDelay' incorporates:
     *  Constant: '<S1120>/Constant1'
     */
    localDW->UnitDelay_DSTATE = 0U;
  }

  /* End of Switch: '<S1120>/Switch1' */

  /* Update for Delay: '<S1120>/Delay' */
  localDW->Delay_DSTATE = rtu_Enable;
}

/* Output and update for atomic system: '<S1112>/DHP_systemtick_Timer' */
void DHP_model_DHP_systemtick_Timer_oz(boolean_T rtu_Enable, uint8_T
  rtu_DeltaSystemTick_ms, uint16_T rtu_KeepTime_ms,
  DW_DHP_systemtick_Timer_DHP_model_k_T *localDW)
{
  uint32_T qY;
  uint8_T rtu_Enable_0;

  /* Switch: '<S1121>/Switch' incorporates:
   *  Constant: '<S1121>/Constant'
   *  Logic: '<S1121>/Logical Operator'
   *  Logic: '<S1121>/Logical Operator1'
   *  UnitDelay: '<S1121>/UnitDelay1'
   */
  if (rtu_Enable && (!VDHP_MCUWakeupWork_Flg)) {
    /* Switch: '<S1121>/Switch2' incorporates:
     *  Constant: '<S1121>/Constant2'
     *  Delay: '<S1121>/Delay'
     *  Logic: '<S1121>/Logical Operator2'
     */
    if (!localDW->Delay_DSTATE) {
      rtu_Enable_0 = 0U;
    } else {
      rtu_Enable_0 = rtu_DeltaSystemTick_ms;
    }

    /* End of Switch: '<S1121>/Switch2' */
  } else {
    rtu_Enable_0 = 0U;
  }

  /* End of Switch: '<S1121>/Switch' */

  /* Sum: '<S1121>/Add1' incorporates:
   *  UnitDelay: '<S1121>/UnitDelay'
   */
  qY = localDW->UnitDelay_DSTATE + rtu_Enable_0;
  if (qY < localDW->UnitDelay_DSTATE) {
    qY = MAX_uint32_T;
  }

  /* RelationalOperator: '<S1121>/Relational Operator' incorporates:
   *  Sum: '<S1121>/Add1'
   */
  VDHP_MCUWakeupWork_Flg = (qY >= rtu_KeepTime_ms);

  /* Switch: '<S1121>/Switch1' */
  if (rtu_Enable) {
    /* Update for UnitDelay: '<S1121>/UnitDelay' incorporates:
     *  Sum: '<S1121>/Add1'
     */
    localDW->UnitDelay_DSTATE = qY;
  } else {
    /* Update for UnitDelay: '<S1121>/UnitDelay' incorporates:
     *  Constant: '<S1121>/Constant1'
     */
    localDW->UnitDelay_DSTATE = 0U;
  }

  /* End of Switch: '<S1121>/Switch1' */

  /* Update for Delay: '<S1121>/Delay' */
  localDW->Delay_DSTATE = rtu_Enable;
}

/* Output and update for atomic system: '<S1113>/DHP_systemtick_Timer' */
void DHP_model_DHP_systemtick_Timer_p3(boolean_T rtu_Enable, uint8_T
  rtu_DeltaSystemTick_ms, uint16_T rtu_KeepTime_ms,
  DW_DHP_systemtick_Timer_DHP_model_b_T *localDW)
{
  uint32_T qY;
  uint8_T rtu_Enable_0;

  /* Switch: '<S1122>/Switch' incorporates:
   *  Constant: '<S1122>/Constant'
   *  Logic: '<S1122>/Logical Operator'
   *  Logic: '<S1122>/Logical Operator1'
   *  UnitDelay: '<S1122>/UnitDelay1'
   */
  if (rtu_Enable && (!VDHP_TestWorkDelay4s_Flg)) {
    /* Switch: '<S1122>/Switch2' incorporates:
     *  Constant: '<S1122>/Constant2'
     *  Delay: '<S1122>/Delay'
     *  Logic: '<S1122>/Logical Operator2'
     */
    if (!localDW->Delay_DSTATE) {
      rtu_Enable_0 = 0U;
    } else {
      rtu_Enable_0 = rtu_DeltaSystemTick_ms;
    }

    /* End of Switch: '<S1122>/Switch2' */
  } else {
    rtu_Enable_0 = 0U;
  }

  /* End of Switch: '<S1122>/Switch' */

  /* Sum: '<S1122>/Add1' incorporates:
   *  UnitDelay: '<S1122>/UnitDelay'
   */
  qY = localDW->UnitDelay_DSTATE + rtu_Enable_0;
  if (qY < localDW->UnitDelay_DSTATE) {
    qY = MAX_uint32_T;
  }

  /* RelationalOperator: '<S1122>/Relational Operator' incorporates:
   *  Sum: '<S1122>/Add1'
   */
  VDHP_TestWorkDelay4s_Flg = (qY >= rtu_KeepTime_ms);

  /* Switch: '<S1122>/Switch1' */
  if (rtu_Enable) {
    /* Update for UnitDelay: '<S1122>/UnitDelay' incorporates:
     *  Sum: '<S1122>/Add1'
     */
    localDW->UnitDelay_DSTATE = qY;
  } else {
    /* Update for UnitDelay: '<S1122>/UnitDelay' incorporates:
     *  Constant: '<S1122>/Constant1'
     */
    localDW->UnitDelay_DSTATE = 0U;
  }

  /* End of Switch: '<S1122>/Switch1' */

  /* Update for Delay: '<S1122>/Delay' */
  localDW->Delay_DSTATE = rtu_Enable;
}

/* Output and update for atomic system: '<S1123>/DHP_systemtick_Timer' */
void DHP_model_DHP_systemtick_Timer_k0(boolean_T rtu_Enable, uint8_T
  rtu_DeltaSystemTick_ms, uint16_T rtu_KeepTime_ms,
  DW_DHP_systemtick_Timer_DHP_model_p_T *localDW)
{
  uint32_T qY;
  uint8_T rtu_Enable_0;

  /* Switch: '<S1138>/Switch' incorporates:
   *  Constant: '<S1138>/Constant'
   *  Logic: '<S1138>/Logical Operator'
   *  Logic: '<S1138>/Logical Operator1'
   *  UnitDelay: '<S1138>/UnitDelay1'
   */
  if (rtu_Enable && (!VDHP_BMS_OverUFlt_flg)) {
    /* Switch: '<S1138>/Switch2' incorporates:
     *  Constant: '<S1138>/Constant2'
     *  Delay: '<S1138>/Delay'
     *  Logic: '<S1138>/Logical Operator2'
     */
    if (!localDW->Delay_DSTATE) {
      rtu_Enable_0 = 0U;
    } else {
      rtu_Enable_0 = rtu_DeltaSystemTick_ms;
    }

    /* End of Switch: '<S1138>/Switch2' */
  } else {
    rtu_Enable_0 = 0U;
  }

  /* End of Switch: '<S1138>/Switch' */

  /* Sum: '<S1138>/Add1' incorporates:
   *  UnitDelay: '<S1138>/UnitDelay'
   */
  qY = localDW->UnitDelay_DSTATE + rtu_Enable_0;
  if (qY < localDW->UnitDelay_DSTATE) {
    qY = MAX_uint32_T;
  }

  /* RelationalOperator: '<S1138>/Relational Operator' incorporates:
   *  Sum: '<S1138>/Add1'
   */
  VDHP_BMS_OverUFlt_flg = (qY >= rtu_KeepTime_ms);

  /* Switch: '<S1138>/Switch1' */
  if (rtu_Enable) {
    /* Update for UnitDelay: '<S1138>/UnitDelay' incorporates:
     *  Sum: '<S1138>/Add1'
     */
    localDW->UnitDelay_DSTATE = qY;
  } else {
    /* Update for UnitDelay: '<S1138>/UnitDelay' incorporates:
     *  Constant: '<S1138>/Constant1'
     */
    localDW->UnitDelay_DSTATE = 0U;
  }

  /* End of Switch: '<S1138>/Switch1' */

  /* Update for Delay: '<S1138>/Delay' */
  localDW->Delay_DSTATE = rtu_Enable;
}

/* Output and update for atomic system: '<S1123>/DHP_systemtick_Timer1' */
void DHP_model_DHP_systemtick_Timer1_f(boolean_T rtu_Enable, uint8_T
  rtu_DeltaSystemTick_ms, uint16_T rtu_KeepTime_ms,
  DW_DHP_systemtick_Timer_DHP_model_h3_T *localDW)
{
  uint32_T qY;
  uint8_T rtu_Enable_0;

  /* Switch: '<S1139>/Switch' incorporates:
   *  Constant: '<S1139>/Constant'
   *  Logic: '<S1139>/Logical Operator'
   *  Logic: '<S1139>/Logical Operator1'
   *  UnitDelay: '<S1139>/UnitDelay1'
   */
  if (rtu_Enable && (!VDHP_BMS_UnderUFlt_flg)) {
    /* Switch: '<S1139>/Switch2' incorporates:
     *  Constant: '<S1139>/Constant2'
     *  Delay: '<S1139>/Delay'
     *  Logic: '<S1139>/Logical Operator2'
     */
    if (!localDW->Delay_DSTATE) {
      rtu_Enable_0 = 0U;
    } else {
      rtu_Enable_0 = rtu_DeltaSystemTick_ms;
    }

    /* End of Switch: '<S1139>/Switch2' */
  } else {
    rtu_Enable_0 = 0U;
  }

  /* End of Switch: '<S1139>/Switch' */

  /* Sum: '<S1139>/Add1' incorporates:
   *  UnitDelay: '<S1139>/UnitDelay'
   */
  qY = localDW->UnitDelay_DSTATE + rtu_Enable_0;
  if (qY < localDW->UnitDelay_DSTATE) {
    qY = MAX_uint32_T;
  }

  /* RelationalOperator: '<S1139>/Relational Operator' incorporates:
   *  Sum: '<S1139>/Add1'
   */
  VDHP_BMS_UnderUFlt_flg = (qY >= rtu_KeepTime_ms);

  /* Switch: '<S1139>/Switch1' */
  if (rtu_Enable) {
    /* Update for UnitDelay: '<S1139>/UnitDelay' incorporates:
     *  Sum: '<S1139>/Add1'
     */
    localDW->UnitDelay_DSTATE = qY;
  } else {
    /* Update for UnitDelay: '<S1139>/UnitDelay' incorporates:
     *  Constant: '<S1139>/Constant1'
     */
    localDW->UnitDelay_DSTATE = 0U;
  }

  /* End of Switch: '<S1139>/Switch1' */

  /* Update for Delay: '<S1139>/Delay' */
  localDW->Delay_DSTATE = rtu_Enable;
}

/* Output and update for atomic system: '<S1123>/DHP_systemtick_Timer2' */
void DHP_model_DHP_systemtick_Timer2(boolean_T rtu_Enable, uint8_T
  rtu_DeltaSystemTick_ms, uint16_T rtu_KeepTime_ms,
  DW_DHP_systemtick_Timer_DHP_model_mf_T *localDW)
{
  uint32_T qY;
  uint8_T rtu_Enable_0;

  /* Switch: '<S1140>/Switch' incorporates:
   *  Constant: '<S1140>/Constant'
   *  Logic: '<S1140>/Logical Operator'
   *  Logic: '<S1140>/Logical Operator1'
   *  UnitDelay: '<S1140>/UnitDelay1'
   */
  if (rtu_Enable && (!VDHP_BMSCell_OverUFlt_flg)) {
    /* Switch: '<S1140>/Switch2' incorporates:
     *  Constant: '<S1140>/Constant2'
     *  Delay: '<S1140>/Delay'
     *  Logic: '<S1140>/Logical Operator2'
     */
    if (!localDW->Delay_DSTATE) {
      rtu_Enable_0 = 0U;
    } else {
      rtu_Enable_0 = rtu_DeltaSystemTick_ms;
    }

    /* End of Switch: '<S1140>/Switch2' */
  } else {
    rtu_Enable_0 = 0U;
  }

  /* End of Switch: '<S1140>/Switch' */

  /* Sum: '<S1140>/Add1' incorporates:
   *  UnitDelay: '<S1140>/UnitDelay'
   */
  qY = localDW->UnitDelay_DSTATE + rtu_Enable_0;
  if (qY < localDW->UnitDelay_DSTATE) {
    qY = MAX_uint32_T;
  }

  /* RelationalOperator: '<S1140>/Relational Operator' incorporates:
   *  Sum: '<S1140>/Add1'
   */
  VDHP_BMSCell_OverUFlt_flg = (qY >= rtu_KeepTime_ms);

  /* Switch: '<S1140>/Switch1' */
  if (rtu_Enable) {
    /* Update for UnitDelay: '<S1140>/UnitDelay' incorporates:
     *  Sum: '<S1140>/Add1'
     */
    localDW->UnitDelay_DSTATE = qY;
  } else {
    /* Update for UnitDelay: '<S1140>/UnitDelay' incorporates:
     *  Constant: '<S1140>/Constant1'
     */
    localDW->UnitDelay_DSTATE = 0U;
  }

  /* End of Switch: '<S1140>/Switch1' */

  /* Update for Delay: '<S1140>/Delay' */
  localDW->Delay_DSTATE = rtu_Enable;
}

/* Output and update for atomic system: '<S1123>/DHP_systemtick_Timer3' */
void DHP_model_DHP_systemtick_Timer3(boolean_T rtu_Enable, uint8_T
  rtu_DeltaSystemTick_ms, uint16_T rtu_KeepTime_ms,
  DW_DHP_systemtick_Timer_DHP_model_ac_T *localDW)
{
  uint32_T qY;
  uint8_T rtu_Enable_0;

  /* Switch: '<S1141>/Switch' incorporates:
   *  Constant: '<S1141>/Constant'
   *  Logic: '<S1141>/Logical Operator'
   *  Logic: '<S1141>/Logical Operator1'
   *  UnitDelay: '<S1141>/UnitDelay1'
   */
  if (rtu_Enable && (!VDHP_BMSCell_UnderUFlt_flg)) {
    /* Switch: '<S1141>/Switch2' incorporates:
     *  Constant: '<S1141>/Constant2'
     *  Delay: '<S1141>/Delay'
     *  Logic: '<S1141>/Logical Operator2'
     */
    if (!localDW->Delay_DSTATE) {
      rtu_Enable_0 = 0U;
    } else {
      rtu_Enable_0 = rtu_DeltaSystemTick_ms;
    }

    /* End of Switch: '<S1141>/Switch2' */
  } else {
    rtu_Enable_0 = 0U;
  }

  /* End of Switch: '<S1141>/Switch' */

  /* Sum: '<S1141>/Add1' incorporates:
   *  UnitDelay: '<S1141>/UnitDelay'
   */
  qY = localDW->UnitDelay_DSTATE + rtu_Enable_0;
  if (qY < localDW->UnitDelay_DSTATE) {
    qY = MAX_uint32_T;
  }

  /* RelationalOperator: '<S1141>/Relational Operator' incorporates:
   *  Sum: '<S1141>/Add1'
   */
  VDHP_BMSCell_UnderUFlt_flg = (qY >= rtu_KeepTime_ms);

  /* Switch: '<S1141>/Switch1' */
  if (rtu_Enable) {
    /* Update for UnitDelay: '<S1141>/UnitDelay' incorporates:
     *  Sum: '<S1141>/Add1'
     */
    localDW->UnitDelay_DSTATE = qY;
  } else {
    /* Update for UnitDelay: '<S1141>/UnitDelay' incorporates:
     *  Constant: '<S1141>/Constant1'
     */
    localDW->UnitDelay_DSTATE = 0U;
  }

  /* End of Switch: '<S1141>/Switch1' */

  /* Update for Delay: '<S1141>/Delay' */
  localDW->Delay_DSTATE = rtu_Enable;
}

/* Output and update for atomic system: '<S1123>/DHP_systemtick_Timer4' */
void DHP_model_DHP_systemtick_Timer4(boolean_T rtu_Enable, uint8_T
  rtu_DeltaSystemTick_ms, uint16_T rtu_KeepTime_ms,
  DW_DHP_systemtick_Timer_DHP_model_gc_T *localDW)
{
  uint32_T qY;
  uint8_T rtu_Enable_0;

  /* Switch: '<S1142>/Switch' incorporates:
   *  Constant: '<S1142>/Constant'
   *  Logic: '<S1142>/Logical Operator'
   *  Logic: '<S1142>/Logical Operator1'
   *  UnitDelay: '<S1142>/UnitDelay1'
   */
  if (rtu_Enable && (!VDHP_BMSBatt_OverTFlt_flg)) {
    /* Switch: '<S1142>/Switch2' incorporates:
     *  Constant: '<S1142>/Constant2'
     *  Delay: '<S1142>/Delay'
     *  Logic: '<S1142>/Logical Operator2'
     */
    if (!localDW->Delay_DSTATE) {
      rtu_Enable_0 = 0U;
    } else {
      rtu_Enable_0 = rtu_DeltaSystemTick_ms;
    }

    /* End of Switch: '<S1142>/Switch2' */
  } else {
    rtu_Enable_0 = 0U;
  }

  /* End of Switch: '<S1142>/Switch' */

  /* Sum: '<S1142>/Add1' incorporates:
   *  UnitDelay: '<S1142>/UnitDelay'
   */
  qY = localDW->UnitDelay_DSTATE + rtu_Enable_0;
  if (qY < localDW->UnitDelay_DSTATE) {
    qY = MAX_uint32_T;
  }

  /* RelationalOperator: '<S1142>/Relational Operator' incorporates:
   *  Sum: '<S1142>/Add1'
   */
  VDHP_BMSBatt_OverTFlt_flg = (qY >= rtu_KeepTime_ms);

  /* Switch: '<S1142>/Switch1' */
  if (rtu_Enable) {
    /* Update for UnitDelay: '<S1142>/UnitDelay' incorporates:
     *  Sum: '<S1142>/Add1'
     */
    localDW->UnitDelay_DSTATE = qY;
  } else {
    /* Update for UnitDelay: '<S1142>/UnitDelay' incorporates:
     *  Constant: '<S1142>/Constant1'
     */
    localDW->UnitDelay_DSTATE = 0U;
  }

  /* End of Switch: '<S1142>/Switch1' */

  /* Update for Delay: '<S1142>/Delay' */
  localDW->Delay_DSTATE = rtu_Enable;
}

/*
 * Output and update for atomic system:
 *    '<S1243>/Fault_Affirm'
 *    '<S1248>/Fault_Affirm'
 *    '<S1253>/Fault_Affirm'
 *    '<S1258>/Fault_Affirm'
 *    '<S1263>/Fault_Affirm'
 *    '<S1268>/Fault_Affirm'
 *    '<S1273>/Fault_Affirm'
 *    '<S1278>/Fault_Affirm'
 *    '<S1282>/Fault_Affirm'
 *    '<S1293>/Fault_Affirm'
 *    ...
 */
void DHP_model_Fault_Affirm(boolean_T rtu_VNM_SleepInd_flg, uint8_T
  rtu_deltaSystemtick_ms, boolean_T rtu_Err_generate_Ins, uint16_T
  rtu_ConfirmTime_ms, uint16_T rtu_ClearTime_ms, boolean_T rtu_Allow_Recover,
  B_Fault_Affirm_DHP_model_T *localB, DW_Fault_Affirm_DHP_model_T *localDW)
{
  boolean_T rtb_RelationalOperator1_fp;
  boolean_T rtb_LogicalOperator3_pb;
  uint8_T rtb_Switch3_cg;
  boolean_T rtb_RelationalOperator3_as;
  uint8_T rtu_Err_generate_Ins_0;
  uint32_T rtb_LogicalOperator3_nc;
  uint32_T qY;
  uint32_T qY_0;
  uint32_T rtu_Err_generate_Ins_1;

  /* Switch: '<S1245>/Switch11' incorporates:
   *  Constant: '<S1245>/Constant3'
   *  Delay: '<S1245>/Delay'
   *  Logic: '<S1245>/Logical Operator1'
   *  Logic: '<S1245>/Logical Operator4'
   */
  if (rtu_Err_generate_Ins && (!localDW->Delay_DSTATE)) {
    rtb_Switch3_cg = 0U;
  } else {
    rtb_Switch3_cg = rtu_deltaSystemtick_ms;
  }

  /* End of Switch: '<S1245>/Switch11' */

  /* Switch: '<S1245>/Switch' incorporates:
   *  Constant: '<S1245>/Constant2'
   *  Delay: '<S1245>/Delay3'
   *  Logic: '<S1245>/Logical Operator5'
   */
  if (rtu_Err_generate_Ins || localDW->Delay3_DSTATE) {
    rtu_Err_generate_Ins_0 = 0U;
  } else {
    rtu_Err_generate_Ins_0 = rtb_Switch3_cg;
  }

  /* End of Switch: '<S1245>/Switch' */

  /* Switch: '<S1245>/Switch1' incorporates:
   *  Constant: '<S1245>/Constant1'
   *  Delay: '<S1245>/Delay1'
   */
  if (rtu_Err_generate_Ins) {
    rtu_Err_generate_Ins_1 = 0U;
  } else {
    rtu_Err_generate_Ins_1 = localDW->Delay1_DSTATE;
  }

  /* End of Switch: '<S1245>/Switch1' */

  /* Sum: '<S1245>/Add2' */
  rtu_Err_generate_Ins_1 += rtu_Err_generate_Ins_0;
  if (rtu_Err_generate_Ins_1 < rtu_Err_generate_Ins_0) {
    rtu_Err_generate_Ins_1 = MAX_uint32_T;
  }

  /* RelationalOperator: '<S1245>/Relational Operator1' incorporates:
   *  Sum: '<S1245>/Add2'
   */
  rtb_RelationalOperator1_fp = (rtu_Err_generate_Ins_1 >= rtu_ClearTime_ms);

  /* Logic: '<S1245>/Logical Operator3' */
  rtb_LogicalOperator3_pb = !rtu_Err_generate_Ins;

  /* Switch: '<S1245>/Switch5' incorporates:
   *  Constant: '<S1245>/Constant10'
   *  Constant: '<S1245>/Constant11'
   *  Delay: '<S1245>/Delay7'
   *  Switch: '<S1245>/Switch4'
   */
  if (rtb_LogicalOperator3_pb) {
    rtu_Err_generate_Ins_0 = 0U;
    rtb_LogicalOperator3_nc = 0U;
  } else {
    rtu_Err_generate_Ins_0 = rtb_Switch3_cg;
    rtb_LogicalOperator3_nc = localDW->Delay7_DSTATE;
  }

  /* End of Switch: '<S1245>/Switch5' */

  /* Sum: '<S1245>/Add6' */
  qY_0 = rtu_Err_generate_Ins_0 + rtb_LogicalOperator3_nc;
  if (qY_0 < rtu_Err_generate_Ins_0) {
    qY_0 = MAX_uint32_T;
  }

  /* Switch: '<S1245>/Switch9' incorporates:
   *  Delay: '<S1245>/Delay4'
   *  Logic: '<S1245>/Logical Operator2'
   *  RelationalOperator: '<S1245>/Relational Operator5'
   *  Sum: '<S1245>/Add6'
   */
  if (localDW->Delay4_DSTATE) {
    rtb_LogicalOperator3_pb = rtb_RelationalOperator1_fp;
  } else {
    rtb_LogicalOperator3_pb = (rtb_LogicalOperator3_pb && (qY_0 <
      rtu_ConfirmTime_ms));
  }

  /* End of Switch: '<S1245>/Switch9' */

  /* Switch: '<S1245>/Switch3' incorporates:
   *  Constant: '<S1245>/Constant4'
   */
  if (!rtu_Err_generate_Ins) {
    rtb_Switch3_cg = 0U;
  }

  /* End of Switch: '<S1245>/Switch3' */

  /* Switch: '<S1245>/Switch7' incorporates:
   *  Constant: '<S1245>/Constant7'
   *  Delay: '<S1245>/Delay2'
   *  Logic: '<S1245>/Logical Operator'
   */
  if (rtb_LogicalOperator3_pb || rtu_VNM_SleepInd_flg) {
    rtb_LogicalOperator3_nc = 0U;
  } else {
    rtb_LogicalOperator3_nc = localDW->Delay2_DSTATE;
  }

  /* End of Switch: '<S1245>/Switch7' */

  /* Sum: '<S1245>/Add3' */
  qY = rtb_LogicalOperator3_nc + rtb_Switch3_cg;
  if (qY < rtb_LogicalOperator3_nc) {
    qY = MAX_uint32_T;
  }

  /* RelationalOperator: '<S1245>/Relational Operator3' incorporates:
   *  Sum: '<S1245>/Add3'
   */
  rtb_RelationalOperator3_as = (qY >= rtu_ConfirmTime_ms);

  /* Switch: '<S1245>/Switch10' incorporates:
   *  Constant: '<S1245>/Constant13'
   *  Delay: '<S1245>/Delay6'
   *  Switch: '<S1245>/Switch6'
   */
  if (rtu_VNM_SleepInd_flg) {
    rtb_LogicalOperator3_pb = false;
  } else {
    rtb_LogicalOperator3_pb = (rtb_RelationalOperator3_as ||
      localDW->Delay6_DSTATE);
  }

  /* End of Switch: '<S1245>/Switch10' */

  /* Switch: '<S1245>/Switch8' */
  if (!rtu_Allow_Recover) {
    rtb_RelationalOperator3_as = rtb_LogicalOperator3_pb;
  }

  /* End of Switch: '<S1245>/Switch8' */

  /* Switch: '<S1245>/Switch2' */
  localB->Switch2 = ((!rtu_VNM_SleepInd_flg) && rtb_RelationalOperator3_as);

  /* Update for Delay: '<S1245>/Delay3' */
  localDW->Delay3_DSTATE = rtb_RelationalOperator1_fp;

  /* Update for Delay: '<S1245>/Delay' */
  localDW->Delay_DSTATE = rtu_Err_generate_Ins;

  /* Update for Delay: '<S1245>/Delay1' incorporates:
   *  Sum: '<S1245>/Add2'
   */
  localDW->Delay1_DSTATE = rtu_Err_generate_Ins_1;

  /* Update for Delay: '<S1245>/Delay4' */
  localDW->Delay4_DSTATE = rtb_RelationalOperator3_as;

  /* Update for Delay: '<S1245>/Delay7' incorporates:
   *  Sum: '<S1245>/Add6'
   */
  localDW->Delay7_DSTATE = qY_0;

  /* Update for Delay: '<S1245>/Delay2' incorporates:
   *  Sum: '<S1245>/Add3'
   */
  localDW->Delay2_DSTATE = qY;

  /* Update for Delay: '<S1245>/Delay6' */
  localDW->Delay6_DSTATE = rtb_LogicalOperator3_pb;
}

/*
 * Output and update for atomic system:
 *    '<S1242>/Fault_Valid_Time'
 *    '<S1247>/Fault_Valid_Time'
 *    '<S1252>/Fault_Valid_Time'
 *    '<S1257>/Fault_Valid_Time'
 *    '<S1262>/Fault_Valid_Time'
 *    '<S1267>/Fault_Valid_Time'
 *    '<S1272>/Fault_Valid_Time'
 *    '<S1277>/Fault_Valid_Time'
 *    '<S1292>/Fault_Valid_Time'
 *    '<S1303>/Fault_Valid_Time'
 *    ...
 */
void DHP_model_Fault_Valid_Time(boolean_T rtu_VNM_SleepInd_flg, uint8_T
  rtu_deltaSystemtick_ms, boolean_T rtu_Err_generate_Ins, uint16_T
  rtu_ConfirmTime_ms, uint16_T rtu_ClearTime_ms, boolean_T rtu_Allow_Recover,
  uint8_T rtu_Fault_Lever, uint8_T rtu_Spd_Limit, uint8_T rtu_Pwr_limit_Pct,
  uint16_T rtu_Handle_Response_Bits, boolean_T rtu_Action_Switch_Open,
  B_Fault_Valid_Time_DHP_model_T *localB, DW_Fault_Valid_Time_DHP_model_T
  *localDW)
{
  /* Outputs for Atomic SubSystem: '<S1243>/Fault_Affirm' */
  DHP_model_Fault_Affirm(rtu_VNM_SleepInd_flg, rtu_deltaSystemtick_ms,
    rtu_Err_generate_Ins, rtu_ConfirmTime_ms, rtu_ClearTime_ms,
    rtu_Allow_Recover, &localB->Fault_Affirm, &localDW->Fault_Affirm);

  /* End of Outputs for SubSystem: '<S1243>/Fault_Affirm' */

  /* Switch: '<S1244>/Switch2' incorporates:
   *  Constant: '<S1243>/Constant'
   *  Constant: '<S1244>/Constant1'
   *  Constant: '<S1244>/Constant2'
   *  Constant: '<S1244>/Constant3'
   *  Switch: '<S1243>/Switch2'
   *  Switch: '<S1244>/Switch1'
   *  Switch: '<S1244>/Switch3'
   *  Switch: '<S1244>/Switch4'
   */
  if (rtu_Action_Switch_Open && localB->Fault_Affirm.Switch2) {
    localB->Switch2 = rtu_Handle_Response_Bits;
    localB->Switch3 = rtu_Spd_Limit;
    localB->Switch4 = rtu_Pwr_limit_Pct;
    localB->Switch2_i = rtu_Fault_Lever;
  } else {
    localB->Switch2 = 0U;
    localB->Switch3 = 200U;
    localB->Switch4 = 100U;
    localB->Switch2_i = 0U;
  }

  /* End of Switch: '<S1244>/Switch2' */
}

/*
 * Output and update for atomic system:
 *    '<S1297>/Fault_Valid_RT'
 *    '<S1314>/Fault_Valid_RT'
 *    '<S1317>/Fault_Valid_RT'
 *    '<S1320>/Fault_Valid_RT'
 *    '<S1373>/Fault_Valid_RT'
 *    '<S1376>/Fault_Valid_RT'
 *    '<S1379>/Fault_Valid_RT'
 *    '<S1382>/Fault_Valid_RT'
 *    '<S1385>/Fault_Valid_RT'
 *    '<S1393>/Fault_Valid_RT'
 *    ...
 */
void DHP_model_Fault_Valid_RT(boolean_T rtu_VNM_SleepInd_flg, boolean_T
  rtu_Err_generate_Ins, boolean_T rtu_Allow_Recover, uint8_T rtu_Fault_Lever,
  uint8_T rtu_Spd_Limit, uint8_T rtu_Pwr_limit_Pct, uint16_T
  rtu_Handle_Response_Bits, boolean_T rtu_Action_Switch_Open,
  B_Fault_Valid_RT_DHP_model_T *localB, DW_Fault_Valid_RT_DHP_model_T *localDW)
{
  boolean_T rtb_Switch10_my;

  /* Switch: '<S1298>/Switch10' incorporates:
   *  Constant: '<S1298>/Constant12'
   *  Constant: '<S1298>/Constant13'
   *  Delay: '<S1298>/Delay6'
   *  Switch: '<S1298>/Switch6'
   *  Switch: '<S1298>/Switch9'
   */
  if (rtu_VNM_SleepInd_flg) {
    rtb_Switch10_my = false;
    localB->Switch9 = false;
  } else {
    rtb_Switch10_my = (rtu_Err_generate_Ins || localDW->Delay6_DSTATE);

    /* Switch: '<S1298>/Switch8' incorporates:
     *  Delay: '<S1298>/Delay6'
     *  Switch: '<S1298>/Switch6'
     */
    if (rtu_Allow_Recover) {
      localB->Switch9 = rtu_Err_generate_Ins;
    } else {
      localB->Switch9 = rtb_Switch10_my;
    }

    /* End of Switch: '<S1298>/Switch8' */
  }

  /* End of Switch: '<S1298>/Switch10' */

  /* Switch: '<S1299>/Switch2' incorporates:
   *  Constant: '<S1298>/Constant'
   *  Constant: '<S1299>/Constant1'
   *  Constant: '<S1299>/Constant2'
   *  Constant: '<S1299>/Constant3'
   *  Switch: '<S1298>/Switch2'
   *  Switch: '<S1299>/Switch1'
   *  Switch: '<S1299>/Switch3'
   *  Switch: '<S1299>/Switch4'
   */
  if (rtu_Action_Switch_Open && localB->Switch9) {
    localB->Switch2 = rtu_Handle_Response_Bits;
    localB->Switch3 = rtu_Spd_Limit;
    localB->Switch4 = rtu_Pwr_limit_Pct;
    localB->Switch2_m = rtu_Fault_Lever;
  } else {
    localB->Switch2 = 0U;
    localB->Switch3 = 200U;
    localB->Switch4 = 100U;
    localB->Switch2_m = 0U;
  }

  /* End of Switch: '<S1299>/Switch2' */

  /* Update for Delay: '<S1298>/Delay6' */
  localDW->Delay6_DSTATE = rtb_Switch10_my;
}

/* Output and update for atomic system: '<S1693>/Fault_Action' */
void DHP_model_Fault_Action(boolean_T rtu_Valid_Err_Generate, uint8_T
  rtu_Spd_Limit, uint8_T rtu_Pwr_limit_Pct, uint16_T rtu_Handle_Response_Bits,
  boolean_T rtu_Action_Switch_Open, B_Fault_Action_DHP_model_T *localB)
{
  /* Switch: '<S1694>/Switch2' incorporates:
   *  Constant: '<S1694>/Constant1'
   *  Constant: '<S1694>/Constant2'
   *  Constant: '<S1694>/Constant3'
   *  Switch: '<S1694>/Switch1'
   *  Switch: '<S1694>/Switch3'
   *  Switch: '<S1694>/Switch4'
   */
  if (rtu_Action_Switch_Open && rtu_Valid_Err_Generate) {
    localB->Switch2 = rtu_Handle_Response_Bits;
    localB->Switch3 = rtu_Spd_Limit;
    localB->Switch4 = rtu_Pwr_limit_Pct;
  } else {
    localB->Switch2 = 0U;
    localB->Switch3 = 200U;
    localB->Switch4 = 100U;
  }

  /* End of Switch: '<S1694>/Switch2' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

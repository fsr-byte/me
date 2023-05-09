/*
 * File: DOM_model.c
 *
 * Code generated for Simulink model 'DOM_model'.
 *
 * Model version                  : 1.965
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Apr 12 11:07:38 2023
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

#include "DOM_model.h"
#include "DOM_model_private.h"

#pragma push
#pragma DATA_SEG __GPAGE_SEG GPAGED_RAM

const DOM DOM_model_rtZDOM = {
  false,                               /* DOM_SSB1Sts */
  false,                               /* DOM_SSB2Sts */
  false,                               /* DOM_SSBSts */
  false,                               /* DOM_SSBRedLed */
  false,                               /* DOM_SSBGreenLed */
  0U,                                  /* DOM_PDU */
  false,                               /* DOM_Ready */
  false                                /* DOM_HVStatus */
} ;                                    /* DOM ground */

#pragma pop

/* External outputs (root outports fed by signals with default storage) */
#pragma push
#pragma DATA_SEG __GPAGE_SEG GPAGED_RAM

ExtY_DOM_model_T DOM_model_Y;

#pragma pop

/* Model step function */
void DOM_model_step(void)
{
  /* SignalConversion: '<Root>/Signal Conversion' incorporates:
   *  Inport: '<Root>/BTK_OUT'
   */
  DOM_SSB1Sts = BTK_output.BTK_SSB1Sts;

  /* SignalConversion: '<Root>/Signal Conversion1' incorporates:
   *  Inport: '<Root>/BTK_OUT'
   */
  DOM_SSB2Sts = BTK_output.BTK_SSB2Sts;

  /* SignalConversion: '<Root>/Signal Conversion2' incorporates:
   *  Inport: '<Root>/BTK_OUT'
   */
  DOM_SSBSts = BTK_output.BTK_SSBSts;

  /* SignalConversion: '<Root>/Signal Conversion3' incorporates:
   *  Inport: '<Root>/BTK_OUT'
   */
  DOM_SSBRedLed = BTK_output.BTK_SSBRedLed;

  /* SignalConversion: '<Root>/Signal Conversion4' incorporates:
   *  Inport: '<Root>/BTK_OUT'
   */
  DOM_SSBGreenLed = BTK_output.BTK_SSBGreenLed;

  /* SignalConversion: '<Root>/Signal Conversion5' incorporates:
   *  Inport: '<Root>/BTK_OUT'
   */
  DOM_PDU = BTK_output.BTK_PDU;

  /* SignalConversion: '<Root>/Signal Conversion6' incorporates:
   *  Inport: '<Root>/BTK_OUT'
   */
  DOM_Ready = BTK_output.BTK_Ready;

  /* SignalConversion: '<Root>/Signal Conversion7' incorporates:
   *  Inport: '<Root>/BTK_OUT'
   */
  DOM_HVStatus = BTK_output.BTK_HVStatus;

  /* BusCreator: '<Root>/BusConversion_InsertedFor_DOM_at_inport_0' incorporates:
   *  Outport: '<Root>/DOM'
   */
  DOM_model_Y.DOM_a.DOM_SSB1Sts = DOM_SSB1Sts;
  DOM_model_Y.DOM_a.DOM_SSB2Sts = DOM_SSB2Sts;
  DOM_model_Y.DOM_a.DOM_SSBSts = DOM_SSBSts;
  DOM_model_Y.DOM_a.DOM_SSBRedLed = DOM_SSBRedLed;
  DOM_model_Y.DOM_a.DOM_SSBGreenLed = DOM_SSBGreenLed;
  DOM_model_Y.DOM_a.DOM_PDU = DOM_PDU;
  DOM_model_Y.DOM_a.DOM_Ready = DOM_Ready;
  DOM_model_Y.DOM_a.DOM_HVStatus = DOM_HVStatus;
}

/* Model initialize function */
void DOM_model_initialize(void)
{
  /* Registration code */

  /* external outputs */
  DOM_model_Y.DOM_a = DOM_model_rtZDOM;
}

/* Model terminate function */
void DOM_model_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

/*
 * File: DOM_model_types.h
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

#ifndef RTW_HEADER_DOM_model_types_h_
#define RTW_HEADER_DOM_model_types_h_
#include "rtwtypes.h"
#ifndef DEFINED_TYPEDEF_FOR_BTK_
#define DEFINED_TYPEDEF_FOR_BTK_

typedef struct {
  boolean_T BTK_SSB1Sts;
  boolean_T BTK_SSB2Sts;
  boolean_T BTK_SSBSts;
  boolean_T BTK_SSBRedLed;
  boolean_T BTK_SSBGreenLed;
  uint8_T BTK_PDU;
  boolean_T BTK_Ready;
  boolean_T BTK_HVStatus;
} BTK;

#endif

#ifndef DEFINED_TYPEDEF_FOR_DOM_
#define DEFINED_TYPEDEF_FOR_DOM_

typedef struct {
  boolean_T DOM_SSB1Sts;
  boolean_T DOM_SSB2Sts;
  boolean_T DOM_SSBSts;
  boolean_T DOM_SSBRedLed;
  boolean_T DOM_SSBGreenLed;
  uint8_T DOM_PDU;
  boolean_T DOM_Ready;
  boolean_T DOM_HVStatus;
} DOM;

#endif
#endif                                 /* RTW_HEADER_DOM_model_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

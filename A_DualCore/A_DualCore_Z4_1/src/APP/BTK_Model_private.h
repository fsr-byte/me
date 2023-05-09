/*
 * File: BTK_Model_private.h
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

#ifndef RTW_HEADER_BTK_Model_private_h_
#define RTW_HEADER_BTK_Model_private_h_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "BTK_Model.h"

/* Imported (extern) block signals */
extern DIM DIM_output;                 /* '<Root>/INP' */

/* Imported (extern) states */
extern uint32_T SystemTickMs;          /* '<S1>/Data Store Memory' */
extern void BTK_Model_BTK_Module_Init(void);
extern void BTK_Model_BTK_Module(void);

#endif                                 /* RTW_HEADER_BTK_Model_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

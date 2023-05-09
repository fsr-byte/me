/*
 * File: DOM_model.h
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

#ifndef RTW_HEADER_DOM_model_h_
#define RTW_HEADER_DOM_model_h_
#ifndef DOM_model_COMMON_INCLUDES_
# define DOM_model_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* DOM_model_COMMON_INCLUDES_ */

#include "DOM_model_types.h"

/* Macros for accessing real-time model data structure */

/* user code (top of header file) */
#include "derivative.h"

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  DOM DOM_a;                           /* '<Root>/DOM' */
} ExtY_DOM_model_T;

/* External outputs (root outports fed by signals with default storage) */
#pragma push
#pragma DATA_SEG __GPAGE_SEG GPAGED_RAM

extern ExtY_DOM_model_T DOM_model_Y;

#pragma pop

/* External data declarations for dependent source files */
#pragma push
#pragma DATA_SEG __GPAGE_SEG GPAGED_RAM

extern const DOM DOM_model_rtZDOM;     /* DOM ground */

#pragma pop

/* Model entry point functions */
extern void DOM_model_initialize(void);
extern void DOM_model_step(void);
extern void DOM_model_terminate(void);

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'DOM_model'
 */
#endif                                 /* RTW_HEADER_DOM_model_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

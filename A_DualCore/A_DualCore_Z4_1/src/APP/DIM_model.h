/*
 * File: DIM_model.h
 *
 * Code generated for Simulink model 'DIM_model'.
 *
 * Model version                  : 1.2351
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Apr 12 11:32:26 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Freescale->32-bit PowerPC
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. MISRA C:2012 guidelines
 * Validation result: Not run
 */

#ifndef RTW_HEADER_DIM_model_h_
#define RTW_HEADER_DIM_model_h_
#ifndef DIM_model_COMMON_INCLUDES_
# define DIM_model_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* DIM_model_COMMON_INCLUDES_ */

#include "DIM_model_types.h"

/* Macros for accessing real-time model data structure */

/* user code (top of header file) */
#include "derivative.h"

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern DIM DIM_output;                 /* '<Root>/Bus Creator' */

/* Model entry point functions */
extern void DIM_model_initialize(void);
extern void DIM_model_step(void);
extern void DIM_model_terminate(void);

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
 * '<Root>' : 'DIM_model'
 */

/*-
 * Requirements for '<Root>': DIM_model
 */
#endif                                 /* RTW_HEADER_DIM_model_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

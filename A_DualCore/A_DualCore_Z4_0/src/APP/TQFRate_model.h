/*
 * File: TQFRate_model.h
 *
 * Code generated for Simulink model 'TQFRate_model'.
 *
 * Model version                  : 1.1651
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Fri Mar 18 15:48:25 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Freescale->32-bit PowerPC
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. MISRA C:2012 guidelines
 * Validation result: Not run
 */

#ifndef RTW_HEADER_TQFRate_model_h_
#define RTW_HEADER_TQFRate_model_h_
#include <math.h>
#include <stddef.h>
#ifndef TQFRate_model_COMMON_INCLUDES_
# define TQFRate_model_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* TQFRate_model_COMMON_INCLUDES_ */

#include "TQFRate_model_types.h"

/* Includes for objects with custom storage classes. */
#include "TQFRate_Cal_Data.h"

/* Macros for accessing real-time model data structure */

/* user code (top of header file) */
#include "derivative.h"

/* Constant parameters (auto storage) */
typedef struct {
  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S3>/2D_MAP_Flat'
   *   '<S3>/2D_MAP_Flat1'
   *   '<S3>/2D_MAP_Flat2'
   *   '<S3>/2D_MAP_Flat3'
   *   '<S5>/2D_MAP_Flat'
   *   '<S5>/2D_MAP_Flat1'
   *   '<S5>/2D_MAP_Flat2'
   *   '<S5>/2D_MAP_Flat3'
   *   '<S6>/2D_MAP_Flat'
   *   '<S6>/2D_MAP_Flat1'
   *   '<S6>/2D_MAP_Flat2'
   *   '<S6>/2D_MAP_Flat3'
   */
  uint32_T pooled1[2];
} ConstParam_TQFRate_model_T;

/* Constant parameters (auto storage) */
#pragma push
#pragma DATA_SEG __GPAGE_SEG GPAGED_RAM

extern const ConstParam_TQFRate_model_T TQFRate_model_ConstP;

#pragma pop

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern TQFRate TQFRate_output;         /* '<Root>/Bus Creator' */
extern int16_T TQFRate__DmdTqFilOld_Nm_abs;/* '<S1>/Data Type Conversion1' */
extern int16_T TQFRate_VehTq_Differ_abs;/* '<S1>/Data Type Conversion' */

/* Model entry point functions */
extern void TQFRate_model_initialize(void);
extern void TQFRate_model_step(void);
extern void TQFRate_model_terminate(void);

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
 * '<Root>' : 'TQFRate_model'
 * '<S1>'   : 'TQFRate_model/Determine_TQFRate'
 * '<S2>'   : 'TQFRate_model/Determine_TQFRate/AntiSlide_Mode'
 * '<S3>'   : 'TQFRate_model/Determine_TQFRate/Cruise_Mode'
 * '<S4>'   : 'TQFRate_model/Determine_TQFRate/Default'
 * '<S5>'   : 'TQFRate_model/Determine_TQFRate/Esc_Mode'
 * '<S6>'   : 'TQFRate_model/Determine_TQFRate/Esc_Mode1'
 */

/*-
 * Requirements for '<Root>': TQFRate_model
 */
#endif                                 /* RTW_HEADER_TQFRate_model_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

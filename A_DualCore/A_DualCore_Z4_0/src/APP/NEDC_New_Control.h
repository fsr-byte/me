/*
 * File: NEDC_New_Control.h
 *
 * Code generated for Simulink model 'SCR_model'.
 *
 * Model version                  : 1.2266
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Fri Mar 18 15:47:47 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Freescale->32-bit PowerPC
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. MISRA C:2012 guidelines
 * Validation result: Not run
 */

#ifndef RTW_HEADER_NEDC_New_Control_h_
#define RTW_HEADER_NEDC_New_Control_h_
#include <math.h>
#ifndef SCR_model_COMMON_INCLUDES_
# define SCR_model_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#endif                                 /* SCR_model_COMMON_INCLUDES_ */

#include "SCR_model_types.h"

extern void SCR_model_NEDC_Recoginiton(void);
extern void SCR_model_NEDC_Work_Init(void);
extern void SCR_model_NEDC_Work_Start(void);
extern void SCR_model_NEDC_Work(void);
extern void SCR_model_NEDC_New_Control_Init(void);
extern void SCR_mode_NEDC_New_Control_Start(void);
extern void SCR_model_NEDC_New_Control(void);

#endif                                 /* RTW_HEADER_NEDC_New_Control_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

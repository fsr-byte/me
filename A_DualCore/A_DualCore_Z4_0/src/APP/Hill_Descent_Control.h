/*
 * File: Hill_Descent_Control.h
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

#ifndef RTW_HEADER_Hill_Descent_Control_h_
#define RTW_HEADER_Hill_Descent_Control_h_
#ifndef SCR_model_COMMON_INCLUDES_
# define SCR_model_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#endif                                 /* SCR_model_COMMON_INCLUDES_ */

#include "SCR_model_types.h"

/* Child system includes */
#include "HDC_Lower_Controller.h"
#include "HDC_Upper_Controller.h"
#include "rt_sys_SCR_model_144.h"

extern void SCR_m_Hill_Descent_Control_Init(void);
extern void SCR_model_Hill_Descent_Control(void);

#endif                                 /* RTW_HEADER_Hill_Descent_Control_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

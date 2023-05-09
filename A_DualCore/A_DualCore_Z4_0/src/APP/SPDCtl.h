/*
 * File: SPDCtl.h
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

#ifndef RTW_HEADER_SPDCtl_h_
#define RTW_HEADER_SPDCtl_h_
#ifndef SCR_model_COMMON_INCLUDES_
# define SCR_model_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#endif                                 /* SCR_model_COMMON_INCLUDES_ */

#include "SCR_model_types.h"

/* Child system includes */
#include "CLTC_Control.h"
#include "Cruise_Control.h"
#include "Hill_Descent_Control.h"
#include "NEDC_New_Control.h"
#include "SPDCtl_OUT.h"

extern void SCR_model_Get_TickDiff_ms_Init(void);
extern void SCR_model_Get_TickDiff_ms(void);
extern void SCR_model_SPDCtl_Init(void);
extern void SCR_model_SPDCtl_Start(void);
extern void SCR_model_SPDCtl(void);

#endif                                 /* RTW_HEADER_SPDCtl_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

/*
 * File: ENM_M.h
 *
 * Code generated for Simulink model 'ENM_model'.
 *
 * Model version                  : 1.1958
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Fri Mar 18 15:39:06 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Freescale->32-bit PowerPC
 * Code generation objective: Execution efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_ENM_M_h_
#define RTW_HEADER_ENM_M_h_
#include <math.h>
#ifndef ENM_model_COMMON_INCLUDES_
# define ENM_model_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* ENM_model_COMMON_INCLUDES_ */

#include "ENM_model_types.h"

/* Child system includes */
#include "ENM_Battery.h"
#include "ENM_DCDC.h"
#include "ENM_EnergyConsumptionStatistics.h"
#include "ENM_PowerLimit.h"

extern void ENM_model_ENM_M_Init(void);
extern void ENM_model_ENM_M_Start(void);
extern void ENM_model_ENM_M(void);

#endif                                 /* RTW_HEADER_ENM_M_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

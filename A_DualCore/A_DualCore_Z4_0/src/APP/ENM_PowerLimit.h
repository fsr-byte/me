/*
 * File: ENM_PowerLimit.h
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

#ifndef RTW_HEADER_ENM_PowerLimit_h_
#define RTW_HEADER_ENM_PowerLimit_h_
#include <math.h>
#ifndef ENM_model_COMMON_INCLUDES_
# define ENM_model_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* ENM_model_COMMON_INCLUDES_ */

#include "ENM_model_types.h"

/* Child system includes */
#include "ENM_lib.h"

extern void ENM_model_DCDC_PwrLimit(void);
extern void ENM_model_ECC_PowerLimit(void);
extern void ENM_m_MotorDischarge_PowerLimit(void);
extern void ENM_mode_Motor_PowerChargeLimit(void);
extern void ENM_model_HVPower_Allocation(void);
extern void ENM_model_ENM_PowerLimit(void);

#endif                                 /* RTW_HEADER_ENM_PowerLimit_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

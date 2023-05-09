/*
 * File: ACR.h
 *
 * Code generated for Simulink model 'ACR_model'.
 *
 * Model version                  : 1.1784
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Fri Mar 18 15:46:44 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Freescale->32-bit PowerPC
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. MISRA C:2012 guidelines
 * Validation result: Not run
 */

#ifndef RTW_HEADER_ACR_h_
#define RTW_HEADER_ACR_h_
#include <math.h>
#ifndef ACR_model_COMMON_INCLUDES_
# define ACR_model_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* ACR_model_COMMON_INCLUDES_ */

#include "ACR_model_types.h"

/* Block signals and states (auto storage) for system '<S14>/Hysteresis_LeftTrue' */
typedef struct
{
    boolean_T Delay_DSTATE;            /* '<S19>/Delay' */
}
rtDW_Hysteresis_LeftTrue_ACR__T;

/* Block signals and states (auto storage) for system '<S14>/Hysteresis_RightTrue' */
typedef struct
{
    boolean_T Delay_DSTATE;            /* '<S20>/Delay' */
}
rtDW_Hysteresis_RightTrue_ACR_T;

extern void ACR_model_Hysteresis_LeftTrue(real32_T rtu_Input, boolean_T
    *rty_Output, rtDW_Hysteresis_LeftTrue_ACR__T *localDW, real32_T
    rtp_leftpoint, real32_T rtp_rightpoint);
extern void ACR_model_Hysteresis_RightTrue(real32_T rtu_Input, boolean_T
    *rty_Output, rtDW_Hysteresis_RightTrue_ACR_T *localDW, real32_T
    rtp_leftpoint, real32_T rtp_rightpoint);
extern void ACR_model_AcceleratedTrqControl(void);
extern void ACR_model_SystemLimitControl(void);
extern void ACR_mod_AccelerationLoopControl(void);
extern void ACR_model_AccelerationRequest(void);
extern void ACR_model_ACR(void);

#endif                                 /* RTW_HEADER_ACR_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

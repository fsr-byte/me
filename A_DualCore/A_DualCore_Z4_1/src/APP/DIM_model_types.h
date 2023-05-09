/*
 * File: DIM_model_types.h
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

#ifndef RTW_HEADER_DIM_model_types_h_
#define RTW_HEADER_DIM_model_types_h_
#include "rtwtypes.h"
#ifndef DEFINED_TYPEDEF_FOR_DIM_
#define DEFINED_TYPEDEF_FOR_DIM_

typedef struct
{
    boolean_T DIM_IgnitionOn_flg;
    boolean_T DIM_SSB_Switch1;
    boolean_T DIM_SSB_Switch2;
    uint8_T DIM_VehicleSpeed;
    boolean_T DIM_BrkLightSwitchActive_flg;
}
DIM;

#endif
#endif                                 /* RTW_HEADER_DIM_model_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

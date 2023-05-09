/*
 * File: BTK_Model_types.h
 *
 * Code generated for Simulink model 'BTK_Model'.
 *
 * Model version                  : 1.4525
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Apr 12 11:25:45 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Freescale->32-bit PowerPC
 * Code generation objectives:
 *    1. RAM efficiency
 *    2. ROM efficiency
 *    3. Execution efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_BTK_Model_types_h_
#define RTW_HEADER_BTK_Model_types_h_
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

#ifndef DEFINED_TYPEDEF_FOR_BTK_
#define DEFINED_TYPEDEF_FOR_BTK_

typedef struct
{
    boolean_T BTK_SSB1Sts;
    boolean_T BTK_SSB2Sts;
    boolean_T BTK_SSBSts;
    boolean_T BTK_SSBRedLed;
    boolean_T BTK_SSBGreenLed;
    uint8_T BTK_PDU;
    boolean_T BTK_Ready;
    boolean_T BTK_HVStatus;
}
BTK;

#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM_BTK_Model_T RT_MODEL_BTK_Model_T;

#endif                                 /* RTW_HEADER_BTK_Model_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

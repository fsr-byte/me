/*
 * File: DIM_model.c
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

#include "DIM_model.h"
#include "DIM_model_private.h"

/* Exported block signals */
DIM DIM_output;                        /* '<Root>/Bus Creator' */

/* Model step function */
void DIM_model_step(void)
{
    /* BusCreator: '<Root>/Bus Creator' incorporates:
     *  Inport: '<Root>/GUI_BrkLightSwitchActive_flg'
     *  Inport: '<Root>/GUI_VehicleSpeed'
     *  Inport: '<Root>/HW_IgnitionOn_flg'
     *  Inport: '<Root>/HW_SSB_Switch1'
     *  Inport: '<Root>/HW_SSB_Switch2'
     */
    DIM_output.DIM_IgnitionOn_flg = HWin_IgnitionOn_flg;
    DIM_output.DIM_SSB_Switch1 = HWin_SSB_Switch1;
    DIM_output.DIM_SSB_Switch2 = HWin_SSB_Switch2;
    DIM_output.DIM_VehicleSpeed = GUI_VehicleSpeed;
    DIM_output.DIM_BrkLightSwitchActive_flg = GUI_BrkLightSwitchActive_flg;
}

/* Model initialize function */
void DIM_model_initialize(void)
{
    /* (no initialization code required) */
}

/* Model terminate function */
void DIM_model_terminate(void)
{
    /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

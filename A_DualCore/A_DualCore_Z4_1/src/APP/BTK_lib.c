/*
 * File: BTK_lib.c
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

#include "BTK_lib.h"

/* Include model header file for global data */
#include "BTK_Model.h"
#include "BTK_Model_private.h"

/*
 * Output and update for atomic system:
 *    '<S3>/BTK_Delay_Confirm'
 *    '<S3>/BTK_Delay_Confirm1'
 */
void BTK_Model_BTK_Delay_Confirm(boolean_T rtu_din, uint32_T rtu_t_dbnc,
    uint32_T rtu_simple, rtB_BTK_Delay_Confirm_BTK_Mod_T *localB,
    rtDW_BTK_Delay_Confirm_BTK_Mo_T *localDW)
{
    int32_T rtb_Switch_nc;

    /* Switch: '<S11>/Switch' incorporates:
     *  DataTypeConversion: '<S11>/Data Type Conversion'
     *  Delay: '<S7>/Delay'
     *  RelationalOperator: '<S7>/edge'
     */
    if (rtu_din != localDW->Delay_DSTATE)
    {
        rtb_Switch_nc = (int32_T)rtu_t_dbnc;
    }
    else
    {
        /* Sum: '<S11>/Sum1' incorporates:
         *  DataTypeConversion: '<S11>/Data Type Conversion1'
         *  Delay: '<S11>/Delay2'
         */
        rtb_Switch_nc = (int32_T)rtu_simple;
        if ((localDW->Delay2_DSTATE >= 0) && (rtb_Switch_nc <
                localDW->Delay2_DSTATE - MAX_int32_T))
        {
            rtb_Switch_nc = MAX_int32_T;
        }
        else if ((localDW->Delay2_DSTATE < 0) && (rtb_Switch_nc >
                  localDW->Delay2_DSTATE - MIN_int32_T))
        {
            rtb_Switch_nc = MIN_int32_T;
        }
        else
        {
            rtb_Switch_nc = localDW->Delay2_DSTATE - rtb_Switch_nc;
        }

        /* End of Sum: '<S11>/Sum1' */
    }

    /* End of Switch: '<S11>/Switch' */

    /* Saturate: '<S11>/Saturation' */
    if (rtb_Switch_nc > 6000000)
    {
        rtb_Switch_nc = 6000000;
    }
    else
    {
        if (rtb_Switch_nc < 0)
        {
            rtb_Switch_nc = 0;
        }
    }

    /* End of Saturate: '<S11>/Saturation' */

    /* Switch: '<S7>/debounce' incorporates:
     *  Constant: '<S11>/Constant2'
     *  RelationalOperator: '<S11>/Relational Operator2'
     */
    if (rtb_Switch_nc == 0)
    {
        localB->debounce = rtu_din;
    }

    /* End of Switch: '<S7>/debounce' */

    /* Update for Delay: '<S11>/Delay2' */
    localDW->Delay2_DSTATE = rtb_Switch_nc;

    /* Update for Delay: '<S7>/Delay' */
    localDW->Delay_DSTATE = rtu_din;
}

/*
 * Output and update for atomic system:
 *    '<S10>/BTKSignalConfirm1'
 *    '<S10>/BTKSignalConfirm2'
 *    '<S10>/BTKSignalConfirm3'
 */
void BTK_Model_BTKSignalConfirm(boolean_T rtu_True_Flag, uint32_T
    rtu_SingalConfirmTime, uint32_T rtu_simple, rtB_BTKSignalConfirm_BTK_Mode_T *
    localB, rtDW_BTKSignalConfirm_BTK_Mod_T *localDW)
{
    uint32_T rtu_True_Flag_0;
    uint32_T rtu_True_Flag_1;

    /* Switch: '<S17>/Switch' incorporates:
     *  Constant: '<S17>/Constant1'
     *  Constant: '<S17>/Constant8'
     *  Switch: '<S17>/Switch1'
     *  UnitDelay: '<S17>/Unit Delay'
     */
    if (rtu_True_Flag)
    {
        rtu_True_Flag_0 = localDW->UnitDelay_DSTATE;
        rtu_True_Flag_1 = rtu_simple;
    }
    else
    {
        rtu_True_Flag_0 = 0U;
        rtu_True_Flag_1 = 0U;
    }

    /* End of Switch: '<S17>/Switch' */

    /* Sum: '<S17>/Add' */
    rtu_True_Flag_1 += /*MW:OvSatOk*/ rtu_True_Flag_0;
    if (rtu_True_Flag_1 < rtu_True_Flag_0)
    {
        rtu_True_Flag_1 = MAX_uint32_T;
    }

    /* RelationalOperator: '<S17>/Relational Operator3' incorporates:
     *  Sum: '<S17>/Add'
     */
    localB->RelationalOperator3 = (rtu_True_Flag_1 >= rtu_SingalConfirmTime);

    /* Update for UnitDelay: '<S17>/Unit Delay' incorporates:
     *  Sum: '<S17>/Add'
     */
    localDW->UnitDelay_DSTATE = rtu_True_Flag_1;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

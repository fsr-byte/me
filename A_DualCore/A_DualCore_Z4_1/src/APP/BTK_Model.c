/*
 * File: BTK_Model.c
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

#include "BTK_Model.h"
#include "BTK_Model_private.h"

#pragma push
#pragma DATA_SEG __GPAGE_SEG GPAGED_RAM

const BTK BTK_Model_rtZBTK =
{
    false,                             /* BTK_SSB1Sts */
    false,                             /* BTK_SSB2Sts */
    false,                             /* BTK_SSBSts */
    false,                             /* BTK_SSBRedLed */
    false,                             /* BTK_SSBGreenLed */
    0U,                                /* BTK_PDU */
    false,                             /* BTK_Ready */
    false                              /* BTK_HVStatus */
} ;                                    /* BTK ground */

#pragma pop

/* Exported block signals */
BTK BTK_output;                        /* '<S1>/Bus Creator' */
boolean_T SSB_Adhesion;                /* '<S10>/Logical Operator' */
boolean_T SSB_SyncCorrect;             /* '<S10>/Logical Operator1' */

/* Block signals (default storage) */
#pragma push
#pragma DATA_SEG __GPAGE_SEG GPAGED_RAM

BlockIO_BTK_Model_T BTK_Model_B;

#pragma pop

/* Block states (default storage) */
#pragma push
#pragma DATA_SEG __GPAGE_SEG GPAGED_RAM

D_Work_BTK_Model_T BTK_Model_DWork;

#pragma pop

/* Previous zero-crossings (trigger) states */
#pragma push
#pragma DATA_SEG __GPAGE_SEG GPAGED_RAM

PrevZCSigStates_BTK_Model_T BTK_Model_PrevZCSigState;

#pragma pop

/* Real-time model */
#pragma push
#pragma DATA_SEG __GPAGE_SEG GPAGED_RAM

RT_MODEL_BTK_Model_T BTK_Model_M_;

#pragma pop
#pragma push
#pragma DATA_SEG __GPAGE_SEG GPAGED_RAM

RT_MODEL_BTK_Model_T *const BTK_Model_M = &BTK_Model_M_;

#pragma pop

/* System initialize for atomic system: '<Root>/BTK_Module' */
void BTK_Model_BTK_Module_Init(void)
{
    /* SystemInitialize for Atomic SubSystem: '<S1>/BTK_ACT_PEPS' */
    BTK_Model_BTK_ACT_PEPS_Init();

    /* End of SystemInitialize for SubSystem: '<S1>/BTK_ACT_PEPS' */
}

/* Output and update for atomic system: '<Root>/BTK_Module' */
void BTK_Model_BTK_Module(void)
{
    /* Outputs for Atomic SubSystem: '<S1>/BTK_ACT_PEPS' */
    BTK_Model_BTK_ACT_PEPS();

    /* End of Outputs for SubSystem: '<S1>/BTK_ACT_PEPS' */

    /* BusCreator: '<S1>/Bus Creator' */
    BTK_output.BTK_SSB1Sts = BTK_Model_B.Merge1;
    BTK_output.BTK_SSB2Sts = BTK_Model_B.Merge2;
    BTK_output.BTK_SSBSts = BTK_Model_B.Merge;
    BTK_output.BTK_PDU = BTK_Model_B.VBTK_PDU;
}

/* Model step function */
void BTK_Model_step(void)
{
    /* Outputs for Atomic SubSystem: '<Root>/BTK_Module' */
    BTK_Model_BTK_Module();

    /* End of Outputs for SubSystem: '<Root>/BTK_Module' */
}

/* Model initialize function */
void BTK_Model_initialize(void)
{
    /* Registration code */

    /* initialize error status */
    rtmSetErrorStatus(BTK_Model_M, (NULL));

    /* block I/O */
    (void) memset(((void *) &BTK_Model_B), 0,
                  sizeof(BlockIO_BTK_Model_T));

    /* exported global signals */
    BTK_output = BTK_Model_rtZBTK;
    SSB_Adhesion = false;
    SSB_SyncCorrect = true;

    /* states (dwork) */
    (void) memset((void *)&BTK_Model_DWork, 0,
                  sizeof(D_Work_BTK_Model_T));
    BTK_Model_PrevZCSigState.ACC_Rise_Trig_ZCE = POS_ZCSIG;
    BTK_Model_PrevZCSigState.ON_Fall_Trig_ZCE = ZERO_ZCSIG;

    /* SystemInitialize for Atomic SubSystem: '<Root>/BTK_Module' */
    BTK_Model_BTK_Module_Init();

    /* End of SystemInitialize for SubSystem: '<Root>/BTK_Module' */
}

/* Model terminate function */
void BTK_Model_terminate(void)
{
    /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

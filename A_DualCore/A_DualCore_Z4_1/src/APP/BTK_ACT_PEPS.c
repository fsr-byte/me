/*
 * File: BTK_ACT_PEPS.c
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

#include "BTK_ACT_PEPS.h"

/* Include model header file for global data */
#include "BTK_Model.h"
#include "BTK_Model_private.h"

/* Named constants for Chart: '<S2>/BTK_StsteMachine' */
#define BTK_Model_IN_BTK_HV_START      ((uint8_T)1U)
#define BTK_Model_IN_BTK_HV_Without    ((uint8_T)2U)
#define BTK_Model_IN_BTK_LV_A          ((uint8_T)3U)
#define BTK_Model_IN_BTK_OFF           ((uint8_T)4U)
#define BTK_Model_IN_BTK_OFF_Down      ((uint8_T)1U)
#define BTK_Model_IN_BTK_OFF_IGN_Break ((uint8_T)1U)
#define BTK_Model_IN_BTK_OFF_SLEEP_IN_W ((uint8_T)2U)
#define BTK_Model_IN_BTK_OFF_Waiting   ((uint8_T)2U)
#define BTK_Model_IN_NO_ACTIVE_CHILD   ((uint8_T)0U)

/* Forward declaration for local functions */
static void BTK_Model_OFFUpSSBTrigger(const boolean_T *LogicalOperator13);
static void BTK_Model_SleepAllw(void);
static void BTK_Model_ClearAllFlags(void);
static void BTK_Model_StartDownAllw(const boolean_T *LogicalOperator13);
static void BTK_Mode_enter_internal_BTK_OFF(void);
static void BTK_Model_HVWOtoSTART(const boolean_T *LogicalOperator13);
static void BTK_Model_HVWOtoOFF(void);
static void BTK_Model_LVUporDnAllw(const boolean_T *LogicalOperator13);

/* Function for Chart: '<S2>/BTK_StsteMachine' */
static void BTK_Model_OFFUpSSBTrigger(const boolean_T *LogicalOperator13)
{
    /* Graphical Function 'OFFUpSSBTrigger': '<S6>:1829' */
    /* Transition: '<S6>:1831' */
    if (*LogicalOperator13)
    {
        /* Transition: '<S6>:1833' */
        /* Transition: '<S6>:2400' */
        BTK_Model_DWork.bool_OFFtoStartAllw = BTK_Model_B.LogicalOperator2;
        BTK_Model_DWork.bool_OFFtoLVAllw = BTK_Model_B.LogicalOperator3;

        /* Transition: '<S6>:2173' */
    }
    else
    {
        /* Transition: '<S6>:2172' */
    }
}

/* Function for Chart: '<S2>/BTK_StsteMachine' */
static void BTK_Model_SleepAllw(void)
{
    uint32_T qY;

    /* DataStoreRead: '<S2>/Data Store Read2' */
    /* Graphical Function 'SleepAllw': '<S6>:2186' */
    /* Transition: '<S6>:2188' */
    qY = SystemTickMs - /*MW:OvSatOk*/ BTK_Model_DWork.u32_SleepTime;
    if (qY > SystemTickMs)
    {
        qY = 0U;
    }

    if (qY > 1500U)
    {
        /* Transition: '<S6>:2195' */
        /* Transition: '<S6>:2196' */
        BTK_Model_B.VBTK_SleepAllw = BTK_TRUE;

        /* Transition: '<S6>:2202' */
        /* Transition: '<S6>:2205' */
    }
    else
    {
        /* Transition: '<S6>:2191' */
        if ((BTK_Model_DWork.VBTK_SleepAllw_pre == BTK_TRUE) &&
                (BTK_Model_B.VBTK_SleepAllw == BTK_FALSE))
        {
            /* DataStoreRead: '<S2>/Data Store Read2' */
            /* Transition: '<S6>:2199' */
            /* Transition: '<S6>:2201' */
            /* 更新时间戳 */
            BTK_Model_DWork.u32_SleepTime = SystemTickMs;

            /* Transition: '<S6>:2205' */
        }
        else
        {
            /* Transition: '<S6>:2204' */
        }
    }

    /* Transition: '<S6>:2207' */
    BTK_Model_DWork.VBTK_SleepAllw_pre = BTK_Model_B.VBTK_SleepAllw;
}

/* Function for Chart: '<S2>/BTK_StsteMachine' */
static void BTK_Model_ClearAllFlags(void)
{
    /* Graphical Function 'ClearAllFlags': '<S6>:2100' */
    /* Transition: '<S6>:2102' */
    /* 模式OFF跳转使能 */
    BTK_Model_DWork.bool_isBTKOFFDown_flg = BTK_FALSE;

    /* 触发模式OFF跳转使能 */
    BTK_Model_DWork.bool_OFFtoStartAllw = BTK_FALSE;
    BTK_Model_DWork.bool_OFFtoLVAllw = BTK_FALSE;
    BTK_Model_DWork.bool_OFFtoHVWOAllw = BTK_FALSE;
}

/* Function for Chart: '<S2>/BTK_StsteMachine' */
static void BTK_Model_StartDownAllw(const boolean_T *LogicalOperator13)
{
    /* Inport: '<Root>/INP' */
    /* Graphical Function 'StartDownAllw': '<S6>:2310' */
    /* Transition: '<S6>:2318' */
    if ((*LogicalOperator13) && (DIM_output.DIM_VehicleSpeed < 10))
    {
        /* Transition: '<S6>:2319' */
        /* Transition: '<S6>:2321' */
        BTK_Model_DWork.bool_STARTtoOFF = BTK_TRUE;
    }
    else
    {
        /* Transition: '<S6>:2320' */
        /* Transition: '<S6>:2417' */
    }

    /* End of Inport: '<Root>/INP' */
}

/* Function for Chart: '<S2>/BTK_StsteMachine' */
static void BTK_Mode_enter_internal_BTK_OFF(void)
{
    /* Entry Internal 'BTK_OFF': '<S6>:979' */
    /* Transition: '<S6>:981' */
    if (BTK_Model_DWork.bool_isBTKOFFDown_flg)
    {
        /* Transition: '<S6>:2420' */
        BTK_Model_DWork.is_BTK_OFF = BTK_Model_IN_BTK_OFF_Down;

        /* Entry 'BTK_OFF_Down': '<S6>:988' */
        BTK_Model_DWork.bool_BTK_OFF_Down_flg = BTK_FALSE;
        BTK_Model_DWork.bool_isBTKOFFDown_flg = BTK_FALSE;
        BTK_Model_ClearAllFlags();

        /* Entry Internal 'BTK_OFF_Down': '<S6>:988' */
        /* Transition: '<S6>:2252' */
        BTK_Model_DWork.is_BTK_OFF_Down = BTK_Model_IN_BTK_OFF_IGN_Break;

        /* DataStoreRead: '<S2>/Data Store Read2' */
        /* Entry 'BTK_OFF_IGN_Break': '<S6>:991' */
        BTK_Model_DWork.u32_sleepDelay_start = SystemTickMs;
    }
    else
    {
        /* Transition: '<S6>:2421' */
        BTK_Model_DWork.is_BTK_OFF = BTK_Model_IN_BTK_OFF_Waiting;

        /* Entry 'BTK_OFF_Waiting': '<S6>:1014' */
        BTK_Model_ClearAllFlags();

        /* DataStoreRead: '<S2>/Data Store Read2' */
        BTK_Model_DWork.u32_SleepTime = SystemTickMs;
        BTK_Model_SleepAllw();
    }
}

/* Function for Chart: '<S2>/BTK_StsteMachine' */
static void BTK_Model_HVWOtoSTART(const boolean_T *LogicalOperator13)
{
    /* Graphical Function 'HVWOtoSTART': '<S6>:2329' */
    /* Transition: '<S6>:2341' */
    if ((*LogicalOperator13) && BTK_Model_B.LogicalOperator2)
    {
        /* Transition: '<S6>:2342' */
        /* Transition: '<S6>:2344' */
        BTK_Model_DWork.bool_HVWOtoSTART = BTK_TRUE;
    }
    else
    {
        /* Transition: '<S6>:2343' */
        /* Transition: '<S6>:2415' */
    }
}

/* Function for Chart: '<S2>/BTK_StsteMachine' */
static void BTK_Model_HVWOtoOFF(void)
{
    /* Graphical Function 'HVWOtoOFF': '<S6>:2356' */
    /* Transition: '<S6>:2366' */
    /* Transition: '<S6>:2367' */
    /* Transition: '<S6>:2371' */
    BTK_Model_DWork.bool_HVtoOFF = BTK_TRUE;
    BTK_output.BTK_HVStatus = BTK_FALSE;
}

/* Function for Chart: '<S2>/BTK_StsteMachine' */
static void BTK_Model_LVUporDnAllw(const boolean_T *LogicalOperator13)
{
    uint32_T qY;

    /* DataStoreRead: '<S2>/Data Store Read2' */
    /* Graphical Function 'LVUporDnAllw': '<S6>:2380' */
    /* Transition: '<S6>:2388' */
    qY = SystemTickMs - /*MW:OvSatOk*/ BTK_Model_DWork.u32_StartTime;
    if (qY > SystemTickMs)
    {
        qY = 0U;
    }

    /* End of DataStoreRead: '<S2>/Data Store Read2' */
    if ((qY > KBTK_MaxTimeInOnState_ms) || (*LogicalOperator13))
    {
        /* Transition: '<S6>:2389' */
        if (BTK_Model_B.LogicalOperator2)
        {
            /* Transition: '<S6>:2405' */
            /* Transition: '<S6>:2409' */
            BTK_Model_DWork.bool_LVtoHV = BTK_TRUE;
        }
        else
        {
            /* Transition: '<S6>:2407' */
            BTK_Model_DWork.bool_LVtoOFF = BTK_TRUE;

            /* Transition: '<S6>:2413' */
        }
    }
    else
    {
        /* Transition: '<S6>:2390' */
        /* Transition: '<S6>:2403' */
        /* Transition: '<S6>:2413' */
    }
}

/* System initialize for atomic system: '<S1>/BTK_ACT_PEPS' */
void BTK_Model_BTK_ACT_PEPS_Init(void)
{
    /* InitializeConditions for Delay: '<S2>/Delay2' */
    BTK_Model_DWork.icLoad = 1U;

    /* SystemInitialize for Merge: '<S3>/Merge' */
    BTK_Model_B.Merge = false;

    /* SystemInitialize for Merge: '<S3>/Merge1' */
    BTK_Model_B.Merge1 = false;

    /* SystemInitialize for Merge: '<S3>/Merge2' */
    BTK_Model_B.Merge2 = false;

    /* SystemInitialize for Chart: '<S2>/BTK_StsteMachine' */
    BTK_Model_DWork.is_BTK_OFF = BTK_Model_IN_NO_ACTIVE_CHILD;
    BTK_Model_DWork.is_BTK_OFF_Down = BTK_Model_IN_NO_ACTIVE_CHILD;
    BTK_Model_DWork.is_active_c1_BTK_Model = 0U;
    BTK_Model_DWork.is_c1_BTK_Model = BTK_Model_IN_NO_ACTIVE_CHILD;
    BTK_Model_DWork.bool_isBTKOFFDown_flg = false;
    BTK_Model_DWork.u32_StartTime = 0U;
    BTK_Model_DWork.bool_BTK_OFF_Down_flg = false;
    BTK_Model_DWork.bool_LVtoOFF = false;
    BTK_Model_DWork.bool_HVtoOFF = false;
    BTK_Model_DWork.bool_LVtoHV = false;
    BTK_Model_DWork.bool_HVWOtoSTART = false;
    BTK_Model_DWork.bool_STARTtoOFF = false;
    BTK_Model_DWork.bool_OFFtoStartAllw = false;
    BTK_Model_DWork.bool_OFFtoLVAllw = false;
    BTK_Model_DWork.bool_OFFtoHVWOAllw = 0U;
    BTK_Model_DWork.u32_SleepTime = 0U;
    BTK_Model_DWork.VBTK_SleepAllw_pre = false;
    BTK_Model_DWork.u32_sleepDelay_start = 0U;
    BTK_Model_B.VBTK_PDU = 0U;
    BTK_output.BTK_SSBRedLed = false;
    BTK_output.BTK_SSBGreenLed = false;
    BTK_output.BTK_Ready = false;
    BTK_output.BTK_HVStatus = false;
    BTK_Model_B.VBTK_SleepAllw = false;
}

/* Output and update for atomic system: '<S1>/BTK_ACT_PEPS' */
void BTK_Model_BTK_ACT_PEPS(void)
{
    boolean_T rtb_Switch;
    boolean_T rtb_Switch1_c;
    uint32_T rtb_Add;

    /* Delay: '<S2>/Delay2' incorporates:
     *  DataStoreRead: '<S2>/Data Store Read1'
     */
    if (BTK_Model_DWork.icLoad != 0)
    {
        BTK_Model_DWork.Delay2_DSTATE = SystemTickMs;
    }

    /* Sum: '<S2>/Add' incorporates:
     *  DataStoreRead: '<S2>/Data Store Read1'
     *  Delay: '<S2>/Delay2'
     */
    rtb_Add = SystemTickMs - BTK_Model_DWork.Delay2_DSTATE;

    /* Outputs for Atomic SubSystem: '<S3>/BTK_Delay_Confirm' */
    /* Inport: '<Root>/INP' incorporates:
     *  Constant: '<S3>/Constant'
     *  Constant: '<S3>/Constant3'
     */
    BTK_Model_BTK_Delay_Confirm(DIM_output.DIM_SSB_Switch1,
        KBTK_SSBConfirmTime_ms, rtb_Add, &BTK_Model_B.BTK_Delay_Confirm,
        &BTK_Model_DWork.BTK_Delay_Confirm);

    /* End of Outputs for SubSystem: '<S3>/BTK_Delay_Confirm' */

    /* Outputs for Atomic SubSystem: '<S3>/BTK_Delay_Confirm1' */
    BTK_Model_BTK_Delay_Confirm(DIM_output.DIM_SSB_Switch2,
        KBTK_SSBConfirmTime_ms, rtb_Add, &BTK_Model_B.BTK_Delay_Confirm1,
        &BTK_Model_DWork.BTK_Delay_Confirm1);

    /* End of Outputs for SubSystem: '<S3>/BTK_Delay_Confirm1' */

    /* Outputs for Enabled SubSystem: '<S3>/Mechanical' incorporates:
     *  EnablePort: '<S9>/Enable'
     */
    /* RelationalOperator: '<S3>/Relational Operator' incorporates:
     *  Constant: '<S3>/Constant1'
     */
    if (1 == ((uint8_T)BTK_PMSC_MEK))
    {
        /* SignalConversion: '<S9>/OutportBuffer_InsertedFor_KeyTrgger_at_inport_0' incorporates:
         *  Constant: '<S9>/Constant1'
         */
        BTK_Model_B.Merge = BTK_FALSE;

        /* Outputs for Triggered SubSystem: '<S9>/ACC_Rise' incorporates:
         *  TriggerPort: '<S13>/Trigger'
         */
        if (BTK_Model_B.BTK_Delay_Confirm.debounce &&
                (BTK_Model_PrevZCSigState.ACC_Rise_Trig_ZCE != POS_ZCSIG))
        {
            /* DataStoreWrite: '<S13>/Data Store Write' incorporates:
             *  DataStoreRead: '<S13>/Data Store Read'
             */
            BTK_Model_DWork.AccUpStartTime_ms = SystemTickMs;
        }

        BTK_Model_PrevZCSigState.ACC_Rise_Trig_ZCE =
            BTK_Model_B.BTK_Delay_Confirm.debounce;

        /* End of Outputs for SubSystem: '<S9>/ACC_Rise' */

        /* Switch: '<S15>/Switch' incorporates:
         *  Constant: '<S15>/Constant'
         *  DataStoreRead: '<S15>/Data Store Read'
         *  DataStoreRead: '<S15>/Data Store Read1'
         *  Delay: '<S15>/Delay4'
         *  RelationalOperator: '<S15>/Relational Operator'
         *  Sum: '<S15>/Subtract'
         */
        if (SystemTickMs - BTK_Model_DWork.AccUpStartTime_ms <
                KBTK_MEKSigSynTime_ms)
        {
            rtb_Switch = BTK_Model_DWork.Delay4_DSTATE;
        }
        else
        {
            rtb_Switch = BTK_Model_B.BTK_Delay_Confirm.debounce;
        }

        /* End of Switch: '<S15>/Switch' */

        /* SignalConversion: '<S9>/OutportBufferForACC_out' */
        BTK_Model_B.Merge1 = rtb_Switch;

        /* Outputs for Triggered SubSystem: '<S9>/ON_Fall' incorporates:
         *  TriggerPort: '<S14>/Trigger'
         */
        if ((!BTK_Model_B.BTK_Delay_Confirm1.debounce) &&
                (BTK_Model_PrevZCSigState.ON_Fall_Trig_ZCE != ZERO_ZCSIG))
        {
            /* DataStoreWrite: '<S14>/Data Store Write' incorporates:
             *  DataStoreRead: '<S14>/Data Store Read'
             */
            BTK_Model_DWork.ONDnStartTime_ms = SystemTickMs;
        }

        BTK_Model_PrevZCSigState.ON_Fall_Trig_ZCE =
            BTK_Model_B.BTK_Delay_Confirm1.debounce;

        /* End of Outputs for SubSystem: '<S9>/ON_Fall' */

        /* Switch: '<S16>/Switch1' incorporates:
         *  Constant: '<S16>/Constant5'
         *  DataStoreRead: '<S16>/Data Store Read2'
         *  DataStoreRead: '<S16>/Data Store Read4'
         *  Delay: '<S16>/Delay3'
         *  RelationalOperator: '<S16>/Relational Operator6'
         *  Sum: '<S16>/Subtract1'
         */
        if (SystemTickMs - BTK_Model_DWork.ONDnStartTime_ms <
                KBTK_MEKSigSynTime_ms)
        {
            rtb_Switch1_c = BTK_Model_DWork.Delay3_DSTATE_c;
        }
        else
        {
            rtb_Switch1_c = BTK_Model_B.BTK_Delay_Confirm1.debounce;
        }

        /* End of Switch: '<S16>/Switch1' */

        /* SignalConversion: '<S9>/OutportBufferForON_Out' */
        BTK_Model_B.Merge2 = rtb_Switch1_c;

        /* Update for Delay: '<S15>/Delay4' */
        BTK_Model_DWork.Delay4_DSTATE = rtb_Switch;

        /* Update for Delay: '<S16>/Delay3' */
        BTK_Model_DWork.Delay3_DSTATE_c = rtb_Switch1_c;
    }

    /* End of RelationalOperator: '<S3>/Relational Operator' */
    /* End of Outputs for SubSystem: '<S3>/Mechanical' */

    /* Outputs for Enabled SubSystem: '<S4>/SSB_Trigger' incorporates:
     *  EnablePort: '<S30>/Enable'
     */
    /* Outputs for Enabled SubSystem: '<S3>/SSB_Sts ' incorporates:
     *  EnablePort: '<S10>/Enable'
     */
    /* RelationalOperator: '<S3>/Relational Operator1' incorporates:
     *  Constant: '<S10>/Constant'
     *  Constant: '<S10>/Constant1'
     *  Constant: '<S10>/Constant5'
     *  Constant: '<S3>/Constant2'
     *  Inport: '<S10>/BTK_SSB1Sts'
     *  Inport: '<S10>/BTK_SSB2Sts'
     *  Logic: '<S10>/Logical Operator5'
     *  RelationalOperator: '<S10>/Relational Operator1'
     */
    if (1 == ((uint8_T)BTK_PMSC_SSB))
    {
        /* Outputs for Atomic SubSystem: '<S10>/BTKSignalConfirm1' */
        BTK_Model_BTKSignalConfirm(BTK_Model_B.BTK_Delay_Confirm.debounce !=
            BTK_Model_B.BTK_Delay_Confirm1.debounce, KBTK_MaxSSBDiffTime_ms,
            rtb_Add, &BTK_Model_B.BTKSignalConfirm1,
            &BTK_Model_DWork.BTKSignalConfirm1);

        /* End of Outputs for SubSystem: '<S10>/BTKSignalConfirm1' */

        /* Outputs for Enabled SubSystem: '<S10>/Enabled Subsystem' incorporates:
         *  EnablePort: '<S27>/Enable'
         */
        if (BTK_Model_B.BTKSignalConfirm1.RelationalOperator3)
        {
            /* DataStoreWrite: '<S27>/Data Store Write' incorporates:
             *  Constant: '<S27>/Constant'
             */
            BTK_Model_DWork.bool_flag = true;
        }

        /* End of Outputs for SubSystem: '<S10>/Enabled Subsystem' */

        /* Outputs for Enabled SubSystem: '<S10>/Enabled Subsystem1' incorporates:
         *  EnablePort: '<S28>/Enable'
         */
        if ((!BTK_Model_B.BTK_Delay_Confirm.debounce) &&
                (!BTK_Model_B.BTK_Delay_Confirm1.debounce))
        {
            /* DataStoreWrite: '<S28>/Data Store Write' incorporates:
             *  Constant: '<S28>/Constant'
             */
            BTK_Model_DWork.bool_flag = false;
        }

        /* End of Outputs for SubSystem: '<S10>/Enabled Subsystem1' */

        /* Outputs for Atomic SubSystem: '<S10>/BTKSignalConfirm2' */
        BTK_Model_BTKSignalConfirm(BTK_Model_B.BTK_Delay_Confirm.debounce,
            KBTK_SSBAdhesionConfirmTime_ms, rtb_Add,
            &BTK_Model_B.BTKSignalConfirm2, &BTK_Model_DWork.BTKSignalConfirm2);

        /* End of Outputs for SubSystem: '<S10>/BTKSignalConfirm2' */

        /* Outputs for Atomic SubSystem: '<S10>/BTKSignalConfirm3' */
        BTK_Model_BTKSignalConfirm(BTK_Model_B.BTK_Delay_Confirm1.debounce,
            KBTK_SSBAdhesionConfirmTime_ms, rtb_Add,
            &BTK_Model_B.BTKSignalConfirm3, &BTK_Model_DWork.BTKSignalConfirm3);

        /* End of Outputs for SubSystem: '<S10>/BTKSignalConfirm3' */

        /* Logic: '<S10>/Logical Operator' incorporates:
         *  Constant: '<S10>/Constant'
         *  Constant: '<S10>/Constant1'
         *  Constant: '<S10>/Constant5'
         *  Inport: '<S10>/BTK_SSB1Sts'
         *  Inport: '<S10>/BTK_SSB2Sts'
         *  Logic: '<S10>/Logical Operator5'
         *  RelationalOperator: '<S10>/Relational Operator1'
         */
        SSB_Adhesion = (BTK_Model_B.BTKSignalConfirm2.RelationalOperator3 ||
                        BTK_Model_B.BTKSignalConfirm3.RelationalOperator3);

        /* Logic: '<S10>/Logical Operator1' */
        SSB_SyncCorrect = !BTK_Model_B.BTKSignalConfirm1.RelationalOperator3;

        /* SignalConversion: '<S10>/OutportBufferForSSB1_Out' incorporates:
         *  Inport: '<S10>/BTK_SSB1Sts'
         */
        BTK_Model_B.Merge1 = BTK_Model_B.BTK_Delay_Confirm.debounce;

        /* SignalConversion: '<S10>/OutportBufferForSSB2_OUt' incorporates:
         *  Inport: '<S10>/BTK_SSB2Sts'
         */
        BTK_Model_B.Merge2 = BTK_Model_B.BTK_Delay_Confirm1.debounce;

        /* Switch: '<S10>/Switch2' incorporates:
         *  Constant: '<S10>/Constant3'
         *  DataStoreRead: '<S10>/Data Store Read2'
         *  Delay: '<S10>/Delay3'
         *  Inport: '<S10>/BTK_SSB1Sts'
         *  Inport: '<S10>/BTK_SSB2Sts'
         *  Logic: '<S10>/Logical Operator10'
         *  Logic: '<S10>/Logical Operator7'
         *  Logic: '<S10>/Logical Operator9'
         *  RelationalOperator: '<S10>/Relational Operator5'
         */
        if (BTK_Model_B.BTK_Delay_Confirm.debounce &&
                BTK_Model_B.BTK_Delay_Confirm1.debounce &&
                (!BTK_Model_DWork.bool_flag))
        {
            rtb_Switch = true;
        }
        else
        {
            rtb_Switch = ((BTK_Model_B.BTK_Delay_Confirm.debounce !=
                           BTK_Model_B.BTK_Delay_Confirm1.debounce) &&
                          BTK_Model_DWork.Delay3_DSTATE_o);
        }

        /* End of Switch: '<S10>/Switch2' */

        /* SignalConversion: '<S10>/OutportBufferForSSB_Sts' */
        BTK_Model_B.Merge = rtb_Switch;

        /* Update for Delay: '<S10>/Delay3' */
        BTK_Model_DWork.Delay3_DSTATE_o = rtb_Switch;

        /* Logic: '<S30>/Logical Operator1' incorporates:
         *  Delay: '<S30>/Delay'
         *  Logic: '<S30>/Logical Operator'
         */
        BTK_Model_B.LogicalOperator1 = (BTK_Model_B.Merge &&
            (!BTK_Model_DWork.Delay_DSTATE));

        /* Logic: '<S30>/Logical Operator2' incorporates:
         *  Inport: '<Root>/INP'
         *  Logic: '<S30>/Logical Operator5'
         */
        BTK_Model_B.LogicalOperator2 = (BTK_Model_B.Merge &&
            DIM_output.DIM_BrkLightSwitchActive_flg);

        /* Logic: '<S30>/Logical Operator3' incorporates:
         *  Inport: '<Root>/INP'
         *  Logic: '<S30>/Logical Operator4'
         *  Logic: '<S30>/Logical Operator6'
         */
        BTK_Model_B.LogicalOperator3 = ((BTK_Model_ConstB.LogicalOperator7 ||
            (!DIM_output.DIM_BrkLightSwitchActive_flg)) && BTK_Model_B.Merge);

        /* Update for Delay: '<S30>/Delay' */
        BTK_Model_DWork.Delay_DSTATE = BTK_Model_B.Merge;
    }

    /* End of RelationalOperator: '<S3>/Relational Operator1' */
    /* End of Outputs for SubSystem: '<S3>/SSB_Sts ' */
    /* End of Outputs for SubSystem: '<S4>/SSB_Trigger' */

    /* Outputs for Enabled SubSystem: '<S4>/MEK_Trigger' incorporates:
     *  EnablePort: '<S29>/Enable'
     */
    /* RelationalOperator: '<S4>/Relational Operator' incorporates:
     *  Constant: '<S4>/Constant1'
     */
    if (1 == ((uint8_T)BTK_PMSC_MEK))
    {
        /* Logic: '<S29>/Logical Operator7' incorporates:
         *  Constant: '<S29>/Constant1'
         *  Constant: '<S29>/Constant2'
         *  Constant: '<S29>/Constant3'
         *  Constant: '<S29>/Constant4'
         *  Delay: '<S2>/Delay3'
         *  Logic: '<S29>/Logical Operator1'
         *  Logic: '<S29>/Logical Operator2'
         *  Logic: '<S29>/Logical Operator3'
         *  Logic: '<S29>/Logical Operator4'
         *  Logic: '<S29>/Logical Operator5'
         *  Logic: '<S29>/Logical Operator6'
         *  Logic: '<S29>/Logical Operator8'
         *  Logic: '<S29>/Logical Operator9'
         *  RelationalOperator: '<S29>/Relational Operator2'
         *  RelationalOperator: '<S29>/Relational Operator3'
         *  RelationalOperator: '<S29>/Relational Operator4'
         *  RelationalOperator: '<S29>/Relational Operator5'
         */
        BTK_Model_B.LogicalOperator7 = ((((3 == BTK_Model_B.VBTK_PDU) ||
            (BTK_Model_B.VBTK_PDU == 0)) && (BTK_Model_B.Merge2 ||
            BTK_Model_B.Merge1)) || ((BTK_Model_B.VBTK_PDU == 1) &&
            ((!BTK_Model_B.Merge1) || BTK_Model_B.Merge2)) ||
            ((BTK_Model_B.VBTK_PDU == 4) && (!BTK_Model_B.Merge2)));
    }

    /* End of RelationalOperator: '<S4>/Relational Operator' */
    /* End of Outputs for SubSystem: '<S4>/MEK_Trigger' */

    /* Logic: '<S4>/Logical Operator13' */
    rtb_Switch = (BTK_Model_B.LogicalOperator7 || BTK_Model_B.LogicalOperator1);

    /* Chart: '<S2>/BTK_StsteMachine' incorporates:
     *  DataStoreRead: '<S2>/Data Store Read2'
     */
    /* Gateway: BTK_Module/BTK_ACT_PEPS/BTK_StsteMachine */
    /* During: BTK_Module/BTK_ACT_PEPS/BTK_StsteMachine */
    if (BTK_Model_DWork.is_active_c1_BTK_Model == 0U)
    {
        /* Entry: BTK_Module/BTK_ACT_PEPS/BTK_StsteMachine */
        BTK_Model_DWork.is_active_c1_BTK_Model = 1U;

        /* Entry Internal: BTK_Module/BTK_ACT_PEPS/BTK_StsteMachine */
        /* Transition: '<S6>:1138' */
        BTK_Model_DWork.is_c1_BTK_Model = BTK_Model_IN_BTK_OFF;

        /* Entry 'BTK_OFF': '<S6>:979' */
        BTK_Model_DWork.u32_SleepTime = 0U;
        BTK_Model_DWork.VBTK_SleepAllw_pre = false;
        BTK_Model_DWork.u32_sleepDelay_start = 0U;

        /* en: VBTK_PDU = BTK_PDU_OFF; */
        BTK_output.BTK_SSBRedLed = BTK_FALSE;
        BTK_output.BTK_SSBGreenLed = BTK_FALSE;
        BTK_Model_B.VBTK_PDU = ((uint8_T)BTK_PDU_OFF_WO);
        BTK_Mode_enter_internal_BTK_OFF();
    }
    else
    {
        switch (BTK_Model_DWork.is_c1_BTK_Model)
        {
          case BTK_Model_IN_BTK_HV_START:
            BTK_Model_B.VBTK_PDU = ((uint8_T)BTK_PDU_START_DRIVE);

            /* During 'BTK_HV_START': '<S6>:2309' */
            if (BTK_Model_DWork.bool_STARTtoOFF)
            {
                /* Transition: '<S6>:2307' */
                BTK_Model_DWork.bool_isBTKOFFDown_flg = BTK_TRUE;

                /* Exit 'BTK_HV_START': '<S6>:2309' */
                BTK_output.BTK_Ready = BTK_FALSE;
                BTK_output.BTK_HVStatus = BTK_FALSE;
                BTK_Model_DWork.is_c1_BTK_Model = BTK_Model_IN_BTK_OFF;

                /* Entry 'BTK_OFF': '<S6>:979' */
                BTK_Model_DWork.u32_SleepTime = 0U;
                BTK_Model_DWork.VBTK_SleepAllw_pre = false;
                BTK_Model_DWork.u32_sleepDelay_start = 0U;

                /* en: VBTK_PDU = BTK_PDU_OFF; */
                BTK_output.BTK_SSBRedLed = BTK_FALSE;
                BTK_output.BTK_SSBGreenLed = BTK_FALSE;
                BTK_Model_B.VBTK_PDU = ((uint8_T)BTK_PDU_OFF_WO);
                BTK_Mode_enter_internal_BTK_OFF();
            }
            else
            {
                /* 用户意图切换电源模式 */
                BTK_Model_StartDownAllw(&rtb_Switch);
            }
            break;

          case BTK_Model_IN_BTK_HV_Without:
            BTK_Model_B.VBTK_PDU = ((uint8_T)BTK_PDU_HV_ACTIVE_WO);

            /* During 'BTK_HV_Without': '<S6>:2328' */
            if (BTK_Model_DWork.bool_HVWOtoSTART)
            {
                /* Transition: '<S6>:2306' */
                /* Exit 'BTK_HV_Without': '<S6>:2328' */
                BTK_output.BTK_SSBRedLed = BTK_FALSE;
                BTK_Model_DWork.is_c1_BTK_Model = BTK_Model_IN_BTK_HV_START;

                /* Entry 'BTK_HV_START': '<S6>:2309' */
                BTK_Model_B.VBTK_PDU = ((uint8_T)BTK_PDU_START_DRIVE);
                BTK_output.BTK_SSBGreenLed = BTK_TRUE;
                BTK_Model_DWork.bool_STARTtoOFF = BTK_FALSE;
                BTK_Model_DWork.bool_OFFtoStartAllw = BTK_FALSE;
                BTK_Model_DWork.bool_LVtoHV = BTK_FALSE;
                BTK_Model_DWork.bool_HVWOtoSTART = BTK_FALSE;
                BTK_output.BTK_Ready = BTK_TRUE;
                BTK_output.BTK_HVStatus = BTK_TRUE;
            }
            else if (BTK_Model_DWork.bool_HVtoOFF)
            {
                /* Transition: '<S6>:2397' */
                BTK_Model_DWork.bool_isBTKOFFDown_flg = BTK_TRUE;

                /* Exit 'BTK_HV_Without': '<S6>:2328' */
                BTK_Model_DWork.is_c1_BTK_Model = BTK_Model_IN_BTK_OFF;

                /* Entry 'BTK_OFF': '<S6>:979' */
                BTK_Model_DWork.u32_SleepTime = 0U;
                BTK_Model_DWork.VBTK_SleepAllw_pre = false;
                BTK_Model_DWork.u32_sleepDelay_start = 0U;

                /* en: VBTK_PDU = BTK_PDU_OFF; */
                BTK_output.BTK_SSBRedLed = BTK_FALSE;
                BTK_output.BTK_SSBGreenLed = BTK_FALSE;
                BTK_Model_B.VBTK_PDU = ((uint8_T)BTK_PDU_OFF_WO);
                BTK_Mode_enter_internal_BTK_OFF();
            }
            else
            {
                BTK_Model_HVWOtoSTART(&rtb_Switch);
                BTK_Model_HVWOtoOFF();
            }
            break;

          case BTK_Model_IN_BTK_LV_A:
            BTK_Model_B.VBTK_PDU = ((uint8_T)BTK_PDU_LV_W);

            /* During 'BTK_LV_A': '<S6>:2379' */
            if (BTK_Model_DWork.bool_LVtoOFF)
            {
                /* Transition: '<S6>:2378' */
                BTK_Model_DWork.bool_isBTKOFFDown_flg = BTK_TRUE;

                /* Exit 'BTK_LV_A': '<S6>:2379' */
                BTK_Model_DWork.is_c1_BTK_Model = BTK_Model_IN_BTK_OFF;

                /* Entry 'BTK_OFF': '<S6>:979' */
                BTK_Model_DWork.u32_SleepTime = 0U;
                BTK_Model_DWork.VBTK_SleepAllw_pre = false;
                BTK_Model_DWork.u32_sleepDelay_start = 0U;

                /* en: VBTK_PDU = BTK_PDU_OFF; */
                BTK_output.BTK_SSBRedLed = BTK_FALSE;
                BTK_output.BTK_SSBGreenLed = BTK_FALSE;
                BTK_Model_B.VBTK_PDU = ((uint8_T)BTK_PDU_OFF_WO);
                BTK_Mode_enter_internal_BTK_OFF();
            }
            else if (BTK_Model_DWork.bool_LVtoHV)
            {
                /* Transition: '<S6>:2304' */
                /* Exit 'BTK_LV_A': '<S6>:2379' */
                BTK_output.BTK_SSBRedLed = BTK_FALSE;
                BTK_Model_DWork.is_c1_BTK_Model = BTK_Model_IN_BTK_HV_START;

                /* Entry 'BTK_HV_START': '<S6>:2309' */
                BTK_Model_B.VBTK_PDU = ((uint8_T)BTK_PDU_START_DRIVE);
                BTK_output.BTK_SSBGreenLed = BTK_TRUE;
                BTK_Model_DWork.bool_STARTtoOFF = BTK_FALSE;
                BTK_Model_DWork.bool_OFFtoStartAllw = BTK_FALSE;
                BTK_Model_DWork.bool_LVtoHV = BTK_FALSE;
                BTK_Model_DWork.bool_HVWOtoSTART = BTK_FALSE;
                BTK_output.BTK_Ready = BTK_TRUE;
                BTK_output.BTK_HVStatus = BTK_TRUE;
            }
            else
            {
                /* 用户触发电源模式切换，LV向其他电源档位跳转判断函数 */
                BTK_Model_LVUporDnAllw(&rtb_Switch);
            }
            break;

          default:
            BTK_Model_B.VBTK_PDU = ((uint8_T)BTK_PDU_OFF_WO);

            /* During 'BTK_OFF': '<S6>:979' */
            if (BTK_Model_DWork.bool_OFFtoLVAllw)
            {
                /* Transition: '<S6>:2303' */
                /* Exit Internal 'BTK_OFF': '<S6>:979' */
                if (BTK_Model_DWork.is_BTK_OFF == BTK_Model_IN_BTK_OFF_Waiting)
                {
                    /* Exit 'BTK_OFF_Waiting': '<S6>:1014' */
                    BTK_Model_B.VBTK_SleepAllw = BTK_FALSE;
                    BTK_Model_DWork.is_BTK_OFF = BTK_Model_IN_NO_ACTIVE_CHILD;
                }
                else
                {
                    /* Exit Internal 'BTK_OFF_Down': '<S6>:988' */
                    BTK_Model_DWork.is_BTK_OFF_Down =
                        BTK_Model_IN_NO_ACTIVE_CHILD;
                    BTK_Model_DWork.is_BTK_OFF = BTK_Model_IN_NO_ACTIVE_CHILD;
                }

                BTK_Model_DWork.is_c1_BTK_Model = BTK_Model_IN_BTK_LV_A;

                /* Entry 'BTK_LV_A': '<S6>:2379' */
                BTK_Model_DWork.bool_OFFtoLVAllw = BTK_FALSE;
                BTK_Model_B.VBTK_PDU = ((uint8_T)BTK_PDU_LV_W);
                BTK_output.BTK_SSBRedLed = BTK_TRUE;
                BTK_Model_DWork.bool_LVtoHV = BTK_FALSE;
                BTK_Model_DWork.bool_LVtoOFF = BTK_FALSE;
            }
            else if (BTK_Model_DWork.bool_OFFtoStartAllw)
            {
                /* Transition: '<S6>:2305' */
                /* Exit Internal 'BTK_OFF': '<S6>:979' */
                if (BTK_Model_DWork.is_BTK_OFF == BTK_Model_IN_BTK_OFF_Waiting)
                {
                    /* Exit 'BTK_OFF_Waiting': '<S6>:1014' */
                    BTK_Model_B.VBTK_SleepAllw = BTK_FALSE;
                    BTK_Model_DWork.is_BTK_OFF = BTK_Model_IN_NO_ACTIVE_CHILD;
                }
                else
                {
                    /* Exit Internal 'BTK_OFF_Down': '<S6>:988' */
                    BTK_Model_DWork.is_BTK_OFF_Down =
                        BTK_Model_IN_NO_ACTIVE_CHILD;
                    BTK_Model_DWork.is_BTK_OFF = BTK_Model_IN_NO_ACTIVE_CHILD;
                }

                BTK_Model_DWork.is_c1_BTK_Model = BTK_Model_IN_BTK_HV_START;

                /* Entry 'BTK_HV_START': '<S6>:2309' */
                BTK_Model_B.VBTK_PDU = ((uint8_T)BTK_PDU_START_DRIVE);
                BTK_output.BTK_SSBGreenLed = BTK_TRUE;
                BTK_Model_DWork.bool_STARTtoOFF = BTK_FALSE;
                BTK_Model_DWork.bool_OFFtoStartAllw = BTK_FALSE;
                BTK_Model_DWork.bool_LVtoHV = BTK_FALSE;
                BTK_Model_DWork.bool_HVWOtoSTART = BTK_FALSE;
                BTK_output.BTK_Ready = BTK_TRUE;
                BTK_output.BTK_HVStatus = BTK_TRUE;
            }
            else if (BTK_Model_DWork.bool_OFFtoHVWOAllw != 0U)
            {
                /* Transition: '<S6>:2398' */
                /* Exit Internal 'BTK_OFF': '<S6>:979' */
                if (BTK_Model_DWork.is_BTK_OFF == BTK_Model_IN_BTK_OFF_Waiting)
                {
                    /* Exit 'BTK_OFF_Waiting': '<S6>:1014' */
                    BTK_Model_B.VBTK_SleepAllw = BTK_FALSE;
                    BTK_Model_DWork.is_BTK_OFF = BTK_Model_IN_NO_ACTIVE_CHILD;
                }
                else
                {
                    /* Exit Internal 'BTK_OFF_Down': '<S6>:988' */
                    BTK_Model_DWork.is_BTK_OFF_Down =
                        BTK_Model_IN_NO_ACTIVE_CHILD;
                    BTK_Model_DWork.is_BTK_OFF = BTK_Model_IN_NO_ACTIVE_CHILD;
                }

                BTK_Model_DWork.is_c1_BTK_Model = BTK_Model_IN_BTK_HV_Without;

                /* Entry 'BTK_HV_Without': '<S6>:2328' */
                BTK_Model_B.VBTK_PDU = ((uint8_T)BTK_PDU_HV_ACTIVE_WO);
                BTK_output.BTK_SSBRedLed = BTK_TRUE;
                BTK_Model_DWork.bool_HVWOtoSTART = BTK_FALSE;
                BTK_Model_DWork.bool_HVtoOFF = BTK_FALSE;
                BTK_Model_DWork.bool_OFFtoHVWOAllw = BTK_FALSE;
                BTK_output.BTK_HVStatus = BTK_TRUE;
            }
            else if (BTK_Model_DWork.is_BTK_OFF == BTK_Model_IN_BTK_OFF_Down)
            {
                /* During 'BTK_OFF_Down': '<S6>:988' */
                if (BTK_Model_DWork.bool_BTK_OFF_Down_flg)
                {
                    /* Transition: '<S6>:984' */
                    BTK_Model_B.VBTK_SleepAllw = BTK_TRUE;

                    /* Exit Internal 'BTK_OFF_Down': '<S6>:988' */
                    BTK_Model_DWork.is_BTK_OFF_Down =
                        BTK_Model_IN_NO_ACTIVE_CHILD;
                    BTK_Model_DWork.is_BTK_OFF = BTK_Model_IN_BTK_OFF_Waiting;

                    /* Entry 'BTK_OFF_Waiting': '<S6>:1014' */
                    BTK_Model_ClearAllFlags();
                    BTK_Model_DWork.u32_SleepTime = SystemTickMs;
                    BTK_Model_SleepAllw();
                }
                else
                {
                    BTK_Model_OFFUpSSBTrigger(&rtb_Switch);
                    if (BTK_Model_DWork.is_BTK_OFF_Down ==
                            BTK_Model_IN_BTK_OFF_IGN_Break)
                    {
                        /* During 'BTK_OFF_IGN_Break': '<S6>:991' */
                        rtb_Add = SystemTickMs - /*MW:OvSatOk*/
                            BTK_Model_DWork.u32_sleepDelay_start;
                        if (rtb_Add > SystemTickMs)
                        {
                            rtb_Add = 0U;
                        }

                        if (rtb_Add > 6000U)
                        {
                            /* Transition: '<S6>:2301' */
                            BTK_Model_DWork.is_BTK_OFF_Down =
                                BTK_Model_IN_BTK_OFF_SLEEP_IN_W;

                            /* Entry 'BTK_OFF_SLEEP_IN_W': '<S6>:2300' */
                            /* sleeping is allowed after 60s in OFF_W mode */
                            BTK_Model_DWork.bool_BTK_OFF_Down_flg = BTK_TRUE;
                        }
                    }
                    else
                    {
                        /* During 'BTK_OFF_SLEEP_IN_W': '<S6>:2300' */
                    }
                }
            }
            else
            {
                /* During 'BTK_OFF_Waiting': '<S6>:1014' */
                BTK_Model_OFFUpSSBTrigger(&rtb_Switch);
                BTK_Model_SleepAllw();
            }
            break;
        }
    }

    /* End of Chart: '<S2>/BTK_StsteMachine' */

    /* Update for Delay: '<S2>/Delay2' incorporates:
     *  DataStoreRead: '<S2>/Data Store Read1'
     */
    BTK_Model_DWork.icLoad = 0U;
    BTK_Model_DWork.Delay2_DSTATE = SystemTickMs;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

/*
 * File: BTK_ACT_PEPS.h
 *
 * Code generated for Simulink model 'BTK_Model'.
 *
 * Model version                  : 1.4445
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Fri Mar 18 15:41:24 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Freescale->32-bit PowerPC
 * Code generation objectives:
 *    1. RAM efficiency
 *    2. ROM efficiency
 *    3. Execution efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_BTK_ACT_PEPS_h_
#define RTW_HEADER_BTK_ACT_PEPS_h_
#ifndef BTK_Model_COMMON_INCLUDES_
# define BTK_Model_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#endif                                 /* BTK_Model_COMMON_INCLUDES_ */

#include "BTK_Model_types.h"

/* Child system includes */
#include "BTK_lib.h"

/* Block signals for system '<S2>/BTK_A_KeyAuth' */
typedef struct
{
    boolean_T KeyAuthSucc_flg;         /* '<S6>/Logical Operator12' */
    boolean_T Switch;                  /* '<S27>/Switch' */
    boolean_T LogicalOperator12;       /* '<S26>/Logical Operator12' */
    rtB_BTK_Delay_Confirm_BTK_Mod_T BTK_Delay_Confirm;/* '<S27>/BTK_Delay_Confirm' */
}
rtB_BTK_A_KeyAuth_BTK_Model_T;

/* Block states (auto storage) for system '<S2>/BTK_A_KeyAuth' */
typedef struct
{
    rtDW_BTK_Delay_Confirm_BTK_Mo_T BTK_Delay_Confirm;/* '<S27>/BTK_Delay_Confirm' */
}
rtDW_BTK_A_KeyAuth_BTK_Model_T;

/* Block signals for system '<S2>/BTK_C_HVtoDown' */
typedef struct
{
    boolean_T LogicalOperator;         /* '<S12>/Logical Operator' */
    boolean_T LogicalOperator1;        /* '<S12>/Logical Operator1' */
    boolean_T LogicalOperator22;       /* '<S58>/Logical Operator22' */
    boolean_T LogicalOperator6;        /* '<S58>/Logical Operator6' */
    boolean_T LogicalOperator2;        /* '<S57>/Logical Operator2' */
    boolean_T OutportBufferForisDowntoLV;/* '<S57>/Constant1' */
    boolean_T Constant1;               /* '<S57>/Constant1' */
}
rtB_BTK_C_HVtoDown_BTK_Model_T;

/* Block signals for system '<S2>/BTK_C_LVUporDown' */
typedef struct
{
    real_T Switch1;                    /* '<S61>/Switch1' */
    boolean_T LogicalOperator;         /* '<S13>/Logical Operator' */
    boolean_T LogicalOperator1;        /* '<S13>/Logical Operator1' */
    boolean_T LogicalOperator3;        /* '<S61>/Logical Operator3' */
    boolean_T LogicalOperator4;        /* '<S60>/Logical Operator4' */
    boolean_T LogicalOperator6;        /* '<S60>/Logical Operator6' */
}
rtB_BTK_C_LVUporDown_BTK_Mode_T;

extern void BTK_Model_BTK_A_KeyAuth(boolean_T rtu_VBTK_SSB1_ACC_Sts, boolean_T
    rtu_VBTK_SSB2_ON_Sts, uint8_T rtu_C_PMSC_En_in, uint8_T
    rtu_VPEPS_Result_enum, uint32_T rtu_SimpleTime_in,
    rtB_BTK_A_KeyAuth_BTK_Model_T *localB, rtDW_BTK_A_KeyAuth_BTK_Model_T
    *localDW);
extern void BTK_Model_BTK_C_HVtoDown_Init(rtB_BTK_C_HVtoDown_BTK_Model_T *localB);
extern void BTK_Model_BTK_C_HVtoDown_Start(rtB_BTK_C_HVtoDown_BTK_Model_T
    *localB);
extern void BTK_Model_BTK_C_HVtoDown(boolean_T rtu_bool_BTKHVtoDownAllw, uint8_T
    rtu_C_PMS_En, boolean_T rtu_VDHP_NormalPowerDownReq_flg, boolean_T
    rtu_UDSReq_flg, boolean_T rtu_BTK_HV_Req, real32_T rtu_VehicleSpeed_kmph_in,
    uint8_T rtu_VBTK_PDU_in, boolean_T rtu_Key_ACC, boolean_T rtu_Key_ON,
    boolean_T rtu_SSBSts, uint8_T rtu_C_PMSC_En_Opt, boolean_T rtu_ChrgReq_Flg,
    boolean_T rtu_WODrv_flg, rtB_BTK_C_HVtoDown_BTK_Model_T *localB);
extern void BTK_Model_BTK_C_LVUporDown(boolean_T rtu_bool_BTKLVtoUporDownAllw,
    uint8_T rtu_C_PMS_En, boolean_T rtu_SSBBrkBothValid, boolean_T
    rtu_SSBValidOnly, boolean_T rtu_VDHP_NormalPowerDownReq_flg, boolean_T
    rtu_KeyAuthSucc_flg, boolean_T rtu_Key_ON, boolean_T rtu_ChrgReq_Flg,
    boolean_T rtu_SSBSts, boolean_T rtu_Key_ACC, uint8_T rtu_C_PMSC_En_Opt,
    rtB_BTK_C_LVUporDown_BTK_Mode_T *localB);
extern void BT_EnabledandTriggeredSubsystem(void);
extern void B_EnabledandTriggeredSubsystem1(void);
extern void BTK_Model_SSB(void);
extern void BTK_Model_WODriver_Confirm(void);
extern void BTK_Model_BTK_ACT_PEPS_Init(void);
extern void BTK_Model_BTK_ACT_PEPS_Enable(void);
extern void BTK_Model_BTK_ACT_PEPS_Start(void);
extern void BTK_Model_BTK_ACT_PEPS_Disable(void);
extern void BTK_Model_BTK_ACT_PEPS(void);

#endif                                 /* RTW_HEADER_BTK_ACT_PEPS_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

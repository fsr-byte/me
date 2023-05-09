/*
 * File: BTK_Model.h
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

#ifndef RTW_HEADER_BTK_Model_h_
#define RTW_HEADER_BTK_Model_h_
#include <stddef.h>
#include <string.h>
#ifndef BTK_Model_COMMON_INCLUDES_
# define BTK_Model_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#endif                                 /* BTK_Model_COMMON_INCLUDES_ */

#include "BTK_Model_types.h"

/* Child system includes */
#include "BTK_ACT_PEPS.h"

/* Includes for objects with custom storage classes. */
#include "BTK_Cal_Data.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* user code (top of header file) */
#include "derivative.h"

/* Block signals (auto storage) */
typedef struct
{
    uint32_T Add;                      /* '<S2>/Add' */
    uint8_T BTK_PDU;                   /* '<S1>/Merge' */
    uint8_T Delay3;                    /* '<S2>/Delay3' */
    uint8_T VBTK_PDU;                  /* '<S2>/BTK_StsteMachine' */
    uint8_T VBTK_ESCLOperReq;          /* '<S2>/BTK_StsteMachine' */
    uint8_T VBTK_Auth_Req;             /* '<S2>/BTK_StsteMachine' */
    uint8_T VBTK_remind;               /* '<S2>/BTK_StsteMachine' */
    boolean_T RelationalOperator2;     /* '<S1>/Relational Operator2' */
    boolean_T RelationalOperator1;     /* '<S1>/Relational Operator1' */
    boolean_T BTK_ACChrg_flg;          /* '<S1>/Merge1' */
    boolean_T BTK_DCChrg_flg;          /* '<S1>/Merge2' */
    boolean_T BTK_RemoteHVACReq;       /* '<S1>/Merge3' */
    boolean_T BTK_IChrgReq;            /* '<S1>/Merge4' */
    boolean_T Merge1;                  /* '<S8>/Merge1' */
    boolean_T Merge2;                  /* '<S8>/Merge2' */
    boolean_T Merge;                   /* '<S8>/Merge' */
    boolean_T LogicalOperator13;       /* '<S9>/Logical Operator13' */
    boolean_T LogicalOperator2;        /* '<S64>/Logical Operator2' */
    boolean_T LogicalOperator;         /* '<S14>/Logical Operator' */
    boolean_T Switch15_p;              /* '<S18>/Switch15' */
    boolean_T Switch15_f;              /* '<S19>/Switch15' */
    boolean_T RelationalOperator1_m;   /* '<S20>/Relational Operator1' */
    boolean_T LogicalOperator_n;       /* '<S20>/Logical Operator' */
    boolean_T LogicalOperator1;        /* '<S20>/Logical Operator1' */
    boolean_T WODriver_Flg;            /* '<S92>/Data Store Read' */
    boolean_T WDriver_Flg;             /* '<S92>/Logical Operator3' */
    boolean_T LogicalOperator2_n;      /* '<S92>/Logical Operator2' */
    boolean_T Switch1;                 /* '<S91>/Switch1' */
    boolean_T LogicalOperator_l;       /* '<S91>/Logical Operator' */
    boolean_T VBTK_SSBRedLed;          /* '<S2>/BTK_StsteMachine' */
    boolean_T VBTK_OFF_StartDiag_flag; /* '<S2>/BTK_StsteMachine' */
    boolean_T VBTK_SleepAllw;          /* '<S2>/BTK_StsteMachine' */
    boolean_T bool_ESCLUnlock_flg;     /* '<S2>/BTK_StsteMachine' */
    boolean_T bool_out_BTKHVtoDownAllw;/* '<S2>/BTK_StsteMachine' */
    boolean_T bool_out_BTKLVtoUporDownAllw;/* '<S2>/BTK_StsteMachine' */
    boolean_T LogicalOperator1_p;      /* '<S54>/Logical Operator1' */
    boolean_T LogicalOperator2_h;      /* '<S54>/Logical Operator2' */
    boolean_T LogicalOperator3;        /* '<S54>/Logical Operator3' */
    boolean_T LogicalOperator7;        /* '<S53>/Logical Operator7' */
    rtB_BTK_Delay_Confirm_BTK_Mod_T BTK_Delay_Confirm_c;/* '<S91>/BTK_Delay_Confirm' */
    rtB_BTK_C_LVUporDown_BTK_Mode_T BTK_C_LVUporDown;/* '<S2>/BTK_C_LVUporDown' */
    rtB_BTK_C_HVtoDown_BTK_Model_T BTK_C_HVtoDown;/* '<S2>/BTK_C_HVtoDown' */
    rtB_BTKSignalConfirm_BTK_Mode_T BTKSignalConfirm1_n;/* '<S11>/BTKSignalConfirm1' */
    rtB_BTKTimeoutCustomTimer_BTK_T BTKTimeoutCustomTimer;/* '<S10>/BTKTimeoutCustomTimer' */
    rtB_BTK_Delay_Confirm_BTK_Mod_T BTK_Delay_Confirm_ho;/* '<S67>/BTK_Delay_Confirm' */
    rtB_BTK_Delay_Confirm_BTK_Mod_T BTK_Delay_Confirm_d;/* '<S66>/BTK_Delay_Confirm' */
    rtB_BTK_Delay_Confirm_BTK_Mod_T BTK_Delay_Confirm_o;/* '<S73>/BTK_Delay_Confirm' */
    rtB_BTK_Delay_Confirm_BTK_Mod_T BTK_Delay_Confirm_h;/* '<S68>/BTK_Delay_Confirm' */
    rtB_BTKSignalConfirm_BTK_Mode_T BTKSignalConfirm3_e;/* '<S34>/BTKSignalConfirm3' */
    rtB_BTKSignalConfirm_BTK_Mode_T BTKSignalConfirm2_d;/* '<S34>/BTKSignalConfirm2' */
    rtB_BTKSignalConfirm_BTK_Mode_T BTKSignalConfirm1_h;/* '<S34>/BTKSignalConfirm1' */
    rtB_BTK_Delay_Confirm_BTK_Mod_T BTK_Delay_Confirm1;/* '<S8>/BTK_Delay_Confirm1' */
    rtB_BTK_Delay_Confirm_BTK_Mod_T BTK_Delay_Confirm;/* '<S8>/BTK_Delay_Confirm' */
    rtB_BTK_A_KeyAuth_BTK_Model_T BTK_A_KeyAuth;/* '<S2>/BTK_A_KeyAuth' */
    rtB_BTKSignalConfirm_BTK_Mode_T BTKSignalConfirm3;/* '<S5>/BTKSignalConfirm3' */
    rtB_BTKSignalConfirm_BTK_Mode_T BTKSignalConfirm2;/* '<S5>/BTKSignalConfirm2' */
    rtB_BTKSignalConfirm_BTK_Mode_T BTKSignalConfirm1;/* '<S5>/BTKSignalConfirm1' */
    rtB_BTKSignalConfirm_BTK_Mode_T BTKSignalConfirm;/* '<S5>/BTKSignalConfirm' */
}
BlockIO_BTK_Model_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct
{
    uint32_T Delay2_DSTATE;            /* '<S2>/Delay2' */
    int32_T u32_timeTmp;               /* '<S7>/Chart' */
    uint32_T u32_StartTime;            /* '<S2>/BTK_StsteMachine' */
    uint32_T u32_timeTemp;             /* '<S2>/BTK_StsteMachine' */
    uint32_T bool_OFFtoHVWOAllw;       /* '<S2>/BTK_StsteMachine' */
    uint32_T u32_timeStart_HVReq;      /* '<S2>/BTK_StsteMachine' */
    uint32_T u32_timeStart_UDS;        /* '<S2>/BTK_StsteMachine' */
    uint32_T u32_SleepTime;            /* '<S2>/BTK_StsteMachine' */
    uint32_T u32_sleepDelay_start;     /* '<S2>/BTK_StsteMachine' */
    uint32_T u32_ESCLUnlock_TimeStart; /* '<S2>/BTK_StsteMachine' */
    uint32_T AccUpStartTime_ms;        /* '<S33>/Data Store Memory' */
    uint32_T ONDnStartTime_ms;         /* '<S33>/Data Store Memory1' */
    uint8_T Delay3_DSTATE;             /* '<S2>/Delay3' */
    uint8_T Delay_DSTATE;              /* '<S4>/Delay' */
    uint8_T Delay_DSTATE_o;            /* '<S7>/Delay' */
    uint8_T Delay1_DSTATE;             /* '<S7>/Delay1' */
    uint8_T Delay_DSTATE_om;           /* '<S95>/Delay' */
    boolean_T Delay1_DSTATE_a;         /* '<S2>/Delay1' */
    boolean_T Delay_DSTATE_b;          /* '<S54>/Delay' */
    boolean_T Delay3_DSTATE_o;         /* '<S34>/Delay3' */
    boolean_T Delay4_DSTATE;           /* '<S39>/Delay4' */
    boolean_T Delay3_DSTATE_c;         /* '<S40>/Delay3' */
    uint8_T icLoad;                    /* '<S2>/Delay2' */
    uint8_T is_active_c1_BTK_Model;    /* '<S2>/BTK_StsteMachine' */
    uint8_T is_c1_BTK_Model;           /* '<S2>/BTK_StsteMachine' */
    uint8_T is_BTK_OFF_Up;             /* '<S2>/BTK_StsteMachine' */
    uint8_T is_BTK_OFF;                /* '<S2>/BTK_StsteMachine' */
    uint8_T is_BTK_HV;                 /* '<S2>/BTK_StsteMachine' */
    uint8_T is_BTK_OFF_ESCL_LOCK;      /* '<S2>/BTK_StsteMachine' */
    uint8_T is_BTK_OFF_Down;           /* '<S2>/BTK_StsteMachine' */
    uint8_T is_BTK_Solution_A;         /* '<S2>/BTK_StsteMachine' */
    uint8_T u8_GearPos_Pre;            /* '<S2>/BTK_StsteMachine' */
    uint8_T is_active_c3_BTK_Model;    /* '<S7>/Chart' */
    uint8_T is_c3_BTK_Model;           /* '<S7>/Chart' */
    uint8_T is_LEDFlash;               /* '<S7>/Chart' */
    uint8_T u8_flash_count;            /* '<S7>/Chart' */
    boolean_T WODriver_Sts;            /* '<S2>/Data Store Memory' */
    boolean_T bool_isBTKOFFDown_flg;   /* '<S2>/BTK_StsteMachine' */
    boolean_T bool_KeyAuthSucc_flg;    /* '<S2>/BTK_StsteMachine' */
    boolean_T bool_BTK_OFF_Down_flg;   /* '<S2>/BTK_StsteMachine' */
    boolean_T bool_UpFaultCheck_flg;   /* '<S2>/BTK_StsteMachine' */
    boolean_T bool_SSB_Trigger_flg;    /* '<S2>/BTK_StsteMachine' */
    boolean_T bool_LVtoOFF;            /* '<S2>/BTK_StsteMachine' */
    boolean_T bool_HVtoOFF;            /* '<S2>/BTK_StsteMachine' */
    boolean_T bool_LVtoHV;             /* '<S2>/BTK_StsteMachine' */
    boolean_T bool_HVtoLV;             /* '<S2>/BTK_StsteMachine' */
    boolean_T UDSInvalidTimeFlg;       /* '<S2>/BTK_StsteMachine' */
    boolean_T bool_ESCL_Unlock_Timeout_flg;/* '<S2>/BTK_StsteMachine' */
    boolean_T bool_GearToStart;        /* '<S2>/BTK_StsteMachine' */
    boolean_T bool_OFFUpTrigger;       /* '<S2>/BTK_StsteMachine' */
    boolean_T bool_HVtoSTART;          /* '<S2>/BTK_StsteMachine' */
    boolean_T bool_HVWOtoSTART;        /* '<S2>/BTK_StsteMachine' */
    boolean_T isToStart;               /* '<S2>/BTK_StsteMachine' */
    boolean_T bool_STARTtoOFF;         /* '<S2>/BTK_StsteMachine' */
    boolean_T bool_OFFtoHVAllw;        /* '<S2>/BTK_StsteMachine' */
    boolean_T bool_OFFtoStartAllw;     /* '<S2>/BTK_StsteMachine' */
    boolean_T bool_OFFtoLVAllw;        /* '<S2>/BTK_StsteMachine' */
    boolean_T bool_BTKOFFtoUpAllw;     /* '<S2>/BTK_StsteMachine' */
    boolean_T bool_timeStamp_flg;      /* '<S2>/BTK_StsteMachine' */
    boolean_T bool_HVReqTimeStamp_flg; /* '<S2>/BTK_StsteMachine' */
    boolean_T bool_UDSTimeStamp_flg;   /* '<S2>/BTK_StsteMachine' */
    boolean_T VBTK_SleepAllw_pre;      /* '<S2>/BTK_StsteMachine' */
    boolean_T bool_ESCLLock_Wait;      /* '<S2>/BTK_StsteMachine' */
    boolean_T bool_flag;               /* '<S34>/Data Store Memory' */
    boolean_T BTK_ACT_PEPS_MODE;       /* '<S1>/BTK_ACT_PEPS' */
    rtDW_BTK_Delay_Confirm_BTK_Mo_T BTK_Delay_Confirm_c;/* '<S91>/BTK_Delay_Confirm' */
    rtDW_BTKSignalConfirm_BTK_Mod_T BTKSignalConfirm1_n;/* '<S11>/BTKSignalConfirm1' */
    rtDW_BTKTimeoutCustomTimer_BT_T BTKTimeoutCustomTimer;/* '<S10>/BTKTimeoutCustomTimer' */
    rtDW_BTK_Delay_Confirm_BTK_Mo_T BTK_Delay_Confirm_ho;/* '<S67>/BTK_Delay_Confirm' */
    rtDW_BTK_Delay_Confirm_BTK_Mo_T BTK_Delay_Confirm_d;/* '<S66>/BTK_Delay_Confirm' */
    rtDW_BTK_Delay_Confirm_BTK_Mo_T BTK_Delay_Confirm_o;/* '<S73>/BTK_Delay_Confirm' */
    rtDW_BTK_Delay_Confirm_BTK_Mo_T BTK_Delay_Confirm_h;/* '<S68>/BTK_Delay_Confirm' */
    rtDW_BTKSignalConfirm_BTK_Mod_T BTKSignalConfirm3_e;/* '<S34>/BTKSignalConfirm3' */
    rtDW_BTKSignalConfirm_BTK_Mod_T BTKSignalConfirm2_d;/* '<S34>/BTKSignalConfirm2' */
    rtDW_BTKSignalConfirm_BTK_Mod_T BTKSignalConfirm1_h;/* '<S34>/BTKSignalConfirm1' */
    rtDW_BTK_Delay_Confirm_BTK_Mo_T BTK_Delay_Confirm1;/* '<S8>/BTK_Delay_Confirm1' */
    rtDW_BTK_Delay_Confirm_BTK_Mo_T BTK_Delay_Confirm;/* '<S8>/BTK_Delay_Confirm' */
    rtDW_BTK_A_KeyAuth_BTK_Model_T BTK_A_KeyAuth;/* '<S2>/BTK_A_KeyAuth' */
    rtDW_BTKSignalConfirm_BTK_Mod_T BTKSignalConfirm3;/* '<S5>/BTKSignalConfirm3' */
    rtDW_BTKSignalConfirm_BTK_Mod_T BTKSignalConfirm2;/* '<S5>/BTKSignalConfirm2' */
    rtDW_BTKSignalConfirm_BTK_Mod_T BTKSignalConfirm1;/* '<S5>/BTKSignalConfirm1' */
    rtDW_BTKSignalConfirm_BTK_Mod_T BTKSignalConfirm;/* '<S5>/BTKSignalConfirm' */
}
D_Work_BTK_Model_T;

/* Zero-crossing (trigger) state */
typedef struct
{
    ZCSigState ON_Fall_Trig_ZCE;       /* '<S33>/ON_Fall' */
    ZCSigState ACC_Rise_Trig_ZCE;      /* '<S33>/ACC_Rise' */
}
PrevZCSigStates_BTK_Model_T;

/* Invariant block signals (auto storage) */
typedef struct
{
    const boolean_T RelationalOperator1;/* '<S17>/Relational Operator1' */
}
ConstBlockIO_BTK_Model_T;

/* Real-time Model Data Structure */
struct tag_RTM_BTK_Model_T
{
    const char_T *errorStatus;
};

/* Block signals (auto storage) */
#pragma push
#pragma DATA_SEG __GPAGE_SEG GPAGED_RAM

extern BlockIO_BTK_Model_T BTK_Model_B;

#pragma pop

/* Block states (auto storage) */

#pragma push
#pragma DATA_SEG __GPAGE_SEG GPAGED_RAM

extern D_Work_BTK_Model_T BTK_Model_DWork;

#pragma pop

/* External data declarations for dependent source files */
#pragma push
#pragma DATA_SEG __GPAGE_SEG GPAGED_RAM

extern const BTK BTK_Model_rtZBTK;     /* BTK ground */

#pragma pop

/* Zero-crossing (trigger) state */

#pragma push
#pragma DATA_SEG __GPAGE_SEG GPAGED_RAM

extern PrevZCSigStates_BTK_Model_T BTK_Model_PrevZCSigState;

#pragma pop
#pragma push
#pragma DATA_SEG __GPAGE_SEG GPAGED_RAM

extern const ConstBlockIO_BTK_Model_T BTK_Model_ConstB;/* constant block i/o */

#pragma pop

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern BTK BTK_output;                 /* '<S1>/Bus Creator' */
extern boolean_T VBTK_SleepAllw_flg;   /* '<S1>/Merge5' */
extern boolean_T SSB_Adhesion;         /* '<S34>/Logical Operator' */
extern boolean_T SSB_SyncCorrect;      /* '<S34>/Logical Operator1' */
extern boolean_T IGN1_FeedVoltCorrect; /* '<S5>/Logical Operator' */
extern boolean_T IGN2_FeedVoltCorrect; /* '<S5>/Logical Operator1' */

/* Model entry point functions */
extern void BTK_Model_initialize(void);
extern void BTK_Model_step(void);
extern void BTK_Model_terminate(void);

/* Real-time Model object */
#pragma push
#pragma DATA_SEG __GPAGE_SEG GPAGED_RAM

extern RT_MODEL_BTK_Model_T *const BTK_Model_M;

#pragma pop

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S2>/Constant' : Unused code path elimination
 * Block '<S19>/Switch1' : Eliminated due to constant selection input
 * Block '<S19>/Constant' : Unused code path elimination
 * Block '<S19>/Constant1' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'BTK_Model'
 * '<S1>'   : 'BTK_Model/BTK_Module'
 * '<S2>'   : 'BTK_Model/BTK_Module/BTK_ACT_PEPS'
 * '<S3>'   : 'BTK_Model/BTK_Module/BTK_Merge_PEPS'
 * '<S4>'   : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/BTK_A_ESCLReq'
 * '<S5>'   : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/BTK_A_IGNFeedBackDiagnosis'
 * '<S6>'   : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/BTK_A_KeyAuth'
 * '<S7>'   : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/BTK_A_RedLed_Flash'
 * '<S8>'   : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/BTK_A_SSB '
 * '<S9>'   : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/BTK_A_SSB_Monitoring'
 * '<S10>'  : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/BTK_C_ESCLLock'
 * '<S11>'  : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/BTK_C_ESCLLock_Wait'
 * '<S12>'  : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/BTK_C_HVtoDown'
 * '<S13>'  : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/BTK_C_LVUporDown'
 * '<S14>'  : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/BTK_HV_Req'
 * '<S15>'  : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/BTK_Signal_Simulation'
 * '<S16>'  : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/BTK_StsteMachine'
 * '<S17>'  : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/Subsystem'
 * '<S18>'  : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/UDS_sig_filter'
 * '<S19>'  : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/VehcleFault_sig_filter'
 * '<S20>'  : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/WODriver_Confirm'
 * '<S21>'  : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/BTK_A_ESCLReq/Enabled Subsystem'
 * '<S22>'  : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/BTK_A_IGNFeedBackDiagnosis/BTKSignalConfirm'
 * '<S23>'  : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/BTK_A_IGNFeedBackDiagnosis/BTKSignalConfirm1'
 * '<S24>'  : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/BTK_A_IGNFeedBackDiagnosis/BTKSignalConfirm2'
 * '<S25>'  : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/BTK_A_IGNFeedBackDiagnosis/BTKSignalConfirm3'
 * '<S26>'  : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/BTK_A_KeyAuth/MEK_KeyAuth'
 * '<S27>'  : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/BTK_A_KeyAuth/SSB_KeyAuth'
 * '<S28>'  : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/BTK_A_KeyAuth/SSB_KeyAuth/BTK_Delay_Confirm'
 * '<S29>'  : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/BTK_A_KeyAuth/SSB_KeyAuth/BTK_Delay_Confirm/AffirmCheck'
 * '<S30>'  : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/BTK_A_RedLed_Flash/Chart'
 * '<S31>'  : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/BTK_A_SSB /BTK_Delay_Confirm'
 * '<S32>'  : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/BTK_A_SSB /BTK_Delay_Confirm1'
 * '<S33>'  : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/BTK_A_SSB /Mechanical'
 * '<S34>'  : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/BTK_A_SSB /SSB_Sts '
 * '<S35>'  : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/BTK_A_SSB /BTK_Delay_Confirm/AffirmCheck'
 * '<S36>'  : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/BTK_A_SSB /BTK_Delay_Confirm1/AffirmCheck'
 * '<S37>'  : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/BTK_A_SSB /Mechanical/ACC_Rise'
 * '<S38>'  : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/BTK_A_SSB /Mechanical/ON_Fall'
 * '<S39>'  : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/BTK_A_SSB /Mechanical/Subsystem'
 * '<S40>'  : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/BTK_A_SSB /Mechanical/Subsystem1'
 * '<S41>'  : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/BTK_A_SSB /SSB_Sts /BTKSignalConfirm1'
 * '<S42>'  : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/BTK_A_SSB /SSB_Sts /BTKSignalConfirm2'
 * '<S43>'  : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/BTK_A_SSB /SSB_Sts /BTKSignalConfirm3'
 * '<S44>'  : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/BTK_A_SSB /SSB_Sts /Compare To Constant'
 * '<S45>'  : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/BTK_A_SSB /SSB_Sts /Compare To Constant1'
 * '<S46>'  : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/BTK_A_SSB /SSB_Sts /Compare To Constant2'
 * '<S47>'  : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/BTK_A_SSB /SSB_Sts /Compare To Constant3'
 * '<S48>'  : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/BTK_A_SSB /SSB_Sts /Compare To Constant4'
 * '<S49>'  : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/BTK_A_SSB /SSB_Sts /Compare To Zero1'
 * '<S50>'  : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/BTK_A_SSB /SSB_Sts /Compare To Zero4'
 * '<S51>'  : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/BTK_A_SSB /SSB_Sts /Enabled Subsystem'
 * '<S52>'  : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/BTK_A_SSB /SSB_Sts /Enabled Subsystem1'
 * '<S53>'  : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/BTK_A_SSB_Monitoring/MEK_Trigger'
 * '<S54>'  : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/BTK_A_SSB_Monitoring/SSB_Trigger'
 * '<S55>'  : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/BTK_C_ESCLLock/BTKTimeoutCustomTimer'
 * '<S56>'  : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/BTK_C_ESCLLock_Wait/BTKSignalConfirm1'
 * '<S57>'  : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/BTK_C_HVtoDown/SolutionA_HVtoDown'
 * '<S58>'  : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/BTK_C_HVtoDown/SolutionB_HVtoDown'
 * '<S59>'  : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/BTK_C_HVtoDown/VehicleSpeedAllwDown'
 * '<S60>'  : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/BTK_C_LVUporDown/SolutionA_LVtoUporDown'
 * '<S61>'  : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/BTK_C_LVUporDown/SolutionB_LVtoUporDown'
 * '<S62>'  : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/BTK_HV_Req/AC_ChrgReqConfirm'
 * '<S63>'  : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/BTK_HV_Req/ChrgAllwSpeed'
 * '<S64>'  : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/BTK_HV_Req/ChrgReqConfirm'
 * '<S65>'  : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/BTK_HV_Req/DC_ChrgReqConfirm'
 * '<S66>'  : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/BTK_HV_Req/TBOX_IChrg_Sig_Filter'
 * '<S67>'  : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/BTK_HV_Req/TboxHVACReq_Sig_Filter'
 * '<S68>'  : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/BTK_HV_Req/AC_ChrgReqConfirm/ACChrg_filter'
 * '<S69>'  : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/BTK_HV_Req/AC_ChrgReqConfirm/Chrg_triggerDn'
 * '<S70>'  : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/BTK_HV_Req/AC_ChrgReqConfirm/Chrg_triggerUp'
 * '<S71>'  : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/BTK_HV_Req/AC_ChrgReqConfirm/ACChrg_filter/BTK_Delay_Confirm'
 * '<S72>'  : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/BTK_HV_Req/AC_ChrgReqConfirm/ACChrg_filter/BTK_Delay_Confirm/AffirmCheck'
 * '<S73>'  : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/BTK_HV_Req/DC_ChrgReqConfirm/ACChrg_filter'
 * '<S74>'  : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/BTK_HV_Req/DC_ChrgReqConfirm/Chrg_triggerDn'
 * '<S75>'  : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/BTK_HV_Req/DC_ChrgReqConfirm/Chrg_triggerUp'
 * '<S76>'  : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/BTK_HV_Req/DC_ChrgReqConfirm/ACChrg_filter/BTK_Delay_Confirm'
 * '<S77>'  : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/BTK_HV_Req/DC_ChrgReqConfirm/ACChrg_filter/BTK_Delay_Confirm/AffirmCheck'
 * '<S78>'  : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/BTK_HV_Req/TBOX_IChrg_Sig_Filter/BTK_Delay_Confirm'
 * '<S79>'  : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/BTK_HV_Req/TBOX_IChrg_Sig_Filter/BTK_Delay_Confirm/AffirmCheck'
 * '<S80>'  : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/BTK_HV_Req/TboxHVACReq_Sig_Filter/BTK_Delay_Confirm'
 * '<S81>'  : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/BTK_HV_Req/TboxHVACReq_Sig_Filter/BTK_Delay_Confirm/AffirmCheck'
 * '<S82>'  : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/BTK_Signal_Simulation/Authtication'
 * '<S83>'  : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/BTK_Signal_Simulation/Brake'
 * '<S84>'  : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/BTK_Signal_Simulation/Config '
 * '<S85>'  : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/BTK_Signal_Simulation/DoorAndVehicle_Sts'
 * '<S86>'  : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/BTK_Signal_Simulation/ESCL'
 * '<S87>'  : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/BTK_Signal_Simulation/PowerMode_Req'
 * '<S88>'  : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/BTK_Signal_Simulation/Subsystem'
 * '<S89>'  : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/BTK_Signal_Simulation/SystemTime_simulation'
 * '<S90>'  : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/BTK_Signal_Simulation/TQM'
 * '<S91>'  : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/WODriver_Confirm/MEK'
 * '<S92>'  : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/WODriver_Confirm/SSB'
 * '<S93>'  : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/WODriver_Confirm/MEK/BTK_Delay_Confirm'
 * '<S94>'  : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/WODriver_Confirm/MEK/BTK_Delay_Confirm/AffirmCheck'
 * '<S95>'  : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/WODriver_Confirm/SSB/DrvrDoorSts_tri'
 * '<S96>'  : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/WODriver_Confirm/SSB/Enabled and Triggered Subsystem'
 * '<S97>'  : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/WODriver_Confirm/SSB/Enabled and Triggered Subsystem1'
 * '<S98>'  : 'BTK_Model/BTK_Module/BTK_Merge_PEPS/BTK_PDU_Analyze'
 * '<S99>'  : 'BTK_Model/BTK_Module/BTK_Merge_PEPS/Signals_Simulation'
 * '<S100>' : 'BTK_Model/BTK_Module/BTK_Merge_PEPS/SpeedAllw_Chrg'
 * '<S101>' : 'BTK_Model/BTK_Module/BTK_Merge_PEPS/Subsystem'
 * '<S102>' : 'BTK_Model/BTK_Module/BTK_Merge_PEPS/BTK_PDU_Analyze/Subsystem'
 * '<S103>' : 'BTK_Model/BTK_Module/BTK_Merge_PEPS/Signals_Simulation/Subsystem'
 * '<S104>' : 'BTK_Model/BTK_Module/BTK_Merge_PEPS/Signals_Simulation/SystemTime_simulation'
 */
#endif                                 /* RTW_HEADER_BTK_Model_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

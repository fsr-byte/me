/*
 * File: CHRG_Model.h
 *
 * Code generated for Simulink model 'CHRG_Model'.
 *
 * Model version                  : 1.1917
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Fri Mar 18 15:31:54 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Freescale->32-bit PowerPC
 * Code generation objectives:
 *    1. RAM efficiency
 *    2. ROM efficiency
 *    3. Execution efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_CHRG_Model_h_
#define RTW_HEADER_CHRG_Model_h_
#include <string.h>
#ifndef CHRG_Model_COMMON_INCLUDES_
# define CHRG_Model_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#endif                                 /* CHRG_Model_COMMON_INCLUDES_ */

#include "CHRG_Model_types.h"

/* Child system includes */
#include "CHRG_Module.h"

/* Includes for objects with custom storage classes. */
#include "CHRG_Cal_Data.h"

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
    uint32_T DataStoreRead1;           /* '<S2>/Data Store Read1' */
    uint32_T TaskTick;                 /* '<S97>/Chart' */
    uint32_T u32_Timestamp;            /* '<S87>/Chart' */
    uint32_T TaskTick_g;               /* '<S44>/Chart' */
    uint8_T DCChrgPlugLockStat;        /* '<S25>/Chart' */
    uint8_T ACChrgPlugLockStat;        /* '<S25>/Chart' */
    boolean_T Switch1;                 /* '<S29>/Switch1' */
    boolean_T Switch1_f;               /* '<S30>/Switch1' */
    boolean_T VCHRG_VCUChrgAllwd_flg;  /* '<S2>/ChrgState' */
    boolean_T VCHRG_ShiftKnobRemindReq_flg;/* '<S2>/ChrgState' */
    boolean_T OBCWakeupTimerReset;     /* '<S2>/ChrgState' */
    boolean_T VCHRG_WaitChrgEnd_Flag;  /* '<S2>/ChrgState' */
    boolean_T LogicalOperator3;        /* '<S18>/Logical Operator3' */
    boolean_T bool_timeout;            /* '<S87>/Chart' */
    boolean_T bool_ChrgEnd;            /* '<S7>/bool_ChrgEnd' */
    boolean_T bool_Enable;             /* '<S7>/Chart' */
    boolean_T ChrgEnd_Overtime;        /* '<S14>/Chart' */
    boolean_T DCChrgPlugLockEn;        /* '<S25>/Chart' */
    boolean_T ACChrgPlugLockEn;        /* '<S25>/Chart' */
    boolean_T LogicalOperator2;        /* '<S100>/Logical Operator2' */
    rtB_CHRG_C_ChrgConnectCheck_C_T CHRG_C_ChrgConnectCheck;/* '<S2>/CHRG_C_ChrgConnectCheck' */
    rtB_CMM_NormalStsTimer_CHRG_M_T CMM_NormalStsTimer_k;/* '<S18>/CMM_NormalStsTimer' */
    rtB_PMMSignalConfirm_CHRG_M_f_T PMMSignalConfirm_h;/* '<S76>/PMMSignalConfirm' */
    rtB_CMM_NormalStsTimer_CHRG_M_T CMM_NormalStsTimer_i;/* '<S75>/CMM_NormalStsTimer' */
    rtB_PMMSignalConfirm_CHRG_M_o_T PMMSignalConfirm_p;/* '<S74>/PMMSignalConfirm' */
    rtB_PMMSignalConfirm_CHRG_M_o_T PMMSignalConfirm_g;/* '<S73>/PMMSignalConfirm' */
    rtB_CMM_NormalStsTimer_CHRG_M_T CMM_NormalStsTimer_c;/* '<S17>/CMM_NormalStsTimer' */
    rtB_CMM_NormalStsTimer_CHRG_M_T CMM_NormalStsTimer;/* '<S16>/CMM_NormalStsTimer' */
    rtB_PMMSignalConfirm_CHRG_M_o_T SignalConfirm1_p;/* '<S12>/SignalConfirm1' */
    rtB_PMMSignalConfirm_CHRG_Mod_T SignalConfirm1;/* '<S67>/SignalConfirm1' */
    rtB_PMMSignalConfirm_CHRG_Mod_T PMMSignalConfirm;/* '<S67>/PMMSignalConfirm' */
}
BlockIO_CHRG_Model_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct
{
    uint32_T Delay_DSTATE;             /* '<S33>/Delay' */
    uint32_T Delay_DSTATE_m;           /* '<S18>/Delay' */
    uint32_T Delay_DSTATE_n;           /* '<S75>/Delay' */
    uint32_T Delay_DSTATE_j;           /* '<S17>/Delay' */
    uint32_T Delay_DSTATE_l;           /* '<S16>/Delay' */
    uint32_T Delay2_DSTATE;            /* '<S101>/Delay2' */
    uint32_T Delay3_DSTATE;            /* '<S101>/Delay3' */
    uint32_T Delay_DSTATE_k;           /* '<S100>/Delay' */
    uint32_T Delay1_DSTATE;            /* '<S100>/Delay1' */
    uint32_T A_FlagValid_Timestamp;    /* '<S2>/Data Store Memory' */
    uint32_T t_ms;                     /* '<S2>/ChrgState' */
    uint32_T VCHRG_WaitInExpMode_StartTime_m;/* '<S2>/ChrgState' */
    uint32_T u32_ChrgPlugLockCheck_StartTime;/* '<S2>/ChrgState' */
    uint32_T StartTime;                /* '<S97>/Chart' */
    uint32_T StartTime_o;              /* '<S44>/Chart' */
    uint32_T StartTime_f;              /* '<S14>/Chart' */
    uint32_T TaskTick;                 /* '<S14>/Chart' */
    boolean_T Delay_DSTATE_kv;         /* '<S4>/Delay' */
    boolean_T Delay_DSTATE_f;          /* '<S44>/Delay' */
    boolean_T Delay1_DSTATE_c;         /* '<S56>/Delay1' */
    boolean_T Delay_DSTATE_o;          /* '<S56>/Delay' */
    boolean_T Delay1_DSTATE_cn;        /* '<S58>/Delay1' */
    boolean_T Delay_DSTATE_d;          /* '<S58>/Delay' */
    uint8_T is_active_c2_CHRG_Model;   /* '<S2>/ChrgState' */
    uint8_T is_c2_CHRG_Model;          /* '<S2>/ChrgState' */
    uint8_T is_ChrgNormal;             /* '<S2>/ChrgState' */
    uint8_T is_NonRun;                 /* '<S2>/ChrgState' */
    uint8_T is_ChrgPlugUnlock;         /* '<S2>/ChrgState' */
    uint8_T is_NonRunningWork;         /* '<S2>/ChrgState' */
    uint8_T is_Charge;                 /* '<S2>/ChrgState' */
    uint8_T is_InToChrg;               /* '<S2>/ChrgState' */
    uint8_T is_ShiftKnobCheck;         /* '<S2>/ChrgState' */
    uint8_T is_active_ShiftKnobCheck;  /* '<S2>/ChrgState' */
    uint8_T is_ChrgLockCheck;          /* '<S2>/ChrgState' */
    uint8_T is_active_ChrgLockCheck;   /* '<S2>/ChrgState' */
    uint8_T is_BMSPwrupallwCheck;      /* '<S2>/ChrgState' */
    uint8_T bSendCnt;                  /* '<S2>/ChrgState' */
    uint8_T icLoad;                    /* '<S4>/Delay' */
    uint8_T is_active_c1_CHRG_Model;   /* '<S97>/Chart' */
    uint8_T is_c1_CHRG_Model;          /* '<S97>/Chart' */
    uint8_T icLoad_i;                  /* '<S16>/Delay' */
    uint8_T is_active_c7_CHRG_Model;   /* '<S87>/Chart' */
    uint8_T is_c7_CHRG_Model;          /* '<S87>/Chart' */
    uint8_T is_active_c5_CHRG_Model;   /* '<S44>/Chart' */
    uint8_T is_c5_CHRG_Model;          /* '<S44>/Chart' */
    uint8_T is_active_c3_CHRG_Model;   /* '<S7>/Chart' */
    uint8_T is_c3_CHRG_Model;          /* '<S7>/Chart' */
    uint8_T is_active_c6_CHRG_Model;   /* '<S14>/Chart' */
    uint8_T is_c6_CHRG_Model;          /* '<S14>/Chart' */
    uint8_T icLoad_b;                  /* '<S101>/Delay2' */
    uint8_T icLoad_if;                 /* '<S100>/Delay' */
    uint8_T icLoad_e;                  /* '<S100>/Delay1' */
    rtDW_CHRG_C_ChrgConnectCheck__T CHRG_C_ChrgConnectCheck;/* '<S2>/CHRG_C_ChrgConnectCheck' */
    rtDW_CMM_NormalStsTimer_CHRG__T CMM_NormalStsTimer_k;/* '<S18>/CMM_NormalStsTimer' */
    rtDW_PMMSignalConfirm_CHRG__c_T PMMSignalConfirm_h;/* '<S76>/PMMSignalConfirm' */
    rtDW_CMM_NormalStsTimer_CHRG__T CMM_NormalStsTimer_i;/* '<S75>/CMM_NormalStsTimer' */
    rtDW_PMMSignalConfirm_CHRG__b_T PMMSignalConfirm_p;/* '<S74>/PMMSignalConfirm' */
    rtDW_PMMSignalConfirm_CHRG__b_T PMMSignalConfirm_g;/* '<S73>/PMMSignalConfirm' */
    rtDW_CMM_NormalStsTimer_CHRG__T CMM_NormalStsTimer_c;/* '<S17>/CMM_NormalStsTimer' */
    rtDW_CMM_NormalStsTimer_CHRG__T CMM_NormalStsTimer;/* '<S16>/CMM_NormalStsTimer' */
    rtDW_PMMSignalConfirm_CHRG__b_T SignalConfirm1_p;/* '<S12>/SignalConfirm1' */
    rtDW_PMMSignalConfirm_CHRG_Mo_T SignalConfirm1;/* '<S67>/SignalConfirm1' */
    rtDW_PMMSignalConfirm_CHRG_Mo_T PMMSignalConfirm;/* '<S67>/PMMSignalConfirm' */
}
D_Work_CHRG_Model_T;

/* Zero-crossing (trigger) state */
typedef struct
{
    ZCSigState EnabledSubsystem2_Trig_ZCE;/* '<S58>/Enabled Subsystem2' */
    ZCSigState EnabledSubsystem_Trig_ZCE;/* '<S56>/Enabled Subsystem' */
}
PrevZCSigStates_CHRG_Model_T;

/* Invariant block signals (auto storage) */
typedef struct
{
    const uint32_T Gain;               /* '<S101>/Gain' */
}
ConstBlockIO_CHRG_Model_T;

/* Real-time Model Data Structure */
struct tag_RTM_CHRG_Model_T
{
    const char_T *errorStatus;

    /*
     * Timing:
     * The following substructure contains information regarding
     * the timing information for the model.
     */
    struct
    {
        uint32_T clockTick0;
    }
    Timing;
};

/* Block signals (auto storage) */
#pragma push
#pragma DATA_SEG __GPAGE_SEG GPAGED_RAM

extern BlockIO_CHRG_Model_T CHRG_Model_B;

#pragma pop

/* Block states (auto storage) */

#pragma push
#pragma DATA_SEG __GPAGE_SEG GPAGED_RAM

extern D_Work_CHRG_Model_T CHRG_Model_DWork;

#pragma pop

/* External data declarations for dependent source files */
#pragma push
#pragma DATA_SEG __GPAGE_SEG GPAGED_RAM

extern const CHRG CHRG_Model_rtZCHRG;  /* CHRG ground */

#pragma pop

/* Zero-crossing (trigger) state */

#pragma push
#pragma DATA_SEG __GPAGE_SEG GPAGED_RAM

extern PrevZCSigStates_CHRG_Model_T CHRG_Model_PrevZCSigState;

#pragma pop
#pragma push
#pragma DATA_SEG __GPAGE_SEG GPAGED_RAM

extern const ConstBlockIO_CHRG_Model_T CHRG_Model_ConstB;/* constant block i/o */

#pragma pop

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern CHRG CHRG_output;               /* '<S1>/Bus Creator' */
extern uint32_T VCHRG_DCChargeCounter_ms;/* '<S64>/Add' */
extern uint8_T VCHRG_ChrgModeLog_enum; /* '<S44>/Data Type Conversion'
                                        * 充电模式记录
                                        */
extern boolean_T VCHRG_ChrgStopInhCharge_flg;/* '<S2>/Data Type Conversion8' */
extern boolean_T VCHRG_ChrgStopNormalPowerDownReq_flg;/* '<S2>/Data Type Conversion' */
extern boolean_T VCHRG_ChrgModeConfirm_flg;/* '<S2>/Merge58'
                                            * 充电模式确认标志
                                            */
extern boolean_T VCHRG_ChrgOperationTimeout_flg;/* '<S2>/Merge43'
                                                 * 充电操作超时标志
                                                 */
extern boolean_T VCHRG_ChrgModeInvalid_flg;/* '<S2>/Merge39'
                                            * 充电模式无效标志
                                            */
extern boolean_T VCHRG_ChrgModeAbnormal_flg;/* '<S2>/Merge40'
                                             * 充电模式异常
                                             */
extern boolean_T VCHRG_OBCWakeupTimeout_flg;/* '<S2>/Merge48'
                                             * OBC唤醒超时标志
                                             */
extern boolean_T bool_ChrgDisconnect;  /* '<S2>/Merge3' */
extern boolean_T VCHRG_ChrgCheck_flg;  /* '<S2>/Merge11'
                                        * 充电检查标志
                                        */
extern boolean_T VCHRG_ChrgOptDCExit_Flag;/* '<S2>/Merge13'
                                           * 直流充电结束标志
                                           */
extern boolean_T VCHRG_ChrgOptACExit_Flag;/* '<S2>/Merge14'
                                           * 交流充电结束标志
                                           */
extern boolean_T VCHRG_OBCSleep_Flag;  /* '<S2>/Merge15'
                                        * OBC休眠标志
                                        */
extern boolean_T VCHRG_ChrgStart_flg;  /* '<S2>/Merge17'
                                        * 充电启动标志
                                        */
extern boolean_T VCHRG_ChrgOperation_flg;/* '<S2>/Merge18'
                                          * 充电启动操作完成标志
                                          */
extern boolean_T VCHRG_ChrgStop_flg;   /* '<S2>/Merge19'
                                        * 充电停止标志
                                        */
extern boolean_T VCHRG_ChrgEnd_flg;    /* '<S2>/Merge20'
                                        * 充电结束标志
                                        */
extern boolean_T VCHRG_ChrgActive_flg; /* '<S2>/Merge25'
                                        * 充电使能标志
                                        */
extern boolean_T VCHRG_ChrgStopAbnormal_flg;/* '<S2>/Merge37'
                                             * 充电异常标志
                                             */
extern boolean_T VCHRG_ChrgFault_flg;  /* '<S2>/Merge38'
                                        * 充电故障标志
                                        */
extern boolean_T VCHRG_ChrgStartTimeout_flg;/* '<S2>/Merge42'
                                             * 充电启动超时
                                             */
extern boolean_T VCHRG_ShiftKnobCheckTimeout_flg;/* '<S2>/Merge44'
                                                  * 充电检查手柄位置超时标志
                                                  */
extern boolean_T VCHRG_ChrgReq_flg;    /* '<S2>/Merge5'
                                        * 充电请求标志
                                        */
extern boolean_T VCHRG_ChrgAgain_flg;  /* '<S2>/Merge51'
                                        * 再次充电标志
                                        */
extern boolean_T VCHRG_TBOXChrgReq_flg;/* '<S2>/Merge6'
                                        * TBOX充电请求标志
                                        */
extern boolean_T VCHRG_OBCWakeup_flg;  /* '<S2>/Merge7'
                                        * OBC唤醒标志
                                        */
extern boolean_T VCHRG_ChrgModeCheck_flg;/* '<S2>/Merge8'
                                          * 充电模式检查标志
                                          */
extern boolean_T VCHRG_ShiftKnobCheck_flg;/* '<S2>/Merge9'
                                           * 充电手柄位置检查标志
                                           */
extern boolean_T VCHRG_OBCSleepTimeout_flg;/* '<S2>/Merge'
                                            * OBC休眠超时标志
                                            */
extern boolean_T VCHRG_ChrgStopChrgCurrLimit_flg;/* '<S2>/Merge2' */
extern boolean_T VCHRG_ChrgModeInvalidRemind_flg;/* '<S35>/Constant' */
extern boolean_T VCHRG_ChrgModeAbnormalRemind_flg;/* '<S36>/Relational Operator' */
extern boolean_T VCHRG_ChrgModeCheckReq_flg;/* '<S2>/ChrgState' */
extern boolean_T chrg_startcheck;      /* '<S2>/ChrgState' */
extern boolean_T VCHRG_BMSPwrupAllw_Timeout;/* '<S2>/ChrgState' */
extern boolean_T VCHRG_ChrgLockCheckTimeout_flg;/* '<S2>/ChrgState'
                                                 * 充电电子锁检查超时
                                                 */
extern boolean_T VCHRG_ChrgLockCheck_flg;/* '<S2>/ChrgState'
                                          * 充电锁止标志
                                          */
extern boolean_T VCHRG_CutOffMCURelay_flg;/* '<S2>/ChrgState'
                                           * CHRG请求PMM断开MCU继电器标记
                                           */
extern boolean_T VCHRG_KeepLVReq_flg;  /* '<S2>/ChrgState'
                                        * CHRG请求PMM模块在LV Ready等待CMM模块充电检查完成，再上高压
                                        */
extern boolean_T VCHRG_ChrgStopLockError_flg;/* '<S74>/PMMSignalConfirm' */
extern boolean_T VCHRG_ChrgStopModeInvalid_flg;/* '<S75>/CMM_NormalStsTimer' */
extern boolean_T VCHRG_ChrgStopOperTimeout_flg;/* '<S76>/PMMSignalConfirm' */

/*
 * Exported States
 *
 * Note: Exported states are block states with an exported global
 * storage class designation.  Code generation will declare the memory for these
 * states and exports their symbols.
 *
 */
extern uint32_T VCHRG_ChrgStartDCStartTime_ms;/* '<Root>/Data Store Memory1' */
extern uint32_T VCHRG_ChrgStartACStartTime_ms;/* '<Root>/Data Store Memory2' */
extern uint32_T VCHRG_ChrgOBCUnlockStartTime_ms;/* '<Root>/Data Store Memory3' */
extern boolean_T VCHRG_ChrgPlugUnlock_flg;/* '<S2>/ChrgState' */
extern boolean_T VCHRG_WaitChrgPlugUnlockTimeout_flg;/* '<S2>/ChrgState'
                                                      * 等待电子锁解锁超时
                                                      */

/* Model entry point functions */
extern void CHRG_Model_initialize(void);
extern void CHRG_Model_step(void);
extern void CHRG_Model_terminate(void);

/* Real-time Model object */
#pragma push
#pragma DATA_SEG __GPAGE_SEG GPAGED_RAM

extern RT_MODEL_CHRG_Model_T *const CHRG_Model_M;

#pragma pop

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S2>/Data Type Conversion16' : Eliminate redundant data type conversion
 * Block '<S28>/Data Type Conversion' : Eliminate redundant data type conversion
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
 * '<Root>' : 'CHRG_Model'
 * '<S1>'   : 'CHRG_Model/CHRG_Module'
 * '<S2>'   : 'CHRG_Model/CHRG_Module/CHRG'
 * '<S3>'   : 'CHRG_Model/CHRG_Module/CHRG/CHRG_C_ChrgActive'
 * '<S4>'   : 'CHRG_Model/CHRG_Module/CHRG/CHRG_C_ChrgAgain'
 * '<S5>'   : 'CHRG_Model/CHRG_Module/CHRG/CHRG_C_ChrgCheck'
 * '<S6>'   : 'CHRG_Model/CHRG_Module/CHRG/CHRG_C_ChrgConnectCheck'
 * '<S7>'   : 'CHRG_Model/CHRG_Module/CHRG/CHRG_C_ChrgEndOpt'
 * '<S8>'   : 'CHRG_Model/CHRG_Module/CHRG/CHRG_C_ChrgFaultCheck'
 * '<S9>'   : 'CHRG_Model/CHRG_Module/CHRG/CHRG_C_ChrgModecheck'
 * '<S10>'  : 'CHRG_Model/CHRG_Module/CHRG/CHRG_C_ChrgOperation'
 * '<S11>'  : 'CHRG_Model/CHRG_Module/CHRG/CHRG_C_ChrgStart'
 * '<S12>'  : 'CHRG_Model/CHRG_Module/CHRG/CHRG_C_ChrgStop'
 * '<S13>'  : 'CHRG_Model/CHRG_Module/CHRG/CHRG_C_ChrgStopAbnormal'
 * '<S14>'  : 'CHRG_Model/CHRG_Module/CHRG/CHRG_C_ChrgStopConfirm'
 * '<S15>'  : 'CHRG_Model/CHRG_Module/CHRG/CHRG_C_ChrgWait'
 * '<S16>'  : 'CHRG_Model/CHRG_Module/CHRG/CHRG_C_OBCSleep'
 * '<S17>'  : 'CHRG_Model/CHRG_Module/CHRG/CHRG_C_OBCWakeUp'
 * '<S18>'  : 'CHRG_Model/CHRG_Module/CHRG/CHRG_C_ParkingStsCheck'
 * '<S19>'  : 'CHRG_Model/CHRG_Module/CHRG/CHRG_C_RecoverChrgStartTimeout'
 * '<S20>'  : 'CHRG_Model/CHRG_Module/CHRG/CHRG_C_ResetChrgCheck'
 * '<S21>'  : 'CHRG_Model/CHRG_Module/CHRG/CHRG_C_ResetChrgFault'
 * '<S22>'  : 'CHRG_Model/CHRG_Module/CHRG/CHRG_C_ResetChrgFlag'
 * '<S23>'  : 'CHRG_Model/CHRG_Module/CHRG/CHRG_C_ShiftKnobCheck'
 * '<S24>'  : 'CHRG_Model/CHRG_Module/CHRG/CMM_CheckMsgLost'
 * '<S25>'  : 'CHRG_Model/CHRG_Module/CHRG/ChrgPulgLock_SignalConvert'
 * '<S26>'  : 'CHRG_Model/CHRG_Module/CHRG/ChrgState'
 * '<S27>'  : 'CHRG_Model/CHRG_Module/CHRG/Compare To Constant'
 * '<S28>'  : 'CHRG_Model/CHRG_Module/CHRG/PMM_A_CHMASignalSts'
 * '<S29>'  : 'CHRG_Model/CHRG_Module/CHRG/PMM_A_PlugConn'
 * '<S30>'  : 'CHRG_Model/CHRG_Module/CHRG/PMM_HandBrake'
 * '<S31>'  : 'CHRG_Model/CHRG_Module/CHRG/ShiftKnob'
 * '<S32>'  : 'CHRG_Model/CHRG_Module/CHRG/ShiftKnobRemind'
 * '<S33>'  : 'CHRG_Model/CHRG_Module/CHRG/Subsystem'
 * '<S34>'  : 'CHRG_Model/CHRG_Module/CHRG/VehChrgSts'
 * '<S35>'  : 'CHRG_Model/CHRG_Module/CHRG/bool_ChangeChargeMethod'
 * '<S36>'  : 'CHRG_Model/CHRG_Module/CHRG/bool_ChrgModeAbnormal'
 * '<S37>'  : 'CHRG_Model/CHRG_Module/CHRG/CHRG_C_ChrgConnectCheck/CMM_Delay_Conferm'
 * '<S38>'  : 'CHRG_Model/CHRG_Module/CHRG/CHRG_C_ChrgConnectCheck/CMM_Delay_Conferm/AffirmCheck'
 * '<S39>'  : 'CHRG_Model/CHRG_Module/CHRG/CHRG_C_ChrgEndOpt/AC'
 * '<S40>'  : 'CHRG_Model/CHRG_Module/CHRG/CHRG_C_ChrgEndOpt/Chart'
 * '<S41>'  : 'CHRG_Model/CHRG_Module/CHRG/CHRG_C_ChrgEndOpt/ChrgEndConfirm'
 * '<S42>'  : 'CHRG_Model/CHRG_Module/CHRG/CHRG_C_ChrgEndOpt/DC'
 * '<S43>'  : 'CHRG_Model/CHRG_Module/CHRG/CHRG_C_ChrgEndOpt/Enabled Subsystem'
 * '<S44>'  : 'CHRG_Model/CHRG_Module/CHRG/CHRG_C_ChrgModecheck/ChrgModeCheck'
 * '<S45>'  : 'CHRG_Model/CHRG_Module/CHRG/CHRG_C_ChrgModecheck/ChrgModeCheck/Chart'
 * '<S46>'  : 'CHRG_Model/CHRG_Module/CHRG/CHRG_C_ChrgModecheck/ChrgModeCheck/Compare To Constant'
 * '<S47>'  : 'CHRG_Model/CHRG_Module/CHRG/CHRG_C_ChrgModecheck/ChrgModeCheck/Compare To Constant1'
 * '<S48>'  : 'CHRG_Model/CHRG_Module/CHRG/CHRG_C_ChrgModecheck/ChrgModeCheck/PMMsToms'
 * '<S49>'  : 'CHRG_Model/CHRG_Module/CHRG/CHRG_C_ChrgOperation/ACTaskTick_ms'
 * '<S50>'  : 'CHRG_Model/CHRG_Module/CHRG/CHRG_C_ChrgOperation/ChrgOperation'
 * '<S51>'  : 'CHRG_Model/CHRG_Module/CHRG/CHRG_C_ChrgOperation/DCTaskTick_ms'
 * '<S52>'  : 'CHRG_Model/CHRG_Module/CHRG/CHRG_C_ChrgOperation/ACTaskTick_ms/Enabled Subsystem1'
 * '<S53>'  : 'CHRG_Model/CHRG_Module/CHRG/CHRG_C_ChrgOperation/ChrgOperation/PMMminToms'
 * '<S54>'  : 'CHRG_Model/CHRG_Module/CHRG/CHRG_C_ChrgOperation/ChrgOperation/minToms1'
 * '<S55>'  : 'CHRG_Model/CHRG_Module/CHRG/CHRG_C_ChrgOperation/DCTaskTick_ms/Enabled Subsystem1'
 * '<S56>'  : 'CHRG_Model/CHRG_Module/CHRG/CHRG_C_ChrgStart/ACTaskTick_ms'
 * '<S57>'  : 'CHRG_Model/CHRG_Module/CHRG/CHRG_C_ChrgStart/ChrgStart'
 * '<S58>'  : 'CHRG_Model/CHRG_Module/CHRG/CHRG_C_ChrgStart/DCTaskTick_ms'
 * '<S59>'  : 'CHRG_Model/CHRG_Module/CHRG/CHRG_C_ChrgStart/ACTaskTick_ms/Enabled Subsystem'
 * '<S60>'  : 'CHRG_Model/CHRG_Module/CHRG/CHRG_C_ChrgStart/ACTaskTick_ms/Enabled Subsystem1'
 * '<S61>'  : 'CHRG_Model/CHRG_Module/CHRG/CHRG_C_ChrgStart/ACTaskTick_ms/Enabled Subsystem2'
 * '<S62>'  : 'CHRG_Model/CHRG_Module/CHRG/CHRG_C_ChrgStart/ChrgStart/sToms1'
 * '<S63>'  : 'CHRG_Model/CHRG_Module/CHRG/CHRG_C_ChrgStart/ChrgStart/sToms2'
 * '<S64>'  : 'CHRG_Model/CHRG_Module/CHRG/CHRG_C_ChrgStart/DCTaskTick_ms/Enabled Subsystem1'
 * '<S65>'  : 'CHRG_Model/CHRG_Module/CHRG/CHRG_C_ChrgStart/DCTaskTick_ms/Enabled Subsystem2'
 * '<S66>'  : 'CHRG_Model/CHRG_Module/CHRG/CHRG_C_ChrgStart/DCTaskTick_ms/Enabled Subsystem3'
 * '<S67>'  : 'CHRG_Model/CHRG_Module/CHRG/CHRG_C_ChrgStop/ChrgStsStop'
 * '<S68>'  : 'CHRG_Model/CHRG_Module/CHRG/CHRG_C_ChrgStop/Compare To Constant1'
 * '<S69>'  : 'CHRG_Model/CHRG_Module/CHRG/CHRG_C_ChrgStop/PMMsToms'
 * '<S70>'  : 'CHRG_Model/CHRG_Module/CHRG/CHRG_C_ChrgStop/SignalConfirm1'
 * '<S71>'  : 'CHRG_Model/CHRG_Module/CHRG/CHRG_C_ChrgStop/ChrgStsStop/PMMSignalConfirm'
 * '<S72>'  : 'CHRG_Model/CHRG_Module/CHRG/CHRG_C_ChrgStop/ChrgStsStop/SignalConfirm1'
 * '<S73>'  : 'CHRG_Model/CHRG_Module/CHRG/CHRG_C_ChrgStopAbnormal/ChrgLimit'
 * '<S74>'  : 'CHRG_Model/CHRG_Module/CHRG/CHRG_C_ChrgStopAbnormal/ChrgLockCheck'
 * '<S75>'  : 'CHRG_Model/CHRG_Module/CHRG/CHRG_C_ChrgStopAbnormal/ChrgModeInvalid'
 * '<S76>'  : 'CHRG_Model/CHRG_Module/CHRG/CHRG_C_ChrgStopAbnormal/ChrgOperationTimeout'
 * '<S77>'  : 'CHRG_Model/CHRG_Module/CHRG/CHRG_C_ChrgStopAbnormal/ChrgLimit/PMMSignalConfirm'
 * '<S78>'  : 'CHRG_Model/CHRG_Module/CHRG/CHRG_C_ChrgStopAbnormal/ChrgLockCheck/Compare To Constant'
 * '<S79>'  : 'CHRG_Model/CHRG_Module/CHRG/CHRG_C_ChrgStopAbnormal/ChrgLockCheck/Compare To Constant1'
 * '<S80>'  : 'CHRG_Model/CHRG_Module/CHRG/CHRG_C_ChrgStopAbnormal/ChrgLockCheck/Compare To Constant2'
 * '<S81>'  : 'CHRG_Model/CHRG_Module/CHRG/CHRG_C_ChrgStopAbnormal/ChrgLockCheck/Compare To Constant3'
 * '<S82>'  : 'CHRG_Model/CHRG_Module/CHRG/CHRG_C_ChrgStopAbnormal/ChrgLockCheck/PMMSignalConfirm'
 * '<S83>'  : 'CHRG_Model/CHRG_Module/CHRG/CHRG_C_ChrgStopAbnormal/ChrgModeInvalid/CMM_NormalStsTimer'
 * '<S84>'  : 'CHRG_Model/CHRG_Module/CHRG/CHRG_C_ChrgStopAbnormal/ChrgOperationTimeout/PMMSignalConfirm'
 * '<S85>'  : 'CHRG_Model/CHRG_Module/CHRG/CHRG_C_ChrgStopConfirm/Chart'
 * '<S86>'  : 'CHRG_Model/CHRG_Module/CHRG/CHRG_C_ChrgStopConfirm/PMMsToms'
 * '<S87>'  : 'CHRG_Model/CHRG_Module/CHRG/CHRG_C_ChrgWait/ChrgWakeUp'
 * '<S88>'  : 'CHRG_Model/CHRG_Module/CHRG/CHRG_C_ChrgWait/ChrgWakeUp/Chart'
 * '<S89>'  : 'CHRG_Model/CHRG_Module/CHRG/CHRG_C_OBCSleep/CMM_NormalStsTimer'
 * '<S90>'  : 'CHRG_Model/CHRG_Module/CHRG/CHRG_C_OBCWakeUp/CMM_NormalStsTimer'
 * '<S91>'  : 'CHRG_Model/CHRG_Module/CHRG/CHRG_C_OBCWakeUp/Compare To Constant'
 * '<S92>'  : 'CHRG_Model/CHRG_Module/CHRG/CHRG_C_ParkingStsCheck/CMM_NormalStsTimer'
 * '<S93>'  : 'CHRG_Model/CHRG_Module/CHRG/CHRG_C_ParkingStsCheck/Compare To Constant'
 * '<S94>'  : 'CHRG_Model/CHRG_Module/CHRG/CHRG_C_ParkingStsCheck/Compare To Constant1'
 * '<S95>'  : 'CHRG_Model/CHRG_Module/CHRG/CHRG_C_ParkingStsCheck/Compare To Constant2'
 * '<S96>'  : 'CHRG_Model/CHRG_Module/CHRG/CHRG_C_ParkingStsCheck/Compare To Constant3'
 * '<S97>'  : 'CHRG_Model/CHRG_Module/CHRG/CHRG_C_ShiftKnobCheck/Subsystem'
 * '<S98>'  : 'CHRG_Model/CHRG_Module/CHRG/CHRG_C_ShiftKnobCheck/Subsystem/Chart'
 * '<S99>'  : 'CHRG_Model/CHRG_Module/CHRG/CHRG_C_ShiftKnobCheck/Subsystem/PMMsToms'
 * '<S100>' : 'CHRG_Model/CHRG_Module/CHRG/CMM_CheckMsgLost/MsgLostChecker'
 * '<S101>' : 'CHRG_Model/CHRG_Module/CHRG/CMM_CheckMsgLost/MsgTimerTrigger'
 * '<S102>' : 'CHRG_Model/CHRG_Module/CHRG/CMM_CheckMsgLost/MsgTimerTrigger/Compare To Constant'
 * '<S103>' : 'CHRG_Model/CHRG_Module/CHRG/ChrgPulgLock_SignalConvert/Chart'
 */
#endif                                 /* RTW_HEADER_CHRG_Model_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

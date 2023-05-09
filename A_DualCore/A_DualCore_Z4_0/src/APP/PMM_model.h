/*
 * File: PMM_model.h
 *
 * Code generated for Simulink model 'PMM_model'.
 *
 * Model version                  : 1.3119
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Fri Mar 18 15:42:54 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Freescale->32-bit PowerPC
 * Code generation objectives:
 *    1. RAM efficiency
 *    2. ROM efficiency
 *    3. Execution efficiency
 *    4. MISRA C:2012 guidelines
 * Validation result: Not run
 */

#ifndef RTW_HEADER_PMM_model_h_
#define RTW_HEADER_PMM_model_h_
#include <stddef.h>
#include <string.h>
#ifndef PMM_model_COMMON_INCLUDES_
# define PMM_model_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* PMM_model_COMMON_INCLUDES_ */

#include "PMM_model_types.h"

/* Child system includes */
#include "PMM_Module.h"

/* Includes for objects with custom storage classes. */
#include "PMM_Cal_Data.h"

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
typedef struct {
  uint32_T DataStoreRead;              /* '<S2>/Data Store Read' */
  uint32_T DataStoreRead_f;            /* '<S1>/Data Store Read' */
  uint32_T TaskTick;                   /* '<S24>/Chart' */
  uint32_T TaskTick_o;                 /* '<S21>/Chart' */
  uint8_T Switch;                      /* '<S14>/Switch' */
  uint8_T Switch_b;                    /* '<S7>/Switch' */
  boolean_T RelationalOperator_g;      /* '<S11>/Relational Operator' */
  boolean_T Delay;                     /* '<S2>/Delay' */
  boolean_T VPMM_InternalSleepActive_flg;/* '<S2>/PMM_State' */
  boolean_T VPMM_MCURelayActive_flg;   /* '<S2>/PMM_State' */
  boolean_T VPMM_PTReady_flg;          /* '<S2>/PMM_State' */
  boolean_T VPMM_HVReady_flg;          /* '<S2>/PMM_State' */
  boolean_T bool_NonRunFlag;           /* '<S2>/PMM_State' */
  boolean_T bool_RunningFlag;          /* '<S2>/PMM_State' */
  boolean_T bool_out_MCUHVActiveTimeout;/* '<S2>/PMM_State' */
  boolean_T LogicalOperator13;         /* '<S24>/Logical Operator13' */
  boolean_T LogicalOperator13_i;       /* '<S29>/Logical Operator13' */
  boolean_T LogicalOperator1;          /* '<S23>/Logical Operator1' */
  boolean_T LogicalOperator2_n;        /* '<S23>/Logical Operator2' */
  boolean_T VPMM_MCUModError;          /* '<S28>/Relational Operator' */
  boolean_T VPMM_BMSModError;          /* '<S28>/Relational Operator2' */
  boolean_T VPMM_DCDCModError;         /* '<S28>/Relational Operator6' */
  boolean_T RelationalOperator3;       /* '<S86>/Relational Operator3' */
  boolean_T LogicalOperator_m;         /* '<S86>/Logical Operator' */
  boolean_T LogicalOperator1_m;        /* '<S86>/Logical Operator1' */
  boolean_T RelationalOperator2;       /* '<S80>/Relational Operator2' */
  boolean_T LogicalOperator_e;         /* '<S80>/Logical Operator' */
  boolean_T RelationalOperator3_c;     /* '<S76>/Relational Operator3' */
  boolean_T RelationalOperator2_m;     /* '<S76>/Relational Operator2' */
  boolean_T LogicalOperator7;          /* '<S21>/Logical Operator7' */
  boolean_T OutportBufferForbool_HVStopWork;/* '<S21>/Constant' */
  boolean_T LogicalOperator5;          /* '<S20>/Logical Operator5' */
  boolean_T LogicalOperator18;         /* '<S20>/Logical Operator18' */
  boolean_T RelationalOperator2_o;     /* '<S19>/Relational Operator2' */
  boolean_T LogicalOperator_d;         /* '<S19>/Logical Operator' */
  boolean_T RelationalOperator1;       /* '<S57>/Relational Operator1' */
  boolean_T LogicalOperator10;         /* '<S55>/Logical Operator10' */
  boolean_T LogicalOperator12_a;       /* '<S55>/Logical Operator12' */
  boolean_T LogicalOperator4_p;        /* '<S18>/Logical Operator4' */
  rtB_PMM_InternalWaitTimeout_P_T PMM_InternalWaitTimeout1;/* '<S110>/PMM_InternalWaitTimeout1' */
  rtB_PMM_InternalWaitTimeout_P_T PMM_InternalWaitTimeout_i;/* '<S109>/PMM_InternalWaitTimeout' */
  rtB_PMM_InternalWaitTimeout_P_T PMM_InternalWaitTimeout_j;/* '<S107>/PMM_InternalWaitTimeout' */
  rtB_PMM_InternalWaitTimeout_P_T PMM_InternalWaitTimeout;/* '<S106>/PMM_InternalWaitTimeout' */
  rtB_BMSMonitor_PMM_model_T BMSMonitor;/* '<S2>/BMSMonitor' */
  rtB_PMMSignalConfirm_PMM_mode_T SignalConfirm1_a;/* '<S80>/SignalConfirm1' */
  rtB_Chart_PMM_model_T sf_Chart_d;    /* '<S80>/Chart' */
  rtB_Chart_PMM_model_T sf_Chart2;     /* '<S76>/Chart2' */
  rtB_Chart_PMM_model_T sf_Chart1;     /* '<S76>/Chart1' */
  rtB_PMMSignalConfirm_PMM_mode_T PMMSignalConfirm;/* '<S73>/PMMSignalConfirm' */
  rtB_ConfirmMCUInHVActiveMode__T ConfirmMCUInHVActiveMode_a;/* '<S20>/ConfirmMCUInHVActiveMode' */
  rtB_Chart_PMM_model_T sf_Chart_k;    /* '<S19>/Chart' */
  rtB_PMMSignalConfirm_PMM_mode_T SignalConfirm1;/* '<S55>/SignalConfirm1' */
  rtB_Chart_PMM_model_T sf_Chart_b;    /* '<S57>/Chart' */
  rtB_PMMTimeout_PMM_model_T PMMTimeout1;/* '<S56>/PMMTimeout1' */
  rtB_ConfirmMCUInHVActiveMode__T ConfirmMCUInHVActiveMode;/* '<S26>/ConfirmMCUInHVActiveMode' */
  rtB_PMM_CheckMsgLost_BMS_PMM__T PMM_CheckMsgLost_MCU;/* '<S2>/PMM_CheckMsgLost_MCU' */
  rtB_PMM_CheckMsgLost_BMS_PMM__T PMM_CheckMsgLost_DCDC;/* '<S2>/PMM_CheckMsgLost_DCDC' */
  rtB_PMM_CheckMsgLost_BMS_PMM__T PMM_CheckMsgLost_BMS;/* '<S2>/PMM_CheckMsgLost_BMS' */
} BlockIO_PMM_model_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  uint32_T Delay1_DSTATE;              /* '<S115>/Delay1' */
  uint32_T Delay2_DSTATE;              /* '<S115>/Delay2' */
  uint32_T Delay2_DSTATE_h;            /* '<S54>/Delay2' */
  uint32_T Delay1_DSTATE_f;            /* '<S54>/Delay1' */
  uint32_T Delay1_DSTATE_e;            /* '<S51>/Delay1' */
  uint32_T Delay2_DSTATE_n;            /* '<S51>/Delay2' */
  uint32_T u32_StartTime;              /* '<S2>/RemoteIChrg_State' */
  uint32_T u32_internal_timestamp;     /* '<S2>/RemoteHVAC_State' */
  uint32_T u32_MCUHVActive_Timestamp;  /* '<S2>/PMM_State' */
  uint32_T StartTime;                  /* '<S24>/Chart' */
  uint32_T StartTime_b;                /* '<S21>/Chart' */
  uint32_T VPMM_DCDownStartTime_ms;    /* '<S68>/Data Store Memory' */
  uint8_T Delay1_DSTATE_c;             /* '<S2>/Delay1' */
  uint8_T Delay5_DSTATE;               /* '<S2>/Delay5' */
  uint8_T Delay_DSTATE;                /* '<S80>/Delay' */
  uint8_T Delay_DSTATE_k;              /* '<S55>/Delay' */
  uint8_T Delay_DSTATE_f;              /* '<S48>/Delay' */
  uint8_T Delay_DSTATE_g;              /* '<S47>/Delay' */
  boolean_T Delay_DSTATE_fe;           /* '<S2>/Delay' */
  boolean_T Delay3_DSTATE;             /* '<S2>/Delay3' */
  boolean_T Delay1_DSTATE_b;           /* '<S4>/Delay1' */
  boolean_T Delay_DSTATE_fw;           /* '<S112>/Delay' */
  boolean_T Delay_DSTATE_o;            /* '<S108>/Delay' */
  boolean_T Delay_DSTATE_e;            /* '<S87>/Delay' */
  boolean_T Delay_DSTATE_j;            /* '<S68>/Delay' */
  boolean_T Delay1_DSTATE_ev;          /* '<S5>/Delay1' */
  uint8_T is_active_c3_PMM_model;      /* '<S39>/Chart' */
  uint8_T is_c3_PMM_model;             /* '<S39>/Chart' */
  uint8_T is_active_c4_PMM_model;      /* '<S2>/RemoteIChrg_State' */
  uint8_T is_c4_PMM_model;             /* '<S2>/RemoteIChrg_State' */
  uint8_T is_IChrg_Procedure;          /* '<S2>/RemoteIChrg_State' */
  uint8_T is_active_c2_PMM_model;      /* '<S2>/RemoteHVAC_State' */
  uint8_T is_c2_PMM_model;             /* '<S2>/RemoteHVAC_State' */
  uint8_T is_active_c1_PMM_model;      /* '<S2>/PMM_State' */
  uint8_T is_c1_PMM_model;             /* '<S2>/PMM_State' */
  uint8_T is_HVMode;                   /* '<S2>/PMM_State' */
  uint8_T is_LVReady;                  /* '<S2>/PMM_State' */
  uint8_T is_LVDown;                   /* '<S2>/PMM_State' */
  uint8_T is_Work;                     /* '<S2>/PMM_State' */
  uint8_T is_NonRunning;               /* '<S2>/PMM_State' */
  uint8_T is_HVDown;                   /* '<S2>/PMM_State' */
  uint8_T is_LVUp;                     /* '<S2>/PMM_State' */
  uint8_T is_HVUp;                     /* '<S2>/PMM_State' */
  uint8_T is_Running;                  /* '<S2>/PMM_State' */
  uint8_T icLoad;                      /* '<S112>/Delay' */
  uint8_T icLoad_d;                    /* '<S115>/Delay1' */
  uint8_T is_active_c25_PMM_model;     /* '<S24>/Chart' */
  uint8_T is_c25_PMM_model;            /* '<S24>/Chart' */
  uint8_T is_active_c24_PMM_model;     /* '<S21>/Chart' */
  uint8_T is_c24_PMM_model;            /* '<S21>/Chart' */
  uint8_T icLoad_e;                    /* '<S48>/Delay' */
  uint8_T icLoad_j;                    /* '<S54>/Delay2' */
  uint8_T icLoad_f;                    /* '<S54>/Delay1' */
  uint8_T icLoad_n;                    /* '<S47>/Delay' */
  uint8_T icLoad_f2;                   /* '<S51>/Delay1' */
  uint8_T icLoad_o;                    /* '<S51>/Delay2' */
  boolean_T bool_CheckAllWakeup;       /* '<S2>/RemoteIChrg_State' */
  boolean_T bool_PMMLVUp_BMSPwrupallwLVUp;/* '<S2>/PMM_State' */
  boolean_T bool_PMMLVUp_MCULVUp;      /* '<S2>/PMM_State' */
  boolean_T bool_PMMLVUp_BMSLVUp;      /* '<S2>/PMM_State' */
  boolean_T bool_PMMLVUp_DCDCLVUp;     /* '<S2>/PMM_State' */
  boolean_T bool_PMMLVUp_CHMAEn_Flg;   /* '<S2>/PMM_State' */
  rtDW_PMM_InternalWaitTimeout__T PMM_InternalWaitTimeout1;/* '<S110>/PMM_InternalWaitTimeout1' */
  rtDW_PMM_InternalWaitTimeout__T PMM_InternalWaitTimeout_i;/* '<S109>/PMM_InternalWaitTimeout' */
  rtDW_PMM_InternalWaitTimeout__T PMM_InternalWaitTimeout_j;/* '<S107>/PMM_InternalWaitTimeout' */
  rtDW_PMM_InternalWaitTimeout__T PMM_InternalWaitTimeout;/* '<S106>/PMM_InternalWaitTimeout' */
  rtDW_PMMSignalConfirm_PMM_mod_T SignalConfirm1_a;/* '<S80>/SignalConfirm1' */
  rtDW_Chart_PMM_model_T sf_Chart_d;   /* '<S80>/Chart' */
  rtDW_Chart_PMM_model_T sf_Chart2;    /* '<S76>/Chart2' */
  rtDW_Chart_PMM_model_T sf_Chart1;    /* '<S76>/Chart1' */
  rtDW_PMMSignalConfirm_PMM_mod_T PMMSignalConfirm;/* '<S73>/PMMSignalConfirm' */
  rtDW_ConfirmMCUInHVActiveMode_T ConfirmMCUInHVActiveMode_a;/* '<S20>/ConfirmMCUInHVActiveMode' */
  rtDW_Chart_PMM_model_T sf_Chart_k;   /* '<S19>/Chart' */
  rtDW_PMMSignalConfirm_PMM_mod_T SignalConfirm1;/* '<S55>/SignalConfirm1' */
  rtDW_Chart_PMM_model_T sf_Chart_b;   /* '<S57>/Chart' */
  rtDW_PMMTimeout_PMM_model_T PMMTimeout1;/* '<S56>/PMMTimeout1' */
  rtDW_ConfirmMCUInHVActiveMode_T ConfirmMCUInHVActiveMode;/* '<S26>/ConfirmMCUInHVActiveMode' */
  rtDW_PMM_CheckMsgLost_BMS_PMM_T PMM_CheckMsgLost_MCU;/* '<S2>/PMM_CheckMsgLost_MCU' */
  rtDW_PMM_CheckMsgLost_BMS_PMM_T PMM_CheckMsgLost_DCDC;/* '<S2>/PMM_CheckMsgLost_DCDC' */
  rtDW_PMM_CheckMsgLost_BMS_PMM_T PMM_CheckMsgLost_BMS;/* '<S2>/PMM_CheckMsgLost_BMS' */
} D_Work_PMM_model_T;

/* Real-time Model Data Structure */
struct tag_RTM_PMM_model_T {
  const char_T *errorStatus;
};

/* Block signals (auto storage) */
#pragma push
#pragma DATA_SEG __GPAGE_SEG GPAGED_RAM

extern BlockIO_PMM_model_T PMM_model_B;

#pragma pop

/* Block states (auto storage) */

#pragma push
#pragma DATA_SEG __GPAGE_SEG GPAGED_RAM

extern D_Work_PMM_model_T PMM_model_DWork;

#pragma pop

/* External data declarations for dependent source files */
#pragma push
#pragma DATA_SEG __GPAGE_SEG GPAGED_RAM

extern const PMM PMM_model_rtZPMM;     /* PMM ground */

#pragma pop

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern PMM PMM_output;                 /* '<S1>/Bus Creator' */
extern uint32_T VPMM_CHMAStartTime_ms; /* '<S44>/Data Store Read' */
extern uint8_T VPMM_IChrgWakeUp;       /* '<S2>/RemoteIChrg_State' */
extern uint8_T VPMM_IChrgState;        /* '<S2>/RemoteIChrg_State' */
extern uint8_T VPMM_SystemState_enum;  /* '<S2>/PMM_State' */
extern uint8_T VPMM_PEPS_PDU;          /* '<S13>/Switch' */
extern boolean_T b_M_PMM_ValidHVWakeUp;/* '<S38>/Logical Operator' */
extern boolean_T b_M_PMM_ValidWakeUp;  /* '<S38>/Logical Operator3' */
extern boolean_T VPMM_Running_flg;     /* '<S2>/Merge28'
                                        * 行驶标志
                                        */
extern boolean_T VPMM_HVActiveChrgModeInvalid_flg;/* '<S2>/Merge56' */
extern boolean_T VPMM_UpToHVMode_flg;  /* '<S2>/PMM_State'
                                        * 上电完成到高压工作模式
                                        */
extern boolean_T VPMM_LVUpTimeout_flg; /* '<S2>/PMM_State' */
extern boolean_T VPMM_HVUpTimeout_flg; /* '<S2>/PMM_State' */
extern boolean_T VPMM_UpToDnWakeup_flg;/* '<S23>/Logical Operator13' */
extern boolean_T VPMM_RunToNon_flg;    /* '<S28>/Logical Operator1' */
extern boolean_T VPMM_HVStopWorkTimeout_flg;/* '<S74>/Relational Operator' */
extern boolean_T VPMM_PreNonToRun_flg; /* '<S26>/Logical Operator1' */
extern boolean_T VPMM_NonToRun_flg;    /* '<S26>/Logical Operator4' */

/*
 * Exported States
 *
 * Note: Exported states are block states with an exported global
 * storage class designation.  Code generation will declare the memory for these
 * states and exports their symbols.
 *
 */
extern uint32_T VPMM_BMSMonitorStartTime_ms;/* '<S2>/Data Store Memory2' */
extern uint32_T VPMM_LastPrechargeTick_ms;/* '<S2>/PMM_State' */
extern uint32_T u32_PMMLVUp_CHMATimeStamp;/* '<S2>/PMM_State' */
extern uint32_T u32_PMMLVUp_EnableVCURelayTimestamp;/* '<S2>/PMM_State' */
extern uint32_T VPMM_MCUDischargeStartTime_ms;/* '<S87>/Data Store Memory' */
extern uint8_T VPMM_RemoteHVACState_enum;/* '<S2>/RemoteHVAC_State' */
extern boolean_T VPMM_HVUpToDn_flg;    /* '<S2>/PMM_State' */
extern boolean_T VPMM_HVDnToUp_flg;    /* '<S2>/PMM_State' */
extern boolean_T VPMM_MCUDischarge_flg;/* '<S2>/PMM_State'
                                        * MCU放电标志
                                        */
extern boolean_T VPMM_DC_MCUDischarge_flg;/* '<S2>/PMM_State'
                                           * MCU放电标志
                                           */
extern boolean_T VPMM_HVModeToDn_flg;  /* '<S2>/PMM_State'
                                        * 高压模式下电标志
                                        */
extern boolean_T VPMM_LVReadyToLVUp_flg;/* '<S2>/PMM_State' */
extern boolean_T VPMM_LVUp_flg;        /* '<S2>/PMM_State'
                                        * 低压上电完成标志
                                        */
extern boolean_T VPMM_LVReady_flg;     /* '<S2>/PMM_State' */
extern boolean_T VPMM_MCULVDn_flg;     /* '<S2>/PMM_State'
                                        * MCU低压下电完成标志
                                        */
extern boolean_T VPMM_MCULVUp_flg;     /* '<S2>/PMM_State'
                                        * 低压上电完成标志
                                        */
extern boolean_T VPMM_HVActive_flg;    /* '<S2>/PMM_State'
                                        * 高压激活标志
                                        */
extern boolean_T VPMM_Sleep_flg;       /* '<S2>/PMM_State'
                                        * 休眠标志
                                        */
extern boolean_T VPMM_LVDown_flg;      /* '<S2>/PMM_State'
                                        * 低压下电标志
                                        */
extern boolean_T VPMM_LVStandby_Flg;   /* '<S2>/PMM_State'
                                        * LV待机标志
                                        */
extern boolean_T VPMM_HVUp_flg;        /* '<S2>/PMM_State'
                                        * 高压上电完成标志
                                        */
extern boolean_T VPMM_LVDnToUp_flg;    /* '<S2>/PMM_State' */
extern boolean_T VPMM_LVReadyToDn_flg; /* '<S2>/PMM_State' */
extern boolean_T VPMM_HVStopWork_flg;  /* '<S2>/PMM_State'
                                        * 高压停止工作模式
                                        */
extern boolean_T VPMM_HVDown_flg;      /* '<S2>/PMM_State'
                                        * 高压下电标志
                                        */
extern boolean_T VPMM_MCUHVActive_flg; /* '<S2>/PMM_State'
                                        * MCU高压激活标志
                                        */

/* Model entry point functions */
extern void PMM_model_initialize(void);
extern void PMM_model_step(void);
extern void PMM_model_terminate(void);

/* Real-time Model object */
#pragma push
#pragma DATA_SEG __GPAGE_SEG GPAGED_RAM

extern RT_MODEL_PMM_model_T *const PMM_model_M;

#pragma pop

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S2>/Delay4' : Unused code path elimination
 * Block '<S8>/Constant' : Unused code path elimination
 * Block '<S8>/Constant3' : Unused code path elimination
 * Block '<S8>/Logical Operator2' : Unused code path elimination
 * Block '<S8>/Logical Operator3' : Unused code path elimination
 * Block '<S8>/Logical Operator4' : Unused code path elimination
 * Block '<S8>/Relational Operator' : Unused code path elimination
 * Block '<S8>/Relational Operator2' : Unused code path elimination
 * Block '<S9>/Constant1' : Unused code path elimination
 * Block '<S9>/Relational Operator1' : Unused code path elimination
 * Block '<S11>/Constant3' : Unused code path elimination
 * Block '<S11>/Relational Operator2' : Unused code path elimination
 * Block '<S12>/Constant3' : Unused code path elimination
 * Block '<S12>/Relational Operator2' : Unused code path elimination
 * Block '<S21>/Constant1' : Unused code path elimination
 * Block '<S21>/Constant3' : Unused code path elimination
 * Block '<S21>/Logical Operator1' : Unused code path elimination
 * Block '<S21>/Logical Operator3' : Unused code path elimination
 * Block '<S21>/Logical Operator8' : Unused code path elimination
 * Block '<S21>/Logical Operator9' : Unused code path elimination
 * Block '<S23>/Logical Operator14' : Unused code path elimination
 * Block '<S118>/Compare' : Unused code path elimination
 * Block '<S118>/Constant' : Unused code path elimination
 * Block '<S111>/Logical Operator3' : Unused code path elimination
 * Block '<S111>/Logical Operator4' : Unused code path elimination
 * Block '<S111>/Logical Operator5' : Unused code path elimination
 * Block '<S127>/Compare' : Unused code path elimination
 * Block '<S127>/Constant' : Unused code path elimination
 * Block '<S40>/Constant' : Unused code path elimination
 * Block '<S40>/Constant1' : Unused code path elimination
 * Block '<S128>/Delay1' : Unused code path elimination
 * Block '<S128>/Logical Operator' : Unused code path elimination
 * Block '<S131>/Compare' : Unused code path elimination
 * Block '<S131>/Constant' : Unused code path elimination
 * Block '<S132>/Compare' : Unused code path elimination
 * Block '<S132>/Constant' : Unused code path elimination
 * Block '<S129>/Constant' : Unused code path elimination
 * Block '<S129>/Delay' : Unused code path elimination
 * Block '<S129>/Logical Operator1' : Unused code path elimination
 * Block '<S133>/Constant1' : Unused code path elimination
 * Block '<S133>/Constant2' : Unused code path elimination
 * Block '<S133>/Delay1' : Unused code path elimination
 * Block '<S133>/Delay2' : Unused code path elimination
 * Block '<S133>/MinMax' : Unused code path elimination
 * Block '<S133>/Relational Operator' : Unused code path elimination
 * Block '<S133>/Sum' : Unused code path elimination
 * Block '<S133>/Sum1' : Unused code path elimination
 * Block '<S133>/Switch' : Unused code path elimination
 * Block '<S133>/Switch1' : Unused code path elimination
 * Block '<S134>/Compare' : Unused code path elimination
 * Block '<S134>/Constant' : Unused code path elimination
 * Block '<S135>/Compare' : Unused code path elimination
 * Block '<S135>/Constant' : Unused code path elimination
 * Block '<S130>/Constant' : Unused code path elimination
 * Block '<S130>/Delay' : Unused code path elimination
 * Block '<S130>/Logical Operator1' : Unused code path elimination
 * Block '<S136>/Constant1' : Unused code path elimination
 * Block '<S136>/Constant2' : Unused code path elimination
 * Block '<S136>/Delay1' : Unused code path elimination
 * Block '<S136>/Delay2' : Unused code path elimination
 * Block '<S136>/MinMax' : Unused code path elimination
 * Block '<S136>/Relational Operator' : Unused code path elimination
 * Block '<S136>/Sum' : Unused code path elimination
 * Block '<S136>/Sum1' : Unused code path elimination
 * Block '<S136>/Switch' : Unused code path elimination
 * Block '<S136>/Switch1' : Unused code path elimination
 * Block '<S128>/Switch' : Unused code path elimination
 * Block '<S40>/Switch' : Unused code path elimination
 * Block '<S3>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S27>/Data Type Conversion' : Eliminate redundant data type conversion
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
 * '<Root>' : 'PMM_model'
 * '<S1>'   : 'PMM_model/PMM_Module'
 * '<S2>'   : 'PMM_model/PMM_Module/PMM'
 * '<S3>'   : 'PMM_model/PMM_Module/PMM/BMSMonitor'
 * '<S4>'   : 'PMM_model/PMM_Module/PMM/BMSMonitor_Start_Time'
 * '<S5>'   : 'PMM_model/PMM_Module/PMM/CHMA_Start_Time'
 * '<S6>'   : 'PMM_model/PMM_Module/PMM/ExitIChrg'
 * '<S7>'   : 'PMM_model/PMM_Module/PMM/GearPosn'
 * '<S8>'   : 'PMM_model/PMM_Module/PMM/KeyOn'
 * '<S9>'   : 'PMM_model/PMM_Module/PMM/PEPSAcc'
 * '<S10>'  : 'PMM_model/PMM_Module/PMM/PEPSHV'
 * '<S11>'  : 'PMM_model/PMM_Module/PMM/PEPSOn'
 * '<S12>'  : 'PMM_model/PMM_Module/PMM/PEPSRemoteOn_HVWO'
 * '<S13>'  : 'PMM_model/PMM_Module/PMM/PEPSSignalConfirm'
 * '<S14>'  : 'PMM_model/PMM_Module/PMM/PEPSUnlcok'
 * '<S15>'  : 'PMM_model/PMM_Module/PMM/PMM_A_HVUpDC'
 * '<S16>'  : 'PMM_model/PMM_Module/PMM/PMM_C_HVActive'
 * '<S17>'  : 'PMM_model/PMM_Module/PMM/PMM_C_HVActiveChrgModeInvalid'
 * '<S18>'  : 'PMM_model/PMM_Module/PMM/PMM_C_HVDnToUp'
 * '<S19>'  : 'PMM_model/PMM_Module/PMM/PMM_C_HVDown'
 * '<S20>'  : 'PMM_model/PMM_Module/PMM/PMM_C_HVModeToDn'
 * '<S21>'  : 'PMM_model/PMM_Module/PMM/PMM_C_HVStopWork'
 * '<S22>'  : 'PMM_model/PMM_Module/PMM/PMM_C_HVUp'
 * '<S23>'  : 'PMM_model/PMM_Module/PMM/PMM_C_HVUpToDn'
 * '<S24>'  : 'PMM_model/PMM_Module/PMM/PMM_C_LVReadyToDn'
 * '<S25>'  : 'PMM_model/PMM_Module/PMM/PMM_C_MCUDischarge'
 * '<S26>'  : 'PMM_model/PMM_Module/PMM/PMM_C_NonToRun'
 * '<S27>'  : 'PMM_model/PMM_Module/PMM/PMM_C_ResetHVActive'
 * '<S28>'  : 'PMM_model/PMM_Module/PMM/PMM_C_RunToNon'
 * '<S29>'  : 'PMM_model/PMM_Module/PMM/PMM_C_UpToHVMode'
 * '<S30>'  : 'PMM_model/PMM_Module/PMM/PMM_CheckMsgLost_BMS'
 * '<S31>'  : 'PMM_model/PMM_Module/PMM/PMM_CheckMsgLost_DCDC'
 * '<S32>'  : 'PMM_model/PMM_Module/PMM/PMM_CheckMsgLost_MCU'
 * '<S33>'  : 'PMM_model/PMM_Module/PMM/PMM_State'
 * '<S34>'  : 'PMM_model/PMM_Module/PMM/RemoteHVAC_State'
 * '<S35>'  : 'PMM_model/PMM_Module/PMM/RemoteIChrg_State'
 * '<S36>'  : 'PMM_model/PMM_Module/PMM/Subsystem'
 * '<S37>'  : 'PMM_model/PMM_Module/PMM/VPMM_VehSts'
 * '<S38>'  : 'PMM_model/PMM_Module/PMM/ValidWakeUp'
 * '<S39>'  : 'PMM_model/PMM_Module/PMM/WakeSrcValid'
 * '<S40>'  : 'PMM_model/PMM_Module/PMM/ignSignalConfirm'
 * '<S41>'  : 'PMM_model/PMM_Module/PMM/BMSMonitor/Enabled Subsystem1'
 * '<S42>'  : 'PMM_model/PMM_Module/PMM/BMSMonitor/PMMminToms'
 * '<S43>'  : 'PMM_model/PMM_Module/PMM/BMSMonitor_Start_Time/Subsystem'
 * '<S44>'  : 'PMM_model/PMM_Module/PMM/CHMA_Start_Time/Subsystem'
 * '<S45>'  : 'PMM_model/PMM_Module/PMM/ExitIChrg/Chart'
 * '<S46>'  : 'PMM_model/PMM_Module/PMM/ExitIChrg/Chart2'
 * '<S47>'  : 'PMM_model/PMM_Module/PMM/PEPSSignalConfirm/OffToOnAcc_Reset'
 * '<S48>'  : 'PMM_model/PMM_Module/PMM/PEPSSignalConfirm/OnAccToOff_Reset'
 * '<S49>'  : 'PMM_model/PMM_Module/PMM/PEPSSignalConfirm/OffToOnAcc_Reset/Compare To Constant'
 * '<S50>'  : 'PMM_model/PMM_Module/PMM/PEPSSignalConfirm/OffToOnAcc_Reset/Compare To Constant1'
 * '<S51>'  : 'PMM_model/PMM_Module/PMM/PEPSSignalConfirm/OffToOnAcc_Reset/restart_timer'
 * '<S52>'  : 'PMM_model/PMM_Module/PMM/PEPSSignalConfirm/OnAccToOff_Reset/Compare To Constant'
 * '<S53>'  : 'PMM_model/PMM_Module/PMM/PEPSSignalConfirm/OnAccToOff_Reset/Compare To Constant1'
 * '<S54>'  : 'PMM_model/PMM_Module/PMM/PEPSSignalConfirm/OnAccToOff_Reset/restart_timer'
 * '<S55>'  : 'PMM_model/PMM_Module/PMM/PMM_C_HVActive/Subsystem'
 * '<S56>'  : 'PMM_model/PMM_Module/PMM/PMM_C_HVActive/Subsystem/DCHVActive'
 * '<S57>'  : 'PMM_model/PMM_Module/PMM/PMM_C_HVActive/Subsystem/MCUHVActive'
 * '<S58>'  : 'PMM_model/PMM_Module/PMM/PMM_C_HVActive/Subsystem/SignalConfirm1'
 * '<S59>'  : 'PMM_model/PMM_Module/PMM/PMM_C_HVActive/Subsystem/DCHVActive/PMMTimeout1'
 * '<S60>'  : 'PMM_model/PMM_Module/PMM/PMM_C_HVActive/Subsystem/MCUHVActive/Chart'
 * '<S61>'  : 'PMM_model/PMM_Module/PMM/PMM_C_HVActiveChrgModeInvalid/Compare To Constant'
 * '<S62>'  : 'PMM_model/PMM_Module/PMM/PMM_C_HVActiveChrgModeInvalid/Compare To Constant1'
 * '<S63>'  : 'PMM_model/PMM_Module/PMM/PMM_C_HVDnToUp/StateCheck'
 * '<S64>'  : 'PMM_model/PMM_Module/PMM/PMM_C_HVDnToUp/WakeUp'
 * '<S65>'  : 'PMM_model/PMM_Module/PMM/PMM_C_HVDown/Chart'
 * '<S66>'  : 'PMM_model/PMM_Module/PMM/PMM_C_HVModeToDn/ConfirmMCUInHVActiveMode'
 * '<S67>'  : 'PMM_model/PMM_Module/PMM/PMM_C_HVModeToDn/PMMsToms'
 * '<S68>'  : 'PMM_model/PMM_Module/PMM/PMM_C_HVModeToDn/TaskTick_ms'
 * '<S69>'  : 'PMM_model/PMM_Module/PMM/PMM_C_HVModeToDn/ConfirmMCUInHVActiveMode/Compare To Constant2'
 * '<S70>'  : 'PMM_model/PMM_Module/PMM/PMM_C_HVModeToDn/TaskTick_ms/Enabled Subsystem'
 * '<S71>'  : 'PMM_model/PMM_Module/PMM/PMM_C_HVModeToDn/TaskTick_ms/Enabled Subsystem1'
 * '<S72>'  : 'PMM_model/PMM_Module/PMM/PMM_C_HVStopWork/Chart'
 * '<S73>'  : 'PMM_model/PMM_Module/PMM/PMM_C_HVStopWork/HVStopWorkCheck'
 * '<S74>'  : 'PMM_model/PMM_Module/PMM/PMM_C_HVStopWork/Timeout'
 * '<S75>'  : 'PMM_model/PMM_Module/PMM/PMM_C_HVStopWork/HVStopWorkCheck/PMMSignalConfirm'
 * '<S76>'  : 'PMM_model/PMM_Module/PMM/PMM_C_HVStopWork/HVStopWorkCheck/Subsystem'
 * '<S77>'  : 'PMM_model/PMM_Module/PMM/PMM_C_HVStopWork/HVStopWorkCheck/Subsystem/Chart1'
 * '<S78>'  : 'PMM_model/PMM_Module/PMM/PMM_C_HVStopWork/HVStopWorkCheck/Subsystem/Chart2'
 * '<S79>'  : 'PMM_model/PMM_Module/PMM/PMM_C_HVStopWork/Timeout/PMMsToms'
 * '<S80>'  : 'PMM_model/PMM_Module/PMM/PMM_C_HVUp/Subsystem'
 * '<S81>'  : 'PMM_model/PMM_Module/PMM/PMM_C_HVUp/Subsystem/Chart'
 * '<S82>'  : 'PMM_model/PMM_Module/PMM/PMM_C_HVUp/Subsystem/PMMsToms'
 * '<S83>'  : 'PMM_model/PMM_Module/PMM/PMM_C_HVUp/Subsystem/SignalConfirm1'
 * '<S84>'  : 'PMM_model/PMM_Module/PMM/PMM_C_HVUpToDn/StateCheck'
 * '<S85>'  : 'PMM_model/PMM_Module/PMM/PMM_C_LVReadyToDn/Chart'
 * '<S86>'  : 'PMM_model/PMM_Module/PMM/PMM_C_MCUDischarge/Subsystem'
 * '<S87>'  : 'PMM_model/PMM_Module/PMM/PMM_C_MCUDischarge/TaskTick_ms'
 * '<S88>'  : 'PMM_model/PMM_Module/PMM/PMM_C_MCUDischarge/Subsystem/PMMsToms'
 * '<S89>'  : 'PMM_model/PMM_Module/PMM/PMM_C_MCUDischarge/TaskTick_ms/Enabled Subsystem'
 * '<S90>'  : 'PMM_model/PMM_Module/PMM/PMM_C_MCUDischarge/TaskTick_ms/Enabled Subsystem1'
 * '<S91>'  : 'PMM_model/PMM_Module/PMM/PMM_C_NonToRun/ConfirmMCUInHVActiveMode'
 * '<S92>'  : 'PMM_model/PMM_Module/PMM/PMM_C_NonToRun/PhysicalN'
 * '<S93>'  : 'PMM_model/PMM_Module/PMM/PMM_C_NonToRun/ConfirmMCUInHVActiveMode/Compare To Constant2'
 * '<S94>'  : 'PMM_model/PMM_Module/PMM/PMM_C_RunToNon/bool_CCConfirm'
 * '<S95>'  : 'PMM_model/PMM_Module/PMM/PMM_C_UpToHVMode/GearConfirm'
 * '<S96>'  : 'PMM_model/PMM_Module/PMM/PMM_C_UpToHVMode/GearConfirm/PhysicalN'
 * '<S97>'  : 'PMM_model/PMM_Module/PMM/PMM_CheckMsgLost_BMS/Atomic Subsystem'
 * '<S98>'  : 'PMM_model/PMM_Module/PMM/PMM_CheckMsgLost_BMS/MsgTimerTrigger'
 * '<S99>'  : 'PMM_model/PMM_Module/PMM/PMM_CheckMsgLost_BMS/MsgTimerTrigger/Compare To Constant'
 * '<S100>' : 'PMM_model/PMM_Module/PMM/PMM_CheckMsgLost_DCDC/Atomic Subsystem'
 * '<S101>' : 'PMM_model/PMM_Module/PMM/PMM_CheckMsgLost_DCDC/MsgTimerTrigger'
 * '<S102>' : 'PMM_model/PMM_Module/PMM/PMM_CheckMsgLost_DCDC/MsgTimerTrigger/Compare To Constant'
 * '<S103>' : 'PMM_model/PMM_Module/PMM/PMM_CheckMsgLost_MCU/Atomic Subsystem'
 * '<S104>' : 'PMM_model/PMM_Module/PMM/PMM_CheckMsgLost_MCU/MsgTimerTrigger'
 * '<S105>' : 'PMM_model/PMM_Module/PMM/PMM_CheckMsgLost_MCU/MsgTimerTrigger/Compare To Constant'
 * '<S106>' : 'PMM_model/PMM_Module/PMM/PMM_State/Work.HVMode.NonRunning.Parking_MCULVDn.MCUWaitLVDn'
 * '<S107>' : 'PMM_model/PMM_Module/PMM/PMM_State/Work.HVMode.NonRunning.Parking_MCULVUP.MCUWaitLVUp'
 * '<S108>' : 'PMM_model/PMM_Module/PMM/PMM_State/Work.LVDown.CheckLVDnToUp'
 * '<S109>' : 'PMM_model/PMM_Module/PMM/PMM_State/Work.LVDown.LVDown.WaitLVDown'
 * '<S110>' : 'PMM_model/PMM_Module/PMM/PMM_State/Work.LVDown.LVStandby.WaitLVStandby'
 * '<S111>' : 'PMM_model/PMM_Module/PMM/PMM_State/Work.LVReady.CheckLVReady'
 * '<S112>' : 'PMM_model/PMM_Module/PMM/PMM_State/Work.LVReady.CheckLVReadyToLVUp'
 * '<S113>' : 'PMM_model/PMM_Module/PMM/PMM_State/Work.HVMode.NonRunning.Parking_MCULVDn.MCUWaitLVDn/PMM_InternalWaitTimeout'
 * '<S114>' : 'PMM_model/PMM_Module/PMM/PMM_State/Work.HVMode.NonRunning.Parking_MCULVUP.MCUWaitLVUp/PMM_InternalWaitTimeout'
 * '<S115>' : 'PMM_model/PMM_Module/PMM/PMM_State/Work.LVDown.CheckLVDnToUp/ PMMTimeoutTimer_SystemTickMs'
 * '<S116>' : 'PMM_model/PMM_Module/PMM/PMM_State/Work.LVDown.LVDown.WaitLVDown/PMM_InternalWaitTimeout'
 * '<S117>' : 'PMM_model/PMM_Module/PMM/PMM_State/Work.LVDown.LVStandby.WaitLVStandby/PMM_InternalWaitTimeout1'
 * '<S118>' : 'PMM_model/PMM_Module/PMM/PMM_State/Work.LVReady.CheckLVReady/Compare To Constant'
 * '<S119>' : 'PMM_model/PMM_Module/PMM/PMM_State/Work.LVReady.CheckLVReady/Compare To Constant1'
 * '<S120>' : 'PMM_model/PMM_Module/PMM/PMM_State/Work.LVReady.CheckLVReady/Compare To Constant2'
 * '<S121>' : 'PMM_model/PMM_Module/PMM/PMM_State/Work.LVReady.CheckLVReadyToLVUp/Compare To Constant1'
 * '<S122>' : 'PMM_model/PMM_Module/PMM/PMM_State/Work.LVReady.CheckLVReadyToLVUp/Compare To Constant2'
 * '<S123>' : 'PMM_model/PMM_Module/PMM/PMM_State/Work.LVReady.CheckLVReadyToLVUp/Compare To Constant3'
 * '<S124>' : 'PMM_model/PMM_Module/PMM/RemoteIChrg_State/CheckAllWakeUp'
 * '<S125>' : 'PMM_model/PMM_Module/PMM/VPMM_VehSts/VPMM_VehStsRunning'
 * '<S126>' : 'PMM_model/PMM_Module/PMM/WakeSrcValid/Chart'
 * '<S127>' : 'PMM_model/PMM_Module/PMM/ignSignalConfirm/Compare To Constant'
 * '<S128>' : 'PMM_model/PMM_Module/PMM/ignSignalConfirm/PEPSSignalConfirm'
 * '<S129>' : 'PMM_model/PMM_Module/PMM/ignSignalConfirm/PEPSSignalConfirm/OffToOnAcc_Reset'
 * '<S130>' : 'PMM_model/PMM_Module/PMM/ignSignalConfirm/PEPSSignalConfirm/OnAccToOff_Reset'
 * '<S131>' : 'PMM_model/PMM_Module/PMM/ignSignalConfirm/PEPSSignalConfirm/OffToOnAcc_Reset/Compare To Constant'
 * '<S132>' : 'PMM_model/PMM_Module/PMM/ignSignalConfirm/PEPSSignalConfirm/OffToOnAcc_Reset/Compare To Constant1'
 * '<S133>' : 'PMM_model/PMM_Module/PMM/ignSignalConfirm/PEPSSignalConfirm/OffToOnAcc_Reset/restart_timer'
 * '<S134>' : 'PMM_model/PMM_Module/PMM/ignSignalConfirm/PEPSSignalConfirm/OnAccToOff_Reset/Compare To Constant'
 * '<S135>' : 'PMM_model/PMM_Module/PMM/ignSignalConfirm/PEPSSignalConfirm/OnAccToOff_Reset/Compare To Constant1'
 * '<S136>' : 'PMM_model/PMM_Module/PMM/ignSignalConfirm/PEPSSignalConfirm/OnAccToOff_Reset/restart_timer'
 */
#endif                                 /* RTW_HEADER_PMM_model_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

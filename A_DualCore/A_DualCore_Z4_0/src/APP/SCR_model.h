/*
 * File: SCR_model.h
 *
 * Code generated for Simulink model 'SCR_model'.
 *
 * Model version                  : 1.2266
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Fri Mar 18 15:47:47 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Freescale->32-bit PowerPC
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. MISRA C:2012 guidelines
 * Validation result: Not run
 */

#ifndef RTW_HEADER_SCR_model_h_
#define RTW_HEADER_SCR_model_h_
#include <stddef.h>
#ifndef SCR_model_COMMON_INCLUDES_
# define SCR_model_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#endif                                 /* SCR_model_COMMON_INCLUDES_ */

#include "SCR_model_types.h"

/* Child system includes */
#include "SPDCtl.h"

/* Includes for objects with custom storage classes. */
#include "SCR_Cal_Data.h"

/* Macros for accessing real-time model data structure */

/* user code (top of header file) */
#include "derivative.h"

/* Block signals and states (auto storage) for system '<Root>' */
typedef struct
{
    rtDW_True_Delay_SCR_model_b_T True_Delay_d;/* '<S5>/True_Delay' */
    rtDW_dataLatch_SCR_model_T dataLatch_f;/* '<S172>/dataLatch' */
    rtDW_Bilateral_Delay_SCR_mo_h_T Bilateral_Delay2;/* '<S221>/Bilateral_Delay2' */
    rtDW_True_Delay_SCR_model_b_T True_Delay1_k;/* '<S220>/True_Delay1' */
    rtDW_True_Delay_SCR_model_b_T True_Delay1;/* '<S219>/True_Delay1' */
    rtDW_True_Delay_SCR_model_T True_Delay_m;/* '<S215>/True_Delay' */
    rtDW_True_Delay_SCR_model_T True_Delay2;/* '<S213>/True_Delay2' */
    rtDW_True_Delay_SCR_model_T True_Delay1_f;/* '<S213>/True_Delay1' */
    rtDW_True_Delay_SCR_model_T True_Delay_ao;/* '<S213>/True_Delay' */
    rtDW_True_Delay_SCR_model_T True_Delay_b;/* '<S245>/True_Delay' */
    rtDW_Kalman_Filter_SCR_model_T Kalman_Filter;/* '<S213>/Kalman_Filter' */
    rtDW_IA_Filter_module_SCR_m_b_T IA_Filter_module_d;/* '<S213>/IA_Filter_module' */
    rtDW_Differential_SCR_model_T Differential;/* '<S213>/Differential' */
    rtDW_True_Delay_SCR_model_T True_Delay1_k5;/* '<S212>/True_Delay1' */
    rtDW_True_Delay_SCR_model_T True_Delay_jq;/* '<S212>/True_Delay' */
    rtDW_Bilateral_Delay_SCR_mo_h_T Bilateral_Delay1;/* '<S172>/Bilateral_Delay1' */
    rtDW_Bilateral_Delay_SCR_mo_h_T Bilateral_Delay_c;/* '<S172>/Bilateral_Delay' */
    rtDW_SetReset_SCR_model_T sf_SetReset_mj;/* '<S197>/SetReset' */
    rtDW_ON_DelayTime_Judge_SCR_m_T ON_DelayTime_Judge1_j;/* '<S197>/ON_DelayTime_Judge1' */
    rtDW_ON_DelayTime_Judge_SCR_m_T ON_DelayTime_Judge_nd;/* '<S197>/ON_DelayTime_Judge' */
    rtDW_True_Delay_SCR_model_b_T True_Delay_j;/* '<S3>/True_Delay' */
    rtDW_dataLatch_SCR_model_T dataLatch3;/* '<S35>/dataLatch3' */
    rtDW_True_Delay_SCR_model_a_T True_Delay_a;/* '<S35>/True_Delay' */
    rtDW_SetReset_SCR_model_k_T sf_SetReset_i;/* '<S155>/SetReset' */
    rtDW_SetReset_SCR_model_k_T sf_SetReset_j;/* '<S154>/SetReset' */
    rtDW_SetReset_SCR_model_k_T sf_SetReset_ka;/* '<S153>/SetReset' */
    rtDW_SetReset_SCR_model_k_T sf_SetReset_k;/* '<S146>/SetReset' */
    rtDW_SetReset_SCR_model_k_T sf_SetReset_m;/* '<S141>/SetReset' */
    rtDW_Key_ShortLongPress_SCR_m_T sf_Key_ShortLongPress_p;/* '<S125>/Key_ShortLongPress' */
    rtDW_SetReset_SCR_model_k_T sf_SetReset_d;/* '<S136>/SetReset' */
    rtDW_Key_ShortLongPress_SCR_m_T sf_Key_ShortLongPress;/* '<S124>/Key_ShortLongPress' */
    rtDW_SetReset_SCR_model_k_T sf_SetReset_n;/* '<S131>/SetReset' */
    rtDW_Zero_Delay_SCR_model_T Zero_Delay2;/* '<S86>/Zero_Delay2' */
    rtDW_Zero_Delay_SCR_model_T Zero_Delay1;/* '<S86>/Zero_Delay1' */
    rtDW_Zero_Delay_SCR_model_T Zero_Delay;/* '<S86>/Zero_Delay' */
    rtDW_ON_DelayTime_Judge_SCR_o_T ON_DelayTime_Judge9;/* '<S86>/ON_DelayTime_Judge9' */
    rtDW_ON_DelayTime_Judge_SCR_m_T ON_DelayTime_Judge8;/* '<S86>/ON_DelayTime_Judge8' */
    rtDW_ON_DelayTime_Judge_SCR_o_T ON_DelayTime_Judge7;/* '<S86>/ON_DelayTime_Judge7' */
    rtDW_ON_DelayTime_Judge_SCR_m_T ON_DelayTime_Judge6;/* '<S86>/ON_DelayTime_Judge6' */
    rtDW_ON_DelayTime_Judge_SCR_m_T ON_DelayTime_Judge5;/* '<S86>/ON_DelayTime_Judge5' */
    rtDW_ON_DelayTime_Judge_SCR_m_T ON_DelayTime_Judge4;/* '<S86>/ON_DelayTime_Judge4' */
    rtDW_ON_DelayTime_Judge_SCR_o_T ON_DelayTime_Judge3;/* '<S86>/ON_DelayTime_Judge3' */
    rtDW_ON_DelayTime_Judge_SCR_m_T ON_DelayTime_Judge2;/* '<S86>/ON_DelayTime_Judge2' */
    rtDW_ON_DelayTime_Judge_SCR_m_T ON_DelayTime_Judge10;/* '<S86>/ON_DelayTime_Judge10' */
    rtDW_ON_DelayTime_Judge_SCR_m_T ON_DelayTime_Judge1_n;/* '<S86>/ON_DelayTime_Judge1' */
    rtDW_ON_DelayTime_Judge_SCR_m_T ON_DelayTime_Judge_n;/* '<S86>/ON_DelayTime_Judge' */
    rtDW_IA_Filter_module_SCR_mod_T IA_Filter_module;/* '<S93>/IA_Filter_module' */
    rtDW_SetReset_SCR_model_T sf_SetReset;/* '<S63>/SetReset' */
    rtDW_ON_DelayTime_Judge_SCR_m_T ON_DelayTime_Judge1;/* '<S63>/ON_DelayTime_Judge1' */
    rtDW_ON_DelayTime_Judge_SCR_m_T ON_DelayTime_Judge;/* '<S63>/ON_DelayTime_Judge' */
    rtDW_Bilateral_Delay_SCR_mode_T Bilateral_Delay;/* '<S15>/Bilateral_Delay' */
    rtDW_dataLatch_SCR_model_T dataLatch;/* '<S13>/dataLatch' */
    rtDW_True_Delay_SCR_model_T True_Delay;/* '<S13>/True_Delay' */
    real_T u1_Cruise_LongPrsAddDecSpd_flag;/* '<S35>/CruiseControl_StateTransition' */
    real32_T Merge2;                   /* '<S294>/Merge2' */
    real32_T Switch;                   /* '<S218>/Switch' */
    real32_T s4s_Cruise_TargetSpd_old; /* '<S35>/Unit Delay' */
    real32_T Switch1;                  /* '<S86>/Switch1' */
    real32_T f4g_CruiseTargetSpd_j;    /* '<S35>/CruiseControl_StateTransition' */
    real32_T Delay_DSTATE;             /* '<S313>/Delay' */
    real32_T Delay_DSTATE_m;           /* '<S304>/Delay' */
    real32_T UnitDelay1_DSTATE;        /* '<S329>/Unit Delay1' */
    real32_T UnitDelay1_DSTATE_o;      /* '<S314>/Unit Delay1' */
    real32_T Delay1_DSTATE;            /* '<S317>/Delay1' */
    real32_T UnitDelay1_DSTATE_g;      /* '<S320>/Unit Delay1' */
    real32_T Delay_DSTATE_c;           /* '<S315>/Delay' */
    real32_T Delay_DSTATE_o;           /* '<S181>/Delay' */
    real32_T Delay1_DSTATE_o;          /* '<S185>/Delay1' */
    real32_T Delay_DSTATE_f;           /* '<S183>/Delay' */
    real32_T UnitDelay_DSTATE;         /* '<S35>/Unit Delay' */
    real32_T UnitDelay_DSTATE_p;       /* '<S86>/Unit Delay' */
    real32_T UnitDelay1_DSTATE_i;      /* '<S86>/Unit Delay1' */
    real32_T Delay_DSTATE_cb;          /* '<S47>/Delay' */
    real32_T Delay_DSTATE_h;           /* '<S49>/Delay' */
    real32_T time;                     /* '<S91>/AbnormalSpd_diagnostic' */
    int32_T DataTypeConversion;        /* '<S6>/Data Type Conversion' */
    int32_T Delay1_DSTATE_nk;          /* '<S26>/Delay1' */
    int32_T Delay2_DSTATE;             /* '<S26>/Delay2' */
    int32_T Delay4_DSTATE;             /* '<S26>/Delay4' */
    int32_T Delay_DSTATE_e3;           /* '<S309>/Delay' */
    int32_T Delay2_DSTATE_o;           /* '<S166>/Delay2' */
    uint32_T DataStoreRead4;           /* '<S1>/Data Store Read4' */
    uint32_T Sum1;                     /* '<S4>/Sum1' */
    uint32_T u4s_keyPressCnt;          /* '<S125>/Key_ShortLongPress' */
    uint32_T u4s_keyPressCnt_b;        /* '<S124>/Key_ShortLongPress' */
    uint32_T Delay1_DSTATE_k;          /* '<S4>/Delay1' */
    uint32_T Delay_DSTATE_d;           /* '<S156>/Delay' */
    uint32_T Delay_DSTATE_n;           /* '<S157>/Delay' */
    uint32_T Delay_DSTATE_mj;          /* '<S159>/Delay' */
    uint32_T Delay_DSTATE_e;           /* '<S160>/Delay' */
    uint32_T Delay_DSTATE_g;           /* '<S162>/Delay' */
    uint32_T Delay_DSTATE_mm;          /* '<S163>/Delay' */
    uint32_T Delay_DSTATE_fs;          /* '<S148>/Delay' */
    uint32_T Delay_DSTATE_a;           /* '<S149>/Delay' */
    uint32_T Delay_DSTATE_od;          /* '<S147>/Delay' */
    uint32_T Delay_DSTATE_g5;          /* '<S143>/Delay' */
    uint32_T Delay_DSTATE_ex;          /* '<S144>/Delay' */
    uint32_T Delay_DSTATE_h3;          /* '<S142>/Delay' */
    uint32_T Delay_DSTATE_ec;          /* '<S138>/Delay' */
    uint32_T Delay_DSTATE_p;           /* '<S139>/Delay' */
    uint32_T Delay_DSTATE_j;           /* '<S133>/Delay' */
    uint32_T Delay_DSTATE_gu;          /* '<S134>/Delay' */
    uint32_T Delay_DSTATE_pe;          /* '<S28>/Delay' */
    uint32_T kph1532_timedelay_timer32;/* '<S293>/NEDC_Enable' */
    uint32_T kph3250_timedelay_timer32;/* '<S293>/NEDC_Enable' */
    uint32_T time_f;                   /* '<S90>/Chart' */
    uint32_T time_l;                   /* '<S128>/CruiseRunReq' */
    uint32_T time_lh;                  /* '<S35>/CRUISECtrlErr' */
    uint32_T timer_kph21;              /* '<S12>/CYCLE_Judge' */
    uint32_T timer_kph20;              /* '<S12>/CYCLE_Judge' */
    uint32_T timer_kph32a;             /* '<S12>/CYCLE_Judge' */
    uint32_T kph2032_timedelay_timer32;/* '<S12>/CYCLE_Judge' */
    uint32_T kph3221_timedelay_timer32;/* '<S12>/CYCLE_Judge' */
    int16_T time_o;                    /* '<S128>/Key_Cancel' */
    uint16_T Timer_kmph120;            /* '<S296>/Chart' */
    uint16_T Timer_kmph70;             /* '<S296>/Chart' */
    uint16_T Timer_kmph50;             /* '<S296>/Chart' */
    uint16_T Timer_kmph35;             /* '<S296>/Chart' */
    uint16_T Timer_kmph32;             /* '<S296>/Chart' */
    uint16_T Timer_kmph15;             /* '<S296>/Chart' */
    uint16_T Add;                      /* '<S92>/Add' */
    uint16_T StepCount;                /* '<S35>/CruiseControl_StateTransition' */
    uint16_T Delay2_DSTATE_f;          /* '<S90>/Delay2' */
    uint16_T Delay_DSTATE_i;           /* '<S92>/Delay' */
    uint16_T Delay_DSTATE_cr;          /* '<S26>/Delay' */
    uint16_T Delay3_DSTATE;            /* '<S26>/Delay3' */
    uint16_T timer_kph15;              /* '<S293>/NEDC_Enable' */
    uint16_T timer_kph32;              /* '<S293>/NEDC_Enable' */
    uint16_T timer_kph50;              /* '<S293>/NEDC_Enable' */
    uint16_T timer_soc60;              /* '<S11>/CONST_Judge' */
    uint16_T timer_soc50;              /* '<S11>/CONST_Judge' */
    uint16_T timer_soc40;              /* '<S11>/CONST_Judge' */
    uint16_T timer_soc80;              /* '<S11>/CONST_Judge' */
    uint16_T timer_soc70;              /* '<S11>/CONST_Judge' */
    uint16_T timer_soc30;              /* '<S11>/CONST_Judge' */
    int8_T UnitDelay2_DSTATE;          /* '<S314>/Unit Delay2' */
    int8_T UnitDelay_DSTATE_h;         /* '<S320>/Unit Delay' */
    int8_T UnitDelay4_DSTATE;          /* '<S314>/Unit Delay4' */
    int8_T UnitDelay2_DSTATE_e;        /* '<S182>/Unit Delay2' */
    int8_T UnitDelay_DSTATE_hx;        /* '<S188>/Unit Delay' */
    int8_T UnitDelay4_DSTATE_k;        /* '<S182>/Unit Delay4' */
    int8_T UnitDelay_DSTATE_hg;        /* '<S54>/Unit Delay' */
    int8_T UnitDelay4_DSTATE_m;        /* '<S48>/Unit Delay4' */
    int8_T If_ActiveSubsystem;         /* '<S294>/If' */
    int8_T If_ActiveSubsystem_i;       /* '<S296>/If' */
    uint8_T Delay2_DSTATE_m[2];        /* '<S35>/Delay2' */
    uint8_T Merge1;                    /* '<S294>/Merge1' */
    uint8_T Switch_l;                  /* '<S172>/Switch' */
    uint8_T Delay1;                    /* '<S35>/Delay1' */
    uint8_T Delay;                     /* '<S78>/Delay' */
    uint8_T Add_c;                     /* '<S128>/Add' */
    uint8_T u1s_key_status;            /* '<S125>/Key_ShortLongPress' */
    uint8_T u1s_key_status_j;          /* '<S124>/Key_ShortLongPress' */
    uint8_T Merge;                     /* '<S86>/Merge' */
    uint8_T Delay1_DSTATE_kg;          /* '<S35>/Delay1' */
    uint8_T Delay_DSTATE_if;           /* '<S78>/Delay' */
    uint8_T icLoad;                    /* '<S304>/Delay' */
    uint8_T icLoad_g;                  /* '<S309>/Delay' */
    uint8_T is_active_c1_SCR_model;    /* '<S296>/Chart' */
    uint8_T is_c1_SCR_model;           /* '<S296>/Chart' */
    uint8_T is_active_kmph15;          /* '<S296>/Chart' */
    uint8_T is_active_kmph32;          /* '<S296>/Chart' */
    uint8_T is_active_kmph50;          /* '<S296>/Chart' */
    uint8_T is_active_kmph35;          /* '<S296>/Chart' */
    uint8_T is_active_kmph70;          /* '<S296>/Chart' */
    uint8_T is_active_kmph120;         /* '<S296>/Chart' */
    uint8_T is_active_kmph15_i;        /* '<S296>/Chart' */
    uint8_T is_active_kmph32_j;        /* '<S296>/Chart' */
    uint8_T is_active_kmph50_h;        /* '<S296>/Chart' */
    uint8_T is_active_kmph35_m;        /* '<S296>/Chart' */
    uint8_T is_active_kmph70_g;        /* '<S296>/Chart' */
    uint8_T is_active_c9_SCR_model;    /* '<S293>/NEDC_Enable' */
    uint8_T is_c9_SCR_model;           /* '<S293>/NEDC_Enable' */
    uint8_T is_nedc_sequence_judge;    /* '<S293>/NEDC_Enable' */
    uint8_T is_active_nedc_sequence_judge;/* '<S293>/NEDC_Enable' */
    uint8_T is_active_nedc_kph_judge;  /* '<S293>/NEDC_Enable' */
    uint8_T is_active_kph15;           /* '<S293>/NEDC_Enable' */
    uint8_T is_active_kph32;           /* '<S293>/NEDC_Enable' */
    uint8_T is_active_kph50;           /* '<S293>/NEDC_Enable' */
    uint8_T is_active_c13_SCR_model;   /* '<S218>/Chart' */
    uint8_T is_c13_SCR_model;          /* '<S218>/Chart' */
    uint8_T icLoad_c;                  /* '<S4>/Delay1' */
    uint8_T is_active_c11_SCR_model;   /* '<S90>/Chart' */
    uint8_T is_c11_SCR_model;          /* '<S90>/Chart' */
    uint8_T is_active_c8_SCR_model;    /* '<S128>/Key_Cancel' */
    uint8_T is_c8_SCR_model;           /* '<S128>/Key_Cancel' */
    uint8_T is_active_c7_SCR_model;    /* '<S128>/CruiseRunReq' */
    uint8_T is_c7_SCR_model;           /* '<S128>/CruiseRunReq' */
    uint8_T is_active_c5_SCR_model;    /* '<S91>/AbnormalSpd_diagnostic' */
    uint8_T is_c5_SCR_model;           /* '<S91>/AbnormalSpd_diagnostic' */
    uint8_T is_active_c3_SCR_model;    /* '<S35>/CruiseControl_StateTransition' */
    uint8_T is_c3_SCR_model;           /* '<S35>/CruiseControl_StateTransition' */
    uint8_T is_ON;                     /* '<S35>/CruiseControl_StateTransition' */
    uint8_T is_Run;                    /* '<S35>/CruiseControl_StateTransition' */
    uint8_T is_Override;               /* '<S35>/CruiseControl_StateTransition' */
    uint8_T is_Normal;                 /* '<S35>/CruiseControl_StateTransition' */
    uint8_T is_SpdSteady;              /* '<S35>/CruiseControl_StateTransition' */
    uint8_T is_ResumeFromCancel;       /* '<S35>/CruiseControl_StateTransition' */
    uint8_T u1s_cruisemode_old;        /* '<S35>/CruiseControl_StateTransition' */
    uint8_T is_active_c6_SCR_model;    /* '<S35>/CRUISECtrlErr' */
    uint8_T is_c6_SCR_model;           /* '<S35>/CRUISECtrlErr' */
    uint8_T is_active_c15_SCR_model;   /* '<S12>/CYCLE_Judge' */
    uint8_T is_c15_SCR_model;          /* '<S12>/CYCLE_Judge' */
    uint8_T is_cycle_sequence_judge;   /* '<S12>/CYCLE_Judge' */
    uint8_T is_active_cycle_sequence_judge;/* '<S12>/CYCLE_Judge' */
    uint8_T is_active_cycle_kph_judge; /* '<S12>/CYCLE_Judge' */
    uint8_T is_active_kph20;           /* '<S12>/CYCLE_Judge' */
    uint8_T is_active_kph21;           /* '<S12>/CYCLE_Judge' */
    uint8_T is_active_kph32a;          /* '<S12>/CYCLE_Judge' */
    uint8_T is_active_c10_SCR_model;   /* '<S11>/CONST_Judge' */
    uint8_T is_c10_SCR_model;          /* '<S11>/CONST_Judge' */
    uint8_T is_active_soc80;           /* '<S11>/CONST_Judge' */
    uint8_T is_active_soc70;           /* '<S11>/CONST_Judge' */
    uint8_T is_cltc_sequence_judge;    /* '<S11>/CONST_Judge' */
    uint8_T is_active_cltc_sequence_judge;/* '<S11>/CONST_Judge' */
    uint8_T is_active_soc30;           /* '<S11>/CONST_Judge' */
    uint8_T is_active_cltc_soc_judge;  /* '<S11>/CONST_Judge' */
    uint8_T is_active_soc60;           /* '<S11>/CONST_Judge' */
    uint8_T is_active_soc50;           /* '<S11>/CONST_Judge' */
    uint8_T is_active_soc40;           /* '<S11>/CONST_Judge' */
    boolean_T LogicalOperator;         /* '<S7>/Logical Operator' */
    boolean_T Merge_g;                 /* '<S294>/Merge' */
    boolean_T bool_kmph120Brake;       /* '<S296>/Chart' */
    boolean_T bool_kmph35Brake;        /* '<S296>/Chart' */
    boolean_T bool_kmph15Brake;        /* '<S296>/Chart' */
    boolean_T bool_kmph32Brake;        /* '<S296>/Chart' */
    boolean_T bool_kmph50Brake;        /* '<S296>/Chart' */
    boolean_T bool_kmph70Brake;        /* '<S296>/Chart' */
    boolean_T bool_nedcBrake;          /* '<S296>/Chart' */
    boolean_T bool_TargetSpdCal;       /* '<S296>/Chart' */
    boolean_T bool_NEDC;               /* '<S293>/NEDC_Enable' */
    boolean_T bool_kph15;              /* '<S293>/NEDC_Enable' */
    boolean_T bool_kph32;              /* '<S293>/NEDC_Enable' */
    boolean_T bool_kph50;              /* '<S293>/NEDC_Enable' */
    boolean_T nonnedc;                 /* '<S293>/NEDC_Enable' */
    boolean_T LogicalOperator1;        /* '<S5>/Logical Operator1' */
    boolean_T flg_set_o;               /* '<S222>/02 set and reset' */
    boolean_T output;                  /* '<S197>/SetReset' */
    boolean_T DataTypeConversion_f;    /* '<S3>/Data Type Conversion' */
    boolean_T DataTypeConversion1;     /* '<S3>/Data Type Conversion1' */
    boolean_T DataTypeConversion2;     /* '<S3>/Data Type Conversion2' */
    boolean_T DataTypeConversion3;     /* '<S3>/Data Type Conversion3' */
    boolean_T Delay3;                  /* '<S90>/Delay3' */
    boolean_T flg_set_o_d;             /* '<S84>/02 set and reset' */
    boolean_T u1_Cruise_LongPrsStepAddDec_fla;/* '<S90>/Chart' */
    boolean_T RelationalOperator_a;    /* '<S87>/Relational Operator' */
    boolean_T RelationalOperator1;     /* '<S87>/Relational Operator1' */
    boolean_T output_k;                /* '<S155>/SetReset' */
    boolean_T output_h;                /* '<S154>/SetReset' */
    boolean_T output_k3;               /* '<S153>/SetReset' */
    boolean_T Switch1_o;               /* '<S147>/Switch1' */
    boolean_T output_e;                /* '<S146>/SetReset' */
    boolean_T Switch1_c;               /* '<S142>/Switch1' */
    boolean_T output_e0;               /* '<S141>/SetReset' */
    boolean_T output_l;                /* '<S136>/SetReset' */
    boolean_T output_i;                /* '<S131>/SetReset' */
    boolean_T Switch1_c5;              /* '<S114>/Switch1' */
    boolean_T AbnormalSpd_diagnostic_flag;/* '<S91>/AbnormalSpd_diagnostic' */
    boolean_T counter_reset;           /* '<S91>/AbnormalSpd_diagnostic' */
    boolean_T u1_CRUISECtrlErr;        /* '<S35>/CRUISECtrlErr' */
    boolean_T flg_set_o_h;             /* '<S20>/02 set and reset' */
    boolean_T bool_CYCLE;              /* '<S12>/CYCLE_Judge' */
    boolean_T UnitDelay1_DSTATE_d;     /* '<S296>/Unit Delay1' */
    boolean_T UnitDelay_DSTATE_pn;     /* '<S296>/Unit Delay' */
    boolean_T UnitDelay_DSTATE_o;      /* '<S306>/Unit Delay' */
    boolean_T UnitDelay1_DSTATE_f;     /* '<S218>/Unit Delay1' */
    boolean_T UnitDelay1_DSTATE_gy;    /* '<S171>/Unit Delay1' */
    boolean_T UnitDelay1_DSTATE_ir;    /* '<S34>/Unit Delay1' */
    boolean_T Delay1_DSTATE_f;         /* '<S156>/Delay1' */
    boolean_T Delay1_DSTATE_a;         /* '<S157>/Delay1' */
    boolean_T Delay1_DSTATE_i;         /* '<S159>/Delay1' */
    boolean_T Delay1_DSTATE_b;         /* '<S160>/Delay1' */
    boolean_T Delay1_DSTATE_kc;        /* '<S162>/Delay1' */
    boolean_T Delay1_DSTATE_p;         /* '<S163>/Delay1' */
    boolean_T Delay1_DSTATE_c;         /* '<S148>/Delay1' */
    boolean_T Delay1_DSTATE_d;         /* '<S149>/Delay1' */
    boolean_T Delay1_DSTATE_cv;        /* '<S147>/Delay1' */
    boolean_T Delay1_DSTATE_p5;        /* '<S143>/Delay1' */
    boolean_T Delay1_DSTATE_f3;        /* '<S144>/Delay1' */
    boolean_T Delay1_DSTATE_b1;        /* '<S142>/Delay1' */
    boolean_T Delay1_DSTATE_dr;        /* '<S138>/Delay1' */
    boolean_T Delay1_DSTATE_ax;        /* '<S139>/Delay1' */
    boolean_T Delay1_DSTATE_g;         /* '<S133>/Delay1' */
    boolean_T Delay1_DSTATE_pt;        /* '<S134>/Delay1' */
    boolean_T UnitDelay3_DSTATE;       /* '<S86>/Unit Delay3' */
    boolean_T UnitDelay2_DSTATE_hg;    /* '<S86>/Unit Delay2' */
    boolean_T u1_Cruise_ShortPrsAddDecSpd_fla;/* '<S35>/CruiseControl_StateTransition' */
    boolean_T bool_kph21;              /* '<S12>/CYCLE_Judge' */
    boolean_T noncycle;                /* '<S12>/CYCLE_Judge' */
    boolean_T bool_kph32a;             /* '<S12>/CYCLE_Judge' */
    boolean_T bool_kph20;              /* '<S12>/CYCLE_Judge' */
    boolean_T bool_soc30;              /* '<S11>/CONST_Judge' */
    boolean_T bool_soc80;              /* '<S11>/CONST_Judge' */
    boolean_T bool_soc70;              /* '<S11>/CONST_Judge' */
    boolean_T bool_soc60;              /* '<S11>/CONST_Judge' */
    boolean_T bool_soc50;              /* '<S11>/CONST_Judge' */
    boolean_T bool_soc40;              /* '<S11>/CONST_Judge' */
}
D_Work_SCR_model_T;

/* Zero-crossing (trigger) state */
typedef struct
{
    ZCSigState Delay_Reset_ZCE;        /* '<S92>/Delay' */
}
PrevZCSigStates_SCR_model_T;

/* Constant parameters (auto storage) */
typedef struct
{
    /* Computed Parameter: uD_Map2_maxIndex
     * Referenced by: '<S65>/2D_Map2'
     */
    uint32_T uD_Map2_maxIndex[2];

    /* Pooled Parameter (Expression: )
     * Referenced by:
     *   '<S65>/2D_Map'
     *   '<S65>/2D_Map1'
     *   '<S66>/2D_Map'
     */
    uint32_T pooled19[2];

    /* Pooled Parameter (Expression: )
     * Referenced by:
     *   '<S66>/2D_Map1'
     *   '<S66>/2D_Map2'
     */
    uint32_T pooled20[2];

    /* Pooled Parameter (Expression: )
     * Referenced by:
     *   '<S199>/2D_Map'
     *   '<S200>/2D_Map'
     */
    uint32_T pooled22[2];

    /* Pooled Parameter (Expression: )
     * Referenced by:
     *   '<S310>/NEDC_PidIntegralMax_Tbl'
     *   '<S310>/NEDC_PidIntegralMin_Tbl'
     */
    uint32_T pooled23[2];

    /* Computed Parameter: uDLookupTable1_bp01Data
     * Referenced by: '<S29>/1-D Lookup Table1'
     */
    uint16_T uDLookupTable1_bp01Data[823];

    /* Computed Parameter: uDLookupTable_bp01Data
     * Referenced by: '<S29>/1-D Lookup Table'
     */
    uint16_T uDLookupTable_bp01Data[900];

    /* Computed Parameter: uDLookupTable1_tableData
     * Referenced by: '<S29>/1-D Lookup Table1'
     */
    int16_T uDLookupTable1_tableData[823];

    /* Computed Parameter: uDLookupTable_tableData
     * Referenced by: '<S29>/1-D Lookup Table'
     */
    int16_T uDLookupTable_tableData[900];
}
ConstParam_SCR_model_T;

/* Block signals and states (auto storage) */
#pragma push
#pragma DATA_SEG __GPAGE_SEG GPAGED_RAM

extern D_Work_SCR_model_T SCR_model_DWork;

#pragma pop

/* External data declarations for dependent source files */

/* Zero-crossing (trigger) state */

#pragma push
#pragma DATA_SEG __GPAGE_SEG GPAGED_RAM

extern PrevZCSigStates_SCR_model_T SCR_model_PrevZCSigState;

#pragma pop

/* Constant parameters (auto storage) */

#pragma push
#pragma DATA_SEG __GPAGE_SEG GPAGED_RAM

extern const ConstParam_SCR_model_T SCR_model_ConstP;

#pragma pop

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern SPDCtl SPDCtl_output;           /* '<S8>/Bus Creator' */
extern real32_T NEDC_SpdCon_VehDyn_Torque;/* '<S327>/Switch2'
                                           * NEDC工况下的纵向动力学公式计算出来的扭矩
                                           */
extern real32_T TargetSpd;             /* '<S304>/MinMax'
                                        * NEDC减速跟线目标车速
                                        */
extern real32_T PID_Spd_Delta;         /* '<S328>/Switch2'
                                        * PID控制器的速度偏差
                                        */
extern real32_T NEDC_pid_p;            /* '<S321>/Product3'
                                        * PID的比例值
                                        */
extern real32_T NEDC_pid_i;            /* '<S318>/Product1'
                                        * PID的积分值
                                        */
extern real32_T NEDC_SpdCon_IntegralTorque;/* '<S320>/Switch5'
                                            * PID的积分器累加值
                                            */
extern real32_T NEDC_SpdCon_PIDTorque; /* '<S324>/Switch3'
                                        * NEDC工况下的PID扭矩
                                        */
extern real32_T NEDC_TorqueGradientLimit_out;/* '<S326>/Switch2'
                                              * NEDC扭矩梯度限制处理后的值
                                              */
extern real32_T NEDCBrakeEnable_Torque_Nm;/* '<S313>/Subtract2'
                                           * NEDC减速跟线目标扭矩值
                                           */
extern real32_T f4g_HDC_RealAccSpd_mpss;/* '<S213>/Saturation'
                                         * 陡坡缓降实际加速度
                                         */
extern real32_T f4g_HDCTargetSpd;      /* '<S218>/Chart'
                                        * 陡坡缓降目标车速
                                        */
extern real32_T f4g_HDC_AccSpd_mpss;   /* '<S218>/Chart'
                                        * 陡坡缓降加速度
                                        */
extern real32_T HDC_TargetTorque;      /* '<S171>/Merge'
                                        * 陡坡缓降目标扭矩
                                        */
extern real32_T f4_M_HDC_BaseTq;       /* '<S177>/Switch1'
                                        * 陡坡缓降加速度对应基础扭矩
                                        */
extern real32_T HDC_pid_p;             /* '<S189>/Product3'
                                        * 陡坡缓降PID调节器P值
                                        */
extern real32_T HDC_pid_i;             /* '<S186>/Product1'
                                        * 陡坡缓降PID调节器I值
                                        */
extern real32_T HDC_i_sum;             /* '<S188>/Switch5'
                                        * 陡坡缓降PID调节器积分之和
                                        */
extern real32_T HDC_SpdCon_PIDTorque;  /* '<S182>/Switch'
                                        * 陡坡缓降PID调节器扭矩值总和
                                        */
extern real32_T TQM_VehSpd;            /* '<S35>/Data Type Conversion1'
                                        * 实际车速
                                        */
extern real32_T f4g_CruiseTargetSpd;   /* '<S82>/Data Type Conversion'
                                        * 巡航目标车速
                                        */
extern real32_T f4g_Cruise_TargetTorque;/* '<S34>/Merge'
                                         * 定速巡航对外输出目标扭矩
                                         */
extern real32_T u2s_ICMVehSpdDisp_kph; /* '<S93>/Switch6'
                                        * 仪表滤波后显示车速
                                        */
extern real32_T f4s_CruiseVehSpd;      /* '<S86>/Switch4'
                                        * 定速巡航目标巡航车速
                                        */
extern real32_T f4_M_CRS_BaseTq;       /* '<S39>/Switch1'
                                        * 用于观测基础扭矩
                                        */
extern real32_T Pid_PidMax;            /* '<S42>/Constant9'
                                        * PID允许最大值
                                        */
extern real32_T Pid_Spd_Delta;         /* '<S70>/Switch2'
                                        * PID的车速偏差
                                        */
extern real32_T Pid_Kp;                /* '<S66>/Switch'
                                        * Kp参数
                                        */
extern real32_T Cruise_pid_p;          /* '<S55>/Product3'
                                        * PID的比例值
                                        */
extern real32_T Pid_IntegratorReset_value;/* '<S62>/Constant2'
                                           * PID的积分器复位值
                                           */
extern real32_T Pid_IntegratorMax;     /* '<S42>/Constant3'
                                        * PID的积分器最大值
                                        */
extern real32_T Pid_Ki;                /* '<S65>/Switch'
                                        * Ki参数
                                        */
extern real32_T Cruise_pid_i;          /* '<S52>/Product1'
                                        * PID的积分值
                                        */
extern real32_T Pid_IntegratorMin;     /* '<S42>/Constant5'
                                        * PID的积分器最小值
                                        */
extern real32_T Cruise_i_sum;          /* '<S54>/Switch5'
                                        * PID的积分器累加值
                                        */
extern real32_T Pid_PidMin;            /* '<S42>/Constant10'
                                        * PID允许最小值
                                        */
extern real32_T Cruise_SpdCon_PIDTorque;/* '<S48>/Switch'
                                         * 用于观测PID扭矩
                                         */
extern int16_T u2_M_CLTCTargetElecMotSpd_rpm;/* '<S27>/Divide3'
                                              * CLTC工况功能目标转速
                                              */
extern uint16_T u2_M_CLTCmodeTimer_s;  /* '<S28>/Data Type Conversion1'
                                        * CLTC工况功能系统时间
                                        */
extern int16_T u2_M_CLTCTargetSpd_mps; /* '<S26>/Data Type Conversion2'
                                        * CLTC工况功能目标车速
                                        */
extern int16_T u2_M_CLTCAccSpd_mpss;   /* '<S29>/Switch'
                                        * CLTC工况功能加速度
                                        */
extern int16_T accBrake;               /* '<S296>/Chart'
                                        * NEDC减速跟线识别到的减速度值
                                        */
extern int8_T Cruise_SpdCon_Pid_IntegralSts;/* '<S48>/Switch1'
                                             * PID的积分器是否上溢出或下溢出标志
                                             */
extern int8_T Cruise_SpdCon_Pid_PidSts;/* '<S48>/Switch2'
                                        * PID是否上溢出或下溢出标志
                                        */
extern uint8_T accBrakeType;           /* '<S296>/Chart'
                                        * NEDC减速跟线识别到的减速度类型
                                        */
extern uint8_T accBrakeTypeHistory;    /* '<S296>/Chart'
                                        * NEDC减速跟线识别到的前一次减速度类型
                                        */
extern uint8_T accBrake_Position;      /* '<S296>/Chart'
                                        * NEDC状态跳转标志位
                                        */
extern uint8_T u2s_NEDCposition_enum;  /* '<S293>/NEDC_Enable'
                                        * NEDC循环识别标识位
                                        */
extern uint8_T u1s_IcmCrsTargetSpd;    /* '<S76>/Data Type Conversion2'
                                        * 向ICM发送的用于显示用的目标巡航车速
                                        */
extern uint8_T u1s_IcmVehSpd;          /* '<S77>/Data Type Conversion2'
                                        * ICM显示的实际车速（内部测试用）
                                        */
extern uint8_T u1_GearMode_CRUISECtrlSys_enum;/* '<S35>/Switch2'
                                               * 定速巡航状态档位使用
                                               */
extern uint8_T u1_CRUISECtrlSys;       /* '<S81>/Switch2'
                                        * 定速巡航系统状态
                                        */
extern uint8_T u1s_SetKey_status;      /* '<S87>/Switch'
                                        * SET-按键按下状态
                                        */
extern uint8_T u1s_ResKey_status;      /* '<S87>/Switch1'
                                        * RES+按键按下状态
                                        */
extern uint8_T u1s_cruisemode;         /* '<S35>/CruiseControl_StateTransition'
                                        * 巡航工作模式
                                        */
extern uint8_T u1s_KeySpdType;         /* '<S35>/CruiseControl_StateTransition'
                                        * SET-/RES+按键的状态
                                        */
extern uint8_T u2s_CyclePosition_enum; /* '<S12>/CYCLE_Judge'
                                        * CLTC工况功能小循环判断工况标志位
                                        */
extern uint8_T u2s_CLTCposition_enum;  /* '<S11>/CONST_Judge'
                                        * CLTC工况功能等速判断工况标志位
                                        */
extern boolean_T bis_HDC_NonDriveGear_flg;/* '<S215>/Logical Operator'
                                           * 陡坡缓降档位、车速不满足使能标志位
                                           */
extern boolean_T bis_BrakeSwitchAct_flg;/* '<S216>/Logical Operator13'
                                         * 陡坡缓降踩制动使能标志位
                                         */
extern boolean_T bis_ParkingSwitchAct_flg;/* '<S217>/Logical Operator13'
                                           * 陡坡缓降驻车开关使能标志位
                                           */
extern boolean_T bis_TargetTqPositive_flg;/* '<S219>/True_Delay1'
                                           * 陡坡缓降退出条件目标扭矩符号正向标志位
                                           */
extern boolean_T bis_EHUVehrpEnable_flg;/* '<S220>/True_Delay1'
                                         * 陡坡缓降使能蠕行使能判断标志位
                                         */
extern boolean_T bis_HDC_Unable_flg;   /* '<S172>/Logical Operator10'
                                        * 陡坡缓降未使能标志位
                                        */
extern boolean_T bis_HDC_DriveGearSts_flg;/* '<S212>/Logical Operator3'
                                           * 陡坡缓降档位、车速满足使能标志位
                                           */
extern boolean_T bis_AcceModeDriving_flg;/* '<S245>/Logical Operator1'
                                          * 陡坡缓降使能加速度判断标志位
                                          */
extern boolean_T bis_HDC_AccSpdAction_flg;/* '<S213>/Logical Operator3'
                                           * 陡坡缓降加速度满足使能标志位
                                           */
extern boolean_T bis_HDC_Enable_flg;   /* '<S172>/Logical Operator5'
                                        * 陡坡缓降使能标志位
                                        */
extern boolean_T flag1;                /* '<S286>/Compare'
                                        * 标志位1
                                        */
extern boolean_T flag2;                /* '<S221>/Relational Operator'
                                        * 标志位2
                                        */
extern boolean_T flag3;                /* '<S221>/Relational Operator1'
                                        * 标志位3
                                        */
extern boolean_T bis_GearDDriverRemind_flg;/* '<S221>/Logical Operator2'
                                            * 陡坡缓降D挡功能受限标志位
                                            */
extern boolean_T bis_GearRDriverRemind_flg;/* '<S221>/Logical Operator11'
                                            * 陡坡缓降R挡功能受限标志位
                                            */
extern boolean_T bis_HDCDriverRemind_flg;/* '<S221>/Bilateral_Delay2'
                                          * 陡坡缓降受限提醒标志位
                                          */
extern boolean_T bis_HDCrun_flg;       /* '<S211>/Switch2'
                                        * 陡坡缓降工作标志位
                                        */
extern boolean_T HDC_IntegralClamping_AntiWindup_flg;/* '<S187>/Logical Operator1'
                                                      * 陡坡缓降PID调节器积分抗饱和标志位
                                                      */
extern boolean_T bis_PTReady_flg;      /* '<S35>/OverRide2'
                                        * 整车Ready标志
                                        */
extern boolean_T bis_BrkPress_flg;     /* '<S85>/Logical Operator'
                                        * 踩下制动踏板标志位
                                        */
extern boolean_T bis_AbsAebEspIntervene_enable;/* '<S3>/Logical Operator1'
                                                * ESP干预标志位
                                                */
extern boolean_T u1g_CRUISECtrlErr;    /* '<S79>/Switch2'
                                        * 定速巡航系统故障
                                        */
extern boolean_T bis_GearD_flg;        /* '<S89>/Logical Operator'
                                        * D档标志位
                                        */
extern boolean_T bis_AccelPdlPress_flg;/* '<S88>/Data Type Conversion'
                                        * 加速踏板踩下标志
                                        */
extern boolean_T bis_KeyCancel_flag;   /* '<S130>/Switch5'
                                        * Cancel按键按下标志
                                        */
extern boolean_T bis_KeyOnOff_flag;    /* '<S129>/Switch6'
                                        * OnOFF按键按下标志
                                        */
extern boolean_T u1s_KeyCancel_flag;   /* '<S128>/Key_Cancel'
                                        * 怀挡方案Cancel功能标志位
                                        */
extern boolean_T CRS_CruiseRunReq_flg; /* '<S128>/CruiseRunReq'
                                        * 定速巡航激活功能怀挡控制标志位
                                        */
extern boolean_T bis_AbnSpd_diagnostic_flg;/* '<S86>/Switch3'
                                            * 巡航系统检测到坏路工况标志位
                                            */
extern boolean_T bis_VehSpdDiffFault_flg;/* '<S86>/ON_DelayTime_Judge5'
                                          * 巡航车速与目标车速差过大导致异常标志位
                                          */
extern boolean_T bis_MinSpdNoTouch_flg;/* '<S86>/ON_DelayTime_Judge8'
                                        * 实际车速小于巡航车速故障标志位
                                        */
extern boolean_T bis_MaxSpdOffUpLimitFault_flg;/* '<S86>/ON_DelayTime_Judge10'
                                                * 定速巡航实际车速超出最大车速故障标志位
                                                */
extern boolean_T bis_CruiseVehSpdSatisfy_flg;/* '<S86>/ON_DelayTime_Judge4'
                                              * 实际车速是否满足巡航上、下限车速判断标志
                                              */
extern boolean_T bis_CruiseFault_high; /* '<S86>/Zero_Delay2'
                                        * 定速巡航高级故障发生标志
                                        */
extern boolean_T bis_CruiseFault_mid;  /* '<S86>/Zero_Delay'
                                        * 定速巡航中级故障发生标志
                                        */
extern boolean_T bis_CRUISEModStop_flg;/* '<S110>/Switch2'
                                        * 定速巡航故障文字提醒标志位
                                        */
extern boolean_T big_CruiseRun_flg;    /* '<S35>/CruiseControl_StateTransition'
                                        * 定速巡航运行标志
                                        */
extern boolean_T big_SetResumeAccDec_flag;/* '<S35>/CruiseControl_StateTransition'
                                           * 判断SET-/RES+按键是设定恢复功能还是加减目标巡航车速功能
                                           */
extern boolean_T big_CruiseSpdFilter_flg;/* '<S35>/CruiseControl_StateTransition'
                                          * 定速巡航目标车速滤波标志位
                                          */
extern boolean_T Pid_IntegratorReset_flag;/* '<S62>/Logical Operator5'
                                           * PID的积分器复位标志
                                           */
extern boolean_T Cruise_IntegralClamping_AntiWindup_flag;/* '<S53>/Logical Operator1'
                                                          * PID的积分抗饱和标志
                                                          */
extern boolean_T Cruise_Pid_IntegralHold_flag;/* '<S63>/SetReset'
                                               * PID积分器的积分保持标志位
                                               */
extern boolean_T b1_M_CLTC_VehStsFlag; /* '<S15>/Bilateral_Delay'
                                        * CLTC工况功能车辆状态标志位
                                        */
extern boolean_T b1_M_CLTC_ConstantSpdFlag;/* '<S13>/dataLatch'
                                            * CLTC工况功能车辆前后车轮差值标志位
                                            */
extern boolean_T b1_M_CLTC_CYCLEFlag;  /* '<S14>/Switch2'
                                        * CLTC工况功能激活标志位
                                        */
extern boolean_T b1_M_CLTC_CONSTFlag;  /* '<S11>/CONST_Judge'
                                        * CLTC工况功能车辆等速行驶标志位
                                        */

/* Model entry point functions */
extern void SCR_model_initialize(void);
extern void SCR_model_step(void);
extern void SCR_model_terminate(void);

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
 * '<Root>' : 'SCR_model'
 * '<S1>'   : 'SCR_model/SPDCtl'
 * '<S2>'   : 'SCR_model/SPDCtl/CLTC_Control'
 * '<S3>'   : 'SCR_model/SPDCtl/Cruise_Control'
 * '<S4>'   : 'SCR_model/SPDCtl/Get_TickDiff_ms'
 * '<S5>'   : 'SCR_model/SPDCtl/Hill_Descent_Control'
 * '<S6>'   : 'SCR_model/SPDCtl/NEDC_New_Control'
 * '<S7>'   : 'SCR_model/SPDCtl/PUD_Process'
 * '<S8>'   : 'SCR_model/SPDCtl/SPDCtl_OUT'
 * '<S9>'   : 'SCR_model/SPDCtl/CLTC_Control/CLTC_Condition'
 * '<S10>'  : 'SCR_model/SPDCtl/CLTC_Control/TargetElecMotSpd'
 * '<S11>'  : 'SCR_model/SPDCtl/CLTC_Control/CLTC_Condition/CONST_Judge'
 * '<S12>'  : 'SCR_model/SPDCtl/CLTC_Control/CLTC_Condition/CYCLE_Judge'
 * '<S13>'  : 'SCR_model/SPDCtl/CLTC_Control/CLTC_Condition/ConstantSpdFlag'
 * '<S14>'  : 'SCR_model/SPDCtl/CLTC_Control/CLTC_Condition/OverRide'
 * '<S15>'  : 'SCR_model/SPDCtl/CLTC_Control/CLTC_Condition/VehStsFlag'
 * '<S16>'  : 'SCR_model/SPDCtl/CLTC_Control/CLTC_Condition/CONST_Judge/CONST_Judge'
 * '<S17>'  : 'SCR_model/SPDCtl/CLTC_Control/CLTC_Condition/CYCLE_Judge/CYCLE_Judge'
 * '<S18>'  : 'SCR_model/SPDCtl/CLTC_Control/CLTC_Condition/ConstantSpdFlag/Compare To Constant'
 * '<S19>'  : 'SCR_model/SPDCtl/CLTC_Control/CLTC_Condition/ConstantSpdFlag/True_Delay'
 * '<S20>'  : 'SCR_model/SPDCtl/CLTC_Control/CLTC_Condition/ConstantSpdFlag/dataLatch'
 * '<S21>'  : 'SCR_model/SPDCtl/CLTC_Control/CLTC_Condition/ConstantSpdFlag/True_Delay/Compare To Constant1'
 * '<S22>'  : 'SCR_model/SPDCtl/CLTC_Control/CLTC_Condition/ConstantSpdFlag/dataLatch/02 set and reset'
 * '<S23>'  : 'SCR_model/SPDCtl/CLTC_Control/CLTC_Condition/VehStsFlag/Bilateral_Delay'
 * '<S24>'  : 'SCR_model/SPDCtl/CLTC_Control/CLTC_Condition/VehStsFlag/Bilateral_Delay/Compare To Constant1'
 * '<S25>'  : 'SCR_model/SPDCtl/CLTC_Control/CLTC_Condition/VehStsFlag/Bilateral_Delay/Compare To Constant2'
 * '<S26>'  : 'SCR_model/SPDCtl/CLTC_Control/TargetElecMotSpd/CLTCTargetSpd'
 * '<S27>'  : 'SCR_model/SPDCtl/CLTC_Control/TargetElecMotSpd/CLTC_TargetElecMotSpd'
 * '<S28>'  : 'SCR_model/SPDCtl/CLTC_Control/TargetElecMotSpd/CLTCmodeTimer'
 * '<S29>'  : 'SCR_model/SPDCtl/CLTC_Control/TargetElecMotSpd/TargetAccCal'
 * '<S30>'  : 'SCR_model/SPDCtl/CLTC_Control/TargetElecMotSpd/CLTC_TargetElecMotSpd/Compare To Constant'
 * '<S31>'  : 'SCR_model/SPDCtl/CLTC_Control/TargetElecMotSpd/TargetAccCal/Compare To Constant'
 * '<S32>'  : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module'
 * '<S33>'  : 'SCR_model/SPDCtl/Cruise_Control/True_Delay'
 * '<S34>'  : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/LowerController'
 * '<S35>'  : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/UpperController'
 * '<S36>'  : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/LowerController/CruiseNonRun'
 * '<S37>'  : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/LowerController/CruiseRun'
 * '<S38>'  : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/LowerController/CruiseRun_Judgement'
 * '<S39>'  : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/LowerController/CruiseRun/BaseTorque'
 * '<S40>'  : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/LowerController/CruiseRun/CruiseTorque_Filter'
 * '<S41>'  : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/LowerController/CruiseRun/Cruise_SpdCon_TorqueController(PIDIC)'
 * '<S42>'  : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/LowerController/CruiseRun/PID_Configure'
 * '<S43>'  : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/LowerController/CruiseRun/RollingCoef'
 * '<S44>'  : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/LowerController/CruiseRun/CruiseTorque_Filter/Torque_Filter'
 * '<S45>'  : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/LowerController/CruiseRun/CruiseTorque_Filter/Torque_Filter/TorqueFilterRate_Calc'
 * '<S46>'  : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/LowerController/CruiseRun/CruiseTorque_Filter/Torque_Filter/TorqueFilterRate_Calc/TorqueFilterRate_Calc'
 * '<S47>'  : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/LowerController/CruiseRun/Cruise_SpdCon_TorqueController(PIDIC)/FirstOrderFilter'
 * '<S48>'  : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/LowerController/CruiseRun/Cruise_SpdCon_TorqueController(PIDIC)/PIDICController'
 * '<S49>'  : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/LowerController/CruiseRun/Cruise_SpdCon_TorqueController(PIDIC)/TorqueGradientLimit'
 * '<S50>'  : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/LowerController/CruiseRun/Cruise_SpdCon_TorqueController(PIDIC)/VehicleLongitudinalDynamic'
 * '<S51>'  : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/LowerController/CruiseRun/Cruise_SpdCon_TorqueController(PIDIC)/PIDICController/DGain'
 * '<S52>'  : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/LowerController/CruiseRun/Cruise_SpdCon_TorqueController(PIDIC)/PIDICController/IGain'
 * '<S53>'  : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/LowerController/CruiseRun/Cruise_SpdCon_TorqueController(PIDIC)/PIDICController/IntegralClamping_AntiWindup'
 * '<S54>'  : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/LowerController/CruiseRun/Cruise_SpdCon_TorqueController(PIDIC)/PIDICController/Integrator'
 * '<S55>'  : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/LowerController/CruiseRun/Cruise_SpdCon_TorqueController(PIDIC)/PIDICController/PGain'
 * '<S56>'  : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/LowerController/CruiseRun/Cruise_SpdCon_TorqueController(PIDIC)/PIDICController/PID_Sum'
 * '<S57>'  : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/LowerController/CruiseRun/Cruise_SpdCon_TorqueController(PIDIC)/PIDICController/Integrator/Subsystem2'
 * '<S58>'  : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/LowerController/CruiseRun/Cruise_SpdCon_TorqueController(PIDIC)/PIDICController/PID_Sum/Subsystem1'
 * '<S59>'  : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/LowerController/CruiseRun/Cruise_SpdCon_TorqueController(PIDIC)/TorqueGradientLimit/Saturation Dynamic'
 * '<S60>'  : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/LowerController/CruiseRun/Cruise_SpdCon_TorqueController(PIDIC)/TorqueGradientLimit/Saturation Dynamic1'
 * '<S61>'  : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/LowerController/CruiseRun/Cruise_SpdCon_TorqueController(PIDIC)/VehicleLongitudinalDynamic/Saturation Dynamic'
 * '<S62>'  : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/LowerController/CruiseRun/PID_Configure/Integrator_Reset'
 * '<S63>'  : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/LowerController/CruiseRun/PID_Configure/PID_IntegralHold_SpdDelta'
 * '<S64>'  : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/LowerController/CruiseRun/PID_Configure/PID_Spd_Delta'
 * '<S65>'  : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/LowerController/CruiseRun/PID_Configure/pid_ki'
 * '<S66>'  : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/LowerController/CruiseRun/PID_Configure/pid_kp'
 * '<S67>'  : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/LowerController/CruiseRun/PID_Configure/PID_IntegralHold_SpdDelta/ON_DelayTime_Judge'
 * '<S68>'  : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/LowerController/CruiseRun/PID_Configure/PID_IntegralHold_SpdDelta/ON_DelayTime_Judge1'
 * '<S69>'  : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/LowerController/CruiseRun/PID_Configure/PID_IntegralHold_SpdDelta/SetReset'
 * '<S70>'  : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/LowerController/CruiseRun/PID_Configure/PID_Spd_Delta/Saturation Dynamic'
 * '<S71>'  : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/UpperController/CRUISECtrlErr'
 * '<S72>'  : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/UpperController/Compare To Constant'
 * '<S73>'  : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/UpperController/Compare To Constant1'
 * '<S74>'  : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/UpperController/Compare To Constant2'
 * '<S75>'  : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/UpperController/CruiseControl_StateTransition'
 * '<S76>'  : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/UpperController/ICM_CruiseTargetSpd_Disp'
 * '<S77>'  : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/UpperController/ICM_VehSpd_Debug'
 * '<S78>'  : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/UpperController/Input_SWC'
 * '<S79>'  : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/UpperController/OverRide1'
 * '<S80>'  : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/UpperController/OverRide2'
 * '<S81>'  : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/UpperController/OverRide3'
 * '<S82>'  : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/UpperController/TargetSpeedFilter'
 * '<S83>'  : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/UpperController/True_Delay'
 * '<S84>'  : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/UpperController/dataLatch3'
 * '<S85>'  : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/UpperController/Input_SWC/BrakePedalPress_Judgement'
 * '<S86>'  : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/UpperController/Input_SWC/CruiseDiagnostic'
 * '<S87>'  : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/UpperController/Input_SWC/CruiseKey_Recoginition'
 * '<S88>'  : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/UpperController/Input_SWC/CruiseOverride_Judgement'
 * '<S89>'  : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/UpperController/Input_SWC/GearD_Judgement'
 * '<S90>'  : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/UpperController/Input_SWC/LongPrsStepAddDec_Judgement'
 * '<S91>'  : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/UpperController/Input_SWC/CruiseDiagnostic/AbnormalSpd_diagnostic'
 * '<S92>'  : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/UpperController/Input_SWC/CruiseDiagnostic/Diagnostic_Counter'
 * '<S93>'  : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/UpperController/Input_SWC/CruiseDiagnostic/IA_Filter_module'
 * '<S94>'  : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/UpperController/Input_SWC/CruiseDiagnostic/If Action Subsystem'
 * '<S95>'  : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/UpperController/Input_SWC/CruiseDiagnostic/If Action Subsystem1'
 * '<S96>'  : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/UpperController/Input_SWC/CruiseDiagnostic/If Action Subsystem2'
 * '<S97>'  : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/UpperController/Input_SWC/CruiseDiagnostic/If Action Subsystem3'
 * '<S98>'  : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/UpperController/Input_SWC/CruiseDiagnostic/If Action Subsystem4'
 * '<S99>'  : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/UpperController/Input_SWC/CruiseDiagnostic/ON_DelayTime_Judge'
 * '<S100>' : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/UpperController/Input_SWC/CruiseDiagnostic/ON_DelayTime_Judge1'
 * '<S101>' : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/UpperController/Input_SWC/CruiseDiagnostic/ON_DelayTime_Judge10'
 * '<S102>' : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/UpperController/Input_SWC/CruiseDiagnostic/ON_DelayTime_Judge2'
 * '<S103>' : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/UpperController/Input_SWC/CruiseDiagnostic/ON_DelayTime_Judge3'
 * '<S104>' : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/UpperController/Input_SWC/CruiseDiagnostic/ON_DelayTime_Judge4'
 * '<S105>' : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/UpperController/Input_SWC/CruiseDiagnostic/ON_DelayTime_Judge5'
 * '<S106>' : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/UpperController/Input_SWC/CruiseDiagnostic/ON_DelayTime_Judge6'
 * '<S107>' : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/UpperController/Input_SWC/CruiseDiagnostic/ON_DelayTime_Judge7'
 * '<S108>' : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/UpperController/Input_SWC/CruiseDiagnostic/ON_DelayTime_Judge8'
 * '<S109>' : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/UpperController/Input_SWC/CruiseDiagnostic/ON_DelayTime_Judge9'
 * '<S110>' : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/UpperController/Input_SWC/CruiseDiagnostic/OverRide1'
 * '<S111>' : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/UpperController/Input_SWC/CruiseDiagnostic/Subsystem'
 * '<S112>' : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/UpperController/Input_SWC/CruiseDiagnostic/Subsystem1'
 * '<S113>' : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/UpperController/Input_SWC/CruiseDiagnostic/Zero_Delay'
 * '<S114>' : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/UpperController/Input_SWC/CruiseDiagnostic/Zero_Delay1'
 * '<S115>' : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/UpperController/Input_SWC/CruiseDiagnostic/Zero_Delay2'
 * '<S116>' : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/UpperController/Input_SWC/CruiseDiagnostic/AbnormalSpd_diagnostic/AbnormalSpd_diagnostic'
 * '<S117>' : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/UpperController/Input_SWC/CruiseDiagnostic/IA_Filter_module/IA_Filter_module'
 * '<S118>' : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/UpperController/Input_SWC/CruiseDiagnostic/IA_Filter_module/IA_Filter_module/Subsystem2'
 * '<S119>' : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/UpperController/Input_SWC/CruiseDiagnostic/IA_Filter_module/IA_Filter_module/Subsystem2/Subsystem'
 * '<S120>' : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/UpperController/Input_SWC/CruiseDiagnostic/IA_Filter_module/IA_Filter_module/Subsystem2/Subsystem1'
 * '<S121>' : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/UpperController/Input_SWC/CruiseDiagnostic/Zero_Delay/Compare To Constant1'
 * '<S122>' : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/UpperController/Input_SWC/CruiseDiagnostic/Zero_Delay1/Compare To Constant1'
 * '<S123>' : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/UpperController/Input_SWC/CruiseDiagnostic/Zero_Delay2/Compare To Constant1'
 * '<S124>' : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/UpperController/Input_SWC/CruiseKey_Recoginition/KeyJudge'
 * '<S125>' : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/UpperController/Input_SWC/CruiseKey_Recoginition/KeyJudge1'
 * '<S126>' : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/UpperController/Input_SWC/CruiseKey_Recoginition/KeyPressJudge'
 * '<S127>' : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/UpperController/Input_SWC/CruiseKey_Recoginition/KeyPressJudge1'
 * '<S128>' : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/UpperController/Input_SWC/CruiseKey_Recoginition/KeyPressJudge2'
 * '<S129>' : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/UpperController/Input_SWC/CruiseKey_Recoginition/Subsystem'
 * '<S130>' : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/UpperController/Input_SWC/CruiseKey_Recoginition/Subsystem1'
 * '<S131>' : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/UpperController/Input_SWC/CruiseKey_Recoginition/KeyJudge/Key_Debouncer'
 * '<S132>' : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/UpperController/Input_SWC/CruiseKey_Recoginition/KeyJudge/Key_ShortLongPress'
 * '<S133>' : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/UpperController/Input_SWC/CruiseKey_Recoginition/KeyJudge/Key_Debouncer/ON_DelayTime_Judge'
 * '<S134>' : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/UpperController/Input_SWC/CruiseKey_Recoginition/KeyJudge/Key_Debouncer/ON_DelayTime_Judge1'
 * '<S135>' : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/UpperController/Input_SWC/CruiseKey_Recoginition/KeyJudge/Key_Debouncer/SetReset'
 * '<S136>' : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/UpperController/Input_SWC/CruiseKey_Recoginition/KeyJudge1/Key_Debouncer'
 * '<S137>' : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/UpperController/Input_SWC/CruiseKey_Recoginition/KeyJudge1/Key_ShortLongPress'
 * '<S138>' : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/UpperController/Input_SWC/CruiseKey_Recoginition/KeyJudge1/Key_Debouncer/ON_DelayTime_Judge'
 * '<S139>' : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/UpperController/Input_SWC/CruiseKey_Recoginition/KeyJudge1/Key_Debouncer/ON_DelayTime_Judge1'
 * '<S140>' : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/UpperController/Input_SWC/CruiseKey_Recoginition/KeyJudge1/Key_Debouncer/SetReset'
 * '<S141>' : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/UpperController/Input_SWC/CruiseKey_Recoginition/KeyPressJudge/Key_Debouncer'
 * '<S142>' : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/UpperController/Input_SWC/CruiseKey_Recoginition/KeyPressJudge/ON_DelayTime_Judge1'
 * '<S143>' : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/UpperController/Input_SWC/CruiseKey_Recoginition/KeyPressJudge/Key_Debouncer/ON_DelayTime_Judge'
 * '<S144>' : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/UpperController/Input_SWC/CruiseKey_Recoginition/KeyPressJudge/Key_Debouncer/ON_DelayTime_Judge1'
 * '<S145>' : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/UpperController/Input_SWC/CruiseKey_Recoginition/KeyPressJudge/Key_Debouncer/SetReset'
 * '<S146>' : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/UpperController/Input_SWC/CruiseKey_Recoginition/KeyPressJudge1/Key_Debouncer'
 * '<S147>' : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/UpperController/Input_SWC/CruiseKey_Recoginition/KeyPressJudge1/ON_DelayTime_Judge1'
 * '<S148>' : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/UpperController/Input_SWC/CruiseKey_Recoginition/KeyPressJudge1/Key_Debouncer/ON_DelayTime_Judge'
 * '<S149>' : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/UpperController/Input_SWC/CruiseKey_Recoginition/KeyPressJudge1/Key_Debouncer/ON_DelayTime_Judge1'
 * '<S150>' : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/UpperController/Input_SWC/CruiseKey_Recoginition/KeyPressJudge1/Key_Debouncer/SetReset'
 * '<S151>' : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/UpperController/Input_SWC/CruiseKey_Recoginition/KeyPressJudge2/CruiseRunReq'
 * '<S152>' : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/UpperController/Input_SWC/CruiseKey_Recoginition/KeyPressJudge2/Key_Cancel'
 * '<S153>' : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/UpperController/Input_SWC/CruiseKey_Recoginition/KeyPressJudge2/Key_Debouncer'
 * '<S154>' : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/UpperController/Input_SWC/CruiseKey_Recoginition/KeyPressJudge2/Key_Debouncer1'
 * '<S155>' : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/UpperController/Input_SWC/CruiseKey_Recoginition/KeyPressJudge2/Key_Debouncer2'
 * '<S156>' : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/UpperController/Input_SWC/CruiseKey_Recoginition/KeyPressJudge2/Key_Debouncer/ON_DelayTime_Judge'
 * '<S157>' : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/UpperController/Input_SWC/CruiseKey_Recoginition/KeyPressJudge2/Key_Debouncer/ON_DelayTime_Judge1'
 * '<S158>' : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/UpperController/Input_SWC/CruiseKey_Recoginition/KeyPressJudge2/Key_Debouncer/SetReset'
 * '<S159>' : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/UpperController/Input_SWC/CruiseKey_Recoginition/KeyPressJudge2/Key_Debouncer1/ON_DelayTime_Judge'
 * '<S160>' : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/UpperController/Input_SWC/CruiseKey_Recoginition/KeyPressJudge2/Key_Debouncer1/ON_DelayTime_Judge1'
 * '<S161>' : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/UpperController/Input_SWC/CruiseKey_Recoginition/KeyPressJudge2/Key_Debouncer1/SetReset'
 * '<S162>' : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/UpperController/Input_SWC/CruiseKey_Recoginition/KeyPressJudge2/Key_Debouncer2/ON_DelayTime_Judge'
 * '<S163>' : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/UpperController/Input_SWC/CruiseKey_Recoginition/KeyPressJudge2/Key_Debouncer2/ON_DelayTime_Judge1'
 * '<S164>' : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/UpperController/Input_SWC/CruiseKey_Recoginition/KeyPressJudge2/Key_Debouncer2/SetReset'
 * '<S165>' : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/UpperController/Input_SWC/LongPrsStepAddDec_Judgement/Chart'
 * '<S166>' : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/UpperController/TargetSpeedFilter/FilterCtl'
 * '<S167>' : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/UpperController/TargetSpeedFilter/FilterCtl/Saturation Dynamic'
 * '<S168>' : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/UpperController/True_Delay/Compare To Constant1'
 * '<S169>' : 'SCR_model/SPDCtl/Cruise_Control/Cruise_Control_Module/UpperController/dataLatch3/02 set and reset'
 * '<S170>' : 'SCR_model/SPDCtl/Cruise_Control/True_Delay/Compare To Constant1'
 * '<S171>' : 'SCR_model/SPDCtl/Hill_Descent_Control/HDC_Lower_Controller'
 * '<S172>' : 'SCR_model/SPDCtl/Hill_Descent_Control/HDC_Upper_Controller'
 * '<S173>' : 'SCR_model/SPDCtl/Hill_Descent_Control/Subsystem'
 * '<S174>' : 'SCR_model/SPDCtl/Hill_Descent_Control/True_Delay'
 * '<S175>' : 'SCR_model/SPDCtl/Hill_Descent_Control/HDC_Lower_Controller/CruiseNonRun'
 * '<S176>' : 'SCR_model/SPDCtl/Hill_Descent_Control/HDC_Lower_Controller/HDCRun'
 * '<S177>' : 'SCR_model/SPDCtl/Hill_Descent_Control/HDC_Lower_Controller/HDCRun/BaseTorque'
 * '<S178>' : 'SCR_model/SPDCtl/Hill_Descent_Control/HDC_Lower_Controller/HDCRun/HDC_SpdCon_TorqueController'
 * '<S179>' : 'SCR_model/SPDCtl/Hill_Descent_Control/HDC_Lower_Controller/HDCRun/PID_Configure'
 * '<S180>' : 'SCR_model/SPDCtl/Hill_Descent_Control/HDC_Lower_Controller/HDCRun/RollingCoef'
 * '<S181>' : 'SCR_model/SPDCtl/Hill_Descent_Control/HDC_Lower_Controller/HDCRun/HDC_SpdCon_TorqueController/FirstOrderFilter'
 * '<S182>' : 'SCR_model/SPDCtl/Hill_Descent_Control/HDC_Lower_Controller/HDCRun/HDC_SpdCon_TorqueController/HDC_PIDController'
 * '<S183>' : 'SCR_model/SPDCtl/Hill_Descent_Control/HDC_Lower_Controller/HDCRun/HDC_SpdCon_TorqueController/TorqueGradientLimit'
 * '<S184>' : 'SCR_model/SPDCtl/Hill_Descent_Control/HDC_Lower_Controller/HDCRun/HDC_SpdCon_TorqueController/VehicleLongitudinalDynamic'
 * '<S185>' : 'SCR_model/SPDCtl/Hill_Descent_Control/HDC_Lower_Controller/HDCRun/HDC_SpdCon_TorqueController/HDC_PIDController/DGain'
 * '<S186>' : 'SCR_model/SPDCtl/Hill_Descent_Control/HDC_Lower_Controller/HDCRun/HDC_SpdCon_TorqueController/HDC_PIDController/IGain'
 * '<S187>' : 'SCR_model/SPDCtl/Hill_Descent_Control/HDC_Lower_Controller/HDCRun/HDC_SpdCon_TorqueController/HDC_PIDController/IntegralClamping_AntiWindup'
 * '<S188>' : 'SCR_model/SPDCtl/Hill_Descent_Control/HDC_Lower_Controller/HDCRun/HDC_SpdCon_TorqueController/HDC_PIDController/Integrator'
 * '<S189>' : 'SCR_model/SPDCtl/Hill_Descent_Control/HDC_Lower_Controller/HDCRun/HDC_SpdCon_TorqueController/HDC_PIDController/PGain'
 * '<S190>' : 'SCR_model/SPDCtl/Hill_Descent_Control/HDC_Lower_Controller/HDCRun/HDC_SpdCon_TorqueController/HDC_PIDController/PID_Sum'
 * '<S191>' : 'SCR_model/SPDCtl/Hill_Descent_Control/HDC_Lower_Controller/HDCRun/HDC_SpdCon_TorqueController/HDC_PIDController/Integrator/Subsystem2'
 * '<S192>' : 'SCR_model/SPDCtl/Hill_Descent_Control/HDC_Lower_Controller/HDCRun/HDC_SpdCon_TorqueController/HDC_PIDController/PID_Sum/Subsystem1'
 * '<S193>' : 'SCR_model/SPDCtl/Hill_Descent_Control/HDC_Lower_Controller/HDCRun/HDC_SpdCon_TorqueController/TorqueGradientLimit/Saturation Dynamic'
 * '<S194>' : 'SCR_model/SPDCtl/Hill_Descent_Control/HDC_Lower_Controller/HDCRun/HDC_SpdCon_TorqueController/TorqueGradientLimit/Saturation Dynamic1'
 * '<S195>' : 'SCR_model/SPDCtl/Hill_Descent_Control/HDC_Lower_Controller/HDCRun/HDC_SpdCon_TorqueController/VehicleLongitudinalDynamic/Saturation Dynamic'
 * '<S196>' : 'SCR_model/SPDCtl/Hill_Descent_Control/HDC_Lower_Controller/HDCRun/PID_Configure/Integrator_Reset'
 * '<S197>' : 'SCR_model/SPDCtl/Hill_Descent_Control/HDC_Lower_Controller/HDCRun/PID_Configure/PID_IntegralHold_SpdDelta'
 * '<S198>' : 'SCR_model/SPDCtl/Hill_Descent_Control/HDC_Lower_Controller/HDCRun/PID_Configure/PID_Spd_Delta'
 * '<S199>' : 'SCR_model/SPDCtl/Hill_Descent_Control/HDC_Lower_Controller/HDCRun/PID_Configure/pid_ki'
 * '<S200>' : 'SCR_model/SPDCtl/Hill_Descent_Control/HDC_Lower_Controller/HDCRun/PID_Configure/pid_kp'
 * '<S201>' : 'SCR_model/SPDCtl/Hill_Descent_Control/HDC_Lower_Controller/HDCRun/PID_Configure/PID_IntegralHold_SpdDelta/ON_DelayTime_Judge'
 * '<S202>' : 'SCR_model/SPDCtl/Hill_Descent_Control/HDC_Lower_Controller/HDCRun/PID_Configure/PID_IntegralHold_SpdDelta/ON_DelayTime_Judge1'
 * '<S203>' : 'SCR_model/SPDCtl/Hill_Descent_Control/HDC_Lower_Controller/HDCRun/PID_Configure/PID_IntegralHold_SpdDelta/SetReset'
 * '<S204>' : 'SCR_model/SPDCtl/Hill_Descent_Control/HDC_Lower_Controller/HDCRun/PID_Configure/PID_Spd_Delta/Saturation Dynamic'
 * '<S205>' : 'SCR_model/SPDCtl/Hill_Descent_Control/HDC_Upper_Controller/Bilateral_Delay'
 * '<S206>' : 'SCR_model/SPDCtl/Hill_Descent_Control/HDC_Upper_Controller/Bilateral_Delay1'
 * '<S207>' : 'SCR_model/SPDCtl/Hill_Descent_Control/HDC_Upper_Controller/Compare To Constant1'
 * '<S208>' : 'SCR_model/SPDCtl/Hill_Descent_Control/HDC_Upper_Controller/Compare To Constant2'
 * '<S209>' : 'SCR_model/SPDCtl/Hill_Descent_Control/HDC_Upper_Controller/Compare To Constant3'
 * '<S210>' : 'SCR_model/SPDCtl/Hill_Descent_Control/HDC_Upper_Controller/Compare To Constant4'
 * '<S211>' : 'SCR_model/SPDCtl/Hill_Descent_Control/HDC_Upper_Controller/OverRide'
 * '<S212>' : 'SCR_model/SPDCtl/Hill_Descent_Control/HDC_Upper_Controller/Subsystem'
 * '<S213>' : 'SCR_model/SPDCtl/Hill_Descent_Control/HDC_Upper_Controller/Subsystem1'
 * '<S214>' : 'SCR_model/SPDCtl/Hill_Descent_Control/HDC_Upper_Controller/Subsystem10'
 * '<S215>' : 'SCR_model/SPDCtl/Hill_Descent_Control/HDC_Upper_Controller/Subsystem2'
 * '<S216>' : 'SCR_model/SPDCtl/Hill_Descent_Control/HDC_Upper_Controller/Subsystem3'
 * '<S217>' : 'SCR_model/SPDCtl/Hill_Descent_Control/HDC_Upper_Controller/Subsystem4'
 * '<S218>' : 'SCR_model/SPDCtl/Hill_Descent_Control/HDC_Upper_Controller/Subsystem5'
 * '<S219>' : 'SCR_model/SPDCtl/Hill_Descent_Control/HDC_Upper_Controller/Subsystem6'
 * '<S220>' : 'SCR_model/SPDCtl/Hill_Descent_Control/HDC_Upper_Controller/Subsystem8'
 * '<S221>' : 'SCR_model/SPDCtl/Hill_Descent_Control/HDC_Upper_Controller/Subsystem9'
 * '<S222>' : 'SCR_model/SPDCtl/Hill_Descent_Control/HDC_Upper_Controller/dataLatch'
 * '<S223>' : 'SCR_model/SPDCtl/Hill_Descent_Control/HDC_Upper_Controller/Bilateral_Delay/Compare To Constant1'
 * '<S224>' : 'SCR_model/SPDCtl/Hill_Descent_Control/HDC_Upper_Controller/Bilateral_Delay/Compare To Constant2'
 * '<S225>' : 'SCR_model/SPDCtl/Hill_Descent_Control/HDC_Upper_Controller/Bilateral_Delay1/Compare To Constant1'
 * '<S226>' : 'SCR_model/SPDCtl/Hill_Descent_Control/HDC_Upper_Controller/Bilateral_Delay1/Compare To Constant2'
 * '<S227>' : 'SCR_model/SPDCtl/Hill_Descent_Control/HDC_Upper_Controller/Subsystem/Compare To Constant'
 * '<S228>' : 'SCR_model/SPDCtl/Hill_Descent_Control/HDC_Upper_Controller/Subsystem/Compare To Constant1'
 * '<S229>' : 'SCR_model/SPDCtl/Hill_Descent_Control/HDC_Upper_Controller/Subsystem/Compare To Constant2'
 * '<S230>' : 'SCR_model/SPDCtl/Hill_Descent_Control/HDC_Upper_Controller/Subsystem/Compare To Constant3'
 * '<S231>' : 'SCR_model/SPDCtl/Hill_Descent_Control/HDC_Upper_Controller/Subsystem/Compare To Constant4'
 * '<S232>' : 'SCR_model/SPDCtl/Hill_Descent_Control/HDC_Upper_Controller/Subsystem/Compare To Constant5'
 * '<S233>' : 'SCR_model/SPDCtl/Hill_Descent_Control/HDC_Upper_Controller/Subsystem/Compare To Constant6'
 * '<S234>' : 'SCR_model/SPDCtl/Hill_Descent_Control/HDC_Upper_Controller/Subsystem/Compare To Constant7'
 * '<S235>' : 'SCR_model/SPDCtl/Hill_Descent_Control/HDC_Upper_Controller/Subsystem/True_Delay'
 * '<S236>' : 'SCR_model/SPDCtl/Hill_Descent_Control/HDC_Upper_Controller/Subsystem/True_Delay1'
 * '<S237>' : 'SCR_model/SPDCtl/Hill_Descent_Control/HDC_Upper_Controller/Subsystem/True_Delay/Compare To Constant1'
 * '<S238>' : 'SCR_model/SPDCtl/Hill_Descent_Control/HDC_Upper_Controller/Subsystem/True_Delay1/Compare To Constant1'
 * '<S239>' : 'SCR_model/SPDCtl/Hill_Descent_Control/HDC_Upper_Controller/Subsystem1/Compare To Constant1'
 * '<S240>' : 'SCR_model/SPDCtl/Hill_Descent_Control/HDC_Upper_Controller/Subsystem1/Compare To Constant2'
 * '<S241>' : 'SCR_model/SPDCtl/Hill_Descent_Control/HDC_Upper_Controller/Subsystem1/Compare To Constant3'
 * '<S242>' : 'SCR_model/SPDCtl/Hill_Descent_Control/HDC_Upper_Controller/Subsystem1/Differential'
 * '<S243>' : 'SCR_model/SPDCtl/Hill_Descent_Control/HDC_Upper_Controller/Subsystem1/IA_Filter_module'
 * '<S244>' : 'SCR_model/SPDCtl/Hill_Descent_Control/HDC_Upper_Controller/Subsystem1/Kalman_Filter'
 * '<S245>' : 'SCR_model/SPDCtl/Hill_Descent_Control/HDC_Upper_Controller/Subsystem1/Subsystem7'
 * '<S246>' : 'SCR_model/SPDCtl/Hill_Descent_Control/HDC_Upper_Controller/Subsystem1/True_Delay'
 * '<S247>' : 'SCR_model/SPDCtl/Hill_Descent_Control/HDC_Upper_Controller/Subsystem1/True_Delay1'
 * '<S248>' : 'SCR_model/SPDCtl/Hill_Descent_Control/HDC_Upper_Controller/Subsystem1/True_Delay2'
 * '<S249>' : 'SCR_model/SPDCtl/Hill_Descent_Control/HDC_Upper_Controller/Subsystem1/IA_Filter_module/Subsystem2'
 * '<S250>' : 'SCR_model/SPDCtl/Hill_Descent_Control/HDC_Upper_Controller/Subsystem1/IA_Filter_module/Subsystem2/Subsystem'
 * '<S251>' : 'SCR_model/SPDCtl/Hill_Descent_Control/HDC_Upper_Controller/Subsystem1/IA_Filter_module/Subsystem2/Subsystem1'
 * '<S252>' : 'SCR_model/SPDCtl/Hill_Descent_Control/HDC_Upper_Controller/Subsystem1/Subsystem7/Compare To Constant1'
 * '<S253>' : 'SCR_model/SPDCtl/Hill_Descent_Control/HDC_Upper_Controller/Subsystem1/Subsystem7/Compare To Constant3'
 * '<S254>' : 'SCR_model/SPDCtl/Hill_Descent_Control/HDC_Upper_Controller/Subsystem1/Subsystem7/Compare To Constant4'
 * '<S255>' : 'SCR_model/SPDCtl/Hill_Descent_Control/HDC_Upper_Controller/Subsystem1/Subsystem7/Compare To Constant5'
 * '<S256>' : 'SCR_model/SPDCtl/Hill_Descent_Control/HDC_Upper_Controller/Subsystem1/Subsystem7/True_Delay'
 * '<S257>' : 'SCR_model/SPDCtl/Hill_Descent_Control/HDC_Upper_Controller/Subsystem1/Subsystem7/True_Delay/Compare To Constant1'
 * '<S258>' : 'SCR_model/SPDCtl/Hill_Descent_Control/HDC_Upper_Controller/Subsystem1/True_Delay/Compare To Constant1'
 * '<S259>' : 'SCR_model/SPDCtl/Hill_Descent_Control/HDC_Upper_Controller/Subsystem1/True_Delay1/Compare To Constant1'
 * '<S260>' : 'SCR_model/SPDCtl/Hill_Descent_Control/HDC_Upper_Controller/Subsystem1/True_Delay2/Compare To Constant1'
 * '<S261>' : 'SCR_model/SPDCtl/Hill_Descent_Control/HDC_Upper_Controller/Subsystem2/Compare To Constant'
 * '<S262>' : 'SCR_model/SPDCtl/Hill_Descent_Control/HDC_Upper_Controller/Subsystem2/Compare To Constant1'
 * '<S263>' : 'SCR_model/SPDCtl/Hill_Descent_Control/HDC_Upper_Controller/Subsystem2/Compare To Constant2'
 * '<S264>' : 'SCR_model/SPDCtl/Hill_Descent_Control/HDC_Upper_Controller/Subsystem2/Compare To Constant3'
 * '<S265>' : 'SCR_model/SPDCtl/Hill_Descent_Control/HDC_Upper_Controller/Subsystem2/Compare To Constant4'
 * '<S266>' : 'SCR_model/SPDCtl/Hill_Descent_Control/HDC_Upper_Controller/Subsystem2/Compare To Constant5'
 * '<S267>' : 'SCR_model/SPDCtl/Hill_Descent_Control/HDC_Upper_Controller/Subsystem2/Compare To Constant6'
 * '<S268>' : 'SCR_model/SPDCtl/Hill_Descent_Control/HDC_Upper_Controller/Subsystem2/Compare To Constant7'
 * '<S269>' : 'SCR_model/SPDCtl/Hill_Descent_Control/HDC_Upper_Controller/Subsystem2/True_Delay'
 * '<S270>' : 'SCR_model/SPDCtl/Hill_Descent_Control/HDC_Upper_Controller/Subsystem2/True_Delay/Compare To Constant1'
 * '<S271>' : 'SCR_model/SPDCtl/Hill_Descent_Control/HDC_Upper_Controller/Subsystem3/Compare To Constant1'
 * '<S272>' : 'SCR_model/SPDCtl/Hill_Descent_Control/HDC_Upper_Controller/Subsystem3/Compare To Constant3'
 * '<S273>' : 'SCR_model/SPDCtl/Hill_Descent_Control/HDC_Upper_Controller/Subsystem3/Compare To Constant4'
 * '<S274>' : 'SCR_model/SPDCtl/Hill_Descent_Control/HDC_Upper_Controller/Subsystem3/Compare To Constant5'
 * '<S275>' : 'SCR_model/SPDCtl/Hill_Descent_Control/HDC_Upper_Controller/Subsystem5/Chart'
 * '<S276>' : 'SCR_model/SPDCtl/Hill_Descent_Control/HDC_Upper_Controller/Subsystem6/Compare To Constant5'
 * '<S277>' : 'SCR_model/SPDCtl/Hill_Descent_Control/HDC_Upper_Controller/Subsystem6/True_Delay1'
 * '<S278>' : 'SCR_model/SPDCtl/Hill_Descent_Control/HDC_Upper_Controller/Subsystem6/True_Delay1/Compare To Constant1'
 * '<S279>' : 'SCR_model/SPDCtl/Hill_Descent_Control/HDC_Upper_Controller/Subsystem8/Compare To Constant1'
 * '<S280>' : 'SCR_model/SPDCtl/Hill_Descent_Control/HDC_Upper_Controller/Subsystem8/Compare To Constant2'
 * '<S281>' : 'SCR_model/SPDCtl/Hill_Descent_Control/HDC_Upper_Controller/Subsystem8/Compare To Constant3'
 * '<S282>' : 'SCR_model/SPDCtl/Hill_Descent_Control/HDC_Upper_Controller/Subsystem8/Compare To Constant6'
 * '<S283>' : 'SCR_model/SPDCtl/Hill_Descent_Control/HDC_Upper_Controller/Subsystem8/True_Delay1'
 * '<S284>' : 'SCR_model/SPDCtl/Hill_Descent_Control/HDC_Upper_Controller/Subsystem8/True_Delay1/Compare To Constant1'
 * '<S285>' : 'SCR_model/SPDCtl/Hill_Descent_Control/HDC_Upper_Controller/Subsystem9/Bilateral_Delay2'
 * '<S286>' : 'SCR_model/SPDCtl/Hill_Descent_Control/HDC_Upper_Controller/Subsystem9/Compare To Constant'
 * '<S287>' : 'SCR_model/SPDCtl/Hill_Descent_Control/HDC_Upper_Controller/Subsystem9/Compare To Constant5'
 * '<S288>' : 'SCR_model/SPDCtl/Hill_Descent_Control/HDC_Upper_Controller/Subsystem9/Bilateral_Delay2/Compare To Constant1'
 * '<S289>' : 'SCR_model/SPDCtl/Hill_Descent_Control/HDC_Upper_Controller/Subsystem9/Bilateral_Delay2/Compare To Constant2'
 * '<S290>' : 'SCR_model/SPDCtl/Hill_Descent_Control/HDC_Upper_Controller/dataLatch/02 set and reset'
 * '<S291>' : 'SCR_model/SPDCtl/Hill_Descent_Control/True_Delay/Compare To Constant1'
 * '<S292>' : 'SCR_model/SPDCtl/NEDC_New_Control/Subsystem'
 * '<S293>' : 'SCR_model/SPDCtl/NEDC_New_Control/Subsystem/NEDC_Recoginiton'
 * '<S294>' : 'SCR_model/SPDCtl/NEDC_New_Control/Subsystem/NEDC_Work'
 * '<S295>' : 'SCR_model/SPDCtl/NEDC_New_Control/Subsystem/NEDC_Recoginiton/NEDC_Enable'
 * '<S296>' : 'SCR_model/SPDCtl/NEDC_New_Control/Subsystem/NEDC_Work/NEDC'
 * '<S297>' : 'SCR_model/SPDCtl/NEDC_New_Control/Subsystem/NEDC_Work/NonNEDC'
 * '<S298>' : 'SCR_model/SPDCtl/NEDC_New_Control/Subsystem/NEDC_Work/NEDC/Chart'
 * '<S299>' : 'SCR_model/SPDCtl/NEDC_New_Control/Subsystem/NEDC_Work/NEDC/NEDCBrake_Disable'
 * '<S300>' : 'SCR_model/SPDCtl/NEDC_New_Control/Subsystem/NEDC_Work/NEDC/NEDCBrake_Enable'
 * '<S301>' : 'SCR_model/SPDCtl/NEDC_New_Control/Subsystem/NEDC_Work/NEDC/ReleaseAccPedal'
 * '<S302>' : 'SCR_model/SPDCtl/NEDC_New_Control/Subsystem/NEDC_Work/NEDC/Saturation Dynamic'
 * '<S303>' : 'SCR_model/SPDCtl/NEDC_New_Control/Subsystem/NEDC_Work/NEDC/NEDCBrake_Enable/Calc_NEDCBrake_Tq'
 * '<S304>' : 'SCR_model/SPDCtl/NEDC_New_Control/Subsystem/NEDC_Work/NEDC/NEDCBrake_Enable/TargetSpd_Calc'
 * '<S305>' : 'SCR_model/SPDCtl/NEDC_New_Control/Subsystem/NEDC_Work/NEDC/NEDCBrake_Enable/Calc_NEDCBrake_Tq/Integral_Hold'
 * '<S306>' : 'SCR_model/SPDCtl/NEDC_New_Control/Subsystem/NEDC_Work/NEDC/NEDCBrake_Enable/Calc_NEDCBrake_Tq/Integral_Reset'
 * '<S307>' : 'SCR_model/SPDCtl/NEDC_New_Control/Subsystem/NEDC_Work/NEDC/NEDCBrake_Enable/Calc_NEDCBrake_Tq/KpKi'
 * '<S308>' : 'SCR_model/SPDCtl/NEDC_New_Control/Subsystem/NEDC_Work/NEDC/NEDCBrake_Enable/Calc_NEDCBrake_Tq/NEDC_SpdCon_TorqueController(PIDIC)'
 * '<S309>' : 'SCR_model/SPDCtl/NEDC_New_Control/Subsystem/NEDC_Work/NEDC/NEDCBrake_Enable/Calc_NEDCBrake_Tq/PID_Spd_Delta'
 * '<S310>' : 'SCR_model/SPDCtl/NEDC_New_Control/Subsystem/NEDC_Work/NEDC/NEDCBrake_Enable/Calc_NEDCBrake_Tq/Pid_IntegralMax'
 * '<S311>' : 'SCR_model/SPDCtl/NEDC_New_Control/Subsystem/NEDC_Work/NEDC/NEDCBrake_Enable/Calc_NEDCBrake_Tq/RollingCoef'
 * '<S312>' : 'SCR_model/SPDCtl/NEDC_New_Control/Subsystem/NEDC_Work/NEDC/NEDCBrake_Enable/Calc_NEDCBrake_Tq/Integral_Hold/PID_IntegralHold_SpdDelta'
 * '<S313>' : 'SCR_model/SPDCtl/NEDC_New_Control/Subsystem/NEDC_Work/NEDC/NEDCBrake_Enable/Calc_NEDCBrake_Tq/NEDC_SpdCon_TorqueController(PIDIC)/FirstOrderFilter'
 * '<S314>' : 'SCR_model/SPDCtl/NEDC_New_Control/Subsystem/NEDC_Work/NEDC/NEDCBrake_Enable/Calc_NEDCBrake_Tq/NEDC_SpdCon_TorqueController(PIDIC)/PIDICController'
 * '<S315>' : 'SCR_model/SPDCtl/NEDC_New_Control/Subsystem/NEDC_Work/NEDC/NEDCBrake_Enable/Calc_NEDCBrake_Tq/NEDC_SpdCon_TorqueController(PIDIC)/TorqueGradientLimit'
 * '<S316>' : 'SCR_model/SPDCtl/NEDC_New_Control/Subsystem/NEDC_Work/NEDC/NEDCBrake_Enable/Calc_NEDCBrake_Tq/NEDC_SpdCon_TorqueController(PIDIC)/VehicleLongitudinalDynamic'
 * '<S317>' : 'SCR_model/SPDCtl/NEDC_New_Control/Subsystem/NEDC_Work/NEDC/NEDCBrake_Enable/Calc_NEDCBrake_Tq/NEDC_SpdCon_TorqueController(PIDIC)/PIDICController/DGain'
 * '<S318>' : 'SCR_model/SPDCtl/NEDC_New_Control/Subsystem/NEDC_Work/NEDC/NEDCBrake_Enable/Calc_NEDCBrake_Tq/NEDC_SpdCon_TorqueController(PIDIC)/PIDICController/IGain'
 * '<S319>' : 'SCR_model/SPDCtl/NEDC_New_Control/Subsystem/NEDC_Work/NEDC/NEDCBrake_Enable/Calc_NEDCBrake_Tq/NEDC_SpdCon_TorqueController(PIDIC)/PIDICController/IntegralClamping_AntiWindup'
 * '<S320>' : 'SCR_model/SPDCtl/NEDC_New_Control/Subsystem/NEDC_Work/NEDC/NEDCBrake_Enable/Calc_NEDCBrake_Tq/NEDC_SpdCon_TorqueController(PIDIC)/PIDICController/Integrator'
 * '<S321>' : 'SCR_model/SPDCtl/NEDC_New_Control/Subsystem/NEDC_Work/NEDC/NEDCBrake_Enable/Calc_NEDCBrake_Tq/NEDC_SpdCon_TorqueController(PIDIC)/PIDICController/PGain'
 * '<S322>' : 'SCR_model/SPDCtl/NEDC_New_Control/Subsystem/NEDC_Work/NEDC/NEDCBrake_Enable/Calc_NEDCBrake_Tq/NEDC_SpdCon_TorqueController(PIDIC)/PIDICController/PID_Sum'
 * '<S323>' : 'SCR_model/SPDCtl/NEDC_New_Control/Subsystem/NEDC_Work/NEDC/NEDCBrake_Enable/Calc_NEDCBrake_Tq/NEDC_SpdCon_TorqueController(PIDIC)/PIDICController/Integrator/Subsystem2'
 * '<S324>' : 'SCR_model/SPDCtl/NEDC_New_Control/Subsystem/NEDC_Work/NEDC/NEDCBrake_Enable/Calc_NEDCBrake_Tq/NEDC_SpdCon_TorqueController(PIDIC)/PIDICController/PID_Sum/Subsystem1'
 * '<S325>' : 'SCR_model/SPDCtl/NEDC_New_Control/Subsystem/NEDC_Work/NEDC/NEDCBrake_Enable/Calc_NEDCBrake_Tq/NEDC_SpdCon_TorqueController(PIDIC)/TorqueGradientLimit/Saturation Dynamic'
 * '<S326>' : 'SCR_model/SPDCtl/NEDC_New_Control/Subsystem/NEDC_Work/NEDC/NEDCBrake_Enable/Calc_NEDCBrake_Tq/NEDC_SpdCon_TorqueController(PIDIC)/TorqueGradientLimit/Saturation Dynamic1'
 * '<S327>' : 'SCR_model/SPDCtl/NEDC_New_Control/Subsystem/NEDC_Work/NEDC/NEDCBrake_Enable/Calc_NEDCBrake_Tq/NEDC_SpdCon_TorqueController(PIDIC)/VehicleLongitudinalDynamic/Saturation Dynamic'
 * '<S328>' : 'SCR_model/SPDCtl/NEDC_New_Control/Subsystem/NEDC_Work/NEDC/NEDCBrake_Enable/Calc_NEDCBrake_Tq/PID_Spd_Delta/Saturation Dynamic'
 * '<S329>' : 'SCR_model/SPDCtl/NEDC_New_Control/Subsystem/NEDC_Work/NEDC/NEDCBrake_Enable/Calc_NEDCBrake_Tq/Pid_IntegralMax/NEDCSpd_VehSpd_Diff_Calc'
 * '<S330>' : 'SCR_model/SPDCtl/NEDC_New_Control/Subsystem/NEDC_Work/NEDC/NEDCBrake_Enable/TargetSpd_Calc/Subsystem'
 */

/*-
 * Requirements for '<Root>': SCR_model
 */
#endif                                 /* RTW_HEADER_SCR_model_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

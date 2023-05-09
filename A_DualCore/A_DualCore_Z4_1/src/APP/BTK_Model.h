/*
 * File: BTK_Model.h
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

/* Block signals (default storage) */
typedef struct
{
    uint8_T VBTK_PDU;                  /* '<S2>/BTK_StsteMachine' */
    boolean_T Merge;                   /* '<S3>/Merge' */
    boolean_T Merge1;                  /* '<S3>/Merge1' */
    boolean_T Merge2;                  /* '<S3>/Merge2' */
    boolean_T VBTK_SleepAllw;          /* '<S2>/BTK_StsteMachine' */
    boolean_T LogicalOperator1;        /* '<S30>/Logical Operator1' */
    boolean_T LogicalOperator2;        /* '<S30>/Logical Operator2' */
    boolean_T LogicalOperator3;        /* '<S30>/Logical Operator3' */
    boolean_T LogicalOperator7;        /* '<S29>/Logical Operator7' */
    rtB_BTKSignalConfirm_BTK_Mode_T BTKSignalConfirm3;/* '<S10>/BTKSignalConfirm3' */
    rtB_BTKSignalConfirm_BTK_Mode_T BTKSignalConfirm2;/* '<S10>/BTKSignalConfirm2' */
    rtB_BTKSignalConfirm_BTK_Mode_T BTKSignalConfirm1;/* '<S10>/BTKSignalConfirm1' */
    rtB_BTK_Delay_Confirm_BTK_Mod_T BTK_Delay_Confirm1;/* '<S3>/BTK_Delay_Confirm1' */
    rtB_BTK_Delay_Confirm_BTK_Mod_T BTK_Delay_Confirm;/* '<S3>/BTK_Delay_Confirm' */
}
BlockIO_BTK_Model_T;

/* Block states (default storage) for system '<Root>' */
typedef struct
{
    uint32_T Delay2_DSTATE;            /* '<S2>/Delay2' */
    uint32_T u32_StartTime;            /* '<S2>/BTK_StsteMachine' */
    uint32_T bool_OFFtoHVWOAllw;       /* '<S2>/BTK_StsteMachine' */
    uint32_T u32_SleepTime;            /* '<S2>/BTK_StsteMachine' */
    uint32_T u32_sleepDelay_start;     /* '<S2>/BTK_StsteMachine' */
    uint32_T AccUpStartTime_ms;        /* '<S9>/Data Store Memory' */
    uint32_T ONDnStartTime_ms;         /* '<S9>/Data Store Memory1' */
    boolean_T Delay_DSTATE;            /* '<S30>/Delay' */
    boolean_T Delay3_DSTATE_o;         /* '<S10>/Delay3' */
    boolean_T Delay4_DSTATE;           /* '<S15>/Delay4' */
    boolean_T Delay3_DSTATE_c;         /* '<S16>/Delay3' */
    uint8_T icLoad;                    /* '<S2>/Delay2' */
    uint8_T is_active_c1_BTK_Model;    /* '<S2>/BTK_StsteMachine' */
    uint8_T is_c1_BTK_Model;           /* '<S2>/BTK_StsteMachine' */
    uint8_T is_BTK_OFF;                /* '<S2>/BTK_StsteMachine' */
    uint8_T is_BTK_OFF_Down;           /* '<S2>/BTK_StsteMachine' */
    boolean_T bool_isBTKOFFDown_flg;   /* '<S2>/BTK_StsteMachine' */
    boolean_T bool_BTK_OFF_Down_flg;   /* '<S2>/BTK_StsteMachine' */
    boolean_T bool_LVtoOFF;            /* '<S2>/BTK_StsteMachine' */
    boolean_T bool_HVtoOFF;            /* '<S2>/BTK_StsteMachine' */
    boolean_T bool_LVtoHV;             /* '<S2>/BTK_StsteMachine' */
    boolean_T bool_HVWOtoSTART;        /* '<S2>/BTK_StsteMachine' */
    boolean_T bool_STARTtoOFF;         /* '<S2>/BTK_StsteMachine' */
    boolean_T bool_OFFtoStartAllw;     /* '<S2>/BTK_StsteMachine' */
    boolean_T bool_OFFtoLVAllw;        /* '<S2>/BTK_StsteMachine' */
    boolean_T VBTK_SleepAllw_pre;      /* '<S2>/BTK_StsteMachine' */
    boolean_T bool_flag;               /* '<S10>/Data Store Memory' */
    rtDW_BTKSignalConfirm_BTK_Mod_T BTKSignalConfirm3;/* '<S10>/BTKSignalConfirm3' */
    rtDW_BTKSignalConfirm_BTK_Mod_T BTKSignalConfirm2;/* '<S10>/BTKSignalConfirm2' */
    rtDW_BTKSignalConfirm_BTK_Mod_T BTKSignalConfirm1;/* '<S10>/BTKSignalConfirm1' */
    rtDW_BTK_Delay_Confirm_BTK_Mo_T BTK_Delay_Confirm1;/* '<S3>/BTK_Delay_Confirm1' */
    rtDW_BTK_Delay_Confirm_BTK_Mo_T BTK_Delay_Confirm;/* '<S3>/BTK_Delay_Confirm' */
}
D_Work_BTK_Model_T;

/* Zero-crossing (trigger) state */
typedef struct
{
    ZCSigState ON_Fall_Trig_ZCE;       /* '<S9>/ON_Fall' */
    ZCSigState ACC_Rise_Trig_ZCE;      /* '<S9>/ACC_Rise' */
}
PrevZCSigStates_BTK_Model_T;

/* Invariant block signals (default storage) */
typedef struct
{
    const boolean_T LogicalOperator7;  /* '<S30>/Logical Operator7' */
}
ConstBlockIO_BTK_Model_T;

/* Real-time Model Data Structure */
struct tag_RTM_BTK_Model_T
{
    const char_T *errorStatus;
};

/* Block signals (default storage) */
#pragma push
#pragma DATA_SEG __GPAGE_SEG GPAGED_RAM

extern BlockIO_BTK_Model_T BTK_Model_B;

#pragma pop

/* Block states (default storage) */
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
extern boolean_T SSB_Adhesion;         /* '<S10>/Logical Operator' */
extern boolean_T SSB_SyncCorrect;      /* '<S10>/Logical Operator1' */

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
 * Block '<S2>/Constant1' : Unused code path elimination
 * Block '<S1>/Constant1' : Unused code path elimination
 * Block '<S2>/Data Type Conversion3' : Eliminate redundant data type conversion
 * Block '<S2>/Data Type Conversion4' : Eliminate redundant data type conversion
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
 * '<S3>'   : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/BTK_A_SSB '
 * '<S4>'   : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/BTK_A_SSB_Monitoring'
 * '<S5>'   : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/BTK_Signal_Simulation'
 * '<S6>'   : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/BTK_StsteMachine'
 * '<S7>'   : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/BTK_A_SSB /BTK_Delay_Confirm'
 * '<S8>'   : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/BTK_A_SSB /BTK_Delay_Confirm1'
 * '<S9>'   : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/BTK_A_SSB /Mechanical'
 * '<S10>'  : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/BTK_A_SSB /SSB_Sts '
 * '<S11>'  : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/BTK_A_SSB /BTK_Delay_Confirm/AffirmCheck'
 * '<S12>'  : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/BTK_A_SSB /BTK_Delay_Confirm1/AffirmCheck'
 * '<S13>'  : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/BTK_A_SSB /Mechanical/ACC_Rise'
 * '<S14>'  : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/BTK_A_SSB /Mechanical/ON_Fall'
 * '<S15>'  : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/BTK_A_SSB /Mechanical/Subsystem'
 * '<S16>'  : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/BTK_A_SSB /Mechanical/Subsystem1'
 * '<S17>'  : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/BTK_A_SSB /SSB_Sts /BTKSignalConfirm1'
 * '<S18>'  : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/BTK_A_SSB /SSB_Sts /BTKSignalConfirm2'
 * '<S19>'  : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/BTK_A_SSB /SSB_Sts /BTKSignalConfirm3'
 * '<S20>'  : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/BTK_A_SSB /SSB_Sts /Compare To Constant'
 * '<S21>'  : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/BTK_A_SSB /SSB_Sts /Compare To Constant1'
 * '<S22>'  : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/BTK_A_SSB /SSB_Sts /Compare To Constant2'
 * '<S23>'  : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/BTK_A_SSB /SSB_Sts /Compare To Constant3'
 * '<S24>'  : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/BTK_A_SSB /SSB_Sts /Compare To Constant4'
 * '<S25>'  : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/BTK_A_SSB /SSB_Sts /Compare To Zero1'
 * '<S26>'  : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/BTK_A_SSB /SSB_Sts /Compare To Zero4'
 * '<S27>'  : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/BTK_A_SSB /SSB_Sts /Enabled Subsystem'
 * '<S28>'  : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/BTK_A_SSB /SSB_Sts /Enabled Subsystem1'
 * '<S29>'  : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/BTK_A_SSB_Monitoring/MEK_Trigger'
 * '<S30>'  : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/BTK_A_SSB_Monitoring/SSB_Trigger'
 * '<S31>'  : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/BTK_Signal_Simulation/Authtication'
 * '<S32>'  : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/BTK_Signal_Simulation/Brake'
 * '<S33>'  : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/BTK_Signal_Simulation/Config '
 * '<S34>'  : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/BTK_Signal_Simulation/DoorAndVehicle_Sts'
 * '<S35>'  : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/BTK_Signal_Simulation/ESCL'
 * '<S36>'  : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/BTK_Signal_Simulation/PowerMode_Req'
 * '<S37>'  : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/BTK_Signal_Simulation/Subsystem'
 * '<S38>'  : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/BTK_Signal_Simulation/SystemTime_simulation'
 * '<S39>'  : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/BTK_Signal_Simulation/TQM'
 * '<S40>'  : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/BTK_Signal_Simulation/DoorAndVehicle_Sts/Compare To Constant'
 * '<S41>'  : 'BTK_Model/BTK_Module/BTK_ACT_PEPS/BTK_Signal_Simulation/DoorAndVehicle_Sts/Compare To Constant1'
 */
#endif                                 /* RTW_HEADER_BTK_Model_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

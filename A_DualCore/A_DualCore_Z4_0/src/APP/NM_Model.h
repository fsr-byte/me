/*
 * File: NM_Model.h
 *
 * Code generated for Simulink model 'NM_Model'.
 *
 * Model version                  : 1.357
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Fri Mar 18 15:42:08 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Freescale->32-bit PowerPC
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 *    3. ROM efficiency
 *    4. MISRA C:2012 guidelines
 * Validation result: Not run
 */

#ifndef RTW_HEADER_NM_Model_h_
#define RTW_HEADER_NM_Model_h_
#include <string.h>
#ifndef NM_Model_COMMON_INCLUDES_
# define NM_Model_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* NM_Model_COMMON_INCLUDES_ */

#include "NM_Model_types.h"

/* Includes for objects with custom storage classes. */
#include "NM_Cal_Data.h"

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
  uint32_T Add;                        /* '<S13>/Add' */
  uint8_T DataTypeConversion1;         /* '<S7>/Data Type Conversion1' */
  uint8_T State;                       /* '<S1>/MainState' */
  uint8_T Skip_flg;                    /* '<S1>/MainState' */
  uint8_T LogicalSuccessor;            /* '<S1>/MainState' */
  uint8_T bool_SleepTry;               /* '<S1>/MainState' */
  uint8_T NM_EnableAppComm;            /* '<S1>/MainState' */
  uint8_T NM_InternalDelayActive;      /* '<S1>/MainState' */
} B_NM_Model_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  uint32_T Delay_DSTATE;               /* '<S3>/Delay' */
  uint32_T Delay_DSTATE_j;             /* '<S4>/Delay' */
  uint32_T Delay_DSTATE_h;             /* '<S11>/Delay' */
  uint32_T NM_InternalSleepActiveStartTime;/* '<S8>/Data Store Memory1' */
  uint32_T t_Error;                    /* '<S1>/MainState' */
  uint32_T t_Type;                     /* '<S1>/MainState' */
  uint32_T t_wbs;                      /* '<S1>/MainState' */
  uint32_T t_Max;                      /* '<S1>/MainState' */
  uint32_T t_Active;                   /* '<S1>/MainState' */
  uint32_T t_limphome;                 /* '<S1>/MainState' */
  uint32_T t_KeyOnAgain;               /* '<S1>/MainState' */
  uint16_T SuccessorCheck_Address;     /* '<S1>/MainState' */
  boolean_T Delay_DSTATE_b;            /* '<S8>/Delay' */
  uint8_T is_active_c1_NM_Model;       /* '<S1>/MainState' */
  uint8_T is_c1_NM_Model;              /* '<S1>/MainState' */
  uint8_T is_OnWork;                   /* '<S1>/MainState' */
  uint8_T is_Reset;                    /* '<S1>/MainState' */
  uint8_T is_Normal;                   /* '<S1>/MainState' */
  uint8_T is_Limphome;                 /* '<S1>/MainState' */
  uint8_T MODE;                        /* '<S1>/MainState' */
  uint8_T RxCnt;                       /* '<S1>/MainState' */
  uint8_T TxCnt;                       /* '<S1>/MainState' */
  uint8_T t_MaxStepEnable;             /* '<S1>/MainState' */
  uint8_T t_TypeStepEnable;            /* '<S1>/MainState' */
  uint8_T SleepIndTargetAdr;           /* '<S1>/MainState' */
  uint8_T SuccessorCheck;              /* '<S1>/MainState' */
  boolean_T TxSuccess_flg;             /* '<S1>/MainState' */
  boolean_T EnabledSubsystem1_MODE;    /* '<S8>/Enabled Subsystem1' */
} DW_NM_Model_T;

/* Real-time Model Data Structure */
struct tag_RTM_NM_Model_T {
  const char_T *errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
  } Timing;
};

/* Block signals (auto storage) */
#pragma push
#pragma DATA_SEG __GPAGE_SEG GPAGED_RAM

extern B_NM_Model_T NM_Model_B;

#pragma pop

/* Block states (auto storage) */

#pragma push
#pragma DATA_SEG __GPAGE_SEG GPAGED_RAM

extern DW_NM_Model_T NM_Model_DW;

#pragma pop

/* External data declarations for dependent source files */
#pragma push
#pragma DATA_SEG __GPAGE_SEG GPAGED_RAM

extern const NM NM_Model_rtZNM;        /* NM ground */

#pragma pop

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern NM NM_output;                   /* '<Root>/Bus Creator' */

/* Model entry point functions */
extern void NM_Model_initialize(void);
extern void NM_Model_step(void);
extern void NM_Model_terminate(void);

/* Real-time Model object */
#pragma push
#pragma DATA_SEG __GPAGE_SEG GPAGED_RAM

extern RT_MODEL_NM_Model_T *const NM_Model_M;

#pragma pop

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S10>/Logical Operator1' : Unused code path elimination
 * Block '<S10>/Logical Operator2' : Unused code path elimination
 * Block '<S10>/Logical Operator3' : Unused code path elimination
 * Block '<S1>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S1>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S1>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S1>/Data Type Conversion3' : Eliminate redundant data type conversion
 * Block '<S1>/Data Type Conversion6' : Eliminate redundant data type conversion
 * Block '<S1>/Data Type Conversion7' : Eliminate redundant data type conversion
 * Block '<S6>/Manual Switch' : Eliminated due to constant selection input
 * Block '<S6>/Constant4' : Unused code path elimination
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
 * '<Root>' : 'NM_Model'
 * '<S1>'   : 'NM_Model/NM_Module'
 * '<S2>'   : 'NM_Model/NM_Module/MainState'
 * '<S3>'   : 'NM_Model/NM_Module/Subsystem'
 * '<S4>'   : 'NM_Model/NM_Module/Subsystem1'
 * '<S5>'   : 'NM_Model/NM_Module/Subsystem2'
 * '<S6>'   : 'NM_Model/NM_Module/Subsystem3'
 * '<S7>'   : 'NM_Model/NM_Module/Subsystem4'
 * '<S8>'   : 'NM_Model/NM_Module/TaskTick_ms'
 * '<S9>'   : 'NM_Model/NM_Module/TaskTick_ms1'
 * '<S10>'  : 'NM_Model/NM_Module/WakeUp'
 * '<S11>'  : 'NM_Model/NM_Module/Subsystem3/Subsystem2'
 * '<S12>'  : 'NM_Model/NM_Module/TaskTick_ms/Enabled Subsystem'
 * '<S13>'  : 'NM_Model/NM_Module/TaskTick_ms/Enabled Subsystem1'
 * '<S14>'  : 'NM_Model/NM_Module/TaskTick_ms1/Enabled Subsystem1'
 */
#endif                                 /* RTW_HEADER_NM_Model_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

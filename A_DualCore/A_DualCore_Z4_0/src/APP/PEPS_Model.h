/*
 * File: PEPS_Model.h
 *
 * Code generated for Simulink model 'PEPS_Model'.
 *
 * Model version                  : 1.84
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Fri Mar 18 15:43:41 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Freescale->32-bit PowerPC
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. ROM efficiency
 *    3. RAM efficiency
 *    4. MISRA C:2012 guidelines
 * Validation result: Not run
 */

#ifndef RTW_HEADER_PEPS_Model_h_
#define RTW_HEADER_PEPS_Model_h_
#include <stddef.h>
#include <string.h>
#ifndef PEPS_Model_COMMON_INCLUDES_
# define PEPS_Model_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* PEPS_Model_COMMON_INCLUDES_ */

#include "PEPS_Model_types.h"

/* Includes for objects with custom storage classes. */
#include "PEPS_Cal_Data.h"

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
    PEPS_EnKey EnKey;                  /* '<S12>/Bus Creator' */
    uint32_T EnRam[2];                 /* '<S5>/Chart1' */
    uint32_T EnRam_e[2];               /* '<S5>/Chart' */
    uint8_T DataStoreRead[16];         /* '<Root>/Data Store Read' */
    uint8_T DataStoreRead1[4];         /* '<Root>/Data Store Read1' */
    uint8_T DataStoreRead2[8];         /* '<Root>/Data Store Read2' */
}
B_PEPS_Model_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct
{
    real_T Delay_DSTATE;               /* '<S6>/Delay' */
    PEPS_EnKey Delay_DSTATE_l;         /* '<S4>/Delay' */
    uint32_T Delay1_DSTATE;            /* '<S6>/Delay1' */
    uint32_T Delay1_DSTATE_i;          /* '<S4>/Delay1' */
    uint32_T EnSum;                    /* '<S5>/Chart1' */
    uint32_T EnSum_k;                  /* '<S5>/Chart' */
    uint8_T Delay2_DSTATE;             /* '<S6>/Delay2' */
    uint8_T Delay3_DSTATE;             /* '<S4>/Delay3' */
    boolean_T Delay2_DSTATE_f;         /* '<S4>/Delay2' */
    uint8_T is_active_c3_PEPS_Model;   /* '<S2>/State' */
    uint8_T is_c3_PEPS_Model;          /* '<S2>/State' */
    uint8_T is_WaitPEPSResponse;       /* '<S2>/State' */
    uint8_T is_PEPSResult;             /* '<S2>/State' */
    uint8_T is_Auth;                   /* '<S2>/State' */
}
DW_PEPS_Model_T;

/* Real-time Model Data Structure */
struct tag_RTM_PEPS_Model_T
{
    const char_T *errorStatus;
};

/* Block signals (auto storage) */
#pragma push
#pragma DATA_SEG __GPAGE_SEG GPAGED_RAM

extern B_PEPS_Model_T PEPS_Model_B;

#pragma pop

/* Block states (auto storage) */

#pragma push
#pragma DATA_SEG __GPAGE_SEG GPAGED_RAM

extern DW_PEPS_Model_T PEPS_Model_DW;

#pragma pop

/* External data declarations for dependent source files */
#pragma push
#pragma DATA_SEG __GPAGE_SEG GPAGED_RAM

extern const PEPS_PEPS PEPS_Model_rtZPEPS_PEPS;/* PEPS_PEPS ground */

#pragma pop

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern PEPS_PEPS PEPS_output;          /* '<Root>/Bus Creator1' */
extern uint32_T vsk1;                  /* '<S15>/Switch1' */
extern uint32_T vsk2;                  /* '<S15>/Switch2' */
extern uint32_T vsk3;                  /* '<S15>/Switch3' */
extern uint32_T vsk4;                  /* '<S15>/Switch4' */
extern uint16_T VPEPS_WaitTime_ms;     /* '<S2>/State' */
extern uint16_T VPEPS_KL15OffTime_ms;  /* '<S2>/State' */
extern uint8_T VPEPS_EncryptedResponseByte5;/* '<S8>/Data Type Conversion' */
extern uint8_T VPEPS_EnKey2;           /* '<S8>/Data Type Conversion1' */
extern uint8_T VPEPS_StatusNew_enum;   /* '<S4>/Switch1' */
extern uint8_T VPEPS_SendChallengeCodeType_enum;/* '<S2>/State' */
extern uint8_T VPEPS_AuthTime_Cnt;     /* '<S2>/State' */
extern uint8_T VPEPS_SendChallenge_Cnt;/* '<S2>/State' */
extern uint8_T VPEPS_Result_enum;      /* '<S2>/State' */
extern boolean_T VPEPS_KeyMatch2_flg;  /* '<S8>/Relational Operator5' */
extern boolean_T VPEPS_KeyMatch3_flg;  /* '<S8>/Relational Operator1' */
extern boolean_T VPEPS_KeyMatch4_flg;  /* '<S8>/Relational Operator2' */
extern boolean_T VPEPS_KeyMatch5_flg;  /* '<S8>/Relational Operator3' */
extern boolean_T VPEPS_KeyMatch6_flg;  /* '<S8>/Relational Operator4' */
extern boolean_T VPEPS_KeyMatch7_flg;  /* '<S8>/Relational Operator6' */
extern boolean_T VPEPS_K15Off_flg;     /* '<S2>/State' */
extern boolean_T VPEPS_OnGoing_flg;    /* '<S2>/State' */
extern boolean_T VPEPS_ResetPEPSStatus_flg;/* '<S2>/State' */

/* Model entry point functions */
extern void PEPS_Model_initialize(void);
extern void PEPS_Model_step(void);
extern void PEPS_Model_terminate(void);

/* Real-time Model object */
#pragma push
#pragma DATA_SEG __GPAGE_SEG GPAGED_RAM

extern RT_MODEL_PEPS_Model_T *const PEPS_Model_M;

#pragma pop

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
 * '<Root>' : 'PEPS_Model'
 * '<S1>'   : 'PEPS_Model/PEPS'
 * '<S2>'   : 'PEPS_Model/PEPS/PEPS'
 * '<S3>'   : 'PEPS_Model/PEPS/PEPS/State'
 * '<S4>'   : 'PEPS_Model/PEPS/PEPS/Subsystem'
 * '<S5>'   : 'PEPS_Model/PEPS/PEPS/Subsystem1'
 * '<S6>'   : 'PEPS_Model/PEPS/PEPS/Subsystem2'
 * '<S7>'   : 'PEPS_Model/PEPS/PEPS/Subsystem/PEPSStatusConvert'
 * '<S8>'   : 'PEPS_Model/PEPS/PEPS/Subsystem/PEPSStatusConvert/EnKeyMatch'
 * '<S9>'   : 'PEPS_Model/PEPS/PEPS/Subsystem1/Chart'
 * '<S10>'  : 'PEPS_Model/PEPS/PEPS/Subsystem1/Chart1'
 * '<S11>'  : 'PEPS_Model/PEPS/PEPS/Subsystem1/DataExtraction '
 * '<S12>'  : 'PEPS_Model/PEPS/PEPS/Subsystem1/DataExtraction1'
 * '<S13>'  : 'PEPS_Model/PEPS/PEPS/Subsystem1/DataReconstruction'
 * '<S14>'  : 'PEPS_Model/PEPS/PEPS/Subsystem1/DataReconstruction/Data_ChallengeCode'
 * '<S15>'  : 'PEPS_Model/PEPS/PEPS/Subsystem1/DataReconstruction/Data_ENVSK'
 * '<S16>'  : 'PEPS_Model/PEPS/PEPS/Subsystem1/DataReconstruction/Data_FixedCode'
 * '<S17>'  : 'PEPS_Model/PEPS/PEPS/Subsystem1/DataReconstruction/Data_ChallengeCode/Subsystem'
 * '<S18>'  : 'PEPS_Model/PEPS/PEPS/Subsystem1/DataReconstruction/Data_ChallengeCode/Subsystem1'
 * '<S19>'  : 'PEPS_Model/PEPS/PEPS/Subsystem1/DataReconstruction/Data_ChallengeCode/Subsystem10'
 * '<S20>'  : 'PEPS_Model/PEPS/PEPS/Subsystem1/DataReconstruction/Data_ChallengeCode/Subsystem2'
 * '<S21>'  : 'PEPS_Model/PEPS/PEPS/Subsystem1/DataReconstruction/Data_ChallengeCode/Subsystem3'
 * '<S22>'  : 'PEPS_Model/PEPS/PEPS/Subsystem1/DataReconstruction/Data_ChallengeCode/Subsystem4'
 * '<S23>'  : 'PEPS_Model/PEPS/PEPS/Subsystem1/DataReconstruction/Data_ChallengeCode/Subsystem5'
 * '<S24>'  : 'PEPS_Model/PEPS/PEPS/Subsystem1/DataReconstruction/Data_ChallengeCode/Subsystem6'
 * '<S25>'  : 'PEPS_Model/PEPS/PEPS/Subsystem1/DataReconstruction/Data_ChallengeCode/Subsystem7'
 * '<S26>'  : 'PEPS_Model/PEPS/PEPS/Subsystem1/DataReconstruction/Data_ChallengeCode/Subsystem8'
 * '<S27>'  : 'PEPS_Model/PEPS/PEPS/Subsystem1/DataReconstruction/Data_ChallengeCode/Subsystem9'
 * '<S28>'  : 'PEPS_Model/PEPS/PEPS/Subsystem1/DataReconstruction/Data_ChallengeCode/Subsystem8/Subsystem'
 * '<S29>'  : 'PEPS_Model/PEPS/PEPS/Subsystem1/DataReconstruction/Data_ChallengeCode/Subsystem8/Subsystem1'
 * '<S30>'  : 'PEPS_Model/PEPS/PEPS/Subsystem1/DataReconstruction/Data_ENVSK/Subsystem10'
 * '<S31>'  : 'PEPS_Model/PEPS/PEPS/Subsystem1/DataReconstruction/Data_ENVSK/Subsystem11'
 * '<S32>'  : 'PEPS_Model/PEPS/PEPS/Subsystem1/DataReconstruction/Data_ENVSK/Subsystem12'
 * '<S33>'  : 'PEPS_Model/PEPS/PEPS/Subsystem1/DataReconstruction/Data_ENVSK/Subsystem8'
 * '<S34>'  : 'PEPS_Model/PEPS/PEPS/Subsystem1/DataReconstruction/Data_ENVSK/Subsystem9'
 * '<S35>'  : 'PEPS_Model/PEPS/PEPS/Subsystem1/DataReconstruction/Data_ENVSK/Subsystem8/Subsystem'
 * '<S36>'  : 'PEPS_Model/PEPS/PEPS/Subsystem1/DataReconstruction/Data_ENVSK/Subsystem8/Subsystem1'
 * '<S37>'  : 'PEPS_Model/PEPS/PEPS/Subsystem1/DataReconstruction/Data_FixedCode/Subsystem8'
 * '<S38>'  : 'PEPS_Model/PEPS/PEPS/Subsystem1/DataReconstruction/Data_FixedCode/Subsystem9'
 */
#endif                                 /* RTW_HEADER_PEPS_Model_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

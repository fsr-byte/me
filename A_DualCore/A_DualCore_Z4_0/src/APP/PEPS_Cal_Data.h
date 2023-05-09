/*
 * File: PEPS_Cal_Data.h
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

#ifndef RTW_HEADER_PEPS_Cal_Data_h_
#define RTW_HEADER_PEPS_Cal_Data_h_
#include "rtwtypes.h"
#include "PEPS_Model_types.h"

/* Exported data declaration */
#include "derivative.h"

/* Declaration for custom storage class: CAL_4_PEPS */
extern CAL_PEPS uint8_T KPEPS_AuthTimeMax_Cnt;
extern CAL_PEPS uint32_T KPEPS_ChallengeCodeHighTest_uint32;
extern CAL_PEPS uint32_T KPEPS_ChallengeCodeLowTest_uint32;
extern CAL_PEPS boolean_T KPEPS_ChallengeCodeRandom_flg;
extern CAL_PEPS uint32_T KPEPS_ENVSK0_uint32;
extern CAL_PEPS uint32_T KPEPS_ENVSK1_uint32;
extern CAL_PEPS uint32_T KPEPS_ENVSK2_uint32;
extern CAL_PEPS uint32_T KPEPS_ENVSK3_uint32;
extern CAL_PEPS boolean_T KPEPS_ENVSKFromEEPROM_flg;
extern CAL_PEPS boolean_T KPEPS_FixedCodeFromEEPROM_flg;
extern CAL_PEPS uint32_T KPEPS_FixedCode_uint32;
extern CAL_PEPS uint16_T KPEPS_K15OffDelay_ms;
extern CAL_PEPS uint32_T KPEPS_RandomX_uint32;
extern CAL_PEPS uint32_T KPEPS_RandomY_uint32;
extern CAL_PEPS uint32_T KPEPS_RandomZ_uint32;
extern CAL_PEPS uint16_T KPEPS_ResponseTimeout_ms;
extern CAL_PEPS uint16_T KPEPS_StepTime_ms;
extern CAL_PEPS uint8_T KPEPS_VCUChallengeRetryMax_Cnt;
extern CAL_PEPS uint8_T PEPS_FAILED;
extern CAL_PEPS boolean_T PEPS_FALSE;
extern CAL_PEPS uint8_T PEPS_INIT;
extern CAL_PEPS uint8_T PEPS_LOCK;
extern CAL_PEPS uint8_T PEPS_ON;
extern CAL_PEPS uint8_T PEPS_RELEASE_FAILED;
extern CAL_PEPS boolean_T PEPS_RELEASE_INIT;
extern CAL_PEPS uint8_T PEPS_RELEASE_SUCCESS;
extern CAL_PEPS uint8_T PEPS_RSP_AUTHFILED;
extern CAL_PEPS uint8_T PEPS_RSP_LOCKED;
extern CAL_PEPS uint8_T PEPS_RSP_ONGOING;
extern CAL_PEPS uint8_T PEPS_RSP_PASS;
extern CAL_PEPS boolean_T PEPS_TRUE;
extern CAL_PEPS uint8_T PEPS_UNLOCK;
extern CAL_PEPS uint8_T PEPS_UNMATCH;

#endif                                 /* RTW_HEADER_PEPS_Cal_Data_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

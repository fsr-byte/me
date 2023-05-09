/*
 * File: PEPS_Cal_Data.c
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

#include "rtwtypes.h"
#include "PEPS_Model_types.h"

/* Exported data definition */
#include "derivative.h"

/* Definition for custom storage class: CAL_4_PEPS */
CAL_PEPS uint8_T KPEPS_AuthTimeMax_Cnt = 3U;
CAL_PEPS uint32_T KPEPS_ChallengeCodeHighTest_uint32 = 16909060U;
CAL_PEPS uint32_T KPEPS_ChallengeCodeLowTest_uint32 = 84281096U;
CAL_PEPS boolean_T KPEPS_ChallengeCodeRandom_flg = 1;
CAL_PEPS uint32_T KPEPS_ENVSK0_uint32 = 2863311530U;
CAL_PEPS uint32_T KPEPS_ENVSK1_uint32 = 2863311530U;
CAL_PEPS uint32_T KPEPS_ENVSK2_uint32 = 2863311530U;
CAL_PEPS uint32_T KPEPS_ENVSK3_uint32 = 2863311530U;
CAL_PEPS boolean_T KPEPS_ENVSKFromEEPROM_flg = 1;
CAL_PEPS boolean_T KPEPS_FixedCodeFromEEPROM_flg = 0;
CAL_PEPS uint32_T KPEPS_FixedCode_uint32 = 2928071356U;
CAL_PEPS uint16_T KPEPS_K15OffDelay_ms = 150U;
CAL_PEPS uint32_T KPEPS_RandomX_uint32 = 23U;
CAL_PEPS uint32_T KPEPS_RandomY_uint32 = 7U;
CAL_PEPS uint32_T KPEPS_RandomZ_uint32 = 251U;
CAL_PEPS uint16_T KPEPS_ResponseTimeout_ms = 100U;
CAL_PEPS uint16_T KPEPS_StepTime_ms = 20U;
CAL_PEPS uint8_T KPEPS_VCUChallengeRetryMax_Cnt = 6U;
CAL_PEPS uint8_T PEPS_FAILED = 5U;
CAL_PEPS boolean_T PEPS_FALSE = 0;
CAL_PEPS uint8_T PEPS_INIT = 0U;
CAL_PEPS uint8_T PEPS_LOCK = 4U;
CAL_PEPS uint8_T PEPS_ON = 3U;
CAL_PEPS uint8_T PEPS_RELEASE_FAILED = 1U;
CAL_PEPS boolean_T PEPS_RELEASE_INIT = 0;
CAL_PEPS uint8_T PEPS_RELEASE_SUCCESS = 2U;
CAL_PEPS uint8_T PEPS_RSP_AUTHFILED = 95U;
CAL_PEPS uint8_T PEPS_RSP_LOCKED = 240U;
CAL_PEPS uint8_T PEPS_RSP_ONGOING = 245U;
CAL_PEPS uint8_T PEPS_RSP_PASS = 0U;
CAL_PEPS boolean_T PEPS_TRUE = 1;
CAL_PEPS uint8_T PEPS_UNLOCK = 2U;
CAL_PEPS uint8_T PEPS_UNMATCH = 1U;

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

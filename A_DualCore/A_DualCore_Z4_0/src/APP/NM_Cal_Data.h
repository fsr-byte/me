/*
 * File: NM_Cal_Data.h
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

#ifndef RTW_HEADER_NM_Cal_Data_h_
#define RTW_HEADER_NM_Cal_Data_h_
#include "rtwtypes.h"
#include "NM_Model_types.h"

/* Exported data define */

/* Definition for custom storage class: Define */
#define NM_ADDRESS_MASK                255U
#define NM_MODE_ACK                    3U
#define NM_MODE_AWAKE                  1U
#define NM_MODE_SLEEP                  2U
#define NM_RX_CNT_STEP                 1U
#define NM_RX_LIMIT                    4U
#define NM_TX_CNT_STEP                 1U
#define NM_TX_LIMIT                    8U
#define NM_T_ERROR                     1000U
#define NM_T_KEYONAGAIN                200U
#define NM_T_MAX                       250U
#define NM_T_TYPE                      95U
#define NM_VCU_ADR                     6U

/* Exported data declaration */
#include "derivative.h"

/* Declaration for custom storage class: CAL_3_NM */
extern CAL_NM uint8_T KNM_DefaultOnTime;
extern CAL_NM uint16_T KPMM_VCUSleepWaitDelay;
extern CAL_NM uint16_T NM_T_WBS;

#endif                                 /* RTW_HEADER_NM_Cal_Data_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

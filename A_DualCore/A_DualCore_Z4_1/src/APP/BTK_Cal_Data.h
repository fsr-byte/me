/*
 * File: BTK_Cal_Data.h
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

#ifndef RTW_HEADER_BTK_Cal_Data_h_
#define RTW_HEADER_BTK_Cal_Data_h_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "BTK_Model_types.h"

/* Exported data define */

/* Definition for custom storage class: Define */
#define BTK_FALSE                      0
#define BTK_PDU_HV_ACTIVE_WO           3U                        /* HV Active without driver */
#define BTK_PDU_LV_W                   1U                        /* LV ready */
#define BTK_PDU_OFF_WO                 0U
#define BTK_PDU_START_DRIVE            2U
#define BTK_PMSC_MEK                   2U
#define BTK_PMSC_SSB                   1U
#define BTK_TRUE                       1

/* Exported data declaration */
#include "derivative.h"

/* Declaration for custom storage class: CAL_16_BTK */
extern CAL_BTK uint32_T KBTK_MEKSigSynTime_ms;/* ACC和ON信号同步时间（钥匙迅速通OFF到ON，ON到OFF过程中） */
extern CAL_BTK uint32_T KBTK_MaxSSBDiffTime_ms;/* 两路开关硬线信号不同步的最大时间 */
extern CAL_BTK uint32_T KBTK_MaxTimeInOnState_ms;/* 低压ON档允许持续时间30mins = 1800000ms */
extern CAL_BTK uint32_T KBTK_SSBAdhesionConfirmTime_ms;/* SSB开关黏连确认时间 */
extern CAL_BTK uint32_T KBTK_SSBConfirmTime_ms;/* SSB开关信号确认时间 */

#endif                                 /* RTW_HEADER_BTK_Cal_Data_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

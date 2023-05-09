/*
 * File: BTK_Cal_Data.c
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

#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "BTK_Model_types.h"

/* Exported data definition */
#include "derivative.h"

/* Definition for custom storage class: CAL_16_BTK */
CAL_BTK uint32_T KBTK_MEKSigSynTime_ms = 80U;/* ACC��ON�ź�ͬ��ʱ�䣨Կ��Ѹ��ͨOFF��ON��ON��OFF�����У� */
CAL_BTK uint32_T KBTK_MaxSSBDiffTime_ms = 80U;/* ��·����Ӳ���źŲ�ͬ�������ʱ�� */
CAL_BTK uint32_T KBTK_MaxTimeInOnState_ms = 1800000U;/* ��ѹON���������ʱ��30mins = 1800000ms */
CAL_BTK uint32_T KBTK_SSBAdhesionConfirmTime_ms = 3000U;/* SSB�������ȷ��ʱ�� */
CAL_BTK uint32_T KBTK_SSBConfirmTime_ms = 100U;/* SSB�����ź�ȷ��ʱ�� */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

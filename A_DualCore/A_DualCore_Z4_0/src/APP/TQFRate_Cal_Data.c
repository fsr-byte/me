/*
 * File: TQFRate_Cal_Data.c
 *
 * Code generated for Simulink model 'TQFRate_model'.
 *
 * Model version                  : 1.1651
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Fri Mar 18 15:48:25 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Freescale->32-bit PowerPC
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. MISRA C:2012 guidelines
 * Validation result: Not run
 */

#include "rtwtypes.h"
#include "TQFRate_model_types.h"

/* Exported data definition */
#include "derivative.h"

/* Definition for custom storage class: CAL_13_TQFRate */
CAL_TQFRate uint8_T u1_CT_TQFRate_CruiseModDriveTqDecZRat_Nmps[25] = { 5U, 5U,
  5U, 5U, 5U, 5U, 10U, 10U, 10U, 10U, 5U, 10U, 15U, 15U, 15U, 5U, 10U, 20U, 20U,
  20U, 5U, 10U, 20U, 25U, 30U } ;      /* Cruise工况下的驱动扭矩减小时的斜率限制MAP的Z轴(单位：Nm/100ms) */

CAL_TQFRate uint8_T u1_CT_TQFRate_CruiseModDriveTqIncZRat_Nmps[25] = { 5U, 5U,
  5U, 5U, 5U, 5U, 10U, 10U, 10U, 10U, 5U, 10U, 15U, 15U, 15U, 5U, 10U, 20U, 20U,
  20U, 5U, 10U, 20U, 25U, 30U } ;      /* Cruise工况下的驱动扭矩增加时的斜率限制MAP的Z轴(单位：Nm/100ms) */

CAL_TQFRate uint8_T u1_CT_TQFRate_CruiseModRegenTqDecZRat_Nmps[25] = { 5U, 5U,
  5U, 5U, 5U, 5U, 10U, 10U, 10U, 10U, 5U, 10U, 15U, 15U, 15U, 5U, 10U, 20U, 20U,
  20U, 5U, 10U, 20U, 25U, 30U } ;      /* Cruise工况下的再生制动扭矩减小时的斜率限制MAP的Z轴(单位：Nm/100ms) */

CAL_TQFRate uint8_T u1_CT_TQFRate_CruiseModRegenTqIncZRat_Nmps[25] = { 5U, 5U,
  5U, 5U, 5U, 5U, 10U, 10U, 10U, 10U, 5U, 10U, 15U, 15U, 15U, 5U, 10U, 20U, 20U,
  20U, 5U, 10U, 20U, 25U, 30U } ;      /* Cruise工况下的再生制动扭矩增加时的斜率限制MAP的Z轴(单位：Nm/100ms) */

CAL_TQFRate uint8_T u1_CT_TQFRate_EscModDriveTqDecZRat_Nmps[25] = { 255U, 255U,
  255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U,
  255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U } ;/* Esc工况下的驱动扭矩减小时的斜率限制MAP的Z轴(单位：Nm/100ms) */

CAL_TQFRate uint8_T u1_CT_TQFRate_EscModDriveTqIncZRat_Nmps[25] = { 5U, 5U, 5U,
  5U, 5U, 5U, 10U, 10U, 10U, 10U, 5U, 10U, 15U, 15U, 15U, 5U, 10U, 20U, 20U, 20U,
  5U, 10U, 20U, 25U, 30U } ;           /* Esc工况下的驱动扭矩增加时的斜率限制MAP的Z轴(单位：Nm/100ms) */

CAL_TQFRate uint8_T u1_CT_TQFRate_EscModRegenTqDecZRat_Nmps[25] = { 5U, 5U, 5U,
  5U, 5U, 5U, 10U, 10U, 10U, 10U, 5U, 10U, 15U, 15U, 15U, 5U, 10U, 20U, 20U, 20U,
  5U, 10U, 20U, 25U, 30U } ;           /* Esc工况下的再生制动扭矩减小时的斜率限制MAP的Z轴(单位：Nm/100ms) */

CAL_TQFRate uint8_T u1_CT_TQFRate_EscModRegenTqIncZRat_Nmps[25] = { 255U, 255U,
  255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U,
  255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U } ;/* Esc工况下的再生制动扭矩增加时的斜率限制MAP的Z轴(单位：Nm/100ms) */

CAL_TQFRate uint8_T u1_CT_TQFRate_IboostModDriveTqDecZRat_Nmps[25] = { 5U, 5U,
  5U, 5U, 5U, 5U, 10U, 10U, 10U, 10U, 5U, 10U, 15U, 15U, 15U, 5U, 10U, 20U, 20U,
  20U, 5U, 10U, 20U, 25U, 30U } ;      /* Iboost工况下的驱动扭矩减小时的斜率限制MAP的Z轴(单位：Nm/100ms) */

CAL_TQFRate uint8_T u1_CT_TQFRate_IboostModDriveTqIncZRat_Nmps[25] = { 5U, 5U,
  5U, 5U, 5U, 5U, 10U, 10U, 10U, 10U, 5U, 10U, 15U, 15U, 15U, 5U, 10U, 20U, 20U,
  20U, 5U, 10U, 20U, 25U, 30U } ;      /* Iboost工况下的驱动扭矩增加时的斜率限制MAP的Z轴(单位：Nm/100ms) */

CAL_TQFRate uint8_T u1_CT_TQFRate_IboostModRegenTqDecZRat_Nmps[25] = { 5U, 5U,
  5U, 5U, 5U, 5U, 10U, 10U, 10U, 10U, 5U, 10U, 15U, 15U, 15U, 5U, 10U, 20U, 20U,
  20U, 5U, 10U, 20U, 25U, 30U } ;      /* Iboost工况下的再生制动扭矩减小时的斜率限制MAP的Z轴(单位：Nm/100ms) */

CAL_TQFRate uint8_T u1_CT_TQFRate_IboostModRegenTqIncZRat_Nmps[25] = { 5U, 5U,
  5U, 5U, 5U, 5U, 10U, 10U, 10U, 10U, 5U, 10U, 15U, 15U, 15U, 5U, 10U, 20U, 20U,
  20U, 5U, 10U, 20U, 25U, 30U } ;      /* Iboost工况下的再生制动扭矩增加时的斜率限制MAP的Z轴(单位：Nm/100ms) */

CAL_TQFRate uint8_T u1_C_TQFRate_DefaultModDriveTqDecRat_Nmps = 50U;/* Default工况下扭矩斜率值 */
CAL_TQFRate uint8_T u1_C_TQFRate_DefaultModDriveTqIncRat_Nmps = 50U;/* Default工况下扭矩斜率值 */
CAL_TQFRate uint8_T u1_C_TQFRate_DefaultModRegenTqIDecRat_Nmps = 50U;/* Default工况下扭矩斜率值 */
CAL_TQFRate uint8_T u1_C_TQFRate_DefaultModRegenTqIncRat_Nmps = 50U;/* Default工况下扭矩斜率值 */
CAL_TQFRate int16_T u2_CT_TQFRate_CruiseModDriveTqDecXOldTq_Nm[5] = { 0, 97, 161,
  321, 641 } ;                         /* Cruise工况下的驱动扭矩减小时的斜率限制MAP的X轴(前回输出扭矩的绝对值) */

CAL_TQFRate int16_T u2_CT_TQFRate_CruiseModDriveTqDecYTqDiff_Nm[5] = { 0, 161,
  321, 641, 1601 } ;                   /* Cruise工况下的驱动扭矩减小时的斜率限制MAP的Y轴((今回期望扭矩 - 前回输出扭矩值)的绝对值) */

CAL_TQFRate int16_T u2_CT_TQFRate_CruiseModDriveTqIncXOldTq_Nm[5] = { 0, 97, 161,
  321, 641 } ;                         /* Cruise工况下的驱动扭矩增加时的斜率限制MAP的X轴(前回输出扭矩的绝对值) */

CAL_TQFRate int16_T u2_CT_TQFRate_CruiseModDriveTqIncYTqDiff_Nm[5] = { 0, 161,
  321, 641, 1601 } ;                   /* Cruise工况下的驱动扭矩增加时的斜率限制MAP的Y轴((今回期望扭矩 - 前回输出扭矩值)的绝对值) */

CAL_TQFRate int16_T u2_CT_TQFRate_CruiseModRegenTqDecXOldTq_Nm[5] = { 0, 97, 161,
  321, 641 } ;                         /* Cruise工况下的再生制动扭矩减小时的斜率限制MAP的X轴(前回输出扭矩的绝对值) */

CAL_TQFRate int16_T u2_CT_TQFRate_CruiseModRegenTqDecYTqDiff_Nm[5] = { 0, 161,
  321, 641, 1601 } ;                   /* Cruise工况下的再生制动扭矩减小时的斜率限制MAP的Y轴((今回期望扭矩 - 前回输出扭矩值)的绝对值) */

CAL_TQFRate int16_T u2_CT_TQFRate_CruiseModRegenTqIncXOldTq_Nm[5] = { 0, 97, 161,
  321, 641 } ;                         /* Cruise工况下的再生制动扭矩增加时的斜率限制MAP的X轴(前回输出扭矩的绝对值) */

CAL_TQFRate int16_T u2_CT_TQFRate_CruiseModRegenTqIncYTqDiff_Nm[5] = { 0, 161,
  321, 641, 1601 } ;                   /* Cruise工况下的再生制动扭矩增加时的斜率限制MAP的Y轴((今回期望扭矩 - 前回输出扭矩值)的绝对值) */

CAL_TQFRate int16_T u2_CT_TQFRate_EscModDriveTqDecXOldTq_Nm[5] = { 0, 97, 161,
  321, 641 } ;                         /* Esc工况下的驱动扭矩减小时的斜率限制MAP的X轴(前回输出扭矩的绝对值) */

CAL_TQFRate int16_T u2_CT_TQFRate_EscModDriveTqDecYTqDiff_Nm[5] = { 0, 161, 321,
  641, 1601 } ;                        /* Esc工况下的驱动扭矩减小时的斜率限制MAP的Y轴((今回期望扭矩 - 前回输出扭矩值)的绝对值) */

CAL_TQFRate int16_T u2_CT_TQFRate_EscModDriveTqIncXOldTq_Nm[5] = { 0, 97, 161,
  321, 641 } ;                         /* Esc工况下的驱动扭矩增加时的斜率限制MAP的X轴(前回输出扭矩的绝对值) */

CAL_TQFRate int16_T u2_CT_TQFRate_EscModDriveTqIncYTqDiff_Nm[5] = { 0, 161, 321,
  641, 1601 } ;                        /* Esc工况下的驱动扭矩增加时的斜率限制MAP的Y轴((今回期望扭矩 - 前回输出扭矩值)的绝对值) */

CAL_TQFRate int16_T u2_CT_TQFRate_EscModRegenTqDecXOldTq_Nm[5] = { 0, 97, 161,
  321, 641 } ;                         /* Esc工况下的再生制动扭矩减小时的斜率限制MAP的X轴(前回输出扭矩的绝对值) */

CAL_TQFRate int16_T u2_CT_TQFRate_EscModRegenTqDecYTqDiff_Nm[5] = { 0, 161, 321,
  641, 1601 } ;                        /* Esc工况下的再生制动扭矩减小时的斜率限制MAP的Y轴((今回期望扭矩 - 前回输出扭矩值)的绝对值) */

CAL_TQFRate int16_T u2_CT_TQFRate_EscModRegenTqIncXOldTq_Nm[5] = { 0, 97, 161,
  321, 641 } ;                         /* Esc工况下的再生制动扭矩增加时的斜率限制MAP的X轴(前回输出扭矩的绝对值) */

CAL_TQFRate int16_T u2_CT_TQFRate_EscModRegenTqIncYTqDiff_Nm[5] = { 0, 161, 321,
  641, 1601 } ;                        /* Esc工况下的再生制动扭矩增加时的斜率限制MAP的Y轴((今回期望扭矩 - 前回输出扭矩值)的绝对值) */

CAL_TQFRate int16_T u2_CT_TQFRate_IboostModDriveTqDecXOldTq_Nm[5] = { 0, 97, 161,
  321, 641 } ;                         /* Iboost工况下的驱动扭矩减小时的斜率限制MAP的X轴(前回输出扭矩的绝对值) */

CAL_TQFRate int16_T u2_CT_TQFRate_IboostModDriveTqDecYTqDiff_Nm[5] = { 0, 161,
  321, 641, 1601 } ;                   /* Iboost工况下的驱动扭矩减小时的斜率限制MAP的Y轴((今回期望扭矩 - 前回输出扭矩值)的绝对值) */

CAL_TQFRate int16_T u2_CT_TQFRate_IboostModDriveTqIncXOldTq_Nm[5] = { 0, 97, 161,
  321, 641 } ;                         /* Iboost工况下的驱动扭矩增加时的斜率限制MAP的X轴(前回输出扭矩的绝对值) */

CAL_TQFRate int16_T u2_CT_TQFRate_IboostModDriveTqIncYTqDiff_Nm[5] = { 0, 161,
  321, 641, 1601 } ;                   /* Iboost工况下的驱动扭矩增加时的斜率限制MAP的Y轴((今回期望扭矩 - 前回输出扭矩值)的绝对值) */

CAL_TQFRate int16_T u2_CT_TQFRate_IboostModRegenTqDecXOldTq_Nm[5] = { 0, 97, 161,
  321, 641 } ;                         /* Iboost工况下的再生制动扭矩减小时的斜率限制MAP的X轴(前回输出扭矩的绝对值) */

CAL_TQFRate int16_T u2_CT_TQFRate_IboostModRegenTqDecYTqDiff_Nm[5] = { 0, 161,
  321, 641, 1601 } ;                   /* Iboost工况下的再生制动扭矩减小时的斜率限制MAP的Y轴((今回期望扭矩 - 前回输出扭矩值)的绝对值) */

CAL_TQFRate int16_T u2_CT_TQFRate_IboostModRegenTqIncXOldTq_Nm[5] = { 0, 97, 161,
  321, 641 } ;                         /* Iboost工况下的再生制动扭矩增加时的斜率限制MAP的X轴(前回输出扭矩的绝对值) */

CAL_TQFRate int16_T u2_CT_TQFRate_IboostModRegenTqIncYTqDiff_Nm[5] = { 0, 161,
  321, 641, 1601 } ;                   /* Iboost工况下的再生制动扭矩增加时的斜率限制MAP的Y轴((今回期望扭矩 - 前回输出扭矩值)的绝对值) */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

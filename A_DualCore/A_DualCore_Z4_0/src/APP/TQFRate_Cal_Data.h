/*
 * File: TQFRate_Cal_Data.h
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

#ifndef RTW_HEADER_TQFRate_Cal_Data_h_
#define RTW_HEADER_TQFRate_Cal_Data_h_
#include "rtwtypes.h"
#include "TQFRate_model_types.h"

/* Exported data declaration */
#include "derivative.h"

/* Declaration for custom storage class: CAL_13_TQFRate */
extern CAL_TQFRate uint8_T u1_CT_TQFRate_CruiseModDriveTqDecZRat_Nmps[25];/* Cruise�����µ�����Ť�ؼ�Сʱ��б������MAP��Z��(��λ��Nm/100ms) */
extern CAL_TQFRate uint8_T u1_CT_TQFRate_CruiseModDriveTqIncZRat_Nmps[25];/* Cruise�����µ�����Ť������ʱ��б������MAP��Z��(��λ��Nm/100ms) */
extern CAL_TQFRate uint8_T u1_CT_TQFRate_CruiseModRegenTqDecZRat_Nmps[25];/* Cruise�����µ������ƶ�Ť�ؼ�Сʱ��б������MAP��Z��(��λ��Nm/100ms) */
extern CAL_TQFRate uint8_T u1_CT_TQFRate_CruiseModRegenTqIncZRat_Nmps[25];/* Cruise�����µ������ƶ�Ť������ʱ��б������MAP��Z��(��λ��Nm/100ms) */
extern CAL_TQFRate uint8_T u1_CT_TQFRate_EscModDriveTqDecZRat_Nmps[25];/* Esc�����µ�����Ť�ؼ�Сʱ��б������MAP��Z��(��λ��Nm/100ms) */
extern CAL_TQFRate uint8_T u1_CT_TQFRate_EscModDriveTqIncZRat_Nmps[25];/* Esc�����µ�����Ť������ʱ��б������MAP��Z��(��λ��Nm/100ms) */
extern CAL_TQFRate uint8_T u1_CT_TQFRate_EscModRegenTqDecZRat_Nmps[25];/* Esc�����µ������ƶ�Ť�ؼ�Сʱ��б������MAP��Z��(��λ��Nm/100ms) */
extern CAL_TQFRate uint8_T u1_CT_TQFRate_EscModRegenTqIncZRat_Nmps[25];/* Esc�����µ������ƶ�Ť������ʱ��б������MAP��Z��(��λ��Nm/100ms) */
extern CAL_TQFRate uint8_T u1_CT_TQFRate_IboostModDriveTqDecZRat_Nmps[25];/* Iboost�����µ�����Ť�ؼ�Сʱ��б������MAP��Z��(��λ��Nm/100ms) */
extern CAL_TQFRate uint8_T u1_CT_TQFRate_IboostModDriveTqIncZRat_Nmps[25];/* Iboost�����µ�����Ť������ʱ��б������MAP��Z��(��λ��Nm/100ms) */
extern CAL_TQFRate uint8_T u1_CT_TQFRate_IboostModRegenTqDecZRat_Nmps[25];/* Iboost�����µ������ƶ�Ť�ؼ�Сʱ��б������MAP��Z��(��λ��Nm/100ms) */
extern CAL_TQFRate uint8_T u1_CT_TQFRate_IboostModRegenTqIncZRat_Nmps[25];/* Iboost�����µ������ƶ�Ť������ʱ��б������MAP��Z��(��λ��Nm/100ms) */
extern CAL_TQFRate uint8_T u1_C_TQFRate_DefaultModDriveTqDecRat_Nmps;/* Default������Ť��б��ֵ */
extern CAL_TQFRate uint8_T u1_C_TQFRate_DefaultModDriveTqIncRat_Nmps;/* Default������Ť��б��ֵ */
extern CAL_TQFRate uint8_T u1_C_TQFRate_DefaultModRegenTqIDecRat_Nmps;/* Default������Ť��б��ֵ */
extern CAL_TQFRate uint8_T u1_C_TQFRate_DefaultModRegenTqIncRat_Nmps;/* Default������Ť��б��ֵ */
extern CAL_TQFRate int16_T u2_CT_TQFRate_CruiseModDriveTqDecXOldTq_Nm[5];/* Cruise�����µ�����Ť�ؼ�Сʱ��б������MAP��X��(ǰ�����Ť�صľ���ֵ) */
extern CAL_TQFRate int16_T u2_CT_TQFRate_CruiseModDriveTqDecYTqDiff_Nm[5];/* Cruise�����µ�����Ť�ؼ�Сʱ��б������MAP��Y��((�������Ť�� - ǰ�����Ť��ֵ)�ľ���ֵ) */
extern CAL_TQFRate int16_T u2_CT_TQFRate_CruiseModDriveTqIncXOldTq_Nm[5];/* Cruise�����µ�����Ť������ʱ��б������MAP��X��(ǰ�����Ť�صľ���ֵ) */
extern CAL_TQFRate int16_T u2_CT_TQFRate_CruiseModDriveTqIncYTqDiff_Nm[5];/* Cruise�����µ�����Ť������ʱ��б������MAP��Y��((�������Ť�� - ǰ�����Ť��ֵ)�ľ���ֵ) */
extern CAL_TQFRate int16_T u2_CT_TQFRate_CruiseModRegenTqDecXOldTq_Nm[5];/* Cruise�����µ������ƶ�Ť�ؼ�Сʱ��б������MAP��X��(ǰ�����Ť�صľ���ֵ) */
extern CAL_TQFRate int16_T u2_CT_TQFRate_CruiseModRegenTqDecYTqDiff_Nm[5];/* Cruise�����µ������ƶ�Ť�ؼ�Сʱ��б������MAP��Y��((�������Ť�� - ǰ�����Ť��ֵ)�ľ���ֵ) */
extern CAL_TQFRate int16_T u2_CT_TQFRate_CruiseModRegenTqIncXOldTq_Nm[5];/* Cruise�����µ������ƶ�Ť������ʱ��б������MAP��X��(ǰ�����Ť�صľ���ֵ) */
extern CAL_TQFRate int16_T u2_CT_TQFRate_CruiseModRegenTqIncYTqDiff_Nm[5];/* Cruise�����µ������ƶ�Ť������ʱ��б������MAP��Y��((�������Ť�� - ǰ�����Ť��ֵ)�ľ���ֵ) */
extern CAL_TQFRate int16_T u2_CT_TQFRate_EscModDriveTqDecXOldTq_Nm[5];/* Esc�����µ�����Ť�ؼ�Сʱ��б������MAP��X��(ǰ�����Ť�صľ���ֵ) */
extern CAL_TQFRate int16_T u2_CT_TQFRate_EscModDriveTqDecYTqDiff_Nm[5];/* Esc�����µ�����Ť�ؼ�Сʱ��б������MAP��Y��((�������Ť�� - ǰ�����Ť��ֵ)�ľ���ֵ) */
extern CAL_TQFRate int16_T u2_CT_TQFRate_EscModDriveTqIncXOldTq_Nm[5];/* Esc�����µ�����Ť������ʱ��б������MAP��X��(ǰ�����Ť�صľ���ֵ) */
extern CAL_TQFRate int16_T u2_CT_TQFRate_EscModDriveTqIncYTqDiff_Nm[5];/* Esc�����µ�����Ť������ʱ��б������MAP��Y��((�������Ť�� - ǰ�����Ť��ֵ)�ľ���ֵ) */
extern CAL_TQFRate int16_T u2_CT_TQFRate_EscModRegenTqDecXOldTq_Nm[5];/* Esc�����µ������ƶ�Ť�ؼ�Сʱ��б������MAP��X��(ǰ�����Ť�صľ���ֵ) */
extern CAL_TQFRate int16_T u2_CT_TQFRate_EscModRegenTqDecYTqDiff_Nm[5];/* Esc�����µ������ƶ�Ť�ؼ�Сʱ��б������MAP��Y��((�������Ť�� - ǰ�����Ť��ֵ)�ľ���ֵ) */
extern CAL_TQFRate int16_T u2_CT_TQFRate_EscModRegenTqIncXOldTq_Nm[5];/* Esc�����µ������ƶ�Ť������ʱ��б������MAP��X��(ǰ�����Ť�صľ���ֵ) */
extern CAL_TQFRate int16_T u2_CT_TQFRate_EscModRegenTqIncYTqDiff_Nm[5];/* Esc�����µ������ƶ�Ť������ʱ��б������MAP��Y��((�������Ť�� - ǰ�����Ť��ֵ)�ľ���ֵ) */
extern CAL_TQFRate int16_T u2_CT_TQFRate_IboostModDriveTqDecXOldTq_Nm[5];/* Iboost�����µ�����Ť�ؼ�Сʱ��б������MAP��X��(ǰ�����Ť�صľ���ֵ) */
extern CAL_TQFRate int16_T u2_CT_TQFRate_IboostModDriveTqDecYTqDiff_Nm[5];/* Iboost�����µ�����Ť�ؼ�Сʱ��б������MAP��Y��((�������Ť�� - ǰ�����Ť��ֵ)�ľ���ֵ) */
extern CAL_TQFRate int16_T u2_CT_TQFRate_IboostModDriveTqIncXOldTq_Nm[5];/* Iboost�����µ�����Ť������ʱ��б������MAP��X��(ǰ�����Ť�صľ���ֵ) */
extern CAL_TQFRate int16_T u2_CT_TQFRate_IboostModDriveTqIncYTqDiff_Nm[5];/* Iboost�����µ�����Ť������ʱ��б������MAP��Y��((�������Ť�� - ǰ�����Ť��ֵ)�ľ���ֵ) */
extern CAL_TQFRate int16_T u2_CT_TQFRate_IboostModRegenTqDecXOldTq_Nm[5];/* Iboost�����µ������ƶ�Ť�ؼ�Сʱ��б������MAP��X��(ǰ�����Ť�صľ���ֵ) */
extern CAL_TQFRate int16_T u2_CT_TQFRate_IboostModRegenTqDecYTqDiff_Nm[5];/* Iboost�����µ������ƶ�Ť�ؼ�Сʱ��б������MAP��Y��((�������Ť�� - ǰ�����Ť��ֵ)�ľ���ֵ) */
extern CAL_TQFRate int16_T u2_CT_TQFRate_IboostModRegenTqIncXOldTq_Nm[5];/* Iboost�����µ������ƶ�Ť������ʱ��б������MAP��X��(ǰ�����Ť�صľ���ֵ) */
extern CAL_TQFRate int16_T u2_CT_TQFRate_IboostModRegenTqIncYTqDiff_Nm[5];/* Iboost�����µ������ƶ�Ť������ʱ��б������MAP��Y��((�������Ť�� - ǰ�����Ť��ֵ)�ľ���ֵ) */

#endif                                 /* RTW_HEADER_TQFRate_Cal_Data_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

/*
 * File: ACR_Cal_Data.h
 *
 * Code generated for Simulink model 'ACR_model'.
 *
 * Model version                  : 1.1784
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Fri Mar 18 15:46:44 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Freescale->32-bit PowerPC
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. MISRA C:2012 guidelines
 * Validation result: Not run
 */

#ifndef RTW_HEADER_ACR_Cal_Data_h_
#define RTW_HEADER_ACR_Cal_Data_h_
#include "rtwtypes.h"
#include "ACR_model_types.h"

/* Exported data declaration */
#include "derivative.h"

/* Declaration for custom storage class: CAL_12_ACR */
extern CAL_ACR real32_T ACR_Air_Friction_Cal;/* ����ϵ�� */
extern CAL_ACR uint8_T ACR_Gear_D;     /* D������ */
extern CAL_ACR uint8_T ACR_Gear_R;     /* R������ */
extern CAL_ACR real32_T ACR_Roll_Friction_Cal;/* ����ϵ�� */
extern CAL_ACR real32_T ACR_RotMassConvCoeff_Cal;/* ��ת��������ϵ�� */
extern CAL_ACR real32_T ACR_Tyre_Radius_Cal;/* ���ֹ����뾶 */
extern CAL_ACR real32_T ACR_VehSysConvEffi;/* ϵͳ����Ч�� */
extern CAL_ACR real32_T ACR_Vehicle_Face_Area;/* ӭ����� */
extern CAL_ACR real32_T ACR_Vehicle_Weight_Cal;/* ���� */
extern CAL_ACR real32_T ACR_Velocity_Ratio_Cal;/* ���ٱ� */
extern CAL_ACR boolean_T KALC_SpdCon_VehDyn_EnableFlag;/* ���ٶȻ�����Ť�ؿ��� */
extern CAL_ACR boolean_T b1_C_ALC_DynTqEna;/* ����ѧ��̬Ť�ؼ���ʹ���ź� */
extern CAL_ACR boolean_T b1_C_ALC_PID_Ena;/* ���ٶȻ�PIDʹ���ź� */
extern CAL_ACR real32_T f4_CT_ALC_AccePct[26];/* D/R��������ٶ�map-����̤�忪�� */
extern CAL_ACR real32_T f4_CT_ALC_AclDiff_Ki[25];/* ���ٶȻ�Kp/Ki_Map-Ki */
extern CAL_ACR real32_T f4_CT_ALC_AclDiff_Kp[25];/* ���ٶȻ�Kp/Ki_Map-Kp */
extern CAL_ACR real32_T f4_CT_ALC_AclDiff_mpss[25];/* ���ٶȻ�Kp/Ki_Map-Ŀ����ٶ���ʵ�ʼ��ٶȲ� */
extern CAL_ACR real32_T f4_CT_ALC_BaseTqX_kph[14];/* D/R��������ٶ�map-Ŀ�공��X�� */
extern CAL_ACR real32_T f4_CT_ALC_BaseTqY_Nm[14];/* D/R��������ٶ�map-����Ť��Y�� */
extern CAL_ACR real32_T f4_CT_ALC_GearD_DemAcl_mpss[962];/* D/R��������ٶ�map-D��������ٶ� */
extern CAL_ACR real32_T f4_CT_ALC_GearR_DemAcl_mpss[962];/* D/R��������ٶ�map-R��������ٶ� */
extern CAL_ACR real32_T f4_CT_ALC_TargetSpdX_Pct[21];/* D/R��������ٶ�map-����̤�忪��X�� */
extern CAL_ACR real32_T f4_CT_ALC_TargetSpdY_kph[21];/* D/R��������ٶ�map-Ŀ�공��Y�� */
extern CAL_ACR real32_T f4_CT_ALC_VehSpd_kph[37];/* D/R��������ٶ�map-���� */
extern CAL_ACR real32_T f4_C_ALC_AclCtr_IntHold_AclDem_mpss;/* ���������ٶȶȴ��ڸ�ֵʱ�����������ٶ���ʵ�ʼ��ٶȲ�ֵС���趨ֵ����ֹͣ���� */
extern CAL_ACR real32_T f4_C_ALC_AclCtr_IntHold_AclDiff_mpss;/* ���������ٶȶȴ����趨ֵʱ�����������ٶ���ʵ�ʼ��ٶȲ�ֵС�ڸ�ֵ����ֹͣ���� */
extern CAL_ACR real32_T f4_C_ALC_AclCtr_TqDownFilter;/* ���ٶȻ�Ť���½��˲�ϵ�� */
extern CAL_ACR real32_T f4_C_ALC_AclCtr_TqDownGradLim;/* ���ٶȻ��½�б������ */
extern CAL_ACR real32_T f4_C_ALC_AclCtr_TqUpFilter;/* ���ٶȻ�Ť�������˲�ϵ�� */
extern CAL_ACR real32_T f4_C_ALC_AclCtr_TqUpGradLim;/* ���ٶȻ�����б������ */
extern CAL_ACR real32_T f4_C_ALC_GearD_PIDEnaRodeSlope_deg;/* ����D����·���¶ȴ��ڸ�ֵʱʹ�ܼ��ٶȻ�PID���� */
extern CAL_ACR real32_T f4_C_ALC_GearD_PIDUnaRodeSlope_deg;/* ����D����·���¶�С�ڸ�ֵʱ�رռ��ٶȻ�PID���� */
extern CAL_ACR real32_T f4_C_ALC_GearR_PIDEnaRodeSlope_deg;/* ����R����·���¶ȴ��ڸ�ֵʱʹ�ܼ��ٶȻ�PID���� */
extern CAL_ACR real32_T f4_C_ALC_GearR_PIDUnaRodeSlope_deg;/* ����R����·���¶�С�ڸ�ֵʱ�رռ��ٶȻ�PID���� */
extern CAL_ACR int8_T s1_C_ALC_AclCtr_MaxIntLim;/* ���ٶȻ���������ֵ */
extern CAL_ACR int8_T s1_C_ALC_AclCtr_MinIntLim;/* ���ٶȻ���������ֵ */
extern CAL_ACR int16_T s2_C_ALC_AclCtr_MaxDynTqLim;/* ����ѧ��̬Ť���������ֵ */
extern CAL_ACR int16_T s2_C_ALC_AclCtr_MinDynTqLim;/* ����ѧ��̬Ť����С����ֵ */
extern CAL_ACR int16_T s2_C_ALC_AclCtr_PIDMaxLim;/* ���ٶȻ�PID����ֵ */
extern CAL_ACR int16_T s2_C_ALC_AclCtr_PIDMinLim;/* ���ٶȻ�PID����ֵ */
extern CAL_ACR int16_T s2_C_ALC_AclCtr_TqMax;/* ���ٶȻ����Ť������ */
extern CAL_ACR int16_T s2_C_ALC_AclCtr_TqMin;/* ���ٶȻ���СŤ������ */

#endif                                 /* RTW_HEADER_ACR_Cal_Data_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

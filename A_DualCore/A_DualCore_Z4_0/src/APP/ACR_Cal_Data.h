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
extern CAL_ACR real32_T ACR_Air_Friction_Cal;/* 风阻系数 */
extern CAL_ACR uint8_T ACR_Gear_D;     /* D挡代号 */
extern CAL_ACR uint8_T ACR_Gear_R;     /* R挡代号 */
extern CAL_ACR real32_T ACR_Roll_Friction_Cal;/* 滚阻系数 */
extern CAL_ACR real32_T ACR_RotMassConvCoeff_Cal;/* 旋转质量换算系数 */
extern CAL_ACR real32_T ACR_Tyre_Radius_Cal;/* 车轮滚动半径 */
extern CAL_ACR real32_T ACR_VehSysConvEffi;/* 系统传递效率 */
extern CAL_ACR real32_T ACR_Vehicle_Face_Area;/* 迎风面积 */
extern CAL_ACR real32_T ACR_Vehicle_Weight_Cal;/* 车重 */
extern CAL_ACR real32_T ACR_Velocity_Ratio_Cal;/* 减速比 */
extern CAL_ACR boolean_T KALC_SpdCon_VehDyn_EnableFlag;/* 加速度环基础扭矩开关 */
extern CAL_ACR boolean_T b1_C_ALC_DynTqEna;/* 动力学静态扭矩计算使能信号 */
extern CAL_ACR boolean_T b1_C_ALC_PID_Ena;/* 加速度环PID使能信号 */
extern CAL_ACR real32_T f4_CT_ALC_AccePct[26];/* D/R挡需求加速度map-加速踏板开度 */
extern CAL_ACR real32_T f4_CT_ALC_AclDiff_Ki[25];/* 加速度环Kp/Ki_Map-Ki */
extern CAL_ACR real32_T f4_CT_ALC_AclDiff_Kp[25];/* 加速度环Kp/Ki_Map-Kp */
extern CAL_ACR real32_T f4_CT_ALC_AclDiff_mpss[25];/* 加速度环Kp/Ki_Map-目标加速度与实际加速度差 */
extern CAL_ACR real32_T f4_CT_ALC_BaseTqX_kph[14];/* D/R挡需求加速度map-目标车速X轴 */
extern CAL_ACR real32_T f4_CT_ALC_BaseTqY_Nm[14];/* D/R挡需求加速度map-基础扭矩Y轴 */
extern CAL_ACR real32_T f4_CT_ALC_GearD_DemAcl_mpss[962];/* D/R挡需求加速度map-D挡需求加速度 */
extern CAL_ACR real32_T f4_CT_ALC_GearR_DemAcl_mpss[962];/* D/R挡需求加速度map-R挡需求加速度 */
extern CAL_ACR real32_T f4_CT_ALC_TargetSpdX_Pct[21];/* D/R挡需求加速度map-加速踏板开度X轴 */
extern CAL_ACR real32_T f4_CT_ALC_TargetSpdY_kph[21];/* D/R挡需求加速度map-目标车速Y轴 */
extern CAL_ACR real32_T f4_CT_ALC_VehSpd_kph[37];/* D/R挡需求加速度map-车速 */
extern CAL_ACR real32_T f4_C_ALC_AclCtr_IntHold_AclDem_mpss;/* 当期望加速度度大于该值时，若期望加速度与实际加速度差值小于设定值，则停止积分 */
extern CAL_ACR real32_T f4_C_ALC_AclCtr_IntHold_AclDiff_mpss;/* 当期望加速度度大于设定值时，若期望加速度与实际加速度差值小于该值，则停止积分 */
extern CAL_ACR real32_T f4_C_ALC_AclCtr_TqDownFilter;/* 加速度环扭矩下降滤波系数 */
extern CAL_ACR real32_T f4_C_ALC_AclCtr_TqDownGradLim;/* 加速度环下降斜率限制 */
extern CAL_ACR real32_T f4_C_ALC_AclCtr_TqUpFilter;/* 加速度环扭矩上升滤波系数 */
extern CAL_ACR real32_T f4_C_ALC_AclCtr_TqUpGradLim;/* 加速度环上升斜率限制 */
extern CAL_ACR real32_T f4_C_ALC_GearD_PIDEnaRodeSlope_deg;/* 处于D挡，路面坡度大于该值时使能加速度环PID调节 */
extern CAL_ACR real32_T f4_C_ALC_GearD_PIDUnaRodeSlope_deg;/* 处于D挡，路面坡度小于该值时关闭加速度环PID调节 */
extern CAL_ACR real32_T f4_C_ALC_GearR_PIDEnaRodeSlope_deg;/* 处于R挡，路面坡度大于该值时使能加速度环PID调节 */
extern CAL_ACR real32_T f4_C_ALC_GearR_PIDUnaRodeSlope_deg;/* 处于R挡，路面坡度小于该值时关闭加速度环PID调节 */
extern CAL_ACR int8_T s1_C_ALC_AclCtr_MaxIntLim;/* 加速度环积分上限值 */
extern CAL_ACR int8_T s1_C_ALC_AclCtr_MinIntLim;/* 加速度环积分下限值 */
extern CAL_ACR int16_T s2_C_ALC_AclCtr_MaxDynTqLim;/* 动力学静态扭矩最大限制值 */
extern CAL_ACR int16_T s2_C_ALC_AclCtr_MinDynTqLim;/* 动力学静态扭矩最小限制值 */
extern CAL_ACR int16_T s2_C_ALC_AclCtr_PIDMaxLim;/* 加速度环PID上限值 */
extern CAL_ACR int16_T s2_C_ALC_AclCtr_PIDMinLim;/* 加速度环PID下限值 */
extern CAL_ACR int16_T s2_C_ALC_AclCtr_TqMax;/* 加速度环最大扭矩限制 */
extern CAL_ACR int16_T s2_C_ALC_AclCtr_TqMin;/* 加速度环最小扭矩限制 */

#endif                                 /* RTW_HEADER_ACR_Cal_Data_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

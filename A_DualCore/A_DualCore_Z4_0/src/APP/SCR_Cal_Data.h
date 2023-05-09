/*
 * File: SCR_Cal_Data.h
 *
 * Code generated for Simulink model 'SCR_model'.
 *
 * Model version                  : 1.2266
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Fri Mar 18 15:47:47 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Freescale->32-bit PowerPC
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. MISRA C:2012 guidelines
 * Validation result: Not run
 */

#ifndef RTW_HEADER_SCR_Cal_Data_h_
#define RTW_HEADER_SCR_Cal_Data_h_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "SCR_model_types.h"

/* Exported data define */

/* Definition for custom storage class: Define */
#define CAL_GEARD                      4U                        /* 系统档位：D档 */
#define CAL_GEARR                      1U                        /* 系统档位：R档 */
#define CAL_GEARRRELEASE               0U                        /* 系统档位：R档下行程 */
#define CRUISE_CANCEL                  2U                        /* Cruise模式：CANCEL */
#define CRUISE_OFF                     0U                        /* Cruise模式：OFF */
#define CRUISE_OVERRIDE                4U                        /* Cruise模式：OVERRIDE */
#define CRUISE_RESUMEFROMCANCEL        6U                        /* Cruise模式：RESUMEFROMCANCEL */
#define CRUISE_RESUMEFROMOVERRIDE      5U                        /* Cruise模式：RESUMEFROMOVERRIDE */
#define CRUISE_SPDSTEADY               3U                        /* Cruise模式：SPDSTEADY */
#define CRUISE_STANDBY                 1U                        /* Cruise模式：STANDBY */
#define GEARD                          4U                        /* D档 */
#define U1S_KEYTYPE_ACCEL              2U                        /* Cruise RES+按键长加目标巡航车速 */
#define U1S_KEYTYPE_DECEL              4U                        /* Cruise SET-按键长加目标巡航车速 */
#define U1S_KEYTYPE_NONE               0U                        /* Cruise按键未按下 */
#define U1S_KEYTYPE_TIPDOWN            3U                        /* Cruise SET-按键点减目标巡航车速 */
#define U1S_KEYTYPE_TIPUP              1U                        /* Cruise RES+按键点加目标巡航车速 */
#define U1_C_NEDC_BRAKETYPE_KMPH120120 6U
#define U1_C_NEDC_BRAKETYPE_KMPH12050  8U
#define U1_C_NEDC_BRAKETYPE_KMPH12080  7U
#define U1_C_NEDC_BRAKETYPE_KMPH15     1U
#define U1_C_NEDC_BRAKETYPE_KMPH32     2U
#define U1_C_NEDC_BRAKETYPE_KMPH35     4U
#define U1_C_NEDC_BRAKETYPE_KMPH50     3U
#define U1_C_NEDC_BRAKETYPE_KMPH70     5U

/* Exported data declaration */
#include "derivative.h"

/* Declaration for custom storage class: CAL_11_SCR */
extern CAL_SCR uint8_T CLTC;           /* CLTC功能等速工况标志位7 */
extern CAL_SCR uint8_T CLTC_SOC40;     /* CLTC功能等速工况标志位5 */
extern CAL_SCR uint8_T CLTC_SOC50;     /* CLTC功能等速工况标志位4 */
extern CAL_SCR uint8_T CLTC_SOC60;     /* CLTC功能等速工况标志位3 */
extern CAL_SCR uint8_T CLTC_SOC70;     /* CLTC功能等速工况标志位2 */
extern CAL_SCR uint8_T CLTC_SOC80;     /* CLTC功能等速工况标志位1 */
extern CAL_SCR uint16_T CRS_No_Evflag_TrueDelay;/* 使能加速度算法 */
extern CAL_SCR uint16_T KCRS_AccelPdlInvalidJudgeTime_ms;/* 加速踏板无效判断时间 */
extern CAL_SCR uint16_T KCRS_BrakePdlInvalidJudgeTime_ms;/* 制动踏板无效判断时间 */
extern CAL_SCR boolean_T KCRS_CRUISECtrlErr_Ena;/* 定速巡航系统故障开关使能条件 */
extern CAL_SCR uint8_T KCRS_CRUISECtrlErr_Val;/* 定速巡航系统故障开关使能默认值 */
extern CAL_SCR uint32_T KCRS_CRUISECtrlErr_holdtime_ms;/* 定速巡航硬件故障点亮故障灯延迟时间 */
extern CAL_SCR boolean_T KCRS_CRUISECtrlSys_Ena;/* 定速巡航系统状态开关使能条件 */
extern CAL_SCR uint8_T KCRS_CRUISECtrlSys_Val;/* 定速巡航系统故障开关使能默认值 */
extern CAL_SCR boolean_T KCRS_CRUISEModStop_Ena;/* 定速巡航文字提醒开关 */
extern CAL_SCR boolean_T KCRS_CRUISEModStop_Val;/* 定速巡航文字提醒开关量 */
extern CAL_SCR uint32_T KCRS_CruiseMaxMinSpdJudge_delta;/* Cruise最大允许车速的波动值 */
extern CAL_SCR uint32_T KCRS_CruiseMaxSpd;/* Cruise最大允许车速 */
extern CAL_SCR uint32_T KCRS_CruiseMinSpd;/* Cruise最小允许车速 */
extern CAL_SCR uint32_T KCRS_CruiseMinSpdNoTouchCheckTime_ms;/* 定速巡航实际车速小于巡航车速判断时间 */
extern CAL_SCR uint8_T KCRS_CruiseMinSpdNoTouchJudge_delta;/* 定速巡航实际车速小于巡航车速判断车速差阈值 */
extern CAL_SCR boolean_T KCRS_CruiseModuleWork_Ena;/* 定速巡航开启开关使能条件 */
extern CAL_SCR boolean_T KCRS_CruiseModuleWork_Val;/* 定速巡航开启开关使能数值 */
extern CAL_SCR boolean_T KCRS_CruiseResumeMode_En;/* 定速巡航Resume功能使能开关 */
extern CAL_SCR boolean_T KCRS_CruiseVehSpdMode_en;/* 定速巡航输入车速模式选择开关 */
extern CAL_SCR uint16_T KCRS_CruiseVehSpdSatisfyCheckTime_ms;/* 实际车速满足巡航车速的持续判断时间 */
extern CAL_SCR uint16_T KCRS_GearInvalidJudgeTime_ms;/* 档位无效判断时间 */
extern CAL_SCR uint16_T KCRS_ICMVehpdDisp_Filter;/* 定速巡航功能仪表车速滤波功能滤波系数 */
extern CAL_SCR boolean_T KCRS_ICMVehpdDisp_Filter_en;/* 定速巡航功能仪表车速滤波功能开关 */
extern CAL_SCR uint16_T KCRS_KeyLongPressActiveTime_mS;/* SET/RES按键长按判断最小时间 */
extern CAL_SCR uint32_T KCRS_KeyResActiveTime_mS;/* 定速巡航恢复功能判断时间 */
extern CAL_SCR uint32_T KCRS_KeySetActiveTime_mS;/* 定速巡航设定功能判断时间 */
extern CAL_SCR uint16_T KCRS_KeyShortPressActiveTime_mS;/* 按键短按判断最小时间 */
extern CAL_SCR uint32_T KCRS_LongPressStepTime_mS;/* 定速巡航长按车速阶跃式增加判定时间 */
extern CAL_SCR uint32_T KCRS_MinorCruiseFaultDelayTime_ms;/* 轻微故障恢复持续判断时间 */
extern CAL_SCR real32_T KCRS_PID_IntegralMax;/* PID积分器的最大值 */
extern CAL_SCR real32_T KCRS_PID_IntegralMin;/* 参考滑行能量回收二档的最大负扭矩值 */
extern CAL_SCR real32_T KCRS_PID_PidMax;/* PID的最大值 */
extern CAL_SCR real32_T KCRS_PID_PidMin;/* 参考滑行能量回收二档的最大负扭矩值 */
extern CAL_SCR real32_T KCRS_PID_SpdDelta_Max;/* PID速度偏差值允许最大值 */
extern CAL_SCR real32_T KCRS_PID_SpdDelta_Min;/* PID速度偏差值允许最小值 */
extern CAL_SCR uint16_T KCRS_PressOnOffDebounceThreshold;/* 按键按下和松开的防抖动阈值时间 */
extern CAL_SCR uint8_T KCRS_QuitCruise_PowerLimitPct;/* 当DHP限功率百分比小于该值时，关闭定速巡航 */
extern CAL_SCR uint32_T KCRS_QuitCruise_TargetVehSpdDiff_HoldTime_ms;/* 当abs(实际车速-目标车速)大于该值，且持续一段时间时，退出定速巡航 */
extern CAL_SCR uint32_T KCRS_QuitCruise_TargetVehSpdDiff_kph;/* 当abs(实际车速-目标车速)大于该值，且持续一段时间时，退出定速巡航 */
extern CAL_SCR uint32_T KCRS_QuitCruise_VehSpdLimit;/* 退出定速巡航功能后系统最小车速 */
extern CAL_SCR uint32_T KCRS_RealSpdOffUpLimit_HoldTime_ms;/* 定速巡航实际车速超出最大车速故障判断时间 */
extern CAL_SCR uint8_T KCRS_RealSpdOffUpLimit_delta;/* 定速巡航实际车速超出最大车速故障车速差阈值 */
extern CAL_SCR real32_T KCRS_SpdCon_PIDAccDecKiX_kph[6];/* （长加长减车速工况）目标巡航车速 */
extern CAL_SCR real32_T KCRS_SpdCon_PIDAccDecKiY_kph[9];/* （长加长减车速工况）目标巡航车速和实际车速的速度差（用于I比例），用于设定目标巡航车速 */
extern CAL_SCR real32_T KCRS_SpdCon_PIDAccDecKiZ[54];/* （长加长减车速工况）PID Ki，用于设定目标巡航车速 */
extern CAL_SCR real32_T KCRS_SpdCon_PIDAccDecKpX_kph[6];/* （长加长减车速工况）目标巡航车速 */
extern CAL_SCR real32_T KCRS_SpdCon_PIDAccDecKpY_kph[7];/* （长加长减车速工况）目标巡航车速和实际车速的速度差（用于P比例），用于设定目标巡航车速 */
extern CAL_SCR real32_T KCRS_SpdCon_PIDAccDecKpZ[42];/* （长加长减车速工况）PID Kp，用于设定目标巡航车速 */
extern CAL_SCR real32_T KCRS_SpdCon_PIDSetResumeKiX_kph[6];/* （设定恢复工况）目标巡航车速 */
extern CAL_SCR real32_T KCRS_SpdCon_PIDSetResumeKiY_kph[9];/* （设定恢复工况）目标巡航车速和实际车速的速度差（用于I积分），用于设定目标巡航车速 */
extern CAL_SCR real32_T KCRS_SpdCon_PIDSetResumeKiZ[54];/* （设定恢复工况）PID Ki，用于设定目标巡航车速 */
extern CAL_SCR real32_T KCRS_SpdCon_PIDSetResumeKpX_kph[6];/* （设定恢复工况）目标巡航车速 */
extern CAL_SCR real32_T KCRS_SpdCon_PIDSetResumeKpY_kph[9];/* （设定恢复工况）目标巡航车速和实际车速的速度差（用于P比例），用于设定目标巡航车速 */
extern CAL_SCR real32_T KCRS_SpdCon_PIDSetResumeKpZ[54];/* （设定恢复工况）PID Kp，用于设定目标巡航车速 */
extern CAL_SCR real32_T KCRS_SpdCon_PIDTipUpDownKiX_kph[5];/* （点加点减车速工况）目标巡航车速 */
extern CAL_SCR real32_T KCRS_SpdCon_PIDTipUpDownKiY_kph[9];/* （点加点减车速工况）目标巡航车速和实际车速的速度差（用于I比例），用于设定目标巡航车速 */
extern CAL_SCR real32_T KCRS_SpdCon_PIDTipUpDownKiZ[45];/* （点加点减车速工况）PID Ki，用于设定目标巡航车速 */
extern CAL_SCR real32_T KCRS_SpdCon_PIDTipUpDownKpX_kph[6];/* （点加点减车速工况）目标巡航车速 */
extern CAL_SCR real32_T KCRS_SpdCon_PIDTipUpDownKpY_kph[7];/* （点加点减车速工况）目标巡航车速和实际车速的速度差（用于P比例），用于设定目标巡航车速 */
extern CAL_SCR real32_T KCRS_SpdCon_PIDTipUpDownKpZ[42];/* （点加点减车速工况）PID Kp，用于设定目标巡航车速 */
extern CAL_SCR real32_T KCRS_SpdCon_PID_IntegralHoldExit_SpdDelta;/* 当实际车速和目标巡航车速的差值稳定在1kph以内，并保持指定时间5s(TBD)时，PID积分器保持 */
extern CAL_SCR uint16_T KCRS_SpdCon_PID_IntegralHoldExit_SpdDelta_Time_ms;/* 当实际车速和目标巡航车速的差值稳定在1kph以内，并保持指定时间5s(TBD)时，PID积分器保持 */
extern CAL_SCR real32_T KCRS_SpdCon_PID_IntegralHold_SpdDelta;/* 当实际车速和目标巡航车速的差值稳定在1kph以内，并保持指定时间5s(TBD)时，PID积分器保持 */
extern CAL_SCR uint16_T KCRS_SpdCon_PID_IntegralHold_SpdDelta_Time_ms;/* 当实际车速和目标巡航车速的差值稳定在1kph以内，并保持指定时间5s(TBD)时，PID积分器保持 */
extern CAL_SCR boolean_T KCRS_SpdCon_Pid_EnableFlag;/* 使能PID */
extern CAL_SCR boolean_T KCRS_SpdCon_VehDyn_EnableFlag;/* 使能车辆纵向动力学模型 */
extern CAL_SCR uint16_T KCRS_TargetVehSpdDiff_DelayTime_ms;/* 定速巡航能力受限导致车速异常退出巡航状态文字提醒时间 */
extern CAL_SCR real32_T KCRS_TorqFlt_FirstOrderDownRatio;/* 定速巡航扭矩一阶滤波参数(下降段) */
extern CAL_SCR real32_T KCRS_TorqFlt_FirstOrderUpRatio;/* 定速巡航扭矩一阶滤波参数(上升段) */
extern CAL_SCR real32_T KCRS_TorqFlt_GradLimLowVal;/* 加速度的最大jerk通过该值来限制
                                                      该值的计算方法如下：以最大加速度jerk为-1.5m/s3，采样时间为0.02s，使用纵向动力学公式中的加速阻力来计算：
                                                      1575*-1.5*0.02*1.05*0.3234/7.93/0.973=-3.46 */
extern CAL_SCR real32_T KCRS_TorqFlt_GradLimMaxVal;/* 梯度限制后的最大允许输出正扭矩
                                                      该值的计算方法如下：以最大加速度为1.75m/s使用纵向动力学公式中的加速阻力来计算：
                                                      1575*1.75*1.05*0.3234/7.93/0.973=121 */
extern CAL_SCR real32_T KCRS_TorqFlt_GradLimMinVal;/* 参考滑行能量回收二档的最大负扭矩值 */
extern CAL_SCR real32_T KCRS_TorqFlt_GradLimUpVal;/* 加速度的最大jerk通过该值来限制
                                                     该值的计算方法如下：以最大加速度jerk为1.5m/s3，采样时间为0.02s，使用纵向动力学公式中的加速阻力来计算：
                                                     1575*1.5*0.02*1.05*0.3234/7.93/0.973=3.46 */
extern CAL_SCR real32_T KCRS_VehDyn_TorqueMax;/* 车辆纵向动力学的最大允许输出正扭矩 */
extern CAL_SCR real32_T KCRS_VehDyn_TorqueMin;/* 车辆纵向动力学的最小允许输出正扭矩 */
extern CAL_SCR uint32_T KCRS_VehSpdCheckDelayTime_period;/* 对于ABS车速变化异常进行检测周期 */
extern CAL_SCR uint16_T KCRS_VehSpdInvalidJudgeTime_ms;/* 车速无效判断时间 */
extern CAL_SCR uint8_T KCRS_t_CRUISECtrlSysDelayTime_ms;/* 定速巡航Run模式退出确认时间 */
extern CAL_SCR uint16_T KCRS_t_CancelPress_ms;/* 定速巡航Cancel动作判断：N挡下行程拨动停滞时间 */
extern CAL_SCR uint32_T KCRS_t_CruiseRun_ms;/* 定速巡航怀挡开关设定功能判断时间 */
extern CAL_SCR uint32_T KHDC_ABSSpeedSatisfy_Delaytime_ms;/* 陡坡缓降使能条件车速满足确认时间 */
extern CAL_SCR uint32_T KHDC_AccSpdThreshold_Delaytime1_ms;/* 陡坡缓降使能加速度满足持续判断时间1 */
extern CAL_SCR uint32_T KHDC_AccSpdThreshold_Delaytime2_ms;/* 陡坡缓降使能加速度满足持续判断时间2 */
extern CAL_SCR uint32_T KHDC_AccSpdThreshold_Delaytime3_ms;/* 陡坡缓降使能加速度满足持续判断时间3 */
extern CAL_SCR uint8_T KHDC_AccSpd_Filter;/* 陡坡缓降加速度一阶滤波因子 */
extern CAL_SCR int32_T KHDC_AccSpd_Threshold1_mpss;/* 陡坡缓降使能加速度阈值1 */
extern CAL_SCR int32_T KHDC_AccSpd_Threshold2_mpss;/* 陡坡缓降使能加速度阈值2 */
extern CAL_SCR int32_T KHDC_AccSpd_Threshold3_mpss;/* 陡坡缓降使能加速度阈值3 */
extern CAL_SCR uint32_T KHDC_AcceMode_Delaytime_ms;/* 陡坡缓降使能条件驱动扭矩判断时间 */
extern CAL_SCR boolean_T KHDC_C_HDC_En;/* 陡坡缓降配置使能 */
extern CAL_SCR real32_T KHDC_CreepGearDSpd_Threshold_KPH;/* 陡坡缓降退出条件蠕行D挡限制车速阈值 */
extern CAL_SCR real32_T KHDC_CreepGearRSpd_Threshold_KPH;/* 陡坡缓降退出条件蠕行R挡限制车速阈值 */
extern CAL_SCR uint8_T KHDC_DHPLimitSpd_Threshold_Nm;/* 陡坡缓降使能诊断模块限制车速最小阈值 */
extern CAL_SCR uint8_T KHDC_GearDSpdLower_KPH;/* 陡坡缓降使能条件D挡车速下限 */
extern CAL_SCR uint8_T KHDC_GearDSpdUpper_KPH;/* 陡坡缓降使能条件D挡车速上限 */
extern CAL_SCR real32_T KHDC_GearD_AcceMode_Threshold_Nm;/* 陡坡缓降使能条件D驱动挡扭矩判断阈值 */
extern CAL_SCR int16_T KHDC_GearD_VehTq_Threshold_Nm;/* 陡坡缓降踩制动退出时D挡扭矩下限 */
extern CAL_SCR uint8_T KHDC_GearRSpdLower_KPH;/* 陡坡缓降使能条件R挡车速下限 */
extern CAL_SCR uint8_T KHDC_GearRSpdUpper_KPH;/* 陡坡缓降使能条件R挡车速上限 */
extern CAL_SCR real32_T KHDC_GearR_AcceMode_Threshold_Nm;/* 陡坡缓降使能条件R挡驱动扭矩判断阈值 */
extern CAL_SCR int16_T KHDC_GearR_VehTq_Threshold_Nm;/* 陡坡缓降踩制动退出时R挡扭矩上限 */
extern CAL_SCR boolean_T KHDC_HDCrun_Ena;/* 陡坡缓降使能开关 */
extern CAL_SCR boolean_T KHDC_HDCrun_Val;/* 陡坡缓降使能数值 */
extern CAL_SCR real32_T KHDC_Kalman_P; /* 陡坡缓降加速度卡尔曼滤波P参数 */
extern CAL_SCR real32_T KHDC_Kalman_Q; /* 陡坡缓降加速度卡尔曼滤波Q参数 */
extern CAL_SCR real32_T KHDC_Kalman_R; /* 陡坡缓降加速度卡尔曼滤波R参数 */
extern CAL_SCR int16_T KHDC_MCUMinRegenAvlTq_Nm;/* 陡坡缓降使能条件MCU能量回馈最小扭矩阈值 */
extern CAL_SCR real32_T KHDC_PID_IntegralMax;/* 陡坡缓降PID计算积分部分最大值 */
extern CAL_SCR real32_T KHDC_PID_IntegralMin;/* 陡坡缓降PID计算积分部分最小值 */
extern CAL_SCR real32_T KHDC_PID_PidMax;/* 陡坡缓降PID调节器计算总和最大值 */
extern CAL_SCR real32_T KHDC_PID_PidMin;/* 陡坡缓降PID调节器计算总和最小值 */
extern CAL_SCR uint8_T KHDC_PID_SpdDelta_Max;/* 陡坡缓降PID计算最大速度差 */
extern CAL_SCR int8_T KHDC_PID_SpdDelta_Min;/* 陡坡缓降PID计算最小速度差 */
extern CAL_SCR real32_T KHDC_SpdCon_PIDCalculateKiX_kph[7];/* HDC目标车速 */
extern CAL_SCR real32_T KHDC_SpdCon_PIDCalculateKiY_kph[9];/* 目标车速和实际车速的速度差（用于I积分），用于设定HDC目标车速 */
extern CAL_SCR real32_T KHDC_SpdCon_PIDCalculateKiZ[63];/* PID Ki，用于设定HDC目标车速 */
extern CAL_SCR real32_T KHDC_SpdCon_PIDCalculateKpX_kph[7];/* HDC目标车速 */
extern CAL_SCR real32_T KHDC_SpdCon_PIDCalculateKpY_kph[9];/* 目标车速和实际车速的速度差（用于P比例），用于设定HDC目标车速 */
extern CAL_SCR real32_T KHDC_SpdCon_PIDCalculateKpZ[63];/* PID Kp，用于设定HDC目标车速 */
extern CAL_SCR real32_T KHDC_SpdCon_PID_IntegralHoldExit_SpdDelta;/* 当实际车速和目标巡航车速的差值稳定在1kph以外，并保持指定时间5s(TBD)时，PID积分器不保持 */
extern CAL_SCR real32_T KHDC_SpdCon_PID_IntegralHold_SpdDelta;/* 当实际车速和目标巡航车速的差值稳定在1kph以内，并保持指定时间5s(TBD)时，PID积分器保持 */
extern CAL_SCR boolean_T KHDC_SpdCon_Pid_EnableFlag;/* 陡坡缓降PID调节器使能开关 */
extern CAL_SCR boolean_T KHDC_SpdCon_VehDyn_EnableFlag;/* 陡坡缓降加速度部分基础扭矩使能开关 */
extern CAL_SCR uint8_T KHDC_SpdLower_Threshold_KPH;/* 陡坡缓降退出车速下限值 */
extern CAL_SCR uint8_T KHDC_SpdOverRemind_KPH;/* 陡坡缓降受限提醒车速偏移值 */
extern CAL_SCR uint32_T KHDC_SpdOverRemind_TrueDelay;/* 陡坡缓降受限提醒激活判断时间 */
extern CAL_SCR uint32_T KHDC_SpdOverRemind_ZeroDelay;/* 陡坡缓降受限提醒恢复判断时间 */
extern CAL_SCR uint8_T KHDC_SpdUpper_Threshold_KPH;/* 陡坡缓降退出车速上限值 */
extern CAL_SCR uint32_T KHDC_SpdValidJudge_Delaytime_ms;/* 陡坡缓降车速有效性判断延迟时间 */
extern CAL_SCR uint16_T KHDC_TargeTqJudge_Delaytime_ms;/* 陡坡缓降退出扭矩正向判断时间 */
extern CAL_SCR real32_T KHDC_TargetTq_Threshold_Nm;/* 陡坡缓降退出目标扭矩阈值 */
extern CAL_SCR real32_T KHDC_TorqFlt_FirstOrderDownRatio;/* 陡坡缓降扭矩一阶滤波下升系数 */
extern CAL_SCR real32_T KHDC_TorqFlt_FirstOrderUpRatio;/* 陡坡缓降扭矩一阶滤波上升系数 */
extern CAL_SCR real32_T KHDC_TorqFlt_GradLimLowVal;/* 陡坡缓降扭矩梯度限制下降最大步长 */
extern CAL_SCR real32_T KHDC_TorqFlt_GradLimMaxVal;/* 陡坡缓降扭矩梯度限制最大值 */
extern CAL_SCR real32_T KHDC_TorqFlt_GradLimMinVal;/* 陡坡缓降扭矩梯度限制最小值 */
extern CAL_SCR real32_T KHDC_TorqFlt_GradLimUpVal;/* 陡坡缓降扭矩梯度限制上升最大步长 */
extern CAL_SCR uint8_T NONCLTC;        /* CLTC功能等速工况标志位0 */
extern CAL_SCR real32_T f4_CT_CRS_BaseTqX_kph[15];/* 定速巡航基础扭矩X轴（目标巡航车速：KPH） */
extern CAL_SCR real32_T f4_CT_CRS_BaseTqY_Nm[15];/* 定速巡航基础扭矩Y轴（巡航基础扭矩：Nm） */
extern CAL_SCR real32_T f4_CT_HDC_BaseTqX_mpss[16];/* 陡坡缓降基础扭矩计算加速度查表值 */
extern CAL_SCR real32_T f4_CT_HDC_BaseTqY_Nm[16];/* 陡坡缓降基础扭矩查表值 */
extern CAL_SCR real32_T f4_CT_NEDC_KPHMode_X[9];/* NEDC KPH模式 */
extern CAL_SCR real32_T f4_CT_NEDC_KPHVehSpdDiff_Y[4];/* KPH模式车速和松开油门踏板时的实际车速的差值 */
extern CAL_SCR real32_T f4_CT_NEDC_PidIntegralMax_Tbl[36];/* PID 积分器最大值(根据NEDC KPH模式和KPH模式车速-松开油门踏板时的实际车速) */
extern CAL_SCR real32_T f4_CT_NEDC_PidIntegralMin_Tbl[36];/* PID 积分器最小值(根据NEDC KPH模式和KPH模式车速-松开油门踏板时的实际车速) */
extern CAL_SCR real32_T f4_CT_NEDC_Pid_Ki_Array[9];/* PID Ki参数值 */
extern CAL_SCR real32_T f4_CT_NEDC_Pid_Kp_Array[9];/* PID Kp参数值 */
extern CAL_SCR uint32_T f4_C_CRS_SpdChangeRateExceptionCounterLimit;/* 车速差值在10ms采样周期内的变化率超过6m/s2的次数 */
extern CAL_SCR real32_T f4_C_CRS_SpdChangeRate_mp10ms;/* 车速差值在10ms采样周期内的变化率超过6m/s2 */
extern CAL_SCR real32_T f4_C_CRS_VehicleMass_KG;/* 整车质量给定值 */
extern CAL_SCR int8_T f4_C_NEDCExit_SpeedHyst;/* KPH35,KPH70工况的特殊情况车速偏差值 */
extern CAL_SCR uint8_T f4_C_NEDC_BrakeEn_Spd;/* NEDC减速工况最小车速,当小于该车速后，退出本次NEDC减速工况 */
extern CAL_SCR real32_T f4_C_NEDC_BrakeTorqueMax_Nm;/* NEDC最大允许输出扭矩 */
extern CAL_SCR real32_T f4_C_NEDC_BrakeTorqueMin_Nm;/* NEDC最小允许输出扭矩 */
extern CAL_SCR real32_T f4_C_NEDC_PID_SpdDelta_Max;/* PID速度差上限值 */
extern CAL_SCR real32_T f4_C_NEDC_PID_SpdDelta_Min;/* PID速度差下限值 */
extern CAL_SCR real32_T f4_C_NEDC_Pid_PidMax;/* PID 最大值 */
extern CAL_SCR real32_T f4_C_NEDC_Pid_PidMin;/* PID 最小值 */
extern CAL_SCR real32_T f4_C_NEDC_TorqFlt_FirstOrderDownRatio;/* 扭矩一阶滤波下升系数 */
extern CAL_SCR real32_T f4_C_NEDC_TorqFlt_FirstOrderUpRatio;/* 扭矩一阶滤波上升系数 */
extern CAL_SCR real32_T f4_C_NEDC_TorqFlt_GradLimDownVal;/* 扭矩梯度限制下降最大步长 */
extern CAL_SCR real32_T f4_C_NEDC_TorqFlt_GradLimSatMaxVal;/* 扭矩梯度限制最大值 */
extern CAL_SCR real32_T f4_C_NEDC_TorqFlt_GradLimSatMinVal;/* 扭矩梯度限制最小值 */
extern CAL_SCR real32_T f4_C_NEDC_TorqFlt_GradLimUpVal;/* 扭矩梯度限制上升最大步长 */
extern CAL_SCR real32_T f4_C_NEDC_VehDyn_TorqueMax;/* PID Kp参数值 */
extern CAL_SCR real32_T f4_C_NEDC_VehDyn_TorqueMin;/* PID Kp参数值 */
extern CAL_SCR int32_T f4_C_NEDC_kmph120120Acc_mps;/* KPH120减速段的目标减速度 */
extern CAL_SCR int32_T f4_C_NEDC_kmph12050Acc_mps;/* KPH50减速段的目标减速度 */
extern CAL_SCR int32_T f4_C_NEDC_kmph12080Acc_mps;/* KPH80减速段的目标减速度 */
extern CAL_SCR int32_T f4_C_NEDC_kmph15Acc_mps;/* KPH15减速段的目标减速度 */
extern CAL_SCR int32_T f4_C_NEDC_kmph32Acc_mps;/* KPH32减速段的目标减速度 */
extern CAL_SCR int32_T f4_C_NEDC_kmph35Acc_mps;/* KPH35减速段的目标减速度 */
extern CAL_SCR int32_T f4_C_NEDC_kmph50Acc_mps;/* KPH50减速段的目标减速度 */
extern CAL_SCR int32_T f4_C_NEDC_kmph70Acc_mps;/* KPH70减速段的目标减速度 */
extern CAL_SCR uint8_T u1_C_CLTC_ConstSpd_kph;/* CLTC功能等速工况目标车速 */
extern CAL_SCR uint8_T u1_C_CLTC_Constkph_hys;/* CLTC功能等速工况目标车速偏移量 */
extern CAL_SCR uint32_T u1_C_CLTC_DelayTimePlus_hys;/* CLTC功能小循环识别超出时间 */
extern CAL_SCR boolean_T u1_C_CLTC_Enable_UseCaliEna;/* CLTC功能强制控制开关 */
extern CAL_SCR boolean_T u1_C_CLTC_Enable_UseCaliVal;/* CLTC功能强制控制数值 */
extern CAL_SCR uint32_T u1_C_CLTC_FrontRearSpdDelta_ms;/* CLTC功能前后车轮差异确认持续时间 */
extern CAL_SCR uint32_T u1_C_CLTC_Kph2032_ms;/* CLTC功能小循环识别2032速度段等待时间 */
extern CAL_SCR uint32_T u1_C_CLTC_Kph3221_ms;/* CLTC功能小循环识别3221速度段等待时间 */
extern CAL_SCR uint8_T u1_C_CLTC_SOC30_pct;/* CLTC功能等速工况SOC30 */
extern CAL_SCR uint8_T u1_C_CLTC_SOC40_pct;/* CLTC功能等速工况SOC40 */
extern CAL_SCR uint8_T u1_C_CLTC_SOC50_pct;/* CLTC功能等速工况SOC50 */
extern CAL_SCR uint8_T u1_C_CLTC_SOC60_pct;/* CLTC功能等速工况SOC60 */
extern CAL_SCR uint8_T u1_C_CLTC_SOC70_pct;/* CLTC功能等速工况SOC70 */
extern CAL_SCR uint8_T u1_C_CLTC_SOC80_pct;/* CLTC功能等速工况SOC80 */
extern CAL_SCR uint16_T u1_C_CLTC_SOCHold_ms;/* CLTC功能等速工况维持目标车速的时间阈值 */
extern CAL_SCR uint8_T u1_C_CLTC_SOC_hys;/* CLTC功能等速工况SOC偏移量 */
extern CAL_SCR uint32_T u1_C_CLTC_StoMS_ms;/* CLTC功能1秒等于1000毫秒 */
extern CAL_SCR int16_T u1_C_CLTC_TargetSpd_Threshold;/* CLTC功能目标车速至0阈值 */
extern CAL_SCR uint32_T u1_C_CLTC_TyreRadius_m;/* 车轮滚动半径 */
extern CAL_SCR uint16_T u1_C_CLTC_VehSts_TrueDelay_ms;/* CLTC功能车辆状态条件确认持续时间 */
extern CAL_SCR uint16_T u1_C_CLTC_VehSts_ZeroDelay_ms;/* CLTC功能车辆状态条件失效持续时间 */
extern CAL_SCR uint32_T u1_C_CLTC_VelocityRatio;/* 减速比 */
extern CAL_SCR uint8_T u1_C_CLTC_cyclekph_hys;/* CLTC功能小循环识别各速度段偏移量 */
extern CAL_SCR uint32_T u1_C_CLTC_kph20Hold_ms;/* CLTC功能小循环识别20速度段维持时间 */
extern CAL_SCR uint8_T u1_C_CLTC_kph20spd_kph;/* CLTC功能小循环识别20速度段 */
extern CAL_SCR uint32_T u1_C_CLTC_kph21Hold_ms;/* CLTC功能小循环识别21速度段维持时间 */
extern CAL_SCR uint8_T u1_C_CLTC_kph21spd_kph;/* CLTC功能小循环识别21速度段 */
extern CAL_SCR uint32_T u1_C_CLTC_kph32aHold_ms;/* CLTC功能小循环识别32速度段维持时间 */
extern CAL_SCR uint8_T u1_C_CLTC_kph32aspd_kph;/* CLTC功能小循环识别32速度段 */
extern CAL_SCR boolean_T u1_C_Cruise_UseShortResPressSpd;/* 长按RES+按键增加目标巡航车速时是否点加目标巡航车速 */
extern CAL_SCR boolean_T u1_C_Cruise_UseShortSetPressSpd;/* 长按SET-按键增加目标巡航车速时是否点减目标巡航车速 */
extern CAL_SCR boolean_T u1_C_Cruise_VehSpdExpectionJudge_flg;/* 是否对ABS车速的异常变化进行检测 */
extern CAL_SCR boolean_T u1_C_NEDC_Enable_UseCali;/* 使用标定量来代替NEDC自动识别 */
extern CAL_SCR boolean_T u1_C_NEDC_PID_SpdDelta_UseMPC;/* 当前车速是否使用预测 */
extern CAL_SCR uint8_T u1_C_NEDC_ReleaseAccelPdl_pct;/* 松开加速踏板的开度 */
extern CAL_SCR uint8_T u1_C_NEDC_SpeedHyst_kmph;/* NEDC工况判断的允许车速偏差 */
extern CAL_SCR uint8_T u1_C_NEDC_kmph120_kmph;/* 120kph车速标志 */
extern CAL_SCR uint8_T u1_C_NEDC_kmph15_kmph;/* 15kph车速标志 */
extern CAL_SCR uint8_T u1_C_NEDC_kmph32_kmph;/* 32kph车速标志 */
extern CAL_SCR uint8_T u1_C_NEDC_kmph35_kmph;/* 35kph车速标志 */
extern CAL_SCR uint8_T u1_C_NEDC_kmph50_kmph;/* 50kph车速标志 */
extern CAL_SCR uint8_T u1_C_NEDC_kmph70_kmph;/* 70kph车速标志 */
extern CAL_SCR uint8_T u1_C_NEDC_kmph80_kmph;/* 80kph车速标志 */
extern CAL_SCR uint8_T u2_C_ClTC_FrontRearSpdDelta_KPH;/* CLTC功能前后轮车速差阈值 */
extern CAL_SCR uint16_T u2_C_NEDC_kmph120HoldTime_s;/* 判别进入NEDC工况120kph稳定车速所需的120kph最小维持时间 */
extern CAL_SCR uint16_T u2_C_NEDC_kmph15HoldTime_s;/* 判别进入NEDC工况15kph稳定车速所需的15kph最小维持时间 */
extern CAL_SCR uint16_T u2_C_NEDC_kmph32HoldTime_s;/* 判别进入NEDC工况32kph稳定车速所需的32kph最小维持时间 */
extern CAL_SCR uint16_T u2_C_NEDC_kmph35HoldTime_s;/* 判别进入NEDC工况35kph稳定车速所需35kph最小维持时间 */
extern CAL_SCR uint16_T u2_C_NEDC_kmph50HoldTime_s;/* 判别进入NEDC工况50kph稳定车速所需的50kph最小维持时间 */
extern CAL_SCR uint16_T u2_C_NEDC_kmph70HoldTime_s;/* 判别进入NEDC工况70kph稳定车速所需的70kph最小维持时间 */
extern CAL_SCR uint32_T u4_C_NEDC_DelayTimeHysMinus_ms;/* 段稳定车速之间过渡的Hys时间 */
extern CAL_SCR uint32_T u4_C_NEDC_DelayTimeHysPlus_ms;/* 段稳定车速之间过渡的Hys时间 */
extern CAL_SCR uint32_T u4_C_NEDC_Kph1532_DelayTime_ms;/* 第一段15kph稳定车速退出后到第二段稳定车速的判断时间 */
extern CAL_SCR uint32_T u4_C_NEDC_Kph3250_DelayTime_ms;/* 第二段32kph稳定车速退出后到第三段稳定车速的判断时间 */
extern CAL_SCR uint32_T u4g_KCRS_CruiseAccDec_AddSpd;/* 长按RES+按键单位采样时间内长加目标巡航车速
                                                        计算公式:dT * a_accdec
                                                        其中,dT=0.01s,a_accdec可设定为5m/s2 */
extern CAL_SCR uint32_T u4g_KCRS_CruiseAccDec_DecSpd;/* 长按SET-按键单位采样时间内长减目标巡航车速
                                                        计算公式:dT * a_accdec
                                                        其中,dT=0.01s,a_accdec可设定为5m/s2 */
extern CAL_SCR uint32_T u4g_KCRS_CruiseTipUpDown_AddSpd;/* 点按SET-/RES+按键点减或点加目标巡航车速 */
extern CAL_SCR uint32_T u4s_KCRS_CruiseSpdSteady_SpdThreshold;/* 从ResumeFromOVerride或ResumeFromCancel模式自动切换到SPDSTEADY模式时时间车速和目标车速的差值 */

#endif                                 /* RTW_HEADER_SCR_Cal_Data_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

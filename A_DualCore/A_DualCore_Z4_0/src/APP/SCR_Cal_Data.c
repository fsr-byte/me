/*
 * File: SCR_Cal_Data.c
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

#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "SCR_model_types.h"

/* Exported data definition */
#include "derivative.h"

/* Definition for custom storage class: CAL_11_SCR */
CAL_SCR uint8_T CLTC = 7U;             /* CLTC功能等速工况标志位7 */
CAL_SCR uint8_T CLTC_SOC40 = 5U;       /* CLTC功能等速工况标志位5 */
CAL_SCR uint8_T CLTC_SOC50 = 4U;       /* CLTC功能等速工况标志位4 */
CAL_SCR uint8_T CLTC_SOC60 = 3U;       /* CLTC功能等速工况标志位3 */
CAL_SCR uint8_T CLTC_SOC70 = 2U;       /* CLTC功能等速工况标志位2 */
CAL_SCR uint8_T CLTC_SOC80 = 1U;       /* CLTC功能等速工况标志位1 */
CAL_SCR uint16_T CRS_No_Evflag_TrueDelay = 80U;/* 使能加速度算法 */
CAL_SCR uint16_T KCRS_AccelPdlInvalidJudgeTime_ms = 5000U;/* 加速踏板无效判断时间 */
CAL_SCR uint16_T KCRS_BrakePdlInvalidJudgeTime_ms = 5000U;/* 制动踏板无效判断时间 */
CAL_SCR boolean_T KCRS_CRUISECtrlErr_Ena = 0;/* 定速巡航系统故障开关使能条件 */
CAL_SCR uint8_T KCRS_CRUISECtrlErr_Val = 0U;/* 定速巡航系统故障开关使能默认值 */
CAL_SCR uint32_T KCRS_CRUISECtrlErr_holdtime_ms = 10000U;/* 定速巡航硬件故障点亮故障灯延迟时间 */
CAL_SCR boolean_T KCRS_CRUISECtrlSys_Ena = 0;/* 定速巡航系统状态开关使能条件 */
CAL_SCR uint8_T KCRS_CRUISECtrlSys_Val = 0U;/* 定速巡航系统故障开关使能默认值 */
CAL_SCR boolean_T KCRS_CRUISEModStop_Ena = 0;/* 定速巡航文字提醒开关 */
CAL_SCR boolean_T KCRS_CRUISEModStop_Val = 0;/* 定速巡航文字提醒开关量 */
CAL_SCR uint32_T KCRS_CruiseMaxMinSpdJudge_delta = 2048U;/* Cruise最大允许车速的波动值 */
CAL_SCR uint32_T KCRS_CruiseMaxSpd = 133120U;/* Cruise最大允许车速 */
CAL_SCR uint32_T KCRS_CruiseMinSpd = 30720U;/* Cruise最小允许车速 */
CAL_SCR uint32_T KCRS_CruiseMinSpdNoTouchCheckTime_ms = 30000U;/* 定速巡航实际车速小于巡航车速判断时间 */
CAL_SCR uint8_T KCRS_CruiseMinSpdNoTouchJudge_delta = 7U;/* 定速巡航实际车速小于巡航车速判断车速差阈值 */
CAL_SCR boolean_T KCRS_CruiseModuleWork_Ena = 1;/* 定速巡航开启开关使能条件 */
CAL_SCR boolean_T KCRS_CruiseModuleWork_Val = 0;/* 定速巡航开启开关使能数值 */
CAL_SCR boolean_T KCRS_CruiseResumeMode_En = 1;/* 定速巡航Resume功能使能开关 */
CAL_SCR boolean_T KCRS_CruiseVehSpdMode_en = 1;/* 定速巡航输入车速模式选择开关 */
CAL_SCR uint16_T KCRS_CruiseVehSpdSatisfyCheckTime_ms = 100U;/* 实际车速满足巡航车速的持续判断时间 */
CAL_SCR uint16_T KCRS_GearInvalidJudgeTime_ms = 5000U;/* 档位无效判断时间 */
CAL_SCR uint16_T KCRS_ICMVehpdDisp_Filter = 100U;/* 定速巡航功能仪表车速滤波功能滤波系数 */
CAL_SCR boolean_T KCRS_ICMVehpdDisp_Filter_en = 1;/* 定速巡航功能仪表车速滤波功能开关 */
CAL_SCR uint16_T KCRS_KeyLongPressActiveTime_mS = 400U;/* SET/RES按键长按判断最小时间 */
CAL_SCR uint32_T KCRS_KeyResActiveTime_mS = 300U;/* 定速巡航恢复功能判断时间 */
CAL_SCR uint32_T KCRS_KeySetActiveTime_mS = 50U;/* 定速巡航设定功能判断时间 */
CAL_SCR uint16_T KCRS_KeyShortPressActiveTime_mS = 50U;/* 按键短按判断最小时间 */
CAL_SCR uint32_T KCRS_LongPressStepTime_mS = 1200U;/* 定速巡航长按车速阶跃式增加判定时间 */
CAL_SCR uint32_T KCRS_MinorCruiseFaultDelayTime_ms = 100U;/* 轻微故障恢复持续判断时间 */
CAL_SCR real32_T KCRS_PID_IntegralMax = 60.0F;/* PID积分器的最大值 */
CAL_SCR real32_T KCRS_PID_IntegralMin = -50.0F;/* 参考滑行能量回收二档的最大负扭矩值 */
CAL_SCR real32_T KCRS_PID_PidMax = 90.0F;/* PID的最大值 */
CAL_SCR real32_T KCRS_PID_PidMin = -50.0F;/* 参考滑行能量回收二档的最大负扭矩值 */
CAL_SCR real32_T KCRS_PID_SpdDelta_Max = 5.0F;/* PID速度偏差值允许最大值 */
CAL_SCR real32_T KCRS_PID_SpdDelta_Min = -5.0F;/* PID速度偏差值允许最小值 */
CAL_SCR uint16_T KCRS_PressOnOffDebounceThreshold = 40U;/* 按键按下和松开的防抖动阈值时间 */
CAL_SCR uint8_T KCRS_QuitCruise_PowerLimitPct = 50U;/* 当DHP限功率百分比小于该值时，关闭定速巡航 */
CAL_SCR uint32_T KCRS_QuitCruise_TargetVehSpdDiff_HoldTime_ms = 300000U;/* 当abs(实际车速-目标车速)大于该值，且持续一段时间时，退出定速巡航 */
CAL_SCR uint32_T KCRS_QuitCruise_TargetVehSpdDiff_kph = 30720U;/* 当abs(实际车速-目标车速)大于该值，且持续一段时间时，退出定速巡航 */
CAL_SCR uint32_T KCRS_QuitCruise_VehSpdLimit = 40U;/* 退出定速巡航功能后系统最小车速 */
CAL_SCR uint32_T KCRS_RealSpdOffUpLimit_HoldTime_ms = 30000U;/* 定速巡航实际车速超出最大车速故障判断时间 */
CAL_SCR uint8_T KCRS_RealSpdOffUpLimit_delta = 5U;/* 定速巡航实际车速超出最大车速故障车速差阈值 */
CAL_SCR real32_T KCRS_SpdCon_PIDAccDecKiX_kph[6] =
{
    20.0F, 40.0F, 60.0F, 80.0F, 100.0F, 120.0F
} ;                                    /* （长加长减车速工况）目标巡航车速 */

CAL_SCR real32_T KCRS_SpdCon_PIDAccDecKiY_kph[9] =
{
    -5.0F, -3.0F, -1.0F, -0.5F, 0.0F, 0.5F, 1.0F, 3.0F, 5.0F
} ;                                    /* （长加长减车速工况）目标巡航车速和实际车速的速度差（用于I比例），用于设定目标巡航车速 */

CAL_SCR real32_T KCRS_SpdCon_PIDAccDecKiZ[54] =
{
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.001F, 0.001F, 0.001F, 0.001F, 0.001F,
    0.001F, 0.001F, 0.001F, 0.001F, 0.001F, 0.001F, 0.001F, 0.001F, 0.001F,
    0.001F, 0.001F, 0.001F, 0.001F, 0.001F, 0.001F, 0.001F, 0.001F, 0.001F,
    0.001F, 0.001F, 0.001F, 0.001F, 0.001F, 0.001F, 0.001F, 0.001F, 0.001F,
    0.001F, 0.001F, 0.001F, 0.001F, 0.001F, 0.001F, 0.001F, 0.001F, 0.001F,
    0.001F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F
} ;                                    /* （长加长减车速工况）PID Ki，用于设定目标巡航车速 */

CAL_SCR real32_T KCRS_SpdCon_PIDAccDecKpX_kph[6] =
{
    20.0F, 40.0F, 60.0F, 80.0F, 100.0F, 120.0F
} ;                                    /* （长加长减车速工况）目标巡航车速 */

CAL_SCR real32_T KCRS_SpdCon_PIDAccDecKpY_kph[7] =
{
    -5.0F, -3.0F, -1.0F, 0.0F, 1.0F, 3.0F, 5.0F
} ;                                    /* （长加长减车速工况）目标巡航车速和实际车速的速度差（用于P比例），用于设定目标巡航车速 */

CAL_SCR real32_T KCRS_SpdCon_PIDAccDecKpZ[42] =
{
    6.0F, 6.0F, 6.0F, 6.0F, 6.0F, 6.0F, 8.0F, 8.0F, 8.0F, 8.0F, 8.0F, 8.0F, 8.0F,
    8.0F, 8.0F, 8.0F, 8.0F, 8.0F, 8.0F, 8.0F, 8.0F, 8.0F, 8.0F, 8.0F, 12.0F,
    12.0F, 12.0F, 12.0F, 12.0F, 12.0F, 12.0F, 12.0F, 12.0F, 12.0F, 12.0F, 12.0F,
    10.0F, 10.0F, 10.0F, 10.0F, 10.0F, 10.0F
} ;                                    /* （长加长减车速工况）PID Kp，用于设定目标巡航车速 */

CAL_SCR real32_T KCRS_SpdCon_PIDSetResumeKiX_kph[6] =
{
    20.0F, 40.0F, 60.0F, 80.0F, 100.0F, 120.0F
} ;                                    /* （设定恢复工况）目标巡航车速 */

CAL_SCR real32_T KCRS_SpdCon_PIDSetResumeKiY_kph[9] =
{
    -5.0F, -4.99F, -1.0F, -0.5F, 0.0F, 0.5F, 1.0F, 4.99F, 5.0F
} ;                                    /* （设定恢复工况）目标巡航车速和实际车速的速度差（用于I积分），用于设定目标巡航车速 */

CAL_SCR real32_T KCRS_SpdCon_PIDSetResumeKiZ[54] =
{
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F,
    0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F,
    0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F,
    0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F,
    0.01F, 0.01F, 0.01F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F
} ;                                    /* （设定恢复工况）PID Ki，用于设定目标巡航车速 */

CAL_SCR real32_T KCRS_SpdCon_PIDSetResumeKpX_kph[6] =
{
    20.0F, 40.0F, 60.0F, 80.0F, 100.0F, 120.0F
} ;                                    /* （设定恢复工况）目标巡航车速 */

CAL_SCR real32_T KCRS_SpdCon_PIDSetResumeKpY_kph[9] =
{
    -5.0F, -3.0F, -1.0F, -0.5F, 0.0F, 0.5F, 1.0F, 3.0F, 5.0F
} ;                                    /* （设定恢复工况）目标巡航车速和实际车速的速度差（用于P比例），用于设定目标巡航车速 */

CAL_SCR real32_T KCRS_SpdCon_PIDSetResumeKpZ[54] =
{
    15.0F, 15.0F, 15.0F, 15.0F, 15.0F, 15.0F, 14.0F, 14.0F, 14.0F, 14.0F, 14.0F,
    14.0F, 10.0F, 10.0F, 10.0F, 10.0F, 10.0F, 10.0F, 5.0F, 5.0F, 5.0F, 5.0F,
    5.0F, 5.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F,
    5.0F, 10.0F, 10.0F, 10.0F, 10.0F, 10.0F, 10.0F, 14.0F, 14.0F, 14.0F, 14.0F,
    14.0F, 14.0F, 15.0F, 15.0F, 15.0F, 15.0F, 15.0F, 15.0F
} ;                                    /* （设定恢复工况）PID Kp，用于设定目标巡航车速 */

CAL_SCR real32_T KCRS_SpdCon_PIDTipUpDownKiX_kph[5] =
{
    20.0F, 40.0F, 70.0F, 100.0F, 120.0F
} ;                                    /* （点加点减车速工况）目标巡航车速 */

CAL_SCR real32_T KCRS_SpdCon_PIDTipUpDownKiY_kph[9] =
{
    -4.0F, -3.0F, -2.0F, -1.0F, 0.0F, 1.0F, 2.0F, 3.0F, 4.0F
} ;                                    /* （点加点减车速工况）目标巡航车速和实际车速的速度差（用于I比例），用于设定目标巡航车速 */

CAL_SCR real32_T KCRS_SpdCon_PIDTipUpDownKiZ[45] =
{
    0.025F, 0.025F, 0.05F, 0.075F, 0.1F, 0.033F, 0.033F, 0.067F, 0.1F, 0.133F,
    0.05F, 0.05F, 0.1F, 0.15F, 0.2F, 0.1F, 0.1F, 0.2F, 0.3F, 0.4F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.1F, 0.1F, 0.2F, 0.3F, 0.4F, 0.05F, 0.05F, 0.1F, 0.15F,
    0.2F, 0.033F, 0.033F, 0.067F, 0.1F, 0.133F, 0.025F, 0.025F, 0.05F, 0.075F,
    0.1F
} ;                                    /* （点加点减车速工况）PID Ki，用于设定目标巡航车速 */

CAL_SCR real32_T KCRS_SpdCon_PIDTipUpDownKpX_kph[6] =
{
    20.0F, 40.0F, 60.0F, 80.0F, 100.0F, 120.0F
} ;                                    /* （点加点减车速工况）目标巡航车速 */

CAL_SCR real32_T KCRS_SpdCon_PIDTipUpDownKpY_kph[7] =
{
    -5.0F, -3.0F, -1.0F, 0.0F, 1.0F, 3.0F, 5.0F
} ;                                    /* （点加点减车速工况）目标巡航车速和实际车速的速度差（用于P比例），用于设定目标巡航车速 */

CAL_SCR real32_T KCRS_SpdCon_PIDTipUpDownKpZ[42] =
{
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F
} ;                                    /* （点加点减车速工况）PID Kp，用于设定目标巡航车速 */

CAL_SCR real32_T KCRS_SpdCon_PID_IntegralHoldExit_SpdDelta = 0.3F;/* 当实际车速和目标巡航车速的差值稳定在1kph以内，并保持指定时间5s(TBD)时，PID积分器保持 */
CAL_SCR uint16_T KCRS_SpdCon_PID_IntegralHoldExit_SpdDelta_Time_ms = 1000U;/* 当实际车速和目标巡航车速的差值稳定在1kph以内，并保持指定时间5s(TBD)时，PID积分器保持 */
CAL_SCR real32_T KCRS_SpdCon_PID_IntegralHold_SpdDelta = 0.3F;/* 当实际车速和目标巡航车速的差值稳定在1kph以内，并保持指定时间5s(TBD)时，PID积分器保持 */
CAL_SCR uint16_T KCRS_SpdCon_PID_IntegralHold_SpdDelta_Time_ms = 5000U;/* 当实际车速和目标巡航车速的差值稳定在1kph以内，并保持指定时间5s(TBD)时，PID积分器保持 */
CAL_SCR boolean_T KCRS_SpdCon_Pid_EnableFlag = 1;/* 使能PID */
CAL_SCR boolean_T KCRS_SpdCon_VehDyn_EnableFlag = 0;/* 使能车辆纵向动力学模型 */
CAL_SCR uint16_T KCRS_TargetVehSpdDiff_DelayTime_ms = 5000U;/* 定速巡航能力受限导致车速异常退出巡航状态文字提醒时间 */
CAL_SCR real32_T KCRS_TorqFlt_FirstOrderDownRatio = 0.8F;/* 定速巡航扭矩一阶滤波参数(下降段) */
CAL_SCR real32_T KCRS_TorqFlt_FirstOrderUpRatio = 0.8F;/* 定速巡航扭矩一阶滤波参数(上升段) */
CAL_SCR real32_T KCRS_TorqFlt_GradLimLowVal = -2.0F;/* 加速度的最大jerk通过该值来限制
                                                       该值的计算方法如下：以最大加速度jerk为-1.5m/s3，采样时间为0.02s，使用纵向动力学公式中的加速阻力来计算：
                                                       1575*-1.5*0.02*1.05*0.3234/7.93/0.973=-3.46 */
CAL_SCR real32_T KCRS_TorqFlt_GradLimMaxVal = 121.0F;/* 梯度限制后的最大允许输出正扭矩
                                                        该值的计算方法如下：以最大加速度为1.75m/s使用纵向动力学公式中的加速阻力来计算：
                                                        1575*1.75*1.05*0.3234/7.93/0.973=121 */
CAL_SCR real32_T KCRS_TorqFlt_GradLimMinVal = -50.0F;/* 参考滑行能量回收二档的最大负扭矩值 */
CAL_SCR real32_T KCRS_TorqFlt_GradLimUpVal = 2.0F;/* 加速度的最大jerk通过该值来限制
                                                     该值的计算方法如下：以最大加速度jerk为1.5m/s3，采样时间为0.02s，使用纵向动力学公式中的加速阻力来计算：
                                                     1575*1.5*0.02*1.05*0.3234/7.93/0.973=3.46 */
CAL_SCR real32_T KCRS_VehDyn_TorqueMax = 80.0F;/* 车辆纵向动力学的最大允许输出正扭矩 */
CAL_SCR real32_T KCRS_VehDyn_TorqueMin = -80.0F;/* 车辆纵向动力学的最小允许输出正扭矩 */
CAL_SCR uint32_T KCRS_VehSpdCheckDelayTime_period = 250U;/* 对于ABS车速变化异常进行检测周期 */
CAL_SCR uint16_T KCRS_VehSpdInvalidJudgeTime_ms = 3000U;/* 车速无效判断时间 */
CAL_SCR uint8_T KCRS_t_CRUISECtrlSysDelayTime_ms = 60U;/* 定速巡航Run模式退出确认时间 */
CAL_SCR uint16_T KCRS_t_CancelPress_ms = 60U;/* 定速巡航Cancel动作判断：N挡下行程拨动停滞时间 */
CAL_SCR uint32_T KCRS_t_CruiseRun_ms = 60U;/* 定速巡航怀挡开关设定功能判断时间 */
CAL_SCR uint32_T KHDC_ABSSpeedSatisfy_Delaytime_ms = 100U;/* 陡坡缓降使能条件车速满足确认时间 */
CAL_SCR uint32_T KHDC_AccSpdThreshold_Delaytime1_ms = 500U;/* 陡坡缓降使能加速度满足持续判断时间1 */
CAL_SCR uint32_T KHDC_AccSpdThreshold_Delaytime2_ms = 300U;/* 陡坡缓降使能加速度满足持续判断时间2 */
CAL_SCR uint32_T KHDC_AccSpdThreshold_Delaytime3_ms = 150U;/* 陡坡缓降使能加速度满足持续判断时间3 */
CAL_SCR uint8_T KHDC_AccSpd_Filter = 50U;/* 陡坡缓降加速度一阶滤波因子 */
CAL_SCR int32_T KHDC_AccSpd_Threshold1_mpss = 307;/* 陡坡缓降使能加速度阈值1 */
CAL_SCR int32_T KHDC_AccSpd_Threshold2_mpss = 410;/* 陡坡缓降使能加速度阈值2 */
CAL_SCR int32_T KHDC_AccSpd_Threshold3_mpss = 512;/* 陡坡缓降使能加速度阈值3 */
CAL_SCR uint32_T KHDC_AcceMode_Delaytime_ms = 50U;/* 陡坡缓降使能条件驱动扭矩判断时间 */
CAL_SCR boolean_T KHDC_C_HDC_En = 1;   /* 陡坡缓降配置使能 */
CAL_SCR real32_T KHDC_CreepGearDSpd_Threshold_KPH = 6.0F;/* 陡坡缓降退出条件蠕行D挡限制车速阈值 */
CAL_SCR real32_T KHDC_CreepGearRSpd_Threshold_KPH = 4.0F;/* 陡坡缓降退出条件蠕行R挡限制车速阈值 */
CAL_SCR uint8_T KHDC_DHPLimitSpd_Threshold_Nm = 8U;/* 陡坡缓降使能诊断模块限制车速最小阈值 */
CAL_SCR uint8_T KHDC_GearDSpdLower_KPH = 8U;/* 陡坡缓降使能条件D挡车速下限 */
CAL_SCR uint8_T KHDC_GearDSpdUpper_KPH = 20U;/* 陡坡缓降使能条件D挡车速上限 */
CAL_SCR real32_T KHDC_GearD_AcceMode_Threshold_Nm = 1.0F;/* 陡坡缓降使能条件D驱动挡扭矩判断阈值 */
CAL_SCR int16_T KHDC_GearD_VehTq_Threshold_Nm = -10;/* 陡坡缓降踩制动退出时D挡扭矩下限 */
CAL_SCR uint8_T KHDC_GearRSpdLower_KPH = 6U;/* 陡坡缓降使能条件R挡车速下限 */
CAL_SCR uint8_T KHDC_GearRSpdUpper_KPH = 20U;/* 陡坡缓降使能条件R挡车速上限 */
CAL_SCR real32_T KHDC_GearR_AcceMode_Threshold_Nm = -1.0F;/* 陡坡缓降使能条件R挡驱动扭矩判断阈值 */
CAL_SCR int16_T KHDC_GearR_VehTq_Threshold_Nm = 10;/* 陡坡缓降踩制动退出时R挡扭矩上限 */
CAL_SCR boolean_T KHDC_HDCrun_Ena = 0; /* 陡坡缓降使能开关 */
CAL_SCR boolean_T KHDC_HDCrun_Val = 0; /* 陡坡缓降使能数值 */
CAL_SCR real32_T KHDC_Kalman_P = 10.0F;/* 陡坡缓降加速度卡尔曼滤波P参数 */
CAL_SCR real32_T KHDC_Kalman_Q = 0.1F; /* 陡坡缓降加速度卡尔曼滤波Q参数 */
CAL_SCR real32_T KHDC_Kalman_R = 1.0F; /* 陡坡缓降加速度卡尔曼滤波R参数 */
CAL_SCR int16_T KHDC_MCUMinRegenAvlTq_Nm = -5;/* 陡坡缓降使能条件MCU能量回馈最小扭矩阈值 */
CAL_SCR real32_T KHDC_PID_IntegralMax = 50.0F;/* 陡坡缓降PID计算积分部分最大值 */
CAL_SCR real32_T KHDC_PID_IntegralMin = -30.0F;/* 陡坡缓降PID计算积分部分最小值 */
CAL_SCR real32_T KHDC_PID_PidMax = 100.0F;/* 陡坡缓降PID调节器计算总和最大值 */
CAL_SCR real32_T KHDC_PID_PidMin = -100.0F;/* 陡坡缓降PID调节器计算总和最小值 */
CAL_SCR uint8_T KHDC_PID_SpdDelta_Max = 5U;/* 陡坡缓降PID计算最大速度差 */
CAL_SCR int8_T KHDC_PID_SpdDelta_Min = -5;/* 陡坡缓降PID计算最小速度差 */
CAL_SCR real32_T KHDC_SpdCon_PIDCalculateKiX_kph[7] =
{
    5.0F, 10.0F, 15.0F, 20.0F, 25.0F, 30.0F, 35.0F
} ;                                    /* HDC目标车速 */

CAL_SCR real32_T KHDC_SpdCon_PIDCalculateKiY_kph[9] =
{
    -5.0F, -4.99F, -1.0F, -0.5F, 0.0F, 0.5F, 1.0F, 4.99F, 5.0F
} ;                                    /* 目标车速和实际车速的速度差（用于I积分），用于设定HDC目标车速 */

CAL_SCR real32_T KHDC_SpdCon_PIDCalculateKiZ[63] =
{
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F,
    0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F,
    0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F,
    0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F,
    0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F
} ;                                    /* PID Ki，用于设定HDC目标车速 */

CAL_SCR real32_T KHDC_SpdCon_PIDCalculateKpX_kph[7] =
{
    5.0F, 10.0F, 15.0F, 20.0F, 25.0F, 30.0F, 35.0F
} ;                                    /* HDC目标车速 */

CAL_SCR real32_T KHDC_SpdCon_PIDCalculateKpY_kph[9] =
{
    -5.0F, -3.0F, -1.5F, -1.0F, 0.0F, 1.0F, 1.5F, 3.0F, 5.0F
} ;                                    /* 目标车速和实际车速的速度差（用于P比例），用于设定HDC目标车速 */

CAL_SCR real32_T KHDC_SpdCon_PIDCalculateKpZ[63] =
{
    15.0F, 15.0F, 15.0F, 15.0F, 15.0F, 15.0F, 15.0F, 14.0F, 14.0F, 14.0F, 14.0F,
    14.0F, 14.0F, 14.0F, 10.0F, 10.0F, 10.0F, 10.0F, 10.0F, 10.0F, 10.0F, 5.0F,
    5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F,
    5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 10.0F, 10.0F, 10.0F, 10.0F, 10.0F,
    10.0F, 10.0F, 14.0F, 14.0F, 14.0F, 14.0F, 14.0F, 14.0F, 14.0F, 15.0F, 15.0F,
    15.0F, 15.0F, 15.0F, 15.0F, 15.0F
} ;                                    /* PID Kp，用于设定HDC目标车速 */

CAL_SCR real32_T KHDC_SpdCon_PID_IntegralHoldExit_SpdDelta = 0.4F;/* 当实际车速和目标巡航车速的差值稳定在1kph以外，并保持指定时间5s(TBD)时，PID积分器不保持 */
CAL_SCR real32_T KHDC_SpdCon_PID_IntegralHold_SpdDelta = 0.3F;/* 当实际车速和目标巡航车速的差值稳定在1kph以内，并保持指定时间5s(TBD)时，PID积分器保持 */
CAL_SCR boolean_T KHDC_SpdCon_Pid_EnableFlag = 1;/* 陡坡缓降PID调节器使能开关 */
CAL_SCR boolean_T KHDC_SpdCon_VehDyn_EnableFlag = 0;/* 陡坡缓降加速度部分基础扭矩使能开关 */
CAL_SCR uint8_T KHDC_SpdLower_Threshold_KPH = 4U;/* 陡坡缓降退出车速下限值 */
CAL_SCR uint8_T KHDC_SpdOverRemind_KPH = 2U;/* 陡坡缓降受限提醒车速偏移值 */
CAL_SCR uint32_T KHDC_SpdOverRemind_TrueDelay = 100U;/* 陡坡缓降受限提醒激活判断时间 */
CAL_SCR uint32_T KHDC_SpdOverRemind_ZeroDelay = 500U;/* 陡坡缓降受限提醒恢复判断时间 */
CAL_SCR uint8_T KHDC_SpdUpper_Threshold_KPH = 35U;/* 陡坡缓降退出车速上限值 */
CAL_SCR uint32_T KHDC_SpdValidJudge_Delaytime_ms = 100U;/* 陡坡缓降车速有效性判断延迟时间 */
CAL_SCR uint16_T KHDC_TargeTqJudge_Delaytime_ms = 100U;/* 陡坡缓降退出扭矩正向判断时间 */
CAL_SCR real32_T KHDC_TargetTq_Threshold_Nm = 0.01F;/* 陡坡缓降退出目标扭矩阈值 */
CAL_SCR real32_T KHDC_TorqFlt_FirstOrderDownRatio = 1.0F;/* 陡坡缓降扭矩一阶滤波下升系数 */
CAL_SCR real32_T KHDC_TorqFlt_FirstOrderUpRatio = 1.0F;/* 陡坡缓降扭矩一阶滤波上升系数 */
CAL_SCR real32_T KHDC_TorqFlt_GradLimLowVal = -20.0F;/* 陡坡缓降扭矩梯度限制下降最大步长 */
CAL_SCR real32_T KHDC_TorqFlt_GradLimMaxVal = 0.0F;/* 陡坡缓降扭矩梯度限制最大值 */
CAL_SCR real32_T KHDC_TorqFlt_GradLimMinVal = -120.0F;/* 陡坡缓降扭矩梯度限制最小值 */
CAL_SCR real32_T KHDC_TorqFlt_GradLimUpVal = 20.0F;/* 陡坡缓降扭矩梯度限制上升最大步长 */
CAL_SCR uint8_T NONCLTC = 0U;          /* CLTC功能等速工况标志位0 */
CAL_SCR real32_T f4_CT_CRS_BaseTqX_kph[15] =
{
    5.0F, 10.0F, 20.0F, 30.0F, 40.0F, 50.0F, 60.0F, 70.0F, 80.0F, 90.0F, 100.0F,
    110.0F, 120.0F, 130.0F, 140.0F
} ;                                    /* 定速巡航基础扭矩X轴（目标巡航车速：KPH） */

CAL_SCR real32_T f4_CT_CRS_BaseTqY_Nm[15] =
{
    5.4F, 5.5F, 6.0F, 7.0F, 8.0F, 10.0F, 12.0F, 14.0F, 17.0F, 20.0F, 23.0F,
    27.0F, 31.0F, 36.0F, 41.0F
} ;                                    /* 定速巡航基础扭矩Y轴（巡航基础扭矩：Nm） */

CAL_SCR real32_T f4_CT_HDC_BaseTqX_mpss[16] =
{
    0.5F, 0.6F, 0.7F, 0.8F, 0.9F, 1.0F, 1.1F, 1.2F, 1.3F, 1.4F, 1.5F, 1.6F, 1.7F,
    1.8F, 1.9F, 2.0F
} ;                                    /* 陡坡缓降基础扭矩计算加速度查表值 */

CAL_SCR real32_T f4_CT_HDC_BaseTqY_Nm[16] =
{
    -10.0F, -12.0F, -14.0F, -16.0F, -18.0F, -20.0F, -22.0F, -24.0F, -26.0F,
    -28.0F, -30.0F, -32.0F, -34.0F, -36.0F, -38.0F, -40.0F
} ;                                    /* 陡坡缓降基础扭矩查表值 */

CAL_SCR real32_T f4_CT_NEDC_KPHMode_X[9] =
{
    0.0F, 1.0F, 2.0F, 3.0F, 4.0F, 5.0F, 6.0F, 7.0F, 8.0F
} ;                                    /* NEDC KPH模式 */

CAL_SCR real32_T f4_CT_NEDC_KPHVehSpdDiff_Y[4] =
{
    0.0F, 1.0F, 2.0F, 3.0F
} ;                                    /* KPH模式车速和松开油门踏板时的实际车速的差值 */

CAL_SCR real32_T f4_CT_NEDC_PidIntegralMax_Tbl[36] =
{
    0.0F, 16.0F, 20.0F, 25.0F, 22.0F, 25.0F, 25.0F, 25.0F, 25.0F, 0.0F, 16.0F,
    20.0F, 25.0F, 22.0F, 25.0F, 25.0F, 25.0F, 25.0F, 0.0F, 16.0F, 20.0F, 25.0F,
    22.0F, 25.0F, 25.0F, 25.0F, 25.0F, 0.0F, 16.0F, 20.0F, 25.0F, 22.0F, 25.0F,
    25.0F, 25.0F, 25.0F
} ;                                    /* PID 积分器最大值(根据NEDC KPH模式和KPH模式车速-松开油门踏板时的实际车速) */

CAL_SCR real32_T f4_CT_NEDC_PidIntegralMin_Tbl[36] =
{
    0.0F, -10.0F, -15.0F, -25.0F, -20.0F, -25.0F, -25.0F, -25.0F, -25.0F, 0.0F,
    -10.0F, -15.0F, -25.0F, -20.0F, -25.0F, -25.0F, -25.0F, -25.0F, 0.0F, -10.0F,
    -15.0F, -25.0F, -20.0F, -25.0F, -25.0F, -25.0F, -25.0F, 0.0F, -10.0F, -15.0F,
    -25.0F, -20.0F, -25.0F, -25.0F, -25.0F, -25.0F
} ;                                    /* PID 积分器最小值(根据NEDC KPH模式和KPH模式车速-松开油门踏板时的实际车速) */

CAL_SCR real32_T f4_CT_NEDC_Pid_Ki_Array[9] =
{
    0.0F, 0.8F, 0.8F, 0.8F, 0.8F, 0.8F, 0.8F, 0.8F, 0.8F
} ;                                    /* PID Ki参数值 */

CAL_SCR real32_T f4_CT_NEDC_Pid_Kp_Array[9] =
{
    0.0F, 15.0F, 15.0F, 15.0F, 15.0F, 15.0F, 15.0F, 15.0F, 15.0F
} ;                                    /* PID Kp参数值 */

CAL_SCR uint32_T f4_C_CRS_SpdChangeRateExceptionCounterLimit = 20U;/* 车速差值在10ms采样周期内的变化率超过6m/s2的次数 */
CAL_SCR real32_T f4_C_CRS_SpdChangeRate_mp10ms = 0.06F;/* 车速差值在10ms采样周期内的变化率超过6m/s2 */
CAL_SCR real32_T f4_C_CRS_VehicleMass_KG = 1650.0F;/* 整车质量给定值 */
CAL_SCR int8_T f4_C_NEDCExit_SpeedHyst = 3;/* KPH35,KPH70工况的特殊情况车速偏差值 */
CAL_SCR uint8_T f4_C_NEDC_BrakeEn_Spd = 1U;/* NEDC减速工况最小车速,当小于该车速后，退出本次NEDC减速工况 */
CAL_SCR real32_T f4_C_NEDC_BrakeTorqueMax_Nm = 0.0F;/* NEDC最大允许输出扭矩 */
CAL_SCR real32_T f4_C_NEDC_BrakeTorqueMin_Nm = -100.0F;/* NEDC最小允许输出扭矩 */
CAL_SCR real32_T f4_C_NEDC_PID_SpdDelta_Max = 3.0F;/* PID速度差上限值 */
CAL_SCR real32_T f4_C_NEDC_PID_SpdDelta_Min = -3.0F;/* PID速度差下限值 */
CAL_SCR real32_T f4_C_NEDC_Pid_PidMax = 50.0F;/* PID 最大值 */
CAL_SCR real32_T f4_C_NEDC_Pid_PidMin = -50.0F;/* PID 最小值 */
CAL_SCR real32_T f4_C_NEDC_TorqFlt_FirstOrderDownRatio = 1.0F;/* 扭矩一阶滤波下升系数 */
CAL_SCR real32_T f4_C_NEDC_TorqFlt_FirstOrderUpRatio = 1.0F;/* 扭矩一阶滤波上升系数 */
CAL_SCR real32_T f4_C_NEDC_TorqFlt_GradLimDownVal = -20.0F;/* 扭矩梯度限制下降最大步长 */
CAL_SCR real32_T f4_C_NEDC_TorqFlt_GradLimSatMaxVal = 120.0F;/* 扭矩梯度限制最大值 */
CAL_SCR real32_T f4_C_NEDC_TorqFlt_GradLimSatMinVal = -120.0F;/* 扭矩梯度限制最小值 */
CAL_SCR real32_T f4_C_NEDC_TorqFlt_GradLimUpVal = 20.0F;/* 扭矩梯度限制上升最大步长 */
CAL_SCR real32_T f4_C_NEDC_VehDyn_TorqueMax = 60.0F;/* PID Kp参数值 */
CAL_SCR real32_T f4_C_NEDC_VehDyn_TorqueMin = -60.0F;/* PID Kp参数值 */
CAL_SCR int32_T f4_C_NEDC_kmph120120Acc_mps = -707;/* KPH120减速段的目标减速度 */
CAL_SCR int32_T f4_C_NEDC_kmph12050Acc_mps = -1423;/* KPH50减速段的目标减速度 */
CAL_SCR int32_T f4_C_NEDC_kmph12080Acc_mps = -1065;/* KPH80减速段的目标减速度 */
CAL_SCR int32_T f4_C_NEDC_kmph15Acc_mps = -850;/* KPH15减速段的目标减速度 */
CAL_SCR int32_T f4_C_NEDC_kmph32Acc_mps = -829;/* KPH32减速段的目标减速度 */
CAL_SCR int32_T f4_C_NEDC_kmph35Acc_mps = -993;/* KPH35减速段的目标减速度 */
CAL_SCR int32_T f4_C_NEDC_kmph50Acc_mps = -532;/* KPH50减速段的目标减速度 */
CAL_SCR int32_T f4_C_NEDC_kmph70Acc_mps = -707;/* KPH70减速段的目标减速度 */
CAL_SCR uint8_T u1_C_CLTC_ConstSpd_kph = 100U;/* CLTC功能等速工况目标车速 */
CAL_SCR uint8_T u1_C_CLTC_Constkph_hys = 5U;/* CLTC功能等速工况目标车速偏移量 */
CAL_SCR uint32_T u1_C_CLTC_DelayTimePlus_hys = 3000U;/* CLTC功能小循环识别超出时间 */
CAL_SCR boolean_T u1_C_CLTC_Enable_UseCaliEna = 0;/* CLTC功能强制控制开关 */
CAL_SCR boolean_T u1_C_CLTC_Enable_UseCaliVal = 0;/* CLTC功能强制控制数值 */
CAL_SCR uint32_T u1_C_CLTC_FrontRearSpdDelta_ms = 30000U;/* CLTC功能前后车轮差异确认持续时间 */
CAL_SCR uint32_T u1_C_CLTC_Kph2032_ms = 10000U;/* CLTC功能小循环识别2032速度段等待时间 */
CAL_SCR uint32_T u1_C_CLTC_Kph3221_ms = 30000U;/* CLTC功能小循环识别3221速度段等待时间 */
CAL_SCR uint8_T u1_C_CLTC_SOC30_pct = 30U;/* CLTC功能等速工况SOC30 */
CAL_SCR uint8_T u1_C_CLTC_SOC40_pct = 40U;/* CLTC功能等速工况SOC40 */
CAL_SCR uint8_T u1_C_CLTC_SOC50_pct = 50U;/* CLTC功能等速工况SOC50 */
CAL_SCR uint8_T u1_C_CLTC_SOC60_pct = 60U;/* CLTC功能等速工况SOC60 */
CAL_SCR uint8_T u1_C_CLTC_SOC70_pct = 70U;/* CLTC功能等速工况SOC70 */
CAL_SCR uint8_T u1_C_CLTC_SOC80_pct = 80U;/* CLTC功能等速工况SOC80 */
CAL_SCR uint16_T u1_C_CLTC_SOCHold_ms = 5000U;/* CLTC功能等速工况维持目标车速的时间阈值 */
CAL_SCR uint8_T u1_C_CLTC_SOC_hys = 2U;/* CLTC功能等速工况SOC偏移量 */
CAL_SCR uint32_T u1_C_CLTC_StoMS_ms = 1000U;/* CLTC功能1秒等于1000毫秒 */
CAL_SCR int16_T u1_C_CLTC_TargetSpd_Threshold = 26;/* CLTC功能目标车速至0阈值 */
CAL_SCR uint32_T u1_C_CLTC_TyreRadius_m = 21194U;/* 车轮滚动半径 */
CAL_SCR uint16_T u1_C_CLTC_VehSts_TrueDelay_ms = 500U;/* CLTC功能车辆状态条件确认持续时间 */
CAL_SCR uint16_T u1_C_CLTC_VehSts_ZeroDelay_ms = 500U;/* CLTC功能车辆状态条件失效持续时间 */
CAL_SCR uint32_T u1_C_CLTC_VelocityRatio = 519674U;/* 减速比 */
CAL_SCR uint8_T u1_C_CLTC_cyclekph_hys = 2U;/* CLTC功能小循环识别各速度段偏移量 */
CAL_SCR uint32_T u1_C_CLTC_kph20Hold_ms = 3000U;/* CLTC功能小循环识别20速度段维持时间 */
CAL_SCR uint8_T u1_C_CLTC_kph20spd_kph = 20U;/* CLTC功能小循环识别20速度段 */
CAL_SCR uint32_T u1_C_CLTC_kph21Hold_ms = 3000U;/* CLTC功能小循环识别21速度段维持时间 */
CAL_SCR uint8_T u1_C_CLTC_kph21spd_kph = 21U;/* CLTC功能小循环识别21速度段 */
CAL_SCR uint32_T u1_C_CLTC_kph32aHold_ms = 3000U;/* CLTC功能小循环识别32速度段维持时间 */
CAL_SCR uint8_T u1_C_CLTC_kph32aspd_kph = 32U;/* CLTC功能小循环识别32速度段 */
CAL_SCR boolean_T u1_C_Cruise_UseShortResPressSpd = 1;/* 长按RES+按键增加目标巡航车速时是否点加目标巡航车速 */
CAL_SCR boolean_T u1_C_Cruise_UseShortSetPressSpd = 1;/* 长按SET-按键增加目标巡航车速时是否点减目标巡航车速 */
CAL_SCR boolean_T u1_C_Cruise_VehSpdExpectionJudge_flg = 0;/* 是否对ABS车速的异常变化进行检测 */
CAL_SCR boolean_T u1_C_NEDC_Enable_UseCali = 0;/* 使用标定量来代替NEDC自动识别 */
CAL_SCR boolean_T u1_C_NEDC_PID_SpdDelta_UseMPC = 0;/* 当前车速是否使用预测 */
CAL_SCR uint8_T u1_C_NEDC_ReleaseAccelPdl_pct = 3U;/* 松开加速踏板的开度 */
CAL_SCR uint8_T u1_C_NEDC_SpeedHyst_kmph = 3U;/* NEDC工况判断的允许车速偏差 */
CAL_SCR uint8_T u1_C_NEDC_kmph120_kmph = 120U;/* 120kph车速标志 */
CAL_SCR uint8_T u1_C_NEDC_kmph15_kmph = 15U;/* 15kph车速标志 */
CAL_SCR uint8_T u1_C_NEDC_kmph32_kmph = 32U;/* 32kph车速标志 */
CAL_SCR uint8_T u1_C_NEDC_kmph35_kmph = 35U;/* 35kph车速标志 */
CAL_SCR uint8_T u1_C_NEDC_kmph50_kmph = 50U;/* 50kph车速标志 */
CAL_SCR uint8_T u1_C_NEDC_kmph70_kmph = 70U;/* 70kph车速标志 */
CAL_SCR uint8_T u1_C_NEDC_kmph80_kmph = 80U;/* 80kph车速标志 */
CAL_SCR uint8_T u2_C_ClTC_FrontRearSpdDelta_KPH = 90U;/* CLTC功能前后轮车速差阈值 */
CAL_SCR uint16_T u2_C_NEDC_kmph120HoldTime_s = 3000U;/* 判别进入NEDC工况120kph稳定车速所需的120kph最小维持时间 */
CAL_SCR uint16_T u2_C_NEDC_kmph15HoldTime_s = 3000U;/* 判别进入NEDC工况15kph稳定车速所需的15kph最小维持时间 */
CAL_SCR uint16_T u2_C_NEDC_kmph32HoldTime_s = 3000U;/* 判别进入NEDC工况32kph稳定车速所需的32kph最小维持时间 */
CAL_SCR uint16_T u2_C_NEDC_kmph35HoldTime_s = 3000U;/* 判别进入NEDC工况35kph稳定车速所需35kph最小维持时间 */
CAL_SCR uint16_T u2_C_NEDC_kmph50HoldTime_s = 3000U;/* 判别进入NEDC工况50kph稳定车速所需的50kph最小维持时间 */
CAL_SCR uint16_T u2_C_NEDC_kmph70HoldTime_s = 3000U;/* 判别进入NEDC工况70kph稳定车速所需的70kph最小维持时间 */
CAL_SCR uint32_T u4_C_NEDC_DelayTimeHysMinus_ms = 2000U;/* 段稳定车速之间过渡的Hys时间 */
CAL_SCR uint32_T u4_C_NEDC_DelayTimeHysPlus_ms = 2000U;/* 段稳定车速之间过渡的Hys时间 */
CAL_SCR uint32_T u4_C_NEDC_Kph1532_DelayTime_ms = 46000U;/* 第一段15kph稳定车速退出后到第二段稳定车速的判断时间 */
CAL_SCR uint32_T u4_C_NEDC_Kph3250_DelayTime_ms = 82000U;/* 第二段32kph稳定车速退出后到第三段稳定车速的判断时间 */
CAL_SCR uint32_T u4g_KCRS_CruiseAccDec_AddSpd = 41U;/* 长按RES+按键单位采样时间内长加目标巡航车速
                                                       计算公式:dT * a_accdec
                                                       其中,dT=0.01s,a_accdec可设定为5m/s2 */
CAL_SCR uint32_T u4g_KCRS_CruiseAccDec_DecSpd = 41U;/* 长按SET-按键单位采样时间内长减目标巡航车速
                                                       计算公式:dT * a_accdec
                                                       其中,dT=0.01s,a_accdec可设定为5m/s2 */
CAL_SCR uint32_T u4g_KCRS_CruiseTipUpDown_AddSpd = 2048U;/* 点按SET-/RES+按键点减或点加目标巡航车速 */
CAL_SCR uint32_T u4s_KCRS_CruiseSpdSteady_SpdThreshold = 1024U;/* 从ResumeFromOVerride或ResumeFromCancel模式自动切换到SPDSTEADY模式时时间车速和目标车速的差值 */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

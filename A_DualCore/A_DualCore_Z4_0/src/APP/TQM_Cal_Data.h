/*
 * File: TQM_Cal_Data.h
 *
 * Code generated for Simulink model 'TQM_model'.
 *
 * Model version                  : 1.3587
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Fri Mar 18 15:45:56 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Freescale->32-bit PowerPC
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. MISRA C:2012 guidelines
 * Validation result: Not run
 */

#ifndef RTW_HEADER_TQM_Cal_Data_h_
#define RTW_HEADER_TQM_Cal_Data_h_
#include "rtwtypes.h"
#include "TQM_model_types.h"

/* Exported data declaration */
#include "derivative.h"

/* Declaration for custom storage class: CAL_9_TQM */
extern CAL_TQM real32_T ABS_FR_DeltaCurveHalfAxle;/* 左右轮轮速差 */
extern CAL_TQM boolean_T ABS_WheelSpd_Enable;/* 是否通过ABS的轮速算车速 */
extern CAL_TQM real32_T ABS_vWhlRL_Revise;/* 通过前一轮的车速来推测本轮车速时的修正量 */
extern CAL_TQM uint16_T ASM_EPB_AntiSlide_Timer;/* MCU防切换EPB防坡度判断延迟counter */
extern CAL_TQM int16_T ASM_EPB_Applied_DelayTime;/* 判断EPB夹驻超时counter，超出则停止夹驻请求。 */
extern CAL_TQM boolean_T ASM_EPB_BrakeSta_En;/* EPB防溜坡进入条件踩制动进入使能标识 */
extern CAL_TQM uint16_T ASM_En_AntiSlide_Spd_Delay;/* EPB防溜车速有效性判断时间 */
extern CAL_TQM int8_T ASM_GearD_Over_Tq;/* D挡，需求扭矩大于防溜坡扭矩超过该值才认为需求扭矩确实大于防溜坡扭矩 */
extern CAL_TQM uint16_T ASM_GearD_Tq_Upper_Delay;/* 需求扭矩大于防溜扭矩的持续时间大于该值则退出防溜功能（D挡） */
extern CAL_TQM int8_T ASM_GearR_Over_Tq;/* R挡，需求扭矩（绝对值）大于防溜坡扭矩（绝对值）超过该值才认为需求扭矩大于防溜坡扭矩 */
extern CAL_TQM uint16_T ASM_GearR_Tq_Upper_Delay;/* 需求扭矩大于防溜扭矩的持续时间大于该值则退出防溜功能（R挡） */
extern CAL_TQM int16_T ASM_MCUAntiSlide_AvTq_Max;/* 允许MCU输出的最大防溜坡扭矩 */
extern CAL_TQM int16_T ASM_MCUAntiSlide_AvTq_Min;/* 允许MCU输出的最小防溜坡扭矩 */
extern CAL_TQM boolean_T ASM_MCUAntiSlide_Ena;/* 转速环防溜坡使能开关 */
extern CAL_TQM boolean_T ASM_MCUAntiSlide_Val;/* 转速环防溜坡使能值 */
extern CAL_TQM int16_T ASM_MCU_GearDAntiSlide_Spd_En;/* D档MCU防溜坡期静止判断转速 */
extern CAL_TQM int8_T ASM_MCU_GearD_Lower_RoadAngle;/* D档防溜坡进入坡度条件的下限值 */
extern CAL_TQM int16_T ASM_MCU_GearRAntiSlide_Spd_En;/* R档MCU防溜坡期静止判断转速 */
extern CAL_TQM int8_T ASM_MCU_GearR_Upper_RoadAngle;/* R档防溜坡进入坡度条件的上限值 */
extern CAL_TQM uint16_T ASM_MCU_QuitApplied_DelayTime;/* EPB防溜坡MCU使能等待周期counter */
extern CAL_TQM uint16_T ASM_S11_AntiSlideEnter_DrivePower;/* 可用放电功率大于该值允许开启防溜坡功能 */
extern CAL_TQM int32_T ASM_S11_AntiSlideEnter_RoadAngle;/* 电机转速小于该值认为车辆处于静止状态（用于坡度判断） */
extern CAL_TQM uint16_T ASM_S11_AntiSlideQuit_DrivePower;/* S11防溜坡功能模式判断坡度值 */
extern CAL_TQM uint32_T ASM_S11_AntiSlide_ConfirmTime;/* 未踩制动时，防溜坡持续时间大于该值则退出防溜坡功能 */
extern CAL_TQM int16_T ASM_S11_AntiSlide_ForwardSpd_Uena;/* 电机转速大于该值认为车辆处于快速行驶状态，此时要求退出防溜坡 */
extern CAL_TQM int16_T ASM_S11_AntiSlide_ReverseSpd_Uena;/* 电机转速小于该值认为车辆处于快速后溜状态，此时要求退出防溜坡 */
extern CAL_TQM int16_T ASM_S11_AntiSlide_Spd_Static;/* 电机转速小于该值认为车辆处于静止状态（D挡） */
extern CAL_TQM boolean_T ASM_S11_AveMotSpdFilter_En;/* 防溜坡车速判断模块车速滤波使能标志 */
extern CAL_TQM uint16_T ASM_S11_EPBConfirm_TrueDelay;/* MCU防溜坡期间EPB夹驻延时判断时间 */
extern CAL_TQM int16_T ASM_S11_EPB_AntiSlide_ForwardSpd;/* EPB防溜进入条件：前进车速阀值 */
extern CAL_TQM int16_T ASM_S11_EPB_AntiSlide_ReverseSpd;/* EPB防溜进入条件：后退车速阀值 */
extern CAL_TQM uint16_T ASM_S11_GearD_Delay;/* 停留在D挡的持续时间大于该值才允许进入防溜坡功能（D挡） */
extern CAL_TQM uint16_T ASM_S11_GearD_Spd_Slide_Delay;/* 车辆进入缓慢后溜状态的持续时间大于该值则认为车辆确实处于缓慢后溜状态（D挡） */
extern CAL_TQM int16_T ASM_S11_GearD_Spd_Slide_Hig;/* 电机转速小于该值认为车辆处于缓慢后溜状态（D挡） */
extern CAL_TQM int16_T ASM_S11_GearD_Spd_Slide_Low;/* 电机转速大于该值认为车辆处于缓慢后溜状态（D挡） */
extern CAL_TQM uint16_T ASM_S11_GearR_Delay;/* 停留在R挡的持续时间大于该值才允许进入防溜坡功能（R挡） */
extern CAL_TQM uint16_T ASM_S11_GearR_Spd_Slide_Delay;/* 车辆进入缓慢后溜状态的持续时间大于该值则认为车辆确实处于缓慢后溜状态（R挡） */
extern CAL_TQM int16_T ASM_S11_GearR_Spd_Slide_Hig;/* 电机转速小于该值认为车辆处于缓慢后溜状态（R挡） */
extern CAL_TQM int16_T ASM_S11_GearR_Spd_Slide_Low;/* 电机转速大于该值认为车辆处于缓慢后溜状态（R挡） */
extern CAL_TQM uint16_T ASM_S11_MCU_Spd_Static_TrueDelay;/* 车辆判别为静止状态的最小持续静止时间 */
extern CAL_TQM uint16_T ASM_S11_MCU_Spd_Static_ZeroDelay;/* 车辆判别为非静止状态的最小持续静止时间 */
extern CAL_TQM uint16_T ASM_S11_StaticConfirm_TrueDelay;/* 用于判断车辆稳定静止的持续时间-用于防溜坡时的角度判断 */
extern CAL_TQM uint16_T ASM_Uena_AntiSlide_Spd_Delay;/* 防溜坡车速超出时间延时 */
extern CAL_TQM uint16_T BLC_ChrgConnectConfirm_Delay;/* 充电连接信号连接确认（充电时不响应EPB的点亮制动灯请求） */
extern CAL_TQM uint16_T BLC_ChrgConnectQuit_Delay;/* 充电连接信号断开确认（充电时不响应EPB的点亮制动灯请求） */
extern CAL_TQM uint8_T BLC_EPBConfirmSpd_Cal;/* EPB拉起时点亮制动灯的车速下限 */
extern CAL_TQM uint8_T BLC_EPBQuitSpd_Cal;/* EPB拉起时熄灭制动灯的车速上限 */
extern CAL_TQM int16_T BLC_GearD_LampOff_Tq;/* D挡能量回馈熄灭制动灯的回馈扭矩阈值 */
extern CAL_TQM int16_T BLC_GearD_LampOn_Tq;/* D挡能量回馈点亮制动灯的回馈扭矩阈值 */
extern CAL_TQM int16_T BLC_GearR_LampOff_Tq;/* R挡能量回馈熄灭制动灯的回馈扭矩阈值 */
extern CAL_TQM int16_T BLC_GearR_LampOn_Tq;/* R挡能量回馈点亮制动灯的回馈扭矩阈值 */
extern CAL_TQM boolean_T Cal_AccePctMode_flg;/* 手动挡车型离合器半联动加速踏板模式选择开关 */
extern CAL_TQM uint16_T Cal_ClutchSysEnable_TrueDelay;/* 手动挡车型离合器使能确认时间 */
extern CAL_TQM uint16_T Cal_ClutchSysEnable_ZeroDelay;/* 手动挡车型离合器释放确认时间 */
extern CAL_TQM real32_T Cal_Clutchlinkage_Threshold;/* 手动挡车型离合器半联动加速踏板深度阈值 */
extern CAL_TQM int16_T Cal_Creep_GearD_VehSpeed;/* D档蠕行目标车速 */
extern CAL_TQM int16_T Cal_Creep_GearR_VehSpeed;/* R档蠕行目标车速 */
extern CAL_TQM boolean_T Cal_Ready_En; /* 手动挡车型离合器档位控制READY开关 */
extern CAL_TQM boolean_T Cal_Ready_Val;/* 手动挡车型离合器档位控制READY数值 */
extern CAL_TQM boolean_T Cal_RegenGrade_Ena;/* 滑行回馈等级强制控制开关 */
extern CAL_TQM uint8_T Cal_RegenGrade_Val;/* 滑行回馈等级强制控制赋值 */
extern CAL_TQM uint8_T Cal_pedalCoefficient;/* 手动挡车型离合器半联动加速踏板深度分段增加段数 */
extern CAL_TQM int16_T CreepD_Spd_Forward_limit_Off;/* D档蠕行正向退出车速 */
extern CAL_TQM int16_T CreepD_Spd_Forward_limit_On;/* D档蠕行正向进入车速 */
extern CAL_TQM int16_T CreepD_Spd_Reverse_limit;/* D档蠕行逆向进入车速 */
extern CAL_TQM int16_T CreepR_Spd_Forward_limit;/* R档蠕行正向进入车速 */
extern CAL_TQM int16_T CreepR_Spd_Reserve_limit_Off;/* R档蠕行逆向退出车速 */
extern CAL_TQM int16_T CreepR_Spd_Reserve_limit_On;/* R档蠕行逆向进入车速 */
extern CAL_TQM uint16_T Creep_Ki_GearD[17];/* D挡蠕行Ki查表-Ki */
extern CAL_TQM uint16_T Creep_Ki_GearR[17];/* R挡蠕行Ki查表-Ki */
extern CAL_TQM uint16_T Creep_Kp_GearD[17];/* D挡蠕行Kp查表-Kp */
extern CAL_TQM uint16_T Creep_Kp_GearR[17];/* R挡蠕行Kp查表-Kp */
extern CAL_TQM int16_T CrpVehSpd_DV[17];/* R/D挡蠕行Kp/Ki查表-车速差 */
extern CAL_TQM uint16_T DTD_GearD_Brake_CloseToGear_MotSpd_Ena;/* D挡靠齿功能开启转速（踩制动） */
extern CAL_TQM uint16_T DTD_GearD_Brake_CloseToGear_MotSpd_Uena;/* D挡靠齿功能关闭转速（踩制动） */
extern CAL_TQM int8_T DTD_GearD_Brake_CloseToGear_Tq;/* D挡靠齿扭矩（踩制动）（map更改为单值） */
extern CAL_TQM boolean_T DTD_GearD_CloseToGear_Ena;/* D挡靠齿功能开关 */
extern CAL_TQM uint16_T DTD_GearD_CloseToGear_MotSpd_Ena;/* D挡靠齿功能开启转速（未踩制动） */
extern CAL_TQM uint16_T DTD_GearD_CloseToGear_MotSpd_Uena;/* D挡靠齿功能关闭转速（未踩制动） */
extern CAL_TQM int8_T DTD_GearD_CloseToGear_Tq;/* D挡靠齿扭矩（未踩制动）（map更改为单值） */
extern CAL_TQM uint16_T DTD_GearR_Brake_CloseToGear_MotSpd_Ena;/* R挡靠齿功能开启转速（踩制动） */
extern CAL_TQM uint16_T DTD_GearR_Brake_CloseToGear_MotSpd_Uena;/* R挡靠齿功能关闭转速（踩制动） */
extern CAL_TQM int8_T DTD_GearR_Brake_CloseToGear_Tq;/* R挡靠齿扭矩（踩制动）（map更改为单值） */
extern CAL_TQM boolean_T DTD_GearR_CloseToGear_Ena;/* R挡靠齿功能开关 */
extern CAL_TQM uint16_T DTD_GearR_CloseToGear_MotSpd_Ena;/* R挡靠齿功能开启转速（未踩制动） */
extern CAL_TQM uint16_T DTD_GearR_CloseToGear_MotSpd_Uena;/* R挡靠齿功能关闭转速（未踩制动） */
extern CAL_TQM int8_T DTD_GearR_CloseToGear_Tq;/* R挡靠齿扭矩（未踩制动）（map更改为单值） */
extern CAL_TQM uint16_T ECM_EPB_Acceleration_X_Filter;
extern CAL_TQM uint16_T ECM_SAS_SteeringAngleSpeed_Filter;
extern CAL_TQM uint16_T ECM_SAS_SteeringAngle_Filter;
extern CAL_TQM uint8_T ENUM_MCUMODE_SpdCtl;/* 电机转速环控制标志 */
extern CAL_TQM uint8_T ENUM_MCUMODE_TRQCTL;/* 电机扭矩环控制标志 */
extern CAL_TQM uint8_T ENUM_TMMODE_MOTOR;/* 电机放电模式标志 */
extern CAL_TQM uint8_T ENUM_TMMODE_REGEN;/* 电机发电模式标志 */
extern CAL_TQM uint8_T ENUM_TQF_DEC;   /* 扭矩下降标志 */
extern CAL_TQM uint8_T ENUM_TQF_INC;   /* 扭矩上升标志 */
extern CAL_TQM uint8_T ENUM_TQF_STEADY;/* 扭矩稳定标志 */
extern CAL_TQM uint16_T EPB_Delay_time;/* EPB夹驻请求有效性判断时间 */
extern CAL_TQM uint8_T FDT_ClutchEnRegen_Spd_Off;/* 手动挡车型离合器拖拽功能使能车速关闭阈值 */
extern CAL_TQM uint8_T FDT_ClutchEnRegen_Spd_On;/* 手动挡车型离合器拖拽功能使能车速开启阈值 */
extern CAL_TQM uint8_T FDT_Crp_PID_SteadyConst;/* 蠕行PID计算中的稳态常量 */
extern CAL_TQM int8_T FDT_GearD_BrakeRegenTq_Offset;/* R挡制动回收扭矩偏移量 */
extern CAL_TQM int16_T FDT_GearD_Crp_Tqlim_Low;/* D挡蠕行的最小输出扭矩 */
extern CAL_TQM int16_T FDT_GearD_Crp_Tqlim_Up;/* D挡蠕行的最大输出扭矩 */
extern CAL_TQM int8_T FDT_GearR_BrakeRegenTq_Offset;/* D挡制动回收扭矩偏移量 */
extern CAL_TQM int16_T FDT_GearR_Crp_Tqlim_Low;/* R挡蠕行的最小输出扭矩 */
extern CAL_TQM int16_T FDT_GearR_Crp_Tqlim_Up;/* R挡蠕行的最大输出扭矩 */
extern CAL_TQM uint8_T FDT_Regen_Spd_Off;/* 能量回收关闭对应的车速上限 */
extern CAL_TQM uint8_T FDT_Regen_Spd_On;/* 能量回收开启对应的车速下限 */
extern CAL_TQM uint8_T Forward;        /* 电机正转标志 */
extern CAL_TQM uint8_T GTC_GearTouch_Direction_Ena;/* 靠齿方向使能开关 */
extern CAL_TQM uint8_T GTC_GearTouch_Direction_Val;/* 靠齿方向使能值 */
extern CAL_TQM boolean_T GTC_GearTouch_Ena;/* 扭矩靠齿功能使能开关 */
extern CAL_TQM uint8_T GTC_GearTouch_EnaSpd_Hig;/* 小于该车速允许执行靠齿 */
extern CAL_TQM uint8_T GTC_GearTouch_EnaSpd_Low;/* 大于该车速允许执行靠齿 */
extern CAL_TQM uint16_T GTC_GearTouch_NtoP_Timer1;/* 第一段靠齿扭矩持续时间——需求扭矩由负变正 */
extern CAL_TQM uint16_T GTC_GearTouch_NtoP_Timer2;/* 前两段靠齿扭矩持续时间之和——需求扭矩由负变正 */
extern CAL_TQM uint16_T GTC_GearTouch_NtoP_Timer3;/* 前三段靠齿扭矩持续时间之和——需求扭矩由负变正 */
extern CAL_TQM uint16_T GTC_GearTouch_NtoP_Timer4;/* 前四段靠齿扭矩持续时间之和——需求扭矩由负变正 */
extern CAL_TQM real32_T GTC_GearTouch_NtoP_Tq1;/* 过零靠齿扭矩第一段——需求扭矩由负变正 */
extern CAL_TQM real32_T GTC_GearTouch_NtoP_Tq2;/* 过零靠齿扭矩第二段——需求扭矩由负变正 */
extern CAL_TQM real32_T GTC_GearTouch_NtoP_Tq3;/* 过零靠齿扭矩第三段——需求扭矩由负变正 */
extern CAL_TQM real32_T GTC_GearTouch_NtoP_Tq4;/* 过零靠齿扭矩第四段——需求扭矩由负变正 */
extern CAL_TQM uint16_T GTC_GearTouch_PtoN_Timer1;/* 第一段靠齿扭矩持续时间——需求扭矩由正变负 */
extern CAL_TQM uint16_T GTC_GearTouch_PtoN_Timer2;/* 前两段靠齿扭矩持续时间之和——需求扭矩由正变负 */
extern CAL_TQM uint16_T GTC_GearTouch_PtoN_Timer3;/* 前三段靠齿扭矩持续时间之和——需求扭矩由正变负 */
extern CAL_TQM uint16_T GTC_GearTouch_PtoN_Timer4;/* 前四段靠齿扭矩持续时间之和——需求扭矩由正变负 */
extern CAL_TQM real32_T GTC_GearTouch_PtoN_Tq1;/* 过零靠齿扭矩第一段——需求扭矩由正变负 */
extern CAL_TQM real32_T GTC_GearTouch_PtoN_Tq2;/* 过零靠齿扭矩第二段——需求扭矩由正变负 */
extern CAL_TQM real32_T GTC_GearTouch_PtoN_Tq3;/* 过零靠齿扭矩第三段——需求扭矩由正变负 */
extern CAL_TQM real32_T GTC_GearTouch_PtoN_Tq4;/* 过零靠齿扭矩第四段——需求扭矩由正变负 */
extern CAL_TQM uint8_T GTC_GearTouch_UnEnaSpd_Hig;/* 大于该车速禁止靠齿 */
extern CAL_TQM uint8_T GTC_GearTouch_UnEnaSpd_Low;/* 小于该车速禁止靠齿 */
extern CAL_TQM real32_T GTC_ZeroAcross_Tq;/* 扭矩过零判断阈值 */
extern CAL_TQM uint8_T GearD;          /* D档 */
extern CAL_TQM uint8_T GearD_Release;  /* N下半行程 */
extern CAL_TQM uint8_T GearR_Release;  /* N上半行程 */
extern CAL_TQM uint8_T Gear_D;         /* D挡标志 */
extern CAL_TQM uint8_T Gear_D1;        /* 手动挡车型D1挡 */
extern CAL_TQM uint8_T Gear_D2;        /* 手动挡车型D2挡 */
extern CAL_TQM uint8_T Gear_D3;        /* 手动挡车型D3挡 */
extern CAL_TQM uint8_T Gear_D4;        /* 手动挡车型D4挡 */
extern CAL_TQM uint8_T Gear_D5;        /* 手动挡车型D5挡 */
extern CAL_TQM uint8_T Gear_N;         /* N挡标志 */
extern CAL_TQM uint8_T Gear_P;         /* P挡标志 */
extern CAL_TQM uint8_T Gear_R;         /* R挡标志 */
extern CAL_TQM uint32_T Gravitational_Accel;/* 重力加速度 */
extern CAL_TQM int16_T KNEDC_AccDeltaLower_mps;
extern CAL_TQM int16_T KNEDC_AccDeltaUpper_mps;
extern CAL_TQM uint8_T KNEDC_BRAKETYPE_KMPH120120;
extern CAL_TQM uint8_T KNEDC_BRAKETYPE_KMPH12050;
extern CAL_TQM uint8_T KNEDC_BRAKETYPE_KMPH12080;
extern CAL_TQM uint8_T KNEDC_BRAKETYPE_KMPH15;
extern CAL_TQM uint8_T KNEDC_BRAKETYPE_KMPH32;
extern CAL_TQM uint8_T KNEDC_BRAKETYPE_KMPH35;
extern CAL_TQM uint8_T KNEDC_BRAKETYPE_KMPH50;
extern CAL_TQM uint8_T KNEDC_BRAKETYPE_KMPH70;
extern CAL_TQM int16_T KNEDC_BrakeTorqueILower_Nm;
extern CAL_TQM int16_T KNEDC_BrakeTorqueIReset_Nm;
extern CAL_TQM int16_T KNEDC_BrakeTorqueIStep_Nm;
extern CAL_TQM int16_T KNEDC_BrakeTorqueIUpper_Nm;
extern CAL_TQM uint8_T KNEDC_SpeedHyst_kmph;/* NEDC工况判断的允许车速偏差 */
extern CAL_TQM int16_T KNEDC_kmph120120Acc_mps;
extern CAL_TQM int16_T KNEDC_kmph12050Acc_mps;
extern CAL_TQM int16_T KNEDC_kmph12080Acc_mps;
extern CAL_TQM uint16_T KNEDC_kmph120HoldTime_s;/* 判别进入NEDC工况120kph稳定车速所需的120kph最小维持时间 */
extern CAL_TQM uint8_T KNEDC_kmph120_kmph;/* 120kph车速标志 */
extern CAL_TQM int16_T KNEDC_kmph15Acc_mps;
extern CAL_TQM uint16_T KNEDC_kmph15HoldTime_s;/* 判别进入NEDC工况15kph稳定车速所需的15kph最小维持时间 */
extern CAL_TQM uint8_T KNEDC_kmph15_kmph;/* 15kph车速标志 */
extern CAL_TQM int16_T KNEDC_kmph32Acc_mps;
extern CAL_TQM uint16_T KNEDC_kmph32HoldTime_s;/* 判别进入NEDC工况32kph稳定车速所需的32kph最小维持时间 */
extern CAL_TQM uint8_T KNEDC_kmph32_kmph;/* 32kph车速标志 */
extern CAL_TQM int16_T KNEDC_kmph35Acc_mps;
extern CAL_TQM uint16_T KNEDC_kmph35HoldTime_s;/* 判别进入NEDC工况35kph稳定车速所需35kph最小维持时间 */
extern CAL_TQM uint8_T KNEDC_kmph35_kmph;/* 35kph车速标志 */
extern CAL_TQM int16_T KNEDC_kmph50Acc_mps;
extern CAL_TQM uint16_T KNEDC_kmph50HoldTime_s;/* 判别进入NEDC工况50kph稳定车速所需的50kph最小维持时间 */
extern CAL_TQM uint8_T KNEDC_kmph50_kmph;/* 50kph车速标志 */
extern CAL_TQM int16_T KNEDC_kmph70Acc_mps;
extern CAL_TQM uint16_T KNEDC_kmph70HoldTime_s;/* 判别进入NEDC工况70kph稳定车速所需的70kph最小维持时间 */
extern CAL_TQM uint8_T KNEDC_kmph70_kmph;/* 70kph车速标志 */
extern CAL_TQM uint8_T KNEDC_kmph80_kmph;/* 80kph车速标志 */
extern CAL_TQM boolean_T KTQD_NEDCBakeEn_flg;/* NEDC工况使能 */
extern CAL_TQM uint16_T KTQD_NEDCBrakeMotorSpeedMin_rpm;/* NEDC能量回收功能进入的转速下限 */
extern CAL_TQM uint16_T KTQF_GearPN_Rate_Nmps;/* P/N挡扭矩卸载斜率限制 */
extern CAL_TQM uint16_T KTQF_RTDefaultDEC_Nmps;/* 扭矩下降默认斜率——扭矩处于稳态 */
extern CAL_TQM uint16_T KTQF_RTDefaultINC_Nmps;/* 扭矩上升默认斜率——扭矩处于稳态 */
extern CAL_TQM int8_T KTQF_TMDecRatStepFactor;/* 扭矩下降斜率调整因子 */
extern CAL_TQM uint8_T KTQF_TMDecRatStepFilterFactor;/* 扭矩下降斜率滤波因子 */
extern CAL_TQM int8_T KTQF_TMIncRatStepFactor;/* 扭矩上升斜率调整因子 */
extern CAL_TQM uint8_T KTQF_TMIncRatStepFilterFactor;/* 扭矩上升斜率滤波因子 */
extern CAL_TQM uint16_T KTQF_TqClunkRateLimitDec_Nmps;/* 扭矩过零点下降斜率限制 */
extern CAL_TQM uint16_T KTQF_TqClunkRateLimitInc_Nmps;/* 扭矩过零点上升斜率限制 */
extern CAL_TQM uint8_T KTQF_TqClunkThresholdDecHigh_Nm;/* 扭矩下降过零点判别上限值 */
extern CAL_TQM int8_T KTQF_TqClunkThresholdDecLow_Nm;/* 扭矩下降过零点判别下限值 */
extern CAL_TQM uint8_T KTQF_TqClunkThresholdIncHigh_Nm;/* 扭矩上升过零点判别上限值 */
extern CAL_TQM int8_T KTQF_TqClunkThresholdIncLow_Nm;/* 扭矩上升过零点判别下限值 */
extern CAL_TQM int32_T KTQF_TqPrecisionLimit_Nm;/* 用于判断扭矩上升、稳定下降状态的最小扭矩增量 */
extern CAL_TQM uint16_T MAM_K11_MCUAntiSlidePowerEna_rpm;/* K11可用放电功率大于该值则可开启防溜坡功能 */
extern CAL_TQM uint16_T MAM_K11_MCUAntiSlidePowerForbid_rpm;/* K11可用放电功率大于该值则退出防溜坡功能 */
extern CAL_TQM int16_T MAM_K11_MCUAntiSlideSpdEna_rpm;/* K11防溜坡功能开启转速 */
extern CAL_TQM int16_T MAM_K11_MCUAntiSlideSpdForbid_rpm;/* K11防溜坡功能退出转速 */
extern CAL_TQM uint16_T MAS_DisAntishake_Delay;/* MCU防抖功能关闭延时 */
extern CAL_TQM uint16_T MAS_EnaAntishake_Delay;/* MCU防抖功能开启延时 */
extern CAL_TQM uint16_T MNEDC_kmph120120Brake_X_kmph[15];/* NEDC工况120kph回馈扭矩map-车速 */
extern CAL_TQM int16_T MNEDC_kmph120120Brake_Z_Nm[15];/* NEDC工况120kph回馈扭矩map-扭矩 */
extern CAL_TQM uint16_T MNEDC_kmph15Brake_X_kmph[15];/* NEDC工况15kph回馈扭矩map-车速 */
extern CAL_TQM int16_T MNEDC_kmph15Brake_Z_Nm[15];/* NEDC工况15kph回馈扭矩map-扭矩 */
extern CAL_TQM uint16_T MNEDC_kmph32Brake_X_kmph[15];/* NEDC工况32kph回馈扭矩map-车速 */
extern CAL_TQM int16_T MNEDC_kmph32Brake_Z_Nm[15];/* NEDC工况32kph回馈扭矩map-扭矩 */
extern CAL_TQM uint16_T MNEDC_kmph35Brake_X_kmph[15];/* NEDC工况35kph回馈扭矩map-车速 */
extern CAL_TQM int16_T MNEDC_kmph35Brake_Z_Nm[15];/* NEDC工况35kph回馈扭矩map-扭矩 */
extern CAL_TQM uint16_T MNEDC_kmph50Brake_X_kmph[15];/* NEDC工况50kph回馈扭矩map-车速 */
extern CAL_TQM int16_T MNEDC_kmph50Brake_Z_Nm[15];/* NEDC工况50kph回馈扭矩map-扭矩 */
extern CAL_TQM uint16_T MNEDC_kmph70Brake_X_kmph[15];/* NEDC工况70kph回馈扭矩map-车速 */
extern CAL_TQM int16_T MNEDC_kmph70Brake_Z_Nm[15];/* NEDC工况70kph回馈扭矩map-扭矩 */
extern CAL_TQM int16_T MTQD_GearD_BrakeRegen_Zero_Tq[19];/* D挡制动能量回收扭矩map-扭矩（零挡回收） */
extern CAL_TQM int16_T MTQD_GearD_CoastRegen_First_Tq[19];/* D挡滑行能量回收扭矩map-扭矩（一挡回收） */
extern CAL_TQM int16_T MTQD_GearD_CoastRegen_Fourth_Tq[19];/* D挡滑行能量回收扭矩map-扭矩（四挡回收） */
extern CAL_TQM int16_T MTQD_GearD_CoastRegen_Second_Tq[19];/* D挡滑行能量回收扭矩map-扭矩（二挡回收） */
extern CAL_TQM uint16_T MTQD_GearD_CoastRegen_Spd[19];/* D挡滑行能量回收扭矩map-转速 */
extern CAL_TQM int16_T MTQD_GearD_CoastRegen_Third_Tq[19];/* D挡滑行能量回收扭矩map-扭矩（三挡回收） */
extern CAL_TQM int16_T MTQD_GearR_BrakeRegen_Zero_Tq[19];/* R挡制动能量回收扭矩map-扭矩（零挡回收） */
extern CAL_TQM int16_T MTQD_GearR_CoastRegen_First_Tq[19];/* R挡滑行能量回收扭矩map-扭矩（一挡回收） */
extern CAL_TQM int16_T MTQD_GearR_CoastRegen_Fourth_Tq[19];/* R挡滑行能量回收扭矩map-扭矩（四挡回收） */
extern CAL_TQM int16_T MTQD_GearR_CoastRegen_Second_Tq[19];/* R挡滑行能量回收扭矩map-扭矩（二挡回收） */
extern CAL_TQM uint16_T MTQD_GearR_CoastRegen_Spd[19];/* R挡滑行能量回收扭矩map-转速 */
extern CAL_TQM int16_T MTQD_GearR_CoastRegen_Third_Tq[19];/* R挡滑行能量回收扭矩map-扭矩（三挡回收） */
extern CAL_TQM uint16_T MTQD_PedalMapAccpedal_ClutchMode_pct[16];/* 手动挡车型D挡峰值扭矩百分比amp-加速踏板开度 */
extern CAL_TQM uint16_T MTQD_PedalMapBoostAccpedal_Eco_pct[16];/* Normal模式D挡峰值扭矩百分比amp-加速踏板开度 */
extern CAL_TQM uint16_T MTQD_PedalMapBoostAccpedal_X_pct[16];/* Sport模式D挡峰值扭矩百分比amp-加速踏板开度 */
extern CAL_TQM uint16_T MTQD_PedalMapBoostTmSpeed_Eco_rpm[12];/* Normal模式D挡峰值扭矩百分比amp-转速 */
extern CAL_TQM uint16_T MTQD_PedalMapBoostTmSpeed_Y_rpm[12];/* Sport模式D挡峰值扭矩百分比amp-转速 */
extern CAL_TQM uint16_T MTQD_PedalMapBoost_Eco_pct[192];/* Normal模式D挡峰值扭矩百分比amp-百分比 */
extern CAL_TQM uint16_T MTQD_PedalMapBoost_pct[192];/* Sport模式D挡峰值扭矩百分比amp-百分比 */
extern CAL_TQM uint16_T MTQD_PedalMapClutchMode_Fifth_pct[192];/* 手动挡车型D5挡扭矩百分比amp-百分比 */
extern CAL_TQM uint16_T MTQD_PedalMapClutchMode_First_pct[192];/* 手动挡车型D1挡扭矩百分比amp-百分比 */
extern CAL_TQM uint16_T MTQD_PedalMapClutchMode_Fourth_pct[192];/* 手动挡车型D4挡扭矩百分比amp-百分比 */
extern CAL_TQM uint16_T MTQD_PedalMapClutchMode_Second_pct[192];/* 手动挡车型D2挡扭矩百分比amp-百分比 */
extern CAL_TQM uint16_T MTQD_PedalMapClutchMode_Third_pct[192];/* 手动挡车型D3挡扭矩百分比amp-百分比 */
extern CAL_TQM uint16_T MTQD_PedalMapRevAccpedal_ClutchMode_pct[16];/* 手动挡车型R挡峰值扭矩百分比amp-加速踏板开度 */
extern CAL_TQM uint16_T MTQD_PedalMapRevAccpedal_X_pct[16];/* R挡峰值扭矩百分比amp-加速踏板开度 */
extern CAL_TQM uint16_T MTQD_PedalMapRevTmSpeed_ClutchMode_rpm[12];/* 手动挡车型R挡峰值扭矩百分比amp-转速 */
extern CAL_TQM uint16_T MTQD_PedalMapRevTmSpeed_Y_rpm[12];/* R挡峰值扭矩百分比amp-转速 */
extern CAL_TQM uint16_T MTQD_PedalMapRev_ClutchMode_pct[192];/* 手动挡车型R挡扭矩百分比amp-百分比 */
extern CAL_TQM uint16_T MTQD_PedalMapRev_pct[192];/* R挡峰值扭矩百分比amp-百分比 */
extern CAL_TQM uint16_T MTQD_PedalMapTmSpeed_ClutchMode_rpm[12];/* 手动挡车型D挡峰值扭矩百分比amp-转速 */
extern CAL_TQM uint16_T MTQD_TqMapPeakTmSpeed_X_rpm[22];/* 电机外特性map-转速 */
extern CAL_TQM int16_T MTQD_TqMapPeakTq_Nm[22];/* 电机外特性map-扭矩 */
extern CAL_TQM uint16_T MTQD_TqMapRevTmSpeed_X_rpm[22];/* R挡峰值扭矩map-转速 */
extern CAL_TQM int16_T MTQD_TqMapRevTq_Nm[22];/* R挡峰值扭矩map-扭矩 */
extern CAL_TQM uint16_T PTT_MotDriveEffi_Pct[182];/* 驱动系统放电效率map-效率 */
extern CAL_TQM uint16_T PTT_MotDriveEffi_Power[14];/* 驱动系统放电效率map-功率 */
extern CAL_TQM uint16_T PTT_MotDriveEffi_Spd[13];/* 驱动系统放电效率map-转速 */
extern CAL_TQM uint16_T PTT_MotRegenEffi_Pct[182];/* 驱动系统发电效率map-效率 */
extern CAL_TQM uint16_T PTT_MotRegenEffi_Power[14];/* 驱动系统发电效率map-功率 */
extern CAL_TQM uint16_T PTT_MotRegenEffi_Spd[13];/* 驱动系统发电效率map-转速 */
extern CAL_TQM uint16_T P_Delay_time;  /* 进P档等待EPB夹驻时间 */
extern CAL_TQM uint8_T Period;         /* 模型运行时间-ms */
extern CAL_TQM uint16_T REC_No_Evflag_TrueDelay;/* 禁止能量回收标志持续时间判断-持续时间大于该值才认为有效（新增） */
extern CAL_TQM uint8_T REC_RegenEnaAccePct_Cal;/* 加速踏板开度大于该值时复位能量回收标志 */
extern CAL_TQM uint8_T REC_RegenEnaSpd_Cal;/* 车速低于该值时复位能量回收标志 */
extern CAL_TQM uint16_T RampExecTime;  /* 斜率限制部分周期时间 */
extern CAL_TQM uint8_T Reverse;        /* 电机反转标志 */
extern CAL_TQM uint8_T SpeedAccelBuffer;
extern CAL_TQM uint8_T SpeedAccel_Alpha;
extern CAL_TQM uint8_T Sport_Mode;     /* 运动模式标志 */
extern CAL_TQM uint8_T Standstill;     /* 电机静止标志 */
extern CAL_TQM boolean_T TQD_FALSE;
extern CAL_TQM boolean_T TQD_TRUE;
extern CAL_TQM int8_T TQD_integral_reset_value;/* i部分扭矩计算重置值 */
extern CAL_TQM int16_T TQD_max_dmd;    /* i部分计算上限扭矩 */
extern CAL_TQM int16_T TQD_min_dmd;    /* i部分计算下限扭矩 */
extern CAL_TQM uint16_T TQF_DriveDecDistance_Filter1;/* 斜率1 */
extern CAL_TQM uint16_T TQF_DriveDecDistance_Filter2;/* 斜率2 */
extern CAL_TQM uint16_T TQF_DriveDecDistance_Filter3;/* 斜率3 */
extern CAL_TQM uint16_T TQF_DriveDecDistance_Filter4;/* 斜率4 */
extern CAL_TQM uint16_T TQF_DriveDecDistance_Filter5;/* 斜率5 */
extern CAL_TQM uint16_T TQF_DriveDecDistance_Filter6;/* 斜率6（新增） */
extern CAL_TQM uint16_T TQF_DriveDecDistance_Filter7;/* 斜率7（新增） */
extern CAL_TQM uint16_T TQF_DriveDecDistance_Filter8;/* 斜率8（新增） */
extern CAL_TQM uint16_T TQF_DriveDecTq1;/* 输出扭矩1 */
extern CAL_TQM uint16_T TQF_DriveDecTq2;/* 输出扭矩2 */
extern CAL_TQM uint16_T TQF_DriveDecTq3;/* 输出扭矩3 */
extern CAL_TQM uint16_T TQF_DriveDecTq4;/* 输出扭矩4 */
extern CAL_TQM uint16_T TQF_DriveDecTq5;/* 输出扭矩5（新增） */
extern CAL_TQM uint16_T TQF_DriveDecTq6;/* 输出扭矩6（新增） */
extern CAL_TQM uint16_T TQF_DriveDecTq7;/* 输出扭矩7（新增） */
extern CAL_TQM uint16_T TQF_DriveDecTqDistance1;/* 需求扭矩与输出扭矩差值1 */
extern CAL_TQM uint16_T TQF_DriveDecTqDistance2;/* 需求扭矩与输出扭矩差值2 */
extern CAL_TQM uint16_T TQF_DriveDecTqDistance3;/* 需求扭矩与输出扭矩差值3 */
extern CAL_TQM uint16_T TQF_DriveDecTqDistance4;/* 需求扭矩与输出扭矩差值4 */
extern CAL_TQM uint16_T TQF_DriveDecTqDistance5;/* 需求扭矩与输出扭矩差值5（新增） */
extern CAL_TQM uint16_T TQF_DriveDecTqDistance6;/* 需求扭矩与输出扭矩差值6（新增） */
extern CAL_TQM uint16_T TQF_DriveDecTqDistance7;/* 需求扭矩与输出扭矩差值7（新增） */
extern CAL_TQM uint16_T TQF_DriveDec_Filter1;/* 斜率1 */
extern CAL_TQM uint16_T TQF_DriveDec_Filter2;/* 斜率2 */
extern CAL_TQM uint16_T TQF_DriveDec_Filter3;/* 斜率3 */
extern CAL_TQM uint16_T TQF_DriveDec_Filter4;/* 斜率4 */
extern CAL_TQM uint16_T TQF_DriveDec_Filter5;/* 斜率5 */
extern CAL_TQM uint16_T TQF_DriveDec_Filter6;/* 斜率6（新增） */
extern CAL_TQM uint16_T TQF_DriveDec_Filter7;/* 斜率7（新增） */
extern CAL_TQM uint16_T TQF_DriveDec_Filter8;/* 斜率8（新增） */
extern CAL_TQM uint16_T TQF_DriveIncDistance_Filter1;/* 斜率1 */
extern CAL_TQM uint16_T TQF_DriveIncDistance_Filter2;/* 斜率2 */
extern CAL_TQM uint16_T TQF_DriveIncDistance_Filter3;/* 斜率3 */
extern CAL_TQM uint16_T TQF_DriveIncDistance_Filter4;/* 斜率4 */
extern CAL_TQM uint16_T TQF_DriveIncDistance_Filter5;/* 斜率5 */
extern CAL_TQM uint16_T TQF_DriveIncDistance_Filter6;/* 斜率6（新增） */
extern CAL_TQM uint16_T TQF_DriveIncDistance_Filter7;/* 斜率7（新增） */
extern CAL_TQM uint16_T TQF_DriveIncDistance_Filter8;/* 斜率8（新增） */
extern CAL_TQM uint16_T TQF_DriveIncTq1;/* 输出扭矩1 */
extern CAL_TQM uint16_T TQF_DriveIncTq2;/* 输出扭矩2 */
extern CAL_TQM uint16_T TQF_DriveIncTq3;/* 输出扭矩3 */
extern CAL_TQM uint16_T TQF_DriveIncTq4;/* 输出扭矩4 */
extern CAL_TQM uint16_T TQF_DriveIncTq5;/* 输出扭矩5（新增） */
extern CAL_TQM uint16_T TQF_DriveIncTq6;/* 输出扭矩6（新增） */
extern CAL_TQM uint16_T TQF_DriveIncTq7;/* 输出扭矩7（新增） */
extern CAL_TQM uint16_T TQF_DriveIncTqDistance1;/* 需求扭矩与输出扭矩差值1 */
extern CAL_TQM uint16_T TQF_DriveIncTqDistance2;/* 需求扭矩与输出扭矩差值2 */
extern CAL_TQM uint16_T TQF_DriveIncTqDistance3;/* 需求扭矩与输出扭矩差值3 */
extern CAL_TQM uint16_T TQF_DriveIncTqDistance4;/* 需求扭矩与输出扭矩差值4 */
extern CAL_TQM uint16_T TQF_DriveIncTqDistance5;/* 需求扭矩与输出扭矩差值5（新增） */
extern CAL_TQM uint16_T TQF_DriveIncTqDistance6;/* 需求扭矩与输出扭矩差值6（新增） */
extern CAL_TQM uint16_T TQF_DriveIncTqDistance7;/* 需求扭矩与输出扭矩差值7（新增） */
extern CAL_TQM uint16_T TQF_DriveInc_Filter1;/* 斜率1 */
extern CAL_TQM uint16_T TQF_DriveInc_Filter2;/* 斜率2 */
extern CAL_TQM uint16_T TQF_DriveInc_Filter3;/* 斜率3 */
extern CAL_TQM uint16_T TQF_DriveInc_Filter4;/* 斜率4 */
extern CAL_TQM uint16_T TQF_DriveInc_Filter5;/* 斜率5 */
extern CAL_TQM uint16_T TQF_DriveInc_Filter6;/* 斜率6（新增） */
extern CAL_TQM uint16_T TQF_DriveInc_Filter7;/* 斜率7（新增） */
extern CAL_TQM uint16_T TQF_DriveInc_Filter8;/* 斜率8（新增） */
extern CAL_TQM uint16_T TQF_EcoDriveIncDistance_Filter1;/* 斜率1 */
extern CAL_TQM uint16_T TQF_EcoDriveIncDistance_Filter2;/* 斜率2 */
extern CAL_TQM uint16_T TQF_EcoDriveIncDistance_Filter3;/* 斜率3 */
extern CAL_TQM uint16_T TQF_EcoDriveIncDistance_Filter4;/* 斜率4 */
extern CAL_TQM uint16_T TQF_EcoDriveIncDistance_Filter5;/* 斜率5 */
extern CAL_TQM uint16_T TQF_EcoDriveIncDistance_Filter6;/* 斜率6（新增） */
extern CAL_TQM uint16_T TQF_EcoDriveIncDistance_Filter7;/* 斜率7（新增） */
extern CAL_TQM uint16_T TQF_EcoDriveIncDistance_Filter8;/* 斜率8（新增） */
extern CAL_TQM uint16_T TQF_EcoDriveIncTq1;/* 输出扭矩1 */
extern CAL_TQM uint16_T TQF_EcoDriveIncTq2;/* 输出扭矩2 */
extern CAL_TQM uint16_T TQF_EcoDriveIncTq3;/* 输出扭矩3 */
extern CAL_TQM uint16_T TQF_EcoDriveIncTq4;/* 输出扭矩4 */
extern CAL_TQM uint16_T TQF_EcoDriveIncTq5;/* 输出扭矩5（新增） */
extern CAL_TQM uint16_T TQF_EcoDriveIncTq6;/* 输出扭矩6（新增） */
extern CAL_TQM uint16_T TQF_EcoDriveIncTq7;/* 输出扭矩7（新增） */
extern CAL_TQM uint16_T TQF_EcoDriveIncTqDistance1;/* 需求扭矩与输出扭矩差值1 */
extern CAL_TQM uint16_T TQF_EcoDriveIncTqDistance2;/* 需求扭矩与输出扭矩差值2 */
extern CAL_TQM uint16_T TQF_EcoDriveIncTqDistance3;/* 需求扭矩与输出扭矩差值3 */
extern CAL_TQM uint16_T TQF_EcoDriveIncTqDistance4;/* 需求扭矩与输出扭矩差值4 */
extern CAL_TQM uint16_T TQF_EcoDriveIncTqDistance5;/* 需求扭矩与输出扭矩差值5（新增） */
extern CAL_TQM uint16_T TQF_EcoDriveIncTqDistance6;/* 需求扭矩与输出扭矩差值6（新增） */
extern CAL_TQM uint16_T TQF_EcoDriveIncTqDistance7;/* 需求扭矩与输出扭矩差值7（新增） */
extern CAL_TQM uint16_T TQF_EcoDriveInc_Filter1;/* 斜率1 */
extern CAL_TQM uint16_T TQF_EcoDriveInc_Filter2;/* 斜率2 */
extern CAL_TQM uint16_T TQF_EcoDriveInc_Filter3;/* 斜率3 */
extern CAL_TQM uint16_T TQF_EcoDriveInc_Filter4;/* 斜率4 */
extern CAL_TQM uint16_T TQF_EcoDriveInc_Filter5;/* 斜率5 */
extern CAL_TQM uint16_T TQF_EcoDriveInc_Filter6;/* 斜率6（新增） */
extern CAL_TQM uint16_T TQF_EcoDriveInc_Filter7;/* 斜率7（新增） */
extern CAL_TQM uint16_T TQF_EcoDriveInc_Filter8;/* 斜率8（新增） */
extern CAL_TQM uint16_T TQF_RegenDecDistance_Filter1;/* 斜率1 */
extern CAL_TQM uint16_T TQF_RegenDecDistance_Filter2;/* 斜率2 */
extern CAL_TQM uint16_T TQF_RegenDecDistance_Filter3;/* 斜率3 */
extern CAL_TQM uint16_T TQF_RegenDecDistance_Filter4;/* 斜率4 */
extern CAL_TQM uint16_T TQF_RegenDecDistance_Filter5;/* 斜率5 */
extern CAL_TQM uint16_T TQF_RegenDecDistance_Filter6;/* 斜率6（新增） */
extern CAL_TQM uint16_T TQF_RegenDecDistance_Filter7;/* 斜率7（新增） */
extern CAL_TQM uint16_T TQF_RegenDecDistance_Filter8;/* 斜率8（新增） */
extern CAL_TQM uint16_T TQF_RegenDecTq1;/* 输出扭矩1 */
extern CAL_TQM uint16_T TQF_RegenDecTq2;/* 输出扭矩2 */
extern CAL_TQM uint16_T TQF_RegenDecTq3;/* 输出扭矩3 */
extern CAL_TQM uint16_T TQF_RegenDecTq4;/* 输出扭矩4 */
extern CAL_TQM uint16_T TQF_RegenDecTq5;/* 输出扭矩5（新增） */
extern CAL_TQM uint16_T TQF_RegenDecTq6;/* 输出扭矩6（新增） */
extern CAL_TQM uint16_T TQF_RegenDecTq7;/* 输出扭矩7（新增） */
extern CAL_TQM uint16_T TQF_RegenDecTqDistance1;/* 需求扭矩与输出扭矩差值1 */
extern CAL_TQM uint16_T TQF_RegenDecTqDistance2;/* 需求扭矩与输出扭矩差值2 */
extern CAL_TQM uint16_T TQF_RegenDecTqDistance3;/* 需求扭矩与输出扭矩差值3 */
extern CAL_TQM uint16_T TQF_RegenDecTqDistance4;/* 需求扭矩与输出扭矩差值4 */
extern CAL_TQM uint16_T TQF_RegenDecTqDistance5;/* 需求扭矩与输出扭矩差值5（新增） */
extern CAL_TQM uint16_T TQF_RegenDecTqDistance6;/* 需求扭矩与输出扭矩差值6（新增） */
extern CAL_TQM uint16_T TQF_RegenDecTqDistance7;/* 需求扭矩与输出扭矩差值7（新增） */
extern CAL_TQM uint16_T TQF_RegenDec_Filter1;/* 斜率1 */
extern CAL_TQM uint16_T TQF_RegenDec_Filter2;/* 斜率2 */
extern CAL_TQM uint16_T TQF_RegenDec_Filter3;/* 斜率3 */
extern CAL_TQM uint16_T TQF_RegenDec_Filter4;/* 斜率4 */
extern CAL_TQM uint16_T TQF_RegenDec_Filter5;/* 斜率5 */
extern CAL_TQM uint16_T TQF_RegenDec_Filter6;/* 斜率6（新增） */
extern CAL_TQM uint16_T TQF_RegenDec_Filter7;/* 斜率7（新增） */
extern CAL_TQM uint16_T TQF_RegenDec_Filter8;/* 斜率8（新增） */
extern CAL_TQM uint16_T TQF_RegenIncDistance_Filter1;/* 斜率1 */
extern CAL_TQM uint16_T TQF_RegenIncDistance_Filter2;/* 斜率2 */
extern CAL_TQM uint16_T TQF_RegenIncDistance_Filter3;/* 斜率3 */
extern CAL_TQM uint16_T TQF_RegenIncDistance_Filter4;/* 斜率4 */
extern CAL_TQM uint16_T TQF_RegenIncDistance_Filter5;/* 斜率5 */
extern CAL_TQM uint16_T TQF_RegenIncDistance_Filter6;/* 斜率6（新增） */
extern CAL_TQM uint16_T TQF_RegenIncDistance_Filter7;/* 斜率7（新增） */
extern CAL_TQM uint16_T TQF_RegenIncDistance_Filter8;/* 斜率8（新增） */
extern CAL_TQM uint16_T TQF_RegenIncTq1;/* 输出扭矩1 */
extern CAL_TQM uint16_T TQF_RegenIncTq2;/* 输出扭矩2 */
extern CAL_TQM uint16_T TQF_RegenIncTq3;/* 输出扭矩3 */
extern CAL_TQM uint16_T TQF_RegenIncTq4;/* 输出扭矩4 */
extern CAL_TQM uint16_T TQF_RegenIncTq5;/* 输出扭矩5（新增） */
extern CAL_TQM uint16_T TQF_RegenIncTq6;/* 输出扭矩6（新增） */
extern CAL_TQM uint16_T TQF_RegenIncTq7;/* 输出扭矩7（新增） */
extern CAL_TQM uint16_T TQF_RegenIncTqDistance1;/* 需求扭矩与输出扭矩差值1 */
extern CAL_TQM uint16_T TQF_RegenIncTqDistance2;/* 需求扭矩与输出扭矩差值2 */
extern CAL_TQM uint16_T TQF_RegenIncTqDistance3;/* 需求扭矩与输出扭矩差值3 */
extern CAL_TQM uint16_T TQF_RegenIncTqDistance4;/* 需求扭矩与输出扭矩差值4 */
extern CAL_TQM uint16_T TQF_RegenIncTqDistance5;/* 需求扭矩与输出扭矩差值5（新增） */
extern CAL_TQM uint16_T TQF_RegenIncTqDistance6;/* 需求扭矩与输出扭矩差值6（新增） */
extern CAL_TQM uint16_T TQF_RegenIncTqDistance7;/* 需求扭矩与输出扭矩差值7（新增） */
extern CAL_TQM uint16_T TQF_RegenInc_Filter1;/* 斜率1 */
extern CAL_TQM uint16_T TQF_RegenInc_Filter2;/* 斜率2 */
extern CAL_TQM uint16_T TQF_RegenInc_Filter3;/* 斜率3 */
extern CAL_TQM uint16_T TQF_RegenInc_Filter4;/* 斜率4 */
extern CAL_TQM uint16_T TQF_RegenInc_Filter5;/* 斜率5 */
extern CAL_TQM uint16_T TQF_RegenInc_Filter6;/* 斜率6（新增） */
extern CAL_TQM uint16_T TQF_RegenInc_Filter7;/* 斜率7（新增） */
extern CAL_TQM uint16_T TQF_RegenInc_Filter8;/* 斜率8（新增） */
extern CAL_TQM boolean_T TQF_TqFilteringEn_flg;/* 扭矩斜率限制使能开关 */
extern CAL_TQM int16_T TQM_MaxTq_Cal;  /* 系统最大允许输出扭矩 */
extern CAL_TQM uint16_T TQR_BMS_Delaytime;/* BMS三级故障时扭矩保持等待周期 */
extern CAL_TQM uint16_T TQR_MCU_Delaytime;/* MCU三级故障时扭矩保持等待周期 */
extern CAL_TQM uint16_T TSC_VehTq_Filter;/* 需求扭矩滤波系数 */
extern CAL_TQM uint16_T Tcl;           /* 软件运行周期 */
extern CAL_TQM uint32_T Tyre_Radius_Cal;/* 车轮滚动半径 */
extern CAL_TQM uint16_T VAJ_AccePress_Fail;/* 加速踏板开度小于该值认为加速踏板松开 */
extern CAL_TQM uint16_T VAJ_AccePress_Succ;/* 加速踏板开度大于该值认为加速踏板踩下 */
extern CAL_TQM uint8_T VGJ_GearOff_Cal;/* 挡位熄灭标志 */
extern CAL_TQM uint16_T VGJ_GearOff_time_Cal;/* 挡位闪烁时间-灭 */
extern CAL_TQM uint16_T VGJ_GearOn_time_Cal;/* 挡位闪烁时间-亮 */
extern CAL_TQM uint8_T VGJ_HigSpd_S11_Cal;/* S11换挡车速判断条件 */
extern CAL_TQM uint8_T VGJ_LowSpd_S11_Cal;/* S11换挡进入P档判断条件 */
extern CAL_TQM uint8_T VGJ_MidSpd_S11_Cal;/* S11低车速时不踩制动N档进入D、R车速条件 */
extern CAL_TQM uint16_T VGJ_Remind_time;/* 挂挡文字提醒最大持续时间 */
extern CAL_TQM uint8_T VGJ_Spd_K11_Cal;/* K11换挡车速判断条件 */
extern CAL_TQM uint8_T VGJ_Spd_Z18;    /* 旋钮档位切换车速阈值 */
extern CAL_TQM uint16_T VPL_PowerLim_Filter;/* 功率值限制滤波参数 */
extern CAL_TQM uint16_T VPL_PowerPctLim_Filter;/* 功率百分比限制滤波参数 */
extern CAL_TQM boolean_T VSJ_ABS_Spd_Valid_Ena;/* ABS车速信号有效位使能开关 */
extern CAL_TQM boolean_T VSJ_ABS_Spd_Valid_Val;/* ABS车速信号有效位使能状态 */
extern CAL_TQM boolean_T VSJ_MCU_Spd_Valid_Ena;/* MCU转速信号有效位使能开关 */
extern CAL_TQM boolean_T VSJ_MCU_Spd_Valid_Val;/* MCU转速信号有效位使能开关 */
extern CAL_TQM int16_T VSJ_SpdNeg_Cal; /* 电机静止-反转判别临界值 */
extern CAL_TQM int16_T VSJ_SpdPos_Cal; /* 电机静止-正转判别临界值 */
extern CAL_TQM boolean_T VSJ_Spd_Valid_Ena;/* 速度信号有效位使能开关 */
extern CAL_TQM boolean_T VSJ_Spd_Valid_Val;/* 速度信号有效位使能状态 */
extern CAL_TQM uint8_T VSL_GearD1_YK19_SpdLim_Hig;/* 手动挡车型D1挡限制车速上限 */
extern CAL_TQM uint8_T VSL_GearD1_YK19_SpdLim_Low;/* 手动挡车型D1挡限制车速下限 */
extern CAL_TQM uint8_T VSL_GearD2_YK19_SpdLim_Hig;/* 手动挡车型D2挡限制车速上限 */
extern CAL_TQM uint8_T VSL_GearD2_YK19_SpdLim_Low;/* 手动挡车型D2挡限制车速下限 */
extern CAL_TQM uint8_T VSL_GearD3_YK19_SpdLim_Hig;/* 手动挡车型D3挡限制车速上限 */
extern CAL_TQM uint8_T VSL_GearD3_YK19_SpdLim_Low;/* 手动挡车型D3挡限制车速下限 */
extern CAL_TQM uint8_T VSL_GearD4_YK19_SpdLim_Hig;/* 手动挡车型D4挡限制车速上限 */
extern CAL_TQM uint8_T VSL_GearD4_YK19_SpdLim_Low;/* 手动挡车型D4挡限制车速下限 */
extern CAL_TQM uint8_T VSL_GearD5_YK19_SpdLim_Hig;/* 手动挡车型D5挡限制车速上限 */
extern CAL_TQM uint8_T VSL_GearD5_YK19_SpdLim_Low;/* 手动挡车型D5挡限制车速下限 */
extern CAL_TQM uint8_T VSL_GearD_ECOSpdLim_Hig;/* ECO模式D挡限速上限 */
extern CAL_TQM uint8_T VSL_GearD_ECOSpdLim_Low;/* ECO模式D挡限速下限 */
extern CAL_TQM uint8_T VSL_GearD_SPTSpdLim_Hig;/* SPT模式D挡限速上限 */
extern CAL_TQM uint8_T VSL_GearD_SPTSpdLim_Low;/* SPT模式D挡限速下限 */
extern CAL_TQM uint8_T VSL_GearD_SpdLim_Hig;/* D挡限速上限 */
extern CAL_TQM uint8_T VSL_GearD_SpdLim_Low;/* D挡限速下限 */
extern CAL_TQM uint8_T VSL_GearR_SpdLim_Hig;/* R挡速度上限 */
extern CAL_TQM uint8_T VSL_GearR_SpdLim_Low;/* R挡限速下限 */
extern CAL_TQM uint8_T VSL_GearR_YK19_SpdLim_Hig;/* 手动挡车型R挡限制车速上限 */
extern CAL_TQM uint8_T VSL_GearR_YK19_SpdLim_Low;/* 手动挡车型R挡限制车速下限 */
extern CAL_TQM uint8_T VSL_HighSOC;    /* 高于该SOC值不限制车速 */
extern CAL_TQM uint8_T VSL_LowSOC;     /* 低于该SOC值限制车速到130 */
extern CAL_TQM uint8_T VSL_LowSOC_SpdLim_rpm;/* 低SOC限制车速 */
extern CAL_TQM uint8_T VSL_NormSOC_SpdLim_rpm;
extern CAL_TQM uint16_T VSL_SpdLim_Filter;/* 车速限制滤波参数 */
extern CAL_TQM boolean_T VTA_Arbitration_Ena;/* 仲裁使能开关 */
extern CAL_TQM boolean_T VTA_Arbitration_Val;/* 仲裁使能值 */
extern CAL_TQM boolean_T VTA_GearN_Ena;/* N挡滑行扭矩使能 */
extern CAL_TQM uint16_T VTA_GearN_MotSpd[14];/* N挡滑行扭矩map-转速 */
extern CAL_TQM int16_T VTA_GearN_Tq[14];/* N挡滑行扭矩map-扭矩 */
extern CAL_TQM uint16_T VTA_Gear_P_N_Filter;/* P/N挡扭矩滤波系数 */
extern CAL_TQM uint16_T Veh_Sim_Interval_dT;/* 积分时间 */
extern CAL_TQM uint32_T Velocity_Ratio_Cal;/* 减速比 */
extern CAL_TQM boolean_T b1_C_TQD_ACRCtrEna;/* 加速度环使能开关 */
extern CAL_TQM boolean_T big_C_ConfigAccSensor_flg;/* 加速度来源判断整车是否配置加速度传感器 */
extern CAL_TQM uint8_T eSpeedlHistSize;
extern CAL_TQM real32_T f4_C_VSP_AccSpdLower_mpss;/* 实际加速度下限 */
extern CAL_TQM real32_T f4_C_VSP_AccSpdUpper_mpss;/* 实际加速度上限 */
extern CAL_TQM real32_T f4_C_VSP_KamFiter_P;/* 加速度卡尔曼滤波系数P */
extern CAL_TQM real32_T f4_C_VSP_KamFiter_Q;/* 加速度卡尔曼滤波系数Q */
extern CAL_TQM real32_T f4_C_VSP_KamFiter_R;/* 加速度卡尔曼滤波系数R */
extern CAL_TQM int16_T lo_dec_limit;   /* 斜率限制部分扭矩减小值 */
extern CAL_TQM real32_T s1_C_ESC_TqUpOffset;/* ESC请求扭矩大于vcu需求扭矩阈值 */
extern CAL_TQM real32_T s1_C_TQM_MCUTqDiff;/* 需求扭矩与实际扭矩的差值判断阈值 */
extern CAL_TQM int8_T s2_C_TQF_DecRatStepFactor;/* 扭矩下降斜率调整因子:该值与软件运行周期相关，该值*软件运行周期=1s */
extern CAL_TQM int8_T s2_C_TQF_IncRatStepFactor;/* 扭矩上升斜率调整因子:该值与软件运行周期相关，该值*软件运行周期=1s */
extern CAL_TQM uint8_T u1_CT_TQF_AbsModRegenTqDecZRat_Nmps[25];/* Creep工况下的再生制动扭矩减小时的斜率限制MAP的Z轴(为了降低数据类型,单位为Nm/100ms) */
extern CAL_TQM uint8_T u1_CT_TQF_GearDAccPdlModEcoDriveTqDecZRat_Nmps[25];/* AccelPedal工况下D挡ECO模式的驱动扭矩减小时的斜率限制MAP的Z轴(为了降低数据类型,单位为Nm/100ms)(为了降低数据类型,单位为Nm/100ms) */
extern CAL_TQM uint8_T u1_CT_TQF_GearDAccPdlModEcoDriveTqIncZRat_Nmps[25];/* AccelPedal工况下D挡ECO模式的驱动扭矩增加时的斜率限制MAP的Z轴(为了降低数据类型,单位为Nm/100ms)(为了降低数据类型,单位为Nm/100ms) */
extern CAL_TQM uint8_T u1_CT_TQF_GearDAccPdlModEcoRegenTqDecZRat_Nmps[25];/* AccelPedal工况下D挡ECO模式的再生制动扭矩减小时的斜率限制MAP的Z轴(为了降低数据类型,单位为Nm/100ms) */
extern CAL_TQM uint8_T u1_CT_TQF_GearDAccPdlModEcoRegenTqIncZRat_Nmps[25];/* AccelPedal工况下D挡ECO模式的再生制动扭矩增加时的斜率限制MAP的Z轴(为了降低数据类型,单位为Nm/100ms) */
extern CAL_TQM uint8_T u1_CT_TQF_GearDAccPdlModSportDriveTqDecZRat_Nmps[25];/* AccelPedal工况下D挡SPORT模式的驱动扭矩减小时的斜率限制MAP的Z轴(为了降低数据类型,单位为Nm/100ms) */
extern CAL_TQM uint8_T u1_CT_TQF_GearDAccPdlModSportDriveTqIncZRat_Nmps[25];/* AccelPedal工况下D挡SPORT模式的驱动扭矩增加时的斜率限制MAP的Z轴(为了降低数据类型,单位为Nm/100ms) */
extern CAL_TQM uint8_T u1_CT_TQF_GearDAccPdlModSportRegenTqDecZRat_Nmps[25];/* AccelPedal工况下D挡SPORT模式的再生制动扭矩减小时的斜率限制MAP的Z轴(为了降低数据类型,单位为Nm/100ms) */
extern CAL_TQM uint8_T u1_CT_TQF_GearDAccPdlModSportRegenTqIncZRat_Nmps[25];/* AccelPedal工况下D挡SPORT模式的再生制动扭矩增加时的斜率限制MAP的Z轴(为了降低数据类型,单位为Nm/100ms) */
extern CAL_TQM uint8_T u1_CT_TQF_GearDCreepModDriveTqDecZRat_Nmps[25];/* Creep工况下D挡的驱动扭矩减小时的斜率限制MAP的Z轴(为了降低数据类型,单位为Nm/100ms) */
extern CAL_TQM uint8_T u1_CT_TQF_GearDCreepModDriveTqIncZRat_Nmps[25];/* Creep工况下D挡的驱动扭矩增加时的斜率限制MAP的Z轴(为了降低数据类型,单位为Nm/100ms) */
extern CAL_TQM uint8_T u1_CT_TQF_GearDCreepModRegenTqDecZRat_Nmps[25];/* Creep工况下D挡的再生制动扭矩减小时的斜率限制MAP的Z轴(为了降低数据类型,单位为Nm/100ms) */
extern CAL_TQM uint8_T u1_CT_TQF_GearDCreepModRegenTqIncZRat_Nmps[25];/* Creep工况下D挡的再生制动扭矩增加时的斜率限制MAP的Z轴(为了降低数据类型,单位为Nm/100ms) */
extern CAL_TQM uint8_T u1_CT_TQF_GearRAccPdlModEcoDriveTqDecZRat_Nmps[25];/* AccelPedal工况下R挡ECO模式的驱动扭矩减小时的斜率限制MAP的Z轴(为了降低数据类型,单位为Nm/100ms)(为了降低数据类型,单位为Nm/100ms) */
extern CAL_TQM uint8_T u1_CT_TQF_GearRAccPdlModEcoDriveTqIncZRat_Nmps[25];/* AccelPedal工况下R挡ECO模式的驱动扭矩增加时的斜率限制MAP的Z轴(为了降低数据类型,单位为Nm/100ms)(为了降低数据类型,单位为Nm/100ms) */
extern CAL_TQM uint8_T u1_CT_TQF_GearRAccPdlModEcoRegenTqDecZRat_Nmps[25];/* AccelPedal工况下R挡ECO模式的再生制动扭矩减小时的斜率限制MAP的Z轴(为了降低数据类型,单位为Nm/100ms) */
extern CAL_TQM uint8_T u1_CT_TQF_GearRAccPdlModEcoRegenTqIncZRat_Nmps[25];/* AccelPedal工况下R挡ECO模式的再生制动扭矩增加时的斜率限制MAP的Z轴(为了降低数据类型,单位为Nm/100ms) */
extern CAL_TQM uint8_T u1_CT_TQF_GearRAccPdlModSportDriveTqDecZRat_Nmps[25];/* AccelPedal工况下R挡SPORT模式的驱动扭矩减小时的斜率限制MAP的Z轴(为了降低数据类型,单位为Nm/100ms) */
extern CAL_TQM uint8_T u1_CT_TQF_GearRAccPdlModSportDriveTqIncZRat_Nmps[25];/* AccelPedal工况下R挡SPORT模式的驱动扭矩增加时的斜率限制MAP的Z轴(为了降低数据类型,单位为Nm/100ms) */
extern CAL_TQM uint8_T u1_CT_TQF_GearRAccPdlModSportRegenTqDecZRat_Nmps[25];/* AccelPedal工况下R挡SPORT模式的再生制动扭矩减小时的斜率限制MAP的Z轴(为了降低数据类型,单位为Nm/100ms) */
extern CAL_TQM uint8_T u1_CT_TQF_GearRAccPdlModSportRegenTqIncZRat_Nmps[25];/* AccelPedal工况下R挡SPORT模式的再生制动扭矩增加时的斜率限制MAP的Z轴(为了降低数据类型,单位为Nm/100ms) */
extern CAL_TQM uint8_T u1_CT_TQF_GearRCreepModDriveTqDecZRat_Nmps[25];/* Creep工况下R挡的驱动扭矩减小时的斜率限制MAP的Z轴(为了降低数据类型,单位为Nm/100ms) */
extern CAL_TQM uint8_T u1_CT_TQF_GearRCreepModDriveTqIncZRat_Nmps[25];/* Creep工况下R挡的驱动扭矩增加时的斜率限制MAP的Z轴(为了降低数据类型,单位为Nm/100ms) */
extern CAL_TQM uint8_T u1_CT_TQF_GearRCreepModRegenTqDecZRat_Nmps[25];/* Creep工况下R挡的再生制动扭矩减小时的斜率限制MAP的Z轴(为了降低数据类型,单位为Nm/100ms) */
extern CAL_TQM uint8_T u1_CT_TQF_GearRCreepModRegenTqIncZRat_Nmps[25];/* Creep工况下R挡的再生制动扭矩增加时的斜率限制MAP的Z轴(为了降低数据类型,单位为Nm/100ms) */
extern CAL_TQM uint8_T u1_CT_TQF_HDCModDriveTqDecZRat_Nmps[25];/* HDC工况下的驱动扭矩减小时的斜率限制MAP的Z轴(单位：Nm/100ms) */
extern CAL_TQM uint8_T u1_CT_TQF_HDCModDriveTqIncZRat_Nmps[25];/* HDC工况下的驱动扭矩增加时的斜率限制MAP的Z轴(单位：Nm/100ms) */
extern CAL_TQM uint8_T u1_CT_TQF_HDCModRegenTqDecZRat_Nmps[25];/* HDC工况下的再生制动扭矩减小时的斜率限制MAP的Z轴(单位：Nm/100ms) */
extern CAL_TQM uint8_T u1_CT_TQF_HDCModRegenTqIncZRat_Nmps[25];/* HDC工况下的再生制动扭矩增加时的斜率限制MAP的Z轴(单位：Nm/100ms) */
extern CAL_TQM uint8_T u1_CT_TQF_HighRegenModDriveTqDecZRat_Nmps[25];/* 高级Regen工况下的驱动扭矩减小时的斜率限制MAP的Z轴(为了降低数据类型,单位为Nm/100ms) */
extern CAL_TQM uint8_T u1_CT_TQF_HighRegenModDriveTqIncZRat_Nmps[25];/* 高级Regen工况下的驱动扭矩增加时的斜率限制MAP的Z轴(为了降低数据类型,单位为Nm/100ms) */
extern CAL_TQM uint8_T u1_CT_TQF_HighRegenModRegenTqDecZRat_Nmps[25];/* 高级Regen工况下的再生制动扭矩减小时的斜率限制MAP的Z轴(为了降低数据类型,单位为Nm/100ms) */
extern CAL_TQM uint8_T u1_CT_TQF_HighRegenModRegenTqIncZRat_Nmps[25];/* 高级egen工况下的再生制动扭矩增加时的斜率限制MAP的Z轴(为了降低数据类型,单位为Nm/100ms) */
extern CAL_TQM uint8_T u1_CT_TQF_LowRegenModDriveTqDecZRat_Nmps[25];/* 低级Regen工况下的驱动扭矩减小时的斜率限制MAP的Z轴(为了降低数据类型,单位为Nm/100ms) */
extern CAL_TQM uint8_T u1_CT_TQF_LowRegenModDriveTqIncZRat_Nmps[25];/* 低级Regen工况下的驱动扭矩增加时的斜率限制MAP的Z轴(为了降低数据类型,单位为Nm/100ms) */
extern CAL_TQM uint8_T u1_CT_TQF_LowRegenModRegenTqDecZRat_Nmps[25];/* 低级Regen工况下的再生制动扭矩减小时的斜率限制MAP的Z轴(为了降低数据类型,单位为Nm/100ms) */
extern CAL_TQM uint8_T u1_CT_TQF_LowRegenModRegenTqIncZRat_Nmps[25];/* 低级egen工况下的再生制动扭矩增加时的斜率限制MAP的Z轴(为了降低数据类型,单位为Nm/100ms) */
extern CAL_TQM uint8_T u1_CT_TQF_NedcModDriveTqDecZRat_Nmps[25];/* NEDC工况下的驱动扭矩减小时的斜率限制MAP的Z轴(为了降低数据类型,单位为Nm/100ms) */
extern CAL_TQM uint8_T u1_CT_TQF_NedcModDriveTqIncZRat_Nmps[25];/* NEDC工况下的驱动扭矩增加时的斜率限制MAP的Z轴(为了降低数据类型,单位为Nm/100ms) */
extern CAL_TQM uint8_T u1_CT_TQF_NedcModRegenTqDecZRat_Nmps[25];/* NEDC工况下的再生制动扭矩减小时的斜率限制MAP的Z轴(为了降低数据类型,单位为Nm/100ms) */
extern CAL_TQM uint8_T u1_CT_TQF_NedcModRegenTqIncZRat_Nmps[25];/* NEDC工况下的再生制动扭矩增加时的斜率限制MAP的Z轴(为了降低数据类型,单位为Nm/100ms) */
extern CAL_TQM uint8_T u1_C_Booster_En;
extern CAL_TQM uint8_T u1_C_ESC_ESP_En;/* 0:无ABS 1：ABS 2:ESP */
extern CAL_TQM boolean_T u1_C_ESC_EscEnableFlg;/* ESC使能开关(0:关闭、1：开启) */
extern CAL_TQM uint8_T u1_C_ESC_EscIncEnaFlg;/* ESC增扭使能开关(0:关闭、1：开启) */
extern CAL_TQM boolean_T u1_C_HDC_En;  /* HDC工况配置字使能 */
extern CAL_TQM uint8_T u1_C_TQF_AbsModDriveTqDecRat_Nmps;/* ABS工况下默认值 */
extern CAL_TQM uint8_T u1_C_TQF_AbsModDriveTqIncRat_Nmps;/* ABS工况下默认值 */
extern CAL_TQM uint8_T u1_C_TQF_DefModGearPNRat_Nmps;/* Deafult工况下P/N挡扭矩卸载斜率限制(为了降低数据类型,单位为Nm/100ms) */
extern CAL_TQM uint8_T u1_C_TQF_DefModSteadyDecRat_Nmps;/* Deafult工况下扭矩下降默认斜率——扭矩处于稳态(为了降低数据类型,单位为Nm/100ms) */
extern CAL_TQM uint8_T u1_C_TQF_DefModSteadyIncRat_Nmps;/* Deafult工况下扭矩上升默认斜率——扭矩处于稳态(为了降低数据类型,单位为Nm/100ms) */
extern CAL_TQM boolean_T u1_C_TQF_UseFilterRateNewArch;/* 是否使用精细化扭矩滤波（1：表示使用精细化扭矩滤波） */
extern CAL_TQM real32_T u1_C_TQM_MCUTqMaxFactor;/* MCU限扭系数阈值(0.9-最大误差) */
extern CAL_TQM int16_T u2_CT_TQF_AbsModRegenTqDecXOldTq_Nm[5];/* Creep工况下的再生制动扭矩减小时的斜率限制MAP的X轴(前回输出扭矩的绝对值) */
extern CAL_TQM int16_T u2_CT_TQF_AbsModRegenTqDecYTqDiff_Nm[5];/* Creep工况下的再生制动扭矩减小时的斜率限制MAP的Y轴((今回期望扭矩 - 前回输出扭矩值)的绝对值) */
extern CAL_TQM int16_T u2_CT_TQF_AccPdlModEcoDriveTqDecXOldTq_Nm[5];/* AccelPedal工况下ECO模式的驱动扭矩减小时的斜率限制MAP的X轴(前回输出扭矩的绝对值) */
extern CAL_TQM int16_T u2_CT_TQF_AccPdlModEcoDriveTqDecYTqDiff_Nm[5];/* AccelPedal工况下ECO模式的驱动扭矩减小时的斜率限制MAP的Y轴((今回期望扭矩 - 前回输出扭矩值)的绝对值) */
extern CAL_TQM int16_T u2_CT_TQF_AccPdlModEcoDriveTqIncXOldTq_Nm[5];/* AccelPedal工况下ECO模式的驱动扭矩增加时的斜率限制MAP的X轴(前回输出扭矩的绝对值) */
extern CAL_TQM int16_T u2_CT_TQF_AccPdlModEcoDriveTqIncYTqDiff_Nm[5];/* AccelPedal工况下ECO模式的驱动扭矩增加时的斜率限制MAP的Y轴((今回期望扭矩 - 前回输出扭矩值)的绝对值) */
extern CAL_TQM int16_T u2_CT_TQF_AccPdlModEcoRegenTqDecXOldTq_Nm[5];/* AccelPedal工况下ECO模式的再生制动扭矩减小时的斜率限制MAP的X轴(前回输出扭矩的绝对值) */
extern CAL_TQM int16_T u2_CT_TQF_AccPdlModEcoRegenTqDecYTqDiff_Nm[5];/* AccelPedal工况下ECO模式的再生制动扭矩减小时的斜率限制MAP的Y轴((今回期望扭矩 - 前回输出扭矩值)的绝对值) */
extern CAL_TQM int16_T u2_CT_TQF_AccPdlModEcoRegenTqIncXOldTq_Nm[5];/* AccelPedal工况下ECO模式的再生制动扭矩增加时的斜率限制MAP的X轴(前回输出扭矩的绝对值) */
extern CAL_TQM int16_T u2_CT_TQF_AccPdlModEcoRegenTqIncYTqDiff_Nm[5];/* AccelPedal工况下ECO模式的再生制动扭矩增加时的斜率限制MAP的Y轴((今回期望扭矩 - 前回输出扭矩值)的绝对值) */
extern CAL_TQM int16_T u2_CT_TQF_AccPdlModSportDriveTqDecXOldTq_Nm[5];/* AccelPedal工况下SPORT模式的驱动扭矩减小时的斜率限制MAP的X轴(前回输出扭矩的绝对值) */
extern CAL_TQM int16_T u2_CT_TQF_AccPdlModSportDriveTqDecYTqDiff_Nm[5];/* AccelPedal工况下SPORT模式的驱动扭矩减小时的斜率限制MAP的Y轴((今回期望扭矩 - 前回输出扭矩值)的绝对值) */
extern CAL_TQM int16_T u2_CT_TQF_AccPdlModSportDriveTqIncXOldTq_Nm[5];/* AccelPedal工况下SPORT模式的驱动扭矩增加时的斜率限制MAP的X轴(前回输出扭矩的绝对值) */
extern CAL_TQM int16_T u2_CT_TQF_AccPdlModSportDriveTqIncYTqDiff_Nm[5];/* AccelPedal工况下SPORT模式的驱动扭矩增加时的斜率限制MAP的Y轴((今回期望扭矩 - 前回输出扭矩值)的绝对值) */
extern CAL_TQM int16_T u2_CT_TQF_AccPdlModSportRegenTqDecXOldTq_Nm[5];/* AccelPedal工况下SPORT模式的再生制动扭矩减小时的斜率限制MAP的X轴(前回输出扭矩的绝对值) */
extern CAL_TQM int16_T u2_CT_TQF_AccPdlModSportRegenTqDecYTqDiff_Nm[5];/* AccelPedal工况下SPORT模式的再生制动扭矩减小时的斜率限制MAP的Y轴((今回期望扭矩 - 前回输出扭矩值)的绝对值) */
extern CAL_TQM int16_T u2_CT_TQF_AccPdlModSportRegenTqIncXOldTq_Nm[5];/* AccelPedal工况下SPORT模式的再生制动扭矩增加时的斜率限制MAP的X轴(前回输出扭矩的绝对值) */
extern CAL_TQM int16_T u2_CT_TQF_AccPdlModSportRegenTqIncYTqDiff_Nm[5];/* AccelPedal工况下SPORT模式的再生制动扭矩增加时的斜率限制MAP的Y轴((今回期望扭矩 - 前回输出扭矩值)的绝对值) */
extern CAL_TQM int16_T u2_CT_TQF_CreepModDriveTqDecXOldTq_Nm[5];/* Creep工况下的驱动扭矩减小时的斜率限制MAP的X轴(前回输出扭矩的绝对值) */
extern CAL_TQM int16_T u2_CT_TQF_CreepModDriveTqDecYTqDiff_Nm[5];/* Creep工况下的驱动扭矩减小时的斜率限制MAP的Y轴((今回期望扭矩 - 前回输出扭矩值)的绝对值) */
extern CAL_TQM int16_T u2_CT_TQF_CreepModDriveTqIncXOldTq_Nm[5];/* Creep工况下的驱动扭矩增加时的斜率限制MAP的X轴(前回输出扭矩的绝对值) */
extern CAL_TQM int16_T u2_CT_TQF_CreepModDriveTqIncYTqDiff_Nm[5];/* Creep工况下的驱动扭矩增加时的斜率限制MAP的Y轴((今回期望扭矩 - 前回输出扭矩值)的绝对值) */
extern CAL_TQM int16_T u2_CT_TQF_CreepModRegenTqDecXOldTq_Nm[5];/* Creep工况下的再生制动扭矩减小时的斜率限制MAP的X轴(前回输出扭矩的绝对值) */
extern CAL_TQM int16_T u2_CT_TQF_CreepModRegenTqDecYTqDiff_Nm[5];/* Creep工况下的再生制动扭矩减小时的斜率限制MAP的Y轴((今回期望扭矩 - 前回输出扭矩值)的绝对值) */
extern CAL_TQM int16_T u2_CT_TQF_CreepModRegenTqIncXOldTq_Nm[5];/* Creep工况下的再生制动扭矩增加时的斜率限制MAP的X轴(前回输出扭矩的绝对值) */
extern CAL_TQM int16_T u2_CT_TQF_CreepModRegenTqIncYTqDiff_Nm[5];/* Creep工况下的再生制动扭矩增加时的斜率限制MAP的Y轴((今回期望扭矩 - 前回输出扭矩值)的绝对值) */
extern CAL_TQM int16_T u2_CT_TQF_HDCModDriveTqDecXOldTq_Nm[5];/* HDC工况下的驱动扭矩减小时的斜率限制MAP的X轴(前回输出扭矩的绝对值) */
extern CAL_TQM int16_T u2_CT_TQF_HDCModDriveTqDecYTqDiff_Nm[5];/* HDC工况下的驱动扭矩减小时的斜率限制MAP的Y轴((今回期望扭矩 - 前回输出扭矩值)的绝对值) */
extern CAL_TQM int16_T u2_CT_TQF_HDCModDriveTqIncXOldTq_Nm[5];/* HDC工况下的驱动扭矩增加时的斜率限制MAP的X轴(前回输出扭矩的绝对值) */
extern CAL_TQM int16_T u2_CT_TQF_HDCModDriveTqIncYTqDiff_Nm[5];/* HDC工况下的驱动扭矩增加时的斜率限制MAP的Y轴((今回期望扭矩 - 前回输出扭矩值)的绝对值) */
extern CAL_TQM int16_T u2_CT_TQF_HDCModRegenTqDecXOldTq_Nm[5];/* HDC工况下的再生制动扭矩减小时的斜率限制MAP的X轴(前回输出扭矩的绝对值) */
extern CAL_TQM int16_T u2_CT_TQF_HDCModRegenTqDecYTqDiff_Nm[5];/* HDC工况下的再生制动扭矩减小时的斜率限制MAP的Y轴((今回期望扭矩 - 前回输出扭矩值)的绝对值) */
extern CAL_TQM int16_T u2_CT_TQF_HDCModRegenTqIncXOldTq_Nm[5];/* HDC工况下的再生制动扭矩增加时的斜率限制MAP的X轴(前回输出扭矩的绝对值) */
extern CAL_TQM int16_T u2_CT_TQF_HDCModRegenTqIncYTqDiff_Nm[5];/* HDC工况下的再生制动扭矩增加时的斜率限制MAP的Y轴((今回期望扭矩 - 前回输出扭矩值)的绝对值) */
extern CAL_TQM int16_T u2_CT_TQF_NedcModDriveTqDecXOldTq_Nm[5];/* NEDC工况下的驱动扭矩减小时的斜率限制MAP的X轴(前回输出扭矩的绝对值) */
extern CAL_TQM int16_T u2_CT_TQF_NedcModDriveTqDecYTqDiff_Nm[5];/* NEDC工况下的驱动扭矩减小时的斜率限制MAP的Y轴((今回期望扭矩 - 前回输出扭矩值)的绝对值) */
extern CAL_TQM int16_T u2_CT_TQF_NedcModDriveTqIncXOldTq_Nm[5];/* NEDC工况下的驱动扭矩增加时的斜率限制MAP的X轴(前回输出扭矩的绝对值) */
extern CAL_TQM int16_T u2_CT_TQF_NedcModDriveTqIncYTqDiff_Nm[5];/* NEDC工况下的驱动扭矩增加时的斜率限制MAP的Y轴((今回期望扭矩 - 前回输出扭矩值)的绝对值) */
extern CAL_TQM int16_T u2_CT_TQF_NedcModRegenTqDecXOldTq_Nm[5];/* NEDC工况下的再生制动扭矩减小时的斜率限制MAP的X轴(前回输出扭矩的绝对值) */
extern CAL_TQM int16_T u2_CT_TQF_NedcModRegenTqDecYTqDiff_Nm[5];/* NEDC工况下的再生制动扭矩减小时的斜率限制MAP的Y轴((今回期望扭矩 - 前回输出扭矩值)的绝对值) */
extern CAL_TQM int16_T u2_CT_TQF_NedcModRegenTqIncXOldTq_Nm[5];/* NEDC工况下的再生制动扭矩增加时的斜率限制MAP的X轴(前回输出扭矩的绝对值) */
extern CAL_TQM int16_T u2_CT_TQF_NedcModRegenTqIncYTqDiff_Nm[5];/* NEDC工况下的再生制动扭矩增加时的斜率限制MAP的Y轴((今回期望扭矩 - 前回输出扭矩值)的绝对值) */
extern CAL_TQM int16_T u2_CT_TQF_RegenModDriveTqDecXOldTq_Nm[5];/* Regen工况下的驱动扭矩减小时的斜率限制MAP的X轴(前回输出扭矩的绝对值) */
extern CAL_TQM int16_T u2_CT_TQF_RegenModDriveTqDecYTqDiff_Nm[5];/* Regen工况下的驱动扭矩减小时的斜率限制MAP的Y轴((今回期望扭矩 - 前回输出扭矩值)的绝对值) */
extern CAL_TQM int16_T u2_CT_TQF_RegenModDriveTqIncXOldTq_Nm[5];/* Regen工况下的驱动扭矩增加时的斜率限制MAP的X轴(前回输出扭矩的绝对值) */
extern CAL_TQM int16_T u2_CT_TQF_RegenModDriveTqIncYTqDiff_Nm[5];/* Regen工况下的驱动扭矩增加时的斜率限制MAP的Y轴((今回期望扭矩 - 前回输出扭矩值)的绝对值) */
extern CAL_TQM int16_T u2_CT_TQF_RegenModRegenTqDecXOldTq_Nm[5];/* Regen工况下的再生制动扭矩减小时的斜率限制MAP的X轴(前回输出扭矩的绝对值) */
extern CAL_TQM int16_T u2_CT_TQF_RegenModRegenTqDecYTqDiff_Nm[5];/* Regen工况下的再生制动扭矩减小时的斜率限制MAP的Y轴((今回期望扭矩 - 前回输出扭矩值)的绝对值) */
extern CAL_TQM int16_T u2_CT_TQF_RegenModRegenTqIncXOldTq_Nm[5];/* Regen工况下的再生制动扭矩增加时的斜率限制MAP的X轴(前回输出扭矩的绝对值) */
extern CAL_TQM int16_T u2_CT_TQF_RegenModRegenTqIncYTqDiff_Nm[5];/* Regen工况下的再生制动扭矩增加时的斜率限制MAP的Y轴((今回期望扭矩 - 前回输出扭矩值)的绝对值) */
extern CAL_TQM real32_T u2_C_ASM_DecMotTq_Step;/* MCU防溜扭矩退出步长 */
extern CAL_TQM real32_T u2_C_ASM_MinTq;/* MCU防溜扭矩退出最小值 */
extern CAL_TQM uint16_T u2_C_GearBoxDelayTime;/* 手动挡车型档位确认周期阈值 */
extern CAL_TQM uint16_T u2_C_TQM_MCUTqDiffDlyTime;/* 需求扭矩与实际扭矩的差值判断时间阈值 */
extern CAL_TQM uint16_T u2_C_VSP_ActAclLowPassFilter_ms;/* 加速度一阶滤波系数 */
extern CAL_TQM int16_T up_inc_limit;   /* 斜率限制部分扭矩增加值 */

#endif                                 /* RTW_HEADER_TQM_Cal_Data_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

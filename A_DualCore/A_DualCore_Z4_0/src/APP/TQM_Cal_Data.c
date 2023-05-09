/*
 * File: TQM_Cal_Data.c
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

#include "rtwtypes.h"
#include "TQM_model_types.h"

/* Exported data definition */
#include "derivative.h"

/* Definition for custom storage class: CAL_9_TQM */
CAL_TQM real32_T ABS_FR_DeltaCurveHalfAxle = 0.2F;/* 左右轮轮速差 */
CAL_TQM boolean_T ABS_WheelSpd_Enable = 0;/* 是否通过ABS的轮速算车速 */
CAL_TQM real32_T ABS_vWhlRL_Revise = 0.0F;/* 通过前一轮的车速来推测本轮车速时的修正量 */
CAL_TQM uint16_T ASM_EPB_AntiSlide_Timer = 200U;/* MCU防切换EPB防坡度判断延迟counter */
CAL_TQM int16_T ASM_EPB_Applied_DelayTime = 200;/* 判断EPB夹驻超时counter，超出则停止夹驻请求。 */
CAL_TQM boolean_T ASM_EPB_BrakeSta_En = 0;/* EPB防溜坡进入条件踩制动进入使能标识 */
CAL_TQM uint16_T ASM_En_AntiSlide_Spd_Delay = 300U;/* EPB防溜车速有效性判断时间 */
CAL_TQM int8_T ASM_GearD_Over_Tq = 5;  /* D挡，需求扭矩大于防溜坡扭矩超过该值才认为需求扭矩确实大于防溜坡扭矩 */
CAL_TQM uint16_T ASM_GearD_Tq_Upper_Delay = 40U;/* 需求扭矩大于防溜扭矩的持续时间大于该值则退出防溜功能（D挡） */
CAL_TQM int8_T ASM_GearR_Over_Tq = -5; /* R挡，需求扭矩（绝对值）大于防溜坡扭矩（绝对值）超过该值才认为需求扭矩大于防溜坡扭矩 */
CAL_TQM uint16_T ASM_GearR_Tq_Upper_Delay = 40U;/* 需求扭矩大于防溜扭矩的持续时间大于该值则退出防溜功能（R挡） */
CAL_TQM int16_T ASM_MCUAntiSlide_AvTq_Max = 180;/* 允许MCU输出的最大防溜坡扭矩 */
CAL_TQM int16_T ASM_MCUAntiSlide_AvTq_Min = -180;/* 允许MCU输出的最小防溜坡扭矩 */
CAL_TQM boolean_T ASM_MCUAntiSlide_Ena = 0;/* 转速环防溜坡使能开关 */
CAL_TQM boolean_T ASM_MCUAntiSlide_Val = 0;/* 转速环防溜坡使能值 */
CAL_TQM int16_T ASM_MCU_GearDAntiSlide_Spd_En = -5;/* D档MCU防溜坡期静止判断转速 */
CAL_TQM int8_T ASM_MCU_GearD_Lower_RoadAngle = -128;/* D档防溜坡进入坡度条件的下限值 */
CAL_TQM int16_T ASM_MCU_GearRAntiSlide_Spd_En = 5;/* R档MCU防溜坡期静止判断转速 */
CAL_TQM int8_T ASM_MCU_GearR_Upper_RoadAngle = 127;/* R档防溜坡进入坡度条件的上限值 */
CAL_TQM uint16_T ASM_MCU_QuitApplied_DelayTime = 20U;/* EPB防溜坡MCU使能等待周期counter */
CAL_TQM uint16_T ASM_S11_AntiSlideEnter_DrivePower = 64U;/* 可用放电功率大于该值允许开启防溜坡功能 */
CAL_TQM int32_T ASM_S11_AntiSlideEnter_RoadAngle = 5120;/* 电机转速小于该值认为车辆处于静止状态（用于坡度判断） */
CAL_TQM uint16_T ASM_S11_AntiSlideQuit_DrivePower = 48U;/* S11防溜坡功能模式判断坡度值 */
CAL_TQM uint32_T ASM_S11_AntiSlide_ConfirmTime = 240000U;/* 未踩制动时，防溜坡持续时间大于该值则退出防溜坡功能 */
CAL_TQM int16_T ASM_S11_AntiSlide_ForwardSpd_Uena = 300;/* 电机转速大于该值认为车辆处于快速行驶状态，此时要求退出防溜坡 */
CAL_TQM int16_T ASM_S11_AntiSlide_ReverseSpd_Uena = -300;/* 电机转速小于该值认为车辆处于快速后溜状态，此时要求退出防溜坡 */
CAL_TQM int16_T ASM_S11_AntiSlide_Spd_Static = 10;/* 电机转速小于该值认为车辆处于静止状态（D挡） */
CAL_TQM boolean_T ASM_S11_AveMotSpdFilter_En = 0;/* 防溜坡车速判断模块车速滤波使能标志 */
CAL_TQM uint16_T ASM_S11_EPBConfirm_TrueDelay = 500U;/* MCU防溜坡期间EPB夹驻延时判断时间 */
CAL_TQM int16_T ASM_S11_EPB_AntiSlide_ForwardSpd = 10;/* EPB防溜进入条件：前进车速阀值 */
CAL_TQM int16_T ASM_S11_EPB_AntiSlide_ReverseSpd = -10;/* EPB防溜进入条件：后退车速阀值 */
CAL_TQM uint16_T ASM_S11_GearD_Delay = 500U;/* 停留在D挡的持续时间大于该值才允许进入防溜坡功能（D挡） */
CAL_TQM uint16_T ASM_S11_GearD_Spd_Slide_Delay = 40U;/* 车辆进入缓慢后溜状态的持续时间大于该值则认为车辆确实处于缓慢后溜状态（D挡） */
CAL_TQM int16_T ASM_S11_GearD_Spd_Slide_Hig = -5;/* 电机转速小于该值认为车辆处于缓慢后溜状态（D挡） */
CAL_TQM int16_T ASM_S11_GearD_Spd_Slide_Low = -200;/* 电机转速大于该值认为车辆处于缓慢后溜状态（D挡） */
CAL_TQM uint16_T ASM_S11_GearR_Delay = 500U;/* 停留在R挡的持续时间大于该值才允许进入防溜坡功能（R挡） */
CAL_TQM uint16_T ASM_S11_GearR_Spd_Slide_Delay = 40U;/* 车辆进入缓慢后溜状态的持续时间大于该值则认为车辆确实处于缓慢后溜状态（R挡） */
CAL_TQM int16_T ASM_S11_GearR_Spd_Slide_Hig = 200;/* 电机转速小于该值认为车辆处于缓慢后溜状态（R挡） */
CAL_TQM int16_T ASM_S11_GearR_Spd_Slide_Low = 5;/* 电机转速大于该值认为车辆处于缓慢后溜状态（R挡） */
CAL_TQM uint16_T ASM_S11_MCU_Spd_Static_TrueDelay = 60U;/* 车辆判别为静止状态的最小持续静止时间 */
CAL_TQM uint16_T ASM_S11_MCU_Spd_Static_ZeroDelay = 80U;/* 车辆判别为非静止状态的最小持续静止时间 */
CAL_TQM uint16_T ASM_S11_StaticConfirm_TrueDelay = 400U;/* 用于判断车辆稳定静止的持续时间-用于防溜坡时的角度判断 */
CAL_TQM uint16_T ASM_Uena_AntiSlide_Spd_Delay = 200U;/* 防溜坡车速超出时间延时 */
CAL_TQM uint16_T BLC_ChrgConnectConfirm_Delay = 200U;/* 充电连接信号连接确认（充电时不响应EPB的点亮制动灯请求） */
CAL_TQM uint16_T BLC_ChrgConnectQuit_Delay = 200U;/* 充电连接信号断开确认（充电时不响应EPB的点亮制动灯请求） */
CAL_TQM uint8_T BLC_EPBConfirmSpd_Cal = 5U;/* EPB拉起时点亮制动灯的车速下限 */
CAL_TQM uint8_T BLC_EPBQuitSpd_Cal = 3U;/* EPB拉起时熄灭制动灯的车速上限 */
CAL_TQM int16_T BLC_GearD_LampOff_Tq = -80;/* D挡能量回馈熄灭制动灯的回馈扭矩阈值 */
CAL_TQM int16_T BLC_GearD_LampOn_Tq = -160;/* D挡能量回馈点亮制动灯的回馈扭矩阈值 */
CAL_TQM int16_T BLC_GearR_LampOff_Tq = 80;/* R挡能量回馈熄灭制动灯的回馈扭矩阈值 */
CAL_TQM int16_T BLC_GearR_LampOn_Tq = 160;/* R挡能量回馈点亮制动灯的回馈扭矩阈值 */
CAL_TQM boolean_T Cal_AccePctMode_flg = 0;/* 手动挡车型离合器半联动加速踏板模式选择开关 */
CAL_TQM uint16_T Cal_ClutchSysEnable_TrueDelay = 50U;/* 手动挡车型离合器使能确认时间 */
CAL_TQM uint16_T Cal_ClutchSysEnable_ZeroDelay = 50U;/* 手动挡车型离合器释放确认时间 */
CAL_TQM real32_T Cal_Clutchlinkage_Threshold = 10.0F;/* 手动挡车型离合器半联动加速踏板深度阈值 */
CAL_TQM int16_T Cal_Creep_GearD_VehSpeed = 96;/* D档蠕行目标车速 */
CAL_TQM int16_T Cal_Creep_GearR_VehSpeed = -64;/* R档蠕行目标车速 */
CAL_TQM boolean_T Cal_Ready_En = 0;    /* 手动挡车型离合器档位控制READY开关 */
CAL_TQM boolean_T Cal_Ready_Val = 0;   /* 手动挡车型离合器档位控制READY数值 */
CAL_TQM boolean_T Cal_RegenGrade_Ena = 0;/* 滑行回馈等级强制控制开关 */
CAL_TQM uint8_T Cal_RegenGrade_Val = 0U;/* 滑行回馈等级强制控制赋值 */
CAL_TQM uint8_T Cal_pedalCoefficient = 7U;/* 手动挡车型离合器半联动加速踏板深度分段增加段数 */
CAL_TQM int16_T CreepD_Spd_Forward_limit_Off = 1920;/* D档蠕行正向退出车速 */
CAL_TQM int16_T CreepD_Spd_Forward_limit_On = 1664;/* D档蠕行正向进入车速 */
CAL_TQM int16_T CreepD_Spd_Reverse_limit = -1062;/* D档蠕行逆向进入车速 */
CAL_TQM int16_T CreepR_Spd_Forward_limit = 1574;/* R档蠕行正向进入车速 */
CAL_TQM int16_T CreepR_Spd_Reserve_limit_Off = -1280;/* R档蠕行逆向退出车速 */
CAL_TQM int16_T CreepR_Spd_Reserve_limit_On = -1152;/* R档蠕行逆向进入车速 */
CAL_TQM uint16_T Creep_Ki_GearD[17] =
{
    200U, 200U, 200U, 200U, 200U, 200U, 200U, 200U, 200U, 200U, 20U, 20U, 20U,
    20U, 20U, 20U, 20U
} ;                                    /* D挡蠕行Ki查表-Ki */

CAL_TQM uint16_T Creep_Ki_GearR[17] =
{
    200U, 200U, 200U, 200U, 200U, 200U, 200U, 200U, 200U, 200U, 20U, 20U, 20U,
    20U, 20U, 20U, 20U
} ;                                    /* R挡蠕行Ki查表-Ki */

CAL_TQM uint16_T Creep_Kp_GearD[17] =
{
    20U, 20U, 20U, 20U, 20U, 20U, 20U, 20U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U
} ;                                    /* D挡蠕行Kp查表-Kp */

CAL_TQM uint16_T Creep_Kp_GearR[17] =
{
    20U, 20U, 20U, 20U, 20U, 20U, 20U, 20U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U
} ;                                    /* R挡蠕行Kp查表-Kp */

CAL_TQM int16_T CrpVehSpd_DV[17] =
{
    -128, -96, -64, -48, -32, -24, -16, -8, 0, 8, 16, 24, 32, 48, 64, 96, 128
} ;                                    /* R/D挡蠕行Kp/Ki查表-车速差 */

CAL_TQM uint16_T DTD_GearD_Brake_CloseToGear_MotSpd_Ena = 1000U;/* D挡靠齿功能开启转速（踩制动） */
CAL_TQM uint16_T DTD_GearD_Brake_CloseToGear_MotSpd_Uena = 1200U;/* D挡靠齿功能关闭转速（踩制动） */
CAL_TQM int8_T DTD_GearD_Brake_CloseToGear_Tq = 1;/* D挡靠齿扭矩（踩制动）（map更改为单值） */
CAL_TQM boolean_T DTD_GearD_CloseToGear_Ena = 0;/* D挡靠齿功能开关 */
CAL_TQM uint16_T DTD_GearD_CloseToGear_MotSpd_Ena = 1000U;/* D挡靠齿功能开启转速（未踩制动） */
CAL_TQM uint16_T DTD_GearD_CloseToGear_MotSpd_Uena = 1200U;/* D挡靠齿功能关闭转速（未踩制动） */
CAL_TQM int8_T DTD_GearD_CloseToGear_Tq = 1;/* D挡靠齿扭矩（未踩制动）（map更改为单值） */
CAL_TQM uint16_T DTD_GearR_Brake_CloseToGear_MotSpd_Ena = 1000U;/* R挡靠齿功能开启转速（踩制动） */
CAL_TQM uint16_T DTD_GearR_Brake_CloseToGear_MotSpd_Uena = 1200U;/* R挡靠齿功能关闭转速（踩制动） */
CAL_TQM int8_T DTD_GearR_Brake_CloseToGear_Tq = 1;/* R挡靠齿扭矩（踩制动）（map更改为单值） */
CAL_TQM boolean_T DTD_GearR_CloseToGear_Ena = 0;/* R挡靠齿功能开关 */
CAL_TQM uint16_T DTD_GearR_CloseToGear_MotSpd_Ena = 1000U;/* R挡靠齿功能开启转速（未踩制动） */
CAL_TQM uint16_T DTD_GearR_CloseToGear_MotSpd_Uena = 1200U;/* R挡靠齿功能关闭转速（未踩制动） */
CAL_TQM int8_T DTD_GearR_CloseToGear_Tq = 1;/* R挡靠齿扭矩（未踩制动）（map更改为单值） */
CAL_TQM uint16_T ECM_EPB_Acceleration_X_Filter = 100U;
CAL_TQM uint16_T ECM_SAS_SteeringAngleSpeed_Filter = 100U;
CAL_TQM uint16_T ECM_SAS_SteeringAngle_Filter = 100U;
CAL_TQM uint8_T ENUM_MCUMODE_SpdCtl = 4U;/* 电机转速环控制标志 */
CAL_TQM uint8_T ENUM_MCUMODE_TRQCTL = 5U;/* 电机扭矩环控制标志 */
CAL_TQM uint8_T ENUM_TMMODE_MOTOR = 1U;/* 电机放电模式标志 */
CAL_TQM uint8_T ENUM_TMMODE_REGEN = 2U;/* 电机发电模式标志 */
CAL_TQM uint8_T ENUM_TQF_DEC = 2U;     /* 扭矩下降标志 */
CAL_TQM uint8_T ENUM_TQF_INC = 1U;     /* 扭矩上升标志 */
CAL_TQM uint8_T ENUM_TQF_STEADY = 0U;  /* 扭矩稳定标志 */
CAL_TQM uint16_T EPB_Delay_time = 10U; /* EPB夹驻请求有效性判断时间 */
CAL_TQM uint8_T FDT_ClutchEnRegen_Spd_Off = 3U;/* 手动挡车型离合器拖拽功能使能车速关闭阈值 */
CAL_TQM uint8_T FDT_ClutchEnRegen_Spd_On = 3U;/* 手动挡车型离合器拖拽功能使能车速开启阈值 */
CAL_TQM uint8_T FDT_Crp_PID_SteadyConst = 10U;/* 蠕行PID计算中的稳态常量 */
CAL_TQM int8_T FDT_GearD_BrakeRegenTq_Offset = 0;/* R挡制动回收扭矩偏移量 */
CAL_TQM int16_T FDT_GearD_Crp_Tqlim_Low = -800;/* D挡蠕行的最小输出扭矩 */
CAL_TQM int16_T FDT_GearD_Crp_Tqlim_Up = 800;/* D挡蠕行的最大输出扭矩 */
CAL_TQM int8_T FDT_GearR_BrakeRegenTq_Offset = 0;/* D挡制动回收扭矩偏移量 */
CAL_TQM int16_T FDT_GearR_Crp_Tqlim_Low = -800;/* R挡蠕行的最小输出扭矩 */
CAL_TQM int16_T FDT_GearR_Crp_Tqlim_Up = 800;/* R挡蠕行的最大输出扭矩 */
CAL_TQM uint8_T FDT_Regen_Spd_Off = 8U;/* 能量回收关闭对应的车速上限 */
CAL_TQM uint8_T FDT_Regen_Spd_On = 12U;/* 能量回收开启对应的车速下限 */
CAL_TQM uint8_T Forward = 1U;          /* 电机正转标志 */
CAL_TQM uint8_T GTC_GearTouch_Direction_Ena = 0U;/* 靠齿方向使能开关 */
CAL_TQM uint8_T GTC_GearTouch_Direction_Val = 0U;/* 靠齿方向使能值 */
CAL_TQM boolean_T GTC_GearTouch_Ena = 0;/* 扭矩靠齿功能使能开关 */
CAL_TQM uint8_T GTC_GearTouch_EnaSpd_Hig = 30U;/* 小于该车速允许执行靠齿 */
CAL_TQM uint8_T GTC_GearTouch_EnaSpd_Low = 8U;/* 大于该车速允许执行靠齿 */
CAL_TQM uint16_T GTC_GearTouch_NtoP_Timer1 = 20U;/* 第一段靠齿扭矩持续时间——需求扭矩由负变正 */
CAL_TQM uint16_T GTC_GearTouch_NtoP_Timer2 = 20U;/* 前两段靠齿扭矩持续时间之和——需求扭矩由负变正 */
CAL_TQM uint16_T GTC_GearTouch_NtoP_Timer3 = 0U;/* 前三段靠齿扭矩持续时间之和——需求扭矩由负变正 */
CAL_TQM uint16_T GTC_GearTouch_NtoP_Timer4 = 0U;/* 前四段靠齿扭矩持续时间之和——需求扭矩由负变正 */
CAL_TQM real32_T GTC_GearTouch_NtoP_Tq1 = 1.0F;/* 过零靠齿扭矩第一段——需求扭矩由负变正 */
CAL_TQM real32_T GTC_GearTouch_NtoP_Tq2 = 1.0F;/* 过零靠齿扭矩第二段——需求扭矩由负变正 */
CAL_TQM real32_T GTC_GearTouch_NtoP_Tq3 = 1.0F;/* 过零靠齿扭矩第三段——需求扭矩由负变正 */
CAL_TQM real32_T GTC_GearTouch_NtoP_Tq4 = 1.0F;/* 过零靠齿扭矩第四段——需求扭矩由负变正 */
CAL_TQM uint16_T GTC_GearTouch_PtoN_Timer1 = 20U;/* 第一段靠齿扭矩持续时间——需求扭矩由正变负 */
CAL_TQM uint16_T GTC_GearTouch_PtoN_Timer2 = 20U;/* 前两段靠齿扭矩持续时间之和——需求扭矩由正变负 */
CAL_TQM uint16_T GTC_GearTouch_PtoN_Timer3 = 0U;/* 前三段靠齿扭矩持续时间之和——需求扭矩由正变负 */
CAL_TQM uint16_T GTC_GearTouch_PtoN_Timer4 = 0U;/* 前四段靠齿扭矩持续时间之和——需求扭矩由正变负 */
CAL_TQM real32_T GTC_GearTouch_PtoN_Tq1 = -1.0F;/* 过零靠齿扭矩第一段——需求扭矩由正变负 */
CAL_TQM real32_T GTC_GearTouch_PtoN_Tq2 = -1.0F;/* 过零靠齿扭矩第二段——需求扭矩由正变负 */
CAL_TQM real32_T GTC_GearTouch_PtoN_Tq3 = -1.0F;/* 过零靠齿扭矩第三段——需求扭矩由正变负 */
CAL_TQM real32_T GTC_GearTouch_PtoN_Tq4 = -1.0F;/* 过零靠齿扭矩第四段——需求扭矩由正变负 */
CAL_TQM uint8_T GTC_GearTouch_UnEnaSpd_Hig = 32U;/* 大于该车速禁止靠齿 */
CAL_TQM uint8_T GTC_GearTouch_UnEnaSpd_Low = 6U;/* 小于该车速禁止靠齿 */
CAL_TQM real32_T GTC_ZeroAcross_Tq = 0.5F;/* 扭矩过零判断阈值 */
CAL_TQM uint8_T GearD = 4U;            /* D档 */
CAL_TQM uint8_T GearD_Release = 6U;    /* N下半行程 */
CAL_TQM uint8_T GearR_Release = 5U;    /* N上半行程 */
CAL_TQM uint8_T Gear_D = 4U;           /* D挡标志 */
CAL_TQM uint8_T Gear_D1 = 7U;          /* 手动挡车型D1挡 */
CAL_TQM uint8_T Gear_D2 = 8U;          /* 手动挡车型D2挡 */
CAL_TQM uint8_T Gear_D3 = 9U;          /* 手动挡车型D3挡 */
CAL_TQM uint8_T Gear_D4 = 10U;         /* 手动挡车型D4挡 */
CAL_TQM uint8_T Gear_D5 = 11U;         /* 手动挡车型D5挡 */
CAL_TQM uint8_T Gear_N = 3U;           /* N挡标志 */
CAL_TQM uint8_T Gear_P = 1U;           /* P挡标志 */
CAL_TQM uint8_T Gear_R = 2U;           /* R挡标志 */
CAL_TQM uint32_T Gravitational_Accel = 642253U;/* 重力加速度 */
CAL_TQM int16_T KNEDC_AccDeltaLower_mps = -102;
CAL_TQM int16_T KNEDC_AccDeltaUpper_mps = 102;
CAL_TQM uint8_T KNEDC_BRAKETYPE_KMPH120120 = 6U;
CAL_TQM uint8_T KNEDC_BRAKETYPE_KMPH12050 = 8U;
CAL_TQM uint8_T KNEDC_BRAKETYPE_KMPH12080 = 7U;
CAL_TQM uint8_T KNEDC_BRAKETYPE_KMPH15 = 1U;
CAL_TQM uint8_T KNEDC_BRAKETYPE_KMPH32 = 2U;
CAL_TQM uint8_T KNEDC_BRAKETYPE_KMPH35 = 4U;
CAL_TQM uint8_T KNEDC_BRAKETYPE_KMPH50 = 3U;
CAL_TQM uint8_T KNEDC_BRAKETYPE_KMPH70 = 5U;
CAL_TQM int16_T KNEDC_BrakeTorqueILower_Nm = 0;
CAL_TQM int16_T KNEDC_BrakeTorqueIReset_Nm = 0;
CAL_TQM int16_T KNEDC_BrakeTorqueIStep_Nm = 1;
CAL_TQM int16_T KNEDC_BrakeTorqueIUpper_Nm = 0;
CAL_TQM uint8_T KNEDC_SpeedHyst_kmph = 3U;/* NEDC工况判断的允许车速偏差 */
CAL_TQM int16_T KNEDC_kmph120120Acc_mps = -707;
CAL_TQM int16_T KNEDC_kmph12050Acc_mps = -1423;
CAL_TQM int16_T KNEDC_kmph12080Acc_mps = -1065;
CAL_TQM uint16_T KNEDC_kmph120HoldTime_s = 3000U;/* 判别进入NEDC工况120kph稳定车速所需的120kph最小维持时间 */
CAL_TQM uint8_T KNEDC_kmph120_kmph = 120U;/* 120kph车速标志 */
CAL_TQM int16_T KNEDC_kmph15Acc_mps = -850;
CAL_TQM uint16_T KNEDC_kmph15HoldTime_s = 3000U;/* 判别进入NEDC工况15kph稳定车速所需的15kph最小维持时间 */
CAL_TQM uint8_T KNEDC_kmph15_kmph = 15U;/* 15kph车速标志 */
CAL_TQM int16_T KNEDC_kmph32Acc_mps = -829;
CAL_TQM uint16_T KNEDC_kmph32HoldTime_s = 3000U;/* 判别进入NEDC工况32kph稳定车速所需的32kph最小维持时间 */
CAL_TQM uint8_T KNEDC_kmph32_kmph = 32U;/* 32kph车速标志 */
CAL_TQM int16_T KNEDC_kmph35Acc_mps = -993;
CAL_TQM uint16_T KNEDC_kmph35HoldTime_s = 3000U;/* 判别进入NEDC工况35kph稳定车速所需35kph最小维持时间 */
CAL_TQM uint8_T KNEDC_kmph35_kmph = 35U;/* 35kph车速标志 */
CAL_TQM int16_T KNEDC_kmph50Acc_mps = -532;
CAL_TQM uint16_T KNEDC_kmph50HoldTime_s = 3000U;/* 判别进入NEDC工况50kph稳定车速所需的50kph最小维持时间 */
CAL_TQM uint8_T KNEDC_kmph50_kmph = 50U;/* 50kph车速标志 */
CAL_TQM int16_T KNEDC_kmph70Acc_mps = -707;
CAL_TQM uint16_T KNEDC_kmph70HoldTime_s = 3000U;/* 判别进入NEDC工况70kph稳定车速所需的70kph最小维持时间 */
CAL_TQM uint8_T KNEDC_kmph70_kmph = 70U;/* 70kph车速标志 */
CAL_TQM uint8_T KNEDC_kmph80_kmph = 80U;/* 80kph车速标志 */
CAL_TQM boolean_T KTQD_NEDCBakeEn_flg = 0;/* NEDC工况使能 */
CAL_TQM uint16_T KTQD_NEDCBrakeMotorSpeedMin_rpm = 100U;/* NEDC能量回收功能进入的转速下限 */
CAL_TQM uint16_T KTQF_GearPN_Rate_Nmps = 400U;/* P/N挡扭矩卸载斜率限制 */
CAL_TQM uint16_T KTQF_RTDefaultDEC_Nmps = 100U;/* 扭矩下降默认斜率——扭矩处于稳态 */
CAL_TQM uint16_T KTQF_RTDefaultINC_Nmps = 100U;/* 扭矩上升默认斜率——扭矩处于稳态 */
CAL_TQM int8_T KTQF_TMDecRatStepFactor = -50;/* 扭矩下降斜率调整因子 */
CAL_TQM uint8_T KTQF_TMDecRatStepFilterFactor = 100U;/* 扭矩下降斜率滤波因子 */
CAL_TQM int8_T KTQF_TMIncRatStepFactor = 50;/* 扭矩上升斜率调整因子 */
CAL_TQM uint8_T KTQF_TMIncRatStepFilterFactor = 50U;/* 扭矩上升斜率滤波因子 */
CAL_TQM uint16_T KTQF_TqClunkRateLimitDec_Nmps = 50U;/* 扭矩过零点下降斜率限制 */
CAL_TQM uint16_T KTQF_TqClunkRateLimitInc_Nmps = 50U;/* 扭矩过零点上升斜率限制 */
CAL_TQM uint8_T KTQF_TqClunkThresholdDecHigh_Nm = 0U;/* 扭矩下降过零点判别上限值 */
CAL_TQM int8_T KTQF_TqClunkThresholdDecLow_Nm = 0;/* 扭矩下降过零点判别下限值 */
CAL_TQM uint8_T KTQF_TqClunkThresholdIncHigh_Nm = 0U;/* 扭矩上升过零点判别上限值 */
CAL_TQM int8_T KTQF_TqClunkThresholdIncLow_Nm = 0;/* 扭矩上升过零点判别下限值 */
CAL_TQM int32_T KTQF_TqPrecisionLimit_Nm = 10;/* 用于判断扭矩上升、稳定下降状态的最小扭矩增量 */
CAL_TQM uint16_T MAM_K11_MCUAntiSlidePowerEna_rpm = 80U;/* K11可用放电功率大于该值则可开启防溜坡功能 */
CAL_TQM uint16_T MAM_K11_MCUAntiSlidePowerForbid_rpm = 48U;/* K11可用放电功率大于该值则退出防溜坡功能 */
CAL_TQM int16_T MAM_K11_MCUAntiSlideSpdEna_rpm = 15;/* K11防溜坡功能开启转速 */
CAL_TQM int16_T MAM_K11_MCUAntiSlideSpdForbid_rpm = 180;/* K11防溜坡功能退出转速 */
CAL_TQM uint16_T MAS_DisAntishake_Delay = 20U;/* MCU防抖功能关闭延时 */
CAL_TQM uint16_T MAS_EnaAntishake_Delay = 100U;/* MCU防抖功能开启延时 */
CAL_TQM uint16_T MNEDC_kmph120120Brake_X_kmph[15] =
{
    0U, 80U, 160U, 320U, 480U, 640U, 800U, 960U, 1120U, 1280U, 1312U, 1600U,
    1760U, 1920U, 2080U
} ;                                    /* NEDC工况120kph回馈扭矩map-车速 */

CAL_TQM int16_T MNEDC_kmph120120Brake_Z_Nm[15] =
{
    0, 0, -480, -480, -480, -480, -480, -480, -480, -240, -272, -256, -240, -32,
    -480
} ;                                    /* NEDC工况120kph回馈扭矩map-扭矩 */

CAL_TQM uint16_T MNEDC_kmph15Brake_X_kmph[15] =
{
    0U, 16U, 32U, 240U, 320U, 640U, 800U, 960U, 1120U, 1280U, 1440U, 1600U,
    1760U, 1920U, 2080U
} ;                                    /* NEDC工况15kph回馈扭矩map-车速 */

CAL_TQM int16_T MNEDC_kmph15Brake_Z_Nm[15] =
{
    0, -16, -736, -736, -720, -720, -720, -640, -608, -592, -640, -640, -640,
    -640, -480
} ;                                    /* NEDC工况15kph回馈扭矩map-扭矩 */

CAL_TQM uint16_T MNEDC_kmph32Brake_X_kmph[15] =
{
    0U, 16U, 32U, 320U, 512U, 640U, 800U, 960U, 1120U, 1280U, 1440U, 1600U,
    1760U, 1920U, 2080U
} ;                                    /* NEDC工况32kph回馈扭矩map-车速 */

CAL_TQM int16_T MNEDC_kmph32Brake_Z_Nm[15] =
{
    0, -16, -752, -752, -736, -688, -480, -480, -480, -480, -480, -480, -480,
    -480, -480
} ;                                    /* NEDC工况32kph回馈扭矩map-扭矩 */

CAL_TQM uint16_T MNEDC_kmph35Brake_X_kmph[15] =
{
    0U, 16U, 32U, 320U, 480U, 560U, 640U, 960U, 1120U, 1280U, 1440U, 1600U,
    1760U, 1920U, 2080U
} ;                                    /* NEDC工况35kph回馈扭矩map-车速 */

CAL_TQM int16_T MNEDC_kmph35Brake_Z_Nm[15] =
{
    0, -16, -800, -800, -800, -816, -880, -640, -608, -592, -640, -640, -640,
    -640, -480
} ;                                    /* NEDC工况35kph回馈扭矩map-扭矩 */

CAL_TQM uint16_T MNEDC_kmph50Brake_X_kmph[15] =
{
    0U, 80U, 160U, 544U, 560U, 592U, 640U, 800U, 960U, 1280U, 1440U, 1600U,
    1760U, 1920U, 2080U
} ;                                    /* NEDC工况50kph回馈扭矩map-车速 */

CAL_TQM int16_T MNEDC_kmph50Brake_Z_Nm[15] =
{
    0, 0, -480, -480, -272, -272, -272, -256, -320, -480, -480, -480, -480, -480,
    -480
} ;                                    /* NEDC工况50kph回馈扭矩map-扭矩 */

CAL_TQM uint16_T MNEDC_kmph70Brake_X_kmph[15] =
{
    0U, 80U, 160U, 320U, 480U, 640U, 800U, 832U, 1120U, 1280U, 1440U, 1600U,
    1760U, 1920U, 2080U
} ;                                    /* NEDC工况70kph回馈扭矩map-车速 */

CAL_TQM int16_T MNEDC_kmph70Brake_Z_Nm[15] =
{
    0, 0, -240, -672, -800, -864, -464, -464, -464, -480, -640, -640, -640, -640,
    -480
} ;                                    /* NEDC工况70kph回馈扭矩map-扭矩 */

CAL_TQM int16_T MTQD_GearD_BrakeRegen_Zero_Tq[19] =
{
    0, 0, -5, -10, -25, -24, -23, -22, -21, -20, -19, -17, -15, -10, -5, 0, 0, 0,
    0
} ;                                    /* D挡制动能量回收扭矩map-扭矩（零挡回收） */

CAL_TQM int16_T MTQD_GearD_CoastRegen_First_Tq[19] =
{
    0, 0, -4, -7, -12, -17, -22, -27, -32, -32, -32, -27, -22, -17, -12, -7, 0,
    0, 0
} ;                                    /* D挡滑行能量回收扭矩map-扭矩（一挡回收） */

CAL_TQM int16_T MTQD_GearD_CoastRegen_Fourth_Tq[19] =
{
    0, 0, -16, -32, -42, -52, -62, -62, -62, -62, -62, -57, -52, -42, -32, -27,
    -22, 0, 0
} ;                                    /* D挡滑行能量回收扭矩map-扭矩（四挡回收） */

CAL_TQM int16_T MTQD_GearD_CoastRegen_Second_Tq[19] =
{
    0, 0, -11, -22, -32, -37, -42, -42, -42, -42, -42, -42, -42, -32, -22, -12,
    0, 0, 0
} ;                                    /* D挡滑行能量回收扭矩map-扭矩（二挡回收） */

CAL_TQM uint16_T MTQD_GearD_CoastRegen_Spd[19] =
{
    0U, 520U, 780U, 975U, 1300U, 1950U, 2600U, 3250U, 3900U, 4550U, 5200U, 5850U,
    6500U, 7150U, 7800U, 8450U, 9100U, 9425U, 9750U
} ;                                    /* D挡滑行能量回收扭矩map-转速 */

CAL_TQM int16_T MTQD_GearD_CoastRegen_Third_Tq[19] =
{
    0, 0, -14, -27, -37, -47, -57, -57, -52, -52, -52, -52, -47, -37, -27, -17,
    -12, 0, 0
} ;                                    /* D挡滑行能量回收扭矩map-扭矩（三挡回收） */

CAL_TQM int16_T MTQD_GearR_BrakeRegen_Zero_Tq[19] =
{
    0, 0, -5, -10, -25, -24, -23, -22, -21, -20, -19, -17, -15, -10, -5, 0, 0, 0,
    0
} ;                                    /* R挡制动能量回收扭矩map-扭矩（零挡回收） */

CAL_TQM int16_T MTQD_GearR_CoastRegen_First_Tq[19] =
{
    0, 0, -4, -7, -12, -17, -22, -27, -32, -32, -32, -27, -22, -17, -12, -7, 0,
    0, 0
} ;                                    /* R挡滑行能量回收扭矩map-扭矩（一挡回收） */

CAL_TQM int16_T MTQD_GearR_CoastRegen_Fourth_Tq[19] =
{
    0, 0, -16, -32, -42, -52, -62, -62, -62, -62, -62, -57, -52, -42, -32, -27,
    -22, 0, 0
} ;                                    /* R挡滑行能量回收扭矩map-扭矩（四挡回收） */

CAL_TQM int16_T MTQD_GearR_CoastRegen_Second_Tq[19] =
{
    0, 0, -11, -22, -32, -37, -42, -42, -42, -42, -42, -42, -42, -32, -22, -12,
    0, 0, 0
} ;                                    /* R挡滑行能量回收扭矩map-扭矩（二挡回收） */

CAL_TQM uint16_T MTQD_GearR_CoastRegen_Spd[19] =
{
    0U, 520U, 780U, 975U, 1300U, 1950U, 2600U, 3250U, 3900U, 4550U, 5200U, 5850U,
    6500U, 7150U, 7800U, 8450U, 9100U, 9425U, 9750U
} ;                                    /* R挡滑行能量回收扭矩map-转速 */

CAL_TQM int16_T MTQD_GearR_CoastRegen_Third_Tq[19] =
{
    0, 0, -14, -27, -37, -47, -57, -57, -52, -52, -52, -52, -47, -37, -27, -17,
    -12, 0, 0
} ;                                    /* R挡滑行能量回收扭矩map-扭矩（三挡回收） */

CAL_TQM uint16_T MTQD_PedalMapAccpedal_ClutchMode_pct[16] =
{
    0U, 80U, 160U, 320U, 480U, 640U, 720U, 800U, 880U, 960U, 1040U, 1120U, 1280U,
    1440U, 1520U, 1600U
} ;                                    /* 手动挡车型D挡峰值扭矩百分比amp-加速踏板开度 */

CAL_TQM uint16_T MTQD_PedalMapBoostAccpedal_Eco_pct[16] =
{
    0U, 80U, 160U, 320U, 480U, 640U, 720U, 800U, 880U, 960U, 1040U, 1120U, 1280U,
    1440U, 1520U, 1600U
} ;                                    /* Normal模式D挡峰值扭矩百分比amp-加速踏板开度 */

CAL_TQM uint16_T MTQD_PedalMapBoostAccpedal_X_pct[16] =
{
    0U, 80U, 160U, 320U, 480U, 640U, 720U, 800U, 880U, 960U, 1040U, 1120U, 1280U,
    1440U, 1520U, 1600U
} ;                                    /* Sport模式D挡峰值扭矩百分比amp-加速踏板开度 */

CAL_TQM uint16_T MTQD_PedalMapBoostTmSpeed_Eco_rpm[12] =
{
    500U, 1000U, 1500U, 1850U, 2250U, 3000U, 3750U, 4500U, 6000U, 7500U, 9000U,
    10500U
} ;                                    /* Normal模式D挡峰值扭矩百分比amp-转速 */

CAL_TQM uint16_T MTQD_PedalMapBoostTmSpeed_Y_rpm[12] =
{
    500U, 1000U, 1500U, 1850U, 2250U, 3000U, 3750U, 4500U, 6000U, 7500U, 9000U,
    10500U
} ;                                    /* Sport模式D挡峰值扭矩百分比amp-转速 */

CAL_TQM uint16_T MTQD_PedalMapBoost_Eco_pct[192] =
{
    0U, 32U, 80U, 160U, 288U, 480U, 640U, 800U, 960U, 1120U, 1280U, 1360U, 1488U,
    1568U, 1600U, 1600U, 0U, 32U, 80U, 160U, 288U, 480U, 640U, 800U, 960U, 1120U,
    1280U, 1360U, 1488U, 1568U, 1600U, 1600U, 0U, 32U, 80U, 160U, 288U, 480U,
    640U, 800U, 960U, 1120U, 1280U, 1360U, 1488U, 1568U, 1600U, 1600U, 0U, 16U,
    80U, 160U, 288U, 480U, 640U, 800U, 960U, 1120U, 1280U, 1360U, 1488U, 1568U,
    1600U, 1600U, 0U, 0U, 64U, 160U, 288U, 480U, 640U, 800U, 944U, 1120U, 1280U,
    1360U, 1488U, 1568U, 1584U, 1600U, 0U, 0U, 48U, 160U, 288U, 480U, 608U, 784U,
    912U, 1120U, 1280U, 1360U, 1488U, 1568U, 1584U, 1600U, 0U, 0U, 32U, 160U,
    272U, 448U, 576U, 752U, 880U, 1120U, 1280U, 1360U, 1488U, 1568U, 1584U,
    1600U, 0U, 0U, 16U, 144U, 256U, 416U, 528U, 688U, 848U, 1072U, 1280U, 1360U,
    1488U, 1552U, 1584U, 1600U, 0U, 0U, 0U, 128U, 240U, 384U, 496U, 656U, 816U,
    1024U, 1264U, 1360U, 1472U, 1536U, 1584U, 1600U, 0U, 0U, 0U, 112U, 208U,
    352U, 464U, 624U, 784U, 976U, 1200U, 1280U, 1440U, 1520U, 1568U, 1600U, 0U,
    0U, 0U, 96U, 176U, 320U, 432U, 592U, 752U, 928U, 1104U, 1200U, 1360U, 1456U,
    1536U, 1600U, 0U, 0U, 0U, 80U, 160U, 288U, 400U, 560U, 720U, 880U, 1040U,
    1120U, 1280U, 1440U, 1520U, 1600U
} ;                                    /* Normal模式D挡峰值扭矩百分比amp-百分比 */

CAL_TQM uint16_T MTQD_PedalMapBoost_pct[192] =
{
    0U, 32U, 80U, 160U, 288U, 480U, 640U, 800U, 960U, 1120U, 1280U, 1360U, 1488U,
    1568U, 1600U, 1600U, 0U, 32U, 80U, 160U, 288U, 480U, 640U, 800U, 960U, 1120U,
    1280U, 1360U, 1488U, 1568U, 1600U, 1600U, 0U, 32U, 80U, 160U, 288U, 480U,
    640U, 800U, 960U, 1120U, 1280U, 1360U, 1488U, 1568U, 1600U, 1600U, 0U, 16U,
    80U, 160U, 288U, 480U, 640U, 800U, 960U, 1120U, 1280U, 1360U, 1488U, 1568U,
    1600U, 1600U, 0U, 0U, 64U, 160U, 288U, 480U, 640U, 800U, 944U, 1120U, 1280U,
    1360U, 1488U, 1568U, 1584U, 1600U, 0U, 0U, 48U, 160U, 288U, 480U, 608U, 784U,
    912U, 1120U, 1280U, 1360U, 1488U, 1568U, 1584U, 1600U, 0U, 0U, 32U, 160U,
    272U, 448U, 576U, 752U, 880U, 1120U, 1280U, 1360U, 1488U, 1568U, 1584U,
    1600U, 0U, 0U, 16U, 144U, 256U, 416U, 528U, 688U, 848U, 1072U, 1280U, 1360U,
    1488U, 1552U, 1584U, 1600U, 0U, 0U, 0U, 128U, 240U, 384U, 496U, 656U, 816U,
    1024U, 1264U, 1360U, 1472U, 1536U, 1584U, 1600U, 0U, 0U, 0U, 112U, 208U,
    352U, 464U, 624U, 784U, 976U, 1200U, 1280U, 1440U, 1520U, 1568U, 1600U, 0U,
    0U, 0U, 96U, 176U, 320U, 432U, 592U, 752U, 928U, 1104U, 1200U, 1360U, 1456U,
    1536U, 1600U, 0U, 0U, 0U, 80U, 160U, 288U, 400U, 560U, 720U, 880U, 1040U,
    1120U, 1280U, 1440U, 1520U, 1600U
} ;                                    /* Sport模式D挡峰值扭矩百分比amp-百分比 */

CAL_TQM uint16_T MTQD_PedalMapClutchMode_Fifth_pct[192] =
{
    0U, 32U, 80U, 160U, 288U, 480U, 640U, 800U, 960U, 1120U, 1280U, 1360U, 1488U,
    1568U, 1600U, 1600U, 0U, 32U, 80U, 160U, 288U, 480U, 640U, 800U, 960U, 1120U,
    1280U, 1360U, 1488U, 1568U, 1600U, 1600U, 0U, 32U, 80U, 160U, 288U, 480U,
    640U, 800U, 960U, 1120U, 1280U, 1360U, 1488U, 1568U, 1600U, 1600U, 0U, 16U,
    80U, 160U, 288U, 480U, 640U, 800U, 960U, 1120U, 1280U, 1360U, 1488U, 1568U,
    1600U, 1600U, 0U, 0U, 64U, 160U, 288U, 480U, 640U, 800U, 944U, 1120U, 1280U,
    1360U, 1488U, 1568U, 1584U, 1600U, 0U, 0U, 48U, 160U, 288U, 480U, 608U, 784U,
    912U, 1120U, 1280U, 1360U, 1488U, 1568U, 1584U, 1600U, 0U, 0U, 32U, 160U,
    272U, 448U, 576U, 752U, 880U, 1120U, 1280U, 1360U, 1488U, 1568U, 1584U,
    1600U, 0U, 0U, 16U, 144U, 256U, 416U, 528U, 688U, 848U, 1072U, 1280U, 1360U,
    1488U, 1552U, 1584U, 1600U, 0U, 0U, 0U, 128U, 240U, 384U, 496U, 656U, 816U,
    1024U, 1264U, 1360U, 1472U, 1536U, 1584U, 1600U, 0U, 0U, 0U, 112U, 208U,
    352U, 464U, 624U, 784U, 976U, 1200U, 1280U, 1440U, 1520U, 1568U, 1600U, 0U,
    0U, 0U, 96U, 176U, 320U, 432U, 592U, 752U, 928U, 1104U, 1200U, 1360U, 1456U,
    1536U, 1600U, 0U, 0U, 0U, 80U, 160U, 288U, 400U, 560U, 720U, 880U, 1040U,
    1120U, 1280U, 1440U, 1520U, 1600U
} ;                                    /* 手动挡车型D5挡扭矩百分比amp-百分比 */

CAL_TQM uint16_T MTQD_PedalMapClutchMode_First_pct[192] =
{
    0U, 32U, 80U, 160U, 288U, 480U, 640U, 800U, 960U, 1120U, 1280U, 1360U, 1488U,
    1568U, 1600U, 1600U, 0U, 32U, 80U, 160U, 288U, 480U, 640U, 800U, 960U, 1120U,
    1280U, 1360U, 1488U, 1568U, 1600U, 1600U, 0U, 32U, 80U, 160U, 288U, 480U,
    640U, 800U, 960U, 1120U, 1280U, 1360U, 1488U, 1568U, 1600U, 1600U, 0U, 16U,
    80U, 160U, 288U, 480U, 640U, 800U, 960U, 1120U, 1280U, 1360U, 1488U, 1568U,
    1600U, 1600U, 0U, 0U, 64U, 160U, 288U, 480U, 640U, 800U, 944U, 1120U, 1280U,
    1360U, 1488U, 1568U, 1584U, 1600U, 0U, 0U, 48U, 160U, 288U, 480U, 608U, 784U,
    912U, 1120U, 1280U, 1360U, 1488U, 1568U, 1584U, 1600U, 0U, 0U, 32U, 160U,
    272U, 448U, 576U, 752U, 880U, 1120U, 1280U, 1360U, 1488U, 1568U, 1584U,
    1600U, 0U, 0U, 16U, 144U, 256U, 416U, 528U, 688U, 848U, 1072U, 1280U, 1360U,
    1488U, 1552U, 1584U, 1600U, 0U, 0U, 0U, 128U, 240U, 384U, 496U, 656U, 816U,
    1024U, 1264U, 1360U, 1472U, 1536U, 1584U, 1600U, 0U, 0U, 0U, 112U, 208U,
    352U, 464U, 624U, 784U, 976U, 1200U, 1280U, 1440U, 1520U, 1568U, 1600U, 0U,
    0U, 0U, 96U, 176U, 320U, 432U, 592U, 752U, 928U, 1104U, 1200U, 1360U, 1456U,
    1536U, 1600U, 0U, 0U, 0U, 80U, 160U, 288U, 400U, 560U, 720U, 880U, 1040U,
    1120U, 1280U, 1440U, 1520U, 1600U
} ;                                    /* 手动挡车型D1挡扭矩百分比amp-百分比 */

CAL_TQM uint16_T MTQD_PedalMapClutchMode_Fourth_pct[192] =
{
    0U, 32U, 80U, 160U, 288U, 480U, 640U, 800U, 960U, 1120U, 1280U, 1360U, 1488U,
    1568U, 1600U, 1600U, 0U, 32U, 80U, 160U, 288U, 480U, 640U, 800U, 960U, 1120U,
    1280U, 1360U, 1488U, 1568U, 1600U, 1600U, 0U, 32U, 80U, 160U, 288U, 480U,
    640U, 800U, 960U, 1120U, 1280U, 1360U, 1488U, 1568U, 1600U, 1600U, 0U, 16U,
    80U, 160U, 288U, 480U, 640U, 800U, 960U, 1120U, 1280U, 1360U, 1488U, 1568U,
    1600U, 1600U, 0U, 0U, 64U, 160U, 288U, 480U, 640U, 800U, 944U, 1120U, 1280U,
    1360U, 1488U, 1568U, 1584U, 1600U, 0U, 0U, 48U, 160U, 288U, 480U, 608U, 784U,
    912U, 1120U, 1280U, 1360U, 1488U, 1568U, 1584U, 1600U, 0U, 0U, 32U, 160U,
    272U, 448U, 576U, 752U, 880U, 1120U, 1280U, 1360U, 1488U, 1568U, 1584U,
    1600U, 0U, 0U, 16U, 144U, 256U, 416U, 528U, 688U, 848U, 1072U, 1280U, 1360U,
    1488U, 1552U, 1584U, 1600U, 0U, 0U, 0U, 128U, 240U, 384U, 496U, 656U, 816U,
    1024U, 1264U, 1360U, 1472U, 1536U, 1584U, 1600U, 0U, 0U, 0U, 112U, 208U,
    352U, 464U, 624U, 784U, 976U, 1200U, 1280U, 1440U, 1520U, 1568U, 1600U, 0U,
    0U, 0U, 96U, 176U, 320U, 432U, 592U, 752U, 928U, 1104U, 1200U, 1360U, 1456U,
    1536U, 1600U, 0U, 0U, 0U, 80U, 160U, 288U, 400U, 560U, 720U, 880U, 1040U,
    1120U, 1280U, 1440U, 1520U, 1600U
} ;                                    /* 手动挡车型D4挡扭矩百分比amp-百分比 */

CAL_TQM uint16_T MTQD_PedalMapClutchMode_Second_pct[192] =
{
    0U, 32U, 80U, 160U, 288U, 480U, 640U, 800U, 960U, 1120U, 1280U, 1360U, 1488U,
    1568U, 1600U, 1600U, 0U, 32U, 80U, 160U, 288U, 480U, 640U, 800U, 960U, 1120U,
    1280U, 1360U, 1488U, 1568U, 1600U, 1600U, 0U, 32U, 80U, 160U, 288U, 480U,
    640U, 800U, 960U, 1120U, 1280U, 1360U, 1488U, 1568U, 1600U, 1600U, 0U, 16U,
    80U, 160U, 288U, 480U, 640U, 800U, 960U, 1120U, 1280U, 1360U, 1488U, 1568U,
    1600U, 1600U, 0U, 0U, 64U, 160U, 288U, 480U, 640U, 800U, 944U, 1120U, 1280U,
    1360U, 1488U, 1568U, 1584U, 1600U, 0U, 0U, 48U, 160U, 288U, 480U, 608U, 784U,
    912U, 1120U, 1280U, 1360U, 1488U, 1568U, 1584U, 1600U, 0U, 0U, 32U, 160U,
    272U, 448U, 576U, 752U, 880U, 1120U, 1280U, 1360U, 1488U, 1568U, 1584U,
    1600U, 0U, 0U, 16U, 144U, 256U, 416U, 528U, 688U, 848U, 1072U, 1280U, 1360U,
    1488U, 1552U, 1584U, 1600U, 0U, 0U, 0U, 128U, 240U, 384U, 496U, 656U, 816U,
    1024U, 1264U, 1360U, 1472U, 1536U, 1584U, 1600U, 0U, 0U, 0U, 112U, 208U,
    352U, 464U, 624U, 784U, 976U, 1200U, 1280U, 1440U, 1520U, 1568U, 1600U, 0U,
    0U, 0U, 96U, 176U, 320U, 432U, 592U, 752U, 928U, 1104U, 1200U, 1360U, 1456U,
    1536U, 1600U, 0U, 0U, 0U, 80U, 160U, 288U, 400U, 560U, 720U, 880U, 1040U,
    1120U, 1280U, 1440U, 1520U, 1600U
} ;                                    /* 手动挡车型D2挡扭矩百分比amp-百分比 */

CAL_TQM uint16_T MTQD_PedalMapClutchMode_Third_pct[192] =
{
    0U, 32U, 80U, 160U, 288U, 480U, 640U, 800U, 960U, 1120U, 1280U, 1360U, 1488U,
    1568U, 1600U, 1600U, 0U, 32U, 80U, 160U, 288U, 480U, 640U, 800U, 960U, 1120U,
    1280U, 1360U, 1488U, 1568U, 1600U, 1600U, 0U, 32U, 80U, 160U, 288U, 480U,
    640U, 800U, 960U, 1120U, 1280U, 1360U, 1488U, 1568U, 1600U, 1600U, 0U, 16U,
    80U, 160U, 288U, 480U, 640U, 800U, 960U, 1120U, 1280U, 1360U, 1488U, 1568U,
    1600U, 1600U, 0U, 0U, 64U, 160U, 288U, 480U, 640U, 800U, 944U, 1120U, 1280U,
    1360U, 1488U, 1568U, 1584U, 1600U, 0U, 0U, 48U, 160U, 288U, 480U, 608U, 784U,
    912U, 1120U, 1280U, 1360U, 1488U, 1568U, 1584U, 1600U, 0U, 0U, 32U, 160U,
    272U, 448U, 576U, 752U, 880U, 1120U, 1280U, 1360U, 1488U, 1568U, 1584U,
    1600U, 0U, 0U, 16U, 144U, 256U, 416U, 528U, 688U, 848U, 1072U, 1280U, 1360U,
    1488U, 1552U, 1584U, 1600U, 0U, 0U, 0U, 128U, 240U, 384U, 496U, 656U, 816U,
    1024U, 1264U, 1360U, 1472U, 1536U, 1584U, 1600U, 0U, 0U, 0U, 112U, 208U,
    352U, 464U, 624U, 784U, 976U, 1200U, 1280U, 1440U, 1520U, 1568U, 1600U, 0U,
    0U, 0U, 96U, 176U, 320U, 432U, 592U, 752U, 928U, 1104U, 1200U, 1360U, 1456U,
    1536U, 1600U, 0U, 0U, 0U, 80U, 160U, 288U, 400U, 560U, 720U, 880U, 1040U,
    1120U, 1280U, 1440U, 1520U, 1600U
} ;                                    /* 手动挡车型D3挡扭矩百分比amp-百分比 */

CAL_TQM uint16_T MTQD_PedalMapRevAccpedal_ClutchMode_pct[16] =
{
    0U, 80U, 160U, 320U, 480U, 640U, 720U, 800U, 880U, 960U, 1040U, 1120U, 1280U,
    1440U, 1520U, 1600U
} ;                                    /* 手动挡车型R挡峰值扭矩百分比amp-加速踏板开度 */

CAL_TQM uint16_T MTQD_PedalMapRevAccpedal_X_pct[16] =
{
    0U, 80U, 160U, 320U, 480U, 640U, 720U, 800U, 880U, 960U, 1040U, 1120U, 1280U,
    1440U, 1520U, 1600U
} ;                                    /* R挡峰值扭矩百分比amp-加速踏板开度 */

CAL_TQM uint16_T MTQD_PedalMapRevTmSpeed_ClutchMode_rpm[12] =
{
    500U, 1000U, 1500U, 1850U, 2250U, 3000U, 3750U, 4500U, 6000U, 7500U, 9000U,
    10500U
} ;                                    /* 手动挡车型R挡峰值扭矩百分比amp-转速 */

CAL_TQM uint16_T MTQD_PedalMapRevTmSpeed_Y_rpm[12] =
{
    500U, 1000U, 1500U, 1850U, 2250U, 3000U, 3750U, 4500U, 6000U, 7500U, 9000U,
    10500U
} ;                                    /* R挡峰值扭矩百分比amp-转速 */

CAL_TQM uint16_T MTQD_PedalMapRev_ClutchMode_pct[192] =
{
    0U, 32U, 80U, 160U, 240U, 320U, 352U, 400U, 432U, 480U, 640U, 800U, 960U,
    1280U, 1600U, 1600U, 0U, 32U, 80U, 160U, 240U, 320U, 352U, 400U, 432U, 480U,
    640U, 800U, 960U, 1280U, 1600U, 1600U, 0U, 32U, 80U, 160U, 240U, 320U, 352U,
    400U, 432U, 480U, 640U, 800U, 960U, 1280U, 1600U, 1600U, 0U, 16U, 80U, 160U,
    240U, 320U, 352U, 400U, 432U, 480U, 640U, 800U, 960U, 1280U, 1600U, 1600U,
    0U, 0U, 64U, 160U, 240U, 320U, 352U, 400U, 432U, 480U, 640U, 800U, 960U,
    1280U, 1584U, 1600U, 0U, 0U, 48U, 160U, 240U, 320U, 336U, 384U, 432U, 480U,
    640U, 800U, 960U, 1280U, 1584U, 1600U, 0U, 0U, 32U, 160U, 224U, 304U, 320U,
    368U, 416U, 480U, 640U, 800U, 960U, 1280U, 1584U, 1600U, 0U, 0U, 16U, 144U,
    208U, 288U, 320U, 352U, 400U, 464U, 640U, 800U, 944U, 1264U, 1584U, 1600U,
    0U, 0U, 0U, 128U, 192U, 272U, 320U, 336U, 384U, 448U, 624U, 800U, 928U,
    1248U, 1584U, 1600U, 0U, 0U, 0U, 112U, 176U, 256U, 304U, 336U, 368U, 432U,
    608U, 784U, 912U, 1232U, 1568U, 1600U, 0U, 0U, 0U, 96U, 144U, 240U, 288U,
    320U, 352U, 416U, 592U, 768U, 896U, 1216U, 1536U, 1600U, 0U, 0U, 0U, 80U,
    128U, 224U, 272U, 304U, 336U, 400U, 576U, 752U, 880U, 1040U, 1520U, 1600U
} ;                                    /* 手动挡车型R挡扭矩百分比amp-百分比 */

CAL_TQM uint16_T MTQD_PedalMapRev_pct[192] =
{
    0U, 32U, 80U, 160U, 240U, 320U, 352U, 400U, 432U, 480U, 640U, 800U, 960U,
    1280U, 1600U, 1600U, 0U, 32U, 80U, 160U, 240U, 320U, 352U, 400U, 432U, 480U,
    640U, 800U, 960U, 1280U, 1600U, 1600U, 0U, 32U, 80U, 160U, 240U, 320U, 352U,
    400U, 432U, 480U, 640U, 800U, 960U, 1280U, 1600U, 1600U, 0U, 16U, 80U, 160U,
    240U, 320U, 352U, 400U, 432U, 480U, 640U, 800U, 960U, 1280U, 1600U, 1600U,
    0U, 0U, 64U, 160U, 240U, 320U, 352U, 400U, 432U, 480U, 640U, 800U, 960U,
    1280U, 1584U, 1600U, 0U, 0U, 48U, 160U, 240U, 320U, 336U, 384U, 432U, 480U,
    640U, 800U, 960U, 1280U, 1584U, 1600U, 0U, 0U, 32U, 160U, 224U, 304U, 320U,
    368U, 416U, 480U, 640U, 800U, 960U, 1280U, 1584U, 1600U, 0U, 0U, 16U, 144U,
    208U, 288U, 320U, 352U, 400U, 464U, 640U, 800U, 944U, 1264U, 1584U, 1600U,
    0U, 0U, 0U, 128U, 192U, 272U, 320U, 336U, 384U, 448U, 624U, 800U, 928U,
    1248U, 1584U, 1600U, 0U, 0U, 0U, 112U, 176U, 256U, 304U, 336U, 368U, 432U,
    608U, 784U, 912U, 1232U, 1568U, 1600U, 0U, 0U, 0U, 96U, 144U, 240U, 288U,
    320U, 352U, 416U, 592U, 768U, 896U, 1216U, 1536U, 1600U, 0U, 0U, 0U, 80U,
    128U, 224U, 272U, 304U, 336U, 400U, 576U, 752U, 880U, 1040U, 1520U, 1600U
} ;                                    /* R挡峰值扭矩百分比amp-百分比 */

CAL_TQM uint16_T MTQD_PedalMapTmSpeed_ClutchMode_rpm[12] =
{
    500U, 1000U, 1500U, 1850U, 2250U, 3000U, 3750U, 4500U, 6000U, 7500U, 9000U,
    10500U
} ;                                    /* 手动挡车型D挡峰值扭矩百分比amp-转速 */

CAL_TQM uint16_T MTQD_TqMapPeakTmSpeed_X_rpm[22] =
{
    0U, 493U, 1030U, 1500U, 2010U, 2510U, 3000U, 3490U, 4090U, 4540U, 5080U,
    5510U, 5960U, 6450U, 6880U, 7400U, 7930U, 8380U, 9020U, 10000U, 11000U,
    12000U
} ;                                    /* 电机外特性map-转速 */

CAL_TQM int16_T MTQD_TqMapPeakTq_Nm[22] =
{
    280, 280, 280, 280, 280, 280, 280, 246, 210, 189, 169, 155, 144, 133, 124,
    116, 108, 102, 95, 85, 0, 0
} ;                                    /* 电机外特性map-扭矩 */

CAL_TQM uint16_T MTQD_TqMapRevTmSpeed_X_rpm[22] =
{
    0U, 493U, 1030U, 1500U, 2010U, 2510U, 3000U, 3490U, 4090U, 4540U, 5080U,
    5510U, 5960U, 6450U, 6880U, 7400U, 7930U, 8380U, 9020U, 10000U, 11000U,
    12000U
} ;                                    /* R挡峰值扭矩map-转速 */

CAL_TQM int16_T MTQD_TqMapRevTq_Nm[22] =
{
    280, 280, 280, 280, 280, 280, 280, 246, 210, 189, 169, 155, 144, 133, 124,
    116, 108, 102, 95, 85, 0, 0
} ;                                    /* R挡峰值扭矩map-扭矩 */

CAL_TQM uint16_T PTT_MotDriveEffi_Pct[182] =
{
    19164U, 21670U, 22246U, 22682U, 22554U, 22415U, 22272U, 21949U, 21309U,
    20429U, 19318U, 18624U, 17559U, 19802U, 21670U, 22246U, 22682U, 22554U,
    22415U, 22272U, 21949U, 21309U, 20429U, 19318U, 18624U, 17559U, 19850U,
    22144U, 22758U, 22682U, 22554U, 22415U, 22272U, 21949U, 21309U, 20429U,
    19318U, 18624U, 17559U, 19080U, 22042U, 23398U, 23475U, 23401U, 23183U,
    22886U, 21949U, 21309U, 20429U, 19318U, 18624U, 17559U, 18097U, 21811U,
    23460U, 23767U, 23846U, 23811U, 23398U, 22436U, 21780U, 21046U, 19318U,
    18624U, 17559U, 17093U, 21504U, 23424U, 23836U, 24038U, 24003U, 23821U,
    22922U, 22321U, 21617U, 20155U, 19448U, 18696U, 16630U, 21274U, 23419U,
    23872U, 24095U, 24077U, 23905U, 23163U, 22643U, 21924U, 20521U, 19886U,
    19123U, 16630U, 21939U, 23309U, 23921U, 24197U, 24218U, 24125U, 23475U,
    23117U, 22564U, 21827U, 21199U, 20403U, 16630U, 20608U, 23073U, 23903U,
    24243U, 24358U, 24225U, 23764U, 23429U, 22986U, 22198U, 21791U, 21248U,
    16630U, 20608U, 22715U, 23770U, 24253U, 24387U, 24279U, 23900U, 23575U,
    23227U, 22554U, 22287U, 21786U, 16630U, 20608U, 22298U, 23718U, 24228U,
    24379U, 24233U, 23918U, 23665U, 23281U, 22700U, 22408U, 21921U, 16630U,
    20608U, 21888U, 23478U, 24161U, 24325U, 24228U, 23921U, 23672U, 23327U,
    22804U, 22548U, 21939U, 16630U, 20608U, 21888U, 23296U, 24067U, 24261U,
    24172U, 23788U, 23639U, 23373U, 23291U, 22712U, 22413U, 16630U, 20608U,
    21888U, 23040U, 23992U, 24172U, 24008U, 23703U, 23296U, 23373U, 23291U,
    22712U, 22413U
} ;                                    /* 驱动系统放电效率map-效率 */

CAL_TQM uint16_T PTT_MotDriveEffi_Power[14] =
{
    68U, 128U, 326U, 685U, 1015U, 1323U, 1491U, 1989U, 2644U, 3416U, 3863U,
    4563U, 5467U, 6186U
} ;                                    /* 驱动系统放电效率map-功率 */

CAL_TQM uint16_T PTT_MotDriveEffi_Spd[13] =
{
    500U, 1000U, 2000U, 3000U, 4000U, 5000U, 6000U, 7000U, 7500U, 8000U, 9000U,
    9500U, 10000U
} ;                                    /* 驱动系统放电效率map-转速 */

CAL_TQM uint16_T PTT_MotRegenEffi_Pct[182] =
{
    19164U, 21670U, 22246U, 22682U, 22554U, 22415U, 22272U, 21949U, 21309U,
    20429U, 19318U, 18624U, 17559U, 19802U, 21670U, 22246U, 22682U, 22554U,
    22415U, 22272U, 21949U, 21309U, 20429U, 19318U, 18624U, 17559U, 19850U,
    22144U, 22758U, 22682U, 22554U, 22415U, 22272U, 21949U, 21309U, 20429U,
    19318U, 18624U, 17559U, 19080U, 22042U, 23398U, 23475U, 23401U, 23183U,
    22886U, 21949U, 21309U, 20429U, 19318U, 18624U, 17559U, 18097U, 21811U,
    23460U, 23767U, 23846U, 23811U, 23398U, 22436U, 21780U, 21046U, 19318U,
    18624U, 17559U, 17093U, 21504U, 23424U, 23836U, 24038U, 24003U, 23821U,
    22922U, 22321U, 21617U, 20155U, 19448U, 18696U, 16630U, 21274U, 23419U,
    23872U, 24095U, 24077U, 23905U, 23163U, 22643U, 21924U, 20521U, 19886U,
    19123U, 16630U, 21939U, 23309U, 23921U, 24197U, 24218U, 24125U, 23475U,
    23117U, 22564U, 21827U, 21199U, 20403U, 16630U, 20608U, 23073U, 23903U,
    24243U, 24358U, 24225U, 23764U, 23429U, 22986U, 22198U, 21791U, 21248U,
    16630U, 20608U, 22715U, 23770U, 24253U, 24387U, 24279U, 23900U, 23575U,
    23227U, 22554U, 22287U, 21786U, 16630U, 20608U, 22298U, 23718U, 24228U,
    24379U, 24233U, 23918U, 23665U, 23281U, 22700U, 22408U, 21921U, 16630U,
    20608U, 21888U, 23478U, 24161U, 24325U, 24228U, 23921U, 23672U, 23327U,
    22804U, 22548U, 21939U, 16630U, 20608U, 21888U, 23296U, 24067U, 24261U,
    24172U, 23788U, 23639U, 23373U, 23291U, 22712U, 22413U, 16630U, 20608U,
    21888U, 23040U, 23992U, 24172U, 24008U, 23703U, 23296U, 23373U, 23291U,
    22712U, 22413U
} ;                                    /* 驱动系统发电效率map-效率 */

CAL_TQM uint16_T PTT_MotRegenEffi_Power[14] =
{
    68U, 128U, 326U, 685U, 1015U, 1323U, 1491U, 1989U, 2644U, 3416U, 3863U,
    4563U, 5467U, 6186U
} ;                                    /* 驱动系统发电效率map-功率 */

CAL_TQM uint16_T PTT_MotRegenEffi_Spd[13] =
{
    500U, 1000U, 2000U, 3000U, 4000U, 5000U, 6000U, 7000U, 7500U, 8000U, 9000U,
    9500U, 10000U
} ;                                    /* 驱动系统发电效率map-转速 */

CAL_TQM uint16_T P_Delay_time = 150U;  /* 进P档等待EPB夹驻时间 */
CAL_TQM uint8_T Period = 20U;          /* 模型运行时间-ms */
CAL_TQM uint16_T REC_No_Evflag_TrueDelay = 81U;/* 禁止能量回收标志持续时间判断-持续时间大于该值才认为有效（新增） */
CAL_TQM uint8_T REC_RegenEnaAccePct_Cal = 4U;/* 加速踏板开度大于该值时复位能量回收标志 */
CAL_TQM uint8_T REC_RegenEnaSpd_Cal = 5U;/* 车速低于该值时复位能量回收标志 */
CAL_TQM uint16_T RampExecTime = 20U;   /* 斜率限制部分周期时间 */
CAL_TQM uint8_T Reverse = 2U;          /* 电机反转标志 */
CAL_TQM uint8_T SpeedAccelBuffer = 2U;
CAL_TQM uint8_T SpeedAccel_Alpha = 1U;
CAL_TQM uint8_T Sport_Mode = 2U;       /* 运动模式标志 */
CAL_TQM uint8_T Standstill = 0U;       /* 电机静止标志 */
CAL_TQM boolean_T TQD_FALSE = 0;
CAL_TQM boolean_T TQD_TRUE = 1;
CAL_TQM int8_T TQD_integral_reset_value = 0;/* i部分扭矩计算重置值 */
CAL_TQM int16_T TQD_max_dmd = 30;      /* i部分计算上限扭矩 */
CAL_TQM int16_T TQD_min_dmd = -30;     /* i部分计算下限扭矩 */
CAL_TQM uint16_T TQF_DriveDecDistance_Filter1 = 50U;/* 斜率1 */
CAL_TQM uint16_T TQF_DriveDecDistance_Filter2 = 150U;/* 斜率2 */
CAL_TQM uint16_T TQF_DriveDecDistance_Filter3 = 300U;/* 斜率3 */
CAL_TQM uint16_T TQF_DriveDecDistance_Filter4 = 500U;/* 斜率4 */
CAL_TQM uint16_T TQF_DriveDecDistance_Filter5 = 800U;/* 斜率5 */
CAL_TQM uint16_T TQF_DriveDecDistance_Filter6 = 1000U;/* 斜率6（新增） */
CAL_TQM uint16_T TQF_DriveDecDistance_Filter7 = 1000U;/* 斜率7（新增） */
CAL_TQM uint16_T TQF_DriveDecDistance_Filter8 = 1000U;/* 斜率8（新增） */
CAL_TQM uint16_T TQF_DriveDecTq1 = 3U; /* 输出扭矩1 */
CAL_TQM uint16_T TQF_DriveDecTq2 = 5U; /* 输出扭矩2 */
CAL_TQM uint16_T TQF_DriveDecTq3 = 10U;/* 输出扭矩3 */
CAL_TQM uint16_T TQF_DriveDecTq4 = 20U;/* 输出扭矩4 */
CAL_TQM uint16_T TQF_DriveDecTq5 = 1000U;/* 输出扭矩5（新增） */
CAL_TQM uint16_T TQF_DriveDecTq6 = 1000U;/* 输出扭矩6（新增） */
CAL_TQM uint16_T TQF_DriveDecTq7 = 1000U;/* 输出扭矩7（新增） */
CAL_TQM uint16_T TQF_DriveDecTqDistance1 = 5U;/* 需求扭矩与输出扭矩差值1 */
CAL_TQM uint16_T TQF_DriveDecTqDistance2 = 10U;/* 需求扭矩与输出扭矩差值2 */
CAL_TQM uint16_T TQF_DriveDecTqDistance3 = 20U;/* 需求扭矩与输出扭矩差值3 */
CAL_TQM uint16_T TQF_DriveDecTqDistance4 = 30U;/* 需求扭矩与输出扭矩差值4 */
CAL_TQM uint16_T TQF_DriveDecTqDistance5 = 1000U;/* 需求扭矩与输出扭矩差值5（新增） */
CAL_TQM uint16_T TQF_DriveDecTqDistance6 = 1000U;/* 需求扭矩与输出扭矩差值6（新增） */
CAL_TQM uint16_T TQF_DriveDecTqDistance7 = 1000U;/* 需求扭矩与输出扭矩差值7（新增） */
CAL_TQM uint16_T TQF_DriveDec_Filter1 = 100U;/* 斜率1 */
CAL_TQM uint16_T TQF_DriveDec_Filter2 = 200U;/* 斜率2 */
CAL_TQM uint16_T TQF_DriveDec_Filter3 = 300U;/* 斜率3 */
CAL_TQM uint16_T TQF_DriveDec_Filter4 = 500U;/* 斜率4 */
CAL_TQM uint16_T TQF_DriveDec_Filter5 = 800U;/* 斜率5 */
CAL_TQM uint16_T TQF_DriveDec_Filter6 = 1000U;/* 斜率6（新增） */
CAL_TQM uint16_T TQF_DriveDec_Filter7 = 1000U;/* 斜率7（新增） */
CAL_TQM uint16_T TQF_DriveDec_Filter8 = 1000U;/* 斜率8（新增） */
CAL_TQM uint16_T TQF_DriveIncDistance_Filter1 = 50U;/* 斜率1 */
CAL_TQM uint16_T TQF_DriveIncDistance_Filter2 = 100U;/* 斜率2 */
CAL_TQM uint16_T TQF_DriveIncDistance_Filter3 = 200U;/* 斜率3 */
CAL_TQM uint16_T TQF_DriveIncDistance_Filter4 = 300U;/* 斜率4 */
CAL_TQM uint16_T TQF_DriveIncDistance_Filter5 = 400U;/* 斜率5 */
CAL_TQM uint16_T TQF_DriveIncDistance_Filter6 = 1000U;/* 斜率6（新增） */
CAL_TQM uint16_T TQF_DriveIncDistance_Filter7 = 1000U;/* 斜率7（新增） */
CAL_TQM uint16_T TQF_DriveIncDistance_Filter8 = 1000U;/* 斜率8（新增） */
CAL_TQM uint16_T TQF_DriveIncTq1 = 3U; /* 输出扭矩1 */
CAL_TQM uint16_T TQF_DriveIncTq2 = 5U; /* 输出扭矩2 */
CAL_TQM uint16_T TQF_DriveIncTq3 = 10U;/* 输出扭矩3 */
CAL_TQM uint16_T TQF_DriveIncTq4 = 20U;/* 输出扭矩4 */
CAL_TQM uint16_T TQF_DriveIncTq5 = 1000U;/* 输出扭矩5（新增） */
CAL_TQM uint16_T TQF_DriveIncTq6 = 1000U;/* 输出扭矩6（新增） */
CAL_TQM uint16_T TQF_DriveIncTq7 = 1000U;/* 输出扭矩7（新增） */
CAL_TQM uint16_T TQF_DriveIncTqDistance1 = 5U;/* 需求扭矩与输出扭矩差值1 */
CAL_TQM uint16_T TQF_DriveIncTqDistance2 = 10U;/* 需求扭矩与输出扭矩差值2 */
CAL_TQM uint16_T TQF_DriveIncTqDistance3 = 20U;/* 需求扭矩与输出扭矩差值3 */
CAL_TQM uint16_T TQF_DriveIncTqDistance4 = 40U;/* 需求扭矩与输出扭矩差值4 */
CAL_TQM uint16_T TQF_DriveIncTqDistance5 = 1000U;/* 需求扭矩与输出扭矩差值5（新增） */
CAL_TQM uint16_T TQF_DriveIncTqDistance6 = 1000U;/* 需求扭矩与输出扭矩差值6（新增） */
CAL_TQM uint16_T TQF_DriveIncTqDistance7 = 1000U;/* 需求扭矩与输出扭矩差值7（新增） */
CAL_TQM uint16_T TQF_DriveInc_Filter1 = 50U;/* 斜率1 */
CAL_TQM uint16_T TQF_DriveInc_Filter2 = 100U;/* 斜率2 */
CAL_TQM uint16_T TQF_DriveInc_Filter3 = 200U;/* 斜率3 */
CAL_TQM uint16_T TQF_DriveInc_Filter4 = 300U;/* 斜率4 */
CAL_TQM uint16_T TQF_DriveInc_Filter5 = 400U;/* 斜率5 */
CAL_TQM uint16_T TQF_DriveInc_Filter6 = 1000U;/* 斜率6（新增） */
CAL_TQM uint16_T TQF_DriveInc_Filter7 = 1000U;/* 斜率7（新增） */
CAL_TQM uint16_T TQF_DriveInc_Filter8 = 1000U;/* 斜率8（新增） */
CAL_TQM uint16_T TQF_EcoDriveIncDistance_Filter1 = 50U;/* 斜率1 */
CAL_TQM uint16_T TQF_EcoDriveIncDistance_Filter2 = 100U;/* 斜率2 */
CAL_TQM uint16_T TQF_EcoDriveIncDistance_Filter3 = 150U;/* 斜率3 */
CAL_TQM uint16_T TQF_EcoDriveIncDistance_Filter4 = 200U;/* 斜率4 */
CAL_TQM uint16_T TQF_EcoDriveIncDistance_Filter5 = 300U;/* 斜率5 */
CAL_TQM uint16_T TQF_EcoDriveIncDistance_Filter6 = 1000U;/* 斜率6（新增） */
CAL_TQM uint16_T TQF_EcoDriveIncDistance_Filter7 = 1000U;/* 斜率7（新增） */
CAL_TQM uint16_T TQF_EcoDriveIncDistance_Filter8 = 1000U;/* 斜率8（新增） */
CAL_TQM uint16_T TQF_EcoDriveIncTq1 = 3U;/* 输出扭矩1 */
CAL_TQM uint16_T TQF_EcoDriveIncTq2 = 5U;/* 输出扭矩2 */
CAL_TQM uint16_T TQF_EcoDriveIncTq3 = 10U;/* 输出扭矩3 */
CAL_TQM uint16_T TQF_EcoDriveIncTq4 = 20U;/* 输出扭矩4 */
CAL_TQM uint16_T TQF_EcoDriveIncTq5 = 1000U;/* 输出扭矩5（新增） */
CAL_TQM uint16_T TQF_EcoDriveIncTq6 = 1000U;/* 输出扭矩6（新增） */
CAL_TQM uint16_T TQF_EcoDriveIncTq7 = 1000U;/* 输出扭矩7（新增） */
CAL_TQM uint16_T TQF_EcoDriveIncTqDistance1 = 5U;/* 需求扭矩与输出扭矩差值1 */
CAL_TQM uint16_T TQF_EcoDriveIncTqDistance2 = 10U;/* 需求扭矩与输出扭矩差值2 */
CAL_TQM uint16_T TQF_EcoDriveIncTqDistance3 = 20U;/* 需求扭矩与输出扭矩差值3 */
CAL_TQM uint16_T TQF_EcoDriveIncTqDistance4 = 50U;/* 需求扭矩与输出扭矩差值4 */
CAL_TQM uint16_T TQF_EcoDriveIncTqDistance5 = 1000U;/* 需求扭矩与输出扭矩差值5（新增） */
CAL_TQM uint16_T TQF_EcoDriveIncTqDistance6 = 1000U;/* 需求扭矩与输出扭矩差值6（新增） */
CAL_TQM uint16_T TQF_EcoDriveIncTqDistance7 = 1000U;/* 需求扭矩与输出扭矩差值7（新增） */
CAL_TQM uint16_T TQF_EcoDriveInc_Filter1 = 50U;/* 斜率1 */
CAL_TQM uint16_T TQF_EcoDriveInc_Filter2 = 100U;/* 斜率2 */
CAL_TQM uint16_T TQF_EcoDriveInc_Filter3 = 200U;/* 斜率3 */
CAL_TQM uint16_T TQF_EcoDriveInc_Filter4 = 250U;/* 斜率4 */
CAL_TQM uint16_T TQF_EcoDriveInc_Filter5 = 400U;/* 斜率5 */
CAL_TQM uint16_T TQF_EcoDriveInc_Filter6 = 1000U;/* 斜率6（新增） */
CAL_TQM uint16_T TQF_EcoDriveInc_Filter7 = 1000U;/* 斜率7（新增） */
CAL_TQM uint16_T TQF_EcoDriveInc_Filter8 = 1000U;/* 斜率8（新增） */
CAL_TQM uint16_T TQF_RegenDecDistance_Filter1 = 50U;/* 斜率1 */
CAL_TQM uint16_T TQF_RegenDecDistance_Filter2 = 100U;/* 斜率2 */
CAL_TQM uint16_T TQF_RegenDecDistance_Filter3 = 200U;/* 斜率3 */
CAL_TQM uint16_T TQF_RegenDecDistance_Filter4 = 400U;/* 斜率4 */
CAL_TQM uint16_T TQF_RegenDecDistance_Filter5 = 600U;/* 斜率5 */
CAL_TQM uint16_T TQF_RegenDecDistance_Filter6 = 1000U;/* 斜率6（新增） */
CAL_TQM uint16_T TQF_RegenDecDistance_Filter7 = 1000U;/* 斜率7（新增） */
CAL_TQM uint16_T TQF_RegenDecDistance_Filter8 = 1000U;/* 斜率8（新增） */
CAL_TQM uint16_T TQF_RegenDecTq1 = 3U; /* 输出扭矩1 */
CAL_TQM uint16_T TQF_RegenDecTq2 = 5U; /* 输出扭矩2 */
CAL_TQM uint16_T TQF_RegenDecTq3 = 10U;/* 输出扭矩3 */
CAL_TQM uint16_T TQF_RegenDecTq4 = 20U;/* 输出扭矩4 */
CAL_TQM uint16_T TQF_RegenDecTq5 = 1000U;/* 输出扭矩5（新增） */
CAL_TQM uint16_T TQF_RegenDecTq6 = 1000U;/* 输出扭矩6（新增） */
CAL_TQM uint16_T TQF_RegenDecTq7 = 1000U;/* 输出扭矩7（新增） */
CAL_TQM uint16_T TQF_RegenDecTqDistance1 = 5U;/* 需求扭矩与输出扭矩差值1 */
CAL_TQM uint16_T TQF_RegenDecTqDistance2 = 10U;/* 需求扭矩与输出扭矩差值2 */
CAL_TQM uint16_T TQF_RegenDecTqDistance3 = 20U;/* 需求扭矩与输出扭矩差值3 */
CAL_TQM uint16_T TQF_RegenDecTqDistance4 = 30U;/* 需求扭矩与输出扭矩差值4 */
CAL_TQM uint16_T TQF_RegenDecTqDistance5 = 1000U;/* 需求扭矩与输出扭矩差值5（新增） */
CAL_TQM uint16_T TQF_RegenDecTqDistance6 = 1000U;/* 需求扭矩与输出扭矩差值6（新增） */
CAL_TQM uint16_T TQF_RegenDecTqDistance7 = 1000U;/* 需求扭矩与输出扭矩差值7（新增） */
CAL_TQM uint16_T TQF_RegenDec_Filter1 = 20U;/* 斜率1 */
CAL_TQM uint16_T TQF_RegenDec_Filter2 = 50U;/* 斜率2 */
CAL_TQM uint16_T TQF_RegenDec_Filter3 = 100U;/* 斜率3 */
CAL_TQM uint16_T TQF_RegenDec_Filter4 = 200U;/* 斜率4 */
CAL_TQM uint16_T TQF_RegenDec_Filter5 = 300U;/* 斜率5 */
CAL_TQM uint16_T TQF_RegenDec_Filter6 = 1000U;/* 斜率6（新增） */
CAL_TQM uint16_T TQF_RegenDec_Filter7 = 1000U;/* 斜率7（新增） */
CAL_TQM uint16_T TQF_RegenDec_Filter8 = 1000U;/* 斜率8（新增） */
CAL_TQM uint16_T TQF_RegenIncDistance_Filter1 = 50U;/* 斜率1 */
CAL_TQM uint16_T TQF_RegenIncDistance_Filter2 = 150U;/* 斜率2 */
CAL_TQM uint16_T TQF_RegenIncDistance_Filter3 = 300U;/* 斜率3 */
CAL_TQM uint16_T TQF_RegenIncDistance_Filter4 = 400U;/* 斜率4 */
CAL_TQM uint16_T TQF_RegenIncDistance_Filter5 = 600U;/* 斜率5 */
CAL_TQM uint16_T TQF_RegenIncDistance_Filter6 = 1000U;/* 斜率6（新增） */
CAL_TQM uint16_T TQF_RegenIncDistance_Filter7 = 1000U;/* 斜率7（新增） */
CAL_TQM uint16_T TQF_RegenIncDistance_Filter8 = 1000U;/* 斜率8（新增） */
CAL_TQM uint16_T TQF_RegenIncTq1 = 3U; /* 输出扭矩1 */
CAL_TQM uint16_T TQF_RegenIncTq2 = 5U; /* 输出扭矩2 */
CAL_TQM uint16_T TQF_RegenIncTq3 = 10U;/* 输出扭矩3 */
CAL_TQM uint16_T TQF_RegenIncTq4 = 20U;/* 输出扭矩4 */
CAL_TQM uint16_T TQF_RegenIncTq5 = 1000U;/* 输出扭矩5（新增） */
CAL_TQM uint16_T TQF_RegenIncTq6 = 1000U;/* 输出扭矩6（新增） */
CAL_TQM uint16_T TQF_RegenIncTq7 = 1000U;/* 输出扭矩7（新增） */
CAL_TQM uint16_T TQF_RegenIncTqDistance1 = 5U;/* 需求扭矩与输出扭矩差值1 */
CAL_TQM uint16_T TQF_RegenIncTqDistance2 = 10U;/* 需求扭矩与输出扭矩差值2 */
CAL_TQM uint16_T TQF_RegenIncTqDistance3 = 20U;/* 需求扭矩与输出扭矩差值3 */
CAL_TQM uint16_T TQF_RegenIncTqDistance4 = 30U;/* 需求扭矩与输出扭矩差值4 */
CAL_TQM uint16_T TQF_RegenIncTqDistance5 = 1000U;/* 需求扭矩与输出扭矩差值5（新增） */
CAL_TQM uint16_T TQF_RegenIncTqDistance6 = 1000U;/* 需求扭矩与输出扭矩差值6（新增） */
CAL_TQM uint16_T TQF_RegenIncTqDistance7 = 1000U;/* 需求扭矩与输出扭矩差值7（新增） */
CAL_TQM uint16_T TQF_RegenInc_Filter1 = 200U;/* 斜率1 */
CAL_TQM uint16_T TQF_RegenInc_Filter2 = 400U;/* 斜率2 */
CAL_TQM uint16_T TQF_RegenInc_Filter3 = 500U;/* 斜率3 */
CAL_TQM uint16_T TQF_RegenInc_Filter4 = 600U;/* 斜率4 */
CAL_TQM uint16_T TQF_RegenInc_Filter5 = 800U;/* 斜率5 */
CAL_TQM uint16_T TQF_RegenInc_Filter6 = 1000U;/* 斜率6（新增） */
CAL_TQM uint16_T TQF_RegenInc_Filter7 = 1000U;/* 斜率7（新增） */
CAL_TQM uint16_T TQF_RegenInc_Filter8 = 1000U;/* 斜率8（新增） */
CAL_TQM boolean_T TQF_TqFilteringEn_flg = 1;/* 扭矩斜率限制使能开关 */
CAL_TQM int16_T TQM_MaxTq_Cal = 280;   /* 系统最大允许输出扭矩 */
CAL_TQM uint16_T TQR_BMS_Delaytime = 50U;/* BMS三级故障时扭矩保持等待周期 */
CAL_TQM uint16_T TQR_MCU_Delaytime = 50U;/* MCU三级故障时扭矩保持等待周期 */
CAL_TQM uint16_T TSC_VehTq_Filter = 60U;/* 需求扭矩滤波系数 */
CAL_TQM uint16_T Tcl = 20U;            /* 软件运行周期 */
CAL_TQM uint32_T Tyre_Radius_Cal = 21194U;/* 车轮滚动半径 */
CAL_TQM uint16_T VAJ_AccePress_Fail = 32U;/* 加速踏板开度小于该值认为加速踏板松开 */
CAL_TQM uint16_T VAJ_AccePress_Succ = 64U;/* 加速踏板开度大于该值认为加速踏板踩下 */
CAL_TQM uint8_T VGJ_GearOff_Cal = 0U;  /* 挡位熄灭标志 */
CAL_TQM uint16_T VGJ_GearOff_time_Cal = 500U;/* 挡位闪烁时间-灭 */
CAL_TQM uint16_T VGJ_GearOn_time_Cal = 500U;/* 挡位闪烁时间-亮 */
CAL_TQM uint8_T VGJ_HigSpd_S11_Cal = 5U;/* S11换挡车速判断条件 */
CAL_TQM uint8_T VGJ_LowSpd_S11_Cal = 2U;/* S11换挡进入P档判断条件 */
CAL_TQM uint8_T VGJ_MidSpd_S11_Cal = 3U;/* S11低车速时不踩制动N档进入D、R车速条件 */
CAL_TQM uint16_T VGJ_Remind_time = 5000U;/* 挂挡文字提醒最大持续时间 */
CAL_TQM uint8_T VGJ_Spd_K11_Cal = 5U;  /* K11换挡车速判断条件 */
CAL_TQM uint8_T VGJ_Spd_Z18 = 5U;      /* 旋钮档位切换车速阈值 */
CAL_TQM uint16_T VPL_PowerLim_Filter = 80U;/* 功率值限制滤波参数 */
CAL_TQM uint16_T VPL_PowerPctLim_Filter = 80U;/* 功率百分比限制滤波参数 */
CAL_TQM boolean_T VSJ_ABS_Spd_Valid_Ena = 0;/* ABS车速信号有效位使能开关 */
CAL_TQM boolean_T VSJ_ABS_Spd_Valid_Val = 0;/* ABS车速信号有效位使能状态 */
CAL_TQM boolean_T VSJ_MCU_Spd_Valid_Ena = 0;/* MCU转速信号有效位使能开关 */
CAL_TQM boolean_T VSJ_MCU_Spd_Valid_Val = 0;/* MCU转速信号有效位使能开关 */
CAL_TQM int16_T VSJ_SpdNeg_Cal = -10;  /* 电机静止-反转判别临界值 */
CAL_TQM int16_T VSJ_SpdPos_Cal = 10;   /* 电机静止-正转判别临界值 */
CAL_TQM boolean_T VSJ_Spd_Valid_Ena = 0;/* 速度信号有效位使能开关 */
CAL_TQM boolean_T VSJ_Spd_Valid_Val = 0;/* 速度信号有效位使能状态 */
CAL_TQM uint8_T VSL_GearD1_YK19_SpdLim_Hig = 15U;/* 手动挡车型D1挡限制车速上限 */
CAL_TQM uint8_T VSL_GearD1_YK19_SpdLim_Low = 12U;/* 手动挡车型D1挡限制车速下限 */
CAL_TQM uint8_T VSL_GearD2_YK19_SpdLim_Hig = 33U;/* 手动挡车型D2挡限制车速上限 */
CAL_TQM uint8_T VSL_GearD2_YK19_SpdLim_Low = 30U;/* 手动挡车型D2挡限制车速下限 */
CAL_TQM uint8_T VSL_GearD3_YK19_SpdLim_Hig = 48U;/* 手动挡车型D3挡限制车速上限 */
CAL_TQM uint8_T VSL_GearD3_YK19_SpdLim_Low = 45U;/* 手动挡车型D3挡限制车速下限 */
CAL_TQM uint8_T VSL_GearD4_YK19_SpdLim_Hig = 58U;/* 手动挡车型D4挡限制车速上限 */
CAL_TQM uint8_T VSL_GearD4_YK19_SpdLim_Low = 55U;/* 手动挡车型D4挡限制车速下限 */
CAL_TQM uint8_T VSL_GearD5_YK19_SpdLim_Hig = 135U;/* 手动挡车型D5挡限制车速上限 */
CAL_TQM uint8_T VSL_GearD5_YK19_SpdLim_Low = 70U;/* 手动挡车型D5挡限制车速下限 */
CAL_TQM uint8_T VSL_GearD_ECOSpdLim_Hig = 90U;/* ECO模式D挡限速上限 */
CAL_TQM uint8_T VSL_GearD_ECOSpdLim_Low = 85U;/* ECO模式D挡限速下限 */
CAL_TQM uint8_T VSL_GearD_SPTSpdLim_Hig = 110U;/* SPT模式D挡限速上限 */
CAL_TQM uint8_T VSL_GearD_SPTSpdLim_Low = 105U;/* SPT模式D挡限速下限 */
CAL_TQM uint8_T VSL_GearD_SpdLim_Hig = 145U;/* D挡限速上限 */
CAL_TQM uint8_T VSL_GearD_SpdLim_Low = 140U;/* D挡限速下限 */
CAL_TQM uint8_T VSL_GearR_SpdLim_Hig = 35U;/* R挡速度上限 */
CAL_TQM uint8_T VSL_GearR_SpdLim_Low = 25U;/* R挡限速下限 */
CAL_TQM uint8_T VSL_GearR_YK19_SpdLim_Hig = 12U;/* 手动挡车型R挡限制车速上限 */
CAL_TQM uint8_T VSL_GearR_YK19_SpdLim_Low = 15U;/* 手动挡车型R挡限制车速下限 */
CAL_TQM uint8_T VSL_HighSOC = 18U;     /* 高于该SOC值不限制车速 */
CAL_TQM uint8_T VSL_LowSOC = 15U;      /* 低于该SOC值限制车速到130 */
CAL_TQM uint8_T VSL_LowSOC_SpdLim_rpm = 130U;/* 低SOC限制车速 */
CAL_TQM uint8_T VSL_NormSOC_SpdLim_rpm = 200U;
CAL_TQM uint16_T VSL_SpdLim_Filter = 80U;/* 车速限制滤波参数 */
CAL_TQM boolean_T VTA_Arbitration_Ena = 0;/* 仲裁使能开关 */
CAL_TQM boolean_T VTA_Arbitration_Val = 0;/* 仲裁使能值 */
CAL_TQM boolean_T VTA_GearN_Ena = 0;   /* N挡滑行扭矩使能 */
CAL_TQM uint16_T VTA_GearN_MotSpd[14] =
{
    500U, 1000U, 1500U, 2000U, 2001U, 2500U, 3000U, 3500U, 4000U, 4001U, 5000U,
    7000U, 9000U, 10000U
} ;                                    /* N挡滑行扭矩map-转速 */

CAL_TQM int16_T VTA_GearN_Tq[14] =
{
    16, 16, 16, 16, 32, 32, 32, 32, 32, 0, 0, 0, 0, 0
} ;                                    /* N挡滑行扭矩map-扭矩 */

CAL_TQM uint16_T VTA_Gear_P_N_Filter = 80U;/* P/N挡扭矩滤波系数 */
CAL_TQM uint16_T Veh_Sim_Interval_dT = 20U;/* 积分时间 */
CAL_TQM uint32_T Velocity_Ratio_Cal = 519674U;/* 减速比 */
CAL_TQM boolean_T b1_C_TQD_ACRCtrEna = 0;/* 加速度环使能开关 */
CAL_TQM boolean_T big_C_ConfigAccSensor_flg = 0;/* 加速度来源判断整车是否配置加速度传感器 */
CAL_TQM uint8_T eSpeedlHistSize = 4U;
CAL_TQM real32_T f4_C_VSP_AccSpdLower_mpss = -5.0F;/* 实际加速度下限 */
CAL_TQM real32_T f4_C_VSP_AccSpdUpper_mpss = 5.0F;/* 实际加速度上限 */
CAL_TQM real32_T f4_C_VSP_KamFiter_P = 10.0F;/* 加速度卡尔曼滤波系数P */
CAL_TQM real32_T f4_C_VSP_KamFiter_Q = 0.1F;/* 加速度卡尔曼滤波系数Q */
CAL_TQM real32_T f4_C_VSP_KamFiter_R = 1.0F;/* 加速度卡尔曼滤波系数R */
CAL_TQM int16_T lo_dec_limit = -400;   /* 斜率限制部分扭矩减小值 */
CAL_TQM real32_T s1_C_ESC_TqUpOffset = 20.0F;/* ESC请求扭矩大于vcu需求扭矩阈值 */
CAL_TQM real32_T s1_C_TQM_MCUTqDiff = 20.0F;/* 需求扭矩与实际扭矩的差值判断阈值 */
CAL_TQM int8_T s2_C_TQF_DecRatStepFactor = -5;/* 扭矩下降斜率调整因子:该值与软件运行周期相关，该值*软件运行周期=1s */
CAL_TQM int8_T s2_C_TQF_IncRatStepFactor = 5;/* 扭矩上升斜率调整因子:该值与软件运行周期相关，该值*软件运行周期=1s */
CAL_TQM uint8_T u1_CT_TQF_AbsModRegenTqDecZRat_Nmps[25] =
{
    10U, 20U, 20U, 20U, 20U, 10U, 20U, 30U, 30U, 30U, 10U, 20U, 30U, 40U, 40U,
    10U, 20U, 30U, 40U, 50U, 10U, 20U, 30U, 40U, 50U
} ;                                    /* Creep工况下的再生制动扭矩减小时的斜率限制MAP的Z轴(为了降低数据类型,单位为Nm/100ms) */

CAL_TQM uint8_T u1_CT_TQF_GearDAccPdlModEcoDriveTqDecZRat_Nmps[25] =
{
    5U, 5U, 5U, 5U, 5U, 10U, 15U, 15U, 15U, 15U, 10U, 20U, 30U, 30U, 30U, 10U,
    20U, 30U, 50U, 50U, 10U, 20U, 30U, 50U, 80U
} ;                                    /* AccelPedal工况下D挡ECO模式的驱动扭矩减小时的斜率限制MAP的Z轴(为了降低数据类型,单位为Nm/100ms)(为了降低数据类型,单位为Nm/100ms) */

CAL_TQM uint8_T u1_CT_TQF_GearDAccPdlModEcoDriveTqIncZRat_Nmps[25] =
{
    5U, 5U, 5U, 5U, 5U, 5U, 10U, 10U, 10U, 10U, 5U, 10U, 15U, 15U, 15U, 5U, 10U,
    20U, 20U, 20U, 5U, 10U, 20U, 25U, 30U
} ;                                    /* AccelPedal工况下D挡ECO模式的驱动扭矩增加时的斜率限制MAP的Z轴(为了降低数据类型,单位为Nm/100ms)(为了降低数据类型,单位为Nm/100ms) */

CAL_TQM uint8_T u1_CT_TQF_GearDAccPdlModEcoRegenTqDecZRat_Nmps[25] =
{
    2U, 5U, 5U, 5U, 5U, 2U, 5U, 10U, 10U, 10U, 2U, 5U, 10U, 20U, 20U, 2U, 5U,
    10U, 20U, 30U, 2U, 5U, 10U, 20U, 30U
} ;                                    /* AccelPedal工况下D挡ECO模式的再生制动扭矩减小时的斜率限制MAP的Z轴(为了降低数据类型,单位为Nm/100ms) */

CAL_TQM uint8_T u1_CT_TQF_GearDAccPdlModEcoRegenTqIncZRat_Nmps[25] =
{
    5U, 5U, 5U, 5U, 5U, 15U, 15U, 15U, 15U, 15U, 20U, 30U, 30U, 30U, 30U, 20U,
    40U, 40U, 40U, 40U, 20U, 40U, 50U, 60U, 60U
} ;                                    /* AccelPedal工况下D挡ECO模式的再生制动扭矩增加时的斜率限制MAP的Z轴(为了降低数据类型,单位为Nm/100ms) */

CAL_TQM uint8_T u1_CT_TQF_GearDAccPdlModSportDriveTqDecZRat_Nmps[25] =
{
    5U, 5U, 5U, 5U, 5U, 10U, 15U, 15U, 15U, 15U, 10U, 20U, 30U, 30U, 30U, 10U,
    20U, 30U, 50U, 50U, 10U, 20U, 30U, 50U, 80U
} ;                                    /* AccelPedal工况下D挡SPORT模式的驱动扭矩减小时的斜率限制MAP的Z轴(为了降低数据类型,单位为Nm/100ms) */

CAL_TQM uint8_T u1_CT_TQF_GearDAccPdlModSportDriveTqIncZRat_Nmps[25] =
{
    5U, 5U, 5U, 5U, 5U, 5U, 10U, 10U, 10U, 10U, 5U, 10U, 20U, 20U, 20U, 5U, 10U,
    20U, 30U, 30U, 5U, 10U, 20U, 30U, 40U
} ;                                    /* AccelPedal工况下D挡SPORT模式的驱动扭矩增加时的斜率限制MAP的Z轴(为了降低数据类型,单位为Nm/100ms) */

CAL_TQM uint8_T u1_CT_TQF_GearDAccPdlModSportRegenTqDecZRat_Nmps[25] =
{
    2U, 5U, 5U, 5U, 5U, 2U, 5U, 10U, 10U, 10U, 2U, 5U, 10U, 20U, 20U, 2U, 5U,
    10U, 20U, 30U, 2U, 5U, 10U, 20U, 30U
} ;                                    /* AccelPedal工况下D挡SPORT模式的再生制动扭矩减小时的斜率限制MAP的Z轴(为了降低数据类型,单位为Nm/100ms) */

CAL_TQM uint8_T u1_CT_TQF_GearDAccPdlModSportRegenTqIncZRat_Nmps[25] =
{
    5U, 5U, 5U, 5U, 5U, 15U, 15U, 15U, 15U, 15U, 20U, 30U, 30U, 30U, 30U, 20U,
    40U, 40U, 40U, 40U, 20U, 40U, 50U, 60U, 60U
} ;                                    /* AccelPedal工况下D挡SPORT模式的再生制动扭矩增加时的斜率限制MAP的Z轴(为了降低数据类型,单位为Nm/100ms) */

CAL_TQM uint8_T u1_CT_TQF_GearDCreepModDriveTqDecZRat_Nmps[25] =
{
    5U, 5U, 5U, 5U, 5U, 10U, 15U, 15U, 15U, 15U, 10U, 20U, 30U, 30U, 30U, 10U,
    20U, 30U, 50U, 50U, 10U, 20U, 30U, 50U, 80U
} ;                                    /* Creep工况下D挡的驱动扭矩减小时的斜率限制MAP的Z轴(为了降低数据类型,单位为Nm/100ms) */

CAL_TQM uint8_T u1_CT_TQF_GearDCreepModDriveTqIncZRat_Nmps[25] =
{
    5U, 5U, 5U, 5U, 5U, 5U, 10U, 10U, 10U, 10U, 5U, 10U, 15U, 15U, 15U, 5U, 10U,
    20U, 20U, 20U, 5U, 10U, 20U, 25U, 30U
} ;                                    /* Creep工况下D挡的驱动扭矩增加时的斜率限制MAP的Z轴(为了降低数据类型,单位为Nm/100ms) */

CAL_TQM uint8_T u1_CT_TQF_GearDCreepModRegenTqDecZRat_Nmps[25] =
{
    2U, 5U, 5U, 5U, 5U, 2U, 5U, 10U, 10U, 10U, 2U, 5U, 10U, 20U, 20U, 2U, 5U,
    10U, 20U, 30U, 2U, 5U, 10U, 20U, 30U
} ;                                    /* Creep工况下D挡的再生制动扭矩减小时的斜率限制MAP的Z轴(为了降低数据类型,单位为Nm/100ms) */

CAL_TQM uint8_T u1_CT_TQF_GearDCreepModRegenTqIncZRat_Nmps[25] =
{
    5U, 5U, 5U, 5U, 5U, 15U, 15U, 15U, 15U, 15U, 20U, 30U, 30U, 30U, 30U, 20U,
    40U, 40U, 40U, 40U, 20U, 40U, 50U, 60U, 60U
} ;                                    /* Creep工况下D挡的再生制动扭矩增加时的斜率限制MAP的Z轴(为了降低数据类型,单位为Nm/100ms) */

CAL_TQM uint8_T u1_CT_TQF_GearRAccPdlModEcoDriveTqDecZRat_Nmps[25] =
{
    5U, 5U, 5U, 5U, 5U, 10U, 15U, 15U, 15U, 15U, 10U, 20U, 30U, 30U, 30U, 10U,
    20U, 30U, 50U, 50U, 10U, 20U, 30U, 50U, 80U
} ;                                    /* AccelPedal工况下R挡ECO模式的驱动扭矩减小时的斜率限制MAP的Z轴(为了降低数据类型,单位为Nm/100ms)(为了降低数据类型,单位为Nm/100ms) */

CAL_TQM uint8_T u1_CT_TQF_GearRAccPdlModEcoDriveTqIncZRat_Nmps[25] =
{
    5U, 5U, 5U, 5U, 5U, 5U, 10U, 10U, 10U, 10U, 5U, 10U, 15U, 15U, 15U, 5U, 10U,
    20U, 20U, 20U, 5U, 10U, 20U, 25U, 30U
} ;                                    /* AccelPedal工况下R挡ECO模式的驱动扭矩增加时的斜率限制MAP的Z轴(为了降低数据类型,单位为Nm/100ms)(为了降低数据类型,单位为Nm/100ms) */

CAL_TQM uint8_T u1_CT_TQF_GearRAccPdlModEcoRegenTqDecZRat_Nmps[25] =
{
    2U, 5U, 5U, 5U, 5U, 2U, 5U, 10U, 10U, 10U, 2U, 5U, 10U, 20U, 20U, 2U, 5U,
    10U, 20U, 30U, 2U, 5U, 10U, 20U, 30U
} ;                                    /* AccelPedal工况下R挡ECO模式的再生制动扭矩减小时的斜率限制MAP的Z轴(为了降低数据类型,单位为Nm/100ms) */

CAL_TQM uint8_T u1_CT_TQF_GearRAccPdlModEcoRegenTqIncZRat_Nmps[25] =
{
    5U, 5U, 5U, 5U, 5U, 15U, 15U, 15U, 15U, 15U, 20U, 30U, 30U, 30U, 30U, 20U,
    40U, 40U, 40U, 40U, 20U, 40U, 50U, 60U, 60U
} ;                                    /* AccelPedal工况下R挡ECO模式的再生制动扭矩增加时的斜率限制MAP的Z轴(为了降低数据类型,单位为Nm/100ms) */

CAL_TQM uint8_T u1_CT_TQF_GearRAccPdlModSportDriveTqDecZRat_Nmps[25] =
{
    5U, 5U, 5U, 5U, 5U, 10U, 15U, 15U, 15U, 15U, 10U, 20U, 30U, 30U, 30U, 10U,
    20U, 30U, 50U, 50U, 10U, 20U, 30U, 50U, 80U
} ;                                    /* AccelPedal工况下R挡SPORT模式的驱动扭矩减小时的斜率限制MAP的Z轴(为了降低数据类型,单位为Nm/100ms) */

CAL_TQM uint8_T u1_CT_TQF_GearRAccPdlModSportDriveTqIncZRat_Nmps[25] =
{
    5U, 5U, 5U, 5U, 5U, 5U, 10U, 10U, 10U, 10U, 5U, 10U, 20U, 20U, 20U, 5U, 10U,
    20U, 30U, 30U, 5U, 10U, 20U, 30U, 40U
} ;                                    /* AccelPedal工况下R挡SPORT模式的驱动扭矩增加时的斜率限制MAP的Z轴(为了降低数据类型,单位为Nm/100ms) */

CAL_TQM uint8_T u1_CT_TQF_GearRAccPdlModSportRegenTqDecZRat_Nmps[25] =
{
    2U, 5U, 5U, 5U, 5U, 2U, 5U, 10U, 10U, 10U, 2U, 5U, 10U, 20U, 20U, 2U, 5U,
    10U, 20U, 30U, 2U, 5U, 10U, 20U, 30U
} ;                                    /* AccelPedal工况下R挡SPORT模式的再生制动扭矩减小时的斜率限制MAP的Z轴(为了降低数据类型,单位为Nm/100ms) */

CAL_TQM uint8_T u1_CT_TQF_GearRAccPdlModSportRegenTqIncZRat_Nmps[25] =
{
    5U, 5U, 5U, 5U, 5U, 15U, 15U, 15U, 15U, 15U, 20U, 30U, 30U, 30U, 30U, 20U,
    40U, 40U, 40U, 40U, 20U, 40U, 50U, 60U, 60U
} ;                                    /* AccelPedal工况下R挡SPORT模式的再生制动扭矩增加时的斜率限制MAP的Z轴(为了降低数据类型,单位为Nm/100ms) */

CAL_TQM uint8_T u1_CT_TQF_GearRCreepModDriveTqDecZRat_Nmps[25] =
{
    5U, 5U, 5U, 5U, 5U, 10U, 15U, 15U, 15U, 15U, 10U, 20U, 30U, 30U, 30U, 10U,
    20U, 30U, 50U, 50U, 10U, 20U, 30U, 50U, 80U
} ;                                    /* Creep工况下R挡的驱动扭矩减小时的斜率限制MAP的Z轴(为了降低数据类型,单位为Nm/100ms) */

CAL_TQM uint8_T u1_CT_TQF_GearRCreepModDriveTqIncZRat_Nmps[25] =
{
    5U, 5U, 5U, 5U, 5U, 5U, 10U, 10U, 10U, 10U, 5U, 10U, 15U, 15U, 15U, 5U, 10U,
    20U, 20U, 20U, 5U, 10U, 20U, 25U, 30U
} ;                                    /* Creep工况下R挡的驱动扭矩增加时的斜率限制MAP的Z轴(为了降低数据类型,单位为Nm/100ms) */

CAL_TQM uint8_T u1_CT_TQF_GearRCreepModRegenTqDecZRat_Nmps[25] =
{
    2U, 5U, 5U, 5U, 5U, 2U, 5U, 10U, 10U, 10U, 2U, 5U, 10U, 20U, 20U, 2U, 5U,
    10U, 20U, 30U, 2U, 5U, 10U, 20U, 30U
} ;                                    /* Creep工况下R挡的再生制动扭矩减小时的斜率限制MAP的Z轴(为了降低数据类型,单位为Nm/100ms) */

CAL_TQM uint8_T u1_CT_TQF_GearRCreepModRegenTqIncZRat_Nmps[25] =
{
    5U, 5U, 5U, 5U, 5U, 15U, 15U, 15U, 15U, 15U, 20U, 30U, 30U, 30U, 30U, 20U,
    40U, 40U, 40U, 40U, 20U, 40U, 50U, 60U, 60U
} ;                                    /* Creep工况下R挡的再生制动扭矩增加时的斜率限制MAP的Z轴(为了降低数据类型,单位为Nm/100ms) */

CAL_TQM uint8_T u1_CT_TQF_HDCModDriveTqDecZRat_Nmps[25] =
{
    5U, 5U, 5U, 5U, 5U, 10U, 15U, 15U, 15U, 15U, 10U, 20U, 30U, 30U, 30U, 10U,
    20U, 30U, 50U, 50U, 10U, 20U, 30U, 50U, 80U
} ;                                    /* HDC工况下的驱动扭矩减小时的斜率限制MAP的Z轴(单位：Nm/100ms) */

CAL_TQM uint8_T u1_CT_TQF_HDCModDriveTqIncZRat_Nmps[25] =
{
    5U, 5U, 5U, 5U, 5U, 5U, 10U, 10U, 10U, 10U, 5U, 10U, 15U, 15U, 15U, 5U, 10U,
    20U, 20U, 20U, 5U, 10U, 20U, 25U, 30U
} ;                                    /* HDC工况下的驱动扭矩增加时的斜率限制MAP的Z轴(单位：Nm/100ms) */

CAL_TQM uint8_T u1_CT_TQF_HDCModRegenTqDecZRat_Nmps[25] =
{
    5U, 5U, 5U, 5U, 5U, 15U, 15U, 15U, 15U, 15U, 20U, 30U, 30U, 30U, 30U, 20U,
    40U, 40U, 40U, 40U, 20U, 40U, 50U, 60U, 60U
} ;                                    /* HDC工况下的再生制动扭矩减小时的斜率限制MAP的Z轴(单位：Nm/100ms) */

CAL_TQM uint8_T u1_CT_TQF_HDCModRegenTqIncZRat_Nmps[25] =
{
    5U, 5U, 5U, 5U, 5U, 15U, 15U, 15U, 15U, 15U, 20U, 30U, 30U, 30U, 30U, 20U,
    40U, 40U, 40U, 40U, 20U, 40U, 50U, 60U, 60U
} ;                                    /* HDC工况下的再生制动扭矩增加时的斜率限制MAP的Z轴(单位：Nm/100ms) */

CAL_TQM uint8_T u1_CT_TQF_HighRegenModDriveTqDecZRat_Nmps[25] =
{
    5U, 5U, 5U, 5U, 5U, 10U, 15U, 15U, 15U, 15U, 10U, 20U, 30U, 30U, 30U, 10U,
    20U, 30U, 50U, 50U, 10U, 20U, 30U, 50U, 80U
} ;                                    /* 高级Regen工况下的驱动扭矩减小时的斜率限制MAP的Z轴(为了降低数据类型,单位为Nm/100ms) */

CAL_TQM uint8_T u1_CT_TQF_HighRegenModDriveTqIncZRat_Nmps[25] =
{
    5U, 5U, 5U, 5U, 5U, 5U, 10U, 10U, 10U, 10U, 5U, 10U, 15U, 15U, 15U, 5U, 10U,
    20U, 20U, 20U, 5U, 10U, 20U, 25U, 30U
} ;                                    /* 高级Regen工况下的驱动扭矩增加时的斜率限制MAP的Z轴(为了降低数据类型,单位为Nm/100ms) */

CAL_TQM uint8_T u1_CT_TQF_HighRegenModRegenTqDecZRat_Nmps[25] =
{
    2U, 5U, 5U, 5U, 5U, 2U, 5U, 10U, 10U, 10U, 2U, 5U, 10U, 20U, 20U, 2U, 5U,
    10U, 20U, 30U, 2U, 5U, 10U, 20U, 30U
} ;                                    /* 高级Regen工况下的再生制动扭矩减小时的斜率限制MAP的Z轴(为了降低数据类型,单位为Nm/100ms) */

CAL_TQM uint8_T u1_CT_TQF_HighRegenModRegenTqIncZRat_Nmps[25] =
{
    5U, 5U, 5U, 5U, 5U, 15U, 15U, 15U, 15U, 15U, 20U, 30U, 30U, 30U, 30U, 20U,
    40U, 40U, 40U, 40U, 20U, 40U, 50U, 60U, 60U
} ;                                    /* 高级egen工况下的再生制动扭矩增加时的斜率限制MAP的Z轴(为了降低数据类型,单位为Nm/100ms) */

CAL_TQM uint8_T u1_CT_TQF_LowRegenModDriveTqDecZRat_Nmps[25] =
{
    5U, 5U, 5U, 5U, 5U, 10U, 15U, 15U, 15U, 15U, 10U, 20U, 30U, 30U, 30U, 10U,
    20U, 30U, 50U, 50U, 10U, 20U, 30U, 50U, 80U
} ;                                    /* 低级Regen工况下的驱动扭矩减小时的斜率限制MAP的Z轴(为了降低数据类型,单位为Nm/100ms) */

CAL_TQM uint8_T u1_CT_TQF_LowRegenModDriveTqIncZRat_Nmps[25] =
{
    5U, 5U, 5U, 5U, 5U, 5U, 10U, 10U, 10U, 10U, 5U, 10U, 15U, 15U, 15U, 5U, 10U,
    20U, 20U, 20U, 5U, 10U, 20U, 25U, 30U
} ;                                    /* 低级Regen工况下的驱动扭矩增加时的斜率限制MAP的Z轴(为了降低数据类型,单位为Nm/100ms) */

CAL_TQM uint8_T u1_CT_TQF_LowRegenModRegenTqDecZRat_Nmps[25] =
{
    2U, 5U, 5U, 5U, 5U, 2U, 5U, 10U, 10U, 10U, 2U, 5U, 10U, 20U, 20U, 2U, 5U,
    10U, 20U, 30U, 2U, 5U, 10U, 20U, 30U
} ;                                    /* 低级Regen工况下的再生制动扭矩减小时的斜率限制MAP的Z轴(为了降低数据类型,单位为Nm/100ms) */

CAL_TQM uint8_T u1_CT_TQF_LowRegenModRegenTqIncZRat_Nmps[25] =
{
    5U, 5U, 5U, 5U, 5U, 15U, 15U, 15U, 15U, 15U, 20U, 30U, 30U, 30U, 30U, 20U,
    40U, 40U, 40U, 40U, 20U, 40U, 50U, 60U, 60U
} ;                                    /* 低级egen工况下的再生制动扭矩增加时的斜率限制MAP的Z轴(为了降低数据类型,单位为Nm/100ms) */

CAL_TQM uint8_T u1_CT_TQF_NedcModDriveTqDecZRat_Nmps[25] =
{
    5U, 5U, 5U, 5U, 5U, 10U, 15U, 15U, 15U, 15U, 10U, 20U, 30U, 30U, 30U, 10U,
    20U, 30U, 50U, 50U, 10U, 20U, 30U, 50U, 80U
} ;                                    /* NEDC工况下的驱动扭矩减小时的斜率限制MAP的Z轴(为了降低数据类型,单位为Nm/100ms) */

CAL_TQM uint8_T u1_CT_TQF_NedcModDriveTqIncZRat_Nmps[25] =
{
    5U, 5U, 5U, 5U, 5U, 5U, 10U, 10U, 10U, 10U, 5U, 10U, 15U, 15U, 15U, 5U, 10U,
    20U, 20U, 20U, 5U, 10U, 20U, 25U, 30U
} ;                                    /* NEDC工况下的驱动扭矩增加时的斜率限制MAP的Z轴(为了降低数据类型,单位为Nm/100ms) */

CAL_TQM uint8_T u1_CT_TQF_NedcModRegenTqDecZRat_Nmps[25] =
{
    2U, 5U, 5U, 5U, 5U, 2U, 5U, 10U, 10U, 10U, 2U, 5U, 10U, 20U, 20U, 2U, 5U,
    10U, 20U, 30U, 2U, 5U, 10U, 20U, 30U
} ;                                    /* NEDC工况下的再生制动扭矩减小时的斜率限制MAP的Z轴(为了降低数据类型,单位为Nm/100ms) */

CAL_TQM uint8_T u1_CT_TQF_NedcModRegenTqIncZRat_Nmps[25] =
{
    5U, 5U, 5U, 5U, 5U, 15U, 15U, 15U, 15U, 15U, 20U, 30U, 30U, 30U, 30U, 20U,
    40U, 40U, 40U, 40U, 20U, 40U, 50U, 60U, 60U
} ;                                    /* NEDC工况下的再生制动扭矩增加时的斜率限制MAP的Z轴(为了降低数据类型,单位为Nm/100ms) */

CAL_TQM uint8_T u1_C_Booster_En = 1U;
CAL_TQM uint8_T u1_C_ESC_ESP_En = 2U;  /* 0:无ABS 1：ABS 2:ESP */
CAL_TQM boolean_T u1_C_ESC_EscEnableFlg = 0;/* ESC使能开关(0:关闭、1：开启) */
CAL_TQM uint8_T u1_C_ESC_EscIncEnaFlg = 0U;/* ESC增扭使能开关(0:关闭、1：开启) */
CAL_TQM boolean_T u1_C_HDC_En = 1;     /* HDC工况配置字使能 */
CAL_TQM uint8_T u1_C_TQF_AbsModDriveTqDecRat_Nmps = 255U;/* ABS工况下默认值 */
CAL_TQM uint8_T u1_C_TQF_AbsModDriveTqIncRat_Nmps = 255U;/* ABS工况下默认值 */
CAL_TQM uint8_T u1_C_TQF_DefModGearPNRat_Nmps = 40U;/* Deafult工况下P/N挡扭矩卸载斜率限制(为了降低数据类型,单位为Nm/100ms) */
CAL_TQM uint8_T u1_C_TQF_DefModSteadyDecRat_Nmps = 10U;/* Deafult工况下扭矩下降默认斜率——扭矩处于稳态(为了降低数据类型,单位为Nm/100ms) */
CAL_TQM uint8_T u1_C_TQF_DefModSteadyIncRat_Nmps = 10U;/* Deafult工况下扭矩上升默认斜率——扭矩处于稳态(为了降低数据类型,单位为Nm/100ms) */
CAL_TQM boolean_T u1_C_TQF_UseFilterRateNewArch = 0;/* 是否使用精细化扭矩滤波（1：表示使用精细化扭矩滤波） */
CAL_TQM real32_T u1_C_TQM_MCUTqMaxFactor = 0.7F;/* MCU限扭系数阈值(0.9-最大误差) */
CAL_TQM int16_T u2_CT_TQF_AbsModRegenTqDecXOldTq_Nm[5] =
{
    0, 97, 161, 321, 641
} ;                                    /* Creep工况下的再生制动扭矩减小时的斜率限制MAP的X轴(前回输出扭矩的绝对值) */

CAL_TQM int16_T u2_CT_TQF_AbsModRegenTqDecYTqDiff_Nm[5] =
{
    0, 161, 321, 641, 961
} ;                                    /* Creep工况下的再生制动扭矩减小时的斜率限制MAP的Y轴((今回期望扭矩 - 前回输出扭矩值)的绝对值) */

CAL_TQM int16_T u2_CT_TQF_AccPdlModEcoDriveTqDecXOldTq_Nm[5] =
{
    0, 97, 161, 321, 641
} ;                                    /* AccelPedal工况下ECO模式的驱动扭矩减小时的斜率限制MAP的X轴(前回输出扭矩的绝对值) */

CAL_TQM int16_T u2_CT_TQF_AccPdlModEcoDriveTqDecYTqDiff_Nm[5] =
{
    0, 161, 321, 641, 961
} ;                                    /* AccelPedal工况下ECO模式的驱动扭矩减小时的斜率限制MAP的Y轴((今回期望扭矩 - 前回输出扭矩值)的绝对值) */

CAL_TQM int16_T u2_CT_TQF_AccPdlModEcoDriveTqIncXOldTq_Nm[5] =
{
    0, 97, 161, 321, 641
} ;                                    /* AccelPedal工况下ECO模式的驱动扭矩增加时的斜率限制MAP的X轴(前回输出扭矩的绝对值) */

CAL_TQM int16_T u2_CT_TQF_AccPdlModEcoDriveTqIncYTqDiff_Nm[5] =
{
    0, 161, 321, 641, 1601
} ;                                    /* AccelPedal工况下ECO模式的驱动扭矩增加时的斜率限制MAP的Y轴((今回期望扭矩 - 前回输出扭矩值)的绝对值) */

CAL_TQM int16_T u2_CT_TQF_AccPdlModEcoRegenTqDecXOldTq_Nm[5] =
{
    0, 97, 161, 321, 641
} ;                                    /* AccelPedal工况下ECO模式的再生制动扭矩减小时的斜率限制MAP的X轴(前回输出扭矩的绝对值) */

CAL_TQM int16_T u2_CT_TQF_AccPdlModEcoRegenTqDecYTqDiff_Nm[5] =
{
    0, 161, 321, 641, 961
} ;                                    /* AccelPedal工况下ECO模式的再生制动扭矩减小时的斜率限制MAP的Y轴((今回期望扭矩 - 前回输出扭矩值)的绝对值) */

CAL_TQM int16_T u2_CT_TQF_AccPdlModEcoRegenTqIncXOldTq_Nm[5] =
{
    0, 97, 161, 321, 641
} ;                                    /* AccelPedal工况下ECO模式的再生制动扭矩增加时的斜率限制MAP的X轴(前回输出扭矩的绝对值) */

CAL_TQM int16_T u2_CT_TQF_AccPdlModEcoRegenTqIncYTqDiff_Nm[5] =
{
    0, 161, 321, 641, 961
} ;                                    /* AccelPedal工况下ECO模式的再生制动扭矩增加时的斜率限制MAP的Y轴((今回期望扭矩 - 前回输出扭矩值)的绝对值) */

CAL_TQM int16_T u2_CT_TQF_AccPdlModSportDriveTqDecXOldTq_Nm[5] =
{
    0, 97, 161, 321, 641
} ;                                    /* AccelPedal工况下SPORT模式的驱动扭矩减小时的斜率限制MAP的X轴(前回输出扭矩的绝对值) */

CAL_TQM int16_T u2_CT_TQF_AccPdlModSportDriveTqDecYTqDiff_Nm[5] =
{
    0, 161, 321, 641, 961
} ;                                    /* AccelPedal工况下SPORT模式的驱动扭矩减小时的斜率限制MAP的Y轴((今回期望扭矩 - 前回输出扭矩值)的绝对值) */

CAL_TQM int16_T u2_CT_TQF_AccPdlModSportDriveTqIncXOldTq_Nm[5] =
{
    0, 97, 161, 321, 641
} ;                                    /* AccelPedal工况下SPORT模式的驱动扭矩增加时的斜率限制MAP的X轴(前回输出扭矩的绝对值) */

CAL_TQM int16_T u2_CT_TQF_AccPdlModSportDriveTqIncYTqDiff_Nm[5] =
{
    0, 161, 321, 641, 1281
} ;                                    /* AccelPedal工况下SPORT模式的驱动扭矩增加时的斜率限制MAP的Y轴((今回期望扭矩 - 前回输出扭矩值)的绝对值) */

CAL_TQM int16_T u2_CT_TQF_AccPdlModSportRegenTqDecXOldTq_Nm[5] =
{
    0, 97, 161, 321, 641
} ;                                    /* AccelPedal工况下SPORT模式的再生制动扭矩减小时的斜率限制MAP的X轴(前回输出扭矩的绝对值) */

CAL_TQM int16_T u2_CT_TQF_AccPdlModSportRegenTqDecYTqDiff_Nm[5] =
{
    0, 161, 321, 641, 961
} ;                                    /* AccelPedal工况下SPORT模式的再生制动扭矩减小时的斜率限制MAP的Y轴((今回期望扭矩 - 前回输出扭矩值)的绝对值) */

CAL_TQM int16_T u2_CT_TQF_AccPdlModSportRegenTqIncXOldTq_Nm[5] =
{
    0, 97, 161, 321, 641
} ;                                    /* AccelPedal工况下SPORT模式的再生制动扭矩增加时的斜率限制MAP的X轴(前回输出扭矩的绝对值) */

CAL_TQM int16_T u2_CT_TQF_AccPdlModSportRegenTqIncYTqDiff_Nm[5] =
{
    0, 161, 321, 641, 961
} ;                                    /* AccelPedal工况下SPORT模式的再生制动扭矩增加时的斜率限制MAP的Y轴((今回期望扭矩 - 前回输出扭矩值)的绝对值) */

CAL_TQM int16_T u2_CT_TQF_CreepModDriveTqDecXOldTq_Nm[5] =
{
    0, 97, 161, 321, 641
} ;                                    /* Creep工况下的驱动扭矩减小时的斜率限制MAP的X轴(前回输出扭矩的绝对值) */

CAL_TQM int16_T u2_CT_TQF_CreepModDriveTqDecYTqDiff_Nm[5] =
{
    0, 161, 321, 641, 961
} ;                                    /* Creep工况下的驱动扭矩减小时的斜率限制MAP的Y轴((今回期望扭矩 - 前回输出扭矩值)的绝对值) */

CAL_TQM int16_T u2_CT_TQF_CreepModDriveTqIncXOldTq_Nm[5] =
{
    0, 97, 161, 321, 641
} ;                                    /* Creep工况下的驱动扭矩增加时的斜率限制MAP的X轴(前回输出扭矩的绝对值) */

CAL_TQM int16_T u2_CT_TQF_CreepModDriveTqIncYTqDiff_Nm[5] =
{
    0, 161, 321, 641, 1601
} ;                                    /* Creep工况下的驱动扭矩增加时的斜率限制MAP的Y轴((今回期望扭矩 - 前回输出扭矩值)的绝对值) */

CAL_TQM int16_T u2_CT_TQF_CreepModRegenTqDecXOldTq_Nm[5] =
{
    0, 97, 161, 321, 641
} ;                                    /* Creep工况下的再生制动扭矩减小时的斜率限制MAP的X轴(前回输出扭矩的绝对值) */

CAL_TQM int16_T u2_CT_TQF_CreepModRegenTqDecYTqDiff_Nm[5] =
{
    0, 161, 321, 641, 961
} ;                                    /* Creep工况下的再生制动扭矩减小时的斜率限制MAP的Y轴((今回期望扭矩 - 前回输出扭矩值)的绝对值) */

CAL_TQM int16_T u2_CT_TQF_CreepModRegenTqIncXOldTq_Nm[5] =
{
    0, 97, 161, 321, 641
} ;                                    /* Creep工况下的再生制动扭矩增加时的斜率限制MAP的X轴(前回输出扭矩的绝对值) */

CAL_TQM int16_T u2_CT_TQF_CreepModRegenTqIncYTqDiff_Nm[5] =
{
    0, 161, 321, 641, 961
} ;                                    /* Creep工况下的再生制动扭矩增加时的斜率限制MAP的Y轴((今回期望扭矩 - 前回输出扭矩值)的绝对值) */

CAL_TQM int16_T u2_CT_TQF_HDCModDriveTqDecXOldTq_Nm[5] =
{
    0, 97, 161, 321, 641
} ;                                    /* HDC工况下的驱动扭矩减小时的斜率限制MAP的X轴(前回输出扭矩的绝对值) */

CAL_TQM int16_T u2_CT_TQF_HDCModDriveTqDecYTqDiff_Nm[5] =
{
    0, 161, 321, 641, 961
} ;                                    /* HDC工况下的驱动扭矩减小时的斜率限制MAP的Y轴((今回期望扭矩 - 前回输出扭矩值)的绝对值) */

CAL_TQM int16_T u2_CT_TQF_HDCModDriveTqIncXOldTq_Nm[5] =
{
    0, 97, 161, 321, 641
} ;                                    /* HDC工况下的驱动扭矩增加时的斜率限制MAP的X轴(前回输出扭矩的绝对值) */

CAL_TQM int16_T u2_CT_TQF_HDCModDriveTqIncYTqDiff_Nm[5] =
{
    0, 161, 321, 641, 1601
} ;                                    /* HDC工况下的驱动扭矩增加时的斜率限制MAP的Y轴((今回期望扭矩 - 前回输出扭矩值)的绝对值) */

CAL_TQM int16_T u2_CT_TQF_HDCModRegenTqDecXOldTq_Nm[5] =
{
    0, 97, 161, 321, 641
} ;                                    /* HDC工况下的再生制动扭矩减小时的斜率限制MAP的X轴(前回输出扭矩的绝对值) */

CAL_TQM int16_T u2_CT_TQF_HDCModRegenTqDecYTqDiff_Nm[5] =
{
    0, 161, 321, 641, 961
} ;                                    /* HDC工况下的再生制动扭矩减小时的斜率限制MAP的Y轴((今回期望扭矩 - 前回输出扭矩值)的绝对值) */

CAL_TQM int16_T u2_CT_TQF_HDCModRegenTqIncXOldTq_Nm[5] =
{
    0, 97, 161, 321, 641
} ;                                    /* HDC工况下的再生制动扭矩增加时的斜率限制MAP的X轴(前回输出扭矩的绝对值) */

CAL_TQM int16_T u2_CT_TQF_HDCModRegenTqIncYTqDiff_Nm[5] =
{
    0, 161, 321, 641, 961
} ;                                    /* HDC工况下的再生制动扭矩增加时的斜率限制MAP的Y轴((今回期望扭矩 - 前回输出扭矩值)的绝对值) */

CAL_TQM int16_T u2_CT_TQF_NedcModDriveTqDecXOldTq_Nm[5] =
{
    0, 97, 161, 321, 641
} ;                                    /* NEDC工况下的驱动扭矩减小时的斜率限制MAP的X轴(前回输出扭矩的绝对值) */

CAL_TQM int16_T u2_CT_TQF_NedcModDriveTqDecYTqDiff_Nm[5] =
{
    0, 161, 321, 641, 961
} ;                                    /* NEDC工况下的驱动扭矩减小时的斜率限制MAP的Y轴((今回期望扭矩 - 前回输出扭矩值)的绝对值) */

CAL_TQM int16_T u2_CT_TQF_NedcModDriveTqIncXOldTq_Nm[5] =
{
    0, 97, 161, 321, 641
} ;                                    /* NEDC工况下的驱动扭矩增加时的斜率限制MAP的X轴(前回输出扭矩的绝对值) */

CAL_TQM int16_T u2_CT_TQF_NedcModDriveTqIncYTqDiff_Nm[5] =
{
    0, 161, 321, 641, 961
} ;                                    /* NEDC工况下的驱动扭矩增加时的斜率限制MAP的Y轴((今回期望扭矩 - 前回输出扭矩值)的绝对值) */

CAL_TQM int16_T u2_CT_TQF_NedcModRegenTqDecXOldTq_Nm[5] =
{
    0, 97, 161, 321, 641
} ;                                    /* NEDC工况下的再生制动扭矩减小时的斜率限制MAP的X轴(前回输出扭矩的绝对值) */

CAL_TQM int16_T u2_CT_TQF_NedcModRegenTqDecYTqDiff_Nm[5] =
{
    0, 161, 321, 641, 961
} ;                                    /* NEDC工况下的再生制动扭矩减小时的斜率限制MAP的Y轴((今回期望扭矩 - 前回输出扭矩值)的绝对值) */

CAL_TQM int16_T u2_CT_TQF_NedcModRegenTqIncXOldTq_Nm[5] =
{
    0, 97, 161, 321, 641
} ;                                    /* NEDC工况下的再生制动扭矩增加时的斜率限制MAP的X轴(前回输出扭矩的绝对值) */

CAL_TQM int16_T u2_CT_TQF_NedcModRegenTqIncYTqDiff_Nm[5] =
{
    0, 161, 321, 641, 961
} ;                                    /* NEDC工况下的再生制动扭矩增加时的斜率限制MAP的Y轴((今回期望扭矩 - 前回输出扭矩值)的绝对值) */

CAL_TQM int16_T u2_CT_TQF_RegenModDriveTqDecXOldTq_Nm[5] =
{
    0, 97, 161, 321, 641
} ;                                    /* Regen工况下的驱动扭矩减小时的斜率限制MAP的X轴(前回输出扭矩的绝对值) */

CAL_TQM int16_T u2_CT_TQF_RegenModDriveTqDecYTqDiff_Nm[5] =
{
    0, 161, 321, 641, 961
} ;                                    /* Regen工况下的驱动扭矩减小时的斜率限制MAP的Y轴((今回期望扭矩 - 前回输出扭矩值)的绝对值) */

CAL_TQM int16_T u2_CT_TQF_RegenModDriveTqIncXOldTq_Nm[5] =
{
    0, 97, 161, 321, 641
} ;                                    /* Regen工况下的驱动扭矩增加时的斜率限制MAP的X轴(前回输出扭矩的绝对值) */

CAL_TQM int16_T u2_CT_TQF_RegenModDriveTqIncYTqDiff_Nm[5] =
{
    0, 161, 321, 641, 1601
} ;                                    /* Regen工况下的驱动扭矩增加时的斜率限制MAP的Y轴((今回期望扭矩 - 前回输出扭矩值)的绝对值) */

CAL_TQM int16_T u2_CT_TQF_RegenModRegenTqDecXOldTq_Nm[5] =
{
    0, 97, 161, 321, 641
} ;                                    /* Regen工况下的再生制动扭矩减小时的斜率限制MAP的X轴(前回输出扭矩的绝对值) */

CAL_TQM int16_T u2_CT_TQF_RegenModRegenTqDecYTqDiff_Nm[5] =
{
    0, 161, 321, 641, 961
} ;                                    /* Regen工况下的再生制动扭矩减小时的斜率限制MAP的Y轴((今回期望扭矩 - 前回输出扭矩值)的绝对值) */

CAL_TQM int16_T u2_CT_TQF_RegenModRegenTqIncXOldTq_Nm[5] =
{
    0, 97, 161, 321, 641
} ;                                    /* Regen工况下的再生制动扭矩增加时的斜率限制MAP的X轴(前回输出扭矩的绝对值) */

CAL_TQM int16_T u2_CT_TQF_RegenModRegenTqIncYTqDiff_Nm[5] =
{
    0, 161, 321, 641, 961
} ;                                    /* Regen工况下的再生制动扭矩增加时的斜率限制MAP的Y轴((今回期望扭矩 - 前回输出扭矩值)的绝对值) */

CAL_TQM real32_T u2_C_ASM_DecMotTq_Step = 10.0F;/* MCU防溜扭矩退出步长 */
CAL_TQM real32_T u2_C_ASM_MinTq = 3.0F;/* MCU防溜扭矩退出最小值 */
CAL_TQM uint16_T u2_C_GearBoxDelayTime = 15U;/* 手动挡车型档位确认周期阈值 */
CAL_TQM uint16_T u2_C_TQM_MCUTqDiffDlyTime = 1000U;/* 需求扭矩与实际扭矩的差值判断时间阈值 */
CAL_TQM uint16_T u2_C_VSP_ActAclLowPassFilter_ms = 80U;/* 加速度一阶滤波系数 */
CAL_TQM int16_T up_inc_limit = 200;    /* 斜率限制部分扭矩增加值 */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

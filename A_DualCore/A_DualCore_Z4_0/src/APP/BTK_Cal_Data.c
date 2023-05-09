/*
 * File: BTK_Cal_Data.c
 *
 * Code generated for Simulink model 'BTK_Model'.
 *
 * Model version                  : 1.4445
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Fri Mar 18 15:41:24 2022
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
CAL_BTK uint32_T KBTK_CheckRelayTime_ms = 100U;/* 继电器闭合后到读取反馈电压的延时时间 */
CAL_BTK uint8_T KBTK_ChrgAndUDSAllwSpeed = 3U;/* 允许进入充电和UDS请求目标电源模式的车速阈值 */
CAL_BTK uint32_T KBTK_ERROR_FLASH_Time = 4000U;/* 电源切换失败RedLED闪烁时间 */
CAL_BTK real32_T KBTK_ESCLLockAllwSpeed = 0.0F;/* 允许ESCL上锁的车速阈值 */
CAL_BTK boolean_T KBTK_EraseESKUPAllw_Flg = 1;/* 擦除ESK时需要UDS服务，要求ESCL解锁失败也可以上电 */
CAL_BTK uint32_T KBTK_MEKSigSynTime_ms = 80U;/* ACC和ON信号同步时间（钥匙迅速通OFF到ON，ON到OFF过程中） */
CAL_BTK uint32_T KBTK_MaxSSBDiffTime_ms = 80U;/* 两路开关硬线信号不同步的最大时间 */
CAL_BTK uint32_T KBTK_MaxTimeInOnState_ms = 1800000U;/* 低压ON档允许持续时间30mins = 1800000ms */
CAL_BTK uint8_T KBTK_PwrOffCarSpeed = 10U;/* 允许退出START模式的车速阈值 */
CAL_BTK uint32_T KBTK_RelayVoltInValidThreshold = 1U;/* 继电器断开后反馈电压阈值 */
CAL_BTK uint32_T KBTK_RelayVoltValidThreshold = 8U;/* 继电器闭合反馈电压最小阈值 */
CAL_BTK uint32_T KBTK_RelayWrongThreshold_ms = 120U;/* 继电器反馈电压错误确认时间，超过后故障置位 */
CAL_BTK uint32_T KBTK_SSBAdhesionConfirmTime_ms = 3000U;/* SSB开关黏连确认时间 */
CAL_BTK uint32_T KBTK_SSBConfirmTime_ms = 100U;/* SSB开关信号确认时间 */
CAL_BTK uint32_T KBTK_SigConfirmTime_ms = 100U;/* 无人唤醒源的信号确认时间-滤波 */
CAL_BTK uint32_T KBTK_StateSwitchDelay_ms = 1000U;/* SSB开关信号触发的最小时间间隔 */
CAL_BTK uint32_T KBTK_WODriver_ConfirmTime_ms = 1000U;/* 车内无人信号确认延时时间 */
CAL_BTK uint32_T KBTK_WaitAuthRsltDelay_ms = 1000U;/* 等待防盗认证结果时间 */
CAL_BTK uint32_T KBTK_WaitESCLRxReq = 100U;/* 等待ESCL模块接收请求的延时时间 */
CAL_BTK uint32_T KBTK_waitForEsclLockTime_ms = 2000U;/* 等待ESCL闭锁超时时间 */
CAL_BTK uint32_T KBTK_waitForEsclUnlockTime_ms = 2000U;/* 等待ESCL解锁超时时间 */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

/*
 * File: BTK_Cal_Data.h
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

#ifndef RTW_HEADER_BTK_Cal_Data_h_
#define RTW_HEADER_BTK_Cal_Data_h_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "BTK_Model_types.h"

/* Exported data define */

/* Definition for custom storage class: Define */
#define BTK_BCM_VEHICLE_LOCKED         2U
#define BTK_BCM_VEHICLE_UNLOCK         0U
#define BTK_BMS_NOCHRGMODE             0U
#define BTK_DRVDOOR_AJAR               2U
#define BTK_DRVDOOR_CLOSED             0U
#define BTK_ESCL_LOCK_REQ              2U
#define BTK_ESCL_NOCMD_REQ             0U
#define BTK_ESCL_STATE_LOCK            0U
#define BTK_ESCL_STATE_UNLOCK          1U
#define BTK_ESCL_UNLOCK_REQ            1U
#define BTK_FALSE                      0
#define BTK_GEAR_D                     4U
#define BTK_GEAR_R                     2U
#define BTK_PDU_HV_ACTIVE_W            4U                        /* HV Active with driver */
#define BTK_PDU_HV_ACTIVE_WO           3U                        /* HV Active without driver */
#define BTK_PDU_LV_W                   1U                        /* LV ready */
#define BTK_PDU_LV_WO                  6U                        /* LV ready WO */
#define BTK_PDU_OFF_W                  0U
#define BTK_PDU_OFF_WO                 0U
#define BTK_PDU_START_DRIVE            2U
#define BTK_PEPS_RELEASE_FAILED        1U
#define BTK_PEPS_RELEASE_SUCCESS       2U
#define BTK_PKERKE_LOCK                2U
#define BTK_PMSC_MEK                   2U
#define BTK_PMSC_SSB                   1U
#define BTK_PMS_A                      1U
#define BTK_PMS_B                      2U
#define BTK_PMS_Z18                    3U
#define BTK_REMIND_ESCLLOCK            3U                        /* ESCL上锁失败 */
#define BTK_REMIND_ESCLUNLOCK          2U                        /* ESCL解锁失败 */
#define BTK_REMIND_FAULT               5U                        /* 三级故障不响应上电 */
#define BTK_REMIND_NONE                0U                        /* 无电源模式切换失败 */
#define BTK_REMIND_OTHER               7U                        /* 模式切换失败-其他原因 */
#define BTK_REMIND_STARTDOWN           4U                        /* 车速过高，不能退出START */
#define BTK_REMIND_TBOXCHECK           1U                        /* 用户钥匙身份认证失败 */
#define BTK_REMIND_UDS                 6U                        /* UDS服务进行中，不响应电源切换请求 */
#define BTK_TBOX_REMOTE_LOCK           1U
#define BTK_TRUE                       1
#define TBOX_RSP_KEYAUTHFILED          95U                       /* 0x5F:Key Authentication is Failed, the encrypted response key shall be all 0x00 钥匙认证失败,加密随机数以全0x00响应 */

/* Exported data declaration */
#include "derivative.h"

/* Declaration for custom storage class: CAL_16_BTK */
extern CAL_BTK uint32_T KBTK_CheckRelayTime_ms;/* 继电器闭合后到读取反馈电压的延时时间 */
extern CAL_BTK uint8_T KBTK_ChrgAndUDSAllwSpeed;/* 允许进入充电和UDS请求目标电源模式的车速阈值 */
extern CAL_BTK uint32_T KBTK_ERROR_FLASH_Time;/* 电源切换失败RedLED闪烁时间 */
extern CAL_BTK real32_T KBTK_ESCLLockAllwSpeed;/* 允许ESCL上锁的车速阈值 */
extern CAL_BTK boolean_T KBTK_EraseESKUPAllw_Flg;/* 擦除ESK时需要UDS服务，要求ESCL解锁失败也可以上电 */
extern CAL_BTK uint32_T KBTK_MEKSigSynTime_ms;/* ACC和ON信号同步时间（钥匙迅速通OFF到ON，ON到OFF过程中） */
extern CAL_BTK uint32_T KBTK_MaxSSBDiffTime_ms;/* 两路开关硬线信号不同步的最大时间 */
extern CAL_BTK uint32_T KBTK_MaxTimeInOnState_ms;/* 低压ON档允许持续时间30mins = 1800000ms */
extern CAL_BTK uint8_T KBTK_PwrOffCarSpeed;/* 允许退出START模式的车速阈值 */
extern CAL_BTK uint32_T KBTK_RelayVoltInValidThreshold;/* 继电器断开后反馈电压阈值 */
extern CAL_BTK uint32_T KBTK_RelayVoltValidThreshold;/* 继电器闭合反馈电压最小阈值 */
extern CAL_BTK uint32_T KBTK_RelayWrongThreshold_ms;/* 继电器反馈电压错误确认时间，超过后故障置位 */
extern CAL_BTK uint32_T KBTK_SSBAdhesionConfirmTime_ms;/* SSB开关黏连确认时间 */
extern CAL_BTK uint32_T KBTK_SSBConfirmTime_ms;/* SSB开关信号确认时间 */
extern CAL_BTK uint32_T KBTK_SigConfirmTime_ms;/* 无人唤醒源的信号确认时间-滤波 */
extern CAL_BTK uint32_T KBTK_StateSwitchDelay_ms;/* SSB开关信号触发的最小时间间隔 */
extern CAL_BTK uint32_T KBTK_WODriver_ConfirmTime_ms;/* 车内无人信号确认延时时间 */
extern CAL_BTK uint32_T KBTK_WaitAuthRsltDelay_ms;/* 等待防盗认证结果时间 */
extern CAL_BTK uint32_T KBTK_WaitESCLRxReq;/* 等待ESCL模块接收请求的延时时间 */
extern CAL_BTK uint32_T KBTK_waitForEsclLockTime_ms;/* 等待ESCL闭锁超时时间 */
extern CAL_BTK uint32_T KBTK_waitForEsclUnlockTime_ms;/* 等待ESCL解锁超时时间 */

#endif                                 /* RTW_HEADER_BTK_Cal_Data_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

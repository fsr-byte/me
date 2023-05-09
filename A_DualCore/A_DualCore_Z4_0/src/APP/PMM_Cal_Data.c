/*
 * File: PMM_Cal_Data.c
 *
 * Code generated for Simulink model 'PMM_model'.
 *
 * Model version                  : 1.3119
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Fri Mar 18 15:42:54 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Freescale->32-bit PowerPC
 * Code generation objectives:
 *    1. RAM efficiency
 *    2. ROM efficiency
 *    3. Execution efficiency
 *    4. MISRA C:2012 guidelines
 * Validation result: Not run
 */

#include "rtwtypes.h"
#include "PMM_model_types.h"

/* Exported data definition */
#include "derivative.h"

/* Definition for custom storage class: CAL_5_PMM */
CAL_PMM uint32_T KPMM_BMSHeartBeatMsg_CycTime_ms = 10U;/* BMS心跳报文间隔的时间 */
CAL_PMM uint8_T KPMM_BMSMonitorDelayTime_min = 2U;/* BMS监控时长延长时间 */
CAL_PMM uint16_T KPMM_ChrgVehicleSpeedMax_kmph = 3U;/* 停车充电车辆最高车速 */
CAL_PMM boolean_T KPMM_DCDCActiveCheckEnable_Flag = 1;/* DCDC高压激活检查使能 */
CAL_PMM uint32_T KPMM_DCDCHeartBeatMsg_CycTime_ms = 100U;/* DCDC心跳报文间隔的时间 */
CAL_PMM uint16_T KPMM_DCDCSByMCUActive_ms = 1000U;/* 常规下电，超时1s未收到MCUOperMdl=3和DCDC OperMod=0 */
CAL_PMM uint8_T KPMM_DCRelayCutOffTime_s = 5U;/* 直充等待直充继电器断开时间 */
CAL_PMM uint32_T KPMM_EPBAppliedTime_ms = 20000U;/* EPB卡钳拉起等待时间 */
CAL_PMM uint8_T KPMM_EVCC_Type = 0U;   /* EVCC类型：0 没有。1 K11P01架构，2 reserved */
CAL_PMM uint32_T KPMM_HVActiveDCDCTime_ms = 1000U;/* DCDC高压激活等待时间 */
CAL_PMM uint32_T KPMM_HVActiveStateKeepTime_ms = 100U;/* 高压激活最短工作时间 */
CAL_PMM uint32_T KPMM_HVActiveTime_ms = 1000U;/* 正常高压激活等待时间 */
CAL_PMM uint32_T KPMM_HVDownTime_ms = 1000U;/* 高压下电等待时间 */
CAL_PMM uint32_T KPMM_HVEACPTCStopWorkConfirmTime_ms = 100U;/* 空调PTC停止工作信号确认时间 */
CAL_PMM real32_T KPMM_HVStopWorkBMSCurrentUpper_A = 5.0F;/* 高压部件停止工作高压工作电流上限 */
CAL_PMM int16_T KPMM_HVStopWorkMotorSpeedUpper_rpm = 800;/* 高压部件停止工作电机转速上限 */
CAL_PMM uint16_T KPMM_HVStopWorkTime_s = 5U;/* 高压部件停止工作等待时间 */
CAL_PMM uint32_T KPMM_HVUpStateKeepTime_ms = 100U;/* 高压上电最短工作时间 */
CAL_PMM uint16_T KPMM_HVUpTime_s = 2U; /* 高压上电等待时间 */
CAL_PMM uint8_T KPMM_IChrgWorkTime = 60U;/* 智能补电监控时间60分钟 */
CAL_PMM uint32_T KPMM_KeyOnReUpConfirmTime_ms = 1000U;/* 断开继电器KeyOn有效信号确认时间 */
CAL_PMM uint32_T KPMM_KeyRemoteOnTimeout_ms = 2000U;/* 远程空调收到PEPS_PDU=3的时间 */
CAL_PMM uint32_T KPMM_LVDownDelayTime_ms = 100U;/* 低压下电等待时间 */
CAL_PMM uint32_T KPMM_LVStandbyTime_ms = 2000U;/* 低压下电待机时间 */
CAL_PMM uint32_T KPMM_LVUpStateKeepTime_ms = 300U;/* 低压上电最短工作时间 */
CAL_PMM uint32_T KPMM_LVUpTimeDCChrg_BMSPwrupallwReseted_ms = 300U;/* 直充插枪后等待BMSPwrupallw为0的时间 */
CAL_PMM uint16_T KPMM_LVUpTimeDCChrg_s = 60U;/* 直充时低压上电等待时间 */
CAL_PMM uint32_T KPMM_LVUpTime_ms = 600U;/* 低压上电等待时间 */
CAL_PMM uint32_T KPMM_MCUActiveTime_ms = 1000U;/* 驻车模式结束MCU激活等待时间 */
CAL_PMM uint16_T KPMM_MCUDischargeTime_s = 4U;/* MCU快速放电等待时间 */
CAL_PMM uint32_T KPMM_MCUHeartBeatMsg_CycTime_ms = 10U;/* MCU心跳报文间隔的时间 */
CAL_PMM uint32_T KPMM_MCULVDnTime_ms = 200U;/* 进入驻车模式断开MCU继电器延时时间 */
CAL_PMM uint32_T KPMM_MCULVUpTime_ms = 600U;/* 驻车模式结束MCU低压上电等待时间 */
CAL_PMM uint32_T KPMM_PEPSOffToAccOnConfirmTime_ms = 500U;/* PEPS从OFF切换到On或ACC后保持的时间 */
CAL_PMM uint32_T KPMM_PEPSOnAccToOffConfirmTime_ms = 1000U;/* PEPS从ACC或On切换到OFF后保持的时间 */
CAL_PMM boolean_T KPMM_PEPSUnlock_flg = 1;/* PEPS解锁标志 */
CAL_PMM uint32_T KPMM_RePrechargeIntervalTime_ms = 1000U;/* Precharge两次之间需要间隔的时间 */
CAL_PMM uint32_T KPMM_RemoteACHVActiveTimeout_ms = 5000U;/* 收到PEPS_PDU==3后等待高压上电完成（进入parking）的时间。 */
CAL_PMM uint32_T KPMM_RemoteACNoRequestTime_ms = 2000U;/* 远程空调无请求确认时间 */
CAL_PMM uint32_T KPMM_RemoteACOnTimeout_ms = 3000U;/* 远程空调系统开启错误时间 */
CAL_PMM uint8_T KPMM_RemoteACStopHoldTime_min = 2U;/* 远程空调停止工作保持时间 */
CAL_PMM real32_T KPMM_RunToChrgVehicleSpeedMax_kmph = 3.0F;
CAL_PMM uint32_T KPMM_WaitBMSIChrgEna_ms = 1000U;/* 智能补电等待BMS允许补电的超时时间，从LVReady开始计时 */
CAL_PMM uint32_T KPMM_WaitBMSSleepClearDTCTime_ms = 2000U;/* 故障下电主继电器断开后等待BMS休眠清除故障码的延时时间 */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

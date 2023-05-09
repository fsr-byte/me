/*
 * File: PMM_Cal_Data.h
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

#ifndef RTW_HEADER_PMM_Cal_Data_h_
#define RTW_HEADER_PMM_Cal_Data_h_
#include "rtwtypes.h"
#include "PMM_model_types.h"

/* Exported data define */

/* Definition for custom storage class: Define */
#define PHYSICAL_N                     6U
#define PMM_ACCMODE_OFF                0U
#define PMM_BMSCHRGSTS_CHRGING         1U
#define PMM_BMSMODE_FAILURE            5U
#define PMM_BMSMODE_HVACTIVE           3U
#define PMM_BMSMODE_INIT               0U
#define PMM_BMSMODE_POWERDOWN          4U
#define PMM_BMSMODE_PRECHARGE          2U
#define PMM_BMSMODE_STANDBY            1U
#define PMM_CHRMODE_AC                 1U
#define PMM_CHRMODE_DC                 2U
#define PMM_DCDCMODE_ERROR             2U
#define PMM_DCDCMODE_OFF               0U
#define PMM_DCDCMODE_ON                1U
#define PMM_DCDCMODE_STANDBY           0U
#define PMM_DCDCMODE_WORK              1U
#define PMM_EPBSTATUS_BRAKE            3U
#define PMM_FALSE                      0
#define PMM_MCUMODE_DISCHARGE          6U
#define PMM_MCUMODE_FAILURE            15U
#define PMM_MCUMODE_HVACTIVE           3U
#define PMM_MCUMODE_INIT               0U
#define PMM_MCUMODE_PRECHARGE          2U
#define PMM_MCUMODE_PREPOWERDOWN       15U
#define PMM_MCUMODE_PRESHUTDOWN        7U
#define PMM_MCUMODE_STANDBY            1U
#define PMM_MCUMODE_TRQCTL             5U
#define PMM_MOTSTSREGEN                2U
#define PMM_PEPSPDU_ACC                1U
#define PMM_PEPSPDU_HV                 4U
#define PMM_PEPSPDU_OFF                0U
#define PMM_PEPSPDU_ON                 2U
#define PMM_PEPSPDU_REMOTEON           3U
#define PMM_PEPSUNLOCK                 2U
#define PMM_PTCMODE_OFF                0U
#define PMM_ROTARYKNOB                 2U
#define PMM_SAMPLETIME                 20U
#define PMM_SHIFTKNOB_INVALID          0U
#define PMM_SHIFTKNOB_N                3U
#define PMM_SHIFTKNOB_P                1U
#define PMM_STATE_DCACTIVEMCULVUP      24U
#define PMM_STATE_EMERGENCY_HVDOWN     25U
#define PMM_STATE_HVACTIVE             3U
#define PMM_STATE_HVDOWN               6U
#define PMM_STATE_HVSTOPWORK           5U
#define PMM_STATE_HVUP                 2U
#define PMM_STATE_IDLE                 0U
#define PMM_STATE_IDLEPOWERDOWN        12U
#define PMM_STATE_LVDOWN               9U
#define PMM_STATE_LVREADY              23U
#define PMM_STATE_LVSTANDBY            8U
#define PMM_STATE_LVUP                 1U
#define PMM_STATE_MCUDISCHARGE         7U
#define PMM_STATE_PARKING              19U
#define PMM_STATE_RUNNING              4U
#define PMM_STATE_VCUSTOPWORK          10U
#define PMM_TRUE                       1
#define PMM_VEHSTSANTIDRIVE            4U
#define PMM_VEHSTSDRIVE                1U
#define PMM_VEHSTSFAILURE              3U
#define PMM_VEHSTSREGEN                2U
#define PMM_VEHSTSSTANDBY              0U
#define PMM_WITHBLOCKWITHOUTP          3U
#define PMM_WITHBLOCKWITHP             1U

/* Exported data declaration */
#include "derivative.h"

/* Declaration for custom storage class: CAL_5_PMM */
extern CAL_PMM uint32_T KPMM_BMSHeartBeatMsg_CycTime_ms;/* BMS心跳报文间隔的时间 */
extern CAL_PMM uint8_T KPMM_BMSMonitorDelayTime_min;/* BMS监控时长延长时间 */
extern CAL_PMM uint16_T KPMM_ChrgVehicleSpeedMax_kmph;/* 停车充电车辆最高车速 */
extern CAL_PMM boolean_T KPMM_DCDCActiveCheckEnable_Flag;/* DCDC高压激活检查使能 */
extern CAL_PMM uint32_T KPMM_DCDCHeartBeatMsg_CycTime_ms;/* DCDC心跳报文间隔的时间 */
extern CAL_PMM uint16_T KPMM_DCDCSByMCUActive_ms;/* 常规下电，超时1s未收到MCUOperMdl=3和DCDC OperMod=0 */
extern CAL_PMM uint8_T KPMM_DCRelayCutOffTime_s;/* 直充等待直充继电器断开时间 */
extern CAL_PMM uint32_T KPMM_EPBAppliedTime_ms;/* EPB卡钳拉起等待时间 */
extern CAL_PMM uint8_T KPMM_EVCC_Type; /* EVCC类型：0 没有。1 K11P01架构，2 reserved */
extern CAL_PMM uint32_T KPMM_HVActiveDCDCTime_ms;/* DCDC高压激活等待时间 */
extern CAL_PMM uint32_T KPMM_HVActiveStateKeepTime_ms;/* 高压激活最短工作时间 */
extern CAL_PMM uint32_T KPMM_HVActiveTime_ms;/* 正常高压激活等待时间 */
extern CAL_PMM uint32_T KPMM_HVDownTime_ms;/* 高压下电等待时间 */
extern CAL_PMM uint32_T KPMM_HVEACPTCStopWorkConfirmTime_ms;/* 空调PTC停止工作信号确认时间 */
extern CAL_PMM real32_T KPMM_HVStopWorkBMSCurrentUpper_A;/* 高压部件停止工作高压工作电流上限 */
extern CAL_PMM int16_T KPMM_HVStopWorkMotorSpeedUpper_rpm;/* 高压部件停止工作电机转速上限 */
extern CAL_PMM uint16_T KPMM_HVStopWorkTime_s;/* 高压部件停止工作等待时间 */
extern CAL_PMM uint32_T KPMM_HVUpStateKeepTime_ms;/* 高压上电最短工作时间 */
extern CAL_PMM uint16_T KPMM_HVUpTime_s;/* 高压上电等待时间 */
extern CAL_PMM uint8_T KPMM_IChrgWorkTime;/* 智能补电监控时间60分钟 */
extern CAL_PMM uint32_T KPMM_KeyOnReUpConfirmTime_ms;/* 断开继电器KeyOn有效信号确认时间 */
extern CAL_PMM uint32_T KPMM_KeyRemoteOnTimeout_ms;/* 远程空调收到PEPS_PDU=3的时间 */
extern CAL_PMM uint32_T KPMM_LVDownDelayTime_ms;/* 低压下电等待时间 */
extern CAL_PMM uint32_T KPMM_LVStandbyTime_ms;/* 低压下电待机时间 */
extern CAL_PMM uint32_T KPMM_LVUpStateKeepTime_ms;/* 低压上电最短工作时间 */
extern CAL_PMM uint32_T KPMM_LVUpTimeDCChrg_BMSPwrupallwReseted_ms;/* 直充插枪后等待BMSPwrupallw为0的时间 */
extern CAL_PMM uint16_T KPMM_LVUpTimeDCChrg_s;/* 直充时低压上电等待时间 */
extern CAL_PMM uint32_T KPMM_LVUpTime_ms;/* 低压上电等待时间 */
extern CAL_PMM uint32_T KPMM_MCUActiveTime_ms;/* 驻车模式结束MCU激活等待时间 */
extern CAL_PMM uint16_T KPMM_MCUDischargeTime_s;/* MCU快速放电等待时间 */
extern CAL_PMM uint32_T KPMM_MCUHeartBeatMsg_CycTime_ms;/* MCU心跳报文间隔的时间 */
extern CAL_PMM uint32_T KPMM_MCULVDnTime_ms;/* 进入驻车模式断开MCU继电器延时时间 */
extern CAL_PMM uint32_T KPMM_MCULVUpTime_ms;/* 驻车模式结束MCU低压上电等待时间 */
extern CAL_PMM uint32_T KPMM_PEPSOffToAccOnConfirmTime_ms;/* PEPS从OFF切换到On或ACC后保持的时间 */
extern CAL_PMM uint32_T KPMM_PEPSOnAccToOffConfirmTime_ms;/* PEPS从ACC或On切换到OFF后保持的时间 */
extern CAL_PMM boolean_T KPMM_PEPSUnlock_flg;/* PEPS解锁标志 */
extern CAL_PMM uint32_T KPMM_RePrechargeIntervalTime_ms;/* Precharge两次之间需要间隔的时间 */
extern CAL_PMM uint32_T KPMM_RemoteACHVActiveTimeout_ms;/* 收到PEPS_PDU==3后等待高压上电完成（进入parking）的时间。 */
extern CAL_PMM uint32_T KPMM_RemoteACNoRequestTime_ms;/* 远程空调无请求确认时间 */
extern CAL_PMM uint32_T KPMM_RemoteACOnTimeout_ms;/* 远程空调系统开启错误时间 */
extern CAL_PMM uint8_T KPMM_RemoteACStopHoldTime_min;/* 远程空调停止工作保持时间 */
extern CAL_PMM real32_T KPMM_RunToChrgVehicleSpeedMax_kmph;
extern CAL_PMM uint32_T KPMM_WaitBMSIChrgEna_ms;/* 智能补电等待BMS允许补电的超时时间，从LVReady开始计时 */
extern CAL_PMM uint32_T KPMM_WaitBMSSleepClearDTCTime_ms;/* 故障下电主继电器断开后等待BMS休眠清除故障码的延时时间 */

#endif                                 /* RTW_HEADER_PMM_Cal_Data_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

/*
 * File: CHRG_Cal_Data.c
 *
 * Code generated for Simulink model 'CHRG_Model'.
 *
 * Model version                  : 1.1917
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Fri Mar 18 15:31:54 2022
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
#include "CHRG_Model_types.h"

/* Exported data definition */
#include "derivative.h"

/* Definition for custom storage class: CAL_6_CMM */
CAL_CMM uint8_T Config_PB_ElecPB = 1U; /* 电子手刹 */
CAL_CMM uint8_T Config_PB_MachPB = 2U; /* 机械手刹 */
CAL_CMM uint32_T KCHRG_AbnormalChrgEndTime_s = 1U;/* 异常充电结束确认时间 */
CAL_CMM uint16_T KCHRG_BMSChrgStsEndCheckTime_ms = 1000U;/* 充电停止确认时间 */
CAL_CMM uint16_T KCHRG_BMSChrgStsFullCheckTime_ms = 1000U;/* 充电满确认时间 */
CAL_CMM uint16_T KCHRG_ChrgConnectCheckTime_ms = 1200U;/* 充电模式检查完成后，持续检查充电枪连接状态，充电枪断开的确认时间 */
CAL_CMM uint16_T KCHRG_ChrgEndTime_s = 1U;/* 充电结束确认时间 */
CAL_CMM uint32_T KCHRG_ChrgLockCheckTime_ms = 120000U;/* 电子锁锁止等待时间 */
CAL_CMM uint16_T KCHRG_ChrgModeCheckTime_s = 6U;/* 充电模式确认时间 */
CAL_CMM uint16_T KCHRG_ChrgOperationACTime_min = 10U;/* 交充充电状态等待时间 */
CAL_CMM uint16_T KCHRG_ChrgOperationDCTime_min = 10U;/* 直充充电状态等待时间 */
CAL_CMM uint32_T KCHRG_ChrgParkingCheckTime_ms = 150000U;/* 充电时持续检测驻车状态，超时2分钟30秒驻车状态未恢复则退出充电 */
CAL_CMM uint16_T KCHRG_ChrgPlugUnlockTime_s = 5U;/* 电子锁解锁等待时间 */
CAL_CMM uint16_T KCHRG_ChrgSingalTime_ms = 5000U;/* 充电时持续检测充电源硬线信号，超过5s则充电异常退出 */
CAL_CMM uint32_T KCHRG_ChrgStartACTime_s = 5U;/* 交充充电开始等待时间 */
CAL_CMM uint32_T KCHRG_ChrgStartDCTime_s = 60U;/* 直充充电开始等待时间 */
CAL_CMM uint32_T KCHRG_ChrgStopCurrentLimitConfirm_ms = 500U;/* 充电电流限制充电停止确认时间 */
CAL_CMM uint32_T KCHRG_ChrgStopLockErrorConfirm_ms = 500U;/* 电子锁锁止故障充电停止确认时间 */
CAL_CMM uint32_T KCHRG_ChrgStopOperationTimeoutConfirm_ms = 100U;/* 充电操作超时充电停止确认时间 */
CAL_CMM uint32_T KCHRG_OBCSleepPeriod_ms = 100U;/* OBC休眠信号发送周期 */
CAL_CMM uint16_T KCHRG_OBCSleepSend_Cnt = 10U;/* OBC休眠发送次数 */
CAL_CMM uint32_T KCHRG_OBCSleepTime_ms = 2000U;/* OBC休眠等待时间 */
CAL_CMM uint32_T KCHRG_OBCWakeupPeriod_ms = 100U;/* OBC唤醒发送周期 */
CAL_CMM uint16_T KCHRG_OBCWakeupSend_Cnt = 10U;/* OBC唤醒发送次数 */
CAL_CMM uint32_T KCHRG_OBCWakeupTime_ms = 120000U;/* OBC唤醒等待时间 */
CAL_CMM uint16_T KCHRG_ShiftKnobCheckTime_s = 60U;/* 充电手柄位置检测等待时间 */
CAL_CMM uint32_T KCHRG_WaitBMSPwrupAllwReEnableTime_ms = 60000U;/* CHMA发出后BMS将BMSPwrupallw重新为1的最大等待时间 */
CAL_CMM uint32_T KCHRG_WaitBMSPwrupAllwResetTime_ms = 300U;/* CHMA发出后BMS将BMSPwrupallw置为0的最大等待时间 */
CAL_CMM uint16_T VCHRG_ExpMode_WaitTime_ms = 2000U;/* chrgmode异常后等待慢充唤醒信号出现的时间 */
CAL_CMM uint8_T VehChrgSts_ChargFinish = 4U;/* 充电状态-充电完成 */
CAL_CMM uint8_T VehChrgSts_DriveCharging = 2U;/* 充电状态-行驶充电 */
CAL_CMM uint8_T VehChrgSts_NoCharg = 3U;/* 充电状态-未充电 */
CAL_CMM uint8_T VehChrgSts_ParkCharging = 1U;/* 充电状态-停车充电 */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

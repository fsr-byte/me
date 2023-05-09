/*
 * File: CHRG_Cal_Data.h
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

#ifndef RTW_HEADER_CHRG_Cal_Data_h_
#define RTW_HEADER_CHRG_Cal_Data_h_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "CHRG_Model_types.h"

/* Exported data define */

/* Definition for custom storage class: Define */
#define CHRG_BMSCHRGSTS_CHRGEND        3U
#define CHRG_BMSCHRGSTS_CHRGFULL       2U
#define CHRG_BMSCHRGSTS_CHRGING        1U
#define CHRG_BMSCHRGSTS_UNCHARGED      0U
#define CHRG_BMSOBCREQ_ENABLE          1U
#define CHRG_BMSPWRUPALLW              16U
#define CHRG_CHRGEND                   13U
#define CHRG_CHRGING                   7U
#define CHRG_CHRGPLUGUNLOCK            10U
#define CHRG_CHRGREQLIMFAC_THREE       3U
#define CHRG_CHRGSTART                 5U
#define CHRG_CHRGSTOP                  8U
#define CHRG_CHRMODE_ABNORMAL          3U
#define CHRG_CHRMODE_AC                1U
#define CHRG_CHRMODE_DC                2U
#define CHRG_EPBSTATUS_BRAKE           3U
#define CHRG_FALSE                     0
#define CHRG_FAULT                     9U
#define CHRG_IDLE                      0U
#define CHRG_LAMPCHECK                 15U
#define CHRG_LOCK_FAILURE              2U
#define CHRG_LOCK_LOCK                 1U
#define CHRG_LOCK_UNLOCK               0U
#define CHRG_MODECHECK                 2U
#define CHRG_MOTSTSREGEN               2U
#define CHRG_NOCHRGMODE                0U
#define CHRG_NONRUN                    4U
#define CHRG_OBCCHRGLOCK_UNLOCK        0U
#define CHRG_OBCCHRGSTS_SLEEP          6U
#define CHRG_OBCCHRGSTS_STANDBY        1U
#define CHRG_OBCSLEEP                  12U
#define CHRG_OBCUNLOCKREMIND           11U
#define CHRG_OBCWAKEUP                 1U
#define CHRG_OPERATION                 6U
#define CHRG_PARKINGCHECK              14U
#define CHRG_PMM_STATE_PARKING         19U
#define CHRG_REMIND                    3U
#define CHRG_SAMPLETIME                20U
#define CHRG_SAMPLETIMEMAX             100U
#define CHRG_SHIFTKNOB_P               1U
#define CHRG_TRUE                      1

/* Exported data declaration */
#include "derivative.h"

/* Declaration for custom storage class: CAL_6_CMM */
extern CAL_CMM uint8_T Config_PB_ElecPB;/* 电子手刹 */
extern CAL_CMM uint8_T Config_PB_MachPB;/* 机械手刹 */
extern CAL_CMM uint32_T KCHRG_AbnormalChrgEndTime_s;/* 异常充电结束确认时间 */
extern CAL_CMM uint16_T KCHRG_BMSChrgStsEndCheckTime_ms;/* 充电停止确认时间 */
extern CAL_CMM uint16_T KCHRG_BMSChrgStsFullCheckTime_ms;/* 充电满确认时间 */
extern CAL_CMM uint16_T KCHRG_ChrgConnectCheckTime_ms;/* 充电模式检查完成后，持续检查充电枪连接状态，充电枪断开的确认时间 */
extern CAL_CMM uint16_T KCHRG_ChrgEndTime_s;/* 充电结束确认时间 */
extern CAL_CMM uint32_T KCHRG_ChrgLockCheckTime_ms;/* 电子锁锁止等待时间 */
extern CAL_CMM uint16_T KCHRG_ChrgModeCheckTime_s;/* 充电模式确认时间 */
extern CAL_CMM uint16_T KCHRG_ChrgOperationACTime_min;/* 交充充电状态等待时间 */
extern CAL_CMM uint16_T KCHRG_ChrgOperationDCTime_min;/* 直充充电状态等待时间 */
extern CAL_CMM uint32_T KCHRG_ChrgParkingCheckTime_ms;/* 充电时持续检测驻车状态，超时2分钟30秒驻车状态未恢复则退出充电 */
extern CAL_CMM uint16_T KCHRG_ChrgPlugUnlockTime_s;/* 电子锁解锁等待时间 */
extern CAL_CMM uint16_T KCHRG_ChrgSingalTime_ms;/* 充电时持续检测充电源硬线信号，超过5s则充电异常退出 */
extern CAL_CMM uint32_T KCHRG_ChrgStartACTime_s;/* 交充充电开始等待时间 */
extern CAL_CMM uint32_T KCHRG_ChrgStartDCTime_s;/* 直充充电开始等待时间 */
extern CAL_CMM uint32_T KCHRG_ChrgStopCurrentLimitConfirm_ms;/* 充电电流限制充电停止确认时间 */
extern CAL_CMM uint32_T KCHRG_ChrgStopLockErrorConfirm_ms;/* 电子锁锁止故障充电停止确认时间 */
extern CAL_CMM uint32_T KCHRG_ChrgStopOperationTimeoutConfirm_ms;/* 充电操作超时充电停止确认时间 */
extern CAL_CMM uint32_T KCHRG_OBCSleepPeriod_ms;/* OBC休眠信号发送周期 */
extern CAL_CMM uint16_T KCHRG_OBCSleepSend_Cnt;/* OBC休眠发送次数 */
extern CAL_CMM uint32_T KCHRG_OBCSleepTime_ms;/* OBC休眠等待时间 */
extern CAL_CMM uint32_T KCHRG_OBCWakeupPeriod_ms;/* OBC唤醒发送周期 */
extern CAL_CMM uint16_T KCHRG_OBCWakeupSend_Cnt;/* OBC唤醒发送次数 */
extern CAL_CMM uint32_T KCHRG_OBCWakeupTime_ms;/* OBC唤醒等待时间 */
extern CAL_CMM uint16_T KCHRG_ShiftKnobCheckTime_s;/* 充电手柄位置检测等待时间 */
extern CAL_CMM uint32_T KCHRG_WaitBMSPwrupAllwReEnableTime_ms;/* CHMA发出后BMS将BMSPwrupallw重新为1的最大等待时间 */
extern CAL_CMM uint32_T KCHRG_WaitBMSPwrupAllwResetTime_ms;/* CHMA发出后BMS将BMSPwrupallw置为0的最大等待时间 */
extern CAL_CMM uint16_T VCHRG_ExpMode_WaitTime_ms;/* chrgmode异常后等待慢充唤醒信号出现的时间 */
extern CAL_CMM uint8_T VehChrgSts_ChargFinish;/* 充电状态-充电完成 */
extern CAL_CMM uint8_T VehChrgSts_DriveCharging;/* 充电状态-行驶充电 */
extern CAL_CMM uint8_T VehChrgSts_NoCharg;/* 充电状态-未充电 */
extern CAL_CMM uint8_T VehChrgSts_ParkCharging;/* 充电状态-停车充电 */

#endif                                 /* RTW_HEADER_CHRG_Cal_Data_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

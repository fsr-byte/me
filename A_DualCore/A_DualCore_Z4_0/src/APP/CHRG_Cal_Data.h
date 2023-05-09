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
extern CAL_CMM uint8_T Config_PB_ElecPB;/* ������ɲ */
extern CAL_CMM uint8_T Config_PB_MachPB;/* ��е��ɲ */
extern CAL_CMM uint32_T KCHRG_AbnormalChrgEndTime_s;/* �쳣������ȷ��ʱ�� */
extern CAL_CMM uint16_T KCHRG_BMSChrgStsEndCheckTime_ms;/* ���ֹͣȷ��ʱ�� */
extern CAL_CMM uint16_T KCHRG_BMSChrgStsFullCheckTime_ms;/* �����ȷ��ʱ�� */
extern CAL_CMM uint16_T KCHRG_ChrgConnectCheckTime_ms;/* ���ģʽ�����ɺ󣬳��������ǹ����״̬�����ǹ�Ͽ���ȷ��ʱ�� */
extern CAL_CMM uint16_T KCHRG_ChrgEndTime_s;/* ������ȷ��ʱ�� */
extern CAL_CMM uint32_T KCHRG_ChrgLockCheckTime_ms;/* ��������ֹ�ȴ�ʱ�� */
extern CAL_CMM uint16_T KCHRG_ChrgModeCheckTime_s;/* ���ģʽȷ��ʱ�� */
extern CAL_CMM uint16_T KCHRG_ChrgOperationACTime_min;/* ������״̬�ȴ�ʱ�� */
extern CAL_CMM uint16_T KCHRG_ChrgOperationDCTime_min;/* ֱ����״̬�ȴ�ʱ�� */
extern CAL_CMM uint32_T KCHRG_ChrgParkingCheckTime_ms;/* ���ʱ�������פ��״̬����ʱ2����30��פ��״̬δ�ָ����˳���� */
extern CAL_CMM uint16_T KCHRG_ChrgPlugUnlockTime_s;/* �����������ȴ�ʱ�� */
extern CAL_CMM uint16_T KCHRG_ChrgSingalTime_ms;/* ���ʱ���������ԴӲ���źţ�����5s�����쳣�˳� */
extern CAL_CMM uint32_T KCHRG_ChrgStartACTime_s;/* �����翪ʼ�ȴ�ʱ�� */
extern CAL_CMM uint32_T KCHRG_ChrgStartDCTime_s;/* ֱ���翪ʼ�ȴ�ʱ�� */
extern CAL_CMM uint32_T KCHRG_ChrgStopCurrentLimitConfirm_ms;/* ���������Ƴ��ֹͣȷ��ʱ�� */
extern CAL_CMM uint32_T KCHRG_ChrgStopLockErrorConfirm_ms;/* ��������ֹ���ϳ��ֹͣȷ��ʱ�� */
extern CAL_CMM uint32_T KCHRG_ChrgStopOperationTimeoutConfirm_ms;/* ��������ʱ���ֹͣȷ��ʱ�� */
extern CAL_CMM uint32_T KCHRG_OBCSleepPeriod_ms;/* OBC�����źŷ������� */
extern CAL_CMM uint16_T KCHRG_OBCSleepSend_Cnt;/* OBC���߷��ʹ��� */
extern CAL_CMM uint32_T KCHRG_OBCSleepTime_ms;/* OBC���ߵȴ�ʱ�� */
extern CAL_CMM uint32_T KCHRG_OBCWakeupPeriod_ms;/* OBC���ѷ������� */
extern CAL_CMM uint16_T KCHRG_OBCWakeupSend_Cnt;/* OBC���ѷ��ʹ��� */
extern CAL_CMM uint32_T KCHRG_OBCWakeupTime_ms;/* OBC���ѵȴ�ʱ�� */
extern CAL_CMM uint16_T KCHRG_ShiftKnobCheckTime_s;/* ����ֱ�λ�ü��ȴ�ʱ�� */
extern CAL_CMM uint32_T KCHRG_WaitBMSPwrupAllwReEnableTime_ms;/* CHMA������BMS��BMSPwrupallw����Ϊ1�����ȴ�ʱ�� */
extern CAL_CMM uint32_T KCHRG_WaitBMSPwrupAllwResetTime_ms;/* CHMA������BMS��BMSPwrupallw��Ϊ0�����ȴ�ʱ�� */
extern CAL_CMM uint16_T VCHRG_ExpMode_WaitTime_ms;/* chrgmode�쳣��ȴ����份���źų��ֵ�ʱ�� */
extern CAL_CMM uint8_T VehChrgSts_ChargFinish;/* ���״̬-������ */
extern CAL_CMM uint8_T VehChrgSts_DriveCharging;/* ���״̬-��ʻ��� */
extern CAL_CMM uint8_T VehChrgSts_NoCharg;/* ���״̬-δ��� */
extern CAL_CMM uint8_T VehChrgSts_ParkCharging;/* ���״̬-ͣ����� */

#endif                                 /* RTW_HEADER_CHRG_Cal_Data_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

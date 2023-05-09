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
CAL_CMM uint8_T Config_PB_ElecPB = 1U; /* ������ɲ */
CAL_CMM uint8_T Config_PB_MachPB = 2U; /* ��е��ɲ */
CAL_CMM uint32_T KCHRG_AbnormalChrgEndTime_s = 1U;/* �쳣������ȷ��ʱ�� */
CAL_CMM uint16_T KCHRG_BMSChrgStsEndCheckTime_ms = 1000U;/* ���ֹͣȷ��ʱ�� */
CAL_CMM uint16_T KCHRG_BMSChrgStsFullCheckTime_ms = 1000U;/* �����ȷ��ʱ�� */
CAL_CMM uint16_T KCHRG_ChrgConnectCheckTime_ms = 1200U;/* ���ģʽ�����ɺ󣬳��������ǹ����״̬�����ǹ�Ͽ���ȷ��ʱ�� */
CAL_CMM uint16_T KCHRG_ChrgEndTime_s = 1U;/* ������ȷ��ʱ�� */
CAL_CMM uint32_T KCHRG_ChrgLockCheckTime_ms = 120000U;/* ��������ֹ�ȴ�ʱ�� */
CAL_CMM uint16_T KCHRG_ChrgModeCheckTime_s = 6U;/* ���ģʽȷ��ʱ�� */
CAL_CMM uint16_T KCHRG_ChrgOperationACTime_min = 10U;/* ������״̬�ȴ�ʱ�� */
CAL_CMM uint16_T KCHRG_ChrgOperationDCTime_min = 10U;/* ֱ����״̬�ȴ�ʱ�� */
CAL_CMM uint32_T KCHRG_ChrgParkingCheckTime_ms = 150000U;/* ���ʱ�������פ��״̬����ʱ2����30��פ��״̬δ�ָ����˳���� */
CAL_CMM uint16_T KCHRG_ChrgPlugUnlockTime_s = 5U;/* �����������ȴ�ʱ�� */
CAL_CMM uint16_T KCHRG_ChrgSingalTime_ms = 5000U;/* ���ʱ���������ԴӲ���źţ�����5s�����쳣�˳� */
CAL_CMM uint32_T KCHRG_ChrgStartACTime_s = 5U;/* �����翪ʼ�ȴ�ʱ�� */
CAL_CMM uint32_T KCHRG_ChrgStartDCTime_s = 60U;/* ֱ���翪ʼ�ȴ�ʱ�� */
CAL_CMM uint32_T KCHRG_ChrgStopCurrentLimitConfirm_ms = 500U;/* ���������Ƴ��ֹͣȷ��ʱ�� */
CAL_CMM uint32_T KCHRG_ChrgStopLockErrorConfirm_ms = 500U;/* ��������ֹ���ϳ��ֹͣȷ��ʱ�� */
CAL_CMM uint32_T KCHRG_ChrgStopOperationTimeoutConfirm_ms = 100U;/* ��������ʱ���ֹͣȷ��ʱ�� */
CAL_CMM uint32_T KCHRG_OBCSleepPeriod_ms = 100U;/* OBC�����źŷ������� */
CAL_CMM uint16_T KCHRG_OBCSleepSend_Cnt = 10U;/* OBC���߷��ʹ��� */
CAL_CMM uint32_T KCHRG_OBCSleepTime_ms = 2000U;/* OBC���ߵȴ�ʱ�� */
CAL_CMM uint32_T KCHRG_OBCWakeupPeriod_ms = 100U;/* OBC���ѷ������� */
CAL_CMM uint16_T KCHRG_OBCWakeupSend_Cnt = 10U;/* OBC���ѷ��ʹ��� */
CAL_CMM uint32_T KCHRG_OBCWakeupTime_ms = 120000U;/* OBC���ѵȴ�ʱ�� */
CAL_CMM uint16_T KCHRG_ShiftKnobCheckTime_s = 60U;/* ����ֱ�λ�ü��ȴ�ʱ�� */
CAL_CMM uint32_T KCHRG_WaitBMSPwrupAllwReEnableTime_ms = 60000U;/* CHMA������BMS��BMSPwrupallw����Ϊ1�����ȴ�ʱ�� */
CAL_CMM uint32_T KCHRG_WaitBMSPwrupAllwResetTime_ms = 300U;/* CHMA������BMS��BMSPwrupallw��Ϊ0�����ȴ�ʱ�� */
CAL_CMM uint16_T VCHRG_ExpMode_WaitTime_ms = 2000U;/* chrgmode�쳣��ȴ����份���źų��ֵ�ʱ�� */
CAL_CMM uint8_T VehChrgSts_ChargFinish = 4U;/* ���״̬-������ */
CAL_CMM uint8_T VehChrgSts_DriveCharging = 2U;/* ���״̬-��ʻ��� */
CAL_CMM uint8_T VehChrgSts_NoCharg = 3U;/* ���״̬-δ��� */
CAL_CMM uint8_T VehChrgSts_ParkCharging = 1U;/* ���״̬-ͣ����� */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

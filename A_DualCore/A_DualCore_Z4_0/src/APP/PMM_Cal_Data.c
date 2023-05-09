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
CAL_PMM uint32_T KPMM_BMSHeartBeatMsg_CycTime_ms = 10U;/* BMS�������ļ����ʱ�� */
CAL_PMM uint8_T KPMM_BMSMonitorDelayTime_min = 2U;/* BMS���ʱ���ӳ�ʱ�� */
CAL_PMM uint16_T KPMM_ChrgVehicleSpeedMax_kmph = 3U;/* ͣ����糵����߳��� */
CAL_PMM boolean_T KPMM_DCDCActiveCheckEnable_Flag = 1;/* DCDC��ѹ������ʹ�� */
CAL_PMM uint32_T KPMM_DCDCHeartBeatMsg_CycTime_ms = 100U;/* DCDC�������ļ����ʱ�� */
CAL_PMM uint16_T KPMM_DCDCSByMCUActive_ms = 1000U;/* �����µ磬��ʱ1sδ�յ�MCUOperMdl=3��DCDC OperMod=0 */
CAL_PMM uint8_T KPMM_DCRelayCutOffTime_s = 5U;/* ֱ��ȴ�ֱ��̵����Ͽ�ʱ�� */
CAL_PMM uint32_T KPMM_EPBAppliedTime_ms = 20000U;/* EPB��ǯ����ȴ�ʱ�� */
CAL_PMM uint8_T KPMM_EVCC_Type = 0U;   /* EVCC���ͣ�0 û�С�1 K11P01�ܹ���2 reserved */
CAL_PMM uint32_T KPMM_HVActiveDCDCTime_ms = 1000U;/* DCDC��ѹ����ȴ�ʱ�� */
CAL_PMM uint32_T KPMM_HVActiveStateKeepTime_ms = 100U;/* ��ѹ������̹���ʱ�� */
CAL_PMM uint32_T KPMM_HVActiveTime_ms = 1000U;/* ������ѹ����ȴ�ʱ�� */
CAL_PMM uint32_T KPMM_HVDownTime_ms = 1000U;/* ��ѹ�µ�ȴ�ʱ�� */
CAL_PMM uint32_T KPMM_HVEACPTCStopWorkConfirmTime_ms = 100U;/* �յ�PTCֹͣ�����ź�ȷ��ʱ�� */
CAL_PMM real32_T KPMM_HVStopWorkBMSCurrentUpper_A = 5.0F;/* ��ѹ����ֹͣ������ѹ������������ */
CAL_PMM int16_T KPMM_HVStopWorkMotorSpeedUpper_rpm = 800;/* ��ѹ����ֹͣ�������ת������ */
CAL_PMM uint16_T KPMM_HVStopWorkTime_s = 5U;/* ��ѹ����ֹͣ�����ȴ�ʱ�� */
CAL_PMM uint32_T KPMM_HVUpStateKeepTime_ms = 100U;/* ��ѹ�ϵ���̹���ʱ�� */
CAL_PMM uint16_T KPMM_HVUpTime_s = 2U; /* ��ѹ�ϵ�ȴ�ʱ�� */
CAL_PMM uint8_T KPMM_IChrgWorkTime = 60U;/* ���ܲ�����ʱ��60���� */
CAL_PMM uint32_T KPMM_KeyOnReUpConfirmTime_ms = 1000U;/* �Ͽ��̵���KeyOn��Ч�ź�ȷ��ʱ�� */
CAL_PMM uint32_T KPMM_KeyRemoteOnTimeout_ms = 2000U;/* Զ�̿յ��յ�PEPS_PDU=3��ʱ�� */
CAL_PMM uint32_T KPMM_LVDownDelayTime_ms = 100U;/* ��ѹ�µ�ȴ�ʱ�� */
CAL_PMM uint32_T KPMM_LVStandbyTime_ms = 2000U;/* ��ѹ�µ����ʱ�� */
CAL_PMM uint32_T KPMM_LVUpStateKeepTime_ms = 300U;/* ��ѹ�ϵ���̹���ʱ�� */
CAL_PMM uint32_T KPMM_LVUpTimeDCChrg_BMSPwrupallwReseted_ms = 300U;/* ֱ���ǹ��ȴ�BMSPwrupallwΪ0��ʱ�� */
CAL_PMM uint16_T KPMM_LVUpTimeDCChrg_s = 60U;/* ֱ��ʱ��ѹ�ϵ�ȴ�ʱ�� */
CAL_PMM uint32_T KPMM_LVUpTime_ms = 600U;/* ��ѹ�ϵ�ȴ�ʱ�� */
CAL_PMM uint32_T KPMM_MCUActiveTime_ms = 1000U;/* פ��ģʽ����MCU����ȴ�ʱ�� */
CAL_PMM uint16_T KPMM_MCUDischargeTime_s = 4U;/* MCU���ٷŵ�ȴ�ʱ�� */
CAL_PMM uint32_T KPMM_MCUHeartBeatMsg_CycTime_ms = 10U;/* MCU�������ļ����ʱ�� */
CAL_PMM uint32_T KPMM_MCULVDnTime_ms = 200U;/* ����פ��ģʽ�Ͽ�MCU�̵�����ʱʱ�� */
CAL_PMM uint32_T KPMM_MCULVUpTime_ms = 600U;/* פ��ģʽ����MCU��ѹ�ϵ�ȴ�ʱ�� */
CAL_PMM uint32_T KPMM_PEPSOffToAccOnConfirmTime_ms = 500U;/* PEPS��OFF�л���On��ACC�󱣳ֵ�ʱ�� */
CAL_PMM uint32_T KPMM_PEPSOnAccToOffConfirmTime_ms = 1000U;/* PEPS��ACC��On�л���OFF�󱣳ֵ�ʱ�� */
CAL_PMM boolean_T KPMM_PEPSUnlock_flg = 1;/* PEPS������־ */
CAL_PMM uint32_T KPMM_RePrechargeIntervalTime_ms = 1000U;/* Precharge����֮����Ҫ�����ʱ�� */
CAL_PMM uint32_T KPMM_RemoteACHVActiveTimeout_ms = 5000U;/* �յ�PEPS_PDU==3��ȴ���ѹ�ϵ���ɣ�����parking����ʱ�䡣 */
CAL_PMM uint32_T KPMM_RemoteACNoRequestTime_ms = 2000U;/* Զ�̿յ�������ȷ��ʱ�� */
CAL_PMM uint32_T KPMM_RemoteACOnTimeout_ms = 3000U;/* Զ�̿յ�ϵͳ��������ʱ�� */
CAL_PMM uint8_T KPMM_RemoteACStopHoldTime_min = 2U;/* Զ�̿յ�ֹͣ��������ʱ�� */
CAL_PMM real32_T KPMM_RunToChrgVehicleSpeedMax_kmph = 3.0F;
CAL_PMM uint32_T KPMM_WaitBMSIChrgEna_ms = 1000U;/* ���ܲ���ȴ�BMS������ĳ�ʱʱ�䣬��LVReady��ʼ��ʱ */
CAL_PMM uint32_T KPMM_WaitBMSSleepClearDTCTime_ms = 2000U;/* �����µ����̵����Ͽ���ȴ�BMS����������������ʱʱ�� */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

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
extern CAL_PMM uint32_T KPMM_BMSHeartBeatMsg_CycTime_ms;/* BMS�������ļ����ʱ�� */
extern CAL_PMM uint8_T KPMM_BMSMonitorDelayTime_min;/* BMS���ʱ���ӳ�ʱ�� */
extern CAL_PMM uint16_T KPMM_ChrgVehicleSpeedMax_kmph;/* ͣ����糵����߳��� */
extern CAL_PMM boolean_T KPMM_DCDCActiveCheckEnable_Flag;/* DCDC��ѹ������ʹ�� */
extern CAL_PMM uint32_T KPMM_DCDCHeartBeatMsg_CycTime_ms;/* DCDC�������ļ����ʱ�� */
extern CAL_PMM uint16_T KPMM_DCDCSByMCUActive_ms;/* �����µ磬��ʱ1sδ�յ�MCUOperMdl=3��DCDC OperMod=0 */
extern CAL_PMM uint8_T KPMM_DCRelayCutOffTime_s;/* ֱ��ȴ�ֱ��̵����Ͽ�ʱ�� */
extern CAL_PMM uint32_T KPMM_EPBAppliedTime_ms;/* EPB��ǯ����ȴ�ʱ�� */
extern CAL_PMM uint8_T KPMM_EVCC_Type; /* EVCC���ͣ�0 û�С�1 K11P01�ܹ���2 reserved */
extern CAL_PMM uint32_T KPMM_HVActiveDCDCTime_ms;/* DCDC��ѹ����ȴ�ʱ�� */
extern CAL_PMM uint32_T KPMM_HVActiveStateKeepTime_ms;/* ��ѹ������̹���ʱ�� */
extern CAL_PMM uint32_T KPMM_HVActiveTime_ms;/* ������ѹ����ȴ�ʱ�� */
extern CAL_PMM uint32_T KPMM_HVDownTime_ms;/* ��ѹ�µ�ȴ�ʱ�� */
extern CAL_PMM uint32_T KPMM_HVEACPTCStopWorkConfirmTime_ms;/* �յ�PTCֹͣ�����ź�ȷ��ʱ�� */
extern CAL_PMM real32_T KPMM_HVStopWorkBMSCurrentUpper_A;/* ��ѹ����ֹͣ������ѹ������������ */
extern CAL_PMM int16_T KPMM_HVStopWorkMotorSpeedUpper_rpm;/* ��ѹ����ֹͣ�������ת������ */
extern CAL_PMM uint16_T KPMM_HVStopWorkTime_s;/* ��ѹ����ֹͣ�����ȴ�ʱ�� */
extern CAL_PMM uint32_T KPMM_HVUpStateKeepTime_ms;/* ��ѹ�ϵ���̹���ʱ�� */
extern CAL_PMM uint16_T KPMM_HVUpTime_s;/* ��ѹ�ϵ�ȴ�ʱ�� */
extern CAL_PMM uint8_T KPMM_IChrgWorkTime;/* ���ܲ�����ʱ��60���� */
extern CAL_PMM uint32_T KPMM_KeyOnReUpConfirmTime_ms;/* �Ͽ��̵���KeyOn��Ч�ź�ȷ��ʱ�� */
extern CAL_PMM uint32_T KPMM_KeyRemoteOnTimeout_ms;/* Զ�̿յ��յ�PEPS_PDU=3��ʱ�� */
extern CAL_PMM uint32_T KPMM_LVDownDelayTime_ms;/* ��ѹ�µ�ȴ�ʱ�� */
extern CAL_PMM uint32_T KPMM_LVStandbyTime_ms;/* ��ѹ�µ����ʱ�� */
extern CAL_PMM uint32_T KPMM_LVUpStateKeepTime_ms;/* ��ѹ�ϵ���̹���ʱ�� */
extern CAL_PMM uint32_T KPMM_LVUpTimeDCChrg_BMSPwrupallwReseted_ms;/* ֱ���ǹ��ȴ�BMSPwrupallwΪ0��ʱ�� */
extern CAL_PMM uint16_T KPMM_LVUpTimeDCChrg_s;/* ֱ��ʱ��ѹ�ϵ�ȴ�ʱ�� */
extern CAL_PMM uint32_T KPMM_LVUpTime_ms;/* ��ѹ�ϵ�ȴ�ʱ�� */
extern CAL_PMM uint32_T KPMM_MCUActiveTime_ms;/* פ��ģʽ����MCU����ȴ�ʱ�� */
extern CAL_PMM uint16_T KPMM_MCUDischargeTime_s;/* MCU���ٷŵ�ȴ�ʱ�� */
extern CAL_PMM uint32_T KPMM_MCUHeartBeatMsg_CycTime_ms;/* MCU�������ļ����ʱ�� */
extern CAL_PMM uint32_T KPMM_MCULVDnTime_ms;/* ����פ��ģʽ�Ͽ�MCU�̵�����ʱʱ�� */
extern CAL_PMM uint32_T KPMM_MCULVUpTime_ms;/* פ��ģʽ����MCU��ѹ�ϵ�ȴ�ʱ�� */
extern CAL_PMM uint32_T KPMM_PEPSOffToAccOnConfirmTime_ms;/* PEPS��OFF�л���On��ACC�󱣳ֵ�ʱ�� */
extern CAL_PMM uint32_T KPMM_PEPSOnAccToOffConfirmTime_ms;/* PEPS��ACC��On�л���OFF�󱣳ֵ�ʱ�� */
extern CAL_PMM boolean_T KPMM_PEPSUnlock_flg;/* PEPS������־ */
extern CAL_PMM uint32_T KPMM_RePrechargeIntervalTime_ms;/* Precharge����֮����Ҫ�����ʱ�� */
extern CAL_PMM uint32_T KPMM_RemoteACHVActiveTimeout_ms;/* �յ�PEPS_PDU==3��ȴ���ѹ�ϵ���ɣ�����parking����ʱ�䡣 */
extern CAL_PMM uint32_T KPMM_RemoteACNoRequestTime_ms;/* Զ�̿յ�������ȷ��ʱ�� */
extern CAL_PMM uint32_T KPMM_RemoteACOnTimeout_ms;/* Զ�̿յ�ϵͳ��������ʱ�� */
extern CAL_PMM uint8_T KPMM_RemoteACStopHoldTime_min;/* Զ�̿յ�ֹͣ��������ʱ�� */
extern CAL_PMM real32_T KPMM_RunToChrgVehicleSpeedMax_kmph;
extern CAL_PMM uint32_T KPMM_WaitBMSIChrgEna_ms;/* ���ܲ���ȴ�BMS������ĳ�ʱʱ�䣬��LVReady��ʼ��ʱ */
extern CAL_PMM uint32_T KPMM_WaitBMSSleepClearDTCTime_ms;/* �����µ����̵����Ͽ���ȴ�BMS����������������ʱʱ�� */

#endif                                 /* RTW_HEADER_PMM_Cal_Data_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

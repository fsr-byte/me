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
CAL_BTK uint32_T KBTK_CheckRelayTime_ms = 100U;/* �̵����պϺ󵽶�ȡ������ѹ����ʱʱ�� */
CAL_BTK uint8_T KBTK_ChrgAndUDSAllwSpeed = 3U;/* ����������UDS����Ŀ���Դģʽ�ĳ�����ֵ */
CAL_BTK uint32_T KBTK_ERROR_FLASH_Time = 4000U;/* ��Դ�л�ʧ��RedLED��˸ʱ�� */
CAL_BTK real32_T KBTK_ESCLLockAllwSpeed = 0.0F;/* ����ESCL�����ĳ�����ֵ */
CAL_BTK boolean_T KBTK_EraseESKUPAllw_Flg = 1;/* ����ESKʱ��ҪUDS����Ҫ��ESCL����ʧ��Ҳ�����ϵ� */
CAL_BTK uint32_T KBTK_MEKSigSynTime_ms = 80U;/* ACC��ON�ź�ͬ��ʱ�䣨Կ��Ѹ��ͨOFF��ON��ON��OFF�����У� */
CAL_BTK uint32_T KBTK_MaxSSBDiffTime_ms = 80U;/* ��·����Ӳ���źŲ�ͬ�������ʱ�� */
CAL_BTK uint32_T KBTK_MaxTimeInOnState_ms = 1800000U;/* ��ѹON���������ʱ��30mins = 1800000ms */
CAL_BTK uint8_T KBTK_PwrOffCarSpeed = 10U;/* �����˳�STARTģʽ�ĳ�����ֵ */
CAL_BTK uint32_T KBTK_RelayVoltInValidThreshold = 1U;/* �̵����Ͽ�������ѹ��ֵ */
CAL_BTK uint32_T KBTK_RelayVoltValidThreshold = 8U;/* �̵����պϷ�����ѹ��С��ֵ */
CAL_BTK uint32_T KBTK_RelayWrongThreshold_ms = 120U;/* �̵���������ѹ����ȷ��ʱ�䣬�����������λ */
CAL_BTK uint32_T KBTK_SSBAdhesionConfirmTime_ms = 3000U;/* SSB�������ȷ��ʱ�� */
CAL_BTK uint32_T KBTK_SSBConfirmTime_ms = 100U;/* SSB�����ź�ȷ��ʱ�� */
CAL_BTK uint32_T KBTK_SigConfirmTime_ms = 100U;/* ���˻���Դ���ź�ȷ��ʱ��-�˲� */
CAL_BTK uint32_T KBTK_StateSwitchDelay_ms = 1000U;/* SSB�����źŴ�������Сʱ���� */
CAL_BTK uint32_T KBTK_WODriver_ConfirmTime_ms = 1000U;/* ���������ź�ȷ����ʱʱ�� */
CAL_BTK uint32_T KBTK_WaitAuthRsltDelay_ms = 1000U;/* �ȴ�������֤���ʱ�� */
CAL_BTK uint32_T KBTK_WaitESCLRxReq = 100U;/* �ȴ�ESCLģ������������ʱʱ�� */
CAL_BTK uint32_T KBTK_waitForEsclLockTime_ms = 2000U;/* �ȴ�ESCL������ʱʱ�� */
CAL_BTK uint32_T KBTK_waitForEsclUnlockTime_ms = 2000U;/* �ȴ�ESCL������ʱʱ�� */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

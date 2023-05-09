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
#define BTK_REMIND_ESCLLOCK            3U                        /* ESCL����ʧ�� */
#define BTK_REMIND_ESCLUNLOCK          2U                        /* ESCL����ʧ�� */
#define BTK_REMIND_FAULT               5U                        /* �������ϲ���Ӧ�ϵ� */
#define BTK_REMIND_NONE                0U                        /* �޵�Դģʽ�л�ʧ�� */
#define BTK_REMIND_OTHER               7U                        /* ģʽ�л�ʧ��-����ԭ�� */
#define BTK_REMIND_STARTDOWN           4U                        /* ���ٹ��ߣ������˳�START */
#define BTK_REMIND_TBOXCHECK           1U                        /* �û�Կ�������֤ʧ�� */
#define BTK_REMIND_UDS                 6U                        /* UDS��������У�����Ӧ��Դ�л����� */
#define BTK_TBOX_REMOTE_LOCK           1U
#define BTK_TRUE                       1
#define TBOX_RSP_KEYAUTHFILED          95U                       /* 0x5F:Key Authentication is Failed, the encrypted response key shall be all 0x00 Կ����֤ʧ��,�����������ȫ0x00��Ӧ */

/* Exported data declaration */
#include "derivative.h"

/* Declaration for custom storage class: CAL_16_BTK */
extern CAL_BTK uint32_T KBTK_CheckRelayTime_ms;/* �̵����պϺ󵽶�ȡ������ѹ����ʱʱ�� */
extern CAL_BTK uint8_T KBTK_ChrgAndUDSAllwSpeed;/* ����������UDS����Ŀ���Դģʽ�ĳ�����ֵ */
extern CAL_BTK uint32_T KBTK_ERROR_FLASH_Time;/* ��Դ�л�ʧ��RedLED��˸ʱ�� */
extern CAL_BTK real32_T KBTK_ESCLLockAllwSpeed;/* ����ESCL�����ĳ�����ֵ */
extern CAL_BTK boolean_T KBTK_EraseESKUPAllw_Flg;/* ����ESKʱ��ҪUDS����Ҫ��ESCL����ʧ��Ҳ�����ϵ� */
extern CAL_BTK uint32_T KBTK_MEKSigSynTime_ms;/* ACC��ON�ź�ͬ��ʱ�䣨Կ��Ѹ��ͨOFF��ON��ON��OFF�����У� */
extern CAL_BTK uint32_T KBTK_MaxSSBDiffTime_ms;/* ��·����Ӳ���źŲ�ͬ�������ʱ�� */
extern CAL_BTK uint32_T KBTK_MaxTimeInOnState_ms;/* ��ѹON���������ʱ��30mins = 1800000ms */
extern CAL_BTK uint8_T KBTK_PwrOffCarSpeed;/* �����˳�STARTģʽ�ĳ�����ֵ */
extern CAL_BTK uint32_T KBTK_RelayVoltInValidThreshold;/* �̵����Ͽ�������ѹ��ֵ */
extern CAL_BTK uint32_T KBTK_RelayVoltValidThreshold;/* �̵����պϷ�����ѹ��С��ֵ */
extern CAL_BTK uint32_T KBTK_RelayWrongThreshold_ms;/* �̵���������ѹ����ȷ��ʱ�䣬�����������λ */
extern CAL_BTK uint32_T KBTK_SSBAdhesionConfirmTime_ms;/* SSB�������ȷ��ʱ�� */
extern CAL_BTK uint32_T KBTK_SSBConfirmTime_ms;/* SSB�����ź�ȷ��ʱ�� */
extern CAL_BTK uint32_T KBTK_SigConfirmTime_ms;/* ���˻���Դ���ź�ȷ��ʱ��-�˲� */
extern CAL_BTK uint32_T KBTK_StateSwitchDelay_ms;/* SSB�����źŴ�������Сʱ���� */
extern CAL_BTK uint32_T KBTK_WODriver_ConfirmTime_ms;/* ���������ź�ȷ����ʱʱ�� */
extern CAL_BTK uint32_T KBTK_WaitAuthRsltDelay_ms;/* �ȴ�������֤���ʱ�� */
extern CAL_BTK uint32_T KBTK_WaitESCLRxReq;/* �ȴ�ESCLģ������������ʱʱ�� */
extern CAL_BTK uint32_T KBTK_waitForEsclLockTime_ms;/* �ȴ�ESCL������ʱʱ�� */
extern CAL_BTK uint32_T KBTK_waitForEsclUnlockTime_ms;/* �ȴ�ESCL������ʱʱ�� */

#endif                                 /* RTW_HEADER_BTK_Cal_Data_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

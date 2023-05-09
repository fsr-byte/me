/*
 * File: SCR_Cal_Data.c
 *
 * Code generated for Simulink model 'SCR_model'.
 *
 * Model version                  : 1.2266
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Fri Mar 18 15:47:47 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Freescale->32-bit PowerPC
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. MISRA C:2012 guidelines
 * Validation result: Not run
 */

#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "SCR_model_types.h"

/* Exported data definition */
#include "derivative.h"

/* Definition for custom storage class: CAL_11_SCR */
CAL_SCR uint8_T CLTC = 7U;             /* CLTC���ܵ��ٹ�����־λ7 */
CAL_SCR uint8_T CLTC_SOC40 = 5U;       /* CLTC���ܵ��ٹ�����־λ5 */
CAL_SCR uint8_T CLTC_SOC50 = 4U;       /* CLTC���ܵ��ٹ�����־λ4 */
CAL_SCR uint8_T CLTC_SOC60 = 3U;       /* CLTC���ܵ��ٹ�����־λ3 */
CAL_SCR uint8_T CLTC_SOC70 = 2U;       /* CLTC���ܵ��ٹ�����־λ2 */
CAL_SCR uint8_T CLTC_SOC80 = 1U;       /* CLTC���ܵ��ٹ�����־λ1 */
CAL_SCR uint16_T CRS_No_Evflag_TrueDelay = 80U;/* ʹ�ܼ��ٶ��㷨 */
CAL_SCR uint16_T KCRS_AccelPdlInvalidJudgeTime_ms = 5000U;/* ����̤����Ч�ж�ʱ�� */
CAL_SCR uint16_T KCRS_BrakePdlInvalidJudgeTime_ms = 5000U;/* �ƶ�̤����Ч�ж�ʱ�� */
CAL_SCR boolean_T KCRS_CRUISECtrlErr_Ena = 0;/* ����Ѳ��ϵͳ���Ͽ���ʹ������ */
CAL_SCR uint8_T KCRS_CRUISECtrlErr_Val = 0U;/* ����Ѳ��ϵͳ���Ͽ���ʹ��Ĭ��ֵ */
CAL_SCR uint32_T KCRS_CRUISECtrlErr_holdtime_ms = 10000U;/* ����Ѳ��Ӳ�����ϵ������ϵ��ӳ�ʱ�� */
CAL_SCR boolean_T KCRS_CRUISECtrlSys_Ena = 0;/* ����Ѳ��ϵͳ״̬����ʹ������ */
CAL_SCR uint8_T KCRS_CRUISECtrlSys_Val = 0U;/* ����Ѳ��ϵͳ���Ͽ���ʹ��Ĭ��ֵ */
CAL_SCR boolean_T KCRS_CRUISEModStop_Ena = 0;/* ����Ѳ���������ѿ��� */
CAL_SCR boolean_T KCRS_CRUISEModStop_Val = 0;/* ����Ѳ���������ѿ����� */
CAL_SCR uint32_T KCRS_CruiseMaxMinSpdJudge_delta = 2048U;/* Cruise��������ٵĲ���ֵ */
CAL_SCR uint32_T KCRS_CruiseMaxSpd = 133120U;/* Cruise��������� */
CAL_SCR uint32_T KCRS_CruiseMinSpd = 30720U;/* Cruise��С������ */
CAL_SCR uint32_T KCRS_CruiseMinSpdNoTouchCheckTime_ms = 30000U;/* ����Ѳ��ʵ�ʳ���С��Ѳ�������ж�ʱ�� */
CAL_SCR uint8_T KCRS_CruiseMinSpdNoTouchJudge_delta = 7U;/* ����Ѳ��ʵ�ʳ���С��Ѳ�������жϳ��ٲ���ֵ */
CAL_SCR boolean_T KCRS_CruiseModuleWork_Ena = 1;/* ����Ѳ����������ʹ������ */
CAL_SCR boolean_T KCRS_CruiseModuleWork_Val = 0;/* ����Ѳ����������ʹ����ֵ */
CAL_SCR boolean_T KCRS_CruiseResumeMode_En = 1;/* ����Ѳ��Resume����ʹ�ܿ��� */
CAL_SCR boolean_T KCRS_CruiseVehSpdMode_en = 1;/* ����Ѳ�����복��ģʽѡ�񿪹� */
CAL_SCR uint16_T KCRS_CruiseVehSpdSatisfyCheckTime_ms = 100U;/* ʵ�ʳ�������Ѳ�����ٵĳ����ж�ʱ�� */
CAL_SCR uint16_T KCRS_GearInvalidJudgeTime_ms = 5000U;/* ��λ��Ч�ж�ʱ�� */
CAL_SCR uint16_T KCRS_ICMVehpdDisp_Filter = 100U;/* ����Ѳ�������Ǳ����˲������˲�ϵ�� */
CAL_SCR boolean_T KCRS_ICMVehpdDisp_Filter_en = 1;/* ����Ѳ�������Ǳ����˲����ܿ��� */
CAL_SCR uint16_T KCRS_KeyLongPressActiveTime_mS = 400U;/* SET/RES���������ж���Сʱ�� */
CAL_SCR uint32_T KCRS_KeyResActiveTime_mS = 300U;/* ����Ѳ���ָ������ж�ʱ�� */
CAL_SCR uint32_T KCRS_KeySetActiveTime_mS = 50U;/* ����Ѳ���趨�����ж�ʱ�� */
CAL_SCR uint16_T KCRS_KeyShortPressActiveTime_mS = 50U;/* �����̰��ж���Сʱ�� */
CAL_SCR uint32_T KCRS_LongPressStepTime_mS = 1200U;/* ����Ѳ���������ٽ�Ծʽ�����ж�ʱ�� */
CAL_SCR uint32_T KCRS_MinorCruiseFaultDelayTime_ms = 100U;/* ��΢���ϻָ������ж�ʱ�� */
CAL_SCR real32_T KCRS_PID_IntegralMax = 60.0F;/* PID�����������ֵ */
CAL_SCR real32_T KCRS_PID_IntegralMin = -50.0F;/* �ο������������ն��������Ť��ֵ */
CAL_SCR real32_T KCRS_PID_PidMax = 90.0F;/* PID�����ֵ */
CAL_SCR real32_T KCRS_PID_PidMin = -50.0F;/* �ο������������ն��������Ť��ֵ */
CAL_SCR real32_T KCRS_PID_SpdDelta_Max = 5.0F;/* PID�ٶ�ƫ��ֵ�������ֵ */
CAL_SCR real32_T KCRS_PID_SpdDelta_Min = -5.0F;/* PID�ٶ�ƫ��ֵ������Сֵ */
CAL_SCR uint16_T KCRS_PressOnOffDebounceThreshold = 40U;/* �������º��ɿ��ķ�������ֵʱ�� */
CAL_SCR uint8_T KCRS_QuitCruise_PowerLimitPct = 50U;/* ��DHP�޹��ʰٷֱ�С�ڸ�ֵʱ���رն���Ѳ�� */
CAL_SCR uint32_T KCRS_QuitCruise_TargetVehSpdDiff_HoldTime_ms = 300000U;/* ��abs(ʵ�ʳ���-Ŀ�공��)���ڸ�ֵ���ҳ���һ��ʱ��ʱ���˳�����Ѳ�� */
CAL_SCR uint32_T KCRS_QuitCruise_TargetVehSpdDiff_kph = 30720U;/* ��abs(ʵ�ʳ���-Ŀ�공��)���ڸ�ֵ���ҳ���һ��ʱ��ʱ���˳�����Ѳ�� */
CAL_SCR uint32_T KCRS_QuitCruise_VehSpdLimit = 40U;/* �˳�����Ѳ�����ܺ�ϵͳ��С���� */
CAL_SCR uint32_T KCRS_RealSpdOffUpLimit_HoldTime_ms = 30000U;/* ����Ѳ��ʵ�ʳ��ٳ�������ٹ����ж�ʱ�� */
CAL_SCR uint8_T KCRS_RealSpdOffUpLimit_delta = 5U;/* ����Ѳ��ʵ�ʳ��ٳ�������ٹ��ϳ��ٲ���ֵ */
CAL_SCR real32_T KCRS_SpdCon_PIDAccDecKiX_kph[6] =
{
    20.0F, 40.0F, 60.0F, 80.0F, 100.0F, 120.0F
} ;                                    /* �����ӳ������ٹ�����Ŀ��Ѳ������ */

CAL_SCR real32_T KCRS_SpdCon_PIDAccDecKiY_kph[9] =
{
    -5.0F, -3.0F, -1.0F, -0.5F, 0.0F, 0.5F, 1.0F, 3.0F, 5.0F
} ;                                    /* �����ӳ������ٹ�����Ŀ��Ѳ�����ٺ�ʵ�ʳ��ٵ��ٶȲ����I�������������趨Ŀ��Ѳ������ */

CAL_SCR real32_T KCRS_SpdCon_PIDAccDecKiZ[54] =
{
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.001F, 0.001F, 0.001F, 0.001F, 0.001F,
    0.001F, 0.001F, 0.001F, 0.001F, 0.001F, 0.001F, 0.001F, 0.001F, 0.001F,
    0.001F, 0.001F, 0.001F, 0.001F, 0.001F, 0.001F, 0.001F, 0.001F, 0.001F,
    0.001F, 0.001F, 0.001F, 0.001F, 0.001F, 0.001F, 0.001F, 0.001F, 0.001F,
    0.001F, 0.001F, 0.001F, 0.001F, 0.001F, 0.001F, 0.001F, 0.001F, 0.001F,
    0.001F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F
} ;                                    /* �����ӳ������ٹ�����PID Ki�������趨Ŀ��Ѳ������ */

CAL_SCR real32_T KCRS_SpdCon_PIDAccDecKpX_kph[6] =
{
    20.0F, 40.0F, 60.0F, 80.0F, 100.0F, 120.0F
} ;                                    /* �����ӳ������ٹ�����Ŀ��Ѳ������ */

CAL_SCR real32_T KCRS_SpdCon_PIDAccDecKpY_kph[7] =
{
    -5.0F, -3.0F, -1.0F, 0.0F, 1.0F, 3.0F, 5.0F
} ;                                    /* �����ӳ������ٹ�����Ŀ��Ѳ�����ٺ�ʵ�ʳ��ٵ��ٶȲ����P�������������趨Ŀ��Ѳ������ */

CAL_SCR real32_T KCRS_SpdCon_PIDAccDecKpZ[42] =
{
    6.0F, 6.0F, 6.0F, 6.0F, 6.0F, 6.0F, 8.0F, 8.0F, 8.0F, 8.0F, 8.0F, 8.0F, 8.0F,
    8.0F, 8.0F, 8.0F, 8.0F, 8.0F, 8.0F, 8.0F, 8.0F, 8.0F, 8.0F, 8.0F, 12.0F,
    12.0F, 12.0F, 12.0F, 12.0F, 12.0F, 12.0F, 12.0F, 12.0F, 12.0F, 12.0F, 12.0F,
    10.0F, 10.0F, 10.0F, 10.0F, 10.0F, 10.0F
} ;                                    /* �����ӳ������ٹ�����PID Kp�������趨Ŀ��Ѳ������ */

CAL_SCR real32_T KCRS_SpdCon_PIDSetResumeKiX_kph[6] =
{
    20.0F, 40.0F, 60.0F, 80.0F, 100.0F, 120.0F
} ;                                    /* ���趨�ָ�������Ŀ��Ѳ������ */

CAL_SCR real32_T KCRS_SpdCon_PIDSetResumeKiY_kph[9] =
{
    -5.0F, -4.99F, -1.0F, -0.5F, 0.0F, 0.5F, 1.0F, 4.99F, 5.0F
} ;                                    /* ���趨�ָ�������Ŀ��Ѳ�����ٺ�ʵ�ʳ��ٵ��ٶȲ����I���֣��������趨Ŀ��Ѳ������ */

CAL_SCR real32_T KCRS_SpdCon_PIDSetResumeKiZ[54] =
{
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F,
    0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F,
    0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F,
    0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F,
    0.01F, 0.01F, 0.01F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F
} ;                                    /* ���趨�ָ�������PID Ki�������趨Ŀ��Ѳ������ */

CAL_SCR real32_T KCRS_SpdCon_PIDSetResumeKpX_kph[6] =
{
    20.0F, 40.0F, 60.0F, 80.0F, 100.0F, 120.0F
} ;                                    /* ���趨�ָ�������Ŀ��Ѳ������ */

CAL_SCR real32_T KCRS_SpdCon_PIDSetResumeKpY_kph[9] =
{
    -5.0F, -3.0F, -1.0F, -0.5F, 0.0F, 0.5F, 1.0F, 3.0F, 5.0F
} ;                                    /* ���趨�ָ�������Ŀ��Ѳ�����ٺ�ʵ�ʳ��ٵ��ٶȲ����P�������������趨Ŀ��Ѳ������ */

CAL_SCR real32_T KCRS_SpdCon_PIDSetResumeKpZ[54] =
{
    15.0F, 15.0F, 15.0F, 15.0F, 15.0F, 15.0F, 14.0F, 14.0F, 14.0F, 14.0F, 14.0F,
    14.0F, 10.0F, 10.0F, 10.0F, 10.0F, 10.0F, 10.0F, 5.0F, 5.0F, 5.0F, 5.0F,
    5.0F, 5.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F,
    5.0F, 10.0F, 10.0F, 10.0F, 10.0F, 10.0F, 10.0F, 14.0F, 14.0F, 14.0F, 14.0F,
    14.0F, 14.0F, 15.0F, 15.0F, 15.0F, 15.0F, 15.0F, 15.0F
} ;                                    /* ���趨�ָ�������PID Kp�������趨Ŀ��Ѳ������ */

CAL_SCR real32_T KCRS_SpdCon_PIDTipUpDownKiX_kph[5] =
{
    20.0F, 40.0F, 70.0F, 100.0F, 120.0F
} ;                                    /* ����ӵ�����ٹ�����Ŀ��Ѳ������ */

CAL_SCR real32_T KCRS_SpdCon_PIDTipUpDownKiY_kph[9] =
{
    -4.0F, -3.0F, -2.0F, -1.0F, 0.0F, 1.0F, 2.0F, 3.0F, 4.0F
} ;                                    /* ����ӵ�����ٹ�����Ŀ��Ѳ�����ٺ�ʵ�ʳ��ٵ��ٶȲ����I�������������趨Ŀ��Ѳ������ */

CAL_SCR real32_T KCRS_SpdCon_PIDTipUpDownKiZ[45] =
{
    0.025F, 0.025F, 0.05F, 0.075F, 0.1F, 0.033F, 0.033F, 0.067F, 0.1F, 0.133F,
    0.05F, 0.05F, 0.1F, 0.15F, 0.2F, 0.1F, 0.1F, 0.2F, 0.3F, 0.4F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.1F, 0.1F, 0.2F, 0.3F, 0.4F, 0.05F, 0.05F, 0.1F, 0.15F,
    0.2F, 0.033F, 0.033F, 0.067F, 0.1F, 0.133F, 0.025F, 0.025F, 0.05F, 0.075F,
    0.1F
} ;                                    /* ����ӵ�����ٹ�����PID Ki�������趨Ŀ��Ѳ������ */

CAL_SCR real32_T KCRS_SpdCon_PIDTipUpDownKpX_kph[6] =
{
    20.0F, 40.0F, 60.0F, 80.0F, 100.0F, 120.0F
} ;                                    /* ����ӵ�����ٹ�����Ŀ��Ѳ������ */

CAL_SCR real32_T KCRS_SpdCon_PIDTipUpDownKpY_kph[7] =
{
    -5.0F, -3.0F, -1.0F, 0.0F, 1.0F, 3.0F, 5.0F
} ;                                    /* ����ӵ�����ٹ�����Ŀ��Ѳ�����ٺ�ʵ�ʳ��ٵ��ٶȲ����P�������������趨Ŀ��Ѳ������ */

CAL_SCR real32_T KCRS_SpdCon_PIDTipUpDownKpZ[42] =
{
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F
} ;                                    /* ����ӵ�����ٹ�����PID Kp�������趨Ŀ��Ѳ������ */

CAL_SCR real32_T KCRS_SpdCon_PID_IntegralHoldExit_SpdDelta = 0.3F;/* ��ʵ�ʳ��ٺ�Ŀ��Ѳ�����ٵĲ�ֵ�ȶ���1kph���ڣ�������ָ��ʱ��5s(TBD)ʱ��PID���������� */
CAL_SCR uint16_T KCRS_SpdCon_PID_IntegralHoldExit_SpdDelta_Time_ms = 1000U;/* ��ʵ�ʳ��ٺ�Ŀ��Ѳ�����ٵĲ�ֵ�ȶ���1kph���ڣ�������ָ��ʱ��5s(TBD)ʱ��PID���������� */
CAL_SCR real32_T KCRS_SpdCon_PID_IntegralHold_SpdDelta = 0.3F;/* ��ʵ�ʳ��ٺ�Ŀ��Ѳ�����ٵĲ�ֵ�ȶ���1kph���ڣ�������ָ��ʱ��5s(TBD)ʱ��PID���������� */
CAL_SCR uint16_T KCRS_SpdCon_PID_IntegralHold_SpdDelta_Time_ms = 5000U;/* ��ʵ�ʳ��ٺ�Ŀ��Ѳ�����ٵĲ�ֵ�ȶ���1kph���ڣ�������ָ��ʱ��5s(TBD)ʱ��PID���������� */
CAL_SCR boolean_T KCRS_SpdCon_Pid_EnableFlag = 1;/* ʹ��PID */
CAL_SCR boolean_T KCRS_SpdCon_VehDyn_EnableFlag = 0;/* ʹ�ܳ���������ѧģ�� */
CAL_SCR uint16_T KCRS_TargetVehSpdDiff_DelayTime_ms = 5000U;/* ����Ѳ���������޵��³����쳣�˳�Ѳ��״̬��������ʱ�� */
CAL_SCR real32_T KCRS_TorqFlt_FirstOrderDownRatio = 0.8F;/* ����Ѳ��Ť��һ���˲�����(�½���) */
CAL_SCR real32_T KCRS_TorqFlt_FirstOrderUpRatio = 0.8F;/* ����Ѳ��Ť��һ���˲�����(������) */
CAL_SCR real32_T KCRS_TorqFlt_GradLimLowVal = -2.0F;/* ���ٶȵ����jerkͨ����ֵ������
                                                       ��ֵ�ļ��㷽�����£��������ٶ�jerkΪ-1.5m/s3������ʱ��Ϊ0.02s��ʹ��������ѧ��ʽ�еļ������������㣺
                                                       1575*-1.5*0.02*1.05*0.3234/7.93/0.973=-3.46 */
CAL_SCR real32_T KCRS_TorqFlt_GradLimMaxVal = 121.0F;/* �ݶ����ƺ��������������Ť��
                                                        ��ֵ�ļ��㷽�����£��������ٶ�Ϊ1.75m/sʹ��������ѧ��ʽ�еļ������������㣺
                                                        1575*1.75*1.05*0.3234/7.93/0.973=121 */
CAL_SCR real32_T KCRS_TorqFlt_GradLimMinVal = -50.0F;/* �ο������������ն��������Ť��ֵ */
CAL_SCR real32_T KCRS_TorqFlt_GradLimUpVal = 2.0F;/* ���ٶȵ����jerkͨ����ֵ������
                                                     ��ֵ�ļ��㷽�����£��������ٶ�jerkΪ1.5m/s3������ʱ��Ϊ0.02s��ʹ��������ѧ��ʽ�еļ������������㣺
                                                     1575*1.5*0.02*1.05*0.3234/7.93/0.973=3.46 */
CAL_SCR real32_T KCRS_VehDyn_TorqueMax = 80.0F;/* ����������ѧ��������������Ť�� */
CAL_SCR real32_T KCRS_VehDyn_TorqueMin = -80.0F;/* ����������ѧ����С���������Ť�� */
CAL_SCR uint32_T KCRS_VehSpdCheckDelayTime_period = 250U;/* ����ABS���ٱ仯�쳣���м������ */
CAL_SCR uint16_T KCRS_VehSpdInvalidJudgeTime_ms = 3000U;/* ������Ч�ж�ʱ�� */
CAL_SCR uint8_T KCRS_t_CRUISECtrlSysDelayTime_ms = 60U;/* ����Ѳ��Runģʽ�˳�ȷ��ʱ�� */
CAL_SCR uint16_T KCRS_t_CancelPress_ms = 60U;/* ����Ѳ��Cancel�����жϣ�N�����г̲���ͣ��ʱ�� */
CAL_SCR uint32_T KCRS_t_CruiseRun_ms = 60U;/* ����Ѳ�����������趨�����ж�ʱ�� */
CAL_SCR uint32_T KHDC_ABSSpeedSatisfy_Delaytime_ms = 100U;/* ���»���ʹ��������������ȷ��ʱ�� */
CAL_SCR uint32_T KHDC_AccSpdThreshold_Delaytime1_ms = 500U;/* ���»���ʹ�ܼ��ٶ���������ж�ʱ��1 */
CAL_SCR uint32_T KHDC_AccSpdThreshold_Delaytime2_ms = 300U;/* ���»���ʹ�ܼ��ٶ���������ж�ʱ��2 */
CAL_SCR uint32_T KHDC_AccSpdThreshold_Delaytime3_ms = 150U;/* ���»���ʹ�ܼ��ٶ���������ж�ʱ��3 */
CAL_SCR uint8_T KHDC_AccSpd_Filter = 50U;/* ���»������ٶ�һ���˲����� */
CAL_SCR int32_T KHDC_AccSpd_Threshold1_mpss = 307;/* ���»���ʹ�ܼ��ٶ���ֵ1 */
CAL_SCR int32_T KHDC_AccSpd_Threshold2_mpss = 410;/* ���»���ʹ�ܼ��ٶ���ֵ2 */
CAL_SCR int32_T KHDC_AccSpd_Threshold3_mpss = 512;/* ���»���ʹ�ܼ��ٶ���ֵ3 */
CAL_SCR uint32_T KHDC_AcceMode_Delaytime_ms = 50U;/* ���»���ʹ����������Ť���ж�ʱ�� */
CAL_SCR boolean_T KHDC_C_HDC_En = 1;   /* ���»�������ʹ�� */
CAL_SCR real32_T KHDC_CreepGearDSpd_Threshold_KPH = 6.0F;/* ���»����˳���������D�����Ƴ�����ֵ */
CAL_SCR real32_T KHDC_CreepGearRSpd_Threshold_KPH = 4.0F;/* ���»����˳���������R�����Ƴ�����ֵ */
CAL_SCR uint8_T KHDC_DHPLimitSpd_Threshold_Nm = 8U;/* ���»���ʹ�����ģ�����Ƴ�����С��ֵ */
CAL_SCR uint8_T KHDC_GearDSpdLower_KPH = 8U;/* ���»���ʹ������D���������� */
CAL_SCR uint8_T KHDC_GearDSpdUpper_KPH = 20U;/* ���»���ʹ������D���������� */
CAL_SCR real32_T KHDC_GearD_AcceMode_Threshold_Nm = 1.0F;/* ���»���ʹ������D������Ť���ж���ֵ */
CAL_SCR int16_T KHDC_GearD_VehTq_Threshold_Nm = -10;/* ���»������ƶ��˳�ʱD��Ť������ */
CAL_SCR uint8_T KHDC_GearRSpdLower_KPH = 6U;/* ���»���ʹ������R���������� */
CAL_SCR uint8_T KHDC_GearRSpdUpper_KPH = 20U;/* ���»���ʹ������R���������� */
CAL_SCR real32_T KHDC_GearR_AcceMode_Threshold_Nm = -1.0F;/* ���»���ʹ������R������Ť���ж���ֵ */
CAL_SCR int16_T KHDC_GearR_VehTq_Threshold_Nm = 10;/* ���»������ƶ��˳�ʱR��Ť������ */
CAL_SCR boolean_T KHDC_HDCrun_Ena = 0; /* ���»���ʹ�ܿ��� */
CAL_SCR boolean_T KHDC_HDCrun_Val = 0; /* ���»���ʹ����ֵ */
CAL_SCR real32_T KHDC_Kalman_P = 10.0F;/* ���»������ٶȿ������˲�P���� */
CAL_SCR real32_T KHDC_Kalman_Q = 0.1F; /* ���»������ٶȿ������˲�Q���� */
CAL_SCR real32_T KHDC_Kalman_R = 1.0F; /* ���»������ٶȿ������˲�R���� */
CAL_SCR int16_T KHDC_MCUMinRegenAvlTq_Nm = -5;/* ���»���ʹ������MCU����������СŤ����ֵ */
CAL_SCR real32_T KHDC_PID_IntegralMax = 50.0F;/* ���»���PID������ֲ������ֵ */
CAL_SCR real32_T KHDC_PID_IntegralMin = -30.0F;/* ���»���PID������ֲ�����Сֵ */
CAL_SCR real32_T KHDC_PID_PidMax = 100.0F;/* ���»���PID�����������ܺ����ֵ */
CAL_SCR real32_T KHDC_PID_PidMin = -100.0F;/* ���»���PID�����������ܺ���Сֵ */
CAL_SCR uint8_T KHDC_PID_SpdDelta_Max = 5U;/* ���»���PID��������ٶȲ� */
CAL_SCR int8_T KHDC_PID_SpdDelta_Min = -5;/* ���»���PID������С�ٶȲ� */
CAL_SCR real32_T KHDC_SpdCon_PIDCalculateKiX_kph[7] =
{
    5.0F, 10.0F, 15.0F, 20.0F, 25.0F, 30.0F, 35.0F
} ;                                    /* HDCĿ�공�� */

CAL_SCR real32_T KHDC_SpdCon_PIDCalculateKiY_kph[9] =
{
    -5.0F, -4.99F, -1.0F, -0.5F, 0.0F, 0.5F, 1.0F, 4.99F, 5.0F
} ;                                    /* Ŀ�공�ٺ�ʵ�ʳ��ٵ��ٶȲ����I���֣��������趨HDCĿ�공�� */

CAL_SCR real32_T KHDC_SpdCon_PIDCalculateKiZ[63] =
{
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F,
    0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F,
    0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F,
    0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F,
    0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F, 0.01F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F
} ;                                    /* PID Ki�������趨HDCĿ�공�� */

CAL_SCR real32_T KHDC_SpdCon_PIDCalculateKpX_kph[7] =
{
    5.0F, 10.0F, 15.0F, 20.0F, 25.0F, 30.0F, 35.0F
} ;                                    /* HDCĿ�공�� */

CAL_SCR real32_T KHDC_SpdCon_PIDCalculateKpY_kph[9] =
{
    -5.0F, -3.0F, -1.5F, -1.0F, 0.0F, 1.0F, 1.5F, 3.0F, 5.0F
} ;                                    /* Ŀ�공�ٺ�ʵ�ʳ��ٵ��ٶȲ����P�������������趨HDCĿ�공�� */

CAL_SCR real32_T KHDC_SpdCon_PIDCalculateKpZ[63] =
{
    15.0F, 15.0F, 15.0F, 15.0F, 15.0F, 15.0F, 15.0F, 14.0F, 14.0F, 14.0F, 14.0F,
    14.0F, 14.0F, 14.0F, 10.0F, 10.0F, 10.0F, 10.0F, 10.0F, 10.0F, 10.0F, 5.0F,
    5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F,
    5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 10.0F, 10.0F, 10.0F, 10.0F, 10.0F,
    10.0F, 10.0F, 14.0F, 14.0F, 14.0F, 14.0F, 14.0F, 14.0F, 14.0F, 15.0F, 15.0F,
    15.0F, 15.0F, 15.0F, 15.0F, 15.0F
} ;                                    /* PID Kp�������趨HDCĿ�공�� */

CAL_SCR real32_T KHDC_SpdCon_PID_IntegralHoldExit_SpdDelta = 0.4F;/* ��ʵ�ʳ��ٺ�Ŀ��Ѳ�����ٵĲ�ֵ�ȶ���1kph���⣬������ָ��ʱ��5s(TBD)ʱ��PID������������ */
CAL_SCR real32_T KHDC_SpdCon_PID_IntegralHold_SpdDelta = 0.3F;/* ��ʵ�ʳ��ٺ�Ŀ��Ѳ�����ٵĲ�ֵ�ȶ���1kph���ڣ�������ָ��ʱ��5s(TBD)ʱ��PID���������� */
CAL_SCR boolean_T KHDC_SpdCon_Pid_EnableFlag = 1;/* ���»���PID������ʹ�ܿ��� */
CAL_SCR boolean_T KHDC_SpdCon_VehDyn_EnableFlag = 0;/* ���»������ٶȲ��ֻ���Ť��ʹ�ܿ��� */
CAL_SCR uint8_T KHDC_SpdLower_Threshold_KPH = 4U;/* ���»����˳���������ֵ */
CAL_SCR uint8_T KHDC_SpdOverRemind_KPH = 2U;/* ���»����������ѳ���ƫ��ֵ */
CAL_SCR uint32_T KHDC_SpdOverRemind_TrueDelay = 100U;/* ���»����������Ѽ����ж�ʱ�� */
CAL_SCR uint32_T KHDC_SpdOverRemind_ZeroDelay = 500U;/* ���»����������ѻָ��ж�ʱ�� */
CAL_SCR uint8_T KHDC_SpdUpper_Threshold_KPH = 35U;/* ���»����˳���������ֵ */
CAL_SCR uint32_T KHDC_SpdValidJudge_Delaytime_ms = 100U;/* ���»���������Ч���ж��ӳ�ʱ�� */
CAL_SCR uint16_T KHDC_TargeTqJudge_Delaytime_ms = 100U;/* ���»����˳�Ť�������ж�ʱ�� */
CAL_SCR real32_T KHDC_TargetTq_Threshold_Nm = 0.01F;/* ���»����˳�Ŀ��Ť����ֵ */
CAL_SCR real32_T KHDC_TorqFlt_FirstOrderDownRatio = 1.0F;/* ���»���Ť��һ���˲�����ϵ�� */
CAL_SCR real32_T KHDC_TorqFlt_FirstOrderUpRatio = 1.0F;/* ���»���Ť��һ���˲�����ϵ�� */
CAL_SCR real32_T KHDC_TorqFlt_GradLimLowVal = -20.0F;/* ���»���Ť���ݶ������½���󲽳� */
CAL_SCR real32_T KHDC_TorqFlt_GradLimMaxVal = 0.0F;/* ���»���Ť���ݶ��������ֵ */
CAL_SCR real32_T KHDC_TorqFlt_GradLimMinVal = -120.0F;/* ���»���Ť���ݶ�������Сֵ */
CAL_SCR real32_T KHDC_TorqFlt_GradLimUpVal = 20.0F;/* ���»���Ť���ݶ�����������󲽳� */
CAL_SCR uint8_T NONCLTC = 0U;          /* CLTC���ܵ��ٹ�����־λ0 */
CAL_SCR real32_T f4_CT_CRS_BaseTqX_kph[15] =
{
    5.0F, 10.0F, 20.0F, 30.0F, 40.0F, 50.0F, 60.0F, 70.0F, 80.0F, 90.0F, 100.0F,
    110.0F, 120.0F, 130.0F, 140.0F
} ;                                    /* ����Ѳ������Ť��X�ᣨĿ��Ѳ�����٣�KPH�� */

CAL_SCR real32_T f4_CT_CRS_BaseTqY_Nm[15] =
{
    5.4F, 5.5F, 6.0F, 7.0F, 8.0F, 10.0F, 12.0F, 14.0F, 17.0F, 20.0F, 23.0F,
    27.0F, 31.0F, 36.0F, 41.0F
} ;                                    /* ����Ѳ������Ť��Y�ᣨѲ������Ť�أ�Nm�� */

CAL_SCR real32_T f4_CT_HDC_BaseTqX_mpss[16] =
{
    0.5F, 0.6F, 0.7F, 0.8F, 0.9F, 1.0F, 1.1F, 1.2F, 1.3F, 1.4F, 1.5F, 1.6F, 1.7F,
    1.8F, 1.9F, 2.0F
} ;                                    /* ���»�������Ť�ؼ�����ٶȲ��ֵ */

CAL_SCR real32_T f4_CT_HDC_BaseTqY_Nm[16] =
{
    -10.0F, -12.0F, -14.0F, -16.0F, -18.0F, -20.0F, -22.0F, -24.0F, -26.0F,
    -28.0F, -30.0F, -32.0F, -34.0F, -36.0F, -38.0F, -40.0F
} ;                                    /* ���»�������Ť�ز��ֵ */

CAL_SCR real32_T f4_CT_NEDC_KPHMode_X[9] =
{
    0.0F, 1.0F, 2.0F, 3.0F, 4.0F, 5.0F, 6.0F, 7.0F, 8.0F
} ;                                    /* NEDC KPHģʽ */

CAL_SCR real32_T f4_CT_NEDC_KPHVehSpdDiff_Y[4] =
{
    0.0F, 1.0F, 2.0F, 3.0F
} ;                                    /* KPHģʽ���ٺ��ɿ�����̤��ʱ��ʵ�ʳ��ٵĲ�ֵ */

CAL_SCR real32_T f4_CT_NEDC_PidIntegralMax_Tbl[36] =
{
    0.0F, 16.0F, 20.0F, 25.0F, 22.0F, 25.0F, 25.0F, 25.0F, 25.0F, 0.0F, 16.0F,
    20.0F, 25.0F, 22.0F, 25.0F, 25.0F, 25.0F, 25.0F, 0.0F, 16.0F, 20.0F, 25.0F,
    22.0F, 25.0F, 25.0F, 25.0F, 25.0F, 0.0F, 16.0F, 20.0F, 25.0F, 22.0F, 25.0F,
    25.0F, 25.0F, 25.0F
} ;                                    /* PID ���������ֵ(����NEDC KPHģʽ��KPHģʽ����-�ɿ�����̤��ʱ��ʵ�ʳ���) */

CAL_SCR real32_T f4_CT_NEDC_PidIntegralMin_Tbl[36] =
{
    0.0F, -10.0F, -15.0F, -25.0F, -20.0F, -25.0F, -25.0F, -25.0F, -25.0F, 0.0F,
    -10.0F, -15.0F, -25.0F, -20.0F, -25.0F, -25.0F, -25.0F, -25.0F, 0.0F, -10.0F,
    -15.0F, -25.0F, -20.0F, -25.0F, -25.0F, -25.0F, -25.0F, 0.0F, -10.0F, -15.0F,
    -25.0F, -20.0F, -25.0F, -25.0F, -25.0F, -25.0F
} ;                                    /* PID ��������Сֵ(����NEDC KPHģʽ��KPHģʽ����-�ɿ�����̤��ʱ��ʵ�ʳ���) */

CAL_SCR real32_T f4_CT_NEDC_Pid_Ki_Array[9] =
{
    0.0F, 0.8F, 0.8F, 0.8F, 0.8F, 0.8F, 0.8F, 0.8F, 0.8F
} ;                                    /* PID Ki����ֵ */

CAL_SCR real32_T f4_CT_NEDC_Pid_Kp_Array[9] =
{
    0.0F, 15.0F, 15.0F, 15.0F, 15.0F, 15.0F, 15.0F, 15.0F, 15.0F
} ;                                    /* PID Kp����ֵ */

CAL_SCR uint32_T f4_C_CRS_SpdChangeRateExceptionCounterLimit = 20U;/* ���ٲ�ֵ��10ms���������ڵı仯�ʳ���6m/s2�Ĵ��� */
CAL_SCR real32_T f4_C_CRS_SpdChangeRate_mp10ms = 0.06F;/* ���ٲ�ֵ��10ms���������ڵı仯�ʳ���6m/s2 */
CAL_SCR real32_T f4_C_CRS_VehicleMass_KG = 1650.0F;/* ������������ֵ */
CAL_SCR int8_T f4_C_NEDCExit_SpeedHyst = 3;/* KPH35,KPH70�����������������ƫ��ֵ */
CAL_SCR uint8_T f4_C_NEDC_BrakeEn_Spd = 1U;/* NEDC���ٹ�����С����,��С�ڸó��ٺ��˳�����NEDC���ٹ��� */
CAL_SCR real32_T f4_C_NEDC_BrakeTorqueMax_Nm = 0.0F;/* NEDC����������Ť�� */
CAL_SCR real32_T f4_C_NEDC_BrakeTorqueMin_Nm = -100.0F;/* NEDC��С�������Ť�� */
CAL_SCR real32_T f4_C_NEDC_PID_SpdDelta_Max = 3.0F;/* PID�ٶȲ�����ֵ */
CAL_SCR real32_T f4_C_NEDC_PID_SpdDelta_Min = -3.0F;/* PID�ٶȲ�����ֵ */
CAL_SCR real32_T f4_C_NEDC_Pid_PidMax = 50.0F;/* PID ���ֵ */
CAL_SCR real32_T f4_C_NEDC_Pid_PidMin = -50.0F;/* PID ��Сֵ */
CAL_SCR real32_T f4_C_NEDC_TorqFlt_FirstOrderDownRatio = 1.0F;/* Ť��һ���˲�����ϵ�� */
CAL_SCR real32_T f4_C_NEDC_TorqFlt_FirstOrderUpRatio = 1.0F;/* Ť��һ���˲�����ϵ�� */
CAL_SCR real32_T f4_C_NEDC_TorqFlt_GradLimDownVal = -20.0F;/* Ť���ݶ������½���󲽳� */
CAL_SCR real32_T f4_C_NEDC_TorqFlt_GradLimSatMaxVal = 120.0F;/* Ť���ݶ��������ֵ */
CAL_SCR real32_T f4_C_NEDC_TorqFlt_GradLimSatMinVal = -120.0F;/* Ť���ݶ�������Сֵ */
CAL_SCR real32_T f4_C_NEDC_TorqFlt_GradLimUpVal = 20.0F;/* Ť���ݶ�����������󲽳� */
CAL_SCR real32_T f4_C_NEDC_VehDyn_TorqueMax = 60.0F;/* PID Kp����ֵ */
CAL_SCR real32_T f4_C_NEDC_VehDyn_TorqueMin = -60.0F;/* PID Kp����ֵ */
CAL_SCR int32_T f4_C_NEDC_kmph120120Acc_mps = -707;/* KPH120���ٶε�Ŀ����ٶ� */
CAL_SCR int32_T f4_C_NEDC_kmph12050Acc_mps = -1423;/* KPH50���ٶε�Ŀ����ٶ� */
CAL_SCR int32_T f4_C_NEDC_kmph12080Acc_mps = -1065;/* KPH80���ٶε�Ŀ����ٶ� */
CAL_SCR int32_T f4_C_NEDC_kmph15Acc_mps = -850;/* KPH15���ٶε�Ŀ����ٶ� */
CAL_SCR int32_T f4_C_NEDC_kmph32Acc_mps = -829;/* KPH32���ٶε�Ŀ����ٶ� */
CAL_SCR int32_T f4_C_NEDC_kmph35Acc_mps = -993;/* KPH35���ٶε�Ŀ����ٶ� */
CAL_SCR int32_T f4_C_NEDC_kmph50Acc_mps = -532;/* KPH50���ٶε�Ŀ����ٶ� */
CAL_SCR int32_T f4_C_NEDC_kmph70Acc_mps = -707;/* KPH70���ٶε�Ŀ����ٶ� */
CAL_SCR uint8_T u1_C_CLTC_ConstSpd_kph = 100U;/* CLTC���ܵ��ٹ���Ŀ�공�� */
CAL_SCR uint8_T u1_C_CLTC_Constkph_hys = 5U;/* CLTC���ܵ��ٹ���Ŀ�공��ƫ���� */
CAL_SCR uint32_T u1_C_CLTC_DelayTimePlus_hys = 3000U;/* CLTC����Сѭ��ʶ�𳬳�ʱ�� */
CAL_SCR boolean_T u1_C_CLTC_Enable_UseCaliEna = 0;/* CLTC����ǿ�ƿ��ƿ��� */
CAL_SCR boolean_T u1_C_CLTC_Enable_UseCaliVal = 0;/* CLTC����ǿ�ƿ�����ֵ */
CAL_SCR uint32_T u1_C_CLTC_FrontRearSpdDelta_ms = 30000U;/* CLTC����ǰ���ֲ���ȷ�ϳ���ʱ�� */
CAL_SCR uint32_T u1_C_CLTC_Kph2032_ms = 10000U;/* CLTC����Сѭ��ʶ��2032�ٶȶεȴ�ʱ�� */
CAL_SCR uint32_T u1_C_CLTC_Kph3221_ms = 30000U;/* CLTC����Сѭ��ʶ��3221�ٶȶεȴ�ʱ�� */
CAL_SCR uint8_T u1_C_CLTC_SOC30_pct = 30U;/* CLTC���ܵ��ٹ���SOC30 */
CAL_SCR uint8_T u1_C_CLTC_SOC40_pct = 40U;/* CLTC���ܵ��ٹ���SOC40 */
CAL_SCR uint8_T u1_C_CLTC_SOC50_pct = 50U;/* CLTC���ܵ��ٹ���SOC50 */
CAL_SCR uint8_T u1_C_CLTC_SOC60_pct = 60U;/* CLTC���ܵ��ٹ���SOC60 */
CAL_SCR uint8_T u1_C_CLTC_SOC70_pct = 70U;/* CLTC���ܵ��ٹ���SOC70 */
CAL_SCR uint8_T u1_C_CLTC_SOC80_pct = 80U;/* CLTC���ܵ��ٹ���SOC80 */
CAL_SCR uint16_T u1_C_CLTC_SOCHold_ms = 5000U;/* CLTC���ܵ��ٹ���ά��Ŀ�공�ٵ�ʱ����ֵ */
CAL_SCR uint8_T u1_C_CLTC_SOC_hys = 2U;/* CLTC���ܵ��ٹ���SOCƫ���� */
CAL_SCR uint32_T u1_C_CLTC_StoMS_ms = 1000U;/* CLTC����1�����1000���� */
CAL_SCR int16_T u1_C_CLTC_TargetSpd_Threshold = 26;/* CLTC����Ŀ�공����0��ֵ */
CAL_SCR uint32_T u1_C_CLTC_TyreRadius_m = 21194U;/* ���ֹ����뾶 */
CAL_SCR uint16_T u1_C_CLTC_VehSts_TrueDelay_ms = 500U;/* CLTC���ܳ���״̬����ȷ�ϳ���ʱ�� */
CAL_SCR uint16_T u1_C_CLTC_VehSts_ZeroDelay_ms = 500U;/* CLTC���ܳ���״̬����ʧЧ����ʱ�� */
CAL_SCR uint32_T u1_C_CLTC_VelocityRatio = 519674U;/* ���ٱ� */
CAL_SCR uint8_T u1_C_CLTC_cyclekph_hys = 2U;/* CLTC����Сѭ��ʶ����ٶȶ�ƫ���� */
CAL_SCR uint32_T u1_C_CLTC_kph20Hold_ms = 3000U;/* CLTC����Сѭ��ʶ��20�ٶȶ�ά��ʱ�� */
CAL_SCR uint8_T u1_C_CLTC_kph20spd_kph = 20U;/* CLTC����Сѭ��ʶ��20�ٶȶ� */
CAL_SCR uint32_T u1_C_CLTC_kph21Hold_ms = 3000U;/* CLTC����Сѭ��ʶ��21�ٶȶ�ά��ʱ�� */
CAL_SCR uint8_T u1_C_CLTC_kph21spd_kph = 21U;/* CLTC����Сѭ��ʶ��21�ٶȶ� */
CAL_SCR uint32_T u1_C_CLTC_kph32aHold_ms = 3000U;/* CLTC����Сѭ��ʶ��32�ٶȶ�ά��ʱ�� */
CAL_SCR uint8_T u1_C_CLTC_kph32aspd_kph = 32U;/* CLTC����Сѭ��ʶ��32�ٶȶ� */
CAL_SCR boolean_T u1_C_Cruise_UseShortResPressSpd = 1;/* ����RES+��������Ŀ��Ѳ������ʱ�Ƿ���Ŀ��Ѳ������ */
CAL_SCR boolean_T u1_C_Cruise_UseShortSetPressSpd = 1;/* ����SET-��������Ŀ��Ѳ������ʱ�Ƿ���Ŀ��Ѳ������ */
CAL_SCR boolean_T u1_C_Cruise_VehSpdExpectionJudge_flg = 0;/* �Ƿ��ABS���ٵ��쳣�仯���м�� */
CAL_SCR boolean_T u1_C_NEDC_Enable_UseCali = 0;/* ʹ�ñ궨��������NEDC�Զ�ʶ�� */
CAL_SCR boolean_T u1_C_NEDC_PID_SpdDelta_UseMPC = 0;/* ��ǰ�����Ƿ�ʹ��Ԥ�� */
CAL_SCR uint8_T u1_C_NEDC_ReleaseAccelPdl_pct = 3U;/* �ɿ�����̤��Ŀ��� */
CAL_SCR uint8_T u1_C_NEDC_SpeedHyst_kmph = 3U;/* NEDC�����жϵ�������ƫ�� */
CAL_SCR uint8_T u1_C_NEDC_kmph120_kmph = 120U;/* 120kph���ٱ�־ */
CAL_SCR uint8_T u1_C_NEDC_kmph15_kmph = 15U;/* 15kph���ٱ�־ */
CAL_SCR uint8_T u1_C_NEDC_kmph32_kmph = 32U;/* 32kph���ٱ�־ */
CAL_SCR uint8_T u1_C_NEDC_kmph35_kmph = 35U;/* 35kph���ٱ�־ */
CAL_SCR uint8_T u1_C_NEDC_kmph50_kmph = 50U;/* 50kph���ٱ�־ */
CAL_SCR uint8_T u1_C_NEDC_kmph70_kmph = 70U;/* 70kph���ٱ�־ */
CAL_SCR uint8_T u1_C_NEDC_kmph80_kmph = 80U;/* 80kph���ٱ�־ */
CAL_SCR uint8_T u2_C_ClTC_FrontRearSpdDelta_KPH = 90U;/* CLTC����ǰ���ֳ��ٲ���ֵ */
CAL_SCR uint16_T u2_C_NEDC_kmph120HoldTime_s = 3000U;/* �б����NEDC����120kph�ȶ����������120kph��Сά��ʱ�� */
CAL_SCR uint16_T u2_C_NEDC_kmph15HoldTime_s = 3000U;/* �б����NEDC����15kph�ȶ����������15kph��Сά��ʱ�� */
CAL_SCR uint16_T u2_C_NEDC_kmph32HoldTime_s = 3000U;/* �б����NEDC����32kph�ȶ����������32kph��Сά��ʱ�� */
CAL_SCR uint16_T u2_C_NEDC_kmph35HoldTime_s = 3000U;/* �б����NEDC����35kph�ȶ���������35kph��Сά��ʱ�� */
CAL_SCR uint16_T u2_C_NEDC_kmph50HoldTime_s = 3000U;/* �б����NEDC����50kph�ȶ����������50kph��Сά��ʱ�� */
CAL_SCR uint16_T u2_C_NEDC_kmph70HoldTime_s = 3000U;/* �б����NEDC����70kph�ȶ����������70kph��Сά��ʱ�� */
CAL_SCR uint32_T u4_C_NEDC_DelayTimeHysMinus_ms = 2000U;/* ���ȶ�����֮����ɵ�Hysʱ�� */
CAL_SCR uint32_T u4_C_NEDC_DelayTimeHysPlus_ms = 2000U;/* ���ȶ�����֮����ɵ�Hysʱ�� */
CAL_SCR uint32_T u4_C_NEDC_Kph1532_DelayTime_ms = 46000U;/* ��һ��15kph�ȶ������˳��󵽵ڶ����ȶ����ٵ��ж�ʱ�� */
CAL_SCR uint32_T u4_C_NEDC_Kph3250_DelayTime_ms = 82000U;/* �ڶ���32kph�ȶ������˳��󵽵������ȶ����ٵ��ж�ʱ�� */
CAL_SCR uint32_T u4g_KCRS_CruiseAccDec_AddSpd = 41U;/* ����RES+������λ����ʱ���ڳ���Ŀ��Ѳ������
                                                       ���㹫ʽ:dT * a_accdec
                                                       ����,dT=0.01s,a_accdec���趨Ϊ5m/s2 */
CAL_SCR uint32_T u4g_KCRS_CruiseAccDec_DecSpd = 41U;/* ����SET-������λ����ʱ���ڳ���Ŀ��Ѳ������
                                                       ���㹫ʽ:dT * a_accdec
                                                       ����,dT=0.01s,a_accdec���趨Ϊ5m/s2 */
CAL_SCR uint32_T u4g_KCRS_CruiseTipUpDown_AddSpd = 2048U;/* �㰴SET-/RES+�����������Ŀ��Ѳ������ */
CAL_SCR uint32_T u4s_KCRS_CruiseSpdSteady_SpdThreshold = 1024U;/* ��ResumeFromOVerride��ResumeFromCancelģʽ�Զ��л���SPDSTEADYģʽʱʱ�䳵�ٺ�Ŀ�공�ٵĲ�ֵ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

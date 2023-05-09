/*
 * File: SCR_Cal_Data.h
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

#ifndef RTW_HEADER_SCR_Cal_Data_h_
#define RTW_HEADER_SCR_Cal_Data_h_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "SCR_model_types.h"

/* Exported data define */

/* Definition for custom storage class: Define */
#define CAL_GEARD                      4U                        /* ϵͳ��λ��D�� */
#define CAL_GEARR                      1U                        /* ϵͳ��λ��R�� */
#define CAL_GEARRRELEASE               0U                        /* ϵͳ��λ��R�����г� */
#define CRUISE_CANCEL                  2U                        /* Cruiseģʽ��CANCEL */
#define CRUISE_OFF                     0U                        /* Cruiseģʽ��OFF */
#define CRUISE_OVERRIDE                4U                        /* Cruiseģʽ��OVERRIDE */
#define CRUISE_RESUMEFROMCANCEL        6U                        /* Cruiseģʽ��RESUMEFROMCANCEL */
#define CRUISE_RESUMEFROMOVERRIDE      5U                        /* Cruiseģʽ��RESUMEFROMOVERRIDE */
#define CRUISE_SPDSTEADY               3U                        /* Cruiseģʽ��SPDSTEADY */
#define CRUISE_STANDBY                 1U                        /* Cruiseģʽ��STANDBY */
#define GEARD                          4U                        /* D�� */
#define U1S_KEYTYPE_ACCEL              2U                        /* Cruise RES+��������Ŀ��Ѳ������ */
#define U1S_KEYTYPE_DECEL              4U                        /* Cruise SET-��������Ŀ��Ѳ������ */
#define U1S_KEYTYPE_NONE               0U                        /* Cruise����δ���� */
#define U1S_KEYTYPE_TIPDOWN            3U                        /* Cruise SET-�������Ŀ��Ѳ������ */
#define U1S_KEYTYPE_TIPUP              1U                        /* Cruise RES+�������Ŀ��Ѳ������ */
#define U1_C_NEDC_BRAKETYPE_KMPH120120 6U
#define U1_C_NEDC_BRAKETYPE_KMPH12050  8U
#define U1_C_NEDC_BRAKETYPE_KMPH12080  7U
#define U1_C_NEDC_BRAKETYPE_KMPH15     1U
#define U1_C_NEDC_BRAKETYPE_KMPH32     2U
#define U1_C_NEDC_BRAKETYPE_KMPH35     4U
#define U1_C_NEDC_BRAKETYPE_KMPH50     3U
#define U1_C_NEDC_BRAKETYPE_KMPH70     5U

/* Exported data declaration */
#include "derivative.h"

/* Declaration for custom storage class: CAL_11_SCR */
extern CAL_SCR uint8_T CLTC;           /* CLTC���ܵ��ٹ�����־λ7 */
extern CAL_SCR uint8_T CLTC_SOC40;     /* CLTC���ܵ��ٹ�����־λ5 */
extern CAL_SCR uint8_T CLTC_SOC50;     /* CLTC���ܵ��ٹ�����־λ4 */
extern CAL_SCR uint8_T CLTC_SOC60;     /* CLTC���ܵ��ٹ�����־λ3 */
extern CAL_SCR uint8_T CLTC_SOC70;     /* CLTC���ܵ��ٹ�����־λ2 */
extern CAL_SCR uint8_T CLTC_SOC80;     /* CLTC���ܵ��ٹ�����־λ1 */
extern CAL_SCR uint16_T CRS_No_Evflag_TrueDelay;/* ʹ�ܼ��ٶ��㷨 */
extern CAL_SCR uint16_T KCRS_AccelPdlInvalidJudgeTime_ms;/* ����̤����Ч�ж�ʱ�� */
extern CAL_SCR uint16_T KCRS_BrakePdlInvalidJudgeTime_ms;/* �ƶ�̤����Ч�ж�ʱ�� */
extern CAL_SCR boolean_T KCRS_CRUISECtrlErr_Ena;/* ����Ѳ��ϵͳ���Ͽ���ʹ������ */
extern CAL_SCR uint8_T KCRS_CRUISECtrlErr_Val;/* ����Ѳ��ϵͳ���Ͽ���ʹ��Ĭ��ֵ */
extern CAL_SCR uint32_T KCRS_CRUISECtrlErr_holdtime_ms;/* ����Ѳ��Ӳ�����ϵ������ϵ��ӳ�ʱ�� */
extern CAL_SCR boolean_T KCRS_CRUISECtrlSys_Ena;/* ����Ѳ��ϵͳ״̬����ʹ������ */
extern CAL_SCR uint8_T KCRS_CRUISECtrlSys_Val;/* ����Ѳ��ϵͳ���Ͽ���ʹ��Ĭ��ֵ */
extern CAL_SCR boolean_T KCRS_CRUISEModStop_Ena;/* ����Ѳ���������ѿ��� */
extern CAL_SCR boolean_T KCRS_CRUISEModStop_Val;/* ����Ѳ���������ѿ����� */
extern CAL_SCR uint32_T KCRS_CruiseMaxMinSpdJudge_delta;/* Cruise��������ٵĲ���ֵ */
extern CAL_SCR uint32_T KCRS_CruiseMaxSpd;/* Cruise��������� */
extern CAL_SCR uint32_T KCRS_CruiseMinSpd;/* Cruise��С������ */
extern CAL_SCR uint32_T KCRS_CruiseMinSpdNoTouchCheckTime_ms;/* ����Ѳ��ʵ�ʳ���С��Ѳ�������ж�ʱ�� */
extern CAL_SCR uint8_T KCRS_CruiseMinSpdNoTouchJudge_delta;/* ����Ѳ��ʵ�ʳ���С��Ѳ�������жϳ��ٲ���ֵ */
extern CAL_SCR boolean_T KCRS_CruiseModuleWork_Ena;/* ����Ѳ����������ʹ������ */
extern CAL_SCR boolean_T KCRS_CruiseModuleWork_Val;/* ����Ѳ����������ʹ����ֵ */
extern CAL_SCR boolean_T KCRS_CruiseResumeMode_En;/* ����Ѳ��Resume����ʹ�ܿ��� */
extern CAL_SCR boolean_T KCRS_CruiseVehSpdMode_en;/* ����Ѳ�����복��ģʽѡ�񿪹� */
extern CAL_SCR uint16_T KCRS_CruiseVehSpdSatisfyCheckTime_ms;/* ʵ�ʳ�������Ѳ�����ٵĳ����ж�ʱ�� */
extern CAL_SCR uint16_T KCRS_GearInvalidJudgeTime_ms;/* ��λ��Ч�ж�ʱ�� */
extern CAL_SCR uint16_T KCRS_ICMVehpdDisp_Filter;/* ����Ѳ�������Ǳ����˲������˲�ϵ�� */
extern CAL_SCR boolean_T KCRS_ICMVehpdDisp_Filter_en;/* ����Ѳ�������Ǳ����˲����ܿ��� */
extern CAL_SCR uint16_T KCRS_KeyLongPressActiveTime_mS;/* SET/RES���������ж���Сʱ�� */
extern CAL_SCR uint32_T KCRS_KeyResActiveTime_mS;/* ����Ѳ���ָ������ж�ʱ�� */
extern CAL_SCR uint32_T KCRS_KeySetActiveTime_mS;/* ����Ѳ���趨�����ж�ʱ�� */
extern CAL_SCR uint16_T KCRS_KeyShortPressActiveTime_mS;/* �����̰��ж���Сʱ�� */
extern CAL_SCR uint32_T KCRS_LongPressStepTime_mS;/* ����Ѳ���������ٽ�Ծʽ�����ж�ʱ�� */
extern CAL_SCR uint32_T KCRS_MinorCruiseFaultDelayTime_ms;/* ��΢���ϻָ������ж�ʱ�� */
extern CAL_SCR real32_T KCRS_PID_IntegralMax;/* PID�����������ֵ */
extern CAL_SCR real32_T KCRS_PID_IntegralMin;/* �ο������������ն��������Ť��ֵ */
extern CAL_SCR real32_T KCRS_PID_PidMax;/* PID�����ֵ */
extern CAL_SCR real32_T KCRS_PID_PidMin;/* �ο������������ն��������Ť��ֵ */
extern CAL_SCR real32_T KCRS_PID_SpdDelta_Max;/* PID�ٶ�ƫ��ֵ�������ֵ */
extern CAL_SCR real32_T KCRS_PID_SpdDelta_Min;/* PID�ٶ�ƫ��ֵ������Сֵ */
extern CAL_SCR uint16_T KCRS_PressOnOffDebounceThreshold;/* �������º��ɿ��ķ�������ֵʱ�� */
extern CAL_SCR uint8_T KCRS_QuitCruise_PowerLimitPct;/* ��DHP�޹��ʰٷֱ�С�ڸ�ֵʱ���رն���Ѳ�� */
extern CAL_SCR uint32_T KCRS_QuitCruise_TargetVehSpdDiff_HoldTime_ms;/* ��abs(ʵ�ʳ���-Ŀ�공��)���ڸ�ֵ���ҳ���һ��ʱ��ʱ���˳�����Ѳ�� */
extern CAL_SCR uint32_T KCRS_QuitCruise_TargetVehSpdDiff_kph;/* ��abs(ʵ�ʳ���-Ŀ�공��)���ڸ�ֵ���ҳ���һ��ʱ��ʱ���˳�����Ѳ�� */
extern CAL_SCR uint32_T KCRS_QuitCruise_VehSpdLimit;/* �˳�����Ѳ�����ܺ�ϵͳ��С���� */
extern CAL_SCR uint32_T KCRS_RealSpdOffUpLimit_HoldTime_ms;/* ����Ѳ��ʵ�ʳ��ٳ�������ٹ����ж�ʱ�� */
extern CAL_SCR uint8_T KCRS_RealSpdOffUpLimit_delta;/* ����Ѳ��ʵ�ʳ��ٳ�������ٹ��ϳ��ٲ���ֵ */
extern CAL_SCR real32_T KCRS_SpdCon_PIDAccDecKiX_kph[6];/* �����ӳ������ٹ�����Ŀ��Ѳ������ */
extern CAL_SCR real32_T KCRS_SpdCon_PIDAccDecKiY_kph[9];/* �����ӳ������ٹ�����Ŀ��Ѳ�����ٺ�ʵ�ʳ��ٵ��ٶȲ����I�������������趨Ŀ��Ѳ������ */
extern CAL_SCR real32_T KCRS_SpdCon_PIDAccDecKiZ[54];/* �����ӳ������ٹ�����PID Ki�������趨Ŀ��Ѳ������ */
extern CAL_SCR real32_T KCRS_SpdCon_PIDAccDecKpX_kph[6];/* �����ӳ������ٹ�����Ŀ��Ѳ������ */
extern CAL_SCR real32_T KCRS_SpdCon_PIDAccDecKpY_kph[7];/* �����ӳ������ٹ�����Ŀ��Ѳ�����ٺ�ʵ�ʳ��ٵ��ٶȲ����P�������������趨Ŀ��Ѳ������ */
extern CAL_SCR real32_T KCRS_SpdCon_PIDAccDecKpZ[42];/* �����ӳ������ٹ�����PID Kp�������趨Ŀ��Ѳ������ */
extern CAL_SCR real32_T KCRS_SpdCon_PIDSetResumeKiX_kph[6];/* ���趨�ָ�������Ŀ��Ѳ������ */
extern CAL_SCR real32_T KCRS_SpdCon_PIDSetResumeKiY_kph[9];/* ���趨�ָ�������Ŀ��Ѳ�����ٺ�ʵ�ʳ��ٵ��ٶȲ����I���֣��������趨Ŀ��Ѳ������ */
extern CAL_SCR real32_T KCRS_SpdCon_PIDSetResumeKiZ[54];/* ���趨�ָ�������PID Ki�������趨Ŀ��Ѳ������ */
extern CAL_SCR real32_T KCRS_SpdCon_PIDSetResumeKpX_kph[6];/* ���趨�ָ�������Ŀ��Ѳ������ */
extern CAL_SCR real32_T KCRS_SpdCon_PIDSetResumeKpY_kph[9];/* ���趨�ָ�������Ŀ��Ѳ�����ٺ�ʵ�ʳ��ٵ��ٶȲ����P�������������趨Ŀ��Ѳ������ */
extern CAL_SCR real32_T KCRS_SpdCon_PIDSetResumeKpZ[54];/* ���趨�ָ�������PID Kp�������趨Ŀ��Ѳ������ */
extern CAL_SCR real32_T KCRS_SpdCon_PIDTipUpDownKiX_kph[5];/* ����ӵ�����ٹ�����Ŀ��Ѳ������ */
extern CAL_SCR real32_T KCRS_SpdCon_PIDTipUpDownKiY_kph[9];/* ����ӵ�����ٹ�����Ŀ��Ѳ�����ٺ�ʵ�ʳ��ٵ��ٶȲ����I�������������趨Ŀ��Ѳ������ */
extern CAL_SCR real32_T KCRS_SpdCon_PIDTipUpDownKiZ[45];/* ����ӵ�����ٹ�����PID Ki�������趨Ŀ��Ѳ������ */
extern CAL_SCR real32_T KCRS_SpdCon_PIDTipUpDownKpX_kph[6];/* ����ӵ�����ٹ�����Ŀ��Ѳ������ */
extern CAL_SCR real32_T KCRS_SpdCon_PIDTipUpDownKpY_kph[7];/* ����ӵ�����ٹ�����Ŀ��Ѳ�����ٺ�ʵ�ʳ��ٵ��ٶȲ����P�������������趨Ŀ��Ѳ������ */
extern CAL_SCR real32_T KCRS_SpdCon_PIDTipUpDownKpZ[42];/* ����ӵ�����ٹ�����PID Kp�������趨Ŀ��Ѳ������ */
extern CAL_SCR real32_T KCRS_SpdCon_PID_IntegralHoldExit_SpdDelta;/* ��ʵ�ʳ��ٺ�Ŀ��Ѳ�����ٵĲ�ֵ�ȶ���1kph���ڣ�������ָ��ʱ��5s(TBD)ʱ��PID���������� */
extern CAL_SCR uint16_T KCRS_SpdCon_PID_IntegralHoldExit_SpdDelta_Time_ms;/* ��ʵ�ʳ��ٺ�Ŀ��Ѳ�����ٵĲ�ֵ�ȶ���1kph���ڣ�������ָ��ʱ��5s(TBD)ʱ��PID���������� */
extern CAL_SCR real32_T KCRS_SpdCon_PID_IntegralHold_SpdDelta;/* ��ʵ�ʳ��ٺ�Ŀ��Ѳ�����ٵĲ�ֵ�ȶ���1kph���ڣ�������ָ��ʱ��5s(TBD)ʱ��PID���������� */
extern CAL_SCR uint16_T KCRS_SpdCon_PID_IntegralHold_SpdDelta_Time_ms;/* ��ʵ�ʳ��ٺ�Ŀ��Ѳ�����ٵĲ�ֵ�ȶ���1kph���ڣ�������ָ��ʱ��5s(TBD)ʱ��PID���������� */
extern CAL_SCR boolean_T KCRS_SpdCon_Pid_EnableFlag;/* ʹ��PID */
extern CAL_SCR boolean_T KCRS_SpdCon_VehDyn_EnableFlag;/* ʹ�ܳ���������ѧģ�� */
extern CAL_SCR uint16_T KCRS_TargetVehSpdDiff_DelayTime_ms;/* ����Ѳ���������޵��³����쳣�˳�Ѳ��״̬��������ʱ�� */
extern CAL_SCR real32_T KCRS_TorqFlt_FirstOrderDownRatio;/* ����Ѳ��Ť��һ���˲�����(�½���) */
extern CAL_SCR real32_T KCRS_TorqFlt_FirstOrderUpRatio;/* ����Ѳ��Ť��һ���˲�����(������) */
extern CAL_SCR real32_T KCRS_TorqFlt_GradLimLowVal;/* ���ٶȵ����jerkͨ����ֵ������
                                                      ��ֵ�ļ��㷽�����£��������ٶ�jerkΪ-1.5m/s3������ʱ��Ϊ0.02s��ʹ��������ѧ��ʽ�еļ������������㣺
                                                      1575*-1.5*0.02*1.05*0.3234/7.93/0.973=-3.46 */
extern CAL_SCR real32_T KCRS_TorqFlt_GradLimMaxVal;/* �ݶ����ƺ��������������Ť��
                                                      ��ֵ�ļ��㷽�����£��������ٶ�Ϊ1.75m/sʹ��������ѧ��ʽ�еļ������������㣺
                                                      1575*1.75*1.05*0.3234/7.93/0.973=121 */
extern CAL_SCR real32_T KCRS_TorqFlt_GradLimMinVal;/* �ο������������ն��������Ť��ֵ */
extern CAL_SCR real32_T KCRS_TorqFlt_GradLimUpVal;/* ���ٶȵ����jerkͨ����ֵ������
                                                     ��ֵ�ļ��㷽�����£��������ٶ�jerkΪ1.5m/s3������ʱ��Ϊ0.02s��ʹ��������ѧ��ʽ�еļ������������㣺
                                                     1575*1.5*0.02*1.05*0.3234/7.93/0.973=3.46 */
extern CAL_SCR real32_T KCRS_VehDyn_TorqueMax;/* ����������ѧ��������������Ť�� */
extern CAL_SCR real32_T KCRS_VehDyn_TorqueMin;/* ����������ѧ����С���������Ť�� */
extern CAL_SCR uint32_T KCRS_VehSpdCheckDelayTime_period;/* ����ABS���ٱ仯�쳣���м������ */
extern CAL_SCR uint16_T KCRS_VehSpdInvalidJudgeTime_ms;/* ������Ч�ж�ʱ�� */
extern CAL_SCR uint8_T KCRS_t_CRUISECtrlSysDelayTime_ms;/* ����Ѳ��Runģʽ�˳�ȷ��ʱ�� */
extern CAL_SCR uint16_T KCRS_t_CancelPress_ms;/* ����Ѳ��Cancel�����жϣ�N�����г̲���ͣ��ʱ�� */
extern CAL_SCR uint32_T KCRS_t_CruiseRun_ms;/* ����Ѳ�����������趨�����ж�ʱ�� */
extern CAL_SCR uint32_T KHDC_ABSSpeedSatisfy_Delaytime_ms;/* ���»���ʹ��������������ȷ��ʱ�� */
extern CAL_SCR uint32_T KHDC_AccSpdThreshold_Delaytime1_ms;/* ���»���ʹ�ܼ��ٶ���������ж�ʱ��1 */
extern CAL_SCR uint32_T KHDC_AccSpdThreshold_Delaytime2_ms;/* ���»���ʹ�ܼ��ٶ���������ж�ʱ��2 */
extern CAL_SCR uint32_T KHDC_AccSpdThreshold_Delaytime3_ms;/* ���»���ʹ�ܼ��ٶ���������ж�ʱ��3 */
extern CAL_SCR uint8_T KHDC_AccSpd_Filter;/* ���»������ٶ�һ���˲����� */
extern CAL_SCR int32_T KHDC_AccSpd_Threshold1_mpss;/* ���»���ʹ�ܼ��ٶ���ֵ1 */
extern CAL_SCR int32_T KHDC_AccSpd_Threshold2_mpss;/* ���»���ʹ�ܼ��ٶ���ֵ2 */
extern CAL_SCR int32_T KHDC_AccSpd_Threshold3_mpss;/* ���»���ʹ�ܼ��ٶ���ֵ3 */
extern CAL_SCR uint32_T KHDC_AcceMode_Delaytime_ms;/* ���»���ʹ����������Ť���ж�ʱ�� */
extern CAL_SCR boolean_T KHDC_C_HDC_En;/* ���»�������ʹ�� */
extern CAL_SCR real32_T KHDC_CreepGearDSpd_Threshold_KPH;/* ���»����˳���������D�����Ƴ�����ֵ */
extern CAL_SCR real32_T KHDC_CreepGearRSpd_Threshold_KPH;/* ���»����˳���������R�����Ƴ�����ֵ */
extern CAL_SCR uint8_T KHDC_DHPLimitSpd_Threshold_Nm;/* ���»���ʹ�����ģ�����Ƴ�����С��ֵ */
extern CAL_SCR uint8_T KHDC_GearDSpdLower_KPH;/* ���»���ʹ������D���������� */
extern CAL_SCR uint8_T KHDC_GearDSpdUpper_KPH;/* ���»���ʹ������D���������� */
extern CAL_SCR real32_T KHDC_GearD_AcceMode_Threshold_Nm;/* ���»���ʹ������D������Ť���ж���ֵ */
extern CAL_SCR int16_T KHDC_GearD_VehTq_Threshold_Nm;/* ���»������ƶ��˳�ʱD��Ť������ */
extern CAL_SCR uint8_T KHDC_GearRSpdLower_KPH;/* ���»���ʹ������R���������� */
extern CAL_SCR uint8_T KHDC_GearRSpdUpper_KPH;/* ���»���ʹ������R���������� */
extern CAL_SCR real32_T KHDC_GearR_AcceMode_Threshold_Nm;/* ���»���ʹ������R������Ť���ж���ֵ */
extern CAL_SCR int16_T KHDC_GearR_VehTq_Threshold_Nm;/* ���»������ƶ��˳�ʱR��Ť������ */
extern CAL_SCR boolean_T KHDC_HDCrun_Ena;/* ���»���ʹ�ܿ��� */
extern CAL_SCR boolean_T KHDC_HDCrun_Val;/* ���»���ʹ����ֵ */
extern CAL_SCR real32_T KHDC_Kalman_P; /* ���»������ٶȿ������˲�P���� */
extern CAL_SCR real32_T KHDC_Kalman_Q; /* ���»������ٶȿ������˲�Q���� */
extern CAL_SCR real32_T KHDC_Kalman_R; /* ���»������ٶȿ������˲�R���� */
extern CAL_SCR int16_T KHDC_MCUMinRegenAvlTq_Nm;/* ���»���ʹ������MCU����������СŤ����ֵ */
extern CAL_SCR real32_T KHDC_PID_IntegralMax;/* ���»���PID������ֲ������ֵ */
extern CAL_SCR real32_T KHDC_PID_IntegralMin;/* ���»���PID������ֲ�����Сֵ */
extern CAL_SCR real32_T KHDC_PID_PidMax;/* ���»���PID�����������ܺ����ֵ */
extern CAL_SCR real32_T KHDC_PID_PidMin;/* ���»���PID�����������ܺ���Сֵ */
extern CAL_SCR uint8_T KHDC_PID_SpdDelta_Max;/* ���»���PID��������ٶȲ� */
extern CAL_SCR int8_T KHDC_PID_SpdDelta_Min;/* ���»���PID������С�ٶȲ� */
extern CAL_SCR real32_T KHDC_SpdCon_PIDCalculateKiX_kph[7];/* HDCĿ�공�� */
extern CAL_SCR real32_T KHDC_SpdCon_PIDCalculateKiY_kph[9];/* Ŀ�공�ٺ�ʵ�ʳ��ٵ��ٶȲ����I���֣��������趨HDCĿ�공�� */
extern CAL_SCR real32_T KHDC_SpdCon_PIDCalculateKiZ[63];/* PID Ki�������趨HDCĿ�공�� */
extern CAL_SCR real32_T KHDC_SpdCon_PIDCalculateKpX_kph[7];/* HDCĿ�공�� */
extern CAL_SCR real32_T KHDC_SpdCon_PIDCalculateKpY_kph[9];/* Ŀ�공�ٺ�ʵ�ʳ��ٵ��ٶȲ����P�������������趨HDCĿ�공�� */
extern CAL_SCR real32_T KHDC_SpdCon_PIDCalculateKpZ[63];/* PID Kp�������趨HDCĿ�공�� */
extern CAL_SCR real32_T KHDC_SpdCon_PID_IntegralHoldExit_SpdDelta;/* ��ʵ�ʳ��ٺ�Ŀ��Ѳ�����ٵĲ�ֵ�ȶ���1kph���⣬������ָ��ʱ��5s(TBD)ʱ��PID������������ */
extern CAL_SCR real32_T KHDC_SpdCon_PID_IntegralHold_SpdDelta;/* ��ʵ�ʳ��ٺ�Ŀ��Ѳ�����ٵĲ�ֵ�ȶ���1kph���ڣ�������ָ��ʱ��5s(TBD)ʱ��PID���������� */
extern CAL_SCR boolean_T KHDC_SpdCon_Pid_EnableFlag;/* ���»���PID������ʹ�ܿ��� */
extern CAL_SCR boolean_T KHDC_SpdCon_VehDyn_EnableFlag;/* ���»������ٶȲ��ֻ���Ť��ʹ�ܿ��� */
extern CAL_SCR uint8_T KHDC_SpdLower_Threshold_KPH;/* ���»����˳���������ֵ */
extern CAL_SCR uint8_T KHDC_SpdOverRemind_KPH;/* ���»����������ѳ���ƫ��ֵ */
extern CAL_SCR uint32_T KHDC_SpdOverRemind_TrueDelay;/* ���»����������Ѽ����ж�ʱ�� */
extern CAL_SCR uint32_T KHDC_SpdOverRemind_ZeroDelay;/* ���»����������ѻָ��ж�ʱ�� */
extern CAL_SCR uint8_T KHDC_SpdUpper_Threshold_KPH;/* ���»����˳���������ֵ */
extern CAL_SCR uint32_T KHDC_SpdValidJudge_Delaytime_ms;/* ���»���������Ч���ж��ӳ�ʱ�� */
extern CAL_SCR uint16_T KHDC_TargeTqJudge_Delaytime_ms;/* ���»����˳�Ť�������ж�ʱ�� */
extern CAL_SCR real32_T KHDC_TargetTq_Threshold_Nm;/* ���»����˳�Ŀ��Ť����ֵ */
extern CAL_SCR real32_T KHDC_TorqFlt_FirstOrderDownRatio;/* ���»���Ť��һ���˲�����ϵ�� */
extern CAL_SCR real32_T KHDC_TorqFlt_FirstOrderUpRatio;/* ���»���Ť��һ���˲�����ϵ�� */
extern CAL_SCR real32_T KHDC_TorqFlt_GradLimLowVal;/* ���»���Ť���ݶ������½���󲽳� */
extern CAL_SCR real32_T KHDC_TorqFlt_GradLimMaxVal;/* ���»���Ť���ݶ��������ֵ */
extern CAL_SCR real32_T KHDC_TorqFlt_GradLimMinVal;/* ���»���Ť���ݶ�������Сֵ */
extern CAL_SCR real32_T KHDC_TorqFlt_GradLimUpVal;/* ���»���Ť���ݶ�����������󲽳� */
extern CAL_SCR uint8_T NONCLTC;        /* CLTC���ܵ��ٹ�����־λ0 */
extern CAL_SCR real32_T f4_CT_CRS_BaseTqX_kph[15];/* ����Ѳ������Ť��X�ᣨĿ��Ѳ�����٣�KPH�� */
extern CAL_SCR real32_T f4_CT_CRS_BaseTqY_Nm[15];/* ����Ѳ������Ť��Y�ᣨѲ������Ť�أ�Nm�� */
extern CAL_SCR real32_T f4_CT_HDC_BaseTqX_mpss[16];/* ���»�������Ť�ؼ�����ٶȲ��ֵ */
extern CAL_SCR real32_T f4_CT_HDC_BaseTqY_Nm[16];/* ���»�������Ť�ز��ֵ */
extern CAL_SCR real32_T f4_CT_NEDC_KPHMode_X[9];/* NEDC KPHģʽ */
extern CAL_SCR real32_T f4_CT_NEDC_KPHVehSpdDiff_Y[4];/* KPHģʽ���ٺ��ɿ�����̤��ʱ��ʵ�ʳ��ٵĲ�ֵ */
extern CAL_SCR real32_T f4_CT_NEDC_PidIntegralMax_Tbl[36];/* PID ���������ֵ(����NEDC KPHģʽ��KPHģʽ����-�ɿ�����̤��ʱ��ʵ�ʳ���) */
extern CAL_SCR real32_T f4_CT_NEDC_PidIntegralMin_Tbl[36];/* PID ��������Сֵ(����NEDC KPHģʽ��KPHģʽ����-�ɿ�����̤��ʱ��ʵ�ʳ���) */
extern CAL_SCR real32_T f4_CT_NEDC_Pid_Ki_Array[9];/* PID Ki����ֵ */
extern CAL_SCR real32_T f4_CT_NEDC_Pid_Kp_Array[9];/* PID Kp����ֵ */
extern CAL_SCR uint32_T f4_C_CRS_SpdChangeRateExceptionCounterLimit;/* ���ٲ�ֵ��10ms���������ڵı仯�ʳ���6m/s2�Ĵ��� */
extern CAL_SCR real32_T f4_C_CRS_SpdChangeRate_mp10ms;/* ���ٲ�ֵ��10ms���������ڵı仯�ʳ���6m/s2 */
extern CAL_SCR real32_T f4_C_CRS_VehicleMass_KG;/* ������������ֵ */
extern CAL_SCR int8_T f4_C_NEDCExit_SpeedHyst;/* KPH35,KPH70�����������������ƫ��ֵ */
extern CAL_SCR uint8_T f4_C_NEDC_BrakeEn_Spd;/* NEDC���ٹ�����С����,��С�ڸó��ٺ��˳�����NEDC���ٹ��� */
extern CAL_SCR real32_T f4_C_NEDC_BrakeTorqueMax_Nm;/* NEDC����������Ť�� */
extern CAL_SCR real32_T f4_C_NEDC_BrakeTorqueMin_Nm;/* NEDC��С�������Ť�� */
extern CAL_SCR real32_T f4_C_NEDC_PID_SpdDelta_Max;/* PID�ٶȲ�����ֵ */
extern CAL_SCR real32_T f4_C_NEDC_PID_SpdDelta_Min;/* PID�ٶȲ�����ֵ */
extern CAL_SCR real32_T f4_C_NEDC_Pid_PidMax;/* PID ���ֵ */
extern CAL_SCR real32_T f4_C_NEDC_Pid_PidMin;/* PID ��Сֵ */
extern CAL_SCR real32_T f4_C_NEDC_TorqFlt_FirstOrderDownRatio;/* Ť��һ���˲�����ϵ�� */
extern CAL_SCR real32_T f4_C_NEDC_TorqFlt_FirstOrderUpRatio;/* Ť��һ���˲�����ϵ�� */
extern CAL_SCR real32_T f4_C_NEDC_TorqFlt_GradLimDownVal;/* Ť���ݶ������½���󲽳� */
extern CAL_SCR real32_T f4_C_NEDC_TorqFlt_GradLimSatMaxVal;/* Ť���ݶ��������ֵ */
extern CAL_SCR real32_T f4_C_NEDC_TorqFlt_GradLimSatMinVal;/* Ť���ݶ�������Сֵ */
extern CAL_SCR real32_T f4_C_NEDC_TorqFlt_GradLimUpVal;/* Ť���ݶ�����������󲽳� */
extern CAL_SCR real32_T f4_C_NEDC_VehDyn_TorqueMax;/* PID Kp����ֵ */
extern CAL_SCR real32_T f4_C_NEDC_VehDyn_TorqueMin;/* PID Kp����ֵ */
extern CAL_SCR int32_T f4_C_NEDC_kmph120120Acc_mps;/* KPH120���ٶε�Ŀ����ٶ� */
extern CAL_SCR int32_T f4_C_NEDC_kmph12050Acc_mps;/* KPH50���ٶε�Ŀ����ٶ� */
extern CAL_SCR int32_T f4_C_NEDC_kmph12080Acc_mps;/* KPH80���ٶε�Ŀ����ٶ� */
extern CAL_SCR int32_T f4_C_NEDC_kmph15Acc_mps;/* KPH15���ٶε�Ŀ����ٶ� */
extern CAL_SCR int32_T f4_C_NEDC_kmph32Acc_mps;/* KPH32���ٶε�Ŀ����ٶ� */
extern CAL_SCR int32_T f4_C_NEDC_kmph35Acc_mps;/* KPH35���ٶε�Ŀ����ٶ� */
extern CAL_SCR int32_T f4_C_NEDC_kmph50Acc_mps;/* KPH50���ٶε�Ŀ����ٶ� */
extern CAL_SCR int32_T f4_C_NEDC_kmph70Acc_mps;/* KPH70���ٶε�Ŀ����ٶ� */
extern CAL_SCR uint8_T u1_C_CLTC_ConstSpd_kph;/* CLTC���ܵ��ٹ���Ŀ�공�� */
extern CAL_SCR uint8_T u1_C_CLTC_Constkph_hys;/* CLTC���ܵ��ٹ���Ŀ�공��ƫ���� */
extern CAL_SCR uint32_T u1_C_CLTC_DelayTimePlus_hys;/* CLTC����Сѭ��ʶ�𳬳�ʱ�� */
extern CAL_SCR boolean_T u1_C_CLTC_Enable_UseCaliEna;/* CLTC����ǿ�ƿ��ƿ��� */
extern CAL_SCR boolean_T u1_C_CLTC_Enable_UseCaliVal;/* CLTC����ǿ�ƿ�����ֵ */
extern CAL_SCR uint32_T u1_C_CLTC_FrontRearSpdDelta_ms;/* CLTC����ǰ���ֲ���ȷ�ϳ���ʱ�� */
extern CAL_SCR uint32_T u1_C_CLTC_Kph2032_ms;/* CLTC����Сѭ��ʶ��2032�ٶȶεȴ�ʱ�� */
extern CAL_SCR uint32_T u1_C_CLTC_Kph3221_ms;/* CLTC����Сѭ��ʶ��3221�ٶȶεȴ�ʱ�� */
extern CAL_SCR uint8_T u1_C_CLTC_SOC30_pct;/* CLTC���ܵ��ٹ���SOC30 */
extern CAL_SCR uint8_T u1_C_CLTC_SOC40_pct;/* CLTC���ܵ��ٹ���SOC40 */
extern CAL_SCR uint8_T u1_C_CLTC_SOC50_pct;/* CLTC���ܵ��ٹ���SOC50 */
extern CAL_SCR uint8_T u1_C_CLTC_SOC60_pct;/* CLTC���ܵ��ٹ���SOC60 */
extern CAL_SCR uint8_T u1_C_CLTC_SOC70_pct;/* CLTC���ܵ��ٹ���SOC70 */
extern CAL_SCR uint8_T u1_C_CLTC_SOC80_pct;/* CLTC���ܵ��ٹ���SOC80 */
extern CAL_SCR uint16_T u1_C_CLTC_SOCHold_ms;/* CLTC���ܵ��ٹ���ά��Ŀ�공�ٵ�ʱ����ֵ */
extern CAL_SCR uint8_T u1_C_CLTC_SOC_hys;/* CLTC���ܵ��ٹ���SOCƫ���� */
extern CAL_SCR uint32_T u1_C_CLTC_StoMS_ms;/* CLTC����1�����1000���� */
extern CAL_SCR int16_T u1_C_CLTC_TargetSpd_Threshold;/* CLTC����Ŀ�공����0��ֵ */
extern CAL_SCR uint32_T u1_C_CLTC_TyreRadius_m;/* ���ֹ����뾶 */
extern CAL_SCR uint16_T u1_C_CLTC_VehSts_TrueDelay_ms;/* CLTC���ܳ���״̬����ȷ�ϳ���ʱ�� */
extern CAL_SCR uint16_T u1_C_CLTC_VehSts_ZeroDelay_ms;/* CLTC���ܳ���״̬����ʧЧ����ʱ�� */
extern CAL_SCR uint32_T u1_C_CLTC_VelocityRatio;/* ���ٱ� */
extern CAL_SCR uint8_T u1_C_CLTC_cyclekph_hys;/* CLTC����Сѭ��ʶ����ٶȶ�ƫ���� */
extern CAL_SCR uint32_T u1_C_CLTC_kph20Hold_ms;/* CLTC����Сѭ��ʶ��20�ٶȶ�ά��ʱ�� */
extern CAL_SCR uint8_T u1_C_CLTC_kph20spd_kph;/* CLTC����Сѭ��ʶ��20�ٶȶ� */
extern CAL_SCR uint32_T u1_C_CLTC_kph21Hold_ms;/* CLTC����Сѭ��ʶ��21�ٶȶ�ά��ʱ�� */
extern CAL_SCR uint8_T u1_C_CLTC_kph21spd_kph;/* CLTC����Сѭ��ʶ��21�ٶȶ� */
extern CAL_SCR uint32_T u1_C_CLTC_kph32aHold_ms;/* CLTC����Сѭ��ʶ��32�ٶȶ�ά��ʱ�� */
extern CAL_SCR uint8_T u1_C_CLTC_kph32aspd_kph;/* CLTC����Сѭ��ʶ��32�ٶȶ� */
extern CAL_SCR boolean_T u1_C_Cruise_UseShortResPressSpd;/* ����RES+��������Ŀ��Ѳ������ʱ�Ƿ���Ŀ��Ѳ������ */
extern CAL_SCR boolean_T u1_C_Cruise_UseShortSetPressSpd;/* ����SET-��������Ŀ��Ѳ������ʱ�Ƿ���Ŀ��Ѳ������ */
extern CAL_SCR boolean_T u1_C_Cruise_VehSpdExpectionJudge_flg;/* �Ƿ��ABS���ٵ��쳣�仯���м�� */
extern CAL_SCR boolean_T u1_C_NEDC_Enable_UseCali;/* ʹ�ñ궨��������NEDC�Զ�ʶ�� */
extern CAL_SCR boolean_T u1_C_NEDC_PID_SpdDelta_UseMPC;/* ��ǰ�����Ƿ�ʹ��Ԥ�� */
extern CAL_SCR uint8_T u1_C_NEDC_ReleaseAccelPdl_pct;/* �ɿ�����̤��Ŀ��� */
extern CAL_SCR uint8_T u1_C_NEDC_SpeedHyst_kmph;/* NEDC�����жϵ�������ƫ�� */
extern CAL_SCR uint8_T u1_C_NEDC_kmph120_kmph;/* 120kph���ٱ�־ */
extern CAL_SCR uint8_T u1_C_NEDC_kmph15_kmph;/* 15kph���ٱ�־ */
extern CAL_SCR uint8_T u1_C_NEDC_kmph32_kmph;/* 32kph���ٱ�־ */
extern CAL_SCR uint8_T u1_C_NEDC_kmph35_kmph;/* 35kph���ٱ�־ */
extern CAL_SCR uint8_T u1_C_NEDC_kmph50_kmph;/* 50kph���ٱ�־ */
extern CAL_SCR uint8_T u1_C_NEDC_kmph70_kmph;/* 70kph���ٱ�־ */
extern CAL_SCR uint8_T u1_C_NEDC_kmph80_kmph;/* 80kph���ٱ�־ */
extern CAL_SCR uint8_T u2_C_ClTC_FrontRearSpdDelta_KPH;/* CLTC����ǰ���ֳ��ٲ���ֵ */
extern CAL_SCR uint16_T u2_C_NEDC_kmph120HoldTime_s;/* �б����NEDC����120kph�ȶ����������120kph��Сά��ʱ�� */
extern CAL_SCR uint16_T u2_C_NEDC_kmph15HoldTime_s;/* �б����NEDC����15kph�ȶ����������15kph��Сά��ʱ�� */
extern CAL_SCR uint16_T u2_C_NEDC_kmph32HoldTime_s;/* �б����NEDC����32kph�ȶ����������32kph��Сά��ʱ�� */
extern CAL_SCR uint16_T u2_C_NEDC_kmph35HoldTime_s;/* �б����NEDC����35kph�ȶ���������35kph��Сά��ʱ�� */
extern CAL_SCR uint16_T u2_C_NEDC_kmph50HoldTime_s;/* �б����NEDC����50kph�ȶ����������50kph��Сά��ʱ�� */
extern CAL_SCR uint16_T u2_C_NEDC_kmph70HoldTime_s;/* �б����NEDC����70kph�ȶ����������70kph��Сά��ʱ�� */
extern CAL_SCR uint32_T u4_C_NEDC_DelayTimeHysMinus_ms;/* ���ȶ�����֮����ɵ�Hysʱ�� */
extern CAL_SCR uint32_T u4_C_NEDC_DelayTimeHysPlus_ms;/* ���ȶ�����֮����ɵ�Hysʱ�� */
extern CAL_SCR uint32_T u4_C_NEDC_Kph1532_DelayTime_ms;/* ��һ��15kph�ȶ������˳��󵽵ڶ����ȶ����ٵ��ж�ʱ�� */
extern CAL_SCR uint32_T u4_C_NEDC_Kph3250_DelayTime_ms;/* �ڶ���32kph�ȶ������˳��󵽵������ȶ����ٵ��ж�ʱ�� */
extern CAL_SCR uint32_T u4g_KCRS_CruiseAccDec_AddSpd;/* ����RES+������λ����ʱ���ڳ���Ŀ��Ѳ������
                                                        ���㹫ʽ:dT * a_accdec
                                                        ����,dT=0.01s,a_accdec���趨Ϊ5m/s2 */
extern CAL_SCR uint32_T u4g_KCRS_CruiseAccDec_DecSpd;/* ����SET-������λ����ʱ���ڳ���Ŀ��Ѳ������
                                                        ���㹫ʽ:dT * a_accdec
                                                        ����,dT=0.01s,a_accdec���趨Ϊ5m/s2 */
extern CAL_SCR uint32_T u4g_KCRS_CruiseTipUpDown_AddSpd;/* �㰴SET-/RES+�����������Ŀ��Ѳ������ */
extern CAL_SCR uint32_T u4s_KCRS_CruiseSpdSteady_SpdThreshold;/* ��ResumeFromOVerride��ResumeFromCancelģʽ�Զ��л���SPDSTEADYģʽʱʱ�䳵�ٺ�Ŀ�공�ٵĲ�ֵ */

#endif                                 /* RTW_HEADER_SCR_Cal_Data_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

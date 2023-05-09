/*
 * File: TQM_Cal_Data.h
 *
 * Code generated for Simulink model 'TQM_model'.
 *
 * Model version                  : 1.3587
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Fri Mar 18 15:45:56 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Freescale->32-bit PowerPC
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. MISRA C:2012 guidelines
 * Validation result: Not run
 */

#ifndef RTW_HEADER_TQM_Cal_Data_h_
#define RTW_HEADER_TQM_Cal_Data_h_
#include "rtwtypes.h"
#include "TQM_model_types.h"

/* Exported data declaration */
#include "derivative.h"

/* Declaration for custom storage class: CAL_9_TQM */
extern CAL_TQM real32_T ABS_FR_DeltaCurveHalfAxle;/* ���������ٲ� */
extern CAL_TQM boolean_T ABS_WheelSpd_Enable;/* �Ƿ�ͨ��ABS�������㳵�� */
extern CAL_TQM real32_T ABS_vWhlRL_Revise;/* ͨ��ǰһ�ֵĳ������ƲⱾ�ֳ���ʱ�������� */
extern CAL_TQM uint16_T ASM_EPB_AntiSlide_Timer;/* MCU���л�EPB���¶��ж��ӳ�counter */
extern CAL_TQM int16_T ASM_EPB_Applied_DelayTime;/* �ж�EPB��פ��ʱcounter��������ֹͣ��פ���� */
extern CAL_TQM boolean_T ASM_EPB_BrakeSta_En;/* EPB�����½����������ƶ�����ʹ�ܱ�ʶ */
extern CAL_TQM uint16_T ASM_En_AntiSlide_Spd_Delay;/* EPB���ﳵ����Ч���ж�ʱ�� */
extern CAL_TQM int8_T ASM_GearD_Over_Tq;/* D��������Ť�ش��ڷ�����Ť�س�����ֵ����Ϊ����Ť��ȷʵ���ڷ�����Ť�� */
extern CAL_TQM uint16_T ASM_GearD_Tq_Upper_Delay;/* ����Ť�ش��ڷ���Ť�صĳ���ʱ����ڸ�ֵ���˳����﹦�ܣ�D���� */
extern CAL_TQM int8_T ASM_GearR_Over_Tq;/* R��������Ť�أ�����ֵ�����ڷ�����Ť�أ�����ֵ��������ֵ����Ϊ����Ť�ش��ڷ�����Ť�� */
extern CAL_TQM uint16_T ASM_GearR_Tq_Upper_Delay;/* ����Ť�ش��ڷ���Ť�صĳ���ʱ����ڸ�ֵ���˳����﹦�ܣ�R���� */
extern CAL_TQM int16_T ASM_MCUAntiSlide_AvTq_Max;/* ����MCU�������������Ť�� */
extern CAL_TQM int16_T ASM_MCUAntiSlide_AvTq_Min;/* ����MCU�������С������Ť�� */
extern CAL_TQM boolean_T ASM_MCUAntiSlide_Ena;/* ת�ٻ�������ʹ�ܿ��� */
extern CAL_TQM boolean_T ASM_MCUAntiSlide_Val;/* ת�ٻ�������ʹ��ֵ */
extern CAL_TQM int16_T ASM_MCU_GearDAntiSlide_Spd_En;/* D��MCU�������ھ�ֹ�ж�ת�� */
extern CAL_TQM int8_T ASM_MCU_GearD_Lower_RoadAngle;/* D�������½����¶�����������ֵ */
extern CAL_TQM int16_T ASM_MCU_GearRAntiSlide_Spd_En;/* R��MCU�������ھ�ֹ�ж�ת�� */
extern CAL_TQM int8_T ASM_MCU_GearR_Upper_RoadAngle;/* R�������½����¶�����������ֵ */
extern CAL_TQM uint16_T ASM_MCU_QuitApplied_DelayTime;/* EPB������MCUʹ�ܵȴ�����counter */
extern CAL_TQM uint16_T ASM_S11_AntiSlideEnter_DrivePower;/* ���÷ŵ繦�ʴ��ڸ�ֵ�����������¹��� */
extern CAL_TQM int32_T ASM_S11_AntiSlideEnter_RoadAngle;/* ���ת��С�ڸ�ֵ��Ϊ�������ھ�ֹ״̬�������¶��жϣ� */
extern CAL_TQM uint16_T ASM_S11_AntiSlideQuit_DrivePower;/* S11�����¹���ģʽ�ж��¶�ֵ */
extern CAL_TQM uint32_T ASM_S11_AntiSlide_ConfirmTime;/* δ���ƶ�ʱ�������³���ʱ����ڸ�ֵ���˳������¹��� */
extern CAL_TQM int16_T ASM_S11_AntiSlide_ForwardSpd_Uena;/* ���ת�ٴ��ڸ�ֵ��Ϊ�������ڿ�����ʻ״̬����ʱҪ���˳������� */
extern CAL_TQM int16_T ASM_S11_AntiSlide_ReverseSpd_Uena;/* ���ת��С�ڸ�ֵ��Ϊ�������ڿ��ٺ���״̬����ʱҪ���˳������� */
extern CAL_TQM int16_T ASM_S11_AntiSlide_Spd_Static;/* ���ת��С�ڸ�ֵ��Ϊ�������ھ�ֹ״̬��D���� */
extern CAL_TQM boolean_T ASM_S11_AveMotSpdFilter_En;/* �����³����ж�ģ�鳵���˲�ʹ�ܱ�־ */
extern CAL_TQM uint16_T ASM_S11_EPBConfirm_TrueDelay;/* MCU�������ڼ�EPB��פ��ʱ�ж�ʱ�� */
extern CAL_TQM int16_T ASM_S11_EPB_AntiSlide_ForwardSpd;/* EPB�������������ǰ�����ٷ�ֵ */
extern CAL_TQM int16_T ASM_S11_EPB_AntiSlide_ReverseSpd;/* EPB����������������˳��ٷ�ֵ */
extern CAL_TQM uint16_T ASM_S11_GearD_Delay;/* ͣ����D���ĳ���ʱ����ڸ�ֵ�������������¹��ܣ�D���� */
extern CAL_TQM uint16_T ASM_S11_GearD_Spd_Slide_Delay;/* �������뻺������״̬�ĳ���ʱ����ڸ�ֵ����Ϊ����ȷʵ���ڻ�������״̬��D���� */
extern CAL_TQM int16_T ASM_S11_GearD_Spd_Slide_Hig;/* ���ת��С�ڸ�ֵ��Ϊ�������ڻ�������״̬��D���� */
extern CAL_TQM int16_T ASM_S11_GearD_Spd_Slide_Low;/* ���ת�ٴ��ڸ�ֵ��Ϊ�������ڻ�������״̬��D���� */
extern CAL_TQM uint16_T ASM_S11_GearR_Delay;/* ͣ����R���ĳ���ʱ����ڸ�ֵ�������������¹��ܣ�R���� */
extern CAL_TQM uint16_T ASM_S11_GearR_Spd_Slide_Delay;/* �������뻺������״̬�ĳ���ʱ����ڸ�ֵ����Ϊ����ȷʵ���ڻ�������״̬��R���� */
extern CAL_TQM int16_T ASM_S11_GearR_Spd_Slide_Hig;/* ���ת��С�ڸ�ֵ��Ϊ�������ڻ�������״̬��R���� */
extern CAL_TQM int16_T ASM_S11_GearR_Spd_Slide_Low;/* ���ת�ٴ��ڸ�ֵ��Ϊ�������ڻ�������״̬��R���� */
extern CAL_TQM uint16_T ASM_S11_MCU_Spd_Static_TrueDelay;/* �����б�Ϊ��ֹ״̬����С������ֹʱ�� */
extern CAL_TQM uint16_T ASM_S11_MCU_Spd_Static_ZeroDelay;/* �����б�Ϊ�Ǿ�ֹ״̬����С������ֹʱ�� */
extern CAL_TQM uint16_T ASM_S11_StaticConfirm_TrueDelay;/* �����жϳ����ȶ���ֹ�ĳ���ʱ��-���ڷ�����ʱ�ĽǶ��ж� */
extern CAL_TQM uint16_T ASM_Uena_AntiSlide_Spd_Delay;/* �����³��ٳ���ʱ����ʱ */
extern CAL_TQM uint16_T BLC_ChrgConnectConfirm_Delay;/* ��������ź�����ȷ�ϣ����ʱ����ӦEPB�ĵ����ƶ������� */
extern CAL_TQM uint16_T BLC_ChrgConnectQuit_Delay;/* ��������źŶϿ�ȷ�ϣ����ʱ����ӦEPB�ĵ����ƶ������� */
extern CAL_TQM uint8_T BLC_EPBConfirmSpd_Cal;/* EPB����ʱ�����ƶ��Ƶĳ������� */
extern CAL_TQM uint8_T BLC_EPBQuitSpd_Cal;/* EPB����ʱϨ���ƶ��Ƶĳ������� */
extern CAL_TQM int16_T BLC_GearD_LampOff_Tq;/* D����������Ϩ���ƶ��ƵĻ���Ť����ֵ */
extern CAL_TQM int16_T BLC_GearD_LampOn_Tq;/* D���������������ƶ��ƵĻ���Ť����ֵ */
extern CAL_TQM int16_T BLC_GearR_LampOff_Tq;/* R����������Ϩ���ƶ��ƵĻ���Ť����ֵ */
extern CAL_TQM int16_T BLC_GearR_LampOn_Tq;/* R���������������ƶ��ƵĻ���Ť����ֵ */
extern CAL_TQM boolean_T Cal_AccePctMode_flg;/* �ֶ����������������������̤��ģʽѡ�񿪹� */
extern CAL_TQM uint16_T Cal_ClutchSysEnable_TrueDelay;/* �ֶ������������ʹ��ȷ��ʱ�� */
extern CAL_TQM uint16_T Cal_ClutchSysEnable_ZeroDelay;/* �ֶ�������������ͷ�ȷ��ʱ�� */
extern CAL_TQM real32_T Cal_Clutchlinkage_Threshold;/* �ֶ����������������������̤�������ֵ */
extern CAL_TQM int16_T Cal_Creep_GearD_VehSpeed;/* D������Ŀ�공�� */
extern CAL_TQM int16_T Cal_Creep_GearR_VehSpeed;/* R������Ŀ�공�� */
extern CAL_TQM boolean_T Cal_Ready_En; /* �ֶ��������������λ����READY���� */
extern CAL_TQM boolean_T Cal_Ready_Val;/* �ֶ��������������λ����READY��ֵ */
extern CAL_TQM boolean_T Cal_RegenGrade_Ena;/* ���л����ȼ�ǿ�ƿ��ƿ��� */
extern CAL_TQM uint8_T Cal_RegenGrade_Val;/* ���л����ȼ�ǿ�ƿ��Ƹ�ֵ */
extern CAL_TQM uint8_T Cal_pedalCoefficient;/* �ֶ����������������������̤����ȷֶ����Ӷ��� */
extern CAL_TQM int16_T CreepD_Spd_Forward_limit_Off;/* D�����������˳����� */
extern CAL_TQM int16_T CreepD_Spd_Forward_limit_On;/* D������������복�� */
extern CAL_TQM int16_T CreepD_Spd_Reverse_limit;/* D������������복�� */
extern CAL_TQM int16_T CreepR_Spd_Forward_limit;/* R������������복�� */
extern CAL_TQM int16_T CreepR_Spd_Reserve_limit_Off;/* R�����������˳����� */
extern CAL_TQM int16_T CreepR_Spd_Reserve_limit_On;/* R������������복�� */
extern CAL_TQM uint16_T Creep_Ki_GearD[17];/* D������Ki���-Ki */
extern CAL_TQM uint16_T Creep_Ki_GearR[17];/* R������Ki���-Ki */
extern CAL_TQM uint16_T Creep_Kp_GearD[17];/* D������Kp���-Kp */
extern CAL_TQM uint16_T Creep_Kp_GearR[17];/* R������Kp���-Kp */
extern CAL_TQM int16_T CrpVehSpd_DV[17];/* R/D������Kp/Ki���-���ٲ� */
extern CAL_TQM uint16_T DTD_GearD_Brake_CloseToGear_MotSpd_Ena;/* D�����ݹ��ܿ���ת�٣����ƶ��� */
extern CAL_TQM uint16_T DTD_GearD_Brake_CloseToGear_MotSpd_Uena;/* D�����ݹ��ܹر�ת�٣����ƶ��� */
extern CAL_TQM int8_T DTD_GearD_Brake_CloseToGear_Tq;/* D������Ť�أ����ƶ�����map����Ϊ��ֵ�� */
extern CAL_TQM boolean_T DTD_GearD_CloseToGear_Ena;/* D�����ݹ��ܿ��� */
extern CAL_TQM uint16_T DTD_GearD_CloseToGear_MotSpd_Ena;/* D�����ݹ��ܿ���ת�٣�δ���ƶ��� */
extern CAL_TQM uint16_T DTD_GearD_CloseToGear_MotSpd_Uena;/* D�����ݹ��ܹر�ת�٣�δ���ƶ��� */
extern CAL_TQM int8_T DTD_GearD_CloseToGear_Tq;/* D������Ť�أ�δ���ƶ�����map����Ϊ��ֵ�� */
extern CAL_TQM uint16_T DTD_GearR_Brake_CloseToGear_MotSpd_Ena;/* R�����ݹ��ܿ���ת�٣����ƶ��� */
extern CAL_TQM uint16_T DTD_GearR_Brake_CloseToGear_MotSpd_Uena;/* R�����ݹ��ܹر�ת�٣����ƶ��� */
extern CAL_TQM int8_T DTD_GearR_Brake_CloseToGear_Tq;/* R������Ť�أ����ƶ�����map����Ϊ��ֵ�� */
extern CAL_TQM boolean_T DTD_GearR_CloseToGear_Ena;/* R�����ݹ��ܿ��� */
extern CAL_TQM uint16_T DTD_GearR_CloseToGear_MotSpd_Ena;/* R�����ݹ��ܿ���ת�٣�δ���ƶ��� */
extern CAL_TQM uint16_T DTD_GearR_CloseToGear_MotSpd_Uena;/* R�����ݹ��ܹر�ת�٣�δ���ƶ��� */
extern CAL_TQM int8_T DTD_GearR_CloseToGear_Tq;/* R������Ť�أ�δ���ƶ�����map����Ϊ��ֵ�� */
extern CAL_TQM uint16_T ECM_EPB_Acceleration_X_Filter;
extern CAL_TQM uint16_T ECM_SAS_SteeringAngleSpeed_Filter;
extern CAL_TQM uint16_T ECM_SAS_SteeringAngle_Filter;
extern CAL_TQM uint8_T ENUM_MCUMODE_SpdCtl;/* ���ת�ٻ����Ʊ�־ */
extern CAL_TQM uint8_T ENUM_MCUMODE_TRQCTL;/* ���Ť�ػ����Ʊ�־ */
extern CAL_TQM uint8_T ENUM_TMMODE_MOTOR;/* ����ŵ�ģʽ��־ */
extern CAL_TQM uint8_T ENUM_TMMODE_REGEN;/* �������ģʽ��־ */
extern CAL_TQM uint8_T ENUM_TQF_DEC;   /* Ť���½���־ */
extern CAL_TQM uint8_T ENUM_TQF_INC;   /* Ť��������־ */
extern CAL_TQM uint8_T ENUM_TQF_STEADY;/* Ť���ȶ���־ */
extern CAL_TQM uint16_T EPB_Delay_time;/* EPB��פ������Ч���ж�ʱ�� */
extern CAL_TQM uint8_T FDT_ClutchEnRegen_Spd_Off;/* �ֶ��������������ק����ʹ�ܳ��ٹر���ֵ */
extern CAL_TQM uint8_T FDT_ClutchEnRegen_Spd_On;/* �ֶ��������������ק����ʹ�ܳ��ٿ�����ֵ */
extern CAL_TQM uint8_T FDT_Crp_PID_SteadyConst;/* ����PID�����е���̬���� */
extern CAL_TQM int8_T FDT_GearD_BrakeRegenTq_Offset;/* R���ƶ�����Ť��ƫ���� */
extern CAL_TQM int16_T FDT_GearD_Crp_Tqlim_Low;/* D�����е���С���Ť�� */
extern CAL_TQM int16_T FDT_GearD_Crp_Tqlim_Up;/* D�����е�������Ť�� */
extern CAL_TQM int8_T FDT_GearR_BrakeRegenTq_Offset;/* D���ƶ�����Ť��ƫ���� */
extern CAL_TQM int16_T FDT_GearR_Crp_Tqlim_Low;/* R�����е���С���Ť�� */
extern CAL_TQM int16_T FDT_GearR_Crp_Tqlim_Up;/* R�����е�������Ť�� */
extern CAL_TQM uint8_T FDT_Regen_Spd_Off;/* �������չرն�Ӧ�ĳ������� */
extern CAL_TQM uint8_T FDT_Regen_Spd_On;/* �������տ�����Ӧ�ĳ������� */
extern CAL_TQM uint8_T Forward;        /* �����ת��־ */
extern CAL_TQM uint8_T GTC_GearTouch_Direction_Ena;/* ���ݷ���ʹ�ܿ��� */
extern CAL_TQM uint8_T GTC_GearTouch_Direction_Val;/* ���ݷ���ʹ��ֵ */
extern CAL_TQM boolean_T GTC_GearTouch_Ena;/* Ť�ؿ��ݹ���ʹ�ܿ��� */
extern CAL_TQM uint8_T GTC_GearTouch_EnaSpd_Hig;/* С�ڸó�������ִ�п��� */
extern CAL_TQM uint8_T GTC_GearTouch_EnaSpd_Low;/* ���ڸó�������ִ�п��� */
extern CAL_TQM uint16_T GTC_GearTouch_NtoP_Timer1;/* ��һ�ο���Ť�س���ʱ�䡪������Ť���ɸ����� */
extern CAL_TQM uint16_T GTC_GearTouch_NtoP_Timer2;/* ǰ���ο���Ť�س���ʱ��֮�͡�������Ť���ɸ����� */
extern CAL_TQM uint16_T GTC_GearTouch_NtoP_Timer3;/* ǰ���ο���Ť�س���ʱ��֮�͡�������Ť���ɸ����� */
extern CAL_TQM uint16_T GTC_GearTouch_NtoP_Timer4;/* ǰ�Ķο���Ť�س���ʱ��֮�͡�������Ť���ɸ����� */
extern CAL_TQM real32_T GTC_GearTouch_NtoP_Tq1;/* ���㿿��Ť�ص�һ�Ρ�������Ť���ɸ����� */
extern CAL_TQM real32_T GTC_GearTouch_NtoP_Tq2;/* ���㿿��Ť�صڶ��Ρ�������Ť���ɸ����� */
extern CAL_TQM real32_T GTC_GearTouch_NtoP_Tq3;/* ���㿿��Ť�ص����Ρ�������Ť���ɸ����� */
extern CAL_TQM real32_T GTC_GearTouch_NtoP_Tq4;/* ���㿿��Ť�ص��ĶΡ�������Ť���ɸ����� */
extern CAL_TQM uint16_T GTC_GearTouch_PtoN_Timer1;/* ��һ�ο���Ť�س���ʱ�䡪������Ť�������为 */
extern CAL_TQM uint16_T GTC_GearTouch_PtoN_Timer2;/* ǰ���ο���Ť�س���ʱ��֮�͡�������Ť�������为 */
extern CAL_TQM uint16_T GTC_GearTouch_PtoN_Timer3;/* ǰ���ο���Ť�س���ʱ��֮�͡�������Ť�������为 */
extern CAL_TQM uint16_T GTC_GearTouch_PtoN_Timer4;/* ǰ�Ķο���Ť�س���ʱ��֮�͡�������Ť�������为 */
extern CAL_TQM real32_T GTC_GearTouch_PtoN_Tq1;/* ���㿿��Ť�ص�һ�Ρ�������Ť�������为 */
extern CAL_TQM real32_T GTC_GearTouch_PtoN_Tq2;/* ���㿿��Ť�صڶ��Ρ�������Ť�������为 */
extern CAL_TQM real32_T GTC_GearTouch_PtoN_Tq3;/* ���㿿��Ť�ص����Ρ�������Ť�������为 */
extern CAL_TQM real32_T GTC_GearTouch_PtoN_Tq4;/* ���㿿��Ť�ص��ĶΡ�������Ť�������为 */
extern CAL_TQM uint8_T GTC_GearTouch_UnEnaSpd_Hig;/* ���ڸó��ٽ�ֹ���� */
extern CAL_TQM uint8_T GTC_GearTouch_UnEnaSpd_Low;/* С�ڸó��ٽ�ֹ���� */
extern CAL_TQM real32_T GTC_ZeroAcross_Tq;/* Ť�ع����ж���ֵ */
extern CAL_TQM uint8_T GearD;          /* D�� */
extern CAL_TQM uint8_T GearD_Release;  /* N�°��г� */
extern CAL_TQM uint8_T GearR_Release;  /* N�ϰ��г� */
extern CAL_TQM uint8_T Gear_D;         /* D����־ */
extern CAL_TQM uint8_T Gear_D1;        /* �ֶ�������D1�� */
extern CAL_TQM uint8_T Gear_D2;        /* �ֶ�������D2�� */
extern CAL_TQM uint8_T Gear_D3;        /* �ֶ�������D3�� */
extern CAL_TQM uint8_T Gear_D4;        /* �ֶ�������D4�� */
extern CAL_TQM uint8_T Gear_D5;        /* �ֶ�������D5�� */
extern CAL_TQM uint8_T Gear_N;         /* N����־ */
extern CAL_TQM uint8_T Gear_P;         /* P����־ */
extern CAL_TQM uint8_T Gear_R;         /* R����־ */
extern CAL_TQM uint32_T Gravitational_Accel;/* �������ٶ� */
extern CAL_TQM int16_T KNEDC_AccDeltaLower_mps;
extern CAL_TQM int16_T KNEDC_AccDeltaUpper_mps;
extern CAL_TQM uint8_T KNEDC_BRAKETYPE_KMPH120120;
extern CAL_TQM uint8_T KNEDC_BRAKETYPE_KMPH12050;
extern CAL_TQM uint8_T KNEDC_BRAKETYPE_KMPH12080;
extern CAL_TQM uint8_T KNEDC_BRAKETYPE_KMPH15;
extern CAL_TQM uint8_T KNEDC_BRAKETYPE_KMPH32;
extern CAL_TQM uint8_T KNEDC_BRAKETYPE_KMPH35;
extern CAL_TQM uint8_T KNEDC_BRAKETYPE_KMPH50;
extern CAL_TQM uint8_T KNEDC_BRAKETYPE_KMPH70;
extern CAL_TQM int16_T KNEDC_BrakeTorqueILower_Nm;
extern CAL_TQM int16_T KNEDC_BrakeTorqueIReset_Nm;
extern CAL_TQM int16_T KNEDC_BrakeTorqueIStep_Nm;
extern CAL_TQM int16_T KNEDC_BrakeTorqueIUpper_Nm;
extern CAL_TQM uint8_T KNEDC_SpeedHyst_kmph;/* NEDC�����жϵ�������ƫ�� */
extern CAL_TQM int16_T KNEDC_kmph120120Acc_mps;
extern CAL_TQM int16_T KNEDC_kmph12050Acc_mps;
extern CAL_TQM int16_T KNEDC_kmph12080Acc_mps;
extern CAL_TQM uint16_T KNEDC_kmph120HoldTime_s;/* �б����NEDC����120kph�ȶ����������120kph��Сά��ʱ�� */
extern CAL_TQM uint8_T KNEDC_kmph120_kmph;/* 120kph���ٱ�־ */
extern CAL_TQM int16_T KNEDC_kmph15Acc_mps;
extern CAL_TQM uint16_T KNEDC_kmph15HoldTime_s;/* �б����NEDC����15kph�ȶ����������15kph��Сά��ʱ�� */
extern CAL_TQM uint8_T KNEDC_kmph15_kmph;/* 15kph���ٱ�־ */
extern CAL_TQM int16_T KNEDC_kmph32Acc_mps;
extern CAL_TQM uint16_T KNEDC_kmph32HoldTime_s;/* �б����NEDC����32kph�ȶ����������32kph��Сά��ʱ�� */
extern CAL_TQM uint8_T KNEDC_kmph32_kmph;/* 32kph���ٱ�־ */
extern CAL_TQM int16_T KNEDC_kmph35Acc_mps;
extern CAL_TQM uint16_T KNEDC_kmph35HoldTime_s;/* �б����NEDC����35kph�ȶ���������35kph��Сά��ʱ�� */
extern CAL_TQM uint8_T KNEDC_kmph35_kmph;/* 35kph���ٱ�־ */
extern CAL_TQM int16_T KNEDC_kmph50Acc_mps;
extern CAL_TQM uint16_T KNEDC_kmph50HoldTime_s;/* �б����NEDC����50kph�ȶ����������50kph��Сά��ʱ�� */
extern CAL_TQM uint8_T KNEDC_kmph50_kmph;/* 50kph���ٱ�־ */
extern CAL_TQM int16_T KNEDC_kmph70Acc_mps;
extern CAL_TQM uint16_T KNEDC_kmph70HoldTime_s;/* �б����NEDC����70kph�ȶ����������70kph��Сά��ʱ�� */
extern CAL_TQM uint8_T KNEDC_kmph70_kmph;/* 70kph���ٱ�־ */
extern CAL_TQM uint8_T KNEDC_kmph80_kmph;/* 80kph���ٱ�־ */
extern CAL_TQM boolean_T KTQD_NEDCBakeEn_flg;/* NEDC����ʹ�� */
extern CAL_TQM uint16_T KTQD_NEDCBrakeMotorSpeedMin_rpm;/* NEDC�������չ��ܽ����ת������ */
extern CAL_TQM uint16_T KTQF_GearPN_Rate_Nmps;/* P/N��Ť��ж��б������ */
extern CAL_TQM uint16_T KTQF_RTDefaultDEC_Nmps;/* Ť���½�Ĭ��б�ʡ���Ť�ش�����̬ */
extern CAL_TQM uint16_T KTQF_RTDefaultINC_Nmps;/* Ť������Ĭ��б�ʡ���Ť�ش�����̬ */
extern CAL_TQM int8_T KTQF_TMDecRatStepFactor;/* Ť���½�б�ʵ������� */
extern CAL_TQM uint8_T KTQF_TMDecRatStepFilterFactor;/* Ť���½�б���˲����� */
extern CAL_TQM int8_T KTQF_TMIncRatStepFactor;/* Ť������б�ʵ������� */
extern CAL_TQM uint8_T KTQF_TMIncRatStepFilterFactor;/* Ť������б���˲����� */
extern CAL_TQM uint16_T KTQF_TqClunkRateLimitDec_Nmps;/* Ť�ع�����½�б������ */
extern CAL_TQM uint16_T KTQF_TqClunkRateLimitInc_Nmps;/* Ť�ع��������б������ */
extern CAL_TQM uint8_T KTQF_TqClunkThresholdDecHigh_Nm;/* Ť���½�������б�����ֵ */
extern CAL_TQM int8_T KTQF_TqClunkThresholdDecLow_Nm;/* Ť���½�������б�����ֵ */
extern CAL_TQM uint8_T KTQF_TqClunkThresholdIncHigh_Nm;/* Ť������������б�����ֵ */
extern CAL_TQM int8_T KTQF_TqClunkThresholdIncLow_Nm;/* Ť������������б�����ֵ */
extern CAL_TQM int32_T KTQF_TqPrecisionLimit_Nm;/* �����ж�Ť���������ȶ��½�״̬����СŤ������ */
extern CAL_TQM uint16_T MAM_K11_MCUAntiSlidePowerEna_rpm;/* K11���÷ŵ繦�ʴ��ڸ�ֵ��ɿ��������¹��� */
extern CAL_TQM uint16_T MAM_K11_MCUAntiSlidePowerForbid_rpm;/* K11���÷ŵ繦�ʴ��ڸ�ֵ���˳������¹��� */
extern CAL_TQM int16_T MAM_K11_MCUAntiSlideSpdEna_rpm;/* K11�����¹��ܿ���ת�� */
extern CAL_TQM int16_T MAM_K11_MCUAntiSlideSpdForbid_rpm;/* K11�����¹����˳�ת�� */
extern CAL_TQM uint16_T MAS_DisAntishake_Delay;/* MCU�������ܹر���ʱ */
extern CAL_TQM uint16_T MAS_EnaAntishake_Delay;/* MCU�������ܿ�����ʱ */
extern CAL_TQM uint16_T MNEDC_kmph120120Brake_X_kmph[15];/* NEDC����120kph����Ť��map-���� */
extern CAL_TQM int16_T MNEDC_kmph120120Brake_Z_Nm[15];/* NEDC����120kph����Ť��map-Ť�� */
extern CAL_TQM uint16_T MNEDC_kmph15Brake_X_kmph[15];/* NEDC����15kph����Ť��map-���� */
extern CAL_TQM int16_T MNEDC_kmph15Brake_Z_Nm[15];/* NEDC����15kph����Ť��map-Ť�� */
extern CAL_TQM uint16_T MNEDC_kmph32Brake_X_kmph[15];/* NEDC����32kph����Ť��map-���� */
extern CAL_TQM int16_T MNEDC_kmph32Brake_Z_Nm[15];/* NEDC����32kph����Ť��map-Ť�� */
extern CAL_TQM uint16_T MNEDC_kmph35Brake_X_kmph[15];/* NEDC����35kph����Ť��map-���� */
extern CAL_TQM int16_T MNEDC_kmph35Brake_Z_Nm[15];/* NEDC����35kph����Ť��map-Ť�� */
extern CAL_TQM uint16_T MNEDC_kmph50Brake_X_kmph[15];/* NEDC����50kph����Ť��map-���� */
extern CAL_TQM int16_T MNEDC_kmph50Brake_Z_Nm[15];/* NEDC����50kph����Ť��map-Ť�� */
extern CAL_TQM uint16_T MNEDC_kmph70Brake_X_kmph[15];/* NEDC����70kph����Ť��map-���� */
extern CAL_TQM int16_T MNEDC_kmph70Brake_Z_Nm[15];/* NEDC����70kph����Ť��map-Ť�� */
extern CAL_TQM int16_T MTQD_GearD_BrakeRegen_Zero_Tq[19];/* D���ƶ���������Ť��map-Ť�أ��㵲���գ� */
extern CAL_TQM int16_T MTQD_GearD_CoastRegen_First_Tq[19];/* D��������������Ť��map-Ť�أ�һ�����գ� */
extern CAL_TQM int16_T MTQD_GearD_CoastRegen_Fourth_Tq[19];/* D��������������Ť��map-Ť�أ��ĵ����գ� */
extern CAL_TQM int16_T MTQD_GearD_CoastRegen_Second_Tq[19];/* D��������������Ť��map-Ť�أ��������գ� */
extern CAL_TQM uint16_T MTQD_GearD_CoastRegen_Spd[19];/* D��������������Ť��map-ת�� */
extern CAL_TQM int16_T MTQD_GearD_CoastRegen_Third_Tq[19];/* D��������������Ť��map-Ť�أ��������գ� */
extern CAL_TQM int16_T MTQD_GearR_BrakeRegen_Zero_Tq[19];/* R���ƶ���������Ť��map-Ť�أ��㵲���գ� */
extern CAL_TQM int16_T MTQD_GearR_CoastRegen_First_Tq[19];/* R��������������Ť��map-Ť�أ�һ�����գ� */
extern CAL_TQM int16_T MTQD_GearR_CoastRegen_Fourth_Tq[19];/* R��������������Ť��map-Ť�أ��ĵ����գ� */
extern CAL_TQM int16_T MTQD_GearR_CoastRegen_Second_Tq[19];/* R��������������Ť��map-Ť�أ��������գ� */
extern CAL_TQM uint16_T MTQD_GearR_CoastRegen_Spd[19];/* R��������������Ť��map-ת�� */
extern CAL_TQM int16_T MTQD_GearR_CoastRegen_Third_Tq[19];/* R��������������Ť��map-Ť�أ��������գ� */
extern CAL_TQM uint16_T MTQD_PedalMapAccpedal_ClutchMode_pct[16];/* �ֶ�������D����ֵŤ�ذٷֱ�amp-����̤�忪�� */
extern CAL_TQM uint16_T MTQD_PedalMapBoostAccpedal_Eco_pct[16];/* NormalģʽD����ֵŤ�ذٷֱ�amp-����̤�忪�� */
extern CAL_TQM uint16_T MTQD_PedalMapBoostAccpedal_X_pct[16];/* SportģʽD����ֵŤ�ذٷֱ�amp-����̤�忪�� */
extern CAL_TQM uint16_T MTQD_PedalMapBoostTmSpeed_Eco_rpm[12];/* NormalģʽD����ֵŤ�ذٷֱ�amp-ת�� */
extern CAL_TQM uint16_T MTQD_PedalMapBoostTmSpeed_Y_rpm[12];/* SportģʽD����ֵŤ�ذٷֱ�amp-ת�� */
extern CAL_TQM uint16_T MTQD_PedalMapBoost_Eco_pct[192];/* NormalģʽD����ֵŤ�ذٷֱ�amp-�ٷֱ� */
extern CAL_TQM uint16_T MTQD_PedalMapBoost_pct[192];/* SportģʽD����ֵŤ�ذٷֱ�amp-�ٷֱ� */
extern CAL_TQM uint16_T MTQD_PedalMapClutchMode_Fifth_pct[192];/* �ֶ�������D5��Ť�ذٷֱ�amp-�ٷֱ� */
extern CAL_TQM uint16_T MTQD_PedalMapClutchMode_First_pct[192];/* �ֶ�������D1��Ť�ذٷֱ�amp-�ٷֱ� */
extern CAL_TQM uint16_T MTQD_PedalMapClutchMode_Fourth_pct[192];/* �ֶ�������D4��Ť�ذٷֱ�amp-�ٷֱ� */
extern CAL_TQM uint16_T MTQD_PedalMapClutchMode_Second_pct[192];/* �ֶ�������D2��Ť�ذٷֱ�amp-�ٷֱ� */
extern CAL_TQM uint16_T MTQD_PedalMapClutchMode_Third_pct[192];/* �ֶ�������D3��Ť�ذٷֱ�amp-�ٷֱ� */
extern CAL_TQM uint16_T MTQD_PedalMapRevAccpedal_ClutchMode_pct[16];/* �ֶ�������R����ֵŤ�ذٷֱ�amp-����̤�忪�� */
extern CAL_TQM uint16_T MTQD_PedalMapRevAccpedal_X_pct[16];/* R����ֵŤ�ذٷֱ�amp-����̤�忪�� */
extern CAL_TQM uint16_T MTQD_PedalMapRevTmSpeed_ClutchMode_rpm[12];/* �ֶ�������R����ֵŤ�ذٷֱ�amp-ת�� */
extern CAL_TQM uint16_T MTQD_PedalMapRevTmSpeed_Y_rpm[12];/* R����ֵŤ�ذٷֱ�amp-ת�� */
extern CAL_TQM uint16_T MTQD_PedalMapRev_ClutchMode_pct[192];/* �ֶ�������R��Ť�ذٷֱ�amp-�ٷֱ� */
extern CAL_TQM uint16_T MTQD_PedalMapRev_pct[192];/* R����ֵŤ�ذٷֱ�amp-�ٷֱ� */
extern CAL_TQM uint16_T MTQD_PedalMapTmSpeed_ClutchMode_rpm[12];/* �ֶ�������D����ֵŤ�ذٷֱ�amp-ת�� */
extern CAL_TQM uint16_T MTQD_TqMapPeakTmSpeed_X_rpm[22];/* ���������map-ת�� */
extern CAL_TQM int16_T MTQD_TqMapPeakTq_Nm[22];/* ���������map-Ť�� */
extern CAL_TQM uint16_T MTQD_TqMapRevTmSpeed_X_rpm[22];/* R����ֵŤ��map-ת�� */
extern CAL_TQM int16_T MTQD_TqMapRevTq_Nm[22];/* R����ֵŤ��map-Ť�� */
extern CAL_TQM uint16_T PTT_MotDriveEffi_Pct[182];/* ����ϵͳ�ŵ�Ч��map-Ч�� */
extern CAL_TQM uint16_T PTT_MotDriveEffi_Power[14];/* ����ϵͳ�ŵ�Ч��map-���� */
extern CAL_TQM uint16_T PTT_MotDriveEffi_Spd[13];/* ����ϵͳ�ŵ�Ч��map-ת�� */
extern CAL_TQM uint16_T PTT_MotRegenEffi_Pct[182];/* ����ϵͳ����Ч��map-Ч�� */
extern CAL_TQM uint16_T PTT_MotRegenEffi_Power[14];/* ����ϵͳ����Ч��map-���� */
extern CAL_TQM uint16_T PTT_MotRegenEffi_Spd[13];/* ����ϵͳ����Ч��map-ת�� */
extern CAL_TQM uint16_T P_Delay_time;  /* ��P���ȴ�EPB��פʱ�� */
extern CAL_TQM uint8_T Period;         /* ģ������ʱ��-ms */
extern CAL_TQM uint16_T REC_No_Evflag_TrueDelay;/* ��ֹ�������ձ�־����ʱ���ж�-����ʱ����ڸ�ֵ����Ϊ��Ч�������� */
extern CAL_TQM uint8_T REC_RegenEnaAccePct_Cal;/* ����̤�忪�ȴ��ڸ�ֵʱ��λ�������ձ�־ */
extern CAL_TQM uint8_T REC_RegenEnaSpd_Cal;/* ���ٵ��ڸ�ֵʱ��λ�������ձ�־ */
extern CAL_TQM uint16_T RampExecTime;  /* б�����Ʋ�������ʱ�� */
extern CAL_TQM uint8_T Reverse;        /* �����ת��־ */
extern CAL_TQM uint8_T SpeedAccelBuffer;
extern CAL_TQM uint8_T SpeedAccel_Alpha;
extern CAL_TQM uint8_T Sport_Mode;     /* �˶�ģʽ��־ */
extern CAL_TQM uint8_T Standstill;     /* �����ֹ��־ */
extern CAL_TQM boolean_T TQD_FALSE;
extern CAL_TQM boolean_T TQD_TRUE;
extern CAL_TQM int8_T TQD_integral_reset_value;/* i����Ť�ؼ�������ֵ */
extern CAL_TQM int16_T TQD_max_dmd;    /* i���ּ�������Ť�� */
extern CAL_TQM int16_T TQD_min_dmd;    /* i���ּ�������Ť�� */
extern CAL_TQM uint16_T TQF_DriveDecDistance_Filter1;/* б��1 */
extern CAL_TQM uint16_T TQF_DriveDecDistance_Filter2;/* б��2 */
extern CAL_TQM uint16_T TQF_DriveDecDistance_Filter3;/* б��3 */
extern CAL_TQM uint16_T TQF_DriveDecDistance_Filter4;/* б��4 */
extern CAL_TQM uint16_T TQF_DriveDecDistance_Filter5;/* б��5 */
extern CAL_TQM uint16_T TQF_DriveDecDistance_Filter6;/* б��6�������� */
extern CAL_TQM uint16_T TQF_DriveDecDistance_Filter7;/* б��7�������� */
extern CAL_TQM uint16_T TQF_DriveDecDistance_Filter8;/* б��8�������� */
extern CAL_TQM uint16_T TQF_DriveDecTq1;/* ���Ť��1 */
extern CAL_TQM uint16_T TQF_DriveDecTq2;/* ���Ť��2 */
extern CAL_TQM uint16_T TQF_DriveDecTq3;/* ���Ť��3 */
extern CAL_TQM uint16_T TQF_DriveDecTq4;/* ���Ť��4 */
extern CAL_TQM uint16_T TQF_DriveDecTq5;/* ���Ť��5�������� */
extern CAL_TQM uint16_T TQF_DriveDecTq6;/* ���Ť��6�������� */
extern CAL_TQM uint16_T TQF_DriveDecTq7;/* ���Ť��7�������� */
extern CAL_TQM uint16_T TQF_DriveDecTqDistance1;/* ����Ť�������Ť�ز�ֵ1 */
extern CAL_TQM uint16_T TQF_DriveDecTqDistance2;/* ����Ť�������Ť�ز�ֵ2 */
extern CAL_TQM uint16_T TQF_DriveDecTqDistance3;/* ����Ť�������Ť�ز�ֵ3 */
extern CAL_TQM uint16_T TQF_DriveDecTqDistance4;/* ����Ť�������Ť�ز�ֵ4 */
extern CAL_TQM uint16_T TQF_DriveDecTqDistance5;/* ����Ť�������Ť�ز�ֵ5�������� */
extern CAL_TQM uint16_T TQF_DriveDecTqDistance6;/* ����Ť�������Ť�ز�ֵ6�������� */
extern CAL_TQM uint16_T TQF_DriveDecTqDistance7;/* ����Ť�������Ť�ز�ֵ7�������� */
extern CAL_TQM uint16_T TQF_DriveDec_Filter1;/* б��1 */
extern CAL_TQM uint16_T TQF_DriveDec_Filter2;/* б��2 */
extern CAL_TQM uint16_T TQF_DriveDec_Filter3;/* б��3 */
extern CAL_TQM uint16_T TQF_DriveDec_Filter4;/* б��4 */
extern CAL_TQM uint16_T TQF_DriveDec_Filter5;/* б��5 */
extern CAL_TQM uint16_T TQF_DriveDec_Filter6;/* б��6�������� */
extern CAL_TQM uint16_T TQF_DriveDec_Filter7;/* б��7�������� */
extern CAL_TQM uint16_T TQF_DriveDec_Filter8;/* б��8�������� */
extern CAL_TQM uint16_T TQF_DriveIncDistance_Filter1;/* б��1 */
extern CAL_TQM uint16_T TQF_DriveIncDistance_Filter2;/* б��2 */
extern CAL_TQM uint16_T TQF_DriveIncDistance_Filter3;/* б��3 */
extern CAL_TQM uint16_T TQF_DriveIncDistance_Filter4;/* б��4 */
extern CAL_TQM uint16_T TQF_DriveIncDistance_Filter5;/* б��5 */
extern CAL_TQM uint16_T TQF_DriveIncDistance_Filter6;/* б��6�������� */
extern CAL_TQM uint16_T TQF_DriveIncDistance_Filter7;/* б��7�������� */
extern CAL_TQM uint16_T TQF_DriveIncDistance_Filter8;/* б��8�������� */
extern CAL_TQM uint16_T TQF_DriveIncTq1;/* ���Ť��1 */
extern CAL_TQM uint16_T TQF_DriveIncTq2;/* ���Ť��2 */
extern CAL_TQM uint16_T TQF_DriveIncTq3;/* ���Ť��3 */
extern CAL_TQM uint16_T TQF_DriveIncTq4;/* ���Ť��4 */
extern CAL_TQM uint16_T TQF_DriveIncTq5;/* ���Ť��5�������� */
extern CAL_TQM uint16_T TQF_DriveIncTq6;/* ���Ť��6�������� */
extern CAL_TQM uint16_T TQF_DriveIncTq7;/* ���Ť��7�������� */
extern CAL_TQM uint16_T TQF_DriveIncTqDistance1;/* ����Ť�������Ť�ز�ֵ1 */
extern CAL_TQM uint16_T TQF_DriveIncTqDistance2;/* ����Ť�������Ť�ز�ֵ2 */
extern CAL_TQM uint16_T TQF_DriveIncTqDistance3;/* ����Ť�������Ť�ز�ֵ3 */
extern CAL_TQM uint16_T TQF_DriveIncTqDistance4;/* ����Ť�������Ť�ز�ֵ4 */
extern CAL_TQM uint16_T TQF_DriveIncTqDistance5;/* ����Ť�������Ť�ز�ֵ5�������� */
extern CAL_TQM uint16_T TQF_DriveIncTqDistance6;/* ����Ť�������Ť�ز�ֵ6�������� */
extern CAL_TQM uint16_T TQF_DriveIncTqDistance7;/* ����Ť�������Ť�ز�ֵ7�������� */
extern CAL_TQM uint16_T TQF_DriveInc_Filter1;/* б��1 */
extern CAL_TQM uint16_T TQF_DriveInc_Filter2;/* б��2 */
extern CAL_TQM uint16_T TQF_DriveInc_Filter3;/* б��3 */
extern CAL_TQM uint16_T TQF_DriveInc_Filter4;/* б��4 */
extern CAL_TQM uint16_T TQF_DriveInc_Filter5;/* б��5 */
extern CAL_TQM uint16_T TQF_DriveInc_Filter6;/* б��6�������� */
extern CAL_TQM uint16_T TQF_DriveInc_Filter7;/* б��7�������� */
extern CAL_TQM uint16_T TQF_DriveInc_Filter8;/* б��8�������� */
extern CAL_TQM uint16_T TQF_EcoDriveIncDistance_Filter1;/* б��1 */
extern CAL_TQM uint16_T TQF_EcoDriveIncDistance_Filter2;/* б��2 */
extern CAL_TQM uint16_T TQF_EcoDriveIncDistance_Filter3;/* б��3 */
extern CAL_TQM uint16_T TQF_EcoDriveIncDistance_Filter4;/* б��4 */
extern CAL_TQM uint16_T TQF_EcoDriveIncDistance_Filter5;/* б��5 */
extern CAL_TQM uint16_T TQF_EcoDriveIncDistance_Filter6;/* б��6�������� */
extern CAL_TQM uint16_T TQF_EcoDriveIncDistance_Filter7;/* б��7�������� */
extern CAL_TQM uint16_T TQF_EcoDriveIncDistance_Filter8;/* б��8�������� */
extern CAL_TQM uint16_T TQF_EcoDriveIncTq1;/* ���Ť��1 */
extern CAL_TQM uint16_T TQF_EcoDriveIncTq2;/* ���Ť��2 */
extern CAL_TQM uint16_T TQF_EcoDriveIncTq3;/* ���Ť��3 */
extern CAL_TQM uint16_T TQF_EcoDriveIncTq4;/* ���Ť��4 */
extern CAL_TQM uint16_T TQF_EcoDriveIncTq5;/* ���Ť��5�������� */
extern CAL_TQM uint16_T TQF_EcoDriveIncTq6;/* ���Ť��6�������� */
extern CAL_TQM uint16_T TQF_EcoDriveIncTq7;/* ���Ť��7�������� */
extern CAL_TQM uint16_T TQF_EcoDriveIncTqDistance1;/* ����Ť�������Ť�ز�ֵ1 */
extern CAL_TQM uint16_T TQF_EcoDriveIncTqDistance2;/* ����Ť�������Ť�ز�ֵ2 */
extern CAL_TQM uint16_T TQF_EcoDriveIncTqDistance3;/* ����Ť�������Ť�ز�ֵ3 */
extern CAL_TQM uint16_T TQF_EcoDriveIncTqDistance4;/* ����Ť�������Ť�ز�ֵ4 */
extern CAL_TQM uint16_T TQF_EcoDriveIncTqDistance5;/* ����Ť�������Ť�ز�ֵ5�������� */
extern CAL_TQM uint16_T TQF_EcoDriveIncTqDistance6;/* ����Ť�������Ť�ز�ֵ6�������� */
extern CAL_TQM uint16_T TQF_EcoDriveIncTqDistance7;/* ����Ť�������Ť�ز�ֵ7�������� */
extern CAL_TQM uint16_T TQF_EcoDriveInc_Filter1;/* б��1 */
extern CAL_TQM uint16_T TQF_EcoDriveInc_Filter2;/* б��2 */
extern CAL_TQM uint16_T TQF_EcoDriveInc_Filter3;/* б��3 */
extern CAL_TQM uint16_T TQF_EcoDriveInc_Filter4;/* б��4 */
extern CAL_TQM uint16_T TQF_EcoDriveInc_Filter5;/* б��5 */
extern CAL_TQM uint16_T TQF_EcoDriveInc_Filter6;/* б��6�������� */
extern CAL_TQM uint16_T TQF_EcoDriveInc_Filter7;/* б��7�������� */
extern CAL_TQM uint16_T TQF_EcoDriveInc_Filter8;/* б��8�������� */
extern CAL_TQM uint16_T TQF_RegenDecDistance_Filter1;/* б��1 */
extern CAL_TQM uint16_T TQF_RegenDecDistance_Filter2;/* б��2 */
extern CAL_TQM uint16_T TQF_RegenDecDistance_Filter3;/* б��3 */
extern CAL_TQM uint16_T TQF_RegenDecDistance_Filter4;/* б��4 */
extern CAL_TQM uint16_T TQF_RegenDecDistance_Filter5;/* б��5 */
extern CAL_TQM uint16_T TQF_RegenDecDistance_Filter6;/* б��6�������� */
extern CAL_TQM uint16_T TQF_RegenDecDistance_Filter7;/* б��7�������� */
extern CAL_TQM uint16_T TQF_RegenDecDistance_Filter8;/* б��8�������� */
extern CAL_TQM uint16_T TQF_RegenDecTq1;/* ���Ť��1 */
extern CAL_TQM uint16_T TQF_RegenDecTq2;/* ���Ť��2 */
extern CAL_TQM uint16_T TQF_RegenDecTq3;/* ���Ť��3 */
extern CAL_TQM uint16_T TQF_RegenDecTq4;/* ���Ť��4 */
extern CAL_TQM uint16_T TQF_RegenDecTq5;/* ���Ť��5�������� */
extern CAL_TQM uint16_T TQF_RegenDecTq6;/* ���Ť��6�������� */
extern CAL_TQM uint16_T TQF_RegenDecTq7;/* ���Ť��7�������� */
extern CAL_TQM uint16_T TQF_RegenDecTqDistance1;/* ����Ť�������Ť�ز�ֵ1 */
extern CAL_TQM uint16_T TQF_RegenDecTqDistance2;/* ����Ť�������Ť�ز�ֵ2 */
extern CAL_TQM uint16_T TQF_RegenDecTqDistance3;/* ����Ť�������Ť�ز�ֵ3 */
extern CAL_TQM uint16_T TQF_RegenDecTqDistance4;/* ����Ť�������Ť�ز�ֵ4 */
extern CAL_TQM uint16_T TQF_RegenDecTqDistance5;/* ����Ť�������Ť�ز�ֵ5�������� */
extern CAL_TQM uint16_T TQF_RegenDecTqDistance6;/* ����Ť�������Ť�ز�ֵ6�������� */
extern CAL_TQM uint16_T TQF_RegenDecTqDistance7;/* ����Ť�������Ť�ز�ֵ7�������� */
extern CAL_TQM uint16_T TQF_RegenDec_Filter1;/* б��1 */
extern CAL_TQM uint16_T TQF_RegenDec_Filter2;/* б��2 */
extern CAL_TQM uint16_T TQF_RegenDec_Filter3;/* б��3 */
extern CAL_TQM uint16_T TQF_RegenDec_Filter4;/* б��4 */
extern CAL_TQM uint16_T TQF_RegenDec_Filter5;/* б��5 */
extern CAL_TQM uint16_T TQF_RegenDec_Filter6;/* б��6�������� */
extern CAL_TQM uint16_T TQF_RegenDec_Filter7;/* б��7�������� */
extern CAL_TQM uint16_T TQF_RegenDec_Filter8;/* б��8�������� */
extern CAL_TQM uint16_T TQF_RegenIncDistance_Filter1;/* б��1 */
extern CAL_TQM uint16_T TQF_RegenIncDistance_Filter2;/* б��2 */
extern CAL_TQM uint16_T TQF_RegenIncDistance_Filter3;/* б��3 */
extern CAL_TQM uint16_T TQF_RegenIncDistance_Filter4;/* б��4 */
extern CAL_TQM uint16_T TQF_RegenIncDistance_Filter5;/* б��5 */
extern CAL_TQM uint16_T TQF_RegenIncDistance_Filter6;/* б��6�������� */
extern CAL_TQM uint16_T TQF_RegenIncDistance_Filter7;/* б��7�������� */
extern CAL_TQM uint16_T TQF_RegenIncDistance_Filter8;/* б��8�������� */
extern CAL_TQM uint16_T TQF_RegenIncTq1;/* ���Ť��1 */
extern CAL_TQM uint16_T TQF_RegenIncTq2;/* ���Ť��2 */
extern CAL_TQM uint16_T TQF_RegenIncTq3;/* ���Ť��3 */
extern CAL_TQM uint16_T TQF_RegenIncTq4;/* ���Ť��4 */
extern CAL_TQM uint16_T TQF_RegenIncTq5;/* ���Ť��5�������� */
extern CAL_TQM uint16_T TQF_RegenIncTq6;/* ���Ť��6�������� */
extern CAL_TQM uint16_T TQF_RegenIncTq7;/* ���Ť��7�������� */
extern CAL_TQM uint16_T TQF_RegenIncTqDistance1;/* ����Ť�������Ť�ز�ֵ1 */
extern CAL_TQM uint16_T TQF_RegenIncTqDistance2;/* ����Ť�������Ť�ز�ֵ2 */
extern CAL_TQM uint16_T TQF_RegenIncTqDistance3;/* ����Ť�������Ť�ز�ֵ3 */
extern CAL_TQM uint16_T TQF_RegenIncTqDistance4;/* ����Ť�������Ť�ز�ֵ4 */
extern CAL_TQM uint16_T TQF_RegenIncTqDistance5;/* ����Ť�������Ť�ز�ֵ5�������� */
extern CAL_TQM uint16_T TQF_RegenIncTqDistance6;/* ����Ť�������Ť�ز�ֵ6�������� */
extern CAL_TQM uint16_T TQF_RegenIncTqDistance7;/* ����Ť�������Ť�ز�ֵ7�������� */
extern CAL_TQM uint16_T TQF_RegenInc_Filter1;/* б��1 */
extern CAL_TQM uint16_T TQF_RegenInc_Filter2;/* б��2 */
extern CAL_TQM uint16_T TQF_RegenInc_Filter3;/* б��3 */
extern CAL_TQM uint16_T TQF_RegenInc_Filter4;/* б��4 */
extern CAL_TQM uint16_T TQF_RegenInc_Filter5;/* б��5 */
extern CAL_TQM uint16_T TQF_RegenInc_Filter6;/* б��6�������� */
extern CAL_TQM uint16_T TQF_RegenInc_Filter7;/* б��7�������� */
extern CAL_TQM uint16_T TQF_RegenInc_Filter8;/* б��8�������� */
extern CAL_TQM boolean_T TQF_TqFilteringEn_flg;/* Ť��б������ʹ�ܿ��� */
extern CAL_TQM int16_T TQM_MaxTq_Cal;  /* ϵͳ����������Ť�� */
extern CAL_TQM uint16_T TQR_BMS_Delaytime;/* BMS��������ʱŤ�ر��ֵȴ����� */
extern CAL_TQM uint16_T TQR_MCU_Delaytime;/* MCU��������ʱŤ�ر��ֵȴ����� */
extern CAL_TQM uint16_T TSC_VehTq_Filter;/* ����Ť���˲�ϵ�� */
extern CAL_TQM uint16_T Tcl;           /* ����������� */
extern CAL_TQM uint32_T Tyre_Radius_Cal;/* ���ֹ����뾶 */
extern CAL_TQM uint16_T VAJ_AccePress_Fail;/* ����̤�忪��С�ڸ�ֵ��Ϊ����̤���ɿ� */
extern CAL_TQM uint16_T VAJ_AccePress_Succ;/* ����̤�忪�ȴ��ڸ�ֵ��Ϊ����̤����� */
extern CAL_TQM uint8_T VGJ_GearOff_Cal;/* ��λϨ���־ */
extern CAL_TQM uint16_T VGJ_GearOff_time_Cal;/* ��λ��˸ʱ��-�� */
extern CAL_TQM uint16_T VGJ_GearOn_time_Cal;/* ��λ��˸ʱ��-�� */
extern CAL_TQM uint8_T VGJ_HigSpd_S11_Cal;/* S11���������ж����� */
extern CAL_TQM uint8_T VGJ_LowSpd_S11_Cal;/* S11��������P���ж����� */
extern CAL_TQM uint8_T VGJ_MidSpd_S11_Cal;/* S11�ͳ���ʱ�����ƶ�N������D��R�������� */
extern CAL_TQM uint16_T VGJ_Remind_time;/* �ҵ���������������ʱ�� */
extern CAL_TQM uint8_T VGJ_Spd_K11_Cal;/* K11���������ж����� */
extern CAL_TQM uint8_T VGJ_Spd_Z18;    /* ��ť��λ�л�������ֵ */
extern CAL_TQM uint16_T VPL_PowerLim_Filter;/* ����ֵ�����˲����� */
extern CAL_TQM uint16_T VPL_PowerPctLim_Filter;/* ���ʰٷֱ������˲����� */
extern CAL_TQM boolean_T VSJ_ABS_Spd_Valid_Ena;/* ABS�����ź���Чλʹ�ܿ��� */
extern CAL_TQM boolean_T VSJ_ABS_Spd_Valid_Val;/* ABS�����ź���Чλʹ��״̬ */
extern CAL_TQM boolean_T VSJ_MCU_Spd_Valid_Ena;/* MCUת���ź���Чλʹ�ܿ��� */
extern CAL_TQM boolean_T VSJ_MCU_Spd_Valid_Val;/* MCUת���ź���Чλʹ�ܿ��� */
extern CAL_TQM int16_T VSJ_SpdNeg_Cal; /* �����ֹ-��ת�б��ٽ�ֵ */
extern CAL_TQM int16_T VSJ_SpdPos_Cal; /* �����ֹ-��ת�б��ٽ�ֵ */
extern CAL_TQM boolean_T VSJ_Spd_Valid_Ena;/* �ٶ��ź���Чλʹ�ܿ��� */
extern CAL_TQM boolean_T VSJ_Spd_Valid_Val;/* �ٶ��ź���Чλʹ��״̬ */
extern CAL_TQM uint8_T VSL_GearD1_YK19_SpdLim_Hig;/* �ֶ�������D1�����Ƴ������� */
extern CAL_TQM uint8_T VSL_GearD1_YK19_SpdLim_Low;/* �ֶ�������D1�����Ƴ������� */
extern CAL_TQM uint8_T VSL_GearD2_YK19_SpdLim_Hig;/* �ֶ�������D2�����Ƴ������� */
extern CAL_TQM uint8_T VSL_GearD2_YK19_SpdLim_Low;/* �ֶ�������D2�����Ƴ������� */
extern CAL_TQM uint8_T VSL_GearD3_YK19_SpdLim_Hig;/* �ֶ�������D3�����Ƴ������� */
extern CAL_TQM uint8_T VSL_GearD3_YK19_SpdLim_Low;/* �ֶ�������D3�����Ƴ������� */
extern CAL_TQM uint8_T VSL_GearD4_YK19_SpdLim_Hig;/* �ֶ�������D4�����Ƴ������� */
extern CAL_TQM uint8_T VSL_GearD4_YK19_SpdLim_Low;/* �ֶ�������D4�����Ƴ������� */
extern CAL_TQM uint8_T VSL_GearD5_YK19_SpdLim_Hig;/* �ֶ�������D5�����Ƴ������� */
extern CAL_TQM uint8_T VSL_GearD5_YK19_SpdLim_Low;/* �ֶ�������D5�����Ƴ������� */
extern CAL_TQM uint8_T VSL_GearD_ECOSpdLim_Hig;/* ECOģʽD���������� */
extern CAL_TQM uint8_T VSL_GearD_ECOSpdLim_Low;/* ECOģʽD���������� */
extern CAL_TQM uint8_T VSL_GearD_SPTSpdLim_Hig;/* SPTģʽD���������� */
extern CAL_TQM uint8_T VSL_GearD_SPTSpdLim_Low;/* SPTģʽD���������� */
extern CAL_TQM uint8_T VSL_GearD_SpdLim_Hig;/* D���������� */
extern CAL_TQM uint8_T VSL_GearD_SpdLim_Low;/* D���������� */
extern CAL_TQM uint8_T VSL_GearR_SpdLim_Hig;/* R���ٶ����� */
extern CAL_TQM uint8_T VSL_GearR_SpdLim_Low;/* R���������� */
extern CAL_TQM uint8_T VSL_GearR_YK19_SpdLim_Hig;/* �ֶ�������R�����Ƴ������� */
extern CAL_TQM uint8_T VSL_GearR_YK19_SpdLim_Low;/* �ֶ�������R�����Ƴ������� */
extern CAL_TQM uint8_T VSL_HighSOC;    /* ���ڸ�SOCֵ�����Ƴ��� */
extern CAL_TQM uint8_T VSL_LowSOC;     /* ���ڸ�SOCֵ���Ƴ��ٵ�130 */
extern CAL_TQM uint8_T VSL_LowSOC_SpdLim_rpm;/* ��SOC���Ƴ��� */
extern CAL_TQM uint8_T VSL_NormSOC_SpdLim_rpm;
extern CAL_TQM uint16_T VSL_SpdLim_Filter;/* ���������˲����� */
extern CAL_TQM boolean_T VTA_Arbitration_Ena;/* �ٲ�ʹ�ܿ��� */
extern CAL_TQM boolean_T VTA_Arbitration_Val;/* �ٲ�ʹ��ֵ */
extern CAL_TQM boolean_T VTA_GearN_Ena;/* N������Ť��ʹ�� */
extern CAL_TQM uint16_T VTA_GearN_MotSpd[14];/* N������Ť��map-ת�� */
extern CAL_TQM int16_T VTA_GearN_Tq[14];/* N������Ť��map-Ť�� */
extern CAL_TQM uint16_T VTA_Gear_P_N_Filter;/* P/N��Ť���˲�ϵ�� */
extern CAL_TQM uint16_T Veh_Sim_Interval_dT;/* ����ʱ�� */
extern CAL_TQM uint32_T Velocity_Ratio_Cal;/* ���ٱ� */
extern CAL_TQM boolean_T b1_C_TQD_ACRCtrEna;/* ���ٶȻ�ʹ�ܿ��� */
extern CAL_TQM boolean_T big_C_ConfigAccSensor_flg;/* ���ٶ���Դ�ж������Ƿ����ü��ٶȴ����� */
extern CAL_TQM uint8_T eSpeedlHistSize;
extern CAL_TQM real32_T f4_C_VSP_AccSpdLower_mpss;/* ʵ�ʼ��ٶ����� */
extern CAL_TQM real32_T f4_C_VSP_AccSpdUpper_mpss;/* ʵ�ʼ��ٶ����� */
extern CAL_TQM real32_T f4_C_VSP_KamFiter_P;/* ���ٶȿ������˲�ϵ��P */
extern CAL_TQM real32_T f4_C_VSP_KamFiter_Q;/* ���ٶȿ������˲�ϵ��Q */
extern CAL_TQM real32_T f4_C_VSP_KamFiter_R;/* ���ٶȿ������˲�ϵ��R */
extern CAL_TQM int16_T lo_dec_limit;   /* б�����Ʋ���Ť�ؼ�Сֵ */
extern CAL_TQM real32_T s1_C_ESC_TqUpOffset;/* ESC����Ť�ش���vcu����Ť����ֵ */
extern CAL_TQM real32_T s1_C_TQM_MCUTqDiff;/* ����Ť����ʵ��Ť�صĲ�ֵ�ж���ֵ */
extern CAL_TQM int8_T s2_C_TQF_DecRatStepFactor;/* Ť���½�б�ʵ�������:��ֵ���������������أ���ֵ*�����������=1s */
extern CAL_TQM int8_T s2_C_TQF_IncRatStepFactor;/* Ť������б�ʵ�������:��ֵ���������������أ���ֵ*�����������=1s */
extern CAL_TQM uint8_T u1_CT_TQF_AbsModRegenTqDecZRat_Nmps[25];/* Creep�����µ������ƶ�Ť�ؼ�Сʱ��б������MAP��Z��(Ϊ�˽�����������,��λΪNm/100ms) */
extern CAL_TQM uint8_T u1_CT_TQF_GearDAccPdlModEcoDriveTqDecZRat_Nmps[25];/* AccelPedal������D��ECOģʽ������Ť�ؼ�Сʱ��б������MAP��Z��(Ϊ�˽�����������,��λΪNm/100ms)(Ϊ�˽�����������,��λΪNm/100ms) */
extern CAL_TQM uint8_T u1_CT_TQF_GearDAccPdlModEcoDriveTqIncZRat_Nmps[25];/* AccelPedal������D��ECOģʽ������Ť������ʱ��б������MAP��Z��(Ϊ�˽�����������,��λΪNm/100ms)(Ϊ�˽�����������,��λΪNm/100ms) */
extern CAL_TQM uint8_T u1_CT_TQF_GearDAccPdlModEcoRegenTqDecZRat_Nmps[25];/* AccelPedal������D��ECOģʽ�������ƶ�Ť�ؼ�Сʱ��б������MAP��Z��(Ϊ�˽�����������,��λΪNm/100ms) */
extern CAL_TQM uint8_T u1_CT_TQF_GearDAccPdlModEcoRegenTqIncZRat_Nmps[25];/* AccelPedal������D��ECOģʽ�������ƶ�Ť������ʱ��б������MAP��Z��(Ϊ�˽�����������,��λΪNm/100ms) */
extern CAL_TQM uint8_T u1_CT_TQF_GearDAccPdlModSportDriveTqDecZRat_Nmps[25];/* AccelPedal������D��SPORTģʽ������Ť�ؼ�Сʱ��б������MAP��Z��(Ϊ�˽�����������,��λΪNm/100ms) */
extern CAL_TQM uint8_T u1_CT_TQF_GearDAccPdlModSportDriveTqIncZRat_Nmps[25];/* AccelPedal������D��SPORTģʽ������Ť������ʱ��б������MAP��Z��(Ϊ�˽�����������,��λΪNm/100ms) */
extern CAL_TQM uint8_T u1_CT_TQF_GearDAccPdlModSportRegenTqDecZRat_Nmps[25];/* AccelPedal������D��SPORTģʽ�������ƶ�Ť�ؼ�Сʱ��б������MAP��Z��(Ϊ�˽�����������,��λΪNm/100ms) */
extern CAL_TQM uint8_T u1_CT_TQF_GearDAccPdlModSportRegenTqIncZRat_Nmps[25];/* AccelPedal������D��SPORTģʽ�������ƶ�Ť������ʱ��б������MAP��Z��(Ϊ�˽�����������,��λΪNm/100ms) */
extern CAL_TQM uint8_T u1_CT_TQF_GearDCreepModDriveTqDecZRat_Nmps[25];/* Creep������D��������Ť�ؼ�Сʱ��б������MAP��Z��(Ϊ�˽�����������,��λΪNm/100ms) */
extern CAL_TQM uint8_T u1_CT_TQF_GearDCreepModDriveTqIncZRat_Nmps[25];/* Creep������D��������Ť������ʱ��б������MAP��Z��(Ϊ�˽�����������,��λΪNm/100ms) */
extern CAL_TQM uint8_T u1_CT_TQF_GearDCreepModRegenTqDecZRat_Nmps[25];/* Creep������D���������ƶ�Ť�ؼ�Сʱ��б������MAP��Z��(Ϊ�˽�����������,��λΪNm/100ms) */
extern CAL_TQM uint8_T u1_CT_TQF_GearDCreepModRegenTqIncZRat_Nmps[25];/* Creep������D���������ƶ�Ť������ʱ��б������MAP��Z��(Ϊ�˽�����������,��λΪNm/100ms) */
extern CAL_TQM uint8_T u1_CT_TQF_GearRAccPdlModEcoDriveTqDecZRat_Nmps[25];/* AccelPedal������R��ECOģʽ������Ť�ؼ�Сʱ��б������MAP��Z��(Ϊ�˽�����������,��λΪNm/100ms)(Ϊ�˽�����������,��λΪNm/100ms) */
extern CAL_TQM uint8_T u1_CT_TQF_GearRAccPdlModEcoDriveTqIncZRat_Nmps[25];/* AccelPedal������R��ECOģʽ������Ť������ʱ��б������MAP��Z��(Ϊ�˽�����������,��λΪNm/100ms)(Ϊ�˽�����������,��λΪNm/100ms) */
extern CAL_TQM uint8_T u1_CT_TQF_GearRAccPdlModEcoRegenTqDecZRat_Nmps[25];/* AccelPedal������R��ECOģʽ�������ƶ�Ť�ؼ�Сʱ��б������MAP��Z��(Ϊ�˽�����������,��λΪNm/100ms) */
extern CAL_TQM uint8_T u1_CT_TQF_GearRAccPdlModEcoRegenTqIncZRat_Nmps[25];/* AccelPedal������R��ECOģʽ�������ƶ�Ť������ʱ��б������MAP��Z��(Ϊ�˽�����������,��λΪNm/100ms) */
extern CAL_TQM uint8_T u1_CT_TQF_GearRAccPdlModSportDriveTqDecZRat_Nmps[25];/* AccelPedal������R��SPORTģʽ������Ť�ؼ�Сʱ��б������MAP��Z��(Ϊ�˽�����������,��λΪNm/100ms) */
extern CAL_TQM uint8_T u1_CT_TQF_GearRAccPdlModSportDriveTqIncZRat_Nmps[25];/* AccelPedal������R��SPORTģʽ������Ť������ʱ��б������MAP��Z��(Ϊ�˽�����������,��λΪNm/100ms) */
extern CAL_TQM uint8_T u1_CT_TQF_GearRAccPdlModSportRegenTqDecZRat_Nmps[25];/* AccelPedal������R��SPORTģʽ�������ƶ�Ť�ؼ�Сʱ��б������MAP��Z��(Ϊ�˽�����������,��λΪNm/100ms) */
extern CAL_TQM uint8_T u1_CT_TQF_GearRAccPdlModSportRegenTqIncZRat_Nmps[25];/* AccelPedal������R��SPORTģʽ�������ƶ�Ť������ʱ��б������MAP��Z��(Ϊ�˽�����������,��λΪNm/100ms) */
extern CAL_TQM uint8_T u1_CT_TQF_GearRCreepModDriveTqDecZRat_Nmps[25];/* Creep������R��������Ť�ؼ�Сʱ��б������MAP��Z��(Ϊ�˽�����������,��λΪNm/100ms) */
extern CAL_TQM uint8_T u1_CT_TQF_GearRCreepModDriveTqIncZRat_Nmps[25];/* Creep������R��������Ť������ʱ��б������MAP��Z��(Ϊ�˽�����������,��λΪNm/100ms) */
extern CAL_TQM uint8_T u1_CT_TQF_GearRCreepModRegenTqDecZRat_Nmps[25];/* Creep������R���������ƶ�Ť�ؼ�Сʱ��б������MAP��Z��(Ϊ�˽�����������,��λΪNm/100ms) */
extern CAL_TQM uint8_T u1_CT_TQF_GearRCreepModRegenTqIncZRat_Nmps[25];/* Creep������R���������ƶ�Ť������ʱ��б������MAP��Z��(Ϊ�˽�����������,��λΪNm/100ms) */
extern CAL_TQM uint8_T u1_CT_TQF_HDCModDriveTqDecZRat_Nmps[25];/* HDC�����µ�����Ť�ؼ�Сʱ��б������MAP��Z��(��λ��Nm/100ms) */
extern CAL_TQM uint8_T u1_CT_TQF_HDCModDriveTqIncZRat_Nmps[25];/* HDC�����µ�����Ť������ʱ��б������MAP��Z��(��λ��Nm/100ms) */
extern CAL_TQM uint8_T u1_CT_TQF_HDCModRegenTqDecZRat_Nmps[25];/* HDC�����µ������ƶ�Ť�ؼ�Сʱ��б������MAP��Z��(��λ��Nm/100ms) */
extern CAL_TQM uint8_T u1_CT_TQF_HDCModRegenTqIncZRat_Nmps[25];/* HDC�����µ������ƶ�Ť������ʱ��б������MAP��Z��(��λ��Nm/100ms) */
extern CAL_TQM uint8_T u1_CT_TQF_HighRegenModDriveTqDecZRat_Nmps[25];/* �߼�Regen�����µ�����Ť�ؼ�Сʱ��б������MAP��Z��(Ϊ�˽�����������,��λΪNm/100ms) */
extern CAL_TQM uint8_T u1_CT_TQF_HighRegenModDriveTqIncZRat_Nmps[25];/* �߼�Regen�����µ�����Ť������ʱ��б������MAP��Z��(Ϊ�˽�����������,��λΪNm/100ms) */
extern CAL_TQM uint8_T u1_CT_TQF_HighRegenModRegenTqDecZRat_Nmps[25];/* �߼�Regen�����µ������ƶ�Ť�ؼ�Сʱ��б������MAP��Z��(Ϊ�˽�����������,��λΪNm/100ms) */
extern CAL_TQM uint8_T u1_CT_TQF_HighRegenModRegenTqIncZRat_Nmps[25];/* �߼�egen�����µ������ƶ�Ť������ʱ��б������MAP��Z��(Ϊ�˽�����������,��λΪNm/100ms) */
extern CAL_TQM uint8_T u1_CT_TQF_LowRegenModDriveTqDecZRat_Nmps[25];/* �ͼ�Regen�����µ�����Ť�ؼ�Сʱ��б������MAP��Z��(Ϊ�˽�����������,��λΪNm/100ms) */
extern CAL_TQM uint8_T u1_CT_TQF_LowRegenModDriveTqIncZRat_Nmps[25];/* �ͼ�Regen�����µ�����Ť������ʱ��б������MAP��Z��(Ϊ�˽�����������,��λΪNm/100ms) */
extern CAL_TQM uint8_T u1_CT_TQF_LowRegenModRegenTqDecZRat_Nmps[25];/* �ͼ�Regen�����µ������ƶ�Ť�ؼ�Сʱ��б������MAP��Z��(Ϊ�˽�����������,��λΪNm/100ms) */
extern CAL_TQM uint8_T u1_CT_TQF_LowRegenModRegenTqIncZRat_Nmps[25];/* �ͼ�egen�����µ������ƶ�Ť������ʱ��б������MAP��Z��(Ϊ�˽�����������,��λΪNm/100ms) */
extern CAL_TQM uint8_T u1_CT_TQF_NedcModDriveTqDecZRat_Nmps[25];/* NEDC�����µ�����Ť�ؼ�Сʱ��б������MAP��Z��(Ϊ�˽�����������,��λΪNm/100ms) */
extern CAL_TQM uint8_T u1_CT_TQF_NedcModDriveTqIncZRat_Nmps[25];/* NEDC�����µ�����Ť������ʱ��б������MAP��Z��(Ϊ�˽�����������,��λΪNm/100ms) */
extern CAL_TQM uint8_T u1_CT_TQF_NedcModRegenTqDecZRat_Nmps[25];/* NEDC�����µ������ƶ�Ť�ؼ�Сʱ��б������MAP��Z��(Ϊ�˽�����������,��λΪNm/100ms) */
extern CAL_TQM uint8_T u1_CT_TQF_NedcModRegenTqIncZRat_Nmps[25];/* NEDC�����µ������ƶ�Ť������ʱ��б������MAP��Z��(Ϊ�˽�����������,��λΪNm/100ms) */
extern CAL_TQM uint8_T u1_C_Booster_En;
extern CAL_TQM uint8_T u1_C_ESC_ESP_En;/* 0:��ABS 1��ABS 2:ESP */
extern CAL_TQM boolean_T u1_C_ESC_EscEnableFlg;/* ESCʹ�ܿ���(0:�رա�1������) */
extern CAL_TQM uint8_T u1_C_ESC_EscIncEnaFlg;/* ESC��Ťʹ�ܿ���(0:�رա�1������) */
extern CAL_TQM boolean_T u1_C_HDC_En;  /* HDC����������ʹ�� */
extern CAL_TQM uint8_T u1_C_TQF_AbsModDriveTqDecRat_Nmps;/* ABS������Ĭ��ֵ */
extern CAL_TQM uint8_T u1_C_TQF_AbsModDriveTqIncRat_Nmps;/* ABS������Ĭ��ֵ */
extern CAL_TQM uint8_T u1_C_TQF_DefModGearPNRat_Nmps;/* Deafult������P/N��Ť��ж��б������(Ϊ�˽�����������,��λΪNm/100ms) */
extern CAL_TQM uint8_T u1_C_TQF_DefModSteadyDecRat_Nmps;/* Deafult������Ť���½�Ĭ��б�ʡ���Ť�ش�����̬(Ϊ�˽�����������,��λΪNm/100ms) */
extern CAL_TQM uint8_T u1_C_TQF_DefModSteadyIncRat_Nmps;/* Deafult������Ť������Ĭ��б�ʡ���Ť�ش�����̬(Ϊ�˽�����������,��λΪNm/100ms) */
extern CAL_TQM boolean_T u1_C_TQF_UseFilterRateNewArch;/* �Ƿ�ʹ�þ�ϸ��Ť���˲���1����ʾʹ�þ�ϸ��Ť���˲��� */
extern CAL_TQM real32_T u1_C_TQM_MCUTqMaxFactor;/* MCU��Ťϵ����ֵ(0.9-������) */
extern CAL_TQM int16_T u2_CT_TQF_AbsModRegenTqDecXOldTq_Nm[5];/* Creep�����µ������ƶ�Ť�ؼ�Сʱ��б������MAP��X��(ǰ�����Ť�صľ���ֵ) */
extern CAL_TQM int16_T u2_CT_TQF_AbsModRegenTqDecYTqDiff_Nm[5];/* Creep�����µ������ƶ�Ť�ؼ�Сʱ��б������MAP��Y��((�������Ť�� - ǰ�����Ť��ֵ)�ľ���ֵ) */
extern CAL_TQM int16_T u2_CT_TQF_AccPdlModEcoDriveTqDecXOldTq_Nm[5];/* AccelPedal������ECOģʽ������Ť�ؼ�Сʱ��б������MAP��X��(ǰ�����Ť�صľ���ֵ) */
extern CAL_TQM int16_T u2_CT_TQF_AccPdlModEcoDriveTqDecYTqDiff_Nm[5];/* AccelPedal������ECOģʽ������Ť�ؼ�Сʱ��б������MAP��Y��((�������Ť�� - ǰ�����Ť��ֵ)�ľ���ֵ) */
extern CAL_TQM int16_T u2_CT_TQF_AccPdlModEcoDriveTqIncXOldTq_Nm[5];/* AccelPedal������ECOģʽ������Ť������ʱ��б������MAP��X��(ǰ�����Ť�صľ���ֵ) */
extern CAL_TQM int16_T u2_CT_TQF_AccPdlModEcoDriveTqIncYTqDiff_Nm[5];/* AccelPedal������ECOģʽ������Ť������ʱ��б������MAP��Y��((�������Ť�� - ǰ�����Ť��ֵ)�ľ���ֵ) */
extern CAL_TQM int16_T u2_CT_TQF_AccPdlModEcoRegenTqDecXOldTq_Nm[5];/* AccelPedal������ECOģʽ�������ƶ�Ť�ؼ�Сʱ��б������MAP��X��(ǰ�����Ť�صľ���ֵ) */
extern CAL_TQM int16_T u2_CT_TQF_AccPdlModEcoRegenTqDecYTqDiff_Nm[5];/* AccelPedal������ECOģʽ�������ƶ�Ť�ؼ�Сʱ��б������MAP��Y��((�������Ť�� - ǰ�����Ť��ֵ)�ľ���ֵ) */
extern CAL_TQM int16_T u2_CT_TQF_AccPdlModEcoRegenTqIncXOldTq_Nm[5];/* AccelPedal������ECOģʽ�������ƶ�Ť������ʱ��б������MAP��X��(ǰ�����Ť�صľ���ֵ) */
extern CAL_TQM int16_T u2_CT_TQF_AccPdlModEcoRegenTqIncYTqDiff_Nm[5];/* AccelPedal������ECOģʽ�������ƶ�Ť������ʱ��б������MAP��Y��((�������Ť�� - ǰ�����Ť��ֵ)�ľ���ֵ) */
extern CAL_TQM int16_T u2_CT_TQF_AccPdlModSportDriveTqDecXOldTq_Nm[5];/* AccelPedal������SPORTģʽ������Ť�ؼ�Сʱ��б������MAP��X��(ǰ�����Ť�صľ���ֵ) */
extern CAL_TQM int16_T u2_CT_TQF_AccPdlModSportDriveTqDecYTqDiff_Nm[5];/* AccelPedal������SPORTģʽ������Ť�ؼ�Сʱ��б������MAP��Y��((�������Ť�� - ǰ�����Ť��ֵ)�ľ���ֵ) */
extern CAL_TQM int16_T u2_CT_TQF_AccPdlModSportDriveTqIncXOldTq_Nm[5];/* AccelPedal������SPORTģʽ������Ť������ʱ��б������MAP��X��(ǰ�����Ť�صľ���ֵ) */
extern CAL_TQM int16_T u2_CT_TQF_AccPdlModSportDriveTqIncYTqDiff_Nm[5];/* AccelPedal������SPORTģʽ������Ť������ʱ��б������MAP��Y��((�������Ť�� - ǰ�����Ť��ֵ)�ľ���ֵ) */
extern CAL_TQM int16_T u2_CT_TQF_AccPdlModSportRegenTqDecXOldTq_Nm[5];/* AccelPedal������SPORTģʽ�������ƶ�Ť�ؼ�Сʱ��б������MAP��X��(ǰ�����Ť�صľ���ֵ) */
extern CAL_TQM int16_T u2_CT_TQF_AccPdlModSportRegenTqDecYTqDiff_Nm[5];/* AccelPedal������SPORTģʽ�������ƶ�Ť�ؼ�Сʱ��б������MAP��Y��((�������Ť�� - ǰ�����Ť��ֵ)�ľ���ֵ) */
extern CAL_TQM int16_T u2_CT_TQF_AccPdlModSportRegenTqIncXOldTq_Nm[5];/* AccelPedal������SPORTģʽ�������ƶ�Ť������ʱ��б������MAP��X��(ǰ�����Ť�صľ���ֵ) */
extern CAL_TQM int16_T u2_CT_TQF_AccPdlModSportRegenTqIncYTqDiff_Nm[5];/* AccelPedal������SPORTģʽ�������ƶ�Ť������ʱ��б������MAP��Y��((�������Ť�� - ǰ�����Ť��ֵ)�ľ���ֵ) */
extern CAL_TQM int16_T u2_CT_TQF_CreepModDriveTqDecXOldTq_Nm[5];/* Creep�����µ�����Ť�ؼ�Сʱ��б������MAP��X��(ǰ�����Ť�صľ���ֵ) */
extern CAL_TQM int16_T u2_CT_TQF_CreepModDriveTqDecYTqDiff_Nm[5];/* Creep�����µ�����Ť�ؼ�Сʱ��б������MAP��Y��((�������Ť�� - ǰ�����Ť��ֵ)�ľ���ֵ) */
extern CAL_TQM int16_T u2_CT_TQF_CreepModDriveTqIncXOldTq_Nm[5];/* Creep�����µ�����Ť������ʱ��б������MAP��X��(ǰ�����Ť�صľ���ֵ) */
extern CAL_TQM int16_T u2_CT_TQF_CreepModDriveTqIncYTqDiff_Nm[5];/* Creep�����µ�����Ť������ʱ��б������MAP��Y��((�������Ť�� - ǰ�����Ť��ֵ)�ľ���ֵ) */
extern CAL_TQM int16_T u2_CT_TQF_CreepModRegenTqDecXOldTq_Nm[5];/* Creep�����µ������ƶ�Ť�ؼ�Сʱ��б������MAP��X��(ǰ�����Ť�صľ���ֵ) */
extern CAL_TQM int16_T u2_CT_TQF_CreepModRegenTqDecYTqDiff_Nm[5];/* Creep�����µ������ƶ�Ť�ؼ�Сʱ��б������MAP��Y��((�������Ť�� - ǰ�����Ť��ֵ)�ľ���ֵ) */
extern CAL_TQM int16_T u2_CT_TQF_CreepModRegenTqIncXOldTq_Nm[5];/* Creep�����µ������ƶ�Ť������ʱ��б������MAP��X��(ǰ�����Ť�صľ���ֵ) */
extern CAL_TQM int16_T u2_CT_TQF_CreepModRegenTqIncYTqDiff_Nm[5];/* Creep�����µ������ƶ�Ť������ʱ��б������MAP��Y��((�������Ť�� - ǰ�����Ť��ֵ)�ľ���ֵ) */
extern CAL_TQM int16_T u2_CT_TQF_HDCModDriveTqDecXOldTq_Nm[5];/* HDC�����µ�����Ť�ؼ�Сʱ��б������MAP��X��(ǰ�����Ť�صľ���ֵ) */
extern CAL_TQM int16_T u2_CT_TQF_HDCModDriveTqDecYTqDiff_Nm[5];/* HDC�����µ�����Ť�ؼ�Сʱ��б������MAP��Y��((�������Ť�� - ǰ�����Ť��ֵ)�ľ���ֵ) */
extern CAL_TQM int16_T u2_CT_TQF_HDCModDriveTqIncXOldTq_Nm[5];/* HDC�����µ�����Ť������ʱ��б������MAP��X��(ǰ�����Ť�صľ���ֵ) */
extern CAL_TQM int16_T u2_CT_TQF_HDCModDriveTqIncYTqDiff_Nm[5];/* HDC�����µ�����Ť������ʱ��б������MAP��Y��((�������Ť�� - ǰ�����Ť��ֵ)�ľ���ֵ) */
extern CAL_TQM int16_T u2_CT_TQF_HDCModRegenTqDecXOldTq_Nm[5];/* HDC�����µ������ƶ�Ť�ؼ�Сʱ��б������MAP��X��(ǰ�����Ť�صľ���ֵ) */
extern CAL_TQM int16_T u2_CT_TQF_HDCModRegenTqDecYTqDiff_Nm[5];/* HDC�����µ������ƶ�Ť�ؼ�Сʱ��б������MAP��Y��((�������Ť�� - ǰ�����Ť��ֵ)�ľ���ֵ) */
extern CAL_TQM int16_T u2_CT_TQF_HDCModRegenTqIncXOldTq_Nm[5];/* HDC�����µ������ƶ�Ť������ʱ��б������MAP��X��(ǰ�����Ť�صľ���ֵ) */
extern CAL_TQM int16_T u2_CT_TQF_HDCModRegenTqIncYTqDiff_Nm[5];/* HDC�����µ������ƶ�Ť������ʱ��б������MAP��Y��((�������Ť�� - ǰ�����Ť��ֵ)�ľ���ֵ) */
extern CAL_TQM int16_T u2_CT_TQF_NedcModDriveTqDecXOldTq_Nm[5];/* NEDC�����µ�����Ť�ؼ�Сʱ��б������MAP��X��(ǰ�����Ť�صľ���ֵ) */
extern CAL_TQM int16_T u2_CT_TQF_NedcModDriveTqDecYTqDiff_Nm[5];/* NEDC�����µ�����Ť�ؼ�Сʱ��б������MAP��Y��((�������Ť�� - ǰ�����Ť��ֵ)�ľ���ֵ) */
extern CAL_TQM int16_T u2_CT_TQF_NedcModDriveTqIncXOldTq_Nm[5];/* NEDC�����µ�����Ť������ʱ��б������MAP��X��(ǰ�����Ť�صľ���ֵ) */
extern CAL_TQM int16_T u2_CT_TQF_NedcModDriveTqIncYTqDiff_Nm[5];/* NEDC�����µ�����Ť������ʱ��б������MAP��Y��((�������Ť�� - ǰ�����Ť��ֵ)�ľ���ֵ) */
extern CAL_TQM int16_T u2_CT_TQF_NedcModRegenTqDecXOldTq_Nm[5];/* NEDC�����µ������ƶ�Ť�ؼ�Сʱ��б������MAP��X��(ǰ�����Ť�صľ���ֵ) */
extern CAL_TQM int16_T u2_CT_TQF_NedcModRegenTqDecYTqDiff_Nm[5];/* NEDC�����µ������ƶ�Ť�ؼ�Сʱ��б������MAP��Y��((�������Ť�� - ǰ�����Ť��ֵ)�ľ���ֵ) */
extern CAL_TQM int16_T u2_CT_TQF_NedcModRegenTqIncXOldTq_Nm[5];/* NEDC�����µ������ƶ�Ť������ʱ��б������MAP��X��(ǰ�����Ť�صľ���ֵ) */
extern CAL_TQM int16_T u2_CT_TQF_NedcModRegenTqIncYTqDiff_Nm[5];/* NEDC�����µ������ƶ�Ť������ʱ��б������MAP��Y��((�������Ť�� - ǰ�����Ť��ֵ)�ľ���ֵ) */
extern CAL_TQM int16_T u2_CT_TQF_RegenModDriveTqDecXOldTq_Nm[5];/* Regen�����µ�����Ť�ؼ�Сʱ��б������MAP��X��(ǰ�����Ť�صľ���ֵ) */
extern CAL_TQM int16_T u2_CT_TQF_RegenModDriveTqDecYTqDiff_Nm[5];/* Regen�����µ�����Ť�ؼ�Сʱ��б������MAP��Y��((�������Ť�� - ǰ�����Ť��ֵ)�ľ���ֵ) */
extern CAL_TQM int16_T u2_CT_TQF_RegenModDriveTqIncXOldTq_Nm[5];/* Regen�����µ�����Ť������ʱ��б������MAP��X��(ǰ�����Ť�صľ���ֵ) */
extern CAL_TQM int16_T u2_CT_TQF_RegenModDriveTqIncYTqDiff_Nm[5];/* Regen�����µ�����Ť������ʱ��б������MAP��Y��((�������Ť�� - ǰ�����Ť��ֵ)�ľ���ֵ) */
extern CAL_TQM int16_T u2_CT_TQF_RegenModRegenTqDecXOldTq_Nm[5];/* Regen�����µ������ƶ�Ť�ؼ�Сʱ��б������MAP��X��(ǰ�����Ť�صľ���ֵ) */
extern CAL_TQM int16_T u2_CT_TQF_RegenModRegenTqDecYTqDiff_Nm[5];/* Regen�����µ������ƶ�Ť�ؼ�Сʱ��б������MAP��Y��((�������Ť�� - ǰ�����Ť��ֵ)�ľ���ֵ) */
extern CAL_TQM int16_T u2_CT_TQF_RegenModRegenTqIncXOldTq_Nm[5];/* Regen�����µ������ƶ�Ť������ʱ��б������MAP��X��(ǰ�����Ť�صľ���ֵ) */
extern CAL_TQM int16_T u2_CT_TQF_RegenModRegenTqIncYTqDiff_Nm[5];/* Regen�����µ������ƶ�Ť������ʱ��б������MAP��Y��((�������Ť�� - ǰ�����Ť��ֵ)�ľ���ֵ) */
extern CAL_TQM real32_T u2_C_ASM_DecMotTq_Step;/* MCU����Ť���˳����� */
extern CAL_TQM real32_T u2_C_ASM_MinTq;/* MCU����Ť���˳���Сֵ */
extern CAL_TQM uint16_T u2_C_GearBoxDelayTime;/* �ֶ������͵�λȷ��������ֵ */
extern CAL_TQM uint16_T u2_C_TQM_MCUTqDiffDlyTime;/* ����Ť����ʵ��Ť�صĲ�ֵ�ж�ʱ����ֵ */
extern CAL_TQM uint16_T u2_C_VSP_ActAclLowPassFilter_ms;/* ���ٶ�һ���˲�ϵ�� */
extern CAL_TQM int16_T up_inc_limit;   /* б�����Ʋ���Ť������ֵ */

#endif                                 /* RTW_HEADER_TQM_Cal_Data_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

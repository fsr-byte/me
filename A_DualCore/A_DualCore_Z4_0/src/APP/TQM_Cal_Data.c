/*
 * File: TQM_Cal_Data.c
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

#include "rtwtypes.h"
#include "TQM_model_types.h"

/* Exported data definition */
#include "derivative.h"

/* Definition for custom storage class: CAL_9_TQM */
CAL_TQM real32_T ABS_FR_DeltaCurveHalfAxle = 0.2F;/* ���������ٲ� */
CAL_TQM boolean_T ABS_WheelSpd_Enable = 0;/* �Ƿ�ͨ��ABS�������㳵�� */
CAL_TQM real32_T ABS_vWhlRL_Revise = 0.0F;/* ͨ��ǰһ�ֵĳ������ƲⱾ�ֳ���ʱ�������� */
CAL_TQM uint16_T ASM_EPB_AntiSlide_Timer = 200U;/* MCU���л�EPB���¶��ж��ӳ�counter */
CAL_TQM int16_T ASM_EPB_Applied_DelayTime = 200;/* �ж�EPB��פ��ʱcounter��������ֹͣ��פ���� */
CAL_TQM boolean_T ASM_EPB_BrakeSta_En = 0;/* EPB�����½����������ƶ�����ʹ�ܱ�ʶ */
CAL_TQM uint16_T ASM_En_AntiSlide_Spd_Delay = 300U;/* EPB���ﳵ����Ч���ж�ʱ�� */
CAL_TQM int8_T ASM_GearD_Over_Tq = 5;  /* D��������Ť�ش��ڷ�����Ť�س�����ֵ����Ϊ����Ť��ȷʵ���ڷ�����Ť�� */
CAL_TQM uint16_T ASM_GearD_Tq_Upper_Delay = 40U;/* ����Ť�ش��ڷ���Ť�صĳ���ʱ����ڸ�ֵ���˳����﹦�ܣ�D���� */
CAL_TQM int8_T ASM_GearR_Over_Tq = -5; /* R��������Ť�أ�����ֵ�����ڷ�����Ť�أ�����ֵ��������ֵ����Ϊ����Ť�ش��ڷ�����Ť�� */
CAL_TQM uint16_T ASM_GearR_Tq_Upper_Delay = 40U;/* ����Ť�ش��ڷ���Ť�صĳ���ʱ����ڸ�ֵ���˳����﹦�ܣ�R���� */
CAL_TQM int16_T ASM_MCUAntiSlide_AvTq_Max = 180;/* ����MCU�������������Ť�� */
CAL_TQM int16_T ASM_MCUAntiSlide_AvTq_Min = -180;/* ����MCU�������С������Ť�� */
CAL_TQM boolean_T ASM_MCUAntiSlide_Ena = 0;/* ת�ٻ�������ʹ�ܿ��� */
CAL_TQM boolean_T ASM_MCUAntiSlide_Val = 0;/* ת�ٻ�������ʹ��ֵ */
CAL_TQM int16_T ASM_MCU_GearDAntiSlide_Spd_En = -5;/* D��MCU�������ھ�ֹ�ж�ת�� */
CAL_TQM int8_T ASM_MCU_GearD_Lower_RoadAngle = -128;/* D�������½����¶�����������ֵ */
CAL_TQM int16_T ASM_MCU_GearRAntiSlide_Spd_En = 5;/* R��MCU�������ھ�ֹ�ж�ת�� */
CAL_TQM int8_T ASM_MCU_GearR_Upper_RoadAngle = 127;/* R�������½����¶�����������ֵ */
CAL_TQM uint16_T ASM_MCU_QuitApplied_DelayTime = 20U;/* EPB������MCUʹ�ܵȴ�����counter */
CAL_TQM uint16_T ASM_S11_AntiSlideEnter_DrivePower = 64U;/* ���÷ŵ繦�ʴ��ڸ�ֵ�����������¹��� */
CAL_TQM int32_T ASM_S11_AntiSlideEnter_RoadAngle = 5120;/* ���ת��С�ڸ�ֵ��Ϊ�������ھ�ֹ״̬�������¶��жϣ� */
CAL_TQM uint16_T ASM_S11_AntiSlideQuit_DrivePower = 48U;/* S11�����¹���ģʽ�ж��¶�ֵ */
CAL_TQM uint32_T ASM_S11_AntiSlide_ConfirmTime = 240000U;/* δ���ƶ�ʱ�������³���ʱ����ڸ�ֵ���˳������¹��� */
CAL_TQM int16_T ASM_S11_AntiSlide_ForwardSpd_Uena = 300;/* ���ת�ٴ��ڸ�ֵ��Ϊ�������ڿ�����ʻ״̬����ʱҪ���˳������� */
CAL_TQM int16_T ASM_S11_AntiSlide_ReverseSpd_Uena = -300;/* ���ת��С�ڸ�ֵ��Ϊ�������ڿ��ٺ���״̬����ʱҪ���˳������� */
CAL_TQM int16_T ASM_S11_AntiSlide_Spd_Static = 10;/* ���ת��С�ڸ�ֵ��Ϊ�������ھ�ֹ״̬��D���� */
CAL_TQM boolean_T ASM_S11_AveMotSpdFilter_En = 0;/* �����³����ж�ģ�鳵���˲�ʹ�ܱ�־ */
CAL_TQM uint16_T ASM_S11_EPBConfirm_TrueDelay = 500U;/* MCU�������ڼ�EPB��פ��ʱ�ж�ʱ�� */
CAL_TQM int16_T ASM_S11_EPB_AntiSlide_ForwardSpd = 10;/* EPB�������������ǰ�����ٷ�ֵ */
CAL_TQM int16_T ASM_S11_EPB_AntiSlide_ReverseSpd = -10;/* EPB����������������˳��ٷ�ֵ */
CAL_TQM uint16_T ASM_S11_GearD_Delay = 500U;/* ͣ����D���ĳ���ʱ����ڸ�ֵ�������������¹��ܣ�D���� */
CAL_TQM uint16_T ASM_S11_GearD_Spd_Slide_Delay = 40U;/* �������뻺������״̬�ĳ���ʱ����ڸ�ֵ����Ϊ����ȷʵ���ڻ�������״̬��D���� */
CAL_TQM int16_T ASM_S11_GearD_Spd_Slide_Hig = -5;/* ���ת��С�ڸ�ֵ��Ϊ�������ڻ�������״̬��D���� */
CAL_TQM int16_T ASM_S11_GearD_Spd_Slide_Low = -200;/* ���ת�ٴ��ڸ�ֵ��Ϊ�������ڻ�������״̬��D���� */
CAL_TQM uint16_T ASM_S11_GearR_Delay = 500U;/* ͣ����R���ĳ���ʱ����ڸ�ֵ�������������¹��ܣ�R���� */
CAL_TQM uint16_T ASM_S11_GearR_Spd_Slide_Delay = 40U;/* �������뻺������״̬�ĳ���ʱ����ڸ�ֵ����Ϊ����ȷʵ���ڻ�������״̬��R���� */
CAL_TQM int16_T ASM_S11_GearR_Spd_Slide_Hig = 200;/* ���ת��С�ڸ�ֵ��Ϊ�������ڻ�������״̬��R���� */
CAL_TQM int16_T ASM_S11_GearR_Spd_Slide_Low = 5;/* ���ת�ٴ��ڸ�ֵ��Ϊ�������ڻ�������״̬��R���� */
CAL_TQM uint16_T ASM_S11_MCU_Spd_Static_TrueDelay = 60U;/* �����б�Ϊ��ֹ״̬����С������ֹʱ�� */
CAL_TQM uint16_T ASM_S11_MCU_Spd_Static_ZeroDelay = 80U;/* �����б�Ϊ�Ǿ�ֹ״̬����С������ֹʱ�� */
CAL_TQM uint16_T ASM_S11_StaticConfirm_TrueDelay = 400U;/* �����жϳ����ȶ���ֹ�ĳ���ʱ��-���ڷ�����ʱ�ĽǶ��ж� */
CAL_TQM uint16_T ASM_Uena_AntiSlide_Spd_Delay = 200U;/* �����³��ٳ���ʱ����ʱ */
CAL_TQM uint16_T BLC_ChrgConnectConfirm_Delay = 200U;/* ��������ź�����ȷ�ϣ����ʱ����ӦEPB�ĵ����ƶ������� */
CAL_TQM uint16_T BLC_ChrgConnectQuit_Delay = 200U;/* ��������źŶϿ�ȷ�ϣ����ʱ����ӦEPB�ĵ����ƶ������� */
CAL_TQM uint8_T BLC_EPBConfirmSpd_Cal = 5U;/* EPB����ʱ�����ƶ��Ƶĳ������� */
CAL_TQM uint8_T BLC_EPBQuitSpd_Cal = 3U;/* EPB����ʱϨ���ƶ��Ƶĳ������� */
CAL_TQM int16_T BLC_GearD_LampOff_Tq = -80;/* D����������Ϩ���ƶ��ƵĻ���Ť����ֵ */
CAL_TQM int16_T BLC_GearD_LampOn_Tq = -160;/* D���������������ƶ��ƵĻ���Ť����ֵ */
CAL_TQM int16_T BLC_GearR_LampOff_Tq = 80;/* R����������Ϩ���ƶ��ƵĻ���Ť����ֵ */
CAL_TQM int16_T BLC_GearR_LampOn_Tq = 160;/* R���������������ƶ��ƵĻ���Ť����ֵ */
CAL_TQM boolean_T Cal_AccePctMode_flg = 0;/* �ֶ����������������������̤��ģʽѡ�񿪹� */
CAL_TQM uint16_T Cal_ClutchSysEnable_TrueDelay = 50U;/* �ֶ������������ʹ��ȷ��ʱ�� */
CAL_TQM uint16_T Cal_ClutchSysEnable_ZeroDelay = 50U;/* �ֶ�������������ͷ�ȷ��ʱ�� */
CAL_TQM real32_T Cal_Clutchlinkage_Threshold = 10.0F;/* �ֶ����������������������̤�������ֵ */
CAL_TQM int16_T Cal_Creep_GearD_VehSpeed = 96;/* D������Ŀ�공�� */
CAL_TQM int16_T Cal_Creep_GearR_VehSpeed = -64;/* R������Ŀ�공�� */
CAL_TQM boolean_T Cal_Ready_En = 0;    /* �ֶ��������������λ����READY���� */
CAL_TQM boolean_T Cal_Ready_Val = 0;   /* �ֶ��������������λ����READY��ֵ */
CAL_TQM boolean_T Cal_RegenGrade_Ena = 0;/* ���л����ȼ�ǿ�ƿ��ƿ��� */
CAL_TQM uint8_T Cal_RegenGrade_Val = 0U;/* ���л����ȼ�ǿ�ƿ��Ƹ�ֵ */
CAL_TQM uint8_T Cal_pedalCoefficient = 7U;/* �ֶ����������������������̤����ȷֶ����Ӷ��� */
CAL_TQM int16_T CreepD_Spd_Forward_limit_Off = 1920;/* D�����������˳����� */
CAL_TQM int16_T CreepD_Spd_Forward_limit_On = 1664;/* D������������복�� */
CAL_TQM int16_T CreepD_Spd_Reverse_limit = -1062;/* D������������복�� */
CAL_TQM int16_T CreepR_Spd_Forward_limit = 1574;/* R������������복�� */
CAL_TQM int16_T CreepR_Spd_Reserve_limit_Off = -1280;/* R�����������˳����� */
CAL_TQM int16_T CreepR_Spd_Reserve_limit_On = -1152;/* R������������복�� */
CAL_TQM uint16_T Creep_Ki_GearD[17] =
{
    200U, 200U, 200U, 200U, 200U, 200U, 200U, 200U, 200U, 200U, 20U, 20U, 20U,
    20U, 20U, 20U, 20U
} ;                                    /* D������Ki���-Ki */

CAL_TQM uint16_T Creep_Ki_GearR[17] =
{
    200U, 200U, 200U, 200U, 200U, 200U, 200U, 200U, 200U, 200U, 20U, 20U, 20U,
    20U, 20U, 20U, 20U
} ;                                    /* R������Ki���-Ki */

CAL_TQM uint16_T Creep_Kp_GearD[17] =
{
    20U, 20U, 20U, 20U, 20U, 20U, 20U, 20U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U
} ;                                    /* D������Kp���-Kp */

CAL_TQM uint16_T Creep_Kp_GearR[17] =
{
    20U, 20U, 20U, 20U, 20U, 20U, 20U, 20U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U
} ;                                    /* R������Kp���-Kp */

CAL_TQM int16_T CrpVehSpd_DV[17] =
{
    -128, -96, -64, -48, -32, -24, -16, -8, 0, 8, 16, 24, 32, 48, 64, 96, 128
} ;                                    /* R/D������Kp/Ki���-���ٲ� */

CAL_TQM uint16_T DTD_GearD_Brake_CloseToGear_MotSpd_Ena = 1000U;/* D�����ݹ��ܿ���ת�٣����ƶ��� */
CAL_TQM uint16_T DTD_GearD_Brake_CloseToGear_MotSpd_Uena = 1200U;/* D�����ݹ��ܹر�ת�٣����ƶ��� */
CAL_TQM int8_T DTD_GearD_Brake_CloseToGear_Tq = 1;/* D������Ť�أ����ƶ�����map����Ϊ��ֵ�� */
CAL_TQM boolean_T DTD_GearD_CloseToGear_Ena = 0;/* D�����ݹ��ܿ��� */
CAL_TQM uint16_T DTD_GearD_CloseToGear_MotSpd_Ena = 1000U;/* D�����ݹ��ܿ���ת�٣�δ���ƶ��� */
CAL_TQM uint16_T DTD_GearD_CloseToGear_MotSpd_Uena = 1200U;/* D�����ݹ��ܹر�ת�٣�δ���ƶ��� */
CAL_TQM int8_T DTD_GearD_CloseToGear_Tq = 1;/* D������Ť�أ�δ���ƶ�����map����Ϊ��ֵ�� */
CAL_TQM uint16_T DTD_GearR_Brake_CloseToGear_MotSpd_Ena = 1000U;/* R�����ݹ��ܿ���ת�٣����ƶ��� */
CAL_TQM uint16_T DTD_GearR_Brake_CloseToGear_MotSpd_Uena = 1200U;/* R�����ݹ��ܹر�ת�٣����ƶ��� */
CAL_TQM int8_T DTD_GearR_Brake_CloseToGear_Tq = 1;/* R������Ť�أ����ƶ�����map����Ϊ��ֵ�� */
CAL_TQM boolean_T DTD_GearR_CloseToGear_Ena = 0;/* R�����ݹ��ܿ��� */
CAL_TQM uint16_T DTD_GearR_CloseToGear_MotSpd_Ena = 1000U;/* R�����ݹ��ܿ���ת�٣�δ���ƶ��� */
CAL_TQM uint16_T DTD_GearR_CloseToGear_MotSpd_Uena = 1200U;/* R�����ݹ��ܹر�ת�٣�δ���ƶ��� */
CAL_TQM int8_T DTD_GearR_CloseToGear_Tq = 1;/* R������Ť�أ�δ���ƶ�����map����Ϊ��ֵ�� */
CAL_TQM uint16_T ECM_EPB_Acceleration_X_Filter = 100U;
CAL_TQM uint16_T ECM_SAS_SteeringAngleSpeed_Filter = 100U;
CAL_TQM uint16_T ECM_SAS_SteeringAngle_Filter = 100U;
CAL_TQM uint8_T ENUM_MCUMODE_SpdCtl = 4U;/* ���ת�ٻ����Ʊ�־ */
CAL_TQM uint8_T ENUM_MCUMODE_TRQCTL = 5U;/* ���Ť�ػ����Ʊ�־ */
CAL_TQM uint8_T ENUM_TMMODE_MOTOR = 1U;/* ����ŵ�ģʽ��־ */
CAL_TQM uint8_T ENUM_TMMODE_REGEN = 2U;/* �������ģʽ��־ */
CAL_TQM uint8_T ENUM_TQF_DEC = 2U;     /* Ť���½���־ */
CAL_TQM uint8_T ENUM_TQF_INC = 1U;     /* Ť��������־ */
CAL_TQM uint8_T ENUM_TQF_STEADY = 0U;  /* Ť���ȶ���־ */
CAL_TQM uint16_T EPB_Delay_time = 10U; /* EPB��פ������Ч���ж�ʱ�� */
CAL_TQM uint8_T FDT_ClutchEnRegen_Spd_Off = 3U;/* �ֶ��������������ק����ʹ�ܳ��ٹر���ֵ */
CAL_TQM uint8_T FDT_ClutchEnRegen_Spd_On = 3U;/* �ֶ��������������ק����ʹ�ܳ��ٿ�����ֵ */
CAL_TQM uint8_T FDT_Crp_PID_SteadyConst = 10U;/* ����PID�����е���̬���� */
CAL_TQM int8_T FDT_GearD_BrakeRegenTq_Offset = 0;/* R���ƶ�����Ť��ƫ���� */
CAL_TQM int16_T FDT_GearD_Crp_Tqlim_Low = -800;/* D�����е���С���Ť�� */
CAL_TQM int16_T FDT_GearD_Crp_Tqlim_Up = 800;/* D�����е�������Ť�� */
CAL_TQM int8_T FDT_GearR_BrakeRegenTq_Offset = 0;/* D���ƶ�����Ť��ƫ���� */
CAL_TQM int16_T FDT_GearR_Crp_Tqlim_Low = -800;/* R�����е���С���Ť�� */
CAL_TQM int16_T FDT_GearR_Crp_Tqlim_Up = 800;/* R�����е�������Ť�� */
CAL_TQM uint8_T FDT_Regen_Spd_Off = 8U;/* �������չرն�Ӧ�ĳ������� */
CAL_TQM uint8_T FDT_Regen_Spd_On = 12U;/* �������տ�����Ӧ�ĳ������� */
CAL_TQM uint8_T Forward = 1U;          /* �����ת��־ */
CAL_TQM uint8_T GTC_GearTouch_Direction_Ena = 0U;/* ���ݷ���ʹ�ܿ��� */
CAL_TQM uint8_T GTC_GearTouch_Direction_Val = 0U;/* ���ݷ���ʹ��ֵ */
CAL_TQM boolean_T GTC_GearTouch_Ena = 0;/* Ť�ؿ��ݹ���ʹ�ܿ��� */
CAL_TQM uint8_T GTC_GearTouch_EnaSpd_Hig = 30U;/* С�ڸó�������ִ�п��� */
CAL_TQM uint8_T GTC_GearTouch_EnaSpd_Low = 8U;/* ���ڸó�������ִ�п��� */
CAL_TQM uint16_T GTC_GearTouch_NtoP_Timer1 = 20U;/* ��һ�ο���Ť�س���ʱ�䡪������Ť���ɸ����� */
CAL_TQM uint16_T GTC_GearTouch_NtoP_Timer2 = 20U;/* ǰ���ο���Ť�س���ʱ��֮�͡�������Ť���ɸ����� */
CAL_TQM uint16_T GTC_GearTouch_NtoP_Timer3 = 0U;/* ǰ���ο���Ť�س���ʱ��֮�͡�������Ť���ɸ����� */
CAL_TQM uint16_T GTC_GearTouch_NtoP_Timer4 = 0U;/* ǰ�Ķο���Ť�س���ʱ��֮�͡�������Ť���ɸ����� */
CAL_TQM real32_T GTC_GearTouch_NtoP_Tq1 = 1.0F;/* ���㿿��Ť�ص�һ�Ρ�������Ť���ɸ����� */
CAL_TQM real32_T GTC_GearTouch_NtoP_Tq2 = 1.0F;/* ���㿿��Ť�صڶ��Ρ�������Ť���ɸ����� */
CAL_TQM real32_T GTC_GearTouch_NtoP_Tq3 = 1.0F;/* ���㿿��Ť�ص����Ρ�������Ť���ɸ����� */
CAL_TQM real32_T GTC_GearTouch_NtoP_Tq4 = 1.0F;/* ���㿿��Ť�ص��ĶΡ�������Ť���ɸ����� */
CAL_TQM uint16_T GTC_GearTouch_PtoN_Timer1 = 20U;/* ��һ�ο���Ť�س���ʱ�䡪������Ť�������为 */
CAL_TQM uint16_T GTC_GearTouch_PtoN_Timer2 = 20U;/* ǰ���ο���Ť�س���ʱ��֮�͡�������Ť�������为 */
CAL_TQM uint16_T GTC_GearTouch_PtoN_Timer3 = 0U;/* ǰ���ο���Ť�س���ʱ��֮�͡�������Ť�������为 */
CAL_TQM uint16_T GTC_GearTouch_PtoN_Timer4 = 0U;/* ǰ�Ķο���Ť�س���ʱ��֮�͡�������Ť�������为 */
CAL_TQM real32_T GTC_GearTouch_PtoN_Tq1 = -1.0F;/* ���㿿��Ť�ص�һ�Ρ�������Ť�������为 */
CAL_TQM real32_T GTC_GearTouch_PtoN_Tq2 = -1.0F;/* ���㿿��Ť�صڶ��Ρ�������Ť�������为 */
CAL_TQM real32_T GTC_GearTouch_PtoN_Tq3 = -1.0F;/* ���㿿��Ť�ص����Ρ�������Ť�������为 */
CAL_TQM real32_T GTC_GearTouch_PtoN_Tq4 = -1.0F;/* ���㿿��Ť�ص��ĶΡ�������Ť�������为 */
CAL_TQM uint8_T GTC_GearTouch_UnEnaSpd_Hig = 32U;/* ���ڸó��ٽ�ֹ���� */
CAL_TQM uint8_T GTC_GearTouch_UnEnaSpd_Low = 6U;/* С�ڸó��ٽ�ֹ���� */
CAL_TQM real32_T GTC_ZeroAcross_Tq = 0.5F;/* Ť�ع����ж���ֵ */
CAL_TQM uint8_T GearD = 4U;            /* D�� */
CAL_TQM uint8_T GearD_Release = 6U;    /* N�°��г� */
CAL_TQM uint8_T GearR_Release = 5U;    /* N�ϰ��г� */
CAL_TQM uint8_T Gear_D = 4U;           /* D����־ */
CAL_TQM uint8_T Gear_D1 = 7U;          /* �ֶ�������D1�� */
CAL_TQM uint8_T Gear_D2 = 8U;          /* �ֶ�������D2�� */
CAL_TQM uint8_T Gear_D3 = 9U;          /* �ֶ�������D3�� */
CAL_TQM uint8_T Gear_D4 = 10U;         /* �ֶ�������D4�� */
CAL_TQM uint8_T Gear_D5 = 11U;         /* �ֶ�������D5�� */
CAL_TQM uint8_T Gear_N = 3U;           /* N����־ */
CAL_TQM uint8_T Gear_P = 1U;           /* P����־ */
CAL_TQM uint8_T Gear_R = 2U;           /* R����־ */
CAL_TQM uint32_T Gravitational_Accel = 642253U;/* �������ٶ� */
CAL_TQM int16_T KNEDC_AccDeltaLower_mps = -102;
CAL_TQM int16_T KNEDC_AccDeltaUpper_mps = 102;
CAL_TQM uint8_T KNEDC_BRAKETYPE_KMPH120120 = 6U;
CAL_TQM uint8_T KNEDC_BRAKETYPE_KMPH12050 = 8U;
CAL_TQM uint8_T KNEDC_BRAKETYPE_KMPH12080 = 7U;
CAL_TQM uint8_T KNEDC_BRAKETYPE_KMPH15 = 1U;
CAL_TQM uint8_T KNEDC_BRAKETYPE_KMPH32 = 2U;
CAL_TQM uint8_T KNEDC_BRAKETYPE_KMPH35 = 4U;
CAL_TQM uint8_T KNEDC_BRAKETYPE_KMPH50 = 3U;
CAL_TQM uint8_T KNEDC_BRAKETYPE_KMPH70 = 5U;
CAL_TQM int16_T KNEDC_BrakeTorqueILower_Nm = 0;
CAL_TQM int16_T KNEDC_BrakeTorqueIReset_Nm = 0;
CAL_TQM int16_T KNEDC_BrakeTorqueIStep_Nm = 1;
CAL_TQM int16_T KNEDC_BrakeTorqueIUpper_Nm = 0;
CAL_TQM uint8_T KNEDC_SpeedHyst_kmph = 3U;/* NEDC�����жϵ�������ƫ�� */
CAL_TQM int16_T KNEDC_kmph120120Acc_mps = -707;
CAL_TQM int16_T KNEDC_kmph12050Acc_mps = -1423;
CAL_TQM int16_T KNEDC_kmph12080Acc_mps = -1065;
CAL_TQM uint16_T KNEDC_kmph120HoldTime_s = 3000U;/* �б����NEDC����120kph�ȶ����������120kph��Сά��ʱ�� */
CAL_TQM uint8_T KNEDC_kmph120_kmph = 120U;/* 120kph���ٱ�־ */
CAL_TQM int16_T KNEDC_kmph15Acc_mps = -850;
CAL_TQM uint16_T KNEDC_kmph15HoldTime_s = 3000U;/* �б����NEDC����15kph�ȶ����������15kph��Сά��ʱ�� */
CAL_TQM uint8_T KNEDC_kmph15_kmph = 15U;/* 15kph���ٱ�־ */
CAL_TQM int16_T KNEDC_kmph32Acc_mps = -829;
CAL_TQM uint16_T KNEDC_kmph32HoldTime_s = 3000U;/* �б����NEDC����32kph�ȶ����������32kph��Сά��ʱ�� */
CAL_TQM uint8_T KNEDC_kmph32_kmph = 32U;/* 32kph���ٱ�־ */
CAL_TQM int16_T KNEDC_kmph35Acc_mps = -993;
CAL_TQM uint16_T KNEDC_kmph35HoldTime_s = 3000U;/* �б����NEDC����35kph�ȶ���������35kph��Сά��ʱ�� */
CAL_TQM uint8_T KNEDC_kmph35_kmph = 35U;/* 35kph���ٱ�־ */
CAL_TQM int16_T KNEDC_kmph50Acc_mps = -532;
CAL_TQM uint16_T KNEDC_kmph50HoldTime_s = 3000U;/* �б����NEDC����50kph�ȶ����������50kph��Сά��ʱ�� */
CAL_TQM uint8_T KNEDC_kmph50_kmph = 50U;/* 50kph���ٱ�־ */
CAL_TQM int16_T KNEDC_kmph70Acc_mps = -707;
CAL_TQM uint16_T KNEDC_kmph70HoldTime_s = 3000U;/* �б����NEDC����70kph�ȶ����������70kph��Сά��ʱ�� */
CAL_TQM uint8_T KNEDC_kmph70_kmph = 70U;/* 70kph���ٱ�־ */
CAL_TQM uint8_T KNEDC_kmph80_kmph = 80U;/* 80kph���ٱ�־ */
CAL_TQM boolean_T KTQD_NEDCBakeEn_flg = 0;/* NEDC����ʹ�� */
CAL_TQM uint16_T KTQD_NEDCBrakeMotorSpeedMin_rpm = 100U;/* NEDC�������չ��ܽ����ת������ */
CAL_TQM uint16_T KTQF_GearPN_Rate_Nmps = 400U;/* P/N��Ť��ж��б������ */
CAL_TQM uint16_T KTQF_RTDefaultDEC_Nmps = 100U;/* Ť���½�Ĭ��б�ʡ���Ť�ش�����̬ */
CAL_TQM uint16_T KTQF_RTDefaultINC_Nmps = 100U;/* Ť������Ĭ��б�ʡ���Ť�ش�����̬ */
CAL_TQM int8_T KTQF_TMDecRatStepFactor = -50;/* Ť���½�б�ʵ������� */
CAL_TQM uint8_T KTQF_TMDecRatStepFilterFactor = 100U;/* Ť���½�б���˲����� */
CAL_TQM int8_T KTQF_TMIncRatStepFactor = 50;/* Ť������б�ʵ������� */
CAL_TQM uint8_T KTQF_TMIncRatStepFilterFactor = 50U;/* Ť������б���˲����� */
CAL_TQM uint16_T KTQF_TqClunkRateLimitDec_Nmps = 50U;/* Ť�ع�����½�б������ */
CAL_TQM uint16_T KTQF_TqClunkRateLimitInc_Nmps = 50U;/* Ť�ع��������б������ */
CAL_TQM uint8_T KTQF_TqClunkThresholdDecHigh_Nm = 0U;/* Ť���½�������б�����ֵ */
CAL_TQM int8_T KTQF_TqClunkThresholdDecLow_Nm = 0;/* Ť���½�������б�����ֵ */
CAL_TQM uint8_T KTQF_TqClunkThresholdIncHigh_Nm = 0U;/* Ť������������б�����ֵ */
CAL_TQM int8_T KTQF_TqClunkThresholdIncLow_Nm = 0;/* Ť������������б�����ֵ */
CAL_TQM int32_T KTQF_TqPrecisionLimit_Nm = 10;/* �����ж�Ť���������ȶ��½�״̬����СŤ������ */
CAL_TQM uint16_T MAM_K11_MCUAntiSlidePowerEna_rpm = 80U;/* K11���÷ŵ繦�ʴ��ڸ�ֵ��ɿ��������¹��� */
CAL_TQM uint16_T MAM_K11_MCUAntiSlidePowerForbid_rpm = 48U;/* K11���÷ŵ繦�ʴ��ڸ�ֵ���˳������¹��� */
CAL_TQM int16_T MAM_K11_MCUAntiSlideSpdEna_rpm = 15;/* K11�����¹��ܿ���ת�� */
CAL_TQM int16_T MAM_K11_MCUAntiSlideSpdForbid_rpm = 180;/* K11�����¹����˳�ת�� */
CAL_TQM uint16_T MAS_DisAntishake_Delay = 20U;/* MCU�������ܹر���ʱ */
CAL_TQM uint16_T MAS_EnaAntishake_Delay = 100U;/* MCU�������ܿ�����ʱ */
CAL_TQM uint16_T MNEDC_kmph120120Brake_X_kmph[15] =
{
    0U, 80U, 160U, 320U, 480U, 640U, 800U, 960U, 1120U, 1280U, 1312U, 1600U,
    1760U, 1920U, 2080U
} ;                                    /* NEDC����120kph����Ť��map-���� */

CAL_TQM int16_T MNEDC_kmph120120Brake_Z_Nm[15] =
{
    0, 0, -480, -480, -480, -480, -480, -480, -480, -240, -272, -256, -240, -32,
    -480
} ;                                    /* NEDC����120kph����Ť��map-Ť�� */

CAL_TQM uint16_T MNEDC_kmph15Brake_X_kmph[15] =
{
    0U, 16U, 32U, 240U, 320U, 640U, 800U, 960U, 1120U, 1280U, 1440U, 1600U,
    1760U, 1920U, 2080U
} ;                                    /* NEDC����15kph����Ť��map-���� */

CAL_TQM int16_T MNEDC_kmph15Brake_Z_Nm[15] =
{
    0, -16, -736, -736, -720, -720, -720, -640, -608, -592, -640, -640, -640,
    -640, -480
} ;                                    /* NEDC����15kph����Ť��map-Ť�� */

CAL_TQM uint16_T MNEDC_kmph32Brake_X_kmph[15] =
{
    0U, 16U, 32U, 320U, 512U, 640U, 800U, 960U, 1120U, 1280U, 1440U, 1600U,
    1760U, 1920U, 2080U
} ;                                    /* NEDC����32kph����Ť��map-���� */

CAL_TQM int16_T MNEDC_kmph32Brake_Z_Nm[15] =
{
    0, -16, -752, -752, -736, -688, -480, -480, -480, -480, -480, -480, -480,
    -480, -480
} ;                                    /* NEDC����32kph����Ť��map-Ť�� */

CAL_TQM uint16_T MNEDC_kmph35Brake_X_kmph[15] =
{
    0U, 16U, 32U, 320U, 480U, 560U, 640U, 960U, 1120U, 1280U, 1440U, 1600U,
    1760U, 1920U, 2080U
} ;                                    /* NEDC����35kph����Ť��map-���� */

CAL_TQM int16_T MNEDC_kmph35Brake_Z_Nm[15] =
{
    0, -16, -800, -800, -800, -816, -880, -640, -608, -592, -640, -640, -640,
    -640, -480
} ;                                    /* NEDC����35kph����Ť��map-Ť�� */

CAL_TQM uint16_T MNEDC_kmph50Brake_X_kmph[15] =
{
    0U, 80U, 160U, 544U, 560U, 592U, 640U, 800U, 960U, 1280U, 1440U, 1600U,
    1760U, 1920U, 2080U
} ;                                    /* NEDC����50kph����Ť��map-���� */

CAL_TQM int16_T MNEDC_kmph50Brake_Z_Nm[15] =
{
    0, 0, -480, -480, -272, -272, -272, -256, -320, -480, -480, -480, -480, -480,
    -480
} ;                                    /* NEDC����50kph����Ť��map-Ť�� */

CAL_TQM uint16_T MNEDC_kmph70Brake_X_kmph[15] =
{
    0U, 80U, 160U, 320U, 480U, 640U, 800U, 832U, 1120U, 1280U, 1440U, 1600U,
    1760U, 1920U, 2080U
} ;                                    /* NEDC����70kph����Ť��map-���� */

CAL_TQM int16_T MNEDC_kmph70Brake_Z_Nm[15] =
{
    0, 0, -240, -672, -800, -864, -464, -464, -464, -480, -640, -640, -640, -640,
    -480
} ;                                    /* NEDC����70kph����Ť��map-Ť�� */

CAL_TQM int16_T MTQD_GearD_BrakeRegen_Zero_Tq[19] =
{
    0, 0, -5, -10, -25, -24, -23, -22, -21, -20, -19, -17, -15, -10, -5, 0, 0, 0,
    0
} ;                                    /* D���ƶ���������Ť��map-Ť�أ��㵲���գ� */

CAL_TQM int16_T MTQD_GearD_CoastRegen_First_Tq[19] =
{
    0, 0, -4, -7, -12, -17, -22, -27, -32, -32, -32, -27, -22, -17, -12, -7, 0,
    0, 0
} ;                                    /* D��������������Ť��map-Ť�أ�һ�����գ� */

CAL_TQM int16_T MTQD_GearD_CoastRegen_Fourth_Tq[19] =
{
    0, 0, -16, -32, -42, -52, -62, -62, -62, -62, -62, -57, -52, -42, -32, -27,
    -22, 0, 0
} ;                                    /* D��������������Ť��map-Ť�أ��ĵ����գ� */

CAL_TQM int16_T MTQD_GearD_CoastRegen_Second_Tq[19] =
{
    0, 0, -11, -22, -32, -37, -42, -42, -42, -42, -42, -42, -42, -32, -22, -12,
    0, 0, 0
} ;                                    /* D��������������Ť��map-Ť�أ��������գ� */

CAL_TQM uint16_T MTQD_GearD_CoastRegen_Spd[19] =
{
    0U, 520U, 780U, 975U, 1300U, 1950U, 2600U, 3250U, 3900U, 4550U, 5200U, 5850U,
    6500U, 7150U, 7800U, 8450U, 9100U, 9425U, 9750U
} ;                                    /* D��������������Ť��map-ת�� */

CAL_TQM int16_T MTQD_GearD_CoastRegen_Third_Tq[19] =
{
    0, 0, -14, -27, -37, -47, -57, -57, -52, -52, -52, -52, -47, -37, -27, -17,
    -12, 0, 0
} ;                                    /* D��������������Ť��map-Ť�أ��������գ� */

CAL_TQM int16_T MTQD_GearR_BrakeRegen_Zero_Tq[19] =
{
    0, 0, -5, -10, -25, -24, -23, -22, -21, -20, -19, -17, -15, -10, -5, 0, 0, 0,
    0
} ;                                    /* R���ƶ���������Ť��map-Ť�أ��㵲���գ� */

CAL_TQM int16_T MTQD_GearR_CoastRegen_First_Tq[19] =
{
    0, 0, -4, -7, -12, -17, -22, -27, -32, -32, -32, -27, -22, -17, -12, -7, 0,
    0, 0
} ;                                    /* R��������������Ť��map-Ť�أ�һ�����գ� */

CAL_TQM int16_T MTQD_GearR_CoastRegen_Fourth_Tq[19] =
{
    0, 0, -16, -32, -42, -52, -62, -62, -62, -62, -62, -57, -52, -42, -32, -27,
    -22, 0, 0
} ;                                    /* R��������������Ť��map-Ť�أ��ĵ����գ� */

CAL_TQM int16_T MTQD_GearR_CoastRegen_Second_Tq[19] =
{
    0, 0, -11, -22, -32, -37, -42, -42, -42, -42, -42, -42, -42, -32, -22, -12,
    0, 0, 0
} ;                                    /* R��������������Ť��map-Ť�أ��������գ� */

CAL_TQM uint16_T MTQD_GearR_CoastRegen_Spd[19] =
{
    0U, 520U, 780U, 975U, 1300U, 1950U, 2600U, 3250U, 3900U, 4550U, 5200U, 5850U,
    6500U, 7150U, 7800U, 8450U, 9100U, 9425U, 9750U
} ;                                    /* R��������������Ť��map-ת�� */

CAL_TQM int16_T MTQD_GearR_CoastRegen_Third_Tq[19] =
{
    0, 0, -14, -27, -37, -47, -57, -57, -52, -52, -52, -52, -47, -37, -27, -17,
    -12, 0, 0
} ;                                    /* R��������������Ť��map-Ť�أ��������գ� */

CAL_TQM uint16_T MTQD_PedalMapAccpedal_ClutchMode_pct[16] =
{
    0U, 80U, 160U, 320U, 480U, 640U, 720U, 800U, 880U, 960U, 1040U, 1120U, 1280U,
    1440U, 1520U, 1600U
} ;                                    /* �ֶ�������D����ֵŤ�ذٷֱ�amp-����̤�忪�� */

CAL_TQM uint16_T MTQD_PedalMapBoostAccpedal_Eco_pct[16] =
{
    0U, 80U, 160U, 320U, 480U, 640U, 720U, 800U, 880U, 960U, 1040U, 1120U, 1280U,
    1440U, 1520U, 1600U
} ;                                    /* NormalģʽD����ֵŤ�ذٷֱ�amp-����̤�忪�� */

CAL_TQM uint16_T MTQD_PedalMapBoostAccpedal_X_pct[16] =
{
    0U, 80U, 160U, 320U, 480U, 640U, 720U, 800U, 880U, 960U, 1040U, 1120U, 1280U,
    1440U, 1520U, 1600U
} ;                                    /* SportģʽD����ֵŤ�ذٷֱ�amp-����̤�忪�� */

CAL_TQM uint16_T MTQD_PedalMapBoostTmSpeed_Eco_rpm[12] =
{
    500U, 1000U, 1500U, 1850U, 2250U, 3000U, 3750U, 4500U, 6000U, 7500U, 9000U,
    10500U
} ;                                    /* NormalģʽD����ֵŤ�ذٷֱ�amp-ת�� */

CAL_TQM uint16_T MTQD_PedalMapBoostTmSpeed_Y_rpm[12] =
{
    500U, 1000U, 1500U, 1850U, 2250U, 3000U, 3750U, 4500U, 6000U, 7500U, 9000U,
    10500U
} ;                                    /* SportģʽD����ֵŤ�ذٷֱ�amp-ת�� */

CAL_TQM uint16_T MTQD_PedalMapBoost_Eco_pct[192] =
{
    0U, 32U, 80U, 160U, 288U, 480U, 640U, 800U, 960U, 1120U, 1280U, 1360U, 1488U,
    1568U, 1600U, 1600U, 0U, 32U, 80U, 160U, 288U, 480U, 640U, 800U, 960U, 1120U,
    1280U, 1360U, 1488U, 1568U, 1600U, 1600U, 0U, 32U, 80U, 160U, 288U, 480U,
    640U, 800U, 960U, 1120U, 1280U, 1360U, 1488U, 1568U, 1600U, 1600U, 0U, 16U,
    80U, 160U, 288U, 480U, 640U, 800U, 960U, 1120U, 1280U, 1360U, 1488U, 1568U,
    1600U, 1600U, 0U, 0U, 64U, 160U, 288U, 480U, 640U, 800U, 944U, 1120U, 1280U,
    1360U, 1488U, 1568U, 1584U, 1600U, 0U, 0U, 48U, 160U, 288U, 480U, 608U, 784U,
    912U, 1120U, 1280U, 1360U, 1488U, 1568U, 1584U, 1600U, 0U, 0U, 32U, 160U,
    272U, 448U, 576U, 752U, 880U, 1120U, 1280U, 1360U, 1488U, 1568U, 1584U,
    1600U, 0U, 0U, 16U, 144U, 256U, 416U, 528U, 688U, 848U, 1072U, 1280U, 1360U,
    1488U, 1552U, 1584U, 1600U, 0U, 0U, 0U, 128U, 240U, 384U, 496U, 656U, 816U,
    1024U, 1264U, 1360U, 1472U, 1536U, 1584U, 1600U, 0U, 0U, 0U, 112U, 208U,
    352U, 464U, 624U, 784U, 976U, 1200U, 1280U, 1440U, 1520U, 1568U, 1600U, 0U,
    0U, 0U, 96U, 176U, 320U, 432U, 592U, 752U, 928U, 1104U, 1200U, 1360U, 1456U,
    1536U, 1600U, 0U, 0U, 0U, 80U, 160U, 288U, 400U, 560U, 720U, 880U, 1040U,
    1120U, 1280U, 1440U, 1520U, 1600U
} ;                                    /* NormalģʽD����ֵŤ�ذٷֱ�amp-�ٷֱ� */

CAL_TQM uint16_T MTQD_PedalMapBoost_pct[192] =
{
    0U, 32U, 80U, 160U, 288U, 480U, 640U, 800U, 960U, 1120U, 1280U, 1360U, 1488U,
    1568U, 1600U, 1600U, 0U, 32U, 80U, 160U, 288U, 480U, 640U, 800U, 960U, 1120U,
    1280U, 1360U, 1488U, 1568U, 1600U, 1600U, 0U, 32U, 80U, 160U, 288U, 480U,
    640U, 800U, 960U, 1120U, 1280U, 1360U, 1488U, 1568U, 1600U, 1600U, 0U, 16U,
    80U, 160U, 288U, 480U, 640U, 800U, 960U, 1120U, 1280U, 1360U, 1488U, 1568U,
    1600U, 1600U, 0U, 0U, 64U, 160U, 288U, 480U, 640U, 800U, 944U, 1120U, 1280U,
    1360U, 1488U, 1568U, 1584U, 1600U, 0U, 0U, 48U, 160U, 288U, 480U, 608U, 784U,
    912U, 1120U, 1280U, 1360U, 1488U, 1568U, 1584U, 1600U, 0U, 0U, 32U, 160U,
    272U, 448U, 576U, 752U, 880U, 1120U, 1280U, 1360U, 1488U, 1568U, 1584U,
    1600U, 0U, 0U, 16U, 144U, 256U, 416U, 528U, 688U, 848U, 1072U, 1280U, 1360U,
    1488U, 1552U, 1584U, 1600U, 0U, 0U, 0U, 128U, 240U, 384U, 496U, 656U, 816U,
    1024U, 1264U, 1360U, 1472U, 1536U, 1584U, 1600U, 0U, 0U, 0U, 112U, 208U,
    352U, 464U, 624U, 784U, 976U, 1200U, 1280U, 1440U, 1520U, 1568U, 1600U, 0U,
    0U, 0U, 96U, 176U, 320U, 432U, 592U, 752U, 928U, 1104U, 1200U, 1360U, 1456U,
    1536U, 1600U, 0U, 0U, 0U, 80U, 160U, 288U, 400U, 560U, 720U, 880U, 1040U,
    1120U, 1280U, 1440U, 1520U, 1600U
} ;                                    /* SportģʽD����ֵŤ�ذٷֱ�amp-�ٷֱ� */

CAL_TQM uint16_T MTQD_PedalMapClutchMode_Fifth_pct[192] =
{
    0U, 32U, 80U, 160U, 288U, 480U, 640U, 800U, 960U, 1120U, 1280U, 1360U, 1488U,
    1568U, 1600U, 1600U, 0U, 32U, 80U, 160U, 288U, 480U, 640U, 800U, 960U, 1120U,
    1280U, 1360U, 1488U, 1568U, 1600U, 1600U, 0U, 32U, 80U, 160U, 288U, 480U,
    640U, 800U, 960U, 1120U, 1280U, 1360U, 1488U, 1568U, 1600U, 1600U, 0U, 16U,
    80U, 160U, 288U, 480U, 640U, 800U, 960U, 1120U, 1280U, 1360U, 1488U, 1568U,
    1600U, 1600U, 0U, 0U, 64U, 160U, 288U, 480U, 640U, 800U, 944U, 1120U, 1280U,
    1360U, 1488U, 1568U, 1584U, 1600U, 0U, 0U, 48U, 160U, 288U, 480U, 608U, 784U,
    912U, 1120U, 1280U, 1360U, 1488U, 1568U, 1584U, 1600U, 0U, 0U, 32U, 160U,
    272U, 448U, 576U, 752U, 880U, 1120U, 1280U, 1360U, 1488U, 1568U, 1584U,
    1600U, 0U, 0U, 16U, 144U, 256U, 416U, 528U, 688U, 848U, 1072U, 1280U, 1360U,
    1488U, 1552U, 1584U, 1600U, 0U, 0U, 0U, 128U, 240U, 384U, 496U, 656U, 816U,
    1024U, 1264U, 1360U, 1472U, 1536U, 1584U, 1600U, 0U, 0U, 0U, 112U, 208U,
    352U, 464U, 624U, 784U, 976U, 1200U, 1280U, 1440U, 1520U, 1568U, 1600U, 0U,
    0U, 0U, 96U, 176U, 320U, 432U, 592U, 752U, 928U, 1104U, 1200U, 1360U, 1456U,
    1536U, 1600U, 0U, 0U, 0U, 80U, 160U, 288U, 400U, 560U, 720U, 880U, 1040U,
    1120U, 1280U, 1440U, 1520U, 1600U
} ;                                    /* �ֶ�������D5��Ť�ذٷֱ�amp-�ٷֱ� */

CAL_TQM uint16_T MTQD_PedalMapClutchMode_First_pct[192] =
{
    0U, 32U, 80U, 160U, 288U, 480U, 640U, 800U, 960U, 1120U, 1280U, 1360U, 1488U,
    1568U, 1600U, 1600U, 0U, 32U, 80U, 160U, 288U, 480U, 640U, 800U, 960U, 1120U,
    1280U, 1360U, 1488U, 1568U, 1600U, 1600U, 0U, 32U, 80U, 160U, 288U, 480U,
    640U, 800U, 960U, 1120U, 1280U, 1360U, 1488U, 1568U, 1600U, 1600U, 0U, 16U,
    80U, 160U, 288U, 480U, 640U, 800U, 960U, 1120U, 1280U, 1360U, 1488U, 1568U,
    1600U, 1600U, 0U, 0U, 64U, 160U, 288U, 480U, 640U, 800U, 944U, 1120U, 1280U,
    1360U, 1488U, 1568U, 1584U, 1600U, 0U, 0U, 48U, 160U, 288U, 480U, 608U, 784U,
    912U, 1120U, 1280U, 1360U, 1488U, 1568U, 1584U, 1600U, 0U, 0U, 32U, 160U,
    272U, 448U, 576U, 752U, 880U, 1120U, 1280U, 1360U, 1488U, 1568U, 1584U,
    1600U, 0U, 0U, 16U, 144U, 256U, 416U, 528U, 688U, 848U, 1072U, 1280U, 1360U,
    1488U, 1552U, 1584U, 1600U, 0U, 0U, 0U, 128U, 240U, 384U, 496U, 656U, 816U,
    1024U, 1264U, 1360U, 1472U, 1536U, 1584U, 1600U, 0U, 0U, 0U, 112U, 208U,
    352U, 464U, 624U, 784U, 976U, 1200U, 1280U, 1440U, 1520U, 1568U, 1600U, 0U,
    0U, 0U, 96U, 176U, 320U, 432U, 592U, 752U, 928U, 1104U, 1200U, 1360U, 1456U,
    1536U, 1600U, 0U, 0U, 0U, 80U, 160U, 288U, 400U, 560U, 720U, 880U, 1040U,
    1120U, 1280U, 1440U, 1520U, 1600U
} ;                                    /* �ֶ�������D1��Ť�ذٷֱ�amp-�ٷֱ� */

CAL_TQM uint16_T MTQD_PedalMapClutchMode_Fourth_pct[192] =
{
    0U, 32U, 80U, 160U, 288U, 480U, 640U, 800U, 960U, 1120U, 1280U, 1360U, 1488U,
    1568U, 1600U, 1600U, 0U, 32U, 80U, 160U, 288U, 480U, 640U, 800U, 960U, 1120U,
    1280U, 1360U, 1488U, 1568U, 1600U, 1600U, 0U, 32U, 80U, 160U, 288U, 480U,
    640U, 800U, 960U, 1120U, 1280U, 1360U, 1488U, 1568U, 1600U, 1600U, 0U, 16U,
    80U, 160U, 288U, 480U, 640U, 800U, 960U, 1120U, 1280U, 1360U, 1488U, 1568U,
    1600U, 1600U, 0U, 0U, 64U, 160U, 288U, 480U, 640U, 800U, 944U, 1120U, 1280U,
    1360U, 1488U, 1568U, 1584U, 1600U, 0U, 0U, 48U, 160U, 288U, 480U, 608U, 784U,
    912U, 1120U, 1280U, 1360U, 1488U, 1568U, 1584U, 1600U, 0U, 0U, 32U, 160U,
    272U, 448U, 576U, 752U, 880U, 1120U, 1280U, 1360U, 1488U, 1568U, 1584U,
    1600U, 0U, 0U, 16U, 144U, 256U, 416U, 528U, 688U, 848U, 1072U, 1280U, 1360U,
    1488U, 1552U, 1584U, 1600U, 0U, 0U, 0U, 128U, 240U, 384U, 496U, 656U, 816U,
    1024U, 1264U, 1360U, 1472U, 1536U, 1584U, 1600U, 0U, 0U, 0U, 112U, 208U,
    352U, 464U, 624U, 784U, 976U, 1200U, 1280U, 1440U, 1520U, 1568U, 1600U, 0U,
    0U, 0U, 96U, 176U, 320U, 432U, 592U, 752U, 928U, 1104U, 1200U, 1360U, 1456U,
    1536U, 1600U, 0U, 0U, 0U, 80U, 160U, 288U, 400U, 560U, 720U, 880U, 1040U,
    1120U, 1280U, 1440U, 1520U, 1600U
} ;                                    /* �ֶ�������D4��Ť�ذٷֱ�amp-�ٷֱ� */

CAL_TQM uint16_T MTQD_PedalMapClutchMode_Second_pct[192] =
{
    0U, 32U, 80U, 160U, 288U, 480U, 640U, 800U, 960U, 1120U, 1280U, 1360U, 1488U,
    1568U, 1600U, 1600U, 0U, 32U, 80U, 160U, 288U, 480U, 640U, 800U, 960U, 1120U,
    1280U, 1360U, 1488U, 1568U, 1600U, 1600U, 0U, 32U, 80U, 160U, 288U, 480U,
    640U, 800U, 960U, 1120U, 1280U, 1360U, 1488U, 1568U, 1600U, 1600U, 0U, 16U,
    80U, 160U, 288U, 480U, 640U, 800U, 960U, 1120U, 1280U, 1360U, 1488U, 1568U,
    1600U, 1600U, 0U, 0U, 64U, 160U, 288U, 480U, 640U, 800U, 944U, 1120U, 1280U,
    1360U, 1488U, 1568U, 1584U, 1600U, 0U, 0U, 48U, 160U, 288U, 480U, 608U, 784U,
    912U, 1120U, 1280U, 1360U, 1488U, 1568U, 1584U, 1600U, 0U, 0U, 32U, 160U,
    272U, 448U, 576U, 752U, 880U, 1120U, 1280U, 1360U, 1488U, 1568U, 1584U,
    1600U, 0U, 0U, 16U, 144U, 256U, 416U, 528U, 688U, 848U, 1072U, 1280U, 1360U,
    1488U, 1552U, 1584U, 1600U, 0U, 0U, 0U, 128U, 240U, 384U, 496U, 656U, 816U,
    1024U, 1264U, 1360U, 1472U, 1536U, 1584U, 1600U, 0U, 0U, 0U, 112U, 208U,
    352U, 464U, 624U, 784U, 976U, 1200U, 1280U, 1440U, 1520U, 1568U, 1600U, 0U,
    0U, 0U, 96U, 176U, 320U, 432U, 592U, 752U, 928U, 1104U, 1200U, 1360U, 1456U,
    1536U, 1600U, 0U, 0U, 0U, 80U, 160U, 288U, 400U, 560U, 720U, 880U, 1040U,
    1120U, 1280U, 1440U, 1520U, 1600U
} ;                                    /* �ֶ�������D2��Ť�ذٷֱ�amp-�ٷֱ� */

CAL_TQM uint16_T MTQD_PedalMapClutchMode_Third_pct[192] =
{
    0U, 32U, 80U, 160U, 288U, 480U, 640U, 800U, 960U, 1120U, 1280U, 1360U, 1488U,
    1568U, 1600U, 1600U, 0U, 32U, 80U, 160U, 288U, 480U, 640U, 800U, 960U, 1120U,
    1280U, 1360U, 1488U, 1568U, 1600U, 1600U, 0U, 32U, 80U, 160U, 288U, 480U,
    640U, 800U, 960U, 1120U, 1280U, 1360U, 1488U, 1568U, 1600U, 1600U, 0U, 16U,
    80U, 160U, 288U, 480U, 640U, 800U, 960U, 1120U, 1280U, 1360U, 1488U, 1568U,
    1600U, 1600U, 0U, 0U, 64U, 160U, 288U, 480U, 640U, 800U, 944U, 1120U, 1280U,
    1360U, 1488U, 1568U, 1584U, 1600U, 0U, 0U, 48U, 160U, 288U, 480U, 608U, 784U,
    912U, 1120U, 1280U, 1360U, 1488U, 1568U, 1584U, 1600U, 0U, 0U, 32U, 160U,
    272U, 448U, 576U, 752U, 880U, 1120U, 1280U, 1360U, 1488U, 1568U, 1584U,
    1600U, 0U, 0U, 16U, 144U, 256U, 416U, 528U, 688U, 848U, 1072U, 1280U, 1360U,
    1488U, 1552U, 1584U, 1600U, 0U, 0U, 0U, 128U, 240U, 384U, 496U, 656U, 816U,
    1024U, 1264U, 1360U, 1472U, 1536U, 1584U, 1600U, 0U, 0U, 0U, 112U, 208U,
    352U, 464U, 624U, 784U, 976U, 1200U, 1280U, 1440U, 1520U, 1568U, 1600U, 0U,
    0U, 0U, 96U, 176U, 320U, 432U, 592U, 752U, 928U, 1104U, 1200U, 1360U, 1456U,
    1536U, 1600U, 0U, 0U, 0U, 80U, 160U, 288U, 400U, 560U, 720U, 880U, 1040U,
    1120U, 1280U, 1440U, 1520U, 1600U
} ;                                    /* �ֶ�������D3��Ť�ذٷֱ�amp-�ٷֱ� */

CAL_TQM uint16_T MTQD_PedalMapRevAccpedal_ClutchMode_pct[16] =
{
    0U, 80U, 160U, 320U, 480U, 640U, 720U, 800U, 880U, 960U, 1040U, 1120U, 1280U,
    1440U, 1520U, 1600U
} ;                                    /* �ֶ�������R����ֵŤ�ذٷֱ�amp-����̤�忪�� */

CAL_TQM uint16_T MTQD_PedalMapRevAccpedal_X_pct[16] =
{
    0U, 80U, 160U, 320U, 480U, 640U, 720U, 800U, 880U, 960U, 1040U, 1120U, 1280U,
    1440U, 1520U, 1600U
} ;                                    /* R����ֵŤ�ذٷֱ�amp-����̤�忪�� */

CAL_TQM uint16_T MTQD_PedalMapRevTmSpeed_ClutchMode_rpm[12] =
{
    500U, 1000U, 1500U, 1850U, 2250U, 3000U, 3750U, 4500U, 6000U, 7500U, 9000U,
    10500U
} ;                                    /* �ֶ�������R����ֵŤ�ذٷֱ�amp-ת�� */

CAL_TQM uint16_T MTQD_PedalMapRevTmSpeed_Y_rpm[12] =
{
    500U, 1000U, 1500U, 1850U, 2250U, 3000U, 3750U, 4500U, 6000U, 7500U, 9000U,
    10500U
} ;                                    /* R����ֵŤ�ذٷֱ�amp-ת�� */

CAL_TQM uint16_T MTQD_PedalMapRev_ClutchMode_pct[192] =
{
    0U, 32U, 80U, 160U, 240U, 320U, 352U, 400U, 432U, 480U, 640U, 800U, 960U,
    1280U, 1600U, 1600U, 0U, 32U, 80U, 160U, 240U, 320U, 352U, 400U, 432U, 480U,
    640U, 800U, 960U, 1280U, 1600U, 1600U, 0U, 32U, 80U, 160U, 240U, 320U, 352U,
    400U, 432U, 480U, 640U, 800U, 960U, 1280U, 1600U, 1600U, 0U, 16U, 80U, 160U,
    240U, 320U, 352U, 400U, 432U, 480U, 640U, 800U, 960U, 1280U, 1600U, 1600U,
    0U, 0U, 64U, 160U, 240U, 320U, 352U, 400U, 432U, 480U, 640U, 800U, 960U,
    1280U, 1584U, 1600U, 0U, 0U, 48U, 160U, 240U, 320U, 336U, 384U, 432U, 480U,
    640U, 800U, 960U, 1280U, 1584U, 1600U, 0U, 0U, 32U, 160U, 224U, 304U, 320U,
    368U, 416U, 480U, 640U, 800U, 960U, 1280U, 1584U, 1600U, 0U, 0U, 16U, 144U,
    208U, 288U, 320U, 352U, 400U, 464U, 640U, 800U, 944U, 1264U, 1584U, 1600U,
    0U, 0U, 0U, 128U, 192U, 272U, 320U, 336U, 384U, 448U, 624U, 800U, 928U,
    1248U, 1584U, 1600U, 0U, 0U, 0U, 112U, 176U, 256U, 304U, 336U, 368U, 432U,
    608U, 784U, 912U, 1232U, 1568U, 1600U, 0U, 0U, 0U, 96U, 144U, 240U, 288U,
    320U, 352U, 416U, 592U, 768U, 896U, 1216U, 1536U, 1600U, 0U, 0U, 0U, 80U,
    128U, 224U, 272U, 304U, 336U, 400U, 576U, 752U, 880U, 1040U, 1520U, 1600U
} ;                                    /* �ֶ�������R��Ť�ذٷֱ�amp-�ٷֱ� */

CAL_TQM uint16_T MTQD_PedalMapRev_pct[192] =
{
    0U, 32U, 80U, 160U, 240U, 320U, 352U, 400U, 432U, 480U, 640U, 800U, 960U,
    1280U, 1600U, 1600U, 0U, 32U, 80U, 160U, 240U, 320U, 352U, 400U, 432U, 480U,
    640U, 800U, 960U, 1280U, 1600U, 1600U, 0U, 32U, 80U, 160U, 240U, 320U, 352U,
    400U, 432U, 480U, 640U, 800U, 960U, 1280U, 1600U, 1600U, 0U, 16U, 80U, 160U,
    240U, 320U, 352U, 400U, 432U, 480U, 640U, 800U, 960U, 1280U, 1600U, 1600U,
    0U, 0U, 64U, 160U, 240U, 320U, 352U, 400U, 432U, 480U, 640U, 800U, 960U,
    1280U, 1584U, 1600U, 0U, 0U, 48U, 160U, 240U, 320U, 336U, 384U, 432U, 480U,
    640U, 800U, 960U, 1280U, 1584U, 1600U, 0U, 0U, 32U, 160U, 224U, 304U, 320U,
    368U, 416U, 480U, 640U, 800U, 960U, 1280U, 1584U, 1600U, 0U, 0U, 16U, 144U,
    208U, 288U, 320U, 352U, 400U, 464U, 640U, 800U, 944U, 1264U, 1584U, 1600U,
    0U, 0U, 0U, 128U, 192U, 272U, 320U, 336U, 384U, 448U, 624U, 800U, 928U,
    1248U, 1584U, 1600U, 0U, 0U, 0U, 112U, 176U, 256U, 304U, 336U, 368U, 432U,
    608U, 784U, 912U, 1232U, 1568U, 1600U, 0U, 0U, 0U, 96U, 144U, 240U, 288U,
    320U, 352U, 416U, 592U, 768U, 896U, 1216U, 1536U, 1600U, 0U, 0U, 0U, 80U,
    128U, 224U, 272U, 304U, 336U, 400U, 576U, 752U, 880U, 1040U, 1520U, 1600U
} ;                                    /* R����ֵŤ�ذٷֱ�amp-�ٷֱ� */

CAL_TQM uint16_T MTQD_PedalMapTmSpeed_ClutchMode_rpm[12] =
{
    500U, 1000U, 1500U, 1850U, 2250U, 3000U, 3750U, 4500U, 6000U, 7500U, 9000U,
    10500U
} ;                                    /* �ֶ�������D����ֵŤ�ذٷֱ�amp-ת�� */

CAL_TQM uint16_T MTQD_TqMapPeakTmSpeed_X_rpm[22] =
{
    0U, 493U, 1030U, 1500U, 2010U, 2510U, 3000U, 3490U, 4090U, 4540U, 5080U,
    5510U, 5960U, 6450U, 6880U, 7400U, 7930U, 8380U, 9020U, 10000U, 11000U,
    12000U
} ;                                    /* ���������map-ת�� */

CAL_TQM int16_T MTQD_TqMapPeakTq_Nm[22] =
{
    280, 280, 280, 280, 280, 280, 280, 246, 210, 189, 169, 155, 144, 133, 124,
    116, 108, 102, 95, 85, 0, 0
} ;                                    /* ���������map-Ť�� */

CAL_TQM uint16_T MTQD_TqMapRevTmSpeed_X_rpm[22] =
{
    0U, 493U, 1030U, 1500U, 2010U, 2510U, 3000U, 3490U, 4090U, 4540U, 5080U,
    5510U, 5960U, 6450U, 6880U, 7400U, 7930U, 8380U, 9020U, 10000U, 11000U,
    12000U
} ;                                    /* R����ֵŤ��map-ת�� */

CAL_TQM int16_T MTQD_TqMapRevTq_Nm[22] =
{
    280, 280, 280, 280, 280, 280, 280, 246, 210, 189, 169, 155, 144, 133, 124,
    116, 108, 102, 95, 85, 0, 0
} ;                                    /* R����ֵŤ��map-Ť�� */

CAL_TQM uint16_T PTT_MotDriveEffi_Pct[182] =
{
    19164U, 21670U, 22246U, 22682U, 22554U, 22415U, 22272U, 21949U, 21309U,
    20429U, 19318U, 18624U, 17559U, 19802U, 21670U, 22246U, 22682U, 22554U,
    22415U, 22272U, 21949U, 21309U, 20429U, 19318U, 18624U, 17559U, 19850U,
    22144U, 22758U, 22682U, 22554U, 22415U, 22272U, 21949U, 21309U, 20429U,
    19318U, 18624U, 17559U, 19080U, 22042U, 23398U, 23475U, 23401U, 23183U,
    22886U, 21949U, 21309U, 20429U, 19318U, 18624U, 17559U, 18097U, 21811U,
    23460U, 23767U, 23846U, 23811U, 23398U, 22436U, 21780U, 21046U, 19318U,
    18624U, 17559U, 17093U, 21504U, 23424U, 23836U, 24038U, 24003U, 23821U,
    22922U, 22321U, 21617U, 20155U, 19448U, 18696U, 16630U, 21274U, 23419U,
    23872U, 24095U, 24077U, 23905U, 23163U, 22643U, 21924U, 20521U, 19886U,
    19123U, 16630U, 21939U, 23309U, 23921U, 24197U, 24218U, 24125U, 23475U,
    23117U, 22564U, 21827U, 21199U, 20403U, 16630U, 20608U, 23073U, 23903U,
    24243U, 24358U, 24225U, 23764U, 23429U, 22986U, 22198U, 21791U, 21248U,
    16630U, 20608U, 22715U, 23770U, 24253U, 24387U, 24279U, 23900U, 23575U,
    23227U, 22554U, 22287U, 21786U, 16630U, 20608U, 22298U, 23718U, 24228U,
    24379U, 24233U, 23918U, 23665U, 23281U, 22700U, 22408U, 21921U, 16630U,
    20608U, 21888U, 23478U, 24161U, 24325U, 24228U, 23921U, 23672U, 23327U,
    22804U, 22548U, 21939U, 16630U, 20608U, 21888U, 23296U, 24067U, 24261U,
    24172U, 23788U, 23639U, 23373U, 23291U, 22712U, 22413U, 16630U, 20608U,
    21888U, 23040U, 23992U, 24172U, 24008U, 23703U, 23296U, 23373U, 23291U,
    22712U, 22413U
} ;                                    /* ����ϵͳ�ŵ�Ч��map-Ч�� */

CAL_TQM uint16_T PTT_MotDriveEffi_Power[14] =
{
    68U, 128U, 326U, 685U, 1015U, 1323U, 1491U, 1989U, 2644U, 3416U, 3863U,
    4563U, 5467U, 6186U
} ;                                    /* ����ϵͳ�ŵ�Ч��map-���� */

CAL_TQM uint16_T PTT_MotDriveEffi_Spd[13] =
{
    500U, 1000U, 2000U, 3000U, 4000U, 5000U, 6000U, 7000U, 7500U, 8000U, 9000U,
    9500U, 10000U
} ;                                    /* ����ϵͳ�ŵ�Ч��map-ת�� */

CAL_TQM uint16_T PTT_MotRegenEffi_Pct[182] =
{
    19164U, 21670U, 22246U, 22682U, 22554U, 22415U, 22272U, 21949U, 21309U,
    20429U, 19318U, 18624U, 17559U, 19802U, 21670U, 22246U, 22682U, 22554U,
    22415U, 22272U, 21949U, 21309U, 20429U, 19318U, 18624U, 17559U, 19850U,
    22144U, 22758U, 22682U, 22554U, 22415U, 22272U, 21949U, 21309U, 20429U,
    19318U, 18624U, 17559U, 19080U, 22042U, 23398U, 23475U, 23401U, 23183U,
    22886U, 21949U, 21309U, 20429U, 19318U, 18624U, 17559U, 18097U, 21811U,
    23460U, 23767U, 23846U, 23811U, 23398U, 22436U, 21780U, 21046U, 19318U,
    18624U, 17559U, 17093U, 21504U, 23424U, 23836U, 24038U, 24003U, 23821U,
    22922U, 22321U, 21617U, 20155U, 19448U, 18696U, 16630U, 21274U, 23419U,
    23872U, 24095U, 24077U, 23905U, 23163U, 22643U, 21924U, 20521U, 19886U,
    19123U, 16630U, 21939U, 23309U, 23921U, 24197U, 24218U, 24125U, 23475U,
    23117U, 22564U, 21827U, 21199U, 20403U, 16630U, 20608U, 23073U, 23903U,
    24243U, 24358U, 24225U, 23764U, 23429U, 22986U, 22198U, 21791U, 21248U,
    16630U, 20608U, 22715U, 23770U, 24253U, 24387U, 24279U, 23900U, 23575U,
    23227U, 22554U, 22287U, 21786U, 16630U, 20608U, 22298U, 23718U, 24228U,
    24379U, 24233U, 23918U, 23665U, 23281U, 22700U, 22408U, 21921U, 16630U,
    20608U, 21888U, 23478U, 24161U, 24325U, 24228U, 23921U, 23672U, 23327U,
    22804U, 22548U, 21939U, 16630U, 20608U, 21888U, 23296U, 24067U, 24261U,
    24172U, 23788U, 23639U, 23373U, 23291U, 22712U, 22413U, 16630U, 20608U,
    21888U, 23040U, 23992U, 24172U, 24008U, 23703U, 23296U, 23373U, 23291U,
    22712U, 22413U
} ;                                    /* ����ϵͳ����Ч��map-Ч�� */

CAL_TQM uint16_T PTT_MotRegenEffi_Power[14] =
{
    68U, 128U, 326U, 685U, 1015U, 1323U, 1491U, 1989U, 2644U, 3416U, 3863U,
    4563U, 5467U, 6186U
} ;                                    /* ����ϵͳ����Ч��map-���� */

CAL_TQM uint16_T PTT_MotRegenEffi_Spd[13] =
{
    500U, 1000U, 2000U, 3000U, 4000U, 5000U, 6000U, 7000U, 7500U, 8000U, 9000U,
    9500U, 10000U
} ;                                    /* ����ϵͳ����Ч��map-ת�� */

CAL_TQM uint16_T P_Delay_time = 150U;  /* ��P���ȴ�EPB��פʱ�� */
CAL_TQM uint8_T Period = 20U;          /* ģ������ʱ��-ms */
CAL_TQM uint16_T REC_No_Evflag_TrueDelay = 81U;/* ��ֹ�������ձ�־����ʱ���ж�-����ʱ����ڸ�ֵ����Ϊ��Ч�������� */
CAL_TQM uint8_T REC_RegenEnaAccePct_Cal = 4U;/* ����̤�忪�ȴ��ڸ�ֵʱ��λ�������ձ�־ */
CAL_TQM uint8_T REC_RegenEnaSpd_Cal = 5U;/* ���ٵ��ڸ�ֵʱ��λ�������ձ�־ */
CAL_TQM uint16_T RampExecTime = 20U;   /* б�����Ʋ�������ʱ�� */
CAL_TQM uint8_T Reverse = 2U;          /* �����ת��־ */
CAL_TQM uint8_T SpeedAccelBuffer = 2U;
CAL_TQM uint8_T SpeedAccel_Alpha = 1U;
CAL_TQM uint8_T Sport_Mode = 2U;       /* �˶�ģʽ��־ */
CAL_TQM uint8_T Standstill = 0U;       /* �����ֹ��־ */
CAL_TQM boolean_T TQD_FALSE = 0;
CAL_TQM boolean_T TQD_TRUE = 1;
CAL_TQM int8_T TQD_integral_reset_value = 0;/* i����Ť�ؼ�������ֵ */
CAL_TQM int16_T TQD_max_dmd = 30;      /* i���ּ�������Ť�� */
CAL_TQM int16_T TQD_min_dmd = -30;     /* i���ּ�������Ť�� */
CAL_TQM uint16_T TQF_DriveDecDistance_Filter1 = 50U;/* б��1 */
CAL_TQM uint16_T TQF_DriveDecDistance_Filter2 = 150U;/* б��2 */
CAL_TQM uint16_T TQF_DriveDecDistance_Filter3 = 300U;/* б��3 */
CAL_TQM uint16_T TQF_DriveDecDistance_Filter4 = 500U;/* б��4 */
CAL_TQM uint16_T TQF_DriveDecDistance_Filter5 = 800U;/* б��5 */
CAL_TQM uint16_T TQF_DriveDecDistance_Filter6 = 1000U;/* б��6�������� */
CAL_TQM uint16_T TQF_DriveDecDistance_Filter7 = 1000U;/* б��7�������� */
CAL_TQM uint16_T TQF_DriveDecDistance_Filter8 = 1000U;/* б��8�������� */
CAL_TQM uint16_T TQF_DriveDecTq1 = 3U; /* ���Ť��1 */
CAL_TQM uint16_T TQF_DriveDecTq2 = 5U; /* ���Ť��2 */
CAL_TQM uint16_T TQF_DriveDecTq3 = 10U;/* ���Ť��3 */
CAL_TQM uint16_T TQF_DriveDecTq4 = 20U;/* ���Ť��4 */
CAL_TQM uint16_T TQF_DriveDecTq5 = 1000U;/* ���Ť��5�������� */
CAL_TQM uint16_T TQF_DriveDecTq6 = 1000U;/* ���Ť��6�������� */
CAL_TQM uint16_T TQF_DriveDecTq7 = 1000U;/* ���Ť��7�������� */
CAL_TQM uint16_T TQF_DriveDecTqDistance1 = 5U;/* ����Ť�������Ť�ز�ֵ1 */
CAL_TQM uint16_T TQF_DriveDecTqDistance2 = 10U;/* ����Ť�������Ť�ز�ֵ2 */
CAL_TQM uint16_T TQF_DriveDecTqDistance3 = 20U;/* ����Ť�������Ť�ز�ֵ3 */
CAL_TQM uint16_T TQF_DriveDecTqDistance4 = 30U;/* ����Ť�������Ť�ز�ֵ4 */
CAL_TQM uint16_T TQF_DriveDecTqDistance5 = 1000U;/* ����Ť�������Ť�ز�ֵ5�������� */
CAL_TQM uint16_T TQF_DriveDecTqDistance6 = 1000U;/* ����Ť�������Ť�ز�ֵ6�������� */
CAL_TQM uint16_T TQF_DriveDecTqDistance7 = 1000U;/* ����Ť�������Ť�ز�ֵ7�������� */
CAL_TQM uint16_T TQF_DriveDec_Filter1 = 100U;/* б��1 */
CAL_TQM uint16_T TQF_DriveDec_Filter2 = 200U;/* б��2 */
CAL_TQM uint16_T TQF_DriveDec_Filter3 = 300U;/* б��3 */
CAL_TQM uint16_T TQF_DriveDec_Filter4 = 500U;/* б��4 */
CAL_TQM uint16_T TQF_DriveDec_Filter5 = 800U;/* б��5 */
CAL_TQM uint16_T TQF_DriveDec_Filter6 = 1000U;/* б��6�������� */
CAL_TQM uint16_T TQF_DriveDec_Filter7 = 1000U;/* б��7�������� */
CAL_TQM uint16_T TQF_DriveDec_Filter8 = 1000U;/* б��8�������� */
CAL_TQM uint16_T TQF_DriveIncDistance_Filter1 = 50U;/* б��1 */
CAL_TQM uint16_T TQF_DriveIncDistance_Filter2 = 100U;/* б��2 */
CAL_TQM uint16_T TQF_DriveIncDistance_Filter3 = 200U;/* б��3 */
CAL_TQM uint16_T TQF_DriveIncDistance_Filter4 = 300U;/* б��4 */
CAL_TQM uint16_T TQF_DriveIncDistance_Filter5 = 400U;/* б��5 */
CAL_TQM uint16_T TQF_DriveIncDistance_Filter6 = 1000U;/* б��6�������� */
CAL_TQM uint16_T TQF_DriveIncDistance_Filter7 = 1000U;/* б��7�������� */
CAL_TQM uint16_T TQF_DriveIncDistance_Filter8 = 1000U;/* б��8�������� */
CAL_TQM uint16_T TQF_DriveIncTq1 = 3U; /* ���Ť��1 */
CAL_TQM uint16_T TQF_DriveIncTq2 = 5U; /* ���Ť��2 */
CAL_TQM uint16_T TQF_DriveIncTq3 = 10U;/* ���Ť��3 */
CAL_TQM uint16_T TQF_DriveIncTq4 = 20U;/* ���Ť��4 */
CAL_TQM uint16_T TQF_DriveIncTq5 = 1000U;/* ���Ť��5�������� */
CAL_TQM uint16_T TQF_DriveIncTq6 = 1000U;/* ���Ť��6�������� */
CAL_TQM uint16_T TQF_DriveIncTq7 = 1000U;/* ���Ť��7�������� */
CAL_TQM uint16_T TQF_DriveIncTqDistance1 = 5U;/* ����Ť�������Ť�ز�ֵ1 */
CAL_TQM uint16_T TQF_DriveIncTqDistance2 = 10U;/* ����Ť�������Ť�ز�ֵ2 */
CAL_TQM uint16_T TQF_DriveIncTqDistance3 = 20U;/* ����Ť�������Ť�ز�ֵ3 */
CAL_TQM uint16_T TQF_DriveIncTqDistance4 = 40U;/* ����Ť�������Ť�ز�ֵ4 */
CAL_TQM uint16_T TQF_DriveIncTqDistance5 = 1000U;/* ����Ť�������Ť�ز�ֵ5�������� */
CAL_TQM uint16_T TQF_DriveIncTqDistance6 = 1000U;/* ����Ť�������Ť�ز�ֵ6�������� */
CAL_TQM uint16_T TQF_DriveIncTqDistance7 = 1000U;/* ����Ť�������Ť�ز�ֵ7�������� */
CAL_TQM uint16_T TQF_DriveInc_Filter1 = 50U;/* б��1 */
CAL_TQM uint16_T TQF_DriveInc_Filter2 = 100U;/* б��2 */
CAL_TQM uint16_T TQF_DriveInc_Filter3 = 200U;/* б��3 */
CAL_TQM uint16_T TQF_DriveInc_Filter4 = 300U;/* б��4 */
CAL_TQM uint16_T TQF_DriveInc_Filter5 = 400U;/* б��5 */
CAL_TQM uint16_T TQF_DriveInc_Filter6 = 1000U;/* б��6�������� */
CAL_TQM uint16_T TQF_DriveInc_Filter7 = 1000U;/* б��7�������� */
CAL_TQM uint16_T TQF_DriveInc_Filter8 = 1000U;/* б��8�������� */
CAL_TQM uint16_T TQF_EcoDriveIncDistance_Filter1 = 50U;/* б��1 */
CAL_TQM uint16_T TQF_EcoDriveIncDistance_Filter2 = 100U;/* б��2 */
CAL_TQM uint16_T TQF_EcoDriveIncDistance_Filter3 = 150U;/* б��3 */
CAL_TQM uint16_T TQF_EcoDriveIncDistance_Filter4 = 200U;/* б��4 */
CAL_TQM uint16_T TQF_EcoDriveIncDistance_Filter5 = 300U;/* б��5 */
CAL_TQM uint16_T TQF_EcoDriveIncDistance_Filter6 = 1000U;/* б��6�������� */
CAL_TQM uint16_T TQF_EcoDriveIncDistance_Filter7 = 1000U;/* б��7�������� */
CAL_TQM uint16_T TQF_EcoDriveIncDistance_Filter8 = 1000U;/* б��8�������� */
CAL_TQM uint16_T TQF_EcoDriveIncTq1 = 3U;/* ���Ť��1 */
CAL_TQM uint16_T TQF_EcoDriveIncTq2 = 5U;/* ���Ť��2 */
CAL_TQM uint16_T TQF_EcoDriveIncTq3 = 10U;/* ���Ť��3 */
CAL_TQM uint16_T TQF_EcoDriveIncTq4 = 20U;/* ���Ť��4 */
CAL_TQM uint16_T TQF_EcoDriveIncTq5 = 1000U;/* ���Ť��5�������� */
CAL_TQM uint16_T TQF_EcoDriveIncTq6 = 1000U;/* ���Ť��6�������� */
CAL_TQM uint16_T TQF_EcoDriveIncTq7 = 1000U;/* ���Ť��7�������� */
CAL_TQM uint16_T TQF_EcoDriveIncTqDistance1 = 5U;/* ����Ť�������Ť�ز�ֵ1 */
CAL_TQM uint16_T TQF_EcoDriveIncTqDistance2 = 10U;/* ����Ť�������Ť�ز�ֵ2 */
CAL_TQM uint16_T TQF_EcoDriveIncTqDistance3 = 20U;/* ����Ť�������Ť�ز�ֵ3 */
CAL_TQM uint16_T TQF_EcoDriveIncTqDistance4 = 50U;/* ����Ť�������Ť�ز�ֵ4 */
CAL_TQM uint16_T TQF_EcoDriveIncTqDistance5 = 1000U;/* ����Ť�������Ť�ز�ֵ5�������� */
CAL_TQM uint16_T TQF_EcoDriveIncTqDistance6 = 1000U;/* ����Ť�������Ť�ز�ֵ6�������� */
CAL_TQM uint16_T TQF_EcoDriveIncTqDistance7 = 1000U;/* ����Ť�������Ť�ز�ֵ7�������� */
CAL_TQM uint16_T TQF_EcoDriveInc_Filter1 = 50U;/* б��1 */
CAL_TQM uint16_T TQF_EcoDriveInc_Filter2 = 100U;/* б��2 */
CAL_TQM uint16_T TQF_EcoDriveInc_Filter3 = 200U;/* б��3 */
CAL_TQM uint16_T TQF_EcoDriveInc_Filter4 = 250U;/* б��4 */
CAL_TQM uint16_T TQF_EcoDriveInc_Filter5 = 400U;/* б��5 */
CAL_TQM uint16_T TQF_EcoDriveInc_Filter6 = 1000U;/* б��6�������� */
CAL_TQM uint16_T TQF_EcoDriveInc_Filter7 = 1000U;/* б��7�������� */
CAL_TQM uint16_T TQF_EcoDriveInc_Filter8 = 1000U;/* б��8�������� */
CAL_TQM uint16_T TQF_RegenDecDistance_Filter1 = 50U;/* б��1 */
CAL_TQM uint16_T TQF_RegenDecDistance_Filter2 = 100U;/* б��2 */
CAL_TQM uint16_T TQF_RegenDecDistance_Filter3 = 200U;/* б��3 */
CAL_TQM uint16_T TQF_RegenDecDistance_Filter4 = 400U;/* б��4 */
CAL_TQM uint16_T TQF_RegenDecDistance_Filter5 = 600U;/* б��5 */
CAL_TQM uint16_T TQF_RegenDecDistance_Filter6 = 1000U;/* б��6�������� */
CAL_TQM uint16_T TQF_RegenDecDistance_Filter7 = 1000U;/* б��7�������� */
CAL_TQM uint16_T TQF_RegenDecDistance_Filter8 = 1000U;/* б��8�������� */
CAL_TQM uint16_T TQF_RegenDecTq1 = 3U; /* ���Ť��1 */
CAL_TQM uint16_T TQF_RegenDecTq2 = 5U; /* ���Ť��2 */
CAL_TQM uint16_T TQF_RegenDecTq3 = 10U;/* ���Ť��3 */
CAL_TQM uint16_T TQF_RegenDecTq4 = 20U;/* ���Ť��4 */
CAL_TQM uint16_T TQF_RegenDecTq5 = 1000U;/* ���Ť��5�������� */
CAL_TQM uint16_T TQF_RegenDecTq6 = 1000U;/* ���Ť��6�������� */
CAL_TQM uint16_T TQF_RegenDecTq7 = 1000U;/* ���Ť��7�������� */
CAL_TQM uint16_T TQF_RegenDecTqDistance1 = 5U;/* ����Ť�������Ť�ز�ֵ1 */
CAL_TQM uint16_T TQF_RegenDecTqDistance2 = 10U;/* ����Ť�������Ť�ز�ֵ2 */
CAL_TQM uint16_T TQF_RegenDecTqDistance3 = 20U;/* ����Ť�������Ť�ز�ֵ3 */
CAL_TQM uint16_T TQF_RegenDecTqDistance4 = 30U;/* ����Ť�������Ť�ز�ֵ4 */
CAL_TQM uint16_T TQF_RegenDecTqDistance5 = 1000U;/* ����Ť�������Ť�ز�ֵ5�������� */
CAL_TQM uint16_T TQF_RegenDecTqDistance6 = 1000U;/* ����Ť�������Ť�ز�ֵ6�������� */
CAL_TQM uint16_T TQF_RegenDecTqDistance7 = 1000U;/* ����Ť�������Ť�ز�ֵ7�������� */
CAL_TQM uint16_T TQF_RegenDec_Filter1 = 20U;/* б��1 */
CAL_TQM uint16_T TQF_RegenDec_Filter2 = 50U;/* б��2 */
CAL_TQM uint16_T TQF_RegenDec_Filter3 = 100U;/* б��3 */
CAL_TQM uint16_T TQF_RegenDec_Filter4 = 200U;/* б��4 */
CAL_TQM uint16_T TQF_RegenDec_Filter5 = 300U;/* б��5 */
CAL_TQM uint16_T TQF_RegenDec_Filter6 = 1000U;/* б��6�������� */
CAL_TQM uint16_T TQF_RegenDec_Filter7 = 1000U;/* б��7�������� */
CAL_TQM uint16_T TQF_RegenDec_Filter8 = 1000U;/* б��8�������� */
CAL_TQM uint16_T TQF_RegenIncDistance_Filter1 = 50U;/* б��1 */
CAL_TQM uint16_T TQF_RegenIncDistance_Filter2 = 150U;/* б��2 */
CAL_TQM uint16_T TQF_RegenIncDistance_Filter3 = 300U;/* б��3 */
CAL_TQM uint16_T TQF_RegenIncDistance_Filter4 = 400U;/* б��4 */
CAL_TQM uint16_T TQF_RegenIncDistance_Filter5 = 600U;/* б��5 */
CAL_TQM uint16_T TQF_RegenIncDistance_Filter6 = 1000U;/* б��6�������� */
CAL_TQM uint16_T TQF_RegenIncDistance_Filter7 = 1000U;/* б��7�������� */
CAL_TQM uint16_T TQF_RegenIncDistance_Filter8 = 1000U;/* б��8�������� */
CAL_TQM uint16_T TQF_RegenIncTq1 = 3U; /* ���Ť��1 */
CAL_TQM uint16_T TQF_RegenIncTq2 = 5U; /* ���Ť��2 */
CAL_TQM uint16_T TQF_RegenIncTq3 = 10U;/* ���Ť��3 */
CAL_TQM uint16_T TQF_RegenIncTq4 = 20U;/* ���Ť��4 */
CAL_TQM uint16_T TQF_RegenIncTq5 = 1000U;/* ���Ť��5�������� */
CAL_TQM uint16_T TQF_RegenIncTq6 = 1000U;/* ���Ť��6�������� */
CAL_TQM uint16_T TQF_RegenIncTq7 = 1000U;/* ���Ť��7�������� */
CAL_TQM uint16_T TQF_RegenIncTqDistance1 = 5U;/* ����Ť�������Ť�ز�ֵ1 */
CAL_TQM uint16_T TQF_RegenIncTqDistance2 = 10U;/* ����Ť�������Ť�ز�ֵ2 */
CAL_TQM uint16_T TQF_RegenIncTqDistance3 = 20U;/* ����Ť�������Ť�ز�ֵ3 */
CAL_TQM uint16_T TQF_RegenIncTqDistance4 = 30U;/* ����Ť�������Ť�ز�ֵ4 */
CAL_TQM uint16_T TQF_RegenIncTqDistance5 = 1000U;/* ����Ť�������Ť�ز�ֵ5�������� */
CAL_TQM uint16_T TQF_RegenIncTqDistance6 = 1000U;/* ����Ť�������Ť�ز�ֵ6�������� */
CAL_TQM uint16_T TQF_RegenIncTqDistance7 = 1000U;/* ����Ť�������Ť�ز�ֵ7�������� */
CAL_TQM uint16_T TQF_RegenInc_Filter1 = 200U;/* б��1 */
CAL_TQM uint16_T TQF_RegenInc_Filter2 = 400U;/* б��2 */
CAL_TQM uint16_T TQF_RegenInc_Filter3 = 500U;/* б��3 */
CAL_TQM uint16_T TQF_RegenInc_Filter4 = 600U;/* б��4 */
CAL_TQM uint16_T TQF_RegenInc_Filter5 = 800U;/* б��5 */
CAL_TQM uint16_T TQF_RegenInc_Filter6 = 1000U;/* б��6�������� */
CAL_TQM uint16_T TQF_RegenInc_Filter7 = 1000U;/* б��7�������� */
CAL_TQM uint16_T TQF_RegenInc_Filter8 = 1000U;/* б��8�������� */
CAL_TQM boolean_T TQF_TqFilteringEn_flg = 1;/* Ť��б������ʹ�ܿ��� */
CAL_TQM int16_T TQM_MaxTq_Cal = 280;   /* ϵͳ����������Ť�� */
CAL_TQM uint16_T TQR_BMS_Delaytime = 50U;/* BMS��������ʱŤ�ر��ֵȴ����� */
CAL_TQM uint16_T TQR_MCU_Delaytime = 50U;/* MCU��������ʱŤ�ر��ֵȴ����� */
CAL_TQM uint16_T TSC_VehTq_Filter = 60U;/* ����Ť���˲�ϵ�� */
CAL_TQM uint16_T Tcl = 20U;            /* ����������� */
CAL_TQM uint32_T Tyre_Radius_Cal = 21194U;/* ���ֹ����뾶 */
CAL_TQM uint16_T VAJ_AccePress_Fail = 32U;/* ����̤�忪��С�ڸ�ֵ��Ϊ����̤���ɿ� */
CAL_TQM uint16_T VAJ_AccePress_Succ = 64U;/* ����̤�忪�ȴ��ڸ�ֵ��Ϊ����̤����� */
CAL_TQM uint8_T VGJ_GearOff_Cal = 0U;  /* ��λϨ���־ */
CAL_TQM uint16_T VGJ_GearOff_time_Cal = 500U;/* ��λ��˸ʱ��-�� */
CAL_TQM uint16_T VGJ_GearOn_time_Cal = 500U;/* ��λ��˸ʱ��-�� */
CAL_TQM uint8_T VGJ_HigSpd_S11_Cal = 5U;/* S11���������ж����� */
CAL_TQM uint8_T VGJ_LowSpd_S11_Cal = 2U;/* S11��������P���ж����� */
CAL_TQM uint8_T VGJ_MidSpd_S11_Cal = 3U;/* S11�ͳ���ʱ�����ƶ�N������D��R�������� */
CAL_TQM uint16_T VGJ_Remind_time = 5000U;/* �ҵ���������������ʱ�� */
CAL_TQM uint8_T VGJ_Spd_K11_Cal = 5U;  /* K11���������ж����� */
CAL_TQM uint8_T VGJ_Spd_Z18 = 5U;      /* ��ť��λ�л�������ֵ */
CAL_TQM uint16_T VPL_PowerLim_Filter = 80U;/* ����ֵ�����˲����� */
CAL_TQM uint16_T VPL_PowerPctLim_Filter = 80U;/* ���ʰٷֱ������˲����� */
CAL_TQM boolean_T VSJ_ABS_Spd_Valid_Ena = 0;/* ABS�����ź���Чλʹ�ܿ��� */
CAL_TQM boolean_T VSJ_ABS_Spd_Valid_Val = 0;/* ABS�����ź���Чλʹ��״̬ */
CAL_TQM boolean_T VSJ_MCU_Spd_Valid_Ena = 0;/* MCUת���ź���Чλʹ�ܿ��� */
CAL_TQM boolean_T VSJ_MCU_Spd_Valid_Val = 0;/* MCUת���ź���Чλʹ�ܿ��� */
CAL_TQM int16_T VSJ_SpdNeg_Cal = -10;  /* �����ֹ-��ת�б��ٽ�ֵ */
CAL_TQM int16_T VSJ_SpdPos_Cal = 10;   /* �����ֹ-��ת�б��ٽ�ֵ */
CAL_TQM boolean_T VSJ_Spd_Valid_Ena = 0;/* �ٶ��ź���Чλʹ�ܿ��� */
CAL_TQM boolean_T VSJ_Spd_Valid_Val = 0;/* �ٶ��ź���Чλʹ��״̬ */
CAL_TQM uint8_T VSL_GearD1_YK19_SpdLim_Hig = 15U;/* �ֶ�������D1�����Ƴ������� */
CAL_TQM uint8_T VSL_GearD1_YK19_SpdLim_Low = 12U;/* �ֶ�������D1�����Ƴ������� */
CAL_TQM uint8_T VSL_GearD2_YK19_SpdLim_Hig = 33U;/* �ֶ�������D2�����Ƴ������� */
CAL_TQM uint8_T VSL_GearD2_YK19_SpdLim_Low = 30U;/* �ֶ�������D2�����Ƴ������� */
CAL_TQM uint8_T VSL_GearD3_YK19_SpdLim_Hig = 48U;/* �ֶ�������D3�����Ƴ������� */
CAL_TQM uint8_T VSL_GearD3_YK19_SpdLim_Low = 45U;/* �ֶ�������D3�����Ƴ������� */
CAL_TQM uint8_T VSL_GearD4_YK19_SpdLim_Hig = 58U;/* �ֶ�������D4�����Ƴ������� */
CAL_TQM uint8_T VSL_GearD4_YK19_SpdLim_Low = 55U;/* �ֶ�������D4�����Ƴ������� */
CAL_TQM uint8_T VSL_GearD5_YK19_SpdLim_Hig = 135U;/* �ֶ�������D5�����Ƴ������� */
CAL_TQM uint8_T VSL_GearD5_YK19_SpdLim_Low = 70U;/* �ֶ�������D5�����Ƴ������� */
CAL_TQM uint8_T VSL_GearD_ECOSpdLim_Hig = 90U;/* ECOģʽD���������� */
CAL_TQM uint8_T VSL_GearD_ECOSpdLim_Low = 85U;/* ECOģʽD���������� */
CAL_TQM uint8_T VSL_GearD_SPTSpdLim_Hig = 110U;/* SPTģʽD���������� */
CAL_TQM uint8_T VSL_GearD_SPTSpdLim_Low = 105U;/* SPTģʽD���������� */
CAL_TQM uint8_T VSL_GearD_SpdLim_Hig = 145U;/* D���������� */
CAL_TQM uint8_T VSL_GearD_SpdLim_Low = 140U;/* D���������� */
CAL_TQM uint8_T VSL_GearR_SpdLim_Hig = 35U;/* R���ٶ����� */
CAL_TQM uint8_T VSL_GearR_SpdLim_Low = 25U;/* R���������� */
CAL_TQM uint8_T VSL_GearR_YK19_SpdLim_Hig = 12U;/* �ֶ�������R�����Ƴ������� */
CAL_TQM uint8_T VSL_GearR_YK19_SpdLim_Low = 15U;/* �ֶ�������R�����Ƴ������� */
CAL_TQM uint8_T VSL_HighSOC = 18U;     /* ���ڸ�SOCֵ�����Ƴ��� */
CAL_TQM uint8_T VSL_LowSOC = 15U;      /* ���ڸ�SOCֵ���Ƴ��ٵ�130 */
CAL_TQM uint8_T VSL_LowSOC_SpdLim_rpm = 130U;/* ��SOC���Ƴ��� */
CAL_TQM uint8_T VSL_NormSOC_SpdLim_rpm = 200U;
CAL_TQM uint16_T VSL_SpdLim_Filter = 80U;/* ���������˲����� */
CAL_TQM boolean_T VTA_Arbitration_Ena = 0;/* �ٲ�ʹ�ܿ��� */
CAL_TQM boolean_T VTA_Arbitration_Val = 0;/* �ٲ�ʹ��ֵ */
CAL_TQM boolean_T VTA_GearN_Ena = 0;   /* N������Ť��ʹ�� */
CAL_TQM uint16_T VTA_GearN_MotSpd[14] =
{
    500U, 1000U, 1500U, 2000U, 2001U, 2500U, 3000U, 3500U, 4000U, 4001U, 5000U,
    7000U, 9000U, 10000U
} ;                                    /* N������Ť��map-ת�� */

CAL_TQM int16_T VTA_GearN_Tq[14] =
{
    16, 16, 16, 16, 32, 32, 32, 32, 32, 0, 0, 0, 0, 0
} ;                                    /* N������Ť��map-Ť�� */

CAL_TQM uint16_T VTA_Gear_P_N_Filter = 80U;/* P/N��Ť���˲�ϵ�� */
CAL_TQM uint16_T Veh_Sim_Interval_dT = 20U;/* ����ʱ�� */
CAL_TQM uint32_T Velocity_Ratio_Cal = 519674U;/* ���ٱ� */
CAL_TQM boolean_T b1_C_TQD_ACRCtrEna = 0;/* ���ٶȻ�ʹ�ܿ��� */
CAL_TQM boolean_T big_C_ConfigAccSensor_flg = 0;/* ���ٶ���Դ�ж������Ƿ����ü��ٶȴ����� */
CAL_TQM uint8_T eSpeedlHistSize = 4U;
CAL_TQM real32_T f4_C_VSP_AccSpdLower_mpss = -5.0F;/* ʵ�ʼ��ٶ����� */
CAL_TQM real32_T f4_C_VSP_AccSpdUpper_mpss = 5.0F;/* ʵ�ʼ��ٶ����� */
CAL_TQM real32_T f4_C_VSP_KamFiter_P = 10.0F;/* ���ٶȿ������˲�ϵ��P */
CAL_TQM real32_T f4_C_VSP_KamFiter_Q = 0.1F;/* ���ٶȿ������˲�ϵ��Q */
CAL_TQM real32_T f4_C_VSP_KamFiter_R = 1.0F;/* ���ٶȿ������˲�ϵ��R */
CAL_TQM int16_T lo_dec_limit = -400;   /* б�����Ʋ���Ť�ؼ�Сֵ */
CAL_TQM real32_T s1_C_ESC_TqUpOffset = 20.0F;/* ESC����Ť�ش���vcu����Ť����ֵ */
CAL_TQM real32_T s1_C_TQM_MCUTqDiff = 20.0F;/* ����Ť����ʵ��Ť�صĲ�ֵ�ж���ֵ */
CAL_TQM int8_T s2_C_TQF_DecRatStepFactor = -5;/* Ť���½�б�ʵ�������:��ֵ���������������أ���ֵ*�����������=1s */
CAL_TQM int8_T s2_C_TQF_IncRatStepFactor = 5;/* Ť������б�ʵ�������:��ֵ���������������أ���ֵ*�����������=1s */
CAL_TQM uint8_T u1_CT_TQF_AbsModRegenTqDecZRat_Nmps[25] =
{
    10U, 20U, 20U, 20U, 20U, 10U, 20U, 30U, 30U, 30U, 10U, 20U, 30U, 40U, 40U,
    10U, 20U, 30U, 40U, 50U, 10U, 20U, 30U, 40U, 50U
} ;                                    /* Creep�����µ������ƶ�Ť�ؼ�Сʱ��б������MAP��Z��(Ϊ�˽�����������,��λΪNm/100ms) */

CAL_TQM uint8_T u1_CT_TQF_GearDAccPdlModEcoDriveTqDecZRat_Nmps[25] =
{
    5U, 5U, 5U, 5U, 5U, 10U, 15U, 15U, 15U, 15U, 10U, 20U, 30U, 30U, 30U, 10U,
    20U, 30U, 50U, 50U, 10U, 20U, 30U, 50U, 80U
} ;                                    /* AccelPedal������D��ECOģʽ������Ť�ؼ�Сʱ��б������MAP��Z��(Ϊ�˽�����������,��λΪNm/100ms)(Ϊ�˽�����������,��λΪNm/100ms) */

CAL_TQM uint8_T u1_CT_TQF_GearDAccPdlModEcoDriveTqIncZRat_Nmps[25] =
{
    5U, 5U, 5U, 5U, 5U, 5U, 10U, 10U, 10U, 10U, 5U, 10U, 15U, 15U, 15U, 5U, 10U,
    20U, 20U, 20U, 5U, 10U, 20U, 25U, 30U
} ;                                    /* AccelPedal������D��ECOģʽ������Ť������ʱ��б������MAP��Z��(Ϊ�˽�����������,��λΪNm/100ms)(Ϊ�˽�����������,��λΪNm/100ms) */

CAL_TQM uint8_T u1_CT_TQF_GearDAccPdlModEcoRegenTqDecZRat_Nmps[25] =
{
    2U, 5U, 5U, 5U, 5U, 2U, 5U, 10U, 10U, 10U, 2U, 5U, 10U, 20U, 20U, 2U, 5U,
    10U, 20U, 30U, 2U, 5U, 10U, 20U, 30U
} ;                                    /* AccelPedal������D��ECOģʽ�������ƶ�Ť�ؼ�Сʱ��б������MAP��Z��(Ϊ�˽�����������,��λΪNm/100ms) */

CAL_TQM uint8_T u1_CT_TQF_GearDAccPdlModEcoRegenTqIncZRat_Nmps[25] =
{
    5U, 5U, 5U, 5U, 5U, 15U, 15U, 15U, 15U, 15U, 20U, 30U, 30U, 30U, 30U, 20U,
    40U, 40U, 40U, 40U, 20U, 40U, 50U, 60U, 60U
} ;                                    /* AccelPedal������D��ECOģʽ�������ƶ�Ť������ʱ��б������MAP��Z��(Ϊ�˽�����������,��λΪNm/100ms) */

CAL_TQM uint8_T u1_CT_TQF_GearDAccPdlModSportDriveTqDecZRat_Nmps[25] =
{
    5U, 5U, 5U, 5U, 5U, 10U, 15U, 15U, 15U, 15U, 10U, 20U, 30U, 30U, 30U, 10U,
    20U, 30U, 50U, 50U, 10U, 20U, 30U, 50U, 80U
} ;                                    /* AccelPedal������D��SPORTģʽ������Ť�ؼ�Сʱ��б������MAP��Z��(Ϊ�˽�����������,��λΪNm/100ms) */

CAL_TQM uint8_T u1_CT_TQF_GearDAccPdlModSportDriveTqIncZRat_Nmps[25] =
{
    5U, 5U, 5U, 5U, 5U, 5U, 10U, 10U, 10U, 10U, 5U, 10U, 20U, 20U, 20U, 5U, 10U,
    20U, 30U, 30U, 5U, 10U, 20U, 30U, 40U
} ;                                    /* AccelPedal������D��SPORTģʽ������Ť������ʱ��б������MAP��Z��(Ϊ�˽�����������,��λΪNm/100ms) */

CAL_TQM uint8_T u1_CT_TQF_GearDAccPdlModSportRegenTqDecZRat_Nmps[25] =
{
    2U, 5U, 5U, 5U, 5U, 2U, 5U, 10U, 10U, 10U, 2U, 5U, 10U, 20U, 20U, 2U, 5U,
    10U, 20U, 30U, 2U, 5U, 10U, 20U, 30U
} ;                                    /* AccelPedal������D��SPORTģʽ�������ƶ�Ť�ؼ�Сʱ��б������MAP��Z��(Ϊ�˽�����������,��λΪNm/100ms) */

CAL_TQM uint8_T u1_CT_TQF_GearDAccPdlModSportRegenTqIncZRat_Nmps[25] =
{
    5U, 5U, 5U, 5U, 5U, 15U, 15U, 15U, 15U, 15U, 20U, 30U, 30U, 30U, 30U, 20U,
    40U, 40U, 40U, 40U, 20U, 40U, 50U, 60U, 60U
} ;                                    /* AccelPedal������D��SPORTģʽ�������ƶ�Ť������ʱ��б������MAP��Z��(Ϊ�˽�����������,��λΪNm/100ms) */

CAL_TQM uint8_T u1_CT_TQF_GearDCreepModDriveTqDecZRat_Nmps[25] =
{
    5U, 5U, 5U, 5U, 5U, 10U, 15U, 15U, 15U, 15U, 10U, 20U, 30U, 30U, 30U, 10U,
    20U, 30U, 50U, 50U, 10U, 20U, 30U, 50U, 80U
} ;                                    /* Creep������D��������Ť�ؼ�Сʱ��б������MAP��Z��(Ϊ�˽�����������,��λΪNm/100ms) */

CAL_TQM uint8_T u1_CT_TQF_GearDCreepModDriveTqIncZRat_Nmps[25] =
{
    5U, 5U, 5U, 5U, 5U, 5U, 10U, 10U, 10U, 10U, 5U, 10U, 15U, 15U, 15U, 5U, 10U,
    20U, 20U, 20U, 5U, 10U, 20U, 25U, 30U
} ;                                    /* Creep������D��������Ť������ʱ��б������MAP��Z��(Ϊ�˽�����������,��λΪNm/100ms) */

CAL_TQM uint8_T u1_CT_TQF_GearDCreepModRegenTqDecZRat_Nmps[25] =
{
    2U, 5U, 5U, 5U, 5U, 2U, 5U, 10U, 10U, 10U, 2U, 5U, 10U, 20U, 20U, 2U, 5U,
    10U, 20U, 30U, 2U, 5U, 10U, 20U, 30U
} ;                                    /* Creep������D���������ƶ�Ť�ؼ�Сʱ��б������MAP��Z��(Ϊ�˽�����������,��λΪNm/100ms) */

CAL_TQM uint8_T u1_CT_TQF_GearDCreepModRegenTqIncZRat_Nmps[25] =
{
    5U, 5U, 5U, 5U, 5U, 15U, 15U, 15U, 15U, 15U, 20U, 30U, 30U, 30U, 30U, 20U,
    40U, 40U, 40U, 40U, 20U, 40U, 50U, 60U, 60U
} ;                                    /* Creep������D���������ƶ�Ť������ʱ��б������MAP��Z��(Ϊ�˽�����������,��λΪNm/100ms) */

CAL_TQM uint8_T u1_CT_TQF_GearRAccPdlModEcoDriveTqDecZRat_Nmps[25] =
{
    5U, 5U, 5U, 5U, 5U, 10U, 15U, 15U, 15U, 15U, 10U, 20U, 30U, 30U, 30U, 10U,
    20U, 30U, 50U, 50U, 10U, 20U, 30U, 50U, 80U
} ;                                    /* AccelPedal������R��ECOģʽ������Ť�ؼ�Сʱ��б������MAP��Z��(Ϊ�˽�����������,��λΪNm/100ms)(Ϊ�˽�����������,��λΪNm/100ms) */

CAL_TQM uint8_T u1_CT_TQF_GearRAccPdlModEcoDriveTqIncZRat_Nmps[25] =
{
    5U, 5U, 5U, 5U, 5U, 5U, 10U, 10U, 10U, 10U, 5U, 10U, 15U, 15U, 15U, 5U, 10U,
    20U, 20U, 20U, 5U, 10U, 20U, 25U, 30U
} ;                                    /* AccelPedal������R��ECOģʽ������Ť������ʱ��б������MAP��Z��(Ϊ�˽�����������,��λΪNm/100ms)(Ϊ�˽�����������,��λΪNm/100ms) */

CAL_TQM uint8_T u1_CT_TQF_GearRAccPdlModEcoRegenTqDecZRat_Nmps[25] =
{
    2U, 5U, 5U, 5U, 5U, 2U, 5U, 10U, 10U, 10U, 2U, 5U, 10U, 20U, 20U, 2U, 5U,
    10U, 20U, 30U, 2U, 5U, 10U, 20U, 30U
} ;                                    /* AccelPedal������R��ECOģʽ�������ƶ�Ť�ؼ�Сʱ��б������MAP��Z��(Ϊ�˽�����������,��λΪNm/100ms) */

CAL_TQM uint8_T u1_CT_TQF_GearRAccPdlModEcoRegenTqIncZRat_Nmps[25] =
{
    5U, 5U, 5U, 5U, 5U, 15U, 15U, 15U, 15U, 15U, 20U, 30U, 30U, 30U, 30U, 20U,
    40U, 40U, 40U, 40U, 20U, 40U, 50U, 60U, 60U
} ;                                    /* AccelPedal������R��ECOģʽ�������ƶ�Ť������ʱ��б������MAP��Z��(Ϊ�˽�����������,��λΪNm/100ms) */

CAL_TQM uint8_T u1_CT_TQF_GearRAccPdlModSportDriveTqDecZRat_Nmps[25] =
{
    5U, 5U, 5U, 5U, 5U, 10U, 15U, 15U, 15U, 15U, 10U, 20U, 30U, 30U, 30U, 10U,
    20U, 30U, 50U, 50U, 10U, 20U, 30U, 50U, 80U
} ;                                    /* AccelPedal������R��SPORTģʽ������Ť�ؼ�Сʱ��б������MAP��Z��(Ϊ�˽�����������,��λΪNm/100ms) */

CAL_TQM uint8_T u1_CT_TQF_GearRAccPdlModSportDriveTqIncZRat_Nmps[25] =
{
    5U, 5U, 5U, 5U, 5U, 5U, 10U, 10U, 10U, 10U, 5U, 10U, 20U, 20U, 20U, 5U, 10U,
    20U, 30U, 30U, 5U, 10U, 20U, 30U, 40U
} ;                                    /* AccelPedal������R��SPORTģʽ������Ť������ʱ��б������MAP��Z��(Ϊ�˽�����������,��λΪNm/100ms) */

CAL_TQM uint8_T u1_CT_TQF_GearRAccPdlModSportRegenTqDecZRat_Nmps[25] =
{
    2U, 5U, 5U, 5U, 5U, 2U, 5U, 10U, 10U, 10U, 2U, 5U, 10U, 20U, 20U, 2U, 5U,
    10U, 20U, 30U, 2U, 5U, 10U, 20U, 30U
} ;                                    /* AccelPedal������R��SPORTģʽ�������ƶ�Ť�ؼ�Сʱ��б������MAP��Z��(Ϊ�˽�����������,��λΪNm/100ms) */

CAL_TQM uint8_T u1_CT_TQF_GearRAccPdlModSportRegenTqIncZRat_Nmps[25] =
{
    5U, 5U, 5U, 5U, 5U, 15U, 15U, 15U, 15U, 15U, 20U, 30U, 30U, 30U, 30U, 20U,
    40U, 40U, 40U, 40U, 20U, 40U, 50U, 60U, 60U
} ;                                    /* AccelPedal������R��SPORTģʽ�������ƶ�Ť������ʱ��б������MAP��Z��(Ϊ�˽�����������,��λΪNm/100ms) */

CAL_TQM uint8_T u1_CT_TQF_GearRCreepModDriveTqDecZRat_Nmps[25] =
{
    5U, 5U, 5U, 5U, 5U, 10U, 15U, 15U, 15U, 15U, 10U, 20U, 30U, 30U, 30U, 10U,
    20U, 30U, 50U, 50U, 10U, 20U, 30U, 50U, 80U
} ;                                    /* Creep������R��������Ť�ؼ�Сʱ��б������MAP��Z��(Ϊ�˽�����������,��λΪNm/100ms) */

CAL_TQM uint8_T u1_CT_TQF_GearRCreepModDriveTqIncZRat_Nmps[25] =
{
    5U, 5U, 5U, 5U, 5U, 5U, 10U, 10U, 10U, 10U, 5U, 10U, 15U, 15U, 15U, 5U, 10U,
    20U, 20U, 20U, 5U, 10U, 20U, 25U, 30U
} ;                                    /* Creep������R��������Ť������ʱ��б������MAP��Z��(Ϊ�˽�����������,��λΪNm/100ms) */

CAL_TQM uint8_T u1_CT_TQF_GearRCreepModRegenTqDecZRat_Nmps[25] =
{
    2U, 5U, 5U, 5U, 5U, 2U, 5U, 10U, 10U, 10U, 2U, 5U, 10U, 20U, 20U, 2U, 5U,
    10U, 20U, 30U, 2U, 5U, 10U, 20U, 30U
} ;                                    /* Creep������R���������ƶ�Ť�ؼ�Сʱ��б������MAP��Z��(Ϊ�˽�����������,��λΪNm/100ms) */

CAL_TQM uint8_T u1_CT_TQF_GearRCreepModRegenTqIncZRat_Nmps[25] =
{
    5U, 5U, 5U, 5U, 5U, 15U, 15U, 15U, 15U, 15U, 20U, 30U, 30U, 30U, 30U, 20U,
    40U, 40U, 40U, 40U, 20U, 40U, 50U, 60U, 60U
} ;                                    /* Creep������R���������ƶ�Ť������ʱ��б������MAP��Z��(Ϊ�˽�����������,��λΪNm/100ms) */

CAL_TQM uint8_T u1_CT_TQF_HDCModDriveTqDecZRat_Nmps[25] =
{
    5U, 5U, 5U, 5U, 5U, 10U, 15U, 15U, 15U, 15U, 10U, 20U, 30U, 30U, 30U, 10U,
    20U, 30U, 50U, 50U, 10U, 20U, 30U, 50U, 80U
} ;                                    /* HDC�����µ�����Ť�ؼ�Сʱ��б������MAP��Z��(��λ��Nm/100ms) */

CAL_TQM uint8_T u1_CT_TQF_HDCModDriveTqIncZRat_Nmps[25] =
{
    5U, 5U, 5U, 5U, 5U, 5U, 10U, 10U, 10U, 10U, 5U, 10U, 15U, 15U, 15U, 5U, 10U,
    20U, 20U, 20U, 5U, 10U, 20U, 25U, 30U
} ;                                    /* HDC�����µ�����Ť������ʱ��б������MAP��Z��(��λ��Nm/100ms) */

CAL_TQM uint8_T u1_CT_TQF_HDCModRegenTqDecZRat_Nmps[25] =
{
    5U, 5U, 5U, 5U, 5U, 15U, 15U, 15U, 15U, 15U, 20U, 30U, 30U, 30U, 30U, 20U,
    40U, 40U, 40U, 40U, 20U, 40U, 50U, 60U, 60U
} ;                                    /* HDC�����µ������ƶ�Ť�ؼ�Сʱ��б������MAP��Z��(��λ��Nm/100ms) */

CAL_TQM uint8_T u1_CT_TQF_HDCModRegenTqIncZRat_Nmps[25] =
{
    5U, 5U, 5U, 5U, 5U, 15U, 15U, 15U, 15U, 15U, 20U, 30U, 30U, 30U, 30U, 20U,
    40U, 40U, 40U, 40U, 20U, 40U, 50U, 60U, 60U
} ;                                    /* HDC�����µ������ƶ�Ť������ʱ��б������MAP��Z��(��λ��Nm/100ms) */

CAL_TQM uint8_T u1_CT_TQF_HighRegenModDriveTqDecZRat_Nmps[25] =
{
    5U, 5U, 5U, 5U, 5U, 10U, 15U, 15U, 15U, 15U, 10U, 20U, 30U, 30U, 30U, 10U,
    20U, 30U, 50U, 50U, 10U, 20U, 30U, 50U, 80U
} ;                                    /* �߼�Regen�����µ�����Ť�ؼ�Сʱ��б������MAP��Z��(Ϊ�˽�����������,��λΪNm/100ms) */

CAL_TQM uint8_T u1_CT_TQF_HighRegenModDriveTqIncZRat_Nmps[25] =
{
    5U, 5U, 5U, 5U, 5U, 5U, 10U, 10U, 10U, 10U, 5U, 10U, 15U, 15U, 15U, 5U, 10U,
    20U, 20U, 20U, 5U, 10U, 20U, 25U, 30U
} ;                                    /* �߼�Regen�����µ�����Ť������ʱ��б������MAP��Z��(Ϊ�˽�����������,��λΪNm/100ms) */

CAL_TQM uint8_T u1_CT_TQF_HighRegenModRegenTqDecZRat_Nmps[25] =
{
    2U, 5U, 5U, 5U, 5U, 2U, 5U, 10U, 10U, 10U, 2U, 5U, 10U, 20U, 20U, 2U, 5U,
    10U, 20U, 30U, 2U, 5U, 10U, 20U, 30U
} ;                                    /* �߼�Regen�����µ������ƶ�Ť�ؼ�Сʱ��б������MAP��Z��(Ϊ�˽�����������,��λΪNm/100ms) */

CAL_TQM uint8_T u1_CT_TQF_HighRegenModRegenTqIncZRat_Nmps[25] =
{
    5U, 5U, 5U, 5U, 5U, 15U, 15U, 15U, 15U, 15U, 20U, 30U, 30U, 30U, 30U, 20U,
    40U, 40U, 40U, 40U, 20U, 40U, 50U, 60U, 60U
} ;                                    /* �߼�egen�����µ������ƶ�Ť������ʱ��б������MAP��Z��(Ϊ�˽�����������,��λΪNm/100ms) */

CAL_TQM uint8_T u1_CT_TQF_LowRegenModDriveTqDecZRat_Nmps[25] =
{
    5U, 5U, 5U, 5U, 5U, 10U, 15U, 15U, 15U, 15U, 10U, 20U, 30U, 30U, 30U, 10U,
    20U, 30U, 50U, 50U, 10U, 20U, 30U, 50U, 80U
} ;                                    /* �ͼ�Regen�����µ�����Ť�ؼ�Сʱ��б������MAP��Z��(Ϊ�˽�����������,��λΪNm/100ms) */

CAL_TQM uint8_T u1_CT_TQF_LowRegenModDriveTqIncZRat_Nmps[25] =
{
    5U, 5U, 5U, 5U, 5U, 5U, 10U, 10U, 10U, 10U, 5U, 10U, 15U, 15U, 15U, 5U, 10U,
    20U, 20U, 20U, 5U, 10U, 20U, 25U, 30U
} ;                                    /* �ͼ�Regen�����µ�����Ť������ʱ��б������MAP��Z��(Ϊ�˽�����������,��λΪNm/100ms) */

CAL_TQM uint8_T u1_CT_TQF_LowRegenModRegenTqDecZRat_Nmps[25] =
{
    2U, 5U, 5U, 5U, 5U, 2U, 5U, 10U, 10U, 10U, 2U, 5U, 10U, 20U, 20U, 2U, 5U,
    10U, 20U, 30U, 2U, 5U, 10U, 20U, 30U
} ;                                    /* �ͼ�Regen�����µ������ƶ�Ť�ؼ�Сʱ��б������MAP��Z��(Ϊ�˽�����������,��λΪNm/100ms) */

CAL_TQM uint8_T u1_CT_TQF_LowRegenModRegenTqIncZRat_Nmps[25] =
{
    5U, 5U, 5U, 5U, 5U, 15U, 15U, 15U, 15U, 15U, 20U, 30U, 30U, 30U, 30U, 20U,
    40U, 40U, 40U, 40U, 20U, 40U, 50U, 60U, 60U
} ;                                    /* �ͼ�egen�����µ������ƶ�Ť������ʱ��б������MAP��Z��(Ϊ�˽�����������,��λΪNm/100ms) */

CAL_TQM uint8_T u1_CT_TQF_NedcModDriveTqDecZRat_Nmps[25] =
{
    5U, 5U, 5U, 5U, 5U, 10U, 15U, 15U, 15U, 15U, 10U, 20U, 30U, 30U, 30U, 10U,
    20U, 30U, 50U, 50U, 10U, 20U, 30U, 50U, 80U
} ;                                    /* NEDC�����µ�����Ť�ؼ�Сʱ��б������MAP��Z��(Ϊ�˽�����������,��λΪNm/100ms) */

CAL_TQM uint8_T u1_CT_TQF_NedcModDriveTqIncZRat_Nmps[25] =
{
    5U, 5U, 5U, 5U, 5U, 5U, 10U, 10U, 10U, 10U, 5U, 10U, 15U, 15U, 15U, 5U, 10U,
    20U, 20U, 20U, 5U, 10U, 20U, 25U, 30U
} ;                                    /* NEDC�����µ�����Ť������ʱ��б������MAP��Z��(Ϊ�˽�����������,��λΪNm/100ms) */

CAL_TQM uint8_T u1_CT_TQF_NedcModRegenTqDecZRat_Nmps[25] =
{
    2U, 5U, 5U, 5U, 5U, 2U, 5U, 10U, 10U, 10U, 2U, 5U, 10U, 20U, 20U, 2U, 5U,
    10U, 20U, 30U, 2U, 5U, 10U, 20U, 30U
} ;                                    /* NEDC�����µ������ƶ�Ť�ؼ�Сʱ��б������MAP��Z��(Ϊ�˽�����������,��λΪNm/100ms) */

CAL_TQM uint8_T u1_CT_TQF_NedcModRegenTqIncZRat_Nmps[25] =
{
    5U, 5U, 5U, 5U, 5U, 15U, 15U, 15U, 15U, 15U, 20U, 30U, 30U, 30U, 30U, 20U,
    40U, 40U, 40U, 40U, 20U, 40U, 50U, 60U, 60U
} ;                                    /* NEDC�����µ������ƶ�Ť������ʱ��б������MAP��Z��(Ϊ�˽�����������,��λΪNm/100ms) */

CAL_TQM uint8_T u1_C_Booster_En = 1U;
CAL_TQM uint8_T u1_C_ESC_ESP_En = 2U;  /* 0:��ABS 1��ABS 2:ESP */
CAL_TQM boolean_T u1_C_ESC_EscEnableFlg = 0;/* ESCʹ�ܿ���(0:�رա�1������) */
CAL_TQM uint8_T u1_C_ESC_EscIncEnaFlg = 0U;/* ESC��Ťʹ�ܿ���(0:�رա�1������) */
CAL_TQM boolean_T u1_C_HDC_En = 1;     /* HDC����������ʹ�� */
CAL_TQM uint8_T u1_C_TQF_AbsModDriveTqDecRat_Nmps = 255U;/* ABS������Ĭ��ֵ */
CAL_TQM uint8_T u1_C_TQF_AbsModDriveTqIncRat_Nmps = 255U;/* ABS������Ĭ��ֵ */
CAL_TQM uint8_T u1_C_TQF_DefModGearPNRat_Nmps = 40U;/* Deafult������P/N��Ť��ж��б������(Ϊ�˽�����������,��λΪNm/100ms) */
CAL_TQM uint8_T u1_C_TQF_DefModSteadyDecRat_Nmps = 10U;/* Deafult������Ť���½�Ĭ��б�ʡ���Ť�ش�����̬(Ϊ�˽�����������,��λΪNm/100ms) */
CAL_TQM uint8_T u1_C_TQF_DefModSteadyIncRat_Nmps = 10U;/* Deafult������Ť������Ĭ��б�ʡ���Ť�ش�����̬(Ϊ�˽�����������,��λΪNm/100ms) */
CAL_TQM boolean_T u1_C_TQF_UseFilterRateNewArch = 0;/* �Ƿ�ʹ�þ�ϸ��Ť���˲���1����ʾʹ�þ�ϸ��Ť���˲��� */
CAL_TQM real32_T u1_C_TQM_MCUTqMaxFactor = 0.7F;/* MCU��Ťϵ����ֵ(0.9-������) */
CAL_TQM int16_T u2_CT_TQF_AbsModRegenTqDecXOldTq_Nm[5] =
{
    0, 97, 161, 321, 641
} ;                                    /* Creep�����µ������ƶ�Ť�ؼ�Сʱ��б������MAP��X��(ǰ�����Ť�صľ���ֵ) */

CAL_TQM int16_T u2_CT_TQF_AbsModRegenTqDecYTqDiff_Nm[5] =
{
    0, 161, 321, 641, 961
} ;                                    /* Creep�����µ������ƶ�Ť�ؼ�Сʱ��б������MAP��Y��((�������Ť�� - ǰ�����Ť��ֵ)�ľ���ֵ) */

CAL_TQM int16_T u2_CT_TQF_AccPdlModEcoDriveTqDecXOldTq_Nm[5] =
{
    0, 97, 161, 321, 641
} ;                                    /* AccelPedal������ECOģʽ������Ť�ؼ�Сʱ��б������MAP��X��(ǰ�����Ť�صľ���ֵ) */

CAL_TQM int16_T u2_CT_TQF_AccPdlModEcoDriveTqDecYTqDiff_Nm[5] =
{
    0, 161, 321, 641, 961
} ;                                    /* AccelPedal������ECOģʽ������Ť�ؼ�Сʱ��б������MAP��Y��((�������Ť�� - ǰ�����Ť��ֵ)�ľ���ֵ) */

CAL_TQM int16_T u2_CT_TQF_AccPdlModEcoDriveTqIncXOldTq_Nm[5] =
{
    0, 97, 161, 321, 641
} ;                                    /* AccelPedal������ECOģʽ������Ť������ʱ��б������MAP��X��(ǰ�����Ť�صľ���ֵ) */

CAL_TQM int16_T u2_CT_TQF_AccPdlModEcoDriveTqIncYTqDiff_Nm[5] =
{
    0, 161, 321, 641, 1601
} ;                                    /* AccelPedal������ECOģʽ������Ť������ʱ��б������MAP��Y��((�������Ť�� - ǰ�����Ť��ֵ)�ľ���ֵ) */

CAL_TQM int16_T u2_CT_TQF_AccPdlModEcoRegenTqDecXOldTq_Nm[5] =
{
    0, 97, 161, 321, 641
} ;                                    /* AccelPedal������ECOģʽ�������ƶ�Ť�ؼ�Сʱ��б������MAP��X��(ǰ�����Ť�صľ���ֵ) */

CAL_TQM int16_T u2_CT_TQF_AccPdlModEcoRegenTqDecYTqDiff_Nm[5] =
{
    0, 161, 321, 641, 961
} ;                                    /* AccelPedal������ECOģʽ�������ƶ�Ť�ؼ�Сʱ��б������MAP��Y��((�������Ť�� - ǰ�����Ť��ֵ)�ľ���ֵ) */

CAL_TQM int16_T u2_CT_TQF_AccPdlModEcoRegenTqIncXOldTq_Nm[5] =
{
    0, 97, 161, 321, 641
} ;                                    /* AccelPedal������ECOģʽ�������ƶ�Ť������ʱ��б������MAP��X��(ǰ�����Ť�صľ���ֵ) */

CAL_TQM int16_T u2_CT_TQF_AccPdlModEcoRegenTqIncYTqDiff_Nm[5] =
{
    0, 161, 321, 641, 961
} ;                                    /* AccelPedal������ECOģʽ�������ƶ�Ť������ʱ��б������MAP��Y��((�������Ť�� - ǰ�����Ť��ֵ)�ľ���ֵ) */

CAL_TQM int16_T u2_CT_TQF_AccPdlModSportDriveTqDecXOldTq_Nm[5] =
{
    0, 97, 161, 321, 641
} ;                                    /* AccelPedal������SPORTģʽ������Ť�ؼ�Сʱ��б������MAP��X��(ǰ�����Ť�صľ���ֵ) */

CAL_TQM int16_T u2_CT_TQF_AccPdlModSportDriveTqDecYTqDiff_Nm[5] =
{
    0, 161, 321, 641, 961
} ;                                    /* AccelPedal������SPORTģʽ������Ť�ؼ�Сʱ��б������MAP��Y��((�������Ť�� - ǰ�����Ť��ֵ)�ľ���ֵ) */

CAL_TQM int16_T u2_CT_TQF_AccPdlModSportDriveTqIncXOldTq_Nm[5] =
{
    0, 97, 161, 321, 641
} ;                                    /* AccelPedal������SPORTģʽ������Ť������ʱ��б������MAP��X��(ǰ�����Ť�صľ���ֵ) */

CAL_TQM int16_T u2_CT_TQF_AccPdlModSportDriveTqIncYTqDiff_Nm[5] =
{
    0, 161, 321, 641, 1281
} ;                                    /* AccelPedal������SPORTģʽ������Ť������ʱ��б������MAP��Y��((�������Ť�� - ǰ�����Ť��ֵ)�ľ���ֵ) */

CAL_TQM int16_T u2_CT_TQF_AccPdlModSportRegenTqDecXOldTq_Nm[5] =
{
    0, 97, 161, 321, 641
} ;                                    /* AccelPedal������SPORTģʽ�������ƶ�Ť�ؼ�Сʱ��б������MAP��X��(ǰ�����Ť�صľ���ֵ) */

CAL_TQM int16_T u2_CT_TQF_AccPdlModSportRegenTqDecYTqDiff_Nm[5] =
{
    0, 161, 321, 641, 961
} ;                                    /* AccelPedal������SPORTģʽ�������ƶ�Ť�ؼ�Сʱ��б������MAP��Y��((�������Ť�� - ǰ�����Ť��ֵ)�ľ���ֵ) */

CAL_TQM int16_T u2_CT_TQF_AccPdlModSportRegenTqIncXOldTq_Nm[5] =
{
    0, 97, 161, 321, 641
} ;                                    /* AccelPedal������SPORTģʽ�������ƶ�Ť������ʱ��б������MAP��X��(ǰ�����Ť�صľ���ֵ) */

CAL_TQM int16_T u2_CT_TQF_AccPdlModSportRegenTqIncYTqDiff_Nm[5] =
{
    0, 161, 321, 641, 961
} ;                                    /* AccelPedal������SPORTģʽ�������ƶ�Ť������ʱ��б������MAP��Y��((�������Ť�� - ǰ�����Ť��ֵ)�ľ���ֵ) */

CAL_TQM int16_T u2_CT_TQF_CreepModDriveTqDecXOldTq_Nm[5] =
{
    0, 97, 161, 321, 641
} ;                                    /* Creep�����µ�����Ť�ؼ�Сʱ��б������MAP��X��(ǰ�����Ť�صľ���ֵ) */

CAL_TQM int16_T u2_CT_TQF_CreepModDriveTqDecYTqDiff_Nm[5] =
{
    0, 161, 321, 641, 961
} ;                                    /* Creep�����µ�����Ť�ؼ�Сʱ��б������MAP��Y��((�������Ť�� - ǰ�����Ť��ֵ)�ľ���ֵ) */

CAL_TQM int16_T u2_CT_TQF_CreepModDriveTqIncXOldTq_Nm[5] =
{
    0, 97, 161, 321, 641
} ;                                    /* Creep�����µ�����Ť������ʱ��б������MAP��X��(ǰ�����Ť�صľ���ֵ) */

CAL_TQM int16_T u2_CT_TQF_CreepModDriveTqIncYTqDiff_Nm[5] =
{
    0, 161, 321, 641, 1601
} ;                                    /* Creep�����µ�����Ť������ʱ��б������MAP��Y��((�������Ť�� - ǰ�����Ť��ֵ)�ľ���ֵ) */

CAL_TQM int16_T u2_CT_TQF_CreepModRegenTqDecXOldTq_Nm[5] =
{
    0, 97, 161, 321, 641
} ;                                    /* Creep�����µ������ƶ�Ť�ؼ�Сʱ��б������MAP��X��(ǰ�����Ť�صľ���ֵ) */

CAL_TQM int16_T u2_CT_TQF_CreepModRegenTqDecYTqDiff_Nm[5] =
{
    0, 161, 321, 641, 961
} ;                                    /* Creep�����µ������ƶ�Ť�ؼ�Сʱ��б������MAP��Y��((�������Ť�� - ǰ�����Ť��ֵ)�ľ���ֵ) */

CAL_TQM int16_T u2_CT_TQF_CreepModRegenTqIncXOldTq_Nm[5] =
{
    0, 97, 161, 321, 641
} ;                                    /* Creep�����µ������ƶ�Ť������ʱ��б������MAP��X��(ǰ�����Ť�صľ���ֵ) */

CAL_TQM int16_T u2_CT_TQF_CreepModRegenTqIncYTqDiff_Nm[5] =
{
    0, 161, 321, 641, 961
} ;                                    /* Creep�����µ������ƶ�Ť������ʱ��б������MAP��Y��((�������Ť�� - ǰ�����Ť��ֵ)�ľ���ֵ) */

CAL_TQM int16_T u2_CT_TQF_HDCModDriveTqDecXOldTq_Nm[5] =
{
    0, 97, 161, 321, 641
} ;                                    /* HDC�����µ�����Ť�ؼ�Сʱ��б������MAP��X��(ǰ�����Ť�صľ���ֵ) */

CAL_TQM int16_T u2_CT_TQF_HDCModDriveTqDecYTqDiff_Nm[5] =
{
    0, 161, 321, 641, 961
} ;                                    /* HDC�����µ�����Ť�ؼ�Сʱ��б������MAP��Y��((�������Ť�� - ǰ�����Ť��ֵ)�ľ���ֵ) */

CAL_TQM int16_T u2_CT_TQF_HDCModDriveTqIncXOldTq_Nm[5] =
{
    0, 97, 161, 321, 641
} ;                                    /* HDC�����µ�����Ť������ʱ��б������MAP��X��(ǰ�����Ť�صľ���ֵ) */

CAL_TQM int16_T u2_CT_TQF_HDCModDriveTqIncYTqDiff_Nm[5] =
{
    0, 161, 321, 641, 1601
} ;                                    /* HDC�����µ�����Ť������ʱ��б������MAP��Y��((�������Ť�� - ǰ�����Ť��ֵ)�ľ���ֵ) */

CAL_TQM int16_T u2_CT_TQF_HDCModRegenTqDecXOldTq_Nm[5] =
{
    0, 97, 161, 321, 641
} ;                                    /* HDC�����µ������ƶ�Ť�ؼ�Сʱ��б������MAP��X��(ǰ�����Ť�صľ���ֵ) */

CAL_TQM int16_T u2_CT_TQF_HDCModRegenTqDecYTqDiff_Nm[5] =
{
    0, 161, 321, 641, 961
} ;                                    /* HDC�����µ������ƶ�Ť�ؼ�Сʱ��б������MAP��Y��((�������Ť�� - ǰ�����Ť��ֵ)�ľ���ֵ) */

CAL_TQM int16_T u2_CT_TQF_HDCModRegenTqIncXOldTq_Nm[5] =
{
    0, 97, 161, 321, 641
} ;                                    /* HDC�����µ������ƶ�Ť������ʱ��б������MAP��X��(ǰ�����Ť�صľ���ֵ) */

CAL_TQM int16_T u2_CT_TQF_HDCModRegenTqIncYTqDiff_Nm[5] =
{
    0, 161, 321, 641, 961
} ;                                    /* HDC�����µ������ƶ�Ť������ʱ��б������MAP��Y��((�������Ť�� - ǰ�����Ť��ֵ)�ľ���ֵ) */

CAL_TQM int16_T u2_CT_TQF_NedcModDriveTqDecXOldTq_Nm[5] =
{
    0, 97, 161, 321, 641
} ;                                    /* NEDC�����µ�����Ť�ؼ�Сʱ��б������MAP��X��(ǰ�����Ť�صľ���ֵ) */

CAL_TQM int16_T u2_CT_TQF_NedcModDriveTqDecYTqDiff_Nm[5] =
{
    0, 161, 321, 641, 961
} ;                                    /* NEDC�����µ�����Ť�ؼ�Сʱ��б������MAP��Y��((�������Ť�� - ǰ�����Ť��ֵ)�ľ���ֵ) */

CAL_TQM int16_T u2_CT_TQF_NedcModDriveTqIncXOldTq_Nm[5] =
{
    0, 97, 161, 321, 641
} ;                                    /* NEDC�����µ�����Ť������ʱ��б������MAP��X��(ǰ�����Ť�صľ���ֵ) */

CAL_TQM int16_T u2_CT_TQF_NedcModDriveTqIncYTqDiff_Nm[5] =
{
    0, 161, 321, 641, 961
} ;                                    /* NEDC�����µ�����Ť������ʱ��б������MAP��Y��((�������Ť�� - ǰ�����Ť��ֵ)�ľ���ֵ) */

CAL_TQM int16_T u2_CT_TQF_NedcModRegenTqDecXOldTq_Nm[5] =
{
    0, 97, 161, 321, 641
} ;                                    /* NEDC�����µ������ƶ�Ť�ؼ�Сʱ��б������MAP��X��(ǰ�����Ť�صľ���ֵ) */

CAL_TQM int16_T u2_CT_TQF_NedcModRegenTqDecYTqDiff_Nm[5] =
{
    0, 161, 321, 641, 961
} ;                                    /* NEDC�����µ������ƶ�Ť�ؼ�Сʱ��б������MAP��Y��((�������Ť�� - ǰ�����Ť��ֵ)�ľ���ֵ) */

CAL_TQM int16_T u2_CT_TQF_NedcModRegenTqIncXOldTq_Nm[5] =
{
    0, 97, 161, 321, 641
} ;                                    /* NEDC�����µ������ƶ�Ť������ʱ��б������MAP��X��(ǰ�����Ť�صľ���ֵ) */

CAL_TQM int16_T u2_CT_TQF_NedcModRegenTqIncYTqDiff_Nm[5] =
{
    0, 161, 321, 641, 961
} ;                                    /* NEDC�����µ������ƶ�Ť������ʱ��б������MAP��Y��((�������Ť�� - ǰ�����Ť��ֵ)�ľ���ֵ) */

CAL_TQM int16_T u2_CT_TQF_RegenModDriveTqDecXOldTq_Nm[5] =
{
    0, 97, 161, 321, 641
} ;                                    /* Regen�����µ�����Ť�ؼ�Сʱ��б������MAP��X��(ǰ�����Ť�صľ���ֵ) */

CAL_TQM int16_T u2_CT_TQF_RegenModDriveTqDecYTqDiff_Nm[5] =
{
    0, 161, 321, 641, 961
} ;                                    /* Regen�����µ�����Ť�ؼ�Сʱ��б������MAP��Y��((�������Ť�� - ǰ�����Ť��ֵ)�ľ���ֵ) */

CAL_TQM int16_T u2_CT_TQF_RegenModDriveTqIncXOldTq_Nm[5] =
{
    0, 97, 161, 321, 641
} ;                                    /* Regen�����µ�����Ť������ʱ��б������MAP��X��(ǰ�����Ť�صľ���ֵ) */

CAL_TQM int16_T u2_CT_TQF_RegenModDriveTqIncYTqDiff_Nm[5] =
{
    0, 161, 321, 641, 1601
} ;                                    /* Regen�����µ�����Ť������ʱ��б������MAP��Y��((�������Ť�� - ǰ�����Ť��ֵ)�ľ���ֵ) */

CAL_TQM int16_T u2_CT_TQF_RegenModRegenTqDecXOldTq_Nm[5] =
{
    0, 97, 161, 321, 641
} ;                                    /* Regen�����µ������ƶ�Ť�ؼ�Сʱ��б������MAP��X��(ǰ�����Ť�صľ���ֵ) */

CAL_TQM int16_T u2_CT_TQF_RegenModRegenTqDecYTqDiff_Nm[5] =
{
    0, 161, 321, 641, 961
} ;                                    /* Regen�����µ������ƶ�Ť�ؼ�Сʱ��б������MAP��Y��((�������Ť�� - ǰ�����Ť��ֵ)�ľ���ֵ) */

CAL_TQM int16_T u2_CT_TQF_RegenModRegenTqIncXOldTq_Nm[5] =
{
    0, 97, 161, 321, 641
} ;                                    /* Regen�����µ������ƶ�Ť������ʱ��б������MAP��X��(ǰ�����Ť�صľ���ֵ) */

CAL_TQM int16_T u2_CT_TQF_RegenModRegenTqIncYTqDiff_Nm[5] =
{
    0, 161, 321, 641, 961
} ;                                    /* Regen�����µ������ƶ�Ť������ʱ��б������MAP��Y��((�������Ť�� - ǰ�����Ť��ֵ)�ľ���ֵ) */

CAL_TQM real32_T u2_C_ASM_DecMotTq_Step = 10.0F;/* MCU����Ť���˳����� */
CAL_TQM real32_T u2_C_ASM_MinTq = 3.0F;/* MCU����Ť���˳���Сֵ */
CAL_TQM uint16_T u2_C_GearBoxDelayTime = 15U;/* �ֶ������͵�λȷ��������ֵ */
CAL_TQM uint16_T u2_C_TQM_MCUTqDiffDlyTime = 1000U;/* ����Ť����ʵ��Ť�صĲ�ֵ�ж�ʱ����ֵ */
CAL_TQM uint16_T u2_C_VSP_ActAclLowPassFilter_ms = 80U;/* ���ٶ�һ���˲�ϵ�� */
CAL_TQM int16_T up_inc_limit = 200;    /* б�����Ʋ���Ť������ֵ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

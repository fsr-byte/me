/*
 * File: TQFRate_model_types.h
 *
 * Code generated for Simulink model 'TQFRate_model'.
 *
 * Model version                  : 1.1651
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Fri Mar 18 15:48:25 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Freescale->32-bit PowerPC
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. MISRA C:2012 guidelines
 * Validation result: Not run
 */

#ifndef RTW_HEADER_TQFRate_model_types_h_
#define RTW_HEADER_TQFRate_model_types_h_
#include "rtwtypes.h"
#ifndef DEFINED_TYPEDEF_FOR_TQM_
#define DEFINED_TYPEDEF_FOR_TQM_

typedef struct {
  boolean_T TQM_Reverse_Light_Sts;
  boolean_T TQM_Brake_LampSts;
  uint8_T TQM_MCU_ModeReq;
  int16_T TQM_MotSpdReq;
  real32_T TQM_VehTq;
  real32_T TQM_TSC_VehTq;
  boolean_T TQM_MCUAntishake;
  boolean_T b1_M_TQM_TqArbitration;
  boolean_T TQM_AntiSlipFunEn;
  uint8_T TQM_WorkMode;
  real32_T TQM_DriverDmdTq_Nm;
  real32_T TQM_CoastRegenTq_Nm;
  real32_T TQM_TQDDriverDmdTq_Nm;
  int16_T TQM_BrakeRegenTq_Ava;
  boolean_T TQM_BrakeRegenTq_Ava_Valid;
  uint8_T TQM_GearR_SpdLim_Low;
  uint8_T TQM_GearD_SpdLim_Low;
  int16_T TQM_ENM_TqDrive_Lim;
  int16_T TQM_AntiSlip_Tq_Lim;
  real32_T TQM_SpdLimTq_Nm;
  real32_T TQM_TQRVehTq_Nm;
  boolean_T TQM_VehSpd_Valid;
  real32_T TQM_AccePct;
  int16_T TQM_VCU_AvTq_Max;
  int16_T TQM_VCU_AvTq_Min;
  uint8_T TQM_Gear_Act;
  boolean_T TQM_GearPos_Valid;
  uint8_T TQM_GearDisp;
  boolean_T TQM_EPBAppliedReq;
  boolean_T TQM_EPBAppliedReqValid;
  uint8_T TQM_Driver_Remind;
  uint8_T TQM_CoastRegenGrade;
  boolean_T TQM_AccePct_Valid;
  real32_T TQM_Veh_Accel;
  real32_T TQM_Road_Angle;
  uint8_T TQM_VehOri;
  boolean_T TQM_AccePress_Flg;
  real32_T TQM_MotSpd;
  boolean_T TQM_MCU_Spd_Valid;
  boolean_T TQM_ABS_Spd_Valid;
  real32_T TQM_VehSpd;
  real32_T TQM_AcceleratedSpeed_mpss;
  boolean_T TQM_FrontSeatMotor_flg;
  boolean_T TQM_RearSeatMotor_flg;
} TQM;

#endif

#ifndef DEFINED_TYPEDEF_FOR_TQFRate_
#define DEFINED_TYPEDEF_FOR_TQFRate_

typedef struct {
  uint8_T u1_M_TQFRate_DriveTqIncRat_Nmps;
  uint8_T u1_M_TQFRate_DriveTqDecRat_Nmps;
  uint8_T u1_M_TQFRate_RegenTqIncRat_Nmps;
  uint8_T u1_M_TQFRate_RegenTqDecRat_Nmps;
} TQFRate;

#endif
#endif                                 /* RTW_HEADER_TQFRate_model_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

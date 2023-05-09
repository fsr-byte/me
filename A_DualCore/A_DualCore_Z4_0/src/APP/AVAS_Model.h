/*
 * File: AVAS_Model.h
 *
 * Code generated for Simulink model 'AVAS_Model'.
 *
 * Model version                  : 1.506
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Fri Mar 18 15:40:41 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Freescale->32-bit PowerPC
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 *    3. ROM efficiency
 *    4. MISRA C:2012 guidelines
 * Validation result: Not run
 */

#ifndef RTW_HEADER_AVAS_Model_h_
#define RTW_HEADER_AVAS_Model_h_
#include <math.h>
#include <stddef.h>
#include <string.h>
#ifndef AVAS_Model_COMMON_INCLUDES_
# define AVAS_Model_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#endif                                 /* AVAS_Model_COMMON_INCLUDES_ */

#include "AVAS_Model_types.h"

/* Includes for objects with custom storage classes. */
#include "AVAS_Cal_Data.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* user code (top of header file) */
#include "derivative.h"

/* Block signals (auto storage) */
typedef struct {
  uint32_T TaskTick;                   /* '<Root>/Time_Chart' */
  uint8_T work_mode;                   /* '<S3>/AVAS_chart' */
  boolean_T bis_DSM_SeatHallCntChg_flg_h;/* '<S7>/Chart' */
  boolean_T RelationalOperator1;       /* '<S2>/Relational Operator1' */
} B_AVAS_Model_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  uint32_T Delay2_DSTATE;              /* '<S1>/Delay2' */
  uint32_T Delay3_DSTATE;              /* '<S1>/Delay3' */
  uint32_T Delay2_DSTATE_h;            /* '<S7>/Delay2' */
  uint32_T Delay_DSTATE;               /* '<S2>/Delay' */
  uint32_T StartTime;                  /* '<Root>/Time_Chart' */
  int16_T Delay_DSTATE_j;              /* '<S15>/Delay' */
  int16_T Delay3_DSTATE_g;             /* '<S7>/Delay3' */
  uint16_T Delay_DSTATE_n;             /* '<S17>/Delay' */
  uint16_T Delay3_DSTATE_e;            /* '<S17>/Delay3' */
  uint16_T Delay_DSTATE_b;             /* '<S18>/Delay' */
  uint16_T Delay3_DSTATE_j;            /* '<S18>/Delay3' */
  uint16_T timer;                      /* '<S15>/Std_Mode' */
  uint16_T timer_j;                    /* '<S13>/Chart1' */
  uint16_T timer_c;                    /* '<S7>/Chart' */
  uint8_T Delay1_DSTATE;               /* '<S2>/Delay1' */
  boolean_T Delay1_DSTATE_m;           /* '<Root>/Delay1' */
  boolean_T Delay_DSTATE_k;            /* '<Root>/Delay' */
  boolean_T Delay1_DSTATE_e;           /* '<S17>/Delay1' */
  boolean_T Delay4_DSTATE;             /* '<S17>/Delay4' */
  boolean_T Delay2_DSTATE_b;           /* '<S17>/Delay2' */
  boolean_T Delay1_DSTATE_g;           /* '<S18>/Delay1' */
  boolean_T Delay4_DSTATE_k;           /* '<S18>/Delay4' */
  boolean_T Delay2_DSTATE_l;           /* '<S18>/Delay2' */
  boolean_T Delay1_DSTATE_i;           /* '<S15>/Delay1' */
  uint8_T icLoad;                      /* '<S1>/Delay2' */
  uint8_T is_active_c25_AVAS_Model;    /* '<Root>/Time_Chart' */
  uint8_T is_c25_AVAS_Model;           /* '<Root>/Time_Chart' */
  uint8_T icLoad_g;                    /* '<S7>/Delay2' */
  uint8_T icLoad_i;                    /* '<S15>/Delay1' */
  uint8_T icLoad_h;                    /* '<S15>/Delay' */
  uint8_T icLoad_c;                    /* '<S7>/Delay3' */
  uint8_T is_active_c7_AVAS_Model;     /* '<S15>/Std_Mode' */
  uint8_T is_c7_AVAS_Model;            /* '<S15>/Std_Mode' */
  uint8_T is_active_c6_AVAS_Model;     /* '<S13>/Chart1' */
  uint8_T is_c6_AVAS_Model;            /* '<S13>/Chart1' */
  uint8_T is_Normal_Mode;              /* '<S13>/Chart1' */
  uint8_T is_Standby;                  /* '<S13>/Chart1' */
  uint8_T is_active_c5_AVAS_Model;     /* '<S7>/Chart' */
  uint8_T is_c5_AVAS_Model;            /* '<S7>/Chart' */
  uint8_T is_active_c2_AVAS_Model;     /* '<S3>/AVAS_chart' */
  uint8_T is_c2_AVAS_Model;            /* '<S3>/AVAS_chart' */
} DW_AVAS_Model_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState ABS_232_MsgLostChk_Trig_ZCE;/* '<Root>/ABS_232_MsgLostChk' */
} PrevZCX_AVAS_Model_T;

/* Real-time Model Data Structure */
struct tag_RTM_AVAS_Model_T {
  const char_T *errorStatus;
};

/* Block signals (auto storage) */
#pragma push
#pragma DATA_SEG __GPAGE_SEG GPAGED_RAM

extern B_AVAS_Model_T AVAS_Model_B;

#pragma pop

/* Block states (auto storage) */

#pragma push
#pragma DATA_SEG __GPAGE_SEG GPAGED_RAM

extern DW_AVAS_Model_T AVAS_Model_DW;

#pragma pop

/* External data declarations for dependent source files */
#pragma push
#pragma DATA_SEG __GPAGE_SEG GPAGED_RAM

extern const AVAS AVAS_Model_rtZAVAS;  /* AVAS ground */

#pragma pop

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern uint32_T VHALI_SeatHallcnt;     /* '<Root>/VHALI_SeatHallcnt'
                                        * 座椅电机霍尔信号计数器
                                        */
extern boolean_T hIOP_FrontSeatMotorSwitch_flg;/* '<Root>/hIOP_FrontSeatMotorSwitch_flg'
                                                * INPUT座椅前电机控制开关信号
                                                */
extern boolean_T hIOP_RearSeatMotorSwitch_flg;/* '<Root>/hIOP_RearSeatMotorSwitch_flg'
                                               * INPUT座椅后电机控制开关信号
                                               */
extern AVAS AVAS_output;               /* '<Root>/Bus Creator1' */
extern int16_T u2s_DSM_ExportHistoryVal_Out;/* '<S13>/Chart1'
                                             * 迎宾态记忆位置
                                             */
extern int16_T u2s_DSM_ImportHistoryVal_Out;/* '<S13>/Chart1'
                                             * 驾驶态记忆位置
                                             */
extern int16_T u2s_DSM_SeatAxlePos_Out;/* '<S13>/Chart1'
                                        * 座椅当前位置
                                        */
extern uint8_T AVAS_LowSpdWarnEna;     /* '<Root>/Data Type Conversion' */
extern uint8_T StandandModeCounter;    /* '<S15>/Std_Mode'
                                        * 0位校准模式计数器
                                        */
extern uint8_T u2s_DSM_WorkMode;       /* '<S13>/Chart1'
                                        * 智能座椅功能工作模式
                                        */
extern boolean_T bis_DSM_LeftButtom_flg;/* '<S14>/Switch'
                                         * 左边按钮激活标志位
                                         */
extern boolean_T bis_DSM_RightButtom_flg;/* '<S14>/Switch1'
                                          * 右边按钮激活标志位
                                          */
extern boolean_T bis_DSM_SeatHallCntChg_flg;/* '<S7>/Switch4'
                                             * 座椅电机霍尔信号计数器变化标志位
                                             */
extern boolean_T bis_DSM_StandandPosActive_flg;/* '<S15>/Std_Mode'
                                                * 0位校准模式激活标志位
                                                */
extern boolean_T TQM_FrontSeatMotor_flg;/* '<S13>/Chart1'
                                         * TQM座椅前电机控制开关信号
                                         */
extern boolean_T TQM_RearSeatMotor_flg;/* '<S13>/Chart1'
                                        * TQM座椅后电机控制开关信号
                                        */
extern boolean_T bis_DrivingModInt_flg;/* '<S13>/Chart1'
                                        * 座椅驾驶态标志位
                                        */

/* Model entry point functions */
extern void AVAS_Model_initialize(void);
extern void AVAS_Model_step(void);
extern void AVAS_Model_terminate(void);

/* Real-time Model object */
#pragma push
#pragma DATA_SEG __GPAGE_SEG GPAGED_RAM

extern RT_MODEL_AVAS_Model_T *const AVAS_Model_M;

#pragma pop

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'AVAS_Model'
 * '<S1>'   : 'AVAS_Model/100ms_trigger'
 * '<S2>'   : 'AVAS_Model/ABS_232_MsgLostChk'
 * '<S3>'   : 'AVAS_Model/AVAS_Module'
 * '<S4>'   : 'AVAS_Model/Compare To Constant'
 * '<S5>'   : 'AVAS_Model/Compare To Constant1'
 * '<S6>'   : 'AVAS_Model/Compare To Constant2'
 * '<S7>'   : 'AVAS_Model/Seat_Module'
 * '<S8>'   : 'AVAS_Model/Time_Chart'
 * '<S9>'   : 'AVAS_Model/100ms_trigger/Compare To Constant'
 * '<S10>'  : 'AVAS_Model/AVAS_Module/AVAS_chart'
 * '<S11>'  : 'AVAS_Model/AVAS_Module/Compare To Zero'
 * '<S12>'  : 'AVAS_Model/Seat_Module/Chart'
 * '<S13>'  : 'AVAS_Model/Seat_Module/Driver_Seat_Module'
 * '<S14>'  : 'AVAS_Model/Seat_Module/Seat_Buttom_Module'
 * '<S15>'  : 'AVAS_Model/Seat_Module/Std_Mode_Module'
 * '<S16>'  : 'AVAS_Model/Seat_Module/Driver_Seat_Module/Chart1'
 * '<S17>'  : 'AVAS_Model/Seat_Module/Seat_Buttom_Module/Bilateral_Delay'
 * '<S18>'  : 'AVAS_Model/Seat_Module/Seat_Buttom_Module/Bilateral_Delay1'
 * '<S19>'  : 'AVAS_Model/Seat_Module/Seat_Buttom_Module/Bilateral_Delay/Compare To Constant1'
 * '<S20>'  : 'AVAS_Model/Seat_Module/Seat_Buttom_Module/Bilateral_Delay/Compare To Constant2'
 * '<S21>'  : 'AVAS_Model/Seat_Module/Seat_Buttom_Module/Bilateral_Delay1/Compare To Constant1'
 * '<S22>'  : 'AVAS_Model/Seat_Module/Seat_Buttom_Module/Bilateral_Delay1/Compare To Constant2'
 * '<S23>'  : 'AVAS_Model/Seat_Module/Std_Mode_Module/Std_Mode'
 */
#endif                                 /* RTW_HEADER_AVAS_Model_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

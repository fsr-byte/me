/*
 * File: TMM_M.h
 *
 * Code generated for Simulink model 'TMM_model'.
 *
 * Model version                  : 1.2731
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Fri Mar 18 15:44:30 2022
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

#ifndef RTW_HEADER_TMM_M_h_
#define RTW_HEADER_TMM_M_h_
#include <math.h>
#ifndef TMM_model_COMMON_INCLUDES_
# define TMM_model_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#endif                                 /* TMM_model_COMMON_INCLUDES_ */

#include "TMM_model_types.h"

/* Child system includes */
#include "TMM_lib.h"
#include "rt_nonfinite.h"

/* Block signals for system '<S23>/CoolFanCtrlHysteresis' */
typedef struct {
  boolean_T fanEnable;                 /* '<S23>/CoolFanCtrlHysteresis' */
  boolean_T HSfanEnable;               /* '<S23>/CoolFanCtrlHysteresis' */
} B_CoolFanCtrlHysteresis_TMM_m_T;

/* Block states (auto storage) for system '<S23>/CoolFanCtrlHysteresis' */
typedef struct {
  uint8_T is_active_c6_TMM_lib;        /* '<S23>/CoolFanCtrlHysteresis' */
  uint8_T is_c6_TMM_lib;               /* '<S23>/CoolFanCtrlHysteresis' */
} DW_CoolFanCtrlHysteresis_TMM__T;

/* Block signals for system '<S46>/IGBT_ave3' */
typedef struct {
  real32_T ret;                        /* '<S51>/Delay1' */
} B_IGBT_ave3_TMM_model_T;

/* Block states (auto storage) for system '<S46>/IGBT_ave3' */
typedef struct {
  real32_T Delay1_DSTATE;              /* '<S51>/Delay1' */
  real32_T Delay2_DSTATE;              /* '<S51>/Delay2' */
  uint8_T icLoad;                      /* '<S51>/Delay1' */
} DW_IGBT_ave3_TMM_model_T;

/* Block signals for system '<S1>/MsgLostChk' */
typedef struct {
  boolean_T RelationalOperator1;       /* '<S6>/Relational Operator1' */
} B_MsgLostChk_TMM_model_T;

/* Block states (auto storage) for system '<S1>/MsgLostChk' */
typedef struct {
  uint32_T Delay_DSTATE;               /* '<S6>/Delay' */
  uint8_T Delay1_DSTATE;               /* '<S6>/Delay1' */
} DW_MsgLostChk_TMM_model_T;

/* Zero-crossing (trigger) state for system '<S1>/MsgLostChk' */
typedef struct {
  ZCSigState MsgLostChk_Trig_ZCE;      /* '<S1>/MsgLostChk' */
} ZCE_MsgLostChk_TMM_model_T;

/* Block signals for system '<S1>/Subsystem' */
typedef struct {
  boolean_T Compare;                   /* '<S58>/Compare' */
} B_Subsystem_TMM_model_T;

/* Block states (auto storage) for system '<S1>/Subsystem' */
typedef struct {
  uint32_T Delay1_DSTATE;              /* '<S9>/Delay1' */
  uint32_T Delay2_DSTATE;              /* '<S9>/Delay2' */
  uint8_T icLoad;                      /* '<S9>/Delay1' */
} DW_Subsystem_TMM_model_T;

/* Block signals for system '<S101>/PowerDistrubuteWithPriority_1' */
typedef struct {
  uint16_T WPTC_Pwr;                   /* '<S106>/Switch1' */
  uint16_T PTC_Pwr;                    /* '<S106>/Switch3' */
  uint16_T AC_Pwr;                     /* '<S106>/Switch5' */
} B_PowerDistrubuteWithPriority_T;

extern void TMM__CoolFanCtrlHysteresis_Init(DW_CoolFanCtrlHysteresis_TMM__T
  *localDW);
extern void TMM_model_CoolFanCtrlHysteresis(int16_T rtu_temp, int16_T
  rtu_fanOff_Par, int16_T rtu_fanLowSpdOn_Par, int16_T rtu_fanHighSpdOn_Par,
  B_CoolFanCtrlHysteresis_TMM_m_T *localB, DW_CoolFanCtrlHysteresis_TMM__T
  *localDW);
extern void TMM_model_IGBT_ave3_Init(DW_IGBT_ave3_TMM_model_T *localDW);
extern void TMM_model_IGBT_ave3(real32_T rtu_input, B_IGBT_ave3_TMM_model_T
  *localB, DW_IGBT_ave3_TMM_model_T *localDW, real32_T rtp_step);
extern void TMM_model_MsgLostChk(boolean_T rtu_Trigger, uint32_T rtu_MSG_Tick,
  B_MsgLostChk_TMM_model_T *localB, DW_MsgLostChk_TMM_model_T *localDW,
  ZCE_MsgLostChk_TMM_model_T *localZCE, uint8_T rtp_MsgLostNumThd);
extern void TMM_model_Subsystem_Init(DW_Subsystem_TMM_model_T *localDW);
extern void TMM_model_Subsystem(B_Subsystem_TMM_model_T *localB,
  DW_Subsystem_TMM_model_T *localDW, uint32_T rtp_trigger_timer_ms);
extern void T_PowerDistrubuteWithPriority_1(uint16_T rtu_First_TargetPwr_w,
  uint16_T rtu_First_ShutoffPwr_w, uint16_T rtu_Second_TargetPwr_W, uint16_T
  rtu_Second_ShutoffPwr_w, uint16_T rtu_Third_TargetPwr_W, uint16_T
  rtu_Third_ShutoffPwr_w, uint32_T rtu_TMS_UpLimitPwr_w,
  B_PowerDistrubuteWithPriority_T *localB);
extern void TMM_mod_BatteryChargeManagement(void);
extern void TMM_model_TMM_M_Init(void);
extern void TMM_model_TMM_M(void);

#endif                                 /* RTW_HEADER_TMM_M_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

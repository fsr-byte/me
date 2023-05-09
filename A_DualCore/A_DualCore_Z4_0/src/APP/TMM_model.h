/*
 * File: TMM_model.h
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

#ifndef RTW_HEADER_TMM_model_h_
#define RTW_HEADER_TMM_model_h_
#include <string.h>
#include <stddef.h>
#ifndef TMM_model_COMMON_INCLUDES_
# define TMM_model_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#endif                                 /* TMM_model_COMMON_INCLUDES_ */

#include "TMM_model_types.h"

/* Child system includes */
#include "TMM_M.h"

/* Includes for objects with custom storage classes. */
#include "TMM_Cal_Data.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */

/* user code (top of header file) */
#include "derivative.h"

/* Block signals (auto storage) */
typedef struct {
  real32_T MultiportSwitch;            /* '<S45>/Multiport Switch' */
  real32_T MultiportSwitch1;           /* '<S45>/Multiport Switch1' */
  real32_T MultiportSwitch2;           /* '<S45>/Multiport Switch2' */
  int16_T INP_BattInWaterT_deg;        /* '<S67>/INP_BattInWaterT_deg' */
  int16_T INP_PTSensorT_deg;           /* '<S67>/INP_PTSensorT_deg' */
  int16_T TMS_BattCurrInWaterT_deg;    /* '<S66>/TMS_BattCurrInWaterT_deg' */
  int16_T BMS_WPTC_SetT_Table;         /* '<S66>/BMS_WPTC_SetT_Table' */
  uint16_T MinMax;                     /* '<S67>/MinMax' */
  uint16_T Switch;                     /* '<S67>/Switch' */
  uint16_T ECC_PTC_TargetPwr_w;        /* '<S67>/ECC_PTC_TargetPwr_w' */
  uint16_T ECC_AC_SpeedSet;            /* '<S67>/ECC_AC_SpeedSet' */
  uint16_T DataTypeConversion;         /* '<S67>/Data Type Conversion' */
  uint16_T ECC_PTC_Target_T;           /* '<S66>/ECC_PTC_Target_T' */
  uint16_T MultiportSwitch_p;          /* '<S122>/Multiport Switch' */
  uint16_T MultiportSwitch1_j;         /* '<S122>/Multiport Switch1' */
  uint16_T MultiportSwitch2_m;         /* '<S122>/Multiport Switch2' */
  uint16_T Sum1_j;                     /* '<S76>/Sum1' */
  int8_T BMS_BattTargetInWaterT;       /* '<S67>/BMS_BattTargetInWaterT' */
  uint8_T TMS_BattTherMag_Req;         /* '<S67>/TMS_BattTherMag_Req' */
  uint8_T BMS_BattTargetInWaterFlow;   /* '<S67>/BMS_BattTargetInWaterFlow' */
  uint8_T AC_SwtSts;                   /* '<S67>/Chart' */
  uint8_T Switch15;                    /* '<S21>/Switch15' */
  boolean_T Delay1;                    /* '<S1>/Delay1' */
  boolean_T ECC_PTC_Work_Req;          /* '<S67>/ECC_PTC_Work_Req' */
  boolean_T ECC_PTC_Work_ReqValid;     /* '<S67>/ECC_PTC_Work_ReqValid' */
  boolean_T Compare;                   /* '<S169>/Compare' */
  boolean_T ECC_AC_Work_ReqValid;      /* '<S67>/ECC_AC_Work_ReqValid' */
  boolean_T Constant;                  /* '<S67>/Constant' */
  boolean_T TMM_ENM_EnaAC;             /* '<S66>/TMM_ENM_EnaAC' */
  boolean_T LogicalOperator;           /* '<S66>/Logical Operator' */
  boolean_T TMM_ENM_EnaWPTC;           /* '<S66>/TMM_ENM_EnaWPTC' */
  boolean_T LogicalOperator2;          /* '<S71>/Logical Operator2' */
  boolean_T LogicalOperator2_m;        /* '<S70>/Logical Operator2' */
  boolean_T UserOperation_Req;         /* '<S59>/UserOp_Req_Notify_K11' */
  boolean_T flg;                       /* '<S55>/hysteresis' */
  boolean_T flg_p;                     /* '<S54>/hysteresis' */
  boolean_T Switch9;                   /* '<S21>/Switch9' */
  boolean_T LogicalOperator1;          /* '<S14>/Logical Operator1' */
  B_PowerDistrubuteWithPriority_T PowerDistrubuteWithPriority_3_e;/* '<S122>/PowerDistrubuteWithPriority_3' */
  B_PowerDistrubuteWithPriority_T PowerDistrubuteWithPriority_2_o;/* '<S122>/PowerDistrubuteWithPriority_2' */
  B_PowerDistrubuteWithPriority_T PowerDistrubuteWithPriority_1_n;/* '<S122>/PowerDistrubuteWithPriority_1' */
  B_PowerDistrubuteWithPriority_T PowerDistrubuteWithPriority_3;/* '<S101>/PowerDistrubuteWithPriority_3' */
  B_PowerDistrubuteWithPriority_T PowerDistrubuteWithPriority_2;/* '<S101>/PowerDistrubuteWithPriority_2' */
  B_PowerDistrubuteWithPriority_T PowerDistrubuteWithPriority_1;/* '<S101>/PowerDistrubuteWithPriority_1' */
  B_Subsystem_TMM_model_T timer_1s;    /* '<S59>/timer_1s' */
  B_Subsystem_TMM_model_T Subsystem;   /* '<S1>/Subsystem' */
  B_MsgLostChk_TMM_model_T MsgLostChk_OBCT;/* '<S1>/MsgLostChk_OBCT' */
  B_MsgLostChk_TMM_model_T MsgLostChk; /* '<S1>/MsgLostChk' */
  B_IGBT_ave3_TMM_model_T IGBT_ave1;   /* '<S44>/IGBT_ave1' */
  B_IGBT_ave3_TMM_model_T IGBT_ave2;   /* '<S47>/IGBT_ave2' */
  B_IGBT_ave3_TMM_model_T IGBT_ave3;   /* '<S46>/IGBT_ave3' */
  B_SignalConfirm_T SignalConfirm1_b;  /* '<S30>/SignalConfirm1' */
  B_SignalConfirm_T SignalConfirm1;    /* '<S22>/SignalConfirm1' */
  B_CoolFanCtrlHysteresis_TMM_m_T sf_CoolFanCtrlHysteresis4;/* '<S23>/CoolFanCtrlHysteresis4' */
  B_CoolFanCtrlHysteresis_TMM_m_T sf_CoolFanCtrlHysteresis3;/* '<S23>/CoolFanCtrlHysteresis3' */
  B_CoolFanCtrlHysteresis_TMM_m_T sf_CoolFanCtrlHysteresis2;/* '<S23>/CoolFanCtrlHysteresis2' */
  B_CoolFanCtrlHysteresis_TMM_m_T sf_CoolFanCtrlHysteresis1;/* '<S23>/CoolFanCtrlHysteresis1' */
  B_CoolFanCtrlHysteresis_TMM_m_T sf_CoolFanCtrlHysteresis;/* '<S23>/CoolFanCtrlHysteresis' */
} B_TMM_model_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real32_T Delay1_DSTATE;              /* '<S48>/Delay1' */
  real32_T Delay2_DSTATE;              /* '<S48>/Delay2' */
  uint32_T Delay2_DSTATE_o;            /* '<S11>/Delay2' */
  uint32_T Delay3_DSTATE;              /* '<S11>/Delay3' */
  uint32_T Delay1_DSTATE_n;            /* '<S88>/Delay1' */
  uint32_T Delay_DSTATE;               /* '<S88>/Delay' */
  uint32_T Delay1_DSTATE_nf;           /* '<S86>/Delay1' */
  uint32_T Delay_DSTATE_n;             /* '<S86>/Delay' */
  uint32_T Delay1_DSTATE_c;            /* '<S85>/Delay1' */
  uint32_T Delay_DSTATE_f;             /* '<S85>/Delay' */
  uint32_T Delay_DSTATE_c;             /* '<S36>/Delay' */
  uint32_T Delay1_DSTATE_j;            /* '<S36>/Delay1' */
  uint32_T internal_timer;             /* '<S40>/WaterTModel_WorkMode' */
  uint16_T Delay2_DSTATE_c;            /* '<S100>/Delay2' */
  uint16_T Delay1_DSTATE_i;            /* '<S100>/Delay1' */
  uint16_T Delay3_DSTATE_e;            /* '<S100>/Delay3' */
  boolean_T Delay2_DSTATE_oz;          /* '<S1>/Delay2' */
  boolean_T Delay_DSTATE_k[2];         /* '<S1>/Delay' */
  boolean_T Delay3_DSTATE_m[4];        /* '<S1>/Delay3' */
  boolean_T Delay1_DSTATE_f[3];        /* '<S1>/Delay1' */
  boolean_T Delay_DSTATE_b;            /* '<S64>/Delay' */
  boolean_T Delay1_DSTATE_l;           /* '<S64>/Delay1' */
  boolean_T Delay2_DSTATE_os;          /* '<S123>/Delay2' */
  boolean_T Delay_DSTATE_ex;           /* '<S124>/Delay' */
  boolean_T Delay_DSTATE_a;            /* '<S125>/Delay' */
  boolean_T Delay3_DSTATE_k;           /* '<S88>/Delay3' */
  boolean_T Delay2_DSTATE_k;           /* '<S86>/Delay2' */
  boolean_T Delay2_DSTATE_l;           /* '<S36>/Delay2' */
  uint8_T icLoad;                      /* '<S11>/Delay2' */
  uint8_T icLoad_n;                    /* '<S88>/Delay1' */
  uint8_T icLoad_g;                    /* '<S88>/Delay3' */
  uint8_T icLoad_l;                    /* '<S86>/Delay1' */
  uint8_T icLoad_gi;                   /* '<S85>/Delay1' */
  uint8_T is_c3_TMM_UserOp_Req;        /* '<S59>/UserOp_Req_Notify_K11' */
  uint8_T is_active_c1_WaterT_Caculate;/* '<S40>/WaterTModel_WorkMode' */
  uint8_T is_c1_WaterT_Caculate;       /* '<S40>/WaterTModel_WorkMode' */
  uint8_T icLoad_nk;                   /* '<S48>/Delay1' */
  uint8_T icLoad_c;                    /* '<S36>/Delay2' */
  uint8_T icLoad_k;                    /* '<S36>/Delay1' */
  boolean_T Relay_PumpEn_MotT_Mode;    /* '<S32>/Relay_PumpEn_MotT' */
  boolean_T Relay_PumpEn_MCUT_Mode;    /* '<S32>/Relay_PumpEn_MCUT' */
  boolean_T Relay_PumpEn_DCDCT_Mode;   /* '<S32>/Relay_PumpEn_DCDCT' */
  boolean_T Relay_PumpEn_OBCT_Mode;    /* '<S32>/Relay_PumpEn_OBCT' */
  boolean_T Relay_PumpEn_IGBTT_Mode;   /* '<S32>/Relay_PumpEn_IGBTT' */
  boolean_T limit_level_1_Mode;        /* '<S16>/limit_level_1' */
  boolean_T limit_level_2_Mode;        /* '<S16>/limit_level_2' */
  boolean_T limit_level_3_Mode;        /* '<S16>/limit_level_3' */
  boolean_T VCU_TMS_Ingress_SignalConvert_M;/* '<S10>/VCU_TMS_Ingress_SignalConvert' */
  boolean_T VCU_TMS_Egress_SignalConvert_MO;/* '<S10>/VCU_TMS_Egress_SignalConvert' */
  boolean_T TMM_Convert_output_signal_MODE;/* '<S10>/TMM_Convert_output_signal' */
  DW_Subsystem_TMM_model_T timer_1s;   /* '<S59>/timer_1s' */
  DW_Subsystem_TMM_model_T Subsystem;  /* '<S1>/Subsystem' */
  DW_MsgLostChk_TMM_model_T MsgLostChk_OBCT;/* '<S1>/MsgLostChk_OBCT' */
  DW_MsgLostChk_TMM_model_T MsgLostChk;/* '<S1>/MsgLostChk' */
  DW_IGBT_ave3_TMM_model_T IGBT_ave1;  /* '<S44>/IGBT_ave1' */
  DW_IGBT_ave3_TMM_model_T IGBT_ave2;  /* '<S47>/IGBT_ave2' */
  DW_IGBT_ave3_TMM_model_T IGBT_ave3;  /* '<S46>/IGBT_ave3' */
  DW_SignalConfirm_T SignalConfirm1_b; /* '<S30>/SignalConfirm1' */
  DW_SignalConfirm_T SignalConfirm1;   /* '<S22>/SignalConfirm1' */
  DW_CoolFanCtrlHysteresis_TMM__T sf_CoolFanCtrlHysteresis4;/* '<S23>/CoolFanCtrlHysteresis4' */
  DW_CoolFanCtrlHysteresis_TMM__T sf_CoolFanCtrlHysteresis3;/* '<S23>/CoolFanCtrlHysteresis3' */
  DW_CoolFanCtrlHysteresis_TMM__T sf_CoolFanCtrlHysteresis2;/* '<S23>/CoolFanCtrlHysteresis2' */
  DW_CoolFanCtrlHysteresis_TMM__T sf_CoolFanCtrlHysteresis1;/* '<S23>/CoolFanCtrlHysteresis1' */
  DW_CoolFanCtrlHysteresis_TMM__T sf_CoolFanCtrlHysteresis;/* '<S23>/CoolFanCtrlHysteresis' */
} DW_TMM_model_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState Thermal_Manage_Trig_ZCE;  /* '<S1>/Thermal_Manage' */
  ZCSigState TriggeredSubsystem_Trig_ZCE;/* '<S94>/Triggered Subsystem' */
  ZCSigState UserOp_Req_Notify_S11P01_Trig_Z;/* '<S59>/UserOp_Req_Notify_S11P01' */
  ZCSigState UserOp_Req_Notify_S11_Trig_ZCE;/* '<S59>/UserOp_Req_Notify_S11' */
  ZCSigState UserOp_Req_Notify_K11_Trig_ZCE;/* '<S59>/UserOp_Req_Notify_K11' */
  ZCE_MsgLostChk_TMM_model_T MsgLostChk_OBCT;/* '<S1>/MsgLostChk_OBCT' */
  ZCE_MsgLostChk_TMM_model_T MsgLostChk;/* '<S1>/MsgLostChk' */
  ZCSigState EnabledWaterT_Caculate_Trig_ZCE;/* '<S1>/Enabled WaterT_Caculate' */
  ZCSigState CoolingSysSts_Trig_ZCE;   /* '<S1>/CoolingSysSts' */
  ZCSigState BatteryChargeManagement_Trig_ZC;/* '<S1>/BatteryChargeManagement' */
} PrevZCX_TMM_model_T;

/* Invariant block signals (auto storage) */
typedef struct {
  const uint8_T TMM_TMS_Batt_OutWT;    /* '<S1>/Data Type Conversion13' */
} ConstB_TMM_model_T;

/* Constant parameters (auto storage) */
typedef struct {
  /* Computed Parameter: uDLookupTable_bp01Data
   * Referenced by: '<S44>/2-D Lookup Table'
   */
  real32_T uDLookupTable_bp01Data[31];

  /* Computed Parameter: uDLookupTable_bp02Data
   * Referenced by: '<S44>/2-D Lookup Table'
   */
  real32_T uDLookupTable_bp02Data[13];

  /* Computed Parameter: uDLookupTable_maxIndex
   * Referenced by: '<S44>/2-D Lookup Table'
   */
  uint32_T uDLookupTable_maxIndex[2];

  /* Computed Parameter: ECCPowerLimit_maxIndex
   * Referenced by: '<S99>/ECCPowerLimit'
   */
  uint32_T ECCPowerLimit_maxIndex[2];

  /* Computed Parameter: BMS_WPTC_SetT_Table_tableData
   * Referenced by: '<S66>/BMS_WPTC_SetT_Table'
   */
  int16_T BMS_WPTC_SetT_Table_tableData[5];

  /* Computed Parameter: Batt_Table_bp01Data
   * Referenced by: '<S66>/Batt_Table'
   */
  uint8_T Batt_Table_bp01Data[5];

  /* Computed Parameter: waterpumpandgearTablenD_table
   * Referenced by: '<S35>/waterpump and gear Table (n-D)   '
   */
  boolean_T waterpumpandgearTablenD_table[5];
} ConstP_TMM_model_T;

/* Block signals (auto storage) */
#pragma push
#pragma DATA_SEG __GPAGE_SEG GPAGED_RAM

extern B_TMM_model_T TMM_model_B;

#pragma pop

/* Block states (auto storage) */

#pragma push
#pragma DATA_SEG __GPAGE_SEG GPAGED_RAM

extern DW_TMM_model_T TMM_model_DW;

#pragma pop

/* External data declarations for dependent source files */
#pragma push
#pragma DATA_SEG __GPAGE_SEG GPAGED_RAM

extern const TMM TMM_model_rtZTMM;     /* TMM ground */

#pragma pop

/* Zero-crossing (trigger) state */

#pragma push
#pragma DATA_SEG __GPAGE_SEG GPAGED_RAM

extern PrevZCX_TMM_model_T TMM_model_PrevZCX;

#pragma pop
#pragma push
#pragma DATA_SEG __GPAGE_SEG GPAGED_RAM

extern const ConstB_TMM_model_T TMM_model_ConstB;/* constant block i/o */

#pragma pop

/* Constant parameters (auto storage) */

#pragma push
#pragma DATA_SEG __GPAGE_SEG GPAGED_RAM

extern const ConstP_TMM_model_T TMM_model_ConstP;

#pragma pop

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern TMM TMM_output;                 /* '<S1>/Bus Creator1' */
extern uint16_T STMM_BattEXV_PositionRequest;/* '<S1>/Data Type Conversion36' */
extern uint16_T STMM_CabinEXV_PositionRequest;/* '<S1>/Data Type Conversion35' */
extern uint16_T STMM_Z18ECC_EAC_MaxPwr_w;/* '<S68>/Switch2' */
extern uint16_T STMM_Z18ECC_PTC_MaxPwr_w;/* '<S68>/Switch5' */
extern uint16_T STMM_LkupECCPowerLimit_W;/* '<S99>/ECCPowerLimit' */
extern uint8_T STMM_WPPWM_Duty_pct;    /* '<S1>/Data Type Conversion2' */
extern uint8_T STMM_Motor_DischargePowerLimit_Pct;/* '<S1>/Data Type Conversion8' */
extern uint8_T STMM_MCUInWaterT_C;     /* '<S1>/Data Type Conversion7' */
extern uint8_T STMM_PDUInWaterT_C;     /* '<S1>/Data Type Conversion11' */
extern uint8_T STMM_MoterInWaterT_C;   /* '<S1>/Data Type Conversion12' */
extern uint8_T STMM_Z18PWMPctOut;      /* '<S68>/Z18PWM_Chart' */
extern uint8_T STMM_WaterT_WorkMode;   /* '<S40>/WaterTModel_WorkMode' */
extern uint8_T STMM_WaterT_MCUThermalPower;/* '<S44>/2-D Lookup Table' */
extern boolean_T STMM_WaterPumpEnReq_flg;/* '<S1>/Data Type Conversion1' */
extern boolean_T STMM_BattGVSt_OnRequest;/* '<S1>/Data Type Conversion24' */
extern boolean_T STMM_BattEXV_initRequest;/* '<S1>/Data Type Conversion23' */
extern boolean_T STMM_CabinGVSt_OnRequest;/* '<S1>/Data Type Conversion22' */
extern boolean_T STMM_CabinEXV_initRequest;/* '<S1>/Data Type Conversion21' */
extern boolean_T STMM_Z18ECC_Defrost_On;/* '<S173>/AND' */
extern boolean_T STMM_Z18ECC_EACReq;   /* '<S68>/Logical Operator2' */
extern boolean_T STMM_Z18ECC_PTCReq;   /* '<S68>/Logical Operator4' */
extern boolean_T STMM_InvalidBattReq;  /* '<S80>/Logical Operator19' */
extern boolean_T STMM_WPTCPreEnReq;    /* '<S80>/Logical Operator10' */
extern boolean_T STMM_PTCPreEnReq;     /* '<S80>/Logical Operator4' */
extern boolean_T STMM_ACPreEnReq;      /* '<S80>/Logical Operator6' */
extern boolean_T STMM_PTC_PwrOutEn;    /* '<S119>/Compare' */
extern boolean_T STMM_AC_PwrOutEn;     /* '<S120>/Compare' */
extern boolean_T STMM_WPTC_PwrOutEn;   /* '<S121>/Compare' */
extern boolean_T STMM_LSCoolFanEnReq_flg;/* '<S22>/Logical Operator4' */
extern boolean_T STMM_HSCoolFanEnReq_flg;/* '<S22>/Logical Operator6' */
extern boolean_T STMM_AfterRunComplete_flg;/* '<S4>/Switch10' */

/*
 * Exported States
 *
 * Note: Exported states are block states with an exported global
 * storage class designation.  Code generation will declare the memory for these
 * states and exports their symbols.
 *
 */
extern boolean_T ECC_ForceShutoff_flg; /* '<S78>/Data Store Memory1' */

/* Model entry point functions */
extern void TMM_model_initialize(void);
extern void TMM_model_step(void);
extern void TMM_model_terminate(void);

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
 * '<Root>' : 'TMM_model'
 * '<S1>'   : 'TMM_model/TMM_M'
 * '<S2>'   : 'TMM_model/TMM_M/BatteryChargeManagement'
 * '<S3>'   : 'TMM_model/TMM_M/Compare To Constant'
 * '<S4>'   : 'TMM_model/TMM_M/CoolingSysSts'
 * '<S5>'   : 'TMM_model/TMM_M/Enabled WaterT_Caculate'
 * '<S6>'   : 'TMM_model/TMM_M/MsgLostChk'
 * '<S7>'   : 'TMM_model/TMM_M/MsgLostChk_OBCT'
 * '<S8>'   : 'TMM_model/TMM_M/PowerLimit'
 * '<S9>'   : 'TMM_model/TMM_M/Subsystem'
 * '<S10>'  : 'TMM_model/TMM_M/Thermal_Manage'
 * '<S11>'  : 'TMM_model/TMM_M/timer_trigger'
 * '<S12>'  : 'TMM_model/TMM_M/BatteryChargeManagement/BatteryHeatM'
 * '<S13>'  : 'TMM_model/TMM_M/BatteryChargeManagement/BatteryHeatM/PMM_A_VCUChrgReqLimFac'
 * '<S14>'  : 'TMM_model/TMM_M/BatteryChargeManagement/BatteryHeatM/VPMM_BattIntrHeatAllwd'
 * '<S15>'  : 'TMM_model/TMM_M/BatteryChargeManagement/BatteryHeatM/PMM_A_VCUChrgReqLimFac/ChargerSocketTemperature'
 * '<S16>'  : 'TMM_model/TMM_M/BatteryChargeManagement/BatteryHeatM/PMM_A_VCUChrgReqLimFac/Subsystem'
 * '<S17>'  : 'TMM_model/TMM_M/BatteryChargeManagement/BatteryHeatM/PMM_A_VCUChrgReqLimFac/ChargerSocketTemperature/Compare To Constant'
 * '<S18>'  : 'TMM_model/TMM_M/BatteryChargeManagement/BatteryHeatM/PMM_A_VCUChrgReqLimFac/ChargerSocketTemperature/Compare To Constant1'
 * '<S19>'  : 'TMM_model/TMM_M/BatteryChargeManagement/BatteryHeatM/PMM_A_VCUChrgReqLimFac/ChargerSocketTemperature/Compare To Constant2'
 * '<S20>'  : 'TMM_model/TMM_M/CoolingSysSts/CoolFan'
 * '<S21>'  : 'TMM_model/TMM_M/CoolingSysSts/WaterPump'
 * '<S22>'  : 'TMM_model/TMM_M/CoolingSysSts/CoolFan/CoolFan_Management'
 * '<S23>'  : 'TMM_model/TMM_M/CoolingSysSts/CoolFan/CoolFan_Management/DevTCoolFanEnReq'
 * '<S24>'  : 'TMM_model/TMM_M/CoolingSysSts/CoolFan/CoolFan_Management/SignalConfirm1'
 * '<S25>'  : 'TMM_model/TMM_M/CoolingSysSts/CoolFan/CoolFan_Management/DevTCoolFanEnReq/CoolFanCtrlHysteresis'
 * '<S26>'  : 'TMM_model/TMM_M/CoolingSysSts/CoolFan/CoolFan_Management/DevTCoolFanEnReq/CoolFanCtrlHysteresis1'
 * '<S27>'  : 'TMM_model/TMM_M/CoolingSysSts/CoolFan/CoolFan_Management/DevTCoolFanEnReq/CoolFanCtrlHysteresis2'
 * '<S28>'  : 'TMM_model/TMM_M/CoolingSysSts/CoolFan/CoolFan_Management/DevTCoolFanEnReq/CoolFanCtrlHysteresis3'
 * '<S29>'  : 'TMM_model/TMM_M/CoolingSysSts/CoolFan/CoolFan_Management/DevTCoolFanEnReq/CoolFanCtrlHysteresis4'
 * '<S30>'  : 'TMM_model/TMM_M/CoolingSysSts/WaterPump/WaterPump_Enable'
 * '<S31>'  : 'TMM_model/TMM_M/CoolingSysSts/WaterPump/WaterPump_PWM_Duty'
 * '<S32>'  : 'TMM_model/TMM_M/CoolingSysSts/WaterPump/WaterPump_Enable/CoolSystemWaterPumpEnReq'
 * '<S33>'  : 'TMM_model/TMM_M/CoolingSysSts/WaterPump/WaterPump_Enable/FaultDetectWaterPumpEnReq'
 * '<S34>'  : 'TMM_model/TMM_M/CoolingSysSts/WaterPump/WaterPump_Enable/SignalConfirm1'
 * '<S35>'  : 'TMM_model/TMM_M/CoolingSysSts/WaterPump/WaterPump_Enable/WaterPumpPreEnReq'
 * '<S36>'  : 'TMM_model/TMM_M/CoolingSysSts/WaterPump/WaterPump_Enable/WaterPumpPreEnReq/timeout_counter'
 * '<S37>'  : 'TMM_model/TMM_M/CoolingSysSts/WaterPump/WaterPump_Enable/WaterPumpPreEnReq/timeout_counter/Compare To Constant'
 * '<S38>'  : 'TMM_model/TMM_M/CoolingSysSts/WaterPump/WaterPump_Enable/WaterPumpPreEnReq/timeout_counter/Compare To Constant1'
 * '<S39>'  : 'TMM_model/TMM_M/CoolingSysSts/WaterPump/WaterPump_Enable/WaterPumpPreEnReq/timeout_counter/Compare To Constant2'
 * '<S40>'  : 'TMM_model/TMM_M/Enabled WaterT_Caculate/WaterT_Caculate'
 * '<S41>'  : 'TMM_model/TMM_M/Enabled WaterT_Caculate/WaterT_Caculate/DriveState'
 * '<S42>'  : 'TMM_model/TMM_M/Enabled WaterT_Caculate/WaterT_Caculate/WaterTModel_WorkMode'
 * '<S43>'  : 'TMM_model/TMM_M/Enabled WaterT_Caculate/WaterT_Caculate/DriveState/init_state_T'
 * '<S44>'  : 'TMM_model/TMM_M/Enabled WaterT_Caculate/WaterT_Caculate/DriveState/stable_state_T'
 * '<S45>'  : 'TMM_model/TMM_M/Enabled WaterT_Caculate/WaterT_Caculate/DriveState/stable_state_T1'
 * '<S46>'  : 'TMM_model/TMM_M/Enabled WaterT_Caculate/WaterT_Caculate/DriveState/stable_state_T/Cal_waterT_DCDC'
 * '<S47>'  : 'TMM_model/TMM_M/Enabled WaterT_Caculate/WaterT_Caculate/DriveState/stable_state_T/Cal_waterT_IGBT'
 * '<S48>'  : 'TMM_model/TMM_M/Enabled WaterT_Caculate/WaterT_Caculate/DriveState/stable_state_T/IGBT_ave'
 * '<S49>'  : 'TMM_model/TMM_M/Enabled WaterT_Caculate/WaterT_Caculate/DriveState/stable_state_T/IGBT_ave1'
 * '<S50>'  : 'TMM_model/TMM_M/Enabled WaterT_Caculate/WaterT_Caculate/DriveState/stable_state_T/Subsystem'
 * '<S51>'  : 'TMM_model/TMM_M/Enabled WaterT_Caculate/WaterT_Caculate/DriveState/stable_state_T/Cal_waterT_DCDC/IGBT_ave3'
 * '<S52>'  : 'TMM_model/TMM_M/Enabled WaterT_Caculate/WaterT_Caculate/DriveState/stable_state_T/Cal_waterT_IGBT/IGBT_ave2'
 * '<S53>'  : 'TMM_model/TMM_M/PowerLimit/MCU_OverTempTqLim'
 * '<S54>'  : 'TMM_model/TMM_M/PowerLimit/MCU_OverTempTqLim/Hysteresis_RightTrue2'
 * '<S55>'  : 'TMM_model/TMM_M/PowerLimit/MCU_OverTempTqLim/Hysteresis_RightTrue3'
 * '<S56>'  : 'TMM_model/TMM_M/PowerLimit/MCU_OverTempTqLim/Hysteresis_RightTrue2/hysteresis'
 * '<S57>'  : 'TMM_model/TMM_M/PowerLimit/MCU_OverTempTqLim/Hysteresis_RightTrue3/hysteresis'
 * '<S58>'  : 'TMM_model/TMM_M/Subsystem/Compare To Constant'
 * '<S59>'  : 'TMM_model/TMM_M/Thermal_Manage/Cabin_User_Req'
 * '<S60>'  : 'TMM_model/TMM_M/Thermal_Manage/Compare To Constant'
 * '<S61>'  : 'TMM_model/TMM_M/Thermal_Manage/Compare To Constant4'
 * '<S62>'  : 'TMM_model/TMM_M/Thermal_Manage/Subsystem'
 * '<S63>'  : 'TMM_model/TMM_M/Thermal_Manage/TMM_Convert_output_signal'
 * '<S64>'  : 'TMM_model/TMM_M/Thermal_Manage/TMM_ENM'
 * '<S65>'  : 'TMM_model/TMM_M/Thermal_Manage/TMM_ModeSwitch_Ingress'
 * '<S66>'  : 'TMM_model/TMM_M/Thermal_Manage/VCU_TMS_Egress_SignalConvert'
 * '<S67>'  : 'TMM_model/TMM_M/Thermal_Manage/VCU_TMS_Ingress_SignalConvert'
 * '<S68>'  : 'TMM_model/TMM_M/Thermal_Manage/Z18_signals'
 * '<S69>'  : 'TMM_model/TMM_M/Thermal_Manage/Cabin_User_Req/UserOp_Req_Notify_K11'
 * '<S70>'  : 'TMM_model/TMM_M/Thermal_Manage/Cabin_User_Req/UserOp_Req_Notify_S11'
 * '<S71>'  : 'TMM_model/TMM_M/Thermal_Manage/Cabin_User_Req/UserOp_Req_Notify_S11P01'
 * '<S72>'  : 'TMM_model/TMM_M/Thermal_Manage/Cabin_User_Req/timer_1s'
 * '<S73>'  : 'TMM_model/TMM_M/Thermal_Manage/Cabin_User_Req/UserOp_Req_Notify_S11P01/Cabin and Bat Req'
 * '<S74>'  : 'TMM_model/TMM_M/Thermal_Manage/Cabin_User_Req/UserOp_Req_Notify_S11P01/only Cabin req'
 * '<S75>'  : 'TMM_model/TMM_M/Thermal_Manage/Cabin_User_Req/timer_1s/Compare To Constant'
 * '<S76>'  : 'TMM_model/TMM_M/Thermal_Manage/TMM_Convert_output_signal/Per_to_Step1'
 * '<S77>'  : 'TMM_model/TMM_M/Thermal_Manage/TMM_ENM/Compare To Constant4'
 * '<S78>'  : 'TMM_model/TMM_M/Thermal_Manage/TMM_ENM/ECC_CheckForceShutoff'
 * '<S79>'  : 'TMM_model/TMM_M/Thermal_Manage/TMM_ENM/PowerManage'
 * '<S80>'  : 'TMM_model/TMM_M/Thermal_Manage/TMM_ENM/PreCheck'
 * '<S81>'  : 'TMM_model/TMM_M/Thermal_Manage/TMM_ENM/ECC_CheckForceShutoff/Compare1'
 * '<S82>'  : 'TMM_model/TMM_M/Thermal_Manage/TMM_ENM/ECC_CheckForceShutoff/Compare2'
 * '<S83>'  : 'TMM_model/TMM_M/Thermal_Manage/TMM_ENM/ECC_CheckForceShutoff/Compare3'
 * '<S84>'  : 'TMM_model/TMM_M/Thermal_Manage/TMM_ENM/ECC_CheckForceShutoff/Compare4'
 * '<S85>'  : 'TMM_model/TMM_M/Thermal_Manage/TMM_ENM/ECC_CheckForceShutoff/Subsystem1'
 * '<S86>'  : 'TMM_model/TMM_M/Thermal_Manage/TMM_ENM/ECC_CheckForceShutoff/Subsystem2'
 * '<S87>'  : 'TMM_model/TMM_M/Thermal_Manage/TMM_ENM/ECC_CheckForceShutoff/set forceshutoff flg'
 * '<S88>'  : 'TMM_model/TMM_M/Thermal_Manage/TMM_ENM/ECC_CheckForceShutoff/tmm_force_shutoff'
 * '<S89>'  : 'TMM_model/TMM_M/Thermal_Manage/TMM_ENM/ECC_CheckForceShutoff/Subsystem1/Compare To Constant'
 * '<S90>'  : 'TMM_model/TMM_M/Thermal_Manage/TMM_ENM/ECC_CheckForceShutoff/Subsystem2/Compare To Constant'
 * '<S91>'  : 'TMM_model/TMM_M/Thermal_Manage/TMM_ENM/ECC_CheckForceShutoff/Subsystem2/Compare To Constant1'
 * '<S92>'  : 'TMM_model/TMM_M/Thermal_Manage/TMM_ENM/ECC_CheckForceShutoff/Subsystem2/Compare To Constant2'
 * '<S93>'  : 'TMM_model/TMM_M/Thermal_Manage/TMM_ENM/ECC_CheckForceShutoff/set forceshutoff flg/If Action Subsystem'
 * '<S94>'  : 'TMM_model/TMM_M/Thermal_Manage/TMM_ENM/ECC_CheckForceShutoff/set forceshutoff flg/If Action Subsystem1'
 * '<S95>'  : 'TMM_model/TMM_M/Thermal_Manage/TMM_ENM/ECC_CheckForceShutoff/set forceshutoff flg/If Action Subsystem1/Triggered Subsystem'
 * '<S96>'  : 'TMM_model/TMM_M/Thermal_Manage/TMM_ENM/ECC_CheckForceShutoff/tmm_force_shutoff/Compare To Constant'
 * '<S97>'  : 'TMM_model/TMM_M/Thermal_Manage/TMM_ENM/ECC_CheckForceShutoff/tmm_force_shutoff/Compare To Constant3'
 * '<S98>'  : 'TMM_model/TMM_M/Thermal_Manage/TMM_ENM/ECC_CheckForceShutoff/tmm_force_shutoff/Compare To Constant4'
 * '<S99>'  : 'TMM_model/TMM_M/Thermal_Manage/TMM_ENM/PowerManage/ECC_PoweApply'
 * '<S100>' : 'TMM_model/TMM_M/Thermal_Manage/TMM_ENM/PowerManage/ECC_PoweDistribute'
 * '<S101>' : 'TMM_model/TMM_M/Thermal_Manage/TMM_ENM/PowerManage/ECC_PoweApply/TMM_PwrDistrubute'
 * '<S102>' : 'TMM_model/TMM_M/Thermal_Manage/TMM_ENM/PowerManage/ECC_PoweApply/TMM_PwrDistrubute/AC_Power_check1'
 * '<S103>' : 'TMM_model/TMM_M/Thermal_Manage/TMM_ENM/PowerManage/ECC_PoweApply/TMM_PwrDistrubute/Compare To Constant1'
 * '<S104>' : 'TMM_model/TMM_M/Thermal_Manage/TMM_ENM/PowerManage/ECC_PoweApply/TMM_PwrDistrubute/Compare To Constant2'
 * '<S105>' : 'TMM_model/TMM_M/Thermal_Manage/TMM_ENM/PowerManage/ECC_PoweApply/TMM_PwrDistrubute/PTC_Power_check'
 * '<S106>' : 'TMM_model/TMM_M/Thermal_Manage/TMM_ENM/PowerManage/ECC_PoweApply/TMM_PwrDistrubute/PowerDistrubuteWithPriority_1'
 * '<S107>' : 'TMM_model/TMM_M/Thermal_Manage/TMM_ENM/PowerManage/ECC_PoweApply/TMM_PwrDistrubute/PowerDistrubuteWithPriority_2'
 * '<S108>' : 'TMM_model/TMM_M/Thermal_Manage/TMM_ENM/PowerManage/ECC_PoweApply/TMM_PwrDistrubute/PowerDistrubuteWithPriority_3'
 * '<S109>' : 'TMM_model/TMM_M/Thermal_Manage/TMM_ENM/PowerManage/ECC_PoweApply/TMM_PwrDistrubute/WPTC_Power_check'
 * '<S110>' : 'TMM_model/TMM_M/Thermal_Manage/TMM_ENM/PowerManage/ECC_PoweApply/TMM_PwrDistrubute/AC_Power_check1/Compare To Constant'
 * '<S111>' : 'TMM_model/TMM_M/Thermal_Manage/TMM_ENM/PowerManage/ECC_PoweApply/TMM_PwrDistrubute/AC_Power_check1/Compare To Constant1'
 * '<S112>' : 'TMM_model/TMM_M/Thermal_Manage/TMM_ENM/PowerManage/ECC_PoweApply/TMM_PwrDistrubute/AC_Power_check1/Compare To Constant2'
 * '<S113>' : 'TMM_model/TMM_M/Thermal_Manage/TMM_ENM/PowerManage/ECC_PoweApply/TMM_PwrDistrubute/PTC_Power_check/Compare To Constant2'
 * '<S114>' : 'TMM_model/TMM_M/Thermal_Manage/TMM_ENM/PowerManage/ECC_PoweApply/TMM_PwrDistrubute/PTC_Power_check/Compare To Constant3'
 * '<S115>' : 'TMM_model/TMM_M/Thermal_Manage/TMM_ENM/PowerManage/ECC_PoweApply/TMM_PwrDistrubute/PTC_Power_check/Compare To Constant4'
 * '<S116>' : 'TMM_model/TMM_M/Thermal_Manage/TMM_ENM/PowerManage/ECC_PoweApply/TMM_PwrDistrubute/WPTC_Power_check/Compare To Constant2'
 * '<S117>' : 'TMM_model/TMM_M/Thermal_Manage/TMM_ENM/PowerManage/ECC_PoweApply/TMM_PwrDistrubute/WPTC_Power_check/Compare To Constant3'
 * '<S118>' : 'TMM_model/TMM_M/Thermal_Manage/TMM_ENM/PowerManage/ECC_PoweApply/TMM_PwrDistrubute/WPTC_Power_check/Compare To Constant4'
 * '<S119>' : 'TMM_model/TMM_M/Thermal_Manage/TMM_ENM/PowerManage/ECC_PoweDistribute/Compare To Zero'
 * '<S120>' : 'TMM_model/TMM_M/Thermal_Manage/TMM_ENM/PowerManage/ECC_PoweDistribute/Compare To Zero1'
 * '<S121>' : 'TMM_model/TMM_M/Thermal_Manage/TMM_ENM/PowerManage/ECC_PoweDistribute/Compare To Zero2'
 * '<S122>' : 'TMM_model/TMM_M/Thermal_Manage/TMM_ENM/PowerManage/ECC_PoweDistribute/TMM_PwrDistrubute'
 * '<S123>' : 'TMM_model/TMM_M/Thermal_Manage/TMM_ENM/PowerManage/ECC_PoweDistribute/delay enable'
 * '<S124>' : 'TMM_model/TMM_M/Thermal_Manage/TMM_ENM/PowerManage/ECC_PoweDistribute/delay enable1'
 * '<S125>' : 'TMM_model/TMM_M/Thermal_Manage/TMM_ENM/PowerManage/ECC_PoweDistribute/delay enable2'
 * '<S126>' : 'TMM_model/TMM_M/Thermal_Manage/TMM_ENM/PowerManage/ECC_PoweDistribute/TMM_PwrDistrubute/AC_Power_check1'
 * '<S127>' : 'TMM_model/TMM_M/Thermal_Manage/TMM_ENM/PowerManage/ECC_PoweDistribute/TMM_PwrDistrubute/Compare To Constant1'
 * '<S128>' : 'TMM_model/TMM_M/Thermal_Manage/TMM_ENM/PowerManage/ECC_PoweDistribute/TMM_PwrDistrubute/Compare To Constant2'
 * '<S129>' : 'TMM_model/TMM_M/Thermal_Manage/TMM_ENM/PowerManage/ECC_PoweDistribute/TMM_PwrDistrubute/PTC_Power_check'
 * '<S130>' : 'TMM_model/TMM_M/Thermal_Manage/TMM_ENM/PowerManage/ECC_PoweDistribute/TMM_PwrDistrubute/PowerDistrubuteWithPriority_1'
 * '<S131>' : 'TMM_model/TMM_M/Thermal_Manage/TMM_ENM/PowerManage/ECC_PoweDistribute/TMM_PwrDistrubute/PowerDistrubuteWithPriority_2'
 * '<S132>' : 'TMM_model/TMM_M/Thermal_Manage/TMM_ENM/PowerManage/ECC_PoweDistribute/TMM_PwrDistrubute/PowerDistrubuteWithPriority_3'
 * '<S133>' : 'TMM_model/TMM_M/Thermal_Manage/TMM_ENM/PowerManage/ECC_PoweDistribute/TMM_PwrDistrubute/WPTC_Power_check'
 * '<S134>' : 'TMM_model/TMM_M/Thermal_Manage/TMM_ENM/PowerManage/ECC_PoweDistribute/TMM_PwrDistrubute/AC_Power_check1/Compare To Constant'
 * '<S135>' : 'TMM_model/TMM_M/Thermal_Manage/TMM_ENM/PowerManage/ECC_PoweDistribute/TMM_PwrDistrubute/AC_Power_check1/Compare To Constant1'
 * '<S136>' : 'TMM_model/TMM_M/Thermal_Manage/TMM_ENM/PowerManage/ECC_PoweDistribute/TMM_PwrDistrubute/AC_Power_check1/Compare To Constant2'
 * '<S137>' : 'TMM_model/TMM_M/Thermal_Manage/TMM_ENM/PowerManage/ECC_PoweDistribute/TMM_PwrDistrubute/PTC_Power_check/Compare To Constant2'
 * '<S138>' : 'TMM_model/TMM_M/Thermal_Manage/TMM_ENM/PowerManage/ECC_PoweDistribute/TMM_PwrDistrubute/PTC_Power_check/Compare To Constant3'
 * '<S139>' : 'TMM_model/TMM_M/Thermal_Manage/TMM_ENM/PowerManage/ECC_PoweDistribute/TMM_PwrDistrubute/PTC_Power_check/Compare To Constant4'
 * '<S140>' : 'TMM_model/TMM_M/Thermal_Manage/TMM_ENM/PowerManage/ECC_PoweDistribute/TMM_PwrDistrubute/WPTC_Power_check/Compare To Constant2'
 * '<S141>' : 'TMM_model/TMM_M/Thermal_Manage/TMM_ENM/PowerManage/ECC_PoweDistribute/TMM_PwrDistrubute/WPTC_Power_check/Compare To Constant3'
 * '<S142>' : 'TMM_model/TMM_M/Thermal_Manage/TMM_ENM/PowerManage/ECC_PoweDistribute/TMM_PwrDistrubute/WPTC_Power_check/Compare To Constant4'
 * '<S143>' : 'TMM_model/TMM_M/Thermal_Manage/TMM_ENM/PreCheck/Compare To Constant'
 * '<S144>' : 'TMM_model/TMM_M/Thermal_Manage/TMM_ENM/PreCheck/Compare To Constant1'
 * '<S145>' : 'TMM_model/TMM_M/Thermal_Manage/TMM_ENM/PreCheck/Compare To Constant2'
 * '<S146>' : 'TMM_model/TMM_M/Thermal_Manage/TMM_ENM/PreCheck/Compare To Constant3'
 * '<S147>' : 'TMM_model/TMM_M/Thermal_Manage/TMM_ENM/PreCheck/Compare To Constant4'
 * '<S148>' : 'TMM_model/TMM_M/Thermal_Manage/TMM_ENM/PreCheck/Compare To Constant5'
 * '<S149>' : 'TMM_model/TMM_M/Thermal_Manage/TMM_ENM/PreCheck/Compare To Constant6'
 * '<S150>' : 'TMM_model/TMM_M/Thermal_Manage/TMM_ModeSwitch_Ingress/TargetPwrCheck'
 * '<S151>' : 'TMM_model/TMM_M/Thermal_Manage/TMM_ModeSwitch_Ingress/TargetPwrCheck1'
 * '<S152>' : 'TMM_model/TMM_M/Thermal_Manage/TMM_ModeSwitch_Ingress/TargetPwrCheck2'
 * '<S153>' : 'TMM_model/TMM_M/Thermal_Manage/TMM_ModeSwitch_Ingress/TargetPwrCheck3'
 * '<S154>' : 'TMM_model/TMM_M/Thermal_Manage/TMM_ModeSwitch_Ingress/TargetPwrCheck4'
 * '<S155>' : 'TMM_model/TMM_M/Thermal_Manage/TMM_ModeSwitch_Ingress/TargetPwrCheck/Compare To Constant1'
 * '<S156>' : 'TMM_model/TMM_M/Thermal_Manage/TMM_ModeSwitch_Ingress/TargetPwrCheck/Compare To Constant2'
 * '<S157>' : 'TMM_model/TMM_M/Thermal_Manage/TMM_ModeSwitch_Ingress/TargetPwrCheck1/Compare To Constant1'
 * '<S158>' : 'TMM_model/TMM_M/Thermal_Manage/TMM_ModeSwitch_Ingress/TargetPwrCheck1/Compare To Constant2'
 * '<S159>' : 'TMM_model/TMM_M/Thermal_Manage/TMM_ModeSwitch_Ingress/TargetPwrCheck2/Compare To Constant1'
 * '<S160>' : 'TMM_model/TMM_M/Thermal_Manage/TMM_ModeSwitch_Ingress/TargetPwrCheck2/Compare To Constant2'
 * '<S161>' : 'TMM_model/TMM_M/Thermal_Manage/TMM_ModeSwitch_Ingress/TargetPwrCheck3/Compare To Constant1'
 * '<S162>' : 'TMM_model/TMM_M/Thermal_Manage/TMM_ModeSwitch_Ingress/TargetPwrCheck3/Compare To Constant2'
 * '<S163>' : 'TMM_model/TMM_M/Thermal_Manage/TMM_ModeSwitch_Ingress/TargetPwrCheck4/Compare To Constant1'
 * '<S164>' : 'TMM_model/TMM_M/Thermal_Manage/TMM_ModeSwitch_Ingress/TargetPwrCheck4/Compare To Constant2'
 * '<S165>' : 'TMM_model/TMM_M/Thermal_Manage/VCU_TMS_Egress_SignalConvert/Compare To Constant1'
 * '<S166>' : 'TMM_model/TMM_M/Thermal_Manage/VCU_TMS_Egress_SignalConvert/Compare To Constant2'
 * '<S167>' : 'TMM_model/TMM_M/Thermal_Manage/VCU_TMS_Egress_SignalConvert/Compare To Constant3'
 * '<S168>' : 'TMM_model/TMM_M/Thermal_Manage/VCU_TMS_Ingress_SignalConvert/Chart'
 * '<S169>' : 'TMM_model/TMM_M/Thermal_Manage/VCU_TMS_Ingress_SignalConvert/Compare To Constant'
 * '<S170>' : 'TMM_model/TMM_M/Thermal_Manage/VCU_TMS_Ingress_SignalConvert/Compare To Constant1'
 * '<S171>' : 'TMM_model/TMM_M/Thermal_Manage/Z18_signals/Compare To Zero'
 * '<S172>' : 'TMM_model/TMM_M/Thermal_Manage/Z18_signals/Compare To Zero1'
 * '<S173>' : 'TMM_model/TMM_M/Thermal_Manage/Z18_signals/DEFROST_REQ_ON'
 * '<S174>' : 'TMM_model/TMM_M/Thermal_Manage/Z18_signals/EAC_ON_HIGH'
 * '<S175>' : 'TMM_model/TMM_M/Thermal_Manage/Z18_signals/EAC_ON_LOW'
 * '<S176>' : 'TMM_model/TMM_M/Thermal_Manage/Z18_signals/EAC_ON_MID'
 * '<S177>' : 'TMM_model/TMM_M/Thermal_Manage/Z18_signals/OFF_REQ'
 * '<S178>' : 'TMM_model/TMM_M/Thermal_Manage/Z18_signals/PTC_ON_HIGH'
 * '<S179>' : 'TMM_model/TMM_M/Thermal_Manage/Z18_signals/PTC_ON_LOW'
 * '<S180>' : 'TMM_model/TMM_M/Thermal_Manage/Z18_signals/PTC_ON_MID'
 * '<S181>' : 'TMM_model/TMM_M/Thermal_Manage/Z18_signals/REMOTE_EAC_ON'
 * '<S182>' : 'TMM_model/TMM_M/Thermal_Manage/Z18_signals/REMOTE_PTC_ON'
 * '<S183>' : 'TMM_model/TMM_M/Thermal_Manage/Z18_signals/Z18PWM_Chart'
 * '<S184>' : 'TMM_model/TMM_M/timer_trigger/Compare To Constant'
 */
#endif                                 /* RTW_HEADER_TMM_model_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

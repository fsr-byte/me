/*
 * File: Funcs_DIM_lib.h
 *
 * Code generated for Simulink model 'DIM_model'.
 *
 * Model version                  : 1.2422
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Fri Mar 18 15:35:30 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Freescale->32-bit PowerPC
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Funcs_DIM_lib_h_
#define RTW_HEADER_Funcs_DIM_lib_h_
#include <math.h>
#ifndef DIM_model_COMMON_INCLUDES_
# define DIM_model_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* DIM_model_COMMON_INCLUDES_ */

#include "DIM_model_types.h"

/* Block signals for system '<S75>/override signal' */
typedef struct {
  boolean_T Switch;                    /* '<S76>/Switch' */
} B_ovrride_signal_CAN1_T;

/* Block signals for system '<S49>/CAN_NofaoffInput' */
typedef struct {
  B_ovrride_signal_CAN1_T overridesignal;/* '<S75>/override signal' */
} B_CAN_NofaoffInput_DIM_model_T;

/* Block signals for system '<S81>/override signal' */
typedef struct {
  real32_T Switch;                     /* '<S82>/Switch' */
} B_ovrride_signal_CAN_T;

/* Block signals for system '<S81>/unit_conversion' */
typedef struct {
  real32_T output_signal;              /* '<S83>/Sum' */
} B_unit_conversion_T;

/* Block signals for system '<S56>/CAN_Input' */
typedef struct {
  B_unit_conversion_T unit_conversion_p;/* '<S81>/unit_conversion' */
  B_ovrride_signal_CAN_T overridesignal;/* '<S81>/override signal' */
} B_CAN_Input_DIM_model_T;

/* Block signals for system '<S100>/override signal' */
typedef struct {
  uint8_T Switch;                      /* '<S101>/Switch' */
} B_ovrride_signal_CAN1_m_T;

/* Block signals for system '<S89>/CAN_NofaoffInput' */
typedef struct {
  B_ovrride_signal_CAN1_m_T overridesignal;/* '<S100>/override signal' */
} B_CAN_NofaoffInput_DIM_model_m_T;

/* Block signals for system '<S124>/unit_conversion' */
typedef struct {
  real32_T output_signal;              /* '<S126>/Sum' */
} B_unit_conversion_n_T;

/* Block signals for system '<S116>/CAN_InputWithInValidValue' */
typedef struct {
  real32_T VINP_SigOut;                /* '<S124>/Switch' */
  B_ovrride_signal_CAN_T overridesignal;/* '<S124>/override signal' */
  B_unit_conversion_n_T unit_conversion_c;/* '<S124>/unit_conversion' */
} B_CAN_InputWithInValidValue_DIM_model_T;

/* Block signals for system '<S127>/override signal' */
typedef struct {
  uint8_T Switch;                      /* '<S128>/Switch' */
} B_ovrride_signal_CAN1_d_T;

/* Block signals for system '<S117>/CAN_NofaoffInput' */
typedef struct {
  B_ovrride_signal_CAN1_d_T overridesignal;/* '<S127>/override signal' */
} B_CAN_NofaoffInput_DIM_model_p_T;

/* Block signals for system '<S122>/CAN_InputWithInValidValue' */
typedef struct {
  real32_T VINP_SigOut;                /* '<S139>/Switch' */
  B_ovrride_signal_CAN_T overridesignal;/* '<S139>/override signal' */
  B_unit_conversion_T unit_conversion_g;/* '<S139>/unit_conversion' */
} B_CAN_InputWithInValidValue_DIM_model_n_T;

/* Block signals for system '<S195>/override signal' */
typedef struct {
  uint8_T Switch;                      /* '<S196>/Switch' */
} B_ovrride_signal_CAN_n_T;

/* Block signals for system '<S183>/CAN_Input' */
typedef struct {
  B_unit_conversion_T unit_conversion_l;/* '<S195>/unit_conversion' */
  B_ovrride_signal_CAN_n_T overridesignal;/* '<S195>/override signal' */
} B_CAN_Input_DIM_model_c_T;

/* Block signals for system '<S198>/override signal' */
typedef struct {
  uint16_T Switch;                     /* '<S199>/Switch' */
} B_ovrride_signal_CAN_i_T;

/* Block signals for system '<S198>/unit_conversion' */
typedef struct {
  real32_T output_signal;              /* '<S200>/Sum' */
} B_unit_conversion_nk_T;

/* Block signals for system '<S184>/CAN_Input' */
typedef struct {
  B_unit_conversion_nk_T unit_conversion_j;/* '<S198>/unit_conversion' */
  B_ovrride_signal_CAN_i_T overridesignal;/* '<S198>/override signal' */
} B_CAN_Input_DIM_model_a_T;

/* Block signals for system '<S207>/unit_conversion' */
typedef struct {
  real32_T output_signal;              /* '<S209>/Sum' */
} B_unit_conversion_j_T;

/* Block signals for system '<S188>/CAN_Input' */
typedef struct {
  B_unit_conversion_j_T unit_conversion_p;/* '<S207>/unit_conversion' */
  B_ovrride_signal_CAN_n_T overridesignal;/* '<S207>/override signal' */
} B_CAN_Input_DIM_model_d_T;

/* Block signals for system '<S242>/unit_conversion' */
typedef struct {
  real32_T output_signal;              /* '<S244>/Sum' */
} B_unit_conversion_d_T;

/* Block signals for system '<S222>/CAN_Input' */
typedef struct {
  B_unit_conversion_d_T unit_conversion_j;/* '<S242>/unit_conversion' */
  B_ovrride_signal_CAN_T overridesignal;/* '<S242>/override signal' */
} B_CAN_Input_DIM_model_i_T;

/* Block signals for system '<S245>/unit_conversion' */
typedef struct {
  uint16_T output_signal;              /* '<S247>/Sum' */
} B_unit_conversion_e_T;

/* Block signals for system '<S223>/CAN_Input' */
typedef struct {
  B_unit_conversion_e_T unit_conversion_m;/* '<S245>/unit_conversion' */
  B_ovrride_signal_CAN_i_T overridesignal;/* '<S245>/override signal' */
} B_CAN_Input_DIM_model_l_T;

/* Block signals for system '<S252>/override signal' */
typedef struct {
  int16_T Switch;                      /* '<S253>/Switch' */
} B_ovrride_signal_CAN_j_T;

/* Block signals for system '<S252>/unit_conversion' */
typedef struct {
  real32_T output_signal;              /* '<S254>/Sum' */
} B_unit_conversion_b_T;

/* Block signals for system '<S226>/CAN_Input' */
typedef struct {
  B_unit_conversion_b_T unit_conversion_e;/* '<S252>/unit_conversion' */
  B_ovrride_signal_CAN_j_T overridesignal;/* '<S252>/override signal' */
} B_CAN_Input_DIM_model_k_T;

/* Block signals for system '<S270>/unit_conversion' */
typedef struct {
  uint32_T output_signal;              /* '<S272>/Sum' */
} B_unit_conversion_by_T;

/* Block signals for system '<S234>/CAN_Input' */
typedef struct {
  B_unit_conversion_by_T unit_conversion_f;/* '<S270>/unit_conversion' */
  B_ovrride_signal_CAN_i_T overridesignal;/* '<S270>/override signal' */
} B_CAN_Input_DIM_model_i3_T;

/* Block signals for system '<S273>/override signal' */
typedef struct {
  uint16_T Switch;                     /* '<S274>/Switch' */
} B_ovrride_signal_CAN1_mq_T;

/* Block signals for system '<S235>/CAN_NofaoffInput' */
typedef struct {
  B_ovrride_signal_CAN1_mq_T overridesignal;/* '<S273>/override signal' */
} B_CAN_NofaoffInput_DIM_model_d_T;

/* Block signals for system '<S328>/override signal' */
typedef struct {
  real32_T Switch;                     /* '<S329>/Switch' */
} B_ovrride_signal_CAN1_a_T;

/* Block signals for system '<S288>/CAN_NofaoffInput' */
typedef struct {
  B_ovrride_signal_CAN1_a_T overridesignal;/* '<S328>/override signal' */
} B_CAN_NofaoffInput_DIM_model_ps_T;

/* Block signals for system '<S340>/unit_conversion' */
typedef struct {
  uint16_T output_signal;              /* '<S342>/Sum' */
} B_unit_conversion_f_T;

/* Block signals for system '<S294>/CAN_Input' */
typedef struct {
  B_unit_conversion_f_T unit_conversion_l;/* '<S340>/unit_conversion' */
  B_ovrride_signal_CAN_i_T overridesignal;/* '<S340>/override signal' */
} B_CAN_Input_DIM_model_e_T;

/* Block signals for system '<S302>/CAN_InputWithInvalidRange_Out' */
typedef struct {
  uint16_T VINP_SigOut;                /* '<S345>/Switch' */
  B_ovrride_signal_CAN_i_T overridesignal1;/* '<S345>/override signal1' */
  B_unit_conversion_by_T unit_conversion_k;/* '<S345>/unit_conversion' */
} B_CAN_InputWithInvalidRange_Out_DIM_model_T;

/* Block signals for system '<S356>/unit_conversion' */
typedef struct {
  real32_T output_signal;              /* '<S358>/Sum' */
} B_unit_conversion_m_T;

/* Block signals for system '<S307>/CAN_InputWithInValidValue' */
typedef struct {
  real32_T VINP_SigOut;                /* '<S356>/Switch' */
  B_ovrride_signal_CAN_T overridesignal;/* '<S356>/override signal' */
  B_unit_conversion_m_T unit_conversion_c;/* '<S356>/unit_conversion' */
} B_CAN_InputWithInValidValue_DIM_model_ng_T;

/* Block signals for system '<S318>/CAN_InputWithInvalidRange' */
typedef struct {
  real32_T VINP_SigOut;                /* '<S383>/Switch' */
  B_ovrride_signal_CAN_T overridesignal;/* '<S383>/override signal' */
  B_unit_conversion_T unit_conversion_h;/* '<S383>/unit_conversion' */
} B_CAN_InputWithInvalidRange_DIM_model_T;

/* Block signals for system '<S417>/override signal' */
typedef struct {
  uint32_T Switch;                     /* '<S418>/Switch' */
} B_ovrride_signal_CAN1_p_T;

/* Block signals for system '<S407>/CAN_NofaoffInput' */
typedef struct {
  B_ovrride_signal_CAN1_p_T overridesignal;/* '<S417>/override signal' */
} B_CAN_NofaoffInput_DIM_model_o_T;

/* Block signals for system '<S441>/unit_conversion' */
typedef struct {
  real32_T output_signal;              /* '<S443>/Sum' */
} B_unit_conversion_c_T;

/* Block signals for system '<S434>/CAN_Input' */
typedef struct {
  B_unit_conversion_c_T unit_conversion_a;/* '<S441>/unit_conversion' */
  B_ovrride_signal_CAN_T overridesignal;/* '<S441>/override signal' */
} B_CAN_Input_DIM_model_m_T;

/* Block signals for system '<S446>/override signal' */
typedef struct {
  real32_T Switch;                     /* '<S447>/Switch' */
} B_ovrride_signal_CAN1_g_T;

/* Block signals for system '<S436>/CAN_NofaoffInput' */
typedef struct {
  B_ovrride_signal_CAN1_g_T overridesignal;/* '<S446>/override signal' */
} B_CAN_NofaoffInput_DIM_model_g_T;

/* Block signals for system '<S452>/unit_conversion' */
typedef struct {
  real32_T output_signal;              /* '<S454>/Sum' */
} B_unit_conversion_bd_T;

/* Block signals for system '<S439>/CAN_Input' */
typedef struct {
  B_unit_conversion_bd_T unit_conversion_l;/* '<S452>/unit_conversion' */
  B_ovrride_signal_CAN_T overridesignal;/* '<S452>/override signal' */
} B_CAN_Input_DIM_model_ad_T;

/* Block signals for system '<S499>/override signal' */
typedef struct {
  uint8_T Switch;                      /* '<S500>/Switch' */
} B_ovrride_signal_CAN1_p4_T;

/* Block signals for system '<S474>/CAN_NofaoffInput' */
typedef struct {
  B_ovrride_signal_CAN1_p4_T overridesignal;/* '<S499>/override signal' */
} B_CAN_NofaoffInput_DIM_model_c_T;

/* Block signals for system '<S501>/override signal' */
typedef struct {
  boolean_T Switch;                    /* '<S502>/Switch' */
} B_ovrride_signal_CAN1_f_T;

/* Block signals for system '<S477>/CAN_NofaoffInput' */
typedef struct {
  B_ovrride_signal_CAN1_f_T overridesignal;/* '<S501>/override signal' */
} B_CAN_NofaoffInput_DIM_model_j_T;

/* Block signals for system '<S503>/override signal' */
typedef struct {
  real32_T Switch;                     /* '<S504>/Switch' */
} B_ovrride_signal_CAN_i3_T;

/* Block signals for system '<S503>/unit_conversion' */
typedef struct {
  real32_T output_signal;              /* '<S505>/Sum' */
} B_unit_conversion_i_T;

/* Block signals for system '<S480>/CAN_Input' */
typedef struct {
  B_unit_conversion_i_T unit_conversion_k;/* '<S503>/unit_conversion' */
  B_ovrride_signal_CAN_i3_T overridesignal;/* '<S503>/override signal' */
} B_CAN_Input_DIM_model_n_T;

/* Block signals for system '<S491>/CAN_Input' */
typedef struct {
  B_unit_conversion_c_T unit_conversion_i;/* '<S518>/unit_conversion' */
  B_ovrride_signal_CAN_i3_T overridesignal;/* '<S518>/override signal' */
} B_CAN_Input_DIM_model_g_T;

/* Block signals for system '<S521>/unit_conversion' */
typedef struct {
  real32_T output_signal;              /* '<S523>/Sum' */
} B_unit_conversion_el_T;

/* Block signals for system '<S495>/CAN_Input' */
typedef struct {
  B_unit_conversion_el_T unit_conversion_d;/* '<S521>/unit_conversion' */
  B_ovrride_signal_CAN_i3_T overridesignal;/* '<S521>/override signal' */
} B_CAN_Input_DIM_model_ig_T;

/* Block signals for system '<S558>/unit_conversion' */
typedef struct {
  real32_T output_signal;              /* '<S560>/Sum' */
} B_unit_conversion_iq_T;

/* Block signals for system '<S544>/CAN_Input' */
typedef struct {
  B_unit_conversion_iq_T unit_conversion_e;/* '<S558>/unit_conversion' */
  B_ovrride_signal_CAN_j_T overridesignal;/* '<S558>/override signal' */
} B_CAN_Input_DIM_model_m2_T;

/* Block signals for system '<S545>/CAN_Input' */
typedef struct {
  B_unit_conversion_n_T unit_conversion_l;/* '<S561>/unit_conversion' */
  B_ovrride_signal_CAN_T overridesignal;/* '<S561>/override signal' */
} B_CAN_Input_DIM_model_at_T;

/* Block signals for system '<S627>/override signal' */
typedef struct {
  int8_T Switch;                       /* '<S628>/Switch' */
} B_ovrride_signal_CAN_m_T;

/* Block signals for system '<S613>/CAN_Input' */
typedef struct {
  B_unit_conversion_b_T unit_conversion_m;/* '<S627>/unit_conversion' */
  B_ovrride_signal_CAN_m_T overridesignal;/* '<S627>/override signal' */
} B_CAN_Input_DIM_model_k2_T;

/* Block signals for system '<S626>/CAN_Input' */
typedef struct {
  B_unit_conversion_j_T unit_conversion_g;/* '<S654>/unit_conversion' */
  B_ovrride_signal_CAN_j_T overridesignal;/* '<S654>/override signal' */
} B_CAN_Input_DIM_model_i1_T;

/* Block signals for system '<S688>/CAN_Input' */
typedef struct {
  B_unit_conversion_j_T unit_conversion_g;/* '<S776>/unit_conversion' */
  B_ovrride_signal_CAN_T overridesignal;/* '<S776>/override signal' */
} B_CAN_Input_DIM_model_p_T;

/* Block signals for system '<S784>/unit_conversion' */
typedef struct {
  real32_T output_signal;              /* '<S786>/Sum' */
} B_unit_conversion_np_T;

/* Block signals for system '<S693>/CAN_InputWithInValidValue' */
typedef struct {
  real32_T VINP_SigOut;                /* '<S784>/Switch' */
  B_ovrride_signal_CAN_T overridesignal;/* '<S784>/override signal' */
  B_unit_conversion_np_T unit_conversion_j;/* '<S784>/unit_conversion' */
} B_CAN_InputWithInValidValue_DIM_model_m_T;

/* Block signals for system '<S699>/CAN_InputWithInvalidRange_Out' */
typedef struct {
  real32_T VINP_SigOut;                /* '<S800>/Switch' */
  B_ovrride_signal_CAN_T overridesignal1;/* '<S800>/override signal1' */
  B_unit_conversion_n_T unit_conversion_g;/* '<S800>/unit_conversion' */
} B_CAN_InputWithInvalidRange_Out_DIM_model_a_T;

/* Block signals for system '<S703>/CAN_Input' */
typedef struct {
  B_unit_conversion_e_T unit_conversion_c;/* '<S806>/unit_conversion' */
  B_ovrride_signal_CAN_n_T overridesignal;/* '<S806>/override signal' */
} B_CAN_Input_DIM_model_b_T;

/* Block signals for system '<S704>/CAN_InputWithInValidValue' */
typedef struct {
  uint16_T VINP_SigOut;                /* '<S809>/Switch' */
  B_ovrride_signal_CAN_n_T overridesignal;/* '<S809>/override signal' */
  B_unit_conversion_by_T unit_conversion_d;/* '<S809>/unit_conversion' */
} B_CAN_InputWithInValidValue_DIM_model_j_T;

/* Block signals for system '<S839>/unit_conversion' */
typedef struct {
  uint32_T output_signal;              /* '<S841>/Sum' */
} B_unit_conversion_bb_T;

/* Block signals for system '<S722>/CAN_Input' */
typedef struct {
  B_unit_conversion_bb_T unit_conversion_n;/* '<S839>/unit_conversion' */
  B_ovrride_signal_CAN_i_T overridesignal;/* '<S839>/override signal' */
} B_CAN_Input_DIM_model_br_T;

/* Block signals for system '<S741>/CAN_InputWithInValidValue' */
typedef struct {
  int16_T VINP_SigOut;                 /* '<S856>/Switch' */
  B_ovrride_signal_CAN_j_T overridesignal;/* '<S856>/override signal' */
  B_unit_conversion_iq_T unit_conversion_l;/* '<S856>/unit_conversion' */
} B_CAN_InputWithInValidValue_DIM_model_jr_T;

/* Block signals for system '<S753>/CAN_InputWithInValidValue' */
typedef struct {
  uint16_T VINP_SigOut;                /* '<S873>/Switch' */
  B_ovrride_signal_CAN_i_T overridesignal;/* '<S873>/override signal' */
  B_unit_conversion_by_T unit_conversion_l;/* '<S873>/unit_conversion' */
} B_CAN_InputWithInValidValue_DIM_model_g_T;

/* Block signals for system '<S758>/CAN_Input' */
typedef struct {
  B_unit_conversion_nk_T unit_conversion_b;/* '<S879>/unit_conversion' */
  B_ovrride_signal_CAN_T overridesignal;/* '<S879>/override signal' */
} B_CAN_Input_DIM_model_o_T;

/* Block signals for system '<S1046>/override signal' */
typedef struct {
  int16_T Switch;                      /* '<S1047>/Switch' */
} B_ovrride_signal_CAN1_aj_T;

/* Block signals for system '<S1002>/CAN_NofaoffInput' */
typedef struct {
  B_ovrride_signal_CAN1_aj_T overridesignal;/* '<S1046>/override signal' */
} B_CAN_NofaoffInput_DIM_model_cu_T;

/* Block signals for system '<S1070>/CAN_Input' */
typedef struct {
  B_unit_conversion_b_T unit_conversion_i;/* '<S1105>/unit_conversion' */
  B_ovrride_signal_CAN_T overridesignal;/* '<S1105>/override signal' */
} B_CAN_Input_DIM_model_gj_T;

/* Block signals for system '<S1131>/unit_conversion' */
typedef struct {
  uint32_T output_signal;              /* '<S1133>/Sum' */
} B_unit_conversion_l_T;

/* Block signals for system '<S1081>/CAN_Input' */
typedef struct {
  B_unit_conversion_l_T unit_conversion_l;/* '<S1131>/unit_conversion' */
  B_ovrride_signal_CAN_i_T overridesignal;/* '<S1131>/override signal' */
} B_CAN_Input_DIM_model_ci_T;

/* Block signals for system '<S1158>/Timer_Keep1' */
typedef struct {
  boolean_T RelationalOperator;        /* '<S1199>/Relational Operator' */
} B_Timer_Keep_DIM_model_T;

/* Block states (auto storage) for system '<S1158>/Timer_Keep1' */
typedef struct {
  uint32_T UnitDelay_DSTATE;           /* '<S1199>/UnitDelay' */
} DW_Timer_Keep_DIM_model_T;

/* Block signals for system '<S1211>/S-R Flip-Flop' */
typedef struct {
  boolean_T LogicalOperator3;          /* '<S1216>/Logical Operator3' */
} B_Flip_Flop_T;

/* Block states (auto storage) for system '<S1211>/S-R Flip-Flop' */
typedef struct {
  boolean_T UnitDelay_DSTATE;          /* '<S1216>/Unit Delay' */
} DW_Flip_Flop_T;

/* Block signals for system '<S1212>/S-R Flip-Flop' */
typedef struct {
  boolean_T LogicalOperator2;          /* '<S1217>/Logical Operator2' */
} B_Flip_Flop_i_T;

/* Block signals for system '<S1218>/Logic' */
typedef struct {
  boolean_T b_State_Dly;               /* '<S1218>/Logic' */
} B_TurnOn_Logic_T;

/* Block states (auto storage) for system '<S1218>/Logic' */
typedef struct {
  real32_T timer;                      /* '<S1218>/Logic' */
  uint8_T is_active_c2_DIM_lib;        /* '<S1218>/Logic' */
  uint8_T is_c2_DIM_lib;               /* '<S1218>/Logic' */
} DW_TurnOn_Logic_T;

/* Block signals for system '<S1212>/TurnOnDelay' */
typedef struct {
  B_TurnOn_Logic_T sf_Logic;           /* '<S1218>/Logic' */
} B_TurnOnDelay_DIM_model_T;

/* Block states (auto storage) for system '<S1212>/TurnOnDelay' */
typedef struct {
  DW_TurnOn_Logic_T sf_Logic;          /* '<S1218>/Logic' */
} DW_TurnOnDelay_DIM_model_T;

/* Block signals for system '<S1219>/Logic' */
typedef struct {
  boolean_T b_State_Dly;               /* '<S1219>/Logic' */
} B_TurnOn_Logic_e_T;

/* Block states (auto storage) for system '<S1219>/Logic' */
typedef struct {
  real32_T timer;                      /* '<S1219>/Logic' */
  uint8_T is_active_c2_DIM_lib;        /* '<S1219>/Logic' */
  uint8_T is_c2_DIM_lib;               /* '<S1219>/Logic' */
} DW_TurnOn_Logic_l_T;

/* Block signals for system '<S1212>/TurnOnDelay1' */
typedef struct {
  B_TurnOn_Logic_e_T sf_Logic;         /* '<S1219>/Logic' */
} B_TurnOnDelay_DIM_model_o_T;

/* Block states (auto storage) for system '<S1212>/TurnOnDelay1' */
typedef struct {
  DW_TurnOn_Logic_l_T sf_Logic;        /* '<S1219>/Logic' */
} DW_TurnOnDelay_DIM_model_l_T;

/* Block signals for system '<S1236>/resetting fault filter' */
typedef struct {
  boolean_T fault_flg;                 /* '<S1237>/rff_ctl' */
} B_ff_resetting_T;

/* Block states (auto storage) for system '<S1236>/resetting fault filter' */
typedef struct {
  uint32_T StartTime;                  /* '<S1237>/rff_ctl' */
  int16_T count;                       /* '<S1237>/rff_ctl' */
  boolean_T last_value;                /* '<S1237>/rff_ctl' */
} DW_ff_resetting_T;

/* Block signals for system '<S1172>/Digital_Input' */
typedef struct {
  boolean_T VINP_DigitalSiglOut_flg;   /* '<S1236>/Switch1' */
  B_ff_resetting_T resettingfaultfilter;/* '<S1236>/resetting fault filter' */
} B_Digital_Input_DIM_model_T;

/* Block states (auto storage) for system '<S1172>/Digital_Input' */
typedef struct {
  DW_ff_resetting_T resettingfaultfilter;/* '<S1236>/resetting fault filter' */
} DW_Digital_Input_DIM_model_T;

/* Block signals for system '<S1362>/override signal' */
typedef struct {
  uint16_T Switch;                     /* '<S1363>/Switch' */
} B_ovrride_signal_CAN1_b_T;

/* Block signals for system '<S1338>/CAN_NofaoffInput' */
typedef struct {
  B_ovrride_signal_CAN1_b_T overridesignal;/* '<S1362>/override signal' */
} B_CAN_NofaoffInput_DIM_model_b_T;

/* Block signals for system '<S1372>/override signal' */
typedef struct {
  uint16_T Switch;                     /* '<S1373>/Switch' */
} B_ovrride_signal_CAN_nq_T;

/* Block signals for system '<S1344>/CAN_Input' */
typedef struct {
  B_unit_conversion_e_T unit_conversion_p;/* '<S1372>/unit_conversion' */
  B_ovrride_signal_CAN_nq_T overridesignal;/* '<S1372>/override signal' */
} B_CAN_Input_DIM_model_m2j_T;

/* Block signals for system '<S1399>/override signal' */
typedef struct {
  int16_T Switch;                      /* '<S1400>/Switch' */
} B_ovrride_signal_CAN_h_T;

/* Block signals for system '<S1357>/CAN_Input' */
typedef struct {
  B_unit_conversion_iq_T unit_conversion_g;/* '<S1399>/unit_conversion' */
  B_ovrride_signal_CAN_h_T overridesignal;/* '<S1399>/override signal' */
} B_CAN_Input_DIM_model_d3_T;

/* Block signals for system '<S1416>/CAN_Input' */
typedef struct {
  B_unit_conversion_T unit_conversion_g;/* '<S1438>/unit_conversion' */
  B_ovrride_signal_CAN_i3_T overridesignal;/* '<S1438>/override signal' */
} B_CAN_Input_DIM_model_pe_T;

/* Block signals for system '<S1441>/override signal' */
typedef struct {
  int8_T Switch;                       /* '<S1442>/Switch' */
} B_ovrride_signal_CAN_nqh_T;

/* Block signals for system '<S1417>/CAN_Input' */
typedef struct {
  B_unit_conversion_b_T unit_conversion_f;/* '<S1441>/unit_conversion' */
  B_ovrride_signal_CAN_nqh_T overridesignal;/* '<S1441>/override signal' */
} B_CAN_Input_DIM_model_g0_T;

/* Block signals for system '<S1493>/CAN_Input' */
typedef struct {
  B_unit_conversion_i_T unit_conversion_o;/* '<S1511>/unit_conversion' */
  B_ovrride_signal_CAN_T overridesignal;/* '<S1511>/override signal' */
} B_CAN_Input_DIM_model_mr_T;

/* Block signals for system '<S2199>/divide' */
typedef struct {
  real32_T Switch;                     /* '<S2200>/Switch' */
} B_divide_DIM_model_T;

/* Block signals for system '<S2194>/rolling average' */
typedef struct {
  real32_T new_ave;                    /* '<S2199>/Switch1' */
  B_divide_DIM_model_T divide;         /* '<S2199>/divide' */
} B_rollingaverage_DIM_model_T;

/* Block states (auto storage) for system '<S2194>/rolling average' */
typedef struct {
  real_T IC_DSTATE;                    /* '<S2199>/IC' */
} DW_rollingaverage_DIM_model_T;

/* Block signals for system '<S2205>/Digital_Input' */
typedef struct {
  B_ff_resetting_T resettingfaultfilter;/* '<S2207>/resetting fault filter' */
} B_Digital_Input_DIM_model_n_T;

/* Block states (auto storage) for system '<S2205>/Digital_Input' */
typedef struct {
  DW_ff_resetting_T resettingfaultfilter;/* '<S2207>/resetting fault filter' */
} DW_Digital_Input_DIM_model_a_T;

/* Block signals for system '<S2206>/Digital_Input' */
typedef struct {
  B_ff_resetting_T resettingfaultfilter;/* '<S2210>/resetting fault filter' */
} B_Digital_Input_DIM_model_g_T;

/* Block states (auto storage) for system '<S2206>/Digital_Input' */
typedef struct {
  DW_ff_resetting_T resettingfaultfilter;/* '<S2210>/resetting fault filter' */
} DW_Digital_Input_DIM_model_f_T;

/* Block signals for system '<S2213>/Digital_Input' */
typedef struct {
  B_ff_resetting_T resettingfaultfilter;/* '<S2215>/resetting fault filter' */
} B_Digital_Input_DIM_model_i_T;

/* Block states (auto storage) for system '<S2213>/Digital_Input' */
typedef struct {
  DW_ff_resetting_T resettingfaultfilter;/* '<S2215>/resetting fault filter' */
} DW_Digital_Input_DIM_model_fs_T;

/* Block signals for system '<S2214>/Digital_Input' */
typedef struct {
  B_ff_resetting_T resettingfaultfilter;/* '<S2218>/resetting fault filter' */
} B_Digital_Input_DIM_model_p_T;

/* Block states (auto storage) for system '<S2214>/Digital_Input' */
typedef struct {
  DW_ff_resetting_T resettingfaultfilter;/* '<S2218>/resetting fault filter' */
} DW_Digital_Input_DIM_model_o_T;

/* Block signals for system '<S2164>/Digital_Input' */
typedef struct {
  B_ff_resetting_T resettingfaultfilter;/* '<S2221>/resetting fault filter' */
} B_Digital_Input_DIM_model_c_T;

/* Block states (auto storage) for system '<S2164>/Digital_Input' */
typedef struct {
  DW_ff_resetting_T resettingfaultfilter;/* '<S2221>/resetting fault filter' */
} DW_Digital_Input_DIM_model_c_T;

/* Block signals for system '<S2165>/Digital_Input' */
typedef struct {
  B_ff_resetting_T resettingfaultfilter;/* '<S2224>/resetting fault filter' */
} B_Digital_Input_DIM_model_m_T;

/* Block states (auto storage) for system '<S2165>/Digital_Input' */
typedef struct {
  DW_ff_resetting_T resettingfaultfilter;/* '<S2224>/resetting fault filter' */
} DW_Digital_Input_DIM_model_b_T;

/* Block signals for system '<S2166>/Digital_Input' */
typedef struct {
  B_ff_resetting_T resettingfaultfilter;/* '<S2227>/resetting fault filter' */
} B_Digital_Input_DIM_model_p1_T;

/* Block states (auto storage) for system '<S2166>/Digital_Input' */
typedef struct {
  DW_ff_resetting_T resettingfaultfilter;/* '<S2227>/resetting fault filter' */
} DW_Digital_Input_DIM_model_l_T;

/* Block signals for system '<S2167>/Digital_Input' */
typedef struct {
  B_ff_resetting_T resettingfaultfilter;/* '<S2230>/resetting fault filter' */
} B_Digital_Input_DIM_model_a_T;

/* Block states (auto storage) for system '<S2167>/Digital_Input' */
typedef struct {
  DW_ff_resetting_T resettingfaultfilter;/* '<S2230>/resetting fault filter' */
} DW_Digital_Input_DIM_model_k_T;

/* Block signals for system '<S2168>/Digital_Input' */
typedef struct {
  B_ff_resetting_T resettingfaultfilter;/* '<S2233>/resetting fault filter' */
} B_Digital_Input_DIM_model_h_T;

/* Block states (auto storage) for system '<S2168>/Digital_Input' */
typedef struct {
  DW_ff_resetting_T resettingfaultfilter;/* '<S2233>/resetting fault filter' */
} DW_Digital_Input_DIM_model_bw_T;

/* Block signals for system '<S2169>/Digital_Input' */
typedef struct {
  B_ff_resetting_T resettingfaultfilter;/* '<S2236>/resetting fault filter' */
} B_Digital_Input_DIM_model_f_T;

/* Block states (auto storage) for system '<S2169>/Digital_Input' */
typedef struct {
  DW_ff_resetting_T resettingfaultfilter;/* '<S2236>/resetting fault filter' */
} DW_Digital_Input_DIM_model_i_T;

/* Block signals for system '<S2170>/Digital_Input' */
typedef struct {
  B_ff_resetting_T resettingfaultfilter;/* '<S2239>/resetting fault filter' */
} B_Digital_Input_DIM_model_d_T;

/* Block states (auto storage) for system '<S2170>/Digital_Input' */
typedef struct {
  DW_ff_resetting_T resettingfaultfilter;/* '<S2239>/resetting fault filter' */
} DW_Digital_Input_DIM_model_g_T;

/* Block signals for system '<S2171>/Digital_Input' */
typedef struct {
  B_ff_resetting_T resettingfaultfilter;/* '<S2242>/resetting fault filter' */
} B_Digital_Input_DIM_model_b_T;

/* Block states (auto storage) for system '<S2171>/Digital_Input' */
typedef struct {
  DW_ff_resetting_T resettingfaultfilter;/* '<S2242>/resetting fault filter' */
} DW_Digital_Input_DIM_model_o5_T;

/* Block signals for system '<S2172>/Digital_Input' */
typedef struct {
  B_ff_resetting_T resettingfaultfilter;/* '<S2245>/resetting fault filter' */
} B_Digital_Input_DIM_model_o_T;

/* Block states (auto storage) for system '<S2172>/Digital_Input' */
typedef struct {
  DW_ff_resetting_T resettingfaultfilter;/* '<S2245>/resetting fault filter' */
} DW_Digital_Input_DIM_model_ik_T;

/* Block signals for system '<S2173>/Digital_Input' */
typedef struct {
  B_ff_resetting_T resettingfaultfilter;/* '<S2248>/resetting fault filter' */
} B_Digital_Input_DIM_model_go_T;

/* Block states (auto storage) for system '<S2173>/Digital_Input' */
typedef struct {
  DW_ff_resetting_T resettingfaultfilter;/* '<S2248>/resetting fault filter' */
} DW_Digital_Input_DIM_model_kd_T;

/* Block signals for system '<S2174>/Digital_Input' */
typedef struct {
  B_ff_resetting_T resettingfaultfilter;/* '<S2251>/resetting fault filter' */
} B_Digital_Input_DIM_model_p0_T;

/* Block states (auto storage) for system '<S2174>/Digital_Input' */
typedef struct {
  DW_ff_resetting_T resettingfaultfilter;/* '<S2251>/resetting fault filter' */
} DW_Digital_Input_DIM_model_bi_T;

/* Block signals for system '<S2175>/Digital_Input' */
typedef struct {
  B_ff_resetting_T resettingfaultfilter;/* '<S2254>/resetting fault filter' */
} B_Digital_Input_DIM_model_mn_T;

/* Block states (auto storage) for system '<S2175>/Digital_Input' */
typedef struct {
  DW_ff_resetting_T resettingfaultfilter;/* '<S2254>/resetting fault filter' */
} DW_Digital_Input_DIM_model_l4_T;

/* Block signals for system '<S2176>/Digital_Input' */
typedef struct {
  B_ff_resetting_T resettingfaultfilter;/* '<S2257>/resetting fault filter' */
} B_Digital_Input_DIM_model_bo_T;

/* Block states (auto storage) for system '<S2176>/Digital_Input' */
typedef struct {
  DW_ff_resetting_T resettingfaultfilter;/* '<S2257>/resetting fault filter' */
} DW_Digital_Input_DIM_model_h_T;

/* Block signals for system '<S2177>/Digital_Input' */
typedef struct {
  B_ff_resetting_T resettingfaultfilter;/* '<S2260>/resetting fault filter' */
} B_Digital_Input_DIM_model_dc_T;

/* Block states (auto storage) for system '<S2177>/Digital_Input' */
typedef struct {
  DW_ff_resetting_T resettingfaultfilter;/* '<S2260>/resetting fault filter' */
} DW_Digital_Input_DIM_model_d_T;

/* Invariant block signals for system '<S1212>/S-R Flip-Flop' */
typedef struct {
  const boolean_T LogicalOperator1;    /* '<S1217>/Logical Operator1' */
} ConstB_Flip_Flop_n_T;

extern void ovrride_signal_CAN1(boolean_T rtu_signal_raw, boolean_T
  rtu_cal_ovrdflg, boolean_T rtu_cal_ovrdval, B_ovrride_signal_CAN1_T *localB);
extern void DIM_model_CAN_NofaoffInput(boolean_T rtu_VHAL_SigIn, boolean_T
  rtu_KINP_cal_ovrdflg, boolean_T rtu_KINP_cal_ovrdval,
  B_CAN_NofaoffInput_DIM_model_T *localB);
extern void ovrride_signal_CAN(real32_T rtu_signal_raw, boolean_T
  rtu_cal_ovrdflg, real32_T rtu_cal_ovrdval, B_ovrride_signal_CAN_T *localB);
extern void unit_conversion(real32_T rtu_input_signal, real32_T rtu_signal_gain,
  uint8_T rtu_signal_offset, B_unit_conversion_T *localB);
extern void DIM_model_CAN_Input(real32_T rtu_VHAL_SigIn, real32_T
  rtu_KINP_sigConv_gain, uint8_T rtu_KINP_sigConv_offset, boolean_T
  rtu_KINP_cal_ovrdflg, real32_T rtu_KINP_cal_ovrdval, B_CAN_Input_DIM_model_T
  *localB);
extern void DIM_model_ovrride_signal_CAN1(uint8_T rtu_signal_raw, boolean_T
  rtu_cal_ovrdflg, uint8_T rtu_cal_ovrdval, B_ovrride_signal_CAN1_m_T *localB);
extern void DIM_model_CAN_NofaoffInput_b(uint8_T rtu_VHAL_SigIn, boolean_T
  rtu_KINP_cal_ovrdflg, uint8_T rtu_KINP_cal_ovrdval,
  B_CAN_NofaoffInput_DIM_model_m_T *localB);
extern void DIM_model_unit_conversion(uint16_T rtu_input_signal, real32_T
  rtu_signal_gain, uint8_T rtu_signal_offset, B_unit_conversion_n_T *localB);
extern void DIM_model_CAN_InputWithInValidValue(uint16_T rtu_VHAL_SigIn,
  real32_T rtu_KINP_sigConv_gain, uint8_T rtu_KINP_sigConv_offset, boolean_T
  rtu_KINP_cal_ovrdflg, real32_T rtu_KINP_cal_ovrdval, uint16_T rtu_InValidValue,
  B_CAN_InputWithInValidValue_DIM_model_T *localB);
extern void DIM_model_ovrride_signal_CAN1_k(uint8_T rtu_signal_raw, boolean_T
  rtu_cal_ovrdflg, boolean_T rtu_cal_ovrdval, B_ovrride_signal_CAN1_d_T *localB);
extern void DIM_model_CAN_NofaoffInput_o(uint8_T rtu_VHAL_SigIn, boolean_T
  rtu_KINP_cal_ovrdflg, boolean_T rtu_KINP_cal_ovrdval,
  B_CAN_NofaoffInput_DIM_model_p_T *localB);
extern void DIM_model_CAN_InputWithInValidValue_m(real32_T rtu_VHAL_SigIn,
  real32_T rtu_KINP_sigConv_gain, uint8_T rtu_KINP_sigConv_offset, boolean_T
  rtu_KINP_cal_ovrdflg, real32_T rtu_KINP_cal_ovrdval, uint16_T rtu_InValidValue,
  B_CAN_InputWithInValidValue_DIM_model_n_T *localB);
extern void DIM_model_ovrride_signal_CAN(uint8_T rtu_signal_raw, boolean_T
  rtu_cal_ovrdflg, uint8_T rtu_cal_ovrdval, B_ovrride_signal_CAN_n_T *localB);
extern void DIM_model_CAN_Input_j(real32_T rtu_VHAL_SigIn, real32_T
  rtu_KINP_sigConv_gain, uint8_T rtu_KINP_sigConv_offset, boolean_T
  rtu_KINP_cal_ovrdflg, uint8_T rtu_KINP_cal_ovrdval, B_CAN_Input_DIM_model_c_T *
  localB);
extern void DIM_model_ovrride_signal_CAN_g(uint16_T rtu_signal_raw, boolean_T
  rtu_cal_ovrdflg, uint16_T rtu_cal_ovrdval, B_ovrride_signal_CAN_i_T *localB);
extern void DIM_model_unit_conversion_j(real32_T rtu_input_signal, real32_T
  rtu_signal_gain, uint16_T rtu_signal_offset, B_unit_conversion_nk_T *localB);
extern void DIM_model_CAN_Input_b(real32_T rtu_VHAL_SigIn, real32_T
  rtu_KINP_sigConv_gain, uint16_T rtu_KINP_sigConv_offset, boolean_T
  rtu_KINP_cal_ovrdflg, uint16_T rtu_KINP_cal_ovrdval, B_CAN_Input_DIM_model_a_T
  *localB);
extern void DIM_model_unit_conversion_p(real32_T rtu_input_signal, real32_T
  rtu_signal_gain, int16_T rtu_signal_offset, B_unit_conversion_j_T *localB);
extern void DIM_model_CAN_Input_o(real32_T rtu_VHAL_SigIn, real32_T
  rtu_KINP_sigConv_gain, int16_T rtu_KINP_sigConv_offset, boolean_T
  rtu_KINP_cal_ovrdflg, uint8_T rtu_KINP_cal_ovrdval, B_CAN_Input_DIM_model_d_T *
  localB);
extern void DIM_model_unit_conversion_j4(real32_T rtu_input_signal, real32_T
  rtu_signal_gain, boolean_T rtu_signal_offset, B_unit_conversion_d_T *localB);
extern void DIM_model_CAN_Input_l(real32_T rtu_VHAL_SigIn, real32_T
  rtu_KINP_sigConv_gain, boolean_T rtu_KINP_sigConv_offset, boolean_T
  rtu_KINP_cal_ovrdflg, real32_T rtu_KINP_cal_ovrdval, B_CAN_Input_DIM_model_i_T
  *localB);
extern void DIM_model_unit_conversion_m(uint8_T rtu_input_signal, uint8_T
  rtu_signal_gain, uint8_T rtu_signal_offset, B_unit_conversion_e_T *localB);
extern void DIM_model_CAN_Input_p(uint8_T rtu_VHAL_SigIn, uint8_T
  rtu_KINP_sigConv_gain, uint8_T rtu_KINP_sigConv_offset, boolean_T
  rtu_KINP_cal_ovrdflg, uint16_T rtu_KINP_cal_ovrdval, B_CAN_Input_DIM_model_l_T
  *localB);
extern void DIM_model_ovrride_signal_CAN_c(int16_T rtu_signal_raw, boolean_T
  rtu_cal_ovrdflg, int16_T rtu_cal_ovrdval, B_ovrride_signal_CAN_j_T *localB);
extern void DIM_model_unit_conversion_e(real32_T rtu_input_signal, real32_T
  rtu_signal_gain, int8_T rtu_signal_offset, B_unit_conversion_b_T *localB);
extern void DIM_model_CAN_Input_g(real32_T rtu_VHAL_SigIn, real32_T
  rtu_KINP_sigConv_gain, int8_T rtu_KINP_sigConv_offset, boolean_T
  rtu_KINP_cal_ovrdflg, int16_T rtu_KINP_cal_ovrdval, B_CAN_Input_DIM_model_k_T *
  localB);
extern void DIM_model_unit_conversion_f(uint16_T rtu_input_signal, uint8_T
  rtu_signal_gain, uint8_T rtu_signal_offset, B_unit_conversion_by_T *localB);
extern void DIM_model_CAN_Input_ge(uint16_T rtu_VHAL_SigIn, uint8_T
  rtu_KINP_sigConv_gain, uint8_T rtu_KINP_sigConv_offset, boolean_T
  rtu_KINP_cal_ovrdflg, uint16_T rtu_KINP_cal_ovrdval,
  B_CAN_Input_DIM_model_i3_T *localB);
extern void DIM_model_ovrride_signal_CAN1_m(uint16_T rtu_signal_raw, boolean_T
  rtu_cal_ovrdflg, uint16_T rtu_cal_ovrdval, B_ovrride_signal_CAN1_mq_T *localB);
extern void DIM_model_CAN_NofaoffInput_p(uint16_T rtu_VHAL_SigIn, boolean_T
  rtu_KINP_cal_ovrdflg, uint16_T rtu_KINP_cal_ovrdval,
  B_CAN_NofaoffInput_DIM_model_d_T *localB);
extern void DIM_model_ovrride_signal_CAN1_b(real32_T rtu_signal_raw, boolean_T
  rtu_cal_ovrdflg, real32_T rtu_cal_ovrdval, B_ovrride_signal_CAN1_a_T *localB);
extern void DIM_model_CAN_NofaoffInput_e(real32_T rtu_VHAL_SigIn, boolean_T
  rtu_KINP_cal_ovrdflg, real32_T rtu_KINP_cal_ovrdval,
  B_CAN_NofaoffInput_DIM_model_ps_T *localB);
extern void DIM_model_unit_conversion_l(uint8_T rtu_input_signal, uint8_T
  rtu_signal_gain, uint16_T rtu_signal_offset, B_unit_conversion_f_T *localB);
extern void DIM_model_CAN_Input_c(uint8_T rtu_VHAL_SigIn, uint8_T
  rtu_KINP_sigConv_gain, uint16_T rtu_KINP_sigConv_offset, boolean_T
  rtu_KINP_cal_ovrdflg, uint16_T rtu_KINP_cal_ovrdval, B_CAN_Input_DIM_model_e_T
  *localB);
extern void DIM_model_CAN_InputWithInvalidRange_Out(uint16_T rtu_VHAL_SigIn,
  uint8_T rtu_KINP_sigConv_gain, uint8_T rtu_KINP_sigConv_offset, boolean_T
  rtu_KINP_cal_ovrdflg, uint16_T rtu_KINP_cal_ovrdval, uint16_T rtu_InValidLow,
  uint16_T rtu_InValidUp, uint16_T rtu_InvalidVal,
  B_CAN_InputWithInvalidRange_Out_DIM_model_T *localB);
extern void DIM_model_unit_conversion_c(uint16_T rtu_input_signal, real32_T
  rtu_signal_gain, real32_T rtu_signal_offset, B_unit_conversion_m_T *localB);
extern void DIM_model_CAN_InputWithInValidValue_o(uint16_T rtu_VHAL_SigIn,
  real32_T rtu_KINP_sigConv_gain, real32_T rtu_KINP_sigConv_offset, boolean_T
  rtu_KINP_cal_ovrdflg, real32_T rtu_KINP_cal_ovrdval, uint16_T rtu_InValidValue,
  B_CAN_InputWithInValidValue_DIM_model_ng_T *localB);
extern void DIM_model_CAN_InputWithInvalidRange(real32_T rtu_VHAL_SigIn,
  real32_T rtu_KINP_sigConv_gain, uint8_T rtu_KINP_sigConv_offset, boolean_T
  rtu_KINP_cal_ovrdflg, real32_T rtu_KINP_cal_ovrdval, uint8_T rtu_InValidLow,
  uint8_T rtu_InValidUp, B_CAN_InputWithInvalidRange_DIM_model_T *localB);
extern void DIM_model_ovrride_signal_CAN1_h(uint32_T rtu_signal_raw, boolean_T
  rtu_cal_ovrdflg, uint32_T rtu_cal_ovrdval, B_ovrride_signal_CAN1_p_T *localB);
extern void DIM_model_CAN_NofaoffInput_e4(uint32_T rtu_VHAL_SigIn, boolean_T
  rtu_KINP_cal_ovrdflg, uint32_T rtu_KINP_cal_ovrdval,
  B_CAN_NofaoffInput_DIM_model_o_T *localB);
extern void DIM_model_unit_conversion_a(real32_T rtu_input_signal, real32_T
  rtu_signal_gain, real32_T rtu_signal_offset, B_unit_conversion_c_T *localB);
extern void DIM_model_CAN_Input_cg(real32_T rtu_VHAL_SigIn, real32_T
  rtu_KINP_sigConv_gain, real32_T rtu_KINP_sigConv_offset, boolean_T
  rtu_KINP_cal_ovrdflg, real32_T rtu_KINP_cal_ovrdval, B_CAN_Input_DIM_model_m_T
  *localB);
extern void DIM_model_ovrride_signal_CAN1_hr(real32_T rtu_signal_raw, boolean_T
  rtu_cal_ovrdflg, uint8_T rtu_cal_ovrdval, B_ovrride_signal_CAN1_g_T *localB);
extern void DIM_model_CAN_NofaoffInput_f(real32_T rtu_VHAL_SigIn, boolean_T
  rtu_KINP_cal_ovrdflg, uint8_T rtu_KINP_cal_ovrdval,
  B_CAN_NofaoffInput_DIM_model_g_T *localB);
extern void DIM_model_unit_conversion_lt(int32_T rtu_input_signal, real32_T
  rtu_signal_gain, uint8_T rtu_signal_offset, B_unit_conversion_bd_T *localB);
extern void DIM_model_CAN_Input_o3(int32_T rtu_VHAL_SigIn, real32_T
  rtu_KINP_sigConv_gain, uint8_T rtu_KINP_sigConv_offset, boolean_T
  rtu_KINP_cal_ovrdflg, real32_T rtu_KINP_cal_ovrdval,
  B_CAN_Input_DIM_model_ad_T *localB);
extern void DIM_model_ovrride_signal_CAN1_d(uint8_T rtu_signal_raw,
  B_ovrride_signal_CAN1_p4_T *localB);
extern void DIM_model_CAN_NofaoffInput_c(uint8_T rtu_VHAL_SigIn,
  B_CAN_NofaoffInput_DIM_model_c_T *localB);
extern void DIM_model_ovrride_signal_CAN1_i(boolean_T rtu_signal_raw,
  B_ovrride_signal_CAN1_f_T *localB);
extern void DIM_model_CAN_NofaoffInput_c2(boolean_T rtu_VHAL_SigIn,
  B_CAN_NofaoffInput_DIM_model_j_T *localB);
extern void DIM_model_ovrride_signal_CAN_d(real32_T rtu_signal_raw,
  B_ovrride_signal_CAN_i3_T *localB);
extern void DIM_model_unit_conversion_k(uint8_T rtu_input_signal, real32_T
  rtu_signal_gain, uint8_T rtu_signal_offset, B_unit_conversion_i_T *localB);
extern void DIM_model_CAN_Input_cf(uint8_T rtu_VHAL_SigIn, real32_T
  rtu_KINP_sigConv_gain, uint8_T rtu_KINP_sigConv_offset,
  B_CAN_Input_DIM_model_n_T *localB);
extern void DIM_model_CAN_Input_f(real32_T rtu_VHAL_SigIn, real32_T
  rtu_KINP_sigConv_gain, real32_T rtu_KINP_sigConv_offset,
  B_CAN_Input_DIM_model_g_T *localB);
extern void DIM_model_unit_conversion_d(uint8_T rtu_input_signal, real32_T
  rtu_signal_gain, real32_T rtu_signal_offset, B_unit_conversion_el_T *localB);
extern void DIM_model_CAN_Input_p4(uint8_T rtu_VHAL_SigIn, real32_T
  rtu_KINP_sigConv_gain, real32_T rtu_KINP_sigConv_offset,
  B_CAN_Input_DIM_model_ig_T *localB);
extern void DIM_model_unit_conversion_et(uint8_T rtu_input_signal, real32_T
  rtu_signal_gain, int8_T rtu_signal_offset, B_unit_conversion_iq_T *localB);
extern void DIM_model_CAN_Input_b2(uint8_T rtu_VHAL_SigIn, real32_T
  rtu_KINP_sigConv_gain, int8_T rtu_KINP_sigConv_offset, boolean_T
  rtu_KINP_cal_ovrdflg, int16_T rtu_KINP_cal_ovrdval, B_CAN_Input_DIM_model_m2_T
  *localB);
extern void DIM_model_CAN_Input_a(uint16_T rtu_VHAL_SigIn, real32_T
  rtu_KINP_sigConv_gain, uint8_T rtu_KINP_sigConv_offset, boolean_T
  rtu_KINP_cal_ovrdflg, real32_T rtu_KINP_cal_ovrdval,
  B_CAN_Input_DIM_model_at_T *localB);
extern void DIM_model_ovrride_signal_CAN_f(int8_T rtu_signal_raw, boolean_T
  rtu_cal_ovrdflg, int8_T rtu_cal_ovrdval, B_ovrride_signal_CAN_m_T *localB);
extern void DIM_model_CAN_Input_g3(real32_T rtu_VHAL_SigIn, real32_T
  rtu_KINP_sigConv_gain, int8_T rtu_KINP_sigConv_offset, boolean_T
  rtu_KINP_cal_ovrdflg, int8_T rtu_KINP_cal_ovrdval, B_CAN_Input_DIM_model_k2_T *
  localB);
extern void DIM_model_CAN_Input_i(real32_T rtu_VHAL_SigIn, real32_T
  rtu_KINP_sigConv_gain, int16_T rtu_KINP_sigConv_offset, boolean_T
  rtu_KINP_cal_ovrdflg, int16_T rtu_KINP_cal_ovrdval, B_CAN_Input_DIM_model_i1_T
  *localB);
extern void DIM_model_CAN_Input_n(real32_T rtu_VHAL_SigIn, real32_T
  rtu_KINP_sigConv_gain, int16_T rtu_KINP_sigConv_offset, boolean_T
  rtu_KINP_cal_ovrdflg, real32_T rtu_KINP_cal_ovrdval, B_CAN_Input_DIM_model_p_T
  *localB);
extern void DIM_model_unit_conversion_jk(uint16_T rtu_input_signal, real32_T
  rtu_signal_gain, uint16_T rtu_signal_offset, B_unit_conversion_np_T *localB);
extern void DIM_model_CAN_InputWithInValidValue_i(uint16_T rtu_VHAL_SigIn,
  real32_T rtu_KINP_sigConv_gain, uint16_T rtu_KINP_sigConv_offset, boolean_T
  rtu_KINP_cal_ovrdflg, real32_T rtu_KINP_cal_ovrdval, uint16_T rtu_InValidValue,
  B_CAN_InputWithInValidValue_DIM_model_m_T *localB);
extern void DIM_model_CAN_InputWithInvalidRange_Out_j(uint16_T rtu_VHAL_SigIn,
  real32_T rtu_KINP_sigConv_gain, uint8_T rtu_KINP_sigConv_offset, boolean_T
  rtu_KINP_cal_ovrdflg, real32_T rtu_KINP_cal_ovrdval, uint16_T rtu_InValidLow,
  uint16_T rtu_InValidUp, uint16_T rtu_InvalidVal,
  B_CAN_InputWithInvalidRange_Out_DIM_model_a_T *localB);
extern void DIM_model_CAN_Input_no(uint8_T rtu_VHAL_SigIn, uint8_T
  rtu_KINP_sigConv_gain, uint8_T rtu_KINP_sigConv_offset, boolean_T
  rtu_KINP_cal_ovrdflg, uint8_T rtu_KINP_cal_ovrdval, B_CAN_Input_DIM_model_b_T *
  localB);
extern void DIM_model_CAN_InputWithInValidValue_h(uint16_T rtu_VHAL_SigIn,
  uint8_T rtu_KINP_sigConv_gain, uint8_T rtu_KINP_sigConv_offset, boolean_T
  rtu_KINP_cal_ovrdflg, uint8_T rtu_KINP_cal_ovrdval, uint16_T rtu_InValidValue,
  B_CAN_InputWithInValidValue_DIM_model_j_T *localB);
extern void DIM_model_unit_conversion_n(uint16_T rtu_input_signal, uint16_T
  rtu_signal_gain, uint8_T rtu_signal_offset, B_unit_conversion_bb_T *localB);
extern void DIM_model_CAN_Input_k(uint16_T rtu_VHAL_SigIn, uint16_T
  rtu_KINP_sigConv_gain, uint8_T rtu_KINP_sigConv_offset, boolean_T
  rtu_KINP_cal_ovrdflg, uint16_T rtu_KINP_cal_ovrdval,
  B_CAN_Input_DIM_model_br_T *localB);
extern void DIM_model_CAN_InputWithInValidValue_k(uint8_T rtu_VHAL_SigIn,
  real32_T rtu_KINP_sigConv_gain, int8_T rtu_KINP_sigConv_offset, boolean_T
  rtu_KINP_cal_ovrdflg, int16_T rtu_KINP_cal_ovrdval, uint8_T rtu_InValidValue,
  B_CAN_InputWithInValidValue_DIM_model_jr_T *localB);
extern void DIM_model_CAN_InputWithInValidValue_h5(uint16_T rtu_VHAL_SigIn,
  uint8_T rtu_KINP_sigConv_gain, uint8_T rtu_KINP_sigConv_offset, boolean_T
  rtu_KINP_cal_ovrdflg, uint16_T rtu_KINP_cal_ovrdval, uint16_T rtu_InValidValue,
  B_CAN_InputWithInValidValue_DIM_model_g_T *localB);
extern void DIM_model_CAN_Input_ir(real32_T rtu_VHAL_SigIn, real32_T
  rtu_KINP_sigConv_gain, uint16_T rtu_KINP_sigConv_offset, boolean_T
  rtu_KINP_cal_ovrdflg, real32_T rtu_KINP_cal_ovrdval, B_CAN_Input_DIM_model_o_T
  *localB);
extern void DIM_model_ovrride_signal_CAN1_g(int16_T rtu_signal_raw, boolean_T
  rtu_cal_ovrdflg, int16_T rtu_cal_ovrdval, B_ovrride_signal_CAN1_aj_T *localB);
extern void DIM_model_CAN_NofaoffInput_pm(int16_T rtu_VHAL_SigIn, boolean_T
  rtu_KINP_cal_ovrdflg, int16_T rtu_KINP_cal_ovrdval,
  B_CAN_NofaoffInput_DIM_model_cu_T *localB);
extern void DIM_model_CAN_Input_ks(real32_T rtu_VHAL_SigIn, real32_T
  rtu_KINP_sigConv_gain, int8_T rtu_KINP_sigConv_offset, boolean_T
  rtu_KINP_cal_ovrdflg, real32_T rtu_KINP_cal_ovrdval,
  B_CAN_Input_DIM_model_gj_T *localB);
extern void DIM_model_unit_conversion_ld(uint16_T rtu_input_signal, uint16_T
  rtu_signal_gain, uint16_T rtu_signal_offset, B_unit_conversion_l_T *localB);
extern void DIM_model_CAN_Input_ow(uint16_T rtu_VHAL_SigIn, uint16_T
  rtu_KINP_sigConv_gain, uint16_T rtu_KINP_sigConv_offset, boolean_T
  rtu_KINP_cal_ovrdflg, uint16_T rtu_KINP_cal_ovrdval,
  B_CAN_Input_DIM_model_ci_T *localB);
extern void DIM_model_Timer_Keep(uint16_T rtu_KeepTimeDelay_s, boolean_T
  rtu_Enable, boolean_T rtu_Reset, B_Timer_Keep_DIM_model_T *localB,
  DW_Timer_Keep_DIM_model_T *localDW);
extern void Flip_Flop_Init(DW_Flip_Flop_T *localDW, boolean_T
  rtp_initial_condition);
extern void Flip_Flop(boolean_T rtu_S, boolean_T rtu_R, B_Flip_Flop_T *localB,
                      DW_Flip_Flop_T *localDW);
extern void DIM_model_Flip_Flop_Init(B_Flip_Flop_i_T *localB, boolean_T
  rtp_initial_condition);
extern void DIM_model_Flip_Flop(boolean_T rtu_S, B_Flip_Flop_i_T *localB, const
  ConstB_Flip_Flop_n_T *localC);
extern void TurnOn_Logic_Init(B_TurnOn_Logic_T *localB, DW_TurnOn_Logic_T
  *localDW);
extern void TurnOn_Logic(boolean_T rtu_b_State, real32_T rtu_delaytime, real32_T
  rtu_steptime, B_TurnOn_Logic_T *localB, DW_TurnOn_Logic_T *localDW);
extern void DIM_model_TurnOnDelay_Init(B_TurnOnDelay_DIM_model_T *localB,
  DW_TurnOnDelay_DIM_model_T *localDW);
extern void DIM_model_TurnOnDelay(boolean_T rtu_In, real32_T rtu_DelayT,
  B_TurnOnDelay_DIM_model_T *localB, DW_TurnOnDelay_DIM_model_T *localDW);
extern void DIM_model_TurnOn_Logic_Init(B_TurnOn_Logic_e_T *localB,
  DW_TurnOn_Logic_l_T *localDW);
extern void DIM_model_TurnOn_Logic(boolean_T rtu_b_State, real32_T rtu_delaytime,
  real32_T rtu_steptime, B_TurnOn_Logic_e_T *localB, DW_TurnOn_Logic_l_T
  *localDW);
extern void DIM_model_TurnOnDelay1_Init(B_TurnOnDelay_DIM_model_o_T *localB,
  DW_TurnOnDelay_DIM_model_l_T *localDW);
extern void DIM_model_TurnOnDelay1(boolean_T rtu_In, real32_T rtu_DelayT,
  B_TurnOnDelay_DIM_model_o_T *localB, DW_TurnOnDelay_DIM_model_l_T *localDW);
extern void ff_resetting_Init(B_ff_resetting_T *localB, DW_ff_resetting_T
  *localDW);
extern void ff_resetting(boolean_T rtu_i_fault, uint8_T rtu_sat, uint8_T rtu_inc,
  uint8_T rtu_dec, uint8_T rtu_ConfirmTime, B_ff_resetting_T *localB,
  DW_ff_resetting_T *localDW);
extern void DIM_model_Digital_Input_Init(B_Digital_Input_DIM_model_T *localB,
  DW_Digital_Input_DIM_model_T *localDW);
extern void DIM_model_Digital_Input(boolean_T rtu_VHAL_SignalIn_flg, uint8_T
  rtu_KINP_DebounceSignal_sat, uint8_T rtu_KINP_DebounceSignal_inc, uint8_T
  rtu_KINP_DebounceSignal_dec, uint8_T rtu_ConfirmTime, boolean_T
  rtu_KINP_cal_ovrdflg, boolean_T rtu_KINP_cal_ovrdval,
  B_Digital_Input_DIM_model_T *localB, DW_Digital_Input_DIM_model_T *localDW);
extern void DIM_model_ovrride_signal_CAN1_o(uint16_T rtu_signal_raw,
  B_ovrride_signal_CAN1_b_T *localB);
extern void DIM_model_CAN_NofaoffInput_fp(uint16_T rtu_VHAL_SigIn,
  B_CAN_NofaoffInput_DIM_model_b_T *localB);
extern void DIM_model_ovrride_signal_CAN_a(uint16_T rtu_signal_raw,
  B_ovrride_signal_CAN_nq_T *localB);
extern void DIM_model_CAN_Input_ky(uint8_T rtu_VHAL_SigIn, uint8_T
  rtu_KINP_sigConv_gain, uint8_T rtu_KINP_sigConv_offset,
  B_CAN_Input_DIM_model_m2j_T *localB);
extern void DIM_model_ovrride_signal_CAN_p(int16_T rtu_signal_raw,
  B_ovrride_signal_CAN_h_T *localB);
extern void DIM_model_CAN_Input_d(uint8_T rtu_VHAL_SigIn, real32_T
  rtu_KINP_sigConv_gain, int8_T rtu_KINP_sigConv_offset,
  B_CAN_Input_DIM_model_d3_T *localB);
extern void DIM_model_CAN_Input_e(real32_T rtu_VHAL_SigIn, real32_T
  rtu_KINP_sigConv_gain, uint8_T rtu_KINP_sigConv_offset,
  B_CAN_Input_DIM_model_pe_T *localB);
extern void DIM_model_ovrride_signal_CAN_j(int8_T rtu_signal_raw,
  B_ovrride_signal_CAN_nqh_T *localB);
extern void DIM_model_CAN_Input_jh(real32_T rtu_VHAL_SigIn, real32_T
  rtu_KINP_sigConv_gain, int8_T rtu_KINP_sigConv_offset,
  B_CAN_Input_DIM_model_g0_T *localB);
extern void DIM_model_CAN_Input_km(uint8_T rtu_VHAL_SigIn, real32_T
  rtu_KINP_sigConv_gain, uint8_T rtu_KINP_sigConv_offset, boolean_T
  rtu_KINP_cal_ovrdflg, real32_T rtu_KINP_cal_ovrdval,
  B_CAN_Input_DIM_model_mr_T *localB);
extern void DIM_model_divide(real32_T rtu_dividend, real32_T rtu_divisor,
  real32_T rtu_default_value, B_divide_DIM_model_T *localB);
extern void DIM_model_rollingaverage_Init(DW_rollingaverage_DIM_model_T *localDW);
extern void DIM_model_rollingaverage(real32_T rtu_new_value, real32_T
  rtu_old_ave, real32_T rtu_delta_t, real32_T rtu_tc,
  B_rollingaverage_DIM_model_T *localB, DW_rollingaverage_DIM_model_T *localDW);
extern void DIM_model_Digital_Input_h_Init(B_Digital_Input_DIM_model_n_T *localB,
  DW_Digital_Input_DIM_model_a_T *localDW);
extern void DIM_model_Digital_Input_k(boolean_T rtu_VHAL_SignalIn_flg, uint8_T
  rtu_KINP_DebounceSignal_sat, uint8_T rtu_KINP_DebounceSignal_inc, uint8_T
  rtu_KINP_DebounceSignal_dec, uint8_T rtu_ConfirmTime, boolean_T
  rtu_KINP_cal_ovrdflg, boolean_T rtu_KINP_cal_ovrdval,
  B_Digital_Input_DIM_model_n_T *localB, DW_Digital_Input_DIM_model_a_T *localDW);
extern void DIM_model_Digital_Input_e_Init(B_Digital_Input_DIM_model_g_T *localB,
  DW_Digital_Input_DIM_model_f_T *localDW);
extern void DIM_model_Digital_Input_g(boolean_T rtu_VHAL_SignalIn_flg, uint8_T
  rtu_KINP_DebounceSignal_sat, uint8_T rtu_KINP_DebounceSignal_inc, uint8_T
  rtu_KINP_DebounceSignal_dec, uint8_T rtu_ConfirmTime, boolean_T
  rtu_KINP_cal_ovrdflg, boolean_T rtu_KINP_cal_ovrdval,
  B_Digital_Input_DIM_model_g_T *localB, DW_Digital_Input_DIM_model_f_T *localDW);
extern void DIM_model_Digital_Input_i_Init(B_Digital_Input_DIM_model_i_T *localB,
  DW_Digital_Input_DIM_model_fs_T *localDW);
extern void DIM_model_Digital_Input_j(boolean_T rtu_VHAL_SignalIn_flg, uint8_T
  rtu_KINP_DebounceSignal_sat, uint8_T rtu_KINP_DebounceSignal_inc, uint8_T
  rtu_KINP_DebounceSignal_dec, uint8_T rtu_ConfirmTime, boolean_T
  rtu_KINP_cal_ovrdflg, boolean_T rtu_KINP_cal_ovrdval,
  B_Digital_Input_DIM_model_i_T *localB, DW_Digital_Input_DIM_model_fs_T
  *localDW);
extern void DIM_model_Digital_Input_hj_Init(B_Digital_Input_DIM_model_p_T
  *localB, DW_Digital_Input_DIM_model_o_T *localDW);
extern void DIM_model_Digital_Input_a(boolean_T rtu_VHAL_SignalIn_flg, uint8_T
  rtu_KINP_DebounceSignal_sat, uint8_T rtu_KINP_DebounceSignal_inc, uint8_T
  rtu_KINP_DebounceSignal_dec, uint8_T rtu_ConfirmTime, boolean_T
  rtu_KINP_cal_ovrdflg, boolean_T rtu_KINP_cal_ovrdval,
  B_Digital_Input_DIM_model_p_T *localB, DW_Digital_Input_DIM_model_o_T *localDW);
extern void DIM_model_Digital_Input_f_Init(B_Digital_Input_DIM_model_c_T *localB,
  DW_Digital_Input_DIM_model_c_T *localDW);
extern void DIM_model_Digital_Input_l(boolean_T rtu_VHAL_SignalIn_flg, uint8_T
  rtu_KINP_DebounceSignal_sat, uint8_T rtu_KINP_DebounceSignal_inc, uint8_T
  rtu_KINP_DebounceSignal_dec, uint8_T rtu_ConfirmTime, boolean_T
  rtu_KINP_cal_ovrdflg, boolean_T rtu_KINP_cal_ovrdval,
  B_Digital_Input_DIM_model_c_T *localB, DW_Digital_Input_DIM_model_c_T *localDW);
extern void DIM_model_Digital_Input_g_Init(B_Digital_Input_DIM_model_m_T *localB,
  DW_Digital_Input_DIM_model_b_T *localDW);
extern void DIM_model_Digital_Input_e(boolean_T rtu_VHAL_SignalIn_flg, uint8_T
  rtu_KINP_DebounceSignal_sat, uint8_T rtu_KINP_DebounceSignal_inc, uint8_T
  rtu_KINP_DebounceSignal_dec, uint8_T rtu_ConfirmTime, boolean_T
  rtu_KINP_cal_ovrdflg, boolean_T rtu_KINP_cal_ovrdval,
  B_Digital_Input_DIM_model_m_T *localB, DW_Digital_Input_DIM_model_b_T *localDW);
extern void DIM_model_Digital_Input_gd_Init(B_Digital_Input_DIM_model_p1_T
  *localB, DW_Digital_Input_DIM_model_l_T *localDW);
extern void DIM_model_Digital_Input_c(boolean_T rtu_VHAL_SignalIn_flg, uint8_T
  rtu_KINP_DebounceSignal_sat, uint8_T rtu_KINP_DebounceSignal_inc, uint8_T
  rtu_KINP_DebounceSignal_dec, uint8_T rtu_ConfirmTime, boolean_T
  rtu_KINP_cal_ovrdflg, boolean_T rtu_KINP_cal_ovrdval,
  B_Digital_Input_DIM_model_p1_T *localB, DW_Digital_Input_DIM_model_l_T
  *localDW);
extern void DIM_model_Digital_Input_b_Init(B_Digital_Input_DIM_model_a_T *localB,
  DW_Digital_Input_DIM_model_k_T *localDW);
extern void DIM_model_Digital_Input_i(boolean_T rtu_VHAL_SignalIn_flg, uint8_T
  rtu_KINP_DebounceSignal_sat, uint8_T rtu_KINP_DebounceSignal_inc, uint8_T
  rtu_KINP_DebounceSignal_dec, uint8_T rtu_ConfirmTime, boolean_T
  rtu_KINP_cal_ovrdflg, boolean_T rtu_KINP_cal_ovrdval,
  B_Digital_Input_DIM_model_a_T *localB, DW_Digital_Input_DIM_model_k_T *localDW);
extern void DIM_model_Digital_Input_d_Init(B_Digital_Input_DIM_model_h_T *localB,
  DW_Digital_Input_DIM_model_bw_T *localDW);
extern void DIM_model_Digital_Input_p(boolean_T rtu_VHAL_SignalIn_flg, uint8_T
  rtu_KINP_DebounceSignal_sat, uint8_T rtu_KINP_DebounceSignal_inc, uint8_T
  rtu_KINP_DebounceSignal_dec, uint8_T rtu_ConfirmTime, boolean_T
  rtu_KINP_cal_ovrdflg, boolean_T rtu_KINP_cal_ovrdval,
  B_Digital_Input_DIM_model_h_T *localB, DW_Digital_Input_DIM_model_bw_T
  *localDW);
extern void DIM_model_Digital_Input_g5_Init(B_Digital_Input_DIM_model_f_T
  *localB, DW_Digital_Input_DIM_model_i_T *localDW);
extern void DIM_model_Digital_Input_ct(boolean_T rtu_VHAL_SignalIn_flg, uint8_T
  rtu_KINP_DebounceSignal_sat, uint8_T rtu_KINP_DebounceSignal_inc, uint8_T
  rtu_KINP_DebounceSignal_dec, uint8_T rtu_ConfirmTime, boolean_T
  rtu_KINP_cal_ovrdflg, boolean_T rtu_KINP_cal_ovrdval,
  B_Digital_Input_DIM_model_f_T *localB, DW_Digital_Input_DIM_model_i_T *localDW);
extern void DIM_model_Digital_Input_o_Init(B_Digital_Input_DIM_model_d_T *localB,
  DW_Digital_Input_DIM_model_g_T *localDW);
extern void DIM_model_Digital_Input_f(boolean_T rtu_VHAL_SignalIn_flg, uint8_T
  rtu_KINP_DebounceSignal_sat, uint8_T rtu_KINP_DebounceSignal_inc, uint8_T
  rtu_KINP_DebounceSignal_dec, uint8_T rtu_ConfirmTime, boolean_T
  rtu_KINP_cal_ovrdflg, boolean_T rtu_KINP_cal_ovrdval,
  B_Digital_Input_DIM_model_d_T *localB, DW_Digital_Input_DIM_model_g_T *localDW);
extern void DIM_model_Digital_Input_gj_Init(B_Digital_Input_DIM_model_b_T
  *localB, DW_Digital_Input_DIM_model_o5_T *localDW);
extern void DIM_model_Digital_Input_gp(boolean_T rtu_VHAL_SignalIn_flg, uint8_T
  rtu_KINP_DebounceSignal_sat, uint8_T rtu_KINP_DebounceSignal_inc, uint8_T
  rtu_KINP_DebounceSignal_dec, uint8_T rtu_ConfirmTime, boolean_T
  rtu_KINP_cal_ovrdflg, boolean_T rtu_KINP_cal_ovrdval,
  B_Digital_Input_DIM_model_b_T *localB, DW_Digital_Input_DIM_model_o5_T
  *localDW);
extern void DIM_model_Digital_Input_ez_Init(B_Digital_Input_DIM_model_o_T
  *localB, DW_Digital_Input_DIM_model_ik_T *localDW);
extern void DIM_model_Digital_Input_i0(boolean_T rtu_VHAL_SignalIn_flg, uint8_T
  rtu_KINP_DebounceSignal_sat, uint8_T rtu_KINP_DebounceSignal_inc, uint8_T
  rtu_KINP_DebounceSignal_dec, uint8_T rtu_ConfirmTime, boolean_T
  rtu_KINP_cal_ovrdflg, boolean_T rtu_KINP_cal_ovrdval,
  B_Digital_Input_DIM_model_o_T *localB, DW_Digital_Input_DIM_model_ik_T
  *localDW);
extern void DIM_model_Digital_Input_c_Init(B_Digital_Input_DIM_model_go_T
  *localB, DW_Digital_Input_DIM_model_kd_T *localDW);
extern void DIM_model_Digital_Input_i3(boolean_T rtu_VHAL_SignalIn_flg, uint8_T
  rtu_KINP_DebounceSignal_sat, uint8_T rtu_KINP_DebounceSignal_inc, uint8_T
  rtu_KINP_DebounceSignal_dec, uint8_T rtu_ConfirmTime, boolean_T
  rtu_KINP_cal_ovrdflg, boolean_T rtu_KINP_cal_ovrdval,
  B_Digital_Input_DIM_model_go_T *localB, DW_Digital_Input_DIM_model_kd_T
  *localDW);
extern void DIM_model_Digital_Input_ic_Init(B_Digital_Input_DIM_model_p0_T
  *localB, DW_Digital_Input_DIM_model_bi_T *localDW);
extern void DIM_model_Digital_Input_jy(boolean_T rtu_VHAL_SignalIn_flg, uint8_T
  rtu_KINP_DebounceSignal_sat, uint8_T rtu_KINP_DebounceSignal_inc, uint8_T
  rtu_KINP_DebounceSignal_dec, uint8_T rtu_ConfirmTime, boolean_T
  rtu_KINP_cal_ovrdflg, boolean_T rtu_KINP_cal_ovrdval,
  B_Digital_Input_DIM_model_p0_T *localB, DW_Digital_Input_DIM_model_bi_T
  *localDW);
extern void DIM_model_Digital_Input_o2_Init(B_Digital_Input_DIM_model_mn_T
  *localB, DW_Digital_Input_DIM_model_l4_T *localDW);
extern void DIM_model_Digital_Input_b(boolean_T rtu_VHAL_SignalIn_flg, uint8_T
  rtu_KINP_DebounceSignal_sat, uint8_T rtu_KINP_DebounceSignal_inc, uint8_T
  rtu_KINP_DebounceSignal_dec, uint8_T rtu_ConfirmTime, boolean_T
  rtu_KINP_cal_ovrdflg, boolean_T rtu_KINP_cal_ovrdval,
  B_Digital_Input_DIM_model_mn_T *localB, DW_Digital_Input_DIM_model_l4_T
  *localDW);
extern void DIM_model_Digital_Input_ft_Init(B_Digital_Input_DIM_model_bo_T
  *localB, DW_Digital_Input_DIM_model_h_T *localDW);
extern void DIM_model_Digital_Input_pd(boolean_T rtu_VHAL_SignalIn_flg, uint8_T
  rtu_KINP_DebounceSignal_sat, uint8_T rtu_KINP_DebounceSignal_inc, uint8_T
  rtu_KINP_DebounceSignal_dec, uint8_T rtu_ConfirmTime, boolean_T
  rtu_KINP_cal_ovrdflg, boolean_T rtu_KINP_cal_ovrdval,
  B_Digital_Input_DIM_model_bo_T *localB, DW_Digital_Input_DIM_model_h_T
  *localDW);
extern void DIM_model_Digital_Input_ey_Init(B_Digital_Input_DIM_model_dc_T
  *localB, DW_Digital_Input_DIM_model_d_T *localDW);
extern void DIM_model_Digital_Input_ll(boolean_T rtu_VHAL_SignalIn_flg, uint8_T
  rtu_KINP_DebounceSignal_sat, uint8_T rtu_KINP_DebounceSignal_inc, uint8_T
  rtu_KINP_DebounceSignal_dec, uint8_T rtu_ConfirmTime, boolean_T
  rtu_KINP_cal_ovrdflg, boolean_T rtu_KINP_cal_ovrdval,
  B_Digital_Input_DIM_model_dc_T *localB, DW_Digital_Input_DIM_model_d_T
  *localDW);

#endif                                 /* RTW_HEADER_Funcs_DIM_lib_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

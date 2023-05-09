/*
 * File: ENM_model.h
 *
 * Code generated for Simulink model 'ENM_model'.
 *
 * Model version                  : 1.1958
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Fri Mar 18 15:39:06 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Freescale->32-bit PowerPC
 * Code generation objective: Execution efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_ENM_model_h_
#define RTW_HEADER_ENM_model_h_
#include <string.h>
#include <stddef.h>
#ifndef ENM_model_COMMON_INCLUDES_
# define ENM_model_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* ENM_model_COMMON_INCLUDES_ */

#include "ENM_model_types.h"

/* Child system includes */
#include "ENM_M.h"

/* Includes for objects with custom storage classes. */
#include "ENM_Cal_Data.h"
#include "rtsplntypes.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */

/* user code (top of header file) */
#include "derivative.h"
#include "ENM_CC_SysSOC.h"
#include "ENM_CC_RemainRange.h"

/* Block signals (auto storage) */
typedef struct
{
    real32_T DataStoreRead1;           /* '<S1>/Data Store Read1' */
    real32_T Switch5;                  /* '<S160>/Switch5' */
    real32_T Switch4;                  /* '<S159>/Switch4' */
    real32_T DataTypeConversion1;      /* '<S78>/Data Type Conversion1' */
    real32_T DataTypeConversion;       /* '<S99>/Data Type Conversion' */
    real32_T MultiportSwitch1;         /* '<S99>/Multiport Switch1' */
    real32_T MultiportSwitch;          /* '<S99>/Multiport Switch' */
    real32_T Switch3;                  /* '<S99>/Switch3' */
    real32_T Saturation;               /* '<S74>/Saturation' */
    real32_T Zone1Ave_whpkm;           /* '<S103>/Chart' */
    real32_T Zone2Ave_whpkm;           /* '<S103>/Chart' */
    real32_T Zone3Ave_whpkm;           /* '<S103>/Chart' */
    real32_T Zone4Ave_whpkm;           /* '<S103>/Chart' */
    real32_T Zone5Ave_whpkm;           /* '<S103>/Chart' */
    real32_T Zone6Ave_whpkm;           /* '<S103>/Chart' */
    real32_T Zone7Ave_whpkm;           /* '<S103>/Chart' */
    real32_T Zone8Ave_whpkm;           /* '<S103>/Chart' */
    real32_T Zone9Ave_whpkm;           /* '<S103>/Chart' */
    real32_T Zone10Ave_whpkm;          /* '<S103>/Chart' */
    real32_T Zone11Ave_whpkm;          /* '<S103>/Chart' */
    real32_T Zone12Ave_whpkm;          /* '<S103>/Chart' */
    real32_T Zone13Ave_whpkm;          /* '<S103>/Chart' */
    real32_T Zone14Ave_whpkm;          /* '<S103>/Chart' */
    real32_T Zone15Ave_whpkm;          /* '<S103>/Chart' */
    real32_T Zone16Ave_whpkm;          /* '<S103>/Chart' */
    real32_T Zone17Ave_whpkm;          /* '<S103>/Chart' */
    real32_T Zone18Ave_whpkm;          /* '<S103>/Chart' */
    real32_T Zone19Ave_whpkm;          /* '<S103>/Chart' */
    real32_T MinMax1;                  /* '<S115>/MinMax1' */
    real32_T Product;                  /* '<S111>/Product' */
    real32_T Switch4_c;                /* '<S106>/Switch4' */
    real32_T Sum5;                     /* '<S124>/Sum5' */
    real32_T DataTypeConversion17;     /* '<S72>/Data Type Conversion17' */
    real32_T Divide3;                  /* '<S72>/Divide3' */
    real32_T DataStoreRead;            /* '<S72>/Data Store Read ' */
    real32_T DataStoreRead1_l;         /* '<S72>/Data Store Read1' */
    real32_T DataStoreRead3;           /* '<S72>/Data Store Read3' */
    real32_T Switch;                   /* '<S82>/Switch' */
    real32_T Sum7;                     /* '<S81>/Sum7' */
    real32_T Switch1;                  /* '<S81>/Switch1' */
    real32_T Divide;                   /* '<S80>/Divide' */
    real32_T Saturation1;              /* '<S85>/Saturation1' */
    real32_T Switch5_g;                /* '<S83>/Switch5' */
    real32_T Switch_i;                 /* '<S76>/Switch' */
    real32_T Switch1_d;                /* '<S67>/Switch1' */
    real32_T TmpSignalConversionAtGainInport;
    real32_T DataStoreRead_d;          /* '<S2>/Data Store Read' */
    real32_T DataStoreRead6;           /* '<S2>/Data Store Read6' */
    real32_T DataStoreRead5;           /* '<S2>/Data Store Read5' */
    real32_T SysSocInit;               /* '<S2>/Chart' */
    real32_T SOC_noRoundUp_Init;       /* '<S2>/Chart' */
    real32_T bmssoc_Init;              /* '<S2>/Chart' */
    real32_T Sum3;                     /* '<S31>/Sum3' */
    real32_T Sum;                      /* '<S31>/Sum' */
    real32_T socJumpPoint;             /* '<S58>/Switch4' */
    real32_T sysSocJumpPoint_f;        /* '<S58>/Switch6' */
    real32_T Switch2;                  /* '<S29>/Switch2' */
    int32_T DataTypeConversion1_e;     /* '<S5>/Data Type Conversion1' */
    int32_T DataTypeConversion3_k;     /* '<S5>/Data Type Conversion3' */
    int32_T Sum_c;                     /* '<S5>/Sum' */
    int32_T Switch1_n;                 /* '<S158>/Switch1' */
    int32_T Saturation_n;              /* '<S157>/Saturation' */
    uint32_T Switch9;                  /* '<S155>/Switch9' */
    uint32_T BMSRatedPwr_Confrimed;    /* '<S102>/Chart' */
    uint32_T BMSRatedPwr_NextTime;     /* '<S102>/Chart' */
    uint32_T DataStoreRead4;           /* '<S72>/Data Store Read4' */
    uint32_T DataStoreRead2;           /* '<S72>/Data Store Read2' */
    uint32_T Sum_k;                    /* '<S82>/Sum' */
    uint32_T Switch2_l;                /* '<S81>/Switch2' */
    uint32_T Switch9_c;                /* '<S84>/Switch9' */
    int16_T Switch2_e;                 /* '<S66>/Switch2' */
    uint16_T DataStoreRead1_i;         /* '<S74>/Data Store Read1' */
    uint16_T RR_merge;                 /* '<S102>/Switch2' */
    uint16_T DataStoreRead1_b;         /* '<S113>/Data Store Read1' */
    uint16_T MinMax3;                  /* '<S144>/MinMax3' */
    uint16_T AVE60km_Milg_km_Confrimed;/* '<S102>/Chart' */
    uint16_T NEDC_Milg_km_Confrimed;   /* '<S102>/Chart' */
    uint16_T Switch1_i;                /* '<S105>/Switch1' */
    boolean_T DataTypeConversion_f;    /* '<S157>/Data Type Conversion' */
    boolean_T RelationalOperator2;     /* '<S112>/Relational Operator2' */
    boolean_T RelationalOperator5;     /* '<S112>/Relational Operator5' */
    boolean_T LogicalOperator4;        /* '<S65>/Logical Operator4' */
    boolean_T MultiportSwitch1_b;      /* '<S9>/Multiport Switch1' */
    boolean_T MultiportSwitch_a;       /* '<S9>/Multiport Switch' */
    boolean_T enaFlg;                  /* '<S9>/JudgeEnaPwrOutput' */
    boolean_T FrdPwr_out;              /* '<S9>/Chart' */
    boolean_T socMidAreaJump;          /* '<S31>/Logical Operator' */
    boolean_T LogicalOperator1;        /* '<S29>/Logical Operator1' */
    boolean_T Compare;                 /* '<S33>/Compare' */
    boolean_T LogicalOperator;         /* '<S27>/Logical Operator' */
    rtB_ENM_xx2kxx_ENM_model_T ENM_xx2kxx1_b;/* '<S159>/ENM_xx2kxx1' */
    rtB_ENM_kxx2xx_ENM_model_T ENM_kxx2xx1;/* '<S157>/ENM_kxx2xx1' */
    rtB_ENM_xx2kxx_ENM_model_T ENM_xx2kxx;/* '<S78>/ENM_xx2kxx' */
    rtB_ENM_xx2kxx_ENM_model_T ENM_xx2kxx1;/* '<S99>/ENM_xx2kxx1' */
    rtB_ENM_DelayProcess_ENM_mo_a_T ENM_DelayProcess;/* '<S146>/ENM_DelayProcess' */
    rtB_ENM_Rolling_Filter_ENM__d_T ENM_Rolling_Filter_h;/* '<S114>/ENM_Rolling_Filter' */
    rtB_ENM_Rolling_Filter_ENM_mo_T ENM_Rolling_Filter;/* '<S110>/ENM_Rolling_Filter' */
    rtB_ENM_Divide_ENM_model_d_T ENM_Divide;/* '<S102>/ENM_Divide' */
    rtB_ENM_Divide_ENM_model_d_T ENM_Divide_f;/* '<S124>/ENM_Divide' */
    rtB_ENM_Divide_ENM_model_d_T ENM_Divide_a;/* '<S123>/ENM_Divide' */
    rtB_ENM_DelayProcess_ENM_mo_l_T ENM_DelayProcess1_i;/* '<S118>/ENM_DelayProcess1' */
    rtB_ENM_kwh_km_2_kwh_ENM_mode_T ENM_kwh_km_2_kwh;/* '<S82>/ENM_kwh_km_2_kwh' */
    rtB_ENM_DelayProcess_ENM_mode_T ENM_DelayProcess1;/* '<S81>/ENM_DelayProcess1' */
    rtB_ENM_kwh_kph_2_kwh_ENM_mod_T ENM_kwh_kph_2_kwh;/* '<S83>/ENM_kwh_kph_2_kwh' */
    rtB_X_Remap_Y_ENM_model_T X_Remap; /* '<S26>/X_Remap' */
    rtB_X_Remap_Y_ENM_model_T X_Remap_Y;/* '<S31>/X_Remap_Y' */
    rtB_X_Remap_Y_ENM_model_T X_Remap_Y4;/* '<S31>/X_Remap_Y4' */
    rtB_X_Remap_Y_ENM_model_T X_Remap_Y2;/* '<S31>/X_Remap_Y2' */
    rtB_u00ms_trigger_ENM_model_T u000ms_trigger;/* '<S12>/5000ms_trigger' */
    rtB_u00ms_trigger_ENM_model_T u00ms_trigger;/* '<S11>/100ms_trigger' */
}
BlockIO_ENM_model_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct
{
    void* m_bpDataSet;                 /* '<S144>/1-D Lookup Table1' */
    void* TWork[6];                    /* '<S144>/1-D Lookup Table1' */
    void* SWork[9];                    /* '<S144>/1-D Lookup Table1' */
    real32_T Delay_DSTATE;             /* '<S78>/Delay' */
    real32_T Delay2_DSTATE;            /* '<S112>/Delay2' */
    real32_T Delay1_DSTATE;            /* '<S110>/Delay1' */
    real32_T Delay_DSTATE_k;           /* '<S106>/Delay' */
    real32_T Delay3_DSTATE;            /* '<S106>/Delay3' */
    real32_T Delay_DSTATE_a;           /* '<S124>/Delay' */
    real32_T Delay1_DSTATE_g;          /* '<S124>/Delay1' */
    real32_T Delay2_DSTATE_m;          /* '<S123>/Delay2' */
    real32_T Delay5_DSTATE;            /* '<S123>/Delay5' */
    real32_T Delay_DSTATE_i;           /* '<S101>/Delay' */
    real32_T Delay1_DSTATE_c;          /* '<S31>/Delay1' */
    real32_T Delay2_DSTATE_e;          /* '<S58>/Delay2' */
    real32_T Delay_DSTATE_p;           /* '<S58>/Delay' */
    real32_T Delay_DSTATE_kw;          /* '<S29>/Delay' */
    real32_T Delay1_DSTATE_d;          /* '<S29>/Delay1' */
    real32_T Delay2_DSTATE_k;          /* '<S27>/Delay2' */
    real32_T Delay_DSTATE_m;           /* '<S11>/Delay' */
    real32_T Delay_DSTATE_kj;          /* '<S12>/Delay' */
    uint32_T Delay1_DSTATE_p;          /* '<S78>/Delay1' */
    uint32_T Delay1_DSTATE_n;          /* '<S155>/Delay1' */
    uint32_T Delay1_DSTATE_dx;         /* '<S111>/Delay1' */
    uint32_T Delay_DSTATE_j;           /* '<S72>/Delay' */
    uint32_T Delay1_DSTATE_m;          /* '<S84>/Delay1' */
    uint32_T Delay1_DSTATE_k;          /* '<S25>/Delay1' */
    uint32_T Delay2_DSTATE_b;          /* '<S25>/Delay2' */
    uint32_T Delay1_DSTATE_e;          /* '<S22>/Delay1' */
    uint32_T Delay2_DSTATE_c;          /* '<S22>/Delay2' */
    real32_T EgyCnse_Keyon_kwh;        /* '<S1>/Data Store Memory13' */
    real32_T m_bpLambda;               /* '<S144>/1-D Lookup Table1' */
    real32_T m_yyA;                    /* '<S144>/1-D Lookup Table1' */
    real32_T m_yyB;                    /* '<S144>/1-D Lookup Table1' */
    real32_T m_yy2;                    /* '<S144>/1-D Lookup Table1' */
    real32_T m_up[5];                  /* '<S144>/1-D Lookup Table1' */
    real32_T m_y2[5];                  /* '<S144>/1-D Lookup Table1' */
    real32_T prevBp0AndTableData[10];  /* '<S144>/1-D Lookup Table1' */
    uint32_T m_bpIndex;                /* '<S144>/1-D Lookup Table1' */
    uint32_T BMSRatedPwr_temp;         /* '<S102>/Chart' */
    uint16_T Delay_DSTATE_pi;          /* '<S108>/Delay' */
    uint16_T config_confirm_cnt;       /* '<S102>/Chart' */
    uint8_T Delay5_DSTATE_p;           /* '<S114>/Delay5' */
    boolean_T IC_DSTATE;               /* '<S114>/IC' */
    boolean_T Delay1_DSTATE_i;         /* '<S114>/Delay1' */
    boolean_T Delay1_DSTATE_gb;        /* '<S108>/Delay1' */
    boolean_T Delay_DSTATE_jk;         /* '<S24>/Delay' */
    boolean_T Delay1_DSTATE_h;         /* '<S24>/Delay1' */
    uint8_T is_active_c2_ENM_model;    /* '<S4>/Chart' */
    uint8_T is_c2_ENM_model;           /* '<S4>/Chart' */
    uint8_T icLoad;                    /* '<S78>/Delay1' */
    uint8_T icLoad_f;                  /* '<S155>/Delay1' */
    uint8_T icLoad_fx;                 /* '<S114>/Delay5' */
    uint8_T icLoad_g;                  /* '<S114>/Delay1' */
    uint8_T reCalcSecDerivFirstDimCoeffs;/* '<S144>/1-D Lookup Table1' */
    uint8_T icLoad_gp;                 /* '<S112>/Delay2' */
    uint8_T icLoad_c;                  /* '<S111>/Delay1' */
    uint8_T icLoad_k;                  /* '<S110>/Delay1' */
    uint8_T icLoad_m;                  /* '<S108>/Delay' */
    uint8_T icLoad_ki;                 /* '<S108>/Delay1' */
    uint8_T is_active_c6_ENM_model;    /* '<S102>/Chart' */
    uint8_T is_c6_ENM_model;           /* '<S102>/Chart' */
    uint8_T icLoad_mk;                 /* '<S106>/Delay' */
    uint8_T icLoad_j;                  /* '<S124>/Delay' */
    uint8_T icLoad_ge;                 /* '<S124>/Delay1' */
    uint8_T icLoad_gd;                 /* '<S123>/Delay2' */
    uint8_T icLoad_e;                  /* '<S123>/Delay5' */
    uint8_T icLoad_l;                  /* '<S101>/Delay' */
    uint8_T icLoad_a;                  /* '<S72>/Delay' */
    uint8_T icLoad_n;                  /* '<S84>/Delay1' */
    uint8_T is_active_c4_ENM_model;    /* '<S2>/Chart' */
    uint8_T is_c4_ENM_model;           /* '<S2>/Chart' */
    uint8_T icLoad_ny;                 /* '<S24>/Delay' */
    uint8_T icLoad_lp;                 /* '<S25>/Delay1' */
    uint8_T is_active_c3_ENM_model;    /* '<S9>/JudgeEnaPwrOutput' */
    uint8_T is_c3_ENM_model;           /* '<S9>/JudgeEnaPwrOutput' */
    uint8_T icLoad_nn;                 /* '<S22>/Delay1' */
    uint8_T is_active_c5_ENM_model;    /* '<S9>/Chart' */
    uint8_T is_c5_ENM_model;           /* '<S9>/Chart' */
    uint8_T icLoad_lc;                 /* '<S31>/Delay1' */
    uint8_T icLoad_j4;                 /* '<S58>/Delay2' */
    uint8_T icLoad_ke;                 /* '<S58>/Delay' */
    uint8_T icLoad_o;                  /* '<S29>/Delay' */
    uint8_T icLoad_d;                  /* '<S29>/Delay1' */
    uint8_T icLoad_ef;                 /* '<S27>/Delay2' */
    uint8_T icLoad_h;                  /* '<S11>/Delay' */
    uint8_T icLoad_jn;                 /* '<S12>/Delay' */
    rtDW_ENM_DelayProcess_ENM_m_p_T ENM_DelayProcess;/* '<S146>/ENM_DelayProcess' */
    rtDW_ENM_Rolling_Filter_ENM_c_T ENM_Rolling_Filter_h;/* '<S114>/ENM_Rolling_Filter' */
    rtDW_ENM_Rolling_Filter_ENM_m_T ENM_Rolling_Filter;/* '<S110>/ENM_Rolling_Filter' */
    rtDW_ENM_DelayProcess_ENM_m_b_T ENM_DelayProcess1_i;/* '<S118>/ENM_DelayProcess1' */
    rtDW_ENM_DelayProcess_ENM_mod_T ENM_DelayProcess1;/* '<S81>/ENM_DelayProcess1' */
    rtDW_u00ms_trigger_ENM_model_T u000ms_trigger;/* '<S12>/5000ms_trigger' */
    rtDW_u00ms_trigger_ENM_model_T u00ms_trigger;/* '<S11>/100ms_trigger' */
}
D_Work_ENM_model_T;

/* Constant parameters (auto storage) */
typedef struct
{
    /* Pooled Parameter (Mixed Expressions)
     * Referenced by:
     *   '<S72>/Delay'
     *   '<S11>/Delay'
     *   '<S12>/Delay'
     *   '<S22>/Delay1'
     *   '<S22>/Delay2'
     *   '<S24>/Delay'
     *   '<S24>/Delay1'
     *   '<S78>/Delay'
     *   '<S78>/Delay1'
     *   '<S82>/Constant'
     *   '<S101>/Delay'
     *   '<S13>/Delay2'
     *   '<S13>/Delay3'
     *   '<S16>/Delay2'
     *   '<S16>/Delay3'
     *   '<S25>/Delay1'
     *   '<S25>/Delay2'
     *   '<S27>/Delay2'
     *   '<S29>/Delay'
     *   '<S29>/Delay1'
     *   '<S31>/Delay1'
     *   '<S84>/Constant1'
     *   '<S84>/Delay1'
     *   '<S94>/Delay'
     *   '<S94>/Delay1'
     *   '<S106>/Delay'
     *   '<S106>/Delay3'
     *   '<S108>/Delay'
     *   '<S108>/Delay1'
     *   '<S110>/Delay1'
     *   '<S111>/Delay1'
     *   '<S112>/Delay2'
     *   '<S114>/Delay'
     *   '<S114>/Delay1'
     *   '<S114>/Delay5'
     *   '<S155>/Constant1'
     *   '<S155>/Delay1'
     *   '<S58>/Delay'
     *   '<S58>/Delay2'
     *   '<S95>/Delay2'
     *   '<S123>/Delay2'
     *   '<S123>/Delay5'
     *   '<S124>/Delay'
     *   '<S124>/Delay1'
     *   '<S144>/1-D Lookup Table1'
     *   '<S119>/Delay'
     *   '<S119>/Delay1'
     *   '<S151>/Delay'
     *   '<S151>/Delay1'
     *   '<S120>/Delay2'
     *   '<S153>/Delay2'
     */
    uint32_T pooled19;

    /* Computed Parameter: uDLookupTable1_maxIndex
     * Referenced by: '<S144>/1-D Lookup Table1'
     */
    uint32_T uDLookupTable1_maxIndex;

    /* Computed Parameter: uDLookupTable1_numYWorkElts
     * Referenced by: '<S144>/1-D Lookup Table1'
     */
    uint32_T uDLookupTable1_numYWorkElts[2];

    /* Computed Parameter: uDLookupTable_maxIndex
     * Referenced by: '<S114>/2-D Lookup Table'
     */
    uint32_T uDLookupTable_maxIndex[2];
}
ConstParam_ENM_model_T;

/* Block signals (auto storage) */
#pragma push
#pragma DATA_SEG __GPAGE_SEG GPAGED_RAM

extern BlockIO_ENM_model_T ENM_model_B;

#pragma pop

/* Block states (auto storage) */

#pragma push
#pragma DATA_SEG __GPAGE_SEG GPAGED_RAM

extern D_Work_ENM_model_T ENM_model_DWork;

#pragma pop

/* External data declarations for dependent source files */
#pragma push
#pragma DATA_SEG __GPAGE_SEG GPAGED_RAM

extern const ENM ENM_model_rtZENM;     /* ENM ground */

#pragma pop

/* Constant parameters (auto storage) */

#pragma push
#pragma DATA_SEG __GPAGE_SEG GPAGED_RAM

extern const ConstParam_ENM_model_T ENM_model_ConstP;

#pragma pop

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern ENM ENM_output;                 /* '<S1>/Bus Creator' */
extern real32_T SENM_Motor_ChargePowerLimit_kw;/* '<S1>/Data Type Conversion' */
extern real32_T SENM_Motor_DischargePowerLimit_kw;/* '<S1>/Data Type Conversion2' */
extern real32_T SENM_ReqDCDCU_V;       /* '<S1>/Data Type Conversion11' */
extern real32_T SysSOC_f;              /* '<S1>/Data Store Read' */
extern real32_T SENM_ActHVPwrCnsExt;   /* '<S1>/Data Type Conversion22' */
extern real32_T SENM_InstantConsume;   /* '<S1>/Data Type Conversion12' */
extern real32_T SENM_SubtotalEgyCnse_kwh;/* '<S1>/Data Type Conversion7' */
extern real32_T SENM_TotalEgyCnse_kwh; /* '<S1>/Data Type Conversion8' */
extern real32_T SENM_VehEgyCnseDrv;    /* '<S1>/Data Type Conversion9' */
extern real32_T CurrentAve_whpkm;      /* '<S103>/Chart' */
extern real32_T Zone0Ave_whpkm;        /* '<S103>/Chart' */
extern real32_T RR_ResiMilg_single_km; /* '<S114>/Switch1' */
extern real32_T RR_Ave_Filt_whpkm;     /* '<S110>/Data Type Conversion' */
extern real32_T SENM_Forecastmiles_after_hide;/* '<S130>/Switch3' */
extern real32_T chargeRangetmp1;       /* '<S124>/Sum1' */
extern real32_T RR_Chrg_Step_km;       /* '<S124>/ENM_Divide' */
extern real32_T RR_Chrg_LosePwr_km;    /* '<S123>/ENM_Divide' */
extern real32_T RR_BattRemain_kWh;     /* '<S104>/Switch3' */
extern real32_T RR_PTRemainEgy_Wh;     /* '<S104>/Product2' */
extern real32_T RR_Ave_Fad_whpkm;      /* '<S101>/Switch' */
extern real32_T dcdcPwr_w;             /* '<S80>/Divide1' */
extern real32_T ecc_InsCnse_w_tmp1;    /* '<S80>/Sum2' */
extern real32_T SENM_InstantConsumption_kw;/* '<S83>/Switch10' */
extern real32_T SENM_InstantEnergyConsump;/* '<S83>/Switch2' */
extern real32_T syssoc_goal;           /* '<S31>/Switch3' */
extern real32_T syssoctmp1;            /* '<S30>/Switch4' */
extern real32_T socDisp_NoRoundUp;     /* '<S29>/Saturation' */
extern int32_T MotDis_PwrLimittmp1;    /* '<S159>/Add3' */
extern int32_T DCDC_PwrLimit_tmp1;     /* '<S157>/Add2' */
extern uint32_T SENM_HVLoadPwrLimit_W; /* '<S1>/Data Type Conversion3' */
extern int16_T SENM_DCDC_Temp;         /* '<S1>/Data Type Conversion19' */
extern uint16_T SENM_MaxPermDCDCPwr_W; /* '<S1>/Data Type Conversion10' */
extern uint16_T SENM_ECC_PowerLimit_W; /* '<S1>/Data Type Conversion16' */
extern uint16_T SENM_CoolingPower_KJ;  /* '<S1>/Data Type Conversion13' */
extern uint16_T SENM_ResiMilg_km;      /* '<S1>/Data Type Conversion15' */
extern uint16_T RR_RemainRange_Rough_km;/* '<S102>/Data Type Conversion' */
extern uint16_T RR_RemainRange_Filter_km;/* '<S114>/Data Type Conversion3' */
extern uint16_T RR_RemainRange_noChrg_km;/* '<S108>/Switch' */
extern uint16_T RR_RemainRange_Chrg_km;/* '<S106>/Data Type Conversion2' */
extern uint16_T chrgforecastMilg_km;   /* '<S125>/Switch4' */
extern uint8_T SENM_SysSOC;            /* '<S1>/Data Type Conversion14' */
extern uint8_T SENM_VCUDrvgEff;        /* '<S83>/Data Type Conversion1' */
extern uint8_T ENM_VCUPwrAvail_KW;     /* '<S86>/WtoKW' */
extern uint8_T ENM_BMSMaxDchaPer;      /* '<S83>/MinMax2' */
extern boolean_T SENM_DCDCEnReq_flg;   /* '<S1>/Data Type Conversion1' */
extern boolean_T SENM_ChargingRemind_flg;/* '<S1>/Data Type Conversion5' */
extern boolean_T SENM_ForbidPwrOutput_flg;/* '<S1>/Data Type Conversion6' */
extern boolean_T SENM_BMSCAN_InitFinishFlg;/* '<S8>/Switch' */
extern boolean_T ENM_Batt_EnergyToolow;/* '<S22>/Relational Operator3' */
extern boolean_T SENM_BMSMaxDchaPwrFlt_flg;/* '<S6>/Logical Operator' */

/*
 * Exported States
 *
 * Note: Exported states are block states with an exported global
 * storage class designation.  Code generation will declare the memory for these
 * states and exports their symbols.
 *
 */
extern uint32_T Battery_Tick;          /* '<S1>/Data Store Memory15' */
extern uint32_T Dcdc_Tick;             /* '<S1>/Data Store Memory36' */
extern uint32_T PwrLimit_Tick;         /* '<S1>/Data Store Memory37' */
extern uint32_T EgyCal_Tick;           /* '<S1>/Data Store Memory38' */
extern uint32_T Tick_in;               /* '<S1>/Data Store Memory39' */
extern uint32_T ENM_Tick;              /* '<S1>/Data Store Memory41' */
extern uint32_T Tick_in_0;             /* '<S1>/Data Store Memory42' */

/* Model entry point functions */
extern void ENM_model_initialize(void);
extern void ENM_model_step(void);
extern void ENM_model_terminate(void);

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
 * '<Root>' : 'ENM_model'
 * '<S1>'   : 'ENM_model/ENM_M'
 * '<S2>'   : 'ENM_model/ENM_M/ENM_Battery'
 * '<S3>'   : 'ENM_model/ENM_M/ENM_DCDC'
 * '<S4>'   : 'ENM_model/ENM_M/ENM_EnergyConsumptionStatistics'
 * '<S5>'   : 'ENM_model/ENM_M/ENM_PowerLimit'
 * '<S6>'   : 'ENM_model/ENM_M/ENM_Battery/BMSMaxDchaPwrCheck'
 * '<S7>'   : 'ENM_model/ENM_M/ENM_Battery/Chart'
 * '<S8>'   : 'ENM_model/ENM_M/ENM_Battery/SocInitJudge'
 * '<S9>'   : 'ENM_model/ENM_M/ENM_Battery/SysSOC_Process'
 * '<S10>'  : 'ENM_model/ENM_M/ENM_Battery/SysSoc_Get'
 * '<S11>'  : 'ENM_model/ENM_M/ENM_Battery/BMSMaxDchaPwrCheck/100ms_check'
 * '<S12>'  : 'ENM_model/ENM_M/ENM_Battery/BMSMaxDchaPwrCheck/5000ms_check'
 * '<S13>'  : 'ENM_model/ENM_M/ENM_Battery/BMSMaxDchaPwrCheck/100ms_check/100ms_trigger'
 * '<S14>'  : 'ENM_model/ENM_M/ENM_Battery/BMSMaxDchaPwrCheck/100ms_check/Compare To Constant'
 * '<S15>'  : 'ENM_model/ENM_M/ENM_Battery/BMSMaxDchaPwrCheck/100ms_check/100ms_trigger/Compare To Constant1'
 * '<S16>'  : 'ENM_model/ENM_M/ENM_Battery/BMSMaxDchaPwrCheck/5000ms_check/5000ms_trigger'
 * '<S17>'  : 'ENM_model/ENM_M/ENM_Battery/BMSMaxDchaPwrCheck/5000ms_check/Compare To Constant'
 * '<S18>'  : 'ENM_model/ENM_M/ENM_Battery/BMSMaxDchaPwrCheck/5000ms_check/5000ms_trigger/Compare To Constant1'
 * '<S19>'  : 'ENM_model/ENM_M/ENM_Battery/SocInitJudge/Compare To Constant1'
 * '<S20>'  : 'ENM_model/ENM_M/ENM_Battery/SysSOC_Process/Chart'
 * '<S21>'  : 'ENM_model/ENM_M/ENM_Battery/SysSOC_Process/Compare To Constant'
 * '<S22>'  : 'ENM_model/ENM_M/ENM_Battery/SysSOC_Process/ENM_TimeoutTimer_SystemTickMs'
 * '<S23>'  : 'ENM_model/ENM_M/ENM_Battery/SysSOC_Process/JudgeEnaPwrOutput'
 * '<S24>'  : 'ENM_model/ENM_M/ENM_Battery/SysSOC_Process/forbid_from_BMSMaxOutPwr'
 * '<S25>'  : 'ENM_model/ENM_M/ENM_Battery/SysSOC_Process/forbid_from_BMSMaxOutPwr/ENM_TimeoutTimer_SystemTickMs'
 * '<S26>'  : 'ENM_model/ENM_M/ENM_Battery/SysSoc_Get/SocSmoothProcess'
 * '<S27>'  : 'ENM_model/ENM_M/ENM_Battery/SysSoc_Get/SocSmoothProcess/SOCJumpProcess'
 * '<S28>'  : 'ENM_model/ENM_M/ENM_Battery/SysSoc_Get/SocSmoothProcess/SOCLimitProcess'
 * '<S29>'  : 'ENM_model/ENM_M/ENM_Battery/SysSoc_Get/SocSmoothProcess/SOCSmooth'
 * '<S30>'  : 'ENM_model/ENM_M/ENM_Battery/SysSoc_Get/SocSmoothProcess/SOC_Canvas'
 * '<S31>'  : 'ENM_model/ENM_M/ENM_Battery/SysSoc_Get/SocSmoothProcess/SOC_InflexionProcess'
 * '<S32>'  : 'ENM_model/ENM_M/ENM_Battery/SysSoc_Get/SocSmoothProcess/X_Remap'
 * '<S33>'  : 'ENM_model/ENM_M/ENM_Battery/SysSoc_Get/SocSmoothProcess/SOCJumpProcess/Compare To Constant'
 * '<S34>'  : 'ENM_model/ENM_M/ENM_Battery/SysSoc_Get/SocSmoothProcess/SOCJumpProcess/Compare To Constant1'
 * '<S35>'  : 'ENM_model/ENM_M/ENM_Battery/SysSoc_Get/SocSmoothProcess/SOCJumpProcess/Compare To Constant2'
 * '<S36>'  : 'ENM_model/ENM_M/ENM_Battery/SysSoc_Get/SocSmoothProcess/SOCLimitProcess/Compare To Constant'
 * '<S37>'  : 'ENM_model/ENM_M/ENM_Battery/SysSoc_Get/SocSmoothProcess/SOCLimitProcess/Compare To Constant1'
 * '<S38>'  : 'ENM_model/ENM_M/ENM_Battery/SysSoc_Get/SocSmoothProcess/SOCLimitProcess/Compare To Constant2'
 * '<S39>'  : 'ENM_model/ENM_M/ENM_Battery/SysSoc_Get/SocSmoothProcess/SOCLimitProcess/Compare To Constant3'
 * '<S40>'  : 'ENM_model/ENM_M/ENM_Battery/SysSoc_Get/SocSmoothProcess/SOCLimitProcess/Compare To Constant5'
 * '<S41>'  : 'ENM_model/ENM_M/ENM_Battery/SysSoc_Get/SocSmoothProcess/SOCLimitProcess/Compare To Constant6'
 * '<S42>'  : 'ENM_model/ENM_M/ENM_Battery/SysSoc_Get/SocSmoothProcess/SOCLimitProcess/Compare To Constant7'
 * '<S43>'  : 'ENM_model/ENM_M/ENM_Battery/SysSoc_Get/SocSmoothProcess/SOCSmooth/Compare To Constant'
 * '<S44>'  : 'ENM_model/ENM_M/ENM_Battery/SysSoc_Get/SocSmoothProcess/SOCSmooth/Compare To Constant1'
 * '<S45>'  : 'ENM_model/ENM_M/ENM_Battery/SysSoc_Get/SocSmoothProcess/SOCSmooth/Compare To Constant2'
 * '<S46>'  : 'ENM_model/ENM_M/ENM_Battery/SysSoc_Get/SocSmoothProcess/SOCSmooth/Compare To Constant3'
 * '<S47>'  : 'ENM_model/ENM_M/ENM_Battery/SysSoc_Get/SocSmoothProcess/SOCSmooth/socDown'
 * '<S48>'  : 'ENM_model/ENM_M/ENM_Battery/SysSoc_Get/SocSmoothProcess/SOCSmooth/socUp'
 * '<S49>'  : 'ENM_model/ENM_M/ENM_Battery/SysSoc_Get/SocSmoothProcess/SOCSmooth/socDown/Compare To Constant'
 * '<S50>'  : 'ENM_model/ENM_M/ENM_Battery/SysSoc_Get/SocSmoothProcess/SOCSmooth/socDown/Compare To Constant1'
 * '<S51>'  : 'ENM_model/ENM_M/ENM_Battery/SysSoc_Get/SocSmoothProcess/SOCSmooth/socUp/Compare To Constant'
 * '<S52>'  : 'ENM_model/ENM_M/ENM_Battery/SysSoc_Get/SocSmoothProcess/SOCSmooth/socUp/Compare To Constant1'
 * '<S53>'  : 'ENM_model/ENM_M/ENM_Battery/SysSoc_Get/SocSmoothProcess/SOC_Canvas/ENM_MIN'
 * '<S54>'  : 'ENM_model/ENM_M/ENM_Battery/SysSoc_Get/SocSmoothProcess/SOC_Canvas/ENM_MIN1'
 * '<S55>'  : 'ENM_model/ENM_M/ENM_Battery/SysSoc_Get/SocSmoothProcess/SOC_Canvas/ENM_Max'
 * '<S56>'  : 'ENM_model/ENM_M/ENM_Battery/SysSoc_Get/SocSmoothProcess/SOC_Canvas/Interval Test'
 * '<S57>'  : 'ENM_model/ENM_M/ENM_Battery/SysSoc_Get/SocSmoothProcess/SOC_Canvas/Interval Test1'
 * '<S58>'  : 'ENM_model/ENM_M/ENM_Battery/SysSoc_Get/SocSmoothProcess/SOC_InflexionProcess/NewInflexionProcess'
 * '<S59>'  : 'ENM_model/ENM_M/ENM_Battery/SysSoc_Get/SocSmoothProcess/SOC_InflexionProcess/X_Remap_Y'
 * '<S60>'  : 'ENM_model/ENM_M/ENM_Battery/SysSoc_Get/SocSmoothProcess/SOC_InflexionProcess/X_Remap_Y2'
 * '<S61>'  : 'ENM_model/ENM_M/ENM_Battery/SysSoc_Get/SocSmoothProcess/SOC_InflexionProcess/X_Remap_Y4'
 * '<S62>'  : 'ENM_model/ENM_M/ENM_Battery/SysSoc_Get/SocSmoothProcess/SOC_InflexionProcess/NewInflexionProcess/ENM_MIN'
 * '<S63>'  : 'ENM_model/ENM_M/ENM_Battery/SysSoc_Get/SocSmoothProcess/SOC_InflexionProcess/NewInflexionProcess/ENM_MIN1'
 * '<S64>'  : 'ENM_model/ENM_M/ENM_DCDC/ENM_DCDC_Management'
 * '<S65>'  : 'ENM_model/ENM_M/ENM_DCDC/ENM_DCDC_Management/DCDCEnReq'
 * '<S66>'  : 'ENM_model/ENM_M/ENM_DCDC/ENM_DCDC_Management/DCDCPowerLimit'
 * '<S67>'  : 'ENM_model/ENM_M/ENM_DCDC/ENM_DCDC_Management/DCDCReqVoltage'
 * '<S68>'  : 'ENM_model/ENM_M/ENM_DCDC/ENM_DCDC_Management/DCDCTemp'
 * '<S69>'  : 'ENM_model/ENM_M/ENM_EnergyConsumptionStatistics/AirControlSysProcess'
 * '<S70>'  : 'ENM_model/ENM_M/ENM_EnergyConsumptionStatistics/Chart'
 * '<S71>'  : 'ENM_model/ENM_M/ENM_EnergyConsumptionStatistics/CoolingSysPwrCal'
 * '<S72>'  : 'ENM_model/ENM_M/ENM_EnergyConsumptionStatistics/EgyEnseCalculation'
 * '<S73>'  : 'ENM_model/ENM_M/ENM_EnergyConsumptionStatistics/HVPwrCnsExt'
 * '<S74>'  : 'ENM_model/ENM_M/ENM_EnergyConsumptionStatistics/ResimilgForcast'
 * '<S75>'  : 'ENM_model/ENM_M/ENM_EnergyConsumptionStatistics/AirControlSysProcess/ENM_Max2'
 * '<S76>'  : 'ENM_model/ENM_M/ENM_EnergyConsumptionStatistics/AirControlSysProcess/InvalidRR_Enable'
 * '<S77>'  : 'ENM_model/ENM_M/ENM_EnergyConsumptionStatistics/AirControlSysProcess/InvalidRR_Enable/Compare To Constant'
 * '<S78>'  : 'ENM_model/ENM_M/ENM_EnergyConsumptionStatistics/CoolingSysPwrCal/CoolingSysPowerConsumptionStatistics'
 * '<S79>'  : 'ENM_model/ENM_M/ENM_EnergyConsumptionStatistics/CoolingSysPwrCal/CoolingSysPowerConsumptionStatistics/ENM_xx2kxx'
 * '<S80>'  : 'ENM_model/ENM_M/ENM_EnergyConsumptionStatistics/EgyEnseCalculation/InsCnseProcess'
 * '<S81>'  : 'ENM_model/ENM_M/ENM_EnergyConsumptionStatistics/EgyEnseCalculation/TotolEgyCnseProcess'
 * '<S82>'  : 'ENM_model/ENM_M/ENM_EnergyConsumptionStatistics/EgyEnseCalculation/VCUVehEgyCnseDrvSys'
 * '<S83>'  : 'ENM_model/ENM_M/ENM_EnergyConsumptionStatistics/EgyEnseCalculation/InsCnseProcess/InstantConsumptionProcess'
 * '<S84>'  : 'ENM_model/ENM_M/ENM_EnergyConsumptionStatistics/EgyEnseCalculation/InsCnseProcess/Odo_Dif'
 * '<S85>'  : 'ENM_model/ENM_M/ENM_EnergyConsumptionStatistics/EgyEnseCalculation/InsCnseProcess/RR_PwrCalProcess'
 * '<S86>'  : 'ENM_model/ENM_M/ENM_EnergyConsumptionStatistics/EgyEnseCalculation/InsCnseProcess/InstantConsumptionProcess/ENM_VCUPwrAvail_KW'
 * '<S87>'  : 'ENM_model/ENM_M/ENM_EnergyConsumptionStatistics/EgyEnseCalculation/InsCnseProcess/InstantConsumptionProcess/ENM_kwh_kph_2_kwh'
 * '<S88>'  : 'ENM_model/ENM_M/ENM_EnergyConsumptionStatistics/EgyEnseCalculation/InsCnseProcess/InstantConsumptionProcess/Interval Test'
 * '<S89>'  : 'ENM_model/ENM_M/ENM_EnergyConsumptionStatistics/EgyEnseCalculation/InsCnseProcess/InstantConsumptionProcess/ENM_VCUPwrAvail_KW/Compare To Zero'
 * '<S90>'  : 'ENM_model/ENM_M/ENM_EnergyConsumptionStatistics/EgyEnseCalculation/InsCnseProcess/InstantConsumptionProcess/ENM_VCUPwrAvail_KW/Compare To Zero1'
 * '<S91>'  : 'ENM_model/ENM_M/ENM_EnergyConsumptionStatistics/EgyEnseCalculation/InsCnseProcess/InstantConsumptionProcess/ENM_kwh_kph_2_kwh/Interval Test'
 * '<S92>'  : 'ENM_model/ENM_M/ENM_EnergyConsumptionStatistics/EgyEnseCalculation/InsCnseProcess/RR_PwrCalProcess/common mode'
 * '<S93>'  : 'ENM_model/ENM_M/ENM_EnergyConsumptionStatistics/EgyEnseCalculation/InsCnseProcess/RR_PwrCalProcess/sport mode'
 * '<S94>'  : 'ENM_model/ENM_M/ENM_EnergyConsumptionStatistics/EgyEnseCalculation/TotolEgyCnseProcess/ENM_DelayProcess1'
 * '<S95>'  : 'ENM_model/ENM_M/ENM_EnergyConsumptionStatistics/EgyEnseCalculation/TotolEgyCnseProcess/ENM_DelayProcess1/AffirmCheck'
 * '<S96>'  : 'ENM_model/ENM_M/ENM_EnergyConsumptionStatistics/EgyEnseCalculation/VCUVehEgyCnseDrvSys/ENM_kwh_km_2_kwh'
 * '<S97>'  : 'ENM_model/ENM_M/ENM_EnergyConsumptionStatistics/EgyEnseCalculation/VCUVehEgyCnseDrvSys/ENM_kwh_km_2_kwh/ENM_Divide'
 * '<S98>'  : 'ENM_model/ENM_M/ENM_EnergyConsumptionStatistics/EgyEnseCalculation/VCUVehEgyCnseDrvSys/ENM_kwh_km_2_kwh/ENM_Divide/Interval Test'
 * '<S99>'  : 'ENM_model/ENM_M/ENM_EnergyConsumptionStatistics/HVPwrCnsExt/HVPwrCnsExt'
 * '<S100>' : 'ENM_model/ENM_M/ENM_EnergyConsumptionStatistics/HVPwrCnsExt/HVPwrCnsExt/ENM_xx2kxx1'
 * '<S101>' : 'ENM_model/ENM_M/ENM_EnergyConsumptionStatistics/ResimilgForcast/AveFading'
 * '<S102>' : 'ENM_model/ENM_M/ENM_EnergyConsumptionStatistics/ResimilgForcast/ResimilgForcast_Process'
 * '<S103>' : 'ENM_model/ENM_M/ENM_EnergyConsumptionStatistics/ResimilgForcast/ResimilgRecord_Update'
 * '<S104>' : 'ENM_model/ENM_M/ENM_EnergyConsumptionStatistics/ResimilgForcast/ResimilgForcast_Process/BattResiPwr_wh_Process'
 * '<S105>' : 'ENM_model/ENM_M/ENM_EnergyConsumptionStatistics/ResimilgForcast/ResimilgForcast_Process/BoundaryDispProcess'
 * '<S106>' : 'ENM_model/ENM_M/ENM_EnergyConsumptionStatistics/ResimilgForcast/ResimilgForcast_Process/Charge_Range'
 * '<S107>' : 'ENM_model/ENM_M/ENM_EnergyConsumptionStatistics/ResimilgForcast/ResimilgForcast_Process/Chart'
 * '<S108>' : 'ENM_model/ENM_M/ENM_EnergyConsumptionStatistics/ResimilgForcast/ResimilgForcast_Process/CurveTrendRestrain'
 * '<S109>' : 'ENM_model/ENM_M/ENM_EnergyConsumptionStatistics/ResimilgForcast/ResimilgForcast_Process/ENM_Divide'
 * '<S110>' : 'ENM_model/ENM_M/ENM_EnergyConsumptionStatistics/ResimilgForcast/ResimilgForcast_Process/Filting'
 * '<S111>' : 'ENM_model/ENM_M/ENM_EnergyConsumptionStatistics/ResimilgForcast/ResimilgForcast_Process/Get_TickDiff_s'
 * '<S112>' : 'ENM_model/ENM_M/ENM_EnergyConsumptionStatistics/ResimilgForcast/ResimilgForcast_Process/JumpAllow_Judge'
 * '<S113>' : 'ENM_model/ENM_M/ENM_EnergyConsumptionStatistics/ResimilgForcast/ResimilgForcast_Process/MilgCanvasRestrain'
 * '<S114>' : 'ENM_model/ENM_M/ENM_EnergyConsumptionStatistics/ResimilgForcast/ResimilgForcast_Process/RangeChangeFilter'
 * '<S115>' : 'ENM_model/ENM_M/ENM_EnergyConsumptionStatistics/ResimilgForcast/ResimilgForcast_Process/ave_whpkm_limit'
 * '<S116>' : 'ENM_model/ENM_M/ENM_EnergyConsumptionStatistics/ResimilgForcast/ResimilgForcast_Process/BoundaryDispProcess/ENM_Max'
 * '<S117>' : 'ENM_model/ENM_M/ENM_EnergyConsumptionStatistics/ResimilgForcast/ResimilgForcast_Process/BoundaryDispProcess/ENM_Max1'
 * '<S118>' : 'ENM_model/ENM_M/ENM_EnergyConsumptionStatistics/ResimilgForcast/ResimilgForcast_Process/BoundaryDispProcess/RR_Plat_Process'
 * '<S119>' : 'ENM_model/ENM_M/ENM_EnergyConsumptionStatistics/ResimilgForcast/ResimilgForcast_Process/BoundaryDispProcess/RR_Plat_Process/ENM_DelayProcess1'
 * '<S120>' : 'ENM_model/ENM_M/ENM_EnergyConsumptionStatistics/ResimilgForcast/ResimilgForcast_Process/BoundaryDispProcess/RR_Plat_Process/ENM_DelayProcess1/AffirmCheck'
 * '<S121>' : 'ENM_model/ENM_M/ENM_EnergyConsumptionStatistics/ResimilgForcast/ResimilgForcast_Process/Charge_Range/ChrgJumpRRProcess'
 * '<S122>' : 'ENM_model/ENM_M/ENM_EnergyConsumptionStatistics/ResimilgForcast/ResimilgForcast_Process/Charge_Range/ENM_Max'
 * '<S123>' : 'ENM_model/ENM_M/ENM_EnergyConsumptionStatistics/ResimilgForcast/ResimilgForcast_Process/Charge_Range/SOCDownMilgForcProcess'
 * '<S124>' : 'ENM_model/ENM_M/ENM_EnergyConsumptionStatistics/ResimilgForcast/ResimilgForcast_Process/Charge_Range/SOCUpMilgForcProcess'
 * '<S125>' : 'ENM_model/ENM_M/ENM_EnergyConsumptionStatistics/ResimilgForcast/ResimilgForcast_Process/Charge_Range/chrgforecastMilg_Process'
 * '<S126>' : 'ENM_model/ENM_M/ENM_EnergyConsumptionStatistics/ResimilgForcast/ResimilgForcast_Process/Charge_Range/SOCDownMilgForcProcess/ENM_Divide'
 * '<S127>' : 'ENM_model/ENM_M/ENM_EnergyConsumptionStatistics/ResimilgForcast/ResimilgForcast_Process/Charge_Range/SOCDownMilgForcProcess/ENM_Divide/Interval Test'
 * '<S128>' : 'ENM_model/ENM_M/ENM_EnergyConsumptionStatistics/ResimilgForcast/ResimilgForcast_Process/Charge_Range/SOCUpMilgForcProcess/ENM_Divide'
 * '<S129>' : 'ENM_model/ENM_M/ENM_EnergyConsumptionStatistics/ResimilgForcast/ResimilgForcast_Process/Charge_Range/SOCUpMilgForcProcess/ENM_Divide/Interval Test'
 * '<S130>' : 'ENM_model/ENM_M/ENM_EnergyConsumptionStatistics/ResimilgForcast/ResimilgForcast_Process/Charge_Range/chrgforecastMilg_Process/Filt_RealForecastMiles'
 * '<S131>' : 'ENM_model/ENM_M/ENM_EnergyConsumptionStatistics/ResimilgForcast/ResimilgForcast_Process/CurveTrendRestrain/ENM_DelayProcess'
 * '<S132>' : 'ENM_model/ENM_M/ENM_EnergyConsumptionStatistics/ResimilgForcast/ResimilgForcast_Process/CurveTrendRestrain/ENM_MIN'
 * '<S133>' : 'ENM_model/ENM_M/ENM_EnergyConsumptionStatistics/ResimilgForcast/ResimilgForcast_Process/CurveTrendRestrain/ENM_MIN1'
 * '<S134>' : 'ENM_model/ENM_M/ENM_EnergyConsumptionStatistics/ResimilgForcast/ResimilgForcast_Process/CurveTrendRestrain/ENM_MIN2'
 * '<S135>' : 'ENM_model/ENM_M/ENM_EnergyConsumptionStatistics/ResimilgForcast/ResimilgForcast_Process/CurveTrendRestrain/ENM_Max'
 * '<S136>' : 'ENM_model/ENM_M/ENM_EnergyConsumptionStatistics/ResimilgForcast/ResimilgForcast_Process/CurveTrendRestrain/ENM_Max1'
 * '<S137>' : 'ENM_model/ENM_M/ENM_EnergyConsumptionStatistics/ResimilgForcast/ResimilgForcast_Process/CurveTrendRestrain/ENM_DelayProcess/AffirmCheck'
 * '<S138>' : 'ENM_model/ENM_M/ENM_EnergyConsumptionStatistics/ResimilgForcast/ResimilgForcast_Process/ENM_Divide/Interval Test'
 * '<S139>' : 'ENM_model/ENM_M/ENM_EnergyConsumptionStatistics/ResimilgForcast/ResimilgForcast_Process/Filting/ENM_Rolling_Filter'
 * '<S140>' : 'ENM_model/ENM_M/ENM_EnergyConsumptionStatistics/ResimilgForcast/ResimilgForcast_Process/Filting/ENM_Rolling_Filter/ENM_Rolling_Everage1'
 * '<S141>' : 'ENM_model/ENM_M/ENM_EnergyConsumptionStatistics/ResimilgForcast/ResimilgForcast_Process/Filting/ENM_Rolling_Filter/ENM_Rolling_Everage1/ENM_Divide'
 * '<S142>' : 'ENM_model/ENM_M/ENM_EnergyConsumptionStatistics/ResimilgForcast/ResimilgForcast_Process/Filting/ENM_Rolling_Filter/ENM_Rolling_Everage1/ENM_Max'
 * '<S143>' : 'ENM_model/ENM_M/ENM_EnergyConsumptionStatistics/ResimilgForcast/ResimilgForcast_Process/Filting/ENM_Rolling_Filter/ENM_Rolling_Everage1/ENM_Divide/Interval Test'
 * '<S144>' : 'ENM_model/ENM_M/ENM_EnergyConsumptionStatistics/ResimilgForcast/ResimilgForcast_Process/MilgCanvasRestrain/RR_SOCRemapCheck'
 * '<S145>' : 'ENM_model/ENM_M/ENM_EnergyConsumptionStatistics/ResimilgForcast/ResimilgForcast_Process/RangeChangeFilter/ENM_Rolling_Filter'
 * '<S146>' : 'ENM_model/ENM_M/ENM_EnergyConsumptionStatistics/ResimilgForcast/ResimilgForcast_Process/RangeChangeFilter/ZeroSpd'
 * '<S147>' : 'ENM_model/ENM_M/ENM_EnergyConsumptionStatistics/ResimilgForcast/ResimilgForcast_Process/RangeChangeFilter/ENM_Rolling_Filter/ENM_Rolling_Everage1'
 * '<S148>' : 'ENM_model/ENM_M/ENM_EnergyConsumptionStatistics/ResimilgForcast/ResimilgForcast_Process/RangeChangeFilter/ENM_Rolling_Filter/ENM_Rolling_Everage1/ENM_Divide'
 * '<S149>' : 'ENM_model/ENM_M/ENM_EnergyConsumptionStatistics/ResimilgForcast/ResimilgForcast_Process/RangeChangeFilter/ENM_Rolling_Filter/ENM_Rolling_Everage1/ENM_Max'
 * '<S150>' : 'ENM_model/ENM_M/ENM_EnergyConsumptionStatistics/ResimilgForcast/ResimilgForcast_Process/RangeChangeFilter/ENM_Rolling_Filter/ENM_Rolling_Everage1/ENM_Divide/Interval Test'
 * '<S151>' : 'ENM_model/ENM_M/ENM_EnergyConsumptionStatistics/ResimilgForcast/ResimilgForcast_Process/RangeChangeFilter/ZeroSpd/ENM_DelayProcess'
 * '<S152>' : 'ENM_model/ENM_M/ENM_EnergyConsumptionStatistics/ResimilgForcast/ResimilgForcast_Process/RangeChangeFilter/ZeroSpd/Interval Test'
 * '<S153>' : 'ENM_model/ENM_M/ENM_EnergyConsumptionStatistics/ResimilgForcast/ResimilgForcast_Process/RangeChangeFilter/ZeroSpd/ENM_DelayProcess/AffirmCheck'
 * '<S154>' : 'ENM_model/ENM_M/ENM_EnergyConsumptionStatistics/ResimilgForcast/ResimilgRecord_Update/Chart'
 * '<S155>' : 'ENM_model/ENM_M/ENM_EnergyConsumptionStatistics/ResimilgForcast/ResimilgRecord_Update/OdodifProcess'
 * '<S156>' : 'ENM_model/ENM_M/ENM_PowerLimit/HVPower_Allocation'
 * '<S157>' : 'ENM_model/ENM_M/ENM_PowerLimit/HVPower_Allocation/DCDC_PwrLimit'
 * '<S158>' : 'ENM_model/ENM_M/ENM_PowerLimit/HVPower_Allocation/ECC_PowerLimit'
 * '<S159>' : 'ENM_model/ENM_M/ENM_PowerLimit/HVPower_Allocation/MotorDischarge_PowerLimit'
 * '<S160>' : 'ENM_model/ENM_M/ENM_PowerLimit/HVPower_Allocation/Motor_PowerChargeLimit'
 * '<S161>' : 'ENM_model/ENM_M/ENM_PowerLimit/HVPower_Allocation/DCDC_PwrLimit/ENM_kxx2xx1'
 * '<S162>' : 'ENM_model/ENM_M/ENM_PowerLimit/HVPower_Allocation/ECC_PowerLimit/ENM_MIN2'
 * '<S163>' : 'ENM_model/ENM_M/ENM_PowerLimit/HVPower_Allocation/MotorDischarge_PowerLimit/ENM_Max'
 * '<S164>' : 'ENM_model/ENM_M/ENM_PowerLimit/HVPower_Allocation/MotorDischarge_PowerLimit/ENM_xx2kxx1'
 */
#endif                                 /* RTW_HEADER_ENM_model_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

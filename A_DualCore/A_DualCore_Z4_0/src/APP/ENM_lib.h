/*
 * File: ENM_lib.h
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

#ifndef RTW_HEADER_ENM_lib_h_
#define RTW_HEADER_ENM_lib_h_
#include <math.h>
#ifndef ENM_model_COMMON_INCLUDES_
# define ENM_model_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* ENM_model_COMMON_INCLUDES_ */

#include "ENM_model_types.h"
#include "rt_nonfinite.h"

/* Block signals for system '<S31>/X_Remap_Y2' */
typedef struct
{
    real32_T Switch4;                  /* '<S60>/Switch4' */
}
rtB_X_Remap_Y_ENM_model_T;

/* Block signals for system '<S83>/ENM_kwh_kph_2_kwh' */
typedef struct
{
    real32_T Switch;                   /* '<S87>/Switch' */
}
rtB_ENM_kwh_kph_2_kwh_ENM_mod_T;

/* Block signals for system '<S81>/ENM_DelayProcess1' */
typedef struct
{
    uint8_T debounce;                  /* '<S94>/debounce' */
}
rtB_ENM_DelayProcess_ENM_mode_T;

/* Block states (auto storage) for system '<S81>/ENM_DelayProcess1' */
typedef struct
{
    int32_T Delay2_DSTATE;             /* '<S95>/Delay2' */
    uint8_T Delay_DSTATE;              /* '<S94>/Delay' */
}
rtDW_ENM_DelayProcess_ENM_mod_T;

/* Block signals for system '<S96>/ENM_Divide' */
typedef struct
{
    real32_T Switch;                   /* '<S97>/Switch' */
}
rtB_ENM_Divide_ENM_model_T;

/* Block signals for system '<S82>/ENM_kwh_km_2_kwh' */
typedef struct
{
    rtB_ENM_Divide_ENM_model_T ENM_Divide;/* '<S96>/ENM_Divide' */
}
rtB_ENM_kwh_km_2_kwh_ENM_mode_T;

/* Block signals for system '<S118>/ENM_DelayProcess1' */
typedef struct
{
    uint16_T debounce;                 /* '<S119>/debounce' */
}
rtB_ENM_DelayProcess_ENM_mo_l_T;

/* Block states (auto storage) for system '<S118>/ENM_DelayProcess1' */
typedef struct
{
    int32_T Delay2_DSTATE;             /* '<S120>/Delay2' */
    uint16_T Delay_DSTATE;             /* '<S119>/Delay' */
}
rtDW_ENM_DelayProcess_ENM_m_b_T;

/* Block signals for system '<S123>/ENM_Divide' */
typedef struct
{
    real32_T Switch;                   /* '<S126>/Switch' */
}
rtB_ENM_Divide_ENM_model_d_T;

/* Block signals for system '<S139>/ENM_Rolling_Everage1' */
typedef struct
{
    real32_T new_ave;                  /* '<S140>/Switch1' */
    rtB_ENM_Divide_ENM_model_d_T ENM_Divide;/* '<S140>/ENM_Divide' */
}
rtB_ENM_Rolling_Everage_ENM_m_T;

/* Block states (auto storage) for system '<S139>/ENM_Rolling_Everage1' */
typedef struct
{
    real_T IC_DSTATE;                  /* '<S140>/IC' */
}
rtDW_ENM_Rolling_Everage_ENM__T;

/* Block signals for system '<S110>/ENM_Rolling_Filter' */
typedef struct
{
    rtB_ENM_Rolling_Everage_ENM_m_T ENM_Rolling_Everage1;/* '<S139>/ENM_Rolling_Everage1' */
}
rtB_ENM_Rolling_Filter_ENM_mo_T;

/* Block states (auto storage) for system '<S110>/ENM_Rolling_Filter' */
typedef struct
{
    rtDW_ENM_Rolling_Everage_ENM__T ENM_Rolling_Everage1;/* '<S139>/ENM_Rolling_Everage1' */
}
rtDW_ENM_Rolling_Filter_ENM_m_T;

/* Block signals for system '<S114>/ENM_Rolling_Filter' */
typedef struct
{
    rtB_ENM_Rolling_Everage_ENM_m_T ENM_Rolling_Everage1;/* '<S145>/ENM_Rolling_Everage1' */
}
rtB_ENM_Rolling_Filter_ENM__d_T;

/* Block states (auto storage) for system '<S114>/ENM_Rolling_Filter' */
typedef struct
{
    rtDW_ENM_Rolling_Everage_ENM__T ENM_Rolling_Everage1;/* '<S145>/ENM_Rolling_Everage1' */
}
rtDW_ENM_Rolling_Filter_ENM_c_T;

/* Block signals for system '<S146>/ENM_DelayProcess' */
typedef struct
{
    boolean_T debounce;                /* '<S151>/debounce' */
}
rtB_ENM_DelayProcess_ENM_mo_a_T;

/* Block states (auto storage) for system '<S146>/ENM_DelayProcess' */
typedef struct
{
    int32_T Delay2_DSTATE;             /* '<S153>/Delay2' */
    boolean_T Delay_DSTATE;            /* '<S151>/Delay' */
}
rtDW_ENM_DelayProcess_ENM_m_p_T;

/* Block signals for system '<S99>/ENM_xx2kxx1' */
typedef struct
{
    real32_T y;                        /* '<S100>/Gain' */
}
rtB_ENM_xx2kxx_ENM_model_T;

/* Block signals for system '<S157>/ENM_kxx2xx1' */
typedef struct
{
    real32_T y;                        /* '<S161>/Gain' */
}
rtB_ENM_kxx2xx_ENM_model_T;

extern void ENM_model_X_Remap_Y(real32_T rtu_x, real32_T rtu_x_max, real32_T
    rtu_x_min, real32_T rtu_x_hide, real32_T rtu_y_max, real32_T rtu_y_min,
    rtB_X_Remap_Y_ENM_model_T *localB);
extern void ENM_model_ENM_kwh_kph_2_kwh(real32_T rtu_P_kwh, real32_T
    rtu_Vehspd_KMperHour, rtB_ENM_kwh_kph_2_kwh_ENM_mod_T *localB);
extern void ENM_model_ENM_DelayProcess(uint8_T rtu_din, real32_T rtu_t_dbnc,
    real32_T rtu_ms_diff, rtB_ENM_DelayProcess_ENM_mode_T *localB,
    rtDW_ENM_DelayProcess_ENM_mod_T *localDW);
extern void ENM_model_ENM_Divide(real32_T rtu_dividend, uint32_T rtu_divisor,
    rtB_ENM_Divide_ENM_model_T *localB);
extern void ENM_model_ENM_kwh_km_2_kwh(real32_T rtu_P_kwh, uint32_T rtu_Km,
    rtB_ENM_kwh_km_2_kwh_ENM_mode_T *localB);
extern void ENM_model_ENM_DelayProcess1(uint16_T rtu_din, real32_T rtu_t_dbnc,
    uint32_T rtu_ms_diff, rtB_ENM_DelayProcess_ENM_mo_l_T *localB,
    rtDW_ENM_DelayProcess_ENM_m_b_T *localDW);
extern void ENM_model_ENM_Divide_a(real32_T rtu_dividend, real32_T rtu_divisor,
    real32_T rtu_default_value, rtB_ENM_Divide_ENM_model_d_T *localB);
extern void ENM_mo_ENM_Rolling_Everage_Init(rtDW_ENM_Rolling_Everage_ENM__T
    *localDW);
extern void ENM_model_ENM_Rolling_Everage(real32_T rtu_new_value, real32_T
    rtu_old_ave, real32_T rtu_delta_t, real32_T rtu_tc,
    rtB_ENM_Rolling_Everage_ENM_m_T *localB, rtDW_ENM_Rolling_Everage_ENM__T
    *localDW);
extern void ENM_mod_ENM_Rolling_Filter_Init(rtDW_ENM_Rolling_Filter_ENM_m_T
    *localDW);
extern void ENM_model_ENM_Rolling_Filter(real32_T rtu_newValue, real32_T
    rtu_oldValue, real32_T rtu_delta_t_s, uint16_T rtu_tc,
    rtB_ENM_Rolling_Filter_ENM_mo_T *localB, rtDW_ENM_Rolling_Filter_ENM_m_T
    *localDW);
extern void ENM_m_ENM_Rolling_Filter_i_Init(rtDW_ENM_Rolling_Filter_ENM_c_T
    *localDW);
extern void ENM_model_ENM_Rolling_Filter_h(real32_T rtu_newValue, real32_T
    rtu_oldValue, real32_T rtu_delta_t_s, real32_T rtu_tc,
    rtB_ENM_Rolling_Filter_ENM__d_T *localB, rtDW_ENM_Rolling_Filter_ENM_c_T
    *localDW);
extern void ENM_model_ENM_DelayProcess_c(boolean_T rtu_din, real32_T rtu_t_dbnc,
    real32_T rtu_ms_diff, rtB_ENM_DelayProcess_ENM_mo_a_T *localB,
    rtDW_ENM_DelayProcess_ENM_m_p_T *localDW);
extern void ENM_model_ENM_xx2kxx(real32_T rtu_u, rtB_ENM_xx2kxx_ENM_model_T
    *localB);
extern void ENM_model_ENM_kxx2xx(real32_T rtu_u, rtB_ENM_kxx2xx_ENM_model_T
    *localB);

#endif                                 /* RTW_HEADER_ENM_lib_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

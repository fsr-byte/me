/*
 * File: ENM_model_private.h
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

#ifndef RTW_HEADER_ENM_model_private_h_
#define RTW_HEADER_ENM_model_private_h_
#include "rtwtypes.h"
#ifndef UCHAR_MAX
#include <limits.h>
#endif

#if ( UCHAR_MAX != (0xFFU) ) || ( SCHAR_MAX != (0x7F) )
#error Code was generated for compiler with different sized uchar/char. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( USHRT_MAX != (0xFFFFU) ) || ( SHRT_MAX != (0x7FFF) )
#error Code was generated for compiler with different sized ushort/short. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( UINT_MAX != (0xFFFFFFFFU) ) || ( INT_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized uint/int. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( ULONG_MAX != (0xFFFFFFFFU) ) || ( LONG_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized ulong/long. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

/* Imported (extern) block signals */
extern INP INP_output;                 /* '<Root>/INP' */
extern DHP DHP_output;                 /* '<Root>/DHP' */
extern PMM PMM_output;                 /* '<Root>/PMM' */
extern TQM TQM_output;                 /* '<Root>/TQM' */
extern TMM TMM_output;                 /* '<Root>/TMM' */
extern CHRG CHRG_output;               /* '<Root>/CHRG' */
extern Config Config_output;           /* '<Root>/CONFIG' */

/* Imported (extern) states */
extern real32_T BMSSocLast;            /* '<S1>/Data Store Memory' */
extern real32_T VCUVehEgyCnseDrv;      /* '<S1>/Data Store Memory10' */
extern real32_T PT_TotalEgyCnse_kwh_sport;/* '<S1>/Data Store Memory16' */
extern real32_T PT_TotalEgyCnse_kwh_eco;/* '<S1>/Data Store Memory17' */
extern real32_T sport_egyCnse_Zone_km[20];/* '<S1>/Data Store Memory18' */
extern real32_T sport_egy_s_Zone_km;   /* '<S1>/Data Store Memory23' */
extern real32_T sport_egyCnse_1km[5];  /* '<S1>/Data Store Memory24' */
extern real32_T sport_egy_s_1km;       /* '<S1>/Data Store Memory27' */
extern real32_T eco_egyCnse_Zone_km[20];/* '<S1>/Data Store Memory28' */
extern real32_T eco_egy_s_Zone_km;     /* '<S1>/Data Store Memory31' */
extern real32_T eco_egyCnse_1km[5];    /* '<S1>/Data Store Memory32' */
extern real32_T eco_egy_s_1km;         /* '<S1>/Data Store Memory35' */
extern real32_T SOCDisp;               /* '<S1>/Data Store Memory43' */
extern real32_T BMSBattResidPwrLast;   /* '<S1>/Data Store Memory44' */
extern real32_T BMSSocMaxLast;         /* '<S1>/Data Store Memory6' */
extern real32_T BMSSocMinLast;         /* '<S1>/Data Store Memory7' */
extern real32_T VCUTotalEgyCnse_kwh;   /* '<S1>/Data Store Memory8' */
extern real32_T VCUSubTotalEgyCnse_kwh;/* '<S1>/Data Store Memory9' */
extern real32_T SocJumpPoint;          /* '<S31>/Data Store Memory' */
extern real32_T sysSocJumpPoint;       /* '<S31>/Data Store Memory1' */
extern uint32_T BootSWVer;             /* '<S1>/Data Store Memory1' */
extern uint32_T SystemTickMs;          /* '<S1>/Data Store Memory11' */
extern uint32_T SubTotMilg;            /* '<S1>/Data Store Memory14' */
extern uint32_T Odo_km_sport;          /* '<S1>/Data Store Memory19' */
extern uint32_T VCUHWVer;              /* '<S1>/Data Store Memory2' */
extern uint32_T Odo_km_eco;            /* '<S1>/Data Store Memory20' */
extern uint32_T sport_mile_Zone_km;    /* '<S1>/Data Store Memory22' */
extern uint32_T sport_mile_1km;        /* '<S1>/Data Store Memory26' */
extern uint32_T AppSWVer;              /* '<S1>/Data Store Memory3' */
extern uint32_T eco_mile_Zone_km;      /* '<S1>/Data Store Memory30' */
extern uint32_T eco_mile_1km;          /* '<S1>/Data Store Memory34' */
extern uint32_T CalSWVer;              /* '<S1>/Data Store Memory4' */
extern uint32_T VCUOdo_km;             /* '<S1>/Data Store Memory40' */
extern uint32_T BMSBattRatedPwrLast;   /* '<S1>/Data Store Memory46' */
extern uint32_T BMSBattRatedPwrNextTime;/* '<S1>/Data Store Memory47' */
extern uint32_T CfgSWVer;              /* '<S1>/Data Store Memory5' */
extern uint16_T ResiMilg;              /* '<S1>/Data Store Memory12' */
extern uint8_T sport_ptr_Zone_km;      /* '<S1>/Data Store Memory21' */
extern uint8_T sport_ptr_1km;          /* '<S1>/Data Store Memory25' */
extern uint8_T eco_ptr_Zone_km;        /* '<S1>/Data Store Memory29' */
extern uint8_T eco_ptr_1km;            /* '<S1>/Data Store Memory33' */
extern uint8_T DriveMode;              /* '<S1>/Data Store Memory45' */
extern boolean_T MidJumpFlg;           /* '<S31>/Data Store Memory2' */

/* Imported (extern) block parameters */
extern uint16_T NEDC_Milg_km;          /* Variable: NEDC_Milg_km
                                        * Referenced by:
                                        *   '<S102>/Chart'
                                        *   '<S115>/Constant1'
                                        */
real32_T look_SplNBinCZcf(uint32_T numDims, const real32_T* u, const
    rt_LUTSplineWork * const SWork);
void rt_Spline2Derivf(const real32_T *x, const real32_T *y, uint32_T n, real32_T
                      *u, real32_T *y2);
real32_T intrp_NSplcf(uint32_T numDims, const rt_LUTSplineWork * const splWork,
                      uint32_T extrapMethod);
extern real32_T look2_iflf_binlca(real32_T u0, real32_T u1, const real32_T bp0[],
    const real32_T bp1[], const real32_T table[], const uint32_T maxIndex[],
    uint32_T stride);
extern uint32_T binsearch_u32f(real32_T u, const real32_T bp[], uint32_T
    startIndex, uint32_T maxIndex);
extern uint32_T plook_u32ff_binc(real32_T u, const real32_T bp[], uint32_T
    maxIndex, real32_T *fraction);

/* Exported data declaration */

/* Declaration for custom storage class: ImportFromFile */
extern uint8_T Vehicle_Type;

#endif                                 /* RTW_HEADER_ENM_model_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

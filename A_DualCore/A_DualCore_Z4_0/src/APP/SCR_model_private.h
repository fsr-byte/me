/*
 * File: SCR_model_private.h
 *
 * Code generated for Simulink model 'SCR_model'.
 *
 * Model version                  : 1.2266
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Fri Mar 18 15:47:47 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Freescale->32-bit PowerPC
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. MISRA C:2012 guidelines
 * Validation result: Not run
 */

#ifndef RTW_HEADER_SCR_model_private_h_
#define RTW_HEADER_SCR_model_private_h_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
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

#if 0

/* Skip this size verification because of preprocessor limitation */
#if ( ULLONG_MAX != (0xFFFFFFFFFFFFFFFFULL) ) || ( LLONG_MAX != (0x7FFFFFFFFFFFFFFFLL) )
#error Code was generated for compiler with different sized ulong_long/long_long. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif
#endif

/* Imported (extern) block signals */
extern INP INP_output;                 /* '<Root>/INP' */
extern TQM TQM_output;                 /* '<Root>/TQM' */
extern DHP DHP_output;                 /* '<Root>/DHP' */
extern PMM PMM_output;                 /* '<Root>/PMM' */
extern Config Config_output;           /* '<Root>/Config' */
extern HALI HALI_output;               /* '<Root>/HALI' */
extern BTK BTK_output;                 /* '<Root>/BTK' */

/* Imported (extern) states */
extern uint32_T SystemTickMs;          /* '<S1>/Data Store Memory4' */
extern uint8_T VINP_CruiseKeyOnOff_flg;/* '<S3>/Data Store Memory' */
extern uint8_T VINP_CruiseKeyCancel_flg;/* '<S3>/Data Store Memory1' */
extern uint8_T VINP_CruiseKeySet_flg;  /* '<S3>/Data Store Memory2' */
extern uint8_T VINP_CruiseKeyRes_flg;  /* '<S3>/Data Store Memory3' */
extern int16_T lib_TQFRate_look1_iu16_mN9lGnRS(uint16_T u0, const uint16_T bp0[],
    const int16_T table[], uint32_T maxIndex);
extern real32_T lib_TQFRate_look1_iflf_binlca(real32_T u0, const real32_T bp0[],
    const real32_T table[], uint32_T maxIndex);
extern real32_T lib_TQFRate_look2_iflf_binlca(real32_T u0, real32_T u1, const
    real32_T bp0[], const real32_T bp1[], const real32_T table[], const uint32_T
    maxIndex[], uint32_T stride);
extern real32_T lib_TQFRate_look2_iflf_binfca(real32_T u0, real32_T u1, const
    real32_T bp0[], const real32_T bp1[], const real32_T table[], const uint32_T
    maxIndex[], uint32_T stride);
extern int64_T lib_TQFRate_div_nde_s64_floor(int64_T numerator, int64_T
    denominator);

/* Exported data declaration */

/* Declaration for custom storage class: ImportFromFile */
extern uint8_T Gear_D;                 /* D挡标志 */
extern uint8_T Gear_N;                 /* N挡标志 */
extern uint8_T Gear_P;                 /* P挡标志 */
extern uint8_T Gear_R;                 /* R挡标志 */

#endif                                 /* RTW_HEADER_SCR_model_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

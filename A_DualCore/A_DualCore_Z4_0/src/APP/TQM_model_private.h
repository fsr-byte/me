/*
 * File: TQM_model_private.h
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

#ifndef RTW_HEADER_TQM_model_private_h_
#define RTW_HEADER_TQM_model_private_h_
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
extern DHP DHP_output;                 /* '<Root>/DHP' */
extern PMM PMM_output;                 /* '<Root>/PMM' */
extern TMM TMM_output;                 /* '<Root>/TMM' */
extern ENM ENM_output;                 /* '<Root>/ENM' */
extern CHRG CHRG_output;               /* '<Root>/CHRG' */
extern Config Config_output;           /* '<Root>/Config' */
extern TQFRate TQFRate_output;         /* '<Root>/TQFRate' */
extern SPDCtl SPDCtl_output;           /* '<Root>/SPDCtl' */
extern ACR ACR_output;                 /* '<Root>/ACR' */
extern BTK BTK_output;                 /* '<Root>/BTK' */

/* Imported (extern) states */
extern uint32_T SystemTickMs;          /* '<S1>/Data Store Memory11' */
extern uint8_T creepGearPositon;       /* '<S105>/Data Store Memory' */

/* Imported (extern) block parameters */
extern uint8_T VHALI_HWVersion;        /* Variable: VHALI_HWVersion
                                        * Referenced by:
                                        *   '<S324>/Constant'
                                        *   '<S325>/Constant'
                                        */
extern real32_T lib_TQM_rt_roundf(real32_T u);
extern uint8_T lib_TQM_look2_is16lu32_Q5rw11mL(int16_T u0, int16_T u1, const
    int16_T bp0[], const int16_T bp1[], const uint8_T table[], const uint32_T
    maxIndex[], uint32_T stride);
extern int16_T lib_TQM_look1_is16bu16_iBDnE1uu(int16_T u0, const uint16_T bp0[],
    const int16_T table[], uint32_T maxIndex);
extern uint16_T lib_TQM_look2_iu16u16l_x5FvcwBO(uint16_T u0, uint16_T u1, const
    uint16_T bp0[], const uint16_T bp1[], const uint16_T table[], const uint32_T
    maxIndex[], uint32_T stride);
extern int16_T lib_TQM_look1_iu16lu64_PJIv0ole(uint16_T u0, const uint16_T bp0[],
    const int16_T table[], uint32_T maxIndex);
extern uint16_T lib_TQM_look1_is32bs16_IoO5fz3f(int32_T u0, const int16_T bp0[],
    const uint16_T table[], uint32_T maxIndex);
extern uint16_T lib_TQM_look1_is32bs16_CX55w5u5(int32_T u0, const int16_T bp0[],
    const uint16_T table[], uint32_T maxIndex);
extern uint16_T lib_TQM_look2_iu16u16b_QtGVXG9F(uint16_T u0, uint16_T u1, const
    uint16_T bp0[], const uint16_T bp1[], const uint16_T table[], const uint32_T
    maxIndex[], uint32_T stride);
extern int32_T lib_TQM_div_nde_s32_floor(int32_T numerator, int32_T denominator);
extern uint32_T lib_TQM_div_nzp_u32_round(uint32_T numerator, uint32_T
    denominator);
extern uint32_T lib_TQM_div_nzp_us32(int32_T numerator, int32_T denominator);
extern uint64_T lib_TQM_div_nzp_u64_round(uint64_T numerator, uint64_T
    denominator);

#endif                                 /* RTW_HEADER_TQM_model_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

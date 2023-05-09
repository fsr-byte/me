/*
 * File: TMM_model_private.h
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

#ifndef RTW_HEADER_TMM_model_private_h_
#define RTW_HEADER_TMM_model_private_h_
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

/* Imported (extern) block signals */
extern PMM PMM_output;                 /* '<Root>/PMM' */
extern INP INP_output;                 /* '<Root>/INP' */
extern DHP DHP_output;                 /* '<Root>/DHP' */
extern TQM TQM_output;                 /* '<Root>/TQM' */
extern ENM ENM_output;                 /* '<Root>/ENM' */
extern CHRG CHRG_output;               /* '<Root>/CHRG' */
extern Config Config_output;           /* '<Root>/CONFIG' */
extern HALI HALI_output;               /* '<Root>/HAL' */

/* Imported (extern) states */
extern uint32_T SystemTickMs;          /* '<S1>/Data Store Memory1' */
extern uint16_T look1_is16lu32n16tu16_binlcse(int16_T u0, const int16_T bp0[],
  const uint16_T table[], uint32_T maxIndex);
extern int16_T look1_is16lu32n16Ds32_binlcs(int16_T u0, const int16_T bp0[],
  const int16_T table[], uint32_T maxIndex);
extern uint8_T look1_iu8lu32n24_binlcse(uint8_T u0, const uint8_T bp0[], const
  uint8_T table[], uint32_T maxIndex);
extern uint8_T look2_iflfyu8tu8DfIf_binlcs(real32_T u0, real32_T u1, const
  real32_T bp0[], const real32_T bp1[], const uint8_T table[], const uint32_T
  maxIndex[], uint32_T stride);
extern real32_T look1_iflf_binlca(real32_T u0, const real32_T bp0[], const
  real32_T table[], uint32_T maxIndex);
extern uint16_T look2_iu32lu32tu16_binfcae(uint32_T u0, uint32_T u1, const
  uint32_T bp0[], const uint32_T bp1[], const uint16_T table[], const uint32_T
  maxIndex[], uint32_T stride);
extern uint32_T plook_u32s16_bincka(int16_T u, const int16_T bp[], uint32_T
  maxIndex);
extern uint32_T plook_u32u8_bincka(uint8_T u, const uint8_T bp[], uint32_T
  maxIndex);
extern uint32_T binsearch_u32s16(int16_T u, const int16_T bp[], uint32_T
  startIndex, uint32_T maxIndex);
extern uint32_T binsearch_u32u8(uint8_T u, const uint8_T bp[], uint32_T
  startIndex, uint32_T maxIndex);

/* Exported data declaration */

/* Declaration for custom storage class: ImportFromFile */
extern uint8_T Vehicle_Type;

#endif                                 /* RTW_HEADER_TMM_model_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

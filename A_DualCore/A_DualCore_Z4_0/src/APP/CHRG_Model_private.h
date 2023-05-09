/*
 * File: CHRG_Model_private.h
 *
 * Code generated for Simulink model 'CHRG_Model'.
 *
 * Model version                  : 1.1917
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Fri Mar 18 15:31:54 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Freescale->32-bit PowerPC
 * Code generation objectives:
 *    1. RAM efficiency
 *    2. ROM efficiency
 *    3. Execution efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_CHRG_Model_private_h_
#define RTW_HEADER_CHRG_Model_private_h_
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
extern INP INP_output;                 /* '<Root>/INP' */
extern DHP DHP_output;                 /* '<Root>/DHP' */
extern TMM TMM_output;                 /* '<Root>/TMM' */
extern TQM TQM_output;                 /* '<Root>/TQM' */
extern PMM PMM_output;                 /* '<Root>/PMM' */
extern Config Config_output;           /* '<Root>/Config' */

/* Imported (extern) states */
extern uint32_T SystemTickMs;          /* '<Root>/Data Store Memory' */
extern uint32_T VHALI_OBC_311_MsgTicks;/* '<Root>/Data Store Memory4' */

#endif                                 /* RTW_HEADER_CHRG_Model_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

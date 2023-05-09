/*
 * File: AVAS_Model_private.h
 *
 * Code generated for Simulink model 'AVAS_Model'.
 *
 * Model version                  : 1.506
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Fri Mar 18 15:40:41 2022
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

#ifndef RTW_HEADER_AVAS_Model_private_h_
#define RTW_HEADER_AVAS_Model_private_h_
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
extern Config Config_output;           /* '<Root>/CONFIG' */
extern TQM TQM_output;                 /* '<Root>/TQM' */
extern PMM PMM_output;                 /* '<Root>/PMM' */
extern BTK BTK_output;                 /* '<Root>/BTK' */

/* Imported (extern) states */
extern uint32_T SystemTickMs;          /* '<Root>/Data Store Memory1' */
extern uint32_T VHALI_ABS_232_MsgTicks;/* '<Root>/Data Store Memory2' */
extern int16_T ex_ExportHistoryVal;    /* '<Root>/Data Store Memory' */
extern int16_T ex_ImportHistoryVal;    /* '<Root>/Data Store Memory3' */
extern int16_T ex_SeatAxlePos;         /* '<Root>/Data Store Memory4' */

/* Exported data declaration */

/* Declaration for custom storage class: ImportFromFile */
extern uint8_T Vehicle_Type;

#endif                                 /* RTW_HEADER_AVAS_Model_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

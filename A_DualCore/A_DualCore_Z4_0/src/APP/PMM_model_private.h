/*
 * File: PMM_model_private.h
 *
 * Code generated for Simulink model 'PMM_model'.
 *
 * Model version                  : 1.3119
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Fri Mar 18 15:42:54 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Freescale->32-bit PowerPC
 * Code generation objectives:
 *    1. RAM efficiency
 *    2. ROM efficiency
 *    3. Execution efficiency
 *    4. MISRA C:2012 guidelines
 * Validation result: Not run
 */

#ifndef RTW_HEADER_PMM_model_private_h_
#define RTW_HEADER_PMM_model_private_h_
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
extern ENM ENM_output;                 /* '<Root>/ENM' */
extern TMM TMM_output;                 /* '<Root>/TMM' */
extern TQM TQM_output;                 /* '<Root>/TQM' */
extern PEPS_PEPS PEPS_output;          /* '<Root>/PEPS' */
extern CHRG CHRG_output;               /* '<Root>/CHRG' */
extern HALI HALI_output;               /* '<Root>/HALI' */
extern Config Config_output;           /* '<Root>/Config' */
extern BTK BTK_output;                 /* '<Root>/BTK' */

/* Imported (extern) states */
extern real_T VCHRG_ChrgLockCheck_flg; /* '<S2>/Data Store Memory' */
extern uint32_T SystemTickMs;          /* '<S2>/Data Store Memory3' */
extern uint32_T VHALI_MCU_115_MsgTicks;/* '<S1>/Data Store Memory2' */
extern uint32_T VHALI_BMS_113_MsgTicks;/* '<S1>/Data Store Memory3' */
extern uint32_T VHALI_DCDC_231_MsgTicks;/* '<S1>/Data Store Memory4' */

/* Imported (extern) block parameters */
extern uint8_T Authentication_flg;     /* Variable: Authentication_flg
                                        * Referenced by: '<S2>/Constant12'
                                        */
extern boolean_T IsVINUseInitValue;    /* Variable: IsVINUseInitValue
                                        * Referenced by: '<S14>/Constant1'
                                        */
extern void mul_wide_su32(int32_T in0, uint32_T in1, uint32_T *ptrOutBitsHi,
  uint32_T *ptrOutBitsLo);
extern uint32_T mul_usu32_sat(int32_T a, uint32_T b);

/* Exported data declaration */

/* Declaration for custom storage class: ImportFromFile */
extern boolean_T VCHRG_ChrgStop_flg;
extern uint8_T VHALI_PEPS_PDU;

#endif                                 /* RTW_HEADER_PMM_model_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

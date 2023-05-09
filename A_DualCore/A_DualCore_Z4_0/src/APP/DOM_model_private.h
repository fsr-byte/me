/*
 * File: DOM_model_private.h
 *
 * Code generated for Simulink model 'DOM_model'.
 *
 * Model version                  : 1.961
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Fri Mar 18 15:38:19 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Freescale->32-bit PowerPC
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. ROM efficiency
 *    3. RAM efficiency
 *    4. MISRA C:2012 guidelines
 * Validation result: Not run
 */

#ifndef RTW_HEADER_DOM_model_private_h_
#define RTW_HEADER_DOM_model_private_h_
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
extern ENM ENM_output;                 /* '<Root>/ENM' */
extern PEPS_PEPS PEPS_output;          /* '<Root>/PEPS' */
extern CHRG CHRG_output;               /* '<Root>/CHRG' */
extern AVAS AVAS_output;               /* '<Root>/AVAS' */
extern Config Config_output;           /* '<Root>/CONFIG' */
extern SPDCtl SPDCtl_output;           /* '<Root>/SPDCtl' */

/* Exported data declaration */

/* Declaration for custom storage class: ImportFromFile */
extern boolean_T VCHRG_ChrgModeAbnormalRemind_flg;
extern boolean_T VCHRG_ChrgModeInvalidRemind_flg;
extern boolean_T VHALO_ACEnReq_flg;
extern boolean_T VHALO_BrakeLamp_flg;
extern boolean_T VHALO_HSpdFanActive_flg;
extern boolean_T VHALO_HVInterlockActive_flg;
extern boolean_T VHALO_LSpdFanActive_flg;
extern boolean_T VHALO_MCURelayActive_flg;
extern boolean_T VHALO_MainRelayActive_flg;
extern boolean_T VHALO_PTCRelayActive_flg;
extern boolean_T VHALO_RLight_flg;
extern boolean_T VHALO_WPTCRelayActive_flg;
extern boolean_T VHALO_WaterPumpActive_flg;
extern uint8_T VHALO_WaterPumpPWMDuty_pct;

#endif                                 /* RTW_HEADER_DOM_model_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

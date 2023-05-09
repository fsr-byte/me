/*
 * File: DIM_model_private.h
 *
 * Code generated for Simulink model 'DIM_model'.
 *
 * Model version                  : 1.2422
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Fri Mar 18 15:35:30 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Freescale->32-bit PowerPC
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_DIM_model_private_h_
#define RTW_HEADER_DIM_model_private_h_
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
extern HALI HALI_output;               /* '<Root>/HALI' */
extern DHP DHP_output;                 /* '<Root>/DHP' */
extern PMM PMM_output;                 /* '<Root>/PMM' */

/* Imported (extern) states */
extern uint32_T SystemTickMs;          /* '<Root>/Data Store Memory' */
extern uint32_T VHALI_BMS_303_MsgTicks;/* '<S2>/Data Store Memory1' */
extern uint32_T VHALI_TMS_2C0_MsgTicks;/* '<S2>/Data Store Memory10' */
extern uint32_T VHALI_BMS_113_MsgTicks;/* '<S2>/Data Store Memory19' */
extern uint32_T VHALI_BMS_233_MsgTicks;/* '<S2>/Data Store Memory2' */
extern uint32_T VHALI_GW_522_MsgTicks; /* '<S2>/Data Store Memory3' */
extern uint32_T VHALI_PEPS_282_MsgTicks;/* '<S2>/Data Store Memory4' */
extern uint32_T VHALI_EAC_349_MsgTicks;/* '<S2>/Data Store Memory5' */
extern uint32_T VHALI_WPTC_566_MsgTicks;/* '<S2>/Data Store Memory6' */
extern uint32_T VHALI_WPTC_2F0_MsgTicks;/* '<S2>/Data Store Memory7' */
extern uint32_T VHALI_ECC_35C_MsgTicks;/* '<S2>/Data Store Memory8' */
extern uint32_T VHALI_ECC_34C_MsgTicks;/* '<S2>/Data Store Memory9' */
extern uint8_T CAN3_BusOffState;       /* '<S2>/Data Store Memory20' */
extern uint8_T VHALI_HWVersion;        /* '<S1189>/Data Store Memory1' */
extern uint8_T ECU_FUN_CFG_Valid;      /* '<S1>/Data Store Memory' */
extern uint8_T ECU_FUN_CFG_Byte[6];    /* '<S1>/Data Store Memory1' */
extern uint8_T VCU_CFG_Valid;          /* '<S1>/Data Store Memory2' */
extern uint8_T VCU_CFG_Byte[8];        /* '<S1>/Data Store Memory3' */

/* Exported data declaration */

/* Declaration for custom storage class: ImportFromFile */
extern uint8_T A11_Mark;
extern uint8_T S11P01_Mark;
extern uint8_T S11P03_Mark;
extern uint8_T S11P05_Mark;
extern uint8_T S11_Mark;
extern uint8_T S21_Mark;
extern uint8_T Vehicle_Type;
extern uint8_T X11_Mark;
extern boolean_T gblUdsCommCtrl;
extern boolean_T hIOP_MCURelay_flg;
extern boolean_T hIOP_MainRelay_flg;

#endif                                 /* RTW_HEADER_DIM_model_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

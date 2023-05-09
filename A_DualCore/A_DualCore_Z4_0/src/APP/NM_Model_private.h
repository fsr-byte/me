/*
 * File: NM_Model_private.h
 *
 * Code generated for Simulink model 'NM_Model'.
 *
 * Model version                  : 1.357
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Fri Mar 18 15:42:08 2022
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

#ifndef RTW_HEADER_NM_Model_private_h_
#define RTW_HEADER_NM_Model_private_h_
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
extern PMM PMM_output;                 /* '<Root>/PMM' */

/* Imported (extern) states */
extern uint32_T SystemTickMs;          /* '<S1>/Data Store Memory3' */

/* Exported data declaration */

/* Declaration for custom storage class: ImportFromFile */
extern boolean_T CanWakeUp_Flg;
extern boolean_T HwWakeup_Flg;
extern boolean_T VBTK_SleepAllw_flg;
extern uint8_T VHALI_BusOff_Flg;       /* ����BusOff��� */
extern uint8_T VHALI_NMAcknowledge;    /* Nm����SleepAck */
extern uint8_T VHALI_NMAlive;          /* NM����Alive */
extern uint8_T VHALI_NMDestinationID;  /* NM����Ŀ���ַ */
extern uint8_T VHALI_NMIndication;     /* Nm����SleepInd */
extern uint8_T VHALI_NMRing;           /* NM����Ring */
extern uint32_T VHALI_NMRx_MsgTicks;   /* NM���Ľ��ռ��� */
extern uint16_T VHALI_NMSourceID;      /* NM����Դ��ַ */
extern uint32_T VHALI_NMTxSuceess_MsgTicks;/* NM���ķ��ͳɹ����� */
extern uint8_T VHALO_BusShutDnReq;     /* ���߹ر����� */
extern uint8_T VHALO_DisableAppComm;   /* VCUͣ������ */
extern boolean_T VHALO_InternalSleepActive_flg;
extern uint8_T VHALO_NMSendAcknowledge;/* NM����SleepAck */
extern uint8_T VHALO_NMSendAlive;      /* NM����Alive */
extern uint8_T VHALO_NMSendDestination;/* NM���ķ���Ŀ���ַ */
extern uint8_T VHALO_NMSendIndication; /* NM����SleepInd */
extern uint8_T VHALO_NMSendLimpHome;   /* NM����Limphome */
extern uint8_T VHALO_NMSendReq;        /* NM�������� */
extern uint8_T VHALO_NMSendRing;       /* NM����Ring */

#endif                                 /* RTW_HEADER_NM_Model_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

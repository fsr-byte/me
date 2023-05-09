/*
 * File: DOM_Cal_Data.h
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

#ifndef RTW_HEADER_DOM_Cal_Data_h_
#define RTW_HEADER_DOM_Cal_Data_h_
#include "rtwtypes.h"
#include "DOM_model_types.h"

/* Exported data define */

/* Definition for custom storage class: Define */
#define DIP_FORBIDCHANGEGEAR           18U
#define DIP_FORBIDCHANGEGEARP          19U
#define DIP_PRESSBRAKEPEDAL            2U
#define DIP_TEXTDISPLAY_0X10           16U
#define DIP_TEXTDISPLAY_0X11           17U
#define DIP_TEXTDISPLAY_0X12           18U
#define DIP_TEXTDISPLAY_0X13           19U
#define DIP_TEXTDISPLAY_0X14           20U
#define DIP_TEXTDISPLAY_0X16           22U
#define DIP_TEXTDISPLAY_0X17           23U
#define DIP_TEXTDISPLAY_0X18           24U
#define DIP_TEXTDISPLAY_0X19           25U
#define DIP_TEXTDISPLAY_0X1A           26U
#define DIP_TEXTDISPLAY_0X1B           27U
#define DIP_TEXTDISPLAY_0X1C           28U
#define DIP_TEXTDISPLAY_0X1D           29U
#define DIP_TEXTDISPLAY_0X1E           30U
#define DIP_TEXTDISPLAY_0X1F           31U
#define DIP_TEXTDISPLAY_0X2            2U
#define DIP_TEXTDISPLAY_0X5            5U
#define DIP_TEXTDISPLAY_0X8            8U
#define DIP_TEXTDISPLAY_0X9            9U
#define DIP_TEXTDISPLAY_0XA            10U
#define DIP_TEXTDISPLAY_0XB            11U
#define DIP_TEXTDISPLAY_0XE            14U
#define DIP_TEXTDISPLAY_0XF            15U
#define DOM_FALSE                      0
#define TQM_EPBERROR                   22U
#define TQM_GEARPUNLOCK                3U

/* Exported data declaration */
#include "derivative.h"

/* Declaration for custom storage class: CAL_14_DOM */
extern CAL_DOM boolean_T KOUTP_ACEnReq_invert;
extern CAL_DOM boolean_T KOUTP_ACEnReq_ovrdflg;
extern CAL_DOM boolean_T KOUTP_ACEnReq_ovrdval;
extern CAL_DOM boolean_T KOUTP_HSpdFanActive_flg_ovrdflg;
extern CAL_DOM boolean_T KOUTP_HSpdFanActive_flg_ovrdval;
extern CAL_DOM boolean_T KOUTP_HSpdFanActive_invert;
extern CAL_DOM boolean_T KOUTP_HVInterlockActive_flg_ovrdflg;
extern CAL_DOM boolean_T KOUTP_HVInterlockActive_flg_ovrdval;
extern CAL_DOM boolean_T KOUTP_HVInterlockActive_invert;
extern CAL_DOM boolean_T KOUTP_LSpdFanActive_flg_ovrdflg;
extern CAL_DOM boolean_T KOUTP_LSpdFanActive_flg_ovrdval;
extern CAL_DOM boolean_T KOUTP_LSpdFanActive_invert;
extern CAL_DOM boolean_T KOUTP_MCURelayActive_flg_ovrdflg;
extern CAL_DOM boolean_T KOUTP_MCURelayActive_flg_ovrdval;
extern CAL_DOM boolean_T KOUTP_MCURelayActive_invert;
extern CAL_DOM boolean_T KOUTP_MainRelayActive_flg_ovrdflg;
extern CAL_DOM boolean_T KOUTP_MainRelayActive_flg_ovrdval;
extern CAL_DOM boolean_T KOUTP_MainRelayActive_invert;
extern CAL_DOM boolean_T KOUTP_PTCRelayActive_flg_ovrdflg;
extern CAL_DOM boolean_T KOUTP_PTCRelayActive_flg_ovrdval;
extern CAL_DOM boolean_T KOUTP_PTCRelayActive_invert;
extern CAL_DOM boolean_T KOUTP_RLight_flg_ovrdflg;
extern CAL_DOM boolean_T KOUTP_RLight_flg_ovrdval;
extern CAL_DOM boolean_T KOUTP_RLight_invert;
extern CAL_DOM boolean_T KOUTP_WPTCRelayActive_flg_ovrdflg;
extern CAL_DOM boolean_T KOUTP_WPTCRelayActive_flg_ovrdval;
extern CAL_DOM boolean_T KOUTP_WPTCRelayActive_invert;
extern CAL_DOM boolean_T KOUTP_WaterPumpActive_flg_ovrdflg;
extern CAL_DOM boolean_T KOUTP_WaterPumpActive_flg_ovrdval;
extern CAL_DOM boolean_T KOUTP_WaterPumpActive_invert;
extern CAL_DOM boolean_T KOUTP_WaterPumpPWMDuyt_pct_ovrdflg;
extern CAL_DOM uint8_T KOUTP_WaterPumpPWMDuyt_pct_ovrdval;
extern CAL_DOM boolean_T KOUT_TextDisplay_beforeSOP_flg;

#endif                                 /* RTW_HEADER_DOM_Cal_Data_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

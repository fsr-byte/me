/*
 * File: DIM_model_private.h
 *
 * Code generated for Simulink model 'DIM_model'.
 *
 * Model version                  : 1.2351
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Apr 12 11:32:26 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Freescale->32-bit PowerPC
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. MISRA C:2012 guidelines
 * Validation result: Not run
 */

#ifndef RTW_HEADER_DIM_model_private_h_
#define RTW_HEADER_DIM_model_private_h_
#include "rtwtypes.h"

/* Exported data declaration */

/* Declaration for custom storage class: ImportFromFile */
extern boolean_T GUI_BrkLightSwitchActive_flg;/* CAN 0x101 */
extern uint8_T GUI_VehicleSpeed;       /* CAN 0x101 */
extern boolean_T HWin_IgnitionOn_flg;  /* HW  KL15+ */
extern boolean_T HWin_SSB_Switch1;     /* HW  DIN_24 */
extern boolean_T HWin_SSB_Switch2;     /* HW  DIN_27 */

#endif                                 /* RTW_HEADER_DIM_model_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

/*
 * File: TQM_OUT.h
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

#ifndef RTW_HEADER_TQM_OUT_h_
#define RTW_HEADER_TQM_OUT_h_
#ifndef TQM_model_COMMON_INCLUDES_
# define TQM_model_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* TQM_model_COMMON_INCLUDES_ */

#include "TQM_model_types.h"

/* Child system includes */
#include "Brake_Lamp_Control.h"
#include "MCU_AntiShake.h"
#include "MCU_Mode_Request.h"
#include "MCU_Torque_Arbitration.h"
#include "Reversing_Light_Control.h"

extern void TQM_mode_Get_TickDiff_ms_g_Init(void);
extern void TQM_model_Get_TickDiff_ms_a(void);
extern void TQM_model_TQM_OUT_Init(void);
extern void TQM_model_TQM_OUT(void);

#endif                                 /* RTW_HEADER_TQM_OUT_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

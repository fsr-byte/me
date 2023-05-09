/*
 * File: TQF.h
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

#ifndef RTW_HEADER_TQF_h_
#define RTW_HEADER_TQF_h_
#include <math.h>
#ifndef TQM_model_COMMON_INCLUDES_
# define TQM_model_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* TQM_model_COMMON_INCLUDES_ */

#include "TQM_model_types.h"

/* Child system includes */
#include "SubsysTQFRateSelection.h"
#include "SubsysTorqueFiltering.h"
#include "TQFRate_Determine.h"
#include "rt_sys_TQM_model_598.h"

extern void TQM_model_OverRide_e(uint8_T rtu_input, uint8_T *rty_Output, uint8_T
    rtp_Value, uint8_T rtp_Enable);
extern void TQM_mode_Get_TickDiff_ms_a_Init(void);
extern void TQM_model_Get_TickDiff_ms_b(void);
extern void TQM_model_TQF_Init(void);
extern void TQM_model_TQF_Start(void);
extern void TQM_model_TQF(void);

#endif                                 /* RTW_HEADER_TQF_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

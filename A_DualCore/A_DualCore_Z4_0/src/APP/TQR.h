/*
 * File: TQR.h
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

#ifndef RTW_HEADER_TQR_h_
#define RTW_HEADER_TQR_h_
#include <math.h>
#ifndef TQM_model_COMMON_INCLUDES_
# define TQM_model_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* TQM_model_COMMON_INCLUDES_ */

#include "TQM_model_types.h"

/* Child system includes */
#include "MCU_WorkMode_Control.h"
#include "PowerLim_To_TqLim.h"
#include "TorquePercent_LimitProcess.h"
#include "VehSpeed_LimitProcess.h"
#include "Vehicle_Torque_Arbitration.h"

extern void TQM_mode_Get_TickDiff_ms_l_Init(void);
extern void TQM_model_Get_TickDiff_ms_p(void);
extern void TQM_model_Torque_LimitProcess(void);
extern void TQM_model_TQR_Init(void);
extern void TQM_model_TQR(void);

#endif                                 /* RTW_HEADER_TQR_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

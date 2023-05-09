/*
 * File: TorquePercent_LimitProcess.h
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

#ifndef RTW_HEADER_TorquePercent_LimitProcess_h_
#define RTW_HEADER_TorquePercent_LimitProcess_h_
#ifndef TQM_model_COMMON_INCLUDES_
# define TQM_model_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* TQM_model_COMMON_INCLUDES_ */

#include "TQM_model_types.h"

/* Block signals and states (auto storage) for system '<S593>/IA_Filter_module1' */
typedef struct
{
    int32_T UnitDelay_DSTATE;          /* '<S598>/Unit Delay' */
}
rtDW_IA_Filter_module_TQM_m_f_T;

extern void TQM_model_IA_Filter_module1(uint32_T rtu_Signal_in, uint32_T
    rtu_Filter_dT, int32_T *rty_Signal_out, rtDW_IA_Filter_module_TQM_m_f_T
    *localDW, uint16_T rtp_Filter_T);
extern void TQM__TorquePercent_LimitProcess(void);

#endif                                 /* RTW_HEADER_TorquePercent_LimitProcess_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

/*
 * File: TQFRate_Determine.h
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

#ifndef RTW_HEADER_TQFRate_Determine_h_
#define RTW_HEADER_TQFRate_Determine_h_
#ifndef TQM_model_COMMON_INCLUDES_
# define TQM_model_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* TQM_model_COMMON_INCLUDES_ */

#include "TQM_model_types.h"

extern void TQM_model_LowRegen_Mode(int16_T rtu_VTQF_DmdTqFilOld_Nm_abs, int16_T
    rtu_VehTq_Differ_abs, uint8_T *rty_u1_M_TQF_LowRegenModDriveTq, uint8_T
    *rty_u1_M_TQF_LowRegenModDrive_h, uint8_T *rty_u1_M_TQF_LowRegenModRegenTq,
    uint8_T *rty_u1_M_TQF_LowRegenModRegen_m);
extern void TQM_model_HighRegen_Mode(int16_T rtu_VTQF_DmdTqFilOld_Nm_abs,
    int16_T rtu_VehTq_Differ_abs, uint8_T *rty_u1_M_TQF_HighRegenModDriveT,
    uint8_T *rty_u1_M_TQF_HighRegenModDriv_m, uint8_T
    *rty_u1_M_TQF_HighRegenModRegenT, uint8_T *rty_u1_M_TQF_HighRegenModRege_a);
extern void TQM_mod_TQFRate_Determine_Start(void);
extern void TQM_model_TQFRate_Determine(void);

#endif                                 /* RTW_HEADER_TQFRate_Determine_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

/*
 * File: ENM_Battery.h
 *
 * Code generated for Simulink model 'ENM_model'.
 *
 * Model version                  : 1.1958
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Fri Mar 18 15:39:06 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Freescale->32-bit PowerPC
 * Code generation objective: Execution efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_ENM_Battery_h_
#define RTW_HEADER_ENM_Battery_h_
#include <math.h>
#ifndef ENM_model_COMMON_INCLUDES_
# define ENM_model_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* ENM_model_COMMON_INCLUDES_ */

#include "ENM_model_types.h"

/* Child system includes */
#include "ENM_lib.h"

/* Block signals for system '<S11>/100ms_trigger' */
typedef struct
{
    boolean_T Compare;                 /* '<S15>/Compare' */
}
rtB_u00ms_trigger_ENM_model_T;

/* Block states (auto storage) for system '<S11>/100ms_trigger' */
typedef struct
{
    uint32_T Delay2_DSTATE;            /* '<S13>/Delay2' */
    uint32_T Delay3_DSTATE;            /* '<S13>/Delay3' */
    uint8_T icLoad;                    /* '<S13>/Delay2' */
}
rtDW_u00ms_trigger_ENM_model_T;

extern void ENM_model_u00ms_trigger_Init(rtDW_u00ms_trigger_ENM_model_T *localDW);
extern void ENM_model_u00ms_trigger(rtB_u00ms_trigger_ENM_model_T *localB,
    rtDW_u00ms_trigger_ENM_model_T *localDW, uint32_T rtp_trigger_timer_ms);
extern void ENM_mod_BMSMaxDchaPwrCheck_Init(void);
extern void ENM_model_BMSMaxDchaPwrCheck(void);
extern void ENM_model_SOCJumpProcess_Init(void);
extern void ENM_model_SOCJumpProcess(void);
extern void ENM_model_SOCLimitProcess(void);
extern void ENM_model_SOCSmooth_Init(void);
extern void ENM_model_SOCSmooth(void);
extern void ENM_model_SOC_Canvas(void);
extern void ENM_mo_NewInflexionProcess_Init(void);
extern void ENM__NewInflexionProcess_Update(void);
extern void ENM_model_NewInflexionProcess(void);
extern void ENM_m_SOC_InflexionProcess_Init(void);
extern void ENM_model_SOC_InflexionProcess(void);
extern void ENM_model_SocSmoothProcess_Init(void);
extern void ENM_model_SocSmoothProcess(void);
extern void ENM_model_SysSoc_Get_Init(void);
extern void ENM_model_SysSoc_Get(void);
extern void ENM_model_SysSOC_Process_Init(void);
extern void ENM_model_SysSOC_Process(void);
extern void ENM_model_SocInitJudge(void);
extern void ENM_model_ENM_Battery_Init(void);
extern void ENM_model_ENM_Battery(void);

#endif                                 /* RTW_HEADER_ENM_Battery_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

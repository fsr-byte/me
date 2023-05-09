/*
 * File: ENM_EnergyConsumptionStatistics.h
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

#ifndef RTW_HEADER_ENM_EnergyConsumptionStatistics_h_
#define RTW_HEADER_ENM_EnergyConsumptionStatistics_h_
#include <string.h>
#include <math.h>
#ifndef ENM_model_COMMON_INCLUDES_
# define ENM_model_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* ENM_model_COMMON_INCLUDES_ */

#include "ENM_model_types.h"

/* Child system includes */
#include "ENM_lib.h"
#include "rtsplntypes.h"
#include "rt_nonfinite.h"

extern void ENM_model_AirControlSysProcess(void);
extern void ENM_m_InstantConsumptionProcess(void);
extern void ENM_model_RR_PwrCalProcess(void);
extern void ENM_model_InsCnseProcess_Init(void);
extern void ENM_model_InsCnseProcess(void);
extern void ENM_model_TotolEgyCnseProcess(void);
extern void ENM_model_VCUVehEgyCnseDrvSys(void);
extern void ENM_mod_EgyEnseCalculation_Init(void);
extern void ENM_model_EgyEnseCalculation(void);
extern void ENM_model_AveFading_Init(void);
extern void ENM_model_AveFading(void);
extern void ENM_mode_BattResiPwr_wh_Process(void);
extern void ENM_model_BoundaryDispProcess(void);
extern void ENM_SOCDownMilgForcProcess_Init(void);
extern void E_SOCDownMilgForcProcess_Update(void);
extern void ENM_mode_SOCDownMilgForcProcess(void);
extern void ENM_m_SOCUpMilgForcProcess_Init(void);
extern void ENM_SOCUpMilgForcProcess_Update(void);
extern void ENM_model_SOCUpMilgForcProcess(void);
extern void ENM_mo_chrgforecastMilg_Process(void);
extern void ENM_model_Charge_Range_Init(void);
extern void ENM_model_Charge_Range(void);
extern void ENM_mod_CurveTrendRestrain_Init(void);
extern void ENM_model_CurveTrendRestrain(void);
extern void ENM_model_Filting_Init(void);
extern void ENM_model_Filting(void);
extern void ENM_model_Get_TickDiff_s_Init(void);
extern void ENM_model_Get_TickDiff_s(void);
extern void ENM_model_JumpAllow_Judge_Init(void);
extern void ENM_model_JumpAllow_Judge(void);
extern void ENM_mode_RR_SOCRemapCheck_Start(void);
extern void ENM_model_RR_SOCRemapCheck(void);
extern void ENM_mo_MilgCanvasRestrain_Start(void);
extern void ENM_model_MilgCanvasRestrain(void);
extern void ENM_mode_RangeChangeFilter_Init(void);
extern void ENM_model_RangeChangeFilter(void);
extern void ENM_model_ave_whpkm_limit(void);
extern void EN_ResimilgForcast_Process_Init(void);
extern void E_ResimilgForcast_Process_Start(void);
extern void ENM_mod_ResimilgForcast_Process(void);
extern void ENM__ResimilgRecord_Update_Init(void);
extern void ENM_model_ResimilgRecord_Update(void);
extern void ENM_model_ResimilgForcast_Init(void);
extern void ENM_model_ResimilgForcast_Start(void);
extern void ENM_model_ResimilgForcast(void);
extern void ENM_model_HVPwrCnsExt(void);
extern void ENM_model_CoolingSysPwrCal_Init(void);
extern void ENM_model_CoolingSysPwrCal(void);
extern void ENM_EnergyConsumptionStati_Init(void);
extern void ENM_EnergyConsumptionStat_Start(void);
extern void ENM_EnergyConsumptionStatistics(void);

#endif                                 /* RTW_HEADER_ENM_EnergyConsumptionStatistics_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

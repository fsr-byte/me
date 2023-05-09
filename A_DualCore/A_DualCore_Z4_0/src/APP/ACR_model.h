/*
 * File: ACR_model.h
 *
 * Code generated for Simulink model 'ACR_model'.
 *
 * Model version                  : 1.1784
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Fri Mar 18 15:46:44 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Freescale->32-bit PowerPC
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. MISRA C:2012 guidelines
 * Validation result: Not run
 */

#ifndef RTW_HEADER_ACR_model_h_
#define RTW_HEADER_ACR_model_h_
#include <stddef.h>
#ifndef ACR_model_COMMON_INCLUDES_
# define ACR_model_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* ACR_model_COMMON_INCLUDES_ */

#include "ACR_model_types.h"

/* Child system includes */
#include "ACR.h"

/* Includes for objects with custom storage classes. */
#include "ACR_Cal_Data.h"

/* Macros for accessing real-time model data structure */

/* user code (top of header file) */
#include "derivative.h"

/* Block signals and states (auto storage) for system '<Root>' */
typedef struct
{
    rtDW_Hysteresis_RightTrue_ACR_T Hysteresis_RightTrue;/* '<S14>/Hysteresis_RightTrue' */
    rtDW_Hysteresis_LeftTrue_ACR__T Hysteresis_LeftTrue;/* '<S14>/Hysteresis_LeftTrue' */
    real32_T Delay;                    /* '<S5>/Delay' */
    real32_T Delay_DSTATE;             /* '<S5>/Delay' */
    real32_T Delay_DSTATE_f;           /* '<S23>/Delay' */
    real32_T Delay_DSTATE_d;           /* '<S25>/Delay' */
    int8_T UnitDelay4_DSTATE;          /* '<S29>/Unit Delay4' */
    int8_T UnitDelay_DSTATE;           /* '<S30>/Unit Delay' */
    int8_T UnitDelay4_DSTATE_m;        /* '<S24>/Unit Delay4' */
    boolean_T UnitDelay1_DSTATE_j;     /* '<S6>/Unit Delay1' */
}
D_Work_ACR_model_T;

/* Constant parameters (auto storage) */
typedef struct
{
    /* Pooled Parameter (Expression: )
     * Referenced by:
     *   '<S10>/GearD_DemAcl_Map'
     *   '<S10>/GearR_DemAcl_Map'
     */
    uint32_T pooled2[2];
}
ConstParam_ACR_model_T;

/* Block signals and states (auto storage) */
#pragma push
#pragma DATA_SEG __GPAGE_SEG GPAGED_RAM

extern D_Work_ACR_model_T ACR_model_DWork;

#pragma pop

/* Constant parameters (auto storage) */

#pragma push
#pragma DATA_SEG __GPAGE_SEG GPAGED_RAM

extern const ConstParam_ACR_model_T ACR_model_ConstP;

#pragma pop

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern ACR ACR_output;                 /* '<S3>/Bus Creator' */
extern real32_T f4_M_ALC_AclCtr_TargetTorque_Nm;/* '<S6>/Merge'
                                                 * 加速度环目标扭矩
                                                 */
extern real32_T f4_M_ALC_DemAcl_mpss;  /* '<S10>/Switch1'
                                        * 目标加速度
                                        */
extern real32_T f4_M_ALC_AclCtr_AclDiff_mpss;/* '<S13>/Add'
                                              * 目标加速度与实际加速度差值
                                              */
extern real32_T f4_M_ALC_AclDiff_Ki;   /* '<S13>/AccelerationControl_Ki_Map'
                                        * Ki参数
                                        */
extern real32_T f4_M_ALC_AclDiff_Kp;   /* '<S13>/AccelerationControl_Kp_Map'
                                        * Kp参数
                                        */
extern real32_T f4_M_ALC_AclCtr_PTorque_Nm;/* '<S31>/Product3'
                                            * 加速度环P环节数值
                                            */
extern real32_T f4_M_ALC_AclCtr_DTorque_Nm;/* '<S27>/Product2'
                                            * 加速度环D环节数值
                                            */
extern real32_T f4_M_ALC_AclCtr_ITorque_Nm;/* '<S30>/Switch5'
                                            * 加速度环I环节数值
                                            */
extern int8_T s1_M_ALC_AclCtr_Pid_IntegralSts;/* '<S24>/Switch1'
                                               * 加速度环PID积分环节状态(-1:积分值达到下限；0：积分值正常；1：积分值达到上限)
                                               */
extern int8_T s1_M_ALC_AclCtr_Pid_PIDSts;/* '<S24>/Switch2'
                                          * 加速度环PID状态(-1:PID达到下限；0：PID正常；1：PID达到上限)
                                          */
extern boolean_T b1_M_ALC_PowerLimFlg; /* '<S7>/Logical Operator'
                                        * 系统限功率标识
                                        */
extern boolean_T b1_M_ALC_AclCtr_PIDEnaFlg;/* '<S14>/Logical Operator2'
                                            * 加速度环PID使能标识
                                            */
extern boolean_T b1_M_ALC_AclCtr_PID_IntHold;/* '<S15>/Logical Operator2'
                                              * 加速度环PID积分停止标识
                                              */
extern boolean_T b1_M_ALC_AclCtr_PID_IntReset;/* '<S16>/Logical Operator1'
                                               * 加速度环PID积分复位标识
                                               */

/* Model entry point functions */
extern void ACR_model_initialize(void);
extern void ACR_model_step(void);
extern void ACR_model_terminate(void);

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'ACR_model'
 * '<S1>'   : 'ACR_model/ACR'
 * '<S2>'   : 'ACR_model/ACR/AccelerationLoopControl'
 * '<S3>'   : 'ACR_model/ACR/AccelerationRequest'
 * '<S4>'   : 'ACR_model/ACR/Get_TickDiff_ms'
 * '<S5>'   : 'ACR_model/ACR/AccelerationLoopControl/ALC'
 * '<S6>'   : 'ACR_model/ACR/AccelerationLoopControl/ALC/AcceleratedTrqControl'
 * '<S7>'   : 'ACR_model/ACR/AccelerationLoopControl/ALC/SystemLimitControl'
 * '<S8>'   : 'ACR_model/ACR/AccelerationLoopControl/ALC/AcceleratedTrqControl/AccPedalNonRun'
 * '<S9>'   : 'ACR_model/ACR/AccelerationLoopControl/ALC/AcceleratedTrqControl/AccPedalRun'
 * '<S10>'  : 'ACR_model/ACR/AccelerationLoopControl/ALC/AcceleratedTrqControl/AccPedalRun/DemandAcceleration'
 * '<S11>'  : 'ACR_model/ACR/AccelerationLoopControl/ALC/AcceleratedTrqControl/AccPedalRun/DemandTorque'
 * '<S12>'  : 'ACR_model/ACR/AccelerationLoopControl/ALC/AcceleratedTrqControl/AccPedalRun/DemandTorque/BaseTorque'
 * '<S13>'  : 'ACR_model/ACR/AccelerationLoopControl/ALC/AcceleratedTrqControl/AccPedalRun/DemandTorque/PID_Diff_Kp_Ki'
 * '<S14>'  : 'ACR_model/ACR/AccelerationLoopControl/ALC/AcceleratedTrqControl/AccPedalRun/DemandTorque/PID_Ena'
 * '<S15>'  : 'ACR_model/ACR/AccelerationLoopControl/ALC/AcceleratedTrqControl/AccPedalRun/DemandTorque/PID_IntHold'
 * '<S16>'  : 'ACR_model/ACR/AccelerationLoopControl/ALC/AcceleratedTrqControl/AccPedalRun/DemandTorque/PID_IntReset'
 * '<S17>'  : 'ACR_model/ACR/AccelerationLoopControl/ALC/AcceleratedTrqControl/AccPedalRun/DemandTorque/RodeSlopManage'
 * '<S18>'  : 'ACR_model/ACR/AccelerationLoopControl/ALC/AcceleratedTrqControl/AccPedalRun/DemandTorque/SpdCon_TorqueController(PIDIC)'
 * '<S19>'  : 'ACR_model/ACR/AccelerationLoopControl/ALC/AcceleratedTrqControl/AccPedalRun/DemandTorque/PID_Ena/Hysteresis_LeftTrue'
 * '<S20>'  : 'ACR_model/ACR/AccelerationLoopControl/ALC/AcceleratedTrqControl/AccPedalRun/DemandTorque/PID_Ena/Hysteresis_RightTrue'
 * '<S21>'  : 'ACR_model/ACR/AccelerationLoopControl/ALC/AcceleratedTrqControl/AccPedalRun/DemandTorque/PID_IntReset/Compare To Zero'
 * '<S22>'  : 'ACR_model/ACR/AccelerationLoopControl/ALC/AcceleratedTrqControl/AccPedalRun/DemandTorque/RodeSlopManage/Compare To Constant'
 * '<S23>'  : 'ACR_model/ACR/AccelerationLoopControl/ALC/AcceleratedTrqControl/AccPedalRun/DemandTorque/SpdCon_TorqueController(PIDIC)/FirstOrderFilter'
 * '<S24>'  : 'ACR_model/ACR/AccelerationLoopControl/ALC/AcceleratedTrqControl/AccPedalRun/DemandTorque/SpdCon_TorqueController(PIDIC)/PIDICController'
 * '<S25>'  : 'ACR_model/ACR/AccelerationLoopControl/ALC/AcceleratedTrqControl/AccPedalRun/DemandTorque/SpdCon_TorqueController(PIDIC)/TorqueGradientLimit'
 * '<S26>'  : 'ACR_model/ACR/AccelerationLoopControl/ALC/AcceleratedTrqControl/AccPedalRun/DemandTorque/SpdCon_TorqueController(PIDIC)/VehicleLongitudinalDynamic'
 * '<S27>'  : 'ACR_model/ACR/AccelerationLoopControl/ALC/AcceleratedTrqControl/AccPedalRun/DemandTorque/SpdCon_TorqueController(PIDIC)/PIDICController/DGain'
 * '<S28>'  : 'ACR_model/ACR/AccelerationLoopControl/ALC/AcceleratedTrqControl/AccPedalRun/DemandTorque/SpdCon_TorqueController(PIDIC)/PIDICController/IGain'
 * '<S29>'  : 'ACR_model/ACR/AccelerationLoopControl/ALC/AcceleratedTrqControl/AccPedalRun/DemandTorque/SpdCon_TorqueController(PIDIC)/PIDICController/IntegralClamping_AntiWindup'
 * '<S30>'  : 'ACR_model/ACR/AccelerationLoopControl/ALC/AcceleratedTrqControl/AccPedalRun/DemandTorque/SpdCon_TorqueController(PIDIC)/PIDICController/Integrator'
 * '<S31>'  : 'ACR_model/ACR/AccelerationLoopControl/ALC/AcceleratedTrqControl/AccPedalRun/DemandTorque/SpdCon_TorqueController(PIDIC)/PIDICController/PGain'
 * '<S32>'  : 'ACR_model/ACR/AccelerationLoopControl/ALC/AcceleratedTrqControl/AccPedalRun/DemandTorque/SpdCon_TorqueController(PIDIC)/PIDICController/PID_Sum'
 * '<S33>'  : 'ACR_model/ACR/AccelerationLoopControl/ALC/AcceleratedTrqControl/AccPedalRun/DemandTorque/SpdCon_TorqueController(PIDIC)/PIDICController/Integrator/Subsystem2'
 * '<S34>'  : 'ACR_model/ACR/AccelerationLoopControl/ALC/AcceleratedTrqControl/AccPedalRun/DemandTorque/SpdCon_TorqueController(PIDIC)/PIDICController/PID_Sum/Subsystem1'
 * '<S35>'  : 'ACR_model/ACR/AccelerationLoopControl/ALC/AcceleratedTrqControl/AccPedalRun/DemandTorque/SpdCon_TorqueController(PIDIC)/TorqueGradientLimit/Saturation Dynamic'
 * '<S36>'  : 'ACR_model/ACR/AccelerationLoopControl/ALC/AcceleratedTrqControl/AccPedalRun/DemandTorque/SpdCon_TorqueController(PIDIC)/TorqueGradientLimit/Subsystem1'
 * '<S37>'  : 'ACR_model/ACR/AccelerationLoopControl/ALC/AcceleratedTrqControl/AccPedalRun/DemandTorque/SpdCon_TorqueController(PIDIC)/VehicleLongitudinalDynamic/Saturation Dynamic'
 */

/*-
 * Requirements for '<Root>': ACR_model
 */
#endif                                 /* RTW_HEADER_ACR_model_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

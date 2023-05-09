/*
 * File: DHP_Sub_HardwireSignal_Filter.c
 *
 * Code generated for Simulink model 'DHP_model'.
 *
 * Model version                  : 1.5367
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Fri Mar 18 15:33:37 2022
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

#include "DHP_Sub_HardwireSignal_Filter.h"

/* Include model header file for global data */
#include "DHP_model.h"
#include "DHP_model_private.h"

/* Output and update for atomic system: '<S2>/DHP_Sub_HardwireSignal_Filter' */
void DHP_model_DHP_Sub_HardwireSignal_Filter(void)
{
  /* DataTypeConversion: '<S2244>/Data Type Conversion' incorporates:
   *  Inport: '<Root>/HALI'
   */
  VDSF_CollisionFreIn_Hz = HALI_output.Hardwire_Inputs.VHALI_Collisionfre_Hz;

  /* DataTypeConversion: '<S2244>/Data Type Conversion1' incorporates:
   *  Inport: '<Root>/HALI'
   */
  VDSF_CollisionDutyIn_pct = HALI_output.Hardwire_Inputs.VHALI_CollisionDuty_pct;

  /* DataTypeConversion: '<S2244>/Data Type Conversion12' incorporates:
   *  Inport: '<Root>/HALI'
   */
  VDSF_HVInterlockFreIn_Hz =
    HALI_output.Hardwire_Inputs.VHALI_HVInterlockFreIn_Hz;

  /* DataTypeConversion: '<S2244>/Data Type Conversion2' incorporates:
   *  Inport: '<Root>/HALI'
   */
  VDSF_BrkSwitch1 = HALI_output.Hardwire_Inputs.VHALI_BrkLightSwitch1Active_flg;

  /* DataTypeConversion: '<S2244>/Data Type Conversion3' incorporates:
   *  Inport: '<Root>/HALI'
   */
  VDSF_BrkSwitch2 = HALI_output.Hardwire_Inputs.VHALI_BrkLightSwitch2Active_flg;

  /* DataTypeConversion: '<S2244>/Data Type Conversion7' incorporates:
   *  Inport: '<Root>/HALI'
   */
  VDSF_AccelPedalL_V = HALI_output.Hardwire_Inputs.VHALI_AccelPedalL_V;

  /* DataTypeConversion: '<S2244>/Data Type Conversion8' incorporates:
   *  Inport: '<Root>/HALI'
   */
  VDSF_AccelPedalH_V = HALI_output.Hardwire_Inputs.VHALI_AccelPedalH_V;

  /* DataTypeConversion: '<S2245>/Data Type Conversion' incorporates:
   *  Inport: '<Root>/HALI'
   */
  VDSF_GearSwitch1Active_flg =
    HALI_output.Hardwire_Inputs.VHALI_GearSwitch1Active_flg;

  /* DataTypeConversion: '<S2246>/Data Type Conversion' incorporates:
   *  Inport: '<Root>/HALI'
   */
  VDSF_GearSwitch2Active_flg =
    HALI_output.Hardwire_Inputs.VHALI_GearSwitch2Active_flg;

  /* DataTypeConversion: '<S2247>/Data Type Conversion' incorporates:
   *  Inport: '<Root>/HALI'
   */
  VDSF_GearSwitch3Active_flg =
    HALI_output.Hardwire_Inputs.VHALI_GearSwitch3Active_flg;

  /* DataTypeConversion: '<S2248>/Data Type Conversion' incorporates:
   *  Inport: '<Root>/HALI'
   */
  VDSF_GearSwitch4Active_flg =
    HALI_output.Hardwire_Inputs.VHALI_GearSwitch4Active_flg;

  /* SignalConversion: '<S2244>/TmpSignal ConversionAtData Type Conversion10Inport1' incorporates:
   *  Inport: '<Root>/HALI'
   */
  DHP_model_B.VHALI_Sensor5V1_V = HALI_output.Hardwire_Inputs.VHALI_Sensor5V1_V;

  /* SignalConversion: '<S2244>/TmpSignal ConversionAtData Type Conversion11Inport1' incorporates:
   *  Inport: '<Root>/HALI'
   */
  DHP_model_B.VHALI_LVBattVoltage_V =
    HALI_output.Hardwire_Inputs.VHALI_LVBattVoltage_V;

  /* SignalConversion: '<S2244>/TmpSignal ConversionAtData Type Conversion4Inport1' incorporates:
   *  Inport: '<Root>/HALI'
   */
  DHP_model_B.VHALI_Sensor5V2_V = HALI_output.Hardwire_Inputs.VHALI_Sensor5V2_V;

  /* DataTypeConversion: '<S2249>/Data Type Conversion' incorporates:
   *  Inport: '<Root>/HALI'
   */
  VDSF_VacuumPumpIn_Hz = HALI_output.Hardwire_Inputs.VHALI_VacuumPumpIn_Hz;

  /* DataTypeConversion: '<S2250>/Data Type Conversion' incorporates:
   *  Inport: '<Root>/HALI'
   */
  VDSF_WaterPwmIn_Duty = HALI_output.Hardwire_Inputs.VHALI_WaterPwmIn_Duty;

  /* DataTypeConversion: '<S2251>/Data Type Conversion' incorporates:
   *  Inport: '<Root>/HALI'
   */
  VDSF_WaterPwmIn_Hz = (uint8_T)HALI_output.Hardwire_Inputs.VHALI_WaterPwmIn_Hz;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

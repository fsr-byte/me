/*
 * File: HALI_model.h
 *
 * Code generated for Simulink model 'HALI_model'.
 *
 * Model version                  : 1.816
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Fri Mar 18 15:39:52 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Freescale->32-bit PowerPC
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_HALI_model_h_
#define RTW_HEADER_HALI_model_h_
#include <string.h>
#include <stddef.h>
#ifndef HALI_model_COMMON_INCLUDES_
# define HALI_model_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* HALI_model_COMMON_INCLUDES_ */

#include "HALI_model_types.h"

/* Child system includes */
#include "Funcs_HALI_lib.h"

/* Includes for objects with custom storage classes. */
#include "HAL_Cal_Data.h"

/* Macros for accessing real-time model data structure */

/* user code (top of header file) */
#include "derivative.h"

/* Block signals (auto storage) */
typedef struct {
  B_Signal_inverter_HALI_model_T Signal_inverter9;/* '<S2>/Signal_inverter9' */
  B_Signal_inverter_HALI_model_T Signal_inverter8;/* '<S2>/Signal_inverter8' */
  B_Signal_inverter_HALI_model_T Signal_inverter7;/* '<S2>/Signal_inverter7' */
  B_Signal_inverter_HALI_model_T Signal_inverter6;/* '<S2>/Signal_inverter6' */
  B_Signal_inverter_HALI_model_T Signal_inverter5;/* '<S2>/Signal_inverter5' */
  B_Signal_inverter_HALI_model_T Signal_inverter4;/* '<S2>/Signal_inverter4' */
  B_Signal_inverter_HALI_model_T Signal_inverter3;/* '<S2>/Signal_inverter3' */
  B_Signal_inverter_HALI_model_T Signal_inverter2;/* '<S2>/Signal_inverter2' */
  B_Signal_inverter_HALI_model_T Signal_inverter12;/* '<S2>/Signal_inverter12' */
  B_Signal_inverter_HALI_model_T Signal_inverter11;/* '<S2>/Signal_inverter11' */
  B_Signal_inverter_HALI_model_T Signal_inverter10;/* '<S2>/Signal_inverter10' */
  B_Signal_inverter_HALI_model_T Signal_inverter1;/* '<S2>/Signal_inverter1' */
  B_Signal_inverter_HALI_model_T Signal_inverter;/* '<S2>/Signal_inverter' */
} B_HALI_model_T;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  uint8_T UdsAppSWVer_o[12];           /* '<Root>/UdsAppSWVer' */
  uint8_T UdsHWVer_o[12];              /* '<Root>/UdsHWVer' */
  uint8_T UdsPartNumber_a[21];         /* '<Root>/UdsPartNumber' */
  uint8_T UdsCalSWVer_i[8];            /* '<Root>/UdsCalSWVer' */
  uint8_T NotUsed1;                    /* '<Root>/NotUsed1' */
  uint8_T NotUsed2;                    /* '<Root>/NotUsed2' */
  uint8_T NotUsed3;                    /* '<Root>/NotUsed3' */
  uint8_T NotUsed4;                    /* '<Root>/NotUsed4' */
  uint16_T NotUsed5;                   /* '<Root>/NotUsed5' */
  uint16_T NotUsed6;                   /* '<Root>/NotUsed6' */
  uint8_T NotUsed7;                    /* '<Root>/NotUsed7' */
  uint32_T NotUsed8;                   /* '<Root>/NotUsed8' */
  uint8_T NotUsed9;                    /* '<Root>/NotUsed9' */
  uint8_T NotUsed10;                   /* '<Root>/NotUsed10' */
  uint8_T NotUsed11;                   /* '<Root>/NotUsed11' */
  uint16_T NotUsed24;                  /* '<Root>/NotUsed24' */
  uint16_T NotUsed25;                  /* '<Root>/NotUsed25' */
  uint16_T NotUsed26;                  /* '<Root>/NotUsed26' */
  uint16_T NotUsed27;                  /* '<Root>/NotUsed27' */
  uint16_T NotUsed28;                  /* '<Root>/NotUsed28' */
  uint16_T NotUsed29;                  /* '<Root>/NotUsed29' */
  uint16_T NotUsed30;                  /* '<Root>/NotUsed30' */
  uint16_T NotUsed31;                  /* '<Root>/NotUsed31' */
  uint32_T NotUsed32;                  /* '<Root>/NotUsed32' */
  uint16_T NotUsed33;                  /* '<Root>/NotUsed33' */
  uint8_T NotUsed34;                   /* '<Root>/NotUsed34' */
} ExtY_HALI_model_T;

/* Block signals (auto storage) */
#pragma push
#pragma DATA_SEG __GPAGE_SEG GPAGED_RAM

extern B_HALI_model_T HALI_model_B;

#pragma pop

/* External outputs (root outports fed by signals with auto storage) */

#pragma push
#pragma DATA_SEG __GPAGE_SEG GPAGED_RAM

extern ExtY_HALI_model_T HALI_model_Y;

#pragma pop

/* External data declarations for dependent source files */
#pragma push
#pragma DATA_SEG __GPAGE_SEG GPAGED_RAM

extern const HALI HALI_model_rtZHALI;  /* HALI ground */

#pragma pop

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern HALI HALI_output;               /* '<S1>/Bus Creator' */

/* Model entry point functions */
extern void HALI_model_initialize(void);
extern void HALI_model_step(void);
extern void HALI_model_terminate(void);

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
 * '<Root>' : 'HALI_model'
 * '<S1>'   : 'HALI_model/HALI'
 * '<S2>'   : 'HALI_model/HALI/Sub_Hardwire'
 * '<S3>'   : 'HALI_model/HALI/Subsystem'
 * '<S4>'   : 'HALI_model/HALI/Sub_Hardwire/FastChargeTemp_UnitConvert1'
 * '<S5>'   : 'HALI_model/HALI/Sub_Hardwire/FastChargeTemp_UnitConvert3'
 * '<S6>'   : 'HALI_model/HALI/Sub_Hardwire/PCBTemp_UnitConvert'
 * '<S7>'   : 'HALI_model/HALI/Sub_Hardwire/Signal_inverter'
 * '<S8>'   : 'HALI_model/HALI/Sub_Hardwire/Signal_inverter1'
 * '<S9>'   : 'HALI_model/HALI/Sub_Hardwire/Signal_inverter10'
 * '<S10>'  : 'HALI_model/HALI/Sub_Hardwire/Signal_inverter11'
 * '<S11>'  : 'HALI_model/HALI/Sub_Hardwire/Signal_inverter12'
 * '<S12>'  : 'HALI_model/HALI/Sub_Hardwire/Signal_inverter2'
 * '<S13>'  : 'HALI_model/HALI/Sub_Hardwire/Signal_inverter3'
 * '<S14>'  : 'HALI_model/HALI/Sub_Hardwire/Signal_inverter4'
 * '<S15>'  : 'HALI_model/HALI/Sub_Hardwire/Signal_inverter5'
 * '<S16>'  : 'HALI_model/HALI/Sub_Hardwire/Signal_inverter6'
 * '<S17>'  : 'HALI_model/HALI/Sub_Hardwire/Signal_inverter7'
 * '<S18>'  : 'HALI_model/HALI/Sub_Hardwire/Signal_inverter8'
 * '<S19>'  : 'HALI_model/HALI/Sub_Hardwire/Signal_inverter9'
 * '<S20>'  : 'HALI_model/HALI/Sub_Hardwire/VacuumPump_UnitConvert'
 * '<S21>'  : 'HALI_model/HALI/Sub_Hardwire/FastChargeTemp_UnitConvert1/Compare To Constant'
 * '<S22>'  : 'HALI_model/HALI/Sub_Hardwire/FastChargeTemp_UnitConvert1/Compare To Constant1'
 * '<S23>'  : 'HALI_model/HALI/Sub_Hardwire/FastChargeTemp_UnitConvert1/V2R'
 * '<S24>'  : 'HALI_model/HALI/Sub_Hardwire/FastChargeTemp_UnitConvert1/V2R/Compare To Constant'
 * '<S25>'  : 'HALI_model/HALI/Sub_Hardwire/FastChargeTemp_UnitConvert1/V2R/Compare To Constant1'
 * '<S26>'  : 'HALI_model/HALI/Sub_Hardwire/FastChargeTemp_UnitConvert1/V2R/Compare To Constant2'
 * '<S27>'  : 'HALI_model/HALI/Sub_Hardwire/FastChargeTemp_UnitConvert3/Compare To Constant'
 * '<S28>'  : 'HALI_model/HALI/Sub_Hardwire/FastChargeTemp_UnitConvert3/Compare To Constant1'
 * '<S29>'  : 'HALI_model/HALI/Sub_Hardwire/FastChargeTemp_UnitConvert3/V2R'
 * '<S30>'  : 'HALI_model/HALI/Sub_Hardwire/FastChargeTemp_UnitConvert3/V2R/Compare To Constant'
 * '<S31>'  : 'HALI_model/HALI/Sub_Hardwire/FastChargeTemp_UnitConvert3/V2R/Compare To Constant1'
 * '<S32>'  : 'HALI_model/HALI/Sub_Hardwire/FastChargeTemp_UnitConvert3/V2R/Compare To Constant2'
 */
#endif                                 /* RTW_HEADER_HALI_model_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

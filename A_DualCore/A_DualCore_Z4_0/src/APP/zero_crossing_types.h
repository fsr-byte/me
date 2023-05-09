/*
 * File: zero_crossing_types.h
 *
 * Code generated for Simulink model 'CHRG_Model'.
 *
 * Model version                  : 1.1917
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Fri Mar 18 15:31:54 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Freescale->32-bit PowerPC
 * Code generation objectives:
 *    1. RAM efficiency
 *    2. ROM efficiency
 *    3. Execution efficiency
 * Validation result: Not run
 */

#ifndef ZERO_CROSSING_TYPES_H
#define ZERO_CROSSING_TYPES_H
#include "rtwtypes.h"

/* Trigger directions: falling, either, and rising */
typedef enum
{
    FALLING_ZERO_CROSSING = -1,
    ANY_ZERO_CROSSING = 0,
    RISING_ZERO_CROSSING = 1
}

ZCDirection;

/* Previous state of a trigger signal */
typedef uint8_T ZCSigState;

/* Initial value of a trigger zero crossing signal */
#define UNINITIALIZED_ZCSIG            0x03U
#define NEG_ZCSIG                      0x02U
#define POS_ZCSIG                      0x01U
#define ZERO_ZCSIG                     0x00U

/* Current state of a trigger signal */
typedef enum
{
    FALLING_ZCEVENT = -1,
    NO_ZCEVENT = 0,
    RISING_ZCEVENT = 1
}

ZCEventType;

#endif                                 /* ZERO_CROSSING_TYPES_H */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

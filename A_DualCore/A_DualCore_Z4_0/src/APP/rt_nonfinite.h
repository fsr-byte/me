/*
 * File: rt_nonfinite.h
 *
 * Code generated for Simulink model 'DIM_model'.
 *
 * Model version                  : 1.2422
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Fri Mar 18 15:35:30 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Freescale->32-bit PowerPC
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_rt_nonfinite_h_
#define RTW_HEADER_rt_nonfinite_h_
#include <stddef.h>
#include "rtwtypes.h"

#pragma push
#pragma DATA_SEG __GPAGE_SEG GPAGED_RAM

extern real_T rtInf;

#pragma pop
#pragma push
#pragma DATA_SEG __GPAGE_SEG GPAGED_RAM

extern real_T rtMinusInf;

#pragma pop
#pragma push
#pragma DATA_SEG __GPAGE_SEG GPAGED_RAM

extern real_T rtNaN;

#pragma pop
#pragma push
#pragma DATA_SEG __GPAGE_SEG GPAGED_RAM

extern real32_T rtInfF;

#pragma pop
#pragma push
#pragma DATA_SEG __GPAGE_SEG GPAGED_RAM

extern real32_T rtMinusInfF;

#pragma pop
#pragma push
#pragma DATA_SEG __GPAGE_SEG GPAGED_RAM

extern real32_T rtNaNF;

#pragma pop

extern void rt_InitInfAndNaN(size_t realSize);
extern boolean_T rtIsInf(real_T value);
extern boolean_T rtIsInfF(real32_T value);
extern boolean_T rtIsNaN(real_T value);
extern boolean_T rtIsNaNF(real32_T value);
typedef struct {
  struct {
    uint32_T wordH;
    uint32_T wordL;
  } words;
} BigEndianIEEEDouble;

typedef struct {
  struct {
    uint32_T wordL;
    uint32_T wordH;
  } words;
} LittleEndianIEEEDouble;

typedef struct {
  union {
    real32_T wordLreal;
    uint32_T wordLuint;
  } wordL;
} IEEESingle;

#endif                                 /* RTW_HEADER_rt_nonfinite_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

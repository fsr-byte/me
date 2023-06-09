

/****************************************************************
 * WARNING this file is automatically generated DO NOT EDIT IT! *
 * *
 * FILE NAME: etpu_fpm_auto.h COPYRIGHT (c) Freescale 2004 *
 * All Rights Reserved *
 * This file generated by: *
 * $RCSfile: etpuc_fpm.c,v $ $Revision: 1.1.2.1 $
 * *
 * This file provides an interface between eTPU code and CPU *
 * code. All references to the FPM function should be made with *
 * information in this file. This allows only symbolic *
 * information to be referenced which allows the eTPU code to be*
 * optimized without effecting the CPU code. *
 ****************************************************************/
#ifndef _ETPU_FPM_AUTO_H
#define _ETPU_FPM_AUTO_H

/* Function Configuration Information */
#define FS_ETPU_FPM_FUNCTION_NUMBER 1
#define FS_ETPU_FPM_TABLE_SELECT 1
#define FS_ETPU_FPM_NUM_PARMS 0x20


/* Host Service Request Definitions */
#define FS_ETPU_FPM_INIT 7
#define FS_ETPU_FPM_UPDATE 3

/* Function Mode Bit Definitions - measurement options - mode options */
#define FS_ETPU_FPM_SINGLE_SHOT 0
#define FS_ETPU_FPM_CONTINUOUS 1
/* Function Mode Bit Definitions - measurement options - edge options */
#define FS_ETPU_FPM_RISING_EDGE 1
#define FS_ETPU_FPM_FALLING_EDGE 0

/* Parameter Definitions */
#define FS_ETPU_FPM_WINDOW_OFFSET 0x5
#define FS_ETPU_FPM_TIMEBASE_OFFSET 0x0
#define FS_ETPU_FPM_EDGE_COUNT_OFFSET 0x1
#define FS_ETPU_FPM_ELAPSED_TCR_COUNTS_OFFSET 0x9

#endif /*_ETPU_FPM_AUTO_H */ 

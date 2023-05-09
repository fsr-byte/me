#ifndef CCP_CFG_H_
#define CCP_CFG_H_



/* -----------------------------------------------------------------------------
    Includes
------------------------------------------------------------------------------*/
#include "Typedefs.h"
/* -----------------------------------------------------------------------------
    Global Macro Definitions
------------------------------------------------------------------------------*/
/*
    Development Error Detection (DET)
      ON  - DET enabled
      OFF - DET disabled
*/
#define CCP_DEV_ERROR_DETECT OFF

/*The CCP does not require this information but the BSW scheduler,
 * which invokes the main function, needs it in order to plan its tasks.
 * unit is ms. */
#define CCP_MAIN_FUNCTION_PERIOD 20u

/*MAX_DAQ indicates the number of DAQ lists on the CCP slave.*/
#define CCP_MAX_DAQ 2u

/*MAX_ODT indicates the maximum amount of ODTs of each DAQ list.*/
#define CCP_MAX_ODT 16u //change from 2 to 5

/*CCP_MAX_ODT_ENTRIES indicates the max number of entries inside one ODT*/
#define CCP_MAX_ODT_ENTRIES 7u

/*MAX_DTO shows the maximum length of a DTO packet in bytes.*/
#define CCP_MAX_DTO 8u

/**/
#define CCP_MAX_EVENT_CHANNEL 4u
#define CCP_EVENT_CHANNEL_5MS 0u
#define CCP_EVENT_CHANNEL_10MS 1u
#define CCP_EVENT_CHANNEL_25MS 2u

/*Indicates the number of predefined, read only DAQ lists on the CCP slave*/
#define CcpMinDaq 2u

/*Enables/disables the existence of the XCP_GetVersionInfo() API service.
 * ON: CCP_GetVersionInfo() API service exists
 * OFF: CCP_GetVersionInfo() API service does not exist*/
#define CCP_VERSION_INFO_API ON

/* CCP Identifiers and Address */
#define CCP_STATION_ADDR  0x3900      /* Define CCP_STATION_ADDR in Intel Format */
                                      /* High/Low byte swapped on motorola machines !!! (0x3900) */

///#define CCP_STATION_ID    "Ccptest"  /* Plug&Play station identification */

#define CCP_DTO_ID        0x200         /* CAN identifier ECU -> Master */
#define CCP_CRO_ID        0x100         /* CAN identifier Master -> ECU */
#define CCP_CRO_LENGTH 8u

#define CCP_SEED_KEY	OFF
#define CCP_PROGRAM		OFF
#define CCP_KERNEL_PROGRAM ON

#define CCP_CHECKSUM_TYPE CCP_DWORD

/* -----------------------------------------------------------------------------
    Function-like Macro Definition
------------------------------------------------------------------------------*/
/* -----------------------------------------------------------------------------
    Global Type Definitions
------------------------------------------------------------------------------*/

/* -----------------------------------------------------------------------------
    Global Constant Declarations
------------------------------------------------------------------------------*/

/* -----------------------------------------------------------------------------
    Global Variable Declarations
------------------------------------------------------------------------------*/

/* -----------------------------------------------------------------------------
    Global Function Declarations
------------------------------------------------------------------------------*/


/* -----------------------------------------------------------------------------
    Global Inline Function Definitions
------------------------------------------------------------------------------*/

#endif /* CCP_CFG_H_ */


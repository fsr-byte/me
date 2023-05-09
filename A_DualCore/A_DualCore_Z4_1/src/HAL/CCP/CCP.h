#ifndef CCP_H_
#define CCP_H_
/*
 *
 * Copyright (c) 2011 SIEMENS AG. All Rights Reserved.
 *
 * Copying of this document or code and giving it to others and the
 * use or communication of the contents thereof, are forbidden without
 * expressed authority. Offenders are liable to the payment of damages.
 * All rights reserved in the event of the grant of a invention patent or the
 * registration of a utility model, design or code.
 *
 * Issued by SIEMENS SLC I IA&DT EC SHA.
 *
 */

/*! @file Ccp.h
 @brief  brief description on this header file
 @details details description on this header file

 */

#ifdef  MASTER_CCP_
    #define CCP_EXTERNAL_
#else
    #define CCP_EXTERNAL_  extern
#endif

/* -----------------------------------------------------------------------------
 Includes
 ------------------------------------------------------------------------------*/
#include "Typedefs.h"

#include "Ccp_Cfg.h"
#define ON  1
#define OFF 0
/* -----------------------------------------------------------------------------
 Global Macro Definitions
 ------------------------------------------------------------------------------*/
 #define CCP_CRO_CAN_ID     0x100
 #define CCP_CRM_CAN_ID     0x200
/* Declare CCP-protocol version */
#define CCP_VERSION_MAJOR   0x02
#define CCP_VERSION_MINOR   0x01
/* Declare CCP SW version*/
#define CCP_VENDOR_ID	0x00
#define CCP_SW_MAJOR_VERSION	0x00
#define CCP_SW_MINOR_VERSION	0x00
#define CCP_SW_PATCH_VERSION	0x00
#define CCP_AR_MAJOR_VERSION	0x00
#define CCP_AR_MINOR_VERSION	0x00
#define CCP_AR_PATCH_VERSION	0x00

/*PID code*/
#define PID_CRM	0xFF
#define PID_Evt	0xFE

/*Memory transfer address*/
#define CCP_MAX_MTA 2

/* Returncodes */
#define CRC_OK                 0x00
#define CRC_NOK                0x01

/* C1 */
#define CRC_CMD_BUSY           0x10
#define CRC_DAQ_BUSY           0x11
#define CRC_KEY_REQUEST        0x18
#define CRC_STATUS_REQUEST     0x19

/* C2 */
#define CRC_COLD_START_REQUEST 0x20
#define CRC_CAL_INIT_REQUEST   0x21
#define CRC_DAQ_INIT_REQUEST   0x22
#define CRC_CODE_REQUEST       0x23

/* C3 (Errors) */
#define CRC_CMD_UNKNOWN        0x30
#define CRC_CMD_SYNTAX         0x31
#define CRC_OUT_OF_RANGE       0x32
#define CRC_ACCESS_DENIED      0x33
#define CRC_OVERLOAD           0x34
#define CRC_ACCESS_LOCKED      0x35


/* Broadcast Station Address */
#define CCP_BROADCAST_STATION_ADDR 0


#define MODULE_ID_CCP 55
#define CCP_INSTANCE_ID 0


/* DAQ list */
#define DAQ_FLAG_START    0x01
#define DAQ_FLAG_SEND     0x02
#define DAQ_FLAG_PREPARED 0x04
#define DAQ_FLAG_OVERRUN  0x80

/* Basic */
#define CCP_CMD_CONNECT  0x01
#define CCP_CMD_SET_MTA  0x02
#define CCP_CMD_DNLOAD  0x03
#define CCP_CMD_UPLOAD  0x04
#define CCP_CMD_TEST  0x05/* V2.1 */
#define CCP_CMD_START_STOP  0x06
#define CCP_CMD_DISCONNECT  0x07
#define CCP_CMD_START_STOP_ALL  0x08/* V2.1 */
#define CCP_CMD_SHORT_UPLOAD  0x0F
#define CCP_CMD_GET_DAQ_SIZE  0x14
#define CCP_CMD_SET_DAQ_PTR  0x15
#define CCP_CMD_WRITE_DAQ  0x16
#define CCP_CMD_EXCHANGE_ID  0x17
#define CCP_CMD_GET_CCP_VERSION  0x1B/* V2.1 */
#define CCP_CMD_DNLOAD6  0x23

/* Optional */
#define CCP_CMD_GET_CAL_PAGE  0x09
#define CCP_CMD_SET_S_STATUS  0x0C
#define CCP_CMD_GET_S_STATUS  0x0D
#define CCP_CMD_BUILD_CHKSUM  0x0E
#define CCP_CMD_CLEAR_MEMORY  0x10
#define CCP_CMD_SET_CAL_PAGE  0x11
#define CCP_CMD_GET_SEED  0x12
#define CCP_CMD_UNLOCK  0x13
#define CCP_CMD_PROGRAM  0x18
#define CCP_CMD_MOVE_MEMORY  0x19
#define CCP_CMD_DIAG_SERVICE  0x20
#define CCP_CMD_ACTION_SERVICE  0x21
#define CCP_CMD_PROGRAM6  0x22

/* Vector extensions */
#define CCP_CMD_PROGRAM_PREPARE  0x1E /* Prepare for flash kernel download */
#define CCP_CMD_PROGRAM_START  0x1F


/* -----------------------------------------------------------------------------
 Function-like Macro Definition
 ------------------------------------------------------------------------------*/
/*!
 @requirement: [Xcp807]
 @service name: Ccp_GetVersionInfo
 @syntax: void Ccp_GetVersionInfo( Std_VersionInfoType* versioninfo )
 @service ID[hex]: 0x01
 @sync/async: sync
 @reentrancy: Non Reentrant
 @param[in]: None
 @param[inout]: None
 @param[out]: Pointer to where to store the version information of this module
 @retval: void
 @precondition: void
 @postcondition: void
 @Description:
 */
#if ( CCP_VERSION_INFO_API == ON )
#define Ccp_GetVersionInfo(_vi) STD_GET_VERSION_INFO(_vi,CCP)
#endif
/* -----------------------------------------------------------------------------
 Global Type Definitions
 ------------------------------------------------------------------------------*/
typedef struct ccpOdtEntry {
  uint8_t * ptr;
  uint8_t   size;
} ccpOdtEntry_t;

/* ODT */
//@@@@typedef ccpOdtEntry_t ccpODT_t[7];

typedef struct ccpDaqList {
  ccpOdtEntry_t  odt[CCP_MAX_ODT][7];
  uint32_t      daqCanId;
  uint16_t        prescaler;
  uint16_t        cycle;
  uint16_t        eventChannel;
  uint8_t        last;
  uint8_t        flags;
} ccpDaqList_t;

typedef struct Ccp
{
    uint8_t Cro[8];/*command request object*/
    uint8_t Crm[8]; /* CRM Command Return Message buffer */

    boolean HasNewCro;
    boolean IsInitialized;

    uint8_t Ccp_Session_SM;

    uint8_t SendStatus;

    uint32_t  MTA[CCP_MAX_MTA]; /* Memory Transfer Address */


#if CCP_MAX_DAQ >0
    boolean DAQUpdated;
    uint8_t Dtm[8]; /* DTM Data Transmission Message buffer */
    ccpOdtEntry_t *DaqListPtr;               /* Pointer for SET_DAQ_PTR, make it near to save RAM  */

    ccpDaqList_t   DaqList[CCP_MAX_DAQ];     /* DAQ list */
#endif

    uint8_t UserSessionStatus; /* Used for GET/SET_SESSION_STATUS */


#if (CCP_SEED_KEY == ON)
    uint8_t ProtectionStatus; /* Resource Protection Status */
#endif

} Ccp;


/* -----------------------------------------------------------------------------
 Global Constant Declarations
 ------------------------------------------------------------------------------*/

/* -----------------------------------------------------------------------------
 Global Variable Declarations
 ------------------------------------------------------------------------------*/
CCP_EXTERNAL_ Ccp ccp;
/* -----------------------------------------------------------------------------
 Global Function Declarations
 ------------------------------------------------------------------------------*/
void Ccp_Init(void);
void Ccp_CopyNewCmd(uint8_t  CANRxData[]);
void Ccp_CMDHandler();
void CcpDAQ_OnEventHandler(uint8_t evtChannel);
void CcpDAQ_FastEventHandler(uint8_t evtChannel);
void CcpDAQ_MiddleEventHandler(uint8_t evtChannel);
void CcpDAQ_SlowEventHandler(uint8_t evtChannel);
/* -----------------------------------------------------------------------------
 Global Inline Function Definitions
 ------------------------------------------------------------------------------*/

#endif /* CCP_H_ */


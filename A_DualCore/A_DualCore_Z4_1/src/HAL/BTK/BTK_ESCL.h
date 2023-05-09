/*
 * BTK_ESCL.h
 *
 *
 *  Created on: 2019-10-12
 *  Author: ZhouYi
 *  
 */

#ifndef BTK_BSW_H_
#define BTK_BSW_H_

#include "typedefs.h"
#include "system.h"

#ifdef __BTK_ESCL__
#define __BTK_ESCL_EXTERN__
#else
#define __BTK_ESCL_EXTERN__  extern
#endif

#define ESCL_LS_POWER    2      /*LS1_OUT3 , index is 2 in Bios_LS_Output*/
#define ESCL_LS_GND     1      /*LS1_OUT2 , index is 1 in Bios_LS_Output*/

#define ESCL_T_INIT_DELAY 50
#define ESCL_T_TIMEOUT_1 180
#define ESCL_T_TIMEOUT_2 1600
#define ESCL_T_TIMEOUT_31 500
#define ESCL_T_TIMEOUT_32 500
#define ESCL_T_TIMEOUT_33 500
#define ESCL_T_TIMEOUT_4 1200
#define ESCL_T_TIMEOUT_5 1600

#define ESCL_UNLOCK_CMD 0x24
#define ESCL_LOCK_CMD  0x3E56
#define ESCL_ERASEKEY_CMD 0x81
#define ESCL_PROGKEY_CMD 0x5A

#define ESCL_FIX_CODE  0xCDF1704C
/* -----------------------------------------------------------------------------
    BTK_ESCL module  type Definitions
------------------------------------------------------------------------------*/
/*ESCL operation  enum*/
typedef enum BTK_EsclReqType_
{
    BTK_ESCL_NOCMD = 0,
    BTK_ESCL_UNLOCK = 1,
    BTK_ESCL_LOCK = 2,
    BTK_ESCL_PROGKEY = 3,
    BTK_ESCL_ERASEKEY = 4,
    BTK_ESCL_FORCEERASE = 5,
} BTK_EsclReqType;

/*ESCL result  enum*/
typedef enum BTK_EsclRsltType_
{
    BTK_ESCL_SUCCESS = 0,
    BTK_ESCL_BUSY = 1,
    BTK_ESCL_UNLOCK_FAILED = 2,
    BTK_ESCL_LOCK_FAILED = 3,
    BTK_ESCL_PROGKEY_FAILED = 5,
    BTK_ESCL_ERASEKEY_FAILED = 4,
} BTK_EsclRsltType;

typedef enum BTK_EsclErrorType_
{
    ESCL_TIMEOUT_1 = 1,  /*timer 1 expired, but no expected status received*/
    ESCL_TIMEOUT_2 = 2,  /*timer 2 expired, but no expected status received*/
    ESCL_TIMEOUT_4 = 4,  /*timer 4 expired, but no expected status received*/
    ESCL_TIMEOUT_5 = 5,  /*timer 5 expired, but no expected status received*/
    ESCL_TIMEOUT_31 = 31,
    ESCL_TIMEOUT_32 = 32,   /*timer 32 expired, but no expected status received;  ESCL progkey after progkey command*/
    ESCL_TIMEOUT_33 = 33,   /*timer 33 expired, but no expected status received;  ESCL erasekey after erasekey command*/
}BTK_EsclErrorType;

typedef enum BTK_EsclState_
{
    ESCL_IDLE_STATE = 0,                              /*idle state*/
    ESCL_SETON_POWER = 1,                             /*set on power*/
    ESCL_WAIT_READY = 2,                             /*wait the ESCL ready after setting on power*/
    ESCL_SEND_PWRDOWN = 3, 
    ESCL_WAIT_PWRDOWN = 4,
    ESCL_CHECK_PWRDOWN = 5,
    ESCL_CUTOFF_POWER = 6, 
    ESCL_SEND_UNLOCK = 7,
    ESCL_WAIT_UNLOCK = 8,
    ESCL_CHECK_UNLOCK = 9,
    ESCL_SETON_GND = 10,
    ESCL_SEND_LOCK = 11,
    ESCL_WAIT_LOCK = 12,
    ESCL_CHECK_LOCK = 13,
    ESCL_SEND_ERASEKEY = 14,
    ESCL_WAIT_ERASEKEY = 15,
    ESCL_CHECK_ERASEKEY = 16,
    ESCL_SEND_PROGKEY_1 = 17,
    ESCL_SEND_PROGKEY_2 = 18,
    ESCL_WAIT_PROGKEY = 19,
    ESCL_CHECK_PROGKEY = 20,
}BTK_EsclState;

typedef struct BTK_EsclSMState_
{
	uint32_t operTime;
	BTK_EsclState currState;
}BTK_EsclSMStateType;
/* -----------------------------------------------------------------------------
      BTK_BSW module  Macro Definitions
------------------------------------------------------------------------------*/
__BTK_ESCL_EXTERN__ uint8_t gblEsclOperReq;
__BTK_ESCL_EXTERN__ BTK_EsclRsltType gblEsclRslt;
__BTK_ESCL_EXTERN__ uint32_t currEsclKey;
__BTK_ESCL_EXTERN__ uint32_t newEsclKey;
__BTK_ESCL_EXTERN__ BTK_EsclReqType udsEsclOperReq;
__BTK_ESCL_EXTERN__ BTK_EsclErrorType  ESCLerrorReason;
__BTK_ESCL_EXTERN__ uint8_t EsclStatus;
__BTK_ESCL_EXTERN__  void BTK_ESCL_Init(void);
__BTK_ESCL_EXTERN__  void BTK_ESCL_Task(void);


#endif /* BTK_ESCL_H_ */

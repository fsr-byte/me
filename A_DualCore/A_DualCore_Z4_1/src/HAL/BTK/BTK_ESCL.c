/*
 * BTK_ESCL.c
 *
 *  Created on: 2019-10-12
 *      Author: ZhouYi
 *  the ESCL moudle defined in the detailed design were impelemented in this source file
 */

#define __BTK_ESCL__

#include "derivative.h"
#include "BTK_ESCL.h"
#include "LIN.h"
#include "global.h"
#include "cstring"

/* =================  Private type Declarations =========================*/

/* =================  Private macro Declarations =========================*/

/* =================  Private Variable Declarations =========================*/
//@@@@uint8_t esclCallCycle = 0;
uint8_t gblEsclOperReq = 0;
BTK_EsclRsltType gblEsclRslt = 0;
BTK_EsclSMStateType gblEsclSM;
uint32_t currEsclKey = 0x12345678;
uint32_t newEsclKey = 0x12345678;
BTK_EsclReqType udsEsclOperReq = 0;
uint8_t UdsEsclCmdExecuting = 0;
BTK_EsclErrorType  ESCLerrorReason = 0;
BTK_EsclReqType pregblEsclOperReq = 0;
uint8_t EsclStatus = 0;
/* =================  Private function Declarations =========================*/
void EsclErrorHandler(BTK_EsclErrorType  errorReason, BTK_EsclRsltType result);
void EsclWaitReadyHandler(BTK_EsclState nextState, uint16_t maxTimeOut, BTK_EsclErrorType error, BTK_EsclRsltType result);
void EsclPwrOnHandler(BTK_EsclState nextState, uint16_t maxTimeOut, BTK_EsclErrorType error, BTK_EsclRsltType result);
void EsclPowerOffHandler(BTK_EsclRsltType result);
/* =================  public funciton implementation =========================*/
/***************************************************************************************************************
 * Name:        BTK_Init
 * Function:    
 *              1. initialize the global variables
 *              2. output the driving signals to SSB leds via PWM port 
 *              3. output the IGN1 IGN2 relay driving signal via LowSide driver 
 *              4. sample and ouput the feedback voltage of IGN1/IGN2 relay
 * Input:        null
 * Return:        null
 * Link:        
 * Attention:    
 ************************************************************************************************************* */
void BTK_ESCL_Init(void)
{
    gblEsclOperReq = BTK_ESCL_NOCMD;
    gblEsclRslt = BTK_ESCL_SUCCESS;
    (void)memset(&gblEsclSM, 0, sizeof(gblEsclSM));
    currEsclKey = currEsclKey ^ESCL_FIX_CODE; 
    EsclStatus = 0;/*locked as default, should be saved in NVM?  defined in DBC: 0x0:Locked  0x1:Unlocked*/
    EsclLinCommFailed = 0;
    ESCLerrorReason = 0;
    pregblEsclOperReq = gblEsclOperReq;
}

/***************************************************************************************************************
 * Name:        EsclErrorHandler
 * Function:    set the failure result and reason
 * Input:        null
 * Return:        null
 * Link:        
 * Attention:    
 ************************************************************************************************************* */
void EsclErrorHandler(BTK_EsclErrorType  errorReason, BTK_EsclRsltType result)
{
    gblEsclRslt  = result;
    gblEsclSM.currState = ESCL_IDLE_STATE;
    ESCLerrorReason = errorReason;
    gblEsclOperReq = BTK_ESCL_NOCMD;
    HAL_Drive_LS(ESCL_LS_POWER, 0);   /*cut off the ESCL power */
}
/***************************************************************************************************************
 * Name:        EsclWaitReadyHandler
 * Function:    read status after send ReadStatus command, check if the ESCl is in ready. 
*                   if in ready , switch to next state; if not enter error state after timeout
 * Input:        null
 * Return:        null
 * Link:        
 * Attention:    
 ************************************************************************************************************* */
void EsclWaitReadyHandler(BTK_EsclState nextState, uint16_t maxTimeOut, BTK_EsclErrorType error, BTK_EsclRsltType result)
{
    uint8_t LinRslt;
    uint64_t  EsclrxData;
    uint8_t  rxDataArray[8];
    uint8_t EsclRspReceived = 0;
    uint8_t EsclError_temp = 0;
    
    LinRslt = LIN_RxAfterTxHead(&EsclrxData);
    if(LIN_RX_OK == LinRslt)
    {
        (void)memcpy(rxDataArray, (uint8_t*)&EsclrxData, sizeof(rxDataArray));
        /*bit 6~7 is 0x1 , ESCL is ready for next command, send the unlock command*/
        if(0x40 == (rxDataArray[4] &0x40))
        {
	     gblEsclSM.currState = nextState;
            gblEsclSM.operTime = SystemTickMs;
        }
        else
        {
            EsclError_temp = rxDataArray[4] &0x0F;
            LinRslt = LIN_RX_EMPTY;
        }
        EsclRspReceived = 1;  /*ESCL response received, no matter correct or wrong*/
    }
    /*check the if the expected status received*/
    if(LIN_RX_OK != LinRslt)
    {
        if((SystemTickMs -  gblEsclSM.operTime) >= maxTimeOut)
        {
            EsclErrorCode = EsclError_temp;
            EsclErrorHandler(error, result);     
        }        
        else
        {
            LIN_TxOnlyHeadForRx(0x31, 4);
        }
    }
    /*update the ESCL LIN communication failed or not status*/
    EsclLinCommFailed = 0;
    if( 0 == EsclRspReceived)
    {
        EsclLinCommFailed = 1;    
    }
}
/***************************************************************************************************************
 * Name:        EsclPwrOnHandler
 * Function:    common power on steps for Unlock, lock, erase key , program key 
 *                  1 power on the ESCL; 2 wait ESCL enter ready status
*                   if in ready , switch to next state; if not enter error state after timeout
 * Input:        null
 * Return:        null
 * Link:        
 * Attention:    
 ************************************************************************************************************* */
void EsclPwrOnHandler(BTK_EsclState nextState, uint16_t maxTimeOut, BTK_EsclErrorType error,  BTK_EsclRsltType result)
{
    if(ESCL_IDLE_STATE == gblEsclSM.currState)
    {
        gblEsclRslt = BTK_ESCL_BUSY;
        HAL_Drive_LS(ESCL_LS_POWER, 1);   /*set on the ESCL power */
        gblEsclSM.currState = ESCL_SETON_POWER;
        gblEsclSM.operTime = SystemTickMs;
    }
    /*send out the read status command*/
    else if(ESCL_SETON_POWER == gblEsclSM.currState)
    {
        /*T_INIT_DELAY after setting ON ESCL power , read the status*/
        if((SystemTickMs - gblEsclSM.operTime) > KHALI_Escl_InitDelay)
        {
            LIN_TxOnlyHeadForRx(0x31, 4);
            gblEsclSM.currState = ESCL_WAIT_READY;
            gblEsclSM.operTime = SystemTickMs;
        }
    }
    /*try to ensure the ESCL is in ready status, if not send another read status command until timeout*/
    else if (ESCL_WAIT_READY == gblEsclSM.currState)
    {
        EsclWaitReadyHandler(nextState, maxTimeOut, error, result);
    }
}
/***************************************************************************************************************
 * Name:        EsclPowerOffHandler
 * Function:    common power off steps for Unlock, lock, erase key , program key 
 *                  1 power on the ESCL; 2 wait ESCL enter ready status
*                   if in ready , switch to next state; if not enter error state after timeout
 * Input:        null
 * Return:        null
 * Link:        
 * Attention:    
 ************************************************************************************************************* */
void EsclPowerOffHandler( BTK_EsclRsltType result)
{
    if(ESCL_IDLE_STATE == gblEsclSM.currState)
    {
        //do nothing here
    }
    else if (ESCL_SEND_PWRDOWN ==  gblEsclSM.currState)
    {
        LIN_MasterTxFrame_WithDlc(0x20,4,0xFE000000);
        gblEsclSM.currState = ESCL_WAIT_PWRDOWN;
        gblEsclSM.operTime = SystemTickMs;
    }
    /*send out the read status command*/
    else if(ESCL_WAIT_PWRDOWN ==  gblEsclSM.currState)
    {
        LIN_TxOnlyHeadForRx(0x31, 4);
        gblEsclSM.currState = ESCL_CHECK_PWRDOWN;
    }
    /*try to ensure the ESCL is in ready status after send out the power command , if not send another read status command until timeout*/
    else if (ESCL_CHECK_PWRDOWN == gblEsclSM.currState)
    {
        EsclWaitReadyHandler(ESCL_CUTOFF_POWER, KHALI_Escl_TimeOut_4, ESCL_TIMEOUT_4, /*result*/BTK_ESCL_SUCCESS);/*if power off fail??? maybe result should not be transmited.*/
    }
    else if (ESCL_CUTOFF_POWER == gblEsclSM.currState)
    {
        HAL_Drive_LS(ESCL_LS_POWER, 0);   /*cut off the ESCL power */
        
        /*failure result was set in function EsclErrorHandler() */
        if(BTK_ESCL_BUSY == gblEsclRslt)
        {
            gblEsclRslt = BTK_ESCL_SUCCESS;
        }
        gblEsclOperReq = BTK_ESCL_NOCMD;
        gblEsclSM.currState = ESCL_IDLE_STATE;
    }
}

/***************************************************************************************************************
 * Name:        EsclUnlockHandler
 * Function:    execute the ESCL UNLocking procedure
 * Input:        null
 * Return:        null
 * Link:        
 * Attention:    
 ************************************************************************************************************* */
void EsclUnlockHandler(void)
{   
    uint64_t  EsclrxData = 0;
    uint8_t  rxDataArray[8];
    uint8_t LinRslt = 0;
    uint8_t EsclError_temp = 0;
    
    /*execute the public power on steps*/
    EsclPwrOnHandler(ESCL_SEND_UNLOCK, KHALI_Escl_TimeOut_1, ESCL_TIMEOUT_1, BTK_ESCL_UNLOCK_FAILED);
    /*don nothing here*/
    if(ESCL_IDLE_STATE == gblEsclSM.currState)
    {
        //do nothing
    }
    
    /*send unlock command */
    else if(ESCL_SEND_UNLOCK ==  gblEsclSM.currState)
    {
        /*left shift 8 bits for command byte*/
        EsclrxData = currEsclKey;
        EsclrxData = EsclrxData << 8;
        EsclrxData = 0xFFFFFF0000000000 + EsclrxData; 
        EsclrxData = EsclrxData + ESCL_UNLOCK_CMD;
        /*send the unlock command*/
        LIN_MasterTxFrame_WithDlc(0x32,8,EsclrxData);  //@@@@ LIN_MasterTxFrame_WithDlc(0x32,8,0x3030303024); LIN_MasterTxFrame_WithDlc(0x32,8,esclUnlokCmd); 
        gblEsclSM.currState = ESCL_WAIT_UNLOCK;
        gblEsclSM.operTime = SystemTickMs;
    }
    /*send out the read Status command*/
    else if (ESCL_WAIT_UNLOCK ==  gblEsclSM.currState)
    {
            LIN_TxOnlyHeadForRx(0x31, 4);
            gblEsclSM.currState = ESCL_CHECK_UNLOCK;
    }
    /*try to ensure the ESCL is unlock, if not send another read status command until timeout*/
    else if (ESCL_CHECK_UNLOCK ==  gblEsclSM.currState)
    {
        /*try to receive Status for ESCL after sending out the head*/
        LinRslt = LIN_RxAfterTxHead(&EsclrxData);
        if(LIN_RX_OK == LinRslt)
        {
            (void)memcpy(rxDataArray, (uint8_t*)&EsclrxData, sizeof(rxDataArray));
            if((0x6C == rxDataArray[7]) && (0x35 == rxDataArray[6]) && (0x40 == (rxDataArray[4] &0x40)))
            {
                gblEsclSM.currState = ESCL_SEND_PWRDOWN;
		  EsclStatus = 1;
            }
            else
            {
                EsclError_temp = rxDataArray[4] &0x0F;
                LinRslt = LIN_RX_EMPTY;
            }
        }
        /*check the if the expected status received*/
        if(LIN_RX_OK != LinRslt)
        {
            if((SystemTickMs -  gblEsclSM.operTime) >= KHALI_Escl_TimeOut_2)
            {
                EsclErrorCode = EsclError_temp;
                EsclErrorHandler(ESCL_TIMEOUT_2, BTK_ESCL_UNLOCK_FAILED);     
            }        
            else
            {
                LIN_TxOnlyHeadForRx(0x31, 4);
            }
        }
    }
    /*execute the public power off steps*/
    EsclPowerOffHandler(BTK_ESCL_UNLOCK_FAILED);
}
/***************************************************************************************************************
 * Name:        EsclLockHandler
 * Function:    execute the ESCL Locking procedure
 * Input:        null
 * Return:        null
 * Link:        
 * Attention:    
 ************************************************************************************************************* */
void EsclLockHandler(void)
{
    uint64_t  EsclrxData = 0;
    uint8_t  rxDataArray[8];
    uint8_t LinRslt = 0;
    uint8_t EsclError_temp = 0;
    
    /*execute the public power on steps*/
    EsclPwrOnHandler(ESCL_SETON_GND, KHALI_Escl_TimeOut_1, ESCL_TIMEOUT_1, BTK_ESCL_LOCK_FAILED);
    /*don nothing here*/
    if(ESCL_IDLE_STATE == gblEsclSM.currState)
    {
        //do nothing
    }
    /*set on the LOCK GND relay*/
    else if (ESCL_SETON_GND == gblEsclSM.currState)
    {
        HAL_Drive_LS(ESCL_LS_GND, 1);   /*set on the ESCL GND */
        gblEsclSM.currState = ESCL_SEND_LOCK;
    }
    /*send the lock command*/
    else if (ESCL_SEND_LOCK == gblEsclSM.currState)
    {
        LIN_MasterTxFrame_WithDlc(0x14,2,0x563E);
        gblEsclSM.currState = ESCL_WAIT_LOCK;
        gblEsclSM.operTime = SystemTickMs;
    }
    /*send out read status command*/
    else if (ESCL_WAIT_LOCK == gblEsclSM.currState)
    {
        LIN_TxOnlyHeadForRx(0x31, 4);
        gblEsclSM.currState = ESCL_CHECK_LOCK;
    }
    /*try to ensure the ESCL is unlock, if not send another read status command until timeout*/
    else if (ESCL_CHECK_LOCK == gblEsclSM.currState)
    {
        LinRslt = LIN_RxAfterTxHead(&EsclrxData);
        if(LIN_RX_OK == LinRslt)
        {
            (void)memcpy(rxDataArray, (uint8_t*)&EsclrxData, sizeof(rxDataArray));
            if((0x4B == rxDataArray[7]) && (0xD2 == rxDataArray[6]) && (0x40 == (rxDataArray[4] &0x40)))
            {
                EsclStatus = 0;
                gblEsclSM.currState = ESCL_SEND_PWRDOWN;
                gblEsclSM.operTime = SystemTickMs;
                HAL_Drive_LS(ESCL_LS_GND, 0);   /*clear off the ESCL GND */
            }
            else
            {
                EsclError_temp = rxDataArray[4] &0x0F;
                LinRslt = LIN_RX_EMPTY;
            }
        }
        else 
        {
            if((SystemTickMs -  gblEsclSM.operTime) >= KHALI_Escl_TimeOut_5)
            {
                EsclErrorHandler(ESCL_TIMEOUT_5, BTK_ESCL_LOCK_FAILED);     
                HAL_Drive_LS(ESCL_LS_GND, 0);   /*clear off the ESCL GND */
            }
            else
            {
                EsclErrorCode = EsclError_temp;
                LIN_TxOnlyHeadForRx(0x31, 4);
            }        
        }
    }
    /*execute the public power off steps*/
    EsclPowerOffHandler(BTK_ESCL_LOCK_FAILED);    
}
/***************************************************************************************************************
 * Name:        EsclEraseKeyHandler
 * Function:    execute the ESCL erasing key procedure
 * Input:        null
 * Return:        null
 * Link:        
 * Attention:    
 ************************************************************************************************************* */
 void EsclProgKeyHandler(void)
 {
    uint64_t  EsclrxData = 0;
    uint8_t  rxDataArray[8];
    uint8_t LinRslt = 0;
 
    /*execute the public power on steps*/
    EsclPwrOnHandler(ESCL_SEND_PROGKEY_1, KHALI_Escl_TimeOut_1, ESCL_TIMEOUT_1, BTK_ESCL_PROGKEY_FAILED);
    /*don nothing here*/
    if(ESCL_IDLE_STATE == gblEsclSM.currState)
    {
        //do nothing
    }
    /*send the program key command*/
    else if (ESCL_SEND_PROGKEY_1 == gblEsclSM.currState)
    {
        EsclrxData = newEsclKey;
        EsclrxData = EsclrxData << 8;
        EsclrxData = 0xFFFFFF0000000000 + EsclrxData; 
        EsclrxData =  EsclrxData + ESCL_PROGKEY_CMD;

        LIN_MasterTxFrame_WithDlc(0x32,8,EsclrxData);
        gblEsclSM.currState = ESCL_SEND_PROGKEY_2;
        gblEsclSM.operTime = SystemTickMs;
    }
    else if (ESCL_SEND_PROGKEY_2 == gblEsclSM.currState)
    {
        if((SystemTickMs - gblEsclSM.operTime) > KHALI_Escl_ProgKeyInterval)
        {
            EsclrxData = newEsclKey;
            EsclrxData = EsclrxData << 8;
            EsclrxData = 0xFFFFFF0000000000 + EsclrxData; 
            EsclrxData =  EsclrxData + ESCL_PROGKEY_CMD;

            LIN_MasterTxFrame_WithDlc(0x32,8,EsclrxData);
            gblEsclSM.currState = ESCL_WAIT_PROGKEY;
            gblEsclSM.operTime = SystemTickMs;
        }
    }

    /*send read status command*/
    else if (ESCL_WAIT_PROGKEY == gblEsclSM.currState)
    {
        LIN_TxOnlyHeadForRx(0x31, 4);
        gblEsclSM.currState = ESCL_CHECK_PROGKEY;
    }

    /*read status, ensure ESCL is in programmed status*/
    else if (ESCL_CHECK_PROGKEY == gblEsclSM.currState)
    {
        LinRslt = LIN_RxAfterTxHead(&EsclrxData);
        if(LIN_RX_OK == LinRslt)
        {
            (void)memcpy(rxDataArray, (uint8_t*)&EsclrxData, sizeof(rxDataArray));
            /*ESCL must in key programmed status and in ready status, it doesn't matter that the ESCL is in locked or unlocked status */
            if((0x50 == (rxDataArray[4] &0x70)))
            {
                currEsclKey = newEsclKey^ESCL_FIX_CODE;
                gblEsclSM.currState = ESCL_SEND_PWRDOWN;
                gblEsclSM.operTime = SystemTickMs;
            }
            else
            {
                LinRslt = LIN_RX_EMPTY;
            }
        }
        else 
        {
            if((SystemTickMs -  gblEsclSM.operTime) >= KHALI_Escl_TimeOut_32)
            {
                EsclErrorHandler(ESCL_TIMEOUT_32, BTK_ESCL_PROGKEY_FAILED);     
            }
            else
            {
                LIN_TxOnlyHeadForRx(0x31, 4);
            }        
        }

        /*execute the public power off steps*/
    }
    EsclPowerOffHandler(BTK_ESCL_PROGKEY_FAILED);
}
/***************************************************************************************************************
 * Name:        EsclEraseKeyHandler
 * Function:    execute the ESCL erasing key procedure
 * Input:        null
 * Return:        null
 * Link:        
 * Attention:    
 ************************************************************************************************************* */
 void EsclEraseKeyHandler(void)
 {
    uint64_t  EsclrxData = 0;
    uint8_t  rxDataArray[8];
    uint8_t LinRslt = 0;

    /*execute the public power on steps*/
    EsclPwrOnHandler(ESCL_SEND_ERASEKEY, KHALI_Escl_TimeOut_1, ESCL_TIMEOUT_1, BTK_ESCL_ERASEKEY_FAILED);
    /*don nothing here*/
    if(ESCL_IDLE_STATE == gblEsclSM.currState)
    {
        //do nothing
    }
    /*send erase key command */
    else if (ESCL_SEND_ERASEKEY == gblEsclSM.currState)
    {
        EsclrxData = currEsclKey;
        EsclrxData = EsclrxData << 8;
        EsclrxData = 0xFFFFFF0000000000 + EsclrxData; 
        EsclrxData =  EsclrxData + ESCL_ERASEKEY_CMD;
        LIN_MasterTxFrame_WithDlc(0x32,8,EsclrxData);
        gblEsclSM.currState = ESCL_WAIT_ERASEKEY;
        gblEsclSM.operTime = SystemTickMs;
    }
    /*send out read status command*/
    else if (ESCL_WAIT_ERASEKEY == gblEsclSM.currState)
    {
        LIN_TxOnlyHeadForRx(0x31, 4);
        gblEsclSM.currState = ESCL_CHECK_ERASEKEY;
    }
    /*check if the key was erased successfully*/
    else if (ESCL_CHECK_ERASEKEY == gblEsclSM.currState)
    {
        LinRslt = LIN_RxAfterTxHead(&EsclrxData);
        if(LIN_RX_OK == LinRslt)
        {
            (void)memcpy(rxDataArray, (uint8_t*)&EsclrxData, sizeof(rxDataArray));
            /*ESCL must in key erased status and in ready status, it doesn't matter that the ESCL is in locked or unlocked status */
            if((0x40 == (rxDataArray[4] &0x70)))
            {
                gblEsclSM.currState = ESCL_SEND_PWRDOWN;
                gblEsclSM.operTime = SystemTickMs;
            }
            else
            {
                LinRslt = LIN_RX_EMPTY;
            }
        }
        else 
        {
            if((SystemTickMs -  gblEsclSM.operTime) >= KHALI_Escl_TimeOut_33)
            {
                EsclErrorHandler(ESCL_TIMEOUT_33, BTK_ESCL_ERASEKEY_FAILED);     
            }
            else
            {
                LIN_TxOnlyHeadForRx(0x31, 4);
            }        
        }
        
    }
    /*execute the public power off steps*/
    EsclPowerOffHandler(BTK_ESCL_ERASEKEY_FAILED);
}

/***************************************************************************************************************
 * Name:        EsclForceEraseHandler
 * Function:    execute the force ESCL erasing key procedure
 * Input:        null
 * Return:        null
 * Link:        
 * Attention:    
 ************************************************************************************************************* */
void EsclForceEraseHandler(void)
 {
    uint64_t  EsclrxData = 0;
    uint8_t  rxDataArray[8];
    uint8_t LinRslt = 0;
    static uint8_t  firstCalled = 1;
    static uint32_t startTime = 0;

    /*execute the public power on steps*/
    EsclPwrOnHandler(ESCL_SEND_ERASEKEY, KHALI_Escl_TimeOut_1, ESCL_TIMEOUT_1, BTK_ESCL_ERASEKEY_FAILED);
    /*don nothing here*/
    if(ESCL_IDLE_STATE == gblEsclSM.currState)
    {
        //do nothing
    }
    /*send erase key command */
    else if (ESCL_SEND_ERASEKEY == gblEsclSM.currState)
    {
        EsclrxData = 0xFFFFFFFF;//currEsclKey   changed by currEsclKey
        EsclrxData = EsclrxData << 8;
        EsclrxData = 0xFFFFFF0000000000 + EsclrxData; 
        EsclrxData =  EsclrxData + ESCL_ERASEKEY_CMD;
        LIN_MasterTxFrame_WithDlc(0x32,8,EsclrxData);
        if(1 == firstCalled)
        {
            startTime = SystemTickMs;
            firstCalled = 0;
        }
	 if((SystemTickMs -  startTime) > KHALI_Escl_ForceEraseDuration)
        {
            gblEsclSM.operTime = SystemTickMs;
            gblEsclSM.currState = ESCL_SEND_PWRDOWN;
            firstCalled = 1;
	     EsclErrorHandler(ESCL_TIMEOUT_33, BTK_ESCL_ERASEKEY_FAILED); 
        }
	 gblEsclSM.currState = ESCL_WAIT_ERASEKEY;
    }
    /*send out read status command*/
    else if (ESCL_WAIT_ERASEKEY == gblEsclSM.currState)
    {
        LIN_TxOnlyHeadForRx(0x31, 4);
        gblEsclSM.currState = ESCL_CHECK_ERASEKEY;
	 gblEsclSM.operTime = SystemTickMs;
    }
    /*check if the key was erased successfully*/
    else if (ESCL_CHECK_ERASEKEY == gblEsclSM.currState)
    {
        LinRslt = LIN_RxAfterTxHead(&EsclrxData);
        if(LIN_RX_OK == LinRslt)
        {
            (void)memcpy(rxDataArray, (uint8_t*)&EsclrxData, sizeof(rxDataArray));
            /*ESCL must in key erased status and in ready status, it doesn't matter that the ESCL is in locked or unlocked status */
            if((0x40 == (rxDataArray[4] &0x70)))
            {
                gblEsclSM.currState = ESCL_SEND_PWRDOWN;
                gblEsclSM.operTime = SystemTickMs;
		  firstCalled = 1;
            }
            else
            {
                LinRslt = LIN_RX_EMPTY;
		  gblEsclSM.currState = ESCL_SEND_ERASEKEY;
            }
        }
        else 
        {
            if((SystemTickMs -  gblEsclSM.operTime) >= KHALI_Escl_TimeOut_33)
            {
                //EsclErrorHandler(ESCL_TIMEOUT_33, BTK_ESCL_ERASEKEY_FAILED); 
                gblEsclSM.currState = ESCL_SEND_ERASEKEY;
            }
            else
            {
                LIN_TxOnlyHeadForRx(0x31, 4);
            }        
        }
        
    }

    /*execute the public power off steps*/
    EsclPowerOffHandler(BTK_ESCL_ERASEKEY_FAILED);
}

/***************************************************************************************************************
 * Name:        BTK_ESCL_Task
 * Function:    
 * Input:        null
 * Return:        null
 * Link:        
 * Attention:    
 ************************************************************************************************************* */
void BTK_ESCL_Task(void)
{   
    static uint8_t esclCallCycle = 0;
    esclCallCycle ++;
    if(esclCallCycle < KHALI_Escl_TasckStep)
    {
         return;
    }
    esclCallCycle  = 0;
    /*ESCL is not busy, accept the ESCL command from UDS*/
    if((0 == UdsEsclCmdExecuting) && (BTK_ESCL_NOCMD != udsEsclOperReq) && (BTK_ESCL_BUSY != gblEsclRslt))
    {
        UdsEsclCmdExecuting = 1;
        gblEsclOperReq = udsEsclOperReq;
    }
	/*Unlock when lock is executing*/
    if(pregblEsclOperReq != gblEsclOperReq)
    {
    	gblEsclSM.currState = ESCL_IDLE_STATE;
    }
    
    if(BTK_ESCL_UNLOCK == gblEsclOperReq)
    {
        EsclUnlockHandler();
    }
    else if (BTK_ESCL_LOCK == gblEsclOperReq)
    {
        EsclLockHandler();
    }
    else if (BTK_ESCL_PROGKEY == gblEsclOperReq)
    {
        EsclProgKeyHandler();
    }
    else if (BTK_ESCL_ERASEKEY == gblEsclOperReq)
    {
        EsclEraseKeyHandler();
    }
    else if (BTK_ESCL_FORCEERASE == gblEsclOperReq)
    {
        EsclForceEraseHandler();
    }
    /*UDS ESCL command finished, */
    if((BTK_ESCL_BUSY != gblEsclRslt) && (1 == UdsEsclCmdExecuting))
    {
         if(BTK_ESCL_NOCMD == udsEsclOperReq)
         {
             UdsEsclCmdExecuting = 0;
         }
    }
    pregblEsclOperReq = gblEsclOperReq;
}

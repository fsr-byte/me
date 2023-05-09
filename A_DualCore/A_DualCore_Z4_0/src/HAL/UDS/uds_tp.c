/*
 *
 * Copyright (c) 2016 Zhou Yi  All Rights Reserved.
 *
 * Copying of this document or code and giving it to others and the
 * use or communication of the contents thereof, are forbidden without
 * expressed authority. Offenders are liable to the payment of damages.
 * All rights reserved in the event of the grant of a invention patent or the
 * registration of a utility model, design or code.
 *
 * Issued by Zhou Yi
 */

/*! @file uds_tp.c
 @brief  brief description on this source file, what is the function to be implemented
 @details details description on the function

  */
#define MASTER_UDS_TP_

/* =====================Includes====================================*/
#include "derivative.h"      /* derivative-specific definitions */

#include "CAN_Operation.h"

#include "UDS_Interface.h"
#include "uds_tp.h"
#include "uds_service.h"
#include "cstring"
/* =====================Private Macro Definitions============================*/
#define UDSTP_N_Cr  150
#define UDSTP_N_Bs  150
//#define UDSTP_N_Cr  150000
//#define UDSTP_N_Bs  150000
#define UDSTP_BS 8   /*according to GuoJi UDS specification  BS = 8, STMin = 10*/
/* ==================== Private function-like Macro==========================*/


/* ===================== Private Type Definitions=========================*/

/* =================  Private Variable Declarations =========================*/

/*all module level variables are defined here*/

uint16_t tpReqCursor = 0; 				/*cursor while receving multi-frame request*/
boolean tpFullReqRecvFlag = 0;         /*a full reqeust was received*/
boolean  tpNewMsgFlag = 0;          /*new CAN message received*/
boolean  phyReqFlag = 0;        /*the request come from physical addressing*/
tpFlowStatusType tpFlowStatus = 0;
uint8_t 	tpBlockSize = 0;
uint8_t	tpSTmin = 0;
uint8_t     tpRxSN = 0;
uint8_t 	tpTxSN = 0;
uint8_t 	tpTxBSCnt = 0;				/*Block size counter when sending CF*/
uint8_t     tpActRecvLen = 0;
udsNRCType tpNRC = 0;

uint16_t tpRspCursor = 0; 			/*cursor while sending multi-frame request*/

udsTpStateType udsTpState = 0;	/*response transmission state*/
uint32_t  udsTpCurrSysTick = 0;
uint32_t  udsTpTxSTMinTick = 0;
/* =================  Private Constant Declarations =========================*/

/* =================  Private Function Declarations =========================*/
void udsTpSendCF(void);
void udsTpSendFlowCtrl(uint8_t FS);
void udsTpSendNRC(udsNRCType NRC, uint8_t service);
/* =================  Global Variable Declarations =========================*/
/*variables defined here can be used by other modules*/

uint8_t tpUdsCANRecv[MAX_CAN_MSG_SIZE] = {0};
uint8_t tpReqBuf[MAX_UDS_REQ_LEN] = {0};
uint16_t tpReqLen = 0;					/*total length while receving multi-frame request*/
uint8_t tpRspBuf[MAX_UDS_RSP_LEN] = {0};
uint16_t tpRspLen = 0;				/*total length of the response to be sent*/
boolean DisCanRxTxFlag = 0;		/*the flag indicating if UDS service ComCtrl is called and CAN communication Tx/Rx is disabled*/

//udsServiceType udsCurrService = 0;

/* =================  Global Constant Declarations =========================*/

/* =================  external variable Declarations =========================*/
extern udsServiceType udsCurrService;

/* =================  Global Function implementation =========================*/
     

/*---------------------------------------------------------------------------
description: initialize all UDS TP layer parameters
output tpReqBuf: 	global variable 
---------------------------------------------------------------------------*/
void udsTpInit(void)
{
    (void)memset(tpReqBuf, 0, sizeof(tpReqBuf));
    (void)memset(tpRspBuf, 0, sizeof(tpRspBuf));
    (void)memset(tpUdsCANRecv, 0, sizeof(tpUdsCANRecv));
    tpReqLen = 0;
    tpRspLen = 0;
    phyReqFlag = TRUE;
    tpNewMsgFlag = FALSE;
    tpFullReqRecvFlag = FALSE;
    udsTpState = UDS_TP_IDLE;
}

/*---------------------------------------------------------------------------
description: check if there is pending CF to be send , send it based on FC parameters 
this function should be called by shedular cyclically
---------------------------------------------------------------------------*/
void udsTpTask(void)
{

    /*waiting for Consecutife Frame, check the N_Cr*/
    if(UDS_TP_WAIT_NF == udsTpState)
    {
        /*return to idle state, ignore next CFs*/
        if((SystemTickMs - udsTpCurrSysTick) > UDSTP_N_Cr)
        {
             udsTpState = UDS_TP_IDLE;
        }
    }
    /*waiting for FlowControl Frame, check the N_Bs*/
    if(UDS_TP_WAIT_FC == udsTpState)
    {
        /*return to idle state, ignore next CFs*/
        if((SystemTickMs - udsTpCurrSysTick) > UDSTP_N_Bs)
        {
             udsTpState = UDS_TP_IDLE;
        }
    }

	//if(TRUE == udsTxCFFlag)
	if(UDS_TP_SEND_CF == udsTpState)
	{
		if( (SystemTickMs > udsTpTxSTMinTick) && ((SystemTickMs -udsTpTxSTMinTick)>= tpSTmin))
		{
			udsTpSendCF();
		}
    }
      
    if (TRUE == tpFullReqRecvFlag)
    {
        tpFullReqRecvFlag = FALSE;
        /*call UDS service layer main function to executive service*/
        udsServiceMain();
   }

 
}

/*---------------------------------------------------------------------------
description: ISO15765 TP receiption handling , check frame type, check length, copy pure request dat into buffer
input param: 		canBuf -- PDU from CAN module
output tpReqBuf: 	global variable 
---------------------------------------------------------------------------*/
void udsTpRecv(boolean PhyIdFlag, uint8_t tpRecvLen)
{
    tpFrameType  frameType;
    uint16_t   cfValidLen;
    uint8_t   cfSN;
    tpNewMsgFlag = TRUE;
    phyReqFlag = PhyIdFlag;
	tpActRecvLen = tpRecvLen;

    /*diagnosis message length must be 8, if not ignore it directly*/
    if(tpActRecvLen != 8)
    {
        return;
    }
    /*handle the received requet message*/
    /*if a service is under execution, refuse the request and return busy directly*/
    if(UDS_NOP_SERVICE != udsCurrService)
    {
       tpNRC = NRC_BRR;
       tpReqBuf[0] = tpUdsCANRecv[1];
    }
    
    else
    {
        tpNRC = NRC_PR;

        /*check higher half of byte 0*/
        frameType = (tpFrameType)((tpUdsCANRecv[0]>>4)&0xF);
        switch(frameType)
        {
        case UDS_SF:
            /*only when TP layer is not sending CF can UDS accept new service request*/
            if((UDS_TP_SEND_CF  != udsTpState) && (UDS_TP_WAIT_FC!= udsTpState))
            {
                tpReqLen = tpUdsCANRecv[0]&0xF;
                /*check length range*/
                if( (tpReqLen > MAX_SF_LEN) || (tpReqLen < 1) )
                {
                    tpNRC = NRC_NRSP;
                }
                else
                {
                    (void)memcpy(tpReqBuf, &tpUdsCANRecv[1], tpReqLen);
                    /*UDS service layer can be called now*/
                    tpFullReqRecvFlag = TRUE;
                }
                /*FF length error, ignore it*/
                if(tpActRecvLen < (tpReqLen +1))
                {
                    tpFullReqRecvFlag = FALSE;            
                    tpNRC = NRC_NRSP;
                    udsTpState = UDS_TP_IDLE;
                }            
            }
            else 
            {
                tpNRC = NRC_NRSP;
            }
        break;

        case UDS_FF:
            /*only when TP layer is not sending CF can UDS accept new service request*/
            if((UDS_TP_SEND_CF  != udsTpState) && (UDS_TP_WAIT_FC!= udsTpState))
            {
                tpReqLen = tpUdsCANRecv[0]&0xF;
                tpReqLen = tpReqLen << 8;
                tpReqLen += tpUdsCANRecv[1];
                if (tpReqLen < MAX_SF_LEN)
                {
                    tpNRC = NRC_NRSP;
                    udsTpState = UDS_TP_IDLE;
                }
                /*check length range: only MAX_UDS_REQ_LEN supported*/
                if(tpReqLen > MAX_UDS_REQ_LEN)
                {
                    tpNRC = NRC_NRSP;
                    /*send flowcontrol with overflow FlowState*/
                    udsTpSendFlowCtrl(UDS_OVFLW);
                }
                else if( (tpActRecvLen < 8) || (phyReqFlag == FALSE) || (tpReqLen <= MAX_SF_LEN) )
                {
                    tpNRC = NRC_NRSP;
                    udsTpState = UDS_TP_IDLE;
                }
                else
                {    
                    tpReqCursor = MAX_FF_LEN;      /*there is 6 vaild data in First frame */
                    (void)memcpy(tpReqBuf, &tpUdsCANRecv[2], tpReqCursor);
                    /*Now, send the Flow Contrl Frame to tester, flowstate is continueToSend*/
                    udsTpSendFlowCtrl(UDS_CTS);
                    udsTpState = UDS_TP_WAIT_NF;
                    /*according to ISO15765-2 chapter 6.5.4.2 , first FF SN is 0, so SN in next CF should be 1*/
                    tpRxSN = 1;
                    /*record current system tick to check N_Cr*/
                    udsTpCurrSysTick = SystemTickMs;
                }
            }
            else
            {
                tpNRC = NRC_NRSP;
            }
        break;

        case UDS_CF:
            /*only when TP layer waiting for consecutive frame,  can UDS accept consecutive frame*/
            if(UDS_TP_WAIT_NF == udsTpState)
            {
                cfValidLen = tpReqLen - tpReqCursor;
                /*max valid data in CF is 7 bytes*/
                if (cfValidLen > MAX_CF_LEN)
                {
                    cfValidLen = MAX_CF_LEN;
                }            
                /*CF length error, ignore it*/
                if(tpActRecvLen < (cfValidLen +1))
                {
                    tpNRC = NRC_NRSP;
                    tpFullReqRecvFlag = FALSE;
                    udsTpState = UDS_TP_IDLE;
                }
                else
                {
                    /*SN is checked here  now*/
                    cfSN = tpUdsCANRecv[0]&0xF;
                    if(cfSN == tpRxSN)
                    {

                        (void)memcpy(&tpReqBuf[tpReqCursor], &tpUdsCANRecv[1], cfValidLen);
                        tpReqCursor += cfValidLen;
                        /*the complete request is received, UDS service layer can be called now*/
                        if (tpReqCursor >=  tpReqLen)
                        {
                            tpFullReqRecvFlag = TRUE;
                        }
                        tpRxSN++;
                        if(tpRxSN > 0xF)
                        {
                           tpRxSN = 0;
                        }
                        /*record current system tick to check N_Cr*/
                        udsTpCurrSysTick = SystemTickMs;                    
                    }
                    /*SN wrong, ignore */
                    else
                    {
                        udsTpState  = UDS_TP_IDLE;
                        tpNRC = NRC_NRSP;
                    }
                }
            }
            else
            {
                tpNRC = NRC_NRSP;
            }
        break;
       
        case UDS_FC:
            /*only when TP layer waiting for flow control frame,  can UDS accept flow control  frame*/
            if(UDS_TP_WAIT_FC == udsTpState)
            {
                /*get FlowStaus */
                tpFlowStatus = (tpFlowStatusType)(tpUdsCANRecv[0]&0xF);
                /*block size*/
                tpBlockSize = tpUdsCANRecv[1];
                /*Minimum Seperate time*/
                tpSTmin = tpUdsCANRecv[2] + 1;
                switch(tpFlowStatus)
                {
                /*send following Consecutive frames*/
                case UDS_CTS:
                    udsTpState = UDS_TP_SEND_CF;
                    /*first Flow control, set SN to 1, other FlowControl should not change the SN*/
                    if(MAX_FF_LEN == tpRspCursor)
                    {
                        tpTxSN = 1;
                    }
                    /*reset Seperate timer and block size counter*/
                    tpTxBSCnt = 0;
                    udsTpTxSTMinTick = SystemTickMs;
                    
                break;

                /*wait for another flow control*/
                case UDS_WT:
                    udsTpState = UDS_TP_WAIT_FC;
                break;

                default:
                    /*PC side overflow, give up current response transmission*/
                    udsTpState = UDS_TP_IDLE;
                break;
                }
                /*flow control frame length wrong */
                if(tpActRecvLen < 3)
                {
                    udsTpState = UDS_TP_IDLE;
                }
            }
            else
            {
                tpNRC = NRC_NRSP;
            }
            if(FALSE == phyReqFlag)
            {
               tpNRC = NRC_NRSP;
               udsTpState = UDS_TP_IDLE;
            }
        break;

        default:
            /*unknown command, ignore it*/
            tpNRC = NRC_NRSP;
            break;

        }

        /*there is error, send Negative response directly*/
        if( (tpNRC != NRC_PR) && (tpNRC != NRC_NRSP) )
        {
            udsTpSendNRC(tpNRC, tpReqBuf[0] );
        }
    }
    
}

/*---------------------------------------------------------------------------
description: ISO15765 TP transmission handling 
input tpRspBuf: 	global variable 
---------------------------------------------------------------------------*/
void udsTpSend(udsNRCType	 NRC)
{
    uint8_t data[8];
    /*reponse is longer than a single Frame, but the request comes from functional addressing , don't send any respnse*/
    #if 0
    if( (tpRspLen > MAX_SF_LEN) && (FALSE == phyReqFlag) )
    {
        return;
    }
#endif    
    /*No response to be sent, return directly*/
    if(NRC_NRSP == NRC)
    {
       return;
    }
    /*according to requirement, padding data is 0x00*/
    (void)memset(data, UDS_PADDING_BYTE, sizeof(data));
    /*response can be put into Single Frame*/
    if(tpRspLen <= MAX_SF_LEN)
    {
    	data[0] = (uint8_t)tpRspLen;
    	(void)memcpy(&data[1], tpRspBuf, tpRspLen);
    	tpRspCursor = tpRspLen;
    	udsTpState = UDS_TP_IDLE;
    }
    else
    {
    	data[0] = (uint8_t)(UDS_FF);
    	data[0] = data[0] << 4;
    	data[0] = data[0] + (uint8_t)(tpRspLen >>8);
    	data[1] =  (uint8_t)tpRspLen;
    	(void)memcpy(&data[2], tpRspBuf, MAX_FF_LEN);
    	tpRspCursor = MAX_FF_LEN;
    	udsTpState = UDS_TP_WAIT_FC;
        /*record current system tick to check N_Bs timeout*/
        udsTpCurrSysTick = SystemTickMs;        
    }
    /*call CAN interface function to send UDS response*/
    CanTransmit_UDS(data);

}

/* =================  Private Function implementation =========================*/

/*---------------------------------------------------------------------------
description: Assembly negative response frame according to ISO14229, Send NRC code
input Parm: 		NRC -- negative code
input Parm: 		service -- negative code
---------------------------------------------------------------------------*/
void udsTpSendNRC(udsNRCType NRC, uint8_t service)
{
	uint8_t data[8];

	/*according to requirement, padding data is 0x00*/
	(void)memset(data, UDS_PADDING_BYTE, sizeof(data));
	/*negative response is single frame, length is always 3*/
	data[0] = 0x3;
	data[1] = 0x7F;
	data[2] = service;
	data[3] = (uint8_t)NRC;
	/*call CAN interface function to send UDS response*/
	CanTransmit_UDS(data);
}

/*---------------------------------------------------------------------------
description: Assembly consecutive frame according to ISO15765 and send
---------------------------------------------------------------------------*/
void udsTpSendCF(void)
{
	uint16_t   cfValidLen;
	uint8_t data[8];

	/*Block size in last flow control frame is not 0 and already send required frame, wait for another Flow control frame*/
	if( (0 != tpBlockSize) && (tpTxBSCnt >= tpBlockSize) )
	{
		udsTpState = UDS_TP_WAIT_FC;
	}
	else
	{
              tpTxBSCnt++;
              /*Block size in last flow control frame is not 0 and already send required frame, wait for another Flow control frame 
              !!! we shoud change the state immediately.  reason: udsTpSendCF is called 20ms, but next flow control frame will be received immediately after Consecutive frame is sent out */
              if( (0 != tpBlockSize) && (tpTxBSCnt >= tpBlockSize) )
              {
                  /*record current system tick to check N_Bs timeout*/
                  udsTpCurrSysTick = SystemTickMs;        
                  /*switch to Wait FlowControl state*/
                  udsTpState = UDS_TP_WAIT_FC;
              }
		/*according to requirement, fill padding data */
		(void)memset(data, UDS_PADDING_BYTE, sizeof(data));
		/*set frame type and SN to byte 0*/
		data[0] = (uint8_t)UDS_CF;
		data[0] = data[0] << 4;
		data[0] += tpTxSN;
		/*increase SN by 1, but range is [0, F]*/
		tpTxSN ++;
		if(tpTxSN > 0xF)
		{
			tpTxSN = 0;
		}
		/*Maximum PDU in CF is 7 bytes*/
		cfValidLen = tpRspLen - tpRspCursor;
		if(cfValidLen > MAX_CF_LEN )
		{
			cfValidLen = MAX_CF_LEN;
		}
		(void)memcpy(&data[1], &tpRspBuf[tpRspCursor], cfValidLen);
		tpRspCursor += cfValidLen;
		/*all Consecutive frames are sent out, change TP layer state to idle*/
		if(tpRspCursor >= tpRspLen)
		{
			udsTpState = UDS_TP_IDLE;
		}
              udsTpTxSTMinTick = SystemTickMs;
		/*call CAN interface function to send UDS response*/
		CanTransmit_UDS(data);
	}
}

/*---------------------------------------------------------------------------
description: Assembly flow control frame according to ISO15765 and send
---------------------------------------------------------------------------*/
void udsTpSendFlowCtrl(uint8_t FS)
{
	uint8_t data[8];

	/*according to requirement, fill padding data */
	(void)memset(data, UDS_PADDING_BYTE, sizeof(data));

	/*set frame type and FS = 0*/
	data[0] = (uint8_t)(UDS_FC);
	//move to higher half byte
	data[0] = data[0] <<4;
	/*flow state*/
	data[0] = data[0] + (FS&0xF);
	/*set block size = 0*/
	data[1] = UDSTP_BS;
	/*set STmin = Tp_RX_STMIN*/
	data[2]  = Tp_RX_STMIN;
	
	/*call CAN interface function to send UDS response*/
	CanTransmit_UDS(data);
}
/* -----------------------------------------------------------------------------
 Global Misra Violation Restore
 ------------------------------------------------------------------------------*/

/* -----------------------------------------------------------------------------
 End of FILE uds_tp.c
 ------------------------------------------------------------------------------*/

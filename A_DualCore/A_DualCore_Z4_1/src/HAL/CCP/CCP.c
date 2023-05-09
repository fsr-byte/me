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
 * 2017 06 21: add the off line calibration feature: 
 read parameter record from specified flash,update the calibration paramters in RAM
 */

/*! @file uds_tp.c
 @brief  brief description on this source file, what is the function to be implemented
 @details details description on the function

  */
#define MASTER_CCP_

/* ==============================Includes====================================*/
#include "Typedefs.h"
#include "Global.h"
#include "NVM.h"
#include "ccp.h"
#include "cstring"
#include "CAN_Operation.h"
#include "EX_Define.h"

/* =====================Private Macro Definitions============================*/
/* Session Status */
#define SS_CAL                0x01
#define SS_DAQ                0x02
#define SS_RESUME             0x04
#define SS_TMP_DISCONNECTED   0x10
#define SS_CONNECTED          0x20
#define SS_STORE              0x40
#define SS_RUN                0x80

/* Priviledge Level */
#define PL_CAL 0x01
#define PL_DAQ 0x02
#define PL_PGM 0x40

#define MAX_CCP_SILENT_TIME  1500  /*1500 2ms ticks = 3s*/
#define CCP_STATION_ID_LENGTH	0x07	/*must be consistent with CCP_STATION_ID*/

#define SRAM_BASE_ADDR  0x40000000
#define SRAM_SIZE  0x3FFFF
/* ==================== Private function-like Macro==========================*/
#define CCP_SET_MTA(n,p) ccp.MTA[n] = p;

#define CCP_PS_GET_STATUS()	(ccp.ProtectionStatus)
#define CCP_PS_CLEAR()	(ccp.ProtectionStatus = 0)
#define CCP_PS_IS_CAL_UNLOCKED()	(0==(ccp.ProtectionStatus&PL_CAL)? FALSE:TRUE)
#define CCP_PS_IS_DAQ_UNLOCKED()	(0==(ccp.ProtectionStatus&PL_DAQ)? FALSE:TRUE)
#define CCP_PS_IS_PGM_UNLOCKED()	(0==(ccp.ProtectionStatus&PL_PGM)? FALSE:TRUE)
#define CCP_PS_IS_CAL_LOCKED()	(0==(ccp.ProtectionStatus&PL_CAL)? TRUE:FALSE)
#define CCP_PS_IS_DAQ_LOCKED()	(0==(ccp.ProtectionStatus&PL_DAQ)? TRUE:FALSE)
#define CCP_PS_IS_PGM_LOCKED()	(0==(ccp.ProtectionStatus&PL_PGM)? TRUE:FALSE)

#define MAX_DAQ_TRY_TIME    2  /*after DAQ transmission tried for 2 ms, give up*/
/* ===================== Private Type Definitions=========================*/

typedef enum CCP_SSCMD
{
    /* Basic */
    CCP_SSCMD_CONNECT, 
    CCP_SSCMD_TEMPDISCONNECT, 
    CCP_SSCMD_ENDSESSION, 
    CCP_SSCMD_INITDAQ, 
    CCP_SSCMD_STARTRUNNING, 
    CCP_SSCMD_STOPRUNNING
} CCP_SSCMD;


/* =================  Private Variable Declarations =========================*/


/* =================  Private Constant Declarations =========================*/

const uint8_t CCP_STATION_ID[] = {"MPCCCP"};


/* =================  Private Function Declarations =========================*/
void Ccp_TxMsgOnCANA(uint8_t Data[], uint8_t len,  uint32_t CAN_ID);
uint32_t Ccp_UINT8ToUINT32(uint8_t array[], uint8_t start);
boolean CcpMTA_IsWritable(uint32_t  addr, uint8_t size);
boolean CcpMTA_IsReadable(uint32_t  addr, uint8_t size);
boolean CcpSSM_IsNotTempDisconnected(uint8_t  SessionStatus);
boolean CcpSSM_IsConnected(uint8_t  SessionStatus);
boolean CcpSSM_IsRunning(uint8_t  SessionStatus);
void Ccp_CMDHandler_Disconnect(uint8_t *  cmd);
void Ccp_CMDHandler_Disconnect(uint8_t *  cmd);
void Ccp_CMDHandler_GetCcpVersion(uint8_t *  cmd);
void Ccp_CMDHandler_ExchangeID(uint8_t *  cmd);
void Ccp_CMDHandler_SetMTA(uint8_t *  cmd);
void Ccp_CMDHandler_Download(uint8_t *  cmd);
void Ccp_CMDHandler_Download6(uint8_t *  cmd);
void Ccp_CMDHandler_Upload(uint8_t *  cmd);
void Ccp_CMDHandler_ShortUpload(uint8_t *  cmd);
void Ccp_loadCalParamFromFlash(void);
void Ccp_CMDHandler_ProgAndProg6(uint8_t *  cmd);

#if CCP_MAX_DAQ>0
void CcpDAQ_StopAll(void);
void CcpDAQ_Stop(uint8_t daqListIndex);
uint8_t CcpDAQ_Clear(uint8_t daqListIndex);
void CcpDAQ_Prepare(uint8_t daqListIndex, uint8_t last, uint8_t eventChannel, uint16_t  prescaler);
void CcpDAQ_Start(uint8_t daqListIndex);
uint8_t CcpDAQ_SampleAndTxDtm(uint8_t daqIndex, uint8_t odtIndex);
void Ccp_CMDHandler_GetDaqSize(uint8_t *  cmd);
void Ccp_CMDHandler_SetDaqPtr(uint8_t *  cmd);
void Ccp_CMDHandler_WriteDaq(uint8_t *  cmd);
void Ccp_CMDHandler_StartStop(uint8_t * cmd);
#endif

/* =================  Global Variable Declarations =========================*/
Ccp ccp;

/* =================  Global Constant Declarations =========================*/


/* =================  Global Function implementation =========================*/


/* =================  Private Function implementation =========================*/
/*---------------------------------------------------------------------------
description: send response (command resposne or DAQ DTO)
input param:     None
---------------------------------------------------------------------------*/
uint8_t Ccp_SendRsponse(uint8_t Data[])
{
  uint8_t rslt = 0;
  VCU_CCP_msg.control.id = CCP_CRM_CAN_ID;
  VCU_CCP_msg.control.dlc = 8;
  VCU_CCP_msg.control.ide = 0;
  VCU_CCP_msg.control.rtr = 0;
  memcpy (VCU_CCP_msg.data.R8, Data, sizeof(VCU_CCP_msg.data.R8));
  rslt = CANTransimitRandomMessage (CcpRecvChannel, &VCU_CCP_msg);
  return rslt;

}
/*---------------------------------------------------------------------------
description: convert 4 bytes in a uint8 array into Motorola type uint32 variable
input param:     array -- the buffer that uint8 data, 
input param:     start  -- start position of useful data
return value:   the uint32 type value
---------------------------------------------------------------------------*/
uint32_t Ccp_UINT8ToUINT32(uint8_t array[], uint8_t start)
{
    uint32_t val = 0;
    uint8_t i = 0;

    for(i = 0; i < sizeof(uint32_t); i++)
    {
        val = val << 8;
        //val += (uint32_t)array[start+sizeof(uint32_t)-1 -i];
        val += (uint32_t)array[start+i];
    }
    return val;
}
/*---------------------------------------------------------------------------
description: check if the address can be written(only calibration RAM area can be written)
input param:     cmd -- received CCP command PDU 
---------------------------------------------------------------------------*/
boolean CcpMTA_IsWritable(uint32_t  addr, uint8_t size)
{
    if((addr >= CAL_DATA_RAM_ADDR) && ((addr + size) <= (CAL_DATA_RAM_ADDR + CAL_DATA_SIZE)))
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}
/*---------------------------------------------------------------------------
description: check if the address can be read
input param:     cmd -- received CCP command PDU 
---------------------------------------------------------------------------*/
boolean CcpMTA_IsReadable(uint32_t  addr, uint8_t size)
{
    if((addr >= SRAM_BASE_ADDR) && ((addr + size) <= (SRAM_BASE_ADDR + SRAM_SIZE)))
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}
/*---------------------------------------------------------------------------
description: check if the session status is NOT Temporary disconnected
input param:     cmd -- received CCP command PDU 
---------------------------------------------------------------------------*/
boolean CcpSSM_IsNotTempDisconnected(uint8_t  SessionStatus)
{
    if (0 == (SessionStatus & SS_TMP_DISCONNECTED))
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}
/*---------------------------------------------------------------------------
description: check if the session status is NOT connected
input param:     cmd -- received CCP command PDU 
---------------------------------------------------------------------------*/
boolean CcpSSM_IsConnected(uint8_t  SessionStatus)
{
    if (0 != (SessionStatus & SS_CONNECTED))
    {
        return TRUE;

    }
    else
    {
        return FALSE;
    }
}
/*---------------------------------------------------------------------------
description: check if the session status is running
input param:     cmd -- received CCP command PDU 
---------------------------------------------------------------------------*/
boolean CcpSSM_IsRunning(uint8_t  SessionStatus)
{
    if (0 != (SessionStatus & SS_RUN))
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}
/*---------------------------------------------------------------------------
description: change the CCP session status 
input param:     ssmptr -- pointer to session status
input param:     cmd -- received CCP command PDU 
---------------------------------------------------------------------------*/
void CcpSSM_ChangeSessionStatus(uint8_t* ssmptr, CCP_SSCMD cmd)
{
    switch (cmd)
    {
        case CCP_SSCMD_CONNECT:
            * ssmptr |= SS_CONNECTED;
            * ssmptr &= ~SS_TMP_DISCONNECTED;
            break;
        case CCP_SSCMD_TEMPDISCONNECT:
            * ssmptr &= ~SS_CONNECTED;
            * ssmptr |= SS_TMP_DISCONNECTED;
            break;
        case CCP_SSCMD_ENDSESSION:
            * ssmptr = 0;
            break;
        case CCP_SSCMD_INITDAQ:
            * ssmptr |= SS_DAQ;
            break;
        case CCP_SSCMD_STARTRUNNING:
            * ssmptr |= SS_RUN;
            break;
        case CCP_SSCMD_STOPRUNNING:
            * ssmptr &= ~SS_RUN;
            break;
        default:
            break;
    }
}
#if CCP_MAX_DAQ > 0
/*---------------------------------------------------------------------------
description: Stop all DAQ lists
input param:     None
---------------------------------------------------------------------------*/
void CcpDAQ_StopAll(void)
{
    uint8_t i = 0;

    for (i = 0; i < CCP_MAX_DAQ; i++)
    {
        ccp.DaqList[i].flags = 0;
    }

    CcpSSM_ChangeSessionStatus(&ccp.Ccp_Session_SM, CCP_SSCMD_STOPRUNNING);
}
/*---------------------------------------------------------------------------
description: Stop the specified DAQ List
input param:     DAQ list index
---------------------------------------------------------------------------*/
void CcpDAQ_Stop(uint8_t daqListIndex)
{
	uint8_t i = 0;
	uint8_t flag = 0;

	ccp.DaqList[daqListIndex].flags = 0;


	/* check if all DAQ lists are stopped */
	for (i = 0; i < CCP_MAX_DAQ; i++)
	{
		flag |= ccp.DaqList[i].flags;
	}

	if (0 == (flag & DAQ_FLAG_START))
	{
		CcpSSM_ChangeSessionStatus(&ccp.Ccp_Session_SM, CCP_SSCMD_STOPRUNNING);
	}
}
/*---------------------------------------------------------------------------
description: clear the specified DAQ List
input param:     DAQ list index
---------------------------------------------------------------------------*/
uint8_t CcpDAQ_Clear(uint8_t daqListIndex)
{
    uint8_t  * p;
    uint8_t  * pl;

    if (daqListIndex>=CCP_MAX_DAQ) 
    {
        return 0;
    }
    
    p = (uint8_t  *)&ccp.DaqList[daqListIndex];
    pl = p+sizeof(ccpDaqList_t);
    while (p < pl) 
    {
        *p++ = 0;
    }
    return CCP_MAX_ODT;
}
/*---------------------------------------------------------------------------
description: prepare parameters for the specified DAQ List
input param:     DAQ list index
---------------------------------------------------------------------------*/
void CcpDAQ_Prepare(uint8_t daqListIndex, uint8_t last, uint8_t eventChannel, uint16_t  prescaler)
{
    ccp.DaqList[daqListIndex].prescaler = prescaler;
    ccp.DaqList[daqListIndex].cycle = 0;
    ccp.DaqList[daqListIndex].last = last;
    ccp.DaqList[daqListIndex].flags |= DAQ_FLAG_PREPARED;
    ccp.DaqList[daqListIndex].eventChannel = eventChannel;
}
/*---------------------------------------------------------------------------
description: start the specified DAQ List: change its flag
input param:     DAQ list index
---------------------------------------------------------------------------*/
void CcpDAQ_Start(uint8_t daqListIndex)
{
    ccp.DaqList[daqListIndex].flags = DAQ_FLAG_START;
    CcpSSM_ChangeSessionStatus(&ccp.Ccp_Session_SM, CCP_SSCMD_STARTRUNNING);
}

/*---------------------------------------------------------------------------
description: start all  DAQ Lists: change its flag
input param:     DAQ list index
---------------------------------------------------------------------------*/
void CcpDAQ_StartAllPrepared(void)
{
	uint8_t i;
	for (i = 0; i < CCP_MAX_DAQ; i++)
	{
		if (0 != (DAQ_FLAG_PREPARED & ccp.DaqList[i].flags))
		{
			CcpDAQ_Start(i);
		}
	}
}
uint8_t CcpDAQ_SampleAndTxDtm(uint8_t daqIndex, uint8_t odtIndex)
{
#define dtm ccp.Dtm
uint8_t totalSize;
uint8_t i, j;
uint8_t * pDaqSrc;
uint8_t rslt;
uint32_t currTime;
    /*PID*/
    dtm[0] = daqIndex*CCP_MAX_ODT + odtIndex;

    totalSize= 0;
    /*loop through the 7 elements of current DAQ list and DAQ ODT*/
    for(i = 0; i < 7; i++)
    {
        if(NULL != ccp.DaqList[daqIndex].odt[odtIndex][i].ptr)
        {
            pDaqSrc = ccp.DaqList[daqIndex].odt[odtIndex][i].ptr;
            for(j = 0; j < ccp.DaqList[daqIndex].odt[odtIndex][i].size; j++)
            {
                dtm[1 +totalSize] = *pDaqSrc;
                pDaqSrc++;
                totalSize ++;
                if(totalSize > 7)
                {
                    break;
                }
            }
        }
        if(totalSize > 7)
        {
            break;
        }
    }
    /*Tx CAN message*/
    rslt = 0;
    currTime = SystemTickMs;
    while(rslt == 0)
    {
        rslt = Ccp_SendRsponse(dtm);
        if((SystemTickMs - currTime) > MaxDaqRetryTime)
        {
            break;
        }
    }
    
    return rslt;
#undef dtm    
}
#endif
/*---------------------------------------------------------------------------
description: CCP CONNECT command handler
input param:     cmd -- received CCP command PDU 
---------------------------------------------------------------------------*/
void Ccp_CMDHandler_Connect(uint8_t *  cmd)
{
#define stationAddr (*(uint16_t *)&cmd[2]) /* Has to be Intel-Format ! */
#define ctr    cmd[1]


    /* This station */
    if ((stationAddr == CCP_STATION_ADDR) || (stationAddr == CCP_BROADCAST_STATION_ADDR))
    { /* This station */


#if CCP_MAX_DAQ>0
        if (CcpSSM_IsNotTempDisconnected(ccp.Ccp_Session_SM))
        {
            CcpDAQ_StopAll();
        }
#endif

        CcpSSM_ChangeSessionStatus(&ccp.Ccp_Session_SM, CCP_SSCMD_CONNECT);


        /* Response */
        /* Station addresses in Intel Format */
        ccp.Crm[1] = CRC_OK;
        /*additional info*/
        ccp.Crm[3] = PID_Evt;
        *(uint16_t *) &ccp.Crm[4] = CCP_STATION_ADDR;
        *(uint16_t *) &ccp.Crm[6] = CCP_BROADCAST_STATION_ADDR;
    }
    else /* Another station */
    {
        /* If connected, temporary disconnect */
        if (CcpSSM_IsConnected(ccp.Ccp_Session_SM))
        {
            CcpSSM_ChangeSessionStatus(&ccp.Ccp_Session_SM, CCP_SSCMD_TEMPDISCONNECT);
        }
        else
        {
            /*
             * nothing to do, just ignore the command
             */
        }
    }


#undef stationAddr
#undef ctr
}
/*---------------------------------------------------------------------------
description: CCP DISCONNECT command handler
input param:     cmd -- received CCP command PDU 
---------------------------------------------------------------------------*/
void Ccp_CMDHandler_Disconnect(uint8_t *  cmd)
{
#define tempDisconnect 0x00
#define endOfSession 0x01
#define disconnectCmd cmd[2]
#define disconnectStationAddr (*(uint16_t *)&cmd[4])
    /*no check on slave address,
     *since all following protocol commands refer to this station only
     *refer to 12.1 Connect command*/
    if (tempDisconnect == disconnectCmd)
    {
        CcpSSM_ChangeSessionStatus(&ccp.Ccp_Session_SM, CCP_SSCMD_TEMPDISCONNECT);
    }
    else if (endOfSession == disconnectCmd)
    { /* End of session */
        CcpSSM_ChangeSessionStatus(&ccp.Ccp_Session_SM, CCP_SSCMD_ENDSESSION);


#if (CCP_MAX_DAQ > 0)
        CcpDAQ_StopAll();
#endif


#if (CCP_SEED_KEY == ON)
        CCP_PS_CLEAR();
#endif
    }
    else
    {
        ccp.Crm[1] = CRC_OUT_OF_RANGE;
    }


#undef tempDisconnect
#undef endOfSession
#undef disconnectCmd
#undef disconnectStationAddr
}
/*---------------------------------------------------------------------------
description: CCP GET_VERSION command handler
input param:     cmd -- received CCP command PDU 
---------------------------------------------------------------------------*/
void Ccp_CMDHandler_GetCcpVersion(uint8_t *  cmd)
{
    ccp.Crm[3] = CCP_VERSION_MAJOR;
    ccp.Crm[4] = CCP_VERSION_MINOR;
}
/*---------------------------------------------------------------------------
description: CCP EXCHANGE_ID command handler
input param:     cmd -- received CCP command PDU 
---------------------------------------------------------------------------*/
void Ccp_CMDHandler_ExchangeID(uint8_t *  cmd)
{
#define masterId cmd[2]

    ccp.Crm[3] = CCP_STATION_ID_LENGTH;
    ccp.Crm[4] = 0; /*no meaning*/
    /* Build the Resource Availability Mask */
    ccp.Crm[5] = PL_CAL; /* Default: Calibration available */
#if (CCP_MAX_DAQ > 0)
    ccp.Crm[5] |= PL_DAQ;
#endif
#if (CCP_PROGRAM ==ON)
    ccp.Crm[5] |= PL_PGM;
#endif
    /* Build the Resource Protection Mask */
    ccp.Crm[6] = 0; /* Default: No Protection */
#if (CCP_SEED_KEY == ON)
    ccp.Crm[6] |= PL_CAL; /* Protected Calibration */
#if (CCP_MAX_DAQ > 0)
    ccp.Crm[6] |= PL_DAQ;
#endif
#if (CCP_PROGRAM ==ON)
    ccp.Crm[6] |= PL_PGM;
#endif
#endif /*(CCP_SEED_KEY == ON)*/

    CCP_SET_MTA(0, (uint32_t )CCP_STATION_ID);
#undef masterId
}
/*---------------------------------------------------------------------------
description: CCP SET_MTA command handler
input param:     cmd -- received CCP command PDU 
---------------------------------------------------------------------------*/
void Ccp_CMDHandler_SetMTA(uint8_t *  cmd)
{
#define mta     cmd[2]
#define addrExt cmd[3]
//#define addr    ((uint32_t)cmd[4])
uint32_t addr;
#if 0
uint8_t i;
#endif

    if (mta < CCP_MAX_MTA)
    {
        /*calculate MTA*/
#if 0        
        addr = 0;
        for(i = 0; i < sizeof(addr); i++)
        {
            addr = addr << 8;
            addr += cmd[4+i];
        }
#endif
        addr = Ccp_UINT8ToUINT32(cmd,  4);
        if (CcpMTA_IsWritable( addr, 1) || CcpMTA_IsReadable( addr, 1))
        {
            ccp.MTA[mta] = addr;
        }
        else
        {
            ccp.Crm[1] = CRC_ACCESS_DENIED;
        }
    }
    else
    {
        ccp.Crm[1] = CRC_OUT_OF_RANGE;
    }


#undef mta
#undef addrExt
//#undef addr
}
/*---------------------------------------------------------------------------
description: CCP DOWNLOAD command handler
input param:     cmd -- received CCP command PDU 
---------------------------------------------------------------------------*/
void Ccp_CMDHandler_Download(uint8_t *  cmd)
{
#define size cmd[2]
#define pdata &cmd[3]
#define MAXLEN    5

uint8_t i;
uint8_t * pDest;
uint32_t MtaAddr;
//uint32_t addrtemp = 0;

#if (CCP_SEED_KEY == ON)
    if (FALSE == CCP_PS_IS_CAL_UNLOCKED())
    {
        ccp.Crm[1] = CRC_KEY_REQUEST;
    }
    else
    {
#endif
        if (size <= MAXLEN)
        {
            if (CcpMTA_IsWritable(ccp.MTA[0], size))
            {
        	//addrtemp = ccp.MTA[0];
                pDest = (uint8_t *) ccp.MTA[0];
                for (i = 0; i < size; i++)
                {
                    *pDest = cmd[3+i];
                    pDest ++;
                }
                /*increase MTA0 by size*/
                ccp.MTA[0] = ccp.MTA[0] + size;
                /*assign MTA[0] to Crm[4]~ Crm[7]*/
                MtaAddr = ccp.MTA[0];
                for( i = 0 ; i < sizeof(MtaAddr); i++)
                {
                    ccp.Crm[7-i] = (uint8_t)MtaAddr;
                    MtaAddr = MtaAddr >>8;
                }

               /*  当标定区间在BSW和DHP模块内时，需要重启Core0  */
               /*according to bug 1626, don't re-start core0 even BSW or DHP is being calibrated */
#if 0               
                if( ((addrtemp >=BSWCalRamAddrStart) && (addrtemp < (BSWCalRamAddrStart + BSWCalRamAddrSize)))
                    || ((addrtemp >=DHPCalRamAddrStart) && (addrtemp < (DHPCalRamAddrStart + DHPCalRamAddrSize))) )
                  {
                    Set_SI0(); //使用软件中断通知Core0进行重启操作。
                  }
#endif
            }
            else
            {
                 ccp.Crm[1] = CRC_ACCESS_DENIED;
            }
        }
        else
        {
            ccp.Crm[1] = CRC_OUT_OF_RANGE;
        }
#if (CCP_SEED_KEY == ON)
    }
#endif
#undef size
#undef pdata
#undef MAXLEN
}
/*---------------------------------------------------------------------------
description: CCP DOWNLOAD6 command handler
input param:     cmd -- received CCP command PDU 
---------------------------------------------------------------------------*/
void Ccp_CMDHandler_Download6(uint8_t *  cmd)
{
#define size 6
#define pdata &cmd[2]
uint8_t i;
uint8_t * pDest;
uint32_t MtaAddr;
//uint32_t addrtemp = 0;

#if (CCP_SEED_KEY == ON)
    if (FALSE == CCP_PS_IS_CAL_UNLOCKED())
    {
        ccp.Crm[1] = CRC_KEY_REQUEST;
    }
    else
    {
#endif
        if (CcpMTA_IsWritable(ccp.MTA[0], size))
        {
            //addrtemp = ccp.MTA[0];
            pDest = (uint8_t *) ccp.MTA[0];
            for (i = 0; i < size; i++)
            {
                *pDest = cmd[3+i];
                pDest ++;
            }
            /*increase MTA0 by size*/
            ccp.MTA[0] = ccp.MTA[0] + size;
            /*assign MTA[0] to Crm[4]~ Crm[7]*/
            MtaAddr = ccp.MTA[0];
            for( i = 0 ; i < sizeof(MtaAddr); i++)
            {
                ccp.Crm[7-i] = (uint8_t)MtaAddr;
                MtaAddr = MtaAddr >>8;
            }

            /*  当标定区间在BSW和DHP模块内时，需要重启Core0  */
            /*according to bug 1626, don't re-start core0 even BSW or DHP is being calibrated */
#if 0            
             if( ((addrtemp >=BSWCalRamAddrStart) && (addrtemp < (BSWCalRamAddrStart + BSWCalRamAddrSize)))
                 || ((addrtemp >=DHPCalRamAddrStart) && (addrtemp < (DHPCalRamAddrStart + DHPCalRamAddrSize))) )
               {
                 Set_SI0(); //使用软件中断通知Core0进行重启操作。
               }
#endif               
        }
        else
        {
            ccp.Crm[1] = CRC_ACCESS_DENIED;
        }

#if (CCP_SEED_KEY == ON)
    }
#endif
#undef size
#undef pdata
}
/*---------------------------------------------------------------------------
description: CCP UPLOAD command handler
input param:     cmd -- received CCP command PDU 
---------------------------------------------------------------------------*/
void Ccp_CMDHandler_Upload(uint8_t *  cmd)
{
#define size cmd[2]
#define pdata &(ccp.Crm[3])
#define MAXLEN    5

uint8_t i;
uint8_t * pSrc;

#if (CCP_SEED_KEY == ON)
    if (FALSE == CCP_PS_IS_CAL_UNLOCKED())
    {
        ccp.Crm[1] = CRC_KEY_REQUEST;
    }
    else
    {
#endif
        if (size <= MAXLEN)
        {
            if (CcpMTA_IsReadable(ccp.MTA[0], size))
            {
                pSrc  = (uint8_t*)ccp.MTA[0];
                for (i = 0; i < size; i++)
                {
                    ccp.Crm[3+i] = *pSrc;
                    pSrc++;
                }
                ccp.MTA[0] = ccp.MTA[0] + size;
            }
            else
            {
                ccp.Crm[1] = CRC_ACCESS_DENIED;
            }
        }
        else
        {
            ccp.Crm[1] = CRC_OUT_OF_RANGE;
        }
#if (CCP_SEED_KEY == ON)
    }
#endif
#undef size
#undef pdata
#undef MAXLEN
}
/*---------------------------------------------------------------------------
description: CCP SHORT_UP command handler
input param:     cmd -- received CCP command PDU 
---------------------------------------------------------------------------*/
void Ccp_CMDHandler_ShortUpload(uint8_t *  cmd)
{
#define size    cmd[2]
#define addrExt cmd[3]
//#define addr    ((uint32_t)cmd[4])
#define pdata &(ccp.Crm[3])
#define MAXLEN    5
uint8_t i;
uint8_t * pSrc;

uint32_t addr;

#if (CCP_SEED_KEY == ON)
    if (FALSE == CCP_PS_IS_CAL_UNLOCKED())
    {
        ccp.Crm[1] = CRC_KEY_REQUEST;
    }
    else
    {
#endif
        if (size <= MAXLEN)
        {

            addr = Ccp_UINT8ToUINT32(cmd,  4);
            if (CcpMTA_IsReadable( addr, size))
            {
                pSrc  = (uint8_t*)addr;
                for (i = 0; i < size; i++)
                {
                    ccp.Crm[3+i] = *pSrc;
                    pSrc++;
                }
            }
            else
            {
                ccp.Crm[1] = CRC_ACCESS_DENIED;
            }
        }
        else
        {
            ccp.Crm[1] = CRC_OUT_OF_RANGE;
        }
#if (CCP_SEED_KEY == ON)
    }
#endif


#undef size
#undef addrExt
#undef addr
#undef pdata
#undef MAXLEN
}
/*---------------------------------------------------------------------------
description: CCP GET_SEED command handler
input param:     cmd -- received CCP command PDU 
---------------------------------------------------------------------------*/
void Ccp_CMDHandler_GetSeed(uint8_t *  cmd)
{
#define privilegeLevel cmd[2]
    ccp.Crm[3] = 0; /* Protection Status: No key required */
    *(uint32_t*) &ccp.Crm[4] = 0;
#if (CCP_SEED_KEY == ON)
    /* Keys required for CAL or PGM */
    switch (privilegeLevel)
    {
        case PL_CAL:
            ccp.Crm[3] = CCP_PS_IS_CAL_LOCKED(); /* Protection Status */
            *(uint32_t*) &ccp.Crm[4] = ccpGetSeed(PL_CAL);
            break;
        case PL_PGM:
            ccp.Crm[3] = CCP_PS_IS_PGM_LOCKED(); /* Protection Status */
            *(uint32_t*) &ccp.Crm[4] = ccpGetSeed(PL_PGM);
            break;
        case PL_DAQ:
            ccp.Crm[3] = CCP_PS_IS_DAQ_LOCKED(); /* Protection Status */
            *(uint32_t*) &ccp.Crm[4] = ccpGetSeed(PL_DAQ);
            break;
        default:
            ccp.Crm[1] = CRC_CMD_SYNTAX;
            /* Error */
    }
#endif
#undef privilegeLevel
}
/*---------------------------------------------------------------------------
description: CCP UNLOCK command handler
input param:     cmd -- received CCP command PDU 
---------------------------------------------------------------------------*/
#if (CCP_SEED_KEY == ON)
void Ccp_CMDHandler_Unlock(uint8_t *  cmd)
{
#define key cmd[2] /* Key may be up to 6 Bytes */
    /* Check key */
    ccp.ProtectionStatus |= ccpUnlock(&key); /* Reset the appropriate resource protection mask bit */
    ccp.Crm[3] = ccp.ProtectionStatus; /* Current Protection Status */
#undef key
}
#endif
/*---------------------------------------------------------------------------
description: CCP TEST command handler
input param:     cmd -- received CCP command PDU 
---------------------------------------------------------------------------*/
void Ccp_CMDHandler_Test(uint8_t *  cmd)
{
#define stationAddr (*(uint16_t *)&cmd[2])

    if(CCP_STATION_ADDR == stationAddr )
    {
        ccp.Crm[1] = CRC_OK;
    }
    else
    {
        ccp.Crm[1] = CRC_NOK;
    }
#undef stationAddr
}

/*---------------------------------------------------------------------------
description: simple logic for get seed
input param:     cmd -- received CCP command PDU 
---------------------------------------------------------------------------*/
#if CCP_SEED_KEY == ON
uint32_t ccpGetSeed(uint8_t resourceMask)
{
    /* Simple example: No algorithm is used here for calculating different seeds! */
    if (resourceMask == PL_CAL)
        return 0x22;
    /* Returns the seed for CALIBRATION ACCESS */
    if (resourceMask == PL_DAQ)
        return 0x55;
    /* Returns the seed for enabling the DATA AQCUISITION */
    if (resourceMask == PL_PGM)
        return 0x99;
    /* Returns the seed for FLASH PROGRAMMING */
    return 0;
}

/*---------------------------------------------------------------------------
description: simple logic for comparing key
input param:     cmd -- received CCP command PDU 
---------------------------------------------------------------------------*/
uint8_t ccpUnlock(uint8_t *key)
{
    /* Simple example: No algorithm is used here for checking the correct key */
    uint32_t test = *((uint32_t*) key);

    /* Check the key for CALIBRATION ACCESS */
    if (test == 0x22)
        return PL_CAL;
    /* Check the key for enabling the DATA AQCUISITION */
    if (test == 0x55)
        return PL_DAQ;
    /* Check the key for FLASH PROGRAMMING */
    if (test == 0x99)
        return PL_PGM;

    /* Key is not correct -> return 0 */
    return 0;
}
#endif /*CCP_SEED_KEY == ON*/

#if CCP_MAX_DAQ > 0
/*---------------------------------------------------------------------------
description: CCP GET_DAQ_SIZE command handler
input param:     cmd -- received CCP command PDU 
---------------------------------------------------------------------------*/
void Ccp_CMDHandler_GetDaqSize(uint8_t *  cmd)
{
#define daqListIdx cmd[2]
#define daqId   (*(uint32_t*)&cmd[4])

#if (CCP_SEED_KEY == ON)
    if (FALSE == CCP_PS_IS_DAQ_UNLOCKED())
    {
        ccp.Crm[1] = CRC_KEY_REQUEST;
    }
    else
    {
#endif


#if (CCP_MAX_DAQ > 0)
        if (daqListIdx < CCP_MAX_DAQ)
        {
            CcpDAQ_Stop(daqListIdx); /* Stop this daq list */
            ccp.Crm[3] = CcpDAQ_Clear(daqListIdx); /* Number of  ODTs */
            ccp.Crm[4] = daqListIdx*CCP_MAX_ODT; /* PID of the first ODT */
            /*calculate the specified CAN_ID*/
            ccp.DaqList[daqListIdx].daqCanId = Ccp_UINT8ToUINT32(cmd,  4);
        }
        else
        {
            ccp.Crm[3] = 0;
            ccp.Crm[4] = 0;
            ccp.Crm[1] = CRC_OUT_OF_RANGE;
        }
#else
        ccp.Crm[3] = 0;
        ccp.Crm[4] = 0;
#endif
#if (CCP_SEED_KEY == ON)
    }
#endif


#undef daqListIdx
#undef daqId
}
/*---------------------------------------------------------------------------
description: CCP SET_DAQ_PTR command handler
input param:     cmd -- received CCP command PDU 
---------------------------------------------------------------------------*/
void Ccp_CMDHandler_SetDaqPtr(uint8_t *  cmd)
{
    #define Daq  cmd[2]
    #define Odt  cmd[3]
    #define Idx  cmd[4]
    if( (Daq>=CCP_MAX_DAQ)||(Odt>=CCP_MAX_ODT)||(Idx>7) )
	{
        ccp.Crm[1] = CRC_CMD_SYNTAX;
        ccp.DaqListPtr = 0;
    } 
	else 
	{
        ccp.DaqListPtr = &ccp.DaqList[Daq].odt[Odt][Idx];
    }

    #undef Daq
    #undef Odt
    #undef Idx
}
/*---------------------------------------------------------------------------
description: CCP WRITE_DAQ command handler
input param:     cmd -- received CCP command PDU 
---------------------------------------------------------------------------*/
void Ccp_CMDHandler_WriteDaq(uint8_t *  cmd)
{
    #define writeDaqSize    cmd[2]
    #define writeDaqAddrExt cmd[3]
    #define writeDaqAddr    (*(uint32_t*)&cmd[4])
    uint32_t addr;

    /*calculate MTA*/
    addr = Ccp_UINT8ToUINT32(cmd,  4);
    if (ccp.DaqListPtr == 0)
    {
        ccp.Crm[1] = CRC_CMD_SYNTAX;
    }
    else if ((FALSE == CcpMTA_IsReadable((uint32_t) addr, writeDaqSize)) || ((writeDaqSize != 1) && (writeDaqSize != 2)
        && (writeDaqSize != 4)))
    {
        ccp.Crm[1] = CRC_OUT_OF_RANGE;
    }
    else
    {
        ccp.DaqListPtr->ptr =  (uint8_t*) addr;
        ccp.DaqListPtr->size = writeDaqSize;
        ccp.DAQUpdated = TRUE;
    }
    #undef writeDaqSize
    #undef writeDaqAddrExt
    #undef writeDaqAddr
}
/*---------------------------------------------------------------------------
description: CCP START_STOP command handler
input param:     cmd -- received CCP command PDU 
---------------------------------------------------------------------------*/
void Ccp_CMDHandler_StartStop(uint8_t * cmd)
{
#define ssCmd       cmd[2]  /* Start or Stop */
#define ssDaq       cmd[3]  /* DAQ list */
#define ssLast      cmd[4]  /* Last ODT to send */
#define ssEventChannel        cmd[5]  /* Event Channel Number */

   uint16_t ssPrescaler = 0;
#if (CCP_SEED_KEY == ON)
    if (FALSE == CCP_PS_IS_DAQ_UNLOCKED())
    {
        ccp.Crm[1] = CRC_KEY_REQUEST;
    }
    else
    {
#endif


#if (CCP_MAX_DAQ > 0)
        if (ssDaq >= CCP_MAX_DAQ )
        {
            ccp.Crm[1] = CRC_OUT_OF_RANGE;
        }
        else
        {
            ssPrescaler = (uint16_t)cmd[6]; 
            ssPrescaler =  ssPrescaler << 8;
            ssPrescaler =  ssPrescaler +  (uint16_t)cmd[7]; 
            if( (0 == ssPrescaler) || (ssEventChannel >= CCP_MAX_EVENT_CHANNEL) )
            {
                ccp.Crm[1] = CRC_OUT_OF_RANGE;
            }
            else
            {
            switch (ssCmd)
            {
                case 0: /* stop */
                    CcpDAQ_Stop(ssDaq);
                break;
                case 1: /* start */
                    CcpDAQ_Prepare(ssDaq, ssLast, ssEventChannel, ssPrescaler);
                    CcpDAQ_Start(ssDaq);
                break;
                case 2: /* prepare */
                    CcpDAQ_Prepare(ssDaq, ssLast, ssEventChannel, ssPrescaler);
                break;
                default:
                    ccp.Crm[1] = CRC_CMD_SYNTAX;
              break;
            }
            }
        }
#else
        ccp.Crm[1] = CRC_ACCESS_DENIED;
#endif


#if (CCP_SEED_KEY == ON)
    }
#endif


#undef ssCmd
#undef ssDaq
#undef ssLast
#undef ssEventChannel
#undef ssPrescaler

}
/*---------------------------------------------------------------------------
description: CCP START_STOP_ALL command handler: start the periodic transmission of all DAQ lists
configured with the previously sent START_STOP command 
Or stop the periodic transmission of all DAQ lists, including those not started synchronized. 
input param:     cmd -- received CCP command PDU 
---------------------------------------------------------------------------*/
void Ccp_CMDHandler_StartStopAll(uint8_t * cmd)
{
#define ssCmd       cmd[2]  /* Start or Stop */


#if (CCP_SEED_KEY == ON)
    if (FALSE == CCP_PS_IS_DAQ_UNLOCKED())
    {
        ccp.Crm[1] = CRC_ACCESS_DENIED;
    }
    else
    {
#endif


#if (CCP_MAX_DAQ > 0)

        switch (ssCmd)
        {
            case 0: /* stop */
                CcpDAQ_StopAll();
            break;
            case 1: /* start prepared DAQ*/
                CcpDAQ_StartAllPrepared();
            break;
            default:
                ccp.Crm[1] = CRC_OUT_OF_RANGE;
            break;
        }
#else
        ccp.Crm[1] = CRC_ACCESS_DENIED;
#endif


#if (CCP_SEED_KEY == ON)
    }
#endif


#undef ssCmd
}

#endif

void Ccp_CMDHandler_GET_CAL_PAGE(void)
{
  ccp.Crm[3] = 0; /* Address Extension */
  //*(uint32_t*)&ccp.Crm[4] = CAL_DATA_RAM_ADDR; /* Address */
  *(uint32_t*)&ccp.Crm[4] = 0; /* Address */
}

/*---------------------------------------------------------------------------
description: initialize CCP module
input param:    None
output param:   None
return value:   None
---------------------------------------------------------------------------*/
void Ccp_Init(void)
{
    memset(&ccp, 0, sizeof(Ccp));
    /*set initialization flag*/
    ccp.IsInitialized = TRUE;    
}
/*---------------------------------------------------------------------------
description: initialize CCP module
input param:    None
output param:   None
return value:   None
---------------------------------------------------------------------------*/
void Ccp_CopyNewCmd(uint8_t  CANRxData[])
{
    memcpy(ccp.Cro, CANRxData, sizeof(ccp.Cro));
     ccp.HasNewCro = TRUE;
}
/*---------------------------------------------------------------------------
description: main handler of CCP commands
input param:    None
output param:   None
return value:   None
---------------------------------------------------------------------------*/
void Ccp_CMDHandler(uint8_t CANRxData[])
{
#define ctr ccp.Cro[1]
#define cmd ccp.Cro     
    boolean lwasConnected;

    if(FALSE == ccp.HasNewCro)
    {
        return;
    }
    ccp.HasNewCro = FALSE;
    
    lwasConnected = CcpSSM_IsConnected(ccp.Ccp_Session_SM);

    memset(ccp.Crm, 0, 8);
    ccp.Crm[1] = CRC_OK; /*set OK by default, will be updated if error occurs*/

    switch (cmd[0])
    {
        case CCP_CMD_CONNECT:
            Ccp_CMDHandler_Connect(cmd);
            break;
        case CCP_CMD_TEST:
            Ccp_CMDHandler_Test(cmd);
            break;
        default:
            break;
    };    
    /*
     * commands other than CONNECT should be handled after being connected
     */
    if (TRUE == lwasConnected)
    {
        switch (cmd[0])
        {
            case CCP_CMD_CONNECT:
                Ccp_CMDHandler_Connect(cmd);
                break;
            case CCP_CMD_SET_MTA:
                Ccp_CMDHandler_SetMTA(cmd);
            break;
            case CCP_CMD_DNLOAD:
                Ccp_CMDHandler_Download(cmd);
            break;
            case CCP_CMD_DNLOAD6:
                Ccp_CMDHandler_Download6(cmd);
            break;
            case CCP_CMD_UPLOAD:
                Ccp_CMDHandler_Upload(cmd);
            break;
            case CCP_CMD_START_STOP:
                Ccp_CMDHandler_StartStop(cmd);
            break;
            case CCP_CMD_DISCONNECT:
                Ccp_CMDHandler_Disconnect(cmd);
            break;
            case CCP_CMD_GET_DAQ_SIZE:
                Ccp_CMDHandler_GetDaqSize(cmd);
            break;
            case CCP_CMD_SET_DAQ_PTR:
                Ccp_CMDHandler_SetDaqPtr(cmd);
            break;
            case CCP_CMD_WRITE_DAQ:
                Ccp_CMDHandler_WriteDaq(cmd);
            break;
            case CCP_CMD_EXCHANGE_ID:
                Ccp_CMDHandler_ExchangeID(cmd);
            break;
            case CCP_CMD_GET_CCP_VERSION:
                Ccp_CMDHandler_GetCcpVersion(cmd);
            break;
            case CCP_CMD_SHORT_UPLOAD:
                Ccp_CMDHandler_ShortUpload(cmd);
            break;
            case CCP_CMD_BUILD_CHKSUM:
//      Ccp_CMDHandler_Build_Chksum(cmd);
            break;
#if (CCP_SEED_KEY == ON)
            case CCP_CMD_GET_SEED:
                Ccp_CMDHandler_GetSeed(cmd);
            break;
            case CCP_CMD_UNLOCK:
                Ccp_CMDHandler_Unlock(cmd);
            break;
#endif
            case CCP_CMD_START_STOP_ALL:
                Ccp_CMDHandler_StartStopAll(cmd);
            break;
            case CCP_CMD_TEST:
                Ccp_CMDHandler_Test(cmd);
            break;

            case CCP_CMD_SET_CAL_PAGE:
                ccp.Crm[1] = 0x00;    /*CCP V2.1 P28 Command Return Code = ACKNOWLEDGE 0x00*/
            break;
      /* Flash Programming */
            case CCP_CMD_CLEAR_MEMORY: /* Clear Memory */
          /*  add support Store Calibration parameters into internal EEPROM   */
          /*clear the EEPROM calibration block valid flag*/
                ccp.Crm[1] =  CRC_OK;
            break;
            case CCP_CMD_PROGRAM:
            case CCP_CMD_PROGRAM6:
               Ccp_CMDHandler_ProgAndProg6(cmd);
            break;
            
            case CCP_CMD_GET_CAL_PAGE:/* Get Active Calibration Page */
              Ccp_CMDHandler_GET_CAL_PAGE();
              break;

            default:
                ccp.Crm[1] = CRC_CMD_UNKNOWN;
            break;
        }
    }

     /* set common part of CRM */
    ccp.Crm[0] = PID_CRM;
    ccp.Crm[2] = ctr;


    /*
     * send CRM to CAN. in case of disconnect, send CRM for the first time
     */
    Ccp_SendRsponse(ccp.Crm);

#undef ctr    
#undef cmd    
}
#if CCP_MAX_DAQ > 0

/*---------------------------------------------------------------------------
description: Fast speed DAQ event handler, to improve performance, DAQ List 0 are designed to support fast event
input param:    evtChannel , must be compatible with CANApe setting and main() function
output param:   None
return value:   None
---------------------------------------------------------------------------*/
void CcpDAQ_FastEventHandler(uint8_t evtChannel)
{
    uint8_t j;
	/*do nothing if session is not in run status*/
    if (FALSE == CcpSSM_IsRunning(ccp.Ccp_Session_SM))
    {
        return;
    }
    /*ignore not started DAQ list*/
    if (0 == (ccp.DaqList[0].flags & DAQ_FLAG_START))
    {
        return;
    }


    /*not prescaled to run, just skip*/
    ccp.DaqList[0].cycle ++;
    if(ccp.DaqList[0].cycle < ccp.DaqList[0].prescaler)
    {
        return;
    }
    ccp.DaqList[0].cycle = 0;
    for(j = 0; j <= ccp.DaqList[0].last; j++)
    {
        CcpDAQ_SampleAndTxDtm(0, j);
    }    
}

/*---------------------------------------------------------------------------
description: middle speed DAQ event handler, to improve performance, DAQ List 1 are designed to support middle speed event
input param:    evtChannel , must be compatible with CANApe setting and main() function
output param:   None
return value:   None
---------------------------------------------------------------------------*/
void CcpDAQ_MiddleEventHandler(uint8_t evtChannel)
{
    uint8_t j;
	/*do nothing if session is not in run status*/
    if (FALSE == CcpSSM_IsRunning(ccp.Ccp_Session_SM))
    {
        return;
    }
    /*ignore not started DAQ list*/
    if (0 == (ccp.DaqList[1].flags & DAQ_FLAG_START))
    {
        return;
    }

    /*not prescaled to run, just skip*/
    ccp.DaqList[1].cycle ++;
    if(ccp.DaqList[1].cycle < ccp.DaqList[1].prescaler)
    {
        return;
    }
    ccp.DaqList[1].cycle = 0;
    for(j = 0; j <= ccp.DaqList[1].last; j++)
    {
        CcpDAQ_SampleAndTxDtm(1, j);
    }    
}

#endif
/*---------------------------------------------------------------------------
description: CCP Program or program6  command handler, copy data into calibration area at then end write into EEPROM
input param:     cmd -- received CCP command PDU 
---------------------------------------------------------------------------*/
void Ccp_CMDHandler_ProgAndProg6(uint8_t *  cmd)
{
    uint8_t size;
    uint32_t CroProgStart;
    #define realCmd cmd[0]
    if( (ccp.MTA[0] >=CAL_DATA_RAM_ADDR) && (ccp.MTA[0] <= (CAL_DATA_RAM_ADDR + CAL_DATA_SIZE)) )
    {
         if(CCP_CMD_PROGRAM == realCmd)
         {
             size = cmd[2];
             CroProgStart = 3;   /*data to be programed start from 3*/
         }
         else
         {
             size = 6;
             CroProgStart = 2;   /*data to be programed start from 3*/
         }
         (void)memcpy((uint8_t*)ccp.MTA[0], &cmd[CroProgStart], size);
         ccp.MTA[0] =  ccp.MTA[0] + size;
         if(0 == size)
         {
              /*write the calibration data and flag*/
        	//@@@@WriteCalDatalntoDFlash();
         }
    }
    else
    {
        ccp.Crm[1] = CRC_OUT_OF_RANGE;
    }

}
/* -----------------------------------------------------------------------------
 Global Misra Violation Restore
 ------------------------------------------------------------------------------*/

/* -----------------------------------------------------------------------------
 End of FILE uds_tp.c
 ------------------------------------------------------------------------------*/

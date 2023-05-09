#include "derivative.h"      /* derivative-specific definitions */
#include "typedefs.h"
#include "CAN.h"
#include "Global.h"
#include "CAN_Operation.h"
#include "cstring"

static _CAN_MESSAGE_ VCU_UDS_msg;
static uint8_t  reSendUDS;   /*1: the UDS message should be resent*/
/***************************************************************************************************************
 * Name:        CanTransmit_UDS
 * Function:    called by Tp Layer to send UDS raw data
 * Input:        pTxdata: pointer to data to be sent
 * output:        VCU_UDS_msg: message data and Id etc
 * output:        reSendUDS: 1: the UDS message should be resent; 0: don't need to be resent
 * Return:        null
 * Link:        
 * Attention:    
 ************************************************************************************************************* */
void CanTransmit_UDS (unsigned char *pTxdata)
{
  uint8_t sendRslt;
  VCU_UDS_msg.control.id = gblUdsRspID;
  VCU_UDS_msg.control.dlc = 8;
  VCU_UDS_msg.control.ide = 0;
  if (HW_udsDiag_flag)
    {
      VCU_UDS_msg.control.ide = 1;
    }
  VCU_UDS_msg.control.rtr = 0;

  (void) memcpy (VCU_UDS_msg.data.R8, pTxdata, sizeof(VCU_UDS_msg.data.R8));
  sendRslt = CANTransimitRandomMessage (UdsRecvChannel, &VCU_UDS_msg);
  reSendUDS = 0;
  if( 0!= sendRslt)
  {
      reSendUDS = 1;
  }
}
/***************************************************************************************************************
 * Name:        UdsResend
 * Function:    called by interrupt to resend UDS message (each 1ms)
 * Input:        reSendUDS: pointer to data to be sent
 * Input:        VCU_UDS_msg: message data and Id etc
 * output:        reSendUDS: 1: the UDS message should be resent; 0: don't need to be resent
 * Return:        null
 * Link:        
 * Attention:    
 ************************************************************************************************************* */
void UdsResend(void)
{
    uint8_t sendRslt;
    if(1 == reSendUDS)
    {
        sendRslt = CANTransimitRandomMessage (UdsRecvChannel, &VCU_UDS_msg);
        reSendUDS = 0;
        if( 0!= sendRslt)
        {
            reSendUDS = 1;
        }
    }
}


//DTC_struct  CAN_CBFor19_Data[10];

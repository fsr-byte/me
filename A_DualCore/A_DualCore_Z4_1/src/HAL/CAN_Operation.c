/*
 * CAN_Operation.c
 *
 *  Created on: 2018年10月8日
 *      Author: helei
 */

#define __CAN_OPERATION_GLOBALS__

#include "derivative.h"
#include "CAN_Operation.h"
#include "CAN_DBC_Lib.h"
#include "Global.h"
#include "History_Data.h"
//#include "PMM_Model.h"
#include "ccp.h"
//#include "NM_Model.h"
#include "Task.h"
#include "System.h"
#include "Global.h"

uint8_t PTBusOffConfirmedFlag = 0;    /*PT CAN bus-off error confirmed*/
/*
0: All OK, no bus-off
1: bus-off detected, waiting for fast recovery delay timeout
2: bus-off detected, waiting for slow recovey delay timeout
3: CAN device re-initialized
4: re-transmission started checking if CAN bus is in error-active state
5: entered error-active  state, delay to clear Bus-off Confirmed flag
*/

uint32_t gblUdsRspID = ID_Return_UDS;

/********external function****************/
extern void udsTpRecv(uint8_t PhyIdFlag, uint8_t tpRecvLen);

uint8_t CANTransimitRandomMessage (CAN_CHANNEL CanChannel,  _CAN_MESSAGE_ *CanMessage)
{
  uint8_t canchannel = CAN3;
  static uint8_t P_mbnow = CAN2_TX_Random_Start;
  static uint8_t B_mbnow = CAN1_TX_Random_Start;
  static uint8_t C_mbnow = CAN3_TX_Random_Start;
  static uint8_t X_mbnow = CAN0_TX_Random_Start;
  uint8_t mbstart = CAN3_TX_Random_Start, mbend = CAN3_TX_Random_End;
  uint8_t mbtick = 0;
  uint8_t mbtickMax = mbend - mbstart + 1;
  uint8_t mbnow = C_mbnow;

  uint32_t config = 0;
  uint64_t message = 0;
  uint8_t recode = 1;
  uint8_t errcode = 0;

    switch(CanChannel)
    {
        case CAN2:
        {
            canchannel = CAN2;
            mbstart = CAN2_TX_Random_Start;
            mbend = CAN2_TX_Random_End;
            mbtickMax = mbend - mbstart + 1;
            mbnow = P_mbnow;
            break;
        }
        case CAN1:
        {
            canchannel = CAN1;
            mbstart = CAN1_TX_Random_Start;
            mbend = CAN1_TX_Random_End;
            mbtickMax = mbend - mbstart + 1;
            mbnow = B_mbnow;
            break;
        }
        case CAN3:
        {
            canchannel = CAN3;
            mbstart = CAN3_TX_Random_Start;
            mbend = CAN3_TX_Random_End;
            mbtickMax = mbend - mbstart + 1;
            mbnow = C_mbnow;
            break;
        }
        case CAN0:
        {
            canchannel = CAN0;
            mbstart = CAN0_TX_Random_Start;
            mbend = CAN0_TX_Random_End;
            mbtickMax = mbend - mbstart + 1;
            mbnow = X_mbnow;
            break;
        }
        default:
        {
            errcode = 1;	//通道错误
            break;
        }
    }
    if( (1 == errcode) || (mbnow < mbstart) || (mbnow > mbend) )	//检测到通道错误或静态变量有问题，返回错误值
    {
        return 0;
    }

    if( CanMessage->control.rtr == 1 )
    {
        config |= CAN_CS_RTR;
    }
    if( CanMessage->control.ide == 1 )
    {
        config |= CAN_CS_IDE;
    }
    if( CanMessage->control.dlc == 8 )
    {
        config |= CAN_CS_DLC8;
    }

    message = CanMessage->data.R64;

    while(recode && (mbtick <= mbtickMax))	//为1时发送不成功
    {
        recode = CAN_Send(canchannel, mbnow, config, CanMessage->control.id, message);
        mbnow++;
        if( mbnow > mbend )	//成环
        {
            mbnow = mbstart;
        }
        if( 1 == recode )	//该MB含有数据无法发送
        {
            mbtick++;	//记录该次总数
        }
        else	//MB填充完毕，可视为发送完毕
        {
            switch(canchannel)
            {
                case CAN2:
                    P_mbnow = mbnow;
                    break;
                case CAN1:
                    B_mbnow = mbnow;
                    break;
                case CAN3:
                    C_mbnow = mbnow;
                    break;
                case CAN0:
                    X_mbnow = mbnow;
                    break;
                default:
                    break;
            }
        }
    }

    if( (mbtick > mbtickMax) && (recode == 1) )	//MB已满，无法发送
    {
        CanMessage->ReSendFlag = 1;	//需要重新发送
        return 0;
    }
    //发送成功
    CanMessage->clocktime = SystemTickMs;	//发送成功时记录当前时间
    CanMessage->clocktime10ms = SystemTick10Ms;
    CanMessage->ReSendFlag = 0;	//不需要重新发送
    CanMessage->times++;
    return 1;
}

uint8_t CANTransimitPeriodMessage (CAN_CHANNEL CanChannel,  _CAN_MESSAGE_ *CanMessage)
{
    uint8_t canchannel = CAN3;
    static uint8_t P_mbnow = CAN2_TX_Period_Start;
    static uint8_t B_mbnow = CAN1_TX_Period_Start;
    static uint8_t C_mbnow = CAN3_TX_Period_Start;
    static uint8_t X_mbnow = CAN0_TX_Period_Start;
    uint8_t mbstart = CAN3_TX_Period_Start, mbend = CAN3_TX_Period_End;
    uint8_t mbtick = 0;
    uint8_t mbtickMax = mbend - mbstart + 1;
    uint8_t mbnow = C_mbnow;

    uint32_t config = 0;
    uint64_t message = 0;
    uint8_t recode = 1;
    uint8_t errcode = 0;

    switch(CanChannel)
    {
        case CAN2:
        {
            canchannel = CAN2;
            mbstart = CAN2_TX_Period_Start;
            mbend = CAN2_TX_Period_End;
            mbtickMax = mbend - mbstart + 1;
            mbnow = P_mbnow;
            break;
        }
        case CAN1:
        {
            canchannel = CAN1;
            mbstart = CAN1_TX_Period_Start;
            mbend = CAN1_TX_Period_End;
            mbtickMax = mbend - mbstart + 1;
            mbnow = B_mbnow;
            break;
        }
        case CAN3:
        {
            canchannel = CAN3;
            mbstart = CAN3_TX_Period_Start;
            mbend = CAN3_TX_Period_End;
            mbtickMax = mbend - mbstart + 1;
            mbnow = C_mbnow;
            break;
        }
        case CAN0:
        {
            canchannel = CAN0;
            mbstart = CAN0_TX_Period_Start;
            mbend = CAN0_TX_Period_End;
            mbtickMax = mbend - mbstart + 1;
            mbnow = X_mbnow;
            break;
        }
        default:
        {
            errcode = 1;	//通道错误
            break;
        }
    }
    if( (1 == errcode) || (mbnow < mbstart) || (mbnow > mbend) )	//检测到通道错误或静态变量有问题，返回错误值
    {
        return 0;
    }

    if( CanMessage->control.rtr == 1 )
    {
        config |= CAN_CS_RTR;
    }
    if( CanMessage->control.ide == 1 )
    {
        config |= CAN_CS_IDE;
    }
    if( CanMessage->control.dlc == 8 )
    {
        config |= CAN_CS_DLC8;
    }

    message = CanMessage->data.R64;

    while(recode && (mbtick <= mbtickMax))	//为1时发送不成功
    {
        recode = CAN_Send(canchannel, mbnow, config, CanMessage->control.id, message);
        mbnow++;
        if( mbnow > mbend )	//成环
        {
            mbnow = mbstart;
        }
        if( 1 == recode )	//该MB含有数据无法发送
        {
            mbtick++;	//记录该次总数
        }
        else	//MB填充完毕，可视为发送完毕
        {
            switch(canchannel)
            {
                case CAN2:
                    P_mbnow = mbnow;
                    break;
                case CAN1:
                    B_mbnow = mbnow;
                    break;
                case CAN3:
                    C_mbnow = mbnow;
                    break;
                case CAN0:
                    X_mbnow = mbnow;
                    break;
                default:
                    break;
            }
        }
    }

    if( (mbtick > mbtickMax) && (recode == 1) )	//MB已满，无法发送
    {
        CanMessage->ReSendFlag = 1;	//需要重新发送
        return 0;
    }
    //发送成功
    CanMessage->clocktime = SystemTickMs;	//发送成功时记录当前时间
    CanMessage->clocktime10ms = SystemTick10Ms;
    CanMessage->ReSendFlag = 0;	//不需要重新发送
    CanMessage->times++;
    return 1;
}

void CANReTransimitPeriodMessage(void)
{
    uint8_t i = 0;
    for(i = 0; i < CAN3_TX_NUM; i++)
    {
        //if(i == 13) continue;//不重发送406报文
        if( 1 == CAN3_TX_Array[i].ReSendFlag )
        {
            CANTransimitPeriodMessage(CAN3, &(CAN3_TX_Array[i]));
        }
    }
}

void CAN_Clear_MsgDataValue(CAN_CHANNEL CanChannel,CHANNEL Channel)
{
     switch (CanChannel)
     {
      case CAN3:
      {
    	  CAN3_TX_Array[Channel].data.R64 = 0;
          break;
        }
      case CAN1:
      {
    	  CAN1_TX_Array[Channel].data.R64 = 0;
          break;
        }
      case CAN2:
	{
		CAN2_TX_Array[Channel].data.R64 = 0;
		break;
	 }
	case CAN0:
	{
		CAN0_TX_Array[Channel].data.R64 = 0;
		break;
	  }
      default:    break;
     }
}

void CAN_Set_ID (CAN_CHANNEL CanChannel, CHANNEL Channel, RXTX_FLAG txrx_flag,
	    ID_FLAG ide, uint8_t dlc, uint32_t id)
{
    switch(CanChannel)
    {
        case CAN2:
        {
            if( (txrx_flag == Tx_Flag) && (Channel < CAN2_TX_NUM) )
            {
                CAN2_TX_Array[Channel].control.ide = ide;
                CAN2_TX_Array[Channel].control.id = id;
                CAN2_TX_Array[Channel].control.dlc = dlc;
            }
            else if( (txrx_flag == Rx_Flag) && (Channel < CAN2_RX_NUM) )
            {
                CAN2_RX_Array[Channel].control.ide = ide;
                CAN2_RX_Array[Channel].control.id = id;
                CAN2_RX_Array[Channel].control.dlc = dlc;
            }
            break;
        }
        case CAN1:
        {
            if( (txrx_flag == Tx_Flag) && (Channel < CAN1_TX_NUM) )
            {
                CAN1_TX_Array[Channel].control.ide = ide;
                CAN1_TX_Array[Channel].control.id = id;
                CAN1_TX_Array[Channel].control.dlc = dlc;
            }
            else if( (txrx_flag == Rx_Flag) && (Channel < CAN1_RX_NUM) )
            {
                CAN1_RX_Array[Channel].control.ide = ide;
                CAN1_RX_Array[Channel].control.id = id;
                CAN1_RX_Array[Channel].control.dlc = dlc;
            }
            break;
        }
        case CAN3:
        {
            if( (txrx_flag == Tx_Flag) && (Channel < CAN3_TX_NUM) )
            {
                CAN3_TX_Array[Channel].control.ide = ide;
                CAN3_TX_Array[Channel].control.id = id;
                CAN3_TX_Array[Channel].control.dlc = dlc;
            }
            else if( (txrx_flag == Rx_Flag) && (Channel < CAN3_RX_NUM) )
            {
                CAN3_RX_Array[Channel].control.ide = ide;
                CAN3_RX_Array[Channel].control.id = id;
                CAN3_RX_Array[Channel].control.dlc = dlc;
            }
            break;
        }
        case CAN0:
        {
            if( (txrx_flag == Tx_Flag) && (Channel < CAN0_TX_NUM) )
            {
                CAN0_TX_Array[Channel].control.ide = ide;
                CAN0_TX_Array[Channel].control.id = id;
                CAN0_TX_Array[Channel].control.dlc = dlc;
            }
            else if( (txrx_flag == Rx_Flag) && (Channel < CAN0_RX_NUM) )
            {
                CAN0_RX_Array[Channel].control.ide = ide;
                CAN0_RX_Array[Channel].control.id = id;
                CAN0_RX_Array[Channel].control.dlc = dlc;
            }
            break;
        }
        default:
            break;
    }
}

void CAN_Set_Message (CAN_CHANNEL CanChannel, CHANNEL Channel,
		 RXTX_FLAG txrx_flag, ID_FLAG ide, uint32_t id, uint8_t dlc,
		 uint8_t rtr, uint32_t period, _CAN_flag_ flag)
{
    switch(CanChannel)
    {
        case CAN2:
        {
            if( (txrx_flag == Tx_Flag) && (Channel < CAN2_TX_NUM) )
            {
                CAN2_TX_Array[Channel].control.ide = ide;
                CAN2_TX_Array[Channel].control.id = id;
                CAN2_TX_Array[Channel].control.dlc = dlc;
                CAN2_TX_Array[Channel].control.rtr = rtr;
                CAN2_TX_Array[Channel].period = period;
                CAN2_TX_Array[Channel].flag = flag;
            }
            else if( (txrx_flag == Rx_Flag) && (Channel < CAN2_RX_NUM) )
            {
                CAN2_RX_Array[Channel].control.ide = ide;
                CAN2_RX_Array[Channel].control.id = id;
                CAN2_RX_Array[Channel].control.dlc = dlc;
                CAN2_RX_Array[Channel].control.rtr = rtr;
                CAN2_RX_Array[Channel].flag = flag;
            }
            break;
        }
        case CAN1:
        {
            if( (txrx_flag == Tx_Flag) && (Channel < CAN1_TX_NUM) )
            {
                CAN1_TX_Array[Channel].control.ide = ide;
                CAN1_TX_Array[Channel].control.id = id;
                CAN1_TX_Array[Channel].control.dlc = dlc;
                CAN1_TX_Array[Channel].control.rtr = rtr;
                CAN1_TX_Array[Channel].period = period;
                CAN1_TX_Array[Channel].flag = flag;
            }
            else if( (txrx_flag == Rx_Flag) && (Channel < CAN1_RX_NUM) )
            {
                CAN1_RX_Array[Channel].control.ide = ide;
                CAN1_RX_Array[Channel].control.id = id;
                CAN1_RX_Array[Channel].control.dlc = dlc;
                CAN1_RX_Array[Channel].control.rtr = rtr;
                CAN1_RX_Array[Channel].flag = flag;
            }
            break;
        }
        case CAN3:
        {
            if( (txrx_flag == Tx_Flag) && (Channel < CAN3_TX_NUM) )
            {
                CAN3_TX_Array[Channel].control.ide = ide;
                CAN3_TX_Array[Channel].control.id = id;
                CAN3_TX_Array[Channel].control.dlc = dlc;
                CAN3_TX_Array[Channel].control.rtr = rtr;
                CAN3_TX_Array[Channel].period = period;
                CAN3_TX_Array[Channel].flag = flag;
            }
            else if( (txrx_flag == Rx_Flag) && (Channel < CAN3_RX_NUM) )
            {
                CAN3_RX_Array[Channel].control.ide = ide;
                CAN3_RX_Array[Channel].control.id = id;
                CAN3_RX_Array[Channel].control.dlc = dlc;
                CAN3_RX_Array[Channel].control.rtr = rtr;
                CAN3_RX_Array[Channel].flag = flag;
            }
            break;
        }
        case CAN0:
        {
            if( (txrx_flag == Tx_Flag) && (Channel < CAN0_TX_NUM) )
            {
                CAN0_TX_Array[Channel].control.ide = ide;
                CAN0_TX_Array[Channel].control.id = id;
                CAN0_TX_Array[Channel].control.dlc = dlc;
                CAN0_TX_Array[Channel].control.rtr = rtr;
                CAN0_TX_Array[Channel].period = period;
                CAN0_TX_Array[Channel].flag = flag;
            }
            else if( (txrx_flag == Rx_Flag) && (Channel < CAN0_RX_NUM) )
            {
                CAN0_RX_Array[Channel].control.ide = ide;
                CAN0_RX_Array[Channel].control.id = id;
                CAN0_RX_Array[Channel].control.dlc = dlc;
                CAN0_RX_Array[Channel].control.rtr = rtr;
                CAN0_RX_Array[Channel].flag = flag;
            }
            break;
        }
        default:
            break;
    }
}

void CAN_Set_MessageFlag(CAN_CHANNEL CanChannel, CHANNEL Channel, RXTX_FLAG txrx_flag, _CAN_flag_ flag)
{
    switch(CanChannel)
    {
      case CAN2:
      {
           if(txrx_flag == Tx_Flag)
           {
               if(Channel<CAN2_TX_NUM)
               {
                   CAN2_TX_Array[Channel].flag = flag;
               }
           }
           else if(txrx_flag == Rx_Flag)
           {
               if(Channel<CAN2_RX_NUM)
               {
                   CAN2_RX_Array[Channel].flag = flag;
               }
           }
           break;
      }
      case CAN1:
      {
           if(txrx_flag == Tx_Flag)
           {
               if(Channel<CAN1_TX_NUM)
               {
                   CAN1_TX_Array[Channel].flag = flag;
               }
           }
           else if(txrx_flag == Rx_Flag)
           {
               if(Channel<CAN1_RX_NUM)
               {
                   CAN1_RX_Array[Channel].flag = flag;
               }
           }
           break;
      }
      case CAN3:
      {
           if(txrx_flag == Tx_Flag)
           {
               if(Channel<CAN3_TX_NUM)
               {
                   CAN3_TX_Array[Channel].flag = flag;
               }
           }
           else if(txrx_flag == Rx_Flag)
           {
               if(Channel<CAN3_RX_NUM)
               {
                   CAN3_RX_Array[Channel].flag = flag;
               }
           }
           break;
      }
      case CAN0:
      {
           if(txrx_flag == Tx_Flag)
           {
               if(Channel<CAN0_TX_NUM)
               {
                   CAN0_TX_Array[Channel].flag = flag;
               }
           }
           else if(txrx_flag == Rx_Flag)
           {
               if(Channel<CAN0_RX_NUM)
               {
                   CAN0_RX_Array[Channel].flag = flag;
               }
           }
           break;
      }
      default:    break;
    }
}

void CAN_Set_TxMessageResend(CAN_CHANNEL CanChannel, CHANNEL Channel,uint8_t flag)
{
    switch(CanChannel)
    {
      case CAN2:
               if(Channel<CAN2_TX_NUM)
            	   CAN2_TX_Array[Channel].ReSendFlag = flag;
           break;
      case CAN1:
               if(Channel<CAN1_TX_NUM)
            	   CAN1_TX_Array[Channel].ReSendFlag = flag;
           break;
      case CAN3:
               if(Channel<CAN3_TX_NUM)
            	   CAN3_TX_Array[Channel].ReSendFlag = flag;
           break;
      case CAN0:
               if(Channel<CAN0_TX_NUM)
            	   CAN0_TX_Array[Channel].ReSendFlag = flag;
           break;
      default:    break;
    }
}

void CAN_Set_TxMessageUncondition(CAN_CHANNEL CanChannel, CHANNEL Channel,uint8_t flag)
{
    switch(CanChannel)
    {
        case CAN2:
            if( Channel < CAN2_TX_NUM )
            {
                CAN2_TX_Array[Channel].Unconditionalexecution = flag;
            }
            break;
        case CAN1:
            if( Channel < CAN1_TX_NUM )
            {
                CAN1_TX_Array[Channel].Unconditionalexecution = flag;
            }
            break;
        case CAN3:
            if( Channel < CAN3_TX_NUM )
            {
                CAN3_TX_Array[Channel].Unconditionalexecution = flag;
            }
            break;
        case CAN0:
            if( Channel < CAN0_TX_NUM )
            {
                CAN0_TX_Array[Channel].Unconditionalexecution = flag;
            }
            break;
        default:
            break;
    }
}

void CAN_Set_MessageTxPeriod(CAN_CHANNEL CanChannel, CHANNEL Channel,uint32_t period)
{
    switch(CanChannel)
    {
        case CAN2:
            if( Channel < CAN2_TX_NUM )
            {
                CAN2_TX_Array[Channel].period = period;
            }
            break;
        case CAN1:
            if( Channel < CAN1_TX_NUM )
            {
                CAN1_TX_Array[Channel].period = period;
            }
            break;
        case CAN3:
            if( Channel < CAN3_TX_NUM )
            {
                CAN3_TX_Array[Channel].period = period;
            }
            break;
        case CAN0:
            if( Channel < CAN0_TX_NUM )
            {
                CAN0_TX_Array[Channel].period = period;
            }
            break;
        default:
            break;
    }
}


uint32_t CAN_Get_Tick(CAN_CHANNEL CanChannel, CHANNEL Channel)
{

    if( (CanChannel == CAN2) && (Channel < CAN2_RX_NUM) )
    {
        return CAN2_RX_Array[Channel].times;
    }
    else if( (CanChannel == CAN1) && (Channel < CAN1_RX_NUM) )
    {
        return CAN1_RX_Array[Channel].times;
    }
    else if( (CanChannel == CAN3) && (Channel < CAN3_RX_NUM) )
    {
        return CAN3_RX_Array[Channel].times;
    }
    else if( (CanChannel == CAN0) && (Channel < CAN0_RX_NUM) )
    {
        return CAN0_RX_Array[Channel].times;
    }
    else
    {
        return 0;
    }
}

uint32_t CAN_Get_ID(CAN_CHANNEL CanChannel, CHANNEL Channel)
{

    if( (CanChannel == CAN2) && (Channel < CAN2_RX_NUM) )
    {
        return CAN2_RX_Array[Channel].control.id;
    }
    else if( (CanChannel == CAN1) && (Channel < CAN1_RX_NUM) )
    {
        return CAN1_RX_Array[Channel].control.id;
    }
    else if( (CanChannel == CAN3) && (Channel < CAN3_RX_NUM) )
    {
        return CAN3_RX_Array[Channel].control.id;
    }
    else if( (CanChannel == CAN0) && (Channel < CAN0_RX_NUM) )
    {
        return CAN0_RX_Array[Channel].control.id;
    }
    else
    {
        return 0;
    }
}

uint8_t CAN_Get_MessageRxTxFlag(CAN_CHANNEL CanChannel,CHANNEL Channel,RXTX_FLAG txrx_flag)
{
    uint8_t can_data_temp = 0;

    switch(CanChannel)
    {
        case CAN2:
        {
            if( txrx_flag == Tx_Flag )
            {
                can_data_temp = CAN2_TX_Array[Channel].flag;
            }
            else if( txrx_flag == Rx_Flag )
            {
                can_data_temp = CAN2_RX_Array[Channel].flag;
            }
            break;
        }
        case CAN1:
        {
            if( txrx_flag == Tx_Flag )
            {
                can_data_temp = CAN1_TX_Array[Channel].flag;
            }
            else if( txrx_flag == Rx_Flag )
            {
                can_data_temp = CAN1_RX_Array[Channel].flag;
            }
            break;
        }
        case CAN3:
        {
            if( txrx_flag == Tx_Flag )
            {
                can_data_temp = CAN3_TX_Array[Channel].flag;
            }
            else if( txrx_flag == Rx_Flag )
            {
                can_data_temp = CAN3_RX_Array[Channel].flag;
            }
            break;
        }
        case CAN0:
        {
            if( txrx_flag == Tx_Flag )
            {
                can_data_temp = CAN0_TX_Array[Channel].flag;
            }
            else if( txrx_flag == Rx_Flag )
            {
                can_data_temp = CAN0_RX_Array[Channel].flag;
            }
            break;
        }
        default:
            break;
    }
    return can_data_temp;
}

void CanNmTx_Handle(void)
{
    uint8_t returni = 0;
    uint8_t i = 0;
    i = 13;

    /*NM messsage Tranmission is disabled*/
    if( (UDS_DisRx_DisTx == NmComCtrlType) || (UDS_EnRx_DisTx == NmComCtrlType) )
    {
        return;
    }

    if( (0 != VHALO_NMSendReq) && (Old_VHALO_NMSendReq != VHALO_NMSendReq) )
    {
        CANDBC_gather(CAN3, i);
        returni = CANTransimitRandomMessage(CAN3, &CAN3_TX_Array[i]);
        //NM message sent, increase the tick
        if( returni != 0 )
        {
            VHALI_NMTxSuceess_MsgTicks++;
            if( 0 == NM_First )
            {
                NM_First = 1;
            }
        }
        if( 1 == NM_First )
        {
            if( NM_AppWaitValid == 1 )	//上电等待150-200ms间隔生效。
            {
                NM_AppWaitValid = 2;
            }
            else if( NM_AppWaitValid == 0 )
            {	//不生效
                NM_SetMessage();
            }
            NM_First = 2;
        }
    }
}

/*
 * 发送周期报文数组中的数据帧，在10ms中断中发送，并使用10ms的时间标记
 * */
void CanTx_Handle (void)
{

    
#if 1

    uint8_t i = 0;
    /*Application message Tramsmission is disabled*/
    if( (UDS_DisRx_DisTx == AppComCtrlType) || (UDS_EnRx_DisTx == AppComCtrlType) )
    {
        return;
    }

	

    for(i = 0; i < CAN2_TX_NUM; i++)	//---------------CAN2------------------
    {
        if( 2 == CAN2_TX_Array[i].Unconditionalexecution ) //在该循环内无条件不执行一次
        {
            CAN2_TX_Array[i].clocktime = SystemTickMs;
            CAN2_TX_Array[i].clocktime10ms = SystemTick10Ms;	//更新时间
            CAN2_TX_Array[i].Unconditionalexecution = 0;	//清除标志
        }
        else if( 1 == CAN2_TX_Array[i].Unconditionalexecution ) //在该循环内无条件执行一次
        {
            CAN_gather(CAN2, i);
            CANTransimitPeriodMessage(CAN2, &CAN2_TX_Array[i]);
            CAN2_TX_Array[i].Unconditionalexecution = 0;	//清除标志
        }
        else	//无条件执行标志位无效时，使用其他标志判断
        {
            if( ((CAN2_TX_Array[i].clocktime10ms + CAN2_TX_Array[i].period - 1) <= SystemTick10Ms)
                    && (CAN2_TX_Array[i].flag != DontSending) )
            {
                CAN_gather(CAN2, i);
                CANTransimitPeriodMessage(CAN2, &CAN2_TX_Array[i]);
            }
        }
    }
    for(i = 0; i < CAN1_TX_NUM; i++)	//---------------CAN1-----------------
    {
        if( 2 == CAN1_TX_Array[i].Unconditionalexecution )	//在该循环内无条件不执行一次
        {
            CAN1_TX_Array[i].clocktime = SystemTickMs;
            CAN1_TX_Array[i].clocktime10ms = SystemTick10Ms;	//更新时间
            CAN1_TX_Array[i].Unconditionalexecution = 0;	//清除标志
        }
        else if( 1 == CAN1_TX_Array[i].Unconditionalexecution )	//在该循环内无条件执行一次
        {
            CAN_gather(CAN1, i);
            CANTransimitPeriodMessage(CAN1, &CAN1_TX_Array[i]);
            CAN1_TX_Array[i].Unconditionalexecution = 0;	//清除标志
        }
        else	//无条件执行标志位无效时，使用其他标志判断
        {
            if( ((CAN1_TX_Array[i].clocktime10ms + CAN1_TX_Array[i].period - 1) <= SystemTick10Ms)
                    && (CAN1_TX_Array[i].flag != DontSending) )
            {
                CAN_gather(CAN1, i);
                CANTransimitPeriodMessage(CAN1, &CAN1_TX_Array[i]);
            }
        }
    }

    for(i = 1; i < CAN3_TX_NUM; i++)	//---------------CAN3---------------------
    {
        if( 2 == CAN3_TX_Array[i].Unconditionalexecution )	//在该循环内无条件不执行一次
        {
            CAN3_TX_Array[i].clocktime = SystemTickMs;
            CAN3_TX_Array[i].clocktime10ms = SystemTick10Ms;	//更新时间
            CAN3_TX_Array[i].Unconditionalexecution = 0;	//清除标志
        }
        else if( 1 == CAN3_TX_Array[i].Unconditionalexecution )	//在该循环内无条件执行一次
        {
            if( CAN3_TX_Array[i].control.id != 0x406 )
            {
                CAN_gather(CAN3, i);
                CANTransimitPeriodMessage(CAN3, &CAN3_TX_Array[i]);
                CAN3_TX_Array[i].Unconditionalexecution = 0;	//清除标志
            }
            //滚动码在该条件下不更新
        }
        else	//无条件执行标志位无效时，使用其他标志判断
        {
            if( ((CAN3_TX_Array[i].clocktime10ms + CAN3_TX_Array[i].period - 1) <= SystemTick10Ms)
                    && (CAN3_TX_Array[i].flag != DontSending) )
            {
                if( CAN3_TX_Array[i].control.id != 0x406 )
                {
                    CAN_gather(CAN3, i);
                    CANTransimitPeriodMessage(CAN3, &CAN3_TX_Array[i]);
                }
                if( i == CHANNEL_2 )	//VCU_110
                {
                    VHALO_VCU110CycCntr++;
                    if( VHALO_VCU110CycCntr > 0xE ) //Zhou Yi change the rolling counter to 0-14, because in CAN Matrix 0xF is invalid value BMS will check this value
                    {
                        VHALO_VCU110CycCntr = 0;
                    }
                }
                if( i == CHANNEL_9 ) //VCU_520
                {
                    VHALO_VCU520CycCntr++;
                    if( VHALO_VCU520CycCntr > 0xF )
                    {
                        VHALO_VCU520CycCntr = 0;
                    }
                }
            }
        }
    }

    for(i = 0; i < CAN0_TX_NUM; i++)	//---------------CAN0--------------------
    {
        if( 2 == CAN0_TX_Array[i].Unconditionalexecution )	//在该循环内无条件不执行一次
        {
            CAN0_TX_Array[i].clocktime = SystemTickMs;
            CAN0_TX_Array[i].clocktime10ms = SystemTick10Ms;	//更新时间
            CAN0_TX_Array[i].Unconditionalexecution = 0;	//清除标志
        }
        else if( 1 == CAN0_TX_Array[i].Unconditionalexecution )	//在该循环内无条件执行一次
        {
            CAN_gather(CAN0, i);
            CANTransimitPeriodMessage(CAN0, &CAN0_TX_Array[i]);
            CAN0_TX_Array[i].Unconditionalexecution = 0;		//清除标志
        }
        else
        {
            if( ((CAN0_TX_Array[i].clocktime10ms + CAN0_TX_Array[i].period - 1) <= SystemTick10Ms)
                    && (CAN0_TX_Array[i].flag != DontSending) )
            {
                CAN_gather(CAN0, i);
                CANTransimitPeriodMessage(CAN0, &CAN0_TX_Array[i]);
            }
        }
    }
#endif
}

/*
 * 将Unconditional execution都置为1，即将所有周期报文都发送一遍
 * */
void CANTx_Begin(void)
{
  //NM_Model_initialize();
  CanNmTx_Handle();
  NM_SetMessage();
}

void CAN_RX_Begin(void)
{
    uint32_t i;
    for(i = 0; i < CAN2_RX_NUM; i++)
    {
        if( 0 == CAN2_RX_Array[i].control.id )	//为0时代表不使用
            continue;

        CAN[CAN2]->MB[i].CS.B.IDE = CAN2_RX_Array[i].control.ide;
        CAN[CAN2]->MB[i].CS.B.DLC = CAN2_RX_Array[i].control.dlc;
        if( 0 == CAN2_RX_Array[i].control.ide )
        {
            CAN[CAN2]->MB[i].ID.B_STD.ID = CAN2_RX_Array[i].control.id;
        }
        else
        {
            CAN[CAN2]->MB[i].ID.B_EXT.ID = CAN2_RX_Array[i].control.id;
        }
        CAN[CAN2]->MB[i].CS.B.CODE = 0x04;	//MB empty - ready for receive
    }

    for(i = 0; i < CAN1_RX_NUM; i++)
    {
        if( 0 == CAN1_RX_Array[i].control.id )	//为0时代表不使用
            continue;

        CAN[CAN1]->MB[i].CS.B.IDE = CAN1_RX_Array[i].control.ide;
        CAN[CAN1]->MB[i].CS.B.DLC = CAN1_RX_Array[i].control.dlc;
        if( 0 == CAN1_RX_Array[i].control.ide )
        {
            CAN[CAN1]->MB[i].ID.B_STD.ID = CAN1_RX_Array[i].control.id;
        }
        else
        {
            CAN[CAN1]->MB[i].ID.B_EXT.ID = CAN1_RX_Array[i].control.id;
        }
        CAN[CAN1]->MB[i].CS.B.CODE = 0x04;	//MB empty - ready for receive
    }

    for(i = 0; i < CAN3_RX_NUM; i++)
    {
        if( 0 == CAN3_RX_Array[i].control.id )	//为0时代表不使用
            continue;

        CAN[CAN3]->MB[i].CS.B.IDE = CAN3_RX_Array[i].control.ide;
        CAN[CAN3]->MB[i].CS.B.DLC = CAN3_RX_Array[i].control.dlc;
        if( 0 == CAN3_RX_Array[i].control.ide )
        {
            CAN[CAN3]->MB[i].ID.B_STD.ID = CAN3_RX_Array[i].control.id;
        }
        else
        {
            CAN[CAN3]->MB[i].ID.B_EXT.ID = CAN3_RX_Array[i].control.id;
        }
        CAN[CAN3]->MB[i].CS.B.CODE = 0x04;	//MB empty - ready for receive
    }

    for(i = 0; i < CAN0_RX_NUM; i++)
    {
        if( 0 == CAN0_RX_Array[i].control.id )	//为0时代表不使用
            continue;

        CAN[CAN0]->MB[i].CS.B.IDE = CAN0_RX_Array[i].control.ide;
        CAN[CAN0]->MB[i].CS.B.DLC = CAN0_RX_Array[i].control.dlc;
        if( 0 == CAN0_RX_Array[i].control.ide )
        {
            CAN[CAN0]->MB[i].ID.B_STD.ID = CAN0_RX_Array[i].control.id;
        }
        else
        {
            CAN[CAN0]->MB[i].ID.B_EXT.ID = CAN0_RX_Array[i].control.id;
        }
        CAN[CAN0]->MB[i].CS.B.CODE = 0x04;	//MB empty - ready for receive
    }
}

/*******************************************************************    用于CCP及UDS的数据传入  在INT中调用  ****/
void CAN2Rx_Handle(uint32_t MessageId)
{
    	if(MessageId == BCCP_CRO_ID)
 	    {
            if(VCU_CCP_Valid)
            {
            	Ccp_CopyNewCmd(CAN1_RX_Array[3].data.R8);
            	CcpRecvChannel = CAN2;
            }
 	    }
}

void CAN1Rx_Handle(uint32_t MessageId)
{
	if(MessageId == BCCP_CRO_ID)
	{	
        if(VCU_CCP_Valid)
        {
        	Ccp_CopyNewCmd(CAN1_RX_Array[3].data.R8);
        	CcpRecvChannel = CAN1;
        }
	}
#if 0
	if(MessageId == ID_VCUHW_UDS)   //VCU硬件测试
	{
		gblUdsRspID = ID_ReturnVCUHW_UDS;
	  tpUdsCANRecv[0] = (unsigned char)(CAN1_RX_Array[4].data.R32[0] >> 24);
	  tpUdsCANRecv[1] = (unsigned char)(CAN1_RX_Array[4].data.R32[0] >> 16);
	  tpUdsCANRecv[2] = (unsigned char)(CAN1_RX_Array[4].data.R32[0] >> 8);
	  tpUdsCANRecv[3] = (unsigned char)(CAN1_RX_Array[4].data.R32[0] );
	  tpUdsCANRecv[4] = (unsigned char)(CAN1_RX_Array[4].data.R32[1]>> 24);
	  tpUdsCANRecv[5] = (unsigned char)(CAN1_RX_Array[4].data.R32[1] >> 16);
	  tpUdsCANRecv[6] = (unsigned char)(CAN1_RX_Array[4].data.R32[1] >> 8);
	  tpUdsCANRecv[7] = (unsigned char)(CAN1_RX_Array[4].data.R32[1] );
	  UdsRecvChannel = CAN1;
	  HW_udsDiag_flag = 1;
	  udsTpRecv(TRUE, (unsigned char)CAN1_RX_Array[4].control.dlc);
	}
	else
	{
		HW_udsDiag_flag = 0;
	}
#endif
}

void CAN3Rx_Handle(uint32_t MessageId)
{
    if(MessageId == BCCP_CRO_ID)
    {
        if(VCU_CCP_Valid)
        {
        	Ccp_CopyNewCmd(CAN3_RX_Array[2].data.R8);
        	CcpRecvChannel = CAN3;
        }
    }

}

void CAN0Rx_Handle(uint32_t MessageId)
{
  if (MessageId == BCCP_CRO_ID)
    {
      if (VCU_CCP_Valid)
	{
	  Ccp_CopyNewCmd (CAN0_RX_Array[2].data.R8);
	  CcpRecvChannel = CAN0;
	}
    }
//  if (MessageId == ID_VCUHW_UDS)   //VCU硬件测试
//    {
//      gblUdsRspID = ID_ReturnVCUHW_UDS;
//      tpUdsCANRecv[0] = (unsigned char) (CAN0_RX_Array[2].data.R32[0] >> 24);
//      tpUdsCANRecv[1] = (unsigned char) (CAN0_RX_Array[2].data.R32[0] >> 16);
//      tpUdsCANRecv[2] = (unsigned char) (CAN0_RX_Array[2].data.R32[0] >> 8);
//      tpUdsCANRecv[3] = (unsigned char) (CAN0_RX_Array[2].data.R32[0]);
//      tpUdsCANRecv[4] = (unsigned char) (CAN0_RX_Array[2].data.R32[1] >> 24);
//      tpUdsCANRecv[5] = (unsigned char) (CAN0_RX_Array[2].data.R32[1] >> 16);
//      tpUdsCANRecv[6] = (unsigned char) (CAN0_RX_Array[2].data.R32[1] >> 8);
//      tpUdsCANRecv[7] = (unsigned char) (CAN0_RX_Array[2].data.R32[1]);
//      UdsRecvChannel = CAN0;
//      HW_udsDiag_flag = 1;
//      udsTpRecv (TRUE, (unsigned char) CAN0_RX_Array[2].control.dlc);
//    }
//  else
//    {
//      HW_udsDiag_flag = 0;
//    }

}

/******************************************************************		BUS OFF 	***************************/
/******************************************************************************
 * Name:            Bus_offTaskInit
 * Called by:       task_code.c, Task_initialize
 * Parameter:       void
 * Return value:    void
 * Description:    initialize the bus-off task relevent global variables
 * Precondition:    ---
 *****************************************************************************/
void Bus_offTaskInit(void)
{
    PTBusOffConfirmedFlag = 0;        /*PT CAN bus-off error confirmed*/

    CAN3_BusOffDelayTimeOut = 1;        /*1:PT CAN bus-off recovery delay timeout, can retry the transmission*/
    CAN3_BusOffFastRecoveryCnt = 0;         /*PT CAN bus-off fast recovery retry count*/
    CAN3_BusOffRecoveryStart = 0;     /*record when the bus-off recovery is started*/

}
/******************************************************************************
 * Name:            Bus_OffEnableTransmission
 * Called by:       Bus_OffHandlerTask
 * Parameter:       void
 * Return value:    void
 * Description:    re initialize the Tx flag for cyclic messages
 * Precondition:    ---
 *****************************************************************************/
 void Bus_OffEnableTransmission(void)
 {
   _CAN_MESSAGE_ Test_CANFrame;
   Test_CANFrame.control.dlc = 8;
   Test_CANFrame.control.id = 0x406;
   Test_CANFrame.control.ide = 0;
   Test_CANFrame.control.rtr = 0;
   Test_CANFrame.data.R64 = 0x0604000000000000;

   NM_First = 0;
   CANTransimitRandomMessage (CAN3, &Test_CANFrame);
   //NM_Model_initialize();
 }

/******************************************************************************
 * Name:            Bus_OffHandler
 * Called by:       task_code.c, every 20ms
 * Parameter:       void
 * Return value:    void
 * Description:    check bus-off status: if bus-off detected, execute fast-recory and slow-recory
 * Precondition:    ---
 *****************************************************************************/
void Bus_OffHandlerTask(void)
{
  static uint32_t time = 0;
     /*check bus-off error*/
     if(BUS_OFF_OK == CAN3_BusOffState)
     {
         //FLTCONF = 1x Bus Off; BOFFINT 为1时检测到BOFF
         if(CAN_3.ESR1.B.BOFFINT == 1)
         {
             NM_ShutAll_CANTxPeriodMessage ();	//关闭所有周期报文
             CAN3_BusOffState = BUS_OFF_DTECTED;
             CAN3_BusOffDelayTimeOut = 0;
         }
     }
     else if (BUS_OFF_DTECTED == CAN3_BusOffState)
     {
         if((SystemTickMs - CAN3_BusOffRecoveryStart) >( BUSOFF_FAST_RECOVERY_DELAY))
         {
             CAN3_BusOffFastRecoveryCnt++;
             /*re-initialize the CAN3*/
             FLEXCAN_3_Init(500);
             /*set the Rx ID filter in CAN_RX_Begin()*/
             CAN_RX_Begin();
             CAN3_BusOffState = BUS_OFF_FAST_RECOVERY_WAIT;               
             CAN3_BusOffRecoveryStart = SystemTickMs;

         } 
     }
     /*wait the fast recovery timeout */
     else if (BUS_OFF_FAST_RECOVERY_WAIT == CAN3_BusOffState)
     {
         if((SystemTickMs - CAN3_BusOffRecoveryStart) > BUSOFF_FAST_RECOVERY_DELAY)
         {
             CAN3_BusOffFastRecoveryCnt++;
             Bus_OffEnableTransmission();
             CAN3_BusOffDelayTimeOut = 1;
             CAN3_BusOffState = BUS_OFF_TX_RESTRATED;

             time = SystemTickMs;
         } 
     }     
     /*wait the slow recovery timeout */
     else if(BUS_OFF_SLOW_RECOVERY_WAIT == CAN3_BusOffState)
     {
          if((SystemTickMs - CAN3_BusOffRecoveryStart) > BUSOFF_SLOW_RECOVERY_DELAY)
          {
              Bus_OffEnableTransmission();
              CAN3_BusOffDelayTimeOut = 1;
              CAN3_BusOffState = BUS_OFF_TX_RESTRATED;

              time = SystemTickMs;
          } 
     }
     /*transmission restarted, wait for bus-off recovered*/
     else if( (BUS_OFF_TX_RESTRATED == CAN3_BusOffState) && ((time + 30u) <= SystemTickMs))
    {
          if(CAN_3.ESR1.B.BOFFINT == 0)
          {
              CAN3_BusOffState =  BUS_OFF_OK;
              CAN3_BusOffFastRecoveryCnt = 0;
              PTBusOffConfirmedFlag = 0;                                
          }
          else
          {
              NM_ShutAll_CANTxPeriodMessage();
              CAN3_BusOffDelayTimeOut = 0;
              /*re-initialize the CAN3*/
              FLEXCAN_3_Init(500);
              /*set the Rx ID filter in CAN_RX_Begin()*/
              CAN_RX_Begin();
              CAN3_BusOffRecoveryStart = SystemTickMs;
              if(CAN3_BusOffFastRecoveryCnt <= MAX_BUSOFF_FAST_RECOVERY)
              {
                   CAN3_BusOffState = BUS_OFF_FAST_RECOVERY_WAIT;        
              }
              else
              {
                   CAN3_BusOffState = BUS_OFF_SLOW_RECOVERY_WAIT;        
              }
              /*set Bus-Off DTC */
              if(CAN3_BusOffFastRecoveryCnt >= MAX_BUS_OFF_DTC_CONFRIM)
              {
                  PTBusOffConfirmedFlag = 1;
              }
              
          }
         
    }
}
/******************************************************************		ACK 	***************************/
void Bus_AckTaskInit(void)//不需要调用初始化，因为这两个标志位都已经在定义时初始化了
{
  Bus_Ack_Start = 0;//是否是no ack状态。
  Bus_Ack_Statusf = 0;//状态流转标志
}

void Bus_AckStopSending(void)
{
  NM_ShutAll_CANTxPeriodMessage ();	//关闭所有周期报文
  CAN3_AckErrFlag = 1;//关闭406报文发送
  NM_First = 0xF;//关闭报文105的发送
  FLEXCAN_3_Init(500);//此时会将所有寄存器清零
  CAN_RX_Begin();//可以接受数据
}

void Bus_AckReInit(void)
{
  CAN3_AckErrFlag = 0;//重新开始发送
  NM_First = 0;
  //NM_Model_initialize();
}

void Bus_AckHandle(void)
{
    uint32_t ackStatus = 0;
    static uint32_t Bus_Ack_StartTime = 0xFFFFFF;	//记录开始的时间
    static uint32_t Bus_Ack_StartTime2 = 0xFFFFFF;

    ackStatus = (CAN_3.ESR1.B.ACKERR == 1) ? 1 : 0;
    if( (Bus_Ack_Start == 0) && (Bus_Ack_Statusf == 0) && (ackStatus == 1) )
    {
        Bus_Ack_Statusf = 1;
        Bus_Ack_StartTime = SystemTickMs;
        Bus_Ack_Start = 1;
    }
    if( (Bus_Ack_Start == 1) && (Bus_Ack_Statusf == 1) )	//持续监控ack状态
    {
        if( ((Bus_Ack_StartTime + 170u) <= SystemTickMs) && (ackStatus == 0) )	//超时还未进入Ack错误，则清除标志重新开始
        {
            Bus_Ack_Start = 0;
            Bus_Ack_Statusf = 0;
        }
    }
    if( (Bus_Ack_Start == 1) && (Bus_Ack_Statusf == 1) && (ackStatus == 1) && ((Bus_Ack_StartTime + 126u) <= SystemTickMs) )
    {
        //超过T_tx_timeout(150+-10%)时间时，重启该通道CAN控制器。并停止发送。
        Bus_AckStopSending();
        Bus_Ack_Statusf = 2;
        Bus_Ack_StartTime2 = SystemTickMs;
    }
    if( (Bus_Ack_Start == 1) && (Bus_Ack_Statusf == 2) && ((Bus_Ack_StartTime2 + 135u) <= SystemTickMs) )
    {
        Bus_AckReInit();
        Bus_Ack_Start = 0;
        Bus_Ack_Statusf = 0;
    }

}
/********************************************************************************************************/
 uint32_t Get_CCP_STATION_ADDR(void)
 {
   return BCCP_STATION_ADDR;
 }

 uint32_t Get_CCP_DTO_ID(void)
 {
   return BCCP_DTO_ID;
 }

  uint32_t Get_CCP_CRO_ID(void)
 {
   return BCCP_CRO_ID;
 }

 uint32_t Get_ID_Phy_UDS(void)
 {
    return  BID_Phy_UDS;
 }

 uint32_t Get_ID_Fun_UDS(void)
 {
    return  BID_Fun_UDS ;
 }

 uint32_t Get_ID_Return_UDS(void)
 {
    return  BID_Return_UDS;
 }


 void CAN_gather(CAN_CHANNEL CanChannel,CHANNEL Channel)
 {
   CANDBC_gather(CanChannel,Channel);
 }

 void CAN_analysis(void)
 {
     CANDBC_analysis();
 }

 /*---------------------------------------------------------------------------
 description: send Test messgage for Storage Management module, at powe-on and power -off phase
 send the ResiMilg and SOCDisp
 input param:       OnOff :1 power on 2: power-off
 output param:     void
 return:            
 ---------------------------------------------------------------------------*/
 void SendNvMOperationMsg(uint8_t OnOff)
 {
//    uint32_t u32NMTxTemp = 0;
//    uint8_t u8Temp = 0;
//    if(1 == KUDS_TestFeature)
//    {
//        NVM_msg.control.id = 0x0FA0666;
//        NVM_msg.control.dlc = 8;
//        NVM_msg.control.ide = 1;
//        NVM_msg.control.rtr = 0;
//
//        u32NMTxTemp = (uint32_t)OnOff;
//        u32NMTxTemp =  u32NMTxTemp << 30;
//        NVM_msg.data.R32[0] = u32NMTxTemp;
//
//        u32NMTxTemp = (unsigned long)VHALO_NMSendIndication;
//        u32NMTxTemp = u32NMTxTemp << 28;
//        NVM_msg.data.R32[0] = NVM_msg.data.R32[0] + u32NMTxTemp;
//
//        u32NMTxTemp = (unsigned long)PMM_output.VPMM_InternalSleepActive_flg;
//        u32NMTxTemp = u32NMTxTemp << 26;
//        NVM_msg.data.R32[0] = NVM_msg.data.R32[0] + u32NMTxTemp;
//
//        u32NMTxTemp = (unsigned long)ResiMilg;
//        NVM_msg.data.R32[0] = NVM_msg.data.R32[0] + u32NMTxTemp;
//
//        u8Temp = (uint8_t)SOCDisp;
//        u32NMTxTemp = (uint32_t)u8Temp;
//        u32NMTxTemp = u32NMTxTemp << 16;
//        NVM_msg.data.R32[0] = NVM_msg.data.R32[0] + u32NMTxTemp;
//        memcpy(&NVM_msg.data.R32[1], &VCUSubTotalEgyCnse_kwh, sizeof(NVM_msg.data.R32[1]));
//        CANTransimitRandomMessage(CAN3,&NVM_msg);
//
//        NVM_msg.control.id = 0x0FA0777;
//        memcpy(&NVM_msg.data.R32[0], &BMSSocLast, sizeof(NVM_msg.data.R32[0]));
//        memcpy(&NVM_msg.data.R32[1], &SOCDisp, sizeof(NVM_msg.data.R32[1]));
//        CANTransimitRandomMessage(CAN3,&NVM_msg);
//    }
 }





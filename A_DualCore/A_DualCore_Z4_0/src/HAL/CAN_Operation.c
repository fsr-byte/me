/*
 * CAN_Operation.c
 *
 *  Created on: 2018年10月8日
 *      Author: helei
 */

#define __CAN_OPERATION_GLOBALS__

#include "derivative.h"
#include "cstring"
#include "CAN_Operation.h"
#include "Global.h"


//_CAN_MESSAGE_ * P_CAN_RX_Frame = &CAN2_RX_Frame;
//_CAN_MESSAGE_ * B_CAN_RX_Frame = &CAN1_RX_Frame;
//_CAN_MESSAGE_ * C_CAN_RX_Frame = &CAN3_RX_Frame;
//_CAN_MESSAGE_ * X_CAN_RX_Frame = &CAN0_RX_Frame;
//
//_CAN_MESSAGE_ * P_CAN_TX_Frame = &CAN2_TX_Frame;
//_CAN_MESSAGE_ * B_CAN_TX_Frame = &CAN1_TX_Frame;
//_CAN_MESSAGE_ * C_CAN_TX_Frame = &CAN3_TX_Frame;
//_CAN_MESSAGE_ * X_CAN_TX_Frame = &CAN0_TX_Frame;


uint32_t gblUdsRspID = ID_Return_UDS;

/********external function****************/
extern void udsTpRecv(uint8_t PhyIdFlag, uint8_t tpRecvLen);

//返回0代表成功，1代表失败
uint8_t CANTransimitRandomMessage (CAN_CHANNEL CanChannel,_CAN_MESSAGE_ *CanMessage)
{
    uint8_t canchannel = CAN1;
    uint32_t config = 0;
    uint64_t message = 0;
    uint8_t recode = 1;
    uint8_t errcode = 0;

    if( (CanChannel == CAN0) || (CanChannel == CAN1) || (CanChannel == CAN2) || (CanChannel == CAN3) ) //-------helei:当前无底盘CAN诊断功能
    {
        canchannel = CanChannel;
        errcode = 0;	//通道正确
    }
    else
    {
        errcode = 1;	//通道错误
    }

    if( 1 == errcode )	//检测到通道错误或静态变量有问题，返回错误值
    {
        return errcode;
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

    recode = CAN_Send(canchannel, 0, config, CanMessage->control.id, message);	//仅使用MB0发送数据
    //发送成功
    if( 0 == recode )
    {
        CanMessage->clocktime = SystemTickMs;	//发送成功时记录当前时间
    }

    return recode;
}


/*******************************************************************    用于CCP及UDS的数据传入  在INT中调用  ****/
void CAN2Rx_Handle(uint32_t MessageId)
{
    if( MessageId == ID_Phy_UDS )
    {
        gblUdsRspID = ID_Return_UDS;
        memcpy(&tpUdsCANRecv[0], &CAN2_RX_Frame.data.R8[0], 8);
        UdsRecvChannel = CAN2;
        udsTpRecv(TRUE, (unsigned char)CAN2_RX_Frame.control.dlc);
    }
    if( MessageId == ID_Fun_UDS )
    {
        gblUdsRspID = ID_Return_UDS;
        memcpy(&tpUdsCANRecv[0], &CAN2_RX_Frame.data.R8[0], 8);
        UdsRecvChannel = CAN2;
        udsTpRecv(FALSE, (unsigned char)CAN2_RX_Frame.control.dlc);
    }
}

void CAN1Rx_Handle(uint32_t MessageId)
{
    if( MessageId == ID_Phy_UDS )
    {
        gblUdsRspID = ID_Return_UDS;
        memcpy(&tpUdsCANRecv[0], &CAN1_RX_Frame.data.R8[0], 8);
        UdsRecvChannel = CAN1;
        udsTpRecv(TRUE, (unsigned char)CAN1_RX_Frame.control.dlc);
    }
    if( MessageId == ID_Fun_UDS )
    {
        gblUdsRspID = ID_Return_UDS;
        memcpy(&tpUdsCANRecv[0], &CAN1_RX_Frame.data.R8[0], 8);
        UdsRecvChannel = CAN1;
        udsTpRecv(FALSE, (unsigned char)CAN1_RX_Frame.control.dlc);
    }

    if( (MessageId == ID_VCUHW_UDS) && KUDS_TestFeature )	//VCU硬件测试
    {
        gblUdsRspID = ID_ReturnVCUHW_UDS;
        memcpy(&tpUdsCANRecv[0], &CAN1_RX_Frame.data.R8[0], 8);
        UdsRecvChannel = CAN1;
        HW_udsDiag_flag = 1;
        udsTpRecv(TRUE, (unsigned char)CAN1_RX_Frame.control.dlc);
    }
    else
    {
        HW_udsDiag_flag = 0;
    }
}

void CAN3Rx_Handle(uint32_t MessageId)
{
    if( MessageId == ID_Phy_UDS )
    {
        gblUdsRspID = ID_Return_UDS;
        memcpy(&tpUdsCANRecv[0], &CAN3_RX_Frame.data.R8[0], 8);
        UdsRecvChannel = CAN3;
        udsTpRecv(TRUE, (unsigned char)CAN3_RX_Frame.control.dlc);
        HW_udsDiag_flag = 0;
    }
    if( MessageId == ID_Fun_UDS )
    {
        gblUdsRspID = ID_Return_UDS;
        memcpy(&tpUdsCANRecv[0], &CAN3_RX_Frame.data.R8[0], 8);
        UdsRecvChannel = CAN3;
        udsTpRecv(FALSE, (unsigned char)CAN3_RX_Frame.control.dlc);
        HW_udsDiag_flag = 0;
    }

}

void CAN0Rx_Handle(uint32_t MessageId)
{
    /*CAN0 only receives HW test ID */
#if 0   
    if(MessageId == ID_Phy_UDS)
    {
        gblUdsRspID = ID_Return_UDS;
        memcpy(&tpUdsCANRecv[0],&CAN0_RX_Frame.data.R8[0],8);
        UdsRecvChannel = CAN0;
        udsTpRecv(TRUE, (unsigned char)CAN0_RX_Frame.control.dlc);
    }
    if(MessageId == ID_Fun_UDS)
    {
        gblUdsRspID = ID_Return_UDS;
        memcpy(&tpUdsCANRecv[0],&CAN0_RX_Frame.data.R8[0],8);
        UdsRecvChannel = CAN0;
        udsTpRecv(FALSE, (unsigned char)CAN0_RX_Frame.control.dlc);
    }
#endif    
    if( (MessageId == ID_VCUHW_UDS) && KUDS_TestFeature )	//VCU硬件测试
    {
        gblUdsRspID = ID_ReturnVCUHW_UDS;
        memcpy(&tpUdsCANRecv[0], &CAN0_RX_Frame.data.R8[0], 8);
        UdsRecvChannel = CAN0;
        HW_udsDiag_flag = 1;
        udsTpRecv(TRUE, (unsigned char)CAN0_RX_Frame.control.dlc);
    }
    else
    {
        HW_udsDiag_flag = 0;
    }
}
/************************************** for CAN polling RX******/
void CAN0_RX_ISR(void)
{
    uint8_t i;
    uint32_t id = 0;
    /*CAN0 only receives HW test ID */
#if 0
    i = 1;	//Core0 的UDS接收专用buff，已匹配mask
    if (((CAN_0.IFLAG1.R >> i) & (0x01)) == 0x01)
    {
        id = CAN_Recive_GetID (CAN0, i);
        if ( (id == ID_Phy_UDS) || (id == ID_Fun_UDS) )
        {
            CAN_Recive_GetWithID (CAN0, i, SystemTickMs);	//
            CAN0Rx_Handle (CAN0_RX_Frame.control.id);
        }
        CAN_0.IFLAG1.R = (0x01 << i);	//clear interrupt flag
    }
#endif

    i = 2;	//Core0 的硬件测试模式专用ID，拓展帧
    if( (((CAN_0.IFLAG1.R >> i) & (0x01)) == 0x01) || (CAN_0.MB[i].CS.B.CODE == 0x02) )	//int flag or full
    {
        id = CAN_Recive_GetID(CAN0, i);
        if( id == ID_VCUHW_UDS )
        {
            CAN_Recive_GetWithID(CAN0, i, SystemTickMs);	//
            CAN0Rx_Handle(CAN0_RX_Frame.control.id);
        }
        CAN_0.IFLAG1.R = (0x01 << i);	//clear interrupt flag
        CAN_0.MB[i].CS.B.CODE = 4;
    }
}

void CAN1_RX_ISR(void)//using for diagnostic
{
    uint8_t i;
    uint32_t id = 0;

    i = 1;	//Core0 的UDS接收专用buff，已匹配mask
    if( ((CAN_1.IFLAG1.R >> i) & (0x01)) == 0x01 )
    {
        id = CAN_Recive_GetID(CAN1, i);
        if( (id == ID_Phy_UDS) || (id == ID_Fun_UDS) )
        {
            CAN_Recive_GetWithID(CAN1, i, SystemTickMs);	//
            CAN1Rx_Handle(CAN1_RX_Frame.control.id);
        }
        CAN_1.IFLAG1.R = (0x01 << i);	//clear interrupt flag
        CAN_1.MB[i].CS.B.CODE = 4;
    }
    i = 2;	//Core0 的硬件测试模式专用ID，拓展帧
    if( ((CAN_1.IFLAG1.R >> i) & (0x01)) == 0x01 )
    {
        id = CAN_Recive_GetID(CAN1, i);
        if( id == ID_VCUHW_UDS )
        {
            CAN_Recive_GetWithID(CAN1, i, SystemTickMs);	//
            CAN1Rx_Handle(CAN1_RX_Frame.control.id);
        }
        CAN_1.IFLAG1.R = (0x01 << i);	//clear interrupt flag
        CAN_1.MB[i].CS.B.CODE = 4;
    }
}

void CAN2_RX_ISR(void)
{
    uint8_t i;
    uint32_t id = 0;

    i = 1;	//Core0 的UDS接收专用buff，已匹配mask
    if( ((CAN_2.IFLAG1.R >> i) & (0x01)) == 0x01 )
    {
        id = CAN_Recive_GetID(CAN2, i);
        if( (id == ID_Phy_UDS) || (id == ID_Fun_UDS) )
        {
            CAN_Recive_GetWithID(CAN2, i, SystemTickMs);	//
            CAN2Rx_Handle(CAN2_RX_Frame.control.id);
        }
        CAN_2.IFLAG1.R = (0x01 << i);	//clear interrupt flag
        CAN_2.MB[i].CS.B.CODE = 4;
    }
}

void CAN3_RX_ISR(void)
{
    uint8_t i;
    uint32_t id = 0;

    i = 1;	//Core0 的UDS接收专用buff，已匹配mask
    if( ((CAN_3.IFLAG1.R >> i) & (0x01)) == 0x01 )
    {
        id = CAN_Recive_GetID(CAN3, i);
        if( (id == ID_Phy_UDS) || (id == ID_Fun_UDS) )
        {
            CAN_Recive_GetWithID(CAN3, i, SystemTickMs);	//
            CAN3Rx_Handle(CAN3_RX_Frame.control.id);
        }
        CAN_3.IFLAG1.R = (0x01 << i);	//clear interrupt flag
        CAN_3.MB[i].CS.B.CODE = 4;
    }
}

void CAN_PollingRx(void)
{
  CAN0_RX_ISR();//接收拓展帧硬件测试报文
  CAN1_RX_ISR();
  CAN2_RX_ISR();
  //@@@@@CAN3_RX_ISR();
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








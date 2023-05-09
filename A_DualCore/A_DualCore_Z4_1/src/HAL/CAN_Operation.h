/*
 * CAN_Operation.h
 *
 *  Created on: 2018年10月8日
 *      Author: helei
 */

#ifndef HAL_CAN_OPERATION_H_
#define HAL_CAN_OPERATION_H_

#include "typedefs.h"
#include "BASE_Global.h"


#ifdef __CAN_OPERATION_GLOBALS__
#define __CAN_OPERATION_EXTERN__
#else
#define __CAN_OPERATION_EXTERN__  extern
#endif


//else
#define BCCP_STATION_ADDR 	0x3900      /* Define CCP_STATION_ADDR in Intel Format */   /* High/Low byte swapped on motorola machines !!! (0x3900) */
#define BCCP_DTO_ID     	0x200         /* CAN identifier ECU -> Master */
#define BCCP_CRO_ID       	0x100         /* CAN identifier Master -> ECU */

#define ID_Phy_UDS      0x700
#define ID_Fun_UDS      0x7DF
#define ID_Return_UDS   0x708

#define ID_VCUHW_UDS    0xFA0529     /* VCU hardware testing mode Request (Master -> ECU) --- extended frame */
#define ID_ReturnVCUHW_UDS    0xFA0531     /* VCU hardware testing mode Response (ECU -> Master) --- extended frame */

#define BID_Phy_UDS     0x7E2
#define BID_Fun_UDS     0x7DE
#define BID_Return_UDS  0x7Ea

#define BOOT_Phy_UDS  0x7E2
#define BOOT_Rsp_UDS  0x7EA

#define ID_ecu_NM       0x01
#define ID_base_NM      0x400
#define ID_Return_NM    (ID_base_NM+ID_ecu_NM)

#define MAX_BUSOFF_FAST_RECOVERY 5
#define MAX_BUS_OFF_DTC_CONFRIM   3
#define BUSOFF_FAST_RECOVERY_DELAY  90
#define BUSOFF_SLOW_RECOVERY_DELAY  1000



/********************		Variable		*************************/
__CAN_OPERATION_EXTERN__ uint32_t gblUdsRspID;

/********************		Function		*************************/
//发送函数
__CAN_OPERATION_EXTERN__ uint8_t CANTransimitRandomMessage (CAN_CHANNEL CanChannel, _CAN_MESSAGE_ *CanMessage);
__CAN_OPERATION_EXTERN__ uint8_t CANTransimitPeriodMessage (CAN_CHANNEL CanChannel, _CAN_MESSAGE_ *CanMessage);
__CAN_OPERATION_EXTERN__ void CANReTransimitPeriodMessage(void);

//初始化时使用
__CAN_OPERATION_EXTERN__ void CAN_Clear_MsgDataValue(CAN_CHANNEL CanChannel,CHANNEL Channel);
__CAN_OPERATION_EXTERN__ void CAN_Set_ID(CAN_CHANNEL CanChannel, CHANNEL Channel, RXTX_FLAG txrx_flag, ID_FLAG ide, uint8_t dlc, uint32_t id);
__CAN_OPERATION_EXTERN__ void CAN_Set_Message (CAN_CHANNEL CanChannel, CHANNEL Channel,RXTX_FLAG txrx_flag, ID_FLAG ide, uint32_t id,
					       uint8_t dlc,uint8_t rtr,uint32_t period,_CAN_flag_ flag);

//动态配置
__CAN_OPERATION_EXTERN__ void CAN_Set_MessageFlag(CAN_CHANNEL CanChannel, CHANNEL Channel, RXTX_FLAG txrx_flag, _CAN_flag_ flag);
__CAN_OPERATION_EXTERN__ void CAN_Set_TxMessageUncondition(CAN_CHANNEL CanChannel, CHANNEL Channel,uint8_t flag);
__CAN_OPERATION_EXTERN__ void CAN_Set_MessageTxPeriod(CAN_CHANNEL CanChannel, CHANNEL Channel,uint32_t period);
__CAN_OPERATION_EXTERN__ void CAN_Set_TxMessageResend(CAN_CHANNEL CanChannel, CHANNEL Channel,uint8_t flag);

//发送与接收需要的协助函数，如CAN3的队列缓冲机制
__CAN_OPERATION_EXTERN__ void CANTx_Begin(void);//该函数需要重新配置使用,初衷是为了方便网络管理发送第一轮报文
__CAN_OPERATION_EXTERN__ void CAN_RX_Begin(void);
__CAN_OPERATION_EXTERN__ void CAN_AnalysisMQToRxArray(void);

//获取配置信息
__CAN_OPERATION_EXTERN__ uint32_t CAN_Get_Tick(CAN_CHANNEL CanChannel, CHANNEL Channel);
__CAN_OPERATION_EXTERN__ uint32_t CAN_Get_ID(CAN_CHANNEL CanChannel, CHANNEL Channel);
__CAN_OPERATION_EXTERN__ uint8_t CAN_Get_MessageRxTxFlag(CAN_CHANNEL CanChannel,CHANNEL Channel,RXTX_FLAG txrx_flag);

//整体发送函数
__CAN_OPERATION_EXTERN__ void CanNmTx_Handle(void);
__CAN_OPERATION_EXTERN__ void CanTx_Handle(void);

//接收报文后需要处理的函数，通常放在中断中，除了使用队列缓冲机制的CAN3外
__CAN_OPERATION_EXTERN__ void CAN0Rx_Handle(uint32_t MessageId);
__CAN_OPERATION_EXTERN__ void CAN1Rx_Handle(uint32_t MessageId);
__CAN_OPERATION_EXTERN__ void CAN2Rx_Handle(uint32_t MessageId);
__CAN_OPERATION_EXTERN__ void CAN3Rx_Handle(uint32_t MessageId);

//bus off 相关
__CAN_OPERATION_EXTERN__ void Bus_offTaskInit(void);
__CAN_OPERATION_EXTERN__ void Bus_OffEnableTransmission(void);
__CAN_OPERATION_EXTERN__ void Bus_OffHandlerTask(void);
//Ack 相关
__CAN_OPERATION_EXTERN__ void Bus_AckHandle(void);

/******************************************/
__CAN_OPERATION_EXTERN__ uint32_t Get_CCP_STATION_ADDR(void);
__CAN_OPERATION_EXTERN__ uint32_t Get_CCP_DTO_ID(void);
__CAN_OPERATION_EXTERN__ uint32_t Get_CCP_CRO_ID(void);
__CAN_OPERATION_EXTERN__ uint32_t Get_ID_Phy_UDS(void);
__CAN_OPERATION_EXTERN__ uint32_t Get_ID_Fun_UDS(void);
__CAN_OPERATION_EXTERN__ uint32_t Get_ID_Return_UDS(void);
__CAN_OPERATION_EXTERN__ void CAN_gather(CAN_CHANNEL CanChannel,CHANNEL Channel);
__CAN_OPERATION_EXTERN__ void CAN_analysis(void);
__CAN_OPERATION_EXTERN__ void SendNvMOperationMsg(uint8_t OnOff);


#endif /* HAL_BASE_CAN_OPERATION_H_ */

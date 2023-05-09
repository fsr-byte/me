/*
 * CAN_Operation.h
 *
 *  Created on: 2018Äê10ÔÂ8ÈÕ
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

//#define P_CAN_LINK	FLEXCAN2
//#define B_CAN_LINK	FLEXCAN1
//#define C_CAN_LINK	FLEXCAN3
//#define X_CAN_LINK	FLEXCAN0

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

/********************		Variable		*************************/
__CAN_OPERATION_EXTERN__ uint32_t gblUdsRspID;

/********************		Function		*************************/
__CAN_OPERATION_EXTERN__ uint8_t CANTransimitRandomMessage (CAN_CHANNEL CanChannel,_CAN_MESSAGE_ *CanMessage);
__CAN_OPERATION_EXTERN__ void CAN2Rx_Handle(uint32_t MessageId);
__CAN_OPERATION_EXTERN__ void CAN1Rx_Handle(uint32_t MessageId);
__CAN_OPERATION_EXTERN__ void CAN3Rx_Handle(uint32_t MessageId);
__CAN_OPERATION_EXTERN__ void CAN0Rx_Handle(uint32_t MessageId);
__CAN_OPERATION_EXTERN__ void CAN_PollingRx(void);


#endif /* HAL_BASE_CAN_OPERATION_H_ */

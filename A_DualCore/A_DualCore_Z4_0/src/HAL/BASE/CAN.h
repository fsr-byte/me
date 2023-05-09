/*
 * CAN.h
 *
 *  Created on: 2018年9月5日
 *      Author: helei
 */

#ifndef BASE_CAN_H_
#define BASE_CAN_H_

#include "typedefs.h"

#ifdef __CAN_GLOBALS__
#define __CAN_EXTERN__
#else
#define __CAN_EXTERN__  extern
#endif

//define for MB
#define CAN_TXCODE_INACTIVE	(0b1000)
#define CAN_TXCODE_ABORT	(0b1001)

#define CAN_RXCODE_INACTIVE	(0b0000)

#define CAN_CS_SRR		0x00400000
#define CAN_CS_IDE		0x00200000
#define CAN_CS_RTR		0x00100000
#define CAN_CS_DLC8		0x00080000

typedef enum
{
  DontSending = 0,
  ReadyToSend = 1,
  CompleteSend = 2,
  ReadyToRecive = 3,
  DontReciving = 4,
  CompleteRecive = 5
} _CAN_flag_;

typedef union _CAN_MB_data_tag_{
	uint64_t R64;
	uint32_t R32[2];
	uint16_t R16[4];
	uint8_t	 R8[8];
}_CAN_MB_data_;

typedef struct _CAN_MB_control_tag_ {
	uint8_t rtr;
	uint8_t	dlc;
	uint8_t ide;
	uint32_t id;
}_CAN_MB_control_;

typedef struct _CAN_MESSAGE_tag_ {
	_CAN_MB_control_ 	control;//对MB的控制字
	_CAN_MB_data_ 		data;	//数据
	uint32_t		clocktime;//发送或接收时的时间
}_CAN_MESSAGE_;

typedef enum _ID_FLAG
 {
    STD_ID      = 0,
    EXT_ID      = 1
} ID_FLAG;

typedef enum _CAN_CHANNEL_
{
    CAN2 = 2,	//对应FLEXCAN2
    CAN1 = 1,	//对应FLEXCAN1 ::诊断CAN
    CAN0 = 0,	//对应FLEXCAN0 ::底盘CAN
    CAN3 = 3,	//对应FLEXCAN3 ::动力CAN，could wake up
}CAN_CHANNEL;

//Globals
__CAN_EXTERN__ _CAN_MESSAGE_ CAN0_TX_Frame;//发送
__CAN_EXTERN__ _CAN_MESSAGE_ CAN1_TX_Frame;
__CAN_EXTERN__ _CAN_MESSAGE_ CAN2_TX_Frame;
__CAN_EXTERN__ _CAN_MESSAGE_ CAN3_TX_Frame;

__CAN_EXTERN__ _CAN_MESSAGE_ CAN0_RX_Frame;//接收
__CAN_EXTERN__ _CAN_MESSAGE_ CAN1_RX_Frame;
__CAN_EXTERN__ _CAN_MESSAGE_ CAN2_RX_Frame;
__CAN_EXTERN__ _CAN_MESSAGE_ CAN3_RX_Frame;

__CAN_EXTERN__ volatile struct CAN_tag *CAN[4];

//Functions
__CAN_EXTERN__ uint8_t CAN_Send(uint8_t canchannel, uint8_t mb, uint32_t config, uint32_t id, uint64_t message );
__CAN_EXTERN__ void CAN_Recive_Set(uint8_t canchannel, uint8_t mb, uint32_t config, uint32_t id);
__CAN_EXTERN__ void CAN_Recive_Get(uint8_t canchannel, uint8_t mb, uint32_t clocktime);
__CAN_EXTERN__ void CAN_Recive_GetWithID(uint8_t canchannel, uint8_t mb, uint32_t clocktime);
__CAN_EXTERN__ uint32_t CAN_Recive_GetID(uint8_t canchannel, uint8_t mb);

__CAN_EXTERN__ uint32_t CAN_SetValue(uint8_t *Buff,uint8_t  start,uint8_t  length , uint32_t Value);

#endif /* BASE_CAN_H_ */

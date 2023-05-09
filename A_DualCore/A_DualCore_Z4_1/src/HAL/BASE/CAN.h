/*
 * CAN.h
 *
 *  Created on: 2018��9��5��
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


//define for using
#define CAN0_RX_NUM		(11)
#define CAN0_TX_NUM		(2)
#define CAN1_RX_NUM		(6)
#define CAN1_TX_NUM		(2)
#define CAN2_RX_NUM		(4)
#define CAN2_TX_NUM		(1)
#define CAN3_RX_NUM		(51)
#define CAN3_TX_NUM		(35)

//MB define
//CAN 0 ����96��MB ֻ��64���� ��Ϊͷ�ļ��������⣬CAN_tag ֻ������64��MB
#define CAN0_TX_Random_Start	(16)
#define CAN0_TX_Random_End	(31)
#define CAN0_TX_Period_Start	(32)
#define CAN0_TX_Period_End	(63)
//CAN 1 ����96��MB ֻ��64���� ��Ϊͷ�ļ��������⣬CAN_tag ֻ������64��MB
#define CAN1_TX_Random_Start	(16)
#define CAN1_TX_Random_End	(31)
#define CAN1_TX_Period_Start	(32)
#define CAN1_TX_Period_End	(63)
//CAN 2 ����64��MB
#define CAN2_TX_Random_Start	(16)
#define CAN2_TX_Random_End	(31)
#define CAN2_TX_Period_Start	(32)
#define CAN2_TX_Period_End	(63)
//CAN 3 ����64��MB
#define CAN3_TX_Random_Start	(51)	//Ӧ�ô��ڵ���CAN3_RX_NUM
#define CAN3_TX_Random_End	(52)
#define CAN3_TX_Period_Start	(53)
#define CAN3_TX_Period_End	(63)



//define for MCR
#define CAN_MCR_MDIS        0x80000000
#define CAN_MCR_FRZ         0x40000000
#define CAN_MCR_FEN         0x20000000
#define CAN_MCR_HALT        0x10000000
#define CAN_MCR_NOTRDY      0x08000000
#define CAN_MCR_SOFTRST     0x02000000
#define CAN_MCR_FRZACK      0x01000000
#define CAN_MCR_WRNEN       0x00200000
#define CAN_MCR_LPMACK      0x00100000
#define CAN_MCR_SRXDIS      0x00020000
#define CAN_MCR_BCC         0x00010000
#define CAN_MCR_LPRIOEN     0x00002000
#define CAN_MCR_AEN         0x00001000

//define for MB
#define CAN_TXCODE_INACTIVE	(0b1000)
#define CAN_TXCODE_ABORT	(0b1001)

#define CAN_RXCODE_INACTIVE	(0b0000)

#define CAN_CS_SRR		0x00400000
#define CAN_CS_IDE		0x00200000
#define CAN_CS_RTR		0x00100000
#define CAN_CS_DLC8		0x00080000

//define structure
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
	_CAN_MB_control_ 	control;//��MB�Ŀ�����
	_CAN_MB_data_ 		data;	//����
	uint32_t			clocktime;	//���ͻ����ʱ��ʱ��
	uint32_t            clocktime10ms;//��¼10ms�����ڷ���ʱ�䣬���������ڷ���
	uint32_t			times;	//����
	uint32_t			period;	//����
	_CAN_flag_			flag;	//��¼��ǰ�ṹ��״̬������Ϊ�����ж�����
	uint8_t 		Unconditionalexecution;	//������ִ��һ�Σ����ɴ˿�ʼ��ʱ, 0: �ñ�־��Ч��1������������һ�Σ�2��������������һ��
	uint8_t				ReSendFlag;/*1: the message send failed, need to be resend in next 1ms; 0: re-send is unnecessary*/
}_CAN_MESSAGE_;

typedef enum _CHANNEL
{
  CHANNEL_0 = 0,
  CHANNEL_1 = 1,
  CHANNEL_2 = 2,
  CHANNEL_3 = 3,
  CHANNEL_4 = 4,
  CHANNEL_5 = 5,
  CHANNEL_6 = 6,
  CHANNEL_7 = 7,
  CHANNEL_8 = 8,
  CHANNEL_9 = 9,
  CHANNEL_10 = 10,
  CHANNEL_11 = 11,
  CHANNEL_12 = 12,
  CHANNEL_13 = 13,
  CHANNEL_14 = 14,
  CHANNEL_15 = 15,
  CHANNEL_16 = 16,
  CHANNEL_17 = 17,
  CHANNEL_18 = 18,
  CHANNEL_19 = 19,
  CHANNEL_20 = 20,
  CHANNEL_21 = 21,
  CHANNEL_22 = 22,
  CHANNEL_23 = 23,
  CHANNEL_24 = 24,
  CHANNEL_25 = 25,
  CHANNEL_26 = 26,
  CHANNEL_27 = 27,
  CHANNEL_28 = 28,
  CHANNEL_29 = 29,
  CHANNEL_30 = 30,
  CHANNEL_31 = 31,
  CHANNEL_32 = 32,
  CHANNEL_33 = 33,
  CHANNEL_34 = 34,
  CHANNEL_35 = 35,
  CHANNEL_36 = 36,
  CHANNEL_37 = 37,
  CHANNEL_38 = 38,
  CHANNEL_39 = 39,
  CHANNEL_40 = 40,
  CHANNEL_41 = 41,
  CHANNEL_42 = 42,
  CHANNEL_43 = 43,
  CHANNEL_44 = 44,
  CHANNEL_45 = 45,
  CHANNEL_46 = 46,
  CHANNEL_47 = 47,
  CHANNEL_48 = 48,
  CHANNEL_49 = 49,
  CHANNEL_50 = 50
} CHANNEL;

typedef enum _BYTE_LOCK
 {
    LOCK        = 1,
    UNLOCK      = 0
} BYTE_LOCK;
typedef enum _RXTX_FLAG
 {
    Tx_Flag      = 1,
    Rx_Flag      = 0
} RXTX_FLAG;
typedef enum _ID_FLAG
 {
    STD_ID      = 0,
    EXT_ID      = 1
} ID_FLAG;
typedef enum _CAN_CHANNEL_
{
  CAN2 = 2,	//��ӦFLEXCAN2
  CAN1 = 1,	//��ӦFLEXCAN1 ::���CAN
  CAN0 = 0,	//��ӦFLEXCAN0 ::����CAN
  CAN3 = 3,	//��ӦFLEXCAN3 ::����CAN��could wake up
}CAN_CHANNEL;

//Globals
__CAN_EXTERN__ _CAN_MESSAGE_ CAN0_RX_Array[CAN0_RX_NUM];
__CAN_EXTERN__ _CAN_MESSAGE_ CAN1_RX_Array[CAN1_RX_NUM];
__CAN_EXTERN__ _CAN_MESSAGE_ CAN2_RX_Array[CAN2_RX_NUM];
__CAN_EXTERN__ _CAN_MESSAGE_ CAN3_RX_Array[CAN3_RX_NUM];

__CAN_EXTERN__ _CAN_MESSAGE_ CAN0_TX_Array[CAN0_TX_NUM];
__CAN_EXTERN__ _CAN_MESSAGE_ CAN1_TX_Array[CAN1_TX_NUM];
__CAN_EXTERN__ _CAN_MESSAGE_ CAN2_TX_Array[CAN2_TX_NUM];
__CAN_EXTERN__ _CAN_MESSAGE_ CAN3_TX_Array[CAN3_TX_NUM];

__CAN_EXTERN__ volatile struct CAN_tag *CAN[4];

//Functions
__CAN_EXTERN__ uint8_t CAN_Send(uint8_t canchannel, uint8_t mb, uint32_t config, uint32_t id, uint64_t message );
__CAN_EXTERN__ void CAN_Recive_Set(uint8_t canchannel, uint8_t mb, uint32_t config, uint32_t id);
__CAN_EXTERN__ boolean CAN_Recive_Get(uint8_t canchannel, uint8_t mb, uint32_t clocktime);
__CAN_EXTERN__ boolean CAN_Recive_GetWithID(uint8_t canchannel, uint8_t mb, uint32_t clocktime);

__CAN_EXTERN__ void FLEXCAN_0_Init(uint32_t BAUTRATE);
__CAN_EXTERN__ void FLEXCAN_1_Init(uint32_t BAUTRATE);
__CAN_EXTERN__ void FLEXCAN_2_Init(uint32_t BAUTRATE);
__CAN_EXTERN__ void FLEXCAN_3_Init(uint32_t BAUTRATE);



#endif /* BASE_CAN_H_ */

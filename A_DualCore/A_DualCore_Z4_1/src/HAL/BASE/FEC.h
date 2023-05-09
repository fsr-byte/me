/*
 * FEC.h
 *
 *  Created on: 2019年1月29日
 *      Author: helei
 */

#ifndef HAL_BASE_FEC_H_
#define HAL_BASE_FEC_H_

#include "typedefs.h"

#ifdef __FEC_GLOBALS__
#define  __FEC_EXTERN__
#else
#define __FEC_EXTERN__  extern
#endif

#define MII_TIMEOUT 0x1000
#define ENET_CONNECT	1
#define INVALID_PHY_ADDR	0xFF

#define FEC_SEND	(0xAC00)	//buffer descriptors 的配置
#define FEC_RECE	(0xA000)

#define BUFF_MAXLEN	(1518)		//BUFF区总长度
#define BUFF_TXMAXLEN	(BUFF_MAXLEN - 4)	//发送除了CRC之外的帧数据

//IO define
#define	FEC_MDIO	(GPIO_PORTD+13)		//Management Data Input/Output
#define FEC_MDC		(GPIO_PORTD+8)		//Management Data Clock
#define FEC_TXEN	(GPIO_PORTC+2)		//Transmit Enable
#define FEC_TXD0	(GPIO_PORTC+6)		//Transmit Data
#define FEC_TXD1	(GPIO_PORTC+5)		//Transmit Data
#define FEC_REF_CLK	(GPIO_PORTC+0)		//Reference Clock connect to TXCLK when RMII
#define FEC_RXD0	(GPIO_PORTC+7)		//Receive Data
#define FEC_RXD1	(GPIO_PORTC+8)		//Receive Data
#define FEC_RX_ER	(GPIO_PORTC+11)		//Receive Error
#define FEC_RXDV	(GPIO_PORTC+13)		//Receive Data Valid

#define FEC_GPIO_EN	(GPIO_PORTD+4)		//TJA1100EN
#define FEC_GPIO_RST_N	(GPIO_PORTD+7)	//TJA1100RST_N
#define FEC_GPIO_INT	(GPIO_PORTD+10)	//GPIO-INT-IRQ10 需要额外配置中断

#define	FEC_Enable(x)	SIUL_SetPad(x)
#define	FEC_Disable(x)	SIUL_ClearPad(x)

//Error define
#define __ERR_ENET_PHYLOOSE__  	(0x01)
#define __ERR_ENET_NOPHY__    	(0x02)
#define __ERR_ENET_DISCONNECT__		(0x04)
#define __ERR_ENET_LENOUTRANGE__	(0x08)
#define __ERR_ENET_CANTSEND__	(0x10)

typedef union _FEC_RX_BUFFDESC_union_tag_
{
  uint16_t R;
  struct
  {
    uint16_t empty :1;	//by user
    uint16_t RO1 :1;
    uint16_t wrap :1;	//by user
    uint16_t RO2 :1;
    uint16_t isLast :1;	//by FEC
    uint16_t :2;
    uint16_t isMiss :1;	//by FEC
    uint16_t isBroadcast :1;	//by FEC
    uint16_t isMulticast :1;	//by FEC
    uint16_t isLengthViolation :1;	//by FEC
    uint16_t isNonOctetAligned :1;	//by FEC
    uint16_t :1;
    uint16_t isCRCerror :1;	//by FEC
    uint16_t isOverrun :1;	//by FEC
    uint16_t isTruncated :1;	//by FEC
  } B;
} _FEC_RX_BUFFDESC_tag_; /* Control and status info.*/

typedef union _FEC_TX_BUFFDESC_union_tag_
{
  uint16_t R;
  struct
  {
    uint16_t ready :1;	//by user
    uint16_t TO1 :1;
    uint16_t wrap :1;	//by user
    uint16_t TO2 :1;
    uint16_t last :1;	//by user
    uint16_t txCRC :1;	//by user
    uint16_t appendBadCRC :1;	//by user
    uint16_t :9;
  } B;
} _FEC_TX_BUFFDESC_tag_; /* Control and status info.*/

typedef struct {
	uint8_t destination[6]; //Destination MAC
	uint8_t source[6]; //Source MAC
	uint16_t length; //Data length
	uint8_t data[BUFF_MAXLEN - 14]; //Data space Frame size ,其中包含CRC字段
	/* CRC is written by hardware 共4个字节 */
} _EthernetFrame_tag_;

typedef struct
{
    uint16_t control; // Buffer descriptor control and status.
    uint16_t length;  // Buffer descriptor data length.
    uint8_t *buffer;  // Data buffer pointer.
} _FEC_BufferDescriptor_tag_;

typedef struct _FEC_DefineData_struct_tag_{
  uint8_t phyAddress;	//本地PHY的物理地址，自动扫描得到  PHY - 0-31. 当前版本只有一个PHY，不做拓展
  _FEC_BufferDescriptor_tag_ *txDescStart;	//发送描述的起始地址
  _FEC_BufferDescriptor_tag_ *rxDescStart;	//接收描述的起始地址
  uint64_t mac;	//后6个字节有效
  enum{
    enet_sendnop,
    enet_sending,
    enet_sendComplete
  }txStatus;	//发送状态
  enum{
    enet_receivenop,
    enet_receiving,
    enet_receiveComplete
  }rxStatus;	//接收状态
  uint8_t connect;
  uint8_t master_slave;
}_FEC_DefineData_tag_;


__FEC_EXTERN__ _FEC_DefineData_tag_ FEC_Data;	//FEC基本数据
__FEC_EXTERN__ _EthernetFrame_tag_  ENET_RxFrame;	//接收到的帧数据

__FEC_EXTERN__ void FEC_PadConfig (void);
__FEC_EXTERN__ void FEC_DataConfig(void);
__FEC_EXTERN__ uint16_t FEC_Init (void);
__FEC_EXTERN__ void FEC_ConfigAllowRx(uint8_t data);
__FEC_EXTERN__ void FEC_ConfigAllowTx(uint8_t data);

__FEC_EXTERN__ uint16_t ENET_Init(void);
__FEC_EXTERN__ uint16_t ENET_TX(uint8_t * data, uint16_t len);
__FEC_EXTERN__ uint16_t ENET_CheckTxStatus(void);
__FEC_EXTERN__ void ENET_SetTxStatusComplete(void);
__FEC_EXTERN__ void ENET_CopyRxFrame(void);
__FEC_EXTERN__ void ENET_StartReceive(void);
__FEC_EXTERN__ void  ENET_Cycle (void);

__FEC_EXTERN__ uint16_t FEC_ReadManagementFrame(uint16_t regAddr, uint16_t *data);
__FEC_EXTERN__ uint16_t FEC_WriteManagementFrame(uint16_t regAddr, uint16_t data);
__FEC_EXTERN__ uint16_t FEC_GetPhyAddress(void);

#endif /* HAL_BASE_FEC_H_ */

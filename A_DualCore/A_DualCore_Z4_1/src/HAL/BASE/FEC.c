/*
 * FEC.c
 *
 *  Created on: 2019年1月29日
 *      Author: helei
 */

#define __FEC_GLOBALS__

#include "FEC.h"
#include "derivative.h"
#include "GPIO.h"
#include "SYS.h"
#include "TJA1100.h"
#include <cstring>

_FEC_DefineData_tag_ 	FEC_Data;
_EthernetFrame_tag_ 	ENET_RxFrame;

// 定义发送和接收buff的描述
__attribute__ ((aligned (16))) _FEC_BufferDescriptor_tag_ txDesc;
__attribute__ ((aligned (16))) _FEC_BufferDescriptor_tag_ rxDesc;
// 定义发送和接收buff的存储区
__attribute__((aligned (16)))  uint8_t txFrame[BUFF_MAXLEN];
__attribute__((aligned (16)))  uint8_t rxFrame[BUFF_MAXLEN];

//配置FEC控制器的硬件端口，并且配置端口模式为RMII模式
void FEC_PadConfig (void)
{
  SIUL2.SCR0[0].B.FEC_MODE = 0;	//1:set pad is MII-Lite mode; 0 is RMII mode
  SIUL_DigitalIO (FEC_MDIO, 0x0C | 0x00090000);		//MDIO(IO)	-->
  SIUL2.MSCR0_255[FEC_MDC].R = 0x2200000C;
  SIUL_DigitalOutput (FEC_TXEN, 0x0C | SIUL_SLEW_DIS);	//TXEN		-->
  SIUL_DigitalOutput (FEC_TXD0, 0x0C | SIUL_SLEW_DIS);	//TXD0		-->
  SIUL_DigitalOutput (FEC_TXD1, 0x0C | SIUL_SLEW_DIS);	//TXD1		-->
  SIUL2.MSCR0_255[FEC_REF_CLK].R = SIUL_INPUT;
  SIUL2.MSCR512_995[996 - 512].B.SSS = 0x01;
  SIUL_DigitalInputSimple (FEC_RXD0, 0 | SIUL_PULL_UP);	//RXD0  	<--high SIUL_PULL_UP
  SIUL_DigitalInputSimple (FEC_RXD1, 0 | SIUL_PULL_UP);	//RXD1  	<--high SIUL_PULL_UP
  SIUL_DigitalInputSimple (FEC_RXDV, 0 | SIUL_PULL_UP);	//对应PHY的CRSDV  	<--high SIUL_PULL_UP
  SIUL_DigitalInputSimple (FEC_RX_ER, 0 | SIUL_PULL_DOWN);//RXER  	<--low SIUL_PULL_DOWN
  //Device configure
  SIUL_DigitalOutput (FEC_GPIO_EN, 0);		//GPIO-TJA1100EN	-->
  SIUL_DigitalOutput (FEC_GPIO_RST_N, 0);	//GPIO-RST_N		-->
  SIUL_DigitalInput (FEC_GPIO_INT, 694, 0, 0x01);//GPIO-INT-IRQ10	<--

  //Default configure
  FEC_Disable(FEC_GPIO_EN);
  FEC_Disable(FEC_GPIO_RST_N);
  wait_micsec (1);
  FEC_Enable(FEC_GPIO_EN);
  FEC_Enable(FEC_TXEN);
  FEC_Enable(FEC_GPIO_RST_N);
}

void FEC_DataConfig(void)
{
  FEC_Data.mac = 0x00049f04b16c;//MAC地址配置,后6个字节有效
  FEC_Data.phyAddress = INVALID_PHY_ADDR;	//先初始化为0xFF，后面使用函数：FEC_GetPhyAddress自动获取
  FEC_Data.connect = 0;		//初始化为未连接
  FEC_Data.master_slave = PHY_MASTER;	//初始化为主
  FEC_Data.rxStatus = enet_receivenop;
  FEC_Data.txStatus = enet_sendnop;
  FEC_Data.txDescStart = &txDesc;
  FEC_Data.rxDescStart = &rxDesc;
  FEC_Data.txDescStart->buffer = (&txFrame[0]);
  FEC_Data.rxDescStart->buffer = (&rxFrame[0]);
  FEC_Data.txDescStart->control = FEC_SEND;
  FEC_Data.rxDescStart->control = FEC_RECE;
}


/*
 * 初始化FEC；调用端口配置，PHY芯片配置，检测是否上电连接网络端口。设置MAC及buff位置
 * */
uint16_t FEC_Init (void)
{
  FEC_PadConfig ();		// Initial pads for the FEC

  FEC.ECR.R = 0x1;				// Start reset
  while (FEC.ECR.B.RESET)
    {
    };	// Wait for reset to complete
  FEC.EIMR.R = 0;		// Disable interrupts
  FEC.EIR.R = 0xFFFFFFFF;	// Clear any interrupts

  FEC_DataConfig();		//Initial

  FEC.GAUR.R = 0;// Reset multicast fields
  FEC.GALR.R = 0;
  FEC.IAUR.R = 0;
  FEC.IALR.R = 0;
  FEC.EMRBR.R = 2047;	// Set rx buf size
  FEC.ETDSR.R = (uint32_t) &txDesc;// Point FEC to our (single) tx and rx descriptors
  FEC.ERDSR.R = (uint32_t) &rxDesc;

  FEC.TCR.R = 0x00000004;		// Enable full duplex
  SIUL2.SCR0[0].B.FEC_MODE = 0;		//RMII
  FEC.RCR.R = 0x07FF000C;		// Set in RMII mode with full frame size 100Mbps
  FEC.MSCR.B.MII_SPEED = 0xA;		// Set RMII speed - operation at 50Mhz /5*2
  FEC.EIMR.R = 0x0A000000;		// Enable interrupt,TXF & RXF
  //FEC.EIMR.R = 0x02000000;		// just RXF
  INTC_0.PSR[218].R = 0x4000 | 0x1E;	//set Interrupt priority TXF
  INTC_0.PSR[219].R = 0x4000 | 0x1F;	//set Interrupt priority RXF


  // Configure a MAC address
  FEC.PALR.R = (uint32_t) (FEC_Data.mac>>16);
  FEC.PAUR.R = (uint32_t) ((FEC_Data.mac & 0xFFFF) << 16);

  FEC.ECR.R = 0x2;		// Enable module

  return 0;
}

/*
 * 配置FEC是否开始接收。
 * */
void FEC_ConfigAllowRx(uint8_t data)
{
  if(data)	//开始接收
    {
      FEC.RDAR.R = 0x01000000;// Flag descriptors available to allow reception
    }
  else		//停止接收
    {
      FEC.RDAR.R = 0;
    }
}

/*
 * 配置FEC是否开始发送
 * */
void FEC_ConfigAllowTx(uint8_t data)
{
  if(data)	//开始发送
    {
      FEC.TDAR.R = 0x01000000;	// Tell FEC frame is ready
    }
  else		//停止发送
    {
      FEC.TDAR.R = 0;
    }
}

/*
 * 负责对以太网模块进行初始化，包括FEC和PHY的初始化以及是否连接的检测
 * */
uint16_t ENET_Init(void)
{
  uint16_t recode = 0, errcode = 0, i = 5;

  FEC_Init();	//初始化FEC控制器
  while( (0 == FEC_GetPhyAddress()) && (i--) ) ;//获取PHY地址
  //recode = FEC_GetPhyAddress();

  if(INVALID_PHY_ADDR == FEC_Data.phyAddress)
    {
      errcode = __ERR_ENET_NOPHY__;
    }
  else	//有PHY地址时
    {
      PHY_Init();	//配置PHY
      if(PHY_MASTER == FEC_Data.master_slave)
	{
	  PHY_Config_Master(PHY_MASTER);	//配置PHY芯片的主从
	}
      else
	{
	  PHY_Config_Master(PHY_SLAVE);	//配置PHY芯片的主从
	}
      wait_micsec(10);
      recode = PHY_isConnected();	//判断是否有端口连接上。
      if(1 == recode)		//如果连接上
	{
	  errcode = 0;	//连接成功，初始化完成
	  FEC_Data.connect = 1;	//标志位，代表已连接
	  FEC_ConfigAllowRx(1);	//开始接收
	}
      else
	{
	  errcode += __ERR_ENET_DISCONNECT__;//将错误码包含未连接信息
	  FEC_Data.connect = 0;	//标志位，代表未连接
	}
    }
  //FEC_ConfigAllowRx(1);	//开始接收
  return errcode;
}

void ENET_send_test(void)
{
  uint8_t i = 0;
  static uint8_t data[100];
  _EthernetFrame_tag_ *Enetframe;

  Enetframe = (_EthernetFrame_tag_ *)&data[0];
  for(i = 0; i < 6; i++)
  {
     Enetframe->destination[i] = 0xff;
  }

     Enetframe->source[0] = 0x11;
     Enetframe->source[1] = 0x22;
     Enetframe->source[2] = 0x33;
     Enetframe->source[3] = 0x44;
     Enetframe->source[4] = 0x55;
     Enetframe->source[5] = 0x66;

     Enetframe->length = 100 - 14;

     for(i = 14; i < 100; i++)
     {
        data[i] = i;
     }
     ENET_TX(&data[0], 100);
}

/*
 * 循环检测尝试重新连接
 * */
void  ENET_Cycle (void)
{
  uint16_t recode = 0;
  static uint8_t data[1];
  if( (0 == FEC_Data.connect) && (0xFF != FEC_Data.phyAddress) ) //未连接，持续扫描，且找到PHY芯片
    {
      recode = PHY_isConnected ();	//判断是否有端口连接上。
      if (1 == recode)	//如果连接上
	{
	  FEC_Data.connect = 1;	//已连接
	  FEC_ConfigAllowRx(1);	//开始接收
	}
      else	//切换主从
	{
	  if (PHY_MASTER == FEC_Data.master_slave)	//当期为主
	    {
	      FEC_Data.master_slave = PHY_SLAVE;	//设置为从
	      PHY_Config_Master (PHY_SLAVE);	//配置PHY芯片的主从
	    }
	  else	//当前为从
	    {
	      FEC_Data.master_slave = PHY_MASTER;	//设置为主
	      PHY_Config_Master (PHY_MASTER);	//配置PHY芯片的主从
	    }
	}
    }

    //ENET_send_test();
    data[0] = 8;
    //Eth_send(1, &data[0], 1);
}

/*
 *  发送以太网帧数据，
 *  *data  为发送数据帧的地址
 *  len	          为发送的长度
 *
 *  return：错误码，0时为正在发送
 * */
uint16_t ENET_TX(uint8_t * data, uint16_t len)
{
  uint16_t errcode = 0;

  FEC.EIR.B.TXF = 1;  //Clear interrupt

  //if (1 == FEC_Data.connect)
//    {
//      if (len > BUFF_TXMAXLEN)	//超出最大的发送长度范围，
//	{
//	  errcode += __ERR_ENET_LENOUTRANGE__;
//	}
//      else if (enet_sending == FEC_Data.txStatus)	//处于发送中，未完成
//	{
//	  errcode += __ERR_ENET_CANTSEND__;
//	}
//      else	//长度正常
	{
	  memcpy (FEC_Data.txDescStart->buffer, data, len);	//拷贝数据到发送区
	  FEC_Data.txDescStart->length = len;	//配置好发送长度
	  FEC_Data.txDescStart->control = FEC_SEND;
	  FEC_ConfigAllowTx (1);
	  FEC_Data.txStatus = enet_sending;
	  errcode = 0;
	}
//    }
  //else
    //{
    //  errcode = __ERR_ENET_DISCONNECT__;
    //}
  return errcode;
}

/*
 * 返回发送帧的当前状态，是否为发送完成
 * return : 0:未完成； 1：完成
 * */
uint16_t ENET_CheckTxStatus(void)
{
  uint16_t recode = 0;
  if(enet_sending == FEC_Data.txStatus)
    {
      recode = 0;
    }
  else
    {
      recode = 1;	//发送完成
    }
  return recode;
}

void ENET_SetTxStatusComplete(void)
{
  FEC_Data.txStatus = enet_sendComplete;
}

void ENET_CopyRxFrame(void)
{
  memcpy((uint8_t *)(&ENET_RxFrame), FEC_Data.rxDescStart->buffer, FEC_Data.rxDescStart->length);	//拷贝接收到的数据到指定存储区
}

void ENET_StartReceive(void)
{
  FEC_Data.rxDescStart->control = FEC_RECE;
  FEC_ConfigAllowRx(1);// Flag descriptors available to allow reception
  FEC_Data.rxStatus = enet_receiving;
}

/*
 * 发送管理帧，对PHY进行控制
 * */
uint16_t FEC_ReadManagementFrame(uint16_t regAddr, uint16_t *data)
{
    uint32_t timeout;
    uint32_t result = 0;
    uint32_t eimr = FEC.EIMR.R;
    FEC.EIR.R = 0x00800000;	// Clear MII interrupt
    FEC.EIMR.R &= ~0x00800000;	// Mask MII interrupt
    FEC.MMFR.R = 0x60020000 | (((FEC_Data.phyAddress) & 0x1F) << 23) | ((regAddr & 0x1F) << 18);
    /* Poll for the MII interrupt */
    for(timeout = 0; timeout < MII_TIMEOUT; timeout++)
    {
        if( FEC.EIR.R & 0x00800000 )
        {
            break;
        }
    }
    FEC.EIR.R = 0x00800000;	// Clear MII interrupt
    FEC.EIMR.R = eimr;			// Restore mask
    if( timeout >= MII_TIMEOUT )
    {
        result = 1;
    }
    else
    {
        *data = (uint16_t)(FEC.MMFR.R & 0xFFFF);
        result = 0;
    }
    return result;
}

/*
 * 接收管理帧，获取PHY的寄存器状态
 * */
uint16_t FEC_WriteManagementFrame(uint16_t regAddr, uint16_t data)
{
    uint32_t timeout = 0;
    uint32_t result;
    uint32_t eimr = FEC.EIMR.R;
    FEC.EIR.R = 0x00800000;	// Clear MII interrupt
    FEC.EIMR.R &= ~0x00800000;	// Mask MII interrupt
    FEC.MMFR.R = 0x50020000 | (((FEC_Data.phyAddress) & 0x1F) << 23) | ((regAddr & 0x1F) << 18) | (data & 0xFFFF);
    /* Poll for the MII interrupt */
    for(timeout = 0; timeout < MII_TIMEOUT; timeout++)
    {
        if( FEC.EIR.R & 0x00800000 )
        {
            break;
        }
    }
    FEC.EIR.R = 0x00800000;	// Clear MII interrupt
    FEC.EIMR.R = eimr;			// Restore mask
    if( timeout == MII_TIMEOUT )
    {
        result = 1;
    }
    else
    {
        result = 0;
    }
    return result;
}

/*
 * 获取PHY芯片的硬件连接地址，为后续PHY管理帧的读取和发送做基础准备
 * 返回值：1：获取成功； 0：获取失败
 * */
uint16_t FEC_GetPhyAddress (void)
{
    uint8_t i;
    uint16_t recode = 0, right = 0;

    for(i = 0; i < 32; i++)
    {	//find PHY
        FEC_Data.phyAddress = i;
        recode = FEC_ReadManagementFrame(PHY_IDR1, &PHY_Register.IDR1.R);
        if( (0 == recode) && (!((PHY_Register.IDR1.R == 0) || (PHY_Register.IDR1.R == 0xffff))) )
        {
            right = 1;	//获取成功
            break;
        }
    }
    return right;
}














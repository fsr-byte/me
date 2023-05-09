/*
 * CAN.c
 *
 *  Created on: 2018年9月5日
 *      Author: helei
 */
#define __CAN_GLOBALS__

#include "derivative.h"
#include "CAN.h"
#include "GPIO.h"
#include "SYS.h"
#include "CAN_DBC_Lib.h"
#include "CAN_Operation.h"
#include "Global.h"

volatile struct CAN_tag *CAN[4] = {&CAN_0, &CAN_1, &CAN_2, &CAN_3};

_CAN_MESSAGE_ CAN0_RX_Array[CAN0_RX_NUM];
_CAN_MESSAGE_ CAN1_RX_Array[CAN1_RX_NUM];
_CAN_MESSAGE_ CAN2_RX_Array[CAN2_RX_NUM];
_CAN_MESSAGE_ CAN3_RX_Array[CAN3_RX_NUM];

_CAN_MESSAGE_ CAN0_TX_Array[CAN0_TX_NUM];
_CAN_MESSAGE_ CAN1_TX_Array[CAN1_TX_NUM];
_CAN_MESSAGE_ CAN2_TX_Array[CAN2_TX_NUM];
_CAN_MESSAGE_ CAN3_TX_Array[CAN3_TX_NUM];

_CAN_MESSAGE_ *CAN_RX_Array[4] = {CAN0_RX_Array,CAN1_RX_Array,CAN2_RX_Array,CAN3_RX_Array};


uint8_t CAN_Send(uint8_t canchannel, uint8_t mb, uint32_t config, uint32_t id, uint64_t message )
{
    if( (CAN[canchannel]->MB[mb].CS.B.CODE == 0x08) || (CAN[canchannel]->MB[mb].CS.B.CODE == 0) )
    {
        if( mb < 32 )		//清除标志位
        {
            CAN[canchannel]->IFLAG1.R = (0x0001 << mb);
        }
        else
        {
            CAN[canchannel]->IFLAG2.R = (0x0001 << (mb - 32));
        }

        CAN[canchannel]->MB[mb].CS.R = 0x08480000 | config;   //Length = 8 Bytes
        if( (config & CAN_CS_IDE) == CAN_CS_IDE )
        {
            CAN[canchannel]->MB[mb].ID.B_EXT.ID = id;  			//Load frame IDentifier
        }
        else
        {
            CAN[canchannel]->MB[mb].ID.B_STD.ID = id;  			//Load frame IDentifier
        }
        CAN[canchannel]->MB[mb].DATA.W[0] = (uint32_t)(message >> 32);			//Byte0 - Byte3  of the message
        CAN[canchannel]->MB[mb].DATA.W[1] = (uint32_t)message;					//Byte4 - Byte7 of the message
        if( (canchannel == CAN3) && ((1 == NM_ReACKandCanStop) || (1 == NM_ShutPerSend)) )
        {
            if( (id == BCCP_DTO_ID) || (id == ID_Return_UDS) || (id == ID_ReturnVCUHW_UDS) || (id == 0x406) )			//特殊报文允许跨过NM发送
            {

            }
            else					//其他报文不能发送
            {
                return 0;
            }
        }
        CAN[canchannel]->MB[mb].CS.B.CODE = 0xc;  //After transmission, the MB automatically becomes an Rx MB with the same ID.
    }
    else
    {
        return 1;	//不可发送
    }

    return 0;	//可以发送
}

void CAN_Recive_Set(uint8_t canchannel, uint8_t mb, uint32_t config, uint32_t id)
{
    CAN[canchannel]->MB[mb].CS.R = 0x00080000 | config;   //Length = 8 Bytes
    if( (config & CAN_CS_IDE) == CAN_CS_IDE )
    {
        CAN[canchannel]->MB[mb].ID.B_EXT.ID = id;  			//Load frame IDentifier
    }
    else
    {
        CAN[canchannel]->MB[mb].ID.B_STD.ID = id;  			//Load frame IDentifier
    }
    CAN[canchannel]->MB[mb].CS.B.CODE = 0x04;		//MB empty - ready for receive
    CAN_RX_Array[canchannel][mb].flag = ReadyToRecive;
}

boolean CAN_Recive_Get(uint8_t canchannel, uint8_t mb, uint32_t clocktime)
{
    boolean ValidMsg = FALSE;
    if( CAN[canchannel]->MB[mb].CS.B.DLC >= CAN_RX_Array[canchannel][mb].control.dlc )		//bug1361:长度小于预期时丢弃报文。
    {
        CAN_RX_Array[canchannel][mb].control.rtr = CAN[canchannel]->MB[mb].CS.B.RTR;
        if( CAN_RX_Array[canchannel][mb].control.rtr != 1 )		//不是远程帧
        {
            //数据
            //CAN_RX_Array[canchannel][mb].control.dlc = CAN[canchannel]->MB[mb].CS.B.DLC;
            CAN_RX_Array[canchannel][mb].data.R32[0] = CAN[canchannel]->MB[mb].DATA.W[0];
            CAN_RX_Array[canchannel][mb].data.R32[1] = CAN[canchannel]->MB[mb].DATA.W[1];
            ValidMsg = TRUE;
        }
        CAN_RX_Array[canchannel][mb].times++;	//得出自上电开始接收的总个数
        CAN_RX_Array[canchannel][mb].period = clocktime - CAN_RX_Array[canchannel][mb].clocktime;	//得出接收的周期单位为ms
        CAN_RX_Array[canchannel][mb].clocktime = clocktime;		//记录接收时的时间
        CAN_RX_Array[canchannel][mb].flag = CompleteRecive;
    }
    return ValidMsg;
}

boolean CAN_Recive_GetWithID(uint8_t canchannel, uint8_t mb, uint32_t clocktime)
{
    boolean ValidMsg = FALSE;
    if( CAN[canchannel]->MB[mb].CS.B.DLC >= CAN_RX_Array[canchannel][mb].control.dlc )		//bug1361:长度小于预期时丢弃报文。
    {
        CAN_RX_Array[canchannel][mb].control.rtr = CAN[canchannel]->MB[mb].CS.B.RTR;
        if( CAN_RX_Array[canchannel][mb].control.rtr != 1 )		//不是远程帧
        {
            if( 0 == CAN_RX_Array[canchannel][mb].control.ide )
            {
                CAN_RX_Array[canchannel][mb].control.id = CAN[canchannel]->MB[mb].ID.B_STD.ID;	//赋值ID,标准帧
            }
            else
            {
                CAN_RX_Array[canchannel][mb].control.id = CAN[canchannel]->MB[mb].ID.B_EXT.ID;	//赋值ID,拓展帧
            }
            //数据
            //CAN_RX_Array[canchannel][mb].control.dlc = CAN[canchannel]->MB[mb].CS.B.DLC;
            CAN_RX_Array[canchannel][mb].data.R32[0] = CAN[canchannel]->MB[mb].DATA.W[0];
            CAN_RX_Array[canchannel][mb].data.R32[1] = CAN[canchannel]->MB[mb].DATA.W[1];
            ValidMsg = TRUE;
        }
        CAN_RX_Array[canchannel][mb].times++;	//得出自上电开始接收的总个数
        CAN_RX_Array[canchannel][mb].period = clocktime - CAN_RX_Array[canchannel][mb].clocktime;	//得出接收的周期单位为ms
        CAN_RX_Array[canchannel][mb].clocktime = clocktime;		//记录接收时的时间
        CAN_RX_Array[canchannel][mb].flag = CompleteRecive;
    }
    return ValidMsg;
}

/*************Initial****************************/
void FLEXCAN_0_Init(uint32_t BAUTRATE)	//MB has 96 (0-95) just using 64
{
    int i = 0;

	INTC_0.PSR[679].R = INT_CAN0RX_07_CORE_PRIORITY;		//将中断送给core？ && 设置该中断优先级
	INTC_0.PSR[680].R = INT_CAN0RX_815_CORE_PRIORITY;		//将中断送给core？ && 设置该中断优先级
	/*CAN0 GPIO settings*/
	SIUL2.MSCR0_255[GPIO_PORTF+12].R = 0x32300008;  //CAN0 TX
	SIUL2.MSCR0_255[GPIO_PORTF+13].R = 0x00390000;  //CAN0 RX
	SIUL2.MSCR512_995[700-512].R = 0x00000004; //CAN0 RX input muxing

	/* enable the FlexCAN module, reset and freeze */
	    CAN_0.MCR.R = (0
	                    | CAN_MCR_FRZ  /* enabled to enter Freeze mode */
	                    | CAN_MCR_HALT /* enter freeze mode if FRZ bit is set */
	                    | CAN_MCR_SOFTRST /* soft reset */
	                    | 0x0000005F);

	    /* wait until soft reset completes */
	    while(1 == CAN_0.MCR.B.SOFTRST) {};
	    /* double check that we are actually in freeze mode */
	    while(0 == CAN_0.MCR.B.FRZACK) {};
	    while(0 == CAN_0.MCR.B.NOTRDY) {};

	    CAN_0.MCR.B.MAXMB = 63;		//最大MB为96，即0-95 共96个;需要在冻结模式下才能写入
	    CAN_0.MCR.B.IRMQ = 1;	//使能独立的掩码，不使用全局掩码;需要在冻结模式下才能写入
	    CAN_0.MCR.B.SRXDIS = 1;	//自身接收发送报文的能力关闭;需要在冻结模式下才能写入

	    CAN_0.CTRL1.R = 0x00DA0007; /* CAN bus: 8 MHz clksrc, 500K bps with 16 tq */
//	    CAN_0.CTRL1.B.RJW = 3;
//	    CAN_0.CTRL1.B.PROPSEG = 7;
//	    CAN_0.CTRL1.B.PSEG1 = 3;
//	    CAN_0.CTRL1.B.PSEG2 = 2;
	    CAN_0.CTRL1.B.BOFFREC = 1; /*Automatic recovering from Bus Off state disabled*/
	    if(BAUTRATE == 500)
	    {
	    	CAN_0.CTRL1.B.PRESDIV  = 0;			//BIT RATE = 8M / (0+1) /(16)=500k
	    }
	    else
	    {
	    	CAN_0.CTRL1.B.PRESDIV  = 1;			//BIT RATE = 8M / (1+1) /(16)=250k
	    }

	    /* Make first 96 message buffers inactive by writing their control fields
	     * to "not active". They will be left
	     * inactive until we're ready for communication. */
	    for(i=0;i<64;i++)
	    {
	        CAN_0.MB[i].CS.R = 0;
	        CAN_0.MB[i].ID.R = 0;
	        CAN_0.MB[i].DATA.W[0] = 0;
	        CAN_0.MB[i].DATA.W[1] = 0;
	    }

	    CAN_0.RXFGMASK.R = 0x1FFFFFFF;
	    CAN_0.RXMGMASK.R = 0x1FFFFFFF;
	    CAN_0.RX14MASK.R = 0x1FFFFFFF;
	    CAN_0.RX15MASK.R = 0x1FFFFFFF;

	    /* set mask registers - all ID bits must match */
	    for(i=0;i<64;i++)
	    {
	        CAN_0.RXIMR[i].R = 0x1FFFFFFF;
	    }
	    //CAN_0.RXIMR[0].R = 0x00; //MB0 接收所有报文


	    CAN_0.CTRL2.B.WRMFRZ = 1; // Enable Unrestricted Write Access to FlexCAN Memory

    	(*(volatile long long int *) (0xFFEB0000UL + 0xAB0))=0x0000000000000000; //TX_SMB
	    (*(volatile long long int *) (0xFFEB0000UL + 0xAB8))=0x0000000000000000; //TX_SMB

	    (*(volatile long long int *) (0xFFEB0000UL + 0xAC0))=0x0000000000000000; //RX_SMB0
	    (*(volatile long long int *) (0xFFEB0000UL + 0xAC8))=0x0000000000000000; //RX_SMB0

	    (*(volatile long long int *) (0xFFEB0000UL + 0xAD0))=0x0000000000000000; //RX_SMB1
	    (*(volatile long long int *) (0xFFEB0000UL + 0xAD8))=0x0000000000000000; //RX_SMB1

    	(*(volatile long int *) (0xFFEB0000UL + 0xA80))=0x00000000; //RX_FIR0
	    (*(volatile long int *) (0xFFEB0000UL + 0xA84))=0x00000000; //RX_FIR1

    	(*(volatile long int *) (0xFFEB0000UL + 0xA88))=0x00000000; //RX_FIR2
	    (*(volatile long int *) (0xFFEB0000UL + 0xA8C))=0x00000000; //RX_FIR3

    	(*(volatile long int *) (0xFFEB0000UL + 0xA90))=0x00000000; //RX_FIR4
	    (*(volatile long int *) (0xFFEB0000UL + 0xA94))=0x00000000; //RX_FIR5

	    (*(volatile long int *) (0xFFEB0000UL + 0xA98))=0x00000000; //Reserved Location 0xA98 to 0xA9B
	    (*(volatile long int *) (0xFFEB0000UL + 0xA9C))=0x00000000; //Reserved Location 0xA9C to 0xA9F

	    for(i=0;i<128;i++)
	    {
		    (*(volatile long long int *) (0xFFEB0000UL + 0x480 + (i*8))) = 0x0000000000000000; //Reserved Location from 0x480 to 0x87F
	    }

	    for(i=0;i<32;i++)
	    {
		    (*(volatile long long int *) (0xFFEB0000UL + 0x980 + (i*8))) = 0x0000000000000000; //Reserved Location from 0x980 to 0xA7F
	    }

	    CAN_0.CTRL2.B.WRMFRZ = 0; // Disable Unrestricted Write Access to FlexCAN Memory

	    CAN_0.IMASK1.R = 0x000003F8;	//使能MB的中断,使用10个接收.不给Core0的UDS使用
	    CAN_0.IMASK2.R = 0x00000000;	//
	    CAN_0.MCR.B.RFEN = 0;
	    CAN_0.MCR.B.FRZ = 0;
	    CAN_0.MCR.B.HALT = 0;

	    /* wait until FlexCAN ready */
	    while(1 == CAN_0.MCR.B.FRZACK) {};
	    while(1 == CAN_0.MCR.B.NOTRDY) {};

}

void FLEXCAN_1_Init(uint32_t BAUTRATE)	//MB has 96 (0-95) just using 64
{
    int i = 0;

	INTC_0.PSR[685].R = INT_CAN1RX_07_CORE_PRIORITY;				//将中断送给core1 && 设置该中断优先级
	/*CAN1 GPIO settings*/
	SIUL2.MSCR0_255[GPIO_PORTG+6].R = 0x32300008;  //CAN1 TX
	SIUL2.MSCR0_255[GPIO_PORTG+5].R = 0x00390000;  //CAN1 RX
	SIUL2.MSCR512_995[701-512].R = 0x00000003; //CAN1 RX input muxing

	/* enable the FlexCAN module, reset and freeze */
	    CAN_1.MCR.R = (0
	                    | CAN_MCR_FRZ  /* enabled to enter Freeze mode */
	                    | CAN_MCR_HALT /* enter freeze mode if FRZ bit is set */
	                    | CAN_MCR_SOFTRST /* soft reset */
	                    | 0x0000005F);


	    /* wait until soft reset completes */
	    while(1 == CAN_1.MCR.B.SOFTRST) {};
	    /* double check that we are actually in freeze mode */
	    while(0 == CAN_1.MCR.B.FRZACK) {};
	    while(0 == CAN_1.MCR.B.NOTRDY) {};

	    CAN_1.MCR.B.MAXMB = 63;		//最大MB为95，即0-95共96个;需要在冻结模式下才能写入
	    CAN_1.MCR.B.IRMQ = 1;	//使能独立的掩码，不使用全局掩码;需要在冻结模式下才能写入
	    CAN_1.MCR.B.SRXDIS = 1;	//自身接收发送报文的能力关闭;需要在冻结模式下才能写入

	    CAN_1.CTRL1.R = 0x00DA0007; /* CAN bus: 8 MHz clksrc, 500K bps with 16 tq */
//	    CAN_1.CTRL1.B.RJW = 3;
//	    CAN_1.CTRL1.B.PROPSEG = 7;
//	    CAN_1.CTRL1.B.PSEG1 = 3;
//	    CAN_1.CTRL1.B.PSEG2 = 2;
	    CAN_1.CTRL1.B.BOFFREC = 1; /*Automatic recovering from Bus Off state disabled*/
	    if(BAUTRATE == 500)
	    {
	    	CAN_1.CTRL1.B.PRESDIV  = 0;			//BIT RATE = 8M / (0+1) /(16)=500k
	    }
	    else
	    {
	    	CAN_1.CTRL1.B.PRESDIV  = 1;			//BIT RATE = 8M / (1+1) /(16)=250k
	    }

	    /* Make first 96 message buffers inactive by writing their control fields
	     * to "not active". They will be left
	     * inactive until we're ready for communication. */
	    for(i=0;i<64;i++)
	    {
	        CAN_1.MB[i].CS.R = 0;
	        CAN_1.MB[i].ID.R = 0;
	        CAN_1.MB[i].DATA.W[0] = 0;
	        CAN_1.MB[i].DATA.W[1] = 0;
	    }

	    CAN_1.RXFGMASK.R = 0x1FFFFFFF;
	    CAN_1.RXMGMASK.R = 0x1FFFFFFF;
	    CAN_1.RX14MASK.R = 0x1FFFFFFF;
	    CAN_1.RX15MASK.R = 0x1FFFFFFF;

	    /* set mask registers - all ID bits must match */
	    for(i=0;i<64;i++)
	    {
	        CAN_1.RXIMR[i].R = 0x1FFFFFFF;
	    }

	    CAN_1.RXIMR[1].R = 0x1C83FFFF;	//用于Core0的UDS接收

	    CAN_1.CTRL2.B.WRMFRZ = 1; // Enable Unrestricted Write Access to FlexCAN Memory

    	(*(volatile long long int *) (0xFBEB4000UL + 0xAB0))=0x0000000000000000; //TX_SMB
	    (*(volatile long long int *) (0xFBEB4000UL + 0xAB8))=0x0000000000000000; //TX_SMB

	    (*(volatile long long int *) (0xFBEB4000UL + 0xAC0))=0x0000000000000000; //RX_SMB0
	    (*(volatile long long int *) (0xFBEB4000UL + 0xAC8))=0x0000000000000000; //RX_SMB0

	    (*(volatile long long int *) (0xFBEB4000UL + 0xAD0))=0x0000000000000000; //RX_SMB1
	    (*(volatile long long int *) (0xFBEB4000UL + 0xAD8))=0x0000000000000000; //RX_SMB1

    	(*(volatile long int *) (0xFBEB4000UL + 0xA80))=0x00000000; //RX_FIR0
	    (*(volatile long int *) (0xFBEB4000UL + 0xA84))=0x00000000; //RX_FIR1

    	(*(volatile long int *) (0xFBEB4000UL + 0xA88))=0x00000000; //RX_FIR2
	    (*(volatile long int *) (0xFBEB4000UL + 0xA8C))=0x00000000; //RX_FIR3

    	(*(volatile long int *) (0xFBEB4000UL + 0xA90))=0x00000000; //RX_FIR4
	    (*(volatile long int *) (0xFBEB4000UL + 0xA94))=0x00000000; //RX_FIR5

	    (*(volatile long int *) (0xFBEB4000UL + 0xA98))=0x00000000; //Reserved Location 0xA98 to 0xA9B
	    (*(volatile long int *) (0xFBEB4000UL + 0xA9C))=0x00000000; //Reserved Location 0xA9C to 0xA9F

	    for(i=0;i<128;i++)
	    {
		    (*(volatile long long int *) (0xFBEB4000UL + 0x480 + (i*8))) = 0x0000000000000000; //Reserved Location from 0x480 to 0x87F
	    }

	    for(i=0;i<32;i++)
	    {
		    (*(volatile long long int *) (0xFBEB4000UL + 0x980 + (i*8))) = 0x0000000000000000; //Reserved Location from 0x980 to 0xA7F
	    }

	    CAN_1.CTRL2.B.WRMFRZ = 0; // Disable Unrestricted Write Access to FlexCAN Memory

	    CAN_1.IMASK1.R = 0x00000038;	//使能MB的中断,MB0用于Core0的发送,MB1用于Core0接收，MB2用于Core0的拓展ID接收
	    CAN_1.IMASK2.R = 0x00000000;	//
	    CAN_1.MCR.B.RFEN = 0;
	    CAN_1.MCR.B.FRZ = 0;
	    CAN_1.MCR.B.HALT = 0;

	    /* wait until FlexCAN ready */
	    while(1 == CAN_1.MCR.B.FRZACK) {};
	    while(1 == CAN_1.MCR.B.NOTRDY) {};
}

void FLEXCAN_2_Init(uint32_t BAUTRATE)
{
    int i = 0;

	INTC_0.PSR[691].R = INT_CAN2RX_07_CORE_PRIORITY;		//将中断送给core1 && 设置该中断优先级为30
	/*CAN2 GPIO settings*/
	SIUL2.MSCR0_255[GPIO_PORTG+2].R = 0x32300008;  //CAN2 TX
	SIUL2.MSCR0_255[GPIO_PORTG+1].R = 0x00390000;  //CAN2 RX
	SIUL2.MSCR512_995[702-512].R = 0x00000003; //CAN2 RX input muxing

	/* enable the FlexCAN module, reset and freeze */
	    CAN_2.MCR.R = (0
	                    | CAN_MCR_FRZ  /* enabled to enter Freeze mode */
	                    | CAN_MCR_HALT /* enter freeze mode if FRZ bit is set */
	                    | CAN_MCR_SOFTRST /* soft reset */
	                    | 0x0000003F);


	    /* wait until soft reset completes */
	    while(1 == CAN_2.MCR.B.SOFTRST) {};
	    /* double check that we are actually in freeze mode */
	    while(0 == CAN_2.MCR.B.FRZACK) {};
	    while(0 == CAN_2.MCR.B.NOTRDY) {};

	    CAN_2.MCR.B.MAXMB = 63;		//最大MB为63，即0-63 共64个;需要在冻结模式下才能写入
	    CAN_2.MCR.B.IRMQ = 1;	//使能独立的掩码，不使用全局掩码;需要在冻结模式下才能写入
	    CAN_2.MCR.B.SRXDIS = 1;	//自身接收发送报文的能力关闭;需要在冻结模式下才能写入

	    CAN_2.CTRL1.R = 0x00DA0007; /* CAN bus: 8 MHz clksrc, 500K bps with 16 tq */
//	    CAN_2.CTRL1.B.RJW = 3;
//	    CAN_2.CTRL1.B.PROPSEG = 7;
//	    CAN_2.CTRL1.B.PSEG1 = 3;
//	    CAN_2.CTRL1.B.PSEG2 = 2;
	    CAN_2.CTRL1.B.BOFFREC = 1; /*Automatic recovering from Bus Off state disabled*/
	    if(BAUTRATE == 500)
	    {
	    	CAN_2.CTRL1.B.PRESDIV  = 0;			//BIT RATE = 8M / (0+1) /(16)=500k
	    }
	    else
	    {
	    	CAN_2.CTRL1.B.PRESDIV  = 1;			//BIT RATE = 8M / (1+1) /(16)=250k
	    }

	    /* Make first 96 message buffers inactive by writing their control fields
	     * to "not active". They will be left
	     * inactive until we're ready for communication. */
	    for(i=0;i<64;i++)
	    {
	        CAN_2.MB[i].CS.R = 0;
	        CAN_2.MB[i].ID.R = 0;
	        CAN_2.MB[i].DATA.W[0] = 0;
	        CAN_2.MB[i].DATA.W[1] = 0;
	    }

	    CAN_2.RXFGMASK.R = 0x1FFFFFFF;
	    CAN_2.RXMGMASK.R = 0x1FFFFFFF;
	    CAN_2.RX14MASK.R = 0x1FFFFFFF;
	    CAN_2.RX15MASK.R = 0x1FFFFFFF;

	    /* set mask registers - all ID bits must match */
	    for(i=0;i<64;i++)
	    {
	        CAN_2.RXIMR[i].R = 0x1FFFFFFF;
	    }

	    CAN_2.RXIMR[1].R = 0x1C83FFFF;	//用于Core0的UDS接收

	    CAN_2.CTRL2.B.WRMFRZ = 1; // Enable Unrestricted Write Access to FlexCAN Memory

    	(*(volatile long long int *) (0xFFEB8000UL + 0xAB0))=0x0000000000000000; //TX_SMB
	    (*(volatile long long int *) (0xFFEB8000UL + 0xAB8))=0x0000000000000000; //TX_SMB

	    (*(volatile long long int *) (0xFFEB8000UL + 0xAC0))=0x0000000000000000; //RX_SMB0
	    (*(volatile long long int *) (0xFFEB8000UL + 0xAC8))=0x0000000000000000; //RX_SMB0

	    (*(volatile long long int *) (0xFFEB8000UL + 0xAD0))=0x0000000000000000; //RX_SMB1
	    (*(volatile long long int *) (0xFFEB8000UL + 0xAD8))=0x0000000000000000; //RX_SMB1

    	(*(volatile long int *) (0xFFEB8000UL + 0xA80))=0x00000000; //RX_FIR0
	    (*(volatile long int *) (0xFFEB8000UL + 0xA84))=0x00000000; //RX_FIR1

    	(*(volatile long int *) (0xFFEB8000UL + 0xA88))=0x00000000; //RX_FIR2
	    (*(volatile long int *) (0xFFEB8000UL + 0xA8C))=0x00000000; //RX_FIR3

    	(*(volatile long int *) (0xFFEB8000UL + 0xA90))=0x00000000; //RX_FIR4
	    (*(volatile long int *) (0xFFEB8000UL + 0xA94))=0x00000000; //RX_FIR5

	    (*(volatile long int *) (0xFFEB8000UL + 0xA98))=0x00000000; //Reserved Location 0xA98 to 0xA9B
	    (*(volatile long int *) (0xFFEB8000UL + 0xA9C))=0x00000000; //Reserved Location 0xA9C to 0xA9F

	    for(i=0;i<128;i++)
	    {
		    (*(volatile long long int *) (0xFFEB8000UL + 0x480 + (i*8))) = 0x0000000000000000; //Reserved Location from 0x480 to 0x87F
	    }

	    for(i=0;i<32;i++)
	    {
		    (*(volatile long long int *) (0xFFEB8000UL + 0x980 + (i*8))) = 0x0000000000000000; //Reserved Location from 0x980 to 0xA7F
	    }

	    CAN_2.CTRL2.B.WRMFRZ = 0; // Disable Unrestricted Write Access to FlexCAN Memory

	    CAN_2.IMASK1.R = 0x0000000C;	//使能MB的中断,使用4个接收，MB0用于Core0的发送,MB1用于Core0接收
	    CAN_2.IMASK2.R = 0x0000000;
	    CAN_2.MCR.B.RFEN = 0;
	    CAN_2.MCR.B.FRZ = 0;
	    CAN_2.MCR.B.HALT = 0;

	    /* wait until FlexCAN ready */
	    while(1 == CAN_2.MCR.B.FRZACK) {};
	    while(1 == CAN_2.MCR.B.NOTRDY) {};
}

void FLEXCAN_3_Init(uint32_t BAUTRATE)
{
    int i = 0;

	INTC_0.PSR[697].R = INT_CAN3RX_07_CORE_PRIORITY;		//将中断送给core1 && 设置该中断优先级
	INTC_0.PSR[698].R = INT_CAN3RX_815_CORE_PRIORITY;
	INTC_0.PSR[699].R = INT_CAN3RX_1631_CORE_PRIORITY;
	INTC_0.PSR[700].R = INT_CAN3RX_3263_CORE_PRIORITY;
	/*CAN3 GPIO settings*/
	SIUL2.MSCR0_255[GPIO_PORTI+1].R = 0x32300008;  //CAN3 TX
	SIUL2.MSCR0_255[GPIO_PORTI+0].R = 0x00390000;  //CAN3 RX
	SIUL2.MSCR512_995[703-512].R = 0x00000002; //CAN3 RX input muxing
	/* enable the FlexCAN module, reset and freeze */
	    CAN_3.MCR.R = (0
	                    | CAN_MCR_FRZ  /* enabled to enter Freeze mode */
	                    | CAN_MCR_HALT /* enter freeze mode if FRZ bit is set */
	                    | CAN_MCR_SOFTRST /* soft reset */
	                    | 0x0000003F);


	    /* wait until soft reset completes */
	    while(1 == CAN_3.MCR.B.SOFTRST) {};
	    /* double check that we are actually in freeze mode */
	    while(0 == CAN_3.MCR.B.FRZACK) {};
	    while(0 == CAN_3.MCR.B.NOTRDY) {};

	    CAN_3.MCR.B.MAXMB = 63;		//最大MB为63，即0-63 共64个;需要在冻结模式下才能写入
	    CAN_3.MCR.B.IRMQ = 1;	//使能独立的掩码，不使用全局掩码;需要在冻结模式下才能写入
	    CAN_3.MCR.B.SRXDIS = 1;	//自身接收发送报文的能力关闭;需要在冻结模式下才能写入

	    CAN_3.CTRL1.R = 0x00DA0007; /* CAN bus: 8 MHz clksrc, 500K bps with 16 tq */
//	    CAN_3.CTRL1.B.RJW = 3;
//	    CAN_3.CTRL1.B.PROPSEG = 7;
//	    CAN_3.CTRL1.B.PSEG1 = 3;
//	    CAN_3.CTRL1.B.PSEG2 = 2;
	    CAN_3.CTRL1.B.BOFFREC = 1; /*Automatic recovering from Bus Off state disabled*/
	    if(BAUTRATE == 500)
	    {
	    	CAN_3.CTRL1.B.PRESDIV  = 0;			//BIT RATE = 8M / (0+1) /(16)=500k
	    }
	    else
	    {
	    	CAN_3.CTRL1.B.PRESDIV  = 1;			//BIT RATE = 8M / (1+1) /(16)=250k
	    }

	    /* Make first 96 message buffers inactive by writing their control fields
	     * to "not active". They will be left
	     * inactive until we're ready for communication. */
	    for(i=0;i<64;i++)
	    {
	        CAN_3.MB[i].CS.R = 0;
	        CAN_3.MB[i].ID.R = 0;
	        CAN_3.MB[i].DATA.W[0] = 0;
	        CAN_3.MB[i].DATA.W[1] = 0;
	    }

	    CAN_3.RXFGMASK.R = 0x1FFFFFFF;
	    CAN_3.RXMGMASK.R = 0x1FFFFFFF;
	    CAN_3.RX14MASK.R = 0x1FFFFFFF;
	    CAN_3.RX15MASK.R = 0x1FFFFFFF;

	    /* set mask registers - all ID bits must match */
	    for(i=0;i<64;i++)
	    {
	        CAN_3.RXIMR[i].R = 0x1FFFFFFF;		//所有信号需要完全符合ID才会接收
	    }
	    CAN_3.RXIMR[1].R = 0x1C83FFFF;	//用于Core0的UDS接收
	    CAN_3.RXIMR[32].R = 0x1C000000;		//所有信号需要符合IDmask才会接收;为网络管理的动态建环提供基础。接收0x400-0x4FF的报文，除了0x406之外

	    CAN_3.CTRL2.B.WRMFRZ = 1; // Enable Unrestricted Write Access to FlexCAN Memory

    	(*(volatile long long int *) (0xFBEBC000UL + 0xAB0))=0x0000000000000000; //TX_SMB
	    (*(volatile long long int *) (0xFBEBC000UL + 0xAB8))=0x0000000000000000; //TX_SMB

	    (*(volatile long long int *) (0xFBEBC000UL + 0xAC0))=0x0000000000000000; //RX_SMB0
	    (*(volatile long long int *) (0xFBEBC000UL + 0xAC8))=0x0000000000000000; //RX_SMB0

	    (*(volatile long long int *) (0xFBEBC000UL + 0xAD0))=0x0000000000000000; //RX_SMB1
	    (*(volatile long long int *) (0xFBEBC000UL + 0xAD8))=0x0000000000000000; //RX_SMB1

    	(*(volatile long int *) (0xFBEBC000UL + 0xA80))=0x00000000; //RX_FIR0
	    (*(volatile long int *) (0xFBEBC000UL + 0xA84))=0x00000000; //RX_FIR1

    	(*(volatile long int *) (0xFBEBC000UL + 0xA88))=0x00000000; //RX_FIR2
	    (*(volatile long int *) (0xFBEBC000UL + 0xA8C))=0x00000000; //RX_FIR3

    	(*(volatile long int *) (0xFBEBC000UL + 0xA90))=0x00000000; //RX_FIR4
	    (*(volatile long int *) (0xFBEBC000UL + 0xA94))=0x00000000; //RX_FIR5

	    (*(volatile long int *) (0xFBEBC000UL + 0xA98))=0x00000000; //Reserved Location 0xA98 to 0xA9B
	    (*(volatile long int *) (0xFBEBC000UL + 0xA9C))=0x00000000; //Reserved Location 0xA9C to 0xA9F

	    for(i=0;i<128;i++)
	    {
		    (*(volatile long long int *) (0xFBEBC000UL + 0x480 + (i*8))) = 0x0000000000000000; //Reserved Location from 0x480 to 0x87F
	    }

	    for(i=0;i<32;i++)
	    {
		    (*(volatile long long int *) (0xFBEBC000UL + 0x980 + (i*8))) = 0x0000000000000000; //Reserved Location from 0x980 to 0xA7F
	    }

	    CAN_3.CTRL2.B.WRMFRZ = 0; // Disable Unrestricted Write Access to FlexCAN Memory

//@@@@	    CAN_3.IMASK1.R = 0xFFFFFFFC;	//使能MB的中断,使用51个接收. MB0用于Core0的发送,MB1用于Core0接收
	    CAN_3.IMASK1.R = 0xFFFFFFFE;	//使能MB的中断,使用51个接收. MB0用于Core0的发送,MB1用于Core0接收
	    CAN_3.IMASK2.R = 0x0007FFFF;	//
	    CAN_3.MCR.B.RFEN = 0;
	    CAN_3.MCR.B.FRZ = 0;
	    CAN_3.MCR.B.HALT = 0;

	    /* wait until FlexCAN ready */
	    while(1 == CAN_3.MCR.B.FRZACK) {};
	    while(1 == CAN_3.MCR.B.NOTRDY) {};
}




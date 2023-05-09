/*
 * Interrupt.c
 *
 *  Created on: 2018年9月6日
 *      Author: helei
 */

#define __INTERRPUT_GLOBALS__

#include "derivative.h"
#include "BASE_Global.h"
#include "Modules_Global.h"
#include "Global.h" 
#include "Interrupt.h"
#include "Task.h"
#include "CAN_Operation.h"
#include "CAN_DBC_Lib.h"
#include "System.h"

/************************************** for CAN ******/

void INT_CAN0_RX_ISR (void)
{
    uint8_t i = 0;
    boolean ValidMsg = 0;
    uint32_t temp = 0;
    StartTimer(5);	//开始精准计时
    i = 3;	//前3个MB给Core0使用
    for(; i < CAN0_RX_NUM; i++)	//初始值为本地开始的接收值，排除Core0的接收和发送
    {
        if( ((CAN_0.IFLAG1.R >> i) & (0x01)) == 0x01 )
        {
            CAN_0.IFLAG1.R = (0x01 << i);	//clear interrupt flag
            if( i < CSCAN_RxReal_Num )	//底盘CAN
            {
                ValidMsg = CAN_Recive_Get(CAN0, i, SystemTickMs);
                CAN_0.MB[i].CS.B.CODE = 0x04;	//MB empty - ready for receive
                if( TRUE == ValidMsg )
                {
                    CAN0Rx_Handle(CAN0_RX_Array[i].control.id);
                }
            }
        }
    }
    temp = GetTimerAndShut(5);
    TimeofAllInt += temp;
    TimeofIntCANRX_temp += temp;
}

void INT_CAN1_RX_ISR (void)	//using for diagnostic
{
    uint8_t i = 0;
    boolean ValidMsg = 0;
    uint32_t temp = 0;
    StartTimer(5);	//开始精准计时

    for(i = 3; i < CAN1_RX_NUM; i++)	//初始值为本地开始的接收值，排除Core0的接收和发送
    {
        if( ((CAN_1.IFLAG1.R >> i) & (0x01)) == 0x01 )
        {
            CAN_1.IFLAG1.R = (0x01 << i);	//clear interrupt flag
            ValidMsg = CAN_Recive_Get(CAN1, i, SystemTickMs);
            CAN_1.MB[i].CS.B.CODE = 0x04; //MB empty - ready for receive
            if( TRUE == ValidMsg )
            {
                CAN1Rx_Handle(CAN1_RX_Array[i].control.id);
            }
        }
    }
    temp = GetTimerAndShut(5);
    TimeofAllInt += temp;
    TimeofIntCANRX_temp += temp;
}

void INT_CAN2_RX_ISR (void)
{
    uint8_t i = 0;
    boolean ValidMsg = 0;
    uint32_t temp = 0;
    StartTimer(5);	//开始精准计时

    for(i = 2; i < CAN2_RX_NUM; i++)	//初始值为本地开始的接收值，排除Core0的接收和发送
    {
        if( ((CAN_2.IFLAG1.R >> i) & (0x01)) == 0x01 )
        {
            CAN_2.IFLAG1.R = (0x01 << i);	//clear interrupt flag
            ValidMsg = CAN_Recive_Get(CAN2, i, SystemTickMs);
            CAN_2.MB[i].CS.B.CODE = 0x04;	//MB empty - ready for receive
            if( TRUE == ValidMsg )
            {
                CAN2Rx_Handle(CAN2_RX_Array[i].control.id);
            }
        }
    }
    temp = GetTimerAndShut(5);
    TimeofAllInt += temp;
    TimeofIntCANRX_temp += temp;
}

void INT_CAN3_RX_ISR (void)
{
    uint8_t i = 0;
    boolean ValidMsg = 0;
    uint32_t flag = 0;
    uint32_t temp = 0;
    StartTimer(5);	//开始精准计时

    for(i = 2; i < CAN3_RX_NUM; i++)	//初始值为本地开始的接收值，排除Core0的接收和发送
    {
        if( i < 32 )
        {
            if( ((CAN_3.IFLAG1.R >> i) & (0x01)) == 0x01 )
            {
                CAN_3.IFLAG1.R = (0x01 << i);	//clear interrupt flag
                ValidMsg = CAN_Recive_Get(CAN3, i, SystemTickMs);
                CAN_3.MB[i].CS.B.CODE = 0x04; //MB empty - ready for receive
                if( TRUE == ValidMsg )
                {
                    CAN3Rx_Handle(CAN3_RX_Array[i].control.id);
                }
            }
        }
        else
        {
            if( ((CAN_3.IFLAG2.R >> (i - 32)) & (0x01)) == 0x01 )
            {
                CAN_3.IFLAG2.R = (0x01 << (i - 32));	//clear interrupt flag
                if( i < PTCAN_RxReal_Num )	//PTCAN 接收
                {
                    if( (32 == i) && (CAN_3.MB[i].ID.B_STD.ID != 0x406) )	//GW_4xx,但不为406
                    {
                        ValidMsg = CAN_Recive_GetWithID(CAN3, i, SystemTickMs);
                        if( TRUE == ValidMsg )
                        {
                            flag = CAN_GetValue((&CAN3_RX_Array[32].data.R8[0]), 13, 1);
                            if( (1 == flag) && (1 == VHALO_NMSendIndication) )	//如果4xx的ACK为1,且本身满足睡眠条件
                            {
                                NM_ReACKandCanStop = 1;
                                NM_ShutAll_CANTxPeriodMessage();	//关闭所有周期报文
                                NM_Twbs = NM_Begin_Twbs;
                            }
                        }
                    }
                    else
                    {
                        ValidMsg = CAN_Recive_Get(CAN3, i, SystemTickMs);
                    }
                    CAN_3.MB[i].CS.B.CODE = 0x04; //MB empty - ready for receive
                    if( TRUE == ValidMsg )
                    {
                        CAN3Rx_Handle(CAN3_RX_Array[i].control.id);
                    }
                }
            }
        }
    }
    temp = GetTimerAndShut(5);
    TimeofAllInt += temp;
    TimeofIntCANRX_temp += temp;
}

/************************************** for ENET FEC   ******/

void INT_ENET_TX_ISR(void)
{
  EnetTxTick ++;

  ENET_SetTxStatusComplete();	//设置发送成功
  FEC.EIR.B.TXF = 1;  //Clear interrupt
}

void INT_ENET_RX_ISR(void)
{
  EnetRxTick ++ ;

  ENET_CopyRxFrame ();
  Eth_receive();
  ENET_StartReceive ();
 

  FEC.EIR.B.RXF = 1;  // Clear interrupt
}

/************************************** for Real Time ******/

/*
 * Name:		INT_RT_ISR
 * Function:	Real Timer 中断函数。用于时间片的划分
 * Input:		null
 * Return:		null
 * Link:		SYS_RT_Init();SystemTickMs、tick_*。
 * Attention:	null
 * */

uint32_t SystemTickMs_new = 0;
uint8_t   SystemTickMs_switch_flag = 1;

uint32_t SystemTickUs_new =0;
uint32_t SystemTickUs_new_last =0;

void INT_RT_ISR(void)
{
  static uint8_t rt_times = 0;
  uint8_t loop =0;
  uint32_t temp = 0;
  StartTimer(5);	//开始精准计时
       static uint8_t init_flag =0;
  SystemTickMs++;			//系统时间计数全局变量加1

  rt_times++;
  CANReTransimitPeriodMessage();

  if (rt_times >= 5)
    {
      rt_times = 0;
      tick_SBCDog++;
      Task_NM();

      /*  SBC dog feed cycle*/
      if (tick_SBCDog >= 60)	//270ms feeddog for windows 512
	{
	  tick_SBCDog_flag = 1;
	  tick_SBCDog = 0;
	}
    }
  PIT_0.RTI_TFLG.B.TIF = 1;	//中断标志位 写一清零(w1c)

  temp = GetTimerAndShut(5);
  TimeofAllInt += temp;
  TimeofIntRT_temp += temp;


       /*get new systemtickMs from SystemTickUs_new*/
        SystemTickUs_new = ((STM_0.CNT.R & 0x3FFFFFFF)<<2); //每4us加1.

        if(init_flag==0)
        {
            init_flag=1;
            SystemTickUs_new_last = SystemTickUs_new;
        }
        for(loop=0;loop<2;loop++)
        {
                /*如果超过了1秒，就跳1秒*/
                if((SystemTickUs_new-SystemTickUs_new_last)>1000000)
                {
                    SystemTickMs_new = SystemTickMs_new+1000;
                    SystemTickUs_new_last = SystemTickUs_new_last+1000000;
                } 
                /*如果超过了100毫秒，就跳100毫秒*/
                else if((SystemTickUs_new-SystemTickUs_new_last)>100000)
                {
                    SystemTickMs_new = SystemTickMs_new+100;
                    SystemTickUs_new_last = SystemTickUs_new_last+100000;
                } 
                /*如果超过了10毫秒，就跳10毫秒*/
                else if((SystemTickUs_new-SystemTickUs_new_last)>10000)
                {
                    SystemTickMs_new = SystemTickMs_new+10;
                    SystemTickUs_new_last = SystemTickUs_new_last+10000;
                } 
            
                /* 如果超过了1毫秒，就跳1毫秒*/
                else if((SystemTickUs_new-SystemTickUs_new_last)>1000)
                {
                    SystemTickMs_new = SystemTickMs_new+1;
                    SystemTickUs_new_last = SystemTickUs_new_last+1000;
                }
                else
                {
                    break;
                }
        }
        if( SystemTickMs_switch_flag)
        {
            SystemTickMs= SystemTickMs_new; /* 用新的ms时钟替换老的时钟。*/
        }
}

void INT_PIT0_0_ISR(void)
{
	PIT_0.TIMER[0].TFLG.B.TIF	= 1;	//中断标志位 写一清零(w1c)
}

void INT_PIT0_1_ISR(void)
{
    uint32_t temp = 0;
    StartTimer(5);	//开始精准计时

    PIT_0.TIMER[1].TFLG.B.TIF = 1;
    SystemTick10Ms += 10;
    if( (AppBeginRunning_flg == 1) && (1 != VHALO_DisableAppComm) && (1 != NM_ReACKandCanStop) )
    {
        CanTx_Handle();         //发送处理
        CAN_PeriodSendTime = SystemTickMs;
    }

    temp = GetTimerAndShut(5);
    TimeofAllInt += temp;
    TimeofIntPIT_temp += temp;
}

/************************************** for PWMin ******/
/************************************************************************** eMIOS0 ************/
void INT_eMIOS0_8_ISR(void)		//采集通道值
{
	eMIOS_0.S8.B.FLAG	= 1;	//清除中断标志
	if(eMIOS_PWMin_data[eMIOS_0_08].flag == unlock)
	{
		eMIOS_PWMin_data[eMIOS_0_08].A_pre = eMIOS_PWMin_data[eMIOS_0_08].A;
		eMIOS_PWMin_data[eMIOS_0_08].A = eMIOS_0.A8.B.A;
		eMIOS_PWMin_data[eMIOS_0_08].B = eMIOS_0.B8.B.B;
	}
	eMIOS_PWMin_data[eMIOS_0_08].stoptick = 0;
}

void INT_eMIOS0_9_ISR(void)		//采集通道值
{
	eMIOS_0.S9.B.FLAG	= 1;	//清除中断标志
	if(eMIOS_PWMin_data[eMIOS_0_09].flag == unlock)
	{
		eMIOS_PWMin_data[eMIOS_0_09].A_pre = eMIOS_PWMin_data[eMIOS_0_09].A;
		eMIOS_PWMin_data[eMIOS_0_09].A = eMIOS_0.A9.B.A;
		eMIOS_PWMin_data[eMIOS_0_09].B = eMIOS_0.B9.B.B;
	}
	eMIOS_PWMin_data[eMIOS_0_09].stoptick = 0;
}



void INT_eMIOS0_10_ISR(void)		//采集通道值
{
	eMIOS_0.S10.B.FLAG	= 1;	//清除中断标志
	if(eMIOS_PWMin_data[eMIOS_0_10].flag == unlock)
	{
		eMIOS_PWMin_data[eMIOS_0_10].A_pre = eMIOS_PWMin_data[eMIOS_0_10].A;
		eMIOS_PWMin_data[eMIOS_0_10].A = eMIOS_0.A10.B.A;
		eMIOS_PWMin_data[eMIOS_0_10].B = eMIOS_0.B10.B.B;
	}
	eMIOS_PWMin_data[eMIOS_0_10].stoptick = 0;
}

void INT_eMIOS0_11_ISR(void)		//采集通道值
{
	eMIOS_0.S11.B.FLAG	= 1;	//清除中断标志
	if(eMIOS_PWMin_data[eMIOS_0_11].flag == unlock)
	{
		eMIOS_PWMin_data[eMIOS_0_11].A_pre = eMIOS_PWMin_data[eMIOS_0_11].A;
		eMIOS_PWMin_data[eMIOS_0_11].A = eMIOS_0.A11.B.A;
		eMIOS_PWMin_data[eMIOS_0_11].B = eMIOS_0.B11.B.B;
	}
	eMIOS_PWMin_data[eMIOS_0_11].stoptick = 0;
}

void INT_eMIOS0_12_ISR(void)		//采集通道值
{
	eMIOS_0.S12.B.FLAG	= 1;	//清除中断标志
	if(eMIOS_PWMin_data[eMIOS_0_12].flag == unlock)
	{
		eMIOS_PWMin_data[eMIOS_0_12].A_pre = eMIOS_PWMin_data[eMIOS_0_12].A;
		eMIOS_PWMin_data[eMIOS_0_12].A = eMIOS_0.A12.B.A;
		eMIOS_PWMin_data[eMIOS_0_12].B = eMIOS_0.B12.B.B;
	}
	eMIOS_PWMin_data[eMIOS_0_12].stoptick = 0;
}

void INT_eMIOS0_13_ISR(void)		//采集通道值
{
	eMIOS_0.S13.B.FLAG	= 1;	//清除中断标志
	if(eMIOS_PWMin_data[eMIOS_0_13].flag == unlock)
	{
		eMIOS_PWMin_data[eMIOS_0_13].A_pre = eMIOS_PWMin_data[eMIOS_0_13].A;
		eMIOS_PWMin_data[eMIOS_0_13].A = eMIOS_0.A13.B.A;
		eMIOS_PWMin_data[eMIOS_0_13].B = eMIOS_0.B13.B.B;
	}
	eMIOS_PWMin_data[eMIOS_0_13].stoptick = 0;
}

void INT_eMIOS0_14_ISR(void)		//采集通道值
{
	eMIOS_0.S14.B.FLAG	= 1;	//清除中断标志
	if(eMIOS_PWMin_data[eMIOS_0_14].flag == unlock)
	{
		eMIOS_PWMin_data[eMIOS_0_14].A_pre = eMIOS_PWMin_data[eMIOS_0_14].A;
		eMIOS_PWMin_data[eMIOS_0_14].A = eMIOS_0.A14.B.A;
		eMIOS_PWMin_data[eMIOS_0_14].B = eMIOS_0.B14.B.B;
	}
	eMIOS_PWMin_data[eMIOS_0_14].stoptick = 0;
}

void INT_eMIOS0_15_ISR(void)		//采集通道值
{
	eMIOS_0.S15.B.FLAG	= 1;	//清除中断标志
	if(eMIOS_PWMin_data[eMIOS_0_15].flag == unlock)
	{
		eMIOS_PWMin_data[eMIOS_0_15].A_pre = eMIOS_PWMin_data[eMIOS_0_15].A;
		eMIOS_PWMin_data[eMIOS_0_15].A = eMIOS_0.A15.B.A;
		eMIOS_PWMin_data[eMIOS_0_15].B = eMIOS_0.B15.B.B;
	}
	eMIOS_PWMin_data[eMIOS_0_15].stoptick = 0;
}

void INT_eMIOS0_16_ISR(void)		//采集通道值
{
	eMIOS_0.S16.B.FLAG	= 1;	//清除中断标志
	if(eMIOS_PWMin_data[eMIOS_0_16].flag == unlock)
	{
		eMIOS_PWMin_data[eMIOS_0_16].A_pre = eMIOS_PWMin_data[eMIOS_0_16].A;
		eMIOS_PWMin_data[eMIOS_0_16].A = eMIOS_0.A16.B.A;
		eMIOS_PWMin_data[eMIOS_0_16].B = eMIOS_0.B16.B.B;
	}
	eMIOS_PWMin_data[eMIOS_0_16].stoptick = 0;
}

void INT_eMIOS0_17_ISR(void)		//采集通道值
{
	eMIOS_0.S17.B.FLAG	= 1;	//清除中断标志
	if(eMIOS_PWMin_data[eMIOS_0_17].flag == unlock)
	{
		eMIOS_PWMin_data[eMIOS_0_17].A_pre = eMIOS_PWMin_data[eMIOS_0_17].A;
		eMIOS_PWMin_data[eMIOS_0_17].A = eMIOS_0.A17.B.A;
		eMIOS_PWMin_data[eMIOS_0_17].B = eMIOS_0.B17.B.B;
	}
	eMIOS_PWMin_data[eMIOS_0_17].stoptick = 0;
}

void INT_eMIOS0_18_ISR(void)		//采集通道值
{
	eMIOS_0.S18.B.FLAG	= 1;	//清除中断标志
	if(eMIOS_PWMin_data[eMIOS_0_18].flag == unlock)
	{
		eMIOS_PWMin_data[eMIOS_0_18].A_pre = eMIOS_PWMin_data[eMIOS_0_18].A;
		eMIOS_PWMin_data[eMIOS_0_18].A = eMIOS_0.A18.B.A;
		eMIOS_PWMin_data[eMIOS_0_18].B = eMIOS_0.B18.B.B;
	}
	eMIOS_PWMin_data[eMIOS_0_18].stoptick = 0;
}

void INT_eMIOS0_19_ISR(void)		//采集通道值
{
	eMIOS_0.S19.B.FLAG	= 1;	//清除中断标志
	if(eMIOS_PWMin_data[eMIOS_0_19].flag == unlock)
	{
		eMIOS_PWMin_data[eMIOS_0_19].A_pre = eMIOS_PWMin_data[eMIOS_0_19].A;
		eMIOS_PWMin_data[eMIOS_0_19].A = eMIOS_0.A19.B.A;
		eMIOS_PWMin_data[eMIOS_0_19].B = eMIOS_0.B19.B.B;
	}
	eMIOS_PWMin_data[eMIOS_0_19].stoptick = 0;
}

void INT_eMIOS0_20_ISR(void)		//采集通道值
{
	eMIOS_0.S20.B.FLAG	= 1;	//清除中断标志
	if(eMIOS_PWMin_data[eMIOS_0_20].flag == unlock)
	{
		eMIOS_PWMin_data[eMIOS_0_20].A_pre = eMIOS_PWMin_data[eMIOS_0_20].A;
		eMIOS_PWMin_data[eMIOS_0_20].A = eMIOS_0.A20.B.A;
		eMIOS_PWMin_data[eMIOS_0_20].B = eMIOS_0.B20.B.B;
	}
	eMIOS_PWMin_data[eMIOS_0_20].stoptick = 0;
}

void INT_eMIOS0_21_ISR(void)		//采集通道值
{
	eMIOS_0.S21.B.FLAG	= 1;	//清除中断标志
	if(eMIOS_PWMin_data[eMIOS_0_21].flag == unlock)
	{
		eMIOS_PWMin_data[eMIOS_0_21].A_pre = eMIOS_PWMin_data[eMIOS_0_21].A;
		eMIOS_PWMin_data[eMIOS_0_21].A = eMIOS_0.A21.B.A;
		eMIOS_PWMin_data[eMIOS_0_21].B = eMIOS_0.B21.B.B;
	}
	eMIOS_PWMin_data[eMIOS_0_21].stoptick = 0;
}

void INT_eMIOS0_22_ISR(void)		//采集通道值
{
	eMIOS_0.S22.B.FLAG	= 1;	//清除中断标志
	if(eMIOS_PWMin_data[eMIOS_0_22].flag == unlock)
	{
		eMIOS_PWMin_data[eMIOS_0_22].A_pre = eMIOS_PWMin_data[eMIOS_0_22].A;
		eMIOS_PWMin_data[eMIOS_0_22].A = eMIOS_0.A22.B.A;
		eMIOS_PWMin_data[eMIOS_0_22].B = eMIOS_0.B22.B.B;
	}
	eMIOS_PWMin_data[eMIOS_0_22].stoptick = 0;
}

/************************************************************************** eMIOS1 ************/

void INT_eMIOS1_8_ISR(void)		//采集通道值
{
	eMIOS_1.S8.B.FLAG	= 1;	//清除中断标志
	if(eMIOS_PWMin_data[eMIOS_1_08].flag == unlock)
	{
		eMIOS_PWMin_data[eMIOS_1_08].A_pre = eMIOS_PWMin_data[eMIOS_1_08].A;
		eMIOS_PWMin_data[eMIOS_1_08].A = eMIOS_1.A8.B.A;
		eMIOS_PWMin_data[eMIOS_1_08].B = eMIOS_1.B8.B.B;
	}
	eMIOS_PWMin_data[eMIOS_1_08].stoptick = 0;
}

void INT_eMIOS1_9_ISR(void)		//采集通道值
{
	eMIOS_1.S9.B.FLAG	= 1;	//清除中断标志
	if(eMIOS_PWMin_data[eMIOS_1_09].flag == unlock)
	{
		eMIOS_PWMin_data[eMIOS_1_09].A_pre = eMIOS_PWMin_data[eMIOS_1_09].A;
		eMIOS_PWMin_data[eMIOS_1_09].A = eMIOS_1.A9.B.A;
		eMIOS_PWMin_data[eMIOS_1_09].B = eMIOS_1.B9.B.B;
	}
	eMIOS_PWMin_data[eMIOS_1_09].stoptick = 0;
}

void INT_eMIOS1_10_ISR(void)		//采集通道值
{
	eMIOS_1.S10.B.FLAG	= 1;	//清除中断标志
	if(eMIOS_PWMin_data[eMIOS_1_10].flag == unlock)
	{
		eMIOS_PWMin_data[eMIOS_1_10].A_pre = eMIOS_PWMin_data[eMIOS_1_10].A;
		eMIOS_PWMin_data[eMIOS_1_10].A = eMIOS_1.A10.B.A;
		eMIOS_PWMin_data[eMIOS_1_10].B = eMIOS_1.B10.B.B;
	}
	eMIOS_PWMin_data[eMIOS_1_10].stoptick = 0;
}

void INT_eMIOS1_11_ISR(void)		//采集通道值
{
	eMIOS_1.S11.B.FLAG	= 1;	//清除中断标志
	if(eMIOS_PWMin_data[eMIOS_1_11].flag == unlock)
	{
		eMIOS_PWMin_data[eMIOS_1_11].A_pre = eMIOS_PWMin_data[eMIOS_1_11].A;
		eMIOS_PWMin_data[eMIOS_1_11].A = eMIOS_1.A11.B.A;
		eMIOS_PWMin_data[eMIOS_1_11].B = eMIOS_1.B11.B.B;
	}
	eMIOS_PWMin_data[eMIOS_1_11].stoptick = 0;
}

void INT_eMIOS1_12_ISR(void)		//采集通道值
{
	eMIOS_1.S12.B.FLAG	= 1;	//清除中断标志
	if(eMIOS_PWMin_data[eMIOS_1_12].flag == unlock)
	{
		eMIOS_PWMin_data[eMIOS_1_12].A_pre = eMIOS_PWMin_data[eMIOS_1_12].A;
		eMIOS_PWMin_data[eMIOS_1_12].A = eMIOS_1.A12.B.A;
		eMIOS_PWMin_data[eMIOS_1_12].B = eMIOS_1.B12.B.B;
	}
	eMIOS_PWMin_data[eMIOS_1_12].stoptick = 0;
}

void INT_eMIOS1_13_ISR(void)		//采集通道值
{
	eMIOS_1.S13.B.FLAG	= 1;	//清除中断标志
	if(eMIOS_PWMin_data[eMIOS_1_13].flag == unlock)
	{
		eMIOS_PWMin_data[eMIOS_1_13].A_pre = eMIOS_PWMin_data[eMIOS_1_13].A;
		eMIOS_PWMin_data[eMIOS_1_13].A = eMIOS_1.A13.B.A;
		eMIOS_PWMin_data[eMIOS_1_13].B = eMIOS_1.B13.B.B;
	}
	eMIOS_PWMin_data[eMIOS_1_13].stoptick = 0;
}

void INT_eMIOS1_14_ISR(void)		//采集通道值
{
	eMIOS_1.S14.B.FLAG	= 1;	//清除中断标志
	if(eMIOS_PWMin_data[eMIOS_1_14].flag == unlock)
	{
		eMIOS_PWMin_data[eMIOS_1_14].A_pre = eMIOS_PWMin_data[eMIOS_1_14].A;
		eMIOS_PWMin_data[eMIOS_1_14].A = eMIOS_1.A14.B.A;
		eMIOS_PWMin_data[eMIOS_1_14].B = eMIOS_1.B14.B.B;
	}
	eMIOS_PWMin_data[eMIOS_1_14].stoptick = 0;
}

void INT_eMIOS1_15_ISR(void)		//采集通道值
{
	eMIOS_1.S15.B.FLAG	= 1;	//清除中断标志
	if(eMIOS_PWMin_data[eMIOS_1_15].flag == unlock)
	{
		eMIOS_PWMin_data[eMIOS_1_15].A_pre = eMIOS_PWMin_data[eMIOS_1_15].A;
		eMIOS_PWMin_data[eMIOS_1_15].A = eMIOS_1.A15.B.A;
		eMIOS_PWMin_data[eMIOS_1_15].B = eMIOS_1.B15.B.B;
	}
	eMIOS_PWMin_data[eMIOS_1_15].stoptick = 0;
}

void INT_eMIOS1_16_ISR(void)		//采集通道值
{
	eMIOS_1.S16.B.FLAG	= 1;	//清除中断标志
	if(eMIOS_PWMin_data[eMIOS_1_16].flag == unlock)
	{
		eMIOS_PWMin_data[eMIOS_1_16].A_pre = eMIOS_PWMin_data[eMIOS_1_16].A;
		eMIOS_PWMin_data[eMIOS_1_16].A = eMIOS_1.A16.B.A;
		eMIOS_PWMin_data[eMIOS_1_16].B = eMIOS_1.B16.B.B;
	}
	eMIOS_PWMin_data[eMIOS_1_16].stoptick = 0;
}

void INT_eMIOS1_17_ISR(void)		//采集通道值
{
	eMIOS_1.S17.B.FLAG	= 1;	//清除中断标志
	if(eMIOS_PWMin_data[eMIOS_1_17].flag == unlock)
	{
		eMIOS_PWMin_data[eMIOS_1_17].A_pre = eMIOS_PWMin_data[eMIOS_1_17].A;
		eMIOS_PWMin_data[eMIOS_1_17].A = eMIOS_1.A17.B.A;
		eMIOS_PWMin_data[eMIOS_1_17].B = eMIOS_1.B17.B.B;
	}
	eMIOS_PWMin_data[eMIOS_1_17].stoptick = 0;
}
#if 0
void INT_eMIOS1_18_ISR(void)		//采集通道值
{
	eMIOS_1.S18.B.FLAG	= 1;	//清除中断标志
	if(eMIOS_PWMin_data[eMIOS_1_18].flag == unlock)
	{
		eMIOS_PWMin_data[eMIOS_1_18].A_pre = eMIOS_PWMin_data[eMIOS_1_18].A;
		eMIOS_PWMin_data[eMIOS_1_18].A = eMIOS_1.A18.B.A;
		eMIOS_PWMin_data[eMIOS_1_18].B = eMIOS_1.B18.B.B;
	}
	eMIOS_PWMin_data[eMIOS_1_18].stoptick = 0;
}
#endif

void INT_eMIOS1_19_ISR(void)		//采集通道值
{
	eMIOS_1.S19.B.FLAG	= 1;	//清除中断标志
	if(eMIOS_PWMin_data[eMIOS_1_19].flag == unlock)
	{
		eMIOS_PWMin_data[eMIOS_1_19].A_pre = eMIOS_PWMin_data[eMIOS_1_19].A;
		eMIOS_PWMin_data[eMIOS_1_19].A = eMIOS_1.A19.B.A;
		eMIOS_PWMin_data[eMIOS_1_19].B = eMIOS_1.B19.B.B;
	}
	eMIOS_PWMin_data[eMIOS_1_19].stoptick = 0;
}

void INT_eMIOS1_20_ISR(void)		//采集通道值
{
	eMIOS_1.S20.B.FLAG	= 1;	//清除中断标志
	if(eMIOS_PWMin_data[eMIOS_1_20].flag == unlock)
	{
		eMIOS_PWMin_data[eMIOS_1_20].A_pre = eMIOS_PWMin_data[eMIOS_1_20].A;
		eMIOS_PWMin_data[eMIOS_1_20].A = eMIOS_1.A20.B.A;
		eMIOS_PWMin_data[eMIOS_1_20].B = eMIOS_1.B20.B.B;
	}
	eMIOS_PWMin_data[eMIOS_1_20].stoptick = 0;
}

void INT_eMIOS1_21_ISR(void)		//采集通道值
{
	eMIOS_1.S21.B.FLAG	= 1;	//清除中断标志
	if(eMIOS_PWMin_data[eMIOS_1_21].flag == unlock)
	{
		eMIOS_PWMin_data[eMIOS_1_21].A_pre = eMIOS_PWMin_data[eMIOS_1_21].A;
		eMIOS_PWMin_data[eMIOS_1_21].A = eMIOS_1.A21.B.A;
		eMIOS_PWMin_data[eMIOS_1_21].B = eMIOS_1.B21.B.B;
	}
	eMIOS_PWMin_data[eMIOS_1_21].stoptick = 0;
}

void INT_eMIOS1_22_ISR(void)		//采集通道值
{
	eMIOS_1.S22.B.FLAG	= 1;	//清除中断标志
	if(eMIOS_PWMin_data[eMIOS_1_22].flag == unlock)
	{
		eMIOS_PWMin_data[eMIOS_1_22].A_pre = eMIOS_PWMin_data[eMIOS_1_22].A;
		eMIOS_PWMin_data[eMIOS_1_22].A = eMIOS_1.A22.B.A;
		eMIOS_PWMin_data[eMIOS_1_22].B = eMIOS_1.B22.B.B;
	}
	eMIOS_PWMin_data[eMIOS_1_22].stoptick = 0;
}




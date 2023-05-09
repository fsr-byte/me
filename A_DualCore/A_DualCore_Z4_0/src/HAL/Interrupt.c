/*
 * Interrupt.c
 *
 *  Created on: 2018年9月6日
 *      Author: helei
 */

#define __INTERRPUT_GLOBALS__

#include "derivative.h"
#include "BASE_Global.h"
#include "Global.h"
#include "Interrupt.h"
#include "CAN_Operation.h"
#include "EX_Define.h"
#include "Task.h"
#include "UDS_Interface.h"
/************************************** for Timer ******/
void INT_PIT0_1_ISR(void)
{
  static uint8_t rt_times = 0;

    PIT_0.TIMER[2].TFLG.B.TIF = 1;
    SystemTickMs ++;
    UdsResend();     /*call UDS resend handler*/
    CAN3_RX_ISR(); /*poll UDS request every 5ms*/
    rt_times++;
    if (rt_times >= 5)
      {

         CAN_PollingRx();/*poll UDS request every 5ms*/
        rt_times = 0;

        tick_5ms++;			//各个时钟计数标志均加1
        tick_10ms++;
        tick_20ms++;
        tick_50ms++;
        tick_100ms++;
        tick_500ms++;
        tick_1000ms++;
        /*	任务切换机制	*/
        if (tick_5ms >= 1)             //5ms任务触发
  	{
  	  tick_5ms_flag = 1;
  	  tick_5ms = 0;
  	}
        if (tick_10ms >= 2)             //10ms任务触发
  	{
  	  tick_10ms_flag = 1;
  	  tick_10ms = 0;
  	}
        if (tick_20ms >= 4)             //20ms任务触发
  	{
  	  tick_20ms_flag = 1;
  	  tick_20ms = 0;
  	}
        if (tick_50ms >= 10)             //50ms任务触发
  	{
  	  tick_50ms_flag = 1;
  	  tick_50ms = 0;
  	}
        if (tick_100ms >= 20)           //100ms任务触发
  	{
  	  tick_100ms_flag = 1;
  	  tick_100ms = 0;
  	}
        if (tick_500ms >= 100)          //500ms任务触发
  	{
  	  tick_500ms_flag = 1;
  	  tick_500ms = 0;
  	}
        if (tick_1000ms >= 200)        //1000ms任务触发
  	{
  	  tick_1000ms_flag = 1;
  	  tick_1000ms = 0;
  	}
      }
}

/************************************** for Software Interrupt ******/
void INT_SI0_ISR(void)
{
  uint8_t errcode = 0;
  INTC_0.SSCIR[0].B.CLR = 1;//clear flag
  errcode = Ex_Cal_IntHandle();
  if(errcode != 0)//读取有误
    {
      ErrTimesInSI0 ++;//记录错误次数
    }
}






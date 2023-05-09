/*
 * Task.c
 *
 *  Created on: 2019年7月2日
 *      Author: helei
 */

#define __TASK_GLOBALS__

#include "BASE_Global.h"
#include "Global.h"
#include "Modules_Global.h"
#include "CAN_Operation.h"
#include "Task.h"
#include "EX_Define.h"
#include "uds_tp.h"
#include "uds_service.h"
#include "NVM.h"
#include "DHP_model.h"

//Task module base variable
uint32_t tick_5ms = 0, tick_10ms = 0, tick_20ms = 0, tick_50ms = 0,
		tick_100ms = 0, tick_500ms = 0, tick_1000ms = 0;
uint8_t tick_5ms_flag = 0, tick_10ms_flag = 0, tick_20ms_flag = 0, tick_50ms_flag = 0,
		tick_100ms_flag = 0, tick_500ms_flag = 0, tick_1000ms_flag = 0;
boolean LastudsAgingTest_flg = 0;

void FaultStatusForAgintTest()
{
  LSChip7240BFaultStatus = NCV7240B_SO_data.R;//LS
  HSChip5180BFaultStatus = BTS5180_data[0].openload + (BTS5180_data[0].shortload<<1);//HS
}

void TASK_5ms(void)
{
    static uint8_t LastInternalSleepActive_flg = 0;
    //init PMM when presleep
    if( (0 == PMM_output.VPMM_InternalSleepActive_flg) && (1 == LastInternalSleepActive_flg) )
    {
        DHP_model_initialize();
    }
    LastInternalSleepActive_flg = PMM_output.VPMM_InternalSleepActive_flg;
}

void TASK_10ms(void)
{
    Ex_Task();//核间通信任务
    udsTpTask();
    udsServiceTask();
}

void TASK_20ms(void)
{
    static uint16_t AgingTestClearDTCDelayTimeCnt = 225; //4.5s
    NvM_Task();

    FaultStatusForAgintTest();
    DHP_model_step();
    //Clear DTC when start Aging Test
    if( (bool_udsAgingTestStart_flag == 1) && (LastudsAgingTest_flg == 0) )
    {
        AgingTestClearDTCDelayTimeCnt = 225;
    }
    if( (bool_udsAgingTestStart_flag == 1) && (AgingTestClearDTCDelayTimeCnt != 0) )
    {
        AgingTestClearDTCDelayTimeCnt = AgingTestClearDTCDelayTimeCnt - 1;
        if( AgingTestClearDTCDelayTimeCnt == 0 )
        {
            (void)usClearRAMDTC();
        }
    }
    LastudsAgingTest_flg = bool_udsAgingTestStart_flag;
}

void TASK_50ms(void)
{
}

void TASK_100ms(void)
{

}

void TASK_500ms(void)
{

}

void TASK_1000ms(void)
{
  //_CAN_MESSAGE_ Test_CANFrame;
  //Test_CANFrame.control.dlc = 8;
  //Test_CANFrame.control.id = 0x010;
  //Test_CANFrame.control.ide = 1;
  //Test_CANFrame.control.rtr = 0;
  //Test_CANFrame.data.R64 = SystemTickMs;
  /* //因CAN1临时用作S21的body CAN接入(CR1931)，故关闭CAN1上的冗余报文--2020.08.18
  CANTransimitRandomMessage(CAN1,&Test_CANFrame);
  */
}

/*************************************************	TASK Schedule	**************************/
void TASK_Schedule(void)
{
	if(tick_5ms_flag == 1)
	{
		tick_5ms_flag = 0;
		TASK_5ms();
	}
	if(tick_10ms_flag == 1)
	{
		tick_10ms_flag = 0;
		TASK_10ms();
	}
	if(tick_20ms_flag == 1)
	{
		tick_20ms_flag = 0;
		TASK_20ms();
	}
	if(tick_50ms_flag == 1)
	{
		tick_50ms_flag = 0;
		TASK_50ms();
	}
	if(tick_100ms_flag == 1)
	{
		tick_100ms_flag = 0;
		TASK_100ms();
	}

	if(tick_500ms_flag == 1)
	{
		tick_500ms_flag = 0;
		TASK_500ms();
	}

	if(tick_1000ms_flag == 1)
	{
		tick_1000ms_flag = 0;
		TASK_1000ms();
	}
}













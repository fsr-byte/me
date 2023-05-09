/*
 * Task.c
 *
 *  Created on: 2018年9月19日
 *      Author: helei
 */

#define __TASK_GLOBALS__

#include "derivative.h"
#include "BASE_Global.h"
#include "Modules_Global.h"
#include "Task.h"
#include "System.h"
#include "Global.h"
#include "CAN_DBC_Lib.h"
#include "CAN_Operation.h"
#include "uds_tp.h"
#include "uds_service.h"
#include "CCP.h"
#include "NVM.h"
//#include "rtwtypes.h"
//#include "HALI_Model.h"
//#include "DIM_Model.h"
//#include "DHP_Model.h"
//#include "CHRG_Model.h"
// #include "ENM_Model.h"
// #include "TQM_Model.h"
// #include "TQFRate_model.h"
// #include "SCR_model.h"
// #include "ACR_model.h"
// #include "TMM_Model.h"
// #include "PEPS_Model.h"
// #include "DOM_Model.h"
// #include "AVAS_Model.h"
// #include "NM_Model.h"
// #include "PMM_model.h"
#include "ccp.h"
#include "EX_Define.h"
#include "TaskLib.h"
#include "BTK_ESCL.h"
//#include "BTK_Model.h"


uint64_t lamp_global = 0;
uint8_t locker_status = 0;



void Eth_send(App_enum app_id, uint8_t * data, uint16_t length);
void Eth_receive();
void vdc_can_tx_process(Data_id_enum id, uint8_t  data);



extern void PMM_model_step(void);

//--------module else variable--------
uint8_t CAN_Send_Cmd = 1;
uint8_t CAN_Send_Nm = 0;

uint8_t authFaileDataCopied = 0;   /*1: authication failed data copied*/
//----------内部声明-----------
static uint8_t TaskCapture_Control(void);
static void TaskCapture_Function(void);
static uint8_t TaskSleep_Control(void);
static void TaskSleep_Function(void);
static uint8_t TaskStatusMoniter_Control(void);
static void TaskStatusMoniter_Function(void);
static uint8_t TaskOutput_Control(void);
static void TaskOutput_Function(void);
static uint8_t TaskCycle_Control(void);
static void TaskCycle_Function(void);
static uint8_t TaskCan_Control(void);
static void TaskCan_Function(void);
static uint8_t TaskLin_Control(void);
static void TaskLin_Function(void);
static uint8_t TaskEnet_Control(void);
static void TaskEnet_Function(void);
static uint8_t TaskCommunication_Control(void);
static void TaskCommunication_Function(void);
static uint8_t TaskNVM_Control(void);
static void TaskNVM_Function(void);
static uint8_t TaskFeedDog_Control(void);
static void TaskFeedDog_Function(void);
static void TaskB2FeedDog_Function(void);
static uint8_t TaskAPPin_Control(void);
static void TaskAPPin_Function(void);
static uint8_t TaskAPPbase_Control(void);
static void TaskAPPbase_Function(void);
static uint8_t TaskAPPsport_Control(void);
static void TaskAPPsport_Function(void);
static uint8_t TaskAPPlong_Control(void);
static void TaskAPPlong_Function(void);
static uint8_t TaskAPPnetwork_Control(void);
static void TaskAPPnetwork_Function(void);
static uint8_t TaskAPPout_Control(void);
static void TaskAPPout_Function(void);
static uint8_t TaskExchange_Control(void);
static void TaskExchange_Function(void);
static uint8_t TaskHWtest_Control(void);
static void TaskHWtest_Function(void);
static uint8_t TaskBTK_Control(void);
static void TaskBTK_Function(void);
static uint8_t TaskAgingTest_Control(void);
static void TaskAgingTest_Function(void);
void BackUpAuthFailedData(void);



//-------------函数----------
static void Task_SetMessage(uint8_t taskid, TaskStatusEnum status, P2u8Function controlf, P2voidFunction functionf)
{
    if( taskid < TaskSum )	//有效的，
    {
        task[taskid].stauts = status;	//控制字及状态位
        task[taskid].control = controlf;	//控制函数
        task[taskid].function = functionf;	//操作函数
    }
    return;
}

void Task_Init(void)
{
    memset(&task[0], 0, TaskSum * sizeof(TASK_tag));	//清空任务组
    //初始化任务组
    Task_SetMessage(TaskCapture, runonce, TaskCapture_Control, TaskCapture_Function);
    Task_SetMessage(TaskSleep, runonce, TaskSleep_Control, TaskSleep_Function);
    Task_SetMessage(TaskStatusMoniter, runonce, TaskStatusMoniter_Control, TaskStatusMoniter_Function);
    Task_SetMessage(TaskOutput, runonce, TaskOutput_Control, TaskOutput_Function);
    Task_SetMessage(TaskCycle, runonce, TaskCycle_Control, TaskCycle_Function);
    Task_SetMessage(TaskCan, runonce, TaskCan_Control, TaskCan_Function);
    Task_SetMessage(TaskLin, runonce, TaskLin_Control, TaskLin_Function);
    Task_SetMessage(TaskEnet, runonce, TaskEnet_Control, TaskEnet_Function);
    Task_SetMessage(TaskCommunication, runonce, TaskCommunication_Control, TaskCommunication_Function);
    Task_SetMessage(TaskNVM, runonce, TaskNVM_Control, TaskNVM_Function);
    if( HW_VCU20_B1 == VCU20DetailedHwVer )
    {
        Task_SetMessage(TaskFeedDog, runonce, TaskFeedDog_Control, TaskFeedDog_Function);
    }
    else
    {
        Task_SetMessage(TaskFeedDog, runonce, TaskFeedDog_Control, TaskB2FeedDog_Function);
    }
    Task_SetMessage(TaskAPPin, runonce, TaskAPPin_Control, TaskAPPin_Function);
    Task_SetMessage(TaskAPPbase, runonce, TaskAPPbase_Control, TaskAPPbase_Function);
    Task_SetMessage(TaskAPPsport, runonce, TaskAPPsport_Control, TaskAPPsport_Function);
    Task_SetMessage(TaskAPPlong, runonce, TaskAPPlong_Control, TaskAPPlong_Function);
    Task_SetMessage(TaskAPPnetwork, runonce, TaskAPPnetwork_Control, TaskAPPnetwork_Function);
    Task_SetMessage(TaskAPPout, runonce, TaskAPPout_Control, TaskAPPout_Function);
    Task_SetMessage(TaskExchange, runonce, TaskExchange_Control, TaskExchange_Function);
    Task_SetMessage(TaskHWtest, runonce, TaskHWtest_Control, TaskHWtest_Function);
    Task_SetMessage(TaskBTK, runonce, TaskBTK_Control, TaskBTK_Function);
    Task_SetMessage(TaskAgingtest, runonce, TaskAgingTest_Control, TaskAgingTest_Function);
    return;
}

void Task_CycleRun(void)
{
    static uint8_t i = 0;
    uint8_t j = 0;
    uint8_t runFlag = TaskCanStop;
    if( i < TaskSum )
    {
        runFlag = TaskCanStop;
        if( NULL != task[i].control )	//控制功能函数有效
        {
            runFlag = task[i].control();	//调用控制功能函数,返回是否可执行
        }
        if( TaskCanRun == runFlag )	//可执行
        {
            task[i].time = SystemTickMs;	//记录执行时间
            StartTimer(3);	//开始精准计时
            task[i].function();	//操作函数执行
            task[i].DeltaT = GetTimerAndShut(3);	//停止精准计时并，记录模块运行时间
            if( task[i].DeltaTmax < task[i].DeltaT )
            {
                task[i].DeltaTmax = task[i].DeltaT;	//记录最大消耗时间
            }
        }
        i++;
        if( i >= TaskSum )	//成环
        {
            i = 0;
            TimeofAllTask = 0;
            MaxTimeofAllTask = 0;
            for(j = 0; j < TaskSum; j++)
            {
                TimeofAllTask += task[j].DeltaT;
                MaxTimeofAllTask += task[j].DeltaTmax;
            }
            TimeofWithoutInt = TimeofAllTask - TimeofAllInt;
            TimeofAllInt = 0;
            TimeofWithoutInt /= 100u;
            TimeofAllTask /= 100u;
            MaxTimeofAllTask /= 100u;

            TimeofIntPIT = TimeofIntPIT_temp / 100u;
            TimeofIntPIT_temp = 0;
            TimeofIntRT = TimeofIntRT_temp / 100u;
            TimeofIntRT_temp = 0;
            TimeofIntCANRX = TimeofIntCANRX_temp / 100u;
            TimeofIntCANRX_temp = 0;
        }
    }
}

//------------------function run------------------
static uint8_t TaskCapture_Control(void)	//Capture control function
{
    uint8_t recode = TaskCanStop;
    uint8_t me = TaskCapture;

    if( (task[me].time + 10) <= SystemTickMs )	//normal下的判断条件  :: 10ms执行一次
    {
        recode = (uint8_t) TaskCanRun;
    }

    if( (task[me].stauts == runonce) && (recode == TaskCanStop) )	//无条件执行一次的机会
    {
        recode = (uint8_t) TaskCanRun;
        task[me].stauts = normal;
    }
    if( (task[me].stauts == stoponce) && (recode == TaskCanRun) )	//无条件不执行一次的机会
    {
        recode = (uint8_t) TaskCanStop;
        task[me].stauts = normal;
    }
    if( task[me].stauts == runalways )	//一直执行
    {
        recode = (uint8_t) TaskCanRun;
    }
    if( task[me].stauts == stopalways )	//一直不执行
    {
        recode = (uint8_t) TaskCanStop;
    }

    return recode;
}
static void TaskCapture_Function(void)	//Capture function
{
    HAL_Capture_Digital();    //数字量采集
    HAL_Capture_ADC();        //模拟量采集
    HAL_Capture_Fin();        //频率量采集

    Task_GetSignal_Step1();
    Task_GetSignal_Step2();
    //高低驱错误检测未加入
    CheckLSFaults();
    CheckHSFaults();
}

static uint8_t TaskSleep_Control(void)
{
    uint8_t recode = TaskCanStop;
    uint8_t me = TaskSleep;

    if( (task[me].time + 20) <= SystemTickMs )	//normal下的判断条件  :: 20ms执行一次
    {
        recode = (uint8_t) TaskCanRun;
    }

    if( (task[me].stauts == runonce) && (recode == TaskCanStop) )	//无条件执行一次的机会
    {
        recode = (uint8_t) TaskCanRun;
        task[me].stauts = normal;
    }
    if( (task[me].stauts == stoponce) && (recode == TaskCanRun) )	//无条件不执行一次的机会
    {
        recode = (uint8_t) TaskCanStop;
        task[me].stauts = normal;
    }
    if( task[me].stauts == runalways )	//一直执行
    {
        recode = (uint8_t) TaskCanRun;
    }
    if( task[me].stauts == stopalways )	//一直不执行
    {
        recode = (uint8_t) TaskCanStop;
    }

    return recode;
}
static void TaskSleep_Function(void)
{
    static uint32_t timeSleepBegin = 0;
    uint32_t sleep_MaxTime_s = 0;
    if( (hIOP_K15_V > 8) || (hIOP_SlowChargeAwake_flg) || (hIOP_FastChargeAwake_flg) || WAKEUP1 || WAKEUP2 || WAKEUPKL15 )
    {
        timeSleepBegin = SystemTickMs;
         //if( WAKEUPKL15 && (0 != C_PMS_En) )
         //{
             //VBTK_SleepAllw_flg = 0;
         //}
    }
    else   //无唤醒事件触发
    {
        sleep_MaxTime_s = SystemTickMs - timeSleepBegin;  //20s强制断计时，用于硬件测试模式
        //only applicatoin data was saved, and PMM state changed to inactive can the MCU power-off
        // if( (VHALO_InternalSleepActive_flg == 0) && (NvMDataSaved == NvMAppDataSaveLoadFlag) && (1 == VBTK_SleepAllw_flg)
        //         && (sleep_MaxTime_s >= 4000) && (!gblUdsKeepPresent) )
        // {
        //     //@@@@ NVM_SaveSecAFailedCounterAndTimer ();
        //     sleep_MaxTime_s = 1000;
        //     HAL_Drive_Sleep(1);                 //断开内部延时,进入休眠状态(电源切断)等待唤醒
        // }
        if( (udsHWTestingModeStatus == UDS_START_HWTEST) && (sleep_MaxTime_s >= 20000) ) //在测试模式下的20s无唤醒源即进入休眠
        {
            HAL_Drive_Sleep(1);                 //断开内部延时,进入休眠状态(电源切断)等待唤醒
        }
        // if( (NM_Twbs == NM_End_Twbs) && (NvMDataSaved == NvMAppDataSaveLoadFlag) && (1 == VBTK_SleepAllw_flg) && (!gblUdsKeepPresent) )
        // {
        //     HAL_Drive_Sleep(1);                 //断开内部延时,进入休眠状态(电源切断)等待唤醒
        //     NM_Twbs = NM_Before_Tbws;
        //     NM_ReACKandCanStop = 0;                 //恢复通信
        //     NM_First = 0;
        // }
    }
}

static uint8_t TaskStatusMoniter_Control(void)
{
    uint8_t recode = TaskCanStop;
    uint8_t me = TaskStatusMoniter;

    if( (task[me].time + 10) <= SystemTickMs )	//normal下的判断条件  :: 10ms执行一次
    {
        recode = (uint8_t) TaskCanRun;
    }

    if( (task[me].stauts == runonce) && (recode == TaskCanStop) )	//无条件执行一次的机会
    {
        recode = (uint8_t) TaskCanRun;
        task[me].stauts = normal;
    }
    if( (task[me].stauts == stoponce) && (recode == TaskCanRun) )	//无条件不执行一次的机会
    {
        recode = (uint8_t) TaskCanStop;
        task[me].stauts = normal;
    }
    if( task[me].stauts == runalways )	//一直执行
    {
        recode = (uint8_t) TaskCanRun;
    }
    if( task[me].stauts == stopalways )	//一直不执行
    {
        recode = (uint8_t) TaskCanStop;
    }

    return recode;
}
static void TaskStatusMoniter_Function(void)
{
    uint8_t i = 0;
    static uint8_t HWtestUsedflag = 0;	//硬件测试模式使用过的标志位
    if( (udsHWTestingModeStatus == UDS_START_HWTEST) || (1 == bool_udsAgingTestStart_flag) )	//硬件测试模式
    {
        for(i = 0; i < TaskSum; i++)
        {
            task[i].stauts = stopalways;
        }
        task[TaskCapture].stauts = normal;
        task[TaskStatusMoniter].stauts = normal;

        task[TaskExchange].stauts = normal;
        task[TaskFeedDog].stauts = normal;
        task[TaskSleep].stauts = normal;
        /*如果老化测试标准有效，使能老化测试任务*/
        if( 1 == bool_udsAgingTestStart_flag )
        {
            task[TaskAgingtest].stauts = normal;
            task[TaskHWtest].stauts = stopalways;
        } /*如果老化测测试标志无效，检测硬件测试标志是否有效*/
        else if( udsHWTestingModeStatus == UDS_START_HWTEST )
        {
            task[TaskAgingtest].stauts = stopalways;
            task[TaskHWtest].stauts = normal;
        }
        else
        {
            task[TaskHWtest].stauts = stopalways;
            task[TaskAgingtest].stauts = stopalways;
        }
        HWtestUsedflag = 1;
    }
    else if( (HWtestUsedflag == 1) && ((udsHWTestingModeStatus != UDS_START_HWTEST) || (1 != bool_udsAgingTestStart_flag)) ) //从硬件测试模式中恢复
    {
        for(i = 0; i < TaskSum; i++)
        {
            task[i].stauts = normal;
        }
        HWtestUsedflag = 0;
    }
    else
    {		//其他模式操作

    }
    return;
}

static uint8_t TaskOutput_Control(void)
{
    uint8_t recode = TaskCanStop;
    uint8_t me = TaskOutput;

    if( (task[me].time + 10) <= SystemTickMs )	//normal下的判断条件  :: 10ms执行一次
    {
        recode = (uint8_t) TaskCanRun;
    }

    if( (task[me].stauts == runonce) && (recode == TaskCanStop) )	//无条件执行一次的机会
    {
        recode = (uint8_t) TaskCanRun;
        task[me].stauts = normal;
    }
    if( (task[me].stauts == stoponce) && (recode == TaskCanRun) )	//无条件不执行一次的机会
    {
        recode = (uint8_t) TaskCanStop;
        task[me].stauts = normal;
    }
    if( task[me].stauts == runalways )	//一直执行
    {
        recode = (uint8_t) TaskCanRun;
    }
    if( task[me].stauts == stopalways )	//一直不执行
    {
        recode = (uint8_t) TaskCanStop;
    }

    return recode;
}
static void TaskOutput_Function(void)
{
    Task_OutputSignal();
    HAL_Drive_HLS();          //高低边驱动
    return;
}

static uint8_t TaskCycle_Control(void)
{
    uint8_t recode = TaskCanStop;
    uint8_t me = TaskCycle;

    if( (task[me].time + 10) <= SystemTickMs )	//normal下的判断条件  :: 10ms执行一次
    {
        recode = (uint8_t) TaskCanRun;
    }

    if( (task[me].stauts == runonce) && (recode == TaskCanStop) )	//无条件执行一次的机会
    {
        recode = (uint8_t) TaskCanRun;
        task[me].stauts = normal;
    }
    if( (task[me].stauts == stoponce) && (recode == TaskCanRun) )	//无条件不执行一次的机会
    {
        recode = (uint8_t) TaskCanStop;
        task[me].stauts = normal;
    }
    if( task[me].stauts == runalways )	//一直执行
    {
        recode = (uint8_t) TaskCanRun;
    }
    if( task[me].stauts == stopalways )	//一直不执行
    {
        recode = (uint8_t) TaskCanStop;
    }

    return recode;
}
static void TaskCycle_Function(void)
{
    if( ((hIOP_K15_V > 8) || (hIOP_SlowChargeAwake_flg) || (hIOP_FastChargeAwake_flg)) && (TRUE == AppBeginRunning_flg) )
    {
        HwWakeup_Flg = 1;
    }
    if( ((hIOP_K15_V > 8) || (hIOP_SlowChargeAwake_flg) || (hIOP_FastChargeAwake_flg) || (VHALO_InternalSleepActive_flg))
            && (TRUE == AppBeginRunning_flg) )
    {
        CAN_Send_Cmd = 1;
        CAN_Send_Nm = 1;
    }
    else
    {
        CAN_Send_Cmd = 0;
        CAN_Send_Nm = 0;
    }

    System_CANBaseCycle();         //接收报文解析
    LIN_Device_Refresh();	//LIN 设备信息解析及组装

    ChkBswWakeSrc(); /*CR 1430*/
    return;
}

static uint8_t TaskCan_Control(void)
{
    uint8_t recode = TaskCanStop;
    uint8_t me = TaskCan;

    if( (task[me].time + 10) <= SystemTickMs )	//normal下的判断条件  :: 10ms执行一次
    {
        recode = (uint8_t) TaskCanRun;
    }

    if( (task[me].stauts == runonce) && (recode == TaskCanStop) )	//无条件执行一次的机会
    {
        recode = (uint8_t) TaskCanRun;
        task[me].stauts = normal;
    }
    if( (task[me].stauts == stoponce) && (recode == TaskCanRun) )	//无条件不执行一次的机会
    {
        recode = (uint8_t) TaskCanStop;
        task[me].stauts = normal;
    }
    if( task[me].stauts == runalways )	//一直执行
    {
        recode = (uint8_t) TaskCanRun;
    }
    if( task[me].stauts == stopalways )	//一直不执行
    {
        recode = (uint8_t) TaskCanStop;
    }

    return recode;
}
static void TaskCan_Function(void)
{
    static uint8_t ChannelTime = 0;

	CAN_gather(CAN3, 1);
	CANTransimitPeriodMessage(CAN3, &CAN3_TX_Array[CHANNEL_1]);
	CAN_gather(CAN3, 2);
	CANTransimitPeriodMessage(CAN3, &CAN3_TX_Array[CHANNEL_2]);
    /***	CAN TX		***************/
    /*VCU_105*//* PEPS module want to send another VCU_105 message  */
    if( VPEPS_SendChallengeCodeType_enum > Old_VPEPS_SendChallengeCodeType_enum )
    {
        ChannelTime += 5;
        if( ChannelTime >= 10 )
        {
            Old_VPEPS_SendChallengeCodeType_enum = VPEPS_SendChallengeCodeType_enum;
            CAN_gather(CAN3, CHANNEL_10);
            CANTransimitRandomMessage(CAN3, &CAN3_TX_Array[CHANNEL_10]);
            ChannelTime = 0;
            VHALO_VCU_105_Ticks++;
        }
    }

    if( KUDS_TestFeature == 0 )	//标定量，用于是否开启发送测试帧
    {
        CAN_Set_MessageFlag(CAN3, CHANNEL_16, Tx_Flag, DontSending);
        CAN_Set_MessageFlag(CAN3, CHANNEL_17, Tx_Flag, DontSending);
        CAN_Set_MessageFlag(CAN3, CHANNEL_18, Tx_Flag, DontSending);
        CAN_Set_MessageFlag(CAN3, CHANNEL_19, Tx_Flag, DontSending);
        CAN_Set_MessageFlag(CAN3, CHANNEL_20, Tx_Flag, DontSending);
        CAN_Set_MessageFlag(CAN3, CHANNEL_21, Tx_Flag, DontSending);	//666
        CAN_Set_MessageFlag(CAN3, CHANNEL_22, Tx_Flag, DontSending);	//777
    }
    return;
}

static uint8_t TaskLin_Control(void)
{
    uint8_t recode = TaskCanStop;
    uint8_t me = TaskLin;

    if( (task[me].time + 10) <= SystemTickMs )	//normal下的判断条件  :: 10ms执行一次
    {
        recode = (uint8_t) TaskCanRun;
    }

    if( (task[me].stauts == runonce) && (recode == TaskCanStop) )	//无条件执行一次的机会
    {
        recode = (uint8_t) TaskCanRun;
        task[me].stauts = normal;
    }
    if( (task[me].stauts == stoponce) && (recode == TaskCanRun) )	//无条件不执行一次的机会
    {
        recode = (uint8_t) TaskCanStop;
        task[me].stauts = normal;
    }
    if( task[me].stauts == runalways )	//一直执行
    {
        recode = (uint8_t) TaskCanRun;
    }
    if( task[me].stauts == stopalways )	//一直不执行
    {
        recode = (uint8_t) TaskCanStop;
    }

    return recode;
}
static void TaskLin_Function(void)
{
    /*only enable LIN Tx for TMS when ESCL is not busy*/
    if( BTK_ESCL_BUSY != gblEsclRslt )
    {
        LIN_Task();	//LIN 发送与接收函数，周期10ms
    }
    return;
}

static uint8_t TaskEnet_Control(void)
{
    uint8_t recode = TaskCanStop;
    uint8_t me = TaskEnet;

    if( (task[me].time + 50) <= SystemTickMs )	//normal下的判断条件  :: 50ms执行一次
    {
        recode = (uint8_t) TaskCanRun;
    }

    if( (task[me].stauts == runonce) && (recode == TaskCanStop) )	//无条件执行一次的机会
    {
        recode = (uint8_t) TaskCanRun;
        task[me].stauts = normal;
    }
    if( (task[me].stauts == stoponce) && (recode == TaskCanRun) )	//无条件不执行一次的机会
    {
        recode = (uint8_t) TaskCanStop;
        task[me].stauts = normal;
    }
    if( task[me].stauts == runalways )	//一直执行
    {
        recode = (uint8_t) TaskCanRun;
    }
    if( task[me].stauts == stopalways )	//一直不执行
    {
        recode = (uint8_t) TaskCanStop;
    }

    return recode;
}

///_CAN_MESSAGE_ VCU_UDS_msg1;

///void UdsResend1(void)
///{
///    uint8_t sendRslt;

///    VCU_UDS_msg1.control.id = 0x123456;
///      VCU_UDS_msg1.control.dlc = 8;
///      VCU_UDS_msg1.control.ide = 1;

///      VCU_UDS_msg1.control.rtr = 0;
///      VCU_UDS_msg1.data.R8[0] = 0x01;
///      VCU_UDS_msg1.data.R8[1] = 0x02;
///      VCU_UDS_msg1.data.R8[2] = 0x03;
///      VCU_UDS_msg1.data.R8[3] = 0x04;
///      VCU_UDS_msg1.data.R8[4] = 0x05;
///      VCU_UDS_msg1.data.R8[5] = 0x06;
///      VCU_UDS_msg1.data.R8[6] = 0x07;
///      VCU_UDS_msg1.data.R8[7] = 0x08;

///    sendRslt = CANTransimitRandomMessage (0, &VCU_UDS_msg1);
///}

void Lamp_LIN_test(void)
{
    
	static uint8_t times_cnt;
	times_cnt++;
	
	if(times_cnt%50 == 0)
    {
	    LIN_MasterTxFrame(0x9, 0);    //close
	    LIN_MasterTxFrame(0x15, 0);    //close
	    //LIN_MasterTxFrame(0x14, 0);    //open
	    times_cnt = 0;
    }
    else if(times_cnt%200 == 0)
    {
	    LIN_MasterTxFrame(0x15, 0);    //close
	    //LIN_MasterTxFrame(0x8, 0);    //close
    }
}

void Locker_test(void)
{
    static uint8_t times_cnt;
    times_cnt++;

	
    if(locker_status == 1)
    {
        HAL_Drive_LS(0,1);
        HAL_Drive_LS(1,0);
        HAL_Drive_LS(2,1);
        HAL_Drive_LS(3,0);
        HAL_Drive_LS(4,1);
        HAL_Drive_LS(5,0);
        HAL_Drive_LS(6,1);
        HAL_Drive_LS(7,0); 
		locker_status = 0;
    }
    else if(locker_status == 2)
    {
        HAL_Drive_LS(0,0);
        HAL_Drive_LS(1,1);
        HAL_Drive_LS(2,0);
        HAL_Drive_LS(3,1);
        HAL_Drive_LS(4,0);
        HAL_Drive_LS(5,1);
        HAL_Drive_LS(6,0);
        HAL_Drive_LS(7,1);
		locker_status = 0;
    }
    else if(times_cnt%10 == 0)
    {
	    HAL_Drive_LS(0,0);
        HAL_Drive_LS(1,0);
        HAL_Drive_LS(2,0);
        HAL_Drive_LS(3,0);
        HAL_Drive_LS(4,0);
        HAL_Drive_LS(5,0);
        HAL_Drive_LS(6,0);
        HAL_Drive_LS(7,0);
    }
}
//boolean_T GUI_SSB_Switch1;                /*HW DIN_24*/
//boolean_T GUI_SSB_Switch2;                /*HW DIN_27*/
static void TaskEnet_Function(void)
{
  uint32_t ret = 0;
    //以太网相关检测
    ENET_Cycle();		//必须调用；用于切换主从和监控是否连接
    ///UdsResend1();
	//Lamp_LIN_test();
	Locker_test();
#if 0
	ret = SIUL_GetPadState(D_IN27_PAD);
    if (ret)
    {
	GUI_SSB_Switch1 = 1;
	GUI_SSB_Switch2 = 1;
    }
    else
    {
	GUI_SSB_Switch1 = 0;
	GUI_SSB_Switch2 = 0;
    }
#endif
    return;
}

static uint8_t TaskCommunication_Control(void)
{
    uint8_t recode = TaskCanStop;
    uint8_t me = TaskCommunication;

    if( (task[me].time + 10) <= SystemTickMs )	//normal下的判断条件  :: 10ms执行一次
    {
        recode = (uint8_t) TaskCanRun;
    }

    if( (task[me].stauts == runonce) && (recode == TaskCanStop) )	//无条件执行一次的机会
    {
        recode = (uint8_t) TaskCanRun;
        task[me].stauts = normal;
    }
    if( (task[me].stauts == stoponce) && (recode == TaskCanRun) )	//无条件不执行一次的机会
    {
        recode = (uint8_t) TaskCanStop;
        task[me].stauts = normal;
    }
    if( task[me].stauts == runalways )	//一直执行
    {
        recode = (uint8_t) TaskCanRun;
    }
    if( task[me].stauts == stopalways )	//一直不执行
    {
        recode = (uint8_t) TaskCanStop;
    }

    return recode;
}
static void TaskCommunication_Function(void)
{
    static uint8_t ccp20flag = 0;

    Bus_AckHandle();	//CAN3 No Ack 检测
    Bus_OffHandlerTask();

    //-----CCP--------------------------
    CcpDAQ_FastEventHandler(0);	//每次循环为10ms
    ccp20flag++;

    if( ccp20flag >= 2 )	//20ms时
    {
        Ccp_CMDHandler();
        CcpDAQ_MiddleEventHandler(1);
        ccp20flag = 0;
    }
    //-----UDS---------------------
#define TempOffset 50
    appDID_outSnapshot.AccPdlSensor5V1 = hIOP_Sen5V1_V * 2 * 1000;
    appDID_outSnapshot.AccPdlSensor5V2 = hIOP_Sen5V2_V * 2 * 1000;
//    appDID_outSnapshot.fastChrgSensorTemp1 = HALI_output.Hardwire_Inputs.VHALI_FastChargeTemp1_C + TempOffset;
//    appDID_outSnapshot.fastChrgSensorTemp2 = HALI_output.Hardwire_Inputs.VHALI_FastChargeTemp2_C + TempOffset;
    appDID_outSnapshot.VCUBMSOperModeReq = VHALO_VCUBMSOperModReq;
    appDID_outSnapshot.BMSOperMode = VHALI_BMSOperMod;
    appDID_outSnapshot.BMSMaxDischrgPwr = VHALI_BMSMaxDchaPwr;
    appDID_outSnapshot.BMSMaxChrgPwr = VHALI_BMSMaxChrgPwr;
    appDID_outSnapshot.BMSMaxDischrgI = VHALI_BMSMaxDchaI;
    appDID_outSnapshot.BMSMaxChrgI = VHALI_BMSMaxChrgI;
    appDID_outSnapshot.BMSCC2SngR = VHALI_BMSCC2SngR;
    appDID_outSnapshot.BMSCCSngR = VHALI_BMSCCSngR;
    appDID_outSnapshot.VCUDCDCOperModeReq = VHALO_VCUDCDCStsMod;
    appDID_outSnapshot.DCDCOperMode = VHALI_DCDCOperMod;
    appDID_outSnapshot.DCDCoutputU = VHALI_DCDCOutpU;
    appDID_outSnapshot.DCDCoutputI = VHALI_DCDCOutpCrrt;
    appDID_outSnapshot.DCDCinputU = VHALI_DCDCInpU;
    appDID_outSnapshot.DCDCinputI = VHALI_DCDCIInput;
    appDID_outSnapshot.VCUMCUOperModeReq = VHALO_MotStsModReq;
    appDID_outSnapshot.MCUOperMode = VHALI_MCUOperMdl;
    appDID_outSnapshot.VCUElecMotErr = VHALO_VCUElecMotErr;
    appDID_outSnapshot.VCUMotspeedReq = VHALO_MotSpdReq;
    appDID_outSnapshot.MCUMaxAvlTorque = VHALI_MCUMaxAvlTq;
    appDID_outSnapshot.MCUMinAvlTorque = VHALI_MCUMinAvlTq;
    appDID_outSnapshot.BMSIsolationR = VHALI_BMSIsolationR;
    if( KUDS_IOCtrlEnable && IOCtrlDidTbl[1].Enable )
    {
        appDID_outSnapshot.MCURelay_flg = IOCtrlDidTbl[1].Status;
    }
    else
    {
        appDID_outSnapshot.MCURelay_flg = hIOP_MCURelay_flg;
    }
    if( KUDS_IOCtrlEnable && IOCtrlDidTbl[2].Enable )
    {
        appDID_outSnapshot.BrklightRelay_flg = IOCtrlDidTbl[2].Status;
    }
    else
    {
        appDID_outSnapshot.BrklightRelay_flg = hIOP_HSRelay1_flg;
    }
    if( KUDS_IOCtrlEnable && IOCtrlDidTbl[0].Enable )
    {
        appDID_outSnapshot.MainRelay_flg = IOCtrlDidTbl[0].Status;
    }
    else
    {
        appDID_outSnapshot.MainRelay_flg = hIOP_MainRelay_flg;
    }
#undef TempOffset

    return;
}

static uint8_t TaskNVM_Control(void)
{
    uint8_t recode = TaskCanStop;
    uint8_t me = TaskNVM;

    if( (task[me].time + 50) <= SystemTickMs )	//normal下的判断条件  :: 50ms执行一次
    {
        recode = (uint8_t) TaskCanRun;
    }

    if( (task[me].stauts == runonce) && (recode == TaskCanStop) )	//无条件执行一次的机会
    {
        recode = (uint8_t) TaskCanRun;
        task[me].stauts = normal;
    }
    if( (task[me].stauts == stoponce) && (recode == TaskCanRun) )	//无条件不执行一次的机会
    {
        recode = (uint8_t) TaskCanStop;
        task[me].stauts = normal;
    }
    if( task[me].stauts == runalways )	//一直执行
    {
        recode = (uint8_t) TaskCanRun;
    }
    if( task[me].stauts == stopalways )	//一直不执行
    {
        recode = (uint8_t) TaskCanStop;
    }

    return recode;
}
static void TaskNVM_Function(void)
{
#if 0
    /*temporary solution, clear DTC information if $14 command received from Core 0*/
    if((0 == prevClrDTCCmdFromCore0) && (1 == currClrDTCCmdFromCore0))
    {
        (void)memset(Fault_storage_array, 0, sizeof(Fault_storage_array));
        (void)memset(DTCStatusRAMTbl, 0, sizeof(DTCStatusRAMTbl));
    }
    prevClrDTCCmdFromCore0 = currClrDTCCmdFromCore0;
    /*temporary solution, clear DTC information if $14 command received from Core 0*/
#endif 
    return;
}

static uint8_t TaskFeedDog_Control(void)
{
    uint8_t recode = TaskCanStop;
    uint8_t me = TaskFeedDog;

    if( (task[me].time + 10) <= SystemTickMs )	//10ms检测一次
    {
        recode = (uint8_t) TaskCanRun;
    }

    if( (task[me].stauts == runonce) && (recode == TaskCanStop) )	//无条件执行一次的机会
    {
        recode = (uint8_t) TaskCanRun;
        task[me].stauts = normal;
    }
    if( (task[me].stauts == stoponce) && (recode == TaskCanRun) )	//无条件不执行一次的机会
    {
        recode = (uint8_t) TaskCanStop;
        task[me].stauts = normal;
    }
    if( task[me].stauts == runalways )	//一直执行
    {
        recode = (uint8_t) TaskCanRun;
    }
    if( task[me].stauts == stopalways )	//一直不执行
    {
        recode = (uint8_t) TaskCanStop;
    }

    return recode;
}
static void TaskFeedDog_Function(void)
{
    uint32_t timeout = 0;
    static uint32_t Time_dog = 0;

    if( 1 == ShouldFeedDog )
    {
        if( 0 == Ex_Base_LockGate(Gate_SPI) )
        {
            FS6500_FeedDog();
            Ex_Base_UnlockGate(Gate_Core0Stop);	//清除    Core0暂停
            ShouldFeedDog = 0;
            Time_dog = SystemTickMs;	//更新时间计数器
            while((0 != Ex_Base_UnlockGate(Gate_SPI)) || ((timeout++) >= 10))
                ;

            if( timeout >= 10 )
            {
                FLAG_GateSPI_ERROR = 1;
            }
        }
        else if( (SystemTickMs - Time_dog) >= 450 )	//需要强制喂狗
        {
            Ex_Base_LockGate(Gate_Core0Stop);	//通知Core0暂停
        }
    }

    else if( (Time_dog + 270) <= SystemTickMs )	//normal下的判断条件  :: 270ms feed dog for windows 512
    {
        if( 0 == Ex_Base_LockGate(Gate_SPI) )
        {
            FS6500_FeedDog();
            Ex_Base_UnlockGate(Gate_Core0Stop);	//清除    Core0暂停
            ShouldFeedDog = 0;
            Time_dog = SystemTickMs;
            while(0 != Ex_Base_UnlockGate(Gate_SPI) || (timeout++) >= 10)
                ;
            if( timeout >= 10 )
            {
                FLAG_GateSPI_ERROR = 1;
            }
        }
        else
        {
            ShouldFeedDog = 1;
        }
    }

    return;
}

/*for VCU 2.0 B2 HW, SBC doesn't share SPI with EEPROM, so the Gate checking is unnecessary*/
static void TaskB2FeedDog_Function(void)
{
    //uint32_t timeout = 0;
    static uint32_t Time_dog = 0;

    if( (Time_dog + 270) <= SystemTickMs )	//normal下的判断条件  :: 270ms feed dog for windows 512
    {
        FS6500_FeedDog();
        Time_dog = SystemTickMs;
    }
}

static uint8_t TaskAPPin_Control(void)
{
    uint8_t recode = TaskCanStop;
    uint8_t me = TaskAPPin;

    if( (task[me].time + 10) <= SystemTickMs )	//normal下的判断条件  :: 10ms执行一次
    {
        recode = (uint8_t) TaskCanRun;
    }

    if( (task[me].stauts == runonce) && (recode == TaskCanStop) )	//无条件执行一次的机会
    {
        recode = (uint8_t) TaskCanRun;
        task[me].stauts = normal;
    }
    if( (task[me].stauts == stoponce) && (recode == TaskCanRun) )	//无条件不执行一次的机会
    {
        recode = (uint8_t) TaskCanStop;
        task[me].stauts = normal;
    }
    if( task[me].stauts == runalways )	//一直执行
    {
        recode = (uint8_t) TaskCanRun;
    }
    if( task[me].stauts == stopalways )	//一直不执行
    {
        recode = (uint8_t) TaskCanStop;
    }

    return recode;
}
static void TaskAPPin_Function(void)
{
    StartTimer(4);	//开始精准计时
//    HALI_model_step();
    VHALO_HALI_Time = GetTimerAndShut(4) / 100u;	//结束精准计时

    StartTimer(4);	//开始精准计时
    DIM_model_step();
    VHALO_DIM_Time = GetTimerAndShut(4) / 100u;	//结束精准计时

    return;
}

static uint8_t TaskAPPbase_Control(void)
{
    uint8_t recode = TaskCanStop;
    uint8_t me = TaskAPPbase;

    if( (task[me].time + 20) <= SystemTickMs )	//normal下的判断条件  :: 20ms执行一次
    {
        recode = (uint8_t) TaskCanRun;
    }

    if( (task[me].stauts == runonce) && (recode == TaskCanStop) )	//无条件执行一次的机会
    {
        recode = (uint8_t) TaskCanRun;
        task[me].stauts = normal;
    }
    if( (task[me].stauts == stoponce) && (recode == TaskCanRun) )	//无条件不执行一次的机会
    {
        recode = (uint8_t) TaskCanStop;
        task[me].stauts = normal;
    }
    if( task[me].stauts == runalways )	//一直执行
    {
        recode = (uint8_t) TaskCanRun;
    }
    if( task[me].stauts == stopalways )	//一直不执行
    {
        recode = (uint8_t) TaskCanStop;
    }

    return recode;
}
static void TaskAPPbase_Function(void)
{
    StartTimer(4);	//开始精准计时
    BTK_Model_step();
    VHALO_BTK_Time = GetTimerAndShut(4) / 100u;	//结束精准计时

    // StartTimer(4);	//开始精准计时
    // PMM_model_step();
    // VHALO_PMM_Time = GetTimerAndShut(4) / 100u;	//结束精准计时

    // StartTimer(4);	//开始精准计时
    // CHRG_Model_step();
    // VHALO_CHRG_Time = GetTimerAndShut(4) / 100u;	//结束精准计时

    // StartTimer(4);	//开始精准计时
    // PEPS_Model_step();
    // if( 0 == VPEPS_SendChallengeCodeType_enum )
    // {
    //     Old_VPEPS_SendChallengeCodeType_enum = VPEPS_SendChallengeCodeType_enum;
    //     authFaileDataCopied = 0;
    // }
    // BackUpAuthFailedData(); /*added for CR1519*/
    // VHALO_PEPS_Time = GetTimerAndShut(4) / 100u;	//结束精准计时
    return;
}
// /*CR 1519: copy the auth failure internal data from core1 to core 0*/
// void BackUpAuthFailedData(void)
// {
//     int pos;
//     uint32_t odometer;

//     /*authentication not enabled, or the authication not confirmed to failed, or data copied , return directly*/
//     if( (1 != Authentication_flg) || (1 != PEPS_output.VPEPS_Result_enum) )
//     {
//         return;
//     }
//     if( authFaileDataCopied > 5 )
//     {
//         return;
//     }
//     authFaileDataCopied++; /*copy authication failed data only 5 times during a ingition on-off cycle*/
//     pos = 0;
//     (void)memset(AuthFailData, 0, sizeof(AuthFailData));
//     /*first 3 bytes is Odometer*/
//     odometer = HALI_output.CAN_Inputs.HALI_EHU.VHALI_ClstrOdo;
//     odometer = odometer << 8;
//     (void)memcpy(&AuthFailData[pos], &odometer, 3);
//     /*T-BOX time*/
//     pos = pos + 3;
//     AuthFailData[pos] = HALI_output.CAN_Inputs.HALI_TBOX.VHALI_TBOX_TimeYear;
//     AuthFailData[pos + 1] = HALI_output.CAN_Inputs.HALI_TBOX.VHALI_TBOX_TimeMonth;
//     AuthFailData[pos + 2] = HALI_output.CAN_Inputs.HALI_TBOX.VHALI_TBOX_TimeDate;
//     AuthFailData[pos + 3] = HALI_output.CAN_Inputs.HALI_TBOX.VHALI_TBOX_TimeHour;
//     AuthFailData[pos + 4] = HALI_output.CAN_Inputs.HALI_TBOX.VHALI_TBOX_TimeMinute;
//     /*signals from PEPS_108*/
//     pos = pos + 5;
//     AuthFailData[pos] = HALI_output.CAN_Inputs.HALI_PEPS.VHALI_PEPS_PDU;
//     AuthFailData[pos + 1] = HALI_output.CAN_Inputs.HALI_PEPS.VHALI_PEPS_EncryptedStatus;
//     AuthFailData[pos + 2] = HALI_output.CAN_Inputs.HALI_PEPS.VHALI_PEPS_EncryptedResponseByte5;
//     AuthFailData[pos + 3] = HALI_output.CAN_Inputs.HALI_PEPS.VHALI_PEPS_EncryptedResponseByte4;
//     AuthFailData[pos + 4] = HALI_output.CAN_Inputs.HALI_PEPS.VHALI_PEPS_EncryptedResponseByte3;
//     AuthFailData[pos + 5] = HALI_output.CAN_Inputs.HALI_PEPS.VHALI_PEPS_EncryptedResponseByte2;
//     AuthFailData[pos + 6] = HALI_output.CAN_Inputs.HALI_PEPS.VHALI_PEPS_EncryptedResponseByte1;
//     AuthFailData[pos + 7] = HALI_output.CAN_Inputs.HALI_PEPS.VHALI_PEPS_EncryptedResponseByte0;
//     /*copy the VSK code*/
//     pos = pos + 8;
//     (void)memcpy(&AuthFailData[pos], PEPS_VSK_Byte, sizeof(PEPS_VSK_Byte));
//     /*copy internal challenge code*/
//     pos = pos + 16;
//     (void)memcpy(&AuthFailData[pos], &PEPS_output.VPEPS_ChallengeCode_array, sizeof(PEPS_output.VPEPS_ChallengeCode_array));
//     /*copy internal calcuated Key*/
//     pos = pos + 8;
//     (void)memcpy(&AuthFailData[pos], &PEPS_output.EnKey, sizeof(PEPS_output.EnKey));
//     /*copy VCU防盗模块内部状态数据 等待时间+发送标志+发送次数+尝试次数+内部状态+正在进行标志+重置标志*/
//     pos = pos + 8;
//     (void)memcpy(&AuthFailData[pos], &VPEPS_WaitTime_ms, 2);
//     pos = pos + 2;
//     AuthFailData[pos] = PEPS_output.VPEPS_SendChallengeCodeType_enum;
//     AuthFailData[pos + 1] = VPEPS_SendChallenge_Cnt;
//     AuthFailData[pos + 2] = PEPS_output.VPEPS_Result_enum;
//     AuthFailData[pos + 3] = VPEPS_AuthTime_Cnt;
//     AuthFailData[pos + 4] = VPEPS_OnGoing_flg;
//     AuthFailData[pos + 5] = VPEPS_ResetPEPSStatus_flg;
//     /*copy internal challenge code*/
//     /*copy internal challenge code*/
//     pos = pos + 6;
//     (void)memcpy(&AuthFailData[pos], &VHALI_PEPS_108_MsgTicks, sizeof(VHALI_PEPS_108_MsgTicks));
//     pos = pos + 4;
//     (void)memcpy(&AuthFailData[pos], &VHALI_PEPS_103_MsgTicks, sizeof(VHALI_PEPS_103_MsgTicks));
//     pos = pos + 4;
//     (void)memcpy(&AuthFailData[pos], &VHALO_VCU_105_Ticks, sizeof(VHALO_VCU_105_Ticks));
//     pos = pos + 4;
//     AuthFailData[pos] = HALI_output.CAN_Inputs.HALI_PEPS.VHALI_PEPS_ReAuth_Req;
// }
// // 
static uint8_t TaskAPPsport_Control(void)
{
    uint8_t recode = TaskCanStop;
    uint8_t me = TaskAPPsport;

    if( (task[me].time + 10) <= SystemTickMs )	//normal下的判断条件  :: 10ms执行一次
    {
        recode = (uint8_t) TaskCanRun;
    }

    if( (task[me].stauts == runonce) && (recode == TaskCanStop) )	//无条件执行一次的机会
    {
        recode = (uint8_t) TaskCanRun;
        task[me].stauts = normal;
    }
    if( (task[me].stauts == stoponce) && (recode == TaskCanRun) )	//无条件不执行一次的机会
    {
        recode = (uint8_t) TaskCanStop;
        task[me].stauts = normal;
    }
    if( task[me].stauts == runalways )	//一直执行
    {
        recode = (uint8_t) TaskCanRun;
    }
    if( task[me].stauts == stopalways )	//一直不执行
    {
        recode = (uint8_t) TaskCanStop;
    }

    return recode;
}
static void TaskAPPsport_Function(void)
{
    StartTimer(4);	//开始精准计时
//    TQM_model_step();
//    ACR_model_step();
//    SCR_model_step();
//    TQFRate_model_step();
    VHALO_TQM_Time = GetTimerAndShut(4) / 100u;	//结束精准计时
    return;
}

static uint8_t TaskAPPlong_Control(void)
{
    uint8_t recode = TaskCanStop;
    uint8_t me = TaskAPPlong;

    if( (task[me].time + 10) <= SystemTickMs )	//normal下的判断条件  :: 10ms执行一次
    {
        recode = (uint8_t) TaskCanRun;
    }

    if( (task[me].stauts == runonce) && (recode == TaskCanStop) )	//无条件执行一次的机会
    {
        recode = (uint8_t) TaskCanRun;
        task[me].stauts = normal;
    }
    if( (task[me].stauts == stoponce) && (recode == TaskCanRun) )	//无条件不执行一次的机会
    {
        recode = (uint8_t) TaskCanStop;
        task[me].stauts = normal;
    }
    if( task[me].stauts == runalways )	//一直执行
    {
        recode = (uint8_t) TaskCanRun;
    }
    if( task[me].stauts == stopalways )	//一直不执行
    {
        recode = (uint8_t) TaskCanStop;
    }

    return recode;
}
static void TaskAPPlong_Function(void)
{
    static uint8_t odd20msTick = 0;   // 0: run ENM step; 1: run TMM step

    if( 0 == odd20msTick )
    {
        odd20msTick = 1;
        /*bug 811: only after PMM enter waked up status and App data loaded, can ENM cyclic task be called*/
        // if( (1 == PMM_output.VPMM_InternalSleepActive_flg) && (NvMDataLoaded == NvMAppDataSaveLoadFlag) )
        // {
        //     StartTimer(4);	//开始精准计时
        //     ENM_model_step();
        //     VHALO_ENM_Time = GetTimerAndShut(4) / 100u;	//结束精准计时
        // }
        // else
        // {
        //     VHALO_ENM_Time = 0;
        // }
    }
    else
    {
        StartTimer(4);	//开始精准计时
        // TMM_model_step();
        VHALO_TMM_Time = GetTimerAndShut(4) / 100u;	//结束精准计时

        odd20msTick = 0;
    }

    // AVAS_Model_step();

    return;
}

static uint8_t TaskAPPnetwork_Control(void)
{
    uint8_t recode = TaskCanStop;
    uint8_t me = TaskAPPnetwork;

    if( (task[me].time + 10) <= SystemTickMs )	//normal下的判断条件  :: 10ms执行一次
    {
        recode = (uint8_t) TaskCanRun;
    }

    if( (task[me].stauts == runonce) && (recode == TaskCanStop) )	//无条件执行一次的机会
    {
        recode = (uint8_t) TaskCanRun;
        task[me].stauts = normal;
    }
    if( (task[me].stauts == stoponce) && (recode == TaskCanRun) )	//无条件不执行一次的机会
    {
        recode = (uint8_t) TaskCanStop;
        task[me].stauts = normal;
    }
    if( task[me].stauts == runalways )	//一直执行
    {
        recode = (uint8_t) TaskCanRun;
    }
    if( task[me].stauts == stopalways )	//一直不执行
    {
        recode = (uint8_t) TaskCanStop;
    }

    return recode;
}
static void TaskAPPnetwork_Function(void)
{
    //因时间要求，在中断中调用处理，除了bus off和NoAck的情况
    return;
}

static uint8_t TaskAPPout_Control(void)
{
    uint8_t recode = TaskCanStop;
    uint8_t me = TaskAPPout;

    if( (task[me].time + 10) <= SystemTickMs )	//normal下的判断条件  :: 10ms执行一次
    {
        recode = (uint8_t) TaskCanRun;
    }

    if( (task[me].stauts == runonce) && (recode == TaskCanStop) )	//无条件执行一次的机会
    {
        recode = (uint8_t) TaskCanRun;
        task[me].stauts = normal;
    }
    if( (task[me].stauts == stoponce) && (recode == TaskCanRun) )	//无条件不执行一次的机会
    {
        recode = (uint8_t) TaskCanStop;
        task[me].stauts = normal;
    }
    if( task[me].stauts == runalways )	//一直执行
    {
        recode = (uint8_t) TaskCanRun;
    }
    if( task[me].stauts == stopalways )	//一直不执行
    {
        recode = (uint8_t) TaskCanStop;
    }

    return recode;
}
static void TaskAPPout_Function(void)
{
    StartTimer(4);	//开始精准计时
    DOM_model_step();
    VHALO_DOM_Time = GetTimerAndShut(4) / 100u;	//结束精准计时

    AppBeginRunning_flg = 1;
    return;
}

static uint8_t TaskExchange_Control(void)
{
    uint8_t recode = TaskCanStop;
    uint8_t me = TaskExchange;

    if( (task[me].time + 10) <= SystemTickMs )	//normal下的判断条件  :: 10ms执行一次
    {
        recode = (uint8_t) TaskCanRun;
    }

    if( (task[me].stauts == runonce) && (recode == TaskCanStop) )	//无条件执行一次的机会
    {
        recode = (uint8_t) TaskCanRun;
        task[me].stauts = normal;
    }
    if( (task[me].stauts == stoponce) && (recode == TaskCanRun) )	//无条件不执行一次的机会
    {
        recode = (uint8_t) TaskCanStop;
        task[me].stauts = normal;
    }
    if( task[me].stauts == runalways )	//一直执行
    {
        recode = (uint8_t) TaskCanRun;
    }
    if( task[me].stauts == stopalways )	//一直不执行
    {
        recode = (uint8_t) TaskCanStop;
    }

    return recode;
}
static void TaskExchange_Function(void)
{
    Ex_Task();	//核间通信任务
    return;
}

static uint8_t TaskHWtest_Control(void)
{
    uint8_t recode = TaskCanStop;
    uint8_t me = TaskHWtest;

    if( udsHWTestingModeStatus == UDS_START_HWTEST )	//normal下的判断条件  :: 硬件测试模式开启
    {
        recode = (uint8_t) TaskCanRun;
    }

    if( (task[me].stauts == runonce) && (recode == TaskCanStop) )	//无条件执行一次的机会
    {
        recode = (uint8_t) TaskCanRun;
        task[me].stauts = normal;
    }
    if( (task[me].stauts == stoponce) && (recode == TaskCanRun) )	//无条件不执行一次的机会
    {
        recode = (uint8_t) TaskCanStop;
        task[me].stauts = normal;
    }
    if( task[me].stauts == runalways )	//一直执行
    {
        recode = (uint8_t) TaskCanRun;
    }
    if( task[me].stauts == stopalways )	//一直不执行
    {
        recode = (uint8_t) TaskCanStop;
    }

    return recode;
}
static void TaskHWtest_Function(void)
{
    uint8_t i = 0;
    static uint32_t Time[10] = { 0 };
    static uint8_t data[100];
    _EthernetFrame_tag_ *Enetframe;

    if( (1 == lintest) && ((Time[0] + 500) <= SystemTickMs) )	//500ms执行一次::Time[0]::LIN
    {
        LIN_MasterTxFrame(0x11, 0x1122334455667700 + EnetRight);
        Time[0] = SystemTickMs;
    }

    ENET_Cycle();		//须调用；用于切换主从和监控是否连接
    if( (1 == EnetTestMaster) && ((Time[1] + 50) <= SystemTickMs) )		//50ms执行一次::Time[1]::ENET
    {
        //测试ENET
        if( data[14] == ENET_RxFrame.data[0] - 1 )
        {
            //测试成功,实时监控
            EnetRight += 1;
        }
        //EnetRight = EnetRxTick;

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

        data[14] = (uint8_t)(SystemTickMs % 100);
        for(i = 15; i < 100; i++)
        {
            data[i] = i;
        }
        ENET_TX(&data[0], 100);
        ENET_StartReceive();

        Time[1] = SystemTickMs;
    }

    HwTest_OutputSignal();		//硬件测试模式时输出
    HAL_Drive_HLS();          //高低边驱动

    return;
}

static uint8_t TaskBTK_Control(void)
{
    uint8_t recode = TaskCanStop;
    uint8_t me = TaskBTK;

    if( (task[me].time + 10) <= SystemTickMs )	//normal下的判断条件  :: 10ms执行一次
    {
        recode = (uint8_t) TaskCanRun;
    }

    if( (task[me].stauts == runonce) && (recode == TaskCanStop) )	//无条件执行一次的机会
    {
        recode = (uint8_t) TaskCanRun;
        task[me].stauts = normal;
    }
    if( (task[me].stauts == stoponce) && (recode == TaskCanRun) )	//无条件不执行一次的机会
    {
        recode = (uint8_t) TaskCanStop;
        task[me].stauts = normal;
    }
    if( task[me].stauts == runalways )	//一直执行
    {
        recode = (uint8_t) TaskCanRun;
    }
    if( task[me].stauts == stopalways )	//一直不执行
    {
        recode = (uint8_t) TaskCanStop;
    }

    return recode;
}

static void TaskBTK_Function(void)
{
//    if( 0 != C_ESCL_En )
//    {
//        BTK_ESCL_Task();
//    }
    return;
}

uint16_t AGING_TEST_CHANNEL_FREQ_SET[8] = { 1000, 2000, 1800, 2200, 1800, 2000, 2200, 1600 };
uint16_t AGING_TEST_CHANNEL_FREQ_GET[8] = { 0 };
uint8_t AGING_TEST_Freq_Inited = 0;
uint8_t AGING_TEST_ERROR_LED = 0;
extern void AgingTest_eMIOS_Init_All();
static uint8_t TaskAgingTest_Control(void)
{
    uint8_t recode = TaskCanStop;
    uint8_t me = TaskAgingtest;
    static uint8_t AgingTest_init_flag = 0;
    /*addtional init for aging test */
    if( bool_udsAgingTestStart_flag == TRUE )
    {
        if( AgingTest_init_flag == 0 )
        {
            AgingTest_eMIOS_Init_All();
        }
        AgingTest_init_flag = 1;
    }
    else if( bool_udsAgingTestStart_flag != TRUE )
    {
        if( AgingTest_init_flag == 1 )
        {
            eMIOS_Init_All();
        }
        AgingTest_init_flag = 0;
    }

    if( (bool_udsAgingTestStart_flag == TRUE) && ((task[me].time + 1000) <= SystemTickMs) )	//normal下的判断条件  :: 硬件测试模式开启
    {
        recode = (uint8_t) TaskCanRun;
    }

    if( (task[me].stauts == runonce) && (recode == TaskCanStop) )	//无条件执行一次的机会
    {
        recode = (uint8_t) TaskCanRun;
        task[me].stauts = normal;
    }
    if( (task[me].stauts == stoponce) && (recode == TaskCanRun) )	//无条件不执行一次的机会
    {
        recode = (uint8_t) TaskCanStop;
        task[me].stauts = normal;
    }
    if( task[me].stauts == runalways )	//一直执行
    {
        recode = (uint8_t) TaskCanRun;
    }
    if( task[me].stauts == stopalways )	//一直不执行
    {
        recode = (uint8_t) TaskCanStop;
    }

    return recode;
}

static void TaskAgingTest_Function(void)
{
    uint8_t i = 0;
    //static uint32_t Time[10] = {0};
    //static uint8_t data[100];
    static uint32_t HLS_Loop_Time = 0;
    static uint8_t HLS_Loop_mode = 0;

    static uint32_t Bridge_Loop_Time = 0;
    static uint8_t Bridge_Loop_mode = 0;

    static uint32_t PWM_LoopReset_Time = 0;

    //part 1. HS and LS looping for every 60s, including 10s off and 50s on.
    if( (SystemTickMs - HLS_Loop_Time) >= 60000 )  //
    {
        /*set HLS state off and restart loop*/
        HLS_Loop_Time = SystemTickMs;
        HLS_Loop_mode = 0;

        for(i = 0; i < LS_NUM; i++)
        {
            HAL_Drive_LS(i, 0);
        }
        for(i = 0; i < HS_NUM; i++)
        {
            HAL_Drive_HS(i, 0);
        }
    }
    else if( (SystemTickMs - HLS_Loop_Time) >= 10000 )
    {
        if( 1 != HLS_Loop_mode )
        {
            HLS_Loop_mode = 1;
            /*set HLS state on */
            for(i = 0; i < LS_NUM; i++)
            {
                HAL_Drive_LS(i, 1);
            }
            for(i = 0; i < HS_NUM; i++)
            {
                HAL_Drive_HS(i, 1);
            }
        }

    }
    HAL_Drive_HLS();          //高低边驱动

    //part 2. 7719 bridge drive.
    if( (SystemTickMs - Bridge_Loop_Time) >= 120000 )  //
    {
        /*set HLS state off and restart loop*/
        Bridge_Loop_Time = SystemTickMs;
        Bridge_Loop_mode = 0;
        /*set bridge mode 1.  AB all off*/
        NCV7719_data.CH1_6.R = 0b1000000000000001;
        NCV7719_data.CH7_8.R = 0b1100000000000001;
    }
    if( (SystemTickMs - Bridge_Loop_Time) >= 10000 )
    {
        if( 0 == Bridge_Loop_mode )
        {
            Bridge_Loop_mode = 1;
            /*set bridge mode 2.  A On B off*/
            NCV7719_data.CH1_6.R = 0b1001111111010101;
            NCV7719_data.CH7_8.R = 0b1100000110000101;
        }

    }
    if( (SystemTickMs - Bridge_Loop_Time) >= 60000 )
    {
        if( 1 == Bridge_Loop_mode )
        {
            Bridge_Loop_mode = 2;
            /*set bridge mode 3.  A Off B on*/
            NCV7719_data.CH1_6.R = 0b1001111110101011;
            NCV7719_data.CH7_8.R = 0b1100000110000011;
        }

    }
    if( (SystemTickMs - Bridge_Loop_Time) >= 70000 )
    {
        if( 2 == Bridge_Loop_mode )
        {
            Bridge_Loop_mode = 3;
            /*set bridge mode 4.  A On B on*/
            NCV7719_data.CH1_6.R = 0b1001111111111111;
            NCV7719_data.CH7_8.R = 0b1100000000000111;
        }
    }

// 	part 3. 传感器5V供电故障
//AD_SEN1 CruiseKeyFaultCode
//AD_SEN2 CruiseKeyFaultCode
//hIOP_PCBTemp_V = HAL_Get_ADC (0);		//:AD 5V_SEN1
// HAL_Get_ADC (0);		//:AD 5V_SEN1
// HAL_Get_ADC (19);	       //:内部参考电压，加速踏1板及怀档供电
// HAL_Get_ADC (18);	       //:内部参考电压，加速踏2板供电

// 	part 4. 频率回路故障：8路,每1秒重新设置一次
    if( (SystemTickMs - PWM_LoopReset_Time) >= 1000 )  //
    {
        PWM_LoopReset_Time = SystemTickMs;

        AGING_TEST_CHANNEL_FREQ_GET[0] = HAL_Get_Finf(AGINGTEST_F_IN_CHANNEL_0);
        AGING_TEST_CHANNEL_FREQ_GET[1] = HAL_Get_Finf(AGINGTEST_F_IN_CHANNEL_1);
        AGING_TEST_CHANNEL_FREQ_GET[2] = HAL_Get_Finf(AGINGTEST_F_IN_CHANNEL_2);
        AGING_TEST_CHANNEL_FREQ_GET[3] = HAL_Get_Finf(AGINGTEST_F_IN_CHANNEL_3);
        AGING_TEST_CHANNEL_FREQ_GET[4] = HAL_Get_Finf(AGINGTEST_F_IN_CHANNEL_4);
        AGING_TEST_CHANNEL_FREQ_GET[5] = HAL_Get_Finf(AGINGTEST_F_IN_CHANNEL_5);
        AGING_TEST_CHANNEL_FREQ_GET[6] = HAL_Get_Finf(AGINGTEST_F_IN_CHANNEL_6);
        AGING_TEST_CHANNEL_FREQ_GET[7] = HAL_Get_Finf(AGINGTEST_F_IN_CHANNEL_7);

        if( 0 == bool_udsAgingTestError_flag )
        {
            AGING_TEST_ERROR_LED = (~AGING_TEST_ERROR_LED) & 0x1;
            my_fs_etpu_pwm_update(AGINGTEST_F_OUT_CHANNEL_0, AGING_TEST_CHANNEL_FREQ_SET[0], AGING_TEST_ERROR_LED * 100 * 100);
        }
        else
        {
            my_fs_etpu_pwm_update(AGINGTEST_F_OUT_CHANNEL_0, AGING_TEST_CHANNEL_FREQ_SET[0], 0 * 100);  //常亮
        }
        if( AGING_TEST_Freq_Inited == 0 )
        {
            AGING_TEST_Freq_Inited = 1;
            my_fs_etpu_pwm_update(AGINGTEST_F_OUT_CHANNEL_1, AGING_TEST_CHANNEL_FREQ_SET[1], 50 * 100);
            my_fs_etpu_pwm_update(AGINGTEST_F_OUT_CHANNEL_2, AGING_TEST_CHANNEL_FREQ_SET[2], 50 * 100);
            my_fs_etpu_pwm_update(AGINGTEST_F_OUT_CHANNEL_3, AGING_TEST_CHANNEL_FREQ_SET[3], 50 * 100);
            my_fs_etpu_pwm_update(AGINGTEST_F_OUT_CHANNEL_4, AGING_TEST_CHANNEL_FREQ_SET[4], 50 * 100);
            my_fs_etpu_pwm_update(AGINGTEST_F_OUT_CHANNEL_5, AGING_TEST_CHANNEL_FREQ_SET[5], 50 * 100);
            my_fs_etpu_pwm_update(AGINGTEST_F_OUT_CHANNEL_6, AGING_TEST_CHANNEL_FREQ_SET[6], 50 * 100);
            my_fs_etpu_pwm_update(AGINGTEST_F_OUT_CHANNEL_7, AGING_TEST_CHANNEL_FREQ_SET[7], 50 * 100);
        }

    }

// 	part 5. 12V供电电压故障：1路
    //use hIOP_K30_V

    return;
}

/*add by yjzh for i-project:ZEEA begin*/
void Lamp_process(Data_id_enum ele_id, uint8_t cmd)
{
	uint8_t * pData = &lamp_global;

    switch (ele_id)
	{

	    case DAYTIMEDRV_LAMP_STS:
			//日行灯
			if (cmd == 0)
			{
				*(pData) = 0;	               
			}
			else
			{
				*(pData) = 1;				
			}
			break;
		case RIGHTTURNLAMPSTS:
			//右转向灯
            if (cmd == 0)
			{
                *(pData+1) = 0;	 
			}
			else
			{
				*(pData+1) = 1;
			}
			break;	
		case BRAKELAMP_SYS:
			//刹车灯
            if (cmd == 0)
			{
				*(pData+2) = 0;  
			}
			else
			{
				*(pData+2) = 1;

			}
			break;				
		case LOW_BEAM_STS:
			//近光灯
			wait_micsec(50);
            if (cmd == 0)
			{
				*(pData+3) = 0;  
			}
			else
			{
				*(pData+3) = 1;
			}

			break;
		case LEFTTURN_LAMP_STS:
			//左转向灯
            if (cmd == 0)
			{
				*(pData+5) = 0;  
			}
			else
			{
				*(pData+5) = 1;
			}

			break;
		case POS_LMP_SYS:
			//位置灯
            if (cmd == 0)
			{
				*(pData+6) = 0;  
			}
			else
			{
				*(pData+6) = 1;
			}
 			break;
		case HIGHBEAM_STS:
			//远光灯
            if (cmd == 0)
			{
				*(pData+7) = 0;  
			}
			else
			{
				*(pData+7) = 1;
			}
 			break;


	
		case HAZARDWARNING_LAMP_STS:
			//告警灯，左右转向灯都亮
			if (cmd == 0)
			{
				*(pData+5) = 0;  
				*(pData+1) = 0;  
			}
			else
			{
				*(pData+5) = 1;
				*(pData+1) = 1;  
			}

			break;


		default:
			break;
	}

	
    LIN_MasterTxFrame(6, lamp_global);
    //LIN_MasterTxFrame(cmd, 0);    //6-远光灯开；7-远光灯关；
                                  //8-位置灯开;9-位置灯关  
                                  //10-转向灯L开；11-转向灯L关
                                  //12-倒车灯开；13-倒车灯关
                                  //14-近光灯开；15-近光灯关
                                  //16-刹车灯开；17-刹车灯关
                                  //18-转向灯R开；19-转向灯R关
                                  //20-日行灯开；21-日行灯关
    return;
}


#if 0
void Lamp_process(Data_id_enum ele_id, uint8_t cmd)
{
    switch (ele_id)
	{
	    case DAYTIMEDRV_LAMP_STS:
			if (cmd == 0)
			{
                LIN_MasterTxFrame(21, 0);
			}
			else
			{
				LIN_MasterTxFrame(20, 0);
			}
			break;
		case LOW_BEAM_STS:
			wait_micsec(50);
			if (cmd == 0)
			{
                LIN_MasterTxFrame(15, 0);
			}
			else
			{
				LIN_MasterTxFrame(14, 0);
			}
			break;
        case POS_LMP_SYS:
            if (cmd == 0)
			{
                LIN_MasterTxFrame(9, 0);
			}
			else
			{
				LIN_MasterTxFrame(8, 0);
			}
			break; 
		case LEFTTURN_LAMP_STS:
            if (cmd == 0)
			{
                LIN_MasterTxFrame(11, 0);
			}
			else
			{
				LIN_MasterTxFrame(10, 0);
			}
			break;
		case RIGHTTURNLAMPSTS:
            if (cmd == 0)
			{
                LIN_MasterTxFrame(19, 0);
			}
			else
			{
				LIN_MasterTxFrame(18, 0);
			}
			break;
		case BRAKELAMP_SYS:
            if (cmd == 0)
			{
                LIN_MasterTxFrame(17, 0);
			}
			else
			{
				LIN_MasterTxFrame(16, 0);
			}
			break;		
		case HAZARDWARNING_LAMP_STS:
            if (cmd == 0)
			{
                LIN_MasterTxFrame(11, 0);
				//wait_micsec(50);
				LIN_MasterTxFrame(19, 0);
			}
			else
			{
				LIN_MasterTxFrame(10, 0);
				//wait_micsec(50);
				LIN_MasterTxFrame(18, 0);
			}
			break;
		case HIGHBEAM_STS:
            if (cmd == 0)
			{
                LIN_MasterTxFrame(7, 0);
			}
			else
			{
				LIN_MasterTxFrame(6, 0);
			}
			break;

		default:
			break;
	}
    //LIN_MasterTxFrame(cmd, 0);    //6-远光灯开；7-远光灯关；
                                  //8-位置灯开;9-位置灯关  
                                  //10-转向灯L开；11-转向灯L关
                                  //12-倒车灯开；13-倒车灯关
                                  //14-近光灯开；15-近光灯关
                                  //16-刹车灯开；17-刹车灯关
                                  //18-转向灯R开；19-转向灯R关
                                  //20-日行灯开；21-日行灯关
    return;
}
#endif
void Locker_process(uint8_t cmd)
{
	
		switch(cmd)
   		{
            case 1:    //lock			   
      		   locker_status = 1;     	       
      	       break;
      	    case 0:    //unlock
      	   	   locker_status = 2; 
      	       break;
      	   default:
                  break;
		}
	  
  
   return;
}

void vdc_can_tx_process(Data_id_enum id, uint8_t  data)
{
	switch (id)
	{
	    case DAYTIMEDRV_LAMP_STS:
            VDC_DaytimeDrvLampSts = data;
			break;
		case LOW_BEAM_STS:
			VDC_LowBeamSts = data;
			break;
        case POS_LMP_SYS:
            VDC_PosLmpSts = data;
			break; 
		case LEFTTURN_LAMP_STS:
            VDC_LeftTurnLampSts = data;
			break;
		case RIGHTTURNLAMPSTS:
            VDC_RightTurnLampSts = data;
			break;
		case BRAKELAMP_SYS:
            VDC_BrakeLampSts = data;
			break;
		case CENTRALLOCK_STS:
            VDC_CentralLockSts = data;
			break;
		case HAZARDWARNING_LAMP_STS:
            VDC_HazardWarningLampSts = data;
			break;
		case HIGHBEAM_STS:
            VDC_HighBeamSts = data;
			break;

		default:
			break;
	}
	
    return;
}

void Eth_send(App_enum app_id, uint8_t * data, uint16_t length)
{
    uint8_t i = 0;  
    _EthernetFrame_tag_ *Enetframe;
	uint8_t eth_data[ETH_PACKET_LENGTH_MAX] = {0};

	if ((data == NULL) || (length == 0))
	{
        return;
	}

    Enetframe = (_EthernetFrame_tag_ *)&eth_data[0];
    for(i = 0; i < 6; i++)
    {
       Enetframe->destination[i] = 0xff;
    }

    Enetframe->source[0] = 0x22;
    Enetframe->source[1] = 0x22;
    Enetframe->source[2] = 0x22;
    Enetframe->source[3] = 0x22;
    Enetframe->source[4] = 0x22;
    Enetframe->source[5] = 0x22;

	Enetframe->data[0] = app_id;

    if (length < ETH_PACKET_LENGTH_MIN-1)
    {
        Enetframe->length = ETH_PACKET_LENGTH_MIN;		
		memcpy(&Enetframe->data[1], data, length);	
	}
	else if (length > ETH_PACKET_LENGTH_MAX-1)
	{
		Enetframe->length = ETH_PACKET_LENGTH_MAX;		
		memcpy(&Enetframe->data[1], data, ETH_PACKET_LENGTH_MAX-1);
	}
	else
	{
		Enetframe->length = length+1;		
		memcpy(&Enetframe->data[1], data, length);
	}   
	
    ENET_TX(&eth_data[0], Enetframe->length+14);
	return;
}

void Eth_receive()
{
    App_enum app_id;
	Data_id_enum ele_id;
	uint8_t  cmd = 0;

	app_id = ENET_RxFrame.data[0];
	ele_id = ENET_RxFrame.data[1];
    cmd = ENET_RxFrame.data[2];  

	vdc_can_tx_process(ele_id, cmd);
	
	switch(app_id)
    {
        case APP_DEFAULT:			
            
			break;
		case APP_LAMP:
			
            Lamp_process(ele_id,cmd);
			break;
		case APP_LOCKER:
            Locker_process(cmd);
			break;
		default:
            break;	
    }
	
    return;
}
/*add by yjzh for i-project:ZEEA end*/

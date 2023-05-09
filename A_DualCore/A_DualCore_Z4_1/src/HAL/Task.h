/*
 * Task.h
 *
 *  Created on: 2018年9月19日
 *      Author: helei
 */

#ifndef HAL_TASK_H_
#define HAL_TASK_H_

#include "typedefs.h"
#include "TaskLib.h"

#ifdef __TASK_GLOBALS__
#define __TASK_EXTERN__
#else
#define __TASK_EXTERN__  extern
#endif

#define ETH_PACKET_LENGTH_MAX 1500
#define ETH_PACKET_LENGTH_MIN 46

typedef enum{
  APP_DEFAULT   = 0,
  APP_LAMP      = 1,
  APP_LOCKER    = 2,
  APP_MAX       = 10
}App_enum;

typedef enum{
  DAYTIMEDRV_LAMP_STS       = 1,  
  LOW_BEAM_STS              = 2,
  POS_LMP_SYS               = 3,
  LEFTTURN_LAMP_STS         = 4,
  RIGHTTURNLAMPSTS          = 5,
  BRAKELAMP_SYS             = 6,
  CENTRALLOCK_STS           = 7,
  HAZARDWARNING_LAMP_STS    = 8,
  HIGHBEAM_STS              = 9
}Data_id_enum;



#define TaskSum		(21u)	//任务总数

//任务编号，数字代表轮询顺序，从小到大
#define TaskCapture 		(0u)
#define TaskSleep 		(1u)
#define TaskStatusMoniter 	(2u)
#define TaskOutput 		(3u)
#define TaskCycle 		(4u)
#define TaskCan 		(5u)
#define TaskBTK             (6u)  //blue tooth Key 
#define TaskEnet 		(7u)
#define TaskCommunication 	(8u)
#define TaskNVM	 		(9u)
#define TaskFeedDog 		(10u)
#define TaskAPPin 		(11u)//DIM HALI
#define TaskAPPbase 		(12u)//PMM CHRG PEPS
#define TaskAPPsport 		(13u)//TQM ACR SCR TQFRate
#define TaskAPPlong 		(14u)//ENM TMM AVAS
#define TaskAPPnetwork 		(15u)//NM
#define TaskAPPout 		(16u)//DOM
#define TaskExchange 		(17u)
#define TaskHWtest 		(18u)//硬件测试任务
#define TaskLin 		(19u)
#define TaskAgingtest 		(20u)//老化测试任务

typedef void (*P2voidFunction)(void);
typedef uint8_t (*P2u8Function)(void);

#define TaskCanRun	(1u)
#define TaskCanStop	(0u)

typedef enum{
  normal = 0,
  runonce = 1,//无条件执行一次
  stoponce = 2,//无条件停止一次
  runalways = 3,//一直执行
  stopalways = 4//一直不执行
}TaskStatusEnum;

typedef struct TASK_struct_tag{
  uint32_t time;//记录本次开始执行的时间，单位1ms
  uint32_t DeltaT;//记录本次执行消耗时间，单位10us
  uint32_t DeltaTmax;//最大的执行消耗时间，单位10us
  TaskStatusEnum stauts;//控制字及状态位
  P2u8Function control;//控制函数；如果可以执行则返回TaskCanRun
  P2voidFunction function;//执行函数
}TASK_tag;

__TASK_EXTERN__ TASK_tag task[TaskSum];//任务列表
__TASK_EXTERN__ volatile uint32_t SystemTickMs;
__TASK_EXTERN__ uint32_t SystemTick10Ms;
__TASK_EXTERN__ uint32_t tick_SBCDog;
__TASK_EXTERN__ uint8_t tick_SBCDog_flag;
extern uint8_t CAN_Send_Cmd;
extern uint8_t CAN_Send_Nm;
extern uint64_t lamp_global;


__TASK_EXTERN__ void Task_Init(void);
__TASK_EXTERN__ void Task_CycleRun(void);
__TASK_EXTERN__ void Eth_send(App_enum app_id, uint8_t * data, uint16_t length);
__TASK_EXTERN__ void Eth_receive();
__TASK_EXTERN__ void vdc_can_tx_process(Data_id_enum id, uint8_t  data);



#endif /* HAL_TASK_H_ */

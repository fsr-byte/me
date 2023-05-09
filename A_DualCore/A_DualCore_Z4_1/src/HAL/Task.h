/*
 * Task.h
 *
 *  Created on: 2018��9��19��
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



#define TaskSum		(21u)	//��������

//�����ţ����ִ�����ѯ˳�򣬴�С����
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
#define TaskHWtest 		(18u)//Ӳ����������
#define TaskLin 		(19u)
#define TaskAgingtest 		(20u)//�ϻ���������

typedef void (*P2voidFunction)(void);
typedef uint8_t (*P2u8Function)(void);

#define TaskCanRun	(1u)
#define TaskCanStop	(0u)

typedef enum{
  normal = 0,
  runonce = 1,//������ִ��һ��
  stoponce = 2,//������ֹͣһ��
  runalways = 3,//һֱִ��
  stopalways = 4//һֱ��ִ��
}TaskStatusEnum;

typedef struct TASK_struct_tag{
  uint32_t time;//��¼���ο�ʼִ�е�ʱ�䣬��λ1ms
  uint32_t DeltaT;//��¼����ִ������ʱ�䣬��λ10us
  uint32_t DeltaTmax;//����ִ������ʱ�䣬��λ10us
  TaskStatusEnum stauts;//�����ּ�״̬λ
  P2u8Function control;//���ƺ������������ִ���򷵻�TaskCanRun
  P2voidFunction function;//ִ�к���
}TASK_tag;

__TASK_EXTERN__ TASK_tag task[TaskSum];//�����б�
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

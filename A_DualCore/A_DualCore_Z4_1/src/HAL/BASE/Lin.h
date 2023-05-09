/*
 * Lin.h
 *
 *  Created on: 2018��12��10��
 *      Author: helei
 */

#ifndef HAL_BASE_LIN_H_
#define HAL_BASE_LIN_H_

#include "typedefs.h"

#ifdef __LIN_GLOBALS__
#define __LIN_EXTERN__
#else
#define __LIN_EXTERN__  extern
#endif

#define LIN_NUM		(3)
#define LIN_TABLENUM	(100)

#define LIN_NULL	(LIN_NUM+1)	//��table�����ø�ֵʱ����ʾ��ǰ�޲���������Ҫ���ͻ����

#define LIN_TX_TIMEOUT	1000000		//not ms just cycle
#define LIN_RX_TIMEOUT	1000000		//not ms just cycle

#define _ERR_LIN_RX_EMPTY_  (12)
#define _ERR_LIN_TASK_ERROR_  (13)
#define _ERR_LIN_TASK_NULL_  (14)	//��ǰ�������У�table�в���Ҫ��������

typedef union _LIN_data_tag_{
	uint64_t R64;
	uint32_t R32[2];
	uint16_t R16[4];
	uint8_t	 R8[8];
}_LIN_data_;

typedef enum LIN_sendflag_tag{
  linsend = 1,
  linrecieve = 2
}LIN_sendflag;

typedef enum LIN_status_tag{
  linnone = 0,
  linsending = 1,
  linsendcomplete = 2,
  linrecieving = 3,
  linrecievecomplete = 4
}LIN_status;

typedef struct _LIN_MESSAGE_tag_{
   uint8_t 	id;
  _LIN_data_ data;//����
  uint16_t period;//����
  LIN_sendflag 	sendrec;//���ͻ����
  LIN_status  status;//����״̬����״̬
}_LIN_MESSAGE_;

#define LIN_TX_OK 0
#define LIN_RX_OK 0
#define LIN_RX_EMPTY  1        /*Rx buffer is empty*/
#define LIN_TX_DLC_TOOLONG 2 /*Tx DLC is too long*/
#define LIN_RX_UNEXPECTED 3  /*unepexcted result received*/


__LIN_EXTERN__ void LIN_Init(void);
__LIN_EXTERN__ uint8_t LIN_MasterTxFrame (uint8_t id, uint64_t data);
__LIN_EXTERN__ uint8_t LIN_MasterRxFrame (uint8_t id, uint64_t *data);
__LIN_EXTERN__ uint16_t LIN_Task(void);
__LIN_EXTERN__ void Lin_Task_App(void);

__LIN_EXTERN__ void LIN_Set_Message(uint8_t num,uint8_t id, LIN_sendflag flag, uint16_t period, uint64_t data);
__LIN_EXTERN__ void LIN_Set_MessageStatus(uint8_t num, LIN_status status);
__LIN_EXTERN__ void LIN_Set_MessageData(uint8_t num, uint64_t data);
__LIN_EXTERN__ void LIN_Set_MessageData_BaseID(uint8_t id, uint64_t data);

__LIN_EXTERN__ void LIN_AutoSetTable(void);

__LIN_EXTERN__ uint16_t LIN_Get_Status(uint8_t num);
__LIN_EXTERN__ uint64_t LIN_Get_Data(uint8_t num);
__LIN_EXTERN__ uint64_t LIN_Get_Data_BaseID(uint8_t id);

__LIN_EXTERN__ uint8_t LIN_MasterTxFrame_WithDlc(uint8_t id, uint16_t dlc, uint64_t data);
__LIN_EXTERN__ uint8_t LIN_MasterRxFrame_WithDlc(uint8_t id, uint16_t dlc, uint64_t *data);

__LIN_EXTERN__  uint8_t LIN_TxOnlyHeadForRx(uint8_t id, uint16_t dlc);
__LIN_EXTERN__ uint8_t LIN_RxAfterTxHead( uint64_t *data);

#endif /* HAL_BASE_LIN_H_ */

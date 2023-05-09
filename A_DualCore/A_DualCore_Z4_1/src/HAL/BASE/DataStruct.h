/*
 * DataStruct.h
 *
 *  Created on: 2019��1��8��
 *      Author: helei
 */

/*
 * LIN Queue & CAN3 RX Queue
 * */

#ifndef HAL_BASE_DATASTRUCT_H_
#define HAL_BASE_DATASTRUCT_H_

#include "typedefs.h"

#ifdef __DATASTRUCT_GLOBALS__
#define __DATASTRUCT_EXTERN__
#else
#define __DATASTRUCT_EXTERN__  extern
#endif

#define LIN_MQ_MAXSIZE	(10)	//������󳤶�
//define about error
#define _ERR_LIN_MQ_FULL_	(5)
#define _ERR_LIN_MQ_EMPTY_	(10)

#define CANRX_MQ_MAXSIZE   (200)	//CAN RX ������󳤶�
#define _ERR_CAN_MQ_FULL_	(5)
#define _ERR_CAN_MQ_EMPTY_	(10)


typedef struct _LIN_DataInMQ_struct_tag_ {
	uint8_t Valid;
	uint64_t Data;
}_LIN_DataInMQ_tag_;

typedef struct _LIN_Frame_struct_tag_ {
	uint8_t id;
	struct {
		uint8_t txStatus:2;	//2:���ͳɹ�   1:�����еȴ���־   0:δ����
		uint8_t rxStatus:2;	//2:���ճɹ�   1:�����еȴ���־   0:δ����
		uint8_t :4;
	}status;
	struct {
		uint16_t tx:1;	//1:����֡  0:����֡
		uint16_t using:1;	//��֡�Ƿ�����
		uint16_t :14;
	}flag;
	uint64_t TxData;
	_LIN_DataInMQ_tag_ * RxDataStructPointer;
}_LIN_Frame_tag_;

typedef struct _LIN_MQ_Control_struct_tag_ {	//LIN ���п��ƽṹ��
	uint32_t Size;		//��ǰ���и���
	uint32_t MaxSize;	//�������ɵ�������
	uint32_t Head;		//ͷλ��
	uint32_t Tail;		//βλ��
	_LIN_Frame_tag_ Frame[LIN_MQ_MAXSIZE];	//��������
}_LIN_MQ_Control_tag_;


typedef struct _CAN_MQ_Control_struct_tag_ {
	uint16_t Size;		//��ǰ���и���
	uint16_t MaxSize;
	uint16_t Head;
	uint16_t Tail;
	CAN_MB_tag Frame[CANRX_MQ_MAXSIZE];
}_CAN_MQ_Control_tag_;


//
__DATASTRUCT_EXTERN__ _LIN_MQ_Control_tag_ LIN_MQ;
__DATASTRUCT_EXTERN__ _LIN_DataInMQ_tag_ LIN_RxData;	//For default RxDataPointer in Function LIN_MQ_PrepareFrame  just for TxData Initial

//
__DATASTRUCT_EXTERN__ _CAN_MQ_Control_tag_ CAN_MQ;

//Function
__DATASTRUCT_EXTERN__ void LIN_MQ_Init(void);
__DATASTRUCT_EXTERN__ uint8_t LIN_MQ_Push(_LIN_Frame_tag_ Frame);
__DATASTRUCT_EXTERN__ _LIN_Frame_tag_ * LIN_MQ_GetCurrentPointer(void);
__DATASTRUCT_EXTERN__ uint8_t LIN_MQ_Pop(_LIN_Frame_tag_ * Frame);

__DATASTRUCT_EXTERN__ void CAN_MQ_Init(void);
__DATASTRUCT_EXTERN__ uint8_t CAN_MQ_Push(void);
__DATASTRUCT_EXTERN__ uint8_t CAN_MQ_Pop(void);
__DATASTRUCT_EXTERN__ CAN_MB_tag * CAN_MQ_GetHead(void);


#endif /* HAL_BASE_DATASTRUCT_H_ */





















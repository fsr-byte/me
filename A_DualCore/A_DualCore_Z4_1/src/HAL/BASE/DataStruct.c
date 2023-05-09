/*
 * DataStruct.c
 *
 *  Created on: 2019��1��8��
 *      Author: helei
 */

#define __DATASTRUCT_GLOBALS__

#include "derivative.h"
#include "DataStruct.h"
#include "string.h"

//LIN
_LIN_MQ_Control_tag_ LIN_MQ;
_LIN_DataInMQ_tag_ LIN_RxData;	//For default RxDataPointer in Function LIN_MQ_PrepareFrame just for TxData Initial

//CAN
_CAN_MQ_Control_tag_ CAN_MQ;


void LIN_MQ_Init(void)
{
	LIN_MQ.MaxSize = LIN_MQ_MAXSIZE;
	LIN_MQ.Size = 0;
	LIN_MQ.Head = 0;
	LIN_MQ.Tail = 0;
}

uint8_t LIN_MQ_Push(_LIN_Frame_tag_ Frame)
{
    if( LIN_MQ.Size >= LIN_MQ.MaxSize )	//�ж϶����Ƿ���
    {
        return _ERR_LIN_MQ_FULL_;	//��������������޷��������֡�����ش�����
    }
    Frame.flag.using = 1;
    Frame.status.rxStatus = 0;
    Frame.status.txStatus = 0;
    memcpy(&(LIN_MQ.Frame[LIN_MQ.Tail]), &(Frame), sizeof(Frame));	//�������
    LIN_MQ.Size++;	//��������1
    LIN_MQ.Tail++;	//β����1
    if( LIN_MQ.Tail >= LIN_MQ.MaxSize )	//��Χ�ж����γ�ѭ������
    {
        LIN_MQ.Tail = 0;
    }

    return 0;
}

_LIN_Frame_tag_ * LIN_MQ_GetCurrentPointer(void)	//��ȡ����ǰ�˵�frameָ��
{
	_LIN_Frame_tag_ * Frame;
	Frame = &(LIN_MQ.Frame[LIN_MQ.Head]);
	return Frame;
}

uint8_t LIN_MQ_Pop(_LIN_Frame_tag_ * Frame)
{
    if( LIN_MQ.Size == 0 )	//�ж϶����Ƿ��
    {
        return _ERR_LIN_MQ_EMPTY_;	//����ǿն������޷���������֡�����ش�����
    }

    memcpy(Frame, &(LIN_MQ.Frame[LIN_MQ.Head]), sizeof(LIN_MQ.Frame[LIN_MQ.Head]));	//��������

//	LIN_MQ.Frame[LIN_MQ.Head].flag.using = 0;
    memset(&(LIN_MQ.Frame[LIN_MQ.Head]), 0, sizeof(LIN_MQ.Frame[LIN_MQ.Head]));	//����Ԫ������

    LIN_MQ.Size--;	//���ȼ���1
    LIN_MQ.Head++;	//����ͷ������1
    if( LIN_MQ.Head >= LIN_MQ.MaxSize )	//��Χ�ж����γ�ѭ������
    {
        LIN_MQ.Head = 0;
    }

    return 0;
}

//CAN
void CAN_MQ_Init(void)
{
  CAN_MQ.MaxSize = CANRX_MQ_MAXSIZE;
  CAN_MQ.Size = 0;
  CAN_MQ.Head = 0;
  CAN_MQ.Tail = 0;
}

/*��MB0��ֱ�Ӷ�ȡ������������շ������У���֧��CAN3 -- C_CAN -- PTCAN
 *HW_MB  -- > MQ
 * */
uint8_t CAN_MQ_Push(void)
{
    if( CAN_MQ.Size >= CAN_MQ.MaxSize )
    {
        return _ERR_CAN_MQ_FULL_;
    }
    CAN_MQ.Frame[CAN_MQ.Tail].CS.R = CAN_3.MB[0].CS.R;	//��������
    CAN_MQ.Frame[CAN_MQ.Tail].ID.R = CAN_3.MB[0].ID.R;
    CAN_MQ.Frame[CAN_MQ.Tail].DATA.W[0] = CAN_3.MB[0].DATA.W[0];
    CAN_MQ.Frame[CAN_MQ.Tail].DATA.W[1] = CAN_3.MB[0].DATA.W[1];

    CAN_MQ.Tail++;
    CAN_MQ.Size++;

    if( CAN_MQ.Tail >= CAN_MQ.MaxSize )	//��Χ�ж����γ�ѭ������
    {
        CAN_MQ.Tail = 0;
    }

    return 0;
}

//ֱ�Ӵӽ��ն����������Ӧ���ݲ�����
uint8_t CAN_MQ_Pop(void)
{
    if( CAN_MQ.Size == 0 )
    {
        return _ERR_CAN_MQ_EMPTY_;
    }

    memset(&(CAN_MQ.Frame[CAN_MQ.Head]), 0, sizeof(CAN_MB_tag));	//�������

    CAN_MQ.Head++;
    CAN_MQ.Size--;

    if( CAN_MQ.Head >= CAN_MQ.MaxSize )
    {
        CAN_MQ.Head = 0;
    }

    return 0;
}

//��ȡ��ǰ�����е�����ָ��
CAN_MB_tag * CAN_MQ_GetHead(void)
{
    CAN_MB_tag * pointer;
    pointer = NULL;
    if( CAN_MQ.Size == 0 )
    {
        return pointer;
    }
    pointer = &CAN_MQ.Frame[CAN_MQ.Head];
    return pointer;
}





















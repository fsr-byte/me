/*
 * CAN.c
 *
 *  Created on: 2018��9��5��
 *      Author: helei
 */
#define __CAN_GLOBALS__

#include "derivative.h"
#include "CAN.h"
#include "Global.h"

volatile struct CAN_tag *CAN[4] = {&CAN_0, &CAN_1, &CAN_2, &CAN_3};

_CAN_MESSAGE_ CAN0_TX_Frame; //����
_CAN_MESSAGE_ CAN1_TX_Frame;
_CAN_MESSAGE_ CAN2_TX_Frame;
_CAN_MESSAGE_ CAN3_TX_Frame;

_CAN_MESSAGE_ CAN0_RX_Frame; //����
_CAN_MESSAGE_ CAN1_RX_Frame;
_CAN_MESSAGE_ CAN2_RX_Frame;
_CAN_MESSAGE_ CAN3_RX_Frame;

_CAN_MESSAGE_ *CAN_RX_Frame[4] = {&CAN0_RX_Frame,&CAN1_RX_Frame,&CAN2_RX_Frame,&CAN3_RX_Frame};


uint8_t CAN_Send(uint8_t canchannel, uint8_t mb, uint32_t config, uint32_t id, uint64_t message )
{
    if( (CAN[canchannel]->MB[mb].CS.B.CODE == 0x08)
            || (CAN[canchannel]->MB[mb].CS.B.CODE == 0) )
    {
        if( mb < 32 )		//�����־λ
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
            CAN[canchannel]->MB[mb].ID.B_EXT.ID = id;  	//Load frame IDentifier
        }
        else
        {
            CAN[canchannel]->MB[mb].ID.B_STD.ID = id;  	//Load frame IDentifier
        }
        CAN[canchannel]->MB[mb].DATA.W[0] = (uint32_t)(message >> 32); //Byte0 - Byte3  of the message
        CAN[canchannel]->MB[mb].DATA.W[1] = (uint32_t)message; //Byte4 - Byte7 of the message
        CAN[canchannel]->MB[mb].CS.B.CODE = 0xc; //After loaded, the MB automatically becomes transmission.
    }
    else
    {
        return 1;	//���ɷ���
    }

    return 0;	//���Է���
}

void CAN_Recive_Set(uint8_t canchannel, uint8_t mb, uint32_t config, uint32_t id)
{
    CAN[canchannel]->MB[mb].CS.R = 0x00080000 | config;   //Length = 8 Bytes
    if( (config & CAN_CS_IDE) == CAN_CS_IDE )
    {
        CAN[canchannel]->MB[mb].ID.B_EXT.ID = id;  	//Load frame IDentifier
    }
    else
    {
        CAN[canchannel]->MB[mb].ID.B_STD.ID = id;  	//Load frame IDentifier
    }

    CAN[canchannel]->MB[mb].CS.B.CODE = 0x04;	//MB empty - ready for receive
}

void CAN_Recive_GetWithID(uint8_t canchannel, uint8_t mb, uint32_t clocktime)
{
    CAN_RX_Frame[canchannel]->control.rtr = CAN[canchannel]->MB[mb].CS.B.RTR;
    if( CAN_RX_Frame[canchannel]->control.rtr != 1 )		//����Զ��֡
    {
        CAN_RX_Frame[canchannel]->control.ide = CAN[canchannel]->MB[mb].CS.B.IDE;
        if( 0 == CAN_RX_Frame[canchannel]->control.ide )
        {
            CAN_RX_Frame[canchannel]->control.id =
                    CAN[canchannel]->MB[mb].ID.B_STD.ID;	//��ֵID,��׼֡
        }
        else
        {
            CAN_RX_Frame[canchannel]->control.id =
                    CAN[canchannel]->MB[mb].ID.B_EXT.ID;	//��ֵID,��չ֡
        }
        //����
        CAN_RX_Frame[canchannel]->control.dlc = CAN[canchannel]->MB[mb].CS.B.DLC;
        CAN_RX_Frame[canchannel]->data.R32[0] = CAN[canchannel]->MB[mb].DATA.W[0];
        CAN_RX_Frame[canchannel]->data.R32[1] = CAN[canchannel]->MB[mb].DATA.W[1];
    }

    CAN_RX_Frame[canchannel]->clocktime = clocktime;		//��¼����ʱ��ʱ��
}

uint32_t CAN_Recive_GetID(uint8_t canchannel, uint8_t mb)
{
    uint32_t id = 0;
    if( 0 == CAN[canchannel]->MB[mb].CS.B.IDE )
    {
        id = CAN[canchannel]->MB[mb].ID.B_STD.ID;		//��ֵID,��׼֡
    }
    else
    {
        id = CAN[canchannel]->MB[mb].ID.B_EXT.ID;		//��ֵID,��չ֡
    }

    return id;
}

uint32_t CAN_SetValue(uint8_t *Buff,uint8_t  start,uint8_t  length , uint32_t Value)
{
    unsigned char for_tick = 0, remain_length = 0;
    unsigned long Buff_filled = 0;
    unsigned long Value_Max = 1;

    Value_Max = (Value_Max << length);

    Value_Max = Value_Max - 1;

    Buff_filled = Value;

    Buff_filled = Buff_filled & Value_Max;

    Buff_filled = (Buff_filled << (start % 8));

    if( length <= (8 - start % 8) )
    {
        for_tick = 1;       //����ܳ���С�ڸ�λ�����ڵ��ֽڵ�ʣ�೤�ȣ������ȡһ���ֽڡ�
    }
    else
    {
        remain_length = length - (8 - start % 8);      //����ʣ�೤��

        if( remain_length % 8 )
        {
            for_tick = remain_length / 8 + 2;        //���ʣ�೤����Ҫ���ֽڣ�����ռ�ֽ�����Ҫ�ӷ�
        }
        else
        {
            for_tick = remain_length / 8 + 1;        //���ʣ�೤�Ȳ���Ҫ���ֽڣ�����ռ�ֽ�����Ҫ��Ҽ
        }
    }

    switch(for_tick)
    {
        case 1:
        {
            *(Buff + (start / 8)) = *(Buff + (start / 8)) | (Buff_filled & 0xff);
            break;
        }
        case 2:
        {
            *(Buff + (start / 8)) = *(Buff + (start / 8)) | (Buff_filled & 0xff);
            *(Buff + (start / 8) - 1) = *(Buff + (start / 8) - 1) | ((Buff_filled >> 8) & 0xff);
            break;
        }
        case 3:
        {
            *(Buff + (start / 8)) = *(Buff + (start / 8)) | (Buff_filled & 0xff);
            *(Buff + (start / 8) - 1) = *(Buff + (start / 8) - 1) | ((Buff_filled >> 8) & 0xff);
            *(Buff + (start / 8) - 2) = *(Buff + (start / 8) - 2) | ((Buff_filled >> 16) & 0xff);
            break;
        }
        case 4:
        {
            *(Buff + (start / 8)) = *(Buff + (start / 8)) | (Buff_filled & 0xff);
            *(Buff + (start / 8) - 1) = *(Buff + (start / 8) - 1) | ((Buff_filled >> 8) & 0xff);
            *(Buff + (start / 8) - 2) = *(Buff + (start / 8) - 2) | ((Buff_filled >> 16) & 0xff);
            *(Buff + (start / 8) - 3) = *(Buff + (start / 8) - 3) | ((Buff_filled >> 24) & 0xff);
            break;
        }
        default:
        {
            break;
        }
    }

    return Buff_filled;
}


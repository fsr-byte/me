/*
 * NCV7513B.c
 *
 *  Created on: 2018��9��5��
 *      Author: helei
 */

#define __NCV7513B_GLOBALS__

#include "derivative.h"
#include "BASE_Global.h"
#include "NCV7513B.h"

_NCV7513B_SI_data_ NCV7513B_SI_data;
_NCV7513B_SO_data_ NCV7513B_SO_data;

void NCV7513B_Init(void)
{
	//��Ҫ��Ӧ��ʼ��DSPI_1 ��������ʹ��
    SIUL_DigitalOutput(NCV7513B_CS, SIUL_GPIO);               // for NCV7513B select , cs
    SIUL_DigitalOutput(NCV7513B_EN2, SIUL_GPIO);              // for NCV7513B en2 , enable2
    SIUL_DigitalInputSimple(NCV7513B_FLTB,SIUL_GPIO);		  // for NCV7513B FLTB
    SIUL_DigitalInputSimple(NCV7513B_STAB,SIUL_GPIO);		  // for NCV7513B STAB

    SIUL_SetPad(NCV7513B_CS);	//Ĭ��CS �ø�
    SIUL_SetPad(NCV7513B_EN2);	//Ĭ�Ͽ������
    //����FLTB֪ͨ����״̬,��MASKѡ��
    NCV7513B_Set_SI(NCV7513B_FLAG_MASK, NCV7513B_DA);			//mask ȫΪ1�� clear״̬������FLTB֪ͨ����״̬
    NCV7513B_Refresh();											//��ȡ0״̬�µĹ�����Ϣ����⿪·���Եض�·���

    //��һ�����
    NCV7513B_Set_SI(NCV7513B_GATE_SELECT, NCV7513B_DN);			//Ĭ��gate ѡ��Ϊ0
    NCV7513B_Refresh();											//��ȡ0״̬�µĹ�����Ϣ����⿪·���Եض�·���

}

void NCV7513B_Diagnosis(void)
{
	//������ع�����Ϣ

	if(SIUL_GetPadState(NCV7513B_FLTB) == 0)	//���ڵ͵�ƽʱ���д������
	{
	    NCV7513B_Set_SI(NCV7513B_NULL_USE, NCV7513B_DN);			//��ȡ���ϴ���
	    NCV7513B_Refresh();
	}//�޴���ʱ����������


}

void NCV7513B_Set_SI(uint8_t address, uint8_t data)
{
	NCV7513B_SI_data.command.address = address;
	NCV7513B_SI_data.command.data = data;
}

void NCV7513B_Set_Data(uint8_t channel, uint8_t data)
{
	if(channel < 6)
	{
		switch(channel)
		{
		case 0 :
			if(data == 0)
				NCV7513B_SI_data.command.data &= (~0x01);
			else
				NCV7513B_SI_data.command.data |= 0x01;
			break;
		case 1 :
			if(data == 0)
				NCV7513B_SI_data.command.data &= (~0x02);
			else
				NCV7513B_SI_data.command.data |= 0x02;
			break;
		case 2 :
			if(data == 0)
				NCV7513B_SI_data.command.data &= (~0x04);
			else
				NCV7513B_SI_data.command.data |= 0x04;
			break;
		case 3 :
			if(data == 0)
				NCV7513B_SI_data.command.data &= (~0x08);
			else
				NCV7513B_SI_data.command.data |= 0x08;
			break;
		case 4 :
			if(data == 0)
				NCV7513B_SI_data.command.data &= (~0x10);
			else
				NCV7513B_SI_data.command.data |= 0x10;
			break;
		case 5 :
			if(data == 0)
				NCV7513B_SI_data.command.data &= (~0x20);
			else
				NCV7513B_SI_data.command.data |= 0x20;
			break;
		}
	}
}

void NCV7513B_Set_Address(uint8_t address)
{
	NCV7513B_SI_data.command.address = address;
}

void NCV7513B_Refresh(void)
{
	uint16_t i = 0, temp = 0;

	for(i=0; i<NCV7513B_RefreshTimes; i++)			/*���Ͳ���ȡ����3��*/
	{
		SIUL_ClearPad(NCV7513B_CS);	//CS select
		DSPI_Send(NCV7513B_SPI, NCV7513B_CTAR, NCV7513B_SI_data.R);
		temp = DSPI_Read(NCV7513B_SPI);
		SIUL_SetPad(NCV7513B_CS);	//CS don't selected
	}

	NCV7513B_SO_data.R = temp;			/*ˢ��״̬����*/
}








/*
 * TJA1100.c
 *
 *  Created on: 2019��1��29��
 *      Author: helei
 */

#define __TJA1100_GLOBALS__

#include "TJA1100.h"
#include "derivative.h"
#include "BASE_Global.h"

_PHY_TJA1100_tag_ PHY_Register;		//TJA1100 global register


/*
 * ��ȡPHYоƬ���мĴ�����ֵ
 * */
void PHY_ReadAllRegister(void)
{
	FEC_ReadManagementFrame(PHY_BasicControlR, &PHY_Register.BasicControlR.R);
	FEC_ReadManagementFrame(PHY_BasicStatusR, &PHY_Register.BasicStatusR.R);
	FEC_ReadManagementFrame(PHY_IDR1, &PHY_Register.IDR1.R);
	FEC_ReadManagementFrame(PHY_IDR2, &PHY_Register.IDR2.R);
	FEC_ReadManagementFrame(PHY_ExtendStatusR, &PHY_Register.ExtendStatusR.R);
	FEC_ReadManagementFrame(PHY_IDR3, &PHY_Register.IDR3.R);
	FEC_ReadManagementFrame(PHY_ExtControlR, &PHY_Register.ExtControlR.R);
	FEC_ReadManagementFrame(PHY_ConfigR1, &PHY_Register.ConfigR1.R);
	FEC_ReadManagementFrame(PHY_ConfigR2, &PHY_Register.ConfigR2.R);
	FEC_ReadManagementFrame(PHY_SymbolErrCountR, &PHY_Register.SymbolErrCountR.R);
	FEC_ReadManagementFrame(PHY_IntStatusR, &PHY_Register.IntStatusR.R);
	FEC_ReadManagementFrame(PHY_IntEnableR, &PHY_Register.IntEnableR.R);
	FEC_ReadManagementFrame(PHY_CommStatusR, &PHY_Register.CommStatusR.R);
	FEC_ReadManagementFrame(PHY_GeneralStatusR, &PHY_Register.GeneralStatusR.R);
	FEC_ReadManagementFrame(PHY_ExternalStatusR, &PHY_Register.ExternalStatusR.R);
	FEC_ReadManagementFrame(PHY_LinkFailCountR, &PHY_Register.LinkFailCountR.R);
}

/*
 * ����Ƿ�����̫���˿������ϣ�����1���������ϣ�0��δ����
 * */
uint16_t PHY_isConnected (void)
{
  uint16_t recode = 0;
  uint8_t result = 0;
  recode = PHY_Get_LinkStatus(&result);
  if (recode)	//��ȡ����
    {
      //��ӡ��ش��󵽰�ȫCAN�ϣ�ASCII����ʽ���ַ���
      return 0;
    }
  else	//�޴���
    {
      if(1 == result)
	return 1;
      else
	return 0;
    }
  return 0;
}

/*
 * ��PHYоƬ���г�ʼ��
 * ��ע�� ��оƬ��֧��100M��ҵ��̫��
 * */
uint16_t PHY_Init (void)
{
  uint8_t result = 0;

  //Get PHY & configure it
  PHY_ReadAllRegister ();

  //PHY_Register.ExtControlR.B.POWER_MODE = 0x3;	//set to normal mode
  PHY_Register.ExtControlR.B.LOOPBACK_MODE = 0x01;	//set to 00:internal loop back mode 01:external loop back
  PHY_Register.ExtControlR.B.CONFIG_EN = 1;		//can change the configure register
  ///PHY_Register.ExtControlR.B.LINK_CONTROL = 1;
  result += FEC_WriteManagementFrame (PHY_ExtControlR, PHY_Register.ExtControlR.R); //д��оƬ

  PHY_Register.ConfigR1.B.MASTER_SLAVE = 1;	//1:Master 0:Slave
  PHY_Register.ConfigR1.B.AUTO_OP = 1;		//1:autonomous 0:managed
  PHY_Register.ConfigR1.B.MII_MODE = 0b10;	//RMII mode enabled (0b10:25MHz XTAL; 0b01:50MHz REFCLK)
  PHY_Register.ConfigR1.B.LED_ENABLE = 1;
  PHY_Register.ConfigR1.B.LED_MODE = 0b00;	//01:frame reception  00:link up
  result += FEC_WriteManagementFrame (PHY_ConfigR1, PHY_Register.ConfigR1.R);	//д��оƬ

  // set 100Mbit/s using Loop back Mode
  PHY_Register.BasicControlR.B.SPEED_SELECT_LSB = 1;	//0:10M/1000M ; 1:100M
  PHY_Register.BasicControlR.B.SPEED_SELECT_MSB = 0;	//0:10M/100M ; 1:1000M
  PHY_Register.BasicControlR.B.LOOPBACK = 0;	//1:ʹ�ûػ�ģʽ; 0:�����ûػ�ģʽ
  result += FEC_WriteManagementFrame (PHY_BasicControlR, PHY_Register.BasicControlR.R);//д��оƬ

  PHY_Register.ExtControlR.B.CONFIG_EN = 0;
  PHY_Register.ExtControlR.B.LINK_CONTROL = 1;
  result += FEC_WriteManagementFrame (PHY_ExtControlR, PHY_Register.ExtControlR.R);//д��оƬ

  PHY_ReadAllRegister ();

  return result;
}

/*
 * ����PHYоƬΪ�����ߴӣ�
 * ��ע����Ϊ��оƬ�����Զ�ʶ�����ã�������Ҫ�ֶ����á������豸����ʱ��Ҫһ����һ���ӡ�
 * */
uint16_t PHY_Config_Master(uint8_t config)
{
  if(PHY_MASTER == config)//��Ҫ����Ϊ��
    {
      if(0 == PHY_Register.ConfigR1.B.MASTER_SLAVE)//��������õ�ֵ��ͬ
	{
	  PHY_Register.ExtControlR.B.CONFIG_EN = 1;		//can change the configure register
	  FEC_WriteManagementFrame (PHY_ExtControlR, PHY_Register.ExtControlR.R); //д��оƬ
	  PHY_Register.ConfigR1.B.MASTER_SLAVE = 1;
	  FEC_WriteManagementFrame (PHY_ConfigR1, PHY_Register.ConfigR1.R);//д��оƬ
	  PHY_Register.ExtControlR.B.CONFIG_EN = 0;		//can't change the configure register
	  FEC_WriteManagementFrame (PHY_ExtControlR, PHY_Register.ExtControlR.R); //д��оƬ
	}
    }
  else//��Ҫ����Ϊ��
    {
      if(1 == PHY_Register.ConfigR1.B.MASTER_SLAVE)//��������õ�ֵ��ͬ
	{
	  PHY_Register.ExtControlR.B.CONFIG_EN = 1;		//can change the configure register
	  FEC_WriteManagementFrame (PHY_ExtControlR, PHY_Register.ExtControlR.R); //д��оƬ
	  PHY_Register.ConfigR1.B.MASTER_SLAVE = 0;
	  FEC_WriteManagementFrame (PHY_ConfigR1, PHY_Register.ConfigR1.R);//д��оƬ
	  PHY_Register.ExtControlR.B.CONFIG_EN = 0;		//can't change the configure register
	  FEC_WriteManagementFrame (PHY_ExtControlR, PHY_Register.ExtControlR.R); //д��оƬ
	}
    }
  return 0;
}

/*
 * ��ȡPHYоƬ��LinkStatus��״̬�������ж�����״̬��
 * ����0������ɻ�ȡ�����򷵻ش����롣״ֵ̬�ӵ�ַ����
 * */
uint16_t PHY_Get_LinkStatus(uint8_t * linkStatus)
{
  uint16_t recode = 0;
  recode = FEC_ReadManagementFrame (PHY_BasicStatusR, &PHY_Register.BasicStatusR.R);
  if(recode)	//���ڴ���
    {
      return recode;
    }
  *linkStatus = PHY_Register.BasicStatusR.B.LINK_STATUS;
  return 0;
}





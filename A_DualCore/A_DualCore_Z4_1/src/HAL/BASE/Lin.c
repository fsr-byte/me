/*
 * Lin.c
 *
 *  Created on: 2018��12��10��
 *      Author: helei
 */

#define __LIN_GLOBALS__

#include "derivative.h"
#include "Lin.h"
#include <math.h>
#include "GPIO.h"
#include "SYS.h"

uint8_t RxBuffer[8] = {0};

_LIN_MESSAGE_ LIN_Array[LIN_NUM];
static uint8_t LIN_Table[LIN_TABLENUM];//����Ϊ���ڵ���LIN_NUM�������÷���

void LIN_ChangeBaudRate(double sysClk, uint32_t baudRate)
{
	double LFDIVvalue = 0;
	double fractionalPart = 0;
	uint32_t integerPart = 0;
	uint32_t fractionalPartRounded = 0;

	LFDIVvalue = sysClk/(16.0*baudRate);

	integerPart = floor(LFDIVvalue);		//to get the integer part
	fractionalPart = LFDIVvalue - floor(LFDIVvalue);		//to get only the fractional part
	fractionalPart*=16;
	fractionalPartRounded = round(fractionalPart);
//	fractionalPartRounded = ceil(fractionalPart);
	LINFlexD_1.LINFBRR.R = fractionalPartRounded;
	LINFlexD_1.LINIBRR.R = integerPart;
}

/*********************************************************************  LIN1   ******************/
void LIN_Init(void)
{ /* Master at 19200 baud with 75MHz LIN_CLK */

	LINFlexD_1.LINCR1.B.INIT = 1; /* Put LINFlex hardware in init mode */
	LINFlexD_1.LINSR.R = 0xFFFF; /* Clear all Interrupt */
	LINFlexD_1.LINIER.B.DTIE = 1; /* Enable TX Interrupt */
	LINFlexD_1.LINIER.B.DRIE = 1; /* Enable RX Interrupt */
	LINFlexD_1.LINCR1.R = 0x00000311; /* Configure module as LIN master & header */
	LIN_ChangeBaudRate(LINFLEX_CLK, 9600);
	LINFlexD_1.LINCR1.R = 0x00000310; /* Change module mode from init to normal */

	//INTC_0.PSR[380].R = INT_to_Core1 | 0x1F;//���ж��͸�core1 && ���ø��ж����ȼ�Ϊ31 LIN1_TX
	//INTC_0.PSR[381].R = INT_to_Core1 | 0x1F;//���ж��͸�core1 && ���ø��ж����ȼ�Ϊ31 LIN1_RX
	/* Configure LINFlexD_1  Pin. */
	SIUL_DigitalInput_LINRX(GPIO_PORTD + 0, 753, 0, 0x01);	//LIN1RX
	SIUL_DigitalOutput_LINTX(GPIO_PORTD + 1, 0x09);		//LIN1TX
}

uint8_t LIN_MasterTxFrame(uint8_t id, uint64_t data)
{
    wait_micsec(50);
	/* Transmit frame*/
	LINFlexD_1.BDRM.R = (uint32_t) (data >> 32); /* Load most significant bytes  */
	LINFlexD_1.BDRL.R = (uint32_t) (data); /* Load least significant bytes */
	LINFlexD_1.BIDR.R = 0x00001E00 | id; /* Init header: ID, 8 B, Tx, enh cksum*/
	LINFlexD_1.LINCR2.B.HTRQ = 1; /* Request header transmission */
	return 0;
}

uint8_t LIN_MasterRxFrame(uint8_t id, uint64_t *data)
{
	/* Request data from ID */
	uint32_t i = 0;

	LINFlexD_1.BDRM.R = 0;
	LINFlexD_1.BDRL.R = 0;
	LINFlexD_1.BIDR.R = 0x00001C00 | id; /* Init header: ID, 8 B, Rx, enh cksum */
	LINFlexD_1.LINCR2.B.HTRQ = 1; /* Request header transmission */
	while ((!LINFlexD_1.LINSR.B.DRF) && (i++ < LIN_RX_TIMEOUT))
		; /* Wait for data receive complete flag */
	if (i >= LIN_RX_TIMEOUT)
	{
		return 1; //error timeout
	}

	*data = LINFlexD_1.BDRM.R;
	*data = (*data) << 32;
	*data += LINFlexD_1.BDRL.R;

	LINFlexD_1.LINSR.R = 0x00000004; /* Clear DRF flag */

	return 0;
}

//----------------------------------------------------------New Function-------------------------------
/*
 * �������ͺ����������ڲ����ж�
 * */
void LIN_Tx(_LIN_MESSAGE_ * message)
{
  LINFlexD_1.BDRM.R = message->data.R32[0]; /* Load most significant bytes  */
  LINFlexD_1.BDRL.R = message->data.R32[1]; /* Load least significant bytes */
  LINFlexD_1.BIDR.R = 0x00001E00 | (message->id); /* Init header: ID, 8 B, Tx, enh cksum*/
  LINFlexD_1.LINCR2.B.HTRQ = 1; /* Request header transmission */
}

/*
 * ����Ƿ�����ɣ��ɹ��򷵻�1�����flag�����򷵻�0
 * */
uint8_t LIN_CheckTx(void)
{
  uint8_t recode = 0;
  if(1 == LINFlexD_1.LINSR.B.DTF)
    {
      recode = 1;//transmit complete
      LINFlexD_1.LINSR.B.DTF = 1;//clear flag
    }
  else
    {
      recode = 0;
    }
  return recode;
}

/*
 * �������պ����������ڲ����жϡ��˺���Ϊ���յĵ�һ��������head�����ݵ������ӽڵ���䡣
 * */
void LIN_Rx_TxHead(_LIN_MESSAGE_ * message)
{
  LINFlexD_1.BDRM.R = 0;
  LINFlexD_1.BDRL.R = 0;
  LINFlexD_1.BIDR.R = 0x00001C00 | (message->id); /* Init header: ID, 8 B, Rx, enh cksum */
  LINFlexD_1.LINCR2.B.HTRQ = 1; /* Request header transmission */
}

/*
 * ���ʱ�������ɣ��ɹ��򷵻�1�����flag�����򷵻�0
 * */
uint8_t LIN_CheckRx(void)
{
  uint8_t recode = 0;
  if(1 == LINFlexD_1.LINSR.B.DRF)
    {
      recode = 1;//recieve complete
      LINFlexD_1.LINSR.B.DRF = 1;//clear flag
    }
  else
    {
      recode = 0;
    }
  return recode;
}

/*
 * �����������ݺ�������������Ӧ��array�У����ý�����ɱ�־λ; ����0ʱ������ճɹ�
 * */
uint16_t LIN_CopyToArray(uint8_t i)
{
  uint16_t errcode = _ERR_LIN_RX_EMPTY_;

  if (i < LIN_NUM)
    {
      LIN_Array[i].data.R32[0] = LINFlexD_1.BDRM.R;	//��������
      LIN_Array[i].data.R32[1] = LINFlexD_1.BDRL.R;
      errcode = 0;
    }

  return errcode;
}

/*
 * �����������ݺ����������յ����ݰ���ID�Ų��ң���������Ӧ��array�У����ý�����ɱ�־λ
 * */
uint16_t LIN_CopyToArray_BaseID(void)
{
  uint8_t i = 0;
  uint8_t id = 0;
  uint16_t errcode = _ERR_LIN_RX_EMPTY_;

  id = LINFlexD_1.BIDR.B.ID;	//��ȡbuff�е�ID��

  for(i = 0; i< LIN_NUM; i++)
    {
      if(LIN_Array[i].id == id)
	{
	  LIN_Array[i].data.R32[0]  = LINFlexD_1.BDRM.R;	//��������
	  LIN_Array[i].data.R32[1]  = LINFlexD_1.BDRL.R;
	  errcode = 0;
	}
    }
  return errcode;
}

/*
 * LIN �շ�������������LIN_Table���з��ͺͽ��ա�ÿ10ms����һ�Σ�
 * */
uint16_t LIN_Task(void)
{
    static uint8_t linTi = LIN_TABLENUM - 1;
    uint8_t i = 0;
    uint16_t temp = 0;
    uint8_t errcode = 0;
    uint8_t recode = _ERR_LIN_TASK_ERROR_;

    if( linTi < LIN_TABLENUM )
    {
        i = LIN_Table[linTi];
        if( i < LIN_NUM )
        {
            //�ϰ벿����⵱ǰ֡�Ƿ��ͻ�������,����ɽ������ݿ����Ĺ���
            if( linsend == LIN_Array[i].sendrec )	//����
            {
                errcode = LIN_CheckTx();
                if( 1 == errcode )	//���ͳɹ�
                {
                    LIN_Array[i].status = linsendcomplete;
                }
                else
                {
                    LIN_Array[i].status = linnone;
                }
            }
            else if( linrecieve == LIN_Array[i].sendrec )  //����
            {
                errcode = LIN_CheckRx();
                if( 1 == errcode )	//���ճɹ�
                {
                    temp = LIN_CopyToArray(i);
                    if( 0 == temp )	//�����ɹ�
                    {
                        LIN_Array[i].status = linrecievecomplete;
                    }
                }
                else
                {
                    LIN_Array[i].status = linnone;
                }
            }
            //�²����Լ�,�ɻ���ִ�з��ͻ����
            linTi++;
            if( linTi >= LIN_TABLENUM )
            {
                linTi = 0;
            }
            i = LIN_Table[linTi];
            if( i < LIN_NUM )	//������������
            {
                if( linsend == LIN_Array[i].sendrec )	//����
                {
                    LIN_Tx(&LIN_Array[i]);
                    recode = 0;
                }
                else if( linrecieve == LIN_Array[i].sendrec )  //����
                {
                    LIN_Rx_TxHead(&LIN_Array[i]);
                    recode = 0;
                }
            }
            else
            {
                recode = _ERR_LIN_TASK_NULL_;
            }
        }
        else	//��ΪLIN_NULLʱ��ִ���²�
        {
            //�²����Լ�,�ɻ���ִ�з��ͻ����
            linTi++;
            if( linTi >= LIN_TABLENUM )
            {
                linTi = 0;
            }
            i = LIN_Table[linTi];
            if( i < LIN_NUM )	//������������
            {
                if( linsend == LIN_Array[i].sendrec )	//����
                {
                    LIN_Tx(&LIN_Array[i]);
                    recode = 0;
                }
                else if( linrecieve == LIN_Array[i].sendrec )  //����
                {
                    LIN_Rx_TxHead(&LIN_Array[i]);
                    recode = 0;
                }
            }
            else
            {
                recode = _ERR_LIN_TASK_NULL_;
            }
        }
    }
    else
    {
        linTi = LIN_TABLENUM - 1;
    }
    Lin_Task_App();
    return recode;
}

/*
 * ��LIN_Array���и�ֵ
 * */
void LIN_Set_Message(uint8_t num,uint8_t id, LIN_sendflag flag, uint16_t period, uint64_t data)
{
  if(num < LIN_NUM)
    {
      LIN_Array[num].id = id;
      LIN_Array[num].sendrec = flag;
      LIN_Array[num].period = period;
      LIN_Array[num].data.R64 = data;
    }
}

/*
 * ��LIN_Array��״̬Ϊ��ֵ��ͨ��λ�ñ�Ž��и�ֵ
 * */
void LIN_Set_MessageStatus(uint8_t num, LIN_status status)
{
  if(num < LIN_NUM)
    {
      LIN_Array[num].status = status;
    }
}

/*
 * ��LIN_Array���и�ֵ��ͨ��λ�ñ�Ž��и�ֵ
 * */
void LIN_Set_MessageData(uint8_t num, uint64_t data)
{
  if(num < LIN_NUM)
    {
      LIN_Array[num].data.R64 = data;
    }
}

/*
 * ��LIN_Array���и�ֵ��ͨ��λID���и�ֵ
 * */
void LIN_Set_MessageData_BaseID(uint8_t id, uint64_t data)
{
  uint8_t i = 0;
  for (i = 0; i < LIN_NUM; i++)
    {
      if (id == LIN_Array[i].id)
	{
	  LIN_Array[i].data.R64 = data;
	  break;
	}
    }
}

/*
 * ��LIN_Arrary�Զ�����LIN_Table
 * */
void LIN_AutoSetTable(void)
{
    uint16_t i = 0, j = 0;
    uint16_t jstart = 0;
    uint16_t period = 100;

    for(i = 0; i < LIN_TABLENUM; i++)
    {
        LIN_Table[i] = LIN_NULL;
    }

    for(i = 0; i < LIN_NUM; i++)
    {
        j = jstart;
        period = LIN_Array[i].period / 20;	//�ۼӼ��
        if( (period < 100) && (period > 0) )	//ʱ�����ڲ�����2s��������Ϊ20ms
        {
            for(; j < LIN_TABLENUM; j += period)
            {
                LIN_Table[j] = i;
            }
            jstart++;
        }
    }
}


/*
 * ����״ֵ̬��ͨ��λ�ñ�Ž��ж�ȡ
 * */
uint16_t LIN_Get_Status(uint8_t num)
{
  uint16_t recode = 0;
  if(num < LIN_NUM)
    {
      recode = LIN_Array[num].status;
    }
  return recode;
}

/*
 * ��������ֵ��ͨ��λλ�ñ�Ž��ж�ȡ
 * */
uint64_t LIN_Get_Data(uint8_t num)
{
  uint64_t recode = 0;

  if (num < LIN_NUM)
    {
      recode = LIN_Array[num].data.R64;
    }
  return recode;
}


/*
 * ��������ֵ��ͨ��λID���ж�ȡ
 * */
uint64_t LIN_Get_Data_BaseID(uint8_t id)
{
  uint64_t recode = 0;
  uint8_t i = 0;

  for (i = 0; i < LIN_NUM; i++)
    {
      if (id == LIN_Array[i].id)
	{
	  recode = LIN_Array[id].data.R64;
	  break;
	}
    }
  return recode;
}

uint8_t LIN_MasterTxFrame_WithDlc(uint8_t id, uint16_t dlc, uint64_t data)
{
  dlc = dlc - 1;
  if (dlc >= 8)
  {
      return 1;
  }

    /* Transmit frame*/
    LINFlexD_1.BDRM.R = (uint32_t) (data >> 32); /* Load most significant bytes  */
    LINFlexD_1.BDRL.R = (uint32_t) (data); /* Load least significant bytes */
    LINFlexD_1.BIDR.R = 0x00000200 | (dlc<<10) | id; /* Init header: ID, 8 B, Tx, enh cksum*/
    LINFlexD_1.LINCR2.B.HTRQ = 1; /* Request header transmission */
    return 0;
}

uint8_t LIN_MasterRxFrame_WithDlc(uint8_t id, uint16_t dlc, uint64_t *data)
{
    /* Request data from ID */
    uint32_t i = 0;

    dlc = dlc - 1;
    if (dlc >= 8)
    {
        return 1;
    }

    LINFlexD_1.BDRM.R = 0;
    LINFlexD_1.BDRL.R = 0;
    LINFlexD_1.BIDR.R = 0x00000000 | (dlc<<10) | id ; /* Init header: ID, 8 B, Rx, enh cksum */
    LINFlexD_1.LINCR2.B.HTRQ = 1; /* Request header transmission */
    while ((!LINFlexD_1.LINSR.B.DRF) && (i++ < LIN_RX_TIMEOUT))
        ; /* Wait for data receive complete flag */
    if (i >= LIN_RX_TIMEOUT)
    {
        return 1; //error timeout
    }

    *data = LINFlexD_1.BDRM.R;
    *data = (*data) << 32;
    *data += LINFlexD_1.BDRL.R;

    LINFlexD_1.LINSR.R = 0x00000004; /* Clear DRF flag */

    return 0;
}


uint8_t LIN_TxOnlyHeadForRx(uint8_t id, uint16_t dlc)
{
    dlc = dlc - 1;
    if (dlc >= 8) 
    {
        return LIN_TX_DLC_TOOLONG;
    }
    LINFlexD_1.BDRM.R = 0;
    LINFlexD_1.BDRL.R = 0;
    LINFlexD_1.BIDR.R = 0x00000000 | (dlc<<10) | id ; /* Init header: ID, 8 B, Rx, enh cksum */
    LINFlexD_1.LINCR2.B.HTRQ = 1; /* Request header transmission */    

    return LIN_TX_OK;
}

uint8_t LIN_RxAfterTxHead( uint64_t *data)
{
    uint8_t rslt = LIN_RX_EMPTY;
    if(1 == LINFlexD_1.LINSR.B.DRF)
    {
        rslt = LIN_RX_OK;
        LINFlexD_1.LINSR.B.DRF = 1;//clear flag
        LINFlexD_1.LINSR.R = 0x00000004; /* Clear DRF flag */
        *data = LINFlexD_1.BDRM.R;
        *data = (*data) << 32;
        *data += LINFlexD_1.BDRL.R;
        
    }
    return rslt;
}



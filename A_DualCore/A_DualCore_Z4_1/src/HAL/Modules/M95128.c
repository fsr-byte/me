/*
 * M95128.c
 *
 *  Created on: 2018��10��16��
 *      Author: helei
 */

#define __M95128_GLOBALS__

#include "derivative.h"
#include "M95128.h"
#include "BASE_Global.h"


void M95128_Init(void)
{
    SIUL_DigitalOutput(M95128_CS, SIUL_GPIO);            // for M95128 select
    SIUL_SetPad(M95128_CS);	//CS don't selected
}

void M95128_tx(uint16_t data)	//SPI����
{
	uint32_t secure_counter;
	DSPI_0.PUSHR.PUSHR.R = (0x90040000 | data);
   	secure_counter = 0;
	while((DSPI_0.SR.B.TCF!=1) && (secure_counter < 50000)){
	secure_counter++;
	}; 			// Wait end of transfert if MASTER
	DSPI_0.SR.B.TCF=1;		// Clear Transfert Flag
}

uint16_t M95128_rx(void)	//SPI����
{
	uint16_t data2;
	uint32_t secure_counter;
	secure_counter = 0;
	while((DSPI_0.SR.B.RFDF != 1) && (secure_counter < 50000)){
	    secure_counter++;
	};	//wait for RX data
	data2 = DSPI_0.POPR.R;					//get received data
	DSPI_0.SR.B.RFDF = 1;					//clear receive flag
	return data2;
}

/***********************************************************/

uint8_t M95128_ReadStatus(void)	//��״̬λ
{
	uint8_t i = 0, temp = 0;
	M95128_CS_Enable();
	for(i=0; i<M95128_ReReadTimes; i++)			/*���Ͳ���ȡ���ݴ���*/
	{
		M95128_tx(M95128_RDSR<<8);
		temp = M95128_rx();
	}
	M95128_CS_Disable();
	return temp;			/*��������*/
}

void M95128_WriteStatus(uint8_t status)	//д״̬λ
{
	uint32_t i = 0;
	M95128_WriteEnable();
	M95128_CS_Enable();
	for(i=0; i<M95128_ReWriteTimes; i++)			/*�������ݴ���*/
	{
		M95128_tx(((M95128_WRSR<<8)|status));
		M95128_rx();
	}
	M95128_CS_Disable();
}

void M95128_WriteEnable(void)	//дʹ��
{
	uint32_t i = 0;
	M95128_CS_Enable();
	for(i=0; i<M95128_ReWriteTimes; i++)			/*�������ݴ���*/
	{
		M95128_tx(M95128_WREN<<8);
		M95128_rx();
	}
	M95128_CS_Disable();
}

void M95128_WriteDisable(void)	//���дʹ��
{
	uint32_t i = 0;
	M95128_CS_Enable();
	for(i=0; i<M95128_ReWriteTimes; i++)			/*�������ݴ���*/
	{
		M95128_tx(M95128_WRDI<<8);
		M95128_rx();
	}
	M95128_CS_Disable();
}

/*****************************************************/
uint8_t Read_byte_EE(uint16_t addr)
{
	uint8_t temp = 0;
	M95128_CS_Enable();
	M95128_tx((M95128_READ<<8)|(addr>>8));
	M95128_rx();
	M95128_tx(addr<<8);
	temp = M95128_rx();
	M95128_CS_Disable();
	return temp;
}
void Write_byte_EE(uint16_t addr, uint8_t data)
{
	M95128_WriteEnable();	//дʹ��
	M95128_CS_Enable();
	M95128_tx((M95128_WRITE<<8) | (addr>>8));
	M95128_rx();
	M95128_tx((addr<<8) | data);
	M95128_rx();
	M95128_CS_Disable();
	M95128_WriteDisable();
}

/*********************************************************/
uint32_t ReadExtEE(uint16_t addr, uint16_t size, uint8_t * data)
{
    uint16_t data_i = 0;
    uint8_t temp = 0;
    uint16_t temp2 = 0;
    uint8_t IniStatus = 0;

    if( (addr >= M95128_Capacity) || ((addr + size) > M95128_Capacity) || (size > M95128_Capacity) )		//��Χ�ж�
    {
        return EXTEE_OUTRANGE;
    }
    if( 1 != M95128_OperationAlready() )
    {
        return EXTEE_BUSY;
    }

    IniStatus = SYS_GetCurIntStatus();
    SYS_Disable_EXTInterrupt();		//�ر��ⲿ�ж�
    M95128_CS_Enable();
    M95128_tx((M95128_READ << 8) | (addr >> 8));
    M95128_rx();
    M95128_tx(addr << 8);
    temp = M95128_rx();
    *(data) = temp;
    if( size % 2 == 1 )
    {
        for(data_i = 1; data_i < size; data_i += 2)
        {
            M95128_tx(0x0000);
            temp2 = M95128_rx();
            *(data + data_i) = temp2 >> 8;
            *(data + data_i + 1) = (uint8_t)temp2;
        }
    }
    else
    {
        for(data_i = 1; data_i < (size - 1); data_i += 2)
        {
            M95128_tx(0x0000);
            temp2 = M95128_rx();
            *(data + data_i) = temp2 >> 8;
            *(data + data_i + 1) = (uint8_t)temp2;
        }
        M95128_tx(0x0000);	//���һ����8λ
        temp2 = M95128_rx();
        *(data + size - 1) = temp2 >> 8;
    }
    M95128_CS_Disable();
    if( IniStatus )
    {
        SYS_Enable_EXTInterrupt();	//�����ⲿ�ж�
    }
    return EXTEE_OK;
}

//�õ�ַ���ö���page����ʼ��ַ����ֻ��������д��һ��page,���ɳ�Խ�߽� ���򷵻�EXTEE_OUTRANGE
uint32_t WriteExtEE(uint16_t addr, uint16_t size, uint8_t *data)

{
    uint16_t data_i = 0, AddrTmp = 0;
    uint8_t AppendData = 0;
    uint8_t IniStatus = 0;

    if( (addr >= M95128_Capacity) || ((addr + size) > M95128_Capacity) || (size > M95128_PageSize) )		//��Χ�ж�
    {
        return EXTEE_OUTRANGE;
    }
    if( (addr / M95128_PageSize) != ((addr + size - 1) / M95128_PageSize) )
    {
        return EXTEE_OUTRANGE;
    }
    if( 1 != M95128_OperationAlready() )
    {
        return EXTEE_BUSY;
    }

    if( 1 == ((size - 1) % 2) )	//ʣ���ֽ�Ϊ����
    {
        if( 0 != ((addr + size) % M95128_PageSize) )	//δ������ҳ�߽�
        {
            ReadExtEE(addr + size, 1, &AppendData);	//��ȡ��ҳ����Ҫ�򸲸Ƕ���д��ֵ,β��ֵ
        }
        else	//������ҳ�߽�,��Ҫ��ȡ��ҳ�ĵ�һ��ֵ
        {
            AddrTmp = addr % M95128_PageSize;
            if( AddrTmp )	//���addr������ҳ����ʼ
            {
                AddrTmp = addr - AddrTmp;
                ReadExtEE(AddrTmp, 1, &AppendData);	//��ȡ��ҳ�ĵ�һ��ֵ��������
            }
            else
            {
                //���addr�������ҳ����ʼ
                AddrTmp = addr - M95128_PageSize;
                AppendData = data[0];	//��ȡ��ҳ�߼��ϼ���д��ĵ�һ��ֵ
            }
        }
    }

    IniStatus = SYS_GetCurIntStatus();
    SYS_Disable_EXTInterrupt();	//�ر��ⲿ�ж�
    M95128_WriteEnable();	//дʹ��
    M95128_CS_Enable();
    M95128_tx((M95128_WRITE << 8) | (addr >> 8));
    M95128_rx();
    M95128_tx((addr << 8) | *data);
    M95128_rx();
    if( 0 == ((size - 1) % 2) )	//ʣ���ֽ�Ϊż��
    {
        for(data_i = 1; data_i < size; data_i += 2)
        {
            M95128_tx(((uint16_t)*(data + data_i) << 8) | (*(data + data_i + 1)));
            M95128_rx();
        }
    }
    else
    {
        for(data_i = 1; data_i < (size - 1); data_i += 2)	//��ʱʣ�����һ���ֽ�δд��
        {
            M95128_tx(((uint16_t)*(data + data_i) << 8) | (*(data + data_i + 1)));
            M95128_rx();
        }
        M95128_tx(((uint16_t)*(data + size - 1) << 8) | (AppendData));	//д�����һ���͸��ӵ���дֵ��
        M95128_rx();
    }
    M95128_CS_Disable();
    if( IniStatus )
    {
        SYS_Enable_EXTInterrupt();	//�����ⲿ�ж�
    }

    return EXTEE_OK;
}

#if 0
uint32_t WriteExtEE(uint16_t addr, uint16_t size, uint8_t * pBuf) {
	uint16_t data_i = 0;
	uint16_t Size_Y = 0;
	uint16_t Size_X = 0;
	uint16_t Size_Header = 0;
	uint16_t size_now = 0, addr_now = 0;
	uint8_t * Buf_now = pBuf;
	uint8_t result;

	result = M95128_OperationAlready();
	if (1 != result) {
		return EXTEE_BUSY;
	}
	if (size != 0) {
		Size_Header = addr % M95128_PageSize;
		if (Size_Header == 0)	//��ʼ��ַΪҳ����ʼ��ַ
				{
			Size_Y = size / M95128_PageSize;
			if (0 == Size_Y)	//û������һ��ҳ
					{
				WritePartPage(addr, pBuf, size);
			} else	//��䳬��һ��ҳʱ
			{
				Size_X = size % M95128_PageSize;
				for (data_i = 0; data_i < Size_Y;)	//������ҳ��ȫ��д��
						{
//					WriteAFullPage((addr + data_i * M95128_PageSize),
//							(pBuf + data_i * M95128_PageSize));
					WritePartPage((addr + data_i * M95128_PageSize),
							(pBuf + data_i * M95128_PageSize),M95128_PageSize);
					data_i++;
					while(0 == M95128_OperationAlready());
				}
				if (Size_X > 0)	//��������ҳд��
						{
					WritePartPage((addr + Size_Y * M95128_PageSize),
							(pBuf + Size_Y * M95128_PageSize),
							(size - Size_Y * M95128_PageSize));
				}
			}
		} else	//��ʼ��ַ��Ϊҳ����ʼ��ַʱ
		{
			size_now = Size_Header + size;
			Size_Y = size_now / M95128_PageSize;
			if (0 == Size_Y)	//��ʼ��ַ���Լ�д������ݶ���ͬһҳ
					{
				WritePartPage(addr, pBuf, size);
			} else	//��ʼ��ַ���Լ�д������ݲ���ͬһҳ
			{
				Size_Header = M95128_PageSize - Size_Header;
				WritePartPage(addr, pBuf, Size_Header);	//д�뿪ʼ�ĵ�һ��ҳ
				//���µ�ַ��
				addr_now = addr + Size_Header;
				size_now = size - Size_Header;
				Buf_now = pBuf + Size_Header;
				while(0 == M95128_OperationAlready());
				Size_Y = size_now / M95128_PageSize;
				if (0 == Size_Y)	//û������һ��ҳ
						{
					WritePartPage(addr_now, Buf_now, size_now);
				} else	//��䳬��һ��ҳʱ
				{
					Size_X = size_now % M95128_PageSize;
					for (data_i = 0; data_i < Size_Y;)	//������ҳ��ȫ��д��
							{
//						WriteAFullPage((addr_now + data_i * M95128_PageSize),
//								(Buf_now + data_i * M95128_PageSize));
						WritePartPage((addr_now + data_i * M95128_PageSize),
								(Buf_now + data_i * M95128_PageSize),M95128_PageSize);
						data_i++;
						while(0 == M95128_OperationAlready());
					}
					if (Size_X > 0)	//��������ҳд��
							{
						WritePartPage((addr_now + Size_Y * M95128_PageSize),
								(Buf_now + Size_Y * M95128_PageSize),
								(size_now - Size_Y * M95128_PageSize));
					}
				}

			}
		}

	} else
		return EXTEE_ERROR;	//��size Ϊ0ʱ�����ش���

	return EXTEE_OK;
}
#endif
/*********************************************************/
uint8_t M95128_OperationAlready(void)
{
	if(1 == (M95128_ReadStatus() & 0x01))
	{
	    return 0;	//����δ���
	}
	else
	{
	    return 1;	//�������
	}
}



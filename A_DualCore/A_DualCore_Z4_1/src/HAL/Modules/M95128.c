/*
 * M95128.c
 *
 *  Created on: 2018年10月16日
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

void M95128_tx(uint16_t data)	//SPI发送
{
	uint32_t secure_counter;
	DSPI_0.PUSHR.PUSHR.R = (0x90040000 | data);
   	secure_counter = 0;
	while((DSPI_0.SR.B.TCF!=1) && (secure_counter < 50000)){
	secure_counter++;
	}; 			// Wait end of transfert if MASTER
	DSPI_0.SR.B.TCF=1;		// Clear Transfert Flag
}

uint16_t M95128_rx(void)	//SPI接收
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

uint8_t M95128_ReadStatus(void)	//读状态位
{
	uint8_t i = 0, temp = 0;
	M95128_CS_Enable();
	for(i=0; i<M95128_ReReadTimes; i++)			/*发送并读取数据次数*/
	{
		M95128_tx(M95128_RDSR<<8);
		temp = M95128_rx();
	}
	M95128_CS_Disable();
	return temp;			/*返回数据*/
}

void M95128_WriteStatus(uint8_t status)	//写状态位
{
	uint32_t i = 0;
	M95128_WriteEnable();
	M95128_CS_Enable();
	for(i=0; i<M95128_ReWriteTimes; i++)			/*发送数据次数*/
	{
		M95128_tx(((M95128_WRSR<<8)|status));
		M95128_rx();
	}
	M95128_CS_Disable();
}

void M95128_WriteEnable(void)	//写使能
{
	uint32_t i = 0;
	M95128_CS_Enable();
	for(i=0; i<M95128_ReWriteTimes; i++)			/*发送数据次数*/
	{
		M95128_tx(M95128_WREN<<8);
		M95128_rx();
	}
	M95128_CS_Disable();
}

void M95128_WriteDisable(void)	//清除写使能
{
	uint32_t i = 0;
	M95128_CS_Enable();
	for(i=0; i<M95128_ReWriteTimes; i++)			/*发送数据次数*/
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
	M95128_WriteEnable();	//写使能
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

    if( (addr >= M95128_Capacity) || ((addr + size) > M95128_Capacity) || (size > M95128_Capacity) )		//范围判断
    {
        return EXTEE_OUTRANGE;
    }
    if( 1 != M95128_OperationAlready() )
    {
        return EXTEE_BUSY;
    }

    IniStatus = SYS_GetCurIntStatus();
    SYS_Disable_EXTInterrupt();		//关闭外部中断
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
        M95128_tx(0x0000);	//最后一个高8位
        temp2 = M95128_rx();
        *(data + size - 1) = temp2 >> 8;
    }
    M95128_CS_Disable();
    if( IniStatus )
    {
        SYS_Enable_EXTInterrupt();	//开启外部中断
    }
    return EXTEE_OK;
}

//该地址不用对其page的起始地址，但只可以用于写入一个page,不可超越边界 否则返回EXTEE_OUTRANGE
uint32_t WriteExtEE(uint16_t addr, uint16_t size, uint8_t *data)

{
    uint16_t data_i = 0, AddrTmp = 0;
    uint8_t AppendData = 0;
    uint8_t IniStatus = 0;

    if( (addr >= M95128_Capacity) || ((addr + size) > M95128_Capacity) || (size > M95128_PageSize) )		//范围判断
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

    if( 1 == ((size - 1) % 2) )	//剩余字节为奇数
    {
        if( 0 != ((addr + size) % M95128_PageSize) )	//未触碰到页边界
        {
            ReadExtEE(addr + size, 1, &AppendData);	//获取该页中需要因覆盖而重写的值,尾端值
        }
        else	//触碰到页边界,需要获取该页的第一个值
        {
            AddrTmp = addr % M95128_PageSize;
            if( AddrTmp )	//如果addr本身不是页的起始
            {
                AddrTmp = addr - AddrTmp;
                ReadExtEE(AddrTmp, 1, &AppendData);	//获取该页的第一个值，物理上
            }
            else
            {
                //如果addr本身就是页的起始
                AddrTmp = addr - M95128_PageSize;
                AppendData = data[0];	//获取该页逻辑上即将写入的第一个值
            }
        }
    }

    IniStatus = SYS_GetCurIntStatus();
    SYS_Disable_EXTInterrupt();	//关闭外部中断
    M95128_WriteEnable();	//写使能
    M95128_CS_Enable();
    M95128_tx((M95128_WRITE << 8) | (addr >> 8));
    M95128_rx();
    M95128_tx((addr << 8) | *data);
    M95128_rx();
    if( 0 == ((size - 1) % 2) )	//剩余字节为偶数
    {
        for(data_i = 1; data_i < size; data_i += 2)
        {
            M95128_tx(((uint16_t)*(data + data_i) << 8) | (*(data + data_i + 1)));
            M95128_rx();
        }
    }
    else
    {
        for(data_i = 1; data_i < (size - 1); data_i += 2)	//此时剩余最后一个字节未写入
        {
            M95128_tx(((uint16_t)*(data + data_i) << 8) | (*(data + data_i + 1)));
            M95128_rx();
        }
        M95128_tx(((uint16_t)*(data + size - 1) << 8) | (AppendData));	//写入最后一个和附加的重写值。
        M95128_rx();
    }
    M95128_CS_Disable();
    if( IniStatus )
    {
        SYS_Enable_EXTInterrupt();	//开启外部中断
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
		if (Size_Header == 0)	//起始地址为页的起始地址
				{
			Size_Y = size / M95128_PageSize;
			if (0 == Size_Y)	//没有填满一个页
					{
				WritePartPage(addr, pBuf, size);
			} else	//填充超过一个页时
			{
				Size_X = size % M95128_PageSize;
				for (data_i = 0; data_i < Size_Y;)	//将整数页的全部写完
						{
//					WriteAFullPage((addr + data_i * M95128_PageSize),
//							(pBuf + data_i * M95128_PageSize));
					WritePartPage((addr + data_i * M95128_PageSize),
							(pBuf + data_i * M95128_PageSize),M95128_PageSize);
					data_i++;
					while(0 == M95128_OperationAlready());
				}
				if (Size_X > 0)	//将非整数页写完
						{
					WritePartPage((addr + Size_Y * M95128_PageSize),
							(pBuf + Size_Y * M95128_PageSize),
							(size - Size_Y * M95128_PageSize));
				}
			}
		} else	//起始地址不为页的起始地址时
		{
			size_now = Size_Header + size;
			Size_Y = size_now / M95128_PageSize;
			if (0 == Size_Y)	//起始地址，以及写入的数据都在同一页
					{
				WritePartPage(addr, pBuf, size);
			} else	//起始地址，以及写入的数据不在同一页
			{
				Size_Header = M95128_PageSize - Size_Header;
				WritePartPage(addr, pBuf, Size_Header);	//写入开始的第一个页
				//更新地址等
				addr_now = addr + Size_Header;
				size_now = size - Size_Header;
				Buf_now = pBuf + Size_Header;
				while(0 == M95128_OperationAlready());
				Size_Y = size_now / M95128_PageSize;
				if (0 == Size_Y)	//没有填满一个页
						{
					WritePartPage(addr_now, Buf_now, size_now);
				} else	//填充超过一个页时
				{
					Size_X = size_now % M95128_PageSize;
					for (data_i = 0; data_i < Size_Y;)	//将整数页的全部写完
							{
//						WriteAFullPage((addr_now + data_i * M95128_PageSize),
//								(Buf_now + data_i * M95128_PageSize));
						WritePartPage((addr_now + data_i * M95128_PageSize),
								(Buf_now + data_i * M95128_PageSize),M95128_PageSize);
						data_i++;
						while(0 == M95128_OperationAlready());
					}
					if (Size_X > 0)	//将非整数页写完
							{
						WritePartPage((addr_now + Size_Y * M95128_PageSize),
								(Buf_now + Size_Y * M95128_PageSize),
								(size_now - Size_Y * M95128_PageSize));
					}
				}

			}
		}

	} else
		return EXTEE_ERROR;	//当size 为0时，返回错误

	return EXTEE_OK;
}
#endif
/*********************************************************/
uint8_t M95128_OperationAlready(void)
{
	if(1 == (M95128_ReadStatus() & 0x01))
	{
	    return 0;	//操作未完成
	}
	else
	{
	    return 1;	//操作完成
	}
}



/*
 * flash.c
 *
 *  Created on: 2018年6月12日
 *      Author: helei
 */

#define __FLASH_GLOBALS__

#include "derivative.h"
#include "flash.h"

//EE 对应ID号(MidIdx)的开始地址
const uint32_t EE_StartAddress[] = {0x00800000,0x00804000,0x00808000,0x0080C000,\
		0x00810000,0x00814000,0x00818000,0x0081C000,0x00820000,0x00830000,0x00840000};

//*************************		FLASH EEPROM OPRATION		****************************************
/*
 * function:	依据地址获取MidIdx的值，即块值
 * input:		addr::	EE的地址位置，0x00800000--0x0083FFFF
 * output:		返回一个MidIdx的值，即区域块的值
 * attention:	仅仅适用于EE
 * */
uint8_t FLASH_EE_GetMidIdx(uint32_t addr)
{
    uint8_t i;
    if( (EE_StartAddress[0] <= addr) && (addr < EE_StartAddress[1]) )
    {
        return 0;
    }
    for(i = 2; i < 11; i++)
    {
        if( (EE_StartAddress[i - 1] <= addr) && (addr < EE_StartAddress[i]) )
        {
            return (i - 1);
        }
    }
    return ERR_FLASH_EE_GetMidIdx;
}


/*
 *
 *
 * attention:	MidIdx范围为0-9，对应EE的起始顺序位置块
 * */
void FLASH_EE_EraseBlock(uint8_t MidIdx)
{
	C55FMC.LOCK0.B.MIDLOCK = MidId_get(MidIdx);	//解锁  Block
	C55FMC.MCR.B.ERS = 1;
	C55FMC.SEL0.B.MIDSEL = MidId_select(MidIdx);
	WRITE32(EE_StartAddress[MidIdx],0xFFFFFFFF);	//写入
	C55FMC.MCR.B.EHV = 1;		//开启高电压允许
	while(C55FMC.MCR.B.DONE != 1);	//判断是否有program或erase 在进行
}

void FLASH_EE_EraseBlockStart(uint8_t MidIdx)
{
	C55FMC.LOCK0.B.MIDLOCK = MidId_get(MidIdx);	//解锁  Block
	C55FMC.MCR.B.ERS = 1;
	C55FMC.SEL0.B.MIDSEL = MidId_select(MidIdx);
	WRITE32(EE_StartAddress[MidIdx],0xFFFFFFFF);	//写入
	C55FMC.MCR.B.EHV = 1;		//开启高电压允许
}

uint8_t FLASH_EE_CheckBusy(void)
{
  uint8_t recode = FLASH_EE_BUSY;
  if(1 == C55FMC.MCR.B.DONE)
  {
    recode = FLASH_EE_IDLE;
  }
  else
  {
    recode = FLASH_EE_BUSY;
  }

  return recode;
}

void FLASH_EE_EraseBlockEnd(uint8_t MidIdx)
{
  C55FMC.MCR.B.EHV = 0;		//关闭高电压允许
  C55FMC.MCR.B.ERS = 0;
  EE_LockBlock(MidId_select(MidIdx));		//再次上锁
}

/*
 * function:	清除EE中全部的数据
 *
 *
 * */
void FLASH_EE_EraseAll(void)
{
	uint8_t i;
	for(i=0; i<10; i++)
	{
		FLASH_EE_EraseBlock(i);
	}
}

/*
 * function:	清除EE中相关块的数据
 *
 *
 * */
void FLASH_EE_Erase(uint32_t address, uint32_t length)
{
    uint8_t istart, iend, i;

    istart = FLASH_EE_GetMidIdx(address);			//得到起始块号
    iend = FLASH_EE_GetMidIdx(address + length - 1);	//的到末尾块号

    if( (ERR_FLASH_EE_GetMidIdx != istart) && (ERR_FLASH_EE_GetMidIdx != iend) )
    {
        for(i = istart; i <= iend; i++)		//将所有需要解锁的块都解锁
        {
            FLASH_EE_EraseBlock(i);
        }
    }
}

void FLASH_EE_EraseStart(uint32_t address, uint32_t length)
{
    uint8_t istart, iend, i;

    istart = FLASH_EE_GetMidIdx(address);			//得到起始块号
    iend = FLASH_EE_GetMidIdx(address + length - 1);	//的到末尾块号
    if( (ERR_FLASH_EE_GetMidIdx != istart) && (ERR_FLASH_EE_GetMidIdx != iend) )
    {
        for(i = istart; i <= iend; i++)		//将所有需要解锁的块都解锁
        {
            FLASH_EE_EraseBlockStart(i);
            break;
        }
    }
}

void FLASH_EE_EraseEnd(uint32_t address, uint32_t length)
{
    uint8_t istart, iend, i;

    istart = FLASH_EE_GetMidIdx(address);			//得到起始块号
    iend = FLASH_EE_GetMidIdx(address + length - 1);	//的到末尾块号
    if( (ERR_FLASH_EE_GetMidIdx != istart) && (ERR_FLASH_EE_GetMidIdx != iend) )
    {
        for(i = istart; i <= iend; i++)		//将所有需要解锁的块都解锁
        {
            FLASH_EE_EraseBlockEnd(i);
            break;
        }
    }
}

/*
 * function:	独立操作写入32bits数据
 *
 * attention:	MidIdx范围为0-9，对应EE的起始顺序位置块
 * */
uint8_t FLASH_EE_Alone_Write32(uint32_t address, uint32_t value)
{
    uint8_t MidIdx;
    MidIdx = FLASH_EE_GetMidIdx(address);
    if( MidIdx == ERR_FLASH_EE_GetMidIdx )
    {
        return 0;
    }
    C55FMC.LOCK0.B.MIDLOCK = MidId_get(MidIdx);	//解锁  Block
    C55FMC.MCR.B.PGM = 1;			//开启写入
    WRITE32(address, value);	//写入
    C55FMC.MCR.B.EHV = 1;		//开启高电压允许
    while(C55FMC.MCR.B.DONE != 1) ;	//判断是否有program或erase 在进行
    C55FMC.MCR.B.EHV = 0;		//关闭高电压允许
    C55FMC.MCR.B.PGM = 0;		//关闭写入
    EE_LockBlock(MidId_select(MidIdx));		//再次上锁

    return 0;
}

/*
 * input:
 *
 * 				*data:	char指针，数组，每个元素为1B
 *
 * attention:	length <= 32*4=128	每次最多可以写入4页数据，每页8个整形,一个整形有4字节;因只能以4B写入所以将元素拼合
 * */
void FLASH_EE_Raw_Write8(uint32_t address, uint32_t length, uint8_t *data)
{
    uint8_t i;
    C55FMC.MCR.B.PGM = 1;			//开启写入
    for(i = 0; i < length; i += 4)
    {
        WRITE32(address + i, (*(data + i) << 24) | (*(data + i + 1) << 16) | (*(data + i + 2) << 8) | (*(data + i + 3)));	//写入
    }
//	WRITE32(address+i, (0x66<<24)|(0x66<<16)|(0x66<<8)|(0x66));	//写入，测试使用
    C55FMC.MCR.B.EHV = 1;		//开启高电压允许
    while(C55FMC.MCR.B.DONE != 1) ;	//判断是否有program或erase 在进行
    C55FMC.MCR.B.EHV = 0;		//关闭高电压允许
    C55FMC.MCR.B.PGM = 0;		//关闭写入
}

/*
 * input:
 *
 * 				*data:	整形指针，数组，每个元素为4B
 *
 * attention:	length <= 32*4=128	每次最多可以写入4页数据，每页8个整形,一个整形有4字节
 * */
void FLASH_EE_Raw_Write32(uint32_t address, uint32_t length, uint32_t *data)
{
    uint8_t i;
    C55FMC.MCR.B.PGM = 1;			//开启写入
    for(i = 0; i < length; i += 4)
    {
        WRITE32(address + i, *(data + (i / 4)));	//写入
    }
//	WRITE32(address+i, 0x66666666);	//写入::测试使用
    C55FMC.MCR.B.EHV = 1;		//开启高电压允许
    while(C55FMC.MCR.B.DONE != 1) ;	//判断是否有program或erase 在进行
    C55FMC.MCR.B.EHV = 0;		//关闭高电压允许
    C55FMC.MCR.B.PGM = 0;		//关闭写入
}

/*
 * function:	将所有相关的饿块都解锁
 *
 *
 * */
void FLASH_EE_UnLock(uint32_t address, uint32_t length)
{
    uint8_t istart, iend, i;

    istart = FLASH_EE_GetMidIdx(address);			//得到起始块号
    iend = FLASH_EE_GetMidIdx(address + length - 1);	//的到末尾块号
    if( (ERR_FLASH_EE_GetMidIdx != istart) && (ERR_FLASH_EE_GetMidIdx != iend) )
    {
        for(i = istart; i <= iend; i++)		//将所有需要解锁的块都解锁
        {
            EE_UnLockBlock(MidId_select(i));
        }
    }
}

/*
 * function:	将所有EE的块都上锁
 *
 *
 * */
void FLASH_EE_Lock()
{
	EE_LockBlock(0xFFFF);		//EE的块全部上锁
}

/*
 *
 *
 * attention:	必须要先将所有需要写入的模块解锁,其中已经调用解锁函数
 * */
uint32_t FLASH_EE_Write8(uint32_t address, uint32_t length, uint8_t *data)
{
    uint32_t i, num;
    uint32_t addressnow = address;
    uint32_t lengthnow = length;
    uint8_t *datanow;
    datanow = data;

    num = length / 128;	//获得所需操作次数
    FLASH_EE_UnLock(address, length);	//解锁所有相关的区域

    for(i = 0; i <= num; i++)
    {
        if( lengthnow >= 128 )
        {
            FLASH_EE_Raw_Write8(addressnow, 128, datanow);		//写入
        }
        else
        {
            FLASH_EE_Raw_Write8(addressnow, lengthnow, datanow);
        }
        addressnow += 128;
        lengthnow -= 128;
        datanow += 128;
    }
    FLASH_EE_Lock();		//对EE进行上锁的操作
    return 0;
}

/*
 *
 *
 * attention:	必须要先将所有需要写入的模块解锁,其中已经调用解锁函数
 * */
void FLASH_EE_Write32(uint32_t address, uint32_t length, uint32_t *data)
{
    uint32_t i, num;
    uint32_t addressnow = address;
    uint32_t lengthnow = length;
    uint32_t *datanow;
    datanow = data;

    num = length / 128;	//获得所需操作次数

    FLASH_EE_UnLock(address, length);	//解锁所有相关的区域

    for(i = 0; i <= num; i++)
    {
        if( lengthnow >= 128 )
        {
            FLASH_EE_Raw_Write32(addressnow, 128, datanow);		//写入
        }
        else
        {
            FLASH_EE_Raw_Write32(addressnow, lengthnow, datanow);
        }
        addressnow += 128;
        lengthnow -= 128;
        datanow += 128;
    }
    FLASH_EE_Lock();		//对EE进行上锁的操作
}

/*
 * function:	回调8位数据数组，不限制读范围。可以是flash，EEPROM，以及SRAM
 *
 * */
uint32_t FLASH_EE_Read8(uint32_t address, uint32_t length, uint8_t * rbuff)
{
	uint32_t i;
	for(i=0; i<length; i++)
	{
		*rbuff = READ8(address+i);
		rbuff++;
	}

	return 0;
}

/*
 * function:	回调32位数据数组，不限制读范围。可以是flash，EEPROM，以及SRAM
 *
 *
 * attention:	输入的length必须为4的倍数
 * */
uint32_t FLASH_EE_Read32(uint32_t address, uint32_t length, uint32_t * rbuff)
{
	uint32_t i;

	if(length%4 != 0)
	{
	  return 1;
	}

	for(i=0; i<length; i+=4)
	{
		*rbuff = READ32(address+i);
		rbuff++;
	}
	return 0;
}





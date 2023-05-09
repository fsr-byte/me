/*
 * flash.c
 *
 *  Created on: 2018��6��12��
 *      Author: helei
 */

#define __FLASH_GLOBALS__

#include "derivative.h"
#include "flash.h"

//EE ��ӦID��(MidIdx)�Ŀ�ʼ��ַ
const uint32_t EE_StartAddress[] = {0x00800000,0x00804000,0x00808000,0x0080C000,\
		0x00810000,0x00814000,0x00818000,0x0081C000,0x00820000,0x00830000,0x00840000};

//*************************		FLASH EEPROM OPRATION		****************************************
/*
 * function:	���ݵ�ַ��ȡMidIdx��ֵ������ֵ
 * input:		addr::	EE�ĵ�ַλ�ã�0x00800000--0x0083FFFF
 * output:		����һ��MidIdx��ֵ����������ֵ
 * attention:	����������EE
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
 * attention:	MidIdx��ΧΪ0-9����ӦEE����ʼ˳��λ�ÿ�
 * */
void FLASH_EE_EraseBlock(uint8_t MidIdx)
{
	C55FMC.LOCK0.B.MIDLOCK = MidId_get(MidIdx);	//����  Block
	C55FMC.MCR.B.ERS = 1;
	C55FMC.SEL0.B.MIDSEL = MidId_select(MidIdx);
	WRITE32(EE_StartAddress[MidIdx],0xFFFFFFFF);	//д��
	C55FMC.MCR.B.EHV = 1;		//�����ߵ�ѹ����
	while(C55FMC.MCR.B.DONE != 1);	//�ж��Ƿ���program��erase �ڽ���
}

void FLASH_EE_EraseBlockStart(uint8_t MidIdx)
{
	C55FMC.LOCK0.B.MIDLOCK = MidId_get(MidIdx);	//����  Block
	C55FMC.MCR.B.ERS = 1;
	C55FMC.SEL0.B.MIDSEL = MidId_select(MidIdx);
	WRITE32(EE_StartAddress[MidIdx],0xFFFFFFFF);	//д��
	C55FMC.MCR.B.EHV = 1;		//�����ߵ�ѹ����
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
  C55FMC.MCR.B.EHV = 0;		//�رոߵ�ѹ����
  C55FMC.MCR.B.ERS = 0;
  EE_LockBlock(MidId_select(MidIdx));		//�ٴ�����
}

/*
 * function:	���EE��ȫ��������
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
 * function:	���EE����ؿ������
 *
 *
 * */
void FLASH_EE_Erase(uint32_t address, uint32_t length)
{
    uint8_t istart, iend, i;

    istart = FLASH_EE_GetMidIdx(address);			//�õ���ʼ���
    iend = FLASH_EE_GetMidIdx(address + length - 1);	//�ĵ�ĩβ���

    if( (ERR_FLASH_EE_GetMidIdx != istart) && (ERR_FLASH_EE_GetMidIdx != iend) )
    {
        for(i = istart; i <= iend; i++)		//��������Ҫ�����Ŀ鶼����
        {
            FLASH_EE_EraseBlock(i);
        }
    }
}

void FLASH_EE_EraseStart(uint32_t address, uint32_t length)
{
    uint8_t istart, iend, i;

    istart = FLASH_EE_GetMidIdx(address);			//�õ���ʼ���
    iend = FLASH_EE_GetMidIdx(address + length - 1);	//�ĵ�ĩβ���
    if( (ERR_FLASH_EE_GetMidIdx != istart) && (ERR_FLASH_EE_GetMidIdx != iend) )
    {
        for(i = istart; i <= iend; i++)		//��������Ҫ�����Ŀ鶼����
        {
            FLASH_EE_EraseBlockStart(i);
            break;
        }
    }
}

void FLASH_EE_EraseEnd(uint32_t address, uint32_t length)
{
    uint8_t istart, iend, i;

    istart = FLASH_EE_GetMidIdx(address);			//�õ���ʼ���
    iend = FLASH_EE_GetMidIdx(address + length - 1);	//�ĵ�ĩβ���
    if( (ERR_FLASH_EE_GetMidIdx != istart) && (ERR_FLASH_EE_GetMidIdx != iend) )
    {
        for(i = istart; i <= iend; i++)		//��������Ҫ�����Ŀ鶼����
        {
            FLASH_EE_EraseBlockEnd(i);
            break;
        }
    }
}

/*
 * function:	��������д��32bits����
 *
 * attention:	MidIdx��ΧΪ0-9����ӦEE����ʼ˳��λ�ÿ�
 * */
uint8_t FLASH_EE_Alone_Write32(uint32_t address, uint32_t value)
{
    uint8_t MidIdx;
    MidIdx = FLASH_EE_GetMidIdx(address);
    if( MidIdx == ERR_FLASH_EE_GetMidIdx )
    {
        return 0;
    }
    C55FMC.LOCK0.B.MIDLOCK = MidId_get(MidIdx);	//����  Block
    C55FMC.MCR.B.PGM = 1;			//����д��
    WRITE32(address, value);	//д��
    C55FMC.MCR.B.EHV = 1;		//�����ߵ�ѹ����
    while(C55FMC.MCR.B.DONE != 1) ;	//�ж��Ƿ���program��erase �ڽ���
    C55FMC.MCR.B.EHV = 0;		//�رոߵ�ѹ����
    C55FMC.MCR.B.PGM = 0;		//�ر�д��
    EE_LockBlock(MidId_select(MidIdx));		//�ٴ�����

    return 0;
}

/*
 * input:
 *
 * 				*data:	charָ�룬���飬ÿ��Ԫ��Ϊ1B
 *
 * attention:	length <= 32*4=128	ÿ��������д��4ҳ���ݣ�ÿҳ8������,һ��������4�ֽ�;��ֻ����4Bд�����Խ�Ԫ��ƴ��
 * */
void FLASH_EE_Raw_Write8(uint32_t address, uint32_t length, uint8_t *data)
{
    uint8_t i;
    C55FMC.MCR.B.PGM = 1;			//����д��
    for(i = 0; i < length; i += 4)
    {
        WRITE32(address + i, (*(data + i) << 24) | (*(data + i + 1) << 16) | (*(data + i + 2) << 8) | (*(data + i + 3)));	//д��
    }
//	WRITE32(address+i, (0x66<<24)|(0x66<<16)|(0x66<<8)|(0x66));	//д�룬����ʹ��
    C55FMC.MCR.B.EHV = 1;		//�����ߵ�ѹ����
    while(C55FMC.MCR.B.DONE != 1) ;	//�ж��Ƿ���program��erase �ڽ���
    C55FMC.MCR.B.EHV = 0;		//�رոߵ�ѹ����
    C55FMC.MCR.B.PGM = 0;		//�ر�д��
}

/*
 * input:
 *
 * 				*data:	����ָ�룬���飬ÿ��Ԫ��Ϊ4B
 *
 * attention:	length <= 32*4=128	ÿ��������д��4ҳ���ݣ�ÿҳ8������,һ��������4�ֽ�
 * */
void FLASH_EE_Raw_Write32(uint32_t address, uint32_t length, uint32_t *data)
{
    uint8_t i;
    C55FMC.MCR.B.PGM = 1;			//����д��
    for(i = 0; i < length; i += 4)
    {
        WRITE32(address + i, *(data + (i / 4)));	//д��
    }
//	WRITE32(address+i, 0x66666666);	//д��::����ʹ��
    C55FMC.MCR.B.EHV = 1;		//�����ߵ�ѹ����
    while(C55FMC.MCR.B.DONE != 1) ;	//�ж��Ƿ���program��erase �ڽ���
    C55FMC.MCR.B.EHV = 0;		//�رոߵ�ѹ����
    C55FMC.MCR.B.PGM = 0;		//�ر�д��
}

/*
 * function:	��������صĶ��鶼����
 *
 *
 * */
void FLASH_EE_UnLock(uint32_t address, uint32_t length)
{
    uint8_t istart, iend, i;

    istart = FLASH_EE_GetMidIdx(address);			//�õ���ʼ���
    iend = FLASH_EE_GetMidIdx(address + length - 1);	//�ĵ�ĩβ���
    if( (ERR_FLASH_EE_GetMidIdx != istart) && (ERR_FLASH_EE_GetMidIdx != iend) )
    {
        for(i = istart; i <= iend; i++)		//��������Ҫ�����Ŀ鶼����
        {
            EE_UnLockBlock(MidId_select(i));
        }
    }
}

/*
 * function:	������EE�Ŀ鶼����
 *
 *
 * */
void FLASH_EE_Lock()
{
	EE_LockBlock(0xFFFF);		//EE�Ŀ�ȫ������
}

/*
 *
 *
 * attention:	����Ҫ�Ƚ�������Ҫд���ģ�����,�����Ѿ����ý�������
 * */
uint32_t FLASH_EE_Write8(uint32_t address, uint32_t length, uint8_t *data)
{
    uint32_t i, num;
    uint32_t addressnow = address;
    uint32_t lengthnow = length;
    uint8_t *datanow;
    datanow = data;

    num = length / 128;	//��������������
    FLASH_EE_UnLock(address, length);	//����������ص�����

    for(i = 0; i <= num; i++)
    {
        if( lengthnow >= 128 )
        {
            FLASH_EE_Raw_Write8(addressnow, 128, datanow);		//д��
        }
        else
        {
            FLASH_EE_Raw_Write8(addressnow, lengthnow, datanow);
        }
        addressnow += 128;
        lengthnow -= 128;
        datanow += 128;
    }
    FLASH_EE_Lock();		//��EE���������Ĳ���
    return 0;
}

/*
 *
 *
 * attention:	����Ҫ�Ƚ�������Ҫд���ģ�����,�����Ѿ����ý�������
 * */
void FLASH_EE_Write32(uint32_t address, uint32_t length, uint32_t *data)
{
    uint32_t i, num;
    uint32_t addressnow = address;
    uint32_t lengthnow = length;
    uint32_t *datanow;
    datanow = data;

    num = length / 128;	//��������������

    FLASH_EE_UnLock(address, length);	//����������ص�����

    for(i = 0; i <= num; i++)
    {
        if( lengthnow >= 128 )
        {
            FLASH_EE_Raw_Write32(addressnow, 128, datanow);		//д��
        }
        else
        {
            FLASH_EE_Raw_Write32(addressnow, lengthnow, datanow);
        }
        addressnow += 128;
        lengthnow -= 128;
        datanow += 128;
    }
    FLASH_EE_Lock();		//��EE���������Ĳ���
}

/*
 * function:	�ص�8λ�������飬�����ƶ���Χ��������flash��EEPROM���Լ�SRAM
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
 * function:	�ص�32λ�������飬�����ƶ���Χ��������flash��EEPROM���Լ�SRAM
 *
 *
 * attention:	�����length����Ϊ4�ı���
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





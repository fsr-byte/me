/*
 * EX_Define.h
 *
 *  Created on: 2019��6��21��
 *      Author: helei
 */

#ifndef HAL_EXCHANGE_EX_DEFINE_H_
#define HAL_EXCHANGE_EX_DEFINE_H_

#include "typedefs.h"
#include "EX_Code.h"
#include "EX_Data.h"

#ifdef __EX_DEFINE_GLOBALS__
#define __EX_DEFINE_EXTERN__
#else
#define __EX_DEFINE_EXTERN__  extern
#endif

/*---------- ��������ʼ��ַ�ͳ���    ------------*/
#define Exchange_C1T0_Addr	(0x40028000)	//Core1-0������
#define Exchange_C1T0_MaxLength	(0x4000)	//16K
#define Exchange_C0T1_Addr	(0x4002C000)	//Core0-1������
#define Exchange_C0T1_MaxLength	(0x4000)	//16K

#define Exchange_Input_Addr	Exchange_C1T0_Addr	//----��ͬ��ʱ��Ҫ�ı�
#define Exchange_Output_Addr	Exchange_C0T1_Addr	//----��ͬ��ʱ��Ҫ�ı�
/*---------- Semaphore ------------*/
#define CoreNone	(0)
#define Core0ID		(1)
#define Core1ID		(2)
#define MyCore		Core0ID		//----��ͬ��ʱ��Ҫ�ı�

//Gate define
#define Gate_C0T1	(0)
#define Gate_C1T0	(1)
#define Gate_SPI	(3)	//Ϊ��Э��Core1�е�SBC��Core0�е�EEPROM������ʹ�ã���Ӵ��ź���
#define Gate_HWInit	(4)	//��Core1��ȡ�������󣬱�ʾCore1�Ѿ���ʼ����ɣ���ʱCore0�������С�
#define Gate_Core0Stop	(5)	//��ι��ʱ��ӽ�Σ��ֵʱ��ʹCore0ֹͣ�ڰ�ȫλ�ã����´�Core1ι���ɹ����ټ���ִ��Core0

#define Gate_Input	Gate_C1T0	//----��ͬ��ʱ��Ҫ�ı�
#define Gate_Output	Gate_C0T1	//----��ͬ��ʱ��Ҫ�ı�

//
#define ERR_MAX_TIMES	(5)	//----�ɵ���
//error
#define _ERR_EX_GATE_	(0x30)	//Gate�Ų�������
#define _ERR_EX_TASK_	(0xC1)	//����������������������
#define _ERR_EX_FLAG_	(0xC2)	//��������־λ����

//Semaphore
__EX_DEFINE_EXTERN__ uint8_t Get_Core_ID(void);
__EX_DEFINE_EXTERN__ uint8_t Get_Gate_Status(uint8_t gate);
__EX_DEFINE_EXTERN__ uint8_t Lock_Gate (uint8_t gate);
__EX_DEFINE_EXTERN__ uint8_t Unlock_Gate(uint8_t gate);
__EX_DEFINE_EXTERN__ uint8_t Reset_Gate(uint8_t gate);
__EX_DEFINE_EXTERN__ void Rest_AllGate(void);



#endif /* HAL_EXCHANGE_EX_DEFINE_H_ */

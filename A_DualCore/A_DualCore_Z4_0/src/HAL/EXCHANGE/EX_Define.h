/*
 * EX_Define.h
 *
 *  Created on: 2019年6月21日
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

/*---------- 交换区起始地址和长度    ------------*/
#define Exchange_C1T0_Addr	(0x40028000)	//Core1-0交换区
#define Exchange_C1T0_MaxLength	(0x4000)	//16K
#define Exchange_C0T1_Addr	(0x4002C000)	//Core0-1交换区
#define Exchange_C0T1_MaxLength	(0x4000)	//16K

#define Exchange_Input_Addr	Exchange_C1T0_Addr	//----不同核时需要改变
#define Exchange_Output_Addr	Exchange_C0T1_Addr	//----不同核时需要改变
/*---------- Semaphore ------------*/
#define CoreNone	(0)
#define Core0ID		(1)
#define Core1ID		(2)
#define MyCore		Core0ID		//----不同核时需要改变

//Gate define
#define Gate_C0T1	(0)
#define Gate_C1T0	(1)
#define Gate_SPI	(3)	//为了协调Core1中的SBC和Core0中的EEPROM的总线使用，添加此信号量
#define Gate_HWInit	(4)	//当Core1获取到改锁后，表示Core1已经初始化完成，此时Core0可以运行。
#define Gate_Core0Stop	(5)	//当喂狗时间接近危险值时，使Core0停止在安全位置，等下次Core1喂狗成功后再继续执行Core0

#define Gate_Input	Gate_C1T0	//----不同核时需要改变
#define Gate_Output	Gate_C0T1	//----不同核时需要改变

//
#define ERR_MAX_TIMES	(5)	//----可调整
//error
#define _ERR_EX_GATE_	(0x30)	//Gate门操作错误
#define _ERR_EX_TASK_	(0xC1)	//任务尝试上锁超出次数错误
#define _ERR_EX_FLAG_	(0xC2)	//交换区标志位错误

//Semaphore
__EX_DEFINE_EXTERN__ uint8_t Get_Core_ID(void);
__EX_DEFINE_EXTERN__ uint8_t Get_Gate_Status(uint8_t gate);
__EX_DEFINE_EXTERN__ uint8_t Lock_Gate (uint8_t gate);
__EX_DEFINE_EXTERN__ uint8_t Unlock_Gate(uint8_t gate);
__EX_DEFINE_EXTERN__ uint8_t Reset_Gate(uint8_t gate);
__EX_DEFINE_EXTERN__ void Rest_AllGate(void);



#endif /* HAL_EXCHANGE_EX_DEFINE_H_ */

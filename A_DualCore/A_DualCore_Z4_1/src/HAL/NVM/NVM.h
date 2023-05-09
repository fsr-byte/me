/*
 * NVM.h
 *
 *
 *  Created on: 2018-10-11
 *      Author: ZhouYi
 */

#ifndef NVM_H_
#define NVM_H_

#include "typedefs.h"
#include "NVM_DidCal.h"
#include "NVM_DTC.h"
#include "NVM_AppData.h"

#ifdef __NVM_GLOBALS__
#define __NVM_EXTERN__
#else
#define __NVM_EXTERN__  extern
#endif
/* -----------------------------------------------------------------------------
    NVM module  type Definitions
------------------------------------------------------------------------------*/
/* -----------------------------------------------------------------------------
      NVM module  Macro Definitions
------------------------------------------------------------------------------*/
__NVM_EXTERN__ void NVM_Init(void);
__NVM_EXTERN__ void NVM_Task(void);
__NVM_EXTERN__ void WriteCalDatalntoDFlash(void);

__NVM_EXTERN__ uint8_t HistDataCheckFaliedFlag;    /*��ʷ���ݼ�����*/
__NVM_EXTERN__ uint8_t AppDataCheckFaliedFlag;     /*�������ݼ�����*/
__NVM_EXTERN__ boolean gbCalDataCorrect;  /*�궨���ݼ�����*/
__NVM_EXTERN__ uint8_t seriousHistFaultFlag ;  /*serious DTC fault, can not go to HV state*/
#endif /* NVM_H_ */

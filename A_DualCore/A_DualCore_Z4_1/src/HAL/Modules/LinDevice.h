/*
 * LinDevice.h
 *
 *  Created on: 2019��1��8��
 *      Author: helei
 */

#ifndef HAL_MODULES_LINDEVICE_H_
#define HAL_MODULES_LINDEVICE_H_

#include "typedefs.h"
#include "BASE_Global.h"

#ifdef __LINDEVICE_GLOBALS__
#define __LINDEVICE_EXTERN__
#else
#define __LINDEVICE_EXTERN__  extern
#endif

//#define TMMEXVCONTROL	 
//#define TMMEXVDEV1	(1)
//#define TMMEXVDEV2	(2)

//#define LIN_EWP		(1)
//#define LIN_EXV		(2)

typedef union _LINEWP_RX_union_tag_{
  uint64_t R;
  struct{
    uint64_t code :16;		//������::0-1
    uint64_t LSBofSpeed :8;	//��ǰ�ٶȵͶ�::2
    uint64_t MSBofSpeed :8;	//��ǰ�ٶȸ߶�::3
    uint64_t LSBofVolatge :8;	//��ѹֵ�Ͷ�::4
    uint64_t MSBofVolatge :8;	//��ѹֵ�߶�::5
    uint64_t T :8;	//current temperature::6
    uint64_t :8;	//reserved::7
  }B;
}_LINEWP_RX_tag_;

typedef union _LINEXV_RX_union_tag_{
  uint64_t R;
  struct{
    uint64_t :3;	//reserved::0
    uint64_t EXVstatus :1;	//�������ͷ�����״̬
    uint64_t EXVinitStatus :2;	//�������ͷ���ʼ��״̬
    uint64_t :1;	//reserved
    uint64_t EXVerrorCheck :1;	//�������ͷ������źż��
    uint64_t EXVterror :2;	//�������ͷ��¶��쳣�ź�::1
    uint64_t EXVvolatgeError :2;//�������ͷ���ѹ�쳣�ź�
    uint64_t EXVerrorStatus :4;	//�������ͷ�����״̬
    uint64_t :8;	//reserved::2
    uint64_t EXVlSBofPosition :8;	//�������ͷ�ʵ��λ�õͶ�::3
    uint64_t EXVmSBofPosition :8;	//�������ͷ�ʵ��λ�ø߶�::4
    uint64_t :24;	//reserved::5-7
  }B;
}_LINEXV_RX_tag_;

typedef union _TMMEXV_union_tag_{	//TMM �������ݽṹ (����)
	uint64_t R;
	struct{
		uint64_t :5;
		uint64_t EVX2Init :3;
		uint64_t :7;
		uint64_t EVX2Enable :1;
		uint64_t EVX2Position :16;
		uint64_t :5;
		uint64_t EVX1Init :3;
		uint64_t :7;
		uint64_t EVX1Enable :1;
		uint64_t EVX1Position :16;
	}B;
}_TMMEXV_tag_;

typedef union _EXV_X_union_tag_{
	uint64_t R;
	struct{
		uint64_t :32;
		uint64_t Position :16;
		uint64_t TemperatureWarn :2;
		uint64_t VoltageState :2;
		uint64_t FaultState :4;
		uint64_t :4;
		uint64_t RunState :1;
		uint64_t CurrentInitState :2;
		uint64_t ResponseError :1;
	}B;
}_EXV_X_tag_;

typedef struct _TMMEXVDATA_struct_tag_{
  _TMMEXV_tag_ control;	//���͵ı���
  _EXV_X_tag_ device1;	//�豸1����Ϣ
  _EXV_X_tag_ device2;	//�豸2����Ϣ
}_TMMEXVDATA_tag_;

__LINDEVICE_EXTERN__ _TMMEXVDATA_tag_ Lin_TMMExvData;
__LINDEVICE_EXTERN__ _LINEWP_RX_tag_ LinEWP_RxData;
__LINDEVICE_EXTERN__ _LINEXV_RX_tag_ LinEXV_RxData;

__LINDEVICE_EXTERN__ void LIN_Device_Init(void);
__LINDEVICE_EXTERN__ void TMMEXV_SetControl_1(uint8_t init,uint8_t enable,uint16_t position);
__LINDEVICE_EXTERN__ void TMMEXV_SetControl_2(uint8_t init,uint8_t enable,uint16_t position);
__LINDEVICE_EXTERN__ void LIN_Device_Refresh(void);

#endif /* HAL_MODULES_LINDEVICE_H_ */

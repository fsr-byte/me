/*
 * LinDevice.h
 *
 *  Created on: 2019年1月8日
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
    uint64_t code :16;		//故障码::0-1
    uint64_t LSBofSpeed :8;	//当前速度低段::2
    uint64_t MSBofSpeed :8;	//当前速度高段::3
    uint64_t LSBofVolatge :8;	//电压值低段::4
    uint64_t MSBofVolatge :8;	//电压值高段::5
    uint64_t T :8;	//current temperature::6
    uint64_t :8;	//reserved::7
  }B;
}_LINEWP_RX_tag_;

typedef union _LINEXV_RX_union_tag_{
  uint64_t R;
  struct{
    uint64_t :3;	//reserved::0
    uint64_t EXVstatus :1;	//电子膨胀阀运行状态
    uint64_t EXVinitStatus :2;	//电子膨胀阀初始化状态
    uint64_t :1;	//reserved
    uint64_t EXVerrorCheck :1;	//电子膨胀阀错误信号检测
    uint64_t EXVterror :2;	//电子膨胀阀温度异常信号::1
    uint64_t EXVvolatgeError :2;//电子膨胀阀电压异常信号
    uint64_t EXVerrorStatus :4;	//电子膨胀阀故障状态
    uint64_t :8;	//reserved::2
    uint64_t EXVlSBofPosition :8;	//电子膨胀阀实际位置低段::3
    uint64_t EXVmSBofPosition :8;	//电子膨胀阀实际位置高段::4
    uint64_t :24;	//reserved::5-7
  }B;
}_LINEXV_RX_tag_;

typedef union _TMMEXV_union_tag_{	//TMM 控制数据结构 (发送)
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
  _TMMEXV_tag_ control;	//发送的报文
  _EXV_X_tag_ device1;	//设备1的信息
  _EXV_X_tag_ device2;	//设备2的信息
}_TMMEXVDATA_tag_;

__LINDEVICE_EXTERN__ _TMMEXVDATA_tag_ Lin_TMMExvData;
__LINDEVICE_EXTERN__ _LINEWP_RX_tag_ LinEWP_RxData;
__LINDEVICE_EXTERN__ _LINEXV_RX_tag_ LinEXV_RxData;

__LINDEVICE_EXTERN__ void LIN_Device_Init(void);
__LINDEVICE_EXTERN__ void TMMEXV_SetControl_1(uint8_t init,uint8_t enable,uint16_t position);
__LINDEVICE_EXTERN__ void TMMEXV_SetControl_2(uint8_t init,uint8_t enable,uint16_t position);
__LINDEVICE_EXTERN__ void LIN_Device_Refresh(void);

#endif /* HAL_MODULES_LINDEVICE_H_ */

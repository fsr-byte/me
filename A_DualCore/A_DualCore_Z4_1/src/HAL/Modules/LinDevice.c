/*
 * LinDevice.c
 *
 *  Created on: 2019��1��8��
 *      Author: helei
 */

#define __LINDEVICE_GLOBALS__

#include "derivative.h"
#include "LinDevice.h"
#include "BASE_Global.h"
#include "Global.h"
//#include "TMM_model.h"


_TMMEXVDATA_tag_ Lin_TMMExvData;
_LINEWP_RX_tag_ LinEWP_RxData;
_LINEXV_RX_tag_ LinEXV_RxData;

//���ݳ�ʼ������
void LIN_Device_Init(void)
{
#ifdef TMMEXVCONTROL
  LIN_Set_Message(TMMEXVCONTROL, 0x11, linsend, 40, 0);	//TMMEXV control
 #endif
#ifdef TMMEXVDEV1
  LIN_Set_Message(TMMEXVDEV1, 0x21, linrecieve, 100, 0);	//TMMEXV 1 info
#endif
#ifdef TMMEXVDEV2
  LIN_Set_Message(TMMEXVDEV2, 0x22, linrecieve, 100, 0);	//TMMEXV 2 info
#endif
#ifdef LIN_EWP
  LIN_Set_Message(LIN_EWP, 0x33, linrecieve, 100, 0);	//EWP info ˮ��״̬
#endif
#ifdef LIN_EXV
  LIN_Set_Message(LIN_EXV, 0x35, linrecieve, 100, 0);	//EXV info �������ͷ�״̬
#endif


  LIN_AutoSetTable();	//ʵʱ���ɵ��ȱ�
}

//״̬���ƺ���1
void TMMEXV_SetControl_1(uint8_t init,uint8_t enable,uint16_t position)
{
	Lin_TMMExvData.control.B.EVX1Init = init;
	Lin_TMMExvData.control.B.EVX1Enable = enable;
	Lin_TMMExvData.control.B.EVX1Position = position;
	LIN_Set_MessageData(0,Lin_TMMExvData.control.R);
}
//״̬���ƺ���1
void TMMEXV_SetControl_2(uint8_t init,uint8_t enable,uint16_t position)
{
	Lin_TMMExvData.control.B.EVX2Init = init;
	Lin_TMMExvData.control.B.EVX2Enable = enable;
	Lin_TMMExvData.control.B.EVX2Position = position;
	LIN_Set_MessageData(0,Lin_TMMExvData.control.R);
}

//����д��Ͷ���ͳһ����,���ݱ�־λ��������Ӧ���ݡ�����װ��Ӧ����
void LIN_Device_Refresh(void)
{
  //uint16_t re_status = 0;

//  STMM_EXV1_initRequest = TMM_output.TMM_TMS_Batt_EXVSt_Init;
//  STMM_EXV1_EnableRequest = 1;
//  STMM_EXV1_PositionRequest = TMM_output.TMM_TMS_Batt_EXVSt_Step;
//
//  STMM_EXV2_initRequest = TMM_output.TMM_TMS_Cabin_EXVSt_Init;
//  STMM_EXV2_EnableRequest = 1;
//  STMM_EXV2_PositionRequest = TMM_output.TMM_TMS_Cabin_EXVSt_Step;

  /*		TMMEXV signal   TX insert */
  TMMEXV_SetControl_1 (STMM_EXV1_initRequest, STMM_EXV1_EnableRequest,
		       STMM_EXV1_PositionRequest);
  TMMEXV_SetControl_2 (STMM_EXV2_initRequest, STMM_EXV2_EnableRequest,
		       STMM_EXV2_PositionRequest);

  /*		LIN Device Receive Operation */
#ifdef LIN_EWP
  re_status = LIN_Get_Status(LIN_EWP);
  if(linrecievecomplete == re_status)	//�豸1�������
    {
      LinEWP_RxData.R = LIN_Get_Data(LIN_EWP);//��ȡ����
//������ָ������
      VHALI_EWP_ErrorCode = LinEWP_RxData.B.code;
      VHALI_EWP_CurrentSpeed = LinEWP_RxData.B.MSBofSpeed;
      VHALI_EWP_CurrentSpeed = (VHALI_EWP_CurrentSpeed << 8) + LinEWP_RxData.B.LSBofSpeed;
      VHALI_EWP_Volatge = LinEWP_RxData.B.MSBofVolatge;
      VHALI_EWP_Volatge = (VHALI_EWP_Volatge << 8) + LinEWP_RxData.B.LSBofVolatge;
      VHALI_EWP_Temperature = LinEWP_RxData.B.T;

      LIN_Set_MessageStatus(LIN_EWP,linrecieving);//���״̬λ
    }
#endif

#ifdef LIN_EXV
  re_status = LIN_Get_Status(LIN_EXV);
  if(linrecievecomplete == re_status)	//�豸1�������
    {
      LinEXV_RxData.R = LIN_Get_Data(LIN_EXV);//��ȡ����
//������ָ������
      VHALI_EXV_ErrorCheck = LinEXV_RxData.B.EXVerrorCheck;
      VHALI_EXV_InitStatus = LinEXV_RxData.B.EXVinitStatus;
      VHALI_EXV_RunStatus = LinEXV_RxData.B.EXVstatus;
      VHALI_EXV_ErrorStatus = LinEXV_RxData.B.EXVerrorStatus;
      VHALI_EXV_VolatgeErrorStatus = LinEXV_RxData.B.EXVvolatgeError;
      VHALI_EXV_TemperatureErrorStatus = LinEXV_RxData.B.EXVterror;
      VHALI_EXV_Position = LinEXV_RxData.B.EXVmSBofPosition;
      VHALI_EXV_Position = (VHALI_EXV_Position << 8) + LinEXV_RxData.B.EXVlSBofPosition;

      LIN_Set_MessageStatus(LIN_EXV,linrecieving);//���״̬λ
    }
#endif


#ifdef TMMEXVDEV1
  /*		TMMEXV signal   RX  */
  re_status = LIN_Get_Status(TMMEXVDEV1);
  if(linrecievecomplete == re_status)	//�豸1�������
    {
      Lin_TMMExvData.device1.R = LIN_Get_Data(TMMEXVDEV1);//��ȡ����

      STMM_EXV1_ResponseError = Lin_TMMExvData.device1.B.ResponseError;
      STMM_EXV1_CurrentInitState = Lin_TMMExvData.device1.B.CurrentInitState;
      STMM_EXV1_RunState = Lin_TMMExvData.device1.B.RunState;
      STMM_EXV1_FaultState = Lin_TMMExvData.device1.B.FaultState;
      STMM_EXV1_VoltageState = Lin_TMMExvData.device1.B.VoltageState;
      STMM_EXV1_TemperatureWarn = Lin_TMMExvData.device1.B.TemperatureWarn;
      STMM_EXV1_CurrentPosition = Lin_TMMExvData.device1.B.Position;

      LIN_Set_MessageStatus(TMMEXVDEV1,linrecieving);//���״̬λ
    }
#endif

#ifdef TMMEXVDEV2
  re_status = LIN_Get_Status(TMMEXVDEV2);
  if(linrecievecomplete == re_status)	//�豸2�������
    {
      Lin_TMMExvData.device2.R = LIN_Get_Data(TMMEXVDEV2);//��ȡ����

      STMM_EXV2_ResponseError = Lin_TMMExvData.device2.B.ResponseError;
      STMM_EXV2_CurrentInitState = Lin_TMMExvData.device2.B.CurrentInitState;
      STMM_EXV2_RunState = Lin_TMMExvData.device2.B.RunState;
      STMM_EXV2_FaultState = Lin_TMMExvData.device2.B.FaultState;
      STMM_EXV2_VoltageState = Lin_TMMExvData.device2.B.VoltageState;
      STMM_EXV2_TemperatureWarn = Lin_TMMExvData.device2.B.TemperatureWarn;
      STMM_EXV2_CurrentPosition = Lin_TMMExvData.device2.B.Position;

      LIN_Set_MessageStatus(TMMEXVDEV2,linrecieving);//���״̬λ
    }
#endif

}


















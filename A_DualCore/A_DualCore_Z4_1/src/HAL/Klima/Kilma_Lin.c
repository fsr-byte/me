#include "Kilma_Lin.h"
#include "Lin.h"
#include "LinDevice.h"

Kilma_Lin Test_Data;

ScheduleTable ScheduleTable_Data =
  { .st_main =
    {
      { &(Test_Data.AQSe_01), 10 },
      { &(Test_Data.HV_He_01), 10 },
      { &(Test_Data.DTSs_01), 10 },
      { &(Test_Data.EKKe_01), 20 },
      { &(Test_Data.FSAs_01), 10 },
      { &(Test_Data.BLOWER1_SET), 10 },
      { &(Test_Data.DTSs_01), 10 },
      { &(Test_Data.EKK3s_01), 20 },
      { &(Test_Data.AQSs_01), 10 },
      { &(Test_Data.HV_Hs_01), 10 },
      { &(Test_Data.DTSs_01), 10 },
      { &(Test_Data.EKKe_01), 20 },
      { &(Test_Data.FSAs_01), 10 },
      { &(Test_Data.BLOWER1_STATUS), 10 },
      { &(Test_Data.DTSs_01), 10 },
      { &(Test_Data.EKK3s_01), 20 },

    }, .st_main_nar =
    {
      { &(Test_Data.AQSe_01), 10 },
      { &(Test_Data.HV_He_01), 10 },
      { &(Test_Data.DTSs_01), 10 },
      { &(Test_Data.EKKe_01), 20 },
      { &(Test_Data.FSAs_01), 10 },
      { &(Test_Data.BLOWER1_SET), 10 },
      { &(Test_Data.DTSs_01), 10 },
      { &(Test_Data.EKK3s_01), 20 },
      { &(Test_Data.AQSs_01), 10 },
      { &(Test_Data.HV_Hs_01), 10 },
      { &(Test_Data.DTSs_01), 10 },
      { &(Test_Data.EKKe_01), 20 },
      { &(Test_Data.FSAs_01), 10 },
      { &(Test_Data.BLOWER1_STATUS), 10 },
      { &(Test_Data.DTSs_01), 10 },
      { &(Test_Data.EKK3s_01), 20 }, }, .st_main_rdw_nar =
    {
      { &(Test_Data.AQSe_01), 10 },
      { &(Test_Data.HV_He_01), 10 },
      { &(Test_Data.DTSs_01), 10 },
      { &(Test_Data.EKKe_01), 20 },
      { &(Test_Data.FSAs_01), 10 },
      { &(Test_Data.BLOWER1_SET), 10 },
      { &(Test_Data.DTSs_01), 10 },
      { &(Test_Data.EKKs_01), 20 },
      { &(Test_Data.AQSs_01), 10 },
      { &(Test_Data.HV_Hs_01), 10 },
      { &(Test_Data.DTSs_01), 10 },
      { &(Test_Data.EKKe_01), 20 },
      { &(Test_Data.FSAs_01), 10 },
      { &(Test_Data.BLOWER1_STATUS), 10 },
      { &(Test_Data.DTSs_01), 10 },
      { &(Test_Data.EKKs_01), 20 }, }, .st_main_OBD =
    {
      { &(Test_Data.AQSe_01), 10 },
      { &(Test_Data.HV_He_01), 10 },
      { &(Test_Data.DTSs_01), 10 },
      { &(Test_Data.EKKe_01), 20 },
      { &(Test_Data.FSAs_01), 10 },
      { &(Test_Data.BLOWER1_SET), 10 },
      { &(Test_Data.DTSs_01), 10 },
      { &(Test_Data.EKK4s_01), 20 },
      { &(Test_Data.AQSs_01), 10 },
      { &(Test_Data.HV_Hs_01), 10 },
      { &(Test_Data.DTSs_01), 10 },
      { &(Test_Data.EKKe_01), 20 },
      { &(Test_Data.FSAs_01), 10 },
      { &(Test_Data.BLOWER1_STATUS), 10 },
      { &(Test_Data.DTSs_01), 10 },
      { &(Test_Data.EKK4s_01), 20 }, }, .st_main2 =
    {
      { &(Test_Data.AQSe_01), 10, },
      { &(Test_Data.HV_He_01), 10, },
      { &(Test_Data.DSs_01), 10, },
      { &(Test_Data.EKKe_01), 20, },
      { &(Test_Data.FSAs_01), 10, },
      { &(Test_Data.BLOWER1_SET), 10, },
      { &(Test_Data.DSs_01), 10, },
      { &(Test_Data.EKK4s_01), 20, },
      { &(Test_Data.AQSs_01), 10, },
      { &(Test_Data.HV_Hs_01), 10, },
      { &(Test_Data.DSs_01), 10, },
      { &(Test_Data.EKKe_01), 20, },
      { &(Test_Data.FSAs_01), 10, },
      { &(Test_Data.BLOWER1_STATUS), 10, },
      { &(Test_Data.DSs_01), 10, },
      { &(Test_Data.EKK4s_01), 20, }, }, .st_EKK_Fehler =
    {
      { &(Test_Data.EKK4s_02), 10, }, }, .DiagRequest =
    {
      { &(Test_Data.MasterReq), 10, }, }, .DiagResponse =
    {
      { &(Test_Data.SlaveResp), 10, }, }, .DiagFunktionalerRequest =
    {
      { &(Test_Data.ISO_Funktionaler_Req_All), 10, } } };

ScheduleTableEntry *pTableEntry = (ScheduleTableEntry *) &ScheduleTable_Data; /**< ָ����ȱ��ָ�� */
uint16_t ScheduleTable_Size; /**< ���ȱ�Ĵ�С */

/**
 * @brief ��ʼ���ṹ�� Frame �ĺ�����
 *
 * @param[in] frame ��Ҫ��ʼ���Ľṹ���ָ��
 * @param[in] id ֡ ID��PID��
 * @param[in] send_flag ���ͱ�־��1 ��ʾ���ͣ�0 ��ʾ���ա�
 * @param[in] data ֡�ľ������ݡ�
 * @return Frame ��ʼ����Ľṹ�塣
 */
void
init_Frame (Frame *frame, uint8_t id, uint8_t send_flag, uint64_t init_Data)
{
  frame->Frame_id = id;
  frame->Send_Flag = send_flag;
  frame->frame1.raw = init_Data;
}
/**

 @brief ��ʼ�����������ڳ�ʼ�����е�Published��Subscribed�Լ�����ź�
 @note �ú���ͨ������init_Frame()������ʼ�����е�Published��Subscribed�Լ�����źţ�
 ������洢�ڶ�Ӧ�Ľṹ���С�
 */
void
Kilma_Lin_Init ()
{
  ScheduleTable_Size = sizeof(ScheduleTable) / 8; /**< ������ȱ�Ĵ�С */
  //��ʼ�����е�Published �ź�

  init_Frame (&(Test_Data.AQSe_01), 0x0A, Published, 0);
  Test_Data.AQSe_01.frame1.AQSe_01.Aussentemp_ungef = 0xFE;
  Test_Data.AQSe_01.frame1.AQSe_01.Navigationsattribute = 0xE;
  Test_Data.AQSe_01.frame1.AQSe_01.Geblaesestufe = 0xE;
  Test_Data.AQSe_01.frame1.AQSe_01.ESP_v_Signal_8Bit = 0xFE;
  Test_Data.AQSe_01.frame1.AQSe_01.Umluft = 0xE;
  init_Frame (&(Test_Data.BLOWER1_SET), 0x27, Published, 0);
  init_Frame (&(Test_Data.EKKe_01), 0x20, Published, 0);
  init_Frame (&(Test_Data.HV_He_01), 0x1C, Published, 0);
  Test_Data.HV_He_01.frame1.Hv_He_01.KL_HV_PTC_soll = 0xFE;
  init_Frame (&(Test_Data.ISO_Funktionaler_Req_All), 0x2C, Published, 0);

  //��ʼ�����е�Subscribed�ź�
  init_Frame (&(Test_Data.AQSs_01), 0x10, Subscribed, 0);
  init_Frame (&(Test_Data.BLOWER1_STATUS), 0x32, Subscribed, 0);
  init_Frame (&(Test_Data.DSs_01), 0x24, Subscribed, 0);
  init_Frame (&(Test_Data.DTSs_01), 0x22, Subscribed, 0);
  init_Frame (&(Test_Data.EKK3s_01), 0x1B, Subscribed, 0);
  init_Frame (&(Test_Data.EKK4s_01), 0xB, Subscribed, 0);
  init_Frame (&(Test_Data.EKK4s_02), 0x35, Subscribed, 0);
  init_Frame (&(Test_Data.EKKs_01), 0x21, Subscribed, 0);
  init_Frame (&(Test_Data.FSAs_01), 0x28, Subscribed, 0);
  init_Frame (&(Test_Data.HV_Hs_01), 0X30, Subscribed, 0);

  //
  init_Frame (&(Test_Data.MasterReq), 0X3C, Published, 0);
  init_Frame (&(Test_Data.SlaveResp), 0X3D, Subscribed, 0);

}

/**
 * @brief ���� LIN ���ߵķ���/����ʱ�����
 *
 * @note �ú���ͨ�����ÿ�����ȱ�����ӳ�ʱ�����ж��Ƿ񵽴����ʱ��㣬
 *       ��������ˣ���ִ����Ӧ�ķ��ͻ���ղ���
 *       �����ʱ������Ϊ10ms��������
 */
void
Schedule_tables_Send ()
{
  static uint8_t i; /**< ������ i */
  static uint8_t j; /**< ������ j */
  i++; /**< ���Ӽ����� i ��ֵ */
  if ((pTableEntry[j].delay_time_ms / 10) == i)
    { /**< �ж��Ƿ񵽴����ʱ��� */

      if (j >= ScheduleTable_Size -1)
	{
	  j = 0;
	}
      i = 0; /**< ���ü����� i ��ֵ */
      if (((Frame *) (pTableEntry[j].Tasks))->Send_Flag == Published)
	{ /**< �ж��Ƿ���Ҫ�������� */
	  LIN_MasterTxFrame_WithDlc (
	      ((Frame *) (pTableEntry[j].Tasks))->Frame_id, 8,
	      ((Frame *) (pTableEntry[j].Tasks))->frame1.raw);
	}
      else if (((Frame *) (pTableEntry[j].Tasks))->Send_Flag == Subscribed)
	{ /**< �ж��Ƿ���Ҫ�������� */
	  LIN_MasterRxFrame_WithDlc (
	      ((Frame *) (pTableEntry[j].Tasks))->Frame_id, 8,
	      &(((Frame *) (pTableEntry[j].Tasks))->frame1.raw));
	}
      else
	{ /**< δ����Ĳ��� */
	  // do nothing
	}
      j++; /**< ���Ӽ����� j ��ֵ */
    }
}

void
Lin_Task_App ()
{
  static uint8_t init_flag;
  if (init_flag == 0)
    {
      Kilma_Lin_Init ();
      init_flag++;
    }
  else
    {
      Schedule_tables_Send ();
    }
}

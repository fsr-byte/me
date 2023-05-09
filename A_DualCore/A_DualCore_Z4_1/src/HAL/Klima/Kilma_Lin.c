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

ScheduleTableEntry *pTableEntry = (ScheduleTableEntry *) &ScheduleTable_Data; /**< 指向调度表的指针 */
uint16_t ScheduleTable_Size; /**< 调度表的大小 */

/**
 * @brief 初始化结构体 Frame 的函数。
 *
 * @param[in] frame 需要初始化的结构体的指针
 * @param[in] id 帧 ID，PID。
 * @param[in] send_flag 发送标志：1 表示发送，0 表示接收。
 * @param[in] data 帧的具体内容。
 * @return Frame 初始化后的结构体。
 */
void
init_Frame (Frame *frame, uint8_t id, uint8_t send_flag, uint64_t init_Data)
{
  frame->Frame_id = id;
  frame->Send_Flag = send_flag;
  frame->frame1.raw = init_Data;
}
/**

 @brief 初始化函数，用于初始化所有的Published和Subscribed以及诊断信号
 @note 该函数通过调用init_Frame()函数初始化所有的Published和Subscribed以及诊断信号，
 并将其存储在对应的结构体中。
 */
void
Kilma_Lin_Init ()
{
  ScheduleTable_Size = sizeof(ScheduleTable) / 8; /**< 计算调度表的大小 */
  //初始化所有的Published 信号

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

  //初始化所有的Subscribed信号
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
 * @brief 用于 LIN 总线的发送/接收时间调度
 *
 * @note 该函数通过检查每个调度表项的延迟时间来判断是否到达调度时间点，
 *       如果到达了，则执行相应的发送或接收操作
 *       请放于时间周期为10ms的任务中
 */
void
Schedule_tables_Send ()
{
  static uint8_t i; /**< 计数器 i */
  static uint8_t j; /**< 计数器 j */
  i++; /**< 增加计数器 i 的值 */
  if ((pTableEntry[j].delay_time_ms / 10) == i)
    { /**< 判断是否到达调度时间点 */

      if (j >= ScheduleTable_Size -1)
	{
	  j = 0;
	}
      i = 0; /**< 重置计数器 i 的值 */
      if (((Frame *) (pTableEntry[j].Tasks))->Send_Flag == Published)
	{ /**< 判断是否需要发送数据 */
	  LIN_MasterTxFrame_WithDlc (
	      ((Frame *) (pTableEntry[j].Tasks))->Frame_id, 8,
	      ((Frame *) (pTableEntry[j].Tasks))->frame1.raw);
	}
      else if (((Frame *) (pTableEntry[j].Tasks))->Send_Flag == Subscribed)
	{ /**< 判断是否需要接收数据 */
	  LIN_MasterRxFrame_WithDlc (
	      ((Frame *) (pTableEntry[j].Tasks))->Frame_id, 8,
	      &(((Frame *) (pTableEntry[j].Tasks))->frame1.raw));
	}
      else
	{ /**< 未定义的操作 */
	  // do nothing
	}
      j++; /**< 增加计数器 j 的值 */
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

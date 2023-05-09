/*
 * main implementation: use this 'C' sample to create your own application
 *
 */

#include "derivative.h" /* include peripheral declarations */
#include "Global.h"
#include "BASE_Global.h"
#include "CAN_Operation.h"
#include "DHP_Model.h"
#include "EX_Define.h"
#include "Task.h"
#include "uds_tp.h"
#include "uds_service.h"
#include "NVM.h"
#include "EX_Define.h"

extern void xcptn_xmpl(void);

/* CAN0: 底盘CAN
 * CAN1: 诊断CAN
 * CAN2: null
 * CAN3: 动力CAN
 *
 * */

int main(void)
{
  uint8_t status = 0;
  status = Get_Gate_Status(Gate_HWInit);
  while(status != Core1ID)//判断Core1是否初始化硬件完成
    {
      status = Get_Gate_Status(Gate_HWInit);
    }
  //此时硬件已经初始化完成。
    xcptn_xmpl (); /* Configure and Enable Interrupts */
    SYS_Disable_EXTInterrupt();	//Disable Interrupts
    SYS_Timer_Init ();
    SYS_SI_Init();
  if (FlagOfInitRam == FLAGOFINITRAM_VALUE)//仅第一次上电时初始化，标定引起的重启不需要初始化
    {
      NvM_Init (); /*NVM must be intialized ealier than UDS, reason: read the security access failure record  */
      udsTpInit ();
      udsServiceInit ();
      FlagOfInitRam ++;
    }
    DHP_model_initialize();
    SYS_Enable_EXTInterrupt();	//Enable Interrupts

  /* Loop forever */
  for (;;)
    {
      TASK_Schedule();

	}
    }

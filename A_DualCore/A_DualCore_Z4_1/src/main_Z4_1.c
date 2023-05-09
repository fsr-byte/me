/*
 * main implementation: use this 'C' sample to create your own application
 *
 */

#include "derivative.h" /* include peripheral declarations */
#include "BASE_Global.h"
#include "Modules_Global.h"
#include "Task.h"
#include "System.h"
#include "CAN_DBC_Lib.h"
#include "CAN_Operation.h"
#include "Global.h"
#include "uds_tp.h"
#include "uds_service.h"
#include "CCP.h"
#include "EX_Define.h"

#define KEY_VALUE1 0x5AF0ul
#define KEY_VALUE2 0xA50Ful

extern void xcptn_xmpl(void);

/* CAN0: 底盘CAN
 * CAN1: 诊断CAN
 * CAN2: null
 * CAN3: 动力CAN
 *
 * */

void hw_init(void)
{
#if defined(DEBUG_SECONDARY_CORE)
	uint32_t mctl = MC_ME.MCTL.R;
	/* enable core 0 in all modes */
	MC_ME.CCTL[1].R = 0x00FE;
	/* Set Start address for core 0: Will reset and start */
#if defined(START_FROM_FLASH)
    MC_ME.CADDR[1].R = 0x11c0000 | 0x1;
#else
    MC_ME.CADDR[1].R = 0x40000000 | 0x1;
#endif /* defined(START_FROM_FLASH) */ 
	
	MC_ME.MCTL.R = (mctl & 0xffff0000ul) | KEY_VALUE1;
	MC_ME.MCTL.R =  mctl; /* key value 2 always from MCTL */
#endif /* defined(DEBUG_SECONDARY_CORE) */
}
uint32_t test_front_rear_flag=0;
int main(void)
{
  volatile int counter = 0;
  uint32_t currTime;
  uint8_t temp = 0;

  xcptn_xmpl (); /* Configure IntTable Address and Enable Interrupts */
  SYS_Disable_EXTInterrupt ();	//Disable Interrupts
  HAL_Set_HALVersion (1.01); //设定底层软件版本
  Init_System ();
  Ex_Base_LockGate (Gate_HWInit);
  hw_init ();	//初始化硬件后引导启动core0功能安全核
  SYS_Enable_EXTInterrupt ();	//Enable Interrupts
  Task_Init ();

  /* Loop forever */
  for (;;)
    {
      counter++;
      currTime = SystemTickMs;
      Task_CycleRun ();
#if 0
      if(1==test_front_rear_flag)
     {
     HAL_Drive_LS (0, 1); //LS1OUT1:座椅电机正转 2
     HAL_Drive_LS (7, 0); // 1 , 0
     }
     else if(2==test_front_rear_flag)
     {
     HAL_Drive_LS (0, 0);
     HAL_Drive_LS (7, 1);	//LS2OUT2:座椅电机反转 62  0, 1
     }
     else
     {
     HAL_Drive_LS (0, 0);
     HAL_Drive_LS (7, 0);	//no operation
     }
      HAL_Drive_HLS();
#endif
      HAL_Capture_Digital();


      if(VHALI_SeatHallActiveIn_flg!=hIOP_SeatHall_flg)
      {
      extern uint32_t VHALI_SeatHallcnt;
      VHALI_SeatHallcnt++;
      }
      VHALI_SeatHallActiveIn_flg =hIOP_SeatHall_flg;//S21
      temp = (uint8_t)(SystemTickMs -currTime);//时间以1ms为单位
      if(temp != 0)
	{
	  VHALO_TotalLoopTime = temp;
	}
    }
}



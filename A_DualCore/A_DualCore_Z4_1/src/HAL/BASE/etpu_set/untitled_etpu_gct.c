/************************************************************************
 *    This file was generated by eTPU Graphical Configuration Tool        
 *                                                                        
 *    DO NOT EDIT !!! DO NOT EDIT !!! DO NOT EDIT !!! DO NOT EDIT !!!     
 *                                                                        
 *  DESCRIPTION:
 *  This file contains my_system_etpu_init and my_system_etpu_start
 *  functions and related items. The function initialize the eTPU 
 *  global and channel settings, based on the user settings 
 *  in the eTPU GCT, and runs the eTPU.               
 *  A header file of the same name .h is also generated.                   
 *
 *  Creation Date:  2018/11/15 13:35:00 
 *
 **************************************************************************/

/* general routines */
#include "etpu_util.h"             /* Utility routines for working eTPU */

/* eTPU function set used */
#include "etpu_set.h"

/* eTPU functions APIs */
#include "etpu_pwm.h" /* PWM */

/* our private header file (generated by eTPU GCT) */
#include "untitled_etpu_gct.h"



/* External object declarations */
/* ... no external variables used */


/**************************************************************************
 * 
 * Global Variables
 *
 **************************************************************************/

uint32_t *fs_free_param;

/**************************************************************************
 *
 * CPU and clock configuration:
 *
 *   CPU = Generic CPU with eTPU2
 *   SYSCLK = 200 MHz
 *   Input_TCRCLK_A = OFF
 *   Input_TCRCLK_B = OFF
 *   
 **************************************************************************/

uint32_t etpu_a_tcr1_freq = 10000000;
uint32_t etpu_a_tcr2_freq = 25000000;
uint32_t etpu_b_tcr1_freq = 10000000;
uint32_t etpu_b_tcr2_freq = 25000000;


/**************************************************************************
 * 
 * etpu_config structure filled accodring to the user settings
 *
 **************************************************************************/

struct etpu_config_t my_etpu_config =
{
  /* etpu_config.mcr */
  FS_ETPU_VIS_OFF	/* SCM not visible (VIS=0) */
  | FS_ETPU_MISC_ENABLE	/* SCM operation enabled (SCMMISEN=1) */,

  /* etpu_config.misc */
  FS_ETPU_MISC,

  /* etpu_config.ecr_a */
  FS_ETPU_ENTRY_TABLE_ADDR	/* entry table base address = shifted FS_ETPU_ENTRY_TABLE */
  | FS_ETPU_FCSS_DIV2	/* channel filter clock source using FPSCK divider */
  | FS_ETPU_CHAN_FILTER_CONT	/* channel filter mode = continuous mode (CDFC=3) */
  | FS_ETPU_ENGINE_ENABLE	/* engine is enabled (MDIS=0) */
  | FS_ETPU_FILTER_CLOCK_DIV2	/* channel filter clock = etpuclk div 2 (FPSCK=0), see also FCSS if using eTPU2 */
  | FS_ETPU_PRIORITY_PASSING_DISABLE	/* Scheduler priority passing disabled (SPPDIS=1) */,

  /* etpu_config.tbcr_a */
  FS_ETPU_ANGLE_MODE_DISABLE	/* TCR2 angle mode is disabled (AM=0) */
  | FS_ETPU_TCR2_PRESCALER(1)	/* TCR2 prescaler = 1 (TCR2P='1-1') */
  | FS_ETPU_TCR1_PRESCALER(20)	/* TCR1 prescaler = 20 (TCR1P='20-1') */
  | FS_ETPU_TCRCLK_INPUT_DIV2CLOCK	/* TCRCLK signal is filtered with filter clock = etpuclk div 2 (TCRCF=x0) */
  | FS_ETPU_TCR2CTL_DIV8	/* TCR2 source = etpuclk div 8 (TCR2CTL=4) */
  | FS_ETPU_TCRCLK_MODE_2SAMPLE	/* TCRCLK signal is filtered using two-sample mode (TCRCF=0x) */
  | FS_ETPU_TCR1CS_DIV1	/* TCR1 source bypassing divider, full system clock */
  | FS_ETPU_TCR1CTL_DIV2	/* TCR1 source = etpuclk div 2 (see also TCR1CS if using eTPU2) */,

  /* etpu_config.stacr_a */
  FS_ETPU_TCR1_STAC_SERVER	/* TCR1 resource operates as server (RSC1=1) */
  | FS_ETPU_TCR2_STAC_SERVER	/* TCR2 resource operates as server (RSC2=1) */
  | FS_ETPU_TCR1_STAC_DISABLE	/* TCR1 operation on STAC bus disabled (REN1=0) */
  | FS_ETPU_TCR2_STAC_DISABLE	/* TCR2 operation on STAC bus disabled (REN2=0) */
  | FS_ETPU_TCR1_STAC_SRVSLOT(0)	/* TCR1 resource server slot = 0 (SRV1=0) */
  | FS_ETPU_TCR2_STAC_SRVSLOT(0)	/* TCR2 resource server slot = 0 (SRV2=0) */,

  /* etpu_config.ecr_b */
  FS_ETPU_ENTRY_TABLE_ADDR	/* entry table base address = shifted FS_ETPU_ENTRY_TABLE */
  | FS_ETPU_FCSS_DIV2	/* channel filter clock source using FPSCK divider */
  | FS_ETPU_CHAN_FILTER_CONT	/* channel filter mode = continuous mode (CDFC=3) */
  | FS_ETPU_ENGINE_ENABLE	/* engine is enabled (MDIS=0) */
  | FS_ETPU_FILTER_CLOCK_DIV2	/* channel filter clock = etpuclk div 2 (FPSCK=0), see also FCSS if using eTPU2 */
  | FS_ETPU_PRIORITY_PASSING_DISABLE	/* Scheduler priority passing disabled (SPPDIS=1) */,

  /* etpu_config.tbcr_b */
  FS_ETPU_ANGLE_MODE_DISABLE	/* TCR2 angle mode is disabled (AM=0) */
  | FS_ETPU_TCR2_PRESCALER(1)	/* TCR2 prescaler = 1 (TCR2P='1-1') */
  | FS_ETPU_TCR1_PRESCALER(20)	/* TCR1 prescaler = 20 (TCR1P='20-1') */
  | FS_ETPU_TCRCLK_INPUT_DIV2CLOCK	/* TCRCLK signal is filtered with filter clock = etpuclk div 2 (TCRCF=x0) */
  | FS_ETPU_TCR2CTL_DIV8	/* TCR2 source = etpuclk div 8 (TCR2CTL=4) */
  | FS_ETPU_TCRCLK_MODE_2SAMPLE	/* TCRCLK signal is filtered using two-sample mode (TCRCF=0x) */
  | FS_ETPU_TCR1CS_DIV1	/* TCR1 source bypassing divider, full system clock */
  | FS_ETPU_TCR1CTL_DIV2	/* TCR1 source = etpuclk div 2 (see also TCR1CS if using eTPU2) */,

  /* etpu_config.stacr_b */
  FS_ETPU_TCR1_STAC_SERVER	/* TCR1 resource operates as server (RSC1=1) */
  | FS_ETPU_TCR2_STAC_SERVER	/* TCR2 resource operates as server (RSC2=1) */
  | FS_ETPU_TCR1_STAC_DISABLE	/* TCR1 operation on STAC bus disabled (REN1=0) */
  | FS_ETPU_TCR2_STAC_DISABLE	/* TCR2 operation on STAC bus disabled (REN2=0) */
  | FS_ETPU_TCR1_STAC_SRVSLOT(0)	/* TCR1 resource server slot = 0 (SRV1=0) */
  | FS_ETPU_TCR2_STAC_SRVSLOT(0)	/* TCR2 resource server slot = 0 (SRV2=0) */,

  /* etpu_config.stacr_b */
  FS_ETPU_WDM_DISABLED	/* Watchdog Mode = disabled (WDM=0) */
  | FS_ETPU_WDTR_WDCNT(0)	/* watchdog count in microcycles */,

  /* etpu_config.stacr_b */
  FS_ETPU_WDM_DISABLED	/* Watchdog Mode = disabled (WDM=0) */
  | FS_ETPU_WDTR_WDCNT(0)	/* watchdog count in microcycles */
};

/**************************************************************************
 * 
 *  FUNCTION : my_system_etpu_init
 * 
 *  PURPOSE  : Initializes the eTPU settings and channel settings, based
 *             on the user settings in the eTPU GCT:
 *
 *             1. Initialize global setting using fs_etpu_init function
 *                and the my_etpu_config structure.
 *             2. Initialize channel setting using channel function APIs 
 *                or standard eTPU routines.
 *
 *  RETURNS  : If the initialization of all channel functions passed OK, 
 *             the return value is 0. If the initialization of a channel 
 *             failed, the returned value is a number of the channel that
 *             failed to initialized increased by 1.
 *
 **************************************************************************/

int32_t my_system_etpu_init()
{
  int32_t err_code;

  /*
   *  Initialization of eTPU global settings
   */

  fs_etpu_init( my_etpu_config, (uint32_t *)etpu_code, sizeof(etpu_code),
                (uint32_t *)etpu_globals, sizeof(etpu_globals));

  /*
   *  Initialization of eTPU channel settings
   */

  /* 
   *  eTPU API Function initialization: 'PWM'
   */
  err_code = fs_etpu_pwm_init (PWM0_CHANNEL,	/* engine: A; channel: 11 */
                               FS_ETPU_PRIORITY_MIDDLE,	/* priority: Middle */
                               1000,	/* freq: 1000 */
                               5000,	/* duty: 5000 */
                               FS_ETPU_PWM_ACTIVELOW,	/* polarity: FS_ETPU_PWM_ACTIVELOW */
                               FS_ETPU_TCR1,	/* timebase: TCR1 */
                               etpu_a_tcr1_freq);	/* timebase_freq: Engine A, TCR1 frequency */
  if (err_code != 0)
  	return ((PWM0_CHANNEL) + 1);
  
  /* 
   *  eTPU API Function initialization: 'PWM'
   */
  err_code = fs_etpu_pwm_init (PWM1_CHANNEL,	/* engine: A; channel: 12 */
                               FS_ETPU_PRIORITY_MIDDLE,	/* priority: Middle */
                               1000,	/* freq: 1000 */
                               5000,	/* duty: 5000 */
                               FS_ETPU_PWM_ACTIVELOW,	/* polarity: FS_ETPU_PWM_ACTIVELOW */
                               FS_ETPU_TCR1,	/* timebase: TCR1 */
                               etpu_a_tcr1_freq);	/* timebase_freq: Engine A, TCR1 frequency */
  if (err_code != 0)
  	return ((PWM1_CHANNEL) + 1);
  
  /* 
   *  eTPU API Function initialization: 'PWM'
   */
  err_code = fs_etpu_pwm_init (PWM2_CHANNEL,	/* engine: A; channel: 13 */
                               FS_ETPU_PRIORITY_MIDDLE,	/* priority: Middle */
                               1000,	/* freq: 1000 */
                               5000,	/* duty: 5000 */
                               FS_ETPU_PWM_ACTIVELOW,	/* polarity: FS_ETPU_PWM_ACTIVELOW */
                               FS_ETPU_TCR1,	/* timebase: TCR1 */
                               etpu_a_tcr1_freq);	/* timebase_freq: Engine A, TCR1 frequency */
  if (err_code != 0)
  	return ((PWM2_CHANNEL) + 1);
  
  /* 
   *  eTPU API Function initialization: 'PWM'
   */
  err_code = fs_etpu_pwm_init (PWM3_CHANNEL,	/* engine: A; channel: 14 */
                               FS_ETPU_PRIORITY_MIDDLE,	/* priority: Middle */
                               1000,	/* freq: 1000 */
                               5000,	/* duty: 5000 */
                               FS_ETPU_PWM_ACTIVELOW,	/* polarity: FS_ETPU_PWM_ACTIVELOW */
                               FS_ETPU_TCR1,	/* timebase: TCR1 */
                               etpu_a_tcr1_freq);	/* timebase_freq: Engine A, TCR1 frequency */
  if (err_code != 0)
  	return ((PWM3_CHANNEL) + 1);
  
  /* 
   *  eTPU API Function initialization: 'PWM'
   */
  err_code = fs_etpu_pwm_init (PWM4_CHANNEL,	/* engine: A; channel: 15 */
                               FS_ETPU_PRIORITY_MIDDLE,	/* priority: Middle */
                               1000,	/* freq: 1000 */
                               5000,	/* duty: 5000 */
                               FS_ETPU_PWM_ACTIVELOW,	/* polarity: FS_ETPU_PWM_ACTIVELOW */
                               FS_ETPU_TCR1,	/* timebase: TCR1 */
                               etpu_a_tcr1_freq);	/* timebase_freq: Engine A, TCR1 frequency */
  if (err_code != 0)
  	return ((PWM4_CHANNEL) + 1);
  
  /* 
   *  eTPU API Function initialization: 'PWM'
   */
  err_code = fs_etpu_pwm_init (PWM5_CHANNEL,	/* engine: A; channel: 16 */
                               FS_ETPU_PRIORITY_MIDDLE,	/* priority: Middle */
                               1000,	/* freq: 1000 */
                               5000,	/* duty: 5000 */
                               FS_ETPU_PWM_ACTIVELOW,	/* polarity: FS_ETPU_PWM_ACTIVELOW */
                               FS_ETPU_TCR1,	/* timebase: TCR1 */
                               etpu_a_tcr1_freq);	/* timebase_freq: Engine A, TCR1 frequency */
  if (err_code != 0)
  	return ((PWM5_CHANNEL) + 1);
  
  /* 
   *  eTPU API Function initialization: 'PWM'
   */
  err_code = fs_etpu_pwm_init (PWM6_CHANNEL,	/* engine: A; channel: 17 */
                               FS_ETPU_PRIORITY_MIDDLE,	/* priority: Middle */
                               1000,	/* freq: 1000 */
                               5000,	/* duty: 5000 */
                               FS_ETPU_PWM_ACTIVELOW,	/* polarity: FS_ETPU_PWM_ACTIVELOW */
                               FS_ETPU_TCR1,	/* timebase: TCR1 */
                               etpu_a_tcr1_freq);	/* timebase_freq: Engine A, TCR1 frequency */
  if (err_code != 0)
  	return ((PWM6_CHANNEL) + 1);
  
  /* 
   *  eTPU API Function initialization: 'PWM'
   */
  err_code = fs_etpu_pwm_init (PWM7_CHANNEL,	/* engine: A; channel: 18 */
                               FS_ETPU_PRIORITY_MIDDLE,	/* priority: Middle */
                               1000,	/* freq: 1000 */
                               5000,	/* duty: 5000 */
                               FS_ETPU_PWM_ACTIVELOW,	/* polarity: FS_ETPU_PWM_ACTIVELOW */
                               FS_ETPU_TCR1,	/* timebase: TCR1 */
                               etpu_a_tcr1_freq);	/* timebase_freq: Engine A, TCR1 frequency */
  if (err_code != 0)
  	return ((PWM7_CHANNEL) + 1);
  
  

  return(0);
}

/**************************************************************************
 *
 *  FUNCTION : my_system_etpu_start
 *
 *  PURPOSE  : Initializes the eTPU settings and channel settings, based
 *             on the user settings in the eTPU GCT:
 *
 *             1. Initialize
 *                - Interrupt Enable
 *                - DMA Enable
 *                - Output Disable
 *                options of each channel.
 *             2. Run eTPU using Global Timebase Enable (GTBE) bit.
 *
 **************************************************************************/

void my_system_etpu_start()
{
  /*
   *  Initialization of Interrupt Enable, DMA Enable
   *  and Output Disable channel options
   */

  uint8_t i;
  uint32_t odis_a;
  uint32_t opol_a;
  uint32_t odis_b;
  uint32_t opol_b;

  eTPU->CIER_A.R = ETPU_CIE_A;
  eTPU->CIER_B.R = ETPU_CIE_B;

  eTPU->CDTRER_A.R = ETPU_DTRE_A;
  eTPU->CDTRER_B.R = ETPU_DTRE_B;

  odis_a = ETPU_ODIS_A;
  opol_a = ETPU_OPOL_A;
  for(i=0; i<32; i++) {
    eTPU->CHAN[i].CR.B.ODIS = odis_a & 0x00000001;
    eTPU->CHAN[i].CR.B.OPOL = opol_a & 0x00000001;
    odis_a >>= 1;
    opol_a >>= 1;
  }

  odis_b = ETPU_ODIS_B;
  opol_b = ETPU_OPOL_B;
  for(i=64; i<96; i++) {
    eTPU->CHAN[i].CR.B.ODIS = odis_b & 0x00000001;
    eTPU->CHAN[i].CR.B.OPOL = opol_b & 0x00000001;
    odis_b >>= 1;
    opol_b >>= 1;
  }

  /*
   *  Synchronous start of all TCR time bases
   */

  fs_timer_start();
}

/**************************************************************************
 *
 * Private GCT-generated data may follow this comment
 *
 **************************************************************************/
//helei:add for change fre & duty in untitled_etpu_gct.c
void my_fs_etpu_pwm_update(uint8_t channel, uint32_t freq, uint16_t duty)
{
	fs_etpu_pwm_update(channel,freq,duty,etpu_a_tcr1_freq);
}



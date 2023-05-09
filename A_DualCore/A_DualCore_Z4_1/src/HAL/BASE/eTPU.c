/*
 * eTPU.c
 *
 *  Created on: 2018Äê9ÔÂ11ÈÕ
 *      Author: helei
 */

#define __eTPU_GLOBALS__

#include "derivative.h"
#include "eTPU.h"
#include "GPIO.h"
#include "Global.h"
//#include "DIM_model.h"

void eTPU_Init(void)
{
	uint32_t error_code = 0;

	eTPU_IO_Init();

	error_code = my_system_etpu_init();
	if(!error_code)
	my_system_etpu_start();
}

void eTPU_IO_Init(void)
{
	SIUL_DigitalOutput(GPIO_PORTA+6,0x01);	//18_A
	SIUL_DigitalOutput(GPIO_PORTA+7,0x01);	//17_A
	SIUL_DigitalOutput(GPIO_PORTA+8,0x01);	//16_A  
	//if(0 == C_PMS_En)
	{
	    SIUL_DigitalOutput(GPIO_PORTA+9,0x01);	//15_A   /*or BTK solution chagne PWM4 to GPIO*/
	    SIUL_DigitalOutput(GPIO_PORTA+10,0x01);	//14_A /*for BTK solution chagne PWM5 to GPIO*/
	}
        //else
        //{
	    //SIUL_DigitalOutput(GPIO_PORTA+9,0x00);	//15_A   /*or BTK solution chagne PWM4 to GPIO*/
        //}
	SIUL_DigitalOutput(GPIO_PORTA+11,0x01);	//13_A
	SIUL_DigitalOutput(GPIO_PORTA+12,0x01);	//12_A
	SIUL_DigitalOutput(GPIO_PORTA+13,0x01);	//11_A
}


/*
using for change the frequency & duty:(function is in "untitled_etpu_gct.h")
#define PWM0_CHANNEL	ETPU_ENGINE_A_CHANNEL(11)
#define PWM1_CHANNEL	ETPU_ENGINE_A_CHANNEL(12)
#define PWM2_CHANNEL	ETPU_ENGINE_A_CHANNEL(13)
#define PWM3_CHANNEL	ETPU_ENGINE_A_CHANNEL(14)
#define PWM4_CHANNEL	ETPU_ENGINE_A_CHANNEL(15)
#define PWM5_CHANNEL	ETPU_ENGINE_A_CHANNEL(16)
#define PWM6_CHANNEL	ETPU_ENGINE_A_CHANNEL(17)
#define PWM7_CHANNEL	ETPU_ENGINE_A_CHANNEL(18)

my_fs_etpu_pwm_update(uint8_t channel, uint32_t freq, uint16_t duty);

eg: my_fs_etpu_pwm_update(PWM0_CHANNEL,1000,5000);// frequency=1000Hz, duty=50%
*/

/*
//helei:add for change fre & duty in untitled_etpu_gct.c
void my_fs_etpu_pwm_update(uint8_t channel, uint32_t freq, uint16_t duty)
{
	fs_etpu_pwm_update(channel,freq,duty,etpu_a_tcr1_freq);
}
 */

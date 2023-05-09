/*
 * GPIO.h
 *
 *  Created on: 2018Äê9ÔÂ5ÈÕ
 *      Author: helei
 */

#ifndef BASE_GPIO_H_
#define BASE_GPIO_H_

#include "typedefs.h"

#ifdef __GPIO_GLOBALS__
#define __GPIO_EXTERN__
#else
#define __GPIO_EXTERN__  extern
#endif

#define GPIO_PORTA	0		//0-13 		:: 0-13
#define GPIO_PORTB	16		//16-17		:: 0-1
#define GPIO_PORTC	32		//32-45		:: 0-13
#define GPIO_PORTD	48		//48-63		:: 0-15
#define GPIO_PORTE	64		//64		:: 0
#define GPIO_PORTF	80		//80-93		:: 0-13
#define GPIO_PORTG	96		//97-111	:: 1-15
#define GPIO_PORTH	112		//112-127	:: 0-15
#define GPIO_PORTI	128		//128-133	:: 0-5
#define GPIO_PORTJ	144		//144-159	:: 0-15
#define GPIO_PORTK	160		//160-174	:: 0-14
#define GPIO_PORTL	176		//176-177	:: 0-1
#define GPIO_PORTW	192		//192-195	:: 0-3
#define GPIO_PORTX	208		//208-223	:: 0-15
#define GPIO_PORTY	224		//224-239	:: 0-15
#define GPIO_PORTZ	240		//240-255	:: 0-15

//Pad Pull
#define 	SIUL_PULL_UP	0x00010000
#define 	SIUL_PULL_DOWN	0x00020000
#define 	SIUL_PULL_DIS	0x00000000

//Pad dir
#define  	SIUL_INPUT	0x00080000
#define 	SIUL_OUTPUT	0x02000000
#define     SIUL_BIDIR  0x02080000

//Pad function
#define 	SIUL_GPIO	0x0

//Pad Input level
#define 	SIUL_TTL	0x00100000
#define 	SIUL_CMOS	0x00300000

//Safe mode control
#define 	SIUL_SMC	0x00800000

//Pad type
#define 	SIUL_DIGITAL	0x00000000
#define 	SIUL_ANALOG 	0x00400000

//Pad slew rate
#define 	SIUL_SLEW_ENB 	0x00000000
#define 	SIUL_SLEW_DIS	0x20000000
#define 	SIUL_DRIVE_HALF 0x00000000
#define 	SIUL_DRIVE_FULL 0x10000000

//Output type
#define 	SIUL_NORMAL		0x00000000
#define 	SIUL_OPEND		0x01000000
#define 	SIUL_PUSHPULL	0x02000000
#define 	SIUL_OPENSOURCE	0x03000000

__GPIO_EXTERN__ void SIUL_DigitalInput(uint8_t pad, uint16_t pad_in, uint32_t config, uint32_t config_in);
__GPIO_EXTERN__ void SIUL_DigitalInputSimple(uint8_t pad, uint32_t config);
__GPIO_EXTERN__ void SIUL_AnalogInput(uint8_t pad, uint32_t config);
__GPIO_EXTERN__ void SIUL_DigitalInput_LINRX(uint8_t pad, uint16_t pad_in, uint32_t config, uint32_t config_in);

__GPIO_EXTERN__ void SIUL_DigitalOutput_LINTX(uint8_t pad, uint32_t config);
__GPIO_EXTERN__ void SIUL_DigitalOutput(uint8_t pad, uint32_t config);
__GPIO_EXTERN__ void SIUL_DigitalIO(uint8_t pad, uint32_t config);

__GPIO_EXTERN__ void SIUL_ToggleIO(uint8_t pad);
__GPIO_EXTERN__ void SIUL_SetPad(uint8_t pad);
__GPIO_EXTERN__ void SIUL_ClearPad(uint8_t pad);
__GPIO_EXTERN__ uint32_t SIUL_GetPadState(uint32_t pad);

__GPIO_EXTERN__ void SIUL_EnableExtInt(uint32_t maskEIRQ);
__GPIO_EXTERN__ void SIUL_EnableExtIntRisingEdge(uint32_t maskEIRQ);
__GPIO_EXTERN__ void SIUL_EnableExtIntFallingEdge(uint32_t maskEIRQ);
__GPIO_EXTERN__ uint32_t SIUL_GetExtIntFlag(uint32_t maskEIRQ);
__GPIO_EXTERN__ void SIUL_ClearExtIntFlag(uint32_t maskEIRQ);


#endif /* BASE_GPIO_H_ */

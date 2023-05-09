/*
 * FS6500.h
 *
 *  Created on: 2018��9��6��
 *      Author: helei
 */

#ifndef MODULES_FS6500_H_
#define MODULES_FS6500_H_

#include "typedefs.h"
#include "FS65xx.h"

#ifdef __FS6500_GLOBALS__
#define __FS6500_EXTERN__
#else
#define __FS6500_EXTERN__  extern
#endif


/*==================================================================================================
*   ERROR TYPES
==================================================================================================*/
#define FS65_RETURN_OK 		0x0U
#define FS65_RETURN_ERROR	0x1U

#define FS65_ERROR_OK		0x0U
#define FS65_ABIST1_FAIL	0x01
#define FS65_INIT_MSM_FAIL	0x02
#define FS65_INIT_FSSM_FAIL	0x04
#define FS65_FS1B_SHORT2HIGH	0x08
#define FS65_ABIST2_FS1B_FAIL	0x10
#define FS65_ABIST2_VAUX_FAIL	0x20
#define FS65_RFR_WD_FAIL	0x40
#define FS65_SPI_FAIL		0x80
#define FS65_LBIST_FAIL		0x90
#define FS65_STATUS_FAIL	0xA0
#define FS65_RELEASE_FS		0xB0

/****************************************************************************\
* LONG_DURATION_TIMER
\****************************************************************************/
#define	LDT_FUNCTION_1			0
#define	LDT_FUNCTION_2			1
#define	LDT_FUNCTION_3			2
#define	LDT_FUNCTION_4			3
#define	LDT_FUNCTION_5			4

#define MAX_AFTER_RUN_VALUE		65535
#define MAX_WAKE_UP_VALUE		(2^24)

/****************************************************************************\
* IO_OUT / AMUX
\****************************************************************************/
#define	AMUX_VREF				0
#define	AMUX_VSNS_WIDE			1
#define	AMUX_IO0_WIDE			2
#define	AMUX_IO5_WIDE			3
#define	AMUX_VSNS_TIGHT			4
#define	AMUX_IO0_TIGHT			5
#define	AMUX_IO5_TIGHT			6
#define	AMUX_TEMP				7

#define	VAMUX_WD_5 		5	///Divider Ratio wide input voltage range with 5V reference
#define	VAMUX_WD_33 	7	///Divider Ratio wide input voltage range with 3.3V reference
#define	VAMUX_TG_5		2	///Divider Ratio tight input voltage range with 5V reference
#define	VAMUX_TG_33 	3	///Divider Ratio tight input voltage range with 3.3V reference
#define	VAMUX_TP_CO		9.9	///Internal temp sensor coefficient in mV/�C
#define	VAMUX_TP_0		516	///Temp sensor  mux output voltage for 0 �C in mV  ->   Vamux_tp - Tj*V_amux_tp_co = (2150mV) - (165�C)*(10mV/�C) = 500 mV

/****************************************************************************\
* CAN/LIN mode
\****************************************************************************/
#define	CAN_SLEEP				0
#define	CAN_RX					1
#define	CAN_SLEEP_WU			2
#define	CAN_NORMAL				3
#define	LIN_SLEEP				0
#define	LIN_RX					1
#define	LIN_SLEEP_WU			2
#define	LIN_NORMAL				3

/****************************************************************************\
* WD_window
\****************************************************************************/
#define	WD_DISABLE			0
#define	WD_WIN_1			1
#define	WD_WIN_2			2
#define	WD_WIN_3			3
#define	WD_WIN_4			4
#define	WD_WIN_6			5
#define	WD_WIN_8			6
#define	WD_WIN_12			7
#define	WD_WIN_16			8
#define	WD_WIN_24			9
#define	WD_WIN_32			10
#define	WD_WIN_64			11
#define	WD_WIN_128			12
#define	WD_WIN_256			13
#define	WD_WIN_512			14
#define	WD_WIN_1024			15

/*==================================================================================================
*   Structures/Type defines
==================================================================================================*/
typedef struct {
    vuint8_t	INIT_VREG;
    vuint8_t	INIT_WU1;
    vuint8_t	INIT_WU2;
    vuint8_t	INIT_INT;
    vuint8_t	INIT_INH_INT;
    vuint8_t	CAN_LIN_MODE;
    vuint8_t	INIT_FS1B_TIMING;
    vuint8_t	INIT_SUPERVISOR;
    vuint8_t	INIT_FAULT;
    vuint8_t	INIT_FSSM;
    vuint8_t	INIT_SF_IMPACT;
    vuint8_t	WD_WINDOW;
    vuint8_t	WD_LFSR;
    vuint8_t	INIT_WD_CNT;
    vuint8_t	INIT_VCORE_OVUV_IMPACT;
    vuint8_t	INIT_VCCA_OVUV_IMPACT;
    vuint8_t	INIT_VAUX_OVUV_IMPACT;
} FS65_RegVal_struct;


typedef union { /* register32_struct */
	uint32_t R;
	struct {
		uint32_t				:16;
		uint32_t	bit15	:	1;
		uint32_t	bit14	:	1;
		uint32_t	bit13	:	1;
		uint32_t	bit12	:	1;
		uint32_t	bit11	:	1;
		uint32_t	bit10	:	1;
		uint32_t	bit9	:	1;
		uint32_t	bit8	:	1;
		uint32_t	bit7	:	1;
		uint32_t	bit6	:	1;
		uint32_t	bit5	:	1;
		uint32_t	bit4	:	1;
		uint32_t	bit3	:	1;
		uint32_t	bit2	:	1;
		uint32_t	bit1	:	1;
		uint32_t	bit0	:	1;
	} B;
} register32_struct;

	typedef union { ///PowerSBC general status register
	uint32_t R;
	struct {
		uint32_t						:24;
		uint32_t	SPI_G			:	1;		//SPI error
		uint32_t	WU				:	1;		//Wake-up event
		uint32_t	CAN_G			:	1;		//CAN event
		uint32_t	LIN_G			:	1;		//LIN event
		uint32_t	IO_G			:	1;		//event on I/Os
		uint32_t	Vpre_G		:	1;		//Vpre event
		uint32_t	Vcore_G		:	1;		//Vcore event
		uint32_t	Vothers_G	:	1;		//Vcca, Vaux or Vcan event
	} B;
} Status_32B_tag;



struct {
	union {
		vuint32_t R;
		struct {								///mask for ADC conversion
			vuint32_t				:24;		///reserved bits
			vuint32_t	Temp	:	1;			///die temperature sensor voltage mask
			vuint32_t	IO5T	:	1;			///IO5 voltage mask - Tight range
			vuint32_t	IO0T	:	1;			///IO0 voltage mask - Tight range
			vuint32_t	VsnsT	:	1;			///battery voltage mask - Tight range
			vuint32_t	IO5W	:	1;			///IO5 voltage mask - Wide range
			vuint32_t	IO0W	:	1;			///IO0 voltage mask - Wide range
			vuint32_t	VsnsW	:	1;			///battery voltage mask - Wide range
			vuint32_t	Vref	:	1;			///reference voltage mask
		} B;
	} scanVoltage;
	struct {											///last sampled voltages
		float	Temp;									///last sampled value of die temperature sensor
		float	IO5T;									///last sampled value of IO5 - Tight range
		float	IO0T;									///last sampled value of IO0 - Tight range
		float	VsnsT;								///last sampled value of Vsns - Tight range
		float	IO5W;									///last sampled value of IO5 - Wide range
		float	IO0W;									///last sampled value of IO0 - Wide range
		float	VsnsW;								///last sampled value of Vsns - Wide range
		float	Vref;									///last sampled value of Vref
	} actualVoltage;
} ADCstruct;

struct {
	uint32_t				writeCmd;					///last write command
	uint32_t				readCmd;					///last read command
	uint32_t				stateSPI;					///actual state of the state machine
	Status_32B_tag			statusPwSBC;			///actual PwSBC status
	uint32_t				response;					///last PwSBC response
	uint32_t				FSdelayDisabled;	///disables delay 3.5 us after a secure command, 1 - disabled, 0 - enabled
} SPIstruct;

struct {
	uint32_t	WD_answer;				///current content of the WD_answer register
	register32_struct currentLFSR;		///last LFSR state
} PITstruct;

///last received state of the registers
struct{
	INIT_VREG_Rx_32B_tag 			 	INIT_VREG;
	INIT_WU1_Rx_32B_tag  				INIT_WU1;
	INIT_WU2_Rx_32B_tag  				INIT_WU2;
	INIT_INT_Rx_32B_tag 				INIT_INT;
	INIT_INH_INT_Rx_32B_tag			INIT_INH_INT;
	LONG_DURATION_TIMER_Rx_32B_tag		LONG_DURATION_TIMER;
	HW_CONFIG_Rx_32B_tag				HW_CONFIG;
	WU_SOURCE_Rx_32B_tag 				WU_SOURCE;
	DEVICE_ID_Rx_32B_tag				DEVICE_ID;
	IO_INPUT_Rx_32B_tag				IO_INPUT;
	DIAG_VPRE_Rx_32B_tag				DIAG_VPRE;
	DIAG_VCORE_Rx_32B_tag				DIAG_VCORE;
	DIAG_VCCA_Rx_32B_tag				DIAG_VCCA;
	DIAG_VAUX_Rx_32B_tag				DIAG_VAUX;
	DIAG_VSUP_VCAN_Rx_32B_tag			DIAG_VSUP_VCAN;
	DIAG_CAN_FD_Rx_32B_tag				DIAG_CAN_FD;
	DIAG_CAN_LIN_Rx_32B_tag			DIAG_CAN_LIN;
	DIAG_SPI_Rx_32B_tag				DIAG_SPI;
	MODE_Rx_32B_tag					MODE;
	REG_MODE_Rx_32B_tag				REG_MODE;
	IO_OUT_AMUX_Rx_32B_tag				IO_OUT_AMUX;
	CAN_LIN_MODE_Rx_32B_tag			CAN_LIN_MODE;
	LDT_AFTER_RUN_1_Rx_32B_tag			LDT_AFTER_RUN_1;
	LDT_AFTER_RUN_2_Rx_32B_tag			LDT_AFTER_RUN_2;
	LDT_WAKE_UP_1_Rx_32B_tag			LDT_WAKE_UP_1;
	LDT_WAKE_UP_2_Rx_32B_tag			LDT_WAKE_UP_2;
	LDT_WAKE_UP_3_Rx_32B_tag			LDT_WAKE_UP_3;
	INIT_FS1B_TIMING_Rx_32B_tag		INIT_FS1B_TIMING;
	BIST_Rx_32B_tag					BIST;
	INIT_SUPERVISOR_Rx_32B_tag			INIT_SUPERVISOR;
	INIT_FAULT_Rx_32B_tag 				INIT_FAULT;
	INIT_FSSM_Rx_32B_tag 				INIT_FSSM;
	INIT_SF_IMPACT_Rx_32B_tag 			INIT_SF_IMPACT;
	WD_WINDOW_Rx_32B_tag 				WD_WINDOW;
	WD_LFSR_Rx_32B_tag 				WD_LFSR;
	WD_ANSWER_Rx_32B_tag 				WD_ANSWER;
	RELEASE_FSxB_Rx_32B_tag 			RELEASE_FSxB;
	SF_OUTPUT_REQUEST_Rx_32B_tag 		SF_OUTPUT_REQUEST;
	INIT_WD_CNT_Rx_32B_tag 			INIT_WD_CNT;
	DIAG_SF_IOS_Rx_32B_tag 			DIAG_SF_IOS;
	WD_COUNTER_Rx_32B_tag 				WD_COUNTER;
	DIAG_SF_ERR_Rx_32B_tag 			DIAG_SF_ERR;
	INIT_VCORE_OVUV_IMPACT_Rx_32B_tag 	INIT_VCORE_OVUV_IMPACT;
	INIT_VCCA_OVUV_IMPACT_Rx_32B_tag 	INIT_VCCA_OVUV_IMPACT;
	INIT_VAUX_OVUV_IMPACT_Rx_32B_tag 	INIT_VAUX_OVUV_IMPACT;
	DEVICE_ID_FS_Rx_32B_tag 			DEVICE_ID_FS;
}INTstruct;

///previous received state of the registers
struct{
	INIT_VREG_Rx_32B_tag 			 	INIT_VREG;
	INIT_WU1_Rx_32B_tag  				INIT_WU1;
	INIT_WU2_Rx_32B_tag  				INIT_WU2;
	INIT_INT_Rx_32B_tag 				INIT_INT;
	INIT_INH_INT_Rx_32B_tag				INIT_INH_INT;
	LONG_DURATION_TIMER_Rx_32B_tag			LONG_DURATION_TIMER;
	HW_CONFIG_Rx_32B_tag				HW_CONFIG;
	WU_SOURCE_Rx_32B_tag 				WU_SOURCE;
	DEVICE_ID_Rx_32B_tag				DEVICE_ID;
	IO_INPUT_Rx_32B_tag				IO_INPUT;
	DIAG_VPRE_Rx_32B_tag				DIAG_VPRE;
	DIAG_VCORE_Rx_32B_tag				DIAG_VCORE;
	DIAG_VCCA_Rx_32B_tag				DIAG_VCCA;
	DIAG_VAUX_Rx_32B_tag				DIAG_VAUX;
	DIAG_VSUP_VCAN_Rx_32B_tag			DIAG_VSUP_VCAN;
	DIAG_CAN_FD_Rx_32B_tag				DIAG_CAN_FD;
	DIAG_CAN_LIN_Rx_32B_tag				DIAG_CAN_LIN;
	DIAG_SPI_Rx_32B_tag				DIAG_SPI;
	MODE_Rx_32B_tag					MODE;
	REG_MODE_Rx_32B_tag				REG_MODE;
	IO_OUT_AMUX_Rx_32B_tag				IO_OUT_AMUX;
	CAN_LIN_MODE_Rx_32B_tag				CAN_LIN_MODE;
	LDT_AFTER_RUN_1_Rx_32B_tag			LDT_AFTER_RUN_1;
	LDT_AFTER_RUN_2_Rx_32B_tag			LDT_AFTER_RUN_2;
	LDT_WAKE_UP_1_Rx_32B_tag			LDT_WAKE_UP_1;
	LDT_WAKE_UP_2_Rx_32B_tag			LDT_WAKE_UP_2;
	LDT_WAKE_UP_3_Rx_32B_tag			LDT_WAKE_UP_3;
	INIT_FS1B_TIMING_Rx_32B_tag			INIT_FS1B_TIMING;
	BIST_Rx_32B_tag					BIST;
	INIT_SUPERVISOR_Rx_32B_tag			INIT_SUPERVISOR;
	INIT_FAULT_Rx_32B_tag 				INIT_FAULT;
	INIT_FSSM_Rx_32B_tag 				INIT_FSSM;
	INIT_SF_IMPACT_Rx_32B_tag 			INIT_SF_IMPACT;
	WD_WINDOW_Rx_32B_tag 				WD_WINDOW;
	WD_LFSR_Rx_32B_tag 				WD_LFSR;
	WD_ANSWER_Rx_32B_tag 				WD_ANSWER;
	RELEASE_FSxB_Rx_32B_tag 			RELEASE_FSxB;
	SF_OUTPUT_REQUEST_Rx_32B_tag 		SF_OUTPUT_REQUEST;
	INIT_WD_CNT_Rx_32B_tag 			INIT_WD_CNT;
	DIAG_SF_IOS_Rx_32B_tag 			DIAG_SS_IOS;
	WD_COUNTER_Rx_32B_tag 				WD_COUNTER;
	DIAG_SF_ERR_Rx_32B_tag 			DIAG_SF_ERR;
	INIT_VCORE_OVUV_IMPACT_Rx_32B_tag 	INIT_VCORE_OVUV_IMPACT;
	INIT_VCCA_OVUV_IMPACT_Rx_32B_tag 	INIT_VCCA_OVUV_IMPACT;
	INIT_VAUX_OVUV_IMPACT_Rx_32B_tag 	INIT_VAUX_OVUV_IMPACT;
	DEVICE_ID_FS_Rx_32B_tag 			DEVICE_ID_FS;
}INTstructPrevious;

//define for FS6500
extern uint8_t SBC_SPI;
uint8_t SBC_CATR;

#define FS6500_SPI		SBC_SPI
#define FS6500_CTAR		SBC_CATR

#define	DSPI_NB    FS6500_SPI			//defines number of DSPI module
#define	DSPI_CS	  FS6500_CTAR			//defines Chip Select
#define	DSPI_BR	1000000		//defines DSPI baud rate in b/s

#define DSPI_TRANSFER_TIMES		3	//SPIÿ��ͨ�Ŵ�����Ϊ�����ݵ���ȷ��; ���˿��Ź�ˢ��֮��
//���Ź�ˢ�±���Ϊ1����Ϊ���Ź�ˢ��Ҳ�Ǹ��ݴ˹���д�룬����Ϊ���Ź��д����ڣ��ڷǴ�����д�����ɴ��󣬶��֮��ᵼ��оƬ��λ���Ѹ���
#define FS6500_CS	GPIO_PORTK+5
#define FS6500_CS_Enable()		SIUL_ClearPad(FS6500_CS)
#define FS6500_CS_Disable()		SIUL_SetPad(FS6500_CS)

__FS6500_EXTERN__ void CheckSBC_SPIChannel(void);
//Function declaration
__FS6500_EXTERN__ void FS6500_Init(void);
__FS6500_EXTERN__ void FS6500_FeedDog(void);

//default
__FS6500_EXTERN__ uint32_t FS65_SelectLDTOperation(uint32_t);
__FS6500_EXTERN__ uint32_t FS65_SetWakeUpReg(void);
__FS6500_EXTERN__ uint32_t FS65_SetRTCReg(void);
__FS6500_EXTERN__ uint32_t FS65_SetLDTNormalMode(void);
__FS6500_EXTERN__ uint32_t FS65_SetLDTCalibrationMode(void);
__FS6500_EXTERN__ uint32_t FS65_StopLDTCounter(void);
__FS6500_EXTERN__ uint32_t FS65_StartLDTCounter(void);
__FS6500_EXTERN__ uint32_t FS65_ConfAfterRunValue(uint32_t);
__FS6500_EXTERN__ uint32_t FS65_ConfWakeUpValue(uint32_t);

__FS6500_EXTERN__ uint32_t FS65_SetLPOFFmode(void);
__FS6500_EXTERN__ uint32_t FS65_SetLPOFFmode_autoWU(void);
__FS6500_EXTERN__ uint32_t	FS65_RequestINT(void);
__FS6500_EXTERN__ uint32_t	FS65_EnableVKAM(void);
__FS6500_EXTERN__ uint32_t	FS65_DisableVKAM(void);

__FS6500_EXTERN__ uint32_t FS65_EnableVcore(void);
__FS6500_EXTERN__ uint32_t FS65_DisableVcore(void);
__FS6500_EXTERN__ uint32_t FS65_EnableVcca(void);
__FS6500_EXTERN__ uint32_t FS65_DisableVcca(void);
__FS6500_EXTERN__ uint32_t FS65_EnableVaux(void);
__FS6500_EXTERN__ uint32_t FS65_DisableVaux(void);
__FS6500_EXTERN__ uint32_t FS65_EnableVcan(void);
__FS6500_EXTERN__ uint32_t FS65_DisableVcan(void);

__FS6500_EXTERN__ uint32_t FS65_EnableOUT4(void);
__FS6500_EXTERN__ uint32_t FS65_SetOUT4(void);
__FS6500_EXTERN__ uint32_t FS65_ClearOUT4(void);
__FS6500_EXTERN__ uint32_t FS65_SwitchAMUXchannel(uint32_t);

__FS6500_EXTERN__ uint32_t FS65_SetCANmode(uint32_t);
__FS6500_EXTERN__ uint32_t FS65_Set_CAN_LIN_MODE(uint32_t);
__FS6500_EXTERN__ uint32_t FS65_SetAutoCANTxDisable(void);
__FS6500_EXTERN__ uint32_t FS65_ClearAutoCANTxDisable(void);
__FS6500_EXTERN__ uint32_t FS65_SetLINmode(uint32_t);
__FS6500_EXTERN__ uint32_t FS65_SetAutoLINTxDisable(void);
__FS6500_EXTERN__ uint32_t FS65_ClearAutoLINTxDisable(void);

__FS6500_EXTERN__ uint32_t FS65_RunABIST2_VAUX(void);
__FS6500_EXTERN__ uint32_t FS65_RunABIST2_FS1B(void);

__FS6500_EXTERN__ uint32_t FS65_ChangeWDwindow(uint32_t);
__FS6500_EXTERN__ uint32_t FS65_SendSeed(uint32_t);
__FS6500_EXTERN__ uint32_t FS65_RefreshWD(uint32_t);
__FS6500_EXTERN__ uint32_t FS65_ComputeLFSR(uint32_t);

__FS6500_EXTERN__ uint32_t	FS65_ReleaseFS0out(void);
__FS6500_EXTERN__ uint32_t FS65_ReleaseFS1out(void);
__FS6500_EXTERN__ uint32_t FS65_ReleaseFS0andFS1out(void);
__FS6500_EXTERN__ uint32_t FS65_RequestReset(void);
__FS6500_EXTERN__ uint32_t FS65_RequestFS1B(void);
__FS6500_EXTERN__ uint32_t FS65_RequestFS1B_DLY(void);
__FS6500_EXTERN__ uint32_t FS65_RequestFS0B(void);

__FS6500_EXTERN__ uint32_t FS65_Set_INIT_VREG(uint32_t);
__FS6500_EXTERN__ uint32_t FS65_Set_INIT_WU1(uint32_t);
__FS6500_EXTERN__ uint32_t FS65_Set_INIT_WU2(uint32_t);
__FS6500_EXTERN__ uint32_t FS65_Set_INIT_INT(uint32_t);
__FS6500_EXTERN__ uint32_t FS65_Set_INIT_INH_INT(uint32_t);
__FS6500_EXTERN__ uint32_t FS65_Set_INIT_FS1B_TIMING(uint32_t);
__FS6500_EXTERN__ uint32_t FS65_Set_INIT_SUPERVISOR(uint32_t);
__FS6500_EXTERN__ uint32_t FS65_Set_INIT_FAULT(uint32_t);
__FS6500_EXTERN__ uint32_t FS65_Set_INIT_FSSM(uint32_t);
__FS6500_EXTERN__ uint32_t FS65_Set_INIT_SF_IMPACT(uint32_t);
__FS6500_EXTERN__ uint32_t FS65_Set_INIT_VCORE_OVUV_IMPACT(uint32_t);
__FS6500_EXTERN__ uint32_t FS65_Set_INIT_VCCA_OVUV_IMPACT(uint32_t);
__FS6500_EXTERN__ uint32_t FS65_Set_INIT_VAUX_OVUV_IMPACT(uint32_t);
__FS6500_EXTERN__ uint32_t FS65_Set_INIT_WD_CNT(uint32_t);

//__FS6500_EXTERN__ uint32_t FS65_GetWDLFSR(void);
__FS6500_EXTERN__ uint32_t FS65_UpdateRegisterContent(uint32_t);

__FS6500_EXTERN__ uint32_t FS65_ComputeParity(uint32_t);
__FS6500_EXTERN__ uint32_t FS65_ComputeSecurityBits(uint32_t);

__FS6500_EXTERN__ uint32_t FS65_SendCmdR(uint32_t);
__FS6500_EXTERN__ uint32_t FS65_SendCmdW(uint32_t);
__FS6500_EXTERN__ uint32_t FS65_SendCmdRW(uint32_t);
__FS6500_EXTERN__ uint32_t FS65_SendSecureCmdRW(uint32_t);
__FS6500_EXTERN__ uint32_t  FS65_SendCmdRW_OneTimes(uint32_t cmd);//helei:add for WD
__FS6500_EXTERN__ uint32_t FS65_SendSecureCmdW(uint32_t);
__FS6500_EXTERN__ void FS65_ProcessSPI(void);

__FS6500_EXTERN__ float FS65_GetVoltageWide(void);
__FS6500_EXTERN__ float FS65_GetVoltage(void);
__FS6500_EXTERN__ float FS65_GetTemperature(void);

__FS6500_EXTERN__ void FS65_IsrPIT_WD(void);
//__FS6500_EXTERN__ void FS65_IsrPIT_UART(void);
__FS6500_EXTERN__ void FS65_IsrSIUL(void);
__FS6500_EXTERN__ void FS65_IsrADC(void);

__FS6500_EXTERN__ void FS65_UpdateRegisters(void);
__FS6500_EXTERN__ void CheckSBC_SPIChannel(void);

//__FS6500_EXTERN__ void FS65_IsrUART_Rx(void);
__FS6500_EXTERN__ void FS65_ErrorCallback(void);

__FS6500_EXTERN__ uint32_t FS65_Init_FSSM(void);
__FS6500_EXTERN__ uint32_t FS65_Init_MSM(void);
__FS6500_EXTERN__ uint32_t FS65_Config_NonInit(void);
__FS6500_EXTERN__ void     FS65_Init(void);
__FS6500_EXTERN__ void	FS65_GetStatus(void);



#endif /* MODULES_FS6500_H_ */

/*
 * TJA1100.h
 *
 *  Created on: 2019年1月29日
 *      Author: helei
 */

#ifndef HAL_MODULES_TJA1100_H_
#define HAL_MODULES_TJA1100_H_

#include "typedefs.h"

#ifdef __TJA1100_GLOBALS__
#define __TJA1100_EXTERN__
#else
#define __TJA1100_EXTERN__  extern
#endif

//PHY address define
#define PHY_BasicControlR	0
#define PHY_BasicStatusR	1
#define PHY_IDR1			2
#define PHY_IDR2			3
#define PHY_ExtendStatusR	15
#define PHY_IDR3			16
#define	PHY_ExtControlR		17
#define PHY_ConfigR1		18
#define PHY_ConfigR2		19
#define PHY_SymbolErrCountR	20
#define PHY_IntStatusR		21
#define PHY_IntEnableR		22
#define PHY_CommStatusR		23
#define PHY_GeneralStatusR	24
#define PHY_ExternalStatusR	25
#define PHY_LinkFailCountR	26

#define PHY_MASTER	1
#define PHY_SLAVE	2


/***************************	 PHY register	******************************/
//PHY register data structure
typedef union _PHY_BasicControlR_union_tag_ {
	uint16_t R;
	struct {
		uint16_t REST :1;
		uint16_t LOOPBACK :1;
		uint16_t SPEED_SELECT_LSB :1;
		uint16_t AUTONEG_EN :1;	//NA
		uint16_t POWER_DOWN :1;
		uint16_t ISOLATE :1;
		uint16_t RE_AUTONEG :1;	//NA
		uint16_t DUPLEX_MODE :1;
		uint16_t COLLISION_TEST :1;
		uint16_t SPEED_SELECT_MSB :1;
		uint16_t UNIDIRECT_EN :1;
		uint16_t reserved :5;
	} B;
} _PHY_BasicControlR_tag_;

typedef union _PHY_BasicStatusR_union_tag_ {
	uint16_t R;
	struct {
		uint16_t _100BASET4 :1;
		uint16_t _100BASEX_FD :1;
		uint16_t _100BASEX_HD :1;
		uint16_t _10Mbps_FD :1;
		uint16_t _10Mbps_HD :1;
		uint16_t _100BASET2_FD :1;
		uint16_t _100BASET2_HD :1;
		uint16_t EXTENDED_STATUS :1;
		uint16_t UNIDIRECT_ABILITY :1;
		uint16_t MF_PREAMBLE_SUPPRESSION :1;
		uint16_t AUTONEG_COMPLETE :1;
		uint16_t REMOTE_FAULT :1;
		uint16_t AUTONEG_ABILITY :1;
		uint16_t LINK_STATUS :1;
		uint16_t JABBER_DETECT :1;
		uint16_t EXTENDED_CAPABILITY :1;
	} B;
} _PHY_BasicStatusR_tag_;

typedef union _PHY_IDR1_union_tag_ {
	uint16_t R;
	struct {
		uint16_t PHY_ID :16;
	} B;
} _PHY_IDR1_tag_;

typedef union _PHY_IDR2_union_tag_ {
	uint16_t R;
	struct {
		uint16_t PHY_ID :6;
		uint16_t TYPE_NO :6;
		uint16_t REVISION_NO :4;
	} B;
} _PHY_IDR2_tag_;

typedef union _PHY_ExtendStatusR_union_tag_ {
	uint16_t R;
	struct {
		uint16_t _1000BASEX_FD :1;
		uint16_t _1000BASEX_HD :1;
		uint16_t _1000BASET_FD :1;
		uint16_t _1000BASET_HD :1;
		uint16_t :4;
		uint16_t _100BASET1 :1;
		uint16_t _1000BASET1 :1;
		uint16_t :6;
	} B;
} _PHY_ExtendStatusR_tag_;

typedef union _PHY_IDR3_union_tag_ {
	uint16_t R;
	struct {
		uint16_t :8;
		uint16_t VISION_NO :8;	//16进制
	} B;
} _PHY_IDR3_tag_;

typedef union _PHY_ExtControlR_union_tag_ {
	uint16_t R;
	struct {
		uint16_t LINK_CONTROL :1;
		uint16_t POWER_MODE :4;
		uint16_t SLAVE_JITTER_TEST :1;
		uint16_t TRAINING_RESTART :1;
		uint16_t TEST_MODE :3;
		uint16_t CABLE_TEST :1;
		uint16_t LOOPBACK_MODE :2;
		uint16_t CONFIG_EN :1;
		uint16_t CONFIG_INH :1;
		uint16_t WAKE_REQUEST :1;
	} B;
} _PHY_ExtControlR_tag_;

typedef union _PHY_ConfigR1_union_tag_ {
	uint16_t R;
	struct {
		uint16_t MASTER_SLAVE :1;
		uint16_t AUTO_OP :1;
		uint16_t LINK_LENGTH :1;
		uint16_t :1;
		uint16_t TX_AMPLITUDE :2;
		uint16_t MII_MODE :2;
		uint16_t MII_DRIVER :1;
		uint16_t :1;
		uint16_t LED_MODE :2;
		uint16_t LED_ENABLE :1;
		uint16_t CONFIG_WAKE :1;
		uint16_t AUTO_PWD :1;
		uint16_t :1;
	} B;
} _PHY_ConfigR1_tag_;

typedef union _PHY_ConfigR2_union_tag_ {
	uint16_t R;
	struct {
		uint16_t PHYAD :5;
		uint16_t SQI_AVERAGING :2;
		uint16_t SQI_WLIMIT :3;
		uint16_t SQI_FAILLIMIT :3;
		uint16_t JUMBO_ENABLE :1;
		uint16_t SLEEP_REQUEST_TO :2;
	} B;
} _PHY_ConfigR2_tag_;

typedef union _PHY_SymbolErrCountR_union_tag_ {
	uint16_t R;
	struct {
		uint16_t SYM_ERR_CNT :16;
	} B;
} _PHY_SymbolErrCountR_tag_;

typedef union _PHY_IntStatusR_union_tag_ {
	uint16_t R;
	struct {
		uint16_t PWON :1;
		uint16_t WAKEUP :1;
		uint16_t :2;
		uint16_t PHY_INIT_FAIL :1;
		uint16_t LINK_STATUS_FAIL :1;
		uint16_t LINK_STATUS_UP :1;
		uint16_t SYM_ERR :1;
		uint16_t TRAINING_FAILED :1;
		uint16_t SQI_WARNING :1;
		uint16_t CONTROL_ERR :1;
		uint16_t :1;
		uint16_t UV_ERR :1;
		uint16_t UV_RECOVERY :1;
		uint16_t TEMP_ERR :1;
		uint16_t SLEEP_ABORT :1;
	} B;
} _PHY_IntStatusR_tag_;

typedef union _PHY_IntEnableR_union_tag_ {
	uint16_t R;
	struct {
		uint16_t PWON_EN :1;
		uint16_t WAKEUP_EN :1;
		uint16_t :2;
		uint16_t PHY_INIT_FAIL_EN :1;
		uint16_t LINK_STATUS_FAIL_EN :1;
		uint16_t LINK_STATUS_UP_EN :1;
		uint16_t SYM_ERR_EN :1;
		uint16_t TRAINING_FAILED_EN :1;
		uint16_t SQI_WARNING_EN :1;
		uint16_t CONTROL_ERR_EN :1;
		uint16_t :1;
		uint16_t UV_ERR_EN :1;
		uint16_t UV_RECOVERY_EN :1;
		uint16_t TEMP_ERR_EN :1;
		uint16_t SLEEP_ABORT_EN :1;
	} B;
} _PHY_IntEnableR_tag_;

typedef union _PHY_CommStatusR_union_tag_ {
	uint16_t R;
	struct {
		uint16_t LINK_UP :1;
		uint16_t TX_MODE :2;
		uint16_t LOC_RCVR_STATUS :1;
		uint16_t REM_RCVR_STATUS :1;
		uint16_t SCR_LOCKED :1;
		uint16_t SSD_ERR :1;
		uint16_t ESD_ERR :1;
		uint16_t SQI :3;
		uint16_t RECEIVE_ERR :1;
		uint16_t TRANSMIT_ERR :1;
		uint16_t PHY_STATE :3;
	} B;
} _PHY_CommStatusR_tag_;

typedef union _PHY_GeneralStatusR_union_tag_ {
	uint16_t R;
	struct {
		uint16_t INT_STATUS :1;
		uint16_t PLL_LOCKED :1;
		uint16_t LOCAL_WU :1;
		uint16_t REMOTE_WU :1;
		uint16_t DATA_DET_WU :1;
		uint16_t EN_STATUS :1;
		uint16_t RESET_STATUS :1;
		uint16_t :1;
		uint16_t LINKFAIL_CNT :5;
		uint16_t :3;
	} B;
} _PHY_GeneralStatusR_tag_;

typedef union _PHY_ExternalStatusR_union_tag_ {
	uint16_t R;
	struct {
		uint16_t :1;
		uint16_t UV_VDDA_3V3 :1;
		uint16_t UV_VDDD_1V8 :1;
		uint16_t UV_VDDA_1V8 :1;
		uint16_t UV_VDDIO :1;
		uint16_t TEMP_HIGH :1;
		uint16_t TEMP_WARN :1;
		uint16_t SHORT_DETECT :1;
		uint16_t OPEN_DETECT :1;
		uint16_t POLARITY_DETECT :1;
		uint16_t INTERLEAVE_DETECT :1;
		uint16_t :5;
	} B;
} _PHY_ExternalStatusR_tag_;

typedef union _PHY_LinkFailCountR_union_tag_ {
	uint16_t R;
	struct {
		uint16_t LOC_RCVR_CNT :8;
		uint16_t REM_RCVR_CNT :8;
	} B;
} _PHY_LinkFailCountR_tag_;

typedef struct _PHY_TJA1100_struct_tag_ {
	_PHY_BasicControlR_tag_ BasicControlR;
	_PHY_BasicStatusR_tag_ BasicStatusR;
	_PHY_IDR1_tag_ IDR1;
	_PHY_IDR2_tag_ IDR2;
	_PHY_ExtendStatusR_tag_ ExtendStatusR;
	_PHY_IDR3_tag_ IDR3;
	_PHY_ExtControlR_tag_ ExtControlR;
	_PHY_ConfigR1_tag_ ConfigR1;
	_PHY_ConfigR2_tag_ ConfigR2;
	_PHY_SymbolErrCountR_tag_ SymbolErrCountR;
	_PHY_IntStatusR_tag_ IntStatusR;
	_PHY_IntEnableR_tag_ IntEnableR;
	_PHY_CommStatusR_tag_ CommStatusR;
	_PHY_GeneralStatusR_tag_ GeneralStatusR;
	_PHY_ExternalStatusR_tag_ ExternalStatusR;
	_PHY_LinkFailCountR_tag_ LinkFailCountR;
} _PHY_TJA1100_tag_;


//value
__TJA1100_EXTERN__ _PHY_TJA1100_tag_ PHY_Register;

__TJA1100_EXTERN__ void PHY_ReadAllRegister(void);
__TJA1100_EXTERN__ uint16_t PHY_isConnected (void);
__TJA1100_EXTERN__ uint16_t PHY_Init (void);
__TJA1100_EXTERN__ uint16_t PHY_Config_Master(uint8_t config);
__TJA1100_EXTERN__ uint16_t PHY_Get_LinkStatus(uint8_t * linkStatus);



#endif /* HAL_MODULES_TJA1100_H_ */

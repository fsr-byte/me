#ifndef UDS_TP_H_
#define UDS_TP_H_
/*
 *

 *
 */

/*! @file Uds_tp.h
    @brief  brief description on this header file
    @details details description on this header file

*/
#ifdef MASTER_UDS_TP_
	#define UDS_TP_EXTERNAL_
#else
	#define UDS_TP_EXTERNAL_  extern
#endif


/* =====================Includes====================================*/
#include "derivative.h"      /* derivative-specific definitions */
#include "CAN_Operation.h"
#include "Global.h"

/* =================  Global Constant Declarations =========================*/
#define MAX_CAN_MSG_SIZE 	8
#define MAX_SF_LEN			7	/*maximum Single Frame data length*/
#define MAX_CF_LEN			7	/*Consecutive Single Frame data length*/
#define MAX_FF_LEN                 6   /*there is 6 byes data in First frame */
#define Tp_RX_STMIN 		10 	/*STmin sent out in FC by ECU*/
#define Tp_TICK				5	/*the TP layer cyclic task is  called (every 5 ms) in Timer interrupt*/
#define MAX_UDS_REQ_LEN      256   /*to save RAM, request buffer is only 256  bytes*/
#define MAX_UDS_RSP_LEN  	1024

#define UDS_PHY_REQ_ID 		0x7E0
#define UDS_RSP_ID 			0x7E8
#define UDS_PADDING_BYTE 	0x00
/* =================  Global Type Declarations =========================*/

typedef enum tpFrame
{
	UDS_SF = 0, 		/*Single Frame*/
	UDS_FF = 1, 		/*First Frame*/
	UDS_CF = 2, 		/*Consecutive Frame*/
	UDS_FC = 3 		/*flow control Frame*/
}tpFrameType;

/*Flow Status in ISO15765 flow Control frame*/
typedef enum tpFlowStatus
{
	UDS_CTS = 0, 		/*continue to send*/
	UDS_WT = 1, 		/*wait */
	UDS_OVFLW = 2 		/*over flow*/
}tpFlowStatusType;

typedef enum udsTpState_
{
	UDS_TP_IDLE = 0,		/*TP layer idle, wait for new request*/
	UDS_TP_WAIT_NF = 1,		/*wait for Rx for consecutive frame*/
	UDS_TP_WAIT_FC = 2,		/*wait for Rx flow control frame*/
	UDS_TP_SEND_CF = 3		/*sending consecutive frame*/
}udsTpStateType;

/*UDS Negative Response code: ISO-14229 Table A.1 ¡ª Definition of responseCode values*/
typedef enum udsNRC
{
	NRC_PR = 0x00,			/*positiveResponse*/
	NRC_NRSP = 0x01,		/*No Response Send out use ISO14229 reserved NRC, inform TP layer that no response to be sent*/
	NRC_WTPFT = 0x02,		/*Wrong TP frame type use ISO14229 reserved NRC, it means ISO15765 frame type is wrong*/
	NRC_GR = 0x10,			/*general reject*/
	NRC_SNS = 0x11,			/*service not supported*/
	NRC_SFNS = 0x12,		/*subFunctionNotSupported*/
	NRC_IMLOIF = 0x13,		/*incorrectMessageLengthOrInvalidFormat */
	NRC_RTL = 0x14, 			/*responseTooLong out of TP layer buffer*/
	NRC_BRR = 0x21,			/*busyRepeatRequest */
	NRC_CNC = 0x22,			/*conditionsNotCorrect  */
	NRC_RSE = 0x24,			/*requestSequenceError  */
	NRC_ROOR = 0x31,		/*requestOutOfRange  */
	NRC_SAD = 0x33,			/*securityAccessDenied  */
	NRC_IK = 0x35,			/*invalidKey  */
	NRC_ENOA = 0x36,		/*exceedNumberOfAttempts  */
	NRC_RTDNE = 0x37,		/*requiredTimeDelayNotExpired  */
	NRC_GPF  = 0x72,              /*generalProgrammingFailure*/
	NRC_RCRRP = 0x78,		/*requestCorrectlyReceived-ResponsePending*/
	NRC_SNSIAS = 0x7F          /*serviceNotSupportedInActiveSession*/
}udsNRCType;

/* =================  Global Variable Declarations =========================*/
UDS_TP_EXTERNAL_ uint8_t tpUdsCANRecv[MAX_CAN_MSG_SIZE];
UDS_TP_EXTERNAL_ uint8_t tpRspBuf[MAX_UDS_RSP_LEN];
UDS_TP_EXTERNAL_ uint16_t tpRspLen;					/*total length of the response to be sent*/
UDS_TP_EXTERNAL_ uint8_t tpReqBuf[MAX_UDS_REQ_LEN];
UDS_TP_EXTERNAL_ uint16_t tpReqLen;					/*total length while receving multi-frame request*/
UDS_TP_EXTERNAL_  boolean  phyReqFlag;        /*the request come from physical addressing*/

/* =================  Global Function Declarations =========================*/
void udsTpInit(void);
void udsTpTask(void);
void udsTpRecv(boolean PhyIdFlag, uint8_t tpRecvLen);
void udsTpSend(udsNRCType	 NRC);

#endif /* UDS_TP_H_ */


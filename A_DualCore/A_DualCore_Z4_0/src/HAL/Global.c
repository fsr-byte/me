/*
 * Global.c
 *
 *  Created on: 2018年10月8日
 *      Author: helei
 */

#define __GLOBAL_GLOBALS__

#include "derivative.h"
#include "Global.h"
#include "BASE_Global.h"
#include "CAN_Operation.h"
#include "uds_service.h"

boolean udsHWTestingModeStatus = 0;
boolean bool_udsAgingTestStart_flag = 0;
boolean bool_udsAgingTestError_flag = 0;
/*CCP area 需要同Core1定义的顺序完全相同！！！*/
CAL_BSW unsigned char Vehicle_Type = 1;
CAL_BSW unsigned char S11_Mark = 1;
CAL_BSW unsigned char K11_Mark = 2;
CAL_BSW unsigned char S11P01_Mark = 4;
CAL_BSW unsigned char A11_Mark = 5;
CAL_BSW unsigned char K11P01_Mark = 6;
CAL_BSW unsigned char S11P03_Mark = 7;
CAL_BSW unsigned char S21_Mark = 8;
CAL_BSW unsigned char K11E01R_Mark = 9;
CAL_BSW unsigned char S11P05_Mark = 12;
CAL_BSW unsigned char K11P06_Mark = 13;
CAL_BSW unsigned char Authentication_flg = 0;
CAL_BSW unsigned char KACMiddleVoltage_flg = 0;
CAL_BSW uint8_t MaxDaqRetryTime = 2; /*after DAQ transmission tried for 2 ms, give up*/
CAL_BSW unsigned char KHALI_DisRelayWhenCanOff = 1;
CAL_BSW unsigned char KUDS_TestFeature = 1;
CAL_BSW unsigned char KUDS_SupportOldBoot = 0;
CAL_BSW unsigned short KUDS_ABSStopedSpeed = VEHICLE_STOP_LIMIT;
CAL_BSW unsigned short KUDS_MotorStopedSpeed = MOTOR_STOP_LIMIT;
CAL_BSW boolean KUDS_IOCtrlEnable = 1; /*1: IO 控制功能打开*/
CAL_BSW uint32_t PeriodSendInvalidMsg = 850; /*CR 1082:  the initialize time is 100ms, the period that send invalid CAN message is 900, set the time to 850 */
CAL_BSW unsigned char KNVM_SelfClrCycle = 0; /*CR1088: DTC self clear operation cycle, 0: disable self clear feature*/
CAL_BSW uint16_t MaxAppDataLoadTime = 800; /*application data loading must be finished in 1800ms*/
CAL_BSW uint16_t MaxAppDataSaveTime = 2000; /*application data saving must be finished in 2000ms (erase two DFLASH nees about 800ms , save 10 page EEPROM costs about 400ms )*/
CAL_BSW uint16_t NEDC_Milg_km = 300U;
CAL_BSW uint16_t Eco_egyCnse_1km_c = 111U;
CAL_BSW uint8_t zone_km_c = 20U;

/*blue tooth relevant calibration parameters*/
//CAL_BSW unsigned char KHALI_VCUActAsPeps = 0;    /*1: VCU acting as PEPS to sample SSB, control the IGN1/IGN2 relay*/
/*timeout values based on ESCL spec*/
CAL_BSW uint16_t KHALI_Escl_InitDelay = 150;
CAL_BSW uint16_t KHALI_Escl_TimeOut_1 = 180;
CAL_BSW uint16_t KHALI_Escl_TimeOut_2 = 1600;
CAL_BSW uint16_t KHALI_Escl_TimeOut_31 = 1500;
CAL_BSW uint16_t KHALI_Escl_TimeOut_32 = 1500;
CAL_BSW uint16_t KHALI_Escl_TimeOut_33 = 1500;
CAL_BSW uint16_t KHALI_Escl_TimeOut_4 = 1200;
CAL_BSW uint16_t KHALI_Escl_TimeOut_5 = 1600;
CAL_BSW uint32_t KHALI_Escl_ForceEraseDuration = 600000;    /*force eracing ESCL, maximum 10 minutes*/
CAL_BSW uint16_t KHALI_Escl_ProgKeyInterval = 50;  /*the interval of the two program key commands*/
CAL_BSW unsigned char KHALI_Escl_TasckStep = 2;            /*how many task cyles should ESCl be called, each cycle is 10ms */
//CAL_BSW uint8_t KHALI_Escl_Installed = 0;          /*0: ESCL not installed, 1: ESCL installed*/

/*blue tooth relevant calibration parameters*/


CORE0_INIT uint8_t FlagOfInitRam = FLAGOFINITRAM_VALUE; //需要设置为不为0的值

uint8_t HW_udsDiag_flag = 0;
volatile uint32_t SystemTickMs;

uint8_t tpUdsCANRecv[8];
uint8_t UdsRecvChannel;

//DualCore Communication
uint8_t RestartCore0 = 0;
uint32_t ErrTimesInSI0 = 0;
CORE0_INIT uint32_t InfoTimesRestart = 0; //重启次数

//NVM
uint8_t DtcToCAN[DTC_NUM_IN_RAM];

//UDS input from Core 1
udsIOCTRLDIDType IOCtrlDidTbl[3]; /*task.c 使用 */
///boolean DisRecordDTC; /*DHP 使用，表示是否关闭诊断 */
unsigned char Bios_Sw_Input[SW_NUM] = { 0 };	//数字量获取
unsigned int ADC_OutBuff[ADC_NUM] = { 0 };		//ADC获取

unsigned char Bios_LS_Output[LS_NUM] = { 0 };	//低驱输出
unsigned char Bios_HS_Output[HS_NUM] = { 0 };	//高驱输出

_BTS_data_ BTS5180_data[2]; /*core 1 to core 0*/
_BTS_data_ BTS5200_data[4];
/* 以太网下线检测使用 */
uint8_t EnetTestMaster = 0;

/*频率量采集变量*/
float hIOP_CollisionSw_Hz = 8;
float hIOP_CollisionSw_Duty = 83;
float hIOP_WaterPwm_Hz = 500;
float hIOP_WaterPwm_Duty = 50;
float hIOP_HVInterlock_Hz = 20;
float hIOP_Fin4_Hz = 500;
uint8_t hIOP_HVInterlock_Duty = 50;
uint8_t hIOP_VacuumPumpIn_Duty = 50;

_NCV7513B_SO_data_ NCV7513B_SO_data;
_NCV7719_INOUTPUT_ NCV7719_data; /*for UDS its input from Core1, for NVM it is output*/
_NCV7240B_SO_data_ NCV7240B_SO_data;
IO_INPUT_Rx_32B_tag FS6500_IO_Input;
HWTest_PwmCtrlType udsHWTestPwmCtrl[PWM_NUM] = { { 0 } };

/*for communication test*/
_CAN_flag_ CanComTest = DontSending;
uint8_t lintest = 0;
uint8_t SocResiMilgNvMCorrect = 0; /*CR 1082*//* bug 1451*/

/*temporary solution before DHP moved to Core 0, clear DTC information if $14 command received from Core 0*/
uint8_t currClrDTCCmdFromCore0 = 0;

uint8_t X11_Mark = 3;
uint8_t bswWakeSrc = WAKEUPSRC_UNKNOWN;

//----add for DHP when compile .. useless in VCU 2.0
uint8_t gbInvalidWriteToCalArea=0;
uint8_t gbWhoWriteCalArea=0;
boolean APPData_Invalid_DFlash_1_2=0;
boolean APPData_Invalid_DFlash_3=0;
boolean APPData_Invalid_DFlash_4=0;
boolean APPData_Invalid_EEPROM_1_2=0;
boolean APPData_Invalid_EEPROM_3=0;
boolean APPData_Invalid_EEPROM_4=0;
boolean DIDData_Invalid_DFlash = 0;
boolean DIDData_Invalid_EEPROM = 0;

uint8_t  AuthFailedData[AUTHFALIED_DATA_SIZE] = {0};   /*CR 1519 bug 1665*/

//----add for DHP during aging test .. useless in VCU 1.0
uint16_t LSChip7240BFaultStatus = 0;
uint8_t HSChip5180BFaultStatus = 0;
/**************************BTK  and ESCL  ***************************************************/
BTK_EsclReqType gblEsclOperReq = BTK_ESCL_NOCMD;
BTK_EsclRsltType gblEsclRslt = BTK_ESCL_SUCCESS;
uint32_t newEsclKey = 0x12345678;
uint32_t currEsclKey = 0x12345678; 
boolean IGN1_FeedVoltCorrect = TRUE;    /*IGN1 relay feedback voltage correct*/
boolean IGN2_FeedVoltCorrect = TRUE;    /*IGN1 relay feedback voltage correct*/
boolean SSB_SyncCorrect = TRUE;   /*FALSE: SSB two switches not synchronized; TRUE: two switches are synchronized*/
uint8_t EsclLinCommFailed = 0;
uint8_t EsclStatus  = 0;
uint8_t EsclErrorCode = 0; //

boolean gblUdsECUUpgrade=FALSE;                    /*ECU is going to be updated, VCU should control to HV Power-off */
boolean gblUdsKeepPresent = FALSE;      /*UDS ECU requests to keep present */
uint8_t gblNVMStateMachineSts = 0;

//end

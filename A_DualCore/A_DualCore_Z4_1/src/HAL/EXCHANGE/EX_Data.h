/*
 * EX_Data.h
 *
 *  Created on: 2019年6月24日
 *      Author: helei
 */

#ifndef HAL_EXCHANGE_EX_DATA_H_
#define HAL_EXCHANGE_EX_DATA_H_

#include "typedefs.h"

//#include "PMM_Module.h"
//#include "DHP_model.h"
#include "Global.h"
#include "NCV7513B.h"
#include "NCV7240B.h"
#include "NCV7719.h"
#include "FS65xx.h"
#include "BTS.h"
#include "NVM.h"
#include "BTK_ESCL.h"
#ifdef __EX_DATA_GLOBALS__
#define __EX_DATA_EXTERN__
#else
#define __EX_DATA_EXTERN__  extern
#endif

typedef enum {
  ReadComplete = 0,
  WriteComplete = 1
}_Exchange_Status_;

/*-----------NVM UDS输入，从Core1到Core0 -----------------*/
//NVM
//extern B_DHP_model_T DHP_model_B;
extern APPDID_outSnapshots appDID_outSnapshot;
extern uint8_t VHALI_TBOX_TimeYear;
extern uint8_t VHALI_TBOX_TimeMonth;
extern uint8_t VHALI_TBOX_TimeDate;
extern uint8_t VHALI_TBOX_TimeHour;
extern uint8_t VHALI_TBOX_TimeMinute;
extern uint8_t VHALI_TBOX_TimeSecond;
extern uint16_t VHALI_BMSErrNum;
extern uint8_t VHALI_MCUErrNum;
//extern PMM PMM_output;//需要其中的两个量：WakeSrcValid 、VPMM_InternalSleepActive_flg
//UDS
extern uint16_t VHALI_ABS_VehicleSpeed;
//extern uint16_t VHALI_MCUElecMotSpd;

/*-----------NVM UDS输出，从Core0到Core1 -----------------*/
//NVM
__EX_DATA_EXTERN__ uint8_t gbCalDataCorrect;
__EX_DATA_EXTERN__ uint8_t gbDidDataCorrect;
__EX_DATA_EXTERN__ uint8_t seriousHistFaultFlag;
__EX_DATA_EXTERN__ uint8_t HistDataCheckFaliedFlag;
__EX_DATA_EXTERN__ uint8_t AppDataCheckFaliedFlag;
__EX_DATA_EXTERN__ uint8_t DtcToCAN[DTC_NUM_IN_RAM];
__EX_DATA_EXTERN__ NvMLoadSaveType NvMAppDataSaveLoadFlag;
//UDS
__EX_DATA_EXTERN__ udsIOCTRLDIDType IOCtrlDidTbl[3];  /*task.c 使用 */
///__EX_DATA_EXTERN__ boolean DisRecordDTC;           /*DHP 使用，表示是否关闭诊断 */
__EX_DATA_EXTERN__ UDS_CtrlType udsSrv28CtrlType;   /*system.c 用来控制CAN 发送 */
__EX_DATA_EXTERN__ UDS_CommType udsSrv28ComType;    /*system.c 用来控制CAN 发送 */
__EX_DATA_EXTERN__ uint8_t VCU_CCP_Valid;


typedef struct _Exchange_C1T0_struct_tag_{
  _Exchange_Status_ QAflag;//读写标志位
  /*------------NVM-------------*/
  //B_DHP_model_T DHP_model_B;
  APPDID_outSnapshots appDID_outSnapshot;
  uint8_t VHALI_TBOX_TimeYear;
  uint8_t VHALI_TBOX_TimeMonth;
  uint8_t VHALI_TBOX_TimeDate;
  uint8_t VHALI_TBOX_TimeHour;
  uint8_t VHALI_TBOX_TimeMinute;
  uint8_t VHALI_TBOX_TimeSecond;
  uint16_t VHALI_BMSErrNum;
  uint8_t VHALI_MCUErrNum;
  //PMM PMM_output;//需要其中的两个量：WakeSrcValid 、VPMM_InternalSleepActive_flg
  uint8_t WakeSrcValid;
  uint8_t VPMM_InternalSleepActive_flg;
  uint16_t VHALO_MotTqReq;
  /*------------UDS-------------*/
  uint16_t VHALI_ABS_VehicleSpeed;
  int16_t VINP_MCUElecMotSpd_rpm;
  uint8_t Bios_Sw_Input[SW_NUM];  //数字量获取
  unsigned int  ADC_OutBuff[ADC_NUM];  //ADC result 
  _BTS_data_ BTS5180_data[2];    /*core 1 to core 0*/
  _BTS_data_ BTS5200_data[4];
  /*频率信号输入*/
  float hIOP_CollisionSw_Hz;
  float hIOP_CollisionSw_Duty;
  float hIOP_WaterPwm_Hz;
  float hIOP_WaterPwm_Duty;
  float hIOP_HVInterlock_Hz;
  uint32_t hIOP_HVInterlock_PulseTime_us;
  uint32_t hIOP_HVInterlock_PeriodTime_us; 
  float hIOP_Fin4_Hz  ;
  uint8_t hIOP_HVInterlock_Duty ;
  uint8_t hIOP_VacuumPumpIn_Duty ;  

  _NCV7513B_SO_data_ NCV7513B_SO_data;
  _NCV7719_INOUTPUT_ NCV7719_data;                      /*for UDS its input from Core1, for NVM it is output*/  
  _NCV7240B_SO_data_ NCV7240B_SO_data;  
  IO_INPUT_Rx_32B_tag	FS6500_IO_Input;      /*FS6500 IO from Core 1*/    
  //uint8_t  IGBTFaultFromMCU;
  uint8_t bswWakeSrc;     /*wakeup source judged by Core 1*/
  /*------------DHP-------------*/
  //Config----
  uint8_t C_CS_En;
  uint8_t C_SRS_En;
  uint8_t C_EAC_En;
  uint8_t C_ECC_En;
  uint8_t C_EHU_En;
  uint8_t C_EPS_En;
  uint8_t C_ICM_En;
  uint8_t C_TMS_En;
  uint8_t C_TMS_Internal;
  uint8_t C_CC_En;
  uint8_t C_Booster_En;
  uint8_t C_VacuumPump_En;
//  boolean_T C_YK19_En ;
  uint8_t C_ESCL_En;
  uint8_t C_PMS_En;
  //NM-----
  uint8_t VNM_TxLiphome_flg;
  uint8_t VNM_TxSleepInd_flg;
  //TQM----
  uint8_t b1_M_TQM_TqArbitration;
  float TQM_VehSpd;
  uint8_t TQM_EPBAppliedReq;
  //INP----
  uint16_t VINP_BMSErrNum;
  uint8_t VINP_IgnitionOn_flg;
  float VINP_MCUIGBTT_C;
  float VINP_MCUElecMotT_C;
  float VINP_MCUT_C;
  uint8_t VINP_DCDCFltRnk_enum;
  uint8_t VINP_OBCFltRnk_enum;
  uint8_t VINP_MCUFltRnk_enum;
  float VINP_MCUDcU_V;
  float VINP_MCUDcCrrt_A;
  uint8_t MCUHWCurrOverErr;
  uint8_t VINP_MCUPwrModErr_flg;
  uint8_t VINP_BMSFltRnk_enum;
  uint8_t VINP_BMSOperMod_enum;
  float VINP_BMSBattU_V;
  float VINP_BMSCellUMax;
  float VINP_BMSCellUMin;
  uint16_t VINP_BMSMaxBattT;
  uint8_t VINP_BMSChrgMod_enum;
  uint8_t VINP_MCUErrNum;
  uint8_t VINP_MCUOperMdl_enum;
  uint8_t VINP_ABS_AbsFlgFlt;
  uint8_t VINP_EPS_EpasFailed;
  uint8_t VINP_ABS_EbdFlgFlt;
  uint8_t VINP_EPB_Status;
  uint8_t VINP_ABS_VehicleSpeedValid_flg;
  uint8_t VINP_MotTqRealValid_flg;
  uint8_t VINP_MCUElecMotSpdValid_flg;
  float VINP_BMSBattUOverU;
  float VINP_BMSBattUUnderU;
  float VINP_BMSCellUMaxOverU;
  float VINP_BMSCellUMinUnderU;
  int16_t VINP_BMSMaxBattTOverT;
  uint8_t VINP_ESP_ESPFailStatus;
  uint8_t VINP_SlowChargeAwakeActive_flg;
  uint8_t VINP_FastChargeAwakeActiveIn_flg;
  uint8_t VINP_ICM_VehSpdChkInvalidFlt_flg;
  uint8_t VINP_PEPS_PDU;
  uint8_t VINP_GearOut_enum;
  float VINP_AccelPedal_per;
  uint8_t VINP_BrkLightSwitchActive_flg;
  //PEPS-----
  uint8_t VPEPS_Result_enum;
  //SPDCtl---
  uint8_t u1_M_SPDCtl_CRUISEDiagError_enum;
  //ENM----
  uint8_t ENM_BMSMaxDchaPwrFlt_flg;
  //CHRG----
  uint8_t VCHRG_ChrgStsLampReq_flg;
  uint8_t VCHRG_VCUChrgAllwd_flg;
  //TMM-----
  uint8_t TMM_WaterPumpEnReq_flg;
  uint8_t TMM_VCUChrgReqLimFac_enum;
  uint8_t TMM_InvalidBattReq;
  //PMM-----
  uint8_t VPMM_PTReady_flg;
  uint8_t VPMM_UpToHVMode_flg;
  uint8_t VPMM_LVEna;
  uint8_t VPMM_LVUpTimeout_flg;
  uint8_t VPMM_HVUpTimeout_flg;
  uint8_t VPMM_HVActiveTimeout_flg;
  uint8_t VPMM_HVDownTimeout_flg;
  uint8_t VPMM_MCUDischargeTimeout_flg;
  uint8_t VPMM_LVUpBMSPwrUpAllwTimeout_flg;
  uint8_t VPMM_LVUpBMSTimeout_flg;
  uint8_t VPMM_LVUpDCDCTimeout_flg;
  uint8_t VPMM_LVUpMCUTimeout_flg;
  uint8_t VPMM_MCUHVActiveTimeout_flg;
  uint8_t VPMM_HVDCDCActiveTimeout_flg;
  uint8_t VPMM_BMSModError;
  uint8_t VPMM_MCUModError;
  uint8_t VPMM_DCDCModError;
  uint8_t VPMM_MCUExitTqlTimeout_flg;
  uint8_t VPMM_DCDCStopworkTimeout_flg;
  uint8_t VPMM_VehSts_enum;
  //HALI-----
//  HALI_Hardwire Hardwire_Inputs;//硬线输入集合都需要拷贝到这里
  uint8_t VHALI_SRS_CrashOutputStatus;
  uint8_t VHALI_BMSChrgSts;
  uint16_t VHALI_MotTqReal;
  uint16_t VHALI_MCUIGBTT;
  uint16_t VHALI_MCUElecMotT;
  uint16_t VHALI_MCUElecMotSpd;
  uint16_t VHALI_BMSSOC;
  uint16_t VHALI_BMSBattU;
  uint16_t VHALI_BMSBattI;
  uint8_t VHALI_BMSAvrgBattT;
  uint8_t VHALI_DCDCT;
  uint32_t VHALI_ClstrOdo;
  uint8_t VHALI_TBOX_TimeYear__1;
  uint8_t VHALI_TBOX_TimeMonth__1;
  uint8_t VHALI_TBOX_TimeDate__1;
  uint8_t VHALI_TBOX_TimeHour__1;
  uint8_t VHALI_TBOX_TimeMinute__1;
  uint8_t VHALI_TBOX_TimeSecond__1;
  uint16_t VHALI_BMSErrNum__1;
  uint8_t VHALI_MCUErrNum__1;
  uint8_t VHALI_EPB_Status;
  //BSW------
  uint32_t VHALI_ICM_234_MsgTicks;
  uint32_t VHALI_EHU_345_MsgTicks;
  uint32_t hIOP_LSFaultCode_enum_POR;
  uint32_t VHALI_EAC_34A_MsgTicks;
  uint32_t VHALI_XBS_241_MsgTicks;
  uint32_t VHALI_ICM_235_MsgTicks;
  uint8_t hIOP_FastChargeAwake_flg;
  uint8_t hIOP_SlowChargeAwake_flg;
  uint8_t hIOP_MainRelay_flg;
  uint8_t hIOP_GearSwitch1_flg;
  uint8_t hIOP_GearSwitch2_flg;
  uint8_t hIOP_GearSwitch3_flg;
  uint8_t hIOP_GearSwitch4_flg;
  uint8_t hIOP_BrkLightSwitch1_flg;
  uint8_t hIOP_BrkLightSwitch2_flg;
  uint8_t hIOP_LSpdFan_flg;
  uint8_t hIOP_HSpdFan_flg;
  uint8_t hIOP_WaterPump_flg;
  uint8_t VHALI_HWVersion;
  //uint8_t IGBTFaultFromMCU;//repid
  //uint8_t seriousHistFaultFlag;//++
  uint8_t hIOP_HSFaultCode_enum_POR;
  //uint8_t gbDidDataCorrect;//Core0 Local using from NVM
  //uint8_t gbCalDataCorrect;//Core0 Local using from NVM
  uint8_t CruiseKeyFaultCode;
///  uint8_t DisRecordDTC; //Core0 Local using from UDS
  uint8_t VHALO_MCURelayActive_flg;//++
  uint8_t PTBusOffConfirmedFlag;
  //uint8_t HistDataCheckFaliedFlag;//Core0 Local using from NVM
  uint8_t VCHRG_ChrgStopLockError_flg;
  uint8_t VCHRG_OBCWakeupTimeout_flg;
  //uint8_t AppDataCheckFaliedFlag;//Core0 Local using from NVM
  uint8_t VCHRG_ChrgFault_flg;
  uint8_t VCHRG_ChrgModeInvalid_flg;
  uint8_t VCHRG_ChrgModeAbnormal_flg;
  uint8_t VCHRG_ChrgLockCheckTimeout_flg;
  uint8_t VCHRG_ShiftKnobCheckTimeout_flg;
  uint8_t VCHRG_ChrgStopAbnormal_flg;
  uint8_t VCHRG_ChrgStopOperTimeout_flg;
  uint8_t VCHRG_ChrgStopModeInvalid_flg;
  //message ticks
  uint32_t VHAL_VCUCanTickCount;
  uint32_t VHAL_VCUPTCanTickCount;
  uint32_t VHAL_VCUBodyCanTickCount;
  uint32_t VHALI_BMS_113_MsgTicks;
  uint32_t VHALI_BMS_213_MsgTicks;
  uint32_t VHALI_BMS_233_MsgTicks;
  uint32_t VHALI_BMS_303_MsgTicks;
  uint32_t VHALI_BMS_313_MsgTicks;
  uint32_t VHALI_BMS_323_MsgTicks;
  uint32_t VHALI_BMS_377_MsgTicks;
  uint32_t VHALI_BMS_513_MsgTicks;
  uint32_t VHALI_BMS_633_MsgTicks;
  uint32_t VHALI_MCU_115_MsgTicks;
  uint32_t VHALI_MCU_125_MsgTicks;
  uint32_t VHALI_MCU_215_MsgTicks;
  uint32_t VHALI_MCU_515_MsgTicks;
  uint32_t VHALI_DCDC_231_MsgTicks;
  uint32_t VHALI_DCDC_251_MsgTicks;
  uint32_t VHALI_OBC_311_MsgTicks;
  uint32_t VHALI_OBC_321_MsgTicks;
  uint32_t VHALI_OBC_331_MsgTicks;
  uint32_t VHALI_PTC_5DA_MsgTicks;
  uint32_t VHALI_ECC_33C_MsgTicks;
  uint32_t VHALI_ECC_34C_MsgTicks;
  uint32_t VHALI_ECC_35C_MsgTicks;
  uint32_t VHALI_PEPS_108_MsgTicks;
  uint32_t VHALI_PEPS_103_MsgTicks;
  uint32_t VHALI_SRS_050_MsgTicks;
  uint32_t VHALI_ABS_232_MsgTicks;
  uint32_t VHALI_ABS_237_MsgTicks;
  uint32_t VHALI_GW_217_MsgTicks;
  uint32_t VHALI_GW_522_MsgTicks;
  uint32_t VHALI_TPMS_317_MsgTicks;
  uint32_t VHALI_TPMS_3A2_MsgTicks;
  uint32_t VHALI_EAC_349_MsgTicks;
  uint32_t VHALI_TBOX_298_MsgTicks;
  uint32_t VHALI_EPS_2A0_MsgTicks;
  uint32_t VHALI_EPS_180_MsgTicks;
  uint32_t VHALI_ECC_36C_MsgTicks;
  uint32_t VHALI_BMS_653_MsgTicks;
  uint32_t VHALI_PEPS_282_MsgTicks;
  uint32_t VHALI_BMS_603_MsgTicks;
  uint32_t VHALI_PTC_5DB_MsgTicks;
  uint32_t VHALI_TBOX_296_MsgTicks;
  uint32_t VHALI_GW_405_MsgTicks;
  uint32_t VHALI_TMS_2C0_MsgTicks;
  uint32_t VHALI_TMS_2C1_MsgTicks;
  uint32_t VHALI_TMS_2C2_MsgTicks;
  uint32_t VHALI_TMS_2C3_MsgTicks;
  uint32_t VHALI_WPTC_2F0_MsgTicks;
  uint32_t VHALI_TMS_325_MsgTicks;
  uint32_t VHALI_WPTC_566_MsgTicks;
  uint32_t VHALI_BMS_304_MsgTicks;
  uint32_t VHALI_BMS_613_MsgTicks;
  uint32_t VHALI_ABS_229_MsgTicks;
  uint32_t VHALI_BMS_623_MsgTicks;
  /*added for CR 1519*/
  uint8_t  AuthFailedData[AUTHFALIED_DATA_SIZE];
  /*added for CR 1519*/
  uint8_t CAN3_BusOffState; /*bug 1578*/
//  uint8_T TQM_GearDisp;    /*for bug 1609*/
  /*BTK and ESCL*/
  boolean SSBSync;                        /*BTK SSB two switches are sync*/
  boolean ING1_FeedCorrect;       /*IGN1 feed back voltage correct*/
  boolean ING2_FeedCorrect;       /*IGN2 feed back voltage correct*/
  BTK_EsclRsltType EsclRslt;
  uint8_t EsclLinCommFailed;
  uint8_t EsclStatus;
  uint8_t EsclErrorCode;

  uint8_t VINP_CruiseKeySet_flg; /*CR1845*/
  uint8_t VINP_CruiseKeyRes_flg;
  uint8_t VCHRG_OBCSleepTimeout_flg; /*CR1853*/
//  boolean_T ENM_Batt_EnergyToolow;/*CR1927*/
  float VINP_BMSMaxDchaPwr_kW;/*CR2097*/
//  boolean_T VBTK_SleepAllw_flg;
}_Exchange_C1T0_tag_;

typedef struct _Exchange_C0T1_struct_tag_{
  _Exchange_Status_ QAflag;//读写标志位
  /*------------NVM-------------*/
  uint8_t DtcToCAN[DTC_NUM_IN_RAM];
  NvMLoadSaveType NvMAppDataSaveLoadFlag;
  //uint8_t PEPS_FixedCode_Byte[4];
  uint8_t PEPS_VSK_Byte[16];
  uint8_t ECU_FUN_CFG_Byte[6];   //ECU configuration(DID: F1FA)
  uint8_t ECU_FUN_CFG_Valid;
  uint8_t VCU_CCP_Byte[1];
  uint8_t VCU_CCP_Valid;
  uint8_t VCU_CFG_Byte[8];   //VCU configuration(DID: F1FD)
  uint8_t VCU_CFG_Valid;
  uint8_t VHALO_VCUHwVer1;
  uint8_t VHALO_VCUHwVer2;
  uint16_t VHALO_VCUSwVer1;
  uint8_t VHALO_VCUSwVer2;
  uint8_t VHALO_VCUSwVer3;
  /*------------UDS-------------*/
  udsIOCTRLDIDType IOCtrlDidTbl[3];  /*task.c 使用 */
///boolean DisRecordDTC;           /*DHP 使用，表示是否关闭诊断 */
  UDS_CtrlType AppComCtrlType;   /* controlling type for NM Message communication*/
  UDS_CtrlType NmComCtrlType;    /*controlling type for App Message communication */
   /*following is relevant to HW test*/
  boolean udsHWTestingModeStatus;
  uint8_t EnetTestMaster;
  unsigned char Bios_LS_Output[LS_NUM];   /* 硬件测试，低驱输出 */
  unsigned char Bios_HS_Output[HS_NUM];   /* 硬件测试，高驱输出 */
  _NCV7719_INOUTPUT_ NCV7719_data;    /* HW test , H  bridge output */
  HWTest_PwmCtrlType udsHWTestPwmCtrl[PWM_NUM];
  /*for HW test communication test*/
   _CAN_flag_ CanComTest;
  uint8_t lintest;
  uint8_t     SocResiMilgNvMCorrect ;
/*for Aging Test start flag.*/
  boolean bool_udsAgingTestStart_flag;
  boolean bool_udsAgingTestError_flag;
  /*------------APP-------------*/
//  DHP DHP_output;
  /*BTK*/
  BTK_EsclReqType EsclOperReq;
  uint32_t EsclkeyToBeProg;
  uint32_t EsclCurrentKey;

  boolean udsECUUpgrade;
  boolean udsKeepPresent;
  uint8_t NVMStateMachineSts;
}_Exchange_C0T1_tag_;

typedef _Exchange_C1T0_tag_ 	_Exchange_Output_tag_;//----不同核时需要改变
typedef _Exchange_C0T1_tag_ 	_Exchange_Input_tag_;//----不同核时需要改变

__EX_DATA_EXTERN__ _Exchange_Input_tag_ * Ex_Input;	//Core1的变量输入
__EX_DATA_EXTERN__ _Exchange_Output_tag_ * Ex_Output;//Core1的变量输出


__EX_DATA_EXTERN__ void Ex_Input_CopyValue(void);
__EX_DATA_EXTERN__ void Ex_Output_CopyValue(void);

#endif /* HAL_EXCHANGE_EX_DATA_H_ */

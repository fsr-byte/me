/*
 * EX_Data.c
 *
 *  Created on: 2019年6月24日
 *      Author: helei
 */

#define __EX_DATA_GLOBALS__

#include "derivative.h"
#include "EX_Define.h"
#include "string.h"
#include "NVM.h"
#include "DHP_model.h"
_Exchange_Input_tag_ * Ex_Input = (_Exchange_Input_tag_ *)Exchange_Input_Addr;	//Core1的变量输入
_Exchange_Output_tag_ * Ex_Output = (_Exchange_Output_tag_ *)Exchange_Output_Addr;//Core1的变量输出

/*-----------NVM UDS输入，从Core1到Core0 -----------------*/
//NVM
B_DHP_model_T DHP_model_B;
APPDID_outSnapshots appDID_outSnapshot;
uint8_t VHALI_TBOX_TimeYear;
uint8_t VHALI_TBOX_TimeMonth;
uint8_t VHALI_TBOX_TimeDate;
uint8_t VHALI_TBOX_TimeHour;
uint8_t VHALI_TBOX_TimeMinute;
uint8_t VHALI_TBOX_TimeSecond;
uint16_t VHALI_BMSErrNum;
uint8_t VHALI_MCUErrNum;
uint8_t Fault_storage_array[2480];    /*bug 1515: change snapshot size to 62, 30 records, so the array is 1860 bytes*/
uint8_t DTCStatusRAMTbl[UDS_SP_DTC_NUM];
PMM PMM_output;//需要其中的两个量：WakeSrcValid 、VPMM_InternalSleepActive_flg
uint16_t VHALO_MotTqReq;

//UDS
uint16_t VHALI_ABS_VehicleSpeed;
///uint16_t VHALI_MCUElecMotSpd;
int16_t VINP_MCUElecMotSpd_rpm; //bug 1620
uint8_t Bios_Sw_Input[SW_NUM];  //数字量获取
unsigned int  ADC_OutBuff[ADC_NUM];  //ADC result
_BTS_data_ BTS5180_data[2];    /*core 1 to core 0*/
_BTS_data_ BTS5200_data[4];
float hIOP_CollisionSw_Hz;/*频率信号输入*/
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
_NCV7719_INOUTPUT_ NCV7719_data;    /*for UDS its input from Core1, for NVM it is output*/
_NCV7240B_SO_data_ NCV7240B_SO_data;
IO_INPUT_Rx_32B_tag FS6500_IO_Input;      /*FS6500 IO from Core 1*/

//APP
HALI HALI_output;
PMM PMM_output;
CHRG CHRG_output;
NM NM_output;//
TMM TMM_output;
TQM TQM_output;//
PEPS_PEPS PEPS_output;
ENM ENM_output;
Config Config_output;//
SPDCtl SPDCtl_output;
INP INP_output;
BTK BTK_output;

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
uint8_t IGBTFaultFromMCU;
uint8_t seriousHistFaultFlag;
uint8_t hIOP_HSFaultCode_enum_POR;
//uint8_t gbDidDataCorrect;
//uint8_t gbCalDataCorrect;
uint8_t CruiseKeyFaultCode;
///uint8_t DisRecordDTC;
uint8_t VHALO_MCURelayActive_flg;
uint8_t PTBusOffConfirmedFlag;
//uint8_t HistDataCheckFaliedFlag;
uint8_t VCHRG_ChrgStopLockError_flg;
uint8_t VCHRG_OBCWakeupTimeout_flg;
//uint8_t AppDataCheckFaliedFlag;
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

/*-----------NVM UDS输出从Core0 到 core 1 -----------------*/
CORE0_INIT uint8_t PEPS_FixedCode_Byte[4];
CORE0_INIT uint8_t PEPS_VSK_Byte[16];
CORE0_INIT uint8_t ECU_FUN_CFG_Byte[6];   //ECU configuration(DID: F1FA)
CORE0_INIT uint8_t ECU_FUN_CFG_Valid;
CORE0_INIT uint8_t VCU_CCP_Byte[1];
CORE0_INIT uint8_t VCU_CCP_Valid; //存放在不重复初始化的区域
CORE0_INIT uint8_t VCU_CFG_Byte[8];   //VCU configuration(DID: F1FD)
CORE0_INIT uint8_t VCU_CFG_Valid;
CORE0_INIT uint8_t VHALO_VCUHwVer1;
CORE0_INIT uint8_t VHALO_VCUHwVer2;
CORE0_INIT uint16_t VHALO_VCUSwVer1;
CORE0_INIT uint8_t VHALO_VCUSwVer2;
CORE0_INIT uint8_t VHALO_VCUSwVer3;

/*for bug 1519*/
uint16_t VPEPS_WaitTime_ms;
uint8_t VPEPS_SendChallengeCodeType_enum;
uint8_t VPEPS_SendChallenge_Cnt;
uint8_t VPEPS_Result_enum;
uint8_t VPEPS_AuthTime_Cnt;
uint8_t VPEPS_OnGoing_flg;
uint8_t VPEPS_ResetPEPSStatus_flg;

uint8_t CAN3_BusOffState;  /*for bug 1578*/
uint8_T TQM_GearDisp;   /*for bug 1609*/

uint8_t VINP_CruiseKeySet_flg; /*CR1845*/
uint8_t VINP_CruiseKeyRes_flg;

uint8_t VCHRG_OBCSleepTimeout_flg;/*CR1853*/
boolean VBTK_SleepAllw_flg;
/*---------------------输入量--------------------*/

void Ex_Input_CopyValue(void)
{
  //从Core1接收本地DHP所需要的输入数据
  //NVM
  //memcpy(&DHP_model_B,&(Ex_Input->DHP_model_B),sizeof(DHP_model_B));
  memcpy(&appDID_outSnapshot,&(Ex_Input->appDID_outSnapshot),sizeof(appDID_outSnapshot));
  VHALI_TBOX_TimeYear = Ex_Input->VHALI_TBOX_TimeYear;
  VHALI_TBOX_TimeMonth = Ex_Input->VHALI_TBOX_TimeMonth;
  VHALI_TBOX_TimeDate = Ex_Input->VHALI_TBOX_TimeDate;
  VHALI_TBOX_TimeHour = Ex_Input->VHALI_TBOX_TimeHour;
  VHALI_TBOX_TimeMinute = Ex_Input->VHALI_TBOX_TimeMinute;
  VHALI_TBOX_TimeSecond = Ex_Input->VHALI_TBOX_TimeSecond;
  VHALI_BMSErrNum = Ex_Input->VHALI_BMSErrNum;
  VHALI_MCUErrNum = Ex_Input->VHALI_MCUErrNum;
  //memcpy(&(Fault_storage_array[0]),&(Ex_Input->Fault_storage_array[0]),sizeof(Fault_storage_array));
  //memcpy(&(DTCStatusRAMTbl[0]),&(Ex_Input->DTCStatusRAMTbl[0]),sizeof(DTCStatusRAMTbl));
  PMM_output.WakeSrcValid = Ex_Input->WakeSrcValid;
  PMM_output.VPMM_InternalSleepActive_flg = Ex_Input->VPMM_InternalSleepActive_flg;
//  IGBTFaultFromMCU = Ex_Input->IGBTFaultFromMCU;
  VHALO_MotTqReq = Ex_Input->VHALO_MotTqReq;
  //UDS
  VHALI_ABS_VehicleSpeed = Ex_Input->VHALI_ABS_VehicleSpeed;
  VINP_MCUElecMotSpd_rpm = Ex_Input->VINP_MCUElecMotSpd_rpm;
  /*HW test relevant parameters*/
  hIOP_CollisionSw_Hz = Ex_Input->hIOP_CollisionSw_Hz;
  hIOP_CollisionSw_Duty = Ex_Input->hIOP_CollisionSw_Duty;
  hIOP_WaterPwm_Hz = Ex_Input->hIOP_WaterPwm_Hz;
  hIOP_WaterPwm_Duty = Ex_Input->hIOP_WaterPwm_Duty;
  hIOP_HVInterlock_Hz = Ex_Input->hIOP_HVInterlock_Hz;
  hIOP_HVInterlock_PulseTime_us  =  Ex_Input->hIOP_HVInterlock_PulseTime_us;
  hIOP_HVInterlock_PeriodTime_us =  Ex_Input->hIOP_HVInterlock_PeriodTime_us;  
  hIOP_HVInterlock_Duty = Ex_Input->hIOP_HVInterlock_Duty;
  hIOP_Fin4_Hz = Ex_Input->hIOP_Fin4_Hz;
  hIOP_VacuumPumpIn_Duty = Ex_Input->hIOP_VacuumPumpIn_Duty;  
  (void)memcpy(&Bios_Sw_Input[0], &Ex_Input->Bios_Sw_Input[0], sizeof(Bios_Sw_Input));
  (void)memcpy(&ADC_OutBuff[0], &Ex_Input->ADC_OutBuff[0], sizeof(ADC_OutBuff));
  (void)memcpy(&BTS5180_data[0], &Ex_Input->BTS5180_data[0], sizeof(BTS5180_data));
  (void)memcpy(&BTS5200_data[0], &Ex_Input->BTS5200_data[0], sizeof(BTS5200_data));
  (void)memcpy(&NCV7513B_SO_data, &Ex_Input->NCV7513B_SO_data, sizeof(NCV7513B_SO_data));
  (void)memcpy(&NCV7719_data.CH1_6_recive, &Ex_Input->NCV7719_data.CH1_6_recive, sizeof(uint32_t));//HB
  (void)memcpy(&NCV7719_data.CH7_8_recive, &Ex_Input->NCV7719_data.CH7_8_recive, sizeof(uint32_t));//HB
  (void)memcpy(&NCV7240B_SO_data, &Ex_Input->NCV7240B_SO_data, sizeof(NCV7240B_SO_data));
  (void)memcpy(&FS6500_IO_Input, &Ex_Input->FS6500_IO_Input, sizeof(FS6500_IO_Input));  
  bswWakeSrc = Ex_Input->bswWakeSrc;
  //------------DHP----------------
Config_output.C_CS_En = Ex_Input->C_CS_En;
Config_output.C_SRS_En = Ex_Input->C_SRS_En;
Config_output.C_EAC_En = Ex_Input->C_EAC_En;
Config_output.C_ECC_En = Ex_Input->C_ECC_En;
Config_output.C_EHU_En = Ex_Input->C_EHU_En;
Config_output.C_EPS_En = Ex_Input->C_EPS_En;
Config_output.C_ICM_En = Ex_Input->C_ICM_En;
Config_output.C_TMS_En = Ex_Input->C_TMS_En;
Config_output.C_TMS_Internal = Ex_Input->C_TMS_Internal;
Config_output.C_CC_En = Ex_Input->C_CC_En;
Config_output.C_Booster_En = Ex_Input->C_Booster_En;
Config_output.C_VacuumPump_En = Ex_Input->C_VacuumPump_En;
NM_output.VNM_TxLiphome_flg = Ex_Input->VNM_TxLiphome_flg;
NM_output.VNM_TxSleepInd_flg = Ex_Input->VNM_TxSleepInd_flg;
TQM_output.b1_M_TQM_TqArbitration = Ex_Input->b1_M_TQM_TqArbitration;
TQM_output.TQM_VehSpd = Ex_Input->TQM_VehSpd;
TQM_output.TQM_EPBAppliedReq = Ex_Input->TQM_EPBAppliedReq;
//----------------------INP
INP_output.CANBMS_signal.VINP_BMSErrNum = Ex_Input->VINP_BMSErrNum;
INP_output.Hardwire_signal.VINP_IgnitionOn_flg = Ex_Input->VINP_IgnitionOn_flg;
INP_output.CANMCU_signal.VINP_MCUIGBTT_C = Ex_Input->VINP_MCUIGBTT_C;
INP_output.CANMCU_signal.VINP_MCUElecMotT_C = Ex_Input->VINP_MCUElecMotT_C;
INP_output.CANMCU_signal.VINP_MCUT_C = Ex_Input->VINP_MCUT_C;
INP_output.CANDCDC_signal.VINP_DCDCFltRnk_enum = Ex_Input->VINP_DCDCFltRnk_enum;
INP_output.CANOBC_signal.VINP_OBCFltRnk_enum = Ex_Input->VINP_OBCFltRnk_enum;
INP_output.CANMCU_signal.VINP_MCUFltRnk_enum = Ex_Input->VINP_MCUFltRnk_enum;
INP_output.CANMCU_signal.VINP_MCUDcU_V = Ex_Input->VINP_MCUDcU_V;
INP_output.CANMCU_signal.VINP_MCUDcCrrt_A = Ex_Input->VINP_MCUDcCrrt_A;
INP_output.CANMCU_signal.MCUHWCurrOverErr = Ex_Input->MCUHWCurrOverErr;
INP_output.CANMCU_signal.VINP_MCUPwrModErr_flg = Ex_Input->VINP_MCUPwrModErr_flg;
INP_output.CANBMS_signal.VINP_BMSFltRnk_enum = Ex_Input->VINP_BMSFltRnk_enum;
INP_output.CANBMS_signal.VINP_BMSOperMod_enum = Ex_Input->VINP_BMSOperMod_enum;
INP_output.CANBMS_signal.VINP_BMSBattU_V = Ex_Input->VINP_BMSBattU_V;
INP_output.CANBMS_signal.VINP_BMSCellUMax = Ex_Input->VINP_BMSCellUMax;
INP_output.CANBMS_signal.VINP_BMSCellUMin = Ex_Input->VINP_BMSCellUMin;
INP_output.CANBMS_signal.VINP_BMSMaxBattT = Ex_Input->VINP_BMSMaxBattT;
INP_output.CANBMS_signal.VINP_BMSChrgMod_enum = Ex_Input->VINP_BMSChrgMod_enum;
INP_output.CANMCU_signal.VINP_MCUErrNum = Ex_Input->VINP_MCUErrNum;
INP_output.CANMCU_signal.VINP_MCUOperMdl_enum = Ex_Input->VINP_MCUOperMdl_enum;
INP_output.ABS.VINP_ABS_AbsFlgFlt = Ex_Input->VINP_ABS_AbsFlgFlt;
INP_output.EPB.VINP_EPS_EpasFailed = Ex_Input->VINP_EPS_EpasFailed;
INP_output.ABS.VINP_ABS_EbdFlgFlt = Ex_Input->VINP_ABS_EbdFlgFlt;
INP_output.EPB.VINP_EPB_Status = Ex_Input->VINP_EPB_Status;
INP_output.ABS.VINP_ABS_VehicleSpeedValid_flg = Ex_Input->VINP_ABS_VehicleSpeedValid_flg;
INP_output.CANMCU_signal.VINP_MotTqRealValid_flg = Ex_Input->VINP_MotTqRealValid_flg;
INP_output.CANMCU_signal.VINP_MCUElecMotSpdValid_flg = Ex_Input->VINP_MCUElecMotSpdValid_flg;
INP_output.CANBMS_signal.VINP_BMSBattUOverU = Ex_Input->VINP_BMSBattUOverU;
INP_output.CANBMS_signal.VINP_BMSBattUUnderU = Ex_Input->VINP_BMSBattUUnderU;
INP_output.CANBMS_signal.VINP_BMSCellUMaxOverU = Ex_Input->VINP_BMSCellUMaxOverU;
INP_output.CANBMS_signal.VINP_BMSCellUMinUnderU = Ex_Input->VINP_BMSCellUMinUnderU;
INP_output.CANBMS_signal.VINP_BMSMaxBattTOverT = Ex_Input->VINP_BMSMaxBattTOverT;
INP_output.ABS.VINP_ESP_ESPFailStatus = Ex_Input->VINP_ESP_ESPFailStatus;
INP_output.Hardwire_signal.VINP_SlowChargeAwakeActive_flg = Ex_Input->VINP_SlowChargeAwakeActive_flg;
INP_output.Hardwire_signal.VINP_FastChargeAwakeActiveIn_flg = Ex_Input->VINP_FastChargeAwakeActiveIn_flg;
INP_output.ICM.VINP_ICM_VehSpdChkInvalidFlt_flg = Ex_Input->VINP_ICM_VehSpdChkInvalidFlt_flg;
INP_output.PEPS.VINP_PEPS_PDU = Ex_Input->VINP_PEPS_PDU;
INP_output.Hardwire_signal.VINP_GearOut_enum = Ex_Input->VINP_GearOut_enum;
INP_output.Hardwire_signal.VINP_AccelPedal_per = Ex_Input->VINP_AccelPedal_per;
INP_output.Hardwire_signal.VINP_BrkLightSwitchActive_flg = Ex_Input->VINP_BrkLightSwitchActive_flg;

//----------------------
PEPS_output.VPEPS_Result_enum = Ex_Input->VPEPS_Result_enum;
SPDCtl_output.u1_M_SPDCtl_CRUISEDiagError_enum = Ex_Input->u1_M_SPDCtl_CRUISEDiagError_enum;
ENM_output.ENM_BMSMaxDchaPwrFlt_flg = Ex_Input->ENM_BMSMaxDchaPwrFlt_flg;
CHRG_output.VCHRG_ChrgStsLampReq_flg = Ex_Input->VCHRG_ChrgStsLampReq_flg;
CHRG_output.VCHRG_VCUChrgAllwd_flg = Ex_Input->VCHRG_VCUChrgAllwd_flg;
TMM_output.TMM_WaterPumpEnReq_flg = Ex_Input->TMM_WaterPumpEnReq_flg;
TMM_output.TMM_VCUChrgReqLimFac_enum = Ex_Input->TMM_VCUChrgReqLimFac_enum;
TMM_output.TMM_InvalidBattReq = Ex_Input->TMM_InvalidBattReq;
PMM_output.VPMM_PTReady_flg = Ex_Input->VPMM_PTReady_flg;
PMM_output.VPMM_UpToHVMode_flg = Ex_Input->VPMM_UpToHVMode_flg;
PMM_output.VPMM_LVEna = Ex_Input->VPMM_LVEna;
PMM_output.VPMM_LVUpTimeout_flg = Ex_Input->VPMM_LVUpTimeout_flg;
PMM_output.VPMM_HVUpTimeout_flg = Ex_Input->VPMM_HVUpTimeout_flg;
PMM_output.VPMM_HVActiveTimeout_flg = Ex_Input->VPMM_HVActiveTimeout_flg;
PMM_output.VPMM_HVDownTimeout_flg = Ex_Input->VPMM_HVDownTimeout_flg;
PMM_output.VPMM_MCUDischargeTimeout_flg = Ex_Input->VPMM_MCUDischargeTimeout_flg;
PMM_output.VPMM_LVUpBMSPwrUpAllwTimeout_flg = Ex_Input->VPMM_LVUpBMSPwrUpAllwTimeout_flg;
PMM_output.VPMM_LVUpBMSTimeout_flg = Ex_Input->VPMM_LVUpBMSTimeout_flg;
PMM_output.VPMM_LVUpDCDCTimeout_flg = Ex_Input->VPMM_LVUpDCDCTimeout_flg;
PMM_output.VPMM_LVUpMCUTimeout_flg = Ex_Input->VPMM_LVUpMCUTimeout_flg;
PMM_output.VPMM_MCUHVActiveTimeout_flg = Ex_Input->VPMM_MCUHVActiveTimeout_flg;
PMM_output.VPMM_HVDCDCActiveTimeout_flg = Ex_Input->VPMM_HVDCDCActiveTimeout_flg;
PMM_output.VPMM_BMSModError = Ex_Input->VPMM_BMSModError;
PMM_output.VPMM_MCUModError = Ex_Input->VPMM_MCUModError;
PMM_output.VPMM_DCDCModError = Ex_Input->VPMM_DCDCModError;
PMM_output.VPMM_MCUExitTqlTimeout_flg = Ex_Input->VPMM_MCUExitTqlTimeout_flg;
PMM_output.VPMM_DCDCStopworkTimeout_flg = Ex_Input->VPMM_DCDCStopworkTimeout_flg;
PMM_output.VPMM_VehSts_enum = Ex_Input->VPMM_VehSts_enum;
memcpy(&HALI_output.Hardwire_Inputs,&Ex_Input->Hardwire_Inputs,sizeof(HALI_Hardwire));//HALI
HALI_output.CAN_Inputs.HALI_SRS.VHALI_SRS_CrashOutputStatus = Ex_Input->VHALI_SRS_CrashOutputStatus;
HALI_output.CAN_Inputs.HALI_BMS.VHALI_BMSChrgSts = Ex_Input->VHALI_BMSChrgSts;
HALI_output.CAN_Inputs.HALI_MCU.VHALI_MotTqReal = Ex_Input->VHALI_MotTqReal;
HALI_output.CAN_Inputs.HALI_MCU.VHALI_MCUIGBTT = Ex_Input->VHALI_MCUIGBTT;
HALI_output.CAN_Inputs.HALI_MCU.VHALI_MCUElecMotT = Ex_Input->VHALI_MCUElecMotT;
HALI_output.CAN_Inputs.HALI_MCU.VHALI_MCUElecMotSpd = Ex_Input->VHALI_MCUElecMotSpd;
HALI_output.CAN_Inputs.HALI_BMS.VHALI_BMSSOC = Ex_Input->VHALI_BMSSOC;
HALI_output.CAN_Inputs.HALI_BMS.VHALI_BMSBattU = Ex_Input->VHALI_BMSBattU;
HALI_output.CAN_Inputs.HALI_BMS.VHALI_BMSBattI = Ex_Input->VHALI_BMSBattI;
HALI_output.CAN_Inputs.HALI_BMS.VHALI_BMSAvrgBattT = Ex_Input->VHALI_BMSAvrgBattT;
HALI_output.CAN_Inputs.HALI_EHU.VHALI_ClstrOdo = Ex_Input->VHALI_ClstrOdo;
HALI_output.CAN_Inputs.HALI_TBOX.VHALI_TBOX_TimeYear = Ex_Input->VHALI_TBOX_TimeYear__1;
HALI_output.CAN_Inputs.HALI_TBOX.VHALI_TBOX_TimeMonth = Ex_Input->VHALI_TBOX_TimeMonth__1;
HALI_output.CAN_Inputs.HALI_TBOX.VHALI_TBOX_TimeDate = Ex_Input->VHALI_TBOX_TimeDate__1;
HALI_output.CAN_Inputs.HALI_TBOX.VHALI_TBOX_TimeHour = Ex_Input->VHALI_TBOX_TimeHour__1;
HALI_output.CAN_Inputs.HALI_TBOX.VHALI_TBOX_TimeMinute = Ex_Input->VHALI_TBOX_TimeMinute__1;
HALI_output.CAN_Inputs.HALI_TBOX.VHALI_TBOX_TimeSecond = Ex_Input->VHALI_TBOX_TimeSecond__1;
HALI_output.CAN_Inputs.HALI_BMS.VHALI_BMSErrNum = Ex_Input->VHALI_BMSErrNum__1;
HALI_output.CAN_Inputs.HALI_MCU.VHALI_MCUErrNum = Ex_Input->VHALI_MCUErrNum__1;
HALI_output.CAN_Inputs.HALI_EPB.VHALI_EPB_Status = Ex_Input->VHALI_EPB_Status;
  //BSW
VHALI_ICM_234_MsgTicks = Ex_Input->VHALI_ICM_234_MsgTicks;
VHALI_EHU_345_MsgTicks = Ex_Input->VHALI_EHU_345_MsgTicks;
hIOP_LSFaultCode_enum_POR = Ex_Input->hIOP_LSFaultCode_enum_POR;
VHALI_EAC_34A_MsgTicks = Ex_Input->VHALI_EAC_34A_MsgTicks;
VHALI_XBS_241_MsgTicks = Ex_Input->VHALI_XBS_241_MsgTicks;
VHALI_ICM_235_MsgTicks = Ex_Input->VHALI_ICM_235_MsgTicks;
hIOP_FastChargeAwake_flg = Ex_Input->hIOP_FastChargeAwake_flg;
hIOP_SlowChargeAwake_flg = Ex_Input->hIOP_SlowChargeAwake_flg;
hIOP_MainRelay_flg = Ex_Input->hIOP_MainRelay_flg;
hIOP_GearSwitch1_flg = Ex_Input->hIOP_GearSwitch1_flg;
hIOP_GearSwitch2_flg = Ex_Input->hIOP_GearSwitch2_flg;
hIOP_GearSwitch3_flg = Ex_Input->hIOP_GearSwitch3_flg;
hIOP_GearSwitch4_flg = Ex_Input->hIOP_GearSwitch4_flg;
hIOP_BrkLightSwitch1_flg = Ex_Input->hIOP_BrkLightSwitch1_flg;
hIOP_BrkLightSwitch2_flg = Ex_Input->hIOP_BrkLightSwitch2_flg;
hIOP_LSpdFan_flg = Ex_Input->hIOP_LSpdFan_flg;
hIOP_HSpdFan_flg = Ex_Input->hIOP_HSpdFan_flg;
hIOP_WaterPump_flg = Ex_Input->hIOP_WaterPump_flg;
VHALI_HWVersion = Ex_Input->VHALI_HWVersion;
hIOP_HSFaultCode_enum_POR = Ex_Input->hIOP_HSFaultCode_enum_POR;
//gbDidDataCorrect = Ex_Input->gbDidDataCorrect;
//gbCalDataCorrect = Ex_Input->gbCalDataCorrect;
CruiseKeyFaultCode = Ex_Input->CruiseKeyFaultCode;
///DisRecordDTC = Ex_Input->DisRecordDTC;
VHALO_MCURelayActive_flg = Ex_Input->VHALO_MCURelayActive_flg;
PTBusOffConfirmedFlag = Ex_Input->PTBusOffConfirmedFlag;
//HistDataCheckFaliedFlag = Ex_Input->HistDataCheckFaliedFlag;
VCHRG_ChrgStopLockError_flg = Ex_Input->VCHRG_ChrgStopLockError_flg;
VCHRG_OBCWakeupTimeout_flg = Ex_Input->VCHRG_OBCWakeupTimeout_flg;
//AppDataCheckFaliedFlag = Ex_Input->AppDataCheckFaliedFlag;
VCHRG_ChrgFault_flg = Ex_Input->VCHRG_ChrgFault_flg;
VCHRG_ChrgModeInvalid_flg = Ex_Input->VCHRG_ChrgModeInvalid_flg;
VCHRG_ChrgModeAbnormal_flg = Ex_Input->VCHRG_ChrgModeAbnormal_flg;
VCHRG_ChrgLockCheckTimeout_flg = Ex_Input->VCHRG_ChrgLockCheckTimeout_flg;
VCHRG_ShiftKnobCheckTimeout_flg = Ex_Input->VCHRG_ShiftKnobCheckTimeout_flg;
VCHRG_ChrgStopAbnormal_flg = Ex_Input->VCHRG_ChrgStopAbnormal_flg;
VCHRG_ChrgStopOperTimeout_flg = Ex_Input->VCHRG_ChrgStopOperTimeout_flg;
VCHRG_ChrgStopModeInvalid_flg = Ex_Input->VCHRG_ChrgStopModeInvalid_flg;
//message ticks
VHAL_VCUCanTickCount = Ex_Input->VHAL_VCUCanTickCount;
VHAL_VCUPTCanTickCount = Ex_Input->VHAL_VCUPTCanTickCount;
VHAL_VCUBodyCanTickCount = Ex_Input->VHAL_VCUBodyCanTickCount;
VHALI_BMS_113_MsgTicks = Ex_Input->VHALI_BMS_113_MsgTicks;
VHALI_BMS_213_MsgTicks = Ex_Input->VHALI_BMS_213_MsgTicks;
VHALI_BMS_233_MsgTicks = Ex_Input->VHALI_BMS_233_MsgTicks;
VHALI_BMS_303_MsgTicks = Ex_Input->VHALI_BMS_303_MsgTicks;
VHALI_BMS_313_MsgTicks = Ex_Input->VHALI_BMS_313_MsgTicks;
VHALI_BMS_323_MsgTicks = Ex_Input->VHALI_BMS_323_MsgTicks;
VHALI_BMS_377_MsgTicks = Ex_Input->VHALI_BMS_377_MsgTicks;
VHALI_BMS_513_MsgTicks = Ex_Input->VHALI_BMS_513_MsgTicks;
VHALI_BMS_633_MsgTicks = Ex_Input->VHALI_BMS_633_MsgTicks;
VHALI_MCU_115_MsgTicks = Ex_Input->VHALI_MCU_115_MsgTicks;
VHALI_MCU_125_MsgTicks = Ex_Input->VHALI_MCU_125_MsgTicks;
VHALI_MCU_215_MsgTicks = Ex_Input->VHALI_MCU_215_MsgTicks;
VHALI_MCU_515_MsgTicks = Ex_Input->VHALI_MCU_515_MsgTicks;
VHALI_DCDC_231_MsgTicks = Ex_Input->VHALI_DCDC_231_MsgTicks;
VHALI_DCDC_251_MsgTicks = Ex_Input->VHALI_DCDC_251_MsgTicks;
VHALI_OBC_311_MsgTicks = Ex_Input->VHALI_OBC_311_MsgTicks;
VHALI_OBC_321_MsgTicks = Ex_Input->VHALI_OBC_321_MsgTicks;
VHALI_OBC_331_MsgTicks = Ex_Input->VHALI_OBC_331_MsgTicks;
VHALI_PTC_5DA_MsgTicks = Ex_Input->VHALI_PTC_5DA_MsgTicks;
VHALI_ECC_33C_MsgTicks = Ex_Input->VHALI_ECC_33C_MsgTicks;
VHALI_ECC_34C_MsgTicks = Ex_Input->VHALI_ECC_34C_MsgTicks;
VHALI_ECC_35C_MsgTicks = Ex_Input->VHALI_ECC_35C_MsgTicks;
VHALI_PEPS_108_MsgTicks = Ex_Input->VHALI_PEPS_108_MsgTicks;
VHALI_PEPS_103_MsgTicks = Ex_Input->VHALI_PEPS_103_MsgTicks;
VHALI_SRS_050_MsgTicks = Ex_Input->VHALI_SRS_050_MsgTicks;
VHALI_ABS_232_MsgTicks = Ex_Input->VHALI_ABS_232_MsgTicks;
VHALI_ABS_237_MsgTicks = Ex_Input->VHALI_ABS_237_MsgTicks;
VHALI_GW_217_MsgTicks = Ex_Input->VHALI_GW_217_MsgTicks;
VHALI_GW_522_MsgTicks = Ex_Input->VHALI_GW_522_MsgTicks;
VHALI_TPMS_317_MsgTicks = Ex_Input->VHALI_TPMS_317_MsgTicks;
VHALI_TPMS_3A2_MsgTicks = Ex_Input->VHALI_TPMS_3A2_MsgTicks;
VHALI_EAC_349_MsgTicks = Ex_Input->VHALI_EAC_349_MsgTicks;
VHALI_TBOX_298_MsgTicks = Ex_Input->VHALI_TBOX_298_MsgTicks;
VHALI_EPS_2A0_MsgTicks = Ex_Input->VHALI_EPS_2A0_MsgTicks;
VHALI_EPS_180_MsgTicks = Ex_Input->VHALI_EPS_180_MsgTicks;
VHALI_ECC_36C_MsgTicks = Ex_Input->VHALI_ECC_36C_MsgTicks;
VHALI_BMS_653_MsgTicks = Ex_Input->VHALI_BMS_653_MsgTicks;
VHALI_PEPS_282_MsgTicks = Ex_Input->VHALI_PEPS_282_MsgTicks;
VHALI_BMS_603_MsgTicks = Ex_Input->VHALI_BMS_603_MsgTicks;
VHALI_PTC_5DB_MsgTicks = Ex_Input->VHALI_PTC_5DB_MsgTicks;
VHALI_TBOX_296_MsgTicks = Ex_Input->VHALI_TBOX_296_MsgTicks;
VHALI_GW_405_MsgTicks = Ex_Input->VHALI_GW_405_MsgTicks;
VHALI_TMS_2C0_MsgTicks = Ex_Input->VHALI_TMS_2C0_MsgTicks;
VHALI_TMS_2C1_MsgTicks = Ex_Input->VHALI_TMS_2C1_MsgTicks;
VHALI_TMS_2C2_MsgTicks = Ex_Input->VHALI_TMS_2C2_MsgTicks;
VHALI_TMS_2C3_MsgTicks = Ex_Input->VHALI_TMS_2C3_MsgTicks;
VHALI_WPTC_2F0_MsgTicks = Ex_Input->VHALI_WPTC_2F0_MsgTicks;
VHALI_TMS_325_MsgTicks = Ex_Input->VHALI_TMS_325_MsgTicks;
VHALI_WPTC_566_MsgTicks = Ex_Input->VHALI_WPTC_566_MsgTicks;
VHALI_BMS_304_MsgTicks = Ex_Input->VHALI_BMS_304_MsgTicks;
VHALI_BMS_613_MsgTicks = Ex_Input->VHALI_BMS_613_MsgTicks;
VHALI_ABS_229_MsgTicks = Ex_Input->VHALI_ABS_229_MsgTicks;
VHALI_BMS_623_MsgTicks = Ex_Input->VHALI_BMS_623_MsgTicks;

    /*added for CR 1519*/
    (void)memcpy(AuthFailedData, &Ex_Input->AuthFailedData, sizeof(AuthFailedData)); /*CR 1519: copy the auth failure internal data from core1 to core 0*/
    /*added for CR 1519*/
    CAN3_BusOffState = Ex_Input->CAN3_BusOffState;  /*for bug 1578*/
    TQM_output.TQM_GearDisp = Ex_Input->TQM_GearDisp;   /*for bug 1609*/
    /*BTK and ESCL*/
    IGN1_FeedVoltCorrect = Ex_Input->ING1_FeedCorrect;
    IGN2_FeedVoltCorrect = Ex_Input->ING2_FeedCorrect;
    SSB_SyncCorrect = Ex_Input->SSBSync;
    gblEsclRslt = Ex_Input->EsclRslt;

    EsclLinCommFailed = Ex_Input->EsclLinCommFailed;
    EsclStatus = Ex_Input->EsclStatus;
    EsclErrorCode = Ex_Input->EsclErrorCode;

    HALI_output.CAN_Inputs.HALI_DCDC.VHALI_DCDCT = Ex_Input->VHALI_DCDCT;//bug1823

    VINP_CruiseKeySet_flg = Ex_Input->VINP_CruiseKeySet_flg; /*CR1845*/
    VINP_CruiseKeyRes_flg = Ex_Input->VINP_CruiseKeyRes_flg;

    VCHRG_OBCSleepTimeout_flg = Ex_Input->VCHRG_OBCSleepTimeout_flg;/*CR1853*/

    Config_output.C_YK19_En = Ex_Input->C_YK19_En ;

    ENM_output.ENM_Batt_EnergyToolow = Ex_Input->ENM_Batt_EnergyToolow;/*CR1927*/

    Config_output.C_ESCL_En = Ex_Input->C_ESCL_En;
    Config_output.C_PMS_En = Ex_Input->C_PMS_En;

    INP_output.CANBMS_signal.VINP_BMSMaxDchaPwr_kW = Ex_Input->VINP_BMSMaxDchaPwr_kW;/*CR2097*/
    VBTK_SleepAllw_flg = Ex_Input->VBTK_SleepAllw_flg;
}

void Ex_Output_CopyValue(void)
{
  //输出本地的DHP的输出数据到交换区
  //NVM
  memcpy(&(Ex_Output->DtcToCAN[0]),&DtcToCAN[0],sizeof(DtcToCAN));
  memcpy(&(Ex_Output->NvMAppDataSaveLoadFlag),&NvMAppDataSaveLoadFlag,sizeof(NvMAppDataSaveLoadFlag));
  //memcpy(&(Ex_Output->PEPS_FixedCode_Byte),&PEPS_FixedCode_Byte,sizeof(PEPS_FixedCode_Byte));
  memcpy(&(Ex_Output->PEPS_VSK_Byte),&PEPS_VSK_Byte,sizeof(PEPS_VSK_Byte));
  memcpy(&(Ex_Output->ECU_FUN_CFG_Byte),&ECU_FUN_CFG_Byte,sizeof(ECU_FUN_CFG_Byte));
  Ex_Output->ECU_FUN_CFG_Valid  = ECU_FUN_CFG_Valid;
  memcpy(&(Ex_Output->VCU_CCP_Byte),&VCU_CCP_Byte,sizeof(VCU_CCP_Byte));
  Ex_Output->VCU_CCP_Valid  = VCU_CCP_Valid;
  memcpy(&(Ex_Output->VCU_CFG_Byte),&VCU_CFG_Byte,sizeof(VCU_CFG_Byte));
  Ex_Output->VCU_CFG_Valid  = VCU_CFG_Valid;
  Ex_Output->VHALO_VCUHwVer1  = VHALO_VCUHwVer1;
  Ex_Output->VHALO_VCUHwVer2  = VHALO_VCUHwVer2;
  Ex_Output->VHALO_VCUSwVer1  = VHALO_VCUSwVer1;
  Ex_Output->VHALO_VCUSwVer2  = VHALO_VCUSwVer2;
  Ex_Output->VHALO_VCUSwVer3  = VHALO_VCUSwVer3;
  //UDS
  /*HW test relevant parameters */
  memcpy(&(Ex_Output->IOCtrlDidTbl[0]),&IOCtrlDidTbl[0],sizeof(IOCtrlDidTbl));
  Ex_Output->udsHWTestingModeStatus  = udsHWTestingModeStatus;
  Ex_Output->EnetTestMaster  = EnetTestMaster;
  (void)memcpy(&Ex_Output->Bios_LS_Output[0], &Bios_LS_Output[0], sizeof(Bios_LS_Output));
  (void)memcpy(&Ex_Output->Bios_HS_Output[0], &Bios_HS_Output[0], sizeof(Bios_HS_Output));
  (void)memcpy(&Ex_Output->NCV7719_data.CH1_6.R, &NCV7719_data.CH1_6.R, sizeof(uint16_t));//HB
  (void)memcpy(&Ex_Output->NCV7719_data.CH7_8.R, &NCV7719_data.CH7_8.R, sizeof(uint16_t));//HB
  (void)memcpy(&Ex_Output->udsHWTestPwmCtrl[0], &udsHWTestPwmCtrl, sizeof(udsHWTestPwmCtrl));
  Ex_Output->CanComTest = CanComTest;
  Ex_Output->lintest = lintest;
  ///Ex_Output->DisRecordDTC = DisRecordDTC;
  memcpy(&(Ex_Output->AppComCtrlType),&AppComCtrlType,sizeof(AppComCtrlType));
  memcpy(&(Ex_Output->NmComCtrlType),&NmComCtrlType,sizeof(NmComCtrlType));
  Ex_Output->SocResiMilgNvMCorrect  = SocResiMilgNvMCorrect;
  Ex_Output->bool_udsAgingTestStart_flag  = bool_udsAgingTestStart_flag;
  Ex_Output->bool_udsAgingTestError_flag  = bool_udsAgingTestError_flag;
  //APP
  memcpy(&(Ex_Output->DHP_output),&DHP_output,sizeof(DHP));
  /*BTK*/
  Ex_Output->EsclOperReq = gblEsclOperReq;
  Ex_Output->EsclkeyToBeProg = newEsclKey;
  Ex_Output->EsclCurrentKey = currEsclKey;

  Ex_Output->udsECUUpgrade = gblUdsECUUpgrade;
  Ex_Output->udsKeepPresent = gblUdsKeepPresent;

  Ex_Output->NVMStateMachineSts = gblNVMStateMachineSts;
}
















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
#include "CAN_DBC_Lib.h"
#include "CAN_Operation.h"
//#include "PMM_Module.h"
//#include "DIM_model.h"
//#include "NM_Model.h"
//#include "TQM_Model.h"
//#include "ENM_Model.h"
//#include "TMM_Model.h"
//#include "PEPS_Model.h"
//#include "CHRG_Model.h"
//#include "HALI_model.h"
//#include "SCR_model.h"
#include "FS6500.h"
#include "Global.h"
//#include "BTK_Model.h"
#include "BTK_ESCL.h"
_Exchange_Input_tag_ * Ex_Input = (_Exchange_Input_tag_ *)Exchange_Input_Addr;	//Core1的变量输入
_Exchange_Output_tag_ * Ex_Output = (_Exchange_Output_tag_ *)Exchange_Output_Addr;//Core1的变量输出

/*-----------NVM UDS输出，从Core0到Core1 -----------------*/
//NVM
uint8_t gbCalDataCorrect = TRUE;
uint8_t gbDidDataCorrect = TRUE ;
uint8_t seriousHistFaultFlag = FALSE;
uint8_t HistDataCheckFaliedFlag  = FALSE;
uint8_t AppDataCheckFaliedFlag = FALSE;
uint8_t DtcToCAN[DTC_NUM_IN_RAM];
NvMLoadSaveType NvMAppDataSaveLoadFlag = 0;
//UDS
udsIOCTRLDIDType IOCtrlDidTbl[3];  /*task.c 使用 */
///boolean DisRecordDTC;           /*DHP 使用，表示是否关闭诊断 */

//uint8_t  IGBTFaultFromMCU = 0;      /*there is a IGBT fault reported by MCU. used by DHP to notify if MCU reported IGBT fault in current cycle*/
//DHP DHP_output;

 void Ex_Input_CopyValue(void)
 {
//   //将Core0的DHP输出的数据从交换区拷贝到本地变量
//   //NVM
//   memcpy(&DtcToCAN[0],&(Ex_Input->DtcToCAN[0]),sizeof(DtcToCAN));
//   memcpy(&NvMAppDataSaveLoadFlag,&(Ex_Input->NvMAppDataSaveLoadFlag),sizeof(NvMAppDataSaveLoadFlag));
//   //memcpy(&PEPS_FixedCode_Byte,&(Ex_Input->PEPS_FixedCode_Byte),sizeof(PEPS_FixedCode_Byte));
//   memcpy(&PEPS_VSK_Byte,&(Ex_Input->PEPS_VSK_Byte),sizeof(PEPS_VSK_Byte));
//   memcpy(&ECU_FUN_CFG_Byte,&(Ex_Input->ECU_FUN_CFG_Byte),sizeof(ECU_FUN_CFG_Byte));
//   ECU_FUN_CFG_Valid = Ex_Input->ECU_FUN_CFG_Valid;
//   memcpy(&VCU_CCP_Byte,&(Ex_Input->VCU_CCP_Byte),sizeof(VCU_CCP_Byte));
//   VCU_CCP_Valid = Ex_Input->VCU_CCP_Valid;
//   memcpy(&VCU_CFG_Byte,&(Ex_Input->VCU_CFG_Byte),sizeof(VCU_CFG_Byte));
//   VCU_CFG_Valid = Ex_Input->VCU_CFG_Valid;
//   VHALO_VCUHwVer1 = Ex_Input->VHALO_VCUHwVer1;
//   VHALO_VCUHwVer2 = Ex_Input->VHALO_VCUHwVer2;
//   VHALO_VCUSwVer1 = Ex_Input->VHALO_VCUSwVer1;
//   VHALO_VCUSwVer2 = Ex_Input->VHALO_VCUSwVer2;
//   VHALO_VCUSwVer3 = Ex_Input->VHALO_VCUSwVer3;
//   //UDS
//   memcpy(&IOCtrlDidTbl[0],&(Ex_Input->IOCtrlDidTbl[0]),sizeof(IOCtrlDidTbl));
//   ///DisRecordDTC = Ex_Input->DisRecordDTC;
//   memcpy(&AppComCtrlType,&(Ex_Input->AppComCtrlType),sizeof(AppComCtrlType));
//   memcpy(&NmComCtrlType,&(Ex_Input->NmComCtrlType),sizeof(NmComCtrlType));
//   /*HW test relevant parameters*/
//   udsHWTestingModeStatus = Ex_Input->udsHWTestingModeStatus;
//   EnetTestMaster = Ex_Input->EnetTestMaster;
//   (void)memcpy(&Ex_Bios_LS_Output[0], &(Ex_Input->Bios_LS_Output[0]), sizeof(Ex_Bios_LS_Output));
//   (void)memcpy(&Ex_Bios_HS_Output[0], &(Ex_Input->Bios_HS_Output[0]), sizeof(Ex_Bios_HS_Output));
//   (void)memcpy(&Ex_NCV7719_data, &Ex_Input->NCV7719_data, sizeof(Ex_NCV7719_data));//HB
//   (void)memcpy(&udsHWTestPwmCtrl[0], &(Ex_Input->udsHWTestPwmCtrl[0]), sizeof(udsHWTestPwmCtrl));
//   CanComTest = Ex_Input->CanComTest;
//   lintest = Ex_Input->lintest;
//   SocResiMilgNvMCorrect = Ex_Input->SocResiMilgNvMCorrect;

//   bool_udsAgingTestStart_flag= Ex_Input->bool_udsAgingTestStart_flag;
//   bool_udsAgingTestError_flag= Ex_Input->bool_udsAgingTestError_flag;
//    //APP
//    memcpy(&DHP_output,&(Ex_Input->DHP_output),sizeof(DHP));
//    /*BTK */
//    udsEsclOperReq = Ex_Input->EsclOperReq;
//    newEsclKey = Ex_Input->EsclkeyToBeProg;
//    currEsclKey = Ex_Input->EsclCurrentKey;

//    gblUdsECUUpgrade = Ex_Input->udsECUUpgrade;
//    gblUdsKeepPresent= Ex_Input->udsKeepPresent;

//    gblNVMStateMachineSts = Ex_Input->NVMStateMachineSts;
 }

 void Ex_Output_CopyValue(void)
 {
//   //将Core0中的DHP需要的量从本地变量拷贝到交换区
//   //NVM
//   //memcpy(&(Ex_Output->DHP_model_B),&DHP_model_B,sizeof(DHP_model_B));
//   memcpy(&(Ex_Output->appDID_outSnapshot),&appDID_outSnapshot,sizeof(appDID_outSnapshot));
//   Ex_Output->VHALI_TBOX_TimeYear = VHALI_TBOX_TimeYear;
//   Ex_Output->VHALI_TBOX_TimeMonth = VHALI_TBOX_TimeMonth;
//   Ex_Output->VHALI_TBOX_TimeDate = VHALI_TBOX_TimeDate;
//   Ex_Output->VHALI_TBOX_TimeHour = VHALI_TBOX_TimeHour;
//   Ex_Output->VHALI_TBOX_TimeMinute = VHALI_TBOX_TimeMinute;
//   Ex_Output->VHALI_TBOX_TimeSecond = VHALI_TBOX_TimeSecond;
//   Ex_Output->VHALI_BMSErrNum = VHALI_BMSErrNum;
//   Ex_Output->VHALI_MCUErrNum = VHALI_MCUErrNum;
//   //memcpy(&(Ex_Output->Fault_storage_array[0]),&(Fault_storage_array[0]),sizeof(Fault_storage_array));
//   //memcpy(&(Ex_Output->DTCStatusRAMTbl[0]),&(DTCStatusRAMTbl[0]),sizeof(DTCStatusRAMTbl));
//   Ex_Output->WakeSrcValid = PMM_output.WakeSrcValid;//需要两个量：WakeSrcValid 、VPMM_InternalSleepActive_flg
//   Ex_Output->VPMM_InternalSleepActive_flg = PMM_output.VPMM_InternalSleepActive_flg;
//   //Ex_Output->IGBTFaultFromMCU = IGBTFaultFromMCU;
//   Ex_Output->VHALO_MotTqReq = VHALO_MotTqReq;
//   //UDS
//   Ex_Output->VHALI_ABS_VehicleSpeed = VHALI_ABS_VehicleSpeed;
//   Ex_Output->VINP_MCUElecMotSpd_rpm = INP_output.CANMCU_signal.VINP_MCUElecMotSpd_rpm;
//   /*HW test relevant*/
//   Ex_Output->hIOP_CollisionSw_Hz = hIOP_CollisionSw_Hz;
//   Ex_Output->hIOP_CollisionSw_Duty = hIOP_CollisionSw_Duty;
//   Ex_Output->hIOP_WaterPwm_Hz = hIOP_WaterPwm_Hz;
//   Ex_Output->hIOP_WaterPwm_Duty = hIOP_WaterPwm_Duty;
//   Ex_Output->hIOP_HVInterlock_Hz = hIOP_HVInterlock_Hz;
//   Ex_Output->hIOP_HVInterlock_Duty = hIOP_HVInterlock_Duty;
//   Ex_Output->hIOP_HVInterlock_PulseTime_us = hIOP_HVInterlock_PulseTime_us;
//   Ex_Output->hIOP_HVInterlock_PeriodTime_us = hIOP_HVInterlock_PeriodTime_us;
//   Ex_Output->hIOP_Fin4_Hz = hIOP_Fin4_Hz;
//   Ex_Output->hIOP_VacuumPumpIn_Duty = hIOP_VacuumPumpIn_Duty;  
//   (void)memcpy(&Ex_Output->Bios_Sw_Input[0], &Bios_Sw_Input[0], sizeof(Bios_Sw_Input));
//   (void)memcpy(&Ex_Output->ADC_OutBuff[0], &ADC_OutBuff[0], sizeof(ADC_OutBuff));
//   (void)memcpy(&Ex_Output->BTS5180_data[0], &BTS5180_data[0], sizeof(BTS5180_data));
//   (void)memcpy(&Ex_Output->BTS5200_data[0], &BTS5200_data[0], sizeof(BTS5200_data));
//   (void)memcpy(&Ex_Output->NCV7513B_SO_data, &NCV7513B_SO_data, sizeof(NCV7513B_SO_data));
//   (void)memcpy(&Ex_Output->NCV7719_data, &NCV7719_data, sizeof(NCV7719_data));//HB
//   (void)memcpy(&Ex_Output->NCV7240B_SO_data, &NCV7240B_SO_data, sizeof(NCV7240B_SO_data));
//   (void)memcpy(&Ex_Output->FS6500_IO_Input, &INTstruct.IO_INPUT, sizeof(Ex_Output->FS6500_IO_Input));
//   Ex_Output->bswWakeSrc = bswWakeSrc;
//   //------------DHP----------------
//   Ex_Output->C_CS_En = Config_output.C_CS_En;//Config
//   Ex_Output->C_SRS_En = Config_output.C_SRS_En;
//   Ex_Output->C_EAC_En = Config_output.C_EAC_En;
//   Ex_Output->C_ECC_En = Config_output.C_ECC_En;
//   Ex_Output->C_EHU_En = Config_output.C_EHU_En;
//   Ex_Output->C_EPS_En = Config_output.C_EPS_En;
//   Ex_Output->C_ICM_En = Config_output.C_ICM_En;
//   Ex_Output->C_TMS_En = Config_output.C_TMS_En;
//   Ex_Output->C_TMS_Internal = Config_output.C_TMS_Internal;
//   Ex_Output->C_CC_En = Config_output.C_CC_En;
//   Ex_Output->C_Booster_En = Config_output.C_Booster_En;
//   Ex_Output->C_VacuumPump_En = Config_output.C_VacuumPump_En;
//   Ex_Output->VNM_TxLiphome_flg = NM_output.VNM_TxLiphome_flg;//NM
//   Ex_Output->VNM_TxSleepInd_flg = NM_output.VNM_TxSleepInd_flg;
//   Ex_Output->b1_M_TQM_TqArbitration = TQM_output.b1_M_TQM_TqArbitration;//TQM
//   Ex_Output->TQM_VehSpd = TQM_output.TQM_VehSpd;
//   Ex_Output->TQM_EPBAppliedReq = TQM_output.TQM_EPBAppliedReq;
//   //----------------------INP
//   Ex_Output->VINP_BMSErrNum = INP_output.CANBMS_signal.VINP_BMSErrNum;
//   Ex_Output->VINP_IgnitionOn_flg = INP_output.Hardwire_signal.VINP_IgnitionOn_flg;
//   Ex_Output->VINP_MCUIGBTT_C = INP_output.CANMCU_signal.VINP_MCUIGBTT_C;
//   Ex_Output->VINP_MCUElecMotT_C = INP_output.CANMCU_signal.VINP_MCUElecMotT_C;
//   Ex_Output->VINP_MCUT_C = INP_output.CANMCU_signal.VINP_MCUT_C;
//   Ex_Output->VINP_DCDCFltRnk_enum = INP_output.CANDCDC_signal.VINP_DCDCFltRnk_enum;
//   Ex_Output->VINP_OBCFltRnk_enum = INP_output.CANOBC_signal.VINP_OBCFltRnk_enum;
//   Ex_Output->VINP_MCUFltRnk_enum = INP_output.CANMCU_signal.VINP_MCUFltRnk_enum;
//   Ex_Output->VINP_MCUDcU_V = INP_output.CANMCU_signal.VINP_MCUDcU_V;
//   Ex_Output->VINP_MCUDcCrrt_A = INP_output.CANMCU_signal.VINP_MCUDcCrrt_A;
//   Ex_Output->MCUHWCurrOverErr = INP_output.CANMCU_signal.MCUHWCurrOverErr;
//   Ex_Output->VINP_MCUPwrModErr_flg = INP_output.CANMCU_signal.VINP_MCUPwrModErr_flg;
//   Ex_Output->VINP_BMSFltRnk_enum = INP_output.CANBMS_signal.VINP_BMSFltRnk_enum;
//   Ex_Output->VINP_BMSOperMod_enum = INP_output.CANBMS_signal.VINP_BMSOperMod_enum;
//   Ex_Output->VINP_BMSBattU_V = INP_output.CANBMS_signal.VINP_BMSBattU_V;
//   Ex_Output->VINP_BMSCellUMax = INP_output.CANBMS_signal.VINP_BMSCellUMax;
//   Ex_Output->VINP_BMSCellUMin = INP_output.CANBMS_signal.VINP_BMSCellUMin;
//   Ex_Output->VINP_BMSMaxBattT = INP_output.CANBMS_signal.VINP_BMSMaxBattT;
//   Ex_Output->VINP_BMSChrgMod_enum = INP_output.CANBMS_signal.VINP_BMSChrgMod_enum;
//   Ex_Output->VINP_MCUErrNum = INP_output.CANMCU_signal.VINP_MCUErrNum;
//   Ex_Output->VINP_MCUOperMdl_enum = INP_output.CANMCU_signal.VINP_MCUOperMdl_enum;
//   Ex_Output->VINP_ABS_AbsFlgFlt = INP_output.ABS.VINP_ABS_AbsFlgFlt;
//   Ex_Output->VINP_EPS_EpasFailed = INP_output.EPB.VINP_EPS_EpasFailed;
//   Ex_Output->VINP_ABS_EbdFlgFlt = INP_output.ABS.VINP_ABS_EbdFlgFlt;
//   Ex_Output->VINP_EPB_Status = INP_output.EPB.VINP_EPB_Status;
//   Ex_Output->VINP_ABS_VehicleSpeedValid_flg = INP_output.ABS.VINP_ABS_VehicleSpeedValid_flg;
//   Ex_Output->VINP_MotTqRealValid_flg = INP_output.CANMCU_signal.VINP_MotTqRealValid_flg;
//   Ex_Output->VINP_MCUElecMotSpdValid_flg = INP_output.CANMCU_signal.VINP_MCUElecMotSpdValid_flg;
//   Ex_Output->VINP_BMSBattUOverU = INP_output.CANBMS_signal.VINP_BMSBattUOverU;
//   Ex_Output->VINP_BMSBattUUnderU = INP_output.CANBMS_signal.VINP_BMSBattUUnderU;
//   Ex_Output->VINP_BMSCellUMaxOverU = INP_output.CANBMS_signal.VINP_BMSCellUMaxOverU;
//   Ex_Output->VINP_BMSCellUMinUnderU = INP_output.CANBMS_signal.VINP_BMSCellUMinUnderU;
//   Ex_Output->VINP_BMSMaxBattTOverT = INP_output.CANBMS_signal.VINP_BMSMaxBattTOverT;
//   Ex_Output->VINP_ESP_ESPFailStatus = INP_output.ABS.VINP_ESP_ESPFailStatus;
//   Ex_Output->VINP_SlowChargeAwakeActive_flg = INP_output.Hardwire_signal.VINP_SlowChargeAwakeActive_flg;
//   Ex_Output->VINP_FastChargeAwakeActiveIn_flg = INP_output.Hardwire_signal.VINP_FastChargeAwakeActiveIn_flg;
//   Ex_Output->VINP_ICM_VehSpdChkInvalidFlt_flg = INP_output.ICM.VINP_ICM_VehSpdChkInvalidFlt_flg;
//   Ex_Output->VINP_PEPS_PDU = INP_output.PEPS.VINP_PEPS_PDU;
//   Ex_Output->VINP_GearOut_enum = INP_output.Hardwire_signal.VINP_GearOut_enum;
//   Ex_Output->VINP_AccelPedal_per = INP_output.Hardwire_signal.VINP_AccelPedal_per;
//   Ex_Output->VINP_BrkLightSwitchActive_flg = INP_output.Hardwire_signal.VINP_BrkLightSwitchActive_flg;
//   //----------------------
//   Ex_Output->VPEPS_Result_enum = PEPS_output.VPEPS_Result_enum;//PEPS
//   Ex_Output->u1_M_SPDCtl_CRUISEDiagError_enum = SPDCtl_output.u1_M_SPDCtl_CRUISEDiagError_enum;//SPDCtl
//   Ex_Output->ENM_BMSMaxDchaPwrFlt_flg = ENM_output.ENM_BMSMaxDchaPwrFlt_flg;//ENM
//   Ex_Output->VCHRG_ChrgStsLampReq_flg = CHRG_output.VCHRG_ChrgStsLampReq_flg;//CHRG
//   Ex_Output->VCHRG_VCUChrgAllwd_flg = CHRG_output.VCHRG_VCUChrgAllwd_flg;
//   Ex_Output->TMM_WaterPumpEnReq_flg = TMM_output.TMM_WaterPumpEnReq_flg;//TMM
//   Ex_Output->TMM_VCUChrgReqLimFac_enum = TMM_output.TMM_VCUChrgReqLimFac_enum;
//   Ex_Output->TMM_InvalidBattReq = TMM_output.TMM_InvalidBattReq;
//   Ex_Output->VPMM_PTReady_flg = PMM_output.VPMM_PTReady_flg;//PMM
//   Ex_Output->VPMM_UpToHVMode_flg = PMM_output.VPMM_UpToHVMode_flg;
//   Ex_Output->VPMM_LVEna = PMM_output.VPMM_LVEna;
//   Ex_Output->VPMM_LVUpTimeout_flg = PMM_output.VPMM_LVUpTimeout_flg;
//   Ex_Output->VPMM_HVUpTimeout_flg = PMM_output.VPMM_HVUpTimeout_flg;
//   Ex_Output->VPMM_HVActiveTimeout_flg = PMM_output.VPMM_HVActiveTimeout_flg;
//   Ex_Output->VPMM_HVDownTimeout_flg = PMM_output.VPMM_HVDownTimeout_flg;
//   Ex_Output->VPMM_MCUDischargeTimeout_flg = PMM_output.VPMM_MCUDischargeTimeout_flg;
//   Ex_Output->VPMM_LVUpBMSPwrUpAllwTimeout_flg = PMM_output.VPMM_LVUpBMSPwrUpAllwTimeout_flg;
//   Ex_Output->VPMM_LVUpBMSTimeout_flg = PMM_output.VPMM_LVUpBMSTimeout_flg;
//   Ex_Output->VPMM_LVUpDCDCTimeout_flg = PMM_output.VPMM_LVUpDCDCTimeout_flg;
//   Ex_Output->VPMM_LVUpMCUTimeout_flg = PMM_output.VPMM_LVUpMCUTimeout_flg;
//   Ex_Output->VPMM_MCUHVActiveTimeout_flg = PMM_output.VPMM_MCUHVActiveTimeout_flg;
//   Ex_Output->VPMM_HVDCDCActiveTimeout_flg = PMM_output.VPMM_HVDCDCActiveTimeout_flg;
//   Ex_Output->VPMM_BMSModError = PMM_output.VPMM_BMSModError;
//   Ex_Output->VPMM_MCUModError = PMM_output.VPMM_MCUModError;
//   Ex_Output->VPMM_DCDCModError = PMM_output.VPMM_DCDCModError;
//   Ex_Output->VPMM_MCUExitTqlTimeout_flg = PMM_output.VPMM_MCUExitTqlTimeout_flg;
//   Ex_Output->VPMM_DCDCStopworkTimeout_flg = PMM_output.VPMM_DCDCStopworkTimeout_flg;
//   Ex_Output->VPMM_VehSts_enum = PMM_output.VPMM_VehSts_enum;
//   memcpy(&Ex_Output->Hardwire_Inputs,&HALI_output.Hardwire_Inputs,sizeof(HALI_Hardwire));//HALI
//   Ex_Output->VHALI_SRS_CrashOutputStatus = HALI_output.CAN_Inputs.HALI_SRS.VHALI_SRS_CrashOutputStatus;
//   Ex_Output->VHALI_BMSChrgSts = HALI_output.CAN_Inputs.HALI_BMS.VHALI_BMSChrgSts;
//   Ex_Output->VHALI_MotTqReal = HALI_output.CAN_Inputs.HALI_MCU.VHALI_MotTqReal;
//   Ex_Output->VHALI_MCUIGBTT = HALI_output.CAN_Inputs.HALI_MCU.VHALI_MCUIGBTT;
//   Ex_Output->VHALI_MCUElecMotT = HALI_output.CAN_Inputs.HALI_MCU.VHALI_MCUElecMotT;
//   Ex_Output->VHALI_MCUElecMotSpd = HALI_output.CAN_Inputs.HALI_MCU.VHALI_MCUElecMotSpd;
//   Ex_Output->VHALI_BMSSOC = HALI_output.CAN_Inputs.HALI_BMS.VHALI_BMSSOC;
//   Ex_Output->VHALI_BMSBattU = HALI_output.CAN_Inputs.HALI_BMS.VHALI_BMSBattU;
//   Ex_Output->VHALI_BMSBattI = HALI_output.CAN_Inputs.HALI_BMS.VHALI_BMSBattI;
//   Ex_Output->VHALI_BMSAvrgBattT = HALI_output.CAN_Inputs.HALI_BMS.VHALI_BMSAvrgBattT;
//   Ex_Output->VHALI_ClstrOdo = HALI_output.CAN_Inputs.HALI_EHU.VHALI_ClstrOdo;
//   Ex_Output->VHALI_TBOX_TimeYear__1 = HALI_output.CAN_Inputs.HALI_TBOX.VHALI_TBOX_TimeYear;
//   Ex_Output->VHALI_TBOX_TimeMonth__1 = HALI_output.CAN_Inputs.HALI_TBOX.VHALI_TBOX_TimeMonth;
//   Ex_Output->VHALI_TBOX_TimeDate__1 = HALI_output.CAN_Inputs.HALI_TBOX.VHALI_TBOX_TimeDate;
//   Ex_Output->VHALI_TBOX_TimeHour__1 = HALI_output.CAN_Inputs.HALI_TBOX.VHALI_TBOX_TimeHour;
//   Ex_Output->VHALI_TBOX_TimeMinute__1 = HALI_output.CAN_Inputs.HALI_TBOX.VHALI_TBOX_TimeMinute;
//   Ex_Output->VHALI_TBOX_TimeSecond__1 = HALI_output.CAN_Inputs.HALI_TBOX.VHALI_TBOX_TimeSecond;
//   Ex_Output->VHALI_BMSErrNum__1 = HALI_output.CAN_Inputs.HALI_BMS.VHALI_BMSErrNum;
//   Ex_Output->VHALI_MCUErrNum__1 = HALI_output.CAN_Inputs.HALI_MCU.VHALI_MCUErrNum;
//   Ex_Output->VHALI_EPB_Status = HALI_output.CAN_Inputs.HALI_EPB.VHALI_EPB_Status;
//   //BSW
//   Ex_Output->VHALI_ICM_234_MsgTicks = VHALI_ICM_234_MsgTicks ;
//   Ex_Output->VHALI_EHU_345_MsgTicks =  VHALI_EHU_345_MsgTicks;
//   Ex_Output->hIOP_LSFaultCode_enum_POR = hIOP_LSFaultCode_enum_POR ;
//   Ex_Output->VHALI_EAC_34A_MsgTicks =  VHALI_EAC_34A_MsgTicks;
//   Ex_Output->VHALI_XBS_241_MsgTicks =  VHALI_XBS_241_MsgTicks;
//   Ex_Output->VHALI_ICM_235_MsgTicks =  VHALI_ICM_235_MsgTicks;
//   Ex_Output->hIOP_FastChargeAwake_flg = hIOP_FastChargeAwake_flg ;
//   Ex_Output->hIOP_SlowChargeAwake_flg =  hIOP_SlowChargeAwake_flg;
//   Ex_Output->hIOP_MainRelay_flg =  hIOP_MainRelay_flg;
//   Ex_Output->hIOP_GearSwitch1_flg = hIOP_GearSwitch1_flg ;
//   Ex_Output->hIOP_GearSwitch2_flg =  hIOP_GearSwitch2_flg;
//   Ex_Output->hIOP_GearSwitch3_flg =  hIOP_GearSwitch3_flg;
//   Ex_Output->hIOP_GearSwitch4_flg = hIOP_GearSwitch4_flg ;
//   Ex_Output->hIOP_BrkLightSwitch1_flg = hIOP_BrkLightSwitch1_flg ;
//   Ex_Output->hIOP_BrkLightSwitch2_flg = hIOP_BrkLightSwitch2_flg ;
//   Ex_Output->hIOP_LSpdFan_flg = hIOP_LSpdFan_flg ;
//   Ex_Output->hIOP_HSpdFan_flg =  hIOP_HSpdFan_flg;
//   Ex_Output->hIOP_WaterPump_flg =  hIOP_WaterPump_flg;
//   Ex_Output->VHALI_HWVersion =  VHALI_HWVersion;
//   Ex_Output->hIOP_HSFaultCode_enum_POR = hIOP_HSFaultCode_enum_POR ;
//   //Ex_Output->gbDidDataCorrect = gbDidDataCorrect ;
//   //Ex_Output->gbCalDataCorrect = gbCalDataCorrect ;
//   Ex_Output->CruiseKeyFaultCode = CruiseKeyFaultCode ;
// ///  Ex_Output->DisRecordDTC = DisRecordDTC ;
//   Ex_Output->VHALO_MCURelayActive_flg = VHALO_MCURelayActive_flg;
//   Ex_Output->PTBusOffConfirmedFlag = PTBusOffConfirmedFlag ;
//   //Ex_Output->HistDataCheckFaliedFlag =  HistDataCheckFaliedFlag;
//   Ex_Output->VCHRG_ChrgStopLockError_flg = VCHRG_ChrgStopLockError_flg ;
//   Ex_Output->VCHRG_OBCWakeupTimeout_flg = VCHRG_OBCWakeupTimeout_flg ;
//   //Ex_Output->AppDataCheckFaliedFlag = AppDataCheckFaliedFlag ;
//   Ex_Output->VCHRG_ChrgFault_flg =  VCHRG_ChrgFault_flg;
//   Ex_Output->VCHRG_ChrgModeInvalid_flg = VCHRG_ChrgModeInvalid_flg ;
//   Ex_Output->VCHRG_ChrgModeAbnormal_flg =  VCHRG_ChrgModeAbnormal_flg;
//   Ex_Output->VCHRG_ChrgLockCheckTimeout_flg = VCHRG_ChrgLockCheckTimeout_flg ;
//   Ex_Output->VCHRG_ShiftKnobCheckTimeout_flg = VCHRG_ShiftKnobCheckTimeout_flg ;
//   Ex_Output->VCHRG_ChrgStopAbnormal_flg =  VCHRG_ChrgStopAbnormal_flg;
//   Ex_Output->VCHRG_ChrgStopOperTimeout_flg =  VCHRG_ChrgStopOperTimeout_flg;
//   Ex_Output->VCHRG_ChrgStopModeInvalid_flg = VCHRG_ChrgStopModeInvalid_flg ;
//   //message tick
//   Ex_Output->VHAL_VCUCanTickCount = VHAL_VCUCanTickCount;
//   Ex_Output->VHAL_VCUPTCanTickCount = VHAL_VCUPTCanTickCount;
//   Ex_Output->VHAL_VCUBodyCanTickCount = VHAL_VCUBodyCanTickCount;
//   Ex_Output->VHALI_BMS_113_MsgTicks = VHALI_BMS_113_MsgTicks;
//   Ex_Output->VHALI_BMS_213_MsgTicks = VHALI_BMS_213_MsgTicks;
//   Ex_Output->VHALI_BMS_233_MsgTicks = VHALI_BMS_233_MsgTicks;
//   Ex_Output->VHALI_BMS_303_MsgTicks = VHALI_BMS_303_MsgTicks;
//   Ex_Output->VHALI_BMS_313_MsgTicks = VHALI_BMS_313_MsgTicks;
//   Ex_Output->VHALI_BMS_323_MsgTicks = VHALI_BMS_323_MsgTicks;
//   Ex_Output->VHALI_BMS_377_MsgTicks = VHALI_BMS_377_MsgTicks;
//   Ex_Output->VHALI_BMS_513_MsgTicks = VHALI_BMS_513_MsgTicks;
//   Ex_Output->VHALI_BMS_633_MsgTicks = VHALI_BMS_633_MsgTicks;
//   Ex_Output->VHALI_MCU_115_MsgTicks = VHALI_MCU_115_MsgTicks;
//   Ex_Output->VHALI_MCU_125_MsgTicks = VHALI_MCU_125_MsgTicks;
//   Ex_Output->VHALI_MCU_215_MsgTicks = VHALI_MCU_215_MsgTicks;
//   Ex_Output->VHALI_MCU_515_MsgTicks = VHALI_MCU_515_MsgTicks;
//   Ex_Output->VHALI_DCDC_231_MsgTicks = VHALI_DCDC_231_MsgTicks;
//   Ex_Output->VHALI_DCDC_251_MsgTicks = VHALI_DCDC_251_MsgTicks;
//   Ex_Output->VHALI_OBC_311_MsgTicks = VHALI_OBC_311_MsgTicks;
//   Ex_Output->VHALI_OBC_321_MsgTicks = VHALI_OBC_321_MsgTicks;
//   Ex_Output->VHALI_OBC_331_MsgTicks = VHALI_OBC_331_MsgTicks;
//   Ex_Output->VHALI_PTC_5DA_MsgTicks = VHALI_PTC_5DA_MsgTicks;
//   Ex_Output->VHALI_ECC_33C_MsgTicks = VHALI_ECC_33C_MsgTicks;
//   Ex_Output->VHALI_ECC_34C_MsgTicks = VHALI_ECC_34C_MsgTicks;
//   Ex_Output->VHALI_ECC_35C_MsgTicks = VHALI_ECC_35C_MsgTicks;
//   Ex_Output->VHALI_PEPS_108_MsgTicks = VHALI_PEPS_108_MsgTicks;
//   Ex_Output->VHALI_PEPS_103_MsgTicks = VHALI_PEPS_103_MsgTicks;
//   Ex_Output->VHALI_SRS_050_MsgTicks = VHALI_SRS_050_MsgTicks;
//   Ex_Output->VHALI_ABS_232_MsgTicks = VHALI_ABS_232_MsgTicks;
//   Ex_Output->VHALI_ABS_237_MsgTicks = VHALI_ABS_237_MsgTicks;
//   Ex_Output->VHALI_GW_217_MsgTicks = VHALI_GW_217_MsgTicks;
//   Ex_Output->VHALI_GW_522_MsgTicks = VHALI_GW_522_MsgTicks;
//   Ex_Output->VHALI_TPMS_317_MsgTicks = VHALI_TPMS_317_MsgTicks;
//   Ex_Output->VHALI_TPMS_3A2_MsgTicks = VHALI_TPMS_3A2_MsgTicks;
//   Ex_Output->VHALI_EAC_349_MsgTicks = VHALI_EAC_349_MsgTicks;
//   Ex_Output->VHALI_TBOX_298_MsgTicks = VHALI_TBOX_298_MsgTicks;
//   Ex_Output->VHALI_EPS_2A0_MsgTicks = VHALI_EPS_2A0_MsgTicks;
//   Ex_Output->VHALI_EPS_180_MsgTicks = VHALI_EPS_180_MsgTicks;
//   Ex_Output->VHALI_ECC_36C_MsgTicks = VHALI_ECC_36C_MsgTicks;
//   Ex_Output->VHALI_BMS_653_MsgTicks = VHALI_BMS_653_MsgTicks;
//   Ex_Output->VHALI_PEPS_282_MsgTicks = VHALI_PEPS_282_MsgTicks;
//   Ex_Output->VHALI_BMS_603_MsgTicks = VHALI_BMS_603_MsgTicks;
//   Ex_Output->VHALI_PTC_5DB_MsgTicks = VHALI_PTC_5DB_MsgTicks;
//   Ex_Output->VHALI_TBOX_296_MsgTicks = VHALI_TBOX_296_MsgTicks;
//   Ex_Output->VHALI_GW_405_MsgTicks = VHALI_GW_405_MsgTicks;
//   Ex_Output->VHALI_TMS_2C0_MsgTicks = VHALI_TMS_2C0_MsgTicks;
//   Ex_Output->VHALI_TMS_2C1_MsgTicks = VHALI_TMS_2C1_MsgTicks;
//   Ex_Output->VHALI_TMS_2C2_MsgTicks = VHALI_TMS_2C2_MsgTicks;
//   Ex_Output->VHALI_TMS_2C3_MsgTicks = VHALI_TMS_2C3_MsgTicks;
//   Ex_Output->VHALI_WPTC_2F0_MsgTicks = VHALI_WPTC_2F0_MsgTicks;
//   Ex_Output->VHALI_TMS_325_MsgTicks = VHALI_TMS_325_MsgTicks;
//   Ex_Output->VHALI_WPTC_566_MsgTicks = VHALI_WPTC_566_MsgTicks;
//   Ex_Output->VHALI_BMS_304_MsgTicks = VHALI_BMS_304_MsgTicks;
//   Ex_Output->VHALI_BMS_613_MsgTicks = VHALI_BMS_613_MsgTicks;
//   Ex_Output->VHALI_ABS_229_MsgTicks = VHALI_ABS_229_MsgTicks;
//   Ex_Output->VHALI_BMS_623_MsgTicks = VHALI_BMS_623_MsgTicks;

//   /*added for CR 1519*/
//   (void)memcpy(Ex_Output->AuthFailedData, AuthFailData, sizeof(AuthFailData));     /*CR 1519: copy the auth failure internal data from core1 to core 0*/
//   /*added for CR 1519*/
//   Ex_Output->CAN3_BusOffState = CAN3_BusOffState; /*for bug 1578*/
//  Ex_Output->TQM_GearDisp = TQM_output.TQM_GearDisp ;   /*for bug 1609*/
//  /*BTK and ESCL*/
//   Ex_Output->SSBSync = SSB_SyncCorrect;
//   Ex_Output->ING1_FeedCorrect = IGN1_FeedVoltCorrect;
//   Ex_Output->ING2_FeedCorrect = IGN2_FeedVoltCorrect;
//   Ex_Output->EsclRslt = gblEsclRslt;

//   Ex_Output->EsclLinCommFailed = EsclLinCommFailed;
//   Ex_Output->EsclStatus = EsclStatus;
//   Ex_Output->EsclErrorCode = EsclErrorCode;

//   Ex_Output->VHALI_DCDCT = HALI_output.CAN_Inputs.HALI_DCDC.VHALI_DCDCT;//bug1823

//   Ex_Output->VINP_CruiseKeySet_flg = VINP_CruiseKeySet_flg; /*CR1845*/
//   Ex_Output->VINP_CruiseKeyRes_flg = VINP_CruiseKeyRes_flg;

//   Ex_Output->VCHRG_OBCSleepTimeout_flg = VCHRG_OBCSleepTimeout_flg; /*CR1853*/

//   Ex_Output->C_YK19_En = Config_output.C_YK19_En ;

//   Ex_Output->ENM_Batt_EnergyToolow = ENM_output.ENM_Batt_EnergyToolow;/*CR1927*/

//   Ex_Output->C_ESCL_En = Config_output.C_ESCL_En;
//   Ex_Output->C_PMS_En = Config_output.C_PMS_En;

//   Ex_Output->VINP_BMSMaxDchaPwr_kW = INP_output.CANBMS_signal.VINP_BMSMaxDchaPwr_kW;/*CR2097*/

//   Ex_Output->VBTK_SleepAllw_flg = VBTK_SleepAllw_flg;
 }


















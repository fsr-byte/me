/*
 * CAN_DBC_Lib.h
 *
 *  Created on: 2018年10月8日
 *      Author: helei
 */

#ifndef HAL_CAN_DBC_LIB_H_
#define HAL_CAN_DBC_LIB_H_

#include "typedefs.h"
#include "BASE_Global.h"
#include "NVM.h"

#ifdef __CAN_DBC_LIB_GLOBALS__
#define __CAN_DBC_LIB_EXTERN__
#else
#define __CAN_DBC_LIB_EXTERN__  extern
#endif

/* 接收报文的数据声明 */
__CAN_DBC_LIB_EXTERN__ uint8_t Receive_Alive;

__CAN_DBC_LIB_EXTERN__ uint32_t VHALI_BMS_113_MsgTicks ;/*BMS_113的报文计数*/

__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_BMS113CycCntr;
__CAN_DBC_LIB_EXTERN__ uint16_t VHALI_BMSBattI;
__CAN_DBC_LIB_EXTERN__ uint16_t VHALI_BMSBattU;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_BMSCRCChk113;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_BMSCrashSts;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_BMSFltRnk;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_BMSHVILSts;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_BMSInsulationHVLoadErr;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_BMSInsulationIntrErr;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_BMSInsulationSts;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_BMSOBCOperModReq;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_BMSOperMod;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_BMSPwrUpAllw;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_BMSRlyWlddErr;
__CAN_DBC_LIB_EXTERN__ uint16_t VHALI_BMSSOC;

__CAN_DBC_LIB_EXTERN__ uint32_t VHALI_BMS_213_MsgTicks ;/*BMS_213的报文计数*/

__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_BMS213CycCntr;
__CAN_DBC_LIB_EXTERN__ uint16_t VHALI_BMSBattExU;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_BMSCRCChk213;
__CAN_DBC_LIB_EXTERN__ uint16_t VHALI_BMSMaxChrgU;
__CAN_DBC_LIB_EXTERN__ uint16_t VHALI_BMSMinDchaIU;

__CAN_DBC_LIB_EXTERN__ uint32_t VHALI_BMS_233_MsgTicks ;/*BMS_233的报文计数*/

__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_BMS233CycCntr;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_BMSCRCChk233;
__CAN_DBC_LIB_EXTERN__ uint16_t VHALI_BMSMaxChrgI;
__CAN_DBC_LIB_EXTERN__ uint16_t VHALI_BMSMaxChrgPwr;
__CAN_DBC_LIB_EXTERN__ uint16_t VHALI_BMSMaxDchaI;
__CAN_DBC_LIB_EXTERN__ uint16_t VHALI_BMSMaxDchaPwr;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_BMSDateMonitoringReq;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_BMSDateMonitoringt;

__CAN_DBC_LIB_EXTERN__ uint32_t VHALI_BMS_305_MsgTicks ;/*BMS_305的报文计数*/
__CAN_DBC_LIB_EXTERN__ uint32_t VHALI_BMS_306_MsgTicks ;/*BMS_306的报文计数*/
__CAN_DBC_LIB_EXTERN__ uint32_t VHALI_BMS_303_MsgTicks ;/*BMS_303的报文计数*/

__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_BMS303CycCntr;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_BMSCRCChk303;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_BMSChrgErrInfo;
__CAN_DBC_LIB_EXTERN__ uint16_t VHALI_BMSChrgIReq;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_BMSChrgMod;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_BMSChrgSts;
__CAN_DBC_LIB_EXTERN__ uint16_t VHALI_BMSChrgUReq;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_BMSDCChrgRlySts;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_BMSOBCHeatModeCtrl;
__CAN_DBC_LIB_EXTERN__ uint16_t VHALI_BMSOBCMaxChrgPwrAvl;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_BMSIChrgEna;

__CAN_DBC_LIB_EXTERN__ uint32_t VHALI_BMS_313_MsgTicks ;/*BMS_313的报文计数*/

__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_BMS313CycCntr;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_BMSAvrgBattT;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_BMSBattIntrHeatActv;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_BMSBattIntrHeatReq;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_BMSCRCChk313;
__CAN_DBC_LIB_EXTERN__ uint16_t VHALI_BMSIsolationR;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_BMSMILReq;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_BMSMaxBattT;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_BMSMinBattT;
__CAN_DBC_LIB_EXTERN__ uint16_t VHALI_BMSPredChrgTi;

__CAN_DBC_LIB_EXTERN__ uint32_t VHALI_BMS_323_MsgTicks ;/*BMS_323的报文计数*/

__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_BMSEquilnSts;
__CAN_DBC_LIB_EXTERN__ uint16_t VHALI_BMSRmaingCpby;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_BMSSOCMax;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_BMSSOCMin;
__CAN_DBC_LIB_EXTERN__ uint16_t VHALI_BMSSOH;

__CAN_DBC_LIB_EXTERN__ uint32_t VHALI_BMS_377_MsgTicks ;/*BMS_377的报文计数*/

__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_BMSBattHeatI;
__CAN_DBC_LIB_EXTERN__ uint16_t VHALI_BMSCC2SngR;
__CAN_DBC_LIB_EXTERN__ uint16_t VHALI_BMSCCSngR;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_BMSErrAmnt;
__CAN_DBC_LIB_EXTERN__ uint16_t VHALI_BMSErrNum;

__CAN_DBC_LIB_EXTERN__ uint32_t VHALI_BMS_513_MsgTicks ;/*BMS_513的报文计数*/

__CAN_DBC_LIB_EXTERN__ uint16_t VHALI_BMSCalDataVers;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_BMSHwVers;
__CAN_DBC_LIB_EXTERN__ uint16_t VHALI_BMSManfctCode;
__CAN_DBC_LIB_EXTERN__ uint16_t VHALI_BMSSwVers;

__CAN_DBC_LIB_EXTERN__ uint32_t VHALI_BMS_603_MsgTicks ;/*BMS_603的报文计数*/

__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_BMSBattNumTot;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_BMSCellNumTot;

__CAN_DBC_LIB_EXTERN__ uint32_t VHALI_BMS_633_MsgTicks ;/*BMS_633的报文计数*/

__CAN_DBC_LIB_EXTERN__ uint16_t VHALI_BMSCellUMax;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_BMSCellUMaxBattNum;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_BMSCellUMaxCellNum;
__CAN_DBC_LIB_EXTERN__ uint16_t VHALI_BMSCellUMin;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_BMSCellUMinBattNum;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_BMSCellUMinCellNum;

__CAN_DBC_LIB_EXTERN__ uint32_t VHALI_BMS_653_MsgTicks ;/*BMS_633的报文计数*/
__CAN_DBC_LIB_EXTERN__ uint16_t VHALI_BMSBattResidPwr;

__CAN_DBC_LIB_EXTERN__ uint16_t VHALI_BMSBattRatedPwr ;
__CAN_DBC_LIB_EXTERN__ uint16_t VHALI_BMSCellUMinUnderU ;
__CAN_DBC_LIB_EXTERN__ uint32_t VHALI_BMS_623_MsgTicks ;
__CAN_DBC_LIB_EXTERN__ uint16_t VHALI_BMSBattUOverU ;
__CAN_DBC_LIB_EXTERN__ uint16_t VHALI_BMSBattUUnderU ;
__CAN_DBC_LIB_EXTERN__ uint16_t VHALI_BMSCellUMaxOverU ;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_BMSMaxBattTOverT ;

__CAN_DBC_LIB_EXTERN__ uint32_t VHALI_MCU_115_MsgTicks ;/*MCU_115的报文计数*/

__CAN_DBC_LIB_EXTERN__ uint16_t VHALI_MCUElecMotSpd;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_MCUID153CycCntr;
__CAN_DBC_LIB_EXTERN__ uint16_t VHALI_MCUMaxAvlTq;
__CAN_DBC_LIB_EXTERN__ uint16_t VHALI_MCUMinAvlTq;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_MCUOperMdl;
__CAN_DBC_LIB_EXTERN__ uint16_t VHALI_MotTqReal;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_Spdvalidflag;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_Trqvalidflag;

__CAN_DBC_LIB_EXTERN__ uint32_t VHALI_MCU_125_MsgTicks ;/*MCU_125的报文计数*/

__CAN_DBC_LIB_EXTERN__ uint16_t VHALI_MCUDcCrrt;
__CAN_DBC_LIB_EXTERN__ uint16_t VHALI_MCUDcU;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_MCUFltRnk;
__CAN_DBC_LIB_EXTERN__ uint16_t VHALI_MCUPhaCrrt;

__CAN_DBC_LIB_EXTERN__ uint32_t VHALI_MCU_215_MsgTicks ;/*MCU_215的报文计数*/

__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_Hardware_Ver;
__CAN_DBC_LIB_EXTERN__ uint16_t VHALI_MCUElecMotT;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_MCUErrAmnt;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_MCUErrNum;
__CAN_DBC_LIB_EXTERN__ uint16_t VHALI_MCUIGBTT;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_MCUMotNum;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_MCUMotNumTot;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_MCUMotSts;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_MCUT;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_Motor_Ver;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_Software_Ver;

__CAN_DBC_LIB_EXTERN__ uint32_t VHALI_MCU_515_MsgTicks ;/*MCU_515的报文计数*/

__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_MCU131CRCErr;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_MCUCANComErr;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_MCUCRCElecMotSpdErr;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_MCUCRCRealTqErr;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_MCUDCUShoCirc;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_MCUDcCrrtSnsrRatiErr;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_MCUDcUOverUErr;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_MCUDcUSnsrRatiErr;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_MCUDcUUnderUErr;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_MCUDischrgErr;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_MCUElecMotOverCrrtErr;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_MCUElecMotOverSpdErr;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_MCUElecMotOverTErr;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_MCUElecMotReslvErr;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_MCUElecMotStopTurnErr;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_MCUElecMotTSnsrRatiErr;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_MCUElecMotTqErr;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_MCUElecMotUnderTErr;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_MCUHVLockErr;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_MCUIGBTOverTErr;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_MCUIGBTTSnsrRatiErr;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_MCULowBatUnderUErr;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_MCUOverTErr;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_MCUPhaACrrtSnsrRatiErr;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_MCUPhaBCrrtSnsrRatiErr;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_MCUPhaCCrrtSnsrRatiErr;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_MCUPrechrgErr;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_MCUPwrModErr;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_MCUPwrModUnderUErr;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_MCUSystemErr;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_MCUTSnsrRatiErr;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_MCUUndefineErr2;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_MCUUndefineErr3;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_VMS_EN_Err;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_MCUHWCurrOverErr;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_McuCurrentSensorErr_A;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_McuCurrentSensorErr_C;

__CAN_DBC_LIB_EXTERN__ uint32_t VHALI_DCDC_231_MsgTicks ;/*DCDC_231的报文计数*/

__CAN_DBC_LIB_EXTERN__ uint16_t VHALI_DCDCAvlOutpPwr;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_DCDCErrCANCom;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_DCDCFltRnk;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_DCDCHwFltFlg;
__CAN_DBC_LIB_EXTERN__ uint16_t VHALI_DCDCInpU;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_DCDCOperMod;
__CAN_DBC_LIB_EXTERN__ uint16_t VHALI_DCDCOutpCrrt;
__CAN_DBC_LIB_EXTERN__ uint16_t VHALI_DCDCOutpU;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_DCDCOverInpU;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_DCDCOverOutpCrrt;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_DCDCOverOutpPwr;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_DCDCOverOutpU;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_DCDCOverT;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_DCDCShoCircOutp;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_DCDCUnderInpU;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_DCDCUnderOutpU;

__CAN_DBC_LIB_EXTERN__ uint32_t VHALI_DCDC_251_MsgTicks ;/*DCDC_251的报文计数*/

__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_DCDCIInput;
__CAN_DBC_LIB_EXTERN__ uint32_t VHALI_DCDCSwVers;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_DCDCT;

__CAN_DBC_LIB_EXTERN__ uint32_t VHALI_OBC_311_MsgTicks ;/*OBC_311的报文计数*/

__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_OBC311CycCntr;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_OBCChrgSts;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_OBCFltRnk;
__CAN_DBC_LIB_EXTERN__ uint16_t VHALI_OBCMaxChrgOutpIAvl;
__CAN_DBC_LIB_EXTERN__ uint16_t VHALI_OBCMaxChrgOutpPwrAvl;
__CAN_DBC_LIB_EXTERN__ uint16_t VHALI_OBCMaxChrgOutpUAvl;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_OBCS2Stus;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_OBCVehInletT;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_PlugLockStatus;

__CAN_DBC_LIB_EXTERN__ uint32_t VHALI_OBC_321_MsgTicks ;/*OBC_321的报文计数*/

__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_CPSts;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_OBC321CycCntr;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_OBCCPValue;

__CAN_DBC_LIB_EXTERN__ uint32_t VHALI_OBC_331_MsgTicks ;/*OBC_331的报文计数*/

__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_OBC331CycCntr;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_OBCCANErr;
__CAN_DBC_LIB_EXTERN__ uint16_t VHALI_OBCChrgDcI;
__CAN_DBC_LIB_EXTERN__ uint16_t VHALI_OBCChrgDcU;
__CAN_DBC_LIB_EXTERN__ uint16_t VHALI_OBCChrgInpAcI;
__CAN_DBC_LIB_EXTERN__ uint16_t VHALI_OBCChrgInpAcU;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_OBCHwErr;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_OBCInpIOver;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_OBCInpUOver;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_OBCInpUUnder;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_OBCOutpIOver;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_OBCOutpUOver;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_OBCOutpUUnder;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_OBCT;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_OBCTOvrErr;

__CAN_DBC_LIB_EXTERN__ uint32_t VHALI_PTC_5DA_MsgTicks ;/*PTC_5DA的报文计数*/

__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_PTC_HVOFFfault;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_PTC_HVOverfault;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_PTC_HVUnderfault;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_PTC_IGBTErr;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_PTC_IGBTOverTErr;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_PTC_IGBTTSnsrErr;
__CAN_DBC_LIB_EXTERN__ uint16_t VHALI_PTC_InVoltage;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_PTC_OverCurrfault;
__CAN_DBC_LIB_EXTERN__ uint16_t VHALI_PTC_Power;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_PTC_State;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_PTC_TempOverTErr;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_PTC_TempSnsrErr;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_PTC_Temperature;

__CAN_DBC_LIB_EXTERN__ uint32_t VHALI_ECC_34C_MsgTicks ;/*ECC_34C的报文计数*/

__CAN_DBC_LIB_EXTERN__ uint16_t VHALI_AC_AcceptPower;
__CAN_DBC_LIB_EXTERN__ uint16_t VHALI_AC_ActSpeed;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_AC_Checksum;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_AC_Command;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_AC_Counter;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_AC_SpeedSet;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_ECC_A_C_Req;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_ECC_A_C_ReqValid;

__CAN_DBC_LIB_EXTERN__ uint32_t VHALI_ECC_35C_MsgTicks ;/*ECC_35C的报文计数*/

__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_ECC_PTC_Req;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_ECC_PTC_ReqValid;
__CAN_DBC_LIB_EXTERN__ uint16_t VHALI_PTCActPower;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_PTCChecksum;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_PTCCommand;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_PTCCounter;
__CAN_DBC_LIB_EXTERN__ uint16_t VHALI_PTCTargetPwr;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_FrontDefrosterSwitch;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_RearDefrosterSwitch;

__CAN_DBC_LIB_EXTERN__ uint32_t VHALI_ECC_36C_MsgTicks ;/*ECC_36C的报文计数*/

__CAN_DBC_LIB_EXTERN__ uint16_t VHALI_PTC_MAXPower;
__CAN_DBC_LIB_EXTERN__ uint16_t VHALI_AC_MAXPower;

__CAN_DBC_LIB_EXTERN__ uint32_t VHALI_PEPS_108_MsgTicks ;/*PEPS_108的报文计数*/

__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_PEPS_EncryptedResponseByte0;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_PEPS_EncryptedResponseByte1;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_PEPS_EncryptedResponseByte2;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_PEPS_EncryptedResponseByte3;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_PEPS_EncryptedResponseByte4;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_PEPS_EncryptedResponseByte5;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_PEPS_EncryptedRsvd;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_PEPS_EncryptedStatus;

__CAN_DBC_LIB_EXTERN__ uint32_t VHALI_PEPS_103_MsgTicks ;/*PEPS_103的报文计数*/

__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_PEPS_ReAuth_Req;

__CAN_DBC_LIB_EXTERN__ uint32_t VHALI_SRS_050_MsgTicks ;/*SRS_050的报文计数*/

__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_SRS_CrashOutputStatus;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_SRS_CrashOutputStatusCheckSum;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_SRS_DriverBuckleSwitchStatus;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_SRS_FrontPsgOccupancy;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_SRS_PassengerBuckleSwitchStatus;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_SRS_RollingCounter;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_SRS_WarningLampStatus;

__CAN_DBC_LIB_EXTERN__ uint32_t VHALI_ABS_232_MsgTicks ;/*ABS_232的报文计数*/

__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_ABS_AbsCtrlActv;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_ABS_AbsFlgFlt;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_ABS_Checksum;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_ABS_EbdFlgFlt;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_ABS_RollingCounter;
__CAN_DBC_LIB_EXTERN__ uint16_t VHALI_ABS_VehicleSpeed;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_ABS_VehicleSpeedValid;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_NO_Evflag;

__CAN_DBC_LIB_EXTERN__ uint32_t VHALI_GW_217_MsgTicks ;/*GW_217的报文计数*/

__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_EPB_Acceleration_X;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_EPB_Brake_Lights_Requested;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_EPB_Status;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_EPS_EpasFailed;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_EPS_TorqSensorStatus;
__CAN_DBC_LIB_EXTERN__ uint16_t VHALI_SAS_SteeringAngle;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_SAS_SteeringAngleSpeed;

__CAN_DBC_LIB_EXTERN__ uint32_t VHALI_GW_522_MsgTicks ;/*GW_522的报文计数*/

__CAN_DBC_LIB_EXTERN__ uint32_t VHALI_ClstrOdo;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_EHU_AccountManagement;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_EHU_AccountType;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_EHU_DriverModel;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_EHU_EnergyRecovery;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_EHU_VoiceIdentify;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_PEPS_PDU;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_SubtotalEgyCnseRet;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_SubtotalMileagereset_A;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_SubtotalMileagereset_B;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_EHU_VehrpValid;

__CAN_DBC_LIB_EXTERN__ uint32_t VHALI_EAC_349_MsgTicks ;/*EAC_349的报文计数*/

__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_Bus_cur_ERR;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_Bus_limit;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_CAN_ERR;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_COMPBaseState;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_COMPCurr;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_COMPHeartBeat;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_COMPMotor_Temp;
__CAN_DBC_LIB_EXTERN__ uint16_t VHALI_COMPSpeed_now;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_COMPVold;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_HVolt_ERR;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_IN_Communi_ERR;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_IN_PWR_ERR;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_LVolt_ERR;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_Pha_cur_ERR;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_Pha_cur_limit;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_Pow_limit;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_Pow_over_ERR;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_Start_ERR;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_Temp_limit;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_Temp_over_ERR;

__CAN_DBC_LIB_EXTERN__ uint32_t VHALI_TBOX_298_MsgTicks ;/*TBOX_298的报文计数*/

__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_TBOX_TimeDate;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_TBOX_TimeHour;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_TBOX_TimeMinute;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_TBOX_TimeMonth;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_TBOX_TimeSecond;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_TBOX_TimeValid;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_TBOX_TimeYear;

__CAN_DBC_LIB_EXTERN__ uint32_t VHALI_GW_405h_MsgTicks ;/*GW_405h的报文计数*/

__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_GW_DestinationID;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_GW_NMAcknowledge;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_GW_NMAlive;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_GW_NMIndication;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_GW_NMLimpHome;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_GW_NMRing;

__CAN_DBC_LIB_EXTERN__ uint16_t VHALI_NMSourceID;

__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_NMDestinationID;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_NMAlive;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_NMRing;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_NMIndication;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_NMLimpHome;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_NMAcknowledge;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_BusOff_Flg;

__CAN_DBC_LIB_EXTERN__ uint32_t VHALI_BCM_410h_MsgTicks;/*BCM_410h的报文计数*/

__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_BCM_DestinationID;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_BCM_NMAcknowledge;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_BCM_NMAlive;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_BCM_NMIndication;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_BCM_NMLimpHome;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_BCM_NMRing;

__CAN_DBC_LIB_EXTERN__ uint32_t VHALI_PEPS_411h_MsgTicks;/*PEPS_411h的报文计数*/

__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_PEPS_DestinationID;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_PEPS_NMAcknowledge;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_PEPS_NMAlive;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_PEPS_NMIndication;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_PEPS_NMLimpHome;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_PEPS_NMRing;

__CAN_DBC_LIB_EXTERN__ uint32_t VHALI_EHU_412h_MsgTicks;/*EHU_412h的报文计数*/

__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_EHU_DestinationID;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_EHU_NMAcknowledge;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_EHU_NMAlive;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_EHU_NMIndication;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_EHU_NMLimpHome;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_EHU_NMRing;

__CAN_DBC_LIB_EXTERN__ uint32_t VHALI_ICM_421h_MsgTicks;/*ICM_421h的报文计数*/

__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_ICM_DestinationID;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_ICM_NMAcknowledge;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_ICM_NMAlive;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_ICM_NMIndication;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_ICM_NMLimpHome;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_ICM_NMRing;

__CAN_DBC_LIB_EXTERN__ uint32_t VHALI_TBOX_430h_MsgTicks;/*TBOX_430h的报文计数*/

__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_TBOX_DestinationID;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_TBOX_NMAcknowledge;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_TBOX_NMAlive;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_TBOX_NMIndication;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_TBOX_NMLimpHome;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_TBOX_NMRing;

__CAN_DBC_LIB_EXTERN__ uint32_t VHALI_ABS_237_MsgTicks ;/*ABS_237的报文计数*/

__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_ABS_Checksum237;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_ABS_RollingCounter237;
__CAN_DBC_LIB_EXTERN__ uint16_t VHALI_WheelSpeedPlusCounter_FL;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_WheelSpeedPlusCounter_FL_invalid;
__CAN_DBC_LIB_EXTERN__ uint8_t  VHALI_WheelSpeedPlusCounter_FL_Valid;
__CAN_DBC_LIB_EXTERN__ uint16_t VHALI_WheelSpeedPlusCounter_FR;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_WheelSpeedPlusCounter_FR_invalid;
__CAN_DBC_LIB_EXTERN__ uint8_t  VHALI_WheelSpeedPlusCounter_FR_Valid;
__CAN_DBC_LIB_EXTERN__ uint16_t VHALI_WheelSpeedPlusCounter_RL;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_WheelSpeedPlusCounter_RL_invalid;
__CAN_DBC_LIB_EXTERN__ uint8_t  VHALI_WheelSpeedPlusCounter_RL_Valid;
__CAN_DBC_LIB_EXTERN__ uint16_t VHALI_WheelSpeedPlusCounter_RR;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_WheelSpeedPlusCounter_RR_invalid;
__CAN_DBC_LIB_EXTERN__ uint8_t  VHALI_WheelSpeedPlusCounter_RR_Valid;

__CAN_DBC_LIB_EXTERN__ uint32_t VHALI_ECC_33C_MsgTicks ;/*ECC_33C的报文计数*/

__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_ECC_AutoReq;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_ECC_Blowing;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_ECC_EnvironmentalTemp;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_ECC_EvaporatorTemp;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_ECC_InterCarTemp;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_ECC_Mode;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_ECC_PM2_5;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_ECC_Rec_FreSetState;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_ECC_Sunlight;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_ECC_TempSetReq;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_ECC_RemoteACStatus;
__CAN_DBC_LIB_EXTERN__ uint32_t VHALI_TPMS_317_MsgTicks ;/*TPMS_317的报文计数*/

__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_FLPressureWarning;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_FLTempHigh;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_FLTirePres;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_FRPressureWarning;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_FRTempHigh;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_FRTirePres;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_RLPressureWarning;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_RLTempHigh;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_RLTirePres;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_RRPressureWarning;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_RRTempHigh;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_RRTirePres;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_StudyFailureWarning;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_StudyMode;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_SystemWarning;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_TPMSLearnIdStatus;

__CAN_DBC_LIB_EXTERN__ uint32_t VHALI_TPMS_3A2_MsgTicks ;/*TPMS_3A2的报文计数*/

__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_FLTireTemp;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_FRTireTemp;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_RLTireTemp;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_RRTireTemp;


//add by songbeibei, ABS_229
__CAN_DBC_LIB_EXTERN__ uint32_t VHALI_NMRx_MsgTicks;
__CAN_DBC_LIB_EXTERN__ uint32_t VHALI_NMTxSuceess_MsgTicks;

__CAN_DBC_LIB_EXTERN__ uint32_t VHALI_ABS_229_MsgTicks ;/*ABS_237的报文计数*/
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_ABS_FLWheelSpeedValid;
__CAN_DBC_LIB_EXTERN__ uint16_t VHALI_ABS_FLWheelSpeed;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_ABS_FRWheelSpeedValid;
__CAN_DBC_LIB_EXTERN__ uint16_t VHALI_ABS_FRWheelSpeed;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_ABS_RLWheelSpeedValid;
__CAN_DBC_LIB_EXTERN__ uint16_t VHALI_ABS_RLWheelSpeed;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_ABS_RRWheelSpeedValid;
__CAN_DBC_LIB_EXTERN__ uint16_t VHALI_ABS_RRWheelSpeed;

__CAN_DBC_LIB_EXTERN__ uint32_t VHALI_EHU_345_MsgTicks;/*EHU_345的报文计数*/

__CAN_DBC_LIB_EXTERN__ uint32_t VHALI_EPS_2A0_MsgTicks;/*EPS_2A0的报文计数*/

__CAN_DBC_LIB_EXTERN__ uint32_t VHALI_EPS_180_MsgTicks;/*EPS_180的报文计数*/
__CAN_DBC_LIB_EXTERN__ uint32_t VHALI_EPB_219_MsgTicks;/*EPB_219的报文计数*/
__CAN_DBC_LIB_EXTERN__ uint32_t VHALI_FCW_281_MsgTicks;/*FCW_281的报文计数*/
__CAN_DBC_LIB_EXTERN__ uint32_t VHALI_FCW_285_MsgTicks;/*FCW_285的报文计数*/

__CAN_DBC_LIB_EXTERN__ uint32_t VHALI_TBOX_296_MsgTicks;
__CAN_DBC_LIB_EXTERN__ uint32_t VHALI_XBS_241_MsgTicks;
//add ended


/* 发送报文的数据声明 */

__CAN_DBC_LIB_EXTERN__ uint8_t VHALO_CHMAsignalSts;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALO_SRSCrashSts;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALO_VCU110CycCntr;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALO_VCUActHVPwrCnsExt;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALO_VCUBMSOperModReq;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALO_VCUBMSSOCEna;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALO_VCUBattIntrHeatAllwd;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALO_VCUCRCID110;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALO_VCUChrgAllwd;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALO_VCUChrgIReqLimFac;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALO_VCUHVILSts;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALO_VCUSOCDisp;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALO_VCUVehSts;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALO_RemoteHVACStopCtrl;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALO_VCU_AvTq_Max;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALO_VCU_AvTq_Min;
__CAN_DBC_LIB_EXTERN__ uint16_t VHALO_AccPed_Int;
__CAN_DBC_LIB_EXTERN__ float VHALO_AccPed_Float;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALO_MCU131CRC;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALO_MCUAntishakeCom;
__CAN_DBC_LIB_EXTERN__ uint16_t VHALO_MotSpdReq;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALO_MotStsModReq;
__CAN_DBC_LIB_EXTERN__ uint16_t VHALO_MotTqReq;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALO_VCUGearPosn;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALO_VCUSysFltRank;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALO_VCU_AntiSlipFunEn_flg;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALO_VCUChrgStsLamp;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALO_VCUOBCSleep;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALO_VCUPlugConnectLamp;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALO_VCUDCDCStsMod;
__CAN_DBC_LIB_EXTERN__ uint16_t VHALO_VCUMaxPermDCDCPwr;
__CAN_DBC_LIB_EXTERN__ uint16_t VHALO_VCUReqDCDCU;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALO_Test12VChk;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALO_TestBrkPedPsd;
__CAN_DBC_LIB_EXTERN__ uint32_t VHALO_VCUVechileMile;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALO_TestBrkPedValid;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALO_TestVacBrkP;
__CAN_DBC_LIB_EXTERN__ uint16_t VHALO_VCUResiMilg;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALO_VCU_EngStatus;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALO_VccPumpEna;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALO_ACChrgrLockEna;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALO_ACChrgrLockFb;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALO_ACChrgrUnLockEna;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALO_EPBAppliedReq;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALO_EPBAppliedReqValid;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALO_KeyAccFlg;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALO_LowSpdWarnEna;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALO_TestAChrgWakeup;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALO_TestFlgKeyOn;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALO_TestHndbrkSig;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALO_TestRvsLampEna;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALO_TestVehDrvPerm;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALO_VCU520CRCChk;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALO_VCU520CycCntr;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALO_VehChrgSts;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALO_VCUEnaHVAC;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALO_VCUEnaPTC;
__CAN_DBC_LIB_EXTERN__ uint16_t VHALO_VCUMaxPermHVACPwr;
__CAN_DBC_LIB_EXTERN__ uint16_t VHALO_VCUMaxPermPTCPwr;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALO_TestBookingChrgSwt;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALO_TestElecMotEff;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALO_VCUMotTqAvlMax;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALO_VCUMotTqAvlMin;
__CAN_DBC_LIB_EXTERN__ uint16_t VHALO_VCUVehEgyCnseAscy;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALO_VehVSpdAvrgHistory;
__CAN_DBC_LIB_EXTERN__ uint16_t VHALO_HCUBCUBattSOC;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALO_SystemErr;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALO_VCUBattChrgErr;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALO_VCUBattChrgPwr;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALO_VCUBattChrgStatus;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALO_VCUBattDischrgPwr;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALO_VCUBrkErr;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALO_VCUDrvgEff;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALO_VCUElecMotErr;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALO_VCUEnaTextDisplayer;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALO_VCUEnaWarnSound;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALO_VCUPowerlimte;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALO_VCUPwrBattCutOff;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALO_VCUPwrBattFlt;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALO_VCUPwrCnse;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALO_VCUPwrSysFlt;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALO_VCURdy;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALO_VCUVehOverSpd;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALO_VCUsysOverT;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALO_ChallengeFrame0;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALO_ChallengeFrame1;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALO_ChallengeFrame2;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALO_ChallengeFrame3;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALO_ChallengeFrame4;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALO_ChallengeFrame5;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALO_ChallengeFrame6;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALO_ChallengeFrame7;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALO_VCU_ReleaseSig;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALO_VCU_BrakeLamp_Req;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALO_VCUOBCWake;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALO_VCU_DestinationID;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALO_VCU_NMAcknowledge;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALO_VCU_NMAlive;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALO_VCU_NMIndication;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALO_VCU_NMLimpHome;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALO_VCU_NMRing;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALO_ESKGearPosn;
__CAN_DBC_LIB_EXTERN__ uint16_t VHALO_InstantEnergyConsump;
__CAN_DBC_LIB_EXTERN__ uint32_t VHALO_VCUHisSubtotalEgyCnse;
__CAN_DBC_LIB_EXTERN__ uint32_t VHALO_VCUSubtotalEgyCnse;
__CAN_DBC_LIB_EXTERN__ uint16_t VHALO_VCUVehEgyCnseDrv;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALO_VCUHwVer1;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALO_VCUHwVer2;
__CAN_DBC_LIB_EXTERN__ uint16_t VHALO_VCUSwVer1;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALO_VCUSwVer2;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALO_VCUSwVer3;
__CAN_DBC_LIB_EXTERN__ uint8_t DtcToCAN[DTC_NUM_IN_RAM];
__CAN_DBC_LIB_EXTERN__ uint8_t VPMM_SystemState_enum;
__CAN_DBC_LIB_EXTERN__ uint8_t VPMM_HVUpTimeout_flg;
__CAN_DBC_LIB_EXTERN__ uint8_t VPMM_LVUpTimeout_flg;

__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_TBOX_RemoteHVACReq;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_TBOX_RemoteWorkReq;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_IChrgWakeUpReq;

__CAN_DBC_LIB_EXTERN__ uint8_t VHALO_NMSendDestination;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALO_NMSendAcknowledge;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALO_NMSendAlive;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALO_NMSendIndication;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALO_NMSendLimpHome;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALO_NMSendRing;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALO_NMSendReq;
__CAN_DBC_LIB_EXTERN__ uint8_t Old_VHALO_NMSendReq;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALO_BusShutDnReq;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALO_DisableAppComm;

__CAN_DBC_LIB_EXTERN__ uint32_t VHALI_PEPS_282_MsgTicks;

__CAN_DBC_LIB_EXTERN__ uint32_t VHALI_GW_405h_MsgTicks_Last;
__CAN_DBC_LIB_EXTERN__ uint32_t VHALI_BCM_410h_MsgTicks_Last;
__CAN_DBC_LIB_EXTERN__ uint32_t VHALI_PEPS_411h_MsgTicks_Last;
__CAN_DBC_LIB_EXTERN__ uint32_t VHALI_EHU_412h_MsgTicks_Last;
__CAN_DBC_LIB_EXTERN__ uint32_t VHALI_ICM_421h_MsgTicks_Last;
__CAN_DBC_LIB_EXTERN__ uint32_t VHALI_TBOX_430h_MsgTicks_Last;

__CAN_DBC_LIB_EXTERN__ uint32_t VHALI_PEPS_282_MsgTicks_Last;
__CAN_DBC_LIB_EXTERN__ uint32_t VHALI_GW_522_MsgTicks_Last;
__CAN_DBC_LIB_EXTERN__ uint32_t VHALI_TBOX_296_MsgTicks_Last;
__CAN_DBC_LIB_EXTERN__ uint32_t VHALI_TBOX_298_MsgTicks_Last;

__CAN_DBC_LIB_EXTERN__ uint32_t VHALI_TMS_325_MsgTicks;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALI_TMS_PoweDesired_WPTC;

__CAN_DBC_LIB_EXTERN__ uint32_t VHALI_WPTC_566_MsgTicks;
__CAN_DBC_LIB_EXTERN__ uint8_t  VHALI_WPTC_RunMode;
__CAN_DBC_LIB_EXTERN__ uint8_t  VHALI_WPTC_CurrentPower;

__CAN_DBC_LIB_EXTERN__ uint8_t VHALO_VCUSportModeStatus;
__CAN_DBC_LIB_EXTERN__ uint8_t VHALO_VCUCHrgPauseReq;
__CAN_DBC_LIB_EXTERN__ uint16_t VHALO_MOT_CharPwr;
__CAN_DBC_LIB_EXTERN__ uint16_t VHALO_ECC_PwrLmit;
__CAN_DBC_LIB_EXTERN__ uint16_t VHALO_MOT_DCharPwr;
__CAN_DBC_LIB_EXTERN__ uint16_t VHALO_RR_RemainRange_Chrg_km;
__CAN_DBC_LIB_EXTERN__ uint16_t VHALO_RR_RemainRange_noChrg_km;
__CAN_DBC_LIB_EXTERN__ int16_t VHALO_RR_Ave_Fad_whpkm;
__CAN_DBC_LIB_EXTERN__ int16_t VHALO_RR_Ave_Filt_whpkm;
__CAN_DBC_LIB_EXTERN__ int16_t VHALO_RR_PTRemainEgy_Wh;



#endif /* HAL_CAN_DBC_LIB_H_ */

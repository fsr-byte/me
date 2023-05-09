#ifndef   __HISTORY_DATA_H
#define   __HISTORY_DATA_H

#include "typedefs.h"

#define DATA_FLAG_SIZE  4

#define EGY_CNSE_Zone_km_ARR_LEN 20
#define EGY_CNSE_1km_ARR_LEN 5

extern HISTORY_RAM_1_DEF float VCUSubTotalEgyCnse_kwh;
extern HISTORY_RAM_1_DEF float VCUTotalEgyCnse_kwh;
extern HISTORY_RAM_1_DEF float VCUVehEgyCnseDrv;
extern HISTORY_RAM_1_DEF uint32_t VCUOdo_km;
extern HISTORY_RAM_1_DEF uint32_t SubTotMilg;

extern HISTORY_RAM_1_DEF uint16_t ResiMilg;
extern HISTORY_RAM_1_DEF uint8_t MidJumpFlg;
extern HISTORY_RAM_1_DEF uint8_t DriveMode;
extern HISTORY_RAM_1_DEF float BMSSocLast;   
extern HISTORY_RAM_1_DEF float BMSSocMaxLast;
extern HISTORY_RAM_1_DEF float BMSSocMinLast;
extern HISTORY_RAM_1_DEF float SOCDisp;
extern HISTORY_RAM_1_DEF float BMSBattResidPwrLast;
extern HISTORY_RAM_1_DEF float SocJumpPoint;
extern HISTORY_RAM_1_DEF float sysSocJumpPoint;
extern HISTORY_RAM_1_DEF uint32_t BMSBattRatedPwrLast;

extern HISTORY_RAM_1_DEF uint8_t creepGearPositon;
extern HISTORY_RAM_1_DEF uint8_t PEPS_ChallengeCodeHistory_Byte[8];
extern HISTORY_RAM_1_DEF int16_t  ex_ExportHistoryVal;
extern HISTORY_RAM_1_DEF int16_t  ex_ImportHistoryVal;
extern HISTORY_RAM_1_DEF int16_t  ex_SeatAxlePos;

extern HISTORY_RAM_2_DEF float sport_egyCnse_Zone_km[EGY_CNSE_Zone_km_ARR_LEN]; // lasted record, power consume in 100km, unit: wh/100km
extern HISTORY_RAM_2_DEF float sport_egyCnse_1km[EGY_CNSE_1km_ARR_LEN];//lasted record, power consume in 1km, unit: wh/km
extern HISTORY_RAM_2_DEF uint32_t sport_mile_Zone_km; // current mileage of this 100km
extern HISTORY_RAM_2_DEF float sport_egy_s_Zone_km; // the start energy consume of this 100km
extern HISTORY_RAM_2_DEF uint32_t sport_mile_1km; // current in this 1km
extern HISTORY_RAM_2_DEF float sport_egy_s_1km; // the start consume in this 1km
extern HISTORY_RAM_2_DEF float PT_TotalEgyCnse_kwh_sport;
extern HISTORY_RAM_2_DEF uint32_t Odo_km_sport;
extern HISTORY_RAM_2_DEF uint8_t sport_ptr_Zone_km; //array index to re-write
extern HISTORY_RAM_2_DEF uint8_t sport_ptr_1km;//array index to re-write

extern HISTORY_RAM_2_DEF float eco_egyCnse_Zone_km[EGY_CNSE_Zone_km_ARR_LEN]; // lasted record, power consume in 100km, unit: wh/100km
extern HISTORY_RAM_2_DEF float eco_egyCnse_1km[EGY_CNSE_1km_ARR_LEN];//lasted record, power consume in 1km, unit: wh/km
extern HISTORY_RAM_2_DEF uint32_t eco_mile_Zone_km; // current mileage of this 100km
extern HISTORY_RAM_2_DEF float TotalEgyCnse_wh_Zone; // the total energy consume of this 100km
extern HISTORY_RAM_2_DEF uint32_t eco_mile_1km; // current in this 1km
extern HISTORY_RAM_2_DEF float TotalEgyCnse_wh_1km; // the total energy consume in this 1km
extern HISTORY_RAM_2_DEF float PT_TotalEgyCnse_kwh_eco;
extern HISTORY_RAM_2_DEF uint32_t Odo_km_eco;
extern HISTORY_RAM_2_DEF uint8_t eco_ptr_Zone_km; //array index to re-write
extern HISTORY_RAM_2_DEF uint8_t eco_ptr_1km;//array index to re-write


extern uint8_t PEPS_VSK_Byte[16];
extern uint8_t ECU_FUN_CFG_Byte[6];
extern uint8_t ECU_FUN_CFG_Valid;
extern uint8_t VCU_CCP_Byte[1];
extern uint8_t VCU_CCP_Valid;
extern uint8_t VCU_CFG_Byte[8];   //VCU configuration
extern uint8_t VCU_CFG_Valid;

extern void AppData_Init_1(void);
extern  void AppData_Init_2(void);
extern void AppData_Init_3(void);
extern  void AppData_Init_4(void) ;
extern  void AppData_Init_5(void) ;

#endif

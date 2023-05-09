#ifndef REMAIN_DRIVING_RANGE_H
#define REMAIN_DRIVING_RANGE_H

#ifndef ENM_model_COMMON_INCLUDES_
#define ENM_model_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif

#include "History_Data.h"

//step length: 20km
//#define EGY_CNSE_Zone_km_ARR_LEN 20
#define MID_TERM_LEN 5
#define LONG_TERM_LEN (EGY_CNSE_Zone_km_ARR_LEN)
#define zone_km 20

// step length: 1km
#define _1Km 1
//#define EGY_CNSE_1km_ARR_LEN 5
#define SHORT_TERM_LEN (EGY_CNSE_1km_ARR_LEN)

#define ECO_AVE  (142)
#define SPORT_AVE (180)
#define _K (1000)
#define AVE_UP_LIMIT (1000)
#define AVE_LOW_LIMIT (-1000)

#define INSTANCE_EGY_CNS_WH (5)// instance energy consumption limitation in 1 loop
/*
#pragma push
#pragma DATA_SEG __GPAGE_SEG ENM_PARM

//for sport mode
extern real32_T sport_egyCnse_Zone_km[EGY_CNSE_Zone_km_ARR_LEN]; // lasted history record, unit: kwh/100km -> wh/km*10
extern uint8_T sport_ptr_Zone_km; //array index to re-write
extern uint32_T sport_mile_Zone_km; // the start mileage of this 100km
extern real32_T sport_egy_s_Zone_km; // the start energy consume of this 100km

extern real32_T sport_egyCnse_1km[EGY_CNSE_1km_ARR_LEN];//lasted history record, unit: wh/km
extern uint8_T sport_ptr_1km;//array index to re-write
extern uint32_T sport_mile_1km; // the mileage in this 1km
extern real32_T sport_egy_s_1km; // the start energy consume in this 1km

//for ecomony mode
extern real32_T eco_egyCnse_Zone_km[EGY_CNSE_Zone_km_ARR_LEN]; // lasted history record, unit: kwh/100km -> wh/km*10
extern uint8_T eco_ptr_Zone_km; //array index to re-write
extern uint32_T eco_mile_Zone_km; // the start mileage of this 100km
extern real32_T eco_egy_s_Zone_km; // the start energy consume of this 100km

extern real32_T eco_egyCnse_1km[EGY_CNSE_1km_ARR_LEN];//lasted history record, unit: wh/km
extern uint8_T eco_ptr_1km;//array index to re-write
extern uint32_T eco_mile_1km; // the mileage in this 1km
extern real32_T eco_egy_s_1km; // the start energy consume in this 1km
#pragma pop
//*/

extern void DataValidCheck(int16_T Uplimit,int16_T Lowlimit);
//extern void Sport_RecordArray_Update(uint32_T odo_dif,real32_T egyCnse,boolean_T Charging_flg);
extern void Eco_RecordArray_Update(uint32_T odo_dif,real32_T InsCnse_wh,boolean_T Charging_flg);
//extern real32_T Sport_Current_AveProcess();
//extern real32_T Sport_ZoneX_AveProcess(real32_T egyCnse, uint8_T offset);
extern real32_T Eco_Current_AveProcess();
extern real32_T Eco_ZoneX_AveProcess(uint8_T offset);

#endif


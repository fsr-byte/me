#ifndef SYS_SOC_H
#define SYS_SOC_H

#ifndef ENM_model_COMMON_INCLUDES_
#define ENM_model_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif

#define SOC_NUM 100
#define SYSTICK_to_S 1000
#define MONS_IN_YEAR 12
#define MON_DIF 1

typedef struct
{
	uint16_T year;
	uint8_T month;
	uint8_T day;
}DATE_T;

#define UPDATED 0
#define OUT_OF_DATE 1
#define SOH_DEFAULT 100

#define S11_EQ_DEFALUT (415*3600) //UINT: W
#define K11_EQ_DEFAULT (291*3600) //UINT: W

extern uint8_T K11_Mark;
extern uint8_T S11_Mark;
extern uint8_T Vehicle_Type;

/* Definition for custom storage class: ENM_PWR */
/*
#pragma push
#pragma DATA_SEG __GPAGE_SEG ENM_PARM

extern DATE_T DateMap[SOC_NUM];
extern uint32_T EQMap[SOC_NUM];
//extern uint32_T EQMap_default[SOC_NUM];//unit: ws
extern uint32_T MileageMap[SOC_NUM]; //unit: km

extern real32_T bmsSocLast;//bms soc latest record
extern real32_T bmsSoHLast;//bms SOH latest record
extern uint32_T powerSum;// power last record
extern boolean_T charged;// battery charged
extern real32_T charged_soc;// bms soc while battery charged
extern real32_T soc_gap;//soc gap between vehicle shut down and power on in current soc zone
extern DATE_T lastday;//last day before this wake up

#pragma pop
*/
//data interface between simulink

//import from low level software
//extern uint32_T SystemTickMs; //system clock tick

extern void InitProcess(boolean_T chargeFlg, real32_T bmssoc, real32_T bmsSoH );
extern void Today (uint8_T day, uint8_T month, uint16_T year, uint32_T mileage);
extern void  BMSSOCProcess(boolean_T chargeFlg,unsigned long sysTickMs, real32_T bmsSoc, uint32_T P_w,real32_T bmsSoH);
extern uint32_T PowerResidueCalculate(uint8_T socMax, uint8_T socMin, real32_T bmsSoc);
extern void MapCheckLoop(real32_T bmsSoc, uint8_T socMin);

#endif


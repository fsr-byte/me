#include "derivative.h"      /* derivative-specific definitions */

#include "History_Data.h"


//History Data
HISTORY_RAM_1_DEF float VCUSubTotalEgyCnse_kwh;
HISTORY_RAM_1_DEF float VCUTotalEgyCnse_kwh;
HISTORY_RAM_1_DEF float VCUVehEgyCnseDrv;
HISTORY_RAM_1_DEF uint32_t VCUOdo_km;
HISTORY_RAM_1_DEF uint32_t SubTotMilg;

HISTORY_RAM_1_DEF uint16_t ResiMilg;
HISTORY_RAM_1_DEF uint8_t MidJumpFlg;
HISTORY_RAM_1_DEF uint8_t DriveMode;
HISTORY_RAM_1_DEF float BMSSocLast;   
HISTORY_RAM_1_DEF float BMSSocMaxLast;
HISTORY_RAM_1_DEF float BMSSocMinLast;
HISTORY_RAM_1_DEF float SOCDisp;
HISTORY_RAM_1_DEF float BMSBattResidPwrLast;
HISTORY_RAM_1_DEF float SocJumpPoint;
HISTORY_RAM_1_DEF float sysSocJumpPoint;
HISTORY_RAM_1_DEF uint32_t BMSBattRatedPwrLast;

HISTORY_RAM_1_DEF uint8_t creepGearPositon;
HISTORY_RAM_1_DEF uint8_t PEPS_ChallengeCodeHistory_Byte[8];
HISTORY_RAM_1_DEF int16_t  ex_ExportHistoryVal;
HISTORY_RAM_1_DEF int16_t  ex_ImportHistoryVal;
HISTORY_RAM_1_DEF int16_t  ex_SeatAxlePos;

HISTORY_RAM_2_DEF float sport_egyCnse_Zone_km[EGY_CNSE_Zone_km_ARR_LEN]; // lasted record, power consume in 100km, unit: wh/100km
HISTORY_RAM_2_DEF float sport_egyCnse_1km[EGY_CNSE_1km_ARR_LEN];//lasted record, power consume in 1km, unit: wh/km
HISTORY_RAM_2_DEF uint32_t sport_mile_Zone_km; // current mileage of this 100km
HISTORY_RAM_2_DEF float sport_egy_s_Zone_km; // the start energy consume of this 100km
HISTORY_RAM_2_DEF uint32_t sport_mile_1km; // current in this 1km
HISTORY_RAM_2_DEF float sport_egy_s_1km; // the start consume in this 1km
HISTORY_RAM_2_DEF float PT_TotalEgyCnse_kwh_sport;
HISTORY_RAM_2_DEF uint32_t Odo_km_sport;
HISTORY_RAM_2_DEF uint8_t sport_ptr_Zone_km; //array index to re-write
HISTORY_RAM_2_DEF uint8_t sport_ptr_1km;//array index to re-write

HISTORY_RAM_2_DEF float eco_egyCnse_Zone_km[EGY_CNSE_Zone_km_ARR_LEN]; // lasted record, power consume in 100km, unit: wh/100km
HISTORY_RAM_2_DEF float eco_egyCnse_1km[EGY_CNSE_1km_ARR_LEN];//lasted record, power consume in 1km, unit: wh/km
HISTORY_RAM_2_DEF uint32_t eco_mile_Zone_km; // current mileage of this 100km
HISTORY_RAM_2_DEF float TotalEgyCnse_wh_Zone; // the total energy consume of this 100km
HISTORY_RAM_2_DEF uint32_t eco_mile_1km; // current in this 1km
HISTORY_RAM_2_DEF float TotalEgyCnse_wh_1km; // the total energy consume in this 1km
HISTORY_RAM_2_DEF float PT_TotalEgyCnse_kwh_eco;
HISTORY_RAM_2_DEF uint32_t Odo_km_eco;
HISTORY_RAM_2_DEF uint8_t eco_ptr_Zone_km; //array index to re-write
HISTORY_RAM_2_DEF uint8_t eco_ptr_1km;//array index to re-write

extern uint16_t NEDC_Milg_km;
extern uint16_t Eco_egyCnse_1km_c;
extern uint8_t zone_km_c;
/******************************************************************************
 * Name:            AppData_Init_1
 * Called by:       uds_storage
 * Parameter:       void
 * Return value:    void
 * Description:     initialize the application data area 1
 * Precondition:    ---
 *****************************************************************************/
void AppData_Init_1()
{
    VCUSubTotalEgyCnse_kwh = 0.0F;
    VCUTotalEgyCnse_kwh = 0.0F;
    VCUVehEgyCnseDrv = 51.1F;
    VCUOdo_km = 0;    
    SubTotMilg = 0;

}

/******************************************************************************
 * Name:            AppData_Init_2
 * Called by:       uds_storage
 * Parameter:       void
 * Return value:    void
 * Description:     initialize the application data area 2
 * Precondition:    ---
 *****************************************************************************/
void AppData_Init_2()
{
    ResiMilg = NEDC_Milg_km/2;
    MidJumpFlg = 0;
    DriveMode = 1;
    BMSSocLast = 50.0F;   
    BMSSocMaxLast = 100.0F;
    BMSSocMinLast = 8.0F;
    SOCDisp = 50.0F;
    BMSBattResidPwrLast = 0.0F;
    SocJumpPoint = 0.0F;
    sysSocJumpPoint =0.0F;
    BMSBattRatedPwrLast=0xFFFF;

}

/******************************************************************************
 * Name:            AppData_Init_53
 * Called by:       uds_storage
 * Parameter:       void
 * Return value:    void
 * Description:     initialize the application data area 3
 * Precondition:    ---
 *****************************************************************************/
void AppData_Init_3()
{
    creepGearPositon = 0;
    ex_ExportHistoryVal = 0;
    ex_ImportHistoryVal = 0;
    ex_SeatAxlePos = 0;

}
/******************************************************************************
 * Name:            AppData_Init_4
 * Called by:       uds_storage
 * Parameter:       void
 * Return value:    void
 * Description:     initialize the application data area 4
 * Precondition:    ---
 *****************************************************************************/
void AppData_Init_4()
{
    int i;
    for( i = 0; i < EGY_CNSE_Zone_km_ARR_LEN;  i++)
    {
        sport_egyCnse_Zone_km[i] = 3600;
    }
    for(i = 0; i < EGY_CNSE_1km_ARR_LEN; i++)
    {
       sport_egyCnse_1km[i] = 180;
    }
    sport_mile_Zone_km = 0;
    sport_egy_s_Zone_km = 0.0F;
    sport_mile_1km = 0;
    sport_egy_s_1km = 0.0F;    
    PT_TotalEgyCnse_kwh_sport = 0.0F;
    Odo_km_sport = 0;
    sport_ptr_Zone_km = 0;
    sport_ptr_1km = 0;   
}

/******************************************************************************
 * Name:            AppData_Init_5
 * Called by:       uds_storage
 * Parameter:       void
 * Return value:    void
 * Description:     initialize the application data area 5
 * Precondition:    ---
 *****************************************************************************/
void AppData_Init_5()
{
    int i;
    for( i = 0; i < EGY_CNSE_Zone_km_ARR_LEN;  i++)
    {
        eco_egyCnse_Zone_km[i] = (float)(Eco_egyCnse_1km_c*zone_km_c);
    }    
    for( i = 0; i < EGY_CNSE_1km_ARR_LEN;  i++)
    {
        eco_egyCnse_1km[i] = (float)(Eco_egyCnse_1km_c);
    }    
    eco_mile_Zone_km = 0;
    TotalEgyCnse_wh_Zone = 0.0F;
    eco_mile_1km = 0;
    TotalEgyCnse_wh_1km = 0.0F;
    PT_TotalEgyCnse_kwh_eco = 0.0F;
    Odo_km_eco = 0;
    eco_ptr_Zone_km = 0;
    eco_ptr_1km = 0;        
}

#ifndef FLT_STORE_C
#define FLT_STORE_C

#include <stdio.h>
#include <string.h>
#include "DHP_CC_FltStore.h"

#pragma push
#pragma DATA_SEG __GPAGE_SEG GPAGED_RAM
//data interface to Simulink
extern unsigned char Fault_storage_array[2480]; 

#pragma pop

//function declare



//function implement
uint8_T FaultStore(boolean_T FltFlg, uint8_T FltLevel, uint8_T FltSerial,  const uint8_T *SnapShotsArray,boolean_T updateInfosFlg )
{
	uint8_T i = 0;
	uint16_T index = 0;
	uint8_T DTCIdx = 0;
	
	if(0 == FltSerial)
		return 0; 
	
	for(i=0; i<FLTINRAM_NUM; i++)
	{
	    index = (uint16_T)( i * (FLT_SNAPSHOTS_LEN) ); /*DTC record length in RAM is 62 bytes, first byte is DTC index*/
        DTCIdx = Fault_storage_array[index];
		if( DTCIdx == FltSerial ) 
		{			
		    if( updateInfosFlg )  //update snapshots infos only when the first-time fault happen
			{
			    memcpy(&Fault_storage_array[index+1], &SnapShotsArray[0], FLT_SNAPSHOTS_LEN-1);
			    return (i+1);//return DTCIdx;
			}
			return 0; //here need to return 		
		}
		
		if(0 == DTCIdx)
		{
			Fault_storage_array[index] = FltSerial;
			memcpy(&Fault_storage_array[index+1], &SnapShotsArray[0], FLT_SNAPSHOTS_LEN-1);
			return (i+1);//return FltSerial;
		}			
	}

	return 0;//return DTCIdx;
	
}


#endif



#ifndef FLT_STORE_H
#define FLT_STORE_H

#ifndef DHP_model_COMMON_INCLUDES_
#define DHP_model_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif

//#include "Global.h"


#define FLT_SNAPSHOTS_LEN 62
#define FLTINRAM_NUM 40



//data interface between simulink
extern uint8_T FaultStore(boolean_T FltFlg, uint8_T FltLevel, uint8_T FltSerial, const uint8_T* SnapShotsArray,boolean_T updateInfosFlg );

#endif


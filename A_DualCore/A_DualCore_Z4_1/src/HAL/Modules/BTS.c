/*
 * BTS.c
 *
 *  Created on: 2018年9月10日
 *      Author: helei
 */

#define __BTS_GLOBALS__

#include "derivative.h"
#include "BTS.h"
#include "BASE_Global.h"
#include "Task.h"

_BTS_data_ BTS5180_data[2];
_BTS_data_ BTS5200_data[4];

uint8_t iSelected = 0;
uint16_t BTS5200_ADvalue = 0;
uint8_t BTS5200_status = 0;
/*******************************************BTS5180***/

void BTS5180_Init(void)
{
	//初始化端口
	SIUL_DigitalOutput(BTS5180_DEN,0);
	SIUL_DigitalOutput(BTS5180_DSEL,0);
	SIUL_DigitalOutput(BTS5180_HS1,0);
	SIUL_DigitalOutput(BTS5180_HS2,0);
	SIUL_DigitalOutput(BTS_KL30a1_C,0);
	//设置默认状态
	BTS5180_HS1_Clear();	//output low
	BTS5180_HS2_Clear();	//output low
	BTS5180_DEN_Clear();	//diagnostic disable
	KL30a1_C_Set();
}

void BTS5180_SetValue(uint8_t num, uint8_t value)
{
	BTS5180_data[num-1].status = value;
}

void BTS5180_Refresh(void)
{
	if(BTS5180_data[0].status == 0)
	{
	    BTS5180_HS1_Clear();
	}
	else
	{
	    BTS5180_HS1_Set();
	}
	if(BTS5180_data[1].status == 0)
	{
	    BTS5180_HS2_Clear();
	}
	else
	{
	    BTS5180_HS2_Set();
	}
}

void BTS5180_Diagnostic(void)
{
    #define WAITTIMEMS_HS 500
	static boolean diagHS_first_flag = 1;  //select HS1 or HS2 to diagnostics in turn
	static uint32_t startDiagHS_Time;
	static boolean diagHS_set_flg = 0; //control to wait 200ms for diag HS
	uint32_t diagHS_deltaTime ;

	if(diagHS_first_flag)
	{
		if(!diagHS_set_flg)
		{
			//diagnostic HS1
			BTS5180_DSEL_Clear();
			BTS5180_DEN_Set();	//open diagnostic
			diagHS_set_flg = 1;
			startDiagHS_Time = SystemTickMs;
		}
		else
		{
			diagHS_deltaTime = (SystemTickMs - startDiagHS_Time);
			if(diagHS_deltaTime > WAITTIMEMS_HS )
			{
				BTS_GETADC();	//get diagnostic value
				BTS5180_data[0].ADvalue = BTS5180_IS;
				BTS5180_data[0].mA = ((float)(BTS5180_data[0].ADvalue)+1)/4096*5*550/1.2;
				if((BTS5180_data[0].status == 0) && (BTS5180_data[0].ADvalue >= 4095))
				{
				    BTS5180_data[0].openload = 1;	//开路故障
				}
				else if((BTS5180_data[0].status != 0) && (BTS5180_data[0].ADvalue > 4000))
				{
				    BTS5180_data[0].shortload = 1;	//短路故障
				}
				else
				{
					BTS5180_data[0].openload = 0;	//无故障
					BTS5180_data[0].shortload = 0;
				}

				diagHS_first_flag = 0;
				diagHS_set_flg = 0;
			}
		}
	}
	else
	{
		if(!diagHS_set_flg)
		{
			//diagnostic HS2
			BTS5180_DSEL_Set();
			BTS5180_DEN_Set();	//open diagnostic
			diagHS_set_flg = 1;
			startDiagHS_Time = SystemTickMs;
		}
		else
		{
			diagHS_deltaTime = (SystemTickMs - startDiagHS_Time);
			if(diagHS_deltaTime > WAITTIMEMS_HS )
			{
				BTS_GETADC();	//get diagnostic value
				BTS5180_data[1].ADvalue = BTS5180_IS;
				BTS5180_data[1].mA = ((float)(BTS5180_data[1].ADvalue)+1)/4096*5*550/1.2;
				if((BTS5180_data[1].status == 0) && (BTS5180_data[1].ADvalue >= 4095))
				{
				    BTS5180_data[1].openload = 1;	//开路故障
				}
				else if((BTS5180_data[1].status != 0) && (BTS5180_data[1].ADvalue > 4000))
				{
				    BTS5180_data[1].shortload = 1;	//短路故障
				}
				else
				{
					BTS5180_data[1].openload = 0;	//无故障
					BTS5180_data[1].shortload = 0;
				}

				diagHS_first_flag = 1;
				diagHS_set_flg = 0;
			}
		}
	}
}


/*******************************************BTS5200***/

void BTS5200_Init(void)
{
	//初始化端口
	SIUL_DigitalOutput(BTS5200_DEN,0);
	SIUL_DigitalOutput(BTS5200_DSEL0,0);
	SIUL_DigitalOutput(BTS5200_DSEL1,0);
	SIUL_DigitalOutput(BTS5200_HS11,0);
	SIUL_DigitalOutput(BTS5200_HS12,0);
	SIUL_DigitalOutput(BTS5200_HS13,0);
	SIUL_DigitalOutput(BTS5200_HS14,0);
	SIUL_DigitalOutput(BTS_KL30a1_C,0);
	//设置默认状态
	BTS5200_HS11_Clear();	//output low
	BTS5200_HS12_Clear();	//output low
	BTS5200_HS13_Clear();	//output low
	BTS5200_HS14_Clear();	//output low
	BTS5200_DEN_Clear();	//diagnostic disable
	KL30a1_C_Set();
}

void BTS5200_SetValue(uint8_t num, uint8_t value)
{
	BTS5200_data[num-1].status = value;
}

void BTS5200_Refresh(void)
{
	if(BTS5200_data[0].status == 0)
	{
	    BTS5200_HS11_Clear();
	}
	else
	{
	    BTS5200_HS11_Set();
	}

	if(BTS5200_data[1].status == 0)
	{
	    BTS5200_HS12_Clear();
	}
	else
	{
	    BTS5200_HS12_Set();
	}

	if(BTS5200_data[2].status == 0)
	{
	    BTS5200_HS13_Clear();
	}
	else
	{
	    BTS5200_HS13_Set();
	}

	if(BTS5200_data[3].status == 0)
	{
	    BTS5200_HS14_Clear();
	}
	else
	{
	    BTS5200_HS14_Set();
	}
}

void BTS5200_Diagnostic(void)
{
	////static uint8_t iSelected = 0;
	static boolean diagHS1_set_flg = 0; //control to wait 200ms for diag HS1
	static boolean diagHS2_set_flg = 0; //control to wait 200ms for diag HS2
	static boolean diagHS3_set_flg = 0; //control to wait 200ms for diag HS3
	static boolean diagHS4_set_flg = 0; //control to wait 200ms for diag HS4
	static uint32_t startHSDiag_Time;
	uint32_t HSdiag_deltaTime ;

	BTS5200_DEN_Set();	//open diagnostic
	switch(iSelected)
	{
	case 0:
		if(!diagHS1_set_flg)
		{
			BTS5200_DSEL1_Clear();
			BTS5200_DSEL0_Clear();
			diagHS1_set_flg = 1;
			diagHS2_set_flg = 0;
			diagHS3_set_flg = 0;
			diagHS4_set_flg = 0;
			startHSDiag_Time = SystemTickMs;
		}
		break;
	case 1:
		if(!diagHS2_set_flg)
		{
			BTS5200_DSEL1_Clear();
			BTS5200_DSEL0_Set();
			diagHS1_set_flg = 0;
			diagHS2_set_flg = 1;
			diagHS3_set_flg = 0;
			diagHS4_set_flg = 0;
			startHSDiag_Time = SystemTickMs;
		}
		break;
	case 2:
		if(!diagHS3_set_flg)
		{
			BTS5200_DSEL1_Set();
			BTS5200_DSEL0_Clear();
			diagHS1_set_flg = 0;
			diagHS2_set_flg = 0;
			diagHS3_set_flg = 1;
			diagHS4_set_flg = 0;
			startHSDiag_Time = SystemTickMs;
		}
		break;
	case 3:
		if(!diagHS4_set_flg)
		{
			BTS5200_DSEL1_Set();
			BTS5200_DSEL0_Set();
			diagHS1_set_flg = 0;
			diagHS2_set_flg = 0;
			diagHS3_set_flg = 0;
			diagHS4_set_flg = 1;
			startHSDiag_Time = SystemTickMs;
		}
		break;
	default: break;
	}

	if(diagHS1_set_flg || diagHS2_set_flg || diagHS3_set_flg || diagHS4_set_flg)
	{
		HSdiag_deltaTime = (SystemTickMs - startHSDiag_Time);
		if(HSdiag_deltaTime > WAITTIMEMS_HS )
		{
			BTS_GETADC();	//get diagnostic value
			BTS5200_data[iSelected].ADvalue = BTS5200_IS;
			BTS5200_ADvalue = BTS5200_IS;
			BTS5200_status = BTS5200_data[iSelected].status;
			BTS5200_data[iSelected].mA = ((float)(BTS5200_data[iSelected].ADvalue)+1)/4096*5*300/1.1;
			if((BTS5200_data[iSelected].status == 0) && (BTS5200_data[iSelected].ADvalue >= 4095))
			{
			    BTS5200_data[iSelected].openload = 1;	//开路故障
			}
			else if((BTS5200_data[iSelected].status != 0) && (BTS5200_data[iSelected].ADvalue > 4000))
			{
			    BTS5200_data[iSelected].shortload = 1;	//短路故障
			}
			else
			{
				BTS5200_data[iSelected].openload = 0;	//无故障
				BTS5200_data[iSelected].shortload = 0;
			}

			iSelected++;
			if(iSelected == 4)
			{
			    iSelected = 0;
			}

			if(diagHS1_set_flg)
			{
			    diagHS1_set_flg = 0;
			}
			else if(diagHS2_set_flg)
			{
			    diagHS2_set_flg = 0;
			}
			else  if(diagHS3_set_flg)
			{
			    diagHS3_set_flg = 0;
			}
			else if(diagHS4_set_flg)
			{
			    diagHS4_set_flg = 0;
			}

		}
	}

}




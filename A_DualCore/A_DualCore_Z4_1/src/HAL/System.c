/*
 * System.c
 *
 *  Created on: 2018年10月9日
 *      Author: helei
 */

#define __SYSTEM_GLOBALS__

#include "derivative.h"
#include "System.h"
#include "BASE_Global.h"
#include "Modules_Global.h"
#include "Global.h"
#include "CAN_DBC_Lib.h"
#include "CAN_Operation.h"
#include "uds_tp.h"
#include "uds_service.h"
#include "CCP.h"
#include "NVM.h"
#include "eMIOS.h"
// #include "HALI_Model.h"
// #include "DIM_Model.h"
// #include "DHP_Model.h"
// #include "CHRG_Model.h"
// #include "ENM_Model.h"
// #include "TQM_Model.h"
// #include "TQFRate_model.h"
// #include "SCR_model.h"
// #include "ACR_model.h"
// #include "NM_Model.h"
// #include "TMM_Model.h"
// #include "PEPS_Model.h"
// #include "DOM_Model.h"
// #include "AVAS_Model.h"
#include "Global.h"
//#include "BTK_Model.h"
#include "BTK_ESCL.h"

extern void PMM_model_initialize(void);
extern void CheckHLSFaultsPOR(void);

void Init_System(void)
{
    uint8_t QC = 0, SC = 0;
    //BASE Initial
    SYS_CLOCK_Init();
    SYS_RT_Init();
    DSPI_0_Master_Init(DSPI_CLK, 400000);
    DSPI_1_Master_Init(DSPI_CLK, 400000);

    FLEXCAN_0_Init(500);
    FLEXCAN_1_Init(500);
    FLEXCAN_2_Init(500);
    FLEXCAN_3_Init(500);
    SARADC_Init();		//ADC in
    eTPU_Init();		//PWM out
    eMIOS_Init_All();	//PWM in
    Init_DIO();
    LIN_Init();
    ENET_Init();	//初始化ENET

    //Modules Initial
    M95128_Init();

    CheckSBC_SPIChannel();
    FS6500_Init();
    NCV7240B_Init();
    NCV7513B_Init();
    NCV7719_Init();
    BTS5180_Init();
    BTS5200_Init();
    LIN_Device_Init();
    CheckHLSFaultsPOR();  //may misdiagnose due to the power mode of ECUs

    FS65_UpdateRegisterContent(IO_INPUT_ADR);  //通过SBC读取KL15(IO0),WAKEUP1(IO4),WAKEUP2(IO5)的状态
    HAL_Capture_Digital();
    HAL_Capture_Digital();
    QC = HAL_Get_Digital(13);
    SC = HAL_Get_Digital(15);
    if( WAKEUPKL15 == 1 )
    {	//KL15唤醒
//        NM_AppWaitValid = 1;
        //if( 0 != C_PMS_En )
        //{
            //VBTK_SleepAllw_flg = 0;
        //}
    }
    if( (WAKEUP1 == 1) || (QC == 1) )
    {	//IO4,WAKEUP1唤醒,快充唤醒
        NM_AppWaitValid = 1;
    }
    if( (WAKEUP2 == 1) || (SC == 1) )
    {	//IO5,WAKEUP2唤醒，慢充唤醒
        NM_AppWaitValid = 1;
    }
    if( WAKEUPCAN_LIN == 1 )
    {	//CAN唤醒
        hIOP_1043WKUP_flg = 1;	//用于判断是否为CAN唤醒
    }
    if( WAKEUPLDT == 1 )
    {	//SBC内部定时器LDT唤醒

    }
    //device
#if (RUN_UDS_NVM_ON_CORE1 == 1)	
    udsTpInit();
    udsServiceInit();
#endif	
    Ccp_Init();
    VHALI_HWVersion = HW_VCU20;
    NM_First = 0;

#if (RUN_UDS_NVM_ON_CORE1 == 1)	
    NVM_Init();	//标定量等存储相关量的初始化，此时车型信息加载
#endif	
    Init_CanMessage();	//依据车型初始化发送接收数组及应将MB

    Bus_offTaskInit();
    prevGW522Tick = 0;
    AppBeginRunning_flg = FALSE;

    DIM_model_initialize();
    BTK_Model_initialize();
    DOM_model_initialize();


//    HALI_model_initialize();
//    DIM_model_initialize();
//    BTK_Model_initialize();
//    PMM_model_initialize();
    //CHRG_Model_initialize();
    //ENM_model_initialize();
    //TQM_model_initialize();
    //SCR_model_initialize();
    //ACR_model_initialize();
    //TQFRate_model_initialize();
    //TMM_model_initialize();
    //PEPS_Model_initialize();
//    DOM_model_initialize();
    //AVAS_Model_initialize();
    //NM_Model_initialize();
//    if( 0 != C_ESCL_En )
//    {
//        BTK_ESCL_Init();
//    }
}

void HAL_Set_HALVersion(float Value)
{
    HAL_Version = Value;

}

void HAL_Get_SwitchKey_Test(void)
{
    /*		Test For Switch		*/
    if( hIOP_CruiseKey_V == 5 )
    {
        CruiseKeyResistance = 10000000;
    }
    else if( hIOP_CruiseKey_V == 0 )
    {
        CruiseKeyResistance = 0;
    }
    else
    {
        CruiseKeyResistance = (uint32_t)(hIOP_CruiseKey_V / (hIOP_PCBTemp_V * 2 - hIOP_CruiseKey_V) * 500.0);
    }

    if( (CruiseKeyResistance > 1200) && (CruiseKeyResistance < 1700) )  //Cancel Key
    {
        VINP_CruiseKeyCancel_flg = 1;
        VINP_CruiseKeySet_flg = 0;
        VINP_CruiseKeyRes_flg = 0;
        VINP_CruiseKeyOnOff_flg = 0;
    }
    else if( (CruiseKeyResistance > 500) && (CruiseKeyResistance < 650) )  //Set Key
    {
        VINP_CruiseKeyCancel_flg = 0;
        VINP_CruiseKeySet_flg = 1;
        VINP_CruiseKeyRes_flg = 0;
        VINP_CruiseKeyOnOff_flg = 0;
    }
    else if( (CruiseKeyResistance > 150) && (CruiseKeyResistance < 250) )  //Res Key
    {
        VINP_CruiseKeyCancel_flg = 0;
        VINP_CruiseKeySet_flg = 0;
        VINP_CruiseKeyRes_flg = 1;
        VINP_CruiseKeyOnOff_flg = 0;
    }
    else if( CruiseKeyResistance < 10 )		//ON Key
    {
        VINP_CruiseKeyCancel_flg = 0;
        VINP_CruiseKeySet_flg = 0;
        VINP_CruiseKeyRes_flg = 0;
        VINP_CruiseKeyOnOff_flg = 1;
    }
    else
    {
        VINP_CruiseKeyCancel_flg = 0;
        VINP_CruiseKeySet_flg = 0;
        VINP_CruiseKeyRes_flg = 0;
        VINP_CruiseKeyOnOff_flg = 0;
    }
}

void HAL_Get_SwitchKey_S11P01(void)
{
    /*		Test For Switch		*/
    if( hIOP_CruiseKey_V == 5 )
    {
        CruiseKeyResistance = 10000000;
    }
    else if( hIOP_CruiseKey_V == 0 )
    {
        CruiseKeyResistance = 0;
    }
    else
    {
        CruiseKeyResistance = (uint32_t)(hIOP_CruiseKey_V / (hIOP_PCBTemp_V * 2 - hIOP_CruiseKey_V) * 499.0);
    }

    if( (CruiseKeyResistance > 50) && (CruiseKeyResistance < 150) )  //DIS/- Key
    {
        //VINP_CruiseKeyOnOff_flg = 0;
        //VINP_CruiseKeyCancel_flg = 0;
        VINP_CruiseKeySet_flg = 0;
        VINP_CruiseKeyRes_flg = 0;
    }
    else if( (CruiseKeyResistance > 180) && (CruiseKeyResistance < 350) )  //DIS/+ Key
    {
        //VINP_CruiseKeyOnOff_flg = 0;
        //VINP_CruiseKeyCancel_flg = 0;
        VINP_CruiseKeySet_flg = 0;
        VINP_CruiseKeyRes_flg = 0;
    }
    else if( (CruiseKeyResistance > 450) && (CruiseKeyResistance < 800) )  //SET/- Key
    {
        //VINP_CruiseKeyOnOff_flg = 0;
        //VINP_CruiseKeyCancel_flg = 0;
        VINP_CruiseKeySet_flg = 1;
        VINP_CruiseKeyRes_flg = 0;
    }
    else if( (CruiseKeyResistance > 1000) && (CruiseKeyResistance < 2000) )  //RES/+ Key
    {
        //VINP_CruiseKeyOnOff_flg = 0;
        //VINP_CruiseKeyCancel_flg = 0;
        VINP_CruiseKeySet_flg = 0;
        VINP_CruiseKeyRes_flg = 1;
    }
    else
    {
        //VINP_CruiseKeyOnOff_flg = 0;
        //VINP_CruiseKeyCancel_flg = 0;
        VINP_CruiseKeySet_flg = 0;
        VINP_CruiseKeyRes_flg = 0;

        if( CruiseKeyResistance > 20000 )  	//开路故障
        {
            CruiseKeyFaultCode = 1;
        }
        else if( CruiseKeyResistance <= 50 )  	//短路故障
        {
            CruiseKeyFaultCode = 2;
        }
        else
        {
            CruiseKeyFaultCode = 0;	//无故障
        }
    }
}

void HAL_Get_SwitchKey_None(void)
{
    VINP_CruiseKeyOnOff_flg = 0;
    VINP_CruiseKeyCancel_flg = 0;
    VINP_CruiseKeySet_flg = 0;
    VINP_CruiseKeyRes_flg = 0;
}

void Init_CANRxMessage_K11(void)
{

    CAN_Set_ID(CAN3, CHANNEL_1, Rx_Flag, STD_ID, 8, ID_Fun_UDS); // UDS functional request 0x7DF/0x700
    CAN_Set_ID(CAN3, CHANNEL_2, Rx_Flag, STD_ID, 8, BCCP_CRO_ID); //CCP command 0x100
    CAN_Set_ID(CAN3, CHANNEL_3, Rx_Flag, STD_ID, 8, 0x113); //BMS_113    Receive Period:10 ms
    CAN_Set_ID(CAN3, CHANNEL_4, Rx_Flag, STD_ID, 8, 0x213); //BMS_213    Receive Period:10 ms
    CAN_Set_ID(CAN3, CHANNEL_5, Rx_Flag, STD_ID, 8, 0x233); //BMS_233    Receive Period:100 ms
    CAN_Set_ID(CAN3, CHANNEL_6, Rx_Flag, STD_ID, 8, 0x303); //BMS_303    Receive Period:100 ms
    CAN_Set_ID(CAN3, CHANNEL_7, Rx_Flag, STD_ID, 8, 0x313); //BMS_313    Receive Period:100 ms
    CAN_Set_ID(CAN3, CHANNEL_8, Rx_Flag, STD_ID, 8, 0x323); //BMS_323    Receive Period:1000 ms
    CAN_Set_ID(CAN3, CHANNEL_9, Rx_Flag, STD_ID, 8, 0x377); //BMS_377    Receive Period:10 ms
    CAN_Set_ID(CAN3, CHANNEL_10, Rx_Flag, STD_ID, 8, 0x513); //BMS_513   Receive Period:1000 ms
    CAN_Set_ID(CAN3, CHANNEL_11, Rx_Flag, STD_ID, 8, 0x633); //BMS_633   Receive Period:100 ms
    CAN_Set_ID(CAN3, CHANNEL_12, Rx_Flag, STD_ID, 8, 0x115); //MCU_115   Receive Period:10 ms
    CAN_Set_ID(CAN3, CHANNEL_13, Rx_Flag, STD_ID, 8, 0x125); //MCU_125   Receive Period:10 ms
    CAN_Set_ID(CAN3, CHANNEL_14, Rx_Flag, STD_ID, 8, 0x215); //MCU_215   Receive Period:1000 ms
    CAN_Set_ID(CAN3, CHANNEL_15, Rx_Flag, STD_ID, 8, 0x515); //MCU_515   Receive Period:1000 ms
    CAN_Set_ID(CAN3, CHANNEL_16, Rx_Flag, STD_ID, 8, 0x231); //DCDC_231  Receive Period:100 ms
    CAN_Set_ID(CAN3, CHANNEL_17, Rx_Flag, STD_ID, 8, 0x251); //DCDC_251  Receive Period:100 ms
    CAN_Set_ID(CAN3, CHANNEL_18, Rx_Flag, STD_ID, 8, 0x311); //OBC_311   Receive Period:100 ms
    CAN_Set_ID(CAN3, CHANNEL_19, Rx_Flag, STD_ID, 8, 0x321); //OBC_321   Receive Period:10 ms
    CAN_Set_ID(CAN3, CHANNEL_20, Rx_Flag, STD_ID, 8, 0x331); //OBC_331   Receive Period:100 ms
    CAN_Set_ID(CAN3, CHANNEL_21, Rx_Flag, STD_ID, 8, 0x613); //BMS_613    Receive Period:1000 ms
    CAN_Set_ID(CAN3, CHANNEL_22, Rx_Flag, STD_ID, 8, 0x34C); //ECC_34C   Receive Period:100 ms
    CAN_Set_ID(CAN3, CHANNEL_23, Rx_Flag, STD_ID, 8, 0x35C); //ECC_35C   Receive Period:100 ms
    CAN_Set_ID(CAN3, CHANNEL_24, Rx_Flag, STD_ID, 8, 0x108); //PEPS_108  Receive Period:0 ms
    CAN_Set_ID(CAN3, CHANNEL_25, Rx_Flag, STD_ID, 8, 0x103); //PEPS_103  Receive Period:0 ms
    CAN_Set_ID(CAN3, CHANNEL_26, Rx_Flag, STD_ID, 4, 0x50); //SRS_050    Receive Period:300 ms
    CAN_Set_ID(CAN3, CHANNEL_27, Rx_Flag, STD_ID, 8, 0x232); //ABS_232   Receive Period:20 ms
    CAN_Set_ID(CAN3, CHANNEL_28, Rx_Flag, STD_ID, 8, 0x304); //BMS_304    Receive Period:10 ms
    CAN_Set_ID(CAN3, CHANNEL_29, Rx_Flag, STD_ID, 8, 0x345); //EHU_345    Receive Period:500 ms
    CAN_Set_ID(CAN3, CHANNEL_30, Rx_Flag, STD_ID, 8, 0x349); //EAC_349   Receive Period:100 ms
    CAN_Set_ID(CAN3, CHANNEL_31, Rx_Flag, STD_ID, 8, 0x298); //TBOX_298  Receive Period:500 ms
    CAN_Set_ID(CAN3, CHANNEL_32, Rx_Flag, STD_ID, 8, 0x422); //GW_422h   Receive Period:0 ms
    CAN_Set_ID(CAN3, CHANNEL_33, Rx_Flag, STD_ID, 8, 0x237); //ABS_237   Receive Period:20 ms
    CAN_Set_ID(CAN3, CHANNEL_34, Rx_Flag, STD_ID, 8, 0x2A0); //EPS_2A0   Receive Period:20 ms
    CAN_Set_ID(CAN3, CHANNEL_35, Rx_Flag, STD_ID, 8, 0x180); //EPS_180   Receive Period:20 ms
    CAN_Set_ID(CAN3, CHANNEL_36, Rx_Flag, STD_ID, 8, 0x603); //BMS_603   Receive Period:1000 ms
    CAN_Set_ID(CAN3, CHANNEL_37, Rx_Flag, STD_ID, 8, 0x653); //BMS_653   Receive Period:100 ms
    CAN_Set_ID(CAN3, CHANNEL_38, Rx_Flag, STD_ID, 8, 0x36C); //ECC_36C   Receive Period:100 ms
    CAN_Set_ID(CAN3, CHANNEL_39, Rx_Flag, STD_ID, 8, 0x229); //ABS_229   Receive Period:20 ms
    CAN_Set_ID(CAN3, CHANNEL_40, Rx_Flag, STD_ID, 8, 0x234); //ICM_234   Receive Period:500 ms
    CAN_Set_ID(CAN3, CHANNEL_41, Rx_Flag, STD_ID, 8, 0x282); //PEPS_282   Receive Period:500 ms
    PTCAN_RxReal_Num = 42;

}

void Init_CANRxMessage_K11P01(void)
{

    CAN_Set_ID(CAN3, CHANNEL_1, Rx_Flag, STD_ID, 8, ID_Fun_UDS); // UDS functional request 0x7DF/0x700
    CAN_Set_ID(CAN3, CHANNEL_2, Rx_Flag, STD_ID, 8, BCCP_CRO_ID); //CCP command 0x100
    CAN_Set_ID(CAN3, CHANNEL_3, Rx_Flag, STD_ID, 8, 0x113); //BMS_113    Receive Period:10 ms
    CAN_Set_ID(CAN3, CHANNEL_4, Rx_Flag, STD_ID, 8, 0x213); //BMS_213    Receive Period:10 ms
    CAN_Set_ID(CAN3, CHANNEL_5, Rx_Flag, STD_ID, 8, 0x233); //BMS_233    Receive Period:100 ms
    CAN_Set_ID(CAN3, CHANNEL_6, Rx_Flag, STD_ID, 8, 0x303); //BMS_303    Receive Period:100 ms
    CAN_Set_ID(CAN3, CHANNEL_7, Rx_Flag, STD_ID, 8, 0x313); //BMS_313    Receive Period:100 ms
    CAN_Set_ID(CAN3, CHANNEL_8, Rx_Flag, STD_ID, 8, 0x323); //BMS_323    Receive Period:1000 ms
    CAN_Set_ID(CAN3, CHANNEL_9, Rx_Flag, STD_ID, 8, 0x377); //BMS_377    Receive Period:10 ms
    CAN_Set_ID(CAN3, CHANNEL_10, Rx_Flag, STD_ID, 8, 0x513); //BMS_513   Receive Period:1000 ms
    CAN_Set_ID(CAN3, CHANNEL_11, Rx_Flag, STD_ID, 8, 0x633); //BMS_633   Receive Period:100 ms
    CAN_Set_ID(CAN3, CHANNEL_12, Rx_Flag, STD_ID, 8, 0x115); //MCU_115   Receive Period:10 ms
    CAN_Set_ID(CAN3, CHANNEL_13, Rx_Flag, STD_ID, 8, 0x125); //MCU_125   Receive Period:10 ms
    CAN_Set_ID(CAN3, CHANNEL_14, Rx_Flag, STD_ID, 8, 0x215); //MCU_215   Receive Period:1000 ms
    CAN_Set_ID(CAN3, CHANNEL_15, Rx_Flag, STD_ID, 8, 0x515); //MCU_515   Receive Period:1000 ms
    CAN_Set_ID(CAN3, CHANNEL_16, Rx_Flag, STD_ID, 8, 0x231); //DCDC_231  Receive Period:100 ms
    CAN_Set_ID(CAN3, CHANNEL_17, Rx_Flag, STD_ID, 8, 0x251); //DCDC_251  Receive Period:100 ms
    CAN_Set_ID(CAN3, CHANNEL_18, Rx_Flag, STD_ID, 8, 0x311); //OBC_311   Receive Period:100 ms
    CAN_Set_ID(CAN3, CHANNEL_19, Rx_Flag, STD_ID, 8, 0x321); //OBC_321   Receive Period:10 ms
    CAN_Set_ID(CAN3, CHANNEL_20, Rx_Flag, STD_ID, 8, 0x331); //OBC_331   Receive Period:100 ms
    CAN_Set_ID(CAN3, CHANNEL_21, Rx_Flag, STD_ID, 8, 0x613); //BMS_613    Receive Period:1000 ms
    CAN_Set_ID(CAN3, CHANNEL_22, Rx_Flag, STD_ID, 8, 0x34C); //ECC_34C   Receive Period:100 ms
    CAN_Set_ID(CAN3, CHANNEL_23, Rx_Flag, STD_ID, 8, 0x35C); //ECC_35C   Receive Period:100 ms
    CAN_Set_ID(CAN3, CHANNEL_24, Rx_Flag, STD_ID, 8, 0x108); //PEPS_108  Receive Period:0 ms
    CAN_Set_ID(CAN3, CHANNEL_25, Rx_Flag, STD_ID, 8, 0x103); //PEPS_103  Receive Period:0 ms
    CAN_Set_ID(CAN3, CHANNEL_26, Rx_Flag, STD_ID, 4, 0x50); //SRS_050    Receive Period:300 ms
    CAN_Set_ID(CAN3, CHANNEL_27, Rx_Flag, STD_ID, 8, 0x232); //ABS_232   Receive Period:20 ms
    CAN_Set_ID(CAN3, CHANNEL_28, Rx_Flag, STD_ID, 8, 0x304); //BMS_304    Receive Period:10 ms
    CAN_Set_ID(CAN3, CHANNEL_29, Rx_Flag, STD_ID, 8, 0x345); //EHU_345    Receive Period:500 ms
    CAN_Set_ID(CAN3, CHANNEL_30, Rx_Flag, STD_ID, 8, 0x349); //EAC_349   Receive Period:100 ms
    CAN_Set_ID(CAN3, CHANNEL_31, Rx_Flag, STD_ID, 8, 0x298); //TBOX_298  Receive Period:500 ms
    CAN_Set_ID(CAN3, CHANNEL_32, Rx_Flag, STD_ID, 8, 0x422); //GW_422h   Receive Period:0 ms
    CAN_Set_ID(CAN3, CHANNEL_33, Rx_Flag, STD_ID, 8, 0x237); //ABS_237   Receive Period:20 ms
    CAN_Set_ID(CAN3, CHANNEL_34, Rx_Flag, STD_ID, 8, 0x2A0); //EPS_2A0   Receive Period:20 ms
    CAN_Set_ID(CAN3, CHANNEL_35, Rx_Flag, STD_ID, 8, 0x180); //EPS_180   Receive Period:20 ms
    CAN_Set_ID(CAN3, CHANNEL_36, Rx_Flag, STD_ID, 8, 0x603); //BMS_603   Receive Period:1000 ms
    CAN_Set_ID(CAN3, CHANNEL_37, Rx_Flag, STD_ID, 8, 0x653); //BMS_653   Receive Period:100 ms
    CAN_Set_ID(CAN3, CHANNEL_38, Rx_Flag, STD_ID, 8, 0x36C); //ECC_36C   Receive Period:100 ms
    CAN_Set_ID(CAN3, CHANNEL_39, Rx_Flag, STD_ID, 8, 0x229); //ABS_229   Receive Period:20 ms
    CAN_Set_ID(CAN3, CHANNEL_40, Rx_Flag, STD_ID, 8, 0x234); //ICM_234   Receive Period:500 ms
    CAN_Set_ID(CAN3, CHANNEL_41, Rx_Flag, STD_ID, 8, 0x282); //PEPS_282   Receive Period:500 ms
    CAN_Set_ID(CAN3, CHANNEL_42, Rx_Flag, STD_ID, 8, 0x623); //BMS_623    Receive Period:1000 ms
    PTCAN_RxReal_Num = 43;

}

/************************************************************************************    CAN    ****/
void Init_CANRxMessage_S11(void)
{
    //CAN_Set_ID (CAN3, CHANNEL_0, Rx_Flag, STD_ID, 8,  ID_Phy_UDS); // Core0 send using
    CAN_Set_ID(CAN3, CHANNEL_1, Rx_Flag, STD_ID, 8, ID_Fun_UDS); // UDS functional request 0x7DF/0x700
    CAN_Set_ID(CAN3, CHANNEL_2, Rx_Flag, STD_ID, 8, BCCP_CRO_ID); //CCP command 0x100
    //CAN_Set_ID(CAN3, CHANNEL_3, Rx_Flag, STD_ID, 8, 0x113); //BMS_113    Receive Period:10 ms
    CAN_Set_ID(CAN3, CHANNEL_3, Rx_Flag, STD_ID, 8, 0x101);
    CAN_Set_ID(CAN3, CHANNEL_4, Rx_Flag, STD_ID, 8, 0x213); //BMS_213    Receive Period:10 ms
    CAN_Set_ID(CAN3, CHANNEL_5, Rx_Flag, STD_ID, 8, 0x233); //BMS_233    Receive Period:100 ms
    CAN_Set_ID(CAN3, CHANNEL_6, Rx_Flag, STD_ID, 8, 0x303); //BMS_303    Receive Period:100 ms
    CAN_Set_ID(CAN3, CHANNEL_7, Rx_Flag, STD_ID, 8, 0x313); //BMS_313    Receive Period:100 ms
    CAN_Set_ID(CAN3, CHANNEL_8, Rx_Flag, STD_ID, 8, 0x323); //BMS_323    Receive Period:1000 ms
    CAN_Set_ID(CAN3, CHANNEL_9, Rx_Flag, STD_ID, 8, 0x377); //BMS_377    Receive Period:10 ms
    CAN_Set_ID(CAN3, CHANNEL_10, Rx_Flag, STD_ID, 8, 0x513); //BMS_513   Receive Period:1000 ms
    CAN_Set_ID(CAN3, CHANNEL_11, Rx_Flag, STD_ID, 8, 0x633); //BMS_633   Receive Period:100 ms
    CAN_Set_ID(CAN3, CHANNEL_12, Rx_Flag, STD_ID, 8, 0x115); //MCU_115   Receive Period:10 ms
    CAN_Set_ID(CAN3, CHANNEL_13, Rx_Flag, STD_ID, 8, 0x125); //MCU_125   Receive Period:10 ms
    CAN_Set_ID(CAN3, CHANNEL_14, Rx_Flag, STD_ID, 8, 0x215); //MCU_215   Receive Period:1000 ms
    CAN_Set_ID(CAN3, CHANNEL_15, Rx_Flag, STD_ID, 8, 0x515); //MCU_515   Receive Period:1000 ms
    CAN_Set_ID(CAN3, CHANNEL_16, Rx_Flag, STD_ID, 8, 0x231); //DCDC_231  Receive Period:100 ms
    CAN_Set_ID(CAN3, CHANNEL_17, Rx_Flag, STD_ID, 8, 0x251); //DCDC_251  Receive Period:100 ms
    CAN_Set_ID(CAN3, CHANNEL_18, Rx_Flag, STD_ID, 8, 0x311); //OBC_311   Receive Period:100 ms
    CAN_Set_ID(CAN3, CHANNEL_19, Rx_Flag, STD_ID, 8, 0x321); //OBC_321   Receive Period:2 ms
    CAN_Set_ID(CAN3, CHANNEL_20, Rx_Flag, STD_ID, 8, 0x331); //OBC_331   Receive Period:100 ms
    CAN_Set_ID(CAN3, CHANNEL_21, Rx_Flag, STD_ID, 8, 0x5DA); //PTC_5DA   Receive Period:500 ms
    CAN_Set_ID(CAN3, CHANNEL_22, Rx_Flag, STD_ID, 8, 0x34C); //ECC_34C   Receive Period:100 ms
    CAN_Set_ID(CAN3, CHANNEL_23, Rx_Flag, STD_ID, 8, 0x35C); //ECC_35C   Receive Period:100 ms
    CAN_Set_ID(CAN3, CHANNEL_24, Rx_Flag, STD_ID, 8, 0x108); //PEPS_108  Receive Period:0 ms
    CAN_Set_ID(CAN3, CHANNEL_25, Rx_Flag, STD_ID, 8, 0x103); //PEPS_103  Receive Period:0 ms
    CAN_Set_ID(CAN3, CHANNEL_26, Rx_Flag, STD_ID, 4, 0x50); //SRS_050    Receive Period:300 ms
    CAN_Set_ID(CAN3, CHANNEL_27, Rx_Flag, STD_ID, 8, 0x232); //ABS_232   Receive Period:20 ms
    CAN_Set_ID(CAN3, CHANNEL_28, Rx_Flag, STD_ID, 8, 0x217); //GW_217    Receive Period:20 ms
    CAN_Set_ID(CAN3, CHANNEL_29, Rx_Flag, STD_ID, 8, 0x522); //GW_522    Receive Period:500 ms
    CAN_Set_ID(CAN3, CHANNEL_30, Rx_Flag, STD_ID, 8, 0x349); //EAC_349   Receive Period:100 ms
    CAN_Set_ID(CAN3, CHANNEL_31, Rx_Flag, STD_ID, 8, 0x298); //TBOX_298  Receive Period:500 ms
    CAN_Set_ID(CAN3, CHANNEL_32, Rx_Flag, STD_ID, 8, 0x405); //GW_405h   Receive Period:0 ms
    CAN_Set_ID(CAN3, CHANNEL_33, Rx_Flag, STD_ID, 8, 0x237); //ABS_237   Receive Period:20 ms
    CAN_Set_ID(CAN3, CHANNEL_34, Rx_Flag, STD_ID, 8, 0x33C); //ECC_33C   Receive Period:100 ms
    CAN_Set_ID(CAN3, CHANNEL_35, Rx_Flag, STD_ID, 8, 0x317); //TPMS_317  Receive Period:500 ms
    CAN_Set_ID(CAN3, CHANNEL_36, Rx_Flag, STD_ID, 8, 0x3A2); //TPMS_3A2  Receive Period:500 ms
    CAN_Set_ID(CAN3, CHANNEL_37, Rx_Flag, STD_ID, 8, 0x603); //BMS_603   Receive Period:1000 ms
    CAN_Set_ID(CAN3, CHANNEL_38, Rx_Flag, STD_ID, 8, 0x653); //BMS_653   Receive Period:100 ms
    CAN_Set_ID(CAN3, CHANNEL_39, Rx_Flag, STD_ID, 8, 0x36C); //ECC_36C   Receive Period:100 ms
    CAN_Set_ID(CAN3, CHANNEL_40, Rx_Flag, STD_ID, 8, 0x296); //TBOX_296  Receive Period:500 ms
    CAN_Set_ID(CAN3, CHANNEL_41, Rx_Flag, STD_ID, 8, 0x5DB); //PTC_5DB  S11P01  Receive Period:500 ms
    CAN_Set_ID(CAN3, CHANNEL_42, Rx_Flag, STD_ID, 8, 0x2F0); //WPTC_2F0 S11P01  Receive Period:100 ms
    CAN_Set_ID(CAN3, CHANNEL_43, Rx_Flag, STD_ID, 8, 0x2C0); //TMS_2C0  S11P01  Receive Period:100 ms
    CAN_Set_ID(CAN3, CHANNEL_44, Rx_Flag, STD_ID, 8, 0x2C1); //TMS_2C1  S11P01  Receive Period:100 ms
    CAN_Set_ID(CAN3, CHANNEL_45, Rx_Flag, STD_ID, 8, 0x2C2); //TMS_2C2  S11P01  Receive Period:100 ms
    CAN_Set_ID(CAN3, CHANNEL_46, Rx_Flag, STD_ID, 8, 0x2C3); //TMS_2C3  S11P01  Receive Period:100 ms
    CAN_Set_ID(CAN3, CHANNEL_47, Rx_Flag, STD_ID, 8, 0x304); //BMS_304    Receive Period:10 ms
    CAN_Set_ID(CAN3, CHANNEL_48, Rx_Flag, STD_ID, 8, 0x613); //BMS_613    Receive Period:1000 ms
    CAN_Set_ID(CAN3, CHANNEL_49, Rx_Flag, STD_ID, 8, 0x623); //BMS_623    Receive Period:1000 ms
    //CAN_Set_ID(CAN3, CHANNEL_50, Rx_Flag, STD_ID, 8, 0x34A); //EAC_34A  S11P01  Receive Period:100 ms
    //CAN_Set_ID(CAN3, CHANNEL_50, Rx_Flag, STD_ID, 8, 0x101); //LZC  S11  Receive Period:100 ms
    PTCAN_RxReal_Num = 51;

    //CAN_Set_ID (CAN0, CHANNEL_0, Rx_Flag, STD_ID, 8,  ID_Phy_UDS);
    //CAN_Set_ID (CAN0, CHANNEL_1, Rx_Flag, STD_ID, 8,  ID_Fun_UDS);
    CAN_Set_ID(CAN0, CHANNEL_2, Rx_Flag, EXT_ID, 8, ID_VCUHW_UDS);
    CAN_Set_ID(CAN0, CHANNEL_3, Rx_Flag, STD_ID, 8, BCCP_CRO_ID);
    CSCAN_RxReal_Num = 4;
}

void Init_CANRxMessage_S11P01(void)
{
//动力CAN
    //CAN_Set_ID (CAN3, CHANNEL_0, Rx_Flag, STD_ID, 8,  ID_Phy_UDS); // Core0 send using
    CAN_Set_ID(CAN3, CHANNEL_1, Rx_Flag, STD_ID, 8, ID_Fun_UDS); // UDS functional request 0x7DF/0x700
    CAN_Set_ID(CAN3, CHANNEL_2, Rx_Flag, STD_ID, 8, BCCP_CRO_ID); //CCP command 0x100
    CAN_Set_ID(CAN3, CHANNEL_3, Rx_Flag, STD_ID, 8, 0x113); //BMS_113
    CAN_Set_ID(CAN3, CHANNEL_4, Rx_Flag, STD_ID, 8, 0x213); //BMS_213
    CAN_Set_ID(CAN3, CHANNEL_5, Rx_Flag, STD_ID, 8, 0x233); //BMS_233
    CAN_Set_ID(CAN3, CHANNEL_6, Rx_Flag, STD_ID, 8, 0x305); //BMS_305
    CAN_Set_ID(CAN3, CHANNEL_7, Rx_Flag, STD_ID, 8, 0x306); //BMS_306
    CAN_Set_ID(CAN3, CHANNEL_8, Rx_Flag, STD_ID, 8, 0x313); //BMS_313
    CAN_Set_ID(CAN3, CHANNEL_9, Rx_Flag, STD_ID, 8, 0x323); //BMS_323
    CAN_Set_ID(CAN3, CHANNEL_10, Rx_Flag, STD_ID, 8, 0x377); //BMS_377
    CAN_Set_ID(CAN3, CHANNEL_11, Rx_Flag, STD_ID, 8, 0x513); //BMS_513
    CAN_Set_ID(CAN3, CHANNEL_12, Rx_Flag, STD_ID, 8, 0x603); //BMS_603
    CAN_Set_ID(CAN3, CHANNEL_13, Rx_Flag, STD_ID, 8, 0x613); //BMS_613
    CAN_Set_ID(CAN3, CHANNEL_14, Rx_Flag, STD_ID, 8, 0x623); //BMS_623
    CAN_Set_ID(CAN3, CHANNEL_15, Rx_Flag, STD_ID, 8, 0x633); //BMS_633
    CAN_Set_ID(CAN3, CHANNEL_16, Rx_Flag, STD_ID, 8, 0x653); //BMS_653
    CAN_Set_ID(CAN3, CHANNEL_17, Rx_Flag, STD_ID, 8, 0x115); //MCU_115
    CAN_Set_ID(CAN3, CHANNEL_18, Rx_Flag, STD_ID, 8, 0x125); //MCU_125
    CAN_Set_ID(CAN3, CHANNEL_19, Rx_Flag, STD_ID, 8, 0x215); //MCU_215
    CAN_Set_ID(CAN3, CHANNEL_20, Rx_Flag, STD_ID, 8, 0x515); //MCU_515
    CAN_Set_ID(CAN3, CHANNEL_21, Rx_Flag, STD_ID, 8, 0x231); //DCDC_231
    CAN_Set_ID(CAN3, CHANNEL_22, Rx_Flag, STD_ID, 8, 0x251); //DCDC_251
    CAN_Set_ID(CAN3, CHANNEL_23, Rx_Flag, STD_ID, 8, 0x311); //OBC_311
    CAN_Set_ID(CAN3, CHANNEL_24, Rx_Flag, STD_ID, 8, 0x321); //OBC_321
    CAN_Set_ID(CAN3, CHANNEL_25, Rx_Flag, STD_ID, 8, 0x331); //OBC_331
    CAN_Set_ID(CAN3, CHANNEL_26, Rx_Flag, STD_ID, 8, 0x5DA); //PTC_5DA
    CAN_Set_ID(CAN3, CHANNEL_27, Rx_Flag, STD_ID, 8, 0x5DB); //PTC_5DB
    CAN_Set_ID(CAN3, CHANNEL_28, Rx_Flag, STD_ID, 8, 0x33C); //ECC_33C
    CAN_Set_ID(CAN3, CHANNEL_29, Rx_Flag, STD_ID, 8, 0x34C); //ECC_34C
    CAN_Set_ID(CAN3, CHANNEL_30, Rx_Flag, STD_ID, 8, 0x35C); //ECC_35C
    CAN_Set_ID(CAN3, CHANNEL_31, Rx_Flag, STD_ID, 8, 0x108); //PEPS_108
    CAN_Set_ID(CAN3, CHANNEL_32, Rx_Flag, STD_ID, 8, 0x405); //GW_405h
    CAN_Set_ID(CAN3, CHANNEL_33, Rx_Flag, STD_ID, 8, 0x282); //PEPS_282
    CAN_Set_ID(CAN3, CHANNEL_34, Rx_Flag, STD_ID, 4, 0x50); //SRS_050
    CAN_Set_ID(CAN3, CHANNEL_35, Rx_Flag, STD_ID, 8, 0x522); //GW_522
    CAN_Set_ID(CAN3, CHANNEL_36, Rx_Flag, STD_ID, 8, 0x349); //EAC_349
    CAN_Set_ID(CAN3, CHANNEL_37, Rx_Flag, STD_ID, 8, 0x34A); //EAC_34A
    CAN_Set_ID(CAN3, CHANNEL_38, Rx_Flag, STD_ID, 8, 0x296); //TBOX_296
    CAN_Set_ID(CAN3, CHANNEL_39, Rx_Flag, STD_ID, 8, 0x298); //TBOX_298
    CAN_Set_ID(CAN3, CHANNEL_40, Rx_Flag, STD_ID, 8, 0x317); //TPMS_317
    CAN_Set_ID(CAN3, CHANNEL_41, Rx_Flag, STD_ID, 8, 0x3A2); //TPMS_3A2
    CAN_Set_ID(CAN3, CHANNEL_42, Rx_Flag, STD_ID, 8, 0x2C0); //TMS_2C0
    CAN_Set_ID(CAN3, CHANNEL_43, Rx_Flag, STD_ID, 8, 0x2C1); //TMS_2C1
    CAN_Set_ID(CAN3, CHANNEL_44, Rx_Flag, STD_ID, 8, 0x2C2); //TMS_2C2
    CAN_Set_ID(CAN3, CHANNEL_45, Rx_Flag, STD_ID, 8, 0x2C3); //TMS_2C3
    CAN_Set_ID(CAN3, CHANNEL_46, Rx_Flag, STD_ID, 8, 0x2F0); //WPTC_2F0
    CAN_Set_ID(CAN3, CHANNEL_47, Rx_Flag, STD_ID, 8, 0x103); //PEPS_103
    CAN_Set_ID(CAN3, CHANNEL_48, Rx_Flag, STD_ID, 8, 0x312); //BCM_312
    CAN_Set_ID(CAN3, CHANNEL_49, Rx_Flag, STD_ID, 8, 0x235); //ICM_235
    CAN_Set_ID(CAN3, CHANNEL_50, Rx_Flag, STD_ID, 8, 0x36C); //ECC_36C
    PTCAN_RxReal_Num = 51;
//底盘CAN
    //CAN_Set_ID (CAN0, CHANNEL_0, Rx_Flag, STD_ID, 8,  ID_Phy_UDS);
    //CAN_Set_ID (CAN0, CHANNEL_1, Rx_Flag, STD_ID, 8,  ID_Fun_UDS);
    CAN_Set_ID(CAN0, CHANNEL_2, Rx_Flag, EXT_ID, 8, ID_VCUHW_UDS);
    CAN_Set_ID(CAN0, CHANNEL_3, Rx_Flag, STD_ID, 8, 0x229);  //ABS_229
    CAN_Set_ID(CAN0, CHANNEL_4, Rx_Flag, STD_ID, 8, 0x232);  //ABS_232
    CAN_Set_ID(CAN0, CHANNEL_5, Rx_Flag, STD_ID, 8, 0x2A0);  //EPS_2A0
    CAN_Set_ID(CAN0, CHANNEL_6, Rx_Flag, STD_ID, 8, 0x180);  //EPS_180
    CAN_Set_ID(CAN0, CHANNEL_7, Rx_Flag, STD_ID, 8, 0x219);  //EPB_219
    CAN_Set_ID(CAN0, CHANNEL_8, Rx_Flag, STD_ID, 8, 0x281);  //FCW_281
    CAN_Set_ID(CAN0, CHANNEL_9, Rx_Flag, STD_ID, 8, 0x285);  //FCW_285
    CSCAN_RxReal_Num = 10;
}

void Init_CANRxMessage_S11P05(void)
{
//动力CAN
    //CAN_Set_ID (CAN3, CHANNEL_0, Rx_Flag, STD_ID, 8,  ID_Phy_UDS); // Core0 send using
    CAN_Set_ID(CAN3, CHANNEL_1, Rx_Flag, STD_ID, 8, ID_Fun_UDS); // UDS functional request 0x7DF/0x700
    CAN_Set_ID(CAN3, CHANNEL_2, Rx_Flag, STD_ID, 8, BCCP_CRO_ID); //CCP command 0x100
    CAN_Set_ID(CAN3, CHANNEL_3, Rx_Flag, STD_ID, 8, 0x113); //BMS_113
    CAN_Set_ID(CAN3, CHANNEL_4, Rx_Flag, STD_ID, 8, 0x213); //BMS_213
    CAN_Set_ID(CAN3, CHANNEL_5, Rx_Flag, STD_ID, 8, 0x233); //BMS_233
    CAN_Set_ID(CAN3, CHANNEL_6, Rx_Flag, STD_ID, 8, 0x305); //BMS_305
    CAN_Set_ID(CAN3, CHANNEL_7, Rx_Flag, STD_ID, 8, 0x306); //BMS_306
    CAN_Set_ID(CAN3, CHANNEL_8, Rx_Flag, STD_ID, 8, 0x313); //BMS_313
    CAN_Set_ID(CAN3, CHANNEL_9, Rx_Flag, STD_ID, 8, 0x323); //BMS_323
    CAN_Set_ID(CAN3, CHANNEL_10, Rx_Flag, STD_ID, 8, 0x377); //BMS_377
    CAN_Set_ID(CAN3, CHANNEL_11, Rx_Flag, STD_ID, 8, 0x513); //BMS_513
    CAN_Set_ID(CAN3, CHANNEL_12, Rx_Flag, STD_ID, 8, 0x603); //BMS_603
    CAN_Set_ID(CAN3, CHANNEL_13, Rx_Flag, STD_ID, 8, 0x613); //BMS_613
    CAN_Set_ID(CAN3, CHANNEL_14, Rx_Flag, STD_ID, 8, 0x623); //BMS_623
    CAN_Set_ID(CAN3, CHANNEL_15, Rx_Flag, STD_ID, 8, 0x633); //BMS_633
    CAN_Set_ID(CAN3, CHANNEL_16, Rx_Flag, STD_ID, 8, 0x653); //BMS_653
    CAN_Set_ID(CAN3, CHANNEL_17, Rx_Flag, STD_ID, 8, 0x115); //MCU_115
    CAN_Set_ID(CAN3, CHANNEL_18, Rx_Flag, STD_ID, 8, 0x125); //MCU_125
    CAN_Set_ID(CAN3, CHANNEL_19, Rx_Flag, STD_ID, 8, 0x215); //MCU_215
    CAN_Set_ID(CAN3, CHANNEL_20, Rx_Flag, STD_ID, 8, 0x515); //MCU_515
    CAN_Set_ID(CAN3, CHANNEL_21, Rx_Flag, STD_ID, 8, 0x231); //DCDC_231
    CAN_Set_ID(CAN3, CHANNEL_22, Rx_Flag, STD_ID, 8, 0x251); //DCDC_251
    CAN_Set_ID(CAN3, CHANNEL_23, Rx_Flag, STD_ID, 8, 0x311); //OBC_311
    CAN_Set_ID(CAN3, CHANNEL_24, Rx_Flag, STD_ID, 8, 0x321); //OBC_321
    CAN_Set_ID(CAN3, CHANNEL_25, Rx_Flag, STD_ID, 8, 0x331); //OBC_331
    CAN_Set_ID(CAN3, CHANNEL_26, Rx_Flag, STD_ID, 8, 0x5DA); //PTC_5DA
    CAN_Set_ID(CAN3, CHANNEL_27, Rx_Flag, STD_ID, 8, 0x5DB); //PTC_5DB
    CAN_Set_ID(CAN3, CHANNEL_28, Rx_Flag, STD_ID, 8, 0x33C); //ECC_33C
    CAN_Set_ID(CAN3, CHANNEL_29, Rx_Flag, STD_ID, 8, 0x34C); //ECC_34C
    CAN_Set_ID(CAN3, CHANNEL_30, Rx_Flag, STD_ID, 8, 0x35C); //ECC_35C
    CAN_Set_ID(CAN3, CHANNEL_31, Rx_Flag, STD_ID, 8, 0x108); //PEPS_108
    CAN_Set_ID(CAN3, CHANNEL_32, Rx_Flag, STD_ID, 8, 0x405); //GW_405h
    CAN_Set_ID(CAN3, CHANNEL_33, Rx_Flag, STD_ID, 8, 0x282); //PEPS_282
    CAN_Set_ID(CAN3, CHANNEL_34, Rx_Flag, STD_ID, 4, 0x50); //SRS_050
    CAN_Set_ID(CAN3, CHANNEL_35, Rx_Flag, STD_ID, 8, 0x522); //GW_522
    CAN_Set_ID(CAN3, CHANNEL_36, Rx_Flag, STD_ID, 8, 0x349); //EAC_349
    CAN_Set_ID(CAN3, CHANNEL_37, Rx_Flag, STD_ID, 8, 0x34A); //EAC_34A
    CAN_Set_ID(CAN3, CHANNEL_38, Rx_Flag, STD_ID, 8, 0x296); //TBOX_296
    CAN_Set_ID(CAN3, CHANNEL_39, Rx_Flag, STD_ID, 8, 0x298); //TBOX_298
    CAN_Set_ID(CAN3, CHANNEL_40, Rx_Flag, STD_ID, 8, 0x317); //TPMS_317
    CAN_Set_ID(CAN3, CHANNEL_41, Rx_Flag, STD_ID, 8, 0x3A2); //TPMS_3A2
    CAN_Set_ID(CAN3, CHANNEL_42, Rx_Flag, STD_ID, 8, 0x2C0); //TMS_2C0
    CAN_Set_ID(CAN3, CHANNEL_43, Rx_Flag, STD_ID, 8, 0x2C1); //TMS_2C1
    CAN_Set_ID(CAN3, CHANNEL_44, Rx_Flag, STD_ID, 8, 0x2C2); //TMS_2C2
    CAN_Set_ID(CAN3, CHANNEL_45, Rx_Flag, STD_ID, 8, 0x2C3); //TMS_2C3
    CAN_Set_ID(CAN3, CHANNEL_46, Rx_Flag, STD_ID, 8, 0x2F0); //WPTC_2F0
    CAN_Set_ID(CAN3, CHANNEL_47, Rx_Flag, STD_ID, 8, 0x103); //PEPS_103
    CAN_Set_ID(CAN3, CHANNEL_48, Rx_Flag, STD_ID, 8, 0x312); //BCM_312
    CAN_Set_ID(CAN3, CHANNEL_49, Rx_Flag, STD_ID, 8, 0x235); //ICM_235
    CAN_Set_ID(CAN3, CHANNEL_50, Rx_Flag, STD_ID, 8, 0x36C); //ECC_36C
    PTCAN_RxReal_Num = 51;
//底盘CAN
    //CAN_Set_ID (CAN0, CHANNEL_0, Rx_Flag, STD_ID, 8,  ID_Phy_UDS);
    //CAN_Set_ID (CAN0, CHANNEL_1, Rx_Flag, STD_ID, 8,  ID_Fun_UDS);
    CAN_Set_ID(CAN0, CHANNEL_2, Rx_Flag, EXT_ID, 8, ID_VCUHW_UDS);
    CAN_Set_ID(CAN0, CHANNEL_3, Rx_Flag, STD_ID, 8, 0x229);  //ABS_229
    CAN_Set_ID(CAN0, CHANNEL_4, Rx_Flag, STD_ID, 8, 0x232);  //ABS_232
    CAN_Set_ID(CAN0, CHANNEL_5, Rx_Flag, STD_ID, 8, 0x2A0);  //EPS_2A0
    CAN_Set_ID(CAN0, CHANNEL_6, Rx_Flag, STD_ID, 8, 0x180);  //EPS_180
    CAN_Set_ID(CAN0, CHANNEL_7, Rx_Flag, STD_ID, 8, 0x219);  //EPB_219
    CAN_Set_ID(CAN0, CHANNEL_8, Rx_Flag, STD_ID, 8, 0x281);  //FCW_281
    CAN_Set_ID(CAN0, CHANNEL_9, Rx_Flag, STD_ID, 8, 0x285);  //FCW_285
    CAN_Set_ID(CAN0, CHANNEL_10, Rx_Flag, STD_ID, 8, 0x385);  //EHU_385
    CSCAN_RxReal_Num = 11;
}
void Init_CANRxMessage_A11(void)
{
//动力CAN
    //CAN_Set_ID (CAN3, CHANNEL_0, Rx_Flag, STD_ID, 8,  ID_Phy_UDS); // Core0 send using
    CAN_Set_ID(CAN3, CHANNEL_1, Rx_Flag, STD_ID, 8, ID_Fun_UDS); // UDS functional request 0x7DF/0x700
    CAN_Set_ID(CAN3, CHANNEL_2, Rx_Flag, STD_ID, 8, BCCP_CRO_ID); //CCP command 0x100
    CAN_Set_ID(CAN3, CHANNEL_3, Rx_Flag, STD_ID, 8, 0x113); //BMS_113
    CAN_Set_ID(CAN3, CHANNEL_4, Rx_Flag, STD_ID, 8, 0x213); //BMS_213
    CAN_Set_ID(CAN3, CHANNEL_5, Rx_Flag, STD_ID, 8, 0x233); //BMS_233
    CAN_Set_ID(CAN3, CHANNEL_6, Rx_Flag, STD_ID, 8, 0x305); //BMS_305
    CAN_Set_ID(CAN3, CHANNEL_7, Rx_Flag, STD_ID, 8, 0x306); //BMS_306
    CAN_Set_ID(CAN3, CHANNEL_8, Rx_Flag, STD_ID, 8, 0x313); //BMS_313
    CAN_Set_ID(CAN3, CHANNEL_9, Rx_Flag, STD_ID, 8, 0x323); //BMS_323
    CAN_Set_ID(CAN3, CHANNEL_10, Rx_Flag, STD_ID, 8, 0x377); //BMS_377
    CAN_Set_ID(CAN3, CHANNEL_11, Rx_Flag, STD_ID, 8, 0x513); //BMS_513
    CAN_Set_ID(CAN3, CHANNEL_12, Rx_Flag, STD_ID, 8, 0x603); //BMS_603
    CAN_Set_ID(CAN3, CHANNEL_13, Rx_Flag, STD_ID, 8, 0x613); //BMS_613
    CAN_Set_ID(CAN3, CHANNEL_14, Rx_Flag, STD_ID, 8, 0x623); //BMS_623
    CAN_Set_ID(CAN3, CHANNEL_15, Rx_Flag, STD_ID, 8, 0x633); //BMS_633
    CAN_Set_ID(CAN3, CHANNEL_16, Rx_Flag, STD_ID, 8, 0x653); //BMS_653
    CAN_Set_ID(CAN3, CHANNEL_17, Rx_Flag, STD_ID, 8, 0x115); //MCU_115
    CAN_Set_ID(CAN3, CHANNEL_18, Rx_Flag, STD_ID, 8, 0x125); //MCU_125
    CAN_Set_ID(CAN3, CHANNEL_19, Rx_Flag, STD_ID, 8, 0x215); //MCU_215
    CAN_Set_ID(CAN3, CHANNEL_20, Rx_Flag, STD_ID, 8, 0x515); //MCU_515
    CAN_Set_ID(CAN3, CHANNEL_21, Rx_Flag, STD_ID, 8, 0x231); //DCDC_231
    CAN_Set_ID(CAN3, CHANNEL_22, Rx_Flag, STD_ID, 8, 0x251); //DCDC_251
    CAN_Set_ID(CAN3, CHANNEL_23, Rx_Flag, STD_ID, 8, 0x311); //OBC_311
    CAN_Set_ID(CAN3, CHANNEL_24, Rx_Flag, STD_ID, 8, 0x321); //OBC_321
    CAN_Set_ID(CAN3, CHANNEL_25, Rx_Flag, STD_ID, 8, 0x331); //OBC_331
    CAN_Set_ID(CAN3, CHANNEL_26, Rx_Flag, STD_ID, 8, 0x5DA); //PTC_5DA
    CAN_Set_ID(CAN3, CHANNEL_27, Rx_Flag, STD_ID, 8, 0x5DB); //PTC_5DB
    CAN_Set_ID(CAN3, CHANNEL_28, Rx_Flag, STD_ID, 8, 0x33C); //ECC_33C
    CAN_Set_ID(CAN3, CHANNEL_29, Rx_Flag, STD_ID, 8, 0x312); //BCM_312
    CAN_Set_ID(CAN3, CHANNEL_30, Rx_Flag, STD_ID, 8, 0x35C); //ECC_35C
    CAN_Set_ID(CAN3, CHANNEL_31, Rx_Flag, STD_ID, 8, 0x108); //PEPS_108
    CAN_Set_ID(CAN3, CHANNEL_32, Rx_Flag, STD_ID, 8, 0x405); //GW_405h
    CAN_Set_ID(CAN3, CHANNEL_33, Rx_Flag, STD_ID, 8, 0x282); //PEPS_282
    CAN_Set_ID(CAN3, CHANNEL_34, Rx_Flag, STD_ID, 8, 0x050); //SRS_050
    CAN_Set_ID(CAN3, CHANNEL_35, Rx_Flag, STD_ID, 8, 0x522); //GW_522
    CAN_Set_ID(CAN3, CHANNEL_36, Rx_Flag, STD_ID, 8, 0x349); //EAC_349
    CAN_Set_ID(CAN3, CHANNEL_37, Rx_Flag, STD_ID, 8, 0x34A); //EAC_34A
    CAN_Set_ID(CAN3, CHANNEL_38, Rx_Flag, STD_ID, 8, 0x296); //TBOX_296
    CAN_Set_ID(CAN3, CHANNEL_39, Rx_Flag, STD_ID, 8, 0x298); //TBOX_298
    CAN_Set_ID(CAN3, CHANNEL_40, Rx_Flag, STD_ID, 8, 0x317); //TPMS_317
    CAN_Set_ID(CAN3, CHANNEL_41, Rx_Flag, STD_ID, 8, 0x3A2); //TPMS_3A2
    CAN_Set_ID(CAN3, CHANNEL_42, Rx_Flag, STD_ID, 8, 0x2C0); //ECC_2C0
    CAN_Set_ID(CAN3, CHANNEL_43, Rx_Flag, STD_ID, 8, 0x2C1); //ECC_2C1
    CAN_Set_ID(CAN3, CHANNEL_44, Rx_Flag, STD_ID, 8, 0x2C2); //ECC_2C2
    CAN_Set_ID(CAN3, CHANNEL_45, Rx_Flag, STD_ID, 8, 0x2C3); //ECC_2C3
    CAN_Set_ID(CAN3, CHANNEL_46, Rx_Flag, STD_ID, 8, 0x2F0); //WPTC_2F0
    CAN_Set_ID(CAN3, CHANNEL_47, Rx_Flag, STD_ID, 8, 0x103); //PEPS_103
    CAN_Set_ID(CAN3, CHANNEL_48, Rx_Flag, STD_ID, 8, 0x2F1); //WPTC_2F1
    PTCAN_RxReal_Num = 49;
//底盘CAN
    //CAN_Set_ID (CAN0, CHANNEL_0, Rx_Flag, STD_ID, 8,  ID_Phy_UDS);
    //CAN_Set_ID (CAN0, CHANNEL_1, Rx_Flag, STD_ID, 8,  ID_Fun_UDS);
    CAN_Set_ID(CAN0, CHANNEL_2, Rx_Flag, EXT_ID, 8, ID_VCUHW_UDS);
    CAN_Set_ID(CAN0, CHANNEL_3, Rx_Flag, STD_ID, 8, 0x229); //ABS_229
    CAN_Set_ID(CAN0, CHANNEL_4, Rx_Flag, STD_ID, 8, 0x232); //ABS_232
    CAN_Set_ID(CAN0, CHANNEL_5, Rx_Flag, STD_ID, 8, 0x2A0); //EPS_2A0
    CAN_Set_ID(CAN0, CHANNEL_6, Rx_Flag, STD_ID, 8, 0x180); //EPS_180
    CAN_Set_ID(CAN0, CHANNEL_7, Rx_Flag, STD_ID, 8, 0x219); //EPB_219
    CAN_Set_ID(CAN0, CHANNEL_8, Rx_Flag, STD_ID, 8, 0x241); //XBS_241
    CSCAN_RxReal_Num = 9;
}

void Init_CANRxMessage_S11P03(void)
{
//动力CAN
    //CAN_Set_ID (CAN3, CHANNEL_0, Rx_Flag, STD_ID, 8,  ID_Phy_UDS); // Core0 send using
    CAN_Set_ID(CAN3, CHANNEL_1, Rx_Flag, STD_ID, 8, ID_Fun_UDS); // UDS functional request 0x7DF/0x700
    CAN_Set_ID(CAN3, CHANNEL_2, Rx_Flag, STD_ID, 8, BCCP_CRO_ID); //CCP command 0x100
    CAN_Set_ID(CAN3, CHANNEL_3, Rx_Flag, STD_ID, 8, 0x113); //BMS_113
    CAN_Set_ID(CAN3, CHANNEL_4, Rx_Flag, STD_ID, 8, 0x213); //BMS_213
    CAN_Set_ID(CAN3, CHANNEL_5, Rx_Flag, STD_ID, 8, 0x233); //BMS_233
    CAN_Set_ID(CAN3, CHANNEL_6, Rx_Flag, STD_ID, 8, 0x303); //BMS_303----++
    CAN_Set_ID(CAN3, CHANNEL_7, Rx_Flag, STD_ID, 8, 0x304); //BMS_304----++
    CAN_Set_ID(CAN3, CHANNEL_8, Rx_Flag, STD_ID, 8, 0x313); //BMS_313
    CAN_Set_ID(CAN3, CHANNEL_9, Rx_Flag, STD_ID, 8, 0x323); //BMS_323
    CAN_Set_ID(CAN3, CHANNEL_10, Rx_Flag, STD_ID, 8, 0x377); //BMS_377
    CAN_Set_ID(CAN3, CHANNEL_11, Rx_Flag, STD_ID, 8, 0x513); //BMS_513
    CAN_Set_ID(CAN3, CHANNEL_12, Rx_Flag, STD_ID, 8, 0x603); //BMS_603
    CAN_Set_ID(CAN3, CHANNEL_13, Rx_Flag, STD_ID, 8, 0x613); //BMS_613
    CAN_Set_ID(CAN3, CHANNEL_14, Rx_Flag, STD_ID, 8, 0x623); //BMS_623
    CAN_Set_ID(CAN3, CHANNEL_15, Rx_Flag, STD_ID, 8, 0x633); //BMS_633
    CAN_Set_ID(CAN3, CHANNEL_16, Rx_Flag, STD_ID, 8, 0x653); //BMS_653
    CAN_Set_ID(CAN3, CHANNEL_17, Rx_Flag, STD_ID, 8, 0x115); //MCU_115
    CAN_Set_ID(CAN3, CHANNEL_18, Rx_Flag, STD_ID, 8, 0x125); //MCU_125
    CAN_Set_ID(CAN3, CHANNEL_19, Rx_Flag, STD_ID, 8, 0x215); //MCU_215
    CAN_Set_ID(CAN3, CHANNEL_20, Rx_Flag, STD_ID, 8, 0x515); //MCU_515
    CAN_Set_ID(CAN3, CHANNEL_21, Rx_Flag, STD_ID, 8, 0x231); //DCDC_231
    CAN_Set_ID(CAN3, CHANNEL_22, Rx_Flag, STD_ID, 8, 0x251); //DCDC_251
    CAN_Set_ID(CAN3, CHANNEL_23, Rx_Flag, STD_ID, 8, 0x311); //OBC_311
    CAN_Set_ID(CAN3, CHANNEL_24, Rx_Flag, STD_ID, 8, 0x321); //OBC_321
    CAN_Set_ID(CAN3, CHANNEL_25, Rx_Flag, STD_ID, 8, 0x331); //OBC_331
    CAN_Set_ID(CAN3, CHANNEL_26, Rx_Flag, STD_ID, 8, 0x5DA); //PTC_5DA
    CAN_Set_ID(CAN3, CHANNEL_27, Rx_Flag, STD_ID, 8, 0x5DB); //PTC_5DB
    CAN_Set_ID(CAN3, CHANNEL_28, Rx_Flag, STD_ID, 8, 0x33C); //ECC_33C
    CAN_Set_ID(CAN3, CHANNEL_29, Rx_Flag, STD_ID, 8, 0x34C); //ECC_34C
    CAN_Set_ID(CAN3, CHANNEL_30, Rx_Flag, STD_ID, 8, 0x35C); //ECC_35C
    CAN_Set_ID(CAN3, CHANNEL_31, Rx_Flag, STD_ID, 8, 0x108); //PEPS_108
    CAN_Set_ID(CAN3, CHANNEL_32, Rx_Flag, STD_ID, 8, 0x405); //GW_405h
    CAN_Set_ID(CAN3, CHANNEL_33, Rx_Flag, STD_ID, 8, 0x282); //PEPS_282
    CAN_Set_ID(CAN3, CHANNEL_34, Rx_Flag, STD_ID, 4, 0x50); //SRS_050
    CAN_Set_ID(CAN3, CHANNEL_35, Rx_Flag, STD_ID, 8, 0x522); //GW_522
    CAN_Set_ID(CAN3, CHANNEL_36, Rx_Flag, STD_ID, 8, 0x349); //EAC_349
    CAN_Set_ID(CAN3, CHANNEL_37, Rx_Flag, STD_ID, 8, 0x34A); //EAC_34A
    CAN_Set_ID(CAN3, CHANNEL_38, Rx_Flag, STD_ID, 8, 0x296); //TBOX_296
    CAN_Set_ID(CAN3, CHANNEL_39, Rx_Flag, STD_ID, 8, 0x298); //TBOX_298
    CAN_Set_ID(CAN3, CHANNEL_40, Rx_Flag, STD_ID, 8, 0x317); //TPMS_317
    CAN_Set_ID(CAN3, CHANNEL_41, Rx_Flag, STD_ID, 8, 0x3A2); //TPMS_3A2
    CAN_Set_ID(CAN3, CHANNEL_42, Rx_Flag, STD_ID, 8, 0x103); //PEPS_103---++
    CAN_Set_ID(CAN3, CHANNEL_43, Rx_Flag, STD_ID, 8, 0x312); //BCM_312---++
    CAN_Set_ID(CAN3, CHANNEL_44, Rx_Flag, STD_ID, 8, 0x235); //ICM_235---++
    CAN_Set_ID(CAN3, CHANNEL_45, Rx_Flag, STD_ID, 8, 0x36C); //ECC_36C---++
    PTCAN_RxReal_Num = 46;
//底盘CAN
    //CAN_Set_ID (CAN0, CHANNEL_0, Rx_Flag, STD_ID, 8,  ID_Phy_UDS);
    //CAN_Set_ID (CAN0, CHANNEL_1, Rx_Flag, STD_ID, 8,  ID_Fun_UDS);
    CAN_Set_ID(CAN0, CHANNEL_2, Rx_Flag, EXT_ID, 8, ID_VCUHW_UDS);
    CAN_Set_ID(CAN0, CHANNEL_3, Rx_Flag, STD_ID, 8, 0x229);  //ABS_229
    CAN_Set_ID(CAN0, CHANNEL_4, Rx_Flag, STD_ID, 8, 0x232);  //ABS_232
    CAN_Set_ID(CAN0, CHANNEL_5, Rx_Flag, STD_ID, 8, 0x2A0);  //EPS_2A0
    CAN_Set_ID(CAN0, CHANNEL_6, Rx_Flag, STD_ID, 8, 0x180);  //EPS_180
    CAN_Set_ID(CAN0, CHANNEL_7, Rx_Flag, STD_ID, 8, 0x219);  //EPB_219
    CAN_Set_ID(CAN0, CHANNEL_8, Rx_Flag, STD_ID, 8, 0x281);  //FCW_281
    CAN_Set_ID(CAN0, CHANNEL_9, Rx_Flag, STD_ID, 8, 0x285);  //FCW_285
    CAN_Set_ID(CAN0, CHANNEL_10, Rx_Flag, STD_ID, 8, 0x240);  //CBS_240
    CSCAN_RxReal_Num = 11;
}

void Init_CANRxMessage_S11P04(void)
{
//动力CAN
    //CAN_Set_ID (CAN3, CHANNEL_0, Rx_Flag, STD_ID, 8,  ID_Phy_UDS); // Core0 send using
    CAN_Set_ID(CAN3, CHANNEL_1, Rx_Flag, STD_ID, 8, ID_Fun_UDS); // UDS functional request 0x7DF/0x700
    CAN_Set_ID(CAN3, CHANNEL_2, Rx_Flag, STD_ID, 8, BCCP_CRO_ID); //CCP command 0x100
    CAN_Set_ID(CAN3, CHANNEL_3, Rx_Flag, STD_ID, 8, 0x113); //BMS_113
    CAN_Set_ID(CAN3, CHANNEL_4, Rx_Flag, STD_ID, 8, 0x213); //BMS_213
    CAN_Set_ID(CAN3, CHANNEL_5, Rx_Flag, STD_ID, 8, 0x233); //BMS_233
    CAN_Set_ID(CAN3, CHANNEL_6, Rx_Flag, STD_ID, 8, 0x305); //BMS_305----++
    CAN_Set_ID(CAN3, CHANNEL_7, Rx_Flag, STD_ID, 8, 0x306); //BMS_306----++
    CAN_Set_ID(CAN3, CHANNEL_8, Rx_Flag, STD_ID, 8, 0x313); //BMS_313
    CAN_Set_ID(CAN3, CHANNEL_9, Rx_Flag, STD_ID, 8, 0x323); //BMS_323
    CAN_Set_ID(CAN3, CHANNEL_10, Rx_Flag, STD_ID, 8, 0x377); //BMS_377
    CAN_Set_ID(CAN3, CHANNEL_11, Rx_Flag, STD_ID, 8, 0x513); //BMS_513
    CAN_Set_ID(CAN3, CHANNEL_12, Rx_Flag, STD_ID, 8, 0x603); //BMS_603
    CAN_Set_ID(CAN3, CHANNEL_13, Rx_Flag, STD_ID, 8, 0x613); //BMS_613
    CAN_Set_ID(CAN3, CHANNEL_14, Rx_Flag, STD_ID, 8, 0x623); //BMS_623
    CAN_Set_ID(CAN3, CHANNEL_15, Rx_Flag, STD_ID, 8, 0x633); //BMS_633
    CAN_Set_ID(CAN3, CHANNEL_16, Rx_Flag, STD_ID, 8, 0x653); //BMS_653
    CAN_Set_ID(CAN3, CHANNEL_17, Rx_Flag, STD_ID, 8, 0x115); //MCU_115
    CAN_Set_ID(CAN3, CHANNEL_18, Rx_Flag, STD_ID, 8, 0x125); //MCU_125
    CAN_Set_ID(CAN3, CHANNEL_19, Rx_Flag, STD_ID, 8, 0x215); //MCU_215
    CAN_Set_ID(CAN3, CHANNEL_20, Rx_Flag, STD_ID, 8, 0x515); //MCU_515
    CAN_Set_ID(CAN3, CHANNEL_21, Rx_Flag, STD_ID, 8, 0x231); //DCDC_231
    CAN_Set_ID(CAN3, CHANNEL_22, Rx_Flag, STD_ID, 8, 0x251); //DCDC_251
    CAN_Set_ID(CAN3, CHANNEL_23, Rx_Flag, STD_ID, 8, 0x311); //OBC_311
    CAN_Set_ID(CAN3, CHANNEL_24, Rx_Flag, STD_ID, 8, 0x321); //OBC_321
    CAN_Set_ID(CAN3, CHANNEL_25, Rx_Flag, STD_ID, 8, 0x331); //OBC_331
    CAN_Set_ID(CAN3, CHANNEL_26, Rx_Flag, STD_ID, 8, 0x5DA); //PTC_5DA
    CAN_Set_ID(CAN3, CHANNEL_27, Rx_Flag, STD_ID, 8, 0x5DB); //PTC_5DB
    CAN_Set_ID(CAN3, CHANNEL_28, Rx_Flag, STD_ID, 8, 0x33C); //ECC_33C
    CAN_Set_ID(CAN3, CHANNEL_29, Rx_Flag, STD_ID, 8, 0x34C); //ECC_34C
    CAN_Set_ID(CAN3, CHANNEL_30, Rx_Flag, STD_ID, 8, 0x35C); //ECC_35C
    CAN_Set_ID(CAN3, CHANNEL_31, Rx_Flag, STD_ID, 8, 0x108); //PEPS_108
    CAN_Set_ID(CAN3, CHANNEL_32, Rx_Flag, STD_ID, 8, 0x405); //GW_405h
    CAN_Set_ID(CAN3, CHANNEL_33, Rx_Flag, STD_ID, 8, 0x282); //PEPS_282
    CAN_Set_ID(CAN3, CHANNEL_34, Rx_Flag, STD_ID, 4, 0x50); //SRS_050
    CAN_Set_ID(CAN3, CHANNEL_35, Rx_Flag, STD_ID, 8, 0x522); //GW_522
    CAN_Set_ID(CAN3, CHANNEL_36, Rx_Flag, STD_ID, 8, 0x349); //EAC_349
    CAN_Set_ID(CAN3, CHANNEL_37, Rx_Flag, STD_ID, 8, 0x34A); //EAC_34A
    CAN_Set_ID(CAN3, CHANNEL_38, Rx_Flag, STD_ID, 8, 0x296); //TBOX_296
    CAN_Set_ID(CAN3, CHANNEL_39, Rx_Flag, STD_ID, 8, 0x298); //TBOX_298
    CAN_Set_ID(CAN3, CHANNEL_40, Rx_Flag, STD_ID, 8, 0x317); //TPMS_317
    CAN_Set_ID(CAN3, CHANNEL_41, Rx_Flag, STD_ID, 8, 0x3A2); //TPMS_3A2
    CAN_Set_ID(CAN3, CHANNEL_42, Rx_Flag, STD_ID, 8, 0x103); //PEPS_103---++
    CAN_Set_ID(CAN3, CHANNEL_43, Rx_Flag, STD_ID, 8, 0x312); //BCM_312---++
    CAN_Set_ID(CAN3, CHANNEL_44, Rx_Flag, STD_ID, 8, 0x235); //ICM_235---++
    CAN_Set_ID(CAN3, CHANNEL_45, Rx_Flag, STD_ID, 8, 0x36C); //ECC_36C---++
    PTCAN_RxReal_Num = 46;
//底盘CAN
    //CAN_Set_ID (CAN0, CHANNEL_0, Rx_Flag, STD_ID, 8,  ID_Phy_UDS);
    //CAN_Set_ID (CAN0, CHANNEL_1, Rx_Flag, STD_ID, 8,  ID_Fun_UDS);
    CAN_Set_ID(CAN0, CHANNEL_2, Rx_Flag, EXT_ID, 8, ID_VCUHW_UDS);
    CAN_Set_ID(CAN0, CHANNEL_3, Rx_Flag, STD_ID, 8, 0x229);  //ABS_229
    CAN_Set_ID(CAN0, CHANNEL_4, Rx_Flag, STD_ID, 8, 0x232);  //ABS_232
    CAN_Set_ID(CAN0, CHANNEL_5, Rx_Flag, STD_ID, 8, 0x2A0);  //EPS_2A0
    CAN_Set_ID(CAN0, CHANNEL_6, Rx_Flag, STD_ID, 8, 0x180);  //EPS_180
    CAN_Set_ID(CAN0, CHANNEL_7, Rx_Flag, STD_ID, 8, 0x219);  //EPB_219
    CAN_Set_ID(CAN0, CHANNEL_8, Rx_Flag, STD_ID, 8, 0x281);  //FCW_281
    CAN_Set_ID(CAN0, CHANNEL_9, Rx_Flag, STD_ID, 8, 0x285);  //FCW_285
    CSCAN_RxReal_Num = 10;
}

void Init_CANRxMessage_S21(void)
{
//动力CAN
    //CAN_Set_ID (CAN3, CHANNEL_0, Rx_Flag, STD_ID, 8,  ID_Phy_UDS); // Core0 send using
    CAN_Set_ID(CAN3, CHANNEL_1, Rx_Flag, STD_ID, 8, ID_Fun_UDS); // UDS functional request 0x7DF/0x700
    CAN_Set_ID(CAN3, CHANNEL_2, Rx_Flag, STD_ID, 8, BCCP_CRO_ID); //CCP command 0x100
    CAN_Set_ID(CAN3, CHANNEL_3, Rx_Flag, STD_ID, 8, 0x113); //BMS_113
    CAN_Set_ID(CAN3, CHANNEL_4, Rx_Flag, STD_ID, 8, 0x213); //BMS_213
    CAN_Set_ID(CAN3, CHANNEL_5, Rx_Flag, STD_ID, 8, 0x233); //BMS_233
    CAN_Set_ID(CAN3, CHANNEL_6, Rx_Flag, STD_ID, 8, 0x305); //BMS_305
    CAN_Set_ID(CAN3, CHANNEL_7, Rx_Flag, STD_ID, 8, 0x306); //BMS_306
    CAN_Set_ID(CAN3, CHANNEL_8, Rx_Flag, STD_ID, 8, 0x313); //BMS_313
    CAN_Set_ID(CAN3, CHANNEL_9, Rx_Flag, STD_ID, 8, 0x323); //BMS_323
    CAN_Set_ID(CAN3, CHANNEL_10, Rx_Flag, STD_ID, 8, 0x377); //BMS_377
    CAN_Set_ID(CAN3, CHANNEL_11, Rx_Flag, STD_ID, 8, 0x513); //BMS_513
    CAN_Set_ID(CAN3, CHANNEL_12, Rx_Flag, STD_ID, 8, 0x603); //BMS_603
    CAN_Set_ID(CAN3, CHANNEL_13, Rx_Flag, STD_ID, 8, 0x613); //BMS_613
    CAN_Set_ID(CAN3, CHANNEL_14, Rx_Flag, STD_ID, 8, 0x623); //BMS_623
    CAN_Set_ID(CAN3, CHANNEL_15, Rx_Flag, STD_ID, 8, 0x633); //BMS_633
    CAN_Set_ID(CAN3, CHANNEL_16, Rx_Flag, STD_ID, 8, 0x653); //BMS_653
    CAN_Set_ID(CAN3, CHANNEL_17, Rx_Flag, STD_ID, 8, 0x115); //MCU_115
    CAN_Set_ID(CAN3, CHANNEL_18, Rx_Flag, STD_ID, 8, 0x125); //MCU_125
    CAN_Set_ID(CAN3, CHANNEL_19, Rx_Flag, STD_ID, 8, 0x215); //MCU_215
    CAN_Set_ID(CAN3, CHANNEL_20, Rx_Flag, STD_ID, 8, 0x515); //MCU_515
    CAN_Set_ID(CAN3, CHANNEL_21, Rx_Flag, STD_ID, 8, 0x231); //DCDC_231
    CAN_Set_ID(CAN3, CHANNEL_22, Rx_Flag, STD_ID, 8, 0x251); //DCDC_251
    CAN_Set_ID(CAN3, CHANNEL_23, Rx_Flag, STD_ID, 8, 0x311); //OBC_311
    CAN_Set_ID(CAN3, CHANNEL_24, Rx_Flag, STD_ID, 8, 0x321); //OBC_321
    CAN_Set_ID(CAN3, CHANNEL_25, Rx_Flag, STD_ID, 8, 0x331); //OBC_331
    CAN_Set_ID(CAN3, CHANNEL_26, Rx_Flag, STD_ID, 8, 0x5DA); //PTC_5DA
    CAN_Set_ID(CAN3, CHANNEL_27, Rx_Flag, STD_ID, 8, 0x5DB); //PTC_5DB
    CAN_Set_ID(CAN3, CHANNEL_28, Rx_Flag, STD_ID, 8, 0x33C); //ECC_33C
    CAN_Set_ID(CAN3, CHANNEL_29, Rx_Flag, STD_ID, 8, 0x34C); //ECC_34C
    CAN_Set_ID(CAN3, CHANNEL_30, Rx_Flag, STD_ID, 8, 0x35C); //ECC_35C
    CAN_Set_ID(CAN3, CHANNEL_31, Rx_Flag, STD_ID, 8, 0x108); //PEPS_108
    CAN_Set_ID(CAN3, CHANNEL_32, Rx_Flag, STD_ID, 8, 0x405); //GW_405h
    CAN_Set_ID(CAN3, CHANNEL_33, Rx_Flag, STD_ID, 8, 0x282); //PEPS_282
    CAN_Set_ID(CAN3, CHANNEL_34, Rx_Flag, STD_ID, 4, 0x50); //SRS_050
    CAN_Set_ID(CAN3, CHANNEL_35, Rx_Flag, STD_ID, 8, 0x522); //GW_522
    CAN_Set_ID(CAN3, CHANNEL_36, Rx_Flag, STD_ID, 8, 0x349); //EAC_349
    CAN_Set_ID(CAN3, CHANNEL_37, Rx_Flag, STD_ID, 8, 0x34A); //EAC_34A
    CAN_Set_ID(CAN3, CHANNEL_38, Rx_Flag, STD_ID, 8, 0x296); //TBOX_296
    CAN_Set_ID(CAN3, CHANNEL_39, Rx_Flag, STD_ID, 8, 0x298); //TBOX_298
    CAN_Set_ID(CAN3, CHANNEL_40, Rx_Flag, STD_ID, 8, 0x317); //TPMS_317
    CAN_Set_ID(CAN3, CHANNEL_41, Rx_Flag, STD_ID, 8, 0x3A2); //TPMS_3A2
    CAN_Set_ID(CAN3, CHANNEL_42, Rx_Flag, STD_ID, 8, 0x2C0); //TMS_2C0
    CAN_Set_ID(CAN3, CHANNEL_43, Rx_Flag, STD_ID, 8, 0x2C1); //TMS_2C1
    CAN_Set_ID(CAN3, CHANNEL_44, Rx_Flag, STD_ID, 8, 0x2C2); //TMS_2C2
    CAN_Set_ID(CAN3, CHANNEL_45, Rx_Flag, STD_ID, 8, 0x2C3); //TMS_2C3
    CAN_Set_ID(CAN3, CHANNEL_46, Rx_Flag, STD_ID, 8, 0x2F0); //WPTC_2F0
    CAN_Set_ID(CAN3, CHANNEL_47, Rx_Flag, STD_ID, 8, 0x103); //PEPS_103
    CAN_Set_ID(CAN3, CHANNEL_48, Rx_Flag, STD_ID, 8, 0x312); //BCM_312
    CAN_Set_ID(CAN3, CHANNEL_49, Rx_Flag, STD_ID, 8, 0x235); //ICM_235
    PTCAN_RxReal_Num = 50;
//底盘CAN
    //CAN_Set_ID (CAN0, CHANNEL_0, Rx_Flag, STD_ID, 8,  ID_Phy_UDS);
    //CAN_Set_ID (CAN0, CHANNEL_1, Rx_Flag, STD_ID, 8,  ID_Fun_UDS);
    CAN_Set_ID(CAN0, CHANNEL_2, Rx_Flag, EXT_ID, 8, ID_VCUHW_UDS);
    CAN_Set_ID(CAN0, CHANNEL_3, Rx_Flag, STD_ID, 8, 0x229);  //ABS_229
    CAN_Set_ID(CAN0, CHANNEL_4, Rx_Flag, STD_ID, 8, 0x232);  //ABS_232
    CAN_Set_ID(CAN0, CHANNEL_5, Rx_Flag, STD_ID, 8, 0x2A0);  //EPS_2A0
    CAN_Set_ID(CAN0, CHANNEL_6, Rx_Flag, STD_ID, 8, 0x180);  //EPS_180
    CAN_Set_ID(CAN0, CHANNEL_7, Rx_Flag, STD_ID, 8, 0x219);  //EPB_219
    CAN_Set_ID(CAN0, CHANNEL_8, Rx_Flag, STD_ID, 8, 0x281);  //FCW_281
    CAN_Set_ID(CAN0, CHANNEL_9, Rx_Flag, STD_ID, 8, 0x285);  //FCW_285
    CSCAN_RxReal_Num = 10;

//Body CAN
    CAN_Set_ID(CAN1, CHANNEL_5, Rx_Flag, STD_ID, 8, 0x312);   //BCM312 body CAN
}

/*
 * CAN 数据帧接收初始化
 * */
void Init_CANRxMessage(void)
{
    //clear
    memset(&CAN2_RX_Array, 0, CAN2_RX_NUM * (sizeof(_CAN_MESSAGE_)));
    memset(&CAN1_RX_Array, 0, CAN1_RX_NUM * (sizeof(_CAN_MESSAGE_)));
    memset(&CAN3_RX_Array, 0, CAN3_RX_NUM * (sizeof(_CAN_MESSAGE_)));
    memset(&CAN0_RX_Array, 0, CAN0_RX_NUM * (sizeof(_CAN_MESSAGE_)));

    //CAN2 -- CAN2 -- 4
    //CAN_Set_ID (CAN2, CHANNEL_0, Rx_Flag, STD_ID, 8,  ID_Phy_UDS);
    CAN_Set_ID(CAN2, CHANNEL_1, Rx_Flag, STD_ID, 8, ID_Fun_UDS);
    //CAN_Set_ID (CAN2, CHANNEL_2, Rx_Flag, STD_ID, 8,  BOOT_Phy_UDS);
    CAN_Set_ID(CAN2, CHANNEL_3, Rx_Flag, STD_ID, 8, BCCP_CRO_ID);

    //CAN1 -- CAN1 -- 5
    //CAN_Set_ID (CAN1, CHANNEL_0, Rx_Flag, STD_ID, 8,  ID_Phy_UDS);
    CAN_Set_ID(CAN1, CHANNEL_1, Rx_Flag, STD_ID, 8, ID_Fun_UDS);
    CAN_Set_ID(CAN1, CHANNEL_2, Rx_Flag, EXT_ID, 8, ID_VCUHW_UDS);  //拓展帧用于开启硬件测试功能
    CAN_Set_ID(CAN1, CHANNEL_3, Rx_Flag, STD_ID, 8, BCCP_CRO_ID);
    //CAN_Set_ID (CAN1, CHANNEL_4, Rx_Flag, STD_ID, 8,  BOOT_Phy_UDS);

    //CAN3 -- CAN3 -- 51  //PTCAN--CAN3 仅接收标准帧，不接收拓展帧
    //CAN0 -- CAN0 -- 4
    if( S11P01_Mark == Vehicle_Type )
    {
        Init_CANRxMessage_S11P01();
    }
    else if( A11_Mark == Vehicle_Type )
    {
        Init_CANRxMessage_A11();
    }
    else if( S11P03_Mark == Vehicle_Type )
    {
        Init_CANRxMessage_S11P03();
    }
    else if( S11P04_Mark == Vehicle_Type )
    {
        Init_CANRxMessage_S11P04();
    }
    else if( S21_Mark == Vehicle_Type )
    {
        Init_CANRxMessage_S21();
    }
    else if( K11P01_Mark == Vehicle_Type )
    {
        Init_CANRxMessage_K11P01();
    }
    else if( K11_Mark == Vehicle_Type )
    {
        Init_CANRxMessage_K11();
    }
    else if( S11P05_Mark == Vehicle_Type )
    {
        Init_CANRxMessage_S11P05();
    }
    else	//默认为S11
    {
        Init_CANRxMessage_S11();
    }
}

void Init_CANTxMessage_K11P01(void)
{
    CAN_Set_Message(CAN3, CHANNEL_0, Tx_Flag, STD_ID, 0x000, 8, 0, 100, DontSending);	//	    no use
    CAN_Set_Message(CAN3, CHANNEL_1, Tx_Flag, STD_ID, 0x10A, 8, 0, 100, ReadyToSend);	//VCU_10A
    CAN_Set_Message(CAN3, CHANNEL_2, Tx_Flag, STD_ID, 0x110, 8, 0, 10, ReadyToSend);	//VCU_110
    CAN_Set_Message(CAN3, CHANNEL_3, Tx_Flag, STD_ID, 0x120, 8, 0, 10, ReadyToSend);	//VCU_120
    CAN_Set_Message(CAN3, CHANNEL_4, Tx_Flag, STD_ID, 0x210, 8, 0, 100, ReadyToSend);	//VCU_210
    CAN_Set_Message(CAN3, CHANNEL_5, Tx_Flag, STD_ID, 0x230, 8, 0, 100, ReadyToSend);	//VCU_230
    CAN_Set_Message(CAN3, CHANNEL_6, Tx_Flag, STD_ID, 0x307, 8, 0, 100, ReadyToSend);	//VCU_307
    CAN_Set_Message(CAN3, CHANNEL_7, Tx_Flag, STD_ID, 0x510, 8, 0, 100, ReadyToSend);	//VCU_510
    CAN_Set_Message(CAN3, CHANNEL_8, Tx_Flag, STD_ID, 0x511, 8, 0, 100, ReadyToSend);	//VCU_511
    CAN_Set_Message(CAN3, CHANNEL_9, Tx_Flag, STD_ID, 0x520, 8, 0, 100, ReadyToSend);	//VCU_520
    CAN_Set_Message(CAN3, CHANNEL_10, Tx_Flag, STD_ID, 0x105, 8, 0, 100, DontSending);	//VCU_105
    CAN_Set_Message(CAN3, CHANNEL_11, Tx_Flag, STD_ID, 0x525, 8, 0, 100, ReadyToSend);	//VCU_525
    CAN_Set_Message(CAN3, CHANNEL_12, Tx_Flag, STD_ID, 0x106, 8, 0, 10, ReadyToSend);	//VCU_106
    CAN_Set_Message(CAN3, CHANNEL_13, Tx_Flag, STD_ID, 0x406, 8, 0, 100, DontSending);	//VCU_406  //NM message
    CAN_Set_Message(CAN3, CHANNEL_14, Tx_Flag, STD_ID, 0x530, 8, 0, 100, ReadyToSend);	//VCU_530
    CAN_Set_Message(CAN3, CHANNEL_15, Tx_Flag, STD_ID, 0x695, 8, 0, 1000, ReadyToSend);	//VCU_695
    CAN_Set_Message(CAN3, CHANNEL_16, Tx_Flag, EXT_ID, 0x168A0111, 8, 0, 100, ReadyToSend);	//VCU_A0111 test frame
    CAN_Set_Message(CAN3, CHANNEL_17, Tx_Flag, EXT_ID, 0x168A0222, 8, 0, 100, ReadyToSend);	//VCU_A0222 test frame
    CAN_Set_Message(CAN3, CHANNEL_18, Tx_Flag, EXT_ID, 0x168A0333, 8, 0, 100, ReadyToSend);	//VCU_A0333 test frame
    CAN_Set_Message(CAN3, CHANNEL_19, Tx_Flag, EXT_ID, 0x168A0444, 8, 0, 100, ReadyToSend);	//VCU_A0444 test frame
    CAN_Set_Message(CAN3, CHANNEL_20, Tx_Flag, EXT_ID, 0x168A0555, 8, 0, 100, ReadyToSend);	//VCU_A0555 test frame
    CAN_Set_Message(CAN3, CHANNEL_21, Tx_Flag, EXT_ID, 0x168A0666, 8, 0, 500, ReadyToSend);	//VCU_A0666 test frame
    CAN_Set_Message(CAN3, CHANNEL_22, Tx_Flag, EXT_ID, 0x168A0777, 8, 0, 500, ReadyToSend);	//VCU_A0777 test frame
    CAN_Set_Message(CAN3, CHANNEL_23, Tx_Flag, STD_ID, 0x2C1, 8, 0, 100, DontSending);	//
    CAN_Set_Message(CAN3, CHANNEL_24, Tx_Flag, STD_ID, 0x2C2, 8, 0, 100, DontSending);	//
    CAN_Set_Message(CAN3, CHANNEL_25, Tx_Flag, STD_ID, 0x2C3, 8, 0, 100, DontSending);	//
    CAN_Set_Message(CAN3, CHANNEL_26, Tx_Flag, STD_ID, 0x240, 8, 0, 100, ReadyToSend);	//VCU_240;周期报文
    CAN_Set_Message(CAN3, CHANNEL_27, Tx_Flag, STD_ID, 0x250, 8, 0, 100, ReadyToSend);	//VCU_250;周期报文
    CAN_Set_Message(CAN3, CHANNEL_28, Tx_Flag, STD_ID, 0x260, 8, 0, 100, ReadyToSend);	//VCU_260;周期报文
    CAN_Set_Message(CAN3, CHANNEL_29, Tx_Flag, STD_ID, 0x524, 8, 0, 500, ReadyToSend);	//VCU_524;周期报文
    CAN_Set_Message(CAN3, CHANNEL_30, Tx_Flag, STD_ID, 0x526, 8, 0, 500, ReadyToSend);	//VCU_526;周期报文
    CAN_Set_Message(CAN3, CHANNEL_31, Tx_Flag, STD_ID, 0x528, 8, 0, 500, ReadyToSend);	//VCU_528;周期报文
    CAN_Set_Message(CAN3, CHANNEL_32, Tx_Flag, STD_ID, 0x532, 8, 0, 500, ReadyToSend);	//VCU_532;周期报文
    CAN_Set_Message(CAN3, CHANNEL_33, Tx_Flag, STD_ID, 0x534, 8, 0, 500, ReadyToSend);	//VCU_534;周期报文

    //CAN0 -- CAN0 -- 1
    CAN_Set_Message(CAN0, CHANNEL_0, Tx_Flag, STD_ID, 0x520, 8, 0, 100, DontSending);	//VCU_520 该通道仅用于硬件测试
}

void Init_CANTxMessage_S11(void)
{
    CAN_Set_Message(CAN3, CHANNEL_0, Tx_Flag, STD_ID, 0x000, 8, 0, 100, DontSending);	//	    no use
    //CAN_Set_Message(CAN3, CHANNEL_1, Tx_Flag, STD_ID, 0x10A, 8, 0, 100, ReadyToSend);	//VCU_10A
    CAN_Set_Message(CAN3, CHANNEL_1, Tx_Flag, STD_ID, 0x301, 8, 0, 100, ReadyToSend);
	CAN_Set_Message(CAN3, CHANNEL_2, Tx_Flag, STD_ID, 0x201, 8, 0, 100, ReadyToSend);	
    //CAN_Set_Message(CAN3, CHANNEL_2, Tx_Flag, STD_ID, 0x110, 8, 0, 10, ReadyToSend);	//VCU_110
    CAN_Set_Message(CAN3, CHANNEL_3, Tx_Flag, STD_ID, 0x120, 8, 0, 10, ReadyToSend);	//VCU_120
    CAN_Set_Message(CAN3, CHANNEL_4, Tx_Flag, STD_ID, 0x210, 8, 0, 100, ReadyToSend);	//VCU_210
    CAN_Set_Message(CAN3, CHANNEL_5, Tx_Flag, STD_ID, 0x230, 8, 0, 100, ReadyToSend);	//VCU_230
    CAN_Set_Message(CAN3, CHANNEL_6, Tx_Flag, STD_ID, 0x307, 8, 0, 100, ReadyToSend);	//VCU_307
    CAN_Set_Message(CAN3, CHANNEL_7, Tx_Flag, STD_ID, 0x510, 8, 0, 100, ReadyToSend);	//VCU_510
    CAN_Set_Message(CAN3, CHANNEL_8, Tx_Flag, STD_ID, 0x511, 8, 0, 100, ReadyToSend);	//VCU_511
    CAN_Set_Message(CAN3, CHANNEL_9, Tx_Flag, STD_ID, 0x520, 8, 0, 100, ReadyToSend);	//VCU_520
    CAN_Set_Message(CAN3, CHANNEL_10, Tx_Flag, STD_ID, 0x105, 8, 0, 100, DontSending);	//VCU_105
    CAN_Set_Message(CAN3, CHANNEL_11, Tx_Flag, STD_ID, 0x525, 8, 0, 100, ReadyToSend);	//VCU_525
    CAN_Set_Message(CAN3, CHANNEL_12, Tx_Flag, STD_ID, 0x220, 8, 0, 100, DontSending);	//VCU_220 no send
    CAN_Set_Message(CAN3, CHANNEL_13, Tx_Flag, STD_ID, 0x406, 8, 0, 100, DontSending);	//VCU_406  //NM message
    CAN_Set_Message(CAN3, CHANNEL_14, Tx_Flag, STD_ID, 0x530, 8, 0, 100, ReadyToSend);	//VCU_530
    CAN_Set_Message(CAN3, CHANNEL_15, Tx_Flag, STD_ID, 0x695, 8, 0, 1000, ReadyToSend);	//VCU_695
    CAN_Set_Message(CAN3, CHANNEL_16, Tx_Flag, EXT_ID, 0x168A0111, 8, 0, 100, ReadyToSend);	//VCU_FA0111 test frame
    CAN_Set_Message(CAN3, CHANNEL_17, Tx_Flag, EXT_ID, 0x168A0222, 8, 0, 100, ReadyToSend);	//VCU_FA0222 test frame
    CAN_Set_Message(CAN3, CHANNEL_18, Tx_Flag, EXT_ID, 0x168A0333, 8, 0, 100, ReadyToSend);	//VCU_FA0333 test frame
    CAN_Set_Message(CAN3, CHANNEL_19, Tx_Flag, EXT_ID, 0x168A0444, 8, 0, 100, ReadyToSend);	//VCU_FA0444 test frame
    CAN_Set_Message(CAN3, CHANNEL_20, Tx_Flag, EXT_ID, 0x168A0555, 8, 0, 100, ReadyToSend);	//VCU_FA0555 test frame
    CAN_Set_Message(CAN3, CHANNEL_21, Tx_Flag, EXT_ID, 0x168A0666, 8, 0, 100, DontSending);	//VCU_FA0666 test frame
    CAN_Set_Message(CAN3, CHANNEL_22, Tx_Flag, EXT_ID, 0x168A0777, 8, 0, 100, DontSending);	//VCU_FA0777 test frame
    CAN_Set_Message(CAN3, CHANNEL_23, Tx_Flag, STD_ID, 0x2C1, 8, 0, 100, DontSending);	//
    CAN_Set_Message(CAN3, CHANNEL_24, Tx_Flag, STD_ID, 0x2C2, 8, 0, 100, DontSending);	//
    CAN_Set_Message(CAN3, CHANNEL_25, Tx_Flag, STD_ID, 0x2C3, 8, 0, 100, DontSending);	//
    CAN_Set_Message(CAN3, CHANNEL_26, Tx_Flag, STD_ID, 0x240, 8, 0, 100, ReadyToSend);	//VCU_240;周期报文
    CAN_Set_Message(CAN3, CHANNEL_27, Tx_Flag, STD_ID, 0x250, 8, 0, 100, ReadyToSend);	//VCU_250;周期报文
    CAN_Set_Message(CAN3, CHANNEL_28, Tx_Flag, STD_ID, 0x260, 8, 0, 100, ReadyToSend);	//VCU_260;周期报文

    CAN_Set_Message(CAN3, CHANNEL_29, Tx_Flag, STD_ID, 0x524, 8, 0, 500, ReadyToSend);    //VCU_524;周期报文
    CAN_Set_Message(CAN3, CHANNEL_30, Tx_Flag, STD_ID, 0x526, 8, 0, 500, ReadyToSend);  //VCU_526;周期报文
    CAN_Set_Message(CAN3, CHANNEL_31, Tx_Flag, STD_ID, 0x528, 8, 0, 500, ReadyToSend);  //VCU_528;周期报文
    CAN_Set_Message(CAN3, CHANNEL_32, Tx_Flag, STD_ID, 0x532, 8, 0, 500, ReadyToSend);  //VCU_532;周期报文
    CAN_Set_Message(CAN3, CHANNEL_33, Tx_Flag, STD_ID, 0x534, 8, 0, 500, ReadyToSend);  //VCU_534;周期报文


    //CAN0 -- CAN0 -- 1
    CAN_Set_Message(CAN0, CHANNEL_0, Tx_Flag, STD_ID, 0x520, 8, 0, 100, DontSending);	//VCU_520 该通道仅用于硬件测试
}

void Init_CANTxMessage_S11P01(void)
{
    CAN_Set_Message(CAN3, CHANNEL_0, Tx_Flag, STD_ID, 0x000, 8, 0, 100, DontSending);	//	    no use
    CAN_Set_Message(CAN3, CHANNEL_1, Tx_Flag, STD_ID, 0x10A, 8, 0, 100, ReadyToSend);	//VCU_10A
    CAN_Set_Message(CAN3, CHANNEL_2, Tx_Flag, STD_ID, 0x110, 8, 0, 10, ReadyToSend);	//VCU_110
    CAN_Set_Message(CAN3, CHANNEL_3, Tx_Flag, STD_ID, 0x120, 8, 0, 10, ReadyToSend);	//VCU_120
    CAN_Set_Message(CAN3, CHANNEL_4, Tx_Flag, STD_ID, 0x210, 8, 0, 100, ReadyToSend);	//VCU_210
    CAN_Set_Message(CAN3, CHANNEL_5, Tx_Flag, STD_ID, 0x230, 8, 0, 100, ReadyToSend);	//VCU_230
    CAN_Set_Message(CAN3, CHANNEL_6, Tx_Flag, STD_ID, 0x307, 8, 0, 100, ReadyToSend);	//VCU_307
    CAN_Set_Message(CAN3, CHANNEL_7, Tx_Flag, STD_ID, 0x510, 8, 0, 100, ReadyToSend);	//VCU_510
    CAN_Set_Message(CAN3, CHANNEL_8, Tx_Flag, STD_ID, 0x511, 8, 0, 100, ReadyToSend);	//VCU_511
    CAN_Set_Message(CAN3, CHANNEL_9, Tx_Flag, STD_ID, 0x520, 8, 0, 100, ReadyToSend);	//VCU_520
    CAN_Set_Message(CAN3, CHANNEL_10, Tx_Flag, STD_ID, 0x105, 8, 0, 100, DontSending);	//VCU_105
    CAN_Set_Message(CAN3, CHANNEL_11, Tx_Flag, STD_ID, 0x525, 8, 0, 100, ReadyToSend);	//VCU_525
    CAN_Set_Message(CAN3, CHANNEL_12, Tx_Flag, STD_ID, 0x220, 8, 0, 100, DontSending);	//VCU_220 no send
    CAN_Set_Message(CAN3, CHANNEL_13, Tx_Flag, STD_ID, 0x406, 8, 0, 100, DontSending);	//VCU_406  //NM message
    CAN_Set_Message(CAN3, CHANNEL_14, Tx_Flag, STD_ID, 0x530, 8, 0, 100, ReadyToSend);	//VCU_530
    CAN_Set_Message(CAN3, CHANNEL_15, Tx_Flag, STD_ID, 0x695, 8, 0, 1000, ReadyToSend);	//VCU_695
    CAN_Set_Message(CAN3, CHANNEL_16, Tx_Flag, EXT_ID, 0x168A0111, 8, 0, 100, ReadyToSend);	//VCU_FA0111 test frame
    CAN_Set_Message(CAN3, CHANNEL_17, Tx_Flag, EXT_ID, 0x168A0222, 8, 0, 100, ReadyToSend);	//VCU_FA0222 test frame
    CAN_Set_Message(CAN3, CHANNEL_18, Tx_Flag, EXT_ID, 0x168A0333, 8, 0, 100, ReadyToSend);	//VCU_FA0333 test frame
    CAN_Set_Message(CAN3, CHANNEL_19, Tx_Flag, EXT_ID, 0x168A0444, 8, 0, 100, ReadyToSend);	//VCU_FA0444 test frame
    CAN_Set_Message(CAN3, CHANNEL_20, Tx_Flag, EXT_ID, 0x168A0555, 8, 0, 100, ReadyToSend);	//VCU_FA0555 test frame
    CAN_Set_Message(CAN3, CHANNEL_21, Tx_Flag, EXT_ID, 0x168A0666, 8, 0, 100, ReadyToSend);	//VCU_FA0666 test frame
    CAN_Set_Message(CAN3, CHANNEL_22, Tx_Flag, EXT_ID, 0x168A0777, 8, 0, 100, ReadyToSend);	//VCU_FA0777 test frame
//    if( Config_output.C_ECC_Internal == 1 )
//    {
//        CAN_Set_Message(CAN3, CHANNEL_23, Tx_Flag, STD_ID, 0x2C1, 8, 0, 100, ReadyToSend);	//
//        CAN_Set_Message(CAN3, CHANNEL_24, Tx_Flag, STD_ID, 0x2C2, 8, 0, 100, ReadyToSend);	//
//        CAN_Set_Message(CAN3, CHANNEL_25, Tx_Flag, STD_ID, 0x2C3, 8, 0, 100, ReadyToSend);	//
//    }
    CAN_Set_Message(CAN3, CHANNEL_26, Tx_Flag, STD_ID, 0x240, 8, 0, 100, ReadyToSend);	//VCU_240;周期报文
    CAN_Set_Message(CAN3, CHANNEL_27, Tx_Flag, STD_ID, 0x250, 8, 0, 100, ReadyToSend);	//VCU_250;周期报文
    CAN_Set_Message(CAN3, CHANNEL_28, Tx_Flag, STD_ID, 0x260, 8, 0, 100, ReadyToSend);	//VCU_260;周期报文

    CAN_Set_Message(CAN3, CHANNEL_29, Tx_Flag, STD_ID, 0x524, 8, 0, 500, ReadyToSend);	//VCU_524;周期报文
    CAN_Set_Message(CAN3, CHANNEL_30, Tx_Flag, STD_ID, 0x526, 8, 0, 500, ReadyToSend);	//VCU_526;周期报文
    CAN_Set_Message(CAN3, CHANNEL_31, Tx_Flag, STD_ID, 0x528, 8, 0, 500, ReadyToSend);	//VCU_528;周期报文
    CAN_Set_Message(CAN3, CHANNEL_32, Tx_Flag, STD_ID, 0x532, 8, 0, 500, ReadyToSend);	//VCU_532;周期报文
    CAN_Set_Message(CAN3, CHANNEL_33, Tx_Flag, STD_ID, 0x534, 8, 0, 500, ReadyToSend);	//VCU_534;周期报文

//    if( Config_output.C_ECC_Internal == 1 )
//    {
//        CAN_Set_Message(CAN3, CHANNEL_34, Tx_Flag, STD_ID, 0x2C4, 8, 0, 100, ReadyToSend);
//    }

    //CAN0 -- CAN0 -- 1
    CAN_Set_Message(CAN0, CHANNEL_0, Tx_Flag, STD_ID, 0x520, 8, 0, 100, DontSending);	//VCU_520 该通道仅用于硬件测试
}

void Init_CANTxMessage_A11(void)
{
    CAN_Set_Message(CAN3, CHANNEL_0, Tx_Flag, STD_ID, 0x000, 8, 0, 100, DontSending);	//	    no use
    CAN_Set_Message(CAN3, CHANNEL_1, Tx_Flag, STD_ID, 0x10A, 8, 0, 100, ReadyToSend);	//VCU_10A
    CAN_Set_Message(CAN3, CHANNEL_2, Tx_Flag, STD_ID, 0x110, 8, 0, 10, ReadyToSend);	//VCU_110
    CAN_Set_Message(CAN3, CHANNEL_3, Tx_Flag, STD_ID, 0x120, 8, 0, 10, ReadyToSend);	//VCU_120
    CAN_Set_Message(CAN3, CHANNEL_4, Tx_Flag, STD_ID, 0x210, 8, 0, 100, ReadyToSend);	//VCU_210
    CAN_Set_Message(CAN3, CHANNEL_5, Tx_Flag, STD_ID, 0x230, 8, 0, 100, ReadyToSend);	//VCU_230
    CAN_Set_Message(CAN3, CHANNEL_6, Tx_Flag, STD_ID, 0x307, 8, 0, 100, ReadyToSend);	//VCU_307
    CAN_Set_Message(CAN3, CHANNEL_7, Tx_Flag, STD_ID, 0x510, 8, 0, 100, ReadyToSend);	//VCU_510
    CAN_Set_Message(CAN3, CHANNEL_8, Tx_Flag, STD_ID, 0x511, 8, 0, 100, ReadyToSend);	//VCU_511
    CAN_Set_Message(CAN3, CHANNEL_9, Tx_Flag, STD_ID, 0x520, 8, 0, 100, ReadyToSend);	//VCU_520
    CAN_Set_Message(CAN3, CHANNEL_10, Tx_Flag, STD_ID, 0x105, 8, 0, 100, DontSending);	//VCU_105
    CAN_Set_Message(CAN3, CHANNEL_11, Tx_Flag, STD_ID, 0x525, 8, 0, 100, ReadyToSend);	//VCU_525
    CAN_Set_Message(CAN3, CHANNEL_12, Tx_Flag, STD_ID, 0x106, 8, 0, 10, ReadyToSend);	//VCU_106 //
    CAN_Set_Message(CAN3, CHANNEL_13, Tx_Flag, STD_ID, 0x406, 8, 0, 100, DontSending);	//VCU_406  //NM message
    CAN_Set_Message(CAN3, CHANNEL_14, Tx_Flag, STD_ID, 0x530, 8, 0, 100, ReadyToSend);	//VCU_530
    CAN_Set_Message(CAN3, CHANNEL_15, Tx_Flag, STD_ID, 0x695, 8, 0, 1000, ReadyToSend);	//VCU_695
    CAN_Set_Message(CAN3, CHANNEL_16, Tx_Flag, EXT_ID, 0x168A0111, 8, 0, 100, ReadyToSend);	//VCU_FA0111 test frame
    CAN_Set_Message(CAN3, CHANNEL_17, Tx_Flag, EXT_ID, 0x168A0222, 8, 0, 100, ReadyToSend);	//VCU_FA0222 test frame
    CAN_Set_Message(CAN3, CHANNEL_18, Tx_Flag, EXT_ID, 0x168A0333, 8, 0, 100, ReadyToSend);	//VCU_FA0333 test frame
    CAN_Set_Message(CAN3, CHANNEL_19, Tx_Flag, EXT_ID, 0x168A0444, 8, 0, 100, ReadyToSend);	//VCU_FA0444 test frame
    CAN_Set_Message(CAN3, CHANNEL_20, Tx_Flag, EXT_ID, 0x168A0555, 8, 0, 100, ReadyToSend);	//VCU_FA0555 test frame
    CAN_Set_Message(CAN3, CHANNEL_21, Tx_Flag, EXT_ID, 0x168A0666, 8, 0, 100, ReadyToSend);	//VCU_FA0666 test frame
    CAN_Set_Message(CAN3, CHANNEL_22, Tx_Flag, EXT_ID, 0x168A0777, 8, 0, 100, ReadyToSend);	//VCU_FA0777 test frame
    CAN_Set_Message(CAN3, CHANNEL_23, Tx_Flag, STD_ID, 0x2C1, 8, 0, 100, DontSending);	//
    CAN_Set_Message(CAN3, CHANNEL_24, Tx_Flag, STD_ID, 0x2C2, 8, 0, 100, DontSending);	//
    CAN_Set_Message(CAN3, CHANNEL_25, Tx_Flag, STD_ID, 0x2C3, 8, 0, 100, DontSending);	//
    CAN_Set_Message(CAN3, CHANNEL_26, Tx_Flag, STD_ID, 0x240, 8, 0, 100, ReadyToSend);	//VCU_240;周期报文
    CAN_Set_Message(CAN3, CHANNEL_27, Tx_Flag, STD_ID, 0x250, 8, 0, 100, ReadyToSend);	//VCU_250;周期报文
    CAN_Set_Message(CAN3, CHANNEL_28, Tx_Flag, STD_ID, 0x260, 8, 0, 100, ReadyToSend);	//VCU_260;周期报文

    CAN_Set_Message(CAN3, CHANNEL_29, Tx_Flag, STD_ID, 0x524, 8, 0, 500, ReadyToSend);    //VCU_524;周期报文
    CAN_Set_Message(CAN3, CHANNEL_30, Tx_Flag, STD_ID, 0x526, 8, 0, 500, ReadyToSend);  //VCU_526;周期报文
    CAN_Set_Message(CAN3, CHANNEL_31, Tx_Flag, STD_ID, 0x528, 8, 0, 500, ReadyToSend);  //VCU_528;周期报文
    CAN_Set_Message(CAN3, CHANNEL_32, Tx_Flag, STD_ID, 0x532, 8, 0, 500, ReadyToSend);  //VCU_532;周期报文
    CAN_Set_Message(CAN3, CHANNEL_33, Tx_Flag, STD_ID, 0x534, 8, 0, 500, ReadyToSend);  //VCU_534;周期报文


    //CAN0 -- CAN0 -- 1
    CAN_Set_Message(CAN0, CHANNEL_0, Tx_Flag, STD_ID, 0x520, 8, 0, 100, DontSending);	//VCU_520 该通道仅用于硬件测试
    CAN_Set_Message(CAN0, CHANNEL_1, Tx_Flag, STD_ID, 0x540, 8, 0, 20, ReadyToSend);	//VCU_540;周期报文
}

void Init_CANTxMessage_S11P03(void)
{
    CAN_Set_Message(CAN3, CHANNEL_0, Tx_Flag, STD_ID, 0x000, 8, 0, 100, DontSending);	//        no use
    CAN_Set_Message(CAN3, CHANNEL_1, Tx_Flag, STD_ID, 0x10A, 8, 0, 100, ReadyToSend);	//VCU_10A
    CAN_Set_Message(CAN3, CHANNEL_2, Tx_Flag, STD_ID, 0x110, 8, 0, 10, ReadyToSend);	//VCU_110
    CAN_Set_Message(CAN3, CHANNEL_3, Tx_Flag, STD_ID, 0x120, 8, 0, 10, ReadyToSend);	//VCU_120
    CAN_Set_Message(CAN3, CHANNEL_4, Tx_Flag, STD_ID, 0x210, 8, 0, 100, ReadyToSend);	//VCU_210
    CAN_Set_Message(CAN3, CHANNEL_5, Tx_Flag, STD_ID, 0x230, 8, 0, 100, ReadyToSend);	//VCU_230
    CAN_Set_Message(CAN3, CHANNEL_6, Tx_Flag, STD_ID, 0x307, 8, 0, 100, ReadyToSend);	//VCU_307
    CAN_Set_Message(CAN3, CHANNEL_7, Tx_Flag, STD_ID, 0x510, 8, 0, 100, ReadyToSend);	//VCU_510
    CAN_Set_Message(CAN3, CHANNEL_8, Tx_Flag, STD_ID, 0x511, 8, 0, 100, ReadyToSend);	//VCU_511
    CAN_Set_Message(CAN3, CHANNEL_9, Tx_Flag, STD_ID, 0x520, 8, 0, 100, ReadyToSend);	//VCU_520
    CAN_Set_Message(CAN3, CHANNEL_10, Tx_Flag, STD_ID, 0x105, 8, 0, 100, DontSending);	//VCU_105
    CAN_Set_Message(CAN3, CHANNEL_11, Tx_Flag, STD_ID, 0x525, 8, 0, 100, ReadyToSend);	//VCU_525
    CAN_Set_Message(CAN3, CHANNEL_12, Tx_Flag, STD_ID, 0x220, 8, 0, 100, DontSending);	//VCU_220 no send
    CAN_Set_Message(CAN3, CHANNEL_13, Tx_Flag, STD_ID, 0x406, 8, 0, 100, DontSending);	//VCU_406  //NM message
    CAN_Set_Message(CAN3, CHANNEL_14, Tx_Flag, STD_ID, 0x530, 8, 0, 100, ReadyToSend);	//VCU_530
    CAN_Set_Message(CAN3, CHANNEL_15, Tx_Flag, STD_ID, 0x695, 8, 0, 1000, ReadyToSend);	//VCU_695
    CAN_Set_Message(CAN3, CHANNEL_16, Tx_Flag, EXT_ID, 0x168A0111, 8, 0, 100, ReadyToSend);	//VCU_FA0111 test frame
    CAN_Set_Message(CAN3, CHANNEL_17, Tx_Flag, EXT_ID, 0x168A0222, 8, 0, 100, ReadyToSend);	//VCU_FA0222 test frame
    CAN_Set_Message(CAN3, CHANNEL_18, Tx_Flag, EXT_ID, 0x168A0333, 8, 0, 100, ReadyToSend);	//VCU_FA0333 test frame
    CAN_Set_Message(CAN3, CHANNEL_19, Tx_Flag, EXT_ID, 0x168A0444, 8, 0, 100, ReadyToSend);	//VCU_FA0444 test frame
    CAN_Set_Message(CAN3, CHANNEL_20, Tx_Flag, EXT_ID, 0x168A0555, 8, 0, 100, ReadyToSend);	//VCU_FA0555 test frame
    CAN_Set_Message(CAN3, CHANNEL_21, Tx_Flag, EXT_ID, 0x168A0666, 8, 0, 500, ReadyToSend);	//VCU_FA0666 test frame
    CAN_Set_Message(CAN3, CHANNEL_22, Tx_Flag, EXT_ID, 0x168A0777, 8, 0, 500, ReadyToSend);	//VCU_FA0777 test frame
    CAN_Set_Message(CAN3, CHANNEL_23, Tx_Flag, STD_ID, 0x2C1, 8, 0, 100, DontSending);	//
    CAN_Set_Message(CAN3, CHANNEL_24, Tx_Flag, STD_ID, 0x2C2, 8, 0, 100, DontSending);	//
    CAN_Set_Message(CAN3, CHANNEL_25, Tx_Flag, STD_ID, 0x2C3, 8, 0, 100, DontSending);	//
    CAN_Set_Message(CAN3, CHANNEL_26, Tx_Flag, STD_ID, 0x240, 8, 0, 100, ReadyToSend);	//VCU_240;周期报文
    CAN_Set_Message(CAN3, CHANNEL_27, Tx_Flag, STD_ID, 0x250, 8, 0, 100, ReadyToSend);	//VCU_250;周期报文
    CAN_Set_Message(CAN3, CHANNEL_28, Tx_Flag, STD_ID, 0x260, 8, 0, 100, ReadyToSend);	//VCU_260;周期报文

    CAN_Set_Message(CAN3, CHANNEL_29, Tx_Flag, STD_ID, 0x524, 8, 0, 500, ReadyToSend);	//VCU_524;周期报文
    CAN_Set_Message(CAN3, CHANNEL_30, Tx_Flag, STD_ID, 0x526, 8, 0, 500, ReadyToSend);	//VCU_526;周期报文
    CAN_Set_Message(CAN3, CHANNEL_31, Tx_Flag, STD_ID, 0x528, 8, 0, 500, ReadyToSend);	//VCU_528;周期报文
    CAN_Set_Message(CAN3, CHANNEL_32, Tx_Flag, STD_ID, 0x532, 8, 0, 500, ReadyToSend);	//VCU_532;周期报文
    CAN_Set_Message(CAN3, CHANNEL_33, Tx_Flag, STD_ID, 0x534, 8, 0, 500, ReadyToSend);	//VCU_534;周期报文

    //CAN0 -- CAN0 -- 1
    CAN_Set_Message(CAN0, CHANNEL_0, Tx_Flag, STD_ID, 0x520, 8, 0, 100, DontSending);	//VCU_520 该通道仅用于硬件测试
    CAN_Set_Message(CAN0, CHANNEL_1, Tx_Flag, STD_ID, 0x540, 8, 0, 20, ReadyToSend);	//VCU_540;周期报文
}

void Init_CANTxMessage_S11P04(void)
{
    CAN_Set_Message(CAN3, CHANNEL_0, Tx_Flag, STD_ID, 0x000, 8, 0, 100, DontSending);	//        no use
    CAN_Set_Message(CAN3, CHANNEL_1, Tx_Flag, STD_ID, 0x10A, 8, 0, 100, ReadyToSend);	//VCU_10A
    CAN_Set_Message(CAN3, CHANNEL_2, Tx_Flag, STD_ID, 0x110, 8, 0, 10, ReadyToSend);	//VCU_110
    CAN_Set_Message(CAN3, CHANNEL_3, Tx_Flag, STD_ID, 0x120, 8, 0, 10, ReadyToSend);	//VCU_120
    CAN_Set_Message(CAN3, CHANNEL_4, Tx_Flag, STD_ID, 0x210, 8, 0, 100, ReadyToSend);	//VCU_210
    CAN_Set_Message(CAN3, CHANNEL_5, Tx_Flag, STD_ID, 0x230, 8, 0, 100, ReadyToSend);	//VCU_230
    CAN_Set_Message(CAN3, CHANNEL_6, Tx_Flag, STD_ID, 0x307, 8, 0, 100, ReadyToSend);	//VCU_307
    CAN_Set_Message(CAN3, CHANNEL_7, Tx_Flag, STD_ID, 0x510, 8, 0, 100, ReadyToSend);	//VCU_510
    CAN_Set_Message(CAN3, CHANNEL_8, Tx_Flag, STD_ID, 0x511, 8, 0, 100, ReadyToSend);	//VCU_511
    CAN_Set_Message(CAN3, CHANNEL_9, Tx_Flag, STD_ID, 0x520, 8, 0, 100, ReadyToSend);	//VCU_520
    CAN_Set_Message(CAN3, CHANNEL_10, Tx_Flag, STD_ID, 0x105, 8, 0, 100, DontSending);	//VCU_105
    CAN_Set_Message(CAN3, CHANNEL_11, Tx_Flag, STD_ID, 0x525, 8, 0, 100, ReadyToSend);	//VCU_525
    CAN_Set_Message(CAN3, CHANNEL_12, Tx_Flag, STD_ID, 0x220, 8, 0, 100, DontSending);	//VCU_220 no send
    CAN_Set_Message(CAN3, CHANNEL_13, Tx_Flag, STD_ID, 0x406, 8, 0, 100, DontSending);	//VCU_406  //NM message
    CAN_Set_Message(CAN3, CHANNEL_14, Tx_Flag, STD_ID, 0x530, 8, 0, 100, ReadyToSend);	//VCU_530
    CAN_Set_Message(CAN3, CHANNEL_15, Tx_Flag, STD_ID, 0x695, 8, 0, 1000, ReadyToSend);	//VCU_695
    CAN_Set_Message(CAN3, CHANNEL_16, Tx_Flag, EXT_ID, 0x168A0111, 8, 0, 100, ReadyToSend);	//VCU_FA0111 test frame
    CAN_Set_Message(CAN3, CHANNEL_17, Tx_Flag, EXT_ID, 0x168A0222, 8, 0, 100, ReadyToSend);	//VCU_FA0222 test frame
    CAN_Set_Message(CAN3, CHANNEL_18, Tx_Flag, EXT_ID, 0x168A0333, 8, 0, 100, ReadyToSend);	//VCU_FA0333 test frame
    CAN_Set_Message(CAN3, CHANNEL_19, Tx_Flag, EXT_ID, 0x168A0444, 8, 0, 100, ReadyToSend);	//VCU_FA0444 test frame
    CAN_Set_Message(CAN3, CHANNEL_20, Tx_Flag, EXT_ID, 0x168A0555, 8, 0, 100, ReadyToSend);	//VCU_FA0555 test frame
    CAN_Set_Message(CAN3, CHANNEL_21, Tx_Flag, EXT_ID, 0x168A0666, 8, 0, 100, ReadyToSend);	//VCU_FA0666 test frame
    CAN_Set_Message(CAN3, CHANNEL_22, Tx_Flag, EXT_ID, 0x168A0777, 8, 0, 100, ReadyToSend);	//VCU_FA0777 test frame
    CAN_Set_Message(CAN3, CHANNEL_23, Tx_Flag, STD_ID, 0x2C1, 8, 0, 100, DontSending);	//
    CAN_Set_Message(CAN3, CHANNEL_24, Tx_Flag, STD_ID, 0x2C2, 8, 0, 100, DontSending);	//
    CAN_Set_Message(CAN3, CHANNEL_25, Tx_Flag, STD_ID, 0x2C3, 8, 0, 100, DontSending);	//
    CAN_Set_Message(CAN3, CHANNEL_26, Tx_Flag, STD_ID, 0x240, 8, 0, 100, ReadyToSend);	//VCU_240;周期报文
    CAN_Set_Message(CAN3, CHANNEL_27, Tx_Flag, STD_ID, 0x250, 8, 0, 100, ReadyToSend);	//VCU_250;周期报文
    CAN_Set_Message(CAN3, CHANNEL_28, Tx_Flag, STD_ID, 0x260, 8, 0, 100, ReadyToSend);	//VCU_260;周期报文

    CAN_Set_Message(CAN3, CHANNEL_29, Tx_Flag, STD_ID, 0x524, 8, 0, 500, ReadyToSend);    //VCU_524;周期报文
    CAN_Set_Message(CAN3, CHANNEL_30, Tx_Flag, STD_ID, 0x526, 8, 0, 500, ReadyToSend);  //VCU_526;周期报文
    CAN_Set_Message(CAN3, CHANNEL_31, Tx_Flag, STD_ID, 0x528, 8, 0, 500, ReadyToSend);  //VCU_528;周期报文
    CAN_Set_Message(CAN3, CHANNEL_32, Tx_Flag, STD_ID, 0x532, 8, 0, 500, ReadyToSend);  //VCU_532;周期报文
    CAN_Set_Message(CAN3, CHANNEL_33, Tx_Flag, STD_ID, 0x534, 8, 0, 500, ReadyToSend);  //VCU_534;周期报文


    //CAN0 -- CAN0 -- 1
    CAN_Set_Message(CAN0, CHANNEL_0, Tx_Flag, STD_ID, 0x520, 8, 0, 100, DontSending);	//VCU_520 该通道仅用于硬件测试
}

void Init_CANTxMessage_S21(void)
{
    CAN_Set_Message(CAN3, CHANNEL_0, Tx_Flag, STD_ID, 0x000, 8, 0, 100, DontSending);	//	    no use
    CAN_Set_Message(CAN3, CHANNEL_1, Tx_Flag, STD_ID, 0x10A, 8, 0, 100, ReadyToSend);	//VCU_10A
    CAN_Set_Message(CAN3, CHANNEL_2, Tx_Flag, STD_ID, 0x110, 8, 0, 10, ReadyToSend);	//VCU_110
    CAN_Set_Message(CAN3, CHANNEL_3, Tx_Flag, STD_ID, 0x120, 8, 0, 10, ReadyToSend);	//VCU_120
    CAN_Set_Message(CAN3, CHANNEL_4, Tx_Flag, STD_ID, 0x210, 8, 0, 100, ReadyToSend);	//VCU_210
    CAN_Set_Message(CAN3, CHANNEL_5, Tx_Flag, STD_ID, 0x230, 8, 0, 100, ReadyToSend);	//VCU_230
    CAN_Set_Message(CAN3, CHANNEL_6, Tx_Flag, STD_ID, 0x307, 8, 0, 100, ReadyToSend);	//VCU_307
    CAN_Set_Message(CAN3, CHANNEL_7, Tx_Flag, STD_ID, 0x510, 8, 0, 100, ReadyToSend);	//VCU_510
    CAN_Set_Message(CAN3, CHANNEL_8, Tx_Flag, STD_ID, 0x511, 8, 0, 100, ReadyToSend);	//VCU_511
    CAN_Set_Message(CAN3, CHANNEL_9, Tx_Flag, STD_ID, 0x520, 8, 0, 100, ReadyToSend);	//VCU_520
    CAN_Set_Message(CAN3, CHANNEL_10, Tx_Flag, STD_ID, 0x105, 8, 0, 100, DontSending);	//VCU_105
    CAN_Set_Message(CAN3, CHANNEL_11, Tx_Flag, STD_ID, 0x525, 8, 0, 100, ReadyToSend);	//VCU_525
    CAN_Set_Message(CAN3, CHANNEL_12, Tx_Flag, STD_ID, 0x220, 8, 0, 100, DontSending);	//VCU_220 no send
    CAN_Set_Message(CAN3, CHANNEL_13, Tx_Flag, STD_ID, 0x406, 8, 0, 100, DontSending);	//VCU_406  //NM message
    CAN_Set_Message(CAN3, CHANNEL_14, Tx_Flag, STD_ID, 0x530, 8, 0, 100, ReadyToSend);	//VCU_530
    CAN_Set_Message(CAN3, CHANNEL_15, Tx_Flag, STD_ID, 0x695, 8, 0, 1000, ReadyToSend);	//VCU_695
    CAN_Set_Message(CAN3, CHANNEL_16, Tx_Flag, EXT_ID, 0x168A0111, 8, 0, 100, ReadyToSend);	//VCU_FA0111 test frame
    CAN_Set_Message(CAN3, CHANNEL_17, Tx_Flag, EXT_ID, 0x168A0222, 8, 0, 100, ReadyToSend);	//VCU_FA0222 test frame
    CAN_Set_Message(CAN3, CHANNEL_18, Tx_Flag, EXT_ID, 0x168A0333, 8, 0, 100, ReadyToSend);	//VCU_FA0333 test frame
    CAN_Set_Message(CAN3, CHANNEL_19, Tx_Flag, EXT_ID, 0x168A0444, 8, 0, 100, ReadyToSend);	//VCU_FA0444 test frame
    CAN_Set_Message(CAN3, CHANNEL_20, Tx_Flag, EXT_ID, 0x168A0555, 8, 0, 100, ReadyToSend);	//VCU_FA0555 test frame
    CAN_Set_Message(CAN3, CHANNEL_21, Tx_Flag, EXT_ID, 0x168A0666, 8, 0, 100, ReadyToSend);	//VCU_FA0666 test frame
    CAN_Set_Message(CAN3, CHANNEL_22, Tx_Flag, EXT_ID, 0x168A0777, 8, 0, 100, ReadyToSend);	//VCU_FA0777 test frame
    CAN_Set_Message(CAN3, CHANNEL_23, Tx_Flag, STD_ID, 0x2C1, 8, 0, 100, DontSending);	//
    CAN_Set_Message(CAN3, CHANNEL_24, Tx_Flag, STD_ID, 0x2C2, 8, 0, 100, DontSending);	//
    CAN_Set_Message(CAN3, CHANNEL_25, Tx_Flag, STD_ID, 0x2C3, 8, 0, 100, DontSending);	//
    CAN_Set_Message(CAN3, CHANNEL_26, Tx_Flag, STD_ID, 0x240, 8, 0, 100, ReadyToSend);	//VCU_240;周期报文
    CAN_Set_Message(CAN3, CHANNEL_27, Tx_Flag, STD_ID, 0x250, 8, 0, 100, ReadyToSend);	//VCU_250;周期报文
    CAN_Set_Message(CAN3, CHANNEL_28, Tx_Flag, STD_ID, 0x260, 8, 0, 100, ReadyToSend);	//VCU_260;周期报文

    CAN_Set_Message(CAN3, CHANNEL_29, Tx_Flag, STD_ID, 0x524, 8, 0, 500, ReadyToSend);  //VCU_524;周期报文
    CAN_Set_Message(CAN3, CHANNEL_30, Tx_Flag, STD_ID, 0x526, 8, 0, 500, ReadyToSend);  //VCU_526;周期报文
    CAN_Set_Message(CAN3, CHANNEL_31, Tx_Flag, STD_ID, 0x528, 8, 0, 500, ReadyToSend);  //VCU_528;周期报文
    CAN_Set_Message(CAN3, CHANNEL_32, Tx_Flag, STD_ID, 0x532, 8, 0, 500, ReadyToSend);  //VCU_532;周期报文
    CAN_Set_Message(CAN3, CHANNEL_33, Tx_Flag, STD_ID, 0x534, 8, 0, 500, ReadyToSend);  //VCU_534;周期报文

    //CAN0 -- CAN0 -- 1
    CAN_Set_Message(CAN0, CHANNEL_0, Tx_Flag, STD_ID, 0x520, 8, 0, 100, DontSending);	//VCU_520 该通道仅用于硬件测试
    //CAN1 -- CAN1 -- 1
    CAN_Set_Message(CAN1, CHANNEL_0, Tx_Flag, STD_ID, 0x520, 8, 0, 100, DontSending);  //VCU_520 该通道仅
    CAN_Set_Message(CAN1, CHANNEL_1, Tx_Flag, STD_ID, 0x282, 8, 0, 100, ReadyToSend);  //VCU_282 BodyCAN

}

void Init_CANTxPeriodMessage(void)
{
    //clear
    memset(&CAN2_TX_Array, 0, CAN2_TX_NUM * (sizeof(_CAN_MESSAGE_)));
    memset(&CAN1_TX_Array, 0, CAN1_TX_NUM * (sizeof(_CAN_MESSAGE_)));
    memset(&CAN3_TX_Array, 0, CAN3_TX_NUM * (sizeof(_CAN_MESSAGE_)));
    memset(&CAN0_TX_Array, 0, CAN0_TX_NUM * (sizeof(_CAN_MESSAGE_)));

    //CAN2 -- CAN2 -- 1
    CAN_Set_Message(CAN2, CHANNEL_0, Tx_Flag, STD_ID, 0x520, 8, 0, 100, DontSending);  //VCU_520 该通道仅用于硬件测试

    //CAN1 -- CAN1 -- 1
    CAN_Set_Message(CAN1, CHANNEL_0, Tx_Flag, STD_ID, 0x520, 8, 0, 100, DontSending);  //VCU_520 该通道仅用于硬件测试

    //CAN3 -- CAN3 -- 26 :: CAN0 -- CAN0
    if( (S11P01_Mark == Vehicle_Type) || (S11P05_Mark == Vehicle_Type) )
    {
        Init_CANTxMessage_S11P01();
    }
    else if( A11_Mark == Vehicle_Type )
    {
        Init_CANTxMessage_A11();
    }
    else if( S11P03_Mark == Vehicle_Type )
    {
        Init_CANTxMessage_S11P03();
    }
    else if( S11P04_Mark == Vehicle_Type )
    {
        Init_CANTxMessage_S11P04();
    }
    else if( S21_Mark == Vehicle_Type )
    {
        Init_CANTxMessage_S21();
    }
    else if( (K11P01_Mark == Vehicle_Type) || (K11_Mark == Vehicle_Type) )
    {
        Init_CANTxMessage_K11P01();
    }
    else	//默认为S11
    {
        Init_CANTxMessage_S11();
    }
}

void NM_ShutAll_CANTxPeriodMessage(void)
{
    uint8_t i = 0;

    SYS_Shut10msTimer();
    NM_ShutPerSend = 1;

    for(i = 0; i < CAN3_TX_NUM; i++)
    {
        CAN_Set_TxMessageUncondition(CAN3, i, 0);
        CAN_Set_MessageFlag(CAN3, i, Tx_Flag, DontSending);
        CAN_Set_TxMessageResend(CAN3, i, 0);
    }
    for(i = CAN3_TX_Random_Start; i <= CAN3_TX_Period_End; i++)
    {
        CAN_3.MB[i].CS.B.CODE = CAN_TXCODE_INACTIVE;
    }
}

void Config_NormalSending(void)
{

}

//NM 模块在最起始的阶段处理
void NM_SetMessage(void)
{
    SYS_Shut10msTimer();	//关闭10ms计时

    Init_CANTxPeriodMessage();

    CAN_Set_TxMessageUncondition(CAN3, CHANNEL_0, 2);
    CAN_Set_TxMessageUncondition(CAN3, CHANNEL_1, 1);
    CAN_Set_TxMessageUncondition(CAN3, CHANNEL_2, 1);
    CAN_Set_TxMessageUncondition(CAN3, CHANNEL_3, 1);
    CAN_Set_TxMessageUncondition(CAN3, CHANNEL_4, 1);
    CAN_Set_TxMessageUncondition(CAN3, CHANNEL_5, 1);
    CAN_Set_TxMessageUncondition(CAN3, CHANNEL_6, 1);
    CAN_Set_TxMessageUncondition(CAN3, CHANNEL_7, 1);
    CAN_Set_TxMessageUncondition(CAN3, CHANNEL_8, 1);
    CAN_Set_TxMessageUncondition(CAN3, CHANNEL_9, 1);
    CAN_Set_TxMessageUncondition(CAN3, CHANNEL_10, 2);	//No send :105
    CAN_Set_TxMessageUncondition(CAN3, CHANNEL_11, 1);
    if( (A11_Mark == Vehicle_Type) || (K11P01_Mark == Vehicle_Type) || (K11_Mark == Vehicle_Type) )
        CAN_Set_TxMessageUncondition(CAN3, CHANNEL_12, 1);  //VCU106
    else
        CAN_Set_TxMessageUncondition(CAN3, CHANNEL_12, 2);  //VCU220
    CAN_Set_TxMessageUncondition(CAN3, CHANNEL_13, 2);
    CAN_Set_TxMessageUncondition(CAN3, CHANNEL_14, 1);
    CAN_Set_TxMessageUncondition(CAN3, CHANNEL_15, 1);
    CAN_Set_TxMessageUncondition(CAN3, CHANNEL_16, 2);
    CAN_Set_TxMessageUncondition(CAN3, CHANNEL_17, 2);
    CAN_Set_TxMessageUncondition(CAN3, CHANNEL_18, 2);
    CAN_Set_TxMessageUncondition(CAN3, CHANNEL_19, 2);
    CAN_Set_TxMessageUncondition(CAN3, CHANNEL_20, 2);
    CAN_Set_TxMessageUncondition(CAN3, CHANNEL_21, 2);
    CAN_Set_TxMessageUncondition(CAN3, CHANNEL_22, 2);
    CAN_Set_TxMessageUncondition(CAN3, CHANNEL_23, 2);  //2C1
    CAN_Set_TxMessageUncondition(CAN3, CHANNEL_24, 2);  //2C2
    CAN_Set_TxMessageUncondition(CAN3, CHANNEL_25, 2);  //2C3
    //send
    CAN_Set_TxMessageUncondition(CAN3, CHANNEL_26, 1);  //240
    CAN_Set_TxMessageUncondition(CAN3, CHANNEL_27, 1);  //250
    CAN_Set_TxMessageUncondition(CAN3, CHANNEL_28, 1);  //260

    CAN_Set_TxMessageUncondition(CAN3, CHANNEL_29, 1);  //524
    CAN_Set_TxMessageUncondition(CAN3, CHANNEL_30, 1);  //526
    CAN_Set_TxMessageUncondition(CAN3, CHANNEL_31, 1);  //528
    CAN_Set_TxMessageUncondition(CAN3, CHANNEL_32, 1);  //532
    CAN_Set_TxMessageUncondition(CAN3, CHANNEL_33, 1);  //534

    NM_ShutPerSend = 0;
    SYS_Reset10msTimer(); //重新打开10ms计时，
}

void Init_CanMessage(void)
{

    Init_CANRxMessage();
    Init_CANTxPeriodMessage();
    CAN_RX_Begin();
}

/*
 * CAN 发送或接收的一些额外判断条件,以及报文解析
 * */
void System_CANBaseCycle(void)
{

    CAN_analysis();
    /*App message receiption is disabled, don't update the message tick*/
    if( (UDS_EnRx_DisTx == AppComCtrlType) || (UDS_EnRx_EnTx == AppComCtrlType) )
    {
        //CAN报文接收后的相关处理
        if( (S11P01_Mark == Vehicle_Type) || (S11P05_Mark == Vehicle_Type) )
        {
//            S11P01_GetRecvMsgTicks();
        }
        else if( A11_Mark == Vehicle_Type )
        {
            A11_GetRecvMsgTicks();
        }
        else if( S11P03_Mark == Vehicle_Type )
        {
            S11P03_GetRecvMsgTicks();
        }
        else if( S11P04_Mark == Vehicle_Type )
        {
            S11P04_GetRecvMsgTicks();
        }
        else if( S21_Mark == Vehicle_Type )
        {
            S21_GetRecvMsgTicks();
        }
        else if( K11P01_Mark == Vehicle_Type )
        {
            K11P01_GetRecvMsgTicks();
        }
        else if( K11_Mark == Vehicle_Type )
        {
            K11_GetRecvMsgTicks();
        }
        else
        {
            S11_GetRecvMsgTicks();
        }
        CANDBC_TickCycle();
    }
//    if( Config_output.C_TMS_En && Config_output.C_TMS_Internal && (S11P01_Mark == Vehicle_Type) )
//    {
//        CAN_Set_MessageFlag(CAN3, CHANNEL_23, Tx_Flag, ReadyToSend);
//        CAN_Set_MessageFlag(CAN3, CHANNEL_24, Tx_Flag, ReadyToSend);
//        CAN_Set_MessageFlag(CAN3, CHANNEL_25, Tx_Flag, ReadyToSend);
//    }
}

/************************************************************************************    DIO    ****/
void Init_DIO(void)
{
    //数字量输入
    SIUL_DigitalInputSimple(D_IN1_PAD, 0);	//PWMT1--D_IN1
    SIUL_DigitalInputSimple(D_IN2_PAD, 0);	//PWMT2--D_IN2
    SIUL_DigitalInputSimple(D_IN3_PAD, 0);	//PWMT3--D_IN3
    SIUL_DigitalInputSimple(D_IN4_PAD, 0);	//PWMT4--D_IN4
    SIUL_DigitalInputSimple(D_IN5_PAD, 0);	//PWMT5--D_IN5
    SIUL_DigitalInputSimple(D_IN6_PAD, 0);	//PWMT6--D_IN6
    SIUL_DigitalInputSimple(D_IN7_PAD, 0);	//PWMT7--D_IN7
    SIUL_DigitalInputSimple(D_IN8_PAD, 0);	//PWMT8--D_IN8
    SIUL_DigitalInputSimple(D_IN9_PAD, 0);	//PWMT9--D_IN9
    SIUL_DigitalInputSimple(D_IN10_PAD, 0);	//PWMT10--D_IN10
    SIUL_DigitalInputSimple(D_IN11_PAD, 0);	//PWMT11--D_IN11
    SIUL_DigitalInputSimple(D_IN12_PAD, 0);	//PWMT12--D_IN12
//	SIUL_DigitalInputSimple(D_IN13_PAD,0);//PWMT13--D_IN13	for PWM
    SIUL_DigitalInputSimple(D_IN14_PAD, 0);	//PWMT14--D_IN14
    SIUL_DigitalInputSimple(D_IN15_PAD, 0);	//PWMT15--D_IN15
    SIUL_DigitalInputSimple(D_IN16_PAD, 0);	//PWMT16--D_IN16
    SIUL_DigitalInputSimple(D_IN17_PAD, 0);	//PWMT17--D_IN17
    SIUL_DigitalInputSimple(D_IN18_PAD, 0);	//PWMT18--D_IN18
    SIUL_DigitalInputSimple(D_IN19_PAD, 0);	//PWMT19--D_IN19
    SIUL_DigitalInputSimple(D_IN20_PAD, 0);	//PWMT20--D_IN20
    SIUL_DigitalInputSimple(D_IN21_PAD, 0);	//PWMT21--D_IN21
    SIUL_DigitalInputSimple(D_IN22_PAD, 0);	//PWMT22--D_IN22
    SIUL_DigitalInputSimple(D_IN23_PAD, 0);	//PWMT23--D_IN23
    SIUL_DigitalInputSimple(D_IN24_PAD, 0);	//PWMT24--D_IN24
    SIUL_DigitalInputSimple(D_IN25_PAD, 0);	//PWMT25--D_IN25
//	SIUL_DigitalInputSimple(D_IN26_PAD,0);//PWMT26--D_IN26	for PWM
    SIUL_DigitalInputSimple(D_IN27_PAD, 0);	//PWMT27--D_IN27
//	SIUL_DigitalInputSimple(D_IN28_PAD,0);//PWMT28--D_IN28	for PWM
    SIUL_DigitalInputSimple(D_IN29_PAD, 0);	//PWMT29--D_IN29
    SIUL_DigitalInputSimple(D_IN30_PAD, 0);	//PWMT30--D_IN30
//	SIUL_DigitalInputSimple(D_IN31_PAD,0);//PWMT31--D_IN31	for PWM

    SIUL_DigitalOutput(DIN_KL30a2_C, 0);	//Pull Up resistance for All DIN is pull up setting
    SIUL_SetPad(DIN_KL30a2_C);				//Enable
    /*initialize the LED driving port from PWM to GPIO */
    //if( 0 != C_PMS_En )
    //{
        //SIUL_DigitalIO(GPIO_PORTA + 9, 0x00);
        //SIUL_DigitalIO(GPIO_PORTA + 10, 0x00);
        //SIUL_ClearPad(GPIO_PORTA + 9);
        //SIUL_ClearPad(GPIO_PORTA + 10);
    //}
}

void HAL_Capture_Digital(void)
{
    uint32_t i = 0;
    static uint8_t pre_Sw_input[SW_NUM] = { 0 };
    static uint8_t Sw_input_temp[SW_NUM] = { 0 };

    /*  保存上次采集数据  */
    for(i = 0; i < SW_NUM; i++)
    {
        pre_Sw_input[i] = Sw_input_temp[i];
    }
    /*  采集当前数据  */
    Sw_input_temp[0] = SIUL_GetPadState(D_IN1_PAD);				//空调中压开关检测，低电平有效
    Sw_input_temp[1] = SIUL_GetPadState(D_IN2_PAD);
    Sw_input_temp[2] = SIUL_GetPadState(D_IN3_PAD);				//点火信号输入
    Sw_input_temp[3] = SIUL_GetPadState(D_IN4_PAD);				//霍尔信号2
    Sw_input_temp[4] = SIUL_GetPadState(D_IN5_PAD);				//霍尔信号4
    Sw_input_temp[5] = SIUL_GetPadState(D_IN6_PAD);				//霍尔信号3
    Sw_input_temp[6] = SIUL_GetPadState(D_IN7_PAD);				//P档位
    Sw_input_temp[7] = SIUL_GetPadState(D_IN8_PAD);				//PTC采集
    Sw_input_temp[8] = SIUL_GetPadState(D_IN9_PAD);
    Sw_input_temp[9] = SIUL_GetPadState(D_IN10_PAD);
    Sw_input_temp[10] = SIUL_GetPadState(D_IN11_PAD);			//制动信号2，高电平有效
    Sw_input_temp[11] = SIUL_GetPadState(D_IN12_PAD);
    Sw_input_temp[12] = SIUL_GetPadState(D_IN13_PAD);			//using for PWM, can read but not initial
    Sw_input_temp[13] = SIUL_GetPadState(D_IN14_PAD);	//快充口A+信号采集
    Sw_input_temp[14] = SIUL_GetPadState(D_IN15_PAD);	//制动信号1，数字量输入(高有效)
    Sw_input_temp[15] = SIUL_GetPadState(D_IN16_PAD);
    //慢充口信号采集,高电平有效
    Sw_input_temp[16] = SIUL_GetPadState(D_IN17_PAD);
    Sw_input_temp[17] = SIUL_GetPadState(D_IN18_PAD);
    Sw_input_temp[18] = SIUL_GetPadState(D_IN19_PAD);
    Sw_input_temp[19] = SIUL_GetPadState(D_IN20_PAD);
    Sw_input_temp[20] = SIUL_GetPadState(D_IN21_PAD);
    Sw_input_temp[21] = SIUL_GetPadState(D_IN22_PAD);
    Sw_input_temp[22] = SIUL_GetPadState(D_IN23_PAD);
    Sw_input_temp[23] = SIUL_GetPadState(D_IN24_PAD);
    Sw_input_temp[24] = SIUL_GetPadState(D_IN25_PAD);
    Sw_input_temp[25] = SIUL_GetPadState(D_IN26_PAD);	//using for PWM, can read but not initial
    Sw_input_temp[26] = SIUL_GetPadState(D_IN27_PAD);
    Sw_input_temp[27] = SIUL_GetPadState(D_IN28_PAD);	//using for PWM, can read but not initial
    Sw_input_temp[28] = SIUL_GetPadState(D_IN29_PAD);
    Sw_input_temp[29] = SIUL_GetPadState(D_IN30_PAD);
    Sw_input_temp[30] = SIUL_GetPadState(D_IN31_PAD);	//using for PWM, can read but not initial

    /*  5ms 抖动软件滤波    */
    for(i = 0; i < SW_NUM; i++)
    {
        if( pre_Sw_input[i] == Sw_input_temp[i] )
        {
            Bios_Sw_Input[i] = Sw_input_temp[i];
        }
    }
}

uint8_t HAL_Get_Digital(uint8_t Channel)
{
    if( Channel < SW_NUM )
    {
        return Bios_Sw_Input[Channel];
    }
    else
    {
        return 0;
    }
}

/************************************************************************************    ADC    ****/
void HAL_Capture_ADC(void)
{
    uint32_t i = 0;

    SARADC_GetAll();	//ADC 采集
    for(i = 0; i < ADC_NUM; i++)
    {
        ADC_OutBuff[i] = ADC_Buff[i];
    }
}

float HAL_Get_ADC(unsigned char Channel)
{
    float adc_data_temp = 0;
    if( Channel < ADC_NUM )
    {
        adc_data_temp = ADC_OutBuff[Channel];
        if( 0 == adc_data_temp )
        {
            adc_data_temp = 0;
        }
        else
        {
            adc_data_temp = (adc_data_temp + 1) * 5 / 4096;
        }
    }
    return adc_data_temp;
}

/************************************************************************************    PWM in    ****/
void HAL_Capture_Fin(void)
{
    eMIOS_CalculationAll();	//PWM 输入计算
    eMIOS_cycle();	//PWM 输入超时判断及处理
    GetEMIOS0_9();
    GetEMIOS0_10();
    GetEMIOS0_12();
    GetEMIOS0_18();
    GetEMIOS1_13();
    GetEMIOS1_16();
    GetEMIOS1_17();
    GetEMIOS1_20();
}

float HAL_Get_Finf(uint8_t Channel)
{
    if( Channel < EMIOSNUM )
    {
        return eMIOS_PWMin_data[Channel].freq;
    }
    else
    {
        return 0;
    }
}

float HAL_Get_FinDuty(uint8_t Channel)
{
    if( Channel < EMIOSNUM )
    {
        return eMIOS_PWMin_data[Channel].duty;
    }
    else
    {
        return 0;
    }

}

/************************************************************************************    HLS    ****/
void HAL_Drive_HLS(void)
{
    uint8_t i = 0;

    //低驱数据填入
    for(i = 0; i < 6; i++)
    {
        if( Bios_LS_Output[i] == 0 )
        {
            NCV7513B_Set_Data(i, 0);
        }
        else
        {
            NCV7513B_Set_Data(i, 1);
        }
    }

    for(i = 6; i < 14; i++)
    {
        if( Bios_LS_Output[i] == 0 )
        {
            NCV7240B_Set_SI(i - 5, NCV7240B_OFF);
        }
        else
        {
            NCV7240B_Set_SI(i - 5, NCV7240B_ON);
        }
    }

    //高驱数据填入
    if( Bios_HS_Output[0] == 0 )
    {
        BTS5180_SetValue(1, 0);
    }
    else
    {
        BTS5180_SetValue(1, 1);
    }
    if( Bios_HS_Output[1] == 0 )
    {
        BTS5180_SetValue(2, 0);
    }
    else
    {
        BTS5180_SetValue(2, 1);
    }
    if( Bios_HS_Output[2] == 0 )
    {
        BTS5200_SetValue(1, 0);
    }
    else
    {
        BTS5200_SetValue(1, 1);
    }
    if( Bios_HS_Output[3] == 0 )
    {
        BTS5200_SetValue(2, 0);
    }
    else
    {
        BTS5200_SetValue(2, 1);
    }
    if( Bios_HS_Output[4] == 0 )
    {
        BTS5200_SetValue(3, 0);
    }
    else
    {
        BTS5200_SetValue(3, 1);
    }
    if( Bios_HS_Output[5] == 0 )
    {
        BTS5200_SetValue(4, 0);
    }
    else
    {
        BTS5200_SetValue(4, 1);
    }

    //增加测试模式下电压大于18V即关断所有输出
    if( (udsHWTestingModeStatus == UDS_START_HWTEST) && (hIOP_K30_V > 17.5) )
    {
        for(i = 0; i < 6; i++)
        {
            NCV7513B_Set_Data(i, 0);
        }
        for(i = 6; i < 14; i++)
        {
            NCV7240B_Set_SI(i - 5, NCV7240B_OFF);
        }
        BTS5180_HS1_Clear();
        BTS5180_HS2_Clear();
        BTS5200_HS11_Clear();
        BTS5200_HS12_Clear();
        BTS5200_HS13_Clear();
        BTS5200_HS14_Clear();
        NCV7719_data.CH1_6.R = 0b1000000000000001; //2HS 1LS
        NCV7719_data.CH7_8.R = 0b1100000000000001; //8HS 7LS
    }
    //执行写入，使数据生效
    NCV7513B_Refresh();
    NCV7240B_Refresh();
    BTS5180_Refresh();
    BTS5200_Refresh();
    NCV7719_Refresh1_6();
    NCV7719_Refresh7_8();

    //diagnostic
    BTS5180_Diagnostic();
    BTS5200_Diagnostic();
}

void HAL_Drive_LS(uint8_t Channel, uint8_t Value)
{
    if( (Value == 1) && (Channel < LS_NUM) )
    {
        Bios_LS_Output[Channel] = Value;
    }
    else
    {
        Bios_LS_Output[Channel] = 0;
    }
}

void HAL_Drive_HS(uint8_t Channel, uint8_t Value)
{
    if( (Value == 1) && (Channel < HS_NUM) )
    {
        Bios_HS_Output[Channel] = Value;
    }
    else
    {
        Bios_HS_Output[Channel] = 0;
    }
}

/************************************************************************************    PWM out    ****/
void HAL_Set_WaterPwm(uint32_t fre, uint16_t duty)
{
    my_fs_etpu_pwm_update(PWM0_CHANNEL, fre, duty * 100);
}

void HAL_Set_LockPwm(uint32_t fre, uint16_t duty)
{
    my_fs_etpu_pwm_update(PWM1_CHANNEL, fre, duty * 100);
}

/************************************************************************************    Power Down    ****/
void HAL_Drive_Sleep(uint8_t Value)
{
    if( Value )
    {
        FS65_SetLPOFFmode();	//控制SBC进入低功耗状态
    }
}

/************************************************************************************    System Cycle    ****/
void System_5ms(void)
{
    static uint8_t ChannelTime = 0;
    /***	CAN TX		***************/
    /*VCU_105*//*Zhou Yi 2017-1-4 根据上层要求发送VCU_105 当发生0到非0 的跳变时  */
    if( NM_AppWaitValid == 0 )
    {
        if( VPEPS_SendChallengeCodeType_enum > Old_VPEPS_SendChallengeCodeType_enum )
        {
            ChannelTime += 5;
            if( ChannelTime >= 10 )
            {
                Old_VPEPS_SendChallengeCodeType_enum = VPEPS_SendChallengeCodeType_enum;

                if( 2 == NM_First )	//105根据PEPS的指示进行发送，同样也属于应用报文，需要在本地唤醒时同Alive报文间隔150ms以上。
                {
                    CAN_gather(CAN3, CHANNEL_10);
                    CANTransimitRandomMessage(CAN3, &CAN3_TX_Array[CHANNEL_10]);
                }
                ChannelTime = 0;
            }
        }
    }
    if( KUDS_TestFeature == 0 )	//标定量，用于是否开启发送测试帧
    {
        CAN_Set_MessageFlag(CAN3, CHANNEL_16, Tx_Flag, DontSending);
        CAN_Set_MessageFlag(CAN3, CHANNEL_17, Tx_Flag, DontSending);
        CAN_Set_MessageFlag(CAN3, CHANNEL_18, Tx_Flag, DontSending);
        CAN_Set_MessageFlag(CAN3, CHANNEL_19, Tx_Flag, DontSending);
        CAN_Set_MessageFlag(CAN3, CHANNEL_20, Tx_Flag, DontSending);
        CAN_Set_MessageFlag(CAN3, CHANNEL_21, Tx_Flag, DontSending);
        CAN_Set_MessageFlag(CAN3, CHANNEL_22, Tx_Flag, DontSending);
    }

    HAL_Capture_Digital();    //数字量采集
    HAL_Capture_ADC();        //模拟量采集
    HAL_Capture_Fin();        //频率量采集
    HAL_Drive_HLS();          //高低边驱动
}

void System_MainCycle(void)
{
    System_CANBaseCycle();         //接收报文解析
    LIN_Device_Refresh();	//LIN 设备信息解析及组装
    Bus_AckHandle();
    Bus_OffHandlerTask();
}


/*
 * TaskLib.c
 *
 *  Created on: 2019年7月11日
 *      Author: helei
 */

#define TASKLIB_GLOBALS

#include "derivative.h"
#include "BASE_Global.h"
#include "Modules_Global.h"
#include "System.h"
#include "Global.h"
#include "CAN_DBC_Lib.h"
#include "CAN_Operation.h"
#include "uds_tp.h"
#include "uds_service.h"
#include "CCP.h"
#include "NVM.h"
// #include "HALI_Model.h"
// #include "DIM_Model.h"
// #include "DHP_Model.h"
//#include "CHRG_Model.h"
//#include "ENM_Model.h"
//#include "TQM_Model.h"
// #include "TQFRate_model.h"
// #include "SCR_model.h"
// #include "ACR_model.h"
// #include "TMM_Model.h"
// #include "PEPS_Model.h"
// #include "DOM_Model.h"
// #include "AVAS_Model.h"
// #include "NM_Model.h"
// #include "PMM_model.h"
#include "ccp.h"
#include "EX_Define.h"
#include "TaskLib.h"
// #include "BTK_Model.h"
extern void PMM_model_step(void);

uint16_t LSChipStatus7240B = 0;

void CheckHLSFaultsPOR(void)
{
    uint16_t data = 0;
    uint32_t tempCode = 0;
    hIOP_LSFaultCode_enum_POR = 0;
    hIOP_HSFaultCode_enum_POR = 0;
    uint8_t i = 0;
    //低驱数据填入
    for(i = 6u; i < 14u; i++)
    {
        NCV7240B_Set_SI(i - 5u, NCV7240B_OFF);
    }
    //执行写入，使数据生效
    NCV7240B_Refresh();

    data = NCV7240B_SO_data.R >> 4;
    if( 2 == (data & 0x02u) ) //MainRelay
    {
        tempCode = (0b01u << 14u);  //openload
    }
    hIOP_LSFaultCode_enum_POR += tempCode;

    // if( 0 != C_PMS_En )  //BlueToothKey
    // {
    //     //低驱数据填入
    //     for(i = 0; i < 6; i++)
    //     {
    //         NCV7513B_Set_Data(i, 0);
    //     }
    //     //执行写入，使数据生效
    //     NCV7513B_Refresh();

    //     data = NCV7513B_SO_data.R;
    //     //IGN1(LS1_out6)
    //     tempCode = (data >> 10) & 0b11;
    //     hIOP_LSFaultCode_enum_POR += tempCode << 16;

    //     //IGN2(LS1_out5)
    //     tempCode = (data >> 8) & 0b11;
    //     hIOP_LSFaultCode_enum_POR += tempCode << 18;

    //     if( C_ESCL_En )  //装配了ESCL
    //     {
    //         //ESCL power (LS1_out3)
    //         tempCode = (data >> 4) & 0b11;
    //         hIOP_LSFaultCode_enum_POR += tempCode << 20;
    //     }
    // }

    return;
}

void CheckLSFaults(void)
{
    uint16_t LSChipStatus7513B = 0;
    LSChipStatus7240B = 0;
    uint16_t tempData = 0;
    uint32_t tempFaultCode = 0;
    hIOP_LSFaultCode_enum = 0; /* VCU1.0: MCURelay(0) +LS(1) +HS(2) +WaterPump(3) +(BMSawake)(4)+  Rlight(5) + PTC(6) + MainRelay(7) */
    //NCV7513B_SO_data.R; //LS 0~5
    //NCV7240B_SO_data.R;  //LS 6~13
    LSChipStatus7240B = NCV7240B_SO_data.R; //Rlight
    if( 1 == (LSChipStatus7240B & 0x01) )
    {
        tempFaultCode = (0b11 << 10); //overload
    }
    else
    {
        tempFaultCode = 0;
    }
    hIOP_LSFaultCode_enum += tempFaultCode;

    tempData = LSChipStatus7240B >> 4; //MainRelay
    //if( 2==(tempData & 0x02) )
    //	tempFaultCode = (0b01 << 14);  //openload
    if( 1 == (tempData & 0x01) )
    {
        tempFaultCode = (0b11 << 14); //overload
    }
    else
    {
        tempFaultCode = 0;
    }
    hIOP_LSFaultCode_enum += tempFaultCode;

    tempData = LSChipStatus7240B >> 6; //PTCRelay
    if( 1 == (tempData & 0x01) )
    {
        tempFaultCode = (0b11 << 12); //overload
    }
    else
    {
        tempFaultCode = 0;
    }
    hIOP_LSFaultCode_enum += tempFaultCode;

    tempData = LSChipStatus7240B >> 8; //MCURelay
    if( 1 == (tempData & 0x01) )
    {
        tempFaultCode = (0b11); //overload
    }
    else
    {
        tempFaultCode = 0;
    }
    hIOP_LSFaultCode_enum += tempFaultCode;

    tempData = LSChipStatus7240B >> 10; //LSFanRelay
    if( 1 == (tempData & 0x01) )
    {
        tempFaultCode = (0b11 << 2); //overload
    }
    else
    {
        tempFaultCode = 0;
    }
    hIOP_LSFaultCode_enum += tempFaultCode;

    tempData = LSChipStatus7240B >> 12; //WaterPump
    if( 1 == (tempData & 0x01) )
    {
        tempFaultCode = (0b11 << 6); //overload
    }
    else
    {
        tempFaultCode = 0;
    }
    hIOP_LSFaultCode_enum += tempFaultCode;

    tempData = LSChipStatus7240B >> 14; //HSFanRelay
    if( 1 == (tempData & 0x01) )
    {
        tempFaultCode = (0b11 << 4); //overload
    }
    else
    {
        tempFaultCode = 0;
    }
    hIOP_LSFaultCode_enum += tempFaultCode;

    // if( 0 != C_PMS_En ) //BluetoothKey
    // {
    //     LSChipStatus7513B = NCV7513B_SO_data.R;
    //     tempData = LSChipStatus7513B >> 10; //IGN1(LS1_out6)
    //     tempFaultCode = tempData & 0b11;
    //     hIOP_LSFaultCode_enum += tempFaultCode << 16;

    //     tempData = LSChipStatus7513B >> 8; //IGN2(LS1_out5)
    //     tempFaultCode = tempData & 0b11;
    //     hIOP_LSFaultCode_enum += tempFaultCode << 18;

    //     if( C_ESCL_En ) //装配了ESCL
    //     {
    //         tempData = LSChipStatus7513B >> 4; //ESCL power (LS1_out3)
    //         tempFaultCode = tempData & 0b11;
    //         hIOP_LSFaultCode_enum += tempFaultCode << 20;
    //     }
    // }

    return;
}

// for HS diagnostic
void CheckHSFaults(void)
{
    hIOP_HSFaultCode_enum = 0;
    //  BTS5180_data   HS 0~1
    //  BTS5200_data   HS 2~6
    if( 1 == BTS5180_data[0].openload )
    {
        hIOP_HSFaultCode_enum = 0b01;
    }
    if( 1 == BTS5180_data[0].shortload )
    {
        hIOP_HSFaultCode_enum = 0b10;
    }
    return;
}

void NM_Handle(void)
{
    static uint32_t timeStart = 0xFFFF;
    static uint32_t timeTwbs = 0xFFFFFFFF;

    if( NM_AppWaitValid == 2 )
    {
        timeStart = SystemTickMs;
        NM_AppWaitValid = 3;
    }
    if( (NM_AppWaitValid == 3) && ((timeStart + 140u) <= SystemTickMs) )
    {
        NM_SetMessage();
        NM_AppWaitValid = 0;
    }

    if( NM_Twbs == NM_Begin_Twbs )  //进入Twbs时间计时
    {
        timeTwbs = SystemTickMs;
        NM_Twbs = NM_Enter_Twbs;
    }
    if( NM_Twbs == NM_Enter_Twbs )
    {
        if( (timeTwbs + 1600) < SystemTickMs )  //可以休眠
        {
            NM_Twbs = NM_End_Twbs;
        }
        // if( (VHALI_NMIndication == 0) || (hIOP_K15_V > 8) || (!VBTK_SleepAllw_flg) || (hIOP_SlowChargeAwake_flg)
        //         || (hIOP_FastChargeAwake_flg) )  //可以恢复通信
        // {
        //     NM_Twbs = NM_Before_Tbws;  //退出Twbs并恢复通信
        //     NM_ReACKandCanStop = 0;  //恢复通信
        //     NM_First = 0;
        //     NM_quitTwbsFirstF = 1;
        // }
    }
    // if( (NM_Twbs == NM_End_Twbs)
    //         && ((VHALI_NMIndication == 0) || (!VBTK_SleepAllw_flg) || (hIOP_K15_V > 8) || (hIOP_SlowChargeAwake_flg)
    //                 || (hIOP_FastChargeAwake_flg)) )  //可以恢复通信
    // {
    //     NM_Twbs = NM_Before_Tbws;  //退出Twbs并恢复通信
    //     NM_ReACKandCanStop = 0;  //恢复通信
    //     NM_First = 0;
    //     NM_quitTwbsFirstF = 1;
    // }
}

void Task_NM(void)
{
    uint32_t timeTemp = 0;

    NM_Handle();
    // NM_Model_step();
    if( (1 != VHALO_DisableAppComm) && (1 != NM_ReACKandCanStop) && (CAN3_BusOffDelayTimeOut == 1) && (CAN3_AckErrFlag == 0) )
    {
        if( (0 != VHALO_NMSendReq) && (Old_VHALO_NMSendReq != VHALO_NMSendReq) )
        {
            if( VHALO_NMSendAcknowledge == 1 )  //需要发送32时关闭周期报文发送
            {
                NM_ShutAll_CANTxPeriodMessage();
            }

            if( NM_quitTwbsFirstF == 1 )	 //退出Twbs并进入NMRest需要发送alive
            {
                if( VHALO_NMSendLimpHome != 1 )	 //limphome模式
                {
                    VHALO_NMSendAlive = 1;
                    VHALO_NMSendRing = 0;
                }
                NM_quitTwbsFirstF = 0;
            }
            if( ((VHALO_NMSendLimpHome == 1) && (VHALO_NMSendIndication == 1))
                    || ((VHALO_NMSendAcknowledge == 1) && (VHALO_NMSendIndication == 1)) )
            {
                //最后发送14或32时需要判断周期报文的发送时间，并估算大约5ms后MB中的报文可以发送出去即可发送NM报文
                timeTemp = SystemTickMs - CAN_PeriodSendTime;
                if( timeTemp < 5 )
                {
                    wait_micsec(5u - timeTemp);	 //等待到间隔5毫秒之后发送
                }
            }
            CanNmTx_Handle();
        }
        Old_VHALO_NMSendReq = VHALO_NMSendReq;
        if( ((VHALO_NMSendLimpHome == 1) && (VHALO_NMSendIndication == 1))
                || ((VHALO_NMSendAcknowledge == 1) && (VHALO_NMSendIndication == 1)) )	 //进入Twbs状态;发送14或32
        {
            VHALI_NMIndication = 1;	 //将接收并存下的ind位设置为不能唤醒1;
            NM_ReACKandCanStop = 1;
            NM_Twbs = NM_Begin_Twbs;
        }
    }
}

void Task_GetSignal_Step1(void)
{
#if (RUN_UDS_NVM_ON_CORE1 == 1)
    udsTpTask ();
#endif
    uint32_t currTime;
    currTime = SystemTickMs;
    uint32_t timeout = 0;

    /*locking SPI Gate resource is only required for B1 board*/
    if( HW_VCU20_B1 == VCU20DetailedHwVer )
    {
        if( 0 == Ex_Base_LockGate(Gate_SPI) )
        {
            timeout = 0;
            FS65_UpdateRegisterContent(IO_INPUT_ADR);	 //通过SBC读取KL15(IO0),WAKEUP1(IO4),WAKEUP2(IO5)的状态
            while((0 != Ex_Base_UnlockGate(Gate_SPI)) || ((timeout++) > 10)) ;
            if( timeout >= 10 )
            {
                FLAG_GateSPI_ERROR = 1;
            }
        }
    }
    else /*for B2, SBC don't share SPI0 with EEPROM, read SBC status directly*/
    {
        FS65_UpdateRegisterContent(IO_INPUT_ADR);	 //通过SBC读取KL15(IO0),WAKEUP1(IO4),WAKEUP2(IO5)的状态
    }
#if 0
    /* IO 采集*/
    if( KACMiddleVoltage_flg == 1 )	//空调中压开关检测，低电平有效，DIN1
    {
        hIOP_AirSwitch_flg = HAL_Get_Digital(0);
    }
    else
    {
        hIOP_AirSwitch_flg = !HAL_Get_Digital(0);
    }
    hIOP_FrontSeatMotorSwitch_flg= !HAL_Get_Digital (1);	//S21 FrontSeatMotor
    hIOP_Crank_flg = HAL_Get_Digital(2);	//delete 点火信号输入  NoUse
    hIOP_GearSwitch1_flg = HAL_Get_Digital(3);	//霍尔信号2 低有效
    hIOP_GearSwitch2_flg = HAL_Get_Digital(4);	//霍尔信号4 低有效
    hIOP_GearSwitch3_flg = HAL_Get_Digital(5);	//霍尔信号3 低有效
    hIOP_GearSwitch4_flg = HAL_Get_Digital(6);	//S平台P档位 K平台S档位，低有效
    hIOP_SeatHall_flg= HAL_Get_Digital (7);	//S21 seat Hall
    hIOP_BrkLightSwitch2_flg = HAL_Get_Digital(10);	//制动信号2，高电平有效
    hIOP_FastChargeAwake_flg = HAL_Get_Digital(13);	//快充口A+(12+)信号采集 高有效
    hIOP_BrkLightSwitch1_flg = HAL_Get_Digital(14);	//制动信号1，数字量输入(高有效)
    hIOP_SlowChargeAwake_flg = HAL_Get_Digital(15);	//慢充口信号采集,高电平有效
    hIOP_RearSeatMotorSwitch_flg= !HAL_Get_Digital (18);	//S21 RearSeatMotor
    HIOP_HandBrake_flg = HAL_Get_Digital(21); //手刹信号--K系列车的
    hIOP_ClutchSwitch1_flg = HAL_Get_Digital(7);  //YK19 离合器信号1
    hIOP_ClutchSwitch2_flg = HAL_Get_Digital(19);  //YK19 离合器信号2
     //if( 0 != C_PMS_En )
     {
         //hIOP_SSB_Switch1_flg = HAL_Get_Digital(23);  //anny
         //hIOP_SSB_Switch2_flg = HAL_Get_Digital(26);  //anny
    //     /*calculate the Feedback voltage the formula is : [Vbat * 19 /(100+19)] = Vfeed so Vbat = Vfeed*119/19*/
    //     hIOP_IGN1_FB_v = HAL_Get_ADC(ADC_AIN20);  //anny
    //     hIOP_IGN2_FB_v = HAL_Get_ADC(ADC_AIN15);  //anny
     }
    /*ADC single transfer*/
    hIOP_FastChargeTemp1_V = HAL_Get_ADC(13);	//AIN3 快充口温度检测1
    hIOP_FastChargeTemp2_V = HAL_Get_ADC(12);	//:AIN4 快充口温度检测2
    hIOP_PCBTemp_V = HAL_Get_ADC(0);		//:AD 5V_SEN1
    hIOP_Sen5V1_V = HAL_Get_ADC(19);	//:内部参考电压，加速踏1板及怀档供电
    hIOP_Sen5V2_V = HAL_Get_ADC(18);	//:内部参考电压，加速踏2板供电
    hIOP_K30_V = HAL_Get_ADC(16) * 11;	//:内部参考电压KL30
    hIOP_AccelPedalH_V = HAL_Get_ADC(17);	//:AIN16 加速踏板
    hIOP_AccelPedalL_V = HAL_Get_ADC(23);	//:AIN19 加速踏板
    hIOP_CruiseKey_V = HAL_Get_ADC(5); /*		Test For Switch	AIN11	pin98	*/

    /*blue tooth key feature is disabled, hIOP_K15_V is controlled by WAKUPKL15*/
     //if( 0 == C_PMS_En )
     {
         if( (WAKEUPKL15 > 0) && (VHALI_PEPS_PDU != 3) )	//通过SBC判断KL15的状态： 高电平是为13，低电平时为0, 当VHALI_PEPS_PDU == 3（远程空调请求),直接通过软件的方式将KL15拉低
         {
             hIOP_K15_V = 13;
         }
         else
         {
             hIOP_K15_V = 0;
         }
     }
     //else
     //{
         //if( VHALO_VCU_PDU == BTK_PDU_START_DRIVE ) /*bug 1699, only set KL_15 in START state*/
         //{
             //hIOP_K15_V = 13;
         //}
         //else
         //{
             //hIOP_K15_V = 0;
         //}
     //}
    /*PWM 采样*/
    hIOP_CollisionSw_Hz = HAL_Get_Finf(F_Collision_CHANNEL) + 0.2f;	//change:DIN13 碰撞信号
    hIOP_CollisionSw_Duty = HAL_Get_FinDuty(F_Collision_CHANNEL);
    hIOP_WaterPwm_Hz = HAL_Get_Finf(F_WaterPump_CHANNEL) + 0.2f;	//change:DIN31 水泵PWM输入
    hIOP_WaterPwm_Duty = HAL_Get_FinDuty(F_WaterPump_CHANNEL);
    hIOP_HVInterlock_Hz = HAL_Get_Finf(F_HVInterlock_CHANNEL) + 0.2f;	//change:DIN28 高压互锁
    hIOP_HVInterlock_PulseTime_us = eMIOS_PWMin_data[F_HVInterlock_CHANNEL].pulsewidth / 5;   //100000/EMIOSCLK; /*转换成us*/
    hIOP_HVInterlock_PeriodTime_us = eMIOS_PWMin_data[F_HVInterlock_CHANNEL].period / 5;  //*100000/EMIOSCLK; /*转换成us*/;
    hIOP_HVInterlock_Duty = (uint8_t)(HAL_Get_FinDuty(F_HVInterlock_CHANNEL));
    hIOP_Fin4_Hz = HAL_Get_Finf(F_VacuumPump_CHANNEL) + 0.2f;
    hIOP_VacuumPumpIn_Duty = (uint8_t)(HAL_Get_FinDuty(F_VacuumPump_CHANNEL));  //change:DIN16 真空泵报警信号
    /*  else  */
    hIOP_McuImportentMsg_Ticks1 = CAN_Get_Tick(3, 7);
    hIOP_McuImportentMsg_Ticks2 = CAN_Get_Tick(3, 8);
    hIOP_BmsImportentMsg_Ticks1 = CAN_Get_Tick(3, 2);
    hIOP_BmsImportentMsg_Ticks3 = CAN_Get_Tick(3, 17);
    hIOP_DCDCImportentMsg_Ticks1 = CAN_Get_Tick(3, 11);
    hIOP_DCDCImportentMsg_Ticks2 = CAN_Get_Tick(3, 12);
    hIOP_VCUCanTickCount = hIOP_McuImportentMsg_Ticks1 + hIOP_McuImportentMsg_Ticks2 + hIOP_BmsImportentMsg_Ticks1
            + hIOP_BmsImportentMsg_Ticks2 + hIOP_BmsImportentMsg_Ticks3 + hIOP_DCDCImportentMsg_Ticks1
            + hIOP_DCDCImportentMsg_Ticks2 + hIOP_ICMImportentMsg_Ticks1;
    VHALO_HWSignal_Time = (unsigned char)(SystemTickMs - currTime);
#endif

	/*add by yjzh for i-project begin*/
	HWin_IgnitionOn_flg = WAKEUPKL15;
    HWin_SSB_Switch1 = HAL_Get_Digital(26);
	HWin_SSB_Switch2 = HAL_Get_Digital(26);
	/*add by yjzh for i-project end*/

    return;
}

void Task_GetSignal_Step2(void)
{
#if 0
    VHALI_ACSwitchActiveIn_flg = hIOP_AirSwitch_flg;
  //VHALI_PTCSwitchActiveIn_flg = hIOP_ACSwitch_flg;
    VHALI_AccelPedalHIn_V = hIOP_AccelPedalH_V;
    VHALI_AccelPedalLIn_V = hIOP_AccelPedalL_V;
    //定速巡航按键识别采用方式
    // if( 1 == Config_output.C_CC_En )	//采用测试方案
    // {
    //     HAL_Get_SwitchKey_Test();
    // }
    // else if( 2 == Config_output.C_CC_En )	//采用默认的S11P01方案
    // {
    //     HAL_Get_SwitchKey_S11P01();
    // }
    // else
    // {
    //     HAL_Get_SwitchKey_None();
    // }
    VHALI_BrkLightSwitch1ActiveIn_flg = hIOP_BrkLightSwitch1_flg;
    VHALI_BrkLightSwitch2ActiveIn_flg = hIOP_BrkLightSwitch2_flg;
    VHALI_FastChargeAwakeActiveIn_flg = hIOP_FastChargeAwake_flg;
    VHALI_FastChargeTemp1In_V = hIOP_FastChargeTemp1_V;
    VHALI_FastChargeTemp2In_V = hIOP_FastChargeTemp2_V;
    VHALI_FastChrgCANAwakeActiveIn_flg = hIOP_1043WKUP_flg;
    VHALI_GearSwitch1ActiveIn_flg = hIOP_GearSwitch1_flg;
    VHALI_GearSwitch2ActiveIn_flg = hIOP_GearSwitch2_flg;
    VHALI_GearSwitch3ActiveIn_flg = hIOP_GearSwitch3_flg;
    VHALI_GearSwitch4ActiveIn_flg = hIOP_GearSwitch4_flg;
    VHALI_LVBattVoltageIn_V = hIOP_K30_V;
    VHALI_LVK15VoltageIn_V = hIOP_K15_V;
    VHALI_LSFaultCodeIn_enum = hIOP_LSFaultCode_enum;
    VHALI_HSFaultCodeIn_enum = hIOP_HSFaultCode_enum;
    VHALI_PCBTempIn_V = hIOP_PCBTemp_V;
    VHALI_Sensor5V1In_V = hIOP_Sen5V1_V;
    VHALI_Sensor5V2In_V = hIOP_Sen5V2_V;
    VHALI_SlowChargeAwakeActiveIn_flg = hIOP_SlowChargeAwake_flg;
    if( (K11P01_Mark == Vehicle_Type) || (Vehicle_Type == K11_Mark) )
    {
        VHALI_HandBrake = !HIOP_HandBrake_flg;	//
    }
    else
    {
        if( VHALI_EPB_Status == 1 )
        {
            VHALI_HandBrake = 0;
        }
        else if( VHALI_EPB_Status == 3 )
        {
            VHALI_HandBrake = 1;
        }
    }
    VHALI_ClutchSwitch1_flg = hIOP_ClutchSwitch1_flg;
    VHALI_ClutchSwitch2_flg = hIOP_ClutchSwitch2_flg;

//PWMin
    if( (hIOP_WaterPwm_Duty <= 0.2) || (hIOP_WaterPwm_Hz == 0) )
    {
        VHALI_WaterPwmIn_Duty = 0xFF;
        VHALI_WaterPwmIn_Hz = 0xFFFF;
    }
    else
    {
        VHALI_WaterPwmIn_Duty = (uint8_t)hIOP_WaterPwm_Duty;
        VHALI_WaterPwmIn_Hz = (uint16_t)hIOP_WaterPwm_Hz;
    }
    if( (hIOP_HVInterlock_Hz <= 0.2) || (hIOP_HVInterlock_Duty == 0) )
    {
        VHALI_HVInterlockFreIn_Hz = 0xFF;
    }
    else
    {
        VHALI_HVInterlockFreIn_Hz = (uint8_t)hIOP_HVInterlock_Hz;
    }
    if( (hIOP_Fin4_Hz <= 0.2) || (hIOP_VacuumPumpIn_Duty == 0) )
    {
        VHALI_VacuumPumpIn_Hz = 0xFFFF;
    }
    else
    {
        VHALI_VacuumPumpIn_Hz = (uint16_t)hIOP_Fin4_Hz;
    }
    if( (hIOP_CollisionSw_Duty <= 0.2) || (hIOP_CollisionSw_Hz == 0) )
    {
        VHALI_CollisionDutyIn_pct = 0xFF;
        VHALI_CollisionFreIn_Hz = 0xFF;
    }
    else
    {
        VHALI_CollisionDutyIn_pct = (uint8_t)hIOP_CollisionSw_Duty;
        VHALI_CollisionFreIn_Hz = (uint8_t)hIOP_CollisionSw_Hz;
    }
     //if( 0 != C_PMS_En )
     {
         //VHALI_SSB_Switch_1 = hIOP_SSB_Switch1_flg;	//anny
         //VHALI_SSB_Switch_2 = hIOP_SSB_Switch2_flg;	//anny
    //     VHALI_IGN1_Out_v = hIOP_IGN1_FB_v * 119 / 19;	//anny
    //     VHALI_IGN2_Out_v = hIOP_IGN2_FB_v * 119 / 19;	//anny
     }
#endif
    return;
}
// boolean_T test_Front_flg=0;
// boolean_T test_Rear_flg=0;

void Task_OutputSignal(void)
{
    hIOP_HSpdFan_flg = VHALO_HSpdFanActive_flg;
    hIOP_HVInterlock_flg = VHALO_HVInterlockActive_flg;
    hIOP_LSpdFan_flg = VHALO_LSpdFanActive_flg;
    hIOP_MCURelay_flg = VHALO_MCURelayActive_flg;
    hIOP_MainRelay_flg = VHALO_MainRelayActive_flg;
    hIOP_PTCRelay_flg = VHALO_PTCRelayActive_flg;
    hIOP_WPTCRelay_flg = VHALO_WPTCRelayActive_flg;
    hIOP_RLight_flg = VHALO_RLight_flg;
    hIOP_WaterPump_flg = VHALO_WaterPumpActive_flg;
    hIOP_WaterPumpPWMDuyt_pct = VHALO_WaterPumpPWMDuty_pct;
    hIOP_LSRelay9_flg = VHALO_ACEnReq_flg;
    // hIOP_Elect2_flg = !(TMM_output.TMM_TMS_Cabin_GVSt);
    hIOP_FrontSeatMotorRelay_flg = VHALO_FrontSeatMotorRelayActive_flg;
    hIOP_RearSeatMotorRelay_flg=VHALO_RearSeatMotorRelayActive_flg;

    hIOP_HSRelay1_flg = (unsigned char)VHALO_BrakeLamp_flg; /*add by zhou yi for brake lamp S11*/
    if( VHALO_InternalSleepActive_flg == 1 )
    {
        prevGW522Tick = VHALI_GW_522_MsgTicks;
        if( KUDS_IOCtrlEnable && IOCtrlDidTbl[2].Enable )
        {
            HAL_Drive_HS(0, IOCtrlDidTbl[2].Status);	//HS2OUT1:制动灯
        }
        else
        {
            HAL_Drive_HS(0, hIOP_HSRelay1_flg);	//HS2OUT1:制动灯
        }
    }
    /*输出PWM； 水泵和高压互锁*/
    HAL_Set_WaterPwm(hIOP_WaterPumpPWM_Hz, hIOP_WaterPumpPWMDuyt_pct); //info  程序中观察一直为高，占空比100%。故可能并未使用。需要查找确认。::水泵PWMO1
    if( hIOP_HVInterlock_flg )
    {
        HAL_Set_LockPwm(hIOP_HVInterlockEn_Hz, 50);	//:高压互锁PWMO2
    }
    else
    {
        HAL_Set_LockPwm(hIOP_HVInterlockEn_Hz, 0);
    }
    /*Zhou Yi 2018-07-09 : if CAN will be stopped, force the relay enter disconnected*/
    if( (CAN_Send_Cmd == 0) && (1 == KHALI_DisRelayWhenCanOff) )
    {
        hIOP_MCURelay_flg = 0;
        hIOP_MainRelay_flg = 0;
    }
    if( KUDS_IOCtrlEnable && IOCtrlDidTbl[1].Enable )
    {
        HAL_Drive_LS(10, IOCtrlDidTbl[1].Status);	//LS2OUT5:MCU供电:59::107
    }
    else
    {
        HAL_Drive_LS(10, hIOP_MCURelay_flg);	//LS2OUT5
    }
    HAL_Drive_LS(11, hIOP_LSpdFan_flg);	//LS2OUT6:低速风扇:58::106
    HAL_Drive_LS(13, hIOP_HSpdFan_flg);	//LS2OUT8:高速风扇:24::98
    HAL_Drive_LS(12, hIOP_WaterPump_flg);	//LS2OUT7:冷却水泵:43::99
    if( (S11P05_Mark == Vehicle_Type) || (S11P01_Mark == Vehicle_Type) || (A11_Mark == Vehicle_Type)
            || (S21_Mark == Vehicle_Type) )
    {
        HAL_Drive_LS(9, hIOP_PTCRelay_flg || hIOP_WPTCRelay_flg);	//LS2OUT4:空气PTC高压接触器:60:113
    }
    else
    {
        HAL_Drive_LS(9, hIOP_PTCRelay_flg);	//LS2OUT4
    }
    if( KUDS_IOCtrlEnable && IOCtrlDidTbl[0].Enable )
    {
        HAL_Drive_LS(8, IOCtrlDidTbl[0].Status);	//LS2OUT3:主继电器:61::112
    }
    else
    {
        HAL_Drive_LS(8, hIOP_MainRelay_flg);	//LS2OUT3
    }
    HAL_Drive_LS(6, hIOP_RLight_flg);	//LS2OUT1:倒车灯继电器低边驱动:81::101
    //HAL_Drive_LS(5,hIOP_Elect1_flg);	//LS1OUT6
    //HAL_Drive_LS(4,hIOP_Elect2_flg);	//LS1OUT5
     //if( 0 != C_PMS_En )  //anny --start
     {
    //     hIOP_IGN1_flg = VHALO_IGN1_Flg;
    //     hIOP_IGN2_flg = VHALO_IGN2_Flg;
    //     HAL_Drive_LS(5, hIOP_IGN1_flg);
    //     HAL_Drive_LS(4, hIOP_IGN2_flg);

         /*drive the SSB LED via GPIO*/
         if( 1 == VHALO_SSB_GreenLed )
         {
             SIUL_SetPad(GPIO_PORTA + 10);
         }
         else
         {
             SIUL_ClearPad(GPIO_PORTA + 10);
         }

         if( 1 == VHALO_SSB_RedLed )
         {
             SIUL_SetPad(GPIO_PORTA + 9);
         }
         else
         {
             SIUL_ClearPad(GPIO_PORTA + 9);
         }  //anny --end
     }
  #if 0
   if((0==hIOP_FrontSeatMotorSwitch_flg)&&(1==hIOP_RearSeatMotorSwitch_flg))
  {
  HAL_Drive_LS (0, 1); //LS1OUT1:座椅电机正转 2 
  HAL_Drive_LS (7, 0); // 1 , 0
  }
  else if((1==hIOP_FrontSeatMotorSwitch_flg)&&(1==hIOP_RearSeatMotorSwitch_flg))
  {
  HAL_Drive_LS (0, 0); 
  HAL_Drive_LS (7, 0);	//座椅停止0, 0
  }
  else if((1==hIOP_FrontSeatMotorSwitch_flg)&&(0==hIOP_RearSeatMotorSwitch_flg))
  {
  HAL_Drive_LS (0, 0);
  HAL_Drive_LS (7, 1);	//LS2OUT2:座椅电机反转 62  0, 1
  }
  else
  {
  HAL_Drive_LS (0, 0);
  HAL_Drive_LS (7, 0);	//座椅停止  0, 0
  }
  #else
 {
//   extern boolean_T TQM_FrontSeatMotor_flg;      /* '<S4>/Switch'
//                                         * TQM座椅前电机控制开关信号
//                                         */
//   extern boolean_T TQM_RearSeatMotor_flg;       /* '<S4>/Switch1'
//                                         * TQM座椅后电机控制开关信号
//                                         */
// if((TQM_FrontSeatMotor_flg==1)||(test_Front_flg==1))
//   {
//     HAL_Drive_LS (0, 1); //LS1OUT1:座椅电机正转 2  1,0
//     HAL_Drive_LS (7, 0);
//   }
// else if((TQM_RearSeatMotor_flg==1)||(test_Rear_flg==1))
//   {
//     HAL_Drive_LS (0, 0);
//     HAL_Drive_LS (7, 1);	//LS2OUT2:座椅电机反转 62  0, 1
//   }
// else
//   {
//     HAL_Drive_LS (0, 0);
//     HAL_Drive_LS (7, 0);	//座椅停止 0,0
//   }
  //HAL_Drive_LS (0, TQM_FrontSeatMotor_flg); //LS1OUT1:座椅电机正转 2
  //HAL_Drive_LS (7, TQM_RearSeatMotor_flg); // 1 , 0
  										
 }

  #endif

    return;
}

void HwTest_OutputSignal(void)
{
    (void)memcpy(&Bios_LS_Output, &Ex_Bios_LS_Output, sizeof(Bios_LS_Output)); /*copy HW test Low side driver output from core 0*/
    (void)memcpy(&Bios_HS_Output, &Ex_Bios_HS_Output, sizeof(Bios_HS_Output)); /*copy HW test High side driver output from core 0*/
    (void)memcpy(&NCV7719_data.CH1_6.R, &Ex_NCV7719_data.CH1_6.R, sizeof(uint16_t)); /*copy HW test H bridge output from core 0*/
    (void)memcpy(&NCV7719_data.CH7_8.R, &Ex_NCV7719_data.CH7_8.R, sizeof(uint16_t)); /*copy HW test H bridge output from core 0*/

    /*CAN communication test*/
    if( ReadyToSend == CanComTest )
    {
        CAN0_TX_Array[0].flag = ReadyToSend;
        CAN1_TX_Array[0].flag = ReadyToSend;
        CAN2_TX_Array[0].flag = ReadyToSend;
    }
    else if( DontSending == CanComTest )
    {
        CAN0_TX_Array[0].flag = DontSending;
        CAN1_TX_Array[0].flag = DontSending;
        CAN2_TX_Array[0].flag = DontSending;
    }
    /*PWM output control  PWM0_CHANNEL */

    my_fs_etpu_pwm_update(PWM0_CHANNEL, udsHWTestPwmCtrl[0].freq, udsHWTestPwmCtrl[0].duty);
    my_fs_etpu_pwm_update(PWM1_CHANNEL, udsHWTestPwmCtrl[1].freq, udsHWTestPwmCtrl[1].duty);
    my_fs_etpu_pwm_update(PWM2_CHANNEL, udsHWTestPwmCtrl[2].freq, udsHWTestPwmCtrl[2].duty);
    my_fs_etpu_pwm_update(PWM3_CHANNEL, udsHWTestPwmCtrl[3].freq, udsHWTestPwmCtrl[3].duty);
    my_fs_etpu_pwm_update(PWM4_CHANNEL, udsHWTestPwmCtrl[4].freq, udsHWTestPwmCtrl[4].duty);
    my_fs_etpu_pwm_update(PWM5_CHANNEL, udsHWTestPwmCtrl[5].freq, udsHWTestPwmCtrl[5].duty);
    my_fs_etpu_pwm_update(PWM6_CHANNEL, udsHWTestPwmCtrl[6].freq, udsHWTestPwmCtrl[6].duty);
    my_fs_etpu_pwm_update(PWM7_CHANNEL, udsHWTestPwmCtrl[7].freq, udsHWTestPwmCtrl[7].duty);
}

/*---------------------------------------------------------------------------
 description:   this function check the  wakup source from BSW view
 1. HW (KL15, DC charge, AC charge ) wake source has higher priority
 2. NM message counter is increasing, the network wakup source is valid
 3. damping should be applied for HW signals
 input param:
 output param: bswWakeSrc
 return value: calculated CRC32
 ---------------------------------------------------------------------------*/
void ChkBswWakeSrc(void)
{
#define INVALID_NETWAKESRC_DELAY  200   /*200ms after power on PMM module can recogonize the wakeup source is unknown , invalid or valid*/
    // if( WAKEUPSRC_UNKNOWN != PMM_output.WakeSrcValid )
    // {
    //     bswWakeSrc = PMM_output.WakeSrcValid;
    // }
    // else
    // {
    //     if( SystemTickMs > INVALID_NETWAKESRC_DELAY )
    //     {
    //         bswWakeSrc = WAKEUPSRC_INVALID; /*force the BSW wakeup source to invalid, then NVM can switch to saved state*/
    //     }
    // }

#undef  INVALID_NETWAKESRC_DELAY
}

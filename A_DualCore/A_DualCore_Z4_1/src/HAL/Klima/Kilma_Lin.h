#ifndef KILMA_LIN_H_
#define KILMA_LIN_H_

#include "stdint.h"

#define Published 1
#define Subscribed 0
typedef union
{
    struct
    {
        uint16_t AQS_Luftguete : 4;            // 空气质量  初始值0xE
        uint16_t AQS_ResponseError : 1;        // 响应错误
        uint16_t AQS_Sensorheizung_Status : 3; // 传感器加热状态
        uint16_t AQS_NoxWert : 10;             // 氮氧化物浓度值
        uint16_t AQS_NoxBereich : 2;           // 氮氧化物浓度范围
        uint16_t AQS_NoxStatus : 4;            // 氮氧化物状态
        uint16_t AQS_COWert : 10;              // 一氧化碳浓度值
        uint16_t AQS_COBereich : 2;            // 一氧化碳浓度范围
        uint16_t AQS_COStatus : 4;             // 一氧化碳状态
        uint16_t AQS_Parameter : 12;           // 参数
        uint16_t AQS_Traffic : 2;              // 通行情况
        uint16_t AQS_Toggle : 2;               // 开关
        uint16_t AQS_HW : 4;                   // 硬件版本
        uint16_t AQS_SW : 4;                   // 软件版本
    } AQSs_01;
    struct
    {
        uint8_t BLOWER1_STATUS1 : 6;       // Blower 1状态1
        uint8_t BLOWER1_ResponseError : 1; // Blower 1响应错误
        uint8_t ST_VLD_BLW_CTRL_1_LIN : 1; // Blower 1电压状态
        uint8_t BLOWER1_STATUS2 : 8;       // Blower 1状态2
        uint16_t BLOWER1_IBATT : 8;        // Blower 1电池电流
        uint16_t BLOWER1_UMOTOR : 8;       // Blower 1电机电压
        uint16_t BLOWER1_TEMPERATURE : 8;  // Blower 1温度
        uint16_t BLOWER1_UBATT : 8;        // Blower 1电池电压
        uint16_t BLOWER1_SUPPLIER : 8;     // Blower 1供应商
        uint8_t BLOWER1_SW : 4;            // Blower 1软件版本号
        uint8_t BLOWER1_HW : 4;            // Blower 1硬件版本号
    } BLOWER1;
    struct
    {
        uint16_t DS_Kaeltemittel_P : 11; // DS的冷媒压力 初始值0x7FE
        uint16_t reserved : 9;           // 占位
        uint8_t DS_DruckError : 1;       // DS的压力错误
        uint8_t DS_TempError : 1;        // DS的温度错误
        uint8_t DS_ChecksumError : 1;    // DS的校验和错误
        uint8_t DS_BitError : 1;         // DS的位错误
        uint8_t DS_HW : 4;               // DS的硬件版本号
        uint8_t DS_SW : 4;               // DS的软件版本号

    } DS;
    struct
    {
        uint64_t DTS1_Kaeltemittel_p : 12;   // pT传感器1制冷剂压力 初始值0xFFE
        uint64_t DTS1_Kaeltemittel_T : 12;   // pT传感器1制冷剂温度 初始值0xFFE
        uint64_t DTS1_interne_Sensor_T : 12; // pT传感器1内部温度   初始值0xFFE
        uint64_t DTS1_Fehler : 1;            // pT传感器1出现错误
        uint64_t DTS1_Kommunikation : 1;     // pT传感器1通信
        uint64_t DTS1_ResponseError : 1;     // pT传感器1响应错误
        uint64_t DTS1_TNCTOC : 1;            // pT传感器1 TNCTOC
    } DTS1;
    struct
    {
        uint64_t EKK3_STATE_HV : 3;               // 电机高压状态
        uint64_t EKK3_STATE_INV_ABN : 1;          // 电机反转异常状态
        uint64_t EKK3_STATE_INTERNAL : 3;         // 内部状态
        uint64_t EKK3_STATE_INV_ABN_TNCTOC : 1;   // 反转异常状态
        uint64_t EKK3_STATE_RPM_SENS_1 : 3;       // 电机转速传感器1状态
        uint64_t EKK3_STATE_RPM_SENS_2 : 3;       // 电机转速传感器2状态
        uint64_t EKK3_ErrMem_STATE : 2;           // 错误存储状态
        uint64_t EKK3_ParameterChange : 1;        // 参数更改
        uint64_t EKK3_ResponseError : 1;          // 响应错误
        uint64_t EKK3_STATE_CURR_SEN_CIRCUIT : 3; // 电机电流传感器电路状态
        uint64_t EKK3_COMP_ST : 3;                // 控制器状态
        uint64_t EKK3_STATE_HV_Ref : 3;           // 高压电压参考状态
        uint64_t EKK3_STATE_INV_TEMP : 3;         // 反转器温度状态
        uint64_t EKK3_STATE_LV : 2;               // 低电压状态
        uint64_t EKK3_COMP_SPEED : 8;             // 控制器速度
        uint64_t EKK3_INPUT_CURRENT : 8;          // 输入电流
        uint64_t EKK3_INV_TEMP : 8;               // 反转器温度
        uint64_t EKK3_HIGH_VOLTAGE : 8;           // 高电压
    } EKK3_t;
    struct
    {
        uint64_t EKK4_MUX_Err_Ind : 2;           // 错误指示器的复用
        uint64_t EKK4_Err_Ind_Nr_1_8_15_22 : 2;  // 错误指示器编号 1，8，15，22
        uint64_t EKK4_Err_Ind_Nr_2_9_16_23 : 2;  // 错误指示器编号 2，9，16，23
        uint64_t EKK4_Err_Ind_Nr_3_10_17_24 : 2; // 错误指示器编号 3，10，17，24
        uint64_t EKK4_Err_Ind_Nr_4_11_18_25 : 2; // 错误指示器编号 4，11，18，25
        uint64_t EKK4_Err_Ind_Nr_5_12_19_26 : 2; // 错误指示器编号 5，12，19，26
        uint64_t EKK4_Err_Ind_Nr_6_13_20_27 : 2; // 错误指示器编号 6，13，20，27
        uint64_t EKK4_Err_Ind_Nr_7_14_21_28 : 2; // 错误指示器编号 7，14，21，28
        uint64_t EKK4_INV_TEMP : 8;              // 逆变器温度
        uint64_t EKK4_INPUT_CURRENT : 8;         // 输入电流
        uint64_t EKK4_HIGH_VOLTAGE : 12;         // 高压
        uint64_t EKK4_Match : 2;                 // 匹配
        uint64_t EKK4_TF_Change : 1;             // 变压器温度变化
        uint64_t EKK4_ResponseError : 1;         // 响应错误
        uint64_t EKK4_COMP_SPEED : 10;           // 计算速度
        uint64_t EKK4_ErrMem_State : 2;          // 错误存储器状态
        uint64_t EKK4_ParameterChange : 1;       // 参数更改
        uint64_t EKK4_COMP_ST : 3;               // 计算状态
    } EKK4_01;
    struct
    {
        uint64_t EKK4_Level_Rsp : 4;              // 四位的EKK4级别响应信号
        uint64_t EKK4_Number_of_Err_Ind_TF : 4;   // 三位的EKK4故障指示信号数量
        uint64_t EKK4_Reason_Err_Ind_TF_1_7 : 3;  // 五位的EKK4故障指示信号1-7原因码
        uint64_t EKK4_Err_Ind_TF_1_7 : 5;         // 三位的EKK4故障指示信号1-7
        uint64_t EKK4_Reason_Err_Ind_TF_2_8 : 3;  // 五位的EKK4故障指示信号2-8原因码
        uint64_t EKK4_Err_Ind_TF_2_8 : 5;         // 三位的EKK4故障指示信号2-8
        uint64_t EKK4_Reason_Err_Ind_TF_3_9 : 3;  // 五位的EKK4故障指示信号3-9原因码
        uint64_t EKK4_Err_Ind_TF_3_9 : 5;         // 三位的EKK4故障指示信号3-9
        uint64_t EKK4_Reason_Err_Ind_TF_4_10 : 3; // 五位的EKK4故障指示信号4-10原因码
        uint64_t EKK4_Err_Ind_TF_4_10 : 5;        // 三位的EKK4故障指示信号4-10
        uint64_t EKK4_Reason_Err_Ind_TF_5_11 : 3; // 五位的EKK4故障指示信号5-11原因码
        uint64_t EKK4_Err_Ind_TF_5_11 : 5;        // 三位的EKK4故障指示信号5-11
        uint64_t EKK4_Reason_Err_Ind_TF_6_12 : 3; // 五位的EKK4故障指示信号6-12原因码
        uint64_t EKK4_Err_Ind_TF_6_12 : 5;        // 三位的EKK4故障指示信号6-12
        uint64_t EKK4_Comp_Error_Mask_Nr : 8;     // 四位的EKK4压缩错误掩码号
    } EKK4_02;

    struct
    {
        uint64_t EKK_HV_ERR : 2;        // 高压故障
        uint64_t EKK_O_LINE_ERR : 2;    // O线故障
        uint64_t EKK_INV_OL : 1;        // 逆变器超过O线最大值
        uint64_t EKK_INV_ABN : 1;       // 逆变器异常
        uint64_t EKK_LMT_OP : 1;        // 限制输出功率
        uint64_t EKK_INV_COMM_ERR : 1;  // 逆变器通信故障
        uint64_t EKK_INV_HI_TEMP : 2;   // 逆变器高温故障
        uint64_t EKK_INV_LO_TEMP : 1;   // 逆变器低温故障
        uint64_t EKK_INV_SPD_ABN : 4;   // 逆变器速度异常
        uint64_t EKK_ST_Invalid : 1;    // 逆变器无效状态
        uint64_t EKK_GW_COMM_ERR : 1;   // 网关通信故障
        uint64_t EKK_LV_ERR : 1;        // 低电压故障
        uint64_t EKK_Reserviert1 : 1;   // 保留位
        uint64_t EKK_ResponseError : 1; // 响应错误
        uint64_t EKK_COMP_ST : 3;       // 压缩机状态
        uint64_t EKK_COMP_SPEED : 8;    // 压缩机转速
        uint64_t EKK_INPUT_CURRENT : 8; // 输入电流
        uint64_t EKK_PWR_CONS : 8;      // 功率消耗
        uint64_t EKK_INV_TEMP : 8;      // 逆变器温度
        uint64_t EKK_HIGH_VOLTAGE : 8;  // 高电压值
    } EKKs_1;

    struct
    {
        uint64_t FSA_Taupunkt : 10;            // FSA的露点温度
        uint64_t reserved : 5;                 // 保留位
        uint64_t FSA_ResponseError : 1;        // FSA的响应错误
        uint64_t FSA_Temp_Luft : 10;           // FSA的空气温度
        uint64_t reserved1 : 6;                // 保留位
        uint64_t FSA_Luftfeuchte_rel : 8;      // FSA的相对湿度
        uint64_t FSA_HW : 4;                   // FSA的硬件版本
        uint64_t FSA_SW : 4;                   // FSA的软件版本
        uint64_t FSA_Temp_Sensor : 11;         // FSA的传感器温度
        uint64_t FSA_Sensorheizung_Status : 1; // FSA的传感器加热器状态
    } FSAs_1;

    struct
    {
        uint64_t PTC_HV_I_ist : 8;                     // PTC高压电流实际值
        uint64_t PTC_HV_ERR : 8;                       // PTC高压错误
        uint64_t PTC_HV_Status_PTC : 3;                // PTC高压状态
        uint64_t PTC_Status_UBatt : 1;                 // 电池电压状态
        uint64_t PTC_ResponseError : 1;                // 响应错误
        uint64_t PTC_TimeOut_Fehler : 1;               // 超时错误
        uint64_t PTC_HV_Err_Heizkreis_1 : 1;           // PTC高压加热电路1错误
        uint64_t PTC_HV_Err_Heizkreis_2 : 1;           // PTC高压加热电路2错误
        uint64_t PTC_HV_Err_Heizkreis_3 : 1;           // PTC高压加热电路3错误
        uint64_t PTC_HV_Err_Leckagestrom : 1;          // PTC高压泄漏电流错误
        uint64_t PTC_HV_Err_Ueberstromabschaltung : 1; // PTC高压过流保护错误
        uint64_t PTC_HV_Err_Temperaturschutz : 1;      // PTC高压温度保护错误
        uint64_t PTC_HV_Err_intern : 1;                // PTC高压内部错误
        uint64_t PTC_UBatt : 8;                        // 电池电压值
        uint64_t PTC_Temp_PCB : 8;                     // PCB温度值
        uint64_t PTC_HV_Heizmedium_Sensor_1 : 8;       // PTC高压加热介质传感器1值
        uint64_t PTC_HV_Heizmedium_Sensor_2 : 8;       // PTC高压加热介质传感器2值
    } HV_Hs_01;

    struct
    {
        uint64_t Aussentemp_ungef : 8;     // 外部温度（近似值），8比特
        uint64_t ESP_v_Signal_8Bit : 8;    // ESP车速信号（8位），8比特
        uint64_t Umluft : 4;               // 内循环，4比特
        uint64_t Geblaesestufe : 4;        // 风扇级别，4比特
        uint64_t Navigationsattribute : 4; // 导航属性，4比特
        uint64_t Empfindlichkeit_AQS : 3;  // AQS灵敏度，3比特
        uint64_t KompressorModus : 1;      // 压缩机模式，1比特
        uint64_t Scheibenreinigung : 1;    // 雨刷控制，1比特
        uint64_t AQS_Sensorheizung : 1;    // 车内空气质量？？，1比特
        uint8_t : 6;                       // 空
        uint8_t : 8;
    } AQSe_01;

    struct
    {
        uint64_t BLOWER1_RX_FREQUENCY : 12;       // BLOWER1接收频率
        uint64_t : 4;                             // 保留位
        uint64_t BLOWER1_SELECT : 2;              // BLOWER1选择
        uint64_t BLOWER1_IMAX_MAX : 6;            // BLOWER1最大电流值
        uint64_t BLOWER1_IMAX_MIN : 5;            // BLOWER1最小电流值
        uint64_t BLOWER1_U_KNEE : 3;              // BLOWER1拐点电压
        uint64_t BLOWER1_SAFETYRUN_THRESHOLD : 4; // BLOWER1安全运行阈值
        uint64_t BLOWER1_RAMP : 4;                // BLOWER1变速斜率
        uint64_t BLOWER1_SPEED : 8;               // BLOWER1速度
        uint64_t BLOWER1_SAFETY_SPEED : 8;        // BLOWER1安全速度
        uint64_t : 8;
    } BLOWER1_SET;

    struct
    {
        uint64_t EKK_REQ_COMP_SPEED : 8;        // EKK压缩机请求速度   偏移量:0，缩放因子:50
        uint64_t EKK_ENB_COMP : 2;              // EKK启用压缩机
        uint64_t EKK_HV_ST : 2;                 // EKK高压状态
        uint64_t EKK_KL_15_Status : 2;          // EKK电源状态
        uint64_t EKKe_Q_Mask : 1;               // EKK质量标记
        uint64_t EKKe_Level_REQ : 1;            // EKK请求等级
        uint64_t EKKe_Error_Mask_Nr : 8;        // EKK错误掩码编号
        uint64_t EKK_REQ_COMP_SPEED_HiRes : 10; // EKK请求的高精度压缩机速度  偏移量:0，缩放因子:15
        uint64_t : 10;
    } EKKe_01;

    struct
    {
        uint32_t KL_HV_PTC_soll : 8; // HV PTC 目标设定值
        uint32_t KL_PTC_ein : 1;     // PTC 启用控制信号
        uint64_t : 10;
    } Hv_He_01;

    struct
    {
        uint8_t ISOALLReqB0; // ISO所有请求字节0
        uint8_t ISOALLReqB1; // ISO所有请求字节1
        uint8_t ISOALLReqB2; // ISO所有请求字节2
        uint8_t ISOALLReqB3; // ISO所有请求字节3
        uint8_t ISOALLReqB4; // ISO所有请求字节4
        uint8_t ISOALLReqB5; // ISO所有请求字节5
        uint8_t ISOALLReqB6; // ISO所有请求字节6
        uint8_t ISOALLReqB7; // ISO所有请求字节7
    } ISO_Funktionaler_Req_All;
    struct
    {
        uint8_t b0;
        uint8_t b1;
        uint8_t b2;
        uint8_t b3;
        uint8_t b4;
        uint8_t b5;
        uint8_t b6;
        uint8_t b7;
    } DiagnosticFrame_MasterReq_t;

    struct
    {
        uint8_t b0;
        uint8_t b1;
        uint8_t b2;
        uint8_t b3;
        uint8_t b4;
        uint8_t b5;
        uint8_t b6;
        uint8_t b7;
    } DiagnosticFrame_SlaveResp_t;

    uint64_t raw;
    uint32_t rwa1[2];
    uint16_t raw2[4];
    uint8_t raw3[8];
} Lin_Frame_Data;

/**
 * @brief 结构体 Frame 描述了 LIN 总线通信中的一个帧。
 */
typedef struct
{
    Lin_Frame_Data frame1; /**< 帧的具体内容 */
    uint8_t Frame_id;      /**< 发送的帧 ID，PID */
    uint8_t Send_Flag;     /**< 发送标志：1 表示发送，0 表示接收 */
} Frame;

typedef struct
{
    /* data */
    Frame AQSe_01;                  // 空气质量传感器数据帧
    Frame BLOWER1_SET;              // 风扇设置数据帧
    Frame EKKe_01;                  // 电控压缩机数据帧
    Frame HV_He_01;                 // 高压加热器数据帧
    Frame ISO_Funktionaler_Req_All; // ISO功能请求数据帧

    // 订阅的数据帧
    Frame AQSs_01;        // 空气质量传感器状态数据帧
    Frame BLOWER1_STATUS; // 风扇状态数据帧
    Frame DSs_01;         // 德国风扇控制器状态数据帧
    Frame DTSs_01;        // 德国温度控制器状态数据帧
    Frame EKK3s_01;       // 电控压缩机状态数据帧
    Frame EKK4s_01;       // 电控压缩机状态数据帧
    Frame EKK4s_02;       // 电控压缩机状态数据帧
    Frame EKKs_01;        // 电控压缩机状态数据帧
    Frame FSAs_01;        // 前风窗玻璃加热器状态数据帧
    Frame HV_Hs_01;       // 高压加热器的状态

    Frame MasterReq;
    Frame SlaveResp;
} Kilma_Lin;

typedef struct
{
    Frame *Tasks;
    int delay_time_ms;
} ScheduleTableEntry;

typedef struct
{
    ScheduleTableEntry st_main[16];                /**< 主调度表 */
    ScheduleTableEntry st_main_nar[16];            /**< 窄带主调度表 */
    ScheduleTableEntry st_main_rdw_nar[16];        /**< 窄带主调度表2 */
    ScheduleTableEntry st_main_OBD[16];            /**< OBD 主调度表 */
    ScheduleTableEntry st_main2[16];               /**< 主调度表2 */
    ScheduleTableEntry st_EKK_Fehler[1];           /**< EKK 错误调度表 */
    ScheduleTableEntry DiagRequest[1];             /**< 诊断请求调度表 */
    ScheduleTableEntry DiagResponse[1];            /**< 诊断响应调度表 */
    ScheduleTableEntry DiagFunktionalerRequest[1]; /**< 功能诊断请求调度表 */
} ScheduleTable;


void Kilma_Lin_Init (void);
void Schedule_tables_Send (void);
#endif // !KILMA_LIN_H_

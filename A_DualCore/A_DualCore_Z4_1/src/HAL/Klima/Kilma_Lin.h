#ifndef KILMA_LIN_H_
#define KILMA_LIN_H_

#include "stdint.h"

#define Published 1
#define Subscribed 0
typedef union
{
    struct
    {
        uint16_t AQS_Luftguete : 4;            // ��������  ��ʼֵ0xE
        uint16_t AQS_ResponseError : 1;        // ��Ӧ����
        uint16_t AQS_Sensorheizung_Status : 3; // ����������״̬
        uint16_t AQS_NoxWert : 10;             // ��������Ũ��ֵ
        uint16_t AQS_NoxBereich : 2;           // ��������Ũ�ȷ�Χ
        uint16_t AQS_NoxStatus : 4;            // ��������״̬
        uint16_t AQS_COWert : 10;              // һ����̼Ũ��ֵ
        uint16_t AQS_COBereich : 2;            // һ����̼Ũ�ȷ�Χ
        uint16_t AQS_COStatus : 4;             // һ����̼״̬
        uint16_t AQS_Parameter : 12;           // ����
        uint16_t AQS_Traffic : 2;              // ͨ�����
        uint16_t AQS_Toggle : 2;               // ����
        uint16_t AQS_HW : 4;                   // Ӳ���汾
        uint16_t AQS_SW : 4;                   // ����汾
    } AQSs_01;
    struct
    {
        uint8_t BLOWER1_STATUS1 : 6;       // Blower 1״̬1
        uint8_t BLOWER1_ResponseError : 1; // Blower 1��Ӧ����
        uint8_t ST_VLD_BLW_CTRL_1_LIN : 1; // Blower 1��ѹ״̬
        uint8_t BLOWER1_STATUS2 : 8;       // Blower 1״̬2
        uint16_t BLOWER1_IBATT : 8;        // Blower 1��ص���
        uint16_t BLOWER1_UMOTOR : 8;       // Blower 1�����ѹ
        uint16_t BLOWER1_TEMPERATURE : 8;  // Blower 1�¶�
        uint16_t BLOWER1_UBATT : 8;        // Blower 1��ص�ѹ
        uint16_t BLOWER1_SUPPLIER : 8;     // Blower 1��Ӧ��
        uint8_t BLOWER1_SW : 4;            // Blower 1����汾��
        uint8_t BLOWER1_HW : 4;            // Blower 1Ӳ���汾��
    } BLOWER1;
    struct
    {
        uint16_t DS_Kaeltemittel_P : 11; // DS����ýѹ�� ��ʼֵ0x7FE
        uint16_t reserved : 9;           // ռλ
        uint8_t DS_DruckError : 1;       // DS��ѹ������
        uint8_t DS_TempError : 1;        // DS���¶ȴ���
        uint8_t DS_ChecksumError : 1;    // DS��У��ʹ���
        uint8_t DS_BitError : 1;         // DS��λ����
        uint8_t DS_HW : 4;               // DS��Ӳ���汾��
        uint8_t DS_SW : 4;               // DS������汾��

    } DS;
    struct
    {
        uint64_t DTS1_Kaeltemittel_p : 12;   // pT������1�����ѹ�� ��ʼֵ0xFFE
        uint64_t DTS1_Kaeltemittel_T : 12;   // pT������1������¶� ��ʼֵ0xFFE
        uint64_t DTS1_interne_Sensor_T : 12; // pT������1�ڲ��¶�   ��ʼֵ0xFFE
        uint64_t DTS1_Fehler : 1;            // pT������1���ִ���
        uint64_t DTS1_Kommunikation : 1;     // pT������1ͨ��
        uint64_t DTS1_ResponseError : 1;     // pT������1��Ӧ����
        uint64_t DTS1_TNCTOC : 1;            // pT������1 TNCTOC
    } DTS1;
    struct
    {
        uint64_t EKK3_STATE_HV : 3;               // �����ѹ״̬
        uint64_t EKK3_STATE_INV_ABN : 1;          // �����ת�쳣״̬
        uint64_t EKK3_STATE_INTERNAL : 3;         // �ڲ�״̬
        uint64_t EKK3_STATE_INV_ABN_TNCTOC : 1;   // ��ת�쳣״̬
        uint64_t EKK3_STATE_RPM_SENS_1 : 3;       // ���ת�ٴ�����1״̬
        uint64_t EKK3_STATE_RPM_SENS_2 : 3;       // ���ת�ٴ�����2״̬
        uint64_t EKK3_ErrMem_STATE : 2;           // ����洢״̬
        uint64_t EKK3_ParameterChange : 1;        // ��������
        uint64_t EKK3_ResponseError : 1;          // ��Ӧ����
        uint64_t EKK3_STATE_CURR_SEN_CIRCUIT : 3; // ���������������·״̬
        uint64_t EKK3_COMP_ST : 3;                // ������״̬
        uint64_t EKK3_STATE_HV_Ref : 3;           // ��ѹ��ѹ�ο�״̬
        uint64_t EKK3_STATE_INV_TEMP : 3;         // ��ת���¶�״̬
        uint64_t EKK3_STATE_LV : 2;               // �͵�ѹ״̬
        uint64_t EKK3_COMP_SPEED : 8;             // �������ٶ�
        uint64_t EKK3_INPUT_CURRENT : 8;          // �������
        uint64_t EKK3_INV_TEMP : 8;               // ��ת���¶�
        uint64_t EKK3_HIGH_VOLTAGE : 8;           // �ߵ�ѹ
    } EKK3_t;
    struct
    {
        uint64_t EKK4_MUX_Err_Ind : 2;           // ����ָʾ���ĸ���
        uint64_t EKK4_Err_Ind_Nr_1_8_15_22 : 2;  // ����ָʾ����� 1��8��15��22
        uint64_t EKK4_Err_Ind_Nr_2_9_16_23 : 2;  // ����ָʾ����� 2��9��16��23
        uint64_t EKK4_Err_Ind_Nr_3_10_17_24 : 2; // ����ָʾ����� 3��10��17��24
        uint64_t EKK4_Err_Ind_Nr_4_11_18_25 : 2; // ����ָʾ����� 4��11��18��25
        uint64_t EKK4_Err_Ind_Nr_5_12_19_26 : 2; // ����ָʾ����� 5��12��19��26
        uint64_t EKK4_Err_Ind_Nr_6_13_20_27 : 2; // ����ָʾ����� 6��13��20��27
        uint64_t EKK4_Err_Ind_Nr_7_14_21_28 : 2; // ����ָʾ����� 7��14��21��28
        uint64_t EKK4_INV_TEMP : 8;              // ������¶�
        uint64_t EKK4_INPUT_CURRENT : 8;         // �������
        uint64_t EKK4_HIGH_VOLTAGE : 12;         // ��ѹ
        uint64_t EKK4_Match : 2;                 // ƥ��
        uint64_t EKK4_TF_Change : 1;             // ��ѹ���¶ȱ仯
        uint64_t EKK4_ResponseError : 1;         // ��Ӧ����
        uint64_t EKK4_COMP_SPEED : 10;           // �����ٶ�
        uint64_t EKK4_ErrMem_State : 2;          // ����洢��״̬
        uint64_t EKK4_ParameterChange : 1;       // ��������
        uint64_t EKK4_COMP_ST : 3;               // ����״̬
    } EKK4_01;
    struct
    {
        uint64_t EKK4_Level_Rsp : 4;              // ��λ��EKK4������Ӧ�ź�
        uint64_t EKK4_Number_of_Err_Ind_TF : 4;   // ��λ��EKK4����ָʾ�ź�����
        uint64_t EKK4_Reason_Err_Ind_TF_1_7 : 3;  // ��λ��EKK4����ָʾ�ź�1-7ԭ����
        uint64_t EKK4_Err_Ind_TF_1_7 : 5;         // ��λ��EKK4����ָʾ�ź�1-7
        uint64_t EKK4_Reason_Err_Ind_TF_2_8 : 3;  // ��λ��EKK4����ָʾ�ź�2-8ԭ����
        uint64_t EKK4_Err_Ind_TF_2_8 : 5;         // ��λ��EKK4����ָʾ�ź�2-8
        uint64_t EKK4_Reason_Err_Ind_TF_3_9 : 3;  // ��λ��EKK4����ָʾ�ź�3-9ԭ����
        uint64_t EKK4_Err_Ind_TF_3_9 : 5;         // ��λ��EKK4����ָʾ�ź�3-9
        uint64_t EKK4_Reason_Err_Ind_TF_4_10 : 3; // ��λ��EKK4����ָʾ�ź�4-10ԭ����
        uint64_t EKK4_Err_Ind_TF_4_10 : 5;        // ��λ��EKK4����ָʾ�ź�4-10
        uint64_t EKK4_Reason_Err_Ind_TF_5_11 : 3; // ��λ��EKK4����ָʾ�ź�5-11ԭ����
        uint64_t EKK4_Err_Ind_TF_5_11 : 5;        // ��λ��EKK4����ָʾ�ź�5-11
        uint64_t EKK4_Reason_Err_Ind_TF_6_12 : 3; // ��λ��EKK4����ָʾ�ź�6-12ԭ����
        uint64_t EKK4_Err_Ind_TF_6_12 : 5;        // ��λ��EKK4����ָʾ�ź�6-12
        uint64_t EKK4_Comp_Error_Mask_Nr : 8;     // ��λ��EKK4ѹ�����������
    } EKK4_02;

    struct
    {
        uint64_t EKK_HV_ERR : 2;        // ��ѹ����
        uint64_t EKK_O_LINE_ERR : 2;    // O�߹���
        uint64_t EKK_INV_OL : 1;        // ���������O�����ֵ
        uint64_t EKK_INV_ABN : 1;       // ������쳣
        uint64_t EKK_LMT_OP : 1;        // �����������
        uint64_t EKK_INV_COMM_ERR : 1;  // �����ͨ�Ź���
        uint64_t EKK_INV_HI_TEMP : 2;   // ��������¹���
        uint64_t EKK_INV_LO_TEMP : 1;   // ��������¹���
        uint64_t EKK_INV_SPD_ABN : 4;   // ������ٶ��쳣
        uint64_t EKK_ST_Invalid : 1;    // �������Ч״̬
        uint64_t EKK_GW_COMM_ERR : 1;   // ����ͨ�Ź���
        uint64_t EKK_LV_ERR : 1;        // �͵�ѹ����
        uint64_t EKK_Reserviert1 : 1;   // ����λ
        uint64_t EKK_ResponseError : 1; // ��Ӧ����
        uint64_t EKK_COMP_ST : 3;       // ѹ����״̬
        uint64_t EKK_COMP_SPEED : 8;    // ѹ����ת��
        uint64_t EKK_INPUT_CURRENT : 8; // �������
        uint64_t EKK_PWR_CONS : 8;      // ��������
        uint64_t EKK_INV_TEMP : 8;      // ������¶�
        uint64_t EKK_HIGH_VOLTAGE : 8;  // �ߵ�ѹֵ
    } EKKs_1;

    struct
    {
        uint64_t FSA_Taupunkt : 10;            // FSA��¶���¶�
        uint64_t reserved : 5;                 // ����λ
        uint64_t FSA_ResponseError : 1;        // FSA����Ӧ����
        uint64_t FSA_Temp_Luft : 10;           // FSA�Ŀ����¶�
        uint64_t reserved1 : 6;                // ����λ
        uint64_t FSA_Luftfeuchte_rel : 8;      // FSA�����ʪ��
        uint64_t FSA_HW : 4;                   // FSA��Ӳ���汾
        uint64_t FSA_SW : 4;                   // FSA������汾
        uint64_t FSA_Temp_Sensor : 11;         // FSA�Ĵ������¶�
        uint64_t FSA_Sensorheizung_Status : 1; // FSA�Ĵ�����������״̬
    } FSAs_1;

    struct
    {
        uint64_t PTC_HV_I_ist : 8;                     // PTC��ѹ����ʵ��ֵ
        uint64_t PTC_HV_ERR : 8;                       // PTC��ѹ����
        uint64_t PTC_HV_Status_PTC : 3;                // PTC��ѹ״̬
        uint64_t PTC_Status_UBatt : 1;                 // ��ص�ѹ״̬
        uint64_t PTC_ResponseError : 1;                // ��Ӧ����
        uint64_t PTC_TimeOut_Fehler : 1;               // ��ʱ����
        uint64_t PTC_HV_Err_Heizkreis_1 : 1;           // PTC��ѹ���ȵ�·1����
        uint64_t PTC_HV_Err_Heizkreis_2 : 1;           // PTC��ѹ���ȵ�·2����
        uint64_t PTC_HV_Err_Heizkreis_3 : 1;           // PTC��ѹ���ȵ�·3����
        uint64_t PTC_HV_Err_Leckagestrom : 1;          // PTC��ѹй©��������
        uint64_t PTC_HV_Err_Ueberstromabschaltung : 1; // PTC��ѹ������������
        uint64_t PTC_HV_Err_Temperaturschutz : 1;      // PTC��ѹ�¶ȱ�������
        uint64_t PTC_HV_Err_intern : 1;                // PTC��ѹ�ڲ�����
        uint64_t PTC_UBatt : 8;                        // ��ص�ѹֵ
        uint64_t PTC_Temp_PCB : 8;                     // PCB�¶�ֵ
        uint64_t PTC_HV_Heizmedium_Sensor_1 : 8;       // PTC��ѹ���Ƚ��ʴ�����1ֵ
        uint64_t PTC_HV_Heizmedium_Sensor_2 : 8;       // PTC��ѹ���Ƚ��ʴ�����2ֵ
    } HV_Hs_01;

    struct
    {
        uint64_t Aussentemp_ungef : 8;     // �ⲿ�¶ȣ�����ֵ����8����
        uint64_t ESP_v_Signal_8Bit : 8;    // ESP�����źţ�8λ����8����
        uint64_t Umluft : 4;               // ��ѭ����4����
        uint64_t Geblaesestufe : 4;        // ���ȼ���4����
        uint64_t Navigationsattribute : 4; // �������ԣ�4����
        uint64_t Empfindlichkeit_AQS : 3;  // AQS�����ȣ�3����
        uint64_t KompressorModus : 1;      // ѹ����ģʽ��1����
        uint64_t Scheibenreinigung : 1;    // ��ˢ���ƣ�1����
        uint64_t AQS_Sensorheizung : 1;    // ���ڿ�������������1����
        uint8_t : 6;                       // ��
        uint8_t : 8;
    } AQSe_01;

    struct
    {
        uint64_t BLOWER1_RX_FREQUENCY : 12;       // BLOWER1����Ƶ��
        uint64_t : 4;                             // ����λ
        uint64_t BLOWER1_SELECT : 2;              // BLOWER1ѡ��
        uint64_t BLOWER1_IMAX_MAX : 6;            // BLOWER1������ֵ
        uint64_t BLOWER1_IMAX_MIN : 5;            // BLOWER1��С����ֵ
        uint64_t BLOWER1_U_KNEE : 3;              // BLOWER1�յ��ѹ
        uint64_t BLOWER1_SAFETYRUN_THRESHOLD : 4; // BLOWER1��ȫ������ֵ
        uint64_t BLOWER1_RAMP : 4;                // BLOWER1����б��
        uint64_t BLOWER1_SPEED : 8;               // BLOWER1�ٶ�
        uint64_t BLOWER1_SAFETY_SPEED : 8;        // BLOWER1��ȫ�ٶ�
        uint64_t : 8;
    } BLOWER1_SET;

    struct
    {
        uint64_t EKK_REQ_COMP_SPEED : 8;        // EKKѹ���������ٶ�   ƫ����:0����������:50
        uint64_t EKK_ENB_COMP : 2;              // EKK����ѹ����
        uint64_t EKK_HV_ST : 2;                 // EKK��ѹ״̬
        uint64_t EKK_KL_15_Status : 2;          // EKK��Դ״̬
        uint64_t EKKe_Q_Mask : 1;               // EKK�������
        uint64_t EKKe_Level_REQ : 1;            // EKK����ȼ�
        uint64_t EKKe_Error_Mask_Nr : 8;        // EKK����������
        uint64_t EKK_REQ_COMP_SPEED_HiRes : 10; // EKK����ĸ߾���ѹ�����ٶ�  ƫ����:0����������:15
        uint64_t : 10;
    } EKKe_01;

    struct
    {
        uint32_t KL_HV_PTC_soll : 8; // HV PTC Ŀ���趨ֵ
        uint32_t KL_PTC_ein : 1;     // PTC ���ÿ����ź�
        uint64_t : 10;
    } Hv_He_01;

    struct
    {
        uint8_t ISOALLReqB0; // ISO���������ֽ�0
        uint8_t ISOALLReqB1; // ISO���������ֽ�1
        uint8_t ISOALLReqB2; // ISO���������ֽ�2
        uint8_t ISOALLReqB3; // ISO���������ֽ�3
        uint8_t ISOALLReqB4; // ISO���������ֽ�4
        uint8_t ISOALLReqB5; // ISO���������ֽ�5
        uint8_t ISOALLReqB6; // ISO���������ֽ�6
        uint8_t ISOALLReqB7; // ISO���������ֽ�7
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
 * @brief �ṹ�� Frame ������ LIN ����ͨ���е�һ��֡��
 */
typedef struct
{
    Lin_Frame_Data frame1; /**< ֡�ľ������� */
    uint8_t Frame_id;      /**< ���͵�֡ ID��PID */
    uint8_t Send_Flag;     /**< ���ͱ�־��1 ��ʾ���ͣ�0 ��ʾ���� */
} Frame;

typedef struct
{
    /* data */
    Frame AQSe_01;                  // ������������������֡
    Frame BLOWER1_SET;              // ������������֡
    Frame EKKe_01;                  // ���ѹ��������֡
    Frame HV_He_01;                 // ��ѹ����������֡
    Frame ISO_Funktionaler_Req_All; // ISO������������֡

    // ���ĵ�����֡
    Frame AQSs_01;        // ��������������״̬����֡
    Frame BLOWER1_STATUS; // ����״̬����֡
    Frame DSs_01;         // �¹����ȿ�����״̬����֡
    Frame DTSs_01;        // �¹��¶ȿ�����״̬����֡
    Frame EKK3s_01;       // ���ѹ����״̬����֡
    Frame EKK4s_01;       // ���ѹ����״̬����֡
    Frame EKK4s_02;       // ���ѹ����״̬����֡
    Frame EKKs_01;        // ���ѹ����״̬����֡
    Frame FSAs_01;        // ǰ�細����������״̬����֡
    Frame HV_Hs_01;       // ��ѹ��������״̬

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
    ScheduleTableEntry st_main[16];                /**< �����ȱ� */
    ScheduleTableEntry st_main_nar[16];            /**< խ�������ȱ� */
    ScheduleTableEntry st_main_rdw_nar[16];        /**< խ�������ȱ�2 */
    ScheduleTableEntry st_main_OBD[16];            /**< OBD �����ȱ� */
    ScheduleTableEntry st_main2[16];               /**< �����ȱ�2 */
    ScheduleTableEntry st_EKK_Fehler[1];           /**< EKK ������ȱ� */
    ScheduleTableEntry DiagRequest[1];             /**< ���������ȱ� */
    ScheduleTableEntry DiagResponse[1];            /**< �����Ӧ���ȱ� */
    ScheduleTableEntry DiagFunktionalerRequest[1]; /**< �������������ȱ� */
} ScheduleTable;


void Kilma_Lin_Init (void);
void Schedule_tables_Send (void);
#endif // !KILMA_LIN_H_

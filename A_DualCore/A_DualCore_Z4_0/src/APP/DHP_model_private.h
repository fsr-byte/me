/*
 * File: DHP_model_private.h
 *
 * Code generated for Simulink model 'DHP_model'.
 *
 * Model version                  : 1.5367
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Fri Mar 18 15:33:37 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Freescale->32-bit PowerPC
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. ROM efficiency
 *    3. RAM efficiency
 *    4. MISRA C:2012 guidelines
 * Validation result: Not run
 */

#ifndef RTW_HEADER_DHP_model_private_h_
#define RTW_HEADER_DHP_model_private_h_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#ifndef UCHAR_MAX
#include <limits.h>
#endif

#if ( UCHAR_MAX != (0xFFU) ) || ( SCHAR_MAX != (0x7F) )
#error Code was generated for compiler with different sized uchar/char. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( USHRT_MAX != (0xFFFFU) ) || ( SHRT_MAX != (0x7FFF) )
#error Code was generated for compiler with different sized ushort/short. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( UINT_MAX != (0xFFFFFFFFU) ) || ( INT_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized uint/int. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( ULONG_MAX != (0xFFFFFFFFU) ) || ( LONG_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized ulong/long. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

/* Imported (extern) block signals */
extern HALI HALI_output;               /* '<Root>/HALI' */
extern PMM PMM_output;                 /* '<Root>/PMM' */
extern CHRG CHRG_output;               /* '<Root>/CHRG' */
extern INP INP_output;                 /* '<Root>/INP' */
extern NM NM_output;                   /* '<Root>/NM' */
extern TMM TMM_output;                 /* '<Root>/TMM' */
extern TQM TQM_output;                 /* '<Root>/TQM' */
extern PEPS_PEPS PEPS_output;          /* '<Root>/PEPS' */
extern ENM ENM_output;                 /* '<Root>/ENM' */
extern Config Config_output;           /* '<Root>/Config' */
extern SPDCtl SPDCtl_output;           /* '<Root>/SPDCtl' */
extern BTK BTK_output;                 /* '<Root>/BTK' */

/* Imported (extern) states */
extern real32_T hIOP_WaterPwm_Duty;    /* '<S10>/Data Store Memory1' */
extern real32_T hIOP_CollisionSw_Duty; /* '<S10>/Data Store Memory3' */
extern real32_T hIOP_Fin4_Hz;          /* '<S4>/Data Store Memory10' */
extern real32_T hIOP_CollisionSw_Hz;   /* '<S4>/Data Store Memory11' */
extern real32_T hIOP_HVInterlock_Hz;   /* '<S4>/Data Store Memory12' */
extern real32_T hIOP_WaterPwm_Hz;      /* '<S4>/Data Store Memory14' */
extern uint32_T SystemTickMs;          /* '<S1>/Data Store Memory1' */
extern uint32_T VHALI_BMS_304_MsgTicks;/* '<S4>/Data Store Memory1' */
extern uint32_T VHALI_ABS_229_MsgTicks;/* '<S4>/Data Store Memory13' */
extern uint32_T VHAL_VCUPTCanTickCount;/* '<S4>/Data Store Memory17' */
extern uint32_T VHAL_VCUCanTickCount;  /* '<S4>/Data Store Memory18' */
extern uint32_T VHALI_BMS_113_MsgTicks;/* '<S4>/Data Store Memory19' */
extern uint32_T VHALI_ICM_234_MsgTicks;/* '<S4>/Data Store Memory2' */
extern uint32_T VHALI_BMS_213_MsgTicks;/* '<S4>/Data Store Memory20' */
extern uint32_T VHALI_BMS_233_MsgTicks;/* '<S4>/Data Store Memory21' */
extern uint32_T VHALI_BMS_303_MsgTicks;/* '<S4>/Data Store Memory22' */
extern uint32_T VHALI_BMS_313_MsgTicks;/* '<S4>/Data Store Memory23' */
extern uint32_T VHALI_BMS_323_MsgTicks;/* '<S4>/Data Store Memory24' */
extern uint32_T VHALI_BMS_377_MsgTicks;/* '<S4>/Data Store Memory25' */
extern uint32_T VHALI_BMS_633_MsgTicks;/* '<S4>/Data Store Memory26' */
extern uint32_T VHALI_BMS_653_MsgTicks;/* '<S4>/Data Store Memory27' */
extern uint32_T VHALI_MCU_115_MsgTicks;/* '<S4>/Data Store Memory28' */
extern uint32_T VHALI_MCU_125_MsgTicks;/* '<S4>/Data Store Memory29' */
extern uint32_T VHALI_EHU_345_MsgTicks;/* '<S4>/Data Store Memory3' */
extern uint32_T VHALI_MCU_215_MsgTicks;/* '<S4>/Data Store Memory30' */
extern uint32_T VHALI_MCU_515_MsgTicks;/* '<S4>/Data Store Memory31' */
extern uint32_T VHALI_DCDC_231_MsgTicks;/* '<S4>/Data Store Memory32' */
extern uint32_T VHALI_DCDC_251_MsgTicks;/* '<S4>/Data Store Memory33' */
extern uint32_T VHALI_OBC_311_MsgTicks;/* '<S4>/Data Store Memory34' */
extern uint32_T VHALI_OBC_321_MsgTicks;/* '<S4>/Data Store Memory35' */
extern uint32_T VHALI_OBC_331_MsgTicks;/* '<S4>/Data Store Memory36' */
extern uint32_T VHALI_ECC_33C_MsgTicks;/* '<S4>/Data Store Memory37' */
extern uint32_T VHALI_ECC_34C_MsgTicks;/* '<S4>/Data Store Memory38' */
extern uint32_T VHALI_ECC_35C_MsgTicks;/* '<S4>/Data Store Memory39' */
extern uint32_T VHALI_BMS_513_MsgTicks;/* '<S4>/Data Store Memory4' */
extern uint32_T VHALI_ECC_36C_MsgTicks;/* '<S4>/Data Store Memory40' */
extern uint32_T VHALI_ABS_232_MsgTicks;/* '<S4>/Data Store Memory41' */
extern uint32_T VHALI_ABS_237_MsgTicks;/* '<S4>/Data Store Memory42' */
extern uint32_T VHALI_GW_217_MsgTicks; /* '<S4>/Data Store Memory43' */
extern uint32_T VHALI_GW_522_MsgTicks; /* '<S4>/Data Store Memory44' */
extern uint32_T VHALI_EPS_2A0_MsgTicks;/* '<S4>/Data Store Memory45' */
extern uint32_T VHALI_EPS_180_MsgTicks;/* '<S4>/Data Store Memory46' */
extern uint32_T VHALI_EAC_349_MsgTicks;/* '<S4>/Data Store Memory47' */
extern uint32_T VHALI_TBOX_298_MsgTicks;/* '<S4>/Data Store Memory48' */
extern uint32_T VHALI_BMS_603_MsgTicks;/* '<S4>/Data Store Memory5' */
extern uint32_T VHALI_TMS_2C0_MsgTicks;/* '<S4>/Data Store Memory51' */
extern uint32_T VHALI_TMS_2C1_MsgTicks;/* '<S4>/Data Store Memory52' */
extern uint32_T VHALI_TMS_2C2_MsgTicks;/* '<S4>/Data Store Memory53' */
extern uint32_T VHALI_TMS_2C3_MsgTicks;/* '<S4>/Data Store Memory54' */
extern uint32_T VHALI_SRS_050_MsgTicks;/* '<S4>/Data Store Memory55' */
extern uint32_T VHALI_BMS_613_MsgTicks;/* '<S4>/Data Store Memory6' */
extern uint32_T VHALI_BMS_623_MsgTicks;/* '<S4>/Data Store Memory8' */
extern uint32_T hIOP_HVInterlock_PulseTime_us;/* '<S701>/Data Store Memory1' */
extern uint32_T VHALI_EAC_34A_MsgTicks;/* '<S687>/Data Store Memory13' */
extern uint32_T VHALI_XBS_241_MsgTicks;/* '<S687>/Data Store Memory17' */
extern uint32_T VHALI_ICM_235_MsgTicks;/* '<S687>/Data Store Memory18' */
extern uint32_T hIOP_LSFaultCode_enum_POR;/* '<S600>/Data Store Memory' */
extern uint16_T VHALO_MotTqReq;        /* '<S10>/Data Store Memory' */
extern uint16_T LSChip7240BFaultStatus;/* '<S591>/Data Store Memory' */
extern uint8_T hIOP_FastChargeAwake_flg;/* '<S10>/Data Store Memory10' */
extern uint8_T hIOP_SlowChargeAwake_flg;/* '<S10>/Data Store Memory11' */
extern uint8_T hIOP_GearSwitch1_flg;   /* '<S10>/Data Store Memory13' */
extern uint8_T hIOP_GearSwitch2_flg;   /* '<S10>/Data Store Memory14' */
extern uint8_T hIOP_GearSwitch3_flg;   /* '<S10>/Data Store Memory15' */
extern uint8_T hIOP_GearSwitch4_flg;   /* '<S10>/Data Store Memory16' */
extern uint8_T hIOP_BrkLightSwitch1_flg;/* '<S10>/Data Store Memory17' */
extern uint8_T hIOP_BrkLightSwitch2_flg;/* '<S10>/Data Store Memory18' */
extern uint8_T hIOP_LSpdFan_flg;       /* '<S10>/Data Store Memory6' */
extern uint8_T hIOP_HSpdFan_flg;       /* '<S10>/Data Store Memory7' */
extern uint8_T hIOP_WaterPump_flg;     /* '<S10>/Data Store Memory8' */
extern uint8_T gbWhoWriteCalArea;      /* '<S10>/Data Store Memory9' */
extern uint8_T hIOP_MainRelay_flg;     /* '<S4>/Data Store Memory16' */
extern uint8_T VHALI_HWVersion;        /* '<S4>/Data Store Memory7' */
extern uint8_T EsclErrorCode;          /* '<S1034>/Data Store Memory1' */
extern uint8_T EsclLinCommFailed;      /* '<S1034>/Data Store Memory16' */
extern uint8_T PTBusOffConfirmedFlag;  /* '<S687>/Data Store Memory' */
extern uint8_T CAN3_BusOffState;       /* '<S687>/Data Store Memory20' */
extern uint8_T HSChip5180BFaultStatus; /* '<S591>/Data Store Memory1' */
extern uint8_T VINP_CruiseKeyRes_flg;  /* '<S592>/Data Store Memory1' */
extern uint8_T VINP_CruiseKeySet_flg;  /* '<S592>/Data Store Memory7' */
extern uint8_T gbDidDataCorrect;       /* '<S528>/Data Store Memory14' */
extern uint8_T gbCalDataCorrect;       /* '<S528>/Data Store Memory15' */
extern uint8_T CruiseKeyFaultCode;     /* '<S528>/Data Store Memory16' */
extern uint8_T gbInvalidWriteToCalArea;/* '<S528>/Data Store Memory19' */
extern uint8_T IGN1_FeedVoltCorrect;   /* '<S528>/Data Store Memory21' */
extern uint8_T IGN2_FeedVoltCorrect;   /* '<S528>/Data Store Memory22' */
extern uint8_T SSB_SyncCorrect;        /* '<S528>/Data Store Memory23' */
extern uint8_T hIOP_HSFaultCode_enum_POR;/* '<S599>/Data Store Memory' */
extern uint8_T DTCStatusRAMTbl[199];   /* '<S7>/Data Store Memory1' */
extern boolean_T DisRecordDTC;         /* '<S1>/Data Store Memory' */
extern boolean_T bool_udsAgingTestError_flag;/* '<S4>/Data Store Memory15' */
extern boolean_T bool_udsAgingTestStart_flag;/* '<S4>/Data Store Memory9' */
extern boolean_T VHALO_MCURelayActive_flg;/* '<S694>/Data Store Memory17' */
extern boolean_T HistDataCheckFaliedFlag;/* '<S528>/Data Store Memory1' */
extern boolean_T VCHRG_ChrgStopLockError_flg;/* '<S528>/Data Store Memory10' */
extern boolean_T VCHRG_OBCWakeupTimeout_flg;/* '<S528>/Data Store Memory11' */
extern boolean_T AppDataCheckFaliedFlag;/* '<S528>/Data Store Memory12' */
extern boolean_T DIDData_Invalid_DFlash;/* '<S528>/Data Store Memory13' */
extern boolean_T DIDData_Invalid_EEPROM;/* '<S528>/Data Store Memory17' */
extern boolean_T VCHRG_ChrgFault_flg;  /* '<S528>/Data Store Memory2' */
extern boolean_T VCHRG_OBCSleepTimeout_flg;/* '<S528>/Data Store Memory24' */
extern boolean_T APPData_Invalid_DFlash_1_2;/* '<S528>/Data Store Memory25' */
extern boolean_T APPData_Invalid_EEPROM_1_2;/* '<S528>/Data Store Memory26' */
extern boolean_T APPData_Invalid_DFlash_3;/* '<S528>/Data Store Memory27' */
extern boolean_T APPData_Invalid_EEPROM_3;/* '<S528>/Data Store Memory28' */
extern boolean_T APPData_Invalid_DFlash_4;/* '<S528>/Data Store Memory29' */
extern boolean_T VCHRG_ChrgModeInvalid_flg;/* '<S528>/Data Store Memory3' */
extern boolean_T APPData_Invalid_EEPROM_4;/* '<S528>/Data Store Memory30' */
extern boolean_T VCHRG_ChrgModeAbnormal_flg;/* '<S528>/Data Store Memory4' */
extern boolean_T VCHRG_ChrgLockCheckTimeout_flg;/* '<S528>/Data Store Memory5' */
extern boolean_T VCHRG_ShiftKnobCheckTimeout_flg;/* '<S528>/Data Store Memory6' */
extern boolean_T VCHRG_ChrgStopAbnormal_flg;/* '<S528>/Data Store Memory7' */
extern boolean_T VCHRG_ChrgStopOperTimeout_flg;/* '<S528>/Data Store Memory8' */
extern boolean_T VCHRG_ChrgStopModeInvalid_flg;/* '<S528>/Data Store Memory9' */

/* Exported data declaration */

/* Declaration for custom storage class: ImportFromFile */
extern uint8_T A11_Mark;
extern uint8_T Authentication_flg;
extern uint8_T FDT_Regen_Spd_Off;
extern uint8_T K11E01R_Mark;
extern uint8_T K11P01_Mark;
extern uint8_T K11P06_Mark;
extern uint8_T K11_Mark;
extern uint32_T KCRS_CruiseMinSpd;
extern uint8_T KHDC_GearDSpdLower_KPH;
extern uint8_T S11P01_Mark;
extern uint8_T S11P03_Mark;
extern uint8_T S11P05_Mark;
extern uint8_T S11_Mark;
extern uint8_T S21_Mark;
extern uint8_T Vehicle_Type;
extern uint8_T X11_Mark;

#endif                                 /* RTW_HEADER_DHP_model_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

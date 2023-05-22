/*
** ###################################################################
**
**     Abstract:
**         Chip specific module features.
**
**     Copyright 2018 NXP
**     All rights reserved.
**
**     THIS SOFTWARE IS PROVIDED BY NXP "AS IS" AND ANY EXPRESSED OR
**     IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
**     OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
**     IN NO EVENT SHALL NXP OR ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
**     INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**     (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
**     SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
**     HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
**     STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
**     IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
**     THE POSSIBILITY OF SUCH DAMAGE.
**
**
** ###################################################################
*/

/*!
 * @file MPC5746R_features.h
 *
 * @page misra_violations MISRA-C:2012 violations
 *
 * @section [global]
 * Violates MISRA 2012 Advisory Rule 2.3, Global typedef not referenced.
 * Type used only in some modules of the SDK.

 * @section [global]
 * Violates MISRA 2012 Advisory Rule 2.5, Global macro not referenced.
 * The macros defined are used to define features for each driver, so this might be reported
 * when the analysis is made only on one driver.
 *
 * @section [global]
 * Violates MISRA 2012 Advisory Directive 4.9, Function-like macro
 * These are very simple macros used for abstracting hw implementation.
 * They help make the code easy to understand.
 *
 * @section [global]
 * Violates MISRA 2012 Required Rule 5.1, identifier clash
 * The supported compilers use more than 31 significant characters for identifiers.
 *
 * @section [global]
 * Violates MISRA 2012 Required Rule 5.2, identifier clash
 * The supported compilers use more than 31 significant characters for identifiers.
 *
 * @section [global]
 * Violates MISRA 2012 Required Rule 5.4, identifier clash
 * The supported compilers use more than 31 significant characters for identifiers.
 *
 * @section [global]
 * Violates MISRA 2012 Required Rule 5.5, identifier clash
 * The supported compilers use more than 31 significant characters for identifiers.
 *
 */

#if !defined(MPC5746R_FEATURES_H)
#define MPC5746R_FEATURES_H

/* include device_registers.h for SIUL2 module configuration structures */
//#include "device_registers.h"

/* ERRATA sections*/

/* @brief E8759: FlexCAN: FD frame format is not compliant to the new ISO/CD 11898-1: 2014-12-11
 * because CAN_CTRL2[ISOCANFDEN] bit cannot be set. The FD frame format is incompatible, the Cyclic
 * Redundancy Check [CRC] does not include the added stuff bit count field. The FD CRC computation
 * is incompatible, a different seed value is used.
 * This errata applies to mask 1N81M for MPC5746R CPU.
 */
#define ERRATA_E8759

/* @brief E8341 FlexCAN: Entering Freeze Mode or Low Power Mode from Normal Mode
 * can cause the module to stop operating
 * In the Flexible Controller Area Network (FlexCAN) module, if the Freeze Enable bit (FRZ) in
 * the Module Configuration Register (MCR) is asserted and the Freeze Mode is requested by
 * asserting the Halt bit (HALT) in MCR, in some cases, the Freeze Mode Acknowledge bit
 * (FRZACK) in the MCR may never be asserted.
 * In addition, the Low-Power Mode Acknowledge bit (LPMACK) in the MCR may never be
 * asserted in some cases when the Low-Power Mode is requested
 * Under the two scenarios described above, the loss of ACK assertion (FRZACK, LPMACK) causes a
 * lock condition. A soft reset action is required in order to remove the lock condition.
 * The change from Normal Mode to Low-Power Mode cannot be done directly. Instead, first
 * change mode from Normal to Freeze Mode, and then from Freeze to Low-Power Mode.
 * This errata applies to mask 1N81M for MPC5746R CPU.
 */
#define ERRATA_E8341

/* @brief E8631 SDADC: Low threshold watchdog cannot be used with signed data.
 * This errata applies to mask 1N83M for MPC57746R CPU.
 */
#define ERRATA_E8631

/* @brief E7204: SENT: Number of Expected Edges Error status flag spuriously set when
 * operating with Option 1 of the Successive Calibration Check method */
#define ERRATA_E7204

/* @brief E7425: SENT: Unexpected NUM_EDGES_ERR error in certain conditions when
 * message has a pause pulse */
#define ERRATA_E7425

/* Mode Entry Module features */

/* @brief Key and inverted key values so write access to MCTL register is permitted */
#define FEATURE_MC_ME_KEY           (0x5AF0U)
#define FEATURE_MC_ME_KEY_INV       (0xA50FU)
/* @brief Mode entry has TEST mode */
#define FEATURE_MC_ME_HAS_TEST_MODE (1U)
/* @brief Mode entry has HALT mode */
#define FEATURE_MC_ME_HAS_HALT_MODE (1U)
/* @brief Mode entry has STOP0 mode */
#define FEATURE_MC_ME_HAS_STOP0_MODE (1U)
/* @brief Mode entry has STANDBY mode */
#define FEATURE_MC_ME_HAS_STANDBY_MODE (0U)
/* @brief Mode entry allow to configured flash bit field*/
#define FEATURE_MC_ME_HAS_FLAON_CONFIG (1U)
/* @brief Mode entry has FLASH in power down mode */
#define FEATURE_MC_ME_HAS_FLAON_PD_MODE (0U)
/* @brief Mode entry has FLASH in low power mode */
#define FEATURE_MC_ME_HAS_FLAON_LP_MODE (0U)
/* @brief Enable or disable SDPLL clock */
#define FEATURE_HAS_SDPLL_CLK_CONFIG (0U)
/* @brief Number of cores. */
#define NUMBER_OF_CORES (2u)

/* WDOG module features */

/* @brief The key values to clear Soft Lock bit */
#define FEATURE_WDOG_UNLOCK_VALUE1  (0xC520U)
#define FEATURE_WDOG_UNLOCK_VALUE2  (0xD928U)

/* PIT module features */

/*! @brief PIT module has RTI channel */
#define FEATURE_PIT_HAS_RTI_CHANNEL (1U)
 /*! @brief Number of interrupt vector for channels of the PIT module */
#define FEATURE_PIT_HAS_NUM_IRQS_CHANS (PIT_IRQS_CH_COUNT)
/*! @brief PIT module has a peculiar instance */
#define FEATURE_PIT_HAS_PECULIAR_INSTANCE   (1U)
/*! @brief The default value of MDIS bit */
#define PIT_MCR_MDIS_DEFAULT                (1U)
/*! @brief PIT instance has not lifetime timer */
#define PIT_INSTANCE_HAS_NOT_LIFETIME_TIMER      (1U)

#if PIT_INSTANCE_HAS_NOT_LIFETIME_TIMER
/*! @brief PIT instance base has not lifetime timer */
#define PIT_INSTANCE_BASE_HAS_NOT_LIFETIME_TIMER   (PIT_0)
#endif

#if FEATURE_PIT_HAS_PECULIAR_INSTANCE
/*! @brief The peculiar instance 1*/
#define PIT_PECULIAR_INSTANCE_1    (1U)
/*! @brief The number channel of the peculiar instance 1 */
#define PIT_CHAN_NUM_OF_PECULIAR_INSTANCE_1   (2U)
/*! @brief The peculiar instance has not RTI channel */
#define PIT_PECULIAR_INSTANCE_HAS_NOT_RTI_CHANNEL (1U)
/*! @brief The peculiar instance base */
#define PIT_PECULIAR_INSTANCE_BASE     (PIT_1)
#endif

#if FEATURE_PIT_HAS_RTI_CHANNEL
/*! @brief The default value of MDIS-RTI bit */
#define PIT_MCR_MDIS_RTI_DEFAULT            (1U)
/*! @brief Clock names for RTI. */
#define RTI_CLOCK_NAMES    {PITRTI0_CLK, PITRTI1_CLK}
#endif
/*! @brief Clock names for PIT. */
#define PIT_CLOCK_NAMES    {PIT0_CLK, PIT1_CLK}

/* SWI2C features */
#define SWI2C_INSTANCE_COUNT                   0xFFU

/* STM module features */

/*! @brief STM module CR register has CSL bit-field */
#define FEATURE_STM_HAS_CLOCK_SELECTION (0U)
/*! @brief Number of interrupt vector for channels of the STM module */
#define FEATURE_STM_HAS_NUM_IRQS_CHANS  (4U)
/*! @brief Clock names for STM. */
#define STM_CLOCK_NAMES    { PBRIDGEx_CLK }

/* SWT module features */

/* @brief Support service mode watchpoint input */
#define FEATURE_SWT_SUPPORT_WATCHPOINT      (0U)
/* @brief Support for clock selection */
#define FEATURE_SWT_HAS_CLOCK_SELECT        (0U)
/* @brief Support for running in stop mode */
#define FEATURE_SWT_HAS_STOP_MODE           (1U)
/* @brief The key values to clear Soft Lock bit */
#define FEATURE_SWT_UNLOCK_VALUE1           (0xC520U)
#define FEATURE_SWT_UNLOCK_VALUE2           (0xD928U)
/* @brief The key values used for resetting the SWT counter in Fixed Service Sequence Mode */
#define FEATURE_SWT_FIXED_SERVICE_VALUE1    (0xA602U)
#define FEATURE_SWT_FIXED_SERVICE_VALUE2    (0xB480U)
/* @brief The reset value of the control register */
#define FEATURE_SWT_CR_RESET_VALUE          (0xFF00010AU)
/* @brief The reset value of the timeout register */
#define FEATURE_SWT_TO_RESET_VALUE          (0x3FDE0U)
/* @brief The reset value of the window register */
#define FEATURE_SWT_WN_RESET_VALUE          (0x0U)
/* @brief The reset value of the service key register */
#define FEATURE_SWT_SK_RESET_VALUE          (0x0U)
/* @brief The minimum timeout value */
#define FEATURE_SWT_TO_MINIMUM_VALUE        (0x100U)
/* @brief Sets the master access protection field */
#define FEATURE_SWT_MAP_MASK                (0xFF000000U)
#define FEATURE_SWT_MAP_SHIFT               (24U)
#define FEATURE_SWT_MAP(x)                  (((uint32_t)(((uint32_t)(x)) << FEATURE_SWT_MAP_SHIFT)) & FEATURE_SWT_MAP_MASK)

/* WKPU module features */

/* @brief WKPU core source. */
typedef enum
{
    WKPU_CORE0    = 0U    /*!< Core 0 */
} wkpu_core_t;

/* @brief The WKPU core array */
#define FEATURE_WKPU_CORE_ARRAY     \
{                                   \
    WKPU_CORE0    /*!< Core 0 */    \
}

/*! @brief The number core support for WKPU module */
#define FEATURE_WKPU_NMI_NUM_CORES                      (1U)
/*! @brief The distance between cores */
#define FEATURE_WKPU_CORE_OFFSET_SIZE                   (8U)
/*! @brief WKPU support non-maskable interrupt */
#define FEATURE_WKPU_SUPPORT_NON_MASK_INT               (1U)
/*! @brief WKPU support critical interrupt */
#define FEATURE_WKPU_SUPPORT_CRITICAL_INT               (2U)
/*! @brief WKPU support machine check request interrupt */
#define FEATURE_WKPU_SUPPORT_MACHINE_CHK_REQ            (3U)
/*! @brief WKPU  isn't generated NMI, critical interrupt, or machine check request  */
#define FEATURE_WKPU_SUPPORT_NONE_REQUEST               (4U)

/* CRC module features */

/* @brief CRC module use for C55. */
#define FEATURE_CRC_DRIVER_HARD_POLYNOMIAL
/* @brief Default CRC read transpose */
#define FEATURE_CRC_DEFAULT_READ_TRANSPOSE      false

/* @brief Default seed value is 0xFFFFU */
#define FEATURE_CRC_DEFAULT_SEED                (0xFFFFU)
/* @brief CRC-8-H2F Autosar polynomial support */
#define FEATURE_CRC_BITS_8_H2F                  (1U)

/* SWI2C features */
#define SWI2C_INSTANCE_COUNT                   0xFFU

/* SMPU module features */

/* @brief Specifies the SMPU hardware and definition revision level */
#define FEATURE_SMPU_HARDWARE_REVISION_LEVEL (1U)
/* @brief Specifies the SMPU has process identifier feature */
#define FEATURE_SMPU_HAS_PROCESS_IDENTIFIER  (0U)
/* @brief Specifies the SMPU has owner lock feature */
#define FEATURE_SMPU_HAS_OWNER_LOCK          (0U)
/* @brief Specifies the SMPU has specific access feature */
#define FEATURE_SMPU_HAS_SPECIFIC_ACCESS_RIGHT_COUNT (0U)
/* @brief Specifies the SMPU support getting error detail */
#define FEATURE_SMPU_SUPPORT_GETTING_ERROR_DETAIL    (1U)
/* @brief Specifies the SMPU has specific instance feature */
#define FEATURE_SMPU_HAS_SPECIFIC_INSTANCE   (1U)
/* @brief Specifies the SMPU has specific region descriptor feature */
#define FEATURE_SMPU_HAS_SPECIFIC_RGD_COUNT  (8U)
/* @brief Specifies the end address reset value */
#define FEATURE_SMPU_END_ADDRESS_RESET_VALUE (0U)
/* @brief Specifies the highest bus master */
#define FEATURE_SMPU_MAX_MASTER_NUMBER       (15U)
/* @brief Specifies total number of bus masters */
#define FEATURE_SMPU_MASTER_COUNT            (7U)
/* @brief The SMPU Logical Bus Master Number for Core 0 master */
#define FEATURE_SMPU_MASTER_CORE0            (0U)
/* @brief The SMPU Logical Bus Master Number for Core 1 master */
#define FEATURE_SMPU_MASTER_CORE1            (1U)
/* @brief The SMPU Logical Bus Master Number for Enhanced Direct Memory Access master */
#define FEATURE_SMPU_MASTER_DMA0             (3U)
/* @brief The SMPU Logical Bus Master Number for Ethernet master */
#define FEATURE_SMPU_MASTER_ENET             (4U)
/* @brief The SMPU Logical Bus Master Number for Serial Interprocessor Interface master */
#define FEATURE_SMPU_MASTER_ZIPWIRE          (7U)
/* @brief The SMPU Logical Bus Master Number for Core 0 Debug master */
#define FEATURE_SMPU_MASTER_DEBUG0           (8U)
/* @brief The SMPU Logical Bus Master Number for Core 1 Debug master */
#define FEATURE_SMPU_MASTER_DEBUG1           (9U)
/* @brief The SMPU Logical Bus Masters */
#define FEATURE_SMPU_MASTER                     \
{                                               \
FEATURE_SMPU_MASTER_CORE0,   /* CORE 0 */       \
FEATURE_SMPU_MASTER_CORE1,   /* CORE 1 */       \
FEATURE_SMPU_MASTER_DMA0,    /* DMA */          \
FEATURE_SMPU_MASTER_ENET,    /* ENET */         \
FEATURE_SMPU_MASTER_ZIPWIRE, /* ZIPWIRE */      \
FEATURE_SMPU_MASTER_DEBUG0,  /* CORE 0 DEBUG */ \
FEATURE_SMPU_MASTER_DEBUG1,  /* CORE 1 DEBUG */ \
}

/* SEMA42 module features */

/* @brief The SEMA42 Logical Bus Master Number for Core Z4a master */
#define FEATURE_SEMA42_MASTER_CORE_Z4A         (0U)
/* @brief The SEMA42 Logical Bus Master Number for Core Z4b master */
#define FEATURE_SEMA42_MASTER_CORE_Z4B         (1U)

/* @brief The SEMA42 Logical Bus Masters */
#define FEATURE_SEMA42_MASTER                      \
{                                                  \
FEATURE_SEMA42_MASTER_CORE_Z4A,  /* CORE Z4A */    \
FEATURE_SEMA42_MASTER_CORE_Z4B,  /* CORE Z4B */    \
}

/* @brief Fast IRC trimmed clock frequency(16MHz). */
#define FEATURE_IRCOSC0_FREQ (16000000U)

/* @brief Fast XOSC clock frequency(40MHz). */
#define FEATURE_XOSC0_FREQ  (40000000U)

/* @brief Define identifiers of auxiliary clock selectors */
#define NO_AC     0U
#define AC0__SC   1U
#define AC1__SC   2U
#define AC2__SC   3U
#define AC3__SC   4U
#define AC4__SC   5U
#define AC5__SC   6U
#define AC6__SC   7U
#define AC7__SC   8U
#define AC8__SC   9U
#define AC9__SC   10U
#define AC10__SC  11U
#define AC11__SC  12U
#define AC12__SC  13U
#define AC13__SC  14U
#define AC14__SC  15U
#define AC15__SC  16U
#define AC0__DC0  17U
#define AC0__DC1  18U
#define AC0__DC2  19U
#define AC0__DC3  20U
#define AC0__DC4  21U
#define AC1__DC0  22U
#define AC1__DC1  23U
#define AC1__DC2  24U
#define AC1__DC3  25U
#define AC2__DC0  26U
#define AC2__DC1  27U
#define AC2__DC2  28U
#define AC2__DC3  29U
#define AC3__DC0  30U
#define AC3__DC1  40U
#define AC3__DC2  41U
#define AC3__DC3  42U
#define AC4__DC0  43U
#define AC4__DC1  44U
#define AC4__DC2  45U
#define AC4__DC3  46U
#define AC5__DC0  47U
#define AC5__DC1  48U
#define AC5__DC2  49U
#define AC5__DC3  50U
#define AC6__DC0  51U
#define AC6__DC1  52U
#define AC6__DC2  53U
#define AC6__DC3  54U
#define AC7__DC0  55U
#define AC7__DC1  56U
#define AC7__DC2  57U
#define AC7__DC3  58U
#define AC8__DC0  59U
#define AC8__DC1  60U
#define AC8__DC2  61U
#define AC8__DC3  62U
#define AC9__DC0  63U
#define AC9__DC1  64U
#define AC9__DC2  65U
#define AC9__DC3  66U
#define AC10__DC0 67U
#define AC10__DC1 68U
#define AC10__DC2 69U
#define AC10__DC3 70U
#define AC11__DC0 71U
#define AC11__DC1 72U
#define AC11__DC2 73U
#define AC11__DC3 74U
#define AC12__DC0 75U
#define AC12__DC1 76U
#define AC12__DC2 77U
#define AC12__DC3 78U
#define AC13__DC0 79U
#define AC13__DC1 80U
#define AC13__DC2 81U
#define AC13__DC3 82U
#define AC14__DC0 83U
#define AC14__DC1 84U
#define AC14__DC2 85U
#define AC14__DC3 86U
#define AC15__DC0 87U
#define AC15__DC1 88U
#define AC15__DC2 89U
#define AC15__DC3 90U

#define SYSTEM_CLOCK_DIVIDER0_MASK (1U<<0U)
#define SYSTEM_CLOCK_DIVIDER1_MASK (1U<<1U)
#define SYSTEM_CLOCK_DIVIDER2_MASK (1U<<2U)
#define SYSTEM_CLOCK_DIVIDER3_MASK (1U<<3U)
#define SYSTEM_CLOCK_DIVIDER4_MASK (1U<<4U)
#define SYSTEM_CLOCK_DIVIDER5_MASK (1U<<5U)
#define SYSTEM_CLOCK_DIVIDER6_MASK (1U<<6U)

#define CMU_RCDIV_IS_NOT_SUPPORTED        (255U)
#define CMU_RCDIV_IS_SUPPORTED_BY_CMU0    (0U)
#define CMU_RCDIV_IS_SUPPORTED_BY_CMU1    (1U)
#define CMU_RCDIV_IS_SUPPORTED_BY_CMU2    (2U)
#define CMU_RCDIV_IS_SUPPORTED_BY_CMU3    (3U)
#define CMU_RCDIV_IS_SUPPORTED_BY_CMU4    (4U)
#define CMU_RCDIV_IS_SUPPORTED_BY_CMU5    (5U)
#define CMU_RCDIV_IS_SUPPORTED_BY_CMU6    (6U)
#define CMU_RCDIV_IS_SUPPORTED_BY_CMU7    (7U)
#define CMU_RCDIV_IS_SUPPORTED_BY_CMU8    (8U)
#define CMU_RCDIV_IS_SUPPORTED_BY_CMU9    (9U)
#define CMU_RCDIV_IS_SUPPORTED_BY_CMU10   (10U)
#define CMU_RCDIV_IS_SUPPORTED_BY_CMU11   (11U)
#define CMU_RCDIV_IS_SUPPORTED_BY_CMU12   (12U)

/* @brief List of the configurable system clock dividers. */
#define SYSTEM_CLOCK_DIVIDERS  (SYSTEM_CLOCK_DIVIDER0_MASK | SYSTEM_CLOCK_DIVIDER1_MASK | SYSTEM_CLOCK_DIVIDER2_MASK)

/* @brief PLL input reference. */
#define FEATURE_PLL0_INPUT_REFERENCE  AC3__SC
#define FEATURE_PLL1_INPUT_REFERENCE  AC4__SC

/* @brief PLL reduced frequency divider version. */
#define FEATURE_PLL_REDUCED_FREQ_DIV_VERSION (0U)

/* @brief FLEXCAN0 configurable interface clock. */
#define FEATURE_FLEXCAN0_CLK_CONFIGURABLE_INTERFACE_CLOCK (0U)

/* @brief PBRIDGEx system clock divider index. */
#define FEATURE_PBRIDGEx_CLK_SYSTEM_CLOCK_DIVIDER_INDEX (2U)

/* @brief PLL0_PHI1 reference entry value. */
#define FEATURE_PLL0_PHI1_REFERENCE_ENTRY_VALUE (3U)

/* @brief ENET_RMII reference entry value. */
#define FEATURE_RMII_SOURCE_ENTRY_VALUE (5U)

/* @brief Synchronous mode for LIN is set using DCF clients */
#define FEATURE_LIN_SYNCHRONOUS_MODE		(0U)

/* @brief LFAST_SYS_PIN source selector. */
#define FEATURE_LFAST_SOURCE_SYS_PIN    (7U)

/* @brief CMU reference. */
#define FEATURE_HAS_RCDIV				  CMU_RCDIV_IS_SUPPORTED_BY_CMU0
#define FEATURE_HAS_RCDIV1				  CMU_RCDIV_IS_NOT_SUPPORTED
#define FIRST_CMU						  CMU_ADCSD
#define CMU_RESET_DIVIDER_VALUE 		  (3U)


#define FEATURE_HAS_SIRC_CLK             (0U)
#define FEATURE_HAS_SIRC_CLKS            (0U)
#define FEATURE_HAS_FIRC_CLK             (0U)
#define FEATURE_HAS_FIRC_CLKS            (0U)
#define FEATURE_HAS_IRCOSC_CLK           (1U)
#define FEATURE_HAS_IRCOSC_CLKS          (1U)
#define FEATURE_HAS_SXOSC_CLK            (0U)
#define FEATURE_HAS_SXOSC_CLKS           (0U)
#define FEATURE_HAS_FXOSC_CLK            (0U)
#define FEATURE_HAS_FXOSC_CLKS           (0U)
#define FEATURE_HAS_XOSC_CLK             (1U)
#define FEATURE_HAS_XOSC_CLKS            (0U)
#define FEATURE_HAS_PLL_PHI0_CLK         (0U)
#define FEATURE_HAS_PLL_PHI0_CLKS        (0U)
#define FEATURE_HAS_PLL_PHI1_CLK         (0U)
#define FEATURE_HAS_PLL_PHI1_CLKS        (0U)
#define FEATURE_HAS_PLL0_PHI0_CLK        (1U)
#define FEATURE_HAS_PLL0_PHI0_CLKS       (0U)
#define FEATURE_HAS_PLL0_PHI1_CLK        (1U)
#define FEATURE_HAS_PLL0_PHI1_CLKS       (0U)
#define FEATURE_HAS_PLL1_PHI0_CLK        (1U)
#define FEATURE_HAS_PLL1_PHI0_CLKS       (0U)
#define FEATURE_HAS_PLL1_PHI1_CLK        (0U)
#define FEATURE_HAS_PLL1_PHI1_CLKS       (0U)
#define FEATURE_HAS_SDPLL_CLK            (0U)
#define FEATURE_HAS_SDPLL_CLKS           (0U)
#define FEATURE_HAS_ENET_RMII_CLK        (1U)
#define FEATURE_HAS_ENET_RMII_CLKS       (0U)
#define FEATURE_HAS_SCS_CLK              (1U)
#define FEATURE_HAS_SCS_CLKS             (0U)
#define FEATURE_HAS_S160_CLK             (0U)
#define FEATURE_HAS_S160_CLKS            (0U)
#define FEATURE_HAS_S80_CLK              (0U)
#define FEATURE_HAS_S80_CLKS             (0U)
#define FEATURE_HAS_S40_CLK              (0U)
#define FEATURE_HAS_S40_CLKS             (0U)
#define FEATURE_HAS_F40_CLK              (0U)
#define FEATURE_HAS_F40_CLKS             (0U)
#define FEATURE_HAS_F80_CLK              (0U)
#define FEATURE_HAS_F80_CLKS             (0U)
#define FEATURE_HAS_FS80_CLK             (0U)
#define FEATURE_HAS_FS80_CLKS            (0U)
#define FEATURE_HAS_F20_CLK              (0U)
#define FEATURE_HAS_F20_CLKS             (0U)
#define FEATURE_HAS_PBRIDGEx_CLK         (1U)
#define FEATURE_HAS_PBRIDGEx_CLKS        (1U)
#define FEATURE_HAS_SYS_CLK              (1U)
#define FEATURE_HAS_SYS_CLKS             (0U)
#define FEATURE_HAS_HALFSYS_CLK          (0U)
#define FEATURE_HAS_HALFSYS_CLKS         (0U)
#define FEATURE_HAS_MOTC_CLK             (0U)
#define FEATURE_HAS_MOTC_CLKS            (0U)
#define FEATURE_HAS_PER_CLK              (1U)
#define FEATURE_HAS_PER_CLKS             (1U)
#define FEATURE_HAS_FXBAR_CLK            (1U)
#define FEATURE_HAS_FXBAR_CLKS           (0U)
#define FEATURE_HAS_SXBAR_CLK            (1U)
#define FEATURE_HAS_SXBAR_CLKS           (1U)
#define FEATURE_HAS_DMA_CLK              (0U)
#define FEATURE_HAS_DMA_CLKS             (0U)
#define FEATURE_HAS_CORE0_CLK            (0U)
#define FEATURE_HAS_CORE0_CLKS           (0U)
#define FEATURE_HAS_CORE1_CLK            (0U)
#define FEATURE_HAS_CORE1_CLKS           (0U)
#define FEATURE_HAS_CORE2_CLK            (0U)
#define FEATURE_HAS_CORE2_CLKS           (0U)
#define FEATURE_HAS_ADC_CLKS             (1U)
#define FEATURE_HAS_ADCSD_CLKS           (1U)
#define FEATURE_HAS_DSPI_CLKS            (1U)
#define FEATURE_HAS_DSPIM_CLKS           (1U)
#define FEATURE_HAS_ENET_CLKS            (1U)
#define FEATURE_HAS_ENET_TIME_CLKS       (0U)
#define FEATURE_HAS_EMIOS_CLKS           (1U)
#define FEATURE_HAS_ETPU_CLKS            (1U)
#define FEATURE_HAS_FLEXCAN_CLKS         (1U)
#define FEATURE_HAS_FLEXRAY_CLKS         (0U)
#define FEATURE_HAS_LFAST_CLKS           (1U)
#define FEATURE_HAS_LIN_CLKS             (1U)
#define FEATURE_HAS_RTI_CLKS             (1U)
#define FEATURE_HAS_SDHC_CLKS            (0U)
#define FEATURE_HAS_SENT_CLKS            (1U)
#define FEATURE_HAS_SGEN_CLKS            (0U)
#define FEATURE_HAS_SPI_CLKS             (0U)
#define FEATURE_HAS_SPT_CLKS             (0U)
#define FEATURE_HAS_CLKOUT0_CLKS         (1U)
#define FEATURE_HAS_CLKOUT1_CLKS         (0U)


#define FEATURE_PROTOCOL_CLOCK_FOR_ADC                 AC0__SC
#define FEATURE_PROTOCOL_CLOCK_FOR_ADCSD               AC0__SC
#define FEATURE_PROTOCOL_CLOCK_FOR_DSPI                AC0__SC
#define FEATURE_PROTOCOL_CLOCK_FOR_DSPIM               AC0__SC
#define FEATURE_PROTOCOL_CLOCK_FOR_ENET                AC10__SC
#define FEATURE_PROTOCOL_CLOCK_FOR_ENET_TIME           NO_AC
#define FEATURE_PROTOCOL_CLOCK_FOR_EMIOS               AC5__SC
#define FEATURE_PROTOCOL_CLOCK_FOR_ETPU                AC5__SC
#define FEATURE_PROTOCOL_CLOCK_FOR_FLEXCAN             AC8__SC
#define FEATURE_PROTOCOL_CLOCK_FOR_FLEXRAY             NO_AC
#define FEATURE_PROTOCOL_CLOCK_FOR_LFAST               AC1__SC
#define FEATURE_PROTOCOL_CLOCK_FOR_LIN                 AC0__SC
#define FEATURE_PROTOCOL_CLOCK_FOR_RTI                 AC9__SC
#define FEATURE_PROTOCOL_CLOCK_FOR_SDHC                NO_AC
#define FEATURE_PROTOCOL_CLOCK_FOR_SENT                AC2__SC
#define FEATURE_PROTOCOL_CLOCK_FOR_SGEN                NO_AC
#define FEATURE_PROTOCOL_CLOCK_FOR_SPI                 NO_AC
#define FEATURE_PROTOCOL_CLOCK_FOR_SPT                 NO_AC
#define FEATURE_PROTOCOL_CLOCK_FOR_CLKOUT0             AC6__SC
#define FEATURE_PROTOCOL_CLOCK_FOR_CLKOUT1             NO_AC
#define FEATURE_INTERFACE_CLOCK_FOR_ADC                NO_AC
#define FEATURE_INTERFACE_CLOCK_FOR_ADCSD              NO_AC
#define FEATURE_INTERFACE_CLOCK_FOR_DSPI               NO_AC
#define FEATURE_INTERFACE_CLOCK_FOR_DSPIM              NO_AC
#define FEATURE_INTERFACE_CLOCK_FOR_ENET               NO_AC
#define FEATURE_INTERFACE_CLOCK_FOR_ENET_TIME          NO_AC
#define FEATURE_INTERFACE_CLOCK_FOR_EMIOS              NO_AC
#define FEATURE_INTERFACE_CLOCK_FOR_ETPU               NO_AC
#define FEATURE_INTERFACE_CLOCK_FOR_FLEXCAN            NO_AC
#define FEATURE_INTERFACE_CLOCK_FOR_FLEXRAY            NO_AC
#define FEATURE_INTERFACE_CLOCK_FOR_LFAST              NO_AC
#define FEATURE_INTERFACE_CLOCK_FOR_LIN                NO_AC
#define FEATURE_INTERFACE_CLOCK_FOR_RTI                NO_AC
#define FEATURE_INTERFACE_CLOCK_FOR_SDHC               NO_AC
#define FEATURE_INTERFACE_CLOCK_FOR_SENT               NO_AC
#define FEATURE_INTERFACE_CLOCK_FOR_SGEN               NO_AC
#define FEATURE_INTERFACE_CLOCK_FOR_SPI                NO_AC
#define FEATURE_INTERFACE_CLOCK_FOR_SPT                NO_AC
#define FEATURE_FRACTIONAL_DIVIDER_FOR_ADC             AC0__DC2
#define FEATURE_FRACTIONAL_DIVIDER_FOR_ADCSD           AC0__DC1
#define FEATURE_FRACTIONAL_DIVIDER_FOR_DSPI            AC0__DC4
#define FEATURE_FRACTIONAL_DIVIDER_FOR_DSPIM           AC0__DC3
#define FEATURE_FRACTIONAL_DIVIDER_FOR_ENET            AC10__DC0
#define FEATURE_FRACTIONAL_DIVIDER_FOR_ENET_TIME       NO_AC
#define FEATURE_FRACTIONAL_DIVIDER_FOR_EMIOS           AC5__DC1
#define FEATURE_FRACTIONAL_DIVIDER_FOR_ETPU            AC5__DC0
#define FEATURE_FRACTIONAL_DIVIDER_FOR_FLEXCAN         AC8__DC0
#define FEATURE_FRACTIONAL_DIVIDER_FOR_FLEXRAY         NO_AC
#define FEATURE_FRACTIONAL_DIVIDER_FOR_LFAST           AC1__DC0
#define FEATURE_FRACTIONAL_DIVIDER_FOR_LIN             AC0__DC4
#define FEATURE_FRACTIONAL_DIVIDER_FOR_RTI             AC9__DC0
#define FEATURE_FRACTIONAL_DIVIDER_FOR_SDHC            NO_AC
#define FEATURE_FRACTIONAL_DIVIDER_FOR_SENT            AC2__DC0
#define FEATURE_FRACTIONAL_DIVIDER_FOR_SGEN            NO_AC
#define FEATURE_FRACTIONAL_DIVIDER_FOR_SPI             NO_AC
#define FEATURE_FRACTIONAL_DIVIDER_FOR_SPT             NO_AC
#define FEATURE_FRACTIONAL_DIVIDER_FOR_CLKOUT0         AC6__DC0
#define FEATURE_FRACTIONAL_DIVIDER_FOR_CLKOUT1         NO_AC



/* Interrupt module features */
/* @brief Highest interrupt priority number. */
#define FEATURE_INTERRUPT_PRIO_MAX  (63u)

/* @brief Has software interrupt. */
#define FEATURE_INTERRUPT_HAS_SOFTWARE_IRQ  (1u)
/* @brief Has pending interrupt state. */
#define FEATURE_INTERRUPT_HAS_PENDING_STATE (0u)
/* @brief Has active interrupt state. */
#define FEATURE_INTERRUPT_HAS_ACTIVE_STATE  (0u)
/* @brief Default interrupt priority for enable interrupts. */
#define FEATURE_INTERRUPT_DEFAULT_PRIO  (1u)
/* @brief Multicore support for interrupts */
#define FEATURE_INTERRUPT_MULTICORE_SUPPORT  (1u)
/* @brief Mask to enable interrupts for all cores */
#define FEATURE_INTERRUPT_ENABLE_ON_ALL_CORES_MASK  (0xC000u)
/* @brief Available cores for this device */
#define FEATURE_INTERRUPT_CORE_0_ENABLED (1u)
#define FEATURE_INTERRUPT_CORE_1_ENABLED (1u)
#define FEATURE_INTERRUPT_CORE_2_ENABLED (0u)
/* @brief Registers in which the start of interrupt vector table needs to be configured */
#define FEATURE_INTERRUPT_INT_VECTORS {&INTC->IACKR0, &INTC->IACKR1}

/* FLASH C55 module features */

/* @brief Type of flash module is C55FMC. */
#define FEATURE_FLS_C55_C55FMC (1U)
/* @brief Type of flash module is C55MP. */
#define FEATURE_FLS_C55_C55MP (0U)
/* @brief Type of flash module is C55FP. */
#define FEATURE_FLS_C55_C55FP (0U)
/* @brief Over-program protection enabled block. */
#define FEATURE_FLS_C55_HAS_OTP
/* @brief Has alternate interface. */
#define FEATURE_FLS_C55_HAS_ALTERNATE (0U)
/* @brief Has erase operation in the alternate interface. */
#define FEATURE_FLS_C55_HAS_ERASE_ALTERNATE (0U)
/* @brief The size of writes that are allowed. */
#define FLASH_C55_PROGRAMABLE_SIZE (0x80U)
/* @brief The address in the uTest space. */
#define FLASH_C55_INTERLOCK_WRITE_UTEST_ADDRESS (0x00400000U)
/* @brief The base address of the 16KB high block. */
#define FLASH_C55_16KB_HIGH_BASE_ADDRESS (0xFFFFFFFFU)
/* @brief The base address of the 32KB high block. */
#define FLASH_C55_32KB_HIGH_BASE_ADDRESS (0xFFFFFFFFU)
/* @brief The base address of the 64KB high block. */
#define FLASH_C55_64KB_HIGH_BASE_ADDRESS (0xFFFFFFFFU)
/* @brief The base address of the 16KB mid block. */
#define FLASH_C55_16KB_MID_BASE_ADDRESS (0x00800000U)
/* @brief The base address of the 32KB mid block. */
#define FLASH_C55_32KB_MID_BASE_ADDRESS (0xFFFFFFFFU)
/* @brief The base address of the 64KB mid block. */
#define FLASH_C55_64KB_MID_BASE_ADDRESS (0x00820000U)
/* @brief The base address of the 16KB low block. */
#define FLASH_C55_16KB_LOW_BASE_ADDRESS (0x00404000U)
/* @brief The base address of the 32KB low block. */
#define FLASH_C55_32KB_LOW_BASE_ADDRESS (0x00FB0000U)
/* @brief The base address of the 64KB low block. */
#define FLASH_C55_64KB_LOW_BASE_ADDRESS (0x00FC0000U)
/* @brief The size of 16K block. */
#define FLASH_C55_16KB_SIZE (0x4000U)
/* @brief The size of 32K block. */
#define FLASH_C55_32KB_SIZE (0x8000U)
/* @brief The size of 64K block. */
#define FLASH_C55_64KB_SIZE (0x10000U)
/* @brief The base address of the 256KB block. */
#define FLASH_C55_256KB_BASE_ADDRESS (0x01000000U)
/* @brief The number of low block */
#define NUM_LOW_BLOCK                          12U
/* @brief The number of 16K low block */
#define NUM_16K_LOW_BLOCK                       6U
/* @brief The number of 32K low block */
#define NUM_32K_LOW_BLOCK                       2U
/* @brief The number of 64K low block */
#define NUM_64K_LOW_BLOCK                       4U
/* @brief The number of mid block */
#define NUM_MID_BLOCK                          10U
/* @brief The number of high block */
#define NUM_HIGH_BLOCK                         0U
/* @brief The number of 256k block */
#define NUM_256K_BLOCK_FIRST                    14U
#define NUM_256K_BLOCK_SECOND                   0U
#define NUM_256K_BLOCK                         (NUM_256K_BLOCK_FIRST + NUM_256K_BLOCK_SECOND)
#define NUM_BLOCK                              (NUM_LOW_BLOCK + NUM_MID_BLOCK + NUM_HIGH_BLOCK + NUM_256K_BLOCK)

#define LOW_BLOCK0_ADDR                        0x00404000U
#define LOW_BLOCK0_MASK                        (1UL << 0x0U)

#define LOW_BLOCK1_ADDR                        0x00FA0000U
#define LOW_BLOCK1_MASK                        (1UL << 0x1U)

#define LOW_BLOCK2_ADDR                        0x00FA4000U
#define LOW_BLOCK2_MASK                        (1UL << 0x2U)

#define LOW_BLOCK3_ADDR                        0x00FA8000U
#define LOW_BLOCK3_MASK                        (1UL << 0x3U)

#define LOW_BLOCK4_ADDR                        0x00FAC000U
#define LOW_BLOCK4_MASK                        (1UL << 0x4U)

#define LOW_BLOCK5_ADDR                        0x00F9C000U
#define LOW_BLOCK5_MASK                        (1UL << 0x5U)

#define LOW_BLOCK6_ADDR                        0x00FB0000U
#define LOW_BLOCK6_MASK                        (1UL << 0x6U)

#define LOW_BLOCK7_ADDR                        0x00FB8000U
#define LOW_BLOCK7_MASK                        (1UL << 0x7U)

#define LOW_BLOCK8_ADDR                        0x00FC0000U
#define LOW_BLOCK8_MASK                        (1UL << 0x8U)

#define LOW_BLOCK9_ADDR                        0x00FD0000U
#define LOW_BLOCK9_MASK                        (1UL << 0x9U)

#define LOW_BLOCK10_ADDR                        0x00FE0000U
#define LOW_BLOCK10_MASK                        (1UL << 0xAU)

#define LOW_BLOCK11_ADDR                        0x00FF0000U
#define LOW_BLOCK11_MASK                        (1UL << 0xBU)

/* Define Macros for mid blocks */
#define MID_BLOCK0_ADDR                        0x00800000U
#define MID_BLOCK0_MASK                        (1UL << 0x0U)

#define MID_BLOCK1_ADDR                        0x00804000U
#define MID_BLOCK1_MASK                        (1UL << 0x1U)

#define MID_BLOCK2_ADDR                        0x00808000U
#define MID_BLOCK2_MASK                        (1UL << 0x2U)

#define MID_BLOCK3_ADDR                        0x0080C000U
#define MID_BLOCK3_MASK                        (1UL << 0x3U)

#define MID_BLOCK4_ADDR                        0x00810000U
#define MID_BLOCK4_MASK                        (1UL << 0x4U)

#define MID_BLOCK5_ADDR                        0x00814000U
#define MID_BLOCK5_MASK                        (1UL << 0x5U)

#define MID_BLOCK6_ADDR                        0x00818000U
#define MID_BLOCK6_MASK                        (1UL << 0x6U)

#define MID_BLOCK7_ADDR                        0x0081C000U
#define MID_BLOCK7_MASK                        (1UL << 0x7U)

#define MID_BLOCK8_ADDR                        0x00820000U
#define MID_BLOCK8_MASK                        (1UL << 0x8U)

#define MID_BLOCK9_ADDR                        0x00830000U
#define MID_BLOCK9_MASK                        (1UL << 0x9U)



/* Define Macros for 256k blocks */
#define N256K_BLOCK0_ADDR                       0x01000000U
#define N256K_BLOCK0_MASK                       (1UL << 0x0U)

#define N256K_BLOCK1_ADDR                       0x01040000U
#define N256K_BLOCK1_MASK                       (1UL << 0x1U)

#define N256K_BLOCK2_ADDR                       0x01080000U
#define N256K_BLOCK2_MASK                       (1UL << 0x2U)

#define N256K_BLOCK3_ADDR                       0x010C0000U
#define N256K_BLOCK3_MASK                       (1UL << 0x3U)

#define N256K_BLOCK4_ADDR                       0x01100000U
#define N256K_BLOCK4_MASK                       (1UL << 0x4U)

#define N256K_BLOCK5_ADDR                       0x01140000U
#define N256K_BLOCK5_MASK                       (1UL << 0x5U)

#define N256K_BLOCK6_ADDR                       0x01180000U
#define N256K_BLOCK6_MASK                       (1UL << 0x6U)

#define N256K_BLOCK7_ADDR                       0x011C0000U
#define N256K_BLOCK7_MASK                       (1UL << 0x7U)

#define N256K_BLOCK8_ADDR                       0x01200000U
#define N256K_BLOCK8_MASK                       (1UL << 0x8U)

#define N256K_BLOCK9_ADDR                       0x01240000U
#define N256K_BLOCK9_MASK                       (1UL << 0x9U)

#define N256K_BLOCK10_ADDR                      0x01280000U
#define N256K_BLOCK10_MASK                      (1UL << 0xAU)

#define N256K_BLOCK11_ADDR                      0x012C0000U
#define N256K_BLOCK11_MASK                      (1UL << 0xBU)

#define N256K_BLOCK12_ADDR                      0x01300000U
#define N256K_BLOCK12_MASK                      (1UL << 0xCU)

#define N256K_BLOCK13_ADDR                      0x01340000U
#define N256K_BLOCK13_MASK                      (1UL << 0xDU)


#define FLASH_BLOCK_ADDR_DEFINE \
{                               \
LOW_BLOCK0_ADDR, /* Low block 0 address */ \
LOW_BLOCK1_ADDR, /* Low block 1 address */ \
LOW_BLOCK2_ADDR, /* Low block 2 address */ \
LOW_BLOCK3_ADDR, /* Low block 3 address */ \
LOW_BLOCK4_ADDR, /* Low block 4 address */ \
LOW_BLOCK5_ADDR, /* Low block 5 address */ \
LOW_BLOCK6_ADDR, /* Low block 6 address */ \
LOW_BLOCK7_ADDR, /* Low block 7 address */ \
LOW_BLOCK8_ADDR, /* Low block 8 address */ \
LOW_BLOCK9_ADDR, /* Low block 9 address */ \
LOW_BLOCK10_ADDR, /* Low block 10 address */ \
LOW_BLOCK11_ADDR, /* Low block 11 address */ \
MID_BLOCK0_ADDR, /* Mid block 0 address */ \
MID_BLOCK1_ADDR, /* Mid block 1 address */ \
MID_BLOCK2_ADDR, /* Mid block 2 address */ \
MID_BLOCK3_ADDR, /* Mid block 3 address */ \
MID_BLOCK4_ADDR, /* Mid block 4 address */  \
MID_BLOCK5_ADDR, /* Mid block 5 address */  \
MID_BLOCK6_ADDR, /* Mid block 6 address */  \
MID_BLOCK7_ADDR, /* Mid block 7 address */  \
MID_BLOCK8_ADDR, /* Mid block 8 address */  \
MID_BLOCK9_ADDR, /* Mid block 8 address */  \
N256K_BLOCK0_ADDR, /* 256K block 0 address */  \
N256K_BLOCK1_ADDR, /* 256K block 1 address */  \
N256K_BLOCK2_ADDR, /* 256K block 2 address */  \
N256K_BLOCK3_ADDR, /* 256K block 3 address */  \
N256K_BLOCK4_ADDR, /* 256K block 4 address */  \
N256K_BLOCK5_ADDR, /* 256K block 5 address */  \
N256K_BLOCK6_ADDR, /* 256K block 6 address */  \
N256K_BLOCK7_ADDR, /* 256K block 7 address */  \
N256K_BLOCK8_ADDR, /* 256K block 8 address */  \
N256K_BLOCK9_ADDR, /* 256K block 9 address */  \
N256K_BLOCK10_ADDR, /* 256K block 10 address */  \
N256K_BLOCK11_ADDR, /* 256K block 11 address */  \
N256K_BLOCK12_ADDR, /* 256K block 12 address */  \
N256K_BLOCK13_ADDR /* 256K block 13 address */  \
}
#define FLASH_BLOCK_MASK_DEFINE \
{                              \
LOW_BLOCK0_MASK, /* Low block 0 mask */ \
LOW_BLOCK1_MASK, /* Low block 1 mask */ \
LOW_BLOCK2_MASK, /* Low block 2 mask */ \
LOW_BLOCK3_MASK, /* Low block 3 mask */ \
LOW_BLOCK4_MASK, /* Low block 4 mask */ \
LOW_BLOCK5_MASK, /* Low block 5 mask */ \
LOW_BLOCK6_MASK, /* Low block 6 mask */ \
LOW_BLOCK7_MASK, /* Low block 7 mask */ \
LOW_BLOCK8_MASK, /* Low block 8 mask */ \
LOW_BLOCK9_MASK, /* Low block 9 mask */ \
LOW_BLOCK10_MASK, /* Low block 10 mask */ \
LOW_BLOCK11_MASK, /* Low block 11 mask */ \
MID_BLOCK0_MASK, /* Mid block 0 mask */ \
MID_BLOCK1_MASK, /* Mid block 1 mask */ \
MID_BLOCK2_MASK, /* Mid block 2 mask */ \
MID_BLOCK3_MASK, /* Mid block 3 mask */ \
MID_BLOCK4_MASK, /* Mid block 4 mask */  \
MID_BLOCK5_MASK, /* Mid block 5 mask */  \
MID_BLOCK6_MASK, /* Mid block 6 mask */  \
MID_BLOCK7_MASK, /* Mid block 7 mask */  \
MID_BLOCK8_MASK, /* Mid block 8 mask */  \
MID_BLOCK9_MASK, /* Mid block 8 mask */  \
N256K_BLOCK0_MASK, /* 256K block 0 mask */  \
N256K_BLOCK1_MASK, /* 256K block 1 mask */  \
N256K_BLOCK2_MASK, /* 256K block 2 mask */  \
N256K_BLOCK3_MASK, /* 256K block 3 mask */  \
N256K_BLOCK4_MASK, /* 256K block 4 mask */  \
N256K_BLOCK5_MASK, /* 256K block 5 mask */  \
N256K_BLOCK6_MASK, /* 256K block 6 mask */  \
N256K_BLOCK7_MASK, /* 256K block 7 mask */  \
N256K_BLOCK8_MASK, /* 256K block 8 mask */  \
N256K_BLOCK9_MASK, /* 256K block 9 mask */  \
N256K_BLOCK10_MASK, /* 256K block 10 mask */  \
N256K_BLOCK11_MASK, /* 256K block 11 mask */  \
N256K_BLOCK12_MASK, /* 256K block 12 mask */  \
N256K_BLOCK13_MASK /* 256K block 13 mask */  \
}

/* EEE module features */

/*  @brief The block endurance for erasing successful */
#define BLOCK_MAX_ENDURANCE       (250000U)
/*  @brief The EEC error will occur in IVOR exception handler */
#define EEE_ERR_IVOR_EXCEPTION    (0)
/*  @brief The EEC error will set an ECC error in MCR register */
#define EEE_ERR_C55_MCR           (1)
/*  @brief Has 4 bytes ECC */
#define EEE_ECC4                  (0)
/*  @brief Has 8 bytes ECC */
#define EEE_ECC8                  (1)
/*  @brief Has 16 bytes ECC */
#define EEE_ECC16                 (0)
/*  @brief Has 32 bytes ECC */
#define EEE_ECC32                 (0)

/* OSIF module features */

#define FEATURE_OSIF_USE_SYSTICK                         (0)
#define FEATURE_OSIF_USE_PIT                             (1)
#define FEATURE_OSIF_FREERTOS_ISR_CONTEXT_METHOD         (2)
#define OSIF_PIT (PIT_0)
#define OSIF_PIT_CHAN_ID_MAX (7u)
#define FEATURE_OSIF_PIT_FRZ_IN_DEBUG                    (0)

/* FCCU module features */

#define FEATURE_FCCU_UNLOCK_OP1                (0x913756AFU)
#define FEATURE_FCCU_UNLOCK_OP2                (0x825A132BU)
#define FEATURE_FCCU_UNLOCK_OP31               (0x29AF8752U)

#define FEATURE_FCCU_NCF_KEY                   (0xAB3498FEU)

#define FEATURE_FCCU_IRQ_EN_MASK               (0x1U)

#define FEATURE_FCCU_TRANS_UNLOCK              (0xBCU)
#define FEATURE_FCCU_PERMNT_LOCK               (0xFFU)

#define FEATURE_FCCU_MAX_FAULTS_NO             (uint8_t)(95U)
/* FCUU filter feature */
#define FEATURE_FCCU_FILTER_EN                 (1U)
/* FCCU open drain for the error indicating pin(s) */
#define FEATURE_FCCU_OPEN_DRAIN_EN             (0U)
/* FCCU mode controller status */
#define FEATURE_FCCU_CONTROL_MODE_EN           (1U)
/* FCCU redundancy control checker */
#define FEATURE_FCCU_RCC_EN                    (1U)
/* FCCU Fault-Output (EOUT) Prescaler */
#define FEATURE_FCCU_FOP_SUPPORT

/* MSCM module features */

/* @brief Has interrupt router control registers (IRSPRCn). */
#define FEATURE_MSCM_HAS_INTERRUPT_ROUTER                (0)
/* @brief Has directed CPU interrupt routerregisters (IRCPxxx). */
#define FEATURE_MSCM_HAS_CPU_INTERRUPT_ROUTER            (0)


/* EMIOS module features */

/* @brief EMIOS CNT register 24 bits. */
#define FEATURE_EMIOS_COUNTER_24_BITS
/* @brief eMIOS disable channel register. */
#define FEATURE_EMIOS_UC_DISABLE
/* @brief EMIOS STAC Client. */
#define FEATURE_EMIOS_STAC_CLIENT
/* @brief EMIOS support all modes for each channel. */
#define FEATURE_EMIOS_ALL_MODE_ON_CHANNEL
/* @brief EMIOS has channel pair in the IRQ interrupt. */
#define FEATURE_EMIOS_CHANNELS_PER_IRQ          (1U)
/* @brief EMIOS number channels maximum. */
#define FEATURE_EMIOS_CHANNEL_MAX_COUNT         (32U)
/* @brief EMIOS Output Pulse-Width Modulation with Trigger. */
#define FEATURE_EMIOS_MODE_OPWMT_SUPPORT        (1U)
/* @brief EMIOS channels and counter buses select. */
#define FEATURE_EMIOS_BUS_A_SELECT              (1U)
#define FEATURE_EMIOS_BUS_B_SELECT              (0U)
#define FEATURE_EMIOS_BUS_C_SELECT              (1U)
#define FEATURE_EMIOS_BUS_D_SELECT              (1U)
#define FEATURE_EMIOS_BUS_E_SELECT              (0U)
#define FEATURE_EMIOS_BUS_F_SELECT              (0U)
/* @brief EMIOS channels and counter buses offset. */
#define FEATURE_EMIOS_BUS_B_SELECT_OFFSET(x)    (x)
#define FEATURE_EMIOS_BUS_C_SELECT_OFFSET(x)    (x - 8U)
#define FEATURE_EMIOS_BUS_D_SELECT_OFFSET(x)    (x - 8U)
#define FEATURE_EMIOS_BUS_E_SELECT_OFFSET(x)    (x)
/* @brief EMIOS number of channels available. */
#define FEATURE_EMIOS_CH_7_0_ENABLE             (0U)
#define FEATURE_EMIOS_CH_15_8_ENABLE            (1U)
#define FEATURE_EMIOS_CH_23_16_ENABLE           (1U)
#define FEATURE_EMIOS_CH_31_24_ENABLE           (0U)
#define FEATURE_EMIOS_CH_COUNT                  ((FEATURE_EMIOS_CH_7_0_ENABLE   * 8U) + \
                                                 (FEATURE_EMIOS_CH_15_8_ENABLE  * 8U) + \
                                                 (FEATURE_EMIOS_CH_23_16_ENABLE * 8U) + \
                                                 (FEATURE_EMIOS_CH_31_24_ENABLE * 8U))
/* @brief EMIOS channels offset. */
#define FEATURE_EMIOS_CH_7_0_SUB_OFFSET(x)      (x)
#define FEATURE_EMIOS_CH_15_8_SUB_OFFSET(x)     (x - 8U)
#define FEATURE_EMIOS_CH_23_16_SUB_OFFSET(x)    (x - 8U)
#define FEATURE_EMIOS_CH_31_24_SUB_OFFSET(x)    (x)

/* PWM_PAL module features */
#define FEATURE_PWMPAL_EMIOS_HAS_CHANNEL_MAPPING    (1)
#define PWMPAL_INDEX_2_HW_CHANNELS {8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23}

/* LINFlexD module features */

/* @brief LINFlexD separate interrupt lines for rx/tx/error. */
#define FEATURE_LINFLEXD_RX_TX_ERR_INT_LINES
/* @brief Clock names for LINFlexD */

/* @brief Address of the least significant byte in a 32-bit register (depends on endianess) */
#define FEATURE_LINFLEXD_LSB_ADDR(reg)  ((uint32_t)(&(reg)) + 3U)
/* @brief Address of the least significant word in a 32-bit register (depends on endianess) */
#define FEATURE_LINFLEXD_LSW_ADDR(reg)  ((uint32_t)(&(reg)) + 2U)
/* @brief LINFlexD "instance-implemented filters" mapping */
#define FEATURE_LINFLEXD_INST_HAS_IFCR {true, false, false, false, false, false}
/* @brief LINFlexD DMA support */
#define FEATURE_LINFLEXD_HAS_DMA_ENABLED
/* @brief LINFlexD DMA enabled instances */
#define FEATURE_LINFLEXD_INST_HAS_DMA {true, true, true, true, true, true}
/* @brief LINFlexD timeout interrupt enable bit mask */

#define FEATURE_LINFLEXD_HAS_DIFFERENT_MEM_MAP


/* EDMA module features */

/* @brief DMA hardware version 2. */
#define FEATURE_DMA_HWV2
/* @brief Number of DMA channels. */
#define FEATURE_DMA_CHANNELS (64U)
/* @brief Number of DMA virtual channels. */
#define FEATURE_DMA_VIRTUAL_CHANNELS (FEATURE_DMA_CHANNELS * DMA_INSTANCE_COUNT)
/* @brief Number of DMA interrupt lines. */
#define FEATURE_DMA_CHANNELS_INTERRUPT_LINES (64U)
/* @brief Number of DMA virtual interrupt lines. */
#define FEATURE_DMA_VIRTUAL_CHANNELS_INTERRUPT_LINES ((uint32_t)FEATURE_DMA_CHANNELS_INTERRUPT_LINES * (uint32_t)DMA_INSTANCE_COUNT)
/* @brief Number of DMA error interrupt lines. */
#define FEATURE_DMA_ERROR_INTERRUPT_LINES (1U)
/* @brief Number of DMA virtual error interrupt lines. */
#define FEATURE_DMA_VIRTUAL_ERROR_INTERRUPT_LINES ((uint32_t)FEATURE_DMA_ERROR_INTERRUPT_LINES * (uint32_t)DMA_INSTANCE_COUNT)
/* @brief DMA module has error interrupt. */
#define FEATURE_DMA_HAS_ERROR_IRQ
/* @brief DMA module separate interrupt lines for each channel */
#define FEATURE_DMA_SEPARATE_IRQ_LINES_PER_CHN
/* @brief Conversion from channel index to DCHPRI index. */
#define FEATURE_DMA_CHN_TO_DCHPRI_INDEX(x) (x)
/* @brief DMA channel groups count. */
#define FEATURE_DMA_CHANNEL_GROUP_COUNT (2U)

/* @brief DMA channel width based on number of TCDs: 2^N, N=4,5,... */
#define FEATURE_DMA_CH_WIDTH (6U)
/* @brief DMA channel to instance */
#define FEATURE_DMA_VCH_TO_INSTANCE(x) 	((x) >> (uint32_t)FEATURE_DMA_CH_WIDTH)
/* @brief DMA virtual channel to channel */
#define FEATURE_DMA_VCH_TO_CH(x)        ((x) & ((uint32_t)FEATURE_DMA_CHANNELS - 1U))
/* @brief DMA supports the following particular transfer size: */
#define FEATURE_DMA_TRANSFER_SIZE_16B
#define FEATURE_DMA_TRANSFER_SIZE_32B


/* DMAMUX module features */

/* @brief DMAMUX peripheral is available in silicon. */
#define FEATURE_DMAMUX_AVAILABLE
/* @brief Number of DMA channels. */
#define FEATURE_DMAMUX_CHANNELS (16U)
/* @brief Has the periodic trigger capability */
#define FEATURE_DMAMUX_HAS_TRIG (1)

/* @brief Conversion from eDMA channel index to DMAMUX channel. */
#define FEATURE_DMAMUX_DMA_CH_TO_CH(x) ((x) & (FEATURE_DMAMUX_CHANNELS - 1U))
/* @brief Conversion from DMAMUX channel DMAMUX register index. */
#define FEATURE_DMAMUX_CHN_REG_INDEX(x) (x)

/*!
 * @brief Structure for the DMA hardware request
 *
 * Defines the structure for the DMA hardware request collections. The user can configure the
 * hardware request into DMAMUX to trigger the DMA transfer accordingly. The index
 * of the hardware request varies according  to the to SoC.
 */
typedef enum {
    EDMA_REQ_MUX_0_DISABLED = 0U,
    EDMA_REQ_SARADC_0_0 = 1U,
    EDMA_REQ_BCTU_2 = 2U,
    EDMA_REQ_ADCSD_0_0_EOC = 3U,
	EDMA_REQ_DECFIL_0_DRAIN = 4U,
	EDMA_REQ_DECFIL_0_FILL = 5U,
	EDMA_REQ_DSPI_0_0_CMD = 6U,
	EDMA_REQ_DSPI_0_0_RX = 7U,
	EDMA_REQ_DSPI_0_0_TX = 8U,
	EDMA_REQ_LINFLEX_0_0_RX = 9U,
	EDMA_REQ_LINFLEX_0_0_TX = 10U,
	EDMA_REQ_SIUL2_REQ0_0 = 11U,
	EDMA_REQ_SIUL2_REQ1 = 12U,
	EDMA_REQ_SIUL2_REQ6 = 13U,
	EDMA_REQ_EMIOS_0_CH8 = 15U,
	EDMA_REQ_EMIOS_0_CH9 = 16U,
	EDMA_REQ_EMIOS_0_CH10 = 17U,
	EDMA_REQ_EMIOS_0_CH11 = 18U,
	EDMA_REQ_EMIOS_0_CH12 = 19U,
	EDMA_REQ_ETPU2_A_CH0_0 = 20U,
	EDMA_REQ_ETPU2_A_CH1_0 = 21U,
	EDMA_REQ_ETPU2_A_CH2_0 = 22U,
	EDMA_REQ_ETPU2_A_CH3 = 23U,
	EDMA_REQ_ETPU2_A_CH4 = 24U,
	EDMA_REQ_ETPU2_A_CH15 = 25U,
	EDMA_REQ_ETPU2_A_CH16 = 26U,
	EDMA_REQ_ETPU2_A_CH17 = 27U,
	EDMA_REQ_ETPU2_A_CH18 = 28U,
	EDMA_REQ_ETPU2_A_CH19 = 29U,
	EDMA_REQ_ETPU2_A_CH30 = 30U,
	EDMA_REQ_ETPU2_A_CH31 = 31U,
	EDMA_REQ_ETPU2_B_CH0_0 = 32U,
	EDMA_REQ_ETPU2_B_CH1_0 = 33U,
	EDMA_REQ_ETPU2_B_CH2_0 = 34U,
	EDMA_REQ_ETPU2_B_CH13 = 35U,
	EDMA_REQ_ETPU2_B_CH14 = 36U,
	EDMA_REQ_ETPU2_B_CH15 = 37U,
	EDMA_REQ_ETPU2_B_CH16 = 38U,
	EDMA_REQ_ETPU2_B_CH17 = 39U,
	EDMA_REQ_ETPU2_B_CH28 = 40U,
	EDMA_REQ_ETPU2_B_CH29 = 41U,
	EDMA_REQ_ETPU2_B_CH30 = 42U,
	EDMA_REQ_ETPU2_B_CH31 = 43U,
	EDMA_REQ_SARADC_2_0 = 44U,
	EDMA_REQ_DSPI_2_0_CMD = 45U,
	EDMA_REQ_DSPI_2_0_RX = 46U,
	EDMA_REQ_DSPI_2_0_TX = 47U,
	EDMA_REQ_SIUL2_REQ4_0 = 48U,
	EDMA_REQ_FLEXCAN_0_0 = 49U,
	EDMA_REQ_REACM_CH0 = 50U,
	EDMA_REQ_REACM_CH3 = 51U,
	EDMA_REQ_REACM_CH6 = 52U,
	EDMA_REQ_REACM_CH7 = 53U,
	EDMA_REQ_MUX_0_ALWAYS_ENABLED_0 = 62U,
	EDMA_REQ_MUX_0_ALWAYS_ENABLED_1 = 63U,
	EDMA_REQ_MUX_1_DISABLED = 64U,
	EDMA_REQ_SARADC_2_1 = 65U,
	EDMA_REQ_BCTU_1_0 = 66U,
	EDMA_REQ_BCTU_3 = 67U,
	EDMA_REQ_DSPI_2_1_CMD = 68U,
	EDMA_REQ_DSPI_2_1_RX = 69U,
	EDMA_REQ_DSPI_2_1_TX = 70U,
	EDMA_REQ_DSPI_M0_CMD = 71U,
	EDMA_REQ_DSPI_M0_RX = 72U,
	EDMA_REQ_DSPI_M0_TX = 73U,
	EDMA_REQ_LINFLEX_M0_RX = 74U,
	EDMA_REQ_LINFLEX_M0_TX = 75U,
	EDMA_REQ_SIUL2_REQ2 = 76U,
	EDMA_REQ_SIUL2_REQ3 = 77U,
	EDMA_REQ_SIUL2_REQ7 = 78U,
	EDMA_REQ_FLEXCAN_2 = 79U,
	EDMA_REQ_EMIOS_0_CH13 = 80U,
	EDMA_REQ_EMIOS_0_CH14 = 81U,
	EDMA_REQ_EMIOS_0_CH15 = 82U,
	EDMA_REQ_EMIOS_0_CH16 = 83U,
	EDMA_REQ_EMIOS_0_CH17 = 84U,
	EDMA_REQ_ETPU2_A_CH5 = 85U,
	EDMA_REQ_ETPU2_A_CH6 = 86U,
	EDMA_REQ_ETPU2_A_CH7 = 87U,
	EDMA_REQ_ETPU2_A_CH8 = 88U,
	EDMA_REQ_ETPU2_A_CH9 = 89U,
	EDMA_REQ_ETPU2_A_CH20 = 90U,
	EDMA_REQ_ETPU2_A_CH21 = 91U,
	EDMA_REQ_ETPU2_A_CH22 = 92U,
	EDMA_REQ_ETPU2_A_CH23 = 93U,
	EDMA_REQ_ETPU2_A_CH24 = 94U,
	EDMA_REQ_ETPU2_B_CH3 = 95U,
	EDMA_REQ_ETPU2_B_CH4 = 96U,
	EDMA_REQ_ETPU2_B_CH5 = 97U,
	EDMA_REQ_ETPU2_B_CH6 = 98U,
	EDMA_REQ_ETPU2_B_CH7 = 99U,
	EDMA_REQ_ETPU2_B_CH18 = 100U,
	EDMA_REQ_ETPU2_B_CH19 = 101U,
	EDMA_REQ_ETPU2_B_CH20 = 102U,
	EDMA_REQ_ETPU2_B_CH21 = 103U,
	EDMA_REQ_ETPU2_B_CH22 = 104U,
	EDMA_REQ_BCTU_0_0 = 105U,
	EDMA_REQ_ADCSD_0_1_EOC = 106U,
	EDMA_REQ_LINFLEX_0_1_RX = 107U,
	EDMA_REQ_LINFLEX_0_1_TX = 108U,
	EDMA_REQ_LINFLEX_2_0_RX = 109U,
	EDMA_REQ_LINFLEX_2_0_TX = 110U,
	EDMA_REQ_SENT_0_0_RX_FAST = 111U,
	EDMA_REQ_SENT_0_0_RX_SLOW = 112U,
	EDMA_REQ_ETPU2_B_CH0_1 = 113U,
	EDMA_REQ_ETPU2_B_CH1_1 = 114U,
	EDMA_REQ_ETPU2_B_CH2_1 = 115U,
	EDMA_REQ_REACM_CH1 = 116U,
	EDMA_REQ_REACM_CH4 = 117U,
	EDMA_REQ_MUX_1_ALWAYS_ENABLED_0 = 127U,
	EDMA_REQ_MUX_2_DISABLED = 128U,
	EDMA_REQ_BCTU_0_1 = 129U,
	EDMA_REQ_ADCSD_2_EOC = 130U,
	EDMA_REQ_DECFIL_1_DRAIN = 131U,
	EDMA_REQ_DECFIL_1_FILL = 132U,
	EDMA_REQ_DSPI_4_CMD = 133U,
	EDMA_REQ_DSPI_4_RX = 134U,
	EDMA_REQ_DSPI_4_TX = 135U,
	EDMA_REQ_LINFLEX_2_1_RX = 136U,
	EDMA_REQ_LINFLEX_2_1_TX = 137U,
	EDMA_REQ_SENT_0_1_RX_FAST = 138U,
	EDMA_REQ_SENT_0_1_RX_SLOW = 139U,
	EDMA_REQ_SIUL2_REQ4_1 = 140U,
	EDMA_REQ_SIUL2_REQ5 = 141U,
	EDMA_REQ_FLEXCAN_0_1 = 142U,
	EDMA_REQ_EMIOS_0_CH18 = 143U,
	EDMA_REQ_EMIOS_0_CH19 = 144U,
	EDMA_REQ_EMIOS_0_CH20 = 145U,
	EDMA_REQ_EMIOS_0_CH21 = 146U,
	EDMA_REQ_EMIOS_0_CH22 = 147U,
    EDMA_REQ_EMIOS_0_CH23 = 148U,
	EDMA_REQ_ETPU2_A_CH10 = 149U,
	EDMA_REQ_ETPU2_A_CH11 = 150U,
	EDMA_REQ_ETPU2_A_CH12 = 151U,
	EDMA_REQ_ETPU2_A_CH13 = 152U,
	EDMA_REQ_ETPU2_A_CH14 = 153U,
	EDMA_REQ_ETPU2_A_CH25 = 154U,
	EDMA_REQ_ETPU2_A_CH26 = 155U,
	EDMA_REQ_ETPU2_A_CH27 = 156U,
	EDMA_REQ_ETPU2_A_CH28 = 157U,
	EDMA_REQ_ETPU2_A_CH29 = 158U,
	EDMA_REQ_ETPU2_B_CH8 = 159U,
	EDMA_REQ_ETPU2_B_CH9 = 160U,
	EDMA_REQ_ETPU2_B_CH10 = 161U,
	EDMA_REQ_ETPU2_B_CH11 = 162U,
	EDMA_REQ_ETPU2_B_CH12 = 163U,
	EDMA_REQ_ETPU2_B_CH23 = 164U,
	EDMA_REQ_ETPU2_B_CH24 = 165U,
	EDMA_REQ_ETPU2_B_CH25 = 166U,
	EDMA_REQ_ETPU2_B_CH26 = 167U,
	EDMA_REQ_ETPU2_B_CH27 = 168U,
	EDMA_REQ_SARADC_0_1 = 169U,
	EDMA_REQ_BCTU_1_1 = 170U,
	EDMA_REQ_DSPI_0_1_CMD = 171U,
	EDMA_REQ_DSPI_0_1_RX = 172U,
	EDMA_REQ_DSPI_0_1_TX = 173U,
	EDMA_REQ_SIUL2_REQ0_1 = 174U,
	EDMA_REQ_ETPU2_A_CH0_1 = 175U,
	EDMA_REQ_ETPU2_A_CH1_1 = 176U,
	EDMA_REQ_ETPU2_A_CH2_1 = 177U,
	EDMA_REQ_REACM_CH2 = 178U,
	EDMA_REQ_REACM_CH5 = 179U,
	EDMA_REQ_REACM_CH8 = 180U,
	EDMA_REQ_REACM_CH9 = 181U,
	EDMA_REQ_MUX_2_ALWAYS_ENABLED_0 = 191U,
	EDMA_REQ_MUX_3_DISABLED = 192U,
	EDMA_REQ_SARADC_1 = 193U,
	EDMA_REQ_SARADC_3 = 194U,
	EDMA_REQ_ADCSD_1_EOC = 195U,
	EDMA_REQ_DSPI_1_CMD = 196U,
	EDMA_REQ_DSPI_1_RX = 197U,
	EDMA_REQ_DSPI_1_TX = 198U,
	EDMA_REQ_DSPI_3_CMD = 199U,
	EDMA_REQ_DSPI_3_RX = 200U,
	EDMA_REQ_DSPI_3_TX = 201U,
	EDMA_REQ_DSPI_M1_CMD = 202U,
	EDMA_REQ_DSPI_M1_RX = 203U,
	EDMA_REQ_DSPI_M1_TX = 204U,
	EDMA_REQ_LINFLEX_1_RX = 205U,
	EDMA_REQ_LINFLEX_1_TX = 206U,
	EDMA_REQ_LINFLEX_3_RX = 207U,
	EDMA_REQ_LINFLEX_3_TX = 208U,
	EDMA_REQ_LINFLEX_M1_RX = 209U,
	EDMA_REQ_LINFLEX_M1_TX = 210U,
	EDMA_REQ_SENT_1_RX_FAST = 211U,
	EDMA_REQ_SENT_1_RX_SLOW = 212U,
	EDMA_REQ_SIPI_CH0 = 213U,
	EDMA_REQ_SIPI_CH1 = 214U,
	EDMA_REQ_SIPI_CH2 = 215U,
	EDMA_REQ_SIPI_CH3 = 216U,
	EDMA_REQ_FLEXCAN_1 = 217U,
	EDMA_REQ_FLEXCAN_3 = 218U,
	EDMA_REQ_EMIOS_1_CH8 = 219U,
	EDMA_REQ_EMIOS_1_CH9 = 220U,
	EDMA_REQ_EMIOS_1_CH10 = 221U,
	EDMA_REQ_EMIOS_1_CH11 = 222U,
	EDMA_REQ_EMIOS_1_CH12 = 223U,
	EDMA_REQ_EMIOS_1_CH13 = 224U,
	EDMA_REQ_EMIOS_1_CH14 = 225U,
	EDMA_REQ_EMIOS_1_CH15 = 226U,
	EDMA_REQ_EMIOS_1_CH16 = 227U,
	EDMA_REQ_EMIOS_1_CH17 = 228U,
	EDMA_REQ_EMIOS_1_CH18 = 229U,
	EDMA_REQ_EMIOS_1_CH19 = 230U,
	EDMA_REQ_EMIOS_1_CH20 = 231U,
	EDMA_REQ_EMIOS_1_CH21 = 232U,
	EDMA_REQ_EMIOS_1_CH22 = 233U,
	EDMA_REQ_EMIOS_1_CH23 = 234U
} dma_request_source_t;

/* EIM module features */

/* @brief The EIM check-bit mask has 32 bits */
#define FEATURE_EIM_CHECKBITMASK_32BIT
/* @brief The EIM has data mask 1 */
#define FEATURE_EIM_DATAMASK1
/* @brief The EIM channel types */
#define FEATURE_EIM_CH_TYPE_0 (0U)
/* @brief The EIM channel type structure */
#define FEATURE_EIM_CH_TYPE \
{                                \
FEATURE_EIM_CH_TYPE_0,         /* Channel type corresponding to channel 0  */       \
}
/* @brief The EIM number of data words for each channel type  */
#define FEATURE_EIM_CH_TYPE_0_NUM_OF_DATA_WORDS (2U)
/* @brief The EIM WORD0 bitfields for each channel type  */
#define FEATURE_EIM_CH_TYPE_0_WORD0_MASK      0xFE000000u
#define FEATURE_EIM_CH_TYPE_0_WORD0_SHIFT     25u
#define FEATURE_EIM_CH_TYPE_0_WORD0_WRITE(x)  (((uint32_t)(((uint32_t)(x))<<FEATURE_EIM_CH_TYPE_0_WORD0_SHIFT))&FEATURE_EIM_CH_TYPE_0_WORD0_MASK)
#define FEATURE_EIM_CH_TYPE_0_WORD0_READ(x)   (((uint32_t)(((uint32_t)(x))&FEATURE_EIM_CH_TYPE_0_WORD0_MASK))>>FEATURE_EIM_CH_TYPE_0_WORD0_SHIFT)
/* @brief The EIM WORD1 bitfields for each channel type  */
#define FEATURE_EIM_CH_TYPE_0_WORD1_MASK      0xFFFFFFFFu
#define FEATURE_EIM_CH_TYPE_0_WORD1_SHIFT     0u
#define FEATURE_EIM_CH_TYPE_0_WORD1_WRITE(x)  (((uint32_t)(((uint32_t)(x))<<FEATURE_EIM_CH_TYPE_0_WORD1_SHIFT))&FEATURE_EIM_CH_TYPE_0_WORD1_MASK)
#define FEATURE_EIM_CH_TYPE_0_WORD1_READ(x)   (((uint32_t)(((uint32_t)(x))&FEATURE_EIM_CH_TYPE_0_WORD1_MASK))>>FEATURE_EIM_CH_TYPE_0_WORD1_SHIFT)
/* @brief The EIM WORD2 bitfields for each channel type  */
#define FEATURE_EIM_CH_TYPE_0_WORD2_MASK      0xFFFFFFFFu
#define FEATURE_EIM_CH_TYPE_0_WORD2_SHIFT     0u
#define FEATURE_EIM_CH_TYPE_0_WORD2_WRITE(x)  (((uint32_t)(((uint32_t)(x))<<FEATURE_EIM_CH_TYPE_0_WORD2_SHIFT))&FEATURE_EIM_CH_TYPE_0_WORD2_MASK)
#define FEATURE_EIM_CH_TYPE_0_WORD2_READ(x)   (((uint32_t)(((uint32_t)(x))&FEATURE_EIM_CH_TYPE_0_WORD2_MASK))>>FEATURE_EIM_CH_TYPE_0_WORD2_SHIFT)

/* BCTU (Body Cross Triggering Unit) module features */
/*! @brief Number of ADC instances which can be triggered by BCTU */
#define FEATURE_BCTU_NUM_ADC            (4U)
#define FEATURE_BCTU_HAS_CCP            (1U)

/* ADC module features */
#define FEATURE_ADC_HAS_CTU              (1)
#define FEATURE_ADC_HAS_CTU_TRIGGER_MODE (1)
#define FEATURE_ADC_HAS_EXT_TRIGGER      (1)
#define FEATURE_ADC_HAS_INJ_TRIGGER_SEL  (0)
#define FEATURE_ADC_HAS_THRHLR_ARRAY     (1)
#define FEATURE_ADC_HAS_CALIBRATION_ALT  (0)
#define FEATURE_ADC_HAS_CLKSEL_EXTENDED  (0)

#define FEATURE_ADC_HAS_CWSELR_UNROLLED  (1)
#define FEATURE_ADC_HAS_CWSELR0          (1)
#define FEATURE_ADC_HAS_CWSELR1          (1)
#define FEATURE_ADC_HAS_CWSELR2          (1)
#define FEATURE_ADC_HAS_CWSELR3          (1)
#define FEATURE_ADC_HAS_CWSELR4          (1)
#define FEATURE_ADC_HAS_CWSELR5          (0)
#define FEATURE_ADC_HAS_CWSELR6          (0)
#define FEATURE_ADC_HAS_CWSELR7          (0)
#define FEATURE_ADC_HAS_CWSELR8          (1)
#define FEATURE_ADC_HAS_CWSELR9          (1)
#define FEATURE_ADC_HAS_CWSELR10         (1)
#define FEATURE_ADC_HAS_CWSELR11         (1)

#define FEATURE_ADC_BAD_ACCESS_PROT_CHANNEL  (1)
                                      /* 31-28   3-0  63-60  35-32 95-92  68-65
                                          \_/    \_/   \_/    \_/   \_/    \_/
                                           |......|     |......|     |......| */
#define FEATURE_ADC_CHN_AVAIL_BITMAP   {{0xFFFFFFFFu, 0x0000007Fu, 0x00000000u}, /* ADC0 */ \
                                        {0xFFFFFFFFu, 0x0000003Fu, 0x00000000u}, /* ADC1 */ \
                                        {0xFFFFFFFFu, 0x0000000Fu, 0x00000000u}, /* ADC2 */ \
                                        {0x001FFFFFu, 0x0000003Du, 0xFFFFFFFFu}} /* ADC3 */

#define FEATURE_ADC_BAD_ACCESS_PROT_FEATURE  (1)
#define FEATURE_ADC_FEAT_AVAIL_BITMAP  {0xFFFFFFFCu,  /* ADC0 */ \
                                        0xFFFFFFFEu,  /* ADC1 */ \
                                        0xFFFFFFFEu,  /* ADC2 */ \
                                        0xFFFFFFFFu}  /* ADC3 */

/* @brief Default values for sample time. */
#define ADC_DEF_SAMPLE_TIME_0           (0x14U)
#define ADC_DEF_SAMPLE_TIME_1           (0x14U)
#define ADC_DEF_SAMPLE_TIME_2           (0x14U)

/* SDADC module features */
/*! @brief SDADC module has instance 0 */
#define FEATURE_SDADC_HAS_INSTANCE_0      (1u)

/*! @brief SUIL IMCR register number for SDADC input trigger configuring */
#define TRIGGER_IMCR_REGISTER_NUMBERS     {456u, 457u, 458u}
/*! @brief SUIL IMCR register number for SDADC DMA/Interrupt gating configuring */
#define GATE_IMCR_REGISTER_NUMBERS        {448u, 449u, 450u}
/* @brief Max of SDADC clock frequency */
#define SDADC_CLOCK_FREQ_MAX_RUNTIME     (16000000u)
/* @brief Min of SDADC clock frequency */
#define SDADC_CLOCK_FREQ_MIN_RUNTIME     (4000000u)
/*! @brief SDADC instances number */
#define FEATURE_SDADC_HAS_INSTANCE_NUMBER    (3u)
/*! @brief SDADC initial gain error table */
#define SDADC_GAIN_ERROR   {65536, 65536, 65536}
/*! @brief DMA channel number for SDADC instances */
#define SDADC_DMA_CHANNEL_NUMBER   {0xFFu, 0xFFu, 0xFFu}
/*! @brief Interrupts from all SDADC instances are mapped to a single interrupt vector */
#define FEATURE_SDADC_INSTANCES_HAVE_COMMON_INT_VECTOR  (0)


/* ADC PAL features */

#define ADC_PAL_BCTU_CONV_UPDATE_IRQ_UNROLLED           (1)


/* SIUL2 module feature */
/*! @brief SIUL2 module external interrupt support DMA */
#define FEATURE_SIUL2_EXTERNAL_INT_SUPPORT_DMA          (1)
/*! @brief SIUL2 module support Analog Pad */
#define FEATURE_SIUL2_HAS_ANALOG_PAD                    (1)
/*! @brief SIUL2 module Slew rate combine with Drive strength */
#define FEATURE_SIUL2_HAS_SLEW_RATE_WITH_DRIVE_STRENGTH (1)

/*! @brief SIUL2 module input mux numbers */
#define FEATURE_SIUL2_INPUT_MUX_WIDTH                   (16U)
/*! @brief SIUL2 module has specific pull register */
#define FEATURE_SIUL2_HAS_SPECIFIC_PULL_REGISTER        (1U)
/*! @brief SIUL2 module has input level selection */
#define FEATURE_SIUL2_HAS_INPUT_LEVEL_SELECTION         (1U)
/*! @brief SIUL2 module has output drive control */
#define FEATURE_SIUL2_HAS_OUTPUT_DRIVE_CONTROL          (1U)
/*! @brief SIUL2 module has weak pull enable */
#define FEATURE_SIUL2_HAS_WEAK_PULL_ENABLE              (1U)


/** Number of instances of the SIUL2 module. */
#define GPIO_INSTANCE_COUNT (10u)

/* SIUL2 - Peripheral instance base addresses */
/** Peripheral SIUL2 base address */
#define GPIO_BASE                                (0xFFFC1700u)
/** Peripheral SIUL2 base pointer */
#define GPIO                                     ((GPIO_Type *)GPIO_BASE)

/* GPIO - Peripheral instance base addresses */
/** Peripheral PTA base address */
#define PTA_BASE                                 (0xFFFC1700u)
/** Peripheral PTA base pointer */
#define PTA                                      ((GPIO_Type *)PTA_BASE)
/** Peripheral PTB base address */
#define PTB_BASE                                 (0xFFFC1702u)
/** Peripheral PTB base pointer */
#define PTB                                      ((GPIO_Type *)PTB_BASE)
/** Peripheral PTC base address */
#define PTC_BASE                                 (0xFFFC1704u)
/** Peripheral PTC base pointer */
#define PTC                                      ((GPIO_Type *)PTC_BASE)
/** Peripheral PTD base address */
#define PTD_BASE                                 (0xFFFC1706u)
/** Peripheral PTD base pointer */
#define PTD                                      ((GPIO_Type *)PTD_BASE)
/** Peripheral PTE base address */
#define PTE_BASE                                 (0xFFFC1708u)
/** Peripheral PTE base pointer */
#define PTE                                      ((GPIO_Type *)PTE_BASE)
/** Peripheral PTF base address */
#define PTF_BASE                                 (0xFFFC170Au)
/** Peripheral PTF base pointer */
#define PTF                                      ((GPIO_Type *)PTF_BASE)
/** Peripheral PTG base address */
#define PTG_BASE                                 (0xFFFC170Cu)
/** Peripheral PTG base pointer */
#define PTG                                      ((GPIO_Type *)PTG_BASE)
/** Peripheral PTH base address */
#define PTH_BASE                                 (0xFFFC170Eu)
/** Peripheral PTH base pointer */
#define PTH                                      ((GPIO_Type *)PTH_BASE)
/** Peripheral PTI base address */
#define PTI_BASE                                 (0xFFFC1710u)
/** Peripheral PTI base pointer */
#define PTI                                      ((GPIO_Type *)PTI_BASE)
/** Peripheral PTJ base address */
#define PTJ_BASE                                 (0xFFFC1712u)
/** Peripheral PTJ base pointer */
#define PTJ                                      ((GPIO_Type *)PTJ_BASE)
/** Peripheral PTK base address */
#define PTK_BASE                                 (0xFFFC1714u)
/** Peripheral PTK base pointer */
#define PTK                                      ((GPIO_Type *)PTK_BASE)
/** Peripheral PTL base address */
#define PTL_BASE                                 (0xFFFC1716u)
/** Peripheral PTL base pointer */
#define PTL                                      ((GPIO_Type *)PTL_BASE)
/** Peripheral PTW base address */
#define PTW_BASE                                 (0xFFFC1718u)
/** Peripheral PTW base pointer */
#define PTW                                      ((GPIO_Type *)PTW_BASE)
/** Peripheral PTX base address */
#define PTX_BASE                                 (0xFFFC171Au)
/** Peripheral PTX base pointer */
#define PTX                                      ((GPIO_Type *)PTX_BASE)
/** Peripheral PTY base address */
#define PTY_BASE                                 (0xFFFC171Cu)
/** Peripheral PTY base pointer */
#define PTY                                      ((GPIO_Type *)PTY_BASE)
/** Peripheral PTZ base address */
#define PTZ_BASE                                 (0xFFFC171Eu)
/** Peripheral PTZ base pointer */
#define PTZ                                      ((GPIO_Type *)PTZ_BASE)

/** Array initializer of GPIO peripheral base addresses */
#define GPIO_BASE_ADDRS                          { PTA_BASE, PTB_BASE, PTC_BASE, PTD_BASE, \
                                                   PTE_BASE, PTF_BASE, PTG_BASE, PTH_BASE, \
                                                   PTI_BASE, PTJ_BASE, PTK_BASE, PTL_BASE, \
                                                   PTW_BASE, PTX_BASE, PTY_BASE, PTZ_BASE }
/** Array initializer of GPIO peripheral base pointers */
#define GPIO_BASE_PTRS                           { PTA, PTB, PTC, PTD, PTE, PTF, PTG, PTH, \
                                                   PTI, PTJ, PTK, PTL, PTW, PTX, PTY, PTZ }

#define SIUL2_MSCR_BASE                          (SIUL2->MSCR)
#define SIUL2_IMCR_BASE                          (SIUL2->IMCR)
#define PORTA                                    ((PORT_Type *)(SIUL2_MSCR_BASE+0x00))
#define PORTB                                    ((PORT_Type *)(SIUL2_MSCR_BASE+0x10))
#define PORTC                                    ((PORT_Type *)(SIUL2_MSCR_BASE+0x20))
#define PORTD                                    ((PORT_Type *)(SIUL2_MSCR_BASE+0x30))
#define PORTE                                    ((PORT_Type *)(SIUL2_MSCR_BASE+0x40))
#define PORTF                                    ((PORT_Type *)(SIUL2_MSCR_BASE+0x50))
#define PORTG                                    ((PORT_Type *)(SIUL2_MSCR_BASE+0x60))
#define PORTH                                    ((PORT_Type *)(SIUL2_MSCR_BASE+0x70))
#define PORTI                                    ((PORT_Type *)(SIUL2_MSCR_BASE+0x80))
#define PORTJ                                    ((PORT_Type *)(SIUL2_MSCR_BASE+0x90))
#define PORTK                                    ((PORT_Type *)(SIUL2_MSCR_BASE+0xA0))
#define PORTL                                    ((PORT_Type *)(SIUL2_MSCR_BASE+0xB0))
#define PORTW                                    ((PORT_Type *)(SIUL2_MSCR_BASE+0xC0))
#define PORTX                                    ((PORT_Type *)(SIUL2_MSCR_BASE+0xD0))
#define PORTY                                    ((PORT_Type *)(SIUL2_MSCR_BASE+0xE0))
#define PORTZ                                    ((PORT_Type *)(SIUL2_MSCR_BASE+0xF0))
#define PORT_BASE_PTRS                           { PORTA, PORTB, PORTC, PORTD, PORTE, PORTF, \
                                                   PORTG, PORTH, PORTI, PORTJ, PORTK, PORTL, \
                                                   PORTW, PORTX, PORTY, PORTZ }

/** Define specific pins, which have general purpose pull */
#define PTY0                                     (0U)
#define PTY1                                     (1U)
#define PTY2                                     (2U)
#define PTY3                                     (3U)
#define PTZ0                                     (4U)
#define PTZ1                                     (5U)
#define PTZ2                                     (6U)
#define PTZ3                                     (7U)
#define PTZ4                                     (8U)
#define PTZ5                                     (9U)
#define PTZ6                                     (10U)
#define PTZ7                                     (11U)
#define PTZ8                                     (12U)
#define PTZ9                                     (13U)
#define PTZ10                                    (14U)
#define PTZ11                                    (15U)
#define PTZ12                                    (16U)
#define PTZ13                                    (17U)
#define PTZ14                                    (18U)
#define PTZ15                                    (19U)

/* DSPI module feature */

/* Define the PCS allocation for each DSPI/SPI module */
#define FEATURE_DSPI_0_PCS_NUMBER  6
#define FEATURE_DSPI_1_PCS_NUMBER  5
#define FEATURE_DSPI_2_PCS_NUMBER  4
#define FEATURE_DSPI_3_PCS_NUMBER  6
#define FEATURE_DSPI_4_PCS_NUMBER  6
#define FEATURE_DSPI_M0_PCS_NUMBER 4
#define FEATURE_DSPI_M1_PCS_NUMBER 4

#define FEATURE_DSPI_PCS_MAPPING {FEATURE_DSPI_0_PCS_NUMBER, FEATURE_DSPI_1_PCS_NUMBER, FEATURE_DSPI_2_PCS_NUMBER, \
                                  FEATURE_DSPI_3_PCS_NUMBER, FEATURE_DSPI_4_PCS_NUMBER, FEATURE_DSPI_M0_PCS_NUMBER, FEATURE_DSPI_M1_PCS_NUMBER}


/* Define the initial values for state structures */
#define FEATURE_DSPI_INITIAL_STATE {NULL, NULL, NULL, NULL, NULL, NULL, NULL}


/* Define margins of instances interval */
#define DSPI_LOWEST_INSTANCE  0U
#define DSPI_HIGHEST_INSTANCE 6U

/* Define FIFO size */
#define DSPI_FIFO_SIZE 4U

/* Each interrupt flag has it's own interrupt index */
#define FEATURES_DSPI_HAS_INDEPENDENT_INTERRUPTS 0U

/* On this platform DSPI in extended mode is supported */
#define FEATURE_DSPI_HAS_EXTENDED_MODE 0U

/* Define number of DSPI instances */
#define SPI_INSTANCE_COUNT         0U



/* Has nibble length limit */
#define FEATURE_SRX_HAS_NIB_LEN_VAR_LIMIT

/* Mappings */
#define FEATURE_SRX_FAST_DMA_REQS {EDMA_REQ_SENT_0_0_RX_FAST, EDMA_REQ_SENT_1_RX_FAST}
#define FEATURE_SRX_SLOW_DMA_REQS {EDMA_REQ_SENT_0_0_RX_SLOW, EDMA_REQ_SENT_1_RX_SLOW}


/* ENET module features */


/*! @brief The maximum supported frequency for MDC, in Hz. */
#define FEATURE_ENET_MDC_MAX_FREQUENCY 2500000U

/*! @brief Minimum hold time on the MDIO output, in nanoseconds. */
#define FEATURE_ENET_MDIO_MIN_HOLD_TIME_NS 10U

/*! @brief Definitions used for aligning the data buffers */
#define FEATURE_ENET_BUFF_ALIGNMENT      (16UL)
/*! @brief Definitions used for aligning the buffer descriptors */
#define FEATURE_ENET_BUFFDESCR_ALIGNMENT (64UL)

/*! @brief Has receive frame parser feature. */
#define FEATURE_ENET_HAS_RECEIVE_PARSER (0)

/*! @brief Has enhanced buffer descriptors programming model. */
#define FEATURE_ENET_HAS_ENHANCED_BD    (0)

/*! @brief Default configuration for the PHY interface */
#define FEATURE_ENET_DEFAULT_PHY_IF     ENET_RMII_MODE

/*! @brief Has adjustable timer enabling IEEE 1588 support */
#define FEATURE_ENET_HAS_ADJUSTABLE_TIMER (0)

/*! @brief Has support for configuring the width of the output compare pulse */
#define FEATURE_ENET_HAS_TIMER_PULSE_WIDTH_CONTROL (0)

/*! @brief The number of available receive and transmit buffer descriptor rings */
#define FEATURE_ENET_RING_COUNT             (1U)

/*! @brief The number of available VLAN priority compare values per class */
#define FEATURE_ENET_CLASS_MATCH_CMP_COUNT  (0U)

/*! @brief Has credit-based shaper */
#define FEATURE_ENET_HAS_CBS                (0)

/*! @brief Has time-based shaper */
#define FEATURE_ENET_HAS_TBS                (0)

/*! @brief Has interrupt coalescing */
#define FEATURE_ENET_HAS_INTCOAL            (0)

/*! @brief Has RGMII mode for data interface */
#define FEATURE_ENET_HAS_RGMII              (0)

/*! @brief Has 1000-Mbit/s speed mode */
#define FEATURE_ENET_HAS_SPEED_1000M        (0)

/*! @brief Has Receive and Transmit accelerator */
#define FEATURE_ENET_HAS_ACCELERATOR		(0)

/*! @brief Has Sleep and Wakeup functionalities */
#define FEATURE_ENET_HAS_SLEEP_WAKEUP		(0)

/*! @brief Has configurable FIFO thresholds */
#define FEATURE_ENET_HAS_CONFIG_FIFO_THRESHOLDS	(0)

/*! @brief RX Configuration features */
#define FEATURE_ENET_HAS_RX_CONFIG					(1)
#define FEATURE_ENET_RX_CONFIG_PAYLOAD_LEN_CHECK	(0)
#define FEATURE_ENET_RX_CONFIG_STRIP_CRC_FIELD		(0)
#define FEATURE_ENET_RX_CONFIG_REMOVE_PADDING		(0)
#define FEATURE_ENET_RX_CONFIG_FORWARD_PAUSE_FRAMES	(0)

/*! @brief TX Configuration features */
#define FEATURE_ENET_HAS_TX_CONFIG	(0)

/*! @brief Offset of the MIB block counters area in bytes */
#define FEATURE_ENET_MIB_COUNTERS_OFFSET	(0x200U)
/*! @brief Size of the MIB block counters area in words */
#define FEATURE_ENET_MIB_COUNTERS_SIZE		(0x80U)

/*! @brief The minimum size of the Tx ring */
#define FEATURE_ENET_TX_MIN_RING_SIZE       (2U)

#define     __IO    volatile             /*!< Defines 'read / write' permissions              */
#define   __I     volatile const       /*!< Defines 'read only' permissions                 */

/** FEC - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[4];
  __IO uint32_t EIR;                               /**< Interrupt Event Register, offset: 0x4 */
  __IO uint32_t EIMR;                              /**< Interrupt Mask Register, offset: 0x8 */
       uint8_t RESERVED_1[4];
  __IO uint32_t RDAR;                              /**< Receive Descriptor Active Register, offset: 0x10 */
  __IO uint32_t TDAR;                              /**< Transmit Descriptor Active Register, offset: 0x14 */
       uint8_t RESERVED_2[12];
  __IO uint32_t ECR;                               /**< Ethernet Control Register, offset: 0x24 */
       uint8_t RESERVED_3[24];
  __IO uint32_t MMFR;                              /**< MII Management Frame Register, offset: 0x40 */
  __IO uint32_t MSCR;                              /**< MII Speed Control Register, offset: 0x44 */
       uint8_t RESERVED_4[28];
  __IO uint32_t MIBC;                              /**< MIB Control Register, offset: 0x64 */
       uint8_t RESERVED_5[28];
  __IO uint32_t RCR;                               /**< Receive Control Register, offset: 0x84 */
       uint8_t RESERVED_6[60];
  __IO uint32_t TCR;                               /**< Transmit Control Register, offset: 0xC4 */
       uint8_t RESERVED_7[28];
  __IO uint32_t PALR;                              /**< Physical Address Low Register, offset: 0xE4 */
  __IO uint32_t PAUR;                              /**< Physical Address High Register and Type Field, offset: 0xE8 */
  __IO uint32_t OPD;                               /**< Opcode/Pause Duration, offset: 0xEC */
       uint8_t RESERVED_8[40];
  __IO uint32_t IAUR;                              /**< Descriptor Individual Upper Address Register, offset: 0x118 */
  __IO uint32_t IALR;                              /**< Descriptor Individual Lower Address Register, offset: 0x11C */
  __IO uint32_t GAUR;                              /**< Descriptor Group Upper Address Register, offset: 0x120 */
  __IO uint32_t GALR;                              /**< Descriptor Group Lower Address Register, offset: 0x124 */
       uint8_t RESERVED_9[28];
  __IO uint32_t TFWR;                              /**< Transmit FIFO Watermark, offset: 0x144 */
       uint8_t RESERVED_10[4];
  __I  uint32_t FRBR;                              /**< FIFO Receive Bound Register, offset: 0x14C */
  __IO uint32_t FRSR;                              /**< FIFO Receive Start Register, offset: 0x150 */
       uint8_t RESERVED_11[44];
  __IO uint32_t ERDSR;                             /**< Receive Descriptor Ring Start Register, offset: 0x180 */
  __IO uint32_t ETDSR;                             /**< Transmit Buffer Descriptor Ring Start Register, offset: 0x184 */
  __IO uint32_t EMRBR;                             /**< Receive Buffer Size Register, offset: 0x188 */
       uint8_t RESERVED_12[116];
  __IO uint32_t RMON_T_DROP;                       /**< Count of frames not counted correctly, offset: 0x200 */
  __IO uint32_t RMON_T_PACKETS;                    /**< RMON Tx packet count, offset: 0x204 */
  __IO uint32_t RMON_T_BC_PKT;                     /**< RMON Tx broadcast packets, offset: 0x208 */
  __IO uint32_t RMON_T_MC_PKT;                     /**< RMON Tx multicast packets, offset: 0x20C */
  __IO uint32_t RMON_T_CRC_ALIGN;                  /**< RMON Tx packets with CRC/align error, offset: 0x210 */
  __IO uint32_t RMON_T_UNDERSIZE;                  /**< RMON Tx packets < 64 bytes, good CRC, offset: 0x214 */
  __IO uint32_t RMON_T_OVERSIZE;                   /**< RMON Tx packets > MAX_FL bytes, good CRC, offset: 0x218 */
  __IO uint32_t RMON_T_FRAG;                       /**< RMON Tx packets < 64 bytes, bad CRC, offset: 0x21C */
  __IO uint32_t RMON_T_JAB;                        /**< RMON Tx packets > MAX_FL bytes, bad CRC, offset: 0x220 */
  __IO uint32_t RMON_T_COL;                        /**< RMON Tx collision count, offset: 0x224 */
  __IO uint32_t RMON_T_P64;                        /**< RMON Tx 64 byte packets, offset: 0x228 */
  __IO uint32_t RMON_T_P65TO127;                   /**< RMON Tx 65 to 127 byte packets, offset: 0x22C */
  __IO uint32_t RMON_T_P128TO255;                  /**< RMON Tx 128 to 255 byte packets, offset: 0x230 */
  __IO uint32_t RMON_T_P256TO511;                  /**< RMON Tx 256 to 511 byte packets, offset: 0x234 */
  __IO uint32_t RMON_T_P512TO1023;                 /**< RMON Tx 512 to 1023 byte packets, offset: 0x238 */
  __IO uint32_t RMON_T_P1024TO2047;                /**< RMON Tx 1024 to 2047 byte packets, offset: 0x23C */
  __IO uint32_t RMON_T_P_GTE2048;                  /**< RMON Tx packets with > 2048 bytes, offset: 0x240 */
  __IO uint32_t RMON_T_OCTETS;                     /**< RMON Tx Octets, offset: 0x244 */
  __IO uint32_t IEEE_T_DROP;                       /**< Count of transmitted frames not counted correctly, offset: 0x248 */
  __IO uint32_t IEEE_T_FRAME_OK;                   /**< Frames transmitted OK, offset: 0x24C */
  __IO uint32_t IEEE_T_1COL;                       /**< Frames transmitted with single collision, offset: 0x250 */
  __IO uint32_t IEEE_T_MCOL;                       /**< Frames transmitted with multiple collisions, offset: 0x254 */
  __IO uint32_t IEEE_T_DEF;                        /**< Frames transmitted after deferral delay, offset: 0x258 */
  __IO uint32_t IEEE_T_LCOL;                       /**< Frames transmitted with late collision, offset: 0x25C */
  __IO uint32_t IEEE_T_EXCOL;                      /**< Frames transmitted with excessive collisions, offset: 0x260 */
  __IO uint32_t IEEE_T_MACERR;                     /**< Frames transmitted with Tx FIFO underrun, offset: 0x264 */
  __IO uint32_t IEEE_T_CSERR;                      /**< Frames transmitted with carrier sense error, offset: 0x268 */
  __IO uint32_t IEEE_T_SQE;                        /**< Frames transmitted with SQE error, offset: 0x26C */
  __IO uint32_t IEEE_T_FDXFC;                      /**< Flow control pause frames transmitted, offset: 0x270 */
  __IO uint32_t IEEE_T_OCTETS_OK;                  /**< Octet count for frames transmitted without error, offset: 0x274 */
       uint8_t RESERVED_13[8];
  __IO uint32_t RMON_R_DROP;                       /**< Count of received frames not counted correctly, offset: 0x280 */
  __IO uint32_t RMON_R_PACKETS;                    /**< RMON Rx packet count, offset: 0x284 */
  __IO uint32_t RMON_R_BC_PKT;                     /**< RMON Rx broadcast packets, offset: 0x288 */
  __IO uint32_t RMON_R_MC_PKT;                     /**< RMON Rx multicast packets, offset: 0x28C */
  __IO uint32_t RMON_R_CRC_ALIGN;                  /**< RMON Rx packets with CRC/Align error, offset: 0x290 */
  __IO uint32_t RMON_R_UNDERSIZE;                  /**< RMON Rx packets < 64 bytes, good CRC, offset: 0x294 */
  __IO uint32_t RMON_R_OVERSIZE;                   /**< RMON Rx packets > MAX_FL bytes, good CRC, offset: 0x298 */
  __IO uint32_t RMON_R_FRAG;                       /**< RMON Rx packets < 64 bytes, bad CRC, offset: 0x29C */
  __IO uint32_t RMON_R_JAB;                        /**< RMON Rx packets > MAX_FL bytes, bad CRC, offset: 0x2A0 */
  __IO uint32_t RMON_R_RESVD_0;                    /**< Reserved, offset: 0x2A4 */
  __IO uint32_t RMON_R_P64;                        /**< RMON Rx 64 byte packets, offset: 0x2A8 */
  __IO uint32_t RMON_R_P65TO127;                   /**< RMON Rx 65 to 127 byte packets, offset: 0x2AC */
  __IO uint32_t RMON_R_P128TO255;                  /**< RMON Rx 128 to 255 byte packets, offset: 0x2B0 */
  __IO uint32_t RMON_R_P256TO511;                  /**< RMON Rx 256 to 511 byte packets, offset: 0x2B4 */
  __IO uint32_t RMON_R_P512TO1023;                 /**< RMON Rx 512 to 1023 byte packets, offset: 0x2B8 */
  __IO uint32_t RMON_R_P1024TO2047;                /**< RMON Rx 1024 to 2047 byte packets, offset: 0x2BC */
  __IO uint32_t RMON_R_P_GTE2048;                  /**< RMON Rx packets with > 2048 bytes, offset: 0x2C0 */
  __IO uint32_t RMON_R_OCTETS;                     /**< RMON Rx octets, offset: 0x2C4 */
  __IO uint32_t IEEE_R_DROP;                       /**< Count of received frames not counted correctly, offset: 0x2C8 */
  __IO uint32_t IEEE_R_FRAME_OK;                   /**< Frames received OK, offset: 0x2CC */
  __IO uint32_t IEEE_R_CRC;                        /**< Frames received with CRC error, offset: 0x2D0 */
  __IO uint32_t IEEE_R_ALIGN;                      /**< Frames received with alignment error, offset: 0x2D4 */
  __IO uint32_t IEEE_R_MACERR;                     /**< Receive FIFO overflow count, offset: 0x2D8 */
  __IO uint32_t IEEE_R_FDXFC;                      /**< Flow control pause frames received, offset: 0x2DC */
  __IO uint32_t IEEE_R_OCTETS_OK;                  /**< Octet count for frames received without error, offset: 0x2E0 */
} FEC_Type, *FEC_MemMapPtr;


/* EIR Bit Fields */
#define FEC_EIR_UN_MASK                          0x80000u
#define FEC_EIR_UN_SHIFT                         19u
#define FEC_EIR_UN_WIDTH                         1u
#define FEC_EIR_UN(x)                            (((uint32_t)(((uint32_t)(x))<<FEC_EIR_UN_SHIFT))&FEC_EIR_UN_MASK)
#define FEC_EIR_RL_MASK                          0x100000u
#define FEC_EIR_RL_SHIFT                         20u
#define FEC_EIR_RL_WIDTH                         1u
#define FEC_EIR_RL(x)                            (((uint32_t)(((uint32_t)(x))<<FEC_EIR_RL_SHIFT))&FEC_EIR_RL_MASK)
#define FEC_EIR_LC_MASK                          0x200000u
#define FEC_EIR_LC_SHIFT                         21u
#define FEC_EIR_LC_WIDTH                         1u
#define FEC_EIR_LC(x)                            (((uint32_t)(((uint32_t)(x))<<FEC_EIR_LC_SHIFT))&FEC_EIR_LC_MASK)
#define FEC_EIR_EBERR_MASK                       0x400000u
#define FEC_EIR_EBERR_SHIFT                      22u
#define FEC_EIR_EBERR_WIDTH                      1u
#define FEC_EIR_EBERR(x)                         (((uint32_t)(((uint32_t)(x))<<FEC_EIR_EBERR_SHIFT))&FEC_EIR_EBERR_MASK)
#define FEC_EIR_MII_MASK                         0x800000u
#define FEC_EIR_MII_SHIFT                        23u
#define FEC_EIR_MII_WIDTH                        1u
#define FEC_EIR_MII(x)                           (((uint32_t)(((uint32_t)(x))<<FEC_EIR_MII_SHIFT))&FEC_EIR_MII_MASK)
#define FEC_EIR_RXB_MASK                         0x1000000u
#define FEC_EIR_RXB_SHIFT                        24u
#define FEC_EIR_RXB_WIDTH                        1u
#define FEC_EIR_RXB(x)                           (((uint32_t)(((uint32_t)(x))<<FEC_EIR_RXB_SHIFT))&FEC_EIR_RXB_MASK)
#define FEC_EIR_RXF_MASK                         0x2000000u
#define FEC_EIR_RXF_SHIFT                        25u
#define FEC_EIR_RXF_WIDTH                        1u
#define FEC_EIR_RXF(x)                           (((uint32_t)(((uint32_t)(x))<<FEC_EIR_RXF_SHIFT))&FEC_EIR_RXF_MASK)
#define FEC_EIR_TXB_MASK                         0x4000000u
#define FEC_EIR_TXB_SHIFT                        26u
#define FEC_EIR_TXB_WIDTH                        1u
#define FEC_EIR_TXB(x)                           (((uint32_t)(((uint32_t)(x))<<FEC_EIR_TXB_SHIFT))&FEC_EIR_TXB_MASK)
#define FEC_EIR_TXF_MASK                         0x8000000u
#define FEC_EIR_TXF_SHIFT                        27u
#define FEC_EIR_TXF_WIDTH                        1u
#define FEC_EIR_TXF(x)                           (((uint32_t)(((uint32_t)(x))<<FEC_EIR_TXF_SHIFT))&FEC_EIR_TXF_MASK)
#define FEC_EIR_GRA_MASK                         0x10000000u
#define FEC_EIR_GRA_SHIFT                        28u
#define FEC_EIR_GRA_WIDTH                        1u
#define FEC_EIR_GRA(x)                           (((uint32_t)(((uint32_t)(x))<<FEC_EIR_GRA_SHIFT))&FEC_EIR_GRA_MASK)
#define FEC_EIR_BABT_MASK                        0x20000000u
#define FEC_EIR_BABT_SHIFT                       29u
#define FEC_EIR_BABT_WIDTH                       1u
#define FEC_EIR_BABT(x)                          (((uint32_t)(((uint32_t)(x))<<FEC_EIR_BABT_SHIFT))&FEC_EIR_BABT_MASK)
#define FEC_EIR_BABR_MASK                        0x40000000u
#define FEC_EIR_BABR_SHIFT                       30u
#define FEC_EIR_BABR_WIDTH                       1u
#define FEC_EIR_BABR(x)                          (((uint32_t)(((uint32_t)(x))<<FEC_EIR_BABR_SHIFT))&FEC_EIR_BABR_MASK)
#define FEC_EIR_HBERR_MASK                       0x80000000u
#define FEC_EIR_HBERR_SHIFT                      31u
#define FEC_EIR_HBERR_WIDTH                      1u
#define FEC_EIR_HBERR(x)                         (((uint32_t)(((uint32_t)(x))<<FEC_EIR_HBERR_SHIFT))&FEC_EIR_HBERR_MASK)


/* MMFR Bit Fields */
#define FEC_MMFR_DATA_MASK                       0xFFFFu
#define FEC_MMFR_DATA_SHIFT                      0u
#define FEC_MMFR_DATA_WIDTH                      16u
#define FEC_MMFR_DATA(x)                         (((uint32_t)(((uint32_t)(x))<<FEC_MMFR_DATA_SHIFT))&FEC_MMFR_DATA_MASK)
#define FEC_MMFR_TA_MASK                         0x30000u
#define FEC_MMFR_TA_SHIFT                        16u
#define FEC_MMFR_TA_WIDTH                        2u
#define FEC_MMFR_TA(x)                           (((uint32_t)(((uint32_t)(x))<<FEC_MMFR_TA_SHIFT))&FEC_MMFR_TA_MASK)
#define FEC_MMFR_RA_MASK                         0x7C0000u
#define FEC_MMFR_RA_SHIFT                        18u
#define FEC_MMFR_RA_WIDTH                        5u
#define FEC_MMFR_RA(x)                           (((uint32_t)(((uint32_t)(x))<<FEC_MMFR_RA_SHIFT))&FEC_MMFR_RA_MASK)
#define FEC_MMFR_PA_MASK                         0xF800000u
#define FEC_MMFR_PA_SHIFT                        23u
#define FEC_MMFR_PA_WIDTH                        5u
#define FEC_MMFR_PA(x)                           (((uint32_t)(((uint32_t)(x))<<FEC_MMFR_PA_SHIFT))&FEC_MMFR_PA_MASK)
#define FEC_MMFR_OP_MASK                         0x30000000u
#define FEC_MMFR_OP_SHIFT                        28u
#define FEC_MMFR_OP_WIDTH                        2u
#define FEC_MMFR_OP(x)                           (((uint32_t)(((uint32_t)(x))<<FEC_MMFR_OP_SHIFT))&FEC_MMFR_OP_MASK)
#define FEC_MMFR_ST_MASK                         0xC0000000u
#define FEC_MMFR_ST_SHIFT                        30u
#define FEC_MMFR_ST_WIDTH                        2u
#define FEC_MMFR_ST(x)                           (((uint32_t)(((uint32_t)(x))<<FEC_MMFR_ST_SHIFT))&FEC_MMFR_ST_MASK)

/* ECR Bit Fields */
#define FEC_ECR_RESET_MASK                       0x1u
#define FEC_ECR_RESET_SHIFT                      0u
#define FEC_ECR_RESET_WIDTH                      1u
#define FEC_ECR_RESET(x)                         (((uint32_t)(((uint32_t)(x))<<FEC_ECR_RESET_SHIFT))&FEC_ECR_RESET_MASK)
#define FEC_ECR_ETHER_EN_MASK                    0x2u
#define FEC_ECR_ETHER_EN_SHIFT                   1u
#define FEC_ECR_ETHER_EN_WIDTH                   1u
#define FEC_ECR_ETHER_EN(x)                      (((uint32_t)(((uint32_t)(x))<<FEC_ECR_ETHER_EN_SHIFT))&FEC_ECR_ETHER_EN_MASK)

/* PAUR Bit Fields */
#define FEC_PAUR_TYPE_MASK                       0xFFFFu
#define FEC_PAUR_TYPE_SHIFT                      0u
#define FEC_PAUR_TYPE_WIDTH                      16u
#define FEC_PAUR_TYPE(x)                         (((uint32_t)(((uint32_t)(x))<<FEC_PAUR_TYPE_SHIFT))&FEC_PAUR_TYPE_MASK)
#define FEC_PAUR_PADDR2_MASK                     0xFFFF0000u
#define FEC_PAUR_PADDR2_SHIFT                    16u
#define FEC_PAUR_PADDR2_WIDTH                    16u
#define FEC_PAUR_PADDR2(x)                       (((uint32_t)(((uint32_t)(x))<<FEC_PAUR_PADDR2_SHIFT))&FEC_PAUR_PADDR2_MASK)

/* RDAR Bit Fields */
#define FEC_RDAR_RDAR_MASK                       0x1000000u
#define FEC_RDAR_RDAR_SHIFT                      24u
#define FEC_RDAR_RDAR_WIDTH                      1u
#define FEC_RDAR_RDAR(x)                         (((uint32_t)(((uint32_t)(x))<<FEC_RDAR_RDAR_SHIFT))&FEC_RDAR_RDAR_MASK)
/* TDAR Bit Fields */
#define FEC_TDAR_TDAR_MASK                       0x1000000u
#define FEC_TDAR_TDAR_SHIFT                      24u
#define FEC_TDAR_TDAR_WIDTH                      1u
#define FEC_TDAR_TDAR(x)                         (((uint32_t)(((uint32_t)(x))<<FEC_TDAR_TDAR_SHIFT))&FEC_TDAR_TDAR_MASK)

#define FEC_MIBC_MIB_DIS_MASK                    0x80000000u
#define FEC_MIBC_MIB_DIS_SHIFT                   31u
#define FEC_MIBC_MIB_DIS_WIDTH                   1u
#define FEC_MIBC_MIB_DIS(x)                      (((uint32_t)(((uint32_t)(x))<<FEC_MIBC_MIB_DIS_SHIFT))&FEC_MIBC_MIB_DIS_MASK)


/* FEC - Peripheral instance base addresses */
/** Peripheral FEC base address */
#define FEC_BASE                                 (0xFC0B0000u)
/** Peripheral FEC base pointer */
#define FEC_TWO                                      ((FEC_Type *)FEC_BASE)
/** Array initializer of FEC peripheral base addresses */
#define FEC_BASE_ADDRS                           { FEC_BASE }
/** Array initializer of FEC peripheral base pointers */
#define FEC_BASE_PTRS                            { FEC_TWO }


#define ENET_Type FEC_Type

#define ENET_INSTANCE_COUNT	1
#define ENET_BASE_PTRS		FEC_BASE_PTRS

#define ENET_EIR_BABR_MASK	FEC_EIR_BABR_MASK
#define ENET_EIR_BABT_MASK	FEC_EIR_BABT_MASK
#define ENET_EIR_GRA_MASK	FEC_EIR_GRA_MASK
#define ENET_EIR_TXF_MASK	FEC_EIR_TXF_MASK
#define ENET_EIR_TXB_MASK	FEC_EIR_TXB_MASK
#define ENET_EIR_RXF_MASK	FEC_EIR_RXF_MASK
#define ENET_EIR_RXB_MASK	FEC_EIR_RXB_MASK
#define ENET_EIR_MII_MASK	FEC_EIR_MII_MASK
#define ENET_EIR_EBERR_MASK	FEC_EIR_EBERR_MASK
#define ENET_EIR_LC_MASK	FEC_EIR_LC_MASK
#define ENET_EIR_RL_MASK	FEC_EIR_RL_MASK
#define ENET_EIR_UN_MASK	FEC_EIR_UN_MASK

#define ENET_MMFR_DATA_MASK		FEC_MMFR_DATA_MASK
#define ENET_MMFR_ST			FEC_MMFR_ST
#define ENET_MMFR_OP			FEC_MMFR_OP
#define ENET_MMFR_PA			FEC_MMFR_PA
#define ENET_MMFR_RA			FEC_MMFR_RA
#define ENET_MMFR_TA			FEC_MMFR_TA
#define ENET_MMFR_DATA			FEC_MMFR_DATA
#define ENET_PAUR_PADDR2_MASK	FEC_PAUR_PADDR2_MASK
#define ENET_PAUR_PADDR2_SHIFT	FEC_PAUR_PADDR2_SHIFT
#define ENET_ECR_ETHEREN_MASK	FEC_ECR_ETHER_EN_MASK
#define ENET_TDAR_TDAR_MASK		FEC_TDAR_TDAR_MASK
#define ENET_RDAR_RDAR_MASK		FEC_RDAR_RDAR_MASK
#define ENET_ECR_RESET_MASK		FEC_ECR_RESET_MASK

/* CAN module features */

/* @brief Frames available in Rx FIFO flag shift */
#define FEATURE_CAN_RXFIFO_FRAME_AVAILABLE  (5U)
/* @brief Rx FIFO warning flag shift */
#define FEATURE_CAN_RXFIFO_WARNING          (6U)
/* @brief Rx FIFO overflow flag shift */
#define FEATURE_CAN_RXFIFO_OVERFLOW         (7U)
/* @brief Maximum number of Message Buffers supported for payload size 8 for CAN0 */
#define FEATURE_CAN0_MAX_MB_NUM             (96U)
/* @brief Maximum number of Message Buffers supported for payload size 8 for CAN1 */
#define FEATURE_CAN1_MAX_MB_NUM             (96U)
/* @brief Maximum number of Message Buffers supported for payload size 8 for CAN2 */
#define FEATURE_CAN2_MAX_MB_NUM             (64U)
/* @brief Maximum number of Message Buffers supported for payload size 8 for CAN3 */
#define FEATURE_CAN3_MAX_MB_NUM             (64U)
/* @brief Maximum number of Message Buffers supported for payload size 8 for any of the CAN instances */
#define FEATURE_CAN_MAX_MB_NUM              (96U)
/* @brief Array of maximum number of Message Buffers supported for payload size 8 for all the CAN instances */
#define FEATURE_CAN_MAX_MB_NUM_ARRAY        { FEATURE_CAN0_MAX_MB_NUM, \
                                              FEATURE_CAN1_MAX_MB_NUM, \
                                              FEATURE_CAN2_MAX_MB_NUM, \
                                              FEATURE_CAN3_MAX_MB_NUM  }
/* @brief Has PE clock source select (bit field CAN_CTRL1[CLKSRC]). */
#define FEATURE_CAN_HAS_PE_CLKSRC_SELECT            (0)
/* @brief Has Pretending Networking mode */
#define FEATURE_CAN_HAS_PRETENDED_NETWORKING        (0)
/* @brief Has Stuff Bit Count Enable Bit */
#define FEATURE_CAN_HAS_STFCNTEN_ENABLE             (0)
/* @brief Has ISO CAN FD Enable Bit */
#define FEATURE_CAN_HAS_ISOCANFDEN_ENABLE           (0)
/* @brief Has Message Buffer Data Size Region 1 */
#define FEATURE_CAN_HAS_MBDSR1                      (0)
/* @brief Has Message Buffer Data Size Region 2 */
#define FEATURE_CAN_HAS_MBDSR2                      (0)
/* @brief Has Supervisor Mode MCR[SUPV]*/
#define FEATURE_CAN_HAS_SUPV             	        (1)
/* @brief Has DMA enable (bit field MCR[DMA]). */
#define FEATURE_CAN_HAS_DMA_ENABLE                  (1)
/* @brief Maximum number of Message Buffers IRQs */
#define FEATURE_CAN_MB_IRQS_MAX_COUNT       (4U)
/* @brief Has Wake Up Irq channels (CAN_Wake_Up_IRQS_CH_COUNT > 0u) */
#define FEATURE_CAN_HAS_WAKE_UP_IRQ         (0U)

/*! @brief FlexCAN Embedded RAM address offset */
#define FEATURE_CAN_RAM_OFFSET              (0x00000080u)
/* @brief Has Self Wake Up mode */
#define FEATURE_CAN_HAS_SELF_WAKE_UP        (0)
/* @brief Has Flexible Data Rate */
#define FEATURE_CAN_HAS_FD                  (0)

/* @bried FlexCAN has Detection And Correction of Memory Errors */
#define FEATURE_CAN_HAS_MEM_ERR_DET         (1)
/* @bried FlexCAN has ECC requires clear of RXMASKs reg */
#define FEATURE_CAN_ECC_CLEAR_RXMASKS       (1)

/* TIMING_PAL module features */
/* @brief The issue: PIT and STM modules can not run if the stop in debug mode is enabled */
#define TIMING_PAL_HAS_PIT_STM_NOT_WORK_IN_DEBUG_MODE (1U)


/*! @brief TDR count */
#define TDR_COUNT 6U

/* PASS module features */

/* @brief Has Region 0 */
#define FEATURE_PASS_HAS_RL0                  (0U)
/* @brief Has Region 1 */
#define FEATURE_PASS_HAS_RL1                  (1U)
/* @brief Has Region 2 */
#define FEATURE_PASS_HAS_RL2                  (2U)

/* PASS module features */

/* @brief Has Region 0 */
#define FEATURE_PASS_HAS_RL0                  (0U)
/* @brief Has Region 1 */
#define FEATURE_PASS_HAS_RL1                  (1U)
/* @brief Has Region 2 */
#define FEATURE_PASS_HAS_RL2                  (2U)

/* ZIPWIRE module features */

/* @brief LFAST data rate change delay */
#define LFAST_DATA_RATE_CHANGE_DELAY 0xFU
/* @brief LFAST wakeup delay control register */
#define LFAST_WAKEUP_DELAY_CONTROL 0x12015402UL
/* @brief LFAST enable slave tx command */
#define LFAST_ENABLE_SLAVE_TX_CMD 0x31U
/* @brief LFAST check slave status command */
#define LFAST_CHECK_SLAVE_STATUS_CMD 0x0U
/* @brief LFAST enable slave pll command */
#define LFAST_ENABLE_SLAVE_PLL_CMD 0x02U
/* @brief LFAST change slave tx speed mode command */
#define LFAST_CHANGE_SLAVE_TX_SPEED_MODE_CMD 0x80U
/* @brief LFAST change slave rx speed mode command */
#define LFAST_CHANGE_SLAVE_RX_SPEED_MODE_CMD 0x10U

/* @brief SIPI channel error flags masks */
#define SIPI_CH0_ERR_MASK 0xFFUL
#define SIPI_CH1_ERR_MASK 0xFF00UL
#define SIPI_CH2_ERR_MASK 0xFF0000UL
#define SIPI_CH3_ERR_MASK 0xFF000000UL
/* @brief SIPI channel count */
#define SIPI_CHANNEL_COUNT 4U
/* @brief SIPI streaming channel number */
#define SIPI_STREAMING_CH 2U
/* @brief SIPI reset timeout */
#define SIPI_RESET_TIMEOUT 10000U
/* @brief SIPI stream channel data register access */
#define SIPI_STREAM_DATA(x) (SIPI->CDR2[(x)])
/* @brief SIPI stream transfer length in bytes */
#define SIPI_STREAM_TRANSFER_LEN 8U
/* @brief SIPI data access macros */
#define SIPI_DATA_SHIFT(x) ((uint32_t)(0x18U & (0x18U << ((uint8_t)(x)))))
#define SIPI_DATA(x,y)     ((x) >> SIPI_DATA_SHIFT(y))
/* @brief SIPI interrupt lines count */
#define SIPI_IRQ_COUNT 7U
/* @brief SIPI separated interrupt lines */
#define SIPI_SEPARATED_INT_LINES


/* DECFILTER module features */
#define FEATURE_DECFILTER_HAS_PSI   (0U)
#define FEATURE_DECFILTER_ENHANCED_DEBUG (0U)

#endif /* MPC5746R_FEATURES_H */

/*******************************************************************************
 * EOF
 ******************************************************************************/

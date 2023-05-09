/*****************************************************************************/
/* FILE NAME: intc_SW_mode_isr_vectors_MPC574xR.c COPYRIGHT(c) Freescale 2013*/
/*                                                      All Rights Reserved  */
/* DESCRIPTION: MPC574xR ISR vectors for INTC in software vector mode        */
/*              Based on MPC5744R ref manual rev 3 Table 17-2.               */
/* USAGE:  For desired vector #, replace "dummy" with ISR name and declare   */
/*         your isr name extern like the example below:                      */
/*                       extern void MyPeripheralISR(void);                  */
/*                                                                           */
/*****************************************************************************/	
/* REV      AUTHOR        DATE        DESCRIPTION OF CHANGE                  */
/* ---   -----------    ----------    ---------------------                  */
/* 1.0	  S Mihalik     14 Oct 2013   Initial version                        */
/*****************************************************************************/
#include "typedefs.h"
#include "Interrupt.h"
/*========================================================================*/
/*		PROTOTYPES					                                 	  */
/*========================================================================*/
void dummy 						  (void);

/*========================================================================*/
/*	GLOBAL VARIABLES						                              */
/*========================================================================*/

const uint32_t __attribute__ ((section (".intc_vector_table"))) IntcIsrVectorTable[] = {
    
(uint32_t) &INT_SI0_ISR, /* Vector #   0 Software settable flag  0 INTC_SSCIR0[CLR0] */
(uint32_t) &dummy, /* Vector #   1 Software settable flag  1 INTC_SSCIR0[CLR1] */
(uint32_t) &dummy, /* Vector #   2 Software settable flag  2 INTC_SSCIR0[CLR2] */
(uint32_t) &dummy, /* Vector #   3 Software settable flag  3 INTC_SSCIR0[CLR3] */
(uint32_t) &dummy, /* Vector #   4 Software settable flag  4 INTC_SSCIR0[CLR4] */
(uint32_t) &dummy, /* Vector #   5 Software settable flag  5 INTC_SSCIR0[CLR5] */
(uint32_t) &dummy, /* Vector #   6 Software settable flag  6 INTC_SSCIR0[CLR6] */
(uint32_t) &dummy, /* Vector #   7 Software settable flag  7 INTC_SSCIR0[CLR7] */
(uint32_t) &dummy, /* Vector #   8 Software settable flag  8 INTC_SSCIR0[CLR8] */
(uint32_t) &dummy, /* Vector #   9 Software settable flag  9 INTC_SSCIR0[CLR9] */
(uint32_t) &dummy, /* Vector #  10 Software settable flag 10 INTC_SSCIR0[CLR10] */
(uint32_t) &dummy, /* Vector #  11 Software settable flag 11 INTC_SSCIR0[CLR11] */
(uint32_t) &dummy, /* Vector #  12 Software settable flag 12 INTC_SSCIR0[CLR12] */
(uint32_t) &dummy, /* Vector #  13 Software settable flag 13 INTC_SSCIR0[CLR13] */
(uint32_t) &dummy, /* Vector #  14 Software settable flag 14 INTC_SSCIR0[CLR14] */
(uint32_t) &dummy, /* Vector #  15 Software settable flag 15 INTC_SSCIR0[CLR15] */
(uint32_t) &dummy, /* Vector #  16 Software settable flag 16 INTC_SSCIR0[CLR16] */
(uint32_t) &dummy, /* Vector #  17 Software settable flag 17 INTC_SSCIR0[CLR17] */
(uint32_t) &dummy, /* Vector #  18 Software settable flag 18 INTC_SSCIR0[CLR18] */
(uint32_t) &dummy, /* Vector #  19 Software settable flag 19 INTC_SSCIR0[CLR19] */
(uint32_t) &dummy, /* Vector #  20 Software settable flag 20 INTC_SSCIR0[CLR20] */
(uint32_t) &dummy, /* Vector #  21 Software settable flag 21 INTC_SSCIR0[CLR21] */
(uint32_t) &dummy, /* Vector #  22 Software settable flag 22 INTC_SSCIR0[CLR22] */
(uint32_t) &dummy, /* Vector #  23 Software settable flag 23 INTC_SSCIR0[CLR23] */
(uint32_t) &dummy, /* Vector #  24 Software settable flag 24 INTC_SSCIR0[CLR24] */
(uint32_t) &dummy, /* Vector #  25 Software settable flag 25 INTC_SSCIR0[CLR25] */
(uint32_t) &dummy, /* Vector #  26 Software settable flag 26 INTC_SSCIR0[CLR26] */
(uint32_t) &dummy, /* Vector #  27 Software settable flag 27 INTC_SSCIR0[CLR27] */
(uint32_t) &dummy, /* Vector #  28 Software settable flag 28 INTC_SSCIR0[CLR28] */
(uint32_t) &dummy, /* Vector #  29 Software settable flag 29 INTC_SSCIR0[CLR29] */
(uint32_t) &dummy, /* Vector #  30 Software settable flag 30 INTC_SSCIR0[CLR30] */
(uint32_t) &dummy, /* Vector #  31 Software settable flag 31 INTC_SSCIR0[CLR31] */
(uint32_t) &dummy, /* Vector #  32 Platform watchdog timer0 SWT_0_IR[TIF] */
(uint32_t) &dummy, /* Vector #  33 Platform watchdog timer1 SWT_1_IR[TIF] */
(uint32_t) &dummy, /* Vector #  34 */
(uint32_t) &dummy, /* Vector #  35 Platform watchdog timer3 SWT_3_IR[TIF] */
(uint32_t) &dummy, /* Vector #  36 Platform periodic timer 0_0 (STM) STM_0_CIR0[CIF] */
(uint32_t) &dummy, /* Vector #  37 Platform periodic timer 0_1 (STM) STM_0_CIR1[CIF] */
(uint32_t) &dummy, /* Vector #  38 Platform periodic timer 0_2 (STM) STM_0_CIR2[CIF] */
(uint32_t) &dummy, /* Vector #  39 Platform periodic timer 0_3 (STM) STM_0_CIR3[CIF] */
(uint32_t) &dummy, /* Vector #  40 Platform periodic timer 1_0 (STM) STM_1_CIR0[CIF] */
(uint32_t) &dummy, /* Vector #  41 Platform periodic timer 1_1 (STM) STM_1_CIR1[CIF] */
(uint32_t) &dummy, /* Vector #  42 Platform periodic timer 1_2 (STM) STM_1_CIR2[CIF] */
(uint32_t) &dummy, /* Vector #  43 Platform periodic timer 1_3 (STM) STM_1_CIR3[CIF] */
(uint32_t) &dummy, /* Vector #  44 */
(uint32_t) &dummy, /* Vector #  45 */
(uint32_t) &dummy, /* Vector #  46 */
(uint32_t) &dummy, /* Vector #  47 */
(uint32_t) &dummy, /* Vector #  48 */
(uint32_t) &dummy, /* Vector #  49 */
(uint32_t) &dummy, /* Vector #  50 */
(uint32_t) &dummy, /* Vector #  51 */
(uint32_t) &dummy, /* Vector #  52 eDMA Combined Error 127 - 0 eDMA Channel Error Flags */
(uint32_t) &dummy, /* Vector #  53 eDMA Channel 0 DMA_INTL[INT0] */
(uint32_t) &dummy, /* Vector #  54 eDMA Channel 1 DMA_INTL[INT1] */
(uint32_t) &dummy, /* Vector #  55 eDMA Channel 2 DMA_INTL[INT2] */
(uint32_t) &dummy, /* Vector #  56 eDMA Channel 3 DMA_INTL[INT3] */
(uint32_t) &dummy, /* Vector #  57 eDMA Channel 4 DMA_INTL[INT4] */
(uint32_t) &dummy, /* Vector #  58 eDMA Channel 5 DMA_INTL[INT5] */
(uint32_t) &dummy, /* Vector #  59 eDMA Channel 6 DMA_INTL[INT6] */
(uint32_t) &dummy, /* Vector #  60 eDMA Channel 7 DMA_INTL[INT7] */
(uint32_t) &dummy, /* Vector #  61 eDMA Channel 8 DMA_INTL[INT8] */
(uint32_t) &dummy, /* Vector #  62 eDMA Channel 9 DMA_INTL[INT9] */
(uint32_t) &dummy, /* Vector #  63 eDMA Channel 10 DMA_INTL[INT10] */
(uint32_t) &dummy, /* Vector #  64 eDMA Channel 11 DMA_INTL[INT11] */
(uint32_t) &dummy, /* Vector #  65 eDMA Channel 12 DMA_INTL[INT12] */
(uint32_t) &dummy, /* Vector #  66 eDMA Channel 13 DMA_INTL[INT13] */
(uint32_t) &dummy, /* Vector #  67 eDMA Channel 14 DMA_INTL[INT14] */
(uint32_t) &dummy, /* Vector #  68 eDMA Channel 15 DMA_INTL[INT15] */
(uint32_t) &dummy, /* Vector #  69 eDMA Channel 16 DMA_INTL[INT16] */
(uint32_t) &dummy, /* Vector #  70 eDMA Channel 17 DMA_INTL[INT17] */
(uint32_t) &dummy, /* Vector #  71 eDMA Channel 18 DMA_INTL[INT18] */
(uint32_t) &dummy, /* Vector #  72 eDMA Channel 19 DMA_INTL[INT19] */
(uint32_t) &dummy, /* Vector #  73 eDMA Channel 20 DMA_INTL[INT20] */
(uint32_t) &dummy, /* Vector #  74 eDMA Channel 21 DMA_INTL[INT21] */
(uint32_t) &dummy, /* Vector #  75 eDMA Channel 22 DMA_INTL[INT22] */
(uint32_t) &dummy, /* Vector #  76 eDMA Channel 23 DMA_INTL[INT23] */
(uint32_t) &dummy, /* Vector #  77 eDMA Channel 24 DMA_INTL[INT24] */
(uint32_t) &dummy, /* Vector #  78 eDMA Channel 25 DMA_INTL[INT25] */
(uint32_t) &dummy, /* Vector #  79 eDMA Channel 26 DMA_INTL[INT26] */
(uint32_t) &dummy, /* Vector #  80 eDMA Channel 27 DMA_INTL[INT27] */
(uint32_t) &dummy, /* Vector #  81 eDMA Channel 28 DMA_INTL[INT28] */
(uint32_t) &dummy, /* Vector #  82 eDMA Channel 29 DMA_INTL[INT29] */
(uint32_t) &dummy, /* Vector #  83 eDMA Channel 30 DMA_INTL[INT30] */
(uint32_t) &dummy, /* Vector #  84 eDMA Channel 31 DMA_INTL[INT31] */
(uint32_t) &dummy, /* Vector #  85 eDMA Channel 32 DMA_INTH[INT32] */
(uint32_t) &dummy, /* Vector #  86 eDMA Channel 33 DMA_INTH[INT33] */
(uint32_t) &dummy, /* Vector #  87 eDMA Channel 34 DMA_INTH[INT34] */
(uint32_t) &dummy, /* Vector #  88 eDMA Channel 35 DMA_INTH[INT35] */
(uint32_t) &dummy, /* Vector #  89 eDMA Channel 36 DMA_INTH[INT36] */
(uint32_t) &dummy, /* Vector #  90 eDMA Channel 37 DMA_INTH[INT37] */
(uint32_t) &dummy, /* Vector #  91 eDMA Channel 38 DMA_INTH[INT38] */
(uint32_t) &dummy, /* Vector #  92 eDMA Channel 39 DMA_INTH[INT39] */
(uint32_t) &dummy, /* Vector #  93 eDMA Channel 40 DMA_INTH[INT40] */
(uint32_t) &dummy, /* Vector #  94 eDMA Channel 41 DMA_INTH[INT41] */
(uint32_t) &dummy, /* Vector #  95 eDMA Channel 42 DMA_INTH[INT42] */
(uint32_t) &dummy, /* Vector #  96 eDMA Channel 43 DMA_INTH[INT43] */
(uint32_t) &dummy, /* Vector #  97 eDMA Channel 44 DMA_INTH[INT44] */
(uint32_t) &dummy, /* Vector #  98 eDMA Channel 45 DMA_INTH[INT45] */
(uint32_t) &dummy, /* Vector #  99 eDMA Channel 46 DMA_INTH[INT46] */
(uint32_t) &dummy, /* Vector # 100 eDMA Channel 47 DMA_INTH[INT47] */

(uint32_t) &dummy, /* Vector # 101 eDMA Channel 48 DMA_INTH[INT48] */
(uint32_t) &dummy, /* Vector # 102 eDMA Channel 49 DMA_INTH[INT49] */
(uint32_t) &dummy, /* Vector # 103 eDMA Channel 50 DMA_INTH[INT50] */
(uint32_t) &dummy, /* Vector # 104 eDMA Channel 51 DMA_INTH[INT51] */
(uint32_t) &dummy, /* Vector # 105 eDMA Channel 52 DMA_INTH[INT52] */
(uint32_t) &dummy, /* Vector # 106 eDMA Channel 53 DMA_INTH[INT53] */
(uint32_t) &dummy, /* Vector # 107 eDMA Channel 54 DMA_INTH[INT54] */
(uint32_t) &dummy, /* Vector # 108 eDMA Channel 55 DMA_INTH[INT55] */
(uint32_t) &dummy, /* Vector # 109 eDMA Channel 56 DMA_INTH[INT56] */
(uint32_t) &dummy, /* Vector # 110 eDMA Channel 57 DMA_INTH[INT57] */
(uint32_t) &dummy, /* Vector # 111 eDMA Channel 58 DMA_INTH[INT58] */
(uint32_t) &dummy, /* Vector # 112 eDMA Channel 59 DMA_INTH[INT59] */
(uint32_t) &dummy, /* Vector # 113 eDMA Channel 60 DMA_INTH[INT60] */
(uint32_t) &dummy, /* Vector # 114 eDMA Channel 61 DMA_INTH[INT61] */
(uint32_t) &dummy, /* Vector # 115 eDMA Channel 62 DMA_INTH[INT62] */
(uint32_t) &dummy, /* Vector # 116 eDMA Channel 63 DMA_INTH[INT63] */
(uint32_t) &dummy, /* Vector # 117 */
(uint32_t) &dummy, /* Vector # 118 */
(uint32_t) &dummy, /* Vector # 119 */
(uint32_t) &dummy, /* Vector # 120 */
(uint32_t) &dummy, /* Vector # 121 */
(uint32_t) &dummy, /* Vector # 122 */
(uint32_t) &dummy, /* Vector # 123 */
(uint32_t) &dummy, /* Vector # 124 */
(uint32_t) &dummy, /* Vector # 125 */
(uint32_t) &dummy, /* Vector # 126 */
(uint32_t) &dummy, /* Vector # 127 */
(uint32_t) &dummy, /* Vector # 128 */
(uint32_t) &dummy, /* Vector # 129 */
(uint32_t) &dummy, /* Vector # 130 */
(uint32_t) &dummy, /* Vector # 131 */
(uint32_t) &dummy, /* Vector # 132 */
(uint32_t) &dummy, /* Vector # 133 */
(uint32_t) &dummy, /* Vector # 134 */
(uint32_t) &dummy, /* Vector # 135 */
(uint32_t) &dummy, /* Vector # 136 */
(uint32_t) &dummy, /* Vector # 137 */
(uint32_t) &dummy, /* Vector # 138 */
(uint32_t) &dummy, /* Vector # 139 */
(uint32_t) &dummy, /* Vector # 140 */
(uint32_t) &dummy, /* Vector # 141 */
(uint32_t) &dummy, /* Vector # 142 */
(uint32_t) &dummy, /* Vector # 143 */
(uint32_t) &dummy, /* Vector # 144 */
(uint32_t) &dummy, /* Vector # 145 */
(uint32_t) &dummy, /* Vector # 146 */
(uint32_t) &dummy, /* Vector # 147 */
(uint32_t) &dummy, /* Vector # 148 */
(uint32_t) &dummy, /* Vector # 149 */
(uint32_t) &dummy, /* Vector # 150 */
(uint32_t) &dummy, /* Vector # 151 */
(uint32_t) &dummy, /* Vector # 152 */
(uint32_t) &dummy, /* Vector # 153 */
(uint32_t) &dummy, /* Vector # 154 */
(uint32_t) &dummy, /* Vector # 155 */
(uint32_t) &dummy, /* Vector # 156 */
(uint32_t) &dummy, /* Vector # 157 */
(uint32_t) &dummy, /* Vector # 158 */
(uint32_t) &dummy, /* Vector # 159 */
(uint32_t) &dummy, /* Vector # 160 */
(uint32_t) &dummy, /* Vector # 161 */
(uint32_t) &dummy, /* Vector # 162 */
(uint32_t) &dummy, /* Vector # 163 */
(uint32_t) &dummy, /* Vector # 164 */
(uint32_t) &dummy, /* Vector # 165 */
(uint32_t) &dummy, /* Vector # 166 */
(uint32_t) &dummy, /* Vector # 167 */
(uint32_t) &dummy, /* Vector # 168 */
(uint32_t) &dummy, /* Vector # 169 */
(uint32_t) &dummy, /* Vector # 170 */
(uint32_t) &dummy, /* Vector # 171 */
(uint32_t) &dummy, /* Vector # 172 */
(uint32_t) &dummy, /* Vector # 173 */
(uint32_t) &dummy, /* Vector # 174 */
(uint32_t) &dummy, /* Vector # 175 */
(uint32_t) &dummy, /* Vector # 176 */
(uint32_t) &dummy, /* Vector # 177 */
(uint32_t) &dummy, /* Vector # 178 */
(uint32_t) &dummy, /* Vector # 179 */
(uint32_t) &dummy, /* Vector # 180 */
(uint32_t) &dummy, /* Vector # 181 */
(uint32_t) &dummy, /* Vector # 182 */
(uint32_t) &dummy, /* Vector # 183 */
(uint32_t) &dummy, /* Vector # 184 */
(uint32_t) &dummy, /* Vector # 185 Flash controller Prog/Erase/Suspend IRQ_0 MCR[DONE] */
(uint32_t) &dummy, /* Vector # 186 */
(uint32_t) &dummy, /* Vector # 187 */
(uint32_t) &dummy, /* Vector # 188 */
(uint32_t) &dummy, /* Vector # 189 */
(uint32_t) &dummy, /* Vector # 190 */
(uint32_t) &dummy, /* Vector # 191 */
(uint32_t) &dummy, /* Vector # 192 */
(uint32_t) &dummy, /* Vector # 193 */
(uint32_t) &dummy, /* Vector # 194 */
(uint32_t) &dummy, /* Vector # 195 */
(uint32_t) &dummy, /* Vector # 196 */
(uint32_t) &dummy, /* Vector # 197 */
(uint32_t) &dummy, /* Vector # 198 */
(uint32_t) &dummy, /* Vector # 199 */
(uint32_t) &dummy, /* Vector # 200 */

(uint32_t) &dummy, /* Vector # 201 */
(uint32_t) &dummy, /* Vector # 202 */
(uint32_t) &dummy, /* Vector # 203 */
(uint32_t) &dummy, /* Vector # 204 */
(uint32_t) &dummy, /* Vector # 205 */
(uint32_t) &dummy, /* Vector # 206 */
(uint32_t) &dummy, /* Vector # 207 */
(uint32_t) &dummy, /* Vector # 208 */
(uint32_t) &dummy, /* Vector # 209 */
(uint32_t) &dummy, /* Vector # 210 */
(uint32_t) &dummy, /* Vector # 211 */
(uint32_t) &dummy, /* Vector # 212 */
(uint32_t) &dummy, /* Vector # 213 */
(uint32_t) &dummy, /* Vector # 214 */
(uint32_t) &dummy, /* Vector # 215 */
(uint32_t) &dummy, /* Vector # 216 */
(uint32_t) &dummy, /* Vector # 217 */
(uint32_t) &dummy, /* Vector # 218 Ethernet_0_0 EIR[TXF] */
(uint32_t) &dummy, /* Vector # 219 Ethernet_0_1 EIR[RXF] */
(uint32_t) &dummy, /* Vector # 220 EIR[HBERR] EIR[BABR] EIR[BABT] EIR[GRA] */
                   /*              EIR[TXB] EIR[RXB] EIR[MII] EIR[EBERR] */
                   /*              EIR[LC] EIR[RL] EIR[UN]*/
(uint32_t) &dummy, /* Vector # 221 */
(uint32_t) &dummy, /* Vector # 222 */
(uint32_t) &dummy, /* Vector # 223 */
(uint32_t) &dummy, /* Vector # 224 */
(uint32_t) &dummy, /* Vector # 225 */
(uint32_t) &dummy, /* Vector # 226 Periodic Interrupt Timer (PIT0) PIT_0_TFLG0[TIF] */
(uint32_t) &dummy, /* Vector # 227 Periodic Interrupt Timer (PIT1) PIT_1_TFLG1[TIF] */
(uint32_t) &INT_PIT0_1_ISR, /* Vector # 228 Periodic Interrupt Timer (PIT2) PIT_1_TFLG2[TIF] */
(uint32_t) &dummy, /* Vector # 229 Periodic Interrupt Timer (PIT3) PIT_1_TFLG3[TIF] */
(uint32_t) &dummy, /* Vector # 230 Periodic Interrupt Timer (PIT4) PIT_1_TFLG4[TIF] */
(uint32_t) &dummy, /* Vector # 231 Periodic Interrupt Timer (PIT5) PIT_1_TFLG5[TIF] */
(uint32_t) &dummy, /* Vector # 232 Periodic Interrupt Timer (PIT6) PIT_1_TFLG6[TIF] */
(uint32_t) &dummy, /* Vector # 233 Periodic Interrupt Timer (PIT7) PIT_1_TFLG7[TIF] */
(uint32_t) &dummy, /* Vector # 234 */
(uint32_t) &dummy, /* Vector # 235 */
(uint32_t) &dummy, /* Vector # 236 */
(uint32_t) &dummy, /* Vector # 237 */
(uint32_t) &dummy, /* Vector # 238 */
(uint32_t) &dummy, /* Vector # 239 PIT_RTI PIT_0_RTI_TFLG[TIF] */
(uint32_t) &dummy, /* Vector # 240 PIT_64_Upper PIT_1_TFLG0[TIF] */
(uint32_t) &dummy, /* Vector # 241 PIT_64_Lower PIT_1_TFLG1[TIF] */
(uint32_t) &dummy, /* Vector # 242 XOSC counter XOSC */
(uint32_t) &dummy, /* Vector # 243 SIU External Interrupt_0 SIU External Interrupt_0 */
(uint32_t) &dummy, /* Vector # 244 SIU External Interrupt_1 SIU External Interrupt_1 */
(uint32_t) &dummy, /* Vector # 245 */
(uint32_t) &dummy, /* Vector # 246 */
(uint32_t) &dummy, /* Vector # 247 */
(uint32_t) &dummy, /* Vector # 248 */
(uint32_t) &dummy, /* Vector # 249 */
(uint32_t) &dummy, /* Vector # 250 */
(uint32_t) &dummy, /* Vector # 251 MC _ME ME_IS[I_SAFE] */
(uint32_t) &dummy, /* Vector # 252 MC _ME ME_IS[I_MTC] */
(uint32_t) &dummy, /* Vector # 253 MC _ME ME_IS[I_IMODE] */
(uint32_t) &dummy, /* Vector # 254 MC_ME 3 ME_IS[I_ICONF] */
(uint32_t) &dummy, /* Vector # 255 MC_RGM 0 MC_RGM Functional and destructive reset */
                   /*              alternate event interrupt */
(uint32_t) &dummy, /* Vector # 256 */
(uint32_t) &dummy, /* Vector # 257 */
(uint32_t) &dummy, /* Vector # 258 */
(uint32_t) &dummy, /* Vector # 259 DSPI0_0 DSPI_0_SR[TFUF] |  alternate event interrupt */
                   /*              DSPI_0_SR[TFIWF] */
(uint32_t) &dummy, /* Vector # 260 DSPI0_1 DSPI_0_SR[EOQF] */
(uint32_t) &dummy, /* Vector # 261 DSPI0_2 DSPI_0_SR[TFFF] */
(uint32_t) &dummy, /* Vector # 262 DSPI0_3 DSPI_0_SR[TCF] */
(uint32_t) &dummy, /* Vector # 263 DSPI0_4 DSPI_0_SR[RFDF] */
(uint32_t) &dummy, /* Vector # 264 DSPI0_5 DSPI_0_SR[CMD_TCF] */
(uint32_t) &dummy, /* Vector # 265 DSPI0_6 DSPI_0_SR[CMDFFF] */
(uint32_t) &dummy, /* Vector # 266 DSPI0_7 DSPI_0_SR[SPEF] */
(uint32_t) &dummy, /* Vector # 267 */
(uint32_t) &dummy, /* Vector # 268 DSPI1_0 DSPI_1_SR[TFUF] | DSPI_1_SR[RFOF]| */
                   /*              DSPI_1_SR[TFIWF] */
(uint32_t) &dummy, /* Vector # 269 DSPI1_1 DSPI_1_SR[EOQF] */
(uint32_t) &dummy, /* Vector # 270 DSPI1_2 DSPI_1_SR[TFFF] */
(uint32_t) &dummy, /* Vector # 271 DSPI1_3 DSPI_1_SR[TCF] */
(uint32_t) &dummy, /* Vector # 272 DSPI1_4 DSPI_1_SR[RFDF] */
(uint32_t) &dummy, /* Vector # 273 DSPI1_5 DSPI_1_SR[CMD_TCF] */
(uint32_t) &dummy, /* Vector # 274 DSPI1_6 DSPI_1_SR[CMDFFF] */
(uint32_t) &dummy, /* Vector # 275 DSPI1_7 DSPI_1_SR[SPEF] */
(uint32_t) &dummy, /* Vector # 276  */
(uint32_t) &dummy, /* Vector # 277 DSPI2_0 DSPI_2_SR[TFUF] | DSPI_2_SR[RFOF]| */
                   /*              DSPI_2_SR[TFIWF] */
(uint32_t) &dummy, /* Vector # 278 DSPI2_1 DSPI_2_SR[EOQF] */
(uint32_t) &dummy, /* Vector # 279 DSPI2_2 DSPI_2_SR[TFFF] */
(uint32_t) &dummy, /* Vector # 280 DSPI2_3 DSPI_2_SR[TCF] */
(uint32_t) &dummy, /* Vector # 281 DSPI2_4 DSPI_2_SR[RFDF] */
(uint32_t) &dummy, /* Vector # 282 DSPI2_5 DSPI_2_SR[CMD_TCF] */
(uint32_t) &dummy, /* Vector # 283 DSPI2_6 DSPI_2_SR[CMDFFF] */
(uint32_t) &dummy, /* Vector # 284 DSPI2_7 DSPI_2_SR[SPEF] */
(uint32_t) &dummy, /* Vector # 285 */
(uint32_t) &dummy, /* Vector # 286 DSPI3_0 DSPI_3_SR[TFUF] | DSPI_3_SR[RFOF]| */
                   /*              DSPI_3_SR[TFIWF] */
(uint32_t) &dummy, /* Vector # 287 DSPI3_1 DSPI_3_SR[EOQF] */
(uint32_t) &dummy, /* Vector # 288 DSPI3_2 DSPI_3_SR[TFFF] */
(uint32_t) &dummy, /* Vector # 289 DSPI3_3 DSPI_3_SR[TCF] */
(uint32_t) &dummy, /* Vector # 290 DSPI3_4 DSPI_3_SR[RFDF] */
(uint32_t) &dummy, /* Vector # 291 DSPI3_5 DSPI_3_SR[CMD_TCF] */
(uint32_t) &dummy, /* Vector # 292 DSPI3_6 DSPI_3_SR[CMDFFF] */
(uint32_t) &dummy, /* Vector # 293 DSPI3_7 DSPI_3_SR[SPEF] */
(uint32_t) &dummy, /* Vector # 294 */
(uint32_t) &dummy, /* Vector # 295 DSPI4_0 DSPI_4_SR[TFUF] | DSPI_4_SR[RFOF]| */
                   /*              DSPI_4_SR[TFIWF] */
(uint32_t) &dummy, /* Vector # 296 DSPI4_1 DSPI_4_SR[EOQF] */
(uint32_t) &dummy, /* Vector # 297 DSPI4_2 DSPI_4_SR[TFFF] */
(uint32_t) &dummy, /* Vector # 298 DSPI4_3 DSPI_4_SR[TCF] */
(uint32_t) &dummy, /* Vector # 299 DSPI4_4 DSPI_4_SR[RFDF] */
(uint32_t) &dummy, /* Vector # 300 DSPI4_5 DSPI_4_SR[CMD_TCF] */

(uint32_t) &dummy, /* Vector # 301 DSPI4_6 DSPI_4_SR[CMDFFF] */
(uint32_t) &dummy, /* Vector # 302 DSPI4_7 DSPI_4_SR[SPEF] */
(uint32_t) &dummy, /* Vector # 303 */
(uint32_t) &dummy, /* Vector # 304 DSPI_M0_0 DSPI_M0_SR[TFUF] | DSPI_M0_SR[RFOF] | */
                   /*              DSPI_M0_SR[TFIWF] */
(uint32_t) &dummy, /* Vector # 305 DSPI_M0_1 DSPI_M0_SR[EOQF] */
(uint32_t) &dummy, /* Vector # 306 DSPI_M0_2 DSPI_M0_SR[TFFF] */
(uint32_t) &dummy, /* Vector # 307 DSPI_M0_3 DSPI_M0_SR[TCF] */
(uint32_t) &dummy, /* Vector # 308 DSPI_M0_4 DSPI_M0_SR[RFDF] */
(uint32_t) &dummy, /* Vector # 309 DSPI_M0_5 DSPI_M0_SR[SPITCF] | */
                   /*              DSPI_M0_SR[CMD_TCF] */
(uint32_t) &dummy, /* Vector # 310 DSPI_M0_6 DSPI_M0_SR[DSITCF] | */
                   /*              DSPI_M0_SR[CMDFFF] */
(uint32_t) &dummy, /* Vector # 311 DSPI_M0_7 DSPI_M0_SR[SPEF] | DSPI_M0_SR[DPEF] */
(uint32_t) &dummy, /* Vector # 312 DSPI_M0_8 DSPI_M0_SR[DDIF] */
(uint32_t) &dummy, /* Vector # 313 DSPI_M1_0 DSPI_M1_SR[TFUF] | DSPI_M1_SR[RFOF] | */
                   /*              DSPI_M1_SR[TFIWF] */
(uint32_t) &dummy, /* Vector # 314 DSPI_M1_1 DSPI_M1_SR[EOQF] */
(uint32_t) &dummy, /* Vector # 315 DSPI_M1_2 DSPI_M1_SR[TFFF] */
(uint32_t) &dummy, /* Vector # 316 DSPI_M1_3 DSPI_M1_SR[TCF] */
(uint32_t) &dummy, /* Vector # 317 DSPI_M1_4 DSPI_M1_SR[RFDF] */
(uint32_t) &dummy, /* Vector # 318 DSPI_M1_5 DSPI_M1_SR[SPITCF] | */
                   /*              DSPI_M1_SR[CMD_TCF] */
(uint32_t) &dummy, /* Vector # 319 DSPI_M1_6 DSPI_M1_SR[DSITCF] | */
                   /*              DSPI_M1_SR[CMDFFF] */
(uint32_t) &dummy, /* Vector # 320 DSPI_M1_7 DSPI_M1_SR[SPEF] | DSPI_M1_SR[DPEF] */
(uint32_t) &dummy, /* Vector # 321 DSPI_M1_8 DSPI_M1_SR[DDIF] */
(uint32_t) &dummy, /* Vector # 322 */
(uint32_t) &dummy, /* Vector # 323 */
(uint32_t) &dummy, /* Vector # 324 */
(uint32_t) &dummy, /* Vector # 325 */
(uint32_t) &dummy, /* Vector # 326 */
(uint32_t) &dummy, /* Vector # 327 */
(uint32_t) &dummy, /* Vector # 328 */
(uint32_t) &dummy, /* Vector # 329 */
(uint32_t) &dummy, /* Vector # 330 */
(uint32_t) &dummy, /* Vector # 331 */
(uint32_t) &dummy, /* Vector # 332 */
(uint32_t) &dummy, /* Vector # 333 */
(uint32_t) &dummy, /* Vector # 334 */
(uint32_t) &dummy, /* Vector # 335 */
(uint32_t) &dummy, /* Vector # 336 */
(uint32_t) &dummy, /* Vector # 337 */
(uint32_t) &dummy, /* Vector # 338 */
(uint32_t) &dummy, /* Vector # 339 */
(uint32_t) &dummy, /* Vector # 340 */
(uint32_t) &dummy, /* Vector # 341 */
(uint32_t) &dummy, /* Vector # 342 */
(uint32_t) &dummy, /* Vector # 343 */
(uint32_t) &dummy, /* Vector # 344 */
(uint32_t) &dummy, /* Vector # 345 */
(uint32_t) &dummy, /* Vector # 346 */
(uint32_t) &dummy, /* Vector # 347 */
(uint32_t) &dummy, /* Vector # 348 */
(uint32_t) &dummy, /* Vector # 349 */
(uint32_t) &dummy, /* Vector # 350 */
(uint32_t) &dummy, /* Vector # 351 */
(uint32_t) &dummy, /* Vector # 352 */
(uint32_t) &dummy, /* Vector # 353 */
(uint32_t) &dummy, /* Vector # 354 */
(uint32_t) &dummy, /* Vector # 355 */
(uint32_t) &dummy, /* Vector # 356 */
(uint32_t) &dummy, /* Vector # 357 */
(uint32_t) &dummy, /* Vector # 358 */
(uint32_t) &dummy, /* Vector # 359 */
(uint32_t) &dummy, /* Vector # 360 */
(uint32_t) &dummy, /* Vector # 361 */
(uint32_t) &dummy, /* Vector # 362 */
(uint32_t) &dummy, /* Vector # 363 */
(uint32_t) &dummy, /* Vector # 364 */
(uint32_t) &dummy, /* Vector # 365 */
(uint32_t) &dummy, /* Vector # 366 */
(uint32_t) &dummy, /* Vector # 367 */
(uint32_t) &dummy, /* Vector # 368 */
(uint32_t) &dummy, /* Vector # 369 */
(uint32_t) &dummy, /* Vector # 370 */
(uint32_t) &dummy, /* Vector # 371 */
(uint32_t) &dummy, /* Vector # 372 */
(uint32_t) &dummy, /* Vector # 373 */
(uint32_t) &dummy, /* Vector # 374 */
(uint32_t) &dummy, /* Vector # 375 */
(uint32_t) &dummy, /* Vector # 376 Linflex/eSCI0_0 LINFlex_0_RXI */
(uint32_t) &dummy, /* Vector # 377 Linflex/eSCI0_1 LINFlex_0_TXI */
(uint32_t) &dummy, /* Vector # 378 Linflex/eSCI0_2 LINFlex_0_ERR */
(uint32_t) &dummy, /* Vector # 379 */
(uint32_t) &dummy, /* Vector # 380 Linflex/eSCI1_0 LinFlex_1_RXI */
(uint32_t) &dummy, /* Vector # 381 Linflex/eSCI1_0 LINFlex_1_TXI */
(uint32_t) &dummy, /* Vector # 382 Linflex/eSCI1_1 LINFlex_1_ERR */
(uint32_t) &dummy, /* Vector # 383 */
(uint32_t) &dummy, /* Vector # 384 Linflex/eSCI2_0 LINFlex_2_RXI */
(uint32_t) &dummy, /* Vector # 385 Linflex/eSCI2_1 LINFlex_2_TXI */
(uint32_t) &dummy, /* Vector # 386 Linflex/eSCI2_2 LINFlex_2_ERR */
(uint32_t) &dummy, /* Vector # 387 */
(uint32_t) &dummy, /* Vector # 388 Linflex/eSCI3_0 LINFlex_3_RXI */
(uint32_t) &dummy, /* Vector # 389 Linflex/eSCI3_1 LINFlex_3_TXI */
(uint32_t) &dummy, /* Vector # 390 Linflex/eSCI3_2 LINFlex_3_ERR */
(uint32_t) &dummy, /* Vector # 391 */
(uint32_t) &dummy, /* Vector # 392 Linflex/eSCI_M0_0 LINFlex_M0_RXI */
(uint32_t) &dummy, /* Vector # 393 Linflex/eSCI_M0_1 LINFlex_M0_TXI */
(uint32_t) &dummy, /* Vector # 394 Linflex/eSCI_M0_2 LINFlex_M0_ERR */
(uint32_t) &dummy, /* Vector # 395 */
(uint32_t) &dummy, /* Vector # 396 Linflex/eSCI_M1_0 LINFlex_M1_RXI */
(uint32_t) &dummy, /* Vector # 397 Linflex/eSCI_M1_1 LINFlex_M1_TXI */
(uint32_t) &dummy, /* Vector # 398 Linflex/eSCI_M1_2 LINFlex_M1_ERR */
(uint32_t) &dummy, /* Vector # 399 */
(uint32_t) &dummy, /* Vector # 400 */

(uint32_t) &dummy, /* Vector # 401 */
(uint32_t) &dummy, /* Vector # 402 */
(uint32_t) &dummy, /* Vector # 403 */
(uint32_t) &dummy, /* Vector # 404 */
(uint32_t) &dummy, /* Vector # 405 */
(uint32_t) &dummy, /* Vector # 406 */
(uint32_t) &dummy, /* Vector # 407 */
(uint32_t) &dummy, /* Vector # 408 */
(uint32_t) &dummy, /* Vector # 409 */
(uint32_t) &dummy, /* Vector # 410 */
(uint32_t) &dummy, /* Vector # 411 */
(uint32_t) &dummy, /* Vector # 412 */
(uint32_t) &dummy, /* Vector # 413 */
(uint32_t) &dummy, /* Vector # 414 */
(uint32_t) &dummy, /* Vector # 415 */
(uint32_t) &dummy, /* Vector # 416 */
(uint32_t) &dummy, /* Vector # 417 */
(uint32_t) &dummy, /* Vector # 418 */
(uint32_t) &dummy, /* Vector # 419 */
(uint32_t) &dummy, /* Vector # 420 */
(uint32_t) &dummy, /* Vector # 421 */
(uint32_t) &dummy, /* Vector # 422 */
(uint32_t) &dummy, /* Vector # 423 */
(uint32_t) &dummy, /* Vector # 424 */
(uint32_t) &dummy, /* Vector # 425 */
(uint32_t) &dummy, /* Vector # 426 */
(uint32_t) &dummy, /* Vector # 427 */
(uint32_t) &dummy, /* Vector # 428 */
(uint32_t) &dummy, /* Vector # 429 */
(uint32_t) &dummy, /* Vector # 430 */
(uint32_t) &dummy, /* Vector # 431 */
(uint32_t) &dummy, /* Vector # 432 */
(uint32_t) &dummy, /* Vector # 433 */
(uint32_t) &dummy, /* Vector # 434 */
(uint32_t) &dummy, /* Vector # 435 */
(uint32_t) &dummy, /* Vector # 436 */
(uint32_t) &dummy, /* Vector # 437 */
(uint32_t) &dummy, /* Vector # 438 */
(uint32_t) &dummy, /* Vector # 439 */
(uint32_t) &dummy, /* Vector # 440 */
(uint32_t) &dummy, /* Vector # 441 */
(uint32_t) &dummy, /* Vector # 442 */
(uint32_t) &dummy, /* Vector # 443 */
(uint32_t) &dummy, /* Vector # 444 */
(uint32_t) &dummy, /* Vector # 445 */
(uint32_t) &dummy, /* Vector # 446 */
(uint32_t) &dummy, /* Vector # 447 */
(uint32_t) &dummy, /* Vector # 448 */
(uint32_t) &dummy, /* Vector # 449 */
(uint32_t) &dummy, /* Vector # 450 */
(uint32_t) &dummy, /* Vector # 451 */
(uint32_t) &dummy, /* Vector # 452 */
(uint32_t) &dummy, /* Vector # 453 */
(uint32_t) &dummy, /* Vector # 454 */
(uint32_t) &dummy, /* Vector # 455 */
(uint32_t) &dummy, /* Vector # 456 */
(uint32_t) &dummy, /* Vector # 457 */
(uint32_t) &dummy, /* Vector # 458 */
(uint32_t) &dummy, /* Vector # 459 */
(uint32_t) &dummy, /* Vector # 460 */
(uint32_t) &dummy, /* Vector # 461 */
(uint32_t) &dummy, /* Vector # 462 */
(uint32_t) &dummy, /* Vector # 463 */
(uint32_t) &dummy, /* Vector # 464 */
(uint32_t) &dummy, /* Vector # 465 */
(uint32_t) &dummy, /* Vector # 466 */
(uint32_t) &dummy, /* Vector # 467 */
(uint32_t) &dummy, /* Vector # 468 */
(uint32_t) &dummy, /* Vector # 469 */
(uint32_t) &dummy, /* Vector # 470 */
(uint32_t) &dummy, /* Vector # 471 */
(uint32_t) &dummy, /* Vector # 472 */
(uint32_t) &dummy, /* Vector # 473 */
(uint32_t) &dummy, /* Vector # 474 */
(uint32_t) &dummy, /* Vector # 475 */
(uint32_t) &dummy, /* Vector # 476 */
(uint32_t) &dummy, /* Vector # 477 Power Monitor Unit GR_S[VD15] | GR_S[VD14] | GR_S[VD13] | */
                   /*              GR_S[VD12] | GR_S[VD10] | GR_S[VD9] | */
                   /*              GR_S[VD7] | GR_S[VD4] | GR_S[VD3] */
(uint32_t) &dummy, /* Vector # 478 Power management Unit (temp sensor) EPR_TD[TEMP_3] | EPR_TD[TEMP_2] | */
                   /*              EPR_TD[TEMP_0] */
(uint32_t) &dummy, /* Vector # 479 */ 
(uint32_t) &dummy, /* Vector # 480 PLL_0_0 PLL0SR[LOLF] */
(uint32_t) &dummy, /* Vector # 481 */
(uint32_t) &dummy, /* Vector # 482 PLL_1_0 PLL1SR[LOLF] */
(uint32_t) &dummy, /* Vector # 483 */
(uint32_t) &dummy, /* Vector # 484 PLL_0_1 PLL0SR[EXTPDF] */
(uint32_t) &dummy, /* Vector # 485 PLL_1_1 PLL1SR[EXTPDF] */
(uint32_t) &dummy, /* Vector # 486 */
(uint32_t) &dummy, /* Vector # 487 */
(uint32_t) &dummy, /* Vector # 488 FCCU_0 FCCU_IRQ_STAT[ALRM_STAT] */
(uint32_t) &dummy, /* Vector # 489 FCCU_1 FCU_IRQ_STAT[CFG_TO_STAT] */
(uint32_t) &dummy, /* Vector # 490 FCCU_2 FCCU_SCFS[RCCS0] */
(uint32_t) &dummy, /* Vector # 491 FCCU_3 FCCU_SCFS[RCCS1] */
(uint32_t) &dummy, /* Vector # 492 */
(uint32_t) &dummy, /* Vector # 493 */
(uint32_t) &dummy, /* Vector # 494 STCU2_0 STCU_RUNSW[LBIE] */
(uint32_t) &dummy, /* Vector # 495 STCU2_1 STCU_RUNSW[MBIE] */
(uint32_t) &dummy, /* Vector # 496 */
(uint32_t) &dummy, /* Vector # 497 */
(uint32_t) &dummy, /* Vector # 498 */
(uint32_t) &dummy, /* Vector # 499 */
(uint32_t) &dummy, /* Vector # 500 */

(uint32_t) &dummy, /* Vector # 501 */
(uint32_t) &dummy, /* Vector # 502 */
(uint32_t) &dummy, /* Vector # 503 */
(uint32_t) &dummy, /* Vector # 504 */
(uint32_t) &dummy, /* Vector # 505 */
(uint32_t) &dummy, /* Vector # 506 */
(uint32_t) &dummy, /* Vector # 507 */
(uint32_t) &dummy, /* Vector # 508 */
(uint32_t) &dummy, /* Vector # 509 */
(uint32_t) &dummy, /* Vector # 510 */
(uint32_t) &dummy, /* Vector # 511 */
(uint32_t) &dummy, /* Vector # 512 */
(uint32_t) &dummy, /* Vector # 513 */
(uint32_t) &dummy, /* Vector # 514 */
(uint32_t) &dummy, /* Vector # 515 */
(uint32_t) &dummy, /* Vector # 516 */
(uint32_t) &dummy, /* Vector # 517 */
(uint32_t) &dummy, /* Vector # 518 */
(uint32_t) &dummy, /* Vector # 519 */
(uint32_t) &dummy, /* Vector # 520 */
(uint32_t) &dummy, /* Vector # 521 */
(uint32_t) &dummy, /* Vector # 522 */
(uint32_t) &dummy, /* Vector # 523 */
(uint32_t) &dummy, /* Vector # 524 */
(uint32_t) &dummy, /* Vector # 525 */
(uint32_t) &dummy, /* Vector # 526 */
(uint32_t) &dummy, /* Vector # 527 */
(uint32_t) &dummy, /* Vector # 528 SAR_ADC0 Combined interrupt SAR_ADC_0_EOCTU (end of CTU injected */
                   /*              conversion) */
                   /*              SAR_ADC_0_JEOC (end of injected */
                   /*              conversion of each channel) */
                   /*              SAR_ADC_0_JECH (end of injected chain) */
                   /*              SAR_ADC_0_EOC (end of normal conversion */
                   /*              of each channel) */
                   /*              SAR_ADC_0_ECH (end of normal chain) */
(uint32_t) &dummy, /* Vector # 529 SAR_ADC0_ER SAR_ADC0_ER */
(uint32_t) &dummy, /* Vector # 530 SAR_ADC0_WD SAR_ADC0_WD */
(uint32_t) &dummy, /* Vector # 531 */
(uint32_t) &dummy, /* Vector # 532 SAR_ADC1 Combined interrupt SAR_ADC_1_EOCTU (end of CTU injected */
                   /*              conversion) */
                   /*              SAR_ADC_1_JEOC (end of injected */
                   /*              conversion of each channel) */
                   /*              SAR_ADC_1_JECH (end of injected chain) */
                   /*              SAR_ADC_1_EOC (end of normal conversion */
                   /*              of each channel) */
                   /*              SAR_ADC_1_ECH (end of normal chain) */
(uint32_t) &dummy, /* Vector # 533 SAR_ADC1_ER SAR_ADC1_ER */
(uint32_t) &dummy, /* Vector # 534 SAR_ADC1_WD SAR_ADC1_WD */
(uint32_t) &dummy, /* Vector # 535 */
(uint32_t) &dummy, /* Vector # 536 SAR_ADC2 Combined interrupt SAR_ADC_2_EOCTU (end of CTU injected */
                   /*              conversion) */
                   /*              SAR_ADC_2_JEOC (end of injected */
                   /*              conversion of each channel) */
                   /*              SAR_ADC_2_JECH (end of injected chain) */
                   /*              SAR_ADC_2_EOC (end of normal conversion */
                   /*              of each channel) */
                   /*              SAR_ADC_2_ECH (end of normal chain) */
(uint32_t) &dummy, /* Vector # 537 SAR_ADC2_ER SAR_ADC2_ER */
(uint32_t) &dummy, /* Vector # 538 SAR_ADC2_WD SAR_ADC2_WD */
(uint32_t) &dummy, /* Vector # 539 */
(uint32_t) &dummy, /* Vector # 540 SAR_ADC3 Combined interrupt SAR_ADC_3_EOCTU (end of CTU injected */
                   /*              conversion) */
                   /*              SAR_ADC_3_JEOC (end of injected */
                   /*              conversion of each channel) */
                   /*              SAR_ADC_3_JECH (end of injected chain) */
                   /*              SAR_ADC_3_EOC (end of normal conversion */
                   /*              of each channel) */
                   /*              SAR_ADC_3_ECH (end of normal chain) */
(uint32_t) &dummy, /* Vector # 541 SAR_ADC3_ER SAR_ADC3_ER */
(uint32_t) &dummy, /* Vector # 542 SAR_ADC3_WD SAR_ADC3_WD */
(uint32_t) &dummy, /* Vector # 543 */
(uint32_t) &dummy, /* Vector # 544 SD_ADC0 SD_ADC0 */
(uint32_t) &dummy, /* Vector # 545 SD_ADC1 SD_ADC1 */
(uint32_t) &dummy, /* Vector # 546 SD_ADC2 SD_ADC2 */
(uint32_t) &dummy, /* Vector # 547 */
(uint32_t) &dummy, /* Vector # 548 */
(uint32_t) &dummy, /* Vector # 549 */
(uint32_t) &dummy, /* Vector # 550 */
(uint32_t) &dummy, /* Vector # 551 */
(uint32_t) &dummy, /* Vector # 552 */
(uint32_t) &dummy, /* Vector # 553 */
(uint32_t) &dummy, /* Vector # 554 */
(uint32_t) &dummy, /* Vector # 555 */
(uint32_t) &dummy, /* Vector # 556 */
(uint32_t) &dummy, /* Vector # 557 */
(uint32_t) &dummy, /* Vector # 558 SENT_COMBINED_FAST_0 SENT_0_FMSG_RDY[0] | */
                   /*              SENT_0_FMSG_RDY[1] | */
                   /*              SENT_0_FMSG_RDY[2] | */
                   /*              SENT_0_FMSG_RDY[3] | */
                   /*              SENT_0_FMSG_RDY[4] */
(uint32_t) &dummy, /* Vector # 559 SENT_COMBINED_SLOW_0 SENT_0_SMSG_RDY[0] | */
                   /*              SENT_0_SMSG_RDY[1] | */
                   /*              SENT_0_SMSG_RDY[2] | */
                   /*              SENT_0_SMSG_RDY[3] | */
                   /*              SENT_0_SMSG_RDY[4] */
(uint32_t) &dummy, /* Vector # 560 SENT_COMBINED_ERR_0 SENT_0_GBL_STATUS[FMDU] | */
                   /*              SENT_0_GBL_STATUS[SMDU] | */
                   /*              SENT_0_CHn_STATUS[4:7] | */
                   /*              SENT_0_CHn_STATUS[9:15] */
(uint32_t) &dummy, /* Vector # 561 SENT_COMBINED_FAST_1 SENT_1_FMSG_RDY[0] | */
                   /*              SENT_1_FMSG_RDY[1] | */
                   /*              SENT_1_FMSG_RDY[2] | */
                   /*              SENT_1_FMSG_RDY[3] | */
                   /*              SENT_1_FMSG_RDY[4] */
(uint32_t) &dummy, /* Vector # 562 SENT_COMBINED_SLOW_1 SENT_1_SMSG_RDY[0] | */
                   /*              SENT_1_SMSG_RDY[1] | */
                   /*              SENT_1_SMSG_RDY[2] | */
                   /*              SENT_1_SMSG_RDY[3] | */
                   /*              SENT_1_SMSG_RDY[4] */
(uint32_t) &dummy, /* Vector # 563 SENT_COMBINED_ERR_1 SENT_1_GBL_STATUS[FMDU] | */
                   /*              SENT_1_GBL_STATUS[SMDU] | */
                   /*              SENT_1_CHn_STATUS[4:7] | */
                   /*              SENT_1_CHn_STATUS[9:15] */
(uint32_t) &dummy, /* Vector # 564 SENT_0_CH0_FAST SENT_0_FMSG_RDY[0] */
(uint32_t) &dummy, /* Vector # 565 SENT_0_CH0_SLOW SENT_0_SMSG_RDY[0] */
(uint32_t) &dummy, /* Vector # 566 SENT_0_CH0_ERR SENT_0_CH0_STATUS[4:7] | */
                   /*              SENT_0_CH0_STATUS[9:15] */
(uint32_t) &dummy, /* Vector # 567 SENT_0_CH1_FAST SENT_0_FMSG_RDY[1] */
(uint32_t) &dummy, /* Vector # 568 SENT_0_CH1_SLOW SENT_0_SMSG_RDY[1] */
(uint32_t) &dummy, /* Vector # 569 SENT_0_CH1_ERR SENT_0_CH1_STATUS[4:7] | */
                   /*              SENT_0_CH1_STATUS[9:15] */
(uint32_t) &dummy, /* Vector # 570 SENT_0_CH2_FAST SENT_0_FMSG_RDY[2] */
(uint32_t) &dummy, /* Vector # 571 SENT_0_CH2_SLOW SENT_0_SMSG_RDY[2] */
(uint32_t) &dummy, /* Vector # 572 SENT_0_CH2_ERR SENT_0_CH2_STATUS[4:7] | */
                   /*              SENT_0_CH3_STATUS[9:15] */
(uint32_t) &dummy, /* Vector # 573 */
(uint32_t) &dummy, /* Vector # 574 */
(uint32_t) &dummy, /* Vector # 575 */
(uint32_t) &dummy, /* Vector # 576 */
(uint32_t) &dummy, /* Vector # 577 */
(uint32_t) &dummy, /* Vector # 578 */
(uint32_t) &dummy, /* Vector # 579 SENT_1_CH0_FAST SENT_1_FMSG_RDY[0] */
(uint32_t) &dummy, /* Vector # 580 SENT_1_CH0_SLOW SENT_1_SMSG_RDY[0] */
(uint32_t) &dummy, /* Vector # 581 SENT_1_CH0_ERR SENT_1_CH2_STATUS[4:7] | */
                   /*              SENT_1_CH2_STATUS[9:15] */
(uint32_t) &dummy, /* Vector # 582 SENT_1_CH1_FAST SENT_1_FMSG_RDY[1] */
(uint32_t) &dummy, /* Vector # 583 SENT_1_CH1_SLOW SENT_1_SMSG_RDY[1] */
(uint32_t) &dummy, /* Vector # 584 SENT_1_CH1_ERR SENT_1_CH1_STATUS[4:7] | */
                   /*              SENT_1_CH1_STATUS[9:15] */
(uint32_t) &dummy, /* Vector # 585 SENT_1_CH2_FAST SENT_1_FMSG_RDY[2] */
(uint32_t) &dummy, /* Vector # 586 SENT_1_CH2_SLOW SENT_1_SMSG_RDY[2] */
(uint32_t) &dummy, /* Vector # 587 SENT_1_CH2_ERR SENT_1_CH3_STATUS[4:7] | */
                   /*              SENT_1_CH3_STATUS[9:15] */
(uint32_t) &dummy, /* Vector # 588 */
(uint32_t) &dummy, /* Vector # 589 */
(uint32_t) &dummy, /* Vector # 590 */
(uint32_t) &dummy, /* Vector # 591 */
(uint32_t) &dummy, /* Vector # 592 */
(uint32_t) &dummy, /* Vector # 593 */
(uint32_t) &dummy, /* Vector # 594 */
(uint32_t) &dummy, /* Vector # 595 */
(uint32_t) &dummy, /* Vector # 596 */
(uint32_t) &dummy, /* Vector # 597 */
(uint32_t) &dummy, /* Vector # 598 */
(uint32_t) &dummy, /* Vector # 599 */
(uint32_t) &dummy, /* Vector # 600 */

(uint32_t) &dummy, /* Vector # 601 */
(uint32_t) &dummy, /* Vector # 602 */
(uint32_t) &dummy, /* Vector # 603 */
(uint32_t) &dummy, /* Vector # 604 */
(uint32_t) &dummy, /* Vector # 605 */
(uint32_t) &dummy, /* Vector # 606 */
(uint32_t) &dummy, /* Vector # 607 */
(uint32_t) &dummy, /* Vector # 608 */
(uint32_t) &dummy, /* Vector # 609 */
(uint32_t) &dummy, /* Vector # 600 */
(uint32_t) &dummy, /* Vector # 611 */
(uint32_t) &dummy, /* Vector # 612 */
(uint32_t) &dummy, /* Vector # 613 */
(uint32_t) &dummy, /* Vector # 614 */
(uint32_t) &dummy, /* Vector # 615 */
(uint32_t) &dummy, /* Vector # 616 */
(uint32_t) &dummy, /* Vector # 617 */
(uint32_t) &dummy, /* Vector # 618 */
(uint32_t) &dummy, /* Vector # 619 */
(uint32_t) &dummy, /* Vector # 620 */
(uint32_t) &dummy, /* Vector # 621 */
(uint32_t) &dummy, /* Vector # 622 */
(uint32_t) &dummy, /* Vector # 623 */
(uint32_t) &dummy, /* Vector # 624 */
(uint32_t) &dummy, /* Vector # 625 */
(uint32_t) &dummy, /* Vector # 626 */
(uint32_t) &dummy, /* Vector # 627 */
(uint32_t) &dummy, /* Vector # 628 */
(uint32_t) &dummy, /* Vector # 629 */
(uint32_t) &dummy, /* Vector # 630 */
(uint32_t) &dummy, /* Vector # 631 */
(uint32_t) &dummy, /* Vector # 632 */
(uint32_t) &dummy, /* Vector # 633 */
(uint32_t) &dummy, /* Vector # 634 */
(uint32_t) &dummy, /* Vector # 635 */
(uint32_t) &dummy, /* Vector # 636 */
(uint32_t) &dummy, /* Vector # 637 */
(uint32_t) &dummy, /* Vector # 638 */
(uint32_t) &dummy, /* Vector # 639 */
(uint32_t) &dummy, /* Vector # 640 */
(uint32_t) &dummy, /* Vector # 641 */
(uint32_t) &dummy, /* Vector # 642 */
(uint32_t) &dummy, /* Vector # 643 */
(uint32_t) &dummy, /* Vector # 644 */
(uint32_t) &dummy, /* Vector # 645 */
(uint32_t) &dummy, /* Vector # 646 */
(uint32_t) &dummy, /* Vector # 647 */
(uint32_t) &dummy, /* Vector # 648 */
(uint32_t) &dummy, /* Vector # 649 */
(uint32_t) &dummy, /* Vector # 650 */
(uint32_t) &dummy, /* Vector # 651 */
(uint32_t) &dummy, /* Vector # 652 */
(uint32_t) &dummy, /* Vector # 653 */
(uint32_t) &dummy, /* Vector # 654 SIPI_0 SIPI_ERR[TOEn] | SIPI_ERR[TIDEn] | */
                   /*              SIPI_ERR[ACKEn] */
(uint32_t) &dummy, /* Vector # 655 SIPI_1 SIPI_SR[GCRCE) */
(uint32_t) &dummy, /* Vector # 656 SIPI_2 SIPI_CSR0[RAR] | SIPI_CSR0[ACKR] */
(uint32_t) &dummy, /* Vector # 657 SIPI_3 SIPI_CSR1[RAR] | SIPI_CSR1[ACKR] */
(uint32_t) &dummy, /* Vector # 658 SIPI_4 SIPI_CSR2[RAR] | SIPI_CSR2[ACKR] */
(uint32_t) &dummy, /* Vector # 659 SIPI_5 SIPI_CSR3[RAR] | SIPI_CSR3[ACKR] */
(uint32_t) &dummy, /* Vector # 660 SIPI_6 SIPI_SR[TE0] | SIPI_SR[TE1] |SIPI_SR[TE2] | */
                   /*              SIPI_SR[TE3] |SIPI_SR[MCR] */
(uint32_t) &dummy, /* Vector # 661 LFAST0_0 LFAST_0_TISR[TXPNGF] | */
                   /*              LFAST_0_TISR[TXUNSF] | */
                   /*              LFAST_0_TISR[TXICLCF] | */
                   /*              LFAST_0_TISR[TXDTF] */
(uint32_t) &dummy, /* Vector # 662 LFAST0_1 LFAST_0_TISR[TXIEF] | */
                   /*              LFAST_0_TISR[TXOVF] */
(uint32_t) &dummy, /* Vector # 663 LFAST0_2 LFAST_0_RISR[RXCTSF] | */
                   /*              LFAST_0_RISR[RXDF] | */
                   /*              LFAST_0_RISR[RXUNSF] */
(uint32_t) &dummy, /* Vector # 664 LFAST0_3 LFAST_0_RISR[RXUOF] | */
                   /*              LFAST_0_RISR[RXMNF] | */
                   /*              LFAST_0_RISR[RXMXF] | */
                   /*              LFAST_0_RISR[RXUFF] | */
                   /*              LFAST_0_RISR[RXOFF] | */
                   /*              LFAST_0_RISR[RXSZF] | */
                   /*              LFAST_0_RISR[RXICF] | */
                   /*              LFAST_0_RISR[RXLCEF] */
(uint32_t) &dummy, /* Vector # 665 LFAST0_4 LFAST_0_RIISR[ICPFF] | */
                   /*              LFAST_0_RIISR[ICPSF] | */
                   /*              LFAST_0_RIISR[ICPRF] | */
                   /*              LFAST_0_RIISR[ICTOF] | */
                   /*              LFAST_0_RIISR[ICLPF] | */
                   /*              LFAST_0_RIISR[ICCTF] | */
                   /*              LFAST_0_RIISR[ICTDF] | */
                   /*              LFAST_0_RIISR[ICTEF] | */
                   /*              LFAST_0_RIISR[ICRFF] | */
                   /*              LFAST_0_RIISR[ICRSF] | */
                   /*              LFAST_0_RIISR[ICTFF] | */
                   /*              LFAST_0_RIISR[ICTSF] | */
                   /*              LFAST_0_RIISR[ICPOFF] | */
                   /*              LFAST_0_RIISR[ICPONF] */
(uint32_t) &dummy, /* Vector # 666 */
(uint32_t) &dummy, /* Vector # 667 */
(uint32_t) &dummy, /* Vector # 668 */
(uint32_t) &dummy, /* Vector # 669 */
(uint32_t) &dummy, /* Vector # 670 */
(uint32_t) &dummy, /* Vector # 671 */
(uint32_t) &dummy, /* Vector # 672 */
(uint32_t) &dummy, /* Vector # 673 */
(uint32_t) &dummy, /* Vector # 674 JTAGM JTAGM_SR[SPU_INT] | JTAGM_SR[Idle] */
(uint32_t) &dummy, /* Vector # 675 JDC JDC_MSR[JIN_INT] | JDC_MSR[JOUT_INT] */
(uint32_t) &dummy, /* Vector # 676 */
(uint32_t) &dummy, /* Vector # 677 FlexCAN_0_0 CAN0_ESR[BOFF_INT] */
(uint32_t) &dummy, /* Vector # 678 FlexCAN_0_1 CAN0_ESR[ERR_INT] */
(uint32_t) &dummy, /* Vector # 679 FlexCAN_0_5 CAN0_IFRL[BUF7:BUF0] */
(uint32_t) &dummy, /* Vector # 680 FlexCAN_0_2 CAN0_IFRL[BUF15:BUF8] */
(uint32_t) &dummy, /* Vector # 681 FlexCAN_0_3 CAN0_IFRL[BUF31:BUF16] */
(uint32_t) &dummy, /* Vector # 682 FlexCAN_0_4 CAN0_IFRL[BUF63:BUF32] */
(uint32_t) &dummy, /* Vector # 683 FlexCAN_1_0 CAN1_ESR[BOFF_INT] */
(uint32_t) &dummy, /* Vector # 684 FlexCAN_1_1 CAN1_ESR[ERR_INT] */
(uint32_t) &dummy, /* Vector # 685 FlexCAN_1_5 CAN1_IFRL[BUF7:BUF0] */
(uint32_t) &dummy, /* Vector # 686 FlexCAN_1_2 CAN1_IFRL[BUF15:BUF8] */
(uint32_t) &dummy, /* Vector # 687 FlexCAN_1_3 CAN1_IFRL[BUF31:BUF16] */
(uint32_t) &dummy, /* Vector # 688 FlexCAN_1_4 CAN1_IFRL[BUF63:BUF32] */
(uint32_t) &dummy, /* Vector # 689 FlexCAN_2_0 CAN2_ESR[BOFF_INT] */
(uint32_t) &dummy, /* Vector # 690 lexCAN_2_1 CAN2_ESR[ERR_INT] */
(uint32_t) &dummy, /* Vector # 691 FlexCAN_2_5 CAN2_IFRL[BUF7:BUF0] */
(uint32_t) &dummy, /* Vector # 692 FlexCAN_2_2 CAN2_IFRL[BUF15:BUF8] */
(uint32_t) &dummy, /* Vector # 693 FlexCAN_2_3 CAN2_IFRL[BUF31:BUF16] */
(uint32_t) &dummy, /* Vector # 694 FlexCAN_2_4 CAN2_IFRL[BUF63:BUF32] */
(uint32_t) &dummy, /* Vector # 695 FlexCAN_3_0 CAN3_ESR[BOFF_INT] */
(uint32_t) &dummy, /* Vector # 696 FlexCAN_3_1 CAN3_ESR[ERR_INT] */
(uint32_t) &CAN3_RX_ISR, /* Vector # 697 FlexCAN_3_5 CAN3_IFRL[BUF7:BUF0] */
(uint32_t) &dummy, /* Vector # 698 FlexCAN_3_2 CAN3_IFRL[BUF15:BUF8] */
(uint32_t) &dummy, /* Vector # 699 FlexCAN_3_3 CAN3_IFRL[BUF31:BUF16] */
(uint32_t) &dummy, /* Vector # 700 FlexCAN_3_4 CAN3_IFRL[BUF63:BUF32] */

(uint32_t) &dummy, /* Vector # 701 */
(uint32_t) &dummy, /* Vector # 702 */
(uint32_t) &dummy, /* Vector # 703 */
(uint32_t) &dummy, /* Vector # 704 */
(uint32_t) &dummy, /* Vector # 705 */
(uint32_t) &dummy, /* Vector # 706 eMIOS_0 channel 8 EMIOS_0_GFR[F8] */
(uint32_t) &dummy, /* Vector # 707 eMIOS_0 channel 9 EMIOS_0_GFR[F9] */
(uint32_t) &dummy, /* Vector # 708 eMIOS_0 channel 10 EMIOS_0_GFR[F10] */
(uint32_t) &dummy, /* Vector # 709 eMIOS_0 channel 11 EMIOS_0_GFR[F11] */
(uint32_t) &dummy, /* Vector # 710 eMIOS_0 channel 12 EMIOS_0_GFR[F12] */
(uint32_t) &dummy, /* Vector # 711 eMIOS_0 channel 13 EMIOS_0_GFR[F13] */
(uint32_t) &dummy, /* Vector # 712 eMIOS_0 channel 14 EMIOS_0_GFR[F14] */
(uint32_t) &dummy, /* Vector # 713 eMIOS_0 channel 15 EMIOS_0_GFR[F15] */
(uint32_t) &dummy, /* Vector # 714 eMIOS_0 channel 16 EMIOS_0_GFR[F16] */
(uint32_t) &dummy, /* Vector # 715 eMIOS_0 channel 17 EMIOS_0_GFR[F17] */
(uint32_t) &dummy, /* Vector # 716 eMIOS_0 channel 18 EMIOS_0_GFR[F18] */
(uint32_t) &dummy, /* Vector # 717 eMIOS_0 channel 19 EMIOS_0_GFR[F19] */
(uint32_t) &dummy, /* Vector # 718 eMIOS_0 channel 20 EMIOS_0_GFR[F20] */
(uint32_t) &dummy, /* Vector # 719 eMIOS_0 channel 21 EMIOS_0_GFR[F21] */
(uint32_t) &dummy, /* Vector # 720 eMIOS_0 channel 22 EMIOS_0_GFR[F22] */
(uint32_t) &dummy, /* Vector # 721 eMIOS_0 channel 23 EMIOS_0_GFR[F23] */
(uint32_t) &dummy, /* Vector # 722 eMIOS_1 channel 8 EMIOS_1_GFR[F8] */
(uint32_t) &dummy, /* Vector # 723 eMIOS_1 channel 9 EMIOS_1_GFR[F9] */
(uint32_t) &dummy, /* Vector # 724 eMIOS_1 channel 10 EMIOS_1_GFR[F10] */
(uint32_t) &dummy, /* Vector # 725 eMIOS_1 channel 11 EMIOS_1_GFR[F11] */
(uint32_t) &dummy, /* Vector # 726 eMIOS_1 channel 12 EMIOS_1_GFR[F12] */
(uint32_t) &dummy, /* Vector # 727 eMIOS_1 channel 13 EMIOS_1_GFR[F13] */
(uint32_t) &dummy, /* Vector # 728 eMIOS_1 channel 14 EMIOS_1_GFR[F14] */
(uint32_t) &dummy, /* Vector # 729 eMIOS_1 channel 15 EMIOS_1_GFR[F15] */
(uint32_t) &dummy, /* Vector # 730 eMIOS_1 channel 16 EMIOS_1_GFR[F16] */
(uint32_t) &dummy, /* Vector # 731 eMIOS_1 channel 17 EMIOS_1_GFR[F17] */
(uint32_t) &dummy, /* Vector # 732 eMIOS_1 channel 18 EMIOS_1_GFR[F18] */
(uint32_t) &dummy, /* Vector # 733 eMIOS_1 channel 19 EMIOS_1_GFR[F19] */
(uint32_t) &dummy, /* Vector # 734 eMIOS_1 channel 20 EMIOS_1_GFR[F20] */
(uint32_t) &dummy, /* Vector # 735 eMIOS_1 channel 21 EMIOS_1_GFR[F21] */
(uint32_t) &dummy, /* Vector # 736 eMIOS_1 channel 22 EMIOS_1_GFR[F22] */
(uint32_t) &dummy, /* Vector # 737 eMIOS_1 channel 23 EMIOS_1_GFR[F23] */
(uint32_t) &dummy, /* Vector # 738 eTPU Engine 0 and 1 Global Exception ETPU_MCRAB[MGEA,MGEB,ILFA,ILFB,SCM */
                   /*              MISF] */
(uint32_t) &dummy, /* Vector # 739 eTPU Engine 0 Channel 0 ETPU_CISR_0[CIS0] */
(uint32_t) &dummy, /* Vector # 740 eTPU Engine 0 Channel 1 ETPU_CISR_0[CIS1] */
(uint32_t) &dummy, /* Vector # 741 eTPU Engine 0 Channel 2 ETPU_CISR_0[CIS2] */
(uint32_t) &dummy, /* Vector # 742 eTPU Engine 0 Channel 3 ETPU_CISR_0[CIS3] */
(uint32_t) &dummy, /* Vector # 743 eTPU Engine 0 Channel 4 ETPU_CISR_0[CIS4] */
(uint32_t) &dummy, /* Vector # 744 eTPU Engine 0 Channel 5 ETPU_CISR_0[CIS5] */
(uint32_t) &dummy, /* Vector # 745 eTPU Engine 0 Channel 6 ETPU_CISR_0[CIS6] */
(uint32_t) &dummy, /* Vector # 746 eTPU Engine 0 Channel 7 ETPU_CISR_0[CIS7] */
(uint32_t) &dummy, /* Vector # 747 eTPU Engine 0 Channel 8 ETPU_CISR_0[CIS8] */
(uint32_t) &dummy, /* Vector # 748 eTPU Engine 0 Channel 9 ETPU_CISR_0[CIS9] */
(uint32_t) &dummy, /* Vector # 749 eTPU Engine 0 Channel 10 ETPU_CISR_0[CIS10] */
(uint32_t) &dummy, /* Vector # 750 eTPU Engine 0 Channel 11 ETPU_CISR_0[CIS11] */
(uint32_t) &dummy, /* Vector # 751 eTPU Engine 0 Channel 12 ETPU_CISR_0[CIS12] */
(uint32_t) &dummy, /* Vector # 752 eTPU Engine 0 Channel 13 ETPU_CISR_0[CIS13] */
(uint32_t) &dummy, /* Vector # 753 eTPU Engine 0 Channel 14 ETPU_CISR_0[CIS14] */
(uint32_t) &dummy, /* Vector # 754 eTPU Engine 0 Channel 15 ETPU_CISR_0[CIS15] */
(uint32_t) &dummy, /* Vector # 755 eTPU Engine 0 Channel 16 ETPU_CISR_0[CIS16] */
(uint32_t) &dummy, /* Vector # 756 eTPU Engine 0 Channel 17 ETPU_CISR_0[CIS17] */
(uint32_t) &dummy, /* Vector # 757 eTPU Engine 0 Channel 18 ETPU_CISR_0[CIS18] */
(uint32_t) &dummy, /* Vector # 758 eTPU Engine 0 Channel 19 ETPU_CISR_0[CIS19] */
(uint32_t) &dummy, /* Vector # 759 eTPU Engine 0 Channel 20 ETPU_CISR_0[CIS20] */
(uint32_t) &dummy, /* Vector # 760 eTPU Engine 0 Channel 21 ETPU_CISR_0[CIS21] */
(uint32_t) &dummy, /* Vector # 761 eTPU Engine 0 Channel 22 ETPU_CISR_0[CIS22] */
(uint32_t) &dummy, /* Vector # 762 eTPU Engine 0 Channel 23 ETPU_CISR_0[CIS23] */
(uint32_t) &dummy, /* Vector # 763 eTPU Engine 0 Channel 24 ETPU_CISR_0[CIS24] */
(uint32_t) &dummy, /* Vector # 764 eTPU Engine 0 Channel 25 ETPU_CISR_0[CIS25] */
(uint32_t) &dummy, /* Vector # 765 eTPU Engine 0 Channel 26 ETPU_CISR_0[CIS26] */
(uint32_t) &dummy, /* Vector # 766 eTPU Engine 0 Channel 27 ETPU_CISR_0[CIS27] */
(uint32_t) &dummy, /* Vector # 767 eTPU Engine 0 Channel 28 ETPU_CISR_0[CIS28] */
(uint32_t) &dummy, /* Vector # 768 eTPU Engine 0 Channel 29 ETPU_CISR_0[CIS29] */
(uint32_t) &dummy, /* Vector # 769 eTPU Engine 0 Channel 30 ETPU_CISR_0[CIS30] */
(uint32_t) &dummy, /* Vector # 770 eTPU Engine 0 Channel 31 ETPU_CISR_0[CIS31] */
(uint32_t) &dummy, /* Vector # 771 eTPU Engine 1 Channel 0 ETPU_CISR_1[CIS0] */
(uint32_t) &dummy, /* Vector # 772 eTPU Engine 1 Channel 1 ETPU_CISR_1[CIS1] */
(uint32_t) &dummy, /* Vector # 773 eTPU Engine 1 Channel 2 ETPU_CISR_1[CIS2] */
(uint32_t) &dummy, /* Vector # 774 eTPU Engine 1 Channel 3 ETPU_CISR_1[CIS3] */
(uint32_t) &dummy, /* Vector # 775 eTPU Engine 1 Channel 4 ETPU_CISR_1[CIS4] */
(uint32_t) &dummy, /* Vector # 776 eTPU Engine 1 Channel 5 ETPU_CISR_1[CIS5] */
(uint32_t) &dummy, /* Vector # 777 eTPU Engine 1 Channel 6 ETPU_CISR_1[CIS6] */
(uint32_t) &dummy, /* Vector # 778 eTPU Engine 1 Channel 7 ETPU_CISR_1[CIS7] */
(uint32_t) &dummy, /* Vector # 779 eTPU Engine 1 Channel 8 ETPU_CISR_1[CIS8] */
(uint32_t) &dummy, /* Vector # 780 eTPU Engine 1 Channel 9 ETPU_CISR_1[CIS9] */
(uint32_t) &dummy, /* Vector # 781 eTPU Engine 1 Channel 10 ETPU_CISR_1[CIS10] */
(uint32_t) &dummy, /* Vector # 782 eTPU Engine 1 Channel 11 ETPU_CISR_1[CIS11] */
(uint32_t) &dummy, /* Vector # 783 eTPU Engine 1 Channel 12 ETPU_CISR_1[CIS12] */
(uint32_t) &dummy, /* Vector # 784 eTPU Engine 1 Channel 13 ETPU_CISR_1[CIS13] */
(uint32_t) &dummy, /* Vector # 785 eTPU Engine 1 Channel 14 ETPU_CISR_1[CIS14] */
(uint32_t) &dummy, /* Vector # 786 eTPU Engine 1 Channel 15 ETPU_CISR_1[CIS15] */
(uint32_t) &dummy, /* Vector # 787 eTPU Engine 1 Channel 16 ETPU_CISR_1[CIS16] */
(uint32_t) &dummy, /* Vector # 788 eTPU Engine 1 Channel 17 ETPU_CISR_1[CIS17] */
(uint32_t) &dummy, /* Vector # 789 eTPU Engine 1 Channel 18 ETPU_CISR_1[CIS18] */
(uint32_t) &dummy, /* Vector # 790 eTPU Engine 1 Channel 19 ETPU_CISR_1[CIS19] */
(uint32_t) &dummy, /* Vector # 791 eTPU Engine 1 Channel 20 ETPU_CISR_1[CIS20] */
(uint32_t) &dummy, /* Vector # 792 eTPU Engine 1 Channel 21 ETPU_CISR_1[CIS21] */
(uint32_t) &dummy, /* Vector # 793 eTPU Engine 1 Channel 22 ETPU_CISR_1[CIS22] */
(uint32_t) &dummy, /* Vector # 794 eTPU Engine 1 Channel 23 ETPU_CISR_1[CIS23] */
(uint32_t) &dummy, /* Vector # 795 eTPU Engine 1 Channel 24 ETPU_CISR_1[CIS24] */
(uint32_t) &dummy, /* Vector # 796 eTPU Engine 1 Channel 25 ETPU_CISR_1[CIS25] */
(uint32_t) &dummy, /* Vector # 797 eTPU Engine 1 Channel 26 ETPU_CISR_1[CIS26] */
(uint32_t) &dummy, /* Vector # 798 eTPU Engine 1 Channel 27 ETPU_CISR_1[CIS27] */
(uint32_t) &dummy, /* Vector # 799 eTPU Engine 1 Channel 28 ETPU_CISR_1[CIS28] */
(uint32_t) &dummy, /* Vector # 800 eTPU Engine 1 Channel 29 ETPU_CISR_1[CIS29] */

(uint32_t) &dummy, /* Vector # 801 eTPU Engine 1 Channel 30 ETPU_CISR_1[CIS30] */
(uint32_t) &dummy, /* Vector # 802 eTPU Engine 1 Channel 31 ETPU_CISR_1[CIS31] */
(uint32_t) &dummy, /* Vector # 803 */
(uint32_t) &dummy, /* Vector # 804 */
(uint32_t) &dummy, /* Vector # 805 */
(uint32_t) &dummy, /* Vector # 806 */
(uint32_t) &dummy, /* Vector # 807 */
(uint32_t) &dummy, /* Vector # 808 */
(uint32_t) &dummy, /* Vector # 809 */
(uint32_t) &dummy, /* Vector # 810 */
(uint32_t) &dummy, /* Vector # 811 */
(uint32_t) &dummy, /* Vector # 812 */
(uint32_t) &dummy, /* Vector # 813 */
(uint32_t) &dummy, /* Vector # 814 */
(uint32_t) &dummy, /* Vector # 815 */
(uint32_t) &dummy, /* Vector # 816 */
(uint32_t) &dummy, /* Vector # 817 */
(uint32_t) &dummy, /* Vector # 818 */
(uint32_t) &dummy, /* Vector # 819 */
(uint32_t) &dummy, /* Vector # 820 */
(uint32_t) &dummy, /* Vector # 821 */
(uint32_t) &dummy, /* Vector # 822 */
(uint32_t) &dummy, /* Vector # 823 */
(uint32_t) &dummy, /* Vector # 824 */
(uint32_t) &dummy, /* Vector # 825 */
(uint32_t) &dummy, /* Vector # 826 */
(uint32_t) &dummy, /* Vector # 827 */
(uint32_t) &dummy, /* Vector # 828 */
(uint32_t) &dummy, /* Vector # 829 */
(uint32_t) &dummy, /* Vector # 830 */
(uint32_t) &dummy, /* Vector # 831 */
(uint32_t) &dummy, /* Vector # 832 */
(uint32_t) &dummy, /* Vector # 833 */
(uint32_t) &dummy, /* Vector # 834 */
(uint32_t) &dummy, /* Vector # 835 */
(uint32_t) &dummy, /* Vector # 836 */
(uint32_t) &dummy, /* Vector # 837 */
(uint32_t) &dummy, /* Vector # 838 */
(uint32_t) &dummy, /* Vector # 839 */
(uint32_t) &dummy, /* Vector # 840 */
(uint32_t) &dummy, /* Vector # 841 */
(uint32_t) &dummy, /* Vector # 842 */
(uint32_t) &dummy, /* Vector # 843 */
(uint32_t) &dummy, /* Vector # 844 */
(uint32_t) &dummy, /* Vector # 845 */
(uint32_t) &dummy, /* Vector # 846 */
(uint32_t) &dummy, /* Vector # 847 */
(uint32_t) &dummy, /* Vector # 848 */
(uint32_t) &dummy, /* Vector # 849 */
(uint32_t) &dummy, /* Vector # 850 */
(uint32_t) &dummy, /* Vector # 851 */
(uint32_t) &dummy, /* Vector # 852 */
(uint32_t) &dummy, /* Vector # 853 */
(uint32_t) &dummy, /* Vector # 854 */
(uint32_t) &dummy, /* Vector # 855 */
(uint32_t) &dummy, /* Vector # 856 */
(uint32_t) &dummy, /* Vector # 857 */
(uint32_t) &dummy, /* Vector # 858 */
(uint32_t) &dummy, /* Vector # 859 */
(uint32_t) &dummy, /* Vector # 860 */
(uint32_t) &dummy, /* Vector # 861 */
(uint32_t) &dummy, /* Vector # 862 */
(uint32_t) &dummy, /* Vector # 863 */
(uint32_t) &dummy, /* Vector # 864 */
(uint32_t) &dummy, /* Vector # 865 */
(uint32_t) &dummy, /* Vector # 866 */
(uint32_t) &dummy, /* Vector # 867 */
(uint32_t) &dummy, /* Vector # 868 */
(uint32_t) &dummy, /* Vector # 869 */
(uint32_t) &dummy, /* Vector # 870 */
(uint32_t) &dummy, /* Vector # 871 */
(uint32_t) &dummy, /* Vector # 872 */
(uint32_t) &dummy, /* Vector # 873 */
(uint32_t) &dummy, /* Vector # 874 */
(uint32_t) &dummy, /* Vector # 875 */
(uint32_t) &dummy, /* Vector # 876 */
(uint32_t) &dummy, /* Vector # 877 */
(uint32_t) &dummy, /* Vector # 878 */
(uint32_t) &dummy, /* Vector # 879 */
(uint32_t) &dummy, /* Vector # 880 */
(uint32_t) &dummy, /* Vector # 881 */
(uint32_t) &dummy, /* Vector # 882 */
(uint32_t) &dummy, /* Vector # 883 */
(uint32_t) &dummy, /* Vector # 884 */
(uint32_t) &dummy, /* Vector # 885 */
(uint32_t) &dummy, /* Vector # 886 */
(uint32_t) &dummy, /* Vector # 887 */
(uint32_t) &dummy, /* Vector # 888 */
(uint32_t) &dummy, /* Vector # 889 */
(uint32_t) &dummy, /* Vector # 890 */
(uint32_t) &dummy, /* Vector # 891 */
(uint32_t) &dummy, /* Vector # 892 */
(uint32_t) &dummy, /* Vector # 893 */
(uint32_t) &dummy, /* Vector # 894 */
(uint32_t) &dummy, /* Vector # 895 */
(uint32_t) &dummy, /* Vector # 896 */
(uint32_t) &dummy, /* Vector # 897 */
(uint32_t) &dummy, /* Vector # 898 */
(uint32_t) &dummy, /* Vector # 899 */
(uint32_t) &dummy, /* Vector # 900 BCTU_0_TRIG BCTU_0_TRIG */

(uint32_t) &dummy, /* Vector # 901 BCTU_0_ADC0 BCTU_0_ADC0 */
(uint32_t) &dummy, /* Vector # 902 BCTU_0_ADC1 BCTU_0_ADC1 */
(uint32_t) &dummy, /* Vector # 903 BCTU_0_ADC2 BCTU_0_ADC2 */
(uint32_t) &dummy, /* Vector # 904 BCTU_0_ADC3 BCTU_0_ADC3 */
(uint32_t) &dummy, /* Vector # 905 BCTU_0_LIST BCTU_0_LIST */
(uint32_t) &dummy, /* Vector # 906 */
(uint32_t) &dummy, /* Vector # 907 */
(uint32_t) &dummy, /* Vector # 908 */
(uint32_t) &dummy, /* Vector # 909 */
(uint32_t) &dummy, /* Vector # 910 */
(uint32_t) &dummy, /* Vector # 911 */
(uint32_t) &dummy, /* Vector # 912 */
(uint32_t) &dummy, /* Vector # 913 */
(uint32_t) &dummy, /* Vector # 914 */
(uint32_t) &dummy, /* Vector # 915 REACM_G ipi_int_reacm */
(uint32_t) &dummy, /* Vector # 916 REACM_0 ipi_int_reacm_ch0 */
(uint32_t) &dummy, /* Vector # 917 REACM_1 ipi_int_reacm_ch1 */
(uint32_t) &dummy, /* Vector # 918 REACM_2 ipi_int_reacm_ch2 */
(uint32_t) &dummy, /* Vector # 919 REACM_3 ipi_int_reacm_ch3 */
(uint32_t) &dummy, /* Vector # 920 REACM_4 ipi_int_reacm_ch4 */
(uint32_t) &dummy, /* Vector # 921 REACM_5 ipi_int_reacm_ch5 */
(uint32_t) &dummy, /* Vector # 922 REACM_6 ipi_int_reacm_ch6 */
(uint32_t) &dummy, /* Vector # 923 REACM_7 ipi_int_reacm_ch7 */
(uint32_t) &dummy, /* Vector # 924 REACM_8 ipi_int_reacm_ch8 */
(uint32_t) &dummy, /* Vector # 925 REACM_9 ipi_int_reacm_ch9 */
(uint32_t) &dummy, /* Vector # 926 */
(uint32_t) &dummy, /* Vector # 927 */
(uint32_t) &dummy, /* Vector # 928 */
(uint32_t) &dummy, /* Vector # 929 */
(uint32_t) &dummy, /* Vector # 930 */
(uint32_t) &dummy, /* Vector # 931 */
(uint32_t) &dummy, /* Vector # 932 DECFIL_0_In ipi_int_dec_filter_0_in */
(uint32_t) &dummy, /* Vector # 933 DECFIL_0_Out ipi_int_dec_filter_0_out */
(uint32_t) &dummy, /* Vector # 934 DECFIL_0_Err ipi_int_dec_filter_0_err */
(uint32_t) &dummy, /* Vector # 935 DECFIL_1_In ipi_int_dec_filter_1_in */
(uint32_t) &dummy, /* Vector # 936 DECFIL_1_Out ipi_int_dec_filter_1_out */
(uint32_t) &dummy, /* Vector # 937 DECFIL_1_Err ipi_int_dec_filter_1_err */

};


void dummy (void) {   /* Dummy ISR vector to trap undefined ISRs */
    while (1) {};  /* Wait forever or for watchdog timeout */
}


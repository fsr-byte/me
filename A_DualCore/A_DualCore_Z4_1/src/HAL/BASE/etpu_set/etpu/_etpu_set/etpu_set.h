
/***************************************************************** 
* WARNING: This file is automatically generated. DO NOT EDIT IT!
*
* COPYRIGHT (c) Freescale 2004-2014, All Rights Reserved
*
* FILE NAME: etpu_set.h
* ARCHITECTURE: eTPU2
*
* This file was generated by: etpuc_set.c on Sep  5 2017 , 15:23:31
*
*****************************************************************/
#ifndef _ETPU_SET_H_
#define _ETPU_SET_H_

/***************************************************************** 
* Function Set Definitions
*****************************************************************/
#define FS_ETPU_ENTRY_TABLE 0x0000
#define FS_ETPU_MISC 0x922a01a7
#define FS_ETPU_ENGINE_MEM_SIZE 0x18
#define FS_ETPU_ARCHITECTURE ETPU2

/***************************************************************** 
* Global Error Definitions
*****************************************************************/
#define FS_ETPU_GLOBAL_ERROR_CHANNEL_MASK 0x00FFU
#define FS_ETPU_GLOBAL_ERROR_EVENT_MASK 0xFF00U
#define FS_ETPU_GLOBAL_ERROR_EVENT_LSR 0x0100U
#define FS_ETPU_GLOBAL_ERROR_EVENT_MRLA 0x0200U
#define FS_ETPU_GLOBAL_ERROR_EVENT_MRLB 0x0400U
#define FS_ETPU_GLOBAL_ERROR_EVENT_TDLA 0x0800U
#define FS_ETPU_GLOBAL_ERROR_EVENT_TDLB 0x1000U
#define FS_ETPU_GLOBAL_ERROR_EVENT_PSS 0x2000U
#define FS_ETPU_GLOBAL_ERROR_EVENT_FLAG0 0x4000U
#define FS_ETPU_GLOBAL_ERROR_EVENT_FLAG1 0x8000U

#define FS_ETPU_OFFSET_GLOBAL_ERROR 0x21

/***************************************************************** 
* Initialization values of global variables
* On eTPU(2) initialization, this array must be copied
* into the eTPU DATA RAM from its start address.
*****************************************************************/
const uint32_t etpu_globals[] = {
0x00000000,0x00000000,0x00000000,0x00000000,
0x00000000,0x00000000,0x00000000,0x00000000,
0x000000ff
};

/***************************************************************** 
* Image of the compiled eTPU code binary
* On eTPU(2) initialization, this array must be copied
* into the eTPU CODE RAM.
*****************************************************************/
const uint32_t etpu_code[] = {

0x404a404f, 0x404a404f, 0x405b0039, 0x407d407d, 
0x407d406f, 0x407d4063, 0x407d406f, 0x407d4063, 
0x4079407d, 0x4079407d, 0x4079407d, 0x4079407d, 
0x4079406f, 0x40794063, 0x4079406f, 0x40794063, 
0x40884088, 0x40884088, 0x40a3007e, 0x40a340a3, 
0x409240a3, 0x409240a3, 0x409240a3, 0x409240a3, 
0x408f408c, 0x408f408c, 0x408f408c, 0x408f408c, 
0x4092408c, 0x4092408c, 0x4092408c, 0x4092408c, 
0xf3300467, 0x00090409, 0x0c090fa2, 0xf29004a7, 
0x0c090fc2, 0xf2d004e7, 0x0c190f82, 0xf2100527, 
0x0c290f82, 0xf2500567, 0x0c490f82, 0xf41005a7, 
0x0c890f82, 0xe39005e7, 0x0d090f82, 0xe3d00627, 
0x0e090f82, 0x9ff97b08, 0xffffbcf9, 0x47eff6bf, 
0x00021411, 0x00071411, 0x00011411, 0xffffccf9, 
0x00001411, 0x0c02aba2, 0x580337e5, 0xcff9f980, 
0xf3b80807, 0x000d2439, 0x4ff00fff, 0x000c2439, 
0x7f7e3f5f, 0xbff37b85, 0xf3f008e7, 0xff3f0cfb, 
0x4f58fdff, 0xf7f00ce7, 0x0ffffffe, 0x4f38fbff, 
0xf7f00e67, 0x0fffff7e, 0xbfeffb84, 0xbf1b7b85, 
0xbfefff80, 0xf7f00a47, 0x7c783fdf, 0xbfeffb84, 
0xbf1b7b85, 0x7ff83fdf, 0xbfeffb81, 0x0008f019, 
0xf0d00b07, 0xf3d00ae7, 0x42ffffff, 0x41ffffff, 
0xf3d00b47, 0x41ffffff, 0x42ffffff, 0xbfefff84, 
0xf5200beb, 0xbf1b7b85, 0x7ff83fdf, 0xbfeffb82, 
0xbffffb80, 0xf7e00a4b, 0xbffffb81, 0xfff83cf9, 
0x0ff2abda, 0x1f1e2fff, 0xcfff7980, 0x000bf019, 
0xf0d00d67, 0xf7f00d87, 0x4affffff, 0x49ffffff, 
0xbffe7b84, 0x7f787e7f, 0xaffffb85, 0xfff83cf9, 
0x0ff2abda, 0x1f1e2fff, 0xcfff7980, 0x000bf019, 
0xf0d00ee7, 0xf7f00d87, 0x49ffffff, 0xf7f00d87, 
0x4affffff, 0xdfe9da85, 0x0c02aba2, 0x7ff83fdf, 
0xc7fff980, 0x47eff6bf, 0x0802fbaa, 0x4819ffff, 
0xf0f01067, 0x4ff0ffff, 0x4ff3ffff, 0xf3b810c7, 
0x591fffff, 0x5affffff, 0x4feff6b9, 0xf339fcfb, 
0x000c2419, 0x0802fbaa, 0xff3ffcfb, 0x1c0d2602, 
0xbffe7b06, 0x7f782e7f, 0xd7f0fa83, 0xbffe7b84, 
0xdfe7fa86, 0xadf87b86, 0xbfefff84, 0xbfeb0b83, 
0xbc197b85, 0xbfeffb86, 0xbfefff85, 0x4fffffff, 
0xbffffb80, 0xbfffff82, 0xffff3cf9, 0x0005f009, 
0xf3f813e7, 0xffff7cf9, 0xf77ffcfb, 0xbff97b83, 
0xbffffb06, 0xbfeffb81, 0x6f1e2e7f, 0x47eff6bf 


};

/***************************************************************** 
* List of eTPU functions included in this set
******************************************************************
"PWM",
"FPM",
"",
"",
"",
"",
"",
"",
"",
"",
"",
"",
"",
"",
"",
"",
"",
"",
"",
"",
"",
"",
"",
"",
"",
"",
"",
"",
"",
"",
"",
"",
"",
"",
"",
"",
"",
"",
"",
"",
"",
"",
"",
"",
"",
"",
"",
"",
"",
"",
"",
"",
"",
"",
"",
"",
"",
"",
"",
"",
"",
"",
"",
""
*/

#endif /* _ETPU_SET_H_ */


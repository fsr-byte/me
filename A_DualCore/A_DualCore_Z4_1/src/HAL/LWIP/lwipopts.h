/*
 * Copyright (c) 2001-2003 Swedish Institute of Computer Science.
 * All rights reserved. 
 * 
 * Redistribution and use in source and binary forms, with or without modification, 
 * are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 3. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission. 
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR IMPLIED 
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF 
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT 
 * SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, 
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT 
 * OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS 
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN 
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING 
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY 
 * OF SUCH DAMAGE.
 *
 * This file is part of the lwIP TCP/IP stack.
 * 
 * Author: Simon Goldschmidt
 *
 */
#ifndef LWIP_HDR_LWIPOPTS_H
#define LWIP_HDR_LWIPOPTS_H

#if 0

/* Prevent having to link sys_arch.c (we don't test the API layers in unit tests) */
#define NO_SYS                          1
#define SYS_LIGHTWEIGHT_PROT            0
#define LWIP_NETCONN                    0
#define LWIP_SOCKET                     0

/* Enable DHCP to test it, disable UDP checksum to easier inject packets */
#define LWIP_DHCP                       1

/* Minimal changes to opt.h required for tcp unit tests: */
#define MEM_SIZE                        16000
#define TCP_SND_QUEUELEN                40
#define MEMP_NUM_TCP_SEG                TCP_SND_QUEUELEN
#define TCP_SND_BUF                     (12 * TCP_MSS)
#define TCP_WND                         (10 * TCP_MSS)
#define LWIP_WND_SCALE                  1
#define TCP_RCV_SCALE                   0
#define PBUF_POOL_SIZE                  400 /* pbuf tests need ~200KByte */

/* Enable IGMP and MDNS for MDNS tests */
#define LWIP_IGMP                       1
#define LWIP_MDNS_RESPONDER             1
#define LWIP_NUM_NETIF_CLIENT_DATA      (LWIP_MDNS_RESPONDER)

/* Minimal changes to opt.h required for etharp unit tests: */
#define ETHARP_SUPPORT_STATIC_ENTRIES   1
#endif

 
 /**
 * SYS_LIGHTWEIGHT_PROT==1: if you want inter-task protection for certain
 * critical regions during buffer allocation, deallocation and memory
 * allocation and deallocation.
 */
 #define SYS_LIGHTWEIGHT_PROT    0     //* SYS_LIGHTWEIGHT_PROT==1:如果你想要确定的跨任务保护 *在缓冲区分配，回收和内存的关键区域 *分配和回收。
 
 /**
 * NO_SYS==1: Provides VERY minimal functionality. Otherwise,
 * use lwIP facilities.
 */
 #define NO_SYS                  1     //NO_SYS表示无操作系统模拟层，这个宏非常重要， 因为无操作系统与有操作系统的移植和编写是完全不一样的， 
                                        //我们现在是无操作系统移植，所以将这个宏定义为1。 

 #define LWIP_RAW     1
 
 /**
 * NO_SYS_NO_TIMERS==1: Drop support for sys_timeout when NO_SYS==1
 * Mainly for compatibility to old versions.
 */
 #define NO_SYS_NO_TIMERS        0    // NO_SYS_NO_TIMERS==1:当NO_SYS==1时，取消对sys_timeout的支持 *主要是为了兼容旧版本。
 
 /* ---------- Memory options ---------- */
 /* MEM_ALIGNMENT: should be set to the alignment of the CPU for which
     lwIP is compiled. 4 byte alignment -> define MEM_ALIGNMENT to 4, 2
     byte alignment -> define MEM_ALIGNMENT to 2. */
 #define MEM_ALIGNMENT           4    //使用4字节对齐模式                
 
 /* MEM_SIZE: the size of the heap memory. If the application will send
 a lot of data that needs to be copied, this should be set high. */
 #define MEM_SIZE                (10*512)        //堆内存的大小。如果应用程序将发送很多需要复制的数据应该设置得大一点。     
 
 /* MEMP_NUM_PBUF: the number of memp struct pbufs. If the application
     sends a lot of data out of ROM (or other static memory), this
     should be set high. */
 #define MEMP_NUM_PBUF           50    // MEMP_NUM_PBUF: memp结构pbuf的数量。如果应用程序从ROM(或其他静态内存)发送大量数据，这应该设得高一些。
 /* MEMP_NUM_UDP_PCB: the number of UDP protocol control blocks. One
     per active UDP "connection". */
 #define MEMP_NUM_UDP_PCB        6    //MEMP_NUM_UDP_PCB: UDP协议控制块的数量。一个每个活跃的UDP“连接”。
 /* MEMP_NUM_TCP_PCB: the number of simulatenously active TCP
     connections. */
 #define MEMP_NUM_TCP_PCB        10   //TCP协议控制块的数量。一个每个活跃的tcp“连接”。
 /* MEMP_NUM_TCP_PCB_LISTEN: the number of listening TCP
     connections. */
 #define MEMP_NUM_TCP_PCB_LISTEN 6   //正在监听的TCP数量连接。
 /* MEMP_NUM_TCP_SEG: the number of simultaneously queued TCP
     segments. */
 #define MEMP_NUM_TCP_SEG        12   //同时排队的TCP段数。
 /* MEMP_NUM_SYS_TIMEOUT: the number of simulateously active
     timeouts. */
 #define MEMP_NUM_SYS_TIMEOUT    10   //同时活动的超时次数。
 
 /* ---------- Pbuf options ---------- */
 /* PBUF_POOL_SIZE: the number of buffers in the pbuf pool. */
 #define PBUF_POOL_SIZE          10      //PBUF_POOL内存池中内存块数量。            
 
 /* PBUF_POOL_BUFSIZE: the size of each pbuf in the pbuf pool. */
 #define PBUF_POOL_BUFSIZE       500     //PBUF_POOL内存池中每个内存块大小。            
 
 /* ---------- TCP options ---------- */
 #define LWIP_TCP                1    //开启TCP
 #define TCP_TTL                 255  //TCP生存时间
 
 /* Controls if TCP should queue segments that arrive out of
     order. Define to 0 if your device is low on memory. */
 #define TCP_QUEUE_OOSEQ         0   //控制TCP是否应该对到达的段进行排队秩序。如果设备内存不足，则定义为0。
 
 /* TCP Maximum segment size. */
 #define TCP_MSS                 (1500 - 40)    //TCP协议报文最大长度。             
 
 /* TCP sender buffer space (bytes). */
 #define TCP_SND_BUF             (4*TCP_MSS)    //允许TCP协议使用的最大发送缓冲区空间（字节）。     
 
 /*  TCP_SND_QUEUELEN: TCP sender buffer space (pbufs). This must be at least
 as much as (2 * TCP_SND_BUF/TCP_MSS) for things to work. */
 
 #define TCP_SND_QUEUELEN        (2* TCP_SND_BUF/TCP_MSS)  //TCP发送端缓冲区空间(pbufs)。这一定是至少最多为(2 * TCP_SND_BUF/TCP_MSS)。
 
 /* TCP receive window. */
 #define TCP_WND                 (2*TCP_MSS)   //TCP接收窗口大小。      
 
 /* ---------- ICMP options ---------- */
 #define LWIP_ICMP                       1
 
 /* ---------- DHCP options ---------- */
 /* Define LWIP_DHCP to 1 if you want DHCP configuration of
 interfaces. DHCP is not implemented in lwIP 0.5.1, however, so
 turning this on does currently not work. */
 #define LWIP_DHCP               0
 
 /* ---------- UDP options ---------- */
 #define LWIP_UDP                1
 #define UDP_TTL                 255
 
 /* ---------- Statistics options ---------- */  //统计功能
 #define LWIP_STATS 0  
 #define LWIP_PROVIDE_ERRNO 1
 
 /* ---------- link callback options ---------- */
 /* LWIP_NETIF_LINK_CALLBACK==1: Support a callback function from an interface
 * whenever the link changes (i.e., link down)
 */
 #define LWIP_NETIF_LINK_CALLBACK        0  //支持来自接口的回调函数当链接改变时(即链接向下)
 /*
     --------------------------------------
     ---------- Checksum options ----------
     --------------------------------------
 */
 
 /*The STM32F4x7 allows comput
 ing and verifying the IP, UDP, TCP and ICMP checksums by hardware:
 - To use this feature let the following define uncommented.
 - To disable it and process by CPU comment the  the checksum. 
 */
// #define CHECKSUM_BY_HARDWARE
 
 #ifdef CHECKSUM_BY_HARDWARE  //硬件效验
 /* CHECKSUM_GEN_IP==0: Generate checksums by hardware for outgoing IP packets.*/
 #define CHECKSUM_GEN_IP                 0
 /* CHECKSUM_GEN_UDP==0: Generate checksums by hardware for outgoing UDP packets.*/
 #define CHECKSUM_GEN_UDP                0
 /* CHECKSUM_GEN_TCP==0: Generate checksums by hardware for outgoing TCP packets.*/
 #define CHECKSUM_GEN_TCP                0
 /* CHECKSUM_CHECK_IP==0: Check checksums by hardware for incoming IP packets.*/
 #define CHECKSUM_CHECK_IP               0
 /* CHECKSUM_CHECK_UDP==0: Check checksums by hardware for incoming UDP packets.*/
 #define CHECKSUM_CHECK_UDP              0
 /* CHECKSUM_CHECK_TCP==0: Check checksums by hardware for incoming TCP packets.*/
 #define CHECKSUM_CHECK_TCP              0
 /*CHECKSUM_CHECK_ICMP==0: Check checksums by hardware for incoming ICMP packets.*/
 #define CHECKSUM_GEN_ICMP               0
 #else                      //软件效验
 /* CHECKSUM_GEN_IP==1: Generate checksums in software for outgoing IP packets.*/
 #define CHECKSUM_GEN_IP                 1
 /* CHECKSUM_GEN_UDP==1: Generate checksums in software for outgoing UDP packets.*/
 #define CHECKSUM_GEN_UDP                1
 /* CHECKSUM_GEN_TCP==1: Generate checksums in software for outgoing TCP packets.*/
 #define CHECKSUM_GEN_TCP                1
 /* CHECKSUM_CHECK_IP==1: Check checksums in software for incoming IP packets.*/
 #define CHECKSUM_CHECK_IP               1
 /* CHECKSUM_CHECK_UDP==1: Check checksums in software for incoming UDP packets.*/
 #define CHECKSUM_CHECK_UDP              1
 /* CHECKSUM_CHECK_TCP==1: Check checksums in software for incoming TCP packets.*/
 #define CHECKSUM_CHECK_TCP              1
 /*CHECKSUM_CHECK_ICMP==1: Check checksums by hardware for incoming ICMP packets.*/
 #define CHECKSUM_GEN_ICMP               1
 #endif
 
 /*
     ----------------------------------------------
     ---------- Sequential layer options ----------
     ----------------------------------------------
 */
 /**
 * LWIP_NETCONN==1: Enable Netconn API (require to use api_lib.c)
 */
 #define LWIP_NETCONN                    0            //开启/关闭netconn功能
 
 /*
     ------------------------------------
     ---------- Socket options ----------
     ------------------------------------
 */
 /**
 * LWIP_SOCKET==1: Enable Socket API (require to use sockets.c)
 */
 #define LWIP_SOCKET                     0            //开启/关闭socket功能
 
 /*
     ----------------------------------------
     ---------- Lwip Debug options ----------
     ----------------------------------------
 */
 //#define LWIP_DEBUG                      1



#endif /* LWIP_HDR_LWIPOPTS_H */

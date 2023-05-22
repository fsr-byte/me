/**
 * @file
 * Ethernet Interface Skeleton
 *
 */

/*
 * Copyright (c) 2001-2004 Swedish Institute of Computer Science.
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
 * Author: Adam Dunkels <adam@sics.se>
 *
 */

/*
 * This file is a skeleton for developing Ethernet network interface
 * drivers for lwIP. Add code to the low_level functions and do a
 * search-and-replace for the word "ethernetif" to replace it with
 * something that better describes your network interface.
 */

#include "lwip/opt.h"
#include <string.h>
#include "lwip/mem.h"
#include "lwip/pbuf.h"
#include "lwip/stats.h"
#include "lwip/snmp.h"
#include "lwip/ethip6.h"
#include "lwip/etharp.h"
#include "lwip/tcpip.h"

//#include "lwipcfg.h"
#include "lwip/sys.h"

#include "ethernetif.h"
#include "enet_driver.h"



#define IFNAME0 'e'
#define IFNAME1 'n'

/* Code returned by the pre-input handler in the case when the frame should be forwarded to the stack */
#define FORWARD_FRAME   (0U)

#define ALIGNED(x)      __attribute__((aligned(x)))
/*! @brief Definitions used for aligning the data buffers */
#define FEATURE_ENET_BUFF_ALIGNMENT      (16UL)
/*! @brief Definitions used for aligning the buffer descriptors */
#define FEATURE_ENET_BUFFDESCR_ALIGNMENT (64UL)
#define FEC_INSTANCE_COUNT   (1u)

#ifndef ENET_INSTANCE_COUNT
#define ENET_INSTANCE_COUNT	FEC_INSTANCE_COUNT
#endif
/*! @brief MAC address of the module */
#ifndef LWIP_MAC_ADDR_BASE
#define LWIP_MAC_ADDR_BASE            0x22,0xE3,0xF4,0x55,0x66,0x77
#endif /* ifndef LWIP_MAC_ADDR_BASE */


#define NETIF_CHECKSUM_SETTING        NETIF_CHECKSUM_ENABLE_ALL
#define LWIP_NETIF_HOSTNAME_TEXT      ("tcpipBoard1")

enet_state_t enetState;


#if  1
/* Custom data section for enet buffers */
#ifndef FEATURE_CUSTOM_DATA_SECTION
#define FEATURE_CUSTOM_DATA_SECTION ".data"
#endif


ALIGNED(FEATURE_ENET_BUFFDESCR_ALIGNMENT)
enet_buffer_descriptor_t txDescriptor[ENET_TXBD_NUM] __attribute__((section(FEATURE_CUSTOM_DATA_SECTION)));
ALIGNED(FEATURE_ENET_BUFFDESCR_ALIGNMENT)
enet_buffer_descriptor_t rxDescriptor[ENET_RXBD_NUM] __attribute__((section(FEATURE_CUSTOM_DATA_SECTION)));
ALIGNED(FEATURE_ENET_BUFF_ALIGNMENT)
uint8_t rxBuffer[ENET_RXBD_NUM * ENET_RXBUFF_SIZE] __attribute__((section(FEATURE_CUSTOM_DATA_SECTION)));
#endif

//__attribute__((aligned (16)))  enet_buffer_descriptor_t txDescriptor[ENET_TXBD_NUM];
//__attribute__((aligned (16)))  enet_buffer_descriptor_t rxDescriptor[ENET_RXBD_NUM];
//__attribute__((aligned (16)))  uint8_t rxBuffer[ENET_RXBD_NUM * ENET_RXBUFF_SIZE];


struct netif * g_netif[ENET_INSTANCE_COUNT];
//typedef uint8_t mutex_t;


/* Lock to synchronize access on TX side, since the frames are sent from different threads */
//mutex_t enetif_tx_lock;


/* This handler is called before a frame is dispatched from the ENET driver to the TCPIP stack.
   If extra processing is needed before the dispatch is done, one must implement this handler and
   register it via enetif_register_rx_buff_process_condition_handler.
*/
static rx_buff_process_condition_handler_t rx_buff_process_handler = NULL;


#if 0 /* don't build, this is only a skeleton, see previous comment */

#include "lwip/def.h"
#include "lwip/mem.h"
#include "lwip/pbuf.h"
#include "lwip/stats.h"
#include "lwip/snmp.h"
#include "lwip/ethip6.h"
#include "lwip/etharp.h"
#include "netif/ppp/pppoe.h"

/* Define those to better describe your network interface. */
#define IFNAME0 'e'
#define IFNAME1 'n'

/**
 * Helper struct to hold private data used to operate your ethernet interface.
 * Keeping the ethernet address of the MAC in this struct is not necessary
 * as it is already kept in the struct netif.
 * But this is only an example, anyway...
 */
struct ethernetif {
  struct eth_addr *ethaddr;
  /* Add whatever per-interface state that is needed here. */
};

/* Forward declarations. */
static void  ethernetif_input(struct netif *netif);

/**
 * In this function, the hardware should be initialized.
 * Called from ethernetif_init().
 *
 * @param netif the already initialized lwip network interface structure
 *        for this ethernetif
 */
static void
low_level_init(struct netif *netif)
{
  struct ethernetif *ethernetif = netif->state;

  /* set MAC hardware address length */
  netif->hwaddr_len = ETHARP_HWADDR_LEN;

  /* set MAC hardware address */
  netif->hwaddr[0] = ;
  ...
  netif->hwaddr[5] = ;

  /* maximum transfer unit */
  netif->mtu = 1500;

  /* device capabilities */
  /* don't set NETIF_FLAG_ETHARP if this device is not an ethernet one */
  netif->flags = NETIF_FLAG_BROADCAST | NETIF_FLAG_ETHARP | NETIF_FLAG_LINK_UP;

#if LWIP_IPV6 && LWIP_IPV6_MLD
  /*
   * For hardware/netifs that implement MAC filtering.
   * All-nodes link-local is handled by default, so we must let the hardware know
   * to allow multicast packets in.
   * Should set mld_mac_filter previously. */
  if (netif->mld_mac_filter != NULL) {
    ip6_addr_t ip6_allnodes_ll;
    ip6_addr_set_allnodes_linklocal(&ip6_allnodes_ll);
    netif->mld_mac_filter(netif, &ip6_allnodes_ll, NETIF_ADD_MAC_FILTER);
  }
#endif /* LWIP_IPV6 && LWIP_IPV6_MLD */

  /* Do whatever else is needed to initialize interface. */
}

/**
 * This function should do the actual transmission of the packet. The packet is
 * contained in the pbuf that is passed to the function. This pbuf
 * might be chained.
 *
 * @param netif the lwip network interface structure for this ethernetif
 * @param p the MAC packet to send (e.g. IP packet including MAC addresses and type)
 * @return ERR_OK if the packet could be sent
 *         an err_t value if the packet couldn't be sent
 *
 * @note Returning ERR_MEM here if a DMA queue of your MAC is full can lead to
 *       strange results. You might consider waiting for space in the DMA queue
 *       to become available since the stack doesn't retry to send a packet
 *       dropped because of memory failure (except for the TCP timers).
 */

static err_t
low_level_output(struct netif *netif, struct pbuf *p)
{
  struct ethernetif *ethernetif = netif->state;
  struct pbuf *q;

  initiate transfer();

#if ETH_PAD_SIZE
  pbuf_header(p, -ETH_PAD_SIZE); /* drop the padding word */
#endif

  for (q = p; q != NULL; q = q->next) {
    /* Send the data from the pbuf to the interface, one pbuf at a
       time. The size of the data in each pbuf is kept in the ->len
       variable. */
    send data from(q->payload, q->len);
  }

  signal that packet should be sent();

  MIB2_STATS_NETIF_ADD(netif, ifoutoctets, p->tot_len);
  if (((u8_t*)p->payload)[0] & 1) {
    /* broadcast or multicast packet*/
    MIB2_STATS_NETIF_INC(netif, ifoutnucastpkts);
  } else {
    /* unicast packet */
    MIB2_STATS_NETIF_INC(netif, ifoutucastpkts);
  }
  /* increase ifoutdiscards or ifouterrors on error */

#if ETH_PAD_SIZE
  pbuf_header(p, ETH_PAD_SIZE); /* reclaim the padding word */
#endif

  LINK_STATS_INC(link.xmit);

  return ERR_OK;
}

/**
 * Should allocate a pbuf and transfer the bytes of the incoming
 * packet from the interface into the pbuf.
 *
 * @param netif the lwip network interface structure for this ethernetif
 * @return a pbuf filled with the received packet (including MAC header)
 *         NULL on memory error
 */
static struct pbuf *
low_level_input(struct netif *netif)
{
  struct ethernetif *ethernetif = netif->state;
  struct pbuf *p, *q;
  u16_t len;

  /* Obtain the size of the packet and put it into the "len"
     variable. */
  len = ;

#if ETH_PAD_SIZE
  len += ETH_PAD_SIZE; /* allow room for Ethernet padding */
#endif

  /* We allocate a pbuf chain of pbufs from the pool. */
  p = pbuf_alloc(PBUF_RAW, len, PBUF_POOL);

  if (p != NULL) {

#if ETH_PAD_SIZE
    pbuf_header(p, -ETH_PAD_SIZE); /* drop the padding word */
#endif

    /* We iterate over the pbuf chain until we have read the entire
     * packet into the pbuf. */
    for (q = p; q != NULL; q = q->next) {
      /* Read enough bytes to fill this pbuf in the chain. The
       * available data in the pbuf is given by the q->len
       * variable.
       * This does not necessarily have to be a memcpy, you can also preallocate
       * pbufs for a DMA-enabled MAC and after receiving truncate it to the
       * actually received size. In this case, ensure the tot_len member of the
       * pbuf is the sum of the chained pbuf len members.
       */
      read data into(q->payload, q->len);
    }
    acknowledge that packet has been read();

    MIB2_STATS_NETIF_ADD(netif, ifinoctets, p->tot_len);
    if (((u8_t*)p->payload)[0] & 1) {
      /* broadcast or multicast packet*/
      MIB2_STATS_NETIF_INC(netif, ifinnucastpkts);
    } else {
      /* unicast packet*/
      MIB2_STATS_NETIF_INC(netif, ifinucastpkts);
    }
#if ETH_PAD_SIZE
    pbuf_header(p, ETH_PAD_SIZE); /* reclaim the padding word */
#endif

    LINK_STATS_INC(link.recv);
  } else {
    drop packet();
    LINK_STATS_INC(link.memerr);
    LINK_STATS_INC(link.drop);
    MIB2_STATS_NETIF_INC(netif, ifindiscards);
  }

  return p;
}

/**
 * This function should be called when a packet is ready to be read
 * from the interface. It uses the function low_level_input() that
 * should handle the actual reception of bytes from the network
 * interface. Then the type of the received packet is determined and
 * the appropriate input function is called.
 *
 * @param netif the lwip network interface structure for this ethernetif
 */
static void
ethernetif_input(struct netif *netif)
{
  struct ethernetif *ethernetif;
  struct eth_hdr *ethhdr;
  struct pbuf *p;

  ethernetif = netif->state;

  /* move received packet into a new pbuf */
  p = low_level_input(netif);
  /* if no packet could be read, silently ignore this */
  if (p != NULL) {
    /* pass all packets to ethernet_input, which decides what packets it supports */
    if (netif->input(p, netif) != ERR_OK) {
      LWIP_DEBUGF(NETIF_DEBUG, ("ethernetif_input: IP input error\n"));
      pbuf_free(p);
      p = NULL;
    }
  }
}

/**
 * Should be called at the beginning of the program to set up the
 * network interface. It calls the function low_level_init() to do the
 * actual setup of the hardware.
 *
 * This function should be passed as a parameter to netif_add().
 *
 * @param netif the lwip network interface structure for this ethernetif
 * @return ERR_OK if the loopif is initialized
 *         ERR_MEM if private data couldn't be allocated
 *         any other err_t on error
 */
err_t
ethernetif_init(struct netif *netif)
{
  struct ethernetif *ethernetif;

  LWIP_ASSERT("netif != NULL", (netif != NULL));

  ethernetif = mem_malloc(sizeof(struct ethernetif));
  if (ethernetif == NULL) {
    LWIP_DEBUGF(NETIF_DEBUG, ("ethernetif_init: out of memory\n"));
    return ERR_MEM;
  }

#if LWIP_NETIF_HOSTNAME
  /* Initialize interface hostname */
  netif->hostname = "lwip";
#endif /* LWIP_NETIF_HOSTNAME */

  /*
   * Initialize the snmp variables and counters inside the struct netif.
   * The last argument should be replaced with your link speed, in units
   * of bits per second.
   */
  MIB2_INIT_NETIF(netif, snmp_ifType_ethernet_csmacd, LINK_SPEED_OF_YOUR_NETIF_IN_BPS);

  netif->state = ethernetif;
  netif->name[0] = IFNAME0;
  netif->name[1] = IFNAME1;
  /* We directly use etharp_output() here to save a function call.
   * You can instead declare your own function an call etharp_output()
   * from it if you have to do some checks before sending (e.g. if link
   * is available...) */
  netif->output = etharp_output;
#if LWIP_IPV6
  netif->output_ip6 = ethip6_output;
#endif /* LWIP_IPV6 */
  netif->linkoutput = low_level_output;

  ethernetif->ethaddr = (struct eth_addr *)&(netif->hwaddr[0]);

  /* initialize the hardware */
  low_level_init(netif);

  return ERR_OK;
}

#endif /* 0 */


/**
 * Transmit a packet.
 * The packet is contained in the pbuf that is passed to the function. This pbuf might be chained.
 *
 * @param netif - the lwip network interface structure for this ethernetif
 * @param p - the pbuf structure
 * Implements enetif_low_level_output_Activity
 */
static err_t enetif_low_level_output(struct netif *netif, struct pbuf *p)
{
    struct pbuf *q;
    status_t status;

    LWIP_ASSERT("Output packet buffer empty", p);

    /* Increment our reference on p */
    pbuf_ref(p);
    q = pbuf_coalesce(p, PBUF_RAW);
    /* If p was a single pbuf, nothing special happened: q = p
       If p was a pbuf chain instead, p's ref was decreased and we got another q pbuf with ref 1
       Either way, q has a +1 ref that we need to free in case we're not keeping the buffer - ie in case of errors
    */
    enet_buffer_t bd;

    bd.data = q->payload;
    bd.length = q->tot_len;

    /* Keep trying to send the frame as long as the driver says there is not enough space in the queue */
    do
    {
        status = ENET_DRV_SendFrame(netif->num, ENET_QUEUE, &bd, NULL);
    }
    while (status == STATUS_ENET_TX_QUEUE_FULL);

    if (status == STATUS_SUCCESS)
    {
        /* Wait for the frame to be trnasmitted - TODO: improve this! */
        while (STATUS_BUSY == ENET_DRV_GetTransmitStatus(netif->num, ENET_QUEUE, &bd, NULL)) {}
    }
    /* Decrement the ref (either p's ref in case it was a single pbuf, or the coalesed q's ref) */
    (void)pbuf_free(q);

    return ERR_OK;
}

/**
 * This function is called when a packet is ready to be read from the interface.
 *
 * @param netif - the lwip network interface structure for this ethernetif
 * @param data - the pointer to the received data buffer
 * @param size - the length of received data buffer
 * @return ERR_OK if the packet is being handled (we take ownership of the data buffer)
 *         ERR_MEM if the packet cannot be handled (we don't take ownership of the data buffer,
 *         therefore the caller should release it)
 * Implements enetif_input_Activity
 */
static err_t enetif_input(struct netif *netif, uint8_t * data, uint16_t size)
{
    err_t ret = ERR_MEM;

    /* Allocate a PBUF_REF pointing to the receive buffer */
    struct pbuf* p  = pbuf_alloc(PBUF_RAW, size, PBUF_REF);
    if (p != NULL)
    {
        ret = ERR_OK;
        p->payload = data;
        if (netif->input(p, netif) != ERR_OK)
        {
            LWIP_DEBUGF(NETIF_DEBUG, ("enetif_input: IP input error\n"));
            (void)pbuf_free(p);
        }
    }

    return ret;
}

/**
 * This function polls the driver for received frames
 * Implements enetif_poll_thread_Activity
 */
err_t enet_poll_interface(struct netif *netif)
{
    uint8_t instance = netif->num;
    enet_buffer_t bd;
    
    /* Check input parameter */
    LWIP_ASSERT("g_netif[instance] != NULL", g_netif[instance] != NULL);

    /* Check if there are any new RX frames and provide them to lwip stack */
    if (STATUS_SUCCESS == ENET_DRV_ReadFrame(instance, ENET_QUEUE, &bd, NULL))
    {
        if ((NULL == rx_buff_process_handler) || (FORWARD_FRAME != rx_buff_process_handler(instance, &bd)))
        {
            (void)enetif_input((struct netif *)g_netif[instance], (uint8_t*)bd.data, (uint16_t)bd.length);
            ENET_DRV_ProvideRxBuff(instance, ENET_QUEUE, &bd);       
        }
    }

    return ERR_OK;
}

/**
 * In this function, the hardware should be initialized.
 * Called from ethernetif_init().
 *
 * @param netif - the already initialized lwip network interface structure
 *        for this ethernetif
 * Implements enetif_low_level_init_Activity
 */
static void enetif_low_level_init(struct netif *netif)
{
    enet_config_t enetConfig;
    /* Use only one ring */
    enet_buffer_config_t enetBufferConfigs[ENET_QUEUE + 1];
    uint8_t macAddr[NETIF_MAX_HWADDR_LEN] = { LWIP_MAC_ADDR_BASE };
    uint8_t i;

    /* set MAC hardware address length */
    netif->hwaddr_len = NETIF_MAX_HWADDR_LEN;

    /* set MAC hardware address */
    for (i = 0; i < NETIF_MAX_HWADDR_LEN; i++)
    {
      netif->hwaddr[i] = macAddr[i];
    }

    /* maximum transfer unit */
    netif->mtu = 1500;

    netif->num = ENET_INSTANCE;

    /* device capabilities */
    /* don't set NETIF_FLAG_ETHARP if this device is not an ethernet one */
    netif->flags = (u8_t)(NETIF_FLAG_BROADCAST | NETIF_FLAG_ETHARP | NETIF_FLAG_ETHERNET);

    ENET_DRV_GetDefaultConfig(&enetConfig);

    enetConfig.miiMode = ENET_MIIMODE;
    enetConfig.miiSpeed = ENET_MIISPEED;

    enetConfig.ringCount = sizeof(enetBufferConfigs) / sizeof (enet_buffer_config_t);
    enetBufferConfigs[ENET_QUEUE].rxRingSize = ENET_RXBD_NUM;
    enetBufferConfigs[ENET_QUEUE].txRingSize = ENET_TXBD_NUM;
    enetBufferConfigs[ENET_QUEUE].rxRingAligned = rxDescriptor;
    enetBufferConfigs[ENET_QUEUE].txRingAligned = txDescriptor;
    enetBufferConfigs[ENET_QUEUE].rxBufferAligned = rxBuffer;

    NETIF_SET_CHECKSUM_CTRL(netif, NETIF_CHECKSUM_SETTING);

    g_netif[ENET_INSTANCE] = netif;
    ENET_DRV_Init(ENET_INSTANCE, &enetState, &enetConfig, enetBufferConfigs, netif->hwaddr);
    ENET_DRV_EnableMDIO(ENET_INSTANCE, 0);

    netif_set_link_up(netif);

}

/**
 * Should be called at the beginning of the program to set up the
 * network interface. It calls the function low_level_init() to do the
 * actual setup of the hardware.
 *
 * This function should be passed as a parameter to netif_add().
 *
 * @param netif - the lwip network interface structure for this ethernetif
 * @return ERR_OK if the loopif is initialized
 *         ERR_MEM if private data couldn't be allocated
 *         any other err_t on error
 * Implements enet_ethernetif_init_Activity
 */
err_t enet_ethernetif_init(struct netif *netif)
{
    LWIP_ASSERT("netif != NULL", (netif != NULL));

    netif->name[0] = IFNAME0;
    netif->name[1] = IFNAME1;

#if LWIP_IPV4
#if LWIP_ARP
    /* We directly use etharp_output() here to save a function call.
     * You can instead declare your own function an call etharp_output()
     * from it if you have to do some checks before sending (e.g. if link
     * is available...) */
    netif->output = etharp_output;
#else /* LWIP_ARP */
    netif->output = NULL; /* not used for PPPoE */
#endif /* LWIP_ARP */
#endif /* LWIP_IPV4 */
#if LWIP_IPV6
    netif->output_ip6 = ethip6_output;
#endif /* LWIP_IPV6 */
    netif->linkoutput = enetif_low_level_output;
#if LWIP_NETIF_HOSTNAME
    /* Initialize interface hostname */
    netif->hostname = LWIP_NETIF_HOSTNAME_TEXT;
#endif /* LWIP_NETIF_HOSTNAME */

#if LWIP_SNMP
    /*
    * Initialize the snmp variables and counters inside the struct netif.
    * The last argument should be replaced with your link speed, in units
    * of bits per second.
    */
    NETIF_INIT_SNMP(netif, (u8_t)snmp_ifType_ethernet_csmacd, (u32_t)100000000);
#endif /* LWIP_SNMP */

    /* initialize the hardware */
    enetif_low_level_init(netif);

    return ERR_OK;
}

/**
 * Clean up network interface and internal structures
 *
 * @param netif - the lwip network interface structure for this ethernetif
 * Implements enet_ethernetif_shutdown_Activity
 */
void enet_ethernetif_shutdown(struct netif *netif)
{
    ENET_DRV_Deinit(netif->num);
}


/**
 * Register pre-input handler
 * This handler is called before a frame is input to the TCPIP stack
 * If returns 0, the frame should be forwarded to the stack
 * If returns something else, the frame is used by other applications
 *
 * @param handler - the handler to be installed
 */
void enetif_register_rx_buff_process_condition_handler(rx_buff_process_condition_handler_t handler)
{
    rx_buff_process_handler = handler;
}











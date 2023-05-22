#ifndef _LWIP_TCP_H_
#define _LWIP_TCP_H_
#include "lwip/tcp.h"


extern err_t accept_callback(void *arg, struct tcp_pcb *newpcb, err_t err);
extern err_t recv_callback(void *arg, struct tcp_pcb *tpcb, struct pbuf *p, err_t err);
void TCP_init(uint16_t PORT);
void TCP_Send(const uint8_t * data,uint8_t len);
void TCP_main(void);
#endif // !_LWIP_TCP_H_
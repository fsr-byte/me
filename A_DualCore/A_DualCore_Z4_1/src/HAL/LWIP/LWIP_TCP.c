#include "LWIP_TCP.h"
struct tcp_pcb *pcb;
// 回调函数，用于处理新连接的回调
err_t accept_callback(void *arg, struct tcp_pcb *newpcb, err_t err)
{
    // 设置接收数据的回调函数
    tcp_recv(newpcb, recv_callback);

    return ERR_OK;
}

// 回调函数，用于接收数据的回调
err_t recv_callback(void *arg, struct tcp_pcb *tpcb, struct pbuf *p, err_t err)
{
    // 处理接收到的数据
    if (p != NULL) {
        // 处理pbuf中的数据
        // ...

        // 释放pbuf
        pbuf_free(p);
    } else {
        // 客户端已关闭连接，可以在这里进行一些清理操作

        // 关闭连接
        tcp_close(tpcb);
    }

    return ERR_OK;
}

void TCP_init(uint16_t PORT)
{
    
    err_t err;

    // 初始化LWIP库
    lwip_init();

    // 创建TCP协议控制块
    pcb = tcp_new();
    if (pcb == NULL) {
        // 创建失败
        return -1;
    }

    // 绑定本地IP地址和端口
    err = tcp_bind(pcb, IP_ADDR_ANY, PORT);
    if (err != ERR_OK) {
        // 绑定失败
        tcp_close(pcb);
        return -1;
    }

    // 监听端口，等待客户端连接
    pcb = tcp_listen(pcb);
    if (pcb == NULL) {
        // 监听失败
        return -1;
    }

    // 设置接收新连接的回调函数
    tcp_accept(pcb, accept_callback);
}

void TCP_Send(const uint8_t * data,uint8_t len)
{
    struct pbuf* p = pbuf_alloc(PBUF_TRANSPORT, len, PBUF_RAM);
    if (p != NULL) {
        // 将数据复制到发送缓冲区
        memcpy(p->payload, data, len);

        // 获取已连接的TCP控制块
        struct tcp_pcb* tpcb = pcb; // 获取已连接的TCP控制块

        // 发送数据
        err_t err = tcp_write(tpcb, p->payload, p->len, TCP_WRITE_FLAG_COPY);
        if (err == ERR_OK) 
        {
            // 数据发送成功
            tcp_output(tpcb); // 手动触发TCP发送数据
        }
         else 
        {
            // 发送失败，需要释放发送缓冲区
            pbuf_free(p);
        }
    }
}

void TCP_main()
{
    // 进入主循环，处理网络事件

    // 处理网络事件
    sys_check_timeouts();

    // 可以在这里添加其他的处理逻辑
    // ...
    return 0;
}

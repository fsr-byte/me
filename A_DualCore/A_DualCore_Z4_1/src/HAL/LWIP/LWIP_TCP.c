#include "LWIP_TCP.h"
struct tcp_pcb *pcb;
// �ص����������ڴ��������ӵĻص�
err_t accept_callback(void *arg, struct tcp_pcb *newpcb, err_t err)
{
    // ���ý������ݵĻص�����
    tcp_recv(newpcb, recv_callback);

    return ERR_OK;
}

// �ص����������ڽ������ݵĻص�
err_t recv_callback(void *arg, struct tcp_pcb *tpcb, struct pbuf *p, err_t err)
{
    // ������յ�������
    if (p != NULL) {
        // ����pbuf�е�����
        // ...

        // �ͷ�pbuf
        pbuf_free(p);
    } else {
        // �ͻ����ѹر����ӣ��������������һЩ�������

        // �ر�����
        tcp_close(tpcb);
    }

    return ERR_OK;
}

void TCP_init(uint16_t PORT)
{
    
    err_t err;

    // ��ʼ��LWIP��
    lwip_init();

    // ����TCPЭ����ƿ�
    pcb = tcp_new();
    if (pcb == NULL) {
        // ����ʧ��
        return -1;
    }

    // �󶨱���IP��ַ�Ͷ˿�
    err = tcp_bind(pcb, IP_ADDR_ANY, PORT);
    if (err != ERR_OK) {
        // ��ʧ��
        tcp_close(pcb);
        return -1;
    }

    // �����˿ڣ��ȴ��ͻ�������
    pcb = tcp_listen(pcb);
    if (pcb == NULL) {
        // ����ʧ��
        return -1;
    }

    // ���ý��������ӵĻص�����
    tcp_accept(pcb, accept_callback);
}

void TCP_Send(const uint8_t * data,uint8_t len)
{
    struct pbuf* p = pbuf_alloc(PBUF_TRANSPORT, len, PBUF_RAM);
    if (p != NULL) {
        // �����ݸ��Ƶ����ͻ�����
        memcpy(p->payload, data, len);

        // ��ȡ�����ӵ�TCP���ƿ�
        struct tcp_pcb* tpcb = pcb; // ��ȡ�����ӵ�TCP���ƿ�

        // ��������
        err_t err = tcp_write(tpcb, p->payload, p->len, TCP_WRITE_FLAG_COPY);
        if (err == ERR_OK) 
        {
            // ���ݷ��ͳɹ�
            tcp_output(tpcb); // �ֶ�����TCP��������
        }
         else 
        {
            // ����ʧ�ܣ���Ҫ�ͷŷ��ͻ�����
            pbuf_free(p);
        }
    }
}

void TCP_main()
{
    // ������ѭ�������������¼�

    // ���������¼�
    sys_check_timeouts();

    // ������������������Ĵ����߼�
    // ...
    return 0;
}

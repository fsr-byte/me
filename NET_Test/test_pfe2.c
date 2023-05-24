#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <linux/if_packet.h>
#include <net/if.h>
#include <netinet/if_ether.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>
#include <netinet/tcp.h>
#include <netinet/in.h>

#define BUFFER_SIZE 65536
#define IP_ADDR "192.168.0.234"
#define PORT 6321
#define MAX_BUFFER_SIZE 1024
#define MAX_DATA_SIZE 512
typedef struct{
  uint8_t destination_mac[6];
  uint8_t source_mac[6];
  uint16_t lenth;
  uint8_t Data[MAX_DATA_SIZE];
//   unsigned int fcs; // 帧校验序列
}ethernet_frame;

char recv_buf[MAX_BUFFER_SIZE];

// GAsyncQueue *queue; // Glib队列
ethernet_frame LLC_Protocol;
pthread_mutex_t LLC_Protocol_mutex = PTHREAD_MUTEX_INITIALIZER;  // 初始化互斥锁


void *thread_Lin_Layer(void *thread_id) {
    int sockfd, ret;
    uint8_t buffer[BUFFER_SIZE];
    struct sockaddr_ll addr;
    socklen_t addr_len = sizeof(addr);
    unsigned char allowed_mac[6] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06};

    // 创建 socket
    sockfd = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_ALL));
    if (sockfd < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }
    printf("sockfd ok!!\n");
    
    // 获取网络接口索引
    struct ifreq ifr;
    memset(&ifr, 0, sizeof(ifr));
    strncpy(ifr.ifr_name, "pfe0", IFNAMSIZ - 1);
    ret = ioctl(sockfd, SIOCGIFINDEX, &ifr);
    if (ret < 0) {
        printf("ioctl ret : %d\n",ret);
        perror("ioctl");
        exit(EXIT_FAILURE);
    }
    printf("ioctl ret : %d\n",ret);

    // 绑定 socket 到指定网络接口
    memset(&addr, 0, sizeof(addr));
    addr.sll_family = AF_PACKET;
    addr.sll_ifindex = ifr.ifr_ifindex;
    addr.sll_protocol = htons(ETH_P_ALL);
    ret = bind(sockfd, (struct sockaddr *)&addr, sizeof(addr));
    if (ret < 0) {
        printf("ioctl ret : %d\n",ret);
        perror("bind");
        exit(EXIT_FAILURE);
    }

    printf("bind ret : %d\n",ret);

    while (1) {
        // 接收数据帧
        memset(buffer, 0, sizeof(buffer));
        ret = recvfrom(sockfd, buffer, BUFFER_SIZE, 0, (struct sockaddr *)&addr, &addr_len);
        if (ret < 0) {
            printf("recvfrom error %d\n",ret);
            perror("recvfrom");
            break;
        }

        memcpy(LLC_Protocol.source_mac,&buffer[6],6);
        if (memcmp(LLC_Protocol.source_mac, allowed_mac, 6) == 0) 
        {
            printf("Received !!!!!!\n");
            printf("Received %d bytes from interface %d:\n", ret, addr.sll_ifindex);
            printf("Destination MAC address: %02x:%02x:%02x:%02x:%02x:%02x\n", buffer[0], buffer[1], buffer[2], buffer[3], buffer[4], buffer[5]);
            printf("Source MAC address: %02x:%02x:%02x:%02x:%02x:%02x\n", buffer[6], buffer[7], buffer[8], buffer[9],buffer[10], buffer[11]);
            printf("Ethernet lenth: %02x%02x\n", buffer[12], buffer[13]);
            printf("Data: ");
            for (int i = 0; i < ret; i++) {
                printf("%02x ",buffer[i]);
            }
            printf("\n");
        }

        // ret = sendto(sockfd, buffer, ret, 0, (struct sockaddr *)&addr, sizeof(addr));
        // if (ret < 0) {
        //     perror("sendto");
        //     break;
        // }
    }

    close(sockfd);
    return 0;
}


void *send_thread(void *arg) {
    int sockfd = *((int *)arg);
    uint8_t data[64] = {0xFE};
    while (1) {
        // buf = (uint8_t *)g_async_queue_pop(queue);
        // int n = send(sockfd, buf, strlen(buf), 0);
        // if (n < 0) {
        //     perror("send");
        // }
        // g_free(buf);
        pthread_mutex_lock(&LLC_Protocol_mutex);  // 加锁
        if(LLC_Protocol.lenth> 0)
        {
            printf("%d,%02x %02x\n",LLC_Protocol.lenth,LLC_Protocol.Data[0],LLC_Protocol.Data[1]);  
            printf("\n");                    
            if(LLC_Protocol.lenth < MAX_DATA_SIZE)
            {
                int n =send(sockfd, LLC_Protocol.Data, LLC_Protocol.lenth, 0);
                if (n < 0) {
                    perror("send");
                }
            }
        }
        LLC_Protocol.lenth = 0;
        pthread_mutex_unlock(&LLC_Protocol_mutex);  // 解锁
    }
    return NULL;
}

void *recv_thread(void *arg) {
    int sockfd = *((int *)arg);
    int n;
    while (1) {
        memset(recv_buf, 0, sizeof(recv_buf));
        n = recv(sockfd, recv_buf, sizeof(recv_buf), 0);
        if (n <= 0) {
            printf("Connection closed\n");
            exit(0);
        }
        printf("Received message: %s", recv_buf);
    }
    return NULL;
}

void *thread_tcp(void *thread_id){

    int sockfd;
    struct sockaddr_in servaddr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket creation failed");
        exit(0);
    }
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);


    if (inet_pton(AF_INET, IP_ADDR, &servaddr.sin_addr) <= 0) {
        perror("inet_pton failed");
        exit(0);
    }


    int flag = 1;
    int result = 0;
    result = setsockopt(sockfd, IPPROTO_TCP, TCP_NODELAY, &flag, sizeof(int));
    if (result < 0) {
        perror("setsockopt failed");
        exit(0);
    }

    // result = setsockopt(sockfd, IPPROTO_TCP, TCP_FASTRETRANS, &flag, sizeof(int));
    // if (result < 0) {
    //     perror("setsockopt failed");
    //     exit(0);
    // }

    result = setsockopt(sockfd, IPPROTO_TCP, TCP_CORK, &flag, sizeof(int));
    if (result < 0) {
        perror("setsockopt failed");
        exit(0);
    }

    printf("setsockopt\n");

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("connect failed");
        // printf("servaddr");
        exit(0);
    }
    pthread_t send_tid, recv_tid;
    if (pthread_create(&send_tid, NULL, send_thread, (void *)&sockfd) != 0) {
        perror("send thread creation failed");
        exit(0);
    }
    if (pthread_create(&recv_tid, NULL, recv_thread,(void *)&sockfd) != 0) {
        perror("recv thread creation failed");
        exit(0);
    }
    pthread_join(send_tid, NULL);
    pthread_join(recv_tid, NULL);    
}

int main()
{
    pthread_t threads[2];
    int rc;
    long t;

    // printf("Creating thread %ld\n", t);
    // rc = pthread_create(&threads[t], NULL, thread_tcp, (void *)t);
    // if (rc) {
    //     printf("ERROR; return code from pthread_create() is %d\n", rc);
    //     return -1;
    // }

    printf("Creating thread %ld\n", t);
    rc = pthread_create(&threads[t], NULL, thread_Lin_Layer, (void *)t);
    if (rc) {
        printf("ERROR; return code from pthread_create() is %d\n", rc);
        return -1;
    }    

    pthread_join(threads[0], NULL);
    pthread_join(threads[1], NULL);

    pthread_exit(NULL);
    return 0;

}

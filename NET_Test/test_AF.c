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
#include <errno.h>
#include <time.h>

#define BUFFER_SIZE 65536
#define IP_ADDR "192.168.0.234"
#define PORT 6321
#define MAX_BUFFER_SIZE 1024
#define MAX_DATA_SIZE 512

typedef struct{         
    // 定义以太网帧结构
  uint8_t destination_mac[6];
  uint8_t source_mac[6];
  uint16_t lenth;
  uint8_t Data[MAX_DATA_SIZE];
//   unsigned int fcs; // 帧校验序列
}ethernet_frame;

char recv_buf[MAX_BUFFER_SIZE];  // 接收缓冲区
struct timeval timeout;  // Recv超时时间
ethernet_frame LLC_Protocol;  // LLC协议
pthread_mutex_t LLC_Protocol_mutex = PTHREAD_MUTEX_INITIALIZER;  // 初始化互斥锁
pthread_t send_tid, recv_tid,close_tid;  //初始化send,recv,close线程
volatile int thread_should_eixt = 0;  // 线程退出标志
struct sockaddr_in servaddr;  // 服务器地址
uint8_t Keep_alive[8] = {0x88};  // 保活帧
uint32_t Net_count = 0;  // 网络存活计数器

int Net_kill(int *sockfd) {
    // 关闭 TCP 连接
    close(*sockfd);

    // 设置线程退出标志
    thread_should_eixt = 2;

    // 等待线程自己结束
    pthread_join(send_tid, NULL);
    pthread_join(recv_tid, NULL);

    // 清除线程退出标志
    thread_should_eixt = 0;
    return 1;
}

//链路层线程
void *thread_Lin_Layer(void *thread_id) {
    int sockfd, ret;
    uint8_t buffer[BUFFER_SIZE];
    struct sockaddr_ll addr;
    socklen_t addr_len = sizeof(addr);
    unsigned char allowed_mac[6] = {0x66, 0x55, 0x44, 0x33, 0x22, 0x11};

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

        pthread_mutex_lock(&LLC_Protocol_mutex);  // 加锁
        if(ret > 14)
        {
            memset((uint8_t *)&LLC_Protocol,0,sizeof(ethernet_frame));
            memcpy(LLC_Protocol.destination_mac,&buffer[0],6);
            memcpy(LLC_Protocol.source_mac,&buffer[6],6);
            
            // 比较接收到的 MAC 地址和需要转发的 MAC 地址是否一致
            if (memcmp(LLC_Protocol.source_mac, allowed_mac, 6) == 0) 
            {
                LLC_Protocol.lenth = buffer[13]+buffer[12]*256;
                
                if(LLC_Protocol.lenth > 0 && LLC_Protocol.lenth < MAX_DATA_SIZE)
                {
                    memcpy(LLC_Protocol.Data,&buffer[14],LLC_Protocol.lenth);                   
                }
                else
                {
        
                }
            }
        }
        pthread_mutex_unlock(&LLC_Protocol_mutex);  // 解锁
    }

    close(sockfd);
    return 0;
}


void *send_thread(void *arg) {
    int sockfd = *((int *)arg);
    uint8_t data[64] = {0xFE};
    while (1) {
        if(thread_should_eixt == 2)
        {
            return NULL;            
        }
        pthread_mutex_lock(&LLC_Protocol_mutex);  // 加锁
        if(LLC_Protocol.lenth> 0)
        {
            printf("Send:%d,%02x %02x\n",LLC_Protocol.lenth,LLC_Protocol.Data[0],LLC_Protocol.Data[1]);  
            if(LLC_Protocol.lenth < MAX_DATA_SIZE)
            {
                int n =send(sockfd, LLC_Protocol.Data, LLC_Protocol.lenth, 0);
                if (n < 0) {
                    thread_should_eixt = 1;
                    perror("send");
                    pthread_mutex_unlock(&LLC_Protocol_mutex);  // 解锁
                    return NULL;  // 发送失败，退出线程
                }
            }
            LLC_Protocol.lenth = 0;  // 发送成功，重置长度
        }
        pthread_mutex_unlock(&LLC_Protocol_mutex);  // 解锁
    }
    thread_should_eixt = 1;
    return NULL;
}

void *recv_thread(void *arg) {
    int sockfd = *((int *)arg);
    int n;
    while (1) {
        if(thread_should_eixt == 2)
        {
            return NULL;            
        }
        memset(recv_buf, 0, sizeof(recv_buf));
        n = recv(sockfd, recv_buf, sizeof(recv_buf), 0);
        if (n < 0) {
            if (errno == EWOULDBLOCK || errno == EAGAIN) {
                printf("recv timeout\n");
            } else {
                perror("recv failed");
                thread_should_eixt = 1;
            }
        }
        else
        {
            Net_count = 0;
        }

        if(Net_count > 10000)
        {
            thread_should_eixt = 1;
        }
        printf("Received message: %s", recv_buf);
    }
    thread_should_eixt = 1;
    return NULL;
}

// 错误处理：在创建socket、连接服务器、发送和接收数据等操作失败时，进行适当的错误处理
void tcp_connect(int *sockfd)
{
    int flag = 1;
    int result = 0;
    timeout.tv_sec = 1;  // 设置超时为1秒
    timeout.tv_usec = 0;

    int optval;
    socklen_t optlen = sizeof(optval);

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

    while (1) {
        if (connect(*sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) >= 0) {
            // 连接成功
            printf("Connect!!!!\n");
            break;
        } else {
            // 连接失败，等待一段时间后重试
            printf("connecting......\n");
            sleep(1);
        }
    }

    Net_count = 0;
    if (pthread_create(&send_tid, NULL, send_thread, (void *)&sockfd) != 0) {
        perror("send thread creation failed");
        exit(0);
    }

    if (pthread_create(&recv_tid, NULL, recv_thread,(void *)&sockfd) != 0) {
        perror("recv thread creation failed");
        exit(0);
    }
}

void *thread_tcp(void *thread_id){

    int sockfd;

    // 关闭旧的socket
    if (*sockfd != -1) {
        close(*sockfd);
    }
    
    tcp_connect(&sockfd);

    while(1)
    {
        if(thread_should_eixt)
        {
            Net_kill(&sockfd);
            tcp_connect(&sockfd);
        }

    }
    pthread_join(send_tid, NULL);
    pthread_join(recv_tid, NULL);    
}

void *timer_thread(void *thread_id){
    struct timespec ts;
    ts.tv_sec = 0;
    ts.tv_nsec = 1000000;  // 1ms

    while(1)
    {
        Net_count ++;
        nanosleep(&ts, NULL);

        if(Net_count % 1000 == 0)
        {
            pthread_mutex_lock(&LLC_Protocol_mutex);  // 加锁
            if(LLC_Protocol.lenth ==  0)
            {
                LLC_Protocol.lenth = 8;
                memcpy(LLC_Protocol.Data,Keep_alive,8);
            }
            pthread_mutex_unlock(&LLC_Protocol_mutex);  // 解锁
        }
    }
}

int main()
{
    pthread_t threads[3];
    int rc;
    long t;

    // 创建线程，并检查返回值
    printf("Creating thread %ld\n", t);
    rc = pthread_create(&threads[t], NULL, thread_tcp, (void *)t);
    if (rc) {
        printf("ERROR; return code from pthread_create() is %d\n", rc);
        return -1;
    }   

    t++;
    printf("Creating thread %ld\n", t);
    rc = pthread_create(&threads[t], NULL, thread_Lin_Layer, (void *)t);
    if (rc) {
        printf("ERROR; return code from pthread_create() is %d\n", rc);
        return -1;
    }    

    t++;
    printf("Creating thread %ld\n", t);
    rc = pthread_create(&threads[t], NULL, timer_thread, (void *)t);
    if (rc) {
        printf("ERROR; return code from pthread_create() is %d\n", rc);
        return -1;
    }  

    // 等待所有子线程结束，并释放它们占用的资源
    for (t = 0; t < 3; t++) {
        rc = pthread_join(threads[t], NULL);
        if (rc) {
            printf("ERROR; return code from pthread_join() is %d\n", rc);
            return -1;
        }
    }

    pthread_exit(NULL);
    return 0;
}

}

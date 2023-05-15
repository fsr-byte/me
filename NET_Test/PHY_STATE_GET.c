#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <linux/sockios.h>
#include <linux/if.h>
#include <linux/ethtool.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int sockfd, err;
    struct ifreq ifr;
    struct ethtool_value edata;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <interface>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    strncpy(ifr.ifr_name, argv[1], IFNAMSIZ - 1);
    edata.cmd = ETHTOOL_GLINK;
    ifr.ifr_data = (char *)&edata;

    while (1) {
        err = ioctl(sockfd, SIOCETHTOOL, &ifr);
        if (err < 0) {
            perror("ioctl");
            exit(EXIT_FAILURE);
        }
        printf("PHY is %s\n", edata.data ? "up" : "down");
        sleep(1);
    }

    close(sockfd);
    return 0;
}

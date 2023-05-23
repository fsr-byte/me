#!/bin/bash

aarch64-none-linux-gnu-gcc -pthread test_AF.c -o ALL_test
sudo rm /home/fsr/linux/nfs/All_test
sudo cp ALL_test /home/fsr/linux/nfs/All_test
sudo chmod 777 /home/fsr/linux/nfs/All_test
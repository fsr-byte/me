################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/HAL/BASE/ADC.c \
../src/HAL/BASE/CAN.c \
../src/HAL/BASE/DataStruct.c \
../src/HAL/BASE/FEC.c \
../src/HAL/BASE/GPIO.c \
../src/HAL/BASE/Lin.c \
../src/HAL/BASE/SPI.c \
../src/HAL/BASE/SYS.c \
../src/HAL/BASE/eMIOS.c \
../src/HAL/BASE/eTPU.c \
../src/HAL/BASE/flash.c 

OBJS += \
./src/HAL/BASE/ADC.o \
./src/HAL/BASE/CAN.o \
./src/HAL/BASE/DataStruct.o \
./src/HAL/BASE/FEC.o \
./src/HAL/BASE/GPIO.o \
./src/HAL/BASE/Lin.o \
./src/HAL/BASE/SPI.o \
./src/HAL/BASE/SYS.o \
./src/HAL/BASE/eMIOS.o \
./src/HAL/BASE/eTPU.o \
./src/HAL/BASE/flash.o 

C_DEPS += \
./src/HAL/BASE/ADC.d \
./src/HAL/BASE/CAN.d \
./src/HAL/BASE/DataStruct.d \
./src/HAL/BASE/FEC.d \
./src/HAL/BASE/GPIO.d \
./src/HAL/BASE/Lin.d \
./src/HAL/BASE/SPI.d \
./src/HAL/BASE/SYS.d \
./src/HAL/BASE/eMIOS.d \
./src/HAL/BASE/eTPU.d \
./src/HAL/BASE/flash.d 


# Each subdirectory must supply rules for building sources it contributes
src/HAL/BASE/%.o: ../src/HAL/BASE/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@src/HAL/BASE/ADC.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



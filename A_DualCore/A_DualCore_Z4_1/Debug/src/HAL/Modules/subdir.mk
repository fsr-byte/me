################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/HAL/Modules/BTS.c \
../src/HAL/Modules/FS6500.c \
../src/HAL/Modules/LinDevice.c \
../src/HAL/Modules/M95128.c \
../src/HAL/Modules/NCV7240B.c \
../src/HAL/Modules/NCV7513B.c \
../src/HAL/Modules/NCV7719.c \
../src/HAL/Modules/TJA1100.c 

OBJS += \
./src/HAL/Modules/BTS.o \
./src/HAL/Modules/FS6500.o \
./src/HAL/Modules/LinDevice.o \
./src/HAL/Modules/M95128.o \
./src/HAL/Modules/NCV7240B.o \
./src/HAL/Modules/NCV7513B.o \
./src/HAL/Modules/NCV7719.o \
./src/HAL/Modules/TJA1100.o 

C_DEPS += \
./src/HAL/Modules/BTS.d \
./src/HAL/Modules/FS6500.d \
./src/HAL/Modules/LinDevice.d \
./src/HAL/Modules/M95128.d \
./src/HAL/Modules/NCV7240B.d \
./src/HAL/Modules/NCV7513B.d \
./src/HAL/Modules/NCV7719.d \
./src/HAL/Modules/TJA1100.d 


# Each subdirectory must supply rules for building sources it contributes
src/HAL/Modules/%.o: ../src/HAL/Modules/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@src/HAL/Modules/BTS.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



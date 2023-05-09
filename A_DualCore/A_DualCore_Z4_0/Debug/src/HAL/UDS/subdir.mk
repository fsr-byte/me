################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/HAL/UDS/UDS_Interface.c \
../src/HAL/UDS/uds_service.c \
../src/HAL/UDS/uds_tp.c 

OBJS += \
./src/HAL/UDS/UDS_Interface.o \
./src/HAL/UDS/uds_service.o \
./src/HAL/UDS/uds_tp.o 

C_DEPS += \
./src/HAL/UDS/UDS_Interface.d \
./src/HAL/UDS/uds_service.d \
./src/HAL/UDS/uds_tp.d 


# Each subdirectory must supply rules for building sources it contributes
src/HAL/UDS/%.o: ../src/HAL/UDS/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@src/HAL/UDS/UDS_Interface.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



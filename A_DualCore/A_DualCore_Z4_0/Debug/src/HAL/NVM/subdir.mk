################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/HAL/NVM/History_Data.c \
../src/HAL/NVM/NVM.c \
../src/HAL/NVM/NVM_AppData.c \
../src/HAL/NVM/NVM_DTC.c \
../src/HAL/NVM/NVM_DidCal.c 

OBJS += \
./src/HAL/NVM/History_Data.o \
./src/HAL/NVM/NVM.o \
./src/HAL/NVM/NVM_AppData.o \
./src/HAL/NVM/NVM_DTC.o \
./src/HAL/NVM/NVM_DidCal.o 

C_DEPS += \
./src/HAL/NVM/History_Data.d \
./src/HAL/NVM/NVM.d \
./src/HAL/NVM/NVM_AppData.d \
./src/HAL/NVM/NVM_DTC.d \
./src/HAL/NVM/NVM_DidCal.d 


# Each subdirectory must supply rules for building sources it contributes
src/HAL/NVM/%.o: ../src/HAL/NVM/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@src/HAL/NVM/History_Data.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



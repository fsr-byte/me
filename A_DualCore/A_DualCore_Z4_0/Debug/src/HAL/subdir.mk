################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/HAL/CAN_Operation.c \
../src/HAL/Global.c \
../src/HAL/Interrupt.c \
../src/HAL/Task.c 

OBJS += \
./src/HAL/CAN_Operation.o \
./src/HAL/Global.o \
./src/HAL/Interrupt.o \
./src/HAL/Task.o 

C_DEPS += \
./src/HAL/CAN_Operation.d \
./src/HAL/Global.d \
./src/HAL/Interrupt.d \
./src/HAL/Task.d 


# Each subdirectory must supply rules for building sources it contributes
src/HAL/%.o: ../src/HAL/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@src/HAL/CAN_Operation.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



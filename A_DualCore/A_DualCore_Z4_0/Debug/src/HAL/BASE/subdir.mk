################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/HAL/BASE/CAN.c \
../src/HAL/BASE/GPIO.c \
../src/HAL/BASE/SYS.c \
../src/HAL/BASE/flash.c 

OBJS += \
./src/HAL/BASE/CAN.o \
./src/HAL/BASE/GPIO.o \
./src/HAL/BASE/SYS.o \
./src/HAL/BASE/flash.o 

C_DEPS += \
./src/HAL/BASE/CAN.d \
./src/HAL/BASE/GPIO.d \
./src/HAL/BASE/SYS.d \
./src/HAL/BASE/flash.d 


# Each subdirectory must supply rules for building sources it contributes
src/HAL/BASE/%.o: ../src/HAL/BASE/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@src/HAL/BASE/CAN.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



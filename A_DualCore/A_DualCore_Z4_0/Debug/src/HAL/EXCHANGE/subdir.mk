################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/HAL/EXCHANGE/EX_Code.c \
../src/HAL/EXCHANGE/EX_Data.c \
../src/HAL/EXCHANGE/EX_Lib.c 

OBJS += \
./src/HAL/EXCHANGE/EX_Code.o \
./src/HAL/EXCHANGE/EX_Data.o \
./src/HAL/EXCHANGE/EX_Lib.o 

C_DEPS += \
./src/HAL/EXCHANGE/EX_Code.d \
./src/HAL/EXCHANGE/EX_Data.d \
./src/HAL/EXCHANGE/EX_Lib.d 


# Each subdirectory must supply rules for building sources it contributes
src/HAL/EXCHANGE/%.o: ../src/HAL/EXCHANGE/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@src/HAL/EXCHANGE/EX_Code.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



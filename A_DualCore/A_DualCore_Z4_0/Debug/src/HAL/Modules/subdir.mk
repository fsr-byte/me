################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/HAL/Modules/M95128.c 

OBJS += \
./src/HAL/Modules/M95128.o 

C_DEPS += \
./src/HAL/Modules/M95128.d 


# Each subdirectory must supply rules for building sources it contributes
src/HAL/Modules/%.o: ../src/HAL/Modules/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@src/HAL/Modules/M95128.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



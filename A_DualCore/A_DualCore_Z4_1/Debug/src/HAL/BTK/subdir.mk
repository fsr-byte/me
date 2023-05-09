################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/HAL/BTK/BTK_ESCL.c 

OBJS += \
./src/HAL/BTK/BTK_ESCL.o 

C_DEPS += \
./src/HAL/BTK/BTK_ESCL.d 


# Each subdirectory must supply rules for building sources it contributes
src/HAL/BTK/%.o: ../src/HAL/BTK/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@src/HAL/BTK/BTK_ESCL.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



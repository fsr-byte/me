################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/HAL/CCP/CCP.c 

OBJS += \
./src/HAL/CCP/CCP.o 

C_DEPS += \
./src/HAL/CCP/CCP.d 


# Each subdirectory must supply rules for building sources it contributes
src/HAL/CCP/%.o: ../src/HAL/CCP/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@src/HAL/CCP/CCP.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



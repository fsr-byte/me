################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/HAL/Klima/Kilma_Lin.c 

OBJS += \
./src/HAL/Klima/Kilma_Lin.o 

C_DEPS += \
./src/HAL/Klima/Kilma_Lin.d 


# Each subdirectory must supply rules for building sources it contributes
src/HAL/Klima/%.o: ../src/HAL/Klima/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@src/HAL/Klima/Kilma_Lin.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



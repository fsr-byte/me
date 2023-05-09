################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/HAL/BASE/etpu_set/etpu/fpm/etpu_fpm.c 

OBJS += \
./src/HAL/BASE/etpu_set/etpu/fpm/etpu_fpm.o 

C_DEPS += \
./src/HAL/BASE/etpu_set/etpu/fpm/etpu_fpm.d 


# Each subdirectory must supply rules for building sources it contributes
src/HAL/BASE/etpu_set/etpu/fpm/%.o: ../src/HAL/BASE/etpu_set/etpu/fpm/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@src/HAL/BASE/etpu_set/etpu/fpm/etpu_fpm.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



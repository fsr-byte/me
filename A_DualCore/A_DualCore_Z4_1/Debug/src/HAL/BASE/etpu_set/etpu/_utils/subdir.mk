################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/HAL/BASE/etpu_set/etpu/_utils/etpu_util.c 

OBJS += \
./src/HAL/BASE/etpu_set/etpu/_utils/etpu_util.o 

C_DEPS += \
./src/HAL/BASE/etpu_set/etpu/_utils/etpu_util.d 


# Each subdirectory must supply rules for building sources it contributes
src/HAL/BASE/etpu_set/etpu/_utils/%.o: ../src/HAL/BASE/etpu_set/etpu/_utils/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@src/HAL/BASE/etpu_set/etpu/_utils/etpu_util.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



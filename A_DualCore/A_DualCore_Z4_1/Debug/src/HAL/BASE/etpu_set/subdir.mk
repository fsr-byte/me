################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/HAL/BASE/etpu_set/untitled_etpu_gct.c 

OBJS += \
./src/HAL/BASE/etpu_set/untitled_etpu_gct.o 

C_DEPS += \
./src/HAL/BASE/etpu_set/untitled_etpu_gct.d 


# Each subdirectory must supply rules for building sources it contributes
src/HAL/BASE/etpu_set/%.o: ../src/HAL/BASE/etpu_set/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@src/HAL/BASE/etpu_set/untitled_etpu_gct.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/MPC57xx__Interrupt_Init.c \
../src/Vector.c \
../src/flashrchw.c \
../src/intc_SW_mode_isr_vectors_MPC574xR.c \
../src/main_Z4_1.c 

S_UPPER_SRCS += \
../src/intc_sw_handlers.S 

OBJS += \
./src/MPC57xx__Interrupt_Init.o \
./src/Vector.o \
./src/flashrchw.o \
./src/intc_SW_mode_isr_vectors_MPC574xR.o \
./src/intc_sw_handlers.o \
./src/main_Z4_1.o 

C_DEPS += \
./src/MPC57xx__Interrupt_Init.d \
./src/Vector.d \
./src/flashrchw.d \
./src/intc_SW_mode_isr_vectors_MPC574xR.d \
./src/main_Z4_1.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@src/MPC57xx__Interrupt_Init.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/%.o: ../src/%.S
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS Assembler'
	powerpc-eabivle-gcc "@src/intc_sw_handlers.args" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



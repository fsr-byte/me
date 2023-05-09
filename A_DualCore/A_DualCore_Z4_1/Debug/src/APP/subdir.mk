################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/APP/BTK_ACT_PEPS.c \
../src/APP/BTK_Cal_Data.c \
../src/APP/BTK_Model.c \
../src/APP/BTK_Model_data.c \
../src/APP/BTK_lib.c \
../src/APP/DIM_model.c \
../src/APP/DOM_model.c 

OBJS += \
./src/APP/BTK_ACT_PEPS.o \
./src/APP/BTK_Cal_Data.o \
./src/APP/BTK_Model.o \
./src/APP/BTK_Model_data.o \
./src/APP/BTK_lib.o \
./src/APP/DIM_model.o \
./src/APP/DOM_model.o 

C_DEPS += \
./src/APP/BTK_ACT_PEPS.d \
./src/APP/BTK_Cal_Data.d \
./src/APP/BTK_Model.d \
./src/APP/BTK_Model_data.d \
./src/APP/BTK_lib.d \
./src/APP/DIM_model.d \
./src/APP/DOM_model.d 


# Each subdirectory must supply rules for building sources it contributes
src/APP/%.o: ../src/APP/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@src/APP/BTK_ACT_PEPS.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



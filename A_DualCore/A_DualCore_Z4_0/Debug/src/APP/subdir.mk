################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/APP/ACR_Cal_Data.c \
../src/APP/AVAS_Cal_Data.c \
../src/APP/BTK_Cal_Data.c \
../src/APP/CHRG_Cal_Data.c \
../src/APP/DHP.c \
../src/APP/DHP_CC_FltStore.c \
../src/APP/DHP_Cal_Data.c \
../src/APP/DHP_Sub_HardwireSignal_Filter.c \
../src/APP/DHP_model.c \
../src/APP/DIM_Cal_Data.c \
../src/APP/DOM_Cal_Data.c \
../src/APP/ENM_Cal_Data.c \
../src/APP/Funcs_DHP_lib.c \
../src/APP/HAL_Cal_Data.c \
../src/APP/NM_Cal_Data.c \
../src/APP/PEPS_Cal_Data.c \
../src/APP/PMM_Cal_Data.c \
../src/APP/SCR_Cal_Data.c \
../src/APP/TMM_Cal_Data.c \
../src/APP/TQFRate_Cal_Data.c \
../src/APP/TQM_Cal_Data.c 

OBJS += \
./src/APP/ACR_Cal_Data.o \
./src/APP/AVAS_Cal_Data.o \
./src/APP/BTK_Cal_Data.o \
./src/APP/CHRG_Cal_Data.o \
./src/APP/DHP.o \
./src/APP/DHP_CC_FltStore.o \
./src/APP/DHP_Cal_Data.o \
./src/APP/DHP_Sub_HardwireSignal_Filter.o \
./src/APP/DHP_model.o \
./src/APP/DIM_Cal_Data.o \
./src/APP/DOM_Cal_Data.o \
./src/APP/ENM_Cal_Data.o \
./src/APP/Funcs_DHP_lib.o \
./src/APP/HAL_Cal_Data.o \
./src/APP/NM_Cal_Data.o \
./src/APP/PEPS_Cal_Data.o \
./src/APP/PMM_Cal_Data.o \
./src/APP/SCR_Cal_Data.o \
./src/APP/TMM_Cal_Data.o \
./src/APP/TQFRate_Cal_Data.o \
./src/APP/TQM_Cal_Data.o 

C_DEPS += \
./src/APP/ACR_Cal_Data.d \
./src/APP/AVAS_Cal_Data.d \
./src/APP/BTK_Cal_Data.d \
./src/APP/CHRG_Cal_Data.d \
./src/APP/DHP.d \
./src/APP/DHP_CC_FltStore.d \
./src/APP/DHP_Cal_Data.d \
./src/APP/DHP_Sub_HardwireSignal_Filter.d \
./src/APP/DHP_model.d \
./src/APP/DIM_Cal_Data.d \
./src/APP/DOM_Cal_Data.d \
./src/APP/ENM_Cal_Data.d \
./src/APP/Funcs_DHP_lib.d \
./src/APP/HAL_Cal_Data.d \
./src/APP/NM_Cal_Data.d \
./src/APP/PEPS_Cal_Data.d \
./src/APP/PMM_Cal_Data.d \
./src/APP/SCR_Cal_Data.d \
./src/APP/TMM_Cal_Data.d \
./src/APP/TQFRate_Cal_Data.d \
./src/APP/TQM_Cal_Data.d 


# Each subdirectory must supply rules for building sources it contributes
src/APP/%.o: ../src/APP/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@src/APP/ACR_Cal_Data.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



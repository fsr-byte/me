################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/HAL/UDS/subdir.mk
-include src/HAL/NVM/subdir.mk
-include src/HAL/Modules/subdir.mk
-include src/HAL/EXCHANGE/subdir.mk
-include src/HAL/BASE/subdir.mk
-include src/HAL/subdir.mk
-include src/APP/subdir.mk
-include src/subdir.mk
-include Project_Settings/Startup_Code/subdir.mk
-include Project_Settings/Linker_Files/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
SECONDARY_FLASH += \
A_DualCore_Z4_0.srec \

SECONDARY_SIZE += \
A_DualCore_Z4_0.siz \


# All Target
all: A_DualCore_Z4_0.elf secondary-outputs

# Tool invocations
A_DualCore_Z4_0.elf: $(OBJS) C:/Users/fsr/code/project/A_DualCore/A_DualCore_Z4_0/Project_Settings/Linker_Files/57xx_flash.ld C:/Users/fsr/code/project/A_DualCore/A_DualCore_Z4_0/Project_Settings/Linker_Files/libs.ld $(OSPT) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: Standard S32DS C Linker'
	powerpc-eabivle-gcc -o "A_DualCore_Z4_0.elf" "@A_DualCore_Z4_0.args"  $(USER_OBJS) $(LIBS) $(OSPT)
	@echo 'Finished building target: $@'
	@echo ' '

A_DualCore_Z4_0.srec: A_DualCore_Z4_0.elf
	@echo 'Invoking: Standard S32DS Create Flash Image'
	powerpc-eabivle-objcopy -O srec A_DualCore_Z4_0.elf  "A_DualCore_Z4_0.srec"
	@echo 'Finished building: $@'
	@echo ' '

A_DualCore_Z4_0.siz: A_DualCore_Z4_0.elf
	@echo 'Invoking: Standard S32DS Print Size'
	powerpc-eabivle-size --format=berkeley A_DualCore_Z4_0.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) ./*
	-@echo ' '

secondary-outputs: $(SECONDARY_FLASH) $(SECONDARY_SIZE)

.PHONY: all clean dependents

-include ../makefile.targets

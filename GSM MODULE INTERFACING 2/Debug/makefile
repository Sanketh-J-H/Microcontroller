################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Drivers/STM32F4xx_HAL_Driver/Src/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := GSM MODULE INTERFACING 2
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
GSM\ MODULE\ INTERFACING\ 2.elf \

MAP_FILES += \
GSM\ MODULE\ INTERFACING\ 2.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
GSM\ MODULE\ INTERFACING\ 2.list \


# All Target
all: main-build

# Main-build Target
main-build: GSM\ MODULE\ INTERFACING\ 2.elf secondary-outputs

# Tool invocations
GSM\ MODULE\ INTERFACING\ 2.elf GSM\ MODULE\ INTERFACING\ 2.map: $(OBJS) $(USER_OBJS) /home/sanketh/data/LinuxTraining/STM32CubeIDE/workspace_1.12.0/GSM\ MODULE\ INTERFACING\ 2/STM32F411RETX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "GSM MODULE INTERFACING 2.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"/home/sanketh/data/LinuxTraining/STM32CubeIDE/workspace_1.12.0/GSM MODULE INTERFACING 2/STM32F411RETX_FLASH.ld" --specs=nosys.specs -Wl,-Map="GSM MODULE INTERFACING 2.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

GSM\ MODULE\ INTERFACING\ 2.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "GSM MODULE INTERFACING 2.list"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) GSM\ MODULE\ INTERFACING\ 2.elf GSM\ MODULE\ INTERFACING\ 2.list GSM\ MODULE\ INTERFACING\ 2.map GSM\\ MODULE\\ INTERFACING\\ 2.elf default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets

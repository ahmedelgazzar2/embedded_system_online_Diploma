################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include subdir.mk
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

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
toggle_LED_with_interrupt.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
toggle_LED_with_interrupt.list \

OBJCOPY_BIN += \
toggle_LED_with_interrupt.bin \


# All Target
all: toggle_LED_with_interrupt.elf secondary-outputs

# Tool invocations
toggle_LED_with_interrupt.elf: $(OBJS) $(USER_OBJS) C:\Users\Dell\STM32CubeIDE\interfacing\toggle_LED_with_interrupt\STM32F103C6TX_FLASH.ld
	arm-none-eabi-gcc -gdwarf-2 -o "toggle_LED_with_interrupt.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"C:\Users\Dell\STM32CubeIDE\interfacing\toggle_LED_with_interrupt\STM32F103C6TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="toggle_LED_with_interrupt.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

toggle_LED_with_interrupt.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "toggle_LED_with_interrupt.list"
	@echo 'Finished building: $@'
	@echo ' '

toggle_LED_with_interrupt.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "toggle_LED_with_interrupt.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
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
LSS += \
interrupt_test.lss \

FLASH_IMAGE += \
interrupt_test.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: interrupt_test.elf secondary-outputs

# Tool invocations
interrupt_test.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,interrupt_test.map -mmcu=atmega16 -o "interrupt_test.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

interrupt_test.lss: interrupt_test.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S interrupt_test.elf  >"interrupt_test.lss"
	@echo 'Finished building: $@'
	@echo ' '

interrupt_test.hex: interrupt_test.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex interrupt_test.elf  "interrupt_test.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: interrupt_test.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega16 interrupt_test.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) interrupt_test.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

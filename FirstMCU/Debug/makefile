################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/UART/subdir.mk
-include MCAL/GLOBAL_INIT/subdir.mk
-include MCAL/EXTI/subdir.mk
-include MCAL/DIO/subdir.mk
-include MCAL/ADC/subdir.mk
-include HAL/lcd/subdir.mk
-include HAL/keybad/subdir.mk
-include APP/subdir.mk
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
FirstMCU.lss \

FLASH_IMAGE += \
FirstMCU.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: FirstMCU.elf secondary-outputs

# Tool invocations
FirstMCU.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,FirstMCU.map -mmcu=atmega32 -o "FirstMCU.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

FirstMCU.lss: FirstMCU.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S FirstMCU.elf  >"FirstMCU.lss"
	@echo 'Finished building: $@'
	@echo ' '

FirstMCU.hex: FirstMCU.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex FirstMCU.elf  "FirstMCU.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: FirstMCU.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 FirstMCU.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) FirstMCU.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

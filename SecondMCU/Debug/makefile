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
-include HAL/motor/subdir.mk
-include HAL/dcmotor/subdir.mk
-include HAL/MQ2/subdir.mk
-include HAL/LED/subdir.mk
-include HAL/Buzzer/subdir.mk
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
SecondMCU.lss \

FLASH_IMAGE += \
SecondMCU.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: SecondMCU.elf secondary-outputs

# Tool invocations
SecondMCU.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,SecondMCU.map -mmcu=atmega32 -o "SecondMCU.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

SecondMCU.lss: SecondMCU.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S SecondMCU.elf  >"SecondMCU.lss"
	@echo 'Finished building: $@'
	@echo ' '

SecondMCU.hex: SecondMCU.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex SecondMCU.elf  "SecondMCU.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: SecondMCU.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 SecondMCU.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) SecondMCU.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

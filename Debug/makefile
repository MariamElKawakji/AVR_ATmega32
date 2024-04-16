################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include DIO/subdir.mk
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
My_AVR_ATmega32.lss \

FLASH_IMAGE += \
My_AVR_ATmega32.hex \

EEPROM_IMAGE += \
My_AVR_ATmega32.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: My_AVR_ATmega32.elf secondary-outputs

# Tool invocations
My_AVR_ATmega32.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,My_AVR_ATmega32.map -mmcu=atmega32 -o "My_AVR_ATmega32.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

My_AVR_ATmega32.lss: My_AVR_ATmega32.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S My_AVR_ATmega32.elf  >"My_AVR_ATmega32.lss"
	@echo 'Finished building: $@'
	@echo ' '

My_AVR_ATmega32.hex: My_AVR_ATmega32.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex My_AVR_ATmega32.elf  "My_AVR_ATmega32.hex"
	@echo 'Finished building: $@'
	@echo ' '

My_AVR_ATmega32.eep: My_AVR_ATmega32.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex My_AVR_ATmega32.elf  "My_AVR_ATmega32.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: My_AVR_ATmega32.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 My_AVR_ATmega32.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) My_AVR_ATmega32.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

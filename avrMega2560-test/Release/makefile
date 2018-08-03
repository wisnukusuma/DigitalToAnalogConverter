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
avrMega2560-test.lss \

FLASH_IMAGE += \
avrMega2560-test.hex \

EEPROM_IMAGE += \
avrMega2560-test.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: avrMega2560-test.elf secondary-outputs

# Tool invocations
avrMega2560-test.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,avrMega2560-test.map -mmcu=atmega2560 -o "avrMega2560-test.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

avrMega2560-test.lss: avrMega2560-test.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S avrMega2560-test.elf  >"avrMega2560-test.lss"
	@echo 'Finished building: $@'
	@echo ' '

avrMega2560-test.hex: avrMega2560-test.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex avrMega2560-test.elf  "avrMega2560-test.hex"
	@echo 'Finished building: $@'
	@echo ' '

avrMega2560-test.eep: avrMega2560-test.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex avrMega2560-test.elf  "avrMega2560-test.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: avrMega2560-test.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega2560 avrMega2560-test.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) avrMega2560-test.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

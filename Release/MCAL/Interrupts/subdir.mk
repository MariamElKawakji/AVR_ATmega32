################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/Interrupts/Interrupts.c 

OBJS += \
./MCAL/Interrupts/Interrupts.o 

C_DEPS += \
./MCAL/Interrupts/Interrupts.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/Interrupts/%.o: ../MCAL/Interrupts/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\C_Eclipse_Workspace\My_AVR_ATmega32" -I"D:\C_Eclipse_Workspace\My_AVR_ATmega32\Common_Files" -I"D:\C_Eclipse_Workspace\My_AVR_ATmega32\MCAL" -I"D:\C_Eclipse_Workspace\My_AVR_ATmega32\HAL" -I"D:\C_Eclipse_Workspace\My_AVR_ATmega32\APP" -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



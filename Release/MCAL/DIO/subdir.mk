################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/DIO/DIO.c \
../MCAL/DIO/DIO_LCFG.c 

OBJS += \
./MCAL/DIO/DIO.o \
./MCAL/DIO/DIO_LCFG.o 

C_DEPS += \
./MCAL/DIO/DIO.d \
./MCAL/DIO/DIO_LCFG.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/DIO/%.o: ../MCAL/DIO/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\C_Eclipse_Workspace\My_AVR_ATmega32" -I"D:\C_Eclipse_Workspace\My_AVR_ATmega32\Common_Files" -I"D:\C_Eclipse_Workspace\My_AVR_ATmega32\MCAL" -I"D:\C_Eclipse_Workspace\My_AVR_ATmega32\HAL" -I"D:\C_Eclipse_Workspace\My_AVR_ATmega32\APP" -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



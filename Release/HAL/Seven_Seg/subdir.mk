################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/Seven_Seg/HSEVEN_SEG_Program.c 

OBJS += \
./HAL/Seven_Seg/HSEVEN_SEG_Program.o 

C_DEPS += \
./HAL/Seven_Seg/HSEVEN_SEG_Program.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/Seven_Seg/%.o: ../HAL/Seven_Seg/%.c HAL/Seven_Seg/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



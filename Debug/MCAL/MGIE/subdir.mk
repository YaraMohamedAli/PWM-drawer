################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/MGIE/MGIE_Program.c 

OBJS += \
./MCAL/MGIE/MGIE_Program.o 

C_DEPS += \
./MCAL/MGIE/MGIE_Program.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/MGIE/%.o: ../MCAL/MGIE/%.c MCAL/MGIE/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



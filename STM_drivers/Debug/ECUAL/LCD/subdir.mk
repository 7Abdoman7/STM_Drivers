################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ECUAL/LCD/LCD_Program.c 

OBJS += \
./ECUAL/LCD/LCD_Program.o 

C_DEPS += \
./ECUAL/LCD/LCD_Program.d 


# Each subdirectory must supply rules for building sources it contributes
ECUAL/LCD/LCD_Program.o: ../ECUAL/LCD/LCD_Program.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"ECUAL/LCD/LCD_Program.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"


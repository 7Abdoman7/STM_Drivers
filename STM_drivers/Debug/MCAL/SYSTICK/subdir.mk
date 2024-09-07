################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/SYSTICK/SYSTICK_Program.c 

OBJS += \
./MCAL/SYSTICK/SYSTICK_Program.o 

C_DEPS += \
./MCAL/SYSTICK/SYSTICK_Program.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/SYSTICK/SYSTICK_Program.o: ../MCAL/SYSTICK/SYSTICK_Program.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"MCAL/SYSTICK/SYSTICK_Program.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"


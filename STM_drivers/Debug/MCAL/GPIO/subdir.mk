################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/GPIO/GPIO_Program.c 

OBJS += \
./MCAL/GPIO/GPIO_Program.o 

C_DEPS += \
./MCAL/GPIO/GPIO_Program.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/GPIO/GPIO_Program.o: ../MCAL/GPIO/GPIO_Program.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"MCAL/GPIO/GPIO_Program.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"


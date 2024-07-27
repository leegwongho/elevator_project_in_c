################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../App/hw/device/button.c \
../App/hw/device/buzz.c \
../App/hw/device/delay.c \
../App/hw/device/led.c \
../App/hw/device/stepper.c \
../App/hw/device/uart.c 

OBJS += \
./App/hw/device/button.o \
./App/hw/device/buzz.o \
./App/hw/device/delay.o \
./App/hw/device/led.o \
./App/hw/device/stepper.o \
./App/hw/device/uart.o 

C_DEPS += \
./App/hw/device/button.d \
./App/hw/device/buzz.d \
./App/hw/device/delay.d \
./App/hw/device/led.d \
./App/hw/device/stepper.d \
./App/hw/device/uart.d 


# Each subdirectory must supply rules for building sources it contributes
App/hw/device/%.o App/hw/device/%.su App/hw/device/%.cyclo: ../App/hw/device/%.c App/hw/device/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"D:/PARKJIHOON/STM32/STM32F411/App" -I"D:/PARKJIHOON/STM32/STM32F411/App/common" -I"D:/PARKJIHOON/STM32/STM32F411/App/hw" -I"D:/PARKJIHOON/STM32/STM32F411/App/hw/device" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-App-2f-hw-2f-device

clean-App-2f-hw-2f-device:
	-$(RM) ./App/hw/device/button.cyclo ./App/hw/device/button.d ./App/hw/device/button.o ./App/hw/device/button.su ./App/hw/device/buzz.cyclo ./App/hw/device/buzz.d ./App/hw/device/buzz.o ./App/hw/device/buzz.su ./App/hw/device/delay.cyclo ./App/hw/device/delay.d ./App/hw/device/delay.o ./App/hw/device/delay.su ./App/hw/device/led.cyclo ./App/hw/device/led.d ./App/hw/device/led.o ./App/hw/device/led.su ./App/hw/device/stepper.cyclo ./App/hw/device/stepper.d ./App/hw/device/stepper.o ./App/hw/device/stepper.su ./App/hw/device/uart.cyclo ./App/hw/device/uart.d ./App/hw/device/uart.o ./App/hw/device/uart.su

.PHONY: clean-App-2f-hw-2f-device


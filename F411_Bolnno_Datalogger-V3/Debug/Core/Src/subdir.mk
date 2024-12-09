################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/ADC.c \
../Core/Src/Accelerometer.c \
../Core/Src/Data.c \
../Core/Src/GPIO.c \
../Core/Src/HTML_Code.c \
../Core/Src/I2C.c \
../Core/Src/ISR.c \
../Core/Src/NTC.c \
../Core/Src/Pressure_Sensor.c \
../Core/Src/SDIO.c \
../Core/Src/SD_Card.c \
../Core/Src/Timer.c \
../Core/Src/UART.c \
../Core/Src/Ultrasonic.c \
../Core/Src/Water_Resistance.c \
../Core/Src/main.c \
../Core/Src/stm32f4xx_hal_msp.c \
../Core/Src/stm32f4xx_it.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32f4xx.c 

OBJS += \
./Core/Src/ADC.o \
./Core/Src/Accelerometer.o \
./Core/Src/Data.o \
./Core/Src/GPIO.o \
./Core/Src/HTML_Code.o \
./Core/Src/I2C.o \
./Core/Src/ISR.o \
./Core/Src/NTC.o \
./Core/Src/Pressure_Sensor.o \
./Core/Src/SDIO.o \
./Core/Src/SD_Card.o \
./Core/Src/Timer.o \
./Core/Src/UART.o \
./Core/Src/Ultrasonic.o \
./Core/Src/Water_Resistance.o \
./Core/Src/main.o \
./Core/Src/stm32f4xx_hal_msp.o \
./Core/Src/stm32f4xx_it.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32f4xx.o 

C_DEPS += \
./Core/Src/ADC.d \
./Core/Src/Accelerometer.d \
./Core/Src/Data.d \
./Core/Src/GPIO.d \
./Core/Src/HTML_Code.d \
./Core/Src/I2C.d \
./Core/Src/ISR.d \
./Core/Src/NTC.d \
./Core/Src/Pressure_Sensor.d \
./Core/Src/SDIO.d \
./Core/Src/SD_Card.d \
./Core/Src/Timer.d \
./Core/Src/UART.d \
./Core/Src/Ultrasonic.d \
./Core/Src/Water_Resistance.d \
./Core/Src/main.d \
./Core/Src/stm32f4xx_hal_msp.d \
./Core/Src/stm32f4xx_it.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32f4xx.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o Core/Src/%.su Core/Src/%.cyclo: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/ADC.cyclo ./Core/Src/ADC.d ./Core/Src/ADC.o ./Core/Src/ADC.su ./Core/Src/Accelerometer.cyclo ./Core/Src/Accelerometer.d ./Core/Src/Accelerometer.o ./Core/Src/Accelerometer.su ./Core/Src/Data.cyclo ./Core/Src/Data.d ./Core/Src/Data.o ./Core/Src/Data.su ./Core/Src/GPIO.cyclo ./Core/Src/GPIO.d ./Core/Src/GPIO.o ./Core/Src/GPIO.su ./Core/Src/HTML_Code.cyclo ./Core/Src/HTML_Code.d ./Core/Src/HTML_Code.o ./Core/Src/HTML_Code.su ./Core/Src/I2C.cyclo ./Core/Src/I2C.d ./Core/Src/I2C.o ./Core/Src/I2C.su ./Core/Src/ISR.cyclo ./Core/Src/ISR.d ./Core/Src/ISR.o ./Core/Src/ISR.su ./Core/Src/NTC.cyclo ./Core/Src/NTC.d ./Core/Src/NTC.o ./Core/Src/NTC.su ./Core/Src/Pressure_Sensor.cyclo ./Core/Src/Pressure_Sensor.d ./Core/Src/Pressure_Sensor.o ./Core/Src/Pressure_Sensor.su ./Core/Src/SDIO.cyclo ./Core/Src/SDIO.d ./Core/Src/SDIO.o ./Core/Src/SDIO.su ./Core/Src/SD_Card.cyclo ./Core/Src/SD_Card.d ./Core/Src/SD_Card.o ./Core/Src/SD_Card.su ./Core/Src/Timer.cyclo ./Core/Src/Timer.d ./Core/Src/Timer.o ./Core/Src/Timer.su ./Core/Src/UART.cyclo ./Core/Src/UART.d ./Core/Src/UART.o ./Core/Src/UART.su ./Core/Src/Ultrasonic.cyclo ./Core/Src/Ultrasonic.d ./Core/Src/Ultrasonic.o ./Core/Src/Ultrasonic.su ./Core/Src/Water_Resistance.cyclo ./Core/Src/Water_Resistance.d ./Core/Src/Water_Resistance.o ./Core/Src/Water_Resistance.su ./Core/Src/main.cyclo ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/main.su ./Core/Src/stm32f4xx_hal_msp.cyclo ./Core/Src/stm32f4xx_hal_msp.d ./Core/Src/stm32f4xx_hal_msp.o ./Core/Src/stm32f4xx_hal_msp.su ./Core/Src/stm32f4xx_it.cyclo ./Core/Src/stm32f4xx_it.d ./Core/Src/stm32f4xx_it.o ./Core/Src/stm32f4xx_it.su ./Core/Src/syscalls.cyclo ./Core/Src/syscalls.d ./Core/Src/syscalls.o ./Core/Src/syscalls.su ./Core/Src/sysmem.cyclo ./Core/Src/sysmem.d ./Core/Src/sysmem.o ./Core/Src/sysmem.su ./Core/Src/system_stm32f4xx.cyclo ./Core/Src/system_stm32f4xx.d ./Core/Src/system_stm32f4xx.o ./Core/Src/system_stm32f4xx.su

.PHONY: clean-Core-2f-Src


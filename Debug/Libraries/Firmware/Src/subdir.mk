################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Libraries/Firmware/Src/Beep_pwm.c \
../Libraries/Firmware/Src/Button_gpio.c \
../Libraries/Firmware/Src/Led_gpio.c \
../Libraries/Firmware/Src/Oled_sh1106_i2c.c \
../Libraries/Firmware/Src/Rtc_ds1307_i2c.c 

OBJS += \
./Libraries/Firmware/Src/Beep_pwm.o \
./Libraries/Firmware/Src/Button_gpio.o \
./Libraries/Firmware/Src/Led_gpio.o \
./Libraries/Firmware/Src/Oled_sh1106_i2c.o \
./Libraries/Firmware/Src/Rtc_ds1307_i2c.o 

C_DEPS += \
./Libraries/Firmware/Src/Beep_pwm.d \
./Libraries/Firmware/Src/Button_gpio.d \
./Libraries/Firmware/Src/Led_gpio.d \
./Libraries/Firmware/Src/Oled_sh1106_i2c.d \
./Libraries/Firmware/Src/Rtc_ds1307_i2c.d 


# Each subdirectory must supply rules for building sources it contributes
Libraries/Firmware/Src/%.o Libraries/Firmware/Src/%.su Libraries/Firmware/Src/%.cyclo: ../Libraries/Firmware/Src/%.c Libraries/Firmware/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../Libraries/Firmware/Inc -I../Libraries/Application/Inc -I../Libraries/Application/Img -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Libraries-2f-Firmware-2f-Src

clean-Libraries-2f-Firmware-2f-Src:
	-$(RM) ./Libraries/Firmware/Src/Beep_pwm.cyclo ./Libraries/Firmware/Src/Beep_pwm.d ./Libraries/Firmware/Src/Beep_pwm.o ./Libraries/Firmware/Src/Beep_pwm.su ./Libraries/Firmware/Src/Button_gpio.cyclo ./Libraries/Firmware/Src/Button_gpio.d ./Libraries/Firmware/Src/Button_gpio.o ./Libraries/Firmware/Src/Button_gpio.su ./Libraries/Firmware/Src/Led_gpio.cyclo ./Libraries/Firmware/Src/Led_gpio.d ./Libraries/Firmware/Src/Led_gpio.o ./Libraries/Firmware/Src/Led_gpio.su ./Libraries/Firmware/Src/Oled_sh1106_i2c.cyclo ./Libraries/Firmware/Src/Oled_sh1106_i2c.d ./Libraries/Firmware/Src/Oled_sh1106_i2c.o ./Libraries/Firmware/Src/Oled_sh1106_i2c.su ./Libraries/Firmware/Src/Rtc_ds1307_i2c.cyclo ./Libraries/Firmware/Src/Rtc_ds1307_i2c.d ./Libraries/Firmware/Src/Rtc_ds1307_i2c.o ./Libraries/Firmware/Src/Rtc_ds1307_i2c.su

.PHONY: clean-Libraries-2f-Firmware-2f-Src


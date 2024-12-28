################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Libraries/Application/Src/Controller/AlarmCtrl.c \
../Libraries/Application/Src/Controller/IdlingCtrl.c \
../Libraries/Application/Src/Controller/MenuCtrl.c \
../Libraries/Application/Src/Controller/StateCtrl.c 

OBJS += \
./Libraries/Application/Src/Controller/AlarmCtrl.o \
./Libraries/Application/Src/Controller/IdlingCtrl.o \
./Libraries/Application/Src/Controller/MenuCtrl.o \
./Libraries/Application/Src/Controller/StateCtrl.o 

C_DEPS += \
./Libraries/Application/Src/Controller/AlarmCtrl.d \
./Libraries/Application/Src/Controller/IdlingCtrl.d \
./Libraries/Application/Src/Controller/MenuCtrl.d \
./Libraries/Application/Src/Controller/StateCtrl.d 


# Each subdirectory must supply rules for building sources it contributes
Libraries/Application/Src/Controller/%.o Libraries/Application/Src/Controller/%.su Libraries/Application/Src/Controller/%.cyclo: ../Libraries/Application/Src/Controller/%.c Libraries/Application/Src/Controller/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../Libraries/Firmware/Inc -I../Libraries/Application/Inc -I../Libraries/Application/Img -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Libraries-2f-Application-2f-Src-2f-Controller

clean-Libraries-2f-Application-2f-Src-2f-Controller:
	-$(RM) ./Libraries/Application/Src/Controller/AlarmCtrl.cyclo ./Libraries/Application/Src/Controller/AlarmCtrl.d ./Libraries/Application/Src/Controller/AlarmCtrl.o ./Libraries/Application/Src/Controller/AlarmCtrl.su ./Libraries/Application/Src/Controller/IdlingCtrl.cyclo ./Libraries/Application/Src/Controller/IdlingCtrl.d ./Libraries/Application/Src/Controller/IdlingCtrl.o ./Libraries/Application/Src/Controller/IdlingCtrl.su ./Libraries/Application/Src/Controller/MenuCtrl.cyclo ./Libraries/Application/Src/Controller/MenuCtrl.d ./Libraries/Application/Src/Controller/MenuCtrl.o ./Libraries/Application/Src/Controller/MenuCtrl.su ./Libraries/Application/Src/Controller/StateCtrl.cyclo ./Libraries/Application/Src/Controller/StateCtrl.d ./Libraries/Application/Src/Controller/StateCtrl.o ./Libraries/Application/Src/Controller/StateCtrl.su

.PHONY: clean-Libraries-2f-Application-2f-Src-2f-Controller


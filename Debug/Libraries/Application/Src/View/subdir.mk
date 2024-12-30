################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Libraries/Application/Src/View/AlarmView.c \
../Libraries/Application/Src/View/CounterView.c \
../Libraries/Application/Src/View/FlashView.c \
../Libraries/Application/Src/View/GeneralDisplay.c \
../Libraries/Application/Src/View/IdlingView.c \
../Libraries/Application/Src/View/MenuView.c 

OBJS += \
./Libraries/Application/Src/View/AlarmView.o \
./Libraries/Application/Src/View/CounterView.o \
./Libraries/Application/Src/View/FlashView.o \
./Libraries/Application/Src/View/GeneralDisplay.o \
./Libraries/Application/Src/View/IdlingView.o \
./Libraries/Application/Src/View/MenuView.o 

C_DEPS += \
./Libraries/Application/Src/View/AlarmView.d \
./Libraries/Application/Src/View/CounterView.d \
./Libraries/Application/Src/View/FlashView.d \
./Libraries/Application/Src/View/GeneralDisplay.d \
./Libraries/Application/Src/View/IdlingView.d \
./Libraries/Application/Src/View/MenuView.d 


# Each subdirectory must supply rules for building sources it contributes
Libraries/Application/Src/View/%.o Libraries/Application/Src/View/%.su Libraries/Application/Src/View/%.cyclo: ../Libraries/Application/Src/View/%.c Libraries/Application/Src/View/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../Libraries/Firmware/Inc -I../Libraries/Application/Inc -I../Libraries/Application/Img -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Libraries-2f-Application-2f-Src-2f-View

clean-Libraries-2f-Application-2f-Src-2f-View:
	-$(RM) ./Libraries/Application/Src/View/AlarmView.cyclo ./Libraries/Application/Src/View/AlarmView.d ./Libraries/Application/Src/View/AlarmView.o ./Libraries/Application/Src/View/AlarmView.su ./Libraries/Application/Src/View/CounterView.cyclo ./Libraries/Application/Src/View/CounterView.d ./Libraries/Application/Src/View/CounterView.o ./Libraries/Application/Src/View/CounterView.su ./Libraries/Application/Src/View/FlashView.cyclo ./Libraries/Application/Src/View/FlashView.d ./Libraries/Application/Src/View/FlashView.o ./Libraries/Application/Src/View/FlashView.su ./Libraries/Application/Src/View/GeneralDisplay.cyclo ./Libraries/Application/Src/View/GeneralDisplay.d ./Libraries/Application/Src/View/GeneralDisplay.o ./Libraries/Application/Src/View/GeneralDisplay.su ./Libraries/Application/Src/View/IdlingView.cyclo ./Libraries/Application/Src/View/IdlingView.d ./Libraries/Application/Src/View/IdlingView.o ./Libraries/Application/Src/View/IdlingView.su ./Libraries/Application/Src/View/MenuView.cyclo ./Libraries/Application/Src/View/MenuView.d ./Libraries/Application/Src/View/MenuView.o ./Libraries/Application/Src/View/MenuView.su

.PHONY: clean-Libraries-2f-Application-2f-Src-2f-View


################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Libraries/Application/Src/GeneralUtilities.c \
../Libraries/Application/Src/ScreenUtilities.c 

OBJS += \
./Libraries/Application/Src/GeneralUtilities.o \
./Libraries/Application/Src/ScreenUtilities.o 

C_DEPS += \
./Libraries/Application/Src/GeneralUtilities.d \
./Libraries/Application/Src/ScreenUtilities.d 


# Each subdirectory must supply rules for building sources it contributes
Libraries/Application/Src/%.o Libraries/Application/Src/%.su Libraries/Application/Src/%.cyclo: ../Libraries/Application/Src/%.c Libraries/Application/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../Libraries/Firmware/Inc -I../Libraries/Application/Inc -I../Libraries/Application/Img -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Libraries-2f-Application-2f-Src

clean-Libraries-2f-Application-2f-Src:
	-$(RM) ./Libraries/Application/Src/GeneralUtilities.cyclo ./Libraries/Application/Src/GeneralUtilities.d ./Libraries/Application/Src/GeneralUtilities.o ./Libraries/Application/Src/GeneralUtilities.su ./Libraries/Application/Src/ScreenUtilities.cyclo ./Libraries/Application/Src/ScreenUtilities.d ./Libraries/Application/Src/ScreenUtilities.o ./Libraries/Application/Src/ScreenUtilities.su

.PHONY: clean-Libraries-2f-Application-2f-Src


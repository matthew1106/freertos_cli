################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/Third_Party/TraceRecorder/streamports/Jlink_RTT/SEGGER_RTT.c \
../Middlewares/Third_Party/TraceRecorder/streamports/Jlink_RTT/trcStreamingPort.c 

OBJS += \
./Middlewares/Third_Party/TraceRecorder/streamports/Jlink_RTT/SEGGER_RTT.o \
./Middlewares/Third_Party/TraceRecorder/streamports/Jlink_RTT/trcStreamingPort.o 

C_DEPS += \
./Middlewares/Third_Party/TraceRecorder/streamports/Jlink_RTT/SEGGER_RTT.d \
./Middlewares/Third_Party/TraceRecorder/streamports/Jlink_RTT/trcStreamingPort.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/Third_Party/TraceRecorder/streamports/Jlink_RTT/%.o Middlewares/Third_Party/TraceRecorder/streamports/Jlink_RTT/%.su Middlewares/Third_Party/TraceRecorder/streamports/Jlink_RTT/%.cyclo: ../Middlewares/Third_Party/TraceRecorder/streamports/Jlink_RTT/%.c Middlewares/Third_Party/TraceRecorder/streamports/Jlink_RTT/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F412Rx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/TraceRecorder/streamports/Jlink_RTT/include -I../Middlewares/Third_Party/TraceRecorder/include -I../Middlewares/Third_Party/TraceRecorder/config -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Middlewares-2f-Third_Party-2f-TraceRecorder-2f-streamports-2f-Jlink_RTT

clean-Middlewares-2f-Third_Party-2f-TraceRecorder-2f-streamports-2f-Jlink_RTT:
	-$(RM) ./Middlewares/Third_Party/TraceRecorder/streamports/Jlink_RTT/SEGGER_RTT.cyclo ./Middlewares/Third_Party/TraceRecorder/streamports/Jlink_RTT/SEGGER_RTT.d ./Middlewares/Third_Party/TraceRecorder/streamports/Jlink_RTT/SEGGER_RTT.o ./Middlewares/Third_Party/TraceRecorder/streamports/Jlink_RTT/SEGGER_RTT.su ./Middlewares/Third_Party/TraceRecorder/streamports/Jlink_RTT/trcStreamingPort.cyclo ./Middlewares/Third_Party/TraceRecorder/streamports/Jlink_RTT/trcStreamingPort.d ./Middlewares/Third_Party/TraceRecorder/streamports/Jlink_RTT/trcStreamingPort.o ./Middlewares/Third_Party/TraceRecorder/streamports/Jlink_RTT/trcStreamingPort.su

.PHONY: clean-Middlewares-2f-Third_Party-2f-TraceRecorder-2f-streamports-2f-Jlink_RTT


################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../component/serial_manager/fsl_component_serial_manager.c \
../component/serial_manager/fsl_component_serial_port_uart.c 

OBJS += \
./component/serial_manager/fsl_component_serial_manager.o \
./component/serial_manager/fsl_component_serial_port_uart.o 

C_DEPS += \
./component/serial_manager/fsl_component_serial_manager.d \
./component/serial_manager/fsl_component_serial_port_uart.d 


# Each subdirectory must supply rules for building sources it contributes
component/serial_manager/%.o: ../component/serial_manager/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__NEWLIB__ -DCPU_LPC55S69JBD100 -DCPU_LPC55S69JBD100_cm33 -DCPU_LPC55S69JBD100_cm33_core0 -DFSL_RTOS_BM -DSDK_OS_BAREMETAL -DSERIAL_PORT_TYPE_UART=1 -DSDK_DEBUGCONSOLE=1 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I"C:\Users\kkorn\Documents\MCUXpressoIDE_11.3.1_5262\workspace\arducam-test\board" -I"C:\Users\kkorn\Documents\MCUXpressoIDE_11.3.1_5262\workspace\arducam-test\source" -I"C:\Users\kkorn\Documents\MCUXpressoIDE_11.3.1_5262\workspace\arducam-test\drivers" -I"C:\Users\kkorn\Documents\MCUXpressoIDE_11.3.1_5262\workspace\arducam-test\LPC55S69\drivers" -I"C:\Users\kkorn\Documents\MCUXpressoIDE_11.3.1_5262\workspace\arducam-test\utilities" -I"C:\Users\kkorn\Documents\MCUXpressoIDE_11.3.1_5262\workspace\arducam-test\component\uart" -I"C:\Users\kkorn\Documents\MCUXpressoIDE_11.3.1_5262\workspace\arducam-test\component\serial_manager" -I"C:\Users\kkorn\Documents\MCUXpressoIDE_11.3.1_5262\workspace\arducam-test\component\lists" -I"C:\Users\kkorn\Documents\MCUXpressoIDE_11.3.1_5262\workspace\arducam-test\startup" -I"C:\Users\kkorn\Documents\MCUXpressoIDE_11.3.1_5262\workspace\arducam-test\CMSIS" -I"C:\Users\kkorn\Documents\MCUXpressoIDE_11.3.1_5262\workspace\arducam-test\device" -O0 -fno-common -g3 -Wall -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmerge-constants -fmacro-prefix-map="../$(@D)/"=. -mcpu=cortex-m33 -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -D__NEWLIB__ -fstack-usage -specs=nano.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



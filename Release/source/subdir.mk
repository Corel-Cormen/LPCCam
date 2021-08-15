################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../source/arducam-test.cpp \
../source/cpp_config.cpp 

C_SRCS += \
../source/semihost_hardfault.c 

OBJS += \
./source/arducam-test.o \
./source/cpp_config.o \
./source/semihost_hardfault.o 

CPP_DEPS += \
./source/arducam-test.d \
./source/cpp_config.d 

C_DEPS += \
./source/semihost_hardfault.d 


# Each subdirectory must supply rules for building sources it contributes
source/%.o: ../source/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C++ Compiler'
	arm-none-eabi-c++ -DCPU_LPC55S69JBD100 -DCPU_LPC55S69JBD100_cm33 -DCPU_LPC55S69JBD100_cm33_core0 -DFSL_RTOS_BM -DSDK_OS_BAREMETAL -DSERIAL_PORT_TYPE_UART=1 -DSDK_DEBUGCONSOLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DNDEBUG -D__NEWLIB__ -I"C:\Users\kornel\Documents\MCUXpressoIDE_11.3.0_5222\workspace\arducam-test\board" -I"C:\Users\kornel\Documents\MCUXpressoIDE_11.3.0_5222\workspace\arducam-test\source" -I"C:\Users\kornel\Documents\MCUXpressoIDE_11.3.0_5222\workspace\arducam-test\drivers" -I"C:\Users\kornel\Documents\MCUXpressoIDE_11.3.0_5222\workspace\arducam-test\LPC55S69\drivers" -I"C:\Users\kornel\Documents\MCUXpressoIDE_11.3.0_5222\workspace\arducam-test\utilities" -I"C:\Users\kornel\Documents\MCUXpressoIDE_11.3.0_5222\workspace\arducam-test\component\uart" -I"C:\Users\kornel\Documents\MCUXpressoIDE_11.3.0_5222\workspace\arducam-test\component\serial_manager" -I"C:\Users\kornel\Documents\MCUXpressoIDE_11.3.0_5222\workspace\arducam-test\component\lists" -I"C:\Users\kornel\Documents\MCUXpressoIDE_11.3.0_5222\workspace\arducam-test\startup" -I"C:\Users\kornel\Documents\MCUXpressoIDE_11.3.0_5222\workspace\arducam-test\CMSIS" -I"C:\Users\kornel\Documents\MCUXpressoIDE_11.3.0_5222\workspace\arducam-test\device" -Os -fno-common -g -Wall -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fno-rtti -fno-exceptions -fmacro-prefix-map="../$(@D)/"=. -mcpu=cortex-m33 -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -D__NEWLIB__ -fstack-usage -specs=nano.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

source/%.o: ../source/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DCPU_LPC55S69JBD100 -DCPU_LPC55S69JBD100_cm33 -DCPU_LPC55S69JBD100_cm33_core0 -DFSL_RTOS_BM -DSDK_OS_BAREMETAL -DSERIAL_PORT_TYPE_UART=1 -DSDK_DEBUGCONSOLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DNDEBUG -D__NEWLIB__ -I"C:\Users\kornel\Documents\MCUXpressoIDE_11.3.0_5222\workspace\arducam-test\board" -I"C:\Users\kornel\Documents\MCUXpressoIDE_11.3.0_5222\workspace\arducam-test\source" -I"C:\Users\kornel\Documents\MCUXpressoIDE_11.3.0_5222\workspace\arducam-test\drivers" -I"C:\Users\kornel\Documents\MCUXpressoIDE_11.3.0_5222\workspace\arducam-test\LPC55S69\drivers" -I"C:\Users\kornel\Documents\MCUXpressoIDE_11.3.0_5222\workspace\arducam-test\utilities" -I"C:\Users\kornel\Documents\MCUXpressoIDE_11.3.0_5222\workspace\arducam-test\component\uart" -I"C:\Users\kornel\Documents\MCUXpressoIDE_11.3.0_5222\workspace\arducam-test\component\serial_manager" -I"C:\Users\kornel\Documents\MCUXpressoIDE_11.3.0_5222\workspace\arducam-test\component\lists" -I"C:\Users\kornel\Documents\MCUXpressoIDE_11.3.0_5222\workspace\arducam-test\startup" -I"C:\Users\kornel\Documents\MCUXpressoIDE_11.3.0_5222\workspace\arducam-test\CMSIS" -I"C:\Users\kornel\Documents\MCUXpressoIDE_11.3.0_5222\workspace\arducam-test\device" -Os -fno-common -g -Wall -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmacro-prefix-map="../$(@D)/"=. -mcpu=cortex-m33 -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -D__NEWLIB__ -fstack-usage -specs=nano.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



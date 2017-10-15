################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Generated_Code/ASerialLdd1.c \
../Generated_Code/ASerialLdd2.c \
../Generated_Code/BLUE.c \
../Generated_Code/BitIoLdd1.c \
../Generated_Code/BitIoLdd2.c \
../Generated_Code/BitIoLdd3.c \
../Generated_Code/BitIoLdd4.c \
../Generated_Code/BitIoLdd5.c \
../Generated_Code/CRC1.c \
../Generated_Code/Cpu.c \
../Generated_Code/IntFlashLdd1.c \
../Generated_Code/LED.c \
../Generated_Code/MQX1.c \
../Generated_Code/PE_LDD.c \
../Generated_Code/SM1.c \
../Generated_Code/SystemTimer1.c \
../Generated_Code/UART_DEBUG.c \
../Generated_Code/blue_at.c \
../Generated_Code/blue_delay.c \
../Generated_Code/blue_pwrc.c \
../Generated_Code/flash.c \
../Generated_Code/led_output.c 

OBJS += \
./Generated_Code/ASerialLdd1.o \
./Generated_Code/ASerialLdd2.o \
./Generated_Code/BLUE.o \
./Generated_Code/BitIoLdd1.o \
./Generated_Code/BitIoLdd2.o \
./Generated_Code/BitIoLdd3.o \
./Generated_Code/BitIoLdd4.o \
./Generated_Code/BitIoLdd5.o \
./Generated_Code/CRC1.o \
./Generated_Code/Cpu.o \
./Generated_Code/IntFlashLdd1.o \
./Generated_Code/LED.o \
./Generated_Code/MQX1.o \
./Generated_Code/PE_LDD.o \
./Generated_Code/SM1.o \
./Generated_Code/SystemTimer1.o \
./Generated_Code/UART_DEBUG.o \
./Generated_Code/blue_at.o \
./Generated_Code/blue_delay.o \
./Generated_Code/blue_pwrc.o \
./Generated_Code/flash.o \
./Generated_Code/led_output.o 

C_DEPS += \
./Generated_Code/ASerialLdd1.d \
./Generated_Code/ASerialLdd2.d \
./Generated_Code/BLUE.d \
./Generated_Code/BitIoLdd1.d \
./Generated_Code/BitIoLdd2.d \
./Generated_Code/BitIoLdd3.d \
./Generated_Code/BitIoLdd4.d \
./Generated_Code/BitIoLdd5.d \
./Generated_Code/CRC1.d \
./Generated_Code/Cpu.d \
./Generated_Code/IntFlashLdd1.d \
./Generated_Code/LED.d \
./Generated_Code/MQX1.d \
./Generated_Code/PE_LDD.d \
./Generated_Code/SM1.d \
./Generated_Code/SystemTimer1.d \
./Generated_Code/UART_DEBUG.d \
./Generated_Code/blue_at.d \
./Generated_Code/blue_delay.d \
./Generated_Code/blue_pwrc.d \
./Generated_Code/flash.d \
./Generated_Code/led_output.d 


# Each subdirectory must supply rules for building sources it contributes
Generated_Code/%.o: ../Generated_Code/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"/home/xiuxiu/workspace.kds/piproject/Static_Code/System" -I"/home/xiuxiu/workspace.kds/piproject/Sources/dev" -I"/home/xiuxiu/workspace.kds/piproject/Sources/tasks" -I"/home/xiuxiu/workspace.kds/piproject/Static_Code/PDD" -I"/home/xiuxiu/workspace.kds/piproject/Static_Code/IO_Map" -I"/opt/Freescale/KDS_v3/eclipse/ProcessorExpert/lib/Kinetis/pdd/inc" -I"/home/xiuxiu/workspace.kds/piproject/Sources" -I"/home/xiuxiu/workspace.kds/piproject/Generated_Code" -I"/home/xiuxiu/workspace.kds/piproject/MQXLITE/include" -I"/home/xiuxiu/workspace.kds/piproject/MQXLITE/config" -I"/home/xiuxiu/workspace.kds/piproject/MQXLITE/kernel" -I"/home/xiuxiu/workspace.kds/piproject/MQXLITE/psp/cortex_m" -I"/home/xiuxiu/workspace.kds/piproject/MQXLITE/psp/cortex_m/core/M0" -I"/home/xiuxiu/workspace.kds/piproject/MQXLITE/psp/cortex_m/compiler/cwgcc" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



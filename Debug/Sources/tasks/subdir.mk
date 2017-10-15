################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/tasks/cmd.c \
../Sources/tasks/decoder.c \
../Sources/tasks/led_run.c \
../Sources/tasks/spi_output.c \
../Sources/tasks/uart.c 

OBJS += \
./Sources/tasks/cmd.o \
./Sources/tasks/decoder.o \
./Sources/tasks/led_run.o \
./Sources/tasks/spi_output.o \
./Sources/tasks/uart.o 

C_DEPS += \
./Sources/tasks/cmd.d \
./Sources/tasks/decoder.d \
./Sources/tasks/led_run.d \
./Sources/tasks/spi_output.d \
./Sources/tasks/uart.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/tasks/%.o: ../Sources/tasks/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"/home/xiuxiu/workspace.kds/piproject/Static_Code/System" -I"/home/xiuxiu/workspace.kds/piproject/Sources/dev" -I"/home/xiuxiu/workspace.kds/piproject/Sources/tasks" -I"/home/xiuxiu/workspace.kds/piproject/Static_Code/PDD" -I"/home/xiuxiu/workspace.kds/piproject/Static_Code/IO_Map" -I"/opt/Freescale/KDS_v3/eclipse/ProcessorExpert/lib/Kinetis/pdd/inc" -I"/home/xiuxiu/workspace.kds/piproject/Sources" -I"/home/xiuxiu/workspace.kds/piproject/Generated_Code" -I"/home/xiuxiu/workspace.kds/piproject/MQXLITE/include" -I"/home/xiuxiu/workspace.kds/piproject/MQXLITE/config" -I"/home/xiuxiu/workspace.kds/piproject/MQXLITE/kernel" -I"/home/xiuxiu/workspace.kds/piproject/MQXLITE/psp/cortex_m" -I"/home/xiuxiu/workspace.kds/piproject/MQXLITE/psp/cortex_m/core/M0" -I"/home/xiuxiu/workspace.kds/piproject/MQXLITE/psp/cortex_m/compiler/cwgcc" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



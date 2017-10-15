################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Static_Code/System/CPU_Init.c \
../Static_Code/System/Peripherals_Init.c \
../Static_Code/System/Vectors.c 

OBJS += \
./Static_Code/System/CPU_Init.o \
./Static_Code/System/Peripherals_Init.o \
./Static_Code/System/Vectors.o 

C_DEPS += \
./Static_Code/System/CPU_Init.d \
./Static_Code/System/Peripherals_Init.d \
./Static_Code/System/Vectors.d 


# Each subdirectory must supply rules for building sources it contributes
Static_Code/System/%.o: ../Static_Code/System/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"/home/xiuxiu/workspace.kds/piproject/Static_Code/System" -I"/home/xiuxiu/workspace.kds/piproject/Sources/dev" -I"/home/xiuxiu/workspace.kds/piproject/Sources/tasks" -I"/home/xiuxiu/workspace.kds/piproject/Static_Code/PDD" -I"/home/xiuxiu/workspace.kds/piproject/Static_Code/IO_Map" -I"/opt/Freescale/KDS_v3/eclipse/ProcessorExpert/lib/Kinetis/pdd/inc" -I"/home/xiuxiu/workspace.kds/piproject/Sources" -I"/home/xiuxiu/workspace.kds/piproject/Generated_Code" -I"/home/xiuxiu/workspace.kds/piproject/MQXLITE/include" -I"/home/xiuxiu/workspace.kds/piproject/MQXLITE/config" -I"/home/xiuxiu/workspace.kds/piproject/MQXLITE/kernel" -I"/home/xiuxiu/workspace.kds/piproject/MQXLITE/psp/cortex_m" -I"/home/xiuxiu/workspace.kds/piproject/MQXLITE/psp/cortex_m/core/M0" -I"/home/xiuxiu/workspace.kds/piproject/MQXLITE/psp/cortex_m/compiler/cwgcc" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



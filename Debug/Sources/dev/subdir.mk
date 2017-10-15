################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/dev/print.c 

OBJS += \
./Sources/dev/print.o 

C_DEPS += \
./Sources/dev/print.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/dev/%.o: ../Sources/dev/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"/home/xiuxiu/workspace.kds/piproject/Static_Code/System" -I"/home/xiuxiu/workspace.kds/piproject/Sources/dev" -I"/home/xiuxiu/workspace.kds/piproject/Sources/tasks" -I"/home/xiuxiu/workspace.kds/piproject/Static_Code/PDD" -I"/home/xiuxiu/workspace.kds/piproject/Static_Code/IO_Map" -I"/opt/Freescale/KDS_v3/eclipse/ProcessorExpert/lib/Kinetis/pdd/inc" -I"/home/xiuxiu/workspace.kds/piproject/Sources" -I"/home/xiuxiu/workspace.kds/piproject/Generated_Code" -I"/home/xiuxiu/workspace.kds/piproject/MQXLITE/include" -I"/home/xiuxiu/workspace.kds/piproject/MQXLITE/config" -I"/home/xiuxiu/workspace.kds/piproject/MQXLITE/kernel" -I"/home/xiuxiu/workspace.kds/piproject/MQXLITE/psp/cortex_m" -I"/home/xiuxiu/workspace.kds/piproject/MQXLITE/psp/cortex_m/core/M0" -I"/home/xiuxiu/workspace.kds/piproject/MQXLITE/psp/cortex_m/compiler/cwgcc" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



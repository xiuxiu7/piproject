################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MQXLITE/psp/cortex_m/cortex.c \
../MQXLITE/psp/cortex_m/int_gkis.c \
../MQXLITE/psp/cortex_m/int_inst.c \
../MQXLITE/psp/cortex_m/int_kisr.c \
../MQXLITE/psp/cortex_m/int_pvta.c \
../MQXLITE/psp/cortex_m/int_unx.c \
../MQXLITE/psp/cortex_m/int_vtab.c \
../MQXLITE/psp/cortex_m/int_xcpt.c \
../MQXLITE/psp/cortex_m/mem_zero.c \
../MQXLITE/psp/cortex_m/psp_iinit.c \
../MQXLITE/psp/cortex_m/psp_supp.c \
../MQXLITE/psp/cortex_m/psp_tiad.c \
../MQXLITE/psp/cortex_m/psp_tinm.c \
../MQXLITE/psp/cortex_m/psp_tipr.c \
../MQXLITE/psp/cortex_m/psp_tisu.c \
../MQXLITE/psp/cortex_m/sc_irdyq.c \
../MQXLITE/psp/cortex_m/stack_bu.c \
../MQXLITE/psp/cortex_m/stack_de.c \
../MQXLITE/psp/cortex_m/stack_st.c 

OBJS += \
./MQXLITE/psp/cortex_m/cortex.o \
./MQXLITE/psp/cortex_m/int_gkis.o \
./MQXLITE/psp/cortex_m/int_inst.o \
./MQXLITE/psp/cortex_m/int_kisr.o \
./MQXLITE/psp/cortex_m/int_pvta.o \
./MQXLITE/psp/cortex_m/int_unx.o \
./MQXLITE/psp/cortex_m/int_vtab.o \
./MQXLITE/psp/cortex_m/int_xcpt.o \
./MQXLITE/psp/cortex_m/mem_zero.o \
./MQXLITE/psp/cortex_m/psp_iinit.o \
./MQXLITE/psp/cortex_m/psp_supp.o \
./MQXLITE/psp/cortex_m/psp_tiad.o \
./MQXLITE/psp/cortex_m/psp_tinm.o \
./MQXLITE/psp/cortex_m/psp_tipr.o \
./MQXLITE/psp/cortex_m/psp_tisu.o \
./MQXLITE/psp/cortex_m/sc_irdyq.o \
./MQXLITE/psp/cortex_m/stack_bu.o \
./MQXLITE/psp/cortex_m/stack_de.o \
./MQXLITE/psp/cortex_m/stack_st.o 

C_DEPS += \
./MQXLITE/psp/cortex_m/cortex.d \
./MQXLITE/psp/cortex_m/int_gkis.d \
./MQXLITE/psp/cortex_m/int_inst.d \
./MQXLITE/psp/cortex_m/int_kisr.d \
./MQXLITE/psp/cortex_m/int_pvta.d \
./MQXLITE/psp/cortex_m/int_unx.d \
./MQXLITE/psp/cortex_m/int_vtab.d \
./MQXLITE/psp/cortex_m/int_xcpt.d \
./MQXLITE/psp/cortex_m/mem_zero.d \
./MQXLITE/psp/cortex_m/psp_iinit.d \
./MQXLITE/psp/cortex_m/psp_supp.d \
./MQXLITE/psp/cortex_m/psp_tiad.d \
./MQXLITE/psp/cortex_m/psp_tinm.d \
./MQXLITE/psp/cortex_m/psp_tipr.d \
./MQXLITE/psp/cortex_m/psp_tisu.d \
./MQXLITE/psp/cortex_m/sc_irdyq.d \
./MQXLITE/psp/cortex_m/stack_bu.d \
./MQXLITE/psp/cortex_m/stack_de.d \
./MQXLITE/psp/cortex_m/stack_st.d 


# Each subdirectory must supply rules for building sources it contributes
MQXLITE/psp/cortex_m/%.o: ../MQXLITE/psp/cortex_m/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"/home/xiuxiu/workspace.kds/piproject/Static_Code/System" -I"/home/xiuxiu/workspace.kds/piproject/Sources/dev" -I"/home/xiuxiu/workspace.kds/piproject/Sources/tasks" -I"/home/xiuxiu/workspace.kds/piproject/Static_Code/PDD" -I"/home/xiuxiu/workspace.kds/piproject/Static_Code/IO_Map" -I"/opt/Freescale/KDS_v3/eclipse/ProcessorExpert/lib/Kinetis/pdd/inc" -I"/home/xiuxiu/workspace.kds/piproject/Sources" -I"/home/xiuxiu/workspace.kds/piproject/Generated_Code" -I"/home/xiuxiu/workspace.kds/piproject/MQXLITE/include" -I"/home/xiuxiu/workspace.kds/piproject/MQXLITE/config" -I"/home/xiuxiu/workspace.kds/piproject/MQXLITE/kernel" -I"/home/xiuxiu/workspace.kds/piproject/MQXLITE/psp/cortex_m" -I"/home/xiuxiu/workspace.kds/piproject/MQXLITE/psp/cortex_m/core/M0" -I"/home/xiuxiu/workspace.kds/piproject/MQXLITE/psp/cortex_m/compiler/cwgcc" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



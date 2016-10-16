################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../L1_FreeRTOS/trace/run_time_counter.c \
../L1_FreeRTOS/trace/trcBase.c \
../L1_FreeRTOS/trace/trcHardwarePort.c \
../L1_FreeRTOS/trace/trcKernel.c \
../L1_FreeRTOS/trace/trcKernelPort.c \
../L1_FreeRTOS/trace/trcUser.c 

OBJS += \
./L1_FreeRTOS/trace/run_time_counter.o \
./L1_FreeRTOS/trace/trcBase.o \
./L1_FreeRTOS/trace/trcHardwarePort.o \
./L1_FreeRTOS/trace/trcKernel.o \
./L1_FreeRTOS/trace/trcKernelPort.o \
./L1_FreeRTOS/trace/trcUser.o 

C_DEPS += \
./L1_FreeRTOS/trace/run_time_counter.d \
./L1_FreeRTOS/trace/trcBase.d \
./L1_FreeRTOS/trace/trcHardwarePort.d \
./L1_FreeRTOS/trace/trcKernel.d \
./L1_FreeRTOS/trace/trcKernelPort.d \
./L1_FreeRTOS/trace/trcUser.d 


# Each subdirectory must supply rules for building sources it contributes
L1_FreeRTOS/trace/%.o: ../L1_FreeRTOS/trace/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -Os -fmessage-length=0 -ffunction-sections -fdata-sections -Wall -Wshadow -Wlogical-op -Wfloat-equal -DBUILD_CFG_MPU=0 -I"C:\SJSU_Dev\projects\CMPE243Project\Master" -I"C:\SJSU_Dev\projects\CMPE243Project\Master\newlib" -I"C:\SJSU_Dev\projects\CMPE243Project\Master\L0_LowLevel" -I"C:\SJSU_Dev\projects\CMPE243Project\Master\L1_FreeRTOS" -I"C:\SJSU_Dev\projects\CMPE243Project\Master\L1_FreeRTOS\include" -I"C:\SJSU_Dev\projects\CMPE243Project\Master\L1_FreeRTOS\portable\no_mpu" -I"C:\SJSU_Dev\projects\CMPE243Project\Master\L2_Drivers" -I"C:\SJSU_Dev\projects\CMPE243Project\Master\L2_Drivers\base" -I"C:\SJSU_Dev\projects\CMPE243Project\Master\L3_Utils" -I"C:\SJSU_Dev\projects\CMPE243Project\Master\L3_Utils\tlm" -I"C:\SJSU_Dev\projects\CMPE243Project\Master\L4_IO" -I"C:\SJSU_Dev\projects\CMPE243Project\Master\L4_IO\fat" -I"C:\SJSU_Dev\projects\CMPE243Project\Master\L4_IO\wireless" -I"C:\SJSU_Dev\projects\CMPE243Project\Master\L5_Application" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



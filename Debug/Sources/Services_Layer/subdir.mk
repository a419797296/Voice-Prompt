################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/Services_Layer/Bluetooth_bsp.c \
../Sources/Services_Layer/CAN_bsp.c \
../Sources/Services_Layer/System_logic.c \
../Sources/Services_Layer/logic_AutodDrvngInfoDspReq.c \
../Sources/Services_Layer/logic_com.c \
../Sources/Services_Layer/logic_fatigue.c \
../Sources/Services_Layer/logic_smart_deg.c \
../Sources/Services_Layer/logic_smart_drive.c \
../Sources/Services_Layer/logic_smart_in.c \
../Sources/Services_Layer/logic_speed.c \
../Sources/Services_Layer/logic_torque.c \
../Sources/Services_Layer/logic_voice.c \
../Sources/Services_Layer/time_base.c \
../Sources/Services_Layer/time_flash.c 

OBJS += \
./Sources/Services_Layer/Bluetooth_bsp.o \
./Sources/Services_Layer/CAN_bsp.o \
./Sources/Services_Layer/System_logic.o \
./Sources/Services_Layer/logic_AutodDrvngInfoDspReq.o \
./Sources/Services_Layer/logic_com.o \
./Sources/Services_Layer/logic_fatigue.o \
./Sources/Services_Layer/logic_smart_deg.o \
./Sources/Services_Layer/logic_smart_drive.o \
./Sources/Services_Layer/logic_smart_in.o \
./Sources/Services_Layer/logic_speed.o \
./Sources/Services_Layer/logic_torque.o \
./Sources/Services_Layer/logic_voice.o \
./Sources/Services_Layer/time_base.o \
./Sources/Services_Layer/time_flash.o 

C_DEPS += \
./Sources/Services_Layer/Bluetooth_bsp.d \
./Sources/Services_Layer/CAN_bsp.d \
./Sources/Services_Layer/System_logic.d \
./Sources/Services_Layer/logic_AutodDrvngInfoDspReq.d \
./Sources/Services_Layer/logic_com.d \
./Sources/Services_Layer/logic_fatigue.d \
./Sources/Services_Layer/logic_smart_deg.d \
./Sources/Services_Layer/logic_smart_drive.d \
./Sources/Services_Layer/logic_smart_in.d \
./Sources/Services_Layer/logic_speed.d \
./Sources/Services_Layer/logic_torque.d \
./Sources/Services_Layer/logic_voice.d \
./Sources/Services_Layer/time_base.d \
./Sources/Services_Layer/time_flash.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/Services_Layer/%.o: ../Sources/Services_Layer/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"C:/Users/Administrator/workspace.kds/Voice Prompt/Static_Code/System" -I"C:/Users/Administrator/workspace.kds/Voice Prompt/Static_Code/PDD" -I"C:/Users/Administrator/workspace.kds/Voice Prompt/Static_Code/IO_Map" -I"D:\Program Files\kinetis-design-studio_3.2.0\eclipse\ProcessorExpert/lib/Kinetis/pdd/inc" -I"C:/Users/Administrator/workspace.kds/Voice Prompt/Sources" -I"C:/Users/Administrator/workspace.kds/Voice Prompt/Generated_Code" -I"C:\Users\Administrator\workspace.kds\Voice Prompt\Sources\Application_Layer" -I"C:\Users\Administrator\workspace.kds\Voice Prompt\Sources\ECU_Abstraction_Layer" -I"C:\Users\Administrator\workspace.kds\Voice Prompt\Sources\Services_Layer" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/Events.c \
../Sources/main.c 

OBJS += \
./Sources/Events.o \
./Sources/main.o 

C_DEPS += \
./Sources/Events.d \
./Sources/main.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/%.o: ../Sources/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"C:/Users/Administrator/workspace.kds/Voice Prompt/Static_Code/System" -I"C:/Users/Administrator/workspace.kds/Voice Prompt/Static_Code/PDD" -I"C:/Users/Administrator/workspace.kds/Voice Prompt/Static_Code/IO_Map" -I"D:\Program Files\kinetis-design-studio_3.2.0\eclipse\ProcessorExpert/lib/Kinetis/pdd/inc" -I"C:/Users/Administrator/workspace.kds/Voice Prompt/Sources" -I"C:/Users/Administrator/workspace.kds/Voice Prompt/Generated_Code" -I"C:\Users\Administrator\workspace.kds\Voice Prompt\Sources\Application_Layer" -I"C:\Users\Administrator\workspace.kds\Voice Prompt\Sources\ECU_Abstraction_Layer" -I"C:\Users\Administrator\workspace.kds\Voice Prompt\Sources\Services_Layer" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



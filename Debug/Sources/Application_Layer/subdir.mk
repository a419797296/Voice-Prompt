################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/Application_Layer/globals.c 

OBJS += \
./Sources/Application_Layer/globals.o 

C_DEPS += \
./Sources/Application_Layer/globals.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/Application_Layer/%.o: ../Sources/Application_Layer/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"C:/Users/Administrator/workspace.kds/Voice Prompt/Static_Code/System" -I"C:/Users/Administrator/workspace.kds/Voice Prompt/Static_Code/PDD" -I"C:/Users/Administrator/workspace.kds/Voice Prompt/Static_Code/IO_Map" -I"D:\Program Files\kinetis-design-studio_3.2.0\eclipse\ProcessorExpert/lib/Kinetis/pdd/inc" -I"C:/Users/Administrator/workspace.kds/Voice Prompt/Sources" -I"C:/Users/Administrator/workspace.kds/Voice Prompt/Generated_Code" -I"C:\Users\Administrator\workspace.kds\Voice Prompt\Sources\Application_Layer" -I"C:\Users\Administrator\workspace.kds\Voice Prompt\Sources\ECU_Abstraction_Layer" -I"C:\Users\Administrator\workspace.kds\Voice Prompt\Sources\Services_Layer" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



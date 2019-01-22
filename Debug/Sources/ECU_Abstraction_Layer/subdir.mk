################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/ECU_Abstraction_Layer/Button.c \
../Sources/ECU_Abstraction_Layer/Lightbar.c \
../Sources/ECU_Abstraction_Layer/Voice.c 

OBJS += \
./Sources/ECU_Abstraction_Layer/Button.o \
./Sources/ECU_Abstraction_Layer/Lightbar.o \
./Sources/ECU_Abstraction_Layer/Voice.o 

C_DEPS += \
./Sources/ECU_Abstraction_Layer/Button.d \
./Sources/ECU_Abstraction_Layer/Lightbar.d \
./Sources/ECU_Abstraction_Layer/Voice.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/ECU_Abstraction_Layer/%.o: ../Sources/ECU_Abstraction_Layer/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"C:/Users/Administrator/workspace.kds/Voice Prompt/Static_Code/System" -I"C:/Users/Administrator/workspace.kds/Voice Prompt/Static_Code/PDD" -I"C:/Users/Administrator/workspace.kds/Voice Prompt/Static_Code/IO_Map" -I"D:\Program Files\kinetis-design-studio_3.2.0\eclipse\ProcessorExpert/lib/Kinetis/pdd/inc" -I"C:/Users/Administrator/workspace.kds/Voice Prompt/Sources" -I"C:/Users/Administrator/workspace.kds/Voice Prompt/Generated_Code" -I"C:\Users\Administrator\workspace.kds\Voice Prompt\Sources\Application_Layer" -I"C:\Users\Administrator\workspace.kds\Voice Prompt\Sources\ECU_Abstraction_Layer" -I"C:\Users\Administrator\workspace.kds\Voice Prompt\Sources\Services_Layer" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



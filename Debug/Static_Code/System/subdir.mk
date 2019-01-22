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
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"C:/Users/Administrator/workspace.kds/Voice Prompt/Static_Code/System" -I"C:/Users/Administrator/workspace.kds/Voice Prompt/Static_Code/PDD" -I"C:/Users/Administrator/workspace.kds/Voice Prompt/Static_Code/IO_Map" -I"D:\Program Files\kinetis-design-studio_3.2.0\eclipse\ProcessorExpert/lib/Kinetis/pdd/inc" -I"C:/Users/Administrator/workspace.kds/Voice Prompt/Sources" -I"C:/Users/Administrator/workspace.kds/Voice Prompt/Generated_Code" -I"C:\Users\Administrator\workspace.kds\Voice Prompt\Sources\Application_Layer" -I"C:\Users\Administrator\workspace.kds\Voice Prompt\Sources\ECU_Abstraction_Layer" -I"C:\Users\Administrator\workspace.kds\Voice Prompt\Sources\Services_Layer" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



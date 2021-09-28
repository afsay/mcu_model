################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../mcu_model/source/gpio.cpp \
../mcu_model/source/mcg.cpp \
../mcu_model/source/microcontroller.cpp \
../mcu_model/source/port.cpp \

C_SRCS +=  

OBJS += \
./mcu_model/source/gpio.o \
./mcu_model/source/mcg.o \
./mcu_model/source/microcontroller.o \
./mcu_model/source/port.o \

CPP_DEPS += \
./mcu_model/source/gpio.d \
./mcu_model/source/mcg.d \
./mcu_model/source/microcontroller.d \
./mcu_model/source/port.d \

C_DEPS +=  


# Each subdirectory must supply rules for building sources it contributes
mcu_model/source/%.o: ../mcu_model/source/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C++ Compiler'
	arm-none-eabi-c++ -DCPU_MKL46Z256VLL4_cm0plus -D__MTB_DISABLE -DCPU_MKL46Z256VLL4 -DFSL_RTOS_BM -DSDK_OS_BAREMETAL -DSDK_DEBUGCONSOLE=1 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I"/home/user/vscode-workspace/MKL46Z4_OOP_Model/CMSIS" -I"/home/user/vscode-workspace/MKL46Z4_OOP_Model/source" -I"/home/user/vscode-workspace/MKL46Z4_OOP_Model/mcu_model/include" -I"/home/user/vscode-workspace/MKL46Z4_OOP_Model" -I"/home/user/vscode-workspace/MKL46Z4_OOP_Model/startup" -I"/home/user/vscode-workspace/MKL46Z4_OOP_Model/CMSIS" -O0 -fno-common -fno-strict-aliasing -g3 -Wall -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fno-rtti -fno-exceptions -specs=picolibc.specs -fmerge-constants -fmacro-prefix-map="../$(@D)/"=. -mcpu=cortex-m0plus -mthumb -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

mcu_model/source/%.o: ../mcu_model/source/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DCPU_MKL46Z256VLH4_cm0plus -D__MTB_DISABLE -DCPU_MKL46Z256VLH4 -DFSL_RTOS_BM -DSDK_OS_BAREMETAL -DSDK_DEBUGCONSOLE=1 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I"/home/user/vscode-workspace/MKL46Z4_OOP_Model/CMSIS" -I"/home/user/vscode-workspace/MKL46Z4_OOP_Model/source" -I"/home/user/vscode-workspace/MKL46Z4_OOP_Model/mcu_model/include" -I"/home/user/vscode-workspace/MKL46Z4_OOP_Model" -I"/home/user/vscode-workspace/MKL46Z4_OOP_Model/startup" -I"/home/user/vscode-workspace/MKL46Z4_OOP_Model/CMSIS" -O0 -fno-common -g3 -Wall -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -specs=picolibc.specs -fmerge-constants -fmacro-prefix-map="../$(@D)/"=. -mcpu=cortex-m0plus -mthumb -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



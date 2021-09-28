################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../source/MKL46Z4_OOP_Model.cpp \
../source/cpp_config.cpp \
../source/syscalls.cpp 

C_SRCS += \
../source/mtb.c \
../source/semihost_hardfault.c 

OBJS += \
./source/MKL46Z4_OOP_Model.o \
./source/cpp_config.o \
./source/mtb.o \
./source/semihost_hardfault.o \
./source/syscalls.o 

CPP_DEPS += \
./source/MKL46Z4_OOP_Model.d \
./source/cpp_config.d \
./source/syscalls.d 

C_DEPS += \
./source/mtb.d \
./source/semihost_hardfault.d 


# Each subdirectory must supply rules for building sources it contributes
source/%.o: ../source/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C++ Compiler'
	arm-none-eabi-c++ -DCPU_MKL46Z256VLL4_cm0plus -D__MTB_DISABLE -DCPU_MKL46Z256VLL4 -DFSL_RTOS_BM -DSDK_OS_BAREMETAL -DSDK_DEBUGCONSOLE=1 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I"/home/user/vscode-workspace/MKL46Z4_OOP_Model/CMSIS" -I"/home/user/vscode-workspace/MKL46Z4_OOP_Model/source" -I"/home/user/vscode-workspace/MKL46Z4_OOP_Model/mcu_model/include" -I"/home/user/vscode-workspace/MKL46Z4_OOP_Model" -I"/home/user/vscode-workspace/MKL46Z4_OOP_Model/startup" -I"/home/user/vscode-workspace/MKL46Z4_OOP_Model/CMSIS" -O0 -fno-common -fno-strict-aliasing -g3 -Wall -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fno-rtti -fno-exceptions -specs=picolibc.specs -fmerge-constants -fmacro-prefix-map="../$(@D)/"=. -mcpu=cortex-m0plus -mthumb -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

source/%.o: ../source/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DCPU_MKL46Z256VLH4_cm0plus -D__MTB_DISABLE -DCPU_MKL46Z256VLH4 -DFSL_RTOS_BM -DSDK_OS_BAREMETAL -DSDK_DEBUGCONSOLE=1 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I"/home/user/vscode-workspace/MKL46Z4_OOP_Model/CMSIS" -I"/home/user/vscode-workspace/MKL46Z4_OOP_Model/source" -I"/home/user/vscode-workspace/MKL46Z4_OOP_Model/mcu_model/include" -I"/home/user/vscode-workspace/MKL46Z4_OOP_Model" -I"/home/user/vscode-workspace/MKL46Z4_OOP_Model/startup" -I"/home/user/vscode-workspace/MKL46Z4_OOP_Model/CMSIS" -O0 -fno-common -g3 -Wall -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -specs=picolibc.specs -fmerge-constants -fmacro-prefix-map="../$(@D)/"=. -mcpu=cortex-m0plus -mthumb -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



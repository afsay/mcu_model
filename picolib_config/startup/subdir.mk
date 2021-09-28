################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../startup/startup_mkl46z4.cpp 

OBJS += \
./startup/startup_mkl46z4.o 

CPP_DEPS += \
./startup/startup_mkl46z4.d 


# Each subdirectory must supply rules for building sources it contributes
startup/%.o: ../startup/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C++ Compiler'
	arm-none-eabi-c++ -DCPU_MKL46Z256VLL4_cm0plus -D__MTB_DISABLE -DCPU_MKL46Z256VLL4 -DFSL_RTOS_BM -DSDK_OS_BAREMETAL -DSDK_DEBUGCONSOLE=1 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I"/home/user/vscode-workspace/MKL46Z4_OOP_Model/CMSIS" -I"/home/user/vscode-workspace/MKL46Z4_OOP_Model/source" -I"/home/user/vscode-workspace/MKL46Z4_OOP_Model" -I"/home/user/vscode-workspace/MKL46Z4_OOP_Model/startup" -I"/home/user/vscode-workspace/MKL46Z4_OOP_Model/CMSIS" -O0 -fno-common -fno-strict-aliasing -g3 -Wall -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fno-rtti -fno-exceptions -specs=picolibc.specs -fmerge-constants -fmacro-prefix-map="../$(@D)/"=. -mcpu=cortex-m0plus -mthumb -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



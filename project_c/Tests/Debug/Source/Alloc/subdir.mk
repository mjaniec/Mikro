################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Source/Alloc/gpAlloc.c 

OBJS += \
./Source/Alloc/gpAlloc.o 

C_DEPS += \
./Source/Alloc/gpAlloc.d 


# Each subdirectory must supply rules for building sources it contributes
Source/Alloc/%.o: ../Source/Alloc/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I"D:\Common\projects\mikro_repo\Mikro\project_c\BaseProject" -I"D:\Common\projects\mikro_repo\Mikro\project_c\Tests\Include" -I"D:\Common\projects\mikro_repo\Mikro\project_c\BaseProject\Include\Base" -I"D:\Common\projects\mikro_repo\Mikro\project_c\BaseProject\Include\Alloc" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


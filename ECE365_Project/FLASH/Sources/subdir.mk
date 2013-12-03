################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/CAN.c" \
"../Sources/CAN_MSG_1840_0x730.c" \
"../Sources/CAN_MSG_2000_0x7D0.c" \
"../Sources/Events.c" \
"../Sources/ProcessorExpert.c" \
"../Sources/mqx_tasks.c" \

C_SRCS += \
../Sources/CAN.c \
../Sources/CAN_MSG_1840_0x730.c \
../Sources/CAN_MSG_2000_0x7D0.c \
../Sources/Events.c \
../Sources/ProcessorExpert.c \
../Sources/mqx_tasks.c \

OBJS += \
./Sources/CAN.o \
./Sources/CAN_MSG_1840_0x730.o \
./Sources/CAN_MSG_2000_0x7D0.o \
./Sources/Events.o \
./Sources/ProcessorExpert.o \
./Sources/mqx_tasks.o \

C_DEPS += \
./Sources/CAN.d \
./Sources/CAN_MSG_1840_0x730.d \
./Sources/CAN_MSG_2000_0x7D0.d \
./Sources/Events.d \
./Sources/ProcessorExpert.d \
./Sources/mqx_tasks.d \

OBJS_QUOTED += \
"./Sources/CAN.o" \
"./Sources/CAN_MSG_1840_0x730.o" \
"./Sources/CAN_MSG_2000_0x7D0.o" \
"./Sources/Events.o" \
"./Sources/ProcessorExpert.o" \
"./Sources/mqx_tasks.o" \

C_DEPS_QUOTED += \
"./Sources/CAN.d" \
"./Sources/CAN_MSG_1840_0x730.d" \
"./Sources/CAN_MSG_2000_0x7D0.d" \
"./Sources/Events.d" \
"./Sources/ProcessorExpert.d" \
"./Sources/mqx_tasks.d" \

OBJS_OS_FORMAT += \
./Sources/CAN.o \
./Sources/CAN_MSG_1840_0x730.o \
./Sources/CAN_MSG_2000_0x7D0.o \
./Sources/Events.o \
./Sources/ProcessorExpert.o \
./Sources/mqx_tasks.o \


# Each subdirectory must supply rules for building sources it contributes
Sources/CAN.o: ../Sources/CAN.c
	@echo 'Building file: $<'
	@echo 'Executing target #1 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/CAN.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/CAN.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/CAN_MSG_1840_0x730.o: ../Sources/CAN_MSG_1840_0x730.c
	@echo 'Building file: $<'
	@echo 'Executing target #2 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/CAN_MSG_1840_0x730.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/CAN_MSG_1840_0x730.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/CAN_MSG_2000_0x7D0.o: ../Sources/CAN_MSG_2000_0x7D0.c
	@echo 'Building file: $<'
	@echo 'Executing target #3 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/CAN_MSG_2000_0x7D0.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/CAN_MSG_2000_0x7D0.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/Events.o: ../Sources/Events.c
	@echo 'Building file: $<'
	@echo 'Executing target #4 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/Events.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/Events.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/ProcessorExpert.o: ../Sources/ProcessorExpert.c
	@echo 'Building file: $<'
	@echo 'Executing target #5 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/ProcessorExpert.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/ProcessorExpert.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/mqx_tasks.o: ../Sources/mqx_tasks.c
	@echo 'Building file: $<'
	@echo 'Executing target #6 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/mqx_tasks.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/mqx_tasks.o"
	@echo 'Finished building: $<'
	@echo ' '



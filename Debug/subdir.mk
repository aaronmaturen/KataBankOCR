################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../OCR.cpp \
../OCRTest.cpp \
../RunAllTests.cpp 

OBJS += \
./OCR.o \
./OCRTest.o \
./RunAllTests.o 

CPP_DEPS += \
./OCR.d \
./OCRTest.d \
./RunAllTests.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/Users/atmature/Documents/workspace/CppUTest/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



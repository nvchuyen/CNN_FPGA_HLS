################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
E:/CMC/CNN/VitisHLS/input_cnn/input_cnn.cpp 

OBJS += \
./source/input_cnn.o 

CPP_DEPS += \
./source/input_cnn.d 


# Each subdirectory must supply rules for building sources it contributes
source/input_cnn.o: E:/CMC/CNN/VitisHLS/input_cnn/input_cnn.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -DAESL_TB -D__llvm__ -D__llvm__ -IC:/Xilinx/Vitis_HLS/2020.2/include/ap_sysc -IC:/Xilinx/Vitis_HLS/2020.2/win64/tools/systemc/include -IC:/Xilinx/Vitis_HLS/2020.2/include/etc -IE:/CMC/CNN/VitisHLS/input_cnn -IC:/Xilinx/Vitis_HLS/2020.2/include -IC:/Xilinx/Vitis_HLS/2020.2/win64/tools/auto_cc/include -IF:/NVChuyen/CNN/VitisHLS/input_cnn -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



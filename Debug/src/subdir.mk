################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/cpp.cpp 

CPP_DEPS += \
./src/cpp.d 

OBJS += \
./src/cpp.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -include"/home/pirxio/eclipse-workspace/cpp/src/Bit.hpp" -include"/home/pirxio/eclipse-workspace/cpp/src/biblioteca/tads/BitReader.hpp" -include"/home/pirxio/eclipse-workspace/cpp/src/biblioteca/tads/BitWriter.hpp" -include"/home/pirxio/eclipse-workspace/cpp/src/biblioteca/tads/Array.hpp" -include"/home/pirxio/eclipse-workspace/cpp/src/biblioteca/funciones/arrays.hpp" -include"/home/pirxio/eclipse-workspace/cpp/src/biblioteca/tads/huffman/HuffmanSetup.hpp" -include"/home/pirxio/eclipse-workspace/cpp/src/biblioteca/tads/huffman/Progress.hpp" -include"/home/pirxio/eclipse-workspace/cpp/src/biblioteca/funciones/files.hpp" -include"/home/pirxio/eclipse-workspace/cpp/src/biblioteca/funciones/lists.hpp" -include"/home/pirxio/eclipse-workspace/cpp/src/biblioteca/funciones/strings.hpp" -include"/home/pirxio/eclipse-workspace/cpp/src/biblioteca/funciones/tokens.hpp" -include"/home/pirxio/eclipse-workspace/cpp/src/biblioteca/tads/Coll.hpp" -include"/home/pirxio/eclipse-workspace/cpp/src/biblioteca/tads/List.hpp" -include"/home/pirxio/eclipse-workspace/cpp/src/biblioteca/tads/Map.hpp" -include"/home/pirxio/eclipse-workspace/cpp/src/biblioteca/tads/Queue.hpp" -include"/home/pirxio/eclipse-workspace/cpp/src/biblioteca/tads/Stack.hpp" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/cpp.d ./src/cpp.o

.PHONY: clean-src


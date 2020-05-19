cmake_minimum_required(VERSION 3.16)
project(ece510project3_0_2)

set(CMAKE_CXX_STANDARD 14)

add_executable(ece510project3_0_2 main.cpp Cpu.cpp Cpu.h tools.cpp tools.h Memory.cpp Memory.h Cpu_1_IF.cpp Cpu_2_ID.cpp Cpu_3_EX.cpp Cpu_4_MEM.cpp Cpu_5_WB.cpp)
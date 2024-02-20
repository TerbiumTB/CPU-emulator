cmake_minimum_required(VERSION 3.26)
project(cpu_emulator)

set(CMAKE_CXX_STANDARD 20)

add_executable(cpu_emulator main.cpp)

include_directories(stack)

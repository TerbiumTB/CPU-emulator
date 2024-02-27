cmake_minimum_required(VERSION 3.26)
project(cpu_emulator)

set(CMAKE_CXX_STANDARD 20)

add_executable(cpu_emulator main.cpp)

include_directories(stack)
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_subdirectory(stack/tests)





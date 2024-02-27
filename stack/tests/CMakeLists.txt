project(stack-tests)

#include_directories(stack)

add_executable(stack-tests stack-tests.cpp)

target_link_libraries(stack-tests gtest gtest_main)
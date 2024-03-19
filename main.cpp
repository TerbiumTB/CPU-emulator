#include <iostream>
#include <vector>
#include <type_traits>

#include "stack.h"
#include "cpu-emulator.h"

using namespace cpu_emulator;

int main(int argc, char *argv[]) {
    auto x = std::make_shared<commands::Begin>();
//    std::cout << std::remove_pointer<decltype(x)>::type ;
    auto f = command_factory::CommandFactory();
//    f.create<std::remove_pointer<decltype(x)>::type()>();

//    std::cout << argv[1];
//    auto emulator = CpuEmulator("/Users/timofejbulgakov/CLionProjects/CPU_emulator/fibonacci.crash");
    auto emulator = CpuEmulator(argv[1]);
//    CpuEmulator emulator{"/Users/timofeybulgakov/CLionProjects/HSEhomework/CPU-emulator/program.crash"};
    emulator.Run();
    return 0;
}


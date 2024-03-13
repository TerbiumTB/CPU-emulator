#include <iostream>
#include <vector>

#include "stack.h"
#include "cpu-emulator.h"

using namespace cpu_emulator;

int main(int argc, char *argv[]) {
//    std::cout << argv[1];
//    auto emulator = CpuEmulator("/Users/timofejbulgakov/CLionProjects/CPU_emulator/fibonacci.crash");
    auto emulator = CpuEmulator(argv[1]);
//    CpuEmulator emulator{"/Users/timofeybulgakov/CLionProjects/HSEhomework/CPU-emulator/program.crash"};
    emulator.Run();
    return 0;
}


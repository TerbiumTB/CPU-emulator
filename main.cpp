#include <iostream>
#include <vector>

#include "stack.h"
#include "cpu-emulator.h"

using namespace cpu_emulator;

int main() {
    auto emulator = CpuEmulator("/Users/timofejbulgakov/CLionProjects/CPU_emulator/program.crash");
    emulator.Run();
    return 0;
}


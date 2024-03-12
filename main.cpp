#include <iostream>
#include <vector>

#include "stack.h"
#include "cpu-emulator.h"

using namespace cpu_emulator;

int main() {
    auto emulator = CpuEmulator("/Users/timofeybulgakov/CLionProjects/HSEhomework/CPU-emulator/program.crash");
    emulator.Run();
    return 0;
}


#ifndef CPU_EMULATOR_CPU_EMULATOR_H
#define CPU_EMULATOR_CPU_EMULATOR_H

#include <utility>
#include <vector>
#include <map>
#include <memory>
#include <fstream>
#include <string>

#include "state.h"
#include "preprocessor.h"
namespace cpu_emulator{
//    struct file: public std::{
//        empty_stack_access() : std::out_of_range("stack is empty!") {};
//    };
    class CpuEmulator{
    private:
        std::ifstream input_file_;
        std::string input_file_name_;
        State state_;
        preprocessor::Preprocessor preprocessor_;

    public:
        explicit CpuEmulator(std::string );

        void Run();
    };
}

#endif //CPU_EMULATOR_CPU_EMULATOR_H

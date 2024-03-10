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
        std::shared_ptr<State> state_;
//        preprocessor::Preprocessor preproc_;

    public:
        explicit CpuEmulator(std::string);

        void Run();
    };
}

#endif //CPU_EMULATOR_CPU_EMULATOR_H

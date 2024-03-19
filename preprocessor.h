#ifndef CPU_EMULATOR_PREPROCESSOR_H
#define CPU_EMULATOR_PREPROCESSOR_H
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <iterator>


#include "parser.h"
#include "commands.h"
#include "state.h"

namespace cpu_emulator::preprocessor{
    class Preprocessor{
    private:
        parser::Parser parser_;
        std::vector<std::shared_ptr<commands::ICommand>> commands_;

    public:
        explicit Preprocessor(std::ifstream &);
        std::vector<std::shared_ptr<commands::ICommand>> Process();

    };
}
#endif //CPU_EMULATOR_PREPROCESSOR_H

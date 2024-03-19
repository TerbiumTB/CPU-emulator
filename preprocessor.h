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
//        parser::Parser parser_;
        std::vector<std::shared_ptr<commands::ICommand>> commands_;
        std::map<std::string, int> labels_;

    public:
        void Process(std::ifstream &);
        [[nodiscard]] std::vector<std::shared_ptr<commands::ICommand>> getCommands() const { return commands_; }
        [[nodiscard]] std::map<std::string, int> getLabels() const { return labels_; }
    };
}
#endif //CPU_EMULATOR_PREPROCESSOR_H

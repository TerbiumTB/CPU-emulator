#include "preprocessor.h"

#include <utility>

namespace cpu_emulator::preprocessor {
    Preprocessor::Preprocessor(std::ifstream & input_file) :
             parser_(input_file) {}

    std::vector<std::shared_ptr<commands::ICommand>> Preprocessor::Process() {

        while(!parser_.IsEmpty()){
            commands_.push_back(parser_.ParseCommand());
        }

        return commands_;
    }
}
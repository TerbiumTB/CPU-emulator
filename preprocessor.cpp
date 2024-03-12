#include "preprocessor.h"

#include <utility>

namespace cpu_emulator::preprocessor {
    Preprocessor::Preprocessor(std::ifstream & input_file, std::shared_ptr<State> & state) :
             parser_(input_file), state_(state) {}

    std::vector<std::shared_ptr<commands::ICommand>> Preprocessor::Process() {

        while(!parser_.IsEmpty()){
            commands_.push_back(parser_.ParseCommand()
                                        ->setState(state_)
                                        .setArgs()
                                        .build());
        }

        return commands_;
    }
}
#include "preprocessor.h"

#include <utility>

namespace cpu_emulator::preprocessor {

    void Preprocessor::Process(std::ifstream & input_file) {
        auto parser = parser::Parser(input_file);

        while(!parser.IsEmpty()){
            try{
                commands_.push_back(parser.ParseCommand());
            }
            catch (parser::syntax_error &e){
                labels_[parser.ParseLabel()] = commands_.size();
            }

        }

//        return commands_;
    }
}
#include "cpu-emulator.h"
#include "iterator"
#include "commands.h"


namespace cpu_emulator {
    CpuEmulator::CpuEmulator(std::string input_file_name) : input_file_name_(std::move(input_file_name)) {
        input_file_.open(input_file_name_);
        state_ = std::make_shared<State>();
    }

    void CpuEmulator::Run() {


        if (input_file_.fail()) {
            throw std::ios_base::failure("program file doesn't exist");
        }
//        auto input = std::istream_iterator<std::string>(input_file_);
//
//        auto end = std::istream_iterator<std::string>();
//        while (input != end){
//            std::cout << *input << std::endl;
//            input++;
//        }

        auto commands = preprocessor::Preprocessor(input_file_, state_).Process();

        for(auto &command : commands){
//            if()
        }
    }

}

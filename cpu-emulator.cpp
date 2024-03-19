#include "cpu-emulator.h"

#include <utility>
#include "commands.h"


namespace cpu_emulator {
    CpuEmulator::CpuEmulator(std::string input_file_name) : input_file_name_(std::move(input_file_name)) {
        input_file_.open(input_file_name_);
    }


    void CpuEmulator::Run() {

        if (input_file_.fail()) {
            throw std::ios_base::failure("program file doesn't exist");
        }

        preprocessor_.Process(input_file_);
        state_.labels = preprocessor_.getLabels();
        auto commands = preprocessor_.getCommands();

        while (state_.pivot < commands.size()){
            commands[state_.pivot]->DoIt(state_);
//            std::cout << state->registers[Register::ax] << ' ' << state->registers[Register::bx] << std::endl;
            state_.pivot++;
        }
    }

}

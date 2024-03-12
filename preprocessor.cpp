#include "preprocessor.h"

#include <utility>

namespace cpu_emulator::preprocessor {
    Preprocessor::Preprocessor(std::ifstream & input_file, std::shared_ptr<State> & state) :
             parser_(input_file), state_(state) {}

    std::vector<std::unique_ptr<commands::ICommand>> Preprocessor::Process() {
        commands_.push_back(parser_.ParseCommand()
                ->setState(state_)
                .setArgs()
                .build());
        commands_.back()->DoIt();


//        a->DoIt();
//        parser_.Parse(parser::TokenType::COMMAND);
//        command_.setArgs(parser_.ParseArgs(command_.Args));
//        while (parser_.IsDefined()){
//            switch(command_parser_.Parse(parser_.get_token().value)){
//                case parser::CommandType::BEGIN:
//                    commands_.push_back(commands::Begin(state_));
//                    break;
//                case parser::CommandType::END:
//                    commands_.push_back(commands::End(state_));
//                    break;
//                case parser::CommandType::PUSH:
//                    parser_.Parse(parser::TokenType::VALUE);
//                    if (parser_.IsDefined()){
//                        commands_.push_back(commands::Push(state_, std::stoi(parser_.get_token().value)));
//                    }
//                    break;
//                case parser::CommandType::POP:
//                    commands_.push_back(commands::Pop(state_));
//                    break;
//                case parser::CommandType::PUSHR:
//                    break;
//                case parser::CommandType::POPR:
//                    break;
//                default:
//                    throw parser::syntax_error();
//            }

//        }
//        return commands_;
//return *commands_;

return {};
    }
}
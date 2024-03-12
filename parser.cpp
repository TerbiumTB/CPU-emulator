#include <string>
#include <regex>
#include <vector>
#include <memory>

#include "parser.h"

namespace cpu_emulator::parser {
    //interface---------------------------------
    ICommandBuilder::ICommandBuilder(std::shared_ptr<file_iterator> &input)
            : input_(input) {}

    std::unique_ptr<commands::ICommand> ICommandBuilder::build() {
        return std::make_unique<commands::ICommand>(state_);
    }

    void ICommandBuilder::input(std::shared_ptr<file_iterator> & input) {
        input_ = input;
    }

    ICommandBuilder &ICommandBuilder::setState(std::shared_ptr<State> &state) {
        state_ = state;
        return *this;
    }

    ICommandBuilder &ICommandBuilder::setArgs() {
        return *this;
    }
    //---------------------------------

    //No args builder---------------------------------
    template<TemplateCommand Command>
    CommandBuilder<Command>::CommandBuilder(std::shared_ptr<file_iterator> &input)
    : ICommandBuilder(input){}

    template<TemplateCommand Command>
    CommandBuilder<Command> &CommandBuilder<Command>::setArgs() {
        return *this;
    }

    template<TemplateCommand Command>
    CommandBuilder<Command> &CommandBuilder<Command>::setState(std::shared_ptr<State> &state) {
        state_ = state;
        return *this;
    }

    template<TemplateCommand Command>
    std::unique_ptr<commands::ICommand> CommandBuilder<Command>::build() {
        return std::make_unique<Command>(Command(state_));
    }
    //---------------------------------


    //builder with value---------------------------------
    template<TemplateCommand Command>
    CommandWithValueBuilder<Command>::CommandWithValueBuilder(std::shared_ptr<file_iterator> &input)
            : ICommandBuilder(input){}

    template<TemplateCommand Command>
    CommandWithValueBuilder<Command> &CommandWithValueBuilder<Command>::setArgs() {
        if (std::regex_match(input_->operator*(), value_regex_)) {
            value_ = std::stoi(input_->operator*());
            input_->operator++();
            return *this;
        }
        throw syntax_error();
    }

    template<TemplateCommand Command>
    CommandWithValueBuilder<Command> &CommandWithValueBuilder<Command>::setState(std::shared_ptr<State> &state) {
        state_ = state;
        return *this;
    }

    template<TemplateCommand Command>
    std::unique_ptr<commands::ICommand> CommandWithValueBuilder<Command>::build() {
        return std::make_unique<Command>(Command(state_, value_));
    }
    //---------------------------------

    //buider with register---------------------------------
    template<TemplateCommand Command>
    CommandWithRegisterBuilder<Command>::CommandWithRegisterBuilder(std::shared_ptr<file_iterator> &input)
            : ICommandBuilder(input){}
    template<TemplateCommand Command>
    CommandWithRegisterBuilder<Command> &CommandWithRegisterBuilder<Command>::setArgs() {
        for (auto &[reg, match] : register_regex_){
            if ((std::regex_match(input_->operator*(), match))){
                input_->operator++();
                return *this;
            }
        }
//        if (std::regex_match(input_->operator*(), register_regex_)) {
//            auto r = input_->operator*()[0];
//            switch(r){
//                case 'B':
//                case 'b':
//                    reg_ = Register::bx;
//                    break;
//                case 'C':
//                case 'c':
//                    reg_ = Register::cx;
//                    break;
//                case 'D':
//                case 'd':
//                    reg_ = Register::dx;
//                    break;
//                case 'E':
//                case 'e':
//                    reg_ = Register::ex;
//                    break;
//                case 'F':
//                case 'f':
//                    reg_ = Register::fx;
//                    break;
//                case 'G':
//                case 'g':
//                    reg_ = Register::gx;
//                    break;
//                case 'H':
//                case 'h':
//                    reg_ = Register::hx;
//                    break;
//                default:
//                    reg_ = Register::ax;
//            }

//        }
        throw syntax_error();
    }

    template<TemplateCommand Command>
    CommandWithRegisterBuilder<Command> &CommandWithRegisterBuilder<Command>::setState(std::shared_ptr<State> &state) {
        state_ = state;
        return *this;
    }

    template<TemplateCommand Command>
    std::unique_ptr<commands::ICommand> CommandWithRegisterBuilder<Command>::build() {
        return std::make_unique<Command>(Command(state_, reg_));
    }
    //---------------------------------

    Parser::Parser(std::ifstream &input_file) {
        input_ = std::make_shared<file_iterator>(file_iterator(input_file));
    }

    std::shared_ptr<ICommandBuilder> Parser::ParseCommand() {
        for (auto &reg: command_regex_) {
            if (std::regex_match(input_->operator*(), reg.regex)) {
                input_->operator++();
                reg.builder->input(input_);
                return reg.builder;
            }
        }

        throw syntax_error();
    }

    bool Parser::IsEmpty() {
        return *input_ == std::istream_iterator<std::string>();
    }
}
#include <string>
#include <regex>
#include <vector>
#include <memory>
#include <type_traits>
#include <iostream>

#include "parser.h"

namespace cpu_emulator::parser {
    Parser::Parser(std::ifstream &input_file) {
        input_ = file_iterator(input_file);
    }

    template<class Arg>
    std::shared_ptr<commands::ICommand> ICommandFactory<Arg>::create(Arg arg) {
        return {};
    }

    std::shared_ptr<commands::ICommand> ICommandFactory<void>::create() {
        return {};
    }

    template<TemplateCommand Command, class Arg>
    std::shared_ptr<commands::ICommand> CommandFactory<Command, Arg>::create(Arg arg) {
        return std::make_shared<Command>(Command(arg));
    }

    template<TemplateCommand Command>
    std::shared_ptr<commands::ICommand> CommandFactory<Command, void>::create() {
        return std::make_shared<Command>();
    }

    std::shared_ptr<commands::ICommand>
    Parser::ParseCommand() {
//        auto x = command_factory::CommandFactory<commands::Label, std::string>();
        for(auto &dir: director_){
            if (std::regex_match(*input_, dir.regex)){
                input_++;
                return dir.factory->create();
            }
        }

        for (auto &dir: director_with_value_){
            if (std::regex_match(*input_, dir.regex)){
                input_++;
                return dir.factory->create(ParseValue());
            }
        }

        for (auto &dir: director_with_register_){
            if (std::regex_match(*input_, dir.regex)){
                input_++;
                return dir.factory->create(ParseRegister());
            }
        }

        for (auto &dir: director_with_label_){
            if (std::regex_match(*input_, dir.regex)){
                if (!dir.declaration)
                    input_++;

                return dir.factory->create(ParseLabel());
            }
        }
        std::cout << *input_ << std::endl;
        throw syntax_error();

    }

    int Parser::ParseValue() {
        if (std::regex_match(*input_, value_regex_)) {
            auto value = std::stoi(*input_);
            input_++;
            return value;
        }
        throw syntax_error();
    }

    Register Parser::ParseRegister() {
        for (auto &[reg, match]: register_regex_)
            if ((std::regex_match(*input_, match))) {
                input_++;
                return reg;
            }
        throw syntax_error();
    }

    std::string Parser::ParseLabel() {
        if (std::regex_match(*input_, label_regex_)) {
            auto label = *input_;
            input_++;
            if (label.back() == ':'){
                label =  label.substr(0, label.size() - 1);
            }

            return label;
        }
        throw syntax_error();
    }

    bool Parser::IsEmpty() {
        return input_ == std::istream_iterator<std::string>();
    }
}
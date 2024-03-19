#include <string>
#include <regex>
#include <vector>
#include <memory>
#include <type_traits>

#include "parser.h"

namespace cpu_emulator::parser {
    Parser::Parser(std::ifstream &input_file) {
        input_ = file_iterator(input_file);
    }

    std::shared_ptr<commands::ICommand> Parser::ParseCommand() {
//        command_factory::CommandFactory factory;
//        auto x = commands::Begin();
        for (auto &reg: command_regex_) {
            if (!std::regex_match(*input_, reg.regex))
                continue;

            if (reg.args != Args::NAME)
                input_++;

            switch (reg.args) {
                case Args::NONE:
//                    return dynamic_cast<command_factory::CommandFactory<commands::ICommand> &>((*reg.factory));
                    return factory.create<decltype()>() ;
                case Args::VALUE:
//                    command_factory::CommandFactory<decltype(*reg.command), int>()
//                    return decltype(reg.command){(ParseValue())};
                    return factory.create<decltype(reg.command)>(ParseValue());
                case Args::REGISTER:
                    return factory.create<decltype(reg.command)>(ParseRegister());
                default:
                    return factory.create<decltype(reg.command)>(ParseLabel());
            }

        }

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
            return label;
        }
        throw syntax_error();
    }

    bool Parser::IsEmpty() {
        return input_ == std::istream_iterator<std::string>();
    }
}
#include <string>
#include <regex>
#include <vector>
#include <memory>
#include <type_traits>

#include "parser.h"

namespace cpu_emulator::parser {
    template<class T>
    Parser<T>::Parser(std::ifstream &input_file) {
        input_ = file_iterator(input_file);
    }

    template<class T>
    std::shared_ptr<commands::ICommand>
    Parser<T>::ParseCommand() {
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
                    return commands_map.at(reg.command)(); // factory.create<decltype()>() ;
                case Args::VALUE:
//                    command_factory::CommandFactory<decltype(*reg.command), int>()
//                    return decltype(reg.command){(ParseValue())};
                    return commands_map.at(reg.command)(
                            ParseValue()); // factory.create<decltype(reg.command)>(ParseValue());
                case Args::REGISTER:
                    return commands_map.at(reg.command)(
                            ParseRegister()); // factory.create<decltype(reg.command)>(ParseRegister());
                default:
                    return commands_map.at(reg.command)(ParseLabel());
//                    return factory.create<decltype(reg.command)>(ParseLabel());
            }

        }

        throw syntax_error();
    }

    template<class T>
    int Parser<T>::ParseValue() {
        if (std::regex_match(*input_, value_regex_)) {
            auto value = std::stoi(*input_);
            input_++;
            return value;
        }
        throw syntax_error();
    }

    template<class T>
    Register Parser<T>::ParseRegister() {
        for (auto &[reg, match]: register_regex_)
            if ((std::regex_match(*input_, match))) {
                input_++;
                return reg;
            }
        throw syntax_error();
    }

    template<class T>
    std::string Parser<T>::ParseLabel() {
        if (std::regex_match(*input_, label_regex_)) {
            auto label = *input_;
            input_++;
            return label;
        }
        throw syntax_error();
    }

    template<class T>
    bool Parser<T>::IsEmpty() {
        return input_ == std::istream_iterator<std::string>();
    }
}
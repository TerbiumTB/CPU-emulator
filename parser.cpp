#include <string>
#include <regex>
#include <vector>
#include <memory>

#include "parser.h"

namespace cpu_emulator::parser {
//    TokenParser::TokenParser(std::ifstream & input_file) {
//        input_ = std::istream_iterator<std::string>(input_file);
//    };
//
//    [[nodiscard]] bool TokenParser::IsDefined() const {
//        return token_.type != TokenType::UNDEFINED;
//    }
//
//    TokenParser &TokenParser::Parse(TokenType type) {
//        std::regex_search(*input_, last_match_, token_regex_.at(type));
//
//        if (last_match_.empty()) {
//            token_ = {*input_, TokenType::UNDEFINED};
//            return *this;
//        }
//
//        ++input_;
//        token_ = {last_match_.str(), type};
//        return *this;
//    }
//
////    TokenParser &TokenParser::Skip(TokenType type) {
////        std::regex_search(input_.cbegin() + offset_, input_.cend(), token_regex_.at(type));
////        if (last_match_.empty()) {
////            throw syntax_error();
////        }
////        offset_ = last_match_.position() + last_match_.length();
////        return *this;
////    }
//    TokenParser &TokenParser::OrElse(TokenType type) {
//        if(!last_match_.empty()){
//            return *this;
//        }
//
//        return Parse(type);
//    }
//
////    CommandType TokenParser::CommandParse() {
////
////        for(auto const&[type, reg] : command_regex_){
////            if (std::regex_match(token_.value, reg)){
////                return type;
////            }
////        }
////        return CommandType::UNDEFINED;
////    }
//
//    [[nodiscard]] Token TokenParser::get_token() const {
//        return token_;
//    }

//    CommandType CommandParser::Parse(const std::string & command_){
//        for(auto const&[type, reg] : command_regex_){
//            if (std::regex_match(command_, reg)){
//                return type;
//            }
//        }
//        return CommandType::UNDEFINED;
//    }
    std::unique_ptr<commands::ICommand> ICommandBuilder::build() {
        return std::make_unique<commands::ICommand>(state_);
    }

    ICommandBuilder &ICommandBuilder::setState(std::shared_ptr<State> & state) {
        state_ = state;
        return *this;
    }
    ICommandBuilder &ICommandBuilder::setArgs() {
        return *this;
    }


    template<TemplateCommand Command>
    CommandBuilder<Command> &CommandBuilder<Command>::setArgs() {
        return *this;
    }

    template<TemplateCommand Command>
    CommandBuilder<Command> &CommandBuilder<Command>::setState(std::shared_ptr<State> & state) {
        state_ = state;
        return *this;
    }

    template<TemplateCommand Command>
    std::unique_ptr<commands::ICommand> CommandBuilder<Command>::build() {

        return std::make_unique<Command>(Command(state_));
    }

    template<TemplateCommand Command>
    CommandWithValueBuilder<Command> &CommandWithValueBuilder<Command>::setArgs() {
        int value =1;
        return *this;
    }

    template<TemplateCommand Command>
    CommandWithValueBuilder<Command> &CommandWithValueBuilder<Command>::setState(std::shared_ptr<State> & state) {
        state_ = state;
        return *this;
    }

    template<TemplateCommand Command>
    std::unique_ptr<commands::ICommand> CommandWithValueBuilder<Command>::build() {

        return std::make_unique<Command>(Command(state_, value_));
    }


    Parser::Parser(std::ifstream & input_file) {
//        command_regex_[std::shared_ptr<CommandBuilder<commands::Begin>>()] = std::regex("BEGIN|BEG|begin|beg");
//        command_regex_[std::shared_ptr<CommandWithValueBuilder<commands::Push>>()] = std::regex("PUSH|push");
        input_ = std::istream_iterator<std::string>(input_file);
    }
    std::shared_ptr<ICommandBuilder> Parser::ParseCommand() {
        for(auto &reg : command_regex_){
//            std::cout << ;
            if (std::regex_match(*input_, reg.regex_)){
                return reg.builder_;
            }
        }

        return {};
//        return std::make_unique<CommandBuilder<commands::Begin>>(CommandBuilder<commands::Begin>(Args::NONE));
    }
}
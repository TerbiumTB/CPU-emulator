#ifndef CPU_EMULATOR_PARSER_H
#define CPU_EMULATOR_PARSER_H

#include <string>
#include <vector>
#include <regex>
#include <iterator>
#include <map>
#include <fstream>


#include "state.h"
#include "command_factory.h"


namespace cpu_emulator::parser {

    struct syntax_error : public std::exception {
        syntax_error() : std::exception() {};

        [[nodiscard]] const char *what() const noexcept override {
            return "syntax error";
        }
    };

    typedef std::istream_iterator<std::string> file_iterator;

    enum class Args {
        NONE,
        VALUE,
        REGISTER,
        LABEL,
        NAME
    };
    struct CommandDirector {
//        std::shared_ptr<command_factory::ICommandFactory> factory;
        commands::ICommand *command;
        Args args;
        std::regex regex;
    };

    enum class CommandNames {
        BEGIN,
        END,
        PUSH,
        POP,
        PUSHR,
        POPR,
        IN,
        OUT,
        ADD,
        SUB,
        MUL,
        DIV,
        JMP,
        JEQ,
        JNE,
        JA,
        JAE,
        JB,
        JBE,
        CALL,
        RET
    };

    template<class T = int>
    class Parser {
    private:
        file_iterator input_;
        std::map<CommandNames, std::function<std::shared_ptr<commands::ICommand>(T)>> commands_map {
                {CommandNames::BEGIN, []() {return std::make_shared<commands::Begin>();}},
                {CommandNames::END, []() {return std::make_shared<commands::End>();}},
                {CommandNames::POP, []() {return std::make_shared<commands::Pop>();}},
                {CommandNames::IN, []() {return std::make_shared<commands::In>();}},
                {CommandNames::OUT, []() {return std::make_shared<commands::Out>();}},
                {CommandNames::ADD, []() {return std::make_shared<commands::Add>();}},
                {CommandNames::SUB, []() {return std::make_shared<commands::Sub>();}},
                {CommandNames::MUL, []() {return std::make_shared<commands::Mul>();}},
                {CommandNames::DIV, []() {return std::make_shared<commands::Div>();}},
                {CommandNames::RET, []() {return std::make_shared<commands::Ret>();}},
                {CommandNames::PUSH,    [](T arg) {return std::make_shared<commands::Push>(arg);}},
                {CommandNames::POPR,    [](T arg) {return std::make_shared<commands::Popr>(arg);}},
                {CommandNames::PUSHR,   [](T arg) {return std::make_shared<commands::Pushr>(arg);}},
                {CommandNames::JMP,     [](T arg) {return std::make_shared<commands::Jmp>(arg);}},
                {CommandNames::JEQ,     [](T arg) {return std::make_shared <commands::Jeq>(arg);}},
                {CommandNames::JNE,     [](T arg) {return std::make_shared<commands::Jne>(arg);}},
                {CommandNames::JA,      [](T arg) {return std::make_shared<commands::Ja>(arg);}},
                {CommandNames::JAE,     [](T arg) {return std::make_shared<commands::Jae>(arg);}},
                {CommandNames::JB,      [](T arg) {return std::make_shared<commands::Jb>(arg);}},
                {CommandNames::JBE,     [](T arg) {return std::make_shared<commands::Jbe>(arg);}},
                {CommandNames::CALL,    [](T arg) {return std::make_shared<commands::Call>(arg);}},
        };
/*        std::vector<CommandDirector> command_regex_ = {
                {std::make_shared<CommandFactory<commands::Begin>>(),             std::regex("BEGIN|BEG|begin|beg")},
                {std::make_shared<CommandFactory<commands::End>>(),               std::regex("END|end")},
                {std::make_shared<CommandWithValueFactory<commands::Push>>(),     std::regex("PUSH|push")},
                {std::make_shared<CommandFactory<commands::Pop>>(),               std::regex("POP|pop")},
                {std::make_shared<CommandWithRegisterFactory<commands::Pushr>>(), std::regex("PUSHR|pushr")},
                {std::make_shared<CommandWithRegisterFactory<commands::Popr>>(),  std::regex("POPR|popr")},
                {std::make_shared<CommandFactory<commands::In>>(),  std::regex("IN|in")},
                {std::make_shared<CommandFactory<commands::Out>>(),  std::regex("OUT|out")},
                {std::make_shared<CommandFactory<commands::Add>>(),  std::regex("ADD|add")},
                {std::make_shared<CommandFactory<commands::Sub>>(),  std::regex("SUB|sub")},
                {std::make_shared<CommandFactory<commands::Mul>>(),  std::regex("MUL|mul")},
                {std::make_shared<CommandFactory<commands::Div>>(),  std::regex("DIV|div")},
                {std::make_shared<CommandFactory<commands::Div>>(),  std::regex("DIV|div")},
                {std::make_shared<CommandFactory<commands::Div>>(),  std::regex("DIV|div")},
//                {std::make_shared<CommandWithLabelFactory<commands::Label>>(),  std::regex("[a-zA-Z_][a-zA-Z0-9_]*:")},
                {std::make_shared<CommandWithLabelFactory<commands::Jmp>>(),  std::regex("JMP|jmp")},
                {std::make_shared<CommandWithLabelFactory<commands::Jeq>>(),  std::regex("JEQ|jeq")},
                {std::make_shared<CommandWithLabelFactory<commands::Jne>>(),  std::regex("JNE|jne")},
                {std::make_shared<CommandWithLabelFactory<commands::Ja>>(),  std::regex("JA|ja")},
                {std::make_shared<CommandWithLabelFactory<commands::Jae>>(),  std::regex("JAE|jae")},
                {std::make_shared<CommandWithLabelFactory<commands::Jb>>(),  std::regex("JB|jb")},
                {std::make_shared<CommandWithLabelFactory<commands::Jbe>>(),  std::regex("JBE|jbe")},
        };*/

//std

        std::vector<CommandDirector> command_regex_ = {
//                  {std::make_shared<commands::Begin>(), Args::NONE,     std::regex("BEGIN|BEG|begin|beg")}
//                {std::make_shared<command_factory::CommandFactory<commands::ICommand, int>>(), Args::NONE,     std::regex("BEGIN|BEG|begin|beg")}
                    {new commands::Begin(),             Args::NONE,     std::regex("BEGIN|BEG|begin|beg")},
//                {std::make_shared<command_factory::CommandFactory<commands::End>>(),               Args::NONE,     std::regex("END|end")},
//                {std::make_shared<command_factory::CommandWithValueFactory<commands::Push>>(),     Args::VALUE,    std::regex("PUSH|push")},
//                {std::make_shared<command_factory::CommandFactory<commands::Pop>>(),               Args::NONE,     std::regex("POP|pop")},
//                {std::make_shared<command_factory::CommandWithRegisterFactory<commands::Pushr>>(), Args::REGISTER, std::regex("PUSHR|pushr")},
//                {std::make_shared<command_factory::CommandWithRegisterFactory<commands::Popr>>(),  Args::REGISTER, std::regex("POPR|popr")},
//                {std::make_shared<command_factory::CommandFactory<commands::In>>(),                Args::NONE,     std::regex("IN|in")},
//                {std::make_shared<command_factory::CommandFactory<commands::Out>>(),               Args::NONE,     std::regex("OUT|out")},
//                {std::make_shared<command_factory::CommandFactory<commands::Add>>(),               Args::NONE,     std::regex("ADD|add")},
//                {std::make_shared<command_factory::CommandFactory<commands::Sub>>(),               Args::NONE,     std::regex("SUB|sub")},
//                {std::make_shared<command_factory::CommandFactory<commands::Mul>>(),               Args::NONE,     std::regex("MUL|mul")},
//                {std::make_shared<command_factory::CommandFactory<commands::Div>>(),               Args::NONE,     std::regex("DIV|div")},
//                {std::make_shared<command_factory::CommandWithLabelFactory<commands::Label>>(),    Args::NAME,     std::regex("[a-zA-Z_][a-zA-Z0-9_]*:")},
//                {std::make_shared<command_factory::CommandWithLabelFactory<commands::Jmp>>(),      Args::LABEL,    std::regex("JMP|jmp")},
//                {std::make_shared<command_factory::CommandWithLabelFactory<commands::Jeq>>(),      Args::LABEL,    std::regex("JEQ|jeq")},
//                {std::make_shared<command_factory::CommandWithLabelFactory<commands::Jne>>(),      Args::LABEL,    std::regex("JNE|jne")},
//                {std::make_shared<command_factory::CommandWithLabelFactory<commands::Ja>>(),       Args::LABEL,    std::regex("JA|ja")},
//                {std::make_shared<command_factory::CommandWithLabelFactory<commands::Jae>>(),      Args::LABEL,    std::regex("JAE|jae")},
//                {std::make_shared<command_factory::CommandWithLabelFactory<commands::Jb>>(),       Args::LABEL,    std::regex("JB|jb")},
//                {std::make_shared<command_factory::CommandWithLabelFactory<commands::Jbe>>(),      Args::LABEL,    std::regex("JBE|jbe")},
//                {std::make_shared<command_factory::CommandWithLabelFactory<commands::Call>>(),     Args::LABEL,    std::regex("CALL|call")},
//                {std::make_shared<command_factory::CommandFactory<commands::Ret>>(),               Args::NONE,     std::regex("RET|ret")},
        };

        std::regex value_regex_ = std::regex("[-+]?[0-9]+");
        std::regex label_regex_ = std::regex("[a-zA-Z_][a-zA-Z0-9_]*");
        std::map<Register, std::regex> register_regex_ = {
                {Register::ax, std::regex("[aA][xX]")},
                {Register::bx, std::regex("[bB][xX]")},
                {Register::cx, std::regex("[cC][xX]")},
                {Register::dx, std::regex("[dD][xX]")},
                {Register::sp, std::regex("[sS][pP]")},
                {Register::bp, std::regex("[bB][pP]")},
        };

    public :
        explicit Parser(std::ifstream &);

//        Parser & SkipSpaces();
        bool IsEmpty();

        std::shared_ptr<commands::ICommand> ParseCommand();

        Register ParseRegister();

        int ParseValue();

        std::string ParseLabel();

    };
}
#endif //CPU_EMULATOR_PARSER_H

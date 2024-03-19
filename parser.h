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

    template<class Command>
    concept TemplateCommand = std::is_base_of<commands::ICommand, Command>::value;

    template<class Arg=void>
    class ICommandFactory {
    public:
        virtual std::shared_ptr<commands::ICommand> create(Arg arg);
    };

    template<>
    class ICommandFactory<void>{
    public:
        virtual std::shared_ptr<commands::ICommand> create();
    };


    template<TemplateCommand Command, class Arg = void>
    class CommandFactory : public ICommandFactory<Arg> {
    public:
        std::shared_ptr<commands::ICommand> create(Arg arg) override;
    };

    template<TemplateCommand Command>
    class CommandFactory<Command, void> : public ICommandFactory<void> {
    public:
        std::shared_ptr<commands::ICommand> create() override;
    };

    template<TemplateCommand Command, class Arg=void>
    std::shared_ptr<ICommandFactory<Arg>> GetFactory(){
        return std::make_shared<CommandFactory<Command, Arg>>();
    }


    typedef std::istream_iterator<std::string> file_iterator;


    template<class Arg>
    struct CommandDirector {
        std::shared_ptr<ICommandFactory<Arg>> factory;
        std::regex regex;
        bool declaration = false;
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

    class Parser {
    private:
        file_iterator input_;

//        std::vector<CommandDirector<std::string>> director_with_label_{
////                {std::shared_ptr<command_factory::CommandFactory<commands::Label, std::string>>(), std::regex("[a-zA-Z_][a-zA-Z0-9_]*:"), /*name of the label is its own arg*/ true},
//                {GetFactory<commands::Label, std::string>(),  std::regex("[a-zA-Z_][a-zA-Z0-9_]*:"), /*name of the label is its own arg*/ true},
////                {command_factory::GetFactory<commands::Jmp, std::string>(),  std::regex("JMP|jmp")},
////                {command_factory::GetFactory<commands::Jeq, std::string>(),  std::regex("JEQ|jeq")},
////                {command_factory::GetFactory<commands::Jne, std::string>(),  std::regex("JNE|jne")},
////                {command_factory::GetFactory<commands::Ja, std::string>(),  std::regex("JA|ja")},
////                {command_factory::GetFactory<commands::Jae, std::string>(),  std::regex("JAE|jae")},
////                {command_factory::GetFactory<commands::Jb, std::string>(), std::regex("JB|jb")},
////                {command_factory::GetFactory<commands::Jbe, std::string>(),    std::regex("JBE|jbe")},
////                {command_factory::GetFactory<commands::Call, std::string>(),    std::regex("CALL|call")},
//        };
        std::vector<CommandDirector<std::string>> director_with_label_{
//                {std::shared_ptr<command_factory::CommandFactory<commands::Label, std::string>>(), std::regex("[a-zA-Z_][a-zA-Z0-9_]*:"), /*name of the label is its own arg*/ true},
//                {GetFactory<commands::Label, std::string>(), std::regex("[a-zA-Z_][a-zA-Z0-9_]*:"), /*name of the label is its own arg*/ true},
                {GetFactory<commands::Jmp, std::string>(),   std::regex("JMP|jmp")},
                {GetFactory<commands::Jeq, std::string>(),   std::regex("JEQ|jeq")},
                {GetFactory<commands::Jne, std::string>(),   std::regex("JNE|jne")},
                {GetFactory<commands::Ja, std::string>(),    std::regex("JA|ja")},
                {GetFactory<commands::Jae, std::string>(),   std::regex("JAE|jae")},
                {GetFactory<commands::Jb, std::string>(),    std::regex("JB|jb")},
                {GetFactory<commands::Jbe, std::string>(),   std::regex("JBE|jbe")},
                {GetFactory<commands::Call, std::string>(),  std::regex("CALL|call")},

        };


        std::vector<CommandDirector<void>> director_{
                {GetFactory<commands::Begin>(),  std::regex("BEGIN|BEG|begin|beg")},
                {GetFactory<commands::End>(),  std::regex("END|end")},
                {GetFactory<commands::In>(),  std::regex("IN|in")},
                {GetFactory<commands::Out>(),  std::regex("OUT|out")},
                {GetFactory<commands::Add>(),  std::regex("ADD|add")},
                {GetFactory<commands::Sub>(),  std::regex("SUB|sub")},
                {GetFactory<commands::Mul>(),  std::regex("MUL|mul")},
                {GetFactory<commands::Div>(),  std::regex("DIV|div")},
                {GetFactory<commands::Pop>(),  std::regex("POP|pop")},
                {GetFactory<commands::Ret>(),  std::regex("RET|ret")}
//                {command_factory::GetFactory<commands::End>(),  std::regex("END|end")},
//                {command_factory::GetFactory<commands::In>(),  std::regex("IN|in")},
//                {command_factory::GetFactory<commands::Out>(),  std::regex("OUT|out")},
//                {command_factory::GetFactory<commands::Add>(),  std::regex("ADD|add")},
//                {command_factory::GetFactory<commands::Sub>(),  std::regex("SUB|sub")},
//                {command_factory::GetFactory<commands::Mul>(),  std::regex("MUL|mul")},
//                {command_factory::GetFactory<commands::Div>(),  std::regex("DIV|div")},
//                {command_factory::GetFactory<commands::Ret>(),  std::regex("RET|ret")}
        };

        std::vector<CommandDirector<int>> director_with_value_{
                {GetFactory<commands::Push, int>(),     std::regex("PUSH|push")},
        };

        std::vector<CommandDirector<Register>> director_with_register_{
                {GetFactory<commands::Popr, Register>(),  std::regex("POPR|popr")},
                {GetFactory<commands::Pushr, Register>(), std::regex("PUSHR|pushr")},
//                {command_factory::GetFactory<commands::Pushr, Register>(), std::regex("PUSHR|pushr")},
        };

        std::regex value_regex_ = std::regex("[-+]?[0-9]+");
        std::regex label_regex_ = std::regex("[a-zA-Z_][a-zA-Z0-9_]*[:]?");
        std::map<Register, std::regex> register_regex_ = {
                {Register::ax, std::regex("[aA][xX]")},
                {Register::bx, std::regex("[bB][xX]")},
                {Register::cx, std::regex("[cC][xX]")},
                {Register::dx, std::regex("[dD][xX]")},
                {Register::sp, std::regex("[sS][pP]")},
                {Register::bp, std::regex("[bB][pP]")},
        };

        Register ParseRegister();

        int ParseValue();

    public :
        explicit Parser(std::ifstream &);

        bool IsEmpty();

        std::shared_ptr<commands::ICommand> ParseCommand();

        std::string ParseLabel();
    };
}
#endif //CPU_EMULATOR_PARSER_H

#ifndef CPU_EMULATOR_PARSER_H
#define CPU_EMULATOR_PARSER_H

#include <string>
#include <vector>
#include <regex>
#include <iterator>
#include <map>
#include <fstream>


#include "state.h"
#include "commands.h"


namespace cpu_emulator::parser {
    typedef std::istream_iterator<std::string> file_iterator;
    template<class Command>
    concept TemplateCommand = std::is_base_of<commands::ICommand, Command>::value;

    class ICommandBuilder {
    protected:
        std::shared_ptr<State> state_;
        std::shared_ptr<file_iterator> input_;
    public:
        ICommandBuilder() = default;
        explicit ICommandBuilder(std::shared_ptr<file_iterator> &);

        virtual ICommandBuilder &setArgs();

        virtual ICommandBuilder &setState(std::shared_ptr<State> &);

        virtual std::unique_ptr<commands::ICommand> build();

    };

    template<TemplateCommand Command>
    class CommandBuilder : public ICommandBuilder {
    public:
        CommandBuilder() = default;
        explicit CommandBuilder(std::shared_ptr<file_iterator> &);


        CommandBuilder<Command> &setArgs() override;

        CommandBuilder<Command> &setState(std::shared_ptr<State> &) override;

        std::unique_ptr<commands::ICommand> build() override;
    };

    template<TemplateCommand Command>
    class CommandWithValueBuilder : public ICommandBuilder {
    private:
        std::regex value_regex_ = std::regex("[-+]?[0-9]+");
        int value_ = 0;
    public:
        CommandWithValueBuilder() = default;
        explicit CommandWithValueBuilder(std::shared_ptr<file_iterator> &);


        CommandWithValueBuilder<Command> &setArgs() override;

        CommandWithValueBuilder<Command> &setState(std::shared_ptr<State> &) override;

        std::unique_ptr<commands::ICommand> build() override;
    };

    template<TemplateCommand Command>
    class CommandWithRegisterBuilder : public ICommandBuilder {
    private:
        Register reg_ = Register::ax;
        std::map<Register, std::regex> register_regex_ = {
                {Register::ax, std::regex("[aA][xX]")},
                {Register::bx, std::regex("[bB][xX]")},
                {Register::cx, std::regex("[cC][xX]")},
                {Register::dx, std::regex("[dD][xX]")},
                {Register::ex, std::regex("[eE][xX]")},
                {Register::fx, std::regex("[fF][xX]")},
                {Register::gx, std::regex("[gG][xX]")},
                {Register::hx, std::regex("[hH][xX]")},
        };
    public:
        CommandWithRegisterBuilder() = default;
        explicit CommandWithRegisterBuilder(std::shared_ptr<file_iterator> &);


        CommandWithRegisterBuilder<Command> &setArgs() override;

        CommandWithRegisterBuilder<Command> &setState(std::shared_ptr<State> &) override;

        std::unique_ptr<commands::ICommand> build() override;
    };

    template<TemplateCommand Command>
    class CommandWithLabelBuilder : public ICommandBuilder {
    private:
        std::string label_;
        std::regex label_regex_ = std::regex("[a-zA-Z_][a-zA-Z0-9_]*");
    public:
        CommandWithLabelBuilder() = default;
        explicit CommandWithLabelBuilder(std::shared_ptr<file_iterator> &);


        CommandWithLabelBuilder<Command> &setArgs() override;

        CommandWithLabelBuilder<Command> &setState(std::shared_ptr<State> &) override;

        std::unique_ptr<commands::ICommand> build() override;
    };

    struct CommandRegex {
        std::shared_ptr<ICommandBuilder> builder;
        std::regex regex;
    };


    class Parser {
    private:
        std::istream_iterator<std::string> input_;
        std::smatch last_match_;
        std::vector<CommandRegex> command_regex_ = {
                {std::make_unique<CommandBuilder<commands::Begin>>(), std::regex("BEGIN|BEG|begin|beg")},
                {std::make_unique<CommandBuilder<commands::End>>(), std::regex("END|end")},
                {std::make_unique<CommandWithValueBuilder<commands::Push>>(), std::regex("PUSH|push")},
                {std::make_unique<CommandBuilder<commands::Pop>>(), std::regex("POP|pop")},
                {std::make_unique<CommandWithRegisterBuilder<commands::Pushr>>(), std::regex("PUSHR|pushr")},
                {std::make_unique<CommandWithRegisterBuilder<commands::Popr>>(), std::regex("POPR|popr")}

        };
        std::regex value_regex_ = std::regex("[-+]?[0-9]+");
        std::regex register_regex_ = std::regex("[a-hA-H][xX]");
        std::regex label_regex_ = std::regex("[a-zA-Z_][a-zA-Z0-9_]*");

    public :
        explicit Parser(std::ifstream &);
//        Parser & SkipSpaces();
        std::shared_ptr<ICommandBuilder> ParseCommand();

        Register ParseRegister();

        int ParseValue();

    };

//    class IParser;
//
////    template<class Command>
////    class CommandParser: public IParser;
//
//    class IParser{
//    private:
//        std::vector<CommandRegex> command_regex_; = {
//                {std::make_unique<CommandParser<commands::Begin>>(), std::regex("BEGIN|BEG|begin|beg")},
//                {std::make_unique<CommandBuilder<commands::End>>(), std::regex("END|end")},
//                {std::make_unique<CommandWithValueBuilder<commands::Push>>(), std::regex("PUSH|push")},
//                {std::make_unique<CommandBuilder<commands::Pop>>(), std::regex("POP|pop")},
//                {std::make_unique<CommandWithRegisterBuilder<commands::Pushr>>(), std::regex("PUSHR|pushr")},
//                {std::make_unique<CommandWithRegisterBuilder<commands::Popr>>(), std::regex("POPR|popr")}
//
//        };
//    protected:
//        std::shared_ptr<file_iterator> input_;
//        std::regex register_regex_ = std::regex("[a-hA-H][xX]");
//        std::regex label_regex_ = std::regex("[a-zA-Z_][a-zA-Z0-9_]*");
//    public:
//        explicit IParser(std::ifstream &);
//        explicit IParser(std::shared_ptr<file_iterator> &);
//
//
//        virtual IParser & ParseArgs();
//        virtual IParser & ParseCommand();
//        virtual std::unique_ptr<commands::ICommand> BuildCommand();
//    };
//
//    template<class Command>
//    class CommandParser : public IParser{
//        explicit CommandParser(std::ifstream &);
//        explicit CommandParser(std::shared_ptr<file_iterator> &);
//
//
//        CommandParser<Command> & ParseArgs() override;
//        CommandParser<Command> & ParseCommand() override;
//        std::unique_ptr<commands::ICommand> BuildCommand() override;
//    };
//
//    template<class Command>
//    class CommandWithValueParser : public IParser{
//    private:
//        std::regex value_regex_ = std::regex("[-+]?[0-9]+");
//        int value;
//    public:
//        explicit CommandWithValueParser(std::ifstream &);
//        explicit CommandWithValueParser(std::shared_ptr<file_iterator> &);
//
//
//        CommandWithValueParser<Command> & ParseArgs() override;
//        CommandWithValueParser<Command> & ParseCommand() override;
//        std::unique_ptr<commands::ICommand> BuildCommand() override;
//    };
}
#endif //CPU_EMULATOR_PARSER_H

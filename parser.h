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

//    typedef std::function<void()> DoCommand;

    template<class Command>
    concept TemplateCommand = std::is_base_of<commands::ICommand, Command>::value;


    class ICommandBuilder {
    protected:
//std::regex command_regex_;
        std::shared_ptr<State> state_;
    public:
//        explicit ICommandBuilder(const std::regex &);
        ICommandBuilder() = default;

//        virtual std::regex regex();
        virtual ICommandBuilder &setArgs();

        virtual ICommandBuilder &setState(std::shared_ptr<State> &);

        virtual std::unique_ptr<commands::ICommand> build();

    };

    template<TemplateCommand Command>
    class CommandBuilder : public ICommandBuilder {
    public:
        CommandBuilder() = default;

        CommandBuilder<Command> &setArgs() override;

        CommandBuilder<Command> &setState(std::shared_ptr<State> &) override;

        std::unique_ptr<commands::ICommand> build() override;
    };

    template<TemplateCommand Command>
    class CommandWithValueBuilder : public ICommandBuilder {
//    private:
//        Command command;
    private:
        int value_;
    public:
        CommandWithValueBuilder() = default;

        CommandWithValueBuilder<Command> &setArgs() override;

        CommandWithValueBuilder<Command> &setState(std::shared_ptr<State> &) override;

        std::unique_ptr<commands::ICommand> build() override;
    };

    template<TemplateCommand Command>
    class CommandWithRegisterBuilder : public ICommandBuilder {
    private:
        Register reg_;
    public:
        CommandWithRegisterBuilder() = default;

        CommandWithRegisterBuilder<Command> &setArgs() override;

        CommandWithRegisterBuilder<Command> &setState(std::shared_ptr<State> &) override;

        std::unique_ptr<commands::ICommand> build() override;
    };

    template<TemplateCommand Command>
    class CommandWithLabelBuilder : public ICommandBuilder {
    private:
        std::string label_;
    public:
        CommandWithLabelBuilder() = default;

        CommandWithLabelBuilder<Command> &setArgs() override;

        CommandWithLabelBuilder<Command> &setState(std::shared_ptr<State> &) override;

        std::unique_ptr<commands::ICommand> build() override;
    };

    struct CommandRegex{
        std::shared_ptr<ICommandBuilder> builder_;
        std::regex regex_;
//        std::shared_ptr<ICommandBuilder>
    };


    class Parser {
    private:
        std::istream_iterator<std::string> input_;
        std::smatch last_match_;
//                std::map<commands::ICommand, std::regex> c{
//                        {commands::Begin(), std::regex("BEGIN|BEG|begin|beg")},
//                {CommandType::END,   std::regex("END|end")},
//                {CommandType::PUSH,  std::regex("PUSH|push")},
//                {CommandType::POP,   std::regex("POP|pop")},
//                {CommandType::PUSHR, std::regex("PUSHR|pushr")},
//                {CommandType::POPR,  std::regex("POPR|popr")
//    };

//   auto a =  CommandBuilder<commands::Begin>(std::regex("BEGIN|BEG|begin|beg"));
//auto vec = std::vector<std::pair<std::unique_ptr<ICommandBuilder>, std::regex>>{
//std::make_pair(std::make_unique<CommandBuilder<commands::Begin>>(), std::regex("BEGIN|BEG|begin|beg")),
//std::make_pair(std::make_unique<CommandBuilder<commands::Begin>>(), std::regex("BEGIN|BEG|begin|beg")),
//std::make_pair(std::make_unique<CommandBuilder<commands::Begin>>(), std::regex("BEGIN|BEG|begin|beg")),
//}
////            std::make_pair<CommandBuilder<commands::Begin>, std::regex>(),
//

//std::vector<std::unique_ptr<ICommandBuilder>>{std::make_unique<CommandBuilder<commands::Begin>>(), std::make_unique<CommandBuilder<commands::Begin>>()}

//std::map<std::unique_ptr<
std::vector<CommandRegex> command_regex_ = {
                {std::make_unique<CommandBuilder<commands::Begin>>(), std::regex("BEGIN|BEG|begin|beg")}

};
//    std::map<std::shared_ptr<ICommandBuilder>, std::regex> command_regex_;
//                {ICommandBuilder(Args::VALUE, commands::Begin()), }
//                {std::make_unique<CommandBuilder<commands::Begin>>(), std::regex("BEGIN|BEG|begin|beg")}

//                std::make_unique<Builder<B>>()
//                {CommandBuilder<commands::End>(Args::NONE),   std::regex("END|end")},
//                {CommandBuilder<commands::Push>(Args::VALUE),  std::regex("PUSH|push")},
//                {CommandBuilder<commands::Pop>(Args::NONE),   std::regex("POP|pop")},
//                {CommandBuilder<commands::Pushr>(Args::REGISTER), std::regex("PUSHR|pushr")},
//                {CommandBuilder<commands::Popr>(Args::REGISTER),  std::regex("POPR|popr")}
//    };

    public :
    explicit Parser(std::ifstream &);

    std::shared_ptr<ICommandBuilder> ParseCommand();

    Register ParseRegister();

    int ParseValue();

};
}
#endif //CPU_EMULATOR_PARSER_H

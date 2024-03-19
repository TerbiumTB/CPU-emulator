#ifndef CPU_EMULATOR_COMMAND_FACTORY_H
#define CPU_EMULATOR_COMMAND_FACTORY_H

#include "commands.h"

namespace cpu_emulator::command_factory {

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

}

#endif //CPU_EMULATOR_COMMAND_FACTORY_H

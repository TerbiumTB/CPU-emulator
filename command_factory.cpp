#include "command_factory.h"

namespace cpu_emulator::command_factory {
    template<TemplateCommand Command, class Arg>
    std::shared_ptr<commands::ICommand> CommandFactory::create(Arg arg) {
        return std::make_shared<commands::ICommand>(Command(arg));
    }

    template<TemplateCommand Command>
    std::shared_ptr<commands::ICommand> CommandFactory::create() {
        return std::make_shared<commands::ICommand>(Command());
    }

//    template<class Command>
//    std::shared_ptr<commands::ICommand> CommandFactory::create<Command, void>() {
//        return std::make_shared<commands::ICommand>(Command());
//    }


//    template<class Command, class Arg>
//    std::shared_ptr<commands::ICommand> ICommandFactory::create<Command, Arg>(Arg arg) {
//        return std::make_shared<commands::ICommand>(Command(arg));
//    }


//    template<TemplateCommand Command, void>
//    std::shared_ptr<commands::ICommand> CommandFactory<Command, void>::create() {
//
//    }

//    template<TemplateCommand Command, class Arg>
//    std::shared_ptr<commands::ICommand> CommandFactory<Command, Arg>::create(Arg arg) {
//        return
//    }

/*    template<TemplateCommand Command>
    std::shared_ptr<Command> CommandFactory::create() {
        return std::make_shared<Command>();
    }

    template<TemplateCommand Command>
    std::shared_ptr<Command> CommandFactory::create(int value) {
        return std::make_shared<Command>(Command(value));
    }

    template<TemplateCommand Command>
    std::shared_ptr<Command> CommandFactory::create(Register reg) {
        return std::make_shared<Command>(Command(reg));
    }

    template<TemplateCommand Command>
    std::shared_ptr<Command> CommandFactory::create(const std::string &label) {
        return std::make_shared<Command>(Command(label));
    }*/

//    template<TemplateCommand Command>
//    std::shared_ptr<commands::ICommand> CommandFactory<Command>::create() {
//        return std::make_shared<Command>();
//    }
//
//    template<TemplateCommand Command>
//    std::shared_ptr<commands::ICommand> CommandWithValueFactory<Command>::create(int value) {
//        return std::make_shared<Command>(Command(value));
//    }
//
//    template<TemplateCommand Command>
//    std::shared_ptr<commands::ICommand> CommandWithRegisterFactory<Command>::create(Register reg) {
//        return std::make_shared<Command>(Command(reg));
//    }
//
//    template<TemplateCommand Command>
//    std::shared_ptr<commands::ICommand> CommandWithLabelFactory<Command>::create(const std::string &label) {
//        return std::make_shared<Command>(Command(label));
//    }
}
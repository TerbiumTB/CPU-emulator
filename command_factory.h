#ifndef CPU_EMULATOR_COMMAND_FACTORY_H
#define CPU_EMULATOR_COMMAND_FACTORY_H

#include "commands.h"

namespace cpu_emulator::command_factory {

    template<class Command>
    concept TemplateCommand = std::is_base_of<commands::ICommand, Command>::value;

//    template<TemplateCommand Command, void>
//    class CommandFactory{
//    public:
//
//        std::shared_ptr<Command> create(Arg);
//
////        template<TemplateCommand Command>
////        std::shared_ptr<Command> create(int);
////
////        template<TemplateCommand Command>
////        std::shared_ptr<Command> create(Register);
////
////        template<TemplateCommand Command>
////        std::shared_ptr<Command> create(const std::string &);
//
    //    };

    class ICommandFactory {
    public :
//        template<TemplateCommand Command, class Args>
////        std::shared_ptr<commands::ICommand> create(Args);
//        template<class Args>
//        std::shared_ptr<commands::ICommand> create(Args);

        std::shared_ptr<commands::ICommand> create(void);
        std::shared_ptr<commands::ICommand> create(int);
        std::shared_ptr<commands::ICommand> create(Register);
    };

    template<TemplateCommand Command, class T>
    class CommandFactory : public ICommandFactory{
        T arg;
    public:

    };


//    class ICommandFactory {
//    public:
//        auto set_args() {
//
//        }
//
//        virtual std::shared_ptr<commands::ICommand> create() { return {}; };
//
//        template<class Command, class Arg>
//        std::shared_ptr<commands::ICommand> create(Arg);
////        virtual std::shared_ptr<commands::ICommand> create(Register) { return {};};
////        virtual std::shared_ptr<commands::ICommand> create(const std::string &) { return {};};
//    };
//
//    template<TemplateCommand Command, class Arg=void>
//    class CommandFactory : public ICommandFactory {
//    public:
//        std::shared_ptr<commands::ICommand> create(Arg);
//    };
//
//    template<TemplateCommand Command>
//    class CommandFactory<Command, void> {
//    public:
//        std::shared_ptr<commands::ICommand> create();
//    };

//    class ICommandFactory {
//    public:
////        ICommandFactory() = default;
//
//        virtual ~ICommandFactory() = default;
//
//        virtual std::shared_ptr<commands::ICommand> create() { return std::make_unique<commands::ICommand>(); };
//
//        virtual std::shared_ptr<commands::ICommand> create(int) { return std::make_unique<commands::ICommand>(); };
//
//        virtual std::shared_ptr<commands::ICommand> create(Register) { return std::make_unique<commands::ICommand>(); };
//
//        virtual std::shared_ptr<commands::ICommand>
//        create(const std::string &) { return std::make_unique<commands::ICommand>(); };
//    };
//
////    template<TemplateCommand>
////    class CommandFactory : public ICommandFactory {
////    public:
//////        CommandFactory() = default;
////        std::shared_ptr<commands::ICommand> create() override;
////
////    };
//
//    template<TemplateCommand>
//    class CommandWithValueFactory : public ICommandFactory {
//    public:
////        CommandWithValueFactory() = default;
//
//        std::shared_ptr<commands::ICommand> create(int) override;
//    };
//
//    template<TemplateCommand>
//    class CommandWithRegisterFactory : public ICommandFactory {
//    public:
////        CommandWithRegisterFactory() = default;
//
//        std::shared_ptr<commands::ICommand> create(Register reg) override;
//    };
//
//    template<TemplateCommand>
//    class CommandWithLabelFactory : public ICommandFactory {
//    public:
////        CommandWithLabelFactory() = default;
//
//        std::shared_ptr<commands::ICommand> create(const std::string &) override;
//    };

}

#endif //CPU_EMULATOR_COMMAND_FACTORY_H

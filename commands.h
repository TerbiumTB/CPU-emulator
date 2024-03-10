#ifndef CPU_EMULATOR_COMMANDS_H
#define CPU_EMULATOR_COMMANDS_H

#include "state.h"

namespace cpu_emulator::commands {

//    template<class Command, typename Arg=int>
//    class ICommand {
//    protected:
//        std::shared_ptr<State> state_;
//    public :
//
//        Command &setState(std::shared_ptr<State> &);
//
//        virtual Command &setArgs(Arg);
//
//        virtual void DoIt();
//    };
//
//    class Begin : public ICommand<Begin> {
//
//        Begin & setArgs(int) override;
//        void DoIt() override;
//    };
//
//    class End : public ICommand<End> {
//        End & setArgs(int) override;
//        void DoIt() override;
//    };
//
//
//    class Push : public ICommand<Push> {
//    private:
//        int value_;
//    public:
//        Push & setArgs(int) override;
//
//        void DoIt() override;
//    };
//
//    class Pop : public ICommand {
//    public:
//        explicit Pop(std::shared_ptr<State> &);
//
//        void DoIt() override;
//    };
//
//    class Pushr : public ICommand {
//    private:
//        Register reg_;
//    public:
//        Pushr(std::shared_ptr<State> &, Register);
//
//        void DoIt() override;
//    };
//
//    class Popr : public ICommand {
//    private:
//        Register reg_;
//    public:
//        Popr(std::shared_ptr<State> &, Register);
//
//        void DoIt() override;
//    };
//    std::map<ArgType, Args> a{
//            {ArgType::LABEL, }
//    };

//    struct Args{
//        ArgType type;
//        std::variant<int, std::string, Register> value;
//    };


    class ICommand {
    protected:
        std::shared_ptr<State> state_;
    public :
        explicit ICommand(std::shared_ptr<State> &);
        virtual void DoIt() {};
        virtual ~ICommand() = default;
    };

    class Begin : public ICommand {

    public:

        explicit Begin(std::shared_ptr<State> &);

        void DoIt() override;
    };

//    class End : public ICommand {
//    public:
//        explicit End(std::shared_ptr<State> &);
//
//        void DoIt() override;
//    };
//
    class Push : public ICommand {
    private:
        int value_;
    public:
        Push(std::shared_ptr<State> &, int value);

        void DoIt() override;
    };
//
//    class Pop : public ICommand {
//    public:
//        explicit Pop(std::shared_ptr<State> &);
//
//        void DoIt() override;
//    };
//
//    class Pushr : public ICommand {
//    private:
//        Register reg_;
//    public:
//        Pushr(std::shared_ptr<State> &, Register);
//
//        void DoIt() override;
//    };
//
//    class Popr : public ICommand {
//    private:
//        Register reg_;
//    public:
//        Popr(std::shared_ptr<State> &, Register);
//
//        void DoIt() override;
//    };
}
#endif //CPU_EMULATOR_COMMANDS_H

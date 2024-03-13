#ifndef CPU_EMULATOR_COMMANDS_H
#define CPU_EMULATOR_COMMANDS_H

#include "state.h"

namespace cpu_emulator::commands {
    struct undefined_label_error : public std::invalid_argument {
        undefined_label_error() : std::invalid_argument("jump to an undefined label") {}
    };

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

    class End : public ICommand {
    public:
        explicit End(std::shared_ptr<State> &);

        void DoIt() override;
    };

    class Push : public ICommand {
    private:
        int value_;
    public:
        Push(std::shared_ptr<State> &, int value);

        void DoIt() override;
    };

    class Pop : public ICommand {
    public:
        explicit Pop(std::shared_ptr<State> &);

        void DoIt() override;
    };

    class Pushr : public ICommand {
    private:
        Register reg_;
    public:
        Pushr(std::shared_ptr<State> &, Register);

        void DoIt() override;
    };

    class Popr : public ICommand {
    private:
        Register reg_;
    public:
        Popr(std::shared_ptr<State> &, Register);

        void DoIt() override;
    };

    class In : public ICommand {
    public:
        explicit In(std::shared_ptr<State> &);

        void DoIt() override;
    };

    class Out : public ICommand {
    public:
        explicit Out(std::shared_ptr<State> &);

        void DoIt() override;
    };

    class Add : public ICommand {
    public:
        explicit Add(std::shared_ptr<State> &);

        void DoIt() override;
    };

    class Sub : public ICommand {
    public:
        explicit Sub(std::shared_ptr<State> &);

        void DoIt() override;
    };

    class Mul : public ICommand {
    public:
        explicit Mul(std::shared_ptr<State> &);

        void DoIt() override;
    };

    class Div : public ICommand {
    public:
        explicit Div(std::shared_ptr<State> &);

        void DoIt() override;
    };

    class Label : public ICommand {
    private:
        std::string label_;
    public:
        Label(std::shared_ptr<State> &, const std::string &);

        void DoIt() override;
    };

    class Jmp : public ICommand {
    protected:
        std::string label_;
        void Jump();
    public:
        Jmp(std::shared_ptr<State> &, const std::string &);

        void DoIt() override;
    };

    class Jeq : public Jmp {
    public:
        Jeq(std::shared_ptr<State> &, const std::string &);

        void DoIt() override;
    };

    class Jne : public Jmp {
    public:
        Jne(std::shared_ptr<State> &, const std::string &);

        void DoIt() override;
    };

    class Ja : public Jmp {
    public:
        Ja(std::shared_ptr<State> &, const std::string &);

        void DoIt() override;
    };

    class Jae : public Jmp {
    public:
        Jae(std::shared_ptr<State> &, const std::string &);

        void DoIt() override;
    };

    class Jb : public Jmp {
    public:
        Jb(std::shared_ptr<State> &, const std::string &);

        void DoIt() override;
    };

    class Jbe : public Jmp {
    public:
        Jbe(std::shared_ptr<State> &, const std::string &);

        void DoIt() override;
    };

}
#endif //CPU_EMULATOR_COMMANDS_H

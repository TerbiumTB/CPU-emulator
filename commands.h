#ifndef CPU_EMULATOR_COMMANDS_H
#define CPU_EMULATOR_COMMANDS_H

#include "state.h"
#include <vector>

namespace cpu_emulator::commands {
    struct undefined_label_error : public std::invalid_argument {
        undefined_label_error() : std::invalid_argument("jump to an undefined label") {}
    };

    class ICommand {
    public :
//        ICommand() = default;
        virtual ~ICommand() = default;

        virtual void DoIt(State &) {};
    };



    class Begin : public ICommand {
    public:
//        Begin() = default;
//        virtual std::vector<bool> Serialize() override;


        void DoIt(State &) override;
    };

    class End : public ICommand {
    public:
//        virtual std::vector<bool> Serialize() override;

//        End() = default;

        void DoIt(State &) override;
    };

    class Push : public ICommand {
    private:
        int value_;
    public:
//        virtual std::vector<bool> Serialize() override;

        explicit Push(int value);

        void DoIt(State &) override;
    };

    class Pop : public ICommand {
    public:
//        virtual std::vector<bool> Serialize() override;

//        Pop() = default;

        void DoIt(State &) override;
    };

    class Pushr : public ICommand {
    private:
        Register reg_;
    public:
        explicit Pushr(Register);

//        virtual std::vector<bool> Serialize() override;


        void DoIt(State &) override;
    };

    class Popr : public ICommand {
    private:
        Register reg_;
    public:
        explicit Popr(Register);
//        virtual std::vector<bool> Serialize() override;


        void DoIt(State &) override;
    };

    class In : public ICommand {
    public:
//        In() = default;
//        virtual std::vector<bool> Serialize() override;


        void DoIt(State &) override;
    };

    class Out : public ICommand {
    public:
//        Out() = default;
//        virtual std::vector<bool> Serialize() override;


        void DoIt(State &) override;
    };

    class Add : public ICommand {
    public:
//        Add() = default;
//        virtual std::vector<bool> Serialize() override;


        void DoIt(State &) override;
    };

    class Sub : public ICommand {
    public:
//        Sub() = default;
//        virtual std::vector<bool> Serialize() override;


        void DoIt(State &) override;
    };

    class Mul : public ICommand {
    public:
//        Mul() = default;
//        virtual std::vector<bool> Serialize() override;


        void DoIt(State &) override;
    };

    class Div : public ICommand {
    public:
//        Div() = default;
//        virtual std::vector<bool> Serialize() override;


        void DoIt(State &) override;
    };

    class Label : public ICommand {
    private:
        std::string label_;
    public:
        explicit Label(const std::string &);
//        virtual std::vector<bool> Serialize() override;


        void DoIt(State &) override;
    };

    class Jmp : public ICommand {
    protected:
        std::string label_;

        void Jump(State &);

    public:
        explicit Jmp(const std::string &);
//        virtual std::vector<bool> Serialize() override;


        void DoIt(State &) override;
    };

    class Jeq : public Jmp {
    public:
        explicit Jeq(const std::string &);
//        virtual std::vector<bool> Serialize() override;


        void DoIt(State &) override;
    };

    class Jne : public Jmp {
    public:
        explicit Jne(const std::string &);
//        virtual std::vector<bool> Serialize() override;


        void DoIt(State &) override;
    };

    class Ja : public Jmp {
    public:
        explicit Ja(const std::string &);
//        virtual std::vector<bool> Serialize() override;


        void DoIt(State &) override;
    };

    class Jae : public Jmp {
    public:
        explicit Jae(const std::string &);
//        virtual std::vector<bool> Serialize() override;


        void DoIt(State &) override;
    };

    class Jb : public Jmp {
    public:
        explicit Jb(const std::string &);
//        virtual std::vector<bool> Serialize() override;


        void DoIt(State &) override;
    };

    class Jbe : public Jmp {
    public:
        explicit Jbe(const std::string &);
//        virtual std::vector<bool> Serialize() override;


        void DoIt(State &) override;
    };

    class Call : public Jmp {
    public:
        explicit Call(const std::string &);
//        virtual std::vector<bool> Serialize() override;


        void DoIt(State &) override;
    };

    class Ret : public ICommand {
    public:
        Ret() = default;
//        virtual std::vector<bool> Serialize() override;


        void DoIt(State &) override;
    };

}
#endif //CPU_EMULATOR_COMMANDS_H

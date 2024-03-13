#include "commands.h"
#include "iostream"


namespace cpu_emulator::commands {
    ICommand::ICommand(std::shared_ptr<State> &state)
            : state_(state) {}


    //Begin------------------------------------
    Begin::Begin(std::shared_ptr<State> &state)
            : ICommand(state) {}


    void Begin::DoIt() {
        state_->run = Execution::STARTED;
    }
    //------------------------------------

    //End------------------------------------
    End::End(std::shared_ptr<State> &state)
            : ICommand(state) {}

    void End::DoIt() {
        state_->run = Execution::ENDED;
    }
    //------------------------------------

    //Push------------------------------------
    Push::Push(std::shared_ptr<State> &state, int value) : ICommand(state) {
        value_ = value;
    }

    void Push::DoIt() {
        if (state_->run == Execution::NOT_STARTED) return;

        state_->stack.push(value_);
    }
    //------------------------------------


    //Pop------------------------------------
    Pop::Pop(std::shared_ptr<State> &state)
            : ICommand(state) {}

    void Pop::DoIt() {
        if (state_->run == Execution::NOT_STARTED) return;

        state_->stack.pop();
    }
    //------------------------------------


    //Pushr------------------------------------
    Pushr::Pushr(std::shared_ptr<State> &state, Register reg)
            : ICommand(state), reg_(reg) {}

    void Pushr::DoIt() {
        if (state_->run == Execution::NOT_STARTED) return;

        state_->stack.push(state_->registers.at(reg_));
    }
    //------------------------------------


    //Popr------------------------------------
    Popr::Popr(std::shared_ptr<State> &state, Register reg)
            : ICommand(state), reg_(reg) {}

    void Popr::DoIt() {
        if (state_->run == Execution::NOT_STARTED) return;

        state_->registers.at(reg_) = state_->stack.pop();
    }
    //------------------------------------

    //In------------------------------------
    In::In(std::shared_ptr<State> &state)
            : ICommand(state) {}

    void In::DoIt() {
        if (state_->run == Execution::NOT_STARTED) return;

        int value;
        std::cout << "Input a value: ";
        std::cin >> value;

        state_->stack.push(value);
    }
    //------------------------------------

    //Out------------------------------------
    Out::Out(std::shared_ptr<State> &state)
            : ICommand(state) {}

    void Out::DoIt() {
        if (state_->run == Execution::NOT_STARTED) return;

        std::cout << state_->stack.pop() << std::endl;
    }
    //------------------------------------

    //Add------------------------------------
    Add::Add(std::shared_ptr<State> &state)
            : ICommand(state) {}

    void Add::DoIt() {
        if (state_->run == Execution::NOT_STARTED) return;

        auto top = state_->stack.pop();
        auto sum = top + state_->stack.top();

        state_->stack.push(top);
        state_->stack.push(sum);
    }
    //------------------------------------

    //Sub------------------------------------
    Sub::Sub(std::shared_ptr<State> &state)
            : ICommand(state) {}

    void Sub::DoIt() {
        if (state_->run == Execution::NOT_STARTED) return;

        auto top = state_->stack.pop();
        auto diff = top - state_->stack.top();

        state_->stack.push(top);
        state_->stack.push(diff);
    }
    //------------------------------------

    //Mul------------------------------------
    Mul::Mul(std::shared_ptr<State> &state)
            : ICommand(state) {}

    void Mul::DoIt() {
        if (state_->run == Execution::NOT_STARTED) return;

        auto top = state_->stack.pop();
        auto prod = top * state_->stack.top();

        state_->stack.push(top);
        state_->stack.push(prod);
    }
    //------------------------------------

    //Div------------------------------------
    Div::Div(std::shared_ptr<State> &state)
            : ICommand(state) {}

    void Div::DoIt() {
        if (state_->run == Execution::NOT_STARTED) return;

        auto top = state_->stack.pop();
        auto quot = top / state_->stack.top();

        state_->stack.push(top);
        state_->stack.push(quot);
    }
    //------------------------------------

    Label::Label(std::shared_ptr<State> &state, const std::string &label)
            : ICommand(state), label_(label.begin(), label.end() - 1) {}

    void Label::DoIt() {
        state_->labels[label_] = state_->pivot;
    }

    Jmp::Jmp(std::shared_ptr<State> &state, const std::string &label)
            : ICommand(state), label_(label) {}

    void Jmp::Jump() {
        if (!state_->labels.contains(label_))
            throw undefined_label_error();

        state_->pivot = state_->labels[label_];
    }
    void Jmp::DoIt() {
        Jump();
    }

    Jeq::Jeq(std::shared_ptr<State> &state, const std::string &label)
            : Jmp(state, label) {}

    void Jeq::DoIt() {
        auto top = state_->stack.pop();
        if (top == state_->stack.top()){
            Jump();
        }
        state_->stack.push(top);
    }

    Jne::Jne(std::shared_ptr<State> &state, const std::string &label)
            : Jmp(state, label) {}

    void Jne::DoIt() {
        auto top = state_->stack.pop();
        if (top != state_->stack.top()){
            Jump();
        }
        state_->stack.push(top);
    }

    Ja::Ja(std::shared_ptr<State> &state, const std::string &label)
            : Jmp(state, label) {}

    void Ja::DoIt() {
        auto top = state_->stack.pop();
        if (top > state_->stack.top()){
            Jump();
        }
        state_->stack.push(top);
    }

    Jae::Jae(std::shared_ptr<State> &state, const std::string &label)
            : Jmp(state, label) {}

    void Jae::DoIt() {
        auto top = state_->stack.pop();
        if (top >= state_->stack.top()){
            Jump();
        }
        state_->stack.push(top);
    }

    Jb::Jb(std::shared_ptr<State> &state, const std::string &label)
            : Jmp(state, label) {}

    void Jb::DoIt() {
        auto top = state_->stack.pop();
        if (top < state_->stack.top()){
            Jump();
        }
        state_->stack.push(top);
    }

    Jbe::Jbe(std::shared_ptr<State> &state, const std::string &label)
            : Jmp(state, label) {}

    void Jbe::DoIt() {
        auto top = state_->stack.pop();
        if (top <= state_->stack.top()){
            Jump();
        }
        state_->stack.push(top);
    }
}
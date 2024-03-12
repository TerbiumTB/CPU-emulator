#include "commands.h"


namespace cpu_emulator::commands {
    ICommand::ICommand(std::shared_ptr<State> &state)
            : state_(state) {}



    //Begin------------------------------------
    Begin::Begin(std::shared_ptr<State> &state)
            : ICommand(state) {}


    void Begin::DoIt() {
        state_->run=true;
    }
    //------------------------------------

    //End------------------------------------
    End::End(std::shared_ptr<State> &state)
            : ICommand(state) {}

    void End::DoIt() {
        state_->run=false;
    }
    //------------------------------------

    //Push------------------------------------
    Push::Push(std::shared_ptr<State> &state, int value) : ICommand(state) {
        value_ = value;
    }

    void Push::DoIt() {
        if (!state_->run) return;

        state_->stack.push(value_);
    }
    //------------------------------------


    //Pop------------------------------------
    Pop::Pop(std::shared_ptr<State> &state)
            : ICommand(state) {}

    void Pop::DoIt() {
        if (!state_->run) return;

        state_->stack.pop();
    }
    //------------------------------------


    //Pushr------------------------------------
    Pushr::Pushr(std::shared_ptr<State> &state, Register reg)
            : ICommand(state), reg_(reg) {}

    void Pushr::DoIt() {
        if (!state_->run) return;

        state_->stack.push(state_->registers.at(reg_));
    }
    //------------------------------------


    //Popr------------------------------------
    Popr::Popr(std::shared_ptr<State> &state, Register reg)
            : ICommand(state), reg_(reg) {}

    void Popr::DoIt() {
        if (!state_->run) return;

        state_->registers.at(reg_) = state_->stack.pop();
    }
    //------------------------------------

}
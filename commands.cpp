#include "commands.h"


namespace cpu_emulator::commands {

//    template<class Command>
//    Command &ICommand<Command>::setState(std::shared_ptr<State> & state) {
//        state_ = state;
//        return static_cast<Command>(*this);
//    }
//
//
//
//
//
//    template<class T = Begin>
//    T &Begin::setArgs() {
//
//    }
    ICommand::ICommand(std::shared_ptr<State> &state)
            : state_(state) {}

    Begin::Begin(std::shared_ptr<State> &state)
            : ICommand(state) {}


    void Begin::DoIt() {
        state_->run_=true;
    }

//    End::End(std::shared_ptr<State> &state)
//            : ICommand(state) {}
//
//    void End::DoIt() {
//        state_->run_=false;
//    }
//
    //Push------------------------------------
    Push::Push(std::shared_ptr<State> &state, int value) : ICommand(state) {
        value_ = value;
    }

    void Push::DoIt() {
        state_->stack_.push(value_);
    }
    //------------------------------------
//
//
//    //Pop------------------------------------
//    Pop::Pop(std::shared_ptr<State> &state)
//            : ICommand(state) {}
//
//    void Pop::DoIt() {
//        state_->stack_.pop();
//    }
//    //------------------------------------
//
//
//    //Pushr------------------------------------
//    Pushr::Pushr(std::shared_ptr<State> &state, Register reg)
//            : ICommand(state), reg_(reg) {}
//
//    void Pushr::DoIt() {
//        state_->stack_.push(state_->registers_.at(reg_));
//    }
//    //------------------------------------
//
//
//    //Popr------------------------------------
//    Popr::Popr(std::shared_ptr<State> &state, Register reg)
//            : ICommand(state), reg_(reg) {}
//
//    void Popr::DoIt() {
//        state_->registers_.at(reg_) = state_->stack_.pop();
//    }
//    //------------------------------------

}
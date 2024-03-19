#include "commands.h"
#include "iostream"
#include <bitset>
#include <utility>


namespace cpu_emulator::commands {

    //Begin------------------------------------
    void Begin::DoIt(State& state) {
        state.run = Execution::STARTED;
    }
    //------------------------------------

    //End------------------------------------
    void End::DoIt(State& state) {
        state.run = Execution::ENDED;
    }
    //------------------------------------

    //Push------------------------------------
//    std::vector<bool> Push::Serialize() {
//        auto x = std::bitset<32>(value_);
//        x[0];
//        for (auto const i: x){
//
//        }
//        std::vector<bool> serial = {0,0,0,0,1};
//        return {1,1,1,1,1};
//    }
    Push::Push(int value){
        value_ = value;
    }

    void Push::DoIt(State& state) {
        if (state.run == Execution::NOT_STARTED) return;

        state.stack.push(value_);
    }
    //------------------------------------


    //Pop------------------------------------
    void Pop::DoIt(State& state) {
        if (state.run == Execution::NOT_STARTED) return;

        state.stack.pop();
    }
    //------------------------------------


    //Pushr------------------------------------
    Pushr::Pushr(Register reg)
            : reg_(reg) {}

    void Pushr::DoIt(State& state) {
        if (state.run == Execution::NOT_STARTED) return;

        state.stack.push(state.registers.at(reg_));
    }
    //------------------------------------


    //Popr------------------------------------
    Popr::Popr(Register reg)
            : reg_(reg) {}
    void Popr::DoIt(State& state) {
        if (state.run == Execution::NOT_STARTED) return;

        state.registers.at(reg_) = state.stack.pop();
    }
    //------------------------------------

    //In------------------------------------
    void In::DoIt(State& state) {
        if (state.run == Execution::NOT_STARTED) return;

        int value;
        std::cout << "Input a value: ";
        std::cin >> value;

        state.stack.push(value);
    }
    //------------------------------------

    //Out------------------------------------
    void Out::DoIt(State& state) {
        if (state.run == Execution::NOT_STARTED) return;

        std::cout << state.stack.pop() << std::endl;
    }
    //------------------------------------

    //Add------------------------------------
    void Add::DoIt(State& state) {
        if (state.run == Execution::NOT_STARTED) return;

//        auto top = state.stack.pop();
//        auto sum = top + state.stack.top();
//
//        state.stack.push(top);
//        state.stack.push(sum);

state.stack.push(state.stack.pop() + state.stack.pop());
    }
    //------------------------------------

    //Sub------------------------------------
    void Sub::DoIt(State& state) {
        if (state.run == Execution::NOT_STARTED) return;

//        auto top = state.stack.pop();
//        auto diff = top - state.stack.top();
//
//        state.stack.push(top);
//        state.stack.push(diff);
state.stack.push(state.stack.pop() - state.stack.pop());
    }
    //------------------------------------

    //Mul------------------------------------
    void Mul::DoIt(State& state) {
        if (state.run == Execution::NOT_STARTED) return;

//        auto top = state.stack.pop();
//        auto prod = top * state.stack.top();
//
//        state.stack.push(top);
//        state.stack.push(prod);
state.stack.push(state.stack.pop() * state.stack.pop());
    }
    //------------------------------------

    //Div------------------------------------

    void Div::DoIt(State& state) {
        if (state.run == Execution::NOT_STARTED) return;

//        auto top = state.stack.pop();
//        auto quot = top / state.stack.top();
//
//        state.stack.push(top);
//        state.stack.push(quot);
state.stack.push(state.stack.pop() / state.stack.pop());
    }
    //------------------------------------

    Label::Label(const std::string &label)
            : label_(label.begin(), label.end() - 1) {}

    void Label::DoIt(State& state) {
        if (state.run == Execution::NOT_STARTED) return;

        state.labels[label_] = state.pivot;
    }

    Jmp::Jmp(std::string label): label_(std::move(label)) {}

    void Jmp::Jump(State& state) {
        if (state.run == Execution::NOT_STARTED) return;


        if (!state.labels.contains(label_))
            throw undefined_label_error();

        state.pivot = state.labels[label_]-1;
    }
    void Jmp::DoIt(State& state) {
        Jump(state);
    }

    Jeq::Jeq(const std::string &label)
            : Jmp(label) {}

    void Jeq::DoIt(State& state) {
        if (state.run == Execution::NOT_STARTED) return;

        auto top = state.stack.pop();
        if (top == state.stack.top()){
            Jump(state);
        }
        state.stack.push(top);
    }

    Jne::Jne(const std::string &label)
            : Jmp(label) {}

    void Jne::DoIt(State &state) {
        if (state.run == Execution::NOT_STARTED) return;

        auto top = state.stack.pop();
        if (top != state.stack.top()){
            Jump(state);
        }
        state.stack.push(top);
    }

    Ja::Ja(const std::string &label)
            : Jmp(label) {}

    void Ja::DoIt(State &state) {
        if (state.run == Execution::NOT_STARTED) return;

        auto top = state.stack.pop();
        if (top > state.stack.top()){
            Jump(state);
        }
        state.stack.push(top);
    }

    Jae::Jae(const std::string &label)
            : Jmp(label) {}

    void Jae::DoIt(State &state) {
        if (state.run == Execution::NOT_STARTED) return;

        auto top = state.stack.pop();
        if (top >= state.stack.top()){
            Jump(state);
        }
        state.stack.push(top);
    }

    Jb::Jb(const std::string &label)
            : Jmp(label) {}

    void Jb::DoIt(State &state) {
        if (state.run == Execution::NOT_STARTED) return;

        auto top = state.stack.pop();
        if (top < state.stack.top()){
            Jump(state);
        }
        state.stack.push(top);
    }

    Jbe::Jbe(const std::string &label)
            : Jmp(label) {}

    void Jbe::DoIt(State &state) {
        if (state.run == Execution::NOT_STARTED) return;

        auto top = state.stack.pop();
        if (top <= state.stack.top()){
            Jump(state);
        }
        state.stack.push(top);
    }

    Call::Call(const std::string &label)
            : Jmp(label) {}

    void Call::DoIt(State &state) {
        if (state.run == Execution::NOT_STARTED) return;

        state.previous_size.push(state.stack.size());
        state.previous_sp.push(state.pivot);
        Jump(state);
    }

    void Ret::DoIt(State &state) {
        if (state.run == Execution::NOT_STARTED) return;


        state.pivot =  state.previous_sp.pop();
        state.stack.resize(state.previous_size.pop());
    }
}
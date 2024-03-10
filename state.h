#ifndef CPU_EMULATOR_STATE_H
#define CPU_EMULATOR_STATE_H

#include <map>
#include <string>
#include "stack.h"

namespace cpu_emulator {
//    template<class T>
//    struct State{
//        generics::stack<T> stack_;
//        std::map<std::string, T> registers_ = {
//                {"ax", T()},
//                {"bx", T()},
//                {"cx", T()},
//                {"dx", T()},
//                {"ex", T()},
//                {"fx", T()},
//                {"gx", T()},
//                {"hx", T()},
//        };
//    };
    enum class Register {
        ax,
        bx,
        cx,
        dx,
        ex,
        fx,
        gx,
        hx
    };
    struct State {
        generics::stack<int> stack_;
        std::map<Register, int> registers_ = {
                {Register::ax, 0},
                {Register::bx, 0},
                {Register::cx, 0},
                {Register::dx, 0},
                {Register::ex, 0},
                {Register::fx, 0},
                {Register::gx, 0},
                {Register::hx, 0},
        };
        bool run_ = false;
    };
}

#endif //CPU_EMULATOR_STATE_H

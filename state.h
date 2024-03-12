#ifndef CPU_EMULATOR_STATE_H
#define CPU_EMULATOR_STATE_H

#include <map>
#include <string>
#include "stack.h"

namespace cpu_emulator {
//    template<class T>
//    struct State{
//        generics::stack<T> stack;
//        std::map<std::string, T> registers = {
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
    enum class Execution{
        NOT_STARTED,
        STARTED,
        ENDED
    };

    struct State {
        generics::stack<int> stack;
        std::map<Register, int> registers = {
                {Register::ax, 0},
                {Register::bx, 0},
                {Register::cx, 0},
                {Register::dx, 0},
                {Register::ex, 0},
                {Register::fx, 0},
                {Register::gx, 0},
                {Register::hx, 0},
        };
//        std::map<std::string, int> registers = {
//                {"ax", 0},
//                {"bx", 0},
//                {"cx", 0},
//                {"dx", 0},
//                {"ex", 0},
//                {"fx", 0},
//                {"gx", 0},
//                {"hx", 0},
//        };
        Execution run = Execution::NOT_STARTED;
        int start;
    };
}

#endif //CPU_EMULATOR_STATE_H

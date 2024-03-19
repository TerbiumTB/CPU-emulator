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
        sp,
        bp
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
                {Register::sp, 0},
                {Register::bp, 0},
        };
        std::map<std::string, int> labels;
        Execution run = Execution::NOT_STARTED;
        generics::stack<int>  previous_sp;
        generics::stack<int>  previous_size;
        int pivot = 0;
    };
}

#endif //CPU_EMULATOR_STATE_H

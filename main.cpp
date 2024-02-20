#include <iostream>
#include "stack.h"
#include "vector"



int main() {
    cpu_emulator::stack<std::vector<int>> vec_stack{};
    auto a = std::vector<int>();
    a.push_back(0);
    a.push_back(9);

    vec_stack.push(a);
    std::cout << a.front() << a.back();
    std::cout << vec_stack.top().back();

    cpu_emulator::stack<int> stack{};

    for (auto i = 0; i < 34; i++){
        stack.push(i);
    }

    auto stack2 = stack;
    stack2.push(10);
    stack2.pop();
    stack2.pop();
    stack2.pop();
    stack2.pop();


    std::cout << stack2.top();
    stack2.top() = 7;
    std::cout << stack2.top();
    return 0;
}


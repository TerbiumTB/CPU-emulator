#include <iostream>
#include <vector>
#include <type_traits>

#include "stack.h"
#include "cpu-emulator.h"

using namespace cpu_emulator;

template<class T=void>
class IA{
public:
    virtual std::unique_ptr<commands::ICommand> create(T a){
        return {};
    }
};

template<>
class IA<void>{
public:
    virtual std::unique_ptr<commands::ICommand> create(){
        return {};
    }
};
template<class U, class T=void>
class A: public IA<T>{
public:
    std::unique_ptr<commands::ICommand> create(T a) override{
        return std::make_unique<U>(U(a));
    }
};

template<class U>
class A<U, void>: public IA<void>{
public:
    std::unique_ptr<commands::ICommand> create() override{
        return std::make_unique<U>();
    }
};

template<class T, class U=void>
std::shared_ptr<IA<U>> GetA(){
    return std::make_shared<A<T, U>>();
}


int main(int argc, char *argv[]) {
//    auto x = std::make_shared<commands::Begin>();
//    std::cout << std::remove_pointer<decltype(x)>::type ;
//    auto f = command_factory::CommandFactory();
//    f.create<std::remove_pointer<decltype(x)>::type()>();

//    std::cout << argv[1];
//    auto emulator = CpuEmulator("/Users/timofejbulgakov/CLionProjects/CPU_emulator/fibonacci.crash");
//    auto emulator = CpuEmulator(argv[1]);
//std::vector<std::shared_ptr<IA<int>>> x{
//        GetA<commands::Push, int>(),
//        std::make_shared<A<commands::Push, int>>(),
//};
//    std::cout << x[0]->create(10);
//    std::cout << x[1]->create(1);
//    auto x = A<commands::Push, int>();
//    std::cout << x.create(10);
//    auto x = command_factory::CommandFactory<commands::Push, int>();
//    x.create(10);
int x = 10;


    CpuEmulator emulator{"factorial"};
    emulator.Run();
    return 0;
}


#include <gtest/gtest.h>
#include <vector>
#include "stack.h"


TEST(STACK, TEST1){
    auto stack1 = generics::stack<int>(12);
    for(int i = 0; i < 25; ++i){
        stack1.push(i);
    }
    EXPECT_EQ(24, stack1.pop());
}

TEST(STACK, TEST2){
    auto stack1 = generics::stack<std::vector<int>>(12);
    for(int i = 0; i < 25; ++i){
        stack1.push(std::vector({i, i, i}));
    }
    EXPECT_EQ(24, stack1.pop()[0]);
}
generics::stack<int> builder(int size){
    return generics::stack<int>(size);
}
TEST(STACK, TEST3){
    generics::stack<int> stack1;
    stack1 = generics::stack<int>(builder(70));
    generics::stack<int> stack2 = generics::stack<int>(stack1);;
    stack1.push(1);
    stack2 = stack1;
    stack1 = stack1;
    stack1.push(2);
    stack2.push(3);
    EXPECT_EQ(2, stack1.pop());
    EXPECT_EQ(3, stack2.pop());
    EXPECT_EQ(stack2.top(), stack1.top());
}

TEST(STACK, TEST4){
    generics::stack<std::vector<int>> stack1{};
    std::vector<int> vec({1, 1, 1});
    stack1.push(vec);
    auto stack2 = stack1;
    stack1 = generics::stack<std::vector<int>>();
    stack1.push(std::vector<int>({2,2,2}));
    EXPECT_EQ(std::vector<int>({2,2,2}), stack1.top());
    EXPECT_EQ(std::vector<int>({1,1,1}), stack2.pop());
}

TEST(STACK, TEST5){
    generics::stack<int> stack1{};

    //remember to rewrite it to cast expressions
    EXPECT_THROW(stack1.pop(), std::out_of_range);
    EXPECT_THROW(stack1.top(), std::out_of_range);
}
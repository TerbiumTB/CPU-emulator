#ifndef CPU_EMULATOR_STACK_H
#define CPU_EMULATOR_STACK_H

#include <utility>

namespace generics {
    struct empty_stack_access: public std::out_of_range{
        empty_stack_access() : std::out_of_range("stack is empty!") {};
    };

    template<typename T>
    class stack {
    private:
        T *stack_;
        int capacity_;
        int head_;

        void resize(int n) {
            T *ptr = new T[n];
            std::copy(stack_, stack_ + capacity_, ptr);
            delete [] stack_;
            stack_ = ptr;
        }

    public:
        explicit stack(int size = 32) : stack_(new T[size]) {
            capacity_ = size;
            head_ = -1;
        }

        ~stack() {
            delete[] stack_;
        }

        stack(stack &&other) noexcept: stack_(std::exchange(other.stack_, nullptr)) {
            capacity_ = other.capacity_;
            head_ = other.head_;
        }

        stack(const stack &other) : stack_(new T[other.capacity_]) {
            std::copy(other.stack_, other.stack_ + other.capacity_, stack_);
            capacity_ = other.capacity_;
            head_ = other.head_;
        }



        stack& operator=(const stack &other) {
            if(&other == this){
                return *this;
            }

            *this = stack{other};

            return *this;
        }

        stack &operator=(stack &&other) noexcept {
            std::swap(stack_, other.stack_);
            capacity_ = other.capacity_;
            head_ = other.head_;
            return *this;
        }

        [[nodiscard]] bool empty() const {
            return head_ == -1;
        }

        unsigned size() {
            return head_ + 1;
        }

        T &top() {
            if (empty()) {
                throw empty_stack_access();
            }
            return stack_[head_];
        }



        void push(T &&value) {
            head_++;
            stack_[head_] = value;

            if (size() == capacity_) {
                resize(capacity_ << 1);
            }
        }

        void push(const T &value) {
            push(std::move(T{value}));
        }

        const T &pop() {
            if (empty()) {
                throw empty_stack_access();
            }
            head_--;
            return stack_[head_ + 1];
        }

        void popn(int n) {
            if (head_ - n < 0){
                throw empty_stack_access();
            }
            head_ -= n;
        }
    };
}
#endif //CPU_EMULATOR_STACK_H
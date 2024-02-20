#ifndef CPU_EMULATOR_STACK_H
#define CPU_EMULATOR_STACK_H

#include <utility>

namespace cpu_emulator {
    template<typename T>
    class stack {
    private:
        T *stack_;
        int capacity_;
        int head_;

        void resize(int n) {
            T *ptr = new T[n];
            std::copy(stack_, stack_ + capacity_, ptr);
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

        stack(const stack &other) : stack_(new T[other.capacity_]) {
            std::copy(other.stack_, other.stack_ + other.capacity_, stack_);
            capacity_ = other.capacity_;
            head_ = other.head_;
        }

        stack(stack &&other) noexcept: stack_(std::exchange(other.stack_, nullptr)) {
            capacity_ = other.capacity_;
            head_ = other.head_;
        }

        stack &operator=(const stack &other) {
            return *this = stack(other);
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
                throw std::out_of_range("stack is empty!");
            }
            return stack_[head_];
        }

        void push(const T &value) {
            head_++;
            stack_[head_] = value;

            if (size() == capacity_) {
                resize(capacity_ << 1);
            }
        }

        void push(T &&value) { push(std::move(value));}

        const T &pop() {
            if (empty()) {
                throw std::out_of_range("stack is empty!");
            }
            head_--;
            return stack_[head_ + 1];
        }
    };
}
#endif //CPU_EMULATOR_STACK_H
#include <array>
#include <print>
#include <stdexcept>

class stack {
public:
    stack() = default;

    void push(int value) {
        if (size == capacity) {
            throw std::runtime_error("Stack is full");
        }
        data[size++] = value;
    }

    int pop() {
        if (size == 0) {
            throw std::runtime_error("Stack is empty");
        }
        return data[--size];
    }

    int top_item() const {
        if (size == 0) {
            throw std::runtime_error("Stack is empty");
        }
        return data[size - 1];
    }

    bool is_empty() const { return size == 0; }

    bool is_full() const { return size == capacity; }

private:
    static constexpr size_t capacity = 10;
    size_t size = 0;
    std::array<int, capacity> data{};
};

int main() {
    stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    std::print("{}\n", s.top_item());
    s.pop();
    std::print("{}\n", s.top_item());
    s.pop();
    std::print("{}\n", s.top_item());
    s.pop();
    std::print("{}\n", s.is_empty());
}

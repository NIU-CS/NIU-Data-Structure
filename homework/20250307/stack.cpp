#include <iostream>
#include <print>
#include <vector>

class stack {
public:
    stack() = default;

    void print() const {
        std::print("[");
        for (size_t i = 0; i < size; ++i) {
            std::print("{}", data[i]);
            if (i != size - 1) {
                std::print(", ");
            }
        }
        std::print("]\n");
    }

    void push(int value) {
        if (is_full()) {
            std::print("Stack is full\n");
            return;
        }
        data[size++] = value;
    }

    int pop() {
        if (is_empty()) {
            std::print("Stack is empty\n");
            return -1;  // 代表取消操作
        }
        return data[--size];
    }

    int top_item() const {
        if (is_empty()) {
            std::print("Stack is empty\n");
            return -1;
        }
        return data[size - 1];
    }

    bool is_empty() const { return size == 0; }

    bool is_full() const { return size == capacity; }

private:
    static constexpr size_t capacity = 10;
    size_t size = 0;
    std::vector<int> data{};
};

int choice() {
    int choice;
    std::print("1. push\n");
    std::print("2. pop\n");
    std::print("3. exit\n");
    std::print("choice: ");
    std::cin >> choice;
    return choice;
}

int main() {
    stack s;

    while (true) {
        std::print("\n");
        s.print();
        switch (choice()) {
            case 1:
                int value;
                std::print("Enter value: ");
                std::cin >> value;
                s.push(value);
                break;
            case 2:
                int popped;
                popped = s.pop();
                if (popped != -1) {  // 只有當 pop 成功時才印出數值
                    std::print("{}\n", popped);
                }
                break;
            case 3:
                return 0;
            default:
                std::print("Invalid choice\n");
        }
    }
}

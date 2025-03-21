#include <iostream>
#include <print>
#include <vector>

class queue {
public:
    queue() : front(0), rear(0), size(0) { data.resize(10); }

    void print() const {
        std::print("[");
        for (int i = 0; i < size; ++i) {
            std::print("{}", data[(front + i) % data.size()]);
            if (i != size - 1) {
                std::print(", ");
            }
        }
        std::print("]\n");
    }

    void enqueue(int value) {
        if (size == data.size()) {
            std::print("Queue is full\n");
            return;
        }
        data[rear] = value;
        rear = (rear + 1) % data.size();
        size++;
    }

    void dequeue() {
        if (size == 0) {
            std::print("Queue is empty\n");
            return;
        }
        front = (front + 1) % data.size();
        size--;
    }

    int front_element() {
        if (size == 0) {
            std::print("Queue is empty\n");
            return -1;
        }
        return data[front];
    }

    int rear_element() {
        if (size == 0) {
            std::print("Queue is empty\n");
            return -1;
        }
        return data[(rear - 1 + data.size()) % data.size()];
    }

private:
    int front = 0;
    int rear = 0;
    int size = 0;
    std::vector<int> data;
};

int choice() {
    int choice;
    std::print("1. enqueue\n");
    std::print("2. dequeue\n");
    std::print("3. exit\n");
    std::print("choice: ");
    std::cin >> choice;
    return choice;
}

int main() {
    queue q;

    while (true) {
        q.print();
        switch (choice()) {
            case 1:
                int value;
                std::print("value: ");
                std::cin >> value;
                q.enqueue(value);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                return 0;
            default:
                std::print("Invalid choice\n");
        }
    }

    return 0;
}

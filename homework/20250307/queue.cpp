#include <array>
#include <print>
#include <iostream>

class queue {
public:
    queue() : front(0), rear(0), size(0) {}

    void enqueue(int value) {
        if (size == data.size()) {
            std::cout << "Queue is full!" << std::endl;
            return;
        }
        data[rear] = value;
        rear = (rear + 1) % data.size();
        size++;
    }

    void dequeue() {
        if (size == 0) {
            std::cout << "Queue is empty!" << std::endl;
            return;
        }
        front = (front + 1) % data.size();
        size--;
    }

    int front_element() {
        if (size == 0) {
            std::cout << "Queue is empty!" << std::endl;
            return -1;
        }
        return data[front];
    }

    int rear_element() {
        if (size == 0) {
            std::cout << "Queue is empty!" << std::endl;
            return -1;
        }
        return data[(rear - 1 + data.size()) % data.size()];
    }

    int size() {
        return size;
    }

private:
    int front;
    int rear;
    int size;
    std::array<int, 10> data;

};

int main() {
    queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    std::cout << "Front element: " << q.front_element() << std::endl;
    std::cout << "Rear element: " << q.rear_element() << std::endl;
    std::cout << "Size: " << q.size() << std::endl;
    q.dequeue();
    std::cout << "Front element after dequeue: " << q.front_element() << std::endl;
    std::cout << "Rear element after dequeue: " << q.rear_element() << std::endl;
    std::cout << "Size after dequeue: " << q.size() << std::endl;
    return 0;
}

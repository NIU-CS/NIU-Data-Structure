#include <iostream>
#include <memory>

struct ListNode {
    int val;
    std::unique_ptr<ListNode> next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class LinkedList {
public:
    LinkedList() : head(nullptr) {}

    void push_front(int value) {
        auto new_node = std::make_unique<ListNode>(value);
        new_node->next = std::move(head);
        head = std::move(new_node);
    }

    void print() const {
        ListNode* current = head.get();
        while (current) {
            std::cout << current->val << " -> ";
            current = current->next.get();
        }
        std::cout << "nullptr" << std::endl;
    }

    void delete_node(int value) {
        if (!head) return;

        if (head->val == value) {
            head = std::move(head->next);
            return;
        }

        ListNode* current = head.get();
        while (current->next) {
            if (current->next->val == value) {
                current->next = std::move(current->next->next);
                return;
            }
            current = current->next.get();
        }
    }

    int pop_front() {
        if (!head) return -1; // 可以考慮改成例外處理
        int value = head->val;
        head = std::move(head->next);
        return value;
    }

    bool is_empty() const {
        return !head;
    }

    void push_back(int value) {
        auto new_node = std::make_unique<ListNode>(value);

        if (!head) {
            head = std::move(new_node);
            return;
        }

        ListNode* current = head.get();
        while (current->next) {
            current = current->next.get();
        }
        current->next = std::move(new_node);
    }

private:
    std::unique_ptr<ListNode> head;
};

class Queue {
public:
    void enqueue(int value) {
        data.push_back(value);
    }

    int dequeue() {
        if (data.is_empty()) {
            std::cout << "Queue is empty!" << std::endl;
            return -1;
        }
        return data.pop_front();
    }

    void print() {
        std::cout << "Queue: ";
        data.print();
    }

private:
    LinkedList data;
};

int choice() {
    int ans;
    std::cout << "\n1. enqueue\n2. dequeue\n3. Exit\nchoice: ";
    std::cin >> ans;
    return ans;
}

int main() {
    Queue queue;
    int ch, value;

    while (true) {
        queue.print();
        ch = choice();
        if (ch == 3) break;
        if (ch == 1) {
            std::cout << "Data: ";
            std::cin >> value;
            queue.enqueue(value);
        }
        if (ch == 2) {
            int result = queue.dequeue();
            if (result != -1) {
                std::cout << "Dequeued: " << result << std::endl;
            }
        }
    }

    return 0;
}

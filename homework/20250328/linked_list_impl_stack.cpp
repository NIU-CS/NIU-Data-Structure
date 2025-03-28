#include <iostream>
#include <memory>
#include <vector>

struct ListNode {
    int val;
    std::unique_ptr<ListNode> next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class LinkedList {
public:
    LinkedList() : head(nullptr) {}

    // 新增節點到鏈結串列的開頭
    void push_front(int value) {
        auto new_node = std::make_unique<ListNode>(value);
        new_node->next = std::move(head);
        head = std::move(new_node);
    }

    // 列印鏈結串列
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
        if (!head) return -1;
        int value = head->val;
        head = std::move(head->next);
        return value;
    }

    bool is_empty() const {
        return !head;
    }

private:
    std::unique_ptr<ListNode> head;
};

class Stack {
public:
    void push(int value) {
        data.push_front(value);
    }

    int pop() {
        if (data.is_empty()) {
            std::cout << "Stack is empty" << std::endl;
            return -1;
        }
        int value = data.pop_front();
        return value;
    }

    void print() {
        this->data.print();
        return;
    }

private:
    LinkedList data;
};

int choice(void) {
    int ans;
    std::cout << "1.push\n" << "2.pop\n" << "3.Exit\n" << "choice:";
    std::cin >> ans;
    return ans;
}

int main() {
    Stack stack;

    int ch, data;
    while (true) {
        stack.print();
        ch = choice();
        if (ch == 3) break;
        if (ch == 1) {
            std::cout << "Data:";
            std::cin >> data;
            stack.push(data);
        }
        if (ch == 2) data = stack.pop();
    }

    return 0;
}

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

private:
    std::unique_ptr<ListNode> head;
};

int main() {
    LinkedList list;
    list.push_front(3);
    list.push_front(2);
    list.push_front(1);
    list.print();
    return 0;
}

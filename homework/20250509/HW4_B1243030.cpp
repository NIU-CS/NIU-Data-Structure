#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <memory>

// 節點結構
struct Node {
    int data;
    std::unique_ptr<Node> left;
    std::unique_ptr<Node> right;

    explicit Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// 二元搜尋樹類別
class BinarySearchTree {
private:
    std::unique_ptr<Node> root;

    // 遞迴插入節點
    std::unique_ptr<Node> insert(std::unique_ptr<Node> node, int data) {
        if (!node) return std::make_unique<Node>(data);
        if (data < node->data)
            node->left = insert(std::move(node->left), data);
        else if (data > node->data)
            node->right = insert(std::move(node->right), data);
        return node;
    }

    // 遞迴刪除節點
    std::unique_ptr<Node> remove(std::unique_ptr<Node> node, int data) {
        if (!node) return nullptr;
        if (data < node->data)
            node->left = remove(std::move(node->left), data);
        else if (data > node->data)
            node->right = remove(std::move(node->right), data);
        else {
            if (!node->left) return std::move(node->right);
            if (!node->right) return std::move(node->left);

            Node* minNode = findMin(node->right.get());
            node->data = minNode->data;
            node->right = remove(std::move(node->right), minNode->data);
        }
        return node;
    }

    // 找到最小值節點
    Node* findMin(Node* node) {
        while (node && node->left)
            node = node->left.get();
        return node;
    }

    // 遞迴搜尋節點
    bool search(Node* node, int data, int& comparisons) {
        if (!node) return false;
        comparisons++;
        if (data == node->data)
            return true;
        else if (data < node->data)
            return search(node->left.get(), data, comparisons);
        else
            return search(node->right.get(), data, comparisons);
    }

    // 中序遍歷 (排序)
    void inorder(Node* node, std::vector<int>& result) {
        if (!node) return;
        inorder(node->left.get(), result);
        result.push_back(node->data);
        inorder(node->right.get(), result);
    }

public:
    BinarySearchTree() : root(nullptr) {}

    void insert(int data) { root = insert(std::move(root), data); }
    void remove(int data) { root = remove(std::move(root), data); }
    bool search(int data, int& comparisons) { return search(root.get(), data, comparisons); }
    std::vector<int> sort() {
        std::vector<int> result;
        inorder(root.get(), result);
        return result;
    }
};

// 主程式
int main() {
    BinarySearchTree bst;
    int choice;

    // 建立二元搜尋樹
    std::cout << "Binary Search Tree Create\n1. File input\n2. Data input\nchoice: ";
    std::cin >> choice;

    if (choice == 1) {
        std::string filename;
        std::cout << "file name: ";
        std::cin >> filename;
        std::ifstream file(filename);
        if (file.is_open()) {
            int value;
            while (file >> value) {
                bst.insert(value);
            }
            file.close();
        } else {
            std::cerr << "Failed to open file.\n";
            return 1;
        }
    } else if (choice == 2) {
        std::cout << "data: ";
        std::cin.ignore();
        std::string line;
        getline(std::cin, line);
        std::stringstream ss(line);
        int value;
        while (ss >> value) {
            bst.insert(value);
        }
    } else {
        std::cerr << "Invalid choice.\n";
        return 1;
    }

    // 選單操作
    while (true) {
        std::cout << "\nBinary Search Tree\n1. insert\n2. delete\n3. find\n4. sort\nchoice: ";
        std::cin >> choice;

        if (choice == 1) {
            int value;
            std::cout << "data: ";
            std::cin >> value;
            bst.insert(value);
        } else if (choice == 2) {
            int value;
            std::cout << "data: ";
            std::cin >> value;
            bst.remove(value);
        } else if (choice == 3) {
            int value, comparisons = 0;
            std::cout << "data: ";
            std::cin >> value;
            if (bst.search(value, comparisons))
                std::cout << "Found " << value << ", spent " << comparisons << " comparisons\n";
            else
                std::cout << "Not found " << value << ", spent " << comparisons << " comparisons\n";
        } else if (choice == 4) {
            std::vector<int> sorted = bst.sort();
            std::cout << "data: ";
            for (const auto& val : sorted)
                std::cout << val << " ";
            std::cout << std::endl;
        } else {
            std::cerr << "Invalid choice.\n";
        }
    }

    return 0;
}

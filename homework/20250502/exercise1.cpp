#include <iostream>
#include <fstream>
#include <memory>
#include <string>

class TreeNode {
public:
    char data;
    std::unique_ptr<TreeNode> left;
    std::unique_ptr<TreeNode> right;

    TreeNode(char d) : data(d) {}
};

class BinaryTree {
public:
    std::unique_ptr<TreeNode> root;

    void buildFromFile(std::istream& in) {
        root = build(in);
    }

    void preorder() const {
        std::cout << "\n先序輸出結果為 => ";
        preorderTraversal(root.get());
        std::cout << std::endl;
    }

private:
    std::unique_ptr<TreeNode> build(std::istream& in) {
        char ch;
        if (!(in >> ch)) return nullptr;
        if (ch == '0') return nullptr;

        auto node = std::make_unique<TreeNode>(ch);
        node->left = build(in);
        node->right = build(in);
        return node;
    }

    void preorderTraversal(const TreeNode* node) const {
        if (!node) return;
        std::cout << node->data << ' ';
        preorderTraversal(node->left.get());
        preorderTraversal(node->right.get());
    }
};

int main() {
    std::ifstream fin("Tree.dat");
    if (!fin) {
        std::cerr << "無法開啟 Tree.dat 檔案！" << std::endl;
        return 1;
    }

    BinaryTree tree;
    tree.buildFromFile(fin);
    tree.preorder();

    return 0;
}
#include <iostream>
#include <fstream>
#include <memory>

class TreeNode {
public:
    char data;
    std::unique_ptr<TreeNode> left;
    std::unique_ptr<TreeNode> right;

    TreeNode(char d) : data(d) {}
};

class BinaryTree {
public:
    void buildFromFile(std::istream& in) {
        root = build(in);
    }

    void preorder() const {
        std::cout << "\n先序輸出結果為 => ";
        preorderTraversal(root.get());
        std::cout << '\n';
    }

    void inorder() const {
        std::cout << "中序輸出結果為 => ";
        inorderTraversal(root.get());
        std::cout << '\n';
    }

    void postorder() const {
        std::cout << "後序輸出結果為 => ";
        postorderTraversal(root.get());
        std::cout << '\n';
    }

private:
    std::unique_ptr<TreeNode> root;

    std::unique_ptr<TreeNode> build(std::istream& in) {
        char ch;
        if (!(in >> ch) || ch == '0') return nullptr;
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

    void inorderTraversal(const TreeNode* node) const {
        if (!node) return;
        inorderTraversal(node->left.get());
        std::cout << node->data << ' ';
        inorderTraversal(node->right.get());
    }

    void postorderTraversal(const TreeNode* node) const {
        if (!node) return;
        postorderTraversal(node->left.get());
        postorderTraversal(node->right.get());
        std::cout << node->data << ' ';
    }
};

int main() {
    std::ifstream fin("Tree.dat");
    if (!fin) {
        std::cerr << "無法開啟 Tree.dat 檔案！\n";
        return 1;
    }

    BinaryTree tree;
    tree.buildFromFile(fin);
    tree.preorder();
    tree.inorder();
    tree.postorder();

    return 0;
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <print>

// восстановить дерево по его массивному представлению
// считаем BST полным(у каждой вершины по два узла):
// для каждого 2*i-го элемента массива 2*i+1 - левый сын, 2*i+2 - правый сын
// далее сдвигаемся ещё на два индекса

struct Node {
    int val_;
    Node* left_;
    Node* right_;

    Node(int x) : val_{ x }, left_{}, right_{ nullptr } {
    }
};

void printTree(Node* node) {
    if (node == nullptr) {
        return;
    }

    printTree(node->left_);
    printTree(node->right_);

    std::println("{}", node->val_);
}

class Tree {
    Node* head{};
public:
    Tree(int x) {
        head = new Node(x);
    }

    Tree(Node* node) : head{ node } {}

    Node* getHead() const {
        return head;
    }

    ~Tree() {
        deleteTree(head);
    }

    void deleteTree(Node* node) {
        if (node == nullptr) {
            return;
        }

        deleteTree(node->left_);
        deleteTree(node->right_);

        delete node;
    }

    Tree(const Tree&) = delete;
    Tree& operator=(const Tree&) = delete;
};



Node* builtTree(std::vector<int>& vec, size_t i) {
    if (i >= vec.size()) {
        return nullptr;
    }

    Node* root = new Node(vec[i]);
    root->left_ = builtTree(vec, 2 * i + 1);
    root->right_ = builtTree(vec, 2 * i + 2);

    return root;
}


int main() {
    std::vector vec{8, 9, 11, 7, 16, 3, 1};

    Node* root = builtTree(vec, 0);

    Tree tree{ root }; // вызовется конструктор от root
    printTree(tree.getHead());
}
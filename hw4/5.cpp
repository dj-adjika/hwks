#include <iostream>

struct Node {
    int val;
    std::unique_ptr<Node> left;
    std::unique_ptr<Node> right;

    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool is_same(const Node* p, const Node* q) {
    if (!p && !q) { // оба null -> true
        return true;
    }

    if (!p || !q || p->val != q->val) {
        return false;
    }

    // рекурсивный спуск в левое и правое поддеревья
    return is_same(p->left.get(), q->left.get()) &&
        is_same(p->right.get(), q->right.get());
}

int main() {
    auto root1 = std::make_unique<Node>(1);
    root1->left = std::make_unique<Node>(2);
    root1->right = std::make_unique<Node>(3);

    auto root2 = std::make_unique<Node>(1);
    root2->left = std::make_unique<Node>(2);
    root2->right = std::make_unique<Node>(3);

    if (is_same(root1.get(), root2.get())) {
        std::cout << "ok" << std::endl;
    }
    else {
        std::cout << "error" << std::endl;
    }

    return 0;
}
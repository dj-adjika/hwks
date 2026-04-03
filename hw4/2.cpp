#include <print>
#include <vector>

// определить симметричность бинарного дерева
// я реализовал алгоритм DFS проверки: передаём указатель на корень, далее рекурсивно 
// вызываем функцию is_mirror(проверяющую совпадение зеркальных элементов)
// сравниваются node_l->left и node_r->right, node_l->right и node_r->left

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

bool is_mirror(Node* left, Node* right) {
    if (left == nullptr && right == nullptr) {
        return true;
    }
    else if (left == nullptr || right == nullptr) {
        return false;
    }

    return (left->val_ == right->val_) && is_mirror(left->left_, right->right_)
        && is_mirror(left->right_, right->left_);
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


    bool is_sym_dfs() const{
        if (head == nullptr){
            return true;
        }

        return is_mirror(head->left_, head->right_);
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
    std::vector vec{ 3, 8, 8, 9,  6, 6, 9};

    Node* root = builtTree(vec, 0);

    Tree tree{ root };
    //printTree(tree.getHead());
    std::println("{}", tree.is_sym_dfs());
}
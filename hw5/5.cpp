#include <print>
#include <cmath>

struct Node {
    int data;
    Node * left;
    Node * right;
    int balance_factor;

    Node(int value): data{value}, left{nullptr}, right{nullptr}, balance_factor{0}{}
};

int write_balance(Node * node){
    if (!node){
        return 0;
    }

    int l_height = write_balance(node->left);
    int r_height = write_balance(node->right);

    node->balance_factor = std::abs(l_height - r_height);

    return 1 + std::max(l_height, r_height);
}

int main(){
    Node head{12};
    head.left = new Node(5);
    head.right = new Node(15);
    head.right->right = new Node(20);
    head.right->left = new Node(13);
    head.right->left->right = new Node(14);

    std::println("{}", write_balance(&head));
}
#include <print>
#include <queue>

// рассмотрен пример отражения BST. 
// Также функция вывода дерева реализована, как LNR обход, в результате
// легко видеть, что дерево до отражения выводится по возрастанию, а после - по убыванию 

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) :data{ value }, right{ nullptr }, left{ nullptr } {}
};

void printTree(Node* node) {
    if (!node) {
        return;
    }

    printTree(node->left);
    std::println("{}", node->data);
    printTree(node->right);
}

void deleteTree(Node* node) {
    if (!node) {
        return;
    }

    deleteTree(node->left);
    deleteTree(node->right);

    delete node;
    node = nullptr;
}

Node* mirrorize(Node* node) {
    if (!node) {
        return nullptr;
    }

    std::queue<Node*> q;
    q.push(node);

    while (q.size() > 0) {
        Node* curr = q.front();
        q.pop();

        std::swap(curr->left, curr->right);

        if (curr->left) {
            q.push(curr->left);
        }

        if (curr->right) {
            q.push(curr->right);
        }
    }

    return node;
}

// также можно сделать рекурсивный вариант отражения:
void rec_mirrorize(Node* node) {
    if (!node) {
        return;
    }

    std::swap(node->left, node->right);
    rec_mirrorize(node->left);
    rec_mirrorize(node->right);

    return;
}

int main() {
    Node * head = new Node{12};
    head->left = new Node(5);
    head->right = new Node(15);
    head->right->right = new Node(20);
    head->right->left = new Node(13);
    head->right->left->right = new Node(14);

    printTree(head);
    std::println("Mirrorized:");
    //mirrorize(&head);
    rec_mirrorize(head);
    printTree(head);

    deleteTree(head);

    return 0;
}
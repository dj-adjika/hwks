#include <print>
#include <vector>
#include <algorithm>
#include <queue>

//         11
//        /  \
//       8    16
//      / \     \
//     2   9     6
//    /     \
//   7       9

// найти минимальную глубину дерева, здесь реализация с DFS, мы спускаемся
// рекурсивно вниз, пока не дойдём до nullptr в каком-то из листьев - это и будет минимальная высота

// 

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
    Node* root{};
public:
    Tree(): root{nullptr}{}

    Tree(int x) {
        root = new Node(x);
    }

    Tree(Node* node) : root{ node } {}

    Node* getroot() const {
        return root;
    }

    // Node* insertBST(Node* node, int val){
    //     if (node == nullptr){
    //         return new Node{val};
    //     }

    //     if (val < node->val_){
    //         node ->left_ = insertBST(node->left_, val);
    //     } else if (val > node->val_){
    //         node->right_ = insertBST(node->right_, val);
    //     } else {
    //         node->right_=insertBST(node->right_, val);
    //     }

    //     return node;
    // }

    // void insert(int val){ // обёртка для более удобного вызова
    //     root = insertBST(root, val);
    // }

    ~Tree() {
        deleteTree(root);
    }

    void deleteTree(Node* node) {
        if (node == nullptr) {
            return;
        }

        deleteTree(node->left_);
        deleteTree(node->right_);

        delete node;
    }

    // void createTree(std::vector<int>& vec){
    //     for (const auto& v: vec){
    //         insert(v);
    //     }
    // }

    int min_d(Node * node) {
        if (node == nullptr){
            return 0;
        } 

        if (node->left_ == nullptr && node->right_ == nullptr){
            return 1;
        } 
        
        if (node->left_!=nullptr && node->right_!=nullptr){
            return 1 + std::min(min_d(node->left_), min_d(node->right_));
        }

        if (node->left_!=nullptr){
            return 1+min_d(node->left_);
        } //else if (node->right_!=nullptr){
            return 1+min_d(node->right_);
        //}
    }

    int min_depth_dfs(){
        return min_d(root);
    }

    int min_bfs(Node* node){
        if (node == nullptr){
            return 0;
        }

        std::queue<std::pair<Node *, int>> q;
        q.push({root, 1});

        while (!q.empty()){
            auto [node, depth] = q.front();
            q.pop();

            if (node->left_==nullptr && node->right_==nullptr){
                return depth;
            }

            if (node->left_){
                q.push({node->left_, depth + 1});
            }
            if (node->right_) {
                q.push({node->right_, depth + 1});
            }

        }

        return 0;
    }

    int min_depth_bfs(){
        return min_bfs(root);
    }

    Tree(const Tree&) = delete;
    Tree& operator=(const Tree&) = delete;
};

// Node* builtTree(std::vector<int>& vec, size_t i) {
//     if (i >= vec.size()) {
//         return nullptr;
//     }

//     Node* root = new Node(vec[i]);
//     root->left_ = builtTree(vec, 2 * i + 1);
//     root->right_ = builtTree(vec, 2 * i + 2);

//     return root;
// }

int main() {
    std::vector<int> vec {11, 8, 16, 2, 9, 6, 7, 9};
    Tree tree{11};
    //tree.createTree(vec);
    //printTree(tree.getroot());
    tree.getroot()->left_ = new Node{8};
    tree.getroot()->left_->left_ = new Node{2};
    tree.getroot()->left_->left_->left_ = new Node{7};
    tree.getroot()->left_->right_ = new Node{9};
    tree.getroot()->left_->right_->right_ = new Node{9};
    tree.getroot()->right_ = new Node{16};
    tree.getroot()->right_->right_ = new Node{6};

    std::println("min depth dfs = {}", tree.min_depth_dfs());
    std::println("min depth bfs = {}", tree.min_depth_bfs());
}

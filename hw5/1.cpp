#include <iostream>
#include <queue>

// определить, является ли бинарное дерево полным
// используем BFS - обход в ширину

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool func(TreeNode* root) {
    if (!root) {
        return true;
    }
    
    std::queue<TreeNode*> q;
    q.push(root);
    bool seenNull = false;
    
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        
        if (!node) {
            seenNull = true;
        } else {
            if (seenNull){
                return false;
            }

            q.push(node->left);
            q.push(node->right);
        }
    }
    return true;
}
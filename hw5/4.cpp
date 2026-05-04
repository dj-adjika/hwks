#include <stack>

// нахождение минимального элемента 

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int ksmallBST(TreeNode* root, int k) {
    std::stack<TreeNode*> s;
    TreeNode* curr = root;
    int count = 0;
    
    while (curr || !s.empty()) {
        while (curr) {
            s.push(curr);
            curr = curr->left;
        }
        
        curr = s.top();
        s.pop();
        count++;

        if (count == k) {
            return curr->val;
        }
        
        curr = curr->right;
    }

    return -1; 
}
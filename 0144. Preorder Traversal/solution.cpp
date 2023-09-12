/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// Recursive Solution
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if (!root) return vector<int> {};

        auto rootTraverse = vector<int> {root->val};
        auto leftTraverse = preorderTraversal(root->left);
        auto rightTraverse = preorderTraversal(root->right);

        rootTraverse.insert(rootTraverse.end(), leftTraverse.begin(), leftTraverse.end());
        rootTraverse.insert(rootTraverse.end(), rightTraverse.begin(), rightTraverse.end());

        return rootTraverse;
    }
};

// Iterative
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if (!root) return vector<int> {};

        std::stack<TreeNode*> Stack;
        Stack.push(root);
        vector<int> res;

        while (!Stack.empty()){
            auto cur = Stack.top();
            res.push_back(cur->val);
            Stack.pop();

            if (cur->right) Stack.push(cur->right); 
            if (cur->left) Stack.push(cur->left);
        }

        return res;
    }
};
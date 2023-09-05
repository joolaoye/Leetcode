#define bool int
#define true 1
#define false 0

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

// Recursive Solution
bool isSameTree(struct TreeNode* p, struct TreeNode* q){
    if ((!p && q) || (p && !q)) return false;

    if (!(p || q)) return true;

    if (p->val != q->val) return false;

    bool left = isSameTree(p->left, q->left);

    bool right = isSameTree(p->right, q->right);

    return left && right;

}
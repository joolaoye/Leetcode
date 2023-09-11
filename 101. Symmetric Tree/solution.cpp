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
class Solution {
public:
    bool checksubtrees(TreeNode* nodeA, TreeNode* nodeB){
    if (!(nodeA || nodeB)) return true;
    if (!nodeA || !nodeB) return false;
    if (nodeA->val != nodeB->val) return false;

    return checksubtrees(nodeA->right, nodeB->left) && checksubtrees(nodeA->left,           nodeB->right);
}

    bool isSymmetric(TreeNode* root) {
        return checksubtrees(root->left, root->right);
    }
};
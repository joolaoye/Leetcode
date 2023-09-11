/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool checksubtrees(struct TreeNode* nodeA, struct TreeNode* nodeB){
    if (!(nodeA || nodeB)) return true;
    if (!nodeA || !nodeB) return false;
    if (nodeA->val != nodeB->val) return false;

    return checksubtrees(nodeA->right, nodeB->left) && checksubtrees(nodeA->left, nodeB->right);
}

bool isSymmetric(struct TreeNode* root){
    return checksubtrees(root->left, root->right);
}

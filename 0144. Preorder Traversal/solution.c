/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

// Populates array
void dfs(struct TreeNode* root, int* arr, int* returnSize){
    if (!root) return;

    arr[(*returnSize)++] = root->val;
    dfs(root->left, arr, returnSize);
    dfs(root->right, arr, returnSize);
}

// Returns the result
int* preorderTraversal(struct TreeNode* root, int* returnSize){
    int* Traverse = malloc(sizeof(int) * 100);
    *returnSize = 0;

    dfs(root, Traverse, returnSize);

    return Traverse;
}
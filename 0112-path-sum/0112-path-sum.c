/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool hasPathSum(struct TreeNode* root, int targetSum) {
    // ensure the tree is not empty
    if (root == NULL) {
        return false;
    }

    targetSum -= root->val;
    
    return (root->left == NULL && root->right == NULL)
        ? targetSum == 0 // leaf node 
        : hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum);
}
int dfs(struct TreeNode *root, int num) {
    int sum = 0;

    // update the number
    num += root->val;

    // visit the left subtree
    if (root->left) {
        sum += dfs(root->left, num * 10);
    }

    // visit the right subtree
    if (root->right) {
        sum += dfs(root->right, num * 10);
    }

    return (sum > 0)
        ? sum
        : num;
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int sumNumbers(struct TreeNode* root) {
    return dfs(root, 0);
}
bool dfs(struct TreeNode *left, struct TreeNode *right) {
    if (left == NULL) {
        return right == NULL;
    }
    else if (right == NULL) {
        return left == NULL;
    }

    return left->val == right->val
        && dfs(left->left, right->right)
        && dfs(left->right, right->left);
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSymmetric(struct TreeNode* root) {
    return dfs(root->left, root->right);
}
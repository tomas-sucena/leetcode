int dfs(struct TreeNode *root) {
    if (root == NULL) {
        return 0;
    }

    // compute the height of the left subtree
    int left = dfs(root->left);
    if (left < 0) return INT_MIN; // short-circuiting
    
    // compute the height of the right subtree
    int right = dfs(root->right);
    if (right < 0) return INT_MIN; // short-circuiting

    // compute the height difference
    int heightDiff, maxHeight;
    
    if (left > right) {
        maxHeight = left;
        heightDiff = left - right;
    }
    else {
        maxHeight = right;
        heightDiff = right - left;
    }

    return (heightDiff <= 1)
        ? 1 + maxHeight
        : INT_MIN;
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isBalanced(struct TreeNode* root) {
    return dfs(root) >= 0;
}
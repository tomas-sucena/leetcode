int max(int a, int b) {
    return (a > b)
        ? a
        : b;
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxDepth(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }

    // post-order traversal:
    // compute the depth of the subtrees and choose the maximum
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}
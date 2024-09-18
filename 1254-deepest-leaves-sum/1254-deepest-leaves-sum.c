void postorderDFS(struct TreeNode *node, int *sum, int level, int *maxLevel) {
    if (node == NULL) {
        return;
    }

    // visit the children
    postorderDFS(node->left, sum, level + 1, maxLevel);
    postorderDFS(node->right, sum, level + 1, maxLevel);

    if (level < *maxLevel) {
        return;
    }

    if (level > *maxLevel) {
        *maxLevel = level;
        *sum = 0;
    }
    
    *sum += node->val;
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int deepestLeavesSum(struct TreeNode* root) {
    int sum = 0, maxLevel = 0;
    
    postorderDFS(root, &sum, 0, &maxLevel);
    return sum;
}
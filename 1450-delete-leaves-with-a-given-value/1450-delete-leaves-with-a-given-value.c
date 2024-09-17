/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* removeLeafNodes(struct TreeNode* root, int target) {
    if (root == NULL) {
        return NULL;
    }

    root->left = removeLeafNodes(root->left, target);
    root->right = removeLeafNodes(root->right, target);

    // determine if the current node is a leaf to be removed
    // if so, delete it
    if (!root->left && !root->right && root->val == target) {
        free(root);
        root = NULL;
    }

    return root;
}
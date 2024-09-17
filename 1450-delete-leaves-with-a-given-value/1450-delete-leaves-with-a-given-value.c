/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* removeLeafNodes(struct TreeNode* root, int target) {
    if (!root) {
        return NULL;
    }

    bool toDelete = root->val == target;
    toDelete &= !(root->left = removeLeafNodes(root->left, target));
    toDelete &= !(root->right = removeLeafNodes(root->right, target));

    // determine if the current node is a leaf to be removed
    // if so, delete it
    if (toDelete) {
        free(root);
        root = NULL;
    }

    return root;
}
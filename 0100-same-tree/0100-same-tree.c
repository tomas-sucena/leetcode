/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    // verify if any of the trees is null
    if (p == NULL) {
        return q == NULL;
    }
    else if (q == NULL) {
        return p == NULL;
    }

    return p->val == q->val
        && isSameTree(p->left, q->left)     // verify if the left subtrees are equal
        && isSameTree(p->right, q->right);  // ensure the right subtrees are equal
}
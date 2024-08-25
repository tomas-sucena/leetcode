int *postorderDFS(struct TreeNode* root, int* returnSize, int *arr) {
    if (root == NULL) {
        return arr;
    }

    // visit the left subtree
    arr = postorderDFS(root->left, returnSize, arr);

    // visit the right subtree
    arr = postorderDFS(root->right, returnSize, arr);

    // append the value of the current node to the array
    int length = *returnSize;
    *returnSize += 1;

    arr[length] = root->val;

    return arr;
}

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
int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    int *ans = malloc(100 * sizeof(int));
    *returnSize = 0;

    postorderDFS(root, returnSize, ans);
    return ans;
}
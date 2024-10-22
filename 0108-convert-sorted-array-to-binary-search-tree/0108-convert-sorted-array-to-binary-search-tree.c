/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    // base case
    if (numsSize < 1) {
        return NULL;
    }

    int mid = numsSize / 2;

    // initialize the binary search tree
    struct TreeNode *tree = malloc(sizeof(struct TreeNode));

    // set the middle element of the array
    // as the root of the binary search tree
    tree->val = nums[mid];

    // recursively create the subtrees
    tree->left = sortedArrayToBST(nums, mid++);
    tree->right = sortedArrayToBST(nums + mid, numsSize - mid);

    return tree;
}
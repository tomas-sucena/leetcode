struct TreeNode* sortedArrayToBST(int *nums, int numsSize) {
    // base case
    if (numsSize < 1) {
        return NULL;
    }

    // initialize the BST
    struct TreeNode *tree = malloc(sizeof(struct TreeNode));
    
    // set the middle element of the array as the root
    // of the BST
    int mid = numsSize / 2;
    tree->val = nums[mid];

    // recursively create the subtrees
    tree->left = sortedArrayToBST(nums, mid++);
    tree->right = sortedArrayToBST(nums + mid, numsSize - mid);

    return tree;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* sortedListToBST(struct ListNode* head) {
    // convert the linked list to an array
    int arrSize = 8, listSize = 0;
    int *nums = malloc(arrSize * sizeof(int));

    for (; head; head = head->next) {
        // grow the array, if necessary
        if (arrSize == listSize) {
            nums = realloc(nums, (arrSize *= 2) * sizeof(int));
        }

        nums[listSize++] = head->val;
    }

    // convert the array to a BST
    return sortedArrayToBST(nums, listSize);
}
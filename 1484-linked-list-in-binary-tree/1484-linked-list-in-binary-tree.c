bool isValidPath(struct ListNode *head, struct TreeNode *root) {
    if (head == NULL) {
        return true;
    }

    // ensure the binary tree node is equal to the head of the linked list
    return root && head->val == root->val
        && (isValidPath(head->next, root->left)
        || isValidPath(head->next, root->right));
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool isSubPath(struct ListNode* head, struct TreeNode* root) {
    if (root == NULL) {
        return false;
    }

    // if the head of the binary tree equals the root of the binary tree,
    // verify if there is a downward path that meets the requirements
    return (head->val == root->val && isValidPath(head, root))
        || isSubPath(head, root->left)
        || isSubPath(head, root->right);
}
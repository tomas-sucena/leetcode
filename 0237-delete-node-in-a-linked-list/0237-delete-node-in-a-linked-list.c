/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteNode(struct ListNode* node) {
    struct ListNode *next = node->next;

    // replace the value of the node
    node->val = next->val;

    // move the value of each node
    // to the previous node
    while (next->next) {
        // advance the pointers
        node = next;
        next = next->next;
        
        // move the value
        node->val = next->val;
    }

    // remove the last node
    node->next = NULL;
}
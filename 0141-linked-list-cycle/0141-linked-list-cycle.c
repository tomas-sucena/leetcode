/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    // to avoid using a hash set to store the pointers,
    // simply modify each visited node
    for (; head; head = head->next) {
        if (head->val == INT_MAX) {
            return true;
        }

        head->val = INT_MAX;
    }

    return false;
}
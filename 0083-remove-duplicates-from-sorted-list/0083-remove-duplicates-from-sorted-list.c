/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void delete(struct ListNode* head, struct ListNode* curr) {
    if (curr == NULL) {
        head->next = NULL;
        return;
    }

    if (curr->val != head->val) {
        head = head->next;
        head->val = curr->val;
    }

    delete(head, curr->next);
}

struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (head == NULL) {
        return NULL;
    }

    delete(head, head->next);
    return head;
}
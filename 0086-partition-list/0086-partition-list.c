/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* partition(struct ListNode* head, int x) {
    // initialize the linked list
    struct ListNode *head_ = NULL, *currHead_ = NULL;
    struct ListNode *tail_ = NULL, *currTail_ = NULL;

    // fill the linked lists
    for (struct ListNode *curr = head; curr; curr = curr->next) {
        if (curr->val < x) {
            currHead_ = head_
                ? (currHead_->next = malloc(sizeof(struct ListNode)))
                : (head_ = malloc(sizeof(struct ListNode)));
            
            currHead_->val = curr->val;
        }
        else {
            currTail_ = tail_
                ? (currTail_->next = malloc(sizeof(struct ListNode)))
                : (tail_ = malloc(sizeof(struct ListNode)));
            
            currTail_->val = curr->val;
        }
    }

    // combine the linked lists
    if (currHead_) {
        currHead_->next = tail_;
    }
    else {
        head_ = tail_;
    }

    if (currTail_) {
        currTail_->next = NULL;
    }

    return head_;
}
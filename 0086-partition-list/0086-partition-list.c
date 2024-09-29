/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* partition(struct ListNode* head, int x) {
    if (head == NULL) {
        return NULL;
    }
    
    // initialize the linked list
    struct ListNode *head_ = malloc(sizeof(struct ListNode)), *curr_ = NULL;

    // append all values less than x
    for (struct ListNode *curr = head; curr; curr = curr->next) {  
        if (curr->val < x) {
            curr_ = curr_
                ? curr_->next
                : head_;
            
            curr_->val = curr->val;
            curr_->next = malloc(sizeof(struct ListNode));            
        }
    }

    // append all other values
    for (struct ListNode *curr = head; curr; curr = curr->next) {
        if (curr->val >= x) {
            curr_ = curr_
                ? curr_->next
                : head_;
            
            curr_->val = curr->val;
            curr_->next = malloc(sizeof(struct ListNode));            
        }
    }

    // free the unused allocated memory
    free(curr_->next);
    curr_->next = NULL;

    return head_;
}
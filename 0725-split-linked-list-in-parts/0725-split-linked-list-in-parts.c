struct ListNode *makePart(struct ListNode **head, int size) {
    // if the head of the linked list is null,
    // that means we must return an empty part
    if (*head == NULL) {
        return NULL;
    }

    struct ListNode *part = malloc(sizeof(struct ListNode));
    struct ListNode *curr = NULL;

    for (int i = 0; i < size; ++i) {
        curr = curr
            ? curr->next
            : part;
        
        curr->val = (*head)->val;
        curr->next = malloc(sizeof(struct ListNode));

        // advance the head of the linked list
        *head = (*head)->next;
    }

    curr->next = NULL;
    return part;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct ListNode** splitListToParts(struct ListNode* head, int k, int* returnSize) {
    // initialize the array
    struct ListNode **ans = malloc(k * sizeof(struct ListNode*));
    *returnSize = k;

    // determine the size of the linked list
    int size = 0;

    for (struct ListNode *curr = head; curr; curr = curr->next) {
        ++size;
    }

    // append the parts that are bigger than the rest
    int index = 0, bigger = size % k;
    size /= k;

    for (; index < bigger; ++index) {
        ans[index] = makePart(&head, size + 1);
    }

    // append the remaining parts
    for (; index < k; ++index) {
        ans[index] = makePart(&head, size);
    }

    return ans;
}
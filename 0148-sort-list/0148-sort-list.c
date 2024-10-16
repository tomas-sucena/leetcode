int lessThan(const void *a, const void *b) {
    return *((int*) a) - *((int*) b);
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* sortList(struct ListNode* head) {
    int length = 8;
    int *arr = malloc(length * sizeof(int));

    // copy all the elements of the linked list to an array
    int index = 0;

    for (struct ListNode *curr = head; curr; curr = curr->next) {
        arr[index++] = curr->val;

        // resize the array if needed
        if (index == length) {
            length *= 2;
            arr = realloc(arr, length * sizeof(int));
        }
    }
    
    // sort the array
    qsort(arr, index, sizeof(int), lessThan);

    // update the linked list
    index = 0;

    for (struct ListNode *curr = head; curr; curr = curr->next) {
        curr->val = arr[index++];
    }

    return head;
}
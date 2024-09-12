/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {
    // special cases
    if (head == NULL || k == 0) {
        return head;
    }

    // compute the size of the linked list
    int size = 0;

    for (struct ListNode *curr = head; curr; curr = curr->next) {
        ++size;
    }

    // update the value of k
    k %= size;

    if (k == 0) {
        return head;
    }

    // move a pointer k nodes to the right
    struct ListNode *back = head;

    for (int i = 1; i < k; ++i) {
        back = back->next;
    }

    struct ListNode *front = head;

    for (; back->next; back = back->next) {
        front = front->next;
    }

    // store the last k-elements in an array
    int *nums = malloc(k * sizeof(int));

    for (int i = 0; front; ++i) {
        nums[i % k] = front->val;
        front = front->next;
    }

    // update the linked list
    int n = 0;

    for (struct ListNode *curr = head; curr; curr = curr->next) {
        int temp = curr->val, index = n++ % k;

        curr->val = nums[index];
        nums[index] = temp;
    }

    return head;
}
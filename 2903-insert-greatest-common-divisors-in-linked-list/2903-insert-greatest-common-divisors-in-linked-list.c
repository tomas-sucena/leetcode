// Euclidean algorithm for computing the greatest common divisor
// taken from https://en.wikipedia.org/wiki/Euclidean_algorithm#Implementations
int gcd(int a, int b) {
    while (a != b) {
        if (a > b) {
            a -= b;
        }
        else {
            b -= a;
        }
    }

    return a;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* insertGreatestCommonDivisors(struct ListNode* head){
    for (struct ListNode *curr = head; curr->next; ) {
        // append the new node to the linked list
        struct ListNode *node = malloc(sizeof(struct ListNode));
        node->val = gcd(curr->val, curr->next->val);
        node->next = curr->next;

        curr->next = node;
        curr = node->next;
    }

    return head;
}
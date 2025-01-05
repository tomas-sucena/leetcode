/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    // traverse list A
    for (struct ListNode *temp = headA; temp; temp = temp->next) {
        temp->val *= -1;
    }

    // traverse list B and find the intersection node
    struct ListNode *ans = NULL;

    for (struct ListNode *temp = headB; temp; temp = temp->next) {
        // NOTE: If the value of the node is negative,
        // that means the node has been visited before.
        if (temp->val < 0) {
            ans = temp;
            break;
        }
    }

    // reset list A
    for (struct ListNode *temp = headA; temp; temp = temp->next) {
        temp->val *= -1;
    }

    return ans;
}
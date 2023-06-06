/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *prev = nullptr, *next = head;

        for (int i = 0; i < n; ++i)
            next = next->next;

        for (; next; next = next->next)
            prev = prev ? prev->next : head;

        // special case
        if (!prev) return head->next;

        prev->next = prev->next->next;
        return head;
    }
};
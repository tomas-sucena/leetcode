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
    ListNode* swapPairs(ListNode* head) {
        ListNode *first = head, *second = head ? head->next : nullptr;

        while (second) {
            int temp = first->val;

            first->val = second->val;
            second->val = temp;

            second = second->next; first = second;
            second = second ? second->next : nullptr;
        }

        return head;
    }
};
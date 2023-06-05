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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *res = new ListNode(), *temp = res;

        while (list1 || list2) {
            int val1 = list1 ? list1->val : INT_MAX;
            int val2 = list2 ? list2->val : INT_MAX;

            temp->next = new ListNode();
            temp = temp->next;

            if (val1 < val2) {
                temp->val = val1;
                list1 = list1->next;

                continue;
            }
        
            temp->val = val2;
            list2 = list2->next;
        }

        return res->next;
    }
};
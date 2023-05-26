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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *res = new ListNode(), *aux = res;
        
        bool carry = 0;
        for (; l1 != nullptr || l2 != nullptr; aux = aux->next){
            aux->next = new ListNode();

            int val1 = (l1 == nullptr) ? 0 : l1->val;
            int val2 = (l2 == nullptr) ? 0 : l2->val;

            int sum = val1 + val2 + carry;
            carry = sum / 10;

            aux->next->val = sum % 10;
            
            l1 = (l1 == nullptr) ? l1 : l1->next;
            l2 = (l2 == nullptr) ? l2 : l2->next;
        }
        
        if (carry) aux->next = new ListNode(carry);
        
        return res->next;
    }
};
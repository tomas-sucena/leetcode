/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> nodes;

        for (; head; head = head->next) {
            // attempt to insert the node in the hash set
            // if the insertion did NOT occur, that means a cycle was found
            if (!nodes.insert(head).second) {
                return head;
            }
        }

        return nullptr;
    }
};
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *head = nullptr, *tail;

        for (;;) {
            int index = -1;
            int min = INT_MAX;

            // find the next lowest value
            for (int i = 0; i < lists.size(); i++) {
                ListNode *list = lists[i];

                if (list && list->val < min) {
                    index = i;
                    min = list->val;
                }
            }

            if (index < 0) {
                break;
            }

            // append the value to the list
            if (head == nullptr) {
                head = new ListNode(min);
                tail = head;
            }
            else {
                tail->next = new ListNode(min);
                tail = tail->next;
            }

            lists[index] = lists[index]->next;
        }

        return head;
    }
};
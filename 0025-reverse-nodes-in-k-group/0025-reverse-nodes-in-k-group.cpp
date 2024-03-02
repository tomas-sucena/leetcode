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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *front = head, *back = nullptr;

        for (;;) {
            ListNode *arr[k];

            // advance the front
            for (int i = 0; i < k; ++i) {
                if (front == nullptr) return head;
                arr[i] = front;
                front = front->next;
            }

            // reverse the nodes
            for (int i = k - 1; i > 0;) {
                ListNode *temp = arr[i--];
                temp->next = arr[i];
            }

            if (back == nullptr) {
                back = arr[0];
                head = arr[k - 1];
            }
            else {
                back->next = arr[k - 1];
                back = arr[0];
            }

            back->next = front;
        }
    }
};
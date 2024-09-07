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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        // create a hash set with the entries of the array of integers
        unordered_set<int> _nums(nums.begin(), nums.end());

        // remove nodes whose value is a number present in the hash set
        ListNode *prev = nullptr;

        for (ListNode *curr = head; curr; curr = curr->next) {
            // if the value of the node is present in the hash set, ignore it
            if (_nums.find(curr->val) != _nums.end()) {
                continue;
            }

            prev = prev ? prev->next : head;
            prev->val = curr->val;
        }

        // if the pointer is null, that means all the values of the list
        // are present in the hash set
        if (prev == nullptr) {
            return nullptr;
        }

        prev->next = nullptr;
        return head;
    }
};
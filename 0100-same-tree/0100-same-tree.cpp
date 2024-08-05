/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // initialize the stack
        stack<TreeNode*> s;
        s.push(q); s.push(p);

        while (!s.empty()) {
            p = s.top(); s.pop();
            q = s.top(); s.pop();

            if (p == nullptr && q == nullptr) {
                continue;
            }
            else if (p && q && p->val == q->val) {
                s.push(q->left); s.push(p->left);
                s.push(q->right); s.push(p->right);
                continue;
            }

            return false;
        }

        return true;
    }
};
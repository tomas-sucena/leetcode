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
    void postorderDFS(TreeNode *root, vector<int> &vec) {
        if (root == NULL) {
            return;
        }

        // visit the left subtree
        postorderDFS(root->left, vec);

        // visit the right subtree
        postorderDFS(root->right, vec);

        // visit the current node
        vec.emplace_back(root->val);
    }

public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        postorderDFS(root, ans);

        return ans;
    }
};
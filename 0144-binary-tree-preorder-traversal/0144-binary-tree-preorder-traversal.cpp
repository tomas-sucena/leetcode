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
    void preorderDFS(TreeNode *root, vector<int> &ans) {
        if (root == nullptr) {
            return;
        }

        // visit the root node
        ans.emplace_back(root->val);

        // visit the left subtree
        preorderDFS(root->left, ans);

        // visit the right subtree
        preorderDFS(root->right, ans);
    }

public:
    vector<int> preorderTraversal(TreeNode* root) {
        // initialize the answer
        vector<int> ans;

        // visit the nodes using preorder Depth-First Search
        preorderDFS(root, ans);

        return ans;
    }
};
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
    bool isValidBST(TreeNode* root, long max, long min) {
        if (root == nullptr) {
            return true;
        }

        return root->val < max && root->val > min       // verify if the value is within the bounds
            && isValidBST(root->left, root->val, min)   // validate the left subtree
            && isValidBST(root->right, max, root->val); // validate the right subtree
    }

public:
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, LONG_MAX, LONG_MIN);
    }
};
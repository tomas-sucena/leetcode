void dfs(TreeNode *root, int level, vector<vector<int>> &nums) {
    if (root == NULL) {
        return;
    }

    // expand the vector, if necessary
    if (nums.size() == level) {
        nums.push_back({});
    }
  
    nums[level].emplace_back(root->val);

    // visit the left subtree
    dfs(root->left, level + 1, nums);

    // visit the right subtree
    dfs(root->right, level + 1, nums);
}

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        // fill the vector
        dfs(root, 0, ans);

        return ans;
    }
};
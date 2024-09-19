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
    void dfs(TreeNode *root, int targetSum, vector<int> path, vector<vector<int>> &paths) {
        if (root == NULL) {
            return;
        }

        targetSum -= root->val;
        path.emplace_back(root->val);

        // verify if the current node is a leaf node
        bool addPath = (targetSum == 0);

        // visit the left subtree
        if (root->left) {
            dfs(root->left, targetSum, path, paths);
            addPath = false;
        }

        // visit the right subtree
        if (root->right) {
            dfs(root->right, targetSum, path, paths);
            addPath = false;
        }
        
        if (addPath) {
            paths.emplace_back(path);
        }
    }

public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> paths;

        // ensure the binary tree is not empty
        if (root == NULL) {
            return paths;
        }

        dfs(root, targetSum, {}, paths);
        return paths;
    }
};
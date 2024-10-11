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
    int minDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        // initialize the queue
        queue<pair<int, TreeNode*>> queue;
        queue.emplace(1, root);

        // perform Breadth-First Search until a null node is found
        while (!queue.empty()) {
            auto top = queue.front();
            queue.pop();

            int depth = top.first;
            TreeNode *node = top.second;

            if (node == nullptr) {
                continue;
            }

            // determine if the current node is a leaf node
            if (node->left == nullptr && node->right == nullptr) {
                return depth;
            }

            // push the node's children to the queue
            queue.emplace(++depth, node->left);
            queue.emplace(depth, node->right);
        }

        // should not be reached
        return -1;
    }
};
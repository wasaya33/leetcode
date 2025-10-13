/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *l, TreeNode *r) : val(x), left(l), right(r) {}
 * };
 */

class Solution {
public:
    bool hasPathSum(TreeNode* root, int target) {
        if (!root) return false;
        if (!root->left && !root->right) {
            return root->val == target;
        }
        int rem = target - root->val;
        return hasPathSum(root->left, rem) || hasPathSum(root->right, rem);
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> indexMap;
        for (int i = 0; i < inorder.size(); ++i) {
            indexMap[inorder[i]] = i;
        }
        return buildSub(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, indexMap);
    }

private:
    TreeNode* buildSub(const vector<int>& preorder, int preL, int preR,
                       const vector<int>& inorder, int inL, int inR,
                       unordered_map<int,int>& indexMap) {
        if (preL > preR || inL > inR) return nullptr;
        int rootVal = preorder[preL];
        TreeNode* root = new TreeNode(rootVal);
        int split = indexMap[rootVal];
        int leftSize = split - inL;
        root->left = buildSub(preorder, preL + 1, preL + leftSize,
                              inorder, inL, split - 1, indexMap);
        root->right = buildSub(preorder, preL + leftSize + 1, preR,
                               inorder, split + 1, inR, indexMap);
        return root;
    }
};

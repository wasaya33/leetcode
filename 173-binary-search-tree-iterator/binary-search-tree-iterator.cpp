/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */

class BSTIterator {
private:
    stack<TreeNode*> st;

    void pushLefts(TreeNode* node) {
        while (node) {
            st.push(node);
            node = node->left;
        }
    }

public:
    BSTIterator(TreeNode* root) {
        pushLefts(root);
    }

    int next() {
        TreeNode* node = st.top();
        st.pop();
        int result = node->val;
        if (node->right) {
            pushLefts(node->right);
        }
        return result;
    }

    bool hasNext() {
        return !st.empty();
    }
};

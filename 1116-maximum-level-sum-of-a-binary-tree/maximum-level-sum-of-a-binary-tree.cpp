class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        int level = 0;
        int ans = 1;
        long long best = LLONG_MIN;

        while (!q.empty()) {
            int sz = q.size();
            level++;
            long long sum = 0;

            for (int i = 0; i < sz; i++) {
                TreeNode* node = q.front();
                q.pop();
                sum += node->val;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            if (sum > best) {
                best = sum;
                ans = level;
            }
        }
        return ans;
    }
};

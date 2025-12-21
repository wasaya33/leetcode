class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();
        vector<int> fixed(n - 1, 0);
        int ans = 0;

        for (int j = 0; j < m; ++j) {
            bool bad = false;
            for (int i = 0; i < n - 1; ++i) {
                if (!fixed[i] && strs[i][j] > strs[i + 1][j]) {
                    bad = true;
                    break;
                }
            }
            if (bad) {
                ans++;
                continue;
            }
            for (int i = 0; i < n - 1; ++i) {
                if (!fixed[i] && strs[i][j] < strs[i + 1][j]) {
                    fixed[i] = 1;
                }
            }
        }

        return ans;
    }
};

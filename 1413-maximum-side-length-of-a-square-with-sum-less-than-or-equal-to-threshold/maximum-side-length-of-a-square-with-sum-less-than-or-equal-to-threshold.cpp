class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> ps(m + 1, vector<int>(n + 1, 0));

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                ps[i + 1][j + 1] = ps[i + 1][j] + ps[i][j + 1] - ps[i][j] + mat[i][j];

        auto getSum = [&](int r1, int c1, int r2, int c2) {
            return ps[r2 + 1][c2 + 1] - ps[r1][c2 + 1] - ps[r2 + 1][c1] + ps[r1][c1];
        };

        auto ok = [&](int k) -> bool {
            if (k == 0) return true;
            for (int i = 0; i + k - 1 < m; ++i) {
                for (int j = 0; j + k - 1 < n; ++j) {
                    if (getSum(i, j, i + k - 1, j + k - 1) <= threshold) return true;
                }
            }
            return false;
        };

        int lo = 0, hi = min(m, n);
        while (lo < hi) {
            int mid = (lo + hi + 1) / 2;
            if (ok(mid)) lo = mid;
            else hi = mid - 1;
        }
        return lo;
    }
};

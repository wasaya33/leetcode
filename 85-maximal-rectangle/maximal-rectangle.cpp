class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        vector<int> st;
        int n = h.size();
        int best = 0;

        for (int i = 0; i <= n; ++i) {
            int cur = (i == n ? 0 : h[i]);
            while (!st.empty() && h[st.back()] > cur) {
                int height = h[st.back()];
                st.pop_back();
                int left = st.empty() ? -1 : st.back();
                int width = i - left - 1;
                best = max(best, height * width);
            }
            st.push_back(i);
        }
        return best;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<int> heights(n, 0);
        int ans = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '1') heights[j]++;
                else heights[j] = 0;
            }
            ans = max(ans, largestRectangleArea(heights));
        }
        return ans;
    }
};

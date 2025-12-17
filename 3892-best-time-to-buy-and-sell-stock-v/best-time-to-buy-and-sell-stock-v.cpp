class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        if (n == 0 || k == 0) return 0;

        const long long NEG_INF = LLONG_MIN / 4;
        vector<vector<long long>> dpPrev(k+1, vector<long long>(3, NEG_INF));
        dpPrev[0][0] = 0;

        for (int price : prices) {
            vector<vector<long long>> dpCurr = dpPrev;
            for (int j = 0; j <= k; ++j) {
                // Close long → increment transaction
                if (j > 0 && dpPrev[j-1][1] > NEG_INF)
                    dpCurr[j][0] = max(dpCurr[j][0], dpPrev[j-1][1] + price);

                // Close short → increment transaction
                if (j > 0 && dpPrev[j-1][2] > NEG_INF)
                    dpCurr[j][0] = max(dpCurr[j][0], dpPrev[j-1][2] - price);

                // Enter long (from not holding)
                if (dpPrev[j][0] > NEG_INF)
                    dpCurr[j][1] = max(dpCurr[j][1], dpPrev[j][0] - price);

                // Enter short (from not holding)
                if (dpPrev[j][0] > NEG_INF)
                    dpCurr[j][2] = max(dpCurr[j][2], dpPrev[j][0] + price);
            }
            dpPrev.swap(dpCurr);
        }

        long long ans = 0;
        for (int j = 0; j <= k; ++j)
            ans = max(ans, dpPrev[j][0]);

        return ans;
    }
};

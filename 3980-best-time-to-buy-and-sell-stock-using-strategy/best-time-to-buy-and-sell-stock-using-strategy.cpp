class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        long long base = 0;
        for (int i = 0; i < n; ++i)
            base += 1LL * strategy[i] * prices[i];

        vector<long long> pre0(n + 1, 0), pre1(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            long long change0 = (0LL - strategy[i]) * prices[i];
            long long change1 = (1LL - strategy[i]) * prices[i];
            pre0[i + 1] = pre0[i] + change0;
            pre1[i + 1] = pre1[i] + change1;
        }

        long long bestDelta = 0;
        for (int l = 0; l + k <= n; ++l) {
            int r = l + k;
            int mid = l + k / 2;
            long long deltaFirst = pre0[mid] - pre0[l];
            long long deltaSecond = pre1[r] - pre1[mid];
            long long delta = deltaFirst + deltaSecond;
            if (delta > bestDelta) bestDelta = delta;
        }

        return base + bestDelta;
    }
};

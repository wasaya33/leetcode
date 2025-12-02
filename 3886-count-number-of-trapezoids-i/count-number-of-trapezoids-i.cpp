class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        const long long MOD = 1000000007;
        unordered_map<long long, long long> cnt;
        for (auto &p : points) {
            cnt[p[1]]++;
        }
        long long ans = 0, sum = 0;
        for (auto &it : cnt) {
            long long c = it.second;
            if (c >= 2) {
                long long pairs = c * (c - 1) / 2;
                ans = (ans + sum * pairs) % MOD;
                sum = (sum + pairs) % MOD;
            }
        }
        return (int)ans;
    }
};

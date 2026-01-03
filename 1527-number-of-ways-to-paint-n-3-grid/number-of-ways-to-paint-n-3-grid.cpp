class Solution {
public:
    int numOfWays(int n) {
        const long long MOD = 1000000007LL;
        long long a = 6, b = 6;

        for (int i = 2; i <= n; ++i) {
            long long na = (3 * a + 2 * b) % MOD;
            long long nb = (2 * a + 2 * b) % MOD;
            a = na;
            b = nb;
        }

        return (a + b) % MOD;
    }
};

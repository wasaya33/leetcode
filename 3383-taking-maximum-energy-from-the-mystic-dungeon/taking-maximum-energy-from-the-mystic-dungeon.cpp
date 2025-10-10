#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        vector<long long> dp(n);
        for (int i = 0; i < n; i++) {
            dp[i] = energy[i];
        }
        for (int i = n - 1 - k; i >= 0; i--) {
            dp[i] += dp[i + k];
        }
        long long ans = dp[0];
        for (int i = 1; i < n; i++) {
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};

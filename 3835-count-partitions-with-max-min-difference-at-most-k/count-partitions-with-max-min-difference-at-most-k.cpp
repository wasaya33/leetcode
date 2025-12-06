class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        static const int MOD = 1000000007;
        int n = nums.size();
        vector<long long> dp(n+1, 0), pref(n+1, 0);
        dp[0] = 1;
        pref[0] = 1;
        deque<int> dqMin, dqMax;
        int l = 0;
        for (int r = 0; r < n; ++r) {
            while (!dqMin.empty() && nums[dqMin.back()] >= nums[r]) dqMin.pop_back();
            dqMin.push_back(r);
            while (!dqMax.empty() && nums[dqMax.back()] <= nums[r]) dqMax.pop_back();
            dqMax.push_back(r);
            while (l <= r && nums[dqMax.front()] - nums[dqMin.front()] > k) {
                if (dqMin.front() == l) dqMin.pop_front();
                if (dqMax.front() == l) dqMax.pop_front();
                l++;
            }
            dp[r+1] = (pref[r] - (l>=1 ? pref[l-1] : 0) + MOD) % MOD;
            pref[r+1] = (pref[r] + dp[r+1]) % MOD;
        }
        return dp[n];
    }
};

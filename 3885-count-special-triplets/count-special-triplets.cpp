class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const long long MOD = 1000000007;
        long long ans = 0;
        unordered_map<int,int> left, right;
        for (int x : nums) right[x]++;
        for (int x : nums) {
            right[x]--;
            long long needed = (long long)x * 2;
            long long cntL = left.count((int)needed) ? left[(int)needed] : 0;
            long long cntR = right.count((int)needed) ? right[(int)needed] : 0;
            ans = (ans + cntL * cntR) % MOD;
            left[x]++;
        }
        return (int)ans;
    }
};

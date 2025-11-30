class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long total = 0;
        for (int x : nums) total += x;
        int rem = total % p;
        if (rem == 0) return 0;

        unordered_map<int,int> last;
        last[0] = -1;
        int n = nums.size();
        int res = n;
        long long prefix = 0;

        for (int i = 0; i < n; ++i) {
            prefix = (prefix + nums[i]) % p;
            int want = (prefix - rem + p) % p;
            if (last.count(want)) {
                res = min(res, i - last[want]);
            }
            last[prefix] = i;
        }

        return res == n ? -1 : res;
    }
};

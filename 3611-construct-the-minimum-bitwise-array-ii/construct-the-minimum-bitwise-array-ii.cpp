class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        ans.reserve(nums.size());

        for (int x : nums) {
            if ((x & 1) == 0) {        
                ans.push_back(-1);
                continue;
            }

            int a = -1;
            for (int i = 0; i < 31; ++i) {
                if (((x >> i) & 1) == 0) {  
                    a = x ^ (1 << (i - 1));
                    break;
                }
            }
            ans.push_back(a);
        }
        return ans;
    }
};

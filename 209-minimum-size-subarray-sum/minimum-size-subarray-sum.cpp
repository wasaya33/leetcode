class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int minLen = n + 1;
        int sum = 0;
        int left = 0;
        for (int right = 0; right < n; ++right) {
            sum += nums[right];
            while (sum >= target) {
                int currLen = right - left + 1;
                if (currLen < minLen) minLen = currLen;
                sum -= nums[left];
                left++;
            }
        }
        return (minLen == n + 1 ? 0 : minLen);
    }
};

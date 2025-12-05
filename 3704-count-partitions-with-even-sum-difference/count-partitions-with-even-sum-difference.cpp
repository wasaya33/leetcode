class Solution {
public:
    int countPartitions(vector<int>& nums) {
        long long s = 0;
        for (int x : nums) s += x;
        return (s % 2 == 0) ? (int)nums.size() - 1 : 0;
    }
};

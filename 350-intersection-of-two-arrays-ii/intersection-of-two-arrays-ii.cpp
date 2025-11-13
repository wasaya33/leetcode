class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> count;
        for (int x : nums1) count[x]++;
        vector<int> result;
        for (int x : nums2) {
            if (count[x] > 0) {
                result.push_back(x);
                count[x]--;
            }
        }
        return result;
    }
};

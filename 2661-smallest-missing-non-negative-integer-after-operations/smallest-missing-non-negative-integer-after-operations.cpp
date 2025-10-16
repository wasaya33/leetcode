#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int,int> cnt;
        for (int x : nums) {
            int r = x % value;
            if (r < 0) r += value;
            cnt[r]++;
        }
        int n = nums.size();
        for (int i = 0; i <= n; i++) {
            int r = i % value;
            if (cnt[r] == 0) return i;
            cnt[r]--;
        }
        return n + 1;
    }
};

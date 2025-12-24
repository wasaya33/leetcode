class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        long long total = 0;
        for (int a : apple) total += a;
        sort(capacity.begin(), capacity.end(), greater<int>());
        int ans = 0;
        for (int c : capacity) {
            total -= c;
            ans++;
            if (total <= 0) break;
        }
        return ans;
    }
};

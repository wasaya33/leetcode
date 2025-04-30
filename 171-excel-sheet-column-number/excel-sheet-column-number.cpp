class Solution {
public:
    int titleToNumber(string columnTitle) {
        int ans = 0; 
        int p = 0;
        for (int i = columnTitle.length() - 1; i >= 0; i--) {
            char c = columnTitle[i];
            int val = (int)c - 'A' + 1;
            ans += val * pow(26, p);
            p++;
        }
        return ans;
    }
};
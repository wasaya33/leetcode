#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int nextBeautifulNumber(int n) {
        for (int x = n + 1; ; x++) {
            if (isBalanced(x)) return x;
        }
        return -1;
    }
private:
    bool isBalanced(int x) {
        string s = to_string(x);
        vector<int> cnt(10, 0);
        for (char c : s) {
            int d = c - '0';
            if (d == 0) return false;
            cnt[d]++;
        }
        for (int d = 1; d < 10; d++) {
            if (cnt[d] && cnt[d] != d) return false;
        }
        return true;
    }
};

#include <string>
using namespace std;

class Solution {
public:
    bool hasSameDigits(string s) {
        int n = s.size();
        while (n > 2) {
            for (int i = 0; i < n - 1; i++) {
                s[i] = char(((s[i] - '0') + (s[i + 1] - '0')) % 10 + '0');
            }
            n--;
        }
        return s[0] == s[1];
    }
};

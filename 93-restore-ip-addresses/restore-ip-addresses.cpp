#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        string part;
        dfs(s, 0, 0, part, res);
        return res;
    }
private:
    void dfs(const string& s, int start, int segments, string& part, vector<string>& res) {
        if (segments == 4 && start == s.size()) {
            res.push_back(part.substr(0, part.size() - 1)); // remove trailing '.'
            return;
        }
        if (segments == 4) return;

        int n = s.size();
        long val = 0;
        for (int len = 1; len <= 3 && start + len <= n; ++len) {
            val = val * 10 + (s[start + len - 1] - '0');
            if (val > 255) break;
            if (len > 1 && s[start] == '0') break;

            int oldSize = part.size();
            part += s.substr(start, len) + '.';
            dfs(s, start + len, segments + 1, part, res);
            part.resize(oldSize);
        }
    }
};

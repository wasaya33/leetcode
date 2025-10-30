#include <vector>
#include <string>
#include <sstream>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stk;
        string part;
        istringstream ss(path);
        while (getline(ss, part, '/')) {
            if (part == "" || part == ".") {
                continue;
            } else if (part == "..") {
                if (!stk.empty()) stk.pop_back();
            } else {
                stk.push_back(part);
            }
        }
        string ans;
        for (auto &dir : stk) {
            ans += "/" + dir;
        }
        return ans.empty() ? "/" : ans;
    }
};

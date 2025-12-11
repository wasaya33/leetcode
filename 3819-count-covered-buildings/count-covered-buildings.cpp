#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        unordered_map<int, vector<int>> ysAtX;
        unordered_map<int, vector<int>> xsAtY;

        for (auto& b : buildings) {
            int x = b[0], y = b[1];
            ysAtX[x].push_back(y);
            xsAtY[y].push_back(x);
        }

        for (auto& [x, vec] : ysAtX) sort(vec.begin(), vec.end());
        for (auto& [y, vec] : xsAtY) sort(vec.begin(), vec.end());

        int ans = 0;
        for (auto& b : buildings) {
            int x = b[0], y = b[1];
            auto& row = ysAtX[x];
            auto& col = xsAtY[y];

            if (row.size() < 3 || col.size() < 3) continue;

            if (row.front() < y && y < row.back() &&
                col.front() < x && x < col.back()) {
                ans++;
            }
        }
        return ans;
    }
};

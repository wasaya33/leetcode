#include <bits/stdc++.h>
using namespace std;

class SummaryRanges {
public:
    map<int, int> intervals;

    SummaryRanges() {}

    void addNum(int val) {
        int left = val, right = val;

        auto it = intervals.upper_bound(val);
        if (it != intervals.begin()) {
            auto prev = it;
            --prev;
            if (prev->second >= val) return;
            if (prev->second + 1 == val) {
                left = prev->first;
                intervals.erase(prev);
            }
        }

        if (it != intervals.end() && it->first == val + 1) {
            right = it->second;
            intervals.erase(it);
        }

        intervals[left] = right;
    }

    vector<vector<int>> getIntervals() {
        vector<vector<int>> res;
        for (auto &p : intervals) {
            res.push_back({p.first, p.second});
        }
        return res;
    }
};

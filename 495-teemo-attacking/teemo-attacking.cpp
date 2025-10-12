#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if (duration == 0 || timeSeries.empty()) return 0;
        int total = 0;
        for (int i = 0; i + 1 < timeSeries.size(); i++) {
            total += min(duration, timeSeries[i + 1] - timeSeries[i]);
        }
        total += duration;
        return total;
    }
};

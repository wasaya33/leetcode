#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        map<int, long long> totalDamage;
        for (int p : power) {
            totalDamage[p] += p;
        }

        vector<int> unique;
        for (auto const& [d, total] : totalDamage) {
            unique.push_back(d);
        }

        int n = unique.size();
        if (n == 0) return 0;

        vector<long long> dp(n + 1, 0);
        
        for (int i = 1; i <= n; ++i) {
            int current = unique[i - 1];
            long long currentTotal = totalDamage[current];
            
            long long skip = dp[i - 1];
            
      
            auto it = upper_bound(unique.begin(), unique.end(), current - 3);
            int prevSafeIndex = it - unique.begin();

            long long take = currentTotal;
            if (prevSafeIndex > 0) {
                take += dp[prevSafeIndex];
            }

            dp[i] = max(skip, take);
        }

        return dp[n];
    }
};
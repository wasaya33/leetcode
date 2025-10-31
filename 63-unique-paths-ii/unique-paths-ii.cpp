#include <vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<long> dp(n, 0);
        dp[0] = (obstacleGrid[0][0] == 0 ? 1 : 0);
        for (int j = 1; j < n; ++j) {
            dp[j] = (obstacleGrid[0][j] == 0 ? dp[j - 1] : 0);
        }
        for (int i = 1; i < m; ++i) {
            dp[0] = (obstacleGrid[i][0] == 0 ? dp[0] : 0);
            for (int j = 1; j < n; ++j) {
                dp[j] = (obstacleGrid[i][j] == 0 ? dp[j] + dp[j - 1] : 0);
            }
        }
        return (int)dp[n - 1];
    }
};

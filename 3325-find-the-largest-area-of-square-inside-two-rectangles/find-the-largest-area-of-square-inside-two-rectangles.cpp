class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft,
                               vector<vector<int>>& topRight) {
        long long best = 0;
        int n = (int)bottomLeft.size();

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                long long x1 = max(bottomLeft[i][0], bottomLeft[j][0]);
                long long y1 = max(bottomLeft[i][1], bottomLeft[j][1]);
                long long x2 = min(topRight[i][0], topRight[j][0]);
                long long y2 = min(topRight[i][1], topRight[j][1]);

                long long w = x2 - x1;
                long long h = y2 - y1;
                if (w > 0 && h > 0) {
                    long long s = min(w, h);
                    best = max(best, s * s);
                }
            }
        }
        return best;
    }
};

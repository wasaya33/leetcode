class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double total = 0;
        long long minY = LLONG_MAX, maxY = LLONG_MIN;

        for (auto &sq : squares) {
            long long y = sq[1], l = sq[2];
            total += 1.0 * l * l;
            minY = min(minY, y);
            maxY = max(maxY, y + l);
        }

        double half = total / 2.0;

        auto below = [&](double Y) -> double {
            double area = 0;
            for (auto &sq : squares) {
                double y = sq[1], l = sq[2];
                if (Y <= y) continue;
                if (Y >= y + l) area += l * l;
                else area += (Y - y) * l;
            }
            return area;
        };

        double lo = (double)minY, hi = (double)maxY;
        for (int it = 0; it < 80; ++it) {
            double mid = (lo + hi) / 2.0;
            if (below(mid) >= half) hi = mid;
            else lo = mid;
        }
        return hi;
    }
};

class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        const long long MOD = 1'000'000'007LL;

        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);

        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());

        unordered_set<int> hDiffs;
        hDiffs.reserve((size_t)hFences.size() * (size_t)hFences.size());

        for (int i = 0; i < (int)hFences.size(); ++i) {
            for (int j = i + 1; j < (int)hFences.size(); ++j) {
                hDiffs.insert(hFences[j] - hFences[i]);
            }
        }

        long long best = -1;
        for (int i = 0; i < (int)vFences.size(); ++i) {
            for (int j = i + 1; j < (int)vFences.size(); ++j) {
                int d = vFences[j] - vFences[i];
                if (hDiffs.count(d)) best = max(best, (long long)d);
            }
        }

        if (best == -1) return -1;
        return (int)((best % MOD) * (best % MOD) % MOD);
    }
};

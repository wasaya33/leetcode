class Solution {
public:
    long long minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,long long>>> g(n);
        g.reserve(n);

        for (auto &e : edges) {
            int u = e[0], v = e[1];
            long long w = e[2];
            g[u].push_back({v, w});       // use as-is
            g[v].push_back({u, 2LL * w}); // traverse reversed
        }

        const long long INF = (1LL<<62);
        vector<long long> dist(n, INF);
        dist[0] = 0;

        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            if (d != dist[u]) continue;
            if (u == n - 1) return d;

            for (auto [v, cost] : g[u]) {
                if (dist[v] > d + cost) {
                    dist[v] = d + cost;
                    pq.push({dist[v], v});
                }
            }
        }

        return -1;
    }
};

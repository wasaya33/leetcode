class Solution {
public:
    struct Trie {
        struct Node {
            int nxt[26];
            int id;
            Node() : id(-1) { fill(nxt, nxt + 26, -1); }
        };
        vector<Node> t;
        Trie() { t.emplace_back(); }

        void insert(const string& s, int id) {
            int p = 0;
            for (char ch : s) {
                int c = ch - 'a';
                if (t[p].nxt[c] == -1) {
                    t[p].nxt[c] = (int)t.size();
                    t.emplace_back();
                }
                p = t[p].nxt[c];
            }
            t[p].id = id;
        }

        // returns ids of all words that match s starting at pos, in order of increasing length
        void matchAll(const string& s, int pos, vector<int>& out) const {
            out.clear();
            int p = 0;
            for (int i = pos; i < (int)s.size(); ++i) {
                int c = s[i] - 'a';
                if (t[p].nxt[c] == -1) break;
                p = t[p].nxt[c];
                if (t[p].id != -1) out.push_back(t[p].id);
            }
        }
    };

    long long minimumCost(string source, string target,
                          vector<string>& original, vector<string>& changed,
                          vector<int>& cost) {
        const long long INF = (1LL<<60);

        // 1) compress strings to ids
        unordered_map<string,int> id;
        id.reserve(original.size() * 2 + 10);
        auto getId = [&](const string& s) -> int {
            auto it = id.find(s);
            if (it != id.end()) return it->second;
            int nid = (int)id.size();
            id.emplace(s, nid);
            return nid;
        };

        for (int i = 0; i < (int)original.size(); ++i) {
            getId(original[i]);
            getId(changed[i]);
        }
        int M = (int)id.size();

        // 2) Floyd on substring rules
        vector<vector<long long>> dist(M, vector<long long>(M, INF));
        for (int i = 0; i < M; ++i) dist[i][i] = 0;

        for (int i = 0; i < (int)original.size(); ++i) {
            int u = getId(original[i]);
            int v = getId(changed[i]);
            dist[u][v] = min(dist[u][v], (long long)cost[i]);
        }

        for (int k = 0; k < M; ++k)
            for (int i = 0; i < M; ++i) if (dist[i][k] < INF)
                for (int j = 0; j < M; ++j) if (dist[k][j] < INF)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

        // 3) build tries for matching source-substrings and target-substrings to ids
        Trie ts, tt;
        vector<string> byId(M);
        for (auto &p : id) byId[p.second] = p.first;
        for (int i = 0; i < M; ++i) {
            ts.insert(byId[i], i);
            tt.insert(byId[i], i);
        }

        // 4) DP over positions
        int n = source.size();
        vector<long long> dp(n + 1, INF);
        dp[n] = 0;

        vector<int> sIds, tIds;
        for (int i = n - 1; i >= 0; --i) {
            if (source[i] == target[i]) dp[i] = min(dp[i], dp[i + 1]);

            ts.matchAll(source, i, sIds);
            tt.matchAll(target, i, tIds);

            // same lengths only: iterate both lists by length (they are in increasing length)
            int ps = 0, pt = 0;
            while (ps < (int)sIds.size() && pt < (int)tIds.size()) {
                int sid = sIds[ps], tid = tIds[pt];
                int ls = (int)byId[sid].size();
                int lt = (int)byId[tid].size();
                if (ls == lt) {
                    if (i + ls <= n && dist[sid][tid] < INF && dp[i + ls] < INF) {
                        dp[i] = min(dp[i], dist[sid][tid] + dp[i + ls]);
                    }
                    ++ps; ++pt;
                } else if (ls < lt) {
                    ++ps;
                } else {
                    ++pt;
                }
            }
        }

        return dp[0] >= INF/2 ? -1 : dp[0];
    }
};

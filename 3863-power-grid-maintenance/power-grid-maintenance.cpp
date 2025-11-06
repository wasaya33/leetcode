class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        vector<int> parent(c + 1);
        iota(parent.begin(), parent.end(), 0);

        function<int(int)> find = [&](int x) {
            if (parent[x] == x) return x;
            return parent[x] = find(parent[x]);
        };

        auto unite = [&](int a, int b) {
            a = find(a);
            b = find(b);
            if (a != b) parent[b] = a;
        };

        for (auto& e : connections) unite(e[0], e[1]);

        unordered_map<int, set<int>> online;
        for (int i = 1; i <= c; ++i) online[find(i)].insert(i);

        vector<int> ans;
        vector<bool> off(c + 1, false);

        for (auto& q : queries) {
            int type = q[0], x = q[1];
            int root = find(x);

            if (type == 1) {
                if (!off[x]) ans.push_back(x);
                else {
                    if (online[root].empty()) ans.push_back(-1);
                    else ans.push_back(*online[root].begin());
                }
            } else {
                if (!off[x]) {
                    off[x] = true;
                    online[root].erase(x);
                }
            }
        }

        return ans;
    }
};

class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<bool> knows(n, false);
        knows[0] = knows[firstPerson] = true;

        sort(meetings.begin(), meetings.end(), [](auto& a, auto& b) {
            return a[2] < b[2];
        });

        int m = meetings.size();
        for (int i = 0; i < m; ) {
            int t = meetings[i][2];
            int j = i;
            while (j < m && meetings[j][2] == t) j++;

            unordered_map<int, vector<int>> g;
            unordered_set<int> people;
            for (int k = i; k < j; ++k) {
                int x = meetings[k][0], y = meetings[k][1];
                g[x].push_back(y);
                g[y].push_back(x);
                people.insert(x);
                people.insert(y);
            }

            queue<int> q;
            for (int p : people) {
                if (knows[p]) q.push(p);
            }

            while (!q.empty()) {
                int u = q.front();
                q.pop();
                for (int v : g[u]) {
                    if (!knows[v]) {
                        knows[v] = true;
                        q.push(v);
                    }
                }
            }

            i = j;
        }

        vector<int> res;
        for (int i = 0; i < n; ++i) {
            if (knows[i]) res.push_back(i);
        }
        return res;
    }
};

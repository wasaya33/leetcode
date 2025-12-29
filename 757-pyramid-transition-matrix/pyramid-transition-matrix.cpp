class Solution {
public:
    unordered_map<int, int> mp;
    unordered_map<string, bool> memo;

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        mp.clear();
        memo.clear();

        for (auto& s : allowed) {
            int a = s[0] - 'A';
            int b = s[1] - 'A';
            int c = s[2] - 'A';
            mp[a * 7 + b] |= (1 << c);
        }

        return dfs(bottom);
    }

    bool dfs(const string& row) {
        if (row.size() == 1) return true;
        if (memo.count(row)) return memo[row];

        string next;
        bool ok = build(row, 0, next);
        memo[row] = ok;
        return ok;
    }

    bool build(const string& row, int i, string& next) {
        if (i + 1 == (int)row.size()) return dfs(next);

        int a = row[i] - 'A';
        int b = row[i + 1] - 'A';
        int mask = mp[a * 7 + b];
        if (mask == 0) return false;

        for (int c = 0; c < 7; ++c) {
            if (mask & (1 << c)) {
                next.push_back(char('A' + c));
                if (build(row, i + 1, next)) return true;
                next.pop_back();
            }
        }
        return false;
    }
};

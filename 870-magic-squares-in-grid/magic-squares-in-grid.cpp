class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int R = grid.size(), C = grid[0].size();
        int ans = 0;

        for (int r = 0; r + 2 < R; ++r) {
            for (int c = 0; c + 2 < C; ++c) {
                if (isMagic(grid, r, c)) ans++;
            }
        }
        return ans;
    }

    bool isMagic(vector<vector<int>>& g, int r, int c) {
        bool seen[10] = {};
        for (int i = r; i < r + 3; ++i) {
            for (int j = c; j < c + 3; ++j) {
                int x = g[i][j];
                if (x < 1 || x > 9 || seen[x]) return false;
                seen[x] = true;
            }
        }

        int s = g[r][c] + g[r][c + 1] + g[r][c + 2];

        if (g[r + 1][c] + g[r + 1][c + 1] + g[r + 1][c + 2] != s) return false;
        if (g[r + 2][c] + g[r + 2][c + 1] + g[r + 2][c + 2] != s) return false;

        if (g[r][c] + g[r + 1][c] + g[r + 2][c] != s) return false;
        if (g[r][c + 1] + g[r + 1][c + 1] + g[r + 2][c + 1] != s) return false;
        if (g[r][c + 2] + g[r + 1][c + 2] + g[r + 2][c + 2] != s) return false;

        if (g[r][c] + g[r + 1][c + 1] + g[r + 2][c + 2] != s) return false;
        if (g[r][c + 2] + g[r + 1][c + 1] + g[r + 2][c] != s) return false;

        return true;
    }
};

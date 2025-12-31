class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int lo = 0, hi = (int)cells.size();
        while (lo < hi) {
            int mid = lo + (hi - lo + 1) / 2;
            if (canCross(row, col, cells, mid)) lo = mid;
            else hi = mid - 1;
        }
        return lo;
    }

    bool canCross(int row, int col, vector<vector<int>>& cells, int day) {
        vector<vector<int>> water(row, vector<int>(col, 0));
        for (int i = 0; i < day; ++i) {
            int r = cells[i][0] - 1;
            int c = cells[i][1] - 1;
            water[r][c] = 1;
        }

        queue<pair<int,int>> q;
        vector<vector<int>> vis(row, vector<int>(col, 0));

        for (int c = 0; c < col; ++c) {
            if (water[0][c] == 0) {
                q.push({0, c});
                vis[0][c] = 1;
            }
        }

        int dr[4] = {1, -1, 0, 0};
        int dc[4] = {0, 0, 1, -1};

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            if (r == row - 1) return true;

            for (int k = 0; k < 4; ++k) {
                int nr = r + dr[k];
                int nc = c + dc[k];
                if (nr < 0 || nr >= row || nc < 0 || nc >= col) continue;
                if (vis[nr][nc]) continue;
                if (water[nr][nc]) continue;
                vis[nr][nc] = 1;
                q.push({nr, nc});
            }
        }
        return false;
    }
};

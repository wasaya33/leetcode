#include <vector>
using namespace std;

class Solution {
public:
    int totalNQueens(int n) {
        vector<bool> cols(n, false);
        vector<bool> diag1(2*n - 1, false);
        vector<bool> diag2(2*n - 1, false);
        return dfs(0, n, cols, diag1, diag2);
    }
    
private:
    int dfs(int row, int n,
            vector<bool>& cols,
            vector<bool>& diag1,
            vector<bool>& diag2) {
        if (row == n) return 1;
        int count = 0;
        for (int c = 0; c < n; c++) {
            int d1 = row + c;
            int d2 = row - c + n - 1;
            if (cols[c] || diag1[d1] || diag2[d2]) continue;
            cols[c] = diag1[d1] = diag2[d2] = true;
            count += dfs(row + 1, n, cols, diag1, diag2);
            cols[c] = diag1[d1] = diag2[d2] = false;
        }
        return count;
    }
};

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') continue;
                
                for (int k = j + 1; k < 9; ++k) {
                    if (board[i][j] == board[i][k]) return false; // Check row
                }
                
                for (int k = i + 1; k < 9; ++k) {
                    if (board[i][j] == board[k][j]) return false; // Check column
                }
                
                int boxRowStart = (i / 3) * 3;
                int boxColStart = (j / 3) * 3;
                for (int x = boxRowStart; x < boxRowStart + 3; ++x) {
                    for (int y = boxColStart; y < boxColStart + 3; ++y) {
                        if (board[i][j] == board[x][y] && (x != i || y != j)) return false; // Check subgrid
                    }
                }
            }
        }
        return true;
    }
};

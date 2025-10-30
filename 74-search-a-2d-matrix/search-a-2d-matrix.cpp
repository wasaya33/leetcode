#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        int m = matrix.size(), n = matrix[0].size();
        int l = 0, r = m * n - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            int value = matrix[mid / n][mid % n];
            if (value == target) return true;
            if (value < target) l = mid + 1;
            else r = mid - 1;
        }
        return false;
    }
};

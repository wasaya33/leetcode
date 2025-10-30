#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<int> height(n, 0);
        int maxArea = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') height[j]++;
                else height[j] = 0;
            }
            maxArea = max(maxArea, largestRectangleArea(height));
        }
        return maxArea;
    }
    
private:
    int largestRectangleArea(const vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        vector<int> h(n + 2, 0);
        for (int i = 0; i < n; i++) h[i + 1] = heights[i];
        int area = 0;
        for (int i = 0; i < n + 2; i++) {
            while (!st.empty() && h[st.top()] > h[i]) {
                int height = h[st.top()]; st.pop();
                int width = i - st.top() - 1;
                area = max(area, height * width);
            }
            st.push(i);
        }
        return area;
    }
};

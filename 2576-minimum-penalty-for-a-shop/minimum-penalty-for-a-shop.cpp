class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        vector<int> preY(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            preY[i + 1] = preY[i] + (customers[i] == 'Y');
        }

        int totalY = preY[n];
        int bestJ = 0;
        int bestPenalty = totalY;

        for (int j = 1; j <= n; ++j) {
            int openN = j - preY[j];
            int closedY = totalY - preY[j];
            int penalty = openN + closedY;
            if (penalty < bestPenalty) {
                bestPenalty = penalty;
                bestJ = j;
            }
        }

        return bestJ;
    }
};

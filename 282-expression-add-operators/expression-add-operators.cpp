class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> result;
        if (num.empty()) return result;
        backtrack(num, target, 0, 0, 0, "", result);
        return result;
    }
    
private:
    void backtrack(const string &num, int target, int pos,
                   long prev, long curr, string expr,
                   vector<string> &result) {
        if (pos == num.size()) {
            if (curr == target) result.push_back(expr);
            return;
        }
        for (int i = pos; i < num.size(); ++i) {
            if (i > pos && num[pos] == '0') break;
            long val = stol(num.substr(pos, i - pos + 1));
            string part = num.substr(pos, i - pos + 1);
            if (pos == 0) {
                backtrack(num, target, i + 1, val, val, part, result);
            } else {
                backtrack(num, target, i + 1,  val, curr + val, expr + "+" + part, result);
                backtrack(num, target, i + 1, -val, curr - val, expr + "-" + part, result);
                backtrack(num, target, i + 1, prev * val, curr - prev + prev * val, expr + "*" + part, result);
            }
        }
    }
};

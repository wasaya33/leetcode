class Solution {
public:
    int calculate(string s) {
        int result = 0;
        int num = 0;
        int sign = 1;
        stack<int> st;
        st.push(sign);

        for (char c : s) {
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            } else if (c == '+' || c == '-') {
                result += sign * num;
                num = 0;
                sign = (c == '+' ? 1 : -1) * st.top();
            } else if (c == '(') {
                st.push(sign);
            } else if (c == ')') {
                st.pop();
            }
        }
        result += sign * num;
        return result;
    }
};

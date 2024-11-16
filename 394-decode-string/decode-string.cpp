class Solution {
public:
    string decodeString(string s) {
        stack<int> countStack;
        stack<string> resultStack;
        string currentString = "";
        int k = 0;

        for (char c : s) {
            if (isdigit(c)) {
                k = k * 10 + (c - '0');
            } else if (c == '[') {
                countStack.push(k);
                resultStack.push(currentString);
                k = 0;
                currentString = "";
            } else if (c == ']') {
                int count = countStack.top(); countStack.pop();
                string temp = currentString;
                currentString = resultStack.top(); resultStack.pop();
                while (count--) {
                    currentString += temp;
                }
            } else {
                currentString += c;
            }
        }
        return currentString;
    }
};

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {}; 

        vector<string> result = {""};
        vector<string> mapping = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        for (char digit : digits) {
            vector<string> temp;
            for (char letter : mapping[digit - '0']) {
                for (string combination : result) {
                    temp.push_back(combination + letter);
                }
            }
            result = temp;
        }
        return result;
    }
};

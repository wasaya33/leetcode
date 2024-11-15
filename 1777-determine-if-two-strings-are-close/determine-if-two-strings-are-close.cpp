#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.size() != word2.size()) return false;

        unordered_map<char, int> freq1, freq2;
        unordered_set<char> unique1, unique2;

        for (char c : word1) {
            freq1[c]++;
            unique1.insert(c);
        }

        for (char c : word2) {
            freq2[c]++;
            unique2.insert(c);
        }

        if (unique1 != unique2) return false;

        vector<int> freqValues1, freqValues2;
        for (auto& [key, value] : freq1) freqValues1.push_back(value);
        for (auto& [key, value] : freq2) freqValues2.push_back(value);

        sort(freqValues1.begin(), freqValues1.end());
        sort(freqValues2.begin(), freqValues2.end());

        return freqValues1 == freqValues2;
    }
};

#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size(), m = mana.size();
        long long sumSkill = accumulate(skill.begin(), skill.end(), 0LL);
        long long prevWizardDone = sumSkill * mana[0];
        for (int j = 1; j < m; j++) {
            long long prevPotionDone = prevWizardDone;
            for (int i = n - 2; i >= 0; i--) {
                prevPotionDone -= (long long)skill[i + 1] * mana[j - 1];
                long long option = prevWizardDone - (long long)skill[i] * mana[j];
                prevWizardDone = max(prevPotionDone, option);
            }
            prevWizardDone += sumSkill * mana[j];
        }
        return prevWizardDone;
    }
};

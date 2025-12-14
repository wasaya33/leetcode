class Solution {
public:
    int numberOfWays(string corridor) {
        const int MOD = 1000000007;
        vector<int> seats;
        for (int i = 0; i < corridor.size(); i++)
            if (corridor[i] == 'S')
                seats.push_back(i);
        if (seats.size() == 0 || seats.size() % 2 == 1)
            return 0;
        long long ans = 1;
        for (int i = 2; i < seats.size(); i += 2)
            ans = ans * (seats[i] - seats[i - 1]) % MOD;
        return ans;
    }
};

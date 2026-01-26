class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());

        int mn = INT_MAX;
        for (int i = 0; i + 1 < (int)arr.size(); ++i)
            mn = min(mn, arr[i + 1] - arr[i]);

        vector<vector<int>> res;
        for (int i = 0; i + 1 < (int)arr.size(); ++i)
            if (arr[i + 1] - arr[i] == mn)
                res.push_back({arr[i], arr[i + 1]});

        return res;
    }
};

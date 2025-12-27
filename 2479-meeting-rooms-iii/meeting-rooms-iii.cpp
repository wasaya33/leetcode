class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());

        priority_queue<int, vector<int>, greater<int>> available;
        for (int i = 0; i < n; ++i) available.push(i);

        using P = pair<long long, int>;
        priority_queue<P, vector<P>, greater<P>> busy;

        vector<int> cnt(n, 0);

        for (auto& mt : meetings) {
            long long start = mt[0], end = mt[1];
            long long dur = end - start;

            while (!busy.empty() && busy.top().first <= start) {
                available.push(busy.top().second);
                busy.pop();
            }

            int room;
            long long finish;

            if (!available.empty()) {
                room = available.top();
                available.pop();
                finish = end;
            } else {
                auto [t, r] = busy.top();
                busy.pop();
                room = r;
                finish = t + dur;
            }

            cnt[room]++;
            busy.push({finish, room});
        }

        int ans = 0;
        for (int i = 1; i < n; ++i) {
            if (cnt[i] > cnt[ans]) ans = i;
        }
        return ans;
    }
};

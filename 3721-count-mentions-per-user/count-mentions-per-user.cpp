#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        sort(events.begin(), events.end(), [](auto &a, auto &b){
            int ta = stoi(a[1]), tb = stoi(b[1]);
            if (ta != tb) return ta < tb;
            return a[0] == "OFFLINE" && b[0] == "MESSAGE";
        });
        vector<int> ans(numberOfUsers,0), onlineUntil(numberOfUsers,0);
        int lazyAll = 0;
        for(auto &e: events) {
            int t = stoi(e[1]);
            if(e[0]=="OFFLINE") {
                int id = stoi(e[2]);
                onlineUntil[id] = t + 60;
            } else {
                string &s = e[2];
                if(s=="ALL") {
                    lazyAll++;
                } else if(s=="HERE") {
                    for(int i=0;i<numberOfUsers;i++)
                        if(onlineUntil[i] <= t) ans[i]++;
                } else {
                    stringstream ss(s);
                    string token;
                    while(ss >> token) {
                        int id = stoi(token.substr(2));
                        ans[id]++;
                    }
                }
            }
        }
        for(int i=0;i<numberOfUsers;i++) ans[i] += lazyAll;
        return ans;
    }
};

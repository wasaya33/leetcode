class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> state(numCourses, 0);
        for (auto &p : prerequisites) {
            graph[p[1]].push_back(p[0]);
        }
        for (int i = 0; i < numCourses; i++) {
            if (state[i] == 0 && hasCycle(graph, state, i)) return false;
        }
        return true;
    }

private:
    bool hasCycle(vector<vector<int>>& graph, vector<int>& state, int u) {
        state[u] = 1;
        for (int v : graph[u]) {
            if (state[v] == 1) return true;
            if (state[v] == 0 && hasCycle(graph, state, v)) return true;
        }
        state[u] = 2;
        return false;
    }
};

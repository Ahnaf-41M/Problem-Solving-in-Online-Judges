class Solution {
public:
    vector<int> adj[2005];
    int indeg[2005], n;

    bool Kahn() {
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indeg[i] == 0)
                q.push(i);
        }
        while (!q.empty()) {
            int nd = q.front();
            q.pop();
            for (int ch : adj[nd]) {
                indeg[ch]--;
                if (indeg[ch] == 0)
                    q.push(ch);
            }
        }
        for (int i = 0; i < n; i++)
            if (indeg[i] != 0)
                return false;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        n = numCourses;
        for (auto v : prerequisites) {
            adj[v[1]].push_back(v[0]);
            indeg[v[0]]++;
        }

        return Kahn();
    }
};
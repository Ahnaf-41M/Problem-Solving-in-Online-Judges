class Solution {
public:
    vector<int> adj[100005];
    bool vis[100005];

    int dfs(int nd) {
        vis[nd] = true;
        int res = 1;
        for (int ch : adj[nd]) {
            if (!vis[ch]) {
                res += dfs(ch);
            }
        }
        return res;
    }
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty())
            return 0;

        // Solution - 1
        // unordered_map<int, int> has, vis;
        // int ans = 0;
        // for(int x : nums) has[x] = 1;

        // for(int x : nums) {
        //     int cur = x, cnt=0;
        //     if(vis[cur]) continue;
        //     while(has[cur] && !vis[cur]) {
        //         cur++, cnt++;
        //     }
        //     int last = cur;
        //     cur = x;
        //     while(has[cur] && !vis[cur]) {
        //         vis[cur] = cnt + vis[last];
        //         cur++;
        //     }
        //     ans = max(ans, vis[cur-1]);
        // }

        // Solution - 2
        sort(nums.begin(), nums.end());
        int cnt = 1, prev = nums[0], ans = 1;
        for (int x : nums) {
            if (prev == x)
                continue;
            if (prev + 1 == x)
                cnt++;
            else
                cnt = 1;
            ans = max(ans, cnt);
            prev = x;
        }

        // Solution - 3
        // unordered_map<int, int> has;
        // int cnt = 1, ans=0;
        // for(int x : nums) {
        //     if(has[x]) continue;
        //     has[x] = cnt++;
        // }
        // for(int x : nums) {
        //     int u = has[x], v = has[x+1];
        //     if(v) {
        //         adj[u].push_back(v);
        //         adj[v].push_back(u);
        //     }
        // }
        // for(int i = 1; i <= cnt; i++) {
        //     if(!vis[i]) {
        //         ans = max(ans, dfs(i));
        //     }
        // }
        return ans;
    }
};
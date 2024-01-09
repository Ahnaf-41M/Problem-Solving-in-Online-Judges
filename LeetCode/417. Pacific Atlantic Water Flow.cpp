class Solution {
public:
    int m, n;
    vector<vector<int>> ans, grid;

    bool valid(int x, int y, vector<vector<int>>& vis) {
        return (x >= 0 && x < m && y >= 0 && y < n && !vis[x][y]);
    }
    void dfs(int x, int y, vector<vector<int>>& vis) {
        vis[x][y] = true;
        if (valid(x - 1, y, vis) && grid[x][y] <= grid[x - 1][y])
            dfs(x - 1, y,  vis);
        if (valid(x, y - 1, vis) && grid[x][y] <= grid[x][y - 1])
            dfs(x, y - 1, vis);
        if (valid(x + 1, y, vis) && grid[x][y] <= grid[x + 1][y])
            dfs(x + 1, y, vis);
        if (valid(x, y + 1, vis) && grid[x][y] <= grid[x][y + 1])
            dfs(x, y + 1, vis);

    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size(), n = heights[0].size();
        grid = heights;

        vector<vector<int>> pac(m, vector<int>(n, 0));
        vector<vector<int>> atl(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            dfs(i, 0, pac);
            dfs(i, n - 1, atl);
        }
        for (int i = 0; i < n; i++) {
            dfs(0, i, pac);
            dfs(m - 1, i, atl);
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pac[i][j] && atl[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
};
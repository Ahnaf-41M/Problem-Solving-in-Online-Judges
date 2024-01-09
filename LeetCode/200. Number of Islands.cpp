class Solution {
public:
    int n, m, ans = 0;
    vector<vector<char>> mat;
    void dfs(int x, int y) {
        mat[x][y] = '0';
        if (x + 1 < n && mat[x + 1][y] == '1') dfs(x + 1, y);
        if (x - 1 >= 0 && mat[x - 1][y] == '1') dfs(x - 1, y);
        if (y + 1 < m && mat[x][y + 1] == '1') dfs(x, y + 1);
        if (y - 1 >= 0 && mat[x][y - 1] == '1') dfs(x, y - 1);
    }
    int numIslands(vector<vector<char>>& grid) {
        mat = grid;
        n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == '1') {
                    ans++;
                    dfs(i, j);
                }
            }
        }
        return ans;
    }
};
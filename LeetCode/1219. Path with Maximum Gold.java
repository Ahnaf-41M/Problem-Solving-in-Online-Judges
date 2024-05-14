class Solution {
    private boolean[][] vis = new boolean[16][16];
    private int n, m, ans = 0;

    private boolean isValid(int x, int y, int[][] grid) {
        return (x >= 0 && x < n && y >= 0 && y < m && !vis[x][y] && grid[x][y] > 0);
    }

    private void dfs(int x, int y, int[][] grid, int curSum) {
        ans = Math.max(ans, curSum);
        vis[x][y] = true;
        if (isValid(x + 1, y, grid))
            dfs(x + 1, y, grid, curSum + grid[x + 1][y]);
        if (isValid(x - 1, y, grid))
            dfs(x - 1, y, grid, curSum + grid[x - 1][y]);
        if (isValid(x, y + 1, grid))
            dfs(x, y + 1, grid, curSum + grid[x][y + 1]);
        if (isValid(x, y - 1, grid))
            dfs(x, y - 1, grid, curSum + grid[x][y - 1]);
        vis[x][y] = false;
    }

    public int getMaximumGold(int[][] grid) {
        n = grid.length;
        m = grid[0].length;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (isValid(i, j, grid)) {
                    dfs(i, j, grid, grid[i][j]);
                }
            }
        }
        return ans;
    }
}
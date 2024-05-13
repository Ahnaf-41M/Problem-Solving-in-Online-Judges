class Solution {
    public int matrixScore(int[][] grid) {
        int n = grid.length, m = grid[0].length;
        for (int i = 0; i < n; i++) {
            if (grid[i][0] == 0) {
                for (int j = 0; j < m; j++) {
                    grid[i][j] = 1 - grid[i][j];
                }
            }
        }

        for (int j = 1; j < m; j++) {
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                cnt += grid[i][j];
            }
            if (cnt >= n - cnt)
                continue;
            for (int i = 0; i < n; i++) {
                grid[i][j] = 1 - grid[i][j];
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int cur_pow = 1;
            for (int j = m - 1; j >= 0; j--) {
                ans += (cur_pow * grid[i][j]);
                cur_pow *= 2;
            }
        }

        return ans;
    }
}
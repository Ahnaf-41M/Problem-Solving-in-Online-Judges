class Solution {
public:
    int dp[101][101];
    int x, y;
    int call(int i, int j) {
        if (i == x && j == y)
            return 1;
        if (i > x || j > y)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];

        return dp[i][j] = call(i + 1, j) + call(i, j + 1);
    }
    int uniquePaths(int m, int n) {
        memset(dp, -1, sizeof(dp));
        x = m - 1, y = n - 1;
        return call(0, 0);
    }
};
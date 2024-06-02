class Solution {
    int[][] dp = new int[1001][1001];
    int n, ans = 0;

    int isPal(int left, int right, char[] s2) {
        if (left >= right)
            return 1;
        if (dp[left][right] != -1)
            return dp[left][right];
        if (s2[left] == s2[right])
            return dp[left][right] = isPal(left + 1, right - 1, s2);
        else
            return dp[left][right] = 0;
    }

    public int countSubstrings(String s) {
        n = s.length();
        char[] s2 = s.toCharArray();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j] = -1;
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (isPal(i, j, s2) > 0) {
                    ans++;
                }
            }
        }
        return ans;
    }
}
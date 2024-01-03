class Solution {
public:
    string s1, s2;
    int n1, n2;
    int dp[1005][1005];

    int call(int i, int j) {
        if (i >= n1 || j >= n2) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        int res = 0;
        if (s1[i] == s2[j]) {
            res = 1 + call(i + 1, j + 1);
        }
        else {
            res = max(res, call(i + 1, j));
            res = max(res, call(i, j + 1));
        }
        return dp[i][j] = res;
    }
    int longestCommonSubsequence(string text1, string text2) {
        s1 = text1, s2 = text2;
        n1 = s1.size(), n2 = s2.size();

        memset(dp, -1, sizeof(dp));

        return call(0, 0);
    }
};
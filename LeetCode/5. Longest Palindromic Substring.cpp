class Solution {
public:
    int dp[1001][1001];
    string str;

    bool func(int l, int r) {
        if (l >= r)
            return 1;
        if (dp[l][r] != -1)
            return dp[l][r];

        if (str[l] == str[r])
            return dp[l][r] = func(l + 1, r - 1);
        else
            return dp[l][r] = 0;
    }
    string longestPalindrome(string s) {
        memset(dp, -1, sizeof(dp));
        str = s;
        string ans = "";
        int n = s.size();
        int ansLen = 1;
        pair<int, int> ansPair = {0, 0};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (func(i, j) && ansLen < j - i + 1) {
                    ansLen = j - i + 1;
                    ansPair = {i, j};
                }
            }
        }
        // cout << ansPair.first << " " << ansPair.second<<"\n";
        for (int i = ansPair.first; i <= ansPair.second; i++) {
            ans.push_back(s[i]);
        }
        return ans;
    }
};
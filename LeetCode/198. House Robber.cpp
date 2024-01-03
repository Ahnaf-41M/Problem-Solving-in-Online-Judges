class Solution {
public:
    int dp[101], n;
    vector<int> ar;

    int call(int pos) {
        if (pos >= n)
            return 0;
        if (dp[pos] != -1)
            return dp[pos];

        int res = ar[pos] + call(pos + 2);
        res = max(res, call(pos + 1));

        return dp[pos] = res;
    }
    int rob(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        ar = nums;
        n = ar.size();
        return call(0);
    }
};
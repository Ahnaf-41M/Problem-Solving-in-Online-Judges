class Solution {
public:
    long long dp[13][10005];
    vector<int> ar;
    long long n, val;

    long long call(int pos, int val) {
        if (val == 0)
            return 0;
        if (val < 0 || pos < 0)
            return INT_MAX;
        if (dp[pos][val] != -1)
            return dp[pos][val];

        long long res = INT_MAX;
        res = min(res, 1 + call(pos, val - ar[pos]));
        res = min(res, call(pos - 1, val));

        return dp[pos][val] = res;
    }
    int coinChange(vector<int>& coins, int amount) {
        ar = coins;
        n = coins.size();
        val = amount;

        memset(dp, -1, sizeof(dp));
        return call(n - 1, val) == INT_MAX ? -1 : call(n - 1, val);
    }
};
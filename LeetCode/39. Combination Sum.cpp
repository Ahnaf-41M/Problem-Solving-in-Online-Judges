class Solution {
public:
    vector<vector<int>> ans;
    vector<int> ar, tmp;
    int n;
    // vector<int> dp[35][45];
    int dp[35][45];

    int call(int pos, int weight) {
        if (weight == 0) {
            ans.push_back(tmp);
            return dp[pos][weight] = 1;
        }
        if (weight < 0 || pos >= n)
            return 0;

        int res = 0;
        tmp.push_back(ar[pos]);
        res = call(pos, weight - ar[pos]);
        tmp.pop_back();

        res = max(res, call(pos + 1, weight));

        return dp[pos][weight] = res;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        memset(dp, -1, sizeof(dp));
        ar = candidates;
        n = ar.size();
        call(0, target);

        return ans;
    }
};
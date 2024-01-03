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
        if (nums.size() == 1) return nums[0];

        memset(dp, -1, sizeof(dp));
        ar.push_back(nums.back());
        for (int x : nums) ar.push_back(x);

        n = ar.size();

        int ans = call(0) - ar[0];
        ar = nums;
        ar.push_back(ar[0]);
        memset(dp, -1, sizeof(dp));
        ans = max(ans, call(0) - ar.back());

        return ans;
    }
};
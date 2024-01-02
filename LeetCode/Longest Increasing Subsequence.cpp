class Solution {
public:
    // int dp[2505][2505], n;
    // vector<int> ar;

    // int call(int pos, int lst_pos) {
    //     if (pos >= n)
    //         return 0;
    //     if (dp[pos][lst_pos + 1] != -1)
    //         return dp[pos][lst_pos + 1];

    //     int res = 0;
    //     res = call(pos + 1, lst_pos);
    //     if (lst_pos == -1 || ar[pos] > ar[lst_pos]) {
    //         res = max(res, 1 + call(pos + 1, pos));
    //     }
    //     return dp[pos][lst_pos+1] = res;
    // }
    int lengthOfLIS(vector<int>& nums) {
        // memset(dp, -1, sizeof(dp));
        // ar = nums;
        // n = nums.size();

        // int ans = 0;

        // return call(0, -1);
        vector<int> lis;
        lis.push_back(nums[0]);

        for (int i = 1; i < nums.size(); i++) {
            if (lis.back() < nums[i])
                lis.push_back(nums[i]);
            else {
                int ind = lower_bound(lis.begin(), lis.end(), nums[i]) - lis.begin();
                lis[ind] = nums[i];
            }
        }
        return lis.size();
    }
};
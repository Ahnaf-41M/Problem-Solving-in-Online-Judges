class Solution {
public:
    // vector<int> ar;
    // int n;
    // int dp[10001];

    // bool call(int pos) {
    //     if (pos == n - 1)
    //         return true;
    //     if (pos > n - 1)
    //         return false;
    //     if (dp[pos] != -1)
    //         return dp[pos];

    //     bool res = 0;
    //     for (int i = 1; i <= ar[pos]; i++) {
    //         res |= call(pos + i);
    //         if(res) return true;
    //     }
    //     return dp[pos] = res;
    // }
    bool canJump(vector<int>& nums) {
        // memset(dp, -1, sizeof(dp));
        // ar = nums;
        // n = ar.size();
        // return call(0);

        int maxIcanReach = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i > maxIcanReach) return false;
            maxIcanReach = max(maxIcanReach, nums[i] + i);
        }
        return true;
    }
};
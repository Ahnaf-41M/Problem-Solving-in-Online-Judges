class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curSum = 0, ans = 0, mx = -1e5;
        for (int x : nums) {
            if (curSum + x < 0) curSum = 0;
            else curSum += x;
            ans = max(ans, curSum);
            mx = max(mx, x);
        }
        return mx < 0 ? mx : ans;
    }
};
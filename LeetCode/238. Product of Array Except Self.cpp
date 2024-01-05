class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        int pref = 1, n = nums.size();
        int suf[n];
        for (int i = n - 1; i >= 0; i--) {
            if (i == n - 1)
                suf[i] = nums[i];
            else
                suf[i] = suf[i + 1] * nums[i];
        }
        for (int i = 0; i < n; i++) {
            if (i == n - 1)
                ans.push_back(pref);
            else
                ans.push_back(pref * suf[i + 1]);
            pref *= nums[i];
        }
        return ans;
    }
};
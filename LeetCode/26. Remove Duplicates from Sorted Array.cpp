class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cur = -200, ans = 0;
        vector<int> tmp;
        for (int x : nums) {
            if (cur != x) {
                cur = x;
                tmp.push_back(x);
                ans++;
            }
        }
        nums = tmp;
        return ans;
    }
};
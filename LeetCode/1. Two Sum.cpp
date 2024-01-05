class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        multiset<pair<int, int> > s;
        int n = nums.size();
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            s.insert({nums[i], i});
        }
        for (int i = 0; i < n; i++) {
            int y = target - nums[i];
            auto it = s.upper_bound({y, 1e6});
            it--;
            if (it != s.end() && it->first == y && it->second != i) {
                ans.push_back(i), ans.push_back(it->second);
                break;
            }
        }
        return ans;
    }
};
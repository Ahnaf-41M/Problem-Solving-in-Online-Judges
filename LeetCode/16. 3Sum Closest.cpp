class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        multiset<int> s;
        for (int x : nums) s.insert(x);

        int n = nums.size(), ans, dif = 1e6;

        for (int i = 0; i < n; i++) {
            s.erase(s.find(nums[i]));
            for (int j = i + 1; j < n; j++) {
                s.erase(s.find(nums[j]));
                int sum = target - (nums[i] + nums[j]);
                auto it = s.lower_bound(sum);
                if (it != s.end()) {
                    sum = (*it) + nums[i] + nums[j];
                    if (abs(sum - target) < dif) {
                        dif = abs(sum - target);
                        ans = sum;
                    }
                }
                it--;
                if (it != s.end()) {
                    sum = (*it) + nums[i] + nums[j];
                    if (abs(sum - target) < dif) {
                        dif = abs(sum - target);
                        ans = sum;
                    }
                }
                s.insert(nums[j]);
            }
            s.insert(nums[i]);
        }
        return ans;
    }
};
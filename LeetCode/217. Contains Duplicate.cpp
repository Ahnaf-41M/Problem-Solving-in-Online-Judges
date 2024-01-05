class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int x : nums) {
            if (mp[x]) {
                return true;
            }
            mp[x] = 1;
        }
        return false;
    }
};
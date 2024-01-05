class Solution {
public:
    int findMin(vector<int>& nums) {
        int high = nums.size() - 1;
        int low = 0, pos = high;

        while (low <= high) {
            int mid = (low + high) >> 1;
            if (nums[low] > nums[mid]) {
                pos = mid - 1;
                high = mid - 1;
            } else if (nums[mid] > nums[high]) {
                pos = mid;
                low = mid + 1;
            } else
                break;
        }
        int res = min({nums[0], nums.back(), nums[pos]});
        if (pos + 1 < nums.size()) res = min(res, nums[pos + 1]);

        return res;
    }
};
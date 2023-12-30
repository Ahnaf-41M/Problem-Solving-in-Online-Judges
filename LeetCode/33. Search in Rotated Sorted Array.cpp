class Solution {
public:
    int search(vector<int>& nums, int target) {
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

        // cout << pos << "\n";
        low = 0, high = pos;
        while (low <= high) {
            int mid = (low + high) >> 1;
            if (nums[mid] == target)
                return mid;
            if (nums[mid] > target)
                high = mid - 1;
            else
                low = mid + 1;
        }

        low = pos + 1, high = nums.size() - 1;
        while (low <= high) {
            int mid = (low + high) >> 1;
            if (nums[mid] == target)
                return mid;
            if (nums[mid] > target)
                high = mid - 1;
            else
                low = mid + 1;
        }

        return -1;
    }
};
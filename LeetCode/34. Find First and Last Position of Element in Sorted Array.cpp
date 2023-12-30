class Solution {
public:
    int Lower_Bound(vector<int> v, int x) {
        int pos = -1, low = 0, high = v.size() - 1;
        while (low <= high) {
            int mid = (low + high) >> 1;
            if (v[mid] >= x) {
                if (v[mid] == x)
                    pos = mid;
                high = mid - 1;
            } else
                low = mid + 1;
        }
        return pos;
    }
    int Upper_Bound(vector<int> v, int x) {
        int pos = -1, low = 0, high = v.size() - 1;
        while (low <= high) {
            int mid = (low + high) >> 1;
            if (v[mid] > x) {
                high = mid - 1;
            } else {
                if (v[mid] == x)
                    pos = mid;
                low = mid + 1;
            }
        }
        return pos;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = Lower_Bound(nums, target);
        int r = Upper_Bound(nums, target);

        return {l, r};
    }
};
class Solution {

    boolean possible(int n, int[] nums, int x) {
        int low = 0, high = n - 1, pos = n;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] >= x) {
                pos = mid;
                high = mid - 1;
            } else low = mid + 1;
        }
        return n - pos == x;
    }
    public int specialArray(int[] nums) {
        int n = nums.length;
        Arrays.sort(nums);

        int ans = -1;
        for (int x = 0; x <= n; x++) {
            if (possible(n, nums, x)) {
                ans = x;
                break;
            }
        }
        return ans;
    }
}
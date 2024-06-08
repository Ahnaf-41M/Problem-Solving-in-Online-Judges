class Solution {
    public boolean checkSubarraySum(int[] nums, int k) {
        int cur_sum = 0, temp_sum = 0;
        int n = nums.length;

        for (int l = 0; l < n; l++) {
            nums[l] %= k;
        }
        cur_sum = nums[0];
        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1] && nums[i] == 0) {
                return true;
            }
            int j = 0;
            cur_sum += nums[i];
            temp_sum = cur_sum;
            while ((i - j + 1 > 1) && (temp_sum % k != 0) && temp_sum >= k) {
                temp_sum -= nums[j];
                j++;
            }
            if (temp_sum % k == 0) {
                return true;
            }
        }
        return false;
    }
}
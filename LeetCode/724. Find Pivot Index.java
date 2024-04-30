class Solution {
    public int pivotIndex(int[] nums) {
        int sum = 0, left = 0;
        for (int x : nums)
            sum += x;
        for (int i = 0; i < nums.length; i++) {
            int right = sum - nums[i];
            if (left == right) {
                return i;
            }
            left += nums[i];
            sum -= nums[i];
        }
        return -1;
    }
}
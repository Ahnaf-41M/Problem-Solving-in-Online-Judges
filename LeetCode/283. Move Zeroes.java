class Solution {
    public void moveZeroes(int[] nums) {
        int i = 0, n = nums.length;
        for (int x : nums) {
            if (x != 0) {
                nums[i++] = x;
            }
        }
        while (i < n) {
            nums[i++] = 0;
        }
    }
}
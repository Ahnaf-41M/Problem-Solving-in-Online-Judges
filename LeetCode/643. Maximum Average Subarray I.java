class Solution {
    public double findMaxAverage(int[] nums, int k) {
        double curSum = 0, ans = -100000;
        for (int i = 0; i < nums.length; i++) {
            curSum += nums[i];
            if (i - k + 1 >= 0) {
                ans = Math.max(ans, curSum / k);
                curSum -= nums[i - k + 1];
            }
        }
        return ans;
    }
}
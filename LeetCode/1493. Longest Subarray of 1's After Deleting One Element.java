class Solution {
    public int longestSubarray(int[] nums) {
        int ans = 0;
        int right = 0, left = 0, n = nums.length, zeroes = 0;

        while (right < n) {
            if (nums[right] == 0)
                zeroes++;
            while (zeroes > 1) {
                if (nums[left] == 0)
                    zeroes--;
                left++;
            }
            ans = Math.max(ans, right - left + 1);
            right++;
        }
        return ans - 1;
    }
}
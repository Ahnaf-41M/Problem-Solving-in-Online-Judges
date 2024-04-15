class Solution {
    public int longestOnes(int[] nums, int k) {
        int ans = 0, j = 0, cur = 0, i = 0;
        int n = nums.length;

        while (i < n) {
            if (nums[i] == 0) {
                if (k > 0) k--;
                else {
                    while (j < n && nums[j] != 0)
                        j++;
                    j++;
                }
            }
            ans = Math.max(ans, i - j + 1);
            i++;
        }
        return ans;

    }
}
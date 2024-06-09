class Solution {
    public int subarraysDivByK(int[] nums, int k) {
        int[] mod_count = new int[k];
        int ans = 0, cur_sum = 0;
        mod_count[0] = 1;
        for (int i = 0; i < nums.length; i++) {
            cur_sum = (nums[i] + cur_sum) % k;
            if (cur_sum < 0) cur_sum += k;
            mod_count[cur_sum]++;
        }
        for (int i = 0; i < k; i++) {
            ans += (mod_count[i] * (mod_count[i] - 1)) / 2;
        }
        return ans;
    }
}
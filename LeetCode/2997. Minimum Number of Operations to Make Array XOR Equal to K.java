class Solution {
    public int minOperations(int[] nums, int k) {
        int cur = 0, ans = 0;
        for (int x : nums) {
            cur ^= x;
        }
        for (int i = 31; i >= 0; i--) {
            int i_k = (1 << i) & k;
            int i_cur = (1 << i) & cur;
            if (i_k != i_cur)
                ans++;
        }
        return ans;
    }
}
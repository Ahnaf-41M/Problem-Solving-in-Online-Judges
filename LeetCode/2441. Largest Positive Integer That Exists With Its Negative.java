class Solution {
    public int findMaxK(int[] nums) {
        int[] sum = new int[1001];
        int ans = -1;
        for (int x : nums) {
            int pos = Math.abs(x);
            if (sum[pos] != x)
                sum[pos] += x;
            if (sum[pos] == 0)
                ans = Math.max(ans, pos);
        }
        return ans;
    }
}
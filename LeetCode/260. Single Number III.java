class Solution {
    public int[] singleNumber(int[] nums) {
        int totXor = 0;
        for (int x : nums) {
            totXor ^= x;
        }
        int firstDifferentBit = 0;
        for (int i = 0; i <= 31; i++) {
            if (((1 << i) & totXor) > 0) {
                firstDifferentBit ^= (1 << i);
                break;
            }
        }

        int[] ans = new int[2];
        for (int x : nums) {
            if ((firstDifferentBit & x) == 0) {
                ans[0] ^= x;
            } else {
                ans[1] ^= x;
            }
        }
        return ans;
    }
}
class Solution {

    public int longestIdealString(String s, int k) {
        int[] dp = new int[26];
        int n = s.length();
        char[] s2 = s.toCharArray();

        /*
         * the idea is to dynamically track the longest possible subsequences
         * ending with each possible character.
         */
        for (int i = 0; i < n; i++) {
            int pos = s2[i] - 'a';
            int left = Math.max(0, pos - k);
            int right = Math.min(25, pos + k);
            int mx = 0;
            for (int j = left; j <= right; j++) {
                mx = Math.max(mx, dp[j]);
            }
            dp[pos] = mx + 1;
        }
        int res = 0;
        for (int x : dp) {
            res = Math.max(x, res);
        }
        return res;
    }
}
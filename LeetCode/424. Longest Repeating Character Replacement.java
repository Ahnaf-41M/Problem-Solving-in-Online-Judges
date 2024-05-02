class Solution {
    public int characterReplacement(String s, int k) {
        char[] s2 = s.toCharArray();
        int n = s2.length, ans = 0;

        for (char ch = 'A'; ch <= 'Z'; ch++) {
            int curK = k;
            int left = 0, right = 0;
            while (left < n) {
                while (right < n && (curK > 0 || s2[right] == ch)) {
                    if (s2[right] != ch) curK--;
                    right++;
                }
                ans = Math.max(ans, right - left);
                if (s2[left] != ch) curK++;
                left++;
            }
        }
        return ans;
    }
}